#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void vpscroll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000F8: jal         0x800D8FF8
    // 0x808000FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800100: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800104: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80800108: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080010C: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80800110: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80800114: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800118: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080011C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800120: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800124: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80800128: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
    // 0x8080012C: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80800130: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x80800134: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80800138: nop

    // 0x8080013C: slti        $at, $v1, 0x2001
    ctx->r1 = SIGNED(ctx->r3) < 0X2001 ? 1 : 0;
    // 0x80800140: bne         $at, $zero, L_80800168
    if (ctx->r1 != 0) {
        // 0x80800144: lui         $at, 0x4600
        ctx->r1 = S32(0X4600 << 16);
            goto L_80800168;
    }
    // 0x80800144: lui         $at, 0x4600
    ctx->r1 = S32(0X4600 << 16);
    // 0x80800148: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080014C: nop

    // 0x80800150: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80800154: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80800158: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8080015C: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800160: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80800164: nop

L_80800168:
    // 0x80800168: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x8080016C: sh          $v1, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r3;
    // 0x80800170: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x80800174: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800178: blez        $t9, L_808001B4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8080017C: addu        $a3, $a0, $t8
        ctx->r7 = ADD32(ctx->r4, ctx->r24);
            goto L_808001B4;
    }
    // 0x8080017C: addu        $a3, $a0, $t8
    ctx->r7 = ADD32(ctx->r4, ctx->r24);
    // 0x80800180: addiu       $v1, $a2, 0x10
    ctx->r3 = ADD32(ctx->r6, 0X10);
    // 0x80800184: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80800188: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
L_8080018C:
    // 0x8080018C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800190: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800194: multu       $t0, $a0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800198: mflo        $t1
    ctx->r9 = lo;
    // 0x8080019C: addu        $t2, $a3, $t1
    ctx->r10 = ADD32(ctx->r7, ctx->r9);
    // 0x808001A0: sb          $a1, 0x3($t2)
    MEM_B(0X3, ctx->r10) = ctx->r5;
    // 0x808001A4: lw          $t3, 0xC($a2)
    ctx->r11 = MEM_W(ctx->r6, 0XC);
    // 0x808001A8: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x808001AC: bnel        $at, $zero, L_8080018C
    if (ctx->r1 != 0) {
        // 0x808001B0: lh          $t0, 0x0($v1)
        ctx->r8 = MEM_H(ctx->r3, 0X0);
            goto L_8080018C;
    }
    goto skip_0;
    // 0x808001B0: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    skip_0:
L_808001B4:
    // 0x808001B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001BC: jr          $ra
    // 0x808001C0: nop

    return;
    // 0x808001C0: nop

;}
RECOMP_FUNC void _basub_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851E0: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851E0);
    return;
    // 0x800851E4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_808008B0_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808008B8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808008BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808008C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008CC: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x808008D0: jal         0x80100094
    // 0x808008D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008D8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x808008DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808008E0: slti        $at, $a2, 0x96
    ctx->r1 = SIGNED(ctx->r6) < 0X96 ? 1 : 0;
    // 0x808008E4: bne         $at, $zero, L_80800908
    if (ctx->r1 != 0) {
        // 0x808008E8: addiu       $t6, $a2, -0xB
        ctx->r14 = ADD32(ctx->r6, -0XB);
            goto L_80800908;
    }
    // 0x808008E8: addiu       $t6, $a2, -0xB
    ctx->r14 = ADD32(ctx->r6, -0XB);
    // 0x808008EC: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x808008F0: beq         $a2, $at, L_80800B18
    if (ctx->r6 == ctx->r1) {
        // 0x808008F4: addiu       $at, $zero, 0x9F
        ctx->r1 = ADD32(0, 0X9F);
            goto L_80800B18;
    }
    // 0x808008F4: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x808008F8: beq         $a2, $at, L_80800B44
    if (ctx->r6 == ctx->r1) {
        // 0x808008FC: nop
    
            goto L_80800B44;
    }
    // 0x808008FC: nop

    // 0x80800900: b           L_80800B80
    // 0x80800904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B80;
    // 0x80800904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800908:
    // 0x80800908: slti        $at, $a2, 0x91
    ctx->r1 = SIGNED(ctx->r6) < 0X91 ? 1 : 0;
    // 0x8080090C: bne         $at, $zero, L_80800924
    if (ctx->r1 != 0) {
        // 0x80800910: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800924;
    }
    // 0x80800910: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800914: beql        $a2, $at, L_80800AFC
    if (ctx->r6 == ctx->r1) {
        // 0x80800918: lbu         $t0, 0x56($v0)
        ctx->r8 = MEM_BU(ctx->r2, 0X56);
            goto L_80800AFC;
    }
    goto skip_0;
    // 0x80800918: lbu         $t0, 0x56($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X56);
    skip_0:
    // 0x8080091C: b           L_80800B80
    // 0x80800920: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B80;
    // 0x80800920: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800924:
    // 0x80800924: slti        $at, $a2, 0x58
    ctx->r1 = SIGNED(ctx->r6) < 0X58 ? 1 : 0;
    // 0x80800928: bne         $at, $zero, L_80800940
    if (ctx->r1 != 0) {
        // 0x8080092C: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_80800940;
    }
    // 0x8080092C: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x80800930: beq         $a2, $at, L_808009B8
    if (ctx->r6 == ctx->r1) {
        // 0x80800934: nop
    
            goto L_808009B8;
    }
    // 0x80800934: nop

    // 0x80800938: b           L_80800B80
    // 0x8080093C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B80;
    // 0x8080093C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800940:
    // 0x80800940: sltiu       $at, $t6, 0x4D
    ctx->r1 = ctx->r14 < 0X4D ? 1 : 0;
    // 0x80800944: beq         $at, $zero, L_80800B74
    if (ctx->r1 == 0) {
        // 0x80800948: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800B74;
    }
    // 0x80800948: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080094C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X28C4) << 16);
    // 0x80800950: addu        $at, $at, $t6
    gpr jr_addend_80800958 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800954: lw          $t6, 0x28C4($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(932, 0X28C4));
    // 0x80800958: jr          $t6
    // 0x8080095C: nop

    switch (jr_addend_80800958 >> 2) {
        case 0: goto L_80800A08; break;
        case 1: goto L_80800B74; break;
        case 2: goto L_80800B74; break;
        case 3: goto L_80800B74; break;
        case 4: goto L_80800B74; break;
        case 5: goto L_80800B74; break;
        case 6: goto L_80800B74; break;
        case 7: goto L_80800B74; break;
        case 8: goto L_80800B74; break;
        case 9: goto L_80800B74; break;
        case 10: goto L_80800B74; break;
        case 11: goto L_80800B74; break;
        case 12: goto L_80800B74; break;
        case 13: goto L_80800B74; break;
        case 14: goto L_80800B74; break;
        case 15: goto L_80800B74; break;
        case 16: goto L_80800B74; break;
        case 17: goto L_80800B74; break;
        case 18: goto L_80800B74; break;
        case 19: goto L_80800B74; break;
        case 20: goto L_808009F0; break;
        case 21: goto L_80800B74; break;
        case 22: goto L_80800B74; break;
        case 23: goto L_80800B74; break;
        case 24: goto L_80800B74; break;
        case 25: goto L_80800B74; break;
        case 26: goto L_80800B74; break;
        case 27: goto L_80800B74; break;
        case 28: goto L_80800B74; break;
        case 29: goto L_80800B74; break;
        case 30: goto L_80800B74; break;
        case 31: goto L_80800B74; break;
        case 32: goto L_80800B74; break;
        case 33: goto L_80800B74; break;
        case 34: goto L_80800B74; break;
        case 35: goto L_80800988; break;
        case 36: goto L_80800B74; break;
        case 37: goto L_80800B74; break;
        case 38: goto L_80800B74; break;
        case 39: goto L_808009C8; break;
        case 40: goto L_80800B74; break;
        case 41: goto L_80800B74; break;
        case 42: goto L_80800B74; break;
        case 43: goto L_80800B74; break;
        case 44: goto L_80800B74; break;
        case 45: goto L_80800B74; break;
        case 46: goto L_80800B74; break;
        case 47: goto L_80800B74; break;
        case 48: goto L_80800B74; break;
        case 49: goto L_80800B74; break;
        case 50: goto L_808009A4; break;
        case 51: goto L_80800B74; break;
        case 52: goto L_80800960; break;
        case 53: goto L_80800974; break;
        case 54: goto L_80800B74; break;
        case 55: goto L_80800B74; break;
        case 56: goto L_80800B74; break;
        case 57: goto L_80800B74; break;
        case 58: goto L_80800B74; break;
        case 59: goto L_80800B74; break;
        case 60: goto L_80800B74; break;
        case 61: goto L_80800B74; break;
        case 62: goto L_80800B74; break;
        case 63: goto L_80800B74; break;
        case 64: goto L_80800B74; break;
        case 65: goto L_80800B74; break;
        case 66: goto L_80800B74; break;
        case 67: goto L_80800B74; break;
        case 68: goto L_80800B74; break;
        case 69: goto L_80800B74; break;
        case 70: goto L_80800B74; break;
        case 71: goto L_80800AB8; break;
        case 72: goto L_80800B74; break;
        case 73: goto L_80800B74; break;
        case 74: goto L_80800B74; break;
        case 75: goto L_80800B74; break;
        case 76: goto L_80800AD0; break;
        default: switch_error(__func__, 0x80800958, 0x808028C4);
    }
    // 0x8080095C: nop

