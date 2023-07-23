/* WARNING: Removing unreachable block (ram,0x0001034c) */
/* WARNING: Removing unreachable block (ram,0x000102c0) */
/* WARNING: Removing unreachable block (ram,0x00010270) */
/* WARNING: Removing unreachable block (ram,0x00010214) */
/* WARNING: Removing unreachable block (ram,0x000101ec) */
/* WARNING: Removing unreachable block (ram,0x0001023c) */
/* WARNING: Removing unreachable block (ram,0x00010298) */
/* WARNING: Removing unreachable block (ram,0x00010320) */
/* WARNING: Removing unreachable block (ram,0x00010378) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetFog(undefined8 param_1,double param_2,double param_3,double param_4)
{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  double extraout_f1;
  double dVar6;
  double dVar7;
  ulonglong uVar8;
  
  uVar8 = _savefpr_24();
  dVar6 = extraout_f1;
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x6e,@105);
  }
  if (param_4 < (double)@106) {
    OSPanic(...data.0,0x70,@107);
  }
  if (param_4 < param_3) {
    OSPanic(...data.0,0x71,@108);
  }
  fVar2 = @106;
  fVar3 = @106;
  fVar1 = @109;
  if ((param_4 != param_3) && (param_2 != dVar6)) {
    fVar2 = (float)(param_4 * param_3) / ((float)(param_4 - param_3) * (float)(param_2 - dVar6));
    fVar3 = (float)(dVar6 / (double)(float)(param_2 - dVar6));
    fVar1 = (float)(param_4 / (double)(float)(param_4 - param_3));
  }
  dVar6 = (double)fVar3;
  iVar5 = 0;
  while (dVar7 = (double)fVar1, @110 < dVar7) {
    iVar5 = iVar5 + 1;
    fVar1 = (float)(dVar7 * (double)@109);
  }
  for (; ((double)@106 < dVar7 && (dVar7 < @112)); dVar7 = (double)(float)(dVar7 * (double)@111)) {
    iVar5 = iVar5 + -1;
  }
  fVar2 = fVar2 / (float)((double)CONCAT44(0x43300000,1 << (iVar5 + 1U & 0x3f) ^ 0x80000000) - @116)
  ;
  uVar4 = __cvt_fp2unsigned((double)(float)((double)@113 * dVar7));
  fVar1 = (float)dVar6;
  if ((uVar4 & 0xff000000) != 0) {
    OSPanic(...data.0,0x94,@114);
  }
  if ((iVar5 + 1U & 0xffffffe0) != 0) {
    OSPanic(...data.0,0x98,@114);
  }
  if ((uVar8 & 0xfffffff800000000) != 0) {
    OSPanic(...data.0,0xaa,@114);
  }
  _DAT_cc008000 = *(uint3 *)uVar8 | 0xf2000000;
  *(uint *)(iRam00000000 + 0x1080) =
       (uint)fVar2 >> 0xc & 0x80000 | (uint)fVar2 >> 0xc & 0x7f800 | (uint)fVar2 >> 0xc & 0x7ff |
       0xee000000;
  *(uint *)(iRam00000000 + 0x1084) = uVar4 & 0xffffff | 0xef000000;
  *(uint *)(iRam00000000 + 0x1088) = iVar5 + 1U & 0xffffff | 0xf0000000;
  *(uint *)(iRam00000000 + 0x108c) =
       (uint)fVar1 >> 0xc & 0x80000 | (uint)fVar1 >> 0xc & 0x7f800 | (uint)fVar1 >> 0xc & 0x7ff |
       ((uint)(uVar8 >> 0x20) & 7) << 0x15 | 0xf1000000;
  *(uint *)(iRam00000000 + 0x1090) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  _restfpr_24();
  return;
}

void GXInitFogAdjTable(undefined4 param_1,undefined4 param_2,float *param_3)
{
  float fVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 uVar9;
  
  uVar9 = _savefpr_27();
  iVar2 = (int)((ulonglong)uVar9 >> 0x20);
  if (cRam00000000 != '\0') {
    OSPanic(...data.0,0xce,@126);
  }
  if (iVar2 == 0) {
    OSPanic(...data.0,0xcf,@127);
  }
  if (0x280 < ((uint)uVar9 & 0xffff)) {
    OSPanic(...data.0,0xd0,@128);
  }
  if (@129 == (double)param_3[0xf]) {
    dVar8 = (double)(param_3[0xb] / (param_3[10] - @130));
    fVar1 = (float)(dVar8 * (double)(@130 + param_3[2])) / *param_3;
  }
  else {
    dVar8 = (double)((@130 + param_3[0xb]) / param_3[10]);
    fVar1 = -(param_3[3] - @130) / *param_3;
  }
  dVar7 = (double)fVar1;
  dVar6 = (double)(@111 / (float)((double)CONCAT44(0x43300000,(uint)uVar9 & 0xffff) - @133));
  for (uVar4 = 0; uVar4 < 10; uVar4 = uVar4 + 1) {
    fVar1 = (float)((double)(float)((double)(float)((double)CONCAT44(0x43300000,(uVar4 + 1) * 0x20)
                                                   - @133) * dVar6) * dVar7);
    dVar5 = (double)sqrtf__Ff((double)(@130 + (fVar1 * fVar1) / (float)(dVar8 * dVar8)));
    uVar3 = __cvt_fp2unsigned((double)(float)((double)@131 * dVar5));
    *(ushort *)(iVar2 + uVar4 * 2) = uVar3 & 0xfff;
  }
  _restfpr_27();
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetFogRangeAdj(byte param_1,uint param_2,int param_3)
{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x106,@145);
  }
  if (param_1 != 0) {
    if (param_3 == 0) {
      OSPanic(...data.0,0x109,@146);
    }
    uVar4 = 0;
    while( true ) {
      if (9 < uVar4) break;
      if ((*(ushort *)(param_3 + uVar4 * 2) & 0xf000) != 0) {
        OSPanic(...data.0,0x10d,@114);
      }
      uVar1 = *(ushort *)(param_3 + uVar4 * 2);
      if ((*(ushort *)(param_3 + (uVar4 + 1) * 2) & 0xf000) != 0) {
        OSPanic(...data.0,0x10e,@114);
      }
      uVar2 = *(ushort *)(param_3 + (uVar4 + 1) * 2);
      if (((uVar4 >> 1) + 0xe9 & 0xffffff00) != 0) {
        OSPanic(...data.0,0x10f,@114);
      }
      uVar3 = ((uVar4 >> 1) + 0xe9) * 0x1000000;
      _DAT_cc008000 = uVar3 | uVar1 & 0xff000fff | (uVar2 & 0xfff) << 0xc;
      *(uint *)(iRam00000000 + (uVar3 >> 0x16) + 0xcc8) = _DAT_cc008000;
      uVar4 = uVar4 + 2;
    }
  }
  if (((param_2 & 0xffff) + 0x156 & 0xfffffc00) != 0) {
    OSPanic(...data.0,0x115,@114);
  }
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x116,@114);
  }
  _DAT_cc008000 = (param_2 & 0xffff) + 0x156 & 0xfffbff | (uint)param_1 << 10 | 0xe8000000;
  *(uint *)(iRam00000000 + 0x1068) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010888) */
