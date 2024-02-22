#include "Stage1Level.h"
#include "User.h"
#include "Stage1BackGround.h"
#include "Ball.h"
#include "Block.h"
#include "Item.h"
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
	Block* NewBlock = SpawnActor<Block>();
	Stage1Map* Stage1 = SpawnActor<Stage1Map>();
	Item* NewItem = SpawnActor<Item>();
	NewItem->SetActorLocation({ 1200,1200 });
	NewItem->SetActive(false);
	Stage1->SetMapImage("Stage1_BackGround.png");
	//Stage1->SetColMapImage("Stage1_ColMap.png");


	{
		//Test
	Block* TestBlock = SpawnActor<Block>();
	TestBlock->SetActorLocation({ 300+30,300 });

	Block* TestBlock1 = SpawnActor<Block>();
	TestBlock1->SetActorLocation({ 300+60,300 });
	Block* TestBlock2 = SpawnActor<Block>();
	TestBlock2->SetActorLocation({ 300+90,300 });
	Block* TestBlock3 = SpawnActor<Block>();
	TestBlock3->SetActorLocation({ 300+120,300 });
	
	}
}


void Stage1Level::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

}
