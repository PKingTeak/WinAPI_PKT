#pragma once
#include <EngineCore/Level.h>
#include<vector>
#include"Block.h"
// Ό³Έν :
class Stage1Level : public ULevel
{
public:
	// constrcuter destructer
	Stage1Level();
	~Stage1Level();

	// delete Function
	Stage1Level(const Stage1Level& _Other) = delete;
	Stage1Level(Stage1Level&& _Other) noexcept = delete;
	Stage1Level& operator=(const Stage1Level& _Other) = delete;
	Stage1Level& operator=(Stage1Level&& _Other) noexcept = delete;
	void StageChange();
	static bool isCheat;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	bool change = false;
	bool BStageChange = false;
	std::vector<Block*> DBlock;
	
};

