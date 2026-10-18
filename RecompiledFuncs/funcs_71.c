#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _idworldmake_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F58: syscall     749
    recomp_syscall_handler(rdram, ctx, 0x80088F58);
    return;
    // 0x80088F5C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80800298_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800298: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8080029C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002A8: jal         0x80100094
    // 0x808002AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002B0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808002B4: lui         $a3, 0x4409
    ctx->r7 = S32(0X4409 << 16);
    // 0x808002B8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808002BC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x808002C0: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x808002C4: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x808002C8: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x808002CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002D0: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x808002D4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x808002D8: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x808002DC: jal         0x80089F20
    // 0x808002E0: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808002E0: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    after_1:
    // 0x808002E4: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x808002E8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x808002EC: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x808002F0: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808002F4: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x808002F8: bne         $at, $zero, L_80800310
    if (ctx->r1 != 0) {
        // 0x808002FC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80800310;
    }
    // 0x808002FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800300: lh          $t0, 0x8A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X8A);
    // 0x80800304: addiu       $a0, $zero, 0xF3
    ctx->r4 = ADD32(0, 0XF3);
    // 0x80800308: jal         0x800D2498
    // 0x8080030C: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    func_800D2498(rdram, ctx);
        goto after_2;
    // 0x8080030C: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    after_2:
L_80800310:
    // 0x80800310: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800314: jal         0x800D0B68
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_3;
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080031C: bne         $v0, $zero, L_80800360
    if (ctx->r2 != 0) {
        // 0x80800320: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_80800360;
    }
    // 0x80800320: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800324: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800328: jal         0x8008A0E0
    // 0x8080032C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x8080032C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_4:
    // 0x80800330: beq         $v0, $zero, L_80800360
    if (ctx->r2 == 0) {
        // 0x80800334: lwc1        $f4, 0x48($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80800360;
    }
    // 0x80800334: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800338: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080033C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800340: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800344: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800348: nop

    // 0x8080034C: bc1f        L_80800358
    if (!c1cs) {
        // 0x80800350: nop
    
            goto L_80800358;
    }
    // 0x80800350: nop

    // 0x80800354: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
L_80800358:
    // 0x80800358: jal         0x800D1254
    // 0x8080035C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800D1254(rdram, ctx);
        goto after_5;
    // 0x8080035C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_5:
L_80800360:
    // 0x80800360: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    // 0x80800364: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80800368: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8080036C: sltiu       $at, $t4, 0x1A
    ctx->r1 = ctx->r12 < 0X1A ? 1 : 0;
    // 0x80800370: beq         $at, $zero, L_808008A8
    if (ctx->r1 == 0) {
        // 0x80800374: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_808008A8;
    }
    // 0x80800374: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80800378: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X2400) << 16);
    // 0x8080037C: addu        $at, $at, $t4
    gpr jr_addend_80800384 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80800380: lw          $t4, 0x2400($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1312, 0X2400));
    // 0x80800384: jr          $t4
    // 0x80800388: nop

    switch (jr_addend_80800384 >> 2) {
        case 0: goto L_8080038C; break;
        case 1: goto L_808008A8; break;
        case 2: goto L_80800414; break;
        case 3: goto L_80800528; break;
        case 4: goto L_80800480; break;
        case 5: goto L_80800528; break;
        case 6: goto L_80800538; break;
        case 7: goto L_808005D4; break;
        case 8: goto L_80800604; break;
        case 9: goto L_80800894; break;
        case 10: goto L_80800644; break;
        case 11: goto L_80800658; break;
        case 12: goto L_80800688; break;
        case 13: goto L_80800894; break;
        case 14: goto L_808006C8; break;
        case 15: goto L_808006DC; break;
        case 16: goto L_8080070C; break;
        case 17: goto L_80800894; break;
        case 18: goto L_8080074C; break;
        case 19: goto L_80800760; break;
        case 20: goto L_80800790; break;
        case 21: goto L_80800894; break;
        case 22: goto L_80800528; break;
        case 23: goto L_808007CC; break;
        case 24: goto L_80800874; break;
        case 25: goto L_808008A0; break;
        default: switch_error(__func__, 0x80800384, 0x80802400);
    }
    // 0x80800388: nop

L_8080038C:
    // 0x8080038C: jal         0x800DA298
    // 0x80800390: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800390: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_6:
    // 0x80800394: bnel        $v0, $zero, L_808003D4
    if (ctx->r2 != 0) {
        // 0x80800398: lw          $v0, 0x5C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X5C);
            goto L_808003D4;
    }
    goto skip_0;
    // 0x80800398: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x8080039C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x808003A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808003A4: addiu       $a1, $zero, 0xF43
    ctx->r5 = ADD32(0, 0XF43);
    // 0x808003A8: lbu         $t5, 0x1D0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1D0);
    // 0x808003AC: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    // 0x808003B0: addiu       $t7, $zero, 0xB2
    ctx->r15 = ADD32(0, 0XB2);
    // 0x808003B4: bnel        $t5, $zero, L_808003D4
    if (ctx->r13 != 0) {
        // 0x808003B8: lw          $v0, 0x5C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X5C);
            goto L_808003D4;
    }
    goto skip_1;
    // 0x808003B8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    skip_1:
    // 0x808003BC: sb          $t6, 0x1D0($v0)
    MEM_B(0X1D0, ctx->r2) = ctx->r14;
    // 0x808003C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808003C4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808003C8: jal         0x8008A208
    // 0x808003CC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808003CC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x808003D0: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
L_808003D4:
    // 0x808003D4: lbu         $t8, 0x1CF($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1CF);
    // 0x808003D8: beql        $t8, $zero, L_808008AC
    if (ctx->r24 == 0) {
        // 0x808003DC: lw          $v1, 0x54($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X54);
            goto L_808008AC;
    }
    goto skip_2;
    // 0x808003DC: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x808003E0: lbu         $t9, 0x1CE($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1CE);
    // 0x808003E4: beql        $t9, $zero, L_808008AC
    if (ctx->r25 == 0) {
        // 0x808003E8: lw          $v1, 0x54($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X54);
            goto L_808008AC;
    }
    goto skip_3;
    // 0x808003E8: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    skip_3:
    // 0x808003EC: jal         0x800F54E4
    // 0x808003F0: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x808003F0: nop

    after_8:
    // 0x808003F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003F8: jal         0x800F82D4
    // 0x808003FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_9;
    // 0x808003FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: jal         0x80800DA8
    // 0x80800408: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_10;
    // 0x80800408: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x8080040C: b           L_808008AC
    // 0x80800410: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x80800410: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_80800414:
    // 0x80800414: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800418: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8080041C: jal         0x80101E14
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_11;
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800424: beql        $v0, $zero, L_80800438
    if (ctx->r2 == 0) {
        // 0x80800428: lui         $a1, 0x3EB3
        ctx->r5 = S32(0X3EB3 << 16);
            goto L_80800438;
    }
    goto skip_4;
    // 0x80800428: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    skip_4:
    // 0x8080042C: jal         0x80801C78
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C78_chstatueboss(rdram, ctx);
        goto after_12;
    // 0x80800430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800434: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
L_80800438:
    // 0x80800438: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x8080043C: jal         0x80801A6C
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A6C_chstatueboss(rdram, ctx);
        goto after_13;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800444: jal         0x80101DDC
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_14;
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8080044C: beq         $v0, $zero, L_808008A8
    if (ctx->r2 == 0) {
        // 0x80800450: addiu       $a1, $zero, 0xF33
        ctx->r5 = ADD32(0, 0XF33);
            goto L_808008A8;
    }
    // 0x80800450: addiu       $a1, $zero, 0xF33
    ctx->r5 = ADD32(0, 0XF33);
    // 0x80800454: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800458: addiu       $t1, $zero, 0xB2
    ctx->r9 = ADD32(0, 0XB2);
    // 0x8080045C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800460: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800464: jal         0x8008A208
    // 0x80800468: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x80800468: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: jal         0x80800DA8
    // 0x80800474: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_16;
    // 0x80800474: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
    // 0x80800478: b           L_808008AC
    // 0x8080047C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x8080047C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_80800480:
    // 0x80800480: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1312, 0X2790) << 16);
    // 0x80800484: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1312, 0X27AC) << 16);
    // 0x80800488: addiu       $a3, $a3, 0x27AC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1312, 0X27AC));
    // 0x8080048C: addiu       $a2, $a2, 0x2790
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1312, 0X2790));
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800494: jal         0x80089D28
    // 0x80800498: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_17;
    // 0x80800498: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_17:
    // 0x8080049C: beq         $v0, $zero, L_808004C4
    if (ctx->r2 == 0) {
        // 0x808004A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808004C4;
    }
    // 0x808004A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004A4: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808004A8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808004AC: jal         0x800E15CC
    // 0x808004B0: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_800E15CC(rdram, ctx);
        goto after_18;
    // 0x808004B0: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_18:
    // 0x808004B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004B8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x808004BC: jal         0x80018820
    // 0x808004C0: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    func_80018820(rdram, ctx);
        goto after_19;
    // 0x808004C0: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_19:
L_808004C4:
    // 0x808004C4: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x808004C8: lui         $a2, 0x3F7D
    ctx->r6 = S32(0X3F7D << 16);
    // 0x808004CC: ori         $a2, $a2, 0x70A4
    ctx->r6 = ctx->r6 | 0X70A4;
    // 0x808004D0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808004D4: jal         0x80102320
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102320(rdram, ctx);
        goto after_20;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808004DC: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x808004E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E4: jal         0x80801AC4
    // 0x808004E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80801AC4_chstatueboss(rdram, ctx);
        goto after_21;
    // 0x808004E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_21:
    // 0x808004EC: jal         0x80101DDC
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_22;
    // 0x808004F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808004F4: beq         $v0, $zero, L_808008A8
    if (ctx->r2 == 0) {
        // 0x808004F8: addiu       $a1, $zero, 0xF34
        ctx->r5 = ADD32(0, 0XF34);
            goto L_808008A8;
    }
    // 0x808004F8: addiu       $a1, $zero, 0xF34
    ctx->r5 = ADD32(0, 0XF34);
    // 0x808004FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800500: addiu       $t0, $zero, 0xB2
    ctx->r8 = ADD32(0, 0XB2);
    // 0x80800504: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800508: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8080050C: jal         0x8008A208
    // 0x80800510: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_23;
    // 0x80800510: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_23:
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800518: jal         0x80800DA8
    // 0x8080051C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_24;
    // 0x8080051C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_24:
    // 0x80800520: b           L_808008AC
    // 0x80800524: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x80800524: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_80800528:
    // 0x80800528: jal         0x80801AF0
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_chstatueboss(rdram, ctx);
        goto after_25;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800530: b           L_808008AC
    // 0x80800534: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x80800534: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_80800538:
    // 0x80800538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080053C: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80800540: jal         0x8008A0D0
    // 0x80800544: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_26;
    // 0x80800544: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_26:
    // 0x80800548: beq         $v0, $zero, L_8080057C
    if (ctx->r2 == 0) {
        // 0x8080054C: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_8080057C;
    }
    // 0x8080054C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800550: jal         0x800F1DF4
    // 0x80800554: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F1DF4(rdram, ctx);
        goto after_27;
    // 0x80800554: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_27:
    // 0x80800558: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080055C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800560: jal         0x800EF1B8
    // 0x80800564: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_28;
    // 0x80800564: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    after_28:
    // 0x80800568: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8080056C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800570: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    // 0x80800574: jal         0x80089F18
    // 0x80800578: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_29;
    // 0x80800578: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_29:
L_8080057C:
    // 0x8080057C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800580: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80800584: jal         0x8008A0D0
    // 0x80800588: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_30;
    // 0x80800588: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_30:
    // 0x8080058C: beq         $v0, $zero, L_808005C0
    if (ctx->r2 == 0) {
        // 0x80800590: addiu       $a0, $sp, 0x38
        ctx->r4 = ADD32(ctx->r29, 0X38);
            goto L_808005C0;
    }
    // 0x80800590: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800594: jal         0x800F1DF4
    // 0x80800598: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F1DF4(rdram, ctx);
        goto after_31;
    // 0x80800598: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_31:
    // 0x8080059C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005A0: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808005A4: jal         0x800EF1B8
    // 0x808005A8: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_32;
    // 0x808005A8: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    after_32:
    // 0x808005AC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808005B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808005B4: lui         $a2, 0x437A
    ctx->r6 = S32(0X437A << 16);
    // 0x808005B8: jal         0x80089F18
    // 0x808005BC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_33;
    // 0x808005BC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_33:
L_808005C0:
    // 0x808005C0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x808005C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808005C8: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x808005CC: b           L_808008A8
    // 0x808005D0: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
        goto L_808008A8;
    // 0x808005D0: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
L_808005D4:
    // 0x808005D4: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x808005D8: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808005DC: jal         0x80801A6C
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A6C_chstatueboss(rdram, ctx);
        goto after_34;
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x808005E4: jal         0x80101DDC
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_35;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808005EC: beq         $v0, $zero, L_808008A8
    if (ctx->r2 == 0) {
        // 0x808005F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008A8;
    }
    // 0x808005F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F4: jal         0x80800DA8
    // 0x808005F8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_36;
    // 0x808005F8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_36:
    // 0x808005FC: b           L_808008AC
    // 0x80800600: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x80800600: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_80800604:
    // 0x80800604: jal         0x80801AF0
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_chstatueboss(rdram, ctx);
        goto after_37;
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x8080060C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80800610: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x80800614: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    // 0x80800618: jal         0x80089C30
    // 0x8080061C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_38;
    // 0x8080061C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x80800620: bnel        $v0, $zero, L_808008AC
    if (ctx->r2 != 0) {
        // 0x80800624: lw          $v1, 0x54($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X54);
            goto L_808008AC;
    }
    goto skip_5;
    // 0x80800624: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    skip_5:
    // 0x80800628: jal         0x80801C78
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C78_chstatueboss(rdram, ctx);
        goto after_39;
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800634: jal         0x80800DA8
    // 0x80800638: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_40;
    // 0x80800638: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_40:
    // 0x8080063C: b           L_808008AC
    // 0x80800640: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x80800640: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_80800644:
    // 0x80800644: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800648: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080064C: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    // 0x80800650: b           L_808008A8
    // 0x80800654: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
        goto L_808008A8;
    // 0x80800654: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_80800658:
    // 0x80800658: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x8080065C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800660: jal         0x80801A6C
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A6C_chstatueboss(rdram, ctx);
        goto after_41;
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80800668: jal         0x80101DDC
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_42;
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80800670: beq         $v0, $zero, L_808008A8
    if (ctx->r2 == 0) {
        // 0x80800674: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008A8;
    }
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: jal         0x80800DA8
    // 0x8080067C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_43;
    // 0x8080067C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_43:
    // 0x80800680: b           L_808008AC
    // 0x80800684: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x80800684: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_80800688:
    // 0x80800688: jal         0x80801AF0
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_chstatueboss(rdram, ctx);
        goto after_44;
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x80800690: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800694: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x80800698: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    // 0x8080069C: jal         0x80089C30
    // 0x808006A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_45;
    // 0x808006A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_45:
    // 0x808006A4: bnel        $v0, $zero, L_808008AC
    if (ctx->r2 != 0) {
        // 0x808006A8: lw          $v1, 0x54($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X54);
            goto L_808008AC;
    }
    goto skip_6;
    // 0x808006A8: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    skip_6:
    // 0x808006AC: jal         0x80801C78
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C78_chstatueboss(rdram, ctx);
        goto after_46;
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: jal         0x80800DA8
    // 0x808006BC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_47;
    // 0x808006BC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_47:
    // 0x808006C0: b           L_808008AC
    // 0x808006C4: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x808006C4: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_808006C8:
    // 0x808006C8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808006CC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808006D0: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x808006D4: b           L_808008A8
    // 0x808006D8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
        goto L_808008A8;
    // 0x808006D8: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_808006DC:
    // 0x808006DC: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x808006E0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808006E4: jal         0x80801A6C
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A6C_chstatueboss(rdram, ctx);
        goto after_48;
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x808006EC: jal         0x80101DDC
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_49;
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x808006F4: beq         $v0, $zero, L_808008A8
    if (ctx->r2 == 0) {
        // 0x808006F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008A8;
    }
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006FC: jal         0x80800DA8
    // 0x80800700: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_50;
    // 0x80800700: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_50:
    // 0x80800704: b           L_808008AC
    // 0x80800708: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x80800708: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_8080070C:
    // 0x8080070C: jal         0x80801AF0
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_chstatueboss(rdram, ctx);
        goto after_51;
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x80800714: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80800718: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x8080071C: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    // 0x80800720: jal         0x80089C30
    // 0x80800724: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_52;
    // 0x80800724: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_52:
    // 0x80800728: bnel        $v0, $zero, L_808008AC
    if (ctx->r2 != 0) {
        // 0x8080072C: lw          $v1, 0x54($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X54);
            goto L_808008AC;
    }
    goto skip_7;
    // 0x8080072C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    skip_7:
    // 0x80800730: jal         0x80801C78
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801C78_chstatueboss(rdram, ctx);
        goto after_53;
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080073C: jal         0x80800DA8
    // 0x80800740: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_54;
    // 0x80800740: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_54:
    // 0x80800744: b           L_808008AC
    // 0x80800748: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x80800748: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_8080074C:
    // 0x8080074C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800750: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800754: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x80800758: b           L_808008A8
    // 0x8080075C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
        goto L_808008A8;
    // 0x8080075C: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
