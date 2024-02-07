#include "User.h"
#include <EngineCore\EngineCore.h>
#include <EngineBase/EngineTime.h>
#include <EnginePlatform/EngineInput.h>
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
	PlayerRenderer->SetImage("Player_Idle.png");
	SetActorLocation({0,0,32,8});
	PlayerRenderer->SetTransform({ { 300,300 },{ 100,400 } });





	//SetActorLocation({ 200, 500 });


}

void User::Tick(float _DeltaTime) //��ŸŸ���� ���� �ð��̴� �����Ӹ��� �ð��� �ٸ��� �ϸ� ���ɿ� ���� �ð��� �޶����� ������ �ȵȴ�.
{

	if (true == EngineInput::IsPress('A'))
	{
		AddActorLocation(FVector::Left * 500.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('D'))
	{
		AddActorLocation(FVector::Right * 500.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('W'))
	{
		AddActorLocation(FVector::Up * 500.0f * _DeltaTime);
	}

	if (true == EngineInput::IsPress('S'))
	{
		AddActorLocation(FVector::Down * 500.0f * _DeltaTime);
	}
	//AutoShot(_DeltaTime);

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