#pragma once
#include <EngineCore/Actor.h>
class Block : public AActor
{
private:
	static  Block* MainBlock;
public:
	Block();
	~Block();

	// delete Function
	Block(const Block& _Other) = delete;
	Block(Block&& _Other) noexcept = delete;
	Block& operator=(const Block& _Other) = delete;
	Block& operator=(Block&& _Other) noexcept = delete;
	static Block* GetMainBlock();
	
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

};

