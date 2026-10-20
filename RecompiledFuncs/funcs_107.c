#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80806FAC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806FAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80806FB0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80806FB4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80806FB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80806FBC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80806FC0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80806FC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80806FC8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80806FCC: jal         0x80100094
    // 0x80806FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806FD4: lw          $t6, 0x6C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X6C);
    // 0x80806FD8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80806FDC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80806FE0: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80806FE4: beql        $t7, $zero, L_80807018
    if (ctx->r15 == 0) {
        // 0x80806FE8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80807018;
    }
    goto skip_0;
    // 0x80806FE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80806FEC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_80806FF0:
    // 0x80806FF0: jal         0x80087AF0
    // 0x80806FF4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _gczoombox_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80806FF4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x80806FF8: lw          $t8, 0x6C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X6C);
    // 0x80806FFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80807000: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80807004: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80807008: sltu        $at, $s0, $t9
    ctx->r1 = ctx->r16 < ctx->r25 ? 1 : 0;
    // 0x8080700C: bnel        $at, $zero, L_80806FF0
    if (ctx->r1 != 0) {
        // 0x80807010: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_80806FF0;
    }
    goto skip_1;
    // 0x80807010: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x80807014: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80807018:
    // 0x80807018: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080701C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80807020: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80807024: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80807028: jr          $ra
    // 0x8080702C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8080702C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _baduo_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800849C0: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x800849C0);
    return;
    // 0x800849C4: addi        $t0, $zero, 0x54
    ctx->r8 = ADD32(0, 0X54);
;}
RECOMP_FUNC void _gclevel_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088228: syscall     676
    recomp_syscall_handler(rdram, ctx, 0x80088228);
    return;
    // 0x8008822C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080000C_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800018: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080001C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800020: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800024: nop

    // 0x80800028: bne         $a1, $at, L_80800078
    if (ctx->r5 != ctx->r1) {
        // 0x8080002C: nop
    
            goto L_80800078;
    }
    // 0x8080002C: nop

    // 0x80800030: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800034: nop

    // 0x80800038: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8080003C: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80800040: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800044: jal         0x800EA05C
    // 0x80800048: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800048: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080004C: addiu       $at, $zero, 0x12B
    ctx->r1 = ADD32(0, 0X12B);
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800054: bne         $v0, $at, L_8080006C
    if (ctx->r2 != ctx->r1) {
        // 0x80800058: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8080006C;
    }
    // 0x80800058: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080005C: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x80800060: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x80800064: b           L_80800078
    // 0x80800068: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
        goto L_80800078;
    // 0x80800068: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
L_8080006C:
    // 0x8080006C: lbu         $t0, 0x65($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X65);
    // 0x80800070: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80800074: sb          $t1, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r9;
L_80800078:
    // 0x80800078: jal         0x80101FDC
    // 0x8080007C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x8080007C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800080: jal         0x80800098
    // 0x80800084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800098_chbanjoctrl(rdram, ctx);
        goto after_2;
    // 0x80800084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080008C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800090: jr          $ra
    // 0x80800094: nop

    return;
    // 0x80800094: nop

;}
RECOMP_FUNC void bsjig_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080040C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800410: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800414: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800418: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080041C: jal         0x8008CABC
    // 0x80800420: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800420: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800424: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800428: jal         0x8009E710
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800430: xori        $t6, $v0, 0x44
    ctx->r14 = ctx->r2 ^ 0X44;
    // 0x80800434: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80800438: sw          $t6, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->r14;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: jal         0x80095774
    // 0x80800444: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    baflag_clear(rdram, ctx);
        goto after_2;
    // 0x80800444: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_2:
    // 0x80800448: jal         0x8008AF24
    // 0x8080044C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_reset(rdram, ctx);
        goto after_3;
    // 0x8080044C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800450: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800454: jal         0x8008AED4
    // 0x80800458: addiu       $a1, $zero, 0x282
    ctx->r5 = ADD32(0, 0X282);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x80800458: addiu       $a1, $zero, 0x282
    ctx->r5 = ADD32(0, 0X282);
    after_4:
    // 0x8080045C: lui         $a1, 0x4066
    ctx->r5 = S32(0X4066 << 16);
    // 0x80800460: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800464: jal         0x8008B1BC
    // 0x80800468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x80800468: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8080046C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800470: jal         0x8008B134
    // 0x80800474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800478: jal         0x8008B064
    // 0x8080047C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x8080047C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    tooie_jiggy_dance_init(rdram, ctx);
    // 0x80800480: jal         0x8009F308
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F308(rdram, ctx);
        goto after_8;
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800488: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080048C: jal         0x8009C914
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_9;
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800494: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800498: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080049C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808004A8: jal         0x8009FFD8
    // 0x808004AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x808004AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_10:
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B4: jal         0x8009B9B0
    // 0x808004B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x808004B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
    // 0x808004BC: jal         0x800FC660
    // 0x808004C0: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_800FC660(rdram, ctx);
        goto after_12;
    // 0x808004C0: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_12:
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C8: jal         0x800A4DFC
    // 0x808004CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800A4DFC(rdram, ctx);
        goto after_13;
    // 0x808004CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_13:
    // 0x808004D0: jal         0x800A4C68
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_14;
    // 0x808004D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808004D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004DC: jal         0x800C52F4
    // 0x808004E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C52F4(rdram, ctx);
        goto after_15;
    // 0x808004E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: jal         0x800A0CF4
    // 0x808004EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_16;
    // 0x808004EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F4: addiu       $a1, $zero, 0x422
    ctx->r5 = ADD32(0, 0X422);
    // 0x808004F8: jal         0x8009DE38
    // 0x808004FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_17;
    // 0x808004FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_17:
    // 0x80800500: jal         0x8008E944
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_18;
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800508: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080050C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800510: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800514: jr          $ra
    // 0x80800518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800518: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ncba1p_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080056C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800570: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800574: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800578: lw          $v0, 0x4C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4C);
    // 0x8080057C: beql        $v0, $at, L_808005B4
    if (ctx->r2 == ctx->r1) {
        // 0x80800580: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808005B4;
    }
    goto skip_0;
    // 0x80800580: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x80800584: beq         $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x80800588: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808005B0;
    }
    // 0x80800588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080058C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800590: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800594: jal         0x8011607C
    // 0x80800598: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_8011607C(rdram, ctx);
        goto after_0;
    // 0x80800598: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080059C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808005A4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x808005A8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x808005AC: lw          $v0, 0x4C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4C);
L_808005B0:
    // 0x808005B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_808005B4:
    // 0x808005B4: beq         $v0, $at, L_808005DC
    if (ctx->r2 == ctx->r1) {
        // 0x808005B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808005DC;
    }
    // 0x808005B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005BC: beq         $v0, $at, L_808005EC
    if (ctx->r2 == ctx->r1) {
        // 0x808005C0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808005EC;
    }
    // 0x808005C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005C4: beq         $v0, $at, L_808005FC
    if (ctx->r2 == ctx->r1) {
        // 0x808005C8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808005FC;
    }
    // 0x808005C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808005CC: beql        $v0, $at, L_80800608
    if (ctx->r2 == ctx->r1) {
        // 0x808005D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800608;
    }
    goto skip_1;
    // 0x808005D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808005D4: b           L_80800608
    // 0x808005D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800608;
    // 0x808005D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005DC:
    // 0x808005DC: jal         0x808000A0
    // 0x808005E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_808000A0_ncba1p(rdram, ctx);
        goto after_1;
    // 0x808005E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x808005E4: b           L_80800608
    // 0x808005E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800608;
    // 0x808005E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005EC:
    // 0x808005EC: jal         0x808003DC
    // 0x808005F0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_808003DC_ncba1p(rdram, ctx);
        goto after_2;
    // 0x808005F0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
    // 0x808005F4: b           L_80800608
    // 0x808005F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800608;
    // 0x808005F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005FC:
    // 0x808005FC: jal         0x80800230
    // 0x80800600: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80800230_ncba1p(rdram, ctx);
        goto after_3;
    // 0x80800600: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_3:
    // 0x80800604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800608:
    // 0x80800608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080060C: jr          $ra
    // 0x80800610: nop

    return;
    // 0x80800610: nop

;}
RECOMP_FUNC void func_8080145C_mlspline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080145C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801464: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801468: jalr        $a0
    // 0x8080146C: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    LOOKUP_FUNC(ctx->r4)(rdram, ctx);
        goto after_0;
    // 0x8080146C: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80801470: jal         0x800EEF94
    // 0x80801474: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800EEF94(rdram, ctx);
        goto after_1;
    // 0x80801474: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80801478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080147C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801480: jr          $ra
    // 0x80801484: nop

    return;
    // 0x80801484: nop

;}
RECOMP_FUNC void func_808003C4_chcrystalbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003D0: jal         0x80102424
    // 0x808003D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x808003D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808003D8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808003DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003E0: beq         $a1, $at, L_80800414
    if (ctx->r5 == ctx->r1) {
        // 0x808003E4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800414;
    }
    // 0x808003E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808003E8: bne         $a1, $at, L_80800414
    if (ctx->r5 != ctx->r1) {
        // 0x808003EC: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_80800414;
    }
    // 0x808003EC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x808003F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808003F4: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x808003F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808003FC: jal         0x800DC178
    // 0x80800400: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800400: nop

    after_1:
    // 0x80800404: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80800408: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080040C: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x80800410: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
L_80800414:
    // 0x80800414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080041C: jr          $ra
    // 0x80800420: nop

    return;
    // 0x80800420: nop

;}
RECOMP_FUNC void func_80800494_chchuffycont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800494: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800498: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080049C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808004A0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808004A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004A8: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808004AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808004B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808004B4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808004B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808004BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808004C0: addiu       $s4, $zero, 0x7
    ctx->r20 = ADD32(0, 0X7);
L_808004C4:
    // 0x808004C4: jal         0x808006A4
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808006A4_chchuffycont(rdram, ctx);
        goto after_0;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808004CC: beq         $v0, $zero, L_80800514
    if (ctx->r2 == 0) {
        // 0x808004D0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800514;
    }
    // 0x808004D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808004D4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x808004D8: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x808004DC: addiu       $a2, $s0, 0xA
    ctx->r6 = ADD32(ctx->r16, 0XA);
    // 0x808004E0: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1704, 0XB20) << 16);
    // 0x808004E4: addiu       $t9, $t9, 0xB20
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1704, 0XB20));
    // 0x808004E8: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x808004EC: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x808004F0: addu        $s2, $t8, $t9
    ctx->r18 = ADD32(ctx->r24, ctx->r25);
    // 0x808004F4: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x808004F8: jal         0x80087CF8
    // 0x808004FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x808004FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80800500: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800504: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800508: jal         0x80087D90
    // 0x8080050C: lh          $a2, 0x8($s2)
    ctx->r6 = MEM_H(ctx->r18, 0X8);
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_2;
    // 0x8080050C: lh          $a2, 0x8($s2)
    ctx->r6 = MEM_H(ctx->r18, 0X8);
    after_2:
    // 0x80800510: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800514:
    // 0x80800514: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800518: bne         $s0, $s4, L_808004C4
    if (ctx->r16 != ctx->r20) {
        // 0x8080051C: nop
    
            goto L_808004C4;
    }
    // 0x8080051C: nop

    // 0x80800520: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800524: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800528: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080052C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800530: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800534: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800538: jr          $ra
    // 0x8080053C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080053C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800D5EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5EB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D5EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5EBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D5EC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D5EC4: jal         0x800D5AB4
    // 0x800D5EC8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_800D5AB4(rdram, ctx);
        goto after_0;
    // 0x800D5EC8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D5ECC: bgez        $v0, L_800D5EDC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D5ED0: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_800D5EDC;
    }
    // 0x800D5ED0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800D5ED4: b           L_800D5FCC
    // 0x800D5ED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D5FCC;
    // 0x800D5ED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D5EDC:
    // 0x800D5EDC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D5EE0: lw          $t7, -0x4700($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4700);
    // 0x800D5EE4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800D5EE8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5EEC: addiu       $a1, $a1, -0x4BC0
    ctx->r5 = ADD32(ctx->r5, -0X4BC0);
    // 0x800D5EF0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800D5EF4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800D5EF8: jal         0x8001E210
    // 0x800D5EFC: addu        $a0, $t7, $t6
    ctx->r4 = ADD32(ctx->r15, ctx->r14);
    rom_read_word(rdram, ctx);
        goto after_1;
    // 0x800D5EFC: addu        $a0, $t7, $t6
    ctx->r4 = ADD32(ctx->r15, ctx->r14);
    after_1:
    // 0x800D5F00: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D5F04: lw          $t8, -0x4BC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BC0);
    // 0x800D5F08: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800D5F0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800D5F10: sll         $t9, $t8, 26
    ctx->r25 = S32(ctx->r24 << 26);
    // 0x800D5F14: srl         $t0, $t9, 30
    ctx->r8 = S32(U32(ctx->r25) >> 30);
    // 0x800D5F18: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x800D5F1C: beq         $t1, $zero, L_800D5F3C
    if (ctx->r9 == 0) {
        // 0x800D5F20: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800D5F3C;
    }
    // 0x800D5F20: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800D5F24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D5F28: jal         0x800E6950
    // 0x800D5F2C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800E6950(rdram, ctx);
        goto after_2;
    // 0x800D5F2C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x800D5F30: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D5F34: b           L_800D5FC8
    // 0x800D5F38: lw          $v1, -0x4818($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4818);
        goto L_800D5FC8;
    // 0x800D5F38: lw          $v1, -0x4818($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4818);
