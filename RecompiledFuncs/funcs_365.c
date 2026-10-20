#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800000_chufoextdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800008: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: bne         $a1, $at, L_808000D4
    if (ctx->r5 != ctx->r1) {
        // 0x80800018: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_808000D4;
    }
    // 0x80800018: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8080001C: lw          $t6, 0x24($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X24);
    // 0x80800020: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80800024: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80800028: beql        $t7, $zero, L_8080003C
    if (ctx->r15 == 0) {
        // 0x8080002C: lhu         $a0, 0x1A($v0)
        ctx->r4 = MEM_HU(ctx->r2, 0X1A);
            goto L_8080003C;
    }
    goto skip_0;
    // 0x8080002C: lhu         $a0, 0x1A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X1A);
    skip_0:
    // 0x80800030: b           L_808000D8
    // 0x80800034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000D8;
    // 0x80800034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800038: lhu         $a0, 0x1A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X1A);
L_8080003C:
    // 0x8080003C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800040: srl         $t8, $a0, 5
    ctx->r24 = S32(U32(ctx->r4) >> 5);
    // 0x80800044: jal         0x800F52B8
    // 0x80800048: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800F52B8(rdram, ctx);
        goto after_0;
    // 0x80800048: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x8080004C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80800050: beq         $v0, $at, L_80800060
    if (ctx->r2 == ctx->r1) {
        // 0x80800054: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80800060;
    }
    // 0x80800054: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800058: b           L_808000D8
    // 0x8080005C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000D8;
    // 0x8080005C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800060:
    // 0x80800060: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800064: jal         0x800EE7F8
    // 0x80800068: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800068: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080006C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800070: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800074: jal         0x800EF1B8
    // 0x80800078: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x80800078: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    after_2:
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800084: jal         0x80086670
    // 0x80800088: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800088: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_3:
    // 0x8080008C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2044, 0X114) << 16);
    // 0x80800090: addiu       $t9, $t9, 0x114
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2044, 0X114));
    // 0x80800094: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800098: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080009C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808000A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808000A4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808000A8: jal         0x800BBCB8
    // 0x808000AC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x808000AC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_4:
    // 0x808000B0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2044, 0X100) << 16);
    // 0x808000B4: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2044, 0X100));
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: jal         0x80089D18
    // 0x808000C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x808000C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x808000C4: jal         0x800DA544
    // 0x808000C8: addiu       $a0, $zero, 0x3AB
    ctx->r4 = ADD32(0, 0X3AB);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x808000C8: addiu       $a0, $zero, 0x3AB
    ctx->r4 = ADD32(0, 0X3AB);
    after_6:
    // 0x808000CC: b           L_808000D8
    // 0x808000D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000D8;
    // 0x808000D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000D4:
    // 0x808000D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000D8:
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void changlerbossbubble_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1340, 0X5D0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x5D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1340, 0X5D0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x5D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1340, 0X5D0));
;}
RECOMP_FUNC void _chaliendad_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086600: syscall     347
    recomp_syscall_handler(rdram, ctx, 0x80086600);
    return;
    // 0x80086604: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800BF710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF710: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BF714: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    // 0x800BF718: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x800BF71C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BF720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF724: beql        $t6, $zero, L_800BF738
    if (ctx->r14 == 0) {
        // 0x800BF728: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BF738;
    }
    goto skip_0;
    // 0x800BF728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BF72C: jal         0x80087F48
    // 0x800BF730: nop

    _gcmapsects_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x800BF730: nop

    after_0:
    // 0x800BF734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BF738:
    // 0x800BF738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BF73C: jr          $ra
    // 0x800BF740: nop

    return;
    // 0x800BF740: nop

;}
RECOMP_FUNC void func_80806744_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806744: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80806748: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080674C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80806750: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80806754: jal         0x800AA0C4
    // 0x80806758: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800AA0C4(rdram, ctx);
        goto after_0;
    // 0x80806758: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080675C: lui         $s0, 0x8081
    ctx->r16 = S32(RELOC_HI16(804, 0X8550) << 16);
    // 0x80806760: addiu       $s0, $s0, -0x7AB0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(804, 0X8550));
    // 0x80806764: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x80806768: addiu       $t6, $zero, 0x18F2
    ctx->r14 = ADD32(0, 0X18F2);
    // 0x8080676C: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x80806770: jal         0x800AA0D0
    // 0x80806774: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800AA0D0(rdram, ctx);
        goto after_1;
    // 0x80806774: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80806778: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8080677C: addiu       $t8, $zero, 0x27
    ctx->r24 = ADD32(0, 0X27);
    // 0x80806780: addiu       $t9, $zero, 0x18E4
    ctx->r25 = ADD32(0, 0X18E4);
    // 0x80806784: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80806788: bnel        $v0, $t7, L_8080679C
    if (ctx->r2 != ctx->r15) {
        // 0x8080678C: sh          $v1, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r3;
            goto L_8080679C;
    }
    goto skip_0;
    // 0x8080678C: sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
    skip_0:
    // 0x80806790: b           L_8080679C
    // 0x80806794: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
        goto L_8080679C;
    // 0x80806794: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x80806798: sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
L_8080679C:
    // 0x8080679C: jal         0x800AA120
    // 0x808067A0: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    func_800AA120(rdram, ctx);
        goto after_2;
    // 0x808067A0: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    after_2:
    // 0x808067A4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808067A8: jal         0x80088158
    // 0x808067AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808067AC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_3:
    // 0x808067B0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808067B4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808067B8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808067BC: subu        $t1, $t0, $v0
    ctx->r9 = SUB32(ctx->r8, ctx->r2);
    // 0x808067C0: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
    // 0x808067C4: jal         0x80803F90
    // 0x808067C8: lw          $a0, 0x50($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X50);
    func_80803F90_chgameselect(rdram, ctx);
        goto after_4;
    // 0x808067C8: lw          $a0, 0x50($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X50);
    after_4:
    // 0x808067CC: lw          $a0, 0x50($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X50);
    // 0x808067D0: jal         0x800E6A58
    // 0x808067D4: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    func_800E6A58(rdram, ctx);
        goto after_5;
    // 0x808067D4: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_5:
    // 0x808067D8: lw          $a0, 0x2C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X2C);
    // 0x808067DC: jal         0x80802730
    // 0x808067E0: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    func_80802730_chgameselect(rdram, ctx);
        goto after_6;
    // 0x808067E0: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    after_6:
    // 0x808067E4: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x808067E8: sw          $t2, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r10;
    // 0x808067EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808067F0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808067F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808067F8: jr          $ra
    // 0x808067FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808067FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800F1AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1AFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F1B00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1B04: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F1B08: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F1B0C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800F1B10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F1B14: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800F1B18: nop

    // 0x800F1B1C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F1B20: jal         0x8002DCA0
    // 0x800F1B24: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800F1B24: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800F1B28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F1B2C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800F1B30: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F1B34: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800F1B38: jal         0x80013B70
    // 0x800F1B3C: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    func_80013B70(rdram, ctx);
        goto after_1;
    // 0x800F1B3C: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    after_1:
    // 0x800F1B40: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800F1B44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800F1B48: swc1        $f0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f0.u32l;
    // 0x800F1B4C: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F1B50: jal         0x80013B7C
    // 0x800F1B54: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    func_80013B7C(rdram, ctx);
        goto after_2;
    // 0x800F1B54: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    after_2:
    // 0x800F1B58: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800F1B5C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800F1B60: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x800F1B64: swc1        $f8, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f8.u32l;
    // 0x800F1B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1B6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F1B70: jr          $ra
    // 0x800F1B74: nop

    return;
    // 0x800F1B74: nop

;}
RECOMP_FUNC void func_808004D4_chminelight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808004D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808004DC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808004E0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x808004E4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808004E8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808004EC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808004F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004F4: jal         0x80100094
    // 0x808004F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808004F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808004FC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1744, 0X688) << 16);
    // 0x80800500: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(1744, 0X6AC) << 16);
    // 0x80800504: addiu       $s3, $s3, 0x6AC
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1744, 0X6AC));
    // 0x80800508: addiu       $s1, $s1, 0x688
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1744, 0X688));
    // 0x8080050C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800510: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
L_80800514:
    // 0x80800514: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800518: jal         0x800C8900
    // 0x8080051C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800C8900(rdram, ctx);
        goto after_1;
    // 0x8080051C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x80800520: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80800524: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80800528: addiu       $s0, $s0, 0x3
    ctx->r16 = ADD32(ctx->r16, 0X3);
    // 0x8080052C: sb          $t6, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r14;
    // 0x80800530: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80800534: sb          $t7, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r15;
    // 0x80800538: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8080053C: bne         $s1, $s3, L_80800514
    if (ctx->r17 != ctx->r19) {
        // 0x80800540: sb          $t8, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r24;
            goto L_80800514;
    }
    // 0x80800540: sb          $t8, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r24;
    // 0x80800544: jal         0x800DA298
    // 0x80800548: addiu       $a0, $zero, 0x9E0
    ctx->r4 = ADD32(0, 0X9E0);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800548: addiu       $a0, $zero, 0x9E0
    ctx->r4 = ADD32(0, 0X9E0);
    after_2:
    // 0x8080054C: beql        $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x80800550: lhu         $t4, 0x72($s4)
        ctx->r12 = MEM_HU(ctx->r20, 0X72);
            goto L_808005B0;
    }
    goto skip_0;
    // 0x80800550: lhu         $t4, 0x72($s4)
    ctx->r12 = MEM_HU(ctx->r20, 0X72);
    skip_0:
    // 0x80800554: lhu         $t9, 0x72($s4)
    ctx->r25 = MEM_HU(ctx->r20, 0X72);
    // 0x80800558: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080055C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80800560: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800564: beq         $t0, $at, L_80800604
    if (ctx->r8 == ctx->r1) {
        // 0x80800568: nop
    
            goto L_80800604;
    }
    // 0x80800568: nop

    // 0x8080056C: lbu         $t1, 0x72($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X72);
    // 0x80800570: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800574: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800578: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x8080057C: ori         $t3, $t2, 0x8
    ctx->r11 = ctx->r10 | 0X8;
    // 0x80800580: sb          $t3, 0x72($s4)
    MEM_B(0X72, ctx->r20) = ctx->r11;
    // 0x80800584: jal         0x80088840
    // 0x80800588: swc1        $f4, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->f4.u32l;
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x80800588: swc1        $f4, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->f4.u32l;
    after_3:
    // 0x8080058C: bne         $v0, $zero, L_808005A0
    if (ctx->r2 != 0) {
        // 0x80800590: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808005A0;
    }
    // 0x80800590: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800594: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800598: b           L_80800604
    // 0x8080059C: swc1        $f6, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f6.u32l;
        goto L_80800604;
    // 0x8080059C: swc1        $f6, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f6.u32l;
L_808005A0:
    // 0x808005A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808005A4: b           L_80800604
    // 0x808005A8: swc1        $f8, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f8.u32l;
        goto L_80800604;
    // 0x808005A8: swc1        $f8, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f8.u32l;
    // 0x808005AC: lhu         $t4, 0x72($s4)
    ctx->r12 = MEM_HU(ctx->r20, 0X72);
L_808005B0:
    // 0x808005B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005B4: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x808005B8: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x808005BC: beq         $t5, $at, L_80800604
    if (ctx->r13 == ctx->r1) {
        // 0x808005C0: nop
    
            goto L_80800604;
    }
    // 0x808005C0: nop

    // 0x808005C4: lbu         $t6, 0x72($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X72);
    // 0x808005C8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808005CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808005D0: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x808005D4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808005D8: sb          $t8, 0x72($s4)
    MEM_B(0X72, ctx->r20) = ctx->r24;
    // 0x808005DC: jal         0x80088840
    // 0x808005E0: swc1        $f10, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->f10.u32l;
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x808005E0: swc1        $f10, 0x54($s4)
    MEM_W(0X54, ctx->r20) = ctx->f10.u32l;
    after_4:
    // 0x808005E4: bne         $v0, $zero, L_808005F8
    if (ctx->r2 != 0) {
        // 0x808005E8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808005F8;
    }
    // 0x808005E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808005F0: b           L_80800604
    // 0x808005F4: swc1        $f16, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f16.u32l;
        goto L_80800604;
    // 0x808005F4: swc1        $f16, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f16.u32l;
L_808005F8:
    // 0x808005F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808005FC: nop

    // 0x80800600: swc1        $f18, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->f18.u32l;
L_80800604:
    // 0x80800604: jal         0x8080011C
    // 0x80800608: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8080011C_chminelight(rdram, ctx);
        goto after_5;
    // 0x80800608: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x8080060C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800610: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800614: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800618: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080061C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800620: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800624: jr          $ra
    // 0x80800628: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800628: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _sucoaster_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A130: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A130);
    return;
    // 0x8008A134: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80801320_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801320: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801324: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80801328: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080132C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80801330: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80801334: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80801338: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8080133C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80801340: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80801344: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80801348: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8080134C: jal         0x8010262C
    // 0x80801350: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_8010262C(rdram, ctx);
        goto after_0;
    // 0x80801350: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80801354: beq         $v0, $zero, L_80801420
    if (ctx->r2 == 0) {
        // 0x80801358: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_80801420;
    }
    // 0x80801358: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8080135C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801360: jal         0x80100094
    // 0x80801364: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801364: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801368: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080136C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80801370: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80801374: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801378: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080137C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
L_80801380:
    // 0x80801380: jal         0x808011A0
    // 0x80801384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808011A0_chstatueboss(rdram, ctx);
        goto after_2;
    // 0x80801384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801388: lwc1        $f4, 0x70($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8080138C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80801390: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801394: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80801398: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080139C: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x808013A0: jal         0x800E0AFC
    // 0x808013A4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_3;
    // 0x808013A4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x808013A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808013AC: slti        $at, $s0, 0x5
    ctx->r1 = SIGNED(ctx->r16) < 0X5 ? 1 : 0;
    // 0x808013B0: bne         $at, $zero, L_80801380
    if (ctx->r1 != 0) {
        // 0x808013B4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80801380;
    }
    // 0x808013B4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808013B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808013BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808013C0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808013C4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x808013C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808013CC: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    // 0x808013D0: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x808013D4: jal         0x800E0B8C
    // 0x808013D8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800E0B8C(rdram, ctx);
        goto after_4;
    // 0x808013D8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x808013DC: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1312, 0X265C) << 16);
    // 0x808013E0: addiu       $s1, $s1, 0x265C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1312, 0X265C));
    // 0x808013E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808013E8: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x808013EC: addiu       $s0, $zero, 0x48
    ctx->r16 = ADD32(0, 0X48);
L_808013F0:
    // 0x808013F0: lwc1        $f8, 0xA8($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XA8);
    // 0x808013F4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808013F8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808013FC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80801400: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80801404: lbu         $a1, 0x1($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1);
    // 0x80801408: jal         0x800E0C20
    // 0x8080140C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800E0C20(rdram, ctx);
        goto after_5;
    // 0x8080140C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80801410: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80801414: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80801418: bne         $s2, $s0, L_808013F0
    if (ctx->r18 != ctx->r16) {
        // 0x8080141C: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_808013F0;
    }
    // 0x8080141C: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
L_80801420:
    // 0x80801420: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80801424: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80801428: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8080142C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80801430: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80801434: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80801438: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8080143C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80801440: jr          $ra
    // 0x80801444: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80801444: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void chboilerboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(932, 0X2C0C) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2C0C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2C0C));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2C0C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(932, 0X2C0C));
;}
RECOMP_FUNC void func_80012598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012598: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001259C: jr          $ra
    // 0x800125A0: addiu       $v0, $v0, 0x5788
    ctx->r2 = ADD32(ctx->r2, 0X5788);
    return;
    // 0x800125A0: addiu       $v0, $v0, 0x5788
    ctx->r2 = ADD32(ctx->r2, 0X5788);
    // 0x800125A4: nop

    // 0x800125A8: nop

    // 0x800125AC: nop

;}
RECOMP_FUNC void _sukickball_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089AE0: syscall     802
    recomp_syscall_handler(rdram, ctx, 0x80089AE0);
    return;
    // 0x80089AE4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void basub_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B60: beq         $a1, $zero, L_80800BA8
    if (ctx->r5 == 0) {
        // 0x80800B64: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(616, 0XC00) << 16);
            goto L_80800BA8;
    }
    // 0x80800B64: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(616, 0XC00) << 16);
    // 0x80800B68: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(616, 0XBF4) << 16);
    // 0x80800B6C: lwc1        $f4, 0xBF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(616, 0XBF4));
    // 0x80800B70: lw          $t6, 0x130($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X130);
    // 0x80800B74: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80800B78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(616, 0XBF8) << 16);
    // 0x80800B7C: swc1        $f4, 0x68($t6)
    MEM_W(0X68, ctx->r14) = ctx->f4.u32l;
    // 0x80800B80: lw          $t8, 0x130($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X130);
    // 0x80800B84: sb          $t7, 0x5F($t8)
    MEM_B(0X5F, ctx->r24) = ctx->r15;
    // 0x80800B88: lw          $t9, 0x130($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X130);
    // 0x80800B8C: lwc1        $f6, 0xBF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(616, 0XBF8));
    // 0x80800B90: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(616, 0XBFC) << 16);
    // 0x80800B94: swc1        $f6, 0x60($t9)
    MEM_W(0X60, ctx->r25) = ctx->f6.u32l;
    // 0x80800B98: lw          $t0, 0x130($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X130);
    // 0x80800B9C: lwc1        $f8, 0xBFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(616, 0XBFC));
    // 0x80800BA0: jr          $ra
    // 0x80800BA4: swc1        $f8, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f8.u32l;
    return;
    // 0x80800BA4: swc1        $f8, 0x64($t0)
    MEM_W(0X64, ctx->r8) = ctx->f8.u32l;
L_80800BA8:
    // 0x80800BA8: lwc1        $f10, 0xC00($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(616, 0XC00));
    // 0x80800BAC: lw          $t1, 0x130($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X130);
    // 0x80800BB0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80800BB4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(616, 0XC04) << 16);
    // 0x80800BB8: swc1        $f10, 0x68($t1)
    MEM_W(0X68, ctx->r9) = ctx->f10.u32l;
    // 0x80800BBC: lw          $t3, 0x130($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X130);
    // 0x80800BC0: sb          $t2, 0x5F($t3)
    MEM_B(0X5F, ctx->r11) = ctx->r10;
    // 0x80800BC4: lw          $t4, 0x130($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X130);
    // 0x80800BC8: lwc1        $f16, 0xC04($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(616, 0XC04));
    // 0x80800BCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(616, 0XC08) << 16);
    // 0x80800BD0: swc1        $f16, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f16.u32l;
    // 0x80800BD4: lw          $t5, 0x130($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X130);
    // 0x80800BD8: lwc1        $f18, 0xC08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(616, 0XC08));
    // 0x80800BDC: swc1        $f18, 0x64($t5)
    MEM_W(0X64, ctx->r13) = ctx->f18.u32l;
    // 0x80800BE0: jr          $ra
    // 0x80800BE4: nop

    return;
    // 0x80800BE4: nop

    // 0x80800BE8: nop

    // 0x80800BEC: nop

;}
RECOMP_FUNC void _chghostdoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E70: syscall     251
    recomp_syscall_handler(rdram, ctx, 0x80085E70);
    return;
    // 0x80085E74: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _chvolcanobits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086400: syscall     322
    recomp_syscall_handler(rdram, ctx, 0x80086400);
    return;
    // 0x80086404: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800184_chstarspinnerctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800184: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800188: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080018C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800190: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800194: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800198: bne         $a1, $at, L_8080028C
    if (ctx->r5 != ctx->r1) {
        // 0x8080019C: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_8080028C;
    }
    // 0x8080019C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x808001A0: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    // 0x808001A4: jal         0x800DA298
    // 0x808001A8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808001A8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808001AC: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x808001B0: bnel        $a1, $zero, L_808001C8
    if (ctx->r5 != 0) {
        // 0x808001B4: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_808001C8;
    }
    goto skip_0;
    // 0x808001B4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    skip_0:
    // 0x808001B8: jal         0x80088848
    // 0x808001BC: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808001BC: nop

    after_1:
    // 0x808001C0: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x808001C4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
L_808001C8:
    // 0x808001C8: sltiu       $t6, $a1, 0x1
    ctx->r14 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x808001CC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x808001D0: jal         0x800BF744
    // 0x808001D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800BF744(rdram, ctx);
        goto after_2;
    // 0x808001D4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x808001D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808001DC: jal         0x800BF744
    // 0x808001E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800BF744(rdram, ctx);
        goto after_3;
    // 0x808001E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x80100094
    // 0x808001EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808001EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808001F0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F8: jal         0x80100094
    // 0x808001FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x808001FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800200: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800204: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800208: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8080020C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800210: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80800214: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800218: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080021C: jal         0x800F10B4
    // 0x80800220: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800220: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x80800224: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800228: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x8080022C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800230: bne         $t8, $zero, L_80800258
    if (ctx->r24 != 0) {
        // 0x80800234: nop
    
            goto L_80800258;
    }
    // 0x80800234: nop

    // 0x80800238: jal         0x808002B4
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002B4_chstarspinnerctrl(rdram, ctx);
        goto after_7;
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800240: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(960, 0X900) << 16);
    // 0x80800244: addiu       $a0, $a0, 0x900
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(960, 0X900));
    // 0x80800248: jal         0x800C8F08
    // 0x8080024C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C8F08(rdram, ctx);
        goto after_8;
    // 0x8080024C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800250: b           L_80800260
    // 0x80800254: nop

        goto L_80800260;
    // 0x80800254: nop

L_80800258:
    // 0x80800258: jal         0x800DA544
    // 0x8080025C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA544(rdram, ctx);
        goto after_9;
    // 0x8080025C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
L_80800260:
    // 0x80800260: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(960, 0X918) << 16);
    // 0x80800264: addiu       $a3, $a3, 0x918
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(960, 0X918));
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800270: jal         0x80086050
    // 0x80800274: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    _chpowerhut_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80800274: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_10:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x80103110
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_11;
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800284: b           L_808002A0
    // 0x80800288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002A0;
    // 0x80800288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080028C:
    // 0x8080028C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(960, 0X918) << 16);
    // 0x80800290: addiu       $a3, $a3, 0x918
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(960, 0X918));
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x80086050
    // 0x8080029C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    _chpowerhut_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x8080029C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_12:
L_808002A0:
    // 0x808002A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808002AC: jr          $ra
    // 0x808002B0: nop

    return;
    // 0x808002B0: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E18: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E18);
    return;
    // 0x80083E1C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800674_chfactoryprop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800674_chfactoryprop");
    // 0x80800674: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800678: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080067C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800680: jal         0x800DB9B0
    // 0x80800684: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x80800684: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800688: bnel        $v0, $zero, L_80800714
    if (ctx->r2 != 0) {
        // 0x8080068C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800714;
    }
    goto skip_0;
    // 0x8080068C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80800690: jal         0x800F54E4
    // 0x80800694: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800694: nop

    after_1:
    // 0x80800698: jal         0x800F55FC
    // 0x8080069C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F55FC(rdram, ctx);
        goto after_2;
    // 0x8080069C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808006A0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808006A4: jal         0x8008FE68
    // 0x808006A8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    func_8008FE68(rdram, ctx);
        goto after_3;
    // 0x808006A8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_3:
    // 0x808006AC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x808006B0: lui         $at, 0x3000
    ctx->r1 = S32(0X3000 << 16);
    // 0x808006B4: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x808006B8: bgez        $t6, L_808006D0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808006BC: and         $t7, $v1, $at
        ctx->r15 = ctx->r3 & ctx->r1;
            goto L_808006D0;
    }
    // 0x808006BC: and         $t7, $v1, $at
    ctx->r15 = ctx->r3 & ctx->r1;
    // 0x808006C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1124, 0XC04) << 16);
    // 0x808006C4: lwc1        $f4, 0xC04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1124, 0XC04));
    // 0x808006C8: b           L_80800724
    // 0x808006CC: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
        goto L_80800724;
    // 0x808006CC: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
L_808006D0:
    // 0x808006D0: beq         $t7, $zero, L_80800704
    if (ctx->r15 == 0) {
        // 0x808006D4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800704;
    }
    // 0x808006D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808006D8: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x808006DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808006E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1124, 0XC08) << 16);
    // 0x808006E4: lwc1        $f6, 0xC08($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1124, 0XC08));
    // 0x808006E8: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808006EC: lui         $a2, 0xC516
    ctx->r6 = S32(0XC516 << 16);
    // 0x808006F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808006F4: jal         0x800F10B4
    // 0x808006F8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x808006F8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x808006FC: b           L_80800724
    // 0x80800700: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
        goto L_80800724;
    // 0x80800700: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_80800704:
    // 0x80800704: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800708: b           L_80800724
    // 0x8080070C: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
        goto L_80800724;
    // 0x8080070C: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    // 0x80800710: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800714:
    // 0x80800714: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800718: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080071C: jal         0x800E3980
    // 0x80800720: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    func_800E3980(rdram, ctx);
        goto after_5;
    // 0x80800720: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    after_5:
