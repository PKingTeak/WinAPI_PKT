#pragma once
#include <EngineCore/Level.h>
// Ό³Έν :
class Stage2Level : public ULevel
{
public:
	// constrcuter destructer
	Stage2Level();
	~Stage2Level();

	// delete Function
	Stage2Level(const Stage2Level& _Other) = delete;
	Stage2Level(Stage2Level&& _Other) noexcept = delete;
	Stage2Level& operator=(const Stage2Level& _Other) = delete;
	Stage2Level& operator=(Stage2Level&& _Other) noexcept = delete;
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

