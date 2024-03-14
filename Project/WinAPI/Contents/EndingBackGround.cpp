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
	EndingImage->SetImage("EndingBoss.png");
	EndingImage->SetTransform({ {EndingScreenSize.X/2,EndingScreenSize.Y/2-150},{64*2,118*2} });
	EndingTitle = CreateImageRenderer();
	EndingTitle->SetImage("Endingtitle.png");
	EndingTitle->SetTransform({{ EndingScreenSize.X/2, EndingScreenSize.Y/2+50 }, {228,64} });

	PlayTitle = CreateImageRenderer();
	PlayTitle->SetImage("Playing.png");
	PlayTitle->SetTransform({ {EndingScreenSize.X / 2 + 120 / 2,EndingScreenSize.Y / 2 + 100},{56 * 2,8 * 2} });
	
	ThankTitle = CreateImageRenderer();
	ThankTitle->SetImage("ThankYou.png");
	ThankTitle->SetTransform({ {EndingScreenSize.X / 2 -140 / 2,EndingScreenSize.Y / 2 + 100},{56 * 2,8 * 2} });
	
	
	RankImage = CreateImageRenderer();
	RankImage->SetImage("SRank.png");
	RankImage->SetTransform({ { EndingScreenSize.X / 2 , EndingScreenSize.Y / 2 + 160 }, {208,50} });
	

}

void EndingBackGround::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);


}