L_80800760:
    // 0x80800760: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x80800764: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800768: jal         0x80801A6C
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A6C_chstatueboss(rdram, ctx);
        goto after_55;
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80800770: jal         0x80101DDC
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_56;
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x80800778: beq         $v0, $zero, L_808008A8
    if (ctx->r2 == 0) {
        // 0x8080077C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008A8;
    }
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800780: jal         0x80800DA8
    // 0x80800784: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_57;
    // 0x80800784: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_57:
    // 0x80800788: b           L_808008AC
    // 0x8080078C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x8080078C: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_80800790:
    // 0x80800790: jal         0x8080232C
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080232C_chstatueboss(rdram, ctx);
        goto after_58;
    // 0x80800794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x80800798: jal         0x80801AF0
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_chstatueboss(rdram, ctx);
        goto after_59;
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x808007A0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x808007A4: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x808007A8: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    // 0x808007AC: jal         0x80089C30
    // 0x808007B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_60;
    // 0x808007B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_60:
    // 0x808007B4: bne         $v0, $zero, L_808008A8
    if (ctx->r2 != 0) {
        // 0x808007B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008A8;
    }
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007BC: jal         0x80800DA8
    // 0x808007C0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_61;
    // 0x808007C0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_61:
    // 0x808007C4: b           L_808008AC
    // 0x808007C8: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x808007C8: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_808007CC:
    // 0x808007CC: jal         0x8080232C
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080232C_chstatueboss(rdram, ctx);
        goto after_62;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_62:
    // 0x808007D4: jal         0x800CEAD0
    // 0x808007D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CEAD0(rdram, ctx);
        goto after_63;
    // 0x808007D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_63:
    // 0x808007DC: beq         $v0, $zero, L_808008A8
    if (ctx->r2 == 0) {
        // 0x808007E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808008A8;
    }
    // 0x808007E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007E4: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808007E8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808007EC: jal         0x800E15CC
    // 0x808007F0: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_64;
    // 0x808007F0: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_64:
    // 0x808007F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808007F8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x808007FC: jal         0x80018820
    // 0x80800800: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    func_80018820(rdram, ctx);
        goto after_65;
    // 0x80800800: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_65:
    // 0x80800804: lw          $t4, 0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XC);
    // 0x80800808: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8080080C: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x80800810: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800814: lw          $t5, 0x48($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X48);
    // 0x80800818: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8080081C: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x80800820: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800824: jal         0x80086D50
    // 0x80800828: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_66;
    // 0x80800828: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_66:
    // 0x8080082C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80800830: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800838: lw          $a3, 0x80($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X80);
    // 0x8080083C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800840: addiu       $a1, $zero, 0x7CC
    ctx->r5 = ADD32(0, 0X7CC);
    // 0x80800844: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800848: jal         0x80086680
    // 0x8080084C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _chexploder_entrypoint_5(rdram, ctx);
        goto after_67;
    // 0x8080084C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_67:
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800854: jal         0x80108B04
    // 0x80800858: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80108B04(rdram, ctx);
        goto after_68;
    // 0x80800858: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_68:
    // 0x8080085C: jal         0x800DA544
    // 0x80800860: addiu       $a0, $zero, 0x36F
    ctx->r4 = ADD32(0, 0X36F);
    func_800DA544(rdram, ctx);
        goto after_69;
    // 0x80800860: addiu       $a0, $zero, 0x36F
    ctx->r4 = ADD32(0, 0X36F);
    after_69:
    // 0x80800864: jal         0x800FDC28
    // 0x80800868: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_70;
    // 0x80800868: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_70:
    // 0x8080086C: b           L_808008AC
    // 0x80800870: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x80800870: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_80800874:
    // 0x80800874: jal         0x800D9078
    // 0x80800878: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_71;
    // 0x80800878: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_71:
    // 0x8080087C: beql        $v0, $zero, L_808008AC
    if (ctx->r2 == 0) {
        // 0x80800880: lw          $v1, 0x54($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X54);
            goto L_808008AC;
    }
    goto skip_8;
    // 0x80800880: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    skip_8:
    // 0x80800884: jal         0x80088180
    // 0x80800888: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_72;
    // 0x80800888: nop

    after_72:
    // 0x8080088C: b           L_808008AC
    // 0x80800890: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
        goto L_808008AC;
    // 0x80800890: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_80800894:
    // 0x80800894: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80800898: b           L_808008A8
    // 0x8080089C: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
        goto L_808008A8;
    // 0x8080089C: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
L_808008A0:
    // 0x808008A0: jal         0x80801AF0
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AF0_chstatueboss(rdram, ctx);
        goto after_73;
    // 0x808008A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_73:
L_808008A8:
    // 0x808008A8: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
L_808008AC:
    // 0x808008AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B4: xori        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 ^ 0X1;
    // 0x808008B8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808008BC: bne         $v0, $zero, L_808008D4
    if (ctx->r2 != 0) {
        // 0x808008C0: nop
    
            goto L_808008D4;
    }
    // 0x808008C0: nop

    // 0x808008C4: beq         $v1, $at, L_808008E4
    if (ctx->r3 == ctx->r1) {
        // 0x808008C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008E4;
    }
    // 0x808008C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008CC: b           L_808008F4
    // 0x808008D0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
        goto L_808008F4;
    // 0x808008D0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
L_808008D4:
    // 0x808008D4: jal         0x808011B4
    // 0x808008D8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_808011B4_chstatueboss(rdram, ctx);
        goto after_74;
    // 0x808008D8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_74:
    // 0x808008DC: b           L_808008F0
    // 0x808008E0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_808008F0;
    // 0x808008E0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_808008E4:
    // 0x808008E4: jal         0x8080124C
    // 0x808008E8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8080124C_chstatueboss(rdram, ctx);
        goto after_75;
    // 0x808008E8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_75:
    // 0x808008EC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_808008F0:
    // 0x808008F0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
L_808008F4:
    // 0x808008F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F8: bne         $t7, $zero, L_80800904
    if (ctx->r15 != 0) {
        // 0x808008FC: nop
    
            goto L_80800904;
    }
    // 0x808008FC: nop

    // 0x80800900: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
L_80800904:
    // 0x80800904: jal         0x80801AC4
    // 0x80800908: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_80801AC4_chstatueboss(rdram, ctx);
        goto after_76;
    // 0x80800908: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_76:
    // 0x8080090C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800910: jal         0x80801804
    // 0x80800914: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_80801804_chstatueboss(rdram, ctx);
        goto after_77;
    // 0x80800914: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_77:
    // 0x80800918: jal         0x80801448
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801448_chstatueboss(rdram, ctx);
        goto after_78;
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x80800920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800924: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800928: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080092C: jr          $ra
    // 0x80800930: nop

    return;
    // 0x80800930: nop

;}
RECOMP_FUNC void bakaztorpedo_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000F4: lw          $t6, 0xB0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB0);
    // 0x808000F8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x808000FC: swc1        $f12, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f12.u32l;
    // 0x80800100: lw          $t7, 0xB0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB0);
    // 0x80800104: jr          $ra
    // 0x80800108: swc1        $f14, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x80800108: swc1        $f14, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_800A0CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0CDC: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x800A0CE0: jr          $ra
    // 0x800A0CE4: sb          $a1, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r5;
    return;
    // 0x800A0CE4: sb          $a1, 0xD($t6)
    MEM_B(0XD, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_808002D0_bsmumstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002D8: jal         0x80083808
    // 0x808002DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808002DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808002E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002E8: jal         0x8080011C
    // 0x808002EC: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_8080011C_bsmumstill(rdram, ctx);
        goto after_1;
    // 0x808002EC: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_1:
    // 0x808002F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002F8: jr          $ra
    // 0x808002FC: nop

    return;
    // 0x808002FC: nop

;}
RECOMP_FUNC void _badialog_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847C0: syscall     121
    recomp_syscall_handler(rdram, ctx, 0x800847C0);
    return;
    // 0x800847C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800E8918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8918: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800E891C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E8920: andi        $s0, $a0, 0xFF
    ctx->r16 = ctx->r4 & 0XFF;
    // 0x800E8924: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800E8928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E892C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800E8930: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8934: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800E8938: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800E893C: lw          $a0, -0x2A00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A00);
    // 0x800E8940: jal         0x800B301C
    // 0x800E8944: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x800E8944: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800E8948: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800E894C: lw          $t6, -0x2984($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2984);
    // 0x800E8950: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800E8954: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800E8958: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800E895C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800E8960: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E8964: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800E8968: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x800E896C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800E8970: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800E8974: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800E8978: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800E897C: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x800E8980: lh          $t0, 0x46($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X46);
    // 0x800E8984: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800E8988: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800E898C: beq         $t0, $zero, L_800E8998
    if (ctx->r8 == 0) {
        // 0x800E8990: addiu       $a3, $sp, 0x24
        ctx->r7 = ADD32(ctx->r29, 0X24);
            goto L_800E8998;
    }
    // 0x800E8990: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x800E8994: sh          $zero, 0x36($s0)
    MEM_H(0X36, ctx->r16) = 0;
L_800E8998:
    // 0x800E8998: jal         0x800C4C34
    // 0x800E899C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800C4C34(rdram, ctx);
        goto after_1;
    // 0x800E899C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800E89A0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800E89A4: beql        $t1, $zero, L_800E89E0
    if (ctx->r9 == 0) {
        // 0x800E89A8: lw          $v0, 0x4C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X4C);
            goto L_800E89E0;
    }
    goto skip_0;
    // 0x800E89A8: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    skip_0:
    // 0x800E89AC: beq         $v0, $zero, L_800E89DC
    if (ctx->r2 == 0) {
        // 0x800E89B0: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_800E89DC;
    }
    // 0x800E89B0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800E89B4: jal         0x800E3928
    // 0x800E89B8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800E3928(rdram, ctx);
        goto after_2;
    // 0x800E89B8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x800E89BC: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x800E89C0: jal         0x800E3980
    // 0x800E89C4: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_800E3980(rdram, ctx);
        goto after_3;
    // 0x800E89C4: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_3:
    // 0x800E89C8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x800E89CC: jal         0x800EE7F8
    // 0x800E89D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x800E89D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x800E89D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800E89D8: sh          $t2, 0x36($s0)
    MEM_H(0X36, ctx->r16) = ctx->r10;
L_800E89DC:
    // 0x800E89DC: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
L_800E89E0:
    // 0x800E89E0: beql        $v0, $zero, L_800E89FC
    if (ctx->r2 == 0) {
        // 0x800E89E4: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_800E89FC;
    }
    goto skip_1;
    // 0x800E89E4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    skip_1:
    // 0x800E89E8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E89EC: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800E89F0: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800E89F4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x800E89F8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_800E89FC:
    // 0x800E89FC: beql        $a0, $zero, L_800E8A10
    if (ctx->r4 == 0) {
        // 0x800E8A00: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800E8A10;
    }
    goto skip_2;
    // 0x800E8A00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800E8A04: jal         0x800EE7F8
    // 0x800E8A08: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x800E8A08: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    after_5:
    // 0x800E8A0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E8A10:
    // 0x800E8A10: lh          $v0, 0x34($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X34);
    // 0x800E8A14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E8A18: jr          $ra
    // 0x800E8A1C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800E8A1C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800D0684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D0688: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D068C: bne         $a1, $at, L_800D06C0
    if (ctx->r5 != ctx->r1) {
        // 0x800D0690: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D06C0;
    }
    // 0x800D0690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0694: jal         0x800CFC5C
    // 0x800D0698: nop

    func_800CFC5C(rdram, ctx);
        goto after_0;
    // 0x800D0698: nop

    after_0:
    // 0x800D069C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D06A0: beq         $v0, $at, L_800D06C0
    if (ctx->r2 == ctx->r1) {
        // 0x800D06A4: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800D06C0;
    }
    // 0x800D06A4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800D06A8: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800D06AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800D06B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D06B4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D06B8: b           L_800D06C4
    // 0x800D06BC: lh          $v0, -0x4E70($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4E70);
        goto L_800D06C4;
    // 0x800D06BC: lh          $v0, -0x4E70($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4E70);
L_800D06C0:
    // 0x800D06C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D06C4:
    // 0x800D06C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D06C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D06CC: jr          $ra
    // 0x800D06D0: nop

    return;
    // 0x800D06D0: nop

;}
RECOMP_FUNC void func_800EB874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB874: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EB878: jr          $ra
    // 0x800EB87C: sw          $zero, 0x2EC0($at)
    MEM_W(0X2EC0, ctx->r1) = 0;
    return;
    // 0x800EB87C: sw          $zero, 0x2EC0($at)
    MEM_W(0X2EC0, ctx->r1) = 0;
;}
RECOMP_FUNC void _baeggfire_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B38: syscall     129
    recomp_syscall_handler(rdram, ctx, 0x80084B38);
    return;
    // 0x80084B3C: xori        $t0, $zero, 0x14
    ctx->r8 = 0 ^ 0X14;
;}
RECOMP_FUNC void func_80097858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009785C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097860: lw          $t7, 0x98($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X98);
    // 0x80097864: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80097868: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8009786C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80097870: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80097874: jal         0x800917A8
    // 0x80097878: sb          $t6, 0x24($t7)
    MEM_B(0X24, ctx->r15) = ctx->r14;
    bastatetimer_set(rdram, ctx);
        goto after_0;
    // 0x80097878: sb          $t6, 0x24($t7)
    MEM_B(0X24, ctx->r15) = ctx->r14;
    after_0:
    // 0x8009787C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097884: jr          $ra
    // 0x80097888: nop

    return;
    // 0x80097888: nop

;}
RECOMP_FUNC void func_80093AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093AB8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80093ABC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80093AC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80093AC4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80093AC8: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80093ACC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80093AD0: lbu         $t7, 0x17($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X17);
    // 0x80093AD4: beql        $t7, $zero, L_80093DE4
    if (ctx->r15 == 0) {
        // 0x80093AD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80093DE4;
    }
    goto skip_0;
    // 0x80093AD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80093ADC: jal         0x800A89F8
    // 0x80093AE0: nop

    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x80093AE0: nop

    after_0:
    // 0x80093AE4: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80093AE8: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80093AEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80093AF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80093AF4: lbu         $a0, 0xA2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XA2);
    // 0x80093AF8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80093AFC: beq         $a0, $a2, L_80093B1C
    if (ctx->r4 == ctx->r6) {
        // 0x80093B00: nop
    
            goto L_80093B1C;
    }
    // 0x80093B00: nop

    // 0x80093B04: beq         $a0, $at, L_80093B24
    if (ctx->r4 == ctx->r1) {
        // 0x80093B08: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80093B24;
    }
    // 0x80093B08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80093B0C: beql        $a0, $at, L_80093B28
    if (ctx->r4 == ctx->r1) {
        // 0x80093B10: lbu         $a0, 0x19($v1)
        ctx->r4 = MEM_BU(ctx->r3, 0X19);
            goto L_80093B28;
    }
    goto skip_1;
    // 0x80093B10: lbu         $a0, 0x19($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X19);
    skip_1:
    // 0x80093B14: b           L_80093B98
    // 0x80093B18: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
        goto L_80093B98;
    // 0x80093B18: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_80093B1C:
    // 0x80093B1C: b           L_80093B94
    // 0x80093B20: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
        goto L_80093B94;
    // 0x80093B20: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
L_80093B24:
    // 0x80093B24: lbu         $a0, 0x19($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X19);
L_80093B28:
    // 0x80093B28: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80093B2C: beq         $a0, $zero, L_80093B44
    if (ctx->r4 == 0) {
        // 0x80093B30: nop
    
            goto L_80093B44;
    }
    // 0x80093B30: nop

    // 0x80093B34: beq         $a0, $a2, L_80093B4C
    if (ctx->r4 == ctx->r6) {
        // 0x80093B38: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_80093B4C;
    }
    // 0x80093B38: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80093B3C: b           L_80093B98
    // 0x80093B40: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
        goto L_80093B98;
    // 0x80093B40: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_80093B44:
    // 0x80093B44: b           L_80093B94
    // 0x80093B48: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
        goto L_80093B94;
    // 0x80093B48: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_80093B4C:
    // 0x80093B4C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80093B50: jal         0x800A4C68
    // 0x80093B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_1;
    // 0x80093B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80093B58: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80093B5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80093B60: bne         $v0, $t1, L_80093B94
    if (ctx->r2 != ctx->r9) {
        // 0x80093B64: nop
    
            goto L_80093B94;
    }
    // 0x80093B64: nop

    // 0x80093B68: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80093B6C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80093B70: lbu         $t2, 0xA3($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XA3);
    // 0x80093B74: beql        $t2, $zero, L_80093B88
    if (ctx->r10 == 0) {
        // 0x80093B78: lbu         $t4, 0x18($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X18);
            goto L_80093B88;
    }
    goto skip_2;
    // 0x80093B78: lbu         $t4, 0x18($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X18);
    skip_2:
    // 0x80093B7C: b           L_80093B94
    // 0x80093B80: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
        goto L_80093B94;
    // 0x80093B80: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x80093B84: lbu         $t4, 0x18($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X18);
L_80093B88:
    // 0x80093B88: bne         $t4, $zero, L_80093B94
    if (ctx->r12 != 0) {
        // 0x80093B8C: nop
    
            goto L_80093B94;
    }
    // 0x80093B8C: nop

    // 0x80093B90: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
L_80093B94:
    // 0x80093B94: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_80093B98:
    // 0x80093B98: beql        $t5, $zero, L_80093DE4
    if (ctx->r13 == 0) {
        // 0x80093B9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80093DE4;
    }
    goto skip_3;
    // 0x80093B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80093BA0: beq         $t5, $a2, L_80093C64
    if (ctx->r13 == ctx->r6) {
        // 0x80093BA4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80093C64;
    }
    // 0x80093BA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80093BA8: bne         $t5, $at, L_80093C64
    if (ctx->r13 != ctx->r1) {
        // 0x80093BAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80093C64;
    }
    // 0x80093BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093BB0: jal         0x8009C128
    // 0x80093BB4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_8009C128(rdram, ctx);
        goto after_2;
    // 0x80093BB4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x80093BB8: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80093BBC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80093BC0: lwc1        $f4, 0x74($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80093BC4: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80093BC8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80093BCC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80093BD0: jal         0x800E3E8C
    // 0x80093BD4: nop

    func_800E3E8C(rdram, ctx);
        goto after_3;
    // 0x80093BD4: nop

    after_3:
    // 0x80093BD8: beql        $v0, $zero, L_80093DE4
    if (ctx->r2 == 0) {
        // 0x80093BDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80093DE4;
    }
    goto skip_4;
    // 0x80093BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80093BE0: jal         0x800BEC1C
    // 0x80093BE4: nop

    func_800BEC1C(rdram, ctx);
        goto after_4;
    // 0x80093BE4: nop

    after_4:
    // 0x80093BE8: beq         $v0, $zero, L_80093C64
    if (ctx->r2 == 0) {
        // 0x80093BEC: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_80093C64;
    }
    // 0x80093BEC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80093BF0: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80093BF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80093BF8: lbu         $t6, 0xA5($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XA5);
    // 0x80093BFC: bnel        $t6, $zero, L_80093C44
    if (ctx->r14 != 0) {
        // 0x80093C00: lbu         $v0, 0xA4($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0XA4);
            goto L_80093C44;
    }
    goto skip_5;
    // 0x80093C00: lbu         $v0, 0xA4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XA4);
    skip_5:
    // 0x80093C04: sb          $t7, 0xA5($v1)
    MEM_B(0XA5, ctx->r3) = ctx->r15;
    // 0x80093C08: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80093C0C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80093C10: jal         0x800EF04C
    // 0x80093C14: addiu       $a1, $a1, 0x64
    ctx->r5 = ADD32(ctx->r5, 0X64);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80093C14: addiu       $a1, $a1, 0x64
    ctx->r5 = ADD32(ctx->r5, 0X64);
    after_5:
    // 0x80093C18: jal         0x800BEC28
    // 0x80093C1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEC28(rdram, ctx);
        goto after_6;
    // 0x80093C1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80093C20: lw          $a2, 0x50($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X50);
    // 0x80093C24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80093C28: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80093C2C: jal         0x80087950
    // 0x80093C30: addiu       $a2, $a2, 0xA6
    ctx->r6 = ADD32(ctx->r6, 0XA6);
    _dbzone_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80093C30: addiu       $a2, $a2, 0xA6
    ctx->r6 = ADD32(ctx->r6, 0XA6);
    after_7:
    // 0x80093C34: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x80093C38: sb          $v0, 0xA4($t8)
    MEM_B(0XA4, ctx->r24) = ctx->r2;
    // 0x80093C3C: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80093C40: lbu         $v0, 0xA4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XA4);
L_80093C44:
    // 0x80093C44: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80093C48: addiu       $a1, $v1, 0xA6
    ctx->r5 = ADD32(ctx->r3, 0XA6);
    // 0x80093C4C: beql        $v0, $zero, L_80093C68
    if (ctx->r2 == 0) {
        // 0x80093C50: lw          $v1, 0x50($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X50);
            goto L_80093C68;
    }
    goto skip_6;
    // 0x80093C50: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    skip_6:
    // 0x80093C54: jal         0x80088790
    // 0x80093C58: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    _glzone_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x80093C58: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_8:
    // 0x80093C5C: beql        $v0, $zero, L_80093DE4
    if (ctx->r2 == 0) {
        // 0x80093C60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80093DE4;
    }
    goto skip_7;
    // 0x80093C60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
L_80093C64:
    // 0x80093C64: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
