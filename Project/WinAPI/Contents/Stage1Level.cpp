#include "Stage1Level.h"
#include "User.h"

Stage1Level::Stage1Level()
{
}

Stage1Level::~Stage1Level()
{
}
void Stage1Level::BeginPlay()
{

	this->SpawnActor<User>();
}
