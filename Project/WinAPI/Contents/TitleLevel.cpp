#include "TitleLevel.h"
#include "BackGround.h"
#include <EnginePlatform/EngineInput.h>
#include "ArkanoidCore.h"
TitleLevel::TitleLevel()
{
}
TitleLevel::~TitleLevel()
{

}
void TitleLevel::BeginPlay()
{
	ULevel::BeginPlay();

	BackGround* Background = SpawnActor<BackGround>();


}

void TitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
	if (UEngineInput::IsDown(' '))
	{
		GEngine->ChangeLevel("Stage1Level");
	}

}