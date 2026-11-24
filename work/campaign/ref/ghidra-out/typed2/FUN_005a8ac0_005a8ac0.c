
void FUN_005a8ac0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int *in_ECX;
  int iVar2;
  int iVar3;
  int *local_10;
  uint local_c;
  
  local_c = DAT_0076700c ^ (uint)&local_10;
  local_10 = in_ECX;
  if ((param_1 < param_3) && (param_2 < param_4)) {
    if (param_1 < PTR_0077241c->cellX0) {
      param_1 = PTR_0077241c->cellX0;
    }
    if (param_2 < PTR_0077241c->cellY0) {
      param_2 = PTR_0077241c->cellY0;
    }
    if (PTR_0077241c->cellX1 < param_3) {
      param_3 = PTR_0077241c->cellX1;
    }
    if (PTR_0077241c->cellY1 < param_4) {
      param_4 = PTR_0077241c->cellY1;
    }
    local_10 = in_ECX + 0x17;
    FUN_006c2d00();
    iVar2 = 0;
    iVar3 = 0;
    while (iVar2 < local_10[1]) {
      iVar2 = iVar2 + 1;
      piVar1 = (int *)(*local_10 + iVar3);
      iVar3 = iVar3 + 0x10;
      if ((param_1 < piVar1[2]) &&
         (*piVar1 < param_3 && (param_2 < piVar1[3] && piVar1[1] < param_4))) {
        __security_check_cookie(local_c ^ (uint)&local_10);
        return;
      }
    }
  }
  __security_check_cookie(local_c ^ (uint)&local_10);
  return;
}

