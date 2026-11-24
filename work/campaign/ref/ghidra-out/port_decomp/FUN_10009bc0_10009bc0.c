
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10009bc0(uint param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  void *_Dst;
  int iVar5;
  int in_ECX;
  undefined4 in_EDX;
  undefined1 local_94 [16];
  uint local_84;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  uint local_44;
  uint local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041d4a;
  local_10 = ExceptionList;
  local_18 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_18);
  if (DAT_10050c64 == (int *)0x0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
  }
  piVar3 = *(int **)(*DAT_10050c64 + 4);
  *(bool *)(in_ECX + 1) = param_3 != 0;
  if (param_3 != 0) {
    *(undefined4 *)(in_ECX + 8) = param_5;
    local_44 = param_1;
    *(undefined4 *)(in_ECX + 4) = param_4;
    local_40 = param_2;
    local_3c = 1;
    local_38 = 1;
    local_34 = param_4;
    local_30 = 1;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0x28;
    local_20 = 0;
    local_1c = 0;
    piVar1 = (int *)(in_ECX + 0x68);
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    piVar4 = (int *)*piVar1;
    if (piVar4 != (int *)0x0) {
      *piVar1 = 0;
      (**(code **)(*piVar4 + 8))(piVar4);
    }
    iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3,&local_44,0,piVar1);
    if (iVar5 < 0) goto LAB_1000a3d8;
    piVar4 = *(int **)(in_ECX + 0x6c);
    if (piVar4 != (int *)0x0) {
      *(undefined4 *)(in_ECX + 0x6c) = 0;
      (**(code **)(*piVar4 + 8))(piVar4);
    }
    iVar5 = (**(code **)(*piVar3 + 0x1c))(piVar3,*piVar1,0,in_ECX + 0x6c);
    if (iVar5 < 0) goto LAB_1000a3d8;
    local_84 = param_1;
    local_80 = param_2;
    local_7c = 1;
    local_78 = 1;
    local_74 = 0x27;
    local_70 = 1;
    local_6c = 0;
    local_68 = 0;
    local_64 = 0x80;
    local_60 = 0;
    local_5c = 0;
    piVar1 = (int *)(in_ECX + 0x70);
    local_8._0_1_ = 2;
    piVar4 = (int *)*piVar1;
    if (piVar4 != (int *)0x0) {
      *piVar1 = 0;
      (**(code **)(*piVar4 + 8))(piVar4);
    }
    iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3,&local_84,0,piVar1);
    if (iVar5 < 0) goto LAB_1000a3d8;
    local_58 = 0x29;
    local_54 = 4;
    local_50 = 0;
    local_8._0_1_ = 3;
    piVar4 = *(int **)(in_ECX + 0x74);
    if (piVar4 != (int *)0x0) {
      *(undefined4 *)(in_ECX + 0x74) = 0;
      (**(code **)(*piVar4 + 8))(piVar4);
    }
    iVar5 = (**(code **)(*piVar3 + 0x20))(piVar3,*piVar1,&local_58,in_ECX + 0x74);
    if (iVar5 < 0) goto LAB_1000a3d8;
  }
  local_80 = *(uint *)(in_ECX + 0x10);
  local_7c = 1;
  local_78 = 1;
  local_74 = 0x3d;
  local_70 = 1;
  local_84 = (local_80 * param_1) / param_2;
  local_6c = 0;
  *(uint *)(in_ECX + 0xc) = local_84;
  local_68 = 0;
  local_64 = 0x28;
  local_60 = 0;
  local_5c = 0;
  piVar1 = (int *)(in_ECX + 0x78);
  local_8._0_1_ = 4;
  local_8._1_3_ = 0;
  piVar4 = (int *)*piVar1;
  if (piVar4 != (int *)0x0) {
    *piVar1 = 0;
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3,&local_84,0,piVar1);
  if (-1 < iVar5) {
    local_58 = 0x3d;
    local_54 = 4;
    local_50 = 0;
    local_8._0_1_ = 5;
    piVar4 = *(int **)(in_ECX + 0x7c);
    if (piVar4 != (int *)0x0) {
      *(undefined4 *)(in_ECX + 0x7c) = 0;
      (**(code **)(*piVar4 + 8))(piVar4);
    }
    iVar5 = (**(code **)(*piVar3 + 0x24))(piVar3,*piVar1,&local_58,in_ECX + 0x7c);
    if (-1 < iVar5) {
      local_40 = *(uint *)(in_ECX + 0x10);
      local_44 = *(uint *)(in_ECX + 0xc);
      local_3c = 1;
      local_38 = 1;
      local_34 = 0x3d;
      local_30 = 1;
      local_2c = 0;
      local_28 = 3;
      local_24 = 0;
      local_20 = 0x20000;
      local_1c = 0;
      piVar1 = (int *)(in_ECX + 0x80);
      local_8._0_1_ = 6;
      piVar4 = (int *)*piVar1;
      if (piVar4 != (int *)0x0) {
        *piVar1 = 0;
        (**(code **)(*piVar4 + 8))(piVar4);
      }
      iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3,&local_44,0,piVar1);
      if (-1 < iVar5) {
        local_40 = *(uint *)(in_ECX + 0x18);
        local_3c = 1;
        local_38 = 1;
        local_30 = 1;
        local_2c = 0;
        local_44 = (local_40 * param_1) / param_2;
        local_28 = 0;
        *(uint *)(in_ECX + 0x14) = local_44;
        local_34 = param_4;
        local_24 = 0x28;
        local_20 = 0;
        local_1c = 0;
        piVar1 = (int *)(in_ECX + 0x84);
        local_8._0_1_ = 7;
        local_8._1_3_ = 0;
        piVar4 = (int *)*piVar1;
        if (piVar4 != (int *)0x0) {
          *piVar1 = 0;
          (**(code **)(*piVar4 + 8))(piVar4);
        }
        iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3,&local_44,0,piVar1);
        if (-1 < iVar5) {
          piVar1 = *(int **)(in_ECX + 0x90);
          puVar2 = (undefined4 *)(in_ECX + 0x90);
          if (piVar1 != (int *)0x0) {
            *puVar2 = 0;
            (**(code **)(*piVar1 + 8))(piVar1);
          }
          iVar5 = (**(code **)(*piVar3 + 0x14))(piVar3,&local_44,0,puVar2);
          if (-1 < iVar5) {
            local_58 = param_4;
            local_54 = 4;
            local_50 = 0;
            local_8._0_1_ = 8;
            piVar1 = *(int **)(in_ECX + 0x88);
            if (piVar1 != (int *)0x0) {
              *(undefined4 *)(in_ECX + 0x88) = 0;
              (**(code **)(*piVar1 + 8))(piVar1);
            }
            iVar5 = (**(code **)(*piVar3 + 0x24))
                              (piVar3,*(undefined4 *)(in_ECX + 0x84),&local_58,in_ECX + 0x88);
            if (-1 < iVar5) {
              piVar1 = *(int **)(in_ECX + 0x94);
              if (piVar1 != (int *)0x0) {
                *(undefined4 *)(in_ECX + 0x94) = 0;
                (**(code **)(*piVar1 + 8))(piVar1);
              }
              iVar5 = (**(code **)(*piVar3 + 0x24))(piVar3,*puVar2,&local_58,in_ECX + 0x94);
              if (-1 < iVar5) {
                piVar1 = *(int **)(in_ECX + 0x8c);
                if (piVar1 != (int *)0x0) {
                  *(undefined4 *)(in_ECX + 0x8c) = 0;
                  (**(code **)(*piVar1 + 8))(piVar1);
                }
                iVar5 = (**(code **)(*piVar3 + 0x1c))
                                  (piVar3,*(undefined4 *)(in_ECX + 0x84),0,in_ECX + 0x8c);
                if (-1 < iVar5) {
                  piVar1 = *(int **)(in_ECX + 0x98);
                  if (piVar1 != (int *)0x0) {
                    *(undefined4 *)(in_ECX + 0x98) = 0;
                    (**(code **)(*piVar1 + 8))(piVar1);
                  }
                  iVar5 = (**(code **)(*piVar3 + 0x1c))(piVar3,*puVar2,0,in_ECX + 0x98);
                  if (-1 < iVar5) {
                    _DAT_10050ef4 = 0;
                    _DAT_10050ef0 = 0;
                    _DAT_10050ef8 = 0;
                    _DAT_10050efc = 0;
                    _DAT_10050f08 = 0;
                    _DAT_10050f0c = 0x3f800000;
                    DAT_10050f00 = (float)((double)(int)param_1 +
                                          *(double *)(&DAT_10047c80 + ((int)param_1 >> 0x1f) * -8));
                    DAT_10050f04 = (float)((double)(int)param_2 +
                                          *(double *)(&DAT_10047c80 + ((int)param_2 >> 0x1f) * -8));
                    _DAT_10050e60 = *(undefined4 *)(in_ECX + 0x9c);
                    _DAT_10050e70 =
                         (float)((double)*(int *)(in_ECX + 0xc) +
                                *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0xc) >> 0x1f) * -8));
                    _DAT_10050e64 = *(undefined4 *)(in_ECX + 0xa0);
                    _DAT_10050e74 =
                         (float)((double)*(int *)(in_ECX + 0x10) +
                                *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0x10) >> 0x1f) * -8))
                    ;
                    _DAT_10050e68 = 0;
                    _DAT_10050e6c = 0;
                    _DAT_10050e78 = 0;
                    _DAT_10050e7c = 0x3f800000;
                    _DAT_10050dd0 = *(undefined4 *)(in_ECX + 0x9c);
                    _DAT_10050de0 =
                         (float)((double)*(int *)(in_ECX + 0x14) +
                                *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0x14) >> 0x1f) * -8))
                    ;
                    _DAT_10050dd4 = *(undefined4 *)(in_ECX + 0xa0);
                    _DAT_10050de4 =
                         (float)((double)*(int *)(in_ECX + 0x18) +
                                *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0x18) >> 0x1f) * -8))
                    ;
                    _DAT_10050dd8 = 0;
                    _DAT_10050ddc = 0;
                    _DAT_10050de8 = 0;
                    _DAT_10050dec = 0x3f800000;
                    _DAT_10050d40 = *(undefined4 *)(in_ECX + 0x9c);
                    _DAT_10050d50 =
                         (float)((double)*(int *)(in_ECX + 0x14) +
                                *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0x14) >> 0x1f) * -8))
                    ;
                    _DAT_10050d44 = *(undefined4 *)(in_ECX + 0xa0);
                    _DAT_10050d48 = 0;
                    _DAT_10050d54 =
                         (float)((double)*(int *)(in_ECX + 0x18) +
                                *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0x18) >> 0x1f) * -8))
                    ;
                    _DAT_10050d4c = 0;
                    _DAT_10050d58 = 0;
                    _DAT_10050d5c = 0x3f800000;
                    _DAT_10050f80 = *(undefined4 *)(in_ECX + 0x9c);
                    _DAT_10050f90 =
                         (float)((double)*(int *)(in_ECX + 0x14) +
                                *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0x14) >> 0x1f) * -8))
                    ;
                    _DAT_10050f84 = *(undefined4 *)(in_ECX + 0xa0);
                    _DAT_10050f88 = 0;
                    _DAT_10050f94 =
                         (float)((double)*(int *)(in_ECX + 0x18) +
                                *(double *)(&DAT_10047c80 + (*(int *)(in_ECX + 0x18) >> 0x1f) * -8))
                    ;
                    _DAT_10050f8c = 0;
                    _DAT_10050f98 = 0;
                    _DAT_10050f9c = 0x3f800000;
                    _DAT_10051010 = *(undefined4 *)(in_ECX + 0x9c);
                    _DAT_10051014 = *(undefined4 *)(in_ECX + 0xa4);
                    _DAT_10051018 = 0;
                    _DAT_1005101c = 0;
                    _DAT_10051028 = 0;
                    _DAT_1005102c = 0x3f800000;
                    ExceptionList = local_10;
                    _DAT_10051020 = DAT_10050f00;
                    _DAT_10051024 = DAT_10050f04;
                    __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
                    return;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_1000a3d8:
  FUN_100053a0(iVar5);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_94,(ThrowInfo *)&DAT_1004a24c);
}

