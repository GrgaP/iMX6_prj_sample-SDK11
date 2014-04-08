# 1 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/drivers/audio/test/wav_file.S"
# 1 "<command-line>"
# 1 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/drivers/audio/test/wav_file.S"
# 30 "/home/leon/git/swp-report/iMX6_Platform_SDK/sdk/drivers/audio/test/wav_file.S"
 .section .wavedata, #alloc
     .globl wavefile_start
wavefile_start:

 .incbin "music.wav"

 .globl wavefile_end
wavefile_end:
