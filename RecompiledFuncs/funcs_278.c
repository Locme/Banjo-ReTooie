#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800DF758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF758: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    // 0x800DF75C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800DF760: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF764: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DF768: sw          $t6, -0x37AC($at)
    MEM_W(-0X37AC, ctx->r1) = ctx->r14;
    // 0x800DF76C: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x800DF770: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF774: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF778: sw          $t7, -0x37A8($at)
    MEM_W(-0X37A8, ctx->r1) = ctx->r15;
    // 0x800DF77C: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x800DF780: addiu       $v0, $v0, -0x36C0
    ctx->r2 = ADD32(ctx->r2, -0X36C0);
    // 0x800DF784: addiu       $v1, $v1, -0x37A0
    ctx->r3 = ADD32(ctx->r3, -0X37A0);
    // 0x800DF788: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    // 0x800DF78C: sw          $t8, -0x37A4($at)
    MEM_W(-0X37A4, ctx->r1) = ctx->r24;
L_800DF790:
    // 0x800DF790: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800DF794: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800DF798: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800DF79C: sw          $t9, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r25;
    // 0x800DF7A0: lw          $t0, -0xC($a1)
    ctx->r8 = MEM_W(ctx->r5, -0XC);
    // 0x800DF7A4: sw          $t0, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r8;
    // 0x800DF7A8: lw          $t1, -0x8($a1)
    ctx->r9 = MEM_W(ctx->r5, -0X8);
    // 0x800DF7AC: sw          $t1, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r9;
    // 0x800DF7B0: lw          $t2, -0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, -0X4);
    // 0x800DF7B4: bne         $v1, $v0, L_800DF790
    if (ctx->r3 != ctx->r2) {
        // 0x800DF7B8: sw          $t2, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r10;
            goto L_800DF790;
    }
    // 0x800DF7B8: sw          $t2, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r10;
    // 0x800DF7BC: jr          $ra
    // 0x800DF7C0: nop

    return;
    // 0x800DF7C0: nop

;}
RECOMP_FUNC void _babackpack_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084510: syscall     113
    recomp_syscall_handler(rdram, ctx, 0x80084510);
    return;
    // 0x80084514: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808002FC_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800300: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800304: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800308: jal         0x800B53A4
    // 0x8080030C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x8080030C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x80800310: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800314: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800318: jal         0x80100094
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080031C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800320: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800324: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1748, 0X212C) << 16);
    // 0x80800328: addiu       $t6, $t6, 0x212C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1748, 0X212C));
    // 0x8080032C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800330: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800334: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800338: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8080033C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800340: jal         0x800BABB8
    // 0x80800344: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800344: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_2:
    // 0x80800348: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8080034C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800350: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800354: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800358: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080035C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800360: lwc1        $f12, 0x38($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X38);
    // 0x80800364: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80800368: lwc1        $f2, 0x1C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8080036C: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80800370: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80800374: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800378: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080037C: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80800380: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800384: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800388: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080038C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800390: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800394: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800398: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8080039C: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x808003A0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808003A4: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x808003A8: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x808003AC: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x808003B0: sll         $t5, $a3, 16
    ctx->r13 = S32(ctx->r7 << 16);
    // 0x808003B4: sll         $t1, $a2, 16
    ctx->r9 = S32(ctx->r6 << 16);
    // 0x808003B8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808003BC: sra         $a2, $t1, 16
    ctx->r6 = S32(SIGNED(ctx->r9) >> 16);
    // 0x808003C0: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    // 0x808003C4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808003C8: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x808003CC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808003D0: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x808003D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808003D8: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x808003DC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x808003E0: jal         0x800BA994
    // 0x808003E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_800BA994(rdram, ctx);
        goto after_3;
    // 0x808003E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_3:
    // 0x808003E8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003EC: jal         0x800BA22C
    // 0x808003F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800BA22C(rdram, ctx);
        goto after_4;
    // 0x808003F0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x808003F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003FC: jr          $ra
    // 0x80800400: nop

    return;
    // 0x80800400: nop

;}
RECOMP_FUNC void func_800E3B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3B54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E3B58: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E3B5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E3B60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3B64: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800E3B68: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3B6C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E3B70: jal         0x800CAA00
    // 0x800E3B74: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CAA00(rdram, ctx);
        goto after_0;
    // 0x800E3B74: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3B7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3B80: jr          $ra
    // 0x800E3B84: nop

    return;
    // 0x800E3B84: nop

;}
RECOMP_FUNC void func_808013C4_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808013D0: jal         0x80100094
    // 0x808013D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808013D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808013D8: addiu       $a0, $v0, 0x4DC
    ctx->r4 = ADD32(ctx->r2, 0X4DC);
    // 0x808013DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808013E0: jal         0x800899C8
    // 0x808013E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x808013E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x808013E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013F0: jr          $ra
    // 0x808013F4: nop

    return;
    // 0x808013F4: nop

;}
RECOMP_FUNC void bavan_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080008C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800090: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800094: lw          $t6, 0x144($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X144);
    // 0x80800098: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(634, 0X2F0) << 16);
    // 0x8080009C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A0: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x808000A4: lw          $t7, 0x144($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X144);
    // 0x808000A8: addiu       $a2, $a2, 0x2F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(634, 0X2F0));
    // 0x808000AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000B0: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x808000B4: lw          $t8, 0x144($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X144);
    // 0x808000B8: swc1        $f0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f0.u32l;
    // 0x808000BC: lw          $t9, 0x144($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X144);
    // 0x808000C0: jal         0x8009D454
    // 0x808000C4: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    func_8009D454(rdram, ctx);
        goto after_0;
    // 0x808000C4: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    after_0:
    // 0x808000C8: lw          $t0, 0x144($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X144);
    // 0x808000CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000D4: sb          $v0, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r2;
    // 0x808000D8: lw          $t1, 0x144($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X144);
    // 0x808000DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000E0: swc1        $f4, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f4.u32l;
    // 0x808000E4: lw          $t2, 0x144($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X144);
    // 0x808000E8: jal         0x800C368C
    // 0x808000EC: lbu         $a0, 0x10($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X10);
    func_800C368C(rdram, ctx);
        goto after_1;
    // 0x808000EC: lbu         $a0, 0x10($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X10);
    after_1:
    // 0x808000F0: lw          $t3, 0x144($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X144);
    // 0x808000F4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x808000F8: jal         0x800C334C
    // 0x808000FC: lbu         $a0, 0x10($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X10);
    func_800C334C(rdram, ctx);
        goto after_2;
    // 0x808000FC: lbu         $a0, 0x10($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X10);
    after_2:
    // 0x80800100: lw          $t4, 0x144($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X144);
    // 0x80800104: jal         0x800C3BDC
    // 0x80800108: lbu         $a0, 0x10($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X10);
    func_800C3BDC(rdram, ctx);
        goto after_3;
    // 0x80800108: lbu         $a0, 0x10($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X10);
    after_3:
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800110: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800114: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void func_80015410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80015414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015418: jal         0x800151BC
    // 0x8001541C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800151BC(rdram, ctx);
        goto after_0;
    // 0x8001541C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80015420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80015428: jr          $ra
    // 0x8001542C: nop

    return;
    // 0x8001542C: nop

;}
RECOMP_FUNC void bstimeout_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: lui         $a2, 0x404C
    ctx->r6 = S32(0X404C << 16);
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800018: jal         0x8008CCBC
    // 0x8080001C: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    after_0:
    // 0x80800020: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800024: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080002C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800030: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800034: jal         0x8009FFD8
    // 0x80800038: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800038: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_1:
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x8009B9B0
    // 0x80800044: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800044: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x800A4DA4
    // 0x80800050: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A4DA4(rdram, ctx);
        goto after_3;
    // 0x80800050: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x80800054: jal         0x8009F308
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F308(rdram, ctx);
        goto after_4;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080005C: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80800060: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8080006C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800070: jal         0x8009C914
    // 0x80800074: nop

    yaw_setIdeal(rdram, ctx);
        goto after_5;
    // 0x80800074: nop

    after_5:
    // 0x80800078: jal         0x800A4CA8
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_6;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800080: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800084: jal         0x80089288
    // 0x80800088: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    _ncbadie_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80800088: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    after_7:
    // 0x8080008C: jal         0x800FC6B0
    // 0x80800090: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_8;
    // 0x80800090: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_8:
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x800A0CF4
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_9;
    // 0x8080009C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808000A0: jal         0x8008E944
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_10;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808000A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000B4: jr          $ra
    // 0x808000B8: nop

    return;
    // 0x808000B8: nop

;}
RECOMP_FUNC void bashoessuck_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B8: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x808004BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004C0: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x808004C4: jal         0x80085020
    // 0x808004C8: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    _bashoes_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x808004C8: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808004CC: beq         $v0, $zero, L_808004DC
    if (ctx->r2 == 0) {
        // 0x808004D0: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808004DC;
    }
    // 0x808004D0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808004D4: b           L_80800718
    // 0x808004D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800718;
    // 0x808004D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004DC:
    // 0x808004DC: jal         0x8009BB24
    // 0x808004E0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_8009BB24(rdram, ctx);
        goto after_1;
    // 0x808004E0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_1:
    // 0x808004E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808004E8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x808004EC: jal         0x800EEFD4
    // 0x808004F0: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    func_800EEFD4(rdram, ctx);
        goto after_2;
    // 0x808004F0: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x808004F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004FC: nop

    // 0x80800500: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800504: nop

    // 0x80800508: bc1f        L_80800518
    if (!c1cs) {
        // 0x8080050C: nop
    
            goto L_80800518;
    }
    // 0x8080050C: nop

    // 0x80800510: b           L_80800718
    // 0x80800514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800718;
    // 0x80800514: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800518:
    // 0x80800518: jal         0x8009C984
    // 0x8080051C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    yaw_get(rdram, ctx);
        goto after_3;
    // 0x8080051C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_3:
    // 0x80800520: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(596, 0X800) << 16);
    // 0x80800524: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80800528: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(596, 0X800));
    // 0x8080052C: jal         0x800882A0
    // 0x80800530: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    _gccubesearch_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800530: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    after_4:
    // 0x80800534: bne         $v0, $zero, L_80800544
    if (ctx->r2 != 0) {
        // 0x80800538: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800544;
    }
    // 0x80800538: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080053C: b           L_80800718
    // 0x80800540: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800718;
    // 0x80800540: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800544:
    // 0x80800544: jal         0x80088C00
    // 0x80800548: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800548: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x8080054C: jal         0x80088498
    // 0x80800550: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    _glsplinefind_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800550: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x80800554: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800558: jal         0x800D7520
    // 0x8080055C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D7520(rdram, ctx);
        goto after_7;
    // 0x8080055C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80800560: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800564: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800568: jal         0x800C7A68
    // 0x8080056C: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    func_800C7A68(rdram, ctx);
        goto after_8;
    // 0x8080056C: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    after_8:
    // 0x80800570: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(596, 0X800) << 16);
    // 0x80800574: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(596, 0X800));
    // 0x80800578: jal         0x800882A0
    // 0x8080057C: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    _gccubesearch_entrypoint_5(rdram, ctx);
        goto after_9;
    // 0x8080057C: lw          $a1, 0x7C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X7C);
    after_9:
    // 0x80800580: bnel        $v0, $zero, L_80800594
    if (ctx->r2 != 0) {
        // 0x80800584: lhu         $v1, 0x8($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0X8);
            goto L_80800594;
    }
    goto skip_0;
    // 0x80800584: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    skip_0:
    // 0x80800588: b           L_80800718
    // 0x8080058C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800718;
    // 0x8080058C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800590: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
L_80800594:
    // 0x80800594: addiu       $at, $zero, 0x16B
    ctx->r1 = ADD32(0, 0X16B);
    // 0x80800598: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8080059C: beq         $v1, $at, L_808005B4
    if (ctx->r3 == ctx->r1) {
        // 0x808005A0: addiu       $at, $zero, 0x16C
        ctx->r1 = ADD32(0, 0X16C);
            goto L_808005B4;
    }
    // 0x808005A0: addiu       $at, $zero, 0x16C
    ctx->r1 = ADD32(0, 0X16C);
    // 0x808005A4: beq         $v1, $at, L_808005C4
    if (ctx->r3 == ctx->r1) {
        // 0x808005A8: lw          $a0, 0x78($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X78);
            goto L_808005C4;
    }
    // 0x808005A8: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808005AC: b           L_808005D0
    // 0x808005B0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
        goto L_808005D0;
    // 0x808005B0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_808005B4:
    // 0x808005B4: jal         0x80085030
    // 0x808005B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bashoes_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x808005B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808005BC: b           L_808005D0
    // 0x808005C0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
        goto L_808005D0;
    // 0x808005C0: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_808005C4:
    // 0x808005C4: jal         0x80085030
    // 0x808005C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bashoes_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x808005C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x808005CC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
L_808005D0:
    // 0x808005D0: jal         0x8009C128
    // 0x808005D4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_8009C128(rdram, ctx);
        goto after_12;
    // 0x808005D4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_12:
    // 0x808005D8: jal         0x800D7520
    // 0x808005DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800D7520(rdram, ctx);
        goto after_13;
    // 0x808005DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x808005E0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808005E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005E8: jal         0x800C82CC
    // 0x808005EC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800C82CC(rdram, ctx);
        goto after_14;
    // 0x808005EC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_14:
    // 0x808005F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005F4: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x808005F8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808005FC: jal         0x800C7A68
    // 0x80800600: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800C7A68(rdram, ctx);
        goto after_15;
    // 0x80800600: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_15:
    // 0x80800604: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800608: jal         0x800EEB40
    // 0x8080060C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EEB40(rdram, ctx);
        goto after_16;
    // 0x8080060C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_16:
    // 0x80800610: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(596, 0X738) << 16);
    // 0x80800614: lwc1        $f8, 0x738($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(596, 0X738));
    // 0x80800618: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8080061C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800620: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800624: nop

    // 0x80800628: bc1f        L_8080065C
    if (!c1cs) {
        // 0x8080062C: nop
    
            goto L_8080065C;
    }
    // 0x8080062C: nop

    // 0x80800630: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800634: jal         0x8009B800
    // 0x80800638: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baphysics_set_type(rdram, ctx);
        goto after_17;
    // 0x80800638: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_17:
    // 0x8080063C: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800640: jal         0x80084EB0
    // 0x80800644: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _bamovespline_entrypoint_7(rdram, ctx);
        goto after_18;
    // 0x80800644: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_18:
    // 0x80800648: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x8080064C: jal         0x80084EC0
    // 0x80800650: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    _bamovespline_entrypoint_9(rdram, ctx);
        goto after_19;
    // 0x80800650: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_19:
    // 0x80800654: b           L_80800718
    // 0x80800658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800718;
    // 0x80800658: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080065C:
    // 0x8080065C: jal         0x800F1E6C
    // 0x80800660: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_800F1E6C(rdram, ctx);
        goto after_20;
    // 0x80800660: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_20:
    // 0x80800664: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800668: jal         0x800F1DCC
    // 0x8080066C: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    func_800F1DCC(rdram, ctx);
        goto after_21;
    // 0x8080066C: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    after_21:
    // 0x80800670: jal         0x800F2100
    // 0x80800674: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_22;
    // 0x80800674: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_22:
    // 0x80800678: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8080067C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800680: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800684: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800688: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8080068C: nop

    // 0x80800690: bc1fl       L_808006A4
    if (!c1cs) {
        // 0x80800694: sub.s       $f12, $f16, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
            goto L_808006A4;
    }
    goto skip_1;
    // 0x80800694: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    skip_1:
    // 0x80800698: b           L_80800718
    // 0x8080069C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800718;
    // 0x8080069C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808006A0: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
L_808006A4:
    // 0x808006A4: jal         0x800F2100
    // 0x808006A8: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    mlAbsF(rdram, ctx);
        goto after_23;
    // 0x808006A8: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    after_23:
    // 0x808006AC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x808006B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006B4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808006B8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808006BC: nop

    // 0x808006C0: bc1f        L_808006D0
    if (!c1cs) {
        // 0x808006C4: nop
    
            goto L_808006D0;
    }
    // 0x808006C4: nop

    // 0x808006C8: b           L_80800718
    // 0x808006CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800718;
    // 0x808006CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006D0:
    // 0x808006D0: jal         0x800EFB8C
    // 0x808006D4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EFB8C(rdram, ctx);
        goto after_24;
    // 0x808006D4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_24:
    // 0x808006D8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x808006DC: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x808006E0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808006E4: nop

    // 0x808006E8: bc1f        L_808006F8
    if (!c1cs) {
        // 0x808006EC: nop
    
            goto L_808006F8;
    }
    // 0x808006EC: nop

    // 0x808006F0: b           L_80800718
    // 0x808006F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800718;
    // 0x808006F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808006F8:
    // 0x808006F8: jal         0x8009B800
    // 0x808006FC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baphysics_set_type(rdram, ctx);
        goto after_25;
    // 0x808006FC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_25:
    // 0x80800700: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    // 0x80800704: jal         0x80084EB0
    // 0x80800708: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _bamovespline_entrypoint_7(rdram, ctx);
        goto after_26;
    // 0x80800708: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_26:
    // 0x8080070C: jal         0x80084EB8
    // 0x80800710: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    _bamovespline_entrypoint_8(rdram, ctx);
        goto after_27;
    // 0x80800710: lw          $a0, 0x78($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X78);
    after_27:
    // 0x80800714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800718:
    // 0x80800718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080071C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80800720: jr          $ra
    // 0x80800724: nop

    return;
    // 0x80800724: nop

    // 0x80800728: nop

    // 0x8080072C: nop

