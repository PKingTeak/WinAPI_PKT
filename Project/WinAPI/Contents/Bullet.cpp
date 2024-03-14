#include "Bullet.h"
#include <Windows.h>
#include <EngineCore\EngineCore.h>

ABullet::ABullet()
{
}

ABullet::~ABullet()
{
}


void ABullet::BeginPlay()
{
	
	{
	//UImageRenderer* BulletRender = CreateImageRenderer(0); //-모양의 총알
	//BulletRender->SetScale({ 50, 10 });
	//BulletRender->SetImage("TestImage.bmp");

	}

	//Destroy(2.0f); //파괴 2초후에 사실 필요 없는기능
}

void ABullet::Tick(float _DeltaTime)
{
	AddActorLocation(Dir * Speed * _DeltaTime);
}
