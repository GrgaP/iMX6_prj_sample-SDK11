# 1 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/core/src/startup.S"
# 1 "<command-line>"
# 1 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/core/src/startup.S"
# 36 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/core/src/startup.S"
# 1 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/include/asm_defines.h" 1
# 37 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/core/src/startup.S" 2


    .global top_of_stacks
    .global vectors
    .global __ram_vectors_start
    .global __ram_vectors_end
    .global __bss_start__
    .global __bss_end__
    .global main
    .global _sys_exit

    .code 32
    .section ".startup","ax"

    .global _start
    .func _start
    .fnstart
_start:
    @ save r0 for cores 1-3, r0 arg field passed by ROM
    @ r0 is a function pointer for secondary cpus
    mov r4, r0

    @ clear some registers
    mov r11,#0
    mov r12,#0
    mov lr,#0

    ldr r0, =top_of_stacks @ symbol defined in linker file
    mov r1, #2048

    @ get cpu id, and subtract the offset from the stacks base address
    mrc p15,0,r2,c0,c0,5 @ read multiprocessor affinity register
    and r2, r2, #3 @ mask off, leaving CPU ID field
    mov r5, r2 @ save cpu id for later

    mul r3, r2, r1
    sub r0, r0, r3

    mov r1, r1, lsl #2

    @ set stacks for all other modes
    msr CPSR_c, #0x11 | 0x80 | 0x40
    mov sp, r0
    sub r0, r0, r1

    msr CPSR_c, #0x12 | 0x80 | 0x40
    mov sp, r0
    sub r0, r0, r1

    msr CPSR_c, #0x17 | 0x80 | 0x40
    mov sp, r0
    sub r0, r0, r1

    msr CPSR_c, #0x1B | 0x80 | 0x40
    mov sp, r0
    sub r0, r0, r1

    msr CPSR_c, #0x1F | 0x80 | 0x40
    mov sp, r0
    sub r0, r0, r1

    @ Set SVC mode stack with interrupts disabled
    msr CPSR_c, #0x13 | 0x80 | 0x40
    mov sp, r0
    sub r0, r0, r1

    @ check cpu id - cpu0 is primary cpu
    cmp r5, #0
    beq primary_cpu_init
    bx r4 @ for secondary cpus, jump to argument function pointer passed in by ROM

    @ control should not return from the secondary cpu entry point
    b startup_exit

primary_cpu_init:




    ldr r1,=__ram_vectors_start
    ldr r2,=__ram_vectors_end
    ldr r3,=vectors
1: cmp r1,r2
    ldmlt r3!,{r4,r5,r6}
    stmlt r1!,{r4,r5,r6}
    blt 1b





    ldr r1,=__stacks_start @ stack region start address
    ldr r2,=top_of_stacks @ stack region end address
    bic r2,r2,#0x7 @ round length down to nearest 8 byte alignment
    ldr r3,=.Ldeadfeed @ get fill pattern address
    ldr r3,[r3] @ read fill pattern into r3
    mov r4,r3 @ copy fill pattern to r4
1: cmp r1,r2 @ the fill loop
    stmltia r1!,{r3-r4}
    blt 1b



    ldr r1,=__bss_start__
    ldr r2,=__bss_end__
    mov r3,#0
1: cmp r1,r2
    stmltia r1!,{r3}
    blt 1b

    @ take care of C++ static initialization. this won't cause any harm for plain C apps.
    ldr r12,=__libc_init_array
    blx r12

    @ branch to c library entry point
    mov r0,#0 @ argc
    mov r1,#0 @ argv
    mov r2,#0 @ env

    ldr r12, =main
    blx r12

    @ if either main() or the secondary cpu entry point return, which they should not,
    @ then call _sys_exit().
startup_exit:
    mov r0,#0
    ldr r12,=_sys_exit
    bx r12

    .cantunwind
    .fnend
    .endfunc @ _start()


.Ldeadfeed:
    .word 0xdeadfeed


    .end
