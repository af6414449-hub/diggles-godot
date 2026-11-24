
uint FUN_100078b0(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  double dVar7;
  double dVar8;
  int local_30;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar6 = *(uint *)(in_ECX + 0x8c);
  uVar5 = 0;
  if (uVar6 == 0) {
    uVar5 = 0xffffffff;
  }
  else {
    piVar4 = *(int **)(in_ECX + 0x90);
    while (((piVar4[1] != param_2 || (uVar6 = *(uint *)(in_ECX + 0x8c), *piVar4 != param_1)) ||
           (uVar6 = *(uint *)(in_ECX + 0x8c),
           (*(uint *)(*(int *)(in_ECX + 0xd4) + uVar5 * 4) & param_3) == 0))) {
      uVar5 = uVar5 + 1;
      piVar4 = piVar4 + 7;
      if (uVar6 <= uVar5) {
        uVar6 = 0xffffffff;
        dVar8 = 999999999.0;
        uVar5 = 0;
        local_30 = 0;
        do {
          if (((*(uint *)(*(int *)(in_ECX + 0xd4) + uVar5 * 4) & param_3) != 0) &&
             ((piVar4 = (int *)(*(int *)(in_ECX + 0x90) + local_30), iVar1 = *piVar4,
              iVar2 = piVar4[1],
              dVar7 = ABS((double)param_1 -
                          ((double)iVar1 + *(double *)(&DAT_10047c80 + (iVar1 >> 0x1f) * -8))) *
                      10000.0 + ABS((double)param_2 -
                                    ((double)iVar2 +
                                    *(double *)(&DAT_10047c80 + (iVar2 >> 0x1f) * -8))),
              dVar7 < dVar8 || ((int)uVar6 < 0)))) {
            uVar3 = FUN_10041395(param_1,param_2);
            uVar3 = FUN_10041395(uVar3);
            FUN_100028b0(&DAT_1416ec40,0x40,"Closer : (%u x %u) for (%u x %u) \n",uVar3);
            OutputDebugStringA(&DAT_1416ec40);
            uVar6 = uVar5;
            dVar8 = dVar7;
          }
          local_30 = local_30 + 0x1c;
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(in_ECX + 0x8c));
        return uVar6;
      }
    }
  }
  return uVar5;
}

