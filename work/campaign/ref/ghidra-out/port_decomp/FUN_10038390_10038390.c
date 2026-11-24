
void FUN_10038390(int param_1)

{
  int *piVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  size_t _NumOfElements;
  int in_ECX;
  int in_EDX;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_10;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar8 = 0;
  if (*(char *)(in_ECX + 0x17) == '\0') {
    if (0 < *(int *)(in_ECX + 4)) {
      iVar7 = 0;
      do {
        if ((*(char *)(in_ECX + 0x17) != '\0') ||
           ((*(byte *)(iVar8 + in_EDX) != 0xff && (10 < *(byte *)(iVar8 + in_EDX))))) {
          uVar4 = FUN_10038000();
          *(undefined4 *)(iVar7 + *(int *)(in_ECX + 0x824)) = uVar4;
          iVar7 = iVar7 + 4;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(in_ECX + 4));
    }
    _NumOfElements = *(size_t *)(in_ECX + 0x82c);
  }
  else {
    _NumOfElements = *(size_t *)(in_ECX + 0x82c);
    if (0 < (int)_NumOfElements) {
      do {
        uVar4 = FUN_10038000();
        *(undefined4 *)(*(int *)(in_ECX + 0x824) + iVar8 * 4) = uVar4;
        iVar8 = iVar8 + 1;
        _NumOfElements = *(size_t *)(in_ECX + 0x82c);
      } while (iVar8 < (int)_NumOfElements);
    }
  }
  qsort(*(void **)(in_ECX + 0x824),_NumOfElements,4,FUN_10038360);
  *(undefined4 *)(*(int *)(in_ECX + 0x824) + *(int *)(in_ECX + 0x82c) * 4) = 0xffffffff;
  if (*(char *)(in_ECX + 0x17) == '\0') {
    iVar8 = *(int *)(in_ECX + 4);
  }
  else {
    iVar8 = *(int *)(in_ECX + 0x82c);
  }
  local_10 = 0;
  if (0 < iVar8) {
    do {
      if (*(char *)(in_ECX + 0x17) == '\0') {
        bVar2 = *(byte *)(in_EDX + local_10);
        if ((bVar2 != 0xff) && (10 < bVar2)) goto LAB_1003849d;
      }
      else {
        bVar2 = *(byte *)(in_EDX + *(int *)(param_1 + local_10 * 4));
LAB_1003849d:
        uVar9 = *(uint *)(in_ECX + 0x82c);
        uVar5 = *(uint *)(local_10 * 4 + *(int *)(in_ECX + 0x20));
        uVar5 = (uVar5 >> 1 ^ uVar5 * 2) & 0x55555555 ^ uVar5 * 2;
        uVar5 = (uVar5 >> 2 ^ uVar5 * 4) & 0x33333333 ^ uVar5 * 4;
        uVar5 = (uVar5 >> 4 ^ uVar5 << 4) & 0xf0f0f0f ^ uVar5 << 4;
        uVar5 = (uVar5 >> 8 ^ uVar5 << 8) & 0xff00ff ^ uVar5 << 8;
        uVar5 = uVar5 << 0x10 | uVar5 >> 0x10;
        iVar7 = 0;
        if (1 < (int)uVar9) {
          iVar7 = 0;
          do {
            uVar6 = uVar9 >> 1;
            uVar3 = *(uint *)(*(int *)(in_ECX + 0x824) + (uVar6 + iVar7) * 4);
            if (uVar3 <= uVar5) {
              iVar7 = uVar6 + iVar7;
            }
            uVar9 = uVar9 - uVar6;
            if (uVar5 < uVar3) {
              uVar9 = uVar6;
            }
          } while (1 < (int)uVar9);
        }
        piVar1 = (int *)(*(int *)(in_ECX + 0x828) + iVar7 * 4);
        if (*(char *)(in_ECX + 0x17) == '\0') {
          *piVar1 = local_10;
        }
        else {
          *piVar1 = *(int *)(local_10 * 4 + param_1);
          *(byte *)(iVar7 + *(int *)(in_ECX + 8)) = bVar2;
        }
      }
      local_10 = local_10 + 1;
    } while (local_10 < iVar8);
  }
  return;
}

