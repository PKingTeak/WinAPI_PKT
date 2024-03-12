#pragma once
#include<EngineCore/Level.h>
#include<EngineCore/ImageRenderer.h>
class EndingLevel :public ULevel
{

public:
	EndingLevel();
	~EndingLevel();

	// delete Function
	EndingLevel(const EndingLevel& _Other) = delete;
	EndingLevel(EndingLevel&& _Other) noexcept = delete;
	EndingLevel& operator=(const EndingLevel& _Other) = delete;
	EndingLevel& operator=(EndingLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	
private:
	UImageRenderer* EndingImage = nullptr;
		
};

