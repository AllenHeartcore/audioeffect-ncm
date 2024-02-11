
char __thiscall FUN_1000a0d0(void *this,int param_1,void *param_2,int param_3,uint param_4)

{
  uint *puVar1;
  undefined uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  void *pvVar9;
  void **ppvVar10;
  char *pcVar11;
  char *pcVar12;
  int *piVar13;
  int iVar14;
  void *local_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100b6476;
  local_10 = ExceptionList;
  uVar4 = DAT_1012c088 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar5 = __Mtx_lock((_Mtx_internal_imp_t *)((int)this + 4));
  if (iVar5 != 0) {
    std::_Throw_C_error(iVar5);
  }
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  if ((((*(int *)((int)this + 0x34) != 0) && (*(int *)((int)this + 0x48) == param_1)) &&
      (*(void **)((int)this + 0x50) == param_2)) && (*(int *)((int)this + 0x54) == param_3)) {
    FUN_1000cb10((int)this);
    puVar6 = *(undefined4 **)((int)this + 0x2c4);
    if (puVar6 != (undefined4 *)0x0) {
      (**(code **)*puVar6)(puVar6,"AudioEffects",3,"Reset audio effect instance done.");
    }
    cVar3 = '\x01';
    goto LAB_1000aa0a;
  }
  *(undefined *)((int)this + 0x44) = 0;
  FUN_1000ca90((int)this);
  puVar6 = (undefined4 *)NCAudioEffectsProcessor::Create();
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = *(undefined4 **)((int)this + 0x2c4);
    uVar2 = (undefined)local_8;
    if (puVar6 != (undefined4 *)0x0) {
      (**(code **)*puVar6)(puVar6,"AudioEffects",0,"Create audio effect instance failed.",uVar4);
      uVar2 = (undefined)local_8;
    }
LAB_1000a19c:
    local_8._0_1_ = uVar2;
    cVar3 = '\0';
  }
  else {


    uVar7 = FUN_10009530(param_1);
    uVar4 = FUN_10011580(uVar7);
    *(uint *)((int)this + 0x58) = uVar4;
    if (param_4 == 0) {
      *(undefined4 *)((int)this + 0x4c) = 0x800;
      uVar8 = 0x800;
    }
    else {
      uVar8 = (undefined4)(((ulonglong)param_4 / (ulonglong)uVar4) / ZEXT48(param_2));
      *(undefined4 *)((int)this + 0x4c) = uVar8;
    }
    cVar3 = (**(code **)*puVar6)(uVar7,uVar8,param_2,param_3);
    if (cVar3 == '\0') {
      puVar6 = *(undefined4 **)((int)this + 0x2c4);
      if (puVar6 != (undefined4 *)0x0) {
        (**(code **)*puVar6)(puVar6,"AudioEffects",0,"Initialize audio effect instance failed.");
      }
    }
    else {
      *(undefined4 **)((int)this + 0x34) = puVar6;
      *(int *)((int)this + 0x48) = param_1;
      *(void **)((int)this + 0x50) = param_2;
      *(int *)((int)this + 0x54) = param_3;


      pvVar9 = (void *)FUN_10052414(0x20);
      local_8._0_1_ = 1;
      if (pvVar9 == (void *)0x0) {
        ppvVar10 = (void **)0x0;
      }
      else {
        ppvVar10 = FUN_1000eef0(pvVar9,*(void **)((int)this + 0x58),param_2,(void *)0x0,
                                *(void **)((int)this + 0x4c));
      }
      local_8._0_1_ = 0;
      uVar2 = (undefined)local_8;
      local_8._0_1_ = 0;
      *(void ***)((int)this + 0x38) = ppvVar10;
      if (ppvVar10 == (void **)0x0) {
        puVar6 = *(undefined4 **)((int)this + 0x2c4);
        if (puVar6 == (undefined4 *)0x0) goto LAB_1000a19c;
        (**(code **)*puVar6)(puVar6,"AudioEffects",0,"Create in audio fifo failed.");
        cVar3 = '\0';
      }
      else {


        pvVar9 = (void *)FUN_10052414(0x20);
        local_8._0_1_ = 2;
        if (pvVar9 == (void *)0x0) {
          ppvVar10 = (void **)0x0;
        }
        else {
          ppvVar10 = FUN_1000eef0(pvVar9,*(void **)((int)this + 0x58),param_2,(void *)0x0,
                                  *(void **)((int)this + 0x4c));
        }
        local_8._0_1_ = 0;
        *(void ***)((int)this + 0x3c) = ppvVar10;
        if (ppvVar10 == (void **)0x0) {
          puVar6 = *(undefined4 **)((int)this + 0x2c4);
          uVar2 = (undefined)local_8;
          if (puVar6 == (undefined4 *)0x0) goto LAB_1000a19c;
          (**(code **)*puVar6)(puVar6,"AudioEffects",0,"Create out audio fifo failed.");
          cVar3 = '\0';
        }
        else {


          iVar5 = FUN_1007fb74(*(int *)((int)this + 0x58) * *(int *)((int)this + 0x50) *
                               *(int *)((int)this + 0x4c));
          *(int *)((int)this + 0x40) = iVar5;
          if (iVar5 != 0) {


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x5d));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar11 = "true";
              if (*(char *)((int)this + 0x5d) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetLoudnessON: on %s",pcVar11);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x14))(param_3);
            if (*(char *)((int)this + 0x5d) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 0x18))
                        (*(undefined4 *)((int)this + 0x60),*(undefined4 *)((int)this + 100));
            }


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x68));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar11 = "true";
              if (*(char *)((int)this + 0x68) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetReverbON: on %s",pcVar11);
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
              iVar14 = 0;
              iVar5 = (int)this + 0x9c;
              do {
                iVar14 = iVar14 + 1;
                (**(code **)(**(int **)((int)this + 0x34) + 0x2c))(iVar14,iVar5);
                iVar5 = iVar5 + 0x14;
              } while (iVar14 < 3);
              (**(code **)(**(int **)((int)this + 0x34) + 0x30))
                        (*(undefined4 *)((int)this + 0xd8),*(undefined4 *)((int)this + 0xdc));
              (**(code **)(**(int **)((int)this + 0x34) + 0x34))
                        (*(undefined4 *)((int)this + 0xe0),*(undefined4 *)((int)this + 0xe4),
                         *(undefined4 *)((int)this + 0xe8),*(undefined4 *)((int)this + 0xec));
              (**(code **)(**(int **)((int)this + 0x34) + 0x38))
                        (*(undefined4 *)((int)this + 0xf0),*(undefined4 *)((int)this + 0xf4),
                         *(undefined4 *)((int)this + 0xf8));
            }


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0xfc));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar11 = "true";
              if (*(char *)((int)this + 0xfc) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetStereoEnhancerON: on %s",pcVar11);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x3c))(param_3);
            if (*(char *)((int)this + 0xfc) != '\0') {
              FUN_1000d740(this,*(float *)((int)this + 0x100),*(float *)((int)this + 0x104),
                           (uint)*(byte *)((int)this + 0x108),*(undefined4 *)((int)this + 0x10c));
            }


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x110));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar11 = "true";
              if (*(char *)((int)this + 0x110) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetRotate3DON: on %s",pcVar11);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x44))(param_3);
            if (*(char *)((int)this + 0x110) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 0x48))(*(undefined4 *)((int)this + 0x114))
              ;
            }


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x118));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar11 = "true";
              if (*(char *)((int)this + 0x118) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetGraphEQON: on %s",pcVar11);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x4c))(param_3);
            if (*(char *)((int)this + 0x118) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 0x50))((int)this + 0x11c);
            }


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x144));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar11 = "true";
              if (*(char *)((int)this + 0x144) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetBassTrebleON: on %s",pcVar11);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x54))(param_3);
            if (*(char *)((int)this + 0x144) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 0x58))
                        (*(undefined4 *)((int)this + 0x148),*(undefined4 *)((int)this + 0x14c));
              (**(code **)(**(int **)((int)this + 0x34) + 0x5c))
                        (*(undefined4 *)((int)this + 0x150),*(undefined4 *)((int)this + 0x154),
                         *(undefined4 *)((int)this + 0x158),*(undefined4 *)((int)this + 0x15c));
            }


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x160));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar11 = "true";
              if (*(char *)((int)this + 0x160) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetCompressorON: on %s",pcVar11);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x60))(param_3);
            if (*(char *)((int)this + 0x160) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 100))((int)this + 0x164);
            }


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x180));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar11 = "true";
              if (*(char *)((int)this + 0x180) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetPostCompressorON: on %s",pcVar11);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x68))(param_3);
            if (*(char *)((int)this + 0x180) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 0x6c))((int)this + 0x184);
            }


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x1a0));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar11 = "true";
              if (*(char *)((int)this + 0x1a0) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetParametricEQON: on %s",pcVar11);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x70))(param_3);
            if (*(char *)((int)this + 0x1a0) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 0x74))(*(undefined4 *)((int)this + 0x1a4))
              ;
              uVar4 = 0;
              iVar5 = (int)this + 0x1a8;
              do {
                (**(code **)(**(int **)((int)this + 0x34) + 0x78))(uVar4,iVar5);
                uVar4 = uVar4 + 1;
                iVar5 = iVar5 + 0x14;
              } while (uVar4 < 9);
            }
            pcVar11 = "true";


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x25c));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar12 = "true";
              if (*(char *)((int)this + 0x25c) == '\0') {
                pcVar12 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetDelayON: on %s",pcVar12);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x7c))(param_3);
            if (*(char *)((int)this + 0x25c) != '\0') {
              (**(code **)(**(int **)((int)this + 0x34) + 0x80))((int)this + 0x260);
            }


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x270));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar12 = "true";
              if (*(char *)((int)this + 0x270) == '\0') {
                pcVar12 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetFIRON: on %s",pcVar12);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x84))(param_3);
            if ((*(char *)((int)this + 0x270) != '\0') && (*(int *)((int)this + 0x284) != 0)) {
              piVar13 = (int *)((int)this + 0x274);
              if (0xf < *(uint *)((int)this + 0x288)) {
                piVar13 = (int *)*piVar13;
              }
              (**(code **)(**(int **)((int)this + 0x34) + 0x88))
                        (piVar13,*(undefined4 *)((int)this + 0x284));
            }


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x28c));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar12 = "true";
              if (*(char *)((int)this + 0x28c) == '\0') {
                pcVar12 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetHeadphoneON: on %s",pcVar12);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x8c))(param_3);
            if ((*(char *)((int)this + 0x28c) != '\0') && (*(int *)((int)this + 0x2a0) != 0)) {
              piVar13 = (int *)((int)this + 0x290);
              if (0xf < *(uint *)((int)this + 0x2a4)) {
                piVar13 = (int *)*piVar13;
              }
              (**(code **)(**(int **)((int)this + 0x34) + 0x90))
                        (piVar13,*(undefined4 *)((int)this + 0x2a0));
            }


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_3 = CONCAT31(param_3._1_3_,*(char *)((int)this + 0x2a8));
            if (puVar6 != (undefined4 *)0x0) {
              pcVar12 = "true";
              if (*(char *)((int)this + 0x2a8) == '\0') {
                pcVar12 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetLimiterON: on %s",pcVar12);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x94))(param_3);
            (**(code **)(**(int **)((int)this + 0x34) + 0x98))((int)this + 0x2ac);


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            param_1 = CONCAT31(0x101037,*(char *)((int)this + 0x5c));
            if (puVar6 != (undefined4 *)0x0) {
              if (*(char *)((int)this + 0x5c) == '\0') {
                pcVar11 = "false";
              }
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"SetBypassMode: bypass %s",pcVar11);
            }
            (**(code **)(**(int **)((int)this + 0x34) + 0x10))(param_1);


            puVar6 = *(undefined4 **)((int)this + 0x2c4);
            if (puVar6 != (undefined4 *)0x0) {
              (**(code **)*puVar6)(puVar6,"AudioEffects",3,"Initialize audio effect instance done.")
              ;
            }
            goto LAB_1000aa0a;
          }
          puVar6 = *(undefined4 **)((int)this + 0x2c4);
          uVar2 = (undefined)local_8;
          if (puVar6 == (undefined4 *)0x0) goto LAB_1000a19c;
          (**(code **)*puVar6)(puVar6,"AudioEffects",0,"Create out audio buffer failed.");
          cVar3 = '\0';
        }
      }
    }
  }
  if (*(int **)((int)this + 0x34) != (int *)0x0) {
    (**(code **)(**(int **)((int)this + 0x34) + 4))();
    *(undefined4 *)((int)this + 0x34) = 0;
  }
  puVar1 = *(uint **)((int)this + 0x38);
  if (puVar1 != (uint *)0x0) {
    FUN_1000f040(puVar1);
    FUN_10052444(puVar1);
    *(undefined4 *)((int)this + 0x38) = 0;
  }
  puVar1 = *(uint **)((int)this + 0x3c);
  if (puVar1 != (uint *)0x0) {
    FUN_1000f040(puVar1);
    FUN_10052444(puVar1);
    *(undefined4 *)((int)this + 0x3c) = 0;
  }
  if (*(void **)((int)this + 0x40) != (void *)0x0) {
    FID_conflict__free(*(void **)((int)this + 0x40));
    *(undefined4 *)((int)this + 0x40) = 0;
  }
LAB_1000aa0a:
  local_8 = 3;
  iVar5 = __Mtx_unlock((int)this + 4);
  if (iVar5 != 0) {
    std::_Throw_C_error(iVar5);
  }
  ExceptionList = local_10;
  return cVar3;
}

