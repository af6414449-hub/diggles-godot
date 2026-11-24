
/* Library Function - Single Match
    public: unsigned __int64 __thiscall
   __crt_strtox::floating_point_value::normal_mantissa_mask(void)const 
   
   Library: Visual Studio 2019 Release */

__uint64 __thiscall
__crt_strtox::floating_point_value::normal_mantissa_mask(floating_point_value *this)

{
  if (this[4] != (floating_point_value)0x0) {
    return 0x1fffffffffffff;
  }
  return 0xffffff;
}

