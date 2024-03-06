#pragma once
#include<EngineCore/Actor.h>
#include<EngineCore/ImageRenderer.h>
#include<EngineCore/EngineResourcesManager.h>
#include<string>

using namespace std;
// Ό³Έν :
class UIManager : public AActor
{
private:
	static UIManager* MainUIMananger;
	
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
	void ScoreUI();
	void ScorePlus(int _GameScore);

	static UIManager* GetUIManager();
protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;
private:
	UImageRenderer* HIGH_Text = nullptr;
	UImageRenderer* SCORE_Text = nullptr;
	UImageRenderer* Time_Text = nullptr;
	UImageRenderer* Time_Text1 = nullptr;
	UImageRenderer* Score_Text= nullptr;
	UImageRenderer* Score_Texts[4] = { nullptr ,nullptr ,nullptr ,nullptr };
	
	

	FVector Middle = { 552 / 2 ,20 };
	float Time = 0.0f;
	int TotalTime = 0;
	string STime = "";
	string STime1 = "";
	int STimeCounter = 0;
	
	string SScore = "";
	int TotalScore =0;
};

