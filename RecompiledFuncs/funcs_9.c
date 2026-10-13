#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080005C_chfireimp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080005C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800064: jal         0x80089EE8
    // 0x80800068: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    _sucoasterfly_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800068: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080006C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800070: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800074: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80800078: jal         0x80089ED8
    // 0x8080007C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _sucoasterfly_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x8080007C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800080: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800084: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800088: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x8080008C: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800090: addiu       $t9, $t8, -0xA
    ctx->r25 = ADD32(ctx->r24, -0XA);
    // 0x80800094: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x80800098: beq         $at, $zero, L_808000B8
    if (ctx->r1 == 0) {
        // 0x8080009C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808000B8;
    }
    // 0x8080009C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808000A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1348, 0X144) << 16);
    // 0x808000A4: addu        $at, $at, $t9
    gpr jr_addend_808000AC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808000A8: lw          $t9, 0x144($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1348, 0X144));
    // 0x808000AC: jr          $t9
    // 0x808000B0: nop

    switch (jr_addend_808000AC >> 2) {
        case 0: goto L_808000B4; break;
        case 1: goto L_808000B4; break;
        case 2: goto L_808000B4; break;
        case 3: goto L_808000B4; break;
        case 4: goto L_808000B4; break;
        case 5: goto L_808000B4; break;
        case 6: goto L_808000B4; break;
        default: switch_error(__func__, 0x808000AC, 0x80800144);
    }
    // 0x808000B0: nop

L_808000B4:
    // 0x808000B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808000B8:
    // 0x808000B8: beql        $v1, $zero, L_80800128
    if (ctx->r3 == 0) {
        // 0x808000BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800128;
    }
    goto skip_0;
    // 0x808000BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000C0: jal         0x800D90A4
    // 0x808000C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800D90A4(rdram, ctx);
        goto after_2;
    // 0x808000C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x808000C8: beql        $v0, $zero, L_80800128
    if (ctx->r2 == 0) {
        // 0x808000CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800128;
    }
    goto skip_1;
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808000D0: jal         0x8010D640
    // 0x808000D4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D640(rdram, ctx);
        goto after_3;
    // 0x808000D4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x808000D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808000DC: lui         $a1, 0x44E1
    ctx->r5 = S32(0X44E1 << 16);
    // 0x808000E0: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x808000E4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808000E8: jal         0x800EFFB4
    // 0x808000EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EFFB4(rdram, ctx);
        goto after_4;
    // 0x808000EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_4:
    // 0x808000F0: beq         $v0, $zero, L_80800124
    if (ctx->r2 == 0) {
        // 0x808000F4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1348, 0X160) << 16);
            goto L_80800124;
    }
    // 0x808000F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1348, 0X160) << 16);
    // 0x808000F8: lwc1        $f12, 0x160($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1348, 0X160));
    // 0x808000FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1348, 0X164) << 16);
    // 0x80800100: jal         0x800DC178
    // 0x80800104: lwc1        $f14, 0x164($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1348, 0X164));
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800104: lwc1        $f14, 0x164($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1348, 0X164));
    after_5:
    // 0x80800108: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8080010C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1348, 0X240) << 16);
    // 0x80800110: addiu       $a2, $a2, 0x240
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1348, 0X240));
    // 0x80800114: swc1        $f0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f0.u32l;
    // 0x80800118: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8080011C: jal         0x80089D18
    // 0x80800120: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800120: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
L_80800124:
    // 0x80800124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800128:
    // 0x80800128: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080012C: jr          $ra
    // 0x80800130: nop

    return;
    // 0x80800130: nop

    // 0x80800134: nop

    // 0x80800138: nop

    // 0x8080013C: nop

;}
RECOMP_FUNC void func_8010F950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F950: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010F954: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010F958: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010F95C: addiu       $v0, $v0, 0x7240
    ctx->r2 = ADD32(ctx->r2, 0X7240);
    // 0x8010F960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010F964: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8010F968: addiu       $t6, $t6, 0x7250
    ctx->r14 = ADD32(ctx->r14, 0X7250);
    // 0x8010F96C: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8010F970: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8010F974: jal         0x8010F384
    // 0x8010F978: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_8010F384(rdram, ctx);
        goto after_0;
    // 0x8010F978: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x8010F97C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010F980: jal         0x800DF8B4
    // 0x8010F984: lw          $a0, 0x7240($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7240);
    func_800DF8B4(rdram, ctx);
        goto after_1;
    // 0x8010F984: lw          $a0, 0x7240($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7240);
    after_1:
    // 0x8010F988: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010F98C: lw          $a0, 0x7240($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7240);
    // 0x8010F990: jal         0x800DF8BC
    // 0x8010F994: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800DF8BC(rdram, ctx);
        goto after_2;
    // 0x8010F994: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x8010F998: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010F99C: jal         0x8010F68C
    // 0x8010F9A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010F68C(rdram, ctx);
        goto after_3;
    // 0x8010F9A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8010F9A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010F9A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010F9AC: jr          $ra
    // 0x8010F9B0: nop

    return;
    // 0x8010F9B0: nop

    // 0x8010F9B4: nop

    // 0x8010F9B8: nop

    // 0x8010F9BC: nop

;}
RECOMP_FUNC void _baduo_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084980: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x80084980);
    return;
    // 0x80084984: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void func_800F0FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F0FC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0FCC: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800F0FD0: jal         0x800F13C4
    // 0x800F0FD4: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    func_800F13C4(rdram, ctx);
        goto after_0;
    // 0x800F0FD4: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x800F0FD8: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800F0FDC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800F0FE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800F0FE4: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800F0FE8: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800F0FEC: jal         0x80013970
    // 0x800F0FF0: nop

    func_80013970(rdram, ctx);
        goto after_1;
    // 0x800F0FF0: nop

    after_1:
    // 0x800F0FF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F0FF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800F0FFC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800F1000: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800F1004: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800F1008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F100C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F1010: mul.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800F1014: jr          $ra
    // 0x800F1018: nop

    return;
    // 0x800F1018: nop

;}
RECOMP_FUNC void func_80800000_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x80800014: jal         0x800D0B68
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080001C: beql        $v0, $zero, L_80800038
    if (ctx->r2 == 0) {
        // 0x80800020: lhu         $t6, 0x76($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0X76);
            goto L_80800038;
    }
    goto skip_0;
    // 0x80800020: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    skip_0:
    // 0x80800024: jal         0x800FFAB0
    // 0x80800028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080002C: b           L_808000C8
    // 0x80800030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000C8;
    // 0x80800030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800034: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
L_80800038:
    // 0x80800038: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x8080003C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800040: addiu       $t8, $t7, -0x32
    ctx->r24 = ADD32(ctx->r15, -0X32);
    // 0x80800044: bnel        $t8, $zero, L_80800070
    if (ctx->r24 != 0) {
        // 0x80800048: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_80800070;
    }
    goto skip_1;
    // 0x80800048: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_1:
    // 0x8080004C: jal         0x800D0B68
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80800050: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800054: bnel        $v0, $zero, L_80800070
    if (ctx->r2 != 0) {
        // 0x80800058: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_80800070;
    }
    goto skip_2;
    // 0x80800058: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_2:
    // 0x8080005C: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800060: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80800064: b           L_80800078
    // 0x80800068: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
        goto L_80800078;
    // 0x80800068: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x8080006C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
L_80800070:
    // 0x80800070: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x80800074: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80800078:
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: addiu       $a1, $s0, 0x20
    ctx->r5 = ADD32(ctx->r16, 0X20);
    // 0x80800080: jal         0x808010B0
    // 0x80800084: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    func_808010B0_chfantasyeyeball(rdram, ctx);
        goto after_3;
    // 0x80800084: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    after_3:
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800090: jal         0x808010B0
    // 0x80800094: addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    func_808010B0_chfantasyeyeball(rdram, ctx);
        goto after_4;
    // 0x80800094: addiu       $a2, $s0, 0x1C
    ctx->r6 = ADD32(ctx->r16, 0X1C);
    after_4:
    // 0x80800098: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000A4: andi        $t5, $t4, 0xFFF7
    ctx->r13 = ctx->r12 & 0XFFF7;
    // 0x808000A8: jal         0x80100094
    // 0x808000AC: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x808000AC: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    after_5:
    // 0x808000B0: jal         0x8008A020
    // 0x808000B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x808000B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x808000B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000BC: nop

    // 0x808000C0: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
    // 0x808000C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000C8:
    // 0x808000C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000D0: jr          $ra
    // 0x808000D4: nop

    return;
    // 0x808000D4: nop

;}
RECOMP_FUNC void func_800DC2D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC2D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC2D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC2DC: jal         0x800DC1AC
    // 0x800DC2E0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_800DC1AC(rdram, ctx);
        goto after_0;
    // 0x800DC2E0: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800DC2E4: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800DC2E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC2EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC2F0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800DC2F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800DC2F8: bc1f        L_800DC308
    if (!c1cs) {
        // 0x800DC2FC: nop
    
            goto L_800DC308;
    }
    // 0x800DC2FC: nop

    // 0x800DC300: b           L_800DC308
    // 0x800DC304: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800DC308;
    // 0x800DC304: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800DC308:
    // 0x800DC308: jr          $ra
    // 0x800DC30C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800DC30C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800E3928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E392C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800E3930: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E3934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E3938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E393C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3940: jal         0x800CA704
    // 0x800E3944: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA704(rdram, ctx);
        goto after_0;
    // 0x800E3944: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E394C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3950: jr          $ra
    // 0x800E3954: nop

    return;
    // 0x800E3954: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_49(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087E20: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087E20);
    return;
    // 0x80087E24: addi        $t0, $zero, 0xC4
    ctx->r8 = ADD32(0, 0XC4);
