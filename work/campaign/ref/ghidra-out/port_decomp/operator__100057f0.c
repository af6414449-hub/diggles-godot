
/* public: class DisplayIndexManager & __thiscall DisplayIndexManager::operator=(class
   DisplayIndexManager const &) */

DisplayIndexManager * __thiscall
DisplayIndexManager::operator=(DisplayIndexManager *this,DisplayIndexManager *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
                    /* 0x57f0  59  ??4DisplayIndexManager@@QAEAAV0@ABV0@@Z */
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0xc) = uVar3;
  *(undefined8 *)(this + 0x10) = *(undefined8 *)(param_1 + 0x10);
  return this;
}

