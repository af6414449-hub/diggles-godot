
/* Library Function - Single Match
    __trandisp2
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __trandisp2(void)

{
  byte bVar1;
  float10 fVar2;
  byte bVar3;
  char cVar4;
  byte bVar5;
  char cVar6;
  int in_EDX;
  undefined2 uVar7;
  int unaff_EBP;
  float10 in_ST0;
  float10 in_ST1;
  
  if (*(char *)(in_EDX + 0xe) == '\x05') {
    uVar7 = (undefined2)
            CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(unaff_EBP + -0xa4) >> 8) & 0xfe | 2),
                     0x3f);
  }
  else {
    uVar7 = 0x133f;
  }
  *(undefined2 *)(unaff_EBP + -0xa2) = uVar7;
  fVar2 = (float10)0;
  *(int *)(unaff_EBP + -0x94) = in_EDX;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)NAN(in_ST0) << 8 | (ushort)(in_ST0 < fVar2) << 9 | (ushort)(in_ST0 != fVar2) << 10 |
       (ushort)(in_ST0 == fVar2) << 0xe;
  *(undefined1 *)(unaff_EBP + -0x90) = 0;
  fVar2 = (float10)0;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)NAN(in_ST1) << 8 | (ushort)(in_ST1 < fVar2) << 9 | (ushort)(in_ST1 != fVar2) << 10 |
       (ushort)(in_ST1 == fVar2) << 0xe;
  cVar6 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;
  bVar1 = cVar6 << 1;
  cVar6 = (&DAT_0071bf3e)[bVar1 & 0xf | cVar6 < '\0'];
  cVar4 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;
  bVar5 = cVar4 << 1 | cVar4 < '\0';
  bVar3 = (&DAT_0071bf3e)[bVar5 & 0xf];
  guard_check_icall(CONCAT11(bVar1,bVar5) & 0x404);
                    /* WARNING: Could not recover jumptable at 0x006f2dcd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(in_EDX + (char)(bVar3 | cVar6 << 2) + 0x10))();
  return;
}

