void GXAdjustForOverscan(uint *param_1,uint *param_2,int param_3,int param_4)
{
  short sVar1;
  short sVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  
  sVar2 = (short)(param_3 << 1);
  if (param_1 != param_2) {
    iVar8 = 7;
    puVar3 = param_1 + -2;
    puVar4 = param_2 + -2;
    do {
      puVar7 = puVar4;
      puVar6 = puVar3;
      uVar5 = puVar6[3];
      puVar7[2] = puVar6[2];
      puVar7[3] = uVar5;
      iVar8 = iVar8 + -1;
      puVar3 = puVar6 + 2;
      puVar4 = puVar7 + 2;
    } while (iVar8 != 0);
    puVar7[4] = puVar6[4];
  }
  *(short *)(param_2 + 1) = *(short *)(param_1 + 1) - sVar2;
  *(short *)((int)param_2 + 6) =
       *(short *)((int)param_1 + 6) -
       (short)(((param_4 << 1 & 0xfffeU) * (uint)*(ushort *)((int)param_1 + 6)) /
              (uint)*(ushort *)(param_1 + 2));
  sVar1 = (short)(param_4 << 1);
  if ((param_1[5] == 0) && ((*param_1 & 2) != 2)) {
    *(short *)(param_2 + 2) = *(short *)(param_1 + 2) - (short)param_4;
  }
  else {
    *(short *)(param_2 + 2) = *(short *)(param_1 + 2) - sVar1;
  }
  *(short *)((int)param_2 + 0xe) = *(short *)((int)param_1 + 0xe) - sVar2;
  *(short *)(param_2 + 4) = *(short *)(param_1 + 4) - sVar1;
  *(short *)((int)param_2 + 10) = *(short *)((int)param_1 + 10) + (short)param_3;
  *(short *)(param_2 + 3) = *(short *)(param_1 + 3) + (short)param_4;
  return;
}

void GXSetDispCopySrc(uint param_1,uint param_2,uint param_3,uint param_4)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x49d,@15);
  }
  *(undefined4 *)(iRam00000000 + 0x1e0) = 0;
  if ((param_1 & 0xfc00) != 0) {
    OSPanic(@14,0x4a0,@16);
  }
  *(uint *)(iRam00000000 + 0x1e0) = *(uint *)(iRam00000000 + 0x1e0) & 0xfffffc00 | param_1 & 0xffff;
  if ((param_2 & 0xfc00) != 0) {
    OSPanic(@14,0x4a1,@16);
  }
  *(uint *)(iRam00000000 + 0x1e0) =
       *(uint *)(iRam00000000 + 0x1e0) & 0xfff003ff | (param_2 & 0xffff) << 10;
  *(uint *)(iRam00000000 + 0x1e0) = *(uint *)(iRam00000000 + 0x1e0) & 0xffffff | 0x49000000;
  *(undefined4 *)(iRam00000000 + 0x1e4) = 0;
  if (((param_3 & 0xffff) - 1 & 0xfffffc00) != 0) {
    OSPanic(@14,0x4a5,@16);
  }
  *(uint *)(iRam00000000 + 0x1e4) =
       *(uint *)(iRam00000000 + 0x1e4) & 0xfffffc00 | (param_3 & 0xffff) - 1;
  if (((param_4 & 0xffff) - 1 & 0xfffffc00) != 0) {
    OSPanic(@14,0x4a6,@16);
  }
  *(uint *)(iRam00000000 + 0x1e4) =
       *(uint *)(iRam00000000 + 0x1e4) & 0xfff003ff | ((param_4 & 0xffff) - 1) * 0x400;
  *(uint *)(iRam00000000 + 0x1e4) = *(uint *)(iRam00000000 + 0x1e4) & 0xffffff | 0x4a000000;
  return;
}

