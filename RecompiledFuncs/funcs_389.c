#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F7F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7F98: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7F9C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800F7FA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7FA4: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x800F7FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7FAC: beq         $a1, $zero, L_800F7FD8
    if (ctx->r5 == 0) {
        // 0x800F7FB0: lw          $a2, 0x5490($a2)
        ctx->r6 = MEM_W(ctx->r6, 0X5490);
            goto L_800F7FD8;
    }
    // 0x800F7FB0: lw          $a2, 0x5490($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5490);
    // 0x800F7FB4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800F7FB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800F7FBC: jal         0x80091C14
    // 0x800F7FC0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    bakey_func_80091C14(rdram, ctx);
        goto after_0;
    // 0x800F7FC0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800F7FC4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7FC8: jal         0x8009F18C
    // 0x800F7FCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bastick_func_8009F18C(rdram, ctx);
        goto after_1;
    // 0x800F7FCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800F7FD0: b           L_800F7FF8
    // 0x800F7FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F7FF8;
    // 0x800F7FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F7FD8:
    // 0x800F7FD8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800F7FDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800F7FE0: jal         0x80091C14
    // 0x800F7FE4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    bakey_func_80091C14(rdram, ctx);
        goto after_2;
    // 0x800F7FE4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x800F7FE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7FEC: jal         0x8009F18C
    // 0x800F7FF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_func_8009F18C(rdram, ctx);
        goto after_3;
    // 0x800F7FF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800F7FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F7FF8:
    // 0x800F7FF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7FFC: jr          $ra
    // 0x800F8000: nop

    return;
    // 0x800F8000: nop

;}
RECOMP_FUNC void func_80023008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023008: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8002300C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80023010: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x80023014: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x80023018: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8002301C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80023020: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80023024: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x80023028: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8002302C: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x80023030: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x80023034: lbu         $t9, 0x4($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4);
    // 0x80023038: andi        $t0, $t9, 0xF0
    ctx->r8 = ctx->r25 & 0XF0;
    // 0x8002303C: sw          $t0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r8;
    // 0x80023040: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x80023044: lbu         $t2, 0x5($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5);
    // 0x80023048: sb          $t2, 0xD3($sp)
    MEM_B(0XD3, ctx->r29) = ctx->r10;
    // 0x8002304C: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x80023050: lbu         $t4, 0x6($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X6);
    // 0x80023054: sb          $t4, 0xD2($sp)
    MEM_B(0XD2, ctx->r29) = ctx->r12;
    // 0x80023058: sb          $t4, 0xD0($sp)
    MEM_B(0XD0, ctx->r29) = ctx->r12;
    // 0x8002305C: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x80023060: lbu         $t6, 0x7($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X7);
    // 0x80023064: sb          $t6, 0xD1($sp)
    MEM_B(0XD1, ctx->r29) = ctx->r14;
    // 0x80023068: sb          $t6, 0xCF($sp)
    MEM_B(0XCF, ctx->r29) = ctx->r14;
    // 0x8002306C: lw          $t7, 0xD4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD4);
    // 0x80023070: addiu       $t8, $t7, -0x80
    ctx->r24 = ADD32(ctx->r15, -0X80);
    // 0x80023074: sltiu       $at, $t8, 0x61
    ctx->r1 = ctx->r24 < 0X61 ? 1 : 0;
    // 0x80023078: beq         $at, $zero, L_80024A34
    if (ctx->r1 == 0) {
        // 0x8002307C: nop
    
            goto L_80024A34;
    }
    // 0x8002307C: nop

    // 0x80023080: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80023084: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80023088: addu        $at, $at, $t8
    gpr jr_addend_80023090 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8002308C: lw          $t8, 0x1A58($at)
    ctx->r24 = ADD32(ctx->r1, 0X1A58);
    // 0x80023090: jr          $t8
    // 0x80023094: nop

    switch (jr_addend_80023090 >> 2) {
        case 0: goto L_80023974; break;
        case 1: goto L_80024A34; break;
        case 2: goto L_80024A34; break;
        case 3: goto L_80024A34; break;
        case 4: goto L_80024A34; break;
        case 5: goto L_80024A34; break;
        case 6: goto L_80024A34; break;
        case 7: goto L_80024A34; break;
        case 8: goto L_80024A34; break;
        case 9: goto L_80024A34; break;
        case 10: goto L_80024A34; break;
        case 11: goto L_80024A34; break;
        case 12: goto L_80024A34; break;
        case 13: goto L_80024A34; break;
        case 14: goto L_80024A34; break;
        case 15: goto L_80024A34; break;
        case 16: goto L_80023098; break;
        case 17: goto L_80024A34; break;
        case 18: goto L_80024A34; break;
        case 19: goto L_80024A34; break;
        case 20: goto L_80024A34; break;
        case 21: goto L_80024A34; break;
        case 22: goto L_80024A34; break;
        case 23: goto L_80024A34; break;
        case 24: goto L_80024A34; break;
        case 25: goto L_80024A34; break;
        case 26: goto L_80024A34; break;
        case 27: goto L_80024A34; break;
        case 28: goto L_80024A34; break;
        case 29: goto L_80024A34; break;
        case 30: goto L_80024A34; break;
        case 31: goto L_80024A34; break;
        case 32: goto L_80023A8C; break;
        case 33: goto L_80024A34; break;
        case 34: goto L_80024A34; break;
        case 35: goto L_80024A34; break;
        case 36: goto L_80024A34; break;
        case 37: goto L_80024A34; break;
        case 38: goto L_80024A34; break;
        case 39: goto L_80024A34; break;
        case 40: goto L_80024A34; break;
        case 41: goto L_80024A34; break;
        case 42: goto L_80024A34; break;
        case 43: goto L_80024A34; break;
        case 44: goto L_80024A34; break;
        case 45: goto L_80024A34; break;
        case 46: goto L_80024A34; break;
        case 47: goto L_80024A34; break;
        case 48: goto L_80023B88; break;
        case 49: goto L_80024A34; break;
        case 50: goto L_80024A34; break;
        case 51: goto L_80024A34; break;
        case 52: goto L_80024A34; break;
        case 53: goto L_80024A34; break;
        case 54: goto L_80024A34; break;
        case 55: goto L_80024A34; break;
        case 56: goto L_80024A34; break;
        case 57: goto L_80024A34; break;
        case 58: goto L_80024A34; break;
        case 59: goto L_80024A34; break;
        case 60: goto L_80024A34; break;
        case 61: goto L_80024A34; break;
        case 62: goto L_80024A34; break;
        case 63: goto L_80024A34; break;
        case 64: goto L_8002483C; break;
        case 65: goto L_80024A34; break;
        case 66: goto L_80024A34; break;
        case 67: goto L_80024A34; break;
        case 68: goto L_80024A34; break;
        case 69: goto L_80024A34; break;
        case 70: goto L_80024A34; break;
        case 71: goto L_80024A34; break;
        case 72: goto L_80024A34; break;
        case 73: goto L_80024A34; break;
        case 74: goto L_80024A34; break;
        case 75: goto L_80024A34; break;
        case 76: goto L_80024A34; break;
        case 77: goto L_80024A34; break;
        case 78: goto L_80024A34; break;
        case 79: goto L_80024A34; break;
        case 80: goto L_80023B04; break;
        case 81: goto L_80024A34; break;
        case 82: goto L_80024A34; break;
        case 83: goto L_80024A34; break;
        case 84: goto L_80024A34; break;
        case 85: goto L_80024A34; break;
        case 86: goto L_80024A34; break;
        case 87: goto L_80024A34; break;
        case 88: goto L_80024A34; break;
        case 89: goto L_80024A34; break;
        case 90: goto L_80024A34; break;
        case 91: goto L_80024A34; break;
        case 92: goto L_80024A34; break;
        case 93: goto L_80024A34; break;
        case 94: goto L_80024A34; break;
        case 95: goto L_80024A34; break;
        case 96: goto L_800248A4; break;
        default: switch_error(__func__, 0x80023090, 0x80041A58);
    }
    // 0x80023094: nop

L_80023098:
    // 0x80023098: lbu         $t9, 0xD1($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XD1);
    // 0x8002309C: beq         $t9, $zero, L_80023974
    if (ctx->r25 == 0) {
        // 0x800230A0: nop
    
            goto L_80023974;
    }
    // 0x800230A0: nop

    // 0x800230A4: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x800230A8: lw          $t0, 0xE0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE0);
    // 0x800230AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800230B0: lw          $t1, 0x2C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2C);
    // 0x800230B4: bne         $t1, $at, L_800230D8
    if (ctx->r9 != ctx->r1) {
        // 0x800230B8: nop
    
            goto L_800230D8;
    }
    // 0x800230B8: nop

    // 0x800230BC: lbu         $t3, 0xD3($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XD3);
    // 0x800230C0: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x800230C4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800230C8: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x800230CC: and         $t6, $t2, $t5
    ctx->r14 = ctx->r10 & ctx->r13;
    // 0x800230D0: bne         $t6, $zero, L_80023164
    if (ctx->r14 != 0) {
        // 0x800230D4: nop
    
            goto L_80023164;
    }
    // 0x800230D4: nop

L_800230D8:
    // 0x800230D8: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x800230DC: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800230E0: beq         $t8, $zero, L_8002315C
    if (ctx->r24 == 0) {
        // 0x800230E4: nop
    
            goto L_8002315C;
    }
    // 0x800230E4: nop

    // 0x800230E8: addiu       $t9, $zero, 0x15
    ctx->r25 = ADD32(0, 0X15);
    // 0x800230EC: sh          $t9, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r25;
    // 0x800230F0: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x800230F4: sb          $t1, 0xBC($sp)
    MEM_B(0XBC, ctx->r29) = ctx->r9;
    // 0x800230F8: lbu         $t0, 0xD3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XD3);
    // 0x800230FC: sb          $t0, 0xBD($sp)
    MEM_B(0XBD, ctx->r29) = ctx->r8;
    // 0x80023100: lbu         $t4, 0xD2($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XD2);
    // 0x80023104: sb          $t4, 0xBE($sp)
    MEM_B(0XBE, ctx->r29) = ctx->r12;
    // 0x80023108: sb          $zero, 0xBF($sp)
    MEM_B(0XBF, ctx->r29) = 0;
    // 0x8002310C: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x80023110: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x80023114: lw          $t2, 0x24($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X24);
    // 0x80023118: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8002311C: multu       $t2, $t6
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023120: mflo        $t7
    ctx->r15 = lo;
    // 0x80023124: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x80023128: nop

    // 0x8002312C: lbu         $t9, 0xD3($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023130: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x80023134: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80023138: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8002313C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80023140: sw          $t8, -0x15B0($at)
    MEM_W(-0X15B0, ctx->r1) = ctx->r24;
    // 0x80023144: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80023148: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x8002314C: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    // 0x80023150: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80023154: jal         0x80026500
    // 0x80023158: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x80023158: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
L_8002315C:
    // 0x8002315C: b           L_80024A3C
    // 0x80023160: nop

        goto L_80024A3C;
    // 0x80023160: nop

L_80023164:
    // 0x80023164: lw          $t0, 0xE0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE0);
    // 0x80023168: lbu         $t3, 0xD3($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XD3);
    // 0x8002316C: lw          $t4, 0x60($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X60);
    // 0x80023170: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x80023174: subu        $t5, $t5, $t3
    ctx->r13 = SUB32(ctx->r13, ctx->r11);
    // 0x80023178: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002317C: addu        $t2, $t4, $t5
    ctx->r10 = ADD32(ctx->r12, ctx->r13);
    // 0x80023180: sw          $t2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r10;
    // 0x80023184: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80023188: lbu         $a1, 0xD2($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XD2);
    // 0x8002318C: lbu         $a2, 0xD1($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD1);
    // 0x80023190: jal         0x80029BA0
    // 0x80023194: lbu         $a3, 0xD3($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0XD3);
    func_80029BA0(rdram, ctx);
        goto after_1;
    // 0x80023194: lbu         $a3, 0xD3($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0XD3);
    after_1:
    // 0x80023198: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x8002319C: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x800231A0: bne         $t6, $zero, L_800231B0
    if (ctx->r14 != 0) {
        // 0x800231A4: nop
    
            goto L_800231B0;
    }
    // 0x800231A4: nop

    // 0x800231A8: b           L_80024A44
    // 0x800231AC: nop

        goto L_80024A44;
    // 0x800231AC: nop

L_800231B0:
    // 0x800231B0: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x800231B4: lbu         $t9, 0x4($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X4);
    // 0x800231B8: sh          $t9, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r25;
    // 0x800231BC: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x800231C0: lbu         $t1, 0x7($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X7);
    // 0x800231C4: sh          $t1, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r9;
    // 0x800231C8: sb          $zero, 0x9C($sp)
    MEM_B(0X9C, ctx->r29) = 0;
    // 0x800231CC: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x800231D0: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800231D4: lbu         $a1, 0xD2($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XD2);
    // 0x800231D8: lbu         $a2, 0xD1($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD1);
    // 0x800231DC: lbu         $a3, 0xD3($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0XD3);
    // 0x800231E0: jal         0x80029A04
    // 0x800231E4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80029A04(rdram, ctx);
        goto after_2;
    // 0x800231E4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x800231E8: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x800231EC: lw          $t3, 0xAC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XAC);
    // 0x800231F0: bne         $t3, $zero, L_80023200
    if (ctx->r11 != 0) {
        // 0x800231F4: nop
    
            goto L_80023200;
    }
    // 0x800231F4: nop

    // 0x800231F8: b           L_80024A44
    // 0x800231FC: nop

        goto L_80024A44;
    // 0x800231FC: nop

L_80023200:
    // 0x80023200: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x80023204: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x80023208: sw          $t5, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r13;
    // 0x8002320C: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x80023210: jal         0x800268D0
    // 0x80023214: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    func_800268D0(rdram, ctx);
        goto after_3;
    // 0x80023214: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    after_3:
    // 0x80023218: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x8002321C: lbu         $t7, 0xD3($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023220: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x80023224: lw          $t6, 0x60($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X60);
    // 0x80023228: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8002322C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80023230: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80023234: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x80023238: lbu         $t1, 0x33($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X33);
    // 0x8002323C: sh          $t1, 0x26($t0)
    MEM_H(0X26, ctx->r8) = ctx->r9;
    // 0x80023240: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x80023244: lbu         $t5, 0xD3($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023248: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x8002324C: lw          $t4, 0x60($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X60);
    // 0x80023250: sll         $t2, $t5, 3
    ctx->r10 = S32(ctx->r13 << 3);
    // 0x80023254: subu        $t2, $t2, $t5
    ctx->r10 = SUB32(ctx->r10, ctx->r13);
    // 0x80023258: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8002325C: addu        $t7, $t4, $t2
    ctx->r15 = ADD32(ctx->r12, ctx->r10);
    // 0x80023260: lbu         $t6, 0x34($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X34);
    // 0x80023264: sh          $t6, 0x24($t9)
    MEM_H(0X24, ctx->r25) = ctx->r14;
    // 0x80023268: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8002326C: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x80023270: sw          $t8, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->r24;
    // 0x80023274: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x80023278: sb          $zero, 0x38($t0)
    MEM_B(0X38, ctx->r8) = 0;
    // 0x8002327C: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x80023280: lbu         $t5, 0x8($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X8);
    // 0x80023284: slti        $at, $t5, 0x40
    ctx->r1 = SIGNED(ctx->r13) < 0X40 ? 1 : 0;
    // 0x80023288: bne         $at, $zero, L_800232A0
    if (ctx->r1 != 0) {
        // 0x8002328C: nop
    
            goto L_800232A0;
    }
    // 0x8002328C: nop

    // 0x80023290: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80023294: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80023298: b           L_800232A8
    // 0x8002329C: sb          $t4, 0x39($t2)
    MEM_B(0X39, ctx->r10) = ctx->r12;
        goto L_800232A8;
    // 0x8002329C: sb          $t4, 0x39($t2)
    MEM_B(0X39, ctx->r10) = ctx->r12;
L_800232A0:
    // 0x800232A0: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800232A4: sb          $zero, 0x39($t7)
    MEM_B(0X39, ctx->r15) = 0;
L_800232A8:
    // 0x800232A8: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x800232AC: lbu         $t6, 0xD2($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XD2);
    // 0x800232B0: lbu         $t8, 0x14($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X14);
    // 0x800232B4: lb          $t3, 0x15($t9)
    ctx->r11 = MEM_B(ctx->r25, 0X15);
    // 0x800232B8: subu        $t1, $t6, $t8
    ctx->r9 = SUB32(ctx->r14, ctx->r24);
    // 0x800232BC: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x800232C0: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x800232C4: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800232C8: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800232CC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800232D0: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x800232D4: sh          $t5, 0x92($sp)
    MEM_H(0X92, ctx->r29) = ctx->r13;
    // 0x800232D8: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x800232DC: lbu         $t2, 0x24($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X24);
    // 0x800232E0: beq         $t2, $zero, L_800232FC
    if (ctx->r10 == 0) {
        // 0x800232E4: nop
    
            goto L_800232FC;
    }
    // 0x800232E4: nop

    // 0x800232E8: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x800232EC: lh          $t7, 0x92($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X92);
    // 0x800232F0: lb          $t8, 0x27($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X27);
    // 0x800232F4: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x800232F8: sh          $t1, 0x92($sp)
    MEM_H(0X92, ctx->r29) = ctx->r9;
L_800232FC:
    // 0x800232FC: jal         0x80027170
    // 0x80023300: lh          $a0, 0x92($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X92);
    func_80027170(rdram, ctx);
        goto after_4;
    // 0x80023300: lh          $a0, 0x92($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X92);
    after_4:
    // 0x80023304: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x80023308: swc1        $f0, 0x2C($t9)
    MEM_W(0X2C, ctx->r25) = ctx->f0.u32l;
    // 0x8002330C: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x80023310: lbu         $t3, 0x24($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X24);
    // 0x80023314: beq         $t3, $zero, L_8002334C
    if (ctx->r11 == 0) {
        // 0x80023318: nop
    
            goto L_8002334C;
    }
    // 0x80023318: nop

    // 0x8002331C: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x80023320: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80023324: lbu         $t4, 0x25($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X25);
    // 0x80023328: sb          $t4, 0x34($t2)
    MEM_B(0X34, ctx->r10) = ctx->r12;
    // 0x8002332C: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x80023330: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x80023334: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x80023338: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x8002333C: lw          $t1, 0x18($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X18);
    // 0x80023340: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x80023344: b           L_80023378
    // 0x80023348: sw          $t9, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r25;
        goto L_80023378;
    // 0x80023348: sw          $t9, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r25;
L_8002334C:
    // 0x8002334C: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x80023350: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x80023354: lbu         $t5, 0xC($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0XC);
    // 0x80023358: sb          $t5, 0x34($t4)
    MEM_B(0X34, ctx->r12) = ctx->r13;
    // 0x8002335C: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x80023360: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x80023364: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x80023368: lw          $t6, 0x1C($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X1C);
    // 0x8002336C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80023370: addu        $t1, $t6, $t7
    ctx->r9 = ADD32(ctx->r14, ctx->r15);
    // 0x80023374: sw          $t1, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r9;
L_80023378:
    // 0x80023378: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x8002337C: sb          $zero, 0x3B($t0)
    MEM_B(0X3B, ctx->r8) = 0;
    // 0x80023380: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x80023384: lbu         $t5, 0x24($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X24);
    // 0x80023388: beq         $t5, $zero, L_800233A0
    if (ctx->r13 == 0) {
        // 0x8002338C: nop
    
            goto L_800233A0;
    }
    // 0x8002338C: nop

    // 0x80023390: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x80023394: lbu         $t2, 0x28($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X28);
    // 0x80023398: b           L_800233D4
    // 0x8002339C: sw          $t2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r10;
        goto L_800233D4;
    // 0x8002339C: sw          $t2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r10;
L_800233A0:
    // 0x800233A0: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x800233A4: lbu         $t7, 0xD3($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD3);
    // 0x800233A8: lw          $t6, 0x60($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X60);
    // 0x800233AC: sll         $t1, $t7, 3
    ctx->r9 = S32(ctx->r15 << 3);
    // 0x800233B0: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x800233B4: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800233B8: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x800233BC: jal         0x800E93AC
    // 0x800233C0: lbu         $a0, 0x33($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X33);
    func_800E93AC(rdram, ctx);
        goto after_5;
    // 0x800233C0: lbu         $a0, 0x33($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X33);
    after_5:
    // 0x800233C4: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x800233C8: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x800233CC: lbu         $t3, 0x4($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X4);
    // 0x800233D0: sw          $t3, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r11;
L_800233D4:
    // 0x800233D4: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800233D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800233DC: nop

    // 0x800233E0: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    // 0x800233E4: lw          $t5, 0xA0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA0);
    // 0x800233E8: beq         $t5, $zero, L_800234F0
    if (ctx->r13 == 0) {
        // 0x800233EC: nop
    
            goto L_800234F0;
    }
    // 0x800233EC: nop

    // 0x800233F0: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x800233F4: lw          $t2, 0x70($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X70);
    // 0x800233F8: beq         $t2, $zero, L_800234F0
    if (ctx->r10 == 0) {
        // 0x800233FC: nop
    
            goto L_800234F0;
    }
    // 0x800233FC: nop

    // 0x80023400: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x80023404: lbu         $t7, 0x24($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X24);
    // 0x80023408: beq         $t7, $zero, L_80023454
    if (ctx->r15 == 0) {
        // 0x8002340C: nop
    
            goto L_80023454;
    }
    // 0x8002340C: nop

    // 0x80023410: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x80023414: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x80023418: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x8002341C: lbu         $t1, 0x2A($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X2A);
    // 0x80023420: lbu         $a2, 0x28($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X28);
    // 0x80023424: lbu         $a3, 0x29($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X29);
    // 0x80023428: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8002342C: lbu         $t9, 0x2B($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X2B);
    // 0x80023430: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80023434: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80023438: lbu         $t0, 0x31($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X31);
    // 0x8002343C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80023440: lw          $t9, 0x70($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X70);
    // 0x80023444: jalr        $t9
    // 0x80023448: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80023448: nop

    after_6:
    // 0x8002344C: b           L_80023498
    // 0x80023450: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
        goto L_80023498;
    // 0x80023450: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
L_80023454:
    // 0x80023454: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80023458: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x8002345C: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x80023460: lbu         $t4, 0x6($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X6);
    // 0x80023464: lbu         $a2, 0x4($t5)
    ctx->r6 = MEM_BU(ctx->r13, 0X4);
    // 0x80023468: lbu         $a3, 0x5($t5)
    ctx->r7 = MEM_BU(ctx->r13, 0X5);
    // 0x8002346C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80023470: lbu         $t2, 0x7($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0X7);
    // 0x80023474: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80023478: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x8002347C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80023480: lbu         $t7, 0x31($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X31);
    // 0x80023484: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80023488: lw          $t9, 0x70($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X70);
    // 0x8002348C: jalr        $t9
    // 0x80023490: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x80023490: nop

    after_7:
    // 0x80023494: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
L_80023498:
    // 0x80023498: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x8002349C: beq         $t6, $zero, L_800234F0
    if (ctx->r14 == 0) {
        // 0x800234A0: nop
    
            goto L_800234F0;
    }
    // 0x800234A0: nop

    // 0x800234A4: addiu       $t0, $zero, 0x16
    ctx->r8 = ADD32(0, 0X16);
    // 0x800234A8: sh          $t0, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r8;
    // 0x800234AC: lw          $t3, 0xAC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XAC);
    // 0x800234B0: sw          $t3, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r11;
    // 0x800234B4: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800234B8: sw          $t4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r12;
    // 0x800234BC: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800234C0: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800234C4: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    // 0x800234C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800234CC: jal         0x80026500
    // 0x800234D0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_8;
    // 0x800234D0: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_8:
    // 0x800234D4: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x800234D8: lbu         $t2, 0x3B($t5)
    ctx->r10 = MEM_BU(ctx->r13, 0X3B);
    // 0x800234DC: ori         $t8, $t2, 0x1
    ctx->r24 = ctx->r10 | 0X1;
    // 0x800234E0: sb          $t8, 0x3B($t5)
    MEM_B(0X3B, ctx->r13) = ctx->r24;
    // 0x800234E4: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800234E8: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x800234EC: sw          $t7, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r15;
L_800234F0:
    // 0x800234F0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800234F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800234F8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800234FC: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80023500: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80023504: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80023508: nop

    // 0x8002350C: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80023510: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80023514: beq         $t6, $zero, L_80023568
    if (ctx->r14 == 0) {
        // 0x80023518: nop
    
            goto L_80023568;
    }
    // 0x80023518: nop

    // 0x8002351C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80023520: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80023524: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80023528: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8002352C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80023530: nop

    // 0x80023534: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80023538: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002353C: nop

    // 0x80023540: andi        $at, $t6, 0x4
    ctx->r1 = ctx->r14 & 0X4;
    // 0x80023544: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80023548: bne         $t6, $zero, L_80023560
    if (ctx->r14 != 0) {
        // 0x8002354C: nop
    
            goto L_80023560;
    }
    // 0x8002354C: nop

    // 0x80023550: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80023554: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80023558: b           L_80023578
    // 0x8002355C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80023578;
    // 0x8002355C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80023560:
    // 0x80023560: b           L_80023578
    // 0x80023564: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80023578;
    // 0x80023564: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80023568:
    // 0x80023568: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8002356C: nop

    // 0x80023570: bltz        $t6, L_80023560
    if (SIGNED(ctx->r14) < 0) {
        // 0x80023574: nop
    
            goto L_80023560;
    }
    // 0x80023574: nop

L_80023578:
    // 0x80023578: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x8002357C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80023580: sb          $t6, 0x3A($t0)
    MEM_B(0X3A, ctx->r8) = ctx->r14;
    // 0x80023584: nop

    // 0x80023588: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002358C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023590: nop

    // 0x80023594: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x80023598: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x8002359C: lbu         $t4, 0x24($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X24);
    // 0x800235A0: beq         $t4, $zero, L_800235B8
    if (ctx->r12 == 0) {
        // 0x800235A4: nop
    
            goto L_800235B8;
    }
    // 0x800235A4: nop

    // 0x800235A8: lw          $t2, 0xA4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA4);
    // 0x800235AC: lbu         $t8, 0x2C($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X2C);
    // 0x800235B0: b           L_800235C4
    // 0x800235B4: sw          $t8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r24;
        goto L_800235C4;
    // 0x800235B4: sw          $t8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r24;
L_800235B8:
    // 0x800235B8: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800235BC: lbu         $t7, 0x8($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X8);
    // 0x800235C0: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
L_800235C4:
    // 0x800235C4: lw          $t1, 0xA0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA0);
    // 0x800235C8: beq         $t1, $zero, L_800236D8
    if (ctx->r9 == 0) {
        // 0x800235CC: nop
    
            goto L_800236D8;
    }
    // 0x800235CC: nop

    // 0x800235D0: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x800235D4: lw          $t6, 0x70($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X70);
    // 0x800235D8: beq         $t6, $zero, L_800236D8
    if (ctx->r14 == 0) {
        // 0x800235DC: nop
    
            goto L_800236D8;
    }
    // 0x800235DC: nop

    // 0x800235E0: lw          $t0, 0xA4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA4);
    // 0x800235E4: lbu         $t3, 0x24($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X24);
    // 0x800235E8: beq         $t3, $zero, L_80023634
    if (ctx->r11 == 0) {
        // 0x800235EC: nop
    
            goto L_80023634;
    }
    // 0x800235EC: nop

    // 0x800235F0: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x800235F4: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x800235F8: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x800235FC: lbu         $t2, 0x2E($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X2E);
    // 0x80023600: lbu         $a2, 0x2C($t4)
    ctx->r6 = MEM_BU(ctx->r12, 0X2C);
    // 0x80023604: lbu         $a3, 0x2D($t4)
    ctx->r7 = MEM_BU(ctx->r12, 0X2D);
    // 0x80023608: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8002360C: lbu         $t8, 0x2F($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X2F);
    // 0x80023610: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80023614: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80023618: lbu         $t5, 0x31($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X31);
    // 0x8002361C: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80023620: lw          $t9, 0x70($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X70);
    // 0x80023624: jalr        $t9
    // 0x80023628: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x80023628: nop

    after_9:
    // 0x8002362C: b           L_80023678
    // 0x80023630: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
        goto L_80023678;
    // 0x80023630: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
