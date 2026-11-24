
/* public: class TimeManager & __thiscall TimeManager::operator=(class TimeManager &&) */

TimeManager * __thiscall TimeManager::operator=(TimeManager *this,TimeManager *param_1)

{
  undefined4 uVar1;
  TimeManager *pTVar2;
  int iVar3;
  int iVar4;
  
                    /* 0x161f0  85  ??4TimeManager@@QAEAAV0@$$QAV0@@Z */
  iVar3 = (int)param_1 - (int)this;
  iVar4 = 0x100;
  pTVar2 = this;
  do {
    uVar1 = *(undefined4 *)(pTVar2 + 8 + iVar3 + -4);
    *(undefined4 *)pTVar2 = *(undefined4 *)(pTVar2 + iVar3);
    *(undefined4 *)(pTVar2 + 4) = uVar1;
    iVar4 = iVar4 + -1;
    pTVar2 = pTVar2 + 8;
  } while (iVar4 != 0);
  iVar4 = 0x100;
  pTVar2 = this + 0x800;
  do {
    uVar1 = *(undefined4 *)(pTVar2 + iVar3 + 4);
    *(undefined4 *)pTVar2 = *(undefined4 *)(pTVar2 + iVar3);
    *(undefined4 *)(pTVar2 + 4) = uVar1;
    iVar4 = iVar4 + -1;
    pTVar2 = pTVar2 + 8;
  } while (iVar4 != 0);
  *(undefined4 *)(this + 0x1000) = *(undefined4 *)(param_1 + 0x1000);
  return this;
}

