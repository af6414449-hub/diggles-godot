
/* Library Function - Single Match
    ___acrt_MultiByteToWideChar
   
   Library: Visual Studio 2019 Release */

void ___acrt_MultiByteToWideChar
               (uint param_1,DWORD param_2,LPCSTR param_3,int param_4,LPWSTR param_5,int param_6)

{
  if (param_1 < 0xc436) {
    if (((param_1 != 0xc435) && (param_1 != 0x2a)) &&
       ((param_1 < 0xc42c || (((0xc42e < param_1 && (param_1 != 0xc431)) && (param_1 != 0xc433))))))
    goto LAB_006e88cc;
LAB_006e88e2:
    param_2 = 0;
  }
  else {
    if (param_1 != 0xd698) {
      if (param_1 < 0xdeaa) goto LAB_006e88cc;
      if ((param_1 < 0xdeb4) || (param_1 == 65000)) goto LAB_006e88e2;
      if (param_1 != 0xfde9) goto LAB_006e88cc;
    }
    param_2 = param_2 & 8;
  }
LAB_006e88cc:
  MultiByteToWideChar(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

