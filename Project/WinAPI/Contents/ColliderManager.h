#pragma once

// Ό³Έν :

enum class ColiiderOrder
{
	Block,
	Ball,
	Player

};



class ColliderManager
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

private:

};

