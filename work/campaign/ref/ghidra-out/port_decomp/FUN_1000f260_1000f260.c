
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000f260(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  piVar1 = (int *)in_ECX[0x32c];
  piVar3 = in_ECX + 0x32c;
  iVar6 = in_ECX[0x2f5];
  iVar7 = in_ECX[0x2ef];
  iVar2 = in_ECX[0x2ee];
  if (piVar1 != (int *)0x0) {
    *piVar3 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (((((iVar6 != 0) != DAT_1416e9d0) || (iVar2 != DAT_1416e9d4)) || (iVar7 != DAT_1416e9d8)) ||
     (DAT_1416e9ec != '\x0f')) {
    _DAT_1416e9e8 = 1;
    _DAT_1416e9dc = 1;
    DAT_1416e9ec = '\x0f';
    DAT_1416e9d0 = (uint)(iVar6 != 0);
    DAT_1416e9d4 = iVar2;
    DAT_1416e9d8 = iVar7;
    _DAT_1416e9e0 = iVar2;
    _DAT_1416e9e4 = iVar7;
    iVar6 = (**(code **)(**(int **)(*in_ECX + 4) + 0x50))
                      (*(int **)(*in_ECX + 4),&DAT_1416e9c8,piVar3);
    if (iVar6 == 0) {
      (**(code **)(**(int **)(*in_ECX + 8) + 0x8c))(*(int **)(*in_ECX + 8),*piVar3,0,0xffffffff);
    }
  }
  piVar1 = (int *)in_ECX[0x32d];
  piVar3 = in_ECX + 0x32d;
  iVar6 = in_ECX[0x2f0];
  if (piVar1 != (int *)0x0) {
    *piVar3 = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  if (((iVar6 != DAT_1416e994) || (DAT_1416e998 != 0)) ||
     ((DAT_1416e990 != 3 || (DAT_1416e9a8 != 0)))) {
    DAT_1416e998 = 0;
    DAT_1416e990 = 3;
    DAT_1416e9a8 = 0;
    _DAT_1416e9b0 = 1;
    DAT_1416e994 = iVar6;
    iVar6 = (**(code **)(**(int **)(*in_ECX + 4) + 0x58))
                      (*(int **)(*in_ECX + 4),&DAT_1416e990,piVar3);
    if (iVar6 == 0) {
      (**(code **)(**(int **)(*in_ECX + 8) + 0xac))(*(int **)(*in_ECX + 8),*piVar3);
    }
  }
  piVar3 = (int *)in_ECX[0x32b];
  iVar6 = in_ECX[0x30b];
  if (piVar3 != (int *)0x0) {
    in_ECX[0x32b] = 0;
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  iVar7 = in_ECX[0x30a];
  iVar2 = in_ECX[0x309];
  iVar4 = in_ECX[0x307];
  iVar5 = in_ECX[0x308];
  if ((((in_ECX[0x2e7] != DAT_1416e95c) || (in_ECX[0x2f1] != DAT_1416e964)) ||
      ((in_ECX[0x2eb] != DAT_1416e960 ||
       ((((in_ECX[0x306] != DAT_1416e968 || (iVar7 != DAT_1416e97c)) || (iVar2 != DAT_1416e978)) ||
        ((iVar4 != DAT_1416e970 || (iVar5 != DAT_1416e974)))))))) ||
     (((char)in_ECX[0x30c] != DAT_1416e96c || ((char)in_ECX[0x30d] != DAT_1416e96d)))) {
    DAT_1416e95c = (uint)(in_ECX[0x2e7] != 0);
    DAT_1416e960 = (uint)(in_ECX[0x2eb] != 0);
    DAT_1416e968 = (uint)(in_ECX[0x306] != 0);
    DAT_1416e964 = in_ECX[0x2f1];
    DAT_1416e96c = (char)in_ECX[0x30c];
    DAT_1416e96d = (char)in_ECX[0x30d];
    DAT_1416e970 = iVar4;
    DAT_1416e974 = iVar5;
    DAT_1416e978 = iVar2;
    DAT_1416e97c = iVar7;
    _DAT_1416e980 = iVar4;
    iRam1416e984 = iVar5;
    iRam1416e988 = iVar2;
    iRam1416e98c = iVar7;
    iVar7 = (**(code **)(**(int **)(*in_ECX + 4) + 0x54))
                      (*(int **)(*in_ECX + 4),&DAT_1416e95c,in_ECX + 0x32b);
    if (iVar7 == 0) {
      (**(code **)(**(int **)(*in_ECX + 8) + 0x90))
                (*(int **)(*in_ECX + 8),in_ECX[0x32b],(char)iVar6);
    }
  }
  return 0;
}

