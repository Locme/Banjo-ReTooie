#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void chdinofamilymissing_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800628: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2260, 0X6DC) << 16);
    // 0x8080062C: jr          $ra
    // 0x80800630: addiu       $v0, $v0, 0x6DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2260, 0X6DC));
    return;
    // 0x80800630: addiu       $v0, $v0, 0x6DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2260, 0X6DC));
    // 0x80800634: nop

    // 0x80800638: nop

    // 0x8080063C: nop

;}
RECOMP_FUNC void func_808012C4_chfactorytoxiccloud(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_808012C4_chfactorytoxiccloud");
    // 0x808012C4: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x808012C8: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x808012CC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x808012D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808012D4: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x808012D8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808012DC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808012E0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808012E4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808012E8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808012EC: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x808012F0: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x808012F4: jal         0x80089C40
    // 0x808012F8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808012F8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x808012FC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80801300: bne         $at, $zero, L_8080139C
    if (ctx->r1 != 0) {
        // 0x80801304: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_8080139C;
    }
    // 0x80801304: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80801308: jal         0x800F54E4
    // 0x8080130C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x8080130C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    after_1:
    // 0x80801310: addiu       $s3, $sp, 0x4C
    ctx->r19 = ADD32(ctx->r29, 0X4C);
    // 0x80801314: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801318: jal         0x800F5A00
    // 0x8080131C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x8080131C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80801320: addiu       $a0, $s5, 0x4
    ctx->r4 = ADD32(ctx->r21, 0X4);
    // 0x80801324: jal         0x800EEB40
    // 0x80801328: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x80801328: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x8080132C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80801330: blez        $s4, L_80801394
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80801334: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80801394;
    }
    // 0x80801334: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801338: addiu       $s1, $sp, 0x68
    ctx->r17 = ADD32(ctx->r29, 0X68);
L_8080133C:
    // 0x8080133C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80801340: lw          $t6, 0x78($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X78);
    // 0x80801344: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80801348: bltzl       $t8, L_8080138C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080134C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8080138C;
    }
    goto skip_0;
    // 0x8080134C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80801350: beq         $s5, $v0, L_80801388
    if (ctx->r21 == ctx->r2) {
        // 0x80801354: addiu       $a0, $v0, 0x4
        ctx->r4 = ADD32(ctx->r2, 0X4);
            goto L_80801388;
    }
    // 0x80801354: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80801358: jal         0x800EEB40
    // 0x8080135C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_4;
    // 0x8080135C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x80801360: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80801364: or          $t9, $zero, $zero
    ctx->r25 = 0 | 0;
    // 0x80801368: bc1fl       L_80801378
    if (!c1cs) {
        // 0x8080136C: and         $s2, $s2, $t9
        ctx->r18 = ctx->r18 & ctx->r25;
            goto L_80801378;
    }
    goto skip_1;
    // 0x8080136C: and         $s2, $s2, $t9
    ctx->r18 = ctx->r18 & ctx->r25;
    skip_1:
    // 0x80801370: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80801374: and         $s2, $s2, $t9
    ctx->r18 = ctx->r18 & ctx->r25;
L_80801378:
    // 0x80801378: bnel        $s2, $zero, L_8080138C
    if (ctx->r18 != 0) {
        // 0x8080137C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8080138C;
    }
    goto skip_2;
    // 0x8080137C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x80801380: b           L_808013A0
    // 0x80801384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808013A0;
    // 0x80801384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801388:
    // 0x80801388: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8080138C:
    // 0x8080138C: bne         $s0, $s4, L_8080133C
    if (ctx->r16 != ctx->r20) {
        // 0x80801390: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8080133C;
    }
    // 0x80801390: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80801394:
    // 0x80801394: b           L_808013A0
    // 0x80801398: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_808013A0;
    // 0x80801398: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8080139C:
    // 0x8080139C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808013A0:
    // 0x808013A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808013A4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x808013A8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808013AC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808013B0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808013B4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x808013B8: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x808013BC: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x808013C0: jr          $ra
    // 0x808013C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x808013C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800BD948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD948: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BD94C: addiu       $v0, $v0, -0x7BF0
    ctx->r2 = ADD32(ctx->r2, -0X7BF0);
    // 0x800BD950: addiu       $t6, $v0, 0x34
    ctx->r14 = ADD32(ctx->r2, 0X34);
    // 0x800BD954: bnel        $a0, $t6, L_800BD968
    if (ctx->r4 != ctx->r14) {
        // 0x800BD958: lw          $t7, 0x0($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X0);
            goto L_800BD968;
    }
    goto skip_0;
    // 0x800BD958: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800BD95C: jr          $ra
    // 0x800BD960: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800BD960: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800BD964: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
L_800BD968:
    // 0x800BD968: subu        $v1, $a0, $t7
    ctx->r3 = SUB32(ctx->r4, ctx->r15);
    // 0x800BD96C: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800BD970: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800BD974: jr          $ra
    // 0x800BD978: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800BD978: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _bsbeemain_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082878: syscall     17
    recomp_syscall_handler(rdram, ctx, 0x80082878);
    return;
    // 0x8008287C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800424_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800424: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800428: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8080042C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800430: beq         $a1, $at, L_80800488
    if (ctx->r5 == ctx->r1) {
        // 0x80800434: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800488;
    }
    // 0x80800434: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800438: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8080043C: beq         $a1, $at, L_80800478
    if (ctx->r5 == ctx->r1) {
        // 0x80800440: lh          $a2, 0x22($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X22);
            goto L_80800478;
    }
    // 0x80800440: lh          $a2, 0x22($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X22);
    // 0x80800444: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800448: beq         $a1, $at, L_80800468
    if (ctx->r5 == ctx->r1) {
        // 0x8080044C: addiu       $at, $zero, 0x91
        ctx->r1 = ADD32(0, 0X91);
            goto L_80800468;
    }
    // 0x8080044C: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80800450: beq         $a1, $at, L_808004BC
    if (ctx->r5 == ctx->r1) {
        // 0x80800454: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808004BC;
    }
    // 0x80800454: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800458: beq         $a1, $at, L_80800498
    if (ctx->r5 == ctx->r1) {
        // 0x8080045C: nop
    
            goto L_80800498;
    }
    // 0x8080045C: nop

    // 0x80800460: b           L_808004DC
    // 0x80800464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004DC;
    // 0x80800464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800468:
    // 0x80800468: jal         0x80800DC8
    // 0x8080046C: nop

    func_80800DC8_chcablecar(rdram, ctx);
        goto after_0;
    // 0x8080046C: nop

    after_0:
    // 0x80800470: b           L_808004DC
    // 0x80800474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004DC;
    // 0x80800474: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800478:
    // 0x80800478: jal         0x80800B74
    // 0x8080047C: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    func_80800B74_chcablecar(rdram, ctx);
        goto after_1;
    // 0x8080047C: lh          $a1, 0x20($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X20);
    after_1:
    // 0x80800480: b           L_808004DC
    // 0x80800484: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004DC;
    // 0x80800484: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800488:
    // 0x80800488: jal         0x808004EC
    // 0x8080048C: nop

    func_808004EC_chcablecar(rdram, ctx);
        goto after_2;
    // 0x8080048C: nop

    after_2:
    // 0x80800490: b           L_808004DC
    // 0x80800494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004DC;
    // 0x80800494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800498:
    // 0x80800498: jal         0x800EA05C
    // 0x8080049C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x8080049C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x808004A0: addiu       $at, $zero, 0xD6
    ctx->r1 = ADD32(0, 0XD6);
    // 0x808004A4: bne         $v0, $at, L_808004D8
    if (ctx->r2 != ctx->r1) {
        // 0x808004A8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808004D8;
    }
    // 0x808004A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808004AC: jal         0x80108B04
    // 0x808004B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_4;
    // 0x808004B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808004B4: b           L_808004DC
    // 0x808004B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004DC;
    // 0x808004B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004BC:
    // 0x808004BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x808004C0: lbu         $t7, 0x2A($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2A);
    // 0x808004C4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808004C8: b           L_808004D8
    // 0x808004CC: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
        goto L_808004D8;
    // 0x808004CC: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x808004D0: b           L_808004DC
    // 0x808004D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004DC;
    // 0x808004D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004D8:
    // 0x808004D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004DC:
    // 0x808004DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004E4: jr          $ra
    // 0x808004E8: nop

    return;
    // 0x808004E8: nop

;}
RECOMP_FUNC void func_800E90A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E90A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E90A8: addiu       $v1, $v1, -0x2970
    ctx->r3 = ADD32(ctx->r3, -0X2970);
    // 0x800E90AC: subu        $t6, $a0, $v1
    ctx->r14 = SUB32(ctx->r4, ctx->r3);
    // 0x800E90B0: addiu       $t7, $t6, -0x3A8
    ctx->r15 = ADD32(ctx->r14, -0X3A8);
    // 0x800E90B4: addiu       $at, $zero, 0xD8
    ctx->r1 = ADD32(0, 0XD8);
    // 0x800E90B8: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800E90BC: mflo        $t8
    ctx->r24 = lo;
    // 0x800E90C0: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x800E90C4: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800E90C8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800E90CC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800E90D0: jr          $ra
    // 0x800E90D4: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    return;
    // 0x800E90D4: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
