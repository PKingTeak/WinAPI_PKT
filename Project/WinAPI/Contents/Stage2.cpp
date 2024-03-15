#include "Stage2.h"
#include<EnginePlatform/EngineInput.h>
#include"User.h"
#include<EnginePlatform/EngineSound.h>
Stage2::Stage2()
{

}

Stage2::~Stage2()
{

}
//더 줄일수 있다. 

void Stage2::SetMapImage(std::string_view _MapImageName)
{
	MapRenderer2->SetImage(_MapImageName);
	UWindowImage* Image = MapRenderer2->GetImage();
	FVector ImageScale = ArkanoidCore::GetScreenSize();
	MapRenderer2->SetTransform({ {ImageScale.Half2D().X , ImageScale.Half2D().Y + 50}, ImageScale });
}




void Stage2::BeginPlay()
{
	AActor::BeginPlay();
	MapRenderer2 = CreateImageRenderer(-10);


}


void Stage2::GameOverMapImage()
{
	SetMapImage("Stage1_GameOver.png");
	UEngineSound::SoundPlay("GamOver.wav");


}


void Stage2::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	if (User::GetMainUser()->CheckGameOver() == true)
	{
		GameOverMapImage();
	}


}