L_80093C68:
    // 0x80093C68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80093C6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80093C70: lbu         $a0, 0xA2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XA2);
    // 0x80093C74: beql        $a0, $a2, L_80093C9C
    if (ctx->r4 == ctx->r6) {
        // 0x80093C78: lbu         $t9, 0x18($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X18);
            goto L_80093C9C;
    }
    goto skip_8;
    // 0x80093C78: lbu         $t9, 0x18($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18);
    skip_8:
    // 0x80093C7C: beq         $a0, $at, L_80093D50
    if (ctx->r4 == ctx->r1) {
        // 0x80093C80: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_80093D50;
    }
    // 0x80093C80: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80093C84: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80093C88: beq         $a0, $at, L_80093D9C
    if (ctx->r4 == ctx->r1) {
        // 0x80093C8C: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_80093D9C;
    }
    // 0x80093C8C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80093C90: b           L_80093DE4
    // 0x80093C94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80093DE4;
    // 0x80093C94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80093C98: lbu         $t9, 0x18($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18);
L_80093C9C:
    // 0x80093C9C: bnel        $t9, $zero, L_80093CC0
    if (ctx->r25 != 0) {
        // 0x80093CA0: lbu         $t1, 0x10($v1)
        ctx->r9 = MEM_BU(ctx->r3, 0X10);
            goto L_80093CC0;
    }
    goto skip_9;
    // 0x80093CA0: lbu         $t1, 0x10($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X10);
    skip_9:
    // 0x80093CA4: jal         0x800A4C68
    // 0x80093CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_9;
    // 0x80093CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80093CAC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80093CB0: beql        $v0, $t0, L_80093DE4
    if (ctx->r2 == ctx->r8) {
        // 0x80093CB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80093DE4;
    }
    goto skip_10;
    // 0x80093CB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80093CB8: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80093CBC: lbu         $t1, 0x10($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X10);
L_80093CC0:
    // 0x80093CC0: bnel        $t1, $zero, L_80093CE4
    if (ctx->r9 != 0) {
        // 0x80093CC4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80093CE4;
    }
    goto skip_11;
    // 0x80093CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_11:
    // 0x80093CC8: jal         0x8008CA98
    // 0x80093CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008CA98(rdram, ctx);
        goto after_10;
    // 0x80093CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80093CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093CD4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80093CD8: jal         0x8009375C
    // 0x80093CDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009375C(rdram, ctx);
        goto after_11;
    // 0x80093CDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x80093CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80093CE4:
    // 0x80093CE4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80093CE8: jal         0x80093864
    // 0x80093CEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80093864(rdram, ctx);
        goto after_12;
    // 0x80093CEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80093CF0: lw          $v1, 0x50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X50);
    // 0x80093CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093CF8: lbu         $t2, 0xA3($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XA3);
    // 0x80093CFC: addiu       $a1, $v1, 0xAC
    ctx->r5 = ADD32(ctx->r3, 0XAC);
    // 0x80093D00: beql        $t2, $zero, L_80093DE4
    if (ctx->r10 == 0) {
        // 0x80093D04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80093DE4;
    }
    goto skip_12;
    // 0x80093D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x80093D08: jal         0x8009216C
    // 0x80093D0C: addiu       $a2, $v1, 0xB8
    ctx->r6 = ADD32(ctx->r3, 0XB8);
    func_8009216C(rdram, ctx);
        goto after_13;
    // 0x80093D0C: addiu       $a2, $v1, 0xB8
    ctx->r6 = ADD32(ctx->r3, 0XB8);
    after_13:
    // 0x80093D10: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
    // 0x80093D14: lbu         $t4, 0xA1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XA1);
    // 0x80093D18: bnel        $t4, $zero, L_80093D3C
    if (ctx->r12 != 0) {
        // 0x80093D1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80093D3C;
    }
    goto skip_13;
    // 0x80093D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_13:
    // 0x80093D20: jal         0x8008D058
    // 0x80093D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D058(rdram, ctx);
        goto after_14;
    // 0x80093D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80093D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093D2C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80093D30: jal         0x8009375C
    // 0x80093D34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009375C(rdram, ctx);
        goto after_15;
    // 0x80093D34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x80093D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80093D3C:
    // 0x80093D3C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80093D40: jal         0x80093864
    // 0x80093D44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80093864(rdram, ctx);
        goto after_16;
    // 0x80093D44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x80093D48: b           L_80093DE4
    // 0x80093D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80093DE4;
    // 0x80093D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80093D50:
    // 0x80093D50: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80093D54: bnel        $t5, $at, L_80093DE4
    if (ctx->r13 != ctx->r1) {
        // 0x80093D58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80093DE4;
    }
    goto skip_14;
    // 0x80093D58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x80093D5C: lbu         $t6, 0x10($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X10);
    // 0x80093D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093D64: bnel        $t6, $zero, L_80093D88
    if (ctx->r14 != 0) {
        // 0x80093D68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80093D88;
    }
    goto skip_15;
    // 0x80093D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_15:
    // 0x80093D6C: jal         0x80084290
    // 0x80093D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bsfirstp_entrypoint_1(rdram, ctx);
        goto after_17;
    // 0x80093D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80093D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093D78: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80093D7C: jal         0x8009375C
    // 0x80093D80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009375C(rdram, ctx);
        goto after_18;
    // 0x80093D80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x80093D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80093D88:
    // 0x80093D88: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80093D8C: jal         0x80093864
    // 0x80093D90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80093864(rdram, ctx);
        goto after_19;
    // 0x80093D90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x80093D94: b           L_80093DE4
    // 0x80093D98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80093DE4;
    // 0x80093D98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80093D9C:
    // 0x80093D9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80093DA0: bnel        $t7, $at, L_80093DE4
    if (ctx->r15 != ctx->r1) {
        // 0x80093DA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80093DE4;
    }
    goto skip_16;
    // 0x80093DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_16:
    // 0x80093DA8: lbu         $t8, 0x10($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X10);
    // 0x80093DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093DB0: bnel        $t8, $zero, L_80093DD4
    if (ctx->r24 != 0) {
        // 0x80093DB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80093DD4;
    }
    goto skip_17;
    // 0x80093DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_17:
    // 0x80093DB8: jal         0x80084290
    // 0x80093DBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bsfirstp_entrypoint_1(rdram, ctx);
        goto after_20;
    // 0x80093DBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80093DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093DC4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80093DC8: jal         0x8009375C
    // 0x80093DCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009375C(rdram, ctx);
        goto after_21;
    // 0x80093DCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x80093DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80093DD4:
    // 0x80093DD4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80093DD8: jal         0x80093864
    // 0x80093DDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80093864(rdram, ctx);
        goto after_22;
    // 0x80093DDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x80093DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80093DE4:
    // 0x80093DE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80093DE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80093DEC: jr          $ra
    // 0x80093DF0: nop

    return;
    // 0x80093DF0: nop

;}
RECOMP_FUNC void func_808062CC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808062CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808062D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808062D4: jal         0x80088328
    // 0x808062D8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    _gcstatusDll_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808062D8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    after_0:
    // 0x808062DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808062E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808062E4: jr          $ra
    // 0x808062E8: nop

    return;
    // 0x808062E8: nop

;}
RECOMP_FUNC void func_800D3B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3B6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3B70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D3B74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3B78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D3B7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800D3B80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800D3B84: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800D3B88: jal         0x800B2A58
    // 0x800D3B8C: lh          $a0, -0x4C04($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4C04);
    func_800B2A58(rdram, ctx);
        goto after_0;
    // 0x800D3B8C: lh          $a0, -0x4C04($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X4C04);
    after_0:
    // 0x800D3B90: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800D3B94: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800D3B98: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3B9C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800D3BA0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D3BA4: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x800D3BA8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800D3BAC: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x800D3BB0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800D3BB4: sw          $t0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r8;
    // 0x800D3BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D3BBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D3BC0: jr          $ra
    // 0x800D3BC4: nop

    return;
    // 0x800D3BC4: nop

;}
RECOMP_FUNC void glintrosyncDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808001C8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x808001CC: addiu       $s1, $s1, 0x75D0
    ctx->r17 = ADD32(ctx->r17, 0X75D0);
    // 0x808001D0: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x808001D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808001DC: bltz        $v0, L_8080030C
    if (SIGNED(ctx->r2) < 0) {
        // 0x808001E0: sll         $t6, $v0, 3
        ctx->r14 = S32(ctx->r2 << 3);
            goto L_8080030C;
    }
    // 0x808001E0: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x808001E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2738, 0X4A4) << 16);
    // 0x808001E8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808001EC: lwc1        $f4, 0x4A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2738, 0X4A4));
    // 0x808001F0: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x808001F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2738, 0X484) << 16);
    // 0x808001F8: lwc1        $f8, 0x484($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2738, 0X484));
    // 0x808001FC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800200: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800204: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800208: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8080020C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800210: nop

    // 0x80800214: bc1fl       L_80800228
    if (!c1cs) {
        // 0x80800218: cfc1        $t7, $FpcCsr
        ctx->r15 = get_cop1_cs();
            goto L_80800228;
    }
    goto skip_0;
    // 0x80800218: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    skip_0:
    // 0x8080021C: b           L_808002A8
    // 0x80800220: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_808002A8;
    // 0x80800220: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800224: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
L_80800228:
    // 0x80800228: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x8080022C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800230: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80800234: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x80800238: nop

    // 0x8080023C: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x80800240: beql        $s0, $zero, L_80800290
    if (ctx->r16 == 0) {
        // 0x80800244: mfc1        $s0, $f16
        ctx->r16 = (int32_t)ctx->f16.u32l;
            goto L_80800290;
    }
    goto skip_1;
    // 0x80800244: mfc1        $s0, $f16
    ctx->r16 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x80800248: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080024C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800250: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80800254: ctc1        $s0, $FpcCsr
    set_cop1_cs(ctx->r16);
    // 0x80800258: nop

    // 0x8080025C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80800260: cfc1        $s0, $FpcCsr
    ctx->r16 = get_cop1_cs();
    // 0x80800264: nop

    // 0x80800268: andi        $s0, $s0, 0x78
    ctx->r16 = ctx->r16 & 0X78;
    // 0x8080026C: bne         $s0, $zero, L_80800284
    if (ctx->r16 != 0) {
        // 0x80800270: nop
    
            goto L_80800284;
    }
    // 0x80800270: nop

    // 0x80800274: mfc1        $s0, $f16
    ctx->r16 = (int32_t)ctx->f16.u32l;
    // 0x80800278: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080027C: b           L_8080029C
    // 0x80800280: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
        goto L_8080029C;
    // 0x80800280: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
L_80800284:
    // 0x80800284: b           L_8080029C
    // 0x80800288: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
        goto L_8080029C;
    // 0x80800288: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8080028C: mfc1        $s0, $f16
    ctx->r16 = (int32_t)ctx->f16.u32l;
L_80800290:
    // 0x80800290: nop

    // 0x80800294: bltz        $s0, L_80800284
    if (SIGNED(ctx->r16) < 0) {
        // 0x80800298: nop
    
            goto L_80800284;
    }
    // 0x80800298: nop

L_8080029C:
    // 0x8080029C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808002A0: nop

    // 0x808002A4: nop

L_808002A8:
    if (tooie_intro_sync_skip(rdram, ctx)) { ctx->r16 = 0; }
    // 0x808002A8: jal         0x808000BC
    // 0x808002AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_808000BC_glintrosyncDll(rdram, ctx);
        goto after_0;
    // 0x808002AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x808002B0: sltu        $at, $v0, $s0
    ctx->r1 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x808002B4: beq         $at, $zero, L_808002D0
    if (ctx->r1 == 0) {
        // 0x808002B8: nop
    
            goto L_808002D0;
    }
    // 0x808002B8: nop

L_808002BC:
    // 0x808002BC: jal         0x808000BC
    // 0x808002C0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_808000BC_glintrosyncDll(rdram, ctx);
        goto after_1;
    // 0x808002C0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_1:
    tooie_preempt_point(rdram, ctx);
    // 0x808002C4: sltu        $at, $v0, $s0
    ctx->r1 = ctx->r2 < ctx->r16 ? 1 : 0;
    // 0x808002C8: bne         $at, $zero, L_808002BC
    if (ctx->r1 != 0) {
        // 0x808002CC: nop
    
            goto L_808002BC;
    }
    // 0x808002CC: nop

L_808002D0:
    // 0x808002D0: jal         0x808000BC
    // 0x808002D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_808000BC_glintrosyncDll(rdram, ctx);
        goto after_2;
    // 0x808002D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x808002D8: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x808002DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808002E0: bgez        $v0, L_808002F4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x808002E4: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_808002F4;
    }
    // 0x808002E4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808002E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002EC: nop

    // 0x808002F0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_808002F4:
    // 0x808002F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2738, 0X488) << 16);
    // 0x808002F8: lwc1        $f8, 0x488($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2738, 0X488));
    // 0x808002FC: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80800300: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800304: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80800308: swc1        $f18, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f18.u32l;
L_8080030C:
    // 0x8080030C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800310: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800314: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800318: jr          $ra
    // 0x8080031C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080031C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8009E058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E05C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E060: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8009E064: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8009E068: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x8009E06C: jal         0x8009DF18
    // 0x8009E070: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_0;
    // 0x8009E070: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_0:
    // 0x8009E074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E07C: jr          $ra
    // 0x8009E080: nop

    return;
    // 0x8009E080: nop

;}
RECOMP_FUNC void func_80802534_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802534: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80802538: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080253C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80802540: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80802544: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80802548: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8080254C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80802550: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80802554: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80802558: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080255C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802560: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x80802564: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80802568: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8080256C: blez        $t6, L_80802640
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80802570: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80802640;
    }
    // 0x80802570: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80802574: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x80802578: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8080257C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80802580:
    // 0x80802580: jal         0x80800070
    // 0x80802584: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80800070_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80802584: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x80802588: lh          $t7, 0x6($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X6);
    // 0x8080258C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80802590: beql        $v0, $t7, L_80802630
    if (ctx->r2 == ctx->r15) {
        // 0x80802594: lh          $t5, 0x2($s2)
        ctx->r13 = MEM_H(ctx->r18, 0X2);
            goto L_80802630;
    }
    goto skip_0;
    // 0x80802594: lh          $t5, 0x2($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X2);
    skip_0:
    // 0x80802598: jal         0x80800000
    // 0x8080259C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_1;
    // 0x8080259C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x808025A0: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x808025A4: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x808025A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808025AC: jal         0x80087AF8
    // 0x808025B0: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    _gczoombox_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808025B0: lw          $a0, 0x3C($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X3C);
    after_2:
    // 0x808025B4: beq         $v0, $zero, L_808025D4
    if (ctx->r2 == 0) {
        // 0x808025B8: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_808025D4;
    }
    // 0x808025B8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808025BC: beq         $v0, $s7, L_80802628
    if (ctx->r2 == ctx->r23) {
        // 0x808025C0: addu        $s1, $s2, $s0
        ctx->r17 = ADD32(ctx->r18, ctx->r16);
            goto L_80802628;
    }
    // 0x808025C0: addu        $s1, $s2, $s0
    ctx->r17 = ADD32(ctx->r18, ctx->r16);
    // 0x808025C4: beq         $v0, $fp, L_80802604
    if (ctx->r2 == ctx->r30) {
        // 0x808025C8: addu        $s1, $s2, $s0
        ctx->r17 = ADD32(ctx->r18, ctx->r16);
            goto L_80802604;
    }
    // 0x808025C8: addu        $s1, $s2, $s0
    ctx->r17 = ADD32(ctx->r18, ctx->r16);
    // 0x808025CC: b           L_80802628
    // 0x808025D0: addu        $s1, $s2, $s0
    ctx->r17 = ADD32(ctx->r18, ctx->r16);
        goto L_80802628;
    // 0x808025D0: addu        $s1, $s2, $s0
    ctx->r17 = ADD32(ctx->r18, ctx->r16);
L_808025D4:
    // 0x808025D4: addu        $s1, $s2, $s0
    ctx->r17 = ADD32(ctx->r18, ctx->r16);
    // 0x808025D8: lb          $t0, 0x94($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X94);
    // 0x808025DC: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x808025E0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x808025E4: beq         $v0, $t0, L_80802628
    if (ctx->r2 == ctx->r8) {
        // 0x808025E8: addu        $s3, $s2, $t1
        ctx->r19 = ADD32(ctx->r18, ctx->r9);
            goto L_80802628;
    }
    // 0x808025E8: addu        $s3, $s2, $t1
    ctx->r19 = ADD32(ctx->r18, ctx->r9);
    // 0x808025EC: jal         0x80087B28
    // 0x808025F0: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    _gczoombox_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x808025F0: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    after_3:
    // 0x808025F4: jal         0x80087B38
    // 0x808025F8: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    _gczoombox_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808025F8: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    after_4:
    // 0x808025FC: b           L_8080262C
    // 0x80802600: sb          $s5, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r21;
        goto L_8080262C;
    // 0x80802600: sb          $s5, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r21;
L_80802604:
    // 0x80802604: lb          $t2, 0x94($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X94);
    // 0x80802608: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8080260C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80802610: beq         $v0, $t2, L_80802628
    if (ctx->r2 == ctx->r10) {
        // 0x80802614: addu        $t4, $s2, $t3
        ctx->r12 = ADD32(ctx->r18, ctx->r11);
            goto L_80802628;
    }
    // 0x80802614: addu        $t4, $s2, $t3
    ctx->r12 = ADD32(ctx->r18, ctx->r11);
    // 0x80802618: jal         0x80087B38
    // 0x8080261C: lw          $a0, 0x3C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X3C);
    _gczoombox_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x8080261C: lw          $a0, 0x3C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X3C);
    after_5:
    // 0x80802620: b           L_8080262C
    // 0x80802624: sb          $s5, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r21;
        goto L_8080262C;
    // 0x80802624: sb          $s5, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r21;
L_80802628:
    // 0x80802628: sb          $s5, 0x94($s1)
    MEM_B(0X94, ctx->r17) = ctx->r21;
L_8080262C:
    // 0x8080262C: lh          $t5, 0x2($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X2);
L_80802630:
    // 0x80802630: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80802634: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80802638: bnel        $at, $zero, L_80802580
    if (ctx->r1 != 0) {
        // 0x8080263C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80802580;
    }
    goto skip_1;
    // 0x8080263C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_80802640:
    // 0x80802640: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80802644: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x80802648: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8080264C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802650: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80802654: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80802658: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080265C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80802660: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80802664: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80802668: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8080266C: jr          $ra
    // 0x80802670: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80802670: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void sccustom_big_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003CC: jal         0x80800044
    // 0x808003D0: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    func_80800044_sccustom_big(rdram, ctx);
        goto after_0;
    // 0x808003D0: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    after_0:
    // 0x808003D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808003D8: jal         0x80800314
    // 0x808003DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800314_sccustom_big(rdram, ctx);
        goto after_1;
    // 0x808003DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808003E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003E8: jr          $ra
    // 0x808003EC: nop

    return;
    // 0x808003EC: nop

;}
RECOMP_FUNC void func_800FFC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFC14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FFC18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFC1C: jal         0x800FFC3C
    // 0x800FFC20: nop

    func_800FFC3C(rdram, ctx);
        goto after_0;
    // 0x800FFC20: nop

    after_0:
    // 0x800FFC24: jal         0x8010DEFC
    // 0x800FFC28: nop

    func_8010DEFC(rdram, ctx);
        goto after_1;
    // 0x800FFC28: nop

    after_1:
    // 0x800FFC2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFC30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FFC34: jr          $ra
    // 0x800FFC38: nop

    return;
    // 0x800FFC38: nop

