
int FUN_00581b40(void)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  FILE *_File;
  int *piVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  bool bVar8;
  int *local_20;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070630d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x44) != -2) {
    iVar4 = FUN_0058a820(DAT_0076700c ^ (uint)&stack0xfffffffc);
    if (*(int *)(in_ECX + 0x44) == -1) {
      FUN_004402c0();
      local_8 = 0;
      _File = _fopen((char *)(local_20 + 3),"rb");
      if (_File == (FILE *)0x0) {
        *(undefined4 *)(in_ECX + 0x44) = 0xfffffffe;
        local_8 = 1;
        if (local_20 == (int *)0x0) {
          ExceptionList = local_10;
          return 0;
        }
        *local_20 = *local_20 + -1;
        if (*local_20 != 0) {
          ExceptionList = local_10;
          return 0;
        }
        FUN_006ba940();
        ExceptionList = local_10;
        return 0;
      }
      _fclose(_File);
      uVar7 = 0;
      if (0 < *(int *)(iVar4 + 0x1c)) {
        bVar8 = *(int *)(iVar4 + 0x1c) != 0;
        local_18 = 0;
        do {
          if (!bVar8) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          cVar3 = FUN_006b97f0(*(int *)(iVar4 + 0x18) + local_18);
          if (cVar3 != '\0') {
            if (uVar7 != 0xffffffff) goto LAB_00581cab;
            break;
          }
          local_18 = local_18 + 0x10;
          uVar7 = uVar7 + 1;
          bVar8 = uVar7 < *(uint *)(iVar4 + 0x1c);
        } while ((int)uVar7 < (int)*(uint *)(iVar4 + 0x1c));
      }
      FUN_0058ff10(1);
      uVar7 = *(uint *)(iVar4 + 0x1c) - 1;
      if (*(uint *)(iVar4 + 0x1c) <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar5 = (int *)(uVar7 * 0x10 + *(int *)(iVar4 + 0x18));
      FUN_00599fc0();
      *(bool *)(piVar5 + 3) = 0 < piVar5[2];
      piVar1 = (int *)*piVar5;
      piVar2 = *(int **)(in_ECX + 4);
      *piVar5 = (int)piVar2;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
        FUN_006ba940();
      }
      *(undefined4 *)(*piVar5 + 8) = *(undefined4 *)(*(int *)(in_ECX + 4) + 8);
LAB_00581cab:
      *(uint *)(in_ECX + 0x44) = uVar7;
      local_8 = 2;
      if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
        FUN_006ba940();
      }
    }
    uVar7 = *(uint *)(in_ECX + 0x44);
    if (*(uint *)(iVar4 + 0x1c) <= uVar7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar6 = *(int *)(iVar4 + 0x18);
    if (*(char *)(iVar6 + 0xc + uVar7 * 0x10) != '\0') {
      uVar7 = *(uint *)(in_ECX + 0x44);
      if (*(uint *)(iVar4 + 0x1c) <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = *(int *)(iVar4 + 0x18);
      }
      ExceptionList = local_10;
      return iVar6 + 4 + uVar7 * 0x10;
    }
  }
  ExceptionList = local_10;
  return 0;
}

