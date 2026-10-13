#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800934_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800934: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800938: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8080093C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800940: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800944: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800948: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080094C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800950: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80800954: jal         0x80100094
    // 0x80800958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080095C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80800960: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800964: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80800968: slti        $at, $a2, 0x33
    ctx->r1 = SIGNED(ctx->r6) < 0X33 ? 1 : 0;
    // 0x8080096C: bne         $at, $zero, L_808009B8
    if (ctx->r1 != 0) {
        // 0x80800970: addiu       $t6, $a2, -0x90
        ctx->r14 = ADD32(ctx->r6, -0X90);
            goto L_808009B8;
    }
    // 0x80800970: addiu       $t6, $a2, -0x90
    ctx->r14 = ADD32(ctx->r6, -0X90);
    // 0x80800974: slti        $at, $a2, 0x41
    ctx->r1 = SIGNED(ctx->r6) < 0X41 ? 1 : 0;
    // 0x80800978: bne         $at, $zero, L_8080099C
    if (ctx->r1 != 0) {
        // 0x8080097C: sltiu       $at, $t6, 0x10
        ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
            goto L_8080099C;
    }
    // 0x8080097C: sltiu       $at, $t6, 0x10
    ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
    // 0x80800980: beq         $at, $zero, L_808009B0
    if (ctx->r1 == 0) {
        // 0x80800984: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808009B0;
    }
    // 0x80800984: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800988: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X2468) << 16);
    // 0x8080098C: addu        $at, $at, $t6
    gpr jr_addend_80800994 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800990: lw          $t6, 0x2468($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1312, 0X2468));
    // 0x80800994: jr          $t6
    // 0x80800998: nop

    switch (jr_addend_80800994 >> 2) {
        case 0: goto L_80800AA4; break;
        case 1: goto L_808009B0; break;
        case 2: goto L_808009B0; break;
        case 3: goto L_808009B0; break;
        case 4: goto L_808009B0; break;
        case 5: goto L_80800B4C; break;
        case 6: goto L_80800AD0; break;
        case 7: goto L_808009B0; break;
        case 8: goto L_808009B0; break;
        case 9: goto L_808009B0; break;
        case 10: goto L_808009B0; break;
        case 11: goto L_808009B0; break;
        case 12: goto L_80800B3C; break;
        case 13: goto L_808009B0; break;
        case 14: goto L_808009B0; break;
        case 15: goto L_80800B08; break;
        default: switch_error(__func__, 0x80800994, 0x80802468);
    }
    // 0x80800998: nop

L_8080099C:
    // 0x8080099C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808009A0: beq         $a2, $at, L_80800A34
    if (ctx->r6 == ctx->r1) {
        // 0x808009A4: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80800A34;
    }
    // 0x808009A4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808009A8: beq         $a2, $at, L_808009FC
    if (ctx->r6 == ctx->r1) {
        // 0x808009AC: addiu       $v0, $sp, 0x38
        ctx->r2 = ADD32(ctx->r29, 0X38);
            goto L_808009FC;
    }
    // 0x808009AC: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
L_808009B0:
    // 0x808009B0: b           L_80800B60
    // 0x808009B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B60;
    // 0x808009B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009B8:
    // 0x808009B8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808009BC: beq         $a2, $at, L_80800A10
    if (ctx->r6 == ctx->r1) {
        // 0x808009C0: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80800A10;
    }
    // 0x808009C0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x808009C4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x808009C8: beq         $a2, $at, L_808009E4
    if (ctx->r6 == ctx->r1) {
        // 0x808009CC: addiu       $v0, $sp, 0x38
        ctx->r2 = ADD32(ctx->r29, 0X38);
            goto L_808009E4;
    }
    // 0x808009CC: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x808009D0: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808009D4: beq         $a2, $at, L_80800AB4
    if (ctx->r6 == ctx->r1) {
        // 0x808009D8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80800AB4;
    }
    // 0x808009D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x808009DC: b           L_80800B60
    // 0x808009E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B60;
    // 0x808009E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009E4:
    // 0x808009E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009E8: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808009EC: jal         0x808010A0
    // 0x808009F0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_808010A0_chstatueboss(rdram, ctx);
        goto after_1;
    // 0x808009F0: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x808009F4: b           L_80800B60
    // 0x808009F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B60;
    // 0x808009F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009FC:
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A00: jal         0x80801518
    // 0x80800A04: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    func_80801518_chstatueboss(rdram, ctx);
        goto after_2;
    // 0x80800A04: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    after_2:
    // 0x80800A08: b           L_80800B60
    // 0x80800A0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B60;
    // 0x80800A0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A10:
    // 0x80800A10: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80800A14: bne         $t7, $at, L_80800A2C
    if (ctx->r15 != ctx->r1) {
        // 0x80800A18: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A2C;
    }
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A1C: jal         0x80800DA8
    // 0x80800A20: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_3;
    // 0x80800A20: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x80800A24: b           L_80800B60
    // 0x80800A28: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800B60;
    // 0x80800A28: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800A2C:
    // 0x80800A2C: b           L_80800B60
    // 0x80800A30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800B60;
    // 0x80800A30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800A34:
    // 0x80800A34: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80800A38: beq         $at, $zero, L_80800B5C
    if (ctx->r1 == 0) {
        // 0x80800A3C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800B5C;
    }
    // 0x80800A3C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800A40: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1312, 0X24A8) << 16);
    // 0x80800A44: addu        $at, $at, $t8
    gpr jr_addend_80800A4C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800A48: lw          $t8, 0x24A8($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1312, 0X24A8));
    // 0x80800A4C: jr          $t8
    // 0x80800A50: nop

    switch (jr_addend_80800A4C >> 2) {
        case 0: goto L_80800A54; break;
        case 1: goto L_80800A64; break;
        case 2: goto L_80800A74; break;
        case 3: goto L_80800A84; break;
        case 4: goto L_80800A94; break;
        default: switch_error(__func__, 0x80800A4C, 0x808024A8);
    }
    // 0x80800A50: nop

L_80800A54:
    // 0x80800A54: jal         0x80801ECC
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801ECC_chstatueboss(rdram, ctx);
        goto after_4;
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800A5C: b           L_80800B60
    // 0x80800A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B60;
    // 0x80800A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A64:
    // 0x80800A64: jal         0x80802144
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802144_chstatueboss(rdram, ctx);
        goto after_5;
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800A6C: b           L_80800B60
    // 0x80800A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B60;
    // 0x80800A70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A74:
    // 0x80800A74: jal         0x80801F74
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801F74_chstatueboss(rdram, ctx);
        goto after_6;
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800A7C: b           L_80800B60
    // 0x80800A80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B60;
    // 0x80800A80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A84:
    // 0x80800A84: jal         0x808020EC
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808020EC_chstatueboss(rdram, ctx);
        goto after_7;
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800A8C: b           L_80800B60
    // 0x80800A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B60;
    // 0x80800A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A94:
    // 0x80800A94: jal         0x80802268
    // 0x80800A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802268_chstatueboss(rdram, ctx);
        goto after_8;
    // 0x80800A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800A9C: b           L_80800B60
    // 0x80800AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B60;
    // 0x80800AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AA4:
    // 0x80800AA4: jal         0x80801CA0
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CA0_chstatueboss(rdram, ctx);
        goto after_9;
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800AAC: b           L_80800B60
    // 0x80800AB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B60;
    // 0x80800AB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AB4:
    // 0x80800AB4: jal         0x800F54E4
    // 0x80800AB8: sb          $t9, 0x1CE($v1)
    MEM_B(0X1CE, ctx->r3) = ctx->r25;
    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80800AB8: sb          $t9, 0x1CE($v1)
    MEM_B(0X1CE, ctx->r3) = ctx->r25;
    after_10:
    // 0x80800ABC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800AC0: jal         0x800F82D4
    // 0x80800AC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_11;
    // 0x80800AC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80800AC8: b           L_80800B60
    // 0x80800ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B60;
    // 0x80800ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AD0:
    // 0x80800AD0: jal         0x800D395C
    // 0x80800AD4: nop

    func_800D395C(rdram, ctx);
        goto after_12;
    // 0x80800AD4: nop

    after_12:
    // 0x80800AD8: bne         $v0, $zero, L_80800AE8
    if (ctx->r2 != 0) {
        // 0x80800ADC: addiu       $a1, $zero, 0xCEB
        ctx->r5 = ADD32(0, 0XCEB);
            goto L_80800AE8;
    }
    // 0x80800ADC: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80800AE0: b           L_80800B60
    // 0x80800AE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B60;
    // 0x80800AE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800AE8:
    // 0x80800AE8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800AEC: addiu       $t0, $zero, 0xB2
    ctx->r8 = ADD32(0, 0XB2);
    // 0x80800AF0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800AF4: addiu       $a2, $zero, 0x146
    ctx->r6 = ADD32(0, 0X146);
    // 0x80800AF8: jal         0x8008A208
    // 0x80800AFC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80800AFC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x80800B00: b           L_80800B60
    // 0x80800B04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B60;
    // 0x80800B04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B08:
    // 0x80800B08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B0C: jal         0x800FDC28
    // 0x80800B10: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800FDC28(rdram, ctx);
        goto after_14;
    // 0x80800B10: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_14:
    // 0x80800B14: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B18: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1312, 0X27C0) << 16);
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B20: lh          $t1, 0x84($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X84);
    // 0x80800B24: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80800B28: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x80800B2C: jal         0x80800DA8
    // 0x80800B30: lh          $a1, 0x27C0($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1312, 0X27C0));
    func_80800DA8_chstatueboss(rdram, ctx);
        goto after_15;
    // 0x80800B30: lh          $a1, 0x27C0($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1312, 0X27C0));
    after_15:
    // 0x80800B34: b           L_80800B60
    // 0x80800B38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B60;
    // 0x80800B38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B3C:
    // 0x80800B3C: jal         0x80801320
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801320_chstatueboss(rdram, ctx);
        goto after_16;
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800B44: b           L_80800B60
    // 0x80800B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B60;
    // 0x80800B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B4C:
    // 0x80800B4C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800B50: addiu       $a1, $a1, 0x6530
    ctx->r5 = ADD32(ctx->r5, 0X6530);
    // 0x80800B54: jal         0x80089FF0
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiecustomhits_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_80800B5C:
    // 0x80800B5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B60:
    // 0x80800B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B64: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800B6C: jr          $ra
    // 0x80800B70: nop

    return;
    // 0x80800B70: nop

;}
RECOMP_FUNC void func_80801A04_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801A10: jal         0x80801680
    // 0x80801A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801680_bsbansack(rdram, ctx);
        goto after_0;
    // 0x80801A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801A18: jal         0x80800238
    // 0x80801A1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800238_bsbansack(rdram, ctx);
        goto after_1;
    // 0x80801A1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A28: jr          $ra
    // 0x80801A2C: nop

    return;
    // 0x80801A2C: nop

