#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void sumumbofx_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080105C: jal         0x800C8B84
    // 0x80801060: lh          $a0, 0x5E($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X5E);
    func_800C8B84(rdram, ctx);
        goto after_0;
    // 0x80801060: lh          $a0, 0x5E($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X5E);
    after_0:
    // 0x80801064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080106C: jr          $ra
    // 0x80801070: nop

    return;
    // 0x80801070: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_37(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082CE8: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082CE8);
    return;
    // 0x80082CEC: addi        $t0, $zero, 0x94
    ctx->r8 = ADD32(0, 0X94);
;}
RECOMP_FUNC void func_80800104_chjadestatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080010C: jal         0x80101870
    // 0x80800110: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800110: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800114: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x8080011C: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x80800120: bgezl       $t8, L_80800134
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800124: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800134;
    }
    goto skip_0;
    // 0x80800124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800128: jal         0x80103110
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x8080012C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800134:
    // 0x80800134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800138: jr          $ra
    // 0x8080013C: nop

    return;
    // 0x8080013C: nop

;}
RECOMP_FUNC void func_808007EC_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808007F0: jr          $ra
    // 0x808007F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808007F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80800A58_chphlegm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A58: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800A5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A60: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1064, 0XCD8) << 16);
    // 0x80800A64: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1064, 0XCC4) << 16);
    // 0x80800A68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A6C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80800A70: addiu       $a2, $a2, 0xCC4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1064, 0XCC4));
    // 0x80800A74: jal         0x80089D18
    // 0x80800A78: addiu       $a1, $a1, 0xCD8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1064, 0XCD8));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800A78: addiu       $a1, $a1, 0xCD8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1064, 0XCD8));
    after_0:
    // 0x80800A7C: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
    // 0x80800A80: jal         0x8008FE68
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008FE68(rdram, ctx);
        goto after_1;
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800A88: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800A8C: jal         0x800EE7F8
    // 0x80800A90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800A90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800A94: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800A98: jal         0x800EE7F8
    // 0x80800A9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800A9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80800AA0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1064, 0XB38) << 16);
    // 0x80800AA4: lwc1        $f6, 0xB38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1064, 0XB38));
    // 0x80800AA8: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800AAC: addiu       $a0, $zero, 0x398
    ctx->r4 = ADD32(0, 0X398);
    // 0x80800AB0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800AB4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800AB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800ABC: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x80800AC0: jal         0x80108528
    // 0x80800AC4: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    func_80108528(rdram, ctx);
        goto after_4;
    // 0x80800AC4: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80800AC8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800ACC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800AD0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800AD4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800AD8: jal         0x800DC178
    // 0x80800ADC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800ADC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_5:
    // 0x80800AE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800AE4: jal         0x80102FDC
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_6;
    // 0x80800AE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800AEC: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800AF0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800AF4: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800AF8: jal         0x800EFB24
    // 0x80800AFC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800EFB24(rdram, ctx);
        goto after_7;
    // 0x80800AFC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_7:
    // 0x80800B00: lui         $a1, 0x455A
    ctx->r5 = S32(0X455A << 16);
    // 0x80800B04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800B08: jal         0x800EF368
    // 0x80800B0C: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    func_800EF368(rdram, ctx);
        goto after_8;
    // 0x80800B0C: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    after_8:
    // 0x80800B10: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800B14: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800B18: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800B1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B24: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800B28: jr          $ra
    // 0x80800B2C: nop

    return;
    // 0x80800B2C: nop

;}
RECOMP_FUNC void func_8010381C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010381C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80103820: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80103824: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80103828: lw          $t6, 0x70($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X70);
    // 0x8010382C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80103830: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80103834: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x80103838: bgezl       $t8, L_80103920
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8010383C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80103920;
    }
    goto skip_0;
    // 0x8010383C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80103840: lh          $a0, 0x60($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X60);
    // 0x80103844: beql        $a0, $zero, L_80103860
    if (ctx->r4 == 0) {
        // 0x80103848: lw          $a0, 0x4($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X4);
            goto L_80103860;
    }
    goto skip_1;
    // 0x80103848: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x8010384C: jal         0x80100E18
    // 0x80103850: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80100E18(rdram, ctx);
        goto after_0;
    // 0x80103850: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80103854: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80103858: sh          $zero, 0x60($s0)
    MEM_H(0X60, ctx->r16) = 0;
    // 0x8010385C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
L_80103860:
    // 0x80103860: beql        $a0, $zero, L_8010387C
    if (ctx->r4 == 0) {
        // 0x80103864: lh          $t9, 0x90($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X90);
            goto L_8010387C;
    }
    goto skip_2;
    // 0x80103864: lh          $t9, 0x90($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X90);
    skip_2:
    // 0x80103868: jal         0x800DBFD8
    // 0x8010386C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800DBFD8(rdram, ctx);
        goto after_1;
    // 0x8010386C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80103870: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80103874: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80103878: lh          $t9, 0x90($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X90);
L_8010387C:
    // 0x8010387C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80103880: beql        $t9, $zero, L_80103898
    if (ctx->r25 == 0) {
        // 0x80103884: lh          $a0, 0x10($v0)
        ctx->r4 = MEM_H(ctx->r2, 0X10);
            goto L_80103898;
    }
    goto skip_3;
    // 0x80103884: lh          $a0, 0x10($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X10);
    skip_3:
    // 0x80103888: jal         0x80106138
    // 0x8010388C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80106138(rdram, ctx);
        goto after_2;
    // 0x8010388C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x80103890: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80103894: lh          $a0, 0x10($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X10);
L_80103898:
    // 0x80103898: beql        $a0, $zero, L_801038B4
    if (ctx->r4 == 0) {
        // 0x8010389C: lhu         $v0, 0x80($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X80);
            goto L_801038B4;
    }
    goto skip_4;
    // 0x8010389C: lhu         $v0, 0x80($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X80);
    skip_4:
    // 0x801038A0: jal         0x800ADFE0
    // 0x801038A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800ADFE0(rdram, ctx);
        goto after_3;
    // 0x801038A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x801038A8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801038AC: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x801038B0: lhu         $v0, 0x80($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X80);
L_801038B4:
    // 0x801038B4: beq         $v0, $zero, L_801038CC
    if (ctx->r2 == 0) {
        // 0x801038B8: sll         $a0, $v0, 16
        ctx->r4 = S32(ctx->r2 << 16);
            goto L_801038CC;
    }
    // 0x801038B8: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x801038BC: sra         $t0, $a0, 16
    ctx->r8 = S32(SIGNED(ctx->r4) >> 16);
    // 0x801038C0: jal         0x800D8954
    // 0x801038C4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800D8954(rdram, ctx);
        goto after_4;
    // 0x801038C4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_4:
    // 0x801038C8: sh          $zero, 0x80($s0)
    MEM_H(0X80, ctx->r16) = 0;
L_801038CC:
    // 0x801038CC: lb          $t2, 0x75($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X75);
    // 0x801038D0: bgezl       $t2, L_801038F0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801038D4: lh          $t4, 0x8E($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X8E);
            goto L_801038F0;
    }
    goto skip_5;
    // 0x801038D4: lh          $t4, 0x8E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X8E);
    skip_5:
    // 0x801038D8: lh          $t3, 0x8C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X8C);
    // 0x801038DC: beql        $t3, $zero, L_801038F0
    if (ctx->r11 == 0) {
        // 0x801038E0: lh          $t4, 0x8E($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X8E);
            goto L_801038F0;
    }
    goto skip_6;
    // 0x801038E0: lh          $t4, 0x8E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X8E);
    skip_6:
    // 0x801038E4: jal         0x80104328
    // 0x801038E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104328(rdram, ctx);
        goto after_5;
    // 0x801038E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801038EC: lh          $t4, 0x8E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X8E);
L_801038F0:
    // 0x801038F0: beql        $t4, $zero, L_80103904
    if (ctx->r12 == 0) {
        // 0x801038F4: lbu         $t5, 0x73($s0)
        ctx->r13 = MEM_BU(ctx->r16, 0X73);
            goto L_80103904;
    }
    goto skip_7;
    // 0x801038F4: lbu         $t5, 0x73($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X73);
    skip_7:
    // 0x801038F8: jal         0x80104504
    // 0x801038FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104504(rdram, ctx);
        goto after_6;
    // 0x801038FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80103900: lbu         $t5, 0x73($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X73);
L_80103904:
    // 0x80103904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80103908: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x8010390C: andi        $t6, $t5, 0xFFF7
    ctx->r14 = ctx->r13 & 0XFFF7;
    // 0x80103910: sb          $t6, 0x73($s0)
    MEM_B(0X73, ctx->r16) = ctx->r14;
    // 0x80103914: jal         0x8010108C
    // 0x80103918: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_7;
    // 0x80103918: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8010391C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80103920:
    // 0x80103920: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80103924: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80103928: jr          $ra
    // 0x8010392C: nop

    return;
    // 0x8010392C: nop

;}
RECOMP_FUNC void func_801015C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801015C8: jr          $ra
    // 0x801015CC: nop

    return;
    // 0x801015CC: nop

;}
RECOMP_FUNC void func_8080030C_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080030C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80800310: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800314: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800318: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080031C: jal         0x80100094
    // 0x80800320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800324: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80800328: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x8080032C: jal         0x80803D98
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803D98_chweldarboss(rdram, ctx);
        goto after_1;
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800334: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080033C: jal         0x8080367C
    // 0x80800340: sh          $v0, 0x78($t6)
    MEM_H(0X78, ctx->r14) = ctx->r2;
    func_8080367C_chweldarboss(rdram, ctx);
        goto after_2;
    // 0x80800340: sh          $v0, 0x78($t6)
    MEM_H(0X78, ctx->r14) = ctx->r2;
    after_2:
    // 0x80800344: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x80800348: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x8080034C: jal         0x800F5A00
    // 0x80800350: lh          $a0, 0x78($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X78);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x80800350: lh          $a0, 0x78($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X78);
    after_3:
    // 0x80800354: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x80800358: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x8080035C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800360: sltiu       $at, $t0, 0x30
    ctx->r1 = ctx->r8 < 0X30 ? 1 : 0;
    // 0x80800364: beq         $at, $zero, L_80801464
    if (ctx->r1 == 0) {
        // 0x80800368: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80801464;
    }
    // 0x80800368: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8080036C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4280) << 16);
    // 0x80800370: addu        $at, $at, $t0
    gpr jr_addend_80800378 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800374: lw          $t0, 0x4280($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4280));
    // 0x80800378: jr          $t0
    // 0x8080037C: nop

    switch (jr_addend_80800378 >> 2) {
        case 0: goto L_80800380; break;
        case 1: goto L_808003D8; break;
        case 2: goto L_80800408; break;
        case 3: goto L_80800494; break;
        case 4: goto L_808004B4; break;
        case 5: goto L_80801464; break;
        case 6: goto L_808004E4; break;
        case 7: goto L_808005E8; break;
        case 8: goto L_80800684; break;
        case 9: goto L_808006F8; break;
        case 10: goto L_80800720; break;
        case 11: goto L_80800738; break;
        case 12: goto L_8080074C; break;
        case 13: goto L_80800784; break;
        case 14: goto L_80801464; break;
        case 15: goto L_80800804; break;
        case 16: goto L_8080082C; break;
        case 17: goto L_80800878; break;
        case 18: goto L_80800914; break;
        case 19: goto L_808009AC; break;
        case 20: goto L_80800A0C; break;
        case 21: goto L_80800A34; break;
        case 22: goto L_80800A4C; break;
        case 23: goto L_80800A60; break;
        case 24: goto L_80800A94; break;
        case 25: goto L_80800AB4; break;
        case 26: goto L_80800ADC; break;
        case 27: goto L_80800B24; break;
        case 28: goto L_80800B80; break;
        case 29: goto L_80800CF0; break;
        case 30: goto L_80800E04; break;
        case 31: goto L_80800E2C; break;
        case 32: goto L_80800F24; break;
        case 33: goto L_80800F80; break;
        case 34: goto L_8080105C; break;
        case 35: goto L_808011C8; break;
        case 36: goto L_808011F4; break;
        case 37: goto L_8080121C; break;
        case 38: goto L_80801234; break;
        case 39: goto L_80801248; break;
        case 40: goto L_80801274; break;
        case 41: goto L_808012C4; break;
        case 42: goto L_808012EC; break;
        case 43: goto L_80801464; break;
        case 44: goto L_80801324; break;
        case 45: goto L_80801334; break;
        case 46: goto L_8080141C; break;
        case 47: goto L_8080144C; break;
        default: switch_error(__func__, 0x80800378, 0x80804280);
    }
    // 0x8080037C: nop

L_80800380:
    // 0x80800380: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800384: jal         0x8010CA74
    // 0x80800388: addiu       $a1, $zero, 0x1B58
    ctx->r5 = ADD32(0, 0X1B58);
    func_8010CA74(rdram, ctx);
        goto after_4;
    // 0x80800388: addiu       $a1, $zero, 0x1B58
    ctx->r5 = ADD32(0, 0X1B58);
    after_4:
    // 0x8080038C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800390: nop
    
            goto L_80801464;
    }
    // 0x80800390: nop

    // 0x80800394: jal         0x800F54E4
    // 0x80800398: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800398: nop

    after_5:
    // 0x8080039C: jal         0x80803B48
    // 0x808003A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80803B48_chweldarboss(rdram, ctx);
        goto after_6;
    // 0x808003A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x808003A4: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x808003A8: nop
    
            goto L_80801464;
    }
    // 0x808003A8: nop

    // 0x808003AC: jal         0x800F54E4
    // 0x808003B0: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x808003B0: nop

    after_7:
    // 0x808003B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003B8: jal         0x800F64A4
    // 0x808003BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F64A4(rdram, ctx);
        goto after_8;
    // 0x808003BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x808003C0: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x808003C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C8: jal         0x80801AA0
    // 0x808003CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_9;
    // 0x808003CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x808003D0: b           L_80801464
    // 0x808003D4: nop

        goto L_80801464;
    // 0x808003D4: nop

L_808003D8:
    // 0x808003D8: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x808003DC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808003E0: addiu       $a0, $zero, 0x431
    ctx->r4 = ADD32(0, 0X431);
    // 0x808003E4: lbu         $t2, 0x70($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X70);
    // 0x808003E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808003EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808003F0: bne         $t2, $zero, L_80801464
    if (ctx->r10 != 0) {
        // 0x808003F4: nop
    
            goto L_80801464;
    }
    // 0x808003F4: nop

    // 0x808003F8: jal         0x80101180
    // 0x808003FC: sb          $t3, 0x70($t1)
    MEM_B(0X70, ctx->r9) = ctx->r11;
    func_80101180(rdram, ctx);
        goto after_10;
    // 0x808003FC: sb          $t3, 0x70($t1)
    MEM_B(0X70, ctx->r9) = ctx->r11;
    after_10:
    // 0x80800400: b           L_80801464
    // 0x80800404: nop

        goto L_80801464;
    // 0x80800404: nop

L_80800408:
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080040C: jal         0x80802C9C
    // 0x80800410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802C9C_chweldarboss(rdram, ctx);
        goto after_11;
    // 0x80800410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800414: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800418: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080041C: nop

    // 0x80800420: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800424: jal         0x800D8FF8
    // 0x80800428: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_12;
    // 0x80800428: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x8080042C: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800430: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800434: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800438: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8080043C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800440: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800444: jal         0x800EF1B8
    // 0x80800448: nop

    func_800EF1B8(rdram, ctx);
        goto after_13;
    // 0x80800448: nop

    after_13:
    // 0x8080044C: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x80800450: jal         0x800D9078
    // 0x80800454: addiu       $a0, $a0, 0xB4
    ctx->r4 = ADD32(ctx->r4, 0XB4);
    func_800D9078(rdram, ctx);
        goto after_14;
    // 0x80800454: addiu       $a0, $a0, 0xB4
    ctx->r4 = ADD32(ctx->r4, 0XB4);
    after_14:
    // 0x80800458: beq         $v0, $zero, L_8080046C
    if (ctx->r2 == 0) {
        // 0x8080045C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080046C;
    }
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: addiu       $a1, $zero, 0x1366
    ctx->r5 = ADD32(0, 0X1366);
    // 0x80800464: jal         0x80802214
    // 0x80800468: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_15;
    // 0x80800468: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_15:
L_8080046C:
    // 0x8080046C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800470: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80800474: jal         0x800F0064
    // 0x80800478: lw          $a2, 0x94($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X94);
    func_800F0064(rdram, ctx);
        goto after_16;
    // 0x80800478: lw          $a2, 0x94($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X94);
    after_16:
    // 0x8080047C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800480: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800484: jal         0x80801AA0
    // 0x80800488: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_17;
    // 0x80800488: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_17:
    // 0x8080048C: b           L_80801464
    // 0x80800490: nop

        goto L_80801464;
    // 0x80800490: nop

L_80800494:
    // 0x80800494: jal         0x80101DDC
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_18;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080049C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x808004A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: jal         0x80801AA0
    // 0x808004A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_19;
    // 0x808004A8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_19:
    // 0x808004AC: b           L_80801464
    // 0x808004B0: nop

        goto L_80801464;
    // 0x808004B0: nop

L_808004B4:
    // 0x808004B4: jal         0x800DA298
    // 0x808004B8: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    func_800DA298(rdram, ctx);
        goto after_20;
    // 0x808004B8: addiu       $a0, $zero, 0x6AD
    ctx->r4 = ADD32(0, 0X6AD);
    after_20:
    // 0x808004BC: bne         $v0, $zero, L_80801464
    if (ctx->r2 != 0) {
        // 0x808004C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C4: addiu       $a1, $zero, 0x1355
    ctx->r5 = ADD32(0, 0X1355);
    // 0x808004C8: jal         0x80802214
    // 0x808004CC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_21;
    // 0x808004CC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_21:
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D4: jal         0x80801AA0
    // 0x808004D8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_22;
    // 0x808004D8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_22:
    // 0x808004DC: b           L_80801464
    // 0x808004E0: nop

        goto L_80801464;
    // 0x808004E0: nop

L_808004E4:
    // 0x808004E4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808004E8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X4AE0) << 16);
    // 0x808004EC: addiu       $a2, $a2, 0x4AE0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X4AE0));
    // 0x808004F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808004F4: jal         0x800F0064
    // 0x808004F8: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    func_800F0064(rdram, ctx);
        goto after_23;
    // 0x808004F8: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    after_23:
    // 0x808004FC: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: jal         0x80802F14
    // 0x80800508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_24;
    // 0x80800508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x8080050C: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800514: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800518: bne         $t4, $zero, L_808005BC
    if (ctx->r12 != 0) {
        // 0x8080051C: nop
    
            goto L_808005BC;
    }
    // 0x8080051C: nop

    // 0x80800520: jal         0x800D8FF8
    // 0x80800524: nop

    func_800D8FF8(rdram, ctx);
        goto after_25;
    // 0x80800524: nop

    after_25:
    // 0x80800528: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800530: jal         0x80802C9C
    // 0x80800534: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802C9C_chweldarboss(rdram, ctx);
        goto after_26;
    // 0x80800534: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80800538: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8080053C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800548: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080054C: jal         0x80802C9C
    // 0x80800550: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    func_80802C9C_chweldarboss(rdram, ctx);
        goto after_27;
    // 0x80800550: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    after_27:
    // 0x80800554: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800558: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080055C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1360, 0X4AE0) << 16);
    // 0x80800560: addiu       $a1, $a1, 0x4AE0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4AE0));
    // 0x80800564: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080056C: jal         0x80102D78
    // 0x80800570: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    func_80102D78(rdram, ctx);
        goto after_28;
    // 0x80800570: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    after_28:
    // 0x80800574: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800578: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8080057C: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80800580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800584: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800588: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8080058C: jal         0x80102B2C
    // 0x80800590: nop

    func_80102B2C(rdram, ctx);
        goto after_29;
    // 0x80800590: nop

    after_29:
    // 0x80800594: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80800598: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8080059C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005A0: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808005A4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808005A8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808005AC: jal         0x800EF1B8
    // 0x808005B0: nop

    func_800EF1B8(rdram, ctx);
        goto after_30;
    // 0x808005B0: nop

    after_30:
    // 0x808005B4: b           L_80801464
    // 0x808005B8: nop

        goto L_80801464;
    // 0x808005B8: nop

L_808005BC:
    // 0x808005BC: jal         0x80101E14
    // 0x808005C0: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_31;
    // 0x808005C0: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_31:
    // 0x808005C4: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x808005C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005CC: jal         0x80801AA0
    // 0x808005D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_32;
    // 0x808005D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_32:
    // 0x808005D4: jal         0x808033D8
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808033D8_chweldarboss(rdram, ctx);
        goto after_33;
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x808005DC: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x808005E0: b           L_80801464
    // 0x808005E4: sb          $v0, 0x63($t5)
    MEM_B(0X63, ctx->r13) = ctx->r2;
        goto L_80801464;
    // 0x808005E4: sb          $v0, 0x63($t5)
    MEM_B(0X63, ctx->r13) = ctx->r2;
L_808005E8:
    // 0x808005E8: jal         0x800D8FF8
    // 0x808005EC: nop

    func_800D8FF8(rdram, ctx);
        goto after_34;
    // 0x808005EC: nop

    after_34:
    // 0x808005F0: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F8: jal         0x80802C9C
    // 0x808005FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80802C9C_chweldarboss(rdram, ctx);
        goto after_35;
    // 0x808005FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_35:
    // 0x80800600: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800604: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800608: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x8080060C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800610: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800614: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x80800618: jal         0x8010CD50
    // 0x8080061C: lh          $a1, 0x78($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X78);
    func_8010CD50(rdram, ctx);
        goto after_36;
    // 0x8080061C: lh          $a1, 0x78($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X78);
    after_36:
    // 0x80800620: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800624: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80800628: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800634: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800638: jal         0x80102B2C
    // 0x8080063C: nop

    func_80102B2C(rdram, ctx);
        goto after_37;
    // 0x8080063C: nop

    after_37:
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800644: jal         0x80802F14
    // 0x80800648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_38;
    // 0x80800648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800650: jal         0x80102CF4
    // 0x80800654: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_80102CF4(rdram, ctx);
        goto after_39;
    // 0x80800654: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_39:
    // 0x80800658: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x8080065C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x8080065C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800660: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800664: jal         0x80101E14
    // 0x80800668: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_40;
    // 0x80800668: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_40:
    // 0x8080066C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800670: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800674: jal         0x80801AA0
    // 0x80800678: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_41;
    // 0x80800678: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_41:
    // 0x8080067C: b           L_80801464
    // 0x80800680: nop

        goto L_80801464;
    // 0x80800680: nop

L_80800684:
    // 0x80800684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800688: jal         0x80802F14
    // 0x8080068C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_42;
    // 0x8080068C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_42:
    // 0x80800690: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800694: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800698: jal         0x80101E14
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_43;
    // 0x8080069C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x808006A0: beq         $v0, $zero, L_808006B0
    if (ctx->r2 == 0) {
        // 0x808006A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006B0;
    }
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006A8: jal         0x80108B04
    // 0x808006AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_44;
    // 0x808006AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_44:
L_808006B0:
    // 0x808006B0: jal         0x80101DDC
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_45;
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x808006B8: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x808006BC: lw          $t7, 0x94($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X94);
            goto L_80801464;
    }
    // 0x808006BC: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x808006C0: lbu         $t8, 0x63($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X63);
    // 0x808006C4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006CC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x808006D0: bne         $t9, $zero, L_808006E8
    if (ctx->r25 != 0) {
        // 0x808006D4: sb          $t9, 0x63($t7)
        MEM_B(0X63, ctx->r15) = ctx->r25;
            goto L_808006E8;
    }
    // 0x808006D4: sb          $t9, 0x63($t7)
    MEM_B(0X63, ctx->r15) = ctx->r25;
    // 0x808006D8: jal         0x80801AA0
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_46;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x808006E0: b           L_80801464
    // 0x808006E4: nop

        goto L_80801464;
    // 0x808006E4: nop