;}
RECOMP_FUNC void func_808008E4_chdinofamilymother(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808008E8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2420, 0X13EC) << 16);
    // 0x808008EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808008F4: addiu       $t6, $t6, 0x13EC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2420, 0X13EC));
    // 0x808008F8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x808008FC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800900: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2420, 0X13F8) << 16);
    // 0x80800904: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80800908: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8080090C: addiu       $t1, $t1, 0x13F8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2420, 0X13F8));
    // 0x80800910: addiu       $t0, $sp, 0x18
    ctx->r8 = ADD32(ctx->r29, 0X18);
    // 0x80800914: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80800918: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8080091C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80800920: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800924: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80800928: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x8080092C: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x80800930: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80800934: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80800938: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x8080093C: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x80800940: jal         0x8010C93C
    // 0x80800944: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8010C93C(rdram, ctx);
        goto after_0;
    // 0x80800944: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80800948: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8080094C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800950: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800954: jal         0x8010C93C
    // 0x80800958: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8010C93C(rdram, ctx);
        goto after_1;
    // 0x80800958: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8080095C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800960: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800964: jr          $ra
    // 0x80800968: nop

    return;
    // 0x80800968: nop

;}
RECOMP_FUNC void func_80801570_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801570: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801574: slti        $at, $a1, 0x58
    ctx->r1 = SIGNED(ctx->r5) < 0X58 ? 1 : 0;
    // 0x80801578: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080157C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80801580: bne         $at, $zero, L_8080159C
    if (ctx->r1 != 0) {
        // 0x80801584: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_8080159C;
    }
    // 0x80801584: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80801588: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080158C: beq         $a1, $at, L_808015C0
    if (ctx->r5 == ctx->r1) {
        // 0x80801590: nop
    
            goto L_808015C0;
    }
    // 0x80801590: nop

    // 0x80801594: b           L_808019B0
    // 0x80801598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808019B0;
    // 0x80801598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080159C:
    // 0x8080159C: addiu       $t6, $a1, -0x18
    ctx->r14 = ADD32(ctx->r5, -0X18);
    // 0x808015A0: sltiu       $at, $t6, 0x40
    ctx->r1 = ctx->r14 < 0X40 ? 1 : 0;
    // 0x808015A4: beq         $at, $zero, L_808019AC
    if (ctx->r1 == 0) {
        // 0x808015A8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808019AC;
    }
    // 0x808015A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808015AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2456, 0X1C30) << 16);
    // 0x808015B0: addu        $at, $at, $t6
    gpr jr_addend_808015B8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808015B4: lw          $t6, 0x1C30($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2456, 0X1C30));
    // 0x808015B8: jr          $t6
    // 0x808015BC: nop

    switch (jr_addend_808015B8 >> 2) {
        case 0: goto L_80801908; break;
        case 1: goto L_808019AC; break;
        case 2: goto L_808019AC; break;
        case 3: goto L_808019AC; break;
        case 4: goto L_808019AC; break;
        case 5: goto L_808019AC; break;
        case 6: goto L_808019AC; break;
        case 7: goto L_808019AC; break;
        case 8: goto L_808019AC; break;
        case 9: goto L_808019AC; break;
        case 10: goto L_808019AC; break;
        case 11: goto L_808019AC; break;
        case 12: goto L_808019AC; break;
        case 13: goto L_808019AC; break;
        case 14: goto L_808019AC; break;
        case 15: goto L_808019AC; break;
        case 16: goto L_808019AC; break;
        case 17: goto L_808019AC; break;
        case 18: goto L_808019AC; break;
        case 19: goto L_808019AC; break;
        case 20: goto L_808019AC; break;
        case 21: goto L_808019AC; break;
        case 22: goto L_808016E4; break;
        case 23: goto L_808019AC; break;
        case 24: goto L_808019AC; break;
        case 25: goto L_808019AC; break;
        case 26: goto L_80801644; break;
        case 27: goto L_808019AC; break;
        case 28: goto L_808019AC; break;
        case 29: goto L_808019AC; break;
        case 30: goto L_808019AC; break;
        case 31: goto L_808019AC; break;
        case 32: goto L_808019AC; break;
        case 33: goto L_808019AC; break;
        case 34: goto L_808019AC; break;
        case 35: goto L_808019AC; break;
        case 36: goto L_808019AC; break;
        case 37: goto L_80801810; break;
        case 38: goto L_808019AC; break;
        case 39: goto L_808019AC; break;
        case 40: goto L_808019AC; break;
        case 41: goto L_808019AC; break;
        case 42: goto L_808019AC; break;
        case 43: goto L_808019AC; break;
        case 44: goto L_808019AC; break;
        case 45: goto L_808019AC; break;
        case 46: goto L_808019AC; break;
        case 47: goto L_808019AC; break;
        case 48: goto L_808019AC; break;
        case 49: goto L_808019AC; break;
        case 50: goto L_808019AC; break;
        case 51: goto L_808019AC; break;
        case 52: goto L_808019AC; break;
        case 53: goto L_808019AC; break;
        case 54: goto L_808019AC; break;
        case 55: goto L_808019AC; break;
        case 56: goto L_808019AC; break;
        case 57: goto L_808019AC; break;
        case 58: goto L_80801938; break;
        case 59: goto L_808019AC; break;
        case 60: goto L_808019AC; break;
        case 61: goto L_808019AC; break;
        case 62: goto L_808019AC; break;
        case 63: goto L_80801960; break;
        default: switch_error(__func__, 0x808015B8, 0x80801C30);
    }
    // 0x808015BC: nop

L_808015C0:
    // 0x808015C0: jal         0x80088848
    // 0x808015C4: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808015C4: nop

    after_0:
    // 0x808015C8: beq         $v0, $zero, L_808015E0
    if (ctx->r2 == 0) {
        // 0x808015CC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808015E0;
    }
    // 0x808015CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808015D0: jal         0x80800ECC
    // 0x808015D4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_1;
    // 0x808015D4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x808015D8: b           L_808019B0
    // 0x808015DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x808015DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808015E0:
    // 0x808015E0: jal         0x800DA298
    // 0x808015E4: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808015E4: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_2:
    // 0x808015E8: beq         $v0, $zero, L_80801634
    if (ctx->r2 == 0) {
        // 0x808015EC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801634;
    }
    // 0x808015EC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808015F0: jal         0x800DA298
    // 0x808015F4: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808015F4: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    after_3:
    // 0x808015F8: bnel        $v0, $zero, L_80801614
    if (ctx->r2 != 0) {
        // 0x808015FC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801614;
    }
    goto skip_0;
    // 0x808015FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x80801600: jal         0x800DA298
    // 0x80801604: addiu       $a0, $zero, 0x3E5
    ctx->r4 = ADD32(0, 0X3E5);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80801604: addiu       $a0, $zero, 0x3E5
    ctx->r4 = ADD32(0, 0X3E5);
    after_4:
    // 0x80801608: beq         $v0, $zero, L_80801624
    if (ctx->r2 == 0) {
        // 0x8080160C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80801624;
    }
    // 0x8080160C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801610: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80801614:
    // 0x80801614: jal         0x80800ECC
    // 0x80801618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_5;
    // 0x80801618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8080161C: b           L_808019B0
    // 0x80801620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x80801620: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801624:
    // 0x80801624: jal         0x80800ECC
    // 0x80801628: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_6;
    // 0x80801628: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_6:
    // 0x8080162C: b           L_808019B0
    // 0x80801630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x80801630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801634:
    // 0x80801634: jal         0x80800ECC
    // 0x80801638: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_7;
    // 0x80801638: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8080163C: b           L_808019B0
    // 0x80801640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x80801640: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801644:
    // 0x80801644: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80801648: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080164C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801650: lhu         $a1, 0x72($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X72);
    // 0x80801654: srl         $t8, $a1, 10
    ctx->r24 = S32(U32(ctx->r5) >> 10);
    // 0x80801658: beq         $t8, $at, L_80801680
    if (ctx->r24 == ctx->r1) {
        // 0x8080165C: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80801680;
    }
    // 0x8080165C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801660: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80801664: beq         $t8, $at, L_808016C4
    if (ctx->r24 == ctx->r1) {
        // 0x80801668: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808016C4;
    }
    // 0x80801668: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080166C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80801670: beq         $t8, $at, L_808016D4
    if (ctx->r24 == ctx->r1) {
        // 0x80801674: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_808016D4;
    }
    // 0x80801674: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801678: b           L_808019B0
    // 0x8080167C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x8080167C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801680:
    // 0x80801680: jal         0x808007D4
    // 0x80801684: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808007D4_chheggy(rdram, ctx);
        goto after_8;
    // 0x80801684: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80801688: jal         0x800DA298
    // 0x8080168C: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x8080168C: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_9:
    // 0x80801690: beq         $v0, $zero, L_808016A0
    if (ctx->r2 == 0) {
        // 0x80801694: lw          $t9, 0x38($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X38);
            goto L_808016A0;
    }
    // 0x80801694: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80801698: b           L_808016A4
    // 0x8080169C: addiu       $a1, $zero, 0x153B
    ctx->r5 = ADD32(0, 0X153B);
        goto L_808016A4;
    // 0x8080169C: addiu       $a1, $zero, 0x153B
    ctx->r5 = ADD32(0, 0X153B);
L_808016A0:
    // 0x808016A0: addiu       $a1, $zero, 0x153A
    ctx->r5 = ADD32(0, 0X153A);
