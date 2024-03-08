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
	SetActorLocation({270,304 ,224*2,240*2});//��ġ������ �ϴ°� �������� ������ ����
	BackGroundRender->SetTransform({ { 0,0 },{ 224*2,240*2 } });



	
}


void BackGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}