/* WARNING: Removing unreachable block (ram,0x000108e0) */
/* WARNING: Removing unreachable block (ram,0x00010930) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetBlendMode(int param_1,uint param_2,uint param_3,uint param_4)
{
  uint uVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x12f,@148);
  }
  uVar1 = 0;
  if ((param_1 == 1) || (param_1 == 3)) {
    uVar1 = 1;
  }
  *(uint *)(iRam00000000 + 0x1d0) = *(uint *)(iRam00000000 + 0x1d0) & 0xfffffffe | uVar1;
  *(uint *)(iRam00000000 + 0x1d0) =
       *(uint *)(iRam00000000 + 0x1d0) & 0xfffff7ff | (LZCOUNT(3 - param_1) & 0x3ffffe0U) << 6;
  *(uint *)(iRam00000000 + 0x1d0) =
       *(uint *)(iRam00000000 + 0x1d0) & 0xfffffffd | (uint)LZCOUNT(2 - param_1) >> 4 & 0xffffffe;
  if ((param_4 & 0xfffffff0) != 0) {
    OSPanic(...data.0,0x139,@114);
  }
  *(uint *)(iRam00000000 + 0x1d0) = *(uint *)(iRam00000000 + 0x1d0) & 0xffff0fff | param_4 << 0xc;
  if ((param_2 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x13a,@114);
  }
  *(uint *)(iRam00000000 + 0x1d0) = *(uint *)(iRam00000000 + 0x1d0) & 0xfffff8ff | param_2 << 8;
  if ((param_3 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x13b,@114);
  }
  *(uint *)(iRam00000000 + 0x1d0) = *(uint *)(iRam00000000 + 0x1d0) & 0xffffff1f | param_3 << 5;
  *(uint *)(iRam00000000 + 0x1d0) = *(uint *)(iRam00000000 + 0x1d0) & 0xffffff | 0x41000000;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1d0);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d0) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1d0);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetColorUpdate(uint param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x14f,@150);
  }
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x150,@114);
  }
  *(uint *)(iRam00000000 + 0x1d0) =
       *(uint *)(iRam00000000 + 0x1d0) & 0xfffffff7 | (param_1 & 0xff) << 3;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1d0);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d0) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1d0);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetAlphaUpdate(uint param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x158,@152);
  }
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x159,@114);
  }
  *(uint *)(iRam00000000 + 0x1d0) =
       *(uint *)(iRam00000000 + 0x1d0) & 0xffffffef | (param_1 & 0xff) << 4;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1d0);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d0) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1d0);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetZMode(uint param_1,uint param_2,uint param_3)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x170,@154);
  }
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x171,@114);
  }
  *(uint *)(iRam00000000 + 0x1d8) = *(uint *)(iRam00000000 + 0x1d8) & 0xfffffffe | param_1 & 0xff;
  if ((param_2 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x172,@114);
  }
  *(uint *)(iRam00000000 + 0x1d8) = *(uint *)(iRam00000000 + 0x1d8) & 0xfffffff1 | param_2 << 1;
  if ((param_3 & 0xfe) != 0) {
    OSPanic(...data.0,0x173,@114);
  }
  *(uint *)(iRam00000000 + 0x1d8) =
       *(uint *)(iRam00000000 + 0x1d8) & 0xffffffef | (param_3 & 0xff) << 4;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1d8);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d8) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1d8);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetZCompLoc(uint param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x17c,@156);
  }
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x17d,@114);
  }
  *(uint *)(iRam00000000 + 0x1dc) =
       *(uint *)(iRam00000000 + 0x1dc) & 0xffffffbf | (param_1 & 0xff) << 6;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1dc);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1dc) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1dc);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Removing unreachable block (ram,0x00010ffc) */
