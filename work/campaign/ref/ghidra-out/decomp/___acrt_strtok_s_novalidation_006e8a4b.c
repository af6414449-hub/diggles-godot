
/* Library Function - Single Match
    ___acrt_strtok_s_novalidation
   
   Library: Visual Studio 2019 Release */

void ___acrt_strtok_s_novalidation(byte *param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  code *pcVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  byte abStack_28 [32];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  uVar3 = 0;
  bVar5 = true;
  do {
    if (!bVar5) {
      ___report_rangecheckfailure();
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    abStack_28[uVar3] = 0;
    uVar3 = uVar3 + 1;
    bVar5 = uVar3 < 0x20;
  } while ((int)uVar3 < 0x20);
  do {
    bVar1 = *param_2;
    param_2 = param_2 + 1;
    abStack_28[bVar1 >> 3] = abStack_28[bVar1 >> 3] | (byte)(1 << (bVar1 & 7));
  } while (bVar1 != 0);
  if (param_1 == (byte *)0x0) {
    param_1 = (byte *)*param_3;
  }
  bVar1 = abStack_28[*param_1 >> 3] & (byte)(1 << (*param_1 & 7));
  while ((bVar1 != 0 && (*param_1 != 0))) {
    param_1 = param_1 + 1;
    bVar1 = abStack_28[*param_1 >> 3] & (byte)(1 << (*param_1 & 7));
  }
  bVar1 = *param_1;
  do {
    pbVar4 = param_1;
    if (bVar1 == 0) {
LAB_006e8b13:
      *param_3 = pbVar4;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    pbVar4 = param_1 + 1;
    if ((abStack_28[*param_1 >> 3] & (byte)(1 << (*param_1 & 7))) != 0) {
      *param_1 = 0;
      goto LAB_006e8b13;
    }
    bVar1 = *pbVar4;
    param_1 = pbVar4;
  } while( true );
}

