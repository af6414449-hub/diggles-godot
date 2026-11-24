
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CGameThread__SrvDoThink(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int this;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int *piVar10;
  undefined4 *puVar11;
  code *pcVar12;
  undefined8 uVar13;
  int *local_2c;
  int *local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00708b1d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(char *)(DAT_00772400 + 0x8a) != '\0') && (*(char *)(DAT_00772400 + 0xa098) != '\0')) {
    local_8 = 0;
    local_18 = this;
    FUN_00449180(DAT_0076700c ^ (uint)&stack0xfffffffc);
    DAT_00c3c9c4 = DAT_00c3c9c4 + 1;
    if (DAT_00768374 <= DAT_00c3c9c4) {
                    /* WARNING: Load size is inaccurate */
      if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6688) &&
         (FUN_006cebf4(&DAT_00ca6688), iVar4 = DAT_00783650, DAT_00ca6688 == -1)) {
        iVar6 = DAT_00783650 * 0x40;
        _DAT_00ca668c = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar6) =
             "CGameThread::SrvDoThink() GetObjMgr().HandleEvents() All Tick";
        *(int *)(&DAT_00773650 + iVar6) = iVar4;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca6688);
      }
      FUN_00405af0(&DAT_00ca668c);
      local_8._0_1_ = 1;
      uVar7 = 0xffffffff;
      while( true ) {
        uVar7 = uVar7 + 1;
        if ((int)this->i_84b5 <= (int)uVar7) break;
        if (this->i_84b5 <= uVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar10 = (int *)(this + 0x488);
        local_2c = *(int **)(this->i_84b1 + uVar7 * 4);
        if (local_2c < (int *)0x2000) {
          piVar10 = piVar10 + (int)local_2c;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        this = local_18;
        if (*piVar10 != 0) {
          if (local_2c < (int *)0x2000) {
            FUN_005cc600();
            this = local_18;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            FUN_005cc600();
            this = local_18;
          }
        }
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0043fd30();
    }
    if ((*(char *)(DAT_00772400 + 0x590) == '\0') && (*(char *)(DAT_00772400 + 0x94) != '\0')) {
                    /* WARNING: Load size is inaccurate */
      local_20 = *ThreadLocalStoragePointer;
      if ((*(int *)(local_20 + 4) < DAT_00ca6690) &&
         (FUN_006cebf4(&DAT_00ca6690), iVar4 = DAT_00783650, DAT_00ca6690 == -1)) {
        iVar6 = DAT_00783650 * 0x40;
        _DAT_00ca6694 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar6) =
             "CGameThread::SrvDoThink() GetObjMgr().HandleEvents() Events";
        *(int *)(&DAT_00773650 + iVar6) = iVar4;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca6690);
      }
      FUN_00405af0(&DAT_00ca6694);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_00605f00();
      FUN_00606230();
      iVar4 = local_18;
      puVar11 = (undefined4 *)0x0;
      do {
        piVar10 = (int *)FUN_005baae0(&local_2c);
        puVar1 = (undefined4 *)*piVar10;
        if (puVar1 != (undefined4 *)0x0) {
          LOCK();
          puVar1[1] = puVar1[1] + 1;
          UNLOCK();
        }
        if (puVar11 != (undefined4 *)0x0) {
          LOCK();
          iVar6 = puVar11[1] + -1;
          puVar11[1] = iVar6;
          UNLOCK();
          if (iVar6 == 0) {
            (**(code **)*puVar11)(1);
          }
        }
        if (local_2c != (int *)0x0) {
          LOCK();
          iVar6 = local_2c[1] + -1;
          local_2c[1] = iVar6;
          UNLOCK();
          if ((iVar6 == 0) && (local_2c != (int *)0x0)) {
            (**(code **)*local_2c)(1);
          }
        }
        puVar11 = puVar1;
      } while (puVar1 != (undefined4 *)0x0);
      local_8 = local_8 & 0xffffff00;
      FUN_0043fd30();
      pcVar12 = RaiseException_exref;
      local_11 = *(char *)(DAT_00772400 + 0x8c);
      DAT_00c3c9c0 = (undefined4 *)((int)DAT_00c3c9c0 + 1);
      if (DAT_00768374 <= (int)DAT_00c3c9c0) {
        DAT_00c3c9c0 = puVar1;
        if ((*(int *)(local_20 + 4) < DAT_00ca6698) &&
           (FUN_006cebf4(&DAT_00ca6698), iVar6 = DAT_00783650, DAT_00ca6698 == -1)) {
          iVar5 = DAT_00783650 * 0x40;
          _DAT_00ca669c = DAT_00783650;
          *(char **)(&DAT_0077368c + iVar5) =
               "CGameThread::SrvDoThink() GetObjMgr().HandleEvents() Active Objs";
          *(int *)(&DAT_00773650 + iVar5) = iVar6;
          DAT_00783650 = DAT_00783650 + 1;
          FUN_006cebaa(&DAT_00ca6698);
        }
        FUN_00405af0(&DAT_00ca669c);
        local_8._0_1_ = 3;
        local_1c = DAT_0077244c;
        uVar7 = DAT_0077244c;
        piVar10 = (int *)0xffffffff;
LAB_005d3b4c:
        piVar10 = (int *)((int)piVar10 + 1);
        local_2c = piVar10;
        if ((int)piVar10 < (int)*(int **)(uVar7 + 0x84c6)) {
          if (*(int **)(uVar7 + 0x84c6) <= piVar10) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar7 = local_1c;
          }
          piVar8 = (int *)(iVar4 + 0x488);
          local_24 = *(uint *)(*(int *)(uVar7 + 0x84c2) + (int)piVar10 * 4);
          local_28 = piVar8;
          if (local_24 < 0x2000) {
            piVar8 = piVar8 + local_24;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar7 = local_1c;
          }
          iVar6 = *piVar8;
          iVar4 = local_18;
          if ((iVar6 != 0) && (1 < (int)local_24)) {
            uVar7 = local_1c;
            if (*(char *)(DAT_00772400 + 0x3d3) != '\0') {
              iVar5 = *(int *)(DAT_00772400 + 100);
              if (((*(int *)(iVar6 + 0x378) != iVar5) &&
                  ((*(int *)(iVar6 + 0x378) != -1 || (iVar5 != 0)))) &&
                 ((*(int *)(iVar6 + 0x36c) != -1 || (iVar5 != 0)))) goto LAB_005d3b4c;
            }
            if (((*(uint *)(iVar6 + 0x3d0) & 0x1000000) != 0) &&
               (((local_11 == '\0' || ((*(uint *)(iVar6 + 0x3d0) & 0x200000) != 0)) &&
                (*(char *)(*(int *)(iVar6 + 0xd4) + 0xcc0) != '\0')))) {
              if ((*(int *)(local_20 + 4) < DAT_00ca66a0) &&
                 (FUN_006cebf4(&DAT_00ca66a0), iVar4 = DAT_00783650, DAT_00ca66a0 == -1)) {
                iVar5 = DAT_00783650 * 0x40;
                DAT_00ca66a4 = DAT_00783650;
                *(char **)(&DAT_0077368c + iVar5) =
                     "CGameThread::SrvDoThink() GetObjMgr().HandleEvents() Active Objs Evt";
                *(int *)(&DAT_00773650 + iVar5) = iVar4;
                DAT_00783650 = DAT_00783650 + 1;
                FUN_006cebaa(&DAT_00ca66a0);
              }
              iVar5 = DAT_00ca66a4;
              uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca66a4 * 0x40);
              iVar4 = FUN_0043fcc0();
              *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar2;
              *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
              iVar4 = (&DAT_00773654)[iVar5 * 0x10];
              if (iVar4 == 0) {
                uVar13 = FUN_006bd180();
                iVar4 = (&DAT_00773654)[iVar5 * 0x10];
                *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar13;
              }
              (&DAT_00773654)[iVar5 * 0x10] = iVar4 + 1;
              local_8._0_1_ = 4;
              if (*(int *)(iVar6 + 0x1ec) != *(int *)(iVar6 + 0x1f0)) {
                FUN_005cabe0();
              }
              FUN_00605c10();
              local_8._0_1_ = 3;
              FUN_0043fd30();
              if (local_24 < 0x2000) {
                piVar8 = local_28 + local_24;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar8 = local_28;
              }
              uVar7 = local_1c;
              iVar4 = local_18;
              piVar10 = local_2c;
              if (*piVar8 != 0) {
                if ((*(int *)(local_20 + 4) < DAT_00ca66a8) &&
                   (FUN_006cebf4(&DAT_00ca66a8), iVar4 = DAT_00783650, DAT_00ca66a8 == -1)) {
                  iVar6 = DAT_00783650 * 0x40;
                  DAT_00ca66ac = DAT_00783650;
                  *(char **)(&DAT_0077368c + iVar6) =
                       "CGameThread::SrvDoThink() GetObjMgr().HandleEvents() Active Objs States";
                  *(int *)(&DAT_00773650 + iVar6) = iVar4;
                  DAT_00783650 = DAT_00783650 + 1;
                  FUN_006cebaa(&DAT_00ca66a8);
                }
                iVar6 = DAT_00ca66ac;
                uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca66ac * 0x40);
                iVar4 = FUN_0043fcc0();
                *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar2;
                *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
                iVar4 = (&DAT_00773654)[iVar6 * 0x10];
                if (iVar4 == 0) {
                  uVar13 = FUN_006bd180();
                  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
                  *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar13;
                }
                (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
                local_8._0_1_ = 5;
                FUN_005cac90();
                FUN_00605c10();
                local_8._0_1_ = 3;
                FUN_0043fd30();
                uVar7 = local_1c;
                iVar4 = local_18;
                piVar10 = local_2c;
              }
            }
          }
          goto LAB_005d3b4c;
        }
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0043fd30();
      }
      FUN_00605c10();
      FUN_00449180();
      uVar7 = 0xffffffff;
      local_1c = DAT_0077244c;
      while( true ) {
        iVar4 = local_18;
        uVar7 = uVar7 + 1;
        if ((int)*(uint *)(local_1c + 0x84b5) <= (int)uVar7) break;
        if (*(uint *)(local_1c + 0x84b5) <= uVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        uVar9 = *(uint *)(*(int *)(local_1c + 0x84b1) + uVar7 * 4);
        piVar10 = (int *)(local_18 + 0x488);
        if (uVar9 < 0x2000) {
          piVar10 = piVar10 + uVar9;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (*piVar10 == 0) {
          FUN_00442970(uVar9);
          FUN_00442970(uVar9);
          FUN_00442970(uVar9);
        }
      }
      local_1c = 0xffffffff;
      local_24 = DAT_0077244c;
      uVar7 = DAT_0077244c;
      while( true ) {
        local_1c = local_1c + 1;
        if ((int)*(uint *)(uVar7 + 0x84d7) <= (int)local_1c) break;
        if (*(uint *)(uVar7 + 0x84d7) <= local_1c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar10 = (int *)(iVar4 + 0x488);
        local_2c = *(int **)(*(int *)(uVar7 + 0x84d3) + local_1c * 4);
        if (local_2c < (int *)0x2000) {
          piVar8 = piVar10 + (int)local_2c;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar8 = piVar10;
        }
        uVar7 = local_24;
        if (*(int *)(*piVar8 + 0xe8) != 1) {
          if (local_2c < (int *)0x2000) {
            piVar10 = piVar10 + (int)local_2c;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar7 = local_24;
          if (*(int *)(*piVar10 + 0xe8) != 0xb) {
            FUN_00442970(local_2c);
          }
        }
      }
      if (*(int *)(DAT_0076a338 + 0x283c) == 0) {
        if ((*(int *)(local_20 + 4) < DAT_00ca66b0) &&
           (FUN_006cebf4(&DAT_00ca66b0), iVar4 = DAT_00783650, DAT_00ca66b0 == -1)) {
          iVar6 = DAT_00783650 * 0x40;
          _DAT_00ca66b4 = DAT_00783650;
          *(char **)(&DAT_0077368c + iVar6) =
               "CGameThread::SrvDoThink() GetObjMgr().HandleEvents() RenderTick";
          *(int *)(&DAT_00773650 + iVar6) = iVar4;
          DAT_00783650 = DAT_00783650 + 1;
          FUN_006cebaa(&DAT_00ca66b0);
        }
        FUN_00405af0(&DAT_00ca66b4);
        local_8 = CONCAT31(local_8._1_3_,6);
        uVar9 = 0xffffffff;
        local_24 = DAT_0077244c;
        uVar7 = DAT_0077244c;
        while( true ) {
          uVar9 = uVar9 + 1;
          if ((int)*(uint *)(uVar7 + 0x84b5) <= (int)uVar9) break;
          if (*(uint *)(uVar7 + 0x84b5) <= uVar9) {
            (*pcVar12)(0xc000008c,1,0,0);
            uVar7 = local_24;
          }
          piVar10 = (int *)(local_18 + 0x488);
          uVar3 = *(uint *)(*(int *)(uVar7 + 0x84b1) + uVar9 * 4);
          if (uVar3 < 0x2000) {
            local_2c = piVar10 + uVar3;
          }
          else {
            (*pcVar12)(0xc000008c,1,0,0);
            uVar7 = local_24;
            local_2c = piVar10;
          }
          pcVar12 = RaiseException_exref;
          if (*local_2c != 0) {
            if (uVar3 < 0x2000) {
              FUN_005cb9a0();
              uVar7 = local_24;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              FUN_005cb9a0();
              uVar7 = local_24;
            }
          }
        }
        FUN_0043fd30();
        ExceptionList = local_10;
        return;
      }
    }
    else {
      FUN_00605c10();
    }
  }
  ExceptionList = local_10;
  return;
}

