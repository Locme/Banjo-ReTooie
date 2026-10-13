#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void scinfobar_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B0: jr          $ra
    // 0x808005B4: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    return;
    // 0x808005B4: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
;}
RECOMP_FUNC void chdinoboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1060, 0X2B40) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2B40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1060, 0X2B40));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2B40
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1060, 0X2B40));
;}
RECOMP_FUNC void func_800C696C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C696C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C6970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C6974: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800C6978: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800C697C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800C6980: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800C6984: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800C6988: jal         0x800EE7F8
    // 0x800C698C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800C698C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x800C6990: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C6994: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C6998: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800C699C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800C69A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C69A4: jal         0x800EE7F8
    // 0x800C69A8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800C69A8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800C69AC: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C69B0: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C69B4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800C69B8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800C69BC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C69C0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x800C69C4: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800C69C8: jal         0x800C6A7C
    // 0x800C69CC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    func_800C6A7C(rdram, ctx);
        goto after_2;
    // 0x800C69CC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x800C69D0: beq         $v0, $zero, L_800C69E8
    if (ctx->r2 == 0) {
        // 0x800C69D4: lwc1        $f4, 0x2C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_800C69E8;
    }
    // 0x800C69D4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C69D8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800C69DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C69E0: b           L_800C69EC
    // 0x800C69E4: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
        goto L_800C69EC;
    // 0x800C69E4: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
L_800C69E8:
    // 0x800C69E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C69EC:
    // 0x800C69EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C69F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800C69F4: jr          $ra
    // 0x800C69F8: nop

    return;
    // 0x800C69F8: nop

;}
RECOMP_FUNC void babounce_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080067C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800680: jal         0x80800504
    // 0x80800684: nop

    babounce_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800684: nop

    after_0:
    // 0x80800688: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080068C: bne         $v0, $at, L_8080069C
    if (ctx->r2 != ctx->r1) {
        // 0x80800690: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080069C;
    }
    // 0x80800690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800694: b           L_808006A0
    // 0x80800698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808006A0;
    // 0x80800698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080069C:
    // 0x8080069C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006A0:
    // 0x808006A0: jr          $ra
    // 0x808006A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808006A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void bsstonehead_entrypoint_43(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015F8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808015FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(376, 0X16D0) << 16);
    // 0x80801600: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801604: jr          $ra
    // 0x80801608: lw          $v0, 0x16D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X16D0));
    return;
    // 0x80801608: lw          $v0, 0x16D0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X16D0));
    // 0x8080160C: nop

;}
RECOMP_FUNC void func_800D0778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D077C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D0780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0784: bne         $a1, $at, L_800D07BC
    if (ctx->r5 != ctx->r1) {
        // 0x800D0788: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800D07BC;
    }
    // 0x800D0788: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D078C: jal         0x800CFC5C
    // 0x800D0790: nop

    func_800CFC5C(rdram, ctx);
        goto after_0;
    // 0x800D0790: nop

    after_0:
    // 0x800D0794: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D0798: beq         $v0, $at, L_800D07BC
    if (ctx->r2 == ctx->r1) {
        // 0x800D079C: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800D07BC;
    }
    // 0x800D079C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D07A0: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800D07A4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800D07A8: addiu       $t7, $t7, -0x4E80
    ctx->r15 = ADD32(ctx->r15, -0X4E80);
    // 0x800D07AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D07B0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800D07B4: jal         0x800EE7F8
    // 0x800D07B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800D07B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
L_800D07BC:
    // 0x800D07BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D07C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D07C4: jr          $ra
    // 0x800D07C8: nop

    return;
    // 0x800D07C8: nop

;}
RECOMP_FUNC void func_80801D40_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801D44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D48: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801D4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801D50: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80801D54: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80801D58: jal         0x80100094
    // 0x80801D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801D60: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80801D64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801D68: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80801D6C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80801D70: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80801D74: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801D78: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80801D7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801D80: addu        $s0, $v0, $t6
    ctx->r16 = ADD32(ctx->r2, ctx->r14);
    // 0x80801D84: jal         0x80801DF0
    // 0x80801D88: addiu       $s0, $s0, 0x568
    ctx->r16 = ADD32(ctx->r16, 0X568);
    func_80801DF0_chfpsgame(rdram, ctx);
        goto after_1;
    // 0x80801D88: addiu       $s0, $s0, 0x568
    ctx->r16 = ADD32(ctx->r16, 0X568);
    after_1:
    // 0x80801D8C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80801D90: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801D94: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80801D98: bnel        $at, $zero, L_80801DB0
    if (ctx->r1 != 0) {
        // 0x80801D9C: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_80801DB0;
    }
    goto skip_0;
    // 0x80801D9C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x80801DA0: jal         0x80801F34
    // 0x80801DA4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80801F34_chfpsgame(rdram, ctx);
        goto after_2;
    // 0x80801DA4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x80801DA8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80801DAC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
L_80801DB0:
    // 0x80801DB0: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80801DB4: addu        $v1, $s0, $t7
    ctx->r3 = ADD32(ctx->r16, ctx->r15);
    // 0x80801DB8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80801DBC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80801DC0: jal         0x8001211C
    // 0x80801DC4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8001211C(rdram, ctx);
        goto after_3;
    // 0x80801DC4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x80801DC8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80801DCC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x80801DD0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80801DD4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80801DD8: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80801DDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801DE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801DE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801DE8: jr          $ra
    // 0x80801DEC: nop

    return;
    // 0x80801DEC: nop

;}
RECOMP_FUNC void func_80090128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009012C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090130: jal         0x800F54E4
    // 0x80090134: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090134: nop

    after_0:
    // 0x80090138: jal         0x800F6438
    // 0x8009013C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x8009013C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80090140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090148: jr          $ra
    // 0x8009014C: nop

    return;
    // 0x8009014C: nop

