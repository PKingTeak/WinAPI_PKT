#include "Ball.h"
#include <EngineCore/EngineResourcesManager.h>
#include "User.h"
Ball::Ball()
{

}
Ball::~Ball()
{}




void Ball::BeginPlay()
{
	AActor::BeginPlay();
	BallRender = CreateImageRenderer(0);
	UEngineResourcesManager::GetInst().CuttingImage("Ball.png", 1, 1);
	BallRender->SetImage("Ball.png"); //아직 없음
	BallRender->SetScale({ 10,8 });

	
}
void Ball::SetPos(FVector _CurPos)
{
	CurBallPos = _CurPos;

}


void Ball::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	DirCheck();
	AddActorLocation(BDir * Speed * _DeltaTime);//공이이동한다.
	

}

void Ball::DirCheck()
{
	CurBallPos = GetActorLocation();
	if (CurBallPos.X <= 0)
	{
		BDir = BDir.Right;
	}
	else if (CurBallPos.X >= 500)
	{
		BDir = BDir.Left;
	}

	if (CurBallPos.Y <= 50)
	{
		BDir = BDir.Down;
	}
	else if (CurBallPos.Y >= User::CurPos.Y-10)
	{
		//공을 제거 해야됨 
		BDir = BDir.Up;

	}
}





void Ball::Move(FVector _StartPos)
{
	CurBallPos = _StartPos;
	
}

