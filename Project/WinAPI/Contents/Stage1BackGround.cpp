#include "Stage1BackGround.h"
#include<EnginePlatform/EngineInput.h>
Stage1Map::Stage1Map()
{

}

Stage1Map::~Stage1Map()
{

}
//더 줄일수 있다. 

void Stage1Map::SetMapImage(std::string_view _MapImageName)
{
	MapRenderer->SetImage(_MapImageName);
	UWindowImage* Image = MapRenderer->GetImage();
	FVector ImageScale = ArkanoidCore::GetScreenSize();
	MapRenderer->SetTransform({ {ImageScale.Half2D().X , ImageScale.Half2D().Y+50}, ImageScale});
}




void Stage1Map::BeginPlay()
{
	AActor::BeginPlay();
	MapRenderer = CreateImageRenderer(-10);


}


void Stage1Map::GameOverMapImage()
{
	SetMapImage("Stage1_GameOver.png");
}


void Stage1Map::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	if (UEngineInput::IsDown('O'))
	{
		GameOverMapImage();

	}



}
