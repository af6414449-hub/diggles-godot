
void __thiscall FUN_004c6030(CSceneRenderer *this)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fd6c5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (this->textureCount == 0) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
                    /* WARNING: Load size is inaccurate */
  if (((*this->textures != 0) && (this->wallVertexCount != 0)) && (this->wallIndexCount != 0)) {
    ppuVar5 = &local_14;
    FUN_0044d010(ppuVar5);
    FUN_0044d570(ppuVar5);
    puVar4 = local_14;
    local_8 = 0;
    if (local_14 != (undefined4 *)0x0) {
      local_14[3] = 4;
      local_14[2] = 10;
      local_14[4] = 0x11;
      local_14[5] = 0xff;
      puVar2 = (undefined4 *)FUN_0040b900();
      puVar4[0xf] = *puVar2;
      local_14[0xe] = 0;
      local_14[0xd] = 0;
      local_14[0xc] = 0;
      local_14[0xb] = 0;
      local_14[10] = 0;
      local_14[9] = 0;
      local_14[8] = 0;
      local_14[7] = 0;
      local_14[6] = 0;
      iVar3 = FUN_006ba810();
      if (iVar3 == 0) {
        puVar4 = (undefined4 *)local_14[0x11];
        local_14[0x11] = 0;
      }
      else {
        iVar3 = FUN_0045fae0();
        puVar4 = (undefined4 *)local_14[0x11];
        local_14[0x11] = iVar3;
        if (iVar3 != 0) {
          LOCK();
          *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + 1;
          UNLOCK();
        }
      }
      if (puVar4 != (undefined4 *)0x0) {
        LOCK();
        iVar3 = puVar4[1] + -1;
        puVar4[1] = iVar3;
        UNLOCK();
        if (iVar3 == 0) {
          (**(code **)*puVar4)();
        }
      }
      FUN_0043d740();
      FUN_0045fd00(0x1c2,this->wallVertexCount);
      FUN_004ce5d0();
      FUN_0045fe20(this->wallIndexCount);
      if (local_14 != (undefined4 *)0x0) {
        LOCK();
        local_14[1] = local_14[1] + 1;
        UNLOCK();
      }
      local_8._0_1_ = 1;
      FUN_0044d010();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0044d6e0();
      if (local_14 != (undefined4 *)0x0) {
        LOCK();
        piVar1 = local_14 + 1;
        iVar3 = *piVar1;
        *piVar1 = *piVar1 + -1;
        UNLOCK();
        if ((iVar3 == 1) && (local_14 != (undefined4 *)0x0)) {
          (**(code **)*local_14)();
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}

