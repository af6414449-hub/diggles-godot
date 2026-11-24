
void FUN_1001dce0(void)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  uint uVar5;
  undefined4 uVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  int *piVar11;
  uint local_84 [25];
  uint local_20;
  uint local_1c;
  int local_14;
  uint local_10;
  uint *local_c;
  int local_8;
  
  local_8 = in_ECX;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(undefined1 *)(in_ECX + 0x1cda8) = 0;
  uVar7 = 0;
  local_10 = 0;
  uVar9 = 0;
  if (*(int *)(in_ECX + 0x14) != 0) {
    local_c = (uint *)(in_ECX + 0x1bda4);
    puVar10 = (uint *)(in_ECX + 0x1bda0);
    piVar11 = (int *)(in_ECX + 0x40);
    do {
      if ((*piVar11 != 0) &&
         ((uVar5 = *(uint *)(*piVar11 + 0x10), (uVar5 & 0x24) == 0 || ((char)uVar5 < '\0')))) {
        puVar10[1] = uVar9;
        uVar7 = uVar7 + 1;
        puVar10 = puVar10 + 1;
        if ((*(byte *)(*piVar11 + 0x10) & 0x80) != 0) {
          local_10 = local_10 + 1;
          *puVar10 = *local_c;
          *local_c = uVar9;
          local_c = local_c + 1;
        }
      }
      uVar9 = uVar9 + 1;
      piVar11 = piVar11 + 1;
    } while (uVar9 < *(uint *)(in_ECX + 0x14));
  }
  local_20 = *(uint *)(in_ECX + 0x10);
  if (local_20 < uVar7) {
    *(uint *)(in_ECX + 0x1cda4) = local_20;
    if (local_20 <= local_10) {
      return;
    }
    puVar10 = (uint *)0x0;
    iVar2 = in_ECX + 0x1bda4 + local_10 * 4;
    uVar7 = uVar7 - local_10;
    local_10 = 0;
    while( true ) {
      uVar9 = uVar7;
      if ((int)(local_10 + 1) < (int)uVar9) {
        local_14 = local_10 - 1;
        local_1c = uVar9;
        local_c = puVar10;
        do {
          uVar7 = local_1c;
          if (local_c == (uint *)0x18) {
            uVar7 = local_84[0];
          }
          puVar10 = (uint *)0x0;
          if (local_c != (uint *)0x18) {
            puVar10 = local_c;
          }
          iVar8 = *(int *)(in_ECX + 0x40 + *(int *)(iVar2 + local_10 * 4) * 4);
          local_84[(int)puVar10] = uVar7;
          puVar10 = (uint *)((int)puVar10 + 1);
          local_c = puVar10;
          fVar4 = *(float *)(iVar8 + 0x3c);
          iVar8 = local_14;
          while( true ) {
            do {
              iVar3 = iVar8 * 4;
              iVar8 = iVar8 + 1;
            } while (fVar4 < *(float *)(*(int *)(in_ECX + 0x40 + *(int *)(iVar2 + 4 + iVar3) * 4) +
                                       0x3c));
            do {
              uVar9 = uVar7;
              iVar3 = *(int *)(iVar2 + -4 + uVar9 * 4);
              local_1c = uVar9;
              uVar7 = uVar9 - 1;
              pfVar1 = (float *)(*(int *)(local_8 + 0x40 + iVar3 * 4) + 0x3c);
            } while (*pfVar1 <= fVar4 && fVar4 != *pfVar1);
            uVar6 = *(undefined4 *)(iVar2 + iVar8 * 4);
            in_ECX = local_8;
            if ((int)uVar7 <= iVar8) break;
            *(int *)(iVar2 + iVar8 * 4) = iVar3;
            *(undefined4 *)(iVar2 + uVar7 * 4) = uVar6;
          }
        } while ((int)(local_10 + 1) < (int)uVar9);
      }
      if ((puVar10 == (uint *)0x0) || ((int)local_20 <= (int)local_10)) break;
      puVar10 = (uint *)((int)puVar10 + -1);
      uVar7 = local_84[(int)puVar10];
      local_10 = uVar9;
    }
  }
  else {
    *(uint *)(in_ECX + 0x1cda4) = uVar7;
  }
  FUN_1001da70();
  return;
}

