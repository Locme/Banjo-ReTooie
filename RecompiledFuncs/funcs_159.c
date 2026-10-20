#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801640_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801648: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080164C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801650: jal         0x80100094
    // 0x80801654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801658: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080165C: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1312, 0X2624) << 16);
    // 0x80801660: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80801664: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80801668: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x8080166C: lh          $v1, 0x2624($v1)
    ctx->r3 = MEM_H(ctx->r3, (int16_t)RELOC_LO16(1312, 0X2624));
    // 0x80801670: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x80801674: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x80801678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080167C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801680: jr          $ra
    // 0x80801684: nop

    return;
    // 0x80801684: nop

;}
RECOMP_FUNC void func_80017850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017850: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80017854: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x80017858: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001785C: jr          $ra
    // 0x80017860: sb          $t6, -0x5118($at)
    MEM_B(-0X5118, ctx->r1) = ctx->r14;
    return;
    // 0x80017860: sb          $t6, -0x5118($at)
    MEM_B(-0X5118, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_800920F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800920F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800920F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800920F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800920FC: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092100: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80092104: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80092108: lbu         $v0, 0x15($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X15);
    // 0x8009210C: beq         $v0, $at, L_80092124
    if (ctx->r2 == ctx->r1) {
        // 0x80092110: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80092124;
    }
    // 0x80092110: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80092114: beql        $v0, $at, L_8009215C
    if (ctx->r2 == ctx->r1) {
        // 0x80092118: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009215C;
    }
    goto skip_0;
    // 0x80092118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8009211C: b           L_80092148
    // 0x80092120: nop

        goto L_80092148;
    // 0x80092120: nop

L_80092124:
    // 0x80092124: jal         0x8009C984
    // 0x80092128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_0;
    // 0x80092128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8009212C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80092130: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80092134: jal         0x800136E4
    // 0x80092138: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x80092138: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    after_1:
    // 0x8009213C: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x80092140: b           L_80092158
    // 0x80092144: swc1        $f0, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f0.u32l;
        goto L_80092158;
    // 0x80092144: swc1        $f0, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f0.u32l;
L_80092148:
    // 0x80092148: jal         0x8009C984
    // 0x8009214C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_2;
    // 0x8009214C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80092150: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x80092154: swc1        $f0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f0.u32l;
L_80092158:
    // 0x80092158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009215C:
    // 0x8009215C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80092160: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80092164: jr          $ra
    // 0x80092168: nop

    return;
    // 0x80092168: nop

;}
RECOMP_FUNC void bskazglide_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A70: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A74: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(244, 0XAF0) << 16);
    // 0x80800A78: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A7C: jr          $ra
    // 0x80800A80: lw          $v0, 0xAF0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(244, 0XAF0));
    return;
    // 0x80800A80: lw          $v0, 0xAF0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(244, 0XAF0));
;}
RECOMP_FUNC void func_80800920_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800924: addiu       $at, $zero, 0x1520
    ctx->r1 = ADD32(0, 0X1520);
    // 0x80800928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080092C: bne         $a1, $at, L_80800944
    if (ctx->r5 != ctx->r1) {
        // 0x80800930: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800944;
    }
    // 0x80800930: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800934: jal         0x80800BD8
    // 0x80800938: nop

    func_80800BD8_chhoneyb(rdram, ctx);
        goto after_0;
    // 0x80800938: nop

    after_0:
    // 0x8080093C: b           L_8080095C
    // 0x80800940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080095C;
    // 0x80800940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800944:
    // 0x80800944: addiu       $at, $zero, 0x151B
    ctx->r1 = ADD32(0, 0X151B);
    // 0x80800948: bne         $a1, $at, L_80800958
    if (ctx->r5 != ctx->r1) {
        // 0x8080094C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80800958;
    }
    // 0x8080094C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800950: b           L_80800958
    // 0x80800954: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
        goto L_80800958;
    // 0x80800954: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
L_80800958:
    // 0x80800958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080095C:
    // 0x8080095C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800960: jr          $ra
    // 0x80800964: nop

    return;
    // 0x80800964: nop

;}
RECOMP_FUNC void func_808002D8_chtntdetonator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808002DC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808002E0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808002E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002E8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808002EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x808002F0: jal         0x800EE7F8
    // 0x808002F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808002F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002F8: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x808002FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800300: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800304: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800308: jal         0x80088B00
    // 0x8080030C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    _fxgenlist_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080030C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800310: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800318: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    // 0x8080031C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800320: jal         0x800BBCB8
    // 0x80800324: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80800324: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800328: jal         0x808003C0
    // 0x8080032C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808003C0_chtntdetonator(rdram, ctx);
        goto after_3;
    // 0x8080032C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80800330: jal         0x80800380
    // 0x80800334: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80800380_chtntdetonator(rdram, ctx);
        goto after_4;
    // 0x80800334: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80800338: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(904, 0X6F0) << 16);
    // 0x8080033C: addiu       $a1, $a1, 0x6F0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(904, 0X6F0));
    // 0x80800340: jal         0x800C4AF0
    // 0x80800344: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800C4AF0(rdram, ctx);
        goto after_5;
    // 0x80800344: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80800348: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8080034C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800350: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800354: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80800358: jal         0x800E1610
    // 0x8080035C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_800E1610(rdram, ctx);
        goto after_6;
    // 0x8080035C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80800360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800364: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80800368: jal         0x80018820
    // 0x8080036C: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    func_80018820(rdram, ctx);
        goto after_7;
    // 0x8080036C: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_7:
    // 0x80800370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800374: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800378: jr          $ra
    // 0x8080037C: nop

    return;
    // 0x8080037C: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B48: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B48);
    return;
    // 0x80087B4C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void vector_pop_back_n(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2EFC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800B2F00: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800B2F04: multu       $a1, $t7
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2F08: mflo        $t8
    ctx->r24 = lo;
    // 0x800B2F0C: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x800B2F10: jr          $ra
    // 0x800B2F14: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    return;
    // 0x800B2F14: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void _ncbadeflect_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089448: syscall     779
    recomp_syscall_handler(rdram, ctx, 0x80089448);
    return;
    // 0x8008944C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800824_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800824: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800828: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080082C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800830: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800834: jal         0x808001A8
    // 0x80800838: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    bsvan_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800838: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080083C: jal         0x8008CABC
    // 0x80800840: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_1;
    // 0x80800840: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800844: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800848: jal         0x8008AF24
    // 0x8080084C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_2;
    // 0x8080084C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800854: jal         0x8008AED4
    // 0x80800858: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800858: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    after_3:
    // 0x8080085C: lui         $a1, 0x3EB7
    ctx->r5 = S32(0X3EB7 << 16);
    // 0x80800860: ori         $a1, $a1, 0xCED9
    ctx->r5 = ctx->r5 | 0XCED9;
    // 0x80800864: jal         0x8008B24C
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_4;
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080086C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800870: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800874: jal         0x8008B1BC
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x80800878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080087C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800880: jal         0x8008B134
    // 0x80800884: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800884: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800888: jal         0x8008B064
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x8080088C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800890: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800894: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800898: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080089C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808008A0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808008A4: jal         0x8009FFD8
    // 0x808008A8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_8;
    // 0x808008A8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x808008AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808008B0: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808008B4: jal         0x8009C99C
    // 0x808008B8: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_9;
    // 0x808008B8: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_9:
    // 0x808008BC: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x808008C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008C4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808008C8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808008CC: jr          $ra
    // 0x808008D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808008D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bsclimb_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082EF8: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082EF8);
    return;
    // 0x80082EFC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_800E4140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4140: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E4144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4148: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800E414C: jal         0x800A89F8
    // 0x800E4150: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x800E4150: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E4154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E4158: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800E415C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800E4160: jal         0x800C4C34
    // 0x800E4164: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    func_800C4C34(rdram, ctx);
        goto after_1;
    // 0x800E4164: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x800E4168: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x800E416C: beq         $t6, $zero, L_800E4180
    if (ctx->r14 == 0) {
        // 0x800E4170: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_800E4180;
    }
    // 0x800E4170: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800E4174: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800E4178: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x800E417C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800E4180:
    // 0x800E4180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E4184: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E4188: jr          $ra
    // 0x800E418C: nop

    return;
    // 0x800E418C: nop

;}
RECOMP_FUNC void _badrone_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847F0: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800847F0);
    return;
    // 0x800847F4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808007F8_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800800: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800804: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800808: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080080C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800810: jal         0x80100094
    // 0x80800814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800814: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800818: beq         $s1, $zero, L_80800844
    if (ctx->r17 == 0) {
        // 0x8080081C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80800844;
    }
    // 0x8080081C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800820: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800824: beq         $s1, $at, L_80800858
    if (ctx->r17 == ctx->r1) {
        // 0x80800828: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800858;
    }
    // 0x80800828: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080082C: beq         $s1, $at, L_808008A4
    if (ctx->r17 == ctx->r1) {
        // 0x80800830: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808008A4;
    }
    // 0x80800830: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800834: beq         $s1, $at, L_808008C8
    if (ctx->r17 == ctx->r1) {
        // 0x80800838: nop
    
            goto L_808008C8;
    }
    // 0x80800838: nop

    // 0x8080083C: b           L_80800914
    // 0x80800840: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
        goto L_80800914;
    // 0x80800840: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80800844:
    // 0x80800844: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800848: nop

    // 0x8080084C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800850: b           L_80800910
    // 0x80800854: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
        goto L_80800910;
    // 0x80800854: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
L_80800858:
    // 0x80800858: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x8080085C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800860: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800864: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800868: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080086C: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800870: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800874: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800878: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080087C: jal         0x800EFA4C
    // 0x80800880: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x80800880: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800884: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800888: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1516, 0XF34) << 16);
    // 0x8080088C: lwc1        $f16, 0xF34($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1516, 0XF34));
    // 0x80800890: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80800894: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800898: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080089C: b           L_80800910
    // 0x808008A0: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
        goto L_80800910;
    // 0x808008A0: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
L_808008A4:
    // 0x808008A4: jal         0x80800D18
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D18_chnewshovel(rdram, ctx);
        goto after_2;
    // 0x808008A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808008AC: jal         0x80800CC4
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800CC4_chnewshovel(rdram, ctx);
        goto after_3;
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808008B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808008B8: nop

    // 0x808008BC: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808008C0: b           L_80800910
    // 0x808008C4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
        goto L_80800910;
    // 0x808008C4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
L_808008C8:
    // 0x808008C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1516, 0XF38) << 16);
    // 0x808008CC: lwc1        $f6, 0xF38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1516, 0XF38));
    // 0x808008D0: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808008D4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808008D8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808008DC: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808008E0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808008E4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x808008E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808008EC: jal         0x800EFA4C
    // 0x808008F0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x808008F0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x808008F4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x808008F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1516, 0XF3C) << 16);
    // 0x808008FC: lwc1        $f16, 0xF3C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1516, 0XF3C));
    // 0x80800900: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80800904: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800908: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080090C: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
