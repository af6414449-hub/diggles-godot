
/* Library Function - Single Match
    public: virtual void * __thiscall std::basic_stringbuf<char,struct std::char_traits<char>,class
   std::allocator<char> >::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2019 Release */

void * __thiscall
std::basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
_scalar_deleting_destructor_
          (basic_stringbuf<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this,
          uint param_1)

{
  FUN_00504770();
  if ((param_1 & 1) != 0) {
    FUN_006cecd8(this,0x44);
  }
  return this;
}