L_800D5F3C:
    // 0x800D5F3C: lw          $t2, -0x4700($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X4700);
    // 0x800D5F40: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D5F44: addiu       $a1, $a1, -0x4BBC
    ctx->r5 = ADD32(ctx->r5, -0X4BBC);
    // 0x800D5F48: addu        $a0, $t2, $v1
    ctx->r4 = ADD32(ctx->r10, ctx->r3);
    // 0x800D5F4C: jal         0x8001E210
    // 0x800D5F50: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    rom_read_word(rdram, ctx);
        goto after_3;
    // 0x800D5F50: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_3:
    // 0x800D5F54: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800D5F58: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800D5F5C: lw          $t4, -0x4BBC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4BBC);
    // 0x800D5F60: lw          $a3, -0x4BC0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BC0);
    // 0x800D5F64: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800D5F68: srl         $t5, $t4, 6
    ctx->r13 = S32(U32(ctx->r12) >> 6);
    // 0x800D5F6C: srl         $t3, $a3, 6
    ctx->r11 = S32(U32(ctx->r7) >> 6);
    // 0x800D5F70: subu        $a2, $t5, $t3
    ctx->r6 = SUB32(ctx->r13, ctx->r11);
    // 0x800D5F74: andi        $t6, $a2, 0x1
    ctx->r14 = ctx->r6 & 0X1;
    // 0x800D5F78: beq         $t6, $zero, L_800D5F84
    if (ctx->r14 == 0) {
        // 0x800D5F7C: or          $a3, $t3, $zero
        ctx->r7 = ctx->r11 | 0;
            goto L_800D5F84;
    }
    // 0x800D5F7C: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x800D5F80: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800D5F84:
    // 0x800D5F84: andi        $v0, $a2, 0xF
    ctx->r2 = ctx->r6 & 0XF;
    // 0x800D5F88: beq         $v0, $zero, L_800D5F98
    if (ctx->r2 == 0) {
        // 0x800D5F8C: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_800D5F98;
    }
    // 0x800D5F8C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800D5F90: subu        $v1, $a2, $v0
    ctx->r3 = SUB32(ctx->r6, ctx->r2);
    // 0x800D5F94: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_800D5F98:
    // 0x800D5F98: slt         $at, $t7, $a2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800D5F9C: bne         $at, $zero, L_800D5FC0
    if (ctx->r1 != 0) {
        // 0x800D5FA0: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_800D5FC0;
    }
    // 0x800D5FA0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800D5FA4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D5FA8: lw          $t8, -0x4BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BB8);
    // 0x800D5FAC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800D5FB0: jal         0x80012F78
    // 0x800D5FB4: addu        $a1, $t8, $a3
    ctx->r5 = ADD32(ctx->r24, ctx->r7);
    rom_dma_read(rdram, ctx);
        goto after_4;
    // 0x800D5FB4: addu        $a1, $t8, $a3
    ctx->r5 = ADD32(ctx->r24, ctx->r7);
    after_4:
    // 0x800D5FB8: b           L_800D5FC8
    // 0x800D5FBC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_800D5FC8;
    // 0x800D5FBC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_800D5FC0:
    // 0x800D5FC0: b           L_800D5FCC
    // 0x800D5FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D5FCC;
    // 0x800D5FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D5FC8:
    // 0x800D5FC8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800D5FCC:
    // 0x800D5FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D5FD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D5FD4: jr          $ra
    // 0x800D5FD8: nop

    return;
    // 0x800D5FD8: nop

;}
RECOMP_FUNC void func_8080154C_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080154C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801550: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801558: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080155C: jal         0x800DC298
    // 0x80801560: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x80801560: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801564: beq         $v0, $zero, L_8080157C
    if (ctx->r2 == 0) {
        // 0x80801568: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8080157C;
    }
    // 0x80801568: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080156C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801570: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80801574: b           L_80801588
    // 0x80801578: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
        goto L_80801588;
    // 0x80801578: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_8080157C:
    // 0x8080157C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80801580: nop

    // 0x80801584: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_80801588:
    // 0x80801588: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080158C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80801590: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801594: jal         0x800DC178
    // 0x80801598: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80801598: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8080159C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808015A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808015A4: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808015A8: jal         0x80089CA0
    // 0x808015AC: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808015AC: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    after_2:
    // 0x808015B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808015B4: jal         0x8010A800
    // 0x808015B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_3;
    // 0x808015B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808015BC: jal         0x80801AFC
    // 0x808015C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80801AFC_chballoonburst(rdram, ctx);
        goto after_4;
    // 0x808015C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x808015C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808015C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808015CC: jr          $ra
    // 0x808015D0: nop

    return;
    // 0x808015D0: nop

;}
RECOMP_FUNC void func_800FD2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD2A0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FD2A4: addiu       $v1, $v1, 0x59C0
    ctx->r3 = ADD32(ctx->r3, 0X59C0);
    // 0x800FD2A8: lh          $t6, 0x20($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X20);
    // 0x800FD2AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FD2B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FD2B4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800FD2B8: sltiu       $at, $t7, 0x17
    ctx->r1 = ctx->r15 < 0X17 ? 1 : 0;
    // 0x800FD2BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800FD2C0: beq         $at, $zero, L_800FDBA8
    if (ctx->r1 == 0) {
        // 0x800FD2C4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800FDBA8;
    }
    // 0x800FD2C4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800FD2C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800FD2CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FD2D0: addu        $at, $at, $t7
    gpr jr_addend_800FD2D8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800FD2D4: lw          $t7, 0x6160($at)
    ctx->r15 = ADD32(ctx->r1, 0X6160);
    // 0x800FD2D8: jr          $t7
    // 0x800FD2DC: nop

    switch (jr_addend_800FD2D8 >> 2) {
        case 0: goto L_800FD2E0; break;
        case 1: goto L_800FDBA8; break;
        case 2: goto L_800FDBA8; break;
        case 3: goto L_800FDBA8; break;
        case 4: goto L_800FD8AC; break;
        case 5: goto L_800FD8EC; break;
        case 6: goto L_800FD3F8; break;
        case 7: goto L_800FD924; break;
        case 8: goto L_800FD994; break;
        case 9: goto L_800FD9CC; break;
        case 10: goto L_800FDA04; break;
        case 11: goto L_800FD414; break;
        case 12: goto L_800FD444; break;
        case 13: goto L_800FD47C; break;
        case 14: goto L_800FDA3C; break;
        case 15: goto L_800FDB4C; break;
        case 16: goto L_800FD5C0; break;
        case 17: goto L_800FD634; break;
        case 18: goto L_800FD788; break;
        case 19: goto L_800FD570; break;
        case 20: goto L_800FD4E8; break;
        case 21: goto L_800FD840; break;
        case 22: goto L_800FD538; break;
        default: switch_error(__func__, 0x800FD2D8, 0x80126160);
    }
    // 0x800FD2DC: nop

L_800FD2E0:
    // 0x800FD2E0: lw          $a0, 0x28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X28);
    // 0x800FD2E4: jal         0x800CBBE0
    // 0x800FD2E8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800CBBE0(rdram, ctx);
        goto after_0;
    // 0x800FD2E8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x800FD2EC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800FD2F0: beq         $v0, $a0, L_800FD3A8
    if (ctx->r2 == ctx->r4) {
        // 0x800FD2F4: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_800FD3A8;
    }
    // 0x800FD2F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800FD2F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800FD2FC: bne         $v0, $at, L_800FDBA8
    if (ctx->r2 != ctx->r1) {
        // 0x800FD300: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800FDBA8;
    }
    // 0x800FD300: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800FD304: addiu       $v0, $v0, 0x41E4
    ctx->r2 = ADD32(ctx->r2, 0X41E4);
    // 0x800FD308: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800FD30C: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800FD310: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800FD314: addiu       $t8, $t8, 0x3F68
    ctx->r24 = ADD32(ctx->r24, 0X3F68);
    // 0x800FD318: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800FD31C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD320: bc1t        L_800FD368
    if (c1cs) {
        // 0x800FD324: nop
    
            goto L_800FD368;
    }
    // 0x800FD324: nop

    // 0x800FD328: lwc1        $f2, 0x8($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800FD32C: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800FD330: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800FD334: nop

    // 0x800FD338: bc1t        L_800FD368
    if (c1cs) {
        // 0x800FD33C: nop
    
            goto L_800FD368;
    }
    // 0x800FD33C: nop

    // 0x800FD340: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FD344: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800FD348: nop

    // 0x800FD34C: bc1t        L_800FD368
    if (c1cs) {
        // 0x800FD350: nop
    
            goto L_800FD368;
    }
    // 0x800FD350: nop

    // 0x800FD354: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800FD358: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x800FD35C: nop

    // 0x800FD360: bc1fl       L_800FD374
    if (!c1cs) {
        // 0x800FD364: add.s       $f8, $f0, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_800FD374;
    }
    goto skip_0;
    // 0x800FD364: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    skip_0:
L_800FD368:
    // 0x800FD368: b           L_800FD398
    // 0x800FD36C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FD398;
    // 0x800FD36C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FD370: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
L_800FD374:
    // 0x800FD374: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800FD378: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800FD37C: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x800FD380: nop

    // 0x800FD384: bc1f        L_800FD394
    if (!c1cs) {
        // 0x800FD388: nop
    
            goto L_800FD394;
    }
    // 0x800FD388: nop

    // 0x800FD38C: b           L_800FD394
    // 0x800FD390: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800FD394;
    // 0x800FD390: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800FD394:
    // 0x800FD394: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800FD398:
    // 0x800FD398: bnel        $v0, $a0, L_800FDBAC
    if (ctx->r2 != ctx->r4) {
        // 0x800FD39C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800FDBAC;
    }
    goto skip_1;
    // 0x800FD39C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800FD3A0: b           L_800FDBA8
    // 0x800FD3A4: sw          $t8, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r24;
        goto L_800FDBA8;
    // 0x800FD3A4: sw          $t8, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r24;
L_800FD3A8:
    // 0x800FD3A8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x800FD3AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800FD3B0: lwc1        $f18, 0x4($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800FD3B4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD3B8: addiu       $a2, $a2, 0x3E84
    ctx->r6 = ADD32(ctx->r6, 0X3E84);
    // 0x800FD3BC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800FD3C0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD3C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD3C8: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // 0x800FD3CC: bc1fl       L_800FDBAC
    if (!c1cs) {
        // 0x800FD3D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800FDBAC;
    }
    goto skip_2;
    // 0x800FD3D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800FD3D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FD3D8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD3DC: jal         0x800FCFB0
    // 0x800FD3E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_1;
    // 0x800FD3E0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800FD3E4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800FD3E8: addiu       $t9, $t9, 0x3FC8
    ctx->r25 = ADD32(ctx->r25, 0X3FC8);
    // 0x800FD3EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD3F0: b           L_800FDBA8
    // 0x800FD3F4: sw          $t9, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r25;
        goto L_800FDBA8;
    // 0x800FD3F4: sw          $t9, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r25;
L_800FD3F8:
    // 0x800FD3F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD3FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800FD400: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800FD404: jal         0x800FEDC4
    // 0x800FD408: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    func_800FEDC4(rdram, ctx);
        goto after_2;
    // 0x800FD408: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    after_2:
    // 0x800FD40C: b           L_800FDBAC
    // 0x800FD410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800FDBAC;
    // 0x800FD410: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FD414:
    // 0x800FD414: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD418: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800FD41C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800FD420: jal         0x800FEDC4
    // 0x800FD424: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    func_800FEDC4(rdram, ctx);
        goto after_3;
    // 0x800FD424: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    after_3:
    // 0x800FD428: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800FD42C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FD430: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800FD434: jal         0x800FEDC4
    // 0x800FD438: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    func_800FEDC4(rdram, ctx);
        goto after_4;
    // 0x800FD438: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    after_4:
    // 0x800FD43C: b           L_800FDBAC
    // 0x800FD440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800FDBAC;
    // 0x800FD440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FD444:
    // 0x800FD444: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x800FD448: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x800FD44C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD450: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800FD454: jal         0x800FEDC4
    // 0x800FD458: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    func_800FEDC4(rdram, ctx);
        goto after_5;
    // 0x800FD458: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    after_5:
    // 0x800FD45C: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x800FD460: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x800FD464: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800FD468: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FD46C: jal         0x800FEDC4
    // 0x800FD470: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    func_800FEDC4(rdram, ctx);
        goto after_6;
    // 0x800FD470: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    after_6:
    // 0x800FD474: b           L_800FDBAC
    // 0x800FD478: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800FDBAC;
    // 0x800FD478: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FD47C:
    // 0x800FD47C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800FD480: addiu       $a1, $a1, 0x41F4
    ctx->r5 = ADD32(ctx->r5, 0X41F4);
    // 0x800FD484: jal         0x800EEAD4
    // 0x800FD488: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_7;
    // 0x800FD488: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_7:
    // 0x800FD48C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800FD490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FD494: lui         $a2, 0x455A
    ctx->r6 = S32(0X455A << 16);
    // 0x800FD498: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x800FD49C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800FD4A0: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x800FD4A4: lwc1        $f14, 0x61BC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X61BC);
    // 0x800FD4A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800FD4AC: jal         0x800F10B4
    // 0x800FD4B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x800FD4B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x800FD4B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800FD4B8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800FD4BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD4C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800FD4C4: jal         0x800FEDC4
    // 0x800FD4C8: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    func_800FEDC4(rdram, ctx);
        goto after_9;
    // 0x800FD4C8: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    after_9:
    // 0x800FD4CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800FD4D0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FD4D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800FD4D8: jal         0x800FEDC4
    // 0x800FD4DC: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    func_800FEDC4(rdram, ctx);
        goto after_10;
    // 0x800FD4DC: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    after_10:
    // 0x800FD4E0: b           L_800FDBAC
    // 0x800FD4E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800FDBAC;
    // 0x800FD4E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FD4E8:
    // 0x800FD4E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800FD4EC: addiu       $a1, $a1, 0x4200
    ctx->r5 = ADD32(ctx->r5, 0X4200);
    // 0x800FD4F0: jal         0x800EEAD4
    // 0x800FD4F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_11;
    // 0x800FD4F4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_11:
    // 0x800FD4F8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800FD4FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FD500: lui         $a2, 0x459C
    ctx->r6 = S32(0X459C << 16);
    // 0x800FD504: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x800FD508: lwc1        $f14, 0x61C0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X61C0);
    // 0x800FD50C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800FD510: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800FD514: jal         0x800F10B4
    // 0x800FD518: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x800FD518: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x800FD51C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800FD520: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD524: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800FD528: jal         0x800FEDC4
    // 0x800FD52C: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    func_800FEDC4(rdram, ctx);
        goto after_13;
    // 0x800FD52C: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    after_13:
    // 0x800FD530: b           L_800FDBAC
    // 0x800FD534: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800FDBAC;
    // 0x800FD534: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FD538:
    // 0x800FD538: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x800FD53C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x800FD540: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD544: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800FD548: jal         0x800FEDC4
    // 0x800FD54C: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    func_800FEDC4(rdram, ctx);
        goto after_14;
    // 0x800FD54C: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    after_14:
    // 0x800FD550: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x800FD554: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x800FD558: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800FD55C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800FD560: jal         0x800FEDC4
    // 0x800FD564: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    func_800FEDC4(rdram, ctx);
        goto after_15;
    // 0x800FD564: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    after_15:
    // 0x800FD568: b           L_800FDBAC
    // 0x800FD56C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800FDBAC;
    // 0x800FD56C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FD570:
    // 0x800FD570: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800FD574: addiu       $a1, $a1, 0x420C
    ctx->r5 = ADD32(ctx->r5, 0X420C);
    // 0x800FD578: jal         0x800EEAD4
    // 0x800FD57C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_16;
    // 0x800FD57C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_16:
    // 0x800FD580: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800FD584: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FD588: lui         $a2, 0x455A
    ctx->r6 = S32(0X455A << 16);
    // 0x800FD58C: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x800FD590: lwc1        $f14, 0x61C4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X61C4);
    // 0x800FD594: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800FD598: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x800FD59C: jal         0x800F10B4
    // 0x800FD5A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_17;
    // 0x800FD5A0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_17:
    // 0x800FD5A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800FD5A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD5AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800FD5B0: jal         0x800FEDC4
    // 0x800FD5B4: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    func_800FEDC4(rdram, ctx);
        goto after_18;
    // 0x800FD5B4: lui         $a3, 0x3FE0
    ctx->r7 = S32(0X3FE0 << 16);
    after_18:
    // 0x800FD5B8: b           L_800FDBAC
    // 0x800FD5BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800FDBAC;
    // 0x800FD5BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FD5C0:
    // 0x800FD5C0: jal         0x80087F38
    // 0x800FD5C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _gcmapsects_entrypoint_7(rdram, ctx);
        goto after_19;
    // 0x800FD5C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_19:
    // 0x800FD5C8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FD5CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FD5D0: beq         $v0, $at, L_800FD5E0
    if (ctx->r2 == ctx->r1) {
        // 0x800FD5D4: addiu       $v1, $v1, 0x59C0
        ctx->r3 = ADD32(ctx->r3, 0X59C0);
            goto L_800FD5E0;
    }
    // 0x800FD5D4: addiu       $v1, $v1, 0x59C0
    ctx->r3 = ADD32(ctx->r3, 0X59C0);
    // 0x800FD5D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD5DC: sb          $v0, 0x59D1($at)
    MEM_B(0X59D1, ctx->r1) = ctx->r2;
