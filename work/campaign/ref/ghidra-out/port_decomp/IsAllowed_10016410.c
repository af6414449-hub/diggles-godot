
/* public: bool __thiscall TimeManager::IsAllowed(int,__int64 *) */

bool __thiscall TimeManager::IsAllowed(TimeManager *this,int param_1,__int64 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  __int64 _Var5;
  
                    /* 0x16410  190  ?IsAllowed@TimeManager@@QAE_NHPA_J@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar4 = _Xtime_get_ticks();
  _Var5 = __alldiv(uVar4,10000000,0);
  iVar3 = (int)((ulonglong)_Var5 >> 0x20);
  uVar1 = (uint)_Var5;
  if (param_2 != (__int64 *)0x0) {
    *param_2 = _Var5;
  }
  uVar2 = (iVar3 - *(int *)(this + param_1 * 8 + 0x804)) -
          (uint)(uVar1 < *(uint *)(this + param_1 * 8 + 0x800));
  if ((*(uint *)(this + param_1 * 8 + 4) <= uVar2) &&
     ((*(uint *)(this + param_1 * 8 + 4) < uVar2 ||
      (*(uint *)(this + param_1 * 8) <= uVar1 - *(uint *)(this + param_1 * 8 + 0x800))))) {
    *(uint *)(this + param_1 * 8 + 0x800) = uVar1;
    *(int *)(this + param_1 * 8 + 0x804) = iVar3;
    return true;
  }
  return false;
}