;}
RECOMP_FUNC void ncbasub_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80800048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080004C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800050: jal         0x80110840
    // 0x80800054: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80110840(rdram, ctx);
        goto after_0;
    // 0x80800054: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800058: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8080005C: jal         0x800F5E7C
    // 0x80800060: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5E7C(rdram, ctx);
        goto after_1;
    // 0x80800060: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800064: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800068: jal         0x800F5F7C
    // 0x8080006C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_800F5F7C(rdram, ctx);
        goto after_2;
    // 0x8080006C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_2:
    // 0x80800070: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800074: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800078: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080007C: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800080: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x8080008C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800090: nop

    // 0x80800094: bc1f        L_808000A0
    if (!c1cs) {
        // 0x80800098: nop
    
            goto L_808000A0;
    }
    // 0x80800098: nop

    // 0x8080009C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_808000A0:
    // 0x808000A0: jal         0x80112524
    // 0x808000A4: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    func_80112524(rdram, ctx);
        goto after_3;
    // 0x808000A4: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    after_3:
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x801107F0
    // 0x808000B0: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_801107F0(rdram, ctx);
        goto after_4;
    // 0x808000B0: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_4:
    // 0x808000B4: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x808000B8: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x808000BC: jal         0x800EFB24
    // 0x808000C0: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x808000C0: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    after_5:
    // 0x808000C4: jal         0x800EEF94
    // 0x808000C8: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    func_800EEF94(rdram, ctx);
        goto after_6;
    // 0x808000C8: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_6:
    // 0x808000CC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x808000D0: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x808000D4: jal         0x800F1A88
    // 0x808000D8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    func_800F1A88(rdram, ctx);
        goto after_7;
    // 0x808000D8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    after_7:
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000E4: jal         0x80113978
    // 0x808000E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80113978(rdram, ctx);
        goto after_8;
    // 0x808000E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x80115358
    // 0x808000F4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_80115358(rdram, ctx);
        goto after_9;
    // 0x808000F4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_9:
    // 0x808000F8: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x808000FC: jal         0x80110840
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110840(rdram, ctx);
        goto after_10;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800104: jal         0x800F53D0
    // 0x80800108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_11;
    // 0x80800108: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x8080010C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800114: jal         0x80110818
    // 0x80800118: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80110818(rdram, ctx);
        goto after_12;
    // 0x80800118: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_12:
    // 0x8080011C: jal         0x80084F00
    // 0x80800120: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    _bamovethrust_entrypoint_6(rdram, ctx);
        goto after_13;
    // 0x80800120: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_13:
    // 0x80800124: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800128: jal         0x8009BFCC
    // 0x8080012C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_8009BFCC(rdram, ctx);
        goto after_14;
    // 0x8080012C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_14:
    // 0x80800130: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800134: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800138: jal         0x800F1DCC
    // 0x8080013C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_15;
    // 0x8080013C: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_15:
    // 0x80800140: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800144: jal         0x8009C984
    // 0x80800148: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    yaw_get(rdram, ctx);
        goto after_16;
    // 0x80800148: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x8080014C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800150: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800154: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800158: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8080015C: jal         0x80013728
    // 0x80800160: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    func_80013728(rdram, ctx);
        goto after_17;
    // 0x80800160: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    after_17:
    // 0x80800164: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800168: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080016C: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800170: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800174: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800178: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8080017C: sub.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80800180: bc1f        L_80800194
    if (!c1cs) {
        // 0x80800184: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80800194;
    }
    // 0x80800184: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800188: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080018C: b           L_808001BC
    // 0x80800190: sub.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f0.fl;
        goto L_808001BC;
    // 0x80800190: sub.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f0.fl;
L_80800194:
    // 0x80800194: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80800198: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080019C: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x808001A0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808001A4: nop

    // 0x808001A8: bc1f        L_808001BC
    if (!c1cs) {
        // 0x808001AC: nop
    
            goto L_808001BC;
    }
    // 0x808001AC: nop

    // 0x808001B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001B4: nop

    // 0x808001B8: sub.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f0.fl;
L_808001BC:
    // 0x808001BC: jal         0x80013728
    // 0x808001C0: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    func_80013728(rdram, ctx);
        goto after_18;
    // 0x808001C0: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    after_18:
    // 0x808001C4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808001C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001CC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808001D0: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808001D4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x808001D8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808001E4: bc1f        L_808001F8
    if (!c1cs) {
        // 0x808001E8: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_808001F8;
    }
    // 0x808001E8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808001EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001F0: b           L_80800220
    // 0x808001F4: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
        goto L_80800220;
    // 0x808001F4: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
L_808001F8:
    // 0x808001F8: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x808001FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800200: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80800204: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800208: nop

    // 0x8080020C: bc1f        L_80800220
    if (!c1cs) {
        // 0x80800210: nop
    
            goto L_80800220;
    }
    // 0x80800210: nop

    // 0x80800214: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800218: nop

    // 0x8080021C: sub.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f0.fl;
L_80800220:
    // 0x80800220: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3114, 0X320) << 16);
    // 0x80800224: lwc1        $f4, 0x320($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3114, 0X320));
    // 0x80800228: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8080022C: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800230: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800234: nop

    // 0x80800238: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8080023C: bne         $t7, $zero, L_80800254
    if (ctx->r15 != 0) {
        // 0x80800240: sub.s       $f12, $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f6.fl;
            goto L_80800254;
    }
    // 0x80800240: sub.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80800244: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80800248: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8080024C: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800250: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
L_80800254:
    // 0x80800254: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80800258: jal         0x80115750
    // 0x8080025C: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    func_80115750(rdram, ctx);
        goto after_19;
    // 0x8080025C: swc1        $f12, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f12.u32l;
    after_19:
    // 0x80800260: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800268: jal         0x80112C3C
    // 0x8080026C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    func_80112C3C(rdram, ctx);
        goto after_20;
    // 0x8080026C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_20:
    // 0x80800270: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80800274: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x80800278: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8080027C: jal         0x800EEBF0
    // 0x80800280: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    func_800EEBF0(rdram, ctx);
        goto after_21;
    // 0x80800280: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    after_21:
    // 0x80800284: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80800288: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    // 0x8080028C: jal         0x800EE780
    // 0x80800290: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    func_800EE780(rdram, ctx);
        goto after_22;
    // 0x80800290: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_22:
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x80111CC8
    // 0x8080029C: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_80111CC8(rdram, ctx);
        goto after_23;
    // 0x8080029C: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_23:
    // 0x808002A0: beql        $v0, $zero, L_808002D4
    if (ctx->r2 == 0) {
        // 0x808002A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002D4;
    }
    goto skip_0;
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808002A8: jal         0x801138A0
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138A0(rdram, ctx);
        goto after_24;
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x808002B0: bne         $v0, $zero, L_808002C8
    if (ctx->r2 != 0) {
        // 0x808002B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002C8;
    }
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: jal         0x80115580
    // 0x808002BC: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    func_80115580(rdram, ctx);
        goto after_25;
    // 0x808002BC: addiu       $a1, $sp, 0x8C
    ctx->r5 = ADD32(ctx->r29, 0X8C);
    after_25:
    // 0x808002C0: beql        $v0, $zero, L_808002D4
    if (ctx->r2 == 0) {
        // 0x808002C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002D4;
    }
    goto skip_1;
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
L_808002C8:
    // 0x808002C8: jal         0x801138F4
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_26;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002D4:
    // 0x808002D4: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x808002D8: jal         0x80110A68
    // 0x808002DC: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    func_80110A68(rdram, ctx);
        goto after_27;
    // 0x808002DC: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    after_27:
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: jal         0x80110790
    // 0x808002E8: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_80110790(rdram, ctx);
        goto after_28;
    // 0x808002E8: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_28:
    // 0x808002EC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x808002F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002F4: beq         $t8, $zero, L_80800304
    if (ctx->r24 == 0) {
        // 0x808002F8: nop
    
            goto L_80800304;
    }
    // 0x808002F8: nop

    // 0x808002FC: b           L_80800304
    // 0x80800300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800304;
    // 0x80800300: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800304:
    // 0x80800304: jal         0x80115858
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80115858(rdram, ctx);
        goto after_29;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8080030C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800310: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800314: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x80800318: jr          $ra
    // 0x8080031C: nop

    return;
    // 0x8080031C: nop

;}
RECOMP_FUNC void _chwaspstatue_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087638: syscall     599
    recomp_syscall_handler(rdram, ctx, 0x80087638);
    return;
    // 0x8008763C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800018_bsstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lw          $t6, 0x164($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X164);
    // 0x8080001C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800020: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800024: bne         $at, $zero, L_80800030
    if (ctx->r1 != 0) {
        // 0x80800028: nop
    
            goto L_80800030;
    }
    // 0x80800028: nop

    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800030:
    // 0x80800030: jr          $ra
    // 0x80800034: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80800034: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void bastick_getZone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EF10: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8009EF14: jr          $ra
    // 0x8009EF18: lw          $v0, 0x3C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X3C);
    return;
    // 0x8009EF18: lw          $v0, 0x3C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X3C);
;}
RECOMP_FUNC void func_8080233C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080233C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802340: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802344: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802348: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080234C: jal         0x80102FDC
    // 0x80802350: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80802350: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_0:
    // 0x80802354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802358: jal         0x8010A828
    // 0x8080235C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8010A828(rdram, ctx);
        goto after_1;
    // 0x8080235C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80802360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802364: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802368: jal         0x80803DC8
    // 0x8080236C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80803DC8_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x8080236C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80802370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802374: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80802378: jal         0x808008C0
    // 0x8080237C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x8080237C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80802380: jal         0x80803E10
    // 0x80802384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803E10_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80802384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802388: jal         0x80804784
    // 0x8080238C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804784_chdiggerboss(rdram, ctx);
        goto after_5;
    // 0x8080238C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80802390: jal         0x80804C28
    // 0x80802394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804C28_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80802394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802398: jal         0x80807640
    // 0x8080239C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807640_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x8080239C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808023A0: jal         0x80807FD8
    // 0x808023A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80807FD8_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x808023A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808023A8: jal         0x808088AC
    // 0x808023AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808088AC_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x808023AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808023B0: jal         0x80808C64
    // 0x808023B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80808C64_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x808023B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808023B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023BC: jal         0x80108B04
    // 0x808023C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80108B04(rdram, ctx);
        goto after_11;
    // 0x808023C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_11:
    // 0x808023C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808023C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808023CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808023D0: jr          $ra
    // 0x808023D4: nop

    return;
    // 0x808023D4: nop

;}
RECOMP_FUNC void func_8080082C_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080082C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800834: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800838: lw          $a2, 0x28($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X28);
    // 0x8080083C: jal         0x80800898
    // 0x80800840: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800898_chnests(rdram, ctx);
        goto after_0;
    // 0x80800840: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800844: beq         $v0, $zero, L_80800888
    if (ctx->r2 == 0) {
        // 0x80800848: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800888;
    }
    // 0x80800848: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080084C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800850: jal         0x80101870
    // 0x80800854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80800854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800858: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080085C: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800860: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800864: bgezl       $t8, L_8080088C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800868: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080088C;
    }
    goto skip_0;
    // 0x80800868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080086C: lhu         $t9, 0x72($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X72);
    // 0x80800870: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800874: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x80800878: bnel        $t0, $at, L_8080088C
    if (ctx->r8 != ctx->r1) {
        // 0x8080087C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080088C;
    }
    goto skip_1;
    // 0x8080087C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800880: jal         0x80103110
    // 0x80800884: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x80800884: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_80800888:
    // 0x80800888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080088C:
    // 0x8080088C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800890: jr          $ra
    // 0x80800894: nop

    return;
    // 0x80800894: nop