L_800FD5E0:
    // 0x800FD5E0: lbu         $v0, 0x11($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X11);
    // 0x800FD5E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800FD5E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800FD5EC: beq         $v0, $a0, L_800FD600
    if (ctx->r2 == ctx->r4) {
        // 0x800FD5F0: addiu       $a1, $zero, 0x4B
        ctx->r5 = ADD32(0, 0X4B);
            goto L_800FD600;
    }
    // 0x800FD5F0: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD5F4: beq         $v0, $at, L_800FD600
    if (ctx->r2 == ctx->r1) {
        // 0x800FD5F8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800FD600;
    }
    // 0x800FD5F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800FD5FC: bne         $v0, $at, L_800FDBA8
    if (ctx->r2 != ctx->r1) {
        // 0x800FD600: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_800FDBA8;
    }
L_800FD600:
    // 0x800FD600: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD604: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800FD608: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD60C: addiu       $a2, $a2, 0x401C
    ctx->r6 = ADD32(ctx->r6, 0X401C);
    // 0x800FD610: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD614: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD618: jal         0x800FCFB0
    // 0x800FD61C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_20;
    // 0x800FD61C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_20:
    // 0x800FD620: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800FD624: addiu       $t0, $t0, 0x4010
    ctx->r8 = ADD32(ctx->r8, 0X4010);
    // 0x800FD628: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD62C: b           L_800FDBA8
    // 0x800FD630: sw          $t0, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r8;
        goto L_800FDBA8;
    // 0x800FD630: sw          $t0, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r8;
L_800FD634:
    // 0x800FD634: jal         0x80087F38
    // 0x800FD638: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _gcmapsects_entrypoint_7(rdram, ctx);
        goto after_21;
    // 0x800FD638: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_21:
    // 0x800FD63C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FD640: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FD644: beq         $v0, $at, L_800FD654
    if (ctx->r2 == ctx->r1) {
        // 0x800FD648: addiu       $v1, $v1, 0x59C0
        ctx->r3 = ADD32(ctx->r3, 0X59C0);
            goto L_800FD654;
    }
    // 0x800FD648: addiu       $v1, $v1, 0x59C0
    ctx->r3 = ADD32(ctx->r3, 0X59C0);
    // 0x800FD64C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD650: sb          $v0, 0x59D1($at)
    MEM_B(0X59D1, ctx->r1) = ctx->r2;
L_800FD654:
    // 0x800FD654: lbu         $v0, 0x11($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X11);
    // 0x800FD658: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800FD65C: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD660: beq         $v0, $zero, L_800FD6E4
    if (ctx->r2 == 0) {
        // 0x800FD664: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800FD6E4;
    }
    // 0x800FD664: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD668: beq         $v0, $at, L_800FD71C
    if (ctx->r2 == ctx->r1) {
        // 0x800FD66C: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_800FD71C;
    }
    // 0x800FD66C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800FD670: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800FD674: beq         $v0, $a0, L_800FD6E4
    if (ctx->r2 == ctx->r4) {
        // 0x800FD678: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800FD6E4;
    }
    // 0x800FD678: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800FD67C: bne         $v0, $at, L_800FDBA8
    if (ctx->r2 != ctx->r1) {
        // 0x800FD680: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_800FDBA8;
    }
    // 0x800FD680: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD684: beq         $a3, $zero, L_800FD6B4
    if (ctx->r7 == 0) {
        // 0x800FD688: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800FD6B4;
    }
    // 0x800FD688: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD68C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD690: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800FD694: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD698: addiu       $a2, $a2, 0x401C
    ctx->r6 = ADD32(ctx->r6, 0X401C);
    // 0x800FD69C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD6A0: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD6A4: jal         0x800FCFB0
    // 0x800FD6A8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_22;
    // 0x800FD6A8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_22:
    // 0x800FD6AC: b           L_800FD6D0
    // 0x800FD6B0: nop

        goto L_800FD6D0;
    // 0x800FD6B0: nop

L_800FD6B4:
    // 0x800FD6B4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD6B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FD6BC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD6C0: addiu       $a2, $a2, 0x4004
    ctx->r6 = ADD32(ctx->r6, 0X4004);
    // 0x800FD6C4: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD6C8: jal         0x800FCFB0
    // 0x800FD6CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_23;
    // 0x800FD6CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_23:
L_800FD6D0:
    // 0x800FD6D0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800FD6D4: addiu       $t1, $t1, 0x4010
    ctx->r9 = ADD32(ctx->r9, 0X4010);
    // 0x800FD6D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD6DC: b           L_800FDBA8
    // 0x800FD6E0: sw          $t1, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r9;
        goto L_800FDBA8;
    // 0x800FD6E0: sw          $t1, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r9;
L_800FD6E4:
    // 0x800FD6E4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD6E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FD6EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD6F0: addiu       $a2, $a2, 0x401C
    ctx->r6 = ADD32(ctx->r6, 0X401C);
    // 0x800FD6F4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD6F8: jal         0x800FCFB0
    // 0x800FD6FC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_24;
    // 0x800FD6FC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_24:
    // 0x800FD700: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800FD704: addiu       $t2, $t2, 0x4010
    ctx->r10 = ADD32(ctx->r10, 0X4010);
    // 0x800FD708: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD70C: sw          $t2, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r10;
    // 0x800FD710: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD714: b           L_800FDBA8
    // 0x800FD718: sb          $zero, 0x5A1E($at)
    MEM_B(0X5A1E, ctx->r1) = 0;
        goto L_800FDBA8;
    // 0x800FD718: sb          $zero, 0x5A1E($at)
    MEM_B(0X5A1E, ctx->r1) = 0;
L_800FD71C:
    // 0x800FD71C: lbu         $t3, 0x5A1E($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X5A1E);
    // 0x800FD720: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD724: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD728: beq         $t3, $zero, L_800FD75C
    if (ctx->r11 == 0) {
        // 0x800FD72C: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800FD75C;
    }
    // 0x800FD72C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD730: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD734: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FD738: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD73C: addiu       $a2, $a2, 0x4028
    ctx->r6 = ADD32(ctx->r6, 0X4028);
    // 0x800FD740: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD744: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD748: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD74C: jal         0x800FCFB0
    // 0x800FD750: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_25;
    // 0x800FD750: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_25:
    // 0x800FD754: b           L_800FD774
    // 0x800FD758: nop

        goto L_800FD774;
    // 0x800FD758: nop

L_800FD75C:
    // 0x800FD75C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD760: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FD764: addiu       $a2, $a2, 0x401C
    ctx->r6 = ADD32(ctx->r6, 0X401C);
    // 0x800FD768: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD76C: jal         0x800FCFB0
    // 0x800FD770: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_26;
    // 0x800FD770: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_26:
L_800FD774:
    // 0x800FD774: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800FD778: addiu       $t4, $t4, 0x4010
    ctx->r12 = ADD32(ctx->r12, 0X4010);
    // 0x800FD77C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD780: b           L_800FDBA8
    // 0x800FD784: sw          $t4, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r12;
        goto L_800FDBA8;
    // 0x800FD784: sw          $t4, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r12;
L_800FD788:
    // 0x800FD788: jal         0x80087F38
    // 0x800FD78C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _gcmapsects_entrypoint_7(rdram, ctx);
        goto after_27;
    // 0x800FD78C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_27:
    // 0x800FD790: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FD794: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FD798: beq         $v0, $at, L_800FD7A8
    if (ctx->r2 == ctx->r1) {
        // 0x800FD79C: addiu       $v1, $v1, 0x59C0
        ctx->r3 = ADD32(ctx->r3, 0X59C0);
            goto L_800FD7A8;
    }
    // 0x800FD79C: addiu       $v1, $v1, 0x59C0
    ctx->r3 = ADD32(ctx->r3, 0X59C0);
    // 0x800FD7A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD7A4: sb          $v0, 0x59D1($at)
    MEM_B(0X59D1, ctx->r1) = ctx->r2;
L_800FD7A8:
    // 0x800FD7A8: lbu         $v0, 0x11($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X11);
    // 0x800FD7AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800FD7B0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD7B4: beq         $v0, $zero, L_800FD7D4
    if (ctx->r2 == 0) {
        // 0x800FD7B8: nop
    
            goto L_800FD7D4;
    }
    // 0x800FD7B8: nop

    // 0x800FD7BC: beq         $v0, $at, L_800FD7D4
    if (ctx->r2 == ctx->r1) {
        // 0x800FD7C0: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_800FD7D4;
    }
    // 0x800FD7C0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800FD7C4: beq         $v0, $a0, L_800FD7D4
    if (ctx->r2 == ctx->r4) {
        // 0x800FD7C8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800FD7D4;
    }
    // 0x800FD7C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800FD7CC: bnel        $v0, $at, L_800FDBAC
    if (ctx->r2 != ctx->r1) {
        // 0x800FD7D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800FDBAC;
    }
    goto skip_3;
    // 0x800FD7D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_800FD7D4:
    // 0x800FD7D4: beq         $a3, $zero, L_800FD804
    if (ctx->r7 == 0) {
        // 0x800FD7D8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800FD804;
    }
    // 0x800FD7D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD7DC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD7E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800FD7E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD7E8: addiu       $a2, $a2, 0x4028
    ctx->r6 = ADD32(ctx->r6, 0X4028);
    // 0x800FD7EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD7F0: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD7F4: jal         0x800FCFB0
    // 0x800FD7F8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_28;
    // 0x800FD7F8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_28:
    // 0x800FD7FC: b           L_800FD820
    // 0x800FD800: nop

        goto L_800FD820;
    // 0x800FD800: nop

L_800FD804:
    // 0x800FD804: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD808: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800FD80C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD810: addiu       $a2, $a2, 0x4004
    ctx->r6 = ADD32(ctx->r6, 0X4004);
    // 0x800FD814: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD818: jal         0x800FCFB0
    // 0x800FD81C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_29;
    // 0x800FD81C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_29:
L_800FD820:
    // 0x800FD820: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800FD824: addiu       $t5, $t5, 0x4010
    ctx->r13 = ADD32(ctx->r13, 0X4010);
    // 0x800FD828: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD82C: sw          $t5, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r13;
    // 0x800FD830: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD834: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800FD838: b           L_800FDBA8
    // 0x800FD83C: sb          $t6, 0x5A1E($at)
    MEM_B(0X5A1E, ctx->r1) = ctx->r14;
        goto L_800FDBA8;
    // 0x800FD83C: sb          $t6, 0x5A1E($at)
    MEM_B(0X5A1E, ctx->r1) = ctx->r14;
L_800FD840:
    // 0x800FD840: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD844: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD848: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD84C: beq         $t7, $zero, L_800FD880
    if (ctx->r15 == 0) {
        // 0x800FD850: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800FD880;
    }
    // 0x800FD850: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD854: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD858: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FD85C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD860: addiu       $a2, $a2, 0x401C
    ctx->r6 = ADD32(ctx->r6, 0X401C);
    // 0x800FD864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD868: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD86C: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800FD870: jal         0x800FCFB0
    // 0x800FD874: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_30;
    // 0x800FD874: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_30:
    // 0x800FD878: b           L_800FD898
    // 0x800FD87C: nop

        goto L_800FD898;
    // 0x800FD87C: nop

L_800FD880:
    // 0x800FD880: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD884: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FD888: addiu       $a2, $a2, 0x4004
    ctx->r6 = ADD32(ctx->r6, 0X4004);
    // 0x800FD88C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD890: jal         0x800FCFB0
    // 0x800FD894: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_31;
    // 0x800FD894: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_31:
L_800FD898:
    // 0x800FD898: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800FD89C: addiu       $t8, $t8, 0x4010
    ctx->r24 = ADD32(ctx->r24, 0X4010);
    // 0x800FD8A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD8A4: b           L_800FDBA8
    // 0x800FD8A8: sw          $t8, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r24;
        goto L_800FDBA8;
    // 0x800FD8A8: sw          $t8, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r24;
