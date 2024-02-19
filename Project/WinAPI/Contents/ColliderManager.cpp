#include "ColliderManager.h"



ColliderManager::ColliderManager()
{
}

ColliderManager::~ColliderManager()
{
}

void ColliderManager::BeginPlay()
{
	{

	ColUser = User::GetMainUser();
	ColBall = Ball::GetMainBall();
	ColBlock = Block::GetMainBlock();
	//속성 부여 완료
	}
	ColUser->CreateCollision(ColliderOrder::Player);
	ColBall->CreateCollision(ColliderOrder::Ball);
	ColBlock->CreateCollision(ColliderOrder::Block);

	
	//충돌체 만들었고 
}
