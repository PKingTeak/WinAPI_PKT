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
		UImageRenderer* BulletRender = CreateImageRenderer(0); //-����� �Ѿ�
		BulletRender->SetScale({ 50, 10 });
		BulletRender->SetImage("TestImage.bmp");

	}

	Destroy(2.0f); //�ı� 2���Ŀ� ��� �ʿ� ���±��
}

void ABullet::Tick(float _DeltaTime)
{
	AddActorLocation(Dir * Speed * _DeltaTime);
}

//	HDC WindowDC = GEngine->MainWindow.GetWindowDC();
//	FTransform Trans = GetTransform();
//	Rectangle(WindowDC, Trans.iLeft(), Trans.iTop(), Trans.iRight(), Trans.iBottom());
//���� �ʿ䰡 ���� ������ ���ο� ����� ������ ����� �ʿ䰡 ��������.