;}
RECOMP_FUNC void _bstalk_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083DA8: syscall     95
    recomp_syscall_handler(rdram, ctx, 0x80083DA8);
    return;
    // 0x80083DAC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8008F7B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F7B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008F7B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F7BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008F7C0: jal         0x80084D40
    // 0x8008F7C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _bahold_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x8008F7C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8008F7C8: beq         $v0, $zero, L_8008F7E0
    if (ctx->r2 == 0) {
        // 0x8008F7CC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8008F7E0;
    }
    // 0x8008F7CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008F7D0: jal         0x80106790
    // 0x8008F7D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x8008F7D4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8008F7D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8008F7DC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_8008F7E0:
    // 0x8008F7E0: beq         $a0, $zero, L_8008F808
    if (ctx->r4 == 0) {
        // 0x8008F7E4: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_8008F808;
    }
    // 0x8008F7E4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8008F7E8: lw          $t8, 0x6C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X6C);
    // 0x8008F7EC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8008F7F0: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x8008F7F4: srl         $t0, $t9, 20
    ctx->r8 = S32(U32(ctx->r25) >> 20);
    // 0x8008F7F8: bne         $t6, $t0, L_8008F808
    if (ctx->r14 != ctx->r8) {
        // 0x8008F7FC: nop
    
            goto L_8008F808;
    }
    // 0x8008F7FC: nop

    // 0x8008F800: jal         0x80084D38
    // 0x8008F804: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bahold_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x8008F804: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
L_8008F808:
    // 0x8008F808: jal         0x800D1B34
    // 0x8008F80C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800D1B34(rdram, ctx);
        goto after_3;
    // 0x8008F80C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x8008F810: jal         0x800D1804
    // 0x8008F814: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D1804(rdram, ctx);
        goto after_4;
    // 0x8008F814: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8008F818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F81C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008F820: jr          $ra
    // 0x8008F824: nop

    return;
    // 0x8008F824: nop

;}
RECOMP_FUNC void func_80096260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80096264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096268: jal         0x80096628
    // 0x8009626C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80096628(rdram, ctx);
        goto after_0;
    // 0x8009626C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80096270: jal         0x800C84B0
    // 0x80096274: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C84B0(rdram, ctx);
        goto after_1;
    // 0x80096274: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80096278: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8009627C: bne         $v0, $at, L_80096298
    if (ctx->r2 != ctx->r1) {
        // 0x80096280: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80096298;
    }
    // 0x80096280: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80096284: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80096288: jal         0x80096254
    // 0x8009628C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80096254(rdram, ctx);
        goto after_2;
    // 0x8009628C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80096290: b           L_800962A4
    // 0x80096294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800962A4;
    // 0x80096294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80096298:
    // 0x80096298: jal         0x80096254
    // 0x8009629C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80096254(rdram, ctx);
        goto after_3;
    // 0x8009629C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x800962A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800962A4:
    // 0x800962A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800962A8: jr          $ra
    // 0x800962AC: nop

    return;
    // 0x800962AC: nop

;}
RECOMP_FUNC void badrone_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800070: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80800074: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800078: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080007C: sb          $zero, 0x4($t6)
    MEM_B(0X4, ctx->r14) = 0;
    // 0x80800080: lw          $t8, 0x54($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X54);
    // 0x80800084: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800088: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080008C: sb          $t7, 0x5($t8)
    MEM_B(0X5, ctx->r24) = ctx->r15;
    // 0x80800090: lw          $t9, 0x54($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X54);
    // 0x80800094: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x80800098: lw          $a0, 0x54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X54);
    // 0x8080009C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x808000A0: jal         0x800EFD24
    // 0x808000A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x808000A4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x808000A8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808000AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000B4: lw          $t0, 0x54($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X54);
    // 0x808000B8: swc1        $f6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f6.u32l;
    // 0x808000BC: lw          $t1, 0x54($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X54);
    // 0x808000C0: sw          $zero, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = 0;
    // 0x808000C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void func_800E9804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9804: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800E9808: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E980C: addiu       $a0, $a0, 0x2DB4
    ctx->r4 = ADD32(ctx->r4, 0X2DB4);
    // 0x800E9810: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800E9814: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E9818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E981C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800E9820: lh          $t7, 0x4($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X4);
    // 0x800E9824: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800E9828: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x800E982C: jal         0x800B3CDC
    // 0x800E9830: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_800B3CDC(rdram, ctx);
        goto after_0;
    // 0x800E9830: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x800E9834: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800E9838: lbu         $t8, 0xB($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XB);
    // 0x800E983C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800E9840: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800E9844: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x800E9848: sb          $t9, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r25;
    // 0x800E984C: lw          $t1, 0x2DB4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2DB4);
    // 0x800E9850: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800E9854: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800E9858: beql        $t0, $t1, L_800E9874
    if (ctx->r8 == ctx->r9) {
        // 0x800E985C: lh          $t3, 0x4($a2)
        ctx->r11 = MEM_H(ctx->r6, 0X4);
            goto L_800E9874;
    }
    goto skip_0;
    // 0x800E985C: lh          $t3, 0x4($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X4);
    skip_0:
    // 0x800E9860: jal         0x800BE4C4
    // 0x800E9864: nop

    func_800BE4C4(rdram, ctx);
        goto after_1;
    // 0x800E9864: nop

    after_1:
    // 0x800E9868: b           L_800E9888
    // 0x800E986C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800E9888;
    // 0x800E986C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9870: lh          $t3, 0x4($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X4);
L_800E9874:
    // 0x800E9874: beql        $t2, $t3, L_800E9888
    if (ctx->r10 == ctx->r11) {
        // 0x800E9878: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E9888;
    }
    goto skip_1;
    // 0x800E9878: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800E987C: jal         0x800E9CF4
    // 0x800E9880: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800E9CF4(rdram, ctx);
        goto after_2;
    // 0x800E9880: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x800E9884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E9888:
    // 0x800E9888: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x800E988C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E9890: jr          $ra
    // 0x800E9894: nop

    return;
    // 0x800E9894: nop

;}
RECOMP_FUNC void func_80800C58_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800C5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C68: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80800C6C: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x80800C70: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800C74: jal         0x800EEC30
    // 0x80800C78: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    func_800EEC30(rdram, ctx);
        goto after_0;
    // 0x80800C78: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_0:
    // 0x80800C7C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800C80: jal         0x800EF04C
    // 0x80800C84: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_1;
    // 0x80800C84: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800C88: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800C8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800C90: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800C94: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800C98: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800C9C: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80800CA0: nop

    // 0x80800CA4: bc1fl       L_80800CB8
    if (!c1cs) {
        // 0x80800CA8: lw          $v0, 0x70($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X70);
            goto L_80800CB8;
    }
    goto skip_0;
    // 0x80800CA8: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    skip_0:
    // 0x80800CAC: b           L_80800D04
    // 0x80800CB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D04;
    // 0x80800CB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800CB4: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
L_80800CB8:
    // 0x80800CB8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800CBC: sll         $a2, $v0, 22
    ctx->r6 = S32(ctx->r2 << 22);
    // 0x80800CC0: srl         $t6, $a2, 26
    ctx->r14 = S32(U32(ctx->r6) >> 26);
    // 0x80800CC4: srl         $a1, $v0, 25
    ctx->r5 = S32(U32(ctx->r2) >> 25);
    // 0x80800CC8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80800CCC: jal         0x800CC338
    // 0x80800CD0: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    func_800CC338(rdram, ctx);
        goto after_2;
    // 0x80800CD0: addiu       $a2, $t6, -0x1
    ctx->r6 = ADD32(ctx->r14, -0X1);
    after_2:
    // 0x80800CD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800CD8: beq         $v0, $at, L_80800D00
    if (ctx->r2 == ctx->r1) {
        // 0x80800CDC: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_80800D00;
    }
    // 0x80800CDC: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80800CE0: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x80800CE4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800CE8: andi        $t0, $t9, 0x3F0
    ctx->r8 = ctx->r25 & 0X3F0;
    // 0x80800CEC: andi        $t2, $t1, 0xFC0F
    ctx->r10 = ctx->r9 & 0XFC0F;
    // 0x80800CF0: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80800CF4: sh          $t3, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r11;
    // 0x80800CF8: b           L_80800D04
    // 0x80800CFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D04;
    // 0x80800CFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D00:
    // 0x80800D00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D04:
    // 0x80800D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800D0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800D10: jr          $ra
    // 0x80800D14: nop

    return;
    // 0x80800D14: nop

;}
RECOMP_FUNC void ncbapivot_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8080009C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000A8: jal         0x8011607C
    // 0x808000AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8011607C(rdram, ctx);
        goto after_0;
    // 0x808000AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000B8: jal         0x80113978
    // 0x808000BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80113978(rdram, ctx);
        goto after_1;
    // 0x808000BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x80800008
    // 0x808000C8: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_80800008_ncbapivot(rdram, ctx);
        goto after_2;
    // 0x808000C8: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_2:
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x801107F0
    // 0x808000D4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_801107F0(rdram, ctx);
        goto after_3;
    // 0x808000D4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_3:
    // 0x808000D8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808000DC: jal         0x800EE7F8
    // 0x808000E0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808000E0: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_4:
    // 0x808000E4: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
    // 0x808000E8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x808000EC: beq         $t7, $zero, L_80800108
    if (ctx->r15 == 0) {
        // 0x808000F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800108;
    }
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808000F8: jal         0x80089468
    // 0x808000FC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    _ncbawaypoint_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x808000FC: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x80800100: b           L_80800114
    // 0x80800104: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
        goto L_80800114;
    // 0x80800104: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_80800108:
    // 0x80800108: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080010C: nop

    // 0x80800110: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