void GXSetTexCopySrc(uint param_1,uint param_2,uint param_3,uint param_4)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x4b9,@18);
  }
  *(undefined4 *)(iRam00000000 + 0x1f0) = 0;
  if ((param_1 & 0xfc00) != 0) {
    OSPanic(@14,0x4bc,@16);
  }
  *(uint *)(iRam00000000 + 0x1f0) = *(uint *)(iRam00000000 + 0x1f0) & 0xfffffc00 | param_1 & 0xffff;
  if ((param_2 & 0xfc00) != 0) {
    OSPanic(@14,0x4bd,@16);
  }
  *(uint *)(iRam00000000 + 0x1f0) =
       *(uint *)(iRam00000000 + 0x1f0) & 0xfff003ff | (param_2 & 0xffff) << 10;
  *(uint *)(iRam00000000 + 0x1f0) = *(uint *)(iRam00000000 + 0x1f0) & 0xffffff | 0x49000000;
  *(undefined4 *)(iRam00000000 + 500) = 0;
  if (((param_3 & 0xffff) - 1 & 0xfffffc00) != 0) {
    OSPanic(@14,0x4c1,@16);
  }
  *(uint *)(iRam00000000 + 500) =
       *(uint *)(iRam00000000 + 500) & 0xfffffc00 | (param_3 & 0xffff) - 1;
  if (((param_4 & 0xffff) - 1 & 0xfffffc00) != 0) {
    OSPanic(@14,0x4c2,@16);
  }
  *(uint *)(iRam00000000 + 500) =
       *(uint *)(iRam00000000 + 500) & 0xfff003ff | ((param_4 & 0xffff) - 1) * 0x400;
  *(uint *)(iRam00000000 + 500) = *(uint *)(iRam00000000 + 500) & 0xffffff | 0x4a000000;
  return;
}

void GXSetDispCopyDst(uint param_1)
{
  if ((param_1 & 0xf) != 0) {
    OSPanic(@14,0x4d7,@20);
  }
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x4d8,@21);
  }
  *(undefined4 *)(iRam00000000 + 0x1e8) = 0;
  if (((param_1 << 1) >> 5 & 0x400) != 0) {
    OSPanic(@14,0x4de,@16);
  }
  *(uint *)(iRam00000000 + 0x1e8) =
       *(uint *)(iRam00000000 + 0x1e8) & 0xfffffc00 | (param_1 << 1) >> 5 & 0x7ff;
  *(uint *)(iRam00000000 + 0x1e8) = *(uint *)(iRam00000000 + 0x1e8) & 0xffffff | 0x4d000000;
  return;
}

/* WARNING: Removing unreachable block (ram,0x000105f4) */
/* WARNING: Removing unreachable block (ram,0x000106f4) */
void GXSetTexCopyDst(undefined2 param_1,undefined2 param_2,uint param_3,uint param_4)
{
  uint uVar1;
  int local_24;
  undefined auStack_20 [4];
  int local_1c [2];
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x4f9,@32);
  }
  *(undefined *)(iRam00000000 + 0x200) = 0;
  uVar1 = param_3 & 0xf;
  if (0xc < uVar1) {
    OSPanic(@14,0x518,@33,@34);
  }
  if (param_3 == 0x13) {
    uVar1 = 0xb;
  }
  if ((param_3 == 0x26) || ((((int)param_3 < 0x26 && ((int)param_3 < 4)) && (-1 < (int)param_3)))) {
    *(uint *)(iRam00000000 + 0x1fc) = *(uint *)(iRam00000000 + 0x1fc) & 0xfffe7fff | 0x18000;
  }
  else {
    *(uint *)(iRam00000000 + 0x1fc) = *(uint *)(iRam00000000 + 0x1fc) & 0xfffe7fff | 0x10000;
  }
  *(bool *)(iRam00000000 + 0x200) = (param_3 & 0x10) == 0x10;
  *(uint *)(iRam00000000 + 0x1fc) =
       *(uint *)(iRam00000000 + 0x1fc) & 0xfffffff7 | uVar1 & 0xfffffff8;
  __GetImageTileCount(param_3,param_1,param_2,local_1c,auStack_20,&local_24);
  *(undefined4 *)(iRam00000000 + 0x1f8) = 0;
  if ((local_1c[0] * local_24 & 0xfffffc00U) != 0) {
    OSPanic(@14,0x538,@16);
  }
  *(uint *)(iRam00000000 + 0x1f8) =
       *(uint *)(iRam00000000 + 0x1f8) & 0xfffffc00 | local_1c[0] * local_24;
  *(uint *)(iRam00000000 + 0x1f8) = *(uint *)(iRam00000000 + 0x1f8) & 0xffffff | 0x4d000000;
  if ((param_4 & 0xfe) != 0) {
    OSPanic(@14,0x53a,@16);
  }
  *(uint *)(iRam00000000 + 0x1fc) =
       *(uint *)(iRam00000000 + 0x1fc) & 0xfffffdff | (param_4 & 0xff) << 9;
  *(uint *)(iRam00000000 + 0x1fc) = *(uint *)(iRam00000000 + 0x1fc) & 0xffffff8f | (uVar1 & 7) << 4;
  return;
}

