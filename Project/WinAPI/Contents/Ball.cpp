#include "Ball.h"
#include <EngineCore/EngineResourcesManager.h>
#include "User.h"
#include <EnginePlatform/EngineInput.h>
#include <vector>
#include"Block.h"
#include"Item.h"
Ball* Ball::MainBall = nullptr;
Ball::Ball()
{

}
Ball::~Ball()
{}




void Ball::BeginPlay()
{

	MainBall = this;
	AActor::BeginPlay();
	BallRender = CreateImageRenderer(0);
	UEngineResourcesManager::GetInst().CuttingImage("Ball.png", 1, 1);
	BallRender->SetImage("Ball.png");
	BallRender->SetScale(BallSize*2 );
	GetUserScale();
	SetActorLocation({ User::CurPos.X,User::CurPos.Y - 10 });



	BallCollison = CreateCollision(ColliderOrder::Ball);
	BallCollison->SetScale({ 2,2 });
	BallCollison->SetColType(ECollisionType::CirCle);




}
void Ball::SetPos(FVector _CurPos)
{

	CurBallPos = _CurPos;

}
void Ball::GetUserScale()
{
	FVector UScale = { User::CurPos.hX() , User::CurPos.hY() };

}



void Ball::Tick(float _DeltaTime)
{
	if (false == IsballLive)
	{
		SetActorLocation({ User::CurPos.X,User::CurPos.Y - 10 });
	}


	if (UEngineInput::IsDown('R'))
	{
		Reset();
	}
	AActor::Tick(_DeltaTime);
	GameStartCheck();

	Move(_DeltaTime);
	// �� �̷��� ��ġ�� üũ�ϴ� ��
	// �浹�ϰ� ���� üũ�ϴ¹�


	WallCheck();
	BlockCheck();


}




UCollision* Ball::GetCollision()
{
	return BallCollison;

}



void Ball::GameStartCheck()
{
	if (true == IsballLive)
	{
		return;
	}

	if (true == UEngineInput::IsDown('A'))
	{
		BDir = FVector(-1.0f, -1.0f);
		BDir.Normalize2D();
	}
	else if (true == UEngineInput::IsDown('D'))
	{
		BDir = FVector(1.0f, -1.0f);
		BDir.Normalize2D();
	}
	else if (true == UEngineInput::IsDown('W'))
	{
		BDir = FVector(0.0f, -1.0f);
		BDir.Normalize2D();
	}

	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		IsballLive = true;
	}
}





Ball* Ball::GetMainBall()
{
	return MainBall;
}


void Ball::Move(float _DeltaTime)
{
	BDir.Normalize2D();

	AddActorLocation(BDir * Speed * _DeltaTime);//�����̵��Ѵ�.
}

void Ball::WallCheck()
{
	// R = P + 2n(-P��n);
	FVector N = FVector::Zero;
	CurBallPos = GetTransform().GetPosition();

	if (CurBallPos.X >= 524)
	{
		N = { -1,0 };
	}
	else if (CurBallPos.X <= 30)
	{
		N = { 1,0 };
	}
	else if (CurBallPos.Y <= 50)
	{
		N = { 0,1 };
	}


	else if (CurBallPos.Y >= 480)
	{
		int a = 0;
		PlayerPos();
	}


	if (false == N.IsZeroVector2D())
	{
		Reflect(N);
	}
}
void Ball::PlayerPos()
{
	float ULeft = User::CurPos.X - 30;
	float URight = User::CurPos.X + 30;


	if (CurBallPos.X >= ULeft && CurBallPos.X <= URight)
	{
		Reflect({ 0.0f, -1.0f });
		FVector Pos = GetTransform().GetPosition() - User::CurPos;
		Pos.X /= User::UserScale.hX(); //���� x���� ������ �������� �ε�ģ ���� ������ 
		BDir.X += Pos.X;
		BDir.Normalize2D();
	}
}
void Ball::Reset()
{

	IsballLive = false;
	CurBallPos = User::CurPos;
	GameStartCheck();
}

