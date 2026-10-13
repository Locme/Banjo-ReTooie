#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chmole_maya_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1596, 0X210) << 16);
    // 0x808000B8: jr          $ra
    // 0x808000BC: addiu       $v0, $v0, 0x210
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1596, 0X210));
    return;
    // 0x808000BC: addiu       $v0, $v0, 0x210
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1596, 0X210));
;}
RECOMP_FUNC void func_80800624_chtntbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800624: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800628: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080062C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800630: jal         0x800D8FF8
    // 0x80800634: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800634: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800638: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1892, 0X8C4) << 16);
    // 0x8080063C: lwc1        $f6, 0x8C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1892, 0X8C4));
    // 0x80800640: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800644: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800648: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8080064C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80800650: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800654: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800658: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800660: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800664: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80800668: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x8080066C: jal         0x808007B0
    // 0x80800670: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    func_808007B0_chtntbox(rdram, ctx);
        goto after_1;
    // 0x80800670: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80800674: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x80800678: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    // 0x8080067C: jal         0x8010B990
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_2;
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800684: andi        $t6, $v0, 0x20
    ctx->r14 = ctx->r2 & 0X20;
    // 0x80800688: beq         $t6, $zero, L_80800764
    if (ctx->r14 == 0) {
        // 0x8080068C: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80800764;
    }
    // 0x8080068C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800690: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800694: jal         0x800EE7F8
    // 0x80800698: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800698: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_3:
    // 0x8080069C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808006A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808006A4: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808006A8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1892, 0X8D0) << 16);
    // 0x808006AC: addiu       $t7, $t7, 0x8D0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1892, 0X8D0));
    // 0x808006B0: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808006B4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808006B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006BC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x808006C0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x808006C4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808006C8: jal         0x800BBCB8
    // 0x808006CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x808006CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x808006D0: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1892, 0X8F4) << 16);
    // 0x808006D4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808006D8: addiu       $t8, $t8, 0x8F4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1892, 0X8F4));
    // 0x808006DC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808006E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808006E4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808006E8: jal         0x800BBCB8
    // 0x808006EC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x808006EC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_5:
    // 0x808006F0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808006F4: jal         0x80800824
    // 0x808006F8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80800824_chtntbox(rdram, ctx);
        goto after_6;
    // 0x808006F8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x808006FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1892, 0X938) << 16);
    // 0x80800700: addiu       $a2, $a2, 0x938
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1892, 0X938));
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800708: jal         0x80089D18
    // 0x8080070C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x8080070C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_7:
    // 0x80800710: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800714: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800718: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080071C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80800720: jal         0x800E1610
    // 0x80800724: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_800E1610(rdram, ctx);
        goto after_8;
    // 0x80800724: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80800728: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080072C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80800730: jal         0x80018820
    // 0x80800734: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    func_80018820(rdram, ctx);
        goto after_9;
    // 0x80800734: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_9:
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080073C: jal         0x8010CEF8
    // 0x80800740: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    func_8010CEF8(rdram, ctx);
        goto after_10;
    // 0x80800740: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_10:
    // 0x80800744: beq         $v0, $zero, L_80800754
    if (ctx->r2 == 0) {
        // 0x80800748: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_80800754;
    }
    // 0x80800748: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8080074C: jal         0x80090494
    // 0x80800750: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80090494(rdram, ctx);
        goto after_11;
    // 0x80800750: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
L_80800754:
    // 0x80800754: jal         0x800FFAB0
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080075C: b           L_808007A0
    // 0x80800760: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808007A0;
    // 0x80800760: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800764:
    // 0x80800764: jal         0x800BFA1C
    // 0x80800768: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800BFA1C(rdram, ctx);
        goto after_13;
    // 0x80800768: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x8080076C: bne         $v0, $zero, L_80800784
    if (ctx->r2 != 0) {
        // 0x80800770: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1892, 0X8C8) << 16);
            goto L_80800784;
    }
    // 0x80800770: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1892, 0X8C8) << 16);
    // 0x80800774: jal         0x800FFAB0
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080077C: b           L_808007A0
    // 0x80800780: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808007A0;
    // 0x80800780: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800784:
    // 0x80800784: lwc1        $f16, 0x8C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1892, 0X8C8));
    // 0x80800788: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080078C: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800790: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80800794: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80800798: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x8080079C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007A0:
    // 0x808007A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808007A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808007A8: jr          $ra
    // 0x808007AC: nop

    return;
    // 0x808007AC: nop

;}
RECOMP_FUNC void func_800A7FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7FD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7FD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7FDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A7FE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7FE4: jal         0x8001B84C
    // 0x800A7FE8: sw          $t6, 0x7650($at)
    MEM_W(0X7650, ctx->r1) = ctx->r14;
    func_8001B84C(rdram, ctx);
        goto after_0;
    // 0x800A7FE8: sw          $t6, 0x7650($at)
    MEM_W(0X7650, ctx->r1) = ctx->r14;
    after_0:
    // 0x800A7FEC: jal         0x8001B840
    // 0x800A7FF0: nop

    func_8001B840(rdram, ctx);
        goto after_1;
    // 0x800A7FF0: nop

    after_1:
    // 0x800A7FF4: jal         0x80081BEC
    // 0x800A7FF8: nop

    defragment_overlays(rdram, ctx);
        goto after_2;
    // 0x800A7FF8: nop

    after_2:
    // 0x800A7FFC: jal         0x8001B518
    // 0x800A8000: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8001B518(rdram, ctx);
        goto after_3;
    // 0x800A8000: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800A8004: jal         0x801015C8
    // 0x800A8008: nop

    func_801015C8(rdram, ctx);
        goto after_4;
    // 0x800A8008: nop

    after_4:
    // 0x800A800C: jal         0x80017840
    // 0x800A8010: nop

    func_80017840(rdram, ctx);
        goto after_5;
    // 0x800A8010: nop

    after_5:
    // 0x800A8014: jal         0x800D8674
    // 0x800A8018: nop

    func_800D8674(rdram, ctx);
        goto after_6;
    // 0x800A8018: nop

    after_6:
    // 0x800A801C: jal         0x8008BA5C
    // 0x800A8020: nop

    func_8008BA5C(rdram, ctx);
        goto after_7;
    // 0x800A8020: nop

    after_7:
    // 0x800A8024: jal         0x800B5A6C
    // 0x800A8028: nop

    func_800B5A6C(rdram, ctx);
        goto after_8;
    // 0x800A8028: nop

    after_8:
    // 0x800A802C: jal         0x800A5654
    // 0x800A8030: nop

    func_800A5654(rdram, ctx);
        goto after_9;
    // 0x800A8030: nop

    after_9:
    // 0x800A8034: jal         0x800DF874
    // 0x800A8038: nop

    func_800DF874(rdram, ctx);
        goto after_10;
    // 0x800A8038: nop

    after_10:
    // 0x800A803C: jal         0x800A95C4
    // 0x800A8040: nop

    func_800A95C4(rdram, ctx);
        goto after_11;
    // 0x800A8040: nop

    after_11:
    // 0x800A8044: jal         0x800F86D8
    // 0x800A8048: nop

    func_800F86D8(rdram, ctx);
        goto after_12;
    // 0x800A8048: nop

    after_12:
    // 0x800A804C: jal         0x800F91EC
    // 0x800A8050: nop

    func_800F91EC(rdram, ctx);
        goto after_13;
    // 0x800A8050: nop

    after_13:
    // 0x800A8054: jal         0x800B562C
    // 0x800A8058: nop

    func_800B562C(rdram, ctx);
        goto after_14;
    // 0x800A8058: nop

    after_14:
    // 0x800A805C: jal         0x800BF58C
    // 0x800A8060: nop

    func_800BF58C(rdram, ctx);
        goto after_15;
    // 0x800A8060: nop

    after_15:
    // 0x800A8064: jal         0x800BD600
    // 0x800A8068: nop

    func_800BD600(rdram, ctx);
        goto after_16;
    // 0x800A8068: nop

    after_16:
    // 0x800A806C: jal         0x800CCFEC
    // 0x800A8070: nop

    func_800CCFEC(rdram, ctx);
        goto after_17;
    // 0x800A8070: nop

    after_17:
    // 0x800A8074: jal         0x800A5D6C
    // 0x800A8078: nop

    func_800A5D6C(rdram, ctx);
        goto after_18;
    // 0x800A8078: nop

    after_18:
    // 0x800A807C: jal         0x800B5E3C
    // 0x800A8080: nop

    func_800B5E3C(rdram, ctx);
        goto after_19;
    // 0x800A8080: nop

    after_19:
    // 0x800A8084: jal         0x800DA1E0
    // 0x800A8088: nop

    func_800DA1E0(rdram, ctx);
        goto after_20;
    // 0x800A8088: nop

    after_20:
    // 0x800A808C: jal         0x800D15CC
    // 0x800A8090: nop

    func_800D15CC(rdram, ctx);
        goto after_21;
    // 0x800A8090: nop

    after_21:
    // 0x800A8094: jal         0x8010E030
    // 0x800A8098: nop

    func_8010E030(rdram, ctx);
        goto after_22;
    // 0x800A8098: nop

    after_22:
    // 0x800A809C: jal         0x800C075C
    // 0x800A80A0: nop

    func_800C075C(rdram, ctx);
        goto after_23;
    // 0x800A80A0: nop

    after_23:
    // 0x800A80A4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A80A8: lh          $t7, 0x7632($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X7632);
    // 0x800A80AC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A80B0: bne         $t7, $at, L_800A80C0
    if (ctx->r15 != ctx->r1) {
        // 0x800A80B4: nop
    
            goto L_800A80C0;
    }
    // 0x800A80B4: nop

    // 0x800A80B8: jal         0x800C08C0
    // 0x800A80BC: nop

    func_800C08C0(rdram, ctx);
        goto after_24;
    // 0x800A80BC: nop

    after_24:
L_800A80C0:
    // 0x800A80C0: jal         0x801005B8
    // 0x800A80C4: nop

    func_801005B8(rdram, ctx);
        goto after_25;
    // 0x800A80C4: nop

    after_25:
    // 0x800A80C8: jal         0x800D6D68
    // 0x800A80CC: nop

    func_800D6D68(rdram, ctx);
        goto after_26;
    // 0x800A80CC: nop

    after_26:
    // 0x800A80D0: jal         0x80100E54
    // 0x800A80D4: nop

    func_80100E54(rdram, ctx);
        goto after_27;
    // 0x800A80D4: nop

    after_27:
    // 0x800A80D8: jal         0x800BFFF4
    // 0x800A80DC: nop

    func_800BFFF4(rdram, ctx);
        goto after_28;
    // 0x800A80DC: nop

    after_28:
    // 0x800A80E0: jal         0x800C9074
    // 0x800A80E4: nop

    func_800C9074(rdram, ctx);
        goto after_29;
    // 0x800A80E4: nop

    after_29:
    // 0x800A80E8: jal         0x800DBB64
    // 0x800A80EC: nop

    func_800DBB64(rdram, ctx);
        goto after_30;
    // 0x800A80EC: nop

    after_30:
    // 0x800A80F0: jal         0x800E8B3C
    // 0x800A80F4: nop

    func_800E8B3C(rdram, ctx);
        goto after_31;
    // 0x800A80F4: nop

    after_31:
    // 0x800A80F8: jal         0x800A86D8
    // 0x800A80FC: nop

    func_800A86D8(rdram, ctx);
        goto after_32;
    // 0x800A80FC: nop

    after_32:
    // 0x800A8100: jal         0x800EE670
    // 0x800A8104: nop

    func_800EE670(rdram, ctx);
        goto after_33;
    // 0x800A8104: nop

    after_33:
    // 0x800A8108: jal         0x800ABA20
    // 0x800A810C: nop

    func_800ABA20(rdram, ctx);
        goto after_34;
    // 0x800A810C: nop

    after_34:
    // 0x800A8110: jal         0x800FA608
    // 0x800A8114: nop

    func_800FA608(rdram, ctx);
        goto after_35;
    // 0x800A8114: nop

    after_35:
    // 0x800A8118: jal         0x800E8A20
    // 0x800A811C: nop

    func_800E8A20(rdram, ctx);
        goto after_36;
    // 0x800A811C: nop

    after_36:
    // 0x800A8120: jal         0x800A9D00
    // 0x800A8124: nop

    func_800A9D00(rdram, ctx);
        goto after_37;
    // 0x800A8124: nop

    after_37:
    // 0x800A8128: jal         0x800C9484
    // 0x800A812C: nop

    func_800C9484(rdram, ctx);
        goto after_38;
    // 0x800A812C: nop

    after_38:
    // 0x800A8130: jal         0x800B4380
    // 0x800A8134: nop

    func_800B4380(rdram, ctx);
        goto after_39;
    // 0x800A8134: nop

    after_39:
    // 0x800A8138: jal         0x800EB7A8
    // 0x800A813C: nop

    func_800EB7A8(rdram, ctx);
        goto after_40;
    // 0x800A813C: nop

    after_40:
    // 0x800A8140: jal         0x800D88C0
    // 0x800A8144: nop

    func_800D88C0(rdram, ctx);
        goto after_41;
    // 0x800A8144: nop

    after_41:
    // 0x800A8148: jal         0x800FFE08
    // 0x800A814C: nop

    func_800FFE08(rdram, ctx);
        goto after_42;
    // 0x800A814C: nop

    after_42:
    // 0x800A8150: jal         0x8001B858
    // 0x800A8154: nop

    func_8001B858(rdram, ctx);
        goto after_43;
    // 0x800A8154: nop

    after_43:
    // 0x800A8158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A815C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A8160: jr          $ra
    // 0x800A8164: nop

    return;
    // 0x800A8164: nop

;}
RECOMP_FUNC void chnests_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F74: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X1350) << 16);
    // 0x80800F78: jr          $ra
    // 0x80800F7C: addiu       $v0, $v0, 0x1350
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1350));
    return;
    // 0x80800F7C: addiu       $v0, $v0, 0x1350
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1350));
;}
RECOMP_FUNC void func_800C57C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C57C0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C57C4: addiu       $v0, $v0, -0x55E0
    ctx->r2 = ADD32(ctx->r2, -0X55E0);
    // 0x800C57C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C57CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C57D0: lbu         $a0, 0x8($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X8);
    // 0x800C57D4: lbu         $a1, 0x9($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X9);
    // 0x800C57D8: jal         0x800BF48C
    // 0x800C57DC: lbu         $a2, 0xA($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0XA);
    func_800BF48C(rdram, ctx);
        goto after_0;
    // 0x800C57DC: lbu         $a2, 0xA($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0XA);
    after_0:
    // 0x800C57E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C57E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C57E8: jr          $ra
    // 0x800C57EC: nop

    return;
    // 0x800C57EC: nop

;}
RECOMP_FUNC void badata_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C30: jal         0x800DC0C0
    // 0x80800C34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x80800C34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800C38: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800C3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800C44: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800C48: nop

    // 0x80800C4C: bc1f        L_80800C78
    if (!c1cs) {
        // 0x80800C50: nop
    
            goto L_80800C78;
    }
    // 0x80800C50: nop

    // 0x80800C54: jal         0x80800000
    // 0x80800C58: nop

    func_80800000_badata(rdram, ctx);
        goto after_1;
    // 0x80800C58: nop

    after_1:
    // 0x80800C5C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800C60: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80800C64: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80800C68: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X156A) << 16);
    // 0x80800C6C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800C70: b           L_80800C98
    // 0x80800C74: lh          $v0, 0x156A($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X156A));
        goto L_80800C98;
    // 0x80800C74: lh          $v0, 0x156A($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X156A));
L_80800C78:
    // 0x80800C78: jal         0x80800000
    // 0x80800C7C: nop

    func_80800000_badata(rdram, ctx);
        goto after_2;
    // 0x80800C7C: nop

    after_2:
    // 0x80800C80: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80800C84: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80800C88: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80800C8C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X156C) << 16);
    // 0x80800C90: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80800C94: lh          $v0, 0x156C($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X156C));
L_80800C98:
    // 0x80800C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CA0: jr          $ra
    // 0x80800CA4: nop

    return;
    // 0x80800CA4: nop

;}
RECOMP_FUNC void func_800F1FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1FF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F1FF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1FF8: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x800F1FFC: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x800F2000: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F2004: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800F2008: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F200C: jal         0x800F1DCC
    // 0x800F2010: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    func_800F1DCC(rdram, ctx);
        goto after_0;
    // 0x800F2010: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x800F2014: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800F2018: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F201C: jal         0x800F2100
    // 0x800F2020: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x800F2020: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800F2024: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800F2028: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F202C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800F2030: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800F2034: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F2038: bc1fl       L_800F204C
    if (!c1cs) {
        // 0x800F203C: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_800F204C;
    }
    goto skip_0;
    // 0x800F203C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x800F2040: b           L_800F2084
    // 0x800F2044: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
        goto L_800F2084;
    // 0x800F2044: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F2048: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_800F204C:
    // 0x800F204C: nop

    // 0x800F2050: bc1f        L_800F207C
    if (!c1cs) {
        // 0x800F2054: nop
    
            goto L_800F207C;
    }
    // 0x800F2054: nop

    // 0x800F2058: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800F205C: nop

    // 0x800F2060: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800F2064: nop

    // 0x800F2068: bc1fl       L_800F207C
    if (!c1cs) {
        // 0x800F206C: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_800F207C;
    }
    goto skip_1;
    // 0x800F206C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    skip_1:
    // 0x800F2070: b           L_800F207C
    // 0x800F2074: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
        goto L_800F207C;
    // 0x800F2074: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x800F2078: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800F207C:
    // 0x800F207C: jal         0x800136E4
    // 0x800F2080: add.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f2.fl;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x800F2080: add.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f2.fl;
    after_2:
L_800F2084:
    // 0x800F2084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F2088: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F208C: jr          $ra
    // 0x800F2090: nop

    return;
    // 0x800F2090: nop

;}
RECOMP_FUNC void func_80801038_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801038: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080103C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80801040: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80801044: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80801048: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8080104C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80801050: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80801054: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80801058: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080105C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801060: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801064: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801068: jal         0x80088750
    // 0x8080106C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _gldialog_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x8080106C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80801070: sw          $v0, 0x100($s4)
    MEM_W(0X100, ctx->r20) = ctx->r2;
    // 0x80801074: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801078: or          $s3, $s4, $zero
    ctx->r19 = ctx->r20 | 0;
    // 0x8080107C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80801080: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x80801084: addiu       $s7, $zero, 0x79
    ctx->r23 = ADD32(0, 0X79);
    // 0x80801088: addiu       $s6, $zero, 0x51
    ctx->r22 = ADD32(0, 0X51);
    // 0x8080108C: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
L_80801090:
    // 0x80801090: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80801094: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801098: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080109C: andi        $a0, $t6, 0xFF
    ctx->r4 = ctx->r14 & 0XFF;
    // 0x808010A0: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x808010A4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x808010A8: jal         0x8001ACCC
    // 0x808010AC: sb          $t6, 0x114($s3)
    MEM_B(0X114, ctx->r19) = ctx->r14;
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x808010AC: sb          $t6, 0x114($s3)
    MEM_B(0X114, ctx->r19) = ctx->r14;
    after_1:
    // 0x808010B0: sw          $v0, 0x104($s2)
    MEM_W(0X104, ctx->r18) = ctx->r2;
    // 0x808010B4: lbu         $t8, 0x114($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X114);
    // 0x808010B8: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x808010BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808010C0: blezl       $t8, L_80801168
    if (SIGNED(ctx->r24) <= 0) {
        // 0x808010C4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80801168;
    }
    goto skip_0;
    // 0x808010C4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_0:
    // 0x808010C8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_808010CC:
    // 0x808010CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808010D0: blez        $v0, L_808010FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808010D4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_808010FC;
    }
    // 0x808010D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808010D8: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x808010DC: beql        $at, $zero, L_80801100
    if (ctx->r1 == 0) {
        // 0x808010E0: slti        $at, $v1, 0x80
        ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_80801100;
    }
    goto skip_1;
    // 0x808010E0: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    skip_1:
    // 0x808010E4: bne         $s5, $v1, L_80801110
    if (ctx->r21 != ctx->r3) {
        // 0x808010E8: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_80801110;
    }
    // 0x808010E8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x808010EC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x808010F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808010F4: b           L_80801110
    // 0x808010F8: addiu       $v0, $v0, 0x75
    ctx->r2 = ADD32(ctx->r2, 0X75);
        goto L_80801110;
    // 0x808010F8: addiu       $v0, $v0, 0x75
    ctx->r2 = ADD32(ctx->r2, 0X75);
L_808010FC:
    // 0x808010FC: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
L_80801100:
    // 0x80801100: bne         $at, $zero, L_80801110
    if (ctx->r1 != 0) {
        // 0x80801104: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80801110;
    }
    // 0x80801104: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801108: b           L_80801110
    // 0x8080110C: addiu       $v0, $v1, -0x80
    ctx->r2 = ADD32(ctx->r3, -0X80);
        goto L_80801110;
    // 0x8080110C: addiu       $v0, $v1, -0x80
    ctx->r2 = ADD32(ctx->r3, -0X80);
L_80801110:
    // 0x80801110: beql        $v0, $s6, L_80801124
    if (ctx->r2 == ctx->r22) {
        // 0x80801114: lbu         $v0, 0x167($s4)
        ctx->r2 = MEM_BU(ctx->r20, 0X167);
            goto L_80801124;
    }
    goto skip_2;
    // 0x80801114: lbu         $v0, 0x167($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X167);
    skip_2:
    // 0x80801118: bnel        $v0, $s7, L_8080112C
    if (ctx->r2 != ctx->r23) {
        // 0x8080111C: lw          $t9, 0x104($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X104);
            goto L_8080112C;
    }
    goto skip_3;
    // 0x8080111C: lw          $t9, 0x104($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X104);
    skip_3:
    // 0x80801120: lbu         $v0, 0x167($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X167);
L_80801124:
    // 0x80801124: addiu       $v0, $v0, -0xC
    ctx->r2 = ADD32(ctx->r2, -0XC);
    // 0x80801128: lw          $t9, 0x104($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X104);
