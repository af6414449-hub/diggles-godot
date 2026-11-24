
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004cde30(CSceneRenderer *this)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint in_stack_00000004;
  int **ppiVar6;
  int *local_2c;
  int *local_28;
  uint *local_24;
  int *local_20;
  int local_1c;
  int local_18;
  CSceneRenderer *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006febf5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = this;
  piVar2 = (int *)FUN_006ba810(0x19,DAT_0076700c ^ (uint)&stack0xfffffffc);
  piVar2[1] = 0x24;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x61746164;
  piVar2[4] = 0x6f72672f;
  piVar2[5] = 0x2f646e75;
  piVar2[6] = 0x61746564;
  piVar2[7] = 0x352f6c69;
  piVar2[8] = 0x72475030;
  piVar2[9] = 0x742e7961;
  *(undefined2 *)(piVar2 + 10) = 0x6167;
  *(undefined1 *)((int)piVar2 + 0x2a) = 0;
  piVar2[2] = 0x1e;
  *piVar2 = 1;
  ppiVar6 = &local_2c;
  local_8 = 0;
  local_2c = piVar2;
  FUN_0044d010(ppiVar6);
  uVar3 = FUN_0044bf20(ppiVar6);
  local_14->defaultTexture = uVar3;
  local_8 = 1;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  puVar1 = local_14->variants;
  local_14->sceneTime = in_stack_00000004;
  local_20 = (int *)0x0;
  in_stack_00000004 = 0;
  do {
    if (in_stack_00000004 < 0x52) {
      *(undefined4 *)((int)local_14->textureIndex + (int)local_20) = 0xffffffff;
      puVar4 = (uint *)((int)local_20 + (int)puVar1);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_14->textureIndex[0] = 0xffffffff;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = puVar1;
    }
    in_stack_00000004 = in_stack_00000004 + 1;
    *puVar4 = 0;
    local_20 = (int *)((int)local_20 + 4);
  } while ((int)in_stack_00000004 < 0x51);
  _DAT_0077234c = 0;
  _DAT_00772348 = 0;
  local_8 = 2;
  FUN_00449180();
  local_20 = (int *)0x0;
  do {
    local_1c = 0;
    local_2c = local_20;
    do {
      local_18 = 0;
      piVar2 = local_2c;
      do {
        iVar5 = 0;
        local_28 = piVar2;
        do {
          if (piVar2 < (int *)0x52) {
            local_14->textureIndex[(int)piVar2] = 0;
            local_24 = local_14->variants + (int)piVar2;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_14->textureIndex[0] = 0;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_24 = local_14->variants;
          }
          uVar3 = FUN_004cd020(local_14);
          iVar5 = iVar5 + 1;
          piVar2 = (int *)((int)piVar2 + 0x1b);
          *local_24 = uVar3;
        } while (iVar5 < 3);
        local_18 = local_18 + 1;
        piVar2 = (int *)((int)local_28 + 9);
      } while (local_18 < 3);
      local_1c = local_1c + 1;
      local_2c = (int *)((int)local_2c + 3);
    } while (local_1c < 3);
    local_20 = (int *)((int)local_20 + 1);
  } while ((int)local_20 < 3);
  local_28 = piVar2;
  FUN_00449180();
  ExceptionList = local_10;
  return;
}

