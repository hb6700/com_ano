#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

//'winmm.lib'������ ��ũ�Ҷ� �߰�
#pragma connect(lib, "winmm.lib")

//����Ǵ� ����ü�� 1����Ʈ ������ ����
#pragma pack(push, 1)

//Short Midi MSG����ü
typedef struct
{
	BYTE byteState;			//MIDI State	
	BYTE byteNote;			//MIDI Data(1)
	BYTE byteVelocity;		//MIDI Data(2)
	BYTE byteNULL;
};MIDShortMSG_ST;

//MIDIShortMSG_ST ����ü ����
//DWORD(unsigned  long)�� ��ȯ�Ҷ� ����ϴ� ����ü
typedef union
{
	DWORD			dwMIDIData;
	MIDShortMSG_ST	stMIDIData;
}MIDShortMSG_ST;

//���� ����ü ���� ������� ����
#pragma pack(pop)

//�̵� ��� �߿� �߻��ϴ� �޽����� �޴� �ݹ� �Լ�
void CALLBACK MidiOutProc(HMIDIOUT hMidiDevice, UINT uMsg, DWORD Instannce, DWORD Param1, DWORD Param2)
{
}

//�̵� ���� �ڵ带 ���ڿ��� ����ϴ� �Լ�
void MIDIOutputError(MMRESULT mmResult)
{
	//����  ���ڿ��� ������ �迭
	char szErrMsg[128];

	//���� �ڵ带 ���ڿ��� ��ȯ
	midiInGetErrorText(mmResult, (char *)szErrMsg, sizeof(szErrMsg));

	//��ȯ�� ���ڿ��� ����� �ڽ��� ���
	MessageBox(0, szErrMsg, "Midi Error!!!", MB_OK);
}

void main()
{
	puts("�� �������� �� ������������ ��");
	puts("�� �������� �� ������������ ��");
	puts("�� �������� �� ������������ ��");
	puts("�� �������� �� ������������ ��");
	puts("�� �������� �� ������������ ��");
	puts("��  ��  ��  ��  ��  ��  ��  ��");
	puts("��  ��  ��  ��  ��  ��  ��  ��");
	puts("������������������������������");

	getchar();
	return 0;
}