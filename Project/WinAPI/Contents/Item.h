#pragma once
#include<EngineCore/Actor.h>
#include<EngineCore/EngineResourcesManager.h>
#include"ArkanoidCore.h"
// Ό³Έν :
class Item :public AActor
{
private:
	static Item* MainItem;
public:
	// constrcuter destructer
	Item();
	
	~Item();

	// delete Function
	Item(const Item& _Other) = delete;
	Item(Item&& _Other) noexcept = delete;
	Item& operator=(const Item& _Other) = delete;
	Item& operator=(Item&& _Other) noexcept = delete;
	
	
	void SpawnItem();

	static UCollision* GetItemCollison();
	static Item* GetMainItem();
	
protected:
	void BeginPlay() override;
	void Tick(float _detaTime) override;
private:
	int ChangeItem();
	void PlayerColCheck();
	UImageRenderer* ItemRender = nullptr;
	UImageRenderer* LifeRender = nullptr;
	UImageRenderer* EnlargeRender = nullptr;
	FVector ItemScale = {16,8};
	static UCollision* ItemCollison;
	bool isLive = false;
	bool isCol = false;
	int ItemCounter = 0;
	int MaxItemCounter = 2;
	std::string ItemName = "";
	int RandomNum = 0;
	int PreNum = 0;

};

