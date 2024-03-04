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
	//속성 부여 완료
	}
	ColUser->CreateCollision(ColliderOrder::Player);




	
	//충돌체 만들었고 
}


void Tick(float _deltaTime)
{

	

}