void GXSetDispCopyFrame2Field(uint param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x54c,@36);
  }
  if ((param_1 & 0xfffffffc) != 0) {
    OSPanic(@14,0x54d,@16);
  }
  *(uint *)(iRam00000000 + 0x1ec) = *(uint *)(iRam00000000 + 0x1ec) & 0xffffcfff | param_1 << 0xc;
  *(uint *)(iRam00000000 + 0x1fc) = *(uint *)(iRam00000000 + 0x1fc) & 0xffffcfff;
  return;
}

/* WARNING: Removing unreachable block (ram,0x000108b0) */
/* WARNING: Removing unreachable block (ram,0x00010840) */
/* WARNING: Removing unreachable block (ram,0x00010878) */
/* WARNING: Removing unreachable block (ram,0x000108e8) */
void GXSetCopyClamp(uint param_1)
{
  uint uVar1;
  uint uVar2;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x561,@38);
  }
  uVar1 = (uint)((param_1 & 1) == 1);
  uVar2 = (uint)((param_1 & 2) == 2);
  *(uint *)(iRam00000000 + 0x1ec) = *(uint *)(iRam00000000 + 0x1ec) & 0xfffffffe | uVar1;
  *(uint *)(iRam00000000 + 0x1ec) = *(uint *)(iRam00000000 + 0x1ec) & 0xfffffffd | uVar2 << 1;
  *(uint *)(iRam00000000 + 0x1fc) = *(uint *)(iRam00000000 + 0x1fc) & 0xfffffffe | uVar1;
  *(uint *)(iRam00000000 + 0x1fc) = *(uint *)(iRam00000000 + 0x1fc) & 0xfffffffd | uVar2 << 1;
  return;
}

uint __GXGetNumXfbLines(uint param_1,uint param_2)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ((param_1 - 1) * 0x100) / param_2;
  uVar2 = uVar1 + 1;
  if ((0x80 < param_2) && (param_2 < 0x100)) {
    for (; (param_2 & 1) == 0; param_2 = param_2 >> 1) {
    }
    if (param_1 == (param_1 / param_2) * param_2) {
      uVar2 = uVar1 + 2;
    }
  }
  if (0x400 < uVar2) {
    uVar2 = 0x400;
  }
  return uVar2;
}

undefined2 GXGetNumXfbLines(double param_1,undefined2 param_2)
{
  uint uVar1;
  undefined2 uVar2;
  
  if (param_1 < (double)@52) {
    OSPanic(@14,0x598,@53);
  }
  uVar1 = __cvt_fp2unsigned((double)(float)((double)@54 / param_1));
  uVar2 = __GXGetNumXfbLines(param_2,uVar1 & 0x1ff);
  return uVar2;
}