L_8080112C:
    // 0x8080112C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801130: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801134: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x80801138: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    // 0x8080113C: lw          $t1, 0x104($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X104);
    // 0x80801140: lbu         $v1, -0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, -0X1);
    // 0x80801144: addu        $t2, $t1, $a0
    ctx->r10 = ADD32(ctx->r9, ctx->r4);
    // 0x80801148: sw          $s0, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r16;
    // 0x8080114C: lbu         $t3, 0x114($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X114);
    // 0x80801150: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80801154: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x80801158: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8080115C: bnel        $at, $zero, L_808010CC
    if (ctx->r1 != 0) {
        // 0x80801160: lbu         $v0, 0x0($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X0);
            goto L_808010CC;
    }
    goto skip_4;
    // 0x80801160: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    skip_4:
    // 0x80801164: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_80801168:
    // 0x80801168: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8080116C: bne         $fp, $at, L_80801090
    if (ctx->r30 != ctx->r1) {
        // 0x80801170: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80801090;
    }
    // 0x80801170: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80801174: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80801178: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080117C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801180: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801184: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801188: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8080118C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80801190: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80801194: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80801198: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8080119C: jr          $ra
    // 0x808011A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x808011A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void bsbeefly_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B40: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800B44: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(76, 0XE50) << 16);
    // 0x80800B48: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800B4C: jr          $ra
    // 0x80800B50: lw          $v0, 0xE50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(76, 0XE50));
    return;
    // 0x80800B50: lw          $v0, 0xE50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(76, 0XE50));
;}
RECOMP_FUNC void func_80801D40_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D40: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80801D44: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80801D48: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801D4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D50: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80801D54: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80801D58: sw          $a2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r6;
    // 0x80801D5C: jal         0x80100094
    // 0x80801D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801D64: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80801D68: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80801D6C: slti        $at, $a2, 0x55
    ctx->r1 = SIGNED(ctx->r6) < 0X55 ? 1 : 0;
    // 0x80801D70: bne         $at, $zero, L_80801D98
    if (ctx->r1 != 0) {
        // 0x80801D74: addiu       $t6, $a2, -0x2E
        ctx->r14 = ADD32(ctx->r6, -0X2E);
            goto L_80801D98;
    }
    // 0x80801D74: addiu       $t6, $a2, -0x2E
    ctx->r14 = ADD32(ctx->r6, -0X2E);
    // 0x80801D78: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80801D7C: beq         $a2, $at, L_80801DE0
    if (ctx->r6 == ctx->r1) {
        // 0x80801D80: lw          $t8, 0x74($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X74);
            goto L_80801DE0;
    }
    // 0x80801D80: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80801D84: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x80801D88: beq         $a2, $at, L_80801E10
    if (ctx->r6 == ctx->r1) {
        // 0x80801D8C: nop
    
            goto L_80801E10;
    }
    // 0x80801D8C: nop

    // 0x80801D90: b           L_80802524
    // 0x80801D94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802524;
    // 0x80801D94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801D98:
    // 0x80801D98: slti        $at, $a2, 0xE
    ctx->r1 = SIGNED(ctx->r6) < 0XE ? 1 : 0;
    // 0x80801D9C: bne         $at, $zero, L_80801DC0
    if (ctx->r1 != 0) {
        // 0x80801DA0: sltiu       $at, $t6, 0x27
        ctx->r1 = ctx->r14 < 0X27 ? 1 : 0;
            goto L_80801DC0;
    }
    // 0x80801DA0: sltiu       $at, $t6, 0x27
    ctx->r1 = ctx->r14 < 0X27 ? 1 : 0;
    // 0x80801DA4: beq         $at, $zero, L_80801DD8
    if (ctx->r1 == 0) {
        // 0x80801DA8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801DD8;
    }
    // 0x80801DA8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801DAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5128) << 16);
    // 0x80801DB0: addu        $at, $at, $t6
    gpr jr_addend_80801DB8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801DB4: lw          $t6, 0x5128($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5128));
    // 0x80801DB8: jr          $t6
    // 0x80801DBC: nop

    switch (jr_addend_80801DB8 >> 2) {
        case 0: goto L_80802094; break;
        case 1: goto L_80802284; break;
        case 2: goto L_80801DD8; break;
        case 3: goto L_80801DD8; break;
        case 4: goto L_80801DD8; break;
        case 5: goto L_80801DD8; break;
        case 6: goto L_80801DD8; break;
        case 7: goto L_80801DD8; break;
        case 8: goto L_80801DD8; break;
        case 9: goto L_80801DD8; break;
        case 10: goto L_80801DD8; break;
        case 11: goto L_80801DD8; break;
        case 12: goto L_80801DD8; break;
        case 13: goto L_80801DD8; break;
        case 14: goto L_80801DD8; break;
        case 15: goto L_80801E40; break;
        case 16: goto L_80801FF0; break;
        case 17: goto L_80801DD8; break;
        case 18: goto L_80801DD8; break;
        case 19: goto L_80801DD8; break;
        case 20: goto L_80801DD8; break;
        case 21: goto L_80801DD8; break;
        case 22: goto L_80801DD8; break;
        case 23: goto L_80801DD8; break;
        case 24: goto L_80801DD8; break;
        case 25: goto L_80801DD8; break;
        case 26: goto L_80801DD8; break;
        case 27: goto L_80801DD8; break;
        case 28: goto L_80801DD8; break;
        case 29: goto L_80801DD8; break;
        case 30: goto L_80801DD8; break;
        case 31: goto L_80801DD8; break;
        case 32: goto L_80801DD8; break;
        case 33: goto L_80801DD8; break;
        case 34: goto L_80801DD8; break;
        case 35: goto L_80801DD8; break;
        case 36: goto L_80802434; break;
        case 37: goto L_80801DD8; break;
        case 38: goto L_80801ED0; break;
        default: switch_error(__func__, 0x80801DB8, 0x80805128);
    }
    // 0x80801DBC: nop

L_80801DC0:
    // 0x80801DC0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80801DC4: beq         $a2, $at, L_8080239C
    if (ctx->r6 == ctx->r1) {
        // 0x80801DC8: lw          $v0, 0x80($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X80);
            goto L_8080239C;
    }
    // 0x80801DC8: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x80801DCC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80801DD0: beq         $a2, $at, L_80802378
    if (ctx->r6 == ctx->r1) {
        // 0x80801DD4: nop
    
            goto L_80802378;
    }
    // 0x80801DD4: nop

L_80801DD8:
    // 0x80801DD8: b           L_80802524
    // 0x80801DDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802524;
    // 0x80801DDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801DE0:
    // 0x80801DE0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80801DE4: jal         0x800D395C
    // 0x80801DE8: sb          $t7, 0x63($t8)
    MEM_B(0X63, ctx->r24) = ctx->r15;
    func_800D395C(rdram, ctx);
        goto after_1;
    // 0x80801DE8: sb          $t7, 0x63($t8)
    MEM_B(0X63, ctx->r24) = ctx->r15;
    after_1:
    // 0x80801DEC: bne         $v0, $zero, L_80801DFC
    if (ctx->r2 != 0) {
        // 0x80801DF0: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80801DFC;
    }
    // 0x80801DF0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801DF4: b           L_80802524
    // 0x80801DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80802524;
    // 0x80801DF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801DFC:
    // 0x80801DFC: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80801E00: jal         0x80800D20
    // 0x80801E04: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_80800D20_chdragonbrothers(rdram, ctx);
        goto after_2;
    // 0x80801E04: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_2:
    // 0x80801E08: b           L_80802524
    // 0x80801E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80801E0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801E10:
    // 0x80801E10: jal         0x800FDC28
    // 0x80801E14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_3;
    // 0x80801E14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80801E18: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80801E1C: sb          $zero, 0x59($t9)
    MEM_B(0X59, ctx->r25) = 0;
    // 0x80801E20: jal         0x80800438
    // 0x80801E24: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80800438_chdragonbrothers(rdram, ctx);
        goto after_4;
    // 0x80801E24: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_4:
    // 0x80801E28: beq         $v0, $zero, L_80802520
    if (ctx->r2 == 0) {
        // 0x80801E2C: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80802520;
    }
    // 0x80801E2C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801E30: jal         0x808004A4
    // 0x80801E34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808004A4_chdragonbrothers(rdram, ctx);
        goto after_5;
    // 0x80801E34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80801E38: b           L_80802524
    // 0x80801E3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80801E3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801E40:
    // 0x80801E40: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1852, 0X5608) << 16);
    // 0x80801E44: addiu       $t0, $t0, 0x5608
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1852, 0X5608));
    // 0x80801E48: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80801E4C: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x80801E50: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801E54: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x80801E58: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x80801E5C: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x80801E60: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80801E64: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x80801E68: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80801E6C: jal         0x800EF934
    // 0x80801E70: lw          $a2, 0x48($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X48);
    func_800EF934(rdram, ctx);
        goto after_6;
    // 0x80801E70: lw          $a2, 0x48($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X48);
    after_6:
    // 0x80801E74: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80801E78: addiu       $a0, $zero, 0x379
    ctx->r4 = ADD32(0, 0X379);
    // 0x80801E7C: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80801E80: lwc1        $f4, 0x48($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X48);
    // 0x80801E84: addiu       $a3, $sp, 0x78
    ctx->r7 = ADD32(ctx->r29, 0X78);
    // 0x80801E88: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80801E8C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80801E90: jal         0x80108528
    // 0x80801E94: nop

    func_80108528(rdram, ctx);
        goto after_7;
    // 0x80801E94: nop

    after_7:
    // 0x80801E98: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80801E9C: lbu         $t2, 0x65($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X65);
    // 0x80801EA0: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80801EA4: andi        $t3, $t2, 0xFFF7
    ctx->r11 = ctx->r10 & 0XFFF7;
    // 0x80801EA8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80801EAC: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80801EB0: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x80801EB4: andi        $t0, $t1, 0x8
    ctx->r8 = ctx->r9 & 0X8;
    // 0x80801EB8: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x80801EBC: sb          $t4, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r12;
    // 0x80801EC0: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80801EC4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80801EC8: b           L_80802520
    // 0x80801ECC: sw          $t6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r14;
        goto L_80802520;
    // 0x80801ECC: sw          $t6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r14;
L_80801ED0:
    // 0x80801ED0: jal         0x80106790
    // 0x80801ED4: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    func_80106790(rdram, ctx);
        goto after_8;
    // 0x80801ED4: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_8:
    // 0x80801ED8: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80801EDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801EE0: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x80801EE4: bgtzl       $t7, L_80801EF8
    if (SIGNED(ctx->r15) > 0) {
        // 0x80801EE8: lhu         $t8, 0x76($v0)
        ctx->r24 = MEM_HU(ctx->r2, 0X76);
            goto L_80801EF8;
    }
    goto skip_0;
    // 0x80801EE8: lhu         $t8, 0x76($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X76);
    skip_0:
    // 0x80801EEC: b           L_80802524
    // 0x80801EF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80801EF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801EF4: lhu         $t8, 0x76($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X76);
L_80801EF8:
    // 0x80801EF8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801EFC: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80801F00: addu        $v1, $a2, $t9
    ctx->r3 = ADD32(ctx->r6, ctx->r25);
    // 0x80801F04: lb          $t1, 0x8($v1)
    ctx->r9 = MEM_B(ctx->r3, 0X8);
    // 0x80801F08: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80801F0C: sb          $t2, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r10;
    // 0x80801F10: lbu         $a0, 0x79($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X79);
    // 0x80801F14: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80801F18: srl         $t0, $a0, 4
    ctx->r8 = S32(U32(ctx->r4) >> 4);
    // 0x80801F1C: bne         $t0, $at, L_80801F30
    if (ctx->r8 != ctx->r1) {
        // 0x80801F20: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80801F30;
    }
    // 0x80801F20: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80801F24: lbu         $t4, 0x7A($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X7A);
    // 0x80801F28: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80801F2C: bne         $t5, $zero, L_80801F4C
    if (ctx->r13 != 0) {
        // 0x80801F30: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801F4C;
    }
L_80801F30:
    // 0x80801F30: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801F34: bne         $a0, $at, L_80801F5C
    if (ctx->r4 != ctx->r1) {
        // 0x80801F38: lw          $t6, 0x78($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X78);
            goto L_80801F5C;
    }
    // 0x80801F38: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x80801F3C: lbu         $t7, 0x7A($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X7A);
    // 0x80801F40: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80801F44: bnel        $t8, $zero, L_80801F60
    if (ctx->r24 != 0) {
        // 0x80801F48: lw          $t9, 0x78($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X78);
            goto L_80801F60;
    }
    goto skip_1;
    // 0x80801F48: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    skip_1:
L_80801F4C:
    // 0x80801F4C: jal         0x80801924
    // 0x80801F50: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    func_80801924_chdragonbrothers(rdram, ctx);
        goto after_9;
    // 0x80801F50: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_9:
    // 0x80801F54: b           L_80802524
    // 0x80801F58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80801F58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801F5C:
    // 0x80801F5C: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
L_80801F60:
    // 0x80801F60: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80801F64: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80801F68: lhu         $v0, 0x72($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X72);
    // 0x80801F6C: srl         $t1, $v0, 10
    ctx->r9 = S32(U32(ctx->r2) >> 10);
    // 0x80801F70: beq         $t1, $at, L_80801F90
    if (ctx->r9 == ctx->r1) {
        // 0x80801F74: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80801F90;
    }
    // 0x80801F74: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80801F78: beq         $t1, $at, L_80801F90
    if (ctx->r9 == ctx->r1) {
        // 0x80801F7C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80801F90;
    }
    // 0x80801F7C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80801F80: beq         $t1, $at, L_80801F90
    if (ctx->r9 == ctx->r1) {
        // 0x80801F84: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80801F90;
    }
    // 0x80801F84: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80801F88: bnel        $t1, $at, L_80802524
    if (ctx->r9 != ctx->r1) {
        // 0x80801F8C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802524;
    }
    goto skip_2;
    // 0x80801F8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
L_80801F90:
    // 0x80801F90: lbu         $t0, 0x7A($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X7A);
    // 0x80801F94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801F98: addiu       $a0, $zero, 0x1D8
    ctx->r4 = ADD32(0, 0X1D8);
    // 0x80801F9C: andi        $t3, $t0, 0x1
    ctx->r11 = ctx->r8 & 0X1;
    // 0x80801FA0: beq         $t3, $zero, L_80801FCC
    if (ctx->r11 == 0) {
        // 0x80801FA4: nop
    
            goto L_80801FCC;
    }
    // 0x80801FA4: nop

    // 0x80801FA8: jal         0x800DA9E4
    // 0x80801FAC: addiu       $a0, $zero, 0x1D7
    ctx->r4 = ADD32(0, 0X1D7);
    func_800DA9E4(rdram, ctx);
        goto after_10;
    // 0x80801FAC: addiu       $a0, $zero, 0x1D7
    ctx->r4 = ADD32(0, 0X1D7);
    after_10:
    // 0x80801FB0: bne         $v0, $zero, L_80802520
    if (ctx->r2 != 0) {
        // 0x80801FB4: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80802520;
    }
    // 0x80801FB4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801FB8: addiu       $a1, $zero, 0x129E
    ctx->r5 = ADD32(0, 0X129E);
    // 0x80801FBC: jal         0x80800D20
    // 0x80801FC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800D20_chdragonbrothers(rdram, ctx);
        goto after_11;
    // 0x80801FC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x80801FC4: b           L_80802524
    // 0x80801FC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80801FC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801FCC:
    // 0x80801FCC: jal         0x800DA9E4
    // 0x80801FD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_12;
    // 0x80801FD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80801FD4: bne         $v0, $zero, L_80802520
    if (ctx->r2 != 0) {
        // 0x80801FD8: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80802520;
    }
    // 0x80801FD8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80801FDC: addiu       $a1, $zero, 0x129F
    ctx->r5 = ADD32(0, 0X129F);
    // 0x80801FE0: jal         0x80800D20
    // 0x80801FE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800D20_chdragonbrothers(rdram, ctx);
        goto after_13;
    // 0x80801FE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80801FE8: b           L_80802524
    // 0x80801FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80801FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801FF0:
    // 0x80801FF0: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80801FF4: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80801FF8: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80801FFC: lhu         $t5, 0x64($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X64);
    // 0x80802000: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80802004: beql        $t6, $zero, L_80802524
    if (ctx->r14 == 0) {
        // 0x80802008: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802524;
    }
    goto skip_3;
    // 0x80802008: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x8080200C: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80802010: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x80802014: bnel        $t9, $zero, L_80802524
    if (ctx->r25 != 0) {
        // 0x80802018: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802524;
    }
    goto skip_4;
    // 0x80802018: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x8080201C: lhu         $t2, 0x72($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X72);
    // 0x80802020: srl         $t0, $t2, 10
    ctx->r8 = S32(U32(ctx->r10) >> 10);
    // 0x80802024: addiu       $t3, $t0, -0x8
    ctx->r11 = ADD32(ctx->r8, -0X8);
    // 0x80802028: sltiu       $at, $t3, 0xB
    ctx->r1 = ctx->r11 < 0XB ? 1 : 0;
    // 0x8080202C: beq         $at, $zero, L_80802520
    if (ctx->r1 == 0) {
        // 0x80802030: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80802520;
    }
    // 0x80802030: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80802034: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X51C4) << 16);
    // 0x80802038: addu        $at, $at, $t3
    gpr jr_addend_80802040 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8080203C: lw          $t3, 0x51C4($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X51C4));
    // 0x80802040: jr          $t3
    // 0x80802044: nop

    switch (jr_addend_80802040 >> 2) {
        case 0: goto L_80802048; break;
        case 1: goto L_80802048; break;
        case 2: goto L_80802048; break;
        case 3: goto L_80802048; break;
        case 4: goto L_80802048; break;
        case 5: goto L_80802048; break;
        case 6: goto L_80802048; break;
        case 7: goto L_80802048; break;
        case 8: goto L_80802048; break;
        case 9: goto L_80802048; break;
        case 10: goto L_80802048; break;
        default: switch_error(__func__, 0x80802040, 0x808051C4);
    }
    // 0x80802044: nop

L_80802048:
    // 0x80802048: jal         0x800F54E4
    // 0x8080204C: nop

    func_800F54E4(rdram, ctx);
        goto after_14;
    // 0x8080204C: nop

    after_14:
    // 0x80802050: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80802054: jal         0x800F6438
    // 0x80802058: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_15;
    // 0x80802058: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_15:
    // 0x8080205C: beql        $v0, $zero, L_80802524
    if (ctx->r2 == 0) {
        // 0x80802060: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802524;
    }
    goto skip_5;
    // 0x80802060: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_5:
    // 0x80802064: jal         0x800F6AA4
    // 0x80802068: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    func_800F6AA4(rdram, ctx);
        goto after_16;
    // 0x80802068: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_16:
    // 0x8080206C: bnel        $v0, $zero, L_80802524
    if (ctx->r2 != 0) {
        // 0x80802070: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802524;
    }
    goto skip_6;
    // 0x80802070: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_6:
    // 0x80802074: jal         0x800F6478
    // 0x80802078: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    func_800F6478(rdram, ctx);
        goto after_17;
    // 0x80802078: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_17:
    // 0x8080207C: beq         $v0, $zero, L_80802520
    if (ctx->r2 == 0) {
        // 0x80802080: lw          $a0, 0x5C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X5C);
            goto L_80802520;
    }
    // 0x80802080: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80802084: jal         0x800F7B9C
    // 0x80802088: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    func_800F7B9C(rdram, ctx);
        goto after_18;
    // 0x80802088: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_18:
    // 0x8080208C: b           L_80802524
    // 0x80802090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80802090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802094:
    // 0x80802094: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x80802098: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x8080209C: addiu       $at, $zero, 0xCEB
    ctx->r1 = ADD32(0, 0XCEB);
    // 0x808020A0: bnel        $v1, $at, L_808020DC
    if (ctx->r3 != ctx->r1) {
        // 0x808020A4: lw          $t5, 0x10($v0)
        ctx->r13 = MEM_W(ctx->r2, 0X10);
            goto L_808020DC;
    }
    goto skip_7;
    // 0x808020A4: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    skip_7:
    // 0x808020A8: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x808020AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808020B0: bne         $t4, $at, L_808020C8
    if (ctx->r12 != ctx->r1) {
        // 0x808020B4: nop
    
            goto L_808020C8;
    }
    // 0x808020B4: nop

    // 0x808020B8: jal         0x80088188
    // 0x808020BC: nop

    _gcfrontend_entrypoint_11(rdram, ctx);
        goto after_19;
    // 0x808020BC: nop

    after_19:
    // 0x808020C0: b           L_80802524
    // 0x808020C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x808020C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808020C8:
    // 0x808020C8: jal         0x80088180
    // 0x808020CC: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_20;
    // 0x808020CC: nop

    after_20:
    // 0x808020D0: b           L_80802524
    // 0x808020D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x808020D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808020D8: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
L_808020DC:
    // 0x808020DC: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x808020E0: sltiu       $at, $t6, 0xD
    ctx->r1 = ctx->r14 < 0XD ? 1 : 0;
    // 0x808020E4: beq         $at, $zero, L_8080225C
    if (ctx->r1 == 0) {
        // 0x808020E8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080225C;
    }
    // 0x808020E8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808020EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X51F0) << 16);
    // 0x808020F0: addu        $at, $at, $t6
    gpr jr_addend_808020F8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808020F4: lw          $t6, 0x51F0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X51F0));
    // 0x808020F8: jr          $t6
    // 0x808020FC: nop

    switch (jr_addend_808020F8 >> 2) {
        case 0: goto L_80802108; break;
        case 1: goto L_80802180; break;
        case 2: goto L_80802188; break;
        case 3: goto L_8080225C; break;
        case 4: goto L_8080225C; break;
        case 5: goto L_808021D0; break;
        case 6: goto L_80802100; break;
        case 7: goto L_8080225C; break;
        case 8: goto L_8080225C; break;
        case 9: goto L_8080225C; break;
        case 10: goto L_8080225C; break;
        case 11: goto L_80802218; break;
        case 12: goto L_80802218; break;
        default: switch_error(__func__, 0x808020F8, 0x808051F0);
    }
    // 0x808020FC: nop

L_80802100:
    // 0x80802100: b           L_80802524
    // 0x80802104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80802104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802108:
    // 0x80802108: addiu       $t7, $v1, -0x1296
    ctx->r15 = ADD32(ctx->r3, -0X1296);
    // 0x8080210C: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x80802110: beq         $at, $zero, L_80802178
    if (ctx->r1 == 0) {
        // 0x80802114: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80802178;
    }
    // 0x80802114: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80802118: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5224) << 16);
    // 0x8080211C: addu        $at, $at, $t7
    gpr jr_addend_80802124 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80802120: lw          $t7, 0x5224($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5224));
    // 0x80802124: jr          $t7
    // 0x80802128: nop

    switch (jr_addend_80802124 >> 2) {
        case 0: goto L_8080212C; break;
        case 1: goto L_8080212C; break;
        case 2: goto L_8080212C; break;
        case 3: goto L_8080212C; break;
        case 4: goto L_8080212C; break;
        case 5: goto L_8080212C; break;
        case 6: goto L_8080212C; break;
        case 7: goto L_8080212C; break;
        default: switch_error(__func__, 0x80802124, 0x80805224);
    }
    // 0x80802128: nop

L_8080212C:
    // 0x8080212C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80802130: lbu         $t9, 0x7A($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X7A);
    // 0x80802134: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x80802138: beq         $t1, $zero, L_80802150
    if (ctx->r9 == 0) {
        // 0x8080213C: nop
    
            goto L_80802150;
    }
    // 0x8080213C: nop

    // 0x80802140: jal         0x800FDC28
    // 0x80802144: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800FDC28(rdram, ctx);
        goto after_21;
    // 0x80802144: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_21:
    // 0x80802148: b           L_8080215C
    // 0x8080214C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
        goto L_8080215C;
    // 0x8080214C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_80802150:
    // 0x80802150: jal         0x800FDC28
    // 0x80802154: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    func_800FDC28(rdram, ctx);
        goto after_22;
    // 0x80802154: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_22:
    // 0x80802158: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_8080215C:
    // 0x8080215C: jal         0x80800B34
    // 0x80802160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800B34_chdragonbrothers(rdram, ctx);
        goto after_23;
    // 0x80802160: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80802164: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80802168: jal         0x808012B4
    // 0x8080216C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_24;
    // 0x8080216C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_24:
    // 0x80802170: b           L_80802268
    // 0x80802174: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
        goto L_80802268;
    // 0x80802174: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_80802178:
    // 0x80802178: b           L_80802524
    // 0x8080217C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x8080217C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802180:
    // 0x80802180: b           L_80802524
    // 0x80802184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80802184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802188:
    // 0x80802188: addiu       $at, $zero, 0x12A1
    ctx->r1 = ADD32(0, 0X12A1);
    // 0x8080218C: beq         $v1, $at, L_808021B8
    if (ctx->r3 == ctx->r1) {
        // 0x80802190: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808021B8;
    }
    // 0x80802190: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80802194: addiu       $at, $zero, 0x12A2
    ctx->r1 = ADD32(0, 0X12A2);
    // 0x80802198: beq         $v1, $at, L_808021B8
    if (ctx->r3 == ctx->r1) {
        // 0x8080219C: addiu       $at, $zero, 0x12A3
        ctx->r1 = ADD32(0, 0X12A3);
            goto L_808021B8;
    }
    // 0x8080219C: addiu       $at, $zero, 0x12A3
    ctx->r1 = ADD32(0, 0X12A3);
    // 0x808021A0: beq         $v1, $at, L_80802264
    if (ctx->r3 == ctx->r1) {
        // 0x808021A4: addiu       $at, $zero, 0x12A4
        ctx->r1 = ADD32(0, 0X12A4);
            goto L_80802264;
    }
    // 0x808021A4: addiu       $at, $zero, 0x12A4
    ctx->r1 = ADD32(0, 0X12A4);
    // 0x808021A8: beql        $v1, $at, L_80802268
    if (ctx->r3 == ctx->r1) {
        // 0x808021AC: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80802268;
    }
    goto skip_8;
    // 0x808021AC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    skip_8:
    // 0x808021B0: b           L_80802524
    // 0x808021B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x808021B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808021B8:
    // 0x808021B8: jal         0x808012B4
    // 0x808021BC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_25;
    // 0x808021BC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_25:
    // 0x808021C0: b           L_80802268
    // 0x808021C4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
        goto L_80802268;
    // 0x808021C4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808021C8: b           L_80802524
    // 0x808021CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x808021CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808021D0:
    // 0x808021D0: addiu       $at, $zero, 0x12A5
    ctx->r1 = ADD32(0, 0X12A5);
    // 0x808021D4: beq         $v1, $at, L_808021E8
    if (ctx->r3 == ctx->r1) {
        // 0x808021D8: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808021E8;
    }
    // 0x808021D8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808021DC: addiu       $at, $zero, 0x12A6
    ctx->r1 = ADD32(0, 0X12A6);
    // 0x808021E0: bnel        $v1, $at, L_80802268
    if (ctx->r3 != ctx->r1) {
        // 0x808021E4: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80802268;
    }
    goto skip_9;
    // 0x808021E4: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    skip_9:
L_808021E8:
    // 0x808021E8: jal         0x808012B4
    // 0x808021EC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_26;
    // 0x808021EC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_26:
    // 0x808021F0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808021F4: jal         0x80800B34
    // 0x808021F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800B34_chdragonbrothers(rdram, ctx);
        goto after_27;
    // 0x808021F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x808021FC: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x80802200: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80802204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802208: jal         0x80800B9C
    // 0x8080220C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_80800B9C_chdragonbrothers(rdram, ctx);
        goto after_28;
    // 0x8080220C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_28:
    // 0x80802210: b           L_80802268
    // 0x80802214: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
        goto L_80802268;
    // 0x80802214: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_80802218:
    // 0x80802218: addiu       $at, $zero, 0x12AE
    ctx->r1 = ADD32(0, 0X12AE);
    // 0x8080221C: beq         $v1, $at, L_80802230
    if (ctx->r3 == ctx->r1) {
        // 0x80802220: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_80802230;
    }
    // 0x80802220: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80802224: addiu       $at, $zero, 0x12AF
    ctx->r1 = ADD32(0, 0X12AF);
    // 0x80802228: bne         $v1, $at, L_80802254
    if (ctx->r3 != ctx->r1) {
        // 0x8080222C: nop
    
            goto L_80802254;
    }
    // 0x8080222C: nop

L_80802230:
    // 0x80802230: jal         0x80800B34
    // 0x80802234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800B34_chdragonbrothers(rdram, ctx);
        goto after_29;
    // 0x80802234: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80802238: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x8080223C: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80802240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802244: jal         0x80800B9C
    // 0x80802248: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_80800B9C_chdragonbrothers(rdram, ctx);
        goto after_30;
    // 0x80802248: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_30:
    // 0x8080224C: b           L_80802268
    // 0x80802250: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
        goto L_80802268;
    // 0x80802250: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_80802254:
    // 0x80802254: b           L_80802524
    // 0x80802258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80802258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080225C:
    // 0x8080225C: b           L_80802524
    // 0x80802260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80802260: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802264:
    // 0x80802264: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_80802268:
    // 0x80802268: jal         0x80800D98
    // 0x8080226C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_31;
    // 0x8080226C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_31:
    // 0x80802270: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80802274: lbu         $t0, 0x74($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X74);
    // 0x80802278: andi        $t3, $t0, 0xFFBF
    ctx->r11 = ctx->r8 & 0XFFBF;
    // 0x8080227C: b           L_80802520
    // 0x80802280: sb          $t3, 0x74($t2)
    MEM_B(0X74, ctx->r10) = ctx->r11;
        goto L_80802520;
    // 0x80802280: sb          $t3, 0x74($t2)
    MEM_B(0X74, ctx->r10) = ctx->r11;
L_80802284:
    // 0x80802284: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x80802288: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x8080228C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802290: bnel        $t4, $at, L_80802524
    if (ctx->r12 != ctx->r1) {
        // 0x80802294: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802524;
    }
    goto skip_10;
    // 0x80802294: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_10:
    // 0x80802298: jal         0x800D395C
    // 0x8080229C: nop

    func_800D395C(rdram, ctx);
        goto after_32;
    // 0x8080229C: nop

    after_32:
    // 0x808022A0: bne         $v0, $zero, L_80802520
    if (ctx->r2 != 0) {
        // 0x808022A4: addiu       $a0, $zero, 0x3D
        ctx->r4 = ADD32(0, 0X3D);
            goto L_80802520;
    }
    // 0x808022A4: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x808022A8: jal         0x800D0A9C
    // 0x808022AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_33;
    // 0x808022AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x808022B0: bne         $v0, $zero, L_80802520
    if (ctx->r2 != 0) {
        // 0x808022B4: lui         $t6, 0x8080
        ctx->r14 = S32(RELOC_HI16(1852, 0X5614) << 16);
            goto L_80802520;
    }
    // 0x808022B4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1852, 0X5614) << 16);
    // 0x808022B8: addiu       $t6, $t6, 0x5614
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1852, 0X5614));
    // 0x808022BC: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x808022C0: addiu       $t5, $sp, 0x4C
    ctx->r13 = ADD32(ctx->r29, 0X4C);
    // 0x808022C4: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x808022C8: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x808022CC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x808022D0: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x808022D4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808022D8: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x808022DC: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x808022E0: lwc1        $f14, 0x18($t9)
    ctx->f14.u32l = MEM_W(ctx->r25, 0X18);
    // 0x808022E4: jal         0x800F2094
    // 0x808022E8: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    func_800F2094(rdram, ctx);
        goto after_34;
    // 0x808022E8: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    after_34:
    // 0x808022EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808022F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808022F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808022F8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808022FC: nop

    // 0x80802300: bc1fl       L_80802354
    if (!c1cs) {
        // 0x80802304: lw          $t1, 0x78($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X78);
            goto L_80802354;
    }
    goto skip_11;
    // 0x80802304: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    skip_11:
    // 0x80802308: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080230C: jal         0x800DC298
    // 0x80802310: nop

    func_800DC298(rdram, ctx);
        goto after_35;
    // 0x80802310: nop

    after_35:
    // 0x80802314: beql        $v0, $zero, L_80802328
    if (ctx->r2 == 0) {
        // 0x80802318: addiu       $v0, $zero, -0x4
        ctx->r2 = ADD32(0, -0X4);
            goto L_80802328;
    }
    goto skip_12;
    // 0x80802318: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
    skip_12:
    // 0x8080231C: b           L_80802328
    // 0x80802320: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802328;
    // 0x80802320: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80802324: addiu       $v0, $zero, -0x4
    ctx->r2 = ADD32(0, -0X4);
L_80802328:
    // 0x80802328: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8080232C: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80802330: lui         $a2, 0x4541
    ctx->r6 = S32(0X4541 << 16);
    // 0x80802334: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80802338: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x8080233C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80802340: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80802344: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80802348: jal         0x800EEB9C
    // 0x8080234C: nop

    func_800EEB9C(rdram, ctx);
        goto after_36;
    // 0x8080234C: nop

    after_36:
    // 0x80802350: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
L_80802354:
    // 0x80802354: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x80802358: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080235C: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x80802360: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80802364: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80802368: jal         0x800D1000
    // 0x8080236C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800D1000(rdram, ctx);
        goto after_37;
    // 0x8080236C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_37:
    // 0x80802370: b           L_80802524
    // 0x80802374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80802374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802378:
    // 0x80802378: jal         0x80101080
    // 0x8080237C: nop

    func_80101080(rdram, ctx);
        goto after_38;
    // 0x8080237C: nop

    after_38:
    // 0x80802380: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80802384: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80802388: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x8080238C: jal         0x80800A80
    // 0x80802390: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80800A80_chdragonbrothers(rdram, ctx);
        goto after_39;
    // 0x80802390: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_39:
    // 0x80802394: b           L_80802524
    // 0x80802398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x80802398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080239C:
    // 0x8080239C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x808023A0: beq         $v0, $at, L_808023CC
    if (ctx->r2 == ctx->r1) {
        // 0x808023A4: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_808023CC;
    }
    // 0x808023A4: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x808023A8: beq         $v0, $at, L_8080241C
    if (ctx->r2 == ctx->r1) {
        // 0x808023AC: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_8080241C;
    }
    // 0x808023AC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808023B0: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x808023B4: bne         $v0, $at, L_8080242C
    if (ctx->r2 != ctx->r1) {
        // 0x808023B8: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_8080242C;
    }
    // 0x808023B8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808023BC: jal         0x80800D98
    // 0x808023C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800D98_chdragonbrothers(rdram, ctx);
        goto after_40;
    // 0x808023C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_40:
    // 0x808023C4: b           L_80802524
    // 0x808023C8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802524;
    // 0x808023C8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808023CC:
    // 0x808023CC: jal         0x800D395C
    // 0x808023D0: nop

    func_800D395C(rdram, ctx);
        goto after_41;
    // 0x808023D0: nop

    after_41:
    // 0x808023D4: beq         $v0, $zero, L_808023EC
    if (ctx->r2 == 0) {
        // 0x808023D8: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808023EC;
    }
    // 0x808023D8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808023DC: jal         0x80088180
    // 0x808023E0: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_42;
    // 0x808023E0: nop

    after_42:
    // 0x808023E4: b           L_80802524
    // 0x808023E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802524;
    // 0x808023E8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808023EC:
    // 0x808023EC: jal         0x80800B34
    // 0x808023F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800B34_chdragonbrothers(rdram, ctx);
        goto after_43;
    // 0x808023F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x808023F4: lw          $a2, 0x78($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X78);
    // 0x808023F8: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x808023FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802400: jal         0x80800B9C
    // 0x80802404: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_80800B9C_chdragonbrothers(rdram, ctx);
        goto after_44;
    // 0x80802404: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_44:
    // 0x80802408: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8080240C: jal         0x808004A4
    // 0x80802410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808004A4_chdragonbrothers(rdram, ctx);
        goto after_45;
    // 0x80802410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_45:
    // 0x80802414: b           L_80802524
    // 0x80802418: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802524;
    // 0x80802418: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8080241C:
    // 0x8080241C: jal         0x808012B4
    // 0x80802420: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_808012B4_chdragonbrothers(rdram, ctx);
        goto after_46;
    // 0x80802420: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_46:
    // 0x80802424: b           L_80802524
    // 0x80802428: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80802524;
    // 0x80802428: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8080242C:
    // 0x8080242C: b           L_80802524
    // 0x80802430: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80802524;
    // 0x80802430: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80802434:
    // 0x80802434: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80802438: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8080243C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80802440: lhu         $v0, 0x72($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X72);
    // 0x80802444: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80802448: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x8080244C: beq         $t2, $at, L_80802464
    if (ctx->r10 == ctx->r1) {
        // 0x80802450: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80802464;
    }
    // 0x80802450: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80802454: beq         $t2, $at, L_808024B8
    if (ctx->r10 == ctx->r1) {
        // 0x80802458: lw          $a1, 0x78($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X78);
            goto L_808024B8;
    }
    // 0x80802458: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x8080245C: b           L_80802510
    // 0x80802460: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1852, 0X5640) << 16);
        goto L_80802510;
    // 0x80802460: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1852, 0X5640) << 16);
L_80802464:
    // 0x80802464: jal         0x800EE7F8
    // 0x80802468: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_47;
    // 0x80802468: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_47:
    // 0x8080246C: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80802470: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5244) << 16);
    // 0x80802474: lwc1        $f8, 0x5244($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5244));
    // 0x80802478: lwc1        $f6, 0x38($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X38);
    // 0x8080247C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80802480: lw          $a1, 0x48($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X48);
    // 0x80802484: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80802488: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8080248C: jal         0x800EF1B8
    // 0x80802490: nop

    func_800EF1B8(rdram, ctx);
        goto after_48;
    // 0x80802490: nop

    after_48:
    // 0x80802494: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80802498: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1852, 0X5620) << 16);
    // 0x8080249C: addiu       $a0, $a0, 0x5620
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1852, 0X5620));
    // 0x808024A0: jal         0x80088090
    // 0x808024A4: lw          $a1, 0x38($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_49;
    // 0x808024A4: lw          $a1, 0x38($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X38);
    after_49:
    // 0x808024A8: jal         0x80088098
    // 0x808024AC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_50;
    // 0x808024AC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_50:
    // 0x808024B0: b           L_80802524
    // 0x808024B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x808024B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808024B8:
    // 0x808024B8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808024BC: jal         0x800EE7F8
    // 0x808024C0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_51;
    // 0x808024C0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_51:
    // 0x808024C4: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x808024C8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808024CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808024D0: lwc1        $f16, 0x38($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X38);
    // 0x808024D4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808024D8: lw          $a1, 0x48($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X48);
    // 0x808024DC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808024E0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808024E4: jal         0x800EF1B8
    // 0x808024E8: nop

    func_800EF1B8(rdram, ctx);
        goto after_52;
    // 0x808024E8: nop

    after_52:
    // 0x808024EC: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x808024F0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1852, 0X5630) << 16);
    // 0x808024F4: addiu       $a0, $a0, 0x5630
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1852, 0X5630));
    // 0x808024F8: jal         0x80088090
    // 0x808024FC: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_53;
    // 0x808024FC: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    after_53:
    // 0x80802500: jal         0x80088098
    // 0x80802504: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_54;
    // 0x80802504: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_54:
    // 0x80802508: b           L_80802524
    // 0x8080250C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80802524;
    // 0x8080250C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802510:
    // 0x80802510: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80802514: addiu       $a0, $a0, 0x5640
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1852, 0X5640));
    // 0x80802518: jal         0x80088090
    // 0x8080251C: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_55;
    // 0x8080251C: lw          $a1, 0x38($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X38);
    after_55:
L_80802520:
    // 0x80802520: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802524:
    // 0x80802524: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802528: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8080252C: jr          $ra
    // 0x80802530: nop

    return;
    // 0x80802530: nop

;}
RECOMP_FUNC void func_80800088_chmolehill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800088: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080008C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800090: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800094: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80800098: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x8080009C: bgezl       $t9, L_80800154
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808000A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800154;
    }
    goto skip_0;
    // 0x808000A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000A4: jal         0x8010D254
    // 0x808000A8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x808000A8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x808000AC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808000B0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808000B4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808000B8: jal         0x800F1DF4
    // 0x808000BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F1DF4(rdram, ctx);
        goto after_1;
    // 0x808000BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808000C0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x808000C4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x808000C8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808000CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000D0: lwc1        $f4, 0x48($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X48);
    // 0x808000D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808000D8: jal         0x800F1DCC
    // 0x808000DC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x808000DC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_2:
    // 0x808000E0: jal         0x80013728
    // 0x808000E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013728(rdram, ctx);
        goto after_3;
    // 0x808000E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x808000E8: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x808000EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000F0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808000F4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808000F8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x808000FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800100: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800104: bc1fl       L_80800114
    if (!c1cs) {
        // 0x80800108: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80800114;
    }
    goto skip_1;
    // 0x80800108: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_1:
    // 0x8080010C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80800110: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80800114:
    // 0x80800114: nop

    // 0x80800118: bc1fl       L_80800128
    if (!c1cs) {
        // 0x8080011C: sub.s       $f10, $f8, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
            goto L_80800128;
    }
    goto skip_2;
    // 0x8080011C: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    skip_2:
    // 0x80800120: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800124: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
L_80800128:
    // 0x80800128: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080012C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800130: jal         0x800EE7F8
    // 0x80800134: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800134: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80800138: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080013C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800140: jal         0x800EF1B8
    // 0x80800144: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_5;
    // 0x80800144: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    after_5:
    // 0x80800148: jal         0x8008F964
    // 0x8080014C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_8008F964(rdram, ctx);
        goto after_6;
    // 0x8080014C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x80800150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800154:
    // 0x80800154: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800158: jr          $ra
    // 0x8080015C: nop

    return;
    // 0x8080015C: nop

;}
RECOMP_FUNC void func_808026E0_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808026E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808026E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808026E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808026EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808026F0: jal         0x80106790
    // 0x808026F4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808026F4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808026F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808026FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802700: jal         0x808022E4
    // 0x80802704: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808022E4_chclockworkmouse(rdram, ctx);
        goto after_1;
    // 0x80802704: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80802708: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080270C: jal         0x80800D14
    // 0x80802710: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80800D14_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x80802710: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80802714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802718: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080271C: jr          $ra
    // 0x80802720: nop

    return;
    // 0x80802720: nop

;}
RECOMP_FUNC void fxrain_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800484: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080048C: jal         0x808001E8
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808001E8_fxrain(rdram, ctx);
        goto after_0;
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800498: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080049C: jr          $ra
    // 0x808004A0: nop

    return;
    // 0x808004A0: nop

