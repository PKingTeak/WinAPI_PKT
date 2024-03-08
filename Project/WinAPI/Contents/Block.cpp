#include "Block.h"
#include<EngineCore/EngineResourcesManager.h>
#include"ColliderManager.h"
#include"Item.h"
#include<iostream>
#include"UIManager.h"



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
	//Item* NewItem = Item::GetMainItem();
	//NewItem->SetActorLocation(this->GetActorLocation());
	//NewItem->SetActive(true, 0.0f);
	UIManager* ScoreUI = UIManager::GetUIManager();
	ScoreUI->ScorePlus(GetBlockScore());
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



int Block::LifeDecrease()
{
	life -= 1;
	return life;
}


void Block::Tick(float _Deltatime)
{
	AActor::Tick(_Deltatime);


}
void Block::SetLife(int _Count)
{
	life = _Count;
}


int Block::GetLife()
{
	return life;
}

void Block::BlockLife(int _Count)
{
	life = _Count;
}


int Block::SetBlockType(int _BlockType, Block* _NewBlock)
{
	Block* thisBlock = _NewBlock;
	UImageRenderer* otherBlockRender = thisBlock->BlockRender;
	int num = _BlockType;
	if (num == 1) // Hardºí·Ï
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


