
void FUN_0049bb70(char param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint extraout_EDX;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  int local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fe5dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar3 = param_2 + -1;
  if (param_2 + -1 < PTR_0077241c->cellX0) {
    iVar3 = PTR_0077241c->cellX0;
  }
  iVar9 = param_3 + -1;
  if (param_3 + -1 < PTR_0077241c->cellY0) {
    iVar9 = PTR_0077241c->cellY0;
  }
  iVar7 = param_4 + 1;
  if (PTR_0077241c->cellX1 < param_4 + 1) {
    iVar7 = PTR_0077241c->cellX1;
  }
  iVar6 = param_5 + 1;
  if (PTR_0077241c->cellY1 < param_5 + 1) {
    iVar6 = PTR_0077241c->cellY1;
  }
  FUN_0040ba00(DAT_0076700c ^ (uint)&stack0xfffffffc);
  iVar2 = local_1c;
  local_8 = 0;
  local_18 = extraout_EDX;
  do {
    do {
      do {
        do {
          do {
            local_18 = local_18 + 1;
            if ((int)*(uint *)(iVar2 + 0xa51) <= (int)local_18) {
              if (0 < (int)local_20) {
                uVar8 = 0;
                bVar10 = local_20 != 0;
                do {
                  if (!bVar10) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  FUN_004957e0(*(undefined4 *)(local_24 + uVar8 * 4));
                  uVar8 = uVar8 + 1;
                  bVar10 = uVar8 < local_20;
                } while ((int)uVar8 < (int)local_20);
              }
              local_8 = 1;
              if ((int)local_20 < 0) {
                FUN_0040b930(-local_20);
              }
              if (local_24 != 0) {
                FUN_006ba940();
              }
              ExceptionList = local_10;
              return;
            }
            if (*(uint *)(iVar2 + 0xa51) <= local_18) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar1 = *(int *)(*(int *)(iVar2 + 0xa4d) + local_18 * 4);
            local_1c = iVar1;
            if ((iVar1 < 0) || (*(int *)(iVar2 + 0x8b8) <= iVar1)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar5 = *(int *)(iVar2 + 0x8b4);
              iVar4 = iVar5;
            }
            else {
              iVar5 = *(int *)(iVar2 + 0x8b4);
              iVar4 = iVar1 * 0x88 + iVar5;
            }
          } while (*(float *)(iVar4 + 0xc) < (float)iVar3);
          if ((iVar1 < 0) || (*(int *)(iVar2 + 0x8b8) <= iVar1)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar5 = *(int *)(iVar2 + 0x8b4);
            iVar4 = iVar5;
          }
          else {
            iVar4 = iVar1 * 0x88 + iVar5;
          }
        } while ((float)iVar7 < *(float *)(iVar4 + 0xc));
        if ((iVar1 < 0) || (*(int *)(iVar2 + 0x8b8) <= iVar1)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar5 = *(int *)(iVar2 + 0x8b4);
          iVar4 = iVar5;
        }
        else {
          iVar4 = iVar1 * 0x88 + iVar5;
        }
      } while (*(float *)(iVar4 + 0x10) < (float)iVar9);
      if ((iVar1 < 0) || (*(int *)(iVar2 + 0x8b8) <= iVar1)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar5 = *(int *)(iVar2 + 0x8b4);
        iVar4 = iVar5;
      }
      else {
        iVar4 = iVar1 * 0x88 + iVar5;
      }
    } while ((float)iVar6 < *(float *)(iVar4 + 0x10));
    if (param_1 == '\0') goto LAB_0049bdac;
    if ((iVar1 < 0) || (*(int *)(iVar2 + 0x8b8) <= iVar1)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar5 = *(int *)(iVar2 + 0x8b4);
      iVar4 = iVar5;
    }
    else {
      iVar4 = iVar1 * 0x88 + iVar5;
    }
    if ((*(byte *)(iVar4 + 0x80) & 2) != 0) goto LAB_0049bdac;
    if ((iVar1 < 0) || (*(int *)(iVar2 + 0x8b8) <= iVar1)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar5 = *(int *)(iVar2 + 0x8b4);
    }
    else {
      iVar5 = iVar1 * 0x88 + iVar5;
    }
    if (*(int *)(iVar5 + 8) == 9) {
LAB_0049bdac:
      FUN_00491db0(&local_1c);
    }
  } while( true );
}

