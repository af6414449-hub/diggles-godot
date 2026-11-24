
/* Library Function - Single Match
    public: __thiscall CPictureHolder::~CPictureHolder(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CPictureHolder::~CPictureHolder(CPictureHolder *this)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_006f9530;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005d8fc0(this);
  ExceptionList = local_10;
  return;
}

