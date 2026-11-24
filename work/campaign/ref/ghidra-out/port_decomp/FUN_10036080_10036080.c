
void FUN_10036080(undefined4 param_1,undefined4 param_2,int *param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  undefined4 extraout_ECX;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined1 local_180 [2];
  undefined2 local_17e;
  undefined4 local_174;
  undefined1 local_170;
  undefined1 local_16f;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_150;
  uint local_14c;
  int local_148;
  undefined4 local_140;
  byte local_13b;
  undefined4 local_130;
  byte local_124;
  byte abStack_123 [263];
  uint local_1c;
  uint local_18;
  undefined4 local_14;
  char local_d;
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)&stack0xfffffffc;
  local_148 = in_ECX;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  local_1c = 0x5fb0a94f;
  local_18 = 0;
  *(undefined4 *)(in_ECX + 0xc) = 1;
  *(undefined4 *)(in_ECX + 0x1090) = 0;
  *(undefined4 *)(in_ECX + 0x1094) = 0;
  iVar4 = FUN_10035930(&local_140,&local_18,extraout_ECX);
  if (iVar4 == 0) {
    puVar1 = (uint *)(in_ECX + 0x30);
    uVar5 = *puVar1;
    *puVar1 = *puVar1 + local_18;
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + (uint)CARRY4(uVar5,local_18);
    while ((local_13b & 2) != 0) {
      local_14c = (uint)local_124;
      iVar6 = 0;
      iVar8 = 0;
      local_150 = 0;
      iVar4 = 0;
      if (1 < local_14c) {
        do {
          iVar6 = iVar6 + (uint)abStack_123[iVar4];
          iVar3 = iVar4 + 1;
          iVar4 = iVar4 + 2;
          iVar8 = iVar8 + (uint)abStack_123[iVar3];
          in_ECX = local_148;
        } while (iVar4 < (int)(local_14c - 1));
      }
      if (iVar4 < (int)local_14c) {
        uVar5 = (uint)abStack_123[iVar4];
      }
      else {
        uVar5 = 0;
      }
      uVar5 = iVar8 + iVar6 + uVar5;
      if (uVar5 == 0x33) {
        iVar4 = (**(code **)(*param_3 + 8))(&local_d,1);
        if (iVar4 != 1) break;
        if (local_d == '\x7f') {
          iVar4 = (**(code **)(*param_3 + 8))(&local_14,4);
          if (iVar4 != 4) break;
          if (((((char)local_14 == 'F') && ((char)((uint)local_14 >> 8) == 'L')) &&
              (local_14._2_1_ == 'A')) && (local_14._3_1_ == 'C')) {
            iVar4 = (**(code **)(*param_3 + 8))(&local_18,2);
            if ((iVar4 == 2) && ((char)local_18 == '\x01')) {
              iVar4 = (**(code **)(*param_3 + 0x14))();
              (**(code **)(*param_3 + 0x10))(iVar4 + 2);
              iVar4 = (**(code **)(*param_3 + 8))(&local_14,4);
              if (((iVar4 == 4) && (((char)local_14 == 'f' && ((char)((uint)local_14 >> 8) == 'L')))
                  ) && ((local_14._2_1_ == 'a' &&
                        ((((local_14._3_1_ == 'C' &&
                           (iVar4 = FUN_1001ec50(param_3,&local_1c,4), iVar4 == 4)) &&
                          ((local_1c & 0x7f) == 0)) &&
                         (((local_1c >> 0x18 | (local_1c & 0xff0000) >> 8 | (local_1c & 0xff00) << 8
                           ) == 0x22 && (iVar4 = FUN_100353e0(local_180), iVar4 != 0)))))))) {
                puVar1 = (uint *)(in_ECX + 0x30);
                uVar5 = *puVar1;
                *puVar1 = *puVar1 + 0x33;
                *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + (uint)(0xffffffcc < uVar5);
                *(undefined4 *)(in_ECX + 0x18) = local_174;
                *(undefined1 *)(in_ECX + 0x1c) = local_170;
                *(undefined1 *)(in_ECX + 0x1d) = local_16f;
                *(undefined4 *)(in_ECX + 0x20) = local_168;
                *(undefined2 *)(in_ECX + 0x28) = local_17e;
                *(undefined4 *)(in_ECX + 0x24) = local_164;
                *(uint *)(in_ECX + 0x1090) = *(uint *)(in_ECX + 0x30) - 0x4f;
                *(uint *)(in_ECX + 0x1094) =
                     *(int *)(in_ECX + 0x34) + -1 + (uint)(0x4e < *(uint *)(in_ECX + 0x30));
                puVar7 = &local_140;
                puVar9 = (undefined4 *)(in_ECX + 0x1098);
                for (iVar4 = 0x48; iVar4 != 0; iVar4 = iVar4 + -1) {
                  *puVar9 = *puVar7;
                  puVar7 = puVar7 + 1;
                  puVar9 = puVar9 + 1;
                }
                *(undefined4 *)(in_ECX + 0x1088) = local_130;
                *(undefined4 *)(in_ECX + 0x38) = 1;
                *(undefined4 *)(in_ECX + 0x3c) = 1;
                __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
                return;
              }
            }
            break;
          }
          iVar4 = (**(code **)(*param_3 + 0x14))();
          (**(code **)(*param_3 + 0x10))(iVar4 + 0x2e);
        }
        else {
          iVar4 = (**(code **)(*param_3 + 0x14))();
          (**(code **)(*param_3 + 0x10))(iVar4 + 0x32);
        }
      }
      else {
        iVar4 = (**(code **)(*param_3 + 0x14))();
        (**(code **)(*param_3 + 0x10))(iVar4 + uVar5);
      }
      puVar1 = (uint *)(in_ECX + 0x30);
      uVar2 = *puVar1;
      *puVar1 = *puVar1 + uVar5;
      *(int *)(in_ECX + 0x34) =
           *(int *)(in_ECX + 0x34) + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar2,uVar5);
      iVar4 = FUN_100359f0(&local_140,&local_18,&local_1c);
      if (iVar4 != 0) break;
      puVar1 = (uint *)(in_ECX + 0x30);
      uVar5 = *puVar1;
      *puVar1 = *puVar1 + local_18;
      *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + (uint)CARRY4(uVar5,local_18);
    }
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