;}
RECOMP_FUNC void _bskazstilt_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083758: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083758);
    return;
    // 0x8008375C: addi        $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void _bamum_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084F30: syscall     142
    recomp_syscall_handler(rdram, ctx, 0x80084F30);
    return;
    // 0x80084F34: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void bsblongleg_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D90: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800D94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D98: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800D9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800DA0: jal         0x8008CABC
    // 0x80800DA4: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800DA4: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    after_0:
    // 0x80800DA8: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800DAC: jal         0x808000C8
    // 0x80800DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C8_bsblongleg(rdram, ctx);
        goto after_1;
    // 0x80800DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800DB4: jal         0x80800064
    // 0x80800DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800064_bsblongleg(rdram, ctx);
        goto after_2;
    // 0x80800DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DC0: jal         0x8009BB24
    // 0x80800DC4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_8009BB24(rdram, ctx);
        goto after_3;
    // 0x80800DC4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_3:
    // 0x80800DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DCC: jal         0x80091A30
    // 0x80800DD0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_4;
    // 0x80800DD0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x80800DD4: beq         $v0, $zero, L_80800DFC
    if (ctx->r2 == 0) {
        // 0x80800DD8: lwc1        $f6, 0x40($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
            goto L_80800DFC;
    }
    // 0x80800DD8: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800DDC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800DE0: nop

    // 0x80800DE4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800DE8: nop

    // 0x80800DEC: bc1f        L_80800DFC
    if (!c1cs) {
        // 0x80800DF0: nop
    
            goto L_80800DFC;
    }
    // 0x80800DF0: nop

    // 0x80800DF4: jal         0x8009BC6C
    // 0x80800DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_5;
    // 0x80800DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80800DFC:
    // 0x80800DFC: jal         0x8009C150
    // 0x80800E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C150(rdram, ctx);
        goto after_6;
    // 0x80800E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800E04: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800E08: jal         0x80096364
    // 0x80800E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096364(rdram, ctx);
        goto after_7;
    // 0x80800E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800E10: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800E14: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x80800E18: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800E1C: sub.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80800E20: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800E24: beq         $v0, $zero, L_80800E58
    if (ctx->r2 == 0) {
        // 0x80800E28: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80800E58;
    }
    // 0x80800E28: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80800E2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E30: beq         $v0, $at, L_80800ED8
    if (ctx->r2 == ctx->r1) {
        // 0x80800E34: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80800ED8;
    }
    // 0x80800E34: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800E38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E3C: beq         $v0, $at, L_80800F44
    if (ctx->r2 == ctx->r1) {
        // 0x80800E40: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_80800F44;
    }
    // 0x80800E40: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800E44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800E48: beq         $v0, $at, L_80800FC8
    if (ctx->r2 == ctx->r1) {
        // 0x80800E4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FC8;
    }
    // 0x80800E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E50: b           L_80801018
    // 0x80800E54: nop

        goto L_80801018;
    // 0x80800E54: nop

L_80800E58:
    // 0x80800E58: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800E5C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800E60: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800E64: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800E68: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800E6C: bc1t        L_80800E8C
    if (c1cs) {
        // 0x80800E70: nop
    
            goto L_80800E8C;
    }
    // 0x80800E70: nop

    // 0x80800E74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800E78: nop

    // 0x80800E7C: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80800E80: nop

    // 0x80800E84: bc1f        L_80800E94
    if (!c1cs) {
        // 0x80800E88: nop
    
            goto L_80800E94;
    }
    // 0x80800E88: nop

L_80800E8C:
    // 0x80800E8C: jal         0x8008B1BC
    // 0x80800E90: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    anctrl_setDuration(rdram, ctx);
        goto after_8;
    // 0x80800E90: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_8:
L_80800E94:
    // 0x80800E94: jal         0x8008B324
    // 0x80800E98: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_isStopped(rdram, ctx);
        goto after_9;
    // 0x80800E98: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_9:
    // 0x80800E9C: beq         $v0, $zero, L_80801018
    if (ctx->r2 == 0) {
        // 0x80800EA0: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80801018;
    }
    // 0x80800EA0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800EA4: lui         $a2, 0x3F07
    ctx->r6 = S32(0X3F07 << 16);
    // 0x80800EA8: ori         $a2, $a2, 0x381D
    ctx->r6 = ctx->r6 | 0X381D;
    // 0x80800EAC: jal         0x8008B1D4
    // 0x80800EB0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_10;
    // 0x80800EB0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x80800EB4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800EB8: jal         0x8008B1BC
    // 0x80800EBC: lui         $a1, 0x4090
    ctx->r5 = S32(0X4090 << 16);
    anctrl_setDuration(rdram, ctx);
        goto after_11;
    // 0x80800EBC: lui         $a1, 0x4090
    ctx->r5 = S32(0X4090 << 16);
    after_11:
    // 0x80800EC0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800EC4: jal         0x8008B134
    // 0x80800EC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_12;
    // 0x80800EC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800ECC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800ED0: b           L_80801018
    // 0x80800ED4: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80801018;
    // 0x80800ED4: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800ED8:
    // 0x80800ED8: jal         0x8008B2B4
    // 0x80800EDC: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_13;
    // 0x80800EDC: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_13:
    // 0x80800EE0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(104, 0X1468) << 16);
    // 0x80800EE4: lwc1        $f4, 0x1468($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(104, 0X1468));
    // 0x80800EE8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800EEC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800EF0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800EF4: nop

    // 0x80800EF8: bc1f        L_80801018
    if (!c1cs) {
        // 0x80800EFC: nop
    
            goto L_80801018;
    }
    // 0x80800EFC: nop

    // 0x80800F00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800F04: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800F08: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80800F0C: nop

    // 0x80800F10: bc1f        L_80801018
    if (!c1cs) {
        // 0x80800F14: nop
    
            goto L_80801018;
    }
    // 0x80800F14: nop

    // 0x80800F18: jal         0x8008B2B4
    // 0x80800F1C: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_14;
    // 0x80800F1C: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_14:
    // 0x80800F20: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800F24: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800F28: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800F2C: swc1        $f12, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f12.u32l;
    // 0x80800F30: jal         0x8008B134
    // 0x80800F34: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_15;
    // 0x80800F34: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_15:
    // 0x80800F38: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800F3C: b           L_80801018
    // 0x80800F40: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_80801018;
    // 0x80800F40: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800F44:
    // 0x80800F44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(104, 0X146C) << 16);
    // 0x80800F48: lwc1        $f8, 0x146C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(104, 0X146C));
    // 0x80800F4C: lwc1        $f14, 0x170($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X170);
    // 0x80800F50: lw          $a3, 0x16C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X16C);
    // 0x80800F54: jal         0x800F10B4
    // 0x80800F58: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x80800F58: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x80800F5C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800F60: jal         0x8008B10C
    // 0x80800F64: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_8008B10C(rdram, ctx);
        goto after_17;
    // 0x80800F64: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_17:
    // 0x80800F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F70: jal         0x8009D2F0
    // 0x80800F74: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_18;
    // 0x80800F74: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_18:
    // 0x80800F78: jal         0x8008E078
    // 0x80800F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_19;
    // 0x80800F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800F80: beq         $v0, $zero, L_80801018
    if (ctx->r2 == 0) {
        // 0x80800F84: nop
    
            goto L_80801018;
    }
    // 0x80800F84: nop

    // 0x80800F88: jal         0x8009FE58
    // 0x80800F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_20;
    // 0x80800F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800F90: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800F94: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800F98: jal         0x8008B1D4
    // 0x80800F9C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_21;
    // 0x80800F9C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_21:
    // 0x80800FA0: lui         $a1, 0x3FA6
    ctx->r5 = S32(0X3FA6 << 16);
    // 0x80800FA4: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800FA8: jal         0x8008B1BC
    // 0x80800FAC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_setDuration(rdram, ctx);
        goto after_22;
    // 0x80800FAC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_22:
    // 0x80800FB0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800FB4: jal         0x8008B134
    // 0x80800FB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_23;
    // 0x80800FB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80800FBC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800FC0: b           L_80801018
    // 0x80800FC4: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_80801018;
    // 0x80800FC4: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_80800FC8:
    // 0x80800FC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800FCC: jal         0x8009D2F0
    // 0x80800FD0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_8009D2F0(rdram, ctx);
        goto after_24;
    // 0x80800FD0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_24:
    // 0x80800FD4: jal         0x8008B324
    // 0x80800FD8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    anctrl_isStopped(rdram, ctx);
        goto after_25;
    // 0x80800FD8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_25:
    // 0x80800FDC: beq         $v0, $zero, L_80800FEC
    if (ctx->r2 == 0) {
        // 0x80800FE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800FEC;
    }
    // 0x80800FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE4: addiu       $t9, $zero, 0x26
    ctx->r25 = ADD32(0, 0X26);
    // 0x80800FE8: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
