#include "BackGround.h"
#include <EngineCore/EngineResourcesManager.h>
BackGround::BackGround()
{

}

BackGround::~BackGround()
{

}

void BackGround::BeginPlay()
{
	AActor::BeginPlay();
	BackGroundRender = CreateImageRenderer();
	BackGroundRender->SetImage("TitleBackGround.png");
	SetActorLocation({276,304 ,552,602});//��ġ������ �ϴ°� �������� ������ ����
	BackGroundRender->SetTransform({ { 0,0 },{ 552,600 } });



	
}


void BackGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}