#include "EndingLevel.h"
#include"EndingBackGround.h"
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
}