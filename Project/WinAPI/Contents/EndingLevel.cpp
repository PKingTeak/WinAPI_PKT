#include "EndingLevel.h"
#include"EndingBackGround.h"
#include<EnginePlatform/EngineInput.h>
EndingLevel::EndingLevel()
{
}
EndingLevel::~EndingLevel()
{}

void EndingLevel::BeginPlay()
{
	ULevel::BeginPlay();
	EndingBackGround* End = SpawnActor<EndingBackGround>();
}

void EndingLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
	if (UEngineInput::IsDown(' '))
	{
		GEngine->ChangeLevel("TitleLevel");
	}
}