;}
RECOMP_FUNC void func_80802910_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802910: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802914: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802918: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080291C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802920: jal         0x80100094
    // 0x80802924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802924: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802928: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080292C: jal         0x800FDC28
    // 0x80802930: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800FDC28(rdram, ctx);
        goto after_1;
    // 0x80802930: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x80802934: jal         0x80802A9C
    // 0x80802938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802A9C_chinflatableboss(rdram, ctx);
        goto after_2;
    // 0x80802938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080293C: jal         0x800A51C0
    // 0x80802940: nop

    func_800A51C0(rdram, ctx);
        goto after_3;
    // 0x80802940: nop

    after_3:
    // 0x80802944: jal         0x808024BC
    // 0x80802948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808024BC_chinflatableboss(rdram, ctx);
        goto after_4;
    // 0x80802948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080294C: jal         0x800DA544
    // 0x80802950: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80802950: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80802954: jal         0x800DA544
    // 0x80802958: addiu       $a0, $zero, 0x17F
    ctx->r4 = ADD32(0, 0X17F);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x80802958: addiu       $a0, $zero, 0x17F
    ctx->r4 = ADD32(0, 0X17F);
    after_6:
    // 0x8080295C: jal         0x80088178
    // 0x80802960: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x80802960: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_7:
    // 0x80802964: jal         0x800F54E4
    // 0x80802968: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80802968: nop

    after_8:
    // 0x8080296C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802970: jal         0x800F82D4
    // 0x80802974: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_9;
    // 0x80802974: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80802978: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8080297C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80802980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802984: jal         0x8010A590
    // 0x80802988: sb          $t6, 0x498($t7)
    MEM_B(0X498, ctx->r15) = ctx->r14;
    func_8010A590(rdram, ctx);
        goto after_10;
    // 0x80802988: sb          $t6, 0x498($t7)
    MEM_B(0X498, ctx->r15) = ctx->r14;
    after_10:
    // 0x8080298C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802990: jal         0x80109FE8
    // 0x80802994: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80109FE8(rdram, ctx);
        goto after_11;
    // 0x80802994: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80802998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080299C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808029A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808029A4: jr          $ra
    // 0x808029A8: nop

    return;
    // 0x808029A8: nop

;}
RECOMP_FUNC void func_80801930_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801938: lbu         $t6, 0x165($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X165);
    // 0x8080193C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80801940: beq         $t6, $zero, L_80801954
    if (ctx->r14 == 0) {
        // 0x80801944: nop
    
            goto L_80801954;
    }
    // 0x80801944: nop

    // 0x80801948: jal         0x80084950
    // 0x8080194C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _baduo_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080194C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801950: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80801954:
    // 0x80801954: jal         0x80800104
    // 0x80801958: nop

    func_80800104_bsbswim(rdram, ctx);
        goto after_1;
    // 0x80801958: nop

    after_1:
    // 0x8080195C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801960: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801964: jr          $ra
    // 0x80801968: nop

    return;
    // 0x80801968: nop

;}
RECOMP_FUNC void func_808001B8_chping(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808001BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001C8: jal         0x80100094
    // 0x808001CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001D0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808001D4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808001D8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808001DC: jal         0x800F5A00
    // 0x808001E0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x808001E0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_1:
    // 0x808001E4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808001E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001EC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808001F0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808001F8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808001FC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800200: jal         0x800EE7F8
    // 0x80800204: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800204: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800208: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8080020C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800210: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800214: lwc1        $f12, 0x4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80800218: jal         0x800F0F9C
    // 0x8080021C: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_800F0F9C(rdram, ctx);
        goto after_3;
    // 0x8080021C: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x80800220: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800224: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800228: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8080022C: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800230: jal         0x80013970
    // 0x80800234: nop

    func_80013970(rdram, ctx);
        goto after_4;
    // 0x80800234: nop

    after_4:
    // 0x80800238: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8080023C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800240: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800244: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800248: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080024C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800250: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80800254: jal         0x80013970
    // 0x80800258: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_80013970(rdram, ctx);
        goto after_5;
    // 0x80800258: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_5:
    // 0x8080025C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800260: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800264: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2144, 0X404) << 16);
    // 0x80800268: lwc1        $f8, 0x404($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2144, 0X404));
    // 0x8080026C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800270: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800274: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800278: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8080027C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800280: jal         0x800F10B4
    // 0x80800284: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_6;
    // 0x80800284: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x80800288: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080028C: jal         0x800A940C
    // 0x80800290: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_800A940C(rdram, ctx);
        goto after_7;
    // 0x80800290: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x80800294: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800298: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8080029C: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808002A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002A4: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x808002A8: nop

    // 0x808002AC: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x808002B0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808002B4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808002B8: jal         0x800C4B90
    // 0x808002BC: nop

    func_800C4B90(rdram, ctx);
        goto after_8;
    // 0x808002BC: nop

    after_8:
    // 0x808002C0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808002C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808002C8: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808002CC: lui         $at, 0x4452
    ctx->r1 = S32(0X4452 << 16);
    // 0x808002D0: lui         $a3, 0x4160
    ctx->r7 = S32(0X4160 << 16);
    // 0x808002D4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808002D8: nop

    // 0x808002DC: bc1f        L_80800334
    if (!c1cs) {
        // 0x808002E0: nop
    
            goto L_80800334;
    }
    // 0x808002E0: nop

    // 0x808002E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002E8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002F0: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    // 0x808002F4: jal         0x800F10B4
    // 0x808002F8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x808002F8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x808002FC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800300: jal         0x8010A590
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_10;
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800308: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8080030C: jal         0x800CB840
    // 0x80800310: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800CB840(rdram, ctx);
        goto after_11;
    // 0x80800310: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x80800314: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800318: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8080031C: jal         0x80109CC4
    // 0x80800320: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_80109CC4(rdram, ctx);
        goto after_12;
    // 0x80800320: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_12:
    // 0x80800324: jal         0x800CB870
    // 0x80800328: nop

    func_800CB870(rdram, ctx);
        goto after_13;
    // 0x80800328: nop

    after_13:
    // 0x8080032C: jal         0x8010A570
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_14;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_80800334:
    // 0x80800334: jal         0x800D8FF8
    // 0x80800338: nop

    func_800D8FF8(rdram, ctx);
        goto after_15;
    // 0x80800338: nop

    after_15:
    // 0x8080033C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80800340: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2144, 0X408) << 16);
    // 0x80800344: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800348: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8080034C: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80800350: lwc1        $f18, 0x408($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2144, 0X408));
    // 0x80800354: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80800358: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8080035C: nop

    // 0x80800360: bc1fl       L_80800374
    if (!c1cs) {
        // 0x80800364: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800374;
    }
    goto skip_0;
    // 0x80800364: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800368: jal         0x800FFA88
    // 0x8080036C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_16;
    // 0x8080036C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_16:
    // 0x80800370: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800374:
    // 0x80800374: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800378: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080037C: jr          $ra
    // 0x80800380: nop

    return;
    // 0x80800380: nop

;}
RECOMP_FUNC void _chfantasybounce_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085C28: syscall     210
    recomp_syscall_handler(rdram, ctx, 0x80085C28);
    return;
    // 0x80085C2C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _sumole_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800899F0: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x800899F0);
    return;
    // 0x800899F4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _chcrate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F98: syscall     486
    recomp_syscall_handler(rdram, ctx, 0x80086F98);
    return;
    // 0x80086F9C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void baphysics_reset_terminal_velocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BC90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BC94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BC98: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8009BC9C: jal         0x8009BCC4
    // 0x8009BCA0: lw          $a1, 0x7EF4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7EF4);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_0;
    // 0x8009BCA0: lw          $a1, 0x7EF4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7EF4);
    after_0:
    // 0x8009BCA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BCA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BCAC: jr          $ra
    // 0x8009BCB0: nop

    return;
    // 0x8009BCB0: nop

;}
RECOMP_FUNC void func_800B2A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2A58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B2A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2A60: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B2A64: jal         0x8001B798
    // 0x800B2A68: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800B2A68: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    after_0:
    // 0x800B2A6C: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800B2A70: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x800B2A74: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B2A78: bnel        $t6, $t7, L_800B2B1C
    if (ctx->r14 != ctx->r15) {
        // 0x800B2A7C: lw          $v0, 0x8($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X8);
            goto L_800B2B1C;
    }
    goto skip_0;
    // 0x800B2A7C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x800B2A80: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B2A84: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800B2A88: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800B2A8C: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    // 0x800B2A90: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800B2A94: div         $zero, $t0, $v0
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r2)));
    // 0x800B2A98: mflo        $a3
    ctx->r7 = lo;
    // 0x800B2A9C: addiu       $a2, $a3, 0x5
    ctx->r6 = ADD32(ctx->r7, 0X5);
    // 0x800B2AA0: bne         $v0, $zero, L_800B2AAC
    if (ctx->r2 != 0) {
        // 0x800B2AA4: nop
    
            goto L_800B2AAC;
    }
    // 0x800B2AA4: nop

    // 0x800B2AA8: break       7
    do_break(2148215464);
L_800B2AAC:
    // 0x800B2AAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B2AB0: bne         $v0, $at, L_800B2AC4
    if (ctx->r2 != ctx->r1) {
        // 0x800B2AB4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B2AC4;
    }
    // 0x800B2AB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B2AB8: bne         $t0, $at, L_800B2AC4
    if (ctx->r8 != ctx->r1) {
        // 0x800B2ABC: nop
    
            goto L_800B2AC4;
    }
    // 0x800B2ABC: nop

    // 0x800B2AC0: break       6
    do_break(2148215488);
L_800B2AC4:
    // 0x800B2AC4: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2AC8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800B2ACC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800B2AD0: mflo        $a1
    ctx->r5 = lo;
    // 0x800B2AD4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800B2AD8: jal         0x8001B710
    // 0x800B2ADC: nop

    func_8001B710(rdram, ctx);
        goto after_1;
    // 0x800B2ADC: nop

    after_1:
    // 0x800B2AE0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2AE4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800B2AE8: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x800B2AEC: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x800B2AF0: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2AF4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800B2AF8: mflo        $t1
    ctx->r9 = lo;
    // 0x800B2AFC: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x800B2B00: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x800B2B04: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B2B08: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2B0C: mflo        $t4
    ctx->r12 = lo;
    // 0x800B2B10: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x800B2B14: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x800B2B18: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
L_800B2B1C:
    // 0x800B2B1C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B2B20: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800B2B24: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800B2B28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2B2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B2B30: jr          $ra
    // 0x800B2B34: nop

    return;
    // 0x800B2B34: nop

;}
RECOMP_FUNC void func_80102F44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102F44: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80102F48: sll         $t8, $t6, 13
    ctx->r24 = S32(ctx->r14 << 13);
    // 0x80102F4C: bgezl       $t8, L_80102F60
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80102F50: lbu         $t0, 0x79($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X79);
            goto L_80102F60;
    }
    goto skip_0;
    // 0x80102F50: lbu         $t0, 0x79($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X79);
    skip_0:
    // 0x80102F54: jr          $ra
    // 0x80102F58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80102F58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80102F5C: lbu         $t0, 0x79($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X79);
L_80102F60:
    // 0x80102F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80102F64: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x80102F68: sb          $t1, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r9;
    // 0x80102F6C: jr          $ra
    // 0x80102F70: nop

    return;
    // 0x80102F70: nop

;}
RECOMP_FUNC void func_808022A8_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808022A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808022AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808022B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808022B4: beq         $a1, $zero, L_808022F0
    if (ctx->r5 == 0) {
        // 0x808022B8: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_808022F0;
    }
    // 0x808022B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808022BC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x808022C0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808022C4: jal         0x800F1EA4
    // 0x808022C8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F1EA4(rdram, ctx);
        goto after_0;
    // 0x808022C8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x808022CC: beq         $v0, $zero, L_808022DC
    if (ctx->r2 == 0) {
        // 0x808022D0: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808022DC;
    }
    // 0x808022D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808022D4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808022D8: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
L_808022DC:
    // 0x808022DC: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808022E0: jal         0x800EF334
    // 0x808022E4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_800EF334(rdram, ctx);
        goto after_1;
    // 0x808022E4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_1:
    // 0x808022E8: jal         0x80089CA8
    // 0x808022EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808022EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_808022F0:
    // 0x808022F0: jal         0x800D8FF8
    // 0x808022F4: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x808022F4: nop

    after_3:
    // 0x808022F8: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808022FC: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80802300: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80802304: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80802308: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x8080230C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802310: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802314: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80802318: jr          $ra
    // 0x8080231C: nop

    return;
    // 0x8080231C: nop

;}
RECOMP_FUNC void ncpoddialog_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802808: bltz        $a1, L_80802828
    if (SIGNED(ctx->r5) < 0) {
        // 0x8080280C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80802828;
    }
    // 0x8080280C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802810: bne         $a1, $zero, L_80802820
    if (ctx->r5 != 0) {
        // 0x80802814: sb          $v0, 0x215($a0)
        MEM_B(0X215, ctx->r4) = ctx->r2;
            goto L_80802820;
    }
    // 0x80802814: sb          $v0, 0x215($a0)
    MEM_B(0X215, ctx->r4) = ctx->r2;
    // 0x80802818: jr          $ra
    // 0x8080281C: sb          $zero, 0x214($a0)
    MEM_B(0X214, ctx->r4) = 0;
    return;
    // 0x8080281C: sb          $zero, 0x214($a0)
    MEM_B(0X214, ctx->r4) = 0;
L_80802820:
    // 0x80802820: jr          $ra
    // 0x80802824: sb          $v0, 0x214($a0)
    MEM_B(0X214, ctx->r4) = ctx->r2;
    return;
    // 0x80802824: sb          $v0, 0x214($a0)
    MEM_B(0X214, ctx->r4) = ctx->r2;
L_80802828:
    // 0x80802828: sb          $zero, 0x215($a0)
    MEM_B(0X215, ctx->r4) = 0;
    // 0x8080282C: jr          $ra
    // 0x80802830: nop

    return;
    // 0x80802830: nop

;}
RECOMP_FUNC void func_808000FC_bscrouch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800100: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: lui         $a1, 0x3ED1
    ctx->r5 = S32(0X3ED1 << 16);
    // 0x8080010C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800110: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    // 0x80800114: jal         0x800A2CE8
    // 0x80800118: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_0;
    // 0x80800118: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8080011C: lui         $a1, 0x3F68
    ctx->r5 = S32(0X3F68 << 16);
    // 0x80800120: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x80800124: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800128: jal         0x800A2CE8
    // 0x8080012C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_1;
    // 0x8080012C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void _susplinet_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E70: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E70);
    return;
    // 0x80089E74: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _chswitch_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800857E0: syscall     176
    recomp_syscall_handler(rdram, ctx, 0x800857E0);
    return;
    // 0x800857E4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800540_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800544: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800548: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080054C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800550: beq         $a1, $at, L_80800594
    if (ctx->r5 == ctx->r1) {
        // 0x80800554: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80800594;
    }
    // 0x80800554: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800558: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080055C: beq         $a1, $at, L_80800594
    if (ctx->r5 == ctx->r1) {
        // 0x80800560: addiu       $at, $zero, 0x38
        ctx->r1 = ADD32(0, 0X38);
            goto L_80800594;
    }
    // 0x80800560: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80800564: beq         $a1, $at, L_80800680
    if (ctx->r5 == ctx->r1) {
        // 0x80800568: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_80800680;
    }
    // 0x80800568: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x8080056C: beq         $a1, $at, L_808005EC
    if (ctx->r5 == ctx->r1) {
        // 0x80800570: addiu       $v0, $sp, 0x20
        ctx->r2 = ADD32(ctx->r29, 0X20);
            goto L_808005EC;
    }
    // 0x80800570: addiu       $v0, $sp, 0x20
    ctx->r2 = ADD32(ctx->r29, 0X20);
    // 0x80800574: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x80800578: beq         $a1, $at, L_80800600
    if (ctx->r5 == ctx->r1) {
        // 0x8080057C: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_80800600;
    }
    // 0x8080057C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80800580: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800584: beq         $a1, $at, L_80800638
    if (ctx->r5 == ctx->r1) {
        // 0x80800588: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80800638;
    }
    // 0x80800588: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080058C: b           L_80800694
    // 0x80800590: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
        goto L_80800694;
    // 0x80800590: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80800594:
    // 0x80800594: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800598: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080059C: jal         0x8008A1A0
    // 0x808005A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _sucoaster_entrypoint_21(rdram, ctx);
        goto after_0;
    // 0x808005A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808005A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808005AC: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x808005B0: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x808005B4: bltzl       $t8, L_808006A4
    if (SIGNED(ctx->r24) < 0) {
        // 0x808005B8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_808006A4;
    }
    goto skip_0;
    // 0x808005B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x808005BC: lw          $t9, 0x64($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X64);
    // 0x808005C0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x808005C4: bgez        $t1, L_808005DC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808005C8: nop
    
            goto L_808005DC;
    }
    // 0x808005C8: nop

    // 0x808005CC: jal         0x8080046C
    // 0x808005D0: nop

    func_8080046C_chhillbilly(rdram, ctx);
        goto after_1;
    // 0x808005D0: nop

    after_1:
    // 0x808005D4: b           L_808006A4
    // 0x808005D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006A4;
    // 0x808005D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005DC:
    // 0x808005DC: jal         0x808004D0
    // 0x808005E0: nop

    func_808004D0_chhillbilly(rdram, ctx);
        goto after_2;
    // 0x808005E0: nop

    after_2:
    // 0x808005E4: b           L_808006A4
    // 0x808005E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006A4;
    // 0x808005E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005EC:
    // 0x808005EC: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808005F0: jal         0x808006B4
    // 0x808005F4: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    func_808006B4_chhillbilly(rdram, ctx);
        goto after_3;
    // 0x808005F4: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    after_3:
    // 0x808005F8: b           L_808006A0
    // 0x808005FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_808006A0;
    // 0x808005FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800600:
    // 0x80800600: beq         $v0, $zero, L_8080060C
    if (ctx->r2 == 0) {
        // 0x80800604: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080060C;
    }
    // 0x80800604: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800608: bne         $v0, $at, L_80800630
    if (ctx->r2 != ctx->r1) {
        // 0x8080060C: addiu       $a1, $zero, 0x78A
        ctx->r5 = ADD32(0, 0X78A);
            goto L_80800630;
    }
L_8080060C:
    // 0x8080060C: addiu       $a1, $zero, 0x78A
    ctx->r5 = ADD32(0, 0X78A);
    // 0x80800610: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800614: jal         0x808009D8
    // 0x80800618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808009D8_chhillbilly(rdram, ctx);
        goto after_4;
    // 0x80800618: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_4:
    // 0x8080061C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800620: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80800624: lbu         $t2, 0x2A($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2A);
    // 0x80800628: andi        $t3, $t2, 0xFFDF
    ctx->r11 = ctx->r10 & 0XFFDF;
    // 0x8080062C: sb          $t3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r11;
L_80800630:
    // 0x80800630: b           L_808006A0
    // 0x80800634: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_808006A0;
    // 0x80800634: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800638:
    // 0x80800638: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080063C: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80800640: srl         $t4, $v0, 10
    ctx->r12 = S32(U32(ctx->r2) >> 10);
    // 0x80800644: beq         $t4, $at, L_80800654
    if (ctx->r12 == ctx->r1) {
        // 0x80800648: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_80800654;
    }
    // 0x80800648: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8080064C: bne         $t4, $at, L_8080065C
    if (ctx->r12 != ctx->r1) {
        // 0x80800650: addiu       $a1, $zero, 0x789
        ctx->r5 = ADD32(0, 0X789);
            goto L_8080065C;
    }
    // 0x80800650: addiu       $a1, $zero, 0x789
    ctx->r5 = ADD32(0, 0X789);
L_80800654:
    // 0x80800654: b           L_8080065C
    // 0x80800658: addiu       $a1, $zero, 0x78A
    ctx->r5 = ADD32(0, 0X78A);
        goto L_8080065C;
    // 0x80800658: addiu       $a1, $zero, 0x78A
    ctx->r5 = ADD32(0, 0X78A);
L_8080065C:
    // 0x8080065C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800660: jal         0x808009D8
    // 0x80800664: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_808009D8_chhillbilly(rdram, ctx);
        goto after_5;
    // 0x80800664: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_5:
    // 0x80800668: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080066C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800670: jal         0x8008A1A0
    // 0x80800674: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _sucoaster_entrypoint_21(rdram, ctx);
        goto after_6;
    // 0x80800674: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800678: b           L_808006A0
    // 0x8080067C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_808006A0;
    // 0x8080067C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800680:
    // 0x80800680: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(852, 0XB54) << 16);
    // 0x80800684: jal         0x80101074
    // 0x80800688: addiu       $a0, $a0, 0xB54
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(852, 0XB54));
    func_80101074(rdram, ctx);
        goto after_7;
    // 0x80800688: addiu       $a0, $a0, 0xB54
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(852, 0XB54));
    after_7:
    // 0x8080068C: b           L_808006A4
    // 0x80800690: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_808006A4;
    // 0x80800690: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80800694:
    // 0x80800694: jal         0x8008A1A0
    // 0x80800698: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _sucoaster_entrypoint_21(rdram, ctx);
        goto after_8;
    // 0x80800698: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_8:
    // 0x8080069C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_808006A0:
    // 0x808006A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808006A4:
    // 0x808006A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006AC: jr          $ra
    // 0x808006B0: nop

    return;
    // 0x808006B0: nop