L_808016A4:
    // 0x808016A4: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x808016A8: addiu       $t0, $zero, 0xCB
    ctx->r8 = ADD32(0, 0XCB);
    // 0x808016AC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808016B0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808016B4: jal         0x8008A208
    // 0x808016B8: addiu       $a3, $t9, 0x4
    ctx->r7 = ADD32(ctx->r25, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x808016B8: addiu       $a3, $t9, 0x4
    ctx->r7 = ADD32(ctx->r25, 0X4);
    after_10:
    // 0x808016BC: b           L_808019B0
    // 0x808016C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x808016C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808016C4:
    // 0x808016C4: jal         0x80800ECC
    // 0x808016C8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_11;
    // 0x808016C8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_11:
    // 0x808016CC: b           L_808019B0
    // 0x808016D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x808016D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808016D4:
    // 0x808016D4: jal         0x80800ECC
    // 0x808016D8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_12;
    // 0x808016D8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_12:
    // 0x808016DC: b           L_808019B0
    // 0x808016E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x808016E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808016E4:
    // 0x808016E4: lh          $t1, 0x40($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X40);
    // 0x808016E8: addiu       $t2, $t1, -0x153A
    ctx->r10 = ADD32(ctx->r9, -0X153A);
    // 0x808016EC: sltiu       $at, $t2, 0xA
    ctx->r1 = ctx->r10 < 0XA ? 1 : 0;
    // 0x808016F0: beq         $at, $zero, L_80801808
    if (ctx->r1 == 0) {
        // 0x808016F4: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80801808;
    }
    // 0x808016F4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x808016F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2456, 0X1D30) << 16);
    // 0x808016FC: addu        $at, $at, $t2
    gpr jr_addend_80801704 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80801700: lw          $t2, 0x1D30($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2456, 0X1D30));
    // 0x80801704: jr          $t2
    // 0x80801708: nop

    switch (jr_addend_80801704 >> 2) {
        case 0: goto L_8080170C; break;
        case 1: goto L_8080170C; break;
        case 2: goto L_808017FC; break;
        case 3: goto L_8080176C; break;
        case 4: goto L_8080176C; break;
        case 5: goto L_8080176C; break;
        case 6: goto L_80801780; break;
        case 7: goto L_80801794; break;
        case 8: goto L_808017CC; break;
        case 9: goto L_808017EC; break;
        default: switch_error(__func__, 0x80801704, 0x80801D30);
    }
    // 0x80801708: nop

L_8080170C:
    // 0x8080170C: jal         0x8080006C
    // 0x80801710: nop

    func_8080006C_chheggy(rdram, ctx);
        goto after_13;
    // 0x80801710: nop

    after_13:
    // 0x80801714: beq         $v0, $zero, L_8080173C
    if (ctx->r2 == 0) {
        // 0x80801718: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_8080173C;
    }
    // 0x80801718: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080171C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801720: beq         $v0, $at, L_8080174C
    if (ctx->r2 == ctx->r1) {
        // 0x80801724: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_8080174C;
    }
    // 0x80801724: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801728: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080172C: beq         $v0, $at, L_8080175C
    if (ctx->r2 == ctx->r1) {
        // 0x80801730: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_8080175C;
    }
    // 0x80801730: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801734: b           L_808019B0
    // 0x80801738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x80801738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080173C:
    // 0x8080173C: jal         0x80800ECC
    // 0x80801740: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_14;
    // 0x80801740: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x80801744: b           L_808019B0
    // 0x80801748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x80801748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080174C:
    // 0x8080174C: jal         0x80800ECC
    // 0x80801750: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_15;
    // 0x80801750: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_15:
    // 0x80801754: b           L_808019B0
    // 0x80801758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x80801758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080175C:
    // 0x8080175C: jal         0x80800ECC
    // 0x80801760: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_16;
    // 0x80801760: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_16:
    // 0x80801764: b           L_808019B0
    // 0x80801768: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x80801768: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080176C:
    // 0x8080176C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801770: jal         0x80800ECC
    // 0x80801774: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_17;
    // 0x80801774: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_17:
    // 0x80801778: b           L_808019B0
    // 0x8080177C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x8080177C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801780:
    // 0x80801780: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801784: jal         0x80800ECC
    // 0x80801788: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_18;
    // 0x80801788: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_18:
    // 0x8080178C: b           L_808019B0
    // 0x80801790: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x80801790: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801794:
    // 0x80801794: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80801798: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8080179C: lw          $t4, 0x64($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X64);
    // 0x808017A0: sll         $t6, $t4, 12
    ctx->r14 = S32(ctx->r12 << 12);
    // 0x808017A4: bgez        $t6, L_808017B4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808017A8: nop
    
            goto L_808017B4;
    }
    // 0x808017A8: nop

    // 0x808017AC: b           L_808017B4
    // 0x808017B0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
        goto L_808017B4;
    // 0x808017B0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_808017B4:
    // 0x808017B4: jal         0x80800ECC
    // 0x808017B8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_19;
    // 0x808017B8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_19:
    // 0x808017BC: jal         0x800D3EF4
    // 0x808017C0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800D3EF4(rdram, ctx);
        goto after_20;
    // 0x808017C0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_20:
    // 0x808017C4: b           L_808019B0
    // 0x808017C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x808017C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808017CC:
    // 0x808017CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808017D0: jal         0x80800ECC
    // 0x808017D4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_21;
    // 0x808017D4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_21:
    // 0x808017D8: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x808017DC: jal         0x800C7074
    // 0x808017E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C7074(rdram, ctx);
        goto after_22;
    // 0x808017E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x808017E4: b           L_808019B0
    // 0x808017E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x808017E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808017EC:
    // 0x808017EC: jal         0x800DA544
    // 0x808017F0: addiu       $a0, $zero, 0xC0B
    ctx->r4 = ADD32(0, 0XC0B);
    func_800DA544(rdram, ctx);
        goto after_23;
    // 0x808017F0: addiu       $a0, $zero, 0xC0B
    ctx->r4 = ADD32(0, 0XC0B);
    after_23:
    // 0x808017F4: b           L_808019B0
    // 0x808017F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x808017F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808017FC:
    // 0x808017FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801800: jal         0x80800ECC
    // 0x80801804: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_24;
    // 0x80801804: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_24:
L_80801808:
    // 0x80801808: b           L_808019B0
    // 0x8080180C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x8080180C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801810:
    // 0x80801810: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801814: jal         0x80100094
    // 0x80801818: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_25;
    // 0x80801818: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x8080181C: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80801820: addiu       $at, $zero, 0x515
    ctx->r1 = ADD32(0, 0X515);
    // 0x80801824: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801828: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x8080182C: addiu       $a0, $zero, 0x517
    ctx->r4 = ADD32(0, 0X517);
    // 0x80801830: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801834: bne         $t8, $at, L_80801848
    if (ctx->r24 != ctx->r1) {
        // 0x80801838: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_80801848;
    }
    // 0x80801838: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080183C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80801840: b           L_8080184C
    // 0x80801844: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
        goto L_8080184C;
    // 0x80801844: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80801848:
    // 0x80801848: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
L_8080184C:
    // 0x8080184C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80801850: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x80801854: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80801858: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8080185C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80801860: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80801864: jal         0x80108528
    // 0x80801868: addu        $a1, $v1, $t1
    ctx->r5 = ADD32(ctx->r3, ctx->r9);
    func_80108528(rdram, ctx);
        goto after_26;
    // 0x80801868: addu        $a1, $v1, $t1
    ctx->r5 = ADD32(ctx->r3, ctx->r9);
    after_26:
    // 0x8080186C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80801870: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80801874: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80801878: addiu       $at, $zero, 0x515
    ctx->r1 = ADD32(0, 0X515);
    // 0x8080187C: sw          $t2, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->r10;
    // 0x80801880: lbu         $t4, 0x65($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X65);
    // 0x80801884: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801888: andi        $t5, $t4, 0xFFFE
    ctx->r13 = ctx->r12 & 0XFFFE;
    // 0x8080188C: sb          $t5, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r13;
    // 0x80801890: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80801894: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x80801898: bnel        $t7, $at, L_808018D8
    if (ctx->r15 != ctx->r1) {
        // 0x8080189C: lw          $t1, 0x0($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X0);
            goto L_808018D8;
    }
    goto skip_1;
    // 0x8080189C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    skip_1:
    // 0x808018A0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x808018A4: addiu       $a1, $zero, 0x975
    ctx->r5 = ADD32(0, 0X975);
    // 0x808018A8: sw          $t8, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r24;
    // 0x808018AC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x808018B0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x808018B4: lhu         $a2, 0x16($t0)
    ctx->r6 = MEM_HU(ctx->r8, 0X16);
    // 0x808018B8: jal         0x80103140
    // 0x808018BC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80103140(rdram, ctx);
        goto after_27;
    // 0x808018BC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_27:
    // 0x808018C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808018C4: jal         0x80102424
    // 0x808018C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_28;
    // 0x808018C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x808018CC: b           L_808019B0
    // 0x808018D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x808018D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808018D4: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
L_808018D8:
    // 0x808018D8: addiu       $a1, $zero, 0x974
    ctx->r5 = ADD32(0, 0X974);
    // 0x808018DC: sw          $t1, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r9;
    // 0x808018E0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x808018E4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x808018E8: lhu         $a2, 0x16($t3)
    ctx->r6 = MEM_HU(ctx->r11, 0X16);
    // 0x808018EC: jal         0x80103140
    // 0x808018F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80103140(rdram, ctx);
        goto after_29;
    // 0x808018F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_29:
    // 0x808018F4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808018F8: jal         0x80102424
    // 0x808018FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_30;
    // 0x808018FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80801900: b           L_808019B0
    // 0x80801904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x80801904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801908:
    // 0x80801908: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8080190C: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80801910: addiu       $a1, $zero, 0x1543
    ctx->r5 = ADD32(0, 0X1543);
    // 0x80801914: beq         $t4, $zero, L_80801930
    if (ctx->r12 == 0) {
        // 0x80801918: addiu       $a2, $zero, 0xE
        ctx->r6 = ADD32(0, 0XE);
            goto L_80801930;
    }
    // 0x80801918: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8080191C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80801920: addiu       $t6, $zero, 0xCB
    ctx->r14 = ADD32(0, 0XCB);
    // 0x80801924: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801928: jal         0x8008A208
    // 0x8080192C: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_31;
    // 0x8080192C: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    after_31:
L_80801930:
    // 0x80801930: b           L_808019B0
    // 0x80801934: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x80801934: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801938:
    // 0x80801938: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080193C: jal         0x80088098
    // 0x80801940: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_32;
    // 0x80801940: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_32:
    // 0x80801944: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80801948: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2456, 0X1E8C) << 16);
    // 0x8080194C: addiu       $a0, $a0, 0x1E8C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2456, 0X1E8C));
    // 0x80801950: jal         0x80088090
    // 0x80801954: lw          $a1, 0x38($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_33;
    // 0x80801954: lw          $a1, 0x38($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X38);
    after_33:
    // 0x80801958: b           L_808019B0
    // 0x8080195C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_808019B0;
    // 0x8080195C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80801960:
    // 0x80801960: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80801964: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80801968: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8080196C: and         $t9, $a2, $at
    ctx->r25 = ctx->r6 & ctx->r1;
    // 0x80801970: srl         $a1, $t9, 16
    ctx->r5 = S32(U32(ctx->r25) >> 16);
    // 0x80801974: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x80801978: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x8080197C: jal         0x80088078
    // 0x80801980: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_34;
    // 0x80801980: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_34:
    // 0x80801984: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80801988: beq         $v0, $zero, L_808019A4
    if (ctx->r2 == 0) {
        // 0x8080198C: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_808019A4;
    }
    // 0x8080198C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80801990: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80801994: jal         0x808007D4
    // 0x80801998: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_808007D4_chheggy(rdram, ctx);
        goto after_35;
    // 0x80801998: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_35:
    // 0x8080199C: b           L_808019B0
    // 0x808019A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808019B0;
    // 0x808019A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808019A4:
    // 0x808019A4: b           L_808019B0
    // 0x808019A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808019B0;
    // 0x808019A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808019AC:
    // 0x808019AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808019B0:
    // 0x808019B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808019B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808019B8: jr          $ra
    // 0x808019BC: nop

    return;
    // 0x808019BC: nop

;}
RECOMP_FUNC void glglobalsettings_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800218: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080021C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800220: jal         0x80800084
    // 0x80800224: nop

    func_80800084_glglobalsettings(rdram, ctx);
        goto after_0;
    // 0x80800224: nop

    after_0:
    // 0x80800228: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8080022C: jal         0x80800168
    // 0x80800230: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80800168_glglobalsettings(rdram, ctx);
        goto after_1;
    // 0x80800230: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80800234: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800238: bne         $v0, $at, L_80800250
    if (ctx->r2 != ctx->r1) {
        // 0x8080023C: nop
    
            goto L_80800250;
    }
    // 0x8080023C: nop

    // 0x80800240: jal         0x80800000
    // 0x80800244: nop

    glglobalsettings_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800244: nop

    after_2:
    // 0x80800248: b           L_80800260
    // 0x8080024C: nop

        goto L_80800260;
    // 0x8080024C: nop

L_80800250:
    // 0x80800250: jal         0x800885B8
    // 0x80800254: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _glglobaldata_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800254: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800258: jal         0x80800034
    // 0x8080025C: nop

    func_80800034_glglobalsettings(rdram, ctx);
        goto after_4;
    // 0x8080025C: nop

    after_4:
L_80800260:
    // 0x80800260: jal         0x8001B084
    // 0x80800264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    heap_free(rdram, ctx);
        goto after_5;
    // 0x80800264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80800268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080026C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800270: jr          $ra
    // 0x80800274: nop

    return;
    // 0x80800274: nop

;}
RECOMP_FUNC void _susplinet_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E20: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E20);
    return;
    // 0x80089E24: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bskazow_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808002A4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(264, 0X2E0) << 16);
    // 0x808002A8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808002AC: jr          $ra
    // 0x808002B0: lw          $v0, 0x2E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(264, 0X2E0));
    return;
    // 0x808002B0: lw          $v0, 0x2E0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(264, 0X2E0));
;}
RECOMP_FUNC void baduo_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808009CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009D8: jal         0x800878A0
    // 0x808009DC: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808009DC: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x808009E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E8: jal         0x800F457C
    // 0x808009EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F457C(rdram, ctx);
        goto after_1;
    // 0x808009EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808009F8: jal         0x800A38F0
    // 0x808009FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_2;
    // 0x808009FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80800A00: jal         0x800F8EBC
    // 0x80800A04: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F8EBC(rdram, ctx);
        goto after_3;
    // 0x80800A04: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_3:
    // 0x80800A08: jal         0x800F53D0
    // 0x80800A0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F53D0(rdram, ctx);
        goto after_4;
    // 0x80800A0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800A10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A14: jal         0x80800008
    // 0x80800A18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800008_baduo(rdram, ctx);
        goto after_5;
    // 0x80800A18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800A1C: jal         0x800F8128
    // 0x80800A20: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F8128(rdram, ctx);
        goto after_6;
    // 0x80800A20: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_6:
    // 0x80800A24: jal         0x800F53D0
    // 0x80800A28: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F53D0(rdram, ctx);
        goto after_7;
    // 0x80800A28: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80800A2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A30: jal         0x80800CA8
    // 0x80800A34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800CA8_baduo(rdram, ctx);
        goto after_8;
    // 0x80800A34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80800A38: jal         0x800F759C
    // 0x80800A3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F759C(rdram, ctx);
        goto after_9;
    // 0x80800A3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A44: jal         0x80800C78
    // 0x80800A48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800C78_baduo(rdram, ctx);
        goto after_10;
    // 0x80800A48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800A4C: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800A50: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A58: addiu       $a1, $zero, 0x5A4
    ctx->r5 = ADD32(0, 0X5A4);
    // 0x80800A5C: jal         0x8009DB04
    // 0x80800A60: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DB04(rdram, ctx);
        goto after_11;
    // 0x80800A60: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_11:
    // 0x80800A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A70: jr          $ra
    // 0x80800A74: nop

    return;
    // 0x80800A74: nop

;}
RECOMP_FUNC void chcactusofstrength_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(824, 0XD48) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xD48
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(824, 0XD48));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xD48
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(824, 0XD48));
;}
RECOMP_FUNC void func_80112160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112160: jr          $ra
    // 0x80112164: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
    return;
    // 0x80112164: addiu       $v0, $zero, 0x34
    ctx->r2 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_8080075C_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080075C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800764: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800768: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080076C: jal         0x80095738
    // 0x80800770: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x80800770: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x80800774: beq         $v0, $zero, L_80800784
    if (ctx->r2 == 0) {
        // 0x80800778: nop
    
            goto L_80800784;
    }
    // 0x80800778: nop

    // 0x8080077C: b           L_808007D0
    // 0x80800780: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_808007D0;
    // 0x80800780: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80800784:
    // 0x80800784: jal         0x8008D3B0
    // 0x80800788: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008D3B0(rdram, ctx);
        goto after_1;
    // 0x80800788: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080078C: beq         $v0, $zero, L_8080079C
    if (ctx->r2 == 0) {
        // 0x80800790: nop
    
            goto L_8080079C;
    }
    // 0x80800790: nop

    // 0x80800794: b           L_808007D0
    // 0x80800798: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
        goto L_808007D0;
    // 0x80800798: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
L_8080079C:
    // 0x8080079C: jal         0x8008E430
    // 0x808007A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E430(rdram, ctx);
        goto after_2;
    // 0x808007A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808007A4: beq         $v0, $zero, L_808007B4
    if (ctx->r2 == 0) {
        // 0x808007A8: nop
    
            goto L_808007B4;
    }
    // 0x808007A8: nop

    // 0x808007AC: b           L_808007D0
    // 0x808007B0: addiu       $v0, $zero, 0x9C
    ctx->r2 = ADD32(0, 0X9C);
        goto L_808007D0;
    // 0x808007B0: addiu       $v0, $zero, 0x9C
    ctx->r2 = ADD32(0, 0X9C);
L_808007B4:
    // 0x808007B4: jal         0x8008E40C
    // 0x808007B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E40C(rdram, ctx);
        goto after_3;
    // 0x808007B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808007BC: beql        $v0, $zero, L_808007D0
    if (ctx->r2 == 0) {
        // 0x808007C0: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_808007D0;
    }
    goto skip_0;
    // 0x808007C0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    skip_0:
    // 0x808007C4: b           L_808007D0
    // 0x808007C8: addiu       $v0, $zero, 0x95
    ctx->r2 = ADD32(0, 0X95);
        goto L_808007D0;
    // 0x808007C8: addiu       $v0, $zero, 0x95
    ctx->r2 = ADD32(0, 0X95);
    // 0x808007CC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
L_808007D0:
    // 0x808007D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007D8: jr          $ra
    // 0x808007DC: nop

    return;
    // 0x808007DC: nop