L_80800114:
    // 0x80800114: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800118: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8080011C: jal         0x800EFB24
    // 0x80800120: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x80800120: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x80800124: jal         0x800EEF94
    // 0x80800128: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    func_800EEF94(rdram, ctx);
        goto after_7;
    // 0x80800128: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_7:
    // 0x8080012C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800130: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800134: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800138: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8080013C: jal         0x800F1A88
    // 0x80800140: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    func_800F1A88(rdram, ctx);
        goto after_8;
    // 0x80800140: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x80115358
    // 0x8080014C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80115358(rdram, ctx);
        goto after_9;
    // 0x8080014C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_9:
    // 0x80800150: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800158: jal         0x80115750
    // 0x8080015C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80115750(rdram, ctx);
        goto after_10;
    // 0x8080015C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_10:
    // 0x80800160: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: jal         0x80112C3C
    // 0x8080016C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_80112C3C(rdram, ctx);
        goto after_11;
    // 0x8080016C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_11:
    // 0x80800170: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80800174: jal         0x801125E8
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801125E8(rdram, ctx);
        goto after_12;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080017C: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800180: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800184: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800188: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x8080018C: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80800190: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800194: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80800198: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8080019C: jal         0x800EEBF0
    // 0x808001A0: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    func_800EEBF0(rdram, ctx);
        goto after_13;
    // 0x808001A0: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x808001A4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x808001A8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808001AC: jal         0x800EE780
    // 0x808001B0: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    func_800EE780(rdram, ctx);
        goto after_14;
    // 0x808001B0: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    after_14:
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: jal         0x80111FD4
    // 0x808001BC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_80111FD4(rdram, ctx);
        goto after_15;
    // 0x808001BC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_15:
    // 0x808001C0: beql        $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x808001C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800234;
    }
    goto skip_0;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001C8: jal         0x801138A0
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138A0(rdram, ctx);
        goto after_16;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001D0: beq         $v0, $zero, L_808001F8
    if (ctx->r2 == 0) {
        // 0x808001D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F8;
    }
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: jal         0x801138F4
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_17;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808001E0: beql        $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x808001E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800234;
    }
    goto skip_1;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808001E8: jal         0x80110F44
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110F44(rdram, ctx);
        goto after_18;
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808001F0: b           L_80800234
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800234;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001F8:
    // 0x808001F8: jal         0x80115580
    // 0x808001FC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80115580(rdram, ctx);
        goto after_19;
    // 0x808001FC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_19:
    // 0x80800200: bne         $v0, $zero, L_80800218
    if (ctx->r2 != 0) {
        // 0x80800204: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800218;
    }
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: jal         0x80115580
    // 0x8080020C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    func_80115580(rdram, ctx);
        goto after_20;
    // 0x8080020C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    after_20:
    // 0x80800210: beql        $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800214: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800234;
    }
    goto skip_2;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_80800218:
    // 0x80800218: jal         0x801138F4
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801138F4(rdram, ctx);
        goto after_21;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800220: beql        $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800224: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800234;
    }
    goto skip_3;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800228: jal         0x80110F44
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80110F44(rdram, ctx);
        goto after_22;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800234:
    // 0x80800234: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80800238: jal         0x80110A68
    // 0x8080023C: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    func_80110A68(rdram, ctx);
        goto after_23;
    // 0x8080023C: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    after_23:
    // 0x80800240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800244: jal         0x80110790
    // 0x80800248: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_80110790(rdram, ctx);
        goto after_24;
    // 0x80800248: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_24:
    // 0x8080024C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800250: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800254: nop

    // 0x80800258: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8080025C: nop

    // 0x80800260: bc1tl       L_80800274
    if (c1cs) {
        // 0x80800264: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800274;
    }
    goto skip_4;
    // 0x80800264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800268: jal         0x80111310
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80111310(rdram, ctx);
        goto after_25;
    // 0x8080026C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800274:
    // 0x80800274: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800278: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8080027C: jr          $ra
    // 0x80800280: nop

    return;
    // 0x80800280: nop

    // 0x80800284: nop

    // 0x80800288: nop

    // 0x8080028C: nop

;}
RECOMP_FUNC void func_80800364_chpickups(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800364: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800368: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080036C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800370: jal         0x800D8FF8
    // 0x80800374: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800374: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800378: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8080037C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800380: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800384: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800388: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8080038C: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80800390: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800394: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800398: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8080039C: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x808003A0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808003A4: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x808003A8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808003AC: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808003B0: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x808003B4: lwc1        $f2, 0x2C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x808003B8: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808003BC: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x808003C0: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x808003C4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808003C8: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808003CC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x808003D0: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x808003D4: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x808003D8: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808003DC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x808003E0: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x808003E4: nop

    // 0x808003E8: bc1fl       L_80800518
    if (!c1cs) {
        // 0x808003EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800518;
    }
    goto skip_0;
    // 0x808003EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808003F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808003F4: nop

    // 0x808003F8: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x808003FC: nop

    // 0x80800400: bc1fl       L_80800518
    if (!c1cs) {
        // 0x80800404: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800518;
    }
    goto skip_1;
    // 0x80800404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800408: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x8080040C: addiu       $at, $zero, 0x3CA
    ctx->r1 = ADD32(0, 0X3CA);
    // 0x80800410: sll         $t6, $v0, 11
    ctx->r14 = S32(ctx->r2 << 11);
    // 0x80800414: srl         $t7, $t6, 20
    ctx->r15 = S32(U32(ctx->r14) >> 20);
    // 0x80800418: beq         $t7, $at, L_80800494
    if (ctx->r15 == ctx->r1) {
        // 0x8080041C: addiu       $at, $zero, 0x3CB
        ctx->r1 = ADD32(0, 0X3CB);
            goto L_80800494;
    }
    // 0x8080041C: addiu       $at, $zero, 0x3CB
    ctx->r1 = ADD32(0, 0X3CB);
    // 0x80800420: beq         $t7, $at, L_80800494
    if (ctx->r15 == ctx->r1) {
        // 0x80800424: addiu       $at, $zero, 0x481
        ctx->r1 = ADD32(0, 0X481);
            goto L_80800494;
    }
    // 0x80800424: addiu       $at, $zero, 0x481
    ctx->r1 = ADD32(0, 0X481);
    // 0x80800428: beq         $t7, $at, L_80800464
    if (ctx->r15 == ctx->r1) {
        // 0x8080042C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800464;
    }
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: addiu       $at, $zero, 0x4B7
    ctx->r1 = ADD32(0, 0X4B7);
    // 0x80800434: beq         $t7, $at, L_80800494
    if (ctx->r15 == ctx->r1) {
        // 0x80800438: addiu       $at, $zero, 0x4D7
        ctx->r1 = ADD32(0, 0X4D7);
            goto L_80800494;
    }
    // 0x80800438: addiu       $at, $zero, 0x4D7
    ctx->r1 = ADD32(0, 0X4D7);
    // 0x8080043C: beq         $t7, $at, L_80800494
    if (ctx->r15 == ctx->r1) {
        // 0x80800440: addiu       $at, $zero, 0x4E2
        ctx->r1 = ADD32(0, 0X4E2);
            goto L_80800494;
    }
    // 0x80800440: addiu       $at, $zero, 0x4E2
    ctx->r1 = ADD32(0, 0X4E2);
    // 0x80800444: beq         $t7, $at, L_80800494
    if (ctx->r15 == ctx->r1) {
        // 0x80800448: addiu       $at, $zero, 0x4E3
        ctx->r1 = ADD32(0, 0X4E3);
            goto L_80800494;
    }
    // 0x80800448: addiu       $at, $zero, 0x4E3
    ctx->r1 = ADD32(0, 0X4E3);
    // 0x8080044C: beq         $t7, $at, L_80800494
    if (ctx->r15 == ctx->r1) {
        // 0x80800450: addiu       $at, $zero, 0x4E4
        ctx->r1 = ADD32(0, 0X4E4);
            goto L_80800494;
    }
    // 0x80800450: addiu       $at, $zero, 0x4E4
    ctx->r1 = ADD32(0, 0X4E4);
    // 0x80800454: beq         $t7, $at, L_80800494
    if (ctx->r15 == ctx->r1) {
        // 0x80800458: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800494;
    }
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080045C: b           L_80800480
    // 0x80800460: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
        goto L_80800480;
    // 0x80800460: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
L_80800464:
    // 0x80800464: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(700, 0XAA8) << 16);
    // 0x80800468: addiu       $a2, $a2, 0xAA8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(700, 0XAA8));
    // 0x8080046C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800470: jal         0x80089D18
    // 0x80800474: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800474: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80800478: b           L_80800494
    // 0x8080047C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
        goto L_80800494;
    // 0x8080047C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
L_80800480:
    // 0x80800480: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(700, 0XAB8) << 16);
    // 0x80800484: addiu       $a2, $a2, 0xAB8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(700, 0XAB8));
    // 0x80800488: jal         0x80089D18
    // 0x8080048C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080048C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x80800490: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
L_80800494:
    // 0x80800494: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80800498: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080049C: swc1        $f12, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f12.u32l;
    // 0x808004A0: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808004A4: bnel        $t9, $at, L_808004E4
    if (ctx->r25 != ctx->r1) {
        // 0x808004A8: lbu         $t2, 0x65($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X65);
            goto L_808004E4;
    }
    goto skip_2;
    // 0x808004A8: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    skip_2:
    // 0x808004AC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x808004B0: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x808004B4: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
    // 0x808004B8: srl         $t1, $v0, 22
    ctx->r9 = S32(U32(ctx->r2) >> 22);
    // 0x808004BC: beq         $t1, $at, L_808004E0
    if (ctx->r9 == ctx->r1) {
        // 0x808004C0: addiu       $at, $zero, 0x67
        ctx->r1 = ADD32(0, 0X67);
            goto L_808004E0;
    }
    // 0x808004C0: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x808004C4: bne         $t1, $at, L_808004E0
    if (ctx->r9 != ctx->r1) {
        // 0x808004C8: addiu       $a0, $zero, 0x4A5
        ctx->r4 = ADD32(0, 0X4A5);
            goto L_808004E0;
    }
    // 0x808004C8: addiu       $a0, $zero, 0x4A5
    ctx->r4 = ADD32(0, 0X4A5);
    // 0x808004CC: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
    // 0x808004D0: jal         0x80101180
    // 0x808004D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x808004D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808004D8: jal         0x800FFAB0
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_808004E0:
    // 0x808004E0: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
L_808004E4:
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004EC: andi        $t9, $t2, 0xFFBF
    ctx->r25 = ctx->r10 & 0XFFBF;
    // 0x808004F0: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x808004F4: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x808004F8: andi        $t0, $t9, 0x7F
    ctx->r8 = ctx->r25 & 0X7F;
    // 0x808004FC: sll         $t5, $t4, 9
    ctx->r13 = S32(ctx->r12 << 9);
    // 0x80800500: srl         $t6, $t5, 31
    ctx->r14 = S32(U32(ctx->r13) >> 31);
    // 0x80800504: sll         $t8, $t6, 7
    ctx->r24 = S32(ctx->r14 << 7);
    // 0x80800508: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8080050C: jal         0x80101FDC
    // 0x80800510: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800510: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    after_5:
    // 0x80800514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800518:
    // 0x80800518: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080051C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800520: jr          $ra
    // 0x80800524: nop

    return;
    // 0x80800524: nop

;}
RECOMP_FUNC void func_80800598_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800598: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080059C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005A4: jal         0x80100094
    // 0x808005A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808005A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005AC: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x808005B0: jal         0x80088FA8
    // 0x808005B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _mlwave_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808005B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808005B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808005BC: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    // 0x808005C0: jal         0x80088FC8
    // 0x808005C4: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    _mlwave_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808005C4: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_2:
    // 0x808005C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808005CC: swc1        $f0, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f0.u32l;
    // 0x808005D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808005D8: jr          $ra
    // 0x808005DC: nop

    return;
    // 0x808005DC: nop

