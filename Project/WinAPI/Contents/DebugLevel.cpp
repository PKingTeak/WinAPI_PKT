#include "DebugLevel.h"
#include"Ball.h"
#include"Block.h"
#include"User.h"
#include<vector>
DebugLevel::DebugLevel()
{}
DebugLevel::~DebugLevel()
{}


void DebugLevel::BeginPlay()
{
	ULevel::BeginPlay();
	Ball* TestBall = SpawnActor<Ball>();
	TestBall->SetSpeed(50.0f);
	User::GetMainUser()->CurPos = { 300,300 };
	TestBall->SetActorLocation({ 300,300 });
	//Block* NewBlock1 = SpawnActor<Block>();
	//NewBlock1->SetActorLocation({ 340, 50 });
	//Block* NewBlock2 = SpawnActor<Block>();
	//NewBlock2->SetActorLocation({ 280, 500 });
 

	{

		std::vector<Block*> Blocks;
		for (int j = 0; j < 20; j++)
		{
			for (int i = 0; i < 30; i++)
			{
				Block* NewBlock1 = SpawnActor<Block>();
				NewBlock1->SetActorLocation(FVector{ 45 + i * 42,120 + 50 * j });
				NewBlock1->SetBlockColor(4);
				Blocks.push_back(NewBlock1);
			}
	
	
		}
	
	//

	}

}

void DebugLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);
}
