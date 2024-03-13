#pragma once
#include<EngineCore/Actor.h>
#include<EngineCore/ImageRenderer.h>
#include<EnginePlatform/WindowImage.h>
#include"ArkanoidCore.h"
#include"UIManager.h"
class EndingBackGround : public AActor
{

public:
	EndingBackGround();
	~EndingBackGround();

	// delete Function
	EndingBackGround(const EndingBackGround& _Other) = delete;
	EndingBackGround(EndingBackGround&& _Other) noexcept = delete;
	EndingBackGround& operator=(const EndingBackGround& _Other) = delete;
	EndingBackGround& operator=(EndingBackGround&& _Other) noexcept = delete;
	
	FVector GetScreenSize();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
private:
	FVector EndingScreenSize = ArkanoidCore::GetScreenSize();
	UImageRenderer* EndingImage = nullptr;
	UImageRenderer* EndingTitle = nullptr;
	UImageRenderer* RankImage = nullptr;
	
		
};

