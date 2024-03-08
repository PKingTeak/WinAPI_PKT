#include "Item.h"
#include<EngineCore/ImageRenderer.h>
#include<EngineBase/EngineMath.h>
#include"ColliderManager.h"
#include<EngineBase/EngineRandom.h>
Item* Item::MainItem = nullptr;
UCollision* Item::ItemCollison = nullptr;

enum ItemType
{
	Slow = 0,
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
	ItemRender->CreateAnimation("SLowItemAnimation", "Item.png",0, 7, 0.5f, true);
	ItemRender->CreateAnimation("LifeAnimation", "Item.png", 48, 55, 0.5f, true);
	ItemRender->CreateAnimation("EnlargeAnimation", "Item.png", 24, 31, true);
	SpawnItem();
	ItemRender->ChangeAnimation(ItemName);

	ItemCollison = CreateCollision(ColliderOrder::Item);
	ItemCollison->SetColType(ECollisionType::Rect);
	


	

}
void Item::SpawnItem()
{
	int Num = DropItem();
	switch (Num)
	{
	case 1 : 
		ItemName = "SLowItemAnimation";

		break;

	case 2:
		ItemName = "EnlargeAnimation";
		break;

	case 3:
		ItemName ="LifeAnimation";
		break;
	default:
		break;
	}
	
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
	PlayerColCheck();
	if (true == this->IsActive())
	{
		AddActorLocation(FVector::Down * _DeltaTime * 100.0f);
		isLive = true;
	}
	


	//아래로 내려줄것인데 
	

}

void Item::PlayerColCheck()
{
	float ItemPosX = this->GetActorLocation().X;
	float ItemPosY = this->GetActorLocation().Y;
	
	float MinUserX = User::CurPos.X - User::CurPos.X;
	float MaxUserX = User::CurPos.X + User::CurPos.X;


	if (ItemPosX > MinUserX && ItemPosY < MaxUserX)
	{
		if (ItemPosY >= User::CurPos.Y-1 && ItemPosY<User::CurPos.Y+3)
		{
		
		isCol = true;
		ItemCounter++;

		this->Destroy(); 

		}
	}
	isCol = false;


	
}
int Item::DropItem()
{
	UEngineRandom Random = UEngineRandom();
	int RandomNum = Random.RandomInt(1, 3);
	return RandomNum;

}

UCollision* Item::GetItemCollison()
{
	return ItemCollison;

}



