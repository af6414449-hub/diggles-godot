
void __thiscall CFluid__Tick(CFluid *this)

{
  FILE *_File;
  size_t sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_stack_00000004;
  int in_stack_00000008;
  int *in_stack_0000000c;
  undefined4 uVar6;
  undefined2 local_34 [2];
  int local_30;
  int local_2c;
  FILE *local_28;
  int local_24;
  int local_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  
  _File = _fopen((char *)(*in_stack_0000000c + 0xc),"rb");
  if ((((_File != (FILE *)0x0) &&
       (local_28 = _File, sVar1 = _fread(&local_24,1,4,_File), sVar1 != 0)) &&
      (local_24 == 0x4c324d)) &&
     ((sVar1 = _fread(&local_30,1,4,_File), sVar1 != 0 &&
      (sVar1 = _fread(&local_2c,1,4,_File), sVar1 != 0)))) {
    iVar2 = local_30;
    if (in_stack_00000008 < local_2c + in_stack_00000008) {
      iVar3 = local_30 + in_stack_00000004;
      iVar5 = in_stack_00000008;
      do {
        iVar4 = in_stack_00000004;
        if (in_stack_00000004 < iVar3) {
          do {
            _fread(local_34,1,2,local_28);
            iVar2 = FUN_00592f10(PTR_0077241c);
            iVar4 = iVar4 + 1;
            *(undefined2 *)(iVar2 + 0x14) = local_34[0];
            iVar3 = in_stack_00000004 + local_30;
            iVar2 = local_30;
          } while (iVar4 < iVar3);
        }
        iVar5 = iVar5 + 1;
        _File = local_28;
      } while (iVar5 < local_2c + in_stack_00000008);
    }
    uVar6 = 0x10;
    iVar3 = in_stack_00000004 * 8 + -8;
    iVar4 = (local_2c + in_stack_00000008) * 8;
    iVar5 = in_stack_00000008 * 8 + -8;
    iVar2 = (iVar2 + in_stack_00000004) * 8;
    local_20 = iVar3;
    iStack_1c = iVar5;
    iStack_18 = iVar2;
    iStack_14 = iVar4;
    FUN_005a3dd0(in_stack_00000004,iVar3,iVar5,iVar2,iVar4,0x10);
    FUN_005a3fd0(iVar3,iVar5,iVar2,iVar4,uVar6);
    _fclose(_File);
  }
  return;
}