;}
RECOMP_FUNC void suflamefx_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808002E0: jr          $ra
    // 0x808002E4: sb          $t6, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r14;
    return;
    // 0x808002E4: sb          $t6, 0x1C($a0)
    MEM_B(0X1C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void chtnthut_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(908, 0X220) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x220
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(908, 0X220));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x220
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(908, 0X220));
;}
RECOMP_FUNC void _ncstart_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089438: syscall     778
    recomp_syscall_handler(rdram, ctx, 0x80089438);
    return;
    // 0x8008943C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_80800074_babuzz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080007C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800080: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80800084: jal         0x800D8FF8
    // 0x80800088: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800088: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8080008C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800090: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800094: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080009C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x808000A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000A4: bc1f        L_808000CC
    if (!c1cs) {
        // 0x808000A8: nop
    
            goto L_808000CC;
    }
    // 0x808000A8: nop

    // 0x808000AC: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808000B0: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x808000B4: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x808000B8: nop

    // 0x808000BC: bc1f        L_808000E8
    if (!c1cs) {
        // 0x808000C0: nop
    
            goto L_808000E8;
    }
    // 0x808000C0: nop

    // 0x808000C4: b           L_808000E8
    // 0x808000C8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_808000E8;
    // 0x808000C8: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_808000CC:
    // 0x808000CC: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x808000D0: sub.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x808000D4: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x808000D8: nop

    // 0x808000DC: bc1f        L_808000E8
    if (!c1cs) {
        // 0x808000E0: nop
    
            goto L_808000E8;
    }
    // 0x808000E0: nop

    // 0x808000E4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_808000E8:
    // 0x808000E8: jr          $ra
    // 0x808000EC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x808000EC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void func_808008EC_chspotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808008F8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808008FC: addiu       $a1, $zero, 0x13C
    ctx->r5 = ADD32(0, 0X13C);
    // 0x80800900: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800904: jal         0x80089C20
    // 0x80800908: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800908: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8080090C: beq         $v0, $zero, L_80800920
    if (ctx->r2 == 0) {
        // 0x80800910: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800920;
    }
    // 0x80800910: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800914: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800918: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8080091C: sw          $t6, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = ctx->r14;
L_80800920:
    // 0x80800920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800928: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080092C: jr          $ra
    // 0x80800930: nop

    return;
    // 0x80800930: nop

;}
RECOMP_FUNC void _bskazflamethrower_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083368: syscall     56
    recomp_syscall_handler(rdram, ctx, 0x80083368);
    return;
    // 0x8008336C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080083C_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080083C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800844: jal         0x800839B8
    // 0x80800848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080084C: jal         0x80800174
    // 0x80800850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800174_bsvanswim(rdram, ctx);
        goto after_1;
    // 0x80800850: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080085C: jr          $ra
    // 0x80800860: nop

    return;
    // 0x80800860: nop

;}
RECOMP_FUNC void func_808008C0_chflamer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808008CC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808008D0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808008D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808008D8: jal         0x80100094
    // 0x808008DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008E0: lh          $t6, 0x16($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X16);
    // 0x808008E4: lh          $t7, 0x18($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X18);
    // 0x808008E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808008EC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x808008F0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808008F4: beql        $at, $zero, L_8080097C
    if (ctx->r1 == 0) {
        // 0x808008F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080097C;
    }
    goto skip_0;
    // 0x808008F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808008FC: lh          $t8, 0x16($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X16);
    // 0x80800900: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800904: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80800908: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8080090C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80800910: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800914: addu        $s0, $v0, $t9
    ctx->r16 = ADD32(ctx->r2, ctx->r25);
    // 0x80800918: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x8080091C: jal         0x800DC128
    // 0x80800920: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    func_800DC128(rdram, ctx);
        goto after_1;
    // 0x80800920: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80800924: sh          $v0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r2;
    // 0x80800928: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1088, 0XB14) << 16);
    // 0x8080092C: lwc1        $f12, 0xB14($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1088, 0XB14));
    // 0x80800930: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1088, 0XB18) << 16);
    // 0x80800934: jal         0x800DC178
    // 0x80800938: lwc1        $f14, 0xB18($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1088, 0XB18));
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800938: lwc1        $f14, 0xB18($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1088, 0XB18));
    after_2:
    // 0x8080093C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800940: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800944: jal         0x800DC298
    // 0x80800948: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    func_800DC298(rdram, ctx);
        goto after_3;
    // 0x80800948: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x8080094C: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x80800950: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800954: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800958: jal         0x800EF3DC
    // 0x8080095C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF3DC(rdram, ctx);
        goto after_4;
    // 0x8080095C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x80800960: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80800964: jal         0x800EE940
    // 0x80800968: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE940(rdram, ctx);
        goto after_5;
    // 0x80800968: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x8080096C: lh          $t0, 0x16($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X16);
    // 0x80800970: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80800974: sh          $t1, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r9;
    // 0x80800978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080097C:
    // 0x8080097C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800980: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800984: jr          $ra
    // 0x80800988: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800988: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void chmolehill_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080083C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800840: jal         0x80100094
    // 0x80800844: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800844: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800848: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8080084C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80800850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800854: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800858: jr          $ra
    // 0x8080085C: nop

    return;
    // 0x8080085C: nop

;}
RECOMP_FUNC void chbounce_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80800034: jr          $ra
    // 0x80800038: swc1        $f12, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x80800038: swc1        $f12, 0x7188($at)
    MEM_W(0X7188, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void _chfiregen_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A00: syscall     404
    recomp_syscall_handler(rdram, ctx, 0x80086A00);
    return;
    // 0x80086A04: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _bstrexsmall_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084080: syscall     102
    recomp_syscall_handler(rdram, ctx, 0x80084080);
    return;
    // 0x80084084: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _ncbaspline_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800893B0: syscall     776
    recomp_syscall_handler(rdram, ctx, 0x800893B0);
    return;
    // 0x800893B4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void chwallsnakebaddy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800670: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1856, 0X7B4) << 16);
    // 0x80800674: jr          $ra
    // 0x80800678: addiu       $v0, $v0, 0x7B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1856, 0X7B4));
    return;
    // 0x80800678: addiu       $v0, $v0, 0x7B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1856, 0X7B4));
    // 0x8080067C: nop

;}
RECOMP_FUNC void gccollectDll_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800958: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080095C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800960: lbu         $t6, 0x762C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X762C);
    // 0x80800964: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800968: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080096C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800970: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800974: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800978: jal         0x800CF87C
    // 0x8080097C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    func_800CF87C(rdram, ctx);
        goto after_0;
    // 0x8080097C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800980: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800984: beql        $v0, $at, L_80800B64
    if (ctx->r2 == ctx->r1) {
        // 0x80800988: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B64;
    }
    goto skip_0;
    // 0x80800988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080098C: beql        $s0, $zero, L_80800B64
    if (ctx->r16 == 0) {
        // 0x80800990: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B64;
    }
    goto skip_1;
    // 0x80800990: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800994: jal         0x800E9DC4
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9DC4(rdram, ctx);
        goto after_1;
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080099C: beql        $v0, $zero, L_80800B64
    if (ctx->r2 == 0) {
        // 0x808009A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800B64;
    }
    goto skip_2;
    // 0x808009A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x808009A4: jal         0x800E9D68
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9D68(rdram, ctx);
        goto after_2;
    // 0x808009A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808009AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808009B0: jal         0x800E9D90
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9D90(rdram, ctx);
        goto after_3;
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808009B8: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x808009BC: beq         $at, $zero, L_80800B60
    if (ctx->r1 == 0) {
        // 0x808009C0: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_80800B60;
    }
    // 0x808009C0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808009C4: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
L_808009C8:
    // 0x808009C8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808009CC: sll         $t8, $t7, 25
    ctx->r24 = S32(ctx->r15 << 25);
    // 0x808009D0: srl         $t9, $t8, 26
    ctx->r25 = S32(U32(ctx->r24) >> 26);
    // 0x808009D4: bnel        $t9, $at, L_80800B50
    if (ctx->r25 != ctx->r1) {
        // 0x808009D8: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_80800B50;
    }
    goto skip_3;
    // 0x808009D8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x808009DC: lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X8);
    // 0x808009E0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808009E4: sltiu       $at, $v0, 0x29E
    ctx->r1 = ctx->r2 < 0X29E ? 1 : 0;
    // 0x808009E8: bne         $at, $zero, L_80800A00
    if (ctx->r1 != 0) {
        // 0x808009EC: addiu       $at, $zero, 0x4E6
        ctx->r1 = ADD32(0, 0X4E6);
            goto L_80800A00;
    }
    // 0x808009EC: addiu       $at, $zero, 0x4E6
    ctx->r1 = ADD32(0, 0X4E6);
    // 0x808009F0: beql        $v0, $at, L_80800A74
    if (ctx->r2 == ctx->r1) {
        // 0x808009F4: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_80800A74;
    }
    goto skip_4;
    // 0x808009F4: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    skip_4:
    // 0x808009F8: b           L_80800B50
    // 0x808009FC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B50;
    // 0x808009FC: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_80800A00:
    // 0x80800A00: sltiu       $at, $v0, 0x202
    ctx->r1 = ctx->r2 < 0X202 ? 1 : 0;
    // 0x80800A04: bne         $at, $zero, L_80800A20
    if (ctx->r1 != 0) {
        // 0x80800A08: addiu       $t0, $v0, -0x1F5
        ctx->r8 = ADD32(ctx->r2, -0X1F5);
            goto L_80800A20;
    }
    // 0x80800A08: addiu       $t0, $v0, -0x1F5
    ctx->r8 = ADD32(ctx->r2, -0X1F5);
    // 0x80800A0C: addiu       $at, $zero, 0x29D
    ctx->r1 = ADD32(0, 0X29D);
    // 0x80800A10: beq         $v0, $at, L_80800A68
    if (ctx->r2 == ctx->r1) {
        // 0x80800A14: nop
    
            goto L_80800A68;
    }
    // 0x80800A14: nop

    // 0x80800A18: b           L_80800B50
    // 0x80800A1C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B50;
    // 0x80800A1C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_80800A20:
    // 0x80800A20: sltiu       $at, $t0, 0xD
    ctx->r1 = ctx->r8 < 0XD ? 1 : 0;
    // 0x80800A24: beq         $at, $zero, L_80800B4C
    if (ctx->r1 == 0) {
        // 0x80800A28: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800B4C;
    }
    // 0x80800A28: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800A2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2626, 0XB80) << 16);
    // 0x80800A30: addu        $at, $at, $t0
    gpr jr_addend_80800A38 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800A34: lw          $t0, 0xB80($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2626, 0XB80));
    // 0x80800A38: jr          $t0
    // 0x80800A3C: nop

    switch (jr_addend_80800A38 >> 2) {
        case 0: goto L_80800A40; break;
        case 1: goto L_80800A48; break;
        case 2: goto L_80800A50; break;
        case 3: goto L_80800A58; break;
        case 4: goto L_80800B4C; break;
        case 5: goto L_80800B4C; break;
        case 6: goto L_80800B4C; break;
        case 7: goto L_80800B4C; break;
        case 8: goto L_80800B4C; break;
        case 9: goto L_80800B4C; break;
        case 10: goto L_80800B4C; break;
        case 11: goto L_80800B4C; break;
        case 12: goto L_80800A60; break;
        default: switch_error(__func__, 0x80800A38, 0x80800B80);
    }
    // 0x80800A3C: nop

