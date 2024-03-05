#include "UIManager.h"
#include <string>

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
	
	
	SetActorLocation({300,10});
	
	{
	HIGH_Text = CreateImageRenderer(10);
	HIGH_Text->SetImage("HIGH.png",0);
	HIGH_Text->SetTransform({ {-40,0}, { 32*2, 8*2} });
	}
	{
	SCORE_Text = CreateImageRenderer(10);
	SCORE_Text->SetImage("Score.png", 0);
	SCORE_Text->SetTransform({ {40,0},{40*2,8*2} });
	}

	{
		Time_Text = CreateImageRenderer(10);
		Time_Text1 = CreateImageRenderer(10);
	}

}


void UIManager::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	IntToString(_DeltaTime);
	TimeUI();
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

