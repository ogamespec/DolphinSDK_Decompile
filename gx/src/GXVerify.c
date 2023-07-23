void __GXVerifyGlobal(void)
{
  return;
}

void __GXVerifyCP(int param_1)
{
  uint uVar1;
  
  uVar1 = *(uint *)(iRam00000000 + param_1 * 4 + 0x1c) >> 9 & 1;
  if (0 < *(int *)(__gxVerif + 4)) {
    if ((*(char *)(iRam00000000 + 0x41c) == '\0') || (uVar1 == 0)) {
      if ((*(char *)(iRam00000000 + 0x41d) != '\0') &&
         ((uVar1 != 1 && ((int)__gxvWarnLev._0_4_ <= *(int *)(__gxVerif + 4))))) {
        sprintf(__gxvDummyStr,__gxvWarnings,@138);
        (**(code **)__gxVerif)(__gxvWarnLev._0_4_,0,__gxvDummyStr);
      }
    }
    else if ((int)__gxvWarnLev._0_4_ <= *(int *)(__gxVerif + 4)) {
      sprintf(__gxvDummyStr,__gxvWarnings,@137);
      (**(code **)__gxVerif)(__gxvWarnLev._0_4_,0,__gxvDummyStr);
    }
  }
  return;
}

void __GXVerifyState(undefined4 param_1)
{
  if (*(int *)(__gxVerif + 4) != 0) {
    __GXVerifyGlobal();
    __GXVerifyCP(param_1);
    __GXVerifyXF();
    __GXVerifySU();
    __GXVerifyBUMP();
    __GXVerifyTEX();
    __GXVerifyTEV();
    __GXVerifyPE();
  }
  return;
}

void GXSetVerifyLevel(undefined4 param_1)
{
  *(undefined4 *)(__gxVerif + 4) = param_1;
  return;
}

undefined4 GXSetVerifyCallback(undefined4 param_1)
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)__gxVerif;
  *(undefined4 *)__gxVerif = param_1;
  return uVar1;
}
