OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
INPUT (crtbegin.o crti.o crtend.o crtn.o)
MEMORY
{
    OCRAM (rwx) : ORIGIN = 0x00900000, LENGTH = 128K
    DDR (rwx) : ORIGIN = 0x10000000, LENGTH = 1024M
}
SECTIONS
{
    .l1_page_table (NOLOAD) :
    {
        __l1_page_table_start = .;
        . += 16K;
    } > OCRAM
    .heap.ocram (NOLOAD) : ALIGN(4)
    {
        __heap_ocram_start = .;
        . += LENGTH(OCRAM) - 16K - 72 ;
        __heap_ocram_end = .;
    } > OCRAM
    .ram_vectors (ORIGIN(OCRAM) + LENGTH(OCRAM) - 72) (NOLOAD) :
    {
        __ram_vectors_start = .;
        . += 72;
        __ram_vectors_end = .;
    } > OCRAM
    _start_image_add = ORIGIN(DDR);
    .ivt (ORIGIN(DDR)) :
    {
        . = . + 0x400;
        *(.ivt)
    } > DDR
    .boot_data :
    {
        __start_boot_data = .;
        *(.boot_data)
    } > DDR
    .dcd_hdr : ALIGN(16)
    {
        __start_dcd = .;
        *(.dcd_hdr)
    } > DDR
    .dcd_wrt_cmd :
    {
        *(.dcd_wrt_cmd)
    } > DDR
    .dcd_data :
    {
        *(.dcd_data)
    } > DDR
    .text : ALIGN(8)
    {
        CREATE_OBJECT_SYMBOLS
        *(.startup)
        *(.text .text.* .gnu.linkonce.t.*)
        *(.glue_7t) *(.glue_7) *(.vfp11_veneer)
        *(.ARM.extab* .gnu.linkonce.armextab.*)
        *(.gcc_except_table)
    } > DDR
    .ctors :
    {
        KEEP (*crtbegin.o(.ctors))
        KEEP (*crtbegin?.o(.ctors))
        KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
        KEEP (*(SORT(.ctors.*)))
        KEEP (*(.ctors))
    } > DDR
    .dtors :
    {
        KEEP (*crtbegin.o(.dtors))
        KEEP (*crtbegin?.o(.dtors))
        KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
        KEEP (*(SORT(.dtors.*)))
        KEEP (*(.dtors))
    } > DDR
    .rodata :
    {
        *(.rodata .rodata.* .gnu.linkonce.r.*)
        . = ALIGN(4);
        KEEP(*(.init))
        . = ALIGN(4);
        __init_array_start = .;
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array))
        __init_array_end = .;
        . = ALIGN(4);
        KEEP(*(.fini))
        . = ALIGN(4);
        __fini_array_start = .;
        KEEP (*(.fini_array))
        KEEP (*(SORT(.fini_array.*)))
        __fini_array_end = .;
    } > DDR
    PROVIDE_HIDDEN(__exidx_start = .);
    .ARM.exidx :
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > DDR
    PROVIDE_HIDDEN(__exidx_end = .);
    .data : ALIGN(8)
    {
        *(.data .data.* .gnu.linkonce.d.*)
        SORT(CONSTRUCTORS)
    } > DDR
    .hab.data (_start_image_add + 4M) : ALIGN(4)
    {
        __hab_data = .;
        . += 8K;
        . = ALIGN (32);
        __hab_data_end = .;
    } > DDR
    _image_size = . - _start_image_add;
    .bss :
    {
        __bss_start__ = .;
        *(.shbss)
        *(.bss .bss.* .gnu.linkonce.b.*)
        *(COMMON)
        *(.bss)
        __bss_end__ = .;
    } > DDR
    .stacks (NOLOAD) :
    {
        __stacks_start = .;
        . += 48K;
        __stacks_end = .;
        top_of_stacks = .;
    } > DDR
    free_memory_start = ALIGN(32);
    . += 128M;
    free_memory_end = .;
    _end = .;
}