L_808006E8:
    // 0x808006E8: jal         0x80801AA0
    // 0x808006EC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_47;
    // 0x808006EC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_47:
    // 0x808006F0: b           L_80801464
    // 0x808006F4: nop

        goto L_80801464;
    // 0x808006F4: nop

L_808006F8:
    // 0x808006F8: jal         0x80802E80
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802E80_chweldarboss(rdram, ctx);
        goto after_48;
    // 0x808006FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x80800700: jal         0x80101DDC
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_49;
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x80800708: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x8080070C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x8080070C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800710: jal         0x80801AA0
    // 0x80800714: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_50;
    // 0x80800714: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_50:
    // 0x80800718: b           L_80801464
    // 0x8080071C: nop

        goto L_80801464;
    // 0x8080071C: nop

L_80800720:
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800724: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800728: jal         0x80802D2C
    // 0x8080072C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_80802D2C_chweldarboss(rdram, ctx);
        goto after_51;
    // 0x8080072C: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_51:
    // 0x80800730: b           L_80801464
    // 0x80800734: nop

        goto L_80801464;
    // 0x80800734: nop

L_80800738:
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080073C: jal         0x80802FE4
    // 0x80800740: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80802FE4_chweldarboss(rdram, ctx);
        goto after_52;
    // 0x80800740: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_52:
    // 0x80800744: b           L_80801464
    // 0x80800748: nop

        goto L_80801464;
    // 0x80800748: nop

L_8080074C:
    // 0x8080074C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800750: jal         0x80802F14
    // 0x80800754: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_53;
    // 0x80800754: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_53:
    // 0x80800758: jal         0x80101DDC
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_54;
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x80800760: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800764: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800768: jal         0x80801AA0
    // 0x8080076C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_55;
    // 0x8080076C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_55:
    // 0x80800770: jal         0x808033D8
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808033D8_chweldarboss(rdram, ctx);
        goto after_56;
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x80800778: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x8080077C: b           L_80801464
    // 0x80800780: sb          $v0, 0x63($t0)
    MEM_B(0X63, ctx->r8) = ctx->r2;
        goto L_80801464;
    // 0x80800780: sb          $v0, 0x63($t0)
    MEM_B(0X63, ctx->r8) = ctx->r2;
L_80800784:
    // 0x80800784: jal         0x80101DDC
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_57;
    // 0x80800788: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_57:
    // 0x8080078C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800790: nop
    
            goto L_80801464;
    }
    // 0x80800790: nop

    // 0x80800794: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80800798: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8080079C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A0: lbu         $t2, 0x7C($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X7C);
    // 0x808007A4: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x808007A8: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x808007AC: bne         $t2, $zero, L_808007E0
    if (ctx->r10 != 0) {
        // 0x808007B0: nop
    
            goto L_808007E0;
    }
    // 0x808007B0: nop

    // 0x808007B4: jal         0x80803CF0
    // 0x808007B8: sb          $t3, 0x7C($v0)
    MEM_B(0X7C, ctx->r2) = ctx->r11;
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_58;
    // 0x808007B8: sb          $t3, 0x7C($v0)
    MEM_B(0X7C, ctx->r2) = ctx->r11;
    after_58:
    // 0x808007BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C0: addiu       $a1, $zero, 0x1359
    ctx->r5 = ADD32(0, 0X1359);
    // 0x808007C4: jal         0x80802214
    // 0x808007C8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_80802214_chweldarboss(rdram, ctx);
        goto after_59;
    // 0x808007C8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_59:
    // 0x808007CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D0: jal         0x80801AA0
    // 0x808007D4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_60;
    // 0x808007D4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_60:
    // 0x808007D8: b           L_80801464
    // 0x808007DC: nop

        goto L_80801464;
    // 0x808007DC: nop

L_808007E0:
    // 0x808007E0: jal         0x80803D64
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803D64_chweldarboss(rdram, ctx);
        goto after_61;
    // 0x808007E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_61:
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007EC: jal         0x80801AA0
    // 0x808007F0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_62;
    // 0x808007F0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_62:
    // 0x808007F4: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x808007F8: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x808007FC: b           L_80801464
    // 0x80800800: sb          $t1, 0x63($t4)
    MEM_B(0X63, ctx->r12) = ctx->r9;
        goto L_80801464;
    // 0x80800800: sb          $t1, 0x63($t4)
    MEM_B(0X63, ctx->r12) = ctx->r9;
L_80800804:
    // 0x80800804: jal         0x808032A8
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808032A8_chweldarboss(rdram, ctx);
        goto after_63;
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x8080080C: jal         0x80101DDC
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_64;
    // 0x80800810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
    // 0x80800814: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800818: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080081C: jal         0x80801AA0
    // 0x80800820: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_65;
    // 0x80800820: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_65:
    // 0x80800824: b           L_80801464
    // 0x80800828: nop

        goto L_80801464;
    // 0x80800828: nop

L_8080082C:
    // 0x8080082C: jal         0x800D9078
    // 0x80800830: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_66;
    // 0x80800830: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_66:
    // 0x80800834: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800838: lw          $t5, 0x94($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X94);
            goto L_80801464;
    }
    // 0x80800838: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8080083C: lh          $a0, 0x76($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X76);
    // 0x80800840: jal         0x800F82D4
    // 0x80800844: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_67;
    // 0x80800844: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_67:
    // 0x80800848: jal         0x80803D64
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803D64_chweldarboss(rdram, ctx);
        goto after_68;
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_68:
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800854: jal         0x80801AA0
    // 0x80800858: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_69;
    // 0x80800858: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_69:
    // 0x8080085C: jal         0x808033D8
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808033D8_chweldarboss(rdram, ctx);
        goto after_70;
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_70:
    // 0x80800864: lw          $v1, 0x94($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X94);
    // 0x80800868: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080086C: sb          $v0, 0x63($v1)
    MEM_B(0X63, ctx->r3) = ctx->r2;
    // 0x80800870: b           L_80801464
    // 0x80800874: sh          $t6, 0x76($v1)
    MEM_H(0X76, ctx->r3) = ctx->r14;
        goto L_80801464;
    // 0x80800874: sh          $t6, 0x76($v1)
    MEM_H(0X76, ctx->r3) = ctx->r14;
L_80800878:
    // 0x80800878: jal         0x800D8FF8
    // 0x8080087C: nop

    func_800D8FF8(rdram, ctx);
        goto after_71;
    // 0x8080087C: nop

    after_71:
    // 0x80800880: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800888: jal         0x80802C9C
    // 0x8080088C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80802C9C_chweldarboss(rdram, ctx);
        goto after_72;
    // 0x8080088C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_72:
    // 0x80800890: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800894: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800898: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8080089C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008A0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808008A4: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x808008A8: jal         0x8010CD50
    // 0x808008AC: lh          $a1, 0x78($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X78);
    func_8010CD50(rdram, ctx);
        goto after_73;
    // 0x808008AC: lh          $a1, 0x78($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X78);
    after_73:
    // 0x808008B0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808008B4: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x808008B8: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808008BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808008C4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808008C8: jal         0x80102B2C
    // 0x808008CC: nop

    func_80102B2C(rdram, ctx);
        goto after_74;
    // 0x808008CC: nop

    after_74:
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D4: jal         0x80802F14
    // 0x808008D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_75;
    // 0x808008D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_75:
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E0: jal         0x80102CF4
    // 0x808008E4: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_80102CF4(rdram, ctx);
        goto after_76;
    // 0x808008E4: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_76:
    // 0x808008E8: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x808008EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F0: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x808008F4: jal         0x80101E14
    // 0x808008F8: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    func_80101E14(rdram, ctx);
        goto after_77;
    // 0x808008F8: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    after_77:
    // 0x808008FC: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800900: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800904: jal         0x80801AA0
    // 0x80800908: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_78;
    // 0x80800908: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_78:
    // 0x8080090C: b           L_80801464
    // 0x80800910: nop

        goto L_80801464;
    // 0x80800910: nop

L_80800914:
    // 0x80800914: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800918: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080091C: jal         0x80101E14
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_79;
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_79:
    // 0x80800924: beq         $v0, $zero, L_8080095C
    if (ctx->r2 == 0) {
        // 0x80800928: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080095C;
    }
    // 0x80800928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080092C: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x80800930: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X4854) << 16);
    // 0x80800934: addiu       $a2, $a2, 0x4854
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X4854));
    // 0x80800938: jal         0x80089D18
    // 0x8080093C: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_80;
    // 0x8080093C: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_80:
    // 0x80800940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800944: jal         0x80108B04
    // 0x80800948: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80108B04(rdram, ctx);
        goto after_81;
    // 0x80800948: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_81:
    // 0x8080094C: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x80800950: lbu         $t9, 0x63($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X63);
    // 0x80800954: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800958: sb          $t0, 0x63($t7)
    MEM_B(0X63, ctx->r15) = ctx->r8;
L_8080095C:
    // 0x8080095C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800960: jal         0x80802F14
    // 0x80800964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_82;
    // 0x80800964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_82:
    // 0x80800968: jal         0x80101DDC
    // 0x8080096C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_83;
    // 0x8080096C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_83:
    // 0x80800970: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800974: lw          $t2, 0x94($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X94);
            goto L_80801464;
    }
    // 0x80800974: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80800978: lbu         $t3, 0x63($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X63);
    // 0x8080097C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800984: bne         $t3, $zero, L_8080099C
    if (ctx->r11 != 0) {
        // 0x80800988: nop
    
            goto L_8080099C;
    }
    // 0x80800988: nop

    // 0x8080098C: jal         0x80801AA0
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_84;
    // 0x80800990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_84:
    // 0x80800994: b           L_80801464
    // 0x80800998: nop

        goto L_80801464;
    // 0x80800998: nop

L_8080099C:
    // 0x8080099C: jal         0x80801AA0
    // 0x808009A0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_85;
    // 0x808009A0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_85:
    // 0x808009A4: b           L_80801464
    // 0x808009A8: nop

        goto L_80801464;
    // 0x808009A8: nop

L_808009AC:
    // 0x808009AC: jal         0x80089C68
    // 0x808009B0: addiu       $a0, $zero, 0x43F
    ctx->r4 = ADD32(0, 0X43F);
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_86;
    // 0x808009B0: addiu       $a0, $zero, 0x43F
    ctx->r4 = ADD32(0, 0X43F);
    after_86:
    // 0x808009B4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808009B8: jal         0x80089C68
    // 0x808009BC: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_87;
    // 0x808009BC: addiu       $a0, $zero, 0x43E
    ctx->r4 = ADD32(0, 0X43E);
    after_87:
    // 0x808009C0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808009C4: jal         0x80089C68
    // 0x808009C8: addiu       $a0, $zero, 0x440
    ctx->r4 = ADD32(0, 0X440);
    _subaddiefind_entrypoint_9(rdram, ctx);
        goto after_88;
    // 0x808009C8: addiu       $a0, $zero, 0x440
    ctx->r4 = ADD32(0, 0X440);
    after_88:
    // 0x808009CC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x808009D0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x808009D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D8: addu        $t4, $v0, $t1
    ctx->r12 = ADD32(ctx->r2, ctx->r9);
    // 0x808009DC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x808009E0: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x808009E4: jal         0x80802F14
    // 0x808009E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_89;
    // 0x808009E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_89:
    // 0x808009EC: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009F4: bne         $t8, $zero, L_80801464
    if (ctx->r24 != 0) {
        // 0x808009F8: nop
    
            goto L_80801464;
    }
    // 0x808009F8: nop

    // 0x808009FC: jal         0x80801AA0
    // 0x80800A00: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_90;
    // 0x80800A00: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_90:
    // 0x80800A04: b           L_80801464
    // 0x80800A08: nop

        goto L_80801464;
    // 0x80800A08: nop

L_80800A0C:
    // 0x80800A0C: jal         0x80802E80
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802E80_chweldarboss(rdram, ctx);
        goto after_91;
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_91:
    // 0x80800A14: jal         0x80101DDC
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_92;
    // 0x80800A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_92:
    // 0x80800A1C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800A20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A24: jal         0x80801AA0
    // 0x80800A28: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_93;
    // 0x80800A28: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_93:
    // 0x80800A2C: b           L_80801464
    // 0x80800A30: nop

        goto L_80801464;
    // 0x80800A30: nop

L_80800A34:
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A38: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x80800A3C: jal         0x80802D2C
    // 0x80800A40: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    func_80802D2C_chweldarboss(rdram, ctx);
        goto after_94;
    // 0x80800A40: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    after_94:
    // 0x80800A44: b           L_80801464
    // 0x80800A48: nop

        goto L_80801464;
    // 0x80800A48: nop

L_80800A4C:
    // 0x80800A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A50: jal         0x80802FE4
    // 0x80800A54: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80802FE4_chweldarboss(rdram, ctx);
        goto after_95;
    // 0x80800A54: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_95:
    // 0x80800A58: b           L_80801464
    // 0x80800A5C: nop

        goto L_80801464;
    // 0x80800A5C: nop

L_80800A60:
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A64: jal         0x80802F14
    // 0x80800A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_96;
    // 0x80800A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_96:
    // 0x80800A6C: jal         0x80101DDC
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_97;
    // 0x80800A70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_97:
    // 0x80800A74: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800A78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A7C: jal         0x80801AA0
    // 0x80800A80: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_98;
    // 0x80800A80: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_98:
    // 0x80800A84: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x80800A88: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80800A8C: b           L_80801464
    // 0x80800A90: sb          $t9, 0x63($t0)
    MEM_B(0X63, ctx->r8) = ctx->r25;
        goto L_80801464;
    // 0x80800A90: sb          $t9, 0x63($t0)
    MEM_B(0X63, ctx->r8) = ctx->r25;
L_80800A94:
    // 0x80800A94: jal         0x80101DDC
    // 0x80800A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_99;
    // 0x80800A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_99:
    // 0x80800A9C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800AA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA4: jal         0x80801AA0
    // 0x80800AA8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_100;
    // 0x80800AA8: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_100:
    // 0x80800AAC: b           L_80801464
    // 0x80800AB0: nop

        goto L_80801464;
    // 0x80800AB0: nop

L_80800AB4:
    // 0x80800AB4: jal         0x808032A8
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808032A8_chweldarboss(rdram, ctx);
        goto after_101;
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_101:
    // 0x80800ABC: jal         0x80101DDC
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_102;
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_102:
    // 0x80800AC4: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800AC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ACC: jal         0x80801AA0
    // 0x80800AD0: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_103;
    // 0x80800AD0: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_103:
    // 0x80800AD4: b           L_80801464
    // 0x80800AD8: nop

        goto L_80801464;
    // 0x80800AD8: nop

L_80800ADC:
    // 0x80800ADC: jal         0x800D9078
    // 0x80800AE0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_104;
    // 0x80800AE0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_104:
    // 0x80800AE4: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800AE8: lw          $t7, 0x94($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X94);
            goto L_80801464;
    }
    // 0x80800AE8: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x80800AEC: lh          $a0, 0x76($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X76);
    // 0x80800AF0: jal         0x800F82D4
    // 0x80800AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_105;
    // 0x80800AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_105:
    // 0x80800AF8: jal         0x80803D64
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803D64_chweldarboss(rdram, ctx);
        goto after_106;
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_106:
    // 0x80800B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B04: jal         0x80801AA0
    // 0x80800B08: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_107;
    // 0x80800B08: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_107:
    // 0x80800B0C: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80800B10: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80800B14: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80800B18: sb          $t2, 0x63($v0)
    MEM_B(0X63, ctx->r2) = ctx->r10;
    // 0x80800B1C: b           L_80801464
    // 0x80800B20: sh          $t3, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r11;
        goto L_80801464;
    // 0x80800B20: sh          $t3, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r11;
L_80800B24:
    // 0x80800B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B28: jal         0x80802F14
    // 0x80800B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_108;
    // 0x80800B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_108:
    // 0x80800B30: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X47B8) << 16);
    // 0x80800B34: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x80800B38: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800B3C: addiu       $a2, $a2, 0x47B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X47B8));
    // 0x80800B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B44: jal         0x80089D20
    // 0x80800B48: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_109;
    // 0x80800B48: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_109:
    // 0x80800B4C: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x80800B50: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800B54: jal         0x80101E14
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_110;
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_110:
    // 0x80800B5C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800B60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B64: jal         0x80801AA0
    // 0x80800B68: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_111;
    // 0x80800B68: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_111:
    // 0x80800B6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4340) << 16);
    // 0x80800B70: lwc1        $f4, 0x4340($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4340));
    // 0x80800B74: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x80800B78: b           L_80801464
    // 0x80800B7C: swc1        $f4, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f4.u32l;
        goto L_80801464;
    // 0x80800B7C: swc1        $f4, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f4.u32l;
L_80800B80:
    // 0x80800B80: jal         0x800D8FF8
    // 0x80800B84: nop

    func_800D8FF8(rdram, ctx);
        goto after_112;
    // 0x80800B84: nop

    after_112:
    // 0x80800B88: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800B8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800B90: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80800B94: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800B98: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80800B9C: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80800BA0: jal         0x800D8FF8
    // 0x80800BA4: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_113;
    // 0x80800BA4: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    after_113:
    // 0x80800BA8: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x80800BAC: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800BB0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4344) << 16);
    // 0x80800BB4: lwc1        $f4, 0x5C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X5C);
    // 0x80800BB8: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800BBC: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80800BC0: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80800BC4: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x80800BC8: lh          $v0, 0x74($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X74);
    // 0x80800BCC: bne         $v0, $zero, L_80800C58
    if (ctx->r2 != 0) {
        // 0x80800BD0: nop
    
            goto L_80800C58;
    }
    // 0x80800BD0: nop

    // 0x80800BD4: lwc1        $f10, 0x4344($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4344));
    // 0x80800BD8: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800BDC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800BE0: nop

    // 0x80800BE4: bc1f        L_80800C58
    if (!c1cs) {
        // 0x80800BE8: nop
    
            goto L_80800C58;
    }
    // 0x80800BE8: nop

    // 0x80800BEC: jal         0x800EF030
    // 0x80800BF0: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    func_800EF030(rdram, ctx);
        goto after_114;
    // 0x80800BF0: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    after_114:
    // 0x80800BF4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4348) << 16);
    // 0x80800BF8: lwc1        $f4, 0x4348($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4348));
    // 0x80800BFC: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80800C00: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1360, 0X4AE0) << 16);
    // 0x80800C04: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800C08: nop

    // 0x80800C0C: bc1fl       L_80800C40
    if (!c1cs) {
        // 0x80800C10: lw          $t8, 0x94($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X94);
            goto L_80800C40;
    }
    goto skip_0;
    // 0x80800C10: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    skip_0:
    // 0x80800C14: jal         0x800F1DF4
    // 0x80800C18: addiu       $a1, $a1, 0x4AE0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4AE0));
    func_800F1DF4(rdram, ctx);
        goto after_115;
    // 0x80800C18: addiu       $a1, $a1, 0x4AE0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4AE0));
    after_115:
    // 0x80800C1C: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80800C20: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C24: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800C28: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x80800C2C: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80800C30: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    // 0x80800C34: jal         0x800EF1B8
    // 0x80800C38: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    func_800EF1B8(rdram, ctx);
        goto after_116;
    // 0x80800C38: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_116:
    // 0x80800C3C: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
L_80800C40:
    // 0x80800C40: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C48: jal         0x80803D64
    // 0x80800C4C: sh          $t6, 0x74($t8)
    MEM_H(0X74, ctx->r24) = ctx->r14;
    func_80803D64_chweldarboss(rdram, ctx);
        goto after_117;
    // 0x80800C4C: sh          $t6, 0x74($t8)
    MEM_H(0X74, ctx->r24) = ctx->r14;
    after_117:
    // 0x80800C50: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x80800C54: lh          $v0, 0x74($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X74);
L_80800C58:
    // 0x80800C58: beq         $v0, $zero, L_80800CB8
    if (ctx->r2 == 0) {
        // 0x80800C5C: addiu       $a0, $sp, 0x84
        ctx->r4 = ADD32(ctx->r29, 0X84);
            goto L_80800CB8;
    }
    // 0x80800C5C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80800C60: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800C64: jal         0x800EFC7C
    // 0x80800C68: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800EFC7C(rdram, ctx);
        goto after_118;
    // 0x80800C68: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_118:
    // 0x80800C6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X434C) << 16);
    // 0x80800C70: lwc1        $f6, 0x434C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X434C));
    // 0x80800C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C78: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800C7C: nop

    // 0x80800C80: bc1fl       L_80800CBC
    if (!c1cs) {
        // 0x80800C84: lw          $t0, 0x94($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X94);
            goto L_80800CBC;
    }
    goto skip_1;
    // 0x80800C84: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    skip_1:
    // 0x80800C88: jal         0x80102D78
    // 0x80800C8C: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    func_80102D78(rdram, ctx);
        goto after_119;
    // 0x80800C8C: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    after_119:
    // 0x80800C90: jal         0x800D8FF8
    // 0x80800C94: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_120;
    // 0x80800C94: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_120:
    // 0x80800C98: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800C9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800CA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800CA4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800CA8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800CAC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800CB0: jal         0x800EF1B8
    // 0x80800CB4: nop

    func_800EF1B8(rdram, ctx);
        goto after_121;
    // 0x80800CB4: nop

    after_121:
L_80800CB8:
    // 0x80800CB8: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
L_80800CBC:
    // 0x80800CBC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CC4: lwc1        $f4, 0x5C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X5C);
    // 0x80800CC8: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80800CCC: nop

    // 0x80800CD0: bc1f        L_80801464
    if (!c1cs) {
        // 0x80800CD4: nop
    
            goto L_80801464;
    }
    // 0x80800CD4: nop

    // 0x80800CD8: jal         0x80801AA0
    // 0x80800CDC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_122;
    // 0x80800CDC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_122:
    // 0x80800CE0: jal         0x8010A570
    // 0x80800CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_123;
    // 0x80800CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_123:
    // 0x80800CE8: b           L_80801464
    // 0x80800CEC: nop

        goto L_80801464;
    // 0x80800CEC: nop