;}
RECOMP_FUNC void func_80800360_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800360: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800364: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800368: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080036C: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800370: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800374: addiu       $at, $zero, 0x368
    ctx->r1 = ADD32(0, 0X368);
    // 0x80800378: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x8080037C: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800380: bne         $t8, $at, L_80800394
    if (ctx->r24 != ctx->r1) {
        // 0x80800384: addiu       $a0, $sp, 0x30
        ctx->r4 = ADD32(ctx->r29, 0X30);
            goto L_80800394;
    }
    // 0x80800384: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800388: addiu       $t9, $zero, 0xCB
    ctx->r25 = ADD32(0, 0XCB);
    // 0x8080038C: b           L_8080039C
    // 0x80800390: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
        goto L_8080039C;
    // 0x80800390: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_80800394:
    // 0x80800394: addiu       $t0, $zero, 0xCC
    ctx->r8 = ADD32(0, 0XCC);
    // 0x80800398: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
L_8080039C:
    // 0x8080039C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808003A0: jal         0x800EE7F8
    // 0x808003A4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808003A4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808003A8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808003AC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808003B0: jal         0x800EF1B8
    // 0x808003B4: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808003B4: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    after_1:
    // 0x808003B8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1052, 0X9CC) << 16);
    // 0x808003BC: addiu       $a2, $a2, 0x9CC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1052, 0X9CC));
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C4: jal         0x80089D18
    // 0x808003C8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808003C8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x808003CC: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1052, 0X7D0) << 16);
    // 0x808003D0: addiu       $t1, $t1, 0x7D0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1052, 0X7D0));
    // 0x808003D4: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808003D8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808003DC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808003E0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003E4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808003E8: jal         0x800BBCB8
    // 0x808003EC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x808003EC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_3:
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808003F8: jal         0x80086670
    // 0x808003FC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808003FC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_4:
    // 0x80800400: jal         0x800DA544
    // 0x80800404: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800404: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x80800408: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080040C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800410: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800414: jr          $ra
    // 0x80800418: nop

    return;
    // 0x80800418: nop

;}
RECOMP_FUNC void bafly_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A18: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800A1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A24: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800A28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A2C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800A30: jal         0x8009C128
    // 0x80800A34: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800A34: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80800A38: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x80800A3C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800A40: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800A44: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800A48: jal         0x800E1610
    // 0x80800A4C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    func_800E1610(rdram, ctx);
        goto after_1;
    // 0x80800A4C: addiu       $a3, $sp, 0x40
    ctx->r7 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A54: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800A58: jal         0x8008CDB8
    // 0x80800A5C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    baanim_playForDuration_once(rdram, ctx);
        goto after_2;
    // 0x80800A5C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    after_2:
    // 0x80800A60: jal         0x8009DA40
    // 0x80800A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009DA40(rdram, ctx);
        goto after_3;
    // 0x80800A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A6C: jal         0x800A32C4
    // 0x80800A70: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800A32C4(rdram, ctx);
        goto after_4;
    // 0x80800A70: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_4:
    // 0x80800A74: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800A78: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800A7C: jal         0x800F1E6C
    // 0x80800A80: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    func_800F1E6C(rdram, ctx);
        goto after_5;
    // 0x80800A80: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    after_5:
    // 0x80800A84: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800A88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A8C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800A90: jal         0x800136E4
    // 0x80800A94: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_6;
    // 0x80800A94: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_6:
    // 0x80800A98: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800A9C: jal         0x8009C914
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_7;
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800AA4: jal         0x8009C974
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_8;
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800AAC: lui         $a1, 0x44A2
    ctx->r5 = S32(0X44A2 << 16);
    // 0x80800AB0: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800AB4: jal         0x8009B9B0
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_9;
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC0: jal         0x8009B9C0
    // 0x80800AC4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_10;
    // 0x80800AC4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_10:
    // 0x80800AC8: jal         0x8009BB00
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800AD0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800AD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AD8: jal         0x8009BA68
    // 0x80800ADC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_12;
    // 0x80800ADC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_12:
    // 0x80800AE0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800AE4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800AF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800AF4: jal         0x8009FFD8
    // 0x80800AF8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_13;
    // 0x80800AF8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_13:
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B00: jal         0x8009BA58
    // 0x80800B04: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_14;
    // 0x80800B04: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_14:
    // 0x80800B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B0C: jal         0x8009BCB4
    // 0x80800B10: lui         $a1, 0xC4E1
    ctx->r5 = S32(0XC4E1 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_15;
    // 0x80800B10: lui         $a1, 0xC4E1
    ctx->r5 = S32(0XC4E1 << 16);
    after_15:
    // 0x80800B14: jal         0x8008E944
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_16;
    // 0x80800B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B20: jal         0x800A4DA4
    // 0x80800B24: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800A4DA4(rdram, ctx);
        goto after_17;
    // 0x80800B24: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
    // 0x80800B28: jal         0x800A4CA8
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_18;
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800B30: lui         $a2, 0x461C
    ctx->r6 = S32(0X461C << 16);
    // 0x80800B34: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x80800B38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B3C: lui         $a1, 0x4140
    ctx->r5 = S32(0X4140 << 16);
    // 0x80800B40: jal         0x800892E0
    // 0x80800B44: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    _ncbafly_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x80800B44: lui         $a3, 0x4448
    ctx->r7 = S32(0X4448 << 16);
    after_19:
    // 0x80800B48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B4C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B50: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800B54: jr          $ra
    // 0x80800B58: nop

    return;
    // 0x80800B58: nop

;}
RECOMP_FUNC void func_80112D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112D2C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80112D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80112D34: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80112D38: jal         0x801107F0
    // 0x80112D3C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_801107F0(rdram, ctx);
        goto after_0;
    // 0x80112D3C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80112D40: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80112D44: jal         0x801127A8
    // 0x80112D48: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_801127A8(rdram, ctx);
        goto after_1;
    // 0x80112D48: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80112D4C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80112D50: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80112D54: jal         0x800EFB24
    // 0x80112D58: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x80112D58: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x80112D5C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80112D60: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80112D64: lw          $a1, 0x60($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X60);
    // 0x80112D68: jal         0x800F1EA4
    // 0x80112D6C: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    func_800F1EA4(rdram, ctx);
        goto after_3;
    // 0x80112D6C: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_3:
    // 0x80112D70: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80112D74: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80112D78: lw          $t8, 0x60($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X60);
    // 0x80112D7C: swc1        $f4, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f4.u32l;
    // 0x80112D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80112D84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80112D88: jr          $ra
    // 0x80112D8C: nop

    return;
    // 0x80112D8C: nop

