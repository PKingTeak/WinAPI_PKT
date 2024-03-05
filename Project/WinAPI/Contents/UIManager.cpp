#include "UIManager.h"

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

}

void UIManager::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
