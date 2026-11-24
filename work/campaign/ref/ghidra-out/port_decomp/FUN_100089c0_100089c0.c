
void FUN_100089c0(undefined4 *param_1,code *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  char cVar12;
  undefined4 *in_ECX;
  undefined4 *in_EDX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b7c);
  cVar12 = (*param_2)();
  if (cVar12 != '\0') {
    uVar1 = in_ECX[1];
    uVar2 = in_ECX[2];
    uVar3 = in_ECX[3];
    uVar4 = *in_EDX;
    uVar5 = in_EDX[1];
    uVar6 = in_EDX[2];
    uVar7 = in_EDX[3];
    uVar8 = in_EDX[4];
    uVar9 = in_EDX[5];
    uVar10 = in_EDX[6];
    uVar11 = in_EDX[7];
    *in_EDX = *in_ECX;
    in_EDX[1] = uVar1;
    in_EDX[2] = uVar2;
    in_EDX[3] = uVar3;
    uVar1 = in_ECX[5];
    uVar2 = in_ECX[6];
    uVar3 = in_ECX[7];
    in_EDX[4] = in_ECX[4];
    in_EDX[5] = uVar1;
    in_EDX[6] = uVar2;
    in_EDX[7] = uVar3;
    *in_ECX = uVar4;
    in_ECX[1] = uVar5;
    in_ECX[2] = uVar6;
    in_ECX[3] = uVar7;
    in_ECX[4] = uVar8;
    in_ECX[5] = uVar9;
    in_ECX[6] = uVar10;
    in_ECX[7] = uVar11;
  }
  cVar12 = (*param_2)(param_1);
  if (cVar12 != '\0') {
    uVar1 = in_EDX[1];
    uVar2 = in_EDX[2];
    uVar3 = in_EDX[3];
    uVar4 = *param_1;
    uVar5 = param_1[1];
    uVar6 = param_1[2];
    uVar7 = param_1[3];
    uVar8 = param_1[4];
    uVar9 = param_1[5];
    uVar10 = param_1[6];
    uVar11 = param_1[7];
    *param_1 = *in_EDX;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
    param_1[3] = uVar3;
    uVar1 = in_EDX[5];
    uVar2 = in_EDX[6];
    uVar3 = in_EDX[7];
    param_1[4] = in_EDX[4];
    param_1[5] = uVar1;
    param_1[6] = uVar2;
    param_1[7] = uVar3;
    *in_EDX = uVar4;
    in_EDX[1] = uVar5;
    in_EDX[2] = uVar6;
    in_EDX[3] = uVar7;
    in_EDX[4] = uVar8;
    in_EDX[5] = uVar9;
    in_EDX[6] = uVar10;
    in_EDX[7] = uVar11;
    cVar12 = (*param_2)();
    if (cVar12 != '\0') {
      uVar1 = in_ECX[1];
      uVar2 = in_ECX[2];
      uVar3 = in_ECX[3];
      uVar4 = *in_EDX;
      uVar5 = in_EDX[1];
      uVar6 = in_EDX[2];
      uVar7 = in_EDX[3];
      uVar8 = in_EDX[4];
      uVar9 = in_EDX[5];
      uVar10 = in_EDX[6];
      uVar11 = in_EDX[7];
      *in_EDX = *in_ECX;
      in_EDX[1] = uVar1;
      in_EDX[2] = uVar2;
      in_EDX[3] = uVar3;
      uVar1 = in_ECX[5];
      uVar2 = in_ECX[6];
      uVar3 = in_ECX[7];
      in_EDX[4] = in_ECX[4];
      in_EDX[5] = uVar1;
      in_EDX[6] = uVar2;
      in_EDX[7] = uVar3;
      *in_ECX = uVar4;
      in_ECX[1] = uVar5;
      in_ECX[2] = uVar6;
      in_ECX[3] = uVar7;
      in_ECX[4] = uVar8;
      in_ECX[5] = uVar9;
      in_ECX[6] = uVar10;
      in_ECX[7] = uVar11;
    }
  }
  return;
}

