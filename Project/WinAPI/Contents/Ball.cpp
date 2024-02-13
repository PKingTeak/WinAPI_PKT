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
	BallRender->SetImage("Ball.png"); 
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
	if (CurBallPos.X <= 5)
	{
		BDir = { 1,1/*진행방향으로 가고픔*/}; //여기를 변경하면 될듯 하다. 방향으로 하지말고 벡터값을 주면서 변경을 시켜보자. 
	}
	else if (CurBallPos.X >= 500)
	{
		BDir = {-1,-1};
	}

	if (CurBallPos.Y <= 50)
	{
		BDir = {-1,1};
	}
	else if (CurBallPos.Y >= User::CurPos.Y-10)
	{
		//공을 제거 해야됨 
		BDir = {1,-1};

	}

	//수정 좀만 더 보자 
}





void Ball::Move(FVector _StartPos)
{
	CurBallPos = _StartPos; //시작 위치 
	
}

