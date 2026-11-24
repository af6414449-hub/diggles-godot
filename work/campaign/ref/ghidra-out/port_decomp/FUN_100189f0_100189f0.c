
void FUN_100189f0(int *param_1)

{
  undefined1 uVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  int *piVar5;
  int *piVar6;
  undefined4 extraout_ECX;
  undefined4 in_EDX;
  int *local_6c;
  int *local_68;
  undefined4 local_64;
  undefined4 local_60;
  float local_24;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10042af7;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (DAT_10050c64 == (int *)0x0) {
    local_68 = (int *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(local_68,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  piVar2 = DAT_10050c64;
  cVar4 = (**(code **)(*param_1 + 0x74))();
  if ((cVar4 == '\0') || (*(char *)((int)piVar2 + 0xcb9) != '\0')) {
    FUN_1000fe70();
    local_6c = (int *)0x0;
    (**(code **)(*param_1 + 0x54))(&local_6c);
    local_68 = (int *)0x0;
    (**(code **)(*param_1 + 0x58))(&local_68);
    piVar6 = local_6c;
    piVar2[0x321] = (uint)(local_6c != (int *)0x0);
    piVar5 = (int *)piVar2[0x205];
    if (piVar5 != local_6c) {
      if (local_6c != (int *)0x0) {
        (**(code **)(*local_6c + 4))(local_6c);
        piVar5 = (int *)piVar2[0x205];
      }
      piVar2[0x205] = (int)piVar6;
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 8))(piVar5);
      }
    }
    piVar3 = local_68;
    piVar6 = (int *)piVar2[0x20d];
    piVar5 = piVar2 + 0x20d;
    if (piVar6 != local_68) {
      if (local_68 != (int *)0x0) {
        (**(code **)(*local_68 + 4))(local_68);
        piVar6 = (int *)*piVar5;
      }
      *piVar5 = (int)piVar3;
      if (piVar6 != (int *)0x0) {
        (**(code **)(*piVar6 + 8))(piVar6);
      }
    }
    piVar6 = *(int **)(*piVar2 + 8);
    (**(code **)(*piVar6 + 0x20))(piVar6,0,1,piVar5);
    if (GammaManager::s_instance == (GammaManager *)0x0) {
      GammaManager::s_instance = (GammaManager *)FUN_1003ff62(8);
      *(undefined8 *)GammaManager::s_instance = 0;
    }
    local_64 = *(undefined4 *)GammaManager::s_instance;
    local_60 = *(undefined4 *)(GammaManager::s_instance + 4);
    local_24 = (float)(*(char *)(*piVar2 + 0xc5) == '\0');
    (**(code **)(*piVar6 + 0xc0))(piVar6,piVar2[4],0,0,&local_64,0,0);
    uVar1 = *(undefined1 *)((int)piVar2 + 0xcb9);
    FUN_1000f0a0(4,0x102,&DAT_10050168,4,&DAT_1005015c,6,extraout_ECX);
    *(undefined1 *)((int)piVar2 + 0xcb9) = uVar1;
    (**(code **)(*param_1 + 0x78))(1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

