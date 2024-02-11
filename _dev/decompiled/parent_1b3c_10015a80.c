
int ** __thiscall FUN_10015a80(void *this,undefined4 *param_1,uint param_2,uint param_3)

{
  code *pcVar1;
  uint uVar2;
  int **ppiVar3;
  void *pvVar4;
  int iVar5;
  
  if ((uint)param_1[4] < param_2) {
    FUN_106f03ef("invalid string position");
  }
  else {
    uVar2 = param_1[4] - param_2;
    iVar5 = *(int *)((int)this + 0x10);
    if (uVar2 < param_3) {
      param_3 = uVar2;
    }
    if (param_3 < -iVar5 - 1U) {
      if ((param_3 != 0) &&
         (uVar2 = FUN_1000aaf0(this,(void **)(iVar5 + param_3),'\0'), (char)uVar2 != '\0')) {
        if (0xf < (uint)param_1[5]) {
          param_1 = (undefined4 *)*param_1;
        }
        pvVar4 = this;
        if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          pvVar4 = *this;
        }
        if (param_3 != 0) {
          FID_conflict__memcpy
                    ((void *)(*(int *)((int)this + 0x10) + (int)pvVar4),
                     (void *)(param_2 + (int)param_1),param_3);
        }
        iVar5 = iVar5 + param_3;
        *(int *)((int)this + 0x10) = iVar5;
        if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
          *(undefined *)(*this + iVar5) = 0;
          return (int **)this;
        }
        *(undefined *)((int)this + iVar5) = 0;
      }
      return (int **)this;
    }
  }
  FUN_106f03c1("string too long");
  pcVar1 = (code *)swi(3);
  ppiVar3 = (int **)(*pcVar1)();
  return ppiVar3;
}

