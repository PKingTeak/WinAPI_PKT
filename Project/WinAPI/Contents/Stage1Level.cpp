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
	


	{
		//Test
		Block* TestBlock;
		std::vector<Block*> Blocks;

		for (int i = 0; i < 12; i++)
		{
			TestBlock = SpawnActor<Block>();
			TestBlock->SetBlockType(BlockType::Hard, TestBlock);
			int Blocklife = TestBlock->GetLife();
			//TestBlock->SetBlockColor(0);
			BlockType thisBlockType = TestBlock->GetBlockType(TestBlock);
			TestBlock->SetActorLocation(FVector{ 45 + i * 42, 100 });
			Blocks.push_back(TestBlock);


		}

		//이걸 반복해서 사용중이다 이걸 관리해주는 클래스는 나중에 만들자
		for (int i = 0; i < 12; i++)
		{

			TestBlock = SpawnActor<Block>();
			TestBlock->SetActorLocation(FVector{ 45 + i * 42,120 });
			TestBlock->SetBlockColor(4);
			Blocks.push_back(TestBlock);
		}

	}

	{
		Block* TestBlock;
		std::vector<Block*> Blocks;

		for (int i = 0; i < 12; i++)
		{
			TestBlock = SpawnActor<Block>();
			TestBlock->SetActorLocation(FVector{ 45 + i * 42,120 +24 });
			TestBlock->SetBlockColor(7);
			Blocks.push_back(TestBlock);
		}
	
	}
	{
		Block* TestBlock;
		std::vector<Block*> Blocks;

		for (int i = 0; i < 12; i++)
		{
			TestBlock = SpawnActor<Block>();
			TestBlock->SetActorLocation(FVector{ 45 + i * 42,120 +24*2 });
			TestBlock->SetBlockColor(5);
			Blocks.push_back(TestBlock);
		}
	
	}
	{
		Block* TestBlock;
		std::vector<Block*> Blocks;

		for (int i = 0; i < 12; i++)
		{
			TestBlock = SpawnActor<Block>();
			TestBlock->SetActorLocation(FVector{ 45 + i * 42,120 + 24 * 3 });
			TestBlock->SetBlockColor(6);
			Blocks.push_back(TestBlock);
		}
	}

	{
		Block* TestBlock;
		std::vector<Block*> Blocks;

		for (int i = 0; i < 12; i++)
		{
			TestBlock = SpawnActor<Block>();
			TestBlock->SetActorLocation(FVector{ 45 + i * 42,120 + 24 * 4 });
			TestBlock->SetBlockColor(3);
			Blocks.push_back(TestBlock);
		}
	}
}



void Stage1Level::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

}
