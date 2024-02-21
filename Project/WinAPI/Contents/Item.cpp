#include "Item.h"
#include<EngineCore/ImageRenderer.h>
#include<EngineBase/EngineMath.h>
#include"ColliderManager.h"
Item* Item::MainItem = nullptr;
UCollision* Item::ItemCollison = nullptr;
Item::Item()
{
}

Item::~Item()
{
}

void Item::BeginPlay()
{
	MainItem = this;
	AActor::BeginPlay();
	SetActorLocation({ 200,100 });
	UImageRenderer* ItemRender = CreateImageRenderer();
	UEngineResourcesManager::GetInst().CuttingImage("Item.png", 8, 8);
	ItemRender->SetImage("Item.png");
	ItemRender->SetTransform({ {0,0}, ItemScale*2 });
	ItemRender->CreateAnimation("ItemAnimation", "Item.png",0, 7, 0.5f, true);
	ItemRender->ChangeAnimation("ItemAnimation");


	ItemCollison = CreateCollision(ColliderOrder::Item);
	ItemCollison->SetColType(ECollisionType::Rect);



}

void Item::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	AddActorLocation(FVector::Down * _DeltaTime * 100.0f); 
	//�Ʒ��� �����ٰ��ε� 
	

}


UCollision* Item::GetItemCollison()
{
	return ItemCollison;

}


