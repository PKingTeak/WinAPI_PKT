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
	//UEngineResourcesManager::GetInst().CuttingImage("Ball.png", 1, 1);
	BallRender->SetImage("Ball.png"); //아직 없음
	BallRender->SetTransform({ { 0,0 }, {10,8} });

	
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
	BDir;

}

void Ball::DirCheck()
{
	if (CurBallPos.X <= 0)
	{
		BDir = BDir.Right;
	}
	else if (CurBallPos.X >= 500)
	{
		BDir = BDir.Left;
	}

	if (CurBallPos.Y <= 0)
	{
		BDir = BDir.Down;
	}
	else if (CurBallPos.Y >= 600)
	{
		//공을 제거 해야됨 
		BDir = BDir.Up;

	}
}


/*

void Ball::Move(float _DetaTime)
{
	if (Dir.X <= 0)
	{
	Dir.X += _DetaTime;
	}
	else if (Dir.X >= 500)
	{
		Dir.X += ( - 1 * _DetaTime);
	}
	else if (Dir.Y <= 0)
	{
		Dir.Y += _DetaTime;
	}
}
*/