L_80800CF0:
    // 0x80800CF0: jal         0x800D8FF8
    // 0x80800CF4: nop

    func_800D8FF8(rdram, ctx);
        goto after_124;
    // 0x80800CF4: nop

    after_124:
    // 0x80800CF8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800CFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800D00: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80800D04: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800D08: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80800D0C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80800D10: jal         0x800D8FF8
    // 0x80800D14: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_125;
    // 0x80800D14: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    after_125:
    // 0x80800D18: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x80800D1C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800D20: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4350) << 16);
    // 0x80800D24: lwc1        $f18, 0x5C($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X5C);
    // 0x80800D28: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80800D2C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800D30: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800D34: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800D38: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80800D3C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800D40: lwc1        $f10, 0x4350($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4350));
    // 0x80800D44: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800D48: nop

    // 0x80800D4C: bc1fl       L_80800DAC
    if (!c1cs) {
        // 0x80800D50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DAC;
    }
    goto skip_2;
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x80800D54: jal         0x800EFC7C
    // 0x80800D58: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800EFC7C(rdram, ctx);
        goto after_126;
    // 0x80800D58: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_126:
    // 0x80800D5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4354) << 16);
    // 0x80800D60: lwc1        $f18, 0x4354($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4354));
    // 0x80800D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D68: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80800D6C: nop

    // 0x80800D70: bc1fl       L_80800DAC
    if (!c1cs) {
        // 0x80800D74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DAC;
    }
    goto skip_3;
    // 0x80800D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x80800D78: jal         0x80102D78
    // 0x80800D7C: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    func_80102D78(rdram, ctx);
        goto after_127;
    // 0x80800D7C: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    after_127:
    // 0x80800D80: jal         0x800D8FF8
    // 0x80800D84: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_128;
    // 0x80800D84: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_128:
    // 0x80800D88: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800D8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800D90: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800D94: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D98: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800D9C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800DA0: jal         0x800EF1B8
    // 0x80800DA4: nop

    func_800EF1B8(rdram, ctx);
        goto after_129;
    // 0x80800DA4: nop

    after_129:
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800DAC:
    // 0x80800DAC: jal         0x80803528
    // 0x80800DB0: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    func_80803528_chweldarboss(rdram, ctx);
        goto after_130;
    // 0x80800DB0: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    after_130:
    // 0x80800DB4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800DB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800DBC: nop

    // 0x80800DC0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800DC4: nop

    // 0x80800DC8: bc1f        L_80801464
    if (!c1cs) {
        // 0x80800DCC: nop
    
            goto L_80801464;
    }
    // 0x80800DCC: nop

    // 0x80800DD0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DD8: jal         0x80802B1C
    // 0x80800DDC: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    func_80802B1C_chweldarboss(rdram, ctx);
        goto after_131;
    // 0x80800DDC: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    after_131:
    // 0x80800DE0: jal         0x808035D0
    // 0x80800DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808035D0_chweldarboss(rdram, ctx);
        goto after_132;
    // 0x80800DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_132:
    // 0x80800DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DEC: jal         0x80801AA0
    // 0x80800DF0: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_133;
    // 0x80800DF0: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_133:
    // 0x80800DF4: jal         0x8010A590
    // 0x80800DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_134;
    // 0x80800DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_134:
    // 0x80800DFC: b           L_80801464
    // 0x80800E00: nop

        goto L_80801464;
    // 0x80800E00: nop

L_80800E04:
    // 0x80800E04: jal         0x80101DDC
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_135;
    // 0x80800E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_135:
    // 0x80800E0C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800E10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E14: jal         0x80801AA0
    // 0x80800E18: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_136;
    // 0x80800E18: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_136:
    // 0x80800E1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800E20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800E24: b           L_80801464
    // 0x80800E28: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
        goto L_80801464;
    // 0x80800E28: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_80800E2C:
    // 0x80800E2C: jal         0x800D8FF8
    // 0x80800E30: nop

    func_800D8FF8(rdram, ctx);
        goto after_137;
    // 0x80800E30: nop

    after_137:
    // 0x80800E34: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80800E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E3C: jal         0x80802C9C
    // 0x80800E40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80802C9C_chweldarboss(rdram, ctx);
        goto after_138;
    // 0x80800E40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_138:
    // 0x80800E44: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80800E48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800E54: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800E58: jal         0x80802C9C
    // 0x80800E5C: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    func_80802C9C_chweldarboss(rdram, ctx);
        goto after_139;
    // 0x80800E5C: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    after_139:
    // 0x80800E60: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80800E64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800E68: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E70: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800E74: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x80800E78: jal         0x8010CD50
    // 0x80800E7C: lh          $a1, 0x78($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X78);
    func_8010CD50(rdram, ctx);
        goto after_140;
    // 0x80800E7C: lh          $a1, 0x78($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X78);
    after_140:
    // 0x80800E80: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800E84: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800E88: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E90: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800E94: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800E98: jal         0x80102B2C
    // 0x80800E9C: nop

    func_80102B2C(rdram, ctx);
        goto after_141;
    // 0x80800E9C: nop

    after_141:
    // 0x80800EA0: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800EA4: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800EA8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800EAC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800EB0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800EB4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800EB8: jal         0x800EF1B8
    // 0x80800EBC: nop

    func_800EF1B8(rdram, ctx);
        goto after_142;
    // 0x80800EBC: nop

    after_142:
    // 0x80800EC0: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x80800EC4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800EC8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800ECC: jal         0x800F0D50
    // 0x80800ED0: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    func_800F0D50(rdram, ctx);
        goto after_143;
    // 0x80800ED0: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    after_143:
    // 0x80800ED4: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x80800ED8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800EDC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80800EE0: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800EE4: jal         0x800F0D50
    // 0x80800EE8: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    func_800F0D50(rdram, ctx);
        goto after_144;
    // 0x80800EE8: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    after_144:
    // 0x80800EEC: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80800EF0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800EF4: sw          $t3, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r11;
    // 0x80800EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EFC: jal         0x80802F14
    // 0x80800F00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_145;
    // 0x80800F00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_145:
    // 0x80800F04: jal         0x800D90A4
    // 0x80800F08: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_146;
    // 0x80800F08: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_146:
    // 0x80800F0C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800F10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F14: jal         0x80801AA0
    // 0x80800F18: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_147;
    // 0x80800F18: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_147:
    // 0x80800F1C: b           L_80801464
    // 0x80800F20: nop

        goto L_80801464;
    // 0x80800F20: nop

L_80800F24:
    // 0x80800F24: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X47B8) << 16);
    // 0x80800F28: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x80800F2C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800F30: addiu       $a2, $a2, 0x47B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X47B8));
    // 0x80800F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F38: jal         0x80089D20
    // 0x80800F3C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_148;
    // 0x80800F3C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_148:
    // 0x80800F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F44: jal         0x80802F14
    // 0x80800F48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_149;
    // 0x80800F48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_149:
    // 0x80800F4C: lui         $a1, 0x3F59
    ctx->r5 = S32(0X3F59 << 16);
    // 0x80800F50: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800F54: jal         0x80101E14
    // 0x80800F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_150;
    // 0x80800F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_150:
    // 0x80800F5C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80800F60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80800F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F64: jal         0x80801AA0
    // 0x80800F68: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_151;
    // 0x80800F68: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_151:
    // 0x80800F6C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4358) << 16);
    // 0x80800F70: lwc1        $f16, 0x4358($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4358));
    // 0x80800F74: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x80800F78: b           L_80801464
    // 0x80800F7C: swc1        $f16, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f16.u32l;
        goto L_80801464;
    // 0x80800F7C: swc1        $f16, 0x5C($t1)
    MEM_W(0X5C, ctx->r9) = ctx->f16.u32l;
L_80800F80:
    // 0x80800F80: jal         0x800D8FF8
    // 0x80800F84: nop

    func_800D8FF8(rdram, ctx);
        goto after_152;
    // 0x80800F84: nop

    after_152:
    // 0x80800F88: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800F8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800F90: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80800F94: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800F98: lwc1        $f18, 0x5C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80800F9C: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80800FA0: jal         0x800D8FF8
    // 0x80800FA4: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_153;
    // 0x80800FA4: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    after_153:
    // 0x80800FA8: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x80800FAC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800FB0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1360, 0X4AE0) << 16);
    // 0x80800FB4: lwc1        $f16, 0x5C($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X5C);
    // 0x80800FB8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800FBC: addiu       $a0, $a0, 0x4AE0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1360, 0X4AE0));
    // 0x80800FC0: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800FC4: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80800FC8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80800FCC: jal         0x800EFC7C
    // 0x80800FD0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800EFC7C(rdram, ctx);
        goto after_154;
    // 0x80800FD0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_154:
    // 0x80800FD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X435C) << 16);
    // 0x80800FD8: lwc1        $f6, 0x435C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X435C));
    // 0x80800FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1360, 0X4AE0) << 16);
    // 0x80800FE4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800FE8: nop

    // 0x80800FEC: bc1fl       L_80801028
    if (!c1cs) {
        // 0x80800FF0: lw          $t5, 0x94($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X94);
            goto L_80801028;
    }
    goto skip_4;
    // 0x80800FF0: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    skip_4:
    // 0x80800FF4: jal         0x80102D78
    // 0x80800FF8: addiu       $a1, $a1, 0x4AE0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4AE0));
    func_80102D78(rdram, ctx);
        goto after_155;
    // 0x80800FF8: addiu       $a1, $a1, 0x4AE0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4AE0));
    after_155:
    // 0x80800FFC: jal         0x800D8FF8
    // 0x80801000: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_156;
    // 0x80801000: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_156:
    // 0x80801004: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80801008: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080100C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801010: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801014: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80801018: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8080101C: jal         0x800EF1B8
    // 0x80801020: nop

    func_800EF1B8(rdram, ctx);
        goto after_157;
    // 0x80801020: nop

    after_157:
    // 0x80801024: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
L_80801028:
    // 0x80801028: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080102C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801030: lwc1        $f10, 0x5C($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X5C);
    // 0x80801034: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80801038: nop

    // 0x8080103C: bc1f        L_80801464
    if (!c1cs) {
        // 0x80801040: nop
    
            goto L_80801464;
    }
    // 0x80801040: nop

    // 0x80801044: jal         0x80801AA0
    // 0x80801048: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_158;
    // 0x80801048: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_158:
    // 0x8080104C: jal         0x8010A570
    // 0x80801050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_159;
    // 0x80801050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_159:
    // 0x80801054: b           L_80801464
    // 0x80801058: nop

        goto L_80801464;
    // 0x80801058: nop

L_8080105C:
    // 0x8080105C: jal         0x800D8FF8
    // 0x80801060: nop

    func_800D8FF8(rdram, ctx);
        goto after_160;
    // 0x80801060: nop

    after_160:
    // 0x80801064: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80801068: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080106C: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80801070: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801074: lwc1        $f18, 0x5C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80801078: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8080107C: jal         0x800D8FF8
    // 0x80801080: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_161;
    // 0x80801080: swc1        $f16, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f16.u32l;
    after_161:
    // 0x80801084: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80801088: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080108C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4360) << 16);
    // 0x80801090: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80801094: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801098: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8080109C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x808010A0: lh          $t6, 0x74($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X74);
    // 0x808010A4: bne         $t6, $zero, L_808010F0
    if (ctx->r14 != 0) {
        // 0x808010A8: nop
    
            goto L_808010F0;
    }
    // 0x808010A8: nop

    // 0x808010AC: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808010B0: lwc1        $f16, 0x4360($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4360));
    // 0x808010B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B8: addiu       $a1, $v0, 0x44
    ctx->r5 = ADD32(ctx->r2, 0X44);
    // 0x808010BC: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x808010C0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X4864) << 16);
    // 0x808010C4: bc1f        L_808010F0
    if (!c1cs) {
        // 0x808010C8: nop
    
            goto L_808010F0;
    }
    // 0x808010C8: nop

    // 0x808010CC: jal         0x80089D18
    // 0x808010D0: addiu       $a2, $a2, 0x4864
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X4864));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_162;
    // 0x808010D0: addiu       $a2, $a2, 0x4864
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X4864));
    after_162:
    // 0x808010D4: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x808010D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808010DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010E0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x808010E4: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x808010E8: jal         0x80803CF0
    // 0x808010EC: sh          $t8, 0x74($t9)
    MEM_H(0X74, ctx->r25) = ctx->r24;
    func_80803CF0_chweldarboss(rdram, ctx);
        goto after_163;
    // 0x808010EC: sh          $t8, 0x74($t9)
    MEM_H(0X74, ctx->r25) = ctx->r24;
    after_163:
L_808010F0:
    // 0x808010F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4364) << 16);
    // 0x808010F4: lwc1        $f4, 0x4364($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4364));
    // 0x808010F8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808010FC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1360, 0X4AE0) << 16);
    // 0x80801100: addiu       $a0, $a0, 0x4AE0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1360, 0X4AE0));
    // 0x80801104: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80801108: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080110C: bc1fl       L_80801170
    if (!c1cs) {
        // 0x80801110: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801170;
    }
    goto skip_5;
    // 0x80801110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x80801114: jal         0x800EFC7C
    // 0x80801118: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800EFC7C(rdram, ctx);
        goto after_164;
    // 0x80801118: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_164:
    // 0x8080111C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1360, 0X4368) << 16);
    // 0x80801120: lwc1        $f6, 0x4368($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1360, 0X4368));
    // 0x80801124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801128: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1360, 0X4AE0) << 16);
    // 0x8080112C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80801130: nop

    // 0x80801134: bc1fl       L_80801170
    if (!c1cs) {
        // 0x80801138: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801170;
    }
    goto skip_6;
    // 0x80801138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
    // 0x8080113C: jal         0x80102D78
    // 0x80801140: addiu       $a1, $a1, 0x4AE0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4AE0));
    func_80102D78(rdram, ctx);
        goto after_165;
    // 0x80801140: addiu       $a1, $a1, 0x4AE0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1360, 0X4AE0));
    after_165:
    // 0x80801144: jal         0x800D8FF8
    // 0x80801148: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_166;
    // 0x80801148: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_166:
    // 0x8080114C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80801150: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801154: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80801158: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080115C: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80801160: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80801164: jal         0x800EF1B8
    // 0x80801168: nop

    func_800EF1B8(rdram, ctx);
        goto after_167;
    // 0x80801168: nop

    after_167:
    // 0x8080116C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801170:
    // 0x80801170: jal         0x80803528
    // 0x80801174: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    func_80803528_chweldarboss(rdram, ctx);
        goto after_168;
    // 0x80801174: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    after_168:
    // 0x80801178: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080117C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801180: nop

    // 0x80801184: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x80801188: nop

    // 0x8080118C: bc1f        L_80801464
    if (!c1cs) {
        // 0x80801190: nop
    
            goto L_80801464;
    }
    // 0x80801190: nop

    // 0x80801194: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80801198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080119C: jal         0x80802B1C
    // 0x808011A0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    func_80802B1C_chweldarboss(rdram, ctx);
        goto after_169;
    // 0x808011A0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    after_169:
    // 0x808011A4: jal         0x808035D0
    // 0x808011A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808035D0_chweldarboss(rdram, ctx);
        goto after_170;
    // 0x808011A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_170:
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011B0: jal         0x80801AA0
    // 0x808011B4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_171;
    // 0x808011B4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_171:
    // 0x808011B8: jal         0x8010A590
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_172;
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_172:
    // 0x808011C0: b           L_80801464
    // 0x808011C4: nop

        goto L_80801464;
    // 0x808011C4: nop

L_808011C8:
    // 0x808011C8: jal         0x80101DDC
    // 0x808011CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_173;
    // 0x808011CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_173:
    // 0x808011D0: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x808011D4: nop
    
            goto L_80801464;
    }
    // 0x808011D4: nop

    // 0x808011D8: jal         0x80803D64
    // 0x808011DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803D64_chweldarboss(rdram, ctx);
        goto after_174;
    // 0x808011DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_174:
    // 0x808011E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011E4: jal         0x80801AA0
    // 0x808011E8: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_175;
    // 0x808011E8: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_175:
    // 0x808011EC: b           L_80801464
    // 0x808011F0: nop

        goto L_80801464;
    // 0x808011F0: nop

L_808011F4:
    // 0x808011F4: jal         0x80802E80
    // 0x808011F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802E80_chweldarboss(rdram, ctx);
        goto after_176;
    // 0x808011F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_176:
    // 0x808011FC: jal         0x80101DDC
    // 0x80801200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_177;
    // 0x80801200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_177:
    // 0x80801204: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80801208: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80801208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080120C: jal         0x80801AA0
    // 0x80801210: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_178;
    // 0x80801210: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_178:
    // 0x80801214: b           L_80801464
    // 0x80801218: nop

        goto L_80801464;
    // 0x80801218: nop

L_8080121C:
    // 0x8080121C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801220: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80801224: jal         0x80802D2C
    // 0x80801228: addiu       $a2, $zero, 0x27
    ctx->r6 = ADD32(0, 0X27);
    func_80802D2C_chweldarboss(rdram, ctx);
        goto after_179;
    // 0x80801228: addiu       $a2, $zero, 0x27
    ctx->r6 = ADD32(0, 0X27);
    after_179:
    // 0x8080122C: b           L_80801464
    // 0x80801230: nop

        goto L_80801464;
    // 0x80801230: nop

L_80801234:
    // 0x80801234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801238: jal         0x80802FE4
    // 0x8080123C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_80802FE4_chweldarboss(rdram, ctx);
        goto after_180;
    // 0x8080123C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_180:
    // 0x80801240: b           L_80801464
    // 0x80801244: nop

        goto L_80801464;
    // 0x80801244: nop

L_80801248:
    // 0x80801248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080124C: jal         0x80802F14
    // 0x80801250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80802F14_chweldarboss(rdram, ctx);
        goto after_181;
    // 0x80801250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_181:
    // 0x80801254: jal         0x80101DDC
    // 0x80801258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_182;
    // 0x80801258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_182:
    // 0x8080125C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80801260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80801260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801264: jal         0x80801AA0
    // 0x80801268: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_183;
    // 0x80801268: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_183:
    // 0x8080126C: b           L_80801464
    // 0x80801270: nop

        goto L_80801464;
    // 0x80801270: nop

L_80801274:
    // 0x80801274: jal         0x80101DDC
    // 0x80801278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_184;
    // 0x80801278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_184:
    // 0x8080127C: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80801280: nop
    
            goto L_80801464;
    }
    // 0x80801280: nop

    // 0x80801284: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80801288: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080128C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801290: lbu         $t0, 0x62($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X62);
    // 0x80801294: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80801298: bne         $t0, $zero, L_808012B4
    if (ctx->r8 != 0) {
        // 0x8080129C: nop
    
            goto L_808012B4;
    }
    // 0x8080129C: nop

    // 0x808012A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012A4: jal         0x80801AA0
    // 0x808012A8: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_185;
    // 0x808012A8: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_185:
    // 0x808012AC: b           L_80801464
    // 0x808012B0: nop

        goto L_80801464;
    // 0x808012B0: nop

L_808012B4:
    // 0x808012B4: jal         0x80801AA0
    // 0x808012B8: sb          $t7, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r15;
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_186;
    // 0x808012B8: sb          $t7, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r15;
    after_186:
    // 0x808012BC: b           L_80801464
    // 0x808012C0: nop

        goto L_80801464;
    // 0x808012C0: nop

L_808012C4:
    // 0x808012C4: jal         0x808032A8
    // 0x808012C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808032A8_chweldarboss(rdram, ctx);
        goto after_187;
    // 0x808012C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_187:
    // 0x808012CC: jal         0x80101DDC
    // 0x808012D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_188;
    // 0x808012D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_188:
    // 0x808012D4: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x808012D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x808012D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012DC: jal         0x80801AA0
    // 0x808012E0: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_189;
    // 0x808012E0: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    after_189:
    // 0x808012E4: b           L_80801464
    // 0x808012E8: nop

        goto L_80801464;
    // 0x808012E8: nop

L_808012EC:
    // 0x808012EC: jal         0x800D9078
    // 0x808012F0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_190;
    // 0x808012F0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_190:
    // 0x808012F4: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x808012F8: lw          $t2, 0x94($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X94);
            goto L_80801464;
    }
    // 0x808012F8: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x808012FC: lh          $a0, 0x76($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X76);
    // 0x80801300: jal         0x800F82D4
    // 0x80801304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_191;
    // 0x80801304: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_191:
    // 0x80801308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080130C: jal         0x80801AA0
    // 0x80801310: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_192;
    // 0x80801310: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_192:
    // 0x80801314: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x80801318: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8080131C: b           L_80801464
    // 0x80801320: sh          $t3, 0x76($t1)
    MEM_H(0X76, ctx->r9) = ctx->r11;
        goto L_80801464;
    // 0x80801320: sh          $t3, 0x76($t1)
    MEM_H(0X76, ctx->r9) = ctx->r11;
L_80801324:
    // 0x80801324: jal         0x80803624
    // 0x80801328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803624_chweldarboss(rdram, ctx);
        goto after_193;
    // 0x80801328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_193:
    // 0x8080132C: b           L_80801464
    // 0x80801330: nop

        goto L_80801464;
    // 0x80801330: nop

L_80801334:
    // 0x80801334: jal         0x800D9078
    // 0x80801338: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_194;
    // 0x80801338: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_194:
    // 0x8080133C: beq         $v0, $zero, L_8080140C
    if (ctx->r2 == 0) {
        // 0x80801340: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_8080140C;
    }
    // 0x80801340: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80801344: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801348: jal         0x800EE7F8
    // 0x8080134C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_195;
    // 0x8080134C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_195:
    // 0x80801350: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80801354: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801358: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080135C: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x80801360: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80801364: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80801368: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x8080136C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80801370: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80801374: sb          $zero, 0x6E($t4)
    MEM_B(0X6E, ctx->r12) = 0;
    // 0x80801378: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8080137C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80801380: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80801384: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80801388: lw          $t6, 0x48($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X48);
    // 0x8080138C: jal         0x80086D50
    // 0x80801390: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_196;
    // 0x80801390: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_196:
    // 0x80801394: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1360, 0X4880) << 16);
    // 0x80801398: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080139C: addiu       $t8, $t8, 0x4880
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(1360, 0X4880));
    // 0x808013A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808013A4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808013A8: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x808013AC: jal         0x800BBCB8
    // 0x808013B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_197;
    // 0x808013B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_197:
    // 0x808013B4: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1360, 0X48B4) << 16);
    // 0x808013B8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808013BC: addiu       $t9, $t9, 0x48B4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1360, 0X48B4));
    // 0x808013C0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808013C4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808013C8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808013CC: jal         0x800BBCB8
    // 0x808013D0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_800BBCB8(rdram, ctx);
        goto after_198;
    // 0x808013D0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_198:
    // 0x808013D4: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808013D8: lw          $a3, 0x48($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X48);
    // 0x808013DC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x808013E0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808013E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013E8: addiu       $a1, $zero, 0x86F
    ctx->r5 = ADD32(0, 0X86F);
    // 0x808013EC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808013F0: jal         0x80086680
    // 0x808013F4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    _chexploder_entrypoint_5(rdram, ctx);
        goto after_199;
    // 0x808013F4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_199:
    // 0x808013F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1360, 0X4874) << 16);
    // 0x808013FC: addiu       $a2, $a2, 0x4874
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1360, 0X4874));
    // 0x80801400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801404: jal         0x80089D18
    // 0x80801408: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_200;
    // 0x80801408: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_200:
L_8080140C:
    // 0x8080140C: jal         0x80803624
    // 0x80801410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803624_chweldarboss(rdram, ctx);
        goto after_201;
    // 0x80801410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_201:
    // 0x80801414: b           L_80801464
    // 0x80801418: nop

        goto L_80801464;
    // 0x80801418: nop