L_80800910:
    // 0x80800910: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_80800914:
    // 0x80800914: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800918: sh          $s1, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r17;
    // 0x8080091C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800920: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800924: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800928: jr          $ra
    // 0x8080092C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080092C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800000_bsdronebubbled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x8080000C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800010: lw          $a2, 0x184($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X184);
    // 0x80800014: lw          $a0, 0x48($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X48);
    // 0x80800018: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8080001C: jal         0x8010114C
    // 0x80800020: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_0:
    // 0x80800024: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800028: lw          $t7, 0x54($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X54);
    // 0x8080002C: sw          $zero, 0x48($t7)
    MEM_W(0X48, ctx->r15) = 0;
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_80800024_chcrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: jal         0x80800380
    // 0x80800030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800380_chcrate(rdram, ctx);
        goto after_0;
    // 0x80800030: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800034: beq         $v0, $zero, L_80800054
    if (ctx->r2 == 0) {
        // 0x80800038: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800054;
    }
    // 0x80800038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080003C: jal         0x800DA298
    // 0x80800040: nop

    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800040: nop

    after_1:
    // 0x80800044: beql        $v0, $zero, L_80800058
    if (ctx->r2 == 0) {
        // 0x80800048: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800058;
    }
    goto skip_0;
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080004C: jal         0x800FFAB0
    // 0x80800050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80800054:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_8080044C_chdiggerbossshell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080044C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80800450: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800454: jr          $ra
    // 0x80800458: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80800458: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void sucoaster_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "sucoaster_entrypoint_2");
    // 0x808000F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800100: jal         0x80100094
    // 0x80800104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800108: lb          $t6, 0x17($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X17);
    // 0x8080010C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800110: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800114: beq         $t6, $at, L_80800134
    if (ctx->r14 == ctx->r1) {
        // 0x80800118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800134;
    }
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: lb          $a1, 0x17($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X17);
    // 0x80800120: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800124: jal         0x80089F40
    // 0x80800128: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddiesect_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800128: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8080012C: beq         $v0, $zero, L_80800268
    if (ctx->r2 == 0) {
        // 0x80800130: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80800268;
    }
    // 0x80800130: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_80800134:
    // 0x80800134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800138: jal         0x80801F70
    // 0x8080013C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    sucoaster_entrypoint_22(rdram, ctx);
        goto after_2;
    // 0x8080013C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x80800140: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80800144: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800148: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x8080014C: sll         $t9, $t7, 29
    ctx->r25 = S32(ctx->r15 << 29);
    // 0x80800150: bltzl       $t9, L_8080026C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800154: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080026C;
    }
    goto skip_0;
    // 0x80800154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800158: jal         0x800D9078
    // 0x8080015C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800D9078(rdram, ctx);
        goto after_3;
    // 0x8080015C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800160: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800164: lbu         $v1, 0x12($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X12);
    // 0x80800168: blez        $v1, L_80800174
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8080016C: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80800174;
    }
    // 0x8080016C: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x80800170: sb          $t0, 0x12($a3)
    MEM_B(0X12, ctx->r7) = ctx->r8;
L_80800174:
    // 0x80800174: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
    // 0x80800178: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8080017C: beql        $t2, $zero, L_808001E8
    if (ctx->r10 == 0) {
        // 0x80800180: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808001E8;
    }
    goto skip_1;
    // 0x80800180: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_1:
    // 0x80800184: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800188: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080018C: srl         $t3, $v0, 10
    ctx->r11 = S32(U32(ctx->r2) >> 10);
    // 0x80800190: beq         $t3, $at, L_808001E4
    if (ctx->r11 == ctx->r1) {
        // 0x80800194: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_808001E4;
    }
    // 0x80800194: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800198: beq         $t3, $at, L_808001E4
    if (ctx->r11 == ctx->r1) {
        // 0x8080019C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_808001E4;
    }
    // 0x8080019C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x808001A0: beql        $t3, $at, L_808001E8
    if (ctx->r11 == ctx->r1) {
        // 0x808001A4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808001E8;
    }
    goto skip_2;
    // 0x808001A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_2:
    // 0x808001A8: lbu         $v0, 0x13($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X13);
    // 0x808001AC: blez        $v0, L_808001E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808001B0: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_808001E4;
    }
    // 0x808001B0: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x808001B4: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x808001B8: bne         $t5, $zero, L_808001E4
    if (ctx->r13 != 0) {
        // 0x808001BC: sb          $t4, 0x13($a3)
        MEM_B(0X13, ctx->r7) = ctx->r12;
            goto L_808001E4;
    }
    // 0x808001BC: sb          $t4, 0x13($a3)
    MEM_B(0X13, ctx->r7) = ctx->r12;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001C8: jal         0x80801A7C
    // 0x808001CC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    sucoaster_entrypoint_17(rdram, ctx);
        goto after_4;
    // 0x808001CC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_4:
    // 0x808001D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X27B0) << 16);
    // 0x808001D4: jal         0x800D9058
    // 0x808001D8: lwc1        $f12, 0x27B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X27B0));
    func_800D9058(rdram, ctx);
        goto after_5;
    // 0x808001D8: lwc1        $f12, 0x27B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X27B0));
    after_5:
    // 0x808001DC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x808001E0: sb          $v0, 0x13($a3)
    MEM_B(0X13, ctx->r7) = ctx->r2;
L_808001E4:
    // 0x808001E4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_808001E8:
    // 0x808001E8: jal         0x80802760
    // 0x808001EC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80802760_sucoaster(rdram, ctx);
        goto after_6;
    // 0x808001EC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_6:
    // 0x808001F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808001F4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x808001F8: beq         $v0, $at, L_80800210
    if (ctx->r2 == ctx->r1) {
        // 0x808001FC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800210;
    }
    // 0x808001FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800200: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800204: jal         0x800F5A00
    // 0x80800208: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_800F5A00(rdram, ctx);
        goto after_7;
    // 0x80800208: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_7:
    // 0x8080020C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_80800210:
    // 0x80800210: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8080021C: bgez        $t8, L_80800234
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800220: nop
    
            goto L_80800234;
    }
    // 0x80800220: nop

    // 0x80800224: jal         0x8008A308
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoasterplayer_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080022C: b           L_80800240
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800240;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800234:
    // 0x80800234: jal         0x8080027C
    // 0x80800238: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_8080027C_sucoaster(rdram, ctx);
        goto after_9;
    // 0x80800238: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_9:
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800240:
    // 0x80800240: jal         0x80100094
    // 0x80800244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x80800244: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800248: beq         $v0, $zero, L_80800268
    if (ctx->r2 == 0) {
        // 0x8080024C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800268;
    }
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: jal         0x80100094
    // 0x80800254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80800254: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080025C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800260: jal         0x800897D8
    // 0x80800264: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_12;
    // 0x80800264: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
L_80800268:
    // 0x80800268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080026C:
    // 0x8080026C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800270: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800274: jr          $ra
    // 0x80800278: nop

    return;
    // 0x80800278: nop

;}
RECOMP_FUNC void subaddiecustomhits_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080029C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808002A8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x808002AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808002B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808002B4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x808002B8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x808002BC: sll         $t9, $t7, 30
    ctx->r25 = S32(ctx->r15 << 30);
    // 0x808002C0: bltz        $t9, L_808002D8
    if (SIGNED(ctx->r25) < 0) {
        // 0x808002C4: nop
    
            goto L_808002D8;
    }
    // 0x808002C4: nop

    // 0x808002C8: jal         0x800EC75C
    // 0x808002CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800EC75C(rdram, ctx);
        goto after_0;
    // 0x808002CC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x808002D0: b           L_80800334
    // 0x808002D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800334;
    // 0x808002D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002D8:
    // 0x808002D8: jal         0x80103328
    // 0x808002DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80103328(rdram, ctx);
        goto after_1;
    // 0x808002DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x808002E0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808002E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808002E8: jal         0x800EE7F8
    // 0x808002EC: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808002EC: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    after_2:
    // 0x808002F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808002F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808002F8: lhu         $t0, 0x6A($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X6A);
    // 0x808002FC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80800300: bgez        $t0, L_80800314
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800304: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800314;
    }
    // 0x80800304: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800308: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080030C: nop

    // 0x80800310: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800314:
    // 0x80800314: lwc1        $f10, 0x38($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X38);
    // 0x80800318: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3246, 0X340) << 16);
    // 0x8080031C: lwc1        $f18, 0x340($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3246, 0X340));
    // 0x80800320: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800324: nop

    // 0x80800328: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8080032C: nop

    // 0x80800330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800334:
    // 0x80800334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800338: jr          $ra
    // 0x8080033C: nop

    return;
    // 0x8080033C: nop

;}
RECOMP_FUNC void func_808005DC_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808005E8: jal         0x801040A8
    // 0x808005EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_801040A8(rdram, ctx);
        goto after_0;
    // 0x808005EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808005F0: jal         0x800AE6BC
    // 0x808005F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AE6BC(rdram, ctx);
        goto after_1;
    // 0x808005F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808005F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800600: jal         0x80806528
    // 0x80800604: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_80806528_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80800604: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080060C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800610: jr          $ra
    // 0x80800614: nop

    return;
    // 0x80800614: nop

;}
RECOMP_FUNC void func_800B2D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2D48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2D4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2D50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B2D54: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800B2D58: jal         0x8001B754
    // 0x800B2D5C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B754(rdram, ctx);
        goto after_0;
    // 0x800B2D5C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x800B2D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2D64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B2D68: jr          $ra
    // 0x800B2D6C: nop

    return;
    // 0x800B2D6C: nop

;}
RECOMP_FUNC void func_800F219C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F219C: mfc1        $v0, $f12
    ctx->r2 = (int32_t)ctx->f12.u32l;
    // 0x800F21A0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800F21A4: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800F21A8: srl         $t0, $v0, 24
    ctx->r8 = S32(U32(ctx->r2) >> 24);
    // 0x800F21AC: beq         $t0, $t1, L_800F21BC
    if (ctx->r8 == ctx->r9) {
        // 0x800F21B0: sll         $v0, $v0, 8
        ctx->r2 = S32(ctx->r2 << 8);
            goto L_800F21BC;
    }
    // 0x800F21B0: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800F21B4: jr          $ra
    // 0x800F21B8: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    return;
    // 0x800F21B8: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
L_800F21BC:
    // 0x800F21BC: jr          $ra
    // 0x800F21C0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x800F21C0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