;}
RECOMP_FUNC void func_80800A84_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A84: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800A88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A8C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800A90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A94: beq         $a1, $zero, L_80800AB0
    if (ctx->r5 == 0) {
        // 0x80800A98: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_80800AB0;
    }
    // 0x80800A98: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800A9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800AA0: beq         $a1, $at, L_80800AB0
    if (ctx->r5 == ctx->r1) {
        // 0x80800AA4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800AB0;
    }
    // 0x80800AA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800AA8: bnel        $a1, $at, L_80800B70
    if (ctx->r5 != ctx->r1) {
        // 0x80800AAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B70;
    }
    goto skip_0;
    // 0x80800AAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80800AB0:
    // 0x80800AB0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800AB4: jal         0x80100094
    // 0x80800AB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800AB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800ABC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800AC0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800AC4: jal         0x8008A2B0
    // 0x80800AC8: addiu       $a1, $v0, 0xAC
    ctx->r5 = ADD32(ctx->r2, 0XAC);
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800AC8: addiu       $a1, $v0, 0xAC
    ctx->r5 = ADD32(ctx->r2, 0XAC);
    after_1:
    // 0x80800ACC: beq         $v0, $zero, L_80800AEC
    if (ctx->r2 == 0) {
        // 0x80800AD0: lw          $t6, 0x40($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X40);
            goto L_80800AEC;
    }
    // 0x80800AD0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80800AD4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800AD8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800ADC: jal         0x800EE7F8
    // 0x80800AE0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800AE0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80800AE4: b           L_80800B04
    // 0x80800AE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_80800B04;
    // 0x80800AE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80800AEC:
    // 0x80800AEC: lw          $a0, 0x70($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X70);
    // 0x80800AF0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800AF4: srl         $t7, $a0, 25
    ctx->r15 = S32(U32(ctx->r4) >> 25);
    // 0x80800AF8: jal         0x800CD08C
    // 0x80800AFC: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    func_800CD08C(rdram, ctx);
        goto after_3;
    // 0x80800AFC: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    after_3:
    // 0x80800B00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80800B04:
    // 0x80800B04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B08: addiu       $a1, $zero, 0x167
    ctx->r5 = ADD32(0, 0X167);
    // 0x80800B0C: jal         0x800DC128
    // 0x80800B10: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x80800B10: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80800B14: addiu       $a0, $s0, 0x443
    ctx->r4 = ADD32(ctx->r16, 0X443);
    // 0x80800B18: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800B1C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800B20: jal         0x80108528
    // 0x80800B24: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_80108528(rdram, ctx);
        goto after_5;
    // 0x80800B24: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x80800B28: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80800B2C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800B30: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80800B34: sw          $s0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r16;
    // 0x80800B38: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    // 0x80800B3C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800B40: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800B44: jal         0x8008A2B0
    // 0x80800B48: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800B48: addiu       $a1, $a1, 0xAC
    ctx->r5 = ADD32(ctx->r5, 0XAC);
    after_6:
    // 0x80800B4C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80800B50: sll         $t2, $v0, 5
    ctx->r10 = S32(ctx->r2 << 5);
    // 0x80800B54: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x80800B58: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80800B5C: lbu         $t4, 0x2A($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X2A);
    // 0x80800B60: andi        $t5, $t4, 0xFFDF
    ctx->r13 = ctx->r12 & 0XFFDF;
    // 0x80800B64: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80800B68: sb          $t6, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r14;
    // 0x80800B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B70:
    // 0x80800B70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800B78: jr          $ra
    // 0x80800B7C: nop

    return;
    // 0x80800B7C: nop

;}
RECOMP_FUNC void func_800B25D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B25D8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800B25DC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B25E0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800B25E4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800B25E8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B25EC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B25F0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B25F4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B25F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B25FC: lhu         $t6, 0x16($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X16);
    // 0x800B2600: addiu       $s6, $a0, 0x18
    ctx->r22 = ADD32(ctx->r4, 0X18);
    // 0x800B2604: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800B2608: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x800B260C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800B2610: addu        $s4, $t8, $a0
    ctx->r20 = ADD32(ctx->r24, ctx->r4);
    // 0x800B2614: addiu       $s4, $s4, 0x18
    ctx->r20 = ADD32(ctx->r20, 0X18);
    // 0x800B2618: sltu        $at, $s6, $s4
    ctx->r1 = ctx->r22 < ctx->r20 ? 1 : 0;
    // 0x800B261C: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x800B2620: beq         $at, $zero, L_800B268C
    if (ctx->r1 == 0) {
        // 0x800B2624: addiu       $s2, $a1, 0x18
        ctx->r18 = ADD32(ctx->r5, 0X18);
            goto L_800B268C;
    }
    // 0x800B2624: addiu       $s2, $a1, 0x18
    ctx->r18 = ADD32(ctx->r5, 0X18);
    // 0x800B2628: addiu       $s3, $sp, 0x5C
    ctx->r19 = ADD32(ctx->r29, 0X5C);
    // 0x800B262C: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
L_800B2630:
    // 0x800B2630: lhu         $a1, 0x6($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X6);
    // 0x800B2634: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B2638: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800B263C: andi        $t9, $a1, 0x1FF
    ctx->r25 = ctx->r5 & 0X1FF;
    // 0x800B2640: jal         0x80087958
    // 0x800B2644: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    _dbpalette_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800B2644: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    after_0:
    // 0x800B2648: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800B264C: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x800B2650: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800B2654:
    // 0x800B2654: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800B2658: lbu         $t1, 0xC($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XC);
    // 0x800B265C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B2660: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B2664: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2668: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B266C: mflo        $t2
    ctx->r10 = lo;
    // 0x800B2670: sra         $t3, $t2, 8
    ctx->r11 = S32(SIGNED(ctx->r10) >> 8);
    // 0x800B2674: bne         $v0, $s0, L_800B2654
    if (ctx->r2 != ctx->r16) {
        // 0x800B2678: sb          $t3, 0xB($v1)
        MEM_B(0XB, ctx->r3) = ctx->r11;
            goto L_800B2654;
    }
    // 0x800B2678: sb          $t3, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r11;
    // 0x800B267C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800B2680: sltu        $at, $s1, $s4
    ctx->r1 = ctx->r17 < ctx->r20 ? 1 : 0;
    // 0x800B2684: bne         $at, $zero, L_800B2630
    if (ctx->r1 != 0) {
        // 0x800B2688: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_800B2630;
    }
    // 0x800B2688: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_800B268C:
    // 0x800B268C: subu        $a1, $s4, $s6
    ctx->r5 = SUB32(ctx->r20, ctx->r22);
    // 0x800B2690: sra         $t4, $a1, 4
    ctx->r12 = S32(SIGNED(ctx->r5) >> 4);
    // 0x800B2694: sll         $a1, $t4, 4
    ctx->r5 = S32(ctx->r12 << 4);
    // 0x800B2698: jal         0x8002E660
    // 0x800B269C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x800B269C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x800B26A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800B26A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B26A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B26AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B26B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B26B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B26B8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800B26BC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800B26C0: jr          $ra
    // 0x800B26C4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800B26C4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800B7B68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7B68: beq         $a0, $zero, L_800B7B80
    if (ctx->r4 == 0) {
        // 0x800B7B6C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800B7B80;
    }
    // 0x800B7B6C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7B70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B7B74: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7B78: jr          $ra
    // 0x800B7B7C: sb          $t6, -0x7E6E($at)
    MEM_B(-0X7E6E, ctx->r1) = ctx->r14;
    return;
    // 0x800B7B7C: sb          $t6, -0x7E6E($at)
    MEM_B(-0X7E6E, ctx->r1) = ctx->r14;
L_800B7B80:
    // 0x800B7B80: sb          $zero, -0x7E6E($at)
    MEM_B(-0X7E6E, ctx->r1) = 0;
    // 0x800B7B84: jr          $ra
    // 0x800B7B88: nop

    return;
    // 0x800B7B88: nop

;}
RECOMP_FUNC void sucoasterfly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E8: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x808000EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000F8: jal         0x80100094
    // 0x808000FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800100: jal         0x800D8FF8
    // 0x80800104: sw          $v0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800104: sw          $v0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800108: swc1        $f0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f0.u32l;
    // 0x8080010C: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x80800110: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80800114: bltzl       $t8, L_80800CE0
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800118: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800CE0;
    }
    goto skip_0;
    // 0x80800118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080011C: jal         0x800D9078
    // 0x80800120: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80800120: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
    // 0x80800124: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800130: jal         0x80100094
    // 0x80800134: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800134: swc1        $f4, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800138: beq         $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x8080013C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800158;
    }
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: jal         0x80100094
    // 0x80800144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800144: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080014C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800150: jal         0x800897D8
    // 0x80800154: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800154: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_80800158:
    // 0x80800158: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x8080015C: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800160: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80800164: sltiu       $at, $t1, 0x10
    ctx->r1 = ctx->r9 < 0X10 ? 1 : 0;
    // 0x80800168: beq         $at, $zero, L_80800C34
    if (ctx->r1 == 0) {
        // 0x8080016C: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80800C34;
    }
    // 0x8080016C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800170: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X21E0) << 16);
    // 0x80800174: addu        $at, $at, $t1
    gpr jr_addend_8080017C = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80800178: lw          $t1, 0x21E0($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3210, 0X21E0));
    // 0x8080017C: jr          $t1
    // 0x80800180: nop

    switch (jr_addend_8080017C >> 2) {
        case 0: goto L_80800184; break;
        case 1: goto L_80800280; break;
        case 2: goto L_808002C8; break;
        case 3: goto L_80800418; break;
        case 4: goto L_8080052C; break;
        case 5: goto L_808005F8; break;
        case 6: goto L_808007E0; break;
        case 7: goto L_808008D4; break;
        case 8: goto L_80800A00; break;
        case 9: goto L_80800AE0; break;
        case 10: goto L_80800B44; break;
        case 11: goto L_80800BD4; break;
        case 12: goto L_80800C2C; break;
        case 13: goto L_80800C2C; break;
        case 14: goto L_80800C2C; break;
        case 15: goto L_80800C2C; break;
        default: switch_error(__func__, 0x8080017C, 0x808021E0);
    }
    // 0x80800180: nop

L_80800184:
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x80801C44
    // 0x8080018C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_sucoasterfly(rdram, ctx);
        goto after_6;
    // 0x8080018C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800190: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x8080019C: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x808001A0: bgez        $t4, L_808001E4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808001A4: nop
    
            goto L_808001E4;
    }
    // 0x808001A4: nop

    // 0x808001A8: jal         0x80089BF0
    // 0x808001AC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x808001AC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_7:
    // 0x808001B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X2220) << 16);
    // 0x808001B4: lwc1        $f6, 0x2220($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2220));
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808001C0: nop

    // 0x808001C4: bc1f        L_808001D4
    if (!c1cs) {
        // 0x808001C8: nop
    
            goto L_808001D4;
    }
    // 0x808001C8: nop

    // 0x808001CC: jal         0x808014AC
    // 0x808001D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_8;
    // 0x808001D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
L_808001D4:
    // 0x808001D4: jal         0x80801DD0
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801DD0_sucoasterfly(rdram, ctx);
        goto after_9;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808001DC: b           L_8080025C
    // 0x808001E0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
        goto L_8080025C;
    // 0x808001E0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
L_808001E4:
    // 0x808001E4: jal         0x80801AB0
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AB0_sucoasterfly(rdram, ctx);
        goto after_10;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001EC: bnel        $v0, $zero, L_8080022C
    if (ctx->r2 != 0) {
        // 0x808001F0: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8080022C;
    }
    goto skip_1;
    // 0x808001F0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_1:
    // 0x808001F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808001F8: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X2224) << 16);
    // 0x80800200: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80800204: nop

    // 0x80800208: bc1fl       L_8080022C
    if (!c1cs) {
        // 0x8080020C: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8080022C;
    }
    goto skip_2;
    // 0x8080020C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_2:
    // 0x80800210: jal         0x800DC298
    // 0x80800214: lwc1        $f12, 0x2224($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2224));
    func_800DC298(rdram, ctx);
        goto after_11;
    // 0x80800214: lwc1        $f12, 0x2224($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2224));
    after_11:
    // 0x80800218: beq         $v0, $zero, L_80800228
    if (ctx->r2 == 0) {
        // 0x8080021C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800228;
    }
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: jal         0x808014AC
    // 0x80800224: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_12;
    // 0x80800224: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
L_80800228:
    // 0x80800228: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_8080022C:
    // 0x8080022C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800230: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800234: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800238: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x8080023C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x80800248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080024C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80800250: jal         0x80102D98
    // 0x80800254: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_80102D98(rdram, ctx);
        goto after_13;
    // 0x80800254: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_13:
    // 0x80800258: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
L_8080025C:
    // 0x8080025C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800268: jal         0x80102BF8
    // 0x8080026C: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    func_80102BF8(rdram, ctx);
        goto after_14;
    // 0x8080026C: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_14:
    // 0x80800270: jal         0x808019A0
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808019A0_sucoasterfly(rdram, ctx);
        goto after_15;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800278: b           L_80800C38
    // 0x8080027C: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x8080027C: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_80800280:
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: jal         0x80801C44
    // 0x80800288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_sucoasterfly(rdram, ctx);
        goto after_16;
    // 0x80800288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x8080028C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800290: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x8080029C: jal         0x80102BF8
    // 0x808002A0: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    func_80102BF8(rdram, ctx);
        goto after_17;
    // 0x808002A0: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_17:
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: jal         0x80102CF4
    // 0x808002AC: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    func_80102CF4(rdram, ctx);
        goto after_18;
    // 0x808002AC: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_18:
    // 0x808002B0: beq         $v0, $zero, L_80800C34
    if (ctx->r2 == 0) {
        // 0x808002B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C34;
    }
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: jal         0x808014AC
    // 0x808002BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_19;
    // 0x808002BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_19:
    // 0x808002C0: b           L_80800C38
    // 0x808002C4: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x808002C4: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_808002C8:
    // 0x808002C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002CC: jal         0x80801C44
    // 0x808002D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_sucoasterfly(rdram, ctx);
        goto after_20;
    // 0x808002D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x808002D4: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002DC: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x808002E0: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x808002E4: bgez        $t7, L_80800344
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808002E8: nop
    
            goto L_80800344;
    }
    // 0x808002E8: nop

    // 0x808002EC: jal         0x80089BF0
    // 0x808002F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_21;
    // 0x808002F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_21:
    // 0x808002F4: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808002F8: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    // 0x808002FC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800308: jal         0x80102BF8
    // 0x8080030C: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    func_80102BF8(rdram, ctx);
        goto after_22;
    // 0x8080030C: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_22:
    // 0x80800310: lwc1        $f4, 0xAC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80800314: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800320: nop

    // 0x80800324: bc1f        L_80800334
    if (!c1cs) {
        // 0x80800328: nop
    
            goto L_80800334;
    }
    // 0x80800328: nop

    // 0x8080032C: jal         0x808014AC
    // 0x80800330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_23;
    // 0x80800330: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
L_80800334:
    // 0x80800334: jal         0x80801DD0
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801DD0_sucoasterfly(rdram, ctx);
        goto after_24;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x8080033C: b           L_80800408
    // 0x80800340: nop

        goto L_80800408;
    // 0x80800340: nop

L_80800344:
    // 0x80800344: jal         0x80089F78
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_25;
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8080034C: beq         $v0, $zero, L_80800394
    if (ctx->r2 == 0) {
        // 0x80800350: nop
    
            goto L_80800394;
    }
    // 0x80800350: nop

    // 0x80800354: jal         0x80107C00
    // 0x80800358: nop

    func_80107C00(rdram, ctx);
        goto after_26;
    // 0x80800358: nop

    after_26:
    // 0x8080035C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800360: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800364: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800368: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x8080036C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800370: addiu       $t8, $zero, 0x4802
    ctx->r24 = ADD32(0, 0X4802);
    // 0x80800374: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080037C: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80800380: jal         0x80089F90
    // 0x80800384: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_27;
    // 0x80800384: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_27:
    // 0x80800388: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x8080038C: lhu         $t0, 0x6($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X6);
    // 0x80800390: sb          $t0, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r8;
L_80800394:
    // 0x80800394: jal         0x80801AB0
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AB0_sucoasterfly(rdram, ctx);
        goto after_28;
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x8080039C: bnel        $v0, $zero, L_808003DC
    if (ctx->r2 != 0) {
        // 0x808003A0: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_808003DC;
    }
    goto skip_3;
    // 0x808003A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_3:
    // 0x808003A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808003A8: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808003AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X2228) << 16);
    // 0x808003B0: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x808003B4: nop

    // 0x808003B8: bc1fl       L_808003DC
    if (!c1cs) {
        // 0x808003BC: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_808003DC;
    }
    goto skip_4;
    // 0x808003BC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_4:
    // 0x808003C0: jal         0x800DC298
    // 0x808003C4: lwc1        $f12, 0x2228($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2228));
    func_800DC298(rdram, ctx);
        goto after_29;
    // 0x808003C4: lwc1        $f12, 0x2228($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2228));
    after_29:
    // 0x808003C8: beq         $v0, $zero, L_808003D8
    if (ctx->r2 == 0) {
        // 0x808003CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D8;
    }
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: jal         0x808014AC
    // 0x808003D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_30;
    // 0x808003D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
L_808003D8:
    // 0x808003D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_808003DC:
    // 0x808003DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003E0: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x808003E4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808003E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003EC: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808003F0: lbu         $a2, 0x10($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X10);
    // 0x808003F4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800400: jal         0x80089F80
    // 0x80800404: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_31;
    // 0x80800404: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_31:
L_80800408:
    // 0x80800408: jal         0x808019A0
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808019A0_sucoasterfly(rdram, ctx);
        goto after_32;
    // 0x8080040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800410: b           L_80800C38
    // 0x80800414: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x80800414: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_80800418:
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: jal         0x80801C44
    // 0x80800420: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_sucoasterfly(rdram, ctx);
        goto after_33;
    // 0x80800420: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x80800424: jal         0x80089F78
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_34;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8080042C: beql        $v0, $zero, L_80800480
    if (ctx->r2 == 0) {
        // 0x80800430: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80800480;
    }
    goto skip_5;
    // 0x80800430: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_5:
    // 0x80800434: jal         0x8010CD28
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_35;
    // 0x80800438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x8080043C: jal         0x80107C00
    // 0x80800440: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    func_80107C00(rdram, ctx);
        goto after_36;
    // 0x80800440: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_36:
    // 0x80800444: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800448: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080044C: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800450: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80800454: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800458: addiu       $t2, $zero, 0x4802
    ctx->r10 = ADD32(0, 0X4802);
    // 0x8080045C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800464: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80800468: jal         0x80089F90
    // 0x8080046C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_37;
    // 0x8080046C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_37:
    // 0x80800470: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80800474: lhu         $t3, 0x6($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X6);
    // 0x80800478: sb          $t3, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r11;
    // 0x8080047C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_80800480:
    // 0x80800480: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80800484: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800488: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080048C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800490: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800494: lbu         $a2, 0x10($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X10);
    // 0x80800498: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x808004A4: jal         0x80089F80
    // 0x808004A8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_38;
    // 0x808004A8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_38:
    // 0x808004AC: jal         0x808019A0
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808019A0_sucoasterfly(rdram, ctx);
        goto after_39;
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x808004B4: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004BC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x808004C0: bgez        $t6, L_808004D8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808004C4: nop
    
            goto L_808004D8;
    }
    // 0x808004C4: nop

    // 0x808004C8: jal         0x808014AC
    // 0x808004CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_40;
    // 0x808004CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x808004D0: b           L_80800C38
    // 0x808004D4: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x808004D4: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_808004D8:
    // 0x808004D8: jal         0x80801B90
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B90_sucoasterfly(rdram, ctx);
        goto after_41;
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x808004E0: bne         $v0, $zero, L_80800C34
    if (ctx->r2 != 0) {
        // 0x808004E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C34;
    }
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: jal         0x80102CF4
    // 0x808004EC: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_80102CF4(rdram, ctx);
        goto after_42;
    // 0x808004EC: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_42:
    // 0x808004F0: beq         $v0, $zero, L_80800C34
    if (ctx->r2 == 0) {
        // 0x808004F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C34;
    }
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: jal         0x801021BC
    // 0x808004FC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_801021BC(rdram, ctx);
        goto after_43;
    // 0x808004FC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_43:
    // 0x80800500: beq         $v0, $zero, L_8080051C
    if (ctx->r2 == 0) {
        // 0x80800504: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080051C;
    }
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080050C: jal         0x808014AC
    // 0x80800510: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_44;
    // 0x80800510: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_44:
    // 0x80800514: b           L_80800C38
    // 0x80800518: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x80800518: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_8080051C:
    // 0x8080051C: jal         0x808014AC
    // 0x80800520: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_45;
    // 0x80800520: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_45:
    // 0x80800524: b           L_80800C38
    // 0x80800528: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x80800528: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_8080052C:
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800530: jal         0x80801C44
    // 0x80800534: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801C44_sucoasterfly(rdram, ctx);
        goto after_46;
    // 0x80800534: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_46:
    // 0x80800538: jal         0x80089F78
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_47;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80800540: beql        $v0, $zero, L_80800594
    if (ctx->r2 == 0) {
        // 0x80800544: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80800594;
    }
    goto skip_6;
    // 0x80800544: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_6:
    // 0x80800548: jal         0x8010CD28
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_48;
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x80800550: jal         0x80107C00
    // 0x80800554: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    func_80107C00(rdram, ctx);
        goto after_49;
    // 0x80800554: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_49:
    // 0x80800558: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080055C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800560: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800564: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80800568: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080056C: addiu       $t7, $zero, 0x4802
    ctx->r15 = ADD32(0, 0X4802);
    // 0x80800570: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x8080057C: jal         0x80089F90
    // 0x80800580: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_50;
    // 0x80800580: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_50:
    // 0x80800584: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80800588: lhu         $t8, 0x6($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X6);
    // 0x8080058C: sb          $t8, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r24;
    // 0x80800590: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_80800594:
    // 0x80800594: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80800598: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080059C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808005A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808005A4: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808005A8: lbu         $a2, 0x10($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X10);
    // 0x808005AC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808005B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x808005B8: jal         0x80089F80
    // 0x808005BC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_51;
    // 0x808005BC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_51:
    // 0x808005C0: jal         0x808019A0
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808019A0_sucoasterfly(rdram, ctx);
        goto after_52;
    // 0x808005C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x808005C8: jal         0x80801B90
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B90_sucoasterfly(rdram, ctx);
        goto after_53;
    // 0x808005CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x808005D0: bnel        $v0, $zero, L_80800C38
    if (ctx->r2 != 0) {
        // 0x808005D4: lwc1        $f12, 0xC0($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
            goto L_80800C38;
    }
    goto skip_7;
    // 0x808005D4: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
    skip_7:
    // 0x808005D8: jal         0x80101DDC
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_54;
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x808005E0: beq         $v0, $zero, L_80800C34
    if (ctx->r2 == 0) {
        // 0x808005E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C34;
    }
    // 0x808005E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E8: jal         0x808014AC
    // 0x808005EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_55;
    // 0x808005EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_55:
    // 0x808005F0: b           L_80800C38
    // 0x808005F4: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x808005F4: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_808005F8:
    // 0x808005F8: jal         0x800F54E4
    // 0x808005FC: nop

    func_800F54E4(rdram, ctx);
        goto after_56;
    // 0x808005FC: nop

    after_56:
    // 0x80800600: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800604: jal         0x800F5BF0
    // 0x80800608: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    func_800F5BF0(rdram, ctx);
        goto after_57;
    // 0x80800608: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    after_57:
    // 0x8080060C: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: jal         0x80801C44
    // 0x80800618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_sucoasterfly(rdram, ctx);
        goto after_58;
    // 0x80800618: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_58:
    // 0x8080061C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800620: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800624: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x80800628: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    // 0x8080062C: jal         0x800F0008
    // 0x80800630: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    func_800F0008(rdram, ctx);
        goto after_59;
    // 0x80800630: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    after_59:
    // 0x80800634: bnel        $v0, $zero, L_80800648
    if (ctx->r2 != 0) {
        // 0x80800638: lw          $t0, 0x64($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X64);
            goto L_80800648;
    }
    goto skip_8;
    // 0x80800638: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    skip_8:
    // 0x8080063C: jal         0x80801A80
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A80_sucoasterfly(rdram, ctx);
        goto after_60;
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_60:
    // 0x80800644: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