L_800FD8AC:
    // 0x800FD8AC: lbu         $t9, 0x40($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X40);
    // 0x800FD8B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD8B4: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD8B8: bne         $t9, $zero, L_800FD8D8
    if (ctx->r25 != 0) {
        // 0x800FD8BC: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800FD8D8;
    }
    // 0x800FD8BC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD8C0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD8C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FD8C8: addiu       $a2, $a2, 0x4004
    ctx->r6 = ADD32(ctx->r6, 0X4004);
    // 0x800FD8CC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD8D0: jal         0x800FCFB0
    // 0x800FD8D4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_32;
    // 0x800FD8D4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_32:
L_800FD8D8:
    // 0x800FD8D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800FD8DC: addiu       $t0, $t0, 0x4010
    ctx->r8 = ADD32(ctx->r8, 0X4010);
    // 0x800FD8E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD8E4: b           L_800FDBA8
    // 0x800FD8E8: sw          $t0, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r8;
        goto L_800FDBA8;
    // 0x800FD8E8: sw          $t0, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r8;
L_800FD8EC:
    // 0x800FD8EC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD8F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FD8F4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD8F8: addiu       $a2, $a2, 0x4040
    ctx->r6 = ADD32(ctx->r6, 0X4040);
    // 0x800FD8FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD900: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD904: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD908: jal         0x800FCFB0
    // 0x800FD90C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_33;
    // 0x800FD90C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_33:
    // 0x800FD910: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800FD914: addiu       $t1, $t1, 0x4010
    ctx->r9 = ADD32(ctx->r9, 0X4010);
    // 0x800FD918: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD91C: b           L_800FDBA8
    // 0x800FD920: sw          $t1, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r9;
        goto L_800FDBA8;
    // 0x800FD920: sw          $t1, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r9;
L_800FD924:
    // 0x800FD924: jal         0x800DA298
    // 0x800FD928: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    func_800DA298(rdram, ctx);
        goto after_34;
    // 0x800FD928: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    after_34:
    // 0x800FD92C: beq         $v0, $zero, L_800FD960
    if (ctx->r2 == 0) {
        // 0x800FD930: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800FD960;
    }
    // 0x800FD930: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD934: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD938: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800FD93C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD940: addiu       $a2, $a2, 0x3E84
    ctx->r6 = ADD32(ctx->r6, 0X3E84);
    // 0x800FD944: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800FD948: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x800FD94C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD950: jal         0x800FCFB0
    // 0x800FD954: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_35;
    // 0x800FD954: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_35:
    // 0x800FD958: b           L_800FD980
    // 0x800FD95C: nop

        goto L_800FD980;
    // 0x800FD95C: nop

L_800FD960:
    // 0x800FD960: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD964: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800FD968: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD96C: addiu       $a2, $a2, 0x3E84
    ctx->r6 = ADD32(ctx->r6, 0X3E84);
    // 0x800FD970: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x800FD974: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD978: jal         0x800FCFB0
    // 0x800FD97C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_36;
    // 0x800FD97C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_36:
L_800FD980:
    // 0x800FD980: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800FD984: addiu       $t2, $t2, 0x4010
    ctx->r10 = ADD32(ctx->r10, 0X4010);
    // 0x800FD988: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD98C: b           L_800FDBA8
    // 0x800FD990: sw          $t2, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r10;
        goto L_800FDBA8;
    // 0x800FD990: sw          $t2, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r10;
L_800FD994:
    // 0x800FD994: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD998: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FD99C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD9A0: addiu       $a2, $a2, 0x4034
    ctx->r6 = ADD32(ctx->r6, 0X4034);
    // 0x800FD9A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD9A8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD9AC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD9B0: jal         0x800FCFB0
    // 0x800FD9B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_37;
    // 0x800FD9B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_37:
    // 0x800FD9B8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800FD9BC: addiu       $t3, $t3, 0x4010
    ctx->r11 = ADD32(ctx->r11, 0X4010);
    // 0x800FD9C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD9C4: b           L_800FDBA8
    // 0x800FD9C8: sw          $t3, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r11;
        goto L_800FDBA8;
    // 0x800FD9C8: sw          $t3, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r11;
L_800FD9CC:
    // 0x800FD9CC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FD9D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FD9D4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FD9D8: addiu       $a2, $a2, 0x401C
    ctx->r6 = ADD32(ctx->r6, 0X401C);
    // 0x800FD9DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FD9E0: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FD9E4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FD9E8: jal         0x800FCFB0
    // 0x800FD9EC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_38;
    // 0x800FD9EC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_38:
    // 0x800FD9F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800FD9F4: addiu       $t4, $t4, 0x4010
    ctx->r12 = ADD32(ctx->r12, 0X4010);
    // 0x800FD9F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FD9FC: b           L_800FDBA8
    // 0x800FDA00: sw          $t4, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r12;
        goto L_800FDBA8;
    // 0x800FDA00: sw          $t4, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r12;
L_800FDA04:
    // 0x800FDA04: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FDA08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FDA0C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FDA10: addiu       $a2, $a2, 0x4028
    ctx->r6 = ADD32(ctx->r6, 0X4028);
    // 0x800FDA14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FDA18: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800FDA1C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FDA20: jal         0x800FCFB0
    // 0x800FDA24: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_39;
    // 0x800FDA24: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_39:
    // 0x800FDA28: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800FDA2C: addiu       $t5, $t5, 0x4010
    ctx->r13 = ADD32(ctx->r13, 0X4010);
    // 0x800FDA30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDA34: b           L_800FDBA8
    // 0x800FDA38: sw          $t5, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r13;
        goto L_800FDBA8;
    // 0x800FDA38: sw          $t5, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r13;
L_800FDA3C:
    // 0x800FDA3C: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    // 0x800FDA40: jal         0x800DA298
    // 0x800FDA44: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_40;
    // 0x800FDA44: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_40:
    // 0x800FDA48: beq         $v0, $zero, L_800FDBA8
    if (ctx->r2 == 0) {
        // 0x800FDA4C: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_800FDBA8;
    }
    // 0x800FDA4C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800FDA50: lui         $a1, 0x44DA
    ctx->r5 = S32(0X44DA << 16);
    // 0x800FDA54: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FDA58: addiu       $a2, $a2, 0x4218
    ctx->r6 = ADD32(ctx->r6, 0X4218);
    // 0x800FDA5C: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x800FDA60: jal         0x800EFFB4
    // 0x800FDA64: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800EFFB4(rdram, ctx);
        goto after_41;
    // 0x800FDA64: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_41:
    // 0x800FDA68: beq         $v0, $zero, L_800FDAB8
    if (ctx->r2 == 0) {
        // 0x800FDA6C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800FDAB8;
    }
    // 0x800FDA6C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800FDA70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FDA74: addiu       $v0, $v0, 0x5A44
    ctx->r2 = ADD32(ctx->r2, 0X5A44);
    // 0x800FDA78: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FDA7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FDA80: nop

    // 0x800FDA84: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800FDA88: nop

    // 0x800FDA8C: bc1fl       L_800FDB00
    if (!c1cs) {
        // 0x800FDA90: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_800FDB00;
    }
    goto skip_4;
    // 0x800FDA90: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_4:
    // 0x800FDA94: jal         0x800D8FF8
    // 0x800FDA98: nop

    func_800D8FF8(rdram, ctx);
        goto after_42;
    // 0x800FDA98: nop

    after_42:
    // 0x800FDA9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FDAA0: addiu       $v0, $v0, 0x5A44
    ctx->r2 = ADD32(ctx->r2, 0X5A44);
    // 0x800FDAA4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FDAA8: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800FDAAC: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x800FDAB0: b           L_800FDAFC
    // 0x800FDAB4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
        goto L_800FDAFC;
    // 0x800FDAB4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_800FDAB8:
    // 0x800FDAB8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FDABC: addiu       $v0, $v0, 0x5A44
    ctx->r2 = ADD32(ctx->r2, 0X5A44);
    // 0x800FDAC0: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FDAC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FDAC8: nop

    // 0x800FDACC: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800FDAD0: nop

    // 0x800FDAD4: bc1fl       L_800FDB00
    if (!c1cs) {
        // 0x800FDAD8: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_800FDB00;
    }
    goto skip_5;
    // 0x800FDAD8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_5:
    // 0x800FDADC: jal         0x800D8FF8
    // 0x800FDAE0: nop

    func_800D8FF8(rdram, ctx);
        goto after_43;
    // 0x800FDAE0: nop

    after_43:
    // 0x800FDAE4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FDAE8: addiu       $v0, $v0, 0x5A44
    ctx->r2 = ADD32(ctx->r2, 0X5A44);
    // 0x800FDAEC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FDAF0: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800FDAF4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800FDAF8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_800FDAFC:
    // 0x800FDAFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_800FDB00:
    // 0x800FDB00: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800FDB04: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x800FDB08: nop

    // 0x800FDB0C: bc1fl       L_800FDBAC
    if (!c1cs) {
        // 0x800FDB10: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800FDBAC;
    }
    goto skip_6;
    // 0x800FDB10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x800FDB14: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800FDB18: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800FDB1C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800FDB20: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x800FDB24: addiu       $t6, $t6, 0x41CC
    ctx->r14 = ADD32(ctx->r14, 0X41CC);
    // 0x800FDB28: addiu       $t7, $t7, 0x41D8
    ctx->r15 = ADD32(ctx->r15, 0X41D8);
    // 0x800FDB2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDB30: bc1f        L_800FDB44
    if (!c1cs) {
        // 0x800FDB34: nop
    
            goto L_800FDB44;
    }
    // 0x800FDB34: nop

    // 0x800FDB38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDB3C: b           L_800FDBA8
    // 0x800FDB40: sw          $t6, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r14;
        goto L_800FDBA8;
    // 0x800FDB40: sw          $t6, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r14;
L_800FDB44:
    // 0x800FDB44: b           L_800FDBA8
    // 0x800FDB48: sw          $t7, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r15;
        goto L_800FDBA8;
    // 0x800FDB48: sw          $t7, 0x5A04($at)
    MEM_W(0X5A04, ctx->r1) = ctx->r15;
L_800FDB4C:
    // 0x800FDB4C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FDB50: addiu       $v0, $v0, 0x5A44
    ctx->r2 = ADD32(ctx->r2, 0X5A44);
    // 0x800FDB54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FDB58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800FDB5C: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800FDB60: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FDB64: addiu       $a2, $a2, 0x3E84
    ctx->r6 = ADD32(ctx->r6, 0X3E84);
    // 0x800FDB68: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x800FDB6C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800FDB70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FDB74: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    // 0x800FDB78: bc1fl       L_800FDB9C
    if (!c1cs) {
        // 0x800FDB7C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800FDB9C;
    }
    goto skip_7;
    // 0x800FDB7C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_7:
    // 0x800FDB80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FDB84: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FDB88: jal         0x800FCFB0
    // 0x800FDB8C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800FCFB0(rdram, ctx);
        goto after_44;
    // 0x800FDB8C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_44:
    // 0x800FDB90: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FDB94: addiu       $v0, $v0, 0x5A44
    ctx->r2 = ADD32(ctx->r2, 0X5A44);
    // 0x800FDB98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800FDB9C:
    // 0x800FDB9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FDBA0: nop

    // 0x800FDBA4: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_800FDBA8:
    // 0x800FDBA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800FDBAC:
    // 0x800FDBAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FDBB0: jr          $ra
    // 0x800FDBB4: nop

    return;
    // 0x800FDBB4: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801454: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80801458: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8080145C: lh          $v0, 0xB0($t7)
    ctx->r2 = MEM_H(ctx->r15, 0XB0);
    // 0x80801460: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80801464: jr          $ra
    // 0x80801468: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
    return;
    // 0x80801468: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_80801200_cheel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801200: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801204: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801208: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080120C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801210: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x80801214: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801218: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8080121C: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    // 0x80801220: jal         0x80102424
    // 0x80801224: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80801224: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x80801228: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8080122C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80801230: sltiu       $at, $t0, 0xC
    ctx->r1 = ctx->r8 < 0XC ? 1 : 0;
    // 0x80801234: beq         $at, $zero, L_8080131C
    if (ctx->r1 == 0) {
        // 0x80801238: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8080131C;
    }
    // 0x80801238: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8080123C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1792, 0X1524) << 16);
    // 0x80801240: addu        $at, $at, $t0
    gpr jr_addend_80801248 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80801244: lw          $t0, 0x1524($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1792, 0X1524));
    // 0x80801248: jr          $t0
    // 0x8080124C: nop

    switch (jr_addend_80801248 >> 2) {
        case 0: goto L_80801250; break;
        case 1: goto L_80801298; break;
        case 2: goto L_808012A8; break;
        case 3: goto L_808012D0; break;
        case 4: goto L_8080131C; break;
        case 5: goto L_808012F0; break;
        case 6: goto L_8080131C; break;
        case 7: goto L_808012E0; break;
        case 8: goto L_80801308; break;
        case 9: goto L_80801308; break;
        case 10: goto L_80801308; break;
        case 11: goto L_80801308; break;
        default: switch_error(__func__, 0x80801248, 0x80801524);
    }
    // 0x8080124C: nop

L_80801250:
    // 0x80801250: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80801254: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801258: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080125C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801260: jal         0x800DC178
    // 0x80801264: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80801264: nop

    after_1:
    // 0x80801268: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080126C: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80801270: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801274: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80801278: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080127C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801280: jal         0x800DC178
    // 0x80801284: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80801284: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x80801288: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8080128C: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80801290: b           L_8080131C
    // 0x80801294: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
        goto L_8080131C;
    // 0x80801294: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
L_80801298:
    // 0x80801298: jal         0x80801120
    // 0x8080129C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801120_cheel(rdram, ctx);
        goto after_3;
    // 0x8080129C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808012A0: b           L_80801320
    // 0x808012A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801320;
    // 0x808012A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808012A8:
    // 0x808012A8: jal         0x8008FD48
    // 0x808012AC: nop

    func_8008FD48(rdram, ctx);
        goto after_4;
    // 0x808012AC: nop

    after_4:
    // 0x808012B0: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x808012B4: bnel        $v0, $at, L_80801320
    if (ctx->r2 != ctx->r1) {
        // 0x808012B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801320;
    }
    goto skip_0;
    // 0x808012B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808012BC: lbu         $t1, 0x72($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X72);
    // 0x808012C0: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x808012C4: ori         $t3, $t2, 0x14
    ctx->r11 = ctx->r10 | 0X14;
    // 0x808012C8: b           L_8080131C
    // 0x808012CC: sb          $t3, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r11;
        goto L_8080131C;
    // 0x808012CC: sb          $t3, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r11;