;}
RECOMP_FUNC void _badrone_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084878: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x80084878);
    return;
    // 0x8008487C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void _cadbfunc_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800855C8: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x800855C8);
    return;
    // 0x800855CC: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_808017E8_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808017E8: jr          $ra
    // 0x808017EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808017EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80106E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106E88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80106E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106E90: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80106E94: jal         0x80100368
    // 0x80106E98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80100368(rdram, ctx);
        goto after_0;
    // 0x80106E98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80106E9C: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x80106EA0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80106EA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80106EA8: beql        $t6, $zero, L_80106ED0
    if (ctx->r14 == 0) {
        // 0x80106EAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106ED0;
    }
    goto skip_0;
    // 0x80106EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80106EB0: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    // 0x80106EB4: srl         $t8, $t7, 21
    ctx->r24 = S32(U32(ctx->r15) >> 21);
    // 0x80106EB8: beql        $t8, $zero, L_80106ED0
    if (ctx->r24 == 0) {
        // 0x80106EBC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80106ED0;
    }
    goto skip_1;
    // 0x80106EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80106EC0: jal         0x80107320
    // 0x80106EC4: nop

    func_80107320(rdram, ctx);
        goto after_1;
    // 0x80106EC4: nop

    after_1:
    // 0x80106EC8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80106ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106ED0:
    // 0x80106ED0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80106ED4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80106ED8: jr          $ra
    // 0x80106EDC: nop

    return;
    // 0x80106EDC: nop

;}
RECOMP_FUNC void _chgameselect_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BE8: syscall     205
    recomp_syscall_handler(rdram, ctx, 0x80085BE8);
    return;
    // 0x80085BEC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void gcextra_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $a0, $zero, 0x4EA
    ctx->r4 = ADD32(0, 0X4EA);
    // 0x8080000C: jal         0x800DA564
    // 0x80800010: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
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
RECOMP_FUNC void _badust_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A18: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x80084A18);
    return;
    // 0x80084A1C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800B7D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7D78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7D7C: lw          $a0, -0x7D50($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D50);
    // 0x800B7D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7D88: beq         $a0, $zero, L_800B7D98
    if (ctx->r4 == 0) {
        // 0x800B7D8C: nop
    
            goto L_800B7D98;
    }
    // 0x800B7D8C: nop

    // 0x800B7D90: jal         0x80088960
    // 0x800B7D94: nop

    _fxleaves_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x800B7D94: nop

    after_0:
L_800B7D98:
    // 0x800B7D98: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B7D9C: lw          $a0, -0x7D4C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D4C);
    // 0x800B7DA0: beq         $a0, $zero, L_800B7DB0
    if (ctx->r4 == 0) {
        // 0x800B7DA4: nop
    
            goto L_800B7DB0;
    }
    // 0x800B7DA4: nop

    // 0x800B7DA8: jal         0x80088920
    // 0x800B7DAC: nop

    _fxrain_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x800B7DAC: nop

    after_1:
L_800B7DB0:
    // 0x800B7DB0: jal         0x800B90E8
    // 0x800B7DB4: nop

    func_800B90E8(rdram, ctx);
        goto after_2;
    // 0x800B7DB4: nop

    after_2:
    // 0x800B7DB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7DBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7DC0: jr          $ra
    // 0x800B7DC4: nop

    return;
    // 0x800B7DC4: nop

;}
RECOMP_FUNC void func_800C67C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C67C8: jr          $ra
    // 0x800C67CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    return;
    // 0x800C67CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
;}
RECOMP_FUNC void func_80014DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014DC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80014DC8: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014DCC: jr          $ra
    // 0x80014DD0: sw          $t6, -0x70A8($at)
    MEM_W(-0X70A8, ctx->r1) = ctx->r14;
    return;
    // 0x80014DD0: sw          $t6, -0x70A8($at)
    MEM_W(-0X70A8, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_800CA7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA7E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA7E8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800CA7EC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800CA7F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA7F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CA7F8: jal         0x800EE7F8
    // 0x800CA7FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800CA7FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800CA800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA804: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA808: jr          $ra
    // 0x800CA80C: nop

    return;
    // 0x800CA80C: nop

;}
RECOMP_FUNC void func_80800000_ncbaledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80112524
    // 0x8080000C: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800018: jr          $ra
    // 0x8080001C: nop

    return;
    // 0x8080001C: nop

;}
RECOMP_FUNC void func_800ADF5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADF5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ADF60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ADF64: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x800ADF68: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800ADF6C: beq         $a1, $zero, L_800ADF80
    if (ctx->r5 == 0) {
        // 0x800ADF70: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_800ADF80;
    }
    // 0x800ADF70: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800ADF74: jal         0x800E0A50
    // 0x800ADF78: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800E0A50(rdram, ctx);
        goto after_0;
    // 0x800ADF78: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800ADF7C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_800ADF80:
    // 0x800ADF80: jal         0x8001B084
    // 0x800ADF84: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    heap_free(rdram, ctx);
        goto after_1;
    // 0x800ADF84: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x800ADF88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ADF8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800ADF90: jr          $ra
    // 0x800ADF94: nop

    return;
    // 0x800ADF94: nop

;}
RECOMP_FUNC void bsstand_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800BF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BF8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BFC: jal         0x8008CABC
    // 0x80800C00: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800C00: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80800C04: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800C08: jal         0x8008B264
    // 0x80800C0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getIndex(rdram, ctx);
        goto after_1;
    // 0x80800C0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800C10: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x80800C14: bne         $v0, $at, L_80800C68
    if (ctx->r2 != ctx->r1) {
        // 0x80800C18: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800C68;
    }
    // 0x80800C18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800C1C: lui         $a1, 0x3F53
    ctx->r5 = S32(0X3F53 << 16);
    // 0x80800C20: jal         0x8008B348
    // 0x80800C24: ori         $a1, $a1, 0x8EF3
    ctx->r5 = ctx->r5 | 0X8EF3;
    anctrl_isAt(rdram, ctx);
        goto after_2;
    // 0x80800C24: ori         $a1, $a1, 0x8EF3
    ctx->r5 = ctx->r5 | 0X8EF3;
    after_2:
    // 0x80800C28: beq         $v0, $zero, L_80800C40
    if (ctx->r2 == 0) {
        // 0x80800C2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C40;
    }
    // 0x80800C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C30: addiu       $a1, $zero, 0x449
    ctx->r5 = ADD32(0, 0X449);
    // 0x80800C34: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800C38: jal         0x8009DF18
    // 0x80800C3C: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DF18(rdram, ctx);
        goto after_3;
    // 0x80800C3C: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_3:
L_80800C40:
    // 0x80800C40: lui         $a1, 0x3F62
    ctx->r5 = S32(0X3F62 << 16);
    // 0x80800C44: ori         $a1, $a1, 0xEB1C
    ctx->r5 = ctx->r5 | 0XEB1C;
    // 0x80800C48: jal         0x8008B348
    // 0x80800C4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_4;
    // 0x80800C4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800C50: beq         $v0, $zero, L_80800C68
    if (ctx->r2 == 0) {
        // 0x80800C54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C68;
    }
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C58: addiu       $a1, $zero, 0x449
    ctx->r5 = ADD32(0, 0X449);
    // 0x80800C5C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800C60: jal         0x8009DF18
    // 0x80800C64: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DF18(rdram, ctx);
        goto after_5;
    // 0x80800C64: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_5:
L_80800C68:
    // 0x80800C68: jal         0x8008B324
    // 0x80800C6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_6;
    // 0x80800C6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800C70: beq         $v0, $zero, L_80800C80
    if (ctx->r2 == 0) {
        // 0x80800C74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C80;
    }
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800C7C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800C80:
    // 0x80800C80: jal         0x80800038
    // 0x80800C84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80800038_bsstand(rdram, ctx);
        goto after_7;
    // 0x80800C84: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x80800C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C8C: jal         0x8009E5C8
    // 0x80800C90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x80800C90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x80800C94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CA0: jr          $ra
    // 0x80800CA4: nop

    return;
    // 0x80800CA4: nop

;}
RECOMP_FUNC void func_80800558_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800558: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080055C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800560: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800564: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800568: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8080056C: jal         0x80101FDC
    // 0x80800570: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800570: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800574: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800578: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080057C: beq         $a1, $at, L_80800594
    if (ctx->r5 == ctx->r1) {
        // 0x80800580: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800594;
    }
    // 0x80800580: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800584: beq         $a1, $at, L_808005C0
    if (ctx->r5 == ctx->r1) {
        // 0x80800588: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808005C0;
    }
    // 0x80800588: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080058C: b           L_808005EC
    // 0x80800590: addiu       $a0, $zero, 0x9FB
    ctx->r4 = ADD32(0, 0X9FB);
        goto L_808005EC;
    // 0x80800590: addiu       $a0, $zero, 0x9FB
    ctx->r4 = ADD32(0, 0X9FB);
L_80800594:
    // 0x80800594: jal         0x800A9C98
    // 0x80800598: nop

    func_800A9C98(rdram, ctx);
        goto after_1;
    // 0x80800598: nop

    after_1:
    // 0x8080059C: beq         $v0, $zero, L_808005B4
    if (ctx->r2 == 0) {
        // 0x808005A0: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_808005B4;
    }
    // 0x808005A0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808005A4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808005A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808005AC: b           L_808005E8
    // 0x808005B0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_808005E8;
    // 0x808005B0: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_808005B4:
    // 0x808005B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808005B8: b           L_808005E8
    // 0x808005BC: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_808005E8;
    // 0x808005BC: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_808005C0:
    // 0x808005C0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808005C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005C8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808005CC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808005D0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808005D4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x808005D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808005DC: jal         0x800DC178
    // 0x808005E0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x808005E0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x808005E4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_808005E8:
    // 0x808005E8: addiu       $a0, $zero, 0x9FB
    ctx->r4 = ADD32(0, 0X9FB);