L_80023634:
    // 0x80023634: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80023638: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x8002363C: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x80023640: lbu         $t6, 0xA($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XA);
    // 0x80023644: lbu         $a2, 0x8($t1)
    ctx->r6 = MEM_BU(ctx->r9, 0X8);
    // 0x80023648: lbu         $a3, 0x9($t1)
    ctx->r7 = MEM_BU(ctx->r9, 0X9);
    // 0x8002364C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80023650: lbu         $t0, 0xB($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0XB);
    // 0x80023654: addiu       $a0, $sp, 0x7C
    ctx->r4 = ADD32(ctx->r29, 0X7C);
    // 0x80023658: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x8002365C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80023660: lbu         $t2, 0x31($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X31);
    // 0x80023664: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80023668: lw          $t9, 0x70($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X70);
    // 0x8002366C: jalr        $t9
    // 0x80023670: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x80023670: nop

    after_10:
    // 0x80023674: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
L_80023678:
    // 0x80023678: lw          $t4, 0xB0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB0);
    // 0x8002367C: beq         $t4, $zero, L_800236D8
    if (ctx->r12 == 0) {
        // 0x80023680: nop
    
            goto L_800236D8;
    }
    // 0x80023680: nop

    // 0x80023684: addiu       $t5, $zero, 0x17
    ctx->r13 = ADD32(0, 0X17);
    // 0x80023688: sh          $t5, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r13;
    // 0x8002368C: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80023690: sw          $t7, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r15;
    // 0x80023694: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80023698: sw          $t6, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r14;
    // 0x8002369C: lbu         $t1, 0xD3($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XD3);
    // 0x800236A0: sb          $t1, 0xC0($sp)
    MEM_B(0XC0, ctx->r29) = ctx->r9;
    // 0x800236A4: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800236A8: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800236AC: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    // 0x800236B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800236B4: jal         0x80026500
    // 0x800236B8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_11;
    // 0x800236B8: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_11:
    // 0x800236BC: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x800236C0: lbu         $t3, 0x3B($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X3B);
    // 0x800236C4: ori         $t2, $t3, 0x2
    ctx->r10 = ctx->r11 | 0X2;
    // 0x800236C8: sb          $t2, 0x3B($t0)
    MEM_B(0X3B, ctx->r8) = ctx->r10;
    // 0x800236CC: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800236D0: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800236D4: sw          $t8, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->r24;
L_800236D8:
    // 0x800236D8: lwc1        $f16, 0x88($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800236DC: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x800236E0: swc1        $f16, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->f16.u32l;
    // 0x800236E4: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x800236E8: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x800236EC: lwc1        $f18, 0x2C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X2C);
    // 0x800236F0: lwc1        $f4, 0x14($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X14);
    // 0x800236F4: lwc1        $f8, 0x30($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X30);
    // 0x800236F8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800236FC: nop

    // 0x80023700: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80023704: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x80023708: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x8002370C: jal         0x80029E64
    // 0x80023710: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    func_80029E64(rdram, ctx);
        goto after_12;
    // 0x80023710: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    after_12:
    // 0x80023714: sb          $v0, 0x87($sp)
    MEM_B(0X87, ctx->r29) = ctx->r2;
    // 0x80023718: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x8002371C: lbu         $t1, 0x11($t6)
    ctx->r9 = MEM_BU(ctx->r14, 0X11);
    // 0x80023720: sb          $t1, 0x86($sp)
    MEM_B(0X86, ctx->r29) = ctx->r9;
    // 0x80023724: lbu         $t3, 0x86($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X86);
    // 0x80023728: beq         $t3, $zero, L_80023774
    if (ctx->r11 == 0) {
        // 0x8002372C: nop
    
            goto L_80023774;
    }
    // 0x8002372C: nop

    // 0x80023730: lh          $t2, 0x92($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X92);
    // 0x80023734: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80023738: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x8002373C: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80023740: lbu         $t9, 0x12($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X12);
    // 0x80023744: mflo        $t0
    ctx->r8 = lo;
    // 0x80023748: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    // 0x8002374C: jal         0x80028B74
    // 0x80023750: addiu       $a0, $a0, -0x40
    ctx->r4 = ADD32(ctx->r4, -0X40);
    func_80028B74(rdram, ctx);
        goto after_13;
    // 0x80023750: addiu       $a0, $a0, -0x40
    ctx->r4 = ADD32(ctx->r4, -0X40);
    after_13:
    // 0x80023754: lui         $at, 0x43DC
    ctx->r1 = S32(0X43DC << 16);
    // 0x80023758: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002375C: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x80023760: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80023764: lwc1        $f4, 0x14($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X14);
    // 0x80023768: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002376C: b           L_80023784
    // 0x80023770: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
        goto L_80023784;
    // 0x80023770: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
L_80023774:
    // 0x80023774: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80023778: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002377C: nop

    // 0x80023780: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
L_80023784:
    // 0x80023784: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x80023788: jal         0x80029FA0
    // 0x8002378C: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    func_80029FA0(rdram, ctx);
        goto after_14;
    // 0x8002378C: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    after_14:
    // 0x80023790: sb          $v0, 0xAB($sp)
    MEM_B(0XAB, ctx->r29) = ctx->r2;
    // 0x80023794: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x80023798: jal         0x80029D54
    // 0x8002379C: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    func_80029D54(rdram, ctx);
        goto after_15;
    // 0x8002379C: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    after_15:
    // 0x800237A0: sh          $v0, 0xC6($sp)
    MEM_H(0XC6, ctx->r29) = ctx->r2;
    // 0x800237A4: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x800237A8: lbu         $t5, 0x24($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X24);
    // 0x800237AC: beq         $t5, $zero, L_800237C4
    if (ctx->r13 == 0) {
        // 0x800237B0: nop
    
            goto L_800237C4;
    }
    // 0x800237B0: nop

    // 0x800237B4: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x800237B8: lw          $t1, 0x18($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X18);
    // 0x800237BC: b           L_800237D0
    // 0x800237C0: sw          $t1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r9;
        goto L_800237D0;
    // 0x800237C0: sw          $t1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r9;
L_800237C4:
    // 0x800237C4: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x800237C8: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x800237CC: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
L_800237D0:
    // 0x800237D0: lbu         $t8, 0xAB($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XAB);
    // 0x800237D4: lbu         $t0, 0x87($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X87);
    // 0x800237D8: lbu         $t9, 0x86($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X86);
    // 0x800237DC: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800237E0: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x800237E4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800237E8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800237EC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800237F0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800237F4: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x800237F8: lw          $t5, 0xB0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB0);
    // 0x800237FC: lbu         $t7, 0x13($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X13);
    // 0x80023800: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x80023804: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x80023808: lh          $a3, 0xC6($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XC6);
    // 0x8002380C: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    // 0x80023810: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x80023814: jal         0x80026CB0
    // 0x80023818: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_80026CB0(rdram, ctx);
        goto after_16;
    // 0x80023818: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_16:
    // 0x8002381C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80023820: sh          $t6, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r14;
    // 0x80023824: lw          $t1, 0xDC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XDC);
    // 0x80023828: sw          $t1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r9;
    // 0x8002382C: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x80023830: lbu         $t2, 0x24($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X24);
    // 0x80023834: beq         $t2, $zero, L_80023858
    if (ctx->r10 == 0) {
        // 0x80023838: nop
    
            goto L_80023858;
    }
    // 0x80023838: nop

    // 0x8002383C: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x80023840: lbu         $t0, 0x26($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X26);
    // 0x80023844: sb          $t0, 0xC0($sp)
    MEM_B(0XC0, ctx->r29) = ctx->r8;
    // 0x80023848: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x8002384C: lw          $t4, 0x1C($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X1C);
    // 0x80023850: b           L_80023870
    // 0x80023854: sw          $t4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r12;
        goto L_80023870;
    // 0x80023854: sw          $t4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r12;
L_80023858:
    // 0x80023858: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x8002385C: lbu         $t5, 0xD($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0XD);
    // 0x80023860: sb          $t5, 0xC0($sp)
    MEM_B(0XC0, ctx->r29) = ctx->r13;
    // 0x80023864: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x80023868: lw          $t1, 0x4($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X4);
    // 0x8002386C: sw          $t1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r9;
L_80023870:
    // 0x80023870: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80023874: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x80023878: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    // 0x8002387C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80023880: jal         0x80026500
    // 0x80023884: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_17;
    // 0x80023884: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_17:
    // 0x80023888: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x8002388C: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x80023890: beq         $t2, $zero, L_8002390C
    if (ctx->r10 == 0) {
        // 0x80023894: nop
    
            goto L_8002390C;
    }
    // 0x80023894: nop

    // 0x80023898: addiu       $t8, $zero, 0x15
    ctx->r24 = ADD32(0, 0X15);
    // 0x8002389C: sh          $t8, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r24;
    // 0x800238A0: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800238A4: sb          $t0, 0xBC($sp)
    MEM_B(0XBC, ctx->r29) = ctx->r8;
    // 0x800238A8: lbu         $t9, 0xD3($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XD3);
    // 0x800238AC: sb          $t9, 0xBD($sp)
    MEM_B(0XBD, ctx->r29) = ctx->r25;
    // 0x800238B0: lbu         $t4, 0xD2($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XD2);
    // 0x800238B4: sb          $t4, 0xBE($sp)
    MEM_B(0XBE, ctx->r29) = ctx->r12;
    // 0x800238B8: sb          $zero, 0xBF($sp)
    MEM_B(0XBF, ctx->r29) = 0;
    // 0x800238BC: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x800238C0: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800238C4: lw          $t5, 0x24($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X24);
    // 0x800238C8: lw          $t1, 0x8($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X8);
    // 0x800238CC: multu       $t5, $t1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800238D0: mflo        $t3
    ctx->r11 = lo;
    // 0x800238D4: sw          $t3, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r11;
    // 0x800238D8: nop

    // 0x800238DC: lbu         $t8, 0xD3($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD3);
    // 0x800238E0: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x800238E4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800238E8: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800238EC: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800238F0: sw          $t2, -0x15B0($at)
    MEM_W(-0X15B0, ctx->r1) = ctx->r10;
    // 0x800238F4: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800238F8: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    // 0x800238FC: lw          $a2, 0xB0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB0);
    // 0x80023900: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80023904: jal         0x80026500
    // 0x80023908: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_18;
    // 0x80023908: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_18:
L_8002390C:
    // 0x8002390C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80023910: lbu         $t4, 0x10($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X10);
    // 0x80023914: andi        $t7, $t4, 0x1
    ctx->r15 = ctx->r12 & 0X1;
    // 0x80023918: beq         $t7, $zero, L_8002396C
    if (ctx->r15 == 0) {
        // 0x8002391C: nop
    
            goto L_8002396C;
    }
    // 0x8002391C: nop

    // 0x80023920: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x80023924: lw          $t5, 0x84($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X84);
    // 0x80023928: beq         $t5, $zero, L_8002396C
    if (ctx->r13 == 0) {
        // 0x8002392C: nop
    
            goto L_8002396C;
    }
    // 0x8002392C: nop

    // 0x80023930: lbu         $t3, 0xD3($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023934: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80023938: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x8002393C: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x80023940: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x80023944: lw          $t2, -0x15B0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X15B0);
    // 0x80023948: lbu         $t4, 0x10($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X10);
    // 0x8002394C: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x80023950: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80023954: and         $t0, $t2, $at
    ctx->r8 = ctx->r10 & ctx->r1;
    // 0x80023958: sra         $t7, $t4, 2
    ctx->r15 = S32(SIGNED(ctx->r12) >> 2);
    // 0x8002395C: or          $a1, $t0, $t7
    ctx->r5 = ctx->r8 | ctx->r15;
    // 0x80023960: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80023964: jal         0x8002EAD0
    // 0x80023968: lw          $a0, 0x84($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X84);
    osSendMesg_recomp(rdram, ctx);
        goto after_19;
    // 0x80023968: lw          $a0, 0x84($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X84);
    after_19:
L_8002396C:
    // 0x8002396C: b           L_80024A3C
    // 0x80023970: nop

        goto L_80024A3C;
    // 0x80023970: nop

L_80023974:
    // 0x80023974: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80023978: lbu         $a1, 0xD2($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XD2);
    // 0x8002397C: jal         0x80029B18
    // 0x80023980: lbu         $a2, 0xD3($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD3);
    func_80029B18(rdram, ctx);
        goto after_20;
    // 0x80023980: lbu         $a2, 0xD3($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD3);
    after_20:
    // 0x80023984: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x80023988: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x8002398C: bne         $t6, $zero, L_8002399C
    if (ctx->r14 != 0) {
        // 0x80023990: nop
    
            goto L_8002399C;
    }
    // 0x80023990: nop

    // 0x80023994: b           L_80024A44
    // 0x80023998: nop

        goto L_80024A44;
    // 0x80023998: nop

L_8002399C:
    // 0x8002399C: lw          $t5, 0xE0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE0);
    // 0x800239A0: lbu         $t3, 0xD3($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XD3);
    // 0x800239A4: lw          $t1, 0x60($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X60);
    // 0x800239A8: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x800239AC: subu        $t8, $t8, $t3
    ctx->r24 = SUB32(ctx->r24, ctx->r11);
    // 0x800239B0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800239B4: addu        $t2, $t1, $t8
    ctx->r10 = ADD32(ctx->r9, ctx->r24);
    // 0x800239B8: sw          $t2, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r10;
    // 0x800239BC: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800239C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800239C4: lbu         $t4, 0x39($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X39);
    // 0x800239C8: bne         $t4, $at, L_800239E0
    if (ctx->r12 != ctx->r1) {
        // 0x800239CC: nop
    
            goto L_800239E0;
    }
    // 0x800239CC: nop

    // 0x800239D0: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800239D4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800239D8: b           L_80023A34
    // 0x800239DC: sb          $t0, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r8;
        goto L_80023A34;
    // 0x800239DC: sb          $t0, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r8;
L_800239E0:
    // 0x800239E0: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x800239E4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800239E8: sb          $t6, 0x39($t5)
    MEM_B(0X39, ctx->r13) = ctx->r14;
    // 0x800239EC: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x800239F0: lbu         $t1, 0x24($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X24);
    // 0x800239F4: beq         $t1, $zero, L_80023A1C
    if (ctx->r9 == 0) {
        // 0x800239F8: nop
    
            goto L_80023A1C;
    }
    // 0x800239F8: nop

    // 0x800239FC: lw          $a1, 0xAC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XAC);
    // 0x80023A00: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x80023A04: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80023A08: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80023A0C: jal         0x8002976C
    // 0x80023A10: lw          $a2, 0x20($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X20);
    func_8002976C(rdram, ctx);
        goto after_21;
    // 0x80023A10: lw          $a2, 0x20($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X20);
    after_21:
    // 0x80023A14: b           L_80023A34
    // 0x80023A18: nop

        goto L_80023A34;
    // 0x80023A18: nop

L_80023A1C:
    // 0x80023A1C: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80023A20: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80023A24: lw          $t9, 0x20($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X20);
    // 0x80023A28: addiu       $a1, $t2, 0x4
    ctx->r5 = ADD32(ctx->r10, 0X4);
    // 0x80023A2C: jal         0x8002976C
    // 0x80023A30: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    func_8002976C(rdram, ctx);
        goto after_22;
    // 0x80023A30: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    after_22:
L_80023A34:
    // 0x80023A34: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x80023A38: lbu         $t0, 0x10($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X10);
    // 0x80023A3C: andi        $t7, $t0, 0x2
    ctx->r15 = ctx->r8 & 0X2;
    // 0x80023A40: beq         $t7, $zero, L_80023A84
    if (ctx->r15 == 0) {
        // 0x80023A44: nop
    
            goto L_80023A84;
    }
    // 0x80023A44: nop

    // 0x80023A48: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x80023A4C: lw          $t5, 0x84($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X84);
    // 0x80023A50: beq         $t5, $zero, L_80023A84
    if (ctx->r13 == 0) {
        // 0x80023A54: nop
    
            goto L_80023A84;
    }
    // 0x80023A54: nop

    // 0x80023A58: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80023A5C: lbu         $t1, 0xD2($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XD2);
    // 0x80023A60: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x80023A64: lbu         $t4, 0x10($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X10);
    // 0x80023A68: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x80023A6C: ori         $t2, $t8, 0x8
    ctx->r10 = ctx->r24 | 0X8;
    // 0x80023A70: sra         $t0, $t4, 2
    ctx->r8 = S32(SIGNED(ctx->r12) >> 2);
    // 0x80023A74: or          $a1, $t2, $t0
    ctx->r5 = ctx->r10 | ctx->r8;
    // 0x80023A78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80023A7C: jal         0x8002EAD0
    // 0x80023A80: lw          $a0, 0x84($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X84);
    osSendMesg_recomp(rdram, ctx);
        goto after_23;
    // 0x80023A80: lw          $a0, 0x84($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X84);
    after_23:
L_80023A84:
    // 0x80023A84: b           L_80024A3C
    // 0x80023A88: nop

        goto L_80024A3C;
    // 0x80023A88: nop

L_80023A8C:
    // 0x80023A8C: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80023A90: lbu         $a1, 0xD2($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XD2);
    // 0x80023A94: jal         0x80029B18
    // 0x80023A98: lbu         $a2, 0xD3($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD3);
    func_80029B18(rdram, ctx);
        goto after_24;
    // 0x80023A98: lbu         $a2, 0xD3($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD3);
    after_24:
    // 0x80023A9C: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x80023AA0: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80023AA4: bne         $t7, $zero, L_80023AB4
    if (ctx->r15 != 0) {
        // 0x80023AA8: nop
    
            goto L_80023AB4;
    }
    // 0x80023AA8: nop

    // 0x80023AAC: b           L_80024A44
    // 0x80023AB0: nop

        goto L_80024A44;
    // 0x80023AB0: nop

L_80023AB4:
    // 0x80023AB4: lbu         $t6, 0xCF($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XCF);
    // 0x80023AB8: lw          $t5, 0xAC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XAC);
    // 0x80023ABC: sb          $t6, 0x37($t5)
    MEM_B(0X37, ctx->r13) = ctx->r14;
    // 0x80023AC0: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x80023AC4: jal         0x80029D54
    // 0x80023AC8: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    func_80029D54(rdram, ctx);
        goto after_25;
    // 0x80023AC8: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    after_25:
    // 0x80023ACC: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x80023AD0: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80023AD4: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80023AD8: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x80023ADC: jal         0x80029F5C
    // 0x80023AE0: lw          $a1, 0x1C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X1C);
    func_80029F5C(rdram, ctx);
        goto after_26;
    // 0x80023AE0: lw          $a1, 0x1C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X1C);
    after_26:
    // 0x80023AE4: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x80023AE8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80023AEC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80023AF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80023AF4: jal         0x80026BE0
    // 0x80023AF8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80026BE0(rdram, ctx);
        goto after_27;
    // 0x80023AF8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_27:
    // 0x80023AFC: b           L_80024A3C
    // 0x80023B00: nop

        goto L_80024A3C;
    // 0x80023B00: nop

L_80023B04:
    // 0x80023B04: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x80023B08: lw          $t8, 0x64($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X64);
    // 0x80023B0C: beq         $t8, $zero, L_80023B80
    if (ctx->r24 == 0) {
        // 0x80023B10: sw          $t8, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r24;
            goto L_80023B80;
    }
    // 0x80023B10: sw          $t8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r24;
L_80023B14:
    // 0x80023B14: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x80023B18: lbu         $t2, 0xD3($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023B1C: lbu         $t4, 0x35($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X35);
    // 0x80023B20: bne         $t4, $t2, L_80023B70
    if (ctx->r12 != ctx->r10) {
        // 0x80023B24: nop
    
            goto L_80023B70;
    }
    // 0x80023B24: nop

    // 0x80023B28: lbu         $t0, 0xD0($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XD0);
    // 0x80023B2C: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x80023B30: sb          $t0, 0x37($t7)
    MEM_B(0X37, ctx->r15) = ctx->r8;
    // 0x80023B34: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x80023B38: jal         0x80029D54
    // 0x80023B3C: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    func_80029D54(rdram, ctx);
        goto after_28;
    // 0x80023B3C: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    after_28:
    // 0x80023B40: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x80023B44: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x80023B48: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80023B4C: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x80023B50: jal         0x80029F5C
    // 0x80023B54: lw          $a1, 0x1C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X1C);
    func_80029F5C(rdram, ctx);
        goto after_29;
    // 0x80023B54: lw          $a1, 0x1C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X1C);
    after_29:
    // 0x80023B58: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x80023B5C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80023B60: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80023B64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80023B68: jal         0x80026BE0
    // 0x80023B6C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80026BE0(rdram, ctx);
        goto after_30;
    // 0x80023B6C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_30:
L_80023B70:
    // 0x80023B70: lw          $t5, 0xD8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD8);
    // 0x80023B74: lw          $t3, 0x0($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X0);
    // 0x80023B78: bne         $t3, $zero, L_80023B14
    if (ctx->r11 != 0) {
        // 0x80023B7C: sw          $t3, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r11;
            goto L_80023B14;
    }
    // 0x80023B7C: sw          $t3, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r11;
L_80023B80:
    // 0x80023B80: b           L_80024A3C
    // 0x80023B84: nop

        goto L_80024A3C;
    // 0x80023B84: nop

L_80023B88:
    // 0x80023B88: lbu         $s0, 0xD0($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0XD0);
    // 0x80023B8C: slti        $at, $s0, 0xFD
    ctx->r1 = SIGNED(ctx->r16) < 0XFD ? 1 : 0;
    // 0x80023B90: bne         $at, $zero, L_80023BC4
    if (ctx->r1 != 0) {
        // 0x80023B94: nop
    
            goto L_80023BC4;
    }
    // 0x80023B94: nop

    // 0x80023B98: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x80023B9C: beq         $s0, $at, L_80023CB8
    if (ctx->r16 == ctx->r1) {
        // 0x80023BA0: nop
    
            goto L_80023CB8;
    }
    // 0x80023BA0: nop

    // 0x80023BA4: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x80023BA8: beq         $s0, $at, L_80023EB8
    if (ctx->r16 == ctx->r1) {
        // 0x80023BAC: nop
    
            goto L_80023EB8;
    }
    // 0x80023BAC: nop

    // 0x80023BB0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80023BB4: beq         $s0, $at, L_80023CE4
    if (ctx->r16 == ctx->r1) {
        // 0x80023BB8: nop
    
            goto L_80023CE4;
    }
    // 0x80023BB8: nop

    // 0x80023BBC: b           L_8002482C
    // 0x80023BC0: nop

        goto L_8002482C;
    // 0x80023BC0: nop

L_80023BC4:
    // 0x80023BC4: slti        $at, $s0, 0x5C
    ctx->r1 = SIGNED(ctx->r16) < 0X5C ? 1 : 0;
    // 0x80023BC8: bne         $at, $zero, L_80023BF0
    if (ctx->r1 != 0) {
        // 0x80023BCC: nop
    
            goto L_80023BF0;
    }
    // 0x80023BCC: nop

    // 0x80023BD0: addiu       $at, $zero, 0x5C
    ctx->r1 = ADD32(0, 0X5C);
    // 0x80023BD4: beq         $s0, $at, L_800246DC
    if (ctx->r16 == ctx->r1) {
        // 0x80023BD8: nop
    
            goto L_800246DC;
    }
    // 0x80023BD8: nop

    // 0x80023BDC: addiu       $at, $zero, 0xFC
    ctx->r1 = ADD32(0, 0XFC);
    // 0x80023BE0: beq         $s0, $at, L_8002418C
    if (ctx->r16 == ctx->r1) {
        // 0x80023BE4: nop
    
            goto L_8002418C;
    }
    // 0x80023BE4: nop

    // 0x80023BE8: b           L_8002482C
    // 0x80023BEC: nop

        goto L_8002482C;
    // 0x80023BEC: nop

L_80023BF0:
    // 0x80023BF0: slti        $at, $s0, 0x42
    ctx->r1 = SIGNED(ctx->r16) < 0X42 ? 1 : 0;
    // 0x80023BF4: bne         $at, $zero, L_80023C10
    if (ctx->r1 != 0) {
        // 0x80023BF8: nop
    
            goto L_80023C10;
    }
    // 0x80023BF8: nop

    // 0x80023BFC: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x80023C00: beq         $s0, $at, L_800245D8
    if (ctx->r16 == ctx->r1) {
        // 0x80023C04: nop
    
            goto L_800245D8;
    }
    // 0x80023C04: nop

    // 0x80023C08: b           L_8002482C
    // 0x80023C0C: nop

        goto L_8002482C;
    // 0x80023C0C: nop

L_80023C10:
    // 0x80023C10: addiu       $t1, $s0, -0x7
    ctx->r9 = ADD32(ctx->r16, -0X7);
    // 0x80023C14: sltiu       $at, $t1, 0x3B
    ctx->r1 = ctx->r9 < 0X3B ? 1 : 0;
    // 0x80023C18: beq         $at, $zero, L_8002482C
    if (ctx->r1 == 0) {
        // 0x80023C1C: nop
    
            goto L_8002482C;
    }
    // 0x80023C1C: nop

    // 0x80023C20: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80023C24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80023C28: addu        $at, $at, $t1
    gpr jr_addend_80023C30 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80023C2C: lw          $t1, 0x1BDC($at)
    ctx->r9 = ADD32(ctx->r1, 0X1BDC);
    // 0x80023C30: jr          $t1
    // 0x80023C34: nop

    switch (jr_addend_80023C30 >> 2) {
        case 0: goto L_80024360; break;
        case 1: goto L_8002482C; break;
        case 2: goto L_8002482C; break;
        case 3: goto L_80023C38; break;
        case 4: goto L_8002482C; break;
        case 5: goto L_8002482C; break;
        case 6: goto L_8002482C; break;
        case 7: goto L_8002482C; break;
        case 8: goto L_8002482C; break;
        case 9: goto L_80024408; break;
        case 10: goto L_8002482C; break;
        case 11: goto L_8002482C; break;
        case 12: goto L_8002482C; break;
        case 13: goto L_8002482C; break;
        case 14: goto L_8002482C; break;
        case 15: goto L_8002482C; break;
        case 16: goto L_8002482C; break;
        case 17: goto L_8002482C; break;
        case 18: goto L_8002482C; break;
        case 19: goto L_80024724; break;
        case 20: goto L_8002482C; break;
        case 21: goto L_8002482C; break;
        case 22: goto L_8002482C; break;
        case 23: goto L_80024318; break;
        case 24: goto L_8002482C; break;
        case 25: goto L_8002472C; break;
        case 26: goto L_80024238; break;
        case 27: goto L_80024270; break;
        case 28: goto L_800242A8; break;
        case 29: goto L_8002482C; break;
        case 30: goto L_8002482C; break;
        case 31: goto L_8002482C; break;
        case 32: goto L_8002482C; break;
        case 33: goto L_8002482C; break;
        case 34: goto L_80024758; break;
        case 35: goto L_8002482C; break;
        case 36: goto L_8002482C; break;
        case 37: goto L_8002482C; break;
        case 38: goto L_8002482C; break;
        case 39: goto L_8002482C; break;
        case 40: goto L_8002482C; break;
        case 41: goto L_8002482C; break;
        case 42: goto L_8002482C; break;
        case 43: goto L_8002482C; break;
        case 44: goto L_8002482C; break;
        case 45: goto L_8002482C; break;
        case 46: goto L_8002482C; break;
        case 47: goto L_8002482C; break;
        case 48: goto L_8002482C; break;
        case 49: goto L_8002482C; break;
        case 50: goto L_8002482C; break;
        case 51: goto L_8002482C; break;
        case 52: goto L_8002482C; break;
        case 53: goto L_8002482C; break;
        case 54: goto L_8002482C; break;
        case 55: goto L_8002482C; break;
        case 56: goto L_8002482C; break;
        case 57: goto L_80024434; break;
        case 58: goto L_80024630; break;
        default: switch_error(__func__, 0x80023C30, 0x80041BDC);
    }
    // 0x80023C34: nop