/* WARNING: Removing unreachable block (ram,0x00010f98) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetPixelFmt(int param_1,uint param_2)
{
  int iVar1;
  
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x1a1,@163);
  }
  iVar1 = *(int *)(iRam00000000 + 0x1dc);
  if ((param_1 < 0) || (7 < param_1)) {
    OSPanic(...data.0,0x1a5,@164);
  }
  if ((*(uint *)(p2f$157 + param_1 * 4) & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x1a7,@114);
  }
  *(uint *)(iRam00000000 + 0x1dc) =
       *(uint *)(iRam00000000 + 0x1dc) & 0xfffffff8 | *(uint *)(p2f$157 + param_1 * 4);
  if ((param_2 & 0xfffffff8) != 0) {
    OSPanic(...data.0,0x1a8,@114);
  }
  *(uint *)(iRam00000000 + 0x1dc) = *(uint *)(iRam00000000 + 0x1dc) & 0xffffffc7 | param_2 << 3;
  if (iVar1 != *(int *)(iRam00000000 + 0x1dc)) {
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1dc);
    *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1dc) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + 0x1dc);
    *(uint *)(iRam00000000 + 0x204) =
         *(uint *)(iRam00000000 + 0x204) & 0xfffffdff | (uint)(param_1 == 2) << 9;
    *(uint *)(iRam00000000 + 0x4f4) = *(uint *)(iRam00000000 + 0x4f4) | 4;
  }
  if (*(int *)(p2f$157 + param_1 * 4) == 4) {
    *(uint *)(iRam00000000 + 0x1d4) =
         (param_1 + -4) * 0x200 & 0x600U | *(uint *)(iRam00000000 + 0x1d4) & 0xfffff9ff;
    *(uint *)(iRam00000000 + 0x1d4) = *(uint *)(iRam00000000 + 0x1d4) & 0xffffff | 0x42000000;
    _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1d4);
    *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d4) >> 0x16 & 0x3fc) + 0xcc8) =
         *(undefined4 *)(iRam00000000 + 0x1d4);
  }
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetDither(uint param_1)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x1cd,@166);
  }
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x1ce,@114);
  }
  *(uint *)(iRam00000000 + 0x1d0) =
       *(uint *)(iRam00000000 + 0x1d0) & 0xfffffffb | (param_1 & 0xff) << 2;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1d0);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d0) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1d0);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Removing unreachable block (ram,0x000111bc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetDstAlpha(uint param_1,uint param_2)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x1e1,@168);
  }
  *(uint *)(iRam00000000 + 0x1d4) = *(uint *)(iRam00000000 + 0x1d4) & 0xffffff00 | param_2 & 0xff;
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x1e3,@114);
  }
  *(uint *)(iRam00000000 + 0x1d4) =
       *(uint *)(iRam00000000 + 0x1d4) & 0xfffffeff | (param_1 & 0xff) << 8;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x1d4);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x1d4) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x1d4);
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetFieldMask(uint param_1,uint param_2)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x1f9,@170);
  }
  if ((param_2 & 0xfe) != 0) {
    OSPanic(...data.0,0x1fb,@114);
  }
  if ((param_1 & 0xfe) != 0) {
    OSPanic(...data.0,0x1fc,@114);
  }
  _DAT_cc008000 = param_2 & 0xfd | (param_1 & 0xff) << 1 | 0x44000000;
  *(uint *)(iRam00000000 + 0xdd8) = _DAT_cc008000;
  *(undefined2 *)(iRam00000000 + 2) = 0;
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXSetFieldMode(byte param_1,uint param_2)
{
  if (iRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x216,@172);
  }
  if ((param_2 & 0xfe) != 0) {
    OSPanic(...data.0,0x21a,@114);
  }
  *(uint *)(iRam00000000 + 0x7c) =
       *(uint *)(iRam00000000 + 0x7c) & 0xffbfffff | (param_2 & 0xff) << 0x16;
  _DAT_cc008000 = *(undefined4 *)(iRam00000000 + 0x7c);
  *(undefined4 *)(iRam00000000 + (*(uint *)(iRam00000000 + 0x7c) >> 0x16 & 0x3fc) + 0xcc8) =
       *(undefined4 *)(iRam00000000 + 0x7c);
  __GXFlushTextureState();
  _DAT_cc008000 = param_1 | 0x68000000;
  *(uint *)(iRam00000000 + 0xe68) = _DAT_cc008000;
  __GXFlushTextureState();
  return;
}
