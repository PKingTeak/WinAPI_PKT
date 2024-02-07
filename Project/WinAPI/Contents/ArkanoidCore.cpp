#include "ArkanoidCore.h"
#include "User.h"
#include "Stage1Level.h"
#include "TitleLevel.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/EngineResourcesManager.h>

FVector ArkanoidCore::ScreenSize = { 800,600 };
//���� ���� �ϰ� ������ �����ָ� ��Ŀ�� ��ã�´�. 
//1120 2001������ ������ Static������ 
//��� �߰��� �ϸ� ��~

ArkanoidCore::ArkanoidCore()
	:UEngineCore()
{
}

ArkanoidCore::~ArkanoidCore()
{
}

// ���ӽ���
void ArkanoidCore::BeginPlay()
{
	UEngineCore::BeginPlay();

	MainWindow.SetWindowScale({ ScreenSize.X,ScreenSize.Y }); //������ �������ְ�

	UEngineDirectory Dir;
	Dir.MoveParent();
	Dir.Move("ImageResource");


	std::list<UEngineFile> FList = Dir.AllFile({ ".png",".bmp" }, true);
	for (UEngineFile& File : FList)

	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}
	
	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<Stage1Level>("Stage1Level");
	
	ChangeLevel("TitleLevel");
	
	
	UEngineResourcesManager::GetInst().CuttingImage("Player_Idle.png", 32,8);
	//�̲������� ��©���ſ���.
	
	// �̶��Ǹ� �̹� ������ â�� ��������ִ� �����ϰŶ�� 
	//â�� ����Ǹ鼭 �ʱ⼳�� 
	// ���� ��� âũ�� ���氰���� 

	//���⸦ �����ϸ� �ȴ�. 
	//���⿡�� Update�� �Ͽ� ������� ���� ��� ���⿡ ��� �κ�
	//

}

void ArkanoidCore::Tick(float _DelatTime)

{
	UEngineCore::Tick(_DelatTime);
	// �Է� �޴°� Ȥ�� ��Ȳ�� �־��ִ°� ������ �ϰ�
	//Ư�� ��ư�� ������ changeLevel�ϴ°��ΰ�?
	//if (/*�÷��̾ �浹�ߴ� �� ������ Ŭ���� �ߴ�*/)
	//{
	//ChangeLevel("Stage1");
	//
	//}
	//���൵��
	//�÷��̾� ���۰����� 
	//���� (��ü�� �Լ� ������ ���� ����)
}

void ArkanoidCore::End()
{
	//�Ҹ��� ȣ���̳� ������ ������ ��������
	
}