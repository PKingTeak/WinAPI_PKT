#include "Block.h"
Block* MainBlock = nullptr;
Block::Block()
{
}
Block::~Block()
{
}

void Block::BeginPlay()
{
	MainBlock = this;
	AActor::BeginPlay();

}

void Block::Tick(float _Deltatime)
{
	AActor::Tick(_Deltatime);


}

Block* Block::GetMainBlock()
{
	return MainBlock;
}