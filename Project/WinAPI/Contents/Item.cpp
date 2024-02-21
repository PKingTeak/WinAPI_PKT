#include "Item.h"
#include<EngineCore/ImageRenderer.h>
#include<EngineBase/EngineMath.h>
Item::Item()
{
}

Item::~Item()
{
}

void Item::BeginPlay()
{
	AActor::BeginPlay();
	SetActorLocation({ 200,100 });
	UImageRenderer* ItemRender = CreateImageRenderer();
	UEngineResourcesManager::GetInst().CuttingImage("Item.png", 8, 8);
	ItemRender->SetImage("Item.png");
	ItemRender->SetScale({ 16,8 });
	ItemRender->SetTransform({ {0,0}, {16,8} });
	ItemRender->CreateAnimation("ItemAnimation", "Item.png",0, 7, true);
	ItemRender->ChangeAnimation("ItemAnimation");



}

void Item::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}