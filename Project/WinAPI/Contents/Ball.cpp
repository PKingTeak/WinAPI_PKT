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
	// 내 미래의 위치로 체크하는 법
	// 충돌하고 나서 체크하는법


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

	AddActorLocation(BDir * Speed * _DeltaTime);//공이이동한다.
}

void Ball::WallCheck()
{
	// R = P + 2n(-P·n);
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
		Pos.X /= User::UserScale.hX(); //유저 x에서 중점을 기준으로 부딪친 곳을 나눠서 
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
		UCollision* Collider = Result[0/*몇번째일때*/];
		AActor* ColAct = Collider->GetOwner();
		Block* ColBlock = dynamic_cast<Block*>(ColAct);
		BlockRatio(ColBlock);
		//BDir = (BDir * -1);
		FVector BlockPos = ColBlock->GetActorLocation();
		Result[0]->Destroy(); //임시로 사용중 CollManager에서 총괄로 관리할것
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

	// 지금 공 위치 = 공의 현재 위치 - 블록의 왼쪽 좌표
	// 지금 공 위치 = 공의 현재 y위치 - 블록의 위쪽 좌표;

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
	//각각 1씩 더해준 이유는 float 의 오차를 없애기 위해서 더해줬습니다. 
	
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
		//왼쪽 
	}

	if (XMid <= CurBallPos.X && CurBallPos.X <= BlockRight)
	{
		isRight = true;
		int b = 0;
		//오른쪽
	}

	if (BlockTop <= CurBallPos.Y && CurBallPos.Y < YMid)
	{
		int c = 0;
		//위
	}

	if (YMid < CurBallPos.Y && CurBallPos.Y <= BlockBottom)
	{
		int d = 0;
		//아래
	}

	int E = 0;
	return Ball::BDir = { -1,-1 };

}

//상하좌우 알아내기
