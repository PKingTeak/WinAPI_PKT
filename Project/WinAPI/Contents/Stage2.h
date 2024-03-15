#pragma once
#include"ArkanoidCore.h"
#include<EngineCore/Actor.h>
#include<EnginePlatform/WindowImage.h>
class Stage2 : public AActor
{

public:
	Stage2();
	~Stage2();

	// delete Function
	Stage2(const Stage2& _Other) = delete;
	Stage2(Stage2&& _Other) noexcept = delete;
	Stage2& operator=(const Stage2& _Other) = delete;
	Stage2& operator=(Stage2&& _Other) noexcept = delete;

	void SetMapImage(std::string_view _MapImageName);
	void GameOverMapImage();

	FVector EndingScreenSize = {};

protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* MapRenderer2 = nullptr;
	UImageRenderer* GameOverRenderer2 = nullptr;




};

