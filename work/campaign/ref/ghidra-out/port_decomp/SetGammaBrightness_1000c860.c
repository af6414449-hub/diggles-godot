
/* public: bool __thiscall GammaManager::SetGammaBrightness(float,float) */

bool __thiscall GammaManager::SetGammaBrightness(GammaManager *this,float param_1,float param_2)

{
                    /* 0xc860  241  ?SetGammaBrightness@GammaManager@@QAE_NMM@Z */
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  *(float *)this = param_1 / 100.0 + param_1 / 100.0 + 0.3;
  *(float *)(this + 4) = param_2 / 100.0 - 0.5;
  return true;
}

