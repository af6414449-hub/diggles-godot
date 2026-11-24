
/* public: class DisplayIndexManager & __thiscall DisplayIndexManager::operator=(class
   DisplayIndexManager &&) */

DisplayIndexManager * __thiscall
DisplayIndexManager::operator=(DisplayIndexManager *this,DisplayIndexManager *param_1)

{
                    /* 0x5810  58  ??4DisplayIndexManager@@QAEAAV0@$$QAV0@@Z */
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(this + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  this[0x14] = param_1[0x14];
  return this;
}

