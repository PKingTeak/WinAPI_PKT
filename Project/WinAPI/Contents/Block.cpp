#include "Block.h"
#include<EngineCore/EngineResourcesManager.h>


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
	BlockRender->SetImage("NormalBlock.png",1);
	UEngineResourcesManager::GetInst().CuttingImage("NormalBlock.png",4,2);
	BlockRender->SetScale(BlockScale*2);
	SetActorLocation({ 100,100 });
	int a = 0;
}

void Block::Tick(float _Deltatime)
{
	AActor::Tick(_Deltatime);


}

//Block* Block::GetMainBlock()
//{
//	return MainBlock;
//}