
/* public: class PostProcessOptionManager & __thiscall PostProcessOptionManager::operator=(class
   PostProcessOptionManager &&) */

PostProcessOptionManager * __thiscall
PostProcessOptionManager::operator=
          (PostProcessOptionManager *this,PostProcessOptionManager *param_1)

{
                    /* 0x5780  81  ??4PostProcessOptionManager@@QAEAAV0@$$QAV0@@Z */
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  this[0x10] = param_1[0x10];
  this[0x11] = param_1[0x11];
  return this;
}

