
void FUN_005fd060(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int *piVar6;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00709d35;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((((PTR_0077241c->cellX0 + 8 <= param_1) && (param_1 < PTR_0077241c->cellX1 + -8)) &&
      (PTR_0077241c->cellY0 + 8 <= param_2)) && (param_2 < PTR_0077241c->cellY1 + -8)) {
    if ((*(char *)(in_ECX + 0xa0) != '\0') &&
       (uVar1 = *(uint *)(in_ECX + 0x78), uVar1 != 0xffffffff)) {
      piVar6 = (int *)(DAT_0077244c + 0x488);
      if (uVar1 < 0x2000) {
        piVar6 = piVar6 + uVar1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_1c = *piVar6;
      if (local_1c != 0) {
        FUN_006b8f50(uVar2);
        local_8 = 0;
        FUN_006b9040(&local_18,"%s dig shut -1",*(int *)(in_ECX + 0x74) + 0xc);
        if (local_18 + 3 == (int *)0x0) {
          piVar6 = (int *)0x0;
        }
        else {
          piVar6 = (int *)Tcl_NewStringObj(local_18 + 3,0xffffffff);
          *piVar6 = *piVar6 + 1;
        }
        local_8 = CONCAT31(local_8._1_3_,1);
        local_14 = piVar6;
        FUN_00555a00(&local_14);
        if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
          TclFreeObj(piVar6);
        }
        local_8 = 2;
        if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
          FUN_006ba940();
        }
      }
    }
    iVar3 = *(int *)(DAT_00772400 + 100);
    *(undefined4 *)(in_ECX + 0x8c) = 0;
    *(undefined4 *)(in_ECX + 0x90) = 0;
    *(undefined4 *)(in_ECX + 0x88) = 0;
    *(undefined1 *)(in_ECX + 0x94) = 0;
    iVar5 = (int)((param_2 >> 0x1f & 3U) + param_2) >> 2;
    local_14 = (int *)((int)(param_1 + (param_1 >> 0x1f & 3U)) >> 2);
    FUN_005fa510(local_14,iVar5,1,1);
    local_18 = (int *)(iVar3 * 4);
    iVar3 = FUN_00592f10(PTR_0077241c);
    uVar2 = *(uint *)(iVar3 + 8) >> ((byte)local_18 & 0x1f);
    if (((uVar2 & 8) == 0) && ((uVar2 & 0xf) != 0)) {
      iVar3 = FUN_005fa5d0((int)local_14 + 1,iVar5);
      if (iVar3 != 1) {
        iVar3 = param_1 + 4;
        iVar4 = FUN_00592f10(PTR_0077241c);
        uVar2 = *(uint *)(iVar4 + 8) >> ((byte)local_18 & 0x1f);
        if (((uVar2 & 8) == 0) && ((uVar2 & 0xf) != 0)) {
          iVar5 = FUN_005fa5d0((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2,iVar5);
          if (iVar5 == 1) {
            ExceptionList = local_10;
            return;
          }
          *(int *)(in_ECX + 0x98) = *(int *)(in_ECX + 0x98) + 2;
          if (*(int *)(in_ECX + 0x98) <= *(int *)(in_ECX + 0x9c)) {
            ExceptionList = local_10;
            return;
          }
          *(int *)(in_ECX + 0x8c) = iVar3;
          *(int *)(in_ECX + 0x90) = param_2;
          *(undefined4 *)(in_ECX + 0x88) = 8;
          *(undefined1 *)(in_ECX + 0x94) = 0;
          ExceptionList = local_10;
          return;
        }
      }
      iVar3 = FUN_005fa5d0(local_14,iVar5 + 1);
      if (iVar3 != 1) {
        iVar3 = param_2 + 4;
        iVar4 = FUN_00592f10(PTR_0077241c);
        uVar2 = *(uint *)(iVar4 + 8) >> ((byte)local_18 & 0x1f);
        if (((uVar2 & 8) == 0) && ((uVar2 & 0xf) != 0)) {
          iVar5 = FUN_005fa5d0(local_14,(int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2);
          if (iVar5 == 1) {
            ExceptionList = local_10;
            return;
          }
          *(int *)(in_ECX + 0x98) = *(int *)(in_ECX + 0x98) + 4;
          if (*(int *)(in_ECX + 0x98) <= *(int *)(in_ECX + 0x9c)) {
            ExceptionList = local_10;
            return;
          }
          *(int *)(in_ECX + 0x8c) = param_1;
          *(int *)(in_ECX + 0x90) = iVar3;
          *(undefined4 *)(in_ECX + 0x88) = 2;
          *(undefined1 *)(in_ECX + 0x94) = 0;
          ExceptionList = local_10;
          return;
        }
      }
      iVar3 = FUN_005fa5d0((int)local_14 + -1,iVar5);
      if (iVar3 != 1) {
        iVar3 = param_1 + -4;
        iVar4 = FUN_00592f10(PTR_0077241c);
        uVar2 = *(uint *)(iVar4 + 8) >> ((byte)local_18 & 0x1f);
        if (((uVar2 & 8) == 0) && ((uVar2 & 0xf) != 0)) {
          iVar5 = FUN_005fa5d0((int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2,iVar5);
          if (iVar5 == 1) {
            ExceptionList = local_10;
            return;
          }
          *(int *)(in_ECX + 0x98) = *(int *)(in_ECX + 0x98) + 2;
          if (*(int *)(in_ECX + 0x98) <= *(int *)(in_ECX + 0x9c)) {
            ExceptionList = local_10;
            return;
          }
          *(int *)(in_ECX + 0x8c) = iVar3;
          *(int *)(in_ECX + 0x90) = param_2;
          *(undefined4 *)(in_ECX + 0x88) = 4;
          *(undefined1 *)(in_ECX + 0x94) = 0;
          ExceptionList = local_10;
          return;
        }
      }
      iVar3 = FUN_005fa5d0(local_14,iVar5 + -1);
      if (iVar3 != 1) {
        iVar3 = FUN_00592f10(PTR_0077241c);
        uVar2 = *(uint *)(iVar3 + 8) >> ((byte)local_18 & 0x1f);
        if (((uVar2 & 8) == 0) && ((uVar2 & 0xf) != 0)) {
          local_20 = param_1;
          local_1c = param_2 + -4;
          FUN_005fcfb0(1,&local_20);
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}