L_80800724:
    // 0x80800724: jal         0x800D8FF8
    // 0x80800728: nop

    func_800D8FF8(rdram, ctx);
        goto after_6;
    // 0x80800728: nop

    after_6:
    // 0x8080072C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800730: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800734: jal         0x800F15F8
    // 0x80800738: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    func_800F15F8(rdram, ctx);
        goto after_7;
    // 0x80800738: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    after_7:
    // 0x8080073C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800740: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800744: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800748: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080074C: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    // 0x80800750: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800754: lui         $a3, 0x46FF
    ctx->r7 = S32(0X46FF << 16);
    // 0x80800758: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8080075C: nop

    // 0x80800760: bc1f        L_80800790
    if (!c1cs) {
        // 0x80800764: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1124, 0XC0C) << 16);
            goto L_80800790;
    }
    // 0x80800764: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1124, 0XC0C) << 16);
    // 0x80800768: lwc1        $f4, 0xC0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1124, 0XC0C));
    // 0x8080076C: lui         $a3, 0x46FF
    ctx->r7 = S32(0X46FF << 16);
    // 0x80800770: ori         $a3, $a3, 0xFE00
    ctx->r7 = ctx->r7 | 0XFE00;
    // 0x80800774: lui         $a2, 0xC5FA
    ctx->r6 = S32(0XC5FA << 16);
    // 0x80800778: jal         0x800F10B4
    // 0x8080077C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x8080077C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80800780: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800784: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80800788: b           L_808007B0
    // 0x8080078C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
        goto L_808007B0;
    // 0x8080078C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_80800790:
    // 0x80800790: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800794: ori         $a3, $a3, 0xFE00
    ctx->r7 = ctx->r7 | 0XFE00;
    // 0x80800798: jal         0x800F10B4
    // 0x8080079C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x8080079C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x808007A0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808007A4: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x808007A8: nop

    // 0x808007AC: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
L_808007B0:
    // 0x808007B0: lbu         $t2, 0x5F($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X5F);
    // 0x808007B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007B8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808007BC: bne         $t2, $zero, L_808007D0
    if (ctx->r10 != 0) {
        // 0x808007C0: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1124, 0XD08) << 16);
            goto L_808007D0;
    }
    // 0x808007C0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1124, 0XD08) << 16);
    // 0x808007C4: jal         0x800C4350
    // 0x808007C8: addiu       $a2, $a2, 0xD08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1124, 0XD08));
    func_800C4350(rdram, ctx);
        goto after_10;
    // 0x808007C8: addiu       $a2, $a2, 0xD08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1124, 0XD08));
    after_10:
    // 0x808007CC: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
L_808007D0:
    // 0x808007D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007D8: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808007DC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808007E0: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x808007E4: addiu       $t3, $s0, 0x4
    ctx->r11 = ADD32(ctx->r16, 0X4);
    // 0x808007E8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x808007EC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808007F0: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    // 0x808007F4: jal         0x800F12D4
    // 0x808007F8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F12D4(rdram, ctx);
        goto after_11;
    // 0x808007F8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_11:
    // 0x808007FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800800: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800804: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80800808: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080080C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800810: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800814: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800818: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    // 0x8080081C: jal         0x800F12D4
    // 0x80800820: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F12D4(rdram, ctx);
        goto after_12;
    // 0x80800820: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x80800824: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80800828: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080082C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800830: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80800834: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800838: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080083C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800840: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800844: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80800848: nop

    // 0x8080084C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80800850: jal         0x800C31DC
    // 0x80800854: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C31DC(rdram, ctx);
        goto after_13;
    // 0x80800854: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_13:
    // 0x80800858: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x8080085C: jal         0x800C3058
    // 0x80800860: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800C3058(rdram, ctx);
        goto after_14;
    // 0x80800860: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_14:
    // 0x80800864: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80800868: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080086C: jal         0x800C4350
    // 0x80800870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800C4350(rdram, ctx);
        goto after_15;
    // 0x80800870: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x80800874: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1124, 0XC10) << 16);
    // 0x80800878: lwc1        $f4, 0xC10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1124, 0XC10));
    // 0x8080087C: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800880: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800884: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800888: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080088C: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    // 0x80800890: jal         0x800F10B4
    // 0x80800894: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x80800894: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x80800898: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080089C: jal         0x800D9154
    // 0x808008A0: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    func_800D9154(rdram, ctx);
        goto after_17;
    // 0x808008A0: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_17:
    // 0x808008A4: beq         $v0, $zero, L_80800974
    if (ctx->r2 == 0) {
        // 0x808008A8: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_80800974;
    }
    // 0x808008A8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808008AC: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808008B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008B4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x808008B8: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x808008BC: nop

    // 0x808008C0: bc1fl       L_80800978
    if (!c1cs) {
        // 0x808008C4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800978;
    }
    goto skip_1;
    // 0x808008C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808008C8: beql        $t7, $zero, L_80800978
    if (ctx->r15 == 0) {
        // 0x808008CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800978;
    }
    goto skip_2;
    // 0x808008CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808008D0: lbu         $t8, 0x18($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18);
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D8: bnel        $t8, $zero, L_808008F4
    if (ctx->r24 != 0) {
        // 0x808008DC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808008F4;
    }
    goto skip_3;
    // 0x808008DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_3:
    // 0x808008E0: jal         0x80089D10
    // 0x808008E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_18;
    // 0x808008E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_18:
    // 0x808008E8: sb          $v0, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r2;
    // 0x808008EC: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808008F0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_808008F4:
    // 0x808008F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008F8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808008FC: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80800900: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800904: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    // 0x80800908: jal         0x800F12D4
    // 0x8080090C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F12D4(rdram, ctx);
        goto after_19;
    // 0x8080090C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_19:
    // 0x80800910: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1124, 0XC14) << 16);
    // 0x80800914: lwc1        $f12, 0xC14($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1124, 0XC14));
    // 0x80800918: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1124, 0XC18) << 16);
    // 0x8080091C: lwc1        $f14, 0xC18($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1124, 0XC18));
    // 0x80800920: jal         0x800DC178
    // 0x80800924: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_20;
    // 0x80800924: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x80800928: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8080092C: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800930: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800934: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800938: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080093C: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x80800940: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800944: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80800948: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8080094C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80800950: jal         0x800C4B70
    // 0x80800954: nop

    func_800C4B70(rdram, ctx);
        goto after_21;
    // 0x80800954: nop

    after_21:
    // 0x80800958: jal         0x800C4B64
    // 0x8080095C: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    func_800C4B64(rdram, ctx);
        goto after_22;
    // 0x8080095C: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_22:
    // 0x80800960: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1124, 0XD14) << 16);
    // 0x80800964: addiu       $a2, $a2, 0xD14
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1124, 0XD14));
    // 0x80800968: lbu         $a0, 0x18($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X18);
    // 0x8080096C: jal         0x800C4350
    // 0x80800970: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800C4350(rdram, ctx);
        goto after_23;
    // 0x80800970: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_23:
L_80800974:
    // 0x80800974: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800978:
    // 0x80800978: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080097C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800980: jr          $ra
    // 0x80800984: nop

    return;
    // 0x80800984: nop

;}
RECOMP_FUNC void bstwirl_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800144: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800148: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080014C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800150: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800154: jal         0x8008CABC
    // 0x80800158: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800158: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x8080015C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800160: jal         0x8009C990
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_1;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800168: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080016C: jal         0x8009B9C0
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_2;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800174: lui         $a1, 0x3E38
    ctx->r5 = S32(0X3E38 << 16);
    // 0x80800178: ori         $a1, $a1, 0x51EC
    ctx->r5 = ctx->r5 | 0X51EC;
    // 0x8080017C: jal         0x8008B348
    // 0x80800180: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x80800180: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800184: beq         $v0, $zero, L_8080019C
    if (ctx->r2 == 0) {
        // 0x80800188: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080019C;
    }
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: addiu       $a1, $zero, 0x5A7
    ctx->r5 = ADD32(0, 0X5A7);
    // 0x80800190: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800194: jal         0x8009DF18
    // 0x80800198: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    func_8009DF18(rdram, ctx);
        goto after_4;
    // 0x80800198: addiu       $a3, $zero, 0x6590
    ctx->r7 = ADD32(0, 0X6590);
    after_4:
L_8080019C:
    // 0x8080019C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808001A0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808001A4: jal         0x8008B348
    // 0x808001A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x808001A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x808001AC: beq         $v0, $zero, L_808001BC
    if (ctx->r2 == 0) {
        // 0x808001B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001BC;
    }
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: jal         0x80084A28
    // 0x808001B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _badust_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x808001B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
L_808001BC:
    // 0x808001BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001C0: jal         0x8008B348
    // 0x808001C4: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x808001C4: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_7:
    // 0x808001C8: beq         $v0, $zero, L_808001D8
    if (ctx->r2 == 0) {
        // 0x808001CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001D8;
    }
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80084A28
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _badust_entrypoint_12(rdram, ctx);
        goto after_8;
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_808001D8:
    // 0x808001D8: lui         $a1, 0x3F4D
    ctx->r5 = S32(0X3F4D << 16);
    // 0x808001DC: ori         $a1, $a1, 0x14E4
    ctx->r5 = ctx->r5 | 0X14E4;
    // 0x808001E0: jal         0x8008B348
    // 0x808001E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x808001E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x808001E8: beq         $v0, $zero, L_80800200
    if (ctx->r2 == 0) {
        // 0x808001EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800200;
    }
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x8009B9B0
    // 0x808001F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x808001F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x808001F8: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x808001FC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800200:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: jal         0x80091A58
    // 0x80800208: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_11;
    // 0x80800208: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_11:
    // 0x8080020C: beq         $v0, $zero, L_80800220
    if (ctx->r2 == 0) {
        // 0x80800210: nop
    
            goto L_80800220;
    }
    // 0x80800210: nop

    // 0x80800214: jal         0x8009FE84
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getTypeOfJump(rdram, ctx);
        goto after_12;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080021C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80800220:
    // 0x80800220: jal         0x8008B2B4
    // 0x80800224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_13;
    // 0x80800224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_13:
    // 0x80800228: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(424, 0X2B0) << 16);
    // 0x8080022C: lwc1        $f4, 0x2B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(424, 0X2B0));
    // 0x80800230: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800234: nop

    // 0x80800238: bc1f        L_80800254
    if (!c1cs) {
        // 0x8080023C: nop
    
            goto L_80800254;
    }
    // 0x8080023C: nop

    // 0x80800240: jal         0x8008E078
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_14;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800248: bne         $v0, $zero, L_80800254
    if (ctx->r2 != 0) {
        // 0x8080024C: addiu       $t7, $zero, 0x2F
        ctx->r15 = ADD32(0, 0X2F);
            goto L_80800254;
    }
    // 0x8080024C: addiu       $t7, $zero, 0x2F
    ctx->r15 = ADD32(0, 0X2F);
    // 0x80800250: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80800254:
    // 0x80800254: jal         0x8008E35C
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_15;
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080025C: beq         $v0, $zero, L_8080026C
    if (ctx->r2 == 0) {
        // 0x80800260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080026C;
    }
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: addiu       $t8, $zero, 0x4C
    ctx->r24 = ADD32(0, 0X4C);
    // 0x80800268: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_8080026C:
    // 0x8080026C: jal         0x800A02DC
    // 0x80800270: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800A02DC(rdram, ctx);
        goto after_16;
    // 0x80800270: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_16:
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: jal         0x8009E5C8
    // 0x8080027C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_17;
    // 0x8080027C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x80800280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800284: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800288: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080028C: jr          $ra
    // 0x80800290: nop

    return;
    // 0x80800290: nop

;}
RECOMP_FUNC void func_80800F64_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F74: jal         0x8008CABC
    // 0x80800F78: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800F78: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800F7C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800F80: lbu         $v1, 0x164($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X164);
    // 0x80800F84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F8C: beq         $v1, $zero, L_80800FA4
    if (ctx->r3 == 0) {
        // 0x80800F90: nop
    
            goto L_80800FA4;
    }
    // 0x80800F90: nop

    // 0x80800F94: beq         $v1, $at, L_80801000
    if (ctx->r3 == ctx->r1) {
        // 0x80800F98: nop
    
            goto L_80801000;
    }
    // 0x80800F98: nop

    // 0x80800F9C: b           L_80801030
    // 0x80800FA0: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
        goto L_80801030;
    // 0x80800FA0: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
