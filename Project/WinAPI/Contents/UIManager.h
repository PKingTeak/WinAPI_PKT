#pragma once
#include<EngineCore/Actor.h>
#include<EngineCore/ImageRenderer.h>
#include<EngineCore/EngineResourcesManager.h>
// Ό³Έν :
class UIManager : public AActor
{
public:
	// constrcuter destructer
	UIManager();
	~UIManager();

	// delete Function
	UIManager(const UIManager& _Other) = delete;
	UIManager(UIManager&& _Other) noexcept = delete;
	UIManager& operator=(const UIManager& _Other) = delete;
	UIManager& operator=(UIManager&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;
private:
	UImageRenderer* HIGH_Text = nullptr;
	UImageRenderer* SCORE_Text = nullptr;
	FVector Middle = { 552 / 2 ,20 };


};

