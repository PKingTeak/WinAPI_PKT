#include "Ball.h"
#include <EngineCore/EngineResourcesManager.h>
#include "User.h"
#include <EnginePlatform/EngineInput.h>
#include <vector>
#include"Block.h"
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

	if (Time >= 3)    
	{
		isCol = true;
	}
	
	if (isCol == true)
	{
		IsCollide();

		//std::vector<UCollision*> Result;
		//if (true == BallCollison->CollisionCheck(ColliderOrder::Player, Result))
		//{
		//
		//	FVector N = { 0,-1 };
		//	FVector N2 = { 0,-2 };
		//	FVector T = { (-1 * BDir.X) * N.X,(-1 * BDir.Y) * N.Y }; //(-P * n)
		//	BDir = BDir + (N2 * T); //R
		//	isCol = true;
		//
		//}
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

void Ball::IsCollide()
{
	std::vector<UCollision*> Result;

	if(true == BallCollison->CollisionCheck(ColliderOrder::Player, Result))
	{

		FVector N = { 0,-1 };
		FVector N2 = { 0,-2 };
		FVector T = { (-1 * BDir.X) * N.X,(-1 * BDir.Y) * N.Y }; //(-P * n)
		BDir = BDir + (N2 * T); //R
		isCol = true;

	}
	else if (true == BallCollison->CollisionCheck(ColliderOrder::Block, Result))
	{
		UCollision* Collider = Result[0/*���°�϶�*/];
		AActor* ColAct = Collider->GetOwner();
		Block* ColBlock = dynamic_cast<Block*>(ColAct);
		BDir =  (BDir* -1);
		//Result[0]->Destroy();
		ColBlock->Destroy();
		//��¼�� ���͸� ����� ������ �ݸ��� �Ѵ� �ڵ����� �Ҹ��ڿ��� �����.

	

		int b = 0;
	}

}
UCollision* Ball::GetCollision()
{
	return BallCollison;

}


void Ball::DirCheck()
{
	CurBallPos = GetActorLocation(); //�� ��ġ�� �˾ƾ� �ϴϱ� 
	if (CurBallPos.X <= 30)
	{
		Reflect(CurBallPos);
		//BDir = { 1,1/*����������� ������*/}; //���⸦ �����ϸ� �ɵ� �ϴ�. �������� �������� ���Ͱ��� �ָ鼭 ������ ���Ѻ���. 
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
	//else if (CurBallPos.Y >= User::CurPos.Y)
	//{
	//	User::UserScale.Y;
	//	/*
	//	�÷��̾� ũ�⸦ �����ͼ� ũ��ȿ� ������ ���ư��� �Ұ��̴�.
	//	*/
	//	Reflect(CurBallPos);
	//	//���� ���� ���� �ؾߵ� ���� ��ġ�� �ٽ� ��ġ���Ѿߵ�
	//
	//}

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
		BallCollison->SetActive(true, 3.0f);
	}



}


void Ball::StartPos(FVector _StartPos)
{
	CurBallPos = _StartPos; //���� ��ġ 

}


Ball* Ball::GetMainBall()
{

	return MainBall;
}


void Ball::Move(float _DeltaTime)
{
	BDir.Normalize2D();

	AddActorLocation(BDir * Speed * _DeltaTime);//�����̵��Ѵ�.

	FVector a = GetActorLocation();

	//�̰ɷ� ���� �����ϸ�ɵ� �ϴ�. 
}
void Ball::Reflect(FVector _CurBallPos)
{
	FVector CurBallPos = _CurBallPos;
	UCollision* PlayerCollision = User::GetUserCollider(); //���� �浹Ÿ�� ��������
	if (CurBallPos.X >= 520)
	{

		FVector N = { -1,0 };
		FVector N2 = { -2,0 };
		FVector T = { (-1 * BDir.X) * N.X,(-1 * BDir.Y) * N.Y }; //(-P * n)
		BDir = BDir + (N2 * T); //R
		//N�� ���ϴ°� ���ϰ���?
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
	//else if (CurBallPos.Y >= User::CurPos.Y)
	//{
	//
	//}


}