L_80800648:
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800650: bgez        $t1, L_808006E0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800654: nop
    
            goto L_808006E0;
    }
    // 0x80800654: nop

    // 0x80800658: jal         0x80089BC0
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiejoy_entrypoint_3(rdram, ctx);
        goto after_61;
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x80800660: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800664: nop

    // 0x80800668: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8080066C: nop

    // 0x80800670: bc1fl       L_808006F0
    if (!c1cs) {
        // 0x80800674: lui         $a1, 0x3DCC
        ctx->r5 = S32(0X3DCC << 16);
            goto L_808006F0;
    }
    goto skip_9;
    // 0x80800674: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    skip_9:
    // 0x80800678: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8080067C: jal         0x800F1DCC
    // 0x80800680: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_62;
    // 0x80800680: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    after_62:
    // 0x80800684: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800688: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080068C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800690: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800694: nop

    // 0x80800698: bc1fl       L_808006BC
    if (!c1cs) {
        // 0x8080069C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_808006BC;
    }
    goto skip_10;
    // 0x8080069C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_10:
    // 0x808006A0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808006A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808006A8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808006AC: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x808006B0: b           L_808006EC
    // 0x808006B4: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
        goto L_808006EC;
    // 0x808006B4: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x808006B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_808006BC:
    // 0x808006BC: nop

    // 0x808006C0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808006C4: nop

    // 0x808006C8: bc1fl       L_808006F0
    if (!c1cs) {
        // 0x808006CC: lui         $a1, 0x3DCC
        ctx->r5 = S32(0X3DCC << 16);
            goto L_808006F0;
    }
    goto skip_11;
    // 0x808006CC: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    skip_11:
    // 0x808006D0: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808006D4: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x808006D8: b           L_808006EC
    // 0x808006DC: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
        goto L_808006EC;
    // 0x808006DC: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
L_808006E0:
    // 0x808006E0: jal         0x80102D78
    // 0x808006E4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_80102D78(rdram, ctx);
        goto after_63;
    // 0x808006E4: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_63:
    // 0x808006E8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_808006EC:
    // 0x808006EC: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
L_808006F0:
    // 0x808006F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F8: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x808006FC: jal         0x80102BF8
    // 0x80800700: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    func_80102BF8(rdram, ctx);
        goto after_64;
    // 0x80800700: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_64:
    // 0x80800704: jal         0x80801B90
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B90_sucoasterfly(rdram, ctx);
        goto after_65;
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
    // 0x8080070C: bne         $v0, $zero, L_80800C34
    if (ctx->r2 != 0) {
        // 0x80800710: addiu       $t2, $s0, 0x18
        ctx->r10 = ADD32(ctx->r16, 0X18);
            goto L_80800C34;
    }
    // 0x80800710: addiu       $t2, $s0, 0x18
    ctx->r10 = ADD32(ctx->r16, 0X18);
    // 0x80800714: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80800718: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x8080071C: lui         $t7, 0x60
    ctx->r15 = S32(0X60 << 16);
    // 0x80800720: ori         $t7, $t7, 0x307
    ctx->r15 = ctx->r15 | 0X307;
    // 0x80800724: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80800728: bgez        $t5, L_8080073C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8080072C: lui         $t6, 0x60
        ctx->r14 = S32(0X60 << 16);
            goto L_8080073C;
    }
    // 0x8080072C: lui         $t6, 0x60
    ctx->r14 = S32(0X60 << 16);
    // 0x80800730: ori         $t6, $t6, 0x4027
    ctx->r14 = ctx->r14 | 0X4027;
    // 0x80800734: b           L_80800740
    // 0x80800738: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
        goto L_80800740;
    // 0x80800738: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
L_8080073C:
    // 0x8080073C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
L_80800740:
    // 0x80800740: jal         0x8080181C
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080181C_sucoasterfly(rdram, ctx);
        goto after_66;
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x80800748: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8080074C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800750: jal         0x800EFB24
    // 0x80800754: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800EFB24(rdram, ctx);
        goto after_67;
    // 0x80800754: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_67:
    // 0x80800758: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8080075C: jal         0x800EF368
    // 0x80800760: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    func_800EF368(rdram, ctx);
        goto after_68;
    // 0x80800760: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    after_68:
    // 0x80800764: jal         0x800EEFFC
    // 0x80800768: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    func_800EEFFC(rdram, ctx);
        goto after_69;
    // 0x80800768: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    after_69:
    // 0x8080076C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800770: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800774: jal         0x800EFCD8
    // 0x80800778: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EFCD8(rdram, ctx);
        goto after_70;
    // 0x80800778: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_70:
    // 0x8080077C: lwc1        $f16, 0x88($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80800780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800784: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x80800788: jal         0x8010B990
    // 0x8080078C: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    func_8010B990(rdram, ctx);
        goto after_71;
    // 0x8080078C: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    after_71:
    // 0x80800790: andi        $t8, $v0, 0x24
    ctx->r24 = ctx->r2 & 0X24;
    // 0x80800794: beq         $t8, $zero, L_808007B0
    if (ctx->r24 == 0) {
        // 0x80800798: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007B0;
    }
    // 0x80800798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A0: jal         0x808014AC
    // 0x808007A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_72;
    // 0x808007A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_72:
    // 0x808007A8: b           L_80800C38
    // 0x808007AC: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x808007AC: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_808007B0:
    // 0x808007B0: jal         0x80102D78
    // 0x808007B4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80102D78(rdram, ctx);
        goto after_73;
    // 0x808007B4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_73:
    // 0x808007B8: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808007BC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x808007C0: jal         0x800F20BC
    // 0x808007C4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_800F20BC(rdram, ctx);
        goto after_74;
    // 0x808007C4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_74:
    // 0x808007C8: bne         $v0, $zero, L_80800C34
    if (ctx->r2 != 0) {
        // 0x808007CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C34;
    }
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D0: jal         0x808014AC
    // 0x808007D4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_75;
    // 0x808007D4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_75:
    // 0x808007D8: b           L_80800C38
    // 0x808007DC: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x808007DC: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_808007E0:
    // 0x808007E0: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x808007E4: lui         $t3, 0x60
    ctx->r11 = S32(0X60 << 16);
    // 0x808007E8: ori         $t3, $t3, 0x307
    ctx->r11 = ctx->r11 | 0X307;
    // 0x808007EC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808007F0: bgez        $t1, L_80800808
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808007F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800808;
    }
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F8: lui         $t2, 0x60
    ctx->r10 = S32(0X60 << 16);
    // 0x808007FC: ori         $t2, $t2, 0x4027
    ctx->r10 = ctx->r10 | 0X4027;
    // 0x80800800: b           L_8080080C
    // 0x80800804: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
        goto L_8080080C;
    // 0x80800804: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
L_80800808:
    // 0x80800808: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
L_8080080C:
    // 0x8080080C: jal         0x80801C44
    // 0x80800810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801C44_sucoasterfly(rdram, ctx);
        goto after_76;
    // 0x80800810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_76:
    // 0x80800814: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800818: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800820: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800824: jal         0x80102BF8
    // 0x80800828: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    func_80102BF8(rdram, ctx);
        goto after_77;
    // 0x80800828: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_77:
    // 0x8080082C: jal         0x8080181C
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080181C_sucoasterfly(rdram, ctx);
        goto after_78;
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x80800834: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800838: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080083C: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800840: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800844: nop

    // 0x80800848: bc1fl       L_808008A0
    if (!c1cs) {
        // 0x8080084C: lbu         $t5, 0x64($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X64);
            goto L_808008A0;
    }
    goto skip_12;
    // 0x8080084C: lbu         $t5, 0x64($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X64);
    skip_12:
    // 0x80800850: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800854: jal         0x800EF368
    // 0x80800858: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EF368(rdram, ctx);
        goto after_79;
    // 0x80800858: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_79:
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800860: jal         0x8010B990
    // 0x80800864: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_8010B990(rdram, ctx);
        goto after_80;
    // 0x80800864: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_80:
    // 0x80800868: andi        $t4, $v0, 0x24
    ctx->r12 = ctx->r2 & 0X24;
    // 0x8080086C: bne         $t4, $zero, L_8080088C
    if (ctx->r12 != 0) {
        // 0x80800870: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080088C;
    }
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800878: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080087C: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x80800880: nop

    // 0x80800884: bc1fl       L_80800C38
    if (!c1cs) {
        // 0x80800888: lwc1        $f12, 0xC0($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
            goto L_80800C38;
    }
    goto skip_13;
    // 0x80800888: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
    skip_13:
L_8080088C:
    // 0x8080088C: jal         0x808014AC
    // 0x80800890: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_81;
    // 0x80800890: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_81:
    // 0x80800894: b           L_80800C38
    // 0x80800898: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x80800898: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8080089C: lbu         $t5, 0x64($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X64);
L_808008A0:
    // 0x808008A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x808008AC: beq         $t6, $zero, L_808008C4
    if (ctx->r14 == 0) {
        // 0x808008B0: nop
    
            goto L_808008C4;
    }
    // 0x808008B0: nop

    // 0x808008B4: jal         0x808014AC
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_82;
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_82:
    // 0x808008BC: b           L_80800C38
    // 0x808008C0: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x808008C0: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_808008C4:
    // 0x808008C4: jal         0x808014AC
    // 0x808008C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_83;
    // 0x808008C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_83:
    // 0x808008CC: b           L_80800C38
    // 0x808008D0: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x808008D0: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_808008D4:
    // 0x808008D4: jal         0x800D8FF8
    // 0x808008D8: nop

    func_800D8FF8(rdram, ctx);
        goto after_84;
    // 0x808008D8: nop

    after_84:
    // 0x808008DC: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x808008E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808008E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008E8: lwc1        $f8, 0xC($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0XC);
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x808008F8: nop

    // 0x808008FC: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800900: jal         0x80801C44
    // 0x80800904: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    func_80801C44_sucoasterfly(rdram, ctx);
        goto after_85;
    // 0x80800904: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    after_85:
    // 0x80800908: jal         0x80089F78
    // 0x8080090C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_86;
    // 0x8080090C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_86:
    // 0x80800910: beq         $v0, $zero, L_80800970
    if (ctx->r2 == 0) {
        // 0x80800914: lw          $a1, 0xC4($sp)
        ctx->r5 = MEM_W(ctx->r29, 0XC4);
            goto L_80800970;
    }
    // 0x80800914: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80800918: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8080091C: jal         0x800EE88C
    // 0x80800920: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    func_800EE88C(rdram, ctx);
        goto after_87;
    // 0x80800920: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    after_87:
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800928: jal         0x80102D78
    // 0x8080092C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_80102D78(rdram, ctx);
        goto after_88;
    // 0x8080092C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_88:
    // 0x80800930: jal         0x80107C00
    // 0x80800934: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    func_80107C00(rdram, ctx);
        goto after_89;
    // 0x80800934: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_89:
    // 0x80800938: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080093C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800940: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800944: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80800948: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8080094C: addiu       $t8, $zero, 0x4802
    ctx->r24 = ADD32(0, 0X4802);
    // 0x80800950: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800958: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x8080095C: jal         0x80089F90
    // 0x80800960: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_90;
    // 0x80800960: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_90:
    // 0x80800964: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80800968: lhu         $t0, 0x6($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X6);
    // 0x8080096C: sb          $t0, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r8;
L_80800970:
    // 0x80800970: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80800974: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800978: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080097C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800980: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800984: lbu         $a2, 0x10($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X10);
    // 0x80800988: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8080098C: addiu       $t9, $a1, 0x12
    ctx->r25 = ADD32(ctx->r5, 0X12);
    // 0x80800990: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80800994: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080099C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808009A0: jal         0x80089F80
    // 0x808009A4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_91;
    // 0x808009A4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_91:
    // 0x808009A8: jal         0x808019A0
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808019A0_sucoasterfly(rdram, ctx);
        goto after_92;
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_92:
    // 0x808009B0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x808009B4: jal         0x800EE88C
    // 0x808009B8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800EE88C(rdram, ctx);
        goto after_93;
    // 0x808009B8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_93:
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C0: jal         0x80102CF4
    // 0x808009C4: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    func_80102CF4(rdram, ctx);
        goto after_94;
    // 0x808009C4: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    after_94:
    // 0x808009C8: bne         $v0, $zero, L_808009EC
    if (ctx->r2 != 0) {
        // 0x808009CC: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808009EC;
    }
    // 0x808009CC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808009D0: jal         0x800EEB40
    // 0x808009D4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_800EEB40(rdram, ctx);
        goto after_95;
    // 0x808009D4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_95:
    // 0x808009D8: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
    // 0x808009DC: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x808009E0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808009E4: nop

    // 0x808009E8: bc1f        L_80800C34
    if (!c1cs) {
        // 0x808009EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C34;
    }
L_808009EC:
    // 0x808009EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F0: jal         0x808014AC
    // 0x808009F4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_96;
    // 0x808009F4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_96:
    // 0x808009F8: b           L_80800C38
    // 0x808009FC: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x808009FC: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_80800A00:
    // 0x80800A00: jal         0x800D8FF8
    // 0x80800A04: nop

    func_800D8FF8(rdram, ctx);
        goto after_97;
    // 0x80800A04: nop

    after_97:
    // 0x80800A08: lw          $t1, 0xC4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC4);
    // 0x80800A0C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800A10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A14: lwc1        $f18, 0xC($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XC);
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A20: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800A24: nop

    // 0x80800A28: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800A2C: jal         0x80801C44
    // 0x80800A30: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    func_80801C44_sucoasterfly(rdram, ctx);
        goto after_98;
    // 0x80800A30: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_98:
    // 0x80800A34: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800A38: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A40: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80800A44: jal         0x80102BF8
    // 0x80800A48: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    func_80102BF8(rdram, ctx);
        goto after_99;
    // 0x80800A48: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_99:
    // 0x80800A4C: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80800A50: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800A54: jal         0x800EE88C
    // 0x80800A58: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    func_800EE88C(rdram, ctx);
        goto after_100;
    // 0x80800A58: addiu       $a1, $a1, 0x12
    ctx->r5 = ADD32(ctx->r5, 0X12);
    after_100:
    // 0x80800A5C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800A60: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800A64: jal         0x800EEB40
    // 0x80800A68: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800EEB40(rdram, ctx);
        goto after_101;
    // 0x80800A68: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_101:
    // 0x80800A6C: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800A70: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800A74: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800A78: nop

    // 0x80800A7C: bc1f        L_80800AA4
    if (!c1cs) {
        // 0x80800A80: nop
    
            goto L_80800AA4;
    }
    // 0x80800A80: nop

    // 0x80800A84: lbu         $t3, 0x64($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X64);
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800A90: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80800A94: jal         0x808014AC
    // 0x80800A98: sb          $t4, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r12;
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_102;
    // 0x80800A98: sb          $t4, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r12;
    after_102:
    // 0x80800A9C: b           L_80800C38
    // 0x80800AA0: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x80800AA0: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_80800AA4:
    // 0x80800AA4: jal         0x8080181C
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080181C_sucoasterfly(rdram, ctx);
        goto after_103;
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_103:
    // 0x80800AAC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800AB0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80800AB4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800AB8: jal         0x800EFB24
    // 0x80800ABC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800EFB24(rdram, ctx);
        goto after_104;
    // 0x80800ABC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_104:
    // 0x80800AC0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AC4: jal         0x800EF368
    // 0x80800AC8: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    func_800EF368(rdram, ctx);
        goto after_105;
    // 0x80800AC8: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    after_105:
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD0: jal         0x8010B990
    // 0x80800AD4: addiu       $a1, $zero, 0x4027
    ctx->r5 = ADD32(0, 0X4027);
    func_8010B990(rdram, ctx);
        goto after_106;
    // 0x80800AD4: addiu       $a1, $zero, 0x4027
    ctx->r5 = ADD32(0, 0X4027);
    after_106:
    // 0x80800AD8: b           L_80800C38
    // 0x80800ADC: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x80800ADC: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_80800AE0:
    // 0x80800AE0: jal         0x8080215C
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080215C_sucoasterfly(rdram, ctx);
        goto after_107;
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_107:
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AEC: jal         0x80801C44
    // 0x80800AF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801C44_sucoasterfly(rdram, ctx);
        goto after_108;
    // 0x80800AF0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_108:
    // 0x80800AF4: jal         0x80101DDC
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_109;
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_109:
    // 0x80800AFC: beq         $v0, $zero, L_80800C34
    if (ctx->r2 == 0) {
        // 0x80800B00: lw          $t5, 0xC4($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XC4);
            goto L_80800C34;
    }
    // 0x80800B00: lw          $t5, 0xC4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC4);
    // 0x80800B04: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x80800B08: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B10: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800B14: bgez        $t8, L_80800B2C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800B18: nop
    
            goto L_80800B2C;
    }
    // 0x80800B18: nop

    // 0x80800B1C: jal         0x808014AC
    // 0x80800B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_110;
    // 0x80800B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_110:
    // 0x80800B24: b           L_80800B34
    // 0x80800B28: nop

        goto L_80800B34;
    // 0x80800B28: nop

L_80800B2C:
    // 0x80800B2C: jal         0x808014AC
    // 0x80800B30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_111;
    // 0x80800B30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_111:
L_80800B34:
    // 0x80800B34: jal         0x80101D7C
    // 0x80800B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101D7C(rdram, ctx);
        goto after_112;
    // 0x80800B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_112:
    // 0x80800B3C: b           L_80800C38
    // 0x80800B40: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x80800B40: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_80800B44:
    // 0x80800B44: jal         0x800D8FF8
    // 0x80800B48: nop

    func_800D8FF8(rdram, ctx);
        goto after_113;
    // 0x80800B48: nop

    after_113:
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B50: jal         0x8080215C
    // 0x80800B54: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    func_8080215C_sucoasterfly(rdram, ctx);
        goto after_114;
    // 0x80800B54: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_114:
    // 0x80800B58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X222C) << 16);
    // 0x80800B5C: lwc1        $f0, 0x222C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X222C));
    // 0x80800B60: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3210, 0X2230) << 16);
    // 0x80800B64: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800B68: lwc1        $f16, 0x2230($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3210, 0X2230));
    // 0x80800B6C: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800B70: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800B74: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B7C: lui         $a1, 0x20
    ctx->r5 = S32(0X20 << 16);
    // 0x80800B80: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80800B84: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80800B88: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800B8C: mul.s       $f16, $f2, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80800B90: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80800B94: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x80800B98: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800B9C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80800BA0: nop

    // 0x80800BA4: bc1f        L_80800BB0
    if (!c1cs) {
        // 0x80800BA8: nop
    
            goto L_80800BB0;
    }
    // 0x80800BA8: nop

    // 0x80800BAC: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
L_80800BB0:
    // 0x80800BB0: jal         0x8010B990
    // 0x80800BB4: ori         $a1, $a1, 0x4007
    ctx->r5 = ctx->r5 | 0X4007;
    func_8010B990(rdram, ctx);
        goto after_115;
    // 0x80800BB4: ori         $a1, $a1, 0x4007
    ctx->r5 = ctx->r5 | 0X4007;
    after_115:
    // 0x80800BB8: andi        $t0, $v0, 0x28
    ctx->r8 = ctx->r2 & 0X28;
    // 0x80800BBC: beq         $t0, $zero, L_80800C34
    if (ctx->r8 == 0) {
        // 0x80800BC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C34;
    }
    // 0x80800BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BC4: jal         0x808014AC
    // 0x80800BC8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_116;
    // 0x80800BC8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_116:
    // 0x80800BCC: b           L_80800C38
    // 0x80800BD0: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x80800BD0: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_80800BD4:
    // 0x80800BD4: jal         0x8080215C
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080215C_sucoasterfly(rdram, ctx);
        goto after_117;
    // 0x80800BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_117:
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BE0: jal         0x80801C44
    // 0x80800BE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801C44_sucoasterfly(rdram, ctx);
        goto after_118;
    // 0x80800BE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_118:
    // 0x80800BE8: jal         0x80101DDC
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_119;
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_119:
    // 0x80800BF0: beq         $v0, $zero, L_80800C34
    if (ctx->r2 == 0) {
        // 0x80800BF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C34;
    }
    // 0x80800BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BF8: jal         0x8008A4B0
    // 0x80800BFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_120;
    // 0x80800BFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_120:
    // 0x80800C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C04: jal         0x80107070
    // 0x80800C08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80107070(rdram, ctx);
        goto after_121;
    // 0x80800C08: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_121:
    // 0x80800C0C: bne         $v0, $zero, L_80800C34
    if (ctx->r2 != 0) {
        // 0x80800C10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C34;
    }
    // 0x80800C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C14: jal         0x808014AC
    // 0x80800C18: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_122;
    // 0x80800C18: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_122:
    // 0x80800C1C: jal         0x80089CA8
    // 0x80800C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_123;
    // 0x80800C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_123:
    // 0x80800C24: b           L_80800C38
    // 0x80800C28: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
        goto L_80800C38;
    // 0x80800C28: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_80800C2C:
    // 0x80800C2C: jal         0x8080215C
    // 0x80800C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080215C_sucoasterfly(rdram, ctx);
        goto after_124;
    // 0x80800C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_124:
L_80800C34:
    // 0x80800C34: lwc1        $f12, 0xC0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC0);
L_80800C38:
    // 0x80800C38: jal         0x800F1DCC
    // 0x80800C3C: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_125;
    // 0x80800C3C: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    after_125:
    // 0x80800C40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800C44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C48: lwc1        $f8, 0xBC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80800C4C: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x80800C50: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C54: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800C58: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80800C5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800C60: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80800C64: lui         $a3, 0xC140
    ctx->r7 = S32(0XC140 << 16);
    // 0x80800C68: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80800C6C: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800C70: jal         0x800F10B4
    // 0x80800C74: nop

    func_800F10B4(rdram, ctx);
        goto after_126;
    // 0x80800C74: nop

    after_126:
    // 0x80800C78: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800C7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800C80: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80800C84: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800C88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800C8C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800C90: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800C94: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80800C98: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80800C9C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800CA0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80800CA4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800CA8: jal         0x800F1FF0
    // 0x80800CAC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_127;
    // 0x80800CAC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_127:
    // 0x80800CB0: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80800CB4: jal         0x801072A8
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801072A8(rdram, ctx);
        goto after_128;
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_128:
    // 0x80800CBC: beq         $v0, $zero, L_80800CD4
    if (ctx->r2 == 0) {
        // 0x80800CC0: nop
    
            goto L_80800CD4;
    }
    // 0x80800CC0: nop

    // 0x80800CC4: jal         0x801072E4
    // 0x80800CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801072E4(rdram, ctx);
        goto after_129;
    // 0x80800CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_129:
    // 0x80800CCC: beql        $v0, $zero, L_80800CE0
    if (ctx->r2 == 0) {
        // 0x80800CD0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800CE0;
    }
    goto skip_14;
    // 0x80800CD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_14:
L_80800CD4:
    // 0x80800CD4: jal         0x8010D690
    // 0x80800CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010D690(rdram, ctx);
        goto after_130;
    // 0x80800CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_130:
    // 0x80800CDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CE0:
    // 0x80800CE0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800CE4: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    // 0x80800CE8: jr          $ra
    // 0x80800CEC: nop

    return;
    // 0x80800CEC: nop

;}
RECOMP_FUNC void func_808000CC_gzreg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000D8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808000DC: jal         0x800F21C4
    // 0x808000E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F21C4(rdram, ctx);
        goto after_0;
    // 0x808000E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000E4: sltiu       $at, $v0, 0xA
    ctx->r1 = ctx->r2 < 0XA ? 1 : 0;
    // 0x808000E8: beq         $at, $zero, L_80800190
    if (ctx->r1 == 0) {
        // 0x808000EC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800190;
    }
    // 0x808000EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000F0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808000F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3394, 0XE6C) << 16);
    // 0x808000F8: addu        $at, $at, $t6
    gpr jr_addend_80800100 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808000FC: lw          $t6, 0xE6C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3394, 0XE6C));
    // 0x80800100: jr          $t6
    // 0x80800104: nop

    switch (jr_addend_80800100 >> 2) {
        case 0: goto L_80800108; break;
        case 1: goto L_8080011C; break;
        case 2: goto L_80800130; break;
        case 3: goto L_80800144; break;
        case 4: goto L_80800158; break;
        case 5: goto L_80800158; break;
        case 6: goto L_80800180; break;
        case 7: goto L_80800180; break;
        case 8: goto L_80800158; break;
        case 9: goto L_80800158; break;
        default: switch_error(__func__, 0x80800100, 0x80800E6C);
    }
    // 0x80800104: nop

L_80800108:
    // 0x80800108: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3394, 0XB64) << 16);
    // 0x8080010C: jal         0x8002DC20
    // 0x80800110: addiu       $a1, $a1, 0xB64
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XB64));
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x80800110: addiu       $a1, $a1, 0xB64
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XB64));
    after_1:
    // 0x80800114: b           L_80800194
    // 0x80800118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800194;
    // 0x80800118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080011C:
    // 0x8080011C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3394, 0XB6C) << 16);
    // 0x80800120: jal         0x8002DC20
    // 0x80800124: addiu       $a1, $a1, 0xB6C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XB6C));
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x80800124: addiu       $a1, $a1, 0xB6C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XB6C));
    after_2:
    // 0x80800128: b           L_80800194
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800194;
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800130:
    // 0x80800130: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3394, 0XB74) << 16);
    // 0x80800134: jal         0x8002DC20
    // 0x80800138: addiu       $a1, $a1, 0xB74
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XB74));
    sprintf_recomp(rdram, ctx);
        goto after_3;
    // 0x80800138: addiu       $a1, $a1, 0xB74
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XB74));
    after_3:
    // 0x8080013C: b           L_80800194
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800194;
    // 0x80800140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800144:
    // 0x80800144: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3394, 0XB7C) << 16);
    // 0x80800148: jal         0x8002DC20
    // 0x8080014C: addiu       $a1, $a1, 0xB7C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XB7C));
    sprintf_recomp(rdram, ctx);
        goto after_4;
    // 0x8080014C: addiu       $a1, $a1, 0xB7C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XB7C));
    after_4:
    // 0x80800150: b           L_80800194
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800194;
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800158:
    // 0x80800158: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8080015C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3394, 0XB84) << 16);
    // 0x80800160: addiu       $a1, $a1, 0xB84
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XB84));
    // 0x80800164: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80800168: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8080016C: mfc1        $a2, $f7
    ctx->r6 = (int32_t)ctx->f_odd[(7 - 1) * 2];
    // 0x80800170: jal         0x8002DC20
    // 0x80800174: nop

    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x80800174: nop

    after_5:
    // 0x80800178: b           L_80800194
    // 0x8080017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800194;
    // 0x8080017C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800180:
    // 0x80800180: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3394, 0XB8C) << 16);
    // 0x80800184: addiu       $a1, $a1, 0xB8C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XB8C));
    // 0x80800188: jal         0x8002DC20
    // 0x8080018C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    sprintf_recomp(rdram, ctx);
        goto after_6;
    // 0x8080018C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_6:
L_80800190:
    // 0x80800190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800194:
    // 0x80800194: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800198: jr          $ra
    // 0x8080019C: nop

    return;
    // 0x8080019C: nop

;}
RECOMP_FUNC void func_8080005C_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800060: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800064: jal         0x80092AD8
    // 0x80800068: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80092AD8(rdram, ctx);
        goto after_0;
    // 0x80800068: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080006C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800070: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800074: jal         0x800E0AF0
    // 0x80800078: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_1;
    // 0x80800078: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_1:
    // 0x8080007C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800080: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800084: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    // 0x80800088: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080008C: lui         $a3, 0xC248
    ctx->r7 = S32(0XC248 << 16);
    // 0x80800090: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800094: jal         0x800E0AFC
    // 0x80800098: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_2;
    // 0x80800098: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8080009C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808000A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808000A8: lwc1        $f4, 0x170($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X170);
    // 0x808000AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808000B0: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x808000B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808000B8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x808000BC: jal         0x800E0AFC
    // 0x808000C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_3;
    // 0x808000C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x808000C4: jal         0x800D8FF8
    // 0x808000C8: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x808000C8: nop

    after_4:
    // 0x808000CC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808000D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000D4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808000D8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808000DC: lwc1        $f6, 0x170($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X170);
    // 0x808000E0: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x808000E4: swc1        $f16, 0x170($t7)
    MEM_W(0X170, ctx->r15) = ctx->f16.u32l;
    // 0x808000E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000F0: jr          $ra
    // 0x808000F4: nop

    return;
    // 0x808000F4: nop

;}
RECOMP_FUNC void func_80800190_chfactorytoxicpools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800194: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800198: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080019C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001A4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808001A8: beq         $a1, $at, L_808001C4
    if (ctx->r5 == ctx->r1) {
        // 0x808001AC: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808001C4;
    }
    // 0x808001AC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808001B0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808001B4: beq         $a1, $at, L_80800220
    if (ctx->r5 == ctx->r1) {
        // 0x808001B8: nop
    
            goto L_80800220;
    }
    // 0x808001B8: nop

    // 0x808001BC: b           L_80800248
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800248;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001C4:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: jal         0x80100094
    // 0x808001CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808001D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: jal         0x80103110
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x808001DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808001E0: jal         0x8010A570
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001E8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808001EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808001F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808001F4: sh          $t7, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r15;
    // 0x808001F8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800200: jal         0x80085708
    // 0x80800204: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800204: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_3:
    // 0x80800208: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1156, 0XA18) << 16);
    // 0x8080020C: addiu       $a1, $a1, 0xA18
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1156, 0XA18));
    // 0x80800210: jal         0x800C4AF0
    // 0x80800214: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800C4AF0(rdram, ctx);
        goto after_4;
    // 0x80800214: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80800218: b           L_8080025C
    // 0x8080021C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080025C;
    // 0x8080021C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800220:
    // 0x80800220: jal         0x800BEA88
    // 0x80800224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_5;
    // 0x80800224: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80800228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080022C: addiu       $a1, $zero, 0x659
    ctx->r5 = ADD32(0, 0X659);
    // 0x80800230: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800234: jal         0x80088F28
    // 0x80800238: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80800238: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x8080023C: jal         0x80800270
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800270_chfactorytoxicpools(rdram, ctx);
        goto after_7;
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800248:
    // 0x80800248: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080024C: jal         0x80085820
    // 0x80800250: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_8;
    // 0x80800250: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x80800254: b           L_80800260
    // 0x80800258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800260;
    // 0x80800258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080025C:
    // 0x8080025C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800260:
    // 0x80800260: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800264: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800268: jr          $ra
    // 0x8080026C: nop

    return;
    // 0x8080026C: nop

;}
RECOMP_FUNC void subaddiefade_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: lbu         $t6, 0x79($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X79);
    // 0x80800038: andi        $t7, $t6, 0xFFFC
    ctx->r15 = ctx->r14 & 0XFFFC;
    // 0x8080003C: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x80800040: jr          $ra
    // 0x80800044: sb          $t8, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r24;
    return;
    // 0x80800044: sb          $t8, 0x79($a0)
    MEM_B(0X79, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8080440C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080440C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80804410: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804414: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804418: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080441C: jal         0x80100094
    // 0x80804420: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804420: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804424: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CF0) << 16);
    // 0x80804428: lwc1        $f4, 0x4CF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CF0));
    // 0x8080442C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80804430: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80804434: jal         0x800EFD24
    // 0x80804438: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80804438: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x8080443C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80804440: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80804444: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804448: swc1        $f6, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f6.u32l;
    // 0x8080444C: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x80804450: srl         $t7, $v0, 4
    ctx->r15 = S32(U32(ctx->r2) >> 4);
    // 0x80804454: beql        $t7, $zero, L_80804480
    if (ctx->r15 == 0) {
        // 0x80804458: lw          $v0, 0x6C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X6C);
            goto L_80804480;
    }
    goto skip_0;
    // 0x80804458: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    skip_0:
    // 0x8080445C: beq         $t7, $at, L_8080447C
    if (ctx->r15 == ctx->r1) {
        // 0x80804460: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080447C;
    }
    // 0x80804460: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804464: beq         $t7, $at, L_8080447C
    if (ctx->r15 == ctx->r1) {
        // 0x80804468: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080447C;
    }
    // 0x80804468: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080446C: beq         $t7, $at, L_80804520
    if (ctx->r15 == ctx->r1) {
        // 0x80804470: nop
    
            goto L_80804520;
    }
    // 0x80804470: nop

    // 0x80804474: b           L_8080454C
    // 0x80804478: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080454C;
    // 0x80804478: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080447C:
    // 0x8080447C: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
L_80804480:
    // 0x80804480: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804488: andi        $t8, $v0, 0x1FF
    ctx->r24 = ctx->r2 & 0X1FF;
    // 0x8080448C: beql        $t8, $zero, L_808044C0
    if (ctx->r24 == 0) {
        // 0x80804490: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_808044C0;
    }
    goto skip_1;
    // 0x80804490: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x80804494: beq         $t8, $at, L_808044F0
    if (ctx->r24 == ctx->r1) {
        // 0x80804498: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808044F0;
    }
    // 0x80804498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080449C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808044A0: beq         $t8, $at, L_80804500
    if (ctx->r24 == ctx->r1) {
        // 0x808044A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804500;
    }
    // 0x808044A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808044A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808044AC: beq         $t8, $at, L_80804510
    if (ctx->r24 == ctx->r1) {
        // 0x808044B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804510;
    }
    // 0x808044B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808044B4: b           L_8080454C
    // 0x808044B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080454C;
    // 0x808044B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808044BC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_808044C0:
    // 0x808044C0: addiu       $a1, $zero, 0x828
    ctx->r5 = ADD32(0, 0X828);
    // 0x808044C4: jal         0x80103140
    // 0x808044C8: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    func_80103140(rdram, ctx);
        goto after_2;
    // 0x808044C8: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    after_2:
    // 0x808044CC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x808044D0: jal         0x800904F4
    // 0x808044D4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800904F4(rdram, ctx);
        goto after_3;
    // 0x808044D4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808044D8: jal         0x800904C8
    // 0x808044DC: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    func_800904C8(rdram, ctx);
        goto after_4;
    // 0x808044DC: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    after_4:
    // 0x808044E0: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x808044E4: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x808044E8: b           L_80804548
    // 0x808044EC: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
        goto L_80804548;
    // 0x808044EC: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_808044F0:
    // 0x808044F0: jal         0x8080422C
    // 0x808044F4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_8080422C_chdodgemcontrol(rdram, ctx);
        goto after_5;
    // 0x808044F4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x808044F8: b           L_8080454C
    // 0x808044FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080454C;
    // 0x808044FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804500:
    // 0x80804500: jal         0x8080422C
    // 0x80804504: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8080422C_chdodgemcontrol(rdram, ctx);
        goto after_6;
    // 0x80804504: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_6:
    // 0x80804508: b           L_8080454C
    // 0x8080450C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080454C;
    // 0x8080450C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804510:
    // 0x80804510: jal         0x8080422C
    // 0x80804514: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8080422C_chdodgemcontrol(rdram, ctx);
        goto after_7;
    // 0x80804514: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_7:
    // 0x80804518: b           L_8080454C
    // 0x8080451C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080454C;
    // 0x8080451C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80804520:
    // 0x80804520: jal         0x80088368
    // 0x80804524: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80804524: nop

    after_8:
    // 0x80804528: lw          $t3, 0x6C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X6C);
    // 0x8080452C: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x80804530: sltu        $at, $t4, $v0
    ctx->r1 = ctx->r12 < ctx->r2 ? 1 : 0;
    // 0x80804534: beql        $at, $zero, L_8080454C
    if (ctx->r1 == 0) {
        // 0x80804538: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080454C;
    }
    goto skip_2;
    // 0x80804538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8080453C: lbu         $t6, 0x64($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X64);
    // 0x80804540: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x80804544: sb          $t7, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r15;
L_80804548:
    // 0x80804548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080454C:
    // 0x8080454C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804550: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80804554: jr          $ra
    // 0x80804558: nop

    return;
    // 0x80804558: nop

;}
RECOMP_FUNC void _bskazeggass_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083340: syscall     55
    recomp_syscall_handler(rdram, ctx, 0x80083340);
    return;
    // 0x80083344: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chpodiumbankaz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2148, 0X548) << 16);
    // 0x808004EC: jr          $ra
    // 0x808004F0: addiu       $v0, $v0, 0x548
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2148, 0X548));
    return;
    // 0x808004F0: addiu       $v0, $v0, 0x548
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2148, 0X548));
    // 0x808004F4: nop

    // 0x808004F8: nop

    // 0x808004FC: nop

;}
RECOMP_FUNC void func_80106768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106768: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010676C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80106770: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106774: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106778: jal         0x800B28CC
    // 0x8010677C: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x8010677C: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    after_0:
    // 0x80106780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106788: jr          $ra
    // 0x8010678C: nop

    return;
    // 0x8010678C: nop

;}
RECOMP_FUNC void func_80800044_chfactoryflypad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800048: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080004C: bne         $a1, $at, L_80800068
    if (ctx->r5 != ctx->r1) {
        // 0x80800050: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800068;
    }
    // 0x80800050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800054: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80800058: jal         0x800887D8
    // 0x8080005C: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x8080005C: addiu       $a1, $zero, 0x42
    ctx->r5 = ADD32(0, 0X42);
    after_0:
    // 0x80800060: b           L_80800070
    // 0x80800064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800070;
    // 0x80800064: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800068:
    // 0x80800068: jal         0x80085820
    // 0x8080006C: nop

    _chswitch_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x8080006C: nop

    after_1:
L_80800070:
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void sumole_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808014E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808014E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808014EC: jal         0x80106790
    // 0x808014F0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808014F0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808014F4: jal         0x800C064C
    // 0x808014F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800C064C(rdram, ctx);
        goto after_1;
    // 0x808014F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808014FC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80801500: bne         $v0, $a0, L_80801554
    if (ctx->r2 != ctx->r4) {
        // 0x80801504: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80801554;
    }
    // 0x80801504: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801508: lw          $t7, 0x64($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X64);
    // 0x8080150C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801510: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80801514: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80801518: bnel        $t9, $at, L_80801558
    if (ctx->r25 != ctx->r1) {
        // 0x8080151C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801558;
    }
    goto skip_0;
    // 0x8080151C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80801520: lw          $t0, 0x3C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X3C);
    // 0x80801524: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80801528: beql        $t0, $zero, L_80801558
    if (ctx->r8 == 0) {
        // 0x8080152C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80801558;
    }
    goto skip_1;
    // 0x8080152C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80801530: beq         $v1, $a0, L_8080154C
    if (ctx->r3 == ctx->r4) {
        // 0x80801534: lw          $v0, 0x20($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X20);
            goto L_8080154C;
    }
    // 0x80801534: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80801538: lbu         $t4, 0x72($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X72);
    // 0x8080153C: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80801540: andi        $t5, $t4, 0xFF03
    ctx->r13 = ctx->r12 & 0XFF03;
    // 0x80801544: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80801548: sb          $t6, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r14;
L_8080154C:
    // 0x8080154C: b           L_80801558
    // 0x80801550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801558;
    // 0x80801550: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801554:
    // 0x80801554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801558:
    // 0x80801558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080155C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801560: jr          $ra
    // 0x80801564: nop

    return;
    // 0x80801564: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A608: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A608);
    return;
    // 0x8008A60C: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void _ncbadolly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089368: syscall     775
    recomp_syscall_handler(rdram, ctx, 0x80089368);
    return;
    // 0x8008936C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801F5C_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801F60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801F64: jal         0x80800ECC
    // 0x80801F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstnt_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801F68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801F6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801F70: jal         0x800845D8
    // 0x80801F74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801F74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80801F78: lui         $a2, 0x3ED0
    ctx->r6 = S32(0X3ED0 << 16);
    // 0x80801F7C: ori         $a2, $a2, 0xFF97
    ctx->r6 = ctx->r6 | 0XFF97;
    // 0x80801F80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801F84: jal         0x800845E0
    // 0x80801F88: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80801F88: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    after_2:
    // 0x80801F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801F94: jr          $ra
    // 0x80801F98: nop

    return;
    // 0x80801F98: nop

