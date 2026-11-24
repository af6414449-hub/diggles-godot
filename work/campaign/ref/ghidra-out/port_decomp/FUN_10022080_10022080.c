
void FUN_10022080(byte *param_1,int param_2,int *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined1 *in_ECX;
  uint uVar4;
  int iVar5;
  void *in_EDX;
  byte *pbVar6;
  undefined1 *puVar7;
  uint _Size;
  uint uVar8;
  int local_1c;
  undefined1 *local_18;
  uint local_14;
  uint local_10;
  void *local_c;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  param_2 = param_2 - (int)param_1;
  local_1c = 0;
  local_18 = in_ECX;
  local_c = in_EDX;
  do {
    if (param_1[param_2] == 0) break;
    _Size = (uint)param_1[param_2];
    if ((param_4 & 8) == 0) {
      uVar4 = (uint)*param_1;
      if (uVar4 == 0) {
        memset(local_18,0,_Size);
        memset(local_c,0,_Size);
      }
      else {
        if ((int)param_4 < 0) {
          local_10 = (1 << (*param_1 & 0x1f)) - 1;
        }
        else {
          local_10 = 0xffffffff;
        }
        if (_Size != 0) {
          puVar7 = local_18;
          local_14 = _Size;
          do {
            uVar8 = 0;
            uVar1 = param_3[1];
            pbVar6 = (byte *)(((int)uVar1 >> 3) + *param_3);
            param_3[1] = uVar1 + uVar4;
            if (param_3[2] < (int)(uVar1 + uVar4)) {
              uVar8 = 0;
            }
            else {
              uVar2 = 0xff >> (sbyte)(uVar1 & 7) & (uint)*pbVar6;
              for (iVar5 = (uVar4 - 8) + (uVar1 & 7); 0 < iVar5; iVar5 = iVar5 + -8) {
                pbVar6 = pbVar6 + 1;
                uVar8 = uVar8 | uVar2 << ((byte)iVar5 & 0x1f);
                uVar2 = (uint)*pbVar6;
              }
              uVar8 = uVar2 >> (-(byte)iVar5 & 0x1f) | uVar8;
            }
            uVar3 = (char)uVar8;
            if (uVar8 == local_10) {
              uVar3 = 0xff;
            }
            puVar7[(int)local_c - (int)local_18] = uVar3;
            *puVar7 = (char)uVar8;
            puVar7 = puVar7 + 1;
            local_14 = local_14 - 1;
          } while (local_14 != 0);
        }
      }
    }
    else {
      memcpy(local_18,local_c,_Size);
    }
    local_c = (void *)((int)local_c + _Size);
    local_18 = local_18 + _Size;
    param_4 = param_4 * 2;
    local_1c = local_1c + 1;
    param_1 = param_1 + 1;
  } while (local_1c < 4);
  *(undefined2 *)(local_18 + 1) = 0;
  *local_18 = 0;
  return;
}

