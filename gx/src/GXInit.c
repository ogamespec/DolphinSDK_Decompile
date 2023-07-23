uint IsWriteGatherBufferEmpty(void)
{
  uint in_spr399;
  
  sync(0);
  return in_spr399 & 1;
}

void EnableWriteGatherPipe(void)
{
  uint uVar1;
  
  uVar1 = PPCMfhid2();
  OSUncachedToPhysical(&DAT_cc008000);
  PPCMtwpar();
  PPCMthid2(uVar1 | 0x40000000);
  return;
}

void DisableWriteGatherPipe(void)
{
  uint uVar1;
  
  uVar1 = PPCMfhid2();
  PPCMthid2(uVar1 & 0xbfffffff);
  return;
}

undefined * __GXDefaultTexRegionCallback(undefined4 param_1)
{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = GXGetTexObjFmt(param_1);
  puVar1 = gx;
  if (((iVar2 == 8) || (iVar2 == 9)) || (iVar2 == 10)) {
    uVar3 = *(uint *)(gx + 0x2cc);
    *(uint *)(gx + 0x2cc) = uVar3 + 1;
    iVar2 = (uVar3 & 3) * 0x10 + 0x288;
  }
  else {
    uVar3 = *(uint *)(gx + 0x2c8);
    *(uint *)(gx + 0x2c8) = uVar3 + 1;
    iVar2 = (uVar3 & 7) * 0x10 + 0x208;
  }
  return puVar1 + iVar2;
}

