#include "Stage1Level.h"
#include "User.h"
#include "Stage1BackGround.h"
#include "Ball.h"
#include "Block.h"
#include "Item.h"
#include <EngineCore/EngineResourcesManager.h>
#include<EngineBase/EngineFile.h>
#include<EngineBase/EngineDirectory.h>
#include<EnginePlatform/EngineInput.h>
#include"UIManager.h"

int Block::BlockCounter = 0;

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
	
	UIManager* StageUI = SpawnActor<UIManager>();
	
	{
		//Test
		Block* TestBlock;
		std::vector<Block*> Blocks;

		for (int i = 0; i < 12; i++)
		{
			TestBlock = SpawnActor<Block>();
			TestBlock->SetBlockType(BlockType::Hard, TestBlock);
			int Blocklife = TestBlock->GetLife();
			BlockType thisBlockType = TestBlock->GetBlockType(TestBlock);
			TestBlock->SetActorLocation(FVector{ 45 + i * 42, 100 });
			Blocks.push_back(TestBlock);
			TestBlock->SetBlockCounter(1);


		}

		//이걸 반복해서 사용중이다 이걸 관리해주는 클래스는 나중에 만들자
		for (int i = 0; i < 12; i++)
		{

			TestBlock = SpawnActor<Block>();
			TestBlock->SetActorLocation(FVector{ 45 + i * 42,120 });
			TestBlock->SetBlockColor(4);
			Blocks.push_back(TestBlock);
			TestBlock->SetScore(90);
			TestBlock->SetBlockCounter(1);
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
			TestBlock->SetScore(120);
			Blocks.push_back(TestBlock);
			TestBlock->SetBlockCounter(1);
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
			TestBlock->SetScore(100);
			Blocks.push_back(TestBlock);
			TestBlock->SetBlockCounter(1);
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
			TestBlock->SetScore(110);
			Blocks.push_back(TestBlock);
			TestBlock->SetBlockCounter(1);
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
			TestBlock->SetScore(80);
			Blocks.push_back(TestBlock);
			TestBlock->SetBlockCounter(1);
		
		}
	}
}


void Stage1Level::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
	int Blocks = Block::BlockCounter;
	if (Blocks <= 0)
	{
		GEngine->ChangeLevel("EndingLevel");
	}
}
