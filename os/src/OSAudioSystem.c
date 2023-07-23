void __OSInitAudioSystem(void)
{
  int iVar1;
  
  iVar1 = OSGetArenaHi();
  memcpy((void *)(iVar1 + -0x80),(void *)0x81000000,0x80);
  memcpy((void *)0x81000000,DSPInitCode,0x80);
  DCFlushRange(0x81000000,0x80);
  _DAT_cc005012 = 0x43;
  if ((_DAT_cc00500a & 0x200) != 0) {
    OSPanic(@36,0x71,@37);
  }
  if ((_DAT_cc00500a & 0x400) != 0) {
    OSPanic(@36,0x75,@38);
  }
  if ((_DAT_cc00500a & 4) == 0) {
    OSPanic(@36,0x79,@39);
  }
  do {
  } while( true );
}

void __OSStopAudioSystem(void)

{
  int iVar1;
  int iVar2;
  
  _DAT_cc005036 = _DAT_cc005036 & 0x7fff;
  _DAT_cc00500a = 0x8ac;
  _DAT_cc005000 = 0;
  do {
  } while ((_DAT_cc005004 & 0x8000) != 0);
  iVar1 = OSGetTick();
  do {
    iVar2 = OSGetTick();
  } while (iVar2 - iVar1 < 0x2c);
  do {
  } while( true );
}

// TODO: DSPInitCode
