#include "UIManager.h"
#include <string>
#include<EnginePlatform/EngineInput.h>
#include"User.h"

UIManager* UIManager::MainUIMananger = nullptr;

using namespace std;
UIManager::UIManager()
{
}

UIManager::~UIManager()
{
}


void UIManager::BeginPlay()
{
	MainUIMananger = this;
	AActor::BeginPlay();

	SetActorLocation({ 300,10 });

	
	{
		SCORE_Text = CreateImageRenderer(10);
		SCORE_Text->SetImage("Score.png", 0);
		SCORE_Text->SetTransform({ {-100,0},{40 * 2,8 * 2} });
	}

	{
		Time_Text = CreateImageRenderer(10);
		Time_Text1 = CreateImageRenderer(10);

		TimeUI_Text = CreateImageRenderer(10);
		TimeUI_Text->SetImage("Time_Text.png");
		TimeUI_Text->SetTransform({ {0,0}, {32 * 2,8 * 2} });
	}

	{
		Ready_Text = CreateImageRenderer(10);
		Ready_Text->SetImage("Ready.png");
		Ready_Text->SetTransform({ {0,450}, {40 * 2,8 * 2} });
	
	}

	{
		//Score_Text = CreateImageRenderer(10);
		for (int i = 0; i <= 3; i++)
		{
			Score_Texts[i] = CreateImageRenderer(10);
			Score_Texts[i]->SetImage("0.png");
		}
	
	}
	{
		for (int i = 0; i < 4; i++)
		{
			UserLife[i] = CreateImageRenderer(20);
			UserLife[i]->SetImage("UI_PlayerLife.png");
			UserLife[i]->SetTransform({ {-260+32 * i,608},{16 * 2,8 * 2} });
			
			if (i > LifeCounter)
			{
				UserLife[i]->SetActive(false);
			}
			
		}
		
			
	}
}


void UIManager::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	IntToString(_DeltaTime);
	TimeUI();
	ScoreUI();
	
	


	if (UEngineInput::IsDown('L'))
	{
		
		ScorePlus(20);
	}

	

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

void UIManager::PlayerLifeMinusUI(const int _Life)
{
	LifeCounter = _Life;
	if (LifeCounter < 0)
	{
		return;
	}

	UserLife[LifeCounter]->SetActive(false);
}

void UIManager::PlayerLifePlusUI(const int _Life)
{
	LifeCounter = _Life;
	if (LifeCounter > 5)
	{
		return;
	}
	UserLife[LifeCounter]->SetActive(true);
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


		str = SScore.substr(i, 1); //1500 문자 하나씩 뽑을려고 만든 지역변수
		str.append(".png"); //뽑은 거에 추가로 .png붙여서 setimage할거다

		Score_Texts[i]->SetImage(str); //하나씩 출력
		Score_Texts[i]->SetTransform({ {-120 + i * 16,20}, {8 * 2,8 * 2} });
	}

	
	
}


UIManager* UIManager::GetUIManager()
{
	return MainUIMananger;
}

