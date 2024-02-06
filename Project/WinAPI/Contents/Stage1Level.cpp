#include "Stage1Level.h"
#include "User.h"
#include <EngineCore/EngineResourcesManager.h>
#include<EngineBase/EngineFile.h>
#include<EngineBase/EngineDirectory.h>

Stage1Level::Stage1Level()
{
}

Stage1Level::~Stage1Level()
{
}
void Stage1Level::BeginPlay()
{
	ULevel::BeginPlay();
	
	User* user = SpawnActor<User>(); //플레이어 생성

}

void Stage1Level::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}
