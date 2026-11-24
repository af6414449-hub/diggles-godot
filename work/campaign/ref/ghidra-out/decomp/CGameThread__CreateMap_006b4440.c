
/* WARNING: Removing unreachable block (ram,0x006b4798) */
/* WARNING: Removing unreachable block (ram,0x006b47a1) */
/* WARNING: Removing unreachable block (ram,0x006b47b6) */
/* WARNING: Removing unreachable block (ram,0x006b47d8) */
/* WARNING: Removing unreachable block (ram,0x006b47f3) */
/* WARNING: Removing unreachable block (ram,0x006b47fd) */
/* WARNING: Removing unreachable block (ram,0x006b4818) */
/* WARNING: Removing unreachable block (ram,0x006b4825) */
/* WARNING: Removing unreachable block (ram,0x006b483b) */
/* WARNING: Removing unreachable block (ram,0x006b4842) */
/* WARNING: Removing unreachable block (ram,0x006b4848) */
/* WARNING: Removing unreachable block (ram,0x006b484f) */
/* WARNING: Removing unreachable block (ram,0x006b4855) */
/* WARNING: Removing unreachable block (ram,0x006b485d) */
/* WARNING: Removing unreachable block (ram,0x006b4865) */
/* WARNING: Removing unreachable block (ram,0x006b4895) */
/* WARNING: Removing unreachable block (ram,0x006b489e) */
/* WARNING: Removing unreachable block (ram,0x006b48a8) */
/* WARNING: Removing unreachable block (ram,0x006b48bc) */
/* WARNING: Removing unreachable block (ram,0x006b48b3) */
/* WARNING: Removing unreachable block (ram,0x006b48c5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CGameThread__CreateMap
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *piVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00712de5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7e3c) &&
     (FUN_006cebf4(&DAT_00ca7e3c,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7e3c == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7e40 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "CGameThread::CreateMap";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7e3c);
  }
  iVar3 = DAT_00ca7e40;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7e40 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar2;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar5 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8._0_1_ = 1;
  *(undefined1 *)(DAT_0077241c + 0x29) = 0;
  uVar2 = FUN_004435d0(&local_14,"Map create");
  uVar2 = FUN_00443730(uVar2);
  local_8._0_1_ = 2;
  FUN_0055a950(uVar2,1);
  local_8._0_1_ = 3;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  *(undefined1 *)(DAT_0077241c + 0x29) = 0;
  CMap__Shut(1);
  CMap__Init(param_1,param_2,param_3,param_4);
  uVar2 = FUN_004435d0(&param_4,"Map clear");
  uVar2 = FUN_00443730(uVar2);
  local_8._0_1_ = 4;
  FUN_0055a950(uVar2,1);
  local_8._0_1_ = 5;
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  CMap__Clear();
  uVar2 = FUN_004435d0(&param_4,"Map Mapgen");
  uVar2 = FUN_00443730(uVar2);
  local_8._0_1_ = 6;
  FUN_0055a950(uVar2,1);
  local_8._0_1_ = 7;
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  local_14 = (int *)0x0;
  local_8._0_1_ = 8;
  FUN_00598f10();
  uVar2 = FUN_004435d0(&param_4,"Map lighting");
  uVar2 = FUN_00443730(uVar2);
  local_8._0_1_ = 9;
  FUN_0055a950(uVar2,1);
  local_8._0_1_ = 10;
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 8;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  *(undefined2 *)(DAT_0077241c + 0x29) = 0x100;
  uVar2 = FUN_004435d0(&param_4,"Map validate");
  uVar2 = FUN_00443730(uVar2);
  local_8._0_1_ = 0xb;
  FUN_0055a950(uVar2,1);
  local_8._0_1_ = 0xc;
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 8;
  if ((*(int *)(DAT_00772400 + 0x5a4) != 0) && (DAT_0076a338 != 0)) {
    FUN_006b59e0();
  }
  uVar9 = 0x10;
  uVar2 = *(undefined4 *)(DAT_0077241c + 0x94);
  uVar6 = *(undefined4 *)(DAT_0077241c + 0x98);
  uVar7 = *(undefined4 *)(DAT_0077241c + 0x9c);
  uVar8 = *(undefined4 *)(DAT_0077241c + 0xa0);
  FUN_005a3dd0(uVar2,uVar6,uVar7,uVar8,0x10);
  FUN_005a3fd0(uVar2,uVar6,uVar7,uVar8,uVar9);
  uVar2 = 0x7ff;
  FUN_005a3dd0(0x7ff);
  FUN_005a46d0(uVar2);
  uVar2 = FUN_004435d0(&param_4,"Map lights");
  uVar2 = FUN_00443730(uVar2);
  local_8._0_1_ = 0xd;
  FUN_0055a950(uVar2,1);
  local_8._0_1_ = 0xe;
  piVar4 = param_4;
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 == 0)) {
    FUN_006ba940();
    piVar4 = extraout_ECX;
  }
  local_8._0_1_ = 8;
  if (*(int *)(DAT_00772400 + 0x5a4) != 0) {
    if (DAT_0076a338 == 0) goto LAB_006b476b;
    FUN_006b59e0();
    piVar4 = extraout_ECX_00;
  }
  if (DAT_0076a338 != 0) {
    FUN_00464cc0();
    piVar4 = extraout_ECX_01;
  }
LAB_006b476b:
  *(undefined1 *)(*(int *)(DAT_0077241c + 0x20) + 8) = 1;
  *(undefined1 *)(DAT_0077241c + 0x29) = 1;
  local_8._0_1_ = 0xf;
  FUN_0059a1f0(piVar4);
  local_8._0_1_ = 1;
  uVar2 = FUN_004435d0(&param_4,"Map done");
  uVar2 = FUN_00443730(uVar2);
  local_8._0_1_ = 0x10;
  FUN_0055a950(uVar2,1);
  local_8 = CONCAT31(local_8._1_3_,0x11);
  if ((param_4 != (int *)0x0) && (*param_4 = *param_4 + -1, *param_4 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  if ((param_5 != (int *)0x0) && (*param_5 = *param_5 + -1, *param_5 < 1)) {
    TclFreeObj(param_5);
  }
  ExceptionList = local_10;
  return;
}

