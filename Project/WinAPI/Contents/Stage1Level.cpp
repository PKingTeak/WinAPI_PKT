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

	User* user = SpawnActor<User>(); //�÷��̾� ����
	NewBall = SpawnActor<Ball>(); // ������
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

		//�̰� �ݺ��ؼ� ������̴� �̰� �������ִ� Ŭ������ ���߿� ������
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
		isCheat = false; // ƽ�� ������ �Ҹ��ڸ� ȣ���ϴ� �����̱⶧���� 
		// ���� ƽ�� ����ɶ� destory �� �Ѱ� �������� �ȳ���
		// ������ �������ʹ� ���;� �ϱ� ������ ����� ����� ���� ��� ����� ������ ischeat�� ���ش�.
	}

	for (size_t i = 0; i < DBlock.size(); i++)
	{
		if (DBlock[i] == nullptr)
		{
			continue;
			//nullptr�ϰ�� �پ� �Ѱ� ����
		}


		if (DBlock[i]->IsDestroy())
		{
			DBlock[i] = nullptr;
			continue;
			//�����ͷ� �װ��� �����ٰ� �ؼ� �����Ͱ� nullptr�� �Ǵ°��� �ƴϴϱ�
			//�� �����͵� nullptr �� ����ߵȴ� <- �̰� ���������
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
				//nullptr�ϰ�� �پ� �Ѱ� ����
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
			StartPos.Y = 400 - 42; // �ٽ� ó������ �׾� �÷��ߵȴ�.

		}

	}
	//DBlock.clear();
	change = false;
	//BStageChange = true;
}
