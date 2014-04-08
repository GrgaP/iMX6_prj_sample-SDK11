# 1 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/core/src/vectors.S"
# 1 "<command-line>"
# 1 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/core/src/vectors.S"
# 31 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/core/src/vectors.S"
# 1 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/include/asm_defines.h" 1
# 32 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/core/src/vectors.S" 2

    .code 32

    .global _start
    .global data_abort_handler
    .global prefetch_abort_handler
    .global IRQ_HDLR







    .section .text.vectors,"ax"

    .global vectors

vectors:
    ldr pc, .Lreset_addr
    ldr pc, .Lundefined_addr
    ldr pc, .Lswi_addr
    ldr pc, .Lprefetch_abort_addr
    ldr pc, .Ldata_abort_addr
    ldr pc, .Lreserved_addr
    ldr pc, .Lirq_addr
    ldr pc, .Lfiq_addr
    .word 0

.Lreset_addr:
    .word _start
.Lundefined_addr:
    .word exception_handler
.Lswi_addr:
    .word exception_handler
.Lprefetch_abort_addr:
    .word prefetch_abort_handler
.Ldata_abort_addr:
    .word data_abort_handler
.Lreserved_addr:
    .word exception_handler
.Lirq_addr:
    .word IRQ_HDLR
.Lfiq_addr:
    .word exception_handler

    .word 0


    .text




    .global exception_handler
    .func exception_handler


exception_handler:



1:
        b 1b
    .endfunc

    .end
