
undefined4 __fastcall
FUN_1015bb40(char *param_1,uint param_2,void *param_3,void *param_4,uint *param_5)

{
  void **ppvVar1;
  int iVar2;
  uint uVar3;
  
  if (param_2 < 0x12) {
    return 0xffffffff;
  }
  if ((((*param_1 == 'N') && (param_1[1] == 'C')) && (param_1[2] == 'A')) && (param_1[3] == 'E')) {
    ppvVar1 = *(void ***)(param_1 + 4);
    uVar3 = (uint)(byte)param_1[0x10];
    if (param_2 != uVar3 + 0x11 + (int)ppvVar1) {
      return 0xfffffffd;
    }
    if (param_3 != (void *)0x0) {
      iVar2 = FUN_1015bad0((int)(param_1 + 0x11),uVar3,param_3);
      if (iVar2 != 0) {
        return 0xfffffffc;
      }
    }
    if (param_5 != (uint *)0x0) {
      *param_5 = (uint)*(ushort *)(param_1 + 0xe);
    }
    if (param_4 != (void *)0x0) {
      FUN_1000a8e0(param_4,(int **)(param_1 + uVar3 + 0x11),ppvVar1);
    }
    return 0;
  }
  return 0xfffffffe;
}

