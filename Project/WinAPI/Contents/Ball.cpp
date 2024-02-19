#include "Ball.h"
#include <EngineCore/EngineResourcesManager.h>
#include "User.h"
#include <EnginePlatform/EngineInput.h>
#include <vector>
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
	BallRender->SetScale({ 10,8 });
	GetUserScale();
	SetActorLocation({ User::CurPos.X,User::CurPos.Y - 10 });

	BallCollison = CreateCollision(ColliderOrder::Ball);
	BallCollison->SetColType(ECollisionType::Point);
	BallCollison->SetScale({ 10,8 });
	BallCollison->SetColType(ECollisionType::CirCle);

}
void Ball::SetPos(FVector _CurPos)
{

	CurBallPos = _CurPos;

}
void Ball::GetUserScale()
{
	FVector UScale = { User::CurPos.hX() , User::CurPos.hY() };
	int a = 0;
}



void Ball::Tick(float _DeltaTime)
{
	
	if (false == IsballLive)
	{
		SetActorLocation({ User::CurPos.X,User::CurPos.Y - 10 });
	}
	Time += _DeltaTime;
	AActor::Tick(_DeltaTime);
	GameStart(Time);
	DirCheck();

	std::vector<UCollision*> Result;
	if (true == BallCollison->CollisionCheck(ColliderOrder::Player, Result))
	{
	
		Reflect(CurBallPos);
	}


	if (IsballLive == true)
	{

		Move(_DeltaTime);

		SetActorLocation({ GetActorLocation() });
	}
	else if (UEngineInput::IsDown(' '))
	{
		IsballLive = true;
	}

}


void Ball::DirCheck()
{
	CurBallPos = GetActorLocation(); //내 위치를 알아야 하니까 
	if (CurBallPos.X <= 30)
	{
		Reflect(CurBallPos);
		//BDir = { 1,1/*진행방향으로 가고픔*/}; //여기를 변경하면 될듯 하다. 방향으로 하지말고 벡터값을 주면서 변경을 시켜보자. 
	}
	else if (CurBallPos.X >= 520)
	{
		//BDir = {-1,-1};
		Reflect(CurBallPos);
	}

	if (CurBallPos.Y <= 50)
	{
		Reflect(CurBallPos);
		//YReflect();
		//BDir = {-1,1};
	}
	else if (CurBallPos.Y >= User::CurPos.Y)
	{
		User::UserScale.Y;
		/*
		플레이어 크기를 가져와서 크기안에 들어오면 날아가게 할것이다.
		*/
		Reflect(CurBallPos);
		//원래 공을 제거 해야됨 시작 위치로 다시 위치시켜야됨

	}

	//수정 좀만 더 보자 
}


void Ball::GameStart(float _DeltaTime)
{

	if (true == IsballLive)
	{
		return;
	}

	if (Time >= 1)
	{

		IsballLive = true;
		Time = 0;
	}

}


void Ball::StartPos(FVector _StartPos)
{
	CurBallPos = _StartPos; //시작 위치 

}


Ball* Ball::GetMainBall()
{

	return MainBall;
}


void Ball::Move(float _DeltaTime)
{
	BDir.Normalize2D();

	AddActorLocation(BDir * Speed * _DeltaTime);//공이이동한다.

	FVector a = GetActorLocation();

	//이걸로 각도 조절하면될듯 하다. 
}
void Ball::Reflect(FVector _CurBallPos)
{
	FVector CurBallPos = _CurBallPos;
	UCollision* PlayerCollision = User::GetUserCollider(); //유저 충돌타입 가져오기
	if (CurBallPos.X >= 520)
	{

		FVector N = { -1,0 };
		FVector N2 = { -2,0 };
		FVector T = { (-1 * BDir.X) * N.X,(-1 * BDir.Y) * N.Y }; //(-P * n)
		BDir = BDir + (N2 * T); //R
		//N을 구하는걸 못하겠음?
	}
	else if (CurBallPos.X <= 30)
	{
		FVector N = { 1,0 };
		FVector N2 = { 2,0 };
		FVector T = { (-1 * BDir.X) * N.X,(-1 * BDir.Y) * N.Y }; //(-P * n)
		BDir = BDir + (N2 * T); //R
	}
	else if (CurBallPos.Y <= 50)
	{
		FVector N = { 0,1 };
		FVector N2 = { 0,2 };
		FVector T = { (-1 * BDir.X) * N.X,(-1 * BDir.Y) * N.Y }; //(-P * n)
		BDir = BDir + (N2 * T); //R

	}
	else if (true == BallCollison->CollisionCheck(ColliderOrder::Player, Result))
		{

			FVector N = { 0,-1 };
			FVector N2 = { 0,-2 };
			FVector T = { (-1 * BDir.X) * N.X,(-1 * BDir.Y) * N.Y }; //(-P * n)
			BDir = BDir + (N2 * T); //R
		}


}