L_808005EC:
    // 0x808005EC: jal         0x800DA3B8
    // 0x808005F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DA3B8(rdram, ctx);
        goto after_3;
    // 0x808005F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x808005F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800600: jr          $ra
    // 0x80800604: nop

    return;
    // 0x80800604: nop

;}
RECOMP_FUNC void func_80800634_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800634: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800638: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080063C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800640: jal         0x8008CABC
    // 0x80800644: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800644: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800648: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080064C: jal         0x8009E710
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800654: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x80800658: bnel        $v0, $at, L_80800674
    if (ctx->r2 != ctx->r1) {
        // 0x8080065C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800674;
    }
    goto skip_0;
    // 0x8080065C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x80800660: jal         0x8008B2B4
    // 0x80800664: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    anctrl_getAnimTimer(rdram, ctx);
        goto after_2;
    // 0x80800664: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800668: b           L_8080067C
    // 0x8080066C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8080067C;
    // 0x8080066C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800670: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80800674:
    // 0x80800674: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800678: nop

L_8080067C:
    // 0x8080067C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x80800688: jal         0x8008CC34
    // 0x8080068C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopStartingAt(rdram, ctx);
        goto after_3;
    // 0x8080068C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x80800690: jal         0x80800000
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bsbswim(rdram, ctx);
        goto after_4;
    // 0x80800694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800698: jal         0x80800030
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800030_bsbswim(rdram, ctx);
        goto after_5;
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A4: jal         0x800852A8
    // 0x808006A8: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    _baswim_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808006A8: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    after_6:
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: jal         0x8009BC5C
    // 0x808006B4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_7;
    // 0x808006B4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_7:
    // 0x808006B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006BC: jal         0x800910BC
    // 0x808006C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800910BC(rdram, ctx);
        goto after_8;
    // 0x808006C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x808006C4: sb          $zero, 0x166($s0)
    MEM_B(0X166, ctx->r16) = 0;
    // 0x808006C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006D4: jr          $ra
    // 0x808006D8: nop

    return;
    // 0x808006D8: nop

;}
RECOMP_FUNC void func_80800200_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800204: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800208: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080020C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800210: jal         0x80100094
    // 0x80800214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800218: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8080021C: jal         0x801022E4
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_1;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800224: addiu       $t6, $v0, -0x429
    ctx->r14 = ADD32(ctx->r2, -0X429);
    // 0x80800228: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x8080022C: beq         $at, $zero, L_80800408
    if (ctx->r1 == 0) {
        // 0x80800230: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800408;
    }
    // 0x80800230: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800234: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9700) << 16);
    // 0x80800238: addu        $at, $at, $t6
    gpr jr_addend_80800240 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080023C: lw          $t6, -0x6900($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9700));
    // 0x80800240: jr          $t6
    // 0x80800244: nop

    switch (jr_addend_80800240 >> 2) {
        case 0: goto L_80800328; break;
        case 1: goto L_80800408; break;
        case 2: goto L_80800328; break;
        case 3: goto L_80800408; break;
        case 4: goto L_80800248; break;
        case 5: goto L_808002F0; break;
        case 6: goto L_80800394; break;
        default: switch_error(__func__, 0x80800240, 0x80809700);
    }
    // 0x80800244: nop

L_80800248:
    // 0x80800248: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8080024C: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800250: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800254: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800258: jal         0x80102320
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102320(rdram, ctx);
        goto after_2;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800260: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80800264: lw          $t8, 0x70($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X70);
    // 0x80800268: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080026C: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0X9E24) << 16);
    // 0x80800270: lbu         $a0, 0xA0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0XA0);
    // 0x80800274: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80800278: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080027C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800280: addiu       $a3, $a3, -0x61DC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0X9E24));
    // 0x80800284: jal         0x80089D68
    // 0x80800288: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800288: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x8080028C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80800290: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800294: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9E38) << 16);
    // 0x80800298: lui         $a3, 0x3F59
    ctx->r7 = S32(0X3F59 << 16);
    // 0x8080029C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808002A0: addiu       $a2, $a2, -0x61C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9E38));
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: jal         0x80089D20
    // 0x808002AC: sb          $v0, 0xA0($t0)
    MEM_B(0XA0, ctx->r8) = ctx->r2;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808002AC: sb          $v0, 0xA0($t0)
    MEM_B(0XA0, ctx->r8) = ctx->r2;
    after_4:
    // 0x808002B0: jal         0x80101DDC
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_5;
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808002B8: beq         $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x808002BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800408;
    }
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002C4: jal         0x808008C0
    // 0x808002C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x808002C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002D4: jal         0x808008C0
    // 0x808002D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_7;
    // 0x808002D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E0: jal         0x8080041C
    // 0x808002E4: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x808002E4: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_8:
    // 0x808002E8: b           L_8080040C
    // 0x808002EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080040C;
    // 0x808002EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002F0:
    // 0x808002F0: jal         0x80101DDC
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_9;
    // 0x808002F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002F8: beq         $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x808002FC: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80800408;
    }
    // 0x808002FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800300: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080030C: jal         0x8080041C
    // 0x80800310: sb          $t1, 0x6($t2)
    MEM_B(0X6, ctx->r10) = ctx->r9;
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x80800310: sb          $t1, 0x6($t2)
    MEM_B(0X6, ctx->r10) = ctx->r9;
    after_10:
    // 0x80800314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800318: jal         0x808041E4
    // 0x8080031C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808041E4_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x8080031C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800320: b           L_8080040C
    // 0x80800324: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080040C;
    // 0x80800324: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800328:
    // 0x80800328: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x8080032C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800334: jal         0x80102320
    // 0x80800338: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80102320(rdram, ctx);
        goto after_12;
    // 0x80800338: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_12:
    // 0x8080033C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80800340: lw          $t4, 0x70($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X70);
    // 0x80800344: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800348: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0X9E24) << 16);
    // 0x8080034C: lbu         $a0, 0xA0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0XA0);
    // 0x80800350: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80800354: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800358: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080035C: addiu       $a3, $a3, -0x61DC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0X9E24));
    // 0x80800360: jal         0x80089D68
    // 0x80800364: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_13;
    // 0x80800364: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_13:
    // 0x80800368: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8080036C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800370: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9E38) << 16);
    // 0x80800374: lui         $a3, 0x3F26
    ctx->r7 = S32(0X3F26 << 16);
    // 0x80800378: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x8080037C: addiu       $a2, $a2, -0x61C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9E38));
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: jal         0x80089D20
    // 0x80800388: sb          $v0, 0xA0($t6)
    MEM_B(0XA0, ctx->r14) = ctx->r2;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_14;
    // 0x80800388: sb          $v0, 0xA0($t6)
    MEM_B(0XA0, ctx->r14) = ctx->r2;
    after_14:
    // 0x8080038C: b           L_8080040C
    // 0x80800390: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080040C;
    // 0x80800390: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800394:
    // 0x80800394: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800398: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9DB8) << 16);
    // 0x8080039C: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x808003A0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808003A4: addiu       $a2, $a2, -0x6248
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9DB8));
    // 0x808003A8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808003AC: jal         0x80089D20
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808003B4: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9DCC) << 16);
    // 0x808003B8: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x808003BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808003C0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808003C4: addiu       $a2, $a2, -0x6234
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9DCC));
    // 0x808003C8: jal         0x80089D20
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808003D0: jal         0x80101DDC
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_17;
    // 0x808003D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808003D8: beq         $v0, $zero, L_80800408
    if (ctx->r2 == 0) {
        // 0x808003DC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80800408;
    }
    // 0x808003DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808003E0: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808003EC: jal         0x8080041C
    // 0x808003F0: sb          $t7, 0x5($t8)
    MEM_B(0X5, ctx->r24) = ctx->r15;
    func_8080041C_chdiggerboss(rdram, ctx);
        goto after_18;
    // 0x808003F0: sb          $t7, 0x5($t8)
    MEM_B(0X5, ctx->r24) = ctx->r15;
    after_18:
    // 0x808003F4: jal         0x808026F8
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026F8_chdiggerboss(rdram, ctx);
        goto after_19;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808003FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800400: jal         0x80807DC0
    // 0x80800404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80807DC0_chdiggerboss(rdram, ctx);
        goto after_20;
    // 0x80800404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
L_80800408:
    // 0x80800408: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080040C:
    // 0x8080040C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800410: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800414: jr          $ra
    // 0x80800418: nop

    return;
    // 0x80800418: nop

;}
RECOMP_FUNC void func_80801BF0_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BF0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2658, 0X215C) << 16);
    // 0x80801BF4: lb          $t6, 0x215C($t6)
    ctx->r14 = MEM_B(ctx->r14, (int16_t)RELOC_LO16(2658, 0X215C));
    // 0x80801BF8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80801BFC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801C00: beq         $a1, $t6, L_80801C34
    if (ctx->r5 == ctx->r14) {
        // 0x80801C04: lui         $v0, 0x8080
        ctx->r2 = S32(RELOC_HI16(2658, 0X215C) << 16);
            goto L_80801C34;
    }
    // 0x80801C04: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2658, 0X215C) << 16);
    // 0x80801C08: addiu       $v0, $v0, 0x215C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2658, 0X215C));
L_80801C0C:
    // 0x80801C0C: beql        $a0, $zero, L_80801C24
    if (ctx->r4 == 0) {
        // 0x80801C10: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80801C24;
    }
    goto skip_0;
    // 0x80801C10: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80801C14: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x80801C18: bnel        $a0, $t7, L_80801C28
    if (ctx->r4 != ctx->r15) {
        // 0x80801C1C: lb          $t8, 0x2($v0)
        ctx->r24 = MEM_B(ctx->r2, 0X2);
            goto L_80801C28;
    }
    goto skip_1;
    // 0x80801C1C: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
    skip_1:
    // 0x80801C20: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80801C24:
    // 0x80801C24: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
