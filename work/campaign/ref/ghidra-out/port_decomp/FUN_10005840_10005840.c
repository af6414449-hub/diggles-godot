
void FUN_10005840(void)

{
  int iVar1;
  int iVar2;
  undefined1 *pExceptionObject;
  int *in_ECX;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  int *extraout_ECX_02;
  int *piVar3;
  undefined4 in_EDX;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined1 local_1e0 [16];
  int local_1d0;
  undefined4 local_1cc;
  undefined1 local_1c8 [4];
  undefined8 local_1c4;
  undefined4 *local_1bc;
  int *local_1b8;
  undefined1 local_1b4 [296];
  undefined1 local_8c [44];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined4 local_38;
  int **local_34;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8._0_1_ = 0xff;
  local_8._1_3_ = 0xffffff;
  puStack_c = &LAB_10041887;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1cc = 0;
  local_2c = in_ECX;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  piVar3 = (int *)*in_ECX;
  if (piVar3 != (int *)0x0) {
    *in_ECX = 0;
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  iVar1 = CreateDXGIFactory1(&DAT_100447c4,in_ECX);
  if (-1 < iVar1) {
    piVar3 = extraout_ECX;
    if ((*(byte *)(in_ECX + 0x20) & 2) != 0) {
      local_1b8 = (int *)0x0;
      local_18 = (int *)0x0;
      local_8 = 0;
      iVar1 = (*(code *)**(undefined4 **)*in_ECX)((undefined4 *)*in_ECX,&DAT_10044804,&local_18);
      if (((iVar1 < 0) ||
          (iVar1 = (**(code **)(*local_18 + 0x70))(local_18,0,&local_1b8,4), iVar1 < 0)) ||
         (local_1b8 == (int *)0x0)) {
        in_ECX[0x20] = in_ECX[0x20] & 0xfffffffd;
      }
      piVar3 = local_18;
      local_8._0_1_ = 0xff;
      local_8._1_3_ = 0xffffff;
      if (local_18 != (int *)0x0) {
        local_18 = (int *)0x0;
        (**(code **)(*piVar3 + 8))(piVar3);
        piVar3 = extraout_ECX_00;
      }
    }
    if ((*(byte *)(in_ECX + 0x20) & 4) != 0) {
      local_18 = (int *)0x0;
      local_8 = 1;
      iVar1 = (*(code *)**(undefined4 **)*in_ECX)((undefined4 *)*in_ECX,&DAT_10044804,&local_18);
      piVar3 = local_18;
      if (iVar1 < 0) {
        in_ECX[0x20] = in_ECX[0x20] & 0xfffffffb;
      }
      local_8._0_1_ = 0xff;
      local_8._1_3_ = 0xffffff;
      if (local_18 != (int *)0x0) {
        local_18 = (int *)0x0;
        (**(code **)(*piVar3 + 8))(piVar3);
        piVar3 = extraout_ECX_01;
      }
    }
    if ((*(byte *)(in_ECX + 0x20) & 1) != 0) {
      local_18 = (int *)0x0;
      local_8 = 2;
      iVar1 = (*(code *)**(undefined4 **)*in_ECX)((undefined4 *)*in_ECX,&DAT_10044788,&local_18);
      piVar3 = local_18;
      if (iVar1 < 0) {
        in_ECX[0x20] = in_ECX[0x20] & 0xfffffffe;
      }
      local_8._0_1_ = 0xff;
      local_8._1_3_ = 0xffffff;
      if (local_18 != (int *)0x0) {
        local_18 = (int *)0x0;
        (**(code **)(*piVar3 + 8))(piVar3);
        piVar3 = extraout_ECX_02;
      }
    }
    piVar4 = (int *)0x0;
    do {
      if ((int)(&DAT_10044760)[(int)piVar4] < in_ECX[0x18]) break;
      piVar4 = (int *)((int)piVar4 + 1);
    } while (piVar4 < (int *)0x7);
    local_24 = piVar4;
    if (piVar4 == (int *)0x0) {
      FUN_10005340(piVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_1c4,(ThrowInfo *)&DAT_1004a26c);
    }
    local_8 = 3;
    puVar5 = (undefined4 *)0x0;
    local_1c4 = 0;
    local_1bc = (undefined4 *)0x0;
    local_1cc = 1;
    iVar1 = (**(code **)(*(int *)*in_ECX + 0x30))((int *)*in_ECX,0,&local_18);
    if (iVar1 != -0x7785fffe) {
      iVar1 = 0;
      do {
        (**(code **)(*local_18 + 0x28))(local_18,local_1b4);
        FUN_100028b0(&DAT_1416e610,0x100,"Enumerated adapter %d : %ls \n",iVar1,local_1b4);
        OutputDebugStringA(&DAT_1416e610);
        local_1d0 = 0;
        iVar2 = (**(code **)(*local_18 + 0x1c))(local_18,0,&local_1b8);
        iVar6 = local_1d0;
        while (iVar2 != -0x7785fffe) {
          (**(code **)(*local_1b8 + 0x1c))(local_1b8,local_8c);
          FUN_100028b0(&DAT_1416e610,0x100,"IDXGIOutput : name(%ls), \nrect(%d-%d, %d-%d)\n",
                       local_8c,local_50._4_4_,local_48._4_4_,(undefined4)local_48,
                       (undefined4)local_40);
          OutputDebugStringA(&DAT_1416e610);
          iVar6 = iVar6 + 1;
          iVar2 = (**(code **)(*local_18 + 0x1c))(local_18,iVar6,&local_1b8);
          in_ECX = local_2c;
        }
        if (puVar5 == local_1bc) {
          FUN_10007ea0(puVar5,&local_18);
          puVar5 = local_1c4._4_4_;
        }
        else {
          *puVar5 = local_18;
          local_1c4 = CONCAT44(puVar5 + 1,(undefined4)local_1c4);
          puVar5 = puVar5 + 1;
        }
        iVar1 = iVar1 + 1;
        iVar6 = (**(code **)(*(int *)*in_ECX + 0x30))((int *)*in_ECX,iVar1,&local_18);
        piVar4 = local_24;
      } while (iVar6 != -0x7785fffe);
    }
    FUN_10007af0();
    local_24 = (int *)0x0;
    local_8 = 4;
    FUN_10006900(&local_24);
    piVar3 = local_24;
    local_20 = (int *)0x0;
    local_1c = (int *)0x0;
    local_1b8 = (int *)0x80004005;
    if ((local_24 == (int *)0x0) ||
       (local_1b8 = (int *)D3D11CreateDevice(local_24,0,0,0x20,&DAT_10044760,piVar4,7,&local_20,
                                             in_ECX + 0x1a,&local_1c), (int)local_1b8 < 0)) {
      piVar4 = local_1c;
      local_8._0_1_ = 5;
      if (local_1c != (int *)0x0) {
        local_1c = (int *)0x0;
        (**(code **)(*piVar4 + 8))(piVar4);
      }
      piVar4 = local_20;
      local_8 = CONCAT31(local_8._1_3_,4);
      if (local_20 != (int *)0x0) {
        local_20 = (int *)0x0;
        (**(code **)(*piVar4 + 8))(piVar4);
      }
      local_8 = 0xffffffff;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(piVar3);
      }
LAB_10005d9c:
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_28 = (int *)0x0;
    local_8._0_1_ = 7;
    iVar1 = (**(code **)*local_20)(local_20,&DAT_100447f4,&local_28);
    if (-1 < iVar1) {
      local_18 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,8);
      iVar1 = (**(code **)*local_28)(local_28,&DAT_10044738,&local_18);
      if (-1 < iVar1) {
        local_34 = &local_2c;
        local_2c = (int *)0x37;
        local_60 = 0;
        local_58 = 0;
        local_50 = 0;
        local_48 = 0;
        local_40 = 0;
        local_38 = 1;
        (**(code **)(*local_18 + 0x30))(local_18,&local_60);
      }
      piVar4 = local_18;
      local_8._0_1_ = 7;
      if (local_18 != (int *)0x0) {
        local_18 = (int *)0x0;
        (**(code **)(*piVar4 + 8))(piVar4);
      }
    }
    piVar4 = (int *)in_ECX[1];
    if (piVar4 != (int *)0x0) {
      in_ECX[1] = 0;
      (**(code **)(*piVar4 + 8))(piVar4);
    }
    iVar1 = (**(code **)*local_20)(local_20,&DAT_10044728,in_ECX + 1);
    if (-1 < iVar1) {
      piVar4 = (int *)in_ECX[2];
      if (piVar4 != (int *)0x0) {
        in_ECX[2] = 0;
        (**(code **)(*piVar4 + 8))(piVar4);
      }
      iVar1 = (**(code **)*local_1c)(local_1c,&DAT_100447e4,in_ECX + 2);
      if (-1 < iVar1) {
        piVar4 = (int *)in_ECX[4];
        if (piVar4 != (int *)0x0) {
          in_ECX[4] = 0;
          (**(code **)(*piVar4 + 8))(piVar4);
        }
        iVar1 = (**(code **)*local_1c)(local_1c,&DAT_100447d4,in_ECX + 4);
        if (-1 < iVar1) {
          OutputDebugStringA(s_CreateDeviceResources_finished__10050090);
          piVar4 = local_28;
          local_8._0_1_ = 6;
          if (local_28 != (int *)0x0) {
            local_28 = (int *)0x0;
            (**(code **)(*piVar4 + 8))(piVar4);
          }
          piVar4 = local_1c;
          local_8._0_1_ = 5;
          if (local_1c != (int *)0x0) {
            local_1c = (int *)0x0;
            (**(code **)(*piVar4 + 8))(piVar4);
          }
          piVar4 = local_20;
          local_8 = CONCAT31(local_8._1_3_,4);
          if (local_20 != (int *)0x0) {
            local_20 = (int *)0x0;
            (**(code **)(*piVar4 + 8))(piVar4);
          }
          local_8 = 0xffffffff;
          (**(code **)(*piVar3 + 8))(piVar3);
          goto LAB_10005d9c;
        }
        FUN_100053a0(iVar1);
        pExceptionObject = local_1e0;
        goto LAB_10005dcf;
      }
    }
  }
  FUN_100053a0(iVar1);
  pExceptionObject = local_1c8;
LAB_10005dcf:
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(pExceptionObject,(ThrowInfo *)&DAT_1004a24c);
}

