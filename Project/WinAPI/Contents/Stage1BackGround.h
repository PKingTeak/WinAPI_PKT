#pragma once
#include"ArkanoidCore.h"
#include<EngineCore/Actor.h>
#include<EnginePlatform/WindowImage.h>
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
	//void SetColMapImage(std::string_view _MapImageName);
	
	
	
protected:
	
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* MapRenderer = nullptr;

	
	
};