void Ball::BlockCheck()
{
	std::vector<UCollision*> Result;
	if (true == BallCollison->CollisionCheck(ColliderOrder::Block, Result))
	{
		UCollision* Collider = Result[0/*���°�϶�*/];
		AActor* ColAct = Collider->GetOwner();
		Block* ColBlock = dynamic_cast<Block*>(ColAct);
		BlockRatio(ColBlock);
		//BDir = (BDir * -1);
		FVector BlockPos = ColBlock->GetActorLocation();
		Result[0]->Destroy(); //�ӽ÷� ����� CollManager���� �Ѱ��� �����Ұ�
		ColBlock->Destroy();
	}
}

void Ball::Reflect(FVector Normal)
{
	FVector N = Normal;
	FVector N2 = N * 2.0f;
	FVector T = { (-1 * BDir.X) * N.X,(-1 * BDir.Y) * N.Y }; //(-P * n)
	BDir = BDir + (N2 * T);
}
void Ball::BlockRatio(Block* _NewBlock)
{

	//FVector BlockLeftTop = { _NewBlock->BlockLeft(),_NewBlock->BlockUP() };
	//
	//FVector BlockRightBottom = { _NewBlock->BlockRight(),_NewBlock->BlockBottom() };
	//



	FTransform Transform = { _NewBlock->GetBlockPos(), _NewBlock->GetBlockScale() };
	BlockSideCheck(_NewBlock);
	float ColX = GetActorLocation().X - Transform.Left();
	float ColY = GetActorLocation().Y - Transform.Top();

	// ���� �� ��ġ = ���� ���� ��ġ - ����� ���� ��ǥ
	// ���� �� ��ġ = ���� ���� y��ġ - ����� ���� ��ǥ;

	float RatioX = ColX / _NewBlock->GetBlockScale().X;
	float RatioY = ColY / _NewBlock->GetBlockScale().Y;

	bool R = false;

	if (RatioX < RatioY)
	{
		R = true;
	}




	//FVector BlockCross = 










}
FVector Ball::BlockSideCheck(Block* _ColBlock)
{
	Block* thisBlock = _ColBlock;
	
	float BlockLeft =  thisBlock->BlockLeft() + thisBlock->GetActorLocation().X+1;
	float BlockRight =  thisBlock->BlockRight() + thisBlock->GetActorLocation().X+1;
	float BlockTop =  thisBlock->BlockUP() + thisBlock->GetActorLocation().Y+1;
	float BlockBottom =  thisBlock->BlockBottom() + thisBlock->GetActorLocation().Y+1;
	//���� 1�� ������ ������ float �� ������ ���ֱ� ���ؼ� ��������ϴ�. 
	
	float XMid = thisBlock->GetActorLocation().X;
	float YMid = thisBlock->GetActorLocation().Y;


	bool isleft = false;
	bool isRight = false;
	bool isDown = false;
	bool isTop = false;

	if (BlockLeft <= CurBallPos.X && CurBallPos.X < XMid)
	{
		float ColX = GetActorLocation().X - _ColBlock->GetBlockScale().X;
		float ColY = GetActorLocation().Y - _ColBlock->GetBlockScale().Y;
		isleft = true;
		int a = 0;
		//���� 
	}

	if (XMid <= CurBallPos.X && CurBallPos.X <= BlockRight)
	{
		isRight = true;
		int b = 0;
		//������
	}

	if (BlockTop <= CurBallPos.Y && CurBallPos.Y < YMid)
	{
		int c = 0;
		//��
	}

	if (YMid < CurBallPos.Y && CurBallPos.Y <= BlockBottom)
	{
		int d = 0;
		//�Ʒ�
	}

	int E = 0;
	return Ball::BDir = { -1,-1 };

}

//�����¿� �˾Ƴ���
