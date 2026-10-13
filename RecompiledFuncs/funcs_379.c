#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _chweather_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800859D8: syscall     185
    recomp_syscall_handler(rdram, ctx, 0x800859D8);
    return;
    // 0x800859DC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void gcmapsects_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080000C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800010: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800014: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800018: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080001C: jal         0x800BF704
    // 0x80800020: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x80800020: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800024: lbu         $v1, 0x77($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X77);
    // 0x80800028: lw          $t6, 0x68($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X68);
    // 0x8080002C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800030: sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3 << 2);
    // 0x80800034: subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // 0x80800038: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x8080003C: subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // 0x80800040: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x80800044: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800048: jal         0x800EE7F8
    // 0x8080004C: addu        $a0, $t6, $s1
    ctx->r4 = ADD32(ctx->r14, ctx->r17);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080004C: addu        $a0, $t6, $s1
    ctx->r4 = ADD32(ctx->r14, ctx->r17);
    after_1:
    // 0x80800050: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x80800054: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800058: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x8080005C: jal         0x800EE7F8
    // 0x80800060: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800060: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_2:
    // 0x80800064: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    // 0x80800068: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080006C: addu        $a0, $t8, $s1
    ctx->r4 = ADD32(ctx->r24, ctx->r17);
    // 0x80800070: jal         0x800EE7F8
    // 0x80800074: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800074: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_3:
    // 0x80800078: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x8080007C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2610, 0X29B0) << 16);
    // 0x80800080: addiu       $a1, $a1, 0x29B0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2610, 0X29B0));
    // 0x80800084: addu        $a0, $t9, $s1
    ctx->r4 = ADD32(ctx->r25, ctx->r17);
    // 0x80800088: jal         0x800EF3DC
    // 0x8080008C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EF3DC(rdram, ctx);
        goto after_4;
    // 0x8080008C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_4:
    // 0x80800090: lw          $t0, 0x68($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X68);
    // 0x80800094: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2610, 0X29B0) << 16);
    // 0x80800098: addiu       $a1, $a1, 0x29B0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2610, 0X29B0));
    // 0x8080009C: addu        $a0, $t0, $s1
    ctx->r4 = ADD32(ctx->r8, ctx->r17);
    // 0x808000A0: jal         0x800EF04C
    // 0x808000A4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808000A4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_5:
    // 0x808000A8: lw          $t1, 0x68($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X68);
    // 0x808000AC: addu        $v0, $t1, $s1
    ctx->r2 = ADD32(ctx->r9, ctx->r17);
    // 0x808000B0: addiu       $a0, $v0, 0x24
    ctx->r4 = ADD32(ctx->r2, 0X24);
    // 0x808000B4: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    // 0x808000B8: jal         0x800EE780
    // 0x808000BC: addiu       $a2, $v0, 0x18
    ctx->r6 = ADD32(ctx->r2, 0X18);
    func_800EE780(rdram, ctx);
        goto after_6;
    // 0x808000BC: addiu       $a2, $v0, 0x18
    ctx->r6 = ADD32(ctx->r2, 0X18);
    after_6:
    // 0x808000C0: lw          $t2, 0x68($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X68);
    // 0x808000C4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x808000C8: addu        $a0, $t2, $s1
    ctx->r4 = ADD32(ctx->r10, ctx->r17);
    // 0x808000CC: jal         0x800EF334
    // 0x808000D0: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EF334(rdram, ctx);
        goto after_7;
    // 0x808000D0: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_7:
    // 0x808000D4: lw          $t3, 0x68($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X68);
    // 0x808000D8: addu        $v0, $t3, $s1
    ctx->r2 = ADD32(ctx->r11, ctx->r17);
    // 0x808000DC: addiu       $a0, $v0, 0x24
    ctx->r4 = ADD32(ctx->r2, 0X24);
    // 0x808000E0: jal         0x800EEAD4
    // 0x808000E4: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    func_800EEAD4(rdram, ctx);
        goto after_8;
    // 0x808000E4: addiu       $a1, $v0, 0xC
    ctx->r5 = ADD32(ctx->r2, 0XC);
    after_8:
    // 0x808000E8: lw          $t4, 0x68($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X68);
    // 0x808000EC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x808000F0: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x808000F4: swc1        $f0, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f0.u32l;
    // 0x808000F8: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x808000FC: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x80800100: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80800104: sh          $t6, 0x40($t8)
    MEM_H(0X40, ctx->r24) = ctx->r14;
    // 0x80800108: lw          $t0, 0x68($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X68);
    // 0x8080010C: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x80800110: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80800114: sh          $t9, 0x42($t1)
    MEM_H(0X42, ctx->r9) = ctx->r25;
    // 0x80800118: lw          $t2, 0x68($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X68);
    // 0x8080011C: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80800120: sb          $v1, 0x38($t3)
    MEM_B(0X38, ctx->r11) = ctx->r3;
    // 0x80800124: lw          $t4, 0x68($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X68);
    // 0x80800128: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8080012C: sb          $v1, 0x39($t5)
    MEM_B(0X39, ctx->r13) = ctx->r3;
    // 0x80800130: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x80800134: addu        $t6, $t7, $s1
    ctx->r14 = ADD32(ctx->r15, ctx->r17);
    // 0x80800138: sb          $v1, 0x3A($t6)
    MEM_B(0X3A, ctx->r14) = ctx->r3;
    // 0x8080013C: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    // 0x80800140: addu        $t0, $t8, $s1
    ctx->r8 = ADD32(ctx->r24, ctx->r17);
    // 0x80800144: sb          $v1, 0x3B($t0)
    MEM_B(0X3B, ctx->r8) = ctx->r3;
    // 0x80800148: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x8080014C: addu        $t1, $t9, $s1
    ctx->r9 = ADD32(ctx->r25, ctx->r17);
    // 0x80800150: sb          $v1, 0x3C($t1)
    MEM_B(0X3C, ctx->r9) = ctx->r3;
    // 0x80800154: lw          $t2, 0x68($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X68);
    // 0x80800158: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x8080015C: sb          $v1, 0x3D($t3)
    MEM_B(0X3D, ctx->r11) = ctx->r3;
    // 0x80800160: lw          $t4, 0x68($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X68);
    // 0x80800164: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80800168: sb          $v1, 0x3E($t5)
    MEM_B(0X3E, ctx->r13) = ctx->r3;
    // 0x8080016C: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x80800170: addu        $t6, $t7, $s1
    ctx->r14 = ADD32(ctx->r15, ctx->r17);
    // 0x80800174: sb          $v1, 0x3F($t6)
    MEM_B(0X3F, ctx->r14) = ctx->r3;
    // 0x80800178: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    // 0x8080017C: addu        $v0, $t8, $s1
    ctx->r2 = ADD32(ctx->r24, ctx->r17);
    // 0x80800180: lbu         $t0, 0x4C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X4C);
    // 0x80800184: andi        $t9, $t0, 0xFF7F
    ctx->r25 = ctx->r8 & 0XFF7F;
    // 0x80800188: sb          $t9, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r25;
    // 0x8080018C: lw          $t1, 0x68($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X68);
    // 0x80800190: addu        $v0, $t1, $s1
    ctx->r2 = ADD32(ctx->r9, ctx->r17);
    // 0x80800194: lbu         $t2, 0x4C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4C);
    // 0x80800198: andi        $t3, $t2, 0xFFBF
    ctx->r11 = ctx->r10 & 0XFFBF;
    // 0x8080019C: sb          $t3, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r11;
    // 0x808001A0: lw          $t4, 0x68($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X68);
    // 0x808001A4: addu        $v0, $t4, $s1
    ctx->r2 = ADD32(ctx->r12, ctx->r17);
    // 0x808001A8: lbu         $t5, 0x4C($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X4C);
    // 0x808001AC: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x808001B0: sb          $t7, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r15;
    // 0x808001B4: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
    // 0x808001B8: addu        $v0, $t6, $s1
    ctx->r2 = ADD32(ctx->r14, ctx->r17);
    // 0x808001BC: lbu         $t8, 0x4C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4C);
    // 0x808001C0: andi        $t0, $t8, 0xFFEF
    ctx->r8 = ctx->r24 & 0XFFEF;
    // 0x808001C4: sb          $t0, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r8;
    // 0x808001C8: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x808001CC: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x808001D0: lbu         $t2, 0x4C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X4C);
    // 0x808001D4: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x808001D8: sb          $t3, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r11;
    // 0x808001DC: lw          $t4, 0x68($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X68);
    // 0x808001E0: addu        $v0, $t4, $s1
    ctx->r2 = ADD32(ctx->r12, ctx->r17);
    // 0x808001E4: lbu         $t7, 0x4C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4C);
    // 0x808001E8: ori         $t6, $t7, 0x1
    ctx->r14 = ctx->r15 | 0X1;
    // 0x808001EC: sb          $t6, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r14;
    // 0x808001F0: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    // 0x808001F4: addu        $t0, $t8, $s1
    ctx->r8 = ADD32(ctx->r24, ctx->r17);
    // 0x808001F8: sw          $zero, 0x44($t0)
    MEM_W(0X44, ctx->r8) = 0;
    // 0x808001FC: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x80800200: addu        $t1, $t9, $s1
    ctx->r9 = ADD32(ctx->r25, ctx->r17);
    // 0x80800204: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
    // 0x80800208: lw          $t2, 0x68($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X68);
    // 0x8080020C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800210: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80800214: swc1        $f4, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->f4.u32l;
    // 0x80800218: lw          $t4, 0x68($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X68);
    // 0x8080021C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80800220: sw          $zero, 0x50($t5)
    MEM_W(0X50, ctx->r13) = 0;
    // 0x80800224: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x80800228: addu        $t6, $t7, $s1
    ctx->r14 = ADD32(ctx->r15, ctx->r17);
    // 0x8080022C: sw          $zero, 0x54($t6)
    MEM_W(0X54, ctx->r14) = 0;
    // 0x80800230: lbu         $t8, 0x77($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X77);
    // 0x80800234: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80800238: sb          $t0, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r8;
    // 0x8080023C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800240: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800244: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800248: jr          $ra
    // 0x8080024C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080024C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_801158EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801158EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801158F0: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x801158F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801158F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801158FC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80115900: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80115904: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80115908: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8011590C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80115910: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80115914: nop

    // 0x80115918: bc1f        L_8011592C
    if (!c1cs) {
        // 0x8011591C: nop
    
            goto L_8011592C;
    }
    // 0x8011591C: nop

    // 0x80115920: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80115924: b           L_80115A88
    // 0x80115928: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
        goto L_80115A88;
    // 0x80115928: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
L_8011592C:
    // 0x8011592C: jal         0x800D8FF8
    // 0x80115930: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80115930: nop

    after_0:
    // 0x80115934: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80115938: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8011593C: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80115940: jal         0x800F1DCC
    // 0x80115944: lwc1        $f14, 0x0($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X0);
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x80115944: lwc1        $f14, 0x0($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x80115948: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8011594C: jal         0x800F2100
    // 0x80115950: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_2;
    // 0x80115950: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x80115954: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80115958: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8011595C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80115960: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80115964: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80115968: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8011596C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80115970: bc1f        L_80115994
    if (!c1cs) {
        // 0x80115974: lwc1        $f6, 0x38($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
            goto L_80115994;
    }
    // 0x80115974: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80115978: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8011597C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80115980: jal         0x800F1344
    // 0x80115984: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F1344(rdram, ctx);
        goto after_3;
    // 0x80115984: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80115988: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8011598C: b           L_80115A10
    // 0x80115990: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
        goto L_80115A10;
    // 0x80115990: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
L_80115994:
    // 0x80115994: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80115998: mul.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8011599C: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x801159A0: nop

    // 0x801159A4: bc1f        L_801159B0
    if (!c1cs) {
        // 0x801159A8: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_801159B0;
    }
    // 0x801159A8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x801159AC: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_801159B0:
    // 0x801159B0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801159B4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801159B8: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x801159BC: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801159C0: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801159C4: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x801159C8: nop

    // 0x801159CC: bc1fl       L_801159FC
    if (!c1cs) {
        // 0x801159D0: c.lt.s      $f18, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
            goto L_801159FC;
    }
    goto skip_0;
    // 0x801159D0: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    skip_0:
    // 0x801159D4: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801159D8: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
    // 0x801159DC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801159E0: nop

    // 0x801159E4: bc1fl       L_80115A14
    if (!c1cs) {
        // 0x801159E8: lwc1        $f4, 0x30($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
            goto L_80115A14;
    }
    goto skip_1;
    // 0x801159E8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x801159EC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x801159F0: b           L_80115A10
    // 0x801159F4: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
        goto L_80115A10;
    // 0x801159F4: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801159F8: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
L_801159FC:
    // 0x801159FC: nop

    // 0x80115A00: bc1fl       L_80115A14
    if (!c1cs) {
        // 0x80115A04: lwc1        $f4, 0x30($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
            goto L_80115A14;
    }
    goto skip_2;
    // 0x80115A04: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    skip_2:
    // 0x80115A08: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x80115A0C: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
L_80115A10:
    // 0x80115A10: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
L_80115A14:
    // 0x80115A14: mul.s       $f12, $f2, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80115A18: jal         0x800F2100
    // 0x80115A1C: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x80115A1C: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x80115A20: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80115A24: jal         0x800F2100
    // 0x80115A28: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x80115A28: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x80115A2C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80115A30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80115A34: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80115A38: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80115A3C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80115A40: bc1fl       L_80115A74
    if (!c1cs) {
        // 0x80115A44: lw          $t9, 0x44($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X44);
            goto L_80115A74;
    }
    goto skip_3;
    // 0x80115A44: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    skip_3:
    // 0x80115A48: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80115A4C: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80115A50: nop

    // 0x80115A54: bc1fl       L_80115A74
    if (!c1cs) {
        // 0x80115A58: lw          $t9, 0x44($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X44);
            goto L_80115A74;
    }
    goto skip_4;
    // 0x80115A58: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    skip_4:
    // 0x80115A5C: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x80115A60: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80115A64: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80115A68: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x80115A6C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x80115A70: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
L_80115A74:
    // 0x80115A74: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80115A78: jal         0x800136E4
    // 0x80115A7C: add.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f14.fl;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x80115A7C: add.s       $f12, $f6, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f14.fl;
    after_6:
    // 0x80115A80: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80115A84: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
L_80115A88:
    // 0x80115A88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80115A8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80115A90: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80115A94: jr          $ra
    // 0x80115A98: nop

    return;
    // 0x80115A98: nop

;}
RECOMP_FUNC void func_8080444C_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080444C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80804454: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80804458: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    // 0x8080445C: jal         0x808015DC
    // 0x80804460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808015DC_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80804464: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80804468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080446C: jal         0x808016A0
    // 0x80804470: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    func_808016A0_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80804470: lw          $a0, 0x28($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X28);
    after_1:
    // 0x80804474: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80804478: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080447C: jal         0x808016E8
    // 0x80804480: lw          $a0, 0x28($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X28);
    func_808016E8_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80804480: lw          $a0, 0x28($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X28);
    after_2:
    // 0x80804484: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80804488: jal         0x80803D00
    // 0x8080448C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80803D00_chgameselect(rdram, ctx);
        goto after_3;
    // 0x8080448C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80804490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80804494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80804498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080449C: jr          $ra
    // 0x808044A0: nop

    return;
    // 0x808044A0: nop

