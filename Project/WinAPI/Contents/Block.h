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
	FVector GetBlockPos()
	{
		return this->GetActorLocation();
	}
	FVector GetBlockScale()
	{
		return BlockScale;
	}
	float Blockwidth()
	{
		return BlockCollision->GetTransform().Left() - BlockCollision->GetTransform().Right();
		
	}
	float BlockHeight()
	{
		return BlockCollision->GetTransform().Top() - BlockCollision->GetTransform().Bottom();
	}
	UCollision* GetBlockCollision()
	{
		return BlockCollision;
	}
	
	
	
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	void BlockRatio();
	void DropItem();
	UImageRenderer* BlockRender = nullptr;
	FVector BlockScale = { 16,8 };
	std::list<Block*> BlockMaker;
	UCollision* BlockCollision = nullptr;
	
};

