#include "Block.h"
#include<EngineCore/EngineResourcesManager.h>
#include"ColliderManager.h"

Block::Block()
{
}
Block::~Block()
{
}

void Block::BeginPlay()
{

	AActor::BeginPlay();
	BlockRender = CreateImageRenderer();
	BlockRender->SetImage("NormalBlock.png", 2);
	UEngineResourcesManager::GetInst().CuttingImage("NormalBlock.png", 4, 2);
	//BlockRender->SetImage("Item.png");
	//UEngineResourcesManager::GetInst().CuttingImage("Item.png", 8, 8);
	BlockRender->SetScale(BlockScale * 2);
	SetActorLocation({ 100,100 });


	BlockCollision = CreateCollision(ColliderOrder::Block);
	BlockCollision->SetColType(ECollisionType::Rect);
	BlockCollision->SetScale(BlockScale * 2);

	

	


}

void Block::Tick(float _Deltatime)
{
	AActor::Tick(_Deltatime);


}

//Block* Block::GetMainBlock()
//{
//	return MainBlock;
//}