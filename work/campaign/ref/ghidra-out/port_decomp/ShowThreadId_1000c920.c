
/* void __cdecl GaLogger::ShowThreadId(char const *) */

void __cdecl GaLogger::ShowThreadId(char *param_1)

{
  DWORD DVar1;
  
                    /* 0xc920  257  ?ShowThreadId@GaLogger@@YAXPBD@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  DVar1 = GetCurrentThreadId();
  FUN_100028b0(&DAT_1416ee10,0x80,"%s: thread - %d \n",param_1,DVar1);
  OutputDebugStringA(&DAT_1416ee10);
  return;
}

