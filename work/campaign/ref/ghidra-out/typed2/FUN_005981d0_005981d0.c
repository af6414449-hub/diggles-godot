
/* WARNING: Removing unreachable block (ram,0x00598626) */
/* WARNING: Removing unreachable block (ram,0x005982eb) */
/* WARNING: Removing unreachable block (ram,0x005982ed) */
/* WARNING: Removing unreachable block (ram,0x005982ef) */
/* WARNING: Removing unreachable block (ram,0x00598300) */
/* WARNING: Removing unreachable block (ram,0x00598325) */
/* WARNING: Removing unreachable block (ram,0x00598334) */
/* WARNING: Removing unreachable block (ram,0x00598343) */
/* WARNING: Removing unreachable block (ram,0x00598352) */
/* WARNING: Removing unreachable block (ram,0x0059837e) */
/* WARNING: Removing unreachable block (ram,0x0059838a) */
/* WARNING: Removing unreachable block (ram,0x00598383) */
/* WARNING: Removing unreachable block (ram,0x005983a0) */
/* WARNING: Removing unreachable block (ram,0x0059840a) */
/* WARNING: Removing unreachable block (ram,0x005983a6) */
/* WARNING: Removing unreachable block (ram,0x005983c5) */
/* WARNING: Removing unreachable block (ram,0x005983c1) */
/* WARNING: Removing unreachable block (ram,0x005983d9) */
/* WARNING: Removing unreachable block (ram,0x005983e1) */
/* WARNING: Removing unreachable block (ram,0x005983ff) */
/* WARNING: Removing unreachable block (ram,0x0059840d) */
/* WARNING: Removing unreachable block (ram,0x005985a6) */
/* WARNING: Removing unreachable block (ram,0x00598424) */
/* WARNING: Removing unreachable block (ram,0x0059843e) */
/* WARNING: Removing unreachable block (ram,0x00598452) */
/* WARNING: Removing unreachable block (ram,0x00598466) */
/* WARNING: Removing unreachable block (ram,0x00598485) */
/* WARNING: Removing unreachable block (ram,0x0059849f) */
/* WARNING: Removing unreachable block (ram,0x005984b3) */
/* WARNING: Removing unreachable block (ram,0x005984c7) */
/* WARNING: Removing unreachable block (ram,0x005984e6) */
/* WARNING: Removing unreachable block (ram,0x00598500) */
/* WARNING: Removing unreachable block (ram,0x00598514) */
/* WARNING: Removing unreachable block (ram,0x00598525) */
/* WARNING: Removing unreachable block (ram,0x00598545) */
/* WARNING: Removing unreachable block (ram,0x0059855f) */
/* WARNING: Removing unreachable block (ram,0x00598573) */
/* WARNING: Removing unreachable block (ram,0x00598584) */
/* WARNING: Removing unreachable block (ram,0x005985a9) */
/* WARNING: Removing unreachable block (ram,0x005985bd) */
/* WARNING: Removing unreachable block (ram,0x005985c4) */
/* WARNING: Removing unreachable block (ram,0x005985c6) */
/* WARNING: Removing unreachable block (ram,0x005985eb) */
/* WARNING: Removing unreachable block (ram,0x0059863c) */
/* WARNING: Removing unreachable block (ram,0x00598645) */
/* WARNING: Removing unreachable block (ram,0x0059865a) */
/* WARNING: Removing unreachable block (ram,0x0059867c) */
/* WARNING: Removing unreachable block (ram,0x00598697) */
/* WARNING: Removing unreachable block (ram,0x005986a1) */
/* WARNING: Removing unreachable block (ram,0x005986bc) */
/* WARNING: Removing unreachable block (ram,0x005986c9) */
/* WARNING: Removing unreachable block (ram,0x005986ed) */
/* WARNING: Removing unreachable block (ram,0x005986f4) */
/* WARNING: Removing unreachable block (ram,0x005986fa) */
/* WARNING: Removing unreachable block (ram,0x00598701) */
/* WARNING: Removing unreachable block (ram,0x00598707) */
/* WARNING: Removing unreachable block (ram,0x0059870f) */
/* WARNING: Removing unreachable block (ram,0x00598717) */
/* WARNING: Removing unreachable block (ram,0x00598747) */
/* WARNING: Removing unreachable block (ram,0x00598750) */
/* WARNING: Removing unreachable block (ram,0x0059875a) */
/* WARNING: Removing unreachable block (ram,0x00598765) */
/* WARNING: Removing unreachable block (ram,0x0059877c) */
/* WARNING: Removing unreachable block (ram,0x00598785) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005981d0(undefined4 *param_1,int *param_2,undefined4 param_3,byte param_4)

{
  CMap *this;
  int iVar1;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  this = PTR_0077241c;
  puStack_18 = &LAB_00706b0d;
  local_1c = ExceptionList;
  ExceptionList = &local_1c;
  if ((((*param_2 < PTR_0077241c->cellX0 + 1) || (PTR_0077241c->cellX1 + -1 <= *param_2)) ||
      (param_2[1] < PTR_0077241c->cellY0 + 1)) || (PTR_0077241c->cellY1 + -1 <= param_2[1])) {
    *param_1 = 0xffffffff;
    param_1[1] = 0xffffffff;
  }
  else {
    local_14 = 0;
    FUN_0041fb80(1);
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iRamfffffff8 = *param_2;
    iRamfffffffc = param_2[1];
    iVar1 = FUN_00592f10(this);
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 4 << ((param_4 & 7) << 2);
    *param_1 = 0xffffffff;
    param_1[1] = 0xffffffff;
  }
  ExceptionList = local_1c;
  return param_1;
}

