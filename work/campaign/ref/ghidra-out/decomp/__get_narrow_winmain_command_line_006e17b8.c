
/* Library Function - Single Match
    __get_narrow_winmain_command_line
   
   Library: Visual Studio 2019 Release */

byte * __get_narrow_winmain_command_line(void)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  
  ___acrt_initialize_multibyte();
  pbVar4 = DAT_0076a208;
  if (DAT_0076a208 == (byte *)0x0) {
    pbVar4 = &DAT_00769d50;
  }
  bVar1 = false;
  do {
    bVar2 = *pbVar4;
    if (bVar2 < 0x21) {
      if (bVar2 == 0) {
        return pbVar4;
      }
      if (!bVar1) {
        do {
          if (0x20 < bVar2) {
            return pbVar4;
          }
          pbVar4 = pbVar4 + 1;
          bVar2 = *pbVar4;
        } while (bVar2 != 0);
        return pbVar4;
      }
    }
    if (bVar2 == 0x22) {
      bVar1 = !bVar1;
    }
    iVar3 = __ismbblead((uint)bVar2);
    if (iVar3 != 0) {
      pbVar4 = pbVar4 + 1;
    }
    pbVar4 = pbVar4 + 1;
  } while( true );
}

