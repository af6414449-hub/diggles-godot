
/* public: void __thiscall AchievementManager::CheckTriggerName(char const *) */

void __thiscall AchievementManager::CheckTriggerName(AchievementManager *this,char *param_1)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  AchID AVar4;
  byte *pbVar5;
  uint uVar6;
  byte *pbVar7;
  size_t _MaxCount;
  uint uVar8;
  char *pcVar9;
  undefined4 ****ppppuVar10;
  undefined4 in_EDX;
  byte *pbVar11;
  uint uVar12;
  bool bVar13;
  undefined4 *local_34;
  undefined4 ***local_2c [4];
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x3290  103  ?CheckTriggerName@AchievementManager@@QAEXPBD@Z */
  local_8 = 0xffffffff;
  puStack_c = &LAB_1004170d;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  local_1c = 0;
  local_18 = 0xf;
  local_2c[0] = (undefined4 ***)((uint)local_2c[0] & 0xffffff00);
  pcVar9 = param_1;
  do {
    cVar1 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar1 != '\0');
  FUN_10003a00(param_1,(int)pcVar9 - (int)(param_1 + 1));
  local_8 = 0;
  local_34 = &DAT_10050c80;
  do {
    pbVar3 = (byte *)*local_34;
    AVar4 = local_34[1];
    pbVar11 = pbVar3;
    do {
      bVar2 = *pbVar11;
      pbVar11 = pbVar11 + 1;
    } while (bVar2 != 0);
    uVar12 = (int)pbVar11 - (int)(pbVar3 + 1);
    ppppuVar10 = local_2c;
    if (0xf < local_18) {
      ppppuVar10 = (undefined4 ****)local_2c[0];
    }
    if (uVar12 <= local_1c) {
      if (uVar12 == 0) {
LAB_1000342f:
        if (this[AVar4 + 0x58] == (AchievementManager)0x0) {
          Store(this,AVar4,0);
        }
      }
      else {
        bVar2 = *pbVar3;
        _MaxCount = (local_1c - uVar12) + 1;
        for (pbVar11 = (byte *)memchr(ppppuVar10,(int)(char)bVar2,_MaxCount); pbVar5 = pbVar3,
            pbVar7 = pbVar11, uVar8 = uVar12, pbVar11 != (byte *)0x0;
            pbVar11 = (byte *)memchr(pbVar11 + 1,(int)(char)bVar2,
                                     (int)ppppuVar10 + (_MaxCount - (int)(pbVar11 + 1)))) {
          while (uVar6 = uVar8 - 4, 3 < uVar8) {
            if (*(int *)pbVar7 != *(int *)pbVar5) goto LAB_10003386;
            pbVar5 = pbVar5 + 4;
            pbVar7 = pbVar7 + 4;
            uVar8 = uVar6;
          }
          if (uVar6 == 0xfffffffc) {
LAB_100033ba:
            uVar8 = 0;
          }
          else {
LAB_10003386:
            bVar13 = *pbVar7 < *pbVar5;
            if ((*pbVar7 == *pbVar5) &&
               ((uVar6 == 0xfffffffd ||
                ((bVar13 = pbVar7[1] < pbVar5[1], pbVar7[1] == pbVar5[1] &&
                 ((uVar6 == 0xfffffffe ||
                  ((bVar13 = pbVar7[2] < pbVar5[2], pbVar7[2] == pbVar5[2] &&
                   ((uVar6 == 0xffffffff || (bVar13 = pbVar7[3] < pbVar5[3], pbVar7[3] == pbVar5[3])
                    ))))))))))) goto LAB_100033ba;
            uVar8 = -(uint)bVar13 | 1;
          }
          if (uVar8 == 0) {
            if ((int)pbVar11 - (int)ppppuVar10 != -1) goto LAB_1000342f;
            break;
          }
        }
      }
    }
    local_34 = local_34 + 2;
    if (0x10050cbf < (int)local_34) {
      if (0xf < local_18) {
        uVar12 = local_18 + 1;
        ppppuVar10 = (undefined4 ****)local_2c[0];
        if (0xfff < uVar12) {
          ppppuVar10 = (undefined4 ****)local_2c[0][-1];
          uVar12 = local_18 + 0x24;
          if (0x1f < (uint)((int)local_2c[0] + (-4 - (int)ppppuVar10))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
        }
        FUN_100402ac(ppppuVar10,uVar12);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