L_80800FA4:
    // 0x80800FA4: jal         0x8009BF5C
    // 0x80800FA8: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x80800FA8: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    after_1:
    // 0x80800FAC: lui         $a1, 0x3E95
    ctx->r5 = S32(0X3E95 << 16);
    // 0x80800FB0: ori         $a1, $a1, 0x4C98
    ctx->r5 = ctx->r5 | 0X4C98;
    // 0x80800FB4: jal         0x8008B348
    // 0x80800FB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_2;
    // 0x80800FB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800FBC: beql        $v0, $zero, L_80801030
    if (ctx->r2 == 0) {
        // 0x80800FC0: lui         $a1, 0x3F19
        ctx->r5 = S32(0X3F19 << 16);
            goto L_80801030;
    }
    goto skip_0;
    // 0x80800FC0: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    skip_0:
    // 0x80800FC4: jal         0x80085270
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800FCC: beql        $v0, $zero, L_80800FE0
    if (ctx->r2 == 0) {
        // 0x80800FD0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FE0;
    }
    goto skip_1;
    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800FD4: jal         0x800A0E64
    // 0x80800FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A0E64(rdram, ctx);
        goto after_4;
    // 0x80800FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FE0:
    // 0x80800FE0: jal         0x800852B8
    // 0x80800FE4: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    _baswim_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800FE4: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_5:
    // 0x80800FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FEC: jal         0x800852A8
    // 0x80800FF0: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    _baswim_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800FF0: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_6:
    // 0x80800FF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800FF8: b           L_8080102C
    // 0x80800FFC: sb          $t6, 0x164($s0)
    MEM_B(0X164, ctx->r16) = ctx->r14;
        goto L_8080102C;
    // 0x80800FFC: sb          $t6, 0x164($s0)
    MEM_B(0X164, ctx->r16) = ctx->r14;
L_80801000:
    // 0x80801000: jal         0x800852C0
    // 0x80801004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80801004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801008: jal         0x800852D0
    // 0x8080100C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_13(rdram, ctx);
        goto after_8;
    // 0x8080100C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801010: lui         $a1, 0x3F14
    ctx->r5 = S32(0X3F14 << 16);
    // 0x80801014: ori         $a1, $a1, 0x7AE1
    ctx->r5 = ctx->r5 | 0X7AE1;
    // 0x80801018: jal         0x8008B348
    // 0x8080101C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_9;
    // 0x8080101C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x80801020: beq         $v0, $zero, L_8080102C
    if (ctx->r2 == 0) {
        // 0x80801024: addiu       $t7, $zero, 0x2B
        ctx->r15 = ADD32(0, 0X2B);
            goto L_8080102C;
    }
    // 0x80801024: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x80801028: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8080102C:
    // 0x8080102C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
L_80801030:
    // 0x80801030: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801034: jal         0x8008B348
    // 0x80801038: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_10;
    // 0x80801038: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x8080103C: beq         $v0, $zero, L_80801050
    if (ctx->r2 == 0) {
        // 0x80801040: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801050;
    }
    // 0x80801040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801044: addiu       $a1, $zero, 0x3FD
    ctx->r5 = ADD32(0, 0X3FD);
    // 0x80801048: jal         0x8009DE38
    // 0x8080104C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_11;
    // 0x8080104C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_11:
L_80801050:
    // 0x80801050: jal         0x8008E35C
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_12;
    // 0x80801054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801058: bne         $v0, $zero, L_80801068
    if (ctx->r2 != 0) {
        // 0x8080105C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801068;
    }
    // 0x8080105C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801060: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80801064: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80801068:
    // 0x80801068: jal         0x8009E5C8
    // 0x8080106C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x8080106C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x80801070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801074: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801078: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080107C: jr          $ra
    // 0x80801080: nop

    return;
    // 0x80801080: nop

;}
RECOMP_FUNC void func_80803F24_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803F24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803F28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803F2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80803F30: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80803F34: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80803F38: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1732, 0X5374) << 16);
    // 0x80803F3C: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x80803F40: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80803F44: bgez        $t8, L_80803F64
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80803F48: addu        $a1, $a1, $t1
        ctx->r5 = ADD32(ctx->r5, ctx->r9);
            goto L_80803F64;
    }
    // 0x80803F48: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80803F4C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80803F50: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80803F54: lw          $a1, 0x5374($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(1732, 0X5374));
    // 0x80803F58: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x80803F5C: jal         0x800DBEFC
    // 0x80803F60: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800DBEFC(rdram, ctx);
        goto after_0;
    // 0x80803F60: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_0:
L_80803F64:
    // 0x80803F64: jal         0x80103014
    // 0x80803F68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80103014(rdram, ctx);
        goto after_1;
    // 0x80803F68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80803F6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803F70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803F74: jr          $ra
    // 0x80803F78: nop

    return;
    // 0x80803F78: nop

;}
RECOMP_FUNC void func_8080124C_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080124C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801250: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80801254: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80801258: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8080125C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80801260: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80801264: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801268: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080126C: jal         0x80100094
    // 0x80801270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801274: lh          $v1, 0x84($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X84);
    // 0x80801278: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8080127C: beq         $at, $zero, L_808012FC
    if (ctx->r1 == 0) {
        // 0x80801280: sll         $s1, $v1, 2
        ctx->r17 = S32(ctx->r3 << 2);
            goto L_808012FC;
    }
    // 0x80801280: sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3 << 2);
    // 0x80801284: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801288: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8080128C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80801290: addu        $s0, $v0, $s1
    ctx->r16 = ADD32(ctx->r2, ctx->r17);
L_80801294:
    // 0x80801294: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80801298: lwc1        $f12, 0x70($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8080129C: jal         0x800F20BC
    // 0x808012A0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800F20BC(rdram, ctx);
        goto after_1;
    // 0x808012A0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_1:
    // 0x808012A4: bne         $v0, $zero, L_808012EC
    if (ctx->r2 != 0) {
        // 0x808012A8: lui         $t6, 0x8080
        ctx->r14 = S32(RELOC_HI16(1312, 0X2630) << 16);
            goto L_808012EC;
    }
    // 0x808012A8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1312, 0X2630) << 16);
    // 0x808012AC: addiu       $t6, $t6, 0x2630
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1312, 0X2630));
    // 0x808012B0: jal         0x800D8FF8
    // 0x808012B4: addu        $s2, $s1, $t6
    ctx->r18 = ADD32(ctx->r17, ctx->r14);
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x808012B4: addu        $s2, $s1, $t6
    ctx->r18 = ADD32(ctx->r17, ctx->r14);
    after_2:
    // 0x808012B8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808012BC: jal         0x800F2100
    // 0x808012C0: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x808012C0: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    after_3:
    // 0x808012C4: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x808012C8: lwc1        $f12, 0x70($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X70);
    // 0x808012CC: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x808012D0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808012D4: jal         0x800F1F38
    // 0x808012D8: nop

    func_800F1F38(rdram, ctx);
        goto after_4;
    // 0x808012D8: nop

    after_4:
    // 0x808012DC: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x808012E0: jal         0x800136E4
    // 0x808012E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x808012E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x808012E8: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
L_808012EC:
    // 0x808012EC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808012F0: slti        $at, $s1, 0x14
    ctx->r1 = SIGNED(ctx->r17) < 0X14 ? 1 : 0;
    // 0x808012F4: bne         $at, $zero, L_80801294
    if (ctx->r1 != 0) {
        // 0x808012F8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80801294;
    }
    // 0x808012F8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_808012FC:
    // 0x808012FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80801300: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801304: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80801308: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8080130C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80801310: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80801314: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80801318: jr          $ra
    // 0x8080131C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080131C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80800000_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800010: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80800014: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800018: ori         $t7, $a2, 0xE
    ctx->r15 = ctx->r6 | 0XE;
    // 0x8080001C: addiu       $t8, $zero, 0x33
    ctx->r24 = ADD32(0, 0X33);
    // 0x80800020: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800024: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80800028: jal         0x8008A208
    // 0x8080002C: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x8080002C: addiu       $a3, $t6, 0x4
    ctx->r7 = ADD32(ctx->r14, 0X4);
    after_0:
    // 0x80800030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800034: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_808017A0_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808017A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808017A8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1060, 0X2A48) << 16);
    // 0x808017AC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1060, 0X2C40) << 16);
    // 0x808017B0: addiu       $a3, $a3, 0x2C40
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1060, 0X2C40));
    // 0x808017B4: addiu       $a2, $a2, 0x2A48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1060, 0X2A48));
    // 0x808017B8: jal         0x80089D28
    // 0x808017BC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808017BC: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x808017C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808017C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808017C8: jr          $ra
    // 0x808017CC: nop

    return;
    // 0x808017CC: nop

;}
RECOMP_FUNC void bswalk_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800F88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800F8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800F90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800F94: jal         0x8080016C
    // 0x80800F98: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    func_8080016C_bswalk(rdram, ctx);
        goto after_0;
    // 0x80800F98: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800FA4: jal         0x8009D2F0
    // 0x80800FA8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_1;
    // 0x80800FA8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_1:
    // 0x80800FAC: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800FB0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FB8: jal         0x800A2CE8
    // 0x80800FBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_2;
    // 0x80800FBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80800FC0: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80800FC4: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FCC: jal         0x800A2CE8
    // 0x80800FD0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_3;
    // 0x80800FD0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x80800FD4: jal         0x808001E4
    // 0x80800FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001E4_bswalk(rdram, ctx);
        goto after_4;
    // 0x80800FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800FDC: jal         0x80800000
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bswalk(rdram, ctx);
        goto after_5;
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800FE4: jal         0x8009EF10
    // 0x80800FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_6;
    // 0x80800FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800FEC: beq         $v0, $zero, L_80801018
    if (ctx->r2 == 0) {
        // 0x80800FF0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80801018;
    }
    // 0x80800FF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800FF4: beq         $v0, $at, L_80801050
    if (ctx->r2 == ctx->r1) {
        // 0x80800FF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801050;
    }
    // 0x80800FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FFC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801000: beq         $v0, $at, L_80801050
    if (ctx->r2 == ctx->r1) {
        // 0x80801004: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801050;
    }
    // 0x80801004: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801008: beq         $v0, $at, L_80801084
    if (ctx->r2 == ctx->r1) {
        // 0x8080100C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801084;
    }
    // 0x8080100C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801010: b           L_808010C4
    // 0x80801014: nop

        goto L_808010C4;
    // 0x80801014: nop

L_80801018:
    // 0x80801018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080101C: jal         0x8009BCD4
    // 0x80801020: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_7;
    // 0x80801020: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    after_7:
    // 0x80801024: beq         $v0, $zero, L_80801030
    if (ctx->r2 == 0) {
        // 0x80801028: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80801030;
    }
    // 0x80801028: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080102C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80801030:
    // 0x80801030: jal         0x80097AD0
    // 0x80801034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_8;
    // 0x80801034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801038: beq         $v0, $zero, L_808010C4
    if (ctx->r2 == 0) {
        // 0x8080103C: nop
    
            goto L_808010C4;
    }
    // 0x8080103C: nop

    // 0x80801040: jal         0x800848A8
    // 0x80801044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_9;
    // 0x80801044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80801048: b           L_808010C4
    // 0x8080104C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_808010C4;
    // 0x8080104C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80801050:
    // 0x80801050: jal         0x8009BCD4
    // 0x80801054: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_10;
    // 0x80801054: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    after_10:
    // 0x80801058: beq         $v0, $zero, L_80801064
    if (ctx->r2 == 0) {
        // 0x8080105C: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80801064;
    }
    // 0x8080105C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80801060: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80801064:
    // 0x80801064: jal         0x80097AD0
    // 0x80801068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_11;
    // 0x80801068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8080106C: beq         $v0, $zero, L_808010C4
    if (ctx->r2 == 0) {
        // 0x80801070: nop
    
            goto L_808010C4;
    }
    // 0x80801070: nop

    // 0x80801074: jal         0x800848A8
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_12;
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080107C: b           L_808010C4
    // 0x80801080: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_808010C4;
    // 0x80801080: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80801084:
    // 0x80801084: jal         0x8009BCD4
    // 0x80801088: lui         $a1, 0x4361
    ctx->r5 = S32(0X4361 << 16);
    func_8009BCD4(rdram, ctx);
        goto after_13;
    // 0x80801088: lui         $a1, 0x4361
    ctx->r5 = S32(0X4361 << 16);
    after_13:
    // 0x8080108C: beq         $v0, $zero, L_808010A8
    if (ctx->r2 == 0) {
        // 0x80801090: nop
    
            goto L_808010A8;
    }
    // 0x80801090: nop

    // 0x80801094: jal         0x80800220
    // 0x80801098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800220_bswalk(rdram, ctx);
        goto after_14;
    // 0x80801098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080109C: beq         $v0, $zero, L_808010A8
    if (ctx->r2 == 0) {
        // 0x808010A0: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_808010A8;
    }
    // 0x808010A0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x808010A4: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_808010A8:
    // 0x808010A8: jal         0x80097AD0
    // 0x808010AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_enter_first_person(rdram, ctx);
        goto after_15;
    // 0x808010AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808010B0: beq         $v0, $zero, L_808010C4
    if (ctx->r2 == 0) {
        // 0x808010B4: nop
    
            goto L_808010C4;
    }
    // 0x808010B4: nop

    // 0x808010B8: jal         0x800848A8
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_24(rdram, ctx);
        goto after_16;
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808010C0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_808010C4:
    // 0x808010C4: jal         0x8008DE24
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DE24(rdram, ctx);
        goto after_17;
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808010CC: beq         $v0, $zero, L_808010D8
    if (ctx->r2 == 0) {
        // 0x808010D0: addiu       $t9, $zero, 0x7A
        ctx->r25 = ADD32(0, 0X7A);
            goto L_808010D8;
    }
    // 0x808010D0: addiu       $t9, $zero, 0x7A
    ctx->r25 = ADD32(0, 0X7A);
    // 0x808010D4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_808010D8:
    // 0x808010D8: jal         0x8008E300
    // 0x808010DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E300(rdram, ctx);
        goto after_18;
    // 0x808010DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808010E0: beq         $v0, $zero, L_80801110
    if (ctx->r2 == 0) {
        // 0x808010E4: nop
    
            goto L_80801110;
    }
    // 0x808010E4: nop

    // 0x808010E8: jal         0x8009BB5C
    // 0x808010EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_19;
    // 0x808010EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808010F0: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x808010F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808010F8: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x808010FC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80801100: nop

    // 0x80801104: bc1f        L_80801110
    if (!c1cs) {
        // 0x80801108: nop
    
            goto L_80801110;
    }
    // 0x80801108: nop

    // 0x8080110C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_80801110:
    // 0x80801110: jal         0x8008DD04
    // 0x80801114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_20;
    // 0x80801114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801118: beq         $v0, $zero, L_80801128
    if (ctx->r2 == 0) {
        // 0x8080111C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801128;
    }
    // 0x8080111C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801120: addiu       $t1, $zero, 0x2F
    ctx->r9 = ADD32(0, 0X2F);
    // 0x80801124: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
