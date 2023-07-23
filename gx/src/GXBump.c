/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetTevIndirect(int param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                     uint param_7,uint param_8,byte param_9,uint param_10)
{
  uint uVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x7f,@8);
  }
  if ((param_2 & 0xfffffffc) != 0) {
    OSPanic(...data.0,0x81,@9);
  }
  if ((param_3 & 0xfffffffc) != 0) {
    OSPanic(...data.0,0x82,@9);
  }
  if ((param_4 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x83,@9);
  }
  if ((param_10 & 0xfffffffc) != 0) {
    OSPanic(...data.0,0x84,@9);
  }
  if ((param_5 & 0xfffffff0) != 0) {
    OSPanic(...data.0,0x85,@9);
  }
  if ((param_6 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x86,@9);
  }
  if ((param_7 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x87,@9);
  }
  if ((param_9 & 0xfe) != 0) {
    OSPanic(...data.0,0x88,@9);
  }
  if ((param_8 & 0xfe) != 0) {
    OSPanic(...data.0,0x89,@9);
  }
  if ((param_1 + 0x10U & 0xffffff00) != 0) {
    OSPanic(...data.0,0x8a,@9);
  }
  uVar1 = (param_1 + 0x10) * 0x1000000;
  _DAT_cc008000 =
       uVar1 | ((((((((param_2 & 0xfffffff3 | param_3 << 2) & 0xffffff8f | param_4 << 4) &
                     0xfffffe7f | param_10 << 7) & 0xffffe1ff | param_5 << 9) & 0xffff1fff |
                  param_6 << 0xd) & 0xfff8ffff | param_7 << 0x10) & 0xfff7ffff |
                (uint)param_9 << 0x13) & 0xffefffff | (param_8 & 0xff) << 0x14) & 0xffffff;
  *(uint *)(iRam00000000 + (uVar1 >> 0x16) + 0xcc8) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Removing unreachable block (ram,0x0001049c) */
