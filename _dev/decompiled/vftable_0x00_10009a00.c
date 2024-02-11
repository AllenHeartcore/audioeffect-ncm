
undefined __thiscall FUN_10009a00(void *this,int param_1,void *param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  void *pvVar9;
  void **ppvVar10;
  char *pcVar11;
  uint uVar12;
  int *piVar13;
  undefined uVar14;
  int iVar15;
  char *pcVar16;
  void *local_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100b30a6;
  local_10 = ExceptionList;
  uVar4 = DAT_10129088 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar5 = __Mtx_lock((_Mtx_internal_imp_t *)((int)this + 4));
  if (iVar5 != 0) {
    std::_Throw_C_error(iVar5);
  }
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if ((((*(int *)((int)this + 0x34) != 0) && (*(int *)((int)this + 0x48) == param_1)) &&
      (*(void **)((int)this + 0x50) == param_2)) && (*(int *)((int)this + 0x54) == param_3)) {
    FUN_1000bef0((int)this);
    puVar6 = *(undefined4 **)((int)this + 0x270);
    if (puVar6 != (undefined4 *)0x0) {
      (**(code **)*puVar6)(puVar6,"AudioEffects",2,"Reset audio effect instance done.",uVar4);
    }
    uVar14 = 1;
    goto LAB_1000a2b0;
  }
  *(undefined *)((int)this + 0x44) = 0;
  FUN_1000be70((int)this);
  puVar6 = (undefined4 *)NCAudioEffectsProcessor::Create();
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = *(undefined4 **)((int)this + 0x270);
    if (puVar6 != (undefined4 *)0x0) {
      pcVar16 = "Create audio effect instance failed.";
      goto LAB_10009cad;
    }
  }
  else {
    uVar7 = FUN_10009030(param_1);
    uVar4 = FUN_10010850(uVar7);
    *(uint *)((int)this + 0x58) = uVar4;
    if (param_4 == 0) {
      *(undefined4 *)((int)this + 0x4c) = 0x800;
      uVar4 = 0x800;
    }
    else {
      uVar4 = (uint)(((ulonglong)param_4 / (ulonglong)uVar4) / ZEXT48(param_2));
      uVar8 = uVar4 - 1 & uVar4;
      uVar12 = uVar4;
      if (uVar8 != 0) {
        uVar12 = uVar4 | uVar4 >> 1;
        uVar12 = uVar12 | uVar12 >> 2;
        uVar12 = uVar12 | uVar12 >> 4;
        uVar12 = uVar12 | uVar12 >> 8;
        uVar12 = (uVar12 | uVar12 >> 0x10) + 1 >> 1;
      }
      if (uVar12 < 0x800) {
        if (uVar8 != 0) {
          uVar4 = uVar4 | uVar4 >> 1;
          uVar4 = uVar4 | uVar4 >> 2;
          uVar4 = uVar4 | uVar4 >> 4;
          uVar4 = uVar4 | uVar4 >> 8;
          uVar4 = (uVar4 | uVar4 >> 0x10) + 1 >> 1;
          *(uint *)((int)this + 0x4c) = uVar4;
          goto LAB_10009b70;
        }
      }
      else {
        uVar4 = 0x800;
      }
      *(uint *)((int)this + 0x4c) = uVar4;
    }
LAB_10009b70:
    puVar1 = *(undefined4 **)((int)this + 0x270);
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)
                (puVar1,"AudioEffects",2,"Create new AudioEffects instance: %d, %u, %u, %u",uVar7,
                 param_3,param_2,uVar4);
      uVar4 = *(uint *)((int)this + 0x4c);
    }
    cVar3 = (**(code **)*puVar6)(uVar7,uVar4,param_2,param_3);
    if (cVar3 == '\0') {
      puVar6 = *(undefined4 **)((int)this + 0x270);
      if (puVar6 != (undefined4 *)0x0) {
        (**(code **)*puVar6)(puVar6,"AudioEffects",0,"Initialize audio effect instance failed.");
      }
    }
    else {
      *(undefined4 **)((int)this + 0x34) = puVar6;
      *(int *)((int)this + 0x48) = param_1;
      *(void **)((int)this + 0x50) = param_2;
      *(int *)((int)this + 0x54) = param_3;
      pvVar9 = (void *)FUN_1004f0b4(0x20);
      local_8._0_1_ = 1;
      if (pvVar9 == (void *)0x0) {
        ppvVar10 = (void **)0x0;
      }
      else {
        ppvVar10 = FUN_1000e0e0(pvVar9,*(void **)((int)this + 0x58),param_2,(void *)0x0,
                                *(void **)((int)this + 0x4c));
      }
      local_8._0_1_ = 0;
      uVar14 = (undefined)local_8;
      local_8._0_1_ = 0;
      *(void ***)((int)this + 0x38) = ppvVar10;
      if (ppvVar10 == (void **)0x0) {
        puVar6 = *(undefined4 **)((int)this + 0x270);
        local_8._0_1_ = uVar14;
        if (puVar6 != (undefined4 *)0x0) {
          pcVar16 = "Create in audio fifo failed.";
LAB_10009cad:
          (**(code **)*puVar6)(puVar6,"AudioEffects",0,pcVar16);
        }
      }
      else {
        pvVar9 = (void *)FUN_1004f0b4(0x20);
        local_8._0_1_ = 2;
        if (pvVar9 == (void *)0x0) {
          ppvVar10 = (void **)0x0;
        }
        else {
          ppvVar10 = FUN_1000e0e0(pvVar9,*(void **)((int)this + 0x58),param_2,(void *)0x0,
                                  *(void **)((int)this + 0x4c));
        }
        local_8._0_1_ = 0;
        *(void ***)((int)this + 0x3c) = ppvVar10;
        if (ppvVar10 == (void **)0x0) {
          puVar6 = *(undefined4 **)((int)this + 0x270);
          if (puVar6 != (undefined4 *)0x0) {
            pcVar16 = "Create out audio fifo failed.";
            goto LAB_10009cad;
          }
        }
        else {
          iVar5 = FUN_1007c814(*(int *)((int)this + 0x58) * *(int *)((int)this + 0x50) *
                               *(int *)((int)this + 0x4c));
          *(int *)((int)this + 0x40) = iVar5;
          if (iVar5 != 0) {
            puVar6 = *(undefined4 **)((int)this + 0x270);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x5d));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar16 = "true";
              if (*(char *)((int)this + 0x5d) == '\0') {
                pcVar16 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetLoudnessON: on %s",pcVar16);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x14))(param_3);
            if (*(char *)((int)this + 0x5d) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 0x18))
                        (*(undefined4 *)((int)this + 0x60),*(undefined4 *)((int)this + 100));
            }
            puVar6 = *(undefined4 **)((int)this + 0x270);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x68));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar16 = "true";
              if (*(char *)((int)this + 0x68) == '\0') {
                pcVar16 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetReverbON: on %s",pcVar16);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x1c))(param_3);
            if (*(char *)((int)this + 0x68) != '\0') {
              param_3 = CONCAT31(param_3._1_3_,*(undefined *)((int)this + 0x69));
              (**(code **)(**(int **)((int)this + 0x34) + 0x20))
                        (param_3,*(undefined4 *)((int)this + 0x6c),*(undefined4 *)((int)this + 0x70)
                         ,*(undefined4 *)((int)this + 0x74));
              (**(code **)(**(int **)((int)this + 0x34) + 0x24))((int)this + 0x78);
              param_3 = CONCAT31(param_3._1_3_,*(undefined *)((int)this + 0x98));
              (**(code **)(**(int **)((int)this + 0x34) + 0x28))(param_3);
              iVar15 = 0;
              iVar5 = (int)this + 0x9c;
              do {
                iVar15 = iVar15 + 1;
                (**(code **)(**(int **)((int)this + 0x34) + 0x2c))(iVar15,iVar5);
                iVar5 = iVar5 + 0x14;
              } while (iVar15 < 3);
              (**(code **)(**(int **)((int)this + 0x34) + 0x30))
                        (*(undefined4 *)((int)this + 0xd8),*(undefined4 *)((int)this + 0xdc));
              (**(code **)(**(int **)((int)this + 0x34) + 0x34))
                        (*(undefined4 *)((int)this + 0xe0),*(undefined4 *)((int)this + 0xe4),
                         *(undefined4 *)((int)this + 0xe8),*(undefined4 *)((int)this + 0xec));
              (**(code **)(**(int **)((int)this + 0x34) + 0x38))
                        (*(undefined4 *)((int)this + 0xf0),*(undefined4 *)((int)this + 0xf4),
                         *(undefined4 *)((int)this + 0xf8));
            }
            puVar6 = *(undefined4 **)((int)this + 0x270);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0xfc));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar16 = "true";
              if (*(char *)((int)this + 0xfc) == '\0') {
                pcVar16 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetStereoEnhancerON: on %s",pcVar16);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x3c))(param_3);
            if (*(char *)((int)this + 0xfc) != '\0') {
              FUN_1000c930(this,*(float *)((int)this + 0x100),*(float *)((int)this + 0x104),
                           (uint)*(byte *)((int)this + 0x108),*(undefined4 *)((int)this + 0x10c));
            }
            puVar6 = *(undefined4 **)((int)this + 0x270);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x110));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar16 = "true";
              if (*(char *)((int)this + 0x110) == '\0') {
                pcVar16 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetRotate3DON: on %s",pcVar16);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x44))(param_3);
            if (*(char *)((int)this + 0x110) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 0x48))(*(undefined4 *)((int)this + 0x114))
              ;
            }
            puVar6 = *(undefined4 **)((int)this + 0x270);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x118));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar16 = "true";
              if (*(char *)((int)this + 0x118) == '\0') {
                pcVar16 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetGraphEQON: on %s",pcVar16);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x4c))(param_3);
            if (*(char *)((int)this + 0x118) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 0x50))((int)this + 0x11c);
            }
            puVar6 = *(undefined4 **)((int)this + 0x270);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x144));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar16 = "true";
              if (*(char *)((int)this + 0x144) == '\0') {
                pcVar16 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetBassTrebleON: on %s",pcVar16);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x54))(param_3);
            if (*(char *)((int)this + 0x144) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 0x58))
                        (*(undefined4 *)((int)this + 0x148),*(undefined4 *)((int)this + 0x14c));
              (**(code **)(**(int **)((int)this + 0x34) + 0x5c))
                        (*(undefined4 *)((int)this + 0x150),*(undefined4 *)((int)this + 0x154),
                         *(undefined4 *)((int)this + 0x158),*(undefined4 *)((int)this + 0x15c));
            }
            puVar6 = *(undefined4 **)((int)this + 0x270);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x160));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar16 = "true";
              if (*(char *)((int)this + 0x160) == '\0') {
                pcVar16 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetParametricEQON: on %s",pcVar16);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x60))(param_3);
            if (*(char *)((int)this + 0x160) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 100))(*(undefined4 *)((int)this + 0x164));
              uVar4 = 0;
              iVar5 = (int)this + 0x168;
              do {
                (**(code **)(**(int **)((int)this + 0x34) + 0x68))(uVar4,iVar5);
                uVar4 = uVar4 + 1;
                iVar5 = iVar5 + 0x14;
              } while (uVar4 < 9);
            }
            pcVar16 = "true";
            puVar6 = *(undefined4 **)((int)this + 0x270);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x21c));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar11 = "true";
              if (*(char *)((int)this + 0x21c) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetFIRON: on %s",pcVar11);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x6c))(param_3);
            if ((*(char *)((int)this + 0x21c) != '\0') && (*(int *)((int)this + 0x230) != 0)) {
              piVar13 = (int *)((int)this + 0x220);
              if (0xf < *(uint *)((int)this + 0x234)) {
                piVar13 = (int *)*piVar13;
              }
              (**(code **)(**(int **)((int)this + 0x34) + 0x70))
                        (piVar13,*(undefined4 *)((int)this + 0x230));
            }
            puVar6 = *(undefined4 **)((int)this + 0x270);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x238));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar11 = "true";
              if (*(char *)((int)this + 0x238) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetHeadphoneON: on %s",pcVar11);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x74))(param_3);
            if ((*(char *)((int)this + 0x238) != '\0') && (*(int *)((int)this + 0x24c) != 0)) {
              piVar13 = (int *)((int)this + 0x23c);
              if (0xf < *(uint *)((int)this + 0x250)) {
                piVar13 = (int *)*piVar13;
              }
              (**(code **)(**(int **)((int)this + 0x34) + 0x78))
                        (piVar13,*(undefined4 *)((int)this + 0x24c));
            }
            puVar6 = *(undefined4 **)((int)this + 0x270);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x254));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar11 = "true";
              if (*(char *)((int)this + 0x254) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetLimiterON: on %s",pcVar11);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x7c))(param_3);
            (**(code **)(**(int **)((int)this + 0x34) + 0x80))((int)this + 600);
            puVar6 = *(undefined4 **)((int)this + 0x270);
            param_2 = (void *)CONCAT31(0x101007,*(char *)((int)this + 0x5c));
            if (puVar6 != (undefined4 *)0x0) {
              if (*(char *)((int)this + 0x5c) == '\0') {
                pcVar16 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetBypassMode: bypass %s",pcVar16);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x10))(param_2);
            uVar14 = 1;
            (**(code **)(**(int **)((int)this + 0x34) + 0xc))();
            *(undefined *)((int)this + 0x44) = 0;
            *(undefined4 *)((int)this + 0x274) = 0xffffffff;
            if (*(int **)((int)this + 0x38) != (int *)0x0) {
              FUN_1000e490(*(int **)((int)this + 0x38));
            }
            if (*(int **)((int)this + 0x3c) != (int *)0x0) {
              FUN_1000e490(*(int **)((int)this + 0x3c));
            }
            puVar6 = *(undefined4 **)((int)this + 0x270);
            if (puVar6 != (undefined4 *)0x0) {
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"Initialize audio effect instance done.")
              ;
            }
            goto LAB_1000a2b0;
          }
          puVar6 = *(undefined4 **)((int)this + 0x270);
          if (puVar6 != (undefined4 *)0x0) {
            pcVar16 = "Create out audio buffer failed.";
            goto LAB_10009cad;
          }
        }
      }
    }
  }
  uVar14 = 0;
  if (*(int **)((int)this + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)((int)this + 0x34) + 4))();
    *(undefined4 *)((int)this + 0x34) = 0;
  }
  puVar2 = *(uint **)((int)this + 0x38);
  if (puVar2 != (uint *)0x0) {
    FUN_1000e230(puVar2);
    FUN_1004f0e4(puVar2);
    *(undefined4 *)((int)this + 0x38) = 0;
  }
  puVar2 = *(uint **)((int)this + 0x3c);
  if (puVar2 != (uint *)0x0) {
    FUN_1000e230(puVar2);
    FUN_1004f0e4(puVar2);
    *(undefined4 *)((int)this + 0x3c) = 0;
  }
  if (*(void **)((int)this + 0x40) != (void *)0x0) {
    FID_conflict__free(*(void **)((int)this + 0x40));
    *(undefined4 *)((int)this + 0x40) = 0;
  }
LAB_1000a2b0:
  local_8 = 3;
  iVar5 = __Mtx_unlock((int)this + 4);
  if (iVar5 != 0) {
    std::_Throw_C_error(iVar5);
  }
  ExceptionList = local_10;
  return uVar14;
}