;}
RECOMP_FUNC void func_80800720_chtorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800720: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800724: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800728: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080072C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800730: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800734: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080073C: jal         0x80100094
    // 0x80800740: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800740: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800744: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800748: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080074C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800750: beq         $a2, $at, L_8080079C
    if (ctx->r6 == ctx->r1) {
        // 0x80800754: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8080079C;
    }
    // 0x80800754: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800758: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x8080075C: beq         $a2, $at, L_8080078C
    if (ctx->r6 == ctx->r1) {
        // 0x80800760: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8080078C;
    }
    // 0x80800760: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800764: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80800768: beq         $a2, $at, L_808007C0
    if (ctx->r6 == ctx->r1) {
        // 0x8080076C: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808007C0;
    }
    // 0x8080076C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800770: beq         $a2, $at, L_808007B0
    if (ctx->r6 == ctx->r1) {
        // 0x80800774: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808007B0;
    }
    // 0x80800774: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800778: addiu       $at, $zero, 0x98
    ctx->r1 = ADD32(0, 0X98);
    // 0x8080077C: beq         $a2, $at, L_80800808
    if (ctx->r6 == ctx->r1) {
        // 0x80800780: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80800808;
    }
    // 0x80800780: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800784: b           L_8080081C
    // 0x80800788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080081C;
    // 0x80800788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080078C:
    // 0x8080078C: jal         0x800FFAB0
    // 0x80800790: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800790: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    after_1:
    // 0x80800794: b           L_8080081C
    // 0x80800798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080081C;
    // 0x80800798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080079C:
    // 0x8080079C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808007A0: jal         0x808001E0
    // 0x808007A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808001E0_chtorpedo(rdram, ctx);
        goto after_2;
    // 0x808007A4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x808007A8: b           L_8080081C
    // 0x808007AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080081C;
    // 0x808007AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007B0:
    // 0x808007B0: jal         0x80109EEC
    // 0x808007B4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80109EEC(rdram, ctx);
        goto after_3;
    // 0x808007B4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_3:
    // 0x808007B8: b           L_8080081C
    // 0x808007BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080081C;
    // 0x808007BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007C0:
    // 0x808007C0: lw          $t6, 0x2C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2C);
    // 0x808007C4: beq         $t6, $zero, L_808007F8
    if (ctx->r14 == 0) {
        // 0x808007C8: nop
    
            goto L_808007F8;
    }
    // 0x808007C8: nop

    // 0x808007CC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x808007D0: lw          $a2, 0x30($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X30);
    // 0x808007D4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x808007D8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x808007DC: lw          $t9, 0x2C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C);
    // 0x808007E0: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x808007E4: jalr        $t9
    // 0x808007E8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x808007E8: nop

    after_4:
    // 0x808007EC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808007F0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808007F4: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
L_808007F8:
    // 0x808007F8: jal         0x800FFAB0
    // 0x808007FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x808007FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_5:
    // 0x80800800: b           L_8080081C
    // 0x80800804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080081C;
    // 0x80800804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800808:
    // 0x80800808: b           L_80800818
    // 0x8080080C: sw          $t7, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r15;
        goto L_80800818;
    // 0x8080080C: sw          $t7, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r15;
    // 0x80800810: b           L_8080081C
    // 0x80800814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080081C;
    // 0x80800814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800818:
    // 0x80800818: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080081C:
    // 0x8080081C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800824: jr          $ra
    // 0x80800828: nop

    return;
    // 0x80800828: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800842C0: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800842C0);
    return;
    // 0x800842C4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800EC708(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC708: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC70C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EC710: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x800EC714: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800EC718: lw          $t6, 0x8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X8);
    // 0x800EC71C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800EC720: sll         $t8, $t6, 30
    ctx->r24 = S32(ctx->r14 << 30);
    // 0x800EC724: bgez        $t8, L_800EC744
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800EC728: nop
    
            goto L_800EC744;
    }
    // 0x800EC728: nop

    // 0x800EC72C: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800EC730: addiu       $a1, $a1, -0x3AFC
    ctx->r5 = ADD32(ctx->r5, -0X3AFC);
    // 0x800EC734: jal         0x800EC5C0
    // 0x800EC738: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EC5C0(rdram, ctx);
        goto after_0;
    // 0x800EC738: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x800EC73C: b           L_800EC750
    // 0x800EC740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800EC750;
    // 0x800EC740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EC744:
    // 0x800EC744: jal         0x800EC5C0
    // 0x800EC748: addiu       $a1, $a1, -0x3B74
    ctx->r5 = ADD32(ctx->r5, -0X3B74);
    func_800EC5C0(rdram, ctx);
        goto after_1;
    // 0x800EC748: addiu       $a1, $a1, -0x3B74
    ctx->r5 = ADD32(ctx->r5, -0X3B74);
    after_1:
    // 0x800EC74C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EC750:
    // 0x800EC750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EC754: jr          $ra
    // 0x800EC758: nop

    return;
    // 0x800EC758: nop

;}
RECOMP_FUNC void gcgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x80016864
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80016864(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: jal         0x800DC310
    // 0x80800014: nop

    func_800DC310(rdram, ctx);
        goto after_1;
    // 0x80800014: nop

    after_1:
    // 0x80800018: jal         0x800EBB5C
    // 0x8080001C: nop

    func_800EBB5C(rdram, ctx);
        goto after_2;
    // 0x8080001C: nop

    after_2:
    // 0x80800020: jal         0x80012128
    // 0x80800024: nop

    func_80012128(rdram, ctx);
        goto after_3;
    // 0x80800024: nop

    after_3:
    // 0x80800028: jal         0x800DA0B4
    // 0x8080002C: nop

    func_800DA0B4(rdram, ctx);
        goto after_4;
    // 0x8080002C: nop

    after_4:
    // 0x80800030: jal         0x800DA0D8
    // 0x80800034: nop

    func_800DA0D8(rdram, ctx);
        goto after_5;
    // 0x80800034: nop

    after_5:
    // 0x80800038: jal         0x800F8E08
    // 0x8080003C: nop

    func_800F8E08(rdram, ctx);
        goto after_6;
    // 0x8080003C: nop

    after_6:
    // 0x80800040: jal         0x8009E8D4
    // 0x80800044: nop

    func_8009E8D4(rdram, ctx);
        goto after_7;
    // 0x80800044: nop

    after_7:
    // 0x80800048: jal         0x800D2438
    // 0x8080004C: nop

    func_800D2438(rdram, ctx);
        goto after_8;
    // 0x8080004C: nop

    after_8:
    // 0x80800050: jal         0x800D1510
    // 0x80800054: nop

    func_800D1510(rdram, ctx);
        goto after_9;
    // 0x80800054: nop

    after_9:
    // 0x80800058: jal         0x800DACD0
    // 0x8080005C: nop

    func_800DACD0(rdram, ctx);
        goto after_10;
    // 0x8080005C: nop

    after_10:
    // 0x80800060: jal         0x80088020
    // 0x80800064: nop

    _gccollectDll_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800064: nop

    after_11:
    // 0x80800068: jal         0x800CB618
    // 0x8080006C: nop

    func_800CB618(rdram, ctx);
        goto after_12;
    // 0x8080006C: nop

    after_12:
    // 0x80800070: jal         0x800D2014
    // 0x80800074: nop

    func_800D2014(rdram, ctx);
        goto after_13;
    // 0x80800074: nop

    after_13:
    // 0x80800078: jal         0x800CEF6C
    // 0x8080007C: nop

    func_800CEF6C(rdram, ctx);
        goto after_14;
    // 0x8080007C: nop

    after_14:
    // 0x80800080: jal         0x800C7170
    // 0x80800084: nop

    func_800C7170(rdram, ctx);
        goto after_15;
    // 0x80800084: nop

    after_15:
    // 0x80800088: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8080008C: beq         $t6, $zero, L_808000A4
    if (ctx->r14 == 0) {
        // 0x80800090: nop
    
            goto L_808000A4;
    }
    // 0x80800090: nop

    // 0x80800094: jal         0x800D37FC
    // 0x80800098: nop

    func_800D37FC(rdram, ctx);
        goto after_16;
    // 0x80800098: nop

    after_16:
    // 0x8080009C: jal         0x80088448
    // 0x808000A0: nop

    _gcgamefix_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x808000A0: nop

    after_17:
L_808000A4:
    // 0x808000A4: jal         0x800A1364
    // 0x808000A8: nop

    func_800A1364(rdram, ctx);
        goto after_18;
    // 0x808000A8: nop

    after_18:
    // 0x808000AC: jal         0x800D3FD4
    // 0x808000B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800D3FD4(rdram, ctx);
        goto after_19;
    // 0x808000B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x808000B4: jal         0x800D162C
    // 0x808000B8: nop

    func_800D162C(rdram, ctx);
        goto after_20;
    // 0x808000B8: nop

    after_20:
    // 0x808000BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000C4: jr          $ra
    // 0x808000C8: nop

    return;
    // 0x808000C8: nop

;}
RECOMP_FUNC void func_808000C0_chmole_maya(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000CC: jal         0x8010C500
    // 0x808000D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8010C500(rdram, ctx);
        goto after_0;
    // 0x808000D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000D4: beq         $v0, $zero, L_80800130
    if (ctx->r2 == 0) {
        // 0x808000D8: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_80800130;
    }
    // 0x808000D8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x808000DC: jal         0x8008FA2C
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008FA2C(rdram, ctx);
        goto after_1;
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808000E4: beql        $v0, $zero, L_80800134
    if (ctx->r2 == 0) {
        // 0x808000E8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800134;
    }
    goto skip_0;
    // 0x808000E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000EC: lbu         $t6, 0x7E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7E);
    // 0x808000F0: addiu       $a0, $zero, 0x506
    ctx->r4 = ADD32(0, 0X506);
    // 0x808000F4: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x808000F8: jal         0x800DA544
    // 0x808000FC: sb          $t7, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r15;
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x808000FC: sb          $t7, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r15;
    after_2:
    // 0x80800100: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800104: addiu       $t8, $zero, 0x6F
    ctx->r24 = ADD32(0, 0X6F);
    // 0x80800108: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8080010C: addiu       $a1, $zero, 0xDBF
    ctx->r5 = ADD32(0, 0XDBF);
    // 0x80800110: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80800114: jal         0x8008A208
    // 0x80800118: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800118: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x8080011C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800120: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800124: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80800128: jal         0x80085708
    // 0x8080012C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x8080012C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_4:
L_80800130:
    // 0x80800130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800134:
    // 0x80800134: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800138: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void func_80802248_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080224C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802250: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802254: jal         0x8010D290
    // 0x80802258: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    func_8010D290(rdram, ctx);
        goto after_0;
    // 0x80802258: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    after_0:
    // 0x8080225C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80802260: bne         $v0, $at, L_80802274
    if (ctx->r2 != ctx->r1) {
        // 0x80802264: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80802274;
    }
    // 0x80802264: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80802268: jal         0x800F54E4
    // 0x8080226C: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x8080226C: nop

    after_1:
    // 0x80802270: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80802274:
    // 0x80802274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080227C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80802280: jr          $ra
    // 0x80802284: nop

    return;
    // 0x80802284: nop

;}
RECOMP_FUNC void _ncpoddialog_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089608: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x80089608);
    return;
    // 0x8008960C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _chmumbopad_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C70: syscall     437
    recomp_syscall_handler(rdram, ctx, 0x80086C70);
    return;
    // 0x80086C74: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chfactorytwinklies_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1308, 0X22F0) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x22F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1308, 0X22F0));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x22F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1308, 0X22F0));