L_80800960:
    // 0x80800960: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800964: jal         0x80800D50
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800D50_chboilerboss(rdram, ctx);
        goto after_1;
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080096C: b           L_80800B80
    // 0x80800970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B80;
    // 0x80800970: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800974:
    // 0x80800974: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800978: jal         0x80800E90
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E90_chboilerboss(rdram, ctx);
        goto after_2;
    // 0x8080097C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800980: b           L_80800B80
    // 0x80800984: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B80;
    // 0x80800984: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800988:
    // 0x80800988: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x8080098C: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800990: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    // 0x80800994: jal         0x80801D80
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801D80_chboilerboss(rdram, ctx);
        goto after_3;
    // 0x80800998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080099C: b           L_80800B80
    // 0x808009A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B80;
    // 0x808009A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009A4:
    // 0x808009A4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808009A8: jal         0x80801584
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801584_chboilerboss(rdram, ctx);
        goto after_4;
    // 0x808009AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808009B0: b           L_80800B80
    // 0x808009B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B80;
    // 0x808009B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009B8:
    // 0x808009B8: jal         0x808022BC
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808022BC_chboilerboss(rdram, ctx);
        goto after_5;
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808009C0: b           L_80800B80
    // 0x808009C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B80;
    // 0x808009C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009C8:
    // 0x808009C8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808009CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808009D0: jal         0x800F54E4
    // 0x808009D4: sh          $t7, 0x64($t8)
    MEM_H(0X64, ctx->r24) = ctx->r15;
    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808009D4: sh          $t7, 0x64($t8)
    MEM_H(0X64, ctx->r24) = ctx->r15;
    after_6:
    // 0x808009D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808009E0: jal         0x800F8300
    // 0x808009E4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800F8300(rdram, ctx);
        goto after_7;
    // 0x808009E4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x808009E8: b           L_80800B80
    // 0x808009EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B80;
    // 0x808009EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009F0:
    // 0x808009F0: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x808009F4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x808009F8: jal         0x80800B94
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B94_chboilerboss(rdram, ctx);
        goto after_8;
    // 0x808009FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800A00: b           L_80800B80
    // 0x80800A04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B80;
    // 0x80800A04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A08:
    // 0x80800A08: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800A0C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800A10: beq         $a3, $at, L_80800A30
    if (ctx->r7 == ctx->r1) {
        // 0x80800A14: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80800A30;
    }
    // 0x80800A14: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80800A18: beq         $a3, $at, L_80800A98
    if (ctx->r7 == ctx->r1) {
        // 0x80800A1C: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80800A98;
    }
    // 0x80800A1C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80800A20: beq         $a3, $at, L_80800A80
    if (ctx->r7 == ctx->r1) {
        // 0x80800A24: nop
    
            goto L_80800A80;
    }
    // 0x80800A24: nop

    // 0x80800A28: b           L_80800B80
    // 0x80800A2C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800B80;
    // 0x80800A2C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800A30:
    // 0x80800A30: jal         0x800D395C
    // 0x80800A34: nop

    func_800D395C(rdram, ctx);
        goto after_9;
    // 0x80800A34: nop

    after_9:
    // 0x80800A38: beq         $v0, $zero, L_80800A58
    if (ctx->r2 == 0) {
        // 0x80800A3C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A58;
    }
    // 0x80800A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A40: jal         0x808026F0
    // 0x80800A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026F0_chboilerboss(rdram, ctx);
        goto after_10;
    // 0x80800A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800A48: jal         0x80088180
    // 0x80800A4C: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_11;
    // 0x80800A4C: nop

    after_11:
    // 0x80800A50: b           L_80800B80
    // 0x80800A54: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800B80;
    // 0x80800A54: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800A58:
    // 0x80800A58: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80800A5C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80800A60: jal         0x808027E4
    // 0x80800A64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808027E4_chboilerboss(rdram, ctx);
        goto after_12;
    // 0x80800A64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x80800A68: addiu       $a0, $zero, 0x46D
    ctx->r4 = ADD32(0, 0X46D);
    // 0x80800A6C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800A70: jal         0x80101180
    // 0x80800A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_13;
    // 0x80800A74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80800A78: b           L_80800B80
    // 0x80800A7C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800B80;
    // 0x80800A7C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800A80:
    // 0x80800A80: jal         0x808026F0
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026F0_chboilerboss(rdram, ctx);
        goto after_14;
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800A88: jal         0x800FFAB0
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_15;
    // 0x80800A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800A90: b           L_80800B80
    // 0x80800A94: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800B80;
    // 0x80800A94: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800A98:
    // 0x80800A98: jal         0x808026F0
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026F0_chboilerboss(rdram, ctx);
        goto after_16;
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80800AA0: jal         0x808024DC
    // 0x80800AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808024DC_chboilerboss(rdram, ctx);
        goto after_17;
    // 0x80800AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800AA8: b           L_80800B80
    // 0x80800AAC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800B80;
    // 0x80800AAC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80800AB0: b           L_80800B80
    // 0x80800AB4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800B80;
    // 0x80800AB4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800AB8:
    // 0x80800AB8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(932, 0X2AA0) << 16);
    // 0x80800ABC: addiu       $a0, $a0, 0x2AA0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(932, 0X2AA0));
    // 0x80800AC0: jal         0x80088090
    // 0x80800AC4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_18;
    // 0x80800AC4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_18:
    // 0x80800AC8: b           L_80800B80
    // 0x80800ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B80;
    // 0x80800ACC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AD0:
    // 0x80800AD0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800AD4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ADC: and         $a2, $a3, $at
    ctx->r6 = ctx->r7 & ctx->r1;
    // 0x80800AE0: srl         $t9, $a2, 16
    ctx->r25 = S32(U32(ctx->r6) >> 16);
    // 0x80800AE4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80800AE8: jal         0x80802690
    // 0x80800AEC: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    func_80802690_chboilerboss(rdram, ctx);
        goto after_19;
    // 0x80800AEC: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    after_19:
    // 0x80800AF0: b           L_80800B84
    // 0x80800AF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800B84;
    // 0x80800AF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800AF8: lbu         $t0, 0x56($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X56);
L_80800AFC:
    // 0x80800AFC: beql        $t0, $zero, L_80800B80
    if (ctx->r8 == 0) {
        // 0x80800B00: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800B80;
    }
    goto skip_1;
    // 0x80800B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800B04: jal         0x800FDC28
    // 0x80800B08: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_20;
    // 0x80800B08: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
    // 0x80800B0C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80800B10: b           L_80800B7C
    // 0x80800B14: sb          $zero, 0x56($t1)
    MEM_B(0X56, ctx->r9) = 0;
        goto L_80800B7C;
    // 0x80800B14: sb          $zero, 0x56($t1)
    MEM_B(0X56, ctx->r9) = 0;
L_80800B18:
    // 0x80800B18: jal         0x800D395C
    // 0x80800B1C: nop

    func_800D395C(rdram, ctx);
        goto after_21;
    // 0x80800B1C: nop

    after_21:
    // 0x80800B20: bne         $v0, $zero, L_80800B30
    if (ctx->r2 != 0) {
        // 0x80800B24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B30;
    }
    // 0x80800B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B28: b           L_80800B80
    // 0x80800B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B80;
    // 0x80800B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B30:
    // 0x80800B30: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    // 0x80800B34: jal         0x8080238C
    // 0x80800B38: addiu       $a2, $zero, 0x4A
    ctx->r6 = ADD32(0, 0X4A);
    func_8080238C_chboilerboss(rdram, ctx);
        goto after_22;
    // 0x80800B38: addiu       $a2, $zero, 0x4A
    ctx->r6 = ADD32(0, 0X4A);
    after_22:
    // 0x80800B3C: b           L_80800B80
    // 0x80800B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B80;
    // 0x80800B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B44:
    // 0x80800B44: jal         0x800FDC28
    // 0x80800B48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_23;
    // 0x80800B48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B50: jal         0x80800F34
    // 0x80800B54: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800F34_chboilerboss(rdram, ctx);
        goto after_24;
    // 0x80800B54: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_24:
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B60: jal         0x8080221C
    // 0x80800B64: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    func_8080221C_chboilerboss(rdram, ctx);
        goto after_25;
    // 0x80800B64: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_25:
    // 0x80800B68: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80800B6C: b           L_80800B7C
    // 0x80800B70: sb          $zero, 0x55($t2)
    MEM_B(0X55, ctx->r10) = 0;
        goto L_80800B7C;
    // 0x80800B70: sb          $zero, 0x55($t2)
    MEM_B(0X55, ctx->r10) = 0;
L_80800B74:
    // 0x80800B74: b           L_80800B80
    // 0x80800B78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B80;
    // 0x80800B78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B7C:
    // 0x80800B7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B80:
    // 0x80800B80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B84:
    // 0x80800B84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B8C: jr          $ra
    // 0x80800B90: nop

    return;
    // 0x80800B90: nop

;}
RECOMP_FUNC void func_80015670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015670: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80015674: lw          $v0, -0x7098($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7098);
    // 0x80015678: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001567C: slti        $at, $a0, -0x20
    ctx->r1 = SIGNED(ctx->r4) < -0X20 ? 1 : 0;
    // 0x80015680: addiu       $t2, $v0, 0x30
    ctx->r10 = ADD32(ctx->r2, 0X30);
    // 0x80015684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80015688: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001568C: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x80015690: addiu       $t1, $v0, 0x44
    ctx->r9 = ADD32(ctx->r2, 0X44);
    // 0x80015694: addiu       $a3, $v0, 0x1C
    ctx->r7 = ADD32(ctx->r2, 0X1C);
    // 0x80015698: beq         $at, $zero, L_800156A8
    if (ctx->r1 == 0) {
        // 0x8001569C: addiu       $t3, $v0, 0x32
        ctx->r11 = ADD32(ctx->r2, 0X32);
            goto L_800156A8;
    }
    // 0x8001569C: addiu       $t3, $v0, 0x32
    ctx->r11 = ADD32(ctx->r2, 0X32);
    // 0x800156A0: b           L_800156B8
    // 0x800156A4: addiu       $a2, $zero, -0x20
    ctx->r6 = ADD32(0, -0X20);
        goto L_800156B8;
    // 0x800156A4: addiu       $a2, $zero, -0x20
    ctx->r6 = ADD32(0, -0X20);
L_800156A8:
    // 0x800156A8: slti        $at, $a2, 0x21
    ctx->r1 = SIGNED(ctx->r6) < 0X21 ? 1 : 0;
    // 0x800156AC: bnel        $at, $zero, L_800156BC
    if (ctx->r1 != 0) {
        // 0x800156B0: slti        $at, $a1, -0x28
        ctx->r1 = SIGNED(ctx->r5) < -0X28 ? 1 : 0;
            goto L_800156BC;
    }
    goto skip_0;
    // 0x800156B0: slti        $at, $a1, -0x28
    ctx->r1 = SIGNED(ctx->r5) < -0X28 ? 1 : 0;
    skip_0:
    // 0x800156B4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
L_800156B8:
    // 0x800156B8: slti        $at, $a1, -0x28
    ctx->r1 = SIGNED(ctx->r5) < -0X28 ? 1 : 0;
L_800156BC:
    // 0x800156BC: beq         $at, $zero, L_800156CC
    if (ctx->r1 == 0) {
        // 0x800156C0: lui         $a0, 0x8
        ctx->r4 = S32(0X8 << 16);
            goto L_800156CC;
    }
    // 0x800156C0: lui         $a0, 0x8
    ctx->r4 = S32(0X8 << 16);
    // 0x800156C4: b           L_800156DC
    // 0x800156C8: addiu       $a1, $zero, -0x28
    ctx->r5 = ADD32(0, -0X28);
        goto L_800156DC;
    // 0x800156C8: addiu       $a1, $zero, -0x28
    ctx->r5 = ADD32(0, -0X28);
L_800156CC:
    // 0x800156CC: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x800156D0: bnel        $at, $zero, L_800156E0
    if (ctx->r1 != 0) {
        // 0x800156D4: ori         $a0, $a0, 0x401
        ctx->r4 = ctx->r4 | 0X401;
            goto L_800156E0;
    }
    goto skip_1;
    // 0x800156D4: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
    skip_1:
    // 0x800156D8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
L_800156DC:
    // 0x800156DC: ori         $a0, $a0, 0x401
    ctx->r4 = ctx->r4 | 0X401;
L_800156E0:
    // 0x800156E0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800156E4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800156E8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800156EC: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800156F0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800156F4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800156F8: jal         0x8002FEC0
    // 0x800156FC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800156FC: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_0:
    // 0x80015700: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80015704: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80015708: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8001570C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80015710: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80015714: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80015718: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8001571C: addiu       $t6, $a2, 0x80
    ctx->r14 = ADD32(ctx->r6, 0X80);
    // 0x80015720: addiu       $t7, $a2, 0x2E0
    ctx->r15 = ADD32(ctx->r6, 0X2E0);
    // 0x80015724: addiu       $t8, $a1, 0x30
    ctx->r24 = ADD32(ctx->r5, 0X30);
    // 0x80015728: sh          $t6, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r14;
    // 0x8001572C: sh          $t7, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r15;
    // 0x80015730: addiu       $t9, $a1, 0x1F4
    ctx->r25 = ADD32(ctx->r5, 0X1F4);
    // 0x80015734: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x80015738: sh          $t9, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r25;
    // 0x8001573C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80015740: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80015744: jal         0x8002FEC0
    // 0x80015748: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80015748: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    after_1:
    // 0x8001574C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015750: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80015754: jr          $ra
    // 0x80015758: nop

    return;
    // 0x80015758: nop

;}
RECOMP_FUNC void _chtoxicroomprops_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087810: syscall     631
    recomp_syscall_handler(rdram, ctx, 0x80087810);
    return;
    // 0x80087814: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void ncpoddialog_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080139C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808013A4: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x808013A8: jal         0x8001B754
    // 0x808013AC: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    func_8001B754(rdram, ctx);
        goto after_0;
    // 0x808013AC: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_0:
    // 0x808013B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808013B8: jr          $ra
    // 0x808013BC: nop

    return;
    // 0x808013BC: nop

