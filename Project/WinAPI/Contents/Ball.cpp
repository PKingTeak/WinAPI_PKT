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
	AddActorLocation(BDir * Speed * _DeltaTime);//�����̵��Ѵ�.
	//��¼�� ���⺤�͸� ���������� ���� �ʿ���°� �ƴұ�?
}

void Ball::DirCheck()
{
	CurBallPos = GetActorLocation(); //�� ��ġ�� �˾ƾ� �ϴϱ� 
	if (CurBallPos.X <= 5)
	{
		BallX = 1;
		BallY = 1;
		//BDir = { 1,1/*����������� ������*/}; //���⸦ �����ϸ� �ɵ� �ϴ�. �������� �������� ���Ͱ��� �ָ鼭 ������ ���Ѻ���. 
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
		//���� ���� ���� �ؾߵ� ���� ��ġ�� �ٽ� ��ġ���Ѿߵ�
		BallX = 1;
		BallY = -1;
		//BDir = {1,-1};

	}
	BDir = { BallX,BallY };
	//���� ���� �� ���� 
}





void Ball::Move(FVector _StartPos)
{
	CurBallPos = _StartPos; //���� ��ġ 
	
}