L_80800FEC:
    // 0x80800FEC: jal         0x80091A58
    // 0x80800FF0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_26;
    // 0x80800FF0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_26:
    // 0x80800FF4: beq         $v0, $zero, L_80801004
    if (ctx->r2 == 0) {
        // 0x80800FF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801004;
    }
    // 0x80800FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FFC: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x80801000: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_80801004:
    // 0x80801004: jal         0x800915AC
    // 0x80801008: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_isDone(rdram, ctx);
        goto after_27;
    // 0x80801008: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_27:
    // 0x8080100C: beq         $v0, $zero, L_80801018
    if (ctx->r2 == 0) {
        // 0x80801010: addiu       $t1, $zero, 0x29
        ctx->r9 = ADD32(0, 0X29);
            goto L_80801018;
    }
    // 0x80801010: addiu       $t1, $zero, 0x29
    ctx->r9 = ADD32(0, 0X29);
    // 0x80801014: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_80801018:
    // 0x80801018: jal         0x80800000
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsblongleg(rdram, ctx);
        goto after_28;
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80801020: beq         $v0, $zero, L_80801030
    if (ctx->r2 == 0) {
        // 0x80801024: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801030;
    }
    // 0x80801024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801028: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x8080102C: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
L_80801030:
    // 0x80801030: jal         0x8009E5C8
    // 0x80801034: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    bs_setState(rdram, ctx);
        goto after_29;
    // 0x80801034: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_29:
    // 0x80801038: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080103C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801040: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801044: jr          $ra
    // 0x80801048: nop

    return;
    // 0x80801048: nop

;}
RECOMP_FUNC void func_80800000_gztrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800004: sltu        $at, $a0, $at
    ctx->r1 = ctx->r4 < ctx->r1 ? 1 : 0;
    // 0x80800008: bne         $at, $zero, L_80800028
    if (ctx->r1 != 0) {
        // 0x8080000C: lui         $at, 0x8080
        ctx->r1 = S32(0X8080 << 16);
            goto L_80800028;
    }
    // 0x8080000C: lui         $at, 0x8080
    ctx->r1 = S32(0X8080 << 16);
    // 0x80800010: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80800014: sltu        $at, $a0, $at
    ctx->r1 = ctx->r4 < ctx->r1 ? 1 : 0;
    // 0x80800018: beq         $at, $zero, L_80800028
    if (ctx->r1 == 0) {
        // 0x8080001C: andi        $t6, $a0, 0x3
        ctx->r14 = ctx->r4 & 0X3;
            goto L_80800028;
    }
    // 0x8080001C: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x80800020: beq         $t6, $zero, L_80800030
    if (ctx->r14 == 0) {
        // 0x80800024: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800030;
    }
    // 0x80800024: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800028:
    // 0x80800028: jr          $ra
    // 0x8080002C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8080002C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800030:
    // 0x80800030: jr          $ra
    // 0x80800034: nop

    return;
    // 0x80800034: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089788: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x80089788);
    return;
    // 0x8008978C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chhoneycarrier_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C78: syscall     438
    recomp_syscall_handler(rdram, ctx, 0x80086C78);
    return;
    // 0x80086C7C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800FABF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FABF4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800FABF8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800FABFC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800FAC00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FAC04: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800FAC08: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800FAC0C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800FAC10: jal         0x800EE7F8
    // 0x800FAC14: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800FAC14: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x800FAC18: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800FAC1C: jal         0x800EE7F8
    // 0x800FAC20: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800FAC20: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x800FAC24: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800FAC28: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FAC2C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800FAC30: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800FAC34: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800FAC38: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800FAC3C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800FAC40: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800FAC44: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x800FAC48: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800FAC4C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800FAC50: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x800FAC54: jal         0x800FAB50
    // 0x800FAC58: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800FAB50(rdram, ctx);
        goto after_2;
    // 0x800FAC58: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x800FAC5C: bne         $v0, $zero, L_800FAC6C
    if (ctx->r2 != 0) {
        // 0x800FAC60: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FAC6C;
    }
    // 0x800FAC60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FAC64: b           L_800FAC90
    // 0x800FAC68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FAC90;
    // 0x800FAC68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FAC6C:
    // 0x800FAC6C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800FAC70: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800FAC74: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800FAC78: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800FAC7C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800FAC80: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800FAC84: jal         0x800EE7F8
    // 0x800FAC88: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x800FAC88: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x800FAC8C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_800FAC90:
    // 0x800FAC90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FAC94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800FAC98: jr          $ra
    // 0x800FAC9C: nop

    return;
    // 0x800FAC9C: nop

;}
RECOMP_FUNC void _gcnewpause_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881F8: syscall     675
    recomp_syscall_handler(rdram, ctx, 0x800881F8);
    return;
    // 0x800881FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800408_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800408: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8080040C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800410: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80800414: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800418: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8080041C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800420: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800424: jal         0x80100094
    // 0x80800428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080042C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80800430: lhu         $v1, 0x72($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X72);
    // 0x80800434: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800438: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x8080043C: beq         $t6, $at, L_8080071C
    if (ctx->r14 == ctx->r1) {
        // 0x80800440: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080071C;
    }
    // 0x80800440: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800444: beq         $t6, $at, L_80800464
    if (ctx->r14 == ctx->r1) {
        // 0x80800448: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800464;
    }
    // 0x80800448: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080044C: beq         $t6, $at, L_808004EC
    if (ctx->r14 == ctx->r1) {
        // 0x80800450: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808004EC;
    }
    // 0x80800450: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800454: beq         $t6, $at, L_80800594
    if (ctx->r14 == ctx->r1) {
        // 0x80800458: nop
    
            goto L_80800594;
    }
    // 0x80800458: nop

    // 0x8080045C: b           L_80800720
    // 0x80800460: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800720;
    // 0x80800460: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800464:
    // 0x80800464: lw          $t7, 0x64($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X64);
    // 0x80800468: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080046C: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    // 0x80800470: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800474: bltz        $t9, L_80800490
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800478: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1192, 0X11C4) << 16);
            goto L_80800490;
    }
    // 0x80800478: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1192, 0X11C4) << 16);
    // 0x8080047C: jal         0x80089D18
    // 0x80800480: addiu       $a2, $a2, 0x11C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1192, 0X11C4));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800480: addiu       $a2, $a2, 0x11C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1192, 0X11C4));
    after_1:
    // 0x80800484: lbu         $t1, 0x65($s3)
    ctx->r9 = MEM_BU(ctx->r19, 0X65);
    // 0x80800488: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8080048C: sb          $t2, 0x65($s3)
    MEM_B(0X65, ctx->r19) = ctx->r10;
L_80800490:
    // 0x80800490: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800494: jal         0x8008A4C8
    // 0x80800498: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _subaddieDll_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800498: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_2:
    // 0x8080049C: jal         0x8008A030
    // 0x808004A0: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    _subaddielink_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808004A0: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_3:
    // 0x808004A4: beq         $v0, $zero, L_808004C0
    if (ctx->r2 == 0) {
        // 0x808004A8: nop
    
            goto L_808004C0;
    }
    // 0x808004A8: nop

    // 0x808004AC: jal         0x8008A040
    // 0x808004B0: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808004B0: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_4:
    // 0x808004B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004B8: jal         0x8008A4C8
    // 0x808004BC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _subaddieDll_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x808004BC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
