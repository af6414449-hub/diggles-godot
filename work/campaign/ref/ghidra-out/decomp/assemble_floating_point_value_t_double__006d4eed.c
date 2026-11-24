
/* Library Function - Single Match
    enum SLD_STATUS __cdecl __crt_strtox::assemble_floating_point_value_t<double>(bool,int,unsigned
   __int64,double &)
   
   Library: Visual Studio 2019 Release */

SLD_STATUS __cdecl
__crt_strtox::assemble_floating_point_value_t<double>
          (bool param_1,int param_2,__uint64 param_3,double *param_4)

{
  *(uint *)((int)param_4 + 4) =
       (param_2 + 0x3ffU & 0x7ff | (uint)param_1 << 0xb) << 0x14 | param_3._4_4_ & 0xfffff;
  *(undefined4 *)param_4 = (undefined4)param_3;
  return 0;
}

