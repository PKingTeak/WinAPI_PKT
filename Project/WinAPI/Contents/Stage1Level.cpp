#include "Stage1Level.h"
#include "User.h"
#include <EngineCore/EngineResourcesManager.h>
#include<EngineBase/EngineFile.h>
#include<EngineBase/EngineDirectory.h>

Stage1Level::Stage1Level()
{
}

Stage1Level::~Stage1Level()
{
}
void Stage1Level::BeginPlay()
{
	UEngineDirectory NewPath;
	NewPath.MoveParent();//����

	NewPath.Move("ImageResource");

	std::list<UEngineFile> AllFileList = NewPath.AllFile({ ".png", ".bmp" }, true);

	for (UEngineFile& File : AllFileList)
	{
		std::string FullPath = File.GetFullPath();
		// �̱��� ���� ����� �Ϻη� GetInst�� ����ϰڽ��ϴ�.
		UEngineResourcesManager::GetInst().LoadImg(FullPath);
	}


	this->SpawnActor<User>();
}
