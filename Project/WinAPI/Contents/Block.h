#pragma once
#include <EngineCore/Actor.h>
#include<list>
class Block : public AActor
{

public:
	Block();
	~Block();

	// delete Function
	Block(const Block& _Other) = delete;
	Block(Block&& _Other) noexcept = delete;
	Block& operator=(const Block& _Other) = delete;
	Block& operator=(Block&& _Other) noexcept = delete;
	
	void BlockMake()
	{
		//block will make
	}
	
	
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	
	void DropItem();
	UImageRenderer* BlockRender = nullptr;
	FVector BlockScale = { 16,8 };
	std::list<Block*> BlockMaker;
	UCollision* BlockCollision = nullptr;

};

