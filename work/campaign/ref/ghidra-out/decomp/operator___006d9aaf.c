
/* Library Function - Single Match
    public: __thiscall <lambda_6e4b09c48022b2350581041d5f6b0c4c>::operator()(void)const 
   
   Library: Visual Studio 2019 Release */

void __thiscall
<lambda_6e4b09c48022b2350581041d5f6b0c4c>::operator()
          (<lambda_6e4b09c48022b2350581041d5f6b0c4c> *this)

{
  byte bVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  uint uVar2;
  undefined *puVar3;
  
  FUN_006cf3b0(&DAT_00763320,8);
  if (DAT_00769b54 != '\0') goto LAB_006d9b60;
  LOCK();
  DAT_00769b4c = 1;
  UNLOCK();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)*extraout_ECX == 0) {
    bVar1 = (byte)DAT_0076700c & 0x1f;
    if (DAT_00769b50 != DAT_0076700c) {
      uVar2 = DAT_0076700c ^ DAT_00769b50;
      guard_check_icall(0,0,0);
      (*(code *)(uVar2 >> bVar1 | uVar2 << 0x20 - bVar1))();
    }
    puVar3 = &DAT_00769d30;
LAB_006d9b17:
    __execute_onexit_table(puVar3);
  }
  else if (*(int *)*extraout_ECX == 1) {
    puVar3 = &DAT_00769d3c;
    goto LAB_006d9b17;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  if (*(int *)*extraout_ECX == 0) {
    __initterm(&DAT_00715684,&DAT_00715694);
  }
  __initterm(&DAT_00715698,&DAT_0071569c);
  if (*(int *)extraout_ECX[1] == 0) {
    DAT_00769b54 = '\x01';
    *(undefined1 *)extraout_ECX[2] = 1;
  }
LAB_006d9b60:
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

