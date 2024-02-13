#include "Ball.h"
#include <EngineCore/EngineResourcesManager.h>
#include "User.h"
#include <EnginePlatform/EngineInput.h>
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
	//어쩌피 방향벡터를 정해줬으니 구지 필요없는거 아닐까?
}

void Ball::DirCheck()
{
	CurBallPos = GetActorLocation(); //내 위치를 알아야 하니까 
	if (CurBallPos.X <= 5)
	{
		BallX = 1;
		BallY = 1;
		//BDir = { 1,1/*진행방향으로 가고픔*/}; //여기를 변경하면 될듯 하다. 방향으로 하지말고 벡터값을 주면서 변경을 시켜보자. 
	}
	else if (CurBallPos.X >= 500)
	{
		BallX = -1;
		BallY = -1;
		//BDir = {-1,-1};
	}

	if (CurBallPos.Y <= 50)
	{
		BallX = -1;
		BallY = 1;
		//BDir = {-1,1};
	}
	else if (CurBallPos.Y >= User::CurPos.Y-10)
	{
		//원래 공을 제거 해야됨 시작 위치로 다시 위치시켜야됨
		BallX = 1;
		BallY = -1;
		//BDir = {1,-1};

	}
	BDir = { BallX,BallY };
	//수정 좀만 더 보자 
}





void Ball::Move(FVector _StartPos)
{
	CurBallPos = _StartPos; //시작 위치 
	
}

