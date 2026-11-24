
/* Library Function - Single Match
    __trandisp1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __trandisp1(void)

{
  byte bVar1;
  float10 fVar2;
  char cVar3;
  undefined4 in_ECX;
  int in_EDX;
  undefined2 uVar4;
  int unaff_EBP;
  float10 in_ST0;
  
  if (*(char *)(in_EDX + 0xe) == '\x05') {
    uVar4 = (undefined2)
            CONCAT31((uint3)((byte)((ushort)*(undefined2 *)(unaff_EBP + -0xa4) >> 8) & 0xfe | 2),
                     0x3f);
  }
  else {
    uVar4 = 0x133f;
  }
  *(undefined2 *)(unaff_EBP + -0xa2) = uVar4;
  fVar2 = (float10)0;
  *(int *)(unaff_EBP + -0x94) = in_EDX;
  *(ushort *)(unaff_EBP + -0xa0) =
       (ushort)NAN(in_ST0) << 8 | (ushort)(in_ST0 < fVar2) << 9 | (ushort)(in_ST0 != fVar2) << 10 |
       (ushort)(in_ST0 == fVar2) << 0xe;
  *(undefined1 *)(unaff_EBP + -0x90) = 0;
  cVar3 = (char)(*(char *)(unaff_EBP + -0x9f) << 1) >> 1;
  bVar1 = cVar3 << 1;
  cVar3 = (&DAT_0071bf3e)[bVar1 & 0xf | cVar3 < '\0'];
  guard_check_icall(CONCAT31((int3)((uint)in_ECX >> 8),bVar1) & 0x404);
                    /* WARNING: Could not recover jumptable at 0x006f2d33. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(in_EDX + cVar3 + 0x10))();
  return;
}