void GXGetYScaleFactor(void)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 uVar8;
  
  uVar8 = _savefpr_30();
  uVar1 = (uint)((ulonglong)uVar8 >> 0x20);
  uVar3 = (uint)uVar8;
  if (0x400 < (uVar3 & 0xffff)) {
    OSPanic(@14,0x5b0,@64);
  }
  if ((uVar3 & 0xffff) < (uVar1 & 0xffff)) {
    OSPanic(@14,0x5b2,@65);
  }
  uVar4 = uVar3 & 0xffff;
  dVar6 = (double)((float)((double)CONCAT44(0x43300000,uVar3 & 0xffff) - @67) /
                  (float)((double)CONCAT44(0x43300000,uVar1 & 0xffff) - @67));
  uVar2 = __cvt_fp2unsigned((double)(float)((double)@54 / dVar6));
  for (uVar2 = __GXGetNumXfbLines(uVar1 & 0xffff,uVar2 & 0x1ff); dVar5 = dVar6,
      (uVar3 & 0xffff) < uVar2; uVar2 = __GXGetNumXfbLines(uVar1 & 0xffff,uVar2 & 0x1ff)) {
    uVar4 = uVar4 - 1;
    dVar6 = (double)((float)((double)CONCAT44(0x43300000,uVar4) - @67) /
                    (float)((double)CONCAT44(0x43300000,uVar1 & 0xffff) - @67));
    uVar2 = __cvt_fp2unsigned((double)(float)((double)@54 / dVar6));
  }
  while (uVar2 < (uVar3 & 0xffff)) {
    uVar4 = uVar4 + 1;
    dVar7 = (double)((float)((double)CONCAT44(0x43300000,uVar4) - @67) /
                    (float)((double)CONCAT44(0x43300000,uVar1 & 0xffff) - @67));
    uVar2 = __cvt_fp2unsigned((double)(float)((double)@54 / dVar7));
    uVar2 = __GXGetNumXfbLines(uVar1 & 0xffff,uVar2 & 0x1ff);
    dVar6 = dVar5;
    dVar5 = dVar7;
  }
  _restfpr_30(dVar6);
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010c78) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetDispCopyYScale(double param_1)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x5df,@70);
  }
  if (param_1 < (double)@52) {
    OSPanic(@14,0x5e1,@71);
  }
  uVar2 = __cvt_fp2unsigned((double)(float)((double)@54 / param_1));
  uVar2 = uVar2 & 0x1ff;
  iVar3 = -uVar2 + 0x100;
  uVar1 = iVar3 + (-(uint)(iVar3 == 0) - (-uVar2 + 0xff));
  _DAT_cc008000 = uVar2 | 0x4e000000;
  *(uint *)(iRam00000000 + 0xe00) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  if ((uVar1 & 0xfe) != 0) {
    OSPanic(@14,0x5ed,@16);
  }
  *(uint *)(iRam00000000 + 0x1ec) =
       *(uint *)(iRam00000000 + 0x1ec) & 0xfffffbff | (uVar1 & 0xff) << 10;
  __GXGetNumXfbLines((*(uint *)(iRam00000000 + 0x1e4) >> 10 & 0x3ff) + 1,uVar2);
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010e34) */
/* WARNING: Removing unreachable block (ram,0x00010dac) */
/* WARNING: Removing unreachable block (ram,0x00010dd8) */
/* WARNING: Removing unreachable block (ram,0x00010e60) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetCopyClear(undefined *param_1,uint param_2)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x606,@73);
  }
  if (0xffffff < param_2) {
    OSPanic(@14,0x608,@74);
  }
  *(uint *)(iRam00000000 + 0xe04) = CONCAT11(param_1[3],*param_1) | 0x4f000000;
  _DAT_cc008000 = *(ushort *)(param_1 + 1) | 0x50000000;
  *(uint *)(iRam00000000 + 0xe08) = _DAT_cc008000;
  if ((param_2 & 0xff000000) != 0) {
    OSPanic(@14,0x617,@16);
  }
  _DAT_cc008000 = param_2 & 0xffffff | 0x51000000;
  *(uint *)(iRam00000000 + 0xe0c) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetCopyFilter(char param_1,byte *param_2,char param_3,byte *param_4)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x633,@82);
  }
  if (param_1 == '\0') {
    local_28 = 0x1666666;
    local_24 = 0x2666666;
    local_20 = 0x3666666;
    local_1c = 0x4666666;
  }
  else {
    if ((*param_2 & 0xf0) != 0) {
      OSPanic(@14,0x637,@16);
    }
    bVar1 = *param_2;
    if ((param_2[1] & 0xf0) != 0) {
      OSPanic(@14,0x638,@16);
    }
    bVar2 = param_2[1];
    if ((param_2[2] & 0xf0) != 0) {
      OSPanic(@14,0x639,@16);
    }
    bVar3 = param_2[2];
    if ((param_2[3] & 0xf0) != 0) {
      OSPanic(@14,0x63a,@16);
    }
    bVar4 = param_2[3];
    if ((param_2[4] & 0xf0) != 0) {
      OSPanic(@14,0x63b,@16);
    }
    bVar5 = param_2[4];
    if ((param_2[5] & 0xf0) != 0) {
      OSPanic(@14,0x63c,@16);
    }
    local_28 = bVar1 & 0xffffff0f | (bVar2 & 0xfffff0f) << 4 | (bVar3 & 0xffff0f) << 8 |
               (bVar4 & 0xfff0f) << 0xc | (bVar5 & 0xff0f) << 0x10 | (param_2[5] & 0xf) << 0x14 |
               0x1000000;
    if ((param_2[6] & 0xf0) != 0) {
      OSPanic(@14,0x640,@16);
    }
    bVar1 = param_2[6];
    if ((param_2[7] & 0xf0) != 0) {
      OSPanic(@14,0x641,@16);
    }
    bVar2 = param_2[7];
    if ((param_2[8] & 0xf0) != 0) {
      OSPanic(@14,0x642,@16);
    }
    bVar3 = param_2[8];
    if ((param_2[9] & 0xf0) != 0) {
      OSPanic(@14,0x643,@16);
    }
    bVar4 = param_2[9];
    if ((param_2[10] & 0xf0) != 0) {
      OSPanic(@14,0x644,@16);
    }
    bVar5 = param_2[10];
    if ((param_2[0xb] & 0xf0) != 0) {
      OSPanic(@14,0x645,@16);
    }
    local_24 = bVar1 & 0xffffff0f | (bVar2 & 0xfffff0f) << 4 | (bVar3 & 0xffff0f) << 8 |
               (bVar4 & 0xfff0f) << 0xc | (bVar5 & 0xff0f) << 0x10 | (param_2[0xb] & 0xf) << 0x14 |
               0x2000000;
    if ((param_2[0xc] & 0xf0) != 0) {
      OSPanic(@14,0x649,@16);
    }
    bVar1 = param_2[0xc];
    if ((param_2[0xd] & 0xf0) != 0) {
      OSPanic(@14,0x64a,@16);
    }
    bVar2 = param_2[0xd];
    if ((param_2[0xe] & 0xf0) != 0) {
      OSPanic(@14,0x64b,@16);
    }
    bVar3 = param_2[0xe];
    if ((param_2[0xf] & 0xf0) != 0) {
      OSPanic(@14,0x64c,@16);
    }
    bVar4 = param_2[0xf];
    if ((param_2[0x10] & 0xf0) != 0) {
      OSPanic(@14,0x64d,@16);
    }
    bVar5 = param_2[0x10];
    if ((param_2[0x11] & 0xf0) != 0) {
      OSPanic(@14,0x64e,@16);
    }
    local_20 = bVar1 & 0xffffff0f | (bVar2 & 0xfffff0f) << 4 | (bVar3 & 0xffff0f) << 8 |
               (bVar4 & 0xfff0f) << 0xc | (bVar5 & 0xff0f) << 0x10 | (param_2[0x11] & 0xf) << 0x14 |
               0x3000000;
    if ((param_2[0x12] & 0xf0) != 0) {
      OSPanic(@14,0x652,@16);
    }
    bVar1 = param_2[0x12];
    if ((param_2[0x13] & 0xf0) != 0) {
      OSPanic(@14,0x653,@16);
    }
    bVar2 = param_2[0x13];
    if ((param_2[0x14] & 0xf0) != 0) {
      OSPanic(@14,0x654,@16);
    }
    bVar3 = param_2[0x14];
    if ((param_2[0x15] & 0xf0) != 0) {
      OSPanic(@14,0x655,@16);
    }
    bVar4 = param_2[0x15];
    if ((param_2[0x16] & 0xf0) != 0) {
      OSPanic(@14,0x656,@16);
    }
    bVar5 = param_2[0x16];
    if ((param_2[0x17] & 0xf0) != 0) {
      OSPanic(@14,0x657,@16);
    }
    local_1c = bVar1 & 0xffffff0f | (bVar2 & 0xfffff0f) << 4 | (bVar3 & 0xffff0f) << 8 |
               (bVar4 & 0xfff0f) << 0xc | (bVar5 & 0xff0f) << 0x10 | (param_2[0x17] & 0xf) << 0x14 |
               0x4000000;
  }
  *(uint *)(iRam00000000 + (local_28 >> 0x16 & 0x3fc) + 0xcc8) = local_28;
  *(uint *)(iRam00000000 + (local_24 >> 0x16 & 0x3fc) + 0xcc8) = local_24;
  *(uint *)(iRam00000000 + (local_20 >> 0x16 & 0x3fc) + 0xcc8) = local_20;
  _DAT_cc008000 = local_1c;
  *(uint *)(iRam00000000 + (local_1c >> 0x16 & 0x3fc) + 0xcc8) = local_1c;
  if (param_3 == '\0') {
    uVar6 = 0x53595000;
    _DAT_cc008000 = 0x54000015;
  }
  else {
    if ((*param_4 & 0xc0) != 0) {
      OSPanic(@14,0x670,@16);
    }
    bVar1 = *param_4;
    if ((param_4[1] & 0xc0) != 0) {
      OSPanic(@14,0x671,@16);
    }
    bVar2 = param_4[1];
    if ((param_4[2] & 0xc0) != 0) {
      OSPanic(@14,0x672,@16);
    }
    bVar3 = param_4[2];
    if ((param_4[3] & 0xc0) != 0) {
      OSPanic(@14,0x673,@16);
    }
    uVar6 = bVar1 & 0xfffff03f | 0x53000000 | (bVar2 & 0x3fff03f) << 6 | (bVar3 & 0xff03f) << 0xc |
            (uint)param_4[3] << 0x12;
    if ((param_4[4] & 0xc0) != 0) {
      OSPanic(@14,0x674,@16);
    }
    bVar1 = param_4[4];
    if ((param_4[5] & 0xc0) != 0) {
      OSPanic(@14,0x675,@16);
    }
    bVar2 = param_4[5];
    if ((param_4[6] & 0xc0) != 0) {
      OSPanic(@14,0x676,@16);
    }
    _DAT_cc008000 =
         bVar1 & 0xfffff03f | 0x54000000 | (bVar2 & 0x3fff03f) << 6 | (uint)param_4[6] << 0xc;
  }
  *(uint *)(iRam00000000 + (uVar6 >> 0x16 & 0x3fc) + 0xcc8) = uVar6;
  *(uint *)(iRam00000000 + (_DAT_cc008000 >> 0x16) + 0xcc8) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

void GXSetDispCopyGamma(uint param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x697,@84);
  }
  if ((param_1 & 0xfffffffc) != 0) {
    OSPanic(@14,0x698,@16);
  }
  *(uint *)(iRam00000000 + 0x1ec) = *(uint *)(iRam00000000 + 0x1ec) & 0xfffffe7f | param_1 << 7;
  return;
}

void __GXVerifCopy(uint param_1,char param_2)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x6ac,@91);
  }
  uVar3 = *(uint *)(iRam00000000 + 0x1ec);
  uVar2 = *(uint *)(iRam00000000 + 0x1e0);
  uVar4 = (*(uint *)(iRam00000000 + 0x1e4) & 0x3ff) + 1;
  uVar1 = *(uint *)(iRam00000000 + 0x1e0) >> 10;
  uVar5 = (*(uint *)(iRam00000000 + 0x1e4) >> 10 & 0x3ff) + 1;
  if (((*(uint *)(iRam00000000 + 0x1ec) & 1) == 0) && ((uVar1 & 0x3ff) == 0)) {
    OSPanic(@14,0x6b6,@92);
  }
  if (((uVar3 >> 1 & 1) == 0) && (0x210 < (uVar1 & 0x3ff) + uVar5)) {
    OSPanic(@14,0x6b8,@93);
  }
  if (((*(uint *)(iRam00000000 + 0x1dc) & 7) == 3) && (param_2 != '\0')) {
    OSPanic(@14,0x6bd,@94);
  }
  if ((*(uint *)(iRam00000000 + 0x1dc) & 7) == 5) {
    if (param_2 != '\0') {
      OSPanic(@14,0x6c3,@95);
    }
    if ((uVar2 & 3) != 0) {
      OSPanic(@14,0x6c5,@96);
    }
    if ((uVar1 & 3) != 0) {
      OSPanic(@14,0x6c7,@97);
    }
    if ((uVar4 & 3) != 0) {
      OSPanic(@14,0x6c9,@98);
    }
    if ((uVar5 & 3) != 0) {
      OSPanic(@14,0x6cb,@99);
    }
  }
  else {
    if ((uVar2 & 1) != 0) {
      OSPanic(@14,0x6cf,@100);
    }
    if ((uVar1 & 1) != 0) {
      OSPanic(@14,0x6d1,@101);
    }
    if ((uVar4 & 1) != 0) {
      OSPanic(@14,0x6d3,@102);
    }
    if ((uVar5 & 1) != 0) {
      OSPanic(@14,0x6d5,@103);
    }
  }
  if ((param_1 & 0x1f) != 0) {
    OSPanic(@14,0x6d9,@104);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXCopyDisp(uint param_1,uint param_2)
{
  bool bVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x6f3,@91);
  }
  __GXVerifCopy(param_1,param_2);
  if ((param_2 & 0xff) != 0) {
    *(uint *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d8) >> 0x16 & 0x3fc) + 0xcc8) =
         *(uint *)(iRam00000000 + 0x1d8) & 0xfffffff0 | 0xf;
    *(uint *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d0) >> 0x16 & 0x3fc) + 0xcc8) =
         *(uint *)(iRam00000000 + 0x1d0) & 0xfffffffc;
  }
  bVar1 = false;
  if ((param_2 & 0xff) == 0) {
    if ((*(uint *)(iRam00000000 + 0x1dc) & 7) != 3) goto LAB_00011c04;
  }
  if ((*(uint *)(iRam00000000 + 0x1dc) >> 6 & 1) == 1) {
    bVar1 = true;
    *(uint *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1dc) >> 0x16 & 0x3fc) + 0xcc8) =
         *(uint *)(iRam00000000 + 0x1dc) & 0xffffffbf;
  }
LAB_00011c04:
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1e0) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1e0);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1e4) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1e4);
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1e8);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1e8) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1e8);
  if (((param_1 & 0x3fffffff) >> 5 & 0x7e00000) != 0) {
    OSPanic(@14,0x71a,@16);
  }
  _DAT_cc008000 = (param_1 & 0x3fffffff) >> 5 & 0xffffff | 0x4b000000;
  *(uint *)(iRam00000000 + 0xdf4) = _DAT_cc008000;
  if ((param_2 & 0xfe) != 0) {
    OSPanic(@14,0x71e,@16);
  }
  *(uint *)(iRam00000000 + 0x1ec) =
       *(uint *)(iRam00000000 + 0x1ec) & 0xfffff7ff | (param_2 & 0xff) << 0xb;
  *(uint *)(iRam00000000 + 0x1ec) = *(uint *)(iRam00000000 + 0x1ec) & 0xffffbfff | 0x4000;
  *(uint *)(iRam00000000 + 0x1ec) = *(uint *)(iRam00000000 + 0x1ec) & 0xffffff | 0x52000000;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1ec);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1ec) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1ec);
  if ((param_2 & 0xff) != 0) {
    *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d8) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + 0x1d8);
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1d0);
    *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d0) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + 0x1d0);
  }
  if (bVar1) {
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1dc);
    *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1dc) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + 0x1dc);
  }
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXCopyTex(uint param_1,uint param_2)
{
  bool bVar1;
  uint uVar2;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x746,@133);
  }
  __GXVerifCopy(param_1,param_2);
  if ((param_2 & 0xff) != 0) {
    *(uint *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d8) >> 0x16 & 0x3fc) + 0xcc8) =
         *(uint *)(iRam00000000 + 0x1d8) & 0xfffffff0 | 0xf;
    *(uint *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d0) >> 0x16 & 0x3fc) + 0xcc8) =
         *(uint *)(iRam00000000 + 0x1d0) & 0xfffffffc;
  }
  bVar1 = false;
  uVar2 = *(uint *)(iRam00000000 + 0x1dc);
  if (*(char *)(iRam00000000 + 0x200) != '\0') {
    if ((uVar2 & 7) != 3) {
      bVar1 = true;
      uVar2 = uVar2 & 0xfffffff8 | 3;
    }
  }
  if ((param_2 & 0xff) == 0) {
    if ((uVar2 & 7) != 3) goto LAB_00011fbc;
  }
  if ((uVar2 >> 6 & 1) == 1) {
    bVar1 = true;
    uVar2 = uVar2 & 0xffffffbf;
  }
LAB_00011fbc:
  if (bVar1) {
    *(uint *)(iRam00000000 + (uVar2 >> 0x16 & 0x3fc) + 0xcc8) = uVar2;
  }
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1f0) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1f0);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 500) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 500);
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1f8);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1f8) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1f8);
  if (((param_1 & 0x3fffffff) >> 5 & 0x7e00000) != 0) {
    OSPanic(@14,0x777,@16);
  }
  _DAT_cc008000 = (param_1 & 0x3fffffff) >> 5 & 0xffffff | 0x4b000000;
  *(uint *)(iRam00000000 + 0xdf4) = _DAT_cc008000;
  if ((param_2 & 0xfe) != 0) {
    OSPanic(@14,0x77b,@16);
  }
  *(uint *)(iRam00000000 + 0x1fc) =
       *(uint *)(iRam00000000 + 0x1fc) & 0xfffff7ff | (param_2 & 0xff) << 0xb;
  *(uint *)(iRam00000000 + 0x1fc) = *(uint *)(iRam00000000 + 0x1fc) & 0xffffbfff;
  *(uint *)(iRam00000000 + 0x1fc) = *(uint *)(iRam00000000 + 0x1fc) & 0xffffff | 0x52000000;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1fc);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1fc) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1fc);
  if ((param_2 & 0xff) != 0) {
    *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d8) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + 0x1d8);
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1d0);
    *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d0) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + 0x1d0);
  }
  if (bVar1) {
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1dc);
    *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1dc) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + 0x1dc);
  }
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXClearBoundingBox(void)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(@14,0x79d,@135);
  }
  *(undefined4 *)(iRam00000000 + 0xe1c) = 0x550003ff;
  _DAT_cc008000 = 0x560003ff;
  *(undefined4 *)(iRam00000000 + 0xe20) = 0x560003ff;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

void GXReadBoundingBox(undefined2 *param_1,undefined2 *param_2,undefined2 *param_3,
                      undefined2 *param_4)
{
  *param_1 = *(undefined2 *)(iRam00000000 + 0x10);
  *param_2 = *(undefined2 *)(iRam00000000 + 0x14);
  *param_3 = *(undefined2 *)(iRam00000000 + 0x12);
  *param_4 = *(undefined2 *)(iRam00000000 + 0x16);
  return;
}