L_808012D0:
    // 0x808012D0: jal         0x80801120
    // 0x808012D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801120_cheel(rdram, ctx);
        goto after_5;
    // 0x808012D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808012D8: b           L_80801320
    // 0x808012DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801320;
    // 0x808012DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808012E0:
    // 0x808012E0: jal         0x8010A570
    // 0x808012E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x808012E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808012E8: b           L_80801320
    // 0x808012EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801320;
    // 0x808012EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808012F0:
    // 0x808012F0: jal         0x8010A570
    // 0x808012F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_7;
    // 0x808012F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808012F8: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x808012FC: andi        $t5, $t4, 0xFFF7
    ctx->r13 = ctx->r12 & 0XFFF7;
    // 0x80801300: b           L_8080131C
    // 0x80801304: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
        goto L_8080131C;
    // 0x80801304: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_80801308:
    // 0x80801308: jal         0x8010A570
    // 0x8080130C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_8;
    // 0x8080130C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801310: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80801314: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80801318: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
L_8080131C:
    // 0x8080131C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801320:
    // 0x80801320: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801328: jr          $ra
    // 0x8080132C: nop

    return;
    // 0x8080132C: nop

;}
RECOMP_FUNC void gcgoto_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006DC: jr          $ra
    // 0x808006E0: nop

    return;
    // 0x808006E0: nop

;}
RECOMP_FUNC void func_80801258_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801258: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080125C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1752, 0X4E28) << 16);
    // 0x80801260: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80801264: addiu       $t6, $t6, 0x4E28
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1752, 0X4E28));
    // 0x80801268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080126C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801270: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801274: addiu       $t9, $t6, 0x30
    ctx->r25 = ADD32(ctx->r14, 0X30);
    // 0x80801278: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_8080127C:
    // 0x8080127C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80801280: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80801284: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80801288: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x8080128C: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x80801290: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x80801294: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x80801298: bne         $t6, $t9, L_8080127C
    if (ctx->r14 != ctx->r25) {
        // 0x8080129C: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_8080127C;
    }
    // 0x8080129C: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x808012A0: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x808012A4: subu        $t1, $t1, $a3
    ctx->r9 = SUB32(ctx->r9, ctx->r7);
    // 0x808012A8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808012AC: addu        $a1, $v0, $t1
    ctx->r5 = ADD32(ctx->r2, ctx->r9);
    // 0x808012B0: jal         0x800EE7F8
    // 0x808012B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808012B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x808012B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012BC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808012C0: jr          $ra
    // 0x808012C4: nop

    return;
    // 0x808012C4: nop

;}
RECOMP_FUNC void _chgameselect_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085BB8: syscall     205
    recomp_syscall_handler(rdram, ctx, 0x80085BB8);
    return;
    // 0x80085BBC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8010568C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010568C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80105698: jal         0x80105494
    // 0x8010569C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80105494(rdram, ctx);
        goto after_0;
    // 0x8010569C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x801056A0: beq         $v0, $zero, L_801056C4
    if (ctx->r2 == 0) {
        // 0x801056A4: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_801056C4;
    }
    // 0x801056A4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x801056A8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801056AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801056B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801056B4: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x801056B8: sra         $t8, $t7, 22
    ctx->r24 = S32(SIGNED(ctx->r15) >> 22);
    // 0x801056BC: bne         $t8, $at, L_801056DC
    if (ctx->r24 != ctx->r1) {
        // 0x801056C0: nop
    
            goto L_801056DC;
    }
    // 0x801056C0: nop

L_801056C4:
    // 0x801056C4: beq         $t9, $zero, L_801056D4
    if (ctx->r25 == 0) {
        // 0x801056C8: nop
    
            goto L_801056D4;
    }
    // 0x801056C8: nop

    // 0x801056CC: jal         0x800FFAB0
    // 0x801056D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x801056D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_801056D4:
    // 0x801056D4: b           L_801056DC
    // 0x801056D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801056DC;
    // 0x801056D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801056DC:
    // 0x801056DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801056E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801056E4: jr          $ra
    // 0x801056E8: nop

    return;
    // 0x801056E8: nop

;}
RECOMP_FUNC void func_80800070_chtalontorpedoboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800074: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800078: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080007C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800080: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800084: beq         $a1, $at, L_808000A0
    if (ctx->r5 == ctx->r1) {
        // 0x80800088: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_808000A0;
    }
    // 0x80800088: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8080008C: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800090: beq         $a1, $at, L_80800138
    if (ctx->r5 == ctx->r1) {
        // 0x80800094: nop
    
            goto L_80800138;
    }
    // 0x80800094: nop

    // 0x80800098: b           L_80800180
    // 0x8080009C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800180;
    // 0x8080009C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000A0:
    // 0x808000A0: jal         0x808001CC
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001CC_chtalontorpedoboulder(rdram, ctx);
        goto after_0;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000A8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808000AC: jal         0x808001F8
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001F8_chtalontorpedoboulder(rdram, ctx);
        goto after_1;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000B8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808000BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x80086670
    // 0x808000C8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000C8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_2:
    // 0x808000CC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808000D0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1436, 0X240) << 16);
    // 0x808000D4: addiu       $t6, $t6, 0x240
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1436, 0X240));
    // 0x808000D8: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x808000DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808000E4: jal         0x800BABB8
    // 0x808000E8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x808000E8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_3:
    // 0x808000EC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1436, 0X2FC) << 16);
    // 0x808000F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808000F4: addiu       $a2, $a2, 0x2FC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1436, 0X2FC));
    // 0x808000F8: jal         0x80089D18
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800100: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800104: beql        $a0, $zero, L_80800118
    if (ctx->r4 == 0) {
        // 0x80800108: lw          $a2, 0x38($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X38);
            goto L_80800118;
    }
    goto skip_0;
    // 0x80800108: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x8080010C: jal         0x800DA544
    // 0x80800110: nop

    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x80800110: nop

    after_5:
    // 0x80800114: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
L_80800118:
    // 0x80800118: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8080011C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800120: beq         $a2, $at, L_8080017C
    if (ctx->r6 == ctx->r1) {
        // 0x80800124: addiu       $a3, $zero, 0x10
        ctx->r7 = ADD32(0, 0X10);
            goto L_8080017C;
    }
    // 0x80800124: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800128: jal         0x80085708
    // 0x8080012C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_13(rdram, ctx);
        goto after_6;
    // 0x8080012C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x80800130: b           L_80800180
    // 0x80800134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800180;
    // 0x80800134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800138:
    // 0x80800138: jal         0x80101080
    // 0x8080013C: nop

    func_80101080(rdram, ctx);
        goto after_7;
    // 0x8080013C: nop

    after_7:
    // 0x80800140: jal         0x80106790
    // 0x80800144: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_8;
    // 0x80800144: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800148: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080014C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800154: jal         0x800866A0
    // 0x80800158: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_9;
    // 0x80800158: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_9:
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800164: jal         0x800866A0
    // 0x80800168: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x80800168: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8080016C: b           L_80800180
    // 0x80800170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800180;
    // 0x80800170: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800174: b           L_80800180
    // 0x80800178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800180;
    // 0x80800178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080017C:
    // 0x8080017C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800180:
    // 0x80800180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800184: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800188: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080018C: jr          $ra
    // 0x80800190: nop

    return;
    // 0x80800190: nop

;}
RECOMP_FUNC void _susplinet_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E50: syscall     812
    recomp_syscall_handler(rdram, ctx, 0x80089E50);
    return;
    // 0x80089E54: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void glglobalsettings_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004D4: addiu       $a0, $zero, 0xBC6
    ctx->r4 = ADD32(0, 0XBC6);
    // 0x808004D8: jal         0x800DA564
    // 0x808004DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x808004DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x808004E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004E8: jr          $ra
    // 0x808004EC: nop

    return;
    // 0x808004EC: nop

;}
RECOMP_FUNC void func_808030AC_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808030AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808030B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808030B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808030B8: jal         0x800D8FF8
    // 0x808030BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808030BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808030C0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808030C4: jal         0x80106790
    // 0x808030C8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808030C8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x808030CC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808030D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808030D4: jal         0x80100094
    // 0x808030D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808030D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808030DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808030E0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1676, 0X4208) << 16);
    // 0x808030E4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808030E8: addiu       $a3, $a3, 0x4208
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1676, 0X4208));
    // 0x808030EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808030F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808030F4: jal         0x80089D50
    // 0x808030F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808030F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x808030FC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80803100: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80803104: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80803108: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8080310C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80803110: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80803114: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803118: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080311C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80803120: bne         $t7, $at, L_80803344
    if (ctx->r15 != ctx->r1) {
        // 0x80803124: swc1        $f16, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
            goto L_80803344;
    }
    // 0x80803124: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x80803128: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080312C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803130: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80803134: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80803138: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080313C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80803140: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80803144: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80803148: andi        $t8, $a0, 0x1FF
    ctx->r24 = ctx->r4 & 0X1FF;
    // 0x8080314C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80803150: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80803154: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80803158: jal         0x800C8E54
    // 0x8080315C: nop

    func_800C8E54(rdram, ctx);
        goto after_4;
    // 0x8080315C: nop

    after_4:
    // 0x80803160: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80803164: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1676, 0X44E4) << 16);
    // 0x80803168: addiu       $a1, $a1, 0x44E4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1676, 0X44E4));
    // 0x8080316C: andi        $t9, $a0, 0x1FF
    ctx->r25 = ctx->r4 & 0X1FF;
    // 0x80803170: jal         0x800C8E84
    // 0x80803174: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800C8E84(rdram, ctx);
        goto after_5;
    // 0x80803174: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_5:
    // 0x80803178: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8080317C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80803180: andi        $t0, $a0, 0x1FF
    ctx->r8 = ctx->r4 & 0X1FF;
    // 0x80803184: jal         0x800C8CB8
    // 0x80803188: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_6;
    // 0x80803188: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_6:
    // 0x8080318C: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x80803190: jal         0x800D0A9C
    // 0x80803194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_7;
    // 0x80803194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80803198: bne         $v0, $zero, L_808032C8
    if (ctx->r2 != 0) {
        // 0x8080319C: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_808032C8;
    }
    // 0x8080319C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808031A0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808031A4: jal         0x800EE7F8
    // 0x808031A8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x808031A8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_8:
    // 0x808031AC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808031B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808031B4: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808031B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808031BC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808031C0: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x808031C4: jal         0x800F1DF4
    // 0x808031C8: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    func_800F1DF4(rdram, ctx);
        goto after_9;
    // 0x808031C8: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x808031CC: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808031D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808031D4: jal         0x800F1828
    // 0x808031D8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800F1828(rdram, ctx);
        goto after_10;
    // 0x808031D8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_10:
    // 0x808031DC: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x808031E0: lwc1        $f12, 0x54($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808031E4: jal         0x800F1DCC
    // 0x808031E8: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_11;
    // 0x808031E8: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    after_11:
    // 0x808031EC: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808031F0: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808031F4: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x808031F8: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x808031FC: lwc1        $f14, 0x44($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80803200: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80803204: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    // 0x80803208: jal         0x800F1DCC
    // 0x8080320C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_12;
    // 0x8080320C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x80803210: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80803214: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80803218: lhu         $t1, 0x78($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X78);
    // 0x8080321C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80803220: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80803224: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x80803228: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8080322C: bne         $t2, $zero, L_80803288
    if (ctx->r10 != 0) {
        // 0x80803230: swc1        $f4, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
            goto L_80803288;
    }
    // 0x80803230: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x80803234: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80803238: nop

    // 0x8080323C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80803240: nop

    // 0x80803244: bc1fl       L_80803258
    if (!c1cs) {
        // 0x80803248: neg.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
            goto L_80803258;
    }
    goto skip_0;
    // 0x80803248: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    skip_0:
    // 0x8080324C: b           L_80803258
    // 0x80803250: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80803258;
    // 0x80803250: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80803254: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80803258:
    // 0x80803258: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8080325C: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80803260: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803264: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80803268: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x8080326C: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80803270: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80803274: nop

    // 0x80803278: bc1fl       L_8080328C
    if (!c1cs) {
        // 0x8080327C: lwc1        $f0, 0x20($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
            goto L_8080328C;
    }
    goto skip_1;
    // 0x8080327C: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    skip_1:
    // 0x80803280: jal         0x80089CA8
    // 0x80803284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x80803284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
L_80803288:
    // 0x80803288: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
L_8080328C:
    // 0x8080328C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80803290: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80803294: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80803298: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8080329C: nop

    // 0x808032A0: bc1fl       L_808032B8
    if (!c1cs) {
        // 0x808032A4: lwc1        $f16, 0x34($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
            goto L_808032B8;
    }
    goto skip_2;
    // 0x808032A4: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
    skip_2:
    // 0x808032A8: sub.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x808032AC: b           L_808032C8
    // 0x808032B0: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
        goto L_808032C8;
    // 0x808032B0: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x808032B4: lwc1        $f16, 0x34($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X34);
L_808032B8:
    // 0x808032B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808032BC: nop

    // 0x808032C0: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x808032C4: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
L_808032C8:
    // 0x808032C8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808032CC: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x808032D0: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x808032D4: jal         0x800EEC30
    // 0x808032D8: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    func_800EEC30(rdram, ctx);
        goto after_14;
    // 0x808032D8: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    after_14:
    // 0x808032DC: lui         $a1, 0x40
    ctx->r5 = S32(0X40 << 16);
    // 0x808032E0: ori         $a1, $a1, 0x7
    ctx->r5 = ctx->r5 | 0X7;
    // 0x808032E4: jal         0x8010B990
    // 0x808032E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_15;
    // 0x808032E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808032EC: andi        $t3, $v0, 0x20
    ctx->r11 = ctx->r2 & 0X20;
    // 0x808032F0: beql        $t3, $zero, L_80803304
    if (ctx->r11 == 0) {
        // 0x808032F4: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80803304;
    }
    goto skip_3;
    // 0x808032F4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    skip_3:
    // 0x808032F8: jal         0x8080300C
    // 0x808032FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080300C_chevilmumbo(rdram, ctx);
        goto after_16;
    // 0x808032FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80803300: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_80803304:
    // 0x80803304: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80803308: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080330C: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80803310: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80803314: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80803318: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8080331C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80803320: sub.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80803324: bc1f        L_8080333C
    if (!c1cs) {
        // 0x80803328: swc1        $f8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
            goto L_8080333C;
    }
    // 0x80803328: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8080332C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80803330: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80803334: b           L_80803344
    // 0x80803338: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80803344;
    // 0x80803338: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_8080333C:
    // 0x8080333C: jal         0x800FFAB0
    // 0x80803340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_17;
    // 0x80803340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_80803344:
    // 0x80803344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80803348: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080334C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80803350: jr          $ra
    // 0x80803354: nop

    return;
    // 0x80803354: nop

