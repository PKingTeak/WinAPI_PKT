#include "Ball.h"
#include <EngineCore/EngineResourcesManager.h>
#include "User.h"
#include <EnginePlatform/EngineInput.h>
#include <vector>
#include"Block.h"
#include"Item.h"
#include <EngineCore/EngineDebug.h>
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
	BallRender->SetScale(BallSize * 2);
	GetUserScale();
	SetActorLocation({ User::CurPos.X,User::CurPos.Y - 10 });



	BallCollison = CreateCollision(ColliderOrder::Ball);
	BallCollison->SetScale({ 2,2 });
	BallCollison->SetColType(ECollisionType::CirCle);
	this->SetActive(true, 1.0f);


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

	float time = 1 / _DeltaTime;
	std::string stime = std::to_string(time);
	UEngineDebug::DebugTextPrint(stime, 24);

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
	WallCheck();
	BlockCheck();
	Move(_DeltaTime);
	// �� �̷��� ��ġ�� üũ�ϴ� ��
	// �浹�ϰ� ���� üũ�ϴ¹�


	

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
	else if (true == UEngineInput::IsDown('S'))
	{
		BDir = FVector(0.0f, 1.0f);
		BDir.Normalize2D();
	}

	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		IsballLive = true;
	}



}



void Ball::Move(float _DeltaTime)
{
	BDir.Normalize2D();

	AddActorLocation(BDir * Speed * _DeltaTime);//�����̵��Ѵ�.
	isCol = false;
}