L_80800A40:
    // 0x80800A40: b           L_80800A74
    // 0x80800A44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80800A74;
    // 0x80800A44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800A48:
    // 0x80800A48: b           L_80800A74
    // 0x80800A4C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80800A74;
    // 0x80800A4C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80800A50:
    // 0x80800A50: b           L_80800A74
    // 0x80800A54: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_80800A74;
    // 0x80800A54: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_80800A58:
    // 0x80800A58: b           L_80800A74
    // 0x80800A5C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80800A74;
    // 0x80800A5C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80800A60:
    // 0x80800A60: b           L_80800A74
    // 0x80800A64: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_80800A74;
    // 0x80800A64: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_80800A68:
    // 0x80800A68: b           L_80800A74
    // 0x80800A6C: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
        goto L_80800A74;
    // 0x80800A6C: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x80800A70: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
L_80800A74:
    // 0x80800A74: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80800A78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800A7C: srl         $t1, $a0, 23
    ctx->r9 = S32(U32(ctx->r4) >> 23);
    // 0x80800A80: jal         0x800CFFBC
    // 0x80800A84: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    func_800CFFBC(rdram, ctx);
        goto after_4;
    // 0x80800A84: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_4:
    // 0x80800A88: beql        $v0, $zero, L_80800B50
    if (ctx->r2 == 0) {
        // 0x80800A8C: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_80800B50;
    }
    goto skip_5;
    // 0x80800A8C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x80800A90: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80800A94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800A98: srl         $t2, $a0, 23
    ctx->r10 = S32(U32(ctx->r4) >> 23);
    // 0x80800A9C: jal         0x800D06D4
    // 0x80800AA0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800D06D4(rdram, ctx);
        goto after_5;
    // 0x80800AA0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_5:
    // 0x80800AA4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80800AA8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800AAC: beql        $v0, $t3, L_80800ABC
    if (ctx->r2 == ctx->r11) {
        // 0x80800AB0: sltiu       $at, $s0, 0x9
        ctx->r1 = ctx->r16 < 0X9 ? 1 : 0;
            goto L_80800ABC;
    }
    goto skip_6;
    // 0x80800AB0: sltiu       $at, $s0, 0x9
    ctx->r1 = ctx->r16 < 0X9 ? 1 : 0;
    skip_6:
    // 0x80800AB4: bne         $v0, $at, L_80800B4C
    if (ctx->r2 != ctx->r1) {
        // 0x80800AB8: sltiu       $at, $s0, 0x9
        ctx->r1 = ctx->r16 < 0X9 ? 1 : 0;
            goto L_80800B4C;
    }
    // 0x80800AB8: sltiu       $at, $s0, 0x9
    ctx->r1 = ctx->r16 < 0X9 ? 1 : 0;
L_80800ABC:
    // 0x80800ABC: beq         $at, $zero, L_80800B2C
    if (ctx->r1 == 0) {
        // 0x80800AC0: sll         $t4, $s0, 2
        ctx->r12 = S32(ctx->r16 << 2);
            goto L_80800B2C;
    }
    // 0x80800AC0: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80800AC4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2626, 0XBB4) << 16);
    // 0x80800AC8: addu        $at, $at, $t4
    gpr jr_addend_80800AD0 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80800ACC: lw          $t4, 0xBB4($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2626, 0XBB4));
    // 0x80800AD0: jr          $t4
    // 0x80800AD4: nop

    switch (jr_addend_80800AD0 >> 2) {
        case 0: goto L_80800B1C; break;
        case 1: goto L_80800AD8; break;
        case 2: goto L_80800B1C; break;
        case 3: goto L_80800AE8; break;
        case 4: goto L_80800B1C; break;
        case 5: goto L_80800B2C; break;
        case 6: goto L_80800B2C; break;
        case 7: goto L_80800B1C; break;
        case 8: goto L_80800B1C; break;
        default: switch_error(__func__, 0x80800AD0, 0x80800BB4);
    }
    // 0x80800AD4: nop

L_80800AD8:
    // 0x80800AD8: jal         0x808007D8
    // 0x80800ADC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808007D8_gccollectDll(rdram, ctx);
        goto after_6;
    // 0x80800ADC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80800AE0: b           L_80800B2C
    // 0x80800AE4: nop

        goto L_80800B2C;
    // 0x80800AE4: nop

L_80800AE8:
    // 0x80800AE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AEC: jal         0x80800890
    // 0x80800AF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800890_gccollectDll(rdram, ctx);
        goto after_7;
    // 0x80800AF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80800AF4: beq         $v0, $zero, L_80800B2C
    if (ctx->r2 == 0) {
        // 0x80800AF8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80800B2C;
    }
    // 0x80800AF8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800AFC: lhu         $t5, 0x6($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X6);
    // 0x80800B00: lhu         $t9, 0x76($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X76);
    // 0x80800B04: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x80800B08: sll         $t8, $t6, 7
    ctx->r24 = S32(ctx->r14 << 7);
    // 0x80800B0C: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x80800B10: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800B14: b           L_80800B2C
    // 0x80800B18: sh          $t1, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r9;
        goto L_80800B2C;
    // 0x80800B18: sh          $t1, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r9;
L_80800B1C:
    // 0x80800B1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800B20: jal         0x80800890
    // 0x80800B24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800890_gccollectDll(rdram, ctx);
        goto after_8;
    // 0x80800B24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80800B28: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80800B2C:
    // 0x80800B2C: beq         $s2, $zero, L_80800B4C
    if (ctx->r18 == 0) {
        // 0x80800B30: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80800B4C;
    }
    // 0x80800B30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B34: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80800B38: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800B3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800B40: srl         $t2, $a1, 23
    ctx->r10 = S32(U32(ctx->r5) >> 23);
    // 0x80800B44: jal         0x800CFBC8
    // 0x80800B48: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_800CFBC8(rdram, ctx);
        goto after_9;
    // 0x80800B48: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_9:
L_80800B4C:
    // 0x80800B4C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_80800B50:
    // 0x80800B50: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x80800B54: sltu        $at, $s1, $t3
    ctx->r1 = ctx->r17 < ctx->r11 ? 1 : 0;
    // 0x80800B58: bnel        $at, $zero, L_808009C8
    if (ctx->r1 != 0) {
        // 0x80800B5C: lw          $t7, 0x4($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X4);
            goto L_808009C8;
    }
    goto skip_7;
    // 0x80800B5C: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    skip_7:
L_80800B60:
    // 0x80800B60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B64:
    // 0x80800B64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B68: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B6C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800B70: jr          $ra
    // 0x80800B74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800B74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void chbaddiesetup_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808001E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808001E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808001EC: jal         0x800A5D60
    // 0x808001F0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800A5D60(rdram, ctx);
        goto after_0;
    // 0x808001F0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808001F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001F8: jal         0x80800000
    // 0x808001FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800000_chbaddiesetup(rdram, ctx);
        goto after_1;
    // 0x808001FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800200: beq         $v0, $zero, L_8080028C
    if (ctx->r2 == 0) {
        // 0x80800204: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8080028C;
    }
    // 0x80800204: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800208: lbu         $t8, 0x4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X4);
    // 0x8080020C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800210: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800214: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x80800218: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8080021C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80800220: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    // 0x80800224: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80800228: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8080022C: sll         $t4, $t3, 5
    ctx->r12 = S32(ctx->r11 << 5);
    // 0x80800230: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80800234: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x80800238: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x8080023C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800240: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80800244: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x80800248: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x8080024C: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x80800250: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    // 0x80800254: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80800258: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8080025C: sll         $t1, $t4, 5
    ctx->r9 = S32(ctx->r12 << 5);
    // 0x80800260: addu        $t5, $t2, $t1
    ctx->r13 = ADD32(ctx->r10, ctx->r9);
    // 0x80800264: sw          $t3, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r11;
    // 0x80800268: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x8080026C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800270: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80800274: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x80800278: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8080027C: sw          $t9, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r25;
    // 0x80800280: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    // 0x80800284: addiu       $t2, $t4, 0x1
    ctx->r10 = ADD32(ctx->r12, 0X1);
    // 0x80800288: sb          $t2, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r10;
L_8080028C:
    // 0x8080028C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800290: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800294: jr          $ra
    // 0x80800298: nop

    return;
    // 0x80800298: nop

;}
RECOMP_FUNC void _bskazmove_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834F0: syscall     63
    recomp_syscall_handler(rdram, ctx, 0x800834F0);
    return;
    // 0x800834F4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800A93E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A93E4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800A93E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A93EC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800A93F0: jr          $ra
    // 0x800A93F4: lw          $v0, 0x7728($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7728);
    return;
    // 0x800A93F4: lw          $v0, 0x7728($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7728);
;}
RECOMP_FUNC void func_80807A10_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80807A10: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80807A14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80807A18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80807A1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80807A20: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80807A24: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80807A28: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80807A2C: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80807A30: jal         0x800E39A8
    // 0x80807A34: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    func_800E39A8(rdram, ctx);
        goto after_0;
    // 0x80807A34: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    after_0:
    // 0x80807A38: jal         0x800A5800
    // 0x80807A3C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    func_800A5800(rdram, ctx);
        goto after_1;
    // 0x80807A3C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    after_1:
    // 0x80807A40: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80807A44: jal         0x80085580
    // 0x80807A48: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80807A48: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x80807A4C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80807A50: jal         0x80085590
    // 0x80807A54: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    _cadbfunc_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80807A54: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_3:
    // 0x80807A58: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80807A5C: jal         0x800EEAD4
    // 0x80807A60: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EEAD4(rdram, ctx);
        goto after_4;
    // 0x80807A60: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80807A64: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80807A68: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80807A6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80807A70: beql        $v0, $zero, L_80807AA0
    if (ctx->r2 == 0) {
        // 0x80807A74: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80807AA0;
    }
    goto skip_0;
    // 0x80807A74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x80807A78: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80807A7C: beq         $v0, $at, L_80807AD4
    if (ctx->r2 == ctx->r1) {
        // 0x80807A80: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80807AD4;
    }
    // 0x80807A80: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80807A84: beq         $v0, $at, L_80807B10
    if (ctx->r2 == ctx->r1) {
        // 0x80807A88: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80807B10;
    }
    // 0x80807A88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80807A8C: beql        $v0, $at, L_80807BB8
    if (ctx->r2 == ctx->r1) {
        // 0x80807A90: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80807BB8;
    }
    goto skip_1;
    // 0x80807A90: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_1:
    // 0x80807A94: b           L_80807BEC
    // 0x80807A98: nop

        goto L_80807BEC;
    // 0x80807A98: nop

    // 0x80807A9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80807AA0:
    // 0x80807AA0: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x80807AA4: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80807AA8: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80807AAC: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80807AB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80807AB4: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80807AB8: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80807ABC: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80807AC0: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x80807AC4: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
    // 0x80807AC8: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x80807ACC: b           L_80807BEC
    // 0x80807AD0: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_80807BEC;
    // 0x80807AD0: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80807AD4:
    // 0x80807AD4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80807AD8: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x80807ADC: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80807AE0: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    // 0x80807AE4: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80807AE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80807AEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80807AF0: andi        $t9, $t7, 0xFE00
    ctx->r25 = ctx->r15 & 0XFE00;
    // 0x80807AF4: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80807AF8: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80807AFC: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x80807B00: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
    // 0x80807B04: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80807B08: b           L_80807BEC
    // 0x80807B0C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
        goto L_80807BEC;
    // 0x80807B0C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_80807B10:
    // 0x80807B10: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80807B14: andi        $t2, $a0, 0x1FF
    ctx->r10 = ctx->r4 & 0X1FF;
    // 0x80807B18: jal         0x800A5800
    // 0x80807B1C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800A5800(rdram, ctx);
        goto after_5;
    // 0x80807B1C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_5:
    // 0x80807B20: jal         0x80085580
    // 0x80807B24: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    _cadbfunc_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80807B24: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x80807B28: jal         0x80085590
    // 0x80807B2C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    _cadbfunc_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80807B2C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x80807B30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80807B34: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80807B38: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80807B3C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80807B40: jal         0x800EFE50
    // 0x80807B44: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_800EFE50(rdram, ctx);
        goto after_8;
    // 0x80807B44: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_8:
    // 0x80807B48: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80807B4C: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x80807B50: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80807B54: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80807B58: jal         0x800F16AC
    // 0x80807B5C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_800F16AC(rdram, ctx);
        goto after_9;
    // 0x80807B5C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_9:
    // 0x80807B60: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80807B64: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80807B68: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7DA4) << 16);
    // 0x80807B6C: sll         $t5, $t3, 11
    ctx->r13 = S32(ctx->r11 << 11);
    // 0x80807B70: bgez        $t5, L_80807B9C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80807B74: swc1        $f16, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
            goto L_80807B9C;
    }
    // 0x80807B74: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x80807B78: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80807B7C: jal         0x800EEAD4
    // 0x80807B80: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EEAD4(rdram, ctx);
        goto after_10;
    // 0x80807B80: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x80807B84: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80807B88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80807B8C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80807B90: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80807B94: b           L_80807BA4
    // 0x80807B98: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_80807BA4;
    // 0x80807B98: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_80807B9C:
    // 0x80807B9C: lwc1        $f6, 0x7DA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7DA4));
    // 0x80807BA0: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80807BA4:
    // 0x80807BA4: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80807BA8: ori         $t9, $t6, 0x10
    ctx->r25 = ctx->r14 | 0X10;
    // 0x80807BAC: b           L_80807BEC
    // 0x80807BB0: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
        goto L_80807BEC;
    // 0x80807BB0: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x80807BB4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80807BB8:
    // 0x80807BB8: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x80807BBC: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80807BC0: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    // 0x80807BC4: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80807BC8: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80807BCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7DA8) << 16);
    // 0x80807BD0: andi        $t1, $t0, 0x1FF
    ctx->r9 = ctx->r8 & 0X1FF;
    // 0x80807BD4: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80807BD8: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
    // 0x80807BDC: lwc1        $f10, 0x7DA8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7DA8));
    // 0x80807BE0: andi        $t7, $t5, 0xFFEF
    ctx->r15 = ctx->r13 & 0XFFEF;
    // 0x80807BE4: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    // 0x80807BE8: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_80807BEC:
    // 0x80807BEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7DAC) << 16);
    // 0x80807BF0: lwc1        $f18, 0x7DAC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7DAC));
    // 0x80807BF4: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80807BF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80807BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80807C00: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80807C04: nop

    // 0x80807C08: bc1f        L_80807C20
    if (!c1cs) {
        // 0x80807C0C: nop
    
            goto L_80807C20;
    }
    // 0x80807C0C: nop

    // 0x80807C10: jal         0x80101FDC
    // 0x80807C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80807C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80807C18: b           L_80807C2C
    // 0x80807C1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80807C2C;
    // 0x80807C1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807C20:
    // 0x80807C20: jal         0x80101FDC
    // 0x80807C24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x80807C24: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x80807C28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80807C2C:
    // 0x80807C2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80807C30: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80807C34: jr          $ra
    // 0x80807C38: nop

    return;
    // 0x80807C38: nop

    // 0x80807C3C: nop

;}
RECOMP_FUNC void func_80110C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110C88: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80110C8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80110C90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80110C94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80110C98: lui         $a1, 0x4409
    ctx->r5 = S32(0X4409 << 16);
    // 0x80110C9C: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80110CA0: lui         $a2, 0x441B
    ctx->r6 = S32(0X441B << 16);
    // 0x80110CA4: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    // 0x80110CA8: jal         0x80110CC0
    // 0x80110CAC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80110CC0(rdram, ctx);
        goto after_0;
    // 0x80110CAC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80110CB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80110CB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80110CB8: jr          $ra
    // 0x80110CBC: nop

    return;
    // 0x80110CBC: nop

;}
RECOMP_FUNC void func_808002BC_chcablespark(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002C4: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    // 0x808002C8: beql        $a1, $zero, L_808002DC
    if (ctx->r5 == 0) {
        // 0x808002CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002DC;
    }
    goto skip_0;
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808002D0: jal         0x800E87E0
    // 0x808002D4: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    func_800E87E0(rdram, ctx);
        goto after_0;
    // 0x808002D4: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    after_0:
    // 0x808002D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002DC:
    // 0x808002DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002E0: jr          $ra
    // 0x808002E4: nop

    return;
    // 0x808002E4: nop

;}
RECOMP_FUNC void func_8080112C_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080112C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801130: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80801134: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80801138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080113C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801140: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80801144: jal         0x800EE7F8
    // 0x80801148: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80801148: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080114C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80801150: jal         0x800EE7F8
    // 0x80801154: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80801154: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x80801158: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080115C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801160: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80801164: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801168: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080116C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801170: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801174: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80801178: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080117C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80801180: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80801184: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80801188: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8080118C: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x80801190: jal         0x800BEF00
    // 0x80801194: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x80801194: lw          $a3, 0x14($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X14);
    after_2:
    // 0x80801198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080119C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808011A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808011A4: jr          $ra
    // 0x808011A8: nop

    return;
    // 0x808011A8: nop

;}
RECOMP_FUNC void bawasher_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080022C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800230: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80800234: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800238: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8080023C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800240: jal         0x800D8FF8
    // 0x80800244: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800244: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x80800248: lw          $v0, 0x14C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14C);
    // 0x8080024C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800250: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800254: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800258: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8080025C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800260: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800264: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800268: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x8080026C: lw          $v0, 0x14C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14C);
    // 0x80800270: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800274: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800278: jal         0x800F15F8
    // 0x8080027C: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    func_800F15F8(rdram, ctx);
        goto after_1;
    // 0x8080027C: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x80800280: lw          $t6, 0x14C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14C);
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800288: jal         0x80092AD8
    // 0x8080028C: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    func_80092AD8(rdram, ctx);
        goto after_2;
    // 0x8080028C: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    after_2:
    // 0x80800290: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800294: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800298: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080029C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002A0: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x808002A4: jal         0x800E0AF0
    // 0x808002A8: nop

    func_800E0AF0(rdram, ctx);
        goto after_3;
    // 0x808002A8: nop

    after_3:
    // 0x808002AC: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x808002B0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808002B4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808002B8: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x808002BC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808002C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002C4: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    // 0x808002C8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x808002CC: jal         0x800E0AFC
    // 0x808002D0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_4;
    // 0x808002D0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x808002D4: lw          $t8, 0x14C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14C);
    // 0x808002D8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808002DC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808002E0: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x808002E4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x808002E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002EC: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x808002F0: jal         0x800E0AFC
    // 0x808002F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_5;
    // 0x808002F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x808002F8: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
    // 0x808002FC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800300: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800304: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80800308: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8080030C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800310: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    // 0x80800314: jal         0x800E0AFC
    // 0x80800318: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_6;
    // 0x80800318: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x8080031C: lw          $t0, 0x14C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14C);
    // 0x80800320: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800324: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800328: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8080032C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800330: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800334: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x80800338: jal         0x800E0AFC
    // 0x8080033C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_7;
    // 0x8080033C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x80800340: lw          $t1, 0x14C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14C);
    // 0x80800344: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800348: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080034C: lw          $a3, 0x8($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8);
    // 0x80800350: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800354: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800358: jal         0x800E0AFC
    // 0x8080035C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    func_800E0AFC(rdram, ctx);
        goto after_8;
    // 0x8080035C: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_8:
    // 0x80800360: lw          $t2, 0x14C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14C);
    // 0x80800364: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080036C: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x80800370: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800374: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800378: jal         0x800E0AFC
    // 0x8080037C: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    func_800E0AFC(rdram, ctx);
        goto after_9;
    // 0x8080037C: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_9:
    // 0x80800380: lw          $t3, 0x14C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14C);
    // 0x80800384: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080038C: lw          $a3, 0x8($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X8);
    // 0x80800390: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80800394: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800398: jal         0x800E0AFC
    // 0x8080039C: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    func_800E0AFC(rdram, ctx);
        goto after_10;
    // 0x8080039C: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    after_10:
    // 0x808003A0: lw          $t4, 0x14C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14C);
    // 0x808003A4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808003A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003AC: lw          $a3, 0x8($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8);
    // 0x808003B0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x808003B4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x808003B8: jal         0x800E0AFC
    // 0x808003BC: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    func_800E0AFC(rdram, ctx);
        goto after_11;
    // 0x808003BC: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_11:
    // 0x808003C0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808003C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808003C8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808003CC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x808003D0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x808003D4: jr          $ra
    // 0x808003D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x808003D8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800995B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800995B0: jr          $ra
    // 0x800995B4: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
    return;
    // 0x800995B4: addiu       $v0, $zero, 0xF0
    ctx->r2 = ADD32(0, 0XF0);
