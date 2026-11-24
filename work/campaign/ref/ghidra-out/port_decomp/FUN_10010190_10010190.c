
uint FUN_10010190(uint param_1,char param_2)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  int *in_ECX;
  undefined4 in_EDX;
  uint uVar4;
  undefined1 local_20 [16];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100423e1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  uVar4 = 0;
  iVar1 = *in_ECX;
  if (DisplayModeManager::s_instance == (DisplayModeManager *)0x0) {
    DisplayModeManager::s_instance = (DisplayModeManager *)FUN_1003ff62(0xc);
    *(undefined8 *)DisplayModeManager::s_instance = 0;
    *(undefined4 *)(DisplayModeManager::s_instance + 8) = 0;
  }
  uVar2 = *(uint *)(iVar1 + 0x8c);
  if (uVar2 != 0) {
    do {
      if (param_2 == '\0') {
        param_1 = param_1 - 1;
        if ((int)param_1 < 0) {
          param_1 = uVar2 - 1;
        }
      }
      else {
        param_1 = (param_1 + 1) % uVar2;
      }
      if ((*(uint *)(*(int *)(iVar1 + 0xd4) + param_1 * 4) &
          *(uint *)(DisplayModeManager::s_instance + 4)) != 0) {
        ExceptionList = local_10;
        return param_1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  if (*(int *)(*(int *)((int)ThreadLocalStoragePointer + _tls_index * 4) + 4) < DAT_1416edc8) {
    FUN_1003fe8c(&DAT_1416edc8);
    if (DAT_1416edc8 == -1) {
      local_8 = 0;
      DAT_1416ebfc = DisplayModeManager::GetInstance();
      local_8 = 0xffffffff;
      FUN_1003fe42(&DAT_1416edc8);
    }
  }
  if (*(int *)DAT_1416ebfc == 1) {
    pcVar3 = "Fullscreen";
  }
  else {
    pcVar3 = "Borderless";
    if (*(int *)DAT_1416ebfc != 4) {
      pcVar3 = "Windowed";
    }
  }
  FUN_100028b0(&DAT_1416ec80,0x40,"Didn\'t find next resolution for current mode : %s \n",pcVar3);
  OutputDebugStringA(&DAT_1416ec80);
  FUN_100053a0(0xffffffff);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_20,(ThrowInfo *)&DAT_1004a24c);
}