L_80801128:
    // 0x80801128: jal         0x800919F4
    // 0x8080112C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_held(rdram, ctx);
        goto after_21;
    // 0x8080112C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x80801130: beq         $v0, $zero, L_80801140
    if (ctx->r2 == 0) {
        // 0x80801134: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801140;
    }
    // 0x80801134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801138: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8080113C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_80801140:
    // 0x80801140: jal         0x80800248
    // 0x80801144: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80800248_bswalk(rdram, ctx);
        goto after_22;
    // 0x80801144: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_22:
    // 0x80801148: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080114C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801150: jal         0x80091A58
    // 0x80801154: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_23;
    // 0x80801154: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_23:
    // 0x80801158: beq         $v0, $zero, L_808011C4
    if (ctx->r2 == 0) {
        // 0x8080115C: nop
    
            goto L_808011C4;
    }
    // 0x8080115C: nop

    // 0x80801160: jal         0x8009FE84
    // 0x80801164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getTypeOfJump(rdram, ctx);
        goto after_24;
    // 0x80801164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80801168: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080116C: jal         0x8009BB00
    // 0x80801170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_25;
    // 0x80801170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80801174: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80801178: nop

    // 0x8080117C: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80801180: nop

    // 0x80801184: bc1f        L_808011C4
    if (!c1cs) {
        // 0x80801188: nop
    
            goto L_808011C4;
    }
    // 0x80801188: nop

    // 0x8080118C: jal         0x8008D714
    // 0x80801190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D714(rdram, ctx);
        goto after_26;
    // 0x80801190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80801194: beq         $v0, $zero, L_808011A4
    if (ctx->r2 == 0) {
        // 0x80801198: addiu       $t3, $zero, 0xB8
        ctx->r11 = ADD32(0, 0XB8);
            goto L_808011A4;
    }
    // 0x80801198: addiu       $t3, $zero, 0xB8
    ctx->r11 = ADD32(0, 0XB8);
    // 0x8080119C: b           L_808011C4
    // 0x808011A0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
        goto L_808011C4;
    // 0x808011A0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
L_808011A4:
    // 0x808011A4: jal         0x8008D790
    // 0x808011A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D790(rdram, ctx);
        goto after_27;
    // 0x808011A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808011AC: beq         $v0, $zero, L_808011C4
    if (ctx->r2 == 0) {
        // 0x808011B0: nop
    
            goto L_808011C4;
    }
    // 0x808011B0: nop

    // 0x808011B4: jal         0x80084978
    // 0x808011B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_12(rdram, ctx);
        goto after_28;
    // 0x808011B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808011BC: b           L_80801210
    // 0x808011C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801210;
    // 0x808011C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011C4:
    // 0x808011C4: jal         0x8008E148
    // 0x808011C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_29;
    // 0x808011C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808011CC: beq         $v0, $zero, L_808011E0
    if (ctx->r2 == 0) {
        // 0x808011D0: nop
    
            goto L_808011E0;
    }
    // 0x808011D0: nop

    // 0x808011D4: jal         0x800848B0
    // 0x808011D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_30;
    // 0x808011D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x808011DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_808011E0:
    // 0x808011E0: jal         0x8008E35C
    // 0x808011E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_31;
    // 0x808011E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x808011E8: beq         $v0, $zero, L_808011F8
    if (ctx->r2 == 0) {
        // 0x808011EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808011F8;
    }
    // 0x808011EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011F0: addiu       $t4, $zero, 0x2D
    ctx->r12 = ADD32(0, 0X2D);
    // 0x808011F4: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
L_808011F8:
    // 0x808011F8: jal         0x800A02DC
    // 0x808011FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800A02DC(rdram, ctx);
        goto after_32;
    // 0x808011FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_32:
    // 0x80801200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801204: jal         0x8009E5C8
    // 0x80801208: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_33;
    // 0x80801208: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_33:
    // 0x8080120C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801210:
    // 0x80801210: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801214: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801218: jr          $ra
    // 0x8080121C: nop

    return;
    // 0x8080121C: nop

;}
RECOMP_FUNC void babounce_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080006C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800074: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80800078: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080007C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800080: lbu         $t6, 0xC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC);
    // 0x80800084: bnel        $t6, $at, L_8080009C
    if (ctx->r14 != ctx->r1) {
        // 0x80800088: lbu         $t7, 0xD($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0XD);
            goto L_8080009C;
    }
    goto skip_0;
    // 0x80800088: lbu         $t7, 0xD($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XD);
    skip_0:
    // 0x8080008C: jal         0x8009BA9C
    // 0x80800090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009BA9C(rdram, ctx);
        goto after_0;
    // 0x80800090: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800094: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x80800098: lbu         $t7, 0xD($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XD);
L_8080009C:
    // 0x8080009C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000A0: bnel        $t7, $at, L_808000C0
    if (ctx->r15 != ctx->r1) {
        // 0x808000A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000C0;
    }
    goto skip_1;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808000A8: jal         0x800951B4
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_1;
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000B0: jal         0x8009BD88
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BD88(rdram, ctx);
        goto after_2;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000B8: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000C0:
    // 0x808000C0: jal         0x8009BCB4
    // 0x808000C4: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    baphysics_set_gravity(rdram, ctx);
        goto after_3;
    // 0x808000C4: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    after_3:
    // 0x808000C8: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x8009BCC4
    // 0x808000D4: lw          $a1, 0x18($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X18);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_4;
    // 0x808000D4: lw          $a1, 0x18($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X18);
    after_4:
    // 0x808000D8: jal         0x8008E95C
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E95C(rdram, ctx);
        goto after_5;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000E0: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x808000E4: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x808000E8: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    // 0x808000EC: beql        $a0, $zero, L_80800108
    if (ctx->r4 == 0) {
        // 0x808000F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800108;
    }
    goto skip_2;
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808000F4: jal         0x8010114C
    // 0x808000F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_6;
    // 0x808000F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x808000FC: lw          $t0, 0x28($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X28);
    // 0x80800100: sw          $zero, 0x10($t0)
    MEM_W(0X10, ctx->r8) = 0;
    // 0x80800104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800108:
    // 0x80800108: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080010C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800110: jr          $ra
    // 0x80800114: nop

    return;
    // 0x80800114: nop

;}
RECOMP_FUNC void func_800F5008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_players_hidden()) { MEM_B(0x48, (gpr)(int32_t)0x80135490) = 0; return; }
    // 0x800F5008: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F500C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800F5010: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800F5014: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800F5018: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800F501C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800F5020: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800F5024: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800F5028: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800F502C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800F5030: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800F5034: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800F5038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F503C: addiu       $s6, $s6, 0x5490
    ctx->r22 = ADD32(ctx->r22, 0X5490);
    // 0x800F5040: addiu       $s5, $s5, 0x54B0
    ctx->r21 = ADD32(ctx->r21, 0X54B0);
    // 0x800F5044: addiu       $s1, $s1, 0x5490
    ctx->r17 = ADD32(ctx->r17, 0X5490);
    // 0x800F5048: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800F504C: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x800F5050: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_800F5054:
    // 0x800F5054: beql        $s0, $zero, L_800F509C
    if (ctx->r16 == 0) {
        // 0x800F5058: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800F509C;
    }
    goto skip_0;
    // 0x800F5058: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x800F505C: lw          $t6, 0x17C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X17C);
    // 0x800F5060: beql        $t6, $zero, L_800F509C
    if (ctx->r14 == 0) {
        // 0x800F5064: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800F509C;
    }
    goto skip_1;
    // 0x800F5064: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_1:
    // 0x800F5068: jal         0x80092258
    // 0x800F506C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092258(rdram, ctx);
        goto after_0;
    // 0x800F506C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800F5070: bne         $s4, $v0, L_800F508C
    if (ctx->r20 != ctx->r2) {
        // 0x800F5074: sll         $t7, $s2, 2
        ctx->r15 = S32(ctx->r18 << 2);
            goto L_800F508C;
    }
    // 0x800F5074: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x800F5078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F507C: jal         0x80098BA8
    // 0x800F5080: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_80098BA8(rdram, ctx);
        goto after_1;
    // 0x800F5080: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x800F5084: b           L_800F509C
    // 0x800F5088: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
        goto L_800F509C;
    // 0x800F5088: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800F508C:
    // 0x800F508C: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x800F5090: sw          $s0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r16;
    // 0x800F5094: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800F5098: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800F509C:
    // 0x800F509C: bnel        $s1, $s5, L_800F5054
    if (ctx->r17 != ctx->r21) {
        // 0x800F50A0: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_800F5054;
    }
    goto skip_2;
    // 0x800F50A0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x800F50A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800F50A8: sb          $s2, 0x48($s6)
    MEM_B(0X48, ctx->r22) = ctx->r18;
    // 0x800F50AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800F50B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800F50B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F50B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800F50BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800F50C0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800F50C4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800F50C8: jr          $ra
    // 0x800F50CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800F50CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void chskeletonexplode_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C84: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800C88: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800C8C: swc1        $f12, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f12.u32l;
    // 0x80800C90: jr          $ra
    // 0x80800C94: swc1        $f14, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x80800C94: swc1        $f14, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_800FFBEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFBEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FFBF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFBF4: jal         0x800FFC3C
    // 0x800FFBF8: nop

    func_800FFC3C(rdram, ctx);
        goto after_0;
    // 0x800FFBF8: nop

    after_0:
    // 0x800FFBFC: jal         0x8010DEFC
    // 0x800FFC00: nop

    func_8010DEFC(rdram, ctx);
        goto after_1;
    // 0x800FFC00: nop

    after_1:
    // 0x800FFC04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFC08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FFC0C: jr          $ra
    // 0x800FFC10: nop

    return;
    // 0x800FFC10: nop

