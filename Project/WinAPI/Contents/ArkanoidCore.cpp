#include "ArkanoidCore.h"
#include "User.h"
#include "Stage1Level.h"
#include "TitleLevel.h"
#include <EngineBase/EngineFile.h>
#include <EngineCore/EngineResourcesManager.h>
#include<EnginePlatform/EngineSound.h>

#include<EngineBase/EngineDirectory.h>


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
	Dir.MoveToSearchChild("ImageResource");
	//SDir.MoveToSearchChild("SoundResource");
	SDir.MoveParent();
	SDir.Move("SoundResource");


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

		int a = 0;

	}


	UEngineResourcesManager::GetInst().CuttingImage("NewBlock.png", 4, 2);
	UEngineResourcesManager::GetInst().CuttingImage("OtherBlock.png", 6, 2);

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
	if (UEngineInput::IsDown('P'))
	{
		DebugMod();
	}
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

void ArkanoidCore::DebugMod()
{
	GEngine->EngineDebugSwitch();
}
void ArkanoidCore::CreateBlock()
{


}

void ArkanoidCore::End()
{
	//�Ҹ��� ȣ���̳� ������ ������ ��������

}