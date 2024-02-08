#include "User.h"
#include <EngineCore\EngineCore.h>
#include <EngineBase/EngineTime.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/EngineResourcesManager.h>
#include <EngineBase/EngineMath.h>

#include"CollisonManger.h"
#include <vector>
#include <list>
#include "Bullet.h"
User::User()
{
}

User::~User()
{
}

void User::BeginPlay()
{
	AActor::BeginPlay(); //Actor���� ��ӹ޾ƿ� BeginePlay()�� ��������ش� ������ ������ ����ִ�.

	//�������� ��������
	
	UImageRenderer* PlayerRenderer = CreateImageRenderer(1);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Idle.png", 1, 6);
	PlayerRenderer->SetImage("Player_Idle.png");
	PlayerRenderer->SetTransform({ { 300,480 },{ 68,16} });
	PlayerRenderer->CreateAnimation("PlayerIdleAnimation", "Player_Idle.png",0,5,0.1f,true);
	PlayerRenderer->ChangeAnimation("PlayerIdleAnimation");
	
	
	//SetActorLocation({16,4,32,8});








	//SetActorLocation({ 200, 500 });


}


void User::Tick(float _DeltaTime) //��ŸŸ���� ���� �ð��̴� �����Ӹ��� �ð��� �ٸ��� �ϸ� ���ɿ� ���� �ð��� �޶����� ������ �ȵȴ�.
{
	
	
	if (true == UEngineInput::IsPress('A'))
	{
		AddActorLocation(FVector::Left * 500.0f * _DeltaTime);
	}

	if (true == UEngineInput::IsPress('D'))
	{
		AddActorLocation(FVector::Right * 500.0f * _DeltaTime);
	}


	//PlayerRenderer->ChangeAnimation("PlayerIdleAnimation");
	//AutoShot(_DeltaTime);

}

void User::CheckCol()
{
	
	
}
// void User::AutoShot(float _DeltaTime)
// {
// 	time += _DeltaTime;
// 
// 	
// 	if (time >= 2)
// 	{
// 		ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>();
// 		NewBullet->SetActorLocation(GetActorLocation());
// 		NewBullet->SetDir(FVector::Up);
// 		time = 0;
// 
// 		//�Ѿ��� ��� ������ .
// 	}
// }