#pragma once
#include<EngineCore/Actor.h>
#include<EngineCore/ImageRenderer.h>
#include<EngineCore/EngineResourcesManager.h>
#include<string>
#include"EndingBackGround.h"

using namespace std;
// ���� :
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
	void PlayerLifeMinusUI(const int _Life);
	void PlayerLifePlusUI(const int _Life);


	static UIManager* GetUIManager();

	void EndScoreText();
	
	UImageRenderer* Ready_Text = nullptr;
	int TotalScore = 0;
	

protected:
	void BeginPlay() override;
	void Tick(float _Deltatime) override;
private:
	
	UImageRenderer* SCORE_Text = nullptr;
	UImageRenderer* TimeUI_Text = nullptr;
	UImageRenderer* Time_Text = nullptr;
	UImageRenderer* Time_Text1 = nullptr;
	UImageRenderer* Time_Text2 = nullptr;
	UImageRenderer* Score_Text= nullptr;
	UImageRenderer* Score_Texts[4] = { nullptr ,nullptr ,nullptr ,nullptr };
	UImageRenderer* UserLife[4] = { nullptr,nullptr,nullptr,nullptr };
	UImageRenderer* GameOver_Text = nullptr;
	UImageRenderer* ThankYou_Text = nullptr;
	FVector Middle = { 552 / 2 ,20 };
	float Time = 0.0f;
	int LifeCounter = 2;
	int TotalTime = 0;
	string STime = "";
	string STime1 = "";
	string STime2 = "";
	
	int STimeCounter = 0;
	int STimeCounter2 = 0;
	string SScore = "";
};