;}
RECOMP_FUNC void func_80800500_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800508: jal         0x808001D4
    // 0x8080050C: nop

    func_808001D4_bscarry(rdram, ctx);
        goto after_0;
    // 0x8080050C: nop

    after_0:
    // 0x80800510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800518: jr          $ra
    // 0x8080051C: nop

    return;
    // 0x8080051C: nop

;}
RECOMP_FUNC void _bswalk_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084218: syscall     107
    recomp_syscall_handler(rdram, ctx, 0x80084218);
    return;
    // 0x8008421C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void bsbansnooze_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800758: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080075C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(49, 0XA98) << 16);
    // 0x80800760: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800764: jr          $ra
    // 0x80800768: lw          $v0, 0xA98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(49, 0XA98));
    return;
    // 0x80800768: lw          $v0, 0xA98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(49, 0XA98));
;}
RECOMP_FUNC void func_8001E490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E498: jal         0x8002E9C0
    // 0x8001E49C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osDestroyThread_recomp(rdram, ctx);
        goto after_0;
    // 0x8001E49C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8001E4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E4A8: jr          $ra
    // 0x8001E4AC: nop

    return;
    // 0x8001E4AC: nop

;}
RECOMP_FUNC void func_80800AB4_chgoldfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800AB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800ABC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800AC4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800AC8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800ACC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800AD0: jal         0x800D90A4
    // 0x80800AD4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x80800AD4: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800AD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800ADC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800AE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800AE4: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800AE8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800AEC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800AF0: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800AF4: jal         0x800F10B4
    // 0x80800AF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800AF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800AFC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800B00: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800B04: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800B08: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800B0C: jal         0x800EFE50
    // 0x80800B10: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_800EFE50(rdram, ctx);
        goto after_2;
    // 0x80800B10: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80800B14: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800B18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800B1C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800B20: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800B24: jal         0x80013970
    // 0x80800B28: nop

    func_80013970(rdram, ctx);
        goto after_3;
    // 0x80800B28: nop

    after_3:
    // 0x80800B2C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800B30: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80800B34: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800B38: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800B3C: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80800B40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800B44: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800B48: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800B4C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800B50: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80800B54: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    // 0x80800B58: lwc1        $f14, 0x54($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800B5C: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800B60: jal         0x800F1FF0
    // 0x80800B64: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_4;
    // 0x80800B64: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80800B68: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800B6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800B70: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800B74: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800B78: lwc1        $f14, 0x50($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800B7C: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80800B80: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800B84: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80800B88: jal         0x800F1FF0
    // 0x80800B8C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F1FF0(rdram, ctx);
        goto after_5;
    // 0x80800B8C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80800B90: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80800B94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B98: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B9C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800BA0: jr          $ra
    // 0x80800BA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800BA4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800D24_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D2C: jal         0x800A3274
    // 0x80800D30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x80800D30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D34: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80800D38: bne         $v0, $at, L_80800D58
    if (ctx->r2 != ctx->r1) {
        // 0x80800D3C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800D58;
    }
    // 0x80800D3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800D40: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(304, 0X1390) << 16);
    // 0x80800D44: addiu       $a1, $a1, 0x1390
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(304, 0X1390));
    // 0x80800D48: jal         0x80800CF4
    // 0x80800D4C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80800CF4_bsledge(rdram, ctx);
        goto after_1;
    // 0x80800D4C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x80800D50: b           L_80800D6C
    // 0x80800D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800D6C;
    // 0x80800D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D58:
    // 0x80800D58: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(304, 0X1388) << 16);
    // 0x80800D5C: addiu       $a1, $a1, 0x1388
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(304, 0X1388));
    // 0x80800D60: jal         0x80800CF4
    // 0x80800D64: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80800CF4_bsledge(rdram, ctx);
        goto after_2;
    // 0x80800D64: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x80800D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800D6C:
    // 0x80800D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D70: jr          $ra
    // 0x80800D74: nop

    return;
    // 0x80800D74: nop

;}
RECOMP_FUNC void func_800C6784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6784: lbu         $t6, 0x95($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X95);
    // 0x800C6788: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800C678C: beql        $t6, $zero, L_800C67C0
    if (ctx->r14 == 0) {
        // 0x800C6790: lwc1        $f0, 0x70($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
            goto L_800C67C0;
    }
    goto skip_0;
    // 0x800C6790: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
    skip_0:
    // 0x800C6794: lwc1        $f4, 0x74($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X74);
    // 0x800C6798: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C679C: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800C67A0: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C67A4: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x800C67A8: nop

    // 0x800C67AC: bc1fl       L_800C67C0
    if (!c1cs) {
        // 0x800C67B0: lwc1        $f0, 0x70($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
            goto L_800C67C0;
    }
    goto skip_1;
    // 0x800C67B0: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
    skip_1:
    // 0x800C67B4: jr          $ra
    // 0x800C67B8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800C67B8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800C67BC: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
L_800C67C0:
    // 0x800C67C0: jr          $ra
    // 0x800C67C4: nop

    return;
    // 0x800C67C4: nop

