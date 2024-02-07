#include "Stage1BackGround.h"

Stage1Map::Stage1Map()
{

}

Stage1Map::~Stage1Map()
{

}


void Stage1Map::SetMapImage(std::string_view _MapImageName)
{
	MapRenderer->SetImage(_MapImageName);
	UWindowImage* Image = MapRenderer->GetImage();
	FVector ImageScale = ArkanoidCore::GetScreenSize();
	MapRenderer->SetTransform({ ImageScale.Half2D(), ImageScale });
}

void Stage1Map::SetColMapImage(std::string_view _MapImageName)
{
	ColMapRenderer->SetImage(_MapImageName);
	UWindowImage* Image = ColMapRenderer->GetImage();
	ColMapImage = Image;
	FVector ImageScale = ArkanoidCore::GetScreenSize();
	ColMapRenderer->SetTransform({ ImageScale.Half2D(), ImageScale });


}

void Stage1Map::SwitchDebug()
{
	if (true == MapRenderer->IsActive())
	{
		MapRenderer->SetActive(false);
		ColMapRenderer->SetActive(true);

	}
	else
	{
		MapRenderer->SetActive(true);
		ColMapRenderer->SetActive(false);
	}


}

void Stage1Map::BeginPlay()
{
	AActor::BeginPlay();
	MapRenderer = CreateImageRenderer(-10);
	ColMapRenderer = CreateImageRenderer(-11); //플레이어 보다는 먼저 그려져야 안덮어 
	ColMapRenderer->SetActive(false);

}


void Stage1Map::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (EngineInput::IsDown('q'))
	{
		SwitchDebug();
	}


}
