
int ** __thiscall FUN_1000a8e0(void *this,int **param_1,void **param_2)

{
  uint uVar1;
  code *pcVar2;
  int **ppiVar3;
  void *pvVar4;
  
  if (param_1 != (int **)0x0) {
    uVar1 = *(uint *)((int)this + 0x14);
    ppiVar3 = (int **)this;
    if (0xf < uVar1) {
                    /* WARNING: Load size is inaccurate */
      ppiVar3 = *this;
    }
    if (ppiVar3 <= param_1) {
      pvVar4 = this;
      if (0xf < uVar1) {
                    /* WARNING: Load size is inaccurate */
        pvVar4 = *this;
      }
      if (param_1 < (int **)(*(int *)((int)this + 0x10) + (int)pvVar4)) {
        if (0xf < uVar1) {
                    /* WARNING: Load size is inaccurate */
          ppiVar3 = FUN_1000a700(this,(int **)this,(int *)((int)param_1 - *this),param_2);
          return ppiVar3;
        }
        ppiVar3 = FUN_1000a700(this,(int **)this,(int *)((int)param_1 - (int)this),param_2);
        return ppiVar3;
      }
    }
  }
  if (param_2 == (void **)0xffffffff) {
    FUN_106f03c1("string too long");
    pcVar2 = (code *)swi(3);
    ppiVar3 = (int **)(*pcVar2)();
    return ppiVar3;
  }
  if (*(void ***)((int)this + 0x14) < param_2) {
    FUN_1000abe0(this,param_2,*(void **)((int)this + 0x10));
    if (param_2 == (void **)0x0) {
      return (int **)this;
    }
  }
  else if (param_2 == (void **)0x0) {
    *(undefined4 *)((int)this + 0x10) = 0;
    if ((void **)0xf < *(void ***)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
      **this = 0;
      return (int **)this;
    }
    *(undefined *)this = 0;
    return (int **)this;
  }
  pvVar4 = this;
  if (0xf < *(uint *)((int)this + 0x14)) {
                    /* WARNING: Load size is inaccurate */
    pvVar4 = *this;
  }
  if (param_2 != (void **)0x0) {
    FID_conflict__memcpy(pvVar4,param_1,(size_t)param_2);
  }
  *(void ***)((int)this + 0x10) = param_2;
  if (*(uint *)((int)this + 0x14) < 0x10) {
    *(undefined *)((int)this + (int)param_2) = 0;
    return (int **)this;
  }
                    /* WARNING: Load size is inaccurate */
  *(undefined *)(*this + (int)param_2) = 0;
  return (int **)this;
}

