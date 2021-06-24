#ifndef MACHINE_H_INCLUDED
#define MACHINE_H_INCLUDED

#include <windows.h>
#include "snake.h"

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

bool DLL_EXPORT check(point snake[5][100], int len[5], int t, GamePanel gp, int direction );
int  DLL_EXPORT machine_move(point snake[5][100], int len[5], int direct[5], int t, GamePanel gp);

#ifdef __cplusplus
}
#endif


#endif // MACHINE_H_INCLUDED
