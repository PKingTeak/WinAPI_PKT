#include "ArkanoidCore.h"
#include "User.h"
#include "Stage1Level.h"
#include <EngineBase/EngineDirectory.h>
#include <EngineBase/EngineFile.h>
#include <EngineCore/EngineResourcesManager.h>
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

	MainWindow.SetWindowScale({ 1280,720 }); //������ �������ְ�

	UEngineDirectory Dir;
	Dir.MoveParent();
	Dir.Move("ImageResource");

	
	
	CreateLevel<Stage1Level>("Stage1");
	//���� ó���� level�� �� ���� �ʿ�� ����
	ChangeLevel("Stage1");
	//MainWindow.SetTitle();
	//MainWindow.SetScale();


	
	// �̶��Ǹ� �̹� ������ â�� ��������ִ� �����ϰŶ�� 
	//â�� ����Ǹ鼭 �ʱ⼳�� 
	// ���� ��� âũ�� ���氰���� 

	//���⸦ �����ϸ� �ȴ�. 
	//���⿡�� Update�� �Ͽ� ������� ���� ��� ���⿡ ��� �κ�
	//

}

void ArkanoidCore::Tick(float _DelatTime)
{ // �Է� �޴°� Ȥ�� ��Ȳ�� �־��ִ°� ������ �ϰ�
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