L_80023C38:
    // 0x80023C38: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x80023C3C: lbu         $t2, 0xD3($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023C40: lbu         $t8, 0xCF($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XCF);
    // 0x80023C44: lw          $t4, 0x60($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X60);
    // 0x80023C48: sll         $t0, $t2, 3
    ctx->r8 = S32(ctx->r10 << 3);
    // 0x80023C4C: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x80023C50: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80023C54: addu        $t7, $t4, $t0
    ctx->r15 = ADD32(ctx->r12, ctx->r8);
    // 0x80023C58: sb          $t8, 0x3($t7)
    MEM_B(0X3, ctx->r15) = ctx->r24;
    // 0x80023C5C: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x80023C60: lw          $t5, 0x64($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X64);
    // 0x80023C64: beq         $t5, $zero, L_80023CB0
    if (ctx->r13 == 0) {
        // 0x80023C68: sw          $t5, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r13;
            goto L_80023CB0;
    }
    // 0x80023C68: sw          $t5, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r13;
L_80023C6C:
    // 0x80023C6C: lw          $t3, 0xD8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD8);
    // 0x80023C70: lbu         $t9, 0xD3($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023C74: lbu         $t1, 0x35($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X35);
    // 0x80023C78: bne         $t1, $t9, L_80023CA0
    if (ctx->r9 != ctx->r25) {
        // 0x80023C7C: nop
    
            goto L_80023CA0;
    }
    // 0x80023C7C: nop

    // 0x80023C80: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x80023C84: jal         0x80029FA0
    // 0x80023C88: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    func_80029FA0(rdram, ctx);
        goto after_31;
    // 0x80023C88: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    after_31:
    // 0x80023C8C: sb          $v0, 0xAB($sp)
    MEM_B(0XAB, ctx->r29) = ctx->r2;
    // 0x80023C90: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x80023C94: lbu         $a1, 0xAB($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XAB);
    // 0x80023C98: jal         0x80026DE0
    // 0x80023C9C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80026DE0(rdram, ctx);
        goto after_32;
    // 0x80023C9C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_32:
L_80023CA0:
    // 0x80023CA0: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
    // 0x80023CA4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80023CA8: bne         $t4, $zero, L_80023C6C
    if (ctx->r12 != 0) {
        // 0x80023CAC: sw          $t4, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r12;
            goto L_80023C6C;
    }
    // 0x80023CAC: sw          $t4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r12;
L_80023CB0:
    // 0x80023CB0: b           L_80024834
    // 0x80023CB4: nop

        goto L_80024834;
    // 0x80023CB4: nop

L_80023CB8:
    // 0x80023CB8: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x80023CBC: lbu         $t6, 0xD3($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023CC0: lbu         $t0, 0xCF($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XCF);
    // 0x80023CC4: lw          $t7, 0x60($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X60);
    // 0x80023CC8: sll         $t5, $t6, 3
    ctx->r13 = S32(ctx->r14 << 3);
    // 0x80023CCC: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x80023CD0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80023CD4: addu        $t3, $t7, $t5
    ctx->r11 = ADD32(ctx->r15, ctx->r13);
    // 0x80023CD8: sb          $t0, 0xB($t3)
    MEM_B(0XB, ctx->r11) = ctx->r8;
    // 0x80023CDC: b           L_80024834
    // 0x80023CE0: nop

        goto L_80024834;
    // 0x80023CE0: nop

L_80023CE4:
    // 0x80023CE4: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x80023CE8: lbu         $t2, 0xD3($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023CEC: lw          $t9, 0x60($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X60);
    // 0x80023CF0: sll         $t4, $t2, 3
    ctx->r12 = S32(ctx->r10 << 3);
    // 0x80023CF4: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x80023CF8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80023CFC: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x80023D00: lbu         $t6, 0xB($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0XB);
    // 0x80023D04: bne         $t6, $zero, L_80023D30
    if (ctx->r14 != 0) {
        // 0x80023D08: nop
    
            goto L_80023D30;
    }
    // 0x80023D08: nop

    // 0x80023D0C: lw          $t5, 0xE0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE0);
    // 0x80023D10: lbu         $t3, 0xD3($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023D14: addiu       $t7, $zero, 0x88
    ctx->r15 = ADD32(0, 0X88);
    // 0x80023D18: lw          $t0, 0x60($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X60);
    // 0x80023D1C: sll         $t1, $t3, 3
    ctx->r9 = S32(ctx->r11 << 3);
    // 0x80023D20: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x80023D24: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80023D28: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80023D2C: sb          $t7, 0xB($t2)
    MEM_B(0XB, ctx->r10) = ctx->r15;
L_80023D30:
    // 0x80023D30: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x80023D34: lbu         $t8, 0xD3($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023D38: lbu         $t0, 0xCF($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XCF);
    // 0x80023D3C: lw          $t4, 0x60($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X60);
    // 0x80023D40: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x80023D44: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x80023D48: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80023D4C: addu        $t5, $t4, $t6
    ctx->r13 = ADD32(ctx->r12, ctx->r14);
    // 0x80023D50: lbu         $t3, 0xA($t5)
    ctx->r11 = MEM_BU(ctx->r13, 0XA);
    // 0x80023D54: beq         $t3, $t0, L_80023EA4
    if (ctx->r11 == ctx->r8) {
        // 0x80023D58: nop
    
            goto L_80023EA4;
    }
    // 0x80023D58: nop

    // 0x80023D5C: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x80023D60: lbu         $t2, 0xD3($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023D64: lbu         $t6, 0xCF($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XCF);
    // 0x80023D68: lw          $t7, 0x60($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X60);
    // 0x80023D6C: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x80023D70: subu        $t9, $t9, $t2
    ctx->r25 = SUB32(ctx->r25, ctx->r10);
    // 0x80023D74: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80023D78: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80023D7C: lbu         $t4, 0x9($t8)
    ctx->r12 = MEM_BU(ctx->r24, 0X9);
    // 0x80023D80: subu        $t5, $t6, $t4
    ctx->r13 = SUB32(ctx->r14, ctx->r12);
    // 0x80023D84: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x80023D88: nop

    // 0x80023D8C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80023D90: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x80023D94: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x80023D98: lbu         $t1, 0xD3($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023D9C: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80023DA0: lw          $t0, 0x60($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X60);
    // 0x80023DA4: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80023DA8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80023DAC: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80023DB0: addu        $t7, $t0, $t2
    ctx->r15 = ADD32(ctx->r8, ctx->r10);
    // 0x80023DB4: lbu         $t9, 0xB($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0XB);
    // 0x80023DB8: andi        $t8, $t9, 0x7F
    ctx->r24 = ctx->r25 & 0X7F;
    // 0x80023DBC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80023DC0: nop

    // 0x80023DC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80023DC8: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80023DCC: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x80023DD0: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80023DD4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80023DD8: nop

    // 0x80023DDC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80023DE0: nop

    // 0x80023DE4: bc1f        L_80023DF8
    if (!c1cs) {
        // 0x80023DE8: nop
    
            goto L_80023DF8;
    }
    // 0x80023DE8: nop

    // 0x80023DEC: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80023DF0: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x80023DF4: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
L_80023DF8:
    // 0x80023DF8: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x80023DFC: lbu         $t5, 0xD3($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023E00: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80023E04: lw          $t4, 0x60($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X60);
    // 0x80023E08: sll         $t3, $t5, 3
    ctx->r11 = S32(ctx->r13 << 3);
    // 0x80023E0C: subu        $t3, $t3, $t5
    ctx->r11 = SUB32(ctx->r11, ctx->r13);
    // 0x80023E10: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80023E14: addu        $t1, $t4, $t3
    ctx->r9 = ADD32(ctx->r12, ctx->r11);
    // 0x80023E18: swc1        $f6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f6.u32l;
    // 0x80023E1C: lw          $t0, 0xE0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE0);
    // 0x80023E20: lbu         $t7, 0xD3($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023E24: lw          $t2, 0x60($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X60);
    // 0x80023E28: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x80023E2C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x80023E30: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80023E34: addu        $t8, $t2, $t9
    ctx->r24 = ADD32(ctx->r10, ctx->r25);
    // 0x80023E38: lbu         $t6, 0x9($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X9);
    // 0x80023E3C: lbu         $t5, 0xA($t8)
    ctx->r13 = MEM_BU(ctx->r24, 0XA);
    // 0x80023E40: bne         $t6, $t5, L_80023E70
    if (ctx->r14 != ctx->r13) {
        // 0x80023E44: nop
    
            goto L_80023E70;
    }
    // 0x80023E44: nop

    // 0x80023E48: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x80023E4C: lbu         $t0, 0xD3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023E50: lbu         $t4, 0xCF($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XCF);
    // 0x80023E54: lw          $t1, 0x60($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X60);
    // 0x80023E58: sll         $t7, $t0, 3
    ctx->r15 = S32(ctx->r8 << 3);
    // 0x80023E5C: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80023E60: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80023E64: addu        $t2, $t1, $t7
    ctx->r10 = ADD32(ctx->r9, ctx->r15);
    // 0x80023E68: b           L_80023E9C
    // 0x80023E6C: sb          $t4, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r12;
        goto L_80023E9C;
    // 0x80023E6C: sb          $t4, 0xA($t2)
    MEM_B(0XA, ctx->r10) = ctx->r12;
L_80023E70:
    // 0x80023E70: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x80023E74: lbu         $t5, 0xD3($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023E78: lbu         $t9, 0xCF($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XCF);
    // 0x80023E7C: lw          $t6, 0x60($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X60);
    // 0x80023E80: sll         $t3, $t5, 3
    ctx->r11 = S32(ctx->r13 << 3);
    // 0x80023E84: subu        $t3, $t3, $t5
    ctx->r11 = SUB32(ctx->r11, ctx->r13);
    // 0x80023E88: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80023E8C: addu        $t0, $t6, $t3
    ctx->r8 = ADD32(ctx->r14, ctx->r11);
    // 0x80023E90: sb          $t9, 0xA($t0)
    MEM_B(0XA, ctx->r8) = ctx->r25;
    // 0x80023E94: b           L_80024834
    // 0x80023E98: nop

        goto L_80024834;
    // 0x80023E98: nop

L_80023E9C:
    // 0x80023E9C: b           L_80023EAC
    // 0x80023EA0: nop

        goto L_80023EAC;
    // 0x80023EA0: nop

L_80023EA4:
    // 0x80023EA4: b           L_80024834
    // 0x80023EA8: nop

        goto L_80024834;
    // 0x80023EA8: nop

L_80023EAC:
    // 0x80023EAC: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x80023EB0: addiu       $t1, $zero, 0xFE
    ctx->r9 = ADD32(0, 0XFE);
    // 0x80023EB4: sb          $t1, 0x6($t7)
    MEM_B(0X6, ctx->r15) = ctx->r9;
L_80023EB8:
    // 0x80023EB8: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x80023EBC: lbu         $t8, 0xD3($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023EC0: lw          $t2, 0x60($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X60);
    // 0x80023EC4: sll         $t5, $t8, 3
    ctx->r13 = S32(ctx->r24 << 3);
    // 0x80023EC8: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x80023ECC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80023ED0: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80023ED4: lbu         $t3, 0x9($t6)
    ctx->r11 = MEM_BU(ctx->r14, 0X9);
    // 0x80023ED8: sb          $t3, 0x6F($sp)
    MEM_B(0X6F, ctx->r29) = ctx->r11;
    // 0x80023EDC: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x80023EE0: lbu         $t1, 0xD3($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023EE4: lw          $t0, 0x60($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X60);
    // 0x80023EE8: sll         $t7, $t1, 3
    ctx->r15 = S32(ctx->r9 << 3);
    // 0x80023EEC: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x80023EF0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80023EF4: addu        $t4, $t0, $t7
    ctx->r12 = ADD32(ctx->r8, ctx->r15);
    // 0x80023EF8: lbu         $t8, 0xA($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0XA);
    // 0x80023EFC: sb          $t8, 0x6E($sp)
    MEM_B(0X6E, ctx->r29) = ctx->r24;
    // 0x80023F00: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x80023F04: lbu         $t6, 0xD3($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023F08: lw          $t5, 0x60($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X60);
    // 0x80023F0C: sll         $t3, $t6, 3
    ctx->r11 = S32(ctx->r14 << 3);
    // 0x80023F10: subu        $t3, $t3, $t6
    ctx->r11 = SUB32(ctx->r11, ctx->r14);
    // 0x80023F14: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80023F18: addu        $t9, $t5, $t3
    ctx->r25 = ADD32(ctx->r13, ctx->r11);
    // 0x80023F1C: lwc1        $f10, 0xC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80023F20: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x80023F24: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x80023F28: lbu         $t7, 0xD3($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023F2C: lw          $t0, 0x60($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X60);
    // 0x80023F30: sll         $t4, $t7, 3
    ctx->r12 = S32(ctx->r15 << 3);
    // 0x80023F34: subu        $t4, $t4, $t7
    ctx->r12 = SUB32(ctx->r12, ctx->r15);
    // 0x80023F38: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80023F3C: addu        $t8, $t0, $t4
    ctx->r24 = ADD32(ctx->r8, ctx->r12);
    // 0x80023F40: lbu         $t2, 0xB($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0XB);
    // 0x80023F44: sb          $t2, 0xD1($sp)
    MEM_B(0XD1, ctx->r29) = ctx->r10;
    // 0x80023F48: lbu         $t6, 0x6E($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X6E);
    // 0x80023F4C: lbu         $t5, 0x6F($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X6F);
    // 0x80023F50: subu        $t3, $t6, $t5
    ctx->r11 = SUB32(ctx->r14, ctx->r13);
    // 0x80023F54: sw          $t3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r11;
    // 0x80023F58: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80023F5C: blez        $t9, L_80024024
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80023F60: nop
    
            goto L_80024024;
    }
    // 0x80023F60: nop

    // 0x80023F64: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x80023F68: lbu         $t0, 0xD3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XD3);
    // 0x80023F6C: lw          $t7, 0x60($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X60);
    // 0x80023F70: sll         $t4, $t0, 3
    ctx->r12 = S32(ctx->r8 << 3);
    // 0x80023F74: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x80023F78: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80023F7C: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80023F80: lbu         $t2, 0xB($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0XB);
    // 0x80023F84: andi        $t6, $t2, 0x80
    ctx->r14 = ctx->r10 & 0X80;
    // 0x80023F88: beq         $t6, $zero, L_80023FA4
    if (ctx->r14 == 0) {
        // 0x80023F8C: nop
    
            goto L_80023FA4;
    }
    // 0x80023F8C: nop

    // 0x80023F90: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80023F94: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80023F98: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80023F9C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80023FA0: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
L_80023FA4:
    // 0x80023FA4: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80023FA8: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80023FAC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80023FB0: nop

    // 0x80023FB4: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x80023FB8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80023FBC: bne         $t9, $zero, L_80023FE4
    if (ctx->r25 != 0) {
        // 0x80023FC0: nop
    
            goto L_80023FE4;
    }
    // 0x80023FC0: nop

    // 0x80023FC4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80023FC8: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80023FCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80023FD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80023FD4: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80023FD8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80023FDC: b           L_80024000
    // 0x80023FE0: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
        goto L_80024000;
    // 0x80023FE0: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
L_80023FE4:
    // 0x80023FE4: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80023FE8: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80023FEC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80023FF0: nop

    // 0x80023FF4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80023FF8: div.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80023FFC: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
L_80024000:
    // 0x80024000: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80024004: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80024008: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002400C: beq         $at, $zero, L_8002401C
    if (ctx->r1 == 0) {
        // 0x80024010: nop
    
            goto L_8002401C;
    }
    // 0x80024010: nop

    // 0x80024014: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80024018: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
L_8002401C:
    // 0x8002401C: b           L_8002409C
    // 0x80024020: nop

        goto L_8002409C;
    // 0x80024020: nop

L_80024024:
    // 0x80024024: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80024028: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8002402C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80024030: nop

    // 0x80024034: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x80024038: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8002403C: bne         $t5, $zero, L_80024058
    if (ctx->r13 != 0) {
        // 0x80024040: nop
    
            goto L_80024058;
    }
    // 0x80024040: nop

    // 0x80024044: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80024048: sw          $t3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r11;
    // 0x8002404C: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80024050: b           L_80024074
    // 0x80024054: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
        goto L_80024074;
    // 0x80024054: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
L_80024058:
    // 0x80024058: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8002405C: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80024060: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80024064: nop

    // 0x80024068: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002406C: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80024070: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
L_80024074:
    // 0x80024074: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80024078: negu        $t0, $t1
    ctx->r8 = SUB32(0, ctx->r9);
    // 0x8002407C: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x80024080: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80024084: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80024088: slt         $at, $t7, $t4
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002408C: beq         $at, $zero, L_8002409C
    if (ctx->r1 == 0) {
        // 0x80024090: nop
    
            goto L_8002409C;
    }
    // 0x80024090: nop

    // 0x80024094: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80024098: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
L_8002409C:
    // 0x8002409C: lbu         $t2, 0x6F($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X6F);
    // 0x800240A0: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800240A4: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x800240A8: sb          $t5, 0x6F($sp)
    MEM_B(0X6F, ctx->r29) = ctx->r13;
    // 0x800240AC: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x800240B0: lbu         $t0, 0xD3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XD3);
    // 0x800240B4: lbu         $t3, 0x6F($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X6F);
    // 0x800240B8: lw          $t1, 0x60($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X60);
    // 0x800240BC: sll         $t7, $t0, 3
    ctx->r15 = S32(ctx->r8 << 3);
    // 0x800240C0: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x800240C4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800240C8: addu        $t4, $t1, $t7
    ctx->r12 = ADD32(ctx->r9, ctx->r15);
    // 0x800240CC: sb          $t3, 0x9($t4)
    MEM_B(0X9, ctx->r12) = ctx->r11;
    // 0x800240D0: lbu         $t8, 0x6F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X6F);
    // 0x800240D4: lbu         $t2, 0x6E($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X6E);
    // 0x800240D8: beq         $t8, $t2, L_8002412C
    if (ctx->r24 == ctx->r10) {
        // 0x800240DC: nop
    
            goto L_8002412C;
    }
    // 0x800240DC: nop

    // 0x800240E0: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x800240E4: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800240E8: lw          $a1, 0xE4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE4);
    // 0x800240EC: lw          $t5, 0x24($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X24);
    // 0x800240F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800240F4: addiu       $a0, $t6, 0x48
    ctx->r4 = ADD32(ctx->r14, 0X48);
    // 0x800240F8: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800240FC: subu        $t9, $t9, $t5
    ctx->r25 = SUB32(ctx->r25, ctx->r13);
    // 0x80024100: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80024104: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80024108: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002410C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80024110: nop

    // 0x80024114: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80024118: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8002411C: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80024120: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80024124: jal         0x80026500
    // 0x80024128: nop

    func_80026500(rdram, ctx);
        goto after_33;
    // 0x80024128: nop

    after_33:
L_8002412C:
    // 0x8002412C: lbu         $t1, 0x6F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X6F);
    // 0x80024130: beq         $t1, $zero, L_80024158
    if (ctx->r9 == 0) {
        // 0x80024134: nop
    
            goto L_80024158;
    }
    // 0x80024134: nop

    // 0x80024138: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x8002413C: lbu         $t4, 0xD3($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024140: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80024144: lw          $t3, 0x30($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X30);
    // 0x80024148: sllv        $t2, $t8, $t4
    ctx->r10 = S32(ctx->r24 << (ctx->r12 & 31));
    // 0x8002414C: or          $t6, $t3, $t2
    ctx->r14 = ctx->r11 | ctx->r10;
    // 0x80024150: b           L_80024178
    // 0x80024154: sw          $t6, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r14;
        goto L_80024178;
    // 0x80024154: sw          $t6, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r14;
L_80024158:
    // 0x80024158: lw          $t5, 0xE0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE0);
    // 0x8002415C: lbu         $t0, 0xD3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024160: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80024164: lw          $t9, 0x30($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X30);
    // 0x80024168: sllv        $t8, $t1, $t0
    ctx->r24 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x8002416C: nor         $t4, $t8, $zero
    ctx->r12 = ~(ctx->r24 | 0);
    // 0x80024170: and         $t3, $t9, $t4
    ctx->r11 = ctx->r25 & ctx->r12;
    // 0x80024174: sw          $t3, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->r11;
L_80024178:
    // 0x80024178: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x8002417C: jal         0x80022E20
    // 0x80024180: lbu         $a1, 0xD3($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XD3);
    func_80022E20(rdram, ctx);
        goto after_34;
    // 0x80024180: lbu         $a1, 0xD3($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XD3);
    after_34:
    // 0x80024184: b           L_80024834
    // 0x80024188: nop

        goto L_80024834;
    // 0x80024188: nop

L_8002418C:
    // 0x8002418C: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x80024190: lbu         $t1, 0xD3($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024194: lbu         $t2, 0xCF($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XCF);
    // 0x80024198: lw          $t7, 0x60($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X60);
    // 0x8002419C: sll         $t0, $t1, 3
    ctx->r8 = S32(ctx->r9 << 3);
    // 0x800241A0: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x800241A4: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800241A8: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x800241AC: sb          $t2, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r10;
    // 0x800241B0: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x800241B4: lbu         $t5, 0xD3($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XD3);
    // 0x800241B8: lbu         $t9, 0xCF($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XCF);
    // 0x800241BC: lw          $t3, 0x60($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X60);
    // 0x800241C0: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800241C4: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x800241C8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800241CC: addu        $t1, $t3, $t6
    ctx->r9 = ADD32(ctx->r11, ctx->r14);
    // 0x800241D0: sb          $t9, 0xA($t1)
    MEM_B(0XA, ctx->r9) = ctx->r25;
    // 0x800241D4: lbu         $t7, 0xCF($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XCF);
    // 0x800241D8: bne         $t7, $zero, L_80024208
    if (ctx->r15 != 0) {
        // 0x800241DC: nop
    
            goto L_80024208;
    }
    // 0x800241DC: nop

    // 0x800241E0: lw          $t0, 0xE0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE0);
    // 0x800241E4: lbu         $t8, 0xD3($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD3);
    // 0x800241E8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800241EC: lw          $t2, 0x30($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X30);
    // 0x800241F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800241F4: sllv        $t5, $t4, $t8
    ctx->r13 = S32(ctx->r12 << (ctx->r24 & 31));
    // 0x800241F8: xor         $t3, $t5, $at
    ctx->r11 = ctx->r13 ^ ctx->r1;
    // 0x800241FC: and         $t6, $t2, $t3
    ctx->r14 = ctx->r10 & ctx->r11;
    // 0x80024200: b           L_80024224
    // 0x80024204: sw          $t6, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r14;
        goto L_80024224;
    // 0x80024204: sw          $t6, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r14;
L_80024208:
    // 0x80024208: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8002420C: lbu         $t7, 0xD3($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024210: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80024214: lw          $t1, 0x30($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X30);
    // 0x80024218: sllv        $t8, $t4, $t7
    ctx->r24 = S32(ctx->r12 << (ctx->r15 & 31));
    // 0x8002421C: or          $t5, $t1, $t8
    ctx->r13 = ctx->r9 | ctx->r24;
    // 0x80024220: sw          $t5, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r13;
L_80024224:
    // 0x80024224: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80024228: jal         0x80022E20
    // 0x8002422C: lbu         $a1, 0xD3($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XD3);
    func_80022E20(rdram, ctx);
        goto after_35;
    // 0x8002422C: lbu         $a1, 0xD3($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XD3);
    after_35:
    // 0x80024230: b           L_80024834
    // 0x80024234: nop

        goto L_80024834;
    // 0x80024234: nop

L_80024238:
    // 0x80024238: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x8002423C: lbu         $t0, 0xD3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024240: lbu         $t2, 0xCF($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XCF);
    // 0x80024244: lw          $t6, 0x60($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X60);
    // 0x80024248: sll         $t4, $t0, 3
    ctx->r12 = S32(ctx->r8 << 3);
    // 0x8002424C: subu        $t4, $t4, $t0
    ctx->r12 = SUB32(ctx->r12, ctx->r8);
    // 0x80024250: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80024254: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x80024258: sb          $t2, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r10;
    // 0x8002425C: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80024260: jal         0x80022ECC
    // 0x80024264: lbu         $a1, 0xD3($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XD3);
    func_80022ECC(rdram, ctx);
        goto after_36;
    // 0x80024264: lbu         $a1, 0xD3($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XD3);
    after_36:
    // 0x80024268: b           L_80024834
    // 0x8002426C: nop

        goto L_80024834;
    // 0x8002426C: nop

L_80024270:
    // 0x80024270: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x80024274: lbu         $t9, 0xD3($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024278: lbu         $t1, 0xCF($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XCF);
    // 0x8002427C: lw          $t5, 0x60($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X60);
    // 0x80024280: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x80024284: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x80024288: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8002428C: addu        $t0, $t5, $t3
    ctx->r8 = ADD32(ctx->r13, ctx->r11);
    // 0x80024290: sb          $t1, 0x12($t0)
    MEM_B(0X12, ctx->r8) = ctx->r9;
    // 0x80024294: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80024298: jal         0x80022ECC
    // 0x8002429C: lbu         $a1, 0xD3($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XD3);
    func_80022ECC(rdram, ctx);
        goto after_37;
    // 0x8002429C: lbu         $a1, 0xD3($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XD3);
    after_37:
    // 0x800242A0: b           L_80024834
    // 0x800242A4: nop

        goto L_80024834;
    // 0x800242A4: nop

L_800242A8:
    // 0x800242A8: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x800242AC: lbu         $t7, 0xD3($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD3);
    // 0x800242B0: lbu         $t6, 0xCF($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XCF);
    // 0x800242B4: lw          $t2, 0x60($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X60);
    // 0x800242B8: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800242BC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800242C0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800242C4: addu        $t9, $t2, $t8
    ctx->r25 = ADD32(ctx->r10, ctx->r24);
    // 0x800242C8: sb          $t6, 0x13($t9)
    MEM_B(0X13, ctx->r25) = ctx->r14;
    // 0x800242CC: lw          $t5, 0xE0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE0);
    // 0x800242D0: lw          $t3, 0x64($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X64);
    // 0x800242D4: beq         $t3, $zero, L_80024310
    if (ctx->r11 == 0) {
        // 0x800242D8: sw          $t3, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r11;
            goto L_80024310;
    }
    // 0x800242D8: sw          $t3, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r11;
L_800242DC:
    // 0x800242DC: lw          $t1, 0xD8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD8);
    // 0x800242E0: lbu         $t4, 0xD3($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XD3);
    // 0x800242E4: lbu         $t0, 0x35($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X35);
    // 0x800242E8: bne         $t0, $t4, L_80024300
    if (ctx->r8 != ctx->r12) {
        // 0x800242EC: nop
    
            goto L_80024300;
    }
    // 0x800242EC: nop

    // 0x800242F0: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x800242F4: lbu         $a1, 0xCF($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0XCF);
    // 0x800242F8: jal         0x8002AB30
    // 0x800242FC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8002AB30(rdram, ctx);
        goto after_38;
    // 0x800242FC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_38:
L_80024300:
    // 0x80024300: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x80024304: lw          $t2, 0x0($t7)
    ctx->r10 = MEM_W(ctx->r15, 0X0);
    // 0x80024308: bne         $t2, $zero, L_800242DC
    if (ctx->r10 != 0) {
        // 0x8002430C: sw          $t2, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r10;
            goto L_800242DC;
    }
    // 0x8002430C: sw          $t2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r10;
L_80024310:
    // 0x80024310: b           L_80024834
    // 0x80024314: nop

        goto L_80024834;
    // 0x80024314: nop

