
/* Library Function - Single Match
    public: virtual void * __thiscall TMPCT::`scalar deleting destructor'(unsigned int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void * __thiscall TMPCT::_scalar_deleting_destructor_(ViWinChat *this,uint param_2)

{
  *(undefined ***)this = ViWinChat::vftable;
  FUN_00504770();
  if ((param_2 & 1) != 0) {
    FUN_006cecd8(this,0xd0);
  }
  return this;
}

