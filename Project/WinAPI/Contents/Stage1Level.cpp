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
#include"Stage2Level.h"
#include<vector>

int Block::BlockCounter = 0;
bool Stage1Level::isCheat = false;

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
	NewBall = SpawnActor<Ball>(); // 공생성
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
			DBlock.push_back(TestBlock);

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
			DBlock.push_back(TestBlock);
		}

	}

	{
		Block* TestBlock;
		std::vector<Block*> Blocks;

		for (int i = 0; i < 12; i++)
		{
			TestBlock = SpawnActor<Block>();
			TestBlock->SetActorLocation(FVector{ 45 + i * 42,120 + 24 });
			TestBlock->SetBlockColor(7);
			TestBlock->SetScore(120);
			Blocks.push_back(TestBlock);
			TestBlock->SetBlockCounter(1);
			DBlock.push_back(TestBlock);
		}

	}
	{
		Block* TestBlock;
		std::vector<Block*> Blocks;

		for (int i = 0; i < 12; i++)
		{
			TestBlock = SpawnActor<Block>();
			TestBlock->SetActorLocation(FVector{ 45 + i * 42,120 + 24 * 2 });
			TestBlock->SetBlockColor(5);
			TestBlock->SetScore(100);
			Blocks.push_back(TestBlock);
			TestBlock->SetBlockCounter(1);
			DBlock.push_back(TestBlock);
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
			DBlock.push_back(TestBlock);
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
			DBlock.push_back(TestBlock);
		}
	}


}



void Stage1Level::Tick(float _DeltaTime)
{

	if (change == false)
	{
		isCheat = false; // 틱이 끝나고 소멸자를 호출하는 구조이기때문에 
		// 다음 틱이 실행될때 destory 를 한건 아이템이 안나옴
		// 하지만 다음부터는 나와야 하기 땜누에 블록을 만들고 난후 모든 블록의 설정은 ischeat을 꺼준다.
	}

	for (size_t i = 0; i < DBlock.size(); i++)
	{
		if (DBlock[i] == nullptr)
		{
			continue;
			//nullptr일경우 뛰어 넘고 진행
		}


		if (DBlock[i]->IsDestroy())
		{
			DBlock[i] = nullptr;
			continue;
			//포인터로 그곳을 지웠다고 해서 포인터가 nullptr이 되는것이 아니니까
			//그 포인터도 nullptr 로 해줘야된다 <- 이거 까먹지말것
		}

	}


	ULevel::Tick(_DeltaTime);
	int Blockcount = Block::BlockCounter;
	if (Blockcount <= 0 || UEngineInput::IsDown('Q'))
	{

		for (size_t i = 0; i < DBlock.size(); i++)
		{
			if (DBlock[i] == nullptr)
			{
				continue;
				//nullptr일경우 뛰어 넘고 진행
			}
			
			DBlock[i]->Destroy(false);
			isCheat = true;
			NewBall->Reset();
		
		}

		DBlock.clear();




		StageChange();
		if (BStageChange == true)
		{

			GEngine->ChangeLevel("EndingLevel");

		}



	}



}

void Stage1Level::StageChange()
{
	change = true;
	{

		Block* TestBlock;
		std::vector<Block*> Blocks;
		for (int i = 0; i < 11; i++)
		{
			TestBlock = SpawnActor<Block>();
			TestBlock->SetBlockType(BlockType::Hard, TestBlock);
			TestBlock->SetActorLocation(FVector{ 45 + i * 42,400 });
			Blocks.push_back(TestBlock);


		}

	}

	{

		Block* TestBlock;
		std::vector<Block*> Blocks;

		FVector BlockScale = { 42, 24 };
		FVector StartPos = { 45 , 400 - 42 };
		int Count = 11;
		int ColorCount = 0;
		for (int i = 0; i < 11; i++)
		{

			for (size_t i = 0; i < Count; i++)
			{
				TestBlock = SpawnActor<Block>();
				TestBlock->SetBlockType(BlockType::Normal, TestBlock);
				TestBlock->SetActorLocation(StartPos);
				Blocks.push_back(TestBlock);
				TestBlock->SetBlockColor(ColorCount);
				TestBlock->SetBlockCounter(1);
				StartPos.Y -= BlockScale.Y;

			}
			Count -= 1;
			ColorCount += 1;
			if (ColorCount > 6)
			{
				ColorCount = 0;
			}
			StartPos.X += BlockScale.X;
			StartPos.Y = 400 - 42; // 다시 처음부터 쌓아 올려야된다.

		}

	}
	//DBlock.clear();
	change = false;
	//BStageChange = true;
}
