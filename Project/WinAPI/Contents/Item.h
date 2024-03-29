#pragma once
#include<EngineCore/Actor.h>
#include<EngineCore/EngineResourcesManager.h>
#include"ArkanoidCore.h"
#include "Ball.h"
// ���� :
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
	static UCollision* GetItemCollison();
	static Item* GetMainItem();
	UImageRenderer* ItemRender = nullptr;

	bool GetisSlow();
	bool isSlow = false;
	
	
	
protected:
	void BeginPlay() override;
	void Tick(float _detaTime) override;
private:
	int ChangeItem();
	void PlayerColCheck();
	FVector ItemScale = {16,8};
	static UCollision* ItemCollison;
	std::string ItemName = "";
	int RandomNum = 0;
	int PreNum = 0;
	

};