;}
RECOMP_FUNC void _plcamera_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878F8: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x800878F8);
    return;
    // 0x800878FC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_8002BCBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BCBC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002BCC0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8002BCC4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8002BCC8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BCCC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002BCD0: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8002BCD4: sra         $a1, $a1, 3
    ctx->r5 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8002BCD8: bne         $a1, $zero, L_8002BCE8
    if (ctx->r5 != 0) {
        // 0x8002BCDC: nop
    
            goto L_8002BCE8;
    }
    // 0x8002BCDC: nop

    // 0x8002BCE0: b           L_8002BD38
    // 0x8002BCE4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8002BD38;
    // 0x8002BCE4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8002BCE8:
    // 0x8002BCE8: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BCEC: mflo        $t6
    ctx->r14 = lo;
    // 0x8002BCF0: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8002BCF4: nop

    // 0x8002BCF8: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8002BCFC: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8002BD00: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8002BD04: multu       $a2, $a1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002BD08: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8002BD0C: mflo        $t0
    ctx->r8 = lo;
    // 0x8002BD10: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8002BD14: sw          $t1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r9;
    // 0x8002BD18: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x8002BD1C: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x8002BD20: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8002BD24: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8002BD28: b           L_8002BD38
    // 0x8002BD2C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8002BD38;
    // 0x8002BD2C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8002BD30: b           L_8002BD38
    // 0x8002BD34: nop

        goto L_8002BD38;
    // 0x8002BD34: nop

L_8002BD38:
    // 0x8002BD38: jr          $ra
    // 0x8002BD3C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8002BD3C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8080082C_chboggyboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080082C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800834: jal         0x80100094
    // 0x80800838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080083C: addiu       $a0, $zero, 0x3A1
    ctx->r4 = ADD32(0, 0X3A1);
    // 0x80800840: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80800844: jal         0x80088480
    // 0x80800848: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800848: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080084C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800850: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80800854: jal         0x800EE940
    // 0x80800858: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    func_800EE940(rdram, ctx);
        goto after_2;
    // 0x80800858: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    after_2:
    // 0x8080085C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800860: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800864: jr          $ra
    // 0x80800868: nop

    return;
    // 0x80800868: nop

;}
RECOMP_FUNC void func_80015E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015E80: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80015E84: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80015E88: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80015E8C: addiu       $t7, $t7, -0x6620
    ctx->r15 = ADD32(ctx->r15, -0X6620);
    // 0x80015E90: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80015E94: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80015E98: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80015E9C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80015EA0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80015EA4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80015EA8: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80015EAC: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
    // 0x80015EB0: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80015EB4: sw          $t1, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r9;
    // 0x80015EB8: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x80015EBC: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x80015EC0: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x80015EC4: jr          $ra
    // 0x80015EC8: sw          $t3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r11;
    return;
    // 0x80015EC8: sw          $t3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r11;
;}
RECOMP_FUNC void func_800DC42C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC42C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC434: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DC438: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800DC43C: jal         0x80020C08
    // 0x800DC440: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80020C08(rdram, ctx);
        goto after_0;
    // 0x800DC440: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x800DC444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC44C: jr          $ra
    // 0x800DC450: nop

    return;
    // 0x800DC450: nop

;}
RECOMP_FUNC void func_800C95D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C95D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C95D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C95DC: jal         0x800C91C8
    // 0x800C95E0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C91C8(rdram, ctx);
        goto after_0;
    // 0x800C95E0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x800C95E4: beq         $v0, $zero, L_800C95FC
    if (ctx->r2 == 0) {
        // 0x800C95E8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800C95FC;
    }
    // 0x800C95E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C95EC: jal         0x800881B8
    // 0x800C95F0: nop

    _gctransitionDll_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x800C95F0: nop

    after_1:
    // 0x800C95F4: b           L_800C9604
    // 0x800C95F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C9604;
    // 0x800C95F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C95FC:
    // 0x800C95FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C9600: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9604:
    // 0x800C9604: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9608: jr          $ra
    // 0x800C960C: nop

    return;
    // 0x800C960C: nop

;}
RECOMP_FUNC void func_800EF11C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF11C: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x800EF120: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF124: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF128: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800EF12C: nop

    // 0x800EF130: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EF134: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800EF138: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EF13C: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800EF140: lh          $t7, 0x2($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X2);
    // 0x800EF144: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800EF148: nop

    // 0x800EF14C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800EF150: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800EF154: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x800EF158: lh          $t8, 0x4($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4);
    // 0x800EF15C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800EF160: nop

    // 0x800EF164: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800EF168: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800EF16C: jr          $ra
    // 0x800EF170: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x800EF170: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
;}
RECOMP_FUNC void _subaddieitem_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089FE0: syscall     821
    recomp_syscall_handler(rdram, ctx, 0x80089FE0);
    return;
    // 0x80089FE4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bacough_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084628: syscall     117
    recomp_syscall_handler(rdram, ctx, 0x80084628);
    return;
    // 0x8008462C: xori        $t0, $zero, 0xC
    ctx->r8 = 0 ^ 0XC;
;}
RECOMP_FUNC void func_80800960_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800968: jal         0x800A587C
    // 0x8080096C: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x8080096C: nop

    after_0:
    // 0x80800970: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800974: bnel        $v0, $at, L_80800990
    if (ctx->r2 != ctx->r1) {
        // 0x80800978: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800990;
    }
    goto skip_0;
    // 0x80800978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8080097C: jal         0x800A586C
    // 0x80800980: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x80800980: nop

    after_1:
    // 0x80800984: b           L_80800990
    // 0x80800988: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
        goto L_80800990;
    // 0x80800988: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8080098C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800990:
    // 0x80800990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800998: jr          $ra
    // 0x8080099C: nop

    return;
    // 0x8080099C: nop

