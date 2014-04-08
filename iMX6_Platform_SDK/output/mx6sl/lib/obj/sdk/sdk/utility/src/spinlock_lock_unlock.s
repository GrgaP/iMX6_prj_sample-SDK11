# 1 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/utility/src/spinlock_lock_unlock.S"
# 1 "<command-line>"
# 1 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/utility/src/spinlock_lock_unlock.S"
# 34 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/utility/src/spinlock_lock_unlock.S"
    .code 32
    .section ".text","ax"

    .global cpu_get_current




    .global spinlock_lock
    .func spinlock_lock
spinlock_lock:

    ldrex r1, [r0]
    cmp r1, #0xFF

    wfene
    bne spinlock_lock

    mrc p15, 0, r1, c0, c0, 5
    and r1, r1, #3
    strex r2, r1, [r0]
    cmp r2, #0
    bne spinlock_lock

    dmb

    bx lr

    .endfunc


    .global spinlock_unlock
    .func spinlock_unlock
spinlock_unlock:

    mrc p15, 0, r1, c0, c0, 5
    and r1, r1, #3

    ldr r2, [r0]
    cmp r1, r2
    movne r0, #1
    bxne lr

    dmb

    mov r1, #0xFF
    str r1, [r0]

    dsb


    sev

    mov r0, #0
    bx lr

    .endfunc


    .end
