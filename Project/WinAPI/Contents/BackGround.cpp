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



	//UEngineResourcesManager::GetInst().CuttingImage("TitleBackGround.bmp", 522, 602);������ �̹��� �ִ°� �ڸ���
	//SetActorLocation({ 0,0 });
	//BackGroundRender->SetImageCuttingTransform({ {0,0},{522,602} });<- �̰� ������
	//BackGroundRender->CreateAnimation(); ���� �ִϸ��̼� �ȳ���

}
void BackGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}