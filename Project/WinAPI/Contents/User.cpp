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
	AActor::BeginPlay(); //Actor에서 상속받아와 BeginePlay()를 실행시켜준다 하지만 지금은 비어있다.


//{
	PlayerRenderer = CreateImageRenderer(0);				  		//좌표 이동 기준점 은 무조건 0으로 해야된다 이유는 랜더는 원래 있던 곳에서 똑같이 겹쳐야 하기 때문
	PlayerRenderer->SetPosition({ 0, 30 });				  		//좌표 이동 기준점 은 무조건 0으로 해야된다 이유는 랜더는 원래 있던 곳에서 똑같이 겹쳐야 하기 때문
	PlayerRenderer->SetImageToScale("TestImage.bmp");
//}
	SetActorLocation({ 200, 500 });
	SetActorScale({ 100, 50 });


}

void User::Tick(float _DeltaTime) //델타타임은 현재 시간이다 프레임마다 시간을 다르게 하면 성능에 따라 시간이 달라지기 때문에 안된다.
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
	AutoShot(_DeltaTime);

}
void User::AutoShot(float _DeltaTime)
{
	time += _DeltaTime;

	
	if (time >= 2)
	{
		ABullet* NewBullet = GetWorld()->SpawnActor<ABullet>();
		NewBullet->SetActorLocation(GetActorLocation());
		NewBullet->SetDir(FVector::Up);
		time = 0;

		//총알이 계속 나간다 .
	}
}