RECOMP_FUNC void chcamerawibble_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1408, 0XE0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1408, 0XE0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1408, 0XE0));
;}
RECOMP_FUNC void func_80803A78_chintrochar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803A78: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80803A7C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80803A80: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80803A84: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80803A88: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80803A8C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1732, 0X4160) << 16);
    // 0x80803A90: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803A94: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80803A98: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80803A9C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80803AA0: lw          $t9, 0x4160($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(1732, 0X4160));
    // 0x80803AA4: andi        $t1, $t9, 0x2
    ctx->r9 = ctx->r25 & 0X2;
    // 0x80803AA8: beq         $t1, $zero, L_80803C58
    if (ctx->r9 == 0) {
        // 0x80803AAC: sw          $t9, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r25;
            goto L_80803C58;
    }
    // 0x80803AAC: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x80803AB0: andi        $t2, $t9, 0x8000
    ctx->r10 = ctx->r25 & 0X8000;
    // 0x80803AB4: beq         $t2, $zero, L_80803BB0
    if (ctx->r10 == 0) {
        // 0x80803AB8: addiu       $a1, $sp, 0x48
        ctx->r5 = ADD32(ctx->r29, 0X48);
            goto L_80803BB0;
    }
    // 0x80803AB8: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80803ABC: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(1732, 0X5318) << 16);
    // 0x80803AC0: addiu       $t4, $t4, 0x5318
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(1732, 0X5318));
    // 0x80803AC4: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80803AC8: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x80803ACC: addiu       $t3, $sp, 0x60
    ctx->r11 = ADD32(ctx->r29, 0X60);
    // 0x80803AD0: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x80803AD4: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x80803AD8: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80803ADC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803AE0: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80803AE4: srl         $t8, $v0, 7
    ctx->r24 = S32(U32(ctx->r2) >> 7);
    // 0x80803AE8: addiu       $v0, $t8, -0x32
    ctx->r2 = ADD32(ctx->r24, -0X32);
    // 0x80803AEC: beq         $v0, $at, L_80803AF8
    if (ctx->r2 == ctx->r1) {
        // 0x80803AF0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80803AF8;
    }
    // 0x80803AF0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80803AF4: bne         $v0, $at, L_80803B0C
    if (ctx->r2 != ctx->r1) {
        // 0x80803AF8: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80803B0C;
    }
L_80803AF8:
    // 0x80803AF8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80803AFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803B00: nop

    // 0x80803B04: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80803B08: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
L_80803B0C:
    // 0x80803B0C: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x80803B10: andi        $t1, $t9, 0x4
    ctx->r9 = ctx->r25 & 0X4;
    // 0x80803B14: bne         $t1, $zero, L_80803B58
    if (ctx->r9 != 0) {
        // 0x80803B18: nop
    
            goto L_80803B58;
    }
    // 0x80803B18: nop

    // 0x80803B1C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80803B20: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80803B24: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80803B28: nop

    // 0x80803B2C: bc1t        L_80803B58
    if (c1cs) {
        // 0x80803B30: nop
    
            goto L_80803B58;
    }
    // 0x80803B30: nop

    // 0x80803B34: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80803B38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80803B3C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80803B40: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80803B44: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80803B48: jal         0x800EFA4C
    // 0x80803B4C: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x80803B4C: nop

    after_0:
    // 0x80803B50: jal         0x800DF4CC
    // 0x80803B54: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    func_800DF4CC(rdram, ctx);
        goto after_1;
    // 0x80803B54: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_1:
L_80803B58:
    // 0x80803B58: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80803B5C: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x80803B60: jal         0x800DF47C
    // 0x80803B64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_2;
    // 0x80803B64: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80803B68: jal         0x8010347C
    // 0x80803B6C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_3;
    // 0x80803B6C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80803B70: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X4778) << 16);
    // 0x80803B74: lwc1        $f16, 0x4778($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X4778));
    // 0x80803B78: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80803B7C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80803B80: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80803B84: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80803B88: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80803B8C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80803B90: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x80803B94: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80803B98: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80803B9C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80803BA0: jal         0x800DF944
    // 0x80803BA4: nop

    func_800DF944(rdram, ctx);
        goto after_4;
    // 0x80803BA4: nop

    after_4:
    // 0x80803BA8: b           L_80803CE0
    // 0x80803BAC: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
        goto L_80803CE0;
    // 0x80803BAC: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
L_80803BB0:
    // 0x80803BB0: jal         0x800E39A8
    // 0x80803BB4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_800E39A8(rdram, ctx);
        goto after_5;
    // 0x80803BB4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_5:
    // 0x80803BB8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80803BBC: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x80803BC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803BC4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80803BC8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80803BCC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80803BD0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80803BD4: jal         0x800EF5A0
    // 0x80803BD8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_6;
    // 0x80803BD8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80803BDC: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80803BE0: jal         0x800EF04C
    // 0x80803BE4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80803BE4: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_7:
    // 0x80803BE8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80803BEC: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x80803BF0: jal         0x800DF47C
    // 0x80803BF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_8;
    // 0x80803BF4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80803BF8: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x80803BFC: andi        $t6, $t2, 0x4
    ctx->r14 = ctx->r10 & 0X4;
    // 0x80803C00: beq         $t6, $zero, L_80803C30
    if (ctx->r14 == 0) {
        // 0x80803C04: nop
    
            goto L_80803C30;
    }
    // 0x80803C04: nop

    // 0x80803C08: jal         0x801039E4
    // 0x80803C0C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_9;
    // 0x80803C0C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x80803C10: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80803C14: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80803C18: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80803C1C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80803C20: jal         0x800DE448
    // 0x80803C24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_10;
    // 0x80803C24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x80803C28: b           L_80803CE0
    // 0x80803C2C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
        goto L_80803CE0;
    // 0x80803C2C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
L_80803C30:
    // 0x80803C30: jal         0x801039E4
    // 0x80803C34: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_11;
    // 0x80803C34: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_11:
    // 0x80803C38: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80803C3C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80803C40: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80803C44: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80803C48: jal         0x800DE448
    // 0x80803C4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_12;
    // 0x80803C4C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x80803C50: b           L_80803CE0
    // 0x80803C54: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
        goto L_80803CE0;
    // 0x80803C54: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
L_80803C58:
    // 0x80803C58: lw          $t5, 0x94($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X94);
    // 0x80803C5C: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x80803C60: bgez        $t4, L_80803C78
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80803C64: nop
    
            goto L_80803C78;
    }
    // 0x80803C64: nop

    // 0x80803C68: jal         0x800DF440
    // 0x80803C6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_13;
    // 0x80803C6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80803C70: b           L_80803C84
    // 0x80803C74: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
        goto L_80803C84;
    // 0x80803C74: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
L_80803C78:
    // 0x80803C78: jal         0x80101970
    // 0x80803C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101970(rdram, ctx);
        goto after_14;
    // 0x80803C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80803C80: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
L_80803C84:
    // 0x80803C84: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x80803C88: beq         $t8, $zero, L_80803CAC
    if (ctx->r24 == 0) {
        // 0x80803C8C: nop
    
            goto L_80803CAC;
    }
    // 0x80803C8C: nop

    // 0x80803C90: lhu         $t9, 0x76($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X76);
    // 0x80803C94: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1732, 0X4168) << 16);
    // 0x80803C98: srl         $t1, $t9, 7
    ctx->r9 = S32(U32(ctx->r25) >> 7);
    // 0x80803C9C: sll         $t0, $t1, 5
    ctx->r8 = S32(ctx->r9 << 5);
    // 0x80803CA0: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80803CA4: jal         0x800DF464
    // 0x80803CA8: lwc1        $f12, 0x4168($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X4168));
    func_800DF464(rdram, ctx);
        goto after_15;
    // 0x80803CA8: lwc1        $f12, 0x4168($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1732, 0X4168));
    after_15:
L_80803CAC:
    // 0x80803CAC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80803CB0: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x80803CB4: jal         0x800DF47C
    // 0x80803CB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_16;
    // 0x80803CB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x80803CBC: jal         0x801039E4
    // 0x80803CC0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_17;
    // 0x80803CC0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_17:
    // 0x80803CC4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80803CC8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80803CCC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80803CD0: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80803CD4: jal         0x800DE448
    // 0x80803CD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_18;
    // 0x80803CD8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x80803CDC: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
L_80803CE0:
    // 0x80803CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803CE4: andi        $t6, $t2, 0x1000
    ctx->r14 = ctx->r10 & 0X1000;
    // 0x80803CE8: beql        $t6, $zero, L_80803CFC
    if (ctx->r14 == 0) {
        // 0x80803CEC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80803CFC;
    }
    goto skip_0;
    // 0x80803CEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80803CF0: jal         0x80803990
    // 0x80803CF4: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    func_80803990_chintrochar(rdram, ctx);
        goto after_19;
    // 0x80803CF4: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    after_19:
    // 0x80803CF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80803CFC:
    // 0x80803CFC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80803D00: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80803D04: jr          $ra
    // 0x80803D08: nop

    return;
    // 0x80803D08: nop

;}
RECOMP_FUNC void func_8010FBD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FBD4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010FBD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010FBDC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010FBE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010FBE4: jal         0x8010F9C0
    // 0x8010FBE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010F9C0(rdram, ctx);
        goto after_0;
    // 0x8010FBE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8010FBEC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8010FBF0: beql        $a0, $zero, L_8010FC04
    if (ctx->r4 == 0) {
        // 0x8010FBF4: lw          $a0, 0xC($s0)
        ctx->r4 = MEM_W(ctx->r16, 0XC);
            goto L_8010FC04;
    }
    goto skip_0;
    // 0x8010FBF4: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x8010FBF8: jal         0x801104F4
    // 0x8010FBFC: nop

    func_801104F4(rdram, ctx);
        goto after_1;
    // 0x8010FBFC: nop

    after_1:
    // 0x8010FC00: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
L_8010FC04:
    // 0x8010FC04: beq         $a0, $zero, L_8010FC14
    if (ctx->r4 == 0) {
        // 0x8010FC08: nop
    
            goto L_8010FC14;
    }
    // 0x8010FC08: nop

    // 0x8010FC0C: jal         0x801150F8
    // 0x8010FC10: nop

    func_801150F8(rdram, ctx);
        goto after_2;
    // 0x8010FC10: nop

    after_2:
L_8010FC14:
    // 0x8010FC14: jal         0x80114C7C
    // 0x8010FC18: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    func_80114C7C(rdram, ctx);
        goto after_3;
    // 0x8010FC18: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_3:
    // 0x8010FC1C: jal         0x8001B084
    // 0x8010FC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    heap_free(rdram, ctx);
        goto after_4;
    // 0x8010FC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8010FC24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010FC28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010FC2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010FC30: jr          $ra
    // 0x8010FC34: nop

    return;
    // 0x8010FC34: nop

;}
RECOMP_FUNC void func_800E4E54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4E54: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800E4E58: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800E4E5C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800E4E60: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800E4E64: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800E4E68: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800E4E6C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800E4E70: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800E4E74: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800E4E78: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800E4E7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E4E80: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800E4E84: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800E4E88: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800E4E8C: addiu       $t0, $t0, 0x32C0
    ctx->r8 = ADD32(ctx->r8, 0X32C0);
    // 0x800E4E90: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800E4E94: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x800E4E98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E4E9C: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800E4EA0: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x800E4EA4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800E4EA8: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x800E4EAC: lw          $s4, 0xC($a0)
    ctx->r20 = MEM_W(ctx->r4, 0XC);
    // 0x800E4EB0: lw          $s2, 0x10($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X10);
    // 0x800E4EB4: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800E4EB8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800E4EBC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800E4EC0: lw          $fp, 0x14($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X14);
    // 0x800E4EC4: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800E4EC8: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x800E4ECC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800E4ED0: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x800E4ED4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800E4ED8: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