L_80024318:
    // 0x80024318: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x8002431C: lw          $t6, 0x84($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X84);
    // 0x80024320: beq         $t6, $zero, L_80024358
    if (ctx->r14 == 0) {
        // 0x80024324: nop
    
            goto L_80024358;
    }
    // 0x80024324: nop

    // 0x80024328: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x8002432C: lbu         $t5, 0xCF($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XCF);
    // 0x80024330: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80024334: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x80024338: andi        $t3, $t5, 0x7
    ctx->r11 = ctx->r13 & 0X7;
    // 0x8002433C: ori         $t1, $t3, 0x10
    ctx->r9 = ctx->r11 | 0X10;
    // 0x80024340: sll         $t4, $t0, 5
    ctx->r12 = S32(ctx->r8 << 5);
    // 0x80024344: and         $t7, $t4, $at
    ctx->r15 = ctx->r12 & ctx->r1;
    // 0x80024348: or          $a1, $t1, $t7
    ctx->r5 = ctx->r9 | ctx->r15;
    // 0x8002434C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80024350: jal         0x8002EAD0
    // 0x80024354: lw          $a0, 0x84($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X84);
    osSendMesg_recomp(rdram, ctx);
        goto after_39;
    // 0x80024354: lw          $a0, 0x84($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X84);
    after_39:
L_80024358:
    // 0x80024358: b           L_80024834
    // 0x8002435C: nop

        goto L_80024834;
    // 0x8002435C: nop

L_80024360:
    // 0x80024360: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x80024364: lbu         $t5, 0xD3($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024368: lbu         $t2, 0xCF($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XCF);
    // 0x8002436C: lw          $t6, 0x60($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X60);
    // 0x80024370: sll         $t3, $t5, 3
    ctx->r11 = S32(ctx->r13 << 3);
    // 0x80024374: subu        $t3, $t3, $t5
    ctx->r11 = SUB32(ctx->r11, ctx->r13);
    // 0x80024378: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8002437C: addu        $t9, $t6, $t3
    ctx->r25 = ADD32(ctx->r14, ctx->r11);
    // 0x80024380: sb          $t2, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r10;
    // 0x80024384: lw          $t0, 0xE0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE0);
    // 0x80024388: lw          $t4, 0x64($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X64);
    // 0x8002438C: beq         $t4, $zero, L_80024400
    if (ctx->r12 == 0) {
        // 0x80024390: sw          $t4, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r12;
            goto L_80024400;
    }
    // 0x80024390: sw          $t4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r12;
L_80024394:
    // 0x80024394: lw          $t1, 0xD8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD8);
    // 0x80024398: lbu         $t8, 0xD3($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD3);
    // 0x8002439C: lbu         $t7, 0x35($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X35);
    // 0x800243A0: bne         $t7, $t8, L_800243F0
    if (ctx->r15 != ctx->r24) {
        // 0x800243A4: nop
    
            goto L_800243F0;
    }
    // 0x800243A4: nop

    // 0x800243A8: lbu         $t5, 0x38($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X38);
    // 0x800243AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800243B0: beq         $t5, $at, L_800243F0
    if (ctx->r13 == ctx->r1) {
        // 0x800243B4: nop
    
            goto L_800243F0;
    }
    // 0x800243B4: nop

    // 0x800243B8: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x800243BC: jal         0x80029D54
    // 0x800243C0: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    func_80029D54(rdram, ctx);
        goto after_40;
    // 0x800243C0: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    after_40:
    // 0x800243C4: sh          $v0, 0xC6($sp)
    MEM_H(0XC6, ctx->r29) = ctx->r2;
    // 0x800243C8: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x800243CC: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x800243D0: jal         0x80029F5C
    // 0x800243D4: lw          $a1, 0x1C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X1C);
    func_80029F5C(rdram, ctx);
        goto after_41;
    // 0x800243D4: lw          $a1, 0x1C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X1C);
    after_41:
    // 0x800243D8: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x800243DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800243E0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800243E4: lh          $a1, 0xC6($sp)
    ctx->r5 = MEM_H(ctx->r29, 0XC6);
    // 0x800243E8: jal         0x80026BE0
    // 0x800243EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80026BE0(rdram, ctx);
        goto after_42;
    // 0x800243EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_42:
L_800243F0:
    // 0x800243F0: lw          $t3, 0xD8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD8);
    // 0x800243F4: lw          $t2, 0x0($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X0);
    // 0x800243F8: bne         $t2, $zero, L_80024394
    if (ctx->r10 != 0) {
        // 0x800243FC: sw          $t2, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r10;
            goto L_80024394;
    }
    // 0x800243FC: sw          $t2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r10;
L_80024400:
    // 0x80024400: b           L_80024834
    // 0x80024404: nop

        goto L_80024834;
    // 0x80024404: nop

L_80024408:
    // 0x80024408: lw          $t0, 0xE0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE0);
    // 0x8002440C: lbu         $t7, 0xD3($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024410: lbu         $t9, 0xCF($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XCF);
    // 0x80024414: lw          $t4, 0x60($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X60);
    // 0x80024418: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8002441C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80024420: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80024424: addu        $t1, $t4, $t8
    ctx->r9 = ADD32(ctx->r12, ctx->r24);
    // 0x80024428: sb          $t9, 0x4($t1)
    MEM_B(0X4, ctx->r9) = ctx->r25;
    // 0x8002442C: b           L_80024834
    // 0x80024430: nop

        goto L_80024834;
    // 0x80024430: nop

L_80024434:
    // 0x80024434: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x80024438: lbu         $t2, 0xD3($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XD3);
    // 0x8002443C: lbu         $t5, 0xCF($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XCF);
    // 0x80024440: lw          $t3, 0x60($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X60);
    // 0x80024444: sll         $t0, $t2, 3
    ctx->r8 = S32(ctx->r10 << 3);
    // 0x80024448: subu        $t0, $t0, $t2
    ctx->r8 = SUB32(ctx->r8, ctx->r10);
    // 0x8002444C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80024450: addu        $t7, $t3, $t0
    ctx->r15 = ADD32(ctx->r11, ctx->r8);
    // 0x80024454: sb          $t5, 0x8($t7)
    MEM_B(0X8, ctx->r15) = ctx->r13;
    // 0x80024458: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x8002445C: lw          $t8, 0x64($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X64);
    // 0x80024460: beq         $t8, $zero, L_800245D0
    if (ctx->r24 == 0) {
        // 0x80024464: sw          $t8, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r24;
            goto L_800245D0;
    }
    // 0x80024464: sw          $t8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r24;
L_80024468:
    // 0x80024468: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x8002446C: lbu         $t6, 0xD3($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024470: lbu         $t1, 0x35($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X35);
    // 0x80024474: bne         $t1, $t6, L_800245C0
    if (ctx->r9 != ctx->r14) {
        // 0x80024478: nop
    
            goto L_800245C0;
    }
    // 0x80024478: nop

    // 0x8002447C: lbu         $t2, 0x39($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X39);
    // 0x80024480: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80024484: beq         $t2, $at, L_800245C0
    if (ctx->r10 == ctx->r1) {
        // 0x80024488: nop
    
            goto L_800245C0;
    }
    // 0x80024488: nop

    // 0x8002448C: lbu         $t3, 0xCF($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XCF);
    // 0x80024490: slti        $at, $t3, 0x40
    ctx->r1 = SIGNED(ctx->r11) < 0X40 ? 1 : 0;
    // 0x80024494: bne         $at, $zero, L_800244C0
    if (ctx->r1 != 0) {
        // 0x80024498: nop
    
            goto L_800244C0;
    }
    // 0x80024498: nop

    // 0x8002449C: lw          $t0, 0xD8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD8);
    // 0x800244A0: lbu         $t5, 0x39($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X39);
    // 0x800244A4: bne         $t5, $zero, L_800244B8
    if (ctx->r13 != 0) {
        // 0x800244A8: nop
    
            goto L_800244B8;
    }
    // 0x800244A8: nop

    // 0x800244AC: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x800244B0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800244B4: sb          $t7, 0x39($t4)
    MEM_B(0X39, ctx->r12) = ctx->r15;
L_800244B8:
    // 0x800244B8: b           L_800245C0
    // 0x800244BC: nop

        goto L_800245C0;
    // 0x800244BC: nop

L_800244C0:
    // 0x800244C0: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x800244C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800244C8: lbu         $t1, 0x39($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X39);
    // 0x800244CC: bne         $t1, $at, L_800244E0
    if (ctx->r9 != ctx->r1) {
        // 0x800244D0: nop
    
            goto L_800244E0;
    }
    // 0x800244D0: nop

    // 0x800244D4: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x800244D8: b           L_800245C0
    // 0x800244DC: sb          $zero, 0x39($t6)
    MEM_B(0X39, ctx->r14) = 0;
        goto L_800245C0;
    // 0x800244DC: sb          $zero, 0x39($t6)
    MEM_B(0X39, ctx->r14) = 0;
L_800244E0:
    // 0x800244E0: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x800244E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800244E8: lbu         $t2, 0x39($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X39);
    // 0x800244EC: bne         $t2, $at, L_800245C0
    if (ctx->r10 != ctx->r1) {
        // 0x800244F0: nop
    
            goto L_800245C0;
    }
    // 0x800244F0: nop

    // 0x800244F4: lw          $t0, 0xD8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD8);
    // 0x800244F8: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800244FC: sb          $t3, 0x39($t0)
    MEM_B(0X39, ctx->r8) = ctx->r11;
    // 0x80024500: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x80024504: lbu         $t7, 0x24($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X24);
    // 0x80024508: beq         $t7, $zero, L_80024580
    if (ctx->r15 == 0) {
        // 0x8002450C: nop
    
            goto L_80024580;
    }
    // 0x8002450C: nop

    // 0x80024510: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x80024514: lbu         $t1, 0xD3($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024518: lw          $t8, 0x60($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X60);
    // 0x8002451C: sll         $t6, $t1, 3
    ctx->r14 = S32(ctx->r9 << 3);
    // 0x80024520: subu        $t6, $t6, $t1
    ctx->r14 = SUB32(ctx->r14, ctx->r9);
    // 0x80024524: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80024528: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8002452C: lw          $t2, 0x20($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X20);
    // 0x80024530: slti        $at, $t2, 0x3E80
    ctx->r1 = SIGNED(ctx->r10) < 0X3E80 ? 1 : 0;
    // 0x80024534: beq         $at, $zero, L_80024544
    if (ctx->r1 == 0) {
        // 0x80024538: nop
    
            goto L_80024544;
    }
    // 0x80024538: nop

    // 0x8002453C: b           L_80024564
    // 0x80024540: addiu       $s0, $zero, 0x3E80
    ctx->r16 = ADD32(0, 0X3E80);
        goto L_80024564;
    // 0x80024540: addiu       $s0, $zero, 0x3E80
    ctx->r16 = ADD32(0, 0X3E80);
L_80024544:
    // 0x80024544: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x80024548: lbu         $t5, 0xD3($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XD3);
    // 0x8002454C: lw          $t0, 0x60($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X60);
    // 0x80024550: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x80024554: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x80024558: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002455C: addu        $t4, $t0, $t7
    ctx->r12 = ADD32(ctx->r8, ctx->r15);
    // 0x80024560: lw          $s0, 0x20($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X20);
L_80024564:
    // 0x80024564: lw          $a1, 0xD8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD8);
    // 0x80024568: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x8002456C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80024570: jal         0x8002976C
    // 0x80024574: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_8002976C(rdram, ctx);
        goto after_43;
    // 0x80024574: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_43:
    // 0x80024578: b           L_800245C0
    // 0x8002457C: nop

        goto L_800245C0;
    // 0x8002457C: nop

L_80024580:
    // 0x80024580: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x80024584: lw          $t8, 0x20($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X20);
    // 0x80024588: lw          $t6, 0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X8);
    // 0x8002458C: slti        $at, $t6, 0x3E80
    ctx->r1 = SIGNED(ctx->r14) < 0X3E80 ? 1 : 0;
    // 0x80024590: beq         $at, $zero, L_800245A0
    if (ctx->r1 == 0) {
        // 0x80024594: nop
    
            goto L_800245A0;
    }
    // 0x80024594: nop

    // 0x80024598: b           L_800245AC
    // 0x8002459C: addiu       $s0, $zero, 0x3E80
    ctx->r16 = ADD32(0, 0X3E80);
        goto L_800245AC;
    // 0x8002459C: addiu       $s0, $zero, 0x3E80
    ctx->r16 = ADD32(0, 0X3E80);
L_800245A0:
    // 0x800245A0: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800245A4: lw          $t2, 0x20($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X20);
    // 0x800245A8: lw          $s0, 0x8($t2)
    ctx->r16 = MEM_W(ctx->r10, 0X8);
L_800245AC:
    // 0x800245AC: lw          $a1, 0xD8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XD8);
    // 0x800245B0: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800245B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800245B8: jal         0x8002976C
    // 0x800245BC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_8002976C(rdram, ctx);
        goto after_44;
    // 0x800245BC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_44:
L_800245C0:
    // 0x800245C0: lw          $t3, 0xD8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD8);
    // 0x800245C4: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x800245C8: bne         $t5, $zero, L_80024468
    if (ctx->r13 != 0) {
        // 0x800245CC: sw          $t5, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r13;
            goto L_80024468;
    }
    // 0x800245CC: sw          $t5, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r13;
L_800245D0:
    // 0x800245D0: b           L_80024834
    // 0x800245D4: nop

        goto L_80024834;
    // 0x800245D4: nop

L_800245D8:
    // 0x800245D8: lw          $t0, 0xE0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE0);
    // 0x800245DC: lbu         $t4, 0xD3($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XD3);
    // 0x800245E0: lbu         $t2, 0xCF($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0XCF);
    // 0x800245E4: lw          $t7, 0x60($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X60);
    // 0x800245E8: sll         $t1, $t4, 3
    ctx->r9 = S32(ctx->r12 << 3);
    // 0x800245EC: subu        $t1, $t1, $t4
    ctx->r9 = SUB32(ctx->r9, ctx->r12);
    // 0x800245F0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800245F4: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x800245F8: lbu         $t6, 0x6($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X6);
    // 0x800245FC: andi        $t9, $t6, 0x80
    ctx->r25 = ctx->r14 & 0X80;
    // 0x80024600: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80024604: sb          $t3, 0x6($t8)
    MEM_B(0X6, ctx->r24) = ctx->r11;
    // 0x80024608: lw          $t5, 0xE0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE0);
    // 0x8002460C: lbu         $t4, 0xD3($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024610: lw          $t0, 0x60($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X60);
    // 0x80024614: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x80024618: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x8002461C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80024620: addu        $t1, $t0, $t7
    ctx->r9 = ADD32(ctx->r8, ctx->r15);
    // 0x80024624: lbu         $t6, 0x6($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X6);
    // 0x80024628: sra         $t9, $t6, 7
    ctx->r25 = S32(SIGNED(ctx->r14) >> 7);
    // 0x8002462C: sb          $t9, 0xCF($sp)
    MEM_B(0XCF, ctx->r29) = ctx->r25;
L_80024630:
    // 0x80024630: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x80024634: lbu         $t8, 0xD3($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024638: lbu         $t1, 0xCF($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XCF);
    // 0x8002463C: lw          $t3, 0x60($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X60);
    // 0x80024640: sll         $t5, $t8, 3
    ctx->r13 = S32(ctx->r24 << 3);
    // 0x80024644: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x80024648: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002464C: addu        $t4, $t3, $t5
    ctx->r12 = ADD32(ctx->r11, ctx->r13);
    // 0x80024650: lbu         $t0, 0x6($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X6);
    // 0x80024654: sll         $t6, $t1, 7
    ctx->r14 = S32(ctx->r9 << 7);
    // 0x80024658: andi        $t7, $t0, 0x7F
    ctx->r15 = ctx->r8 & 0X7F;
    // 0x8002465C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80024660: sb          $t9, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r25;
    // 0x80024664: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x80024668: lw          $t8, 0x64($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X64);
    // 0x8002466C: beq         $t8, $zero, L_800246D4
    if (ctx->r24 == 0) {
        // 0x80024670: sw          $t8, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r24;
            goto L_800246D4;
    }
    // 0x80024670: sw          $t8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r24;
L_80024674:
    // 0x80024674: lw          $t3, 0xD8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD8);
    // 0x80024678: lbu         $t0, 0xD3($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XD3);
    // 0x8002467C: lbu         $t5, 0x35($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X35);
    // 0x80024680: bne         $t5, $t0, L_800246C4
    if (ctx->r13 != ctx->r8) {
        // 0x80024684: nop
    
            goto L_800246C4;
    }
    // 0x80024684: nop

    // 0x80024688: lbu         $t1, 0x38($t3)
    ctx->r9 = MEM_BU(ctx->r11, 0X38);
    // 0x8002468C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80024690: beq         $t1, $at, L_800246C4
    if (ctx->r9 == ctx->r1) {
        // 0x80024694: nop
    
            goto L_800246C4;
    }
    // 0x80024694: nop

    // 0x80024698: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x8002469C: lbu         $t9, 0xD3($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XD3);
    // 0x800246A0: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x800246A4: lw          $t6, 0x60($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X60);
    // 0x800246A8: sll         $t4, $t9, 3
    ctx->r12 = S32(ctx->r25 << 3);
    // 0x800246AC: subu        $t4, $t4, $t9
    ctx->r12 = SUB32(ctx->r12, ctx->r25);
    // 0x800246B0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800246B4: addu        $t2, $t6, $t4
    ctx->r10 = ADD32(ctx->r14, ctx->r12);
    // 0x800246B8: lbu         $a1, 0x6($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X6);
    // 0x800246BC: jal         0x80026F40
    // 0x800246C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80026F40(rdram, ctx);
        goto after_45;
    // 0x800246C0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_45:
L_800246C4:
    // 0x800246C4: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x800246C8: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x800246CC: bne         $t5, $zero, L_80024674
    if (ctx->r13 != 0) {
        // 0x800246D0: sw          $t5, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r13;
            goto L_80024674;
    }
    // 0x800246D0: sw          $t5, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r13;
L_800246D4:
    // 0x800246D4: b           L_80024834
    // 0x800246D8: nop

        goto L_80024834;
    // 0x800246D8: nop

L_800246DC:
    // 0x800246DC: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x800246E0: lw          $t3, 0x11F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X11F4);
    // 0x800246E4: lbu         $t0, 0xCF($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XCF);
    // 0x800246E8: lw          $t1, 0x3C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X3C);
    // 0x800246EC: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800246F0: beq         $at, $zero, L_8002471C
    if (ctx->r1 == 0) {
        // 0x800246F4: nop
    
            goto L_8002471C;
    }
    // 0x800246F4: nop

    // 0x800246F8: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x800246FC: lbu         $t4, 0xD3($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024700: lbu         $t7, 0xCF($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XCF);
    // 0x80024704: lw          $t6, 0x60($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X60);
    // 0x80024708: sll         $t2, $t4, 3
    ctx->r10 = S32(ctx->r12 << 3);
    // 0x8002470C: subu        $t2, $t2, $t4
    ctx->r10 = SUB32(ctx->r10, ctx->r12);
    // 0x80024710: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80024714: addu        $t8, $t6, $t2
    ctx->r24 = ADD32(ctx->r14, ctx->r10);
    // 0x80024718: sb          $t7, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r15;
L_8002471C:
    // 0x8002471C: b           L_80024834
    // 0x80024720: nop

        goto L_80024834;
    // 0x80024720: nop

L_80024724:
    // 0x80024724: b           L_80024834
    // 0x80024728: nop

        goto L_80024834;
    // 0x80024728: nop

L_8002472C:
    // 0x8002472C: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x80024730: lbu         $t1, 0xD3($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024734: lbu         $t5, 0xCF($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XCF);
    // 0x80024738: lw          $t0, 0x60($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X60);
    // 0x8002473C: sll         $t9, $t1, 3
    ctx->r25 = S32(ctx->r9 << 3);
    // 0x80024740: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
    // 0x80024744: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80024748: addu        $t4, $t0, $t9
    ctx->r12 = ADD32(ctx->r8, ctx->r25);
    // 0x8002474C: sb          $t5, 0x32($t4)
    MEM_B(0X32, ctx->r12) = ctx->r13;
    // 0x80024750: b           L_80024834
    // 0x80024754: nop

        goto L_80024834;
    // 0x80024754: nop

L_80024758:
    // 0x80024758: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x8002475C: lw          $t2, 0x24($t6)
    ctx->r10 = MEM_W(ctx->r14, 0X24);
    // 0x80024760: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x80024764: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80024768: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8002476C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80024770: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80024774: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80024778: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8002477C: nop

    // 0x80024780: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    // 0x80024784: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80024788: lui         $t0, 0x393
    ctx->r8 = S32(0X393 << 16);
    // 0x8002478C: ori         $t0, $t0, 0x8700
    ctx->r8 = ctx->r8 | 0X8700;
    // 0x80024790: div         $zero, $t0, $t1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r9)));
    // 0x80024794: mflo        $t9
    ctx->r25 = lo;
    // 0x80024798: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
    // 0x8002479C: bne         $t1, $zero, L_800247A8
    if (ctx->r9 != 0) {
        // 0x800247A0: nop
    
            goto L_800247A8;
    }
    // 0x800247A0: nop

    // 0x800247A4: break       7
    do_break(2147633060);
L_800247A8:
    // 0x800247A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800247AC: bne         $t1, $at, L_800247C0
    if (ctx->r9 != ctx->r1) {
        // 0x800247B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800247C0;
    }
    // 0x800247B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800247B4: bne         $t0, $at, L_800247C0
    if (ctx->r8 != ctx->r1) {
        // 0x800247B8: nop
    
            goto L_800247C0;
    }
    // 0x800247B8: nop

    // 0x800247BC: break       6
    do_break(2147633084);
L_800247C0:
    // 0x800247C0: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800247C4: lbu         $t4, 0xCF($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XCF);
    // 0x800247C8: addu        $t2, $t5, $t4
    ctx->r10 = ADD32(ctx->r13, ctx->r12);
    // 0x800247CC: addiu       $t6, $t2, -0x40
    ctx->r14 = ADD32(ctx->r10, -0X40);
    // 0x800247D0: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x800247D4: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800247D8: lui         $t8, 0x393
    ctx->r24 = S32(0X393 << 16);
    // 0x800247DC: ori         $t8, $t8, 0x8700
    ctx->r24 = ctx->r24 | 0X8700;
    // 0x800247E0: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x800247E4: mflo        $t3
    ctx->r11 = lo;
    // 0x800247E8: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800247EC: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800247F0: bne         $t7, $zero, L_800247FC
    if (ctx->r15 != 0) {
        // 0x800247F4: nop
    
            goto L_800247FC;
    }
    // 0x800247F4: nop

    // 0x800247F8: break       7
    do_break(2147633144);
L_800247FC:
    // 0x800247FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024800: bne         $t7, $at, L_80024814
    if (ctx->r15 != ctx->r1) {
        // 0x80024804: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024814;
    }
    // 0x80024804: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024808: bne         $t8, $at, L_80024814
    if (ctx->r24 != ctx->r1) {
        // 0x8002480C: nop
    
            goto L_80024814;
    }
    // 0x8002480C: nop

    // 0x80024810: break       6
    do_break(2147633168);
L_80024814:
    // 0x80024814: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80024818: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002481C: jal         0x80024D90
    // 0x80024820: nop

    func_80024D90(rdram, ctx);
        goto after_46;
    // 0x80024820: nop

    after_46:
    // 0x80024824: b           L_80024834
    // 0x80024828: nop

        goto L_80024834;
    // 0x80024828: nop

L_8002482C:
    // 0x8002482C: b           L_80024834
    // 0x80024830: nop

        goto L_80024834;
    // 0x80024830: nop

L_80024834:
    // 0x80024834: b           L_80024A3C
    // 0x80024838: nop

        goto L_80024A3C;
    // 0x80024838: nop

L_8002483C:
    // 0x8002483C: lw          $t0, 0xE0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE0);
    // 0x80024840: lbu         $t9, 0xD3($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024844: lbu         $t8, 0xD2($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD2);
    // 0x80024848: lw          $t1, 0x60($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X60);
    // 0x8002484C: sll         $t5, $t9, 3
    ctx->r13 = S32(ctx->r25 << 3);
    // 0x80024850: subu        $t5, $t5, $t9
    ctx->r13 = SUB32(ctx->r13, ctx->r25);
    // 0x80024854: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80024858: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x8002485C: lbu         $t2, 0x32($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X32);
    // 0x80024860: sll         $t6, $t2, 7
    ctx->r14 = S32(ctx->r10 << 7);
    // 0x80024864: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80024868: sw          $t7, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r15;
    // 0x8002486C: jal         0x800E9048
    // 0x80024870: nop

    func_800E9048(rdram, ctx);
        goto after_47;
    // 0x80024870: nop

    after_47:
    // 0x80024874: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x80024878: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002487C: beq         $at, $zero, L_8002489C
    if (ctx->r1 == 0) {
        // 0x80024880: nop
    
            goto L_8002489C;
    }
    // 0x80024880: nop

    // 0x80024884: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80024888: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x8002488C: jal         0x8002A318
    // 0x80024890: lbu         $a2, 0xD3($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD3);
    func_8002A318(rdram, ctx);
        goto after_48;
    // 0x80024890: lbu         $a2, 0xD3($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XD3);
    after_48:
    // 0x80024894: b           L_8002489C
    // 0x80024898: nop

        goto L_8002489C;
    // 0x80024898: nop

L_8002489C:
    // 0x8002489C: b           L_80024A3C
    // 0x800248A0: nop

        goto L_80024A3C;
    // 0x800248A0: nop

L_800248A4:
    // 0x800248A4: lbu         $t0, 0xCF($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XCF);
    // 0x800248A8: lbu         $t1, 0xD0($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XD0);
    // 0x800248AC: sll         $t9, $t0, 7
    ctx->r25 = S32(ctx->r8 << 7);
    // 0x800248B0: addu        $t5, $t9, $t1
    ctx->r13 = ADD32(ctx->r25, ctx->r9);
    // 0x800248B4: addiu       $t4, $t5, -0x2000
    ctx->r12 = ADD32(ctx->r13, -0X2000);
    // 0x800248B8: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x800248BC: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x800248C0: lbu         $t8, 0xD3($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD3);
    // 0x800248C4: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800248C8: lw          $t6, 0x60($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X60);
    // 0x800248CC: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x800248D0: subu        $t7, $t7, $t8
    ctx->r15 = SUB32(ctx->r15, ctx->r24);
    // 0x800248D4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800248D8: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
    // 0x800248DC: lh          $t0, 0x0($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X0);
    // 0x800248E0: multu       $t0, $t9
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800248E4: mflo        $t1
    ctx->r9 = lo;
    // 0x800248E8: bgez        $t1, L_800248F8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800248EC: sra         $t5, $t1, 13
        ctx->r13 = S32(SIGNED(ctx->r9) >> 13);
            goto L_800248F8;
    }
    // 0x800248EC: sra         $t5, $t1, 13
    ctx->r13 = S32(SIGNED(ctx->r9) >> 13);
    // 0x800248F0: addiu       $at, $t1, 0x1FFF
    ctx->r1 = ADD32(ctx->r9, 0X1FFF);
    // 0x800248F4: sra         $t5, $at, 13
    ctx->r13 = S32(SIGNED(ctx->r1) >> 13);
L_800248F8:
    // 0x800248F8: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800248FC: jal         0x80027170
    // 0x80024900: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_80027170(rdram, ctx);
        goto after_49;
    // 0x80024900: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_49:
    // 0x80024904: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80024908: lw          $t4, 0xE0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE0);
    // 0x8002490C: lbu         $t8, 0xD3($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024910: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80024914: lw          $t2, 0x60($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X60);
    // 0x80024918: sll         $t6, $t8, 3
    ctx->r14 = S32(ctx->r24 << 3);
    // 0x8002491C: subu        $t6, $t6, $t8
    ctx->r14 = SUB32(ctx->r14, ctx->r24);
    // 0x80024920: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80024924: addu        $t7, $t2, $t6
    ctx->r15 = ADD32(ctx->r10, ctx->r14);
    // 0x80024928: swc1        $f16, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f16.u32l;
    // 0x8002492C: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x80024930: lw          $t0, 0x64($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X64);
    // 0x80024934: beq         $t0, $zero, L_80024A2C
    if (ctx->r8 == 0) {
        // 0x80024938: sw          $t0, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r8;
            goto L_80024A2C;
    }
    // 0x80024938: sw          $t0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r8;