;}
RECOMP_FUNC void func_800E9EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9EB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9EBC: jal         0x800E9E88
    // 0x800E9EC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800E9E88(rdram, ctx);
        goto after_0;
    // 0x800E9EC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E9EC4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800E9EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9ECC: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x800E9ED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9ED4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800E9ED8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800E9EDC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E9EE0: jr          $ra
    // 0x800E9EE4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    return;
    // 0x800E9EE4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
;}
RECOMP_FUNC void func_80800888_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800888: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080088C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800890: jal         0x800A587C
    // 0x80800894: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x80800894: nop

    after_0:
    // 0x80800898: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080089C: beq         $v0, $at, L_808008B4
    if (ctx->r2 == ctx->r1) {
        // 0x808008A0: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_808008B4;
    }
    // 0x808008A0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808008A4: beq         $v0, $at, L_808008C4
    if (ctx->r2 == ctx->r1) {
        // 0x808008A8: nop
    
            goto L_808008C4;
    }
    // 0x808008A8: nop

    // 0x808008AC: b           L_808008D4
    // 0x808008B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808008D4;
    // 0x808008B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008B4:
    // 0x808008B4: jal         0x800A586C
    // 0x808008B8: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x808008B8: nop

    after_1:
    // 0x808008BC: b           L_808008D4
    // 0x808008C0: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
        goto L_808008D4;
    // 0x808008C0: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
L_808008C4:
    // 0x808008C4: jal         0x800A586C
    // 0x808008C8: nop

    func_800A586C(rdram, ctx);
        goto after_2;
    // 0x808008C8: nop

    after_2:
    // 0x808008CC: b           L_808008D4
    // 0x808008D0: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
        goto L_808008D4;
    // 0x808008D0: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
L_808008D4:
    // 0x808008D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008DC: jr          $ra
    // 0x808008E0: nop

    return;
    // 0x808008E0: nop

;}
RECOMP_FUNC void func_808003EC_chintrotext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808003F0: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x808003F4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x808003F8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808003FC: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80800400: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800404: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80800408: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8080040C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800410: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800414: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800418: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8080041C: jal         0x80100094
    // 0x80800420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800424: lhu         $t6, 0x72($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X72);
    // 0x80800428: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8080042C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800430: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80800434: bnel        $at, $zero, L_808004F4
    if (ctx->r1 != 0) {
        // 0x80800438: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808004F4;
    }
    goto skip_0;
    // 0x80800438: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8080043C: jal         0x800A819C
    // 0x80800440: nop

    func_800A819C(rdram, ctx);
        goto after_1;
    // 0x80800440: nop

    after_1:
    // 0x80800444: beql        $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x80800448: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_808004F4;
    }
    goto skip_1;
    // 0x80800448: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x8080044C: jal         0x80088B20
    // 0x80800450: nop

    _fxkern_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800450: nop

    after_2:
    // 0x80800454: jal         0x80089C90
    // 0x80800458: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800458: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x8080045C: jal         0x800B8C8C
    // 0x80800460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B8C8C(rdram, ctx);
        goto after_4;
    // 0x80800460: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800464: lh          $t8, 0x0($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X0);
    // 0x80800468: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080046C: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x80800470: blez        $t8, L_808004F0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80800474: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808004F0;
    }
    // 0x80800474: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800478: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080047C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800480: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800484: addiu       $s2, $zero, 0xC25
    ctx->r18 = ADD32(0, 0XC25);
L_80800488:
    // 0x80800488: jal         0x800B8CE0
    // 0x8080048C: lh          $a0, 0x2A($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2A);
    func_800B8CE0(rdram, ctx);
        goto after_5;
    // 0x8080048C: lh          $a0, 0x2A($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2A);
    after_5:
    // 0x80800490: lh          $t9, 0x2A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2A);
    // 0x80800494: bnel        $s2, $t9, L_808004A8
    if (ctx->r18 != ctx->r25) {
        // 0x80800498: mov.s       $f12, $f22
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
            goto L_808004A8;
    }
    goto skip_2;
    // 0x80800498: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    skip_2:
    // 0x8080049C: b           L_808004A8
    // 0x808004A0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
        goto L_808004A8;
    // 0x808004A0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x808004A4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
L_808004A8:
    // 0x808004A8: jal         0x80088B28
    // 0x808004AC: nop

    _fxkern_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808004AC: nop

    after_6:
    // 0x808004B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808004B4: jal         0x80100094
    // 0x808004B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x808004B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808004BC: lh          $t0, 0x16($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X16);
    // 0x808004C0: jal         0x800E71B8
    // 0x808004C4: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    func_800E71B8(rdram, ctx);
        goto after_8;
    // 0x808004C4: addu        $a0, $t0, $v0
    ctx->r4 = ADD32(ctx->r8, ctx->r2);
    after_8:
    // 0x808004C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808004CC: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x808004D0: jal         0x80088B18
    // 0x808004D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _fxkern_entrypoint_1(rdram, ctx);
        goto after_9;
    // 0x808004D4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_9:
    // 0x808004D8: lh          $t1, 0x0($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X0);
    // 0x808004DC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808004E0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x808004E4: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808004E8: bne         $at, $zero, L_80800488
    if (ctx->r1 != 0) {
        // 0x808004EC: nop
    
            goto L_80800488;
    }
    // 0x808004EC: nop

L_808004F0:
    // 0x808004F0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_808004F4:
    // 0x808004F4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808004F8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x808004FC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800500: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800504: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800508: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8080050C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80800510: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80800514: jr          $ra
    // 0x80800518: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800518: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _gczoombox_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AE8: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087AE8);
    return;
    // 0x80087AEC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _gczoombox_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BF0: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087BF0);
    return;
    // 0x80087BF4: addi        $t0, $zero, 0x88
    ctx->r8 = ADD32(0, 0X88);
;}
RECOMP_FUNC void fxsplash_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x800889A0
    // 0x80800010: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _fxripple_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080001C: jr          $ra
    // 0x80800020: nop

    return;
    // 0x80800020: nop

;}
RECOMP_FUNC void bapackctrl_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: lw          $v0, 0xD8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XD8);
    // 0x808000CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808000D0: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808000D4: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x808000D8: lw          $t6, 0xD8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD8);
    // 0x808000DC: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
    // 0x808000E0: lw          $t7, 0xD8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XD8);
    // 0x808000E4: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x808000E8: lw          $a0, 0xD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD8);
    // 0x808000EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x808000F0: jal         0x800EFD24
    // 0x808000F4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x808000F4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x808000F8: jal         0x80800008
    // 0x808000FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800008_bapackctrl(rdram, ctx);
        goto after_1;
    // 0x808000FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800108: lw          $t8, 0xD8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XD8);
    // 0x8080010C: jal         0x80800150
    // 0x80800110: sb          $zero, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = 0;
    bapackctrl_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800110: sb          $zero, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = 0;
    after_2:
    // 0x80800114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void func_80800000_chjigsawbitcont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80101FDC
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800010: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800014: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800018: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080001C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800020: bnel        $t6, $at, L_80800078
    if (ctx->r14 != ctx->r1) {
        // 0x80800024: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800078;
    }
    goto skip_0;
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800028: lhu         $t8, 0x76($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X76);
    // 0x8080002C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1644, 0X9B4) << 16);
    // 0x80800030: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80800034: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x80800038: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8080003C: jal         0x800DA298
    // 0x80800040: lh          $a0, 0x9B4($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1644, 0X9B4));
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800040: lh          $a0, 0x9B4($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1644, 0X9B4));
    after_1:
    // 0x80800044: bne         $v0, $zero, L_80800074
    if (ctx->r2 != 0) {
        // 0x80800048: lw          $t1, 0x18($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X18);
            goto L_80800074;
    }
    // 0x80800048: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: lhu         $t2, 0x76($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X76);
    // 0x80800050: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1644, 0X9B4) << 16);
    // 0x80800054: srl         $t3, $t2, 7
    ctx->r11 = S32(U32(ctx->r10) >> 7);
    // 0x80800058: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8080005C: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x80800060: jal         0x800DA544
    // 0x80800064: lh          $a0, 0x9B4($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1644, 0X9B4));
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x80800064: lh          $a0, 0x9B4($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1644, 0X9B4));
    after_2:
    // 0x80800068: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080006C: jal         0x80108B04
    // 0x80800070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_3;
    // 0x80800070: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_80800074:
    // 0x80800074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800078:
    // 0x80800078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080007C: jr          $ra
    // 0x80800080: nop

    return;
    // 0x80800080: nop

;}
RECOMP_FUNC void func_80800EA0_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800EA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EA8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800EAC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1632, 0X4704) << 16);
    // 0x80800EB0: addiu       $a2, $a2, 0x4704
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X4704));
    // 0x80800EB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800EB8: jal         0x80089D18
    // 0x80800EBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800EBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800EC0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1632, 0X4714) << 16);
    // 0x80800EC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800EC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800ECC: jal         0x80089D18
    // 0x80800ED0: addiu       $a2, $a2, 0x4714
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X4714));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800ED0: addiu       $a2, $a2, 0x4714
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1632, 0X4714));
    after_1:
    // 0x80800ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800ED8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800EDC: jr          $ra
    // 0x80800EE0: nop

    return;
    // 0x80800EE0: nop

;}
RECOMP_FUNC void func_80800A18_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800A20: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800A24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A28: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800A2C: jal         0x8001B798
    // 0x80800A30: lh          $a0, 0x2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x80800A30: lh          $a0, 0x2($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2);
    after_0:
    // 0x80800A34: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A38: jal         0x80089EA8
    // 0x80800A3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _susplinet_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80800A3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A48: jal         0x80089E58
    // 0x80800A4C: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    _susplinet_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800A4C: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    after_2:
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800A58: jal         0x80089E58
    // 0x80800A5C: addiu       $a2, $s1, 0x10
    ctx->r6 = ADD32(ctx->r17, 0X10);
    _susplinet_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800A5C: addiu       $a2, $s1, 0x10
    ctx->r6 = ADD32(ctx->r17, 0X10);
    after_3:
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A64: jal         0x80089E60
    // 0x80800A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _susplinet_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800A6C: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A74: jal         0x80089E60
    // 0x80800A78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _susplinet_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800A78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800A7C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    // 0x80800A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A84: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800A88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800A8C: jr          $ra
    // 0x80800A90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800A90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _sufreezy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B78: syscall     804
    recomp_syscall_handler(rdram, ctx, 0x80089B78);
    return;
    // 0x80089B7C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801D20_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801D24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801D2C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801D30: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801D34: jal         0x800B53A4
    // 0x80801D38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80801D38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80801D3C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80801D40: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1016, 0X1FB0) << 16);
    // 0x80801D44: addiu       $t6, $t6, 0x1FB0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1016, 0X1FB0));
    // 0x80801D48: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80801D4C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801D50: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801D54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801D58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801D5C: jal         0x800BABB8
    // 0x80801D60: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80801D60: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80801D64: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801D68: jal         0x800BA3FC
    // 0x80801D6C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800BA3FC(rdram, ctx);
        goto after_2;
    // 0x80801D6C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80801D70: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80801D74: jal         0x800BA22C
    // 0x80801D78: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x80801D78: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80801D7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801D84: jr          $ra
    // 0x80801D88: nop

    return;
    // 0x80801D88: nop

;}
RECOMP_FUNC void func_80807AF8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807AF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80807AFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80807B00: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80807B04: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80807B08: lw          $s1, 0x188($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X188);
    // 0x80807B0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80807B10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80807B14: jal         0x800D3948
    // 0x80807B18: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x80807B18: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x80807B1C: beql        $v0, $zero, L_80807B50
    if (ctx->r2 == 0) {
        // 0x80807B20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80807B50;
    }
    goto skip_0;
    // 0x80807B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80807B24: jal         0x800EA068
    // 0x80807B28: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    func_800EA068(rdram, ctx);
        goto after_1;
    // 0x80807B28: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_1:
    // 0x80807B2C: beq         $v0, $zero, L_80807B44
    if (ctx->r2 == 0) {
        // 0x80807B30: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80807B44;
    }
    // 0x80807B30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80807B34: jal         0x80088378
    // 0x80807B38: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    _gcstatusDll_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x80807B38: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_2:
    // 0x80807B3C: b           L_80807B4C
    // 0x80807B40: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_80807B4C;
    // 0x80807B40: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80807B44:
    // 0x80807B44: jal         0x80088328
    // 0x80807B48: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    _gcstatusDll_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80807B48: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_3:
L_80807B4C:
    // 0x80807B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80807B50:
    // 0x80807B50: jal         0x800A34A0
    // 0x80807B54: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800A34A0(rdram, ctx);
        goto after_4;
    // 0x80807B54: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80807B58: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80807B5C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80807B60: sw          $v0, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->r2;
    // 0x80807B64: sw          $v0, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->r2;
    // 0x80807B68: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x80807B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807B70: jal         0x8009B7C0
    // 0x80807B74: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    func_8009B7C0(rdram, ctx);
        goto after_5;
    // 0x80807B74: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    after_5:
    // 0x80807B78: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80807B7C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80807B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807B84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80807B88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80807B8C: jal         0x8009FFD8
    // 0x80807B90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8009FFD8(rdram, ctx);
        goto after_6;
    // 0x80807B90: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80807B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807B98: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80807B9C: jal         0x80098140
    // 0x80807BA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_7;
    // 0x80807BA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80807BA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80807BA8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80807BAC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80807BB0: jr          $ra
    // 0x80807BB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80807BB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800F08_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800F14: jal         0x808005F0
    // 0x80800F18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808005F0_bskaztorpedo(rdram, ctx);
        goto after_0;
    // 0x80800F18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F20: addiu       $a1, $zero, 0x135
    ctx->r5 = ADD32(0, 0X135);
    // 0x80800F24: jal         0x8008CB3C
    // 0x80800F28: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80800F28: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_1:
    // 0x80800F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800F38: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800F3C: jal         0x8009FFD8
    // 0x80800F40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800F40: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80800F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F48: jal         0x800961AC
    // 0x80800F4C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800961AC(rdram, ctx);
        goto after_3;
    // 0x80800F4C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x80800F50: jal         0x80084DB8
    // 0x80800F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800F58: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x80800F5C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800F60: jal         0x80084DF0
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800F68: jal         0x80800E98
    // 0x80800F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E98_bskaztorpedo(rdram, ctx);
        goto after_6;
    // 0x80800F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800F70: jal         0x80084E20
    // 0x80800F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x80800F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F80: jal         0x800A38F0
    // 0x80800F84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800A38F0(rdram, ctx);
        goto after_8;
    // 0x80800F84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80800F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F8C: jal         0x80084CE8
    // 0x80800F90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_14(rdram, ctx);
        goto after_9;
    // 0x80800F90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800F94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800F98: nop

    // 0x80800F9C: swc1        $f4, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f4.u32l;
    // 0x80800FA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800FA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800FA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800FAC: jr          $ra
    // 0x80800FB0: nop

    return;
    // 0x80800FB0: nop

;}
RECOMP_FUNC void func_808001E0_chscreenadjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808001E4: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x808001E8: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x808001EC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x808001F0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x808001F4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x808001F8: lw          $s0, 0x64($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X64);
    // 0x808001FC: lw          $s1, 0x68($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X68);
    // 0x80800200: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x80800204: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x80800208: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x8080020C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800210: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800214: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80800218: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8080021C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800220: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800224: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800228: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8080022C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80800230: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80800234: jal         0x800BC474
    // 0x80800238: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    func_800BC474(rdram, ctx);
        goto after_0;
    // 0x80800238: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    after_0:
    // 0x8080023C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800240: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800244: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80800248: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8080024C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80800250: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80800254: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80800258: jal         0x800BC474
    // 0x8080025C: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    func_800BC474(rdram, ctx);
        goto after_1;
    // 0x8080025C: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    after_1:
    // 0x80800260: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80800264: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800268: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8080026C: subu        $a1, $t6, $s0
    ctx->r5 = SUB32(ctx->r14, ctx->r16);
    // 0x80800270: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800274: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800278: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8080027C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80800280: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80800284: jal         0x800BC474
    // 0x80800288: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    func_800BC474(rdram, ctx);
        goto after_2;
    // 0x80800288: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    after_2:
    // 0x8080028C: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80800290: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800294: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80800298: subu        $a1, $t7, $s1
    ctx->r5 = SUB32(ctx->r15, ctx->r17);
    // 0x8080029C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x808002A0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x808002A4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x808002A8: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x808002AC: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x808002B0: jal         0x800BC474
    // 0x808002B4: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    func_800BC474(rdram, ctx);
        goto after_3;
    // 0x808002B4: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    after_3:
    // 0x808002B8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x808002BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002C0: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x808002C4: subu        $a2, $t8, $s1
    ctx->r6 = SUB32(ctx->r24, ctx->r17);
    // 0x808002C8: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x808002CC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x808002D0: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x808002D4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x808002D8: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x808002DC: jal         0x800BC474
    // 0x808002E0: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    func_800BC474(rdram, ctx);
        goto after_4;
    // 0x808002E0: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    after_4:
    // 0x808002E4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x808002E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002EC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x808002F0: subu        $a2, $t9, $s0
    ctx->r6 = SUB32(ctx->r25, ctx->r16);
    // 0x808002F4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808002F8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x808002FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80800300: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80800304: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80800308: jal         0x800BC474
    // 0x8080030C: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    func_800BC474(rdram, ctx);
        goto after_5;
    // 0x8080030C: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    after_5:
    // 0x80800310: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800314: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80800318: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8080031C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80800320: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80800324: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80800328: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8080032C: jal         0x800BC474
    // 0x80800330: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    func_800BC474(rdram, ctx);
        goto after_6;
    // 0x80800330: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    after_6:
    // 0x80800334: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800338: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8080033C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80800340: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80800344: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80800348: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8080034C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80800350: jal         0x800BC474
    // 0x80800354: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    func_800BC474(rdram, ctx);
        goto after_7;
    // 0x80800354: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    after_7:
    // 0x80800358: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8080035C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800360: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800364: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800368: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8080036C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80800370: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80800374: jr          $ra
    // 0x80800378: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800378: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80111E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111E88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80111E8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80111E90: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80111E94: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80111E98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80111E9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80111EA0: jal         0x800D8FF8
    // 0x80111EA4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80111EA4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80111EA8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80111EAC: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80111EB0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80111EB4: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80111EB8: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    // 0x80111EBC: nop

    // 0x80111EC0: bc1fl       L_80111ED8
    if (!c1cs) {
        // 0x80111EC4: sub.s       $f6, $f14, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f2.fl;
            goto L_80111ED8;
    }
    goto skip_0;
    // 0x80111EC4: sub.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f2.fl;
    skip_0:
    // 0x80111EC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80111ECC: b           L_80111F5C
    // 0x80111ED0: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
        goto L_80111F5C;
    // 0x80111ED0: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x80111ED4: sub.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f2.fl;
L_80111ED8:
    // 0x80111ED8: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80111EDC: lwc1        $f12, 0x0($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80111EE0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80111EE4: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80111EE8: sub.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80111EEC: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80111EF0: nop

    // 0x80111EF4: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80111EF8: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80111EFC: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80111F00: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80111F04: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80111F08: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80111F0C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80111F10: nop

    // 0x80111F14: bc1f        L_80111F3C
    if (!c1cs) {
        // 0x80111F18: add.s       $f20, $f4, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f2.fl;
            goto L_80111F3C;
    }
    // 0x80111F18: add.s       $f20, $f4, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80111F1C: c.lt.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl < ctx->f14.fl;
    // 0x80111F20: nop

    // 0x80111F24: bc1fl       L_80111F5C
    if (!c1cs) {
        // 0x80111F28: swc1        $f20, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f20.u32l;
            goto L_80111F5C;
    }
    goto skip_1;
    // 0x80111F28: swc1        $f20, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f20.u32l;
    skip_1:
    // 0x80111F2C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80111F30: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
    // 0x80111F34: b           L_80111F58
    // 0x80111F38: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
        goto L_80111F58;
    // 0x80111F38: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_80111F3C:
    // 0x80111F3C: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x80111F40: nop

    // 0x80111F44: bc1fl       L_80111F5C
    if (!c1cs) {
        // 0x80111F48: swc1        $f20, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f20.u32l;
            goto L_80111F5C;
    }
    goto skip_2;
    // 0x80111F48: swc1        $f20, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f20.u32l;
    skip_2:
    // 0x80111F4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80111F50: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
    // 0x80111F54: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
L_80111F58:
    // 0x80111F58: swc1        $f20, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f20.u32l;
L_80111F5C:
    // 0x80111F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80111F60: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80111F64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80111F68: jr          $ra
    // 0x80111F6C: nop

    return;
    // 0x80111F6C: nop

;}
RECOMP_FUNC void func_800A88C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A88C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A88C8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800A88CC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A88D0: addiu       $t7, $t7, 0x7688
    ctx->r15 = ADD32(ctx->r15, 0X7688);
    // 0x800A88D4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A88D8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800A88DC: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800A88E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A88E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A88E8: bne         $a2, $zero, L_800A88F8
    if (ctx->r6 != 0) {
        // 0x800A88EC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800A88F8;
    }
    // 0x800A88EC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800A88F0: b           L_800A8938
    // 0x800A88F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A8938;
    // 0x800A88F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A88F8:
    // 0x800A88F8: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800A88FC: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x800A8900: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800A8904: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800A8908: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800A890C: jal         0x80015CE8
    // 0x800A8910: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    func_80015CE8(rdram, ctx);
        goto after_0;
    // 0x800A8910: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x800A8914: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A8918: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800A891C: lw          $t9, 0x7674($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7674);
    // 0x800A8920: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800A8924: bnel        $a3, $t9, L_800A8938
    if (ctx->r7 != ctx->r25) {
        // 0x800A8928: lw          $v0, 0x1C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X1C);
            goto L_800A8938;
    }
    goto skip_0;
    // 0x800A8928: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800A892C: jal         0x800E42B4
    // 0x800A8930: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    func_800E42B4(rdram, ctx);
        goto after_1;
    // 0x800A8930: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x800A8934: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800A8938:
    // 0x800A8938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A893C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A8940: jr          $ra
    // 0x800A8944: nop

    return;
    // 0x800A8944: nop