L_80801C28:
    // 0x80801C28: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80801C2C: bne         $a1, $t8, L_80801C0C
    if (ctx->r5 != ctx->r24) {
        // 0x80801C30: nop
    
            goto L_80801C0C;
    }
    // 0x80801C30: nop

L_80801C34:
    // 0x80801C34: jr          $ra
    // 0x80801C38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80801C38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80802108_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802108: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080210C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802110: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802114: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802118: jal         0x80100094
    // 0x8080211C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080211C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802120: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80802124: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80802128: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8080212C: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80802130: jal         0x800FFA88
    // 0x80802134: lw          $a0, 0xA0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XA0);
    func_800FFA88(rdram, ctx);
        goto after_1;
    // 0x80802134: lw          $a0, 0xA0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XA0);
    after_1:
    // 0x80802138: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8080213C: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80802140: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802144: sw          $zero, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = 0;
    // 0x80802148: jal         0x8010114C
    // 0x8080214C: lw          $a0, 0x9C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X9C);
    func_8010114C(rdram, ctx);
        goto after_2;
    // 0x8080214C: lw          $a0, 0x9C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X9C);
    after_2:
    // 0x80802150: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80802154: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80802158: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8080215C: sw          $zero, 0x9C($t7)
    MEM_W(0X9C, ctx->r15) = 0;
    // 0x80802160: jal         0x8008A0E0
    // 0x80802164: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80802164: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x80802168: beq         $v0, $zero, L_80802178
    if (ctx->r2 == 0) {
        // 0x8080216C: addiu       $a0, $zero, 0x25
        ctx->r4 = ADD32(0, 0X25);
            goto L_80802178;
    }
    // 0x8080216C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x80802170: addiu       $t8, $sp, 0x30
    ctx->r24 = ADD32(ctx->r29, 0X30);
    // 0x80802174: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_80802178:
    // 0x80802178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080217C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80802180: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80802184: jal         0x800D10D4
    // 0x80802188: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D10D4(rdram, ctx);
        goto after_4;
    // 0x80802188: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8080218C: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80802190: jal         0x80106790
    // 0x80802194: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80802194: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x80802198: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8080219C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808021A0: beql        $a0, $zero, L_808021D4
    if (ctx->r4 == 0) {
        // 0x808021A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808021D4;
    }
    goto skip_0;
    // 0x808021A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808021A8: jal         0x80106790
    // 0x808021AC: nop

    func_80106790(rdram, ctx);
        goto after_6;
    // 0x808021AC: nop

    after_6:
    // 0x808021B0: lbu         $t0, 0x73($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X73);
    // 0x808021B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808021B8: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x808021BC: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x808021C0: sb          $t1, 0x73($v0)
    MEM_B(0X73, ctx->r2) = ctx->r9;
    // 0x808021C4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808021C8: jal         0x80802210
    // 0x808021CC: addiu       $a3, $zero, 0x438
    ctx->r7 = ADD32(0, 0X438);
    func_80802210_changlerboss(rdram, ctx);
        goto after_7;
    // 0x808021CC: addiu       $a3, $zero, 0x438
    ctx->r7 = ADD32(0, 0X438);
    after_7:
    // 0x808021D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808021D4:
    // 0x808021D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808021D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808021DC: jr          $ra
    // 0x808021E0: nop

    return;
    // 0x808021E0: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_43(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D18: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D18);
    return;
    // 0x80082D1C: addi        $t0, $zero, 0xAC
    ctx->r8 = ADD32(0, 0XAC);
;}
RECOMP_FUNC void _gspropprop_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088C30: syscall     729
    recomp_syscall_handler(rdram, ctx, 0x80088C30);
    return;
    // 0x80088C34: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80095AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095AD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80095AD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80095AD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80095ADC: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80095AE0: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x80095AE4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80095AE8: sb          $zero, 0xA3($t6)
    MEM_B(0XA3, ctx->r14) = 0;
    // 0x80095AEC: lw          $v1, 0x94($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X94);
    // 0x80095AF0: ori         $a1, $a1, 0x5
    ctx->r5 = ctx->r5 | 0X5;
    // 0x80095AF4: lbu         $v0, 0xA3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XA3);
    // 0x80095AF8: sb          $v0, 0x54($v1)
    MEM_B(0X54, ctx->r3) = ctx->r2;
    // 0x80095AFC: lw          $t7, 0x94($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X94);
    // 0x80095B00: sb          $v0, 0xA1($t7)
    MEM_B(0XA1, ctx->r15) = ctx->r2;
    // 0x80095B04: lw          $t8, 0x94($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X94);
    // 0x80095B08: sb          $v0, 0x18($t8)
    MEM_B(0X18, ctx->r24) = ctx->r2;
    // 0x80095B0C: lw          $t9, 0x94($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X94);
    // 0x80095B10: sb          $v0, 0x56($t9)
    MEM_B(0X56, ctx->r25) = ctx->r2;
    // 0x80095B14: lw          $t0, 0x94($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X94);
    // 0x80095B18: jal         0x800959FC
    // 0x80095B1C: sb          $v0, 0xA0($t0)
    MEM_B(0XA0, ctx->r8) = ctx->r2;
    func_800959FC(rdram, ctx);
        goto after_0;
    // 0x80095B1C: sb          $v0, 0xA0($t0)
    MEM_B(0XA0, ctx->r8) = ctx->r2;
    after_0:
    // 0x80095B20: jal         0x800C5A38
    // 0x80095B24: nop

    func_800C5A38(rdram, ctx);
        goto after_1;
    // 0x80095B24: nop

    after_1:
    // 0x80095B28: lw          $t1, 0x94($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X94);
    // 0x80095B2C: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x80095B30: lw          $a0, 0x94($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X94);
    // 0x80095B34: jal         0x800EFD24
    // 0x80095B38: addiu       $a0, $a0, 0x90
    ctx->r4 = ADD32(ctx->r4, 0X90);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80095B38: addiu       $a0, $a0, 0x90
    ctx->r4 = ADD32(ctx->r4, 0X90);
    after_2:
    // 0x80095B3C: lw          $a0, 0x94($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X94);
    // 0x80095B40: jal         0x800EFD24
    // 0x80095B44: addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    func_800EFD24(rdram, ctx);
        goto after_3;
    // 0x80095B44: addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    after_3:
    // 0x80095B48: lw          $a0, 0x94($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X94);
    // 0x80095B4C: jal         0x800EFD24
    // 0x80095B50: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    func_800EFD24(rdram, ctx);
        goto after_4;
    // 0x80095B50: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    after_4:
    // 0x80095B54: lw          $a0, 0x94($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X94);
    // 0x80095B58: jal         0x800EFD24
    // 0x80095B5C: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    func_800EFD24(rdram, ctx);
        goto after_5;
    // 0x80095B5C: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    after_5:
    // 0x80095B60: lw          $t2, 0x94($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X94);
    // 0x80095B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80095B68: sw          $zero, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = 0;
    // 0x80095B6C: lw          $t3, 0x94($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X94);
    // 0x80095B70: jal         0x80095A40
    // 0x80095B74: sb          $zero, 0xA2($t3)
    MEM_B(0XA2, ctx->r11) = 0;
    func_80095A40(rdram, ctx);
        goto after_6;
    // 0x80095B74: sb          $zero, 0xA2($t3)
    MEM_B(0XA2, ctx->r11) = 0;
    after_6:
    // 0x80095B78: lw          $v1, 0x94($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X94);
    // 0x80095B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80095B80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80095B84: lwc1        $f4, 0x64($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X64);
    // 0x80095B88: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80095B8C: lw          $v1, 0x94($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X94);
    // 0x80095B90: lwc1        $f6, 0x68($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80095B94: jal         0x80096254
    // 0x80095B98: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    func_80096254(rdram, ctx);
        goto after_7;
    // 0x80095B98: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    after_7:
    // 0x80095B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80095BA0: jal         0x8009590C
    // 0x80095BA4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009590C(rdram, ctx);
        goto after_8;
    // 0x80095BA4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x80095BA8: lw          $t4, 0x94($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X94);
    // 0x80095BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80095BB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80095BB4: jal         0x800961AC
    // 0x80095BB8: sw          $zero, 0x9C($t4)
    MEM_W(0X9C, ctx->r12) = 0;
    func_800961AC(rdram, ctx);
        goto after_9;
    // 0x80095BB8: sw          $zero, 0x9C($t4)
    MEM_W(0X9C, ctx->r12) = 0;
    after_9:
    // 0x80095BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80095BC0: jal         0x80095774
    // 0x80095BC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    baflag_clear(rdram, ctx);
        goto after_10;
    // 0x80095BC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80095BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80095BCC: jal         0x80095774
    // 0x80095BD0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baflag_clear(rdram, ctx);
        goto after_11;
    // 0x80095BD0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80095BD4: lw          $t6, 0x94($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X94);
    // 0x80095BD8: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x80095BDC: addiu       $t5, $t5, 0x5A6C
    ctx->r13 = ADD32(ctx->r13, 0X5A6C);
    // 0x80095BE0: sw          $t5, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r13;
    // 0x80095BE4: lw          $t8, 0x94($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X94);
    // 0x80095BE8: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x80095BEC: addiu       $t7, $t7, 0x5A64
    ctx->r15 = ADD32(ctx->r15, 0X5A64);
    // 0x80095BF0: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x80095BF4: lw          $t9, 0x94($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X94);
    // 0x80095BF8: sb          $zero, 0xA4($t9)
    MEM_B(0XA4, ctx->r25) = 0;
    // 0x80095BFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80095C00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80095C04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80095C08: jr          $ra
    // 0x80095C0C: nop

    return;
    // 0x80095C0C: nop