;}
RECOMP_FUNC void changlerboss_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1332, 0X2EFC) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x2EFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1332, 0X2EFC));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x2EFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1332, 0X2EFC));
;}
RECOMP_FUNC void func_8080003C_gcdialogcamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080003C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800040: bnel        $a1, $at, L_80800054
    if (ctx->r5 != ctx->r1) {
        // 0x80800044: lhu         $t6, 0x12($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0X12);
            goto L_80800054;
    }
    goto skip_0;
    // 0x80800044: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
    skip_0:
    // 0x80800048: jr          $ra
    // 0x8080004C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8080004C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800050: lhu         $t6, 0x12($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X12);
L_80800054:
    // 0x80800054: srl         $t7, $t6, 1
    ctx->r15 = S32(U32(ctx->r14) >> 1);
    // 0x80800058: xor         $v1, $a1, $t7
    ctx->r3 = ctx->r5 ^ ctx->r15;
    // 0x8080005C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80800060: jr          $ra
    // 0x80800064: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800064: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _chswappy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800872D0: syscall     547
    recomp_syscall_handler(rdram, ctx, 0x800872D0);
    return;
    // 0x800872D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_801068A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801068A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801068AC: lw          $a1, 0x6EE0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6EE0);
    // 0x801068B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801068B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801068B8: bne         $a1, $zero, L_801068C8
    if (ctx->r5 != 0) {
        // 0x801068BC: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_801068C8;
    }
    // 0x801068BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801068C0: b           L_80106910
    // 0x801068C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80106910;
    // 0x801068C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801068C8:
    // 0x801068C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801068CC: jal         0x800B2928
    // 0x801068D0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    vector_size(rdram, ctx);
        goto after_0;
    // 0x801068D0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801068D4: blez        $v0, L_8010690C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801068D8: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8010690C;
    }
    // 0x801068D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801068DC: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x801068E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801068E4: bltz        $a1, L_801068F4
    if (SIGNED(ctx->r5) < 0) {
        // 0x801068E8: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_801068F4;
    }
    // 0x801068E8: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801068EC: bne         $at, $zero, L_801068FC
    if (ctx->r1 != 0) {
        // 0x801068F0: nop
    
            goto L_801068FC;
    }
    // 0x801068F0: nop

L_801068F4:
    // 0x801068F4: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x801068F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_801068FC:
    // 0x801068FC: jal         0x800B28CC
    // 0x80106900: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    vector_at(rdram, ctx);
        goto after_1;
    // 0x80106900: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    after_1:
    // 0x80106904: b           L_80106914
    // 0x80106908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80106914;
    // 0x80106908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010690C:
    // 0x8010690C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80106910:
    // 0x80106910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106914:
    // 0x80106914: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106918: jr          $ra
    // 0x8010691C: nop

    return;
    // 0x8010691C: nop

;}
RECOMP_FUNC void _chbilldrillboulder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F80: syscall     485
    recomp_syscall_handler(rdram, ctx, 0x80086F80);
    return;
    // 0x80086F84: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsbanswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800834: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800838: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(53, 0XA50) << 16);
    // 0x8080083C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800840: jr          $ra
    // 0x80800844: lw          $v0, 0xA50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(53, 0XA50));
    return;
    // 0x80800844: lw          $v0, 0xA50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(53, 0XA50));
;}
RECOMP_FUNC void func_800A0D94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0D94: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0D98: jr          $ra
    // 0x800A0D9C: sb          $a1, 0x16($t6)
    MEM_B(0X16, ctx->r14) = ctx->r5;
    return;
    // 0x800A0D9C: sb          $a1, 0x16($t6)
    MEM_B(0X16, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800BF8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF8B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BF8B4: jr          $ra
    // 0x800BF8B8: lbu         $v0, -0x79D9($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X79D9);
    return;
    // 0x800BF8B8: lbu         $v0, -0x79D9($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X79D9);
;}
RECOMP_FUNC void gcfrontend_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080039C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003A4: jal         0x800D3CF8
    // 0x808003A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D3CF8(rdram, ctx);
        goto after_0;
    // 0x808003A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808003AC: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    // 0x808003B0: jal         0x808002DC
    // 0x808003B4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_808002DC_gcfrontend(rdram, ctx);
        goto after_1;
    // 0x808003B4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x808003B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003C0: jr          $ra
    // 0x808003C4: nop

    return;
    // 0x808003C4: nop

;}
RECOMP_FUNC void bswasher_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808015DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(443, 0X1EA0) << 16);
    // 0x808015E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808015E4: jr          $ra
    // 0x808015E8: lw          $v0, 0x1EA0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1EA0));
    return;
    // 0x808015E8: lw          $v0, 0x1EA0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(443, 0X1EA0));
;}
RECOMP_FUNC void suexpression_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800188: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080018C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800190: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800194: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80800198: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x8080019C: jal         0x80089B38
    // 0x808001A0: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    _suexpressmorph_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808001A0: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    after_0:
    // 0x808001A4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808001A8: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x808001AC: jal         0x80089760
    // 0x808001B0: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    _suexpressjoint_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808001B0: lh          $a0, 0x1A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1A);
    after_1:
    // 0x808001B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001B8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808001BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x808001C4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x808001C8: lui         $v1, 0x7FFF
    ctx->r3 = S32(0X7FFF << 16);
    // 0x808001CC: ori         $v1, $v1, 0xFFFC
    ctx->r3 = ctx->r3 | 0XFFFC;
    // 0x808001D0: addiu       $t0, $t9, 0x3
    ctx->r8 = ADD32(ctx->r25, 0X3);
    // 0x808001D4: and         $t1, $t0, $v1
    ctx->r9 = ctx->r8 & ctx->r3;
    // 0x808001D8: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x808001DC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x808001E0: addiu       $t3, $t2, 0x3
    ctx->r11 = ADD32(ctx->r10, 0X3);
    // 0x808001E4: and         $t4, $t3, $v1
    ctx->r12 = ctx->r11 & ctx->r3;
    // 0x808001E8: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x808001EC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x808001F0: addiu       $t6, $t5, 0x3
    ctx->r14 = ADD32(ctx->r13, 0X3);
    // 0x808001F4: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x808001F8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x808001FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800204: jr          $ra
    // 0x80800208: nop

    return;
    // 0x80800208: nop

