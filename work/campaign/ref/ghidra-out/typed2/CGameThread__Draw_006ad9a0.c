
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameThread__Draw(CGameThread *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_ECX;
  uint uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071284d;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  iVar1 = *ThreadLocalStoragePointer;
  if ((*(int *)(iVar1 + 4) < DAT_00ca7d08) &&
     (FUN_006cebf4(&DAT_00ca7d08,local_14), iVar2 = DAT_00783650, DAT_00ca7d08 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7d0c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) =
         "CGameThread::Draw() EndBuildFrame -> RenderThread RenderEB RenderBegin";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7d08);
  }
  iVar3 = DAT_00ca7d0c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7d0c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar5 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  iVar2 = FUN_0044d010();
  if (*(char *)(iVar2 + 0x223) == '\0') {
    FUN_0044f280(1);
    iVar3 = (**(code **)(**(int **)(iVar2 + 0x80) + 0x24))();
    if (*(int *)(iVar2 + 0x8c) != iVar3) {
      *(int *)(iVar2 + 0x8c) = iVar3;
    }
    *(undefined1 *)(iVar2 + 0x223) = 1;
    *(undefined4 *)(iVar2 + 0x224) = 0;
  }
  local_8 = 0xffffffff;
  FUN_0043fd30();
  iVar2 = FUN_0044d010();
  local_24 = 0;
  local_1c = *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x94) + 0x18) + 0x10);
  local_20 = 0;
  local_18 = *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x94) + 0x18) + 0xc);
  iVar3 = (**(code **)(**(int **)(iVar2 + 0x80) + 0x30))
                    (1,&local_24,(*(char *)(iVar2 + 0x90) != '\0') * '\x02' + '\x01',0,0x3f800000,0)
  ;
  if (*(int *)(iVar2 + 0x8c) != iVar3) {
    *(int *)(iVar2 + 0x8c) = iVar3;
  }
  if ((((*(char *)(DAT_0076a338 + 0x19f08) == '\0') && (*(char *)(DAT_0076a338 + 0x101) == '\0')) &&
      (*(char *)(DAT_0076a338 + 0x19f12) == '\0')) && (*(char *)(DAT_0076a338 + 0x2850) == '\0')) {
    if ((*(int *)(iVar1 + 4) < DAT_00ca7d18) &&
       (FUN_006cebf4(&DAT_00ca7d18), iVar2 = DAT_00783650, DAT_00ca7d18 == -1)) {
      iVar3 = DAT_00783650 * 0x40;
      _DAT_00ca7d1c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) =
           "CGameThread::Draw() EndBuildFrame -> RenderThread RenderEB Fill";
      *(int *)(&DAT_00773650 + iVar3) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7d18);
    }
    FUN_00405af0(&DAT_00ca7d1c);
    uVar8 = 0;
    uVar6 = 0;
    local_8 = 2;
    uVar7 = extraout_ECX;
    FUN_0044d010(0,extraout_ECX,0);
    FUN_0044f200(uVar6,uVar7,uVar8);
    *(undefined4 *)(DAT_0076a338 + 0x19f14) = 1;
  }
  else {
    if ((*(int *)(iVar1 + 4) < DAT_00ca7d10) &&
       (FUN_006cebf4(&DAT_00ca7d10), iVar2 = DAT_00783650, DAT_00ca7d10 == -1)) {
      iVar3 = DAT_00783650 * 0x40;
      DAT_00ca7d14 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) =
           "CGameThread::Draw() EndBuildFrame -> RenderThread RenderEB Fill";
      *(int *)(&DAT_00773650 + iVar3) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7d10);
    }
    iVar3 = DAT_00ca7d14;
    uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7d14 * 0x40);
    iVar2 = FUN_0043fcc0();
    *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
    *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    if (iVar2 == 0) {
      uVar5 = FUN_006bd180();
      iVar2 = (&DAT_00773654)[iVar3 * 0x10];
      *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar5;
    }
    (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
    local_8 = 1;
    if (*(char *)(DAT_0076a338 + 0x19f12) == '\0') {
      uVar4 = (*(int *)(DAT_0076a338 + 0x2854) << 8 | *(uint *)(DAT_0076a338 + 0x2858)) << 8 |
              *(uint *)(DAT_0076a338 + 0x285c);
      iVar2 = FUN_0044d010();
      local_24 = 0;
      local_1c = *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x94) + 0x18) + 0x10);
      local_20 = 0;
      local_18 = *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x94) + 0x18) + 0xc);
      iVar3 = (**(code **)(**(int **)(iVar2 + 0x80) + 0x30))
                        (1,&local_24,(*(char *)(iVar2 + 0x90) != '\0') * '\x02' + '\x01',uVar4,
                         0x3f800000,0);
      if (*(int *)(iVar2 + 0x8c) != iVar3) {
        *(int *)(iVar2 + 0x8c) = iVar3;
      }
      *(uint *)(DAT_0076a338 + 0x19f14) = uVar4;
    }
    else {
      iVar2 = FUN_0044d010();
      local_24 = 0;
      local_1c = *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x94) + 0x18) + 0x10);
      local_20 = 0;
      local_18 = *(undefined4 *)(*(int *)(*(int *)(iVar2 + 0x94) + 0x18) + 0xc);
      iVar3 = (**(code **)(**(int **)(iVar2 + 0x80) + 0x30))
                        (1,&local_24,(*(char *)(iVar2 + 0x90) != '\0') * '\x02' + '\x01',0xffb8b2aa,
                         0x3f800000,0);
      if (*(int *)(iVar2 + 0x8c) != iVar3) {
        *(int *)(iVar2 + 0x8c) = iVar3;
      }
      *(undefined4 *)(DAT_0076a338 + 0x19f14) = 0xffb8b2aa;
    }
  }
  FUN_0043fd30();
  if ((*(int *)(iVar1 + 4) < DAT_00ca7d20) &&
     (FUN_006cebf4(&DAT_00ca7d20), iVar2 = DAT_00783650, DAT_00ca7d20 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7d24 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) =
         "CGameThread::Draw() EndBuildFrame -> RenderThread RenderEB BeginFrame";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7d20);
  }
  iVar3 = DAT_00ca7d24;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7d24 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar5 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 3;
  FUN_0044d010();
  FUN_0044d7c0();
  FUN_0043fd30();
  if ((*(int *)(iVar1 + 4) < DAT_00ca7d28) &&
     (FUN_006cebf4(&DAT_00ca7d28), iVar2 = DAT_00783650, DAT_00ca7d28 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7d2c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) =
         "CGameThread::Draw() EndBuildFrame -> RenderThread RenderEB EndFrame";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7d28);
  }
  iVar3 = DAT_00ca7d2c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7d2c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar5 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 4;
  FUN_0044d010();
  FUN_0044d9d0();
  FUN_0043fd30();
  if ((*(int *)(iVar1 + 4) < DAT_00ca7d30) &&
     (FUN_006cebf4(&DAT_00ca7d30), iVar2 = DAT_00783650, DAT_00ca7d30 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7d34 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) =
         "CGameThread::Draw() EndBuildFrame -> RenderThread RenderEB RenderEnd";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7d30);
  }
  iVar3 = DAT_00ca7d34;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7d34 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar5 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 5;
  iVar2 = FUN_0044d010();
  if (*(char *)(iVar2 + 0x223) != '\0') {
    iVar3 = (**(code **)(**(int **)(iVar2 + 0x80) + 0x28))();
    if (*(int *)(iVar2 + 0x8c) != iVar3) {
      *(int *)(iVar2 + 0x8c) = iVar3;
    }
    FUN_0044f280(0);
    *(undefined1 *)(iVar2 + 0x223) = 0;
  }
  local_8 = 0xffffffff;
  FUN_0043fd30();
  if (this->i_84 != 0) {
    FUN_006ae320();
  }
  if ((*(char *)(DAT_0076a338 + 0x2839) == '\0') && (*(int *)(DAT_0076a338 + 0x283c) == 0)) {
    if ((*(int *)(iVar1 + 4) < DAT_00ca7d38) &&
       (FUN_006cebf4(&DAT_00ca7d38), iVar1 = DAT_00783650, DAT_00ca7d38 == -1)) {
      iVar2 = DAT_00783650 * 0x40;
      _DAT_00ca7d3c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar2) =
           "CGameThread::Draw() EndBuildFrame -> RenderThread RenderEB Flip";
      *(int *)(&DAT_00773650 + iVar2) = iVar1;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7d38);
    }
    FUN_00405af0(&DAT_00ca7d3c);
    local_8 = 6;
    FUN_0044d010();
    FUN_0044ff00();
    local_8 = 0xffffffff;
    FUN_0043fd30();
  }
  FUN_0044d010();
  FUN_0044bcd0();
  FUN_0044d010();
  FUN_0044c450();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