;}
RECOMP_FUNC void chcheatopage_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(872, 0X330) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x330
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(872, 0X330));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x330
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(872, 0X330));
;}
RECOMP_FUNC void func_808008F0_chbadbeehive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F0: jr          $ra
    // 0x808008F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808008F4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800C70_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C78: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800C7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C80: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800C84: beq         $t6, $at, L_80800C9C
    if (ctx->r14 == ctx->r1) {
        // 0x80800C88: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800C9C;
    }
    // 0x80800C88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C8C: beql        $t6, $at, L_80800CA8
    if (ctx->r14 == ctx->r1) {
        // 0x80800C90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800CA8;
    }
    goto skip_0;
    // 0x80800C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800C94: b           L_80800CA8
    // 0x80800C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800CA8;
    // 0x80800C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C9C:
    // 0x80800C9C: jal         0x80800CB4
    // 0x80800CA0: nop

    func_80800CB4_chpawnbroker(rdram, ctx);
        goto after_0;
    // 0x80800CA0: nop

    after_0:
    // 0x80800CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CA8:
    // 0x80800CA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CAC: jr          $ra
    // 0x80800CB0: nop

    return;
    // 0x80800CB0: nop

;}
RECOMP_FUNC void gldbDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800360: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800364: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800368: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080036C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800370: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80800374:
    // 0x80800374: jal         0x80088500
    // 0x80800378: nop

    _gleeprom_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800378: nop

    after_0:
    // 0x8080037C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80800380: sllv        $t7, $t6, $s0
    ctx->r15 = S32(ctx->r14 << (ctx->r16 & 31));
    // 0x80800384: and         $t8, $v0, $t7
    ctx->r24 = ctx->r2 & ctx->r15;
    // 0x80800388: srav        $a0, $t8, $s0
    ctx->r4 = S32(SIGNED(ctx->r24) >> (ctx->r16 & 31));
    // 0x8080038C: jal         0x800DA544
    // 0x80800390: addiu       $a0, $a0, 0x9C4
    ctx->r4 = ADD32(ctx->r4, 0X9C4);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800390: addiu       $a0, $a0, 0x9C4
    ctx->r4 = ADD32(ctx->r4, 0X9C4);
    after_1:
    // 0x80800394: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80800398: slti        $at, $s0, 0x20
    ctx->r1 = SIGNED(ctx->r16) < 0X20 ? 1 : 0;
    // 0x8080039C: bne         $at, $zero, L_80800374
    if (ctx->r1 != 0) {
        // 0x808003A0: nop
    
            goto L_80800374;
    }
    // 0x808003A0: nop

    // 0x808003A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808003A8: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
L_808003AC:
    // 0x808003AC: jal         0x80088458
    // 0x808003B0: nop

    _glreflight_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808003B0: nop

    after_2:
    // 0x808003B4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x808003B8: sllv        $t0, $t9, $s0
    ctx->r8 = S32(ctx->r25 << (ctx->r16 & 31));
    // 0x808003BC: and         $t1, $v0, $t0
    ctx->r9 = ctx->r2 & ctx->r8;
    // 0x808003C0: srav        $a0, $t1, $s0
    ctx->r4 = S32(SIGNED(ctx->r9) >> (ctx->r16 & 31));
    // 0x808003C4: jal         0x800DA544
    // 0x808003C8: addiu       $a0, $a0, 0x9C4
    ctx->r4 = ADD32(ctx->r4, 0X9C4);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x808003C8: addiu       $a0, $a0, 0x9C4
    ctx->r4 = ADD32(ctx->r4, 0X9C4);
    after_3:
    // 0x808003CC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x808003D0: bne         $s0, $s1, L_808003AC
    if (ctx->r16 != ctx->r17) {
        // 0x808003D4: nop
    
            goto L_808003AC;
    }
    // 0x808003D4: nop

    // 0x808003D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808003E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808003E4: jr          $ra
    // 0x808003E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808003E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void chweldarbossdoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1372, 0X270) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x270
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1372, 0X270));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x270
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1372, 0X270));
;}
RECOMP_FUNC void _baflameline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B68: syscall     130
    recomp_syscall_handler(rdram, ctx, 0x80084B68);
    return;
    // 0x80084B6C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void ncbawaypoint_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x84
    ctx->r2 = ADD32(0, 0X84);
;}
RECOMP_FUNC void boot___osSiRawReadIo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8010A01C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A01C: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8010A020: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8010A024: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010A028: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8010A02C: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8010A030: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8010A034: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8010A038: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8010A03C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8010A040: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8010A044: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8010A048: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8010A04C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8010A050: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8010A054: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8010A058: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8010A05C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8010A060: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8010A064: jal         0x800BE444
    // 0x8010A068: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    func_800BE444(rdram, ctx);
        goto after_0;
    // 0x8010A068: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    after_0:
    // 0x8010A06C: sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    // 0x8010A070: jal         0x800CB854
    // 0x8010A074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_1;
    // 0x8010A074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8010A078: beql        $v0, $zero, L_8010A0A0
    if (ctx->r2 == 0) {
        // 0x8010A07C: sw          $zero, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = 0;
            goto L_8010A0A0;
    }
    goto skip_0;
    // 0x8010A07C: sw          $zero, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = 0;
    skip_0:
    // 0x8010A080: jal         0x800CB854
    // 0x8010A084: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_2;
    // 0x8010A084: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8010A088: addiu       $t6, $v0, 0x1F
    ctx->r14 = ADD32(ctx->r2, 0X1F);
    // 0x8010A08C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8010A090: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8010A094: b           L_8010A0A0
    // 0x8010A098: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
        goto L_8010A0A0;
    // 0x8010A098: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x8010A09C: sw          $zero, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = 0;
L_8010A0A0:
    // 0x8010A0A0: addiu       $s7, $sp, 0xB4
    ctx->r23 = ADD32(ctx->r29, 0XB4);
    // 0x8010A0A4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8010A0A8: jal         0x800EE7F8
    // 0x8010A0AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x8010A0AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8010A0B0: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8010A0B4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8010A0B8: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8010A0BC: jal         0x800F0C68
    // 0x8010A0C0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800F0C68(rdram, ctx);
        goto after_4;
    // 0x8010A0C0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_4:
    // 0x8010A0C4: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8010A0C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8010A0CC: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8010A0D0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8010A0D4: lwc1        $f22, 0x64B0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X64B0);
    // 0x8010A0D8: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8010A0DC: beq         $a0, $zero, L_8010A2B8
    if (ctx->r4 == 0) {
        // 0x8010A0E0: addiu       $s4, $sp, 0x7C
        ctx->r20 = ADD32(ctx->r29, 0X7C);
            goto L_8010A2B8;
    }
    // 0x8010A0E0: addiu       $s4, $sp, 0x7C
    ctx->r20 = ADD32(ctx->r29, 0X7C);
    // 0x8010A0E4: addiu       $s2, $sp, 0x70
    ctx->r18 = ADD32(ctx->r29, 0X70);
L_8010A0E8:
    // 0x8010A0E8: jal         0x800E9E88
    // 0x8010A0EC: nop

    func_800E9E88(rdram, ctx);
        goto after_5;
    // 0x8010A0EC: nop

    after_5:
    // 0x8010A0F0: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x8010A0F4: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x8010A0F8: jal         0x800E9EB4
    // 0x8010A0FC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_6;
    // 0x8010A0FC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_6:
    // 0x8010A100: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x8010A104: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x8010A108: lw          $v1, 0xE0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE0);
    // 0x8010A10C: sltu        $at, $t1, $v0
    ctx->r1 = ctx->r9 < ctx->r2 ? 1 : 0;
    // 0x8010A110: beql        $at, $zero, L_8010A2A4
    if (ctx->r1 == 0) {
        // 0x8010A114: lw          $v0, 0xCC($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XCC);
            goto L_8010A2A4;
    }
    goto skip_1;
    // 0x8010A114: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
    skip_1:
L_8010A118:
    // 0x8010A118: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x8010A11C: lw          $v0, 0x8($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X8);
    // 0x8010A120: sll         $t4, $v0, 27
    ctx->r12 = S32(ctx->r2 << 27);
    // 0x8010A124: bgez        $t4, L_8010A288
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8010A128: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_8010A288;
    }
    // 0x8010A128: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8010A12C: beq         $t5, $zero, L_8010A288
    if (ctx->r13 == 0) {
        // 0x8010A130: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8010A288;
    }
    // 0x8010A130: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8010A134: beq         $t6, $zero, L_8010A14C
    if (ctx->r14 == 0) {
        // 0x8010A138: lw          $s3, 0x0($t2)
        ctx->r19 = MEM_W(ctx->r10, 0X0);
            goto L_8010A14C;
    }
    // 0x8010A138: lw          $s3, 0x0($t2)
    ctx->r19 = MEM_W(ctx->r10, 0X0);
    // 0x8010A13C: lw          $t8, 0x24($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X24);
    // 0x8010A140: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x8010A144: bnel        $v1, $t9, L_8010A28C
    if (ctx->r3 != ctx->r25) {
        // 0x8010A148: lw          $t5, 0xA8($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA8);
            goto L_8010A28C;
    }
    goto skip_2;
    // 0x8010A148: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    skip_2:
L_8010A14C:
    // 0x8010A14C: lw          $t0, 0x28($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X28);
    // 0x8010A150: sll         $t2, $t0, 22
    ctx->r10 = S32(ctx->r8 << 22);
    // 0x8010A154: bgezl       $t2, L_8010A28C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8010A158: lw          $t5, 0xA8($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA8);
            goto L_8010A28C;
    }
    goto skip_3;
    // 0x8010A158: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    skip_3:
    // 0x8010A15C: lhu         $v0, 0x14($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X14);
    // 0x8010A160: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8010A164: beql        $v0, $zero, L_8010A28C
    if (ctx->r2 == 0) {
        // 0x8010A168: lw          $t5, 0xA8($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA8);
            goto L_8010A28C;
    }
    goto skip_4;
    // 0x8010A168: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    skip_4:
    // 0x8010A16C: beql        $v0, $at, L_8010A28C
    if (ctx->r2 == ctx->r1) {
        // 0x8010A170: lw          $t5, 0xA8($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA8);
            goto L_8010A28C;
    }
    goto skip_5;
    // 0x8010A170: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    skip_5:
    // 0x8010A174: lhu         $t3, 0x18($s3)
    ctx->r11 = MEM_HU(ctx->r19, 0X18);
    // 0x8010A178: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8010A17C: beql        $t4, $zero, L_8010A28C
    if (ctx->r12 == 0) {
        // 0x8010A180: lw          $t5, 0xA8($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XA8);
            goto L_8010A28C;
    }
    goto skip_6;
    // 0x8010A180: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    skip_6:
    // 0x8010A184: jal         0x80106790
    // 0x8010A188: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80106790(rdram, ctx);
        goto after_7;
    // 0x8010A188: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x8010A18C: lw          $t5, 0x94($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X94);
    // 0x8010A190: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8010A194: sll         $t6, $t5, 14
    ctx->r14 = S32(ctx->r13 << 14);
    // 0x8010A198: bltzl       $t6, L_8010A1AC
    if (SIGNED(ctx->r14) < 0) {
        // 0x8010A19C: lw          $t8, 0x64($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X64);
            goto L_8010A1AC;
    }
    goto skip_7;
    // 0x8010A19C: lw          $t8, 0x64($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X64);
    skip_7:
    // 0x8010A1A0: b           L_8010A288
    // 0x8010A1A4: lw          $v1, 0xE0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE0);
        goto L_8010A288;
    // 0x8010A1A4: lw          $v1, 0xE0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE0);
    // 0x8010A1A8: lw          $t8, 0x64($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X64);
L_8010A1AC:
    // 0x8010A1AC: lw          $t2, 0xC8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC8);
    // 0x8010A1B0: sll         $t0, $t8, 14
    ctx->r8 = S32(ctx->r24 << 14);
    // 0x8010A1B4: bltz        $t0, L_8010A1D4
    if (SIGNED(ctx->r8) < 0) {
        // 0x8010A1B8: nop
    
            goto L_8010A1D4;
    }
    // 0x8010A1B8: nop

    // 0x8010A1BC: lhu         $t1, 0x66($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X66);
    // 0x8010A1C0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8010A1C4: addiu       $a1, $zero, 0xA2
    ctx->r5 = ADD32(0, 0XA2);
    // 0x8010A1C8: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8010A1CC: beq         $t3, $zero, L_8010A1DC
    if (ctx->r11 == 0) {
        // 0x8010A1D0: nop
    
            goto L_8010A1DC;
    }
    // 0x8010A1D0: nop

