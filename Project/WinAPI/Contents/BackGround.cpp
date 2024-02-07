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
	//UEngineResourcesManager::GetInst().CuttingImage("TitleBackGround.bmp", 522, 602);여러개 이미지 있는거 자를때
	BackGroundRender = CreateImageRenderer();
	//SetActorLocation({ 0,0 });
	BackGroundRender->SetImage("TitleBackGround.png");
	SetActorLocation({400,300 ,640,480});//수치상으로 하는거 안좋으니 변수로 변경
	//BackGroundRender->SetImageCuttingTransform({ {0,0},{522,602} });<- 이건 랜더러
	BackGroundRender->SetTransform({ { 0,0 },{ 800,600 } });
	//BackGroundRender->CreateAnimation(); 아직 애니메이션 안넣음

}
void BackGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}