void __GXDefaultVerifyCallback(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  OSReport(...data.0,param_1,param_2,param_3);
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
undefined1 * GXInit(undefined4 param_1,undefined4 param_2)
{
  uint uVar1;
  
  gx[0x4f0] = 0;
  gx[0x4f1] = 1;
  __GXinBegin = 0;
  *(undefined4 *)(gx + 0x4dc) = 0;
  *(undefined4 *)(gx + 0x4e0) = 0;
  *(undefined2 *)(gx + 4) = 0;
  __piReg = OSPhysicalToUncached(0xc003000);
  __cpReg = OSPhysicalToUncached(0xc000000);
  __peReg = OSPhysicalToUncached(0xc001000);
  __memReg = OSPhysicalToUncached(0xc004000);
  __GXFifoInit();
  GXInitFifoBase(FifoObj,param_1,param_2);
  GXSetCPUFifo(FifoObj);
  GXSetGPFifo(FifoObj);
  __GXPEInit();
  EnableWriteGatherPipe();
  *(undefined4 *)(gx + 0x204) = 0;
  *(uint *)(gx + 0x204) = *(uint *)(gx + 0x204) & 0xffffff;
  *(undefined4 *)(gx + 0x124) = 0xff;
  *(uint *)(gx + 0x124) = *(uint *)(gx + 0x124) & 0xffffff | 0xf000000;
  *(undefined4 *)(gx + 0x7c) = 0;
  *(uint *)(gx + 0x7c) = *(uint *)(gx + 0x7c) & 0xffffff | 0x22000000;
  for (uVar1 = 0; uVar1 < 0x10; uVar1 = uVar1 + 1) {
    *(undefined4 *)(gx + uVar1 * 4 + 0x130) = 0;
    *(undefined4 *)(gx + uVar1 * 4 + 0x170) = 0;
    *(undefined4 *)(gx + (uVar1 >> 1) * 4 + 0x100) = 0;
    *(undefined4 *)(gx + uVar1 * 4 + 0x49c) = 0xff;
    if ((uVar1 * 2 + 0xc0 & 0xffffff00) != 0) {
      OSPanic(@91,0x30c,@92);
    }
    *(uint *)(gx + uVar1 * 4 + 0x130) =
         *(uint *)(gx + uVar1 * 4 + 0x130) & 0xffffff | (uVar1 * 2 + 0xc0) * 0x1000000;
    if ((uVar1 * 2 + 0xc1 & 0xffffff00) != 0) {
      OSPanic(@91,0x30d,@92);
    }
    *(uint *)(gx + uVar1 * 4 + 0x170) =
         *(uint *)(gx + uVar1 * 4 + 0x170) & 0xffffff | (uVar1 * 2 + 0xc1) * 0x1000000;
    if (((uVar1 >> 1) + 0xf6 & 0xffffff00) != 0) {
      OSPanic(@91,0x30f,@92);
    }
    *(uint *)(gx + (uVar1 >> 1) * 4 + 0x1b0) =
         *(uint *)(gx + (uVar1 >> 1) * 4 + 0x1b0) & 0xffffff | ((uVar1 >> 1) + 0xf6) * 0x1000000;
    if (((uVar1 >> 1) + 0x28 & 0xffffff00) != 0) {
      OSPanic(@91,0x311,@92);
    }
    *(uint *)(gx + (uVar1 >> 1) * 4 + 0x100) =
         *(uint *)(gx + (uVar1 >> 1) * 4 + 0x100) & 0xffffff | ((uVar1 >> 1) + 0x28) * 0x1000000;
  }
  *(undefined4 *)(gx + 0x120) = 0;
  *(uint *)(gx + 0x120) = *(uint *)(gx + 0x120) & 0xffffff | 0x27000000;
  for (uVar1 = 0; uVar1 < 8; uVar1 = uVar1 + 1) {
    *(undefined4 *)(gx + uVar1 * 4 + 0xb8) = 0;
    *(undefined4 *)(gx + uVar1 * 4 + 0xd8) = 0;
    if ((uVar1 * 2 + 0x30 & 0xffffff00) != 0) {
      OSPanic(@91,0x31a,@92);
    }
    *(uint *)(gx + uVar1 * 4 + 0xb8) =
         *(uint *)(gx + uVar1 * 4 + 0xb8) & 0xffffff | (uVar1 * 2 + 0x30) * 0x1000000;
    if ((uVar1 * 2 + 0x31 & 0xffffff00) != 0) {
      OSPanic(@91,0x31b,@92);
    }
    *(uint *)(gx + uVar1 * 4 + 0xd8) =
         *(uint *)(gx + uVar1 * 4 + 0xd8) & 0xffffff | (uVar1 * 2 + 0x31) * 0x1000000;
  }
  *(uint *)(gx + 0xf8) = *(uint *)(gx + 0xf8) & 0xffffff | 0x20000000;
  *(uint *)(gx + 0xfc) = *(uint *)(gx + 0xfc) & 0xffffff | 0x21000000;
  *(uint *)(gx + 0x1d0) = *(uint *)(gx + 0x1d0) & 0xffffff | 0x41000000;
  *(uint *)(gx + 0x1d4) = *(uint *)(gx + 0x1d4) & 0xffffff | 0x42000000;
  *(uint *)(gx + 0x1d8) = *(uint *)(gx + 0x1d8) & 0xffffff | 0x40000000;
  *(uint *)(gx + 0x1dc) = *(uint *)(gx + 0x1dc) & 0xffffff | 0x43000000;
  *(uint *)(gx + 0x1fc) = *(uint *)(gx + 0x1fc) & 0xfffffe7f;
  *(undefined4 *)(gx + 0x4f4) = 0;
  gx[0x4f2] = 0;
  *(undefined4 *)(iRam00000000 + 4) = 3;
  GXSetVerifyCallback(__GXDefaultVerifyCallback);
  for (uVar1 = 0; uVar1 < 0x100; uVar1 = uVar1 + 1) {
    *(uint *)(iRam00000000 + uVar1 * 4 + 0xcc8) =
         *(uint *)(iRam00000000 + uVar1 * 4 + 0xcc8) & 0xffffff | 0xff000000;
  }
  memset((void *)(iRam00000000 + 0x10c8),0,0x50);
  memset((void *)(iRam00000000 + 0x1118),0,0x100);
  memset((void *)(iRam00000000 + 0x1218),0,0x60);
  memset((void *)(iRam00000000 + 0x1378),0,0x80);
  uVar1 = _DAT_800000f8 / 500;
  __GXFlushTextureState();
  _DAT_cc008000 = uVar1 >> 0xb | 0x69000400;
  *(uint *)(iRam00000000 + 0xe6c) = _DAT_cc008000;
  __GXFlushTextureState();
  *(uint *)(iRam00000000 + 0xde0) = uVar1 / 0x1080 | 0x46000200;
  for (uVar1 = 0; uVar1 < 8; uVar1 = uVar1 + 1) {
    *(uint *)(gx + uVar1 * 4 + 0x1c) = *(uint *)(gx + uVar1 * 4 + 0x1c) & 0xbfffffff | 0x40000000;
    *(uint *)(gx + uVar1 * 4 + 0x3c) = *(uint *)(gx + uVar1 * 4 + 0x3c) & 0x7fffffff | 0x80000000;
  }
  *(undefined4 *)(iRam00000000 + 8) = 0x3f;
  *(undefined *)(iRam00000000 + 0x10c8) = 1;
  *(undefined4 *)(iRam00000000 + 0x50) = 1;
  *(undefined *)(iRam00000000 + 0x10da) = 1;
  *(undefined *)(iRam00000000 + 0x10c8) = 0;
  _DAT_cc008000 = 0x5800000f;
  *(undefined4 *)(iRam00000000 + 0xe28) = 0x5800000f;
  for (uVar1 = 0; uVar1 < 8; uVar1 = uVar1 + 1) {
    GXInitTexCacheRegion(gx + uVar1 * 0x10 + 0x208,0,uVar1 << 0xf,0,uVar1 * 0x8000 + 0x80000,0);
  }
  for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1) {
    GXInitTexCacheRegion
              (gx + uVar1 * 0x10 + 0x288,0,(uVar1 * 2 + 8) * 0x8000,0,(uVar1 * 2 + 9) * 0x8000,0);
  }
  for (uVar1 = 0; uVar1 < 0x10; uVar1 = uVar1 + 1) {
    GXInitTlutRegion(gx + uVar1 * 0x10 + 0x2d0,uVar1 * 0x2000 + 0xc0000,0x10);
  }
  for (uVar1 = 0; uVar1 < 4; uVar1 = uVar1 + 1) {
    GXInitTlutRegion(gx + (uVar1 + 0x10) * 0x10 + 0x2d0,uVar1 * 0x8000 + 0xe0000,0x40);
  }
  *(undefined2 *)(__cpReg + 6) = 0;
  *(uint *)(gx + 0x4ec) = *(uint *)(gx + 0x4ec) & 0xffffff0f;
  *(undefined4 *)(iRam00000000 + 0x20) = 0;
  *(undefined *)(iRam00000000 + 0x10ce) = 1;
  *(undefined4 *)(iRam00000000 + 0xd54) = 0x23000000;
  *(undefined4 *)(iRam00000000 + 0xd58) = 0x24000000;
  _DAT_cc008000 = 0x67000000;
  *(undefined4 *)(iRam00000000 + 0xe64) = 0x67000000;
  __GXSetTmemConfig(0);
  __GXInitGX();
  return FifoObj;
}

