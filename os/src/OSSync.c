                             //
                             // .text 
                             // SHT_PROGBITS  [0x0 - 0x8f]
                             // ram:00010000-ram:0001008f
                             //
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined SystemCallVector()
             undefined         r3:1           <RETURN>
                             __OSSystemCallVectorStart                       XREF[4]:     Entry Point(*), 
                             SystemCallVector                                             __OSInitSystemCall:00010044(*), 
                                                                                          __OSInitSystemCall:0001004c(*), 
                                                                                          _elfSectionHeaders::00000034(*)  
        00010000 7d 30 fa a6     mfspr      r9,DBSR
        00010004 61 2a 00 08     ori        r10,r9,0x8
        00010008 7d 50 fb a6     mtspr      DBSR,r10
        0001000c 4c 00 01 2c     isync
        00010010 7c 00 04 ac     sync       0x0
        00010014 7d 30 fb a6     mtspr      DBSR,r9
        00010018 4c 00 00 64     rfi
                             **************************************************************
                             *                          FUNCTION                          *
                             **************************************************************
                             undefined __OSSystemCallVectorEnd()
             undefined         r3:1           <RETURN>
                             __OSSystemCallVectorEnd                         XREF[1]:     Entry Point(*)  
        0001001c 60 00 00 00     ori        r0,r0,0x0


void __OSInitSystemCall(void)
{
  void *__dest;
  
  __dest = (void *)OSPhysicalToCached(0xc00);
  memcpy(__dest,SystemCallVector,0x1c);
  DCFlushRangeNoSync(__dest,0x100);
  sync(0);
  ICInvalidateRange(__dest,0x100);
  return;
}