/* WARNING: Removing unreachable block (ram,0x00010378) */
/* WARNING: Removing unreachable block (ram,0x000105c0) */
/* WARNING: Removing unreachable block (ram,0x00010564) */
/* WARNING: Removing unreachable block (ram,0x00010440) */
/* WARNING: Removing unreachable block (ram,0x0001031c) */
/* WARNING: Removing unreachable block (ram,0x00010348) */
/* WARNING: Removing unreachable block (ram,0x0001046c) */
/* WARNING: Removing unreachable block (ram,0x00010590) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetIndTexMtx(int param_1,float *param_2,char param_3)
{
  uint uVar1;
  float fVar2;
  float fVar3;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0xa7,@22);
  }
  if (param_1 != 8) {
    if (param_1 < 8) {
      if (param_1 != 4) {
        if (3 < param_1) {
          param_1 = param_1 + -5;
          goto LAB_000102c8;
        }
        if (0 < param_1) {
          param_1 = param_1 + -1;
          goto LAB_000102c8;
        }
      }
    }
    else if (param_1 < 0xc) {
      param_1 = param_1 + -9;
      goto LAB_000102c8;
    }
  }
  param_1 = 0;
LAB_000102c8:
  fVar2 = @23 * *param_2;
  fVar3 = @23 * param_2[3];
  param_3 = param_3 + '\x11';
  if ((param_1 * 3 + 6U & 0xffffff00) != 0) {
    OSPanic(...data.0,0xc0,@9);
  }
  uVar1 = (param_1 * 3 + 6) * 0x1000000;
  _DAT_cc008000 =
       uVar1 | ((int)param_3 & 3U) << 0x16 | (int)fVar2 & 0x7ffU | ((int)fVar3 & 0x7ffU) << 0xb;
  *(uint *)(iRam00000000 + (uVar1 >> 0x16) + 0xcc8) = _DAT_cc008000;
  fVar2 = @23 * param_2[1];
  fVar3 = @23 * param_2[4];
  if ((param_1 * 3 + 7U & 0xffffff00) != 0) {
    OSPanic(...data.0,0xc9,@9);
  }
  uVar1 = (param_1 * 3 + 7) * 0x1000000;
  _DAT_cc008000 =
       uVar1 | ((int)param_3 & 0xcU) << 0x14 | (int)fVar2 & 0x7ffU | ((int)fVar3 & 0x7ffU) << 0xb;
  *(uint *)(iRam00000000 + (uVar1 >> 0x16) + 0xcc8) = _DAT_cc008000;
  fVar2 = @23 * param_2[2];
  fVar3 = @23 * param_2[5];
  if ((param_1 * 3 + 8U & 0xffffff00) != 0) {
    OSPanic(...data.0,0xd2,@9);
  }
  uVar1 = (param_1 * 3 + 8) * 0x1000000;
  _DAT_cc008000 =
       uVar1 | ((int)param_3 & 0x30U) << 0x12 | (int)fVar2 & 0x7ffU | ((int)fVar3 & 0x7ffU) << 0xb;
  *(uint *)(iRam00000000 + (uVar1 >> 0x16) + 0xcc8) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetIndTexCoordScale(int param_1,uint param_2,uint param_3)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0xe6,@37);
  }
  if (param_1 == 2) {
    if ((param_2 & 0xfffffff0) != 0) {
      OSPanic(...data.0,0xf6,@9);
    }
    *(uint *)(iRam00000000 + 300) = *(uint *)(iRam00000000 + 300) & 0xfffffff0 | param_2;
    if ((param_3 & 0xfffffff0) != 0) {
      OSPanic(...data.0,0xf7,@9);
    }
    *(uint *)(iRam00000000 + 300) = *(uint *)(iRam00000000 + 300) & 0xffffff0f | param_3 << 4;
    *(uint *)(iRam00000000 + 300) = *(uint *)(iRam00000000 + 300) & 0xffffff | 0x26000000;
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 300);
    *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 300) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + 300);
    goto LAB_000109f4;
  }
  if (param_1 < 2) {
    if (param_1 == 0) {
      if ((param_2 & 0xfffffff0) != 0) {
        OSPanic(...data.0,0xea,@9);
      }
      *(uint *)(iRam00000000 + 0x128) = *(uint *)(iRam00000000 + 0x128) & 0xfffffff0 | param_2;
      if ((param_3 & 0xfffffff0) != 0) {
        OSPanic(...data.0,0xeb,@9);
      }
      *(uint *)(iRam00000000 + 0x128) = *(uint *)(iRam00000000 + 0x128) & 0xffffff0f | param_3 << 4;
      *(uint *)(iRam00000000 + 0x128) = *(uint *)(iRam00000000 + 0x128) & 0xffffff | 0x25000000;
      _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x128);
      *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x128) >> 0x16 & 0x3fc) + 0xcc8) =
           *(undefined4 *)(iRam00000000 + 0x128);
      goto LAB_000109f4;
    }
    if (-1 < param_1) {
      if ((param_2 & 0xfffffff0) != 0) {
        OSPanic(...data.0,0xf0,@9);
      }
      *(uint *)(iRam00000000 + 0x128) = *(uint *)(iRam00000000 + 0x128) & 0xfffff0ff | param_2 << 8;
      if ((param_3 & 0xfffffff0) != 0) {
        OSPanic(...data.0,0xf1,@9);
      }
      *(uint *)(iRam00000000 + 0x128) =
           *(uint *)(iRam00000000 + 0x128) & 0xffff0fff | param_3 << 0xc;
      *(uint *)(iRam00000000 + 0x128) = *(uint *)(iRam00000000 + 0x128) & 0xffffff | 0x25000000;
      _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x128);
      *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x128) >> 0x16 & 0x3fc) + 0xcc8) =
           *(undefined4 *)(iRam00000000 + 0x128);
      goto LAB_000109f4;
    }
  }
  else if (param_1 < 4) {
    if ((param_2 & 0xfffffff0) != 0) {
      OSPanic(...data.0,0xfc,@9);
    }
    *(uint *)(iRam00000000 + 300) = *(uint *)(iRam00000000 + 300) & 0xfffff0ff | param_2 << 8;
    if ((param_3 & 0xfffffff0) != 0) {
      OSPanic(...data.0,0xfd,@9);
    }
    *(uint *)(iRam00000000 + 300) = *(uint *)(iRam00000000 + 300) & 0xffff0fff | param_3 << 0xc;
    *(uint *)(iRam00000000 + 300) = *(uint *)(iRam00000000 + 300) & 0xffffff | 0x26000000;
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 300);
    *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 300) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + 300);
    goto LAB_000109f4;
  }
  OSPanic(...data.0,0x102,@38);
LAB_000109f4:
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetIndTexOrder(int param_1,uint param_2,uint param_3)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x11b,@46);
  }
  if (7 < (int)param_3) {
    OSPanic(...data.0,0x11d,@47);
  }
  if (7 < (int)param_2) {
    OSPanic(...data.0,0x11e,@48);
  }
  if (param_1 == 2) {
    if ((param_3 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x12a,@9);
    }
    *(uint *)(iRam00000000 + 0x120) = *(uint *)(iRam00000000 + 0x120) & 0xffff8fff | param_3 << 0xc;
    if ((param_2 & 0xfffffff8) != 0) {
      OSPanic(...data.0,299,@9);
    }
    *(uint *)(iRam00000000 + 0x120) = *(uint *)(iRam00000000 + 0x120) & 0xfffc7fff | param_2 << 0xf;
    goto LAB_00010c9c;
  }
  if (param_1 < 2) {
    if (param_1 == 0) {
      if ((param_3 & 0xfffffff8) != 0) {
        OSPanic(...data.0,0x122,@9);
      }
      *(uint *)(iRam00000000 + 0x120) = *(uint *)(iRam00000000 + 0x120) & 0xfffffff8 | param_3;
      if ((param_2 & 0xfffffff8) != 0) {
        OSPanic(...data.0,0x123,@9);
      }
      *(uint *)(iRam00000000 + 0x120) = *(uint *)(iRam00000000 + 0x120) & 0xffffffc7 | param_2 << 3;
      goto LAB_00010c9c;
    }
    if (-1 < param_1) {
      if ((param_3 & 0xfffffff8) != 0) {
        OSPanic(...data.0,0x126,@9);
      }
      *(uint *)(iRam00000000 + 0x120) = *(uint *)(iRam00000000 + 0x120) & 0xfffffe3f | param_3 << 6;
      if ((param_2 & 0xfffffff8) != 0) {
        OSPanic(...data.0,0x127,@9);
      }
      *(uint *)(iRam00000000 + 0x120) = *(uint *)(iRam00000000 + 0x120) & 0xfffff1ff | param_2 << 9;
      goto LAB_00010c9c;
    }
  }
  else if (param_1 < 4) {
    if ((param_3 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x12e,@9);
    }
    *(uint *)(iRam00000000 + 0x120) = *(uint *)(iRam00000000 + 0x120) & 0xffe3ffff | param_3 << 0x12
    ;
    if ((param_2 & 0xfffffff8) != 0) {
      OSPanic(...data.0,0x12f,@9);
    }
    *(uint *)(iRam00000000 + 0x120) = *(uint *)(iRam00000000 + 0x120) & 0xff1fffff | param_2 << 0x15
    ;
    goto LAB_00010c9c;
  }
  OSPanic(...data.0,0x132,@49);
LAB_00010c9c:
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x120);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x120) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x120);
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 3;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

void GXSetNumIndStages(byte param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x144,@51);
  }
  if (4 < param_1) {
    OSPanic(...data.0,0x146,@52);
  }
  if ((param_1 & 0xf8) != 0) {
    OSPanic(...data.0,0x147,@9);
  }
  *(uint *)(iRam00000000 + 0x204) =
       *(uint *)(iRam00000000 + 0x204) & 0xfff8ffff | (uint)param_1 << 0x10;
  *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 6;
  return;
}

void GXSetTevDirect(undefined4 param_1)
{
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x158,@54);
  }
  GXSetTevIndirect(param_1,0,0,0,0,0,0,0,0,0);
  return;
}

void GXSetTevIndWarp(undefined4 param_1,undefined4 param_2,char param_3,char param_4,
                    undefined4 param_5)
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_4 == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = 6;
  }
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x16e,@56);
  }
  if (param_3 == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = 7;
  }
  GXSetTevIndirect(param_1,param_2,0,uVar1,param_5,uVar2,uVar2,0,0,0);
  return;
}

void GXSetTevIndTile(int param_1,int param_2,ushort param_3,ushort param_4,ushort param_5,
                    ushort param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                    undefined4 param_10)
{
  undefined4 uVar1;
  undefined4 uVar2;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint uStack_24;
  undefined4 local_20;
  uint uStack_1c;
  
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,400,@72);
  }
  if (0xf < param_1) {
    OSPanic(...data.0,0x191,@73);
  }
  if (3 < param_2) {
    OSPanic(...data.0,0x192,@74);
  }
  if (param_3 == 0x40) {
    uVar2 = 3;
  }
  else if (param_3 < 0x40) {
    if (param_3 == 0x20) {
      uVar2 = 4;
    }
    else if ((param_3 < 0x20) && (param_3 == 0x10)) {
      uVar2 = 5;
    }
    else {
LAB_00010ff4:
      OSPanic(...data.0,0x19b,@75);
      uVar2 = 0;
    }
  }
  else if (param_3 == 0x100) {
    uVar2 = 1;
  }
  else {
    if ((0xff < param_3) || (param_3 != 0x80)) goto LAB_00010ff4;
    uVar2 = 2;
  }
  if (param_4 == 0x40) {
    uVar1 = 3;
    goto LAB_0001108c;
  }
  if (param_4 < 0x40) {
    if (param_4 == 0x20) {
      uVar1 = 4;
      goto LAB_0001108c;
    }
    if ((param_4 < 0x20) && (param_4 == 0x10)) {
      uVar1 = 5;
      goto LAB_0001108c;
    }
  }
  else {
    if (param_4 == 0x100) {
      uVar1 = 1;
      goto LAB_0001108c;
    }
    if ((param_4 < 0x100) && (param_4 == 0x80)) {
      uVar1 = 2;
      goto LAB_0001108c;
    }
  }
  OSPanic(...data.0,0x1a7,@76);
  uVar1 = 0;
LAB_0001108c:
  uStack_1c = (uint)param_5;
  local_20 = 0x43300000;
  local_40 = (float)((double)CONCAT44(0x43300000,uStack_1c) - @80) * @77;
  local_38 = @78;
  local_3c = @78;
  uStack_24 = (uint)param_6;
  local_28 = 0x43300000;
  local_30 = (float)((double)CONCAT44(0x43300000,uStack_24) - @80) * @77;
  local_2c = @78;
  local_34 = @78;
  GXSetIndTexMtx(param_8,&local_40,10);
  GXSetTevIndirect(param_1,param_2,param_7,param_9,param_8,uVar2,uVar1,0,1,param_10);
  return;
}

void GXSetTevIndBumpST(int param_1,undefined4 param_2,int param_3)
{
  undefined4 unaff_r29;
  undefined4 unaff_r30;
  
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x1cf,@88);
  }
  if (param_3 == 2) {
    unaff_r30 = 6;
    unaff_r29 = 10;
  }
  else {
    if (param_3 < 2) {
      if (0 < param_3) {
        unaff_r30 = 5;
        unaff_r29 = 9;
        goto LAB_000111f0;
      }
    }
    else if (param_3 < 4) {
      unaff_r30 = 7;
      unaff_r29 = 0xb;
      goto LAB_000111f0;
    }
    OSPanic(...data.0,0x1e0,@89);
  }
LAB_000111f0:
  GXSetTevIndirect(param_1,param_2,0,3,unaff_r30,6,6,0,0,0);
  GXSetTevIndirect(param_1 + 1,param_2,0,3,unaff_r29,6,6,1,0,0);
  GXSetTevIndirect(param_1 + 2,param_2,0,0,0,0,0,1,0,0);
  return;
}

void GXSetTevIndBumpXYZ(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x214,@91);
  }
  GXSetTevIndirect(param_1,param_2,0,7,param_3,0,0,0,0,0);
  return;
}

void GXSetTevIndRepeat(undefined4 param_1)
{
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0x231,@93);
  }
  GXSetTevIndirect(param_1,0,0,0,0,6,6,1,0,0);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXUpdateBPMask(void)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_r30;
  uint uVar4;
  
  uVar3 = 0;
  uVar2 = 0;
  for (uVar4 = 0; uVar4 < (*(uint *)(iRam00000000 + 0x204) >> 0x10 & 7); uVar4 = uVar4 + 1) {
    if (uVar4 == 2) {
      unaff_r30 = *(uint *)(iRam00000000 + 0x120) >> 0xc & 7;
    }
    else if ((int)uVar4 < 2) {
      if (uVar4 == 0) {
        unaff_r30 = *(uint *)(iRam00000000 + 0x120) & 7;
      }
      else if (-1 < (int)uVar4) {
        unaff_r30 = *(uint *)(iRam00000000 + 0x120) >> 6 & 7;
      }
    }
    else if ((int)uVar4 < 4) {
      unaff_r30 = *(uint *)(iRam00000000 + 0x120) >> 0x12 & 7;
    }
    uVar3 = uVar3 | 1 << (unaff_r30 & 0x3f);
  }
  for (uVar4 = 0; uVar4 < (*(uint *)(iRam00000000 + 0x204) >> 10 & 0xf) + 1; uVar4 = uVar4 + 1) {
    uVar1 = *(uint *)(iRam00000000 + uVar4 * 4 + 0x49c);
    if ((uVar1 & 0xfffffeff) != 0xff) {
      uVar2 = uVar2 | 1 << (uVar1 & 0x3f);
    }
  }
  if ((uVar3 & uVar2) != 0) {
    OSPanic(...data.0,0x269,@114);
  }
  if ((*(uint *)(iRam00000000 + 0x124) & 0xff) != uVar3) {
    if ((uVar3 & 0xffffff00) != 0) {
      OSPanic(...data.0,0x26e,@9);
    }
    *(uint *)(iRam00000000 + 0x124) = *(uint *)(iRam00000000 + 0x124) & 0xffffff00 | uVar3;
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x124);
    *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x124) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + 0x124);
    *(undefined2 *)(iRam00000000 + 2) = 0;
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void __GXFlushTextureState(void)
{
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x124);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x124) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x124);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}