L_8080141C:
    // 0x8080141C: jal         0x800D9078
    // 0x80801420: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_202;
    // 0x80801420: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_202:
    // 0x80801424: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80801428: nop
    
            goto L_80801464;
    }
    // 0x80801428: nop

    // 0x8080142C: jal         0x800DA544
    // 0x80801430: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    func_800DA544(rdram, ctx);
        goto after_203;
    // 0x80801430: addiu       $a0, $zero, 0x18C
    ctx->r4 = ADD32(0, 0X18C);
    after_203:
    // 0x80801434: addiu       $a0, $zero, 0x345
    ctx->r4 = ADD32(0, 0X345);
    // 0x80801438: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080143C: jal         0x80101180
    // 0x80801440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_204;
    // 0x80801440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_204:
    // 0x80801444: b           L_80801464
    // 0x80801448: nop

        goto L_80801464;
    // 0x80801448: nop

L_8080144C:
    // 0x8080144C: jal         0x800D9078
    // 0x80801450: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_205;
    // 0x80801450: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_205:
    // 0x80801454: beq         $v0, $zero, L_80801464
    if (ctx->r2 == 0) {
        // 0x80801458: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801464;
    }
    // 0x80801458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080145C: jal         0x80801AA0
    // 0x80801460: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_206;
    // 0x80801460: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_206:
L_80801464:
    // 0x80801464: jal         0x808023F8
    // 0x80801468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808023F8_chweldarboss(rdram, ctx);
        goto after_207;
    // 0x80801468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_207:
    // 0x8080146C: jal         0x8080247C
    // 0x80801470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080247C_chweldarboss(rdram, ctx);
        goto after_208;
    // 0x80801470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_208:
    // 0x80801474: jal         0x808026BC
    // 0x80801478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808026BC_chweldarboss(rdram, ctx);
        goto after_209;
    // 0x80801478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_209:
    // 0x8080147C: jal         0x80803770
    // 0x80801480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803770_chweldarboss(rdram, ctx);
        goto after_210;
    // 0x80801480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_210:
    // 0x80801484: jal         0x80803C18
    // 0x80801488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803C18_chweldarboss(rdram, ctx);
        goto after_211;
    // 0x80801488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_211:
    // 0x8080148C: jal         0x808034A0
    // 0x80801490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808034A0_chweldarboss(rdram, ctx);
        goto after_212;
    // 0x80801490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_212:
    // 0x80801494: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80801498: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080149C: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    // 0x808014A0: beq         $t7, $zero, L_808014B8
    if (ctx->r15 == 0) {
        // 0x808014A4: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_808014B8;
    }
    // 0x808014A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808014A8: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x808014AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808014B0: jal         0x80089F20
    // 0x808014B4: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_213;
    // 0x808014B4: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    after_213:
L_808014B8:
    // 0x808014B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808014BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808014C0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    // 0x808014C4: jr          $ra
    // 0x808014C8: nop

    return;
    // 0x808014C8: nop

;}
RECOMP_FUNC void func_80800D20_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D2C: jal         0x8080009C
    // 0x80800D30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8080009C_chstoneballcontrol(rdram, ctx);
        goto after_0;
    // 0x80800D30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800D34: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800D38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4EB8) << 16);
    // 0x80800D3C: lwc1        $f12, 0x4EB8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4EB8));
    // 0x80800D40: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4EBC) << 16);
    // 0x80800D44: jal         0x800DC178
    // 0x80800D48: lwc1        $f14, 0x4EBC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4EBC));
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800D48: lwc1        $f14, 0x4EBC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4EBC));
    after_1:
    // 0x80800D4C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800D50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800D54: nop

    // 0x80800D58: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800D5C: jal         0x800DC0C0
    // 0x80800D60: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x80800D60: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x80800D64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800D68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D70: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800D74: nop

    // 0x80800D78: bc1f        L_80800D8C
    if (!c1cs) {
        // 0x80800D7C: nop
    
            goto L_80800D8C;
    }
    // 0x80800D7C: nop

    // 0x80800D80: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800D84: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80800D88: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
L_80800D8C:
    // 0x80800D8C: jal         0x80800B4C
    // 0x80800D90: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800B4C_chstoneballcontrol(rdram, ctx);
        goto after_3;
    // 0x80800D90: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x80800D94: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800D98: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800D9C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800DA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800DA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DAC: jr          $ra
    // 0x80800DB0: nop

    return;
    // 0x80800DB0: nop

;}
RECOMP_FUNC void func_80800000_chworlddoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800008: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800014: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80800018: jal         0x800EE7F8
    // 0x8080001C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800020: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800024: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800028: lui         $a3, 0xC248
    ctx->r7 = S32(0XC248 << 16);
    // 0x8080002C: lw          $a1, 0x44($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X44);
    // 0x80800030: jal         0x800EF214
    // 0x80800034: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    func_800EF214(rdram, ctx);
        goto after_1;
    // 0x80800034: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    after_1:
    // 0x80800038: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2476, 0X990) << 16);
    // 0x8080003C: addiu       $t6, $t6, 0x990
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2476, 0X990));
    // 0x80800040: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800044: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800048: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080004C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800050: jal         0x800BBCB8
    // 0x80800054: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80800054: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_2:
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080005C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void _subaddiefind_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C28: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C28);
    return;
    // 0x80089C2C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80094EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094EEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094EF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094EF4: jal         0x800964D0
    // 0x80094EF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800964D0(rdram, ctx);
        goto after_0;
    // 0x80094EF8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80094EFC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80094F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80094F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094F08: xor         $v0, $v0, $t6
    ctx->r2 = ctx->r2 ^ ctx->r14;
    // 0x80094F0C: jr          $ra
    // 0x80094F10: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x80094F10: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void func_808005C4_chdinofoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808005C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005D0: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808005D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005D8: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808005DC: bltzl       $t8, L_808006AC
    if (SIGNED(ctx->r24) < 0) {
        // 0x808005E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808006AC;
    }
    goto skip_0;
    // 0x808005E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808005E4: jal         0x80088848
    // 0x808005E8: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x808005E8: nop

    after_0:
    // 0x808005EC: bnel        $v0, $zero, L_808006AC
    if (ctx->r2 != 0) {
        // 0x808005F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808006AC;
    }
    goto skip_1;
    // 0x808005F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808005F4: jal         0x800F54E4
    // 0x808005F8: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808005F8: nop

    after_1:
    // 0x808005FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800600: jal         0x800F5A00
    // 0x80800604: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800F5A00(rdram, ctx);
        goto after_2;
    // 0x80800604: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x80800608: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8080060C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800610: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800614: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80800618: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8080061C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80800620: jal         0x800EFE50
    // 0x80800624: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    func_800EFE50(rdram, ctx);
        goto after_3;
    // 0x80800624: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800628: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x8080062C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800630: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800634: jal         0x800EEB40
    // 0x80800638: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EEB40(rdram, ctx);
        goto after_4;
    // 0x80800638: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x8080063C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1040, 0X7D0) << 16);
    // 0x80800640: lwc1        $f6, 0x7D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1040, 0X7D0));
    // 0x80800644: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800648: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8080064C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800650: nop

    // 0x80800654: bc1fl       L_808006AC
    if (!c1cs) {
        // 0x80800658: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808006AC;
    }
    goto skip_2;
    // 0x80800658: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8080065C: jal         0x800EFB24
    // 0x80800660: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x80800660: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_5:
    // 0x80800664: jal         0x800D8FF8
    // 0x80800668: nop

    func_800D8FF8(rdram, ctx);
        goto after_6;
    // 0x80800668: nop

    after_6:
    // 0x8080066C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800670: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800674: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800678: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8080067C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800680: jal         0x800EF368
    // 0x80800684: nop

    func_800EF368(rdram, ctx);
        goto after_7;
    // 0x80800684: nop

    after_7:
    // 0x80800688: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080068C: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800690: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800694: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800698: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8080069C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x808006A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808006A4: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x808006A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006AC:
    // 0x808006AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006B0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808006B4: jr          $ra
    // 0x808006B8: nop

    return;
    // 0x808006B8: nop

;}
RECOMP_FUNC void func_800BC358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BC35C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BC360: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800BC364: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x800BC368: bnel        $t7, $a2, L_800BC3AC
    if (ctx->r15 != ctx->r6) {
        // 0x800BC36C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800BC3AC;
    }
    goto skip_0;
    // 0x800BC36C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800BC370: lbu         $v0, 0xA($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA);
    // 0x800BC374: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800BC378: beq         $v0, $zero, L_800BC390
    if (ctx->r2 == 0) {
        // 0x800BC37C: nop
    
            goto L_800BC390;
    }
    // 0x800BC37C: nop

    // 0x800BC380: beq         $v0, $at, L_800BC3A0
    if (ctx->r2 == ctx->r1) {
        // 0x800BC384: nop
    
            goto L_800BC3A0;
    }
    // 0x800BC384: nop

    // 0x800BC388: b           L_800BC3AC
    // 0x800BC38C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800BC3AC;
    // 0x800BC38C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BC390:
    // 0x800BC390: jal         0x800BBD60
    // 0x800BC394: nop

    func_800BBD60(rdram, ctx);
        goto after_0;
    // 0x800BC394: nop

    after_0:
    // 0x800BC398: b           L_800BC3AC
    // 0x800BC39C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800BC3AC;
    // 0x800BC39C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BC3A0:
    // 0x800BC3A0: jal         0x800BBFDC
    // 0x800BC3A4: nop

    func_800BBFDC(rdram, ctx);
        goto after_1;
    // 0x800BC3A4: nop

    after_1:
    // 0x800BC3A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800BC3AC:
    // 0x800BC3AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BC3B0: jr          $ra
    // 0x800BC3B4: nop

    return;
    // 0x800BC3B4: nop

;}
RECOMP_FUNC void chswitch_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(696, 0XDC4) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0xDC4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(696, 0XDC4));
    return;
    // 0x80800014: addiu       $v0, $v0, 0xDC4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(696, 0XDC4));
;}
RECOMP_FUNC void func_800EAA2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EAA2C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800EAA30: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800EAA34: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800EAA38: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800EAA3C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800EAA40: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800EAA44: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800EAA48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800EAA4C: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x800EAA50: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800EAA54: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800EAA58: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800EAA5C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800EAA60: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800EAA64: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800EAA68: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x800EAA6C: jal         0x800E9E88
    // 0x800EAA70: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    func_800E9E88(rdram, ctx);
        goto after_0;
    // 0x800EAA70: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    after_0:
    // 0x800EAA74: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x800EAA78: jal         0x800E9EB4
    // 0x800EAA7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800E9EB4(rdram, ctx);
        goto after_1;
    // 0x800EAA7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800EAA80: sltu        $at, $s4, $v0
    ctx->r1 = ctx->r20 < ctx->r2 ? 1 : 0;
    // 0x800EAA84: beq         $at, $zero, L_800EADC4
    if (ctx->r1 == 0) {
        // 0x800EAA88: sw          $v0, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r2;
            goto L_800EADC4;
    }
    // 0x800EAA88: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x800EAA8C: lw          $fp, 0xC8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XC8);
    // 0x800EAA90: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
L_800EAA94:
    // 0x800EAA94: sll         $t7, $v0, 27
    ctx->r15 = S32(ctx->r2 << 27);
    // 0x800EAA98: bgez        $t7, L_800EADB0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800EAA9C: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_800EADB0;
    }
    // 0x800EAA9C: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x800EAAA0: bne         $t8, $zero, L_800EAC2C
    if (ctx->r24 != 0) {
        // 0x800EAAA4: sll         $t1, $v0, 28
        ctx->r9 = S32(ctx->r2 << 28);
            goto L_800EAC2C;
    }
    // 0x800EAAA4: sll         $t1, $v0, 28
    ctx->r9 = S32(ctx->r2 << 28);
    // 0x800EAAA8: sll         $t0, $v0, 30
    ctx->r8 = S32(ctx->r2 << 30);
    // 0x800EAAAC: bgezl       $t0, L_800EADB4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800EAAB0: lw          $t4, 0xA8($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XA8);
            goto L_800EADB4;
    }
    goto skip_0;
    // 0x800EAAB0: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    skip_0:
    // 0x800EAAB4: jal         0x80088C88
    // 0x800EAAB8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    _gsproplookup_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x800EAAB8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x800EAABC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800EAAC0: jal         0x800BFC54
    // 0x800EAAC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800BFC54(rdram, ctx);
        goto after_3;
    // 0x800EAAC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800EAAC8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800EAACC: jal         0x800B2720
    // 0x800EAAD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2720(rdram, ctx);
        goto after_4;
    // 0x800EAAD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800EAAD4: beq         $v0, $zero, L_800EAC14
    if (ctx->r2 == 0) {
        // 0x800EAAD8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800EAC14;
    }
    // 0x800EAAD8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800EAADC: lh          $t1, 0x4($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X4);
    // 0x800EAAE0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EAAE4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800EAAE8: nop

    // 0x800EAAEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EAAF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800EAAF4: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    // 0x800EAAF8: lh          $t2, 0x6($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X6);
    // 0x800EAAFC: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800EAB00: nop

    // 0x800EAB04: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EAB08: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x800EAB0C: lh          $t3, 0x8($s4)
    ctx->r11 = MEM_H(ctx->r20, 0X8);
    // 0x800EAB10: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x800EAB14: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800EAB18: nop

    // 0x800EAB1C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EAB20: swc1        $f18, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f18.u32l;
    // 0x800EAB24: lbu         $t4, 0x2($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X2);
    // 0x800EAB28: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x800EAB2C: bgez        $t4, L_800EAB40
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800EAB30: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800EAB40;
    }
    // 0x800EAB30: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EAB34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EAB38: nop

    // 0x800EAB3C: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_800EAB40:
    // 0x800EAB40: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800EAB44: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EAB48: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x800EAB4C: lbu         $t5, 0x3($s4)
    ctx->r13 = MEM_BU(ctx->r20, 0X3);
    // 0x800EAB50: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800EAB54: bgez        $t5, L_800EAB68
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800EAB58: cvt.s.w     $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800EAB68;
    }
    // 0x800EAB58: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EAB5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800EAB60: nop

    // 0x800EAB64: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_800EAB68:
    // 0x800EAB68: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800EAB6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800EAB70: jal         0x800B2840
    // 0x800EAB74: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    func_800B2840(rdram, ctx);
        goto after_5;
    // 0x800EAB74: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x800EAB78: lbu         $t6, 0xA($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0XA);
    // 0x800EAB7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EAB80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800EAB84: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800EAB88: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x800EAB8C: addiu       $a3, $sp, 0x84
    ctx->r7 = ADD32(ctx->r29, 0X84);
    // 0x800EAB90: bgez        $t6, L_800EABA8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800EAB94: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800EABA8;
    }
    // 0x800EAB94: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EAB98: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EAB9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800EABA0: nop

    // 0x800EABA4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800EABA8:
    // 0x800EABA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EABAC: lwc1        $f16, 0x5E54($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5E54);
    // 0x800EABB0: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800EABB4: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x800EABB8: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800EABBC: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800EABC0: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x800EABC4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800EABC8: sw          $fp, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r30;
    // 0x800EABCC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800EABD0: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800EABD4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800EABD8: jal         0x800AC848
    // 0x800EABDC: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    func_800AC848(rdram, ctx);
        goto after_6;
    // 0x800EABDC: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    after_6:
    // 0x800EABE0: beq         $v0, $zero, L_800EAC08
    if (ctx->r2 == 0) {
        // 0x800EABE4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800EAC08;
    }
    // 0x800EABE4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EABE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EABEC: lw          $v0, 0x2DD0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2DD0);
    // 0x800EABF0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800EABF4: beq         $v0, $zero, L_800EAC08
    if (ctx->r2 == 0) {
        // 0x800EABF8: nop
    
            goto L_800EAC08;
    }
    // 0x800EABF8: nop

    // 0x800EABFC: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800EAC00: jalr        $v0
    // 0x800EAC04: lw          $a1, 0x2DD4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2DD4);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_7;
    // 0x800EAC04: lw          $a1, 0x2DD4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2DD4);
    after_7:
L_800EAC08:
    // 0x800EAC08: beq         $s0, $zero, L_800EAC14
    if (ctx->r16 == 0) {
        // 0x800EAC0C: nop
    
            goto L_800EAC14;
    }
    // 0x800EAC0C: nop

    // 0x800EAC10: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
L_800EAC14:
    // 0x800EAC14: beql        $s2, $zero, L_800EADB4
    if (ctx->r18 == 0) {
        // 0x800EAC18: lw          $t4, 0xA8($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XA8);
            goto L_800EADB4;
    }
    goto skip_1;
    // 0x800EAC18: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    skip_1:
    // 0x800EAC1C: jal         0x800BFC74
    // 0x800EAC20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800BFC74(rdram, ctx);
        goto after_8;
    // 0x800EAC20: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_8:
    // 0x800EAC24: b           L_800EADB4
    // 0x800EAC28: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
        goto L_800EADB4;
    // 0x800EAC28: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
L_800EAC2C:
    // 0x800EAC2C: bgez        $t1, L_800EADB0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800EAC30: lw          $s3, 0x0($s4)
        ctx->r19 = MEM_W(ctx->r20, 0X0);
            goto L_800EADB0;
    }
    // 0x800EAC30: lw          $s3, 0x0($s4)
    ctx->r19 = MEM_W(ctx->r20, 0X0);
    // 0x800EAC34: lhu         $t2, 0x18($s3)
    ctx->r10 = MEM_HU(ctx->r19, 0X18);
    // 0x800EAC38: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800EAC3C: beql        $t3, $zero, L_800EADB4
    if (ctx->r11 == 0) {
        // 0x800EAC40: lw          $t4, 0xA8($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XA8);
            goto L_800EADB4;
    }
    goto skip_2;
    // 0x800EAC40: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    skip_2:
    // 0x800EAC44: jal         0x80106790
    // 0x800EAC48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80106790(rdram, ctx);
        goto after_9;
    // 0x800EAC48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x800EAC4C: lw          $t4, 0x64($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X64);
    // 0x800EAC50: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EAC54: sll         $t6, $t4, 14
    ctx->r14 = S32(ctx->r12 << 14);
    // 0x800EAC58: bltzl       $t6, L_800EADB4
    if (SIGNED(ctx->r14) < 0) {
        // 0x800EAC5C: lw          $t4, 0xA8($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XA8);
            goto L_800EADB4;
    }
    goto skip_3;
    // 0x800EAC5C: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    skip_3:
    // 0x800EAC60: lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC);
    // 0x800EAC64: beq         $v0, $zero, L_800EACBC
    if (ctx->r2 == 0) {
        // 0x800EAC68: nop
    
            goto L_800EACBC;
    }
    // 0x800EAC68: nop

    // 0x800EAC6C: jalr        $v0
    // 0x800EAC70: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_10;
    // 0x800EAC70: nop

    after_10:
    // 0x800EAC74: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x800EAC78: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800EAC7C: beq         $t7, $zero, L_800EACBC
    if (ctx->r15 == 0) {
        // 0x800EAC80: nop
    
            goto L_800EACBC;
    }
    // 0x800EAC80: nop

    // 0x800EAC84: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x800EAC88: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800EAC8C: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800EAC90: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800EAC94: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800EAC98: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800EAC9C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800EACA0: lw          $a1, 0xBC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XBC);
    // 0x800EACA4: jalr        $t9
    // 0x800EACA8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x800EACA8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_11:
    // 0x800EACAC: beql        $v0, $zero, L_800EADB4
    if (ctx->r2 == 0) {
        // 0x800EACB0: lw          $t4, 0xA8($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XA8);
            goto L_800EADB4;
    }
    goto skip_4;
    // 0x800EACB0: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    skip_4:
    // 0x800EACB4: b           L_800EADB0
    // 0x800EACB8: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
        goto L_800EADB0;
    // 0x800EACB8: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
L_800EACBC:
    // 0x800EACBC: jal         0x80103328
    // 0x800EACC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103328(rdram, ctx);
        goto after_12;
    // 0x800EACC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800EACC4: addiu       $s5, $s0, 0x4
    ctx->r21 = ADD32(ctx->r16, 0X4);
    // 0x800EACC8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800EACCC: jal         0x800EEAD4
    // 0x800EACD0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_13;
    // 0x800EACD0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_13:
    // 0x800EACD4: lhu         $t0, 0x6A($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6A);
    // 0x800EACD8: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800EACDC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800EACE0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800EACE4: bgez        $t0, L_800EACF8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800EACE8: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800EACF8;
    }
    // 0x800EACE8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EACEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EACF0: nop

    // 0x800EACF4: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_800EACF8:
    // 0x800EACF8: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800EACFC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800EAD00: c.le.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl <= ctx->f4.fl;
    // 0x800EAD04: nop

    // 0x800EAD08: bc1tl       L_800EADB4
    if (c1cs) {
        // 0x800EAD0C: lw          $t4, 0xA8($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XA8);
            goto L_800EADB4;
    }
    goto skip_5;
    // 0x800EAD0C: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    skip_5:
    // 0x800EAD10: jal         0x800CB854
    // 0x800EAD14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_14;
    // 0x800EAD14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x800EAD18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800EAD1C: bne         $v0, $at, L_800EAD2C
    if (ctx->r2 != ctx->r1) {
        // 0x800EAD20: nop
    
            goto L_800EAD2C;
    }
    // 0x800EAD20: nop

    // 0x800EAD24: jal         0x80103508
    // 0x800EAD28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103508(rdram, ctx);
        goto after_15;
    // 0x800EAD28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_800EAD2C:
    // 0x800EAD2C: jal         0x80103AA0
    // 0x800EAD30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80103AA0(rdram, ctx);
        goto after_16;
    // 0x800EAD30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_16:
    // 0x800EAD34: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800EAD38: jal         0x800B2720
    // 0x800EAD3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B2720(rdram, ctx);
        goto after_17;
    // 0x800EAD3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
    // 0x800EAD40: beq         $v0, $zero, L_800EADA0
    if (ctx->r2 == 0) {
        // 0x800EAD44: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800EADA0;
    }
    // 0x800EAD44: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800EAD48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EAD4C: jal         0x80103CDC
    // 0x800EAD50: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80103CDC(rdram, ctx);
        goto after_18;
    // 0x800EAD50: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_18:
    // 0x800EAD54: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800EAD58: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x800EAD5C: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x800EAD60: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    // 0x800EAD64: sw          $fp, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r30;
    // 0x800EAD68: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800EAD6C: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x800EAD70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EAD74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800EAD78: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800EAD7C: addiu       $a3, $s0, 0x44
    ctx->r7 = ADD32(ctx->r16, 0X44);
    // 0x800EAD80: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800EAD84: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800EAD88: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800EAD8C: jal         0x800AC848
    // 0x800EAD90: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    func_800AC848(rdram, ctx);
        goto after_19;
    // 0x800EAD90: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_19:
    // 0x800EAD94: beq         $v0, $zero, L_800EADA0
    if (ctx->r2 == 0) {
        // 0x800EAD98: nop
    
            goto L_800EADA0;
    }
    // 0x800EAD98: nop

    // 0x800EAD9C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
