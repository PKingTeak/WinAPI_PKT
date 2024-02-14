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
	if (false == IsballLive)
	{
	SetActorLocation({ User::CurPos.X,User::CurPos.Y - 10 });
	}
	Time += _DeltaTime;
	AActor::Tick(_DeltaTime);
	GameStart(Time);
	DirCheck();
	if (IsballLive == true)
	{
		Move(_DeltaTime);
	}
	else if (UEngineInput::IsDown(' '))
	{
		IsballLive = true;
	}
	
}

void Ball::DirCheck()
{
	CurBallPos = GetActorLocation(); //�� ��ġ�� �˾ƾ� �ϴϱ� 
	if (CurBallPos.X <= 30)
	{
		Reflect(CurBallPos);
		//BDir = { 1,1/*����������� ������*/}; //���⸦ �����ϸ� �ɵ� �ϴ�. �������� �������� ���Ͱ��� �ָ鼭 ������ ���Ѻ���. 
	}
	else if (CurBallPos.X > 510)
	{
		//BDir = {-1,-1};
		Reflect(CurBallPos);
	}

	if (CurBallPos.Y < 50)
	{
		Reflect(CurBallPos);
		//YReflect();
		//BDir = {-1,1};
	}
	else if (CurBallPos.Y >= User::CurPos.Y-10)
	{
		Reflect(CurBallPos);
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


void Ball::StartPos(FVector _StartPos)
{
	CurBallPos = _StartPos; //���� ��ġ 
	
}

void Ball::Block()
{
	
}


void Ball::Move(float _DeltaTime)
{
	BDir.Normalize2D();

	AddActorLocation(BDir * Speed * _DeltaTime);//�����̵��Ѵ�.

	//�̰ɷ� ���� �����ϸ�ɵ� �ϴ�. 
}
void Ball::Reflect(FVector _CurBallPos)
{
	FVector CurBallPos = _CurBallPos;
	if (CurBallPos.X >= 510)
	{

	FVector N = { -1,0 };
	FVector N2 = { -2,0 };
	FVector T = { (-1 * BDir.X) * N.X,(-1 * BDir.Y) * N.Y }; //(-P * n)
	BDir = BDir + (N2 * T); //R
	//N�� ���ϴ°� ���ϰ���?
	}
	else if(CurBallPos.X <= 30)
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
	else if (CurBallPos.Y >= User::CurPos.Y)
	{
	//	FVector N = { 0,-1 };
	//	FVector N2 = { 0,-2 };
	//	FVector T = { (-1 * BDir.X) * N.X,(-1 * BDir.Y) * N.Y }; //(-P * n)
	//	BDir = BDir + (N2 * T); //R
	}


	
	
	//
	int a = 0;
}
 
//void Ball::YLReflect()
//{	  //
//	  //
//}	  //
//
/*

R= P + 2n(-P * n)

BDir =  BDir +NCurBallPos(Cos);
*/