;}
RECOMP_FUNC void baflag_isFalse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095748: lw          $t6, 0x80($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X80);
    // 0x8009574C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80095750: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x80095754: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80095758: jr          $ra
    // 0x8009575C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x8009575C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}
RECOMP_FUNC void func_808005A0_chbabydino(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808005AC: jal         0x80105834
    // 0x808005B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80105834(rdram, ctx);
        goto after_0;
    // 0x808005B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808005B4: jal         0x80105A5C
    // 0x808005B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80105A5C(rdram, ctx);
        goto after_1;
    // 0x808005B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808005BC: beq         $v0, $zero, L_808005DC
    if (ctx->r2 == 0) {
        // 0x808005C0: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_808005DC;
    }
    // 0x808005C0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808005C4: beq         $t6, $zero, L_808005D4
    if (ctx->r14 == 0) {
        // 0x808005C8: nop
    
            goto L_808005D4;
    }
    // 0x808005C8: nop

    // 0x808005CC: jal         0x800FFAB0
    // 0x808005D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x808005D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_808005D4:
    // 0x808005D4: b           L_808005E0
    // 0x808005D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005E0;
    // 0x808005D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005DC:
    // 0x808005DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005E0:
    // 0x808005E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808005E8: jr          $ra
    // 0x808005EC: nop

    return;
    // 0x808005EC: nop

;}
RECOMP_FUNC void bsmummove_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800304: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800308: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(320, 0X5B0) << 16);
    // 0x8080030C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800310: jr          $ra
    // 0x80800314: lw          $v0, 0x5B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(320, 0X5B0));
    return;
    // 0x80800314: lw          $v0, 0x5B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(320, 0X5B0));
;}
RECOMP_FUNC void gcmapsects_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801AD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801AD8: jal         0x800BF704
    // 0x80801ADC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800BF704(rdram, ctx);
        goto after_0;
    // 0x80801ADC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801AE0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80801AE4: sb          $t6, 0x81($v0)
    MEM_B(0X81, ctx->r2) = ctx->r14;
    // 0x80801AE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801AF0: jr          $ra
    // 0x80801AF4: nop

    return;
    // 0x80801AF4: nop

;}
RECOMP_FUNC void glsplineDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800DAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DB0: jal         0x80800C70
    // 0x80800DB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800C70_glsplineDll(rdram, ctx);
        goto after_0;
    // 0x80800DB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800DB8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800DBC: beq         $v0, $zero, L_80800FA8
    if (ctx->r2 == 0) {
        // 0x80800DC0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800FA8;
    }
    // 0x80800DC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DC4: sw          $v0, 0x198($a3)
    MEM_W(0X198, ctx->r7) = ctx->r2;
    // 0x80800DC8: jal         0x800D674C
    // 0x80800DCC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80800DCC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800DD0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800DD4: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80800DD8: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x80800DDC: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
    // 0x80800DE0: ori         $t4, $t4, 0x5
    ctx->r12 = ctx->r12 | 0X5;
    // 0x80800DE4: ori         $t5, $t5, 0x6
    ctx->r13 = ctx->r13 | 0X6;
    // 0x80800DE8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800DEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800DF0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800DF4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80800DF8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80800DFC: sw          $zero, 0x1A0($a3)
    MEM_W(0X1A0, ctx->r7) = 0;
L_80800E00:
    // 0x80800E00: bne         $v1, $t0, L_80800E20
    if (ctx->r3 != ctx->r8) {
        // 0x80800E04: nop
    
            goto L_80800E20;
    }
    // 0x80800E04: nop

    // 0x80800E08: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80800E0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800E10: bne         $t1, $t6, L_80800E20
    if (ctx->r9 != ctx->r14) {
        // 0x80800E14: nop
    
            goto L_80800E20;
    }
    // 0x80800E14: nop

    // 0x80800E18: b           L_80800E20
    // 0x80800E1C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
        goto L_80800E20;
    // 0x80800E1C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80800E20:
    // 0x80800E20: bne         $v1, $t3, L_80800E38
    if (ctx->r3 != ctx->r11) {
        // 0x80800E24: lw          $a0, 0x0($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X0);
            goto L_80800E38;
    }
    // 0x80800E24: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80800E28: bne         $t0, $a0, L_80800E38
    if (ctx->r8 != ctx->r4) {
        // 0x80800E2C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800E38;
    }
    // 0x80800E2C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800E30: b           L_80800E38
    // 0x80800E34: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80800E38;
    // 0x80800E34: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80800E38:
    // 0x80800E38: bne         $v1, $zero, L_80800E50
    if (ctx->r3 != 0) {
        // 0x80800E3C: nop
    
            goto L_80800E50;
    }
    // 0x80800E3C: nop

    // 0x80800E40: bne         $a0, $zero, L_80800E50
    if (ctx->r4 != 0) {
        // 0x80800E44: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800E50;
    }
    // 0x80800E44: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800E48: b           L_80800E50
    // 0x80800E4C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
        goto L_80800E50;
    // 0x80800E4C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
L_80800E50:
    // 0x80800E50: beql        $t4, $a0, L_80800E64
    if (ctx->r12 == ctx->r4) {
        // 0x80800E54: lw          $t7, 0x1A0($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X1A0);
            goto L_80800E64;
    }
    goto skip_0;
    // 0x80800E54: lw          $t7, 0x1A0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1A0);
    skip_0:
    // 0x80800E58: bne         $t5, $a0, L_80800E6C
    if (ctx->r13 != ctx->r4) {
        // 0x80800E5C: nop
    
            goto L_80800E6C;
    }
    // 0x80800E5C: nop

    // 0x80800E60: lw          $t7, 0x1A0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1A0);
L_80800E64:
    // 0x80800E64: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80800E68: sw          $t8, 0x1A0($a3)
    MEM_W(0X1A0, ctx->r7) = ctx->r24;
L_80800E6C:
    // 0x80800E6C: bne         $v1, $t1, L_80800E00
    if (ctx->r3 != ctx->r9) {
        // 0x80800E70: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80800E00;
    }
    // 0x80800E70: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800E74: lw          $a0, 0x1A0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1A0);
    // 0x80800E78: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80800E7C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80800E80: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80800E84: jal         0x8001ACCC
    // 0x80800E88: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x80800E88: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_2:
    // 0x80800E8C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800E90: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x80800E94: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80800E98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E9C: ori         $t5, $t5, 0x6
    ctx->r13 = ctx->r13 | 0X6;
    // 0x80800EA0: ori         $t4, $t4, 0x5
    ctx->r12 = ctx->r12 | 0X5;
    // 0x80800EA4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80800EA8: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80800EAC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800EB0: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80800EB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800EB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800EBC: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80800EC0: sw          $v0, 0x19C($a3)
    MEM_W(0X19C, ctx->r7) = ctx->r2;
L_80800EC4:
    // 0x80800EC4: bne         $v1, $t0, L_80800F00
    if (ctx->r3 != ctx->r8) {
        // 0x80800EC8: sll         $t9, $a2, 2
        ctx->r25 = S32(ctx->r6 << 2);
            goto L_80800F00;
    }
    // 0x80800EC8: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80800ECC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80800ED0: bne         $t1, $v0, L_80800EE0
    if (ctx->r9 != ctx->r2) {
        // 0x80800ED4: nop
    
            goto L_80800EE0;
    }
    // 0x80800ED4: nop

    // 0x80800ED8: b           L_80800F00
    // 0x80800EDC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
        goto L_80800F00;
    // 0x80800EDC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_80800EE0:
    // 0x80800EE0: beq         $t4, $v0, L_80800EF0
    if (ctx->r12 == ctx->r2) {
        // 0x80800EE4: nop
    
            goto L_80800EF0;
    }
    // 0x80800EE4: nop

    // 0x80800EE8: bnel        $t5, $v0, L_80800EFC
    if (ctx->r13 != ctx->r2) {
        // 0x80800EEC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800EFC;
    }
    goto skip_1;
    // 0x80800EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_80800EF0:
    // 0x80800EF0: b           L_80800EFC
    // 0x80800EF4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_80800EFC;
    // 0x80800EF4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80800EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800EFC:
    // 0x80800EFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800F00:
    // 0x80800F00: bne         $v1, $t3, L_80800F20
    if (ctx->r3 != ctx->r11) {
        // 0x80800F04: nop
    
            goto L_80800F20;
    }
    // 0x80800F04: nop

    // 0x80800F08: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800F0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800F10: bne         $t0, $t6, L_80800F20
    if (ctx->r8 != ctx->r14) {
        // 0x80800F14: nop
    
            goto L_80800F20;
    }
    // 0x80800F14: nop

    // 0x80800F18: b           L_80800F20
    // 0x80800F1C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
        goto L_80800F20;
    // 0x80800F1C: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80800F20:
    // 0x80800F20: bne         $v1, $zero, L_80800F40
    if (ctx->r3 != 0) {
        // 0x80800F24: nop
    
            goto L_80800F40;
    }
    // 0x80800F24: nop

    // 0x80800F28: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80800F2C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800F30: bne         $t7, $zero, L_80800F40
    if (ctx->r15 != 0) {
        // 0x80800F34: nop
    
            goto L_80800F40;
    }
    // 0x80800F34: nop

    // 0x80800F38: b           L_80800F40
    // 0x80800F3C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
        goto L_80800F40;
    // 0x80800F3C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
L_80800F40:
    // 0x80800F40: bne         $v1, $t2, L_80800F5C
    if (ctx->r3 != ctx->r10) {
        // 0x80800F44: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80800F5C;
    }
    // 0x80800F44: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800F48: lw          $t8, 0x19C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X19C);
    // 0x80800F4C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800F50: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80800F54: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80800F58: sw          $a1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r5;
L_80800F5C:
    // 0x80800F5C: bne         $v1, $t1, L_80800EC4
    if (ctx->r3 != ctx->r9) {
        // 0x80800F60: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80800EC4;
    }
    // 0x80800F60: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800F64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80800F68: beq         $t2, $v0, L_80800FA8
    if (ctx->r10 == ctx->r2) {
        // 0x80800F6C: sra         $t8, $v0, 16
        ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80800FA8;
    }
    // 0x80800F6C: sra         $t8, $v0, 16
    ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
L_80800F70:
    // 0x80800F70: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80800F74: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80800F78: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
    // 0x80800F7C: sb          $t7, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r15;
    // 0x80800F80: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80800F84: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800F88: sra         $t9, $v0, 16
    ctx->r25 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80800F8C: andi        $t7, $t9, 0x7F
    ctx->r15 = ctx->r25 & 0X7F;
    // 0x80800F90: addu        $t6, $a3, $t7
    ctx->r14 = ADD32(ctx->r7, ctx->r15);
    // 0x80800F94: or          $t8, $v0, $zero
    ctx->r24 = ctx->r2 | 0;
    // 0x80800F98: sb          $t8, 0x80($t6)
    MEM_B(0X80, ctx->r14) = ctx->r24;
    // 0x80800F9C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80800FA0: bnel        $t2, $v0, L_80800F70
    if (ctx->r10 != ctx->r2) {
        // 0x80800FA4: sra         $t8, $v0, 16
        ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80800F70;
    }
    goto skip_2;
    // 0x80800FA4: sra         $t8, $v0, 16
    ctx->r24 = S32(SIGNED(ctx->r2) >> 16);
    skip_2:
L_80800FA8:
    // 0x80800FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800FB0: jr          $ra
    // 0x80800FB4: nop

    return;
    // 0x80800FB4: nop

    // 0x80800FB8: nop

    // 0x80800FBC: nop

;}
RECOMP_FUNC void _glglobalsettings_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886C0: syscall     699
    recomp_syscall_handler(rdram, ctx, 0x800886C0);
    return;
    // 0x800886C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8010038C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010038C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100394: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80100398: lh          $t7, 0x7E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X7E);
    // 0x8010039C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801003A0: bltzl       $t7, L_80100404
    if (SIGNED(ctx->r15) < 0) {
        // 0x801003A4: lw          $v0, 0x7C($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X7C);
            goto L_80100404;
    }
    goto skip_0;
    // 0x801003A4: lw          $v0, 0x7C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X7C);
    skip_0:
    // 0x801003A8: lbu         $t9, 0x7E($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X7E);
    // 0x801003AC: addiu       $a1, $zero, 0x95
    ctx->r5 = ADD32(0, 0X95);
    // 0x801003B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801003B4: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x801003B8: sb          $t0, 0x7E($a0)
    MEM_B(0X7E, ctx->r4) = ctx->r8;
    // 0x801003BC: jal         0x8010108C
    // 0x801003C0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8010108C(rdram, ctx);
        goto after_0;
    // 0x801003C0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x801003C4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801003C8: lw          $t1, 0x64($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X64);
    // 0x801003CC: sll         $t3, $t1, 14
    ctx->r11 = S32(ctx->r9 << 14);
    // 0x801003D0: bgezl       $t3, L_801003E4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801003D4: lw          $t4, 0x78($a3)
        ctx->r12 = MEM_W(ctx->r7, 0X78);
            goto L_801003E4;
    }
    goto skip_1;
    // 0x801003D4: lw          $t4, 0x78($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X78);
    skip_1:
    // 0x801003D8: b           L_80100464
    // 0x801003DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100464;
    // 0x801003DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801003E0: lw          $t4, 0x78($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X78);
L_801003E4:
    // 0x801003E4: sll         $t6, $t4, 26
    ctx->r14 = S32(ctx->r12 << 26);
    // 0x801003E8: bgezl       $t6, L_80100404
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801003EC: lw          $v0, 0x7C($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X7C);
            goto L_80100404;
    }
    goto skip_2;
    // 0x801003EC: lw          $v0, 0x7C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X7C);
    skip_2:
    // 0x801003F0: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    // 0x801003F4: jal         0x80081D34
    // 0x801003F8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80081D34(rdram, ctx);
        goto after_1;
    // 0x801003F8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x801003FC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80100400: lw          $v0, 0x7C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X7C);
L_80100404:
    // 0x80100404: sll         $t8, $v0, 17
    ctx->r24 = S32(ctx->r2 << 17);
    // 0x80100408: bltzl       $t8, L_8010041C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8010040C: lhu         $v1, 0x7C($a3)
        ctx->r3 = MEM_HU(ctx->r7, 0X7C);
            goto L_8010041C;
    }
    goto skip_3;
    // 0x8010040C: lhu         $v1, 0x7C($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X7C);
    skip_3:
    // 0x80100410: b           L_80100464
    // 0x80100414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100464;
    // 0x80100414: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80100418: lhu         $v1, 0x7C($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X7C);
L_8010041C:
    // 0x8010041C: sll         $t0, $v0, 18
    ctx->r8 = S32(ctx->r2 << 18);
    // 0x80100420: bne         $v1, $zero, L_80100430
    if (ctx->r3 != 0) {
        // 0x80100424: nop
    
            goto L_80100430;
    }
    // 0x80100424: nop

    // 0x80100428: b           L_80100464
    // 0x8010042C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80100464;
    // 0x8010042C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80100430:
    // 0x80100430: bgez        $t0, L_80100448
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80100434: sll         $t2, $v0, 19
        ctx->r10 = S32(ctx->r2 << 19);
            goto L_80100448;
    }
    // 0x80100434: sll         $t2, $v0, 19
    ctx->r10 = S32(ctx->r2 << 19);
    // 0x80100438: bgezl       $t2, L_8010044C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8010043C: mtc1        $v1, $f4
        ctx->f4.u32l = ctx->r3;
            goto L_8010044C;
    }
    goto skip_4;
    // 0x8010043C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    skip_4:
    // 0x80100440: b           L_80100464
    // 0x80100444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80100464;
    // 0x80100444: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80100448:
    // 0x80100448: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
L_8010044C:
    // 0x8010044C: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    // 0x80100450: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80100454: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80100458: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8010045C: jal         0x800EFFB4
    // 0x80100460: nop

    func_800EFFB4(rdram, ctx);
        goto after_2;
    // 0x80100460: nop

    after_2:
L_80100464:
    // 0x80100464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010046C: jr          $ra
    // 0x80100470: nop

    return;
    // 0x80100470: nop

    // 0x80100474: nop

    // 0x80100478: nop

    // 0x8010047C: nop

;}
RECOMP_FUNC void bainput_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009819C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800981A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800981A4: lw          $t6, 0xA4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA4);
    // 0x800981A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800981AC: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800981B0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800981B4: nop

    // 0x800981B8: bc1tl       L_800981F0
    if (c1cs) {
        // 0x800981BC: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_800981F0;
    }
    goto skip_0;
    // 0x800981BC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    skip_0:
    // 0x800981C0: jal         0x800D8FF8
    // 0x800981C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800981C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800981C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800981CC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800981D0: lw          $t7, 0xA4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XA4);
    // 0x800981D4: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800981D8: jal         0x800F0E00
    // 0x800981DC: sub.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f0.fl;
    func_800F0E00(rdram, ctx);
        goto after_1;
    // 0x800981DC: sub.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f0.fl;
    after_1:
    // 0x800981E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800981E4: lw          $t8, 0xA4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XA4);
    // 0x800981E8: swc1        $f0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f0.u32l;
    // 0x800981EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
L_800981F0:
    // 0x800981F0: jal         0x80098140
    // 0x800981F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_2;
    // 0x800981F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800981F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800981FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80098200: jr          $ra
    // 0x80098204: nop

    return;
    // 0x80098204: nop

;}
RECOMP_FUNC void func_8001713C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001713C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80017140: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80017144: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80017148: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8001714C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80017150: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017154: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80017158: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001715C: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80017160: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80017164: addiu       $t8, $t8, -0x6060
    ctx->r24 = ADD32(ctx->r24, -0X6060);
    // 0x80017168: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001716C: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80017170: lh          $v0, 0x26C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X26C);
    // 0x80017174: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80017178: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001717C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80017180: beq         $a1, $v0, L_80017194
    if (ctx->r5 == ctx->r2) {
        // 0x80017184: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80017194;
    }
    // 0x80017184: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80017188: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001718C: bne         $v0, $at, L_800171A4
    if (ctx->r2 != ctx->r1) {
        // 0x80017190: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800171A4;
    }
    // 0x80017190: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80017194:
    // 0x80017194: jal         0x80016ED0
    // 0x80017198: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80016ED0(rdram, ctx);
        goto after_0;
    // 0x80017198: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8001719C: b           L_80017200
    // 0x800171A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80017200;
    // 0x800171A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800171A4:
    // 0x800171A4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800171A8: sb          $a0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r4;
    // 0x800171AC: jal         0x80016ED0
    // 0x800171B0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_80016ED0(rdram, ctx);
        goto after_1;
    // 0x800171B0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_1:
    // 0x800171B4: jal         0x800305B0
    // 0x800171B8: nop

    osGetTime_recomp(rdram, ctx);
        goto after_2;
    // 0x800171B8: nop

    after_2:
    // 0x800171BC: lw          $t9, 0x20C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20C);
    // 0x800171C0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800171C4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800171C8: beql        $t9, $zero, L_800171E8
    if (ctx->r25 == 0) {
        // 0x800171CC: sw          $zero, 0x1F8($s0)
        MEM_W(0X1F8, ctx->r16) = 0;
            goto L_800171E8;
    }
    goto skip_0;
    // 0x800171CC: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
    skip_0:
L_800171D0:
    // 0x800171D0: jal         0x800305B0
    // 0x800171D4: nop

    osGetTime_recomp(rdram, ctx);
        goto after_3;
    // 0x800171D4: nop

    after_3:
    // 0x800171D8: lw          $t0, 0x20C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X20C);
    // 0x800171DC: bne         $t0, $zero, L_800171D0
    if (ctx->r8 != 0) {
        // 0x800171E0: nop
    
            goto L_800171D0;
    }
    // 0x800171E0: nop

    // 0x800171E4: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
L_800171E8:
    // 0x800171E8: jal         0x80016DF8
    // 0x800171EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80016DF8(rdram, ctx);
        goto after_4;
    // 0x800171EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x800171F0: lbu         $a0, 0x33($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X33);
    // 0x800171F4: jal         0x80016ED0
    // 0x800171F8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80016ED0(rdram, ctx);
        goto after_5;
    // 0x800171F8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_5:
    // 0x800171FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80017200:
    // 0x80017200: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80017204: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80017208: jr          $ra
    // 0x8001720C: nop

    return;
    // 0x8001720C: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A90: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A90);
    return;
    // 0x80082A94: addi        $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
;}
RECOMP_FUNC void gcdialogexec_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802304: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80802308: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080230C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802310: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802314: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x80802318: lhu         $t7, 0x15A($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X15A);
    // 0x8080231C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802320: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80802324: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x80802328: beq         $t8, $zero, L_8080234C
    if (ctx->r24 == 0) {
        // 0x8080232C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080234C;
    }
    // 0x8080232C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802330: jal         0x80015ECC
    // 0x80802334: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015ECC(rdram, ctx);
        goto after_0;
    // 0x80802334: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80802338: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080233C: jal         0x80015F5C
    // 0x80802340: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_80015F5C(rdram, ctx);
        goto after_1;
    // 0x80802340: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_1:
    // 0x80802344: b           L_80802364
    // 0x80802348: lbu         $t9, 0x15C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15C);
        goto L_80802364;
    // 0x80802348: lbu         $t9, 0x15C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15C);
L_8080234C:
    // 0x8080234C: jal         0x80015E80
    // 0x80802350: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_80015E80(rdram, ctx);
        goto after_2;
    // 0x80802350: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_2:
    // 0x80802354: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802358: jal         0x80015F28
    // 0x8080235C: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    func_80015F28(rdram, ctx);
        goto after_3;
    // 0x8080235C: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x80802360: lbu         $t9, 0x15C($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15C);
L_80802364:
    // 0x80802364: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x80802368: sltiu       $at, $t4, 0x7
    ctx->r1 = ctx->r12 < 0X7 ? 1 : 0;
    // 0x8080236C: beq         $at, $zero, L_80802DF0
    if (ctx->r1 == 0) {
        // 0x80802370: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80802DF0;
    }
    // 0x80802370: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80802374: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2594, 0X2E64) << 16);
    // 0x80802378: addu        $at, $at, $t4
    gpr jr_addend_80802380 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8080237C: lw          $t4, 0x2E64($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2594, 0X2E64));
    // 0x80802380: jr          $t4
    // 0x80802384: nop

    switch (jr_addend_80802380 >> 2) {
        case 0: goto L_80802388; break;
        case 1: goto L_808023FC; break;
        case 2: goto L_80802D14; break;
        case 3: goto L_80802D8C; break;
        case 4: goto L_80802DF0; break;
        case 5: goto L_80802DF0; break;
        case 6: goto L_80802DE4; break;
        default: switch_error(__func__, 0x80802380, 0x80802E64);
    }
    // 0x80802384: nop

L_80802388:
    // 0x80802388: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8080238C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80802390: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80802394: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_80802398:
    // 0x80802398: lw          $t5, 0x120($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X120);
    // 0x8080239C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808023A0: bne         $t5, $zero, L_808023AC
    if (ctx->r13 != 0) {
        // 0x808023A4: nop
    
            goto L_808023AC;
    }
    // 0x808023A4: nop

    // 0x808023A8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_808023AC:
    // 0x808023AC: bne         $v0, $a0, L_80802398
    if (ctx->r2 != ctx->r4) {
        // 0x808023B0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80802398;
    }
    // 0x808023B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808023B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808023B8: bne         $t0, $at, L_808023D0
    if (ctx->r8 != ctx->r1) {
        // 0x808023BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808023D0;
    }
    // 0x808023BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023C0: jal         0x80800A50
    // 0x808023C4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_4;
    // 0x808023C4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_4:
    // 0x808023C8: b           L_80802DF4
    // 0x808023CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802DF4;
    // 0x808023CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808023D0:
    // 0x808023D0: lbu         $v0, 0x15F($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X15F);
    // 0x808023D4: lbu         $t6, 0x15D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15D);
    // 0x808023D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023DC: srl         $t7, $v0, 6
    ctx->r15 = S32(U32(ctx->r2) >> 6);
    // 0x808023E0: bne         $t6, $t7, L_80802DF0
    if (ctx->r14 != ctx->r15) {
        // 0x808023E4: andi        $t8, $v0, 0xFF3F
        ctx->r24 = ctx->r2 & 0XFF3F;
            goto L_80802DF0;
    }
    // 0x808023E4: andi        $t8, $v0, 0xFF3F
    ctx->r24 = ctx->r2 & 0XFF3F;
    // 0x808023E8: sb          $t8, 0x15F($s0)
    MEM_B(0X15F, ctx->r16) = ctx->r24;
    // 0x808023EC: jal         0x80800A50
    // 0x808023F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_5;
    // 0x808023F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808023F4: b           L_80802DF4
    // 0x808023F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802DF4;
    // 0x808023F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808023FC:
    // 0x808023FC: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802400: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80802404: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80802408: srl         $t9, $a3, 15
    ctx->r25 = S32(U32(ctx->r7) >> 15);
    // 0x8080240C: addu        $t4, $s0, $t9
    ctx->r12 = ADD32(ctx->r16, ctx->r25);
    // 0x80802410: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80802414: lbu         $t5, 0x116($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X116);
    // 0x80802418: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x8080241C: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x80802420: lw          $t9, 0x104($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X104);
    // 0x80802424: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x80802428: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x8080242C: addu        $t4, $t6, $t9
    ctx->r12 = ADD32(ctx->r14, ctx->r25);
    // 0x80802430: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80802434: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80802438: sh          $t5, 0x118($t8)
    MEM_H(0X118, ctx->r24) = ctx->r13;
    // 0x8080243C: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802440: srl         $t6, $a3, 15
    ctx->r14 = S32(U32(ctx->r7) >> 15);
    // 0x80802444: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80802448: addu        $t4, $s0, $t6
    ctx->r12 = ADD32(ctx->r16, ctx->r14);
    // 0x8080244C: lbu         $t7, 0x116($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X116);
    // 0x80802450: addu        $t1, $s0, $t9
    ctx->r9 = ADD32(ctx->r16, ctx->r25);
    // 0x80802454: lw          $t8, 0x104($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X104);
    // 0x80802458: sll         $t5, $t7, 3
    ctx->r13 = S32(ctx->r15 << 3);
    // 0x8080245C: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x80802460: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80802464: sw          $t9, 0x10C($t1)
    MEM_W(0X10C, ctx->r9) = ctx->r25;
    // 0x80802468: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x8080246C: srl         $t4, $a3, 15
    ctx->r12 = S32(U32(ctx->r7) >> 15);
    // 0x80802470: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x80802474: addu        $t5, $s0, $t7
    ctx->r13 = ADD32(ctx->r16, ctx->r15);
    // 0x80802478: lh          $v0, 0x118($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X118);
    // 0x8080247C: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x80802480: beq         $v0, $at, L_808024E4
    if (ctx->r2 == ctx->r1) {
        // 0x80802484: addiu       $at, $zero, -0x8
        ctx->r1 = ADD32(0, -0X8);
            goto L_808024E4;
    }
    // 0x80802484: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80802488: beq         $v0, $at, L_808024B0
    if (ctx->r2 == ctx->r1) {
        // 0x8080248C: sll         $t8, $a3, 2
        ctx->r24 = S32(ctx->r7 << 2);
            goto L_808024B0;
    }
    // 0x8080248C: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x80802490: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80802494: beq         $v0, $at, L_80802530
    if (ctx->r2 == ctx->r1) {
        // 0x80802498: sll         $t4, $a3, 2
        ctx->r12 = S32(ctx->r7 << 2);
            goto L_80802530;
    }
    // 0x80802498: sll         $t4, $a3, 2
    ctx->r12 = S32(ctx->r7 << 2);
    // 0x8080249C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808024A0: beq         $v0, $at, L_80802564
    if (ctx->r2 == ctx->r1) {
        // 0x808024A4: addu        $t4, $s0, $a3
        ctx->r12 = ADD32(ctx->r16, ctx->r7);
            goto L_80802564;
    }
    // 0x808024A4: addu        $t4, $s0, $a3
    ctx->r12 = ADD32(ctx->r16, ctx->r7);
    // 0x808024A8: b           L_808025A4
    // 0x808024AC: nop

        goto L_808025A4;
    // 0x808024AC: nop

L_808024B0:
    // 0x808024B0: addu        $t6, $s0, $t8
    ctx->r14 = ADD32(ctx->r16, ctx->r24);
    // 0x808024B4: lw          $t9, 0x10C($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X10C);
    // 0x808024B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024BC: jal         0x80800478
    // 0x808024C0: lbu         $a1, 0x0($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X0);
    func_80800478_gcdialogexec(rdram, ctx);
        goto after_6;
    // 0x808024C0: lbu         $a1, 0x0($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X0);
    after_6:
    // 0x808024C4: lhu         $t4, 0x15E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X15E);
    // 0x808024C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808024CC: srl         $t7, $t4, 15
    ctx->r15 = S32(U32(ctx->r12) >> 15);
    // 0x808024D0: addu        $a2, $s0, $t7
    ctx->r6 = ADD32(ctx->r16, ctx->r15);
    // 0x808024D4: lbu         $t5, 0x116($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X116);
    // 0x808024D8: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x808024DC: b           L_808025A4
    // 0x808024E0: sb          $t8, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r24;
        goto L_808025A4;
    // 0x808024E0: sb          $t8, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r24;
L_808024E4:
    // 0x808024E4: lhu         $t6, 0x15A($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X15A);
    // 0x808024E8: sll         $t4, $a3, 2
    ctx->r12 = S32(ctx->r7 << 2);
    // 0x808024EC: addu        $t7, $s0, $t4
    ctx->r15 = ADD32(ctx->r16, ctx->r12);
    // 0x808024F0: andi        $t9, $t6, 0x200
    ctx->r25 = ctx->r14 & 0X200;
    // 0x808024F4: bne         $t9, $zero, L_80802518
    if (ctx->r25 != 0) {
        // 0x808024F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802518;
    }
    // 0x808024F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024FC: lw          $t5, 0x10C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X10C);
    // 0x80802500: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802504: jal         0x800880C8
    // 0x80802508: lbu         $a1, 0x0($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X0);
    _gcdialogcamera_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x80802508: lbu         $a1, 0x0($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X0);
    after_7:
    // 0x8080250C: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802510: srl         $t8, $a3, 15
    ctx->r24 = S32(U32(ctx->r7) >> 15);
    // 0x80802514: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_80802518:
    // 0x80802518: addu        $a2, $s0, $a3
    ctx->r6 = ADD32(ctx->r16, ctx->r7);
    // 0x8080251C: lbu         $t6, 0x116($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X116);
    // 0x80802520: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80802524: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80802528: b           L_808025A4
    // 0x8080252C: sb          $t9, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r25;
        goto L_808025A4;
    // 0x8080252C: sb          $t9, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r25;
L_80802530:
    // 0x80802530: addu        $t7, $s0, $t4
    ctx->r15 = ADD32(ctx->r16, ctx->r12);
    // 0x80802534: lw          $t5, 0x10C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X10C);
    // 0x80802538: addu        $a2, $s0, $a3
    ctx->r6 = ADD32(ctx->r16, ctx->r7);
    // 0x8080253C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802540: lbu         $t8, 0x0($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X0);
    // 0x80802544: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80802548: sb          $t8, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r24;
    // 0x8080254C: lbu         $t6, 0x116($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X116);
    // 0x80802550: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80802554: jal         0x80800A50
    // 0x80802558: sb          $t9, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r25;
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_8;
    // 0x80802558: sb          $t9, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r25;
    after_8:
    // 0x8080255C: b           L_808025A4
    // 0x80802560: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_808025A4;
    // 0x80802560: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80802564:
    // 0x80802564: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    // 0x80802568: lh          $a1, 0x162($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X162);
    // 0x8080256C: jal         0x8008A228
    // 0x80802570: lbu         $a2, 0x116($t4)
    ctx->r6 = MEM_BU(ctx->r12, 0X116);
    _subaddiedialog_entrypoint_15(rdram, ctx);
        goto after_9;
    // 0x80802570: lbu         $a2, 0x116($t4)
    ctx->r6 = MEM_BU(ctx->r12, 0X116);
    after_9:
    // 0x80802574: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802578: bne         $v0, $at, L_80802588
    if (ctx->r2 != ctx->r1) {
        // 0x8080257C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802588;
    }
    // 0x8080257C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802580: jal         0x80800A50
    // 0x80802584: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_10;
    // 0x80802584: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_10:
L_80802588:
    // 0x80802588: lhu         $t7, 0x15E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X15E);
    // 0x8080258C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80802590: srl         $t5, $t7, 15
    ctx->r13 = S32(U32(ctx->r15) >> 15);
    // 0x80802594: addu        $a2, $s0, $t5
    ctx->r6 = ADD32(ctx->r16, ctx->r13);
    // 0x80802598: lbu         $t8, 0x116($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X116);
    // 0x8080259C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x808025A0: sb          $t6, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r14;
L_808025A4:
    // 0x808025A4: bnel        $v1, $zero, L_80802DF4
    if (ctx->r3 != 0) {
        // 0x808025A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802DF4;
    }
    goto skip_0;
    // 0x808025A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808025AC: lhu         $t9, 0x15E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X15E);
    // 0x808025B0: srl         $t4, $t9, 15
    ctx->r12 = S32(U32(ctx->r25) >> 15);
    // 0x808025B4: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x808025B8: addu        $t5, $s0, $t7
    ctx->r13 = ADD32(ctx->r16, ctx->r15);
    // 0x808025BC: lw          $a0, 0x120($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X120);
    // 0x808025C0: beql        $a0, $zero, L_80802600
    if (ctx->r4 == 0) {
        // 0x808025C4: lhu         $t7, 0x15E($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X15E);
            goto L_80802600;
    }
    goto skip_1;
    // 0x808025C4: lhu         $t7, 0x15E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X15E);
    skip_1:
    // 0x808025C8: jal         0x80087C18
    // 0x808025CC: nop

    _gczoombox_entrypoint_39(rdram, ctx);
        goto after_11;
    // 0x808025CC: nop

    after_11:
    // 0x808025D0: bnel        $v0, $zero, L_80802600
    if (ctx->r2 != 0) {
        // 0x808025D4: lhu         $t7, 0x15E($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X15E);
            goto L_80802600;
    }
    goto skip_2;
    // 0x808025D4: lhu         $t7, 0x15E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X15E);
    skip_2:
    // 0x808025D8: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x808025DC: srl         $t8, $a3, 15
    ctx->r24 = S32(U32(ctx->r7) >> 15);
    // 0x808025E0: addu        $a2, $s0, $t8
    ctx->r6 = ADD32(ctx->r16, ctx->r24);
    // 0x808025E4: lbu         $t6, 0x11C($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X11C);
    // 0x808025E8: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x808025EC: sll         $t9, $t6, 26
    ctx->r25 = S32(ctx->r14 << 26);
    // 0x808025F0: srl         $t4, $t9, 30
    ctx->r12 = S32(U32(ctx->r25) >> 30);
    // 0x808025F4: beq         $t4, $zero, L_80802620
    if (ctx->r12 == 0) {
        // 0x808025F8: sll         $t6, $a3, 1
        ctx->r14 = S32(ctx->r7 << 1);
            goto L_80802620;
    }
    // 0x808025F8: sll         $t6, $a3, 1
    ctx->r14 = S32(ctx->r7 << 1);
    // 0x808025FC: lhu         $t7, 0x15E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X15E);
L_80802600:
    // 0x80802600: srl         $t5, $t7, 15
    ctx->r13 = S32(U32(ctx->r15) >> 15);
    // 0x80802604: lbu         $t7, 0x15E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15E);
    // 0x80802608: xori        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 ^ 0X1;
    // 0x8080260C: sll         $t4, $t6, 7
    ctx->r12 = S32(ctx->r14 << 7);
    // 0x80802610: andi        $t5, $t7, 0xFF7F
    ctx->r13 = ctx->r15 & 0XFF7F;
    // 0x80802614: or          $t8, $t4, $t5
    ctx->r24 = ctx->r12 | ctx->r13;
    // 0x80802618: b           L_80802DF0
    // 0x8080261C: sb          $t8, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r24;
        goto L_80802DF0;
    // 0x8080261C: sb          $t8, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r24;
L_80802620:
    // 0x80802620: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x80802624: lh          $t7, 0x118($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X118);
    // 0x80802628: addiu       $t4, $t7, 0xB
    ctx->r12 = ADD32(ctx->r15, 0XB);
    // 0x8080262C: sltiu       $at, $t4, 0x8
    ctx->r1 = ctx->r12 < 0X8 ? 1 : 0;
    // 0x80802630: beq         $at, $zero, L_80802988
    if (ctx->r1 == 0) {
        // 0x80802634: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80802988;
    }
    // 0x80802634: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80802638: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2594, 0X2E80) << 16);
    // 0x8080263C: addu        $at, $at, $t4
    gpr jr_addend_80802644 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80802640: lw          $t4, 0x2E80($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2594, 0X2E80));
    // 0x80802644: jr          $t4
    // 0x80802648: nop

    switch (jr_addend_80802644 >> 2) {
        case 0: goto L_8080264C; break;
        case 1: goto L_8080264C; break;
        case 2: goto L_80802988; break;
        case 3: goto L_80802988; break;
        case 4: goto L_80802808; break;
        case 5: goto L_8080291C; break;
        case 6: goto L_80802780; break;
        case 7: goto L_808026CC; break;
        default: switch_error(__func__, 0x80802644, 0x80802E80);
    }
    // 0x80802648: nop

L_8080264C:
    // 0x8080264C: addiu       $t3, $zero, -0xA
    ctx->r11 = ADD32(0, -0XA);
    // 0x80802650: addiu       $t2, $zero, -0xB
    ctx->r10 = ADD32(0, -0XB);
    // 0x80802654: addu        $a2, $s0, $a3
    ctx->r6 = ADD32(ctx->r16, ctx->r7);