L_800EADA0:
    // 0x800EADA0: beql        $s2, $zero, L_800EADB4
    if (ctx->r18 == 0) {
        // 0x800EADA4: lw          $t4, 0xA8($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XA8);
            goto L_800EADB4;
    }
    goto skip_6;
    // 0x800EADA4: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    skip_6:
    // 0x800EADA8: jal         0x800D62E4
    // 0x800EADAC: lhu         $a0, 0x14($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X14);
    func_800D62E4(rdram, ctx);
        goto after_20;
    // 0x800EADAC: lhu         $a0, 0x14($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X14);
    after_20:
L_800EADB0:
    // 0x800EADB0: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
L_800EADB4:
    // 0x800EADB4: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x800EADB8: sltu        $at, $s4, $t4
    ctx->r1 = ctx->r20 < ctx->r12 ? 1 : 0;
    // 0x800EADBC: bnel        $at, $zero, L_800EAA94
    if (ctx->r1 != 0) {
        // 0x800EADC0: lw          $v0, 0x8($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X8);
            goto L_800EAA94;
    }
    goto skip_7;
    // 0x800EADC0: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    skip_7:
L_800EADC4:
    // 0x800EADC4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800EADC8: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x800EADCC: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800EADD0: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800EADD4: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800EADD8: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800EADDC: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800EADE0: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800EADE4: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800EADE8: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800EADEC: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800EADF0: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800EADF4: jr          $ra
    // 0x800EADF8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800EADF8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void baphysics_set_terminal_velocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BCC4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BCC8: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BCCC: jr          $ra
    // 0x8009BCD0: swc1        $f12, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8009BCD0: swc1        $f12, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_80104958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104958: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8010495C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80104960: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80104964: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80104968: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8010496C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80104970: jal         0x800AAD28
    // 0x80104974: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800AAD28(rdram, ctx);
        goto after_0;
    // 0x80104974: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x80104978: addiu       $s1, $s2, 0x4
    ctx->r17 = ADD32(ctx->r18, 0X4);
    // 0x8010497C: addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
    // 0x80104980: addiu       $s0, $sp, 0x34
    ctx->r16 = ADD32(ctx->r29, 0X34);
L_80104984:
    // 0x80104984: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80104988: jal         0x800EE940
    // 0x8010498C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE940(rdram, ctx);
        goto after_1;
    // 0x8010498C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80104990: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80104994: bne         $s0, $s2, L_80104984
    if (ctx->r16 != ctx->r18) {
        // 0x80104998: addiu       $s1, $s1, 0x6
        ctx->r17 = ADD32(ctx->r17, 0X6);
            goto L_80104984;
    }
    // 0x80104998: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x8010499C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801049A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801049A4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801049A8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801049AC: jr          $ra
    // 0x801049B0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801049B0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void subaddiefind_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808008F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808008F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800900: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800904: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800908: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8080090C: jal         0x8010413C
    // 0x80800910: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    func_8010413C(rdram, ctx);
        goto after_0;
    // 0x80800910: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x80800914: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800918: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080091C: jal         0x800BE3F8
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BE3F8(rdram, ctx);
        goto after_1;
    // 0x80800920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800924: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800928: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8080092C: beq         $t6, $zero, L_808009C0
    if (ctx->r14 == 0) {
        // 0x80800930: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_808009C0;
    }
    // 0x80800930: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
L_80800934:
    // 0x80800934: jal         0x800E9E88
    // 0x80800938: nop

    func_800E9E88(rdram, ctx);
        goto after_2;
    // 0x80800938: nop

    after_2:
    // 0x8080093C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800940: jal         0x800E9EB4
    // 0x80800944: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_3;
    // 0x80800944: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_3:
    // 0x80800948: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8080094C: beq         $at, $zero, L_808009B0
    if (ctx->r1 == 0) {
        // 0x80800950: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_808009B0;
    }
    // 0x80800950: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800954: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
L_80800958:
    // 0x80800958: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8080095C: beql        $t8, $zero, L_808009A4
    if (ctx->r24 == 0) {
        // 0x80800960: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_808009A4;
    }
    goto skip_0;
    // 0x80800960: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_0:
    // 0x80800964: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800968: lhu         $t9, 0x18($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X18);
    // 0x8080096C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80800970: beql        $t0, $zero, L_808009A4
    if (ctx->r8 == 0) {
        // 0x80800974: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_808009A4;
    }
    goto skip_1;
    // 0x80800974: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_1:
    // 0x80800978: jal         0x80106790
    // 0x8080097C: nop

    func_80106790(rdram, ctx);
        goto after_4;
    // 0x8080097C: nop

    after_4:
    // 0x80800980: lw          $t1, 0x64($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X64);
    // 0x80800984: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80800988: addu        $t5, $s3, $t4
    ctx->r13 = ADD32(ctx->r19, ctx->r12);
    // 0x8080098C: sll         $t3, $t1, 14
    ctx->r11 = S32(ctx->r9 << 14);
    // 0x80800990: bltzl       $t3, L_808009A4
    if (SIGNED(ctx->r11) < 0) {
        // 0x80800994: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_808009A4;
    }
    goto skip_2;
    // 0x80800994: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    skip_2:
    // 0x80800998: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8080099C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808009A0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_808009A4:
    // 0x808009A4: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x808009A8: bnel        $at, $zero, L_80800958
    if (ctx->r1 != 0) {
        // 0x808009AC: lw          $t7, 0x8($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X8);
            goto L_80800958;
    }
    goto skip_3;
    // 0x808009AC: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    skip_3:
L_808009B0:
    // 0x808009B0: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    // 0x808009B4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x808009B8: bne         $a0, $zero, L_80800934
    if (ctx->r4 != 0) {
        // 0x808009BC: nop
    
            goto L_80800934;
    }
    // 0x808009BC: nop

L_808009C0:
    // 0x808009C0: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x808009C4: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x808009C8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x808009CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808009D0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x808009D4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x808009D8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x808009DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x808009E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x808009E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009E8: jr          $ra
    // 0x808009EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808009EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8009864C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009864C: lw          $t6, 0xE0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XE0);
    // 0x80098650: jr          $ra
    // 0x80098654: lwc1        $f0, 0x10($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X10);
    return;
    // 0x80098654: lwc1        $f0, 0x10($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X10);
;}
RECOMP_FUNC void func_8008D14C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D14C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D158: jal         0x800C6E38
    // 0x8008D15C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D15C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008D160: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D164: beq         $t6, $zero, L_8008D17C
    if (ctx->r14 == 0) {
        // 0x8008D168: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D17C;
    }
    // 0x8008D168: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D16C: jal         0x800A3304
    // 0x8008D170: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_1;
    // 0x8008D170: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008D174: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D178: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008D17C:
    // 0x8008D17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D184: jr          $ra
    // 0x8008D188: nop

    return;
    // 0x8008D188: nop

;}
RECOMP_FUNC void _chboggyfatboy_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086878: syscall     392
    recomp_syscall_handler(rdram, ctx, 0x80086878);
    return;
    // 0x8008687C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800000_chstinger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8080000C: lw          $t7, 0x7C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X7C);
    // 0x80800010: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80800014: bgezl       $t9, L_80800150
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800018: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800150;
    }
    goto skip_0;
    // 0x80800018: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8080001C: jal         0x800B5BE4
    // 0x80800020: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_0:
    // 0x80800024: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80800028: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2152, 0X7D0) << 16);
    // 0x8080002C: addiu       $t0, $t0, 0x7D0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2152, 0X7D0));
    // 0x80800030: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800034: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800038: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8080003C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800040: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800044: jal         0x800BABB8
    // 0x80800048: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800048: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8080004C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80800050: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800054: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x80800058: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080005C: jal         0x800DC178
    // 0x80800060: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800060: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800064: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80800068: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080006C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80800070: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80800074: jal         0x800EFA98
    // 0x80800078: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_800EFA98(rdram, ctx);
        goto after_3;
    // 0x80800078: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_3:
    // 0x8080007C: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800080: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800084: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80800088: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080008C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80800090: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800094: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800098: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080009C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808000A0: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x808000A4: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    // 0x808000A8: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x808000AC: sll         $t5, $a2, 16
    ctx->r13 = S32(ctx->r6 << 16);
    // 0x808000B0: sra         $a2, $t5, 16
    ctx->r6 = S32(SIGNED(ctx->r13) >> 16);
    // 0x808000B4: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x808000B8: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x808000BC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x808000C0: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    // 0x808000C4: jal         0x800BA930
    // 0x808000C8: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    func_800BA930(rdram, ctx);
        goto after_4;
    // 0x808000C8: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    after_4:
    // 0x808000CC: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x808000D0: jal         0x800BA22C
    // 0x808000D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800BA22C(rdram, ctx);
        goto after_5;
    // 0x808000D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x808000D8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808000DC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808000E0: jal         0x800EFA98
    // 0x808000E4: lui         $a2, 0xC1C8
    ctx->r6 = S32(0XC1C8 << 16);
    func_800EFA98(rdram, ctx);
        goto after_6;
    // 0x808000E4: lui         $a2, 0xC1C8
    ctx->r6 = S32(0XC1C8 << 16);
    after_6:
    // 0x808000E8: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808000EC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808000F0: jal         0x800EE780
    // 0x808000F4: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    func_800EE780(rdram, ctx);
        goto after_7;
    // 0x808000F4: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_7:
    // 0x808000F8: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2152, 0X844) << 16);
    // 0x808000FC: addiu       $t0, $t0, 0x844
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2152, 0X844));
    // 0x80800100: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800104: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080010C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800110: jal         0x800BBCB8
    // 0x80800114: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_8;
    // 0x80800114: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80800118: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8080011C: jal         0x800EF04C
    // 0x80800120: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x80800120: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_9:
    // 0x80800124: jal         0x800B5BE4
    // 0x80800128: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800B5BE4(rdram, ctx);
        goto after_10;
    // 0x80800128: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_10:
    // 0x8080012C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2152, 0X7FC) << 16);
    // 0x80800130: addiu       $t1, $t1, 0x7FC
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2152, 0X7FC));
    // 0x80800134: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080013C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80800140: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800144: jal         0x800BABB8
    // 0x80800148: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_11;
    // 0x80800148: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_11:
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800150:
    // 0x80800150: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void func_800B37A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B37A4: addiu       $t6, $a0, 0x18
    ctx->r14 = ADD32(ctx->r4, 0X18);
    // 0x800B37A8: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800B37AC: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x800B37B0: jr          $ra
    // 0x800B37B4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x800B37B4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void func_800F87A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F87A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F87A8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F87AC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800F87B0: lw          $t7, 0x5490($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5490);
    // 0x800F87B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F87B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F87BC: jal         0x800F56D8
    // 0x800F87C0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_800F56D8(rdram, ctx);
        goto after_0;
    // 0x800F87C0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x800F87C4: beq         $v0, $zero, L_800F87F0
    if (ctx->r2 == 0) {
        // 0x800F87C8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F87F0;
    }
    // 0x800F87C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F87CC: jal         0x8009E674
    // 0x800F87D0: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    func_8009E674(rdram, ctx);
        goto after_1;
    // 0x800F87D0: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_1:
    // 0x800F87D4: beq         $v0, $zero, L_800F87F0
    if (ctx->r2 == 0) {
        // 0x800F87D8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F87F0;
    }
    // 0x800F87D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F87DC: jal         0x8009E7C8
    // 0x800F87E0: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x800F87E0: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_2:
    // 0x800F87E4: xori        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 ^ 0X2;
    // 0x800F87E8: b           L_800F87F4
    // 0x800F87EC: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
        goto L_800F87F4;
    // 0x800F87EC: sltiu       $v0, $t8, 0x1
    ctx->r2 = ctx->r24 < 0X1 ? 1 : 0;
L_800F87F0:
    // 0x800F87F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F87F4:
    // 0x800F87F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F87F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F87FC: jr          $ra
    // 0x800F8800: nop

    return;
    // 0x800F8800: nop

;}
RECOMP_FUNC void func_80800000_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800004: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800008: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800014: addiu       $a0, $zero, 0x299
    ctx->r4 = ADD32(0, 0X299);
    // 0x80800018: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x8080001C: jal         0x800882C0
    // 0x80800020: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80800024: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80800028: beq         $v0, $t0, L_80800040
    if (ctx->r2 == ctx->r8) {
        // 0x8080002C: addiu       $a0, $zero, 0x3FC
        ctx->r4 = ADD32(0, 0X3FC);
            goto L_80800040;
    }
    // 0x8080002C: addiu       $a0, $zero, 0x3FC
    ctx->r4 = ADD32(0, 0X3FC);
    // 0x80800030: jal         0x800FFA88
    // 0x80800034: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_1;
    // 0x80800034: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_1:
    // 0x80800038: b           L_80800214
    // 0x8080003C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800214;
    // 0x8080003C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800040:
    // 0x80800040: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x80800044: jal         0x800882C0
    // 0x80800048: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800048: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8080004C: bne         $v0, $zero, L_80800064
    if (ctx->r2 != 0) {
        // 0x80800050: lw          $a0, 0x84($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X84);
            goto L_80800064;
    }
    // 0x80800050: lw          $a0, 0x84($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X84);
    // 0x80800054: jal         0x800FFA88
    // 0x80800058: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_3;
    // 0x80800058: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x8080005C: b           L_80800214
    // 0x80800060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800214;
    // 0x80800060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800064:
    // 0x80800064: jal         0x80088C00
    // 0x80800068: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800068: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_4:
    // 0x8080006C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80800070: jal         0x80088C00
    // 0x80800074: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800074: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_5:
    // 0x80800078: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x8080007C: jal         0x80088C00
    // 0x80800080: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800080: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_6:
    // 0x80800084: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x80800088: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080008C: jal         0x80088C00
    // 0x80800090: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80800090: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    after_7:
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x800EFC7C
    // 0x8080009C: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    func_800EFC7C(rdram, ctx);
        goto after_8;
    // 0x8080009C: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    after_8:
    // 0x808000A0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x800EFC7C
    // 0x808000AC: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_800EFC7C(rdram, ctx);
        goto after_9;
    // 0x808000AC: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_9:
    // 0x808000B0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B8: jal         0x800EFC7C
    // 0x808000BC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EFC7C(rdram, ctx);
        goto after_10;
    // 0x808000BC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_10:
    // 0x808000C0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x808000C4: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x808000C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808000CC: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x808000D0: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
L_808000D4:
    // 0x808000D4: beq         $at, $zero, L_808001C8
    if (ctx->r1 == 0) {
        // 0x808000D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001C8;
    }
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: subu        $a3, $t0, $s0
    ctx->r7 = SUB32(ctx->r8, ctx->r16);
    // 0x808000E0: andi        $t8, $a3, 0x3
    ctx->r24 = ctx->r7 & 0X3;
    // 0x808000E4: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x808000E8: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x808000EC: beq         $t8, $zero, L_80800130
    if (ctx->r24 == 0) {
        // 0x808000F0: addu        $v1, $t6, $t7
        ctx->r3 = ADD32(ctx->r14, ctx->r15);
            goto L_80800130;
    }
    // 0x808000F0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x808000F4: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x808000F8: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x808000FC: addu        $a1, $t8, $s0
    ctx->r5 = ADD32(ctx->r24, ctx->r16);
L_80800100:
    // 0x80800100: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800104: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800108: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8080010C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800110: nop

    // 0x80800114: bc1f        L_80800124
    if (!c1cs) {
        // 0x80800118: nop
    
            goto L_80800124;
    }
    // 0x80800118: nop

    // 0x8080011C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80800120: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
L_80800124:
    // 0x80800124: bne         $a1, $a0, L_80800100
    if (ctx->r5 != ctx->r4) {
        // 0x80800128: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80800100;
    }
    // 0x80800128: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8080012C: beq         $a0, $t0, L_808001C8
    if (ctx->r4 == ctx->r8) {
        // 0x80800130: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_808001C8;
    }
L_80800130:
    // 0x80800130: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80800134: addiu       $t2, $sp, 0x40
    ctx->r10 = ADD32(ctx->r29, 0X40);
    // 0x80800138: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8080013C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
L_80800140:
    // 0x80800140: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800144: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800148: nop

    // 0x8080014C: bc1fl       L_80800164
    if (!c1cs) {
        // 0x80800150: lwc1        $f12, 0x4($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80800164;
    }
    goto skip_0;
    // 0x80800150: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80800154: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80800158: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x8080015C: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800160: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
L_80800164:
    // 0x80800164: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800168: nop

    // 0x8080016C: bc1fl       L_80800184
    if (!c1cs) {
        // 0x80800170: lwc1        $f12, 0x8($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
            goto L_80800184;
    }
    goto skip_1;
    // 0x80800170: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    skip_1:
    // 0x80800174: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x80800178: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x8080017C: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800180: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
L_80800184:
    // 0x80800184: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80800188: nop

    // 0x8080018C: bc1fl       L_808001A4
    if (!c1cs) {
        // 0x80800190: lwc1        $f12, 0xC($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
            goto L_808001A4;
    }
    goto skip_2;
    // 0x80800190: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    skip_2:
    // 0x80800194: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x80800198: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x8080019C: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x808001A0: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
L_808001A4:
    // 0x808001A4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x808001A8: nop

    // 0x808001AC: bc1fl       L_808001C0
    if (!c1cs) {
        // 0x808001B0: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_808001C0;
    }
    goto skip_3;
    // 0x808001B0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    skip_3:
    // 0x808001B4: swc1        $f2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
    // 0x808001B8: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x808001BC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
L_808001C0:
    // 0x808001C0: bnel        $v0, $a2, L_80800140
    if (ctx->r2 != ctx->r6) {
        // 0x808001C4: lwc1        $f12, 0x0($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
            goto L_80800140;
    }
    goto skip_4;
    // 0x808001C4: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    skip_4:
L_808001C8:
    // 0x808001C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808001CC: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x808001D0: bnel        $at, $zero, L_808000D4
    if (ctx->r1 != 0) {
        // 0x808001D4: slti        $at, $s0, 0x3
        ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
            goto L_808000D4;
    }
    goto skip_5;
    // 0x808001D4: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    skip_5:
    // 0x808001D8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x808001DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808001E0: swc1        $f4, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f4.u32l;
    // 0x808001E4: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808001E8: swc1        $f6, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f6.u32l;
    // 0x808001EC: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x808001F0: swc1        $f8, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f8.u32l;
    // 0x808001F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_808001F8:
    // 0x808001F8: jal         0x80801508
    // 0x808001FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80801508_chfactorymagnet(rdram, ctx);
        goto after_11;
    // 0x808001FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x80800200: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800204: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80800208: bnel        $s0, $at, L_808001F8
    if (ctx->r16 != ctx->r1) {
        // 0x8080020C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808001F8;
    }
    goto skip_6;
    // 0x8080020C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_6:
    // 0x80800210: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800214:
    // 0x80800214: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800218: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080021C: jr          $ra
    // 0x80800220: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80800220: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_8080134C_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080134C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801350: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80801354: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801358: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080135C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80801360: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80801364: sb          $t6, 0xE($a1)
    MEM_B(0XE, ctx->r5) = ctx->r14;
    // 0x80801368: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8080136C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801370: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80801374: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801378: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8080137C: jal         0x8008A1F0
    // 0x80801380: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80801380: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x80801384: bne         $v0, $zero, L_80801394
    if (ctx->r2 != 0) {
        // 0x80801388: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80801394;
    }
    // 0x80801388: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080138C: b           L_808013C0
    // 0x80801390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808013C0;
    // 0x80801390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801394:
    // 0x80801394: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801398: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080139C: jal         0x8008A1F8
    // 0x808013A0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808013A0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x808013A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808013A8: beq         $v0, $at, L_808013BC
    if (ctx->r2 == ctx->r1) {
        // 0x808013AC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808013BC;
    }
    // 0x808013AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808013B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808013B4: jal         0x80801464
    // 0x808013B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80801464_chnicecavemen(rdram, ctx);
        goto after_2;
    // 0x808013B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_808013BC:
    // 0x808013BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808013C0:
    // 0x808013C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808013C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808013C8: jr          $ra
    // 0x808013CC: nop

    return;
    // 0x808013CC: nop

;}
RECOMP_FUNC void _fxsplash25d_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800889D8: syscall     717
    recomp_syscall_handler(rdram, ctx, 0x800889D8);
    return;
    // 0x800889DC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void suexpressjoint_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800100: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800104: sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
    // 0x80800108: lh          $a0, 0x4($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4);
    // 0x8080010C: jal         0x80800000
    // 0x80800110: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80800000_suexpressjoint(rdram, ctx);
        goto after_0;
    // 0x80800110: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800114: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: sh          $v0, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r2;
    // 0x8080011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800124: jr          $ra
    // 0x80800128: nop

    return;
    // 0x80800128: nop

;}
RECOMP_FUNC void func_800C84B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C84B0: sll         $t6, $a0, 14
    ctx->r14 = S32(ctx->r4 << 14);
    // 0x800C84B4: bgez        $t6, L_800C84C4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800C84B8: andi        $v0, $a0, 0x1F00
        ctx->r2 = ctx->r4 & 0X1F00;
            goto L_800C84C4;
    }
    // 0x800C84B8: andi        $v0, $a0, 0x1F00
    ctx->r2 = ctx->r4 & 0X1F00;
    // 0x800C84BC: jr          $ra
    // 0x800C84C0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x800C84C0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_800C84C4:
    // 0x800C84C4: bne         $v0, $zero, L_800C84D4
    if (ctx->r2 != 0) {
        // 0x800C84C8: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800C84D4;
    }
    // 0x800C84C8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800C84CC: jr          $ra
    // 0x800C84D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C84D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C84D4:
    // 0x800C84D4: lw          $t7, -0x56D0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X56D0);
    // 0x800C84D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800C84DC: addiu       $a0, $a0, -0x56C8
    ctx->r4 = ADD32(ctx->r4, -0X56C8);
    // 0x800C84E0: bne         $v0, $t7, L_800C84F4
    if (ctx->r2 != ctx->r15) {
        // 0x800C84E4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800C84F4;
    }
    // 0x800C84E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800C84E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800C84EC: jr          $ra
    // 0x800C84F0: lw          $v0, -0x56CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X56CC);
    return;
    // 0x800C84F0: lw          $v0, -0x56CC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X56CC);
L_800C84F4:
    // 0x800C84F4: addiu       $v1, $v1, -0x5648
    ctx->r3 = ADD32(ctx->r3, -0X5648);
    // 0x800C84F8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
L_800C84FC:
    // 0x800C84FC: bnel        $v0, $t8, L_800C8510
    if (ctx->r2 != ctx->r24) {
        // 0x800C8500: lw          $t9, 0x8($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X8);
            goto L_800C8510;
    }
    goto skip_0;
    // 0x800C8500: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x800C8504: jr          $ra
    // 0x800C8508: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    return;
    // 0x800C8508: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800C850C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
L_800C8510:
    // 0x800C8510: bnel        $v0, $t9, L_800C8524
    if (ctx->r2 != ctx->r25) {
        // 0x800C8514: lw          $t0, 0x10($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X10);
            goto L_800C8524;
    }
    goto skip_1;
    // 0x800C8514: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    skip_1:
    // 0x800C8518: jr          $ra
    // 0x800C851C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x800C851C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800C8520: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
