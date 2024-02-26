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
	BallRender->SetScale(BallSize*2);
	GetUserScale();
	SetActorLocation({ User::CurPos.X,User::CurPos.Y - 10 });



	BallCollison = CreateCollision(ColliderOrder::Ball);
	BallCollison->SetScale({ 10,10 });
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
	CurBallPos =  User::CurPos;
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
		BDir = (BDir * -1);
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
	
//float StandardCross = _NewBlock->Blockwidth(); //대각선
//UCollision* BlockCol = _NewBlock->GetBlockCollision();
//
//
//FVector StandardRCross = ColBlock->GetRightTop() - ColBlock->GetLeftBottom(); //대각선 반대
//
//FVector StandardVector = { StandardCross.hX() / StandardCross.X , StandardCross.hY() / StandardCross.Y};
//
//
//float BlockBDH = _NewBlock->GetTransform().Top() - _NewBlock->GetTransform().Bottom();
//float BlockX = BlockScale.Left.X - BlockScale.Right.X ;
////float BlockY = BlockScale.
//// 중심 
//
//float BallScaleX = CurBallPos.X + BallSize.X;
//float BallScaleY = CurBallPos.Y + BallSize.Y;
//
//int a = 0;
	
	


	
	
}
//상하좌우 알아내기