L_80802658:
    // 0x80802658: lbu         $t5, 0x116($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X116);
    // 0x8080265C: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x80802660: sb          $t8, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r24;
    // 0x80802664: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802668: srl         $t6, $a3, 15
    ctx->r14 = S32(U32(ctx->r7) >> 15);
    // 0x8080266C: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x80802670: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80802674: lbu         $t7, 0x116($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X116);
    // 0x80802678: addu        $t8, $s0, $t5
    ctx->r24 = ADD32(ctx->r16, ctx->r13);
    // 0x8080267C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80802680: lw          $t6, 0x104($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X104);
    // 0x80802684: sll         $t4, $t7, 3
    ctx->r12 = S32(ctx->r15 << 3);
    // 0x80802688: sll         $t5, $a3, 1
    ctx->r13 = S32(ctx->r7 << 1);
    // 0x8080268C: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x80802690: lh          $t7, 0x0($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X0);
    // 0x80802694: addu        $t8, $s0, $t5
    ctx->r24 = ADD32(ctx->r16, ctx->r13);
    // 0x80802698: sh          $t7, 0x118($t8)
    MEM_H(0X118, ctx->r24) = ctx->r15;
    // 0x8080269C: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x808026A0: srl         $t4, $a3, 15
    ctx->r12 = S32(U32(ctx->r7) >> 15);
    // 0x808026A4: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x808026A8: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x808026AC: lh          $v0, 0x118($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X118);
    // 0x808026B0: or          $a3, $t4, $zero
    ctx->r7 = ctx->r12 | 0;
    // 0x808026B4: beql        $t3, $v0, L_80802658
    if (ctx->r11 == ctx->r2) {
        // 0x808026B8: addu        $a2, $s0, $a3
        ctx->r6 = ADD32(ctx->r16, ctx->r7);
            goto L_80802658;
    }
    goto skip_3;
    // 0x808026B8: addu        $a2, $s0, $a3
    ctx->r6 = ADD32(ctx->r16, ctx->r7);
    skip_3:
    // 0x808026BC: beql        $t2, $v0, L_80802658
    if (ctx->r10 == ctx->r2) {
        // 0x808026C0: addu        $a2, $s0, $a3
        ctx->r6 = ADD32(ctx->r16, ctx->r7);
            goto L_80802658;
    }
    goto skip_4;
    // 0x808026C0: addu        $a2, $s0, $a3
    ctx->r6 = ADD32(ctx->r16, ctx->r7);
    skip_4:
    // 0x808026C4: b           L_80802DF4
    // 0x808026C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802DF4;
    // 0x808026C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808026CC:
    // 0x808026CC: lbu         $t5, 0x116($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X116);
    // 0x808026D0: bnel        $t5, $zero, L_80802710
    if (ctx->r13 != 0) {
        // 0x808026D4: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_80802710;
    }
    goto skip_5;
    // 0x808026D4: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    skip_5:
    // 0x808026D8: lw          $t7, 0x15C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X15C);
    // 0x808026DC: sll         $t8, $t7, 26
    ctx->r24 = S32(ctx->r15 << 26);
    // 0x808026E0: lbu         $t7, 0x15F($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X15F);
    // 0x808026E4: srl         $t4, $t8, 30
    ctx->r12 = S32(U32(ctx->r24) >> 30);
    // 0x808026E8: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x808026EC: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x808026F0: andi        $t5, $t9, 0x30
    ctx->r13 = ctx->r25 & 0X30;
    // 0x808026F4: andi        $t8, $t7, 0xFFCF
    ctx->r24 = ctx->r15 & 0XFFCF;
    // 0x808026F8: or          $t4, $t5, $t8
    ctx->r12 = ctx->r13 | ctx->r24;
    // 0x808026FC: sb          $t4, 0x15F($s0)
    MEM_B(0X15F, ctx->r16) = ctx->r12;
    // 0x80802700: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802704: srl         $t6, $a3, 15
    ctx->r14 = S32(U32(ctx->r7) >> 15);
    // 0x80802708: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8080270C: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
L_80802710:
    // 0x80802710: addu        $t7, $s0, $t9
    ctx->r15 = ADD32(ctx->r16, ctx->r25);
    // 0x80802714: jal         0x80087B40
    // 0x80802718: lw          $a0, 0x120($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X120);
    _gczoombox_entrypoint_12(rdram, ctx);
        goto after_12;
    // 0x80802718: lw          $a0, 0x120($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X120);
    after_12:
    // 0x8080271C: lhu         $t5, 0x15E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802720: srl         $t8, $t5, 15
    ctx->r24 = S32(U32(ctx->r13) >> 15);
    // 0x80802724: addu        $a2, $s0, $t8
    ctx->r6 = ADD32(ctx->r16, ctx->r24);
    // 0x80802728: lbu         $t4, 0x11C($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X11C);
    // 0x8080272C: andi        $t6, $t4, 0xFF3F
    ctx->r14 = ctx->r12 & 0XFF3F;
    // 0x80802730: ori         $t9, $t6, 0x40
    ctx->r25 = ctx->r14 | 0X40;
    // 0x80802734: sb          $t9, 0x11C($a2)
    MEM_B(0X11C, ctx->r6) = ctx->r25;
    // 0x80802738: lhu         $t7, 0x15E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X15E);
    // 0x8080273C: srl         $t5, $t7, 15
    ctx->r13 = S32(U32(ctx->r15) >> 15);
    // 0x80802740: addu        $a2, $s0, $t5
    ctx->r6 = ADD32(ctx->r16, ctx->r13);
    // 0x80802744: lbu         $t8, 0x11C($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X11C);
    // 0x80802748: andi        $t4, $t8, 0xFFCF
    ctx->r12 = ctx->r24 & 0XFFCF;
    // 0x8080274C: ori         $t6, $t4, 0x10
    ctx->r14 = ctx->r12 | 0X10;
    // 0x80802750: sb          $t6, 0x11C($a2)
    MEM_B(0X11C, ctx->r6) = ctx->r14;
    // 0x80802754: lhu         $t9, 0x15E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802758: srl         $t7, $t9, 15
    ctx->r15 = S32(U32(ctx->r25) >> 15);
    // 0x8080275C: lbu         $t9, 0x15E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15E);
    // 0x80802760: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x80802764: sll         $t6, $t8, 7
    ctx->r14 = S32(ctx->r24 << 7);
    // 0x80802768: andi        $t7, $t9, 0xFF7F
    ctx->r15 = ctx->r25 & 0XFF7F;
    // 0x8080276C: or          $t4, $t6, $t7
    ctx->r12 = ctx->r14 | ctx->r15;
    // 0x80802770: sb          $t4, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r12;
    // 0x80802774: ori         $t9, $t4, 0x40
    ctx->r25 = ctx->r12 | 0X40;
    // 0x80802778: b           L_80802DF0
    // 0x8080277C: sb          $t9, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r25;
        goto L_80802DF0;
    // 0x8080277C: sb          $t9, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r25;
L_80802780:
    // 0x80802780: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80802784: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80802788: jal         0x80087B40
    // 0x8080278C: lw          $a0, 0x120($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X120);
    _gczoombox_entrypoint_12(rdram, ctx);
        goto after_13;
    // 0x8080278C: lw          $a0, 0x120($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X120);
    after_13:
    // 0x80802790: lhu         $t5, 0x15E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802794: srl         $t8, $t5, 15
    ctx->r24 = S32(U32(ctx->r13) >> 15);
    // 0x80802798: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x8080279C: addu        $t9, $s0, $t4
    ctx->r25 = ADD32(ctx->r16, ctx->r12);
    // 0x808027A0: jal         0x80087B30
    // 0x808027A4: lw          $a0, 0x120($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X120);
    _gczoombox_entrypoint_10(rdram, ctx);
        goto after_14;
    // 0x808027A4: lw          $a0, 0x120($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X120);
    after_14:
    // 0x808027A8: lhu         $t6, 0x15E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X15E);
    // 0x808027AC: srl         $t7, $t6, 15
    ctx->r15 = S32(U32(ctx->r14) >> 15);
    // 0x808027B0: addu        $a2, $s0, $t7
    ctx->r6 = ADD32(ctx->r16, ctx->r15);
    // 0x808027B4: lbu         $t5, 0x11C($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X11C);
    // 0x808027B8: andi        $t8, $t5, 0xFF3F
    ctx->r24 = ctx->r13 & 0XFF3F;
    // 0x808027BC: sb          $t8, 0x11C($a2)
    MEM_B(0X11C, ctx->r6) = ctx->r24;
    // 0x808027C0: lhu         $t4, 0x15E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X15E);
    // 0x808027C4: srl         $t9, $t4, 15
    ctx->r25 = S32(U32(ctx->r12) >> 15);
    // 0x808027C8: addu        $a2, $s0, $t9
    ctx->r6 = ADD32(ctx->r16, ctx->r25);
    // 0x808027CC: lbu         $t6, 0x11C($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X11C);
    // 0x808027D0: andi        $t7, $t6, 0xFFCF
    ctx->r15 = ctx->r14 & 0XFFCF;
    // 0x808027D4: ori         $t5, $t7, 0x10
    ctx->r13 = ctx->r15 | 0X10;
    // 0x808027D8: sb          $t5, 0x11C($a2)
    MEM_B(0X11C, ctx->r6) = ctx->r13;
    // 0x808027DC: lhu         $t8, 0x15E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X15E);
    // 0x808027E0: srl         $t4, $t8, 15
    ctx->r12 = S32(U32(ctx->r24) >> 15);
    // 0x808027E4: lbu         $t8, 0x15E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X15E);
    // 0x808027E8: xori        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 ^ 0X1;
    // 0x808027EC: sll         $t5, $t6, 7
    ctx->r13 = S32(ctx->r14 << 7);
    // 0x808027F0: andi        $t4, $t8, 0xFF7F
    ctx->r12 = ctx->r24 & 0XFF7F;
    // 0x808027F4: or          $t7, $t5, $t4
    ctx->r15 = ctx->r13 | ctx->r12;
    // 0x808027F8: sb          $t7, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r15;
    // 0x808027FC: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80802800: b           L_80802DF0
    // 0x80802804: sb          $t8, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r24;
        goto L_80802DF0;
    // 0x80802804: sb          $t8, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r24;
L_80802808:
    // 0x80802808: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x8080280C: lbu         $a1, 0x116($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X116);
    // 0x80802810: addu        $t1, $s0, $t5
    ctx->r9 = ADD32(ctx->r16, ctx->r13);
    // 0x80802814: lw          $a0, 0x104($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X104);
    // 0x80802818: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x8080281C: addu        $t4, $a0, $v0
    ctx->r12 = ADD32(ctx->r4, ctx->r2);
    // 0x80802820: lh          $v1, 0x0($t4)
    ctx->r3 = MEM_H(ctx->r12, 0X0);
    // 0x80802824: slti        $at, $v1, -0x5
    ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
    // 0x80802828: beq         $at, $zero, L_80802844
    if (ctx->r1 == 0) {
        // 0x8080282C: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80802844;
    }
    // 0x8080282C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80802830:
    // 0x80802830: addu        $t9, $a0, $v0
    ctx->r25 = ADD32(ctx->r4, ctx->r2);
    // 0x80802834: lh          $v1, 0x0($t9)
    ctx->r3 = MEM_H(ctx->r25, 0X0);
    // 0x80802838: slti        $at, $v1, -0x5
    ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
    // 0x8080283C: bnel        $at, $zero, L_80802830
    if (ctx->r1 != 0) {
        // 0x80802840: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80802830;
    }
    goto skip_6;
    // 0x80802840: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    skip_6:
L_80802844:
    // 0x80802844: bltz        $v1, L_80802874
    if (SIGNED(ctx->r3) < 0) {
        // 0x80802848: nop
    
            goto L_80802874;
    }
    // 0x80802848: nop

    // 0x8080284C: addiu       $a1, $v1, 0xC
    ctx->r5 = ADD32(ctx->r3, 0XC);
    // 0x80802850: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80802854: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80802858: jal         0x80087C08
    // 0x8080285C: lw          $a0, 0x120($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X120);
    _gczoombox_entrypoint_37(rdram, ctx);
        goto after_15;
    // 0x8080285C: lw          $a0, 0x120($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X120);
    after_15:
    // 0x80802860: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802864: srl         $t8, $a3, 15
    ctx->r24 = S32(U32(ctx->r7) >> 15);
    // 0x80802868: addu        $a2, $s0, $t8
    ctx->r6 = ADD32(ctx->r16, ctx->r24);
    // 0x8080286C: lbu         $a1, 0x116($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X116);
    // 0x80802870: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_80802874:
    // 0x80802874: beq         $a1, $zero, L_8080289C
    if (ctx->r5 == 0) {
        // 0x80802878: sll         $t5, $a3, 2
        ctx->r13 = S32(ctx->r7 << 2);
            goto L_8080289C;
    }
    // 0x80802878: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x8080287C: addu        $t4, $s0, $t5
    ctx->r12 = ADD32(ctx->r16, ctx->r13);
    // 0x80802880: jal         0x80087B40
    // 0x80802884: lw          $a0, 0x120($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X120);
    _gczoombox_entrypoint_12(rdram, ctx);
        goto after_16;
    // 0x80802884: lw          $a0, 0x120($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X120);
    after_16:
    // 0x80802888: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x8080288C: srl         $t9, $a3, 15
    ctx->r25 = S32(U32(ctx->r7) >> 15);
    // 0x80802890: addu        $a2, $s0, $t9
    ctx->r6 = ADD32(ctx->r16, ctx->r25);
    // 0x80802894: lbu         $a1, 0x116($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X116);
    // 0x80802898: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
L_8080289C:
    // 0x8080289C: bne         $a1, $zero, L_808028D0
    if (ctx->r5 != 0) {
        // 0x808028A0: lbu         $v0, 0x11C($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X11C);
            goto L_808028D0;
    }
    // 0x808028A0: lbu         $v0, 0x11C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X11C);
    // 0x808028A4: srl         $t6, $v0, 6
    ctx->r14 = S32(U32(ctx->r2) >> 6);
    // 0x808028A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808028AC: bne         $t6, $at, L_808028D0
    if (ctx->r14 != ctx->r1) {
        // 0x808028B0: sll         $t7, $a3, 2
        ctx->r15 = S32(ctx->r7 << 2);
            goto L_808028D0;
    }
    // 0x808028B0: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x808028B4: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x808028B8: jal         0x80087B40
    // 0x808028BC: lw          $a0, 0x120($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X120);
    _gczoombox_entrypoint_12(rdram, ctx);
        goto after_17;
    // 0x808028BC: lw          $a0, 0x120($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X120);
    after_17:
    // 0x808028C0: lhu         $t5, 0x15E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X15E);
    // 0x808028C4: srl         $t4, $t5, 15
    ctx->r12 = S32(U32(ctx->r13) >> 15);
    // 0x808028C8: addu        $a2, $s0, $t4
    ctx->r6 = ADD32(ctx->r16, ctx->r12);
    // 0x808028CC: lbu         $v0, 0x11C($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X11C);
L_808028D0:
    // 0x808028D0: andi        $t9, $v0, 0xFF3F
    ctx->r25 = ctx->r2 & 0XFF3F;
    // 0x808028D4: sb          $t9, 0x11C($a2)
    MEM_B(0X11C, ctx->r6) = ctx->r25;
    // 0x808028D8: lhu         $t6, 0x15E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X15E);
    // 0x808028DC: srl         $t7, $t6, 15
    ctx->r15 = S32(U32(ctx->r14) >> 15);
    // 0x808028E0: addu        $a2, $s0, $t7
    ctx->r6 = ADD32(ctx->r16, ctx->r15);
    // 0x808028E4: lbu         $t8, 0x116($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X116);
    // 0x808028E8: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x808028EC: sb          $t5, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r13;
    // 0x808028F0: lhu         $t4, 0x15E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X15E);
    // 0x808028F4: srl         $t9, $t4, 15
    ctx->r25 = S32(U32(ctx->r12) >> 15);
    // 0x808028F8: lbu         $t4, 0x15E($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X15E);
    // 0x808028FC: xori        $t7, $t9, 0x1
    ctx->r15 = ctx->r25 ^ 0X1;
    // 0x80802900: sll         $t5, $t7, 7
    ctx->r13 = S32(ctx->r15 << 7);
    // 0x80802904: andi        $t9, $t4, 0xFF7F
    ctx->r25 = ctx->r12 & 0XFF7F;
    // 0x80802908: or          $t8, $t5, $t9
    ctx->r24 = ctx->r13 | ctx->r25;
    // 0x8080290C: sb          $t8, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r24;
    // 0x80802910: ori         $t4, $t8, 0x40
    ctx->r12 = ctx->r24 | 0X40;
    // 0x80802914: b           L_80802DF0
    // 0x80802918: sb          $t4, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r12;
        goto L_80802DF0;
    // 0x80802918: sb          $t4, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r12;
L_8080291C:
    // 0x8080291C: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x80802920: addu        $t9, $s0, $t5
    ctx->r25 = ADD32(ctx->r16, ctx->r13);
    // 0x80802924: jal         0x80087B40
    // 0x80802928: lw          $a0, 0x120($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X120);
    _gczoombox_entrypoint_12(rdram, ctx);
        goto after_18;
    // 0x80802928: lw          $a0, 0x120($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X120);
    after_18:
    // 0x8080292C: lhu         $t6, 0x15E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802930: srl         $t7, $t6, 15
    ctx->r15 = S32(U32(ctx->r14) >> 15);
    // 0x80802934: addu        $a2, $s0, $t7
    ctx->r6 = ADD32(ctx->r16, ctx->r15);
    // 0x80802938: lbu         $t8, 0x11C($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X11C);
    // 0x8080293C: andi        $t4, $t8, 0xFF3F
    ctx->r12 = ctx->r24 & 0XFF3F;
    // 0x80802940: sb          $t4, 0x11C($a2)
    MEM_B(0X11C, ctx->r6) = ctx->r12;
    // 0x80802944: lhu         $t5, 0x15E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802948: srl         $t9, $t5, 15
    ctx->r25 = S32(U32(ctx->r13) >> 15);
    // 0x8080294C: addu        $a2, $s0, $t9
    ctx->r6 = ADD32(ctx->r16, ctx->r25);
    // 0x80802950: lbu         $t6, 0x116($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X116);
    // 0x80802954: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80802958: sb          $t7, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r15;
    // 0x8080295C: lhu         $t8, 0x15E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802960: srl         $t4, $t8, 15
    ctx->r12 = S32(U32(ctx->r24) >> 15);
    // 0x80802964: lbu         $t8, 0x15E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X15E);
    // 0x80802968: xori        $t9, $t4, 0x1
    ctx->r25 = ctx->r12 ^ 0X1;
    // 0x8080296C: sll         $t7, $t9, 7
    ctx->r15 = S32(ctx->r25 << 7);
    // 0x80802970: andi        $t4, $t8, 0xFF7F
    ctx->r12 = ctx->r24 & 0XFF7F;
    // 0x80802974: or          $t6, $t7, $t4
    ctx->r14 = ctx->r15 | ctx->r12;
    // 0x80802978: sb          $t6, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r14;
    // 0x8080297C: ori         $t8, $t6, 0x40
    ctx->r24 = ctx->r14 | 0X40;
    // 0x80802980: b           L_80802DF0
    // 0x80802984: sb          $t8, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r24;
        goto L_80802DF0;
    // 0x80802984: sb          $t8, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r24;
