
void FUN_10006b00(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 *in_ECX;
  int local_200;
  int *local_1fc;
  int *local_1f8;
  undefined1 local_1f4 [296];
  undefined1 local_cc [64];
  int local_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  undefined1 local_6c [64];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_1f8 = (int *)0x0;
  local_200 = 0;
  iVar7 = (**(code **)(*(int *)*in_ECX + 0x30))((int *)*in_ECX,0,&local_1f8);
  do {
    if (iVar7 == -0x7785fffe) {
      FUN_10006900(param_1);
      (**(code **)(*(int *)*param_1 + 0x1c))((int *)*param_1,0,param_2);
      (**(code **)(*(int *)*param_2 + 0x1c))((int *)*param_2,local_6c);
      in_ECX[0x2f] = (local_2c + local_24) / 2;
      in_ECX[0x30] = (local_28 + local_20) / 2;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    (**(code **)(*local_1f8 + 0x28))(local_1f8,local_1f4);
    FUN_100028b0(&DAT_1416e510,0x100,"Enumerated adapter %d : %ls \n",local_200,local_1f4);
    OutputDebugStringA(&DAT_1416e510);
    local_1fc = (int *)0x0;
    iVar7 = 0;
    iVar8 = (**(code **)(*local_1f8 + 0x1c))(local_1f8,0,&local_1fc);
    while (iVar8 != -0x7785fffe) {
      (**(code **)(*local_1fc + 0x1c))(local_1fc,local_cc);
      iVar6 = iStack_80;
      iVar5 = iStack_84;
      iVar4 = iStack_88;
      iVar8 = local_8c;
      FUN_100028b0(&DAT_1416e510,0x100,"Output coords : %d-%d, %d-%d \n",local_8c,iStack_84,
                   iStack_88,iStack_80);
      OutputDebugStringA(&DAT_1416e510);
      if (((int)in_ECX[0x2f] < iVar8) || (iVar5 < (int)in_ECX[0x2f])) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      iVar1 = in_ECX[0x30];
      if ((iVar1 < iVar4) || (iVar6 < iVar1)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      if ((bVar2) && (bVar3)) {
        FUN_100028b0(&DAT_1416e510,0x100,"Chosen output : (%d-%d, %d-%d) for point (%d, %d)\n",iVar8
                     ,iVar5,iVar4,iVar6,in_ECX[0x2f],iVar1);
        OutputDebugStringA(&DAT_1416e510);
        *param_1 = local_1f8;
        *param_2 = local_1fc;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      (**(code **)(*local_1fc + 8))(local_1fc);
      local_1fc = (int *)0x0;
      iVar7 = iVar7 + 1;
      iVar8 = (**(code **)(*local_1f8 + 0x1c))(local_1f8,iVar7,&local_1fc);
    }
    if (local_1f8 != (int *)0x0) {
      (**(code **)(*local_1f8 + 8))(local_1f8);
      local_1f8 = (int *)0x0;
    }
    local_200 = local_200 + 1;
    iVar7 = (**(code **)(*(int *)*in_ECX + 0x30))((int *)*in_ECX,local_200,&local_1f8);
  } while( true );
}