L_800E4EDC:
    // 0x800E4EDC: sltu        $at, $s2, $v0
    ctx->r1 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x800E4EE0: beq         $at, $zero, L_800E4F48
    if (ctx->r1 == 0) {
        // 0x800E4EE4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800E4F48;
    }
    // 0x800E4EE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800E4EE8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E4EEC:
    // 0x800E4EEC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E4EF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E4EF4: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E4EF8: bnel        $at, $zero, L_800E4F28
    if (ctx->r1 != 0) {
        // 0x800E4EFC: addu        $t9, $s1, $v0
        ctx->r25 = ADD32(ctx->r17, ctx->r2);
            goto L_800E4F28;
    }
    goto skip_0;
    // 0x800E4EFC: addu        $t9, $s1, $v0
    ctx->r25 = ADD32(ctx->r17, ctx->r2);
    skip_0:
    // 0x800E4F00: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E4F04: jal         0x8001311C
    // 0x800E4F08: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_0;
    // 0x800E4F08: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_0:
    // 0x800E4F0C: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800E4F10: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x800E4F14: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E4F18: addiu       $t8, $t7, 0x1800
    ctx->r24 = ADD32(ctx->r15, 0X1800);
    // 0x800E4F1C: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x800E4F20: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E4F24: addu        $t9, $s1, $v0
    ctx->r25 = ADD32(ctx->r17, ctx->r2);
L_800E4F28:
    // 0x800E4F28: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x800E4F2C: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x800E4F30: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800E4F34: sllv        $t2, $t1, $s2
    ctx->r10 = S32(ctx->r9 << (ctx->r18 & 31));
    // 0x800E4F38: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E4F3C: sltu        $at, $s2, $v1
    ctx->r1 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x800E4F40: bne         $at, $zero, L_800E4EEC
    if (ctx->r1 != 0) {
        // 0x800E4F44: or          $s4, $s4, $t2
        ctx->r20 = ctx->r20 | ctx->r10;
            goto L_800E4EEC;
    }
    // 0x800E4F44: or          $s4, $s4, $t2
    ctx->r20 = ctx->r20 | ctx->r10;
L_800E4F48:
    // 0x800E4F48: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800E4F4C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800E4F50: and         $t0, $s4, $t4
    ctx->r8 = ctx->r20 & ctx->r12;
    // 0x800E4F54: sll         $t5, $t0, 3
    ctx->r13 = S32(ctx->r8 << 3);
    // 0x800E4F58: addu        $s6, $t5, $t6
    ctx->r22 = ADD32(ctx->r13, ctx->r14);
    // 0x800E4F5C: lbu         $s3, 0x0($s6)
    ctx->r19 = MEM_BU(ctx->r22, 0X0);
    // 0x800E4F60: sltiu       $at, $s3, 0x11
    ctx->r1 = ctx->r19 < 0X11 ? 1 : 0;
    // 0x800E4F64: bnel        $at, $zero, L_800E5014
    if (ctx->r1 != 0) {
        // 0x800E4F68: lbu         $v0, 0x1($s6)
        ctx->r2 = MEM_BU(ctx->r22, 0X1);
            goto L_800E5014;
    }
    goto skip_1;
    // 0x800E4F68: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
    skip_1:
    // 0x800E4F6C: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
L_800E4F70:
    // 0x800E4F70: addiu       $s3, $s3, -0x10
    ctx->r19 = ADD32(ctx->r19, -0X10);
    // 0x800E4F74: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x800E4F78: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E4F7C: beq         $at, $zero, L_800E4FE0
    if (ctx->r1 == 0) {
        // 0x800E4F80: srlv        $s4, $s4, $v0
        ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
            goto L_800E4FE0;
    }
    // 0x800E4F80: srlv        $s4, $s4, $v0
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
    // 0x800E4F84: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E4F88:
    // 0x800E4F88: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E4F8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E4F90: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E4F94: bnel        $at, $zero, L_800E4FC0
    if (ctx->r1 != 0) {
        // 0x800E4F98: addu        $t9, $s1, $v0
        ctx->r25 = ADD32(ctx->r17, ctx->r2);
            goto L_800E4FC0;
    }
    goto skip_2;
    // 0x800E4F98: addu        $t9, $s1, $v0
    ctx->r25 = ADD32(ctx->r17, ctx->r2);
    skip_2:
    // 0x800E4F9C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E4FA0: jal         0x8001311C
    // 0x800E4FA4: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_1;
    // 0x800E4FA4: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_1:
    // 0x800E4FA8: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800E4FAC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E4FB0: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E4FB4: addiu       $t8, $t7, 0x1800
    ctx->r24 = ADD32(ctx->r15, 0X1800);
    // 0x800E4FB8: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x800E4FBC: addu        $t9, $s1, $v0
    ctx->r25 = ADD32(ctx->r17, ctx->r2);
L_800E4FC0:
    // 0x800E4FC0: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x800E4FC4: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x800E4FC8: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800E4FCC: sllv        $t2, $t1, $s2
    ctx->r10 = S32(ctx->r9 << (ctx->r18 & 31));
    // 0x800E4FD0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E4FD4: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E4FD8: bne         $at, $zero, L_800E4F88
    if (ctx->r1 != 0) {
        // 0x800E4FDC: or          $s4, $s4, $t2
        ctx->r20 = ctx->r20 | ctx->r10;
            goto L_800E4F88;
    }
    // 0x800E4FDC: or          $s4, $s4, $t2
    ctx->r20 = ctx->r20 | ctx->r10;
L_800E4FE0:
    // 0x800E4FE0: sll         $t4, $s3, 1
    ctx->r12 = S32(ctx->r19 << 1);
    // 0x800E4FE4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800E4FE8: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x800E4FEC: lhu         $t0, 0x32C0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X32C0);
    // 0x800E4FF0: lw          $t7, 0x4($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X4);
    // 0x800E4FF4: and         $t5, $t0, $s4
    ctx->r13 = ctx->r8 & ctx->r20;
    // 0x800E4FF8: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800E4FFC: addu        $s6, $t6, $t7
    ctx->r22 = ADD32(ctx->r14, ctx->r15);
    // 0x800E5000: lbu         $s3, 0x0($s6)
    ctx->r19 = MEM_BU(ctx->r22, 0X0);
    // 0x800E5004: sltiu       $at, $s3, 0x11
    ctx->r1 = ctx->r19 < 0X11 ? 1 : 0;
    // 0x800E5008: beql        $at, $zero, L_800E4F70
    if (ctx->r1 == 0) {
        // 0x800E500C: lbu         $v0, 0x1($s6)
        ctx->r2 = MEM_BU(ctx->r22, 0X1);
            goto L_800E4F70;
    }
    goto skip_3;
    // 0x800E500C: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
    skip_3:
    // 0x800E5010: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
L_800E5014:
    // 0x800E5014: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800E5018: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800E501C: srlv        $s4, $s4, $v0
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
    // 0x800E5020: bne         $s3, $at, L_800E503C
    if (ctx->r19 != ctx->r1) {
        // 0x800E5024: subu        $s2, $s2, $v0
        ctx->r18 = SUB32(ctx->r18, ctx->r2);
            goto L_800E503C;
    }
    // 0x800E5024: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x800E5028: lhu         $t8, 0x4($s6)
    ctx->r24 = MEM_HU(ctx->r22, 0X4);
    // 0x800E502C: addu        $t1, $t9, $fp
    ctx->r9 = ADD32(ctx->r25, ctx->r30);
    // 0x800E5030: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800E5034: b           L_800E531C
    // 0x800E5038: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
        goto L_800E531C;
    // 0x800E5038: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
L_800E503C:
    // 0x800E503C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800E5040: beq         $s3, $at, L_800E5350
    if (ctx->r19 == ctx->r1) {
        // 0x800E5044: lw          $t2, 0x40($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X40);
            goto L_800E5350;
    }
    // 0x800E5044: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800E5048: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E504C: beq         $at, $zero, L_800E50B0
    if (ctx->r1 == 0) {
        // 0x800E5050: addu        $s5, $t2, $fp
        ctx->r21 = ADD32(ctx->r10, ctx->r30);
            goto L_800E50B0;
    }
    // 0x800E5050: addu        $s5, $t2, $fp
    ctx->r21 = ADD32(ctx->r10, ctx->r30);
    // 0x800E5054: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E5058:
    // 0x800E5058: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E505C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E5060: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E5064: bnel        $at, $zero, L_800E5090
    if (ctx->r1 != 0) {
        // 0x800E5068: addu        $t0, $s1, $v0
        ctx->r8 = ADD32(ctx->r17, ctx->r2);
            goto L_800E5090;
    }
    goto skip_4;
    // 0x800E5068: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
    skip_4:
    // 0x800E506C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E5070: jal         0x8001311C
    // 0x800E5074: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_2;
    // 0x800E5074: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_2:
    // 0x800E5078: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x800E507C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5080: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E5084: addiu       $t4, $t3, 0x1800
    ctx->r12 = ADD32(ctx->r11, 0X1800);
    // 0x800E5088: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
    // 0x800E508C: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
L_800E5090:
    // 0x800E5090: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800E5094: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800E5098: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800E509C: sllv        $t6, $t5, $s2
    ctx->r14 = S32(ctx->r13 << (ctx->r18 & 31));
    // 0x800E50A0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E50A4: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E50A8: bne         $at, $zero, L_800E5058
    if (ctx->r1 != 0) {
        // 0x800E50AC: or          $s4, $s4, $t6
        ctx->r20 = ctx->r20 | ctx->r14;
            goto L_800E5058;
    }
    // 0x800E50AC: or          $s4, $s4, $t6
    ctx->r20 = ctx->r20 | ctx->r14;
