
/* Library Function - Single Match
    public: double & __thiscall __crt_strtox::floating_point_value::as_double(void)const 
   
   Library: Visual Studio 2019 Release */

double * __thiscall __crt_strtox::floating_point_value::as_double(floating_point_value *this)

{
  if (this[4] != (floating_point_value)0x0) {
    return *(double **)this;
  }
                    /* WARNING: Subroutine does not return */
  __invoke_watson(L"_is_double",L"__crt_strtox::floating_point_value::as_double",
                  L"minkernel\\crts\\ucrt\\inc\\corecrt_internal_strtox.h",0x19f,0);
}

