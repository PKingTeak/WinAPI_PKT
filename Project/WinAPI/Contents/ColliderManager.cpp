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
	
	//ColBlock = Block::GetMainBlock();
	//�Ӽ� �ο� �Ϸ�
	}
	ColUser->CreateCollision(ColliderOrder::Player);




	
	//�浹ü ������� 
}


void Tick(float _deltaTime)
{

	

}
