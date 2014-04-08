# 1 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/core/src/arm_abort.S"
# 1 "<command-line>"
# 1 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/core/src/arm_abort.S"
# 31 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/core/src/arm_abort.S"
    .code 32
    .section ".text","ax"

    .extern dump_regs






    .global common_abort_handler
    .func common_abort_handler
common_abort_handler:
 push {r0-r12}
 mrs r7, cpsr
 mrs r6, spsr
 mov r5, sp
 msr cpsr, r6
 dsb
 stmfd r5!, {sp, lr}
 msr cpsr, r7
 dsb
 mov sp, r5
 push {r6, lr}


 mrc p15, 0, r4, c5, c0, 0
 mrc p15, 0, r3, c6, c0, 0
 mrc p15, 0, r2, c5, c0, 1
 mrc p15, 0, r1, c6, c0, 2
 push {r1-r4}

 ldr r1,=.Labort_type
 ldr r0,[r1]
 mov r1, sp
 bl dump_regs


 pop {r0-r12}
 add sp, sp, #16


1:
 b 1b

 sub pc, lr, #4
    .endfunc

    .global data_abort_handler
    .func data_abort_handler
data_abort_handler:
    push {r0-r1}
    ldr r1,=.Labort_type
    mov r0,#0
    str r0,[r1]
    pop {r0-r1}
    b common_abort_handler
    .endfunc

    .global prefetch_abort_handler
    .func prefetch_abort_handler
prefetch_abort_handler:
    push {r0-r1}
    ldr r1,=.Labort_type
    mov r0,#1
    str r0,[r1]
    pop {r0-r1}
    b common_abort_handler
    .endfunc



    .data




.Labort_type:
    .word 0

    .end