;}
RECOMP_FUNC void func_8080000C_chklungoforcefield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800018: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080001C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800020: jal         0x800DC298
    // 0x80800024: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x80800024: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800028: beq         $v0, $zero, L_8080003C
    if (ctx->r2 == 0) {
        // 0x8080002C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8080003C;
    }
    // 0x8080002C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800030: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800034: b           L_8080004C
    // 0x80800038: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_8080004C;
    // 0x80800038: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_8080003C:
    // 0x8080003C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800040: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800044: nop

    // 0x80800048: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_8080004C:
    // 0x8080004C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800050: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800054: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800058: jal         0x800DC178
    // 0x8080005C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x8080005C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80800060: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800064: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800068: jal         0x800C8A98
    // 0x8080006C: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x8080006C: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80800070: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80800074: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800078: jal         0x800C8CB8
    // 0x8080007C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_3;
    // 0x8080007C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800080: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1248, 0X460) << 16);
    // 0x80800084: addiu       $a1, $a1, 0x460
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1248, 0X460));
    // 0x80800088: jal         0x800C8E84
    // 0x8080008C: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x8080008C: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_4:
    // 0x80800090: jal         0x800E8B74
    // 0x80800094: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800E8B74(rdram, ctx);
        goto after_5;
    // 0x80800094: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80800098: sb          $v0, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r2;
    // 0x8080009C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808000A0: jal         0x800E8DB0
    // 0x808000A4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_800E8DB0(rdram, ctx);
        goto after_6;
    // 0x808000A4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_6:
    // 0x808000A8: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
    // 0x808000AC: jal         0x800E8D28
    // 0x808000B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E8D28(rdram, ctx);
        goto after_7;
    // 0x808000B0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_7:
    // 0x808000B4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1248, 0X448) << 16);
    // 0x808000B8: addiu       $a1, $a1, 0x448
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1248, 0X448));
    // 0x808000BC: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
    // 0x808000C0: jal         0x800E8D5C
    // 0x808000C4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800E8D5C(rdram, ctx);
        goto after_8;
    // 0x808000C4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x808000C8: jal         0x80089CA0
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: jal         0x8010A828
    // 0x808000D8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_8010A828(rdram, ctx);
        goto after_10;
    // 0x808000D8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_10:
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void gclightsDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x808000A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808000AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000B4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808000B8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x808000BC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x808000C0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x808000C4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808000C8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808000CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x808000D0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x808000D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808000D8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x808000DC: jal         0x800B2D70
    // 0x808000E0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    vector_new(rdram, ctx);
        goto after_0;
    // 0x808000E0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x808000E4: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x808000E8: jal         0x80800000
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_gclightsDll(rdram, ctx);
        goto after_1;
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000F4: jal         0x800825C8
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808000FC: bne         $v0, $zero, L_80800300
    if (ctx->r2 != 0) {
        // 0x80800100: addiu       $s7, $sp, 0x4C
        ctx->r23 = ADD32(ctx->r29, 0X4C);
            goto L_80800300;
    }
    // 0x80800100: addiu       $s7, $sp, 0x4C
    ctx->r23 = ADD32(ctx->r29, 0X4C);
    // 0x80800104: addiu       $fp, $sp, 0x58
    ctx->r30 = ADD32(ctx->r29, 0X58);
    // 0x80800108: addiu       $s6, $sp, 0x6C
    ctx->r22 = ADD32(ctx->r29, 0X6C);
    // 0x8080010C: addiu       $s5, $sp, 0x78
    ctx->r21 = ADD32(ctx->r29, 0X78);
    // 0x80800110: addiu       $s4, $sp, 0x8C
    ctx->r20 = ADD32(ctx->r29, 0X8C);
    // 0x80800114: addiu       $s3, $sp, 0x98
    ctx->r19 = ADD32(ctx->r29, 0X98);
    // 0x80800118: addiu       $s2, $sp, 0xA0
    ctx->r18 = ADD32(ctx->r29, 0XA0);
    // 0x8080011C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800120:
    // 0x80800120: jal         0x800825C8
    // 0x80800124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x80800124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800128: beq         $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x8080012C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001D0;
    }
    // 0x8080012C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800130: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800134: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80800138: jal         0x800825E8
    // 0x8080013C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x8080013C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_4:
    // 0x80800140: beq         $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x80800144: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001D0;
    }
    // 0x80800144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800148: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080014C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80800150: jal         0x800825E8
    // 0x80800154: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _gsmaker_entrypoint_20(rdram, ctx);
        goto after_5;
    // 0x80800154: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_5:
    // 0x80800158: beq         $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x8080015C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001D0;
    }
    // 0x8080015C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800160: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800164: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80800168: jal         0x800825F8
    // 0x8080016C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_22(rdram, ctx);
        goto after_6;
    // 0x8080016C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x80800170: beql        $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x80800174: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001D4;
    }
    goto skip_0;
    // 0x80800174: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80800178: jal         0x80800488
    // 0x8080017C: nop

    gclightsDll_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x8080017C: nop

    after_7:
    // 0x80800180: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800188: jal         0x800C8CB8
    // 0x8080018C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800C8CB8(rdram, ctx);
        goto after_8;
    // 0x8080018C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_8:
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: jal         0x800C8D4C
    // 0x80800198: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C8D4C(rdram, ctx);
        goto after_9;
    // 0x80800198: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_9:
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001A0: jal         0x800C8E84
    // 0x808001A4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800C8E84(rdram, ctx);
        goto after_10;
    // 0x808001A4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_10:
    // 0x808001A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001AC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808001B0: jal         0x800825D0
    // 0x808001B4: addiu       $a2, $sp, 0x8B
    ctx->r6 = ADD32(ctx->r29, 0X8B);
    _gsmaker_entrypoint_17(rdram, ctx);
        goto after_11;
    // 0x808001B4: addiu       $a2, $sp, 0x8B
    ctx->r6 = ADD32(ctx->r29, 0X8B);
    after_11:
    // 0x808001B8: beq         $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x808001BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002EC;
    }
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: jal         0x800C8F64
    // 0x808001C4: lbu         $a1, 0x8B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X8B);
    func_800C8F64(rdram, ctx);
        goto after_12;
    // 0x808001C4: lbu         $a1, 0x8B($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X8B);
    after_12:
    // 0x808001C8: b           L_808002F0
    // 0x808001CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808002F0;
    // 0x808001CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808001D0:
    // 0x808001D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808001D4:
    // 0x808001D4: jal         0x800825C8
    // 0x808001D8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_13;
    // 0x808001D8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_13:
    // 0x808001DC: beq         $v0, $zero, L_8080020C
    if (ctx->r2 == 0) {
        // 0x808001E0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080020C;
    }
    // 0x808001E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808001E8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x808001EC: jal         0x800825F8
    // 0x808001F0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_22(rdram, ctx);
        goto after_14;
    // 0x808001F0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_14:
    // 0x808001F4: beql        $v0, $zero, L_80800210
    if (ctx->r2 == 0) {
        // 0x808001F8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800210;
    }
    goto skip_1;
    // 0x808001F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_1:
    // 0x808001FC: jal         0x800C8C90
    // 0x80800200: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800C8C90(rdram, ctx);
        goto after_15;
    // 0x80800200: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_15:
    // 0x80800204: b           L_808002F0
    // 0x80800208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808002F0;
    // 0x80800208: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8080020C:
    // 0x8080020C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800210:
    // 0x80800210: jal         0x800825C8
    // 0x80800214: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_16;
    // 0x80800214: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_16:
    // 0x80800218: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x8080021C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800248;
    }
    // 0x8080021C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800220: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800224: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800228: jal         0x800825F8
    // 0x8080022C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_22(rdram, ctx);
        goto after_17;
    // 0x8080022C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_17:
    // 0x80800230: beql        $v0, $zero, L_8080024C
    if (ctx->r2 == 0) {
        // 0x80800234: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080024C;
    }
    goto skip_2;
    // 0x80800234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_2:
    // 0x80800238: jal         0x80800528
    // 0x8080023C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    gclightsDll_entrypoint_5(rdram, ctx);
        goto after_18;
    // 0x8080023C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_18:
    // 0x80800240: b           L_808002F0
    // 0x80800244: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808002F0;
    // 0x80800244: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800248:
    // 0x80800248: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8080024C:
    // 0x8080024C: jal         0x800825C8
    // 0x80800250: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_19;
    // 0x80800250: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_19:
    // 0x80800254: beq         $v0, $zero, L_80800278
    if (ctx->r2 == 0) {
        // 0x80800258: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800278;
    }
    // 0x80800258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080025C: jal         0x80800488
    // 0x80800260: nop

    gclightsDll_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x80800260: nop

    after_20:
    // 0x80800264: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800268: jal         0x800B2974
    // 0x8080026C: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    vector_push_back(rdram, ctx);
        goto after_21;
    // 0x8080026C: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    after_21:
    // 0x80800270: b           L_808002EC
    // 0x80800274: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
        goto L_808002EC;
    // 0x80800274: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
L_80800278:
    // 0x80800278: jal         0x800825C8
    // 0x8080027C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_22;
    // 0x8080027C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_22:
    // 0x80800280: beq         $v0, $zero, L_808002C8
    if (ctx->r2 == 0) {
        // 0x80800284: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808002C8;
    }
    // 0x80800284: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800288: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080028C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80800290: jal         0x800825E8
    // 0x80800294: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_20(rdram, ctx);
        goto after_23;
    // 0x80800294: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_23:
    // 0x80800298: beq         $v0, $zero, L_808002C8
    if (ctx->r2 == 0) {
        // 0x8080029C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808002C8;
    }
    // 0x8080029C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808002A4: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x808002A8: jal         0x800825F8
    // 0x808002AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_22(rdram, ctx);
        goto after_24;
    // 0x808002AC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_24:
    // 0x808002B0: beq         $v0, $zero, L_808002C8
    if (ctx->r2 == 0) {
        // 0x808002B4: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_808002C8;
    }
    // 0x808002B4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x808002B8: jal         0x800C8F08
    // 0x808002BC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800C8F08(rdram, ctx);
        goto after_25;
    // 0x808002BC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_25:
    // 0x808002C0: b           L_808002F0
    // 0x808002C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_808002F0;
    // 0x808002C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808002C8:
    // 0x808002C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002CC: jal         0x800825C8
    // 0x808002D0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_26;
    // 0x808002D0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_26:
    // 0x808002D4: beq         $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x808002D8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808002EC;
    }
    // 0x808002D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002DC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808002E0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x808002E4: jal         0x800825F8
    // 0x808002E8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _gsmaker_entrypoint_22(rdram, ctx);
        goto after_27;
    // 0x808002E8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_27:
L_808002EC:
    // 0x808002EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808002F0:
    // 0x808002F0: jal         0x800825C8
    // 0x808002F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gsmaker_entrypoint_16(rdram, ctx);
        goto after_28;
    // 0x808002F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_28:
    // 0x808002F8: beql        $v0, $zero, L_80800120
    if (ctx->r2 == 0) {
        // 0x808002FC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800120;
    }
    goto skip_3;
    // 0x808002FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_3:
L_80800300:
    // 0x80800300: jal         0x800B296C
    // 0x80800304: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    vector_end(rdram, ctx);
        goto after_29;
    // 0x80800304: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    after_29:
    // 0x80800308: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080030C: jal         0x800B28C4
    // 0x80800310: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    vector_begin(rdram, ctx);
        goto after_30;
    // 0x80800310: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    after_30:
    // 0x80800314: sltu        $at, $v0, $s1
    ctx->r1 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x80800318: beq         $at, $zero, L_80800338
    if (ctx->r1 == 0) {
        // 0x8080031C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80800338;
    }
    // 0x8080031C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800320:
    // 0x80800320: jal         0x800C8B84
    // 0x80800324: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800C8B84(rdram, ctx);
        goto after_31;
    // 0x80800324: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_31:
    // 0x80800328: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8080032C: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80800330: bne         $at, $zero, L_80800320
    if (ctx->r1 != 0) {
        // 0x80800334: nop
    
            goto L_80800320;
    }
    // 0x80800334: nop

L_80800338:
    // 0x80800338: jal         0x800B2D28
    // 0x8080033C: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    vector_free(rdram, ctx);
        goto after_32;
    // 0x8080033C: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    after_32:
    // 0x80800340: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800344: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800348: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080034C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800350: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80800354: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800358: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8080035C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800360: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80800364: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80800368: jr          $ra
    // 0x8080036C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8080036C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void wait_five_seconds_gzpublic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800008: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800014: addiu       $s1, $zero, 0x12C
    ctx->r17 = ADD32(0, 0X12C);
