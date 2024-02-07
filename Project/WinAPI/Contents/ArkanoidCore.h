#pragma once
#include <EngineCore\EngineCore.h>

// Ό³Έν :
class ArkanoidCore : public UEngineCore
{
public:
	// constrcuter destructer
	ArkanoidCore();
	~ArkanoidCore();

	// delete Function
	ArkanoidCore(const ArkanoidCore& _Other) = delete;
	ArkanoidCore(ArkanoidCore&& _Other) noexcept = delete;
	ArkanoidCore& operator=(const ArkanoidCore& _Other) = delete;
	ArkanoidCore& operator=(ArkanoidCore&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DelatTime) override;
	void End() override;
	FVector   ScreenSize = { 640,480 } ;

private:

};