L_80802988:
    // 0x80802988: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x8080298C: lbu         $t7, 0x116($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X116);
    // 0x80802990: addu        $t9, $s0, $t5
    ctx->r25 = ADD32(ctx->r16, ctx->r13);
    // 0x80802994: lw          $t6, 0x104($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X104);
    // 0x80802998: sll         $t4, $t7, 3
    ctx->r12 = S32(ctx->r15 << 3);
    // 0x8080299C: addiu       $t3, $zero, -0xA
    ctx->r11 = ADD32(0, -0XA);
    // 0x808029A0: addu        $v1, $t4, $t6
    ctx->r3 = ADD32(ctx->r12, ctx->r14);
    // 0x808029A4: lh          $v0, 0x8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X8);
    // 0x808029A8: addiu       $t2, $zero, -0xB
    ctx->r10 = ADD32(0, -0XB);
    // 0x808029AC: bne         $t3, $v0, L_808029E8
    if (ctx->r11 != ctx->r2) {
        // 0x808029B0: nop
    
            goto L_808029E8;
    }
    // 0x808029B0: nop

    // 0x808029B4: jal         0x80801DB4
    // 0x808029B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801DB4_gcdialogexec(rdram, ctx);
        goto after_19;
    // 0x808029B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808029BC: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x808029C0: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x808029C4: srl         $t8, $a3, 15
    ctx->r24 = S32(U32(ctx->r7) >> 15);
    // 0x808029C8: addu        $t7, $s0, $t8
    ctx->r15 = ADD32(ctx->r16, ctx->r24);
    // 0x808029CC: lbu         $t5, 0x116($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X116);
    // 0x808029D0: sll         $t4, $t8, 2
    ctx->r12 = S32(ctx->r24 << 2);
    // 0x808029D4: addu        $t6, $s0, $t4
    ctx->r14 = ADD32(ctx->r16, ctx->r12);
    // 0x808029D8: lw          $t8, 0x104($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X104);
    // 0x808029DC: sll         $t9, $t5, 3
    ctx->r25 = S32(ctx->r13 << 3);
    // 0x808029E0: b           L_80802A20
    // 0x808029E4: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
        goto L_80802A20;
    // 0x808029E4: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
L_808029E8:
    // 0x808029E8: bne         $t2, $v0, L_80802A20
    if (ctx->r10 != ctx->r2) {
        // 0x808029EC: nop
    
            goto L_80802A20;
    }
    // 0x808029EC: nop

    // 0x808029F0: jal         0x80802020
    // 0x808029F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802020_gcdialogexec(rdram, ctx);
        goto after_20;
    // 0x808029F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808029F8: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x808029FC: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802A00: srl         $t7, $a3, 15
    ctx->r15 = S32(U32(ctx->r7) >> 15);
    // 0x80802A04: addu        $t5, $s0, $t7
    ctx->r13 = ADD32(ctx->r16, ctx->r15);
    // 0x80802A08: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80802A0C: lbu         $t4, 0x116($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X116);
    // 0x80802A10: addu        $t8, $s0, $t9
    ctx->r24 = ADD32(ctx->r16, ctx->r25);
    // 0x80802A14: lw          $t7, 0x104($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X104);
    // 0x80802A18: sll         $t6, $t4, 3
    ctx->r14 = S32(ctx->r12 << 3);
    // 0x80802A1C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
L_80802A20:
    // 0x80802A20: jal         0x80087AE8
    // 0x80802A24: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    _gczoombox_entrypoint_1(rdram, ctx);
        goto after_21;
    // 0x80802A24: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    after_21:
    // 0x80802A28: bnel        $v0, $zero, L_80802A50
    if (ctx->r2 != 0) {
        // 0x80802A2C: lw          $a0, 0x168($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X168);
            goto L_80802A50;
    }
    goto skip_7;
    // 0x80802A2C: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
    skip_7:
    // 0x80802A30: lhu         $t5, 0x15E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802A34: srl         $t4, $t5, 15
    ctx->r12 = S32(U32(ctx->r13) >> 15);
    // 0x80802A38: addu        $a2, $s0, $t4
    ctx->r6 = ADD32(ctx->r16, ctx->r12);
    // 0x80802A3C: lbu         $t9, 0x116($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X116);
    // 0x80802A40: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80802A44: b           L_80802DF0
    // 0x80802A48: sb          $t8, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r24;
        goto L_80802DF0;
    // 0x80802A48: sb          $t8, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r24;
    // 0x80802A4C: lw          $a0, 0x168($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X168);
L_80802A50:
    // 0x80802A50: jal         0x80800000
    // 0x80802A54: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    func_80800000_gcdialogexec(rdram, ctx);
        goto after_22;
    // 0x80802A54: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_22:
    // 0x80802A58: addiu       $t2, $zero, -0xB
    ctx->r10 = ADD32(0, -0XB);
    // 0x80802A5C: beq         $v0, $zero, L_80802A90
    if (ctx->r2 == 0) {
        // 0x80802A60: addiu       $t3, $zero, -0xA
        ctx->r11 = ADD32(0, -0XA);
            goto L_80802A90;
    }
    // 0x80802A60: addiu       $t3, $zero, -0xA
    ctx->r11 = ADD32(0, -0XA);
    // 0x80802A64: lhu         $t6, 0x15E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802A68: lw          $a1, 0x168($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X168);
    // 0x80802A6C: lbu         $a2, 0x167($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X167);
    // 0x80802A70: srl         $t7, $t6, 15
    ctx->r15 = S32(U32(ctx->r14) >> 15);
    // 0x80802A74: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x80802A78: addu        $t4, $s0, $t5
    ctx->r12 = ADD32(ctx->r16, ctx->r13);
    // 0x80802A7C: lw          $a0, 0x120($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X120);
    // 0x80802A80: jal         0x80087BF8
    // 0x80802A84: lw          $a3, 0x16C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X16C);
    _gczoombox_entrypoint_35(rdram, ctx);
        goto after_23;
    // 0x80802A84: lw          $a3, 0x16C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X16C);
    after_23:
    // 0x80802A88: addiu       $t2, $zero, -0xB
    ctx->r10 = ADD32(0, -0XB);
    // 0x80802A8C: addiu       $t3, $zero, -0xA
    ctx->r11 = ADD32(0, -0XA);
L_80802A90:
    // 0x80802A90: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x80802A94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80802A98: bnel        $t9, $at, L_80802B30
    if (ctx->r25 != ctx->r1) {
        // 0x80802A9C: lw          $t8, 0x15C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X15C);
            goto L_80802B30;
    }
    goto skip_8;
    // 0x80802A9C: lw          $t8, 0x15C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X15C);
    skip_8:
    // 0x80802AA0: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802AA4: srl         $t8, $a3, 15
    ctx->r24 = S32(U32(ctx->r7) >> 15);
    // 0x80802AA8: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x80802AAC: addu        $t4, $s0, $t5
    ctx->r12 = ADD32(ctx->r16, ctx->r13);
    // 0x80802AB0: lh          $a1, 0x118($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X118);
    // 0x80802AB4: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80802AB8: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80802ABC: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80802AC0: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80802AC4: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80802AC8: lw          $a0, 0x120($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X120);
    // 0x80802ACC: jal         0x80087C08
    // 0x80802AD0: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    _gczoombox_entrypoint_37(rdram, ctx);
        goto after_24;
    // 0x80802AD0: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    after_24:
    // 0x80802AD4: beql        $v0, $zero, L_80802B10
    if (ctx->r2 == 0) {
        // 0x80802AD8: lhu         $t7, 0x15E($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X15E);
            goto L_80802B10;
    }
    goto skip_9;
    // 0x80802AD8: lhu         $t7, 0x15E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X15E);
    skip_9:
    // 0x80802ADC: lhu         $t6, 0x15E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802AE0: srl         $t7, $t6, 15
    ctx->r15 = S32(U32(ctx->r14) >> 15);
    // 0x80802AE4: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x80802AE8: addu        $t4, $s0, $t5
    ctx->r12 = ADD32(ctx->r16, ctx->r13);
    // 0x80802AEC: jal         0x80087B40
    // 0x80802AF0: lw          $a0, 0x120($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X120);
    _gczoombox_entrypoint_12(rdram, ctx);
        goto after_25;
    // 0x80802AF0: lw          $a0, 0x120($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X120);
    after_25:
    // 0x80802AF4: lbu         $t8, 0x15E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X15E);
    // 0x80802AF8: addiu       $t2, $zero, -0xB
    ctx->r10 = ADD32(0, -0XB);
    // 0x80802AFC: addiu       $t3, $zero, -0xA
    ctx->r11 = ADD32(0, -0XA);
    // 0x80802B00: ori         $t6, $t8, 0x40
    ctx->r14 = ctx->r24 | 0X40;
    // 0x80802B04: b           L_80802B2C
    // 0x80802B08: sb          $t6, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r14;
        goto L_80802B2C;
    // 0x80802B08: sb          $t6, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r14;
    // 0x80802B0C: lhu         $t7, 0x15E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X15E);
L_80802B10:
    // 0x80802B10: srl         $t5, $t7, 15
    ctx->r13 = S32(U32(ctx->r15) >> 15);
    // 0x80802B14: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80802B18: addu        $t9, $s0, $t4
    ctx->r25 = ADD32(ctx->r16, ctx->r12);
    // 0x80802B1C: jal         0x80087B70
    // 0x80802B20: lw          $a0, 0x120($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X120);
    _gczoombox_entrypoint_18(rdram, ctx);
        goto after_26;
    // 0x80802B20: lw          $a0, 0x120($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X120);
    after_26:
    // 0x80802B24: addiu       $t2, $zero, -0xB
    ctx->r10 = ADD32(0, -0XB);
    // 0x80802B28: addiu       $t3, $zero, -0xA
    ctx->r11 = ADD32(0, -0XA);
L_80802B2C:
    // 0x80802B2C: lw          $t8, 0x15C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X15C);
L_80802B30:
    // 0x80802B30: sll         $t7, $t8, 17
    ctx->r15 = S32(ctx->r24 << 17);
    // 0x80802B34: bgezl       $t7, L_80802B6C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80802B38: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80802B6C;
    }
    goto skip_10;
    // 0x80802B38: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    skip_10:
    // 0x80802B3C: lhu         $t5, 0x15E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802B40: srl         $t4, $t5, 15
    ctx->r12 = S32(U32(ctx->r13) >> 15);
    // 0x80802B44: sll         $t9, $t4, 2
    ctx->r25 = S32(ctx->r12 << 2);
    // 0x80802B48: addu        $t8, $s0, $t9
    ctx->r24 = ADD32(ctx->r16, ctx->r25);
    // 0x80802B4C: jal         0x80087B38
    // 0x80802B50: lw          $a0, 0x120($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X120);
    _gczoombox_entrypoint_11(rdram, ctx);
        goto after_27;
    // 0x80802B50: lw          $a0, 0x120($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X120);
    after_27:
    // 0x80802B54: lbu         $t6, 0x15E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15E);
    // 0x80802B58: addiu       $t2, $zero, -0xB
    ctx->r10 = ADD32(0, -0XB);
    // 0x80802B5C: addiu       $t3, $zero, -0xA
    ctx->r11 = ADD32(0, -0XA);
    // 0x80802B60: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x80802B64: sb          $t7, 0x15E($s0)
    MEM_B(0X15E, ctx->r16) = ctx->r15;
    // 0x80802B68: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
L_80802B6C:
    // 0x80802B6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80802B70: bnel        $t5, $at, L_80802CB8
    if (ctx->r13 != ctx->r1) {
        // 0x80802B74: lhu         $t9, 0x15E($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X15E);
            goto L_80802CB8;
    }
    goto skip_11;
    // 0x80802B74: lhu         $t9, 0x15E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X15E);
    skip_11:
    // 0x80802B78: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802B7C: srl         $t4, $a3, 15
    ctx->r12 = S32(U32(ctx->r7) >> 15);
    // 0x80802B80: addu        $t9, $s0, $t4
    ctx->r25 = ADD32(ctx->r16, ctx->r12);
    // 0x80802B84: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x80802B88: lbu         $a1, 0x116($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X116);
    // 0x80802B8C: addu        $t1, $s0, $t8
    ctx->r9 = ADD32(ctx->r16, ctx->r24);
    // 0x80802B90: lw          $t6, 0x104($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X104);
    // 0x80802B94: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80802B98: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80802B9C: addu        $t9, $s0, $t4
    ctx->r25 = ADD32(ctx->r16, ctx->r12);
    // 0x80802BA0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80802BA4: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x80802BA8: lh          $t8, 0x118($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X118);
    // 0x80802BAC: subu        $t6, $a1, $a1
    ctx->r14 = SUB32(ctx->r5, ctx->r5);
    // 0x80802BB0: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80802BB4: bne         $t5, $t8, L_80802C60
    if (ctx->r13 != ctx->r24) {
        // 0x80802BB8: or          $t0, $a1, $zero
        ctx->r8 = ctx->r5 | 0;
            goto L_80802C60;
    }
    // 0x80802BB8: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80802BBC: beql        $at, $zero, L_80802C64
    if (ctx->r1 == 0) {
        // 0x80802BC0: lw          $a0, 0x120($t1)
        ctx->r4 = MEM_W(ctx->r9, 0X120);
            goto L_80802C64;
    }
    goto skip_12;
    // 0x80802BC0: lw          $a0, 0x120($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X120);
    skip_12:
    // 0x80802BC4: lh          $v0, 0x8($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X8);
    // 0x80802BC8: beql        $t2, $v0, L_80802C64
    if (ctx->r10 == ctx->r2) {
        // 0x80802BCC: lw          $a0, 0x120($t1)
        ctx->r4 = MEM_W(ctx->r9, 0X120);
            goto L_80802C64;
    }
    goto skip_13;
    // 0x80802BCC: lw          $a0, 0x120($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X120);
    skip_13:
    // 0x80802BD0: beq         $t3, $v0, L_80802C60
    if (ctx->r11 == ctx->r2) {
        // 0x80802BD4: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_80802C60;
    }
    // 0x80802BD4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80802BD8: addiu       $t4, $sp, 0x44
    ctx->r12 = ADD32(ctx->r29, 0X44);
    // 0x80802BDC: addu        $v1, $t7, $t4
    ctx->r3 = ADD32(ctx->r15, ctx->r12);
    // 0x80802BE0: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
L_80802BE4:
    // 0x80802BE4: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x80802BE8: negu        $t8, $t5
    ctx->r24 = SUB32(0, ctx->r13);
    // 0x80802BEC: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x80802BF0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80802BF4: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802BF8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80802BFC: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
    // 0x80802C00: srl         $t7, $a3, 15
    ctx->r15 = S32(U32(ctx->r7) >> 15);
    // 0x80802C04: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x80802C08: addu        $t1, $s0, $t4
    ctx->r9 = ADD32(ctx->r16, ctx->r12);
    // 0x80802C0C: lw          $t5, 0x104($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X104);
    // 0x80802C10: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80802C14: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x80802C18: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80802C1C: addu        $a0, $t5, $t8
    ctx->r4 = ADD32(ctx->r13, ctx->r24);
    // 0x80802C20: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x80802C24: lh          $t4, 0x118($t7)
    ctx->r12 = MEM_H(ctx->r15, 0X118);
    // 0x80802C28: addu        $t5, $s0, $a3
    ctx->r13 = ADD32(ctx->r16, ctx->r7);
    // 0x80802C2C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80802C30: bnel        $t9, $t4, L_80802C64
    if (ctx->r25 != ctx->r12) {
        // 0x80802C34: lw          $a0, 0x120($t1)
        ctx->r4 = MEM_W(ctx->r9, 0X120);
            goto L_80802C64;
    }
    goto skip_14;
    // 0x80802C34: lw          $a0, 0x120($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X120);
    skip_14:
    // 0x80802C38: lbu         $a1, 0x116($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X116);
    // 0x80802C3C: subu        $t8, $t0, $a1
    ctx->r24 = SUB32(ctx->r8, ctx->r5);
    // 0x80802C40: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x80802C44: beql        $at, $zero, L_80802C64
    if (ctx->r1 == 0) {
        // 0x80802C48: lw          $a0, 0x120($t1)
        ctx->r4 = MEM_W(ctx->r9, 0X120);
            goto L_80802C64;
    }
    goto skip_15;
    // 0x80802C48: lw          $a0, 0x120($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X120);
    skip_15:
    // 0x80802C4C: lh          $v0, 0x8($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X8);
    // 0x80802C50: beql        $t2, $v0, L_80802C64
    if (ctx->r10 == ctx->r2) {
        // 0x80802C54: lw          $a0, 0x120($t1)
        ctx->r4 = MEM_W(ctx->r9, 0X120);
            goto L_80802C64;
    }
    goto skip_16;
    // 0x80802C54: lw          $a0, 0x120($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X120);
    skip_16:
    // 0x80802C58: bnel        $t3, $v0, L_80802BE4
    if (ctx->r11 != ctx->r2) {
        // 0x80802C5C: lw          $t9, 0x4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X4);
            goto L_80802BE4;
    }
    goto skip_17;
    // 0x80802C5C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    skip_17:
L_80802C60:
    // 0x80802C60: lw          $a0, 0x120($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X120);
L_80802C64:
    // 0x80802C64: jal         0x80087BE0
    // 0x80802C68: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    _gczoombox_entrypoint_32(rdram, ctx);
        goto after_28;
    // 0x80802C68: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    after_28:
    // 0x80802C6C: lhu         $a3, 0x15E($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802C70: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80802C74: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80802C78: srl         $t6, $a3, 15
    ctx->r14 = S32(U32(ctx->r7) >> 15);
    // 0x80802C7C: addu        $t4, $s0, $t6
    ctx->r12 = ADD32(ctx->r16, ctx->r14);
    // 0x80802C80: lbu         $t5, 0x116($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X116);
    // 0x80802C84: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80802C88: addu        $t9, $s0, $t7
    ctx->r25 = ADD32(ctx->r16, ctx->r15);
    // 0x80802C8C: lw          $a0, 0x120($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X120);
    // 0x80802C90: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80802C94: jal         0x80087B18
    // 0x80802C98: subu        $a1, $t0, $t5
    ctx->r5 = SUB32(ctx->r8, ctx->r13);
    _gczoombox_entrypoint_7(rdram, ctx);
        goto after_29;
    // 0x80802C98: subu        $a1, $t0, $t5
    ctx->r5 = SUB32(ctx->r8, ctx->r13);
    after_29:
    // 0x80802C9C: lhu         $t8, 0x15E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802CA0: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80802CA4: srl         $t6, $t8, 15
    ctx->r14 = S32(U32(ctx->r24) >> 15);
    // 0x80802CA8: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80802CAC: b           L_80802D00
    // 0x80802CB0: sb          $t0, 0x116($t7)
    MEM_B(0X116, ctx->r15) = ctx->r8;
        goto L_80802D00;
    // 0x80802CB0: sb          $t0, 0x116($t7)
    MEM_B(0X116, ctx->r15) = ctx->r8;
    // 0x80802CB4: lhu         $t9, 0x15E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X15E);
L_80802CB8:
    // 0x80802CB8: srl         $t4, $t9, 15
    ctx->r12 = S32(U32(ctx->r25) >> 15);
    // 0x80802CBC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80802CC0: addu        $t8, $s0, $t5
    ctx->r24 = ADD32(ctx->r16, ctx->r13);
    // 0x80802CC4: jal         0x80087BE0
    // 0x80802CC8: lw          $a0, 0x120($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X120);
    _gczoombox_entrypoint_32(rdram, ctx);
        goto after_30;
    // 0x80802CC8: lw          $a0, 0x120($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X120);
    after_30:
    // 0x80802CCC: lhu         $t6, 0x15E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802CD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802CD4: srl         $t7, $t6, 15
    ctx->r15 = S32(U32(ctx->r14) >> 15);
    // 0x80802CD8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80802CDC: addu        $t4, $s0, $t9
    ctx->r12 = ADD32(ctx->r16, ctx->r25);
    // 0x80802CE0: jal         0x80087B20
    // 0x80802CE4: lw          $a0, 0x120($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X120);
    _gczoombox_entrypoint_8(rdram, ctx);
        goto after_31;
    // 0x80802CE4: lw          $a0, 0x120($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X120);
    after_31:
    // 0x80802CE8: lhu         $t5, 0x15E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X15E);
    // 0x80802CEC: srl         $t8, $t5, 15
    ctx->r24 = S32(U32(ctx->r13) >> 15);
    // 0x80802CF0: addu        $a2, $s0, $t8
    ctx->r6 = ADD32(ctx->r16, ctx->r24);
    // 0x80802CF4: lbu         $t6, 0x116($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X116);
    // 0x80802CF8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80802CFC: sb          $t7, 0x116($a2)
    MEM_B(0X116, ctx->r6) = ctx->r15;
