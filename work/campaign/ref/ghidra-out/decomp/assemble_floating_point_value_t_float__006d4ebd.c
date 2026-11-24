
/* Library Function - Single Match
    enum SLD_STATUS __cdecl __crt_strtox::assemble_floating_point_value_t<float>(bool,int,unsigned
   __int64,float &)
   
   Library: Visual Studio 2019 Release */

SLD_STATUS __cdecl
__crt_strtox::assemble_floating_point_value_t<float>
          (bool param_1,int param_2,__uint64 param_3,float *param_4)

{
  *param_4 = (float)((param_2 + 0x7fU & 0xff) << 0x17 | (uint)param_1 << 0x1f |
                    (uint)param_3 & 0x7fffff);
  return 0;
}