L_8002493C:
    // 0x8002493C: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x80024940: lbu         $t5, 0xD3($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024944: lbu         $t1, 0x35($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X35);
    // 0x80024948: bne         $t1, $t5, L_80024A1C
    if (ctx->r9 != ctx->r13) {
        // 0x8002494C: nop
    
            goto L_80024A1C;
    }
    // 0x8002494C: nop

    // 0x80024950: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x80024954: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80024958: lwc1        $f18, 0x2C($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X2C);
    // 0x8002495C: lwc1        $f6, 0x30($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X30);
    // 0x80024960: addiu       $a0, $t4, 0x4
    ctx->r4 = ADD32(ctx->r12, 0X4);
    // 0x80024964: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80024968: nop

    // 0x8002496C: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80024970: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80024974: jal         0x80026E90
    // 0x80024978: nop

    func_80026E90(rdram, ctx);
        goto after_50;
    // 0x80024978: nop

    after_50:
    // 0x8002497C: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x80024980: lbu         $t6, 0xD3($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XD3);
    // 0x80024984: lw          $t2, 0x60($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X60);
    // 0x80024988: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8002498C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80024990: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80024994: addu        $t3, $t2, $t7
    ctx->r11 = ADD32(ctx->r10, ctx->r15);
    // 0x80024998: lbu         $t0, 0x11($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0X11);
    // 0x8002499C: beq         $t0, $zero, L_80024A1C
    if (ctx->r8 == 0) {
        // 0x800249A0: nop
    
            goto L_80024A1C;
    }
    // 0x800249A0: nop

    // 0x800249A4: lw          $t9, 0xE0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE0);
    // 0x800249A8: lbu         $t5, 0xD3($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0XD3);
    // 0x800249AC: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
    // 0x800249B0: lw          $t1, 0x60($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X60);
    // 0x800249B4: sll         $t4, $t5, 3
    ctx->r12 = S32(ctx->r13 << 3);
    // 0x800249B8: lw          $t3, 0x20($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X20);
    // 0x800249BC: subu        $t4, $t4, $t5
    ctx->r12 = SUB32(ctx->r12, ctx->r13);
    // 0x800249C0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800249C4: lbu         $t7, 0x36($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X36);
    // 0x800249C8: lbu         $t0, 0x14($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0X14);
    // 0x800249CC: addu        $t8, $t1, $t4
    ctx->r24 = ADD32(ctx->r9, ctx->r12);
    // 0x800249D0: lbu         $t6, 0x12($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X12);
    // 0x800249D4: subu        $t9, $t7, $t0
    ctx->r25 = SUB32(ctx->r15, ctx->r8);
    // 0x800249D8: addu        $a0, $t6, $t9
    ctx->r4 = ADD32(ctx->r14, ctx->r25);
    // 0x800249DC: jal         0x80028B74
    // 0x800249E0: addiu       $a0, $a0, -0x40
    ctx->r4 = ADD32(ctx->r4, -0X40);
    func_80028B74(rdram, ctx);
        goto after_51;
    // 0x800249E0: addiu       $a0, $a0, -0x40
    ctx->r4 = ADD32(ctx->r4, -0X40);
    after_51:
    // 0x800249E4: lui         $at, 0x43DC
    ctx->r1 = S32(0X43DC << 16);
    // 0x800249E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800249EC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800249F0: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800249F4: mul.s       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x800249F8: lw          $t5, 0xD8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD8);
    // 0x800249FC: lwc1        $f6, 0x30($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X30);
    // 0x80024A00: addiu       $a0, $t5, 0x4
    ctx->r4 = ADD32(ctx->r13, 0X4);
    // 0x80024A04: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80024A08: nop

    // 0x80024A0C: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80024A10: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80024A14: jal         0x8002A7E0
    // 0x80024A18: nop

    func_8002A7E0(rdram, ctx);
        goto after_52;
    // 0x80024A18: nop

    after_52:
L_80024A1C:
    // 0x80024A1C: lw          $t1, 0xD8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD8);
    // 0x80024A20: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80024A24: bne         $t4, $zero, L_8002493C
    if (ctx->r12 != 0) {
        // 0x80024A28: sw          $t4, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r12;
            goto L_8002493C;
    }
    // 0x80024A28: sw          $t4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r12;
L_80024A2C:
    // 0x80024A2C: b           L_80024A3C
    // 0x80024A30: nop

        goto L_80024A3C;
    // 0x80024A30: nop

L_80024A34:
    // 0x80024A34: b           L_80024A3C
    // 0x80024A38: nop

        goto L_80024A3C;
    // 0x80024A38: nop

L_80024A3C:
    // 0x80024A3C: b           L_80024A44
    // 0x80024A40: nop

        goto L_80024A44;
    // 0x80024A40: nop

L_80024A44:
    // 0x80024A44: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80024A48: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80024A4C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80024A50: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80024A54: jr          $ra
    // 0x80024A58: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x80024A58: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_800C954C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C954C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9554: jal         0x800C91C8
    // 0x800C9558: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800C91C8(rdram, ctx);
        goto after_0;
    // 0x800C9558: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x800C955C: beq         $v0, $zero, L_800C9574
    if (ctx->r2 == 0) {
        // 0x800C9560: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800C9574;
    }
    // 0x800C9560: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C9564: jal         0x800881C0
    // 0x800C9568: nop

    _gctransitionDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x800C9568: nop

    after_1:
    // 0x800C956C: b           L_800C957C
    // 0x800C9570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C957C;
    // 0x800C9570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9574:
    // 0x800C9574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C9578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C957C:
    // 0x800C957C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9580: jr          $ra
    // 0x800C9584: nop

    return;
    // 0x800C9584: nop

;}
RECOMP_FUNC void _bamovegoto_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E28: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084E28);
    return;
    // 0x80084E2C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800BA4B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA4B8: sh          $a1, 0xAA($a0)
    MEM_H(0XAA, ctx->r4) = ctx->r5;
    // 0x800BA4BC: jr          $ra
    // 0x800BA4C0: sw          $a2, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->r6;
    return;
    // 0x800BA4C0: sw          $a2, 0xBC($a0)
    MEM_W(0XBC, ctx->r4) = ctx->r6;
;}
RECOMP_FUNC void _sumumbofx_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089898: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089898);
    return;
    // 0x8008989C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_808001E0_chicestationbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001E4: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808001E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001EC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808001F0: beq         $a1, $at, L_8080020C
    if (ctx->r5 == ctx->r1) {
        // 0x808001F4: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8080020C;
    }
    // 0x808001F4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x808001F8: addiu       $at, $zero, 0x9D
    ctx->r1 = ADD32(0, 0X9D);
    // 0x808001FC: beql        $a1, $at, L_80800254
    if (ctx->r5 == ctx->r1) {
        // 0x80800200: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80800254;
    }
    goto skip_0;
    // 0x80800200: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x80800204: b           L_80800268
    // 0x80800208: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
        goto L_80800268;
    // 0x80800208: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_8080020C:
    // 0x8080020C: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800210: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800214: addiu       $v0, $zero, 0x873
    ctx->r2 = ADD32(0, 0X873);
    // 0x80800218: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080021C: bne         $t7, $at, L_8080022C
    if (ctx->r15 != ctx->r1) {
        // 0x80800220: nop
    
            goto L_8080022C;
    }
    // 0x80800220: nop

    // 0x80800224: b           L_8080022C
    // 0x80800228: addiu       $v0, $zero, 0x872
    ctx->r2 = ADD32(0, 0X872);
        goto L_8080022C;
    // 0x80800228: addiu       $v0, $zero, 0x872
    ctx->r2 = ADD32(0, 0X872);
L_8080022C:
    // 0x8080022C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80800230: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x80800234: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    // 0x80800238: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8080023C: jal         0x80103140
    // 0x80800240: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x80800240: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800244: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800248: b           L_80800264
    // 0x8080024C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_80800264;
    // 0x8080024C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80800250: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80800254:
    // 0x80800254: jal         0x800FFAB0
    // 0x80800258: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800258: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8080025C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800260: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80800264:
    // 0x80800264: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_80800268:
    // 0x80800268: jal         0x80086248
    // 0x8080026C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chdoor_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x8080026C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800270: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800278: jr          $ra
    // 0x8080027C: nop

    return;
    // 0x8080027C: nop

;}
RECOMP_FUNC void func_80800A94_ncpoducam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800AA0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800AA4: lbu         $v0, 0x60($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X60);
    // 0x80800AA8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800AAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AB0: beq         $v0, $at, L_80800AE0
    if (ctx->r2 == ctx->r1) {
        // 0x80800AB4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800AE0;
    }
    // 0x80800AB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800AB8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800ABC: beq         $v0, $at, L_80800AF0
    if (ctx->r2 == ctx->r1) {
        // 0x80800AC0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800AF0;
    }
    // 0x80800AC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800AC4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800AC8: bne         $v0, $at, L_80800AF8
    if (ctx->r2 != ctx->r1) {
        // 0x80800ACC: nop
    
            goto L_80800AF8;
    }
    // 0x80800ACC: nop

    // 0x80800AD0: jal         0x80800A18
    // 0x80800AD4: nop

    func_80800A18_ncpoducam(rdram, ctx);
        goto after_0;
    // 0x80800AD4: nop

    after_0:
    // 0x80800AD8: b           L_80800AF8
    // 0x80800ADC: nop

        goto L_80800AF8;
    // 0x80800ADC: nop

L_80800AE0:
    // 0x80800AE0: jal         0x80800704
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800704_ncpoducam(rdram, ctx);
        goto after_1;
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800AE8: b           L_80800AF8
    // 0x80800AEC: nop

        goto L_80800AF8;
    // 0x80800AEC: nop

L_80800AF0:
    // 0x80800AF0: jal         0x808003A8
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003A8_ncpoducam(rdram, ctx);
        goto after_2;
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80800AF8:
    // 0x80800AF8: jal         0x80110024
    // 0x80800AFC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80110024(rdram, ctx);
        goto after_3;
    // 0x80800AFC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80800B00: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800B04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B08: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800B0C: jal         0x80089500
    // 0x80800B10: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    _ncpod_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800B10: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_4:
    // 0x80800B14: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800B18: jal         0x80089508
    // 0x80800B1C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    _ncpod_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800B1C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    after_5:
    // 0x80800B20: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800B24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B28: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800B2C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800B30: nop

    // 0x80800B34: bc1fl       L_80800B64
    if (!c1cs) {
        // 0x80800B38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B64;
    }
    goto skip_0;
    // 0x80800B38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800B3C: lbu         $v0, 0x60($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X60);
    // 0x80800B40: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800B44: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800B48: beq         $v0, $at, L_80800B58
    if (ctx->r2 == ctx->r1) {
        // 0x80800B4C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80800B58;
    }
    // 0x80800B4C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800B50: bnel        $v0, $at, L_80800B64
    if (ctx->r2 != ctx->r1) {
        // 0x80800B54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B64;
    }
    goto skip_1;
    // 0x80800B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_80800B58:
    // 0x80800B58: jal         0x80089518
    // 0x80800B5C: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    _ncpod_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800B5C: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    after_6:
    // 0x80800B60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B64:
    // 0x80800B64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B68: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B6C: jr          $ra
    // 0x80800B70: nop

    return;
    // 0x80800B70: nop

;}
RECOMP_FUNC void func_80801334_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801334: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080133C: jal         0x808001A8
    // 0x80801340: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsvan_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80801340: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801344: jal         0x800839C8
    // 0x80801348: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsrest_entrypoint_16(rdram, ctx);
        goto after_1;
    // 0x80801348: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080134C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801354: jr          $ra
    // 0x80801358: nop

    return;
    // 0x80801358: nop

;}
RECOMP_FUNC void sumumbofx_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DB0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800DB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800DBC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800DC0: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80800DC4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800DC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800DCC: beql        $t6, $at, L_80800F1C
    if (ctx->r14 == ctx->r1) {
        // 0x80800DD0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800F1C;
    }
    goto skip_0;
    // 0x80800DD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800DD4: lw          $v0, 0x60($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X60);
    // 0x80800DD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800DDC: srl         $t7, $v0, 25
    ctx->r15 = S32(U32(ctx->r2) >> 25);
    // 0x80800DE0: beql        $t7, $zero, L_80800E38
    if (ctx->r15 == 0) {
        // 0x80800DE4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800E38;
    }
    goto skip_1;
    // 0x80800DE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x80800DE8: beq         $t7, $at, L_80800E10
    if (ctx->r15 == ctx->r1) {
        // 0x80800DEC: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_80800E10;
    }
    // 0x80800DEC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800DF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DF4: beq         $t7, $at, L_80800E44
    if (ctx->r15 == ctx->r1) {
        // 0x80800DF8: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_80800E44;
    }
    // 0x80800DF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800DFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800E00: beql        $t7, $at, L_80800E38
    if (ctx->r15 == ctx->r1) {
        // 0x80800E04: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800E38;
    }
    goto skip_2;
    // 0x80800E04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_2:
    // 0x80800E08: b           L_80800E64
    // 0x80800E0C: lbu         $t8, 0x63($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X63);
        goto L_80800E64;
    // 0x80800E0C: lbu         $t8, 0x63($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X63);
L_80800E10:
    // 0x80800E10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800E14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800E18: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800E1C: lwc1        $f14, 0x14($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800E20: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800E24: jal         0x800F10B4
    // 0x80800E28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80800E28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800E2C: b           L_80800E60
    // 0x80800E30: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
        goto L_80800E60;
    // 0x80800E30: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800E34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800E38:
    // 0x80800E38: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E3C: b           L_80800E60
    // 0x80800E40: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
        goto L_80800E60;
    // 0x80800E40: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_80800E44:
    // 0x80800E44: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800E48: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80800E4C: lwc1        $f14, 0x14($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80800E50: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800E54: jal         0x800F10B4
    // 0x80800E58: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800E58: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800E5C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
L_80800E60:
    // 0x80800E60: lbu         $t8, 0x63($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X63);
L_80800E64:
    // 0x80800E64: beql        $t8, $zero, L_80800EF0
    if (ctx->r24 == 0) {
        // 0x80800E68: lw          $v0, 0x54($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X54);
            goto L_80800EF0;
    }
    goto skip_3;
    // 0x80800E68: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    skip_3:
    // 0x80800E6C: jal         0x800F54E4
    // 0x80800E70: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800E70: nop

    after_2:
    // 0x80800E74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800E78: jal         0x800F5A00
    // 0x80800E7C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x80800E7C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x80800E80: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800E84: jal         0x800EEB40
    // 0x80800E88: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EEB40(rdram, ctx);
        goto after_4;
    // 0x80800E88: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x80800E8C: lwc1        $f14, 0x34($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800E90: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800E94: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80800E98: nop

    // 0x80800E9C: bc1t        L_80800EE4
    if (c1cs) {
        // 0x80800EA0: nop
    
            goto L_80800EE4;
    }
    // 0x80800EA0: nop

    // 0x80800EA4: lwc1        $f2, 0x38($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800EA8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800EAC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800EB0: nop

    // 0x80800EB4: bc1fl       L_80800ECC
    if (!c1cs) {
        // 0x80800EB8: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80800ECC;
    }
    goto skip_4;
    // 0x80800EB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_4:
    // 0x80800EBC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800EC0: b           L_80800EE4
    // 0x80800EC4: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
        goto L_80800EE4;
    // 0x80800EC4: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80800EC8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80800ECC:
    // 0x80800ECC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800ED0: jal         0x800F10B4
    // 0x80800ED4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800ED4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80800ED8: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800EDC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800EE0: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
L_80800EE4:
    // 0x80800EE4: b           L_80800EF0
    // 0x80800EE8: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
        goto L_80800EF0;
    // 0x80800EE8: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x80800EEC: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
L_80800EF0:
    // 0x80800EF0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800EF4: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800EF8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800EFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800F00: addiu       $a2, $s0, 0x48
    ctx->r6 = ADD32(ctx->r16, 0X48);
    // 0x80800F04: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800F08: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800F0C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800F10: jal         0x800B99CC
    // 0x80800F14: nop

    func_800B99CC(rdram, ctx);
        goto after_6;
    // 0x80800F14: nop

    after_6:
    // 0x80800F18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F1C:
    // 0x80800F1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F20: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800F24: jr          $ra
    // 0x80800F28: nop

    return;
    // 0x80800F28: nop

;}
RECOMP_FUNC void gcstatusDll_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B4: jal         0x800D3948
    // 0x808001B8: nop

    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x808001B8: nop

    after_0:
    // 0x808001BC: beql        $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808001F8;
    }
    goto skip_0;
    // 0x808001C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x808001C4: jal         0x80800160
    // 0x808001C8: nop

    gcstatusDll_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x808001C8: nop

    after_1:
    // 0x808001CC: sltiu       $at, $v0, 0x7
    ctx->r1 = ctx->r2 < 0X7 ? 1 : 0;
    // 0x808001D0: beq         $at, $zero, L_808001F4
    if (ctx->r1 == 0) {
        // 0x808001D4: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_808001F4;
    }
    // 0x808001D4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808001D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2674, 0X210) << 16);
    // 0x808001DC: addu        $at, $at, $t6
    gpr jr_addend_808001E4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808001E0: lw          $t6, 0x210($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2674, 0X210));
    // 0x808001E4: jr          $t6
    // 0x808001E8: nop

    switch (jr_addend_808001E4 >> 2) {
        case 0: goto L_808001F4; break;
        case 1: goto L_808001F4; break;
        case 2: goto L_808001F4; break;
        case 3: goto L_808001EC; break;
        case 4: goto L_808001F4; break;
        case 5: goto L_808001EC; break;
        case 6: goto L_808001F4; break;
        default: switch_error(__func__, 0x808001E4, 0x80800210);
    }
    // 0x808001E8: nop

L_808001EC:
    // 0x808001EC: b           L_808001F8
    // 0x808001F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001F8;
    // 0x808001F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001F4:
    // 0x808001F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001F8:
    // 0x808001F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800200: jr          $ra
    // 0x80800204: nop

    return;
    // 0x80800204: nop

    // 0x80800208: nop

    // 0x8080020C: nop

;}
RECOMP_FUNC void func_80800000_chsounder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x8080000C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800010: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800014: srl         $t6, $v0, 7
    ctx->r14 = S32(U32(ctx->r2) >> 7);
    // 0x80800018: beq         $t6, $at, L_80800034
    if (ctx->r14 == ctx->r1) {
        // 0x8080001C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80800034;
    }
    // 0x8080001C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800020: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x80800024: beq         $t6, $at, L_80800050
    if (ctx->r14 == ctx->r1) {
        // 0x80800028: addiu       $a1, $a0, 0x4
        ctx->r5 = ADD32(ctx->r4, 0X4);
            goto L_80800050;
    }
    // 0x80800028: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x8080002C: b           L_8080006C
    // 0x80800030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080006C;
    // 0x80800030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800034:
    // 0x80800034: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1684, 0XA0) << 16);
    // 0x80800038: addiu       $t7, $t7, 0xA0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1684, 0XA0));
    // 0x8080003C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800040: jal         0x80089D58
    // 0x80800044: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800044: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_0:
    // 0x80800048: b           L_8080006C
    // 0x8080004C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080006C;
    // 0x8080004C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800050:
    // 0x80800050: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1684, 0XAC) << 16);
    // 0x80800054: addiu       $t8, $t8, 0xAC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1684, 0XAC));
    // 0x80800058: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080005C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800060: jal         0x80089D58
    // 0x80800064: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x80800064: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_1:
    // 0x80800068: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080006C:
    // 0x8080006C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803D60: beql        $a1, $zero, L_80803D7C
    if (ctx->r5 == 0) {
        // 0x80803D64: lbu         $t9, 0x1E7($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X1E7);
            goto L_80803D7C;
    }
    goto skip_0;
    // 0x80803D64: lbu         $t9, 0x1E7($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1E7);
    skip_0:
    // 0x80803D68: lbu         $t7, 0x1E7($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1E7);
    // 0x80803D6C: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80803D70: jr          $ra
    // 0x80803D74: sb          $t8, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r24;
    return;
    // 0x80803D74: sb          $t8, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r24;
    // 0x80803D78: lbu         $t9, 0x1E7($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1E7);
L_80803D7C:
    // 0x80803D7C: andi        $t0, $t9, 0xFFDF
    ctx->r8 = ctx->r25 & 0XFFDF;
    // 0x80803D80: sb          $t0, 0x1E7($a0)
    MEM_B(0X1E7, ctx->r4) = ctx->r8;
    // 0x80803D84: jr          $ra
    // 0x80803D88: nop

    return;
    // 0x80803D88: nop

;}
RECOMP_FUNC void suexpression_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800288: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080028C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800290: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800294: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800298: bne         $a3, $zero, L_808002A8
    if (ctx->r7 != 0) {
        // 0x8080029C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_808002A8;
    }
    // 0x8080029C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808002A0: b           L_808002AC
    // 0x808002A4: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
        goto L_808002AC;
    // 0x808002A4: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
L_808002A8:
    // 0x808002A8: sh          $a2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r6;
L_808002AC:
    // 0x808002AC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808002B0: addu        $t7, $a2, $a3
    ctx->r15 = ADD32(ctx->r6, ctx->r7);
    // 0x808002B4: bnel        $t6, $zero, L_808002C8
    if (ctx->r14 != 0) {
        // 0x808002B8: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_808002C8;
    }
    goto skip_0;
    // 0x808002B8: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    skip_0:
    // 0x808002BC: b           L_808002C8
    // 0x808002C0: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_808002C8;
    // 0x808002C0: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x808002C4: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_808002C8:
    // 0x808002C8: lh          $v0, 0x2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2);
    // 0x808002CC: beq         $v0, $zero, L_808002DC
    if (ctx->r2 == 0) {
        // 0x808002D0: addu        $a0, $s0, $v0
        ctx->r4 = ADD32(ctx->r16, ctx->r2);
            goto L_808002DC;
    }
    // 0x808002D0: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x808002D4: jal         0x80089B60
    // 0x808002D8: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    _suexpressmorph_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x808002D8: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    after_0:
L_808002DC:
    // 0x808002DC: lh          $v0, 0x0($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X0);
    // 0x808002E0: beq         $v0, $zero, L_808002F0
    if (ctx->r2 == 0) {
        // 0x808002E4: addu        $a0, $s0, $v0
        ctx->r4 = ADD32(ctx->r16, ctx->r2);
            goto L_808002F0;
    }
    // 0x808002E4: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x808002E8: jal         0x80089770
    // 0x808002EC: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    _suexpressjoint_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808002EC: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    after_1:
L_808002F0:
    // 0x808002F0: addiu       $v0, $zero, 0x4B
    ctx->r2 = ADD32(0, 0X4B);
    // 0x808002F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808002F8: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x808002FC: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80800300: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x80800304: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x80800308: sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    // 0x8080030C: sb          $v0, 0x11($s0)
    MEM_B(0X11, ctx->r16) = ctx->r2;
    // 0x80800310: sb          $t8, 0x12($s0)
    MEM_B(0X12, ctx->r16) = ctx->r24;
    // 0x80800314: sh          $zero, 0xE($s0)
    MEM_H(0XE, ctx->r16) = 0;
    // 0x80800318: sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
    // 0x8080031C: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x80800320: sh          $t9, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r25;
    // 0x80800324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800328: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080032C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800330: jr          $ra
    // 0x80800334: nop

    return;
    // 0x80800334: nop

;}
RECOMP_FUNC void chdinoswitches_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1048, 0XD08) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0xD08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1048, 0XD08));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0xD08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1048, 0XD08));
;}
RECOMP_FUNC void sumultiscore_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A00: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800A04: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800A08: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x80800A0C: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80800A10: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80800A14: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80800A18: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80800A1C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80800A20: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80800A24: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800A28: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800A2C: lw          $v1, 0x518($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X518);
    // 0x80800A30: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800A34: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800A38: blez        $v1, L_80800BCC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80800A3C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(3154, 0X1478) << 16);
            goto L_80800BCC;
    }
    // 0x80800A3C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3154, 0X1478) << 16);
    // 0x80800A40: lwc1        $f24, 0x1478($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3154, 0X1478));
    // 0x80800A44: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80800A48: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800A4C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800A50: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80800A54:
    // 0x80800A54: blez        $v0, L_80800BBC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800A58: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80800BBC;
    }
    // 0x80800A58: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80800A5C: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x80800A60: addu        $t6, $t6, $s3
    ctx->r14 = ADD32(ctx->r14, ctx->r19);
    // 0x80800A64: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80800A68: subu        $t6, $t6, $s3
    ctx->r14 = SUB32(ctx->r14, ctx->r19);
    // 0x80800A6C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800A70: addu        $s5, $s2, $t6
    ctx->r21 = ADD32(ctx->r18, ctx->r14);
    // 0x80800A74: addiu       $s5, $s5, 0x28
    ctx->r21 = ADD32(ctx->r21, 0X28);
    // 0x80800A78: sll         $t7, $s4, 5
    ctx->r15 = S32(ctx->r20 << 5);
L_80800A7C:
    // 0x80800A7C: addu        $s1, $s5, $t7
    ctx->r17 = ADD32(ctx->r21, ctx->r15);
    // 0x80800A80: lwc1        $f4, 0x30($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800A84: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x80800A88: nop

    // 0x80800A8C: bc1tl       L_80800AF8
    if (c1cs) {
        // 0x80800A90: addiu       $s0, $s1, 0x18
        ctx->r16 = ADD32(ctx->r17, 0X18);
            goto L_80800AF8;
    }
    goto skip_0;
    // 0x80800A90: addiu       $s0, $s1, 0x18
    ctx->r16 = ADD32(ctx->r17, 0X18);
    skip_0:
    // 0x80800A94: jal         0x800D8FF8
    // 0x80800A98: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800A98: nop

    after_0:
    // 0x80800A9C: addiu       $s0, $s1, 0x18
    ctx->r16 = ADD32(ctx->r17, 0X18);
    // 0x80800AA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800AA4: jal         0x800F1574
    // 0x80800AA8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800F1574(rdram, ctx);
        goto after_1;
    // 0x80800AA8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_1:
    // 0x80800AAC: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800AB0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800AB4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80800AB8: nop

    // 0x80800ABC: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80800AC0: nop

    // 0x80800AC4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800AC8: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80800ACC: mul.s       $f12, $f0, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80800AD0: jal         0x800138D0
    // 0x80800AD4: nop

    func_800138D0(rdram, ctx);
        goto after_2;
    // 0x80800AD4: nop

    after_2:
    // 0x80800AD8: jal         0x800F2100
    // 0x80800ADC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_3;
    // 0x80800ADC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80800AE0: mul.s       $f16, $f0, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80800AE4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800AE8: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x80800AEC: nop

    // 0x80800AF0: sb          $t1, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r9;
    // 0x80800AF4: addiu       $s0, $s1, 0x18
    ctx->r16 = ADD32(ctx->r17, 0X18);
L_80800AF8:
    // 0x80800AF8: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x80800AFC: sltiu       $at, $t2, 0x6
    ctx->r1 = ctx->r10 < 0X6 ? 1 : 0;
    // 0x80800B00: beq         $at, $zero, L_80800BA4
    if (ctx->r1 == 0) {
        // 0x80800B04: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80800BA4;
    }
    // 0x80800B04: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800B08: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3154, 0X147C) << 16);
    // 0x80800B0C: addu        $at, $at, $t2
    gpr jr_addend_80800B14 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80800B10: lw          $t2, 0x147C($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3154, 0X147C));
    // 0x80800B14: jr          $t2
    // 0x80800B18: nop

    switch (jr_addend_80800B14 >> 2) {
        case 0: goto L_80800B1C; break;
        case 1: goto L_80800B34; break;
        case 2: goto L_80800B4C; break;
        case 3: goto L_80800B64; break;
        case 4: goto L_80800B7C; break;
        case 5: goto L_80800B94; break;
        default: switch_error(__func__, 0x80800B14, 0x8080147C);
    }
    // 0x80800B18: nop

