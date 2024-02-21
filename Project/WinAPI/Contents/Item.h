#pragma once
#include<EngineCore/Actor.h>
#include<EngineCore/EngineResourcesManager.h>
#include"ArkanoidCore.h"
// Ό³Έν :
class Item :public AActor
{
public:
	// constrcuter destructer
	Item();
	~Item();

	// delete Function
	Item(const Item& _Other) = delete;
	Item(Item&& _Other) noexcept = delete;
	Item& operator=(const Item& _Other) = delete;
	Item& operator=(Item&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _detaTime) override;
private:
	UImageRenderer* ItemRender = nullptr;

	UCollision* ItemCollison = nullptr;


};

