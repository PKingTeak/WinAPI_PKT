#include "EndingBackGround.h"
#include"UIManager.h"
#include<EngineCore/ImageRenderer.h>
#include<EngineCore/EngineResourcesManager.h>
#include"ArkanoidCore.h"
#include<EngineCore/ImageRenderer.h>
#include"Stage1Level.h"
EndingBackGround::EndingBackGround()
{
}
EndingBackGround::~EndingBackGround()
{

}
void EndingBackGround::BeginPlay()
{
	AActor::BeginPlay();
	


	EndingImage = CreateImageRenderer(0);
	EndingImage->SetImage("Ending.png");
	EndingImage->SetTransform({ {EndingScreenSize.X/2,EndingScreenSize.Y/2-150},{ 80 *2,126 *2} });
	EndingTitle = CreateImageRenderer();
	EndingTitle->SetImage("Endingtitle.png");
	EndingTitle->SetTransform({{ EndingScreenSize.X/2, EndingScreenSize.Y/2+50 }, {228,64} });
	RankImage = CreateImageRenderer();
	RankImage->SetImage("SRank.png");
	RankImage->SetTransform({ { EndingScreenSize.X / 2 , EndingScreenSize.Y / 2 + 160 }, {208,50} });
	

}

void EndingBackGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);


}