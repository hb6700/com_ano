#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

//'winmm.lib'파일을 링크할때 추가
#pragma connect(lib, "winmm.lib")

//선언되는 구조체를 1바이트 단위로 정렬
#pragma pack(push, 1)

//Short Midi MSG구조체
typedef struct
{
	BYTE byteState;			//MIDI State	
	BYTE byteNote;			//MIDI Data(1)
	BYTE byteVelocity;		//MIDI Data(2)
	BYTE byteNULL;
};MIDShortMSG_ST;

//MIDIShortMSG_ST 구조체 값을
//DWORD(unsigned  long)로 변환할때 사용하는 공용체
typedef union
{
	DWORD			dwMIDIData;
	MIDShortMSG_ST	stMIDIData;
}MIDShortMSG_ST;

//원래 구조체 벙렬 방식으로 변경
#pragma pack(pop)

//미디 출력 중에 발생하는 메시지를 받는 콜백 함수
void CALLBACK MidiOutProc(HMIDIOUT hMidiDevice, UINT uMsg, DWORD Instannce, DWORD Param1, DWORD Param2)
{
}

//미디 에러 코드를 문자열로 출력하는 함수
void MIDIOutputError(MMRESULT mmResult)
{
	//에러  문자열을 저장할 배열
	char szErrMsg[128];

	//에러 코드를 문자열로 변환
	midiInGetErrorText(mmResult, (char *)szErrMsg, sizeof(szErrMsg));

	//변환된 문자열을 멤시지 박스로 출력
	MessageBox(0, szErrMsg, "Midi Error!!!", MB_OK);
}

void main()
{
	puts("│ ││││ │ ││││││ │");
	puts("│ ││││ │ ││││││ │");
	puts("│ ││││ │ ││││││ │");
	puts("│ ││││ │ ││││││ │");
	puts("│ └┘└┘ │ └┘└┘└┘ │");
	puts("│  │  │  │  │  │  │  │");
	puts("│  │  │  │  │  │  │  │");
	puts("└─┴─┴─┴─┴─┴─┴─┘");

	getchar();
	return 0;
}