;}
RECOMP_FUNC void func_800BA2E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA2E8: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x800BA2EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BA2F0: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800BA2F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800BA2F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BA2FC: addiu       $a2, $v0, 0xD4
    ctx->r6 = ADD32(ctx->r2, 0XD4);
    // 0x800BA300: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BA304: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800BA308: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800BA30C: jal         0x8001ACCC
    // 0x800BA310: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800BA310: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x800BA314: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800BA318: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800BA31C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800BA320: jal         0x8001BCF8
    // 0x800BA324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    rare_memset(rdram, ctx);
        goto after_1;
    // 0x800BA324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x800BA328: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800BA32C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BA330: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BA334: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800BA338: sb          $t6, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r14;
    // 0x800BA33C: sb          $v0, 0x83($s0)
    MEM_B(0X83, ctx->r16) = ctx->r2;
    // 0x800BA340: sb          $v0, 0x82($s0)
    MEM_B(0X82, ctx->r16) = ctx->r2;
    // 0x800BA344: sb          $v0, 0x81($s0)
    MEM_B(0X81, ctx->r16) = ctx->r2;
    // 0x800BA348: sb          $v0, 0x80($s0)
    MEM_B(0X80, ctx->r16) = ctx->r2;
    // 0x800BA34C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BA350: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x800BA354: jal         0x800BA4D0
    // 0x800BA358: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    func_800BA4D0(rdram, ctx);
        goto after_2;
    // 0x800BA358: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x800BA35C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BA360: jal         0x800BA568
    // 0x800BA364: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    func_800BA568(rdram, ctx);
        goto after_3;
    // 0x800BA364: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_3:
    // 0x800BA368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BA36C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800BA370: jal         0x800BA894
    // 0x800BA374: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    func_800BA894(rdram, ctx);
        goto after_4;
    // 0x800BA374: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_4:
    // 0x800BA378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BA37C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800BA380: jal         0x800BA8F8
    // 0x800BA384: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    func_800BA8F8(rdram, ctx);
        goto after_5;
    // 0x800BA384: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_5:
    // 0x800BA388: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x800BA38C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x800BA390: jal         0x800BA4C4
    // 0x800BA394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BA4C4(rdram, ctx);
        goto after_6;
    // 0x800BA394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800BA398: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BA39C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BA3A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BA3A4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800BA3A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800BA3AC: jal         0x800BA554
    // 0x800BA3B0: nop

    func_800BA554(rdram, ctx);
        goto after_7;
    // 0x800BA3B0: nop

    after_7:
    // 0x800BA3B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BA3B8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800BA3BC: jal         0x800BA7C4
    // 0x800BA3C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800BA7C4(rdram, ctx);
        goto after_8;
    // 0x800BA3C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_8:
    // 0x800BA3C4: addiu       $v1, $s0, 0xD4
    ctx->r3 = ADD32(ctx->r16, 0XD4);
    // 0x800BA3C8: sw          $v1, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r3;
    // 0x800BA3CC: sw          $v1, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->r3;
    // 0x800BA3D0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800BA3D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800BA3D8: sb          $a0, 0x52($s0)
    MEM_B(0X52, ctx->r16) = ctx->r4;
    // 0x800BA3DC: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800BA3E0: sw          $t9, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r25;
    // 0x800BA3E4: sb          $a0, 0x53($s0)
    MEM_B(0X53, ctx->r16) = ctx->r4;
    // 0x800BA3E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA3EC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800BA3F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BA3F4: jr          $ra
    // 0x800BA3F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800BA3F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _chfactoryrobot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086218: syscall     291
    recomp_syscall_handler(rdram, ctx, 0x80086218);
    return;
    // 0x8008621C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _badata_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084648: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084648);
    return;
    // 0x8008464C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A7990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A799C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A79A0: jal         0x800FE8EC
    // 0x800A79A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800FE8EC(rdram, ctx);
        goto after_0;
    // 0x800A79A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A79A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800A79AC: jal         0x800A7A6C
    // 0x800A79B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800A7A6C(rdram, ctx);
        goto after_1;
    // 0x800A79B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800A79B4: jal         0x800A7A90
    // 0x800A79B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800A7A90(rdram, ctx);
        goto after_2;
    // 0x800A79B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800A79BC: jal         0x800A7B18
    // 0x800A79C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A7B18(rdram, ctx);
        goto after_3;
    // 0x800A79C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800A79C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A79C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A79CC: jr          $ra
    // 0x800A79D0: nop

    return;
    // 0x800A79D0: nop

;}
RECOMP_FUNC void func_808008F8_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800900: jal         0x80082FE8
    // 0x80800904: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800904: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800908: jal         0x8080081C
    // 0x8080090C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstrexlarge_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080090C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800918: jr          $ra
    // 0x8080091C: nop

    return;
    // 0x8080091C: nop

;}
RECOMP_FUNC void func_80802994_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080299C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808029A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808029A4: jal         0x80100094
    // 0x808029A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808029A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808029AC: beq         $v0, $zero, L_808029C8
    if (ctx->r2 == 0) {
        // 0x808029B0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808029C8;
    }
    // 0x808029B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808029B4: jal         0x80100094
    // 0x808029B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808029B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808029BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808029C0: jal         0x80087CA0
    // 0x808029C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808029C4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_808029C8:
    // 0x808029C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808029CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808029D0: jr          $ra
    // 0x808029D4: nop

    return;
    // 0x808029D4: nop

;}
RECOMP_FUNC void _fxdialog_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088B38: syscall     725
    recomp_syscall_handler(rdram, ctx, 0x80088B38);
    return;
    // 0x80088B3C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080032C_chfog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800330: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800334: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800338: jal         0x800DC0C0
    // 0x8080033C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x8080033C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800340: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA40) << 16);
    // 0x80800344: lwc1        $f4, 0xA40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA40));
    // 0x80800348: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080034C: nop

    // 0x80800350: bc1f        L_80800364
    if (!c1cs) {
        // 0x80800354: nop
    
            goto L_80800364;
    }
    // 0x80800354: nop

    // 0x80800358: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8080035C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80800360: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
L_80800364:
    // 0x80800364: jal         0x800DC0C0
    // 0x80800368: nop

    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x80800368: nop

    after_1:
    // 0x8080036C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA44) << 16);
    // 0x80800370: lwc1        $f10, 0xA44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA44));
    // 0x80800374: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800378: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080037C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800380: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80800384: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80800388: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x8080038C: bc1fl       L_808003A4
    if (!c1cs) {
        // 0x80800390: lwc1        $f8, 0x18($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
            goto L_808003A4;
    }
    goto skip_0;
    // 0x80800390: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    skip_0:
    // 0x80800394: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800398: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8080039C: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x808003A0: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
L_808003A4:
    // 0x808003A4: c.eq.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl == ctx->f8.fl;
    // 0x808003A8: nop

    // 0x808003AC: bc1f        L_808003E0
    if (!c1cs) {
        // 0x808003B0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1620, 0XA48) << 16);
            goto L_808003E0;
    }
    // 0x808003B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA48) << 16);
    // 0x808003B4: lwc1        $f10, 0xA48($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA48));
    // 0x808003B8: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808003BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA4C) << 16);
    // 0x808003C0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808003C4: nop

    // 0x808003C8: bc1fl       L_80800410
    if (!c1cs) {
        // 0x808003CC: lwc1        $f6, 0x1C($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_80800410;
    }
    goto skip_1;
    // 0x808003CC: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    skip_1:
    // 0x808003D0: lwc1        $f4, 0xA4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA4C));
    // 0x808003D4: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808003D8: b           L_8080040C
    // 0x808003DC: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
        goto L_8080040C;
    // 0x808003DC: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_808003E0:
    // 0x808003E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA50) << 16);
    // 0x808003E4: lwc1        $f8, 0xA50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA50));
    // 0x808003E8: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808003EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA54) << 16);
    // 0x808003F0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808003F4: nop

    // 0x808003F8: bc1fl       L_80800410
    if (!c1cs) {
        // 0x808003FC: lwc1        $f6, 0x1C($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_80800410;
    }
    goto skip_2;
    // 0x808003FC: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    skip_2:
    // 0x80800400: lwc1        $f10, 0xA54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA54));
    // 0x80800404: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80800408: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
L_8080040C:
    // 0x8080040C: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
L_80800410:
    // 0x80800410: c.eq.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl == ctx->f6.fl;
    // 0x80800414: nop

    // 0x80800418: bc1f        L_8080044C
    if (!c1cs) {
        // 0x8080041C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1620, 0XA58) << 16);
            goto L_8080044C;
    }
    // 0x8080041C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA58) << 16);
    // 0x80800420: lwc1        $f8, 0xA58($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA58));
    // 0x80800424: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800428: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA5C) << 16);
    // 0x8080042C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800430: nop

    // 0x80800434: bc1fl       L_8080047C
    if (!c1cs) {
        // 0x80800438: lui         $at, 0xC348
        ctx->r1 = S32(0XC348 << 16);
            goto L_8080047C;
    }
    goto skip_3;
    // 0x80800438: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    skip_3:
    // 0x8080043C: lwc1        $f10, 0xA5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA5C));
    // 0x80800440: add.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800444: b           L_80800478
    // 0x80800448: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
        goto L_80800478;
    // 0x80800448: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
L_8080044C:
    // 0x8080044C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA60) << 16);
    // 0x80800450: lwc1        $f6, 0xA60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA60));
    // 0x80800454: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800458: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA64) << 16);
    // 0x8080045C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800460: nop

    // 0x80800464: bc1fl       L_8080047C
    if (!c1cs) {
        // 0x80800468: lui         $at, 0xC348
        ctx->r1 = S32(0XC348 << 16);
            goto L_8080047C;
    }
    goto skip_4;
    // 0x80800468: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    skip_4:
    // 0x8080046C: lwc1        $f8, 0xA64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA64));
    // 0x80800470: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80800474: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
L_80800478:
    // 0x80800478: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
L_8080047C:
    // 0x8080047C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800480: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800484: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800488: nop

    // 0x8080048C: bc1fl       L_808004B4
    if (!c1cs) {
        // 0x80800490: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_808004B4;
    }
    goto skip_5;
    // 0x80800490: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    skip_5:
    // 0x80800494: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800498: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x8080049C: nop

    // 0x808004A0: bc1tl       L_808004B4
    if (c1cs) {
        // 0x808004A4: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_808004B4;
    }
    goto skip_6;
    // 0x808004A4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    skip_6:
    // 0x808004A8: b           L_80800500
    // 0x808004AC: swc1        $f12, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f12.u32l;
        goto L_80800500;
    // 0x808004AC: swc1        $f12, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f12.u32l;
    // 0x808004B0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_808004B4:
    // 0x808004B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004B8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808004BC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808004C0: nop

    // 0x808004C4: bc1fl       L_808004F8
    if (!c1cs) {
        // 0x808004C8: lwc1        $f6, 0x28($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
            goto L_808004F8;
    }
    goto skip_7;
    // 0x808004C8: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    skip_7:
    // 0x808004CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004D0: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x808004D4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808004D8: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x808004DC: nop

    // 0x808004E0: bc1tl       L_808004F8
    if (c1cs) {
        // 0x808004E4: lwc1        $f6, 0x28($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
            goto L_808004F8;
    }
    goto skip_8;
    // 0x808004E4: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    skip_8:
    // 0x808004E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004EC: b           L_80800500
    // 0x808004F0: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
        goto L_80800500;
    // 0x808004F0: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x808004F4: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
L_808004F8:
    // 0x808004F8: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x808004FC: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
L_80800500:
    // 0x80800500: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800504: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800508: nop

    // 0x8080050C: bc1fl       L_80800534
    if (!c1cs) {
        // 0x80800510: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80800534;
    }
    goto skip_9;
    // 0x80800510: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    skip_9:
    // 0x80800514: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800518: c.eq.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl == ctx->f10.fl;
    // 0x8080051C: nop

    // 0x80800520: bc1tl       L_80800534
    if (c1cs) {
        // 0x80800524: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80800534;
    }
    goto skip_10;
    // 0x80800524: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    skip_10:
    // 0x80800528: b           L_80800580
    // 0x8080052C: swc1        $f12, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f12.u32l;
        goto L_80800580;
    // 0x8080052C: swc1        $f12, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f12.u32l;
    // 0x80800530: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_80800534:
    // 0x80800534: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800538: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080053C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800540: nop

    // 0x80800544: bc1fl       L_80800578
    if (!c1cs) {
        // 0x80800548: lwc1        $f4, 0x2C($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
            goto L_80800578;
    }
    goto skip_11;
    // 0x80800548: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    skip_11:
    // 0x8080054C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800550: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800554: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800558: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8080055C: nop

    // 0x80800560: bc1tl       L_80800578
    if (c1cs) {
        // 0x80800564: lwc1        $f4, 0x2C($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
            goto L_80800578;
    }
    goto skip_12;
    // 0x80800564: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    skip_12:
    // 0x80800568: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080056C: b           L_80800580
    // 0x80800570: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
        goto L_80800580;
    // 0x80800570: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x80800574: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