;}
RECOMP_FUNC void func_80800018_chfactoryflypad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080001C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800024: jal         0x80085808
    // 0x80800028: addiu       $a1, $zero, 0x16B
    ctx->r5 = ADD32(0, 0X16B);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a1, $zero, 0x16B
    ctx->r5 = ADD32(0, 0X16B);
    after_0:
    // 0x8080002C: jal         0x80085818
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void func_80800188_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080018C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800190: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800194: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800198: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080019C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808001A0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x808001A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808001A8: jal         0x800DC128
    // 0x808001AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DC128(rdram, ctx);
        goto after_0;
    // 0x808001AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808001B0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808001B4: jal         0x800B53A4
    // 0x808001B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B53A4(rdram, ctx);
        goto after_1;
    // 0x808001B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808001BC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1776, 0X1814) << 16);
    // 0x808001C0: addiu       $t6, $t6, 0x1814
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1776, 0X1814));
    // 0x808001C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808001C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808001D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808001D8: jal         0x800BABB8
    // 0x808001DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808001DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x808001E0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x808001E4: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001EC: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x808001F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808001F4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808001F8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x808001FC: nop

    // 0x80800200: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80800204: jal         0x800BA568
    // 0x80800208: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    func_800BA568(rdram, ctx);
        goto after_3;
    // 0x80800208: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    after_3:
    // 0x8080020C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1620) << 16);
    // 0x80800210: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800214: lwc1        $f16, 0x1620($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1620));
    // 0x80800218: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1624) << 16);
    // 0x8080021C: lwc1        $f4, 0x1624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1624));
    // 0x80800220: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8080022C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800230: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800234: jal         0x800BA7C4
    // 0x80800238: nop

    func_800BA7C4(rdram, ctx);
        goto after_4;
    // 0x80800238: nop

    after_4:
    // 0x8080023C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1628) << 16);
    // 0x80800240: lwc1        $f8, 0x1628($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1628));
    // 0x80800244: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800248: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X162C) << 16);
    // 0x8080024C: lwc1        $f18, 0x162C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X162C));
    // 0x80800250: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800258: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8080025C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800260: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800264: jal         0x800BA7FC
    // 0x80800268: nop

    func_800BA7FC(rdram, ctx);
        goto after_5;
    // 0x80800268: nop

    after_5:
    // 0x8080026C: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80800270: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800274: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800278: addiu       $t4, $zero, -0xF
    ctx->r12 = ADD32(0, -0XF);
    // 0x8080027C: addiu       $t7, $zero, 0x5DC
    ctx->r15 = ADD32(0, 0X5DC);
    // 0x80800280: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80800284: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800288: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080028C: add.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: addiu       $a1, $zero, -0x4B
    ctx->r5 = ADD32(0, -0X4B);
    // 0x80800298: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8080029C: addiu       $a3, $zero, 0x4B0
    ctx->r7 = ADD32(0, 0X4B0);
    // 0x808002A0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808002A4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808002A8: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x808002AC: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x808002B0: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    // 0x808002B4: jal         0x800BA994
    // 0x808002B8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    func_800BA994(rdram, ctx);
        goto after_6;
    // 0x808002B8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_6:
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C0: jal         0x800BA22C
    // 0x808002C4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800BA22C(rdram, ctx);
        goto after_7;
    // 0x808002C4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x808002C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808002CC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808002D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
RECOMP_FUNC void func_80020758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020758: jr          $ra
    // 0x8002075C: nop

    return;
    // 0x8002075C: nop

;}
RECOMP_FUNC void vplight_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80800218: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8080021C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80800220: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80800224: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80800228: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8080022C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80800230: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800234: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800238: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8080023C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800240: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    // 0x80800244: lw          $t8, 0x1C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1C);
    // 0x80800248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080024C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800250: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x80800254: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800258: addu        $s6, $a1, $t8
    ctx->r22 = ADD32(ctx->r5, ctx->r24);
    // 0x8080025C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80800260: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800264: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x80800268: jal         0x800C8760
    // 0x8080026C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800C8760(rdram, ctx);
        goto after_0;
    // 0x8080026C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80800270: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x80800274: beq         $v0, $zero, L_80800480
    if (ctx->r2 == 0) {
        // 0x80800278: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80800480;
    }
    // 0x80800278: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8080027C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80800280: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
    // 0x80800284: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
L_80800288:
    // 0x80800288: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080028C: or          $fp, $s0, $zero
    ctx->r30 = ctx->r16 | 0;
    // 0x80800290: jal         0x800C89D8
    // 0x80800294: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    func_800C89D8(rdram, ctx);
        goto after_1;
    // 0x80800294: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    after_1:
    // 0x80800298: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x8080029C: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x808002A0: sltu        $at, $s0, $t1
    ctx->r1 = ctx->r16 < ctx->r9 ? 1 : 0;
    // 0x808002A4: beq         $at, $zero, L_80800324
    if (ctx->r1 == 0) {
        // 0x808002A8: nop
    
            goto L_80800324;
    }
    // 0x808002A8: nop

    // 0x808002AC: lbu         $t9, 0x0($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0X0);
L_808002B0:
    // 0x808002B0: beql        $t9, $zero, L_80800318
    if (ctx->r25 == 0) {
        // 0x808002B4: addiu       $fp, $fp, 0x10
        ctx->r30 = ADD32(ctx->r30, 0X10);
            goto L_80800318;
    }
    goto skip_0;
    // 0x808002B4: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
    skip_0:
    // 0x808002B8: lbu         $t2, 0x1($fp)
    ctx->r10 = MEM_BU(ctx->r30, 0X1);
    // 0x808002BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808002C0: or          $v1, $fp, $zero
    ctx->r3 = ctx->r30 | 0;
    // 0x808002C4: beql        $t2, $zero, L_80800318
    if (ctx->r10 == 0) {
        // 0x808002C8: addiu       $fp, $fp, 0x10
        ctx->r30 = ADD32(ctx->r30, 0X10);
            goto L_80800318;
    }
    goto skip_1;
    // 0x808002C8: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
    skip_1:
L_808002CC:
    // 0x808002CC: lbu         $t3, 0x2($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2);
    // 0x808002D0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808002D4: bne         $s3, $t3, L_8080030C
    if (ctx->r19 != ctx->r11) {
        // 0x808002D8: nop
    
            goto L_8080030C;
    }
    // 0x808002D8: nop

    // 0x808002DC: beq         $v0, $zero, L_808002F4
    if (ctx->r2 == 0) {
        // 0x808002E0: subu        $a0, $fp, $s0
        ctx->r4 = SUB32(ctx->r30, ctx->r16);
            goto L_808002F4;
    }
    // 0x808002E0: subu        $a0, $fp, $s0
    ctx->r4 = SUB32(ctx->r30, ctx->r16);
    // 0x808002E4: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x808002E8: lbu         $t4, 0x1($fp)
    ctx->r12 = MEM_BU(ctx->r30, 0X1);
    // 0x808002EC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x808002F0: sb          $t5, 0x1($fp)
    MEM_B(0X1, ctx->r30) = ctx->r13;
L_808002F4:
    // 0x808002F4: sra         $t6, $a0, 4
    ctx->r14 = S32(SIGNED(ctx->r4) >> 4);
    // 0x808002F8: multu       $t6, $s4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808002FC: mflo        $t7
    ctx->r15 = lo;
    // 0x80800300: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x80800304: b           L_80800314
    // 0x80800308: sb          $s5, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r21;
        goto L_80800314;
    // 0x80800308: sb          $s5, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r21;
L_8080030C:
    // 0x8080030C: bne         $a0, $s1, L_808002CC
    if (ctx->r4 != ctx->r17) {
        // 0x80800310: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_808002CC;
    }
    // 0x80800310: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800314:
    // 0x80800314: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
L_80800318:
    // 0x80800318: sltu        $at, $fp, $t1
    ctx->r1 = ctx->r30 < ctx->r9 ? 1 : 0;
    // 0x8080031C: bnel        $at, $zero, L_808002B0
    if (ctx->r1 != 0) {
        // 0x80800320: lbu         $t9, 0x0($fp)
        ctx->r25 = MEM_BU(ctx->r30, 0X0);
            goto L_808002B0;
    }
    goto skip_2;
    // 0x80800320: lbu         $t9, 0x0($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0X0);
    skip_2:
L_80800324:
    // 0x80800324: beq         $v0, $zero, L_80800460
    if (ctx->r2 == 0) {
        // 0x80800328: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800460;
    }
    // 0x80800328: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080032C: jal         0x800C8800
    // 0x80800330: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    func_800C8800(rdram, ctx);
        goto after_2;
    // 0x80800330: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    after_2:
    // 0x80800334: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800338: jal         0x800C883C
    // 0x8080033C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    func_800C883C(rdram, ctx);
        goto after_3;
    // 0x8080033C: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_3:
    // 0x80800340: addiu       $t9, $sp, 0x74
    ctx->r25 = ADD32(ctx->r29, 0X74);
    // 0x80800344: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800348: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080034C: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x80800350: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x80800354: jal         0x80800134
    // 0x80800358: addiu       $a3, $sp, 0x80
    ctx->r7 = ADD32(ctx->r29, 0X80);
    func_80800134_vplight(rdram, ctx);
        goto after_4;
    // 0x80800358: addiu       $a3, $sp, 0x80
    ctx->r7 = ADD32(ctx->r29, 0X80);
    after_4:
    // 0x8080035C: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80800360: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80800364: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x80800368: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8080036C: bnel        $at, $zero, L_80800464
    if (ctx->r1 != 0) {
        // 0x80800370: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800464;
    }
    goto skip_3;
    // 0x80800370: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_3:
    // 0x80800374: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
L_80800378:
    // 0x80800378: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8080037C: slt         $at, $t3, $a3
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80800380: bnel        $at, $zero, L_80800450
    if (ctx->r1 != 0) {
        // 0x80800384: lw          $t5, 0x7C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X7C);
            goto L_80800450;
    }
    goto skip_4;
    // 0x80800384: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    skip_4:
    // 0x80800388: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
L_8080038C:
    // 0x8080038C: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x80800390: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800394: bnel        $at, $zero, L_8080043C
    if (ctx->r1 != 0) {
        // 0x80800398: lw          $t4, 0x78($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X78);
            goto L_8080043C;
    }
    goto skip_5;
    // 0x80800398: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    skip_5:
    // 0x8080039C: lhu         $t5, 0xE($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0XE);
L_808003A0:
    // 0x808003A0: lhu         $t8, 0xC($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0XC);
    // 0x808003A4: multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808003A8: mflo        $t6
    ctx->r14 = lo;
    // 0x808003AC: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x808003B0: nop

    // 0x808003B4: multu       $a3, $t8
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808003B8: mflo        $t9
    ctx->r25 = lo;
    // 0x808003BC: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x808003C0: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x808003C4: addu        $t3, $s7, $t2
    ctx->r11 = ADD32(ctx->r23, ctx->r10);
    // 0x808003C8: lh          $a1, 0x0($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X0);
    // 0x808003CC: bltz        $a1, L_80800424
    if (SIGNED(ctx->r5) < 0) {
        // 0x808003D0: sll         $t4, $a1, 4
        ctx->r12 = S32(ctx->r5 << 4);
            goto L_80800424;
    }
    // 0x808003D0: sll         $t4, $a1, 4
    ctx->r12 = S32(ctx->r5 << 4);
    // 0x808003D4: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    // 0x808003D8: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x808003DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003E0: beq         $t5, $zero, L_80800424
    if (ctx->r13 == 0) {
        // 0x808003E4: addu        $v1, $a0, $v0
        ctx->r3 = ADD32(ctx->r4, ctx->r2);
            goto L_80800424;
    }
    // 0x808003E4: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
L_808003E8:
    // 0x808003E8: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x808003EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808003F0: bne         $t6, $zero, L_8080041C
    if (ctx->r14 != 0) {
        // 0x808003F4: nop
    
            goto L_8080041C;
    }
    // 0x808003F4: nop

    // 0x808003F8: multu       $a1, $s4
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808003FC: sb          $s3, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r19;
    // 0x80800400: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x80800404: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80800408: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x8080040C: mflo        $t9
    ctx->r25 = lo;
    // 0x80800410: addu        $t2, $t9, $s6
    ctx->r10 = ADD32(ctx->r25, ctx->r22);
    // 0x80800414: b           L_80800424
    // 0x80800418: sb          $s5, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r21;
        goto L_80800424;
    // 0x80800418: sb          $s5, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r21;
L_8080041C:
    // 0x8080041C: bnel        $v0, $s1, L_808003E8
    if (ctx->r2 != ctx->r17) {
        // 0x80800420: addu        $v1, $a0, $v0
        ctx->r3 = ADD32(ctx->r4, ctx->r2);
            goto L_808003E8;
    }
    goto skip_6;
    // 0x80800420: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    skip_6:
L_80800424:
    // 0x80800424: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80800428: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8080042C: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800430: beql        $at, $zero, L_808003A0
    if (ctx->r1 == 0) {
        // 0x80800434: lhu         $t5, 0xE($s2)
        ctx->r13 = MEM_HU(ctx->r18, 0XE);
            goto L_808003A0;
    }
    goto skip_7;
    // 0x80800434: lhu         $t5, 0xE($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0XE);
    skip_7:
    // 0x80800438: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
L_8080043C:
    // 0x8080043C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80800440: slt         $at, $t4, $a3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80800444: beql        $at, $zero, L_8080038C
    if (ctx->r1 == 0) {
        // 0x80800448: lw          $a2, 0x80($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X80);
            goto L_8080038C;
    }
    goto skip_8;
    // 0x80800448: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    skip_8:
    // 0x8080044C: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
L_80800450:
    // 0x80800450: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80800454: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80800458: beql        $at, $zero, L_80800378
    if (ctx->r1 == 0) {
        // 0x8080045C: lw          $a3, 0x84($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X84);
            goto L_80800378;
    }
    goto skip_9;
    // 0x8080045C: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    skip_9:
L_80800460:
    // 0x80800460: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80800464:
    // 0x80800464: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800468: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8080046C: jal         0x800C878C
    // 0x80800470: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    func_800C878C(rdram, ctx);
        goto after_5;
    // 0x80800470: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    after_5:
    // 0x80800474: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x80800478: bne         $v0, $zero, L_80800288
    if (ctx->r2 != 0) {
        // 0x8080047C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80800288;
    }
    // 0x8080047C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80800480:
    // 0x80800480: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800484: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800488: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8080048C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800490: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800494: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80800498: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8080049C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808004A0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x808004A4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x808004A8: jr          $ra
    // 0x808004AC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x808004AC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_8080027C_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080027C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800284: jal         0x808001D4
    // 0x80800288: nop

    func_808001D4_bscarry(rdram, ctx);
        goto after_0;
    // 0x80800288: nop

    after_0:
    // 0x8080028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800294: jr          $ra
    // 0x80800298: nop

    return;
    // 0x80800298: nop

;}
RECOMP_FUNC void _bapackctrl_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084788: syscall     119
    recomp_syscall_handler(rdram, ctx, 0x80084788);
    return;
    // 0x8008478C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800A5BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5BCC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5BD0: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x800A5BD4: jr          $ra
    // 0x800A5BD8: lbu         $v0, 0xB($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XB);
    return;
    // 0x800A5BD8: lbu         $v0, 0xB($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XB);
    // 0x800A5BDC: nop

;}
RECOMP_FUNC void ncbadive_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808000A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B0: jal         0x801107F0
    // 0x808000B4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_801107F0(rdram, ctx);
        goto after_0;
    // 0x808000B4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_0:
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: jal         0x80800080
    // 0x808000C0: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_80800080_ncbadive(rdram, ctx);
        goto after_1;
    // 0x808000C0: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_1:
    // 0x808000C4: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x808000C8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808000CC: jal         0x800EFB24
    // 0x808000D0: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x808000D0: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_2:
    // 0x808000D4: jal         0x800EEF94
    // 0x808000D8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    func_800EEF94(rdram, ctx);
        goto after_3;
    // 0x808000D8: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    after_3:
    // 0x808000DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3038, 0X1C0) << 16);
    // 0x808000E0: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x808000E4: lwc1        $f14, 0x1C0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3038, 0X1C0));
    // 0x808000E8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808000EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000F0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808000F4: lwc1        $f12, 0xC($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0XC);
    // 0x808000F8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x808000FC: jal         0x800F10B4
    // 0x80800100: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800100: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80800104: jal         0x800D8FF8
    // 0x80800108: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x80800108: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8080010C: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x80800110: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800114: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800118: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8080011C: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80800120: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800124: jal         0x800EFA20
    // 0x80800128: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    func_800EFA20(rdram, ctx);
        goto after_6;
    // 0x80800128: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_6:
    // 0x8080012C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80800130: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80800134: jal         0x800EFB24
    // 0x80800138: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_800EFB24(rdram, ctx);
        goto after_7;
    // 0x80800138: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_7:
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: jal         0x80111FD4
    // 0x80800144: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_80111FD4(rdram, ctx);
        goto after_8;
    // 0x80800144: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_8:
    // 0x80800148: beq         $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x8080014C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800158;
    }
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: jal         0x8011309C
    // 0x80800154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8011309C(rdram, ctx);
        goto after_9;
    // 0x80800154: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
L_80800158:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x80800080
    // 0x80800160: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_80800080_ncbadive(rdram, ctx);
        goto after_10;
    // 0x80800160: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_10:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8080016C: jal         0x80110A68
    // 0x80800170: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    func_80110A68(rdram, ctx);
        goto after_11;
    // 0x80800170: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_11:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80110790
    // 0x8080017C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80110790(rdram, ctx);
        goto after_12;
    // 0x8080017C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_12:
    // 0x80800180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800184: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800188: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void func_8010D6E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010D6E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8010D6E4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8010D6E8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8010D6EC: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8010D6F0: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8010D6F4: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8010D6F8: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8010D6FC: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x8010D700: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x8010D704: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8010D708: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8010D70C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8010D710: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8010D714: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_8010D718:
    // 0x8010D718: jal         0x800F6438
    // 0x8010D71C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x8010D71C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8010D720: beql        $v0, $zero, L_8010D760
    if (ctx->r2 == 0) {
        // 0x8010D724: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8010D760;
    }
    goto skip_0;
    // 0x8010D724: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8010D728: jal         0x800F682C
    // 0x8010D72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F682C(rdram, ctx);
        goto after_1;
    // 0x8010D72C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8010D730: beq         $v0, $zero, L_8010D748
    if (ctx->r2 == 0) {
        // 0x8010D734: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8010D748;
    }
    // 0x8010D734: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010D738: jal         0x80109EE0
    // 0x8010D73C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109EE0(rdram, ctx);
        goto after_2;
    // 0x8010D73C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8010D740: beql        $v0, $zero, L_8010D760
    if (ctx->r2 == 0) {
        // 0x8010D744: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8010D760;
    }
    goto skip_1;
    // 0x8010D744: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
L_8010D748:
    // 0x8010D748: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8010D74C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8010D750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010D754: jal         0x800F4F34
    // 0x8010D758: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800F4F34(rdram, ctx);
        goto after_3;
    // 0x8010D758: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x8010D75C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8010D760:
    // 0x8010D760: bne         $s0, $s3, L_8010D718
    if (ctx->r16 != ctx->r19) {
        // 0x8010D764: nop
    
            goto L_8010D718;
    }
    // 0x8010D764: nop

    // 0x8010D768: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8010D76C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8010D770: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8010D774: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8010D778: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8010D77C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8010D780: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8010D784: jr          $ra
    // 0x8010D788: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8010D788: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8010D78C: nop

;}
RECOMP_FUNC void subaddiejoy_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080012C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800130: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800134: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x80800138: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8080013C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80800140: jal         0x80016068
    // 0x80800144: srl         $a0, $t7, 30
    ctx->r4 = S32(U32(ctx->r15) >> 30);
    func_80016068(rdram, ctx);
        goto after_0;
    // 0x80800144: srl         $a0, $t7, 30
    ctx->r4 = S32(U32(ctx->r15) >> 30);
    after_0:
    // 0x80800148: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080014C: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800150: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800154: nop

    // 0x80800158: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8080015C: jal         0x8002DCA0
    // 0x80800160: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80800160: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80800164: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800168: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8080016C: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800170: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80800174: nop

    // 0x80800178: bc1tl       L_808001CC
    if (c1cs) {
        // 0x8080017C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001CC;
    }
    goto skip_0;
    // 0x8080017C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800180: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800184: jal         0x80013B70
    // 0x80800188: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    func_80013B70(rdram, ctx);
        goto after_2;
    // 0x80800188: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x8080018C: jal         0x800E3A80
    // 0x80800190: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_800E3A80(rdram, ctx);
        goto after_3;
    // 0x80800190: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80800194: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800198: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080019C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808001A0: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x808001A4: jal         0x800136E4
    // 0x808001A8: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x808001A8: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_4:
    // 0x808001AC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x808001B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001B8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x808001BC: jal         0x800F13F0
    // 0x808001C0: swc1        $f0, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->f0.u32l;
    func_800F13F0(rdram, ctx);
        goto after_5;
    // 0x808001C0: swc1        $f0, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->f0.u32l;
    after_5:
    // 0x808001C4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808001C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001CC:
    // 0x808001CC: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x808001D0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808001D4: jr          $ra
    // 0x808001D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808001D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void chbeanstalkseed_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080031C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2356, 0XC00) << 16);
    // 0x80800320: jr          $ra
    // 0x80800324: addiu       $v0, $v0, 0xC00
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2356, 0XC00));
    return;
    // 0x80800324: addiu       $v0, $v0, 0xC00
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2356, 0XC00));
;}
RECOMP_FUNC void func_80103AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80103AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103AEC: lhu         $a1, 0x14($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X14);
    // 0x80103AF0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80103AF4: beq         $a1, $zero, L_80103B04
    if (ctx->r5 == 0) {
        // 0x80103AF8: nop
    
            goto L_80103B04;
    }
    // 0x80103AF8: nop

    // 0x80103AFC: bne         $a1, $at, L_80103B0C
    if (ctx->r5 != ctx->r1) {
        // 0x80103B00: nop
    
            goto L_80103B0C;
    }
    // 0x80103B00: nop

L_80103B04:
    // 0x80103B04: b           L_80103B14
    // 0x80103B08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103B14;
    // 0x80103B08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80103B0C:
    // 0x80103B0C: jal         0x800D674C
    // 0x80103B10: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80103B10: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_80103B14:
    // 0x80103B14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103B18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103B1C: jr          $ra
    // 0x80103B20: nop

    return;
    // 0x80103B20: nop

;}
RECOMP_FUNC void func_80013678(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001367C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013680: jal         0x800131C0
    // 0x80013684: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800131C0(rdram, ctx);
        goto after_0;
    // 0x80013684: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80013688: jal         0x80012548
    // 0x8001368C: nop

    func_80012548(rdram, ctx);
        goto after_1;
    // 0x8001368C: nop

    after_1:
    // 0x80013690: jal         0x80012598
    // 0x80013694: nop

    func_80012598(rdram, ctx);
        goto after_2;
    // 0x80013694: nop

    after_2:
    // 0x80013698: jal         0x8002E510
    // 0x8001369C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_3;
    // 0x8001369C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
L_800136A0:
    // 0x800136A0: b           L_800136A0
    pause_self(rdram);
    // 0x800136A4: nop

    // 0x800136A8: nop

    // 0x800136AC: nop

    // 0x800136B0: nop

    // 0x800136B4: nop

    // 0x800136B8: nop

    // 0x800136BC: nop

    // 0x800136C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800136C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800136C8: jr          $ra
    // 0x800136CC: nop

    return;
    // 0x800136CC: nop

;}
RECOMP_FUNC void func_800CDFD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDFD0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800CDFD4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CDFD8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800CDFDC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800CDFE0: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800CDFE4: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800CDFE8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800CDFEC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800CDFF0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CDFF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CDFF8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CDFFC: lw          $a0, 0x24($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X24);
    // 0x800CE000: srl         $t6, $a0, 22
    ctx->r14 = S32(U32(ctx->r4) >> 22);
    // 0x800CE004: jal         0x800CE21C
    // 0x800CE008: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800CE21C(rdram, ctx);
        goto after_0;
    // 0x800CE008: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x800CE00C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CE010: beq         $v0, $at, L_800CE17C
    if (ctx->r2 == ctx->r1) {
        // 0x800CE014: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800CE17C;
    }
    // 0x800CE014: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800CE018: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CE01C: addiu       $a0, $a0, -0x4FE0
    ctx->r4 = ADD32(ctx->r4, -0X4FE0);
    // 0x800CE020: jal         0x800DAB54
    // 0x800CE024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DAB54(rdram, ctx);
        goto after_1;
    // 0x800CE024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800CE028: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CE02C: bne         $v0, $at, L_800CE17C
    if (ctx->r2 != ctx->r1) {
        // 0x800CE030: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800CE17C;
    }
    // 0x800CE030: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CE034: jal         0x800EC370
    // 0x800CE038: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EC370(rdram, ctx);
        goto after_2;
    // 0x800CE038: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_2:
    // 0x800CE03C: lh          $t7, 0x4C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4C);
    // 0x800CE040: lh          $t8, 0x4E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X4E);
    // 0x800CE044: lh          $t9, 0x50($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X50);
    // 0x800CE048: addiu       $s4, $sp, 0x68
    ctx->r20 = ADD32(ctx->r29, 0X68);
    // 0x800CE04C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800CE050: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x800CE054: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x800CE058: jal         0x800BDD24
    // 0x800CE05C: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    func_800BDD24(rdram, ctx);
        goto after_3;
    // 0x800CE05C: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    after_3:
    // 0x800CE060: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800CE064: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800CE068: addiu       $s7, $zero, 0x14
    ctx->r23 = ADD32(0, 0X14);
    // 0x800CE06C: beq         $t0, $zero, L_800CE17C
    if (ctx->r8 == 0) {
        // 0x800CE070: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800CE17C;
    }
    // 0x800CE070: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800CE074: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
L_800CE078:
    // 0x800CE078: jal         0x800E9D68
    // 0x800CE07C: nop

    func_800E9D68(rdram, ctx);
        goto after_4;
    // 0x800CE07C: nop

    after_4:
    // 0x800CE080: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800CE084: jal         0x800E9DD4
    // 0x800CE088: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_800E9DD4(rdram, ctx);
        goto after_5;
    // 0x800CE088: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_5:
    // 0x800CE08C: multu       $v0, $s7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CE090: mflo        $t1
    ctx->r9 = lo;
    // 0x800CE094: addu        $s3, $t1, $s0
    ctx->r19 = ADD32(ctx->r9, ctx->r16);
    // 0x800CE098: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x800CE09C: beql        $at, $zero, L_800CE170
    if (ctx->r1 == 0) {
        // 0x800CE0A0: lw          $a0, 0x4($s6)
        ctx->r4 = MEM_W(ctx->r22, 0X4);
            goto L_800CE170;
    }
    goto skip_0;
    // 0x800CE0A0: lw          $a0, 0x4($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X4);
    skip_0:
L_800CE0A4:
    // 0x800CE0A4: jal         0x80088BA8
    // 0x800CE0A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gspropctrl_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x800CE0A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800CE0AC: bne         $v0, $s5, L_800CE15C
    if (ctx->r2 != ctx->r21) {
        // 0x800CE0B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800CE15C;
    }
    // 0x800CE0B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CE0B4: jal         0x80088BB0
    // 0x800CE0B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _gspropctrl_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x800CE0B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800CE0BC: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x800CE0C0: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x800CE0C4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CE0C8: subu        $t2, $v1, $v0
    ctx->r10 = SUB32(ctx->r3, ctx->r2);
    // 0x800CE0CC: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800CE0D0: beq         $at, $zero, L_800CE15C
    if (ctx->r1 == 0) {
        // 0x800CE0D4: addu        $t4, $v1, $v0
        ctx->r12 = ADD32(ctx->r3, ctx->r2);
            goto L_800CE15C;
    }
    // 0x800CE0D4: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x800CE0D8: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800CE0DC: beql        $at, $zero, L_800CE160
    if (ctx->r1 == 0) {
        // 0x800CE0E0: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800CE160;
    }
    goto skip_1;
    // 0x800CE0E0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_1:
    // 0x800CE0E4: lb          $t6, 0x13($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X13);
    // 0x800CE0E8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800CE0EC: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800CE0F0: bgez        $t6, L_800CE118
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800CE0F4: lw          $t8, 0x68($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X68);
            goto L_800CE118;
    }
    // 0x800CE0F4: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800CE0F8: jal         0x800CE1A8
    // 0x800CE0FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800CE1A8(rdram, ctx);
        goto after_8;
    // 0x800CE0FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800CE100: beq         $v0, $zero, L_800CE15C
    if (ctx->r2 == 0) {
        // 0x800CE104: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800CE15C;
    }
    // 0x800CE104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CE108: jal         0x800D5318
    // 0x800CE10C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800D5318(rdram, ctx);
        goto after_9;
    // 0x800CE10C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x800CE110: b           L_800CE160
    // 0x800CE114: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
        goto L_800CE160;
    // 0x800CE114: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_800CE118:
    // 0x800CE118: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x800CE11C: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800CE120: beq         $at, $zero, L_800CE15C
    if (ctx->r1 == 0) {
        // 0x800CE124: addu        $t9, $v1, $v0
        ctx->r25 = ADD32(ctx->r3, ctx->r2);
            goto L_800CE15C;
    }
    // 0x800CE124: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x800CE128: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800CE12C: beq         $at, $zero, L_800CE15C
    if (ctx->r1 == 0) {
        // 0x800CE130: lw          $v1, 0x64($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X64);
            goto L_800CE15C;
    }
    // 0x800CE130: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x800CE134: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800CE138: subu        $t0, $v1, $v0
    ctx->r8 = SUB32(ctx->r3, ctx->r2);
    // 0x800CE13C: addu        $t2, $v1, $v0
    ctx->r10 = ADD32(ctx->r3, ctx->r2);
    // 0x800CE140: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800CE144: beq         $at, $zero, L_800CE15C
    if (ctx->r1 == 0) {
        // 0x800CE148: slt         $at, $t1, $t2
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800CE15C;
    }
    // 0x800CE148: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800CE14C: beq         $at, $zero, L_800CE15C
    if (ctx->r1 == 0) {
        // 0x800CE150: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800CE15C;
    }
    // 0x800CE150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CE154: jal         0x800D5318
    // 0x800CE158: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800D5318(rdram, ctx);
        goto after_10;
    // 0x800CE158: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_10:
L_800CE15C:
    // 0x800CE15C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_800CE160:
    // 0x800CE160: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x800CE164: bne         $at, $zero, L_800CE0A4
    if (ctx->r1 != 0) {
        // 0x800CE168: nop
    
            goto L_800CE0A4;
    }
    // 0x800CE168: nop

    // 0x800CE16C: lw          $a0, 0x4($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X4);
L_800CE170:
    // 0x800CE170: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x800CE174: bne         $a0, $zero, L_800CE078
    if (ctx->r4 != 0) {
        // 0x800CE178: nop
    
            goto L_800CE078;
    }
    // 0x800CE178: nop

L_800CE17C:
    // 0x800CE17C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800CE180: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CE184: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CE188: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CE18C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CE190: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800CE194: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800CE198: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800CE19C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800CE1A0: jr          $ra
    // 0x800CE1A4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800CE1A4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void _fxsparkle_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888D0: syscall     709
    recomp_syscall_handler(rdram, ctx, 0x800888D0);
    return;
    // 0x800888D4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80103508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103508: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8010350C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80103510: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80103514: lw          $t6, 0x70($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X70);
    // 0x80103518: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010351C: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x80103520: bltzl       $t8, L_8010380C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80103524: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8010380C;
    }
    goto skip_0;
    // 0x80103524: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80103528: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8010352C: jal         0x80100368
    // 0x80103530: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    func_80100368(rdram, ctx);
        goto after_0;
    // 0x80103530: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    after_0:
    // 0x80103534: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80103538: jal         0x801039A4
    // 0x8010353C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_801039A4(rdram, ctx);
        goto after_1;
    // 0x8010353C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x80103540: bne         $v0, $zero, L_80103554
    if (ctx->r2 != 0) {
        // 0x80103544: sw          $v0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r2;
            goto L_80103554;
    }
    // 0x80103544: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80103548: jal         0x801039E4
    // 0x8010354C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_801039E4(rdram, ctx);
        goto after_2;
    // 0x8010354C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_2:
    // 0x80103550: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
L_80103554:
    // 0x80103554: jal         0x80103328
    // 0x80103558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103328(rdram, ctx);
        goto after_3;
    // 0x80103558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8010355C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80103560: lhu         $v1, 0x16($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X16);
    // 0x80103564: beql        $v1, $zero, L_80103580
    if (ctx->r3 == 0) {
        // 0x80103568: sw          $zero, 0x54($sp)
        MEM_W(0X54, ctx->r29) = 0;
            goto L_80103580;
    }
    goto skip_1;
    // 0x80103568: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    skip_1:
    // 0x8010356C: jal         0x800D674C
    // 0x80103570: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    func_800D674C(rdram, ctx);
        goto after_4;
    // 0x80103570: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    after_4:
    // 0x80103574: b           L_80103580
    // 0x80103578: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
        goto L_80103580;
    // 0x80103578: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8010357C: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
L_80103580:
    // 0x80103580: lbu         $t1, 0x7B($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7B);
    // 0x80103584: srl         $t2, $t1, 6
    ctx->r10 = S32(U32(ctx->r9) >> 6);
    // 0x80103588: beql        $t2, $zero, L_8010359C
    if (ctx->r10 == 0) {
        // 0x8010358C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8010359C;
    }
    goto skip_2;
    // 0x8010358C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    skip_2:
    // 0x80103590: b           L_8010359C
    // 0x80103594: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_8010359C;
    // 0x80103594: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80103598: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8010359C:
    // 0x8010359C: lbu         $t3, 0x70($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X70);
    // 0x801035A0: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x801035A4: beql        $t4, $zero, L_801035B8
    if (ctx->r12 == 0) {
        // 0x801035A8: lw          $t5, 0x70($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X70);
            goto L_801035B8;
    }
    goto skip_3;
    // 0x801035A8: lw          $t5, 0x70($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X70);
    skip_3:
    // 0x801035AC: b           L_801035D4
    // 0x801035B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_801035D4;
    // 0x801035B0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801035B4: lw          $t5, 0x70($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X70);
L_801035B8:
    // 0x801035B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801035BC: sll         $t7, $t5, 10
    ctx->r15 = S32(ctx->r13 << 10);
    // 0x801035C0: bgez        $t7, L_801035D0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801035C4: nop
    
            goto L_801035D0;
    }
    // 0x801035C4: nop

    // 0x801035C8: b           L_801035D0
    // 0x801035CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801035D0;
    // 0x801035CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801035D0:
    // 0x801035D0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_801035D4:
    // 0x801035D4: bnel        $a3, $zero, L_801035E8
    if (ctx->r7 != 0) {
        // 0x801035D8: lh          $t8, 0x60($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X60);
            goto L_801035E8;
    }
    goto skip_4;
    // 0x801035D8: lh          $t8, 0x60($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X60);
    skip_4:
    // 0x801035DC: beql        $a2, $zero, L_80103668
    if (ctx->r6 == 0) {
        // 0x801035E0: lw          $t3, 0x54($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X54);
            goto L_80103668;
    }
    goto skip_5;
    // 0x801035E0: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    skip_5:
    // 0x801035E4: lh          $t8, 0x60($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X60);
L_801035E8:
    // 0x801035E8: bnel        $t8, $zero, L_80103668
    if (ctx->r24 != 0) {
        // 0x801035EC: lw          $t3, 0x54($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X54);
            goto L_80103668;
    }
    goto skip_6;
    // 0x801035EC: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    skip_6:
    // 0x801035F0: lhu         $v0, 0x96($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X96);
    // 0x801035F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801035F8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801035FC: srl         $t9, $v0, 15
    ctx->r25 = S32(U32(ctx->r2) >> 15);
    // 0x80103600: beq         $t9, $zero, L_80103628
    if (ctx->r25 == 0) {
        // 0x80103604: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80103628;
    }
    // 0x80103604: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80103608: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8010360C: jal         0x80089CD8
    // 0x80103610: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80103610: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_5:
    // 0x80103614: lhu         $v0, 0x96($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X96);
    // 0x80103618: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8010361C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80103620: srl         $t0, $v0, 15
    ctx->r8 = S32(U32(ctx->r2) >> 15);
    // 0x80103624: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80103628:
    // 0x80103628: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8010362C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80103630: beq         $v0, $zero, L_80103640
    if (ctx->r2 == 0) {
        // 0x80103634: lhu         $v1, 0x16($t1)
        ctx->r3 = MEM_HU(ctx->r9, 0X16);
            goto L_80103640;
    }
    // 0x80103634: lhu         $v1, 0x16($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X16);
    // 0x80103638: b           L_80103644
    // 0x8010363C: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
        goto L_80103644;
    // 0x8010363C: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
L_80103640:
    // 0x80103640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80103644:
    // 0x80103644: lhu         $a1, 0x14($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X14);
    // 0x80103648: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8010364C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80103650: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80103654: jal         0x80100D24
    // 0x80103658: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80100D24(rdram, ctx);
        goto after_6;
    // 0x80103658: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_6:
    // 0x8010365C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80103660: sh          $v0, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r2;
    // 0x80103664: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
L_80103668:
    // 0x80103668: slti        $at, $a2, 0x2
    ctx->r1 = SIGNED(ctx->r6) < 0X2 ? 1 : 0;
    // 0x8010366C: beql        $t3, $zero, L_801036A4
    if (ctx->r11 == 0) {
        // 0x80103670: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_801036A4;
    }
    goto skip_7;
    // 0x80103670: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    skip_7:
    // 0x80103674: bnel        $at, $zero, L_801036A4
    if (ctx->r1 != 0) {
        // 0x80103678: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_801036A4;
    }
    goto skip_8;
    // 0x80103678: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    skip_8:
    // 0x8010367C: jal         0x80103D24
    // 0x80103680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103D24(rdram, ctx);
        goto after_7;
    // 0x80103680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80103684: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80103688: jal         0x800B2840
    // 0x8010368C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800B2840(rdram, ctx);
        goto after_8;
    // 0x8010368C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_8:
    // 0x80103690: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80103694: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80103698: jal         0x800B25D8
    // 0x8010369C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    func_800B25D8(rdram, ctx);
        goto after_9;
    // 0x8010369C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    after_9:
    // 0x801036A0: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
L_801036A4:
    // 0x801036A4: beql        $t4, $zero, L_801036E0
    if (ctx->r12 == 0) {
        // 0x801036A8: lw          $t6, 0x58($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X58);
            goto L_801036E0;
    }
    goto skip_9;
    // 0x801036A8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    skip_9:
    // 0x801036AC: jal         0x80103C94
    // 0x801036B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103C94(rdram, ctx);
        goto after_10;
    // 0x801036B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801036B4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x801036B8: jal         0x800B2840
    // 0x801036BC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800B2840(rdram, ctx);
        goto after_11;
    // 0x801036BC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_11:
    // 0x801036C0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x801036C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801036C8: jal         0x800B25D8
    // 0x801036CC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    func_800B25D8(rdram, ctx);
        goto after_12;
    // 0x801036CC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    after_12:
    // 0x801036D0: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x801036D4: jal         0x800D6CEC
    // 0x801036D8: lhu         $a0, 0x16($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X16);
    func_800D6CEC(rdram, ctx);
        goto after_13;
    // 0x801036D8: lhu         $a0, 0x16($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X16);
    after_13:
    // 0x801036DC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