L_80802D00:
    // 0x80802D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D04: jal         0x80800A50
    // 0x80802D08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_32;
    // 0x80802D08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_32:
    // 0x80802D0C: b           L_80802DF4
    // 0x80802D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802DF4;
    // 0x80802D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802D14:
    // 0x80802D14: lhu         $v0, 0x15A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X15A);
    // 0x80802D18: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80802D1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802D20: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80802D24: beq         $t9, $zero, L_80802D44
    if (ctx->r25 == 0) {
        // 0x80802D28: andi        $t5, $v0, 0x40
        ctx->r13 = ctx->r2 & 0X40;
            goto L_80802D44;
    }
    // 0x80802D28: andi        $t5, $v0, 0x40
    ctx->r13 = ctx->r2 & 0X40;
    // 0x80802D2C: bne         $t4, $at, L_80802D44
    if (ctx->r12 != ctx->r1) {
        // 0x80802D30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802D44;
    }
    // 0x80802D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D34: jal         0x80800A50
    // 0x80802D38: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_33;
    // 0x80802D38: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_33:
    // 0x80802D3C: b           L_80802DF4
    // 0x80802D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802DF4;
    // 0x80802D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802D44:
    // 0x80802D44: bne         $t5, $zero, L_80802DF0
    if (ctx->r13 != 0) {
        // 0x80802D48: andi        $t8, $v0, 0x80
        ctx->r24 = ctx->r2 & 0X80;
            goto L_80802DF0;
    }
    // 0x80802D48: andi        $t8, $v0, 0x80
    ctx->r24 = ctx->r2 & 0X80;
    // 0x80802D4C: beq         $t8, $zero, L_80802D68
    if (ctx->r24 == 0) {
        // 0x80802D50: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80802D68;
    }
    // 0x80802D50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802D54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802D58: jal         0x80015F0C
    // 0x80802D5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80015F0C(rdram, ctx);
        goto after_34;
    // 0x80802D5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_34:
    // 0x80802D60: b           L_80802D74
    // 0x80802D64: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
        goto L_80802D74;
    // 0x80802D64: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
L_80802D68:
    // 0x80802D68: jal         0x80015F0C
    // 0x80802D6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80015F0C(rdram, ctx);
        goto after_35;
    // 0x80802D6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_35:
    // 0x80802D70: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
L_80802D74:
    // 0x80802D74: bne         $t6, $zero, L_80802DF0
    if (ctx->r14 != 0) {
        // 0x80802D78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802DF0;
    }
    // 0x80802D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D7C: jal         0x80800A50
    // 0x80802D80: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_36;
    // 0x80802D80: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_36:
    // 0x80802D84: b           L_80802DF4
    // 0x80802D88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802DF4;
    // 0x80802D88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802D8C:
    // 0x80802D8C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80802D90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80802D94: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80802D98: bne         $v0, $t7, L_80802DB0
    if (ctx->r2 != ctx->r15) {
        // 0x80802D9C: lw          $t9, 0x78($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X78);
            goto L_80802DB0;
    }
    // 0x80802D9C: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80802DA0: jal         0x800880D0
    // 0x80802DA4: sb          $v0, 0x160($s0)
    MEM_B(0X160, ctx->r16) = ctx->r2;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_37;
    // 0x80802DA4: sb          $v0, 0x160($s0)
    MEM_B(0X160, ctx->r16) = ctx->r2;
    after_37:
    // 0x80802DA8: b           L_80802DC4
    // 0x80802DAC: lb          $t4, 0x160($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X160);
        goto L_80802DC4;
    // 0x80802DAC: lb          $t4, 0x160($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X160);
L_80802DB0:
    // 0x80802DB0: bne         $v0, $t9, L_80802DC0
    if (ctx->r2 != ctx->r25) {
        // 0x80802DB4: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80802DC0;
    }
    // 0x80802DB4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80802DB8: jal         0x800880D0
    // 0x80802DBC: sb          $zero, 0x160($s0)
    MEM_B(0X160, ctx->r16) = 0;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_38;
    // 0x80802DBC: sb          $zero, 0x160($s0)
    MEM_B(0X160, ctx->r16) = 0;
    after_38:
L_80802DC0:
    // 0x80802DC0: lb          $t4, 0x160($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X160);
L_80802DC4:
    // 0x80802DC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80802DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802DCC: beql        $t4, $at, L_80802DF4
    if (ctx->r12 == ctx->r1) {
        // 0x80802DD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802DF4;
    }
    goto skip_18;
    // 0x80802DD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_18:
    // 0x80802DD4: jal         0x80800A50
    // 0x80802DD8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_39;
    // 0x80802DD8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_39:
    // 0x80802DDC: b           L_80802DF4
    // 0x80802DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802DF4;
    // 0x80802DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802DE4:
    // 0x80802DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802DE8: jal         0x80800A50
    // 0x80802DEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800A50_gcdialogexec(rdram, ctx);
        goto after_40;
    // 0x80802DEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_40:
L_80802DF0:
    // 0x80802DF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802DF4:
    // 0x80802DF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802DF8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x80802DFC: jr          $ra
    // 0x80802E00: nop

    return;
    // 0x80802E00: nop

    // 0x80802E04: nop

    // 0x80802E08: nop

    // 0x80802E0C: nop

;}
RECOMP_FUNC void babackpack_get_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chhoneyb_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(800, 0X1020) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1020
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(800, 0X1020));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1020
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(800, 0X1020));
;}
RECOMP_FUNC void func_80800F50_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F58: jal         0x808000F0
    // 0x80800F5C: nop

    bsvan_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800F5C: nop

    after_0:
    // 0x80800F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F68: jr          $ra
    // 0x80800F6C: nop

    return;
    // 0x80800F6C: nop

;}
RECOMP_FUNC void func_800F7E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7E64: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7E68: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7E6C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7E70: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7E74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7E78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7E7C: jal         0x800A3410
    // 0x800F7E80: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800A3410(rdram, ctx);
        goto after_0;
    // 0x800F7E80: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7E84: jal         0x80092778
    // 0x800F7E88: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80092778(rdram, ctx);
        goto after_1;
    // 0x800F7E88: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800F7E8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7E90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7E94: jr          $ra
    // 0x800F7E98: nop

    return;
    // 0x800F7E98: nop

;}
RECOMP_FUNC void func_8080067C_chfactorycrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080067C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800684: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800688: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080068C: jal         0x800E3980
    // 0x80800690: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x80800690: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800694: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1136, 0XA38) << 16);
    // 0x80800698: lwc1        $f4, 0xA38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1136, 0XA38));
    // 0x8080069C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808006A0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808006A4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808006A8: nop

    // 0x808006AC: bc1fl       L_808006C0
    if (!c1cs) {
        // 0x808006B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808006C0;
    }
    goto skip_0;
    // 0x808006B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808006B4: jal         0x80101870
    // 0x808006B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x808006B8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x808006BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006C0:
    // 0x808006C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006C4: jr          $ra
    // 0x808006C8: nop

    return;
    // 0x808006C8: nop

;}
RECOMP_FUNC void capod_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_test_room_quiet()) { ctx->r2 = 0; return; }
    // 0x808003B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C0: jal         0x8008FFE8
    // 0x808003C4: nop

    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x808003C4: nop

    after_0:
    // 0x808003C8: beq         $v0, $zero, L_808003E0
    if (ctx->r2 == 0) {
        // 0x808003CC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808003E0;
    }
    // 0x808003CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003D0: jal         0x80089598
    // 0x808003D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncpod_entrypoint_27(rdram, ctx);
        goto after_1;
    // 0x808003D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808003D8: b           L_808003E8
    // 0x808003DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003E8;
    // 0x808003DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003E0:
    // 0x808003E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003E8:
    // 0x808003E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003EC: jr          $ra
    // 0x808003F0: nop

    return;
    // 0x808003F0: nop

;}
RECOMP_FUNC void func_80800A1C_chdinofamilysick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A24: jal         0x80101F24
    // 0x80800A28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101F24(rdram, ctx);
        goto after_0;
    // 0x80800A28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A2C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2408, 0XF48) << 16);
    // 0x80800A30: addiu       $a1, $a1, 0xF48
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2408, 0XF48));
    // 0x80800A34: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800A38: jal         0x800F3780
    // 0x80800A3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800F3780(rdram, ctx);
        goto after_1;
    // 0x80800A3C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80800A40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800A44: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800A48: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800A4C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800A50: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800A54: bne         $t7, $at, L_80800A68
    if (ctx->r15 != ctx->r1) {
        // 0x80800A58: lui         $at, 0x3F40
        ctx->r1 = S32(0X3F40 << 16);
            goto L_80800A68;
    }
    // 0x80800A58: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800A5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800A60: b           L_80800A78
    // 0x80800A64: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
        goto L_80800A78;
    // 0x80800A64: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
L_80800A68:
    // 0x80800A68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A6C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800A70: nop

    // 0x80800A74: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
L_80800A78:
    // 0x80800A78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A7C: nop

    // 0x80800A80: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80800A84: nop

    // 0x80800A88: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800A8C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800A90: jal         0x80105A9C
    // 0x80800A94: nop

    func_80105A9C(rdram, ctx);
        goto after_2;
    // 0x80800A94: nop

    after_2:
    // 0x80800A98: jal         0x80105834
    // 0x80800A9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80105834(rdram, ctx);
        goto after_3;
    // 0x80800A9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800AA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800AA8: jr          $ra
    // 0x80800AAC: nop

    return;
    // 0x80800AAC: nop

;}
RECOMP_FUNC void func_80800018_chflysaucerdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080001C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800020: lw          $a1, 0x48($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X48);
    // 0x80800024: addiu       $t6, $zero, 0x45
    ctx->r14 = ADD32(0, 0X45);
    // 0x80800028: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8080002C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800030: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800034: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800038: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x8080003C: jal         0x80086898
    // 0x80800040: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800040: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    after_0:
    // 0x80800044: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800048: jal         0x800868A8
    // 0x8080004C: lui         $a1, 0x4060
    ctx->r5 = S32(0X4060 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x8080004C: lui         $a1, 0x4060
    ctx->r5 = S32(0X4060 << 16);
    after_1:
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800054: jal         0x800868C0
    // 0x80800058: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800058: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8080005C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800060: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800064: jr          $ra
    // 0x80800068: nop

    return;
    // 0x80800068: nop

;}
RECOMP_FUNC void subaddiemulti_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800070: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800074: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800078: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080007C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800080: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800084: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800088: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080008C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800090: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_80800094:
    // 0x80800094: jal         0x800F6438
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_0;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080009C: beq         $v0, $zero, L_808000C0
    if (ctx->r2 == 0) {
        // 0x808000A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000C0;
    }
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808000A8: jal         0x800F8300
    // 0x808000AC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800F8300(rdram, ctx);
        goto after_1;
    // 0x808000AC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x808000B0: beq         $s1, $zero, L_808000C0
    if (ctx->r17 == 0) {
        // 0x808000B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000C0;
    }
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x800F608C
    // 0x808000BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F608C(rdram, ctx);
        goto after_2;
    // 0x808000BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
L_808000C0:
    // 0x808000C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808000C4: bne         $s0, $s3, L_80800094
    if (ctx->r16 != ctx->r19) {
        // 0x808000C8: nop
    
            goto L_80800094;
    }
    // 0x808000C8: nop

    // 0x808000CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000D8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808000DC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808000E0: jr          $ra
    // 0x808000E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _suquiz_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A820: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A820);
    return;
    // 0x8008A824: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_8009F308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F308: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009F30C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F310: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8009F314: jal         0x8009C128
    // 0x8009F318: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8009F318: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8009F31C: jal         0x800A4C48
    // 0x8009F320: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800A4C48(rdram, ctx);
        goto after_1;
    // 0x8009F320: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8009F324: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009F328: jal         0x800CA7E4
    // 0x8009F32C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800CA7E4(rdram, ctx);
        goto after_2;
    // 0x8009F32C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x8009F330: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8009F334: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8009F338: jal         0x800F1E6C
    // 0x8009F33C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800F1E6C(rdram, ctx);
        goto after_3;
    // 0x8009F33C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x8009F340: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F344: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8009F348: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8009F34C: jr          $ra
    // 0x8009F350: nop

    return;
    // 0x8009F350: nop

;}
RECOMP_FUNC void sufreezy_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800210: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800214: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800218: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080021C: jal         0x80106790
    // 0x80800220: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800220: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800224: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080022C: jal         0x80100094
    // 0x80800230: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800230: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800234: jal         0x8008A040
    // 0x80800238: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800238: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080023C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800240: jal         0x8010A570
    // 0x80800244: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x80800244: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80800248: jal         0x8010A590
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_4;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: jal         0x80102190
    // 0x80800258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80102190(rdram, ctx);
        goto after_5;
    // 0x80800258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080025C: lbu         $t6, 0x7B($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7B);
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800268: andi        $t7, $t6, 0xFFFB
    ctx->r15 = ctx->r14 & 0XFFFB;
    // 0x8080026C: sb          $t7, 0x7B($s0)
    MEM_B(0X7B, ctx->r16) = ctx->r15;
    // 0x80800270: jal         0x8010108C
    // 0x80800274: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_6;
    // 0x80800274: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800278: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080027C: jal         0x80088628
    // 0x80800280: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    _glhittableDll_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800280: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80800284: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800288: jal         0x80088618
    // 0x8080028C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _glhittableDll_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x8080028C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800290: beq         $v0, $zero, L_808002B0
    if (ctx->r2 == 0) {
        // 0x80800294: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_808002B0;
    }
    // 0x80800294: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800298: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080029C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808002A0: jal         0x800EB2DC
    // 0x808002A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800EB2DC(rdram, ctx);
        goto after_9;
    // 0x808002A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x808002A8: b           L_808002C0
    // 0x808002AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
        goto L_808002C0;
    // 0x808002AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_808002B0:
    // 0x808002B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002B4: jal         0x800EB210
    // 0x808002B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800EB210(rdram, ctx);
        goto after_10;
    // 0x808002B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_10:
    // 0x808002BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_808002C0:
    // 0x808002C0: jal         0x80100094
    // 0x808002C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x808002C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808002C8: jal         0x8008A020
    // 0x808002CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x808002CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x808002D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002DC: jr          $ra
    // 0x808002E0: nop

    return;
    // 0x808002E0: nop

    // 0x808002E4: nop

    // 0x808002E8: nop

    // 0x808002EC: nop

;}
RECOMP_FUNC void func_80092C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092C08: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80092C0C: jal         0x800921E0
    // 0x80092C10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800921E0(rdram, ctx);
        goto after_0;
    // 0x80092C10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80092C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092C18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092C1C: jr          $ra
    // 0x80092C20: nop

    return;
    // 0x80092C20: nop

;}
RECOMP_FUNC void _bstrexlarge_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084008: syscall     101
    recomp_syscall_handler(rdram, ctx, 0x80084008);
    return;
    // 0x8008400C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _subaddiecustomhits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A008: syscall     822
    recomp_syscall_handler(rdram, ctx, 0x8008A008);
    return;
    // 0x8008A00C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808008F0_chballoonburst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800900: jal         0x80100094
    // 0x80800904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800908: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080090C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800910: andi        $t6, $a0, 0x1FF
    ctx->r14 = ctx->r4 & 0X1FF;
    // 0x80800914: jal         0x800CEAA8
    // 0x80800918: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800CEAA8(rdram, ctx);
        goto after_1;
    // 0x80800918: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x8080091C: beql        $v0, $zero, L_8080093C
    if (ctx->r2 == 0) {
        // 0x80800920: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8080093C;
    }
    goto skip_0;
    // 0x80800920: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800924: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80800928: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080092C: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x80800930: jal         0x800CE88C
    // 0x80800934: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800CE88C(rdram, ctx);
        goto after_2;
    // 0x80800934: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x80800938: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_8080093C:
    // 0x8080093C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800940: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80800944: jal         0x8008A2B0
    // 0x80800948: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800948: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_3:
    // 0x8080094C: beq         $v0, $zero, L_8080095C
    if (ctx->r2 == 0) {
        // 0x80800950: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_8080095C;
    }
    // 0x80800950: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800954: jal         0x8008A2C0
    // 0x80800958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8080095C:
    // 0x8080095C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800960: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800964: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800968: jr          $ra
    // 0x8080096C: nop

    return;
    // 0x8080096C: nop

;}
RECOMP_FUNC void func_800B80D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B80D0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B80D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B80D8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800B80DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B80E0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B80E4: addiu       $a1, $a1, -0x7D40
    ctx->r5 = ADD32(ctx->r5, -0X7D40);
    // 0x800B80E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B80EC: lbu         $t2, 0x1($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1);
    // 0x800B80F0: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800B80F4: lbu         $t6, 0x2($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2);
    // 0x800B80F8: lbu         $t1, 0x3($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X3);
    // 0x800B80FC: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x800B8100: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x800B8104: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x800B8108: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800B810C: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800B8110: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x800B8114: jr          $ra
    // 0x800B8118: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    return;
    // 0x800B8118: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
;}
RECOMP_FUNC void _baswim_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852A0: syscall     156
    recomp_syscall_handler(rdram, ctx, 0x800852A0);
    return;
    // 0x800852A4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800F4E5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4E5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F4E60: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800F4E64: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800F4E68: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F4E6C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x800F4E70: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F4E74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F4E78: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800F4E7C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800F4E80: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800F4E84: jal         0x800A3048
    // 0x800F4E88: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800A3048(rdram, ctx);
        goto after_0;
    // 0x800F4E88: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F4E8C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800F4E90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F4E94: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800F4E98: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800F4E9C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F4EA0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800F4EA4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800F4EA8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800F4EAC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800F4EB0: jal         0x8009F440
    // 0x800F4EB4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_8009F440(rdram, ctx);
        goto after_1;
    // 0x800F4EB4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800F4EB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F4EBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F4EC0: jr          $ra
    // 0x800F4EC4: nop

    return;
    // 0x800F4EC4: nop

;}
RECOMP_FUNC void func_808003B8_chstarspinnerctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003C0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808003C4: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x808003C8: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x808003CC: bgezl       $t9, L_80800440
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808003D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800440;
    }
    goto skip_0;
    // 0x808003D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808003D4: jal         0x8001210C
    // 0x808003D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x808003D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x808003DC: bne         $v0, $zero, L_8080043C
    if (ctx->r2 != 0) {
        // 0x808003E0: lw          $a1, 0x30($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X30);
            goto L_8080043C;
    }
    // 0x808003E0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808003E4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808003E8: jal         0x800EE7F8
    // 0x808003EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808003EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x808003F0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x808003F4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808003F8: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x808003FC: jal         0x800EF1B8
    // 0x80800400: lw          $a1, 0x48($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x80800400: lw          $a1, 0x48($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X48);
    after_2:
    // 0x80800404: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800408: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080040C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800410: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(960, 0X9BC) << 16);
    // 0x80800414: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800418: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080041C: addiu       $t1, $t1, 0x9BC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(960, 0X9BC));
    // 0x80800420: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800424: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800428: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8080042C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800430: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800434: jal         0x800BBCB8
    // 0x80800438: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x80800438: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
L_8080043C:
    // 0x8080043C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800440:
    // 0x80800440: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800444: jr          $ra
    // 0x80800448: nop

    return;
    // 0x80800448: nop

;}