L_80800B1C:
    // 0x80800B1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B20: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800B24: jal         0x80800BFC
    // 0x80800B28: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80800BFC_sumultiscore(rdram, ctx);
        goto after_4;
    // 0x80800B28: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x80800B2C: b           L_80800BA8
    // 0x80800B30: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
        goto L_80800BA8;
    // 0x80800B30: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80800B34:
    // 0x80800B34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B38: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800B3C: jal         0x80800D24
    // 0x80800B40: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80800D24_sumultiscore(rdram, ctx);
        goto after_5;
    // 0x80800B40: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80800B44: b           L_80800BA8
    // 0x80800B48: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
        goto L_80800BA8;
    // 0x80800B48: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80800B4C:
    // 0x80800B4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B50: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800B54: jal         0x80800D54
    // 0x80800B58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80800D54_sumultiscore(rdram, ctx);
        goto after_6;
    // 0x80800B58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
    // 0x80800B5C: b           L_80800BA8
    // 0x80800B60: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
        goto L_80800BA8;
    // 0x80800B60: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80800B64:
    // 0x80800B64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B68: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800B6C: jal         0x80800D64
    // 0x80800B70: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80800D64_sumultiscore(rdram, ctx);
        goto after_7;
    // 0x80800B70: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x80800B74: b           L_80800BA8
    // 0x80800B78: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
        goto L_80800BA8;
    // 0x80800B78: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80800B7C:
    // 0x80800B7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B80: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800B84: jal         0x80800DD0
    // 0x80800B88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80800DD0_sumultiscore(rdram, ctx);
        goto after_8;
    // 0x80800B88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_8:
    // 0x80800B8C: b           L_80800BA8
    // 0x80800B90: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
        goto L_80800BA8;
    // 0x80800B90: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80800B94:
    // 0x80800B94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B98: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800B9C: jal         0x80800E84
    // 0x80800BA0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_80800E84_sumultiscore(rdram, ctx);
        goto after_9;
    // 0x80800BA0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
L_80800BA4:
    // 0x80800BA4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80800BA8:
    // 0x80800BA8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80800BAC: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800BB0: bnel        $at, $zero, L_80800A7C
    if (ctx->r1 != 0) {
        // 0x80800BB4: sll         $t7, $s4, 5
        ctx->r15 = S32(ctx->r20 << 5);
            goto L_80800A7C;
    }
    goto skip_1;
    // 0x80800BB4: sll         $t7, $s4, 5
    ctx->r15 = S32(ctx->r20 << 5);
    skip_1:
    // 0x80800BB8: lw          $v1, 0x518($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X518);
L_80800BBC:
    // 0x80800BBC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80800BC0: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800BC4: bne         $at, $zero, L_80800A54
    if (ctx->r1 != 0) {
        // 0x80800BC8: nop
    
            goto L_80800A54;
    }
    // 0x80800BC8: nop

L_80800BCC:
    // 0x80800BCC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800BD0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800BD4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800BD8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80800BDC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80800BE0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80800BE4: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80800BE8: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80800BEC: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80800BF0: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80800BF4: jr          $ra
    // 0x80800BF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800BF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800E0C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0C20: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800E0C24: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800E0C28: lh          $v0, 0x4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4);
    // 0x800E0C2C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800E0C30: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800E0C34: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800E0C38: beq         $at, $zero, L_800E0CAC
    if (ctx->r1 == 0) {
        // 0x800E0C3C: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_800E0CAC;
    }
    // 0x800E0C3C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800E0C40: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800E0C44: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800E0C48: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x800E0C4C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E0C50: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x800E0C54: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x800E0C58: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800E0C5C: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x800E0C60: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
    // 0x800E0C64: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800E0C68: sra         $t2, $t6, 5
    ctx->r10 = S32(SIGNED(ctx->r14) >> 5);
    // 0x800E0C6C: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x800E0C70: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x800E0C74: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800E0C78: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800E0C7C: sb          $t1, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r9;
    // 0x800E0C80: sb          $t6, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r14;
    // 0x800E0C84: addu        $a3, $a0, $t3
    ctx->r7 = ADD32(ctx->r4, ctx->r11);
    // 0x800E0C88: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
    // 0x800E0C8C: lw          $t4, 0x10($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X10);
    // 0x800E0C90: andi        $t5, $t6, 0x1F
    ctx->r13 = ctx->r14 & 0X1F;
    // 0x800E0C94: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800E0C98: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x800E0C9C: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x800E0CA0: sw          $t8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r24;
    // 0x800E0CA4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800E0CA8: sb          $t9, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r25;
L_800E0CAC:
    // 0x800E0CAC: jr          $ra
    // 0x800E0CB0: nop

    return;
    // 0x800E0CB0: nop

;}
RECOMP_FUNC void func_800201A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800201A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800201A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800201AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800201B0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800201B4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800201B8: jal         0x8002FEC0
    // 0x800201BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800201BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800201C0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800201C4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800201C8: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800201CC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800201D0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800201D4: beq         $t8, $zero, L_80020278
    if (ctx->r24 == 0) {
        // 0x800201D8: nop
    
            goto L_80020278;
    }
    // 0x800201D8: nop

L_800201DC:
    // 0x800201DC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800201E0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800201E4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800201E8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800201EC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800201F0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800201F4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800201F8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800201FC: addiu       $t4, $t3, 0xC
    ctx->r12 = ADD32(ctx->r11, 0XC);
    // 0x80020200: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80020204: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80020208: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8002020C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80020210: bne         $t6, $t7, L_80020264
    if (ctx->r14 != ctx->r15) {
        // 0x80020214: nop
    
            goto L_80020264;
    }
    // 0x80020214: nop

    // 0x80020218: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x8002021C: lhu         $t9, 0x3A($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3A);
    // 0x80020220: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x80020224: beq         $t0, $zero, L_80020264
    if (ctx->r8 == 0) {
        // 0x80020228: nop
    
            goto L_80020264;
    }
    // 0x80020228: nop

    // 0x8002022C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80020230: beq         $t1, $zero, L_80020250
    if (ctx->r9 == 0) {
        // 0x80020234: nop
    
            goto L_80020250;
    }
    // 0x80020234: nop

    // 0x80020238: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002023C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80020240: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80020244: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80020248: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8002024C: sw          $t7, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r15;
L_80020250:
    // 0x80020250: jal         0x80020E74
    // 0x80020254: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80020E74(rdram, ctx);
        goto after_1;
    // 0x80020254: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80020258: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8002025C: jal         0x80020E40
    // 0x80020260: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80020E40(rdram, ctx);
        goto after_2;
    // 0x80020260: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
L_80020264:
    // 0x80020264: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80020268: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8002026C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80020270: bne         $t8, $zero, L_800201DC
    if (ctx->r24 != 0) {
        // 0x80020274: nop
    
            goto L_800201DC;
    }
    // 0x80020274: nop

L_80020278:
    // 0x80020278: jal         0x8002FEC0
    // 0x8002027C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x8002027C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80020280: b           L_80020288
    // 0x80020284: nop

        goto L_80020288;
    // 0x80020284: nop

L_80020288:
    // 0x80020288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002028C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80020290: jr          $ra
    // 0x80020294: nop

    return;
    // 0x80020294: nop

;}
RECOMP_FUNC void cosectionstor_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000F4: slti        $at, $a0, 0xA0
    ctx->r1 = SIGNED(ctx->r4) < 0XA0 ? 1 : 0;
    // 0x808000F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000FC: bne         $at, $zero, L_80800194
    if (ctx->r1 != 0) {
        // 0x80800100: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80800194;
    }
    // 0x80800100: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800104: addiu       $a0, $a0, -0xA0
    ctx->r4 = ADD32(ctx->r4, -0XA0);
    // 0x80800108: jal         0x800FF44C
    // 0x8080010C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_800FF44C(rdram, ctx);
        goto after_0;
    // 0x8080010C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800110: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800114: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80800118: addiu       $t7, $t7, 0x7198
    ctx->r15 = ADD32(ctx->r15, 0X7198);
    // 0x8080011C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800120: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80800124: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800128: beq         $a1, $zero, L_80800138
    if (ctx->r5 == 0) {
        // 0x8080012C: nop
    
            goto L_80800138;
    }
    // 0x8080012C: nop

    // 0x80800130: jal         0x8001B084
    // 0x80800134: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    heap_free(rdram, ctx);
        goto after_1;
    // 0x80800134: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
L_80800138:
    // 0x80800138: jal         0x8001ACCC
    // 0x8080013C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    heap_alloc(rdram, ctx);
        goto after_2;
    // 0x8080013C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x80800140: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80800144: jal         0x800DAA1C
    // 0x80800148: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800DAA1C(rdram, ctx);
        goto after_3;
    // 0x80800148: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8080014C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800150: addiu       $v1, $zero, 0x20
    ctx->r3 = ADD32(0, 0X20);
    // 0x80800154: sra         $t0, $v1, 5
    ctx->r8 = S32(SIGNED(ctx->r3) >> 5);
    // 0x80800158: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8080015C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80800160: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800164: jal         0x80088040
    // 0x80800168: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    _gccollectDll_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800168: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x8080016C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80800170: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80800174: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800178: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x8080017C: addiu       $t3, $t2, 0x7F
    ctx->r11 = ADD32(ctx->r10, 0X7F);
    // 0x80800180: sra         $t5, $t3, 7
    ctx->r13 = S32(SIGNED(ctx->r11) >> 7);
    // 0x80800184: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80800188: jal         0x80089F08
    // 0x8080018C: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    _subaddiestore_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x8080018C: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    after_5:
    // 0x80800190: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_80800194:
    // 0x80800194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800198: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080019C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void func_800C5008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5008: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C500C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C5010: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800C5014: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800C5018: addiu       $t6, $sp, 0x20
    ctx->r14 = ADD32(ctx->r29, 0X20);
    // 0x800C501C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C5020: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800C5024: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x800C5028: jal         0x800A8A04
    // 0x800C502C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_800A8A04(rdram, ctx);
        goto after_0;
    // 0x800C502C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800C5030: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800C5034: lui         $at, 0x4398
    ctx->r1 = S32(0X4398 << 16);
    // 0x800C5038: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C503C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800C5040: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800C5044: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800C5048: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C504C: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C5050: lui         $at, 0x4364
    ctx->r1 = S32(0X4364 << 16);
    // 0x800C5054: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C5058: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C505C: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800C5060: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x800C5064: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800C5068: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800C506C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800C5070: nop

    // 0x800C5074: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C5078: div.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C507C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C5080: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x800C5084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5088: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C508C: jr          $ra
    // 0x800C5090: nop

    return;
    // 0x800C5090: nop

;}
RECOMP_FUNC void func_800EC398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC39C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800EC3A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EC3A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800EC3A8: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800EC3AC: jal         0x800EE88C
    // 0x800EC3B0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x800EC3B0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x800EC3B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EC3B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EC3BC: jr          $ra
    // 0x800EC3C0: nop

    return;
    // 0x800EC3C0: nop

;}
RECOMP_FUNC void chtiptup_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1020, 0X1448) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1448
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1020, 0X1448));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1448
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1020, 0X1448));
;}
RECOMP_FUNC void _ncbasub_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089700: syscall     789
    recomp_syscall_handler(rdram, ctx, 0x80089700);
    return;
    // 0x80089704: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A8184(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8184: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8188: jr          $ra
    // 0x800A818C: lh          $v0, 0x7632($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7632);
    return;
    // 0x800A818C: lh          $v0, 0x7632($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7632);
;}
RECOMP_FUNC void gcegg_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800128: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x8080012C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800130: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80800134: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2678, 0X20C) << 16);
    // 0x80800138: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080013C: jr          $ra
    // 0x80800140: lbu         $v0, 0x20C($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(2678, 0X20C));
    return;
    // 0x80800140: lbu         $v0, 0x20C($v0)
    ctx->r2 = MEM_BU(ctx->r2, (int16_t)RELOC_LO16(2678, 0X20C));
;}
RECOMP_FUNC void gcmapDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800874: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800878: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080087C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800880: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80800884: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800888: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x8080088C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800890:
    // 0x80800890: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800894: sw          $zero, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = 0;
    // 0x80800898: sw          $zero, 0x90($v0)
    MEM_W(0X90, ctx->r2) = 0;
    // 0x8080089C: sw          $zero, 0x94($v0)
    MEM_W(0X94, ctx->r2) = 0;
    // 0x808008A0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x808008A4: bne         $v1, $a0, L_80800890
    if (ctx->r3 != ctx->r4) {
        // 0x808008A8: sw          $zero, 0x78($v0)
        MEM_W(0X78, ctx->r2) = 0;
            goto L_80800890;
    }
    // 0x808008A8: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    // 0x808008AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808008B0: jal         0x800BF744
    // 0x808008B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800BF744(rdram, ctx);
        goto after_0;
    // 0x808008B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008B8: jal         0x808006C0
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcmapDll_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808008C0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x808008C4: sb          $v0, 0x87($s0)
    MEM_B(0X87, ctx->r16) = ctx->r2;
    // 0x808008C8: sb          $v0, 0x86($s0)
    MEM_B(0X86, ctx->r16) = ctx->r2;
    // 0x808008CC: sb          $v0, 0x85($s0)
    MEM_B(0X85, ctx->r16) = ctx->r2;
    // 0x808008D0: jal         0x800EA05C
    // 0x808008D4: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    func_800EA05C(rdram, ctx);
        goto after_2;
    // 0x808008D4: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    after_2:
    // 0x808008D8: jal         0x80800000
    // 0x808008DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800000_gcmapDll(rdram, ctx);
        goto after_3;
    // 0x808008DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808008E0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x808008E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808008E8: jal         0x8001BBA0
    // 0x808008EC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    rare_memcpy(rdram, ctx);
        goto after_4;
    // 0x808008EC: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_4:
    // 0x808008F0: lhu         $v0, 0x5A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5A);
    // 0x808008F4: sb          $zero, 0x55($s0)
    MEM_B(0X55, ctx->r16) = 0;
    // 0x808008F8: sb          $zero, 0x29($s0)
    MEM_B(0X29, ctx->r16) = 0;
    // 0x808008FC: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x80800900: beq         $v0, $zero, L_8080096C
    if (ctx->r2 == 0) {
        // 0x80800904: sw          $zero, 0x14($s0)
        MEM_W(0X14, ctx->r16) = 0;
            goto L_8080096C;
    }
    // 0x80800904: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80800908: jal         0x800D674C
    // 0x8080090C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D674C(rdram, ctx);
        goto after_5;
    // 0x8080090C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800910: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80800914: jal         0x800D70D0
    // 0x80800918: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D70D0(rdram, ctx);
        goto after_6;
    // 0x80800918: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8080091C: jal         0x800D71F4
    // 0x80800920: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D71F4(rdram, ctx);
        goto after_7;
    // 0x80800920: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80800924: jal         0x800B2720
    // 0x80800928: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_800B2720(rdram, ctx);
        goto after_8;
    // 0x80800928: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_8:
    // 0x8080092C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80800930: jal         0x800B2840
    // 0x80800934: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_800B2840(rdram, ctx);
        goto after_9;
    // 0x80800934: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_9:
    // 0x80800938: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8080093C: jal         0x800B284C
    // 0x80800940: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_800B284C(rdram, ctx);
        goto after_10;
    // 0x80800940: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_10:
    // 0x80800944: beq         $v0, $zero, L_8080097C
    if (ctx->r2 == 0) {
        // 0x80800948: sw          $v0, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->r2;
            goto L_8080097C;
    }
    // 0x80800948: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x8080094C: jal         0x800EA068
    // 0x80800950: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_800EA068(rdram, ctx);
        goto after_11;
    // 0x80800950: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_11:
    // 0x80800954: beql        $v0, $zero, L_80800980
    if (ctx->r2 == 0) {
        // 0x80800958: lhu         $v0, 0x5C($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X5C);
            goto L_80800980;
    }
    goto skip_0;
    // 0x80800958: lhu         $v0, 0x5C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5C);
    skip_0:
    // 0x8080095C: jal         0x80088760
    // 0x80800960: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    _glzone_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x80800960: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_12:
    // 0x80800964: b           L_8080097C
    // 0x80800968: sw          $v0, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->r2;
        goto L_8080097C;
    // 0x80800968: sw          $v0, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->r2;
L_8080096C:
    // 0x8080096C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x80800970: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80800974: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80800978: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
L_8080097C:
    // 0x8080097C: lhu         $v0, 0x5C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X5C);
L_80800980:
    // 0x80800980: sw          $zero, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = 0;
    // 0x80800984: beql        $v0, $zero, L_808009D4
    if (ctx->r2 == 0) {
        // 0x80800988: sw          $zero, 0x38($s0)
        MEM_W(0X38, ctx->r16) = 0;
            goto L_808009D4;
    }
    goto skip_1;
    // 0x80800988: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    skip_1:
    // 0x8080098C: jal         0x800D674C
    // 0x80800990: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D674C(rdram, ctx);
        goto after_13;
    // 0x80800990: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x80800994: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x80800998: jal         0x800D70D0
    // 0x8080099C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D70D0(rdram, ctx);
        goto after_14;
    // 0x8080099C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_14:
    // 0x808009A0: jal         0x800D71F4
    // 0x808009A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D71F4(rdram, ctx);
        goto after_15;
    // 0x808009A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x808009A8: jal         0x800B2720
    // 0x808009AC: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    func_800B2720(rdram, ctx);
        goto after_16;
    // 0x808009AC: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_16:
    // 0x808009B0: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x808009B4: jal         0x800B2840
    // 0x808009B8: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    func_800B2840(rdram, ctx);
        goto after_17;
    // 0x808009B8: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_17:
    // 0x808009BC: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x808009C0: jal         0x800B284C
    // 0x808009C4: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    func_800B284C(rdram, ctx);
        goto after_18;
    // 0x808009C4: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_18:
    // 0x808009C8: b           L_808009E0
    // 0x808009CC: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
        goto L_808009E0;
    // 0x808009CC: sw          $v0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r2;
    // 0x808009D0: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
L_808009D4:
    // 0x808009D4: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x808009D8: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x808009DC: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
L_808009E0:
    // 0x808009E0: jal         0x800DBFF8
    // 0x808009E4: nop

    func_800DBFF8(rdram, ctx);
        goto after_19;
    // 0x808009E4: nop

    after_19:
    // 0x808009E8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x808009EC: sw          $v0, 0x178($s0)
    MEM_W(0X178, ctx->r16) = ctx->r2;
    // 0x808009F0: beql        $t8, $zero, L_80800A0C
    if (ctx->r24 == 0) {
        // 0x808009F4: sb          $zero, 0x28($s0)
        MEM_B(0X28, ctx->r16) = 0;
            goto L_80800A0C;
    }
    goto skip_2;
    // 0x808009F4: sb          $zero, 0x28($s0)
    MEM_B(0X28, ctx->r16) = 0;
    skip_2:
    // 0x808009F8: jal         0x800D731C
    // 0x808009FC: lhu         $a0, 0x5A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X5A);
    func_800D731C(rdram, ctx);
        goto after_20;
    // 0x808009FC: lhu         $a0, 0x5A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X5A);
    after_20:
    // 0x80800A00: b           L_80800A0C
    // 0x80800A04: sb          $v0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r2;
        goto L_80800A0C;
    // 0x80800A04: sb          $v0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r2;
    // 0x80800A08: sb          $zero, 0x28($s0)
    MEM_B(0X28, ctx->r16) = 0;
L_80800A0C:
    // 0x80800A0C: lw          $t9, 0x38($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X38);
    // 0x80800A10: beql        $t9, $zero, L_80800A2C
    if (ctx->r25 == 0) {
        // 0x80800A14: sb          $zero, 0x54($s0)
        MEM_B(0X54, ctx->r16) = 0;
            goto L_80800A2C;
    }
    goto skip_3;
    // 0x80800A14: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
    skip_3:
    // 0x80800A18: jal         0x800D731C
    // 0x80800A1C: lhu         $a0, 0x5C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X5C);
    func_800D731C(rdram, ctx);
        goto after_21;
    // 0x80800A1C: lhu         $a0, 0x5C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X5C);
    after_21:
    // 0x80800A20: b           L_80800A2C
    // 0x80800A24: sb          $v0, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r2;
        goto L_80800A2C;
    // 0x80800A24: sb          $v0, 0x54($s0)
    MEM_B(0X54, ctx->r16) = ctx->r2;
    // 0x80800A28: sb          $zero, 0x54($s0)
    MEM_B(0X54, ctx->r16) = 0;
L_80800A2C:
    // 0x80800A2C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800A30: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800A34: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800A38: beql        $t0, $zero, L_80800A4C
    if (ctx->r8 == 0) {
        // 0x80800A3C: sb          $zero, 0x2A($s0)
        MEM_B(0X2A, ctx->r16) = 0;
            goto L_80800A4C;
    }
    goto skip_4;
    // 0x80800A3C: sb          $zero, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = 0;
    skip_4:
    // 0x80800A40: b           L_80800A4C
    // 0x80800A44: sb          $t1, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r9;
        goto L_80800A4C;
    // 0x80800A44: sb          $t1, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r9;
    // 0x80800A48: sb          $zero, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = 0;
L_80800A4C:
    // 0x80800A4C: lw          $t2, 0x2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2C);
    // 0x80800A50: beql        $t2, $zero, L_80800A64
    if (ctx->r10 == 0) {
        // 0x80800A54: sb          $zero, 0x56($s0)
        MEM_B(0X56, ctx->r16) = 0;
            goto L_80800A64;
    }
    goto skip_5;
    // 0x80800A54: sb          $zero, 0x56($s0)
    MEM_B(0X56, ctx->r16) = 0;
    skip_5:
    // 0x80800A58: b           L_80800A64
    // 0x80800A5C: sb          $t3, 0x56($s0)
    MEM_B(0X56, ctx->r16) = ctx->r11;
        goto L_80800A64;
    // 0x80800A5C: sb          $t3, 0x56($s0)
    MEM_B(0X56, ctx->r16) = ctx->r11;
    // 0x80800A60: sb          $zero, 0x56($s0)
    MEM_B(0X56, ctx->r16) = 0;
L_80800A64:
    // 0x80800A64: jal         0x80087F78
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcmapsects_entrypoint_15(rdram, ctx);
        goto after_22;
    // 0x80800A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800A6C: jal         0x808005A8
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005A8_gcmapDll(rdram, ctx);
        goto after_23;
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800A74: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80800A78: sb          $t5, 0x57($s0)
    MEM_B(0X57, ctx->r16) = ctx->r13;
    // 0x80800A7C: sb          $t5, 0x2B($s0)
    MEM_B(0X2B, ctx->r16) = ctx->r13;
    // 0x80800A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A8C: jr          $ra
    // 0x80800A90: nop

    return;
    // 0x80800A90: nop

;}
RECOMP_FUNC void func_808009C0_chflamer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808009C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009C8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808009CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009D0: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x808009D4: jal         0x80100094
    // 0x808009D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009DC: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808009E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808009E4: beql        $a0, $zero, L_80800A24
    if (ctx->r4 == 0) {
        // 0x808009E8: lh          $t9, 0x4($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X4);
            goto L_80800A24;
    }
    goto skip_0;
    // 0x808009E8: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
    skip_0:
    // 0x808009EC: jal         0x80103F38
    // 0x808009F0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80103F38(rdram, ctx);
        goto after_1;
    // 0x808009F0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x808009F4: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808009F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009FC: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80800A00: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800A04: trunc.w.s   $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80800A08: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x80800A0C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800A10: nop

    // 0x80800A14: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x80800A18: b           L_80800A40
    // 0x80800A1C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_80800A40;
    // 0x80800A1C: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80800A20: lh          $t9, 0x4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4);
L_80800A24:
    // 0x80800A24: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x80800A28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800A2C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80800A30: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800A34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800A38: jal         0x800EE7F8
    // 0x80800A3C: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800A3C: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_2:
L_80800A40:
    // 0x80800A40: lbu         $t1, 0x14($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X14);
    // 0x80800A44: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800A48: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800A4C: beq         $t1, $zero, L_80800A84
    if (ctx->r9 == 0) {
        // 0x80800A50: nop
    
            goto L_80800A84;
    }
    // 0x80800A50: nop

    // 0x80800A54: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A58: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800A5C: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800A60: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800A64: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800A68: jal         0x800E3E8C
    // 0x80800A6C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_800E3E8C(rdram, ctx);
        goto after_3;
    // 0x80800A6C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80800A70: bne         $v0, $zero, L_80800A84
    if (ctx->r2 != 0) {
        // 0x80800A74: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800A84;
    }
    // 0x80800A74: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800A78: jal         0x800E3E8C
    // 0x80800A7C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800E3E8C(rdram, ctx);
        goto after_4;
    // 0x80800A7C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800A80: beq         $v0, $zero, L_80800AF4
    if (ctx->r2 == 0) {
        // 0x80800A84: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1088, 0XB1C) << 16);
            goto L_80800AF4;
    }
L_80800A84:
    // 0x80800A84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1088, 0XB1C) << 16);
    // 0x80800A88: lwc1        $f12, 0xB1C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1088, 0XB1C));
    // 0x80800A8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A90: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800A94: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800A98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A9C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800AA0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800AA4: jal         0x800DC178
    // 0x80800AA8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800AA8: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80800AAC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1088, 0XB7C) << 16);
    // 0x80800AB0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800AB4: addiu       $a1, $a1, 0xB7C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1088, 0XB7C));
    // 0x80800AB8: jal         0x800F2F60
    // 0x80800ABC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800F2F60(rdram, ctx);
        goto after_6;
    // 0x80800ABC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x80800AC0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800AC4: jal         0x800EE7F8
    // 0x80800AC8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800AC8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_7:
    // 0x80800ACC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800AD0: jal         0x800C8CB8
    // 0x80800AD4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800C8CB8(rdram, ctx);
        goto after_8;
    // 0x80800AD4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_8:
    // 0x80800AD8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800ADC: jal         0x800C8E84
    // 0x80800AE0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800C8E84(rdram, ctx);
        goto after_9;
    // 0x80800AE0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_9:
    // 0x80800AE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800AE8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800AEC: jal         0x800C8E54
    // 0x80800AF0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800C8E54(rdram, ctx);
        goto after_10;
    // 0x80800AF0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_10:
L_80800AF4:
    // 0x80800AF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800AF8: sb          $t2, 0x14($s0)
    MEM_B(0X14, ctx->r16) = ctx->r10;
    // 0x80800AFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B04: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800B08: jr          $ra
    // 0x80800B0C: nop

    return;
    // 0x80800B0C: nop

;}
RECOMP_FUNC void chlagoonbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1052, 0X804) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x804
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1052, 0X804));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x804
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1052, 0X804));
;}
RECOMP_FUNC void _bamovegoto_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084DB8: syscall     137
    recomp_syscall_handler(rdram, ctx, 0x80084DB8);
    return;
    // 0x80084DBC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801C60_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C60: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801C64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801C68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801C6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801C70: jal         0x80106790
    // 0x80801C74: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801C74: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80801C78: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80801C7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801C80: jal         0x80100094
    // 0x80801C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801C88: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80801C8C: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x80801C90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801C94: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801C98: srl         $t6, $a0, 10
    ctx->r14 = S32(U32(ctx->r4) >> 10);
    // 0x80801C9C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80801CA0: beq         $t6, $at, L_80801CC4
    if (ctx->r14 == ctx->r1) {
        // 0x80801CA4: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80801CC4;
    }
    // 0x80801CA4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80801CA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801CAC: beq         $t6, $at, L_80801CFC
    if (ctx->r14 == ctx->r1) {
        // 0x80801CB0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801CFC;
    }
    // 0x80801CB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801CB4: beq         $t6, $at, L_80801D4C
    if (ctx->r14 == ctx->r1) {
        // 0x80801CB8: addiu       $a1, $zero, -0x7
        ctx->r5 = ADD32(0, -0X7);
            goto L_80801D4C;
    }
    // 0x80801CB8: addiu       $a1, $zero, -0x7
    ctx->r5 = ADD32(0, -0X7);
    // 0x80801CBC: b           L_80801D64
    // 0x80801CC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_80801D64;
    // 0x80801CC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80801CC4:
    // 0x80801CC4: jal         0x80089CC0
    // 0x80801CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80801CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801CCC: jal         0x80089C90
    // 0x80801CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80801CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801CD4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80801CD8: bne         $v0, $at, L_80801CEC
    if (ctx->r2 != ctx->r1) {
        // 0x80801CDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801CEC;
    }
    // 0x80801CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801CE0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80801CE4: jal         0x80801C18
    // 0x80801CE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80801C18_chdodgemcontrol(rdram, ctx);
        goto after_4;
    // 0x80801CE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
