#pragma once
#include<EngineCore/Level.h>

class DebugLevel : public ULevel
{

public:
	DebugLevel();
	~DebugLevel();

	// delete Function
	DebugLevel(const DebugLevel& _Other) = delete;
	DebugLevel(DebugLevel&& _Other) noexcept = delete;
	DebugLevel& operator=(const DebugLevel& _Other) = delete;
	DebugLevel& operator=(DebugLevel&& _Other) noexcept = delete;

	

protected:

	//void BeginPlay() override;
	//void Tick(float _DeltaTime) override;

private:
	
};

