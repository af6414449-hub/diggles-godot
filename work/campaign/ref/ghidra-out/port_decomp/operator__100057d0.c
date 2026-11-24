
/* public: class DisplayModeManager & __thiscall DisplayModeManager::operator=(class
   DisplayModeManager &&) */

DisplayModeManager * __thiscall
DisplayModeManager::operator=(DisplayModeManager *this,DisplayModeManager *param_1)

{
                    /* 0x57d0  60  ??4DisplayModeManager@@QAEAAV0@$$QAV0@@Z */
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  this[8] = param_1[8];
  return this;
}

