#pragma once
#include <EngineCore/Actor.h>
#include<list>
enum BlockSide
{
	

};

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
	float BlockRight()
	{
		
		return  BlockCollision->GetTransform().Right();
		
	}
	float BlockLeft()
	{
		return BlockCollision->GetTransform().Left();
	}
	float BlockBottom()
	{
		return  BlockCollision->GetTransform().Bottom();
	}

	float BlockUP()
	{
		return BlockCollision->GetTransform().Top();
	}
	UCollision* GetBlockCollision()
	{
		return BlockCollision;
	}
	//FVector BlockSideCheck(FVector _CurBallPos);
	
	
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	
	UImageRenderer* BlockRender = nullptr;
	FVector BlockScale = { 44, 24 };

	std::list<Block*> BlockMaker;
	UCollision* BlockCollision = nullptr;
	

};