L_8010A1D4:
    // 0x8010A1D4: b           L_8010A288
    // 0x8010A1D8: lw          $v1, 0xE0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE0);
        goto L_8010A288;
    // 0x8010A1D8: lw          $v1, 0xE0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE0);
L_8010A1DC:
    // 0x8010A1DC: jal         0x8010108C
    // 0x8010A1E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_8;
    // 0x8010A1E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8010A1E4: blez        $v0, L_8010A1FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8010A1E8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8010A1FC;
    }
    // 0x8010A1E8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8010A1EC: jal         0x80101080
    // 0x8010A1F0: nop

    func_80101080(rdram, ctx);
        goto after_9;
    // 0x8010A1F0: nop

    after_9:
    // 0x8010A1F4: b           L_8010A210
    // 0x8010A1F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8010A210;
    // 0x8010A1F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8010A1FC:
    // 0x8010A1FC: addiu       $s0, $sp, 0x88
    ctx->r16 = ADD32(ctx->r29, 0X88);
    // 0x8010A200: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010A204: jal         0x80103DFC
    // 0x8010A208: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80103DFC(rdram, ctx);
        goto after_10;
    // 0x8010A208: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_10:
    // 0x8010A20C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8010A210:
    // 0x8010A210: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8010A214: beq         $s1, $zero, L_8010A284
    if (ctx->r17 == 0) {
        // 0x8010A218: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8010A284;
    }
    // 0x8010A218: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8010A21C:
    // 0x8010A21C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8010A220: jal         0x800EE7F8
    // 0x8010A224: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x8010A224: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x8010A228: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010A22C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8010A230: jal         0x800EFB24
    // 0x8010A234: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    func_800EFB24(rdram, ctx);
        goto after_12;
    // 0x8010A234: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_12:
    // 0x8010A238: jal         0x800EEFD4
    // 0x8010A23C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EEFD4(rdram, ctx);
        goto after_13;
    // 0x8010A23C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x8010A240: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8010A244: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8010A248: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8010A24C: bc1fl       L_8010A278
    if (!c1cs) {
        // 0x8010A250: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_8010A278;
    }
    goto skip_8;
    // 0x8010A250: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    skip_8:
    // 0x8010A254: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8010A258: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8010A25C: jal         0x800F0BD0
    // 0x8010A260: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800F0BD0(rdram, ctx);
        goto after_14;
    // 0x8010A260: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_14:
    // 0x8010A264: beql        $v0, $zero, L_8010A278
    if (ctx->r2 == 0) {
        // 0x8010A268: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_8010A278;
    }
    goto skip_9;
    // 0x8010A268: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    skip_9:
    // 0x8010A26C: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x8010A270: or          $s6, $s3, $zero
    ctx->r22 = ctx->r19 | 0;
    // 0x8010A274: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_8010A278:
    // 0x8010A278: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8010A27C: bne         $s1, $zero, L_8010A21C
    if (ctx->r17 != 0) {
        // 0x8010A280: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8010A21C;
    }
    // 0x8010A280: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_8010A284:
    // 0x8010A284: lw          $v1, 0xE0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE0);
L_8010A288:
    // 0x8010A288: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
L_8010A28C:
    // 0x8010A28C: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x8010A290: addiu       $t7, $t5, 0xC
    ctx->r15 = ADD32(ctx->r13, 0XC);
    // 0x8010A294: sltu        $at, $t7, $t6
    ctx->r1 = ctx->r15 < ctx->r14 ? 1 : 0;
    // 0x8010A298: bne         $at, $zero, L_8010A118
    if (ctx->r1 != 0) {
        // 0x8010A29C: sw          $t7, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r15;
            goto L_8010A118;
    }
    // 0x8010A29C: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
    // 0x8010A2A0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8010A2A4:
    // 0x8010A2A4: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8010A2A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8010A2AC: sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    // 0x8010A2B0: bne         $a0, $zero, L_8010A0E8
    if (ctx->r4 != 0) {
        // 0x8010A2B4: nop
    
            goto L_8010A0E8;
    }
    // 0x8010A2B4: nop

L_8010A2B8:
    // 0x8010A2B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8010A2BC: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x8010A2C0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8010A2C4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010A2C8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8010A2CC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8010A2D0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8010A2D4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8010A2D8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8010A2DC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8010A2E0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8010A2E4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8010A2E8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8010A2EC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8010A2F0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8010A2F4: jr          $ra
    // 0x8010A2F8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x8010A2F8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_800EFCD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFCD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EFCDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EFCE0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800EFCE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EFCE8: jal         0x800137F4
    // 0x800EFCEC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800137F4(rdram, ctx);
        goto after_0;
    // 0x800EFCEC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800EFCF0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EFCF4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800EFCF8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800EFCFC: jal         0x80013788
    // 0x800EFD00: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    func_80013788(rdram, ctx);
        goto after_1;
    // 0x800EFD00: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    after_1:
    // 0x800EFD04: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EFD08: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800EFD0C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800EFD10: swc1        $f10, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f10.u32l;
    // 0x800EFD14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EFD18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EFD1C: jr          $ra
    // 0x800EFD20: nop

    return;
    // 0x800EFD20: nop

;}
RECOMP_FUNC void func_800B2DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2DC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B2DC4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B2DC8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B2DCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2DD0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800B2DD4: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2DD8: mflo        $v0
    ctx->r2 = lo;
    // 0x800B2DDC: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x800B2DE0: jal         0x8001B668
    // 0x800B2DE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8001B668(rdram, ctx);
        goto after_0;
    // 0x800B2DE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800B2DE8: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800B2DEC: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800B2DF0: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x800B2DF4: jal         0x8001B798
    // 0x800B2DF8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x800B2DF8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_1:
    // 0x800B2DFC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800B2E00: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800B2E04: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x800B2E08: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x800B2E0C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800B2E10: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2E14: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x800B2E18: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
    // 0x800B2E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2E20: lh          $v0, 0x26($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X26);
    // 0x800B2E24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B2E28: jr          $ra
    // 0x800B2E2C: nop

    return;
    // 0x800B2E2C: nop

;}
RECOMP_FUNC void func_8080005C_chlavaslabswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800068: jal         0x80085808
    // 0x8080006C: addiu       $a1, $zero, 0x38F
    ctx->r5 = ADD32(0, 0X38F);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080006C: addiu       $a1, $zero, 0x38F
    ctx->r5 = ADD32(0, 0X38F);
    after_0:
    // 0x80800070: jal         0x80085818
    // 0x80800074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chswitch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080007C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800080: jr          $ra
    // 0x80800084: nop

    return;
    // 0x80800084: nop

;}
RECOMP_FUNC void func_8009BAF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BAF4: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BAF8: jr          $ra
    // 0x8009BAFC: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    return;
    // 0x8009BAFC: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
;}
RECOMP_FUNC void chfiregen_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C2C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1588, 0X18DC) << 16);
    // 0x80800C30: jr          $ra
    // 0x80800C34: addiu       $v0, $v0, 0x18DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X18DC));
    return;
    // 0x80800C34: addiu       $v0, $v0, 0x18DC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1588, 0X18DC));
;}
RECOMP_FUNC void chspiralgrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1520, 0X180) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x180
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1520, 0X180));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x180
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1520, 0X180));
;}
RECOMP_FUNC void _sumole_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A70: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A70);
    return;
    // 0x80089A74: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void boot___ll_rem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800028E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800028E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800028E8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800028EC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800028F0: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x800028F4: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x800028F8: ddivu       $zero, $t6, $t7
    DDIVU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x800028FC: bne         $t7, $zero, L_80002908
    if (ctx->r15 != 0) {
        // 0x80002900: nop
    
            goto L_80002908;
    }
    // 0x80002900: nop

    // 0x80002904: break       7
    do_break(2147494148);
L_80002908:
    // 0x80002908: mfhi        $v0
    ctx->r2 = hi;
    // 0x8000290C: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x80002910: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x80002914: jr          $ra
    // 0x80002918: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80002918: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void gspropctrl_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: jr          $ra
    // 0x8080004C: lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8);
    return;
    // 0x8080004C: lhu         $v0, 0x8($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X8);
;}
RECOMP_FUNC void batimer_isAt_falling(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: lw          $t6, 0x13C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X13C);
    // 0x80800160: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800164: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800168: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8080016C: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80800170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800174: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x80800178: nop

    // 0x8080017C: bc1f        L_80800188
    if (!c1cs) {
        // 0x80800180: nop
    
            goto L_80800188;
    }
    // 0x80800180: nop

    // 0x80800184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800188:
    // 0x80800188: beq         $v0, $zero, L_808001AC
    if (ctx->r2 == 0) {
        // 0x8080018C: nop
    
            goto L_808001AC;
    }
    // 0x8080018C: nop

    // 0x80800190: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800198: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x8080019C: nop

    // 0x808001A0: bc1f        L_808001AC
    if (!c1cs) {
        // 0x808001A4: nop
    
            goto L_808001AC;
    }
    // 0x808001A4: nop

    // 0x808001A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001AC:
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void func_8001D37C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D37C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D380: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001D384: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001D388: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001D38C: sw          $t6, -0x2EA0($at)
    MEM_W(-0X2EA0, ctx->r1) = ctx->r14;
    // 0x8001D390: or          $a3, $sp, $zero
    ctx->r7 = ctx->r29 | 0;
    // 0x8001D394: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001D398: addiu       $a3, $a3, 0x27
    ctx->r7 = ADD32(ctx->r7, 0X27);
    // 0x8001D39C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8001D3A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D3A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001D3A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001D3AC: and         $t7, $a3, $at
    ctx->r15 = ctx->r7 & ctx->r1;
    // 0x8001D3B0: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x8001D3B4: addiu       $a0, $a0, -0x2CC0
    ctx->r4 = ADD32(ctx->r4, -0X2CC0);
    // 0x8001D3B8: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x8001D3BC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8001D3C0: jal         0x80030B30
    // 0x8001D3C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _Printf(rdram, ctx);
        goto after_0;
    // 0x8001D3C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8001D3C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D3CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D3D0: jr          $ra
    // 0x8001D3D4: nop

    return;
    // 0x8001D3D4: nop

;}
RECOMP_FUNC void func_80801230_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801230: lbu         $t7, 0x15D($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X15D);
    // 0x80801234: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80801238: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    // 0x8080123C: jr          $ra
    // 0x80801240: sb          $t7, 0x15E($a0)
    MEM_B(0X15E, ctx->r4) = ctx->r15;
    return;
    // 0x80801240: sb          $t7, 0x15E($a0)
    MEM_B(0X15E, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void _bssplat_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A78: syscall     88
    recomp_syscall_handler(rdram, ctx, 0x80083A78);
    return;
    // 0x80083A7C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chfactoryworkerdirty_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087310: syscall     550
    recomp_syscall_handler(rdram, ctx, 0x80087310);
    return;
    // 0x80087314: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801130_chhoopswoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801130: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801134: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801138: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080113C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801140: jal         0x80100094
    // 0x80801144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801148: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080114C: lhu         $t6, 0x6E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6E);
    // 0x80801150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801154: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80801158: ori         $t8, $t7, 0x5
    ctx->r24 = ctx->r15 | 0X5;
    // 0x8080115C: jal         0x80800094
    // 0x80801160: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
    func_80800094_chhoopswoop(rdram, ctx);
        goto after_1;
    // 0x80801160: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
    after_1:
    // 0x80801164: jal         0x8008A0A0
    // 0x80801168: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _subaddiemulti_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80801168: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_2:
    // 0x8080116C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80801170: addiu       $s0, $s0, 0x4DC
    ctx->r16 = ADD32(ctx->r16, 0X4DC);
    // 0x80801174: jal         0x80089980
    // 0x80801178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sumultiscore_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80801178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080117C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801180: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801188: jal         0x80089988
    // 0x8080118C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x8080118C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80801190: jal         0x80088368
    // 0x80801194: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80801194: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_5:
    // 0x80801198: blezl       $v0, L_808011CC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080119C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808011CC;
    }
    goto skip_0;
    // 0x8080119C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_808011A0:
    // 0x808011A0: jal         0x800F53D0
    // 0x808011A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F53D0(rdram, ctx);
        goto after_6;
    // 0x808011A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808011A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808011AC: jal         0x800946C4
    // 0x808011B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800946C4(rdram, ctx);
        goto after_7;
    // 0x808011B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808011B4: jal         0x80088368
    // 0x808011B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x808011B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_8:
    // 0x808011BC: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808011C0: bne         $at, $zero, L_808011A0
    if (ctx->r1 != 0) {
        // 0x808011C4: nop
    
            goto L_808011A0;
    }
    // 0x808011C4: nop

    // 0x808011C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011CC:
    // 0x808011CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808011D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808011D4: jr          $ra
    // 0x808011D8: nop

    return;
    // 0x808011D8: nop