L_808004C0:
    // 0x808004C0: jal         0x800D9078
    // 0x808004C4: addiu       $a0, $s3, 0x58
    ctx->r4 = ADD32(ctx->r19, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x808004C4: addiu       $a0, $s3, 0x58
    ctx->r4 = ADD32(ctx->r19, 0X58);
    after_6:
    // 0x808004C8: beql        $v0, $zero, L_80800720
    if (ctx->r2 == 0) {
        // 0x808004CC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800720;
    }
    goto skip_0;
    // 0x808004CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808004D0: jal         0x80800B9C
    // 0x808004D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80800B9C_chbilldrillplate(rdram, ctx);
        goto after_7;
    // 0x808004D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x808004D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808004DC: jal         0x80101FDC
    // 0x808004E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x808004E0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x808004E4: b           L_80800720
    // 0x808004E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800720;
    // 0x808004E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808004EC:
    // 0x808004EC: lw          $t3, 0x64($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X64);
    // 0x808004F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808004F4: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    // 0x808004F8: sll         $t5, $t3, 11
    ctx->r13 = S32(ctx->r11 << 11);
    // 0x808004FC: bltz        $t5, L_80800518
    if (SIGNED(ctx->r13) < 0) {
        // 0x80800500: lui         $a2, 0x8080
        ctx->r6 = S32(RELOC_HI16(1192, 0X11C4) << 16);
            goto L_80800518;
    }
    // 0x80800500: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1192, 0X11C4) << 16);
    // 0x80800504: jal         0x80089D18
    // 0x80800508: addiu       $a2, $a2, 0x11C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1192, 0X11C4));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800508: addiu       $a2, $a2, 0x11C4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1192, 0X11C4));
    after_9:
    // 0x8080050C: lbu         $t7, 0x65($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X65);
    // 0x80800510: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800514: sb          $t8, 0x65($s3)
    MEM_B(0X65, ctx->r19) = ctx->r24;
L_80800518:
    // 0x80800518: jal         0x800D9078
    // 0x8080051C: addiu       $a0, $s3, 0x30
    ctx->r4 = ADD32(ctx->r19, 0X30);
    func_800D9078(rdram, ctx);
        goto after_10;
    // 0x8080051C: addiu       $a0, $s3, 0x30
    ctx->r4 = ADD32(ctx->r19, 0X30);
    after_10:
    // 0x80800520: beq         $v0, $zero, L_80800538
    if (ctx->r2 == 0) {
        // 0x80800524: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800538;
    }
    // 0x80800524: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800528: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1192, 0X11D4) << 16);
    // 0x8080052C: addiu       $a2, $a2, 0x11D4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1192, 0X11D4));
    // 0x80800530: jal         0x80089D18
    // 0x80800534: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800534: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    after_11:
L_80800538:
    // 0x80800538: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080053C: jal         0x8008A4C8
    // 0x80800540: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _subaddieDll_entrypoint_7(rdram, ctx);
        goto after_12;
    // 0x80800540: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_12:
    // 0x80800544: jal         0x8008A030
    // 0x80800548: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    _subaddielink_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80800548: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_13:
    // 0x8080054C: beq         $v0, $zero, L_80800568
    if (ctx->r2 == 0) {
        // 0x80800550: nop
    
            goto L_80800568;
    }
    // 0x80800550: nop

    // 0x80800554: jal         0x8008A040
    // 0x80800558: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x80800558: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_14:
    // 0x8080055C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800560: jal         0x8008A4C8
    // 0x80800564: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _subaddieDll_entrypoint_7(rdram, ctx);
        goto after_15;
    // 0x80800564: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_15:
L_80800568:
    // 0x80800568: jal         0x800D9078
    // 0x8080056C: addiu       $a0, $s3, 0x58
    ctx->r4 = ADD32(ctx->r19, 0X58);
    func_800D9078(rdram, ctx);
        goto after_16;
    // 0x8080056C: addiu       $a0, $s3, 0x58
    ctx->r4 = ADD32(ctx->r19, 0X58);
    after_16:
    // 0x80800570: beq         $v0, $zero, L_8080071C
    if (ctx->r2 == 0) {
        // 0x80800574: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8080071C;
    }
    // 0x80800574: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800578: jal         0x80101FDC
    // 0x8080057C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_17;
    // 0x8080057C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800580: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800584: jal         0x80103110
    // 0x80800588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_18;
    // 0x80800588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x8080058C: b           L_80800720
    // 0x80800590: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800720;
    // 0x80800590: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800594:
    // 0x80800594: jal         0x800D8FF8
    // 0x80800598: nop

    func_800D8FF8(rdram, ctx);
        goto after_19;
    // 0x80800598: nop

    after_19:
    // 0x8080059C: lwc1        $f2, 0x34($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X34);
    // 0x808005A0: lwc1        $f4, 0x8($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X8);
    // 0x808005A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1192, 0X1088) << 16);
    // 0x808005A8: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x808005AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808005B0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x808005B4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808005B8: swc1        $f8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f8.u32l;
    // 0x808005BC: lwc1        $f10, 0x1088($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1192, 0X1088));
    // 0x808005C0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x808005C4: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x808005C8: swc1        $f18, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->f18.u32l;
    // 0x808005CC: lwc1        $f4, 0x34($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X34);
    // 0x808005D0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808005D4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808005D8: jal         0x80800C98
    // 0x808005DC: nop

    func_80800C98_chbilldrillplate(rdram, ctx);
        goto after_20;
    // 0x808005DC: nop

    after_20:
    // 0x808005E0: lwc1        $f8, 0x8($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X8);
    // 0x808005E4: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808005E8: addiu       $s2, $s3, 0x4
    ctx->r18 = ADD32(ctx->r19, 0X4);
    // 0x808005EC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1192, 0X11E0) << 16);
    // 0x808005F0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x808005F4: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808005F8: addiu       $a2, $a2, 0x11E0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1192, 0X11E0));
    // 0x808005FC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800600: bc1f        L_808006E8
    if (!c1cs) {
        // 0x80800604: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808006E8;
    }
    // 0x80800604: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800608: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080060C: swc1        $f10, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f10.u32l;
    // 0x80800610: jal         0x80089D18
    // 0x80800614: swc1        $f16, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->f16.u32l;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x80800614: swc1        $f16, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->f16.u32l;
    after_21:
    // 0x80800618: jal         0x800B53A4
    // 0x8080061C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B53A4(rdram, ctx);
        goto after_22;
    // 0x8080061C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_22:
    // 0x80800620: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800624: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800628: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800630:
    // 0x80800630: jal         0x800EE7F8
    // 0x80800634: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_23;
    // 0x80800634: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_23:
    // 0x80800638: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080063C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800640: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800644: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800648: jal         0x800DC178
    // 0x8080064C: nop

    func_800DC178(rdram, ctx);
        goto after_24;
    // 0x8080064C: nop

    after_24:
    // 0x80800650: mtc1        $s1, $f18
    ctx->f18.u32l = ctx->r17;
    // 0x80800654: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800658: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080065C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800660: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800668: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080066C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800670: jal         0x800EF1B8
    // 0x80800674: nop

    func_800EF1B8(rdram, ctx);
        goto after_25;
    // 0x80800674: nop

    after_25:
    // 0x80800678: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1192, 0X11F0) << 16);
    // 0x8080067C: addiu       $t9, $t9, 0x11F0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1192, 0X11F0));
    // 0x80800680: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800684: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80800688: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080068C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800690: jal         0x800BABB8
    // 0x80800694: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    func_800BABB8(rdram, ctx);
        goto after_26;
    // 0x80800694: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    after_26:
    // 0x80800698: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080069C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808006A0: bnel        $s1, $at, L_80800630
    if (ctx->r17 != ctx->r1) {
        // 0x808006A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800630;
    }
    goto skip_1;
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808006A8: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x808006AC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808006B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808006B4: jal         0x800E15CC
    // 0x808006B8: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_27;
    // 0x808006B8: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_27:
    // 0x808006BC: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x808006C0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808006C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808006C8: jal         0x80018820
    // 0x808006CC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80018820(rdram, ctx);
        goto after_28;
    // 0x808006CC: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_28:
    // 0x808006D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808006D4: jal         0x80101FDC
    // 0x808006D8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_29;
    // 0x808006D8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_29:
    // 0x808006DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808006E0: jal         0x80103110
    // 0x808006E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_30;
    // 0x808006E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_30:
L_808006E8:
    // 0x808006E8: jal         0x8008A030
    // 0x808006EC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    _subaddielink_entrypoint_2(rdram, ctx);
        goto after_31;
    // 0x808006EC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_31:
    // 0x808006F0: beql        $v0, $zero, L_80800720
    if (ctx->r2 == 0) {
        // 0x808006F4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800720;
    }
    goto skip_2;
    // 0x808006F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x808006F8: jal         0x8008A040
    // 0x808006FC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_32;
    // 0x808006FC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_32:
    // 0x80800700: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80800704: lwc1        $f10, 0x8($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80800708: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080070C: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80800710: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800714: jal         0x80103014
    // 0x80800718: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    func_80103014(rdram, ctx);
        goto after_33;
    // 0x80800718: swc1        $f18, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f18.u32l;
    after_33:
L_8080071C:
    // 0x8080071C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800720:
    // 0x80800720: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800724: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800728: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8080072C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800730: jr          $ra
    // 0x80800734: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800734: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void gczoombox_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803390: lbu         $t6, 0x177($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X177);
    // 0x80803394: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80803398: jr          $ra
    // 0x8080339C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
    return;
    // 0x8080339C: sb          $t7, 0x177($a0)
    MEM_B(0X177, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80800120_cadbfunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800128: jal         0x800A587C
    // 0x8080012C: nop

    func_800A587C(rdram, ctx);
        goto after_0;
    // 0x8080012C: nop

    after_0:
    // 0x80800130: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800134: beq         $v0, $at, L_8080015C
    if (ctx->r2 == ctx->r1) {
        // 0x80800138: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8080015C;
    }
    // 0x80800138: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080013C: beq         $v0, $at, L_8080016C
    if (ctx->r2 == ctx->r1) {
        // 0x80800140: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8080016C;
    }
    // 0x80800140: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800144: beq         $v0, $at, L_8080017C
    if (ctx->r2 == ctx->r1) {
        // 0x80800148: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8080017C;
    }
    // 0x80800148: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8080014C: beq         $v0, $at, L_8080018C
    if (ctx->r2 == ctx->r1) {
        // 0x80800150: nop
    
            goto L_8080018C;
    }
    // 0x80800150: nop

    // 0x80800154: b           L_8080019C
    // 0x80800158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080019C;
    // 0x80800158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080015C:
    // 0x8080015C: jal         0x800A586C
    // 0x80800160: nop

    func_800A586C(rdram, ctx);
        goto after_1;
    // 0x80800160: nop

    after_1:
    // 0x80800164: b           L_8080019C
    // 0x80800168: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
        goto L_8080019C;
    // 0x80800168: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_8080016C:
    // 0x8080016C: jal         0x800A586C
    // 0x80800170: nop

    func_800A586C(rdram, ctx);
        goto after_2;
    // 0x80800170: nop

    after_2:
    // 0x80800174: b           L_8080019C
    // 0x80800178: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
        goto L_8080019C;
    // 0x80800178: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_8080017C:
    // 0x8080017C: jal         0x800A586C
    // 0x80800180: nop

    func_800A586C(rdram, ctx);
        goto after_3;
    // 0x80800180: nop

    after_3:
    // 0x80800184: b           L_8080019C
    // 0x80800188: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
        goto L_8080019C;
    // 0x80800188: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_8080018C:
    // 0x8080018C: jal         0x800A586C
    // 0x80800190: nop

    func_800A586C(rdram, ctx);
        goto after_4;
    // 0x80800190: nop

    after_4:
    // 0x80800194: b           L_8080019C
    // 0x80800198: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
        goto L_8080019C;
    // 0x80800198: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_8080019C:
    // 0x8080019C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A4: jr          $ra
    // 0x808001A8: nop

    return;
    // 0x808001A8: nop

;}
RECOMP_FUNC void _baswim_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852B8: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x800852B8);
    return;
    // 0x800852BC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _chmole_overworld_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DA8: syscall     453
    recomp_syscall_handler(rdram, ctx, 0x80086DA8);
    return;
    // 0x80086DAC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800DC028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC028: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800DC02C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC030: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800DC034: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800DC038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC03C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800DC040: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800DC044: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800DC048: jal         0x800EE7F8
    // 0x800DC04C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800DC04C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800DC050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC058: jr          $ra
    // 0x800DC05C: nop

    return;
    // 0x800DC05C: nop

