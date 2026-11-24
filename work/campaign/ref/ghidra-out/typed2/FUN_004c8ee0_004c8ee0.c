
void __thiscall FUN_004c8ee0(CSceneRenderer *this)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  iVar2 = this->holeHead;
  iVar3 = this->holeCapacity;
  if ((iVar2 != iVar3) || (this->flag4 != '\0')) {
    if (this->flag4 != '\0') {
      if (iVar2 < iVar3) {
        do {
          if ((iVar2 < 0) || (this->holeCount <= iVar2)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar1 = (int *)this->holesData;
            iVar2 = this->holeHead;
          }
          else {
            piVar1 = (int *)((int)this->holesData + iVar2 * 0x1c);
          }
          if (*piVar1 == -1) goto LAB_004c8fee;
          iVar2 = iVar2 + 1;
          this->holeHead = iVar2;
          iVar3 = this->holeCapacity;
        } while (iVar2 < iVar3);
      }
      this->flag4 = '\0';
      iVar2 = 0;
      this->holeHead = 0;
    }
    if (iVar2 < iVar3) {
      while( true ) {
        if ((iVar2 < 0) || (this->holeCount <= iVar2)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pvVar4 = this->holesData;
        }
        else {
          pvVar4 = (void *)((int)this->holesData + iVar2 * 0x1c);
        }
        if (2 < this->holeTail - *(int *)((int)pvVar4 + 0x18)) break;
        iVar2 = this->holeHead + 1;
        this->holeHead = iVar2;
        if (this->holeCapacity <= iVar2) {
          return;
        }
      }
LAB_004c8fee:
      FUN_004c8c60(this);
      this->holeHead = this->holeHead + 1;
    }
  }
  return;
}