void __GXInitGX(void)
{
  int iVar1;
  uint uVar2;
  undefined *puVar3;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_18;
  uint uStack_14;
  undefined4 local_10;
  uint uStack_c;
  
  local_50 = @93;
  local_54 = @94;
  local_58 = @95;
  iVar1 = VIGetTvFormat();
  if (iVar1 == 2) {
    puVar3 = &GXMpal480IntDf;
    goto LAB_00010d30;
  }
  if (iVar1 < 2) {
    if (iVar1 == 0) {
      puVar3 = &GXNtsc480IntDf;
      goto LAB_00010d30;
    }
    if (-1 < iVar1) {
      puVar3 = &GXPal528IntDf;
      goto LAB_00010d30;
    }
  }
  else if (iVar1 == 5) {
    puVar3 = &GXEurgb60Hz480IntDf;
    goto LAB_00010d30;
  }
  OSPanic(@91,0x415,@130);
  puVar3 = &GXNtsc480IntDf;
LAB_00010d30:
  local_5c = local_50;
  GXSetCopyClear(&local_5c,0xffffff);
  GXSetTexCoordGen(0,1,4,0x3c);
  GXSetTexCoordGen(1,1,5,0x3c);
  GXSetTexCoordGen(2,1,6,0x3c);
  GXSetTexCoordGen(3,1,7,0x3c);
  GXSetTexCoordGen(4,1,8,0x3c);
  GXSetTexCoordGen(5,1,9,0x3c);
  GXSetTexCoordGen(6,1,10,0x3c);
  GXSetTexCoordGen(7,1,0xb,0x3c);
  GXSetNumTexGens(1);
  GXClearVtxDesc();
  GXInvalidateVtxCache();
  for (uVar2 = 9; uVar2 < 0x19; uVar2 = uVar2 + 1) {
    GXSetArray(uVar2,gx,0);
  }
  GXSetLineWidth(6,0);
  GXSetPointSize(6,0);
  GXEnableTexOffsets(0,0,0);
  GXEnableTexOffsets(1,0,0);
  GXEnableTexOffsets(2,0,0);
  GXEnableTexOffsets(3,0,0);
  GXEnableTexOffsets(4,0,0);
  GXEnableTexOffsets(5,0,0);
  GXEnableTexOffsets(6,0,0);
  GXEnableTexOffsets(7,0,0);
  local_4c = @131;
  local_48 = @132;
  local_44 = @132;
  local_40 = @132;
  local_3c = @132;
  local_38 = @131;
  local_34 = @132;
  local_30 = @132;
  local_2c = @132;
  local_28 = @132;
  local_24 = @131;
  local_20 = @132;
  GXLoadPosMtxImm(&local_4c,0);
  GXLoadNrmMtxImm(&local_4c,0);
  GXSetCurrentMtx(0);
  GXLoadTexMtxImm(&local_4c,0x3c,0);
  GXLoadTexMtxImm(&local_4c,0x7d,0);
  uStack_c = (uint)*(ushort *)(puVar3 + 4);
  local_10 = 0x43300000;
  uStack_14 = (uint)*(ushort *)(puVar3 + 8);
  local_18 = 0x43300000;
  GXSetViewport((double)@132,(double)@132,
                (double)(float)((double)CONCAT44(0x43300000,uStack_c) - @135),
                (double)(float)((double)CONCAT44(0x43300000,uStack_14) - @135),(double)@132,
                (double)@131);
  GXSetCoPlanar(0);
  GXSetCullMode(2);
  GXSetClipMode(0);
  GXSetScissor(0,0,*(undefined2 *)(puVar3 + 4),*(undefined2 *)(puVar3 + 6));
  GXSetScissorBoxOffset(0,0);
  GXSetNumChans(0);
  GXSetChanCtrl(4,0,0,1,0,0,2);
  local_60 = local_54;
  GXSetChanAmbColor(4,&local_60);
  local_64 = local_58;
  GXSetChanMatColor(4,&local_64);
  GXSetChanCtrl(5,0,0,1,0,0,2);
  local_68 = local_54;
  GXSetChanAmbColor(5,&local_68);
  local_6c = local_58;
  GXSetChanMatColor(5,&local_6c);
  GXInvalidateTexAll();
  *(undefined4 *)(gx + 0x2c8) = 0;
  *(undefined4 *)(gx + 0x2cc) = 0;
  GXSetTexRegionCallback(__GXDefaultTexRegionCallback);
  GXSetTlutRegionCallback(__GXDefaultTlutRegionCallback);
  GXSetTevOrder(0,0,0,4);
  GXSetTevOrder(1,1,1,4);
  GXSetTevOrder(2,2,2,4);
  GXSetTevOrder(3,3,3,4);
  GXSetTevOrder(4,4,4,4);
  GXSetTevOrder(5,5,5,4);
  GXSetTevOrder(6,6,6,4);
  GXSetTevOrder(7,7,7,4);
  GXSetTevOrder(8,0xff,0xff,0xff);
  GXSetTevOrder(9,0xff,0xff,0xff);
  GXSetTevOrder(10,0xff,0xff,0xff);
  GXSetTevOrder(0xb,0xff,0xff,0xff);
  GXSetTevOrder(0xc,0xff,0xff,0xff);
  GXSetTevOrder(0xd,0xff,0xff,0xff);
  GXSetTevOrder(0xe,0xff,0xff,0xff);
  GXSetTevOrder(0xf,0xff,0xff,0xff);
  GXSetNumTevStages(1);
  GXSetTevOp(0,3);
  GXSetAlphaCompare(7,0,0,7,0);
  GXSetZTexture(0,0x11,0);
  for (uVar2 = 0; uVar2 < 0x10; uVar2 = uVar2 + 1) {
    GXSetTevKColorSel(uVar2,6);
    GXSetTevKAlphaSel(uVar2,0);
    GXSetTevSwapMode(uVar2,0,0);
  }
  GXSetTevSwapModeTable(0,0,1,2,3);
  GXSetTevSwapModeTable(1,0,0,0,3);
  GXSetTevSwapModeTable(2,1,1,1,3);
  GXSetTevSwapModeTable(3,2,2,2,3);
  for (uVar2 = 0; uVar2 < 0x10; uVar2 = uVar2 + 1) {
    GXSetTevDirect(uVar2);
  }
  GXSetNumIndStages(0);
  GXSetIndTexCoordScale(0,0,0);
  GXSetIndTexCoordScale(1,0,0);
  GXSetIndTexCoordScale(2,0,0);
  GXSetIndTexCoordScale(3,0,0);
  local_70 = local_54;
  GXSetFog((double)@132,(double)@131,(double)@133,(double)@131,0,&local_70);
  GXSetFogRangeAdj(0,0,0);
  GXSetBlendMode(0,4,5,0);
  GXSetColorUpdate(1);
  GXSetAlphaUpdate(1);
  GXSetZMode(1,3,1);
  GXSetZCompLoc(1);
  GXSetDither(1);
  GXSetDstAlpha(0,0);
  GXSetPixelFmt(0,0);
  GXSetFieldMask(1,1);
  GXSetFieldMode(puVar3[0x18],(uint)*(ushort *)(puVar3 + 0x10) == (uint)*(ushort *)(puVar3 + 8) << 1
                );
  GXSetDispCopySrc(0,0,*(undefined2 *)(puVar3 + 4),*(undefined2 *)(puVar3 + 6));
  GXSetDispCopyDst(*(undefined2 *)(puVar3 + 4),*(undefined2 *)(puVar3 + 6));
  uStack_14 = (uint)*(ushort *)(puVar3 + 8);
  local_18 = 0x43300000;
  uStack_c = (uint)*(ushort *)(puVar3 + 6);
  local_10 = 0x43300000;
  GXSetDispCopyYScale((double)((float)((double)CONCAT44(0x43300000,uStack_14) - @135) /
                              (float)((double)CONCAT44(0x43300000,uStack_c) - @135)));
  GXSetCopyClamp(3);
  GXSetCopyFilter(puVar3[0x19],puVar3 + 0x1a,1,puVar3 + 0x32);
  GXSetDispCopyGamma(0);
  GXSetDispCopyFrame2Field(0);
  GXClearBoundingBox();
  GXPokeColorUpdate(1);
  GXPokeAlphaUpdate(1);
  GXPokeDither(0);
  GXPokeBlendMode(0,0,1,0xf);
  GXPokeAlphaMode(7,0);
  GXPokeAlphaRead(1);
  GXPokeDstAlpha(0,0);
  GXPokeZMode(1,7,1);
  GXSetGPMetric(0x23,0x16);
  GXClearGPMetric();
  return;
}