L_80800018:
    // 0x80800018: jal         0x80015778
    // 0x8080001C: nop

    wait_one_frame(rdram, ctx);
        goto after_0;
    // 0x8080001C: nop

    after_0:
    // 0x80800020: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800024: bne         $s0, $s1, L_80800018
    if (ctx->r16 != ctx->r17) {
        // 0x80800028: nop
    
            goto L_80800018;
    }
    // 0x80800028: nop

    // 0x8080002C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800030: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080003C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80102D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102DA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102DA4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80102DA8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80102DAC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80102DB0: lhu         $t8, 0x12($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X12);
    // 0x80102DB4: srl         $t9, $t8, 1
    ctx->r25 = S32(U32(ctx->r24) >> 1);
    // 0x80102DB8: jal         0x8001210C
    // 0x80102DBC: and         $a0, $t9, $a1
    ctx->r4 = ctx->r25 & ctx->r5;
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80102DBC: and         $a0, $t9, $a1
    ctx->r4 = ctx->r25 & ctx->r5;
    after_0:
    // 0x80102DC0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80102DC4: bnel        $v0, $t0, L_80102DF8
    if (ctx->r2 != ctx->r8) {
        // 0x80102DC8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80102DF8;
    }
    goto skip_0;
    // 0x80102DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80102DCC: jal         0x800DC298
    // 0x80102DD0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x80102DD0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80102DD4: beq         $v0, $zero, L_80102DF4
    if (ctx->r2 == 0) {
        // 0x80102DD8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80102DF4;
    }
    // 0x80102DD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80102DDC: lw          $a1, 0x48($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X48);
    // 0x80102DE0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80102DE4: jal         0x8010297C
    // 0x80102DE8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_8010297C(rdram, ctx);
        goto after_2;
    // 0x80102DE8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80102DEC: b           L_80102DF8
    // 0x80102DF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80102DF8;
    // 0x80102DF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80102DF4:
    // 0x80102DF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102DF8:
    // 0x80102DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102DFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102E00: jr          $ra
    // 0x80102E04: nop

    return;
    // 0x80102E04: nop

;}
RECOMP_FUNC void subaddierouteDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800674: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800678: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080067C: andi        $t6, $a2, 0x1C
    ctx->r14 = ctx->r6 & 0X1C;
    // 0x80800680: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80800684: beq         $t6, $zero, L_80800694
    if (ctx->r14 == 0) {
        // 0x80800688: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80800694;
    }
    // 0x80800688: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080068C: b           L_808006C0
    // 0x80800690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006C0;
    // 0x80800690: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800694:
    // 0x80800694: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800698: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8080069C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808006A0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808006A4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x808006A8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x808006AC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808006B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808006B4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808006B8: jal         0x80102D98
    // 0x808006BC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_80102D98(rdram, ctx);
        goto after_0;
    // 0x808006BC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_0:
L_808006C0:
    // 0x808006C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006C8: jr          $ra
    // 0x808006CC: nop

    return;
    // 0x808006CC: nop

;}
RECOMP_FUNC void func_80801DD0_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801DD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801DD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801DDC: jal         0x8010CD28
    // 0x80801DE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8010CD28(rdram, ctx);
        goto after_0;
    // 0x80801DE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801DE4: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80801DE8: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x80801DEC: jal         0x800F20BC
    // 0x80801DF0: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    func_800F20BC(rdram, ctx);
        goto after_1;
    // 0x80801DF0: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_1:
    // 0x80801DF4: beq         $v0, $zero, L_80801E44
    if (ctx->r2 == 0) {
        // 0x80801DF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801E44;
    }
    // 0x80801DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801DFC: jal         0x80089BD8
    // 0x80801E00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80801E00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80801E04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801E08: bne         $v0, $at, L_80801E44
    if (ctx->r2 != ctx->r1) {
        // 0x80801E0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801E44;
    }
    // 0x80801E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E10: jal         0x801021BC
    // 0x80801E14: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_801021BC(rdram, ctx);
        goto after_3;
    // 0x80801E14: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x80801E18: beq         $v0, $zero, L_80801E34
    if (ctx->r2 == 0) {
        // 0x80801E1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801E34;
    }
    // 0x80801E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E24: jal         0x808014AC
    // 0x80801E28: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_4;
    // 0x80801E28: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_4:
    // 0x80801E2C: b           L_80801E48
    // 0x80801E30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801E48;
    // 0x80801E30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801E34:
    // 0x80801E34: jal         0x808014AC
    // 0x80801E38: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_5;
    // 0x80801E38: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_5:
    // 0x80801E3C: b           L_80801E48
    // 0x80801E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801E48;
    // 0x80801E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801E44:
    // 0x80801E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801E48:
    // 0x80801E48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801E4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801E50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801E54: jr          $ra
    // 0x80801E58: nop

    return;
    // 0x80801E58: nop

;}
RECOMP_FUNC void vector_push_back(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2974: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B2978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B297C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800B2980: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x800B2984: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800B2988: lw          $a3, 0x8($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X8);
    // 0x800B298C: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x800B2990: bnel        $t7, $a3, L_800B2A3C
    if (ctx->r15 != ctx->r7) {
        // 0x800B2994: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_800B2A3C;
    }
    goto skip_0;
    // 0x800B2994: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x800B2998: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x800B299C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800B29A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B29A4: subu        $t9, $a3, $t8
    ctx->r25 = SUB32(ctx->r7, ctx->r24);
    // 0x800B29A8: div         $zero, $t9, $v0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r2)));
    // 0x800B29AC: mflo        $t0
    ctx->r8 = lo;
    // 0x800B29B0: addiu       $v1, $t0, 0x5
    ctx->r3 = ADD32(ctx->r8, 0X5);
    // 0x800B29B4: bne         $v0, $zero, L_800B29C0
    if (ctx->r2 != 0) {
        // 0x800B29B8: nop
    
            goto L_800B29C0;
    }
    // 0x800B29B8: nop

    // 0x800B29BC: break       7
    do_break(2148215228);
L_800B29C0:
    // 0x800B29C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B29C4: bne         $v0, $at, L_800B29D8
    if (ctx->r2 != ctx->r1) {
        // 0x800B29C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B29D8;
    }
    // 0x800B29C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B29CC: bne         $t9, $at, L_800B29D8
    if (ctx->r25 != ctx->r1) {
        // 0x800B29D0: nop
    
            goto L_800B29D8;
    }
    // 0x800B29D0: nop

    // 0x800B29D4: break       6
    do_break(2148215252);
L_800B29D8:
    // 0x800B29D8: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B29DC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x800B29E0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800B29E4: mflo        $a1
    ctx->r5 = lo;
    // 0x800B29E8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800B29EC: jal         0x8001B208
    // 0x800B29F0: nop

    heap_realloc(rdram, ctx);
        goto after_0;
    // 0x800B29F0: nop

    after_0:
    // 0x800B29F4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800B29F8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800B29FC: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x800B2A00: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x800B2A04: multu       $t0, $a0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2A08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800B2A0C: mflo        $t1
    ctx->r9 = lo;
    // 0x800B2A10: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x800B2A14: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x800B2A18: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x800B2A1C: multu       $t3, $a0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2A20: mflo        $t4
    ctx->r12 = lo;
    // 0x800B2A24: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x800B2A28: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x800B2A2C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800B2A30: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x800B2A34: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x800B2A38: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_800B2A3C:
    // 0x800B2A3C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800B2A40: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x800B2A44: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800B2A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2A4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B2A50: jr          $ra
    // 0x800B2A54: nop

    return;
    // 0x800B2A54: nop

;}
RECOMP_FUNC void func_80800B40_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800B4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B50: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x80800B54: jal         0x8080015C
    // 0x80800B58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8080015C_chhumba(rdram, ctx);
        goto after_0;
    // 0x80800B58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80800B5C: jal         0x8008F8B0
    // 0x80800B60: nop

    func_8008F8B0(rdram, ctx);
        goto after_1;
    // 0x80800B60: nop

    after_1:
    // 0x80800B64: jal         0x8008F8D8
    // 0x80800B68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_2;
    // 0x80800B68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800B6C: jal         0x8008F938
    // 0x80800B70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F938(rdram, ctx);
        goto after_3;
    // 0x80800B70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800B74: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800B78: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800B7C: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80800B80: jal         0x8008F904
    // 0x80800B84: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_8008F904(rdram, ctx);
        goto after_4;
    // 0x80800B84: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_4:
    // 0x80800B88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B8C: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80800B90: jal         0x8008F9F8
    // 0x80800B94: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8008F9F8(rdram, ctx);
        goto after_5;
    // 0x80800B94: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_5:
    // 0x80800B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BA0: jr          $ra
    // 0x80800BA4: nop

    return;
    // 0x80800BA4: nop

;}
RECOMP_FUNC void func_800DC178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DC17C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DC180: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800DC184: jal         0x800DC0C0
    // 0x800DC188: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x800DC188: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800DC18C: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800DC190: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800DC194: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DC198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DC19C: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800DC1A0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800DC1A4: jr          $ra
    // 0x800DC1A8: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
    return;
    // 0x800DC1A8: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
;}
RECOMP_FUNC void func_800CA334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA334: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CA338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA33C: jal         0x8001ACCC
    // 0x800CA340: addiu       $a0, $zero, 0x168
    ctx->r4 = ADD32(0, 0X168);
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800CA340: addiu       $a0, $zero, 0x168
    ctx->r4 = ADD32(0, 0X168);
    after_0:
    // 0x800CA344: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800CA348: jal         0x800CA440
    // 0x800CA34C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800CA440(rdram, ctx);
        goto after_1;
    // 0x800CA34C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800CA350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA354: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800CA358: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CA35C: jr          $ra
    // 0x800CA360: nop

    return;
    // 0x800CA360: nop

;}
RECOMP_FUNC void func_80800AB8_chonearmbandit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AB8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800ABC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800AC0: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x80800AC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AC8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80800ACC: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800AD0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800AD4: jal         0x8008A0E0
    // 0x80800AD8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800AD8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80800ADC: bne         $v0, $zero, L_80800B10
    if (ctx->r2 != 0) {
        // 0x80800AE0: lw          $a1, 0x50($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X50);
            goto L_80800B10;
    }
    // 0x80800AE0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80800AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE8: jal         0x800EE7F8
    // 0x80800AEC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800AEC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x80800AF0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80800AF4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800AF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800AFC: lwc1        $f4, 0x38($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X38);
    // 0x80800B00: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800B04: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800B08: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80800B0C: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
