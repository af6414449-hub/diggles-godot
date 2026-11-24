
/* Library Function - Single Match
    private: bool __thiscall __crt_stdio_output::output_processor<char,class
   __crt_stdio_output::stream_output_adapter<char>,class
   __crt_stdio_output::standard_base<char,class __crt_stdio_output::stream_output_adapter<char> >
   >::state_case_type(void)
   
   Library: Visual Studio 2019 Release */

bool __thiscall
__crt_stdio_output::
output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
::state_case_type(output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                  *this)

{
  output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
  *poVar1;
  output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
  oVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int local_c;
  undefined4 local_8;
  
  oVar2 = this[0x31];
  local_8 = this;
  if ((char)oVar2 < 'e') {
    if (oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                  )0x64) {
LAB_006d3895:
      *(uint *)(this + 0x20) = *(uint *)(this + 0x20) | 0x10;
LAB_006d3899:
      uVar11 = 0;
      uVar10 = 10;
LAB_006d389c:
      cVar6 = type_case_integer(uVar10,uVar11);
    }
    else if ((char)oVar2 < 'Y') {
      if (oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                    )0x58) {
        uVar11 = 1;
LAB_006d3841:
        uVar10 = 0x10;
        goto LAB_006d389c;
      }
      if (oVar2 != (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                    )0x41) {
        if (oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                      )0x43) goto LAB_006d3855;
        if ((char)oVar2 < 'E') {
          return false;
        }
        if ('G' < (char)oVar2) {
          if (oVar2 != (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                        )0x53) {
            return false;
          }
          goto LAB_006d3829;
        }
      }
LAB_006d38a5:
      cVar6 = type_case_a();
    }
    else if (oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                       )0x5a) {
      cVar6 = type_case_Z();
    }
    else {
      if (oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                    )0x61) goto LAB_006d38a5;
      if (oVar2 != (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                    )0x63) {
        return false;
      }
LAB_006d3855:
      cVar6 = type_case_c_tchar(0);
    }
  }
  else if ((char)oVar2 < 'q') {
    if (oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                  )0x70) {
      cVar6 = type_case_p();
    }
    else {
      if ((char)oVar2 < 'h') goto LAB_006d38a5;
      if (oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                    )0x69) goto LAB_006d3895;
      if (oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                    )0x6e) {
        cVar6 = type_case_n();
      }
      else {
        if (oVar2 != (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                      )0x6f) {
          return false;
        }
        cVar6 = type_case_o();
      }
    }
  }
  else {
    if (oVar2 != (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                  )0x73) {
      if (oVar2 != (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                    )0x75) {
        if (oVar2 != (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                      )0x78) {
          return false;
        }
        uVar11 = 0;
        goto LAB_006d3841;
      }
      goto LAB_006d3899;
    }
LAB_006d3829:
    cVar6 = type_case_s();
  }
  if (cVar6 == '\0') {
    return false;
  }
  if (this[0x30] !=
      (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
       )0x0) {
    return true;
  }
  iVar8 = 0;
  local_8 = (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
             *)((uint)local_8 & 0xff000000);
  uVar3 = *(uint *)(this + 0x20);
  local_c = 0;
  if ((uVar3 >> 4 & 1) != 0) {
    if ((uVar3 >> 6 & 1) == 0) {
      if ((uVar3 & 1) == 0) {
        if ((uVar3 >> 1 & 1) != 0) {
          local_8 = (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                     *)CONCAT31(local_8._1_3_,0x20);
          iVar8 = 1;
          local_c = 1;
        }
        goto LAB_006d392b;
      }
      local_8 = (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                 *)CONCAT31(local_8._1_3_,0x2b);
    }
    else {
      local_8 = (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                 *)CONCAT31(local_8._1_3_,0x2d);
    }
    local_c = 1;
    iVar8 = 1;
  }
LAB_006d392b:
  oVar2 = this[0x31];
  if (((oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                  )0x78) ||
      (oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                 )0x58)) && ((uVar3 >> 5 & 1) != 0)) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if ((oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                 )0x61) ||
     (oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                )0x41)) {
    bVar5 = true;
  }
  else {
    bVar5 = false;
  }
  if ((bVar4) || (bVar5)) {
    *(undefined1 *)((int)&local_8 + iVar8) = 0x30;
    if ((oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                   )0x58) ||
       (oVar2 == (output_processor<char,class___crt_stdio_output::stream_output_adapter<char>,class___crt_stdio_output::standard_base<char,class___crt_stdio_output::stream_output_adapter<char>_>_>
                  )0x41)) {
      uVar7 = 0x58;
    }
    else {
      uVar7 = 0x78;
    }
    *(undefined1 *)((int)&local_8 + iVar8 + 1) = uVar7;
    iVar8 = iVar8 + 2;
    local_c = iVar8;
  }
  poVar1 = this + 0x18;
  iVar9 = (*(int *)(this + 0x24) - *(int *)(this + 0x38)) - iVar8;
  if (((byte)this[0x20] & 0xc) == 0) {
    write_multiple_characters<class___crt_stdio_output::stream_output_adapter<char>,char>
              ((stream_output_adapter<char> *)(this + 0x448),' ',iVar9,(int *)poVar1);
    iVar8 = local_c;
  }
  stream_output_adapter<char>::write_string
            ((stream_output_adapter<char> *)(this + 0x448),(char *)&local_8,iVar8,(int *)poVar1,
             (__crt_deferred_errno_cache *)(this + 0xc));
  if (((*(uint *)(this + 0x20) >> 3 & 1) != 0) && ((*(uint *)(this + 0x20) >> 2 & 1) == 0)) {
    write_multiple_characters<class___crt_stdio_output::stream_output_adapter<char>,char>
              ((stream_output_adapter<char> *)(this + 0x448),'0',iVar9,(int *)poVar1);
  }
  write_stored_string_tchar(0);
  if ((-1 < *(int *)poVar1) && ((*(uint *)(this + 0x20) >> 2 & 1) != 0)) {
    write_multiple_characters<class___crt_stdio_output::stream_output_adapter<char>,char>
              ((stream_output_adapter<char> *)(this + 0x448),' ',iVar9,(int *)poVar1);
  }
  return true;
}