;}
RECOMP_FUNC void func_808014F0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014F0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808014F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808014F8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808014FC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80801500: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801504: jal         0x8008A0D8
    // 0x80801508: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    _subaddieskeleton_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801508: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8080150C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80801510: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80801514: jal         0x800EFB24
    // 0x80801518: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x80801518: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_1:
    // 0x8080151C: jal         0x800EEF94
    // 0x80801520: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EEF94(rdram, ctx);
        goto after_2;
    // 0x80801520: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x80801524: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801528: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8080152C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80801530: nop

    // 0x80801534: bc1tl       L_80801590
    if (c1cs) {
        // 0x80801538: lwc1        $f16, 0x28($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80801590;
    }
    goto skip_0;
    // 0x80801538: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x8080153C: jal         0x800D8FF8
    // 0x80801540: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x80801540: nop

    after_3:
    // 0x80801544: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7C98) << 16);
    // 0x80801548: lwc1        $f6, 0x7C98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7C98));
    // 0x8080154C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80801550: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801554: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    // 0x80801558: lui         $a3, 0xC57A
    ctx->r7 = S32(0XC57A << 16);
    // 0x8080155C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80801560: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80801564: jal         0x800FF060
    // 0x80801568: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    func_800FF060(rdram, ctx);
        goto after_4;
    // 0x80801568: addiu       $a1, $a1, 0x24
    ctx->r5 = ADD32(ctx->r5, 0X24);
    after_4:
    // 0x8080156C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80801570: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80801574: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80801578: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8080157C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80801580: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801584: jal         0x800EF174
    // 0x80801588: nop

    func_800EF174(rdram, ctx);
        goto after_5;
    // 0x80801588: nop

    after_5:
    // 0x8080158C: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
L_80801590:
    // 0x80801590: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80801594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801598: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8080159C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x808015A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7C9C) << 16);
    // 0x808015A4: bc1t        L_808015C8
    if (c1cs) {
        // 0x808015A8: nop
    
            goto L_808015C8;
    }
    // 0x808015A8: nop

    // 0x808015AC: lwc1        $f4, 0x24($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X24);
    // 0x808015B0: lwc1        $f6, 0x7C9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7C9C));
    // 0x808015B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808015B8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808015BC: nop

    // 0x808015C0: bc1f        L_808015D0
    if (!c1cs) {
        // 0x808015C4: nop
    
            goto L_808015D0;
    }
    // 0x808015C4: nop

L_808015C8:
    // 0x808015C8: b           L_808015D0
    // 0x808015CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_808015D0;
    // 0x808015CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808015D0:
    // 0x808015D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808015D4: jr          $ra
    // 0x808015D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808015D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80020EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020EDC: jr          $ra
    // 0x80020EE0: nop

    return;
    // 0x80020EE0: nop

;}
RECOMP_FUNC void func_808013EC_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013F4: jal         0x808009B0
    // 0x808013F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808009B0_bssub(rdram, ctx);
        goto after_0;
    // 0x808013F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808013FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801400: jal         0x800845D8
    // 0x80801404: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801404: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80801408: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080140C: addiu       $a1, $zero, 0x12E
    ctx->r5 = ADD32(0, 0X12E);
    // 0x80801410: jal         0x800845E0
    // 0x80801414: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80801414: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    after_2:
    // 0x80801418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080141C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801420: jr          $ra
    // 0x80801424: nop

    return;
    // 0x80801424: nop

;}
RECOMP_FUNC void func_800F7F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7F50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7F54: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800F7F58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800F7F5C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F7F60: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800F7F64: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800F7F68: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7F6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F7F70: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F7F74: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x800F7F78: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7F7C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800F7F80: jal         0x80098730
    // 0x800F7F84: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_80098730(rdram, ctx);
        goto after_0;
    // 0x800F7F84: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x800F7F88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7F8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7F90: jr          $ra
    // 0x800F7F94: nop

    return;
    // 0x800F7F94: nop

;}
RECOMP_FUNC void chmonsterinterior_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1320, 0X1F10) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x1F10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1320, 0X1F10));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x1F10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1320, 0X1F10));
;}
RECOMP_FUNC void _sumumbofx_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800898C0: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x800898C0);
    return;
    // 0x800898C4: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void _bsmumcast_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083898: syscall     77
    recomp_syscall_handler(rdram, ctx, 0x80083898);
    return;
    // 0x8008389C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808014C8_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808014CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808014D0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808014D4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808014D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808014DC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808014E0: jal         0x8009D3A8
    // 0x808014E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x808014E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808014E8: lui         $a1, 0x3E18
    ctx->r5 = S32(0X3E18 << 16);
    // 0x808014EC: ori         $a1, $a1, 0x44D0
    ctx->r5 = ctx->r5 | 0X44D0;
    // 0x808014F0: jal         0x8008CB10
    // 0x808014F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x808014F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808014F8: bne         $v0, $zero, L_80801510
    if (ctx->r2 != 0) {
        // 0x808014FC: lui         $a1, 0x3E8C
        ctx->r5 = S32(0X3E8C << 16);
            goto L_80801510;
    }
    // 0x808014FC: lui         $a1, 0x3E8C
    ctx->r5 = S32(0X3E8C << 16);
    // 0x80801500: ori         $a1, $a1, 0x2268
    ctx->r5 = ctx->r5 | 0X2268;
    // 0x80801504: jal         0x8008CB10
    // 0x80801508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x80801508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080150C: beq         $v0, $zero, L_8080153C
    if (ctx->r2 == 0) {
        // 0x80801510: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_8080153C;
    }
L_80801510:
    // 0x80801510: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80801514: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x80801518: addiu       $t6, $zero, 0xBB8
    ctx->r14 = ADD32(0, 0XBB8);
    // 0x8080151C: addiu       $t7, $zero, 0xFA0
    ctx->r15 = ADD32(0, 0XFA0);
    // 0x80801520: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801524: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801528: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8080152C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801534: jal         0x8009DEC0
    // 0x80801538: addiu       $a1, $zero, 0x4A1
    ctx->r5 = ADD32(0, 0X4A1);
    func_8009DEC0(rdram, ctx);
        goto after_3;
    // 0x80801538: addiu       $a1, $zero, 0x4A1
    ctx->r5 = ADD32(0, 0X4A1);
    after_3:
L_8080153C:
    // 0x8080153C: jal         0x8008E148
    // 0x80801540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E148(rdram, ctx);
        goto after_4;
    // 0x80801540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801544: beq         $v0, $zero, L_80801558
    if (ctx->r2 == 0) {
        // 0x80801548: nop
    
            goto L_80801558;
    }
    // 0x80801548: nop

    // 0x8080154C: jal         0x800848B0
    // 0x80801550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_25(rdram, ctx);
        goto after_5;
    // 0x80801550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801554: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80801558:
    // 0x80801558: jal         0x8008DD04
    // 0x8080155C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DD04(rdram, ctx);
        goto after_6;
    // 0x8080155C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801560: beq         $v0, $zero, L_8080156C
    if (ctx->r2 == 0) {
        // 0x80801564: nop
    
            goto L_8080156C;
    }
    // 0x80801564: nop

    // 0x80801568: addiu       $s1, $zero, 0x36
    ctx->r17 = ADD32(0, 0X36);
L_8080156C:
    // 0x8080156C: jal         0x8009EF10
    // 0x80801570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_7;
    // 0x80801570: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801574: beq         $v0, $zero, L_80801580
    if (ctx->r2 == 0) {
        // 0x80801578: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801580;
    }
    // 0x80801578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080157C: addiu       $s1, $zero, 0x33
    ctx->r17 = ADD32(0, 0X33);
L_80801580:
    // 0x80801580: jal         0x80800064
    // 0x80801584: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800064_bswasher(rdram, ctx);
        goto after_8;
    // 0x80801584: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x80801588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080158C: jal         0x800A02DC
    // 0x80801590: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A02DC(rdram, ctx);
        goto after_9;
    // 0x80801590: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80801594: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080159C: jal         0x80091A58
    // 0x808015A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_10;
    // 0x808015A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808015A4: beq         $v0, $zero, L_808015B0
    if (ctx->r2 == 0) {
        // 0x808015A8: nop
    
            goto L_808015B0;
    }
    // 0x808015A8: nop

    // 0x808015AC: addiu       $s1, $zero, 0x38
    ctx->r17 = ADD32(0, 0X38);
L_808015B0:
    // 0x808015B0: jal         0x80800300
    // 0x808015B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800300_bswasher(rdram, ctx);
        goto after_11;
    // 0x808015B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808015B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015BC: jal         0x8009E5C8
    // 0x808015C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_12;
    // 0x808015C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_12:
    // 0x808015C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808015C8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808015CC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808015D0: jr          $ra
    // 0x808015D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808015D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bamovegoto_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084DD0: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084DD0);
    return;
    // 0x80084DD4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void sumultiscore_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080054C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800550: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800554: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80800558: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8080055C: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x80800560: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80800564: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80800568: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8080056C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800570: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800574: jal         0x80088368
    // 0x80800578: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800578: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080057C: sw          $v0, 0x518($s7)
    MEM_W(0X518, ctx->r23) = ctx->r2;
    // 0x80800580: blez        $v0, L_808006C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800584: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_808006C4;
    }
    // 0x80800584: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800588: addiu       $s0, $s7, 0x28
    ctx->r16 = ADD32(ctx->r23, 0X28);
    // 0x8080058C: addiu       $s6, $sp, 0x48
    ctx->r22 = ADD32(ctx->r29, 0X48);
    // 0x80800590: addiu       $s5, $sp, 0x4C
    ctx->r21 = ADD32(ctx->r29, 0X4C);
    // 0x80800594: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
    // 0x80800598: addiu       $s3, $sp, 0x54
    ctx->r19 = ADD32(ctx->r29, 0X54);
    // 0x8080059C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_808005A0:
    // 0x808005A0: jal         0x800A940C
    // 0x808005A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800A940C(rdram, ctx);
        goto after_1;
    // 0x808005A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x808005A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808005B0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x808005B4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x808005B8: jal         0x800A8A04
    // 0x808005BC: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    func_800A8A04(rdram, ctx);
        goto after_2;
    // 0x808005BC: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_2:
    // 0x808005C0: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x808005C4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808005C8: addiu       $s0, $s0, 0x13C
    ctx->r16 = ADD32(ctx->r16, 0X13C);
    // 0x808005CC: addiu       $t7, $t6, 0x1C
    ctx->r15 = ADD32(ctx->r14, 0X1C);
    // 0x808005D0: sh          $t7, -0x13C($s0)
    MEM_H(-0X13C, ctx->r16) = ctx->r15;
    // 0x808005D4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x808005D8: addiu       $t9, $t8, 0xE
    ctx->r25 = ADD32(ctx->r24, 0XE);
    // 0x808005DC: sh          $t9, -0x13A($s0)
    MEM_H(-0X13A, ctx->r16) = ctx->r25;
    // 0x808005E0: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x808005E4: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x808005E8: bgez        $t0, L_808005F8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808005EC: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_808005F8;
    }
    // 0x808005EC: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x808005F0: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x808005F4: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_808005F8:
    // 0x808005F8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x808005FC: sh          $t3, -0x138($s0)
    MEM_H(-0X138, ctx->r16) = ctx->r11;
    // 0x80800600: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80800604: addiu       $t5, $t4, 0xE
    ctx->r13 = ADD32(ctx->r12, 0XE);
    // 0x80800608: sh          $t5, -0x136($s0)
    MEM_H(-0X136, ctx->r16) = ctx->r13;
    // 0x8080060C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80800610: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80800614: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800618: addiu       $t9, $t8, -0x1C
    ctx->r25 = ADD32(ctx->r24, -0X1C);
    // 0x8080061C: sh          $t9, -0x134($s0)
    MEM_H(-0X134, ctx->r16) = ctx->r25;
    // 0x80800620: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80800624: addiu       $t1, $t0, 0xE
    ctx->r9 = ADD32(ctx->r8, 0XE);
    // 0x80800628: sh          $t1, -0x132($s0)
    MEM_H(-0X132, ctx->r16) = ctx->r9;
    // 0x8080062C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80800630: addiu       $t3, $t2, 0x1C
    ctx->r11 = ADD32(ctx->r10, 0X1C);
    // 0x80800634: sh          $t3, -0x130($s0)
    MEM_H(-0X130, ctx->r16) = ctx->r11;
    // 0x80800638: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8080063C: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80800640: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80800644: addiu       $t7, $t6, -0xE
    ctx->r15 = ADD32(ctx->r14, -0XE);
    // 0x80800648: sh          $t7, -0x12E($s0)
    MEM_H(-0X12E, ctx->r16) = ctx->r15;
    // 0x8080064C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80800650: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80800654: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800658: addiu       $t1, $t0, -0x1C
    ctx->r9 = ADD32(ctx->r8, -0X1C);
    // 0x8080065C: sh          $t1, -0x12C($s0)
    MEM_H(-0X12C, ctx->r16) = ctx->r9;
    // 0x80800660: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80800664: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80800668: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8080066C: addiu       $t5, $t4, -0xE
    ctx->r13 = ADD32(ctx->r12, -0XE);
    // 0x80800670: sh          $t5, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r13;
    // 0x80800674: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80800678: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x8080067C: bgez        $t6, L_8080068C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800680: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8080068C;
    }
    // 0x80800680: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80800684: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x80800688: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8080068C:
    // 0x8080068C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80800690: sh          $t9, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r25;
    // 0x80800694: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80800698: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8080069C: bgez        $t0, L_808006AC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808006A0: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_808006AC;
    }
    // 0x808006A0: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x808006A4: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x808006A8: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_808006AC:
    // 0x808006AC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x808006B0: sh          $t3, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r11;
    // 0x808006B4: lw          $t4, 0x518($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X518);
    // 0x808006B8: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808006BC: bnel        $at, $zero, L_808005A0
    if (ctx->r1 != 0) {
        // 0x808006C0: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_808005A0;
    }
    goto skip_0;
    // 0x808006C0: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    skip_0:
L_808006C4:
    // 0x808006C4: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
    // 0x808006C8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808006CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808006D0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808006D4: jal         0x80800708
    // 0x808006D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    sumultiscore_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808006D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x808006DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x808006E0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808006E4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808006E8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808006EC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808006F0: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x808006F4: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x808006F8: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x808006FC: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x80800700: jr          $ra
    // 0x80800704: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800704: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _gcgoto_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A98: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087A98);
    return;
    // 0x80087A9C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80801130_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801130: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801134: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801138: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080113C: jal         0x80082838
    // 0x80801140: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801140: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801144: jal         0x80082FE0
    // 0x80801148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080114C: jal         0x80084800
    // 0x80801150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badrone_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801154: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801158: bne         $v0, $at, L_80801178
    if (ctx->r2 != ctx->r1) {
        // 0x8080115C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801178;
    }
    // 0x8080115C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801160: jal         0x80084CC8
    // 0x80801164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bafpctrl_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x80801164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80801168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080116C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801170: jal         0x800947EC
    // 0x80801174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800947EC(rdram, ctx);
        goto after_4;
    // 0x80801174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
L_80801178:
    // 0x80801178: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080117C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801184: jr          $ra
    // 0x80801188: nop

    return;
    // 0x80801188: nop

;}
RECOMP_FUNC void _badata_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846A8: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x800846A8);
    return;
    // 0x800846AC: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void bsblongleg_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012C8: jal         0x80800204
    // 0x808012CC: nop

    func_80800204_bsblongleg(rdram, ctx);
        goto after_0;
    // 0x808012CC: nop

    after_0:
    // 0x808012D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012D8: jr          $ra
    // 0x808012DC: nop

    return;
    // 0x808012DC: nop

;}
RECOMP_FUNC void func_80800520_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800524: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080052C: beq         $a1, $at, L_808005CC
    if (ctx->r5 == ctx->r1) {
        // 0x80800530: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808005CC;
    }
    // 0x80800530: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800534: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80800538: beq         $a1, $at, L_8080060C
    if (ctx->r5 == ctx->r1) {
        // 0x8080053C: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_8080060C;
    }
    // 0x8080053C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800540: beq         $a1, $at, L_8080059C
    if (ctx->r5 == ctx->r1) {
        // 0x80800544: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_8080059C;
    }
    // 0x80800544: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80800548: beq         $a1, $at, L_80800574
    if (ctx->r5 == ctx->r1) {
        // 0x8080054C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80800574;
    }
    // 0x8080054C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800550: beq         $a1, $at, L_80800584
    if (ctx->r5 == ctx->r1) {
        // 0x80800554: lw          $t6, 0x20($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X20);
            goto L_80800584;
    }
    // 0x80800554: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800558: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8080055C: beq         $a1, $at, L_808005BC
    if (ctx->r5 == ctx->r1) {
        // 0x80800560: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808005BC;
    }
    // 0x80800560: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800564: beq         $a1, $at, L_808005FC
    if (ctx->r5 == ctx->r1) {
        // 0x80800568: nop
    
            goto L_808005FC;
    }
    // 0x80800568: nop

    // 0x8080056C: b           L_8080062C
    // 0x80800570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080062C;
    // 0x80800570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800574:
    // 0x80800574: jal         0x808006F8
    // 0x80800578: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_808006F8_chonearmbandit(rdram, ctx);
        goto after_0;
    // 0x80800578: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8080057C: b           L_8080062C
    // 0x80800580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080062C;
    // 0x80800580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800584:
    // 0x80800584: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80800588: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8080058C: jal         0x80086678
    // 0x80800590: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _chexploder_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800590: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80800594: b           L_8080062C
    // 0x80800598: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080062C;
    // 0x80800598: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080059C:
    // 0x8080059C: jal         0x801072A8
    // 0x808005A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_801072A8(rdram, ctx);
        goto after_2;
    // 0x808005A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x808005A4: bne         $v0, $zero, L_80800628
    if (ctx->r2 != 0) {
        // 0x808005A8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800628;
    }
    // 0x808005A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005AC: jal         0x80800AB8
    // 0x808005B0: nop

    func_80800AB8_chonearmbandit(rdram, ctx);
        goto after_3;
    // 0x808005B0: nop

    after_3:
    // 0x808005B4: b           L_8080062C
    // 0x808005B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080062C;
    // 0x808005B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005BC:
    // 0x808005BC: jal         0x80800D00
    // 0x808005C0: nop

    func_80800D00_chonearmbandit(rdram, ctx);
        goto after_4;
    // 0x808005C0: nop

    after_4:
    // 0x808005C4: b           L_8080062C
    // 0x808005C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080062C;
    // 0x808005C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005CC:
    // 0x808005CC: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x808005D0: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808005D4: blezl       $t8, L_8080062C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x808005D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080062C;
    }
    goto skip_0;
    // 0x808005D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808005DC: jal         0x8008A4A8
    // 0x808005E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddieDll_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808005E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_5:
    // 0x808005E4: bne         $v0, $zero, L_80800628
    if (ctx->r2 != 0) {
        // 0x808005E8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800628;
    }
    // 0x808005E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005EC: jal         0x80107070
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80107070(rdram, ctx);
        goto after_6;
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808005F4: b           L_8080062C
    // 0x808005F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080062C;
    // 0x808005F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005FC:
    // 0x808005FC: jal         0x80089F60
    // 0x80800600: nop

    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800600: nop

    after_7:
    // 0x80800604: b           L_8080062C
    // 0x80800608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080062C;
    // 0x80800608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080060C:
    // 0x8080060C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(896, 0X1280) << 16);
    // 0x80800610: jal         0x80101074
    // 0x80800614: addiu       $a0, $a0, 0x1280
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(896, 0X1280));
    func_80101074(rdram, ctx);
        goto after_8;
    // 0x80800614: addiu       $a0, $a0, 0x1280
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(896, 0X1280));
    after_8:
    // 0x80800618: b           L_8080062C
    // 0x8080061C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8080062C;
    // 0x8080061C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80800620: b           L_8080062C
    // 0x80800624: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080062C;
    // 0x80800624: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800628:
    // 0x80800628: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080062C:
    // 0x8080062C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800634: jr          $ra
    // 0x80800638: nop

    return;
    // 0x80800638: nop

