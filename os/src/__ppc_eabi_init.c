void __init_user(void)
{
  __init_cpp();
  return;
}

void __init_cpp(void)
{
  code **ppcVar1;
  
  for (ppcVar1 = (code **)&_ctors; *ppcVar1 != (code *)0x0; ppcVar1 = ppcVar1 + 1) {
    (**ppcVar1)();
  }
  return;
}

void __fini_cpp(void)
{
  code **ppcVar1;
  
  for (ppcVar1 = (code **)&_dtors; *ppcVar1 != (code *)0x0; ppcVar1 = ppcVar1 + 1) {
    (**ppcVar1)();
  }
  return;
}

void abort(void)
{
  _ExitProcess();
  return;
}

void exit(int __status)
{
  __fini_cpp();
  _ExitProcess();
  return;
}

void _ExitProcess(void)
{
  PPCHalt();
  return;
}

void __init_hardware(void)
{
  __OSPSInit();
  __OSCacheInit();
  return;
}

                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __flush_cache()
             undefined         r3:1           <RETURN>
                             __flush_cache                                   XREF[1]:     Entry Point(*)  
        0001013c 3c a0 ff ff     lis        r5,-0x1
        00010140 60 a5 ff f1     ori        r5,r5,0xfff1
        00010144 7c a5 18 38     and        r5,r5,r3
        00010148 7c 65 18 50     subf       r3,r5,r3
        0001014c 7c 84 1a 14     add        r4,r4,r3
                             LAB_00010150                                    XREF[1]:     00010164(j)  
        00010150 7c 00 28 6c     dcbst      0,r5
        00010154 7c 00 04 ac     sync       0x0
        00010158 7c 00 2f ac     icbi       0,r5
        0001015c 30 a5 00 08     addic      r5,r5,0x8
        00010160 34 84 ff f8     subic.     r4,r4,0x8
        00010164 40 80 ff ec     bge        LAB_00010150
        00010168 4c 00 01 2c     isync
        0001016c 4e 80 00 20     blr
