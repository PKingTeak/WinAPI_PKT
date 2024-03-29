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
	
	AActor::BeginPlay();

	SetActorLocation({ 300,10 });
	MainUIMananger = this;
	
	{
		SCORE_Text = CreateImageRenderer(10);
		SCORE_Text->SetImage("Score.png", 0);
		SCORE_Text->SetTransform({ {-100,0},{40 * 2,8 * 2} });
	}

	{
		Time_Text = CreateImageRenderer(10);
		Time_Text1 = CreateImageRenderer(10);
		Time_Text2 = CreateImageRenderer(10);

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
		GameOver_Text = CreateImageRenderer(10);
		GameOver_Text->SetImage("GameOver.png");
		GameOver_Text->SetTransform({ {-20,250} ,{64 * 4,8 * 4} });
		GameOver_Text->SetActive(false);
	}
	{
		ThankYou_Text = CreateImageRenderer(10);
		ThankYou_Text->SetImage("ThankYou.png");
		ThankYou_Text->SetTransform({ {-20,350} ,{64 * 4,8 * 4} });
		ThankYou_Text->SetActive(false);
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
	if (User::GetMainUser()->CheckGameOver() == true)
	{
		GameOver_Text->SetActive(true);
		ThankYou_Text->SetActive(true);
	}
	


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
		STimeCounter2++;
	}
	if (STimeCounter2 > 9)
	{
		STimeCounter2 = 0;
	}
	
	STime = std::to_string(TotalTime);
	STime1 = std::to_string(STimeCounter);
	STime2 = std::to_string(STimeCounter2);
}
void UIManager::TimeUI()
{

	Time_Text->SetImage(STime + ".png");
	Time_Text->SetTransform({ {20,20},{8 * 2,8 * 2} });


	Time_Text1->SetImage(STime1 + ".png");
	Time_Text1->SetTransform({ {4,20},{8 * 2,8 * 2} });


	Time_Text2->SetImage(STime2 + ".png");
	Time_Text2->SetTransform({ {-12,20},{8 * 2,8 * 2} });

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
	if (LifeCounter >= 4)
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

