
void FUN_00507eb0(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int this;
  
  if (this->i_58 == 5) {
    puVar1 = *(undefined4 **)(this + 0x44);
    FUN_004ff900(puVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),*puVar1,
                 puVar1[1],0,0,3);
    return;
  }
  if (this->i_58 == 0) {
    if (this->c_5d == '\0') {
      piVar2 = *(int **)(this + 0x44);
    }
    else {
      piVar2 = *(int **)(this + 0x48);
    }
    if (((piVar2[2] != 0) && (0 < *piVar2)) && (0 < piVar2[1])) {
      FUN_004ff900(piVar2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),*piVar2,
                   piVar2[1],0,0,3);
    }
  }
  iVar3 = this->i_58;
  if (iVar3 == 1) {
    piVar2 = *(int **)(this + 0x48);
    if (piVar2[2] == 0) {
      return;
    }
    if (*piVar2 < 1) {
      return;
    }
    if (piVar2[1] < 1) {
      return;
    }
    FUN_004ff900(piVar2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),*piVar2,
                 piVar2[1],0,0,3);
    iVar3 = this->i_58;
  }
  if (((iVar3 == 2) || (iVar3 == 3)) &&
     ((piVar2 = *(int **)(this + 0x4c), piVar2[2] != 0 && ((0 < *piVar2 && (0 < piVar2[1])))))) {
    FUN_004ff900(piVar2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),*piVar2,
                 piVar2[1],0,0,3);
    iVar3 = this->i_58;
  }
  if ((((iVar3 == 4) && (piVar2 = *(int **)(this + 0x50), piVar2[2] != 0)) && (0 < *piVar2)) &&
     (0 < piVar2[1])) {
    FUN_004ff900(piVar2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),*piVar2,
                 piVar2[1],0,0,3);
  }
  return;
}