L_80800578:
    // 0x80800578: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8080057C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_80800580:
    // 0x80800580: jal         0x800E3B50
    // 0x80800584: sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    func_800E3B50(rdram, ctx);
        goto after_2;
    // 0x80800584: sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    after_2:
    // 0x80800588: jal         0x800E3980
    // 0x8080058C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    func_800E3980(rdram, ctx);
        goto after_3;
    // 0x8080058C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x80800590: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    // 0x80800594: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80800598: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8080059C: jal         0x800EFB24
    // 0x808005A0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x808005A0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_4:
    // 0x808005A4: jal         0x800F54E4
    // 0x808005A8: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x808005A8: nop

    after_5:
    // 0x808005AC: jal         0x800F690C
    // 0x808005B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F690C(rdram, ctx);
        goto after_6;
    // 0x808005B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x808005B4: bne         $v0, $zero, L_80800744
    if (ctx->r2 != 0) {
        // 0x808005B8: lh          $v1, 0x3A($sp)
        ctx->r3 = MEM_H(ctx->r29, 0X3A);
            goto L_80800744;
    }
    // 0x808005B8: lh          $v1, 0x3A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3A);
    // 0x808005BC: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x808005C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808005C4: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808005C8: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x808005CC: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x808005D0: nop

    // 0x808005D4: bc1fl       L_80800630
    if (!c1cs) {
        // 0x808005D8: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80800630;
    }
    goto skip_13;
    // 0x808005D8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_13:
    // 0x808005DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005E0: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x808005E4: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808005E8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808005EC: nop

    // 0x808005F0: bc1fl       L_80800630
    if (!c1cs) {
        // 0x808005F4: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80800630;
    }
    goto skip_14;
    // 0x808005F4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_14:
    // 0x808005F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005FC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800600: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800604: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80800608: nop

    // 0x8080060C: bc1fl       L_8080061C
    if (!c1cs) {
        // 0x80800610: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_8080061C;
    }
    goto skip_15;
    // 0x80800610: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_15:
    // 0x80800614: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800618: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_8080061C:
    // 0x8080061C: nop

    // 0x80800620: bc1fl       L_80800630
    if (!c1cs) {
        // 0x80800624: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80800630;
    }
    goto skip_16;
    // 0x80800624: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_16:
    // 0x80800628: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8080062C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_80800630:
    // 0x80800630: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800634: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80800638: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080063C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA68) << 16);
    // 0x80800640: lwc1        $f10, 0xA68($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA68));
    // 0x80800644: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800648: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8080064C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800650: nop

    // 0x80800654: bc1tl       L_80800678
    if (c1cs) {
        // 0x80800658: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_80800678;
    }
    goto skip_17;
    // 0x80800658: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_17:
    // 0x8080065C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800660: nop

    // 0x80800664: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800668: nop

    // 0x8080066C: bc1fl       L_808006A0
    if (!c1cs) {
        // 0x80800670: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_808006A0;
    }
    goto skip_18;
    // 0x80800670: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    skip_18:
    // 0x80800674: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_80800678:
    // 0x80800678: nop

    // 0x8080067C: bc1fl       L_8080068C
    if (!c1cs) {
        // 0x80800680: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_8080068C;
    }
    goto skip_19;
    // 0x80800680: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_19:
    // 0x80800684: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80800688: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_8080068C:
    // 0x8080068C: nop

    // 0x80800690: bc1fl       L_808006A0
    if (!c1cs) {
        // 0x80800694: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_808006A0;
    }
    goto skip_20;
    // 0x80800694: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    skip_20:
    // 0x80800698: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8080069C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
L_808006A0:
    // 0x808006A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006A4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x808006A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006AC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808006B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA6C) << 16);
    // 0x808006B4: bc1fl       L_808006F8
    if (!c1cs) {
        // 0x808006B8: c.lt.s      $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
            goto L_808006F8;
    }
    goto skip_21;
    // 0x808006B8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    skip_21:
    // 0x808006BC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808006C0: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808006C4: bc1fl       L_808006F8
    if (!c1cs) {
        // 0x808006C8: c.lt.s      $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
            goto L_808006F8;
    }
    goto skip_22;
    // 0x808006C8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    skip_22:
    // 0x808006CC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x808006D0: nop

    // 0x808006D4: bc1fl       L_808006E4
    if (!c1cs) {
        // 0x808006D8: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_808006E4;
    }
    goto skip_23;
    // 0x808006D8: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_23:
    // 0x808006DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808006E0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_808006E4:
    // 0x808006E4: nop

    // 0x808006E8: bc1fl       L_808006F8
    if (!c1cs) {
        // 0x808006EC: c.lt.s      $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
            goto L_808006F8;
    }
    goto skip_24;
    // 0x808006EC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    skip_24:
    // 0x808006F0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x808006F4: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
L_808006F8:
    // 0x808006F8: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808006FC: bc1fl       L_808007D8
    if (!c1cs) {
        // 0x80800700: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_808007D8;
    }
    goto skip_25;
    // 0x80800700: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_25:
    // 0x80800704: lwc1        $f10, 0xA6C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA6C));
    // 0x80800708: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8080070C: nop

    // 0x80800710: bc1fl       L_808007D8
    if (!c1cs) {
        // 0x80800714: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_808007D8;
    }
    goto skip_26;
    // 0x80800714: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_26:
    // 0x80800718: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8080071C: nop

    // 0x80800720: bc1fl       L_80800730
    if (!c1cs) {
        // 0x80800724: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80800730;
    }
    goto skip_27;
    // 0x80800724: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_27:
    // 0x80800728: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8080072C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_80800730:
    // 0x80800730: nop

    // 0x80800734: bc1fl       L_808007D8
    if (!c1cs) {
        // 0x80800738: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_808007D8;
    }
    goto skip_28;
    // 0x80800738: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_28:
    // 0x8080073C: b           L_808007D4
    // 0x80800740: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_808007D4;
    // 0x80800740: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800744:
    // 0x80800744: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800748: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8080074C: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800750: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800754: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800758: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8080075C: bc1fl       L_8080076C
    if (!c1cs) {
        // 0x80800760: c.lt.s      $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
            goto L_8080076C;
    }
    goto skip_29;
    // 0x80800760: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    skip_29:
    // 0x80800764: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80800768: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
L_8080076C:
    // 0x8080076C: nop

    // 0x80800770: bc1fl       L_80800780
    if (!c1cs) {
        // 0x80800774: lwc1        $f0, 0x50($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
            goto L_80800780;
    }
    goto skip_30;
    // 0x80800774: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    skip_30:
    // 0x80800778: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8080077C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
L_80800780:
    // 0x80800780: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800784: nop

    // 0x80800788: bc1fl       L_808007A4
    if (!c1cs) {
        // 0x8080078C: lwc1        $f10, 0x58($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
            goto L_808007A4;
    }
    goto skip_31;
    // 0x8080078C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    skip_31:
    // 0x80800790: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800794: nop

    // 0x80800798: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x8080079C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808007A0: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
L_808007A4:
    // 0x808007A4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808007A8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808007AC: nop

    // 0x808007B0: bc1fl       L_808007C8
    if (!c1cs) {
        // 0x808007B4: lwc1        $f4, 0x54($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
            goto L_808007C8;
    }
    goto skip_32;
    // 0x808007B4: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    skip_32:
    // 0x808007B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808007BC: nop

    // 0x808007C0: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    // 0x808007C4: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
L_808007C8:
    // 0x808007C8: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x808007CC: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808007D0: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
L_808007D4:
    // 0x808007D4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_808007D8:
    // 0x808007D8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x808007DC: jal         0x800EE7F8
    // 0x808007E0: sh          $v1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r3;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x808007E0: sh          $v1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r3;
    after_7:
    // 0x808007E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808007E8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808007EC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808007F0: lh          $v1, 0x3A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3A);
    // 0x808007F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808007F8: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x808007FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800800: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800804: bne         $v1, $a0, L_80800838
    if (ctx->r3 != ctx->r4) {
        // 0x80800808: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_80800838;
    }
    // 0x80800808: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080080C: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800810: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800814: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800818: sub.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8080081C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800820: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800824: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80800828: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8080082C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800830: b           L_808008A4
    // 0x80800834: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
        goto L_808008A4;
    // 0x80800834: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_80800838:
    // 0x80800838: bne         $v1, $at, L_80800864
    if (ctx->r3 != ctx->r1) {
        // 0x8080083C: nop
    
            goto L_80800864;
    }
    // 0x8080083C: nop

    // 0x80800840: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800844: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800848: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080084C: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80800850: swc1        $f12, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f12.u32l;
    // 0x80800854: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80800858: add.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8080085C: b           L_808008A4
    // 0x80800860: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
        goto L_808008A4;
    // 0x80800860: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
L_80800864:
    // 0x80800864: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA70) << 16);
    // 0x80800868: lwc1        $f6, 0xA70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA70));
    // 0x8080086C: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800870: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA74) << 16);
    // 0x80800874: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800878: nop

    // 0x8080087C: bc1t        L_80800894
    if (c1cs) {
        // 0x80800880: nop
    
            goto L_80800894;
    }
    // 0x80800880: nop

    // 0x80800884: lwc1        $f8, 0xA74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA74));
    // 0x80800888: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8080088C: nop

    // 0x80800890: bc1f        L_808008A4
    if (!c1cs) {
        // 0x80800894: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1620, 0XA78) << 16);
            goto L_808008A4;
    }
L_80800894:
    // 0x80800894: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA78) << 16);
    // 0x80800898: lwc1        $f10, 0xA78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA78));
    // 0x8080089C: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808008A0: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
L_808008A4:
    // 0x808008A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808008A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808008AC: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x808008B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008B4: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808008B8: lui         $at, 0xC020
    ctx->r1 = S32(0XC020 << 16);
    // 0x808008BC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808008C0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808008C4: nop

    // 0x808008C8: bc1fl       L_80800900
    if (!c1cs) {
        // 0x808008CC: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80800900;
    }
    goto skip_33;
    // 0x808008CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_33:
    // 0x808008D0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808008D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808008D8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x808008DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808008E0: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808008E4: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x808008E8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808008EC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x808008F0: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x808008F4: b           L_80800970
    // 0x808008F8: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
        goto L_80800970;
    // 0x808008F8: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x808008FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80800900:
    // 0x80800900: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA7C) << 16);
    // 0x80800904: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800908: nop

    // 0x8080090C: bc1f        L_80800938
    if (!c1cs) {
        // 0x80800910: nop
    
            goto L_80800938;
    }
    // 0x80800910: nop

    // 0x80800914: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800918: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080091C: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800920: swc1        $f12, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f12.u32l;
    // 0x80800924: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800928: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8080092C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80800930: b           L_80800970
    // 0x80800934: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
        goto L_80800970;
    // 0x80800934: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
L_80800938:
    // 0x80800938: lwc1        $f2, 0xA7C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA7C));
    // 0x8080093C: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800940: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1620, 0XA80) << 16);
    // 0x80800944: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800948: nop

    // 0x8080094C: bc1t        L_80800964
    if (c1cs) {
        // 0x80800950: nop
    
            goto L_80800964;
    }
    // 0x80800950: nop

    // 0x80800954: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800958: nop

    // 0x8080095C: bc1fl       L_80800974
    if (!c1cs) {
        // 0x80800960: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_80800974;
    }
    goto skip_34;
    // 0x80800960: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_34:
L_80800964:
    // 0x80800964: lwc1        $f8, 0xA80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1620, 0XA80));
    // 0x80800968: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8080096C: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
L_80800970:
    // 0x80800970: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_80800974:
    // 0x80800974: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800978: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080097C: beql        $t6, $a0, L_80800998
    if (ctx->r14 == ctx->r4) {
        // 0x80800980: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_80800998;
    }
    goto skip_35;
    // 0x80800980: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_35:
    // 0x80800984: beql        $t6, $at, L_808009E0
    if (ctx->r14 == ctx->r1) {
        // 0x80800988: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808009E0;
    }
    goto skip_36;
    // 0x80800988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_36:
    // 0x8080098C: b           L_808009E0
    // 0x80800990: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808009E0;
    // 0x80800990: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800994: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_80800998:
    // 0x80800998: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8080099C: bgezl       $t9, L_808009E0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808009A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808009E0;
    }
    goto skip_37;
    // 0x808009A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_37:
    // 0x808009A4: jal         0x800D90A4
    // 0x808009A8: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_8;
    // 0x808009A8: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_8:
    // 0x808009AC: bne         $v0, $zero, L_808009DC
    if (ctx->r2 != 0) {
        // 0x808009B0: lui         $a2, 0x4100
        ctx->r6 = S32(0X4100 << 16);
            goto L_808009DC;
    }
    // 0x808009B0: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x808009B4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808009B8: lwc1        $f12, 0x34($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808009BC: lui         $a3, 0x437F
    ctx->r7 = S32(0X437F << 16);
    // 0x808009C0: jal         0x800F10B4
    // 0x808009C4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x808009C4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_9:
    // 0x808009C8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808009D4: jal         0x80089C98
    // 0x808009D8: nop

    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x808009D8: nop

    after_10:
L_808009DC:
    // 0x808009DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009E0:
    // 0x808009E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808009E4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x808009E8: jr          $ra
    // 0x808009EC: nop

    return;
    // 0x808009EC: nop

