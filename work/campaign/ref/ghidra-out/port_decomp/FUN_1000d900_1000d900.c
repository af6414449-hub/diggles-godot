
void FUN_1000d900(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int *in_ECX;
  int *piVar2;
  undefined4 in_EDX;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  bool bVar7;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int local_1c [4];
  int local_c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  local_20 = param_3;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_2c = (int *)0x0;
  piVar4 = (int *)0x0;
  local_34 = (int *)0x0;
  piVar6 = (int *)0x0;
  local_c = 0;
  iVar1 = (**(code **)(*param_1 + 0x88))(param_1,param_2,&local_c,&local_2c);
  if ((iVar1 < 0) || (local_c == 0)) goto LAB_1000db71;
  local_30 = (int *)0x0;
  local_28 = (int *)0x0;
  iVar1 = (**(code **)(*local_2c + 0x88))(local_2c,&local_30);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*local_30 + 0x20))(local_30,local_1c);
    if (-1 < iVar1) {
      piVar2 = &DAT_100434a0;
      piVar3 = local_1c;
      uVar5 = 0xc;
      do {
        if (*piVar2 != *piVar3) {
          piVar2 = &DAT_100434b0;
          piVar3 = local_1c;
          uVar5 = 0xc;
          goto LAB_1000d9e0;
        }
        piVar2 = piVar2 + 1;
        piVar3 = piVar3 + 1;
        bVar7 = 3 < uVar5;
        uVar5 = uVar5 - 4;
      } while (bVar7);
      iVar1 = MFCreateAudioRendererActivate(&local_28);
      goto LAB_1000d9fe;
    }
  }
  goto LAB_1000da17;
  while( true ) {
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
    bVar7 = uVar5 < 4;
    uVar5 = uVar5 - 4;
    if (bVar7) break;
LAB_1000d9e0:
    if (*piVar2 != *piVar3) {
      iVar1 = -0x7fffbffb;
      goto LAB_1000da17;
    }
  }
  iVar1 = MFCreateVideoRendererActivate(local_20,&local_28);
LAB_1000d9fe:
  if (-1 < iVar1) {
    local_34 = local_28;
    (**(code **)(*local_28 + 4))(local_28);
  }
LAB_1000da17:
  if (local_30 != (int *)0x0) {
    (**(code **)(*local_30 + 8))(local_30);
    local_30 = (int *)0x0;
  }
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
    local_28 = (int *)0x0;
  }
  if (-1 < iVar1) {
    local_20 = local_2c;
    local_24 = (int *)0x0;
    iVar1 = MFCreateTopologyNode(1,&local_24);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*local_24 + 0x6c))(local_24,&DAT_1004501c,in_EDX);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_24 + 0x6c))(local_24,&DAT_10045088,param_1);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_24 + 0x6c))(local_24,&DAT_100450a8,local_20);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*in_ECX + 0x88))(in_ECX,local_24);
            piVar3 = local_24;
            if (-1 < iVar1) {
              (**(code **)(*local_24 + 4))(local_24);
              piVar6 = piVar3;
            }
          }
        }
      }
    }
    if (local_24 != (int *)0x0) {
      (**(code **)(*local_24 + 8))(local_24);
      local_24 = (int *)0x0;
    }
    if (-1 < iVar1) {
      local_20 = (int *)0x0;
      iVar1 = MFCreateTopologyNode(0,&local_20);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_20 + 0x84))(local_20,local_34);
        if (-1 < iVar1) {
          iVar1 = (**(code **)(*local_20 + 0x54))(local_20,&DAT_10044ffc,0);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*local_20 + 0x54))(local_20,&DAT_10045078,0);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*in_ECX + 0x88))(in_ECX,local_20);
              piVar3 = local_20;
              if (-1 < iVar1) {
                (**(code **)(*local_20 + 4))(local_20);
                piVar4 = piVar3;
              }
            }
          }
        }
      }
      if (local_20 != (int *)0x0) {
        (**(code **)(*local_20 + 8))(local_20);
        local_20 = (int *)0x0;
      }
      if (-1 < iVar1) {
        (**(code **)(*piVar6 + 0xa0))(piVar6,0,piVar4,0);
      }
    }
  }
LAB_1000db71:
  if (local_2c != (int *)0x0) {
    (**(code **)(*local_2c + 8))(local_2c);
    local_2c = (int *)0x0;
  }
  if (local_34 != (int *)0x0) {
    (**(code **)(*local_34 + 8))(local_34);
  }
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 8))(piVar6);
  }
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