;}
RECOMP_FUNC void _suegg_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A428: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A428);
    return;
    // 0x8008A42C: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void _bahold_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D40: syscall     134
    recomp_syscall_handler(rdram, ctx, 0x80084D40);
    return;
    // 0x80084D44: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void bamovespline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800204: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800208: lw          $v0, 0xC8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC8);
    // 0x8080020C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800210: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800214: lbu         $t6, 0x90($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X90);
    // 0x80800218: beql        $t6, $at, L_8080022C
    if (ctx->r14 == ctx->r1) {
        // 0x8080021C: lwc1        $f4, 0xA8($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0XA8);
            goto L_8080022C;
    }
    goto skip_0;
    // 0x8080021C: lwc1        $f4, 0xA8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XA8);
    skip_0:
    // 0x80800220: b           L_808002B0
    // 0x80800224: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002B0;
    // 0x80800224: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800228: lwc1        $f4, 0xA8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XA8);
L_8080022C:
    // 0x8080022C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800230: nop

    // 0x80800234: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800238: nop

    // 0x8080023C: bc1fl       L_80800250
    if (!c1cs) {
        // 0x80800240: lh          $a0, 0x94($v0)
        ctx->r4 = MEM_H(ctx->r2, 0X94);
            goto L_80800250;
    }
    goto skip_1;
    // 0x80800240: lh          $a0, 0x94($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X94);
    skip_1:
    // 0x80800244: b           L_808002B0
    // 0x80800248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002B0;
    // 0x80800248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080024C: lh          $a0, 0x94($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X94);
L_80800250:
    // 0x80800250: jal         0x800D7520
    // 0x80800254: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_800D7520(rdram, ctx);
        goto after_0;
    // 0x80800254: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800258: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8080025C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800264: lw          $t7, 0xC8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XC8);
    // 0x80800268: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8080026C: jal         0x800C7A68
    // 0x80800270: lw          $a1, 0x98($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X98);
    func_800C7A68(rdram, ctx);
        goto after_1;
    // 0x80800270: lw          $a1, 0x98($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X98);
    after_1:
    // 0x80800274: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800278: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080027C: jal         0x800C7A68
    // 0x80800280: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_800C7A68(rdram, ctx);
        goto after_2;
    // 0x80800280: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_2:
    // 0x80800284: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800288: jal         0x800EEB40
    // 0x8080028C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x8080028C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80800290: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800298: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8080029C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808002A0: nop

    // 0x808002A4: bc1fl       L_808002B4
    if (!c1cs) {
        // 0x808002A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808002B4;
    }
    goto skip_2;
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x808002AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002B0:
    // 0x808002B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002B4:
    // 0x808002B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808002B8: jr          $ra
    // 0x808002BC: nop

    return;
    // 0x808002BC: nop

;}
RECOMP_FUNC void func_808003C8_chklungophial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C8: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x808003CC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x808003D0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808003D4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808003D8: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x808003DC: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x808003E0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x808003E4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x808003E8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x808003EC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x808003F0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808003F4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808003F8: jal         0x80100094
    // 0x808003FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800400: addiu       $s3, $sp, 0x94
    ctx->r19 = ADD32(ctx->r29, 0X94);
    // 0x80800404: sw          $v0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r2;
    // 0x80800408: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080040C: jal         0x80103DFC
    // 0x80800410: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80103DFC(rdram, ctx);
        goto after_1;
    // 0x80800410: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x80800414: addiu       $s0, $sp, 0x88
    ctx->r16 = ADD32(ctx->r29, 0X88);
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: jal         0x800EE7F8
    // 0x80800420: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800420: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x80800424: addiu       $a0, $s5, 0x4
    ctx->r4 = ADD32(ctx->r21, 0X4);
    // 0x80800428: jal         0x800F1DF4
    // 0x8080042C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    func_800F1DF4(rdram, ctx);
        goto after_3;
    // 0x8080042C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    after_3:
    // 0x80800430: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800434: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800438: lwc1        $f4, 0x38($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X38);
    // 0x8080043C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800444: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800448: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8080044C: jal         0x800EF1B8
    // 0x80800450: nop

    func_800EF1B8(rdram, ctx);
        goto after_4;
    // 0x80800450: nop

    after_4:
    // 0x80800454: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800458: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080045C: lwc1        $f10, 0x38($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X38);
    // 0x80800460: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80800464: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1244, 0XCDC) << 16);
    // 0x80800468: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080046C: addiu       $t6, $t6, 0xCDC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1244, 0XCDC));
    // 0x80800470: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800474: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800478: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8080047C: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80800480: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x80800484: lw          $a2, 0x38($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X38);
    // 0x80800488: jal         0x800BBCB8
    // 0x8080048C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x8080048C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_5:
    // 0x80800490: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1244, 0XD18) << 16);
    // 0x80800494: addiu       $a2, $a2, 0xD18
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1244, 0XD18));
    // 0x80800498: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080049C: jal         0x80089D18
    // 0x808004A0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x808004A0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
    // 0x808004A4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1244, 0XD50) << 16);
    // 0x808004A8: addiu       $a2, $a2, 0xD50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1244, 0XD50));
    // 0x808004AC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808004B0: jal         0x80089D18
    // 0x808004B4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x808004B4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x808004B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808004BC: bne         $s1, $at, L_80800638
    if (ctx->r17 != ctx->r1) {
        // 0x808004C0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800638;
    }
    // 0x808004C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808004C4: addiu       $a0, $zero, 0x423
    ctx->r4 = ADD32(0, 0X423);
    // 0x808004C8: jal         0x80089C30
    // 0x808004CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808004CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808004D0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808004D4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808004D8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808004DC: jal         0x808006B4
    // 0x808004E0: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    func_808006B4_chklungophial(rdram, ctx);
        goto after_9;
    // 0x808004E0: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    after_9:
    // 0x808004E4: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x808004E8: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80800570;
    }
    // 0x808004E8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808004EC: lwc1        $f8, 0x38($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X38);
    // 0x808004F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808004F4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1244, 0XD6C) << 16);
    // 0x808004F8: addiu       $t7, $t7, 0xD6C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1244, 0XD6C));
    // 0x808004FC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800500: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800504: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800508: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8080050C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800510: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800514: jal         0x800BABB8
    // 0x80800518: nop

    func_800BABB8(rdram, ctx);
        goto after_10;
    // 0x80800518: nop

    after_10:
    // 0x8080051C: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800520: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80800524: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80800528: trunc.w.s   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080052C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800530: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800534: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800538: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080053C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800540: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800544: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x80800548: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8080054C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80800550: sll         $t2, $a2, 16
    ctx->r10 = S32(ctx->r6 << 16);
    // 0x80800554: sra         $a2, $t2, 16
    ctx->r6 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80800558: sll         $t5, $a3, 16
    ctx->r13 = S32(ctx->r7 << 16);
    // 0x8080055C: jal         0x800BA77C
    // 0x80800560: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    func_800BA77C(rdram, ctx);
        goto after_11;
    // 0x80800560: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    after_11:
    // 0x80800564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800568: jal         0x800BA22C
    // 0x8080056C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_12;
    // 0x8080056C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
L_80800570:
    // 0x80800570: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1244, 0XD90) << 16);
    // 0x80800574: addiu       $t7, $t7, 0xD90
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1244, 0XD90));
    // 0x80800578: lw          $a3, 0x38($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X38);
    // 0x8080057C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800580: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800584: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800588: jal         0x800BABB8
    // 0x8080058C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_13;
    // 0x8080058C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80800590: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1244, 0XDCC) << 16);
    // 0x80800594: addiu       $a2, $a2, 0xDCC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1244, 0XDCC));
    // 0x80800598: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080059C: jal         0x80089D18
    // 0x808005A0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x808005A0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_14:
    // 0x808005A4: beq         $s4, $zero, L_80800654
    if (ctx->r20 == 0) {
        // 0x808005A8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1244, 0XBF8) << 16);
            goto L_80800654;
    }
    // 0x808005A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XBF8) << 16);
    // 0x808005AC: lwc1        $f20, 0xBF8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XBF8));
    // 0x808005B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808005B4: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x808005B8: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
L_808005BC:
    // 0x808005BC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808005C0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XBFC) << 16);
    // 0x808005C4: jal         0x800DC178
    // 0x808005C8: lwc1        $f14, 0xBFC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XBFC));
    func_800DC178(rdram, ctx);
        goto after_15;
    // 0x808005C8: lwc1        $f14, 0xBFC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XBFC));
    after_15:
    // 0x808005CC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808005D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808005D4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808005D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808005DC: jal         0x800DC178
    // 0x808005E0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_16;
    // 0x808005E0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_16:
    // 0x808005E4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x808005E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808005EC: jal         0x800EEB9C
    // 0x808005F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEB9C(rdram, ctx);
        goto after_17;
    // 0x808005F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x808005F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808005F8: jal         0x800EF04C
    // 0x808005FC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EF04C(rdram, ctx);
        goto after_18;
    // 0x808005FC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_18:
    // 0x80800600: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800604: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800608: jal         0x80800AEC
    // 0x8080060C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800AEC_chklungophial(rdram, ctx);
        goto after_19;
    // 0x8080060C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_19:
    // 0x80800610: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC00) << 16);
    // 0x80800614: lwc1        $f12, 0xC00($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC00));
    // 0x80800618: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC04) << 16);
    // 0x8080061C: jal         0x800DC178
    // 0x80800620: lwc1        $f14, 0xC04($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC04));
    func_800DC178(rdram, ctx);
        goto after_20;
    // 0x80800620: lwc1        $f14, 0xC04($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC04));
    after_20:
    // 0x80800624: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800628: bne         $s0, $s2, L_808005BC
    if (ctx->r16 != ctx->r18) {
        // 0x8080062C: add.s       $f20, $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
            goto L_808005BC;
    }
    // 0x8080062C: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x80800630: b           L_80800658
    // 0x80800634: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
        goto L_80800658;
    // 0x80800634: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
L_80800638:
    // 0x80800638: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1244, 0XD28) << 16);
    // 0x8080063C: addiu       $t8, $t8, 0xD28
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1244, 0XD28));
    // 0x80800640: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800644: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800648: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080064C: jal         0x800BBCB8
    // 0x80800650: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_800BBCB8(rdram, ctx);
        goto after_21;
    // 0x80800650: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_21:
L_80800654:
    // 0x80800654: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
L_80800658:
    // 0x80800658: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8080065C: lw          $a0, 0xC($t9)
    ctx->r4 = MEM_W(ctx->r25, 0XC);
    // 0x80800660: beq         $a0, $zero, L_80800678
    if (ctx->r4 == 0) {
        // 0x80800664: nop
    
            goto L_80800678;
    }
    // 0x80800664: nop

    // 0x80800668: jal         0x800863E8
    // 0x8080066C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_22;
    // 0x8080066C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_22:
    // 0x80800670: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80800674: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