;}
RECOMP_FUNC void func_80800714_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080071C: jal         0x80800198
    // 0x80800720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800198_bsmumswim(rdram, ctx);
        goto after_0;
    // 0x80800720: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800724: jal         0x800A4E30
    // 0x80800728: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A4E30(rdram, ctx);
        goto after_1;
    // 0x80800728: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080072C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800730: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800734: jr          $ra
    // 0x80800738: nop

    return;
    // 0x80800738: nop

;}
RECOMP_FUNC void _bsbeemain_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082888: syscall     17
    recomp_syscall_handler(rdram, ctx, 0x80082888);
    return;
    // 0x8008288C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chdippy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C80: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1284, 0X14B0) << 16);
    // 0x80800C84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800C8C: addiu       $t6, $t6, 0x14B0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1284, 0X14B0));
    // 0x80800C90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800C94: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x80800C98: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800CA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800CA4: jal         0x800BBCB8
    // 0x80800CA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800CA8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CB4: jr          $ra
    // 0x80800CB8: nop

    return;
    // 0x80800CB8: nop

;}
RECOMP_FUNC void _bakaztorpedo_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084DA0: syscall     136
    recomp_syscall_handler(rdram, ctx, 0x80084DA0);
    return;
    // 0x80084DA4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_80800E54_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800E58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E5C: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80800E60: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800E64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800E68: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800E6C: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
    // 0x80800E70: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800E74: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800E78: nop

    // 0x80800E7C: beql        $t7, $at, L_80800EAC
    if (ctx->r15 == ctx->r1) {
        // 0x80800E80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800EAC;
    }
    goto skip_0;
    // 0x80800E80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800E84: jal         0x800EE904
    // 0x80800E88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800EE904(rdram, ctx);
        goto after_0;
    // 0x80800E88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800E8C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800E90: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80800E94: lwc1        $f8, 0x50($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X50);
    // 0x80800E98: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800E9C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x80800EA0: jal         0x800C8E84
    // 0x80800EA4: nop

    func_800C8E84(rdram, ctx);
        goto after_1;
    // 0x80800EA4: nop

    after_1:
    // 0x80800EA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800EAC:
    // 0x80800EAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800EB0: jr          $ra
    // 0x80800EB4: nop

    return;
    // 0x80800EB4: nop

;}
RECOMP_FUNC void _bsbswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B48: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082B48);
    return;
    // 0x80082B4C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _baeggcursor_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AF0: syscall     128
    recomp_syscall_handler(rdram, ctx, 0x80084AF0);
    return;
    // 0x80084AF4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void baduo_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "baduo_entrypoint_13");
    // 0x8080030C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800310: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800314: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800318: jal         0x800F54E4
    // 0x8080031C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8080031C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800320: lw          $t6, 0x58($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X58);
    // 0x80800324: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800328: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080032C: lbu         $v1, 0x0($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X0);
    // 0x80800330: beq         $v1, $at, L_80800348
    if (ctx->r3 == ctx->r1) {
        // 0x80800334: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800348;
    }
    // 0x80800334: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800338: beq         $v1, $at, L_8080037C
    if (ctx->r3 == ctx->r1) {
        // 0x8080033C: nop
    
            goto L_8080037C;
    }
    // 0x8080033C: nop

    // 0x80800340: b           L_80800530
    // 0x80800344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800530;
    // 0x80800344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800348:
    // 0x80800348: jal         0x800A3274
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_1;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800350: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800354: bnel        $v0, $at, L_80800530
    if (ctx->r2 != ctx->r1) {
        // 0x80800358: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800530;
    }
    goto skip_0;
    // 0x80800358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080035C: jal         0x8008D40C
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D40C(rdram, ctx);
        goto after_2;
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800364: beq         $v0, $zero, L_8080052C
    if (ctx->r2 == 0) {
        // 0x80800368: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080052C;
    }
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: jal         0x8080017C
    // 0x80800370: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    baduo_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800370: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800374: b           L_80800530
    // 0x80800378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800530;
    // 0x80800378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080037C:
    // 0x8080037C: jal         0x800F5B0C
    // 0x80800380: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    func_800F5B0C(rdram, ctx);
        goto after_4;
    // 0x80800380: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_4:
    // 0x80800384: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800388: bnel        $v0, $at, L_80800530
    if (ctx->r2 != ctx->r1) {
        // 0x8080038C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800530;
    }
    goto skip_1;
    // 0x8080038C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800390: jal         0x80800050
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baduo_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800398: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8080039C: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x808003A0: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x808003A4: bne         $t7, $a0, L_808003C4
    if (ctx->r15 != ctx->r4) {
        // 0x808003A8: nop
    
            goto L_808003C4;
    }
    // 0x808003A8: nop

    // 0x808003AC: jal         0x800878A0
    // 0x808003B0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808003B0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_6:
    // 0x808003B4: jal         0x800F8EBC
    // 0x808003B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F8EBC(rdram, ctx);
        goto after_7;
    // 0x808003B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808003BC: b           L_808003D0
    // 0x808003C0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
        goto L_808003D0;
    // 0x808003C0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_808003C4:
    // 0x808003C4: jal         0x800F8EBC
    // 0x808003C8: nop

    func_800F8EBC(rdram, ctx);
        goto after_8;
    // 0x808003C8: nop

    after_8:
    // 0x808003CC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_808003D0:
    // 0x808003D0: lw          $t8, 0x184($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X184);
    // 0x808003D4: bne         $a0, $t8, L_808003EC
    if (ctx->r4 != ctx->r24) {
        // 0x808003D8: nop
    
            goto L_808003EC;
    }
    // 0x808003D8: nop

    // 0x808003DC: jal         0x800F82D4
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_9;
    // 0x808003E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808003E4: b           L_80800404
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800404;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003EC:
    // 0x808003EC: jal         0x800F82D4
    // 0x808003F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_10;
    // 0x808003F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x808003F4: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x808003F8: jal         0x800F82D4
    // 0x808003FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_11;
    // 0x808003FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800404:
    // 0x80800404: jal         0x80084788
    // 0x80800408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_12;
    // 0x80800408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x8080040C: jal         0x800F911C
    // 0x80800410: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800F911C(rdram, ctx);
        goto after_13;
    // 0x80800410: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x80800414: jal         0x800F80D8
    // 0x80800418: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F80D8(rdram, ctx);
        goto after_14;
    // 0x80800418: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_14:
    // 0x8080041C: jal         0x800A3274
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_15;
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800424: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800428: jal         0x800D5034
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D5034(rdram, ctx);
        goto after_16;
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800434: jal         0x800A3410
    // 0x80800438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A3410(rdram, ctx);
        goto after_17;
    // 0x80800438: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x8080043C: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    // 0x80800440: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800444: jal         0x800F8268
    // 0x80800448: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800F8268(rdram, ctx);
        goto after_18;
    // 0x80800448: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_18:
    // 0x8080044C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80800450: lw          $t0, 0x184($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X184);
    // 0x80800454: beq         $t9, $t0, L_8080047C
    if (ctx->r25 == ctx->r8) {
        // 0x80800458: nop
    
            goto L_8080047C;
    }
    // 0x80800458: nop

    // 0x8080045C: jal         0x800F53D0
    // 0x80800460: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800F53D0(rdram, ctx);
        goto after_19;
    // 0x80800460: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_19:
    // 0x80800464: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800468: jal         0x800F53D0
    // 0x8080046C: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F53D0(rdram, ctx);
        goto after_20;
    // 0x8080046C: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_20:
    // 0x80800470: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800474: jal         0x80800008
    // 0x80800478: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800008_baduo(rdram, ctx);
        goto after_21;
    // 0x80800478: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_21:
L_8080047C:
    // 0x8080047C: jal         0x8009C984
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_22;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800484: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800488: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080048C: jal         0x800F5A00
    // 0x80800490: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800F5A00(rdram, ctx);
        goto after_23;
    // 0x80800490: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_23:
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: jal         0x8009C128
    // 0x8080049C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_8009C128(rdram, ctx);
        goto after_24;
    // 0x8080049C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_24:
    // 0x808004A0: jal         0x800F759C
    // 0x808004A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800F759C(rdram, ctx);
        goto after_25;
    // 0x808004A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_25:
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808004B0: jal         0x800A38F0
    // 0x808004B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_26;
    // 0x808004B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_26:
    // 0x808004B8: jal         0x800A91A8
    // 0x808004BC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800A91A8(rdram, ctx);
        goto after_27;
    // 0x808004BC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_27:
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C4: jal         0x8080017C
    // 0x808004C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    baduo_entrypoint_7(rdram, ctx);
        goto after_28;
    // 0x808004C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x808004CC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808004D0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808004D4: jal         0x800F1F0C
    // 0x808004D8: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    func_800F1F0C(rdram, ctx);
        goto after_29;
    // 0x808004D8: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    after_29:
    // 0x808004DC: jal         0x800F2100
    // 0x808004E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_30;
    // 0x808004E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_30:
    // 0x808004E4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808004E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004EC: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808004F8: nop

    // 0x808004FC: bc1f        L_80800514
    if (!c1cs) {
        // 0x80800500: nop
    
            goto L_80800514;
    }
    // 0x80800500: nop

    // 0x80800504: jal         0x8009E5C8
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_setState(rdram, ctx);
        goto after_31;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x8080050C: b           L_80800520
    // 0x80800510: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
        goto L_80800520;
    // 0x80800510: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
L_80800514:
    // 0x80800514: jal         0x8009E5C8
    // 0x80800518: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    bs_setState(rdram, ctx);
        goto after_32;
    // 0x80800518: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    after_32:
    // 0x8080051C: addiu       $a0, $zero, 0x158
    ctx->r4 = ADD32(0, 0X158);
L_80800520:
    // 0x80800520: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80800524: jal         0x80101180
    // 0x80800528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_33;
    // 0x80800528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_33:
L_8080052C:
    // 0x8080052C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800530:
    // 0x80800530: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800534: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800538: jr          $ra
    // 0x8080053C: nop

    return;
    // 0x8080053C: nop

;}
RECOMP_FUNC void _suspline_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DE8: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089DE8);
    return;
    // 0x80089DEC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_80800CA0_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CA0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800CA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800CA8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80800CAC: jal         0x80100094
    // 0x80800CB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800CB4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800CB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800CBC: lbu         $t6, 0x72($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X72);
    // 0x80800CC0: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x80800CC4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800CC8: sb          $t8, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r24;
    // 0x80800CCC: jal         0x808019C4
    // 0x80800CD0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    func_808019C4_chdodgemcontrol(rdram, ctx);
        goto after_1;
    // 0x80800CD0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800CD4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80800CD8: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80800CDC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80800CE0: lw          $t2, 0x64($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X64);
    // 0x80800CE4: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x80800CE8: bgezl       $t4, L_80800DCC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800CEC: lbu         $v0, 0x79($t6)
        ctx->r2 = MEM_BU(ctx->r14, 0X79);
            goto L_80800DCC;
    }
    goto skip_0;
    // 0x80800CEC: lbu         $v0, 0x79($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X79);
    skip_0:
    // 0x80800CF0: lbu         $v0, 0x79($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X79);
    // 0x80800CF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800CF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800CFC: srl         $t5, $v0, 4
    ctx->r13 = S32(U32(ctx->r2) >> 4);
    // 0x80800D00: beq         $t5, $zero, L_80800D24
    if (ctx->r13 == 0) {
        // 0x80800D04: addiu       $a1, $zero, 0x8A
        ctx->r5 = ADD32(0, 0X8A);
            goto L_80800D24;
    }
    // 0x80800D04: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    // 0x80800D08: beq         $t5, $t0, L_80800D58
    if (ctx->r13 == ctx->r8) {
        // 0x80800D0C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800D58;
    }
    // 0x80800D0C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D14: beq         $t5, $at, L_80800D90
    if (ctx->r13 == ctx->r1) {
        // 0x80800D18: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800D90;
    }
    // 0x80800D18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800D1C: b           L_80800FB8
    // 0x80800D20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB8;
    // 0x80800D20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D24:
    // 0x80800D24: jal         0x800D2054
    // 0x80800D28: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    func_800D2054(rdram, ctx);
        goto after_2;
    // 0x80800D28: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    after_2:
    // 0x80800D2C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800D30: bne         $v0, $t0, L_80800D40
    if (ctx->r2 != ctx->r8) {
        // 0x80800D34: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800D40;
    }
    // 0x80800D34: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800D38: b           L_80800D44
    // 0x80800D3C: addiu       $a3, $zero, 0x10EC
    ctx->r7 = ADD32(0, 0X10EC);
        goto L_80800D44;
    // 0x80800D3C: addiu       $a3, $zero, 0x10EC
    ctx->r7 = ADD32(0, 0X10EC);
L_80800D40:
    // 0x80800D40: addiu       $a3, $zero, 0x10ED
    ctx->r7 = ADD32(0, 0X10ED);
L_80800D44:
    // 0x80800D44: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800D48: jal         0x8080061C
    // 0x80800D4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080061C_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x80800D4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800D50: b           L_80800FB8
    // 0x80800D54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB8;
    // 0x80800D54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D58:
    // 0x80800D58: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    // 0x80800D5C: jal         0x800D2054
    // 0x80800D60: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    func_800D2054(rdram, ctx);
        goto after_4;
    // 0x80800D60: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    after_4:
    // 0x80800D64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800D68: bne         $v0, $t0, L_80800D78
    if (ctx->r2 != ctx->r8) {
        // 0x80800D6C: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800D78;
    }
    // 0x80800D6C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800D70: b           L_80800D7C
    // 0x80800D74: addiu       $a3, $zero, 0x10EE
    ctx->r7 = ADD32(0, 0X10EE);
        goto L_80800D7C;
    // 0x80800D74: addiu       $a3, $zero, 0x10EE
    ctx->r7 = ADD32(0, 0X10EE);
