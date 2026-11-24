
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    public: void __thiscall <lambda_b57350f2640456a0859d250846f69caf>::operator()(void)const 
   
   Library: Visual Studio 2019 Release */

void __thiscall
<lambda_b57350f2640456a0859d250846f69caf>::operator()
          (<lambda_b57350f2640456a0859d250846f69caf> *this)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  ushort *puVar5;
  bool bVar6;
  
  __copytlocinfo_nolock(**(undefined4 **)this,*(undefined4 *)(**(int **)(this + 4) + 0x4c));
  iVar2 = __wsetlocale_nolock(**(undefined4 **)this,**(undefined4 **)(this + 0xc),
                              **(undefined4 **)(this + 0x10));
  **(int **)(this + 8) = iVar2;
  if (iVar2 == 0) {
    ___acrt_release_locale_ref(**(undefined4 **)this);
    ___acrt_free_locale(**(undefined4 **)this);
  }
  else {
    puVar3 = (ushort *)**(undefined4 **)(this + 0x10);
    if (puVar3 != (ushort *)0x0) {
      puVar5 = &DAT_007672d8;
      do {
        uVar1 = *puVar3;
        bVar6 = uVar1 < *puVar5;
        if (uVar1 != *puVar5) {
LAB_006e1c0c:
          uVar4 = -(uint)bVar6 | 1;
          goto LAB_006e1c10;
        }
        if (uVar1 == 0) break;
        uVar1 = puVar3[1];
        bVar6 = uVar1 < puVar5[1];
        if (uVar1 != puVar5[1]) goto LAB_006e1c0c;
        puVar3 = puVar3 + 2;
        puVar5 = puVar5 + 2;
      } while (uVar1 != 0);
      uVar4 = 0;
LAB_006e1c10:
      if (uVar4 != 0) {
        LOCK();
        DAT_00769d54 = 1;
        UNLOCK();
      }
    }
    __updatetlocinfoEx_nolock(**(int **)(this + 4) + 0x4c,**(undefined4 **)this);
    ___acrt_release_locale_ref(**(undefined4 **)this);
    if (((*(byte *)(**(int **)(this + 4) + 0x350) & 2) == 0) && (((byte)DAT_007673b0 & 1) == 0)) {
      __updatetlocinfoEx_nolock(&DAT_00769d78,*(undefined4 *)(**(int **)(this + 4) + 0x4c));
      PTR_PTR_00767928 = (undefined *)DAT_00769d78[0x22];
      PTR_DAT_0076731c = (undefined *)*DAT_00769d78;
      _DAT_007672dc = DAT_00769d78[1];
      return;
    }
  }
  return;
}

