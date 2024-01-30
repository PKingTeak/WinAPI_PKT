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
		UImageRenderer* BulletRender = CreateImageRenderer(0); //-모양의 총알
		BulletRender->SetScale({ 50, 10 });
		BulletRender->SetImage("TestImage.bmp");

	}

	Destroy(2.0f); //파괴 2초후에 사실 필요 없는기능
}

void ABullet::Tick(float _DeltaTime)
{
	AddActorLocation(Dir * Speed * _DeltaTime);
}

//	HDC WindowDC = GEngine->MainWindow.GetWindowDC();
//	FTransform Trans = GetTransform();
//	Rectangle(WindowDC, Trans.iLeft(), Trans.iTop(), Trans.iRight(), Trans.iBottom());
//이제 필요가 없다 이유는 내부에 숨겼기 때문에 사용할 필요가 없어졌다.