;}
RECOMP_FUNC void basquash_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x80800004: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800EE4_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800EF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800EF4: jal         0x80100094
    // 0x80800EF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800EF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800EFC: jal         0x8009EA64
    // 0x80800F00: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8009EA64(rdram, ctx);
        goto after_1;
    // 0x80800F00: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800F04: addiu       $at, $zero, 0x38A
    ctx->r1 = ADD32(0, 0X38A);
    // 0x80800F08: bne         $v0, $at, L_80800F3C
    if (ctx->r2 != ctx->r1) {
        // 0x80800F0C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800F3C;
    }
    // 0x80800F0C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F10: lbu         $t6, 0x8FA($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X8FA);
    // 0x80800F14: beql        $t6, $zero, L_80800F40
    if (ctx->r14 == 0) {
        // 0x80800F18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800F40;
    }
    goto skip_0;
    // 0x80800F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800F1C: sb          $zero, 0x8FA($v1)
    MEM_B(0X8FA, ctx->r3) = 0;
    // 0x80800F20: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800F24: jal         0x80800E58
    // 0x80800F28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800E58_chhandcart(rdram, ctx);
        goto after_2;
    // 0x80800F28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800F2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800F30: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800F34: jal         0x80800CD0
    // 0x80800F38: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    func_80800CD0_chhandcart(rdram, ctx);
        goto after_3;
    // 0x80800F38: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    after_3:
L_80800F3C:
    // 0x80800F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F40:
    // 0x80800F40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800F44: jr          $ra
    // 0x80800F48: nop

    return;
    // 0x80800F48: nop

;}
RECOMP_FUNC void chhoneycarrier_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1724, 0X3F4) << 16);
    // 0x808003C0: jr          $ra
    // 0x808003C4: addiu       $v0, $v0, 0x3F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1724, 0X3F4));
    return;
    // 0x808003C4: addiu       $v0, $v0, 0x3F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1724, 0X3F4));
;}
RECOMP_FUNC void bswalk_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808002C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808002CC: jr          $ra
    // 0x808002D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808002D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void bsfirstp_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808072B4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808072B8: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB580) << 16);
    // 0x808072BC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808072C0: jr          $ra
    // 0x808072C4: lw          $v0, -0x4A80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB580));
    return;
    // 0x808072C4: lw          $v0, -0x4A80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB580));
;}
RECOMP_FUNC void _bsbansack_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800826E8: syscall     7
    recomp_syscall_handler(rdram, ctx, 0x800826E8);
    return;
    // 0x800826EC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void susubgame_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080005C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800060: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800064: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800068: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8080006C: jal         0x80088078
    // 0x80800070: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800070: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80800074: beq         $v0, $zero, L_808000A4
    if (ctx->r2 == 0) {
        // 0x80800078: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_808000A4;
    }
    // 0x80800078: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080007C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80800080: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800088: beq         $t6, $at, L_8080009C
    if (ctx->r14 == ctx->r1) {
        // 0x8080008C: addiu       $a2, $zero, 0x5
        ctx->r6 = ADD32(0, 0X5);
            goto L_8080009C;
    }
    // 0x8080008C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800090: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800094: jal         0x8080014C
    // 0x80800098: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    susubgame_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800098: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
L_8080009C:
    // 0x8080009C: b           L_808000A8
    // 0x808000A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808000A8;
    // 0x808000A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808000A4:
    // 0x808000A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000A8:
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
RECOMP_FUNC void func_808000B4_bskazcrouch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(224, 0X7A0) << 16);
    // 0x808000B8: lwc1        $f4, 0x7A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(224, 0X7A0));
    // 0x808000BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000C8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808000CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000D0: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x808000D4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x808000D8: jal         0x800F10B4
    // 0x808000DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x808000DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808000E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000E4: jal         0x8008B1BC
    // 0x808000E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_setDuration(rdram, ctx);
        goto after_1;
    // 0x808000E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000F4: jr          $ra
    // 0x808000F8: nop

    return;
    // 0x808000F8: nop

;}
RECOMP_FUNC void _bawasher_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085410: syscall     161
    recomp_syscall_handler(rdram, ctx, 0x80085410);
    return;
    // 0x80085414: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800774_chblackeye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800774: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800778: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080077C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800780: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x80800784: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800788: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800790: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800794: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x80800798: jal         0x800EFA4C
    // 0x8080079C: lui         $a3, 0xC448
    ctx->r7 = S32(0XC448 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x8080079C: lui         $a3, 0xC448
    ctx->r7 = S32(0XC448 << 16);
    after_0:
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A4: jal         0x800EF334
    // 0x808007A8: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_800EF334(rdram, ctx);
        goto after_1;
    // 0x808007A8: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_1:
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808007B4: jal         0x800EF934
    // 0x808007B8: lw          $a2, 0x48($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X48);
    func_800EF934(rdram, ctx);
        goto after_2;
    // 0x808007B8: lw          $a2, 0x48($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X48);
    after_2:
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C0: jal         0x800EF04C
    // 0x808007C4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x808007C4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_3:
    // 0x808007C8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1796, 0XF18) << 16);
    // 0x808007CC: addiu       $t6, $t6, 0xF18
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1796, 0XF18));
    // 0x808007D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808007D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808007DC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808007E0: jal         0x800BBCB8
    // 0x808007E4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x808007E4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_4:
    // 0x808007E8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1796, 0XF6C) << 16);
    // 0x808007EC: addiu       $t7, $t7, 0xF6C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1796, 0XF6C));
    // 0x808007F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808007F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808007FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800800: jal         0x800BBCB8
    // 0x80800804: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x80800804: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80800808: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1796, 0XE20) << 16);
    // 0x8080080C: addiu       $a1, $a1, 0xE20
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1796, 0XE20));
    // 0x80800810: jal         0x80800000
    // 0x80800814: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800000_chblackeye(rdram, ctx);
        goto after_6;
    // 0x80800814: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80800818: lbu         $t8, 0x65($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X65);
    // 0x8080081C: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x80800820: sb          $t9, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r25;
    // 0x80800824: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800828: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8080082C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800830: jr          $ra
    // 0x80800834: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800834: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800AA074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA074: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AA078: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AA07C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800AA080: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AA084: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x800AA088: addiu       $s1, $zero, 0x4E
    ctx->r17 = ADD32(0, 0X4E);
    // 0x800AA08C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800AA090:
    // 0x800AA090: jal         0x800A9F60
    // 0x800AA094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A9F60(rdram, ctx);
        goto after_0;
    // 0x800AA094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800AA098: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800AA09C: bnel        $s0, $s1, L_800AA090
    if (ctx->r16 != ctx->r17) {
        // 0x800AA0A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800AA090;
    }
    goto skip_0;
    // 0x800AA0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800AA0A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA0A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AA0AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AA0B0: jr          $ra
    // 0x800AA0B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800AA0B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800070_chchompaslunch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080007C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800080: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800084: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800088: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080008C: beq         $t6, $at, L_808000AC
    if (ctx->r14 == ctx->r1) {
        // 0x80800090: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000AC;
    }
    // 0x80800090: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800094: beq         $t6, $at, L_808000D4
    if (ctx->r14 == ctx->r1) {
        // 0x80800098: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808000D4;
    }
    // 0x80800098: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080009C: beq         $t6, $at, L_808000FC
    if (ctx->r14 == ctx->r1) {
        // 0x808000A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000FC;
    }
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: b           L_80800108
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800108;
    // 0x808000A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000AC:
    // 0x808000AC: jal         0x80800250
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800250_chchompaslunch(rdram, ctx);
        goto after_0;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000B4: jal         0x800D9078
    // 0x808000B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x808000B8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x808000BC: beq         $v0, $zero, L_80800104
    if (ctx->r2 == 0) {
        // 0x808000C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800104;
    }
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x80102424
    // 0x808000C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x808000C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x808000CC: b           L_80800108
    // 0x808000D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800108;
    // 0x808000D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000D4:
    // 0x808000D4: jal         0x8080037C
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080037C_chchompaslunch(rdram, ctx);
        goto after_3;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000DC: jal         0x80101DDC
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_4;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000E4: beq         $v0, $zero, L_80800104
    if (ctx->r2 == 0) {
        // 0x808000E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800104;
    }
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: jal         0x80102424
    // 0x808000F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x808000F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x808000F4: b           L_80800108
    // 0x808000F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800108;
    // 0x808000F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000FC:
    // 0x808000FC: jal         0x80105230
    // 0x80800100: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_6;
    // 0x80800100: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_80800104:
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
RECOMP_FUNC void func_800E78C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E78C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E78CC: addiu       $v0, $v0, -0x2A80
    ctx->r2 = ADD32(ctx->r2, -0X2A80);
    // 0x800E78D0: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x800E78D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E78D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E78DC: beql        $a1, $t6, L_800E791C
    if (ctx->r5 == ctx->r14) {
        // 0x800E78E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E791C;
    }
    goto skip_0;
    // 0x800E78E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E78E4: sw          $a1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r5;
    // 0x800E78E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E78EC: jal         0x800E765C
    // 0x800E78F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800E765C(rdram, ctx);
        goto after_0;
    // 0x800E78F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E78F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800E78F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800E78FC: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x800E7900: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E7904: ori         $t8, $t8, 0x1201
    ctx->r24 = ctx->r24 | 0X1201;
    // 0x800E7908: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800E790C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800E7910: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x800E7914: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800E7918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E791C:
    // 0x800E791C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E7920: jr          $ra
    // 0x800E7924: nop

    return;
    // 0x800E7924: nop

