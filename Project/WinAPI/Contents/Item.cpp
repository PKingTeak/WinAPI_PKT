#include "Item.h"
#include<EngineCore/ImageRenderer.h>
#include<EngineBase/EngineMath.h>
#include"ColliderManager.h"
#include<random>
Item* Item::MainItem = nullptr;
UCollision* Item::ItemCollison = nullptr;

enum ItemType
{
	Slow = 0,
	Catch = 1,
	Laser = 2,
	Enlarge = 3,
	LifeUP = 7
};


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
	ItemRender->CreateAnimation("LifeAnimation", "Item.png", 48, 55, 0.5f, true);
	ItemRender->ChangeAnimation("LifeAnimation");


	ItemCollison = CreateCollision(ColliderOrder::Item);
	ItemCollison->SetColType(ECollisionType::Rect);

	

	

}

void Item::SetItemType(int _ItemType)
{
	ItemRender->SetImage("Item.png", _ItemType);
	ItemRender->ChangeAnimation("LifeAnimation");


}

Item* Item::GetMainItem()
{
	return MainItem;
}

void Item::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	
	if (true == this->IsActive())
	{
		AddActorLocation(FVector::Down * _DeltaTime * 100.0f);
		isLive = true;
	}
	


	//�Ʒ��� �����ٰ��ε� 
	

}

UCollision* Item::GetItemCollison()
{
	return ItemCollison;

}