L_80800678:
    // 0x80800678: jal         0x800FFAB0
    // 0x8080067C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_23;
    // 0x8080067C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_23:
    // 0x80800680: jal         0x8010A570
    // 0x80800684: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8010A570(rdram, ctx);
        goto after_24;
    // 0x80800684: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_24:
    // 0x80800688: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8080068C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800690: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800694: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80800698: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x8080069C: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x808006A0: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x808006A4: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x808006A8: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x808006AC: jr          $ra
    // 0x808006B0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x808006B0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_800F90EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F90EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F90F0: jr          $ra
    // 0x800F90F4: swc1        $f12, 0x550C($at)
    MEM_W(0X550C, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x800F90F4: swc1        $f12, 0x550C($at)
    MEM_W(0X550C, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void _dbzone_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087940: syscall     640
    recomp_syscall_handler(rdram, ctx, 0x80087940);
    return;
    // 0x80087944: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800364_bskazglide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800364: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800368: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080036C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800370: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800374: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80800378: jal         0x800852F0
    // 0x8080037C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x8080037C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: jal         0x80085300
    // 0x80800388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_1;
    // 0x80800388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080038C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800390: nop

    // 0x80800394: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800398: nop

    // 0x8080039C: bc1f        L_808003AC
    if (!c1cs) {
        // 0x808003A0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_808003AC;
    }
    // 0x808003A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808003A4: b           L_808003B0
    // 0x808003A8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
        goto L_808003B0;
    // 0x808003A8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_808003AC:
    // 0x808003AC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_808003B0:
    // 0x808003B0: jal         0x80084C10
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003BC: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808003C0: jal         0x80084C18
    // 0x808003C4: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    _bafly_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x808003C4: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    after_3:
    // 0x808003C8: jal         0x80084C20
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafly_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808003D0: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x808003D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003D8: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x808003DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003E0: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x808003E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003E8: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x808003EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x808003F8: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x808003FC: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    // 0x80800400: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800404: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80800408: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8080040C: jal         0x80084C08
    // 0x80800410: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    _bafly_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800410: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: jal         0x8008DF8C
    // 0x8080041C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_8008DF8C(rdram, ctx);
        goto after_6;
    // 0x8080041C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_6:
    // 0x80800420: bne         $v0, $zero, L_8080043C
    if (ctx->r2 != 0) {
        // 0x80800424: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080043C;
    }
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: jal         0x80091A30
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_released(rdram, ctx);
        goto after_7;
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800430: beq         $v0, $zero, L_80800444
    if (ctx->r2 == 0) {
        // 0x80800434: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80800444;
    }
    // 0x80800434: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800438: beq         $t7, $zero, L_80800444
    if (ctx->r15 == 0) {
        // 0x8080043C: addiu       $t8, $zero, 0xDF
        ctx->r24 = ADD32(0, 0XDF);
            goto L_80800444;
    }
L_8080043C:
    // 0x8080043C: addiu       $t8, $zero, 0xDF
    ctx->r24 = ADD32(0, 0XDF);
    // 0x80800440: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80800444:
    // 0x80800444: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800448: beq         $t9, $zero, L_80800494
    if (ctx->r25 == 0) {
        // 0x8080044C: nop
    
            goto L_80800494;
    }
    // 0x8080044C: nop

    // 0x80800450: jal         0x80097D9C
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_feathery_flap(rdram, ctx);
        goto after_8;
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800458: bne         $v0, $zero, L_8080046C
    if (ctx->r2 != 0) {
        // 0x8080045C: addiu       $t1, $zero, 0x15C
        ctx->r9 = ADD32(0, 0X15C);
            goto L_8080046C;
    }
    // 0x8080045C: addiu       $t1, $zero, 0x15C
    ctx->r9 = ADD32(0, 0X15C);
    // 0x80800460: lbu         $t0, 0x15C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X15C);
    // 0x80800464: beq         $t0, $zero, L_80800470
    if (ctx->r8 == 0) {
        // 0x80800468: nop
    
            goto L_80800470;
    }
    // 0x80800468: nop

L_8080046C:
    // 0x8080046C: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_80800470:
    // 0x80800470: jal         0x80097FB8
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097FB8(rdram, ctx);
        goto after_9;
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800478: bne         $v0, $zero, L_8080048C
    if (ctx->r2 != 0) {
        // 0x8080047C: addiu       $t3, $zero, 0xC4
        ctx->r11 = ADD32(0, 0XC4);
            goto L_8080048C;
    }
    // 0x8080047C: addiu       $t3, $zero, 0xC4
    ctx->r11 = ADD32(0, 0XC4);
    // 0x80800480: lbu         $t2, 0x15D($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X15D);
    // 0x80800484: beq         $t2, $zero, L_808004C4
    if (ctx->r10 == 0) {
        // 0x80800488: nop
    
            goto L_808004C4;
    }
    // 0x80800488: nop

L_8080048C:
    // 0x8080048C: b           L_808004C4
    // 0x80800490: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
        goto L_808004C4;
    // 0x80800490: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80800494:
    // 0x80800494: jal         0x80097D9C
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_feathery_flap(rdram, ctx);
        goto after_10;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080049C: beq         $v0, $zero, L_808004AC
    if (ctx->r2 == 0) {
        // 0x808004A0: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_808004AC;
    }
    // 0x808004A0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x808004A4: sb          $t4, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r12;
    // 0x808004A8: sb          $zero, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = 0;
L_808004AC:
    // 0x808004AC: jal         0x80097FB8
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097FB8(rdram, ctx);
        goto after_11;
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808004B4: beq         $v0, $zero, L_808004C4
    if (ctx->r2 == 0) {
        // 0x808004B8: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_808004C4;
    }
    // 0x808004B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808004BC: sb          $zero, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = 0;
    // 0x808004C0: sb          $t5, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = ctx->r13;
L_808004C4:
    // 0x808004C4: jal         0x8008E35C
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_12;
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808004CC: beq         $v0, $zero, L_808004DC
    if (ctx->r2 == 0) {
        // 0x808004D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004DC;
    }
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D4: addiu       $t6, $zero, 0x160
    ctx->r14 = ADD32(0, 0X160);
    // 0x808004D8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_808004DC:
    // 0x808004DC: jal         0x8009E5C8
    // 0x808004E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_13;
    // 0x808004E0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_13:
    // 0x808004E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808004E8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808004EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808004F0: jr          $ra
    // 0x808004F4: nop

    return;
    // 0x808004F4: nop

;}
RECOMP_FUNC void func_80090A4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090A4C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80090A50: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80090A54: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80090A58: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80090A5C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80090A60: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80090A64: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80090A68: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80090A6C: jal         0x800D8FF8
    // 0x80090A70: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80090A70: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    after_0:
    // 0x80090A74: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80090A78: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80090A7C: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x80090A80: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80090A84: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x80090A88: bc1fl       L_80090B6C
    if (!c1cs) {
        // 0x80090A8C: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80090B6C;
    }
    goto skip_0;
    // 0x80090A8C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
L_80090A90:
    // 0x80090A90: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x80090A94: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80090A98: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80090A9C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80090AA0: lw          $t6, 0x20($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X20);
    // 0x80090AA4: lwc1        $f12, 0x4($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80090AA8: c.lt.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl < ctx->f12.fl;
    // 0x80090AAC: nop

    // 0x80090AB0: bc1tl       L_80090B6C
    if (c1cs) {
        // 0x80090AB4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80090B6C;
    }
    goto skip_1;
    // 0x80090AB4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80090AB8: jal         0x800F2100
    // 0x80090ABC: nop

    mlAbsF(rdram, ctx);
        goto after_1;
    // 0x80090ABC: nop

    after_1:
    // 0x80090AC0: lw          $t7, 0x20($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X20);
    // 0x80090AC4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80090AC8: jal         0x800908A8
    // 0x80090ACC: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    func_800908A8(rdram, ctx);
        goto after_2;
    // 0x80090ACC: lbu         $a0, 0x0($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X0);
    after_2:
    // 0x80090AD0: lw          $t8, 0x20($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X20);
    // 0x80090AD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80090AD8: lbu         $t9, 0x8($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X8);
    // 0x80090ADC: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80090AE0: mflo        $t0
    ctx->r8 = lo;
    // 0x80090AE4: addu        $s0, $v0, $t0
    ctx->r16 = ADD32(ctx->r2, ctx->r8);
    // 0x80090AE8: lbu         $a1, 0x4($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X4);
    // 0x80090AEC: jal         0x800950FC
    // 0x80090AF0: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    func_800950FC(rdram, ctx);
        goto after_3;
    // 0x80090AF0: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_3:
    // 0x80090AF4: lbu         $t1, 0x10($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X10);
    // 0x80090AF8: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80090AFC: bnel        $s3, $t1, L_80090B48
    if (ctx->r19 != ctx->r9) {
        // 0x80090B00: lw          $v0, 0x20($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X20);
            goto L_80090B48;
    }
    goto skip_2;
    // 0x80090B00: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    skip_2:
    // 0x80090B04: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80090B08: c.eq.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl == ctx->f8.fl;
    // 0x80090B0C: nop

    // 0x80090B10: bc1f        L_80090B28
    if (!c1cs) {
        // 0x80090B14: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80090B28;
    }
    // 0x80090B14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80090B18: jal         0x800908F0
    // 0x80090B1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800908F0(rdram, ctx);
        goto after_4;
    // 0x80090B1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80090B20: b           L_80090B6C
    // 0x80090B24: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80090B6C;
    // 0x80090B24: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80090B28:
    // 0x80090B28: lw          $t2, 0x20($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X20);
    // 0x80090B2C: jal         0x800908A8
    // 0x80090B30: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    func_800908A8(rdram, ctx);
        goto after_5;
    // 0x80090B30: lbu         $a0, 0x0($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X0);
    after_5:
    // 0x80090B34: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x80090B38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80090B3C: b           L_80090B54
    // 0x80090B40: sb          $zero, 0x8($t3)
    MEM_B(0X8, ctx->r11) = 0;
        goto L_80090B54;
    // 0x80090B40: sb          $zero, 0x8($t3)
    MEM_B(0X8, ctx->r11) = 0;
    // 0x80090B44: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
L_80090B48:
    // 0x80090B48: lbu         $t4, 0x8($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X8);
    // 0x80090B4C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80090B50: sb          $t5, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r13;
L_80090B54:
    // 0x80090B54: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x80090B58: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80090B5C: lw          $t6, 0x20($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X20);
    // 0x80090B60: bc1t        L_80090A90
    if (c1cs) {
        // 0x80090B64: swc1        $f10, 0x4($t6)
        MEM_W(0X4, ctx->r14) = ctx->f10.u32l;
            goto L_80090A90;
    }
    // 0x80090B64: swc1        $f10, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f10.u32l;
    // 0x80090B68: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80090B6C:
    // 0x80090B6C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80090B70: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80090B74: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80090B78: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80090B7C: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80090B80: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80090B84: jr          $ra
    // 0x80090B88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80090B88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80090B8C: nop

;}
RECOMP_FUNC void func_80800524_chjigsawcollect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800524: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080052C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800530: jal         0x80100094
    // 0x80800534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800538: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8080053C: beql        $t6, $zero, L_8080055C
    if (ctx->r14 == 0) {
        // 0x80800540: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_8080055C;
    }
    goto skip_0;
    // 0x80800540: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800544: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80800548: jal         0x800C8B84
    // 0x8080054C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800C8B84(rdram, ctx);
        goto after_1;
    // 0x8080054C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800550: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800554: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x80800558: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_8080055C:
    // 0x8080055C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800564: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x80800568: sll         $t0, $t8, 11
    ctx->r8 = S32(ctx->r24 << 11);
    // 0x8080056C: bgezl       $t0, L_80800598
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800570: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800598;
    }
    goto skip_1;
    // 0x80800570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800574: jal         0x800FCAE0
    // 0x80800578: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    func_800FCAE0(rdram, ctx);
        goto after_2;
    // 0x80800578: addiu       $a2, $zero, 0x1F4
    ctx->r6 = ADD32(0, 0X1F4);
    after_2:
    // 0x8080057C: jal         0x800FCA90
    // 0x80800580: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800FCA90(rdram, ctx);
        goto after_3;
    // 0x80800580: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_3:
    // 0x80800584: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80800588: lbu         $t2, 0x65($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X65);
    // 0x8080058C: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x80800590: sb          $t3, 0x65($t1)
    MEM_B(0X65, ctx->r9) = ctx->r11;
    // 0x80800594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800598:
    // 0x80800598: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080059C: jr          $ra
    // 0x808005A0: nop

    return;
    // 0x808005A0: nop

