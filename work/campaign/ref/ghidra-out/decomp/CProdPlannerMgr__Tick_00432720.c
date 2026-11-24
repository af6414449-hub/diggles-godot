
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CProdPlannerMgr__Tick(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *in_ECX;
  uint uVar8;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fb0d9;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((*(char *)(DAT_00772400 + 0x590) == '\0') && (DAT_0076837a == '\0')) {
                    /* WARNING: Load size is inaccurate */
    iVar7 = *ThreadLocalStoragePointer;
    if ((*(int *)(iVar7 + 4) < DAT_00c67180) &&
       (FUN_006cebf4(&DAT_00c67180,uVar4), iVar1 = DAT_00783650, DAT_00c67180 == -1)) {
      iVar6 = DAT_00783650 * 0x40;
      _DAT_00c67184 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar6) = "CProdPlannerMgr::Tick()";
      *(int *)(&DAT_00773650 + iVar6) = iVar1;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00c67180);
    }
    FUN_00405af0(&DAT_00c67184);
    local_8 = 0;
    uVar8 = 0;
    iVar1 = in_ECX[1];
    if (0 < iVar1) {
      do {
        if ((uint)in_ECX[1] <= uVar8) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar6 = *(int *)(*in_ECX + uVar8 * 4);
        iVar2 = *(int *)(iVar6 + 0x36c);
        if ((iVar2 != -1) && (*(int *)(iVar6 + 0x3e0) != 0)) {
          uVar5 = FUN_0042f510();
          if ((uint)in_ECX[iVar2 * 0xc25 + 10] <= uVar5) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(int *)(in_ECX[iVar2 * 0xc25 + 9] + uVar5 * 4) = iVar6;
        }
        uVar8 = uVar8 + 1;
      } while ((int)uVar8 < iVar1);
    }
    FUN_0042fbb0(0);
    if ((*(int *)(iVar7 + 4) < DAT_00c67188) &&
       (FUN_006cebf4(&DAT_00c67188,uVar4), DAT_00c67188 == -1)) {
      local_8._0_1_ = 1;
      if (DAT_00772400 != 0) {
        FUN_005655a0(&DAT_00768820);
        iVar7 = _rand();
        _DAT_00768820 = (double)iVar7 * _DAT_00768828 * 3.0517578125e-05;
      }
      _atexit(FUN_00713a20);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_006cebaa(&DAT_00c67188);
    }
    cVar3 = FUN_00565a10();
    if (cVar3 != '\0') {
      CProdPlanner__MaintenanceTick();
      DAT_00c3c968 = DAT_00c3c968 + 1 & 0x80000007;
      if ((int)DAT_00c3c968 < 0) {
        DAT_00c3c968 = (DAT_00c3c968 - 1 | 0xfffffff8) + 1;
      }
    }
    FUN_0043fd30();
  }
  ExceptionList = local_10;
  return;
}