L_800C8524:
    // 0x800C8524: bnel        $v0, $t0, L_800C8538
    if (ctx->r2 != ctx->r8) {
        // 0x800C8528: lw          $t1, 0x18($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X18);
            goto L_800C8538;
    }
    goto skip_2;
    // 0x800C8528: lw          $t1, 0x18($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X18);
    skip_2:
    // 0x800C852C: jr          $ra
    // 0x800C8530: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    return;
    // 0x800C8530: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x800C8534: lw          $t1, 0x18($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X18);
L_800C8538:
    // 0x800C8538: bnel        $v0, $t1, L_800C854C
    if (ctx->r2 != ctx->r9) {
        // 0x800C853C: addiu       $a0, $a0, 0x20
        ctx->r4 = ADD32(ctx->r4, 0X20);
            goto L_800C854C;
    }
    goto skip_3;
    // 0x800C853C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    skip_3:
    // 0x800C8540: jr          $ra
    // 0x800C8544: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    return;
    // 0x800C8544: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x800C8548: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
L_800C854C:
    // 0x800C854C: bnel        $a0, $v1, L_800C84FC
    if (ctx->r4 != ctx->r3) {
        // 0x800C8550: lw          $t8, 0x0($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X0);
            goto L_800C84FC;
    }
    goto skip_4;
    // 0x800C8550: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    skip_4:
    // 0x800C8554: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C8558: jr          $ra
    // 0x800C855C: nop

    return;
    // 0x800C855C: nop

;}
RECOMP_FUNC void func_80114CF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114CF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80114CF8: sll         $t7, $a2, 13
    ctx->r15 = S32(ctx->r6 << 13);
    // 0x80114CFC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80114D00: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80114D04: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80114D08: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80114D0C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80114D10: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80114D14: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80114D18: bltz        $t7, L_80114D70
    if (SIGNED(ctx->r15) < 0) {
        // 0x80114D1C: sw          $a3, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r7;
            goto L_80114D70;
    }
    // 0x80114D1C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80114D20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80114D24: addiu       $s1, $a0, 0x14
    ctx->r17 = ADD32(ctx->r4, 0X14);
    // 0x80114D28: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80114D2C: addiu       $s3, $zero, 0x24
    ctx->r19 = ADD32(0, 0X24);
L_80114D30:
    // 0x80114D30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80114D34: jal         0x800EE7F8
    // 0x80114D38: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80114D38: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80114D3C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80114D40: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80114D44: bne         $s0, $s3, L_80114D30
    if (ctx->r16 != ctx->r19) {
        // 0x80114D48: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80114D30;
    }
    // 0x80114D48: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80114D4C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80114D50: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80114D54: jal         0x800EE7F8
    // 0x80114D58: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80114D58: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_1:
    // 0x80114D5C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80114D60: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80114D64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80114D68: sb          $t0, 0x3($t9)
    MEM_B(0X3, ctx->r25) = ctx->r8;
    // 0x80114D6C: sw          $t8, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->r24;
L_80114D70:
    // 0x80114D70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80114D74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80114D78: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80114D7C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80114D80: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80114D84: jr          $ra
    // 0x80114D88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80114D88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80114D8C: nop

;}
RECOMP_FUNC void func_800AA2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA2A0: lh          $t6, 0x12($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X12);
    // 0x800AA2A4: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800AA2A8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800AA2AC: bne         $t6, $zero, L_800AA2C4
    if (ctx->r14 != 0) {
        // 0x800AA2B0: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800AA2C4;
    }
    // 0x800AA2B0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800AA2B4: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800AA2B8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800AA2BC: jr          $ra
    // 0x800AA2C0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    return;
    // 0x800AA2C0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800AA2C4:
    // 0x800AA2C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800AA2C8: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800AA2CC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
L_800AA2D0:
    // 0x800AA2D0: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800AA2D4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AA2D8: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800AA2DC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800AA2E0: lh          $v0, 0x12($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X12);
    // 0x800AA2E4: bc1fl       L_800AA334
    if (!c1cs) {
        // 0x800AA2E8: trunc.w.s   $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_800AA334;
    }
    goto skip_0;
    // 0x800AA2E8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_0:
    // 0x800AA2EC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800AA2F0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800AA2F4: nop

    // 0x800AA2F8: div         $zero, $t8, $v0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r2)));
    // 0x800AA2FC: mflo        $t9
    ctx->r25 = lo;
    // 0x800AA300: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800AA304: bne         $v0, $zero, L_800AA310
    if (ctx->r2 != 0) {
        // 0x800AA308: nop
    
            goto L_800AA310;
    }
    // 0x800AA308: nop

    // 0x800AA30C: break       7
    do_break(2148180748);
L_800AA310:
    // 0x800AA310: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA314: bne         $v0, $at, L_800AA328
    if (ctx->r2 != ctx->r1) {
        // 0x800AA318: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AA328;
    }
    // 0x800AA318: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA31C: bne         $t8, $at, L_800AA328
    if (ctx->r24 != ctx->r1) {
        // 0x800AA320: nop
    
            goto L_800AA328;
    }
    // 0x800AA320: nop

    // 0x800AA324: break       6
    do_break(2148180772);
L_800AA328:
    // 0x800AA328: b           L_800AA374
    // 0x800AA32C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
        goto L_800AA374;
    // 0x800AA32C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800AA330: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
L_800AA334:
    // 0x800AA334: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800AA338: nop

    // 0x800AA33C: div         $zero, $t3, $v0
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r2)));
    // 0x800AA340: mflo        $t4
    ctx->r12 = lo;
    // 0x800AA344: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x800AA348: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x800AA34C: bne         $v0, $zero, L_800AA358
    if (ctx->r2 != 0) {
        // 0x800AA350: nop
    
            goto L_800AA358;
    }
    // 0x800AA350: nop

    // 0x800AA354: break       7
    do_break(2148180820);
L_800AA358:
    // 0x800AA358: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA35C: bne         $v0, $at, L_800AA370
    if (ctx->r2 != ctx->r1) {
        // 0x800AA360: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AA370;
    }
    // 0x800AA360: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA364: bne         $t3, $at, L_800AA370
    if (ctx->r11 != ctx->r1) {
        // 0x800AA368: nop
    
            goto L_800AA370;
    }
    // 0x800AA368: nop

    // 0x800AA36C: break       6
    do_break(2148180844);
L_800AA370:
    // 0x800AA370: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
L_800AA374:
    // 0x800AA374: lh          $a1, 0x0($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X0);
    // 0x800AA378: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AA37C: beql        $at, $zero, L_800AA390
    if (ctx->r1 == 0) {
        // 0x800AA380: lh          $a1, 0x6($t1)
        ctx->r5 = MEM_H(ctx->r9, 0X6);
            goto L_800AA390;
    }
    goto skip_1;
    // 0x800AA380: lh          $a1, 0x6($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X6);
    skip_1:
    // 0x800AA384: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x800AA388: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800AA38C: lh          $a1, 0x6($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X6);
L_800AA390:
    // 0x800AA390: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
    // 0x800AA394: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800AA398: beq         $at, $zero, L_800AA3A4
    if (ctx->r1 == 0) {
        // 0x800AA39C: nop
    
            goto L_800AA3A4;
    }
    // 0x800AA39C: nop

    // 0x800AA3A0: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
L_800AA3A4:
    // 0x800AA3A4: bne         $t0, $a2, L_800AA2D0
    if (ctx->r8 != ctx->r6) {
        // 0x800AA3A8: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800AA2D0;
    }
    // 0x800AA3A8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800AA3AC: jr          $ra
    // 0x800AA3B0: nop

    return;
    // 0x800AA3B0: nop

;}
RECOMP_FUNC void func_808000D0_chdrawbridgeswitches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D8: addiu       $a1, $zero, 0xA20
    ctx->r5 = ADD32(0, 0XA20);
    // 0x808000DC: jal         0x80800000
    // 0x808000E0: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80800000_chdrawbridgeswitches(rdram, ctx);
        goto after_0;
    // 0x808000E0: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_0:
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void func_800155BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800155BC: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800155C0: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    // 0x800155C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800155C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800155CC: beq         $a0, $zero, L_800155F8
    if (ctx->r4 == 0) {
        // 0x800155D0: lui         $a1, 0x1
        ctx->r5 = S32(0X1 << 16);
            goto L_800155F8;
    }
    // 0x800155D0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x800155D4: lui         $a2, 0x2
    ctx->r6 = S32(0X2 << 16);
    // 0x800155D8: ori         $a2, $a2, 0x1D80
    ctx->r6 = ctx->r6 | 0X1D80;
    // 0x800155DC: jal         0x80019E98
    // 0x800155E0: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    aligned8_memset(rdram, ctx);
        goto after_0;
    // 0x800155E0: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    after_0:
    // 0x800155E4: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800155E8: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x800155EC: ori         $a1, $a1, 0x1D80
    ctx->r5 = ctx->r5 | 0X1D80;
    // 0x800155F0: jal         0x8002E660
    // 0x800155F4: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x800155F4: lw          $a0, -0x7080($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7080);
    after_1:
L_800155F8:
    // 0x800155F8: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x800155FC: lw          $a0, -0x707C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X707C);
    // 0x80015600: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80015604: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x80015608: beq         $a0, $zero, L_8001562C
    if (ctx->r4 == 0) {
        // 0x8001560C: lui         $a2, 0x2
        ctx->r6 = S32(0X2 << 16);
            goto L_8001562C;
    }
    // 0x8001560C: lui         $a2, 0x2
    ctx->r6 = S32(0X2 << 16);
    // 0x80015610: jal         0x80019E98
    // 0x80015614: ori         $a2, $a2, 0x1D80
    ctx->r6 = ctx->r6 | 0X1D80;
    aligned8_memset(rdram, ctx);
        goto after_2;
    // 0x80015614: ori         $a2, $a2, 0x1D80
    ctx->r6 = ctx->r6 | 0X1D80;
    after_2:
    // 0x80015618: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001561C: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    // 0x80015620: ori         $a1, $a1, 0x1D80
    ctx->r5 = ctx->r5 | 0X1D80;
    // 0x80015624: jal         0x8002E660
    // 0x80015628: lw          $a0, -0x707C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X707C);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_3;
    // 0x80015628: lw          $a0, -0x707C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X707C);
    after_3:
L_8001562C:
    // 0x8001562C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80015630: lw          $a0, -0x7078($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7078);
    // 0x80015634: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80015638: ori         $a1, $a1, 0x1
    ctx->r5 = ctx->r5 | 0X1;
    // 0x8001563C: beq         $a0, $zero, L_80015660
    if (ctx->r4 == 0) {
        // 0x80015640: lui         $a2, 0x1
        ctx->r6 = S32(0X1 << 16);
            goto L_80015660;
    }
    // 0x80015640: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80015644: jal         0x80019E98
    // 0x80015648: ori         $a2, $a2, 0xEC0
    ctx->r6 = ctx->r6 | 0XEC0;
    aligned8_memset(rdram, ctx);
        goto after_4;
    // 0x80015648: ori         $a2, $a2, 0xEC0
    ctx->r6 = ctx->r6 | 0XEC0;
    after_4:
    // 0x8001564C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80015650: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80015654: ori         $a1, $a1, 0xEC0
    ctx->r5 = ctx->r5 | 0XEC0;
    // 0x80015658: jal         0x8002E660
    // 0x8001565C: lw          $a0, -0x7078($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7078);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_5;
    // 0x8001565C: lw          $a0, -0x7078($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7078);
    after_5:
L_80015660:
    // 0x80015660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80015664: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80015668: jr          $ra
    // 0x8001566C: nop

    return;
    // 0x8001566C: nop

;}
RECOMP_FUNC void bskazstilt_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800418: jal         0x80800234
    // 0x8080041C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800234_bskazstilt(rdram, ctx);
        goto after_0;
    // 0x8080041C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800420: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800424: jal         0x800C2FDC
    // 0x80800428: lbu         $a0, 0x160($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X160);
    func_800C2FDC(rdram, ctx);
        goto after_1;
    // 0x80800428: lbu         $a0, 0x160($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X160);
    after_1:
    // 0x8080042C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800434: jr          $ra
    // 0x80800438: nop

    return;
    // 0x80800438: nop

;}
RECOMP_FUNC void func_801094E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801094E0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801094E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801094E8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x801094EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801094F0: addiu       $t6, $t6, 0x461C
    ctx->r14 = ADD32(ctx->r14, 0X461C);
    // 0x801094F4: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x801094F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801094FC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80109500: jal         0x800BBCB8
    // 0x80109504: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80109504: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80109508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010950C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80109510: jr          $ra
    // 0x80109514: nop

    return;
    // 0x80109514: nop

;}
RECOMP_FUNC void func_8080011C_chminelight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800120: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800124: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800128: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8080012C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800130: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800134: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800138: jal         0x80100094
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080013C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800140: lhu         $v1, 0x72($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X72);
    // 0x80800144: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800148: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080014C: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x80800150: beq         $t6, $at, L_80800168
    if (ctx->r14 == ctx->r1) {
        // 0x80800154: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800168;
    }
    // 0x80800154: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800158: beq         $t6, $at, L_808001BC
    if (ctx->r14 == ctx->r1) {
        // 0x8080015C: nop
    
            goto L_808001BC;
    }
    // 0x8080015C: nop

    // 0x80800160: b           L_8080020C
    // 0x80800164: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
        goto L_8080020C;
    // 0x80800164: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
L_80800168:
    // 0x80800168: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1744, 0X640) << 16);
    // 0x8080016C: lwc1        $f4, 0x640($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1744, 0X640));
    // 0x80800170: lwc1        $f6, 0x30($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800174: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800178: nop

    // 0x8080017C: bc1fl       L_808001AC
    if (!c1cs) {
        // 0x80800180: lbu         $t7, 0x72($s1)
        ctx->r15 = MEM_BU(ctx->r17, 0X72);
            goto L_808001AC;
    }
    goto skip_0;
    // 0x80800180: lbu         $t7, 0x72($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X72);
    skip_0:
    // 0x80800184: jal         0x8001210C
    // 0x80800188: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_1;
    // 0x80800188: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x8080018C: beq         $v0, $zero, L_80800208
    if (ctx->r2 == 0) {
        // 0x80800190: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1744, 0X644) << 16);
            goto L_80800208;
    }
    // 0x80800190: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1744, 0X644) << 16);
    // 0x80800194: lwc1        $f8, 0x30($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800198: lwc1        $f10, 0x644($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1744, 0X644));
    // 0x8080019C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x808001A0: b           L_80800208
    // 0x808001A4: swc1        $f16, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f16.u32l;
        goto L_80800208;
    // 0x808001A4: swc1        $f16, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f16.u32l;
    // 0x808001A8: lbu         $t7, 0x72($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X72);
L_808001AC:
    // 0x808001AC: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x808001B0: ori         $t9, $t8, 0xC
    ctx->r25 = ctx->r24 | 0XC;
    // 0x808001B4: b           L_80800208
    // 0x808001B8: sb          $t9, 0x72($s1)
    MEM_B(0X72, ctx->r17) = ctx->r25;
        goto L_80800208;
    // 0x808001B8: sb          $t9, 0x72($s1)
    MEM_B(0X72, ctx->r17) = ctx->r25;
L_808001BC:
    // 0x808001BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1744, 0X648) << 16);
    // 0x808001C0: lwc1        $f20, 0x648($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1744, 0X648));
    // 0x808001C4: lwc1        $f18, 0x30($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X30);
    // 0x808001C8: c.le.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl <= ctx->f18.fl;
    // 0x808001CC: nop

    // 0x808001D0: bc1fl       L_808001FC
    if (!c1cs) {
        // 0x808001D4: lbu         $t0, 0x72($s1)
        ctx->r8 = MEM_BU(ctx->r17, 0X72);
            goto L_808001FC;
    }
    goto skip_1;
    // 0x808001D4: lbu         $t0, 0x72($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X72);
    skip_1:
    // 0x808001D8: jal         0x8001210C
    // 0x808001DC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_2;
    // 0x808001DC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x808001E0: beql        $v0, $zero, L_8080020C
    if (ctx->r2 == 0) {
        // 0x808001E4: lwc1        $f0, 0x30($s1)
        ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
            goto L_8080020C;
    }
    goto skip_2;
    // 0x808001E4: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
    skip_2:
    // 0x808001E8: lwc1        $f4, 0x30($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X30);
    // 0x808001EC: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x808001F0: b           L_80800208
    // 0x808001F4: swc1        $f6, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f6.u32l;
        goto L_80800208;
    // 0x808001F4: swc1        $f6, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f6.u32l;
    // 0x808001F8: lbu         $t0, 0x72($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X72);
L_808001FC:
    // 0x808001FC: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x80800200: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x80800204: sb          $t2, 0x72($s1)
    MEM_B(0X72, ctx->r17) = ctx->r10;
L_80800208:
    // 0x80800208: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
L_8080020C:
    // 0x8080020C: lwc1        $f8, 0x54($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X54);
    // 0x80800210: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1744, 0X64C) << 16);
    // 0x80800214: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x80800218: nop

    // 0x8080021C: bc1t        L_80800470
    if (c1cs) {
        // 0x80800220: nop
    
            goto L_80800470;
    }
    // 0x80800220: nop

    // 0x80800224: lwc1        $f10, 0x64C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1744, 0X64C));
    // 0x80800228: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8080022C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80800230: nop

    // 0x80800234: bc1fl       L_80800318
    if (!c1cs) {
        // 0x80800238: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800318;
    }
    goto skip_3;
    // 0x80800238: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_3:
    // 0x8080023C: jal         0x800DC0C0
    // 0x80800240: nop

    func_800DC0C0(rdram, ctx);
        goto after_3;
    // 0x80800240: nop

    after_3:
    // 0x80800244: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1744, 0X650) << 16);
    // 0x80800248: lwc1        $f16, 0x650($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1744, 0X650));
    // 0x8080024C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800250: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80800254: nop

    // 0x80800258: bc1fl       L_80800318
    if (!c1cs) {
        // 0x8080025C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800318;
    }
    goto skip_4;
    // 0x8080025C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_4:
    // 0x80800260: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800264: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800268: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080026C: jal         0x800DC178
    // 0x80800270: nop

    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800270: nop

    after_4:
    // 0x80800274: lw          $t3, 0x6C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X6C);
    // 0x80800278: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1744, 0X688) << 16);
    // 0x8080027C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80800280: andi        $t4, $t3, 0x1FF
    ctx->r12 = ctx->r11 & 0X1FF;
    // 0x80800284: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80800288: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8080028C: lw          $a0, 0x688($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1744, 0X688));
    // 0x80800290: jal         0x800C8800
    // 0x80800294: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    func_800C8800(rdram, ctx);
        goto after_5;
    // 0x80800294: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    after_5:
    // 0x80800298: lhu         $t6, 0x72($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X72);
    // 0x8080029C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002A0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808002A4: bne         $t7, $at, L_808002E4
    if (ctx->r15 != ctx->r1) {
        // 0x808002A8: nop
    
            goto L_808002E4;
    }
    // 0x808002A8: nop

    // 0x808002AC: jal         0x800DC0C0
    // 0x808002B0: nop

    func_800DC0C0(rdram, ctx);
        goto after_6;
    // 0x808002B0: nop

    after_6:
    // 0x808002B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1744, 0X654) << 16);
    // 0x808002B8: lwc1        $f18, 0x654($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1744, 0X654));
    // 0x808002BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002C0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x808002C4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808002C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1744, 0X660) << 16);
    // 0x808002CC: bc1fl       L_80800318
    if (!c1cs) {
        // 0x808002D0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800318;
    }
    goto skip_5;
    // 0x808002D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_5:
    // 0x808002D4: jal         0x80089D18
    // 0x808002D8: addiu       $a2, $a2, 0x660
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1744, 0X660));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x808002D8: addiu       $a2, $a2, 0x660
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1744, 0X660));
    after_7:
    // 0x808002DC: b           L_80800318
    // 0x808002E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80800318;
    // 0x808002E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808002E4:
    // 0x808002E4: jal         0x800DC0C0
    // 0x808002E8: nop

    func_800DC0C0(rdram, ctx);
        goto after_8;
    // 0x808002E8: nop

    after_8:
    // 0x808002EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1744, 0X658) << 16);
    // 0x808002F0: lwc1        $f4, 0x658($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1744, 0X658));
    // 0x808002F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002F8: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x808002FC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800300: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1744, 0X674) << 16);
    // 0x80800304: bc1fl       L_80800318
    if (!c1cs) {
        // 0x80800308: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800318;
    }
    goto skip_6;
    // 0x80800308: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_6:
    // 0x8080030C: jal         0x80089D18
    // 0x80800310: addiu       $a2, $a2, 0x674
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1744, 0X674));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800310: addiu       $a2, $a2, 0x674
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1744, 0X674));
    after_9:
    // 0x80800314: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800318:
    // 0x80800318: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8080031C: lw          $t8, 0x6C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X6C);
L_80800320:
    // 0x80800320: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800324: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800328: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080032C: mflo        $t0
    ctx->r8 = lo;
    // 0x80800330: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x80800334: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80800338: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8080033C: bgez        $t2, L_80800350
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800340: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80800350;
    }
    // 0x80800340: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800344: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800348: nop

    // 0x8080034C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80800350:
    // 0x80800350: mul.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80800354: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800358: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080035C: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x80800360: nop

    // 0x80800364: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x80800368: lw          $t5, 0x6C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X6C);
    // 0x8080036C: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80800370: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800374: mflo        $t7
    ctx->r15 = lo;
    // 0x80800378: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x8080037C: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x80800380: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800384: bgez        $t9, L_80800398
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800388: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800398;
    }
    // 0x80800388: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080038C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800390: nop

    // 0x80800394: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80800398:
    // 0x80800398: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8080039C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808003A0: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808003A4: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x808003A8: nop

    // 0x808003AC: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x808003B0: lw          $t2, 0x6C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X6C);
    // 0x808003B4: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x808003B8: multu       $t3, $s0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808003BC: mflo        $t4
    ctx->r12 = lo;
    // 0x808003C0: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x808003C4: lbu         $t6, 0x2($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X2);
    // 0x808003C8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x808003CC: bgez        $t6, L_808003E0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808003D0: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_808003E0;
    }
    // 0x808003D0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808003D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808003D8: nop

    // 0x808003DC: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_808003E0:
    // 0x808003E0: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x808003E4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1744, 0X688) << 16);
    // 0x808003E8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x808003EC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x808003F0: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x808003F4: nop

    // 0x808003F8: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x808003FC: lw          $t9, 0x6C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X6C);
    // 0x80800400: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x80800404: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x80800408: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8080040C: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80800410: jal         0x800C8E84
    // 0x80800414: lw          $a0, 0x688($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1744, 0X688));
    func_800C8E84(rdram, ctx);
        goto after_10;
    // 0x80800414: lw          $a0, 0x688($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(1744, 0X688));
    after_10:
    // 0x80800418: lw          $v0, 0x6C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X6C);
    // 0x8080041C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80800420: andi        $t2, $v0, 0x1FF
    ctx->r10 = ctx->r2 & 0X1FF;
    // 0x80800424: sltiu       $at, $t2, 0x8
    ctx->r1 = ctx->r10 < 0X8 ? 1 : 0;
    // 0x80800428: bne         $at, $zero, L_80800448
    if (ctx->r1 != 0) {
        // 0x8080042C: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_80800448;
    }
    // 0x8080042C: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80800430: lhu         $t3, 0x6E($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X6E);
    // 0x80800434: lwc1        $f16, 0x30($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800438: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x8080043C: sh          $t4, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r12;
    // 0x80800440: b           L_80800460
    // 0x80800444: swc1        $f16, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f16.u32l;
        goto L_80800460;
    // 0x80800444: swc1        $f16, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f16.u32l;