;}
RECOMP_FUNC void subaddieDll_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080039C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808003A0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808003A4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808003A8: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x808003AC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808003B0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808003B4: jal         0x800882B0
    // 0x808003B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _gccubesearch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808003B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x808003BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003C0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x808003C4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
L_808003C8:
    // 0x808003C8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808003CC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x808003D0: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x808003D4: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x808003D8: lh          $v0, 0x0($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X0);
    // 0x808003DC: lh          $v1, 0x0($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X0);
    // 0x808003E0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808003E4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x808003E8: beql        $at, $zero, L_808003FC
    if (ctx->r1 == 0) {
        // 0x808003EC: sh          $v1, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r3;
            goto L_808003FC;
    }
    goto skip_0;
    // 0x808003EC: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    skip_0:
    // 0x808003F0: b           L_808003FC
    // 0x808003F4: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
        goto L_808003FC;
    // 0x808003F4: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x808003F8: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
L_808003FC:
    // 0x808003FC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800400: beql        $at, $zero, L_80800414
    if (ctx->r1 == 0) {
        // 0x80800404: sh          $v1, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r3;
            goto L_80800414;
    }
    goto skip_1;
    // 0x80800404: sh          $v1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r3;
    skip_1:
    // 0x80800408: b           L_80800414
    // 0x8080040C: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
        goto L_80800414;
    // 0x8080040C: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
    // 0x80800410: sh          $v1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r3;
L_80800414:
    // 0x80800414: bne         $a1, $a2, L_808003C8
    if (ctx->r5 != ctx->r6) {
        // 0x80800418: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_808003C8;
    }
    // 0x80800418: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8080041C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800420: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800424: jr          $ra
    // 0x80800428: nop

    return;
    // 0x80800428: nop

;}
RECOMP_FUNC void func_80100534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100534: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80100538: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010053C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80100540: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80100544: jal         0x8001211C
    // 0x80100548: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8001211C(rdram, ctx);
        goto after_0;
    // 0x80100548: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8010054C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80100550: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80100554: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80100558: addiu       $s1, $s1, 0x43DC
    ctx->r17 = ADD32(ctx->r17, 0X43DC);
    // 0x8010055C: addiu       $s0, $s0, 0x43A0
    ctx->r16 = ADD32(ctx->r16, 0X43A0);
    // 0x80100560: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
L_80100564:
    // 0x80100564: beql        $a0, $zero, L_80100598
    if (ctx->r4 == 0) {
        // 0x80100568: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80100598;
    }
    goto skip_0;
    // 0x80100568: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x8010056C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80100570: subu        $t7, $s2, $t6
    ctx->r15 = SUB32(ctx->r18, ctx->r14);
    // 0x80100574: slti        $at, $t7, 0x1F
    ctx->r1 = SIGNED(ctx->r15) < 0X1F ? 1 : 0;
    // 0x80100578: bnel        $at, $zero, L_80100598
    if (ctx->r1 != 0) {
        // 0x8010057C: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80100598;
    }
    goto skip_1;
    // 0x8010057C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x80100580: jal         0x8001B084
    // 0x80100584: nop

    heap_free(rdram, ctx);
        goto after_1;
    // 0x80100584: nop

    after_1:
    // 0x80100588: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8010058C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80100590: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80100594: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_80100598:
    // 0x80100598: bnel        $s0, $s1, L_80100564
    if (ctx->r16 != ctx->r17) {
        // 0x8010059C: lw          $a0, 0x8($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X8);
            goto L_80100564;
    }
    goto skip_2;
    // 0x8010059C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    skip_2:
    // 0x801005A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801005A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801005A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801005AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801005B0: jr          $ra
    // 0x801005B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801005B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800A25D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A25D0: lw          $t6, 0xB4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB4);
    // 0x800A25D4: jr          $ra
    // 0x800A25D8: lbu         $v0, 0x2($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2);
    return;
    // 0x800A25D8: lbu         $v0, 0x2($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X2);
;}
RECOMP_FUNC void func_80803208_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080320C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803210: jal         0x80801764
    // 0x80803214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801764_chcollballcontrol(rdram, ctx);
        goto after_0;
    // 0x80803214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080321C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803220: jr          $ra
    // 0x80803224: nop

    return;
    // 0x80803224: nop

;}
RECOMP_FUNC void _badrone_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084830: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084830);
    return;
    // 0x80084834: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800560_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800568: jal         0x8080064C
    // 0x8080056C: nop

    bstrexlarge_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080056C: nop

    after_0:
    // 0x80800570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800578: jr          $ra
    // 0x8080057C: nop

    return;
    // 0x8080057C: nop

;}
RECOMP_FUNC void func_80096604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009660C: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096610: jal         0x800C6840
    // 0x80096614: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C6840(rdram, ctx);
        goto after_0;
    // 0x80096614: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x80096618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009661C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80096620: jr          $ra
    // 0x80096624: nop

    return;
    // 0x80096624: nop

;}
RECOMP_FUNC void _bsbegghead_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082908: syscall     19
    recomp_syscall_handler(rdram, ctx, 0x80082908);
    return;
    // 0x8008290C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8009332C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009332C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80093330: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093334: jr          $ra
    // 0x80093338: swc1        $f12, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80093338: swc1        $f12, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_808000BC_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000C8: jal         0x80100094
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000D0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808000D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808000D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000DC: lhu         $v1, 0x72($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X72);
    // 0x808000E0: srl         $t7, $v1, 10
    ctx->r15 = S32(U32(ctx->r3) >> 10);
    // 0x808000E4: beq         $t7, $at, L_808002C4
    if (ctx->r15 == ctx->r1) {
        // 0x808000E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808002C4;
    }
    // 0x808000E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000EC: beq         $t7, $at, L_8080010C
    if (ctx->r15 == ctx->r1) {
        // 0x808000F0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080010C;
    }
    // 0x808000F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808000F4: beq         $t7, $at, L_8080021C
    if (ctx->r15 == ctx->r1) {
        // 0x808000F8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8080021C;
    }
    // 0x808000F8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808000FC: beq         $t7, $at, L_8080027C
    if (ctx->r15 == ctx->r1) {
        // 0x80800100: addiu       $a0, $zero, 0x2E
        ctx->r4 = ADD32(0, 0X2E);
            goto L_8080027C;
    }
    // 0x80800100: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x80800104: b           L_808002C8
    // 0x80800108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002C8;
    // 0x80800108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080010C:
    // 0x8080010C: jal         0x800F54E4
    // 0x80800110: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800110: nop

    after_1:
    // 0x80800114: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800118: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8080011C: addiu       $a0, $zero, 0xF7
    ctx->r4 = ADD32(0, 0XF7);
    // 0x80800120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800124: jal         0x800D2498
    // 0x80800128: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    func_800D2498(rdram, ctx);
        goto after_2;
    // 0x80800128: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x8080012C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800130: lw          $a0, 0x6C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X6C);
    // 0x80800134: andi        $t0, $a0, 0x1FF
    ctx->r8 = ctx->r4 & 0X1FF;
    // 0x80800138: jal         0x800CEAD0
    // 0x8080013C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_3;
    // 0x8080013C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_3:
    // 0x80800140: beq         $v0, $zero, L_80800194
    if (ctx->r2 == 0) {
        // 0x80800144: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800194;
    }
    // 0x80800144: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800148: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080014C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800150: jal         0x80800C38
    // 0x80800154: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_80800C38_chmonsterinterior(rdram, ctx);
        goto after_4;
    // 0x80800154: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_4:
    // 0x80800158: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8080015C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800160: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800164: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    // 0x80800168: jal         0x800F8300
    // 0x8080016C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F8300(rdram, ctx);
        goto after_5;
    // 0x8080016C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800170: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800174: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x80800178: jal         0x800F7C0C
    // 0x8080017C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800F7C0C(rdram, ctx);
        goto after_6;
    // 0x8080017C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_6:
    // 0x80800180: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800184: jal         0x80101FDC
    // 0x80800188: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800188: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
    // 0x8080018C: b           L_808002C8
    // 0x80800190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002C8;
    // 0x80800190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800194:
    // 0x80800194: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800198: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080019C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001A0: jal         0x800DC178
    // 0x808001A4: nop

    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x808001A4: nop

    after_8:
    // 0x808001A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808001AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001B0: jal         0x800D9154
    // 0x808001B4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9154(rdram, ctx);
        goto after_9;
    // 0x808001B4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_9:
    // 0x808001B8: beql        $v0, $zero, L_808002C8
    if (ctx->r2 == 0) {
        // 0x808001BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002C8;
    }
    goto skip_0;
    // 0x808001BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001C0: jal         0x800DC0C0
    // 0x808001C4: nop

    func_800DC0C0(rdram, ctx);
        goto after_10;
    // 0x808001C4: nop

    after_10:
    // 0x808001C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1320, 0X1CD0) << 16);
    // 0x808001CC: lwc1        $f4, 0x1CD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1CD0));
    // 0x808001D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808001D4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808001D8: nop

    // 0x808001DC: bc1fl       L_808001F0
    if (!c1cs) {
        // 0x808001E0: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_808001F0;
    }
    goto skip_1;
    // 0x808001E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x808001E4: b           L_8080020C
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8080020C;
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_808001F0:
    // 0x808001F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001F4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808001F8: nop

    // 0x808001FC: bc1f        L_8080020C
    if (!c1cs) {
        // 0x80800200: nop
    
            goto L_8080020C;
    }
    // 0x80800200: nop

    // 0x80800204: b           L_8080020C
    // 0x80800208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8080020C;
    // 0x80800208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080020C:
    // 0x8080020C: jal         0x80108B04
    // 0x80800210: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80108B04(rdram, ctx);
        goto after_11;
    // 0x80800210: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_11:
    // 0x80800214: b           L_808002C8
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002C8;
    // 0x80800218: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080021C:
    // 0x8080021C: jal         0x8008A2E8
    // 0x80800220: nop

    _susubgame_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x80800220: nop

    after_12:
    // 0x80800224: beq         $v0, $zero, L_808002C4
    if (ctx->r2 == 0) {
        // 0x80800228: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_808002C4;
    }
    // 0x80800228: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080022C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800230: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800234: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800238: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080023C: jal         0x8008A2C8
    // 0x80800240: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_13;
    // 0x80800240: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_13:
    // 0x80800244: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800248: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8080024C: addiu       $t3, $zero, 0xB3
    ctx->r11 = ADD32(0, 0XB3);
    // 0x80800250: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    // 0x80800254: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x80800258: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8080025C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800260: jal         0x8008A208
    // 0x80800264: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80800264: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x80800268: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080026C: jal         0x80101FDC
    // 0x80800270: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_15;
    // 0x80800270: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_15:
    // 0x80800274: b           L_808002C8
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808002C8;
    // 0x80800278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080027C:
    // 0x8080027C: jal         0x800D0B68
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_16;
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800284: beql        $v0, $zero, L_808002C8
    if (ctx->r2 == 0) {
        // 0x80800288: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002C8;
    }
    goto skip_2;
    // 0x80800288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8080028C: jal         0x800F54E4
    // 0x80800290: nop

    func_800F54E4(rdram, ctx);
        goto after_17;
    // 0x80800290: nop

    after_17:
    // 0x80800294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800298: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080029C: jal         0x800F8300
    // 0x808002A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F8300(rdram, ctx);
        goto after_18;
    // 0x808002A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x808002A4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x808002A8: addiu       $t4, $zero, 0xCEB
    ctx->r12 = ADD32(0, 0XCEB);
    // 0x808002AC: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x808002B0: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
    // 0x808002B4: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x808002B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808002BC: jal         0x80101FDC
    // 0x808002C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_19;
    // 0x808002C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_19:
L_808002C4:
    // 0x808002C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002C8:
    // 0x808002C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002CC: jr          $ra
    // 0x808002D0: nop

    return;
    // 0x808002D0: nop

;}
RECOMP_FUNC void func_80800928_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080092C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800930: jal         0x80800164
    // 0x80800934: nop

    func_80800164_bsbanshack(rdram, ctx);
        goto after_0;
    // 0x80800934: nop

    after_0:
    // 0x80800938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080093C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800940: jr          $ra
    // 0x80800944: nop

    return;
    // 0x80800944: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010D4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808010D8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1B58) << 16);
    // 0x808010DC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808010E0: jr          $ra
    // 0x808010E4: lw          $v0, 0x1B58($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B58));
    return;
    // 0x808010E4: lw          $v0, 0x1B58($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B58));
;}
RECOMP_FUNC void func_808010B4_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010BC: jal         0x80800130
    // 0x808010C0: nop

    func_80800130_bsstatue(rdram, ctx);
        goto after_0;
    // 0x808010C0: nop

    after_0:
    // 0x808010C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010CC: jr          $ra
    // 0x808010D0: nop

    return;
    // 0x808010D0: nop

;}
