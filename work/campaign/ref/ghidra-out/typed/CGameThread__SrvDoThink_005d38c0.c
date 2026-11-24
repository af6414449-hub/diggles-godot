
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CGameThread__SrvDoThink(CGameThread *this)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  CGameThread *pCVar10;
  undefined1 *puVar11;
  uint uVar12;
  undefined4 *puVar13;
  code *pcVar14;
  undefined8 uVar15;
  int *local_2c;
  int *local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  CGameThread *local_18;
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
         (FUN_006cebf4(&DAT_00ca6688), iVar7 = DAT_00783650, DAT_00ca6688 == -1)) {
        iVar5 = DAT_00783650 * 0x40;
        _DAT_00ca668c = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar5) =
             "CGameThread::SrvDoThink() GetObjMgr().HandleEvents() All Tick";
        *(int *)(&DAT_00773650 + iVar5) = iVar7;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca6688);
      }
      FUN_00405af0(&DAT_00ca668c);
      local_8._0_1_ = 1;
      uVar9 = 0xffffffff;
      while( true ) {
        uVar9 = uVar9 + 1;
        if (this->i_84b5 <= (int)uVar9) break;
        if ((uint)this->i_84b5 <= uVar9) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar4 = (int *)&this->field_0x488;
        local_2c = *(int **)(this->i_84b1 + uVar9 * 4);
        if (local_2c < (int *)0x2000) {
          piVar4 = (int *)((int)piVar4 + (int)local_2c * 4);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        this = local_18;
        if (*piVar4 != 0) {
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
         (FUN_006cebf4(&DAT_00ca6690), iVar7 = DAT_00783650, DAT_00ca6690 == -1)) {
        iVar5 = DAT_00783650 * 0x40;
        _DAT_00ca6694 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar5) =
             "CGameThread::SrvDoThink() GetObjMgr().HandleEvents() Events";
        *(int *)(&DAT_00773650 + iVar5) = iVar7;
        DAT_00783650 = DAT_00783650 + 1;
        FUN_006cebaa(&DAT_00ca6690);
      }
      FUN_00405af0(&DAT_00ca6694);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_00605f00();
      FUN_00606230();
      pCVar10 = local_18;
      puVar13 = (undefined4 *)0x0;
      do {
        piVar4 = (int *)FUN_005baae0(&local_2c);
        puVar1 = (undefined4 *)*piVar4;
        if (puVar1 != (undefined4 *)0x0) {
          LOCK();
          puVar1[1] = puVar1[1] + 1;
          UNLOCK();
        }
        if (puVar13 != (undefined4 *)0x0) {
          LOCK();
          iVar7 = puVar13[1] + -1;
          puVar13[1] = iVar7;
          UNLOCK();
          if (iVar7 == 0) {
            (**(code **)*puVar13)(1);
          }
        }
        if (local_2c != (int *)0x0) {
          LOCK();
          iVar7 = local_2c[1] + -1;
          local_2c[1] = iVar7;
          UNLOCK();
          if ((iVar7 == 0) && (local_2c != (int *)0x0)) {
            (**(code **)*local_2c)(1);
          }
        }
        puVar13 = puVar1;
      } while (puVar1 != (undefined4 *)0x0);
      local_8 = local_8 & 0xffffff00;
      FUN_0043fd30();
      pcVar14 = RaiseException_exref;
      local_11 = *(char *)(DAT_00772400 + 0x8c);
      DAT_00c3c9c0 = (undefined4 *)((int)DAT_00c3c9c0 + 1);
      if (DAT_00768374 <= (int)DAT_00c3c9c0) {
        DAT_00c3c9c0 = puVar1;
        if ((*(int *)(local_20 + 4) < DAT_00ca6698) &&
           (FUN_006cebf4(&DAT_00ca6698), iVar7 = DAT_00783650, DAT_00ca6698 == -1)) {
          iVar5 = DAT_00783650 * 0x40;
          _DAT_00ca669c = DAT_00783650;
          *(char **)(&DAT_0077368c + iVar5) =
               "CGameThread::SrvDoThink() GetObjMgr().HandleEvents() Active Objs";
          *(int *)(&DAT_00773650 + iVar5) = iVar7;
          DAT_00783650 = DAT_00783650 + 1;
          FUN_006cebaa(&DAT_00ca6698);
        }
        FUN_00405af0(&DAT_00ca669c);
        local_8._0_1_ = 3;
        local_1c = DAT_0077244c;
        uVar9 = DAT_0077244c;
        piVar4 = (int *)0xffffffff;
LAB_005d3b4c:
        piVar4 = (int *)((int)piVar4 + 1);
        local_2c = piVar4;
        if ((int)piVar4 < (int)*(int **)(uVar9 + 0x84c6)) {
          if (*(int **)(uVar9 + 0x84c6) <= piVar4) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar9 = local_1c;
          }
          puVar11 = &pCVar10->field_0x488;
          local_24 = *(uint *)(*(int *)(uVar9 + 0x84c2) + (int)piVar4 * 4);
          local_28 = (int *)puVar11;
          if (local_24 < 0x2000) {
            piVar6 = (int *)(puVar11 + local_24 * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar9 = local_1c;
            piVar6 = (int *)puVar11;
          }
          iVar7 = *piVar6;
          pCVar10 = local_18;
          if ((iVar7 != 0) && (1 < (int)local_24)) {
            uVar9 = local_1c;
            if (*(char *)(DAT_00772400 + 0x3d3) != '\0') {
              iVar5 = *(int *)(DAT_00772400 + 100);
              if (((*(int *)(iVar7 + 0x378) != iVar5) &&
                  ((*(int *)(iVar7 + 0x378) != -1 || (iVar5 != 0)))) &&
                 ((*(int *)(iVar7 + 0x36c) != -1 || (iVar5 != 0)))) goto LAB_005d3b4c;
            }
            if (((*(uint *)(iVar7 + 0x3d0) & 0x1000000) != 0) &&
               (((local_11 == '\0' || ((*(uint *)(iVar7 + 0x3d0) & 0x200000) != 0)) &&
                (*(char *)(*(int *)(iVar7 + 0xd4) + 0xcc0) != '\0')))) {
              if ((*(int *)(local_20 + 4) < DAT_00ca66a0) &&
                 (FUN_006cebf4(&DAT_00ca66a0), iVar5 = DAT_00783650, DAT_00ca66a0 == -1)) {
                iVar8 = DAT_00783650 * 0x40;
                DAT_00ca66a4 = DAT_00783650;
                *(char **)(&DAT_0077368c + iVar8) =
                     "CGameThread::SrvDoThink() GetObjMgr().HandleEvents() Active Objs Evt";
                *(int *)(&DAT_00773650 + iVar8) = iVar5;
                DAT_00783650 = DAT_00783650 + 1;
                FUN_006cebaa(&DAT_00ca66a0);
              }
              iVar8 = DAT_00ca66a4;
              uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca66a4 * 0x40);
              iVar5 = FUN_0043fcc0();
              *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar2;
              *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
              iVar5 = (&DAT_00773654)[iVar8 * 0x10];
              if (iVar5 == 0) {
                uVar15 = FUN_006bd180();
                iVar5 = (&DAT_00773654)[iVar8 * 0x10];
                *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar15;
              }
              (&DAT_00773654)[iVar8 * 0x10] = iVar5 + 1;
              local_8._0_1_ = 4;
              if (*(int *)(iVar7 + 0x1ec) != *(int *)(iVar7 + 0x1f0)) {
                FUN_005cabe0();
              }
              FUN_00605c10();
              local_8._0_1_ = 3;
              FUN_0043fd30();
              if (local_24 < 0x2000) {
                piVar6 = local_28 + local_24;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar6 = local_28;
              }
              uVar9 = local_1c;
              pCVar10 = local_18;
              piVar4 = local_2c;
              if (*piVar6 != 0) {
                if ((*(int *)(local_20 + 4) < DAT_00ca66a8) &&
                   (FUN_006cebf4(&DAT_00ca66a8), iVar7 = DAT_00783650, DAT_00ca66a8 == -1)) {
                  iVar5 = DAT_00783650 * 0x40;
                  DAT_00ca66ac = DAT_00783650;
                  *(char **)(&DAT_0077368c + iVar5) =
                       "CGameThread::SrvDoThink() GetObjMgr().HandleEvents() Active Objs States";
                  *(int *)(&DAT_00773650 + iVar5) = iVar7;
                  DAT_00783650 = DAT_00783650 + 1;
                  FUN_006cebaa(&DAT_00ca66a8);
                }
                iVar5 = DAT_00ca66ac;
                uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca66ac * 0x40);
                iVar7 = FUN_0043fcc0();
                *(undefined4 *)(iVar7 + *(int *)(iVar7 + 0x8000) * 4) = uVar2;
                *(int *)(iVar7 + 0x8000) = *(int *)(iVar7 + 0x8000) + 1;
                iVar7 = (&DAT_00773654)[iVar5 * 0x10];
                if (iVar7 == 0) {
                  uVar15 = FUN_006bd180();
                  iVar7 = (&DAT_00773654)[iVar5 * 0x10];
                  *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar15;
                }
                (&DAT_00773654)[iVar5 * 0x10] = iVar7 + 1;
                local_8._0_1_ = 5;
                FUN_005cac90();
                FUN_00605c10();
                local_8._0_1_ = 3;
                FUN_0043fd30();
                uVar9 = local_1c;
                pCVar10 = local_18;
                piVar4 = local_2c;
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
      uVar9 = 0xffffffff;
      local_1c = DAT_0077244c;
      while( true ) {
        pCVar10 = local_18;
        uVar9 = uVar9 + 1;
        if ((int)*(uint *)(local_1c + 0x84b5) <= (int)uVar9) break;
        if (*(uint *)(local_1c + 0x84b5) <= uVar9) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        uVar12 = *(uint *)(*(int *)(local_1c + 0x84b1) + uVar9 * 4);
        piVar4 = (int *)&local_18->field_0x488;
        if (uVar12 < 0x2000) {
          piVar4 = (int *)((int)piVar4 + uVar12 * 4);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (*piVar4 == 0) {
          FUN_00442970(uVar12);
          FUN_00442970(uVar12);
          FUN_00442970(uVar12);
        }
      }
      local_1c = 0xffffffff;
      local_24 = DAT_0077244c;
      uVar9 = DAT_0077244c;
      while( true ) {
        local_1c = local_1c + 1;
        if ((int)*(uint *)(uVar9 + 0x84d7) <= (int)local_1c) break;
        if (*(uint *)(uVar9 + 0x84d7) <= local_1c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar4 = (int *)&pCVar10->field_0x488;
        local_2c = *(int **)(*(int *)(uVar9 + 0x84d3) + local_1c * 4);
        if (local_2c < (int *)0x2000) {
          piVar6 = (int *)((int)piVar4 + (int)local_2c * 4);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar6 = piVar4;
        }
        uVar9 = local_24;
        if (*(int *)(*piVar6 + 0xe8) != 1) {
          if (local_2c < (int *)0x2000) {
            piVar4 = (int *)((int)piVar4 + (int)local_2c * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar9 = local_24;
          if (*(int *)(*piVar4 + 0xe8) != 0xb) {
            FUN_00442970(local_2c);
          }
        }
      }
      if (*(int *)(DAT_0076a338 + 0x283c) == 0) {
        if ((*(int *)(local_20 + 4) < DAT_00ca66b0) &&
           (FUN_006cebf4(&DAT_00ca66b0), iVar7 = DAT_00783650, DAT_00ca66b0 == -1)) {
          iVar5 = DAT_00783650 * 0x40;
          _DAT_00ca66b4 = DAT_00783650;
          *(char **)(&DAT_0077368c + iVar5) =
               "CGameThread::SrvDoThink() GetObjMgr().HandleEvents() RenderTick";
          *(int *)(&DAT_00773650 + iVar5) = iVar7;
          DAT_00783650 = DAT_00783650 + 1;
          FUN_006cebaa(&DAT_00ca66b0);
        }
        FUN_00405af0(&DAT_00ca66b4);
        local_8 = CONCAT31(local_8._1_3_,6);
        uVar12 = 0xffffffff;
        local_24 = DAT_0077244c;
        uVar9 = DAT_0077244c;
        while( true ) {
          uVar12 = uVar12 + 1;
          if ((int)*(uint *)(uVar9 + 0x84b5) <= (int)uVar12) break;
          if (*(uint *)(uVar9 + 0x84b5) <= uVar12) {
            (*pcVar14)(0xc000008c,1,0,0);
            uVar9 = local_24;
          }
          puVar11 = &local_18->field_0x488;
          uVar3 = *(uint *)(*(int *)(uVar9 + 0x84b1) + uVar12 * 4);
          if (uVar3 < 0x2000) {
            local_2c = (int *)(puVar11 + uVar3 * 4);
          }
          else {
            (*pcVar14)(0xc000008c,1,0,0);
            uVar9 = local_24;
            local_2c = (int *)puVar11;
          }
          pcVar14 = RaiseException_exref;
          if (*local_2c != 0) {
            if (uVar3 < 0x2000) {
              FUN_005cb9a0();
              uVar9 = local_24;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              FUN_005cb9a0();
              uVar9 = local_24;
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