L_800E50B0:
    // 0x800E50B0: sll         $t9, $s3, 1
    ctx->r25 = S32(ctx->r19 << 1);
    // 0x800E50B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800E50B8: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800E50BC: lhu         $t8, 0x32C0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X32C0);
    // 0x800E50C0: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x800E50C4: lhu         $t2, 0x4($s6)
    ctx->r10 = MEM_HU(ctx->r22, 0X4);
    // 0x800E50C8: subu        $s2, $s2, $s3
    ctx->r18 = SUB32(ctx->r18, ctx->r19);
    // 0x800E50CC: and         $t1, $t8, $s4
    ctx->r9 = ctx->r24 & ctx->r20;
    // 0x800E50D0: sltu        $at, $s2, $v1
    ctx->r1 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x800E50D4: srlv        $s4, $s4, $s3
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r19 & 31));
    // 0x800E50D8: beq         $at, $zero, L_800E5140
    if (ctx->r1 == 0) {
        // 0x800E50DC: addu        $s7, $t1, $t2
        ctx->r23 = ADD32(ctx->r9, ctx->r10);
            goto L_800E5140;
    }
    // 0x800E50DC: addu        $s7, $t1, $t2
    ctx->r23 = ADD32(ctx->r9, ctx->r10);
    // 0x800E50E0: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E50E4:
    // 0x800E50E4: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E50E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E50EC: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E50F0: bnel        $at, $zero, L_800E5120
    if (ctx->r1 != 0) {
        // 0x800E50F4: addu        $t0, $s1, $v0
        ctx->r8 = ADD32(ctx->r17, ctx->r2);
            goto L_800E5120;
    }
    goto skip_5;
    // 0x800E50F4: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
    skip_5:
    // 0x800E50F8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E50FC: jal         0x8001311C
    // 0x800E5100: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_3;
    // 0x800E5100: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_3:
    // 0x800E5104: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x800E5108: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E510C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E5110: addiu       $t4, $t3, 0x1800
    ctx->r12 = ADD32(ctx->r11, 0X1800);
    // 0x800E5114: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
    // 0x800E5118: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x800E511C: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
L_800E5120:
    // 0x800E5120: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800E5124: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800E5128: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800E512C: sllv        $t6, $t5, $s2
    ctx->r14 = S32(ctx->r13 << (ctx->r18 & 31));
    // 0x800E5130: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E5134: sltu        $at, $s2, $v1
    ctx->r1 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x800E5138: bne         $at, $zero, L_800E50E4
    if (ctx->r1 != 0) {
        // 0x800E513C: or          $s4, $s4, $t6
        ctx->r20 = ctx->r20 | ctx->r14;
            goto L_800E50E4;
    }
    // 0x800E513C: or          $s4, $s4, $t6
    ctx->r20 = ctx->r20 | ctx->r14;
L_800E5140:
    // 0x800E5140: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800E5144: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800E5148: and         $t8, $s4, $t9
    ctx->r24 = ctx->r20 & ctx->r25;
    // 0x800E514C: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x800E5150: addu        $s6, $t1, $t2
    ctx->r22 = ADD32(ctx->r9, ctx->r10);
    // 0x800E5154: lbu         $s3, 0x0($s6)
    ctx->r19 = MEM_BU(ctx->r22, 0X0);
    // 0x800E5158: sltiu       $at, $s3, 0x11
    ctx->r1 = ctx->r19 < 0X11 ? 1 : 0;
    // 0x800E515C: bnel        $at, $zero, L_800E520C
    if (ctx->r1 != 0) {
        // 0x800E5160: lbu         $v0, 0x1($s6)
        ctx->r2 = MEM_BU(ctx->r22, 0X1);
            goto L_800E520C;
    }
    goto skip_6;
    // 0x800E5160: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
    skip_6:
    // 0x800E5164: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
L_800E5168:
    // 0x800E5168: addiu       $s3, $s3, -0x10
    ctx->r19 = ADD32(ctx->r19, -0X10);
    // 0x800E516C: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x800E5170: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E5174: beq         $at, $zero, L_800E51D8
    if (ctx->r1 == 0) {
        // 0x800E5178: srlv        $s4, $s4, $v0
        ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
            goto L_800E51D8;
    }
    // 0x800E5178: srlv        $s4, $s4, $v0
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
    // 0x800E517C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E5180:
    // 0x800E5180: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E5188: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E518C: bnel        $at, $zero, L_800E51B8
    if (ctx->r1 != 0) {
        // 0x800E5190: addu        $t0, $s1, $v0
        ctx->r8 = ADD32(ctx->r17, ctx->r2);
            goto L_800E51B8;
    }
    goto skip_7;
    // 0x800E5190: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
    skip_7:
    // 0x800E5194: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E5198: jal         0x8001311C
    // 0x800E519C: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_4;
    // 0x800E519C: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_4:
    // 0x800E51A0: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x800E51A4: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E51A8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E51AC: addiu       $t4, $t3, 0x1800
    ctx->r12 = ADD32(ctx->r11, 0X1800);
    // 0x800E51B0: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
    // 0x800E51B4: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
L_800E51B8:
    // 0x800E51B8: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800E51BC: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800E51C0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800E51C4: sllv        $t6, $t5, $s2
    ctx->r14 = S32(ctx->r13 << (ctx->r18 & 31));
    // 0x800E51C8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E51CC: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E51D0: bne         $at, $zero, L_800E5180
    if (ctx->r1 != 0) {
        // 0x800E51D4: or          $s4, $s4, $t6
        ctx->r20 = ctx->r20 | ctx->r14;
            goto L_800E5180;
    }
    // 0x800E51D4: or          $s4, $s4, $t6
    ctx->r20 = ctx->r20 | ctx->r14;
L_800E51D8:
    // 0x800E51D8: sll         $t9, $s3, 1
    ctx->r25 = S32(ctx->r19 << 1);
    // 0x800E51DC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800E51E0: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800E51E4: lhu         $t8, 0x32C0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X32C0);
    // 0x800E51E8: lw          $t3, 0x4($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X4);
    // 0x800E51EC: and         $t1, $t8, $s4
    ctx->r9 = ctx->r24 & ctx->r20;
    // 0x800E51F0: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800E51F4: addu        $s6, $t2, $t3
    ctx->r22 = ADD32(ctx->r10, ctx->r11);
    // 0x800E51F8: lbu         $s3, 0x0($s6)
    ctx->r19 = MEM_BU(ctx->r22, 0X0);
    // 0x800E51FC: sltiu       $at, $s3, 0x11
    ctx->r1 = ctx->r19 < 0X11 ? 1 : 0;
    // 0x800E5200: beql        $at, $zero, L_800E5168
    if (ctx->r1 == 0) {
        // 0x800E5204: lbu         $v0, 0x1($s6)
        ctx->r2 = MEM_BU(ctx->r22, 0X1);
            goto L_800E5168;
    }
    goto skip_8;
    // 0x800E5204: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
    skip_8:
    // 0x800E5208: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
L_800E520C:
    // 0x800E520C: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x800E5210: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E5214: beq         $at, $zero, L_800E5278
    if (ctx->r1 == 0) {
        // 0x800E5218: srlv        $s4, $s4, $v0
        ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
            goto L_800E5278;
    }
    // 0x800E5218: srlv        $s4, $s4, $v0
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
    // 0x800E521C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E5220:
    // 0x800E5220: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5224: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E5228: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E522C: bnel        $at, $zero, L_800E5258
    if (ctx->r1 != 0) {
        // 0x800E5230: addu        $t5, $s1, $v0
        ctx->r13 = ADD32(ctx->r17, ctx->r2);
            goto L_800E5258;
    }
    goto skip_9;
    // 0x800E5230: addu        $t5, $s1, $v0
    ctx->r13 = ADD32(ctx->r17, ctx->r2);
    skip_9:
    // 0x800E5234: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E5238: jal         0x8001311C
    // 0x800E523C: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_5;
    // 0x800E523C: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_5:
    // 0x800E5240: lw          $t4, 0x30($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X30);
    // 0x800E5244: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5248: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E524C: addiu       $t0, $t4, 0x1800
    ctx->r8 = ADD32(ctx->r12, 0X1800);
    // 0x800E5250: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x800E5254: addu        $t5, $s1, $v0
    ctx->r13 = ADD32(ctx->r17, ctx->r2);
L_800E5258:
    // 0x800E5258: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800E525C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800E5260: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800E5264: sllv        $t7, $t6, $s2
    ctx->r15 = S32(ctx->r14 << (ctx->r18 & 31));
    // 0x800E5268: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E526C: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E5270: bne         $at, $zero, L_800E5220
    if (ctx->r1 != 0) {
        // 0x800E5274: or          $s4, $s4, $t7
        ctx->r20 = ctx->r20 | ctx->r15;
            goto L_800E5220;
    }
    // 0x800E5274: or          $s4, $s4, $t7
    ctx->r20 = ctx->r20 | ctx->r15;
L_800E5278:
    // 0x800E5278: sll         $t2, $s3, 1
    ctx->r10 = S32(ctx->r19 << 1);
    // 0x800E527C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800E5280: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800E5284: lhu         $t3, 0x32C0($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X32C0);
    // 0x800E5288: lhu         $t8, 0x4($s6)
    ctx->r24 = MEM_HU(ctx->r22, 0X4);
    // 0x800E528C: andi        $a1, $s7, 0x3
    ctx->r5 = ctx->r23 & 0X3;
    // 0x800E5290: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800E5294: and         $t4, $t3, $s4
    ctx->r12 = ctx->r11 & ctx->r20;
    // 0x800E5298: subu        $t1, $fp, $t8
    ctx->r9 = SUB32(ctx->r30, ctx->r24);
    // 0x800E529C: subu        $v1, $t1, $t4
    ctx->r3 = SUB32(ctx->r9, ctx->r12);
    // 0x800E52A0: srlv        $s4, $s4, $s3
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r19 & 31));
    // 0x800E52A4: beq         $a1, $zero, L_800E52E0
    if (ctx->r5 == 0) {
        // 0x800E52A8: subu        $s2, $s2, $s3
        ctx->r18 = SUB32(ctx->r18, ctx->r19);
            goto L_800E52E0;
    }
    // 0x800E52A8: subu        $s2, $s2, $s3
    ctx->r18 = SUB32(ctx->r18, ctx->r19);
    // 0x800E52AC: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800E52B0: addu        $a0, $a1, $s7
    ctx->r4 = ADD32(ctx->r5, ctx->r23);
    // 0x800E52B4: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
L_800E52B8:
    // 0x800E52B8: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x800E52BC: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x800E52C0: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800E52C4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800E52C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E52CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E52D0: bne         $a0, $s7, L_800E52B8
    if (ctx->r4 != ctx->r23) {
        // 0x800E52D4: sb          $t5, -0x1($s5)
        MEM_B(-0X1, ctx->r21) = ctx->r13;
            goto L_800E52B8;
    }
    // 0x800E52D4: sb          $t5, -0x1($s5)
    MEM_B(-0X1, ctx->r21) = ctx->r13;
    // 0x800E52D8: beql        $s7, $zero, L_800E5320
    if (ctx->r23 == 0) {
        // 0x800E52DC: lw          $t1, 0x4C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X4C);
            goto L_800E5320;
    }
    goto skip_10;
    // 0x800E52DC: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    skip_10:
L_800E52E0:
    // 0x800E52E0: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800E52E4: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
