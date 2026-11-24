
int FUN_1003c7b0(int param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  undefined4 *puVar6;
  int in_ECX;
  float *pfVar7;
  int iVar8;
  int in_EDX;
  float *pfVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  undefined4 *puVar13;
  int local_14;
  int local_c;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  local_c = *(int *)(in_ECX + 0x3ec);
  if (local_c != 0) {
    if (local_c * 2 == *(int *)(in_ECX + 0x7c)) {
      pfVar4 = *(float **)(in_ECX + 0x450);
    }
    else {
      if (local_c * 2 != *(int *)(in_ECX + 0x80)) {
        return 0;
      }
      pfVar4 = *(float **)(in_ECX + 0x454);
    }
    if (pfVar4 == (float *)0x0) {
      return 0;
    }
    local_14 = 0;
    if (0 < *(int *)(in_ECX + 4)) {
      piVar11 = (int *)(in_ECX + 0x32c);
      do {
        if (0 < local_c) {
          iVar8 = piVar11[0x20];
          pfVar5 = (float *)(*piVar11 + param_1 * 4);
          pfVar9 = pfVar4 + local_c + -1;
          pfVar7 = pfVar4;
          iVar12 = local_c;
          do {
            pfVar1 = (float *)((iVar8 - (int)pfVar4) + (int)pfVar7);
            fVar2 = *pfVar9;
            pfVar9 = pfVar9 + -1;
            fVar3 = *pfVar7;
            pfVar7 = pfVar7 + 1;
            *pfVar5 = *pfVar1 * fVar2 + *pfVar5 * fVar3;
            pfVar5 = pfVar5 + 1;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        local_14 = local_14 + 1;
        piVar11 = piVar11 + 1;
      } while (local_14 < *(int *)(in_ECX + 4));
      local_c = *(int *)(in_ECX + 0x3ec);
    }
  }
  *(int *)(in_ECX + 0x3ec) = in_EDX - param_2;
  local_14 = 0;
  if (0 < *(int *)(in_ECX + 4)) {
    puVar6 = (undefined4 *)(in_ECX + 0x3ac);
    do {
      if (param_2 < in_EDX) {
        puVar13 = (undefined4 *)(puVar6[-0x20] + param_2 * 4);
        iVar8 = param_2;
        puVar10 = (undefined4 *)*puVar6;
        do {
          iVar8 = iVar8 + 1;
          *puVar10 = *puVar13;
          puVar13 = puVar13 + 1;
          puVar10 = puVar10 + 1;
        } while (iVar8 < in_EDX);
      }
      local_14 = local_14 + 1;
      puVar6 = puVar6 + 1;
    } while (local_14 < *(int *)(in_ECX + 4));
  }
  if (local_c == 0) {
    return 0;
  }
  if (param_2 <= in_EDX) {
    in_EDX = param_2;
  }
  *(int *)(in_ECX + 0x594) = *(int *)(in_ECX + 0x594) + (in_EDX - param_1);
  return in_EDX - param_1;
}

