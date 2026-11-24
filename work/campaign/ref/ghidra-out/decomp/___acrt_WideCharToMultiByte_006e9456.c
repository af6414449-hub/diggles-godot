
/* Library Function - Single Match
    ___acrt_WideCharToMultiByte
   
   Library: Visual Studio 2019 Release */

void ___acrt_WideCharToMultiByte
               (uint param_1,uint param_2,LPCWSTR param_3,int param_4,LPSTR param_5,int param_6,
               uint param_7,uint param_8)

{
  byte bVar1;
  DWORD dwFlags;
  bool bVar2;
  
  dwFlags = 0;
  if ((param_1 == 65000) || (bVar1 = 0, param_1 == 0xfde9)) {
    bVar1 = 1;
  }
  if (param_1 < 0xc436) {
    if ((param_1 == 0xc435) || (param_1 == 0x2a)) goto LAB_006e94d0;
    if (0xc42b < param_1) {
      if ((param_1 < 0xc42f) || (param_1 == 0xc431)) goto LAB_006e94d0;
      bVar2 = param_1 == 0xc433;
LAB_006e94c5:
      if (bVar2) goto LAB_006e94d0;
    }
  }
  else {
    if (param_1 == 0xd698) goto LAB_006e94d0;
    if (0xdea9 < param_1) {
      if ((param_1 < 0xdeb4) || (param_1 == 65000)) goto LAB_006e94d0;
      bVar2 = param_1 == 0xfde9;
      goto LAB_006e94c5;
    }
  }
  dwFlags = param_2 & 0xffffff7f;
LAB_006e94d0:
  WideCharToMultiByte(param_1,dwFlags,param_3,param_4,param_5,param_6,
                      (LPCSTR)(~-(uint)bVar1 & param_7),(LPBOOL)(~-(uint)bVar1 & param_8));
  return;
}