L_80801CEC:
    // 0x80801CEC: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x80801CF0: srl         $v1, $a0, 10
    ctx->r3 = S32(U32(ctx->r4) >> 10);
    // 0x80801CF4: b           L_80801D60
    // 0x80801CF8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_80801D60;
    // 0x80801CF8: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80801CFC:
    // 0x80801CFC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801D00: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D08: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80801D0C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801D10: nop

    // 0x80801D14: bc1f        L_80801D34
    if (!c1cs) {
        // 0x80801D18: nop
    
            goto L_80801D34;
    }
    // 0x80801D18: nop

    // 0x80801D1C: jal         0x800D8FF8
    // 0x80801D20: nop

    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x80801D20: nop

    after_5:
    // 0x80801D24: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80801D28: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80801D2C: b           L_80801D3C
    // 0x80801D30: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80801D3C;
    // 0x80801D30: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80801D34:
    // 0x80801D34: jal         0x80801C18
    // 0x80801D38: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80801C18_chdodgemcontrol(rdram, ctx);
        goto after_6;
    // 0x80801D38: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_6:
L_80801D3C:
    // 0x80801D3C: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x80801D40: srl         $v1, $a0, 10
    ctx->r3 = S32(U32(ctx->r4) >> 10);
    // 0x80801D44: b           L_80801D60
    // 0x80801D48: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_80801D60;
    // 0x80801D48: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80801D4C:
    // 0x80801D4C: jal         0x80089CC0
    // 0x80801D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x80801D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80801D54: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x80801D58: srl         $v1, $a0, 10
    ctx->r3 = S32(U32(ctx->r4) >> 10);
    // 0x80801D5C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80801D60:
    // 0x80801D60: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80801D64:
    // 0x80801D64: beq         $v1, $at, L_80801E08
    if (ctx->r3 == ctx->r1) {
        // 0x80801D68: addiu       $t6, $sp, 0x30
        ctx->r14 = ADD32(ctx->r29, 0X30);
            goto L_80801E08;
    }
    // 0x80801D68: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80801D6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801D70: bne         $v1, $at, L_80801E68
    if (ctx->r3 != ctx->r1) {
        // 0x80801D74: addiu       $t0, $sp, 0x3C
        ctx->r8 = ADD32(ctx->r29, 0X3C);
            goto L_80801E68;
    }
    // 0x80801D74: addiu       $t0, $sp, 0x3C
    ctx->r8 = ADD32(ctx->r29, 0X3C);
    // 0x80801D78: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1752, 0X4EB4) << 16);
    // 0x80801D7C: addiu       $t1, $t1, 0x4EB4
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1752, 0X4EB4));
    // 0x80801D80: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80801D84: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80801D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D8C: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80801D90: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80801D94: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80801D98: jal         0x80089C90
    // 0x80801D9C: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80801D9C: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    after_8:
    // 0x80801DA0: lw          $t5, 0x6C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X6C);
    // 0x80801DA4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80801DA8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80801DAC: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80801DB0: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80801DB4: lbu         $t8, 0xB6($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XB6);
    // 0x80801DB8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80801DBC: addu        $t2, $a1, $t9
    ctx->r10 = ADD32(ctx->r5, ctx->r25);
    // 0x80801DC0: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x80801DC4: jal         0x800C8E84
    // 0x80801DC8: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    func_800C8E84(rdram, ctx);
        goto after_9;
    // 0x80801DC8: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    after_9:
    // 0x80801DCC: jal         0x80089C90
    // 0x80801DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80801DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801DD4: bnel        $v0, $zero, L_80801DFC
    if (ctx->r2 != 0) {
        // 0x80801DD8: lhu         $a0, 0x72($s0)
        ctx->r4 = MEM_HU(ctx->r16, 0X72);
            goto L_80801DFC;
    }
    goto skip_0;
    // 0x80801DD8: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x80801DDC: lw          $t1, 0x6C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X6C);
    // 0x80801DE0: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80801DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801DE8: andi        $t3, $t1, 0x1FF
    ctx->r11 = ctx->r9 & 0X1FF;
    // 0x80801DEC: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x80801DF0: jal         0x800FFAB0
    // 0x80801DF4: sb          $zero, 0xAC($t5)
    MEM_B(0XAC, ctx->r13) = 0;
    func_800FFAB0(rdram, ctx);
        goto after_11;
    // 0x80801DF4: sb          $zero, 0xAC($t5)
    MEM_B(0XAC, ctx->r13) = 0;
    after_11:
    // 0x80801DF8: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
L_80801DFC:
    // 0x80801DFC: srl         $t4, $a0, 10
    ctx->r12 = S32(U32(ctx->r4) >> 10);
    // 0x80801E00: b           L_80801E68
    // 0x80801E04: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
        goto L_80801E68;
    // 0x80801E04: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
L_80801E08:
    // 0x80801E08: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1752, 0X4EC0) << 16);
    // 0x80801E0C: addiu       $t7, $t7, 0x4EC0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1752, 0X4EC0));
    // 0x80801E10: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80801E14: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80801E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E1C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80801E20: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80801E24: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x80801E28: jal         0x80089C90
    // 0x80801E2C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x80801E2C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    after_12:
    // 0x80801E30: lw          $t1, 0x6C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X6C);
    // 0x80801E34: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80801E38: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80801E3C: andi        $t0, $t1, 0x1FF
    ctx->r8 = ctx->r9 & 0X1FF;
    // 0x80801E40: addu        $t3, $t2, $t0
    ctx->r11 = ADD32(ctx->r10, ctx->r8);
    // 0x80801E44: lbu         $t5, 0xB6($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0XB6);
    // 0x80801E48: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x80801E4C: addu        $t8, $a1, $t4
    ctx->r24 = ADD32(ctx->r5, ctx->r12);
    // 0x80801E50: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x80801E54: jal         0x800C8E84
    // 0x80801E58: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    func_800C8E84(rdram, ctx);
        goto after_13;
    // 0x80801E58: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    after_13:
    // 0x80801E5C: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x80801E60: srl         $t6, $a0, 10
    ctx->r14 = S32(U32(ctx->r4) >> 10);
    // 0x80801E64: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_80801E68:
    // 0x80801E68: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80801E6C: beql        $at, $zero, L_80801EF0
    if (ctx->r1 == 0) {
        // 0x80801E70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801EF0;
    }
    goto skip_1;
    // 0x80801E70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80801E74: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x80801E78: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80801E7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801E80: andi        $t1, $t9, 0x1FF
    ctx->r9 = ctx->r25 & 0X1FF;
    // 0x80801E84: addu        $v0, $t7, $t1
    ctx->r2 = ADD32(ctx->r15, ctx->r9);
    // 0x80801E88: lbu         $v1, 0xAC($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XAC);
    // 0x80801E8C: beq         $v1, $at, L_80801EA4
    if (ctx->r3 == ctx->r1) {
        // 0x80801E90: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801EA4;
    }
    // 0x80801E90: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801E94: beq         $v1, $at, L_80801EE4
    if (ctx->r3 == ctx->r1) {
        // 0x80801E98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801EE4;
    }
    // 0x80801E98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E9C: b           L_80801EF0
    // 0x80801EA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801EF0;
    // 0x80801EA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801EA4:
    // 0x80801EA4: lbu         $t2, 0xB6($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XB6);
    // 0x80801EA8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1752, 0X4ECC) << 16);
    // 0x80801EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EB0: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x80801EB4: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80801EB8: jal         0x80801B94
    // 0x80801EBC: lh          $a1, 0x4ECC($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1752, 0X4ECC));
    func_80801B94_chdodgemcontrol(rdram, ctx);
        goto after_14;
    // 0x80801EBC: lh          $a1, 0x4ECC($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1752, 0X4ECC));
    after_14:
    // 0x80801EC0: lw          $t5, 0x6C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X6C);
    // 0x80801EC4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80801EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801ECC: andi        $t4, $t5, 0x1FF
    ctx->r12 = ctx->r13 & 0X1FF;
    // 0x80801ED0: addu        $t8, $t3, $t4
    ctx->r24 = ADD32(ctx->r11, ctx->r12);
    // 0x80801ED4: jal         0x800FFAB0
    // 0x80801ED8: sb          $zero, 0xAC($t8)
    MEM_B(0XAC, ctx->r24) = 0;
    func_800FFAB0(rdram, ctx);
        goto after_15;
    // 0x80801ED8: sb          $zero, 0xAC($t8)
    MEM_B(0XAC, ctx->r24) = 0;
    after_15:
    // 0x80801EDC: b           L_80801EF0
    // 0x80801EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801EF0;
    // 0x80801EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801EE4:
    // 0x80801EE4: jal         0x800FFAB0
    // 0x80801EE8: sb          $zero, 0xAC($v0)
    MEM_B(0XAC, ctx->r2) = 0;
    func_800FFAB0(rdram, ctx);
        goto after_16;
    // 0x80801EE8: sb          $zero, 0xAC($v0)
    MEM_B(0XAC, ctx->r2) = 0;
    after_16:
    // 0x80801EEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801EF0:
    // 0x80801EF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801EF4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80801EF8: jr          $ra
    // 0x80801EFC: nop

    return;
    // 0x80801EFC: nop

;}
RECOMP_FUNC void func_80801238_chstonepillar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801238: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080123C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801240: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801244: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801248: jal         0x80100094
    // 0x8080124C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080124C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801250: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80801254: jal         0x800D9078
    // 0x80801258: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80801258: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x8080125C: beql        $v0, $zero, L_808012BC
    if (ctx->r2 == 0) {
        // 0x80801260: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_808012BC;
    }
    goto skip_0;
    // 0x80801260: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80801264: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80801268: addiu       $at, $zero, 0x19F
    ctx->r1 = ADD32(0, 0X19F);
    // 0x8080126C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80801270: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80801274: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x80801278: beql        $t8, $at, L_808012BC
    if (ctx->r24 == ctx->r1) {
        // 0x8080127C: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_808012BC;
    }
    goto skip_1;
    // 0x8080127C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80801280: jal         0x800D0B68
    // 0x80801284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80801284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801288: bne         $v0, $zero, L_808012B8
    if (ctx->r2 != 0) {
        // 0x8080128C: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_808012B8;
    }
    // 0x8080128C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80801290: lh          $t0, 0x2C($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X2C);
    // 0x80801294: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801298: beql        $t0, $at, L_808012BC
    if (ctx->r8 == ctx->r1) {
        // 0x8080129C: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_808012BC;
    }
    goto skip_2;
    // 0x8080129C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x808012A0: jal         0x8080112C
    // 0x808012A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080112C_chstonepillar(rdram, ctx);
        goto after_3;
    // 0x808012A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808012A8: beql        $v0, $zero, L_808012BC
    if (ctx->r2 == 0) {
        // 0x808012AC: lw          $t1, 0x28($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X28);
            goto L_808012BC;
    }
    goto skip_3;
    // 0x808012AC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    skip_3:
    // 0x808012B0: jal         0x800FC660
    // 0x808012B4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_4;
    // 0x808012B4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_4:
L_808012B8:
    // 0x808012B8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
L_808012BC:
    // 0x808012BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808012C0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808012C4: lwc1        $f6, 0x24($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X24);
    // 0x808012C8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808012CC: nop

    // 0x808012D0: bc1f        L_80801354
    if (!c1cs) {
        // 0x808012D4: nop
    
            goto L_80801354;
    }
    // 0x808012D4: nop

    // 0x808012D8: jal         0x800D8FF8
    // 0x808012DC: nop

    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x808012DC: nop

    after_5:
    // 0x808012E0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x808012E4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808012E8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x808012EC: lwc1        $f8, 0x24($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X24);
    // 0x808012F0: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x808012F4: jal         0x800EE7F8
    // 0x808012F8: swc1        $f10, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x808012F8: swc1        $f10, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f10.u32l;
    after_6:
    // 0x808012FC: lui         $at, 0xC0F0
    ctx->r1 = S32(0XC0F0 << 16);
    // 0x80801300: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801304: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80801308: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080130C: jal         0x800DC178
    // 0x80801310: nop

    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80801310: nop

    after_7:
    // 0x80801314: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801318: lui         $at, 0xC0F0
    ctx->r1 = S32(0XC0F0 << 16);
    // 0x8080131C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801320: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80801324: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80801328: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080132C: jal         0x800DC178
    // 0x80801330: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80801330: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_8:
    // 0x80801334: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801338: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080133C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80801340: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80801344: jal         0x800EE7F8
    // 0x80801348: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80801348: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x8080134C: b           L_80801360
    // 0x80801350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801360;
    // 0x80801350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801354:
    // 0x80801354: jal         0x800EE7F8
    // 0x80801358: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80801358: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_10:
    // 0x8080135C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801360:
    // 0x80801360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801364: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801368: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080136C: jr          $ra
    // 0x80801370: nop

    return;
    // 0x80801370: nop

;}
RECOMP_FUNC void _badata_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846D0: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x800846D0);
    return;
    // 0x800846D4: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_80802180_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802180: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80802184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802188: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080218C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802190: jal         0x80100094
    // 0x80802194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802194: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802198: jal         0x800D8FF8
    // 0x8080219C: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8080219C: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808021A0: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x808021A4: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808021A8: jal         0x800F1DCC
    // 0x808021AC: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x808021AC: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    after_2:
    // 0x808021B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4BF4) << 16);
    // 0x808021B4: lwc1        $f6, 0x4BF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4BF4));
    // 0x808021B8: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808021BC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808021C0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808021C4: jal         0x800138D0
    // 0x808021C8: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    func_800138D0(rdram, ctx);
        goto after_3;
    // 0x808021C8: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x808021CC: jal         0x800F2100
    // 0x808021D0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x808021D0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x808021D4: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x808021D8: jal         0x808046EC
    // 0x808021DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808046EC_chdodgemcontrol(rdram, ctx);
        goto after_5;
    // 0x808021DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808021E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4BF8) << 16);
    // 0x808021E4: lwc1        $f10, 0x4BF8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4BF8));
    // 0x808021E8: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x808021EC: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x808021F0: lw          $v0, 0x8C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8C);
    // 0x808021F4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808021F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4BFC) << 16);
    // 0x808021FC: lwc1        $f16, 0x4BFC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4BFC));
    // 0x80802200: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80802204: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80802208: lui         $a2, 0xC220
    ctx->r6 = S32(0XC220 << 16);
    // 0x8080220C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80802210: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80802214: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80802218: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8080221C: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x80802220: jal         0x800EEB9C
    // 0x80802224: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_6;
    // 0x80802224: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_6:
    // 0x80802228: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080222C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80802230: jal         0x800EF04C
    // 0x80802234: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80802234: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_7:
    // 0x80802238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080223C: jal         0x80102CF4
    // 0x80802240: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    func_80102CF4(rdram, ctx);
        goto after_8;
    // 0x80802240: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    after_8:
    // 0x80802244: bne         $v0, $zero, L_80802254
    if (ctx->r2 != 0) {
        // 0x80802248: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802254;
    }
    // 0x80802248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080224C: jal         0x80102B2C
    // 0x80802250: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    func_80102B2C(rdram, ctx);
        goto after_9;
    // 0x80802250: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    after_9:
L_80802254:
    // 0x80802254: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x80802258: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080225C: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80802260: lwc1        $f6, 0xC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80802264: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    // 0x80802268: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080226C: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x80802270: jal         0x800EEB9C
    // 0x80802274: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_10;
    // 0x80802274: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_10:
    // 0x80802278: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080227C: jal         0x800EF04C
    // 0x80802280: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    func_800EF04C(rdram, ctx);
        goto after_11;
    // 0x80802280: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    after_11:
    // 0x80802284: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80802288: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080228C: jal         0x800EEB9C
    // 0x80802290: lui         $a2, 0x4243
    ctx->r6 = S32(0X4243 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_12;
    // 0x80802290: lui         $a2, 0x4243
    ctx->r6 = S32(0X4243 << 16);
    after_12:
    // 0x80802294: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x80802298: jal         0x800EF04C
    // 0x8080229C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_13;
    // 0x8080229C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x808022A0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x808022A4: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808022A8: jal         0x800EEB9C
    // 0x808022AC: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    func_800EEB9C(rdram, ctx);
        goto after_14;
    // 0x808022AC: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    after_14:
    // 0x808022B0: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x808022B4: jal         0x800EF04C
    // 0x808022B8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    func_800EF04C(rdram, ctx);
        goto after_15;
    // 0x808022B8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    after_15:
    // 0x808022BC: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808022C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808022C4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808022C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C00) << 16);
    // 0x808022CC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x808022D0: nop

    // 0x808022D4: bc1fl       L_808022E8
    if (!c1cs) {
        // 0x808022D8: lwc1        $f0, 0x70($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
            goto L_808022E8;
    }
    goto skip_0;
    // 0x808022D8: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    skip_0:
    // 0x808022DC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x808022E0: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x808022E4: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
L_808022E8:
    // 0x808022E8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808022EC: nop

    // 0x808022F0: bc1fl       L_80802304
    if (!c1cs) {
        // 0x808022F4: lwc1        $f18, 0x4($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
            goto L_80802304;
    }
    goto skip_1;
    // 0x808022F4: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x808022F8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x808022FC: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80802300: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
L_80802304:
    // 0x80802304: lwc1        $f4, 0x4C00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C00));
    // 0x80802308: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8080230C: nop

    // 0x80802310: bc1f        L_80802354
    if (!c1cs) {
        // 0x80802314: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1752, 0X4C04) << 16);
            goto L_80802354;
    }
    // 0x80802314: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C04) << 16);
    // 0x80802318: lwc1        $f6, 0x4C04($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C04));
    // 0x8080231C: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80802320: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802324: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80802328: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8080232C: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x80802330: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x80802334: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80802338: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8080233C: jal         0x800EEB9C
    // 0x80802340: nop

    func_800EEB9C(rdram, ctx);
        goto after_16;
    // 0x80802340: nop

    after_16:
    // 0x80802344: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080234C: jal         0x80802104
    // 0x80802350: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    func_80802104_chdodgemcontrol(rdram, ctx);
        goto after_17;
    // 0x80802350: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    after_17:
L_80802354:
    // 0x80802354: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C08) << 16);
    // 0x80802358: lwc1        $f6, 0x4C08($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C08));
    // 0x8080235C: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80802360: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80802364: nop

    // 0x80802368: bc1f        L_808023CC
    if (!c1cs) {
        // 0x8080236C: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1752, 0X4C0C) << 16);
            goto L_808023CC;
    }
    // 0x8080236C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C0C) << 16);
    // 0x80802370: lwc1        $f8, 0x4C0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C0C));
    // 0x80802374: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80802378: lui         $a2, 0x4243
    ctx->r6 = S32(0X4243 << 16);
    // 0x8080237C: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x80802380: jal         0x800EEB9C
    // 0x80802384: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_18;
    // 0x80802384: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_18:
    // 0x80802388: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8080238C: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80802390: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80802394: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802398: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8080239C: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x808023A0: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x808023A4: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808023A8: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x808023AC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808023B0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808023B4: jal         0x800EEB9C
    // 0x808023B8: nop

    func_800EEB9C(rdram, ctx);
        goto after_19;
    // 0x808023B8: nop

    after_19:
    // 0x808023BC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808023C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808023C4: jal         0x80802104
    // 0x808023C8: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    func_80802104_chdodgemcontrol(rdram, ctx);
        goto after_20;
    // 0x808023C8: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    after_20:
L_808023CC:
    // 0x808023CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C10) << 16);
    // 0x808023D0: lwc1        $f0, 0x4C10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C10));
    // 0x808023D4: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x808023D8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808023DC: nop

    // 0x808023E0: bc1f        L_80802428
    if (!c1cs) {
        // 0x808023E4: nop
    
            goto L_80802428;
    }
    // 0x808023E4: nop

    // 0x808023E8: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x808023EC: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x808023F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808023F4: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x808023F8: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x808023FC: lui         $a1, 0x4387
    ctx->r5 = S32(0X4387 << 16);
    // 0x80802400: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80802404: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80802408: jal         0x800EEB9C
    // 0x8080240C: nop

    func_800EEB9C(rdram, ctx);
        goto after_21;
    // 0x8080240C: nop

    after_21:
    // 0x80802410: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80802414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802418: jal         0x80802104
    // 0x8080241C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    func_80802104_chdodgemcontrol(rdram, ctx);
        goto after_22;
    // 0x8080241C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    after_22:
    // 0x80802420: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C14) << 16);
    // 0x80802424: lwc1        $f0, 0x4C14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C14));
L_80802428:
    // 0x80802428: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C18) << 16);
    // 0x8080242C: lwc1        $f2, 0x4C18($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C18));
    // 0x80802430: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80802434: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80802438: nop

    // 0x8080243C: bc1fl       L_808024B0
    if (!c1cs) {
        // 0x80802440: lwc1        $f18, 0xC($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
            goto L_808024B0;
    }
    goto skip_2;
    // 0x80802440: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    skip_2:
    // 0x80802444: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x80802448: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080244C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80802450: jal         0x800EEB9C
    // 0x80802454: lui         $a2, 0x4243
    ctx->r6 = S32(0X4243 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_23;
    // 0x80802454: lui         $a2, 0x4243
    ctx->r6 = S32(0X4243 << 16);
    after_23:
    // 0x80802458: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8080245C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80802460: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80802464: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802468: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8080246C: lui         $a1, 0x4387
    ctx->r5 = S32(0X4387 << 16);
    // 0x80802470: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80802474: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80802478: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x8080247C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80802480: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80802484: jal         0x800EEB9C
    // 0x80802488: nop

    func_800EEB9C(rdram, ctx);
        goto after_24;
    // 0x80802488: nop

    after_24:
    // 0x8080248C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80802490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802494: jal         0x80802104
    // 0x80802498: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    func_80802104_chdodgemcontrol(rdram, ctx);
        goto after_25;
    // 0x80802498: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    after_25:
    // 0x8080249C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C1C) << 16);
    // 0x808024A0: lwc1        $f2, 0x4C1C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C1C));
    // 0x808024A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C20) << 16);
    // 0x808024A8: lwc1        $f0, 0x4C20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C20));
    // 0x808024AC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
L_808024B0:
    // 0x808024B0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808024B4: nop

    // 0x808024B8: bc1fl       L_80802504
    if (!c1cs) {
        // 0x808024BC: lwc1        $f16, 0x64($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
            goto L_80802504;
    }
    goto skip_3;
    // 0x808024BC: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    skip_3:
    // 0x808024C0: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x808024C4: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x808024C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808024CC: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x808024D0: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x808024D4: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x808024D8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x808024DC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808024E0: jal         0x800EEB9C
    // 0x808024E4: nop

    func_800EEB9C(rdram, ctx);
        goto after_26;
    // 0x808024E4: nop

    after_26:
    // 0x808024E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x808024EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808024F0: jal         0x80802104
    // 0x808024F4: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    func_80802104_chdodgemcontrol(rdram, ctx);
        goto after_27;
    // 0x808024F4: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    after_27:
    // 0x808024F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C24) << 16);
    // 0x808024FC: lwc1        $f2, 0x4C24($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C24));
    // 0x80802500: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
L_80802504:
    // 0x80802504: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80802508: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    // 0x8080250C: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80802510: nop

    // 0x80802514: bc1f        L_8080256C
    if (!c1cs) {
        // 0x80802518: nop
    
            goto L_8080256C;
    }
    // 0x80802518: nop

    // 0x8080251C: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x80802520: jal         0x800EEB9C
    // 0x80802524: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_28;
    // 0x80802524: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_28:
    // 0x80802528: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8080252C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80802530: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80802534: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80802538: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8080253C: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x80802540: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80802544: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80802548: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x8080254C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80802550: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80802554: jal         0x800EEB9C
    // 0x80802558: nop

    func_800EEB9C(rdram, ctx);
        goto after_29;
    // 0x80802558: nop

    after_29:
    // 0x8080255C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802560: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802564: jal         0x80802104
    // 0x80802568: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    func_80802104_chdodgemcontrol(rdram, ctx);
        goto after_30;
    // 0x80802568: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    after_30:
L_8080256C:
    // 0x8080256C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C28) << 16);
    // 0x80802570: lwc1        $f6, 0x4C28($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C28));
    // 0x80802574: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80802578: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C2C) << 16);
    // 0x8080257C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80802580: nop

    // 0x80802584: bc1f        L_808025C8
    if (!c1cs) {
        // 0x80802588: nop
    
            goto L_808025C8;
    }
    // 0x80802588: nop

    // 0x8080258C: lwc1        $f8, 0x4C2C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C2C));
    // 0x80802590: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80802594: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80802598: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8080259C: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x808025A0: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x808025A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808025A8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808025AC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808025B0: jal         0x800EEB9C
    // 0x808025B4: nop

    func_800EEB9C(rdram, ctx);
        goto after_31;
    // 0x808025B4: nop

    after_31:
    // 0x808025B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808025BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808025C0: jal         0x80802104
    // 0x808025C4: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    func_80802104_chdodgemcontrol(rdram, ctx);
        goto after_32;
    // 0x808025C4: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_32:
L_808025C8:
    // 0x808025C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C30) << 16);
    // 0x808025CC: lwc1        $f8, 0x4C30($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C30));
    // 0x808025D0: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x808025D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C34) << 16);
    // 0x808025D8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x808025DC: nop

    // 0x808025E0: bc1fl       L_80802648
    if (!c1cs) {
        // 0x808025E4: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_80802648;
    }
    goto skip_4;
    // 0x808025E4: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    skip_4:
    // 0x808025E8: lwc1        $f10, 0x4C34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C34));
    // 0x808025EC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808025F0: lui         $a2, 0x4243
    ctx->r6 = S32(0X4243 << 16);
    // 0x808025F4: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x808025F8: jal         0x800EEB9C
    // 0x808025FC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_33;
    // 0x808025FC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_33:
    // 0x80802600: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80802604: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80802608: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x8080260C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802610: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80802614: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80802618: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8080261C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80802620: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x80802624: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80802628: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8080262C: jal         0x800EEB9C
    // 0x80802630: nop

    func_800EEB9C(rdram, ctx);
        goto after_34;
    // 0x80802630: nop

    after_34:
    // 0x80802634: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80802638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080263C: jal         0x80802104
    // 0x80802640: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    func_80802104_chdodgemcontrol(rdram, ctx);
        goto after_35;
    // 0x80802640: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    after_35:
    // 0x80802644: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
L_80802648:
    // 0x80802648: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x8080264C: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80802650: jal         0x800EEB9C
    // 0x80802654: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EEB9C(rdram, ctx);
        goto after_36;
    // 0x80802654: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_36:
    // 0x80802658: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080265C: jal         0x800EF04C
    // 0x80802660: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    func_800EF04C(rdram, ctx);
        goto after_37;
    // 0x80802660: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    after_37:
    // 0x80802664: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802668: jal         0x800EF334
    // 0x8080266C: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    func_800EF334(rdram, ctx);
        goto after_38;
    // 0x8080266C: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    after_38:
    // 0x80802670: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80802674: jal         0x800EF04C
    // 0x80802678: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EF04C(rdram, ctx);
        goto after_39;
    // 0x80802678: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_39:
    // 0x8080267C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80802680: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80802684: jal         0x800EF334
    // 0x80802688: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    func_800EF334(rdram, ctx);
        goto after_40;
    // 0x80802688: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    after_40:
    // 0x8080268C: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x80802690: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802694: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80802698: lwc1        $f0, 0x18($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X18);
    // 0x8080269C: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x808026A0: nop

    // 0x808026A4: bc1t        L_808026B4
    if (c1cs) {
        // 0x808026A8: nop
    
            goto L_808026B4;
    }
    // 0x808026A8: nop

    // 0x808026AC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x808026B0: swc1        $f6, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f6.u32l;
L_808026B4:
    // 0x808026B4: jal         0x808039B8
    // 0x808026B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808039B8_chdodgemcontrol(rdram, ctx);
        goto after_41;
    // 0x808026B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x808026BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808026C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808026C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x808026C8: jr          $ra
    // 0x808026CC: nop

    return;
    // 0x808026CC: nop

;}
RECOMP_FUNC void gccubesearch_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002D0: jal         0x80800194
    // 0x808002D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    gccubesearch_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808002D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x808002D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002E0: jr          $ra
    // 0x808002E4: nop

    return;
    // 0x808002E4: nop

;}
RECOMP_FUNC void func_80800A70_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A78: jal         0x80800114
    // 0x80800A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800114_bsmumswim(rdram, ctx);
        goto after_0;
    // 0x80800A7C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A80: jal         0x80082FE0
    // 0x80800A84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800A84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A90: jr          $ra
    // 0x80800A94: nop

    return;
    // 0x80800A94: nop

