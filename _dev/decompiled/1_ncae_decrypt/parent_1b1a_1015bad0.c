
undefined4 __fastcall FUN_1015bad0(int param_1,uint param_2,void *param_3)

{
  byte bVar1;
  uint uVar2;
  byte local_5;
  
  if ((param_2 - 1 & 3) == 0) {
    bVar1 = *(byte *)(param_1 + 4);
    uVar2 = 0;
    if (param_2 != 0) {
      do {
        if ((uVar2 != 4) && (local_5 = *(byte *)(uVar2 + param_1) ^ bVar1, param_3 != (void *)0x0))
        {
          FUN_10015950(param_3,(int **)&local_5,1);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < param_2);
    }
    return 0;
  }
  return 0xffffffff;
}

