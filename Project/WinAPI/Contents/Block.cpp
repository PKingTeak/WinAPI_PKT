#include "Block.h"
#include<EngineCore/EngineResourcesManager.h>
#include"ColliderManager.h"
#include"Item.h"
#include<iostream>
#include"UIManager.h"
#include<EngineBase/EngineRandom.h>
#include"Stage1Level.h"



enum Blocks
{
	WHITE = 0,
	ORANG = 1,
	MINT = 2,
	GREEN = 3,
	RED = 4,
	BLUE = 5,
	PINK = 6,
	YELLOW = 7

};





Block::Block()
{

}
Block::Block(int _Color)
{

}
Block::~Block()
{
	if (Stage1Level::isCheat == false)
	{


		int SpawnNum = ItemSpawnpercentage();

		if (SpawnNum == 2 || SpawnNum == 5 || SpawnNum == 8)
		{
			ULevel* Stage1Level = GetWorld(); //�ش� ���� ��������
			Item* NewItem = Stage1Level->SpawnActor<Item>();
			NewItem->SetActorLocation(this->GetActorLocation()); //��ġ 
			NewItem->SetActive(true);

		}
		ScoreUI->ScorePlus(GetBlockScore());
		if (BlockCounter > 0)
		{
			BlockCounter--;

		}

	}
	else
	{
		int a = 0;
	}
}




void Block::BeginPlay()
{
	ScoreUI = UIManager::GetUIManager();

	AActor::BeginPlay();



	BlockRender = CreateImageRenderer();
	BlockRender->SetImage("NewBlock.png", MINT);
	BlockRender->SetScale(BlockScale);


	BlockCollision = CreateCollision(ColliderOrder::Block);
	BlockCollision->SetColType(ECollisionType::Rect);
	BlockCollision->SetScale(BlockScale);



}


int Block::ItemSpawnpercentage()
{
	return UEngineRandom::MainRandom.RandomInt(1, 10);


}



int Block::LifeDecrease()
{
	Blocklife -= 1;
	return Blocklife;
}


void Block::Tick(float _Deltatime)
{
	AActor::Tick(_Deltatime);


}
void Block::SetLife(int _Count)
{
	Blocklife = _Count;
}


int Block::GetLife()
{
	return Blocklife;
}

void Block::BlockLife(int _Count)
{
	Blocklife = _Count;
}


int Block::SetBlockType(int _BlockType, Block* _NewBlock)
{
	Block* thisBlock = _NewBlock;
	UImageRenderer* otherBlockRender = thisBlock->BlockRender;
	int num = _BlockType;
	if (num == 1) // Hard���
	{
		thisBlock->SetLife(2);

		otherBlockRender->SetImage("OtherBlock.png", 0);
		otherBlockRender->SetScale(BlockScale);
		otherBlockRender->CreateAnimation("HardBlockAnimation", "OtherBlock.png", 0, 5, 0.1f, false);

		this->HardBlockAnimation(thisBlock);
	}
	else if (num == 2)
	{
		thisBlock->SetLife(99999);
	}
	BlockRender = otherBlockRender;
	return num;
}



BlockType Block::GetBlockType(Block* _NewBlock)
{

	return _NewBlock->Type;
}

void Block::SetScore(int _BlockScore)
{
	BlockScore = _BlockScore;
}

void Block::SetBlockCounter(int _BlockCounter)
{
	BlockCounter += _BlockCounter;
}

int Block::GetBlockCounter()
{
	return BlockCounter;
}