L_80800D78:
    // 0x80800D78: addiu       $a3, $zero, 0x10EF
    ctx->r7 = ADD32(0, 0X10EF);
L_80800D7C:
    // 0x80800D7C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800D80: jal         0x8080061C
    // 0x80800D84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080061C_chdodgemcontrol(rdram, ctx);
        goto after_5;
    // 0x80800D84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800D88: b           L_80800FB8
    // 0x80800D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB8;
    // 0x80800D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D90:
    // 0x80800D90: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80800D94: jal         0x800D2054
    // 0x80800D98: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    func_800D2054(rdram, ctx);
        goto after_6;
    // 0x80800D98: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    after_6:
    // 0x80800D9C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800DA0: bne         $v0, $t0, L_80800DB0
    if (ctx->r2 != ctx->r8) {
        // 0x80800DA4: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800DB0;
    }
    // 0x80800DA4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800DA8: b           L_80800DB4
    // 0x80800DAC: addiu       $a3, $zero, 0x10F0
    ctx->r7 = ADD32(0, 0X10F0);
        goto L_80800DB4;
    // 0x80800DAC: addiu       $a3, $zero, 0x10F0
    ctx->r7 = ADD32(0, 0X10F0);
L_80800DB0:
    // 0x80800DB0: addiu       $a3, $zero, 0x10F1
    ctx->r7 = ADD32(0, 0X10F1);
L_80800DB4:
    // 0x80800DB4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800DB8: jal         0x8080061C
    // 0x80800DBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080061C_chdodgemcontrol(rdram, ctx);
        goto after_7;
    // 0x80800DBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800DC0: b           L_80800FB8
    // 0x80800DC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB8;
    // 0x80800DC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DC8: lbu         $v0, 0x79($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X79);
L_80800DCC:
    // 0x80800DCC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800DD0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800DD4: srl         $t7, $v0, 4
    ctx->r15 = S32(U32(ctx->r2) >> 4);
    // 0x80800DD8: beq         $t7, $zero, L_80800E08
    if (ctx->r15 == 0) {
        // 0x80800DDC: nop
    
            goto L_80800E08;
    }
    // 0x80800DDC: nop

    // 0x80800DE0: beq         $t7, $t0, L_80800E5C
    if (ctx->r15 == ctx->r8) {
        // 0x80800DE4: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800E5C;
    }
    // 0x80800DE4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800DE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DEC: beq         $t7, $at, L_80800EB0
    if (ctx->r15 == ctx->r1) {
        // 0x80800DF0: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80800EB0;
    }
    // 0x80800DF0: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800DF4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800DF8: beq         $t7, $at, L_80800F04
    if (ctx->r15 == ctx->r1) {
        // 0x80800DFC: addiu       $a0, $t1, 0x10
        ctx->r4 = ADD32(ctx->r9, 0X10);
            goto L_80800F04;
    }
    // 0x80800DFC: addiu       $a0, $t1, 0x10
    ctx->r4 = ADD32(ctx->r9, 0X10);
    // 0x80800E00: b           L_80800FB8
    // 0x80800E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB8;
    // 0x80800E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E08:
    // 0x80800E08: jal         0x808008EC
    // 0x80800E0C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    func_808008EC_chdodgemcontrol(rdram, ctx);
        goto after_8;
    // 0x80800E0C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    after_8:
    // 0x80800E10: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80800E14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800E18: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    // 0x80800E1C: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    // 0x80800E20: addiu       $a3, $zero, 0x10D7
    ctx->r7 = ADD32(0, 0X10D7);
    // 0x80800E24: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800E28: bne         $at, $zero, L_80800E44
    if (ctx->r1 != 0) {
        // 0x80800E2C: nop
    
            goto L_80800E44;
    }
    // 0x80800E2C: nop

    // 0x80800E30: addiu       $a3, $zero, 0x10D4
    ctx->r7 = ADD32(0, 0X10D4);
    // 0x80800E34: jal         0x800D2054
    // 0x80800E38: sh          $a3, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r7;
    func_800D2054(rdram, ctx);
        goto after_9;
    // 0x80800E38: sh          $a3, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r7;
    after_9:
    // 0x80800E3C: b           L_80800E44
    // 0x80800E40: lh          $a3, 0x5A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5A);
        goto L_80800E44;
    // 0x80800E40: lh          $a3, 0x5A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5A);
L_80800E44:
    // 0x80800E44: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800E48: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800E4C: jal         0x8080061C
    // 0x80800E50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080061C_chdodgemcontrol(rdram, ctx);
        goto after_10;
    // 0x80800E50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80800E54: b           L_80800FB8
    // 0x80800E58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB8;
    // 0x80800E58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E5C:
    // 0x80800E5C: jal         0x808008EC
    // 0x80800E60: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    func_808008EC_chdodgemcontrol(rdram, ctx);
        goto after_11;
    // 0x80800E60: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    after_11:
    // 0x80800E64: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80800E68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800E6C: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    // 0x80800E70: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    // 0x80800E74: addiu       $a3, $zero, 0x10D7
    ctx->r7 = ADD32(0, 0X10D7);
    // 0x80800E78: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800E7C: bne         $at, $zero, L_80800E98
    if (ctx->r1 != 0) {
        // 0x80800E80: nop
    
            goto L_80800E98;
    }
    // 0x80800E80: nop

    // 0x80800E84: addiu       $a3, $zero, 0x10D5
    ctx->r7 = ADD32(0, 0X10D5);
    // 0x80800E88: jal         0x800D2054
    // 0x80800E8C: sh          $a3, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r7;
    func_800D2054(rdram, ctx);
        goto after_12;
    // 0x80800E8C: sh          $a3, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r7;
    after_12:
    // 0x80800E90: b           L_80800E98
    // 0x80800E94: lh          $a3, 0x5A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5A);
        goto L_80800E98;
    // 0x80800E94: lh          $a3, 0x5A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5A);
L_80800E98:
    // 0x80800E98: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800E9C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800EA0: jal         0x8080061C
    // 0x80800EA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080061C_chdodgemcontrol(rdram, ctx);
        goto after_13;
    // 0x80800EA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80800EA8: b           L_80800FB8
    // 0x80800EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB8;
    // 0x80800EAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800EB0:
    // 0x80800EB0: jal         0x808008EC
    // 0x80800EB4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    func_808008EC_chdodgemcontrol(rdram, ctx);
        goto after_14;
    // 0x80800EB4: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    after_14:
    // 0x80800EB8: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80800EBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800EC0: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80800EC4: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    // 0x80800EC8: addiu       $a3, $zero, 0x10D7
    ctx->r7 = ADD32(0, 0X10D7);
    // 0x80800ECC: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800ED0: bne         $at, $zero, L_80800EEC
    if (ctx->r1 != 0) {
        // 0x80800ED4: nop
    
            goto L_80800EEC;
    }
    // 0x80800ED4: nop

    // 0x80800ED8: addiu       $a3, $zero, 0x10D6
    ctx->r7 = ADD32(0, 0X10D6);
    // 0x80800EDC: jal         0x800D2054
    // 0x80800EE0: sh          $a3, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r7;
    func_800D2054(rdram, ctx);
        goto after_15;
    // 0x80800EE0: sh          $a3, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r7;
    after_15:
    // 0x80800EE4: b           L_80800EEC
    // 0x80800EE8: lh          $a3, 0x5A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5A);
        goto L_80800EEC;
    // 0x80800EE8: lh          $a3, 0x5A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5A);
L_80800EEC:
    // 0x80800EEC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800EF0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800EF4: jal         0x8080061C
    // 0x80800EF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080061C_chdodgemcontrol(rdram, ctx);
        goto after_16;
    // 0x80800EF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x80800EFC: b           L_80800FB8
    // 0x80800F00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800FB8;
    // 0x80800F00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800F04:
    // 0x80800F04: lbu         $t8, 0xC2($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0XC2);
    // 0x80800F08: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80800F0C: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800F10: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80800F14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800F18: jal         0x80089978
    // 0x80800F1C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    _sumultiscore_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x80800F1C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_17:
    // 0x80800F20: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80800F24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800F28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800F2C: lbu         $t2, 0xC2($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XC2);
    // 0x80800F30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800F34: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80800F38: blez        $t2, L_80800F70
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80800F3C: or          $v1, $t1, $zero
        ctx->r3 = ctx->r9 | 0;
            goto L_80800F70;
    }
    // 0x80800F3C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80800F40:
    // 0x80800F40: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80800F44: bnel        $t0, $t3, L_80800F58
    if (ctx->r8 != ctx->r11) {
        // 0x80800F48: sw          $zero, 0x20($v1)
        MEM_W(0X20, ctx->r3) = 0;
            goto L_80800F58;
    }
    goto skip_1;
    // 0x80800F48: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    skip_1:
    // 0x80800F4C: b           L_80800F58
    // 0x80800F50: sw          $t0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r8;
        goto L_80800F58;
    // 0x80800F50: sw          $t0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r8;
    // 0x80800F54: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
L_80800F58:
    // 0x80800F58: lbu         $t4, 0xC2($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0XC2);
    // 0x80800F5C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80800F60: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800F64: slt         $at, $a1, $t4
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80800F68: bne         $at, $zero, L_80800F40
    if (ctx->r1 != 0) {
        // 0x80800F6C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80800F40;
    }
    // 0x80800F6C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80800F70:
    // 0x80800F70: beq         $v0, $zero, L_80800F94
    if (ctx->r2 == 0) {
        // 0x80800F74: addiu       $a3, $zero, 0x10DA
        ctx->r7 = ADD32(0, 0X10DA);
            goto L_80800F94;
    }
    // 0x80800F74: addiu       $a3, $zero, 0x10DA
    ctx->r7 = ADD32(0, 0X10DA);
    // 0x80800F78: addiu       $a3, $zero, 0x10D9
    ctx->r7 = ADD32(0, 0X10D9);
    // 0x80800F7C: sb          $a2, 0xC1($t1)
    MEM_B(0XC1, ctx->r9) = ctx->r6;
    // 0x80800F80: sh          $a3, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r7;
    // 0x80800F84: jal         0x800FC6B0
    // 0x80800F88: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_18;
    // 0x80800F88: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_18:
    // 0x80800F8C: b           L_80800FA4
    // 0x80800F90: lh          $a3, 0x5A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5A);
        goto L_80800FA4;
    // 0x80800F90: lh          $a3, 0x5A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5A);
L_80800F94:
    // 0x80800F94: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80800F98: jal         0x800FC6B0
    // 0x80800F9C: sh          $a3, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r7;
    func_800FC6B0(rdram, ctx);
        goto after_19;
    // 0x80800F9C: sh          $a3, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r7;
    after_19:
    // 0x80800FA0: lh          $a3, 0x5A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X5A);
L_80800FA4:
    // 0x80800FA4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80800FA8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800FAC: jal         0x8080061C
    // 0x80800FB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080061C_chdodgemcontrol(rdram, ctx);
        goto after_20;
    // 0x80800FB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x80800FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800FB8:
    // 0x80800FB8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800FBC: jr          $ra
    // 0x80800FC0: nop

    return;
    // 0x80800FC0: nop

;}
RECOMP_FUNC void sulights_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005D4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808005D8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808005DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808005E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808005E8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x808005EC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808005F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808005F4: jal         0x80800000
    // 0x808005F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800000_sulights(rdram, ctx);
        goto after_0;
    // 0x808005F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808005FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3374, 0X9E8) << 16);
    // 0x80800600: lwc1        $f2, 0x9E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3374, 0X9E8));
    // 0x80800604: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800608: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080060C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800610: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800614: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800618: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8080061C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800620: bc1fl       L_80800634
    if (!c1cs) {
        // 0x80800624: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_80800634;
    }
    goto skip_0;
    // 0x80800624: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x80800628: b           L_80800634
    // 0x8080062C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80800634;
    // 0x8080062C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80800630: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80800634:
    // 0x80800634: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800638: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8080063C: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
    // 0x80800640: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80800644: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80800648: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x8080064C: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x80800650: lw          $t8, 0x8($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X8);
    // 0x80800654: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x80800658: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8080065C: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x80800660: lw          $t0, 0x4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X4);
    // 0x80800664: sw          $t0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r8;
    // 0x80800668: lw          $t1, 0x8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8);
    // 0x8080066C: sw          $t1, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r9;
    // 0x80800670: jal         0x800C8E84
    // 0x80800674: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800C8E84(rdram, ctx);
        goto after_1;
    // 0x80800674: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080067C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800680: jr          $ra
    // 0x80800684: nop

    return;
    // 0x80800684: nop

;}
RECOMP_FUNC void func_800C5148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5148: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C514C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C5150: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5154: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C5158: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C515C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C5160: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800C5164: jal         0x800C5094
    // 0x800C5168: swc1        $f12, -0x5610($at)
    MEM_W(-0X5610, ctx->r1) = ctx->f12.u32l;
    func_800C5094(rdram, ctx);
        goto after_0;
    // 0x800C5168: swc1        $f12, -0x5610($at)
    MEM_W(-0X5610, ctx->r1) = ctx->f12.u32l;
    after_0:
    // 0x800C516C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C5170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C5174: jr          $ra
    // 0x800C5178: nop

    return;
    // 0x800C5178: nop

;}
RECOMP_FUNC void _ncbapivot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089478: syscall     781
    recomp_syscall_handler(rdram, ctx, 0x80089478);
    return;
    // 0x8008947C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void sukickball_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800278: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080027C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800284: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800288: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080028C: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80800290: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3166, 0X1218) << 16);
    // 0x80800294: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800298: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8080029C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808002A0: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x808002A4: jal         0x800DF744
    // 0x808002A8: lw          $a1, 0x1218($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(3166, 0X1218));
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x808002A8: lw          $a1, 0x1218($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(3166, 0X1218));
    after_0:
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: jal         0x80101870
    // 0x808002B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x808002B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x808002B8: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x808002BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808002C0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x808002C4: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x808002C8: bgez        $t1, L_808002D8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808002CC: lui         $a3, 0x3F00
        ctx->r7 = S32(0X3F00 << 16);
            goto L_808002D8;
    }
    // 0x808002CC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x808002D0: jal         0x80800000
    // 0x808002D4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80800000_sukickball(rdram, ctx);
        goto after_2;
    // 0x808002D4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
