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
	//UEngineResourcesManager::GetInst().CuttingImage("TitleBackGround.bmp", 522, 602);������ �̹��� �ִ°� �ڸ���
	BackGroundRender = CreateImageRenderer();
	//SetActorLocation({ 0,0 });
	BackGroundRender->SetImage("TitleBackGround.png");
	SetActorLocation({276,304 ,552,602});//��ġ������ �ϴ°� �������� ������ ����
	//BackGroundRender->SetImageCuttingTransform({ {0,0},{522,602} });<- �̰� ������
	BackGroundRender->SetTransform({ { 0,0 },{ 552,600 } });
	//BackGroundRender->CreateAnimation(); ���� �ִϸ��̼� �ȳ���

}
void BackGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}