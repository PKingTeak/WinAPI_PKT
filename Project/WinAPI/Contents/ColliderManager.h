#pragma once
#include "ArkanoidCore.h"
#include"User.h"
#include"Ball.h"
#include"Block.h"
#include"Item.h"
// Ό³Έν :

enum class ColliderOrder
{
	Block,
	Ball,
	Item,
	Player

};



class ColliderManager : public ArkanoidCore
{


public:
	// constrcuter destructer
	ColliderManager();
	~ColliderManager();

	// delete Function
	ColliderManager(const ColliderManager& _Other) = delete;
	ColliderManager(ColliderManager&& _Other) noexcept = delete;
	ColliderManager& operator=(const ColliderManager& _Other) = delete;
	ColliderManager& operator=(ColliderManager&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DetaTime) override;

private:
	User* ColUser = nullptr;
	//Ball* ColBall = nullptr;
	Block* ColBlock = nullptr;
};

