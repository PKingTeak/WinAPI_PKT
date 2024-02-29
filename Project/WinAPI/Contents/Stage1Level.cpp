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
	//Block* NewBlock = SpawnActor<Block>();
	Stage1Map* Stage1 = SpawnActor<Stage1Map>();
	Item* NewItem = SpawnActor<Item>();
	NewItem->SetActorLocation({ 1200,1200 }); //아이템 위치 이동시킨후 일단 다른곳에 생성ㄴ
	NewItem->SetActive(false);
	Stage1->SetMapImage("Stage1_BackGround.png");
	//Stage1->SetColMapImage("Stage1_ColMap.png");


	{
		//Test
		Block* TestBlock;
		std::vector<Block*> a;
		for (int i = 0; i < 10; ++i) {
			TestBlock = SpawnActor<Block>();
			TestBlock->SetActorLocation(FVector{ 50+i*44,100 });
			a.push_back(TestBlock);
		}
	
	
	//Block* TestBlock[] = SpawnActor<Block>();
	//TestBlock8->SetActorLocation({ 364,300 });
	//Block* TestBlock1 = SpawnActor<Block>();
	//TestBlock1->SetActorLocation({ 100,300 });
	//Block* TestBlock2 = SpawnActor<Block>();
	//TestBlock2->SetActorLocation({ 200,300 });
	//Block* TestBlock3 = SpawnActor<Block>();
	//TestBlock3->SetActorLocation({ 500,300 });
	//
	//Block* TestBlock4 = SpawnActor<Block>();
	//TestBlock4->SetActorLocation({ 300,200 });
	//Block* TestBlock5 = SpawnActor<Block>();
	//TestBlock5->SetActorLocation({ 100,200 });
	//Block* TestBlock6 = SpawnActor<Block>();
	//TestBlock6->SetActorLocation({ 200,200 });
	//Block* TestBlock7 = SpawnActor<Block>();
	//TestBlock7->SetActorLocation({ 500,200 });
	
	}
}


void Stage1Level::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

}