L_80800448:
    // 0x80800448: lhu         $t7, 0x6E($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X6E);
    // 0x8080044C: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80800450: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x80800454: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800458: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8080045C: sh          $t9, 0x6E($s1)
    MEM_H(0X6E, ctx->r17) = ctx->r25;
L_80800460:
    // 0x80800460: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800464: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800468: bnel        $v1, $at, L_80800320
    if (ctx->r3 != ctx->r1) {
        // 0x8080046C: lw          $t8, 0x6C($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X6C);
            goto L_80800320;
    }
    goto skip_7;
    // 0x8080046C: lw          $t8, 0x6C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X6C);
    skip_7:
L_80800470:
    // 0x80800470: jal         0x80088F08
    // 0x80800474: addiu       $a0, $zero, 0x1AA
    ctx->r4 = ADD32(0, 0X1AA);
    _idworld_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80800474: addiu       $a0, $zero, 0x1AA
    ctx->r4 = ADD32(0, 0X1AA);
    after_11:
    // 0x80800478: beq         $v0, $zero, L_808004B0
    if (ctx->r2 == 0) {
        // 0x8080047C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808004B0;
    }
    // 0x8080047C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800480: lwc1        $f18, 0x30($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800484: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800488: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8080048C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80800490: lwc1        $f10, 0x30($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800494: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800498: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8080049C: lwc1        $f4, 0x30($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X30);
    // 0x808004A0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x808004A4: lwc1        $f6, 0x30($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X30);
    // 0x808004A8: jal         0x800EDDDC
    // 0x808004AC: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    func_800EDDDC(rdram, ctx);
        goto after_12;
    // 0x808004AC: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    after_12:
L_808004B0:
    // 0x808004B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808004B4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808004B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004BC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808004C0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808004C4: jr          $ra
    // 0x808004C8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x808004C8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_80800068_chworlddoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8080006C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800070: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800074: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8080007C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80800080: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80800084: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800088: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080008C: lbu         $a0, 0x79($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X79);
    // 0x80800090: srl         $t6, $a0, 4
    ctx->r14 = S32(U32(ctx->r4) >> 4);
    // 0x80800094: jal         0x8008A748
    // 0x80800098: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sujiggy_entrypoint_22(rdram, ctx);
        goto after_0;
    // 0x80800098: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8080009C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x808000A0: addiu       $a0, $zero, 0x4DC
    ctx->r4 = ADD32(0, 0X4DC);
    // 0x808000A4: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x808000A8: jal         0x800882C0
    // 0x808000AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808000AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x808000B0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808000B4: blez        $v0, L_80800118
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808000B8: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80800118;
    }
    // 0x808000B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808000BC: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x808000C0: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x808000C4: addiu       $s3, $s3, 0x32
    ctx->r19 = ADD32(ctx->r19, 0X32);
L_808000C8:
    // 0x808000C8: jal         0x80088BE8
    // 0x808000CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808000CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x808000D0: bne         $v0, $s3, L_80800108
    if (ctx->r2 != ctx->r19) {
        // 0x808000D4: addiu       $a1, $s2, 0x18
        ctx->r5 = ADD32(ctx->r18, 0X18);
            goto L_80800108;
    }
    // 0x808000D4: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x808000D8: jal         0x80088C00
    // 0x808000DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808000DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808000E0: jal         0x80088C10
    // 0x808000E4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x808000E4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x808000E8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x808000EC: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x808000F0: jal         0x80088C08
    // 0x808000F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x808000F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x808000F8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808000FC: nop

    // 0x80800100: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800104: swc1        $f6, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f6.u32l;
L_80800108:
    // 0x80800108: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080010C: bne         $s1, $s4, L_808000C8
    if (ctx->r17 != ctx->r20) {
        // 0x80800110: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808000C8;
    }
    // 0x80800110: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800114: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80800118:
    // 0x80800118: addiu       $t8, $s2, 0x18
    ctx->r24 = ADD32(ctx->r18, 0X18);
    // 0x8080011C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80800120: addiu       $a0, $zero, 0x4DD
    ctx->r4 = ADD32(0, 0X4DD);
    // 0x80800124: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80800128: jal         0x800882C0
    // 0x8080012C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _gccubesearch_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x8080012C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
    // 0x80800130: blez        $v0, L_808001A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800134: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_808001A8;
    }
    // 0x80800134: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80800138: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x8080013C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800140: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800144: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x80800148: addiu       $s3, $s3, 0x32
    ctx->r19 = ADD32(ctx->r19, 0X32);
L_8080014C:
    // 0x8080014C: jal         0x80088BE8
    // 0x80800150: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80800150: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80800154: bne         $v0, $s3, L_8080019C
    if (ctx->r2 != ctx->r19) {
        // 0x80800158: addiu       $a1, $s2, 0x28
        ctx->r5 = ADD32(ctx->r18, 0X28);
            goto L_8080019C;
    }
    // 0x80800158: addiu       $a1, $s2, 0x28
    ctx->r5 = ADD32(ctx->r18, 0X28);
    // 0x8080015C: jal         0x80088C00
    // 0x80800160: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800160: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x80800164: jal         0x80088C10
    // 0x80800168: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x80800168: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x8080016C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80800170: nop

    // 0x80800174: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800178: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8080017C: swc1        $f16, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f16.u32l;
    // 0x80800180: jal         0x80088C08
    // 0x80800184: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_10;
    // 0x80800184: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x80800188: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8080018C: nop

    // 0x80800190: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800194: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80800198: swc1        $f6, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f6.u32l;
L_8080019C:
    // 0x8080019C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808001A0: bne         $s1, $s4, L_8080014C
    if (ctx->r17 != ctx->r20) {
        // 0x808001A4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8080014C;
    }
    // 0x808001A4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_808001A8:
    // 0x808001A8: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x808001AC: addiu       $s0, $s2, 0x28
    ctx->r16 = ADD32(ctx->r18, 0X28);
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x808001B8: jal         0x800F18FC
    // 0x808001BC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_800F18FC(rdram, ctx);
        goto after_11;
    // 0x808001BC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_11:
    // 0x808001C0: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x808001C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808001C8: lui         $a2, 0x457A
    ctx->r6 = S32(0X457A << 16);
    // 0x808001CC: swc1        $f8, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f8.u32l;
    // 0x808001D0: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808001D4: swc1        $f10, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f10.u32l;
    // 0x808001D8: jal         0x800EEBF0
    // 0x808001DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_800EEBF0(rdram, ctx);
        goto after_12;
    // 0x808001DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_12:
    // 0x808001E0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808001E4: jal         0x800EF04C
    // 0x808001E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_13;
    // 0x808001E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x808001EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808001F0: lw          $v0, 0x54($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X54);
    // 0x808001F4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808001F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001FC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80800200: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80800204: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80800208: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8080020C: jr          $ra
    // 0x80800210: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800210: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void _bahold_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D30: syscall     134
    recomp_syscall_handler(rdram, ctx, 0x80084D30);
    return;
    // 0x80084D34: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80112D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112D08: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x80112D0C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80112D10: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80112D14: sw          $a1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r5;
    // 0x80112D18: lw          $t7, 0x60($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X60);
    // 0x80112D1C: swc1        $f12, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f12.u32l;
    // 0x80112D20: lw          $t8, 0x60($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X60);
    // 0x80112D24: jr          $ra
    // 0x80112D28: swc1        $f14, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f14.u32l;
    return;
    // 0x80112D28: swc1        $f14, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80025680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025680: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80025684: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80025688: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8002568C: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80025690: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x80025694: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x80025698: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x8002569C: sw          $zero, 0x4($sp)
    MEM_W(0X4, ctx->r29) = 0;
    // 0x800256A0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800256A4: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800256A8: beq         $t0, $zero, L_80025740
    if (ctx->r8 == 0) {
        // 0x800256AC: nop
    
            goto L_80025740;
    }
    // 0x800256AC: nop

L_800256B0:
    // 0x800256B0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800256B4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800256B8: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x800256BC: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x800256C0: addu        $t5, $a0, $t2
    ctx->r13 = ADD32(ctx->r4, ctx->r10);
    // 0x800256C4: sw          $t4, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r12;
    // 0x800256C8: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x800256CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800256D0: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800256D4: lw          $t9, 0x8C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8C);
    // 0x800256D8: addu        $t0, $a0, $t7
    ctx->r8 = ADD32(ctx->r4, ctx->r15);
    // 0x800256DC: sw          $t9, 0x98($t0)
    MEM_W(0X98, ctx->r8) = ctx->r25;
    // 0x800256E0: lw          $t1, 0x4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4);
    // 0x800256E4: addu        $t3, $a1, $t1
    ctx->r11 = ADD32(ctx->r5, ctx->r9);
    // 0x800256E8: lbu         $t2, 0x10C($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X10C);
    // 0x800256EC: addu        $t4, $a0, $t1
    ctx->r12 = ADD32(ctx->r4, ctx->r9);
    // 0x800256F0: sb          $t2, 0x118($t4)
    MEM_B(0X118, ctx->r12) = ctx->r10;
    // 0x800256F4: lw          $t5, 0x4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4);
    // 0x800256F8: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x800256FC: lbu         $t8, 0x12C($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X12C);
    // 0x80025700: addu        $t7, $a0, $t5
    ctx->r15 = ADD32(ctx->r4, ctx->r13);
    // 0x80025704: sb          $t8, 0x138($t7)
    MEM_B(0X138, ctx->r15) = ctx->r24;
    // 0x80025708: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x8002570C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80025710: addu        $t3, $a1, $t0
    ctx->r11 = ADD32(ctx->r5, ctx->r8);
    // 0x80025714: lw          $t1, 0x14C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X14C);
    // 0x80025718: addu        $t2, $a0, $t0
    ctx->r10 = ADD32(ctx->r4, ctx->r8);
    // 0x8002571C: sw          $t1, 0x158($t2)
    MEM_W(0X158, ctx->r10) = ctx->r9;
    // 0x80025720: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x80025724: addiu       $t6, $t4, 0x1
    ctx->r14 = ADD32(ctx->r12, 0X1);
    // 0x80025728: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8002572C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80025730: lw          $t8, 0x4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X4);
    // 0x80025734: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x80025738: bne         $at, $zero, L_800256B0
    if (ctx->r1 != 0) {
        // 0x8002573C: nop
    
            goto L_800256B0;
    }
    // 0x8002573C: nop

L_80025740:
    // 0x80025740: b           L_80025748
    // 0x80025744: nop

        goto L_80025748;
    // 0x80025744: nop

L_80025748:
    // 0x80025748: jr          $ra
    // 0x8002574C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8002574C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_808000C4_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: lhu         $t6, 0x142($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X142);
    // 0x808000C8: beq         $t6, $zero, L_808000D4
    if (ctx->r14 == 0) {
        // 0x808000CC: nop
    
            goto L_808000D4;
    }
    // 0x808000CC: nop

    // 0x808000D0: sh          $zero, 0x142($a0)
    MEM_H(0X142, ctx->r4) = 0;
L_808000D4:
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void func_800293B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800293B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800293B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800293BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800293C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800293C4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800293C8: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800293CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800293D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800293D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800293D8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800293DC: jal         0x80020EE4
    // 0x800293E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_0;
    // 0x800293E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x800293E4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800293E8: sw          $v0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->r2;
    // 0x800293EC: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800293F0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800293F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800293F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800293FC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80029400: jal         0x80020EE4
    // 0x80029404: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_1;
    // 0x80029404: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80029408: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8002940C: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
    // 0x80029410: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80029414: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80029418: jalr        $t9
    // 0x8002941C: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8002941C: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_2:
    // 0x80029420: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80029424: sw          $v0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r2;
    // 0x80029428: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002942C: sw          $zero, 0x34($t1)
    MEM_W(0X34, ctx->r9) = 0;
    // 0x80029430: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80029434: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80029438: sw          $t2, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->r10;
    // 0x8002943C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80029440: sw          $zero, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = 0;
    // 0x80029444: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80029448: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002944C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029454: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80029458: jal         0x80020EE4
    // 0x8002945C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_3;
    // 0x8002945C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80029460: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80029464: sw          $v0, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r2;
    // 0x80029468: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002946C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80029470: swc1        $f4, 0x4C($t7)
    MEM_W(0X4C, ctx->r15) = ctx->f4.u32l;
    // 0x80029474: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80029478: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002947C: sw          $t8, 0x50($t9)
    MEM_W(0X50, ctx->r25) = ctx->r24;
    // 0x80029480: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80029484: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80029488: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002948C: swc1        $f6, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f6.u32l;
    // 0x80029490: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80029494: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
    // 0x80029498: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x8002949C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800294A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800294A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800294A8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800294AC: jal         0x80020EE4
    // 0x800294B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_4;
    // 0x800294B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x800294B4: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800294B8: sw          $v0, 0x54($t3)
    MEM_W(0X54, ctx->r11) = ctx->r2;
    // 0x800294BC: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800294C0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800294C4: sw          $t4, 0x78($t5)
    MEM_W(0X78, ctx->r13) = ctx->r12;
    // 0x800294C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800294CC: sw          $zero, 0x84($t6)
    MEM_W(0X84, ctx->r14) = 0;
    // 0x800294D0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800294D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800294D8: sh          $t7, 0x5A($t8)
    MEM_H(0X5A, ctx->r24) = ctx->r15;
    // 0x800294DC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800294E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800294E4: sh          $t9, 0x68($t0)
    MEM_H(0X68, ctx->r8) = ctx->r25;
    // 0x800294E8: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800294EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800294F0: sh          $t1, 0x6E($t2)
    MEM_H(0X6E, ctx->r10) = ctx->r9;
    // 0x800294F4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800294F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800294FC: sh          $t3, 0x5C($t4)
    MEM_H(0X5C, ctx->r12) = ctx->r11;
    // 0x80029500: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80029504: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80029508: sh          $t5, 0x5E($t6)
    MEM_H(0X5E, ctx->r14) = ctx->r13;
    // 0x8002950C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80029510: sh          $zero, 0x60($t7)
    MEM_H(0X60, ctx->r15) = 0;
    // 0x80029514: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80029518: sh          $zero, 0x62($t8)
    MEM_H(0X62, ctx->r24) = 0;
    // 0x8002951C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80029520: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80029524: sh          $t9, 0x66($t0)
    MEM_H(0X66, ctx->r8) = ctx->r25;
    // 0x80029528: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002952C: sh          $zero, 0x64($t1)
    MEM_H(0X64, ctx->r9) = 0;
    // 0x80029530: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80029534: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80029538: sh          $t2, 0x66($t3)
    MEM_H(0X66, ctx->r11) = ctx->r10;
    // 0x8002953C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80029540: sh          $zero, 0x64($t4)
    MEM_H(0X64, ctx->r12) = 0;
    // 0x80029544: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80029548: sw          $zero, 0x70($t5)
    MEM_W(0X70, ctx->r13) = 0;
    // 0x8002954C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80029550: sw          $zero, 0x74($t6)
    MEM_W(0X74, ctx->r14) = 0;
    // 0x80029554: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80029558: sh          $zero, 0x58($t7)
    MEM_H(0X58, ctx->r15) = 0;
    // 0x8002955C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80029560: sw          $zero, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = 0;
    // 0x80029564: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80029568: sw          $zero, 0x80($t9)
    MEM_W(0X80, ctx->r25) = 0;
    // 0x8002956C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80029570: sb          $zero, 0x8C($t0)
    MEM_B(0X8C, ctx->r8) = 0;
    // 0x80029574: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80029578: sh          $zero, 0x92($t1)
    MEM_H(0X92, ctx->r9) = 0;
    // 0x8002957C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80029580: sh          $zero, 0x90($t2)
    MEM_H(0X90, ctx->r10) = 0;
    // 0x80029584: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x80029588: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002958C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029594: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80029598: jal         0x80020EE4
    // 0x8002959C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80020EE4(rdram, ctx);
        goto after_5;
    // 0x8002959C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x800295A0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800295A4: sw          $v0, 0xBC($t4)
    MEM_W(0XBC, ctx->r12) = ctx->r2;
    // 0x800295A8: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800295AC: sw          $zero, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = 0;
    // 0x800295B0: b           L_800295B8
    // 0x800295B4: nop

        goto L_800295B8;
    // 0x800295B4: nop

L_800295B8:
    // 0x800295B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800295BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800295C0: jr          $ra
    // 0x800295C4: nop

    return;
    // 0x800295C4: nop

    // 0x800295C8: nop

    // 0x800295CC: nop

;}
RECOMP_FUNC void chintrotext_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1120, 0X7D0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x7D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1120, 0X7D0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x7D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1120, 0X7D0));
;}
RECOMP_FUNC void bsstonehead_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010E4: jal         0x80085148
    // 0x808010E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _baspin_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808010E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808010EC: jal         0x80800000
    // 0x808010F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x808010F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808010F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808010FC: jr          $ra
    // 0x80801100: nop

    return;
    // 0x80801100: nop

;}
RECOMP_FUNC void func_8080081C_chtrashcompactor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080081C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800820: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800824: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800828: addiu       $t7, $zero, 0x9F5
    ctx->r15 = ADD32(0, 0X9F5);
    // 0x8080082C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800830: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800834: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800838: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080083C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800840: jal         0x80086898
    // 0x80800844: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800844: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    after_0:
    // 0x80800848: beq         $v0, $zero, L_8080086C
    if (ctx->r2 == 0) {
        // 0x8080084C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8080086C;
    }
    // 0x8080084C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800858: jal         0x800868C8
    // 0x8080085C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x8080085C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_1:
    // 0x80800860: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800864: jal         0x800868C0
    // 0x80800868: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800868: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_2:
L_8080086C:
    // 0x8080086C: jal         0x800C87DC
    // 0x80800870: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800C87DC(rdram, ctx);
        goto after_3;
    // 0x80800870: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80800874: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800878: jal         0x80089CE8
    // 0x8080087C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x8080087C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800880: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800884: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800888: jr          $ra
    // 0x8080088C: nop

    return;
    // 0x8080088C: nop

;}
RECOMP_FUNC void func_80800694_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800694: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800698: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080069C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006A0: jal         0x801022E4
    // 0x808006A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x808006A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808006A8: addiu       $at, $zero, 0x189
    ctx->r1 = ADD32(0, 0X189);
    // 0x808006AC: beq         $v0, $at, L_8080071C
    if (ctx->r2 == ctx->r1) {
        // 0x808006B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080071C;
    }
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B4: addiu       $at, $zero, 0x18A
    ctx->r1 = ADD32(0, 0X18A);
    // 0x808006B8: bne         $v0, $at, L_80800760
    if (ctx->r2 != ctx->r1) {
        // 0x808006BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800760;
    }
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808006C4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X15B0) << 16);
    // 0x808006C8: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x808006CC: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808006D0: addiu       $a2, $a2, 0x15B0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X15B0));
    // 0x808006D4: jal         0x80089D20
    // 0x808006D8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808006D8: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x808006DC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X15C0) << 16);
    // 0x808006E0: lui         $a3, 0x3EB3
    ctx->r7 = S32(0X3EB3 << 16);
    // 0x808006E4: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808006E8: addiu       $a2, $a2, 0x15C0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X15C0));
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F0: jal         0x80089D20
    // 0x808006F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808006F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808006F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X15CC) << 16);
    // 0x808006FC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1020, 0X15DC) << 16);
    // 0x80800700: addiu       $a3, $a3, 0x15DC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1020, 0X15DC));
    // 0x80800704: addiu       $a2, $a2, 0x15CC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X15CC));
    // 0x80800708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080070C: jal         0x80089D28
    // 0x80800710: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800710: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800714: b           L_80800764
    // 0x80800718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800764;
    // 0x80800718: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080071C:
    // 0x8080071C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1020, 0X1600) << 16);
    // 0x80800720: jal         0x80101E4C
    // 0x80800724: addiu       $a1, $a1, 0x1600
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1020, 0X1600));
    func_80101E4C(rdram, ctx);
        goto after_4;
    // 0x80800724: addiu       $a1, $a1, 0x1600
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1020, 0X1600));
    after_4:
    // 0x80800728: beql        $v0, $zero, L_80800764
    if (ctx->r2 == 0) {
        // 0x8080072C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800764;
    }
    goto skip_0;
    // 0x8080072C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800730: lbu         $a0, 0x28($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X28);
    // 0x80800734: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800738: bne         $a0, $zero, L_80800750
    if (ctx->r4 != 0) {
        // 0x8080073C: nop
    
            goto L_80800750;
    }
    // 0x8080073C: nop

    // 0x80800740: jal         0x80089D10
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800748: sb          $v0, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r2;
    // 0x8080074C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
L_80800750:
    // 0x80800750: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1020, 0X15EC) << 16);
    // 0x80800754: addiu       $a2, $a2, 0x15EC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1020, 0X15EC));
    // 0x80800758: jal         0x800C4350
    // 0x8080075C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4350(rdram, ctx);
        goto after_6;
    // 0x8080075C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
L_80800760:
    // 0x80800760: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800764:
    // 0x80800764: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800768: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080076C: jr          $ra
    // 0x80800770: nop

    return;
    // 0x80800770: nop

