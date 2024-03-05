#pragma once
#include<EngineCore/Actor.h>
#include<EngineCore/ImageRenderer.h>
#include<EngineCore/EngineResourcesManager.h>
#include<string>

using namespace std;
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

	void IntToString(float _DetaTime);
	void TimeUI();
protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;
private:
	UImageRenderer* HIGH_Text = nullptr;
	UImageRenderer* SCORE_Text = nullptr;
	UImageRenderer* Time_Text = nullptr;
	FVector Middle = { 552 / 2 ,20 };
	int Time = 0;
	string STime = "";

};