;}
RECOMP_FUNC void baflameline_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
;}
RECOMP_FUNC void bsbbilldrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800600: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800608: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080060C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800610: jal         0x800931AC
    // 0x80800614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800931AC(rdram, ctx);
        goto after_0;
    // 0x80800614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800618: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080061C: jal         0x80093300
    // 0x80800620: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80093300(rdram, ctx);
        goto after_1;
    // 0x80800620: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800628: jal         0x80098520
    // 0x8080062C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80098520(rdram, ctx);
        goto after_2;
    // 0x8080062C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x80800630: jal         0x8009BC6C
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_3;
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800638: jal         0x8009BC90
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_4;
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800644: jal         0x800A0CF4
    // 0x80800648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_5;
    // 0x80800648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800650: jal         0x80095774
    // 0x80800654: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    baflag_clear(rdram, ctx);
        goto after_6;
    // 0x80800654: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_6:
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080065C: jal         0x80095774
    // 0x80800660: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    baflag_clear(rdram, ctx);
        goto after_7;
    // 0x80800660: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_7:
    // 0x80800664: jal         0x8009E474
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_8;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080066C: jal         0x808000C0
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C0_bsbbilldrill(rdram, ctx);
        goto after_9;
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800674: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800678: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080067C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800680: jr          $ra
    // 0x80800684: nop

    return;
    // 0x80800684: nop

;}
RECOMP_FUNC void mlMtx_get_stack_pointer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018BA8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80018BAC: jr          $ra
    // 0x80018BB0: lw          $v0, -0x4350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4350);
    return;
    // 0x80018BB0: lw          $v0, -0x4350($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4350);
;}
RECOMP_FUNC void _sumissilehome_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A770: syscall     850
    recomp_syscall_handler(rdram, ctx, 0x8008A770);
    return;
    // 0x8008A774: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80803E18_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803E18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803E1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80803E20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80803E24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803E28: jal         0x80100094
    // 0x80803E2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80803E2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803E30: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80803E34: jal         0x80106790
    // 0x80803E38: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80803E38: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x80803E3C: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x80803E40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803E44: andi        $t6, $a1, 0x1FF
    ctx->r14 = ctx->r5 & 0X1FF;
    // 0x80803E48: jal         0x80089AF8
    // 0x80803E4C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80803E4C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_2:
    // 0x80803E50: beq         $v0, $zero, L_80803EE0
    if (ctx->r2 == 0) {
        // 0x80803E54: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80803EE0;
    }
    // 0x80803E54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803E58: beq         $v0, $at, L_80803EC0
    if (ctx->r2 == ctx->r1) {
        // 0x80803E5C: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80803EC0;
    }
    // 0x80803E5C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80803E60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803E64: beq         $v0, $at, L_80803E7C
    if (ctx->r2 == ctx->r1) {
        // 0x80803E68: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80803E7C;
    }
    // 0x80803E68: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80803E6C: beq         $v0, $at, L_80803E98
    if (ctx->r2 == ctx->r1) {
        // 0x80803E70: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_80803E98;
    }
    // 0x80803E70: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80803E74: b           L_80803EE4
    // 0x80803E78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803EE4;
    // 0x80803E78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803E7C:
    // 0x80803E7C: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80803E80: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80803E84: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x80803E88: jal         0x80089AB8
    // 0x80803E8C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _sukickball_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80803E8C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_3:
    // 0x80803E90: b           L_80803EE4
    // 0x80803E94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803EE4;
    // 0x80803E94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803E98:
    // 0x80803E98: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80803E9C: lbu         $a1, 0x14($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X14);
    // 0x80803EA0: andi        $t8, $a0, 0x1FF
    ctx->r24 = ctx->r4 & 0X1FF;
    // 0x80803EA4: jal         0x80803D54
    // 0x80803EA8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80803D54_chcollballcontrol(rdram, ctx);
        goto after_4;
    // 0x80803EA8: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_4:
    // 0x80803EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803EB0: jal         0x80803EF4
    // 0x80803EB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80803EF4_chcollballcontrol(rdram, ctx);
        goto after_5;
    // 0x80803EB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80803EB8: b           L_80803EE4
    // 0x80803EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80803EE4;
    // 0x80803EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803EC0:
    // 0x80803EC0: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x80803EC4: lbu         $a1, 0x14($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X14);
    // 0x80803EC8: andi        $t0, $a0, 0x1FF
    ctx->r8 = ctx->r4 & 0X1FF;
    // 0x80803ECC: jal         0x80803D54
    // 0x80803ED0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_80803D54_chcollballcontrol(rdram, ctx);
        goto after_6;
    // 0x80803ED0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_6:
    // 0x80803ED4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803ED8: jal         0x80089AB8
    // 0x80803EDC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    _sukickball_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80803EDC: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_7:
L_80803EE0:
    // 0x80803EE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80803EE4:
    // 0x80803EE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80803EE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80803EEC: jr          $ra
    // 0x80803EF0: nop

    return;
    // 0x80803EF0: nop

;}
RECOMP_FUNC void func_8008E9AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E9AC: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8008E9B0: jr          $ra
    // 0x8008E9B4: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    return;
    // 0x8008E9B4: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
;}
RECOMP_FUNC void _chicestationbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086358: syscall     311
    recomp_syscall_handler(rdram, ctx, 0x80086358);
    return;
    // 0x8008635C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _baduo_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084990: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084990);
    return;
    // 0x80084994: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _chjigsawdance_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800858B8: syscall     179
    recomp_syscall_handler(rdram, ctx, 0x800858B8);
    return;
    // 0x800858BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void boot___osGetSR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800B798C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B798C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7994: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800B7998: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B799C: beq         $a2, $zero, L_800B7A88
    if (ctx->r6 == 0) {
        // 0x800B79A0: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800B7A88;
    }
    // 0x800B79A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800B79A4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B79A8: addiu       $a2, $a2, -0x7E80
    ctx->r6 = ADD32(ctx->r6, -0X7E80);
    // 0x800B79AC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800B79B0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800B79B4: bne         $t7, $zero, L_800B79D0
    if (ctx->r15 != 0) {
        // 0x800B79B8: nop
    
            goto L_800B79D0;
    }
    // 0x800B79B8: nop

    // 0x800B79BC: jal         0x800B2D70
    // 0x800B79C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    vector_new(rdram, ctx);
        goto after_0;
    // 0x800B79C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x800B79C4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B79C8: addiu       $a2, $a2, -0x7E80
    ctx->r6 = ADD32(ctx->r6, -0X7E80);
    // 0x800B79CC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_800B79D0:
    // 0x800B79D0: jal         0x800B2974
    // 0x800B79D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    vector_push_back(rdram, ctx);
        goto after_1;
    // 0x800B79D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x800B79D8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800B79DC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B79E0: addiu       $a2, $a2, -0x7E80
    ctx->r6 = ADD32(ctx->r6, -0X7E80);
    // 0x800B79E4: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800B79E8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800B79EC: lbu         $t5, 0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X6);
    // 0x800B79F0: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x800B79F4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800B79F8: andi        $t6, $t5, 0xFF0F
    ctx->r14 = ctx->r13 & 0XFF0F;
    // 0x800B79FC: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
    // 0x800B7A00: lbu         $t2, 0x11($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X11);
    // 0x800B7A04: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x800B7A08: or          $t2, $t4, $t6
    ctx->r10 = ctx->r12 | ctx->r14;
    // 0x800B7A0C: sb          $t2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r10;
    // 0x800B7A10: lbu         $t9, 0x12($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X12);
    // 0x800B7A14: andi        $t3, $t2, 0xF7
    ctx->r11 = ctx->r10 & 0XF7;
    // 0x800B7A18: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800B7A1C: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x800B7A20: or          $t9, $t1, $t3
    ctx->r25 = ctx->r9 | ctx->r11;
    // 0x800B7A24: sb          $t9, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r25;
    // 0x800B7A28: lbu         $t6, 0x10($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X10);
    // 0x800B7A2C: andi        $t0, $t9, 0xFB
    ctx->r8 = ctx->r25 & 0XFB;
    // 0x800B7A30: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800B7A34: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800B7A38: or          $t6, $t8, $t0
    ctx->r14 = ctx->r24 | ctx->r8;
    // 0x800B7A3C: sb          $t6, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r14;
    // 0x800B7A40: lbu         $t3, 0x13($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X13);
    // 0x800B7A44: andi        $t7, $t6, 0xFD
    ctx->r15 = ctx->r14 & 0XFD;
    // 0x800B7A48: sll         $t5, $t3, 1
    ctx->r13 = S32(ctx->r11 << 1);
    // 0x800B7A4C: andi        $t4, $t5, 0x2
    ctx->r12 = ctx->r13 & 0X2;
    // 0x800B7A50: or          $t9, $t4, $t7
    ctx->r25 = ctx->r12 | ctx->r15;
    // 0x800B7A54: sb          $t9, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r25;
    // 0x800B7A58: lh          $t8, 0x14($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X14);
    // 0x800B7A5C: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x800B7A60: lwc1        $f4, 0x18($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800B7A64: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800B7A68: lbu         $t0, 0xC($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0XC);
    // 0x800B7A6C: sb          $t0, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r8;
    // 0x800B7A70: lbu         $t2, 0xD($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XD);
    // 0x800B7A74: sb          $t2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r10;
    // 0x800B7A78: lbu         $t1, 0xE($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0XE);
    // 0x800B7A7C: sb          $t1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r9;
    // 0x800B7A80: lbu         $t3, 0xF($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0XF);
    // 0x800B7A84: sb          $t3, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r11;
L_800B7A88:
    // 0x800B7A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B7A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7A90: jr          $ra
    // 0x800B7A94: nop

    return;
    // 0x800B7A94: nop

;}
RECOMP_FUNC void func_8080013C_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80800140: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80800144: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80800148: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080014C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2372, 0X1030) << 16);
    // 0x80800150: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800154: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x80800158: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x8080015C: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80800160: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x80800164: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80800168: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8080016C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80800170: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800174: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800178: lwc1        $f22, 0x1030($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2372, 0X1030));
    // 0x8080017C: jal         0x80100094
    // 0x80800180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800184: lw          $t6, 0x6C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X6C);
    // 0x80800188: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080018C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800190: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800194: beq         $t7, $zero, L_80800344
    if (ctx->r15 == 0) {
        // 0x80800198: addiu       $s7, $sp, 0x7C
        ctx->r23 = ADD32(ctx->r29, 0X7C);
            goto L_80800344;
    }
    // 0x80800198: addiu       $s7, $sp, 0x7C
    ctx->r23 = ADD32(ctx->r29, 0X7C);
    // 0x8080019C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x808001A0: addiu       $s6, $sp, 0xA8
    ctx->r22 = ADD32(ctx->r29, 0XA8);
    // 0x808001A4: addiu       $s5, $sp, 0x88
    ctx->r21 = ADD32(ctx->r29, 0X88);
    // 0x808001A8: addiu       $s4, $sp, 0x94
    ctx->r20 = ADD32(ctx->r29, 0X94);
    // 0x808001AC: addiu       $s2, $sp, 0xB4
    ctx->r18 = ADD32(ctx->r29, 0XB4);
    // 0x808001B0: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