L_801036E0:
    // 0x801036E0: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x801036E4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801036E8: bnel        $t7, $zero, L_80103714
    if (ctx->r15 != 0) {
        // 0x801036EC: lh          $t9, 0x90($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X90);
            goto L_80103714;
    }
    goto skip_10;
    // 0x801036EC: lh          $t9, 0x90($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X90);
    skip_10:
    // 0x801036F0: jal         0x80102FA0
    // 0x801036F4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80102FA0(rdram, ctx);
        goto after_14;
    // 0x801036F4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_14:
    // 0x801036F8: beql        $v0, $zero, L_80103714
    if (ctx->r2 == 0) {
        // 0x801036FC: lh          $t9, 0x90($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X90);
            goto L_80103714;
    }
    goto skip_11;
    // 0x801036FC: lh          $t9, 0x90($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X90);
    skip_11:
    // 0x80103700: jal         0x800DBFF8
    // 0x80103704: nop

    func_800DBFF8(rdram, ctx);
        goto after_15;
    // 0x80103704: nop

    after_15:
    // 0x80103708: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8010370C: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x80103710: lh          $t9, 0x90($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X90);
L_80103714:
    // 0x80103714: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80103718: bnel        $t9, $zero, L_8010373C
    if (ctx->r25 != 0) {
        // 0x8010371C: lw          $t0, 0x58($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X58);
            goto L_8010373C;
    }
    goto skip_12;
    // 0x8010371C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    skip_12:
    // 0x80103720: jal         0x80102FA0
    // 0x80103724: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    func_80102FA0(rdram, ctx);
        goto after_16;
    // 0x80103724: addiu       $a1, $zero, 0x1000
    ctx->r5 = ADD32(0, 0X1000);
    after_16:
    // 0x80103728: beql        $v0, $zero, L_8010373C
    if (ctx->r2 == 0) {
        // 0x8010372C: lw          $t0, 0x58($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X58);
            goto L_8010373C;
    }
    goto skip_13;
    // 0x8010372C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    skip_13:
    // 0x80103730: jal         0x80105DFC
    // 0x80103734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105DFC(rdram, ctx);
        goto after_17;
    // 0x80103734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80103738: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
L_8010373C:
    // 0x8010373C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80103740: lh          $t1, 0x10($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X10);
    // 0x80103744: bnel        $t1, $zero, L_80103770
    if (ctx->r9 != 0) {
        // 0x80103748: lhu         $t3, 0x80($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X80);
            goto L_80103770;
    }
    goto skip_14;
    // 0x80103748: lhu         $t3, 0x80($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X80);
    skip_14:
    // 0x8010374C: jal         0x80102FA0
    // 0x80103750: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80102FA0(rdram, ctx);
        goto after_18;
    // 0x80103750: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_18:
    // 0x80103754: beql        $v0, $zero, L_80103770
    if (ctx->r2 == 0) {
        // 0x80103758: lhu         $t3, 0x80($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X80);
            goto L_80103770;
    }
    goto skip_15;
    // 0x80103758: lhu         $t3, 0x80($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X80);
    skip_15:
    // 0x8010375C: jal         0x800AE020
    // 0x80103760: nop

    func_800AE020(rdram, ctx);
        goto after_19;
    // 0x80103760: nop

    after_19:
    // 0x80103764: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x80103768: sh          $v0, 0x10($t2)
    MEM_H(0X10, ctx->r10) = ctx->r2;
    // 0x8010376C: lhu         $t3, 0x80($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X80);
L_80103770:
    // 0x80103770: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80103774: bnel        $t3, $zero, L_8010379C
    if (ctx->r11 != 0) {
        // 0x80103778: lh          $t4, 0x8C($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X8C);
            goto L_8010379C;
    }
    goto skip_16;
    // 0x80103778: lh          $t4, 0x8C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X8C);
    skip_16:
    // 0x8010377C: jal         0x80102FA0
    // 0x80103780: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    func_80102FA0(rdram, ctx);
        goto after_20;
    // 0x80103780: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    after_20:
    // 0x80103784: beql        $v0, $zero, L_8010379C
    if (ctx->r2 == 0) {
        // 0x80103788: lh          $t4, 0x8C($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X8C);
            goto L_8010379C;
    }
    goto skip_17;
    // 0x80103788: lh          $t4, 0x8C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X8C);
    skip_17:
    // 0x8010378C: jal         0x800D88F8
    // 0x80103790: nop

    func_800D88F8(rdram, ctx);
        goto after_21;
    // 0x80103790: nop

    after_21:
    // 0x80103794: sh          $v0, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r2;
    // 0x80103798: lh          $t4, 0x8C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X8C);
L_8010379C:
    // 0x8010379C: bnel        $t4, $zero, L_801037C8
    if (ctx->r12 != 0) {
        // 0x801037A0: lh          $t8, 0x8E($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X8E);
            goto L_801037C8;
    }
    goto skip_18;
    // 0x801037A0: lh          $t8, 0x8E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8E);
    skip_18:
    // 0x801037A4: lb          $t6, 0x75($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X75);
    // 0x801037A8: bgezl       $t6, L_801037C8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801037AC: lh          $t8, 0x8E($s0)
        ctx->r24 = MEM_H(ctx->r16, 0X8E);
            goto L_801037C8;
    }
    goto skip_19;
    // 0x801037AC: lh          $t8, 0x8E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8E);
    skip_19:
    // 0x801037B0: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x801037B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801037B8: srl         $t7, $a1, 10
    ctx->r15 = S32(U32(ctx->r5) >> 10);
    // 0x801037BC: jal         0x80102424
    // 0x801037C0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x801037C0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_22:
    // 0x801037C4: lh          $t8, 0x8E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8E);
L_801037C8:
    // 0x801037C8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x801037CC: bnel        $t8, $zero, L_801037F0
    if (ctx->r24 != 0) {
        // 0x801037D0: lbu         $t0, 0x73($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X73);
            goto L_801037F0;
    }
    goto skip_20;
    // 0x801037D0: lbu         $t0, 0x73($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X73);
    skip_20:
    // 0x801037D4: jal         0x80102FA0
    // 0x801037D8: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    func_80102FA0(rdram, ctx);
        goto after_23;
    // 0x801037D8: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    after_23:
    // 0x801037DC: beql        $v0, $zero, L_801037F0
    if (ctx->r2 == 0) {
        // 0x801037E0: lbu         $t0, 0x73($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X73);
            goto L_801037F0;
    }
    goto skip_21;
    // 0x801037E0: lbu         $t0, 0x73($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X73);
    skip_21:
    // 0x801037E4: jal         0x80104460
    // 0x801037E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104460(rdram, ctx);
        goto after_24;
    // 0x801037E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x801037EC: lbu         $t0, 0x73($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X73);
L_801037F0:
    // 0x801037F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801037F4: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x801037F8: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x801037FC: sb          $t1, 0x73($s0)
    MEM_B(0X73, ctx->r16) = ctx->r9;
    // 0x80103800: jal         0x8010108C
    // 0x80103804: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    func_8010108C(rdram, ctx);
        goto after_25;
    // 0x80103804: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    after_25:
    // 0x80103808: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8010380C:
    // 0x8010380C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80103810: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80103814: jr          $ra
    // 0x80103818: nop

    return;
    // 0x80103818: nop

;}
RECOMP_FUNC void func_80107858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010785C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107860: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80107864: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80107868: lh          $a1, 0xA($a1)
    ctx->r5 = MEM_H(ctx->r5, 0XA);
    // 0x8010786C: jal         0x801073F8
    // 0x80107870: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_801073F8(rdram, ctx);
        goto after_0;
    // 0x80107870: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80107874: bne         $v0, $zero, L_80107888
    if (ctx->r2 != 0) {
        // 0x80107878: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80107888;
    }
    // 0x80107878: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8010787C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80107880: jal         0x801078DC
    // 0x80107884: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    func_801078DC(rdram, ctx);
        goto after_1;
    // 0x80107884: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
L_80107888:
    // 0x80107888: jal         0x80089C90
    // 0x8010788C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x8010788C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80107890: bne         $v0, $zero, L_801078A0
    if (ctx->r2 != 0) {
        // 0x80107894: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801078A0;
    }
    // 0x80107894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107898: b           L_801078A4
    // 0x8010789C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801078A4;
    // 0x8010789C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801078A0:
    // 0x801078A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801078A4:
    // 0x801078A4: jr          $ra
    // 0x801078A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801078A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8008E9B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E9B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E9BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E9C0: jal         0x8008E4B8
    // 0x8008E9C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8008E4B8(rdram, ctx);
        goto after_0;
    // 0x8008E9C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008E9C8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E9CC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8008E9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E9D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E9D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8008E9DC: jr          $ra
    // 0x8008E9E0: nop

    return;
    // 0x8008E9E0: nop

;}
RECOMP_FUNC void func_80800E1C_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800E24: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800E30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800E34: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80800E38: jal         0x80100094
    // 0x80800E3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E40: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E44: slti        $at, $a2, 0x97
    ctx->r1 = SIGNED(ctx->r6) < 0X97 ? 1 : 0;
    // 0x80800E48: bne         $at, $zero, L_80800E64
    if (ctx->r1 != 0) {
        // 0x80800E4C: addiu       $t6, $a2, -0x2E
        ctx->r14 = ADD32(ctx->r6, -0X2E);
            goto L_80800E64;
    }
    // 0x80800E4C: addiu       $t6, $a2, -0x2E
    ctx->r14 = ADD32(ctx->r6, -0X2E);
    // 0x80800E50: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x80800E54: beq         $a2, $at, L_80800F9C
    if (ctx->r6 == ctx->r1) {
        // 0x80800E58: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800F9C;
    }
    // 0x80800E58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E5C: b           L_80800FE0
    // 0x80800E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FE0;
    // 0x80800E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E64:
    // 0x80800E64: slti        $at, $a2, 0x50
    ctx->r1 = SIGNED(ctx->r6) < 0X50 ? 1 : 0;
    // 0x80800E68: bne         $at, $zero, L_80800E80
    if (ctx->r1 != 0) {
        // 0x80800E6C: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_80800E80;
    }
    // 0x80800E6C: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80800E70: beq         $a2, $at, L_80800FAC
    if (ctx->r6 == ctx->r1) {
        // 0x80800E74: nop
    
            goto L_80800FAC;
    }
    // 0x80800E74: nop

    // 0x80800E78: b           L_80800FE0
    // 0x80800E7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FE0;
    // 0x80800E7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E80:
    // 0x80800E80: sltiu       $at, $t6, 0x22
    ctx->r1 = ctx->r14 < 0X22 ? 1 : 0;
    // 0x80800E84: beq         $at, $zero, L_80800FD4
    if (ctx->r1 == 0) {
        // 0x80800E88: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800FD4;
    }
    // 0x80800E88: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800E8C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2208, 0X135C) << 16);
    // 0x80800E90: addu        $at, $at, $t6
    gpr jr_addend_80800E98 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800E94: lw          $t6, 0x135C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2208, 0X135C));
    // 0x80800E98: jr          $t6
    // 0x80800E9C: nop

    switch (jr_addend_80800E98 >> 2) {
        case 0: goto L_80800F84; break;
        case 1: goto L_80800FD4; break;
        case 2: goto L_80800F6C; break;
        case 3: goto L_80800FD4; break;
        case 4: goto L_80800FD4; break;
        case 5: goto L_80800FD4; break;
        case 6: goto L_80800FD4; break;
        case 7: goto L_80800FD4; break;
        case 8: goto L_80800FD4; break;
        case 9: goto L_80800FD4; break;
        case 10: goto L_80800FD4; break;
        case 11: goto L_80800FD4; break;
        case 12: goto L_80800FD4; break;
        case 13: goto L_80800FD4; break;
        case 14: goto L_80800FD4; break;
        case 15: goto L_80800F50; break;
        case 16: goto L_80800FD4; break;
        case 17: goto L_80800FD4; break;
        case 18: goto L_80800FD4; break;
        case 19: goto L_80800FD4; break;
        case 20: goto L_80800FD4; break;
        case 21: goto L_80800FD4; break;
        case 22: goto L_80800FD4; break;
        case 23: goto L_80800FD4; break;
        case 24: goto L_80800FD4; break;
        case 25: goto L_80800FD4; break;
        case 26: goto L_80800FD4; break;
        case 27: goto L_80800EA0; break;
        case 28: goto L_80800FD4; break;
        case 29: goto L_80800FD4; break;
        case 30: goto L_80800FD4; break;
        case 31: goto L_80800FD4; break;
        case 32: goto L_80800FD4; break;
        case 33: goto L_80800F04; break;
        default: switch_error(__func__, 0x80800E98, 0x8080135C);
    }
    // 0x80800E9C: nop