;}
RECOMP_FUNC void func_80800254_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800254: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800258: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080025C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800260: jal         0x800A3048
    // 0x80800264: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A3048(rdram, ctx);
        goto after_0;
    // 0x80800264: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800268: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080026C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800270: nop

    // 0x80800274: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800278: jal         0x800D8FF8
    // 0x8080027C: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8080027C: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80800280: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800284: jal         0x8008E35C
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_2;
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080028C: beq         $v0, $zero, L_808002D0
    if (ctx->r2 == 0) {
        // 0x80800290: sw          $v0, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r2;
            goto L_808002D0;
    }
    // 0x80800290: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x8009BCB4
    // 0x8080029C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_3;
    // 0x8080029C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: jal         0x8009BCC4
    // 0x808002A8: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_4;
    // 0x808002A8: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    after_4:
    // 0x808002AC: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808002B0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808002B4: jal         0x80084EF0
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovethrust_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C0: jal         0x80084EE8
    // 0x808002C4: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    _bamovethrust_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808002C4: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_6:
    // 0x808002C8: b           L_8080031C
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080031C;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002D0:
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D4: jal         0x8009BCB4
    // 0x808002D8: lui         $a1, 0xC4E1
    ctx->r5 = S32(0XC4E1 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_7;
    // 0x808002D8: lui         $a1, 0xC4E1
    ctx->r5 = S32(0XC4E1 << 16);
    after_7:
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E0: jal         0x8009BCC4
    // 0x808002E4: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_8;
    // 0x808002E4: lui         $a1, 0xC57A
    ctx->r5 = S32(0XC57A << 16);
    after_8:
    // 0x808002E8: lui         $a1, 0x3F73
    ctx->r5 = S32(0X3F73 << 16);
    // 0x808002EC: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808002F0: jal         0x80084EF0
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovethrust_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002F8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808002FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800300: lwc1        $f8, 0x16C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8080030C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800310: jal         0x80084EE8
    // 0x80800314: nop

    _bamovethrust_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80800314: nop

    after_10:
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080031C:
    // 0x8080031C: jal         0x800919F4
    // 0x80800320: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_held(rdram, ctx);
        goto after_11;
    // 0x80800320: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_11:
    // 0x80800324: bnel        $v0, $zero, L_80800350
    if (ctx->r2 != 0) {
        // 0x80800328: lwc1        $f12, 0x16C($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
            goto L_80800350;
    }
    goto skip_0;
    // 0x80800328: lwc1        $f12, 0x16C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
    skip_0:
    // 0x8080032C: jal         0x80085190
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basub_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800334: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800338: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8080033C: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x80800340: nop

    // 0x80800344: bc1t        L_80800360
    if (c1cs) {
        // 0x80800348: nop
    
            goto L_80800360;
    }
    // 0x80800348: nop

    // 0x8080034C: lwc1        $f12, 0x16C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
L_80800350:
    // 0x80800350: jal         0x80800030
    // 0x80800354: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    func_80800030_bssub(rdram, ctx);
        goto after_13;
    // 0x80800354: lwc1        $f14, 0x4C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X4C);
    after_13:
    // 0x80800358: b           L_8080036C
    // 0x8080035C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8080036C;
    // 0x8080035C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800360:
    // 0x80800360: jal         0x80800048
    // 0x80800364: lwc1        $f12, 0x16C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
    func_80800048_bssub(rdram, ctx);
        goto after_14;
    // 0x80800364: lwc1        $f12, 0x16C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
    after_14:
    // 0x80800368: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8080036C:
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800370: jal         0x80085190
    // 0x80800374: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    _basub_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x80800374: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    after_15:
    // 0x80800378: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080037C: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800380: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800384: nop

    // 0x80800388: bc1t        L_808003B8
    if (c1cs) {
        // 0x8080038C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003B8;
    }
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: jal         0x80085190
    // 0x80800394: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    _basub_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x80800394: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    after_16:
    // 0x80800398: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8080039C: lwc1        $f6, 0x16C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808003A0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808003A8: jal         0x800F0D50
    // 0x808003AC: add.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f2.fl;
    func_800F0D50(rdram, ctx);
        goto after_17;
    // 0x808003AC: add.s       $f12, $f6, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f2.fl;
    after_17:
    // 0x808003B0: b           L_808003D0
    // 0x808003B4: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
        goto L_808003D0;
    // 0x808003B4: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
L_808003B8:
    // 0x808003B8: lwc1        $f8, 0x16C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808003BC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003C0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x808003C4: jal         0x800F0D50
    // 0x808003C8: add.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f2.fl;
    func_800F0D50(rdram, ctx);
        goto after_18;
    // 0x808003C8: add.s       $f12, $f8, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f2.fl;
    after_18:
    // 0x808003CC: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
L_808003D0:
    // 0x808003D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16C0) << 16);
    // 0x808003D4: lwc1        $f10, 0x16C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16C0));
    // 0x808003D8: lwc1        $f12, 0x16C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808003DC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808003E0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x808003E4: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    // 0x808003E8: jal         0x800F10B4
    // 0x808003EC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_19;
    // 0x808003EC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_19:
    // 0x808003F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003F4: jal         0x800851E8
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basub_entrypoint_13(rdram, ctx);
        goto after_20;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808003FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16C4) << 16);
    // 0x80800400: lwc1        $f16, 0x16C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16C4));
    // 0x80800404: lwc1        $f12, 0x16C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800408: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080040C: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800410: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800414: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80800418: jal         0x800F10B4
    // 0x8080041C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_21;
    // 0x8080041C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_21:
    // 0x80800420: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80800424: jal         0x8009C990
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_22;
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8080042C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800430: jal         0x8009C984
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_23;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800438: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080043C: jal         0x800F1DCC
    // 0x80800440: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_24;
    // 0x80800440: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_24:
    // 0x80800444: jal         0x800F2100
    // 0x80800448: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_25;
    // 0x80800448: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_25:
    // 0x8080044C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16C8) << 16);
    // 0x80800450: lwc1        $f4, 0x16C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16C8));
    // 0x80800454: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800458: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080045C: lui         $a2, 0x4300
    ctx->r6 = S32(0X4300 << 16);
    // 0x80800460: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800464: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80800468: jal         0x800F10B4
    // 0x8080046C: div.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    func_800F10B4(rdram, ctx);
        goto after_26;
    // 0x8080046C: div.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    after_26:
    // 0x80800470: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80800474: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800478: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16CC) << 16);
    // 0x8080047C: bne         $t6, $zero, L_8080048C
    if (ctx->r14 != 0) {
        // 0x80800480: add.s       $f2, $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_8080048C;
    }
    // 0x80800480: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80800484: lwc1        $f6, 0x16CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16CC));
    // 0x80800488: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_8080048C:
    // 0x8080048C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800490: jal         0x800851D8
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basub_entrypoint_11(rdram, ctx);
        goto after_27;
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800498: jal         0x8009BFD8
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BFD8(rdram, ctx);
        goto after_28;
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808004A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808004A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004A8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808004AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808004B0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808004B4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808004B8: lui         $a2, 0x42AA
    ctx->r6 = S32(0X42AA << 16);
    // 0x808004BC: bc1fl       L_808004D4
    if (!c1cs) {
        // 0x808004C0: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_808004D4;
    }
    goto skip_1;
    // 0x808004C0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_1:
    // 0x808004C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808004C8: nop

    // 0x808004CC: sub.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x808004D0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
L_808004D4:
    // 0x808004D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808004D8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x808004DC: jal         0x800F1344
    // 0x808004E0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F1344(rdram, ctx);
        goto after_29;
    // 0x808004E0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_29:
    // 0x808004E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004E8: jal         0x800851E0
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basub_entrypoint_12(rdram, ctx);
        goto after_30;
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x808004F0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x808004F4: beql        $t7, $zero, L_80800580
    if (ctx->r15 == 0) {
        // 0x808004F8: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80800580;
    }
    goto skip_2;
    // 0x808004F8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_2:
    // 0x808004FC: jal         0x80085190
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _basub_entrypoint_2(rdram, ctx);
        goto after_31;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80800504: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080050C: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800510: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x80800514: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800518: bc1tl       L_80800534
    if (c1cs) {
        // 0x8080051C: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_80800534;
    }
    goto skip_3;
    // 0x8080051C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_3:
    // 0x80800520: jal         0x800914FC
    // 0x80800524: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800914FC(rdram, ctx);
        goto after_32;
    // 0x80800524: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_32:
    // 0x80800528: b           L_80800618
    // 0x8080052C: nop

        goto L_80800618;
    // 0x8080052C: nop

    // 0x80800530: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_80800534:
    // 0x80800534: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800538: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080053C: jal         0x800DC178
    // 0x80800540: nop

    func_800DC178(rdram, ctx);
        goto after_33;
    // 0x80800540: nop

    after_33:
    // 0x80800544: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800548: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080054C: lwc1        $f12, 0x16C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800550: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800554: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800558: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8080055C: jal         0x800F10B4
    // 0x80800560: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_34;
    // 0x80800560: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_34:
    // 0x80800564: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080056C: jal         0x800914FC
    // 0x80800570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800914FC(rdram, ctx);
        goto after_35;
    // 0x80800570: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_35:
    // 0x80800574: b           L_80800618
    // 0x80800578: nop

        goto L_80800618;
    // 0x80800578: nop

    // 0x8080057C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80800580:
    // 0x80800580: lwc1        $f8, 0x16C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80800584: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800588: nop

    // 0x8080058C: bc1f        L_80800618
    if (!c1cs) {
        // 0x80800590: nop
    
            goto L_80800618;
    }
    // 0x80800590: nop

    // 0x80800594: jal         0x8008E078
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_36;
    // 0x80800598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x8080059C: beq         $v0, $zero, L_80800618
    if (ctx->r2 == 0) {
        // 0x808005A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800618;
    }
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A4: jal         0x8009C128
    // 0x808005A8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009C128(rdram, ctx);
        goto after_37;
    // 0x808005A8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_37:
    // 0x808005AC: jal         0x800B5BE4
    // 0x808005B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B5BE4(rdram, ctx);
        goto after_38;
    // 0x808005B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_38:
    // 0x808005B4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(380, 0X16E0) << 16);
    // 0x808005B8: addiu       $t8, $t8, 0x16E0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(380, 0X16E0));
    // 0x808005BC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808005C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808005C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005C8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x808005CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005D0: jal         0x800BABB8
    // 0x808005D4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_39;
    // 0x808005D4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_39:
    // 0x808005D8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808005DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16D0) << 16);
    // 0x808005E0: jal         0x800DC178
    // 0x808005E4: lwc1        $f14, 0x16D0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16D0));
    func_800DC178(rdram, ctx);
        goto after_40;
    // 0x808005E4: lwc1        $f14, 0x16D0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16D0));
    after_40:
    // 0x808005E8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808005EC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808005F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005F8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x808005FC: nop

    // 0x80800600: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x80800604: jal         0x800BA77C
    // 0x80800608: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_41;
    // 0x80800608: sra         $a3, $t0, 16
    ctx->r7 = S32(SIGNED(ctx->r8) >> 16);
    after_41:
    // 0x8080060C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800610: jal         0x800BA22C
    // 0x80800614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_42;
    // 0x80800614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_42:
L_80800618:
    // 0x80800618: jal         0x808000F0
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000F0_bssub(rdram, ctx);
        goto after_43;
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x80800620: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800624: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800628: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080062C: jr          $ra
    // 0x80800630: nop

    return;
    // 0x80800630: nop

;}
RECOMP_FUNC void func_808000E0_bahold(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808000EC: jal         0x8008FF40
    // 0x808000F0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_8008FF40(rdram, ctx);
        goto after_0;
    // 0x808000F0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x808000F4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808000F8: jal         0x80092D44
    // 0x808000FC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80092D44(rdram, ctx);
        goto after_1;
    // 0x808000FC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800100: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800104: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800108: lw          $t7, 0x9C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X9C);
    // 0x8080010C: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80800110: jal         0x800136E4
    // 0x80800114: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x80800114: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_2:
    // 0x80800118: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8080011C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800120: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800124: lw          $t8, 0x9C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X9C);
    // 0x80800128: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080012C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x80800130: lwc1        $f10, 0x0($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80800134: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800138: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8080013C: lw          $t9, 0x9C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X9C);
    // 0x80800140: jal         0x80800088
    // 0x80800144: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    func_80800088_bahold(rdram, ctx);
        goto after_3;
    // 0x80800144: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    after_3:
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080014C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800150: jr          $ra
    // 0x80800154: nop

    return;
    // 0x80800154: nop

;}
RECOMP_FUNC void func_80801174_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801174: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801178: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8080117C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801180: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801184: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80801188: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x8080118C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80801190: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80801194: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80801198: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8080119C: lw          $t7, 0x4C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4C);
    // 0x808011A0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808011A4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808011A8: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x808011AC: beq         $t8, $zero, L_808011BC
    if (ctx->r24 == 0) {
        // 0x808011B0: addiu       $a0, $v0, 0x24
        ctx->r4 = ADD32(ctx->r2, 0X24);
            goto L_808011BC;
    }
    // 0x808011B0: addiu       $a0, $v0, 0x24
    ctx->r4 = ADD32(ctx->r2, 0X24);
    // 0x808011B4: b           L_8080130C
    // 0x808011B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080130C;
    // 0x808011B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011BC:
    // 0x808011BC: lw          $a1, 0x30($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X30);
    // 0x808011C0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x808011C4: jal         0x800E3E8C
    // 0x808011C8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_800E3E8C(rdram, ctx);
        goto after_0;
    // 0x808011C8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x808011CC: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x808011D0: beq         $v0, $zero, L_80801308
    if (ctx->r2 == 0) {
        // 0x808011D4: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_80801308;
    }
    // 0x808011D4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808011D8: lw          $t9, 0x68($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X68);
    // 0x808011DC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x808011E0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x808011E4: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
    // 0x808011E8: addiu       $a0, $v0, 0xC
    ctx->r4 = ADD32(ctx->r2, 0XC);
    // 0x808011EC: jal         0x800E3D0C
    // 0x808011F0: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    func_800E3D0C(rdram, ctx);
        goto after_1;
    // 0x808011F0: addiu       $a1, $v0, 0x18
    ctx->r5 = ADD32(ctx->r2, 0X18);
    after_1:
    // 0x808011F4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x808011F8: beq         $v0, $zero, L_80801308
    if (ctx->r2 == 0) {
        // 0x808011FC: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_80801308;
    }
    // 0x808011FC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80801200: lw          $t2, 0x68($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X68);
    // 0x80801204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801208: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8080120C: addu        $v0, $t2, $v1
    ctx->r2 = ADD32(ctx->r10, ctx->r3);
    // 0x80801210: lbu         $t4, 0x4C($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X4C);
    // 0x80801214: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80801218: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    // 0x8080121C: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x80801220: sb          $t5, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r13;
    // 0x80801224: lw          $t6, 0x68($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X68);
    // 0x80801228: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8080122C: lbu         $t8, 0x4C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4C);
    // 0x80801230: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x80801234: sb          $t9, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r25;
    // 0x80801238: lw          $t2, 0x68($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X68);
    // 0x8080123C: addu        $v0, $t2, $v1
    ctx->r2 = ADD32(ctx->r10, ctx->r3);
    // 0x80801240: lw          $t3, 0x4C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4C);
    // 0x80801244: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80801248: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x8080124C: bgezl       $t5, L_80801268
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80801250: lbu         $t8, 0x4C($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X4C);
            goto L_80801268;
    }
    goto skip_0;
    // 0x80801250: lbu         $t8, 0x4C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4C);
    skip_0:
    // 0x80801254: lw          $t7, 0x68($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X68);
    // 0x80801258: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080125C: sb          $t6, 0x7B($a3)
    MEM_B(0X7B, ctx->r7) = ctx->r14;
    // 0x80801260: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80801264: lbu         $t8, 0x4C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4C);
L_80801268:
    // 0x80801268: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8080126C: beq         $t9, $zero, L_80801278
    if (ctx->r25 == 0) {
        // 0x80801270: nop
    
            goto L_80801278;
    }
    // 0x80801270: nop

    // 0x80801274: sb          $t2, 0x7E($a3)
    MEM_B(0X7E, ctx->r7) = ctx->r10;
L_80801278:
    // 0x80801278: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8080127C: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x80801280: lw          $v1, 0x68($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X68);
    // 0x80801284: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80801288: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x8080128C: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80801290: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x80801294: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80801298: lbu         $a1, 0x38($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X38);
    // 0x8080129C: beq         $t0, $a1, L_80801300
    if (ctx->r8 == ctx->r5) {
        // 0x808012A0: nop
    
            goto L_80801300;
    }
    // 0x808012A0: nop

    // 0x808012A4: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808012A8: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x808012AC: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x808012B0: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x808012B4: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x808012B8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x808012BC: mflo        $t6
    ctx->r14 = lo;
    // 0x808012C0: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x808012C4: lbu         $t8, 0x4C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4C);
    // 0x808012C8: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x808012CC: sb          $t9, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r25;
    // 0x808012D0: lw          $v1, 0x68($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X68);
    // 0x808012D4: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x808012D8: addu        $t4, $t3, $a0
    ctx->r12 = ADD32(ctx->r11, ctx->r4);
    // 0x808012DC: lbu         $t5, 0x38($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X38);
    // 0x808012E0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808012E4: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808012E8: mflo        $t6
    ctx->r14 = lo;
    // 0x808012EC: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x808012F0: lbu         $t8, 0x4C($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4C);
    // 0x808012F4: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x808012F8: bne         $a0, $t1, L_80801278
    if (ctx->r4 != ctx->r9) {
        // 0x808012FC: sb          $t9, 0x4C($v0)
        MEM_B(0X4C, ctx->r2) = ctx->r25;
            goto L_80801278;
    }
    // 0x808012FC: sb          $t9, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r25;
L_80801300:
    // 0x80801300: b           L_8080130C
    // 0x80801304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080130C;
    // 0x80801304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801308:
    // 0x80801308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080130C:
    // 0x8080130C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801310: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801318: jr          $ra
    // 0x8080131C: nop

    return;
    // 0x8080131C: nop

;}
RECOMP_FUNC void func_80800000_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x8009E6EC
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800018: beq         $v0, $at, L_8080003C
    if (ctx->r2 == ctx->r1) {
        // 0x8080001C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080003C;
    }
    // 0x8080001C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800020: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80800024: beq         $v0, $at, L_80800058
    if (ctx->r2 == ctx->r1) {
        // 0x80800028: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_80800058;
    }
    // 0x80800028: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8080002C: beq         $v0, $at, L_80800074
    if (ctx->r2 == ctx->r1) {
        // 0x80800030: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800074;
    }
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: b           L_808000B4
    // 0x80800038: nop

        goto L_808000B4;
    // 0x80800038: nop

L_8080003C:
    // 0x8080003C: jal         0x8009E830
    // 0x80800040: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_1;
    // 0x80800040: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: jal         0x8009E5C8
    // 0x8080004C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x8080004C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_2:
    // 0x80800050: b           L_808000C0
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C0;
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800058:
    // 0x80800058: jal         0x8008E9AC
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E9AC(rdram, ctx);
        goto after_3;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: jal         0x8008F6B8
    // 0x80800068: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8008F6B8(rdram, ctx);
        goto after_4;
    // 0x80800068: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8080006C: b           L_808000C0
    // 0x80800070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C0;
    // 0x80800070: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800074:
    // 0x80800074: jal         0x800915AC
    // 0x80800078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bastatetimer_isDone(rdram, ctx);
        goto after_5;
    // 0x80800078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080007C: beq         $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x80800080: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000A4;
    }
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: jal         0x8009E5C8
    // 0x8080008C: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x8080008C: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    after_6:
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: jal         0x8009E830
    // 0x80800098: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_7;
    // 0x80800098: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8080009C: b           L_808000C0
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C0;
    // 0x808000A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000A4:
    // 0x808000A4: jal         0x8009E830
    // 0x808000A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E830(rdram, ctx);
        goto after_8;
    // 0x808000A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808000AC: b           L_808000C0
    // 0x808000B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C0;
    // 0x808000B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000B4:
    // 0x808000B4: jal         0x80099B94
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099B94(rdram, ctx);
        goto after_9;
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808000BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C0:
    // 0x808000C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void func_808003C4_chsquits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808003C8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x808003CC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x808003D0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x808003D4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x808003D8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x808003DC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x808003E0: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x808003E4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x808003E8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808003EC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808003F0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808003F4: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x808003F8: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1456, 0X694) << 16);
    // 0x808003FC: addiu       $t8, $t8, 0x694
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1456, 0X694));
    // 0x80800400: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800404: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800408: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080040C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800410: addu        $s5, $t7, $t8
    ctx->r21 = ADD32(ctx->r15, ctx->r24);
    // 0x80800414: lwc1        $f24, 0x2C($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80800418: lw          $a1, 0x8($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X8);
    // 0x8080041C: jal         0x800D91EC
    // 0x80800420: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    func_800D91EC(rdram, ctx);
        goto after_0;
    // 0x80800420: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_0:
    // 0x80800424: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80800428: lw          $t9, 0x4($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X4);
    // 0x8080042C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800430: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800434: blez        $t9, L_808004C0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80800438: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1456, 0X5A4) << 16);
            goto L_808004C0;
    }
    // 0x80800438: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1456, 0X5A4) << 16);
    // 0x8080043C: lwc1        $f22, 0x5A4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1456, 0X5A4));
    // 0x80800440: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1456, 0X5A8) << 16);
    // 0x80800444: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(1456, 0X720) << 16);
    // 0x80800448: addiu       $s6, $s6, 0x720
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(1456, 0X720));
    // 0x8080044C: lwc1        $f20, 0x5A8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1456, 0X5A8));
    // 0x80800450: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
L_80800454:
    // 0x80800454: lwc1        $f12, 0x2C($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X2C);
    // 0x80800458: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x8080045C: addu        $s0, $t0, $s3
    ctx->r16 = ADD32(ctx->r8, ctx->r19);
    // 0x80800460: jal         0x80800528
    // 0x80800464: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    func_80800528_chsquits(rdram, ctx);
        goto after_1;
    // 0x80800464: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_1:
    // 0x80800468: beq         $v0, $zero, L_808004A8
    if (ctx->r2 == 0) {
        // 0x8080046C: addiu       $s1, $s4, 0x4
        ctx->r17 = ADD32(ctx->r20, 0X4);
            goto L_808004A8;
    }
    // 0x8080046C: addiu       $s1, $s4, 0x4
    ctx->r17 = ADD32(ctx->r20, 0X4);
    // 0x80800470: jal         0x800C4B7C
    // 0x80800474: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_800C4B7C(rdram, ctx);
        goto after_2;
    // 0x80800474: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_2:
    // 0x80800478: jal         0x800C4B70
    // 0x8080047C: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    func_800C4B70(rdram, ctx);
        goto after_3;
    // 0x8080047C: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_3:
    // 0x80800480: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800484: jal         0x800DC178
    // 0x80800488: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800488: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_4:
    // 0x8080048C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800490: jal         0x800C4B64
    // 0x80800494: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800C4B64(rdram, ctx);
        goto after_5;
    // 0x80800494: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_5:
    // 0x80800498: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080049C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808004A0: jal         0x80089D18
    // 0x808004A4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808004A4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_6:
L_808004A8:
    // 0x808004A8: lw          $t1, 0x4($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X4);
    // 0x808004AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808004B0: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x808004B4: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x808004B8: bnel        $at, $zero, L_80800454
    if (ctx->r1 != 0) {
        // 0x808004BC: lw          $t0, 0x0($s5)
        ctx->r8 = MEM_W(ctx->r21, 0X0);
            goto L_80800454;
    }
    goto skip_0;
    // 0x808004BC: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    skip_0:
L_808004C0:
    // 0x808004C0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x808004C4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808004C8: beql        $t2, $zero, L_808004F8
    if (ctx->r10 == 0) {
        // 0x808004CC: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_808004F8;
    }
    goto skip_1;
    // 0x808004CC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_1:
    // 0x808004D0: lhu         $t3, 0x6E($s4)
    ctx->r11 = MEM_HU(ctx->r20, 0X6E);
    // 0x808004D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808004D8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808004DC: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x808004E0: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x808004E4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004E8: jal         0x800DC178
    // 0x808004EC: sh          $t5, 0x6E($s4)
    MEM_H(0X6E, ctx->r20) = ctx->r13;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x808004EC: sh          $t5, 0x6E($s4)
    MEM_H(0X6E, ctx->r20) = ctx->r13;
    after_7:
    // 0x808004F0: swc1        $f0, 0x2C($s4)
    MEM_W(0X2C, ctx->r20) = ctx->f0.u32l;
    // 0x808004F4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_808004F8:
    // 0x808004F8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808004FC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800500: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800504: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800508: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8080050C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800510: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800514: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80800518: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8080051C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80800520: jr          $ra
    // 0x80800524: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800524: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