L_80800B10:
    // 0x80800B10: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80800B14: addiu       $a0, $zero, 0x35B
    ctx->r4 = ADD32(0, 0X35B);
    // 0x80800B18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800B1C: lwc1        $f18, 0x48($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X48);
    // 0x80800B20: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x80800B24: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800B28: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800B2C: jal         0x80108528
    // 0x80800B30: nop

    func_80108528(rdram, ctx);
        goto after_2;
    // 0x80800B30: nop

    after_2:
    // 0x80800B34: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80800B38: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800B3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B40: jal         0x80102FDC
    // 0x80800B44: lw          $a1, 0x38($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X38);
    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x80800B44: lw          $a1, 0x38($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X38);
    after_3:
    // 0x80800B48: jal         0x800F54E4
    // 0x80800B4C: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x80800B4C: nop

    after_4:
    // 0x80800B50: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800B54: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800B58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B5C: jal         0x8010D09C
    // 0x80800B60: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_8010D09C(rdram, ctx);
        goto after_5;
    // 0x80800B60: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_5:
    // 0x80800B64: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800B68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800B6C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800B70: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80800B74: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800B78: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800B7C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800B80: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x80800B84: lw          $t2, 0x64($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X64);
    // 0x80800B88: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80800B8C: bgez        $t4, L_80800BE4
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800B90: nop
    
            goto L_80800BE4;
    }
    // 0x80800B90: nop

    // 0x80800B94: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800B98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800B9C: jal         0x800F1DF4
    // 0x80800BA0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800F1DF4(rdram, ctx);
        goto after_6;
    // 0x80800BA0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_6:
    // 0x80800BA4: jal         0x800136E4
    // 0x80800BA8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_7;
    // 0x80800BA8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_7:
    // 0x80800BAC: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80800BB0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800BB4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800BB8: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x80800BBC: jal         0x800F20BC
    // 0x80800BC0: lwc1        $f14, 0x48($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0X48);
    func_800F20BC(rdram, ctx);
        goto after_8;
    // 0x80800BC0: lwc1        $f14, 0x48($t5)
    ctx->f14.u32l = MEM_W(ctx->r13, 0X48);
    after_8:
    // 0x80800BC4: beq         $v0, $zero, L_80800BD8
    if (ctx->r2 == 0) {
        // 0x80800BC8: lw          $t6, 0x50($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X50);
            goto L_80800BD8;
    }
    // 0x80800BC8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80800BCC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800BD0: b           L_80800C70
    // 0x80800BD4: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
        goto L_80800C70;
    // 0x80800BD4: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
L_80800BD8:
    // 0x80800BD8: lwc1        $f18, 0x48($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X48);
    // 0x80800BDC: b           L_80800C70
    // 0x80800BE0: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
        goto L_80800C70;
    // 0x80800BE0: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
L_80800BE4:
    // 0x80800BE4: jal         0x800F1DF4
    // 0x80800BE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800F1DF4(rdram, ctx);
        goto after_9;
    // 0x80800BE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_9:
    // 0x80800BEC: jal         0x800136E4
    // 0x80800BF0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_10;
    // 0x80800BF0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_10:
    // 0x80800BF4: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80800BF8: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80800BFC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800C00: jal         0x800F1DCC
    // 0x80800C04: lwc1        $f14, 0x48($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_11;
    // 0x80800C04: lwc1        $f14, 0x48($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X48);
    after_11:
    // 0x80800C08: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x80800C0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C10: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80800C14: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800C18: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800C1C: nop

    // 0x80800C20: bc1fl       L_80800C44
    if (!c1cs) {
        // 0x80800C24: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80800C44;
    }
    goto skip_0;
    // 0x80800C24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_0:
    // 0x80800C28: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800C2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800C30: lwc1        $f6, 0x48($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X48);
    // 0x80800C34: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80800C38: b           L_80800C70
    // 0x80800C3C: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
        goto L_80800C70;
    // 0x80800C3C: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x80800C40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80800C44:
    // 0x80800C44: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80800C48: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80800C4C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80800C50: nop

    // 0x80800C54: bc1fl       L_80800C74
    if (!c1cs) {
        // 0x80800C58: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800C74;
    }
    goto skip_1;
    // 0x80800C58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80800C5C: lwc1        $f18, 0x48($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X48);
    // 0x80800C60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C64: nop

    // 0x80800C68: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800C6C: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
L_80800C70:
    // 0x80800C70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800C74:
    // 0x80800C74: jal         0x800F1828
    // 0x80800C78: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800F1828(rdram, ctx);
        goto after_12;
    // 0x80800C78: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_12:
    // 0x80800C7C: jal         0x800136E4
    // 0x80800C80: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_13;
    // 0x80800C80: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_13:
    // 0x80800C84: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800C88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800C8C: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80800C90: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800C94: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C9C: bc1fl       L_80800CCC
    if (!c1cs) {
        // 0x80800CA0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80800CCC;
    }
    goto skip_2;
    // 0x80800CA0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x80800CA4: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80800CA8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800CAC: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800CB0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800CB4: nop

    // 0x80800CB8: bc1f        L_80800CE4
    if (!c1cs) {
        // 0x80800CBC: nop
    
            goto L_80800CE4;
    }
    // 0x80800CBC: nop

    // 0x80800CC0: b           L_80800CE4
    // 0x80800CC4: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
        goto L_80800CE4;
    // 0x80800CC4: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80800CC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80800CCC:
    // 0x80800CCC: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800CD0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800CD4: nop

    // 0x80800CD8: bc1f        L_80800CE4
    if (!c1cs) {
        // 0x80800CDC: nop
    
            goto L_80800CE4;
    }
    // 0x80800CDC: nop

    // 0x80800CE0: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
L_80800CE4:
    // 0x80800CE4: jal         0x80108944
    // 0x80800CE8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_80108944(rdram, ctx);
        goto after_14;
    // 0x80800CE8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_14:
    // 0x80800CEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CF4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800CF8: jr          $ra
    // 0x80800CFC: nop

    return;
    // 0x80800CFC: nop

;}
RECOMP_FUNC void func_80800000_chTalTorpWall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800004: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800344_chfactorymaindoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080034C: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800350: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800354: addiu       $a1, $zero, 0xA00
    ctx->r5 = ADD32(0, 0XA00);
    // 0x80800358: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080035C: bne         $t7, $at, L_80800384
    if (ctx->r15 != ctx->r1) {
        // 0x80800360: nop
    
            goto L_80800384;
    }
    // 0x80800360: nop

    // 0x80800364: addiu       $a1, $zero, 0xA01
    ctx->r5 = ADD32(0, 0XA01);
    // 0x80800368: jal         0x80085808
    // 0x8080036C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x8080036C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800370: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800374: jal         0x80085810
    // 0x80800378: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800378: addiu       $a1, $zero, 0x200
    ctx->r5 = ADD32(0, 0X200);
    after_1:
    // 0x8080037C: b           L_8080039C
    // 0x80800380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080039C;
    // 0x80800380: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800384:
    // 0x80800384: jal         0x80085808
    // 0x80800388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8080038C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800390: jal         0x80085810
    // 0x80800394: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800394: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_3:
    // 0x80800398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080039C:
    // 0x8080039C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003A0: jr          $ra
    // 0x808003A4: nop

    return;
    // 0x808003A4: nop

;}
RECOMP_FUNC void func_800F6E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6E80: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6E84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6E88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6E90: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6E94: jal         0x800A336C
    // 0x800F6E98: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A336C(rdram, ctx);
        goto after_0;
    // 0x800F6E98: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F6E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6EA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6EA4: jr          $ra
    // 0x800F6EA8: nop

    return;
    // 0x800F6EA8: nop

;}
RECOMP_FUNC void func_808013BC_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808013C0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808013C4: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808013C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808013CC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808013D0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808013D4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808013D8: jal         0x80100094
    // 0x808013DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808013DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808013E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808013E4: jal         0x80088368
    // 0x808013E8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808013E8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_1:
    // 0x808013EC: blez        $v0, L_80801440
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808013F0: sll         $t6, $s2, 2
        ctx->r14 = S32(ctx->r18 << 2);
            goto L_80801440;
    }
    // 0x808013F0: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x808013F4: addu        $s1, $s0, $t6
    ctx->r17 = ADD32(ctx->r16, ctx->r14);
    // 0x808013F8: addiu       $s0, $s2, 0xC3
    ctx->r16 = ADD32(ctx->r18, 0XC3);
L_808013FC:
    // 0x808013FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801400: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80801404: jal         0x800D24E8
    // 0x80801408: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D24E8(rdram, ctx);
        goto after_2;
    // 0x80801408: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8080140C: beql        $s3, $zero, L_8080142C
    if (ctx->r19 == 0) {
        // 0x80801410: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8080142C;
    }
    goto skip_0;
    // 0x80801410: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80801414: lw          $t7, 0x20($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X20);
    // 0x80801418: beql        $t7, $zero, L_8080142C
    if (ctx->r15 == 0) {
        // 0x8080141C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8080142C;
    }
    goto skip_1;
    // 0x8080141C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x80801420: jal         0x800D28A0
    // 0x80801424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D28A0(rdram, ctx);
        goto after_3;
    // 0x80801424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801428: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8080142C:
    // 0x8080142C: jal         0x80088368
    // 0x80801430: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80801430: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    after_4:
    // 0x80801434: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80801438: bnel        $at, $zero, L_808013FC
    if (ctx->r1 != 0) {
        // 0x8080143C: addiu       $s0, $s2, 0xC3
        ctx->r16 = ADD32(ctx->r18, 0XC3);
            goto L_808013FC;
    }
    goto skip_2;
    // 0x8080143C: addiu       $s0, $s2, 0xC3
    ctx->r16 = ADD32(ctx->r18, 0XC3);
    skip_2:
L_80801440:
    // 0x80801440: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801444: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801448: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080144C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80801450: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80801454: jr          $ra
    // 0x80801458: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801458: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void chnicecavemen_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1096, 0X1AEC) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x1AEC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1096, 0X1AEC));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x1AEC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1096, 0X1AEC));
;}
RECOMP_FUNC void func_800B5654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5654: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B5658: bne         $a1, $at, L_800B5670
    if (ctx->r5 != ctx->r1) {
        // 0x800B565C: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800B5670;
    }
    // 0x800B565C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B5660: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B5664: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5668: jr          $ra
    // 0x800B566C: sb          $t6, 0x7F1C($at)
    MEM_B(0X7F1C, ctx->r1) = ctx->r14;
    return;
    // 0x800B566C: sb          $t6, 0x7F1C($at)
    MEM_B(0X7F1C, ctx->r1) = ctx->r14;
L_800B5670:
    // 0x800B5670: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5674: sb          $zero, 0x7F1C($at)
    MEM_B(0X7F1C, ctx->r1) = 0;
    // 0x800B5678: jr          $ra
    // 0x800B567C: nop

    return;
    // 0x800B567C: nop

;}
