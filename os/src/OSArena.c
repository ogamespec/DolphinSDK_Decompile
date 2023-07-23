uint OSGetArenaHi(void)
{
  if (__OSArenaLo == 0xffffffff) {
    OSPanic(...data.0,0x37,@3);
  }
  if (__OSArenaHi < __OSArenaLo) {
    OSPanic(...data.0,0x39,@4);
  }
  return __OSArenaHi;
}

uint OSGetArenaLo(void)
{
  if (__OSArenaLo == 0xffffffff) {
    OSPanic(...data.0,0x49,@6);
  }
  if (__OSArenaHi < __OSArenaLo) {
    OSPanic(...data.0,0x4b,@7);
  }
  return __OSArenaLo;
}

void OSSetArenaHi(undefined4 param_1)
{
  __OSArenaHi = param_1;
  return;
}

void OSSetArenaLo(undefined4 param_1)
{
  __OSArenaLo = param_1;
  return;
}

uint OSAllocFromArenaLo(int param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = OSGetArenaLo();
  uVar2 = iVar1 + param_2 + -1 & ~(param_2 - 1U);
  OSSetArenaLo(uVar2 + param_1 + param_2 + -1 & ~(param_2 - 1U));
  return uVar2;
}

uint OSAllocFromArenaHi(int param_1,int param_2)
{
  uint uVar1;
  
  uVar1 = OSGetArenaHi();
  uVar1 = (uVar1 & ~(param_2 - 1U)) - param_1 & ~(param_2 - 1U);
  OSSetArenaHi(uVar1);
  return uVar1;
}
