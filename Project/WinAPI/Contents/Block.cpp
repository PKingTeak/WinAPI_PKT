#include "Block.h"
#include<EngineCore/EngineResourcesManager.h>
#include"ColliderManager.h"
#include"Item.h"

enum Blocks
{
	WHITE = 0,
	ORANG = 1,
	MINT = 2 ,
	GREEN= 3,
	RED = 4,
	BLUE = 5,
	PINK = 6,
	YELLOW = 7

};
 

Block::Block()
{
}
Block::~Block()
{
	Item* NewItem = Item::GetMainItem();
	NewItem->SetActorLocation(this->GetActorLocation());
	NewItem->SetActive(true);

	
}

void Block::BeginPlay()
{

	AActor::BeginPlay();
	BlockRender = CreateImageRenderer();
	BlockRender->SetImage("NormalBlock.png", MINT);
	UEngineResourcesManager::GetInst().CuttingImage("NormalBlock.png", 4, 2);
	BlockRender->SetScale(BlockScale * 2);
	SetActorLocation({ 100,100 });

	
	BlockCollision = CreateCollision(ColliderOrder::Block);
	BlockCollision->SetColType(ECollisionType::Rect);
	BlockCollision->SetScale(BlockScale * 2);

	

		


}



void Block::DropItem()
{
	

}

void Block::Tick(float _Deltatime)
{
	AActor::Tick(_Deltatime);


}

//Block* Block::GetMainBlock()
//{
//	return MainBlock;
//}