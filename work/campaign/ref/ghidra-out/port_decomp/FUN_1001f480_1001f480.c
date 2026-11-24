
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_1001f480(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined1 auStack_402c [4];
  undefined4 *local_4028;
  undefined4 *local_4024;
  uint local_4020;
  undefined4 *local_401c;
  undefined4 *local_4018;
  undefined4 *local_4014;
  undefined4 local_4010 [4097];
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)auStack_402c;
  local_4014 = param_2;
  local_4024 = param_1;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar4 = (undefined4 *)0x0;
  if (*(int *)(in_ECX + 0x1c8) == 0) {
    __security_check_cookie(local_c ^ (uint)auStack_402c);
    return;
  }
  switch(*(undefined4 *)(*(int *)(in_ECX + 0x1c0) + 0x68)) {
  case 0:
    local_401c = (undefined4 *)0x0;
    if (param_2 != (undefined4 *)0x0) {
      do {
        local_4020 = (int)param_2 - (int)local_401c;
        local_4028 = puVar4;
        if (local_4020 < 0x201) {
          iVar1 = FUN_1002ca50(local_4020,0);
          local_4018 = (undefined4 *)((int)puVar4 + iVar1);
          if (local_4020 != 0) goto LAB_1001f852;
        }
        else {
          local_4020 = 0x200;
          iVar1 = FUN_1002ca50(0x200,0);
          local_4018 = (undefined4 *)(iVar1 + (int)puVar4);
LAB_1001f852:
          uVar5 = 0;
          local_4028 = local_4024;
          do {
            uVar3 = 0;
            puVar4 = local_4028;
            if (*(int *)(in_ECX + 0x48) != 0) {
              do {
                iVar1 = *(ushort *)(*(int *)(in_ECX + 0x1cc) + 0x50) * uVar5 + uVar3;
                uVar3 = uVar3 + 1;
                *puVar4 = local_4010[iVar1];
                puVar4 = puVar4 + (int)local_4014;
              } while (uVar3 < *(uint *)(in_ECX + 0x48));
            }
            uVar5 = uVar5 + 1;
            local_4028 = local_4028 + 1;
            param_2 = local_4014;
          } while (uVar5 < local_4020);
        }
        local_4024 = local_4024 + 0x200;
        local_401c = local_401c + 0x80;
        puVar4 = local_4018;
        if (param_2 <= local_401c) {
          *(int *)(in_ECX + 0x1c4) = *(int *)(in_ECX + 0x1c4) + (int)local_4018;
          __security_check_cookie(local_c ^ (uint)auStack_402c);
          return;
        }
      } while( true );
    }
    break;
  case 1:
    if (*(uint *)(in_ECX + 0x1d4) < *(uint *)(in_ECX + 0x1d0)) {
      puVar4 = (undefined4 *)
               FUN_1001f3f0(param_2,param_3,*(uint *)(in_ECX + 0x1d0),*(uint *)(in_ECX + 0x1d4),
                            *(undefined4 *)(in_ECX + 0x48));
      *(int *)(in_ECX + 0x1c4) = *(int *)(in_ECX + 0x1c4) + (int)puVar4;
      *(int *)(in_ECX + 0x1d4) = *(int *)(in_ECX + 0x1d4) + (int)puVar4;
    }
    while (puVar4 < param_2) {
      uVar2 = FUN_1003f880(in_ECX + 0x1d8);
      *(undefined4 *)(in_ECX + 0x1d0) = uVar2;
      *(undefined4 *)(in_ECX + 0x1d4) = 0;
      iVar1 = FUN_1001f3f0((int)param_2 - (int)puVar4,param_3,uVar2,0,*(undefined4 *)(in_ECX + 0x48)
                          );
      puVar4 = (undefined4 *)((int)puVar4 + iVar1);
      *(int *)(in_ECX + 0x1c4) = *(int *)(in_ECX + 0x1c4) + iVar1;
      *(int *)(in_ECX + 0x1d4) = *(int *)(in_ECX + 0x1d4) + iVar1;
      if ((*(uint *)(*(int *)(in_ECX + 0x1c0) + 0x78) <= *(uint *)(in_ECX + 0x1c4)) || (iVar1 == 0))
      {
        *(uint *)(in_ECX + 0x1c4) = *(uint *)(in_ECX + 0x1c4) + (int)puVar4;
        __security_check_cookie(local_c ^ (uint)auStack_402c);
        return;
      }
    }
  default:
    __security_check_cookie(local_c ^ (uint)auStack_402c);
    return;
  case 2:
    local_4028 = (undefined4 *)0x0;
    if (param_2 != (undefined4 *)0x0) {
      do {
        local_4020 = (int)param_2 - (int)local_4028;
        local_401c = puVar4;
        if (local_4020 < 0x201) {
          iVar1 = FUN_10036ae0(local_4020,0);
          local_4018 = (undefined4 *)((int)puVar4 + iVar1);
          if (local_4020 != 0) goto LAB_1001f557;
        }
        else {
          local_4020 = 0x200;
          iVar1 = FUN_10036ae0(0x200,0);
          local_4018 = (undefined4 *)(iVar1 + (int)puVar4);
LAB_1001f557:
          uVar5 = 0;
          local_401c = local_4024;
          do {
            uVar3 = 0;
            puVar4 = local_401c;
            if (*(int *)(in_ECX + 0x48) != 0) {
              do {
                iVar1 = *(byte *)(*(int *)(in_ECX + 0x1cc) + 0x1c) * uVar5 + uVar3;
                uVar3 = uVar3 + 1;
                *puVar4 = local_4010[iVar1];
                puVar4 = puVar4 + (int)local_4014;
              } while (uVar3 < *(uint *)(in_ECX + 0x48));
            }
            uVar5 = uVar5 + 1;
            local_401c = local_401c + 1;
            param_2 = local_4014;
          } while (uVar5 < local_4020);
        }
        local_4024 = local_4024 + 0x200;
        local_4028 = local_4028 + 0x80;
        puVar4 = local_4018;
      } while (local_4028 < param_2);
    }
    break;
  case 3:
    local_401c = (undefined4 *)0x0;
    if (param_2 != (undefined4 *)0x0) {
      do {
        local_4020 = (int)param_2 - (int)local_401c;
        local_4028 = puVar4;
        if (local_4020 < 0x201) {
          iVar1 = FUN_10027ee0(local_4020,0);
          local_4018 = (undefined4 *)((int)puVar4 + iVar1);
          if (local_4020 != 0) goto LAB_1001f652;
        }
        else {
          local_4020 = 0x200;
          iVar1 = FUN_10027ee0(0x200,0);
          local_4018 = (undefined4 *)(iVar1 + (int)puVar4);
LAB_1001f652:
          uVar5 = 0;
          local_4028 = local_4024;
          do {
            uVar3 = 0;
            puVar4 = local_4028;
            if (*(int *)(in_ECX + 0x48) != 0) {
              do {
                iVar1 = *(int *)(*(int *)(in_ECX + 0x1cc) + 0x1a20) * uVar5 + uVar3;
                uVar3 = uVar3 + 1;
                *puVar4 = local_4010[iVar1];
                puVar4 = puVar4 + (int)local_4014;
              } while (uVar3 < *(uint *)(in_ECX + 0x48));
            }
            uVar5 = uVar5 + 1;
            local_4028 = local_4028 + 1;
            param_2 = local_4014;
          } while (uVar5 < local_4020);
        }
        local_4024 = local_4024 + 0x200;
        local_401c = local_401c + 0x80;
        puVar4 = local_4018;
        if (param_2 <= local_401c) {
          *(int *)(in_ECX + 0x1c4) = *(int *)(in_ECX + 0x1c4) + (int)local_4018;
          __security_check_cookie(local_c ^ (uint)auStack_402c);
          return;
        }
      } while( true );
    }
  }
  *(int *)(in_ECX + 0x1c4) = *(int *)(in_ECX + 0x1c4) + (int)puVar4;
  __security_check_cookie(local_c ^ (uint)auStack_402c);
  return;
}