L_80800EA0:
    // 0x80800EA0: jal         0x8080045C
    // 0x80800EA4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8080045C_chclinker(rdram, ctx);
        goto after_1;
    // 0x80800EA4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80800EA8: beq         $v0, $zero, L_80800FDC
    if (ctx->r2 == 0) {
        // 0x80800EAC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800FDC;
    }
    // 0x80800EAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800EB0: jal         0x80100094
    // 0x80800EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800EB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800EB8: jal         0x80800598
    // 0x80800EBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800598_chclinker(rdram, ctx);
        goto after_3;
    // 0x80800EBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800EC0: jal         0x800D395C
    // 0x80800EC4: nop

    func_800D395C(rdram, ctx);
        goto after_4;
    // 0x80800EC4: nop

    after_4:
    // 0x80800EC8: beq         $v0, $zero, L_80800EE4
    if (ctx->r2 == 0) {
        // 0x80800ECC: addiu       $a0, $zero, 0x35
        ctx->r4 = ADD32(0, 0X35);
            goto L_80800EE4;
    }
    // 0x80800ECC: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x80800ED0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800ED4: jal         0x808008E0
    // 0x80800ED8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808008E0_chclinker(rdram, ctx);
        goto after_5;
    // 0x80800ED8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_5:
    // 0x80800EDC: b           L_80800FE0
    // 0x80800EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE0;
    // 0x80800EE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EE4:
    // 0x80800EE4: jal         0x800D0A9C
    // 0x80800EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_6;
    // 0x80800EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800EEC: bne         $v0, $zero, L_80800FDC
    if (ctx->r2 != 0) {
        // 0x80800EF0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800FDC;
    }
    // 0x80800EF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800EF4: jal         0x808008E0
    // 0x80800EF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808008E0_chclinker(rdram, ctx);
        goto after_7;
    // 0x80800EF8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800EFC: b           L_80800FE0
    // 0x80800F00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE0;
    // 0x80800F00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F04:
    // 0x80800F04: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80800F08: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80800F0C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800F10: beq         $t8, $zero, L_80800F28
    if (ctx->r24 == 0) {
        // 0x80800F14: sw          $t8, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r24;
            goto L_80800F28;
    }
    // 0x80800F14: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80800F18: jal         0x800FC63C
    // 0x80800F1C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_800FC63C(rdram, ctx);
        goto after_8;
    // 0x80800F1C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_8:
    // 0x80800F20: b           L_80800FE0
    // 0x80800F24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE0;
    // 0x80800F24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F28:
    // 0x80800F28: jal         0x800D395C
    // 0x80800F2C: nop

    func_800D395C(rdram, ctx);
        goto after_9;
    // 0x80800F2C: nop

    after_9:
    // 0x80800F30: beq         $v0, $zero, L_80800F40
    if (ctx->r2 == 0) {
        // 0x80800F34: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80800F40;
    }
    // 0x80800F34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800F38: b           L_80800F40
    // 0x80800F3C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
        goto L_80800F40;
    // 0x80800F3C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_80800F40:
    // 0x80800F40: jal         0x808008E0
    // 0x80800F44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808008E0_chclinker(rdram, ctx);
        goto after_10;
    // 0x80800F44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_10:
    // 0x80800F48: b           L_80800FE0
    // 0x80800F4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE0;
    // 0x80800F4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F50:
    // 0x80800F50: addiu       $a0, $zero, 0x178
    ctx->r4 = ADD32(0, 0X178);
    // 0x80800F54: jal         0x801084B0
    // 0x80800F58: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_801084B0(rdram, ctx);
        goto after_11;
    // 0x80800F58: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_11:
    // 0x80800F5C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80800F60: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80800F64: b           L_80800FDC
    // 0x80800F68: sw          $t0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r8;
        goto L_80800FDC;
    // 0x80800F68: sw          $t0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r8;
L_80800F6C:
    // 0x80800F6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F70: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x80800F74: jal         0x80800C9C
    // 0x80800F78: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_80800C9C_chclinker(rdram, ctx);
        goto after_12;
    // 0x80800F78: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_12:
    // 0x80800F7C: b           L_80800FE4
    // 0x80800F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800FE4;
    // 0x80800F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F84:
    // 0x80800F84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F88: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    // 0x80800F8C: jal         0x80800D24
    // 0x80800F90: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    func_80800D24_chclinker(rdram, ctx);
        goto after_13;
    // 0x80800F90: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    after_13:
    // 0x80800F94: b           L_80800FE0
    // 0x80800F98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE0;
    // 0x80800F98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F9C:
    // 0x80800F9C: jal         0x808008E0
    // 0x80800FA0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808008E0_chclinker(rdram, ctx);
        goto after_14;
    // 0x80800FA0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_14:
    // 0x80800FA4: b           L_80800FE0
    // 0x80800FA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE0;
    // 0x80800FA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FAC:
    // 0x80800FAC: jal         0x800D395C
    // 0x80800FB0: nop

    func_800D395C(rdram, ctx);
        goto after_15;
    // 0x80800FB0: nop

    after_15:
    // 0x80800FB4: bne         $v0, $zero, L_80800FC4
    if (ctx->r2 != 0) {
        // 0x80800FB8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800FC4;
    }
    // 0x80800FB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800FBC: b           L_80800FE0
    // 0x80800FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FE0;
    // 0x80800FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800FC4:
    // 0x80800FC4: jal         0x808008E0
    // 0x80800FC8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808008E0_chclinker(rdram, ctx);
        goto after_16;
    // 0x80800FC8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_16:
    // 0x80800FCC: b           L_80800FE0
    // 0x80800FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800FE0;
    // 0x80800FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FD4:
    // 0x80800FD4: b           L_80800FE0
    // 0x80800FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FE0;
    // 0x80800FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800FDC:
    // 0x80800FDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800FE0:
    // 0x80800FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800FE4:
    // 0x80800FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FE8: jr          $ra
    // 0x80800FEC: nop

    return;
    // 0x80800FEC: nop

;}
RECOMP_FUNC void bawobble_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800174: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800178: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x8080017C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800180: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
    // 0x80800184: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
    // 0x80800188: jr          $ra
    // 0x8080018C: swc1        $f14, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x8080018C: swc1        $f14, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void _subaddierouteDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F90: syscall     818
    recomp_syscall_handler(rdram, ctx, 0x80089F90);
    return;
    // 0x80089F94: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800868_gccubeDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800868: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080086C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800870: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800874: jal         0x800CE308
    // 0x80800878: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800CE308(rdram, ctx);
        goto after_0;
    // 0x80800878: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800884: jr          $ra
    // 0x80800888: nop

    return;
    // 0x80800888: nop

;}
RECOMP_FUNC void func_808005E4_chdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808005F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005F4: jal         0x80100094
    // 0x808005F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808005F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005FC: lh          $t6, 0x38($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X38);
    // 0x80800600: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800604: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800608: beql        $t6, $zero, L_80800690
    if (ctx->r14 == 0) {
        // 0x8080060C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800690;
    }
    goto skip_0;
    // 0x8080060C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800610: beq         $v1, $zero, L_80800624
    if (ctx->r3 == 0) {
        // 0x80800614: nop
    
            goto L_80800624;
    }
    // 0x80800614: nop

    // 0x80800618: lh          $t7, 0x34($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X34);
    // 0x8080061C: bnel        $t7, $zero, L_8080063C
    if (ctx->r15 != 0) {
        // 0x80800620: lh          $a0, 0x38($a1)
        ctx->r4 = MEM_H(ctx->r5, 0X38);
            goto L_8080063C;
    }
    goto skip_1;
    // 0x80800620: lh          $a0, 0x38($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X38);
    skip_1:
L_80800624:
    // 0x80800624: bnel        $v1, $zero, L_80800690
    if (ctx->r3 != 0) {
        // 0x80800628: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800690;
    }
    goto skip_2;
    // 0x80800628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8080062C: lh          $t8, 0x36($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X36);
    // 0x80800630: beql        $t8, $zero, L_80800690
    if (ctx->r24 == 0) {
        // 0x80800634: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800690;
    }
    goto skip_3;
    // 0x80800634: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80800638: lh          $a0, 0x38($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X38);
L_8080063C:
    // 0x8080063C: jal         0x800C4B7C
    // 0x80800640: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800C4B7C(rdram, ctx);
        goto after_1;
    // 0x80800640: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800644: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800648: jal         0x800C4B70
    // 0x8080064C: lh          $a0, 0x3A($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X3A);
    func_800C4B70(rdram, ctx);
        goto after_2;
    // 0x8080064C: lh          $a0, 0x3A($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X3A);
    after_2:
    // 0x80800650: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800654: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800658: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080065C: lh          $t1, 0x3C($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X3C);
    // 0x80800660: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80800664: nop

    // 0x80800668: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080066C: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800670: jal         0x800C4B64
    // 0x80800674: nop

    func_800C4B64(rdram, ctx);
        goto after_3;
    // 0x80800674: nop

    after_3:
    // 0x80800678: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080067C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1148, 0X15B0) << 16);
    // 0x80800680: addiu       $a2, $a2, 0x15B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1148, 0X15B0));
    // 0x80800684: jal         0x80089D18
    // 0x80800688: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800688: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_4:
    // 0x8080068C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800690:
    // 0x80800690: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800694: jr          $ra
    // 0x80800698: nop

    return;
    // 0x80800698: nop

;}
RECOMP_FUNC void func_808016B0_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808016B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808016B8: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808016BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808016C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016C4: beq         $a1, $at, L_80801758
    if (ctx->r5 == ctx->r1) {
        // 0x808016C8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80801758;
    }
    // 0x808016C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808016CC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808016D0: beq         $a1, $at, L_80801700
    if (ctx->r5 == ctx->r1) {
        // 0x808016D4: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_80801700;
    }
    // 0x808016D4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808016D8: beq         $a1, $at, L_808016F0
    if (ctx->r5 == ctx->r1) {
        // 0x808016DC: addiu       $at, $zero, 0x49
        ctx->r1 = ADD32(0, 0X49);
            goto L_808016F0;
    }
    // 0x808016DC: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x808016E0: beq         $a1, $at, L_80801730
    if (ctx->r5 == ctx->r1) {
        // 0x808016E4: addiu       $a0, $zero, 0x6E8
        ctx->r4 = ADD32(0, 0X6E8);
            goto L_80801730;
    }
    // 0x808016E4: addiu       $a0, $zero, 0x6E8
    ctx->r4 = ADD32(0, 0X6E8);
    // 0x808016E8: b           L_80801774
    // 0x808016EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801774;
    // 0x808016EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808016F0:
    // 0x808016F0: jal         0x80090708
    // 0x808016F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_0;
    // 0x808016F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x808016F8: b           L_80801774
    // 0x808016FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801774;
    // 0x808016FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801700:
    // 0x80801700: lbu         $t6, 0x74($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X74);
    // 0x80801704: addiu       $at, $zero, 0x180E
    ctx->r1 = ADD32(0, 0X180E);
    // 0x80801708: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080170C: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80801710: sb          $t7, 0x74($a2)
    MEM_B(0X74, ctx->r6) = ctx->r15;
    // 0x80801714: lh          $t8, 0x20($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X20);
    // 0x80801718: bnel        $t8, $at, L_80801774
    if (ctx->r24 != ctx->r1) {
        // 0x8080171C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801774;
    }
    goto skip_0;
    // 0x8080171C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80801720: jal         0x80801494
    // 0x80801724: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801494_chlakemonster(rdram, ctx);
        goto after_1;
    // 0x80801724: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80801728: b           L_80801774
    // 0x8080172C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801774;
    // 0x8080172C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801730:
    // 0x80801730: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801734: jal         0x800DA9E4
    // 0x80801738: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DA9E4(rdram, ctx);
        goto after_2;
    // 0x80801738: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x8080173C: beq         $v0, $zero, L_80801770
    if (ctx->r2 == 0) {
        // 0x80801740: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80801770;
    }
    // 0x80801740: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801744: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801748: jal         0x80801494
    // 0x8080174C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801494_chlakemonster(rdram, ctx);
        goto after_3;
    // 0x8080174C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80801750: b           L_80801774
    // 0x80801754: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801774;
    // 0x80801754: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801758:
    // 0x80801758: jal         0x80800838
    // 0x8080175C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80800838_chlakemonster(rdram, ctx);
        goto after_4;
    // 0x8080175C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80801760: b           L_80801774
    // 0x80801764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801774;
    // 0x80801764: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801768: b           L_80801774
    // 0x8080176C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801774;
    // 0x8080176C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801770:
    // 0x80801770: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801774:
    // 0x80801774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080177C: jr          $ra
    // 0x80801780: nop

    return;
    // 0x80801780: nop

;}
RECOMP_FUNC void _gccubeDll_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C88: syscall     655
    recomp_syscall_handler(rdram, ctx, 0x80087C88);
    return;
    // 0x80087C8C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _bamotor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085490: syscall     163
    recomp_syscall_handler(rdram, ctx, 0x80085490);
    return;
    // 0x80085494: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chfactoryflypad_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864A0: syscall     328
    recomp_syscall_handler(rdram, ctx, 0x800864A0);
    return;
    // 0x800864A4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void glgamestore_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B8: jal         0x80800030
    // 0x808001BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800030_glgamestore(rdram, ctx);
        goto after_0;
    // 0x808001BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C8: jal         0x8080013C
    // 0x808001CC: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_8080013C_glgamestore(rdram, ctx);
        goto after_1;
    // 0x808001CC: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_1:
    // 0x808001D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void _bsbfly_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082988: syscall     22
    recomp_syscall_handler(rdram, ctx, 0x80082988);
    return;
    // 0x8008298C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