;}
RECOMP_FUNC void bsmumswim_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808009C4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(332, 0XB50) << 16);
    // 0x808009C8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808009CC: jr          $ra
    // 0x808009D0: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(332, 0XB50));
    return;
    // 0x808009D0: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(332, 0XB50));
;}
RECOMP_FUNC void suautobaddies_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80800104
    // 0x8080000C: nop

    func_80800104_suautobaddies(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: jal         0x80800194
    // 0x80800014: nop

    func_80800194_suautobaddies(rdram, ctx);
        goto after_1;
    // 0x80800014: nop

    after_1:
    // 0x80800018: jal         0x80800258
    // 0x8080001C: nop

    func_80800258_suautobaddies(rdram, ctx);
        goto after_2;
    // 0x8080001C: nop

    after_2:
    // 0x80800020: jal         0x80800298
    // 0x80800024: nop

    func_80800298_suautobaddies(rdram, ctx);
        goto after_3;
    // 0x80800024: nop

    after_3:
    // 0x80800028: jal         0x8080036C
    // 0x8080002C: nop

    func_8080036C_suautobaddies(rdram, ctx);
        goto after_4;
    // 0x8080002C: nop

    after_4:
    // 0x80800030: jal         0x808003DC
    // 0x80800034: nop

    func_808003DC_suautobaddies(rdram, ctx);
        goto after_5;
    // 0x80800034: nop

    after_5:
    // 0x80800038: jal         0x8080041C
    // 0x8080003C: nop

    suautobaddies_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x8080003C: nop

    after_6:
    // 0x80800040: jal         0x800EA05C
    // 0x80800044: nop

    func_800EA05C(rdram, ctx);
        goto after_7;
    // 0x80800044: nop

    after_7:
    // 0x80800048: jal         0x80088258
    // 0x8080004C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcsectionDll_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x8080004C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800054: jal         0x80088260
    // 0x80800058: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    _gcsectionDll_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80800058: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    after_9:
    // 0x8080005C: beq         $v0, $zero, L_8080007C
    if (ctx->r2 == 0) {
        // 0x80800060: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_8080007C;
    }
    // 0x80800060: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800064: addiu       $a0, $a0, 0x6D68
    ctx->r4 = ADD32(ctx->r4, 0X6D68);
    // 0x80800068: addiu       $a1, $zero, 0x374
    ctx->r5 = ADD32(0, 0X374);
    // 0x8080006C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800070: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800074: jal         0x80086D48
    // 0x80800078: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _chbaddiesetup_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80800078: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_10:
L_8080007C:
    // 0x8080007C: jal         0x800A9CD0
    // 0x80800080: nop

    func_800A9CD0(rdram, ctx);
        goto after_11;
    // 0x80800080: nop

    after_11:
    // 0x80800084: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800088: bne         $v0, $at, L_80800098
    if (ctx->r2 != ctx->r1) {
        // 0x8080008C: lui         $a0, 0x8008
        ctx->r4 = S32(0X8008 << 16);
            goto L_80800098;
    }
    // 0x8080008C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800090: jal         0x80086D28
    // 0x80800094: addiu       $a0, $a0, 0x5B28
    ctx->r4 = ADD32(ctx->r4, 0X5B28);
    _chbaddiesetup_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x80800094: addiu       $a0, $a0, 0x5B28
    ctx->r4 = ADD32(ctx->r4, 0X5B28);
    after_12:
L_80800098:
    // 0x80800098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080009C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000A0: jr          $ra
    // 0x808000A4: nop

    return;
    // 0x808000A4: nop

;}
RECOMP_FUNC void func_808062B8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808062B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808062BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808062C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808062C4: jal         0x80100094
    // 0x808062C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808062C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808062CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808062D0: jal         0x80802228
    // 0x808062D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x808062D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808062D8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808062DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808062E0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808062E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808062E8: swc1        $f4, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f4.u32l;
    // 0x808062EC: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x808062F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808062F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808062F8: jr          $ra
    // 0x808062FC: nop

    return;
    // 0x808062FC: nop

;}