;}
RECOMP_FUNC void vpwibble_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080034C: jal         0x8001B084
    // 0x80800350: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x80800350: nop

    after_0:
    // 0x80800354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800358: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080035C: jr          $ra
    // 0x80800360: nop

    return;
    // 0x80800360: nop

;}
RECOMP_FUNC void func_8080126C_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080126C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801270: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801274: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801278: jal         0x800F54E4
    // 0x8080127C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8080127C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801280: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x80801284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801288: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8080128C: bne         $a1, $zero, L_808012F0
    if (ctx->r5 != 0) {
        // 0x80801290: nop
    
            goto L_808012F0;
    }
    // 0x80801290: nop

    // 0x80801294: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801298: jal         0x800DC298
    // 0x8080129C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x8080129C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808012A0: beq         $v0, $zero, L_808012CC
    if (ctx->r2 == 0) {
        // 0x808012A4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808012CC;
    }
    // 0x808012A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808012A8: jal         0x800F640C
    // 0x808012AC: addiu       $a1, $zero, 0x3CA
    ctx->r5 = ADD32(0, 0X3CA);
    func_800F640C(rdram, ctx);
        goto after_2;
    // 0x808012AC: addiu       $a1, $zero, 0x3CA
    ctx->r5 = ADD32(0, 0X3CA);
    after_2:
    // 0x808012B0: blez        $v0, L_808012C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808012B4: addiu       $t7, $zero, 0x3CB
        ctx->r15 = ADD32(0, 0X3CB);
            goto L_808012C4;
    }
    // 0x808012B4: addiu       $t7, $zero, 0x3CB
    ctx->r15 = ADD32(0, 0X3CB);
    // 0x808012B8: addiu       $t6, $zero, 0x3CA
    ctx->r14 = ADD32(0, 0X3CA);
    // 0x808012BC: b           L_80801320
    // 0x808012C0: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
        goto L_80801320;
    // 0x808012C0: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
L_808012C4:
    // 0x808012C4: b           L_80801320
    // 0x808012C8: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
        goto L_80801320;
    // 0x808012C8: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
L_808012CC:
    // 0x808012CC: jal         0x800F640C
    // 0x808012D0: addiu       $a1, $zero, 0x3CB
    ctx->r5 = ADD32(0, 0X3CB);
    func_800F640C(rdram, ctx);
        goto after_3;
    // 0x808012D0: addiu       $a1, $zero, 0x3CB
    ctx->r5 = ADD32(0, 0X3CB);
    after_3:
    // 0x808012D4: blez        $v0, L_808012E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808012D8: addiu       $t9, $zero, 0x3CA
        ctx->r25 = ADD32(0, 0X3CA);
            goto L_808012E8;
    }
    // 0x808012D8: addiu       $t9, $zero, 0x3CA
    ctx->r25 = ADD32(0, 0X3CA);
    // 0x808012DC: addiu       $t8, $zero, 0x3CB
    ctx->r24 = ADD32(0, 0X3CB);
    // 0x808012E0: b           L_80801320
    // 0x808012E4: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
        goto L_80801320;
    // 0x808012E4: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
L_808012E8:
    // 0x808012E8: b           L_80801320
    // 0x808012EC: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
        goto L_80801320;
    // 0x808012EC: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
L_808012F0:
    // 0x808012F0: jal         0x800F640C
    // 0x808012F4: nop

    func_800F640C(rdram, ctx);
        goto after_4;
    // 0x808012F4: nop

    after_4:
    // 0x808012F8: bnel        $v0, $zero, L_80801324
    if (ctx->r2 != 0) {
        // 0x808012FC: lw          $t3, 0x30($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X30);
            goto L_80801324;
    }
    goto skip_0;
    // 0x808012FC: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    skip_0:
    // 0x80801300: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x80801304: addiu       $at, $zero, 0x3CA
    ctx->r1 = ADD32(0, 0X3CA);
    // 0x80801308: addiu       $t2, $zero, 0x3CA
    ctx->r10 = ADD32(0, 0X3CA);
    // 0x8080130C: bne         $t0, $at, L_8080131C
    if (ctx->r8 != ctx->r1) {
        // 0x80801310: addiu       $t1, $zero, 0x3CB
        ctx->r9 = ADD32(0, 0X3CB);
            goto L_8080131C;
    }
    // 0x80801310: addiu       $t1, $zero, 0x3CB
    ctx->r9 = ADD32(0, 0X3CB);
    // 0x80801314: b           L_80801320
    // 0x80801318: sw          $t1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r9;
        goto L_80801320;
    // 0x80801318: sw          $t1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r9;
L_8080131C:
    // 0x8080131C: sw          $t2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r10;
L_80801320:
    // 0x80801320: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
L_80801324:
    // 0x80801324: addiu       $at, $zero, 0x3CA
    ctx->r1 = ADD32(0, 0X3CA);
    // 0x80801328: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080132C: bne         $t3, $at, L_8080133C
    if (ctx->r11 != ctx->r1) {
        // 0x80801330: addiu       $v1, $zero, 0x1803
        ctx->r3 = ADD32(0, 0X1803);
            goto L_8080133C;
    }
    // 0x80801330: addiu       $v1, $zero, 0x1803
    ctx->r3 = ADD32(0, 0X1803);
    // 0x80801334: b           L_8080133C
    // 0x80801338: addiu       $v1, $zero, 0x17D5
    ctx->r3 = ADD32(0, 0X17D5);
        goto L_8080133C;
    // 0x80801338: addiu       $v1, $zero, 0x17D5
    ctx->r3 = ADD32(0, 0X17D5);
L_8080133C:
    // 0x8080133C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801340: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801344: jr          $ra
    // 0x80801348: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80801348: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _cadbfunc_entrypoint_29(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085668: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085668);
    return;
    // 0x8008566C: addi        $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
;}
RECOMP_FUNC void _bskazshoesspringjump_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800835A0: syscall     67
    recomp_syscall_handler(rdram, ctx, 0x800835A0);
    return;
    // 0x800835A4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800300_plcamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800300: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800304: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800308: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080030C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800310: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2519, 0X510) << 16);
    // 0x80800314: addiu       $a0, $a0, 0x510
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2519, 0X510));
    // 0x80800318: jal         0x800882A8
    // 0x8080031C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _gccubesearch_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x8080031C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80800320: bne         $v0, $zero, L_80800330
    if (ctx->r2 != 0) {
        // 0x80800324: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800330;
    }
    // 0x80800324: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800328: b           L_80800364
    // 0x8080032C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800364;
    // 0x8080032C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800330:
    // 0x80800330: jal         0x80088C00
    // 0x80800334: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800334: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800338: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080033C: jal         0x800EEB40
    // 0x80800340: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800EEB40(rdram, ctx);
        goto after_2;
    // 0x80800340: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800344: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2519, 0X500) << 16);
    // 0x80800348: lwc1        $f4, 0x500($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2519, 0X500));
    // 0x8080034C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800350: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800354: nop

    // 0x80800358: bc1fl       L_80800368
    if (!c1cs) {
        // 0x8080035C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800368;
    }
    goto skip_0;
    // 0x8080035C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800360: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800364:
    // 0x80800364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800368:
    // 0x80800368: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080036C: jr          $ra
    // 0x80800370: nop

    return;
    // 0x80800370: nop

;}
RECOMP_FUNC void func_800AA148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AA14C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA150: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800AA154: jal         0x800A9FA0
    // 0x800AA158: lh          $a0, 0x7780($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7780);
    func_800A9FA0(rdram, ctx);
        goto after_0;
    // 0x800AA158: lh          $a0, 0x7780($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X7780);
    after_0:
    // 0x800AA15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AA164: jr          $ra
    // 0x800AA168: nop

    return;
    // 0x800AA168: nop

;}
RECOMP_FUNC void bastick_calculateZonePosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ED08: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8009ED0C: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8009ED10: sub.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8009ED14: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x8009ED18: jr          $ra
    // 0x8009ED1C: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    return;
    // 0x8009ED1C: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
;}
RECOMP_FUNC void func_80800080_bsdroneslide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800084: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800088: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080008C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800090: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800094: beq         $a1, $at, L_808000B0
    if (ctx->r5 == ctx->r1) {
        // 0x80800098: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_808000B0;
    }
    // 0x80800098: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080009C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000A0: beq         $a1, $at, L_808000D8
    if (ctx->r5 == ctx->r1) {
        // 0x808000A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D8;
    }
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: b           L_808000F8
    // 0x808000AC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
        goto L_808000F8;
    // 0x808000AC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_808000B0:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808000B8: jal         0x800846A8
    // 0x808000BC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x808000BC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808000C8: jal         0x80800000
    // 0x808000CC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80800000_bsdroneslide(rdram, ctx);
        goto after_1;
    // 0x808000CC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x808000D0: b           L_808000F8
    // 0x808000D4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
        goto L_808000F8;
    // 0x808000D4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_808000D8:
    // 0x808000D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808000DC: jal         0x800846A0
    // 0x808000E0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    _badata_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808000E0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808000EC: jal         0x80800000
    // 0x808000F0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_80800000_bsdroneslide(rdram, ctx);
        goto after_3;
    // 0x808000F0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x808000F4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_808000F8:
    // 0x808000F8: sb          $t7, 0x190($s0)
    MEM_B(0X190, ctx->r16) = ctx->r15;
    // 0x808000FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800100: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
