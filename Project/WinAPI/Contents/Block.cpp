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
	BlockRender->SetImage("NewBlock.png", MINT);
	BlockRender->SetScale(BlockScale);

	
	BlockCollision = CreateCollision(ColliderOrder::Block);
	BlockCollision->SetColType(ECollisionType::Rect);
	BlockCollision->SetScale(BlockScale);

	int a = 0;
}





void Block::Tick(float _Deltatime)
{
	AActor::Tick(_Deltatime);


}

void Block::BlockSide(FVector _CurBallPos)
{
	Block* thisBlock = this;
	float BlockLeft = (BlockScale.hX() + thisBlock->BlockLeft()) + thisBlock->GetActorLocation().X;
	float BlockRight = BlockScale.hX() + thisBlock->BlockRight() + thisBlock->GetActorLocation().X;


	float BlockTop = BlockScale.hY() + thisBlock->BlockUP()+ thisBlock->GetActorLocation().Y;
	float BlockBottom = BlockScale.hY() + thisBlock->BlockBottom()+ thisBlock->GetActorLocation().Y;
	if (BlockLeft <= _CurBallPos.X && _CurBallPos.X < BlockScale.hX())
	{

		int a = 0;
		//왼쪽 
	}
	else if (_CurBallPos.X >= BlockScale.hX() && _CurBallPos.X <= BlockRight)
	{
		int b = 0;
		//오른쪽
	}
	
	if (_CurBallPos.Y <= BlockScale.hY() && _CurBallPos.Y >= BlockTop)
	{
		int c = 0;
		//위
	}
	else if (_CurBallPos.Y > BlockScale.hY() && _CurBallPos.Y <= BlockBottom)
	{
		int d = 0;
		//아래
	}

	int x = 0;

}

//Block* Block::GetMainBlock()
//{
//	return MainBlock;
//}