#include "Block.h"
#include<EngineCore/EngineResourcesManager.h>
#include"ColliderManager.h"
#include"Item.h"
#include<iostream>


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
enum BlockType
{
	Normal,
	Stack,
	NotDestory

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


}

void Block::BeginPlay()
{
	

	AActor::BeginPlay();
	BlockRender = CreateImageRenderer();
	BlockRender->SetImage("NewBlock.png", MINT);
	BlockRender->SetScale(BlockScale);


	BlockCollision = CreateCollision(ColliderOrder::Block);
	BlockCollision->SetColType(ECollisionType::Rect);
	BlockCollision->SetScale(BlockScale);


}





void Block::Tick(float _Deltatime)
{
	AActor::Tick(_Deltatime);


}

void Block::StackBlock()
{


}