L_800E52E8:
    // 0x800E52E8: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800E52EC: addiu       $s7, $s7, -0x4
    ctx->r23 = ADD32(ctx->r23, -0X4);
    // 0x800E52F0: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800E52F4: sb          $t7, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r15;
    // 0x800E52F8: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x800E52FC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800E5300: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800E5304: sb          $t9, -0x3($s5)
    MEM_B(-0X3, ctx->r21) = ctx->r25;
    // 0x800E5308: lbu         $t8, -0x2($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X2);
    // 0x800E530C: sb          $t8, -0x2($s5)
    MEM_B(-0X2, ctx->r21) = ctx->r24;
    // 0x800E5310: lbu         $t2, -0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, -0X1);
    // 0x800E5314: bne         $s7, $zero, L_800E52E8
    if (ctx->r23 != 0) {
        // 0x800E5318: sb          $t2, -0x1($s5)
        MEM_B(-0X1, ctx->r21) = ctx->r10;
            goto L_800E52E8;
    }
    // 0x800E5318: sb          $t2, -0x1($s5)
    MEM_B(-0X1, ctx->r21) = ctx->r10;
L_800E531C:
    // 0x800E531C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
L_800E5320:
    // 0x800E5320: lh          $t3, 0x3C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X3C);
    // 0x800E5324: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x800E5328: slt         $v0, $t3, $t1
    ctx->r2 = SIGNED(ctx->r11) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800E532C: beq         $v0, $zero, L_800E5348
    if (ctx->r2 == 0) {
        // 0x800E5330: sw          $t4, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r12;
            goto L_800E5348;
    }
    // 0x800E5330: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800E5334: sw          $fp, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r30;
    // 0x800E5338: sw          $s4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r20;
    // 0x800E533C: sw          $s2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r18;
    // 0x800E5340: b           L_800E5360
    // 0x800E5344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800E5360;
    // 0x800E5344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E5348:
    // 0x800E5348: b           L_800E4EDC
    // 0x800E534C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
        goto L_800E4EDC;
    // 0x800E534C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
L_800E5350:
    // 0x800E5350: sw          $fp, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r30;
    // 0x800E5354: sw          $s4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r20;
    // 0x800E5358: sw          $s2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r18;
    // 0x800E535C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E5360:
    // 0x800E5360: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800E5364: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E5368: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800E536C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800E5370: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800E5374: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800E5378: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800E537C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800E5380: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800E5384: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800E5388: jr          $ra
    // 0x800E538C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800E538C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80801EF0_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801EF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801EF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801EFC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801F00: jal         0x80801E80
    // 0x80801F04: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80801E80_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x80801F04: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80801F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801F10: jr          $ra
    // 0x80801F14: nop

    return;
    // 0x80801F14: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080044C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800450: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800454: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800458: jal         0x8009E74C
    // 0x8080045C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8009E74C(rdram, ctx);
        goto after_0;
    // 0x8080045C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x80800460: bne         $v0, $zero, L_808004B8
    if (ctx->r2 != 0) {
        // 0x80800464: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004B8;
    }
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800468: jal         0x808000C8
    // 0x8080046C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808000C8_bstrexsmall(rdram, ctx);
        goto after_1;
    // 0x8080046C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800470: jal         0x8009EF60
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_2;
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: jal         0x80092864
    // 0x80800480: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_3;
    // 0x80800480: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x80800484: jal         0x8009E474
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_4;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080048C: jal         0x80095A40
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_5;
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x8009590C
    // 0x8080049C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009590C(rdram, ctx);
        goto after_6;
    // 0x8080049C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808004A0: jal         0x8009BC6C
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_7;
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004B0: jal         0x800947EC
    // 0x808004B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_8;
    // 0x808004B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
L_808004B8:
    // 0x808004B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004C4: jr          $ra
    // 0x808004C8: nop

    return;
    // 0x808004C8: nop

;}
RECOMP_FUNC void func_800B7A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7A98: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B7A9C: addiu       $v1, $v1, -0x7E80
    ctx->r3 = ADD32(ctx->r3, -0X7E80);
    // 0x800B7AA0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800B7AA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B7AA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B7AAC: addiu       $t9, $zero, -0x7FFF
    ctx->r25 = ADD32(0, -0X7FFF);
    // 0x800B7AB0: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    // 0x800B7AB4: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x800B7AB8: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // 0x800B7ABC: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x800B7AC0: sb          $zero, 0x13($v1)
    MEM_B(0X13, ctx->r3) = 0;
    // 0x800B7AC4: sb          $zero, 0x10($v1)
    MEM_B(0X10, ctx->r3) = 0;
    // 0x800B7AC8: sb          $zero, 0x12($v1)
    MEM_B(0X12, ctx->r3) = 0;
    // 0x800B7ACC: sb          $zero, 0x11($v1)
    MEM_B(0X11, ctx->r3) = 0;
    // 0x800B7AD0: sh          $t9, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r25;
    // 0x800B7AD4: jr          $ra
    // 0x800B7AD8: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    return;
    // 0x800B7AD8: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
;}
RECOMP_FUNC void _chfiregen_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869C0: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x800869C0);
    return;
    // 0x800869C4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800B2400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2400: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B2404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2408: lhu         $a2, 0x16($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0X16);
    // 0x800B240C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800B2410: srl         $t6, $a2, 1
    ctx->r14 = S32(U32(ctx->r6) >> 1);
    // 0x800B2414: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800B2418: beq         $a1, $zero, L_800B2428
    if (ctx->r5 == 0) {
        // 0x800B241C: addiu       $a2, $t7, 0x18
        ctx->r6 = ADD32(ctx->r15, 0X18);
            goto L_800B2428;
    }
    // 0x800B241C: addiu       $a2, $t7, 0x18
    ctx->r6 = ADD32(ctx->r15, 0X18);
    // 0x800B2420: b           L_800B242C
    // 0x800B2424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800B242C;
    // 0x800B2424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800B2428:
    // 0x800B2428: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800B242C:
    // 0x800B242C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B2430: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x800B2434: jal         0x8001ACEC
    // 0x800B2438: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    heap_alloc_sided(rdram, ctx);
        goto after_0;
    // 0x800B2438: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x800B243C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800B2440: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800B2444: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800B2448: jal         0x8001BBC8
    // 0x800B244C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    aligned4_memcpy(rdram, ctx);
        goto after_1;
    // 0x800B244C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800B2450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2454: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2458: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B245C: jr          $ra
    // 0x800B2460: nop

    return;
    // 0x800B2460: nop

;}
RECOMP_FUNC void func_80800038_gztrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x8080003C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800040: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800044: beq         $v0, $zero, L_80800060
    if (ctx->r2 == 0) {
        // 0x80800048: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_80800060;
    }
    // 0x80800048: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_8080004C:
    // 0x8080004C: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80800050: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80800054: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800058: bne         $v0, $zero, L_8080004C
    if (ctx->r2 != 0) {
        // 0x8080005C: sb          $v0, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = ctx->r2;
            goto L_8080004C;
    }
    // 0x8080005C: sb          $v0, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r2;
L_80800060:
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_800F4D18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4D18: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F4D1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4D20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F4D24: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F4D28: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F4D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4D30: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F4D34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800F4D38: jal         0x800A3048
    // 0x800F4D3C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800A3048(rdram, ctx);
        goto after_0;
    // 0x800F4D3C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F4D40: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800F4D44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F4D48: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F4D4C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800F4D50: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F4D54: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800F4D58: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800F4D5C: jal         0x8009F678
    // 0x800F4D60: nop

    func_8009F678(rdram, ctx);
        goto after_1;
    // 0x800F4D60: nop

    after_1:
    // 0x800F4D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4D68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F4D6C: jr          $ra
    // 0x800F4D70: nop

    return;
    // 0x800F4D70: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087CC8: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087CC8);
    return;
    // 0x80087CCC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void subaddiedraw25d_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800010: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800014: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80800024: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800028: jal         0x80103AE4
    // 0x8080002C: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    func_80103AE4(rdram, ctx);
        goto after_0;
    // 0x8080002C: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800030: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800034: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800038: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8080003C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800040: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80800044: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80800048: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8080004C: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800050: jal         0x800EFA4C
    // 0x80800054: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x80800054: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    after_1:
    // 0x80800058: lhu         $t6, 0x78($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X78);
    // 0x8080005C: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80800060: beq         $t7, $zero, L_80800080
    if (ctx->r15 == 0) {
        // 0x80800064: nop
    
            goto L_80800080;
    }
    // 0x80800064: nop

    // 0x80800068: jal         0x800E257C
    // 0x8080006C: lbu         $a0, 0x9B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9B);
    func_800E257C(rdram, ctx);
        goto after_2;
    // 0x8080006C: lbu         $a0, 0x9B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X9B);
    after_2:
    // 0x80800070: jal         0x800E2588
    // 0x80800074: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_3;
    // 0x80800074: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800078: b           L_808000B0
    // 0x8080007C: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
        goto L_808000B0;
    // 0x8080007C: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
L_80800080:
    // 0x80800080: jal         0x800AF5A8
    // 0x80800084: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800AF5A8(rdram, ctx);
        goto after_4;
    // 0x80800084: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x80800088: andi        $t8, $v0, 0xB00
    ctx->r24 = ctx->r2 & 0XB00;
    // 0x8080008C: beq         $t8, $zero, L_808000A4
    if (ctx->r24 == 0) {
        // 0x80800090: nop
    
            goto L_808000A4;
    }
    // 0x80800090: nop

    // 0x80800094: jal         0x800E2588
    // 0x80800098: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E2588(rdram, ctx);
        goto after_5;
    // 0x80800098: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8080009C: b           L_808000B0
    // 0x808000A0: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
        goto L_808000B0;
    // 0x808000A0: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
L_808000A4:
    // 0x808000A4: jal         0x800E2588
    // 0x808000A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800E2588(rdram, ctx);
        goto after_6;
    // 0x808000A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x808000AC: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
L_808000B0:
    // 0x808000B0: sll         $t1, $t9, 30
    ctx->r9 = S32(ctx->r25 << 30);
    // 0x808000B4: bgez        $t1, L_808000CC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808000B8: nop
    
            goto L_808000CC;
    }
    // 0x808000B8: nop

    // 0x808000BC: lbu         $a0, 0x98($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X98);
    // 0x808000C0: lbu         $a1, 0x99($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X99);
    // 0x808000C4: jal         0x800E24F8
    // 0x808000C8: lbu         $a2, 0x9A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9A);
    func_800E24F8(rdram, ctx);
        goto after_7;
    // 0x808000C8: lbu         $a2, 0x9A($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9A);
    after_7:
L_808000CC:
    // 0x808000CC: jal         0x8080024C
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    subaddiedraw25d_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808000D4: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x808000D8: addiu       $a0, $a0, -0x6400
    ctx->r4 = ADD32(ctx->r4, -0X6400);
    // 0x808000DC: jal         0x800E24E4
    // 0x808000E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E24E4(rdram, ctx);
        goto after_9;
    // 0x808000E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x808000E4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x808000E8: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x808000EC: addiu       $t7, $sp, 0x48
    ctx->r15 = ADD32(ctx->r29, 0X48);
    // 0x808000F0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x808000F4: addiu       $t8, $sp, 0x54
    ctx->r24 = ADD32(ctx->r29, 0X54);
    // 0x808000F8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x808000FC: lhu         $a2, 0xA($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0XA);
    // 0x80800100: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80800104: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80800108: srl         $t3, $a2, 11
    ctx->r11 = S32(U32(ctx->r6) >> 11);
    // 0x8080010C: sll         $t4, $a3, 26
    ctx->r12 = S32(ctx->r7 << 26);
    // 0x80800110: srl         $a3, $t4, 31
    ctx->r7 = S32(U32(ctx->r12) >> 31);
    // 0x80800114: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80800118: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8080011C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800120: jal         0x800E2C54
    // 0x80800124: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    func_800E2C54(rdram, ctx);
        goto after_10;
    // 0x80800124: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_10:
    // 0x80800128: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080012C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800130: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800134: jr          $ra
    // 0x80800138: nop

    return;
    // 0x80800138: nop

;}
RECOMP_FUNC void _bsbswim_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B58: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082B58);
    return;
    // 0x80082B5C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808003AC_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B4: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808003B8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808003BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808003C0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808003C4: bne         $t7, $at, L_808003E4
    if (ctx->r15 != ctx->r1) {
        // 0x808003C8: addiu       $a0, $a0, 0x58
        ctx->r4 = ADD32(ctx->r4, 0X58);
            goto L_808003E4;
    }
    // 0x808003C8: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    // 0x808003CC: jal         0x800D9078
    // 0x808003D0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x808003D0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x808003D4: beq         $v0, $zero, L_808003E4
    if (ctx->r2 == 0) {
        // 0x808003D8: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_808003E4;
    }
    // 0x808003D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808003DC: jal         0x8080034C
    // 0x808003E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8080034C_chnests(rdram, ctx);
        goto after_1;
    // 0x808003E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
L_808003E4:
    // 0x808003E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003EC: jr          $ra
    // 0x808003F0: nop

    return;
    // 0x808003F0: nop

;}
RECOMP_FUNC void func_80800000_rtlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lhu         $t6, 0xE($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XE);
    // 0x80800004: div         $zero, $a1, $t6
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r14)));
    // 0x80800008: mflo        $t7
    ctx->r15 = lo;
    // 0x8080000C: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x80800010: lhu         $t8, 0xE($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XE);
    // 0x80800014: lhu         $t0, 0xC($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0XC);
    // 0x80800018: bne         $t6, $zero, L_80800024
    if (ctx->r14 != 0) {
        // 0x8080001C: nop
    
            goto L_80800024;
    }
    // 0x8080001C: nop

    // 0x80800020: break       7
    do_break(2155872288);
L_80800024:
    // 0x80800024: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800028: bne         $t6, $at, L_8080003C
    if (ctx->r14 != ctx->r1) {
        // 0x8080002C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8080003C;
    }
    // 0x8080002C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800030: bne         $a1, $at, L_8080003C
    if (ctx->r5 != ctx->r1) {
        // 0x80800034: nop
    
            goto L_8080003C;
    }
    // 0x80800034: nop

    // 0x80800038: break       6
    do_break(2155872312);
L_8080003C:
    // 0x8080003C: div         $zero, $a1, $t8
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r24)));
    // 0x80800040: mfhi        $t9
    ctx->r25 = hi;
    // 0x80800044: bne         $t8, $zero, L_80800050
    if (ctx->r24 != 0) {
        // 0x80800048: nop
    
            goto L_80800050;
    }
    // 0x80800048: nop

    // 0x8080004C: break       7
    do_break(2155872332);
L_80800050:
    // 0x80800050: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800054: bne         $t8, $at, L_80800068
    if (ctx->r24 != ctx->r1) {
        // 0x80800058: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80800068;
    }
    // 0x80800058: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080005C: bne         $a1, $at, L_80800068
    if (ctx->r5 != ctx->r1) {
        // 0x80800060: nop
    
            goto L_80800068;
    }
    // 0x80800060: nop

    // 0x80800064: break       6
    do_break(2155872356);
L_80800068:
    // 0x80800068: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x8080006C: mflo        $t1
    ctx->r9 = lo;
    // 0x80800070: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x80800074: lhu         $t2, 0xE($a0)
    ctx->r10 = MEM_HU(ctx->r4, 0XE);
    // 0x80800078: lhu         $t4, 0xC($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0XC);
    // 0x8080007C: bne         $t0, $zero, L_80800088
    if (ctx->r8 != 0) {
        // 0x80800080: nop
    
            goto L_80800088;
    }
    // 0x80800080: nop

    // 0x80800084: break       7
    do_break(2155872388);
L_80800088:
    // 0x80800088: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080008C: bne         $t0, $at, L_808000A0
    if (ctx->r8 != ctx->r1) {
        // 0x80800090: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_808000A0;
    }
    // 0x80800090: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800094: bne         $t9, $at, L_808000A0
    if (ctx->r25 != ctx->r1) {
        // 0x80800098: nop
    
            goto L_808000A0;
    }
    // 0x80800098: nop

    // 0x8080009C: break       6
    do_break(2155872412);
L_808000A0:
    // 0x808000A0: div         $zero, $a1, $t2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r10)));
    // 0x808000A4: mfhi        $t3
    ctx->r11 = hi;
    // 0x808000A8: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x808000AC: bne         $t2, $zero, L_808000B8
    if (ctx->r10 != 0) {
        // 0x808000B0: nop
    
            goto L_808000B8;
    }
    // 0x808000B0: nop

    // 0x808000B4: break       7
    do_break(2155872436);
L_808000B8:
    // 0x808000B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808000BC: bne         $t2, $at, L_808000D0
    if (ctx->r10 != ctx->r1) {
        // 0x808000C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_808000D0;
    }
    // 0x808000C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808000C4: bne         $a1, $at, L_808000D0
    if (ctx->r5 != ctx->r1) {
        // 0x808000C8: nop
    
            goto L_808000D0;
    }
    // 0x808000C8: nop

    // 0x808000CC: break       6
    do_break(2155872460);
L_808000D0:
    // 0x808000D0: div         $zero, $t3, $t4
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r12)));
    // 0x808000D4: mfhi        $t5
    ctx->r13 = hi;
    // 0x808000D8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x808000DC: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x808000E0: bne         $t4, $zero, L_808000EC
    if (ctx->r12 != 0) {
        // 0x808000E4: nop
    
            goto L_808000EC;
    }
    // 0x808000E4: nop

    // 0x808000E8: break       7
    do_break(2155872488);
L_808000EC:
    // 0x808000EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808000F0: bne         $t4, $at, L_80800104
    if (ctx->r12 != ctx->r1) {
        // 0x808000F4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80800104;
    }
    // 0x808000F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808000F8: bne         $t3, $at, L_80800104
    if (ctx->r11 != ctx->r1) {
        // 0x808000FC: nop
    
            goto L_80800104;
    }
    // 0x808000FC: nop

    // 0x80800100: break       6
    do_break(2155872512);
L_80800104:
    // 0x80800104: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80800108: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8080010C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x80800110: lw          $t2, 0x8($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X8);
    // 0x80800114: or          $t6, $t5, $zero
    ctx->r14 = ctx->r13 | 0;
    // 0x80800118: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8080011C: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x80800120: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x80800124: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80800128: jr          $ra
    // 0x8080012C: sw          $t4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r12;
    return;
    // 0x8080012C: sw          $t4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r12;
;}
RECOMP_FUNC void _gclightsDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E98: syscall     660
    recomp_syscall_handler(rdram, ctx, 0x80087E98);
    return;
    // 0x80087E9C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chquiz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803948: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2484, 0X7480) << 16);
    // 0x8080394C: jr          $ra
    // 0x80803950: addiu       $v0, $v0, 0x7480
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2484, 0X7480));
    return;
    // 0x80803950: addiu       $v0, $v0, 0x7480
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2484, 0X7480));
;}
RECOMP_FUNC void _vpwibble_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089028: syscall     756
    recomp_syscall_handler(rdram, ctx, 0x80089028);
    return;
    // 0x8008902C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _ncpodfixpos_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800896A0: syscall     786
    recomp_syscall_handler(rdram, ctx, 0x800896A0);
    return;
    // 0x800896A4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800E00_chlagoonufoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800E08: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800E0C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800E10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E14: beq         $a1, $at, L_80800E30
    if (ctx->r5 == ctx->r1) {
        // 0x80800E18: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800E30;
    }
    // 0x80800E18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800E1C: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800E20: beq         $a1, $at, L_80800E44
    if (ctx->r5 == ctx->r1) {
        // 0x80800E24: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(748, 0X1B58) << 16);
            goto L_80800E44;
    }
    // 0x80800E24: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(748, 0X1B58) << 16);
    // 0x80800E28: b           L_80800E64
    // 0x80800E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E64;
    // 0x80800E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E30:
    // 0x80800E30: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800E34: jal         0x80102424
    // 0x80800E38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800E38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800E3C: b           L_80800E64
    // 0x80800E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E64;
    // 0x80800E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E44:
    // 0x80800E44: addiu       $a0, $a0, 0x1B58
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(748, 0X1B58));
    // 0x80800E48: jal         0x80088090
    // 0x80800E4C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800E4C: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_1:
    // 0x80800E50: b           L_80800E64
    // 0x80800E54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E64;
    // 0x80800E54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800E58: b           L_80800E64
    // 0x80800E5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E64;
    // 0x80800E5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800E60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E64:
    // 0x80800E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E6C: jr          $ra
    // 0x80800E70: nop

    return;
    // 0x80800E70: nop

