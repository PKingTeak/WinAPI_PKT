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
	AddActorLocation(BDir * Speed * _DeltaTime);//�����̵��Ѵ�.
	

}

void Ball::DirCheck()
{
	CurBallPos = GetActorLocation();
	if (CurBallPos.X <= 5)
	{
		BDir = { 1,1/*����������� ������*/}; //���⸦ �����ϸ� �ɵ� �ϴ�. �������� �������� ���Ͱ��� �ָ鼭 ������ ���Ѻ���. 
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
		//���� ���� �ؾߵ� 
		BDir = {1,-1};

	}

	//���� ���� �� ���� 
}





void Ball::Move(FVector _StartPos)
{
	CurBallPos = _StartPos; //���� ��ġ 
	
}

