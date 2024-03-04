#pragma once
#include <EngineCore/Actor.h>
#include<vector>

enum class BlockType
{
	Normal = 0 ,
	Hard = 1,
	Gold = 2

};

class Block : public AActor
{

public:
	Block();
	Block(int _Color);
	~Block();

	// delete Function
	Block(const Block& _Other) = delete;
	Block(Block&& _Other) noexcept = delete;
	Block& operator=(const Block& _Other) = delete;
	Block& operator=(Block&& _Other) noexcept = delete;
	

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

	//WHITE = 0,ORANG = 1,MINT = 2,GREEN = 3,RED = 4,BLUE = 5,PINK = 6,YELLOW = 7
	void SetBlockColor(int _Color)
	{
		
		BlockRender->SetImage("NewBlock.png", _Color);
	}

	void StackBlock();
	
	int GetLife();
	void BlockLife(int _Count);
	void SetLife(int _Count);
	int LifeDecrease();
	template<typename EnumType>
	int SetBlockType(EnumType _BlockType , Block* _NewBlock)
	{
		return SetBlockType(static_cast<int>(_BlockType), _NewBlock);
	}
	
	int SetBlockType(int _BlockType, Block* _NewBlock);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	UImageRenderer* BlockRender = nullptr;
	FVector BlockScale = { 44, 24 };
	UCollision* BlockCollision = nullptr;
	int life = 0;
	BlockType Type = BlockType::Normal;
};

