
/* public: void __thiscall TimeManager::SetTimer(int,unsigned __int64) */

UINT_PTR TimeManager::SetTimer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc)

{
  int in_ECX;
  
                    /* 0x16320  252  ?SetTimer@TimeManager@@QAEXH_K@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(UINT *)(in_ECX + 4 + (int)hWnd * 8) = uElapse;
  *(UINT_PTR *)(in_ECX + (int)hWnd * 8) = nIDEvent;
  return (UINT_PTR)hWnd;
}

