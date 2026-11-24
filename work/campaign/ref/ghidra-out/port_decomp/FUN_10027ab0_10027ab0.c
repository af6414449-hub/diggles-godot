
undefined4 FUN_10027ab0(int param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  size_t sVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  void *pvVar8;
  undefined4 uVar9;
  int in_ECX;
  size_t sVar10;
  undefined4 in_EDX;
  uint uVar11;
  size_t sVar12;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  if ((*(byte *)(in_ECX + 0x52b4) & 1) != 0) {
    return 0;
  }
  sVar10 = *(uint *)(in_ECX + 0x52a8);
  while( true ) {
    if (sVar10 < 0x4000) {
      uVar11 = *(uint *)(in_ECX + 0x52ac);
      if (uVar11 < 0x4000) {
        pvVar8 = *(void **)(in_ECX + 0x52b0);
        puVar1 = (undefined4 *)(in_ECX + 0x1a34);
        if (puVar1 == (undefined4 *)0x0) {
          return 0;
        }
        if (*(code **)(in_ECX + 0x1a3c) == (code *)0x0) {
          if (*(code **)(in_ECX + 0x1a38) == (code *)0x0) {
            return 0;
          }
          if (*(int *)(in_ECX + 0x1a40) == 0) {
            return 0;
          }
          pvVar5 = (void *)(**(code **)(in_ECX + 0x1a38))(0x4000,*puVar1);
          if (pvVar5 == (void *)0x0) {
            return 0;
          }
          if (pvVar8 != (void *)0x0) {
            memcpy(pvVar5,pvVar8,uVar11);
            (**(code **)(in_ECX + 0x1a40))(pvVar8,*puVar1);
          }
        }
        else {
          pvVar5 = (void *)(**(code **)(in_ECX + 0x1a3c))(pvVar8,0x4000,*puVar1);
          if (pvVar5 == (void *)0x0) {
            return 0;
          }
        }
        sVar10 = *(uint *)(in_ECX + 0x52a8);
        uVar11 = 0x4000;
        *(void **)(in_ECX + 0x52b0) = pvVar5;
        *(undefined4 *)(in_ECX + 0x52ac) = 0x4000;
      }
      uVar6 = (**(code **)(in_ECX + 0x1a28))
                        (*(undefined4 *)(in_ECX + 0x1a30),*(int *)(in_ECX + 0x52b0) + sVar10,
                         uVar11 - sVar10);
      puVar2 = (uint *)(in_ECX + 0x3e60);
      uVar11 = *puVar2;
      *puVar2 = *puVar2 + uVar6;
      *(int *)(in_ECX + 0x3e64) = *(int *)(in_ECX + 0x3e64) + (uint)CARRY4(uVar11,uVar6);
      if ((uVar6 == 0) && (*(int *)(in_ECX + 0x52a8) == 0)) goto LAB_10027de3;
      *(int *)(in_ECX + 0x52a8) = *(int *)(in_ECX + 0x52a8) + uVar6;
      sVar10 = *(uint *)(in_ECX + 0x52a8);
    }
    if (0x7fffffff < sVar10) goto LAB_10027de3;
    iVar7 = FUN_10026a60(sVar10,in_EDX,&iStack_1c);
    iVar4 = iStack_1c;
    sVar10 = *(size_t *)(in_ECX + 0x52a8);
    sVar12 = sVar10 - iStack_1c;
    if (0 < iStack_1c) {
      memmove(*(void **)(in_ECX + 0x52b0),(void *)((int)*(void **)(in_ECX + 0x52b0) + iStack_1c),
              sVar12);
      *(size_t *)(in_ECX + 0x52a8) = sVar12;
      sVar10 = sVar12;
    }
    if ((iVar7 != 0) || ((0 < iVar4 && (param_1 != 0)))) break;
    if (iVar4 == 0) {
      sVar12 = *(size_t *)(in_ECX + 0x52ac);
      if (sVar12 == sVar10) {
        puVar1 = (undefined4 *)(in_ECX + 0x1a34);
        sVar3 = sVar12 + 0x4000;
        pvVar5 = *(void **)(in_ECX + 0x52b0);
        if (puVar1 == (undefined4 *)0x0) {
          return 0;
        }
        if (*(code **)(in_ECX + 0x1a3c) == (code *)0x0) {
          if (*(code **)(in_ECX + 0x1a38) == (code *)0x0) {
            return 0;
          }
          if (*(int *)(in_ECX + 0x1a40) == 0) {
            return 0;
          }
          pvVar8 = (void *)(**(code **)(in_ECX + 0x1a38))(sVar3,*puVar1);
          if (pvVar8 == (void *)0x0) {
            return 0;
          }
          if (pvVar5 != (void *)0x0) {
            memcpy(pvVar8,pvVar5,sVar12);
            (**(code **)(in_ECX + 0x1a40))(pvVar5,*puVar1);
          }
        }
        else {
          pvVar8 = (void *)(**(code **)(in_ECX + 0x1a3c))(pvVar5,sVar3,*puVar1);
          if (pvVar8 == (void *)0x0) {
            return 0;
          }
        }
        sVar10 = *(size_t *)(in_ECX + 0x52a8);
        *(void **)(in_ECX + 0x52b0) = pvVar8;
        *(size_t *)(in_ECX + 0x52ac) = sVar3;
        sVar12 = sVar3;
      }
      else {
        pvVar8 = *(void **)(in_ECX + 0x52b0);
      }
      uVar6 = (**(code **)(in_ECX + 0x1a28))
                        (*(undefined4 *)(in_ECX + 0x1a30),sVar10 + (int)pvVar8,sVar12 - sVar10);
      puVar2 = (uint *)(in_ECX + 0x3e60);
      uVar11 = *puVar2;
      *puVar2 = *puVar2 + uVar6;
      *(int *)(in_ECX + 0x3e64) = *(int *)(in_ECX + 0x3e64) + (uint)CARRY4(uVar11,uVar6);
      if (uVar6 == 0) {
LAB_10027de3:
        *(uint *)(in_ECX + 0x52b4) = *(uint *)(in_ECX + 0x52b4) | 1;
        return 0;
      }
      *(int *)(in_ECX + 0x52a8) = *(int *)(in_ECX + 0x52a8) + uVar6;
      sVar10 = *(uint *)(in_ECX + 0x52a8);
    }
  }
  uVar9 = FUN_100215f0();
  *(undefined4 *)(in_ECX + 0x1a4c) = 0;
  *(undefined4 *)(in_ECX + 0x1a50) = uVar9;
  *(undefined4 *)(in_ECX + 0x1a44) = uStack_18;
  *(undefined4 *)(in_ECX + 0x1a48) = uStack_14;
  if (*(int *)(in_ECX + 0x1a20) == 0) {
    *(undefined4 *)(in_ECX + 0x1a20) = uStack_18;
    if (*(int *)(in_ECX + 0x1a24) == 0) goto LAB_10027db7;
  }
  else {
    if (*(int *)(in_ECX + 0x1a24) != 0) goto LAB_10027dc4;
LAB_10027db7:
    *(undefined4 *)(in_ECX + 0x1a24) = uStack_14;
  }
  FUN_100279d0();
LAB_10027dc4:
  if (((int *)(in_ECX + 0x3e68) != (int *)0x0) && (*(int *)(in_ECX + 0x1a48) != 0)) {
    *(int *)(in_ECX + 0x3e68) = *(int *)(in_ECX + 0x1a48);
  }
  return uVar9;
}

