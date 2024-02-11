
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void __cdecl FUN_103ac270(undefined4 *param_1,void *param_2)

{
  char cVar1;
  uint uVar2;
  FILE *_File;
  uint uVar3;
  int *apiStack_10008 [16385];
  
  uVar2 = DAT_10a76ad0 ^ (uint)&stack0xfffffffc;
  cVar1 = FUN_103a5a60(param_1);
  if ((cVar1 == '\0') &&
     (_File = (FILE *)FUN_103ab5d0(param_1,(int **)&DAT_109d7320), _File != (FILE *)0x0)) {
    uVar3 = _fread(apiStack_10008,1,0x10000,_File);
    while (uVar3 != 0) {
      if (param_2 != (void *)0x0) {
        FUN_10015950(param_2,apiStack_10008,uVar3);
      }
      uVar3 = _fread(apiStack_10008,1,0x10000,_File);
    }
    _fclose(_File);
    FUN_10704e34(uVar2 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_10704e34(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