;}
RECOMP_FUNC void func_808007A4_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007B0: jal         0x808002D4
    // 0x808007B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808002D4_bsbansack(rdram, ctx);
        goto after_0;
    // 0x808007B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808007B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007BC: addiu       $a1, $zero, 0x28A
    ctx->r5 = ADD32(0, 0X28A);
    // 0x808007C0: jal         0x8008CCBC
    // 0x808007C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x808007C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x808007C8: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x808007CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808007DC: jal         0x8009FFD8
    // 0x808007E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808007E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007E8: jal         0x8009BCB4
    // 0x808007EC: lui         $a1, 0xC448
    ctx->r5 = S32(0XC448 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_3;
    // 0x808007EC: lui         $a1, 0xC448
    ctx->r5 = S32(0XC448 << 16);
    after_3:
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F4: jal         0x8009BA58
    // 0x808007F8: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_4;
    // 0x808007F8: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_4:
    // 0x808007FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800800: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800804: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800808: jr          $ra
    // 0x8080080C: nop

    return;
    // 0x8080080C: nop

;}
RECOMP_FUNC void func_808001EC_chfactorytrashbelt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001EC: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x808001F0: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x808001F4: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x808001F8: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x808001FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800200: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80800204: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80800208: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8080020C: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80800210: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80800214: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80800218: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8080021C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80800220: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80800224: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80800228: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8080022C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800230: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800234: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800238: jal         0x80100094
    // 0x8080023C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080023C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800240: lhu         $t6, 0x76($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X76);
    // 0x80800244: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800248: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x8080024C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800250: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800254: lwc1        $f12, 0x58($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80800258: bgez        $t7, L_80800270
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8080025C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800270;
    }
    // 0x8080025C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800260: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800264: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800268: nop

    // 0x8080026C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80800270:
    // 0x80800270: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800274: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800278: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8080027C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800280: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800284: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800288: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8080028C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800290: jal         0x800F10B4
    // 0x80800294: nop

    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800294: nop

    after_1:
    // 0x80800298: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x8080029C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x808002A0: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x808002A4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808002A8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808002AC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808002B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808002B4: lui         $s4, 0x8010
    ctx->r20 = S32(0X8010 << 16);
    // 0x808002B8: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(2328, 0X5E0) << 16);
    // 0x808002BC: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(2328, 0X5D4) << 16);
    // 0x808002C0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808002C4: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x808002C8: addiu       $s5, $s5, 0x5D4
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(2328, 0X5D4));
    // 0x808002CC: addiu       $s6, $s6, 0x5E0
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(2328, 0X5E0));
    // 0x808002D0: addiu       $s4, $s4, 0x17D0
    ctx->r20 = ADD32(ctx->r20, 0X17D0);
    // 0x808002D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808002D8: addiu       $s7, $zero, 0x7
    ctx->r23 = ADD32(0, 0X7);
    // 0x808002DC: addiu       $s3, $sp, 0x80
    ctx->r19 = ADD32(ctx->r29, 0X80);
    // 0x808002E0: addiu       $s2, $sp, 0x8C
    ctx->r18 = ADD32(ctx->r29, 0X8C);
    // 0x808002E4: lw          $at, 0x0($s5)
    ctx->r1 = MEM_W(ctx->r21, 0X0);
L_808002E8:
    // 0x808002E8: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x808002EC: lw          $t0, 0x4($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X4);
    // 0x808002F0: sw          $at, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r1;
    // 0x808002F4: lw          $at, 0x8($s5)
    ctx->r1 = MEM_W(ctx->r21, 0X8);
    // 0x808002F8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002FC: lw          $t3, 0x4($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X4);
    // 0x80800300: sw          $at, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r1;
    // 0x80800304: lw          $at, 0x0($s6)
    ctx->r1 = MEM_W(ctx->r22, 0X0);
    // 0x80800308: sw          $t0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r8;
    // 0x8080030C: sw          $t3, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r11;
    // 0x80800310: sw          $at, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r1;
    // 0x80800314: lw          $at, 0x8($s6)
    ctx->r1 = MEM_W(ctx->r22, 0X8);
    // 0x80800318: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    // 0x8080031C: lui         $a2, 0x442F
    ctx->r6 = S32(0X442F << 16);
    // 0x80800320: sw          $at, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r1;
    // 0x80800324: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800328: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080032C: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80800330: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80800334: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80800338: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8080033C: add.s       $f16, $f10, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x80800340: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80800344: jal         0x800F10B4
    // 0x80800348: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800348: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x8080034C: mul.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80800350: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800354: mul.s       $f12, $f8, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80800358: jal         0x800138D0
    // 0x8080035C: nop

    func_800138D0(rdram, ctx);
        goto after_3;
    // 0x8080035C: nop

    after_3:
    // 0x80800360: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800364: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800368: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8080036C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800370: nop

    // 0x80800374: mul.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x80800378: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8080037C: mul.s       $f12, $f4, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80800380: jal         0x800138D0
    // 0x80800384: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    func_800138D0(rdram, ctx);
        goto after_4;
    // 0x80800384: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x80800388: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x8080038C: sw          $s0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r16;
    // 0x80800390: jal         0x800DF830
    // 0x80800394: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_5;
    // 0x80800394: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80800398: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080039C: jal         0x800DF47C
    // 0x808003A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800DF47C(rdram, ctx);
        goto after_6;
    // 0x808003A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x808003A4: jal         0x8010347C
    // 0x808003A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_8010347C(rdram, ctx);
        goto after_7;
    // 0x808003A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_7:
    // 0x808003AC: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x808003B0: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x808003B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808003B8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x808003BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808003C0: jal         0x800DE498
    // 0x808003C4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800DE498(rdram, ctx);
        goto after_8;
    // 0x808003C4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_8:
    // 0x808003C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808003CC: bnel        $s0, $s7, L_808002E8
    if (ctx->r16 != ctx->r23) {
        // 0x808003D0: lw          $at, 0x0($s5)
        ctx->r1 = MEM_W(ctx->r21, 0X0);
            goto L_808002E8;
    }
    goto skip_0;
    // 0x808003D0: lw          $at, 0x0($s5)
    ctx->r1 = MEM_W(ctx->r21, 0X0);
    skip_0:
    // 0x808003D4: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x808003D8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808003DC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808003E0: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x808003E4: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x808003E8: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x808003EC: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x808003F0: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x808003F4: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x808003F8: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x808003FC: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80800400: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80800404: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80800408: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8080040C: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x80800410: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x80800414: jr          $ra
    // 0x80800418: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80800418: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void bsbabykaz_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808004C8: jal         0x8009E69C
    // 0x808004CC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_8009E69C(rdram, ctx);
        goto after_0;
    // 0x808004CC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x808004D0: bnel        $v0, $zero, L_8080054C
    if (ctx->r2 != 0) {
        // 0x808004D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080054C;
    }
    goto skip_0;
    // 0x808004D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808004D8: jal         0x8009EF60
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_1;
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808004E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808004F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808004F4: jal         0x800A4D6C
    // 0x808004F8: nop

    func_800A4D6C(rdram, ctx);
        goto after_2;
    // 0x808004F8: nop

    after_2:
    // 0x808004FC: jal         0x80095A40
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095A40(rdram, ctx);
        goto after_3;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800508: jal         0x8009590C
    // 0x8080050C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009590C(rdram, ctx);
        goto after_4;
    // 0x8080050C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800510: jal         0x800A1040
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1040(rdram, ctx);
        goto after_5;
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800518: jal         0x8009E474
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_6;
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800528: jal         0x800947EC
    // 0x8080052C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_7;
    // 0x8080052C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: jal         0x80092864
    // 0x80800538: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80092864(rdram, ctx);
        goto after_8;
    // 0x80800538: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_8:
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800540: jal         0x80095A74
    // 0x80800544: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80095A74(rdram, ctx);
        goto after_9;
    // 0x80800544: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80800548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080054C:
    // 0x8080054C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800550: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800554: jr          $ra
    // 0x80800558: nop

    return;
    // 0x80800558: nop

;}
RECOMP_FUNC void func_8080050C_sccustom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080050C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800510: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800518: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3342, 0X940) << 16);
    // 0x8080051C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800520: jal         0x800E73D4
    // 0x80800524: addiu       $a0, $a0, 0x940
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3342, 0X940));
    func_800E73D4(rdram, ctx);
        goto after_0;
    // 0x80800524: addiu       $a0, $a0, 0x940
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3342, 0X940));
    after_0:
    // 0x80800528: jal         0x8008A618
    // 0x8080052C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _scinfobar_entrypoint_19(rdram, ctx);
        goto after_1;
    // 0x8080052C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800530: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3342, 0X940) << 16);
    // 0x80800534: addiu       $a0, $a0, 0x940
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3342, 0X940));
    // 0x80800538: jal         0x800E6DB4
    // 0x8080053C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_2;
    // 0x8080053C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800540: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3342, 0X940) << 16);
    // 0x80800544: addiu       $a0, $a0, 0x940
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3342, 0X940));
    // 0x80800548: jal         0x800E6A58
    // 0x8080054C: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    func_800E6A58(rdram, ctx);
        goto after_3;
    // 0x8080054C: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    after_3:
    // 0x80800550: jal         0x8008A620
    // 0x80800554: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _scinfobar_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800554: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_4:
    // 0x80800558: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3342, 0X940) << 16);
    // 0x8080055C: addiu       $a0, $a0, 0x940
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3342, 0X940));
    // 0x80800560: jal         0x800E6DB4
    // 0x80800564: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800E6DB4(rdram, ctx);
        goto after_5;
    // 0x80800564: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80800568: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080056C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3342, 0X940) << 16);
    // 0x80800570: addiu       $v0, $v0, 0x940
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3342, 0X940));
    // 0x80800574: jr          $ra
    // 0x80800578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _bskazfly_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833A0: syscall     57
    recomp_syscall_handler(rdram, ctx, 0x800833A0);
    return;
    // 0x800833A4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void baduo_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000D8: lw          $t6, 0x58($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X58);
    // 0x808000DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000E4: jal         0x808002C8
    // 0x808000E8: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    baduo_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808000E8: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    after_0:
    // 0x808000EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000F0: lw          $t7, 0x58($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X58);
    // 0x808000F4: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x808000F8: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    // 0x808000FC: jal         0x800EFD24
    // 0x80800100: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80800100: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    after_1:
    // 0x80800104: lw          $t8, 0x58($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X58);
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x800A3274
    // 0x80800110: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    func_800A3274(rdram, ctx);
        goto after_2;
    // 0x80800110: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    after_2:
    // 0x80800114: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800118: beq         $v0, $at, L_80800128
    if (ctx->r2 == ctx->r1) {
        // 0x8080011C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80800128;
    }
    // 0x8080011C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800120: bne         $v0, $at, L_80800160
    if (ctx->r2 != ctx->r1) {
        // 0x80800124: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800160;
    }
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800128:
    // 0x80800128: jal         0x800F8B88
    // 0x8080012C: nop

    func_800F8B88(rdram, ctx);
        goto after_3;
    // 0x8080012C: nop

    after_3:
    // 0x80800130: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800134: bne         $v0, $at, L_80800150
    if (ctx->r2 != ctx->r1) {
        // 0x80800138: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800150;
    }
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: jal         0x8080017C
    // 0x80800144: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baduo_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800144: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800148: b           L_8080016C
    // 0x8080014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080016C;
    // 0x8080014C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800150:
    // 0x80800150: jal         0x8080017C
    // 0x80800154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    baduo_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80800154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800158: b           L_8080016C
    // 0x8080015C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080016C;
    // 0x8080015C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800160:
    // 0x80800160: jal         0x8080017C
    // 0x80800164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    baduo_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080016C:
    // 0x8080016C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800170: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800174: jr          $ra
    // 0x80800178: nop

    return;
    // 0x80800178: nop

;}
RECOMP_FUNC void func_80800410_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800410: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800414: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800418: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080041C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800420: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800424: jal         0x80100094
    // 0x80800428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080042C: lui         $at, 0xC150
    ctx->r1 = S32(0XC150 << 16);
    // 0x80800430: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800434: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80800438: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080043C: jal         0x800DC178
    // 0x80800440: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800440: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_1:
    // 0x80800444: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800448: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080044C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800450: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800454: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800458: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080045C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800460: addu        $s0, $s1, $t7
    ctx->r16 = ADD32(ctx->r17, ctx->r15);
    // 0x80800464: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800468: jal         0x800DC178
    // 0x8080046C: swc1        $f0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x8080046C: swc1        $f0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x80800470: lui         $at, 0xC150
    ctx->r1 = S32(0XC150 << 16);
    // 0x80800474: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800478: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x8080047C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800480: jal         0x800DC178
    // 0x80800484: swc1        $f0, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800484: swc1        $f0, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x80800488: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8080048C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800490: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80800494: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800498: jal         0x800DC178
    // 0x8080049C: swc1        $f0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x8080049C: swc1        $f0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f0.u32l;
    after_4:
    // 0x808004A0: swc1        $f0, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->f0.u32l;
    // 0x808004A4: addiu       $a0, $s0, 0x64
    ctx->r4 = ADD32(ctx->r16, 0X64);
    // 0x808004A8: jal         0x800EE7F8
    // 0x808004AC: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808004AC: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    after_5:
    // 0x808004B0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x808004B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004B8: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x808004BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22B0) << 16);
    // 0x808004C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808004C4: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x808004C8: lwc1        $f12, 0x22B0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22B0));
    // 0x808004CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X22B4) << 16);
    // 0x808004D0: jal         0x800DC178
    // 0x808004D4: lwc1        $f14, 0x22B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22B4));
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808004D4: lwc1        $f14, 0x22B4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X22B4));
    after_6:
    // 0x808004D8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808004DC: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    // 0x808004E0: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x808004E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808004E8: addu        $s0, $s1, $t9
    ctx->r16 = ADD32(ctx->r17, ctx->r25);
    // 0x808004EC: jal         0x800DC128
    // 0x808004F0: swc1        $f0, 0x244($s0)
    MEM_W(0X244, ctx->r16) = ctx->f0.u32l;
    func_800DC128(rdram, ctx);
        goto after_7;
    // 0x808004F0: swc1        $f0, 0x244($s0)
    MEM_W(0X244, ctx->r16) = ctx->f0.u32l;
    after_7:
    // 0x808004F4: sw          $v0, 0x27C($s0)
    MEM_W(0X27C, ctx->r16) = ctx->r2;
    // 0x808004F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004FC: jal         0x800DC128
    // 0x80800500: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_800DC128(rdram, ctx);
        goto after_8;
    // 0x80800500: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_8:
    // 0x80800504: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80800508: addu        $t1, $s1, $t0
    ctx->r9 = ADD32(ctx->r17, ctx->r8);
    // 0x8080050C: sb          $v0, 0x26C($t1)
    MEM_B(0X26C, ctx->r9) = ctx->r2;
    // 0x80800510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800514: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800518: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080051C: jr          $ra
    // 0x80800520: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800520: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bsmumcast_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x808002B0: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x808002B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002B8: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x808002BC: beq         $at, $zero, L_808003F0
    if (ctx->r1 == 0) {
        // 0x808002C0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808003F0;
    }
    // 0x808002C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808002C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(316, 0X488) << 16);
    // 0x808002C8: addu        $at, $at, $t6
    gpr jr_addend_808002D0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808002CC: lw          $t6, 0x488($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(316, 0X488));
    // 0x808002D0: jr          $t6
    // 0x808002D4: nop

    switch (jr_addend_808002D0 >> 2) {
        case 0: goto L_808003F0; break;
        case 1: goto L_808002D8; break;
        case 2: goto L_80800340; break;
        case 3: goto L_80800360; break;
        case 4: goto L_808003E4; break;
        default: switch_error(__func__, 0x808002D0, 0x80800488);
    }
    // 0x808002D4: nop

L_808002D8:
    // 0x808002D8: jal         0x8008CAEC
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_0;
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808002E0: beq         $v0, $zero, L_808002F0
    if (ctx->r2 == 0) {
        // 0x808002E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F0;
    }
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: jal         0x80800000
    // 0x808002EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800000_bsmumcast(rdram, ctx);
        goto after_1;
    // 0x808002EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
L_808002F0:
    // 0x808002F0: lui         $a1, 0x3EB8
    ctx->r5 = S32(0X3EB8 << 16);
    // 0x808002F4: ori         $a1, $a1, 0xBAC7
    ctx->r5 = ctx->r5 | 0XBAC7;
    // 0x808002F8: jal         0x8008CB10
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800300: beq         $v0, $zero, L_8080031C
    if (ctx->r2 == 0) {
        // 0x80800304: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080031C;
    }
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: jal         0x800A0DAC
    // 0x8080030C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0DAC(rdram, ctx);
        goto after_3;
    // 0x8080030C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: jal         0x800A0DA0
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0DA0(rdram, ctx);
        goto after_4;
    // 0x80800318: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_8080031C:
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: jal         0x8008CB10
    // 0x80800324: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_5;
    // 0x80800324: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_5:
    // 0x80800328: beql        $v0, $zero, L_808003F4
    if (ctx->r2 == 0) {
        // 0x8080032C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F4;
    }
    goto skip_0;
    // 0x8080032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800330: jal         0x80086C90
    // 0x80800334: nop

    _chjujubagfx_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800334: nop

    after_6:
    // 0x80800338: b           L_808003F4
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003F4;
    // 0x8080033C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800340:
    // 0x80800340: jal         0x800DA298
    // 0x80800344: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800344: addiu       $a0, $zero, 0x9DF
    ctx->r4 = ADD32(0, 0X9DF);
    after_7:
    // 0x80800348: beq         $v0, $zero, L_808003F0
    if (ctx->r2 == 0) {
        // 0x8080034C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F0;
    }
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800350: jal         0x80800000
    // 0x80800354: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800000_bsmumcast(rdram, ctx);
        goto after_8;
    // 0x80800354: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80800358: b           L_808003F4
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003F4;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800360:
    // 0x80800360: lui         $a1, 0x3EB8
    ctx->r5 = S32(0X3EB8 << 16);
    // 0x80800364: ori         $a1, $a1, 0xBAC7
    ctx->r5 = ctx->r5 | 0XBAC7;
    // 0x80800368: jal         0x8008CB10
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_9;
    // 0x8080036C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800370: beq         $v0, $zero, L_8080038C
    if (ctx->r2 == 0) {
        // 0x80800374: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080038C;
    }
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800378: jal         0x800A0DAC
    // 0x8080037C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0DAC(rdram, ctx);
        goto after_10;
    // 0x8080037C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: jal         0x800A0DA0
    // 0x80800388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0DA0(rdram, ctx);
        goto after_11;
    // 0x80800388: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
L_8080038C:
    // 0x8080038C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800390: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800394: jal         0x8008CB10
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_12;
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080039C: beq         $v0, $zero, L_808003AC
    if (ctx->r2 == 0) {
        // 0x808003A0: nop
    
            goto L_808003AC;
    }
    // 0x808003A0: nop

    // 0x808003A4: jal         0x800DA544
    // 0x808003A8: addiu       $a0, $zero, 0x9F3
    ctx->r4 = ADD32(0, 0X9F3);
    func_800DA544(rdram, ctx);
        goto after_13;
    // 0x808003A8: addiu       $a0, $zero, 0x9F3
    ctx->r4 = ADD32(0, 0X9F3);
    after_13:
L_808003AC:
    // 0x808003AC: jal         0x8008CAEC
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_14;
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808003B4: beql        $v0, $zero, L_808003F4
    if (ctx->r2 == 0) {
        // 0x808003B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F4;
    }
    goto skip_1;
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808003BC: jal         0x8008E124
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E124(rdram, ctx);
        goto after_15;
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808003C4: beq         $v0, $zero, L_808003DC
    if (ctx->r2 == 0) {
        // 0x808003C8: addiu       $t7, $zero, 0xE5
        ctx->r15 = ADD32(0, 0XE5);
            goto L_808003DC;
    }
    // 0x808003C8: addiu       $t7, $zero, 0xE5
    ctx->r15 = ADD32(0, 0XE5);
    // 0x808003CC: jal         0x80084740
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badata_entrypoint_32(rdram, ctx);
        goto after_16;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808003D4: b           L_808003F0
    // 0x808003D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_808003F0;
    // 0x808003D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_808003DC:
    // 0x808003DC: b           L_808003F0
    // 0x808003E0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_808003F0;
    // 0x808003E0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_808003E4:
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: jal         0x80800000
    // 0x808003EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800000_bsmumcast(rdram, ctx);
        goto after_17;
    // 0x808003EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_17:
L_808003F0:
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003F4:
    // 0x808003F4: jal         0x8009E5C8
    // 0x808003F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_18;
    // 0x808003F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_18:
    // 0x808003FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800400: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800404: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800408: jr          $ra
    // 0x8080040C: nop

    return;
    // 0x8080040C: nop

;}
RECOMP_FUNC void func_80800C78_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800C84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800C88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800C8C: jal         0x80100094
    // 0x80800C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C94: jal         0x800D8FF8
    // 0x80800C98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800C98: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800C9C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CA0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800CA4: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80800CA8: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800CAC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800CB0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80800CB4: swc1        $f10, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f10.u32l;
    // 0x80800CB8: lwc1        $f2, 0x18($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800CBC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800CC0: nop

    // 0x80800CC4: bc1fl       L_80800CEC
    if (!c1cs) {
        // 0x80800CC8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80800CEC;
    }
    goto skip_0;
    // 0x80800CC8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x80800CCC: swc1        $f12, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f12.u32l;
    // 0x80800CD0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80800CD4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800CD8: jal         0x808003B0
    // 0x80800CDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808003B0_chfishshootgame(rdram, ctx);
        goto after_2;
    // 0x80800CDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800CE0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CE4: lwc1        $f2, 0x18($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800CE8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80800CEC:
    // 0x80800CEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800CF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800CF4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80800CF8: nop

    // 0x80800CFC: bc1fl       L_80800D14
    if (!c1cs) {
        // 0x80800D00: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80800D14;
    }
    goto skip_1;
    // 0x80800D00: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_1:
    // 0x80800D04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800D08: b           L_80800D14
    // 0x80800D0C: sub.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f2.fl;
        goto L_80800D14;
    // 0x80800D0C: sub.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80800D10: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80800D14:
    // 0x80800D14: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800D18: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80800D1C: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80800D20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D24: sub.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80800D28: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800D2C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80800D30: jal         0x80800C24
    // 0x80800D34: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    func_80800C24_chfishshootgame(rdram, ctx);
        goto after_3;
    // 0x80800D34: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    after_3:
    // 0x80800D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D40: jr          $ra
    // 0x80800D44: nop

    return;
    // 0x80800D44: nop

;}
RECOMP_FUNC void _chcollballcontrol_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086EB8: syscall     467
    recomp_syscall_handler(rdram, ctx, 0x80086EB8);
    return;
    // 0x80086EBC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080460C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080460C: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x80804610: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80804614: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x80804618: beql        $t6, $zero, L_80804648
    if (ctx->r14 == 0) {
        // 0x8080461C: lw          $t7, 0x6C($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X6C);
            goto L_80804648;
    }
    goto skip_0;
    // 0x8080461C: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
    skip_0:
    // 0x80804620: beq         $t6, $at, L_80804674
    if (ctx->r14 == ctx->r1) {
        // 0x80804624: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80804674;
    }
    // 0x80804624: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80804628: beq         $t6, $at, L_808046A4
    if (ctx->r14 == ctx->r1) {
        // 0x8080462C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808046A4;
    }
    // 0x8080462C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80804630: beql        $t6, $at, L_808046D8
    if (ctx->r14 == ctx->r1) {
        // 0x80804634: lui         $at, 0x4416
        ctx->r1 = S32(0X4416 << 16);
            goto L_808046D8;
    }
    goto skip_1;
    // 0x80804634: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    skip_1:
    // 0x80804638: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080463C: b           L_808046E4
    // 0x80804640: nop

        goto L_808046E4;
    // 0x80804640: nop

    // 0x80804644: lw          $t7, 0x6C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X6C);
L_80804648:
    // 0x80804648: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8080464C: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80804650: bnel        $t8, $zero, L_8080466C
    if (ctx->r24 != 0) {
        // 0x80804654: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8080466C;
    }
    goto skip_2;
    // 0x80804654: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x80804658: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080465C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80804660: jr          $ra
    // 0x80804664: nop

    return;
    // 0x80804664: nop

    // 0x80804668: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8080466C:
    // 0x8080466C: jr          $ra
    // 0x80804670: nop

    return;
    // 0x80804670: nop

L_80804674:
    // 0x80804674: lw          $t9, 0x6C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X6C);
    // 0x80804678: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8080467C: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x80804680: bnel        $t0, $zero, L_8080469C
    if (ctx->r8 != 0) {
        // 0x80804684: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8080469C;
    }
    goto skip_3;
    // 0x80804684: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_3:
    // 0x80804688: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080468C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80804690: jr          $ra
    // 0x80804694: nop

    return;
    // 0x80804694: nop

    // 0x80804698: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8080469C:
    // 0x8080469C: jr          $ra
    // 0x808046A0: nop

    return;
    // 0x808046A0: nop

L_808046A4:
    // 0x808046A4: lw          $t1, 0x6C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X6C);
    // 0x808046A8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808046AC: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x808046B0: bnel        $t2, $zero, L_808046CC
    if (ctx->r10 != 0) {
        // 0x808046B4: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_808046CC;
    }
    goto skip_4;
    // 0x808046B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_4:
    // 0x808046B8: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x808046BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808046C0: jr          $ra
    // 0x808046C4: nop

    return;
    // 0x808046C4: nop

    // 0x808046C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_808046CC:
    // 0x808046CC: jr          $ra
    // 0x808046D0: nop

    return;
    // 0x808046D0: nop

    // 0x808046D4: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
L_808046D8:
    // 0x808046D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808046DC: jr          $ra
    // 0x808046E0: nop

    return;
    // 0x808046E0: nop

L_808046E4:
    // 0x808046E4: jr          $ra
    // 0x808046E8: nop

    return;
    // 0x808046E8: nop

;}
RECOMP_FUNC void baphysics_set_target_yaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B9C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B9C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B9C8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009B9CC: jal         0x800136E4
    // 0x8009B9D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x8009B9D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009B9D4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8009B9D8: lw          $t7, 0xC8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC8);
    // 0x8009B9DC: swc1        $f0, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f0.u32l;
    // 0x8009B9E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B9E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B9E8: jr          $ra
    // 0x8009B9EC: nop

    return;
    // 0x8009B9EC: nop

;}
RECOMP_FUNC void func_800D4564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D4568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D456C: jal         0x800AAD28
    // 0x800D4570: nop

    func_800AAD28(rdram, ctx);
        goto after_0;
    // 0x800D4570: nop

    after_0:
    // 0x800D4574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D4578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D457C: jr          $ra
    // 0x800D4580: nop

    return;
    // 0x800D4580: nop

;}
RECOMP_FUNC void func_800BF8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF8BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BF8C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BF8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BF8C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BF8CC: jal         0x80088128
    // 0x800BF8D0: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    _gcmapDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x800BF8D0: addiu       $a0, $a0, -0x7A50
    ctx->r4 = ADD32(ctx->r4, -0X7A50);
    after_0:
    // 0x800BF8D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BF8D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BF8DC: jr          $ra
    // 0x800BF8E0: nop

    return;
    // 0x800BF8E0: nop

;}
RECOMP_FUNC void func_80800000_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x80800004: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x80800008: sw          $zero, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
    return;
    // 0x80800010: sw          $zero, 0x28($a0)
    MEM_W(0X28, ctx->r4) = 0;
;}
