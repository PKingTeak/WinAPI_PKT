#include "TitleLevel.h"
#include "BackGround.h"
#include <EnginePlatform/EngineInput.h>
#include "ArkanoidCore.h"
#include<EngineBase/EngineDirectory.h>
#include<EnginePlatform/EngineSound.h>
#include<list>
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
	//UEngineSound::SoundPlay("Sound1.wav");



}

void TitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
	if (UEngineInput::IsDown(' '))
	{
		GEngine->ChangeLevel("Stage1Level");
	}

}