;}
RECOMP_FUNC void func_80013FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013FE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80013FE8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80013FEC: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80013FF0: addiu       $s0, $s0, -0xC10
    ctx->r16 = ADD32(ctx->r16, -0XC10);
    // 0x80013FF4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80013FF8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80013FFC: addiu       $v0, $v0, -0x6FB0
    ctx->r2 = ADD32(ctx->r2, -0X6FB0);
    // 0x80014000: addiu       $t6, $t6, -0x6EE0
    ctx->r14 = ADD32(ctx->r14, -0X6EE0);
    // 0x80014004: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80014008: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8001400C: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x80014010: addiu       $t8, $t8, -0x47C0
    ctx->r24 = ADD32(ctx->r24, -0X47C0);
    // 0x80014014: addiu       $t9, $t9, 0x2F90
    ctx->r25 = ADD32(ctx->r25, 0X2F90);
    // 0x80014018: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001401C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80014020: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80014024: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x80014028: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x8001402C: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
    // 0x80014030: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80014034: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80014038: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x8001403C: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x80014040: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80014044: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80014048: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8001404C: sra         $t4, $t3, 3
    ctx->r12 = S32(SIGNED(ctx->r11) >> 3);
    // 0x80014050: sll         $a1, $t4, 3
    ctx->r5 = S32(ctx->r12 << 3);
    // 0x80014054: jal         0x8002E660
    // 0x80014058: sw          $a1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r5;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80014058: sw          $a1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r5;
    after_0:
    // 0x8001405C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80014060: jal         0x8002E660
    // 0x80014064: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x80014064: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x80014068: jal         0x8002F08C
    // 0x8001406C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_2;
    // 0x8001406C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80014070: jal         0x8002F1F4
    // 0x80014074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_3;
    // 0x80014074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80014078: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x8001407C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014080: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80014084: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80014088: sw          $t7, -0x7B74($at)
    MEM_W(-0X7B74, ctx->r1) = ctx->r15;
    // 0x8001408C: lw          $t8, 0x4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X4);
    // 0x80014090: addiu       $s0, $s0, -0x7B78
    ctx->r16 = ADD32(ctx->r16, -0X7B78);
    // 0x80014094: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80014098: jal         0x8002F240
    // 0x8001409C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    osDpGetStatus_recomp(rdram, ctx);
        goto after_4;
    // 0x8001409C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    after_4:
    // 0x800140A0: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x800140A4: bnel        $t0, $zero, L_800140C8
    if (ctx->r8 != 0) {
        // 0x800140A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800140C8;
    }
    goto skip_0;
    // 0x800140A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800140AC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800140B0: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800140B4: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x800140B8: sw          $t1, -0x7B7C($at)
    MEM_W(-0X7B7C, ctx->r1) = ctx->r9;
    // 0x800140BC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800140C0: sw          $t2, -0x70F0($at)
    MEM_W(-0X70F0, ctx->r1) = ctx->r10;
    // 0x800140C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800140C8:
    // 0x800140C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800140CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800140D0: jr          $ra
    // 0x800140D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800140D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bahold_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800214: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800218: lw          $t6, 0x9C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C);
    // 0x8080021C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800220: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
    // 0x80800224: lw          $t7, 0x9C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X9C);
    // 0x80800228: jr          $ra
    // 0x8080022C: swc1        $f14, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x8080022C: swc1        $f14, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80800C78_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C7C: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80800C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C84: beq         $a1, $at, L_80800D14
    if (ctx->r5 == ctx->r1) {
        // 0x80800C88: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800D14;
    }
    // 0x80800C88: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800C8C: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80800C90: beq         $a1, $at, L_80800D34
    if (ctx->r5 == ctx->r1) {
        // 0x80800C94: addiu       $at, $zero, 0x29
        ctx->r1 = ADD32(0, 0X29);
            goto L_80800D34;
    }
    // 0x80800C94: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80800C98: beq         $a1, $at, L_80800CF4
    if (ctx->r5 == ctx->r1) {
        // 0x80800C9C: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_80800CF4;
    }
    // 0x80800C9C: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80800CA0: beq         $a1, $at, L_80800D04
    if (ctx->r5 == ctx->r1) {
        // 0x80800CA4: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800D04;
    }
    // 0x80800CA4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800CA8: bne         $a1, $at, L_80800D60
    if (ctx->r5 != ctx->r1) {
        // 0x80800CAC: nop
    
            goto L_80800D60;
    }
    // 0x80800CAC: nop

    // 0x80800CB0: jal         0x80800B78
    // 0x80800CB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800B78_chhoneyb(rdram, ctx);
        goto after_0;
    // 0x80800CB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800CB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800CBC: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800CC0: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800CC4: addiu       $t8, $t7, -0x32
    ctx->r24 = ADD32(ctx->r15, -0X32);
    // 0x80800CC8: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800CCC: beq         $at, $zero, L_80800CE4
    if (ctx->r1 == 0) {
        // 0x80800CD0: nop
    
            goto L_80800CE4;
    }
    // 0x80800CD0: nop

    // 0x80800CD4: jal         0x80088848
    // 0x80800CD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800CD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800CDC: beq         $v0, $zero, L_80800D68
    if (ctx->r2 == 0) {
        // 0x80800CE0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800D68;
    }
    // 0x80800CE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800CE4:
    // 0x80800CE4: jal         0x800FFAB0
    // 0x80800CE8: nop

    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800CE8: nop

    after_2:
    // 0x80800CEC: b           L_80800D6C
    // 0x80800CF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D6C;
    // 0x80800CF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CF4:
    // 0x80800CF4: jal         0x8010DC50
    // 0x80800CF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8010DC50(rdram, ctx);
        goto after_3;
    // 0x80800CF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80800CFC: b           L_80800D6C
    // 0x80800D00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D6C;
    // 0x80800D00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D04:
    // 0x80800D04: jal         0x8010DCB4
    // 0x80800D08: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8010DCB4(rdram, ctx);
        goto after_4;
    // 0x80800D08: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80800D0C: b           L_80800D6C
    // 0x80800D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D6C;
    // 0x80800D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D14:
    // 0x80800D14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800D18: jal         0x8010DD20
    // 0x80800D1C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_8010DD20(rdram, ctx);
        goto after_5;
    // 0x80800D1C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800D20: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800D24: jal         0x800DF744
    // 0x80800D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_6;
    // 0x80800D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800D2C: b           L_80800D6C
    // 0x80800D30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D6C;
    // 0x80800D30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D34:
    // 0x80800D34: lhu         $t0, 0x76($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X76);
    // 0x80800D38: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800D3C: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x80800D40: addiu       $t2, $t1, -0x32
    ctx->r10 = ADD32(ctx->r9, -0X32);
    // 0x80800D44: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80800D48: bnel        $at, $zero, L_80800D6C
    if (ctx->r1 != 0) {
        // 0x80800D4C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800D6C;
    }
    goto skip_0;
    // 0x80800D4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800D50: jal         0x80089CA8
    // 0x80800D54: nop

    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80800D54: nop

    after_7:
    // 0x80800D58: b           L_80800D6C
    // 0x80800D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D6C;
    // 0x80800D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D60:
    // 0x80800D60: b           L_80800D6C
    // 0x80800D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D6C;
    // 0x80800D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D68:
    // 0x80800D68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D6C:
    // 0x80800D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D74: jr          $ra
    // 0x80800D78: nop

    return;
    // 0x80800D78: nop

;}
RECOMP_FUNC void func_80800094_chwitchyshockpadswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800098: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080009C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000A4: beq         $a1, $at, L_808000C0
    if (ctx->r5 == ctx->r1) {
        // 0x808000A8: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808000C0;
    }
    // 0x808000A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808000AC: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808000B0: beq         $a1, $at, L_808000EC
    if (ctx->r5 == ctx->r1) {
        // 0x808000B4: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_808000EC;
    }
    // 0x808000B4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808000B8: b           L_80800140
    // 0x808000BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_80800140;
    // 0x808000BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_808000C0:
    // 0x808000C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808000C4: jal         0x80108B04
    // 0x808000C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_0;
    // 0x808000C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000CC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808000D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000D4: addiu       $a2, $zero, 0x8B
    ctx->r6 = ADD32(0, 0X8B);
    // 0x808000D8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x808000DC: jal         0x80085708
    // 0x808000E0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808000E0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x808000E4: b           L_80800154
    // 0x808000E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800154;
    // 0x808000E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000EC:
    // 0x808000EC: lwc1        $f4, 0x24($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X24);
    // 0x808000F0: addiu       $a0, $zero, 0x210
    ctx->r4 = ADD32(0, 0X210);
    // 0x808000F4: addiu       $a1, $t7, 0x18
    ctx->r5 = ADD32(ctx->r15, 0X18);
    // 0x808000F8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808000FC: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x80800100: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800104: jal         0x80108528
    // 0x80800108: nop

    func_80108528(rdram, ctx);
        goto after_2;
    // 0x80800108: nop

    after_2:
    // 0x8080010C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80800110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800114: beql        $t9, $zero, L_80800154
    if (ctx->r25 == 0) {
        // 0x80800118: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800154;
    }
    goto skip_0;
    // 0x80800118: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080011C: jal         0x80089CA0
    // 0x80800120: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800120: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800124: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800128: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8080012C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800130: jal         0x800862D8
    // 0x80800134: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _chappearfx_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800134: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80800138: b           L_80800154
    // 0x8080013C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800154;
    // 0x8080013C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800140:
    // 0x80800140: jal         0x80085820
    // 0x80800144: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x80800144: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800148: b           L_80800158
    // 0x8080014C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800158;
    // 0x8080014C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800154:
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800158:
    // 0x80800158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

    // 0x80800164: nop

    // 0x80800168: nop

    // 0x8080016C: nop

;}
RECOMP_FUNC void func_80091EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091EA0: jr          $ra
    // 0x80091EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80091EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void _gclevel_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088238: syscall     676
    recomp_syscall_handler(rdram, ctx, 0x80088238);
    return;
    // 0x8008823C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800200_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800204: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800208: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080020C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800210: jal         0x800F54E4
    // 0x80800214: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800214: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800218: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080021C: jal         0x800F6438
    // 0x80800220: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x80800220: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800224: beql        $v0, $zero, L_808002AC
    if (ctx->r2 == 0) {
        // 0x80800228: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002AC;
    }
    goto skip_0;
    // 0x80800228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080022C: jal         0x800F6478
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6478(rdram, ctx);
        goto after_2;
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800234: beql        $v0, $zero, L_808002AC
    if (ctx->r2 == 0) {
        // 0x80800238: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002AC;
    }
    goto skip_1;
    // 0x80800238: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080023C: jal         0x8010C500
    // 0x80800240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010C500(rdram, ctx);
        goto after_3;
    // 0x80800240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800244: beq         $v0, $zero, L_808002A8
    if (ctx->r2 == 0) {
        // 0x80800248: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A8;
    }
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: jal         0x800F64A4
    // 0x80800250: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    func_800F64A4(rdram, ctx);
        goto after_4;
    // 0x80800250: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_4:
    // 0x80800254: bnel        $v0, $zero, L_808002AC
    if (ctx->r2 != 0) {
        // 0x80800258: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002AC;
    }
    goto skip_2;
    // 0x80800258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8080025C: jal         0x800F497C
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F497C(rdram, ctx);
        goto after_5;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800264: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80800268: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800270: jal         0x800F49D4
    // 0x80800274: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_6;
    // 0x80800274: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80800280: jal         0x800F4AC0
    // 0x80800284: lui         $a2, 0x432A
    ctx->r6 = S32(0X432A << 16);
    func_800F4AC0(rdram, ctx);
        goto after_7;
    // 0x80800284: lui         $a2, 0x432A
    ctx->r6 = S32(0X432A << 16);
    after_7:
    // 0x80800288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080028C: jal         0x8080082C
    // 0x80800290: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080082C_chmadamegrunty(rdram, ctx);
        goto after_8;
    // 0x80800290: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800294: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080029C: addiu       $a2, $zero, 0xAE
    ctx->r6 = ADD32(0, 0XAE);
    // 0x808002A0: jal         0x80085708
    // 0x808002A4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    _capod_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x808002A4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_9:
L_808002A8:
    // 0x808002A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002AC:
    // 0x808002AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002B4: jr          $ra
    // 0x808002B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808002B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
