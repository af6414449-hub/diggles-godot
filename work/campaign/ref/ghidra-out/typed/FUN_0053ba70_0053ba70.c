
void __thiscall FUN_0053ba70(ViWinSpeechText *this)

{
  uint uVar1;
  int *piVar2;
  code *extraout_ECX;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  ViWinSpeechText *pVVar7;
  int *local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007033cd;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (this->i_4c != 0) {
    piVar2 = *(int **)&this->field_0x20;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    iVar5 = piVar2[2];
    if (iVar5 == -1) {
      piVar4 = piVar2 + 3;
      do {
        iVar5 = *piVar4;
        piVar4 = (int *)((int)piVar4 + 1);
      } while ((char)iVar5 != '\0');
      iVar5 = (int)piVar4 - ((int)piVar2 + 0xd);
      piVar2[2] = iVar5;
    }
    local_8 = 0;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
      FUN_006ba940(uVar1);
    }
    local_8 = 0xffffffff;
    if (iVar5 != 0) {
      FUN_004ef860("bigbig");
      local_8 = 1;
      iVar5 = FUN_004efa10();
      local_14 = *(int *)(iVar5 + 0x200) + -2;
      uVar6 = 0;
      while( true ) {
        iVar5 = this->i_4c;
        if (3 < iVar5) {
          iVar5 = 3;
        }
        if (iVar5 <= (int)uVar6) break;
        pVVar7 = this + 1;
        if (uVar6 < 4) {
          pVVar7 = (ViWinSpeechText *)((int)&pVVar7->field_0x0 + uVar6 * 4);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_18 = *(undefined4 *)pVVar7;
        pcVar3 = RaiseException_exref;
        if ((uint)this->i_4c <= uVar6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pcVar3 = extraout_ECX;
        }
        iVar5 = local_14;
        local_20 = 5;
        local_1c = local_14;
        FUN_004fdff0(&local_20,*(int *)(this->i_48 + uVar6 * 4) + 0xc,&local_18,&local_2c,1,pcVar3);
        piVar2 = (int *)FUN_004ef240();
        if (local_24 == *piVar2) {
          if (local_28 == 0) goto LAB_0053bbbc;
        }
        else {
          local_28 = 0;
          local_24 = *piVar2;
LAB_0053bbbc:
          local_28 = FUN_004ef660(local_2c + 3);
        }
        local_14 = iVar5 + -2 + *(int *)(local_28 + 0x200);
        uVar6 = uVar6 + 1;
      }
      local_8 = 2;
      if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
        FUN_006ba940(uVar1);
      }
    }
  }
  ExceptionList = local_10;
  return;
}

