
/* public: void __thiscall TimeManager::ShowTime(char const *,int) */

void __thiscall TimeManager::ShowTime(TimeManager *this,char *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  undefined8 uVar5;
  char *local_1c;
  __time64_t _Stack_18;
  uint local_c;
  
                    /* 0x16350  258  ?ShowTime@TimeManager@@QAEXPBDH@Z */
  local_c = DAT_1005000c ^ (uint)&local_1c;
  local_1c = param_1;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar5 = _Xtime_get_ticks();
  _Stack_18 = __alldiv(uVar5,10000000,0);
  iVar4 = (int)((ulonglong)_Stack_18 >> 0x20);
  uVar1 = (uint)_Stack_18;
  uVar2 = (iVar4 - *(int *)(this + param_2 * 8 + 0x804)) -
          (uint)(uVar1 < *(uint *)(this + param_2 * 8 + 0x800));
  if ((*(uint *)(this + param_2 * 8 + 4) <= uVar2) &&
     ((*(uint *)(this + param_2 * 8 + 4) < uVar2 ||
      (*(uint *)(this + param_2 * 8) <= uVar1 - *(uint *)(this + param_2 * 8 + 0x800))))) {
    *(uint *)(this + param_2 * 8 + 0x800) = uVar1;
    *(int *)(this + param_2 * 8 + 0x804) = iVar4;
    pcVar3 = _ctime64(&_Stack_18);
    FUN_100028b0(&DAT_1416ef60,0x40,&DAT_10045450,pcVar3);
    OutputDebugStringA(local_1c);
    OutputDebugStringA(&DAT_1416ef60);
  }
  __security_check_cookie(local_c ^ (uint)&local_1c);
  return;
}

