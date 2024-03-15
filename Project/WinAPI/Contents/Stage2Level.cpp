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

	User* user = SpawnActor<User>(); //플레이어 생성
	Ball* NewBall = SpawnActor<Ball>(); // 공생성
	Stage1Map* Stage2 = SpawnActor<Stage1Map>();
	Stage2->SetMapImage("Stage1_BackGround.png");
	UIManager* StageUI = SpawnActor<UIManager>();
	Block* TestBlock;
	std::vector<Block*> Blocks;

	{
		//Test

		for (int i = 0; i < 11; i++) //일자로 놓기
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
		

		//벡터용
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
		StartPos.Y = 400 - 42; // 다시 처음부터 쌓아 올려야된다.
	}

	/*
	내 코드가 안됬던 이윤ㄴ 
	startY위치를 다시 시작 Y로 옮기지 않았다 그래서 쌓여있던곳에 
	또다른 블록들이 쌓여서 이상하게 쌓이는 현상이 생겼다. 

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
