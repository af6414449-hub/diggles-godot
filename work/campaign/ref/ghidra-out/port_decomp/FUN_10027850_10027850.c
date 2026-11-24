
undefined8 FUN_10027850(int param_1,int param_2,int param_3,float *param_4,int param_5)

{
  int iVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  int local_1c;
  uint local_18;
  int local_c;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  local_c = param_3;
  if ((param_3 == 0) && (param_2 == 0)) {
    return 0;
  }
  local_1c = 0;
  local_18 = 0;
  do {
    if (*(int *)(param_5 + 0x1a50) != 0) {
      do {
        if ((local_c == 0) && (param_2 == 0)) break;
        iVar3 = *(int *)(param_5 + 0x1a20);
        if (*(int *)(param_5 + 0x1a44) == 1) {
          *param_4 = *(float *)(param_5 + 0x1a54 + *(int *)(param_5 + 0x1a4c) * 4);
          if (iVar3 != 1) {
            fVar2 = *(float *)(param_5 + 0x1a54 + *(int *)(param_5 + 0x1a4c) * 4);
LAB_10027942:
            param_4[1] = fVar2;
          }
        }
        else {
          iVar1 = *(int *)(param_5 + 0x1a4c) * *(int *)(param_5 + 0x1a44);
          fVar2 = *(float *)(param_5 + 0x1a54 + iVar1 * 4);
          if (iVar3 != 1) {
            *param_4 = fVar2;
            fVar2 = *(float *)(param_5 + 0x1a58 +
                              *(int *)(param_5 + 0x1a4c) * *(int *)(param_5 + 0x1a44) * 4);
            goto LAB_10027942;
          }
          *param_4 = (fVar2 + 0.0 + *(float *)(param_5 + 0x1a58 + iVar1 * 4)) * 0.5;
        }
        *(int *)(param_5 + 0x1a4c) = *(int *)(param_5 + 0x1a4c) + 1;
        *(int *)(param_5 + 0x1a50) = *(int *)(param_5 + 0x1a50) + -1;
        bVar4 = 0xfffffffe < local_18;
        local_18 = local_18 + 1;
        local_1c = local_1c + (uint)bVar4;
        bVar4 = param_2 != 0;
        param_2 = param_2 + -1;
        local_c = local_c + -1 + (uint)bVar4;
        param_4 = param_4 + *(int *)(param_1 + 8);
      } while (*(int *)(param_5 + 0x1a50) != 0);
      if (param_2 == 0 && local_c == 0) {
LAB_100279c2:
        return CONCAT44(local_1c,local_18);
      }
    }
    iVar3 = FUN_10027ab0(0);
    if ((iVar3 == 0) || ((local_c == 0 && (param_2 == 0)))) goto LAB_100279c2;
  } while( true );
}

