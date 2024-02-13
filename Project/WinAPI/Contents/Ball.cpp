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
	
	SetActorLocation({ User::CurPos.X,User::CurPos.Y - 10 });
	BallRender = CreateImageRenderer(0);
	UEngineResourcesManager::GetInst().CuttingImage("Ball.png", 1, 1);
	Move({ User::CurPos.X,User::CurPos.Y - 10 });
	BallRender->SetImage("Ball.png"); 
	BallRender->SetScale({ 10,8 });

	
}
void Ball::SetPos(FVector _CurPos)
{
	CurBallPos = _CurPos;

}


void Ball::Tick(float _DeltaTime)
{
	
	Time += _DeltaTime;
	AActor::Tick(_DeltaTime);
	GameStart(Time);
	DirCheck();
	if (IsballLive == true)
	{
	AddActorLocation(BDir * Speed * _DeltaTime);//�����̵��Ѵ�.
	}
	//��¼�� ���⺤�͸� ���������� ���� �ʿ���°� �ƴұ�?
	
}

void Ball::DirCheck()
{
	CurBallPos = GetActorLocation(); //�� ��ġ�� �˾ƾ� �ϴϱ� 
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
		//���� ���� ���� �ؾߵ� ���� ��ġ�� �ٽ� ��ġ���Ѿߵ�
	
		BDir = {1,-1};

	}
	
	//���� ���� �� ���� 
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


void Ball::Move(FVector _StartPos)
{
	CurBallPos = _StartPos; //���� ��ġ 
	
}

