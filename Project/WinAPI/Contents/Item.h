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
	
	
	void ChangeItemAnimation();
	void SpawnItem(std::string_view _ItemName);
	static UCollision* GetItemCollison();
	static Item* GetMainItem();
	UImageRenderer* ItemRender = nullptr;
	
protected:
	void BeginPlay() override;
	void Tick(float _detaTime) override;
private:
	int ChangeItem();
	void PlayerColCheck();
	FVector ItemScale = {16,8};
	static UCollision* ItemCollison;
	bool isLive = false;
	bool isCol = false;
	std::string ItemName = "";
	int ItemCounter = 0;
	int MaxItemCounter = 2;
	int RandomNum = 0;
	int PreNum = 0;

};

