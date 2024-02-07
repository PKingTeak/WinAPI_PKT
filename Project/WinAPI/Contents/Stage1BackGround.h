#pragma once
#include<EngineCore/Actor.h>
#include"ArkanoidCore.h"
class Stage1Map : public AActor
{

public:
	Stage1Map();
	~Stage1Map();

	// delete Function
	Stage1Map(const Stage1Map& _Other) = delete;
	Stage1Map(Stage1Map&& _Other) noexcept = delete;
	Stage1Map& operator=(const Stage1Map& _Other) = delete;
	Stage1Map& operator=(Stage1Map&& _Other) noexcept = delete;

	void SetMapImage(std::string_view _MapImageName);
	void SetColMapImage(std::string_view _MapImageName);
	void SwitchDebug();
protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	static UWindowImage* ColMapImage;

private:
	UImageRenderer* MapRenderer = nullptr;
	UImageRenderer* ColMapRenderer = nullptr;
	
};

