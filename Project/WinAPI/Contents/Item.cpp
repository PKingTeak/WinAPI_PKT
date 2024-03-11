#include "Item.h"
#include<EngineCore/ImageRenderer.h>
#include<EngineBase/EngineMath.h>
#include"ColliderManager.h"
#include<EngineBase/EngineRandom.h>
#include"Ball.h"
#include <EngineCore/EngineDebug.h>
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
	this->Destroy();
}

void Item::BeginPlay()
{
	MainItem = this;
	AActor::BeginPlay();
	SetActorLocation({ 200,100 });
	UImageRenderer* ItemRender = CreateImageRenderer();
	UEngineResourcesManager::GetInst().CuttingImage("Item.png", 8, 8);
	ItemRender->SetTransform({ {0,0}, ItemScale * 2 });
	ItemRender->SetImage("Item.png");
	ItemRender->CreateAnimation("SLowItemAnimation", "Item.png", 0, 7, 0.5f, true);
	ItemRender->CreateAnimation("LifeAnimation", "Item.png", 48, 55, 0.5f, true);
	ItemRender->CreateAnimation("EnlargeAnimation", "Item.png", 24, 31, true);
	ChangeItemAnimation();
	ItemRender->ChangeAnimation(ItemName);
	ItemCollison = CreateCollision(ColliderOrder::Item);
	ItemCollison->SetColType(ECollisionType::Rect);
	


	
	
}





Item* Item::GetMainItem()
{
	return MainItem;
}

void Item::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	PlayerColCheck();

	FVector CurPos = GetActorLocation();
	std::string CurstringX = std::to_string(CurPos.X);
	std::string CurStringY = std::to_string(CurPos.Y);
	UEngineDebug::DebugTextPrint(CurstringX, 24);
	UEngineDebug::DebugTextPrint(CurstringX, 20);
	
	
	if (true != this->IsActive())
	{
		this->ChangeItemAnimation();
	}
	AddActorLocation(FVector::Down * _DeltaTime * 100.0f);
	

	if (this->GetActorLocation().Y > 650)
	{
		this->Destroy();
	}
	//아래로 내려줄것인데 
	

}


void Item::ChangeItemAnimation()
{
	
	int Num = ChangeItem();
	//ChangeItem();
	switch (Num)
	{
	case 1:
		ItemName = "SLowItemAnimation";
		break;

	case 2:
		ItemName = "EnlargeAnimation";
		break;

	case 3:
		ItemName = "LifeAnimation";
		break;
	default:
		break;
	}

}


void Item::PlayerColCheck()
{
	float ItemPosX = this->GetActorLocation().X;
	float ItemPosY = this->GetActorLocation().Y;
	
	float MinUserX = User::CurPos.X - User::UserScale.X;
	float MaxUserX = User::CurPos.X + User::UserScale.X;

	Ball* NewBall = Ball::GetMainBall();
	

	if (ItemPosX > MinUserX && ItemPosX < MaxUserX+1)
	{
		if (ItemPosY >= User::CurPos.Y-1 && ItemPosY<User::CurPos.Y+3)
		{
			if (ItemName == "EnlargeAnimation")
			{
			User::GetMainUser()->SetPlayerState(PlayerState::PEnlarge, User::GetMainUser());
		
			this->Destroy();
			}
			
			if (ItemName == "LifeAnimation")
			{
				User::GetMainUser()->PlayerLifePlus();
				isSlow = false;
				this->Destroy();
			}

			if (ItemName == "SLowItemAnimation")
			{
				
				NewBall->SetSpeed(200.0f);
				isSlow = true;
				this->Destroy();
			}
			
			if (isSlow == false)
			{
				NewBall->SetSpeed(300.0f);
			}
			

			
		}

	}
	bool isCol = false;
	
	

	

	
}
int Item::ChangeItem()
{
	
	RandomNum = UEngineRandom::MainRandom.RandomInt(1, 3);
	PreNum =  RandomNum;
	return RandomNum;

}

UCollision* Item::GetItemCollison()
{
	return ItemCollison;

}