;}
RECOMP_FUNC void func_800EDC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDC10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EDC14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EDC18: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800EDC1C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EDC20: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800EDC24: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800EDC28: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800EDC2C: sb          $t6, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r14;
    // 0x800EDC30: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    // 0x800EDC34: swc1        $f14, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f14.u32l;
    // 0x800EDC38: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x800EDC3C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EDC40: sh          $zero, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = 0;
    // 0x800EDC44: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x800EDC48: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800EDC4C: jal         0x800ED964
    // 0x800EDC50: sh          $t7, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r15;
    func_800ED964(rdram, ctx);
        goto after_0;
    // 0x800EDC50: sh          $t7, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r15;
    after_0:
    // 0x800EDC54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EDC58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EDC5C: jr          $ra
    // 0x800EDC60: nop

    return;
    // 0x800EDC60: nop

;}
RECOMP_FUNC void func_8009514C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009514C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80095150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095154: lui         $a2, 0x3DB8
    ctx->r6 = S32(0X3DB8 << 16);
    // 0x80095158: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009515C: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x80095160: jal         0x80095124
    // 0x80095164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80095124(rdram, ctx);
        goto after_0;
    // 0x80095164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80095168: lui         $a2, 0x3DB8
    ctx->r6 = S32(0X3DB8 << 16);
    // 0x8009516C: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x80095170: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80095174: jal         0x80095124
    // 0x80095178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80095124(rdram, ctx);
        goto after_1;
    // 0x80095178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8009517C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80095180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80095184: jr          $ra
    // 0x80095188: nop

    return;
    // 0x80095188: nop

;}
RECOMP_FUNC void bsjump_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800608: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080060C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800610: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800614: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800618: jal         0x8008CABC
    // 0x8080061C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080061C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800620: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800624: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800628: jal         0x80095738
    // 0x8080062C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baflag_isTrue(rdram, ctx);
        goto after_1;
    // 0x8080062C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x80800630: beq         $v0, $zero, L_80800668
    if (ctx->r2 == 0) {
        // 0x80800634: nop
    
            goto L_80800668;
    }
    // 0x80800634: nop

    // 0x80800638: jal         0x8009BB50
    // 0x8080063C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_2;
    // 0x8080063C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80800640: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80800644: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800648: nop

    // 0x8080064C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800650: nop

    // 0x80800654: bc1f        L_80800668
    if (!c1cs) {
        // 0x80800658: nop
    
            goto L_80800668;
    }
    // 0x80800658: nop

    // 0x8080065C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800660: jal         0x8009BA58
    // 0x80800664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_3;
    // 0x80800664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
L_80800668:
    // 0x80800668: jal         0x8008AF24
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_4;
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800674: jal         0x8008AED4
    // 0x80800678: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x80800678: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    after_5:
    // 0x8080067C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800680: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800684: jal         0x8008B1C8
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_6;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080068C: lui         $a1, 0x3EC2
    ctx->r5 = S32(0X3EC2 << 16);
    // 0x80800690: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x80800694: jal         0x8008B1BC
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_7;
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080069C: jal         0x8008B064
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_8;
    // 0x808006A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808006A4: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x808006A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808006AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808006B8: jal         0x8009FFD8
    // 0x808006BC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x808006BC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x808006C0: sw          $zero, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = 0;
    // 0x808006C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006C8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808006CC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808006D0: jr          $ra
    // 0x808006D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808006D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80809384_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80809388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080938C: jal         0x80807C8C
    // 0x80809390: nop

    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80809390: nop

    after_0:
    // 0x80809394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80809398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080939C: jr          $ra
    // 0x808093A0: nop

    return;
    // 0x808093A0: nop

;}
RECOMP_FUNC void func_8080172C_chnewmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080172C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801734: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801738: jal         0x80100094
    // 0x8080173C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080173C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801740: beq         $v0, $zero, L_80801750
    if (ctx->r2 == 0) {
        // 0x80801744: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801750;
    }
    // 0x80801744: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801748: jal         0x800897C8
    // 0x8080174C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080174C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80801750:
    // 0x80801750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801758: jr          $ra
    // 0x8080175C: nop

    return;
    // 0x8080175C: nop

;}
RECOMP_FUNC void func_80800000_bsbanbflip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8009EF1C
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800014: jal         0x8009EF10
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800018: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080001C: bne         $v0, $zero, L_80800038
    if (ctx->r2 != 0) {
        // 0x80800020: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80800038;
    }
    // 0x80800020: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800028: jal         0x8009B9B0
    // 0x8080002C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080002C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800030: b           L_80800058
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800058;
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800038:
    // 0x80800038: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8080003C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800040: jal         0x800F1214
    // 0x80800044: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800044: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_3:
    // 0x80800048: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080004C: jal         0x8009B9B0
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800058:
    // 0x80800058: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_800EEFFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEFFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EF000: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EF004: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EF008: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF00C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EF010: nop

    // 0x800EF014: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EF018: jal         0x8002DCA0
    // 0x800EF01C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800EF01C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800EF020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EF024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EF028: jr          $ra
    // 0x800EF02C: nop

    return;
    // 0x800EF02C: nop

;}
RECOMP_FUNC void func_80800B78_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B80: jal         0x800883F8
    // 0x80800B84: nop

    _gcextra_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800B84: nop

    after_0:
    // 0x80800B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B90: jr          $ra
    // 0x80800B94: nop

    return;
    // 0x80800B94: nop

;}
RECOMP_FUNC void func_80800CE4_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CEC: jal         0x8009BD88
    // 0x80800CF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009BD88(rdram, ctx);
        goto after_0;
    // 0x80800CF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800CF4: jal         0x8008E95C
    // 0x80800CF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E95C(rdram, ctx);
        goto after_1;
    // 0x80800CF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800CFC: jal         0x800951B4
    // 0x80800D00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800951B4(rdram, ctx);
        goto after_2;
    // 0x80800D00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800D04: jal         0x80800104
    // 0x80800D08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800104_bsbswim(rdram, ctx);
        goto after_3;
    // 0x80800D08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D14: jr          $ra
    // 0x80800D18: nop

    return;
    // 0x80800D18: nop

;}
RECOMP_FUNC void func_80801F44_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801F48: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801F4C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801F50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801F54: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80801F58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801F5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801F60: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
L_80801F64:
    // 0x80801F64: jal         0x800F6438
    // 0x80801F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x80801F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80801F6C: beql        $v0, $zero, L_80801F8C
    if (ctx->r2 == 0) {
        // 0x80801F70: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80801F8C;
    }
    goto skip_0;
    // 0x80801F70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80801F74: jal         0x800F5EF8
    // 0x80801F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_1;
    // 0x80801F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801F7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801F80: jal         0x8010F9C0
    // 0x80801F84: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8010F9C0(rdram, ctx);
        goto after_2;
    // 0x80801F84: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80801F88: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80801F8C:
    // 0x80801F8C: bne         $s0, $s2, L_80801F64
    if (ctx->r16 != ctx->r18) {
        // 0x80801F90: nop
    
            goto L_80801F64;
    }
    // 0x80801F90: nop

    // 0x80801F94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801F98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801F9C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801FA0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801FA4: jr          $ra
    // 0x80801FA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801FA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ncbatarget_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800258: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080025C: lw          $t6, 0x58($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X58);
    // 0x80800260: jr          $ra
    // 0x80800264: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x80800264: swc1        $f12, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void chcrusherboulder_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801274: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1640, 0X14EC) << 16);
    // 0x80801278: jr          $ra
    // 0x8080127C: addiu       $v0, $v0, 0x14EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1640, 0X14EC));
    return;
    // 0x8080127C: addiu       $v0, $v0, 0x14EC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1640, 0X14EC));
;}
RECOMP_FUNC void func_8008DF18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008DF18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008DF1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008DF20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008DF24: jal         0x80091570
    // 0x8008DF28: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    bastatetimer_isActive(rdram, ctx);
        goto after_0;
    // 0x8008DF28: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x8008DF2C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008DF30: bne         $t6, $zero, L_8008DF7C
    if (ctx->r14 != 0) {
        // 0x8008DF34: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008DF7C;
    }
    // 0x8008DF34: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008DF38: jal         0x800A3378
    // 0x8008DF3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3378(rdram, ctx);
        goto after_1;
    // 0x8008DF3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008DF40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008DF44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008DF48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008DF4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8008DF50: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8008DF54: nop

    // 0x8008DF58: bc1f        L_8008DF64
    if (!c1cs) {
        // 0x8008DF5C: nop
    
            goto L_8008DF64;
    }
    // 0x8008DF5C: nop

    // 0x8008DF60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008DF64:
    // 0x8008DF64: beql        $v0, $zero, L_8008DF80
    if (ctx->r2 == 0) {
        // 0x8008DF68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008DF80;
    }
    goto skip_0;
    // 0x8008DF68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008DF6C: jal         0x8009659C
    // 0x8008DF70: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_8009659C(rdram, ctx);
        goto after_2;
    // 0x8008DF70: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_2:
    // 0x8008DF74: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008DF78: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008DF7C:
    // 0x8008DF7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008DF80:
    // 0x8008DF80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008DF84: jr          $ra
    // 0x8008DF88: nop

    return;
    // 0x8008DF88: nop

;}