L_808001B4:
    // 0x808001B4: c.eq.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl == ctx->f4.fl;
    // 0x808001B8: nop

    // 0x808001BC: bc1f        L_808001F8
    if (!c1cs) {
        // 0x808001C0: nop
    
            goto L_808001F8;
    }
    // 0x808001C0: nop

    // 0x808001C4: jal         0x800D90A4
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D90A4(rdram, ctx);
        goto after_1;
    // 0x808001C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001CC: beql        $v0, $zero, L_8080032C
    if (ctx->r2 == 0) {
        // 0x808001D0: lw          $t5, 0x6C($s3)
        ctx->r13 = MEM_W(ctx->r19, 0X6C);
            goto L_8080032C;
    }
    goto skip_0;
    // 0x808001D0: lw          $t5, 0x6C($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X6C);
    skip_0:
    // 0x808001D4: lw          $t8, 0x34($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X34);
    // 0x808001D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808001DC: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x808001E0: beql        $at, $zero, L_8080032C
    if (ctx->r1 == 0) {
        // 0x808001E4: lw          $t5, 0x6C($s3)
        ctx->r13 = MEM_W(ctx->r19, 0X6C);
            goto L_8080032C;
    }
    goto skip_1;
    // 0x808001E4: lw          $t5, 0x6C($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X6C);
    skip_1:
    // 0x808001E8: jal         0x80800BE0
    // 0x808001EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800BE0_chfactorysparkroom(rdram, ctx);
        goto after_2;
    // 0x808001EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x808001F0: b           L_8080032C
    // 0x808001F4: lw          $t5, 0x6C($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X6C);
        goto L_8080032C;
    // 0x808001F4: lw          $t5, 0x6C($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X6C);
L_808001F8:
    // 0x808001F8: jal         0x800D90A4
    // 0x808001FC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800D90A4(rdram, ctx);
        goto after_3;
    // 0x808001FC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800200: beq         $v0, $zero, L_80800218
    if (ctx->r2 == 0) {
        // 0x80800204: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800218;
    }
    // 0x80800204: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800208: jal         0x80800B60
    // 0x8080020C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800B60_chfactorysparkroom(rdram, ctx);
        goto after_4;
    // 0x8080020C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80800210: b           L_8080032C
    // 0x80800214: lw          $t5, 0x6C($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X6C);
        goto L_8080032C;
    // 0x80800214: lw          $t5, 0x6C($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X6C);
L_80800218:
    // 0x80800218: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8080021C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800220: lwc1        $f14, 0x0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800224: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800228: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8080022C: jal         0x800F10B4
    // 0x80800230: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80800230: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80800234: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2372, 0X107C) << 16);
    // 0x80800238: addiu       $t9, $t9, 0x107C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2372, 0X107C));
    // 0x8080023C: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80800240: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2372, 0X1088) << 16);
    // 0x80800244: addiu       $t2, $t2, 0x1088
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2372, 0X1088));
    // 0x80800248: sw          $at, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r1;
    // 0x8080024C: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80800250: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800254: sw          $t1, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r9;
    // 0x80800258: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x8080025C: sw          $at, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r1;
    // 0x80800260: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x80800264: sw          $at, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r1;
    // 0x80800268: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x8080026C: sw          $t4, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r12;
    // 0x80800270: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x80800274: jal         0x800F54E4
    // 0x80800278: sw          $at, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r1;
    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80800278: sw          $at, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r1;
    after_6:
    // 0x8080027C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800280: jal         0x800F5A00
    // 0x80800284: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800F5A00(rdram, ctx);
        goto after_7;
    // 0x80800284: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_7:
    // 0x80800288: jal         0x800D7520
    // 0x8080028C: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    func_800D7520(rdram, ctx);
        goto after_8;
    // 0x8080028C: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_8:
    // 0x80800290: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800298: jal         0x800C7A68
    // 0x8080029C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800C7A68(rdram, ctx);
        goto after_9;
    // 0x8080029C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_9:
    // 0x808002A0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808002A4: jal         0x800EFC7C
    // 0x808002A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_10;
    // 0x808002A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_10:
    // 0x808002AC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x808002B0: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x808002B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808002B8: bc1fl       L_808002CC
    if (!c1cs) {
        // 0x808002BC: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_808002CC;
    }
    goto skip_2;
    // 0x808002BC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    skip_2:
    // 0x808002C0: jal         0x800EE7F8
    // 0x808002C4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x808002C4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_11:
    // 0x808002C8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
L_808002CC:
    // 0x808002CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808002D0: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x808002D4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808002D8: jal         0x800DC0C0
    // 0x808002DC: swc1        $f16, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f16.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_12;
    // 0x808002DC: swc1        $f16, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x808002E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2372, 0X1034) << 16);
    // 0x808002E4: lwc1        $f18, 0x1034($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2372, 0X1034));
    // 0x808002E8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2372, 0X1038) << 16);
    // 0x808002EC: lwc1        $f6, 0x1038($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2372, 0X1038));
    // 0x808002F0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808002F4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808002F8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808002FC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80800300: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800304: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80800308: jal         0x800F3214
    // 0x8080030C: nop

    func_800F3214(rdram, ctx);
        goto after_13;
    // 0x8080030C: nop

    after_13:
    // 0x80800310: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80800314: jal         0x800C8E84
    // 0x80800318: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800C8E84(rdram, ctx);
        goto after_14;
    // 0x80800318: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_14:
    // 0x8080031C: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80800320: jal         0x800C8CB8
    // 0x80800324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_15;
    // 0x80800324: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_15:
    // 0x80800328: lw          $t5, 0x6C($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X6C);
L_8080032C:
    // 0x8080032C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800330: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80800334: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80800338: sltu        $at, $s1, $t6
    ctx->r1 = ctx->r17 < ctx->r14 ? 1 : 0;
    // 0x8080033C: bnel        $at, $zero, L_808001B4
    if (ctx->r1 != 0) {
        // 0x80800340: lwc1        $f4, 0x4($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
            goto L_808001B4;
    }
    goto skip_3;
    // 0x80800340: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    skip_3:
L_80800344:
    // 0x80800344: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2372, 0X103C) << 16);
    // 0x80800348: lwc1        $f10, 0x103C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2372, 0X103C));
    // 0x8080034C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80800350: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
    // 0x80800354: c.lt.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl < ctx->f10.fl;
    // 0x80800358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080035C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2372, 0X1060) << 16);
    // 0x80800360: bc1fl       L_80800398
    if (!c1cs) {
        // 0x80800364: lw          $t0, 0x70($s3)
        ctx->r8 = MEM_W(ctx->r19, 0X70);
            goto L_80800398;
    }
    goto skip_4;
    // 0x80800364: lw          $t0, 0x70($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X70);
    skip_4:
    // 0x80800368: lw          $t7, 0x70($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X70);
    // 0x8080036C: lbu         $a0, 0x50($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X50);
    // 0x80800370: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2372, 0X1060) << 16);
    // 0x80800374: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80800378: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080037C: addiu       $a3, $a3, 0x1060
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2372, 0X1060));
    // 0x80800380: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
    // 0x80800384: jal         0x80089D68
    // 0x80800388: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_16;
    // 0x80800388: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x8080038C: b           L_808003B0
    // 0x80800390: sb          $v0, 0x50($s3)
    MEM_B(0X50, ctx->r19) = ctx->r2;
        goto L_808003B0;
    // 0x80800390: sb          $v0, 0x50($s3)
    MEM_B(0X50, ctx->r19) = ctx->r2;
    // 0x80800394: lw          $t0, 0x70($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X70);
L_80800398:
    // 0x80800398: lbu         $a0, 0x50($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X50);
    // 0x8080039C: addiu       $a3, $a3, 0x1060
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2372, 0X1060));
    // 0x808003A0: andi        $t9, $t0, 0x1
    ctx->r25 = ctx->r8 & 0X1;
    // 0x808003A4: jal         0x80089D68
    // 0x808003A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_17;
    // 0x808003A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_17:
    // 0x808003AC: sb          $v0, 0x50($s3)
    MEM_B(0X50, ctx->r19) = ctx->r2;
L_808003B0:
    // 0x808003B0: lwc1        $f16, 0x54($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X54);
    // 0x808003B4: c.eq.s      $f24, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f24.fl == ctx->f16.fl;
    // 0x808003B8: nop

    // 0x808003BC: bc1f        L_808004F4
    if (!c1cs) {
        // 0x808003C0: nop
    
            goto L_808004F4;
    }
    // 0x808003C0: nop

    // 0x808003C4: jal         0x800F54E4
    // 0x808003C8: nop

    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x808003C8: nop

    after_18:
    // 0x808003CC: jal         0x800F581C
    // 0x808003D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F581C(rdram, ctx);
        goto after_19;
    // 0x808003D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
    // 0x808003D4: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x808003D8: bltz        $t1, L_808003FC
    if (SIGNED(ctx->r9) < 0) {
        // 0x808003DC: lui         $s0, 0x800
        ctx->r16 = S32(0X800 << 16);
            goto L_808003FC;
    }
    // 0x808003DC: lui         $s0, 0x800
    ctx->r16 = S32(0X800 << 16);
    // 0x808003E0: jal         0x800F54E4
    // 0x808003E4: nop

    func_800F54E4(rdram, ctx);
        goto after_20;
    // 0x808003E4: nop

    after_20:
    // 0x808003E8: jal         0x800F55FC
    // 0x808003EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F55FC(rdram, ctx);
        goto after_21;
    // 0x808003EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
    // 0x808003F0: and         $t3, $v0, $s0
    ctx->r11 = ctx->r2 & ctx->r16;
    // 0x808003F4: beql        $t3, $zero, L_808005AC
    if (ctx->r11 == 0) {
        // 0x808003F8: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_808005AC;
    }
    goto skip_5;
    // 0x808003F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_5:
L_808003FC:
    // 0x808003FC: jal         0x800F54E4
    // 0x80800400: nop

    func_800F54E4(rdram, ctx);
        goto after_22;
    // 0x80800400: nop

    after_22:
    // 0x80800404: jal         0x800F6C5C
    // 0x80800408: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_23;
    // 0x80800408: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x8080040C: beql        $v0, $zero, L_808005AC
    if (ctx->r2 == 0) {
        // 0x80800410: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_808005AC;
    }
    goto skip_6;
    // 0x80800410: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_6:
    // 0x80800414: jal         0x800F54E4
    // 0x80800418: nop

    func_800F54E4(rdram, ctx);
        goto after_24;
    // 0x80800418: nop

    after_24:
    // 0x8080041C: addiu       $s0, $s3, 0x4
    ctx->r16 = ADD32(ctx->r19, 0X4);
    // 0x80800420: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800424: jal         0x800F5A00
    // 0x80800428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5A00(rdram, ctx);
        goto after_25;
    // 0x80800428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_25:
    // 0x8080042C: jal         0x800F54E4
    // 0x80800430: nop

    func_800F54E4(rdram, ctx);
        goto after_26;
    // 0x80800430: nop

    after_26:
    // 0x80800434: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800438: jal         0x800F796C
    // 0x8080043C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800F796C(rdram, ctx);
        goto after_27;
    // 0x8080043C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_27:
    // 0x80800440: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800444: jal         0x800862B8
    // 0x80800448: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _chelectricfence_entrypoint_1(rdram, ctx);
        goto after_28;
    // 0x80800448: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_28:
    // 0x8080044C: lhu         $t2, 0x76($s3)
    ctx->r10 = MEM_HU(ctx->r19, 0X76);
    // 0x80800450: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800454: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800458: srl         $t4, $t2, 7
    ctx->r12 = S32(U32(ctx->r10) >> 7);
    // 0x8080045C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80800460: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800464: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80800468: bgez        $t4, L_80800480
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8080046C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80800480;
    }
    // 0x8080046C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800470: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800474: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800478: nop

    // 0x8080047C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80800480:
    // 0x80800480: div.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80800484: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800488: jal         0x80018820
    // 0x8080048C: nop

    func_80018820(rdram, ctx);
        goto after_29;
    // 0x8080048C: nop

    after_29:
    // 0x80800490: lhu         $t5, 0x76($s3)
    ctx->r13 = MEM_HU(ctx->r19, 0X76);
    // 0x80800494: addiu       $s1, $sp, 0x70
    ctx->r17 = ADD32(ctx->r29, 0X70);
    // 0x80800498: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080049C: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x808004A0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x808004A4: bgez        $t6, L_808004B8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808004A8: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_808004B8;
    }
    // 0x808004A8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808004AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808004B0: nop

    // 0x808004B4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_808004B8:
    // 0x808004B8: div.s       $f6, $f16, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x808004BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808004C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004C4: jal         0x800EE7F8
    // 0x808004C8: swc1        $f6, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f6.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_30;
    // 0x808004C8: swc1        $f6, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->f6.u32l;
    after_30:
    // 0x808004CC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x808004D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808004D4: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x808004D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808004DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808004E0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808004E4: jal         0x808005E0
    // 0x808004E8: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    func_808005E0_chfactorysparkroom(rdram, ctx);
        goto after_31;
    // 0x808004E8: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    after_31:
    // 0x808004EC: b           L_808005AC
    // 0x808004F0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_808005AC;
    // 0x808004F0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_808004F4:
    // 0x808004F4: jal         0x800D90A4
    // 0x808004F8: addiu       $a0, $s3, 0x54
    ctx->r4 = ADD32(ctx->r19, 0X54);
    func_800D90A4(rdram, ctx);
        goto after_32;
    // 0x808004F8: addiu       $a0, $s3, 0x54
    ctx->r4 = ADD32(ctx->r19, 0X54);
    after_32:
    // 0x808004FC: beq         $v0, $zero, L_8080051C
    if (ctx->r2 == 0) {
        // 0x80800500: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8080051C;
    }
    // 0x80800500: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800504: jal         0x808007E0
    // 0x80800508: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808007E0_chfactorysparkroom(rdram, ctx);
        goto after_33;
    // 0x80800508: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_33:
    // 0x8080050C: jal         0x80089D40
    // 0x80800510: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_34;
    // 0x80800510: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_34:
    // 0x80800514: b           L_808005AC
    // 0x80800518: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_808005AC;
    // 0x80800518: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8080051C:
    // 0x8080051C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2372, 0X1070) << 16);
    // 0x80800520: addiu       $a3, $a3, 0x1070
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2372, 0X1070));
    // 0x80800524: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    // 0x80800528: jal         0x80089D50
    // 0x8080052C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_35;
    // 0x8080052C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_35:
    // 0x80800530: lhu         $t7, 0x76($s3)
    ctx->r15 = MEM_HU(ctx->r19, 0X76);
    // 0x80800534: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800538: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8080053C: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x80800540: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80800544: lwc1        $f12, 0x54($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X54);
    // 0x80800548: bgez        $t8, L_80800560
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8080054C: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80800560;
    }
    // 0x8080054C: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800550: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800554: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800558: nop

    // 0x8080055C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_80800560:
    // 0x80800560: div.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80800564: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2372, 0X1040) << 16);
    // 0x80800568: lwc1        $f8, 0x1040($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2372, 0X1040));
    // 0x8080056C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800570: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800574: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80800578: nop

    // 0x8080057C: bc1fl       L_808005AC
    if (!c1cs) {
        // 0x80800580: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_808005AC;
    }
    goto skip_7;
    // 0x80800580: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_7:
    // 0x80800584: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800588: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080058C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800590: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    // 0x80800594: jal         0x800F10B4
    // 0x80800598: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_36;
    // 0x80800598: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_36:
    // 0x8080059C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005A0: jal         0x808006D0
    // 0x808005A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_808006D0_chfactorysparkroom(rdram, ctx);
        goto after_37;
    // 0x808005A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_37:
    // 0x808005A8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_808005AC:
    // 0x808005AC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808005B0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808005B4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808005B8: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x808005BC: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x808005C0: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x808005C4: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x808005C8: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x808005CC: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x808005D0: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x808005D4: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x808005D8: jr          $ra
    // 0x808005DC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x808005DC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_800BBCB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BBCB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BBCBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BBCC0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800BBCC4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800BBCC8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800BBCCC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800BBCD0: jal         0x800B53A4
    // 0x800BBCD4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x800BBCD4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800BBCD8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800BBCDC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800BBCE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800BBCE4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800BBCE8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800BBCEC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800BBCF0: jal         0x800BABB8
    // 0x800BBCF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x800BBCF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x800BBCF8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800BBCFC: jal         0x800BA22C
    // 0x800BBD00: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800BA22C(rdram, ctx);
        goto after_2;
    // 0x800BBD00: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x800BBD04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BBD08: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800BBD0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BBD10: jr          $ra
    // 0x800BBD14: nop

    return;
    // 0x800BBD14: nop

;}
RECOMP_FUNC void func_80800050_chflamer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800050: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80800054: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800058: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8080005C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80800060: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800064: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800068: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8080006C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800070: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800074: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800078: jal         0x80100094
    // 0x8080007C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080007C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800080: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800084: jal         0x8008A040
    // 0x80800088: addiu       $a0, $v0, 0x1B4
    ctx->r4 = ADD32(ctx->r2, 0X1B4);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800088: addiu       $a0, $v0, 0x1B4
    ctx->r4 = ADD32(ctx->r2, 0X1B4);
    after_1:
    // 0x8080008C: beq         $v0, $zero, L_808000DC
    if (ctx->r2 == 0) {
        // 0x80800090: sw          $v0, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r2;
            goto L_808000DC;
    }
    // 0x80800090: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80800094: jal         0x801072A8
    // 0x80800098: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_801072A8(rdram, ctx);
        goto after_2;
    // 0x80800098: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8080009C: bne         $v0, $zero, L_808000DC
    if (ctx->r2 != 0) {
        // 0x808000A0: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_808000DC;
    }
    // 0x808000A0: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x808000A4: jal         0x80103F38
    // 0x808000A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103F38(rdram, ctx);
        goto after_3;
    // 0x808000A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808000AC: swc1        $f0, 0x1B0($s4)
    MEM_W(0X1B0, ctx->r20) = ctx->f0.u32l;
    // 0x808000B0: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x808000B4: addiu       $a0, $s6, 0x4
    ctx->r4 = ADD32(ctx->r22, 0X4);
    // 0x808000B8: jal         0x800EE7F8
    // 0x808000BC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808000BC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x808000C0: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x808000C4: addiu       $a0, $s6, 0x44
    ctx->r4 = ADD32(ctx->r22, 0X44);
    // 0x808000C8: jal         0x800EE7F8
    // 0x808000CC: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808000CC: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_5:
    // 0x808000D0: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x808000D4: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x808000D8: swc1        $f4, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->f4.u32l;
L_808000DC:
    // 0x808000DC: jal         0x8080098C
    // 0x808000E0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_8080098C_chflamer(rdram, ctx);
        goto after_6;
    // 0x808000E0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_6:
    // 0x808000E4: lhu         $v0, 0x72($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X72);
    // 0x808000E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000EC: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x808000F0: srl         $t7, $v0, 10
    ctx->r15 = S32(U32(ctx->r2) >> 10);
    // 0x808000F4: beq         $t7, $at, L_80800114
    if (ctx->r15 == ctx->r1) {
        // 0x808000F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800114;
    }
    // 0x808000F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000FC: beq         $t7, $at, L_80800170
    if (ctx->r15 == ctx->r1) {
        // 0x80800100: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800170;
    }
    // 0x80800100: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800104: beql        $t7, $at, L_808001B0
    if (ctx->r15 == ctx->r1) {
        // 0x80800108: lh          $t0, 0x18($s4)
        ctx->r8 = MEM_H(ctx->r20, 0X18);
            goto L_808001B0;
    }
    goto skip_0;
    // 0x80800108: lh          $t0, 0x18($s4)
    ctx->r8 = MEM_H(ctx->r20, 0X18);
    skip_0:
    // 0x8080010C: b           L_80800208
    // 0x80800110: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
        goto L_80800208;
    // 0x80800110: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80800114:
    // 0x80800114: beq         $t8, $zero, L_8080012C
    if (ctx->r24 == 0) {
        // 0x80800118: nop
    
            goto L_8080012C;
    }
    // 0x80800118: nop

    // 0x8080011C: lbu         $t9, 0x74($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X74);
    // 0x80800120: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80800124: bnel        $t0, $zero, L_8080013C
    if (ctx->r8 != 0) {
        // 0x80800128: lh          $t1, 0x18($s4)
        ctx->r9 = MEM_H(ctx->r20, 0X18);
            goto L_8080013C;
    }
    goto skip_1;
    // 0x80800128: lh          $t1, 0x18($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X18);
    skip_1:
L_8080012C:
    // 0x8080012C: jal         0x80800738
    // 0x80800130: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80800738_chflamer(rdram, ctx);
        goto after_7;
    // 0x80800130: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_7:
    // 0x80800134: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80800138: lh          $t1, 0x18($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X18);
L_8080013C:
    // 0x8080013C: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80800140: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x80800144: sh          $t2, 0x18($s4)
    MEM_H(0X18, ctx->r20) = ctx->r10;
    // 0x80800148: lh          $t3, 0x18($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X18);
    // 0x8080014C: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x80800150: bnel        $at, $zero, L_80800208
    if (ctx->r1 != 0) {
        // 0x80800154: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80800208;
    }
    goto skip_2;
    // 0x80800154: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_2:
    // 0x80800158: sh          $t4, 0x18($s4)
    MEM_H(0X18, ctx->r20) = ctx->r12;
    // 0x8080015C: lbu         $t5, 0x72($s6)
    ctx->r13 = MEM_BU(ctx->r22, 0X72);
    // 0x80800160: andi        $t6, $t5, 0xFF03
    ctx->r14 = ctx->r13 & 0XFF03;
    // 0x80800164: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80800168: b           L_80800204
    // 0x8080016C: sb          $t7, 0x72($s6)
    MEM_B(0X72, ctx->r22) = ctx->r15;
        goto L_80800204;
    // 0x8080016C: sb          $t7, 0x72($s6)
    MEM_B(0X72, ctx->r22) = ctx->r15;
L_80800170:
    // 0x80800170: jal         0x800D9078
    // 0x80800174: addiu       $a0, $s6, 0x58
    ctx->r4 = ADD32(ctx->r22, 0X58);
    func_800D9078(rdram, ctx);
        goto after_8;
    // 0x80800174: addiu       $a0, $s6, 0x58
    ctx->r4 = ADD32(ctx->r22, 0X58);
    after_8:
    // 0x80800178: bne         $v0, $zero, L_8080019C
    if (ctx->r2 != 0) {
        // 0x8080017C: nop
    
            goto L_8080019C;
    }
    // 0x8080017C: nop

    // 0x80800180: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x80800184: beq         $v0, $zero, L_8080019C
    if (ctx->r2 == 0) {
        // 0x80800188: nop
    
            goto L_8080019C;
    }
    // 0x80800188: nop

    // 0x8080018C: lbu         $t8, 0x74($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X74);
    // 0x80800190: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80800194: bnel        $t9, $zero, L_80800208
    if (ctx->r25 != 0) {
        // 0x80800198: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80800208;
    }
    goto skip_3;
    // 0x80800198: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_3:
L_8080019C:
    // 0x8080019C: jal         0x80800738
    // 0x808001A0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80800738_chflamer(rdram, ctx);
        goto after_9;
    // 0x808001A0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_9:
    // 0x808001A4: b           L_80800204
    // 0x808001A8: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
        goto L_80800204;
    // 0x808001A8: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x808001AC: lh          $t0, 0x18($s4)
    ctx->r8 = MEM_H(ctx->r20, 0X18);
