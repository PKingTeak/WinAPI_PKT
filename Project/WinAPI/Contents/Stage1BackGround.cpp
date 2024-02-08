#include "Stage1BackGround.h"
#include"CollisonManger.h"

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
	MapRenderer->SetTransform({ {ImageScale.Half2D().X , ImageScale.Half2D().Y+30}, ImageScale});
}

//void  Stage1Map::SetColMapImage(std::string_view _MapImageName)
//{
//	ColMapRenderer->SetImage(_MapImageName);
//	UWindowImage* Image = ColMapRenderer->GetImage();
//	CollisonManger::ColMapImage = Image;
//	FVector ImageScale = ArkanoidCore::GetScreenSize();
//	ColMapRenderer->SetTransform({ ImageScale.Half2D(), ImageScale });
//
//
//}
//


void Stage1Map::BeginPlay()
{
	AActor::BeginPlay();
	MapRenderer = CreateImageRenderer(-10);
//	ColMapRenderer = CreateImageRenderer(-11); //플레이어 보다는 먼저 그려져야 안덮어 
//	ColMapRenderer->SetActive(false);

}


void Stage1Map::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	


}
