#include "ArkanoidCore.h"
#include "User.h"
#include "Stage1Level.h"
#include "TitleLevel.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/EngineResourcesManager.h>
#include<EnginePlatform/EngineSound.h>

FVector ArkanoidCore::ScreenSize = { 552,602 }; //Static�� �̿��Ͽ� ���� �����ϴ� ���� �ʱ�ȭ 

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
	MainWindow.SetClearColor(Color8Bit::BlackA);
	UEngineDirectory Dir;
	UEngineDirectory SDir;
	Dir.MoveParent();
	Dir.Move("ImageResource");
	SDir.MoveParent();
	SDir.Move("SoundResorce");

	
	std::list<UEngineFile> FList = Dir.AllFile({ ".png",".bmp" }, true);
	for (UEngineFile& File : FList)

	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}
	std::list<UEngineFile> NewList = SDir.AllFile({ ".wav", ".mp3" }, true);
	// �������� ��Ģ�� ���Ұų�.
	for (UEngineFile& File : NewList)
	{
		UEngineSound::Load(File.GetFullPath());
	}

	
	UEngineResourcesManager::GetInst().CuttingImage("NewBlock.png", 4, 2);

	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<Stage1Level>("Stage1Level");
	
	ChangeLevel("Stage1Level");
	
	
	
	//�̲������� ��©���ſ���.
	
	// �̶��Ǹ� �̹� ������ â�� ��������ִ� �����ϰŶ�� 
	//â�� ����Ǹ鼭 �ʱ⼳�� 
	// ���� ��� âũ�� ���氰���� 

	//���⸦ �����ϸ� �ȴ�. 
	//���⿡�� Update�� �Ͽ� ������� ���� ��� ���⿡ ��� �κ�
	//

	// �������� ��Ģ�� ���Ұų�.
	

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