;}
RECOMP_FUNC void func_8080064C_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080064C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800654: lhu         $v1, 0x15E($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X15E);
    // 0x80800658: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080065C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80800660: srl         $t6, $v1, 15
    ctx->r14 = S32(U32(ctx->r3) >> 15);
    // 0x80800664: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80800668: sll         $t1, $t6, 2
    ctx->r9 = S32(ctx->r14 << 2);
    // 0x8080066C: lbu         $t8, 0x116($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X116);
    // 0x80800670: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80800674: lw          $t3, 0x104($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X104);
    // 0x80800678: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8080067C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80800680: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80800684: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80800688: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8080068C: sh          $t5, 0x118($t7)
    MEM_H(0X118, ctx->r15) = ctx->r13;
    // 0x80800690: lhu         $v1, 0x15E($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X15E);
    // 0x80800694: srl         $t8, $v1, 15
    ctx->r24 = S32(U32(ctx->r3) >> 15);
    // 0x80800698: sll         $t1, $t8, 2
    ctx->r9 = S32(ctx->r24 << 2);
    // 0x8080069C: addu        $t2, $a0, $t8
    ctx->r10 = ADD32(ctx->r4, ctx->r24);
    // 0x808006A0: lbu         $t9, 0x116($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X116);
    // 0x808006A4: addu        $v0, $a0, $t1
    ctx->r2 = ADD32(ctx->r4, ctx->r9);
    // 0x808006A8: lw          $t4, 0x104($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X104);
    // 0x808006AC: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x808006B0: addu        $t6, $t3, $t4
    ctx->r14 = ADD32(ctx->r11, ctx->r12);
    // 0x808006B4: lw          $t5, 0x4($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X4);
    // 0x808006B8: sw          $t5, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->r13;
    // 0x808006BC: lhu         $v1, 0x15E($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X15E);
    // 0x808006C0: srl         $t7, $v1, 15
    ctx->r15 = S32(U32(ctx->r3) >> 15);
    // 0x808006C4: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x808006C8: addu        $t1, $a0, $t8
    ctx->r9 = ADD32(ctx->r4, ctx->r24);
    // 0x808006CC: lh          $a1, 0x118($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X118);
    // 0x808006D0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x808006D4: addu        $a0, $a2, $v1
    ctx->r4 = ADD32(ctx->r6, ctx->r3);
    // 0x808006D8: beq         $a1, $at, L_80800744
    if (ctx->r5 == ctx->r1) {
        // 0x808006DC: addiu       $at, $zero, -0x8
        ctx->r1 = ADD32(0, -0X8);
            goto L_80800744;
    }
    // 0x808006DC: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x808006E0: beq         $a1, $at, L_80800708
    if (ctx->r5 == ctx->r1) {
        // 0x808006E4: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_80800708;
    }
    // 0x808006E4: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x808006E8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x808006EC: beq         $a1, $at, L_80800770
    if (ctx->r5 == ctx->r1) {
        // 0x808006F0: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_80800770;
    }
    // 0x808006F0: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x808006F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808006F8: beq         $a1, $at, L_80800798
    if (ctx->r5 == ctx->r1) {
        // 0x808006FC: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_80800798;
    }
    // 0x808006FC: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80800700: b           L_808007A0
    // 0x80800704: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
        goto L_808007A0;
    // 0x80800704: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
L_80800708:
    // 0x80800708: addu        $t9, $a2, $t2
    ctx->r25 = ADD32(ctx->r6, ctx->r10);
    // 0x8080070C: lw          $t3, 0x10C($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X10C);
    // 0x80800710: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800714: lbu         $a1, 0x0($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X0);
    // 0x80800718: jal         0x80800478
    // 0x8080071C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80800478_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x8080071C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800720: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800724: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800728: lhu         $t4, 0x15E($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X15E);
    // 0x8080072C: srl         $t6, $t4, 15
    ctx->r14 = S32(U32(ctx->r12) >> 15);
    // 0x80800730: addu        $a0, $a2, $t6
    ctx->r4 = ADD32(ctx->r6, ctx->r14);
    // 0x80800734: lbu         $t5, 0x116($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X116);
    // 0x80800738: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8080073C: b           L_80800A40
    // 0x80800740: sb          $t7, 0x116($a0)
    MEM_B(0X116, ctx->r4) = ctx->r15;
        goto L_80800A40;
    // 0x80800740: sb          $t7, 0x116($a0)
    MEM_B(0X116, ctx->r4) = ctx->r15;
L_80800744:
    // 0x80800744: lbu         $t8, 0x116($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X116);
    // 0x80800748: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x8080074C: sb          $t1, 0x116($a0)
    MEM_B(0X116, ctx->r4) = ctx->r9;
    // 0x80800750: lhu         $t2, 0x15E($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X15E);
    // 0x80800754: srl         $t9, $t2, 15
    ctx->r25 = S32(U32(ctx->r10) >> 15);
    // 0x80800758: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8080075C: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x80800760: lw          $t6, 0x10C($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X10C);
    // 0x80800764: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x80800768: b           L_80800A40
    // 0x8080076C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_80800A40;
    // 0x8080076C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80800770:
    // 0x80800770: addu        $t7, $a2, $t5
    ctx->r15 = ADD32(ctx->r6, ctx->r13);
    // 0x80800774: lw          $t8, 0x10C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10C);
    // 0x80800778: addu        $a0, $a2, $v1
    ctx->r4 = ADD32(ctx->r6, ctx->r3);
    // 0x8080077C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800780: lbu         $t1, 0x0($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X0);
    // 0x80800784: sb          $t1, 0x158($a2)
    MEM_B(0X158, ctx->r6) = ctx->r9;
    // 0x80800788: lbu         $t2, 0x116($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X116);
    // 0x8080078C: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x80800790: b           L_80800A40
    // 0x80800794: sb          $t9, 0x116($a0)
    MEM_B(0X116, ctx->r4) = ctx->r25;
        goto L_80800A40;
    // 0x80800794: sb          $t9, 0x116($a0)
    MEM_B(0X116, ctx->r4) = ctx->r25;
L_80800798:
    // 0x80800798: b           L_80800A40
    // 0x8080079C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A40;
    // 0x8080079C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007A0:
    // 0x808007A0: lw          $a0, 0x120($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X120);
    // 0x808007A4: beql        $a0, $zero, L_808007E8
    if (ctx->r4 == 0) {
        // 0x808007A8: lhu         $t8, 0x15E($a2)
        ctx->r24 = MEM_HU(ctx->r6, 0X15E);
            goto L_808007E8;
    }
    goto skip_0;
    // 0x808007A8: lhu         $t8, 0x15E($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X15E);
    skip_0:
    // 0x808007AC: jal         0x80087C18
    // 0x808007B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _gczoombox_entrypoint_39(rdram, ctx);
        goto after_1;
    // 0x808007B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x808007B4: bne         $v0, $zero, L_808007E4
    if (ctx->r2 != 0) {
        // 0x808007B8: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_808007E4;
    }
    // 0x808007B8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808007BC: lhu         $v1, 0x15E($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X15E);
    // 0x808007C0: srl         $t6, $v1, 15
    ctx->r14 = S32(U32(ctx->r3) >> 15);
    // 0x808007C4: addu        $a0, $a2, $t6
    ctx->r4 = ADD32(ctx->r6, ctx->r14);
    // 0x808007C8: lbu         $t0, 0x11C($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X11C);
    // 0x808007CC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x808007D0: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x808007D4: sll         $t5, $t0, 26
    ctx->r13 = S32(ctx->r8 << 26);
    // 0x808007D8: srl         $t7, $t5, 30
    ctx->r15 = S32(U32(ctx->r13) >> 30);
    // 0x808007DC: beq         $t7, $zero, L_8080080C
    if (ctx->r15 == 0) {
        // 0x808007E0: addu        $t1, $a2, $t8
        ctx->r9 = ADD32(ctx->r6, ctx->r24);
            goto L_8080080C;
    }
    // 0x808007E0: addu        $t1, $a2, $t8
    ctx->r9 = ADD32(ctx->r6, ctx->r24);
L_808007E4:
    // 0x808007E4: lhu         $t8, 0x15E($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X15E);
L_808007E8:
    // 0x808007E8: lbu         $t6, 0x15E($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X15E);
    // 0x808007EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808007F0: srl         $t1, $t8, 15
    ctx->r9 = S32(U32(ctx->r24) >> 15);
    // 0x808007F4: xori        $t9, $t1, 0x1
    ctx->r25 = ctx->r9 ^ 0X1;
    // 0x808007F8: sll         $t4, $t9, 7
    ctx->r12 = S32(ctx->r25 << 7);
    // 0x808007FC: andi        $t5, $t6, 0xFF7F
    ctx->r13 = ctx->r14 & 0XFF7F;
    // 0x80800800: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x80800804: b           L_80800A40
    // 0x80800808: sb          $t7, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r15;
        goto L_80800A40;
    // 0x80800808: sb          $t7, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r15;
L_8080080C:
    // 0x8080080C: lh          $t2, 0x118($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X118);
    // 0x80800810: addiu       $t9, $t2, 0xB
    ctx->r25 = ADD32(ctx->r10, 0XB);
    // 0x80800814: sltiu       $at, $t9, 0x8
    ctx->r1 = ctx->r25 < 0X8 ? 1 : 0;
    // 0x80800818: beq         $at, $zero, L_80800A30
    if (ctx->r1 == 0) {
        // 0x8080081C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800A30;
    }
    // 0x8080081C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800820: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2594, 0X2E14) << 16);
    // 0x80800824: addu        $at, $at, $t9
    gpr jr_addend_8080082C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800828: lw          $t9, 0x2E14($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2594, 0X2E14));
    // 0x8080082C: jr          $t9
    // 0x80800830: nop

    switch (jr_addend_8080082C >> 2) {
        case 0: goto L_80800834; break;
        case 1: goto L_80800834; break;
        case 2: goto L_80800A30; break;
        case 3: goto L_80800A30; break;
        case 4: goto L_8080095C; break;
        case 5: goto L_808009E0; break;
        case 6: goto L_80800908; break;
        case 7: goto L_808008B0; break;
        default: switch_error(__func__, 0x8080082C, 0x80802E14);
    }
    // 0x80800830: nop

L_80800834:
    // 0x80800834: addiu       $a3, $zero, -0xB
    ctx->r7 = ADD32(0, -0XB);
    // 0x80800838: addiu       $a1, $zero, -0xA
    ctx->r5 = ADD32(0, -0XA);
    // 0x8080083C: addu        $a0, $a2, $v1
    ctx->r4 = ADD32(ctx->r6, ctx->r3);
L_80800840:
    // 0x80800840: lbu         $t3, 0x116($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X116);
    // 0x80800844: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x80800848: sb          $t6, 0x116($a0)
    MEM_B(0X116, ctx->r4) = ctx->r14;
    // 0x8080084C: lhu         $v1, 0x15E($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X15E);
    // 0x80800850: srl         $t4, $v1, 15
    ctx->r12 = S32(U32(ctx->r3) >> 15);
    // 0x80800854: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x80800858: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x8080085C: lbu         $t7, 0x116($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X116);
    // 0x80800860: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x80800864: lw          $t9, 0x104($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X104);
    // 0x80800868: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8080086C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80800870: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x80800874: lh          $t6, 0x0($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X0);
    // 0x80800878: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x8080087C: sh          $t6, 0x118($t5)
    MEM_H(0X118, ctx->r13) = ctx->r14;
    // 0x80800880: lhu         $v1, 0x15E($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X15E);
    // 0x80800884: srl         $t7, $v1, 15
    ctx->r15 = S32(U32(ctx->r3) >> 15);
    // 0x80800888: sll         $t1, $t7, 1
    ctx->r9 = S32(ctx->r15 << 1);
    // 0x8080088C: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x80800890: lh          $v0, 0x118($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X118);
    // 0x80800894: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80800898: beql        $a1, $v0, L_80800840
    if (ctx->r5 == ctx->r2) {
        // 0x8080089C: addu        $a0, $a2, $v1
        ctx->r4 = ADD32(ctx->r6, ctx->r3);
            goto L_80800840;
    }
    goto skip_1;
    // 0x8080089C: addu        $a0, $a2, $v1
    ctx->r4 = ADD32(ctx->r6, ctx->r3);
    skip_1:
    // 0x808008A0: beql        $a3, $v0, L_80800840
    if (ctx->r7 == ctx->r2) {
        // 0x808008A4: addu        $a0, $a2, $v1
        ctx->r4 = ADD32(ctx->r6, ctx->r3);
            goto L_80800840;
    }
    goto skip_2;
    // 0x808008A4: addu        $a0, $a2, $v1
    ctx->r4 = ADD32(ctx->r6, ctx->r3);
    skip_2:
    // 0x808008A8: b           L_80800A40
    // 0x808008AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A40;
    // 0x808008AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008B0:
    // 0x808008B0: andi        $t8, $t0, 0xFF3F
    ctx->r24 = ctx->r8 & 0XFF3F;
    // 0x808008B4: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x808008B8: sb          $t9, 0x11C($a0)
    MEM_B(0X11C, ctx->r4) = ctx->r25;
    // 0x808008BC: lhu         $t3, 0x15E($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X15E);
    // 0x808008C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808008C4: srl         $t4, $t3, 15
    ctx->r12 = S32(U32(ctx->r11) >> 15);
    // 0x808008C8: addu        $a0, $a2, $t4
    ctx->r4 = ADD32(ctx->r6, ctx->r12);
    // 0x808008CC: lbu         $t6, 0x11C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X11C);
    // 0x808008D0: andi        $t5, $t6, 0xFFCF
    ctx->r13 = ctx->r14 & 0XFFCF;
    // 0x808008D4: ori         $t7, $t5, 0x10
    ctx->r15 = ctx->r13 | 0X10;
    // 0x808008D8: sb          $t7, 0x11C($a0)
    MEM_B(0X11C, ctx->r4) = ctx->r15;
    // 0x808008DC: lbu         $t2, 0x15E($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X15E);
    // 0x808008E0: ori         $t1, $t2, 0x40
    ctx->r9 = ctx->r10 | 0X40;
    // 0x808008E4: sb          $t1, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r9;
    // 0x808008E8: lhu         $t9, 0x15E($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X15E);
    // 0x808008EC: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x808008F0: srl         $t3, $t9, 15
    ctx->r11 = S32(U32(ctx->r25) >> 15);
    // 0x808008F4: xori        $t6, $t3, 0x1
    ctx->r14 = ctx->r11 ^ 0X1;
    // 0x808008F8: sll         $t7, $t6, 7
    ctx->r15 = S32(ctx->r14 << 7);
    // 0x808008FC: or          $t8, $t7, $t2
    ctx->r24 = ctx->r15 | ctx->r10;
    // 0x80800900: b           L_80800A40
    // 0x80800904: sb          $t8, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r24;
        goto L_80800A40;
    // 0x80800904: sb          $t8, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r24;
L_80800908:
    // 0x80800908: andi        $t9, $t0, 0xFF3F
    ctx->r25 = ctx->r8 & 0XFF3F;
    // 0x8080090C: sb          $t9, 0x11C($a0)
    MEM_B(0X11C, ctx->r4) = ctx->r25;
    // 0x80800910: lhu         $t3, 0x15E($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X15E);
    // 0x80800914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800918: srl         $t4, $t3, 15
    ctx->r12 = S32(U32(ctx->r11) >> 15);
    // 0x8080091C: addu        $a0, $a2, $t4
    ctx->r4 = ADD32(ctx->r6, ctx->r12);
    // 0x80800920: lbu         $t6, 0x11C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X11C);
    // 0x80800924: andi        $t5, $t6, 0xFFCF
    ctx->r13 = ctx->r14 & 0XFFCF;
    // 0x80800928: ori         $t1, $t5, 0x10
    ctx->r9 = ctx->r13 | 0X10;
    // 0x8080092C: sb          $t1, 0x11C($a0)
    MEM_B(0X11C, ctx->r4) = ctx->r9;
    // 0x80800930: lbu         $t2, 0x15E($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X15E);
    // 0x80800934: ori         $t7, $t2, 0x40
    ctx->r15 = ctx->r10 | 0X40;
    // 0x80800938: sb          $t7, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r15;
    // 0x8080093C: lhu         $t9, 0x15E($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X15E);
    // 0x80800940: andi        $t2, $t7, 0x7F
    ctx->r10 = ctx->r15 & 0X7F;
    // 0x80800944: srl         $t3, $t9, 15
    ctx->r11 = S32(U32(ctx->r25) >> 15);
    // 0x80800948: xori        $t6, $t3, 0x1
    ctx->r14 = ctx->r11 ^ 0X1;
    // 0x8080094C: sll         $t1, $t6, 7
    ctx->r9 = S32(ctx->r14 << 7);
    // 0x80800950: or          $t8, $t1, $t2
    ctx->r24 = ctx->r9 | ctx->r10;
    // 0x80800954: b           L_80800A40
    // 0x80800958: sb          $t8, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r24;
        goto L_80800A40;
    // 0x80800958: sb          $t8, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r24;
L_8080095C:
    // 0x8080095C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80800960: lbu         $a3, 0x116($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X116);
    // 0x80800964: addu        $t3, $a2, $t9
    ctx->r11 = ADD32(ctx->r6, ctx->r25);
    // 0x80800968: lw          $a1, 0x104($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X104);
    // 0x8080096C: sll         $v0, $a3, 3
    ctx->r2 = S32(ctx->r7 << 3);
    // 0x80800970: andi        $t1, $t0, 0xFF3F
    ctx->r9 = ctx->r8 & 0XFF3F;
    // 0x80800974: addu        $t4, $a1, $v0
    ctx->r12 = ADD32(ctx->r5, ctx->r2);
    // 0x80800978: lh          $t6, 0x0($t4)
    ctx->r14 = MEM_H(ctx->r12, 0X0);
    // 0x8080097C: slti        $at, $t6, -0x5
    ctx->r1 = SIGNED(ctx->r14) < -0X5 ? 1 : 0;
    // 0x80800980: beq         $at, $zero, L_8080099C
    if (ctx->r1 == 0) {
        // 0x80800984: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_8080099C;
    }
    // 0x80800984: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80800988:
    // 0x80800988: addu        $t5, $a1, $v0
    ctx->r13 = ADD32(ctx->r5, ctx->r2);
    // 0x8080098C: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x80800990: slti        $at, $t7, -0x5
    ctx->r1 = SIGNED(ctx->r15) < -0X5 ? 1 : 0;
    // 0x80800994: bnel        $at, $zero, L_80800988
    if (ctx->r1 != 0) {
        // 0x80800998: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80800988;
    }
    goto skip_3;
    // 0x80800998: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    skip_3:
L_8080099C:
    // 0x8080099C: sb          $t1, 0x11C($a0)
    MEM_B(0X11C, ctx->r4) = ctx->r9;
    // 0x808009A0: lhu         $t2, 0x15E($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X15E);
    // 0x808009A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808009A8: srl         $t8, $t2, 15
    ctx->r24 = S32(U32(ctx->r10) >> 15);
    // 0x808009AC: addu        $a0, $a2, $t8
    ctx->r4 = ADD32(ctx->r6, ctx->r24);
    // 0x808009B0: lbu         $t9, 0x116($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X116);
    // 0x808009B4: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x808009B8: sb          $t3, 0x116($a0)
    MEM_B(0X116, ctx->r4) = ctx->r11;
    // 0x808009BC: lhu         $t4, 0x15E($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X15E);
    // 0x808009C0: lbu         $t8, 0x15E($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X15E);
    // 0x808009C4: srl         $t6, $t4, 15
    ctx->r14 = S32(U32(ctx->r12) >> 15);
    // 0x808009C8: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x808009CC: sll         $t2, $t7, 7
    ctx->r10 = S32(ctx->r15 << 7);
    // 0x808009D0: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x808009D4: or          $t3, $t2, $t9
    ctx->r11 = ctx->r10 | ctx->r25;
    // 0x808009D8: b           L_80800A40
    // 0x808009DC: sb          $t3, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r11;
        goto L_80800A40;
    // 0x808009DC: sb          $t3, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r11;
L_808009E0:
    // 0x808009E0: andi        $t4, $t0, 0xFF3F
    ctx->r12 = ctx->r8 & 0XFF3F;
    // 0x808009E4: sb          $t4, 0x11C($a0)
    MEM_B(0X11C, ctx->r4) = ctx->r12;
    // 0x808009E8: lhu         $t6, 0x15E($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X15E);
    // 0x808009EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808009F0: srl         $t5, $t6, 15
    ctx->r13 = S32(U32(ctx->r14) >> 15);
    // 0x808009F4: addu        $a0, $a2, $t5
    ctx->r4 = ADD32(ctx->r6, ctx->r13);
    // 0x808009F8: lbu         $t7, 0x116($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X116);
    // 0x808009FC: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x80800A00: sb          $t1, 0x116($a0)
    MEM_B(0X116, ctx->r4) = ctx->r9;
    // 0x80800A04: lhu         $t8, 0x15E($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X15E);
    // 0x80800A08: lbu         $t5, 0x15E($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X15E);
    // 0x80800A0C: srl         $t2, $t8, 15
    ctx->r10 = S32(U32(ctx->r24) >> 15);
    // 0x80800A10: xori        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 ^ 0X1;
    // 0x80800A14: sll         $t6, $t3, 7
    ctx->r14 = S32(ctx->r11 << 7);
    // 0x80800A18: andi        $t7, $t5, 0xFF7F
    ctx->r15 = ctx->r13 & 0XFF7F;
    // 0x80800A1C: or          $t2, $t6, $t7
    ctx->r10 = ctx->r14 | ctx->r15;
    // 0x80800A20: sb          $t2, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r10;
    // 0x80800A24: ori         $t9, $t2, 0x40
    ctx->r25 = ctx->r10 | 0X40;
    // 0x80800A28: b           L_80800A40
    // 0x80800A2C: sb          $t9, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r25;
        goto L_80800A40;
    // 0x80800A2C: sb          $t9, 0x15E($a2)
    MEM_B(0X15E, ctx->r6) = ctx->r25;
L_80800A30:
    // 0x80800A30: lbu         $t3, 0x116($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X116);
    // 0x80800A34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800A38: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80800A3C: sb          $t4, 0x116($a0)
    MEM_B(0X116, ctx->r4) = ctx->r12;
L_80800A40:
    // 0x80800A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A48: jr          $ra
    // 0x80800A4C: nop

    return;
    // 0x80800A4C: nop

;}
RECOMP_FUNC void func_80800264_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800264: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800268: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080026C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800270: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800274: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800278: jal         0x800EA05C
    // 0x8080027C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x8080027C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800280: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1700, 0X247C) << 16);
    // 0x80800284: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800288: addiu       $s1, $s1, 0x247C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1700, 0X247C));
    // 0x8080028C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800290: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
L_80800294:
    // 0x80800294: jal         0x8080000C
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080000C_chchuffy(rdram, ctx);
        goto after_1;
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080029C: beq         $v0, $s3, L_808002C0
    if (ctx->r2 == ctx->r19) {
        // 0x808002A0: sll         $t6, $s0, 3
        ctx->r14 = S32(ctx->r16 << 3);
            goto L_808002C0;
    }
    // 0x808002A0: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x808002A4: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x808002A8: jal         0x800DA298
    // 0x808002AC: lh          $a0, 0x2($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X2);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808002AC: lh          $a0, 0x2($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X2);
    after_2:
    // 0x808002B0: beql        $v0, $zero, L_808002C4
    if (ctx->r2 == 0) {
        // 0x808002B4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808002C4;
    }
    goto skip_0;
    // 0x808002B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x808002B8: b           L_808002D0
    // 0x808002BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002D0;
    // 0x808002BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002C0:
    // 0x808002C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_808002C4:
    // 0x808002C4: bne         $s0, $s2, L_80800294
    if (ctx->r16 != ctx->r18) {
        // 0x808002C8: nop
    
            goto L_80800294;
    }
    // 0x808002C8: nop

    // 0x808002CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002D0:
    // 0x808002D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808002D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808002DC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808002E0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808002E4: jr          $ra
    // 0x808002E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808002E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800888_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800888: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080088C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800890: jal         0x80800BB8
    // 0x80800894: nop

    func_80800BB8_chcheato(rdram, ctx);
        goto after_0;
    // 0x80800894: nop

    after_0:
    // 0x80800898: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8080089C: jal         0x800D3EF4
    // 0x808008A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D3EF4(rdram, ctx);
        goto after_1;
    // 0x808008A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808008A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808008AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008B0: jr          $ra
    // 0x808008B4: addiu       $v0, $v0, 0x114A
    ctx->r2 = ADD32(ctx->r2, 0X114A);
    return;
    // 0x808008B4: addiu       $v0, $v0, 0x114A
    ctx->r2 = ADD32(ctx->r2, 0X114A);
;}
