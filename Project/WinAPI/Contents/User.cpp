#include "User.h"
#include <EngineBase/EngineTime.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineMath.h>
#include "ArkanoidCore.h"

#include"CollisonManger.h"
#include <vector>
#include <list>
#include "Bullet.h"
#include "Ball.h"
FVector User::CurPos = {};
FVector User::UserScale = {};
User::User()
{
}

User::~User()
{
}

void User::BeginPlay()
{
	AActor::BeginPlay(); //Actor���� ��ӹ޾ƿ� BeginePlay()�� ��������ش� ������ ������ ����ִ�.
	UserScale = this->GetTransform().GetScale();
	//�������� ��������
	SetActorLocation({ 300,480 });
	CurPos = GetActorLocation();
	UImageRenderer* PlayerRenderer = CreateImageRenderer(0);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Idle.png", 1, 6);
	PlayerRenderer->SetImage("Player_Idle.png");
	PlayerRenderer->SetTransform({ { 0,0 },{ 68,16} });
	PlayerRenderer->CreateAnimation("PlayerIdleAnimation", "Player_Idle.png",0,5,0.1f,true);
	PlayerRenderer->ChangeAnimation("PlayerIdleAnimation");
	
	int a = 0;


	//SetActorLocation({16,4,32,8});
	//SetActorLocation({ 200, 500 });


}


void User::Tick(float _DeltaTime) //��ŸŸ���� ���� �ð��̴� �����Ӹ��� �ð��� �ٸ��� �ϸ� ���ɿ� ���� �ð��� �޶����� ������ �ȵȴ�.
{
	CurPos = GetActorLocation();
	FVector MovePos = FVector::Zero;
	FVector NextPos = GetActorLocation();
	CurPos = NextPos;
	if (true == UEngineInput::IsPress('A'))
	{
		MovePos = FVector::Left * 500.0f * _DeltaTime;
		NextPos += MovePos;
		//AddActorLocation(MovePos);
	}

	if (true == UEngineInput::IsPress('D'))
	{
		MovePos = FVector::Right * 500.0f * _DeltaTime;
		NextPos += MovePos;
	}

	if (NextPos.X <= 50 || NextPos.X >= 500)
	{
		return;
	}
	AddActorLocation(MovePos);

	

	
}





/*
void ������()



if(Input(' ');

void User::AutoShot(float _DeltaTime)
 {
	if (true == Isballlive)
	{
		return;
	}
	time += _DeltaTime;
	if (time >= 2)
	{

		Ball* NewBall = GetWorld()->SpawnActor<Ball>(); //���⼭ ���� ������
		NewBall->Move(CurPos);
		NewBall->SetActorLocation({ CurPos.X,CurPos.Y - 10 });//�÷��̾��� �������� ����

		NewBall->DirCheck();
		Isballlive = true;
		time = 0;
		//���� ������� �ٽ� ����� �Ұ��̴�.

	}

//
// ������ ������ �Ծ����� �����̽��ٸ� ������ ���� �Լ�
// 	if (time >= 2)
// 	{
// 		//�Ѿ��� ��� ������ .
// 	}
 }



{

 ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>();
 NewBullet->SetActorLocation(GetActorLocation());
 NewBullet->SetDir(FVector::Up);
 time = 0;
} 
*/
