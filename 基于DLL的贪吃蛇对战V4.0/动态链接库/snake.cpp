#include "machine.h"

// a sample exported function
/**
void DLL_EXPORT SomeFunction(const LPCSTR sometext)
{
    MessageBoxA(0, sometext, "DLL Message", MB_OK | MB_ICONINFORMATION);
}
**/
using namespace std;

bool DLL_EXPORT check(point snake[5][100], int len[5], int t, GamePanel gp, int direction )
{
    //�����check��������ڴ˴�����ɾȥ����ʾ������
	if (snake[t][1].y == gp.m && direction == 1) return false;
	if (snake[t][1].y == 2 && direction == 2) return false;
	return true;
}

int DLL_EXPORT machine_move(point snake[5][100], int len[5], int direct[5], int t, GamePanel gp)
{
    //�����machine_move��������ڴ˴�����ɾȥ����ʾ������

	if (t == 0) return 2;
	else return 1;
}
