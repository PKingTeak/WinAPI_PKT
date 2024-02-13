#include "Stage1Level.h"
#include "User.h"
#include "Stage1BackGround.h"
#include "Ball.h"
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
	Ball* NewBall = SpawnActor<Ball>(); // 공생성
	Stage1Map* Stage1 = SpawnActor<Stage1Map>();
	Stage1->SetMapImage("Stage1_BackGround.png");
	//Stage1->SetColMapImage("Stage1_ColMap.png");

}


void Stage1Level::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

}
