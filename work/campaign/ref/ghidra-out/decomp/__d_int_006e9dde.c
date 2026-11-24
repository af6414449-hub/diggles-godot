
/* Library Function - Single Match
    __d_int
   
   Library: Visual Studio 2019 Release */

int __d_int(ushort *param_1,short param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  uVar2 = param_1[3];
  uVar1 = uVar2 >> 4 & 0x7ff;
  if (uVar1 == 0x7ff) {
    if (((((uVar2 & 0xf) == 0) && (param_1[2] == 0)) && (param_1[1] == 0)) && (*param_1 == 0)) {
      return 1;
    }
    return 2;
  }
  if (((((uVar2 & 0x7fff) == 0) && (param_1[2] == 0)) && ((param_1[1] == 0 && (*param_1 == 0)))) ||
     (param_2 = (0x433 - uVar1) - param_2, param_2 < 1)) {
    return 0;
  }
  if (0x34 < param_2) {
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    param_1[3] = uVar2 & 0x8000;
    return -1;
  }
  iVar3 = (int)param_2 >> 4;
  uVar2 = *(ushort *)(&DAT_007189b4 + ((int)param_2 & 0xfU) * 2) &
          param_1[*(int *)(&DAT_007189d4 + iVar3 * 4)];
  param_1[*(int *)(&DAT_007189d4 + iVar3 * 4)] =
       param_1[*(int *)(&DAT_007189d4 + iVar3 * 4)] ^ uVar2;
  if (iVar3 != 1) {
    if (iVar3 != 2) {
      if (iVar3 != 3) goto LAB_006e9ed6;
      uVar2 = uVar2 | param_1[2];
      param_1[2] = 0;
    }
    uVar2 = uVar2 | param_1[1];
    param_1[1] = 0;
  }
  uVar2 = uVar2 | *param_1;
  *param_1 = 0;
LAB_006e9ed6:
  return (uVar2 == 0) - 1;
}

