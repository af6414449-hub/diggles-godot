
/* Library Function - Single Match
    int __cdecl common_fseek_nolock(class __crt_stdio_stream,__int64,int)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_fseek_nolock(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  bool bVar1;
  int *piVar2;
  int unaff_EDI;
  undefined8 uVar3;
  longlong lVar4;
  
  if (((uint)param_1[3] >> 0xd & 1) == 0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    return -1;
  }
  LOCK();
  param_1[3] = param_1[3] & 0xfffffff7;
  UNLOCK();
  bVar1 = common_fseek_binary_mode_read_only_fast_track_nolock(param_1,param_2,param_3,param_4);
  if (!bVar1) {
    if (param_4 == 1) {
      uVar3 = FUN_006de912(param_1);
      param_3 = param_3 + (int)((ulonglong)uVar3 >> 0x20) + (uint)CARRY4(param_2,(uint)uVar3);
      param_4 = 0;
    }
    ___acrt_stdio_flush_nolock(param_1);
    param_1[2] = 0;
    *param_1 = param_1[1];
    if (((uint)param_1[3] >> 2 & 1) == 0) {
      if ((((byte)param_1[3] & 0x41) == 0x41) && (((uint)param_1[3] >> 8 & 1) == 0)) {
        param_1[6] = 0x200;
      }
    }
    else {
      LOCK();
      param_1[3] = param_1[3] & 0xfffffffc;
      UNLOCK();
    }
    lVar4 = __lseeki64_nolock(param_1[4],CONCAT44(param_4,param_3),unaff_EDI);
    if (lVar4 == -1) {
      return -1;
    }
  }
  return 0;
}

