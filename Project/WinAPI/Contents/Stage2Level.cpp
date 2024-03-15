#include "Stage2Level.h"
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

Stage2Level::Stage2Level()
{
}

Stage2Level::~Stage2Level()
{
}
void Stage2Level::BeginPlay()
{
	ULevel::BeginPlay();

	User* user = SpawnActor<User>(); //�÷��̾� ����
	Ball* NewBall = SpawnActor<Ball>(); // ������
	Stage1Map* Stage2 = SpawnActor<Stage1Map>();
	Stage2->SetMapImage("Stage1_BackGround.png");
	UIManager* StageUI = SpawnActor<UIManager>();
	Block* TestBlock;
	std::vector<Block*> Blocks;

	{
		//Test

		for (int i = 0; i < 11; i++) //���ڷ� ����
		{
			TestBlock = SpawnActor<Block>();
			TestBlock->SetBlockType(BlockType::Hard, TestBlock);
			int Blocklife = TestBlock->GetLife();
			BlockType thisBlockType = TestBlock->GetBlockType(TestBlock);
			TestBlock->SetActorLocation(FVector{ 45 + i * 42, 400 });
			Blocks.push_back(TestBlock);
			TestBlock->SetBlockCounter(1);


		}

	}

	FVector BlockScale = { 42, 24 };
	FVector StartPos = { 45 , 400 - 42 };
	int Count = 11;
	int ColorCount = 0;
	for (int i = 0; i < 11; i++)
	{
		

		//���Ϳ�
		for (size_t i = 0; i < Count; i++)
		{
			TestBlock = SpawnActor<Block>();
			TestBlock->SetBlockType(BlockType::Normal, TestBlock);
			BlockType thisBlockType = TestBlock->GetBlockType(TestBlock);
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

	/*
	�� �ڵ尡 �ȉ�� ������ 
	startY��ġ�� �ٽ� ���� Y�� �ű��� �ʾҴ� �׷��� �׿��ִ����� 
	�Ǵٸ� ��ϵ��� �׿��� �̻��ϰ� ���̴� ������ �����. 

	*/

	


}



void Stage2Level::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
	int Blocks = Block::BlockCounter;
	if (Blocks <= 0 || UEngineInput::IsDown('Q'))
	{
		GEngine->ChangeLevel("EndingLevel");

	}

}
