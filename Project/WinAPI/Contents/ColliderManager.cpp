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
	//�Ӽ� �ο� �Ϸ�
	}
	ColUser->CreateCollision(ColliderOrder::Player);
	ColBall->CreateCollision(ColliderOrder::Ball);
	ColBlock->CreateCollision(ColliderOrder::Block);

	
	//�浹ü ������� 
}