;}
RECOMP_FUNC void _idworld_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F10: syscall     748
    recomp_syscall_handler(rdram, ctx, 0x80088F10);
    return;
    // 0x80088F14: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800190_changlerbossflare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800194: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800198: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080019C: lw          $a3, 0x54($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X54);
    // 0x808001A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A4: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x808001A8: beq         $a3, $zero, L_808001C0
    if (ctx->r7 == 0) {
        // 0x808001AC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808001C0;
    }
    // 0x808001AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808001B0: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808001B4: jal         0x800863E8
    // 0x808001B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808001B8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x808001BC: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
L_808001C0:
    // 0x808001C0: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1336, 0X500) << 16);
    // 0x808001C4: addiu       $t6, $t6, 0x500
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1336, 0X500));
    // 0x808001C8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001CC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808001D0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x808001D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001DC: jal         0x800BBCB8
    // 0x808001E0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x808001E0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_1:
    // 0x808001E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1336, 0X53C) << 16);
    // 0x808001E8: addiu       $a2, $a2, 0x53C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1336, 0X53C));
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x80089D18
    // 0x808001F4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808001F4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x808001F8: jal         0x8010A570
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800200: jal         0x800FFAB0
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800208: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080020C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800210: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

;}
RECOMP_FUNC void bafpctrl_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CB8: beql        $a2, $zero, L_80800CD8
    if (ctx->r6 == 0) {
        // 0x80800CBC: lw          $v0, 0x90($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X90);
            goto L_80800CD8;
    }
    goto skip_0;
    // 0x80800CBC: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    skip_0:
    // 0x80800CC0: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x80800CC4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800CC8: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x80800CCC: jr          $ra
    // 0x80800CD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x80800CD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80800CD4: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
L_80800CD8:
    // 0x80800CD8: nor         $t9, $a1, $zero
    ctx->r25 = ~(ctx->r5 | 0);
    // 0x80800CDC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80800CE0: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80800CE4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80800CE8: jr          $ra
    // 0x80800CEC: nop

    return;
    // 0x80800CEC: nop

;}
RECOMP_FUNC void _gccubesearch_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800882E8: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x800882E8);
    return;
    // 0x800882EC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_80108EE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108EE8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80108EEC: jr          $ra
    // 0x80108EF0: addiu       $v0, $v0, 0x45F8
    ctx->r2 = ADD32(ctx->r2, 0X45F8);
    return;
    // 0x80108EF0: addiu       $v0, $v0, 0x45F8
    ctx->r2 = ADD32(ctx->r2, 0X45F8);
;}
RECOMP_FUNC void func_800FCB00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCB00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FCB04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FCB08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FCB0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800FCB10: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800FCB14: jal         0x800FB5F8
    // 0x800FCB18: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800FB5F8(rdram, ctx);
        goto after_0;
    // 0x800FCB18: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800FCB1C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800FCB20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800FCB24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800FCB28: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800FCB2C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800FCB30: addiu       $t9, $t8, 0x3C
    ctx->r25 = ADD32(ctx->r24, 0X3C);
    // 0x800FCB34: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800FCB38: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800FCB3C: jal         0x800FCB9C
    // 0x800FCB40: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800FCB9C(rdram, ctx);
        goto after_1;
    // 0x800FCB40: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x800FCB44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FCB48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FCB4C: jr          $ra
    // 0x800FCB50: nop

    return;
    // 0x800FCB50: nop

;}
RECOMP_FUNC void bsrest_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808005A8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(344, 0X920) << 16);
    // 0x808005AC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808005B0: jr          $ra
    // 0x808005B4: lw          $v0, 0x920($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(344, 0X920));
    return;
    // 0x808005B4: lw          $v0, 0x920($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(344, 0X920));
;}
RECOMP_FUNC void _glcutDll_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088848: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x80088848);
    return;
    // 0x8008884C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_800E8A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8A60: jr          $ra
    // 0x800E8A64: nop

    return;
    // 0x800E8A64: nop

;}
RECOMP_FUNC void func_8010AA9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AA9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010AAA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AAA4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010AAA8: jal         0x800EE7F8
    // 0x8010AAAC: addiu       $a1, $a1, 0x6F40
    ctx->r5 = ADD32(ctx->r5, 0X6F40);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8010AAAC: addiu       $a1, $a1, 0x6F40
    ctx->r5 = ADD32(ctx->r5, 0X6F40);
    after_0:
    // 0x8010AAB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AAB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AAB8: jr          $ra
    // 0x8010AABC: nop

    return;
    // 0x8010AABC: nop

;}
RECOMP_FUNC void _ncfixposrot_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089228: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x80089228);
    return;
    // 0x8008922C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_800A0024(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0024: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A0028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A002C: jal         0x8009CC68
    // 0x800A0030: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8009CC68(rdram, ctx);
        goto after_0;
    // 0x800A0030: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A0034: beq         $v0, $zero, L_800A0054
    if (ctx->r2 == 0) {
        // 0x800A0038: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0054;
    }
    // 0x800A0038: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A003C: jal         0x8009CC18
    // 0x800A0040: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009CC18(rdram, ctx);
        goto after_1;
    // 0x800A0040: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x800A0044: beq         $v0, $zero, L_800A0054
    if (ctx->r2 == 0) {
        // 0x800A0048: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0054;
    }
    // 0x800A0048: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A004C: jal         0x800A0064
    // 0x800A0050: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800A0064(rdram, ctx);
        goto after_2;
    // 0x800A0050: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_2:
L_800A0054:
    // 0x800A0054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A0058: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A005C: jr          $ra
    // 0x800A0060: nop

    return;
    // 0x800A0060: nop

;}
RECOMP_FUNC void func_80800450_subaddiefade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800450: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80800454: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80800458: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x8080045C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800460: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800464: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800468: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8080046C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800470: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800474: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800478: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8080047C: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x80800480: nop

    // 0x80800484: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80800488: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8080048C: jr          $ra
    // 0x80800490: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    return;
    // 0x80800490: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8008C990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C990: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008C994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C99C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8008C9A0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8008C9A4: jal         0x8008B10C
    // 0x8008C9A8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_8008B10C(rdram, ctx);
        goto after_0;
    // 0x8008C9A8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8008C9AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C9B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C9B4: jr          $ra
    // 0x8008C9B8: nop

    return;
    // 0x8008C9B8: nop