L_808001B0:
    // 0x808001B0: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x808001B4: sh          $t1, 0x18($s4)
    MEM_H(0X18, ctx->r20) = ctx->r9;
    // 0x808001B8: lh          $t2, 0x18($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X18);
    // 0x808001BC: bgtzl       $t2, L_80800208
    if (SIGNED(ctx->r10) > 0) {
        // 0x808001C0: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80800208;
    }
    goto skip_4;
    // 0x808001C0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_4:
    // 0x808001C4: lh          $t3, 0x16($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X16);
    // 0x808001C8: sh          $zero, 0x18($s4)
    MEM_H(0X18, ctx->r20) = 0;
    // 0x808001CC: bnel        $t3, $zero, L_80800208
    if (ctx->r11 != 0) {
        // 0x808001D0: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80800208;
    }
    goto skip_5;
    // 0x808001D0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_5:
    // 0x808001D4: jal         0x800BF8E4
    // 0x808001D8: nop

    func_800BF8E4(rdram, ctx);
        goto after_10;
    // 0x808001D8: nop

    after_10:
    // 0x808001DC: blez        $v0, L_808001F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808001E0: lui         $a1, 0x3F80
        ctx->r5 = S32(0X3F80 << 16);
            goto L_808001F4;
    }
    // 0x808001E0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808001E4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x808001E8: jal         0x800863E8
    // 0x808001EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chlightfader_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x808001EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_11:
    // 0x808001F0: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
L_808001F4:
    // 0x808001F4: jal         0x800FFA88
    // 0x808001F8: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_12;
    // 0x808001F8: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_12:
    // 0x808001FC: b           L_80800410
    // 0x80800200: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80800410;
    // 0x80800200: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800204:
    // 0x80800204: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80800208:
    // 0x80800208: jal         0x808007A8
    // 0x8080020C: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    func_808007A8_chflamer(rdram, ctx);
        goto after_13;
    // 0x8080020C: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_13:
    // 0x80800210: beq         $v0, $zero, L_808003F4
    if (ctx->r2 == 0) {
        // 0x80800214: nop
    
            goto L_808003F4;
    }
    // 0x80800214: nop

    // 0x80800218: jal         0x800D8FF8
    // 0x8080021C: nop

    func_800D8FF8(rdram, ctx);
        goto after_14;
    // 0x8080021C: nop

    after_14:
    // 0x80800220: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800224: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800228: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080022C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800230: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800234: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x80800238: addiu       $s0, $s4, 0x1C
    ctx->r16 = ADD32(ctx->r20, 0X1C);
    // 0x8080023C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800240: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80800244: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80800248: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8080024C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x80800250: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x80800254: lh          $t4, 0x16($s4)
    ctx->r12 = MEM_H(ctx->r20, 0X16);
    // 0x80800258: blez        $t4, L_808003F4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8080025C: nop
    
            goto L_808003F4;
    }
    // 0x8080025C: nop

    // 0x80800260: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800264: addiu       $s5, $sp, 0x44
    ctx->r21 = ADD32(ctx->r29, 0X44);
    // 0x80800268: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x8080026C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80800270: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80800274: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
L_80800278:
    // 0x80800278: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080027C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800280: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x80800284: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800288: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8080028C: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80800290: nop

    // 0x80800294: slti        $at, $t6, 0x9
    ctx->r1 = SIGNED(ctx->r14) < 0X9 ? 1 : 0;
    // 0x80800298: bnel        $at, $zero, L_808002E0
    if (ctx->r1 != 0) {
        // 0x8080029C: lh          $t0, 0x4($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X4);
            goto L_808002E0;
    }
    goto skip_6;
    // 0x8080029C: lh          $t0, 0x4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4);
    skip_6:
    // 0x808002A0: lh          $t7, 0x16($s4)
    ctx->r15 = MEM_H(ctx->r20, 0X16);
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x808002AC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x808002B0: sh          $t8, 0x16($s4)
    MEM_H(0X16, ctx->r20) = ctx->r24;
    // 0x808002B4: lh          $s1, 0x16($s4)
    ctx->r17 = MEM_H(ctx->r20, 0X16);
    // 0x808002B8: blez        $s1, L_808003E8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x808002BC: sll         $t9, $s1, 2
        ctx->r25 = S32(ctx->r17 << 2);
            goto L_808003E8;
    }
    // 0x808002BC: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x808002C0: addu        $t9, $t9, $s1
    ctx->r25 = ADD32(ctx->r25, ctx->r17);
    // 0x808002C4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808002C8: addu        $a1, $s4, $t9
    ctx->r5 = ADD32(ctx->r20, ctx->r25);
    // 0x808002CC: jal         0x8001BBA0
    // 0x808002D0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    rare_memcpy(rdram, ctx);
        goto after_15;
    // 0x808002D0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_15:
    // 0x808002D4: b           L_808003E8
    // 0x808002D8: lh          $s1, 0x16($s4)
    ctx->r17 = MEM_H(ctx->r20, 0X16);
        goto L_808003E8;
    // 0x808002D8: lh          $s1, 0x16($s4)
    ctx->r17 = MEM_H(ctx->r20, 0X16);
    // 0x808002DC: lh          $t0, 0x4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4);
L_808002E0:
    // 0x808002E0: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808002E4: lh          $t4, 0xA($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XA);
    // 0x808002E8: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x808002EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808002F0: addiu       $a1, $s0, 0x8
    ctx->r5 = ADD32(ctx->r16, 0X8);
    // 0x808002F4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x808002F8: addiu       $s1, $s6, 0x4
    ctx->r17 = ADD32(ctx->r22, 0X4);
    // 0x808002FC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800300: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800304: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80800308: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8080030C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800310: sh          $t2, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r10;
    // 0x80800314: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x80800318: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8080031C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80800320: nop

    // 0x80800324: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800328: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8080032C: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80800330: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800334: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80800338: jal         0x800EE88C
    // 0x8080033C: sh          $t6, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r14;
    func_800EE88C(rdram, ctx);
        goto after_16;
    // 0x8080033C: sh          $t6, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r14;
    after_16:
    // 0x80800340: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800344: jal         0x800EF04C
    // 0x80800348: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_17;
    // 0x80800348: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_17:
    // 0x8080034C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800350: jal         0x800EFC7C
    // 0x80800354: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_18;
    // 0x80800354: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_18:
    // 0x80800358: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x8080035C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800360: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800364: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800368: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8080036C: nop

    // 0x80800370: bc1fl       L_808003E0
    if (!c1cs) {
        // 0x80800374: lh          $s1, 0x16($s4)
        ctx->r17 = MEM_H(ctx->r20, 0X16);
            goto L_808003E0;
    }
    goto skip_7;
    // 0x80800374: lh          $s1, 0x16($s4)
    ctx->r17 = MEM_H(ctx->r20, 0X16);
    skip_7:
    // 0x80800378: jal         0x800EFB24
    // 0x8080037C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800EFB24(rdram, ctx);
        goto after_19;
    // 0x8080037C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_19:
    // 0x80800380: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800384: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800388: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8080038C: jal         0x800EF368
    // 0x80800390: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    func_800EF368(rdram, ctx);
        goto after_20;
    // 0x80800390: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    after_20:
    // 0x80800394: lh          $t7, 0x8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8);
    // 0x80800398: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080039C: lh          $t0, 0xC($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XC);
    // 0x808003A0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x808003A4: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x808003A8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808003AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808003B0: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x808003B4: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808003B8: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x808003BC: nop

    // 0x808003C0: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
    // 0x808003C4: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808003C8: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x808003CC: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808003D0: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x808003D4: nop

    // 0x808003D8: sh          $t2, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r10;
    // 0x808003DC: lh          $s1, 0x16($s4)
    ctx->r17 = MEM_H(ctx->r20, 0X16);
L_808003E0:
    // 0x808003E0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x808003E4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_808003E8:
    // 0x808003E8: slt         $at, $s3, $s1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x808003EC: bnel        $at, $zero, L_80800278
    if (ctx->r1 != 0) {
        // 0x808003F0: lwc1        $f8, 0x0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
            goto L_80800278;
    }
    goto skip_8;
    // 0x808003F0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    skip_8:
L_808003F4:
    // 0x808003F4: jal         0x800BF8E4
    // 0x808003F8: nop

    func_800BF8E4(rdram, ctx);
        goto after_21;
    // 0x808003F8: nop

    after_21:
    // 0x808003FC: blez        $v0, L_8080040C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800400: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_8080040C;
    }
    // 0x80800400: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800404: jal         0x808009C0
    // 0x80800408: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    func_808009C0_chflamer(rdram, ctx);
        goto after_22;
    // 0x80800408: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    after_22:
L_8080040C:
    // 0x8080040C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800410:
    // 0x80800410: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800414: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800418: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080041C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800420: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800424: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800428: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8080042C: jr          $ra
    // 0x80800430: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80800430: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80091E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091E48: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x80091E4C: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x80091E50: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80091E54: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
    // 0x80091E58: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x80091E5C: lbu         $t8, 0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3);
    // 0x80091E60: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80091E64: jr          $ra
    // 0x80091E68: sb          $t9, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r25;
    return;
    // 0x80091E68: sb          $t9, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void bsrest_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808006EC: jal         0x8009BF5C
    // 0x808006F0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_0;
    // 0x808006F0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x808006F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006F8: jal         0x8009C4CC
    // 0x808006FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_1;
    // 0x808006FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800700: jal         0x8080003C
    // 0x80800704: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    static_344_8080003C(rdram, ctx);
        goto after_2;
    // 0x80800704: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080070C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800710: jr          $ra
    // 0x80800714: nop

    return;
    // 0x80800714: nop

;}
RECOMP_FUNC void boot_send_mesg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8008E1C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E1C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008E1C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E1CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008E1D0: jal         0x8009659C
    // 0x8008E1D4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8009659C(rdram, ctx);
        goto after_0;
    // 0x8008E1D4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x8008E1D8: sltu        $a2, $zero, $v0
    ctx->r6 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008E1DC: beq         $a2, $zero, L_8008E1F0
    if (ctx->r6 == 0) {
        // 0x8008E1E0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8008E1F0;
    }
    // 0x8008E1E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008E1E4: jal         0x80095748
    // 0x8008E1E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_isFalse(rdram, ctx);
        goto after_1;
    // 0x8008E1E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8008E1EC: sltu        $a2, $zero, $v0
    ctx->r6 = 0 < ctx->r2 ? 1 : 0;
L_8008E1F0:
    // 0x8008E1F0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8008E1F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008E1F8: jal         0x8009659C
    // 0x8008E1FC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_8009659C(rdram, ctx);
        goto after_2;
    // 0x8008E1FC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_2:
    // 0x8008E200: beq         $v0, $zero, L_8008E210
    if (ctx->r2 == 0) {
        // 0x8008E204: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8008E210;
    }
    // 0x8008E204: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8008E208: jal         0x80095748
    // 0x8008E20C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    baflag_isFalse(rdram, ctx);
        goto after_3;
    // 0x8008E20C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
L_8008E210:
    // 0x8008E210: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E214: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008E218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E21C: bne         $t6, $zero, L_8008E22C
    if (ctx->r14 != 0) {
        // 0x8008E220: nop
    
            goto L_8008E22C;
    }
    // 0x8008E220: nop

    // 0x8008E224: beq         $t7, $zero, L_8008E234
    if (ctx->r15 == 0) {
        // 0x8008E228: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8008E234;
    }
    // 0x8008E228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008E22C:
    // 0x8008E22C: b           L_8008E234
    // 0x8008E230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008E234;
    // 0x8008E230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008E234:
    // 0x8008E234: jr          $ra
    // 0x8008E238: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8008E238: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800CA704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA704: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA708: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CA70C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA710: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CA714: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800CA718: jal         0x800EFB24
    // 0x800CA71C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800CA71C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800CA720: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800CA724: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800CA728: jal         0x800EEAA4
    // 0x800CA72C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EEAA4(rdram, ctx);
        goto after_1;
    // 0x800CA72C: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_1:
    // 0x800CA730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA734: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA738: jr          $ra
    // 0x800CA73C: nop

    return;
    // 0x800CA73C: nop

;}
RECOMP_FUNC void _subaddiefade_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C90: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089C90);
    return;
    // 0x80089C94: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
