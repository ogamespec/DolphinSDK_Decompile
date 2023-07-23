void GXBeginDisplayList(uint param_1,uint param_2)
{
  undefined4 uVar1;
  
  uVar1 = GXGetCPUFifo();
  if (pvRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0x7f,@12);
  }
  if (*(char *)((int)pvRam00000000 + 0x4f0) != '\0') {
    OSPanic(...data.0,0x80,@13);
  }
  if ((param_2 & 0x1f) != 0) {
    OSPanic(...data.0,0x81,@14);
  }
  if ((param_1 & 0x1f) != 0) {
    OSPanic(...data.0,0x82,@15);
  }
  if (*(int *)((int)pvRam00000000 + 0x4f4) != 0) {
    __GXSetDirtyState();
  }
  if (*(char *)((int)pvRam00000000 + 0x4f1) != '\0') {
    memcpy(__savedGXdata,pvRam00000000,0x4f8);
  }
  DisplayListFifo._4_4_ = param_1 + (param_2 - 4);
  DisplayListFifo._28_4_ = 0;
  DisplayListFifo._0_4_ = param_1;
  DisplayListFifo._8_4_ = param_2;
  DisplayListFifo._20_4_ = param_1;
  DisplayListFifo._24_4_ = param_1;
  *(undefined *)((int)pvRam00000000 + 0x4f0) = 1;
  GXSaveCPUFifo(uVar1);
  OldCPUFifo = uVar1;
  GXSetCPUFifo(DisplayListFifo);
  return;
}

undefined4 GXEndDisplayList(void)
{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (pvRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0xb8,@24);
  }
  if (*(char *)((int)pvRam00000000 + 0x4f0) != '\x01') {
    OSPanic(...data.0,0xb9,@25);
  }
  if (*(int *)((int)pvRam00000000 + 0x4f4) != 0) {
    __GXSetDirtyState();
  }
  uVar3 = *(uint *)((int)pvRam00000000 + 0x14) >> 0x1a & 1;
  __GXSaveCPUFifoAux(DisplayListFifo);
  if (uVar3 != 0) {
    OSPanic(...data.0,0xc6,@26);
  }
  GXSetCPUFifo(OldCPUFifo);
  if (*(char *)((int)pvRam00000000 + 0x4f1) != '\0') {
    uVar1 = OSDisableInterrupts();
    uVar2 = *(undefined4 *)((int)pvRam00000000 + 8);
    memcpy(pvRam00000000,__savedGXdata,0x4f8);
    *(undefined4 *)((int)pvRam00000000 + 8) = uVar2;
    OSRestoreInterrupts(uVar1);
  }
  *(undefined *)((int)pvRam00000000 + 0x4f0) = 0;
  uVar1 = DisplayListFifo._28_4_;
  if (uVar3 != 0) {
    uVar1 = 0;
  }
  return uVar1;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
void GXCallDisplayList(uint param_1,uint param_2)
{
  if (piRam00000000._0_1_ != '\0') {
    OSPanic(...data.0,0xef,@32);
  }
  if (*(char *)(piRam00000000 + 0x13c) != '\0') {
    OSPanic(...data.0,0xf0,@33);
  }
  if ((param_2 & 0x1f) != 0) {
    OSPanic(...data.0,0xf1,@34);
  }
  if ((param_1 & 0x1f) != 0) {
    OSPanic(...data.0,0xf2,@35);
  }
  if (piRam00000000[0x13d] != 0) {
    __GXSetDirtyState();
  }
  __GXShadowDispList(param_1,param_2);
  if (*piRam00000000 == 0) {
    __GXSendFlushPrim();
  }
  _DAT_cc008000 = param_2;
  return;
}
