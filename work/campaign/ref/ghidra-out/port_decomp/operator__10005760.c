
/* public: class PostProcessOptionManager & __thiscall PostProcessOptionManager::operator=(class
   PostProcessOptionManager const &) */

PostProcessOptionManager * __thiscall
PostProcessOptionManager::operator=
          (PostProcessOptionManager *this,PostProcessOptionManager *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
                    /* 0x5760  82  ??4PostProcessOptionManager@@QAEAAV0@ABV0@@Z */
  uVar1 = *(undefined4 *)(param_1 + 4);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = uVar1;
  *(undefined4 *)(this + 8) = uVar2;
  *(undefined4 *)(this + 0xc) = uVar3;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  return this;
}