;}
RECOMP_FUNC void chfirefx_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x808002CC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808002D0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808002D4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x808002D8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808002DC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808002E0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808002E4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808002E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808002EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002F0: jal         0x80100094
    // 0x808002F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002F8: jal         0x800F54E4
    // 0x808002FC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808002FC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    after_1:
    // 0x80800300: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800304: jal         0x800D9078
    // 0x80800308: addiu       $a0, $s6, 0x58
    ctx->r4 = ADD32(ctx->r22, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80800308: addiu       $a0, $s6, 0x58
    ctx->r4 = ADD32(ctx->r22, 0X58);
    after_2:
    // 0x8080030C: lhu         $v1, 0x72($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0X72);
    // 0x80800310: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800314: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80800318: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x8080031C: beql        $t6, $at, L_808003C4
    if (ctx->r14 == ctx->r1) {
        // 0x80800320: lh          $t2, 0xA($s3)
        ctx->r10 = MEM_H(ctx->r19, 0XA);
            goto L_808003C4;
    }
    goto skip_0;
    // 0x80800320: lh          $t2, 0xA($s3)
    ctx->r10 = MEM_H(ctx->r19, 0XA);
    skip_0:
    // 0x80800324: bne         $t6, $s1, L_808003DC
    if (ctx->r14 != ctx->r17) {
        // 0x80800328: nop
    
            goto L_808003DC;
    }
    // 0x80800328: nop

    // 0x8080032C: lh          $t7, 0xA($s3)
    ctx->r15 = MEM_H(ctx->r19, 0XA);
    // 0x80800330: lh          $v0, 0xC($s3)
    ctx->r2 = MEM_H(ctx->r19, 0XC);
    // 0x80800334: addiu       $t8, $t7, 0x2
    ctx->r24 = ADD32(ctx->r15, 0X2);
    // 0x80800338: sh          $t8, 0xA($s3)
    MEM_H(0XA, ctx->r19) = ctx->r24;
    // 0x8080033C: lh          $t9, 0xA($s3)
    ctx->r25 = MEM_H(ctx->r19, 0XA);
    // 0x80800340: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800344: bnel        $at, $zero, L_80800354
    if (ctx->r1 != 0) {
        // 0x80800348: lhu         $t0, 0x10($s3)
        ctx->r8 = MEM_HU(ctx->r19, 0X10);
            goto L_80800354;
    }
    goto skip_1;
    // 0x80800348: lhu         $t0, 0x10($s3)
    ctx->r8 = MEM_HU(ctx->r19, 0X10);
    skip_1:
    // 0x8080034C: sh          $v0, 0xA($s3)
    MEM_H(0XA, ctx->r19) = ctx->r2;
    // 0x80800350: lhu         $t0, 0x10($s3)
    ctx->r8 = MEM_HU(ctx->r19, 0X10);
L_80800354:
    // 0x80800354: andi        $t1, $t0, 0x4
    ctx->r9 = ctx->r8 & 0X4;
    // 0x80800358: beq         $t1, $zero, L_808003DC
    if (ctx->r9 == 0) {
        // 0x8080035C: nop
    
            goto L_808003DC;
    }
    // 0x8080035C: nop

    // 0x80800360: jal         0x800F6438
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_3;
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800368: beq         $v0, $zero, L_808003DC
    if (ctx->r2 == 0) {
        // 0x8080036C: nop
    
            goto L_808003DC;
    }
    // 0x8080036C: nop

    // 0x80800370: jal         0x800F6AA4
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6AA4(rdram, ctx);
        goto after_4;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800378: bne         $v0, $zero, L_808003DC
    if (ctx->r2 != 0) {
        // 0x8080037C: nop
    
            goto L_808003DC;
    }
    // 0x8080037C: nop

    // 0x80800380: jal         0x800F6478
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6478(rdram, ctx);
        goto after_5;
    // 0x80800384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800388: beq         $v0, $zero, L_808003DC
    if (ctx->r2 == 0) {
        // 0x8080038C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_808003DC;
    }
    // 0x8080038C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800390: jal         0x8010CEF8
    // 0x80800394: lh          $a1, 0x12($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X12);
    func_8010CEF8(rdram, ctx);
        goto after_6;
    // 0x80800394: lh          $a1, 0x12($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X12);
    after_6:
    // 0x80800398: beq         $v0, $zero, L_808003DC
    if (ctx->r2 == 0) {
        // 0x8080039C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003DC;
    }
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A0: jal         0x800F7B9C
    // 0x808003A4: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    func_800F7B9C(rdram, ctx);
        goto after_7;
    // 0x808003A4: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_7:
    // 0x808003A8: bne         $v0, $s1, L_808003DC
    if (ctx->r2 != ctx->r17) {
        // 0x808003AC: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_808003DC;
    }
    // 0x808003AC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808003B0: jal         0x80086448
    // 0x808003B4: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    _chhotwaterpoolbits_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x808003B4: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    after_8:
    // 0x808003B8: b           L_808003DC
    // 0x808003BC: nop

        goto L_808003DC;
    // 0x808003BC: nop

    // 0x808003C0: lh          $t2, 0xA($s3)
    ctx->r10 = MEM_H(ctx->r19, 0XA);
L_808003C4:
    // 0x808003C4: addiu       $t3, $t2, -0x2
    ctx->r11 = ADD32(ctx->r10, -0X2);
    // 0x808003C8: sh          $t3, 0xA($s3)
    MEM_H(0XA, ctx->r19) = ctx->r11;
    // 0x808003CC: lh          $t4, 0xA($s3)
    ctx->r12 = MEM_H(ctx->r19, 0XA);
    // 0x808003D0: bgez        $t4, L_808003DC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x808003D4: nop
    
            goto L_808003DC;
    }
    // 0x808003D4: nop

    // 0x808003D8: sh          $zero, 0xA($s3)
    MEM_H(0XA, ctx->r19) = 0;
L_808003DC:
    // 0x808003DC: jal         0x80800884
    // 0x808003E0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80800884_chfirefx(rdram, ctx);
        goto after_9;
    // 0x808003E0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_9:
    // 0x808003E4: beql        $v0, $zero, L_808005F0
    if (ctx->r2 == 0) {
        // 0x808003E8: lhu         $t7, 0x10($s3)
        ctx->r15 = MEM_HU(ctx->r19, 0X10);
            goto L_808005F0;
    }
    goto skip_2;
    // 0x808003E8: lhu         $t7, 0x10($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X10);
    skip_2:
    // 0x808003EC: jal         0x800D8FF8
    // 0x808003F0: nop

    func_800D8FF8(rdram, ctx);
        goto after_10;
    // 0x808003F0: nop

    after_10:
    // 0x808003F4: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x808003F8: lwc1        $f4, 0x4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
    // 0x808003FC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800400: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800404: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800408: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080040C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800410: addiu       $s0, $s3, 0x20
    ctx->r16 = ADD32(ctx->r19, 0X20);
    // 0x80800414: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80800418: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8080041C: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80800420: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80800424: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80800428: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8080042C: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x80800430: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x80800434: lh          $t6, 0x8($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X8);
    // 0x80800438: blezl       $t6, L_808005F0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8080043C: lhu         $t7, 0x10($s3)
        ctx->r15 = MEM_HU(ctx->r19, 0X10);
            goto L_808005F0;
    }
    goto skip_3;
    // 0x8080043C: lhu         $t7, 0x10($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X10);
    skip_3:
    // 0x80800440: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800444: addiu       $s5, $sp, 0x48
    ctx->r21 = ADD32(ctx->r29, 0X48);
    // 0x80800448: addiu       $s2, $sp, 0x54
    ctx->r18 = ADD32(ctx->r29, 0X54);
    // 0x8080044C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800450: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80800454: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
L_80800458:
    // 0x80800458: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080045C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800460: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x80800464: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800468: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8080046C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80800470: nop

    // 0x80800474: slti        $at, $t8, 0x9
    ctx->r1 = SIGNED(ctx->r24) < 0X9 ? 1 : 0;
    // 0x80800478: bnel        $at, $zero, L_808004C0
    if (ctx->r1 != 0) {
        // 0x8080047C: lh          $t3, 0x4($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X4);
            goto L_808004C0;
    }
    goto skip_4;
    // 0x8080047C: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    skip_4:
    // 0x80800480: lh          $t9, 0x8($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X8);
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800488: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8080048C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800490: sh          $t0, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r8;
    // 0x80800494: lh          $s1, 0x8($s3)
    ctx->r17 = MEM_H(ctx->r19, 0X8);
    // 0x80800498: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8080049C: blez        $s1, L_808005E0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x808004A0: sll         $t1, $s1, 2
        ctx->r9 = S32(ctx->r17 << 2);
            goto L_808005E0;
    }
    // 0x808004A0: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x808004A4: addu        $t1, $t1, $s1
    ctx->r9 = ADD32(ctx->r9, ctx->r17);
    // 0x808004A8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808004AC: jal         0x8001BBA0
    // 0x808004B0: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    rare_memcpy(rdram, ctx);
        goto after_11;
    // 0x808004B0: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_11:
    // 0x808004B4: b           L_808005E0
    // 0x808004B8: lh          $s1, 0x8($s3)
    ctx->r17 = MEM_H(ctx->r19, 0X8);
        goto L_808005E0;
    // 0x808004B8: lh          $s1, 0x8($s3)
    ctx->r17 = MEM_H(ctx->r19, 0X8);
    // 0x808004BC: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
L_808004C0:
    // 0x808004C0: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808004C4: lh          $t7, 0xA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XA);
    // 0x808004C8: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x808004CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808004D0: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x808004D4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808004D8: addiu       $s1, $s6, 0x4
    ctx->r17 = ADD32(ctx->r22, 0X4);
    // 0x808004DC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808004E0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808004E4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x808004E8: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x808004EC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808004F0: sh          $t5, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r13;
    // 0x808004F4: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x808004F8: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x808004FC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80800500: nop

    // 0x80800504: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800508: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8080050C: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80800510: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800514: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80800518: jal         0x800EE88C
    // 0x8080051C: sh          $t9, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r25;
    func_800EE88C(rdram, ctx);
        goto after_12;
    // 0x8080051C: sh          $t9, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r25;
    after_12:
    // 0x80800520: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800524: jal         0x800EF04C
    // 0x80800528: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_13;
    // 0x80800528: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_13:
    // 0x8080052C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800530: jal         0x800EFC7C
    // 0x80800534: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_14;
    // 0x80800534: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_14:
    // 0x80800538: lh          $t0, 0x12($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X12);
    // 0x8080053C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1104, 0X11D4) << 16);
    // 0x80800540: lwc1        $f8, 0x11D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1104, 0X11D4));
    // 0x80800544: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80800548: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080054C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800550: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800554: mul.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80800558: nop

    // 0x8080055C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80800560: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800564: nop

    // 0x80800568: bc1f        L_808005D4
    if (!c1cs) {
        // 0x8080056C: nop
    
            goto L_808005D4;
    }
    // 0x8080056C: nop

    // 0x80800570: jal         0x800EFB24
    // 0x80800574: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_15;
    // 0x80800574: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_15:
    // 0x80800578: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8080057C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800580: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80800584: jal         0x800EF368
    // 0x80800588: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    func_800EF368(rdram, ctx);
        goto after_16;
    // 0x80800588: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    after_16:
    // 0x8080058C: lh          $t1, 0x8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X8);
    // 0x80800590: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800594: lh          $t4, 0xC($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XC);
    // 0x80800598: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8080059C: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x808005A0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808005A4: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808005A8: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x808005AC: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808005B0: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x808005B4: nop

    // 0x808005B8: sh          $t3, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r11;
    // 0x808005BC: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808005C0: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x808005C4: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808005C8: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x808005CC: nop

    // 0x808005D0: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
L_808005D4:
    // 0x808005D4: lh          $s1, 0x8($s3)
    ctx->r17 = MEM_H(ctx->r19, 0X8);
    // 0x808005D8: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x808005DC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_808005E0:
    // 0x808005E0: slt         $at, $s4, $s1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x808005E4: bnel        $at, $zero, L_80800458
    if (ctx->r1 != 0) {
        // 0x808005E8: lwc1        $f8, 0x0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
            goto L_80800458;
    }
    goto skip_5;
    // 0x808005E8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x808005EC: lhu         $t7, 0x10($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X10);
L_808005F0:
    // 0x808005F0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x808005F4: beq         $t8, $zero, L_80800604
    if (ctx->r24 == 0) {
        // 0x808005F8: nop
    
            goto L_80800604;
    }
    // 0x808005F8: nop

    // 0x808005FC: jal         0x80800C18
    // 0x80800600: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80800C18_chfirefx(rdram, ctx);
        goto after_17;
    // 0x80800600: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_17:
L_80800604:
    // 0x80800604: jal         0x80800E9C
    // 0x80800608: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80800E9C_chfirefx(rdram, ctx);
        goto after_18;
    // 0x80800608: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_18:
    // 0x8080060C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
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
    // 0x80800624: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800628: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8080062C: jr          $ra
    // 0x80800630: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80800630: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
