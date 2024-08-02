
int ** __thiscall FUN_10015950(void *this,int **param_1,uint param_2)

{
  code *pcVar1;
  int **ppiVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  
  if (param_1 != (int **)0x0) {
    uVar3 = *(uint *)((int)this + 0x14);
    ppiVar2 = (int **)this;
    if (0xf < uVar3) {
                    /* WARNING: Load size is inaccurate */
      ppiVar2 = *this;
    }
    if (ppiVar2 <= param_1) {
      pvVar4 = this;
      if (0xf < uVar3) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      if (param_1 < (int **)(*(int *)((int)this + 0x10) + (int)pvVar4)) {
        if (uVar3 < 0x10) {
          ppiVar2 = FUN_10015a80(this,(undefined4 *)this,(int)param_1 - (int)this,param_2);
          return ppiVar2;
        }
                    /* WARNING: Load size is inaccurate */
        ppiVar2 = FUN_10015a80(this,(undefined4 *)this,(int)param_1 - *this,param_2);
        return ppiVar2;
      }
    }
  }
  iVar5 = *(int *)((int)this + 0x10);
  if (-iVar5 - 1U <= param_2) {
    FUN_106f03c1("string too long");
    pcVar1 = (code *)swi(3);
    ppiVar2 = (int **)(*pcVar1)();
    return ppiVar2;
  }
  if ((param_2 != 0) &&
     (uVar3 = FUN_1000aaf0(this,(void **)(iVar5 + param_2),'\0'), (char)uVar3 != '\0')) {
    pvVar4 = this;
    if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      pvVar4 = *this;
    }
    if (param_2 != 0) {
      FID_conflict__memcpy((void *)(*(int *)((int)this + 0x10) + (int)pvVar4),param_1,param_2);
    }
    iVar5 = iVar5 + param_2;
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