void Ball::WallCheck()
{
	// R = P + 2n(-P��n);
	FVector N = FVector::Zero;
	CurBallPos = GetTransform().GetPosition();
	bool PlayerDead = false;

	if (CurBallPos.X >= 524)
	{
		N = { -1,0 };
		CurBallPos.X = 524;

	}
	else if (CurBallPos.X <= 30)
	{
		N = { 1,0 };
		CurBallPos.X = 30;

	}
	else if (CurBallPos.Y <= 80)
	{
		N = { 0,1 };
		CurBallPos.Y = 80;

	}


	else if (CurBallPos.Y >= 530 && CurBallPos.Y < 540)
	{

		PlayerPos();
		CurBallPos.Y += 530-CurBallPos.Y;
	}
	else if (CurBallPos.Y >= 650 && CurBallPos.Y <= 750)
	{


		User* user = User::GetMainUser();
		user->User::PlayerDie(user);
		IsballLive = false;
		//GameStartCheck();



	}


	if (false == N.IsZeroVector2D())
	{
		Reflect(N);
		int a = 0;

	}
}
void Ball::PlayerPos()
{
	float ULeft = User::CurPos.X - 30;
	float URight = User::CurPos.X + 30;


	if (CurBallPos.X >= ULeft && CurBallPos.X <= URight)
	{
		if (User::CurPos.Y + 4 > CurBallPos.Y) // �÷��̾� �ϴ� ����
		{
			Reflect({ 0.0f, -1.0f });
			FVector Pos = GetTransform().GetPosition() - User::CurPos;
			Pos.X /= User::UserScale.hX(); //���� x���� ������ �������� �ε�ģ ���� ������ 
			BDir.X += Pos.X;
			BDir.Normalize2D();
		}

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
	int Blocklife = 0;

	std::vector<UCollision*> Result;
	if (true == BallCollison->CollisionCheck(ColliderOrder::Block, Result))
	{
		if (isCol == true)
		{
			return;
		}
		isCol = true;
		UCollision* Collider = Result[0/*���°�϶�*/];
		AActor* ColAct = Collider->GetOwner();
		Block* ColBlock = dynamic_cast<Block*>(ColAct);
		BlockRatio(ColBlock);
		FVector BlockPos = ColBlock->GetActorLocation();
		Blocklife = ColBlock->GetLife();
		BlockType Type = ColBlock->GetBlockType(ColBlock);
		//Result[0]->Destroy(); //�ӽ÷� ����� CollManager���� �Ѱ��� �����Ұ�
		if (Blocklife > 0)
		{
			ColBlock->LifeDecrease();
			if (Type == BlockType::Hard)
			{
				ColBlock->BlockAniReset(ColBlock);
				ColBlock->HardBlockAnimation(ColBlock);

			}
		}
		else
		{
			ColBlock->Destroy();
		}


	}

}

void Ball::Reflect(FVector Normal)
{
	FVector N = Normal;
	FVector N2 = N * 2;
	float X = BDir.X;
	float Y = BDir.Y;
	float T = (-BDir.X) * N.X + (-BDir.Y) * N.Y; //(-P * n) <���Ⱑ �̻��ϴ�.
	BDir = BDir + (N2 * T); //R = P+2n(-P����n)
}


void Ball::BlockRatio(Block* _NewBlock)
{
	FVector N = { BDir.X,BDir.Y };

	FTransform Transform = { _NewBlock->GetBlockPos(), _NewBlock->GetBlockScale() };

	bool R = BlockSideCheckLR(_NewBlock);
	bool D = BlockSideCheckUD(_NewBlock);


	if (false == R && false == D)
	{
		if (true == MidTopHeight)
		{
			MidHeight = false;
			Reflect({ -1.0f,0.0f });
		}
		else
		{
			Reflect({ 0.0,-1.0f });
		}

		//N

	}
	if (true == R && true == D)
	{
		if (true == MidHeight)
		{
			MidHeight = false;
			Reflect({ 1.0f,0.0f });
			CurBallPos.Y = _NewBlock->GetBlockScale().Y-1; // ���⼭ ǥ������ �Ű��ִ��۾�

		}
		else
		{
			Reflect({ 0.0f,-1.0f });
		}
		//������ �Ʒ�
	}

	if (true == R && false == D)
	{
		if (true == MidTopHeight)
		{
			MidHeight = false;
			Reflect({ 1.0f,0.0f });

		}
		else
		{
			Reflect({ 0.0f,-1.0f });
		}
		//������ ��


	}
	if (false == R && true == D)
	{
		if (true == MidHeight)
		{
			MidHeight = false;
			Reflect({ -1.0f,0.0f });

		}
		else
		{
			Reflect({ 0.0f,1.0f });
		}
		// ���⼭ ���� y�� -�� �پ ���;� �ϴµ� ���� ����� ���´�. �׷��� ������ ������ ������ ���� �̻��ϴ�
	   // X���� �߳���
	   //���� �Ʒ�
	}


}
bool Ball::BlockSideCheckLR(Block* _ColBlock)
{

	bool isRight = false;

	Block* thisBlock = _ColBlock;
	float BlockLeft = thisBlock->BlockLeft() + thisBlock->GetActorLocation().X - 1;
	float BlockRight = thisBlock->BlockRight() + thisBlock->GetActorLocation().X - 1;

	//���� 1�� ������ ������ float �� ������ ���ֱ� ���ؼ� ��������ϴ�. 

	float XMid = thisBlock->GetActorLocation().X;



	if (BlockLeft <= CurBallPos.X && CurBallPos.X < XMid)
	{

		isRight = false;

		//���� 
		//���� ���������� �ϴ� ���� Ȯ���ϰ� ���Ʒ� ���� �����Ҷ� boolŸ������ Ȯ���ϰ� �״��� ����� ����
	}

	if (XMid <= CurBallPos.X && CurBallPos.X <= BlockRight)
	{
		isRight = true;

		//������
	}

	return isRight;



}

bool Ball::BlockSideCheckUD(Block* _ColBlock)
{
	bool isDown = false;
	bool isMD = false;
	Block* thisBlock = _ColBlock;
	float BlockTop = thisBlock->BlockUP() + thisBlock->GetActorLocation().Y - 2;
	float BlockBottom = thisBlock->BlockBottom() + thisBlock->GetActorLocation().Y - 1;

	float YMid = thisBlock->GetActorLocation().Y;


	if (BlockTop + 2 < CurBallPos.Y && CurBallPos.Y < YMid)
	{

		isDown = false;
		MidTopHeight = true;
		//�� ����
	}
	if (BlockTop + 1 > CurBallPos.Y)
	{
		isDown = false;
		// ��¥ ����

	}

	if (YMid <= CurBallPos.Y && CurBallPos.Y < BlockBottom)
	{

		MidHeight = true;
		isDown = true;

		//�Ʒ� ������
	}
	if (CurBallPos.Y > BlockBottom)
	{
		isDown = true;
		MidTopHeight = false;
	}
	return isDown;
}



