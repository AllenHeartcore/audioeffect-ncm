
AudioEffects ** FUN_100455d0(void)

{
  LONG LVar1;
  AudioEffects **ppAVar2;
  void *local_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10810b9b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_10b2c35c == (AudioEffects **)0x0) ||
     (ppAVar2 = DAT_10b2c35c, DAT_10b2c35c == (AudioEffects **)0x1)) {
    LVar1 = InterlockedCompareExchange((LONG *)&DAT_10b2c35c,1,0);
    if (LVar1 == 0) {
      ppAVar2 = (AudioEffects **)FUN_10705677(0xc);
      local_8 = 0;
      if (ppAVar2 == (AudioEffects **)0x0) {
        ppAVar2 = (AudioEffects **)0x0;
      }
      else {
        ppAVar2 = FUN_10045380(ppAVar2);
      }
      local_8 = 0xffffffff;
      DAT_10b2c35c = ppAVar2;
      if (ppAVar2 != (AudioEffects **)0x0) {
        FUN_103a3b10(0x10045690,0);
      }
      ExceptionList = local_10;
      return ppAVar2;
    }
    ppAVar2 = (AudioEffects **)FUN_103ad690((int *)&DAT_10b2c35c);
  }
  ExceptionList = local_10;
  return ppAVar2;
}

