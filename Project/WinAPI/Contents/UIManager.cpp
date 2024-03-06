#include "UIManager.h"
#include <string>
#include<EnginePlatform/EngineInput.h>

using namespace std;
UIManager::UIManager()
{
}

UIManager::~UIManager()
{
}


void UIManager::BeginPlay()
{
	AActor::BeginPlay();


	SetActorLocation({ 300,10 });

	{
		HIGH_Text = CreateImageRenderer(10);
		HIGH_Text->SetImage("HIGH.png", 0);
		HIGH_Text->SetTransform({ {-40,0}, { 32 * 2, 8 * 2} });
	}
	{
		SCORE_Text = CreateImageRenderer(10);
		SCORE_Text->SetImage("Score.png", 0);
		SCORE_Text->SetTransform({ {40,0},{40 * 2,8 * 2} });
	}

	{
		Time_Text = CreateImageRenderer(10);
		Time_Text1 = CreateImageRenderer(10);

	}

	{
		ScorePlus(1501);
		//Score_Text = CreateImageRenderer(10);
		for (int i = 0; i <= 5; i++)
		{
			Score_Texts[i] = CreateImageRenderer(10);
			Score_Texts[i]->SetImage("0.png");
		}
		int a = 0;
	}
}


void UIManager::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	IntToString(_DeltaTime);
	TimeUI();
	ScoreUI();



}

void UIManager::IntToString(float _Deltatime)
{

	float PlusTime = _Deltatime;
	Time += PlusTime;
	if (Time >= 1)
	{
		TotalTime += 1;
		Time -= 1;
	}
	if (TotalTime > 9)
	{
		STimeCounter++;
		TotalTime = 0;
	}
	if (STimeCounter > 9)
	{
		Time = 0;
		STimeCounter = 0;
	}

	STime = std::to_string(TotalTime);
	STime1 = std::to_string(STimeCounter);
}
void UIManager::TimeUI()
{

	Time_Text->SetImage(STime + ".png");
	Time_Text->SetTransform({ {0,20},{8 * 2,8 * 2} });


	Time_Text1->SetImage(STime1 + ".png");
	Time_Text1->SetTransform({ {-16,20},{8 * 2,8 * 2} });


}

void UIManager::ScorePlus(int _GameScore)
{

	TotalScore += _GameScore;

}


void UIManager::ScoreUI()
{

	std::string SScore = std::to_string(TotalScore);
	std::string str; // 문자 하나씩 뽑아주기 위한 지역변수
	for (int i = 0; i < SScore.length(); ++i)
	{


		str = SScore.substr(i, 1); //1500
		str.append(".png");

		//Score_Text->SetImage(str);
		//Score_Text->SetTransform({ {-100 + i * 8,20}, {8 * 2,8 * 2} });

		Score_Texts[i]->SetImage(str);
		Score_Texts[i]->SetTransform({ {-100 + i * 16,20}, {8 * 2,8 * 2} });
	}

	
	int a = 0;
}

