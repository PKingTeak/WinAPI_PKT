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
	SetActorLocation({270,304});//수치상으로 하는거 안좋으니 변수로 변경
	BackGroundRender->SetTransform({ { 0,0 },{ 552, 602} });


	//224*2  240*2
	
}


void BackGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}