L_808002D8:
    // 0x808002D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002E4: jr          $ra
    // 0x808002E8: nop

    return;
    // 0x808002E8: nop

;}
RECOMP_FUNC void func_80095964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80095968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009596C: beq         $a1, $zero, L_80095998
    if (ctx->r5 == 0) {
        // 0x80095970: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80095998;
    }
    // 0x80095970: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80095974: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80095978: jal         0x80095A08
    // 0x8009597C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80095A08(rdram, ctx);
        goto after_0;
    // 0x8009597C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80095980: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80095984: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80095988: jal         0x80095A08
    // 0x8009598C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80095A08(rdram, ctx);
        goto after_1;
    // 0x8009598C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80095990: b           L_800959BC
    // 0x80095994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800959BC;
    // 0x80095994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80095998:
    // 0x80095998: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8009599C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800959A0: jal         0x80095A08
    // 0x800959A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80095A08(rdram, ctx);
        goto after_2;
    // 0x800959A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800959A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800959AC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800959B0: jal         0x80095A08
    // 0x800959B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80095A08(rdram, ctx);
        goto after_3;
    // 0x800959B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800959B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800959BC:
    // 0x800959BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800959C0: jr          $ra
    // 0x800959C4: nop

    return;
    // 0x800959C4: nop

;}
RECOMP_FUNC void _chnests_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085AC8: syscall     191
    recomp_syscall_handler(rdram, ctx, 0x80085AC8);
    return;
    // 0x80085ACC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_800A5800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5800: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A5804: addiu       $v1, $v1, -0x6AC0
    ctx->r3 = ADD32(ctx->r3, -0X6AC0);
    // 0x800A5808: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800A580C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5814: sw          $a0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r4;
    // 0x800A5818: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800A581C: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800A5820: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800A5824: lbu         $a0, 0x3C($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3C);
    // 0x800A5828: jal         0x800A5790
    // 0x800A582C: lbu         $a1, 0x3D($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X3D);
    func_800A5790(rdram, ctx);
        goto after_0;
    // 0x800A582C: lbu         $a1, 0x3D($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X3D);
    after_0:
    // 0x800A5830: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A5834: addiu       $v1, $v1, -0x6AC0
    ctx->r3 = ADD32(ctx->r3, -0X6AC0);
    // 0x800A5838: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800A583C: sw          $v0, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r2;
    // 0x800A5840: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800A5844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5848: lw          $v0, 0x34($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X34);
    // 0x800A584C: jr          $ra
    // 0x800A5850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800A5850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _babounce_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845D8: syscall     116
    recomp_syscall_handler(rdram, ctx, 0x800845D8);
    return;
    // 0x800845DC: xori        $t0, $zero, 0x10
    ctx->r8 = 0 ^ 0X10;
;}
RECOMP_FUNC void func_80800F74_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800F7C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800F88: lw          $a1, 0x6C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X6C);
    // 0x80800F8C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800F90: andi        $t7, $a1, 0x1FF
    ctx->r15 = ctx->r5 & 0X1FF;
    // 0x80800F94: jal         0x800DF744
    // 0x80800F98: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x80800F98: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_0:
    // 0x80800F9C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800FA0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800FA4: lw          $a1, 0x64($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X64);
    // 0x80800FA8: sll         $t9, $a1, 12
    ctx->r25 = S32(ctx->r5 << 12);
    // 0x80800FAC: jal         0x800DF744
    // 0x80800FB0: srl         $a1, $t9, 31
    ctx->r5 = S32(U32(ctx->r25) >> 31);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800FB0: srl         $a1, $t9, 31
    ctx->r5 = S32(U32(ctx->r25) >> 31);
    after_1:
    // 0x80800FB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800FB8: jal         0x80101870
    // 0x80800FBC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_2;
    // 0x80800FBC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FC8: jr          $ra
    // 0x80800FCC: nop

    return;
    // 0x80800FCC: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083CC0: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083CC0);
    return;
    // 0x80083CC4: addi        $t0, $zero, 0x70
    ctx->r8 = ADD32(0, 0X70);
;}
RECOMP_FUNC void bssplitup_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C0: jr          $ra
    // 0x808004C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808004C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800000_bskazmove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080000C: jal         0x80084FE0
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _bashoes_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800010: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800014: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800018: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8080001C: beq         $v0, $at, L_80800040
    if (ctx->r2 == ctx->r1) {
        // 0x80800020: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80800040;
    }
    // 0x80800020: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800024: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800028: beq         $v0, $at, L_8080005C
    if (ctx->r2 == ctx->r1) {
        // 0x8080002C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8080005C;
    }
    // 0x8080002C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800030: beql        $v0, $at, L_8080007C
    if (ctx->r2 == ctx->r1) {
        // 0x80800034: lui         $at, 0x437A
        ctx->r1 = S32(0X437A << 16);
            goto L_8080007C;
    }
    goto skip_0;
    // 0x80800034: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    skip_0:
    // 0x80800038: b           L_80800094
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800094;
    // 0x8080003C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800040:
    // 0x80800040: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800044: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800048: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x8080004C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800050: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80800054: b           L_80800090
    // 0x80800058: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
        goto L_80800090;
    // 0x80800058: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_8080005C:
    // 0x8080005C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800060: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800064: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800068: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080006C: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80800070: b           L_80800090
    // 0x80800074: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
        goto L_80800090;
    // 0x80800074: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x80800078: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
L_8080007C:
    // 0x8080007C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800080: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800084: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800088: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8080008C: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
L_80800090:
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800094:
    // 0x80800094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800098: jr          $ra
    // 0x8080009C: nop

    return;
    // 0x8080009C: nop

;}
RECOMP_FUNC void func_80800000_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x801022E4
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: addiu       $t6, $v0, -0x435
    ctx->r14 = ADD32(ctx->r2, -0X435);
    // 0x80800018: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x8080001C: beq         $at, $zero, L_8080016C
    if (ctx->r1 == 0) {
        // 0x80800020: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080016C;
    }
    // 0x80800020: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800024: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X96D0) << 16);
    // 0x80800028: addu        $at, $at, $t6
    gpr jr_addend_80800030 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080002C: lw          $t6, -0x6930($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1480, 0X96D0));
    // 0x80800030: jr          $t6
    // 0x80800034: nop

    switch (jr_addend_80800030 >> 2) {
        case 0: goto L_80800038; break;
        case 1: goto L_808000BC; break;
        case 2: goto L_808000DC; break;
        case 3: goto L_8080016C; break;
        case 4: goto L_8080016C; break;
        case 5: goto L_8080016C; break;
        case 6: goto L_8080007C; break;
        case 7: goto L_8080016C; break;
        case 8: goto L_8080016C; break;
        case 9: goto L_8080016C; break;
        case 10: goto L_8080016C; break;
        case 11: goto L_80800100; break;
        default: switch_error(__func__, 0x80800030, 0x808096D0);
    }
    // 0x80800034: nop

L_80800038:
    // 0x80800038: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080003C: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9DB8) << 16);
    // 0x80800040: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80800044: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800048: addiu       $a2, $a2, -0x6248
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9DB8));
    // 0x8080004C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800050: jal         0x80089D20
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800058: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9DCC) << 16);
    // 0x8080005C: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x80800060: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800064: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800068: addiu       $a2, $a2, -0x6234
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9DCC));
    // 0x8080006C: jal         0x80089D20
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800074: b           L_80800170
    // 0x80800078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800170;
    // 0x80800078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080007C:
    // 0x8080007C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800080: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9DB8) << 16);
    // 0x80800084: addiu       $a2, $a2, -0x6248
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9DB8));
    // 0x80800088: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800090: jal         0x80089D20
    // 0x80800094: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800094: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_3:
    // 0x80800098: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9DCC) << 16);
    // 0x8080009C: lui         $a3, 0x3F59
    ctx->r7 = S32(0X3F59 << 16);
    // 0x808000A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808000A4: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808000A8: addiu       $a2, $a2, -0x6234
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9DCC));
    // 0x808000AC: jal         0x80089D20
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000B4: b           L_80800170
    // 0x808000B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800170;
    // 0x808000B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000BC:
    // 0x808000BC: jal         0x80101DDC
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_5;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000C4: beq         $v0, $zero, L_8080016C
    if (ctx->r2 == 0) {
        // 0x808000C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080016C;
    }
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000CC: jal         0x80800180
    // 0x808000D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x808000D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x808000D4: b           L_80800170
    // 0x808000D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800170;
    // 0x808000D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000DC:
    // 0x808000DC: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9DE4) << 16);
    // 0x808000E0: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x808000E4: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808000E8: addiu       $a2, $a2, -0x621C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9DE4));
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x80089D20
    // 0x808000F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x808000F4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x808000F8: b           L_80800170
    // 0x808000FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800170;
    // 0x808000FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800100:
    // 0x80800100: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800104: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9DFC) << 16);
    // 0x80800108: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x8080010C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800110: addiu       $a2, $a2, -0x6204
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9DFC));
    // 0x80800114: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800118: jal         0x80089D20
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800120: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0X9E10) << 16);
    // 0x80800124: lui         $a3, 0x3F59
    ctx->r7 = S32(0X3F59 << 16);
    // 0x80800128: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080012C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800130: addiu       $a2, $a2, -0x61F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0X9E10));
    // 0x80800134: jal         0x80089D20
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: jal         0x80101E14
    // 0x80800144: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    func_80101E14(rdram, ctx);
        goto after_10;
    // 0x80800144: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_10:
    // 0x80800148: beql        $v0, $zero, L_80800170
    if (ctx->r2 == 0) {
        // 0x8080014C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800170;
    }
    goto skip_0;
    // 0x8080014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800150: jal         0x80802228
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800158: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080015C: jal         0x80100094
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800164: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800168: sb          $t7, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r15;
L_8080016C:
    // 0x8080016C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800170:
    // 0x80800170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800174: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void func_808020EC_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808020EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808020F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808020F4: jal         0x80800E54
    // 0x808020F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstnt_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808020F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808020FC: jal         0x80090A2C
    // 0x80802100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80090A2C(rdram, ctx);
        goto after_1;
    // 0x80802100: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80802104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080210C: jr          $ra
    // 0x80802110: nop

    return;
    // 0x80802110: nop

;}
RECOMP_FUNC void func_800ED7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED7F8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800ED7FC: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800ED800: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x800ED804: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800ED808: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800ED80C: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800ED810: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800ED814: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800ED818: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800ED81C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800ED820: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800ED824: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x800ED828: lh          $t7, 0x14($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X14);
    // 0x800ED82C: lh          $t6, 0x1A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1A);
    // 0x800ED830: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED834: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800ED838: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800ED83C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800ED840: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800ED844: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800ED848: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800ED84C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800ED850: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800ED854: sll         $t2, $a3, 4
    ctx->r10 = S32(ctx->r7 << 4);
    // 0x800ED858: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800ED85C: addu        $s3, $t2, $a1
    ctx->r19 = ADD32(ctx->r10, ctx->r5);
    // 0x800ED860: sltu        $at, $a1, $s3
    ctx->r1 = ctx->r5 < ctx->r19 ? 1 : 0;
    // 0x800ED864: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800ED868: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800ED86C: addiu       $s2, $sp, 0x48
    ctx->r18 = ADD32(ctx->r29, 0X48);
    // 0x800ED870: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800ED874: nop

    // 0x800ED878: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800ED87C: add.s       $f20, $f0, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800ED880: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800ED884: lh          $t0, 0x16($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X16);
    // 0x800ED888: lh          $t9, 0x1C($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X1C);
    // 0x800ED88C: swc1        $f22, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f22.u32l;
    // 0x800ED890: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800ED894: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800ED898: nop

    // 0x800ED89C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800ED8A0: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800ED8A4: beq         $at, $zero, L_800ED940
    if (ctx->r1 == 0) {
        // 0x800ED8A8: swc1        $f18, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
            goto L_800ED940;
    }
    // 0x800ED8A8: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
L_800ED8AC:
    // 0x800ED8AC: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x800ED8B0: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x800ED8B4: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800ED8B8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800ED8BC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800ED8C0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800ED8C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800ED8C8: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800ED8CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800ED8D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800ED8D4: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800ED8D8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800ED8DC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800ED8E0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800ED8E4: jal         0x800EFA4C
    // 0x800ED8E8: nop

    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800ED8E8: nop

    after_0:
    // 0x800ED8EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800ED8F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800ED8F4: jal         0x800EF9A8
    // 0x800ED8F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF9A8(rdram, ctx);
        goto after_1;
    // 0x800ED8F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800ED8FC: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800ED900: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800ED904: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800ED908: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x800ED90C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800ED910: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800ED914: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800ED918: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800ED91C: nop

    // 0x800ED920: sh          $t6, -0x10($s1)
    MEM_H(-0X10, ctx->r17) = ctx->r14;
    // 0x800ED924: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800ED928: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800ED92C: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ED930: trunc.w.s   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800ED934: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800ED938: bne         $at, $zero, L_800ED8AC
    if (ctx->r1 != 0) {
        // 0x800ED93C: sh          $t8, -0xE($s1)
        MEM_H(-0XE, ctx->r17) = ctx->r24;
            goto L_800ED8AC;
    }
    // 0x800ED93C: sh          $t8, -0xE($s1)
    MEM_H(-0XE, ctx->r17) = ctx->r24;
L_800ED940:
    // 0x800ED940: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800ED944: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800ED948: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800ED94C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800ED950: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800ED954: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800ED958: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800ED95C: jr          $ra
    // 0x800ED960: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800ED960: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8080103C_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080103C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801044: jal         0x800897C8
    // 0x80801048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80801048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080104C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801054: jr          $ra
    // 0x80801058: nop

    return;
    // 0x80801058: nop

    // 0x8080105C: nop

;}
RECOMP_FUNC void func_800EDCEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDCEC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EDCF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EDCF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EDCF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800EDCFC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800EDD00: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800EDD04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800EDD08: jal         0x800EDC64
    // 0x800EDD0C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800EDC64(rdram, ctx);
        goto after_0;
    // 0x800EDD0C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x800EDD10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EDD14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EDD18: jr          $ra
    // 0x800EDD1C: nop

    return;
    // 0x800EDD1C: nop

;}
RECOMP_FUNC void _bsbkflamethrower_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829A0: syscall     23
    recomp_syscall_handler(rdram, ctx, 0x800829A0);
    return;
    // 0x800829A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
