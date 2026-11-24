
/* Library Function - Single Match
    public: __thiscall std::bad_exception::bad_exception(void)
   
   Library: Visual Studio 2019 Release */

bad_exception * __thiscall std::bad_exception::bad_exception(bad_exception *this)

{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(char **)(this + 4) = "bad exception";
  *(undefined ***)this = vftable;
  return this;
}

