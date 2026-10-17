#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800B90_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B98: jal         0x80082838
    // 0x80800B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsbee_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BA4: jal         0x800845D8
    // 0x80800BA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800BA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800BAC: lui         $a2, 0x3F40
    ctx->r6 = S32(0X3F40 << 16);
    // 0x80800BB0: ori         $a2, $a2, 0x75F7
    ctx->r6 = ctx->r6 | 0X75F7;
    // 0x80800BB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BB8: jal         0x800845E0
    // 0x80800BBC: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80800BBC: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    after_2:
    // 0x80800BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BC8: jr          $ra
    // 0x80800BCC: nop

    return;
    // 0x80800BCC: nop

;}
RECOMP_FUNC void dbid_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
    // 0x80800004: addiu       $v0, $a0, 0x2
    ctx->r2 = ADD32(ctx->r4, 0X2);
    // 0x80800008: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8080000C: blez        $a2, L_80800080
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80800010: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80800080;
    }
    // 0x80800010: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80800014:
    // 0x80800014: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80800018: bnel        $a1, $t6, L_80800068
    if (ctx->r5 != ctx->r14) {
        // 0x8080001C: lh          $t0, 0x2($v0)
        ctx->r8 = MEM_H(ctx->r2, 0X2);
            goto L_80800068;
    }
    goto skip_0;
    // 0x8080001C: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    skip_0:
    // 0x80800020: lh          $a1, 0x2($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X2);
    // 0x80800024: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800028: addiu       $a2, $v0, 0x2
    ctx->r6 = ADD32(ctx->r2, 0X2);
    // 0x8080002C: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80800030: bne         $at, $zero, L_8080005C
    if (ctx->r1 != 0) {
        // 0x80800034: sll         $a3, $a1, 1
        ctx->r7 = S32(ctx->r5 << 1);
            goto L_8080005C;
    }
    // 0x80800034: sll         $a3, $a1, 1
    ctx->r7 = S32(ctx->r5 << 1);
L_80800038:
    // 0x80800038: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x8080003C: lh          $t7, 0x4($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X4);
    // 0x80800040: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80800044: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80800048: beq         $t7, $t9, L_80800054
    if (ctx->r15 == ctx->r25) {
        // 0x8080004C: slt         $at, $a0, $a3
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80800054;
    }
    // 0x8080004C: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80800050: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800054:
    // 0x80800054: bne         $at, $zero, L_80800038
    if (ctx->r1 != 0) {
        // 0x80800058: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_80800038;
    }
    // 0x80800058: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8080005C:
    // 0x8080005C: jr          $ra
    // 0x80800060: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x80800060: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80800064: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
L_80800068:
    // 0x80800068: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080006C: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80800070: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80800074: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80800078: bne         $at, $zero, L_80800014
    if (ctx->r1 != 0) {
        // 0x8080007C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80800014;
    }
    // 0x8080007C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80800080:
    // 0x80800080: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800084: jr          $ra
    // 0x80800088: nop

    return;
    // 0x80800088: nop

;}
RECOMP_FUNC void func_808004B4_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808004B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808004BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808004C0: jal         0x8009EF1C
    // 0x808004C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x808004C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: jal         0x8009EF10
    // 0x808004D0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x808004D0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x808004D4: beq         $v0, $zero, L_808004F8
    if (ctx->r2 == 0) {
        // 0x808004D8: lwc1        $f12, 0x24($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
            goto L_808004F8;
    }
    // 0x808004D8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808004DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808004E0: beq         $v0, $at, L_8080050C
    if (ctx->r2 == ctx->r1) {
        // 0x808004E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080050C;
    }
    // 0x808004E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004E8: beql        $v0, $at, L_80800534
    if (ctx->r2 == ctx->r1) {
        // 0x808004EC: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_80800534;
    }
    goto skip_0;
    // 0x808004EC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    skip_0:
    // 0x808004F0: b           L_80800550
    // 0x808004F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800550;
    // 0x808004F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004F8:
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: jal         0x8009B9B0
    // 0x80800500: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800500: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800504: b           L_80800550
    // 0x80800508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800550;
    // 0x80800508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080050C:
    // 0x8080050C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800510: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800514: jal         0x800F1214
    // 0x80800518: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800518: lui         $a2, 0x43C8
    ctx->r6 = S32(0X43C8 << 16);
    after_3:
    // 0x8080051C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800520: jal         0x8009B9B0
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800528: b           L_80800550
    // 0x8080052C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800550;
    // 0x8080052C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800530: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
L_80800534:
    // 0x80800534: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800538: jal         0x800F1214
    // 0x8080053C: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    func_800F1214(rdram, ctx);
        goto after_5;
    // 0x8080053C: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    after_5:
    // 0x80800540: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800544: jal         0x8009B9B0
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080054C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800550:
    // 0x80800550: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800554: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800558: jr          $ra
    // 0x8080055C: nop

    return;
    // 0x8080055C: nop

;}
RECOMP_FUNC void func_800CAA1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAA1C: jr          $ra
    // 0x800CAA20: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    return;
    // 0x800CAA20: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
;}
RECOMP_FUNC void idworldmake_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808000B0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808000B4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808000B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000BC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808000C0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808000C4: jal         0x80088880
    // 0x808000C8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    _glidmake_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808000C8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    after_0:
    // 0x808000CC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808000D0: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x808000D4: addiu       $s2, $v0, 0x2
    ctx->r18 = ADD32(ctx->r2, 0X2);
    // 0x808000D8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x808000DC: blezl       $t6, L_80800420
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808000E0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800420;
    }
    goto skip_0;
    // 0x808000E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_808000E4:
    // 0x808000E4: lh          $a1, 0x0($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X0);
    // 0x808000E8: slti        $at, $a1, 0x65
    ctx->r1 = SIGNED(ctx->r5) < 0X65 ? 1 : 0;
    // 0x808000EC: bne         $at, $zero, L_80800114
    if (ctx->r1 != 0) {
        // 0x808000F0: slti        $at, $a1, 0xC8
        ctx->r1 = SIGNED(ctx->r5) < 0XC8 ? 1 : 0;
            goto L_80800114;
    }
    // 0x808000F0: slti        $at, $a1, 0xC8
    ctx->r1 = SIGNED(ctx->r5) < 0XC8 ? 1 : 0;
    // 0x808000F4: beq         $at, $zero, L_80800114
    if (ctx->r1 == 0) {
        // 0x808000F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800114;
    }
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800100: addiu       $a3, $a1, -0x64
    ctx->r7 = ADD32(ctx->r5, -0X64);
    // 0x80800104: jal         0x80800000
    // 0x80800108: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_1;
    // 0x80800108: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_1:
    // 0x8080010C: b           L_808003FC
    // 0x80800110: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x80800110: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80800114:
    // 0x80800114: slti        $at, $a1, 0xC8
    ctx->r1 = SIGNED(ctx->r5) < 0XC8 ? 1 : 0;
    // 0x80800118: bne         $at, $zero, L_80800140
    if (ctx->r1 != 0) {
        // 0x8080011C: slti        $at, $a1, 0x12C
        ctx->r1 = SIGNED(ctx->r5) < 0X12C ? 1 : 0;
            goto L_80800140;
    }
    // 0x8080011C: slti        $at, $a1, 0x12C
    ctx->r1 = SIGNED(ctx->r5) < 0X12C ? 1 : 0;
    // 0x80800120: beq         $at, $zero, L_80800140
    if (ctx->r1 == 0) {
        // 0x80800124: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800140;
    }
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080012C: addiu       $a3, $a1, -0xC8
    ctx->r7 = ADD32(ctx->r5, -0XC8);
    // 0x80800130: jal         0x80800000
    // 0x80800134: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_2;
    // 0x80800134: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_2:
    // 0x80800138: b           L_808003FC
    // 0x8080013C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x8080013C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80800140:
    // 0x80800140: slti        $at, $a1, 0x12C
    ctx->r1 = SIGNED(ctx->r5) < 0X12C ? 1 : 0;
    // 0x80800144: bne         $at, $zero, L_8080016C
    if (ctx->r1 != 0) {
        // 0x80800148: slti        $at, $a1, 0x190
        ctx->r1 = SIGNED(ctx->r5) < 0X190 ? 1 : 0;
            goto L_8080016C;
    }
    // 0x80800148: slti        $at, $a1, 0x190
    ctx->r1 = SIGNED(ctx->r5) < 0X190 ? 1 : 0;
    // 0x8080014C: beq         $at, $zero, L_8080016C
    if (ctx->r1 == 0) {
        // 0x80800150: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080016C;
    }
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800158: addiu       $a3, $a1, -0x12C
    ctx->r7 = ADD32(ctx->r5, -0X12C);
    // 0x8080015C: jal         0x80800000
    // 0x80800160: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_3;
    // 0x80800160: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_3:
    // 0x80800164: b           L_808003FC
    // 0x80800168: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x80800168: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8080016C:
    // 0x8080016C: slti        $at, $a1, 0x190
    ctx->r1 = SIGNED(ctx->r5) < 0X190 ? 1 : 0;
    // 0x80800170: bne         $at, $zero, L_80800198
    if (ctx->r1 != 0) {
        // 0x80800174: slti        $at, $a1, 0x1F4
        ctx->r1 = SIGNED(ctx->r5) < 0X1F4 ? 1 : 0;
            goto L_80800198;
    }
    // 0x80800174: slti        $at, $a1, 0x1F4
    ctx->r1 = SIGNED(ctx->r5) < 0X1F4 ? 1 : 0;
    // 0x80800178: beq         $at, $zero, L_80800198
    if (ctx->r1 == 0) {
        // 0x8080017C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800198;
    }
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800184: addiu       $a3, $a1, -0x190
    ctx->r7 = ADD32(ctx->r5, -0X190);
    // 0x80800188: jal         0x80800000
    // 0x8080018C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_4;
    // 0x8080018C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_4:
    // 0x80800190: b           L_808003FC
    // 0x80800194: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x80800194: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80800198:
    // 0x80800198: slti        $at, $a1, 0x1F4
    ctx->r1 = SIGNED(ctx->r5) < 0X1F4 ? 1 : 0;
    // 0x8080019C: bne         $at, $zero, L_808001C4
    if (ctx->r1 != 0) {
        // 0x808001A0: slti        $at, $a1, 0x258
        ctx->r1 = SIGNED(ctx->r5) < 0X258 ? 1 : 0;
            goto L_808001C4;
    }
    // 0x808001A0: slti        $at, $a1, 0x258
    ctx->r1 = SIGNED(ctx->r5) < 0X258 ? 1 : 0;
    // 0x808001A4: beq         $at, $zero, L_808001C4
    if (ctx->r1 == 0) {
        // 0x808001A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001C4;
    }
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001AC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808001B0: addiu       $a3, $a1, -0x1F4
    ctx->r7 = ADD32(ctx->r5, -0X1F4);
    // 0x808001B4: jal         0x80800000
    // 0x808001B8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_5;
    // 0x808001B8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_5:
    // 0x808001BC: b           L_808003FC
    // 0x808001C0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x808001C0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808001C4:
    // 0x808001C4: slti        $at, $a1, 0x258
    ctx->r1 = SIGNED(ctx->r5) < 0X258 ? 1 : 0;
    // 0x808001C8: bne         $at, $zero, L_808001F0
    if (ctx->r1 != 0) {
        // 0x808001CC: slti        $at, $a1, 0x2BC
        ctx->r1 = SIGNED(ctx->r5) < 0X2BC ? 1 : 0;
            goto L_808001F0;
    }
    // 0x808001CC: slti        $at, $a1, 0x2BC
    ctx->r1 = SIGNED(ctx->r5) < 0X2BC ? 1 : 0;
    // 0x808001D0: beq         $at, $zero, L_808001F0
    if (ctx->r1 == 0) {
        // 0x808001D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001F0;
    }
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808001DC: addiu       $a3, $a1, -0x258
    ctx->r7 = ADD32(ctx->r5, -0X258);
    // 0x808001E0: jal         0x80800000
    // 0x808001E4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_6;
    // 0x808001E4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_6:
    // 0x808001E8: b           L_808003FC
    // 0x808001EC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x808001EC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808001F0:
    // 0x808001F0: slti        $at, $a1, 0x2BC
    ctx->r1 = SIGNED(ctx->r5) < 0X2BC ? 1 : 0;
    // 0x808001F4: bne         $at, $zero, L_8080021C
    if (ctx->r1 != 0) {
        // 0x808001F8: slti        $at, $a1, 0x320
        ctx->r1 = SIGNED(ctx->r5) < 0X320 ? 1 : 0;
            goto L_8080021C;
    }
    // 0x808001F8: slti        $at, $a1, 0x320
    ctx->r1 = SIGNED(ctx->r5) < 0X320 ? 1 : 0;
    // 0x808001FC: beq         $at, $zero, L_8080021C
    if (ctx->r1 == 0) {
        // 0x80800200: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080021C;
    }
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800204: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800208: addiu       $a3, $a1, -0x2BC
    ctx->r7 = ADD32(ctx->r5, -0X2BC);
    // 0x8080020C: jal         0x80800000
    // 0x80800210: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_7;
    // 0x80800210: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_7:
    // 0x80800214: b           L_808003FC
    // 0x80800218: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x80800218: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8080021C:
    // 0x8080021C: slti        $at, $a1, 0x320
    ctx->r1 = SIGNED(ctx->r5) < 0X320 ? 1 : 0;
    // 0x80800220: bne         $at, $zero, L_80800248
    if (ctx->r1 != 0) {
        // 0x80800224: slti        $at, $a1, 0x384
        ctx->r1 = SIGNED(ctx->r5) < 0X384 ? 1 : 0;
            goto L_80800248;
    }
    // 0x80800224: slti        $at, $a1, 0x384
    ctx->r1 = SIGNED(ctx->r5) < 0X384 ? 1 : 0;
    // 0x80800228: beq         $at, $zero, L_80800248
    if (ctx->r1 == 0) {
        // 0x8080022C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800248;
    }
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800230: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80800234: addiu       $a3, $a1, -0x320
    ctx->r7 = ADD32(ctx->r5, -0X320);
    // 0x80800238: jal         0x80800000
    // 0x8080023C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_8;
    // 0x8080023C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_8:
    // 0x80800240: b           L_808003FC
    // 0x80800244: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x80800244: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80800248:
    // 0x80800248: slti        $at, $a1, 0x384
    ctx->r1 = SIGNED(ctx->r5) < 0X384 ? 1 : 0;
    // 0x8080024C: bne         $at, $zero, L_80800274
    if (ctx->r1 != 0) {
        // 0x80800250: slti        $at, $a1, 0x3E8
        ctx->r1 = SIGNED(ctx->r5) < 0X3E8 ? 1 : 0;
            goto L_80800274;
    }
    // 0x80800250: slti        $at, $a1, 0x3E8
    ctx->r1 = SIGNED(ctx->r5) < 0X3E8 ? 1 : 0;
    // 0x80800254: beq         $at, $zero, L_80800274
    if (ctx->r1 == 0) {
        // 0x80800258: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800274;
    }
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80800260: addiu       $a3, $a1, -0x384
    ctx->r7 = ADD32(ctx->r5, -0X384);
    // 0x80800264: jal         0x80800000
    // 0x80800268: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_9;
    // 0x80800268: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_9:
    // 0x8080026C: b           L_808003FC
    // 0x80800270: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x80800270: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80800274:
    // 0x80800274: slti        $at, $a1, 0x3E8
    ctx->r1 = SIGNED(ctx->r5) < 0X3E8 ? 1 : 0;
    // 0x80800278: bne         $at, $zero, L_808002A0
    if (ctx->r1 != 0) {
        // 0x8080027C: slti        $at, $a1, 0x44C
        ctx->r1 = SIGNED(ctx->r5) < 0X44C ? 1 : 0;
            goto L_808002A0;
    }
    // 0x8080027C: slti        $at, $a1, 0x44C
    ctx->r1 = SIGNED(ctx->r5) < 0X44C ? 1 : 0;
    // 0x80800280: beq         $at, $zero, L_808002A0
    if (ctx->r1 == 0) {
        // 0x80800284: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002A0;
    }
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800288: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8080028C: addiu       $a3, $a1, -0x3E8
    ctx->r7 = ADD32(ctx->r5, -0X3E8);
    // 0x80800290: jal         0x80800000
    // 0x80800294: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_10;
    // 0x80800294: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_10:
    // 0x80800298: b           L_808003FC
    // 0x8080029C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x8080029C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808002A0:
    // 0x808002A0: slti        $at, $a1, 0x44C
    ctx->r1 = SIGNED(ctx->r5) < 0X44C ? 1 : 0;
    // 0x808002A4: bne         $at, $zero, L_808002CC
    if (ctx->r1 != 0) {
        // 0x808002A8: slti        $at, $a1, 0x4B0
        ctx->r1 = SIGNED(ctx->r5) < 0X4B0 ? 1 : 0;
            goto L_808002CC;
    }
    // 0x808002A8: slti        $at, $a1, 0x4B0
    ctx->r1 = SIGNED(ctx->r5) < 0X4B0 ? 1 : 0;
    // 0x808002AC: beq         $at, $zero, L_808002CC
    if (ctx->r1 == 0) {
        // 0x808002B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002CC;
    }
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B4: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x808002B8: addiu       $a3, $a1, -0x44C
    ctx->r7 = ADD32(ctx->r5, -0X44C);
    // 0x808002BC: jal         0x80800000
    // 0x808002C0: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_11;
    // 0x808002C0: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_11:
    // 0x808002C4: b           L_808003FC
    // 0x808002C8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x808002C8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808002CC:
    // 0x808002CC: slti        $at, $a1, 0x4B0
    ctx->r1 = SIGNED(ctx->r5) < 0X4B0 ? 1 : 0;
    // 0x808002D0: bne         $at, $zero, L_808002F8
    if (ctx->r1 != 0) {
        // 0x808002D4: slti        $at, $a1, 0x6A4
        ctx->r1 = SIGNED(ctx->r5) < 0X6A4 ? 1 : 0;
            goto L_808002F8;
    }
    // 0x808002D4: slti        $at, $a1, 0x6A4
    ctx->r1 = SIGNED(ctx->r5) < 0X6A4 ? 1 : 0;
    // 0x808002D8: beq         $at, $zero, L_808002F8
    if (ctx->r1 == 0) {
        // 0x808002DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F8;
    }
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x808002E4: addiu       $a3, $a1, -0x4B0
    ctx->r7 = ADD32(ctx->r5, -0X4B0);
    // 0x808002E8: jal         0x80800000
    // 0x808002EC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_12;
    // 0x808002EC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_12:
    // 0x808002F0: b           L_808003FC
    // 0x808002F4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x808002F4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808002F8:
    // 0x808002F8: slti        $at, $a1, 0x6A4
    ctx->r1 = SIGNED(ctx->r5) < 0X6A4 ? 1 : 0;
    // 0x808002FC: bne         $at, $zero, L_80800324
    if (ctx->r1 != 0) {
        // 0x80800300: slti        $at, $a1, 0x708
        ctx->r1 = SIGNED(ctx->r5) < 0X708 ? 1 : 0;
            goto L_80800324;
    }
    // 0x80800300: slti        $at, $a1, 0x708
    ctx->r1 = SIGNED(ctx->r5) < 0X708 ? 1 : 0;
    // 0x80800304: beq         $at, $zero, L_80800324
    if (ctx->r1 == 0) {
        // 0x80800308: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800324;
    }
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080030C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80800310: addiu       $a3, $a1, -0x6A4
    ctx->r7 = ADD32(ctx->r5, -0X6A4);
    // 0x80800314: jal         0x80800000
    // 0x80800318: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_13;
    // 0x80800318: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_13:
    // 0x8080031C: b           L_808003FC
    // 0x80800320: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x80800320: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80800324:
    // 0x80800324: slti        $at, $a1, 0x708
    ctx->r1 = SIGNED(ctx->r5) < 0X708 ? 1 : 0;
    // 0x80800328: bne         $at, $zero, L_80800350
    if (ctx->r1 != 0) {
        // 0x8080032C: slti        $at, $a1, 0x76C
        ctx->r1 = SIGNED(ctx->r5) < 0X76C ? 1 : 0;
            goto L_80800350;
    }
    // 0x8080032C: slti        $at, $a1, 0x76C
    ctx->r1 = SIGNED(ctx->r5) < 0X76C ? 1 : 0;
    // 0x80800330: beq         $at, $zero, L_80800350
    if (ctx->r1 == 0) {
        // 0x80800334: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800350;
    }
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8080033C: addiu       $a3, $a1, -0x708
    ctx->r7 = ADD32(ctx->r5, -0X708);
    // 0x80800340: jal         0x80800000
    // 0x80800344: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_14;
    // 0x80800344: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_14:
    // 0x80800348: b           L_808003FC
    // 0x8080034C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x8080034C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80800350:
    // 0x80800350: slti        $at, $a1, 0x76C
    ctx->r1 = SIGNED(ctx->r5) < 0X76C ? 1 : 0;
    // 0x80800354: bne         $at, $zero, L_8080037C
    if (ctx->r1 != 0) {
        // 0x80800358: slti        $at, $a1, 0x7D0
        ctx->r1 = SIGNED(ctx->r5) < 0X7D0 ? 1 : 0;
            goto L_8080037C;
    }
    // 0x80800358: slti        $at, $a1, 0x7D0
    ctx->r1 = SIGNED(ctx->r5) < 0X7D0 ? 1 : 0;
    // 0x8080035C: beq         $at, $zero, L_8080037C
    if (ctx->r1 == 0) {
        // 0x80800360: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080037C;
    }
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80800368: addiu       $a3, $a1, -0x76C
    ctx->r7 = ADD32(ctx->r5, -0X76C);
    // 0x8080036C: jal         0x80800000
    // 0x80800370: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_15;
    // 0x80800370: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_15:
    // 0x80800374: b           L_808003FC
    // 0x80800378: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x80800378: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8080037C:
    // 0x8080037C: slti        $at, $a1, 0x7D0
    ctx->r1 = SIGNED(ctx->r5) < 0X7D0 ? 1 : 0;
    // 0x80800380: bne         $at, $zero, L_808003A8
    if (ctx->r1 != 0) {
        // 0x80800384: slti        $at, $a1, 0x834
        ctx->r1 = SIGNED(ctx->r5) < 0X834 ? 1 : 0;
            goto L_808003A8;
    }
    // 0x80800384: slti        $at, $a1, 0x834
    ctx->r1 = SIGNED(ctx->r5) < 0X834 ? 1 : 0;
    // 0x80800388: beq         $at, $zero, L_808003A8
    if (ctx->r1 == 0) {
        // 0x8080038C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003A8;
    }
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800394: addiu       $a3, $a1, -0x7D0
    ctx->r7 = ADD32(ctx->r5, -0X7D0);
    // 0x80800398: jal         0x80800000
    // 0x8080039C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_16;
    // 0x8080039C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_16:
    // 0x808003A0: b           L_808003FC
    // 0x808003A4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x808003A4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808003A8:
    // 0x808003A8: slti        $at, $a1, 0x834
    ctx->r1 = SIGNED(ctx->r5) < 0X834 ? 1 : 0;
    // 0x808003AC: bne         $at, $zero, L_808003D4
    if (ctx->r1 != 0) {
        // 0x808003B0: slti        $at, $a1, 0x898
        ctx->r1 = SIGNED(ctx->r5) < 0X898 ? 1 : 0;
            goto L_808003D4;
    }
    // 0x808003B0: slti        $at, $a1, 0x898
    ctx->r1 = SIGNED(ctx->r5) < 0X898 ? 1 : 0;
    // 0x808003B4: beq         $at, $zero, L_808003D4
    if (ctx->r1 == 0) {
        // 0x808003B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003D4;
    }
    // 0x808003B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003BC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x808003C0: addiu       $a3, $a1, -0x4B0
    ctx->r7 = ADD32(ctx->r5, -0X4B0);
    // 0x808003C4: jal         0x80800000
    // 0x808003C8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_17;
    // 0x808003C8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_17:
    // 0x808003CC: b           L_808003FC
    // 0x808003D0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_808003FC;
    // 0x808003D0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808003D4:
    // 0x808003D4: slti        $at, $a1, 0x898
    ctx->r1 = SIGNED(ctx->r5) < 0X898 ? 1 : 0;
    // 0x808003D8: bne         $at, $zero, L_808003F8
    if (ctx->r1 != 0) {
        // 0x808003DC: slti        $at, $a1, 0x8FC
        ctx->r1 = SIGNED(ctx->r5) < 0X8FC ? 1 : 0;
            goto L_808003F8;
    }
    // 0x808003DC: slti        $at, $a1, 0x8FC
    ctx->r1 = SIGNED(ctx->r5) < 0X8FC ? 1 : 0;
    // 0x808003E0: beq         $at, $zero, L_808003F8
    if (ctx->r1 == 0) {
        // 0x808003E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003F8;
    }
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808003EC: addiu       $a3, $a1, -0x898
    ctx->r7 = ADD32(ctx->r5, -0X898);
    // 0x808003F0: jal         0x80800000
    // 0x808003F4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_80800000_idworldmake(rdram, ctx);
        goto after_18;
    // 0x808003F4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_18:
L_808003F8:
    // 0x808003F8: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808003FC:
    // 0x808003FC: lh          $t7, 0x2($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X2);
    // 0x80800400: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80800404: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80800408: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8080040C: addu        $s2, $s2, $t8
    ctx->r18 = ADD32(ctx->r18, ctx->r24);
    // 0x80800410: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80800414: bne         $at, $zero, L_808000E4
    if (ctx->r1 != 0) {
        // 0x80800418: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_808000E4;
    }
    // 0x80800418: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8080041C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800420:
    // 0x80800420: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800424: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800428: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8080042C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800430: jr          $ra
    // 0x80800434: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800434: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808000A0_chplatuegrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000AC: jal         0x800DA298
    // 0x808000B0: addiu       $a0, $zero, 0x3EA
    ctx->r4 = ADD32(0, 0X3EA);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000B0: addiu       $a0, $zero, 0x3EA
    ctx->r4 = ADD32(0, 0X3EA);
    after_0:
    // 0x808000B4: beq         $v0, $zero, L_808000CC
    if (ctx->r2 == 0) {
        // 0x808000B8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808000CC;
    }
    // 0x808000B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808000C4: jal         0x80102424
    // 0x808000C8: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x808000C8: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    after_1:
L_808000CC:
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void func_800C0064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0068: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800C006C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C0070: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C0074: jal         0x80088068
    // 0x800C0078: addiu       $a0, $a0, -0x7890
    ctx->r4 = ADD32(ctx->r4, -0X7890);
    _gcskyDll_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x800C0078: addiu       $a0, $a0, -0x7890
    ctx->r4 = ADD32(ctx->r4, -0X7890);
    after_0:
    // 0x800C007C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C0080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0084: jr          $ra
    // 0x800C0088: nop

    return;
    // 0x800C0088: nop

    // 0x800C008C: nop

;}
RECOMP_FUNC void func_800DC61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC61C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800DC620: jr          $ra
    // 0x800DC624: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800DC624: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_800C00BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C00BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C00C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C00C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C00C8: jal         0x80087C90
    // 0x800C00CC: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    _gcdialogDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800C00CC: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    after_0:
    // 0x800C00D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C00D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C00D8: jr          $ra
    // 0x800C00DC: nop

    return;
    // 0x800C00DC: nop

;}
RECOMP_FUNC void func_80801C1C_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801C20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801C24: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801C28: jal         0x800D9078
    // 0x80801C2C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80801C2C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x80801C30: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801C34: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801C38: lui         $at, 0xC37A
    ctx->r1 = S32(0XC37A << 16);
    // 0x80801C3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801C40: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801C44: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x80801C48: lwc1        $f12, 0x28($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X28);
    // 0x80801C4C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80801C50: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801C54: jal         0x800F12D4
    // 0x80801C58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F12D4(rdram, ctx);
        goto after_1;
    // 0x80801C58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80801C5C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80801C60: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x80801C64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C68: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80801C6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801C70: jr          $ra
    // 0x80801C74: nop

    return;
    // 0x80801C74: nop

;}
RECOMP_FUNC void _chsmalltrexdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087468: syscall     574
    recomp_syscall_handler(rdram, ctx, 0x80087468);
    return;
    // 0x8008746C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chweldarboss_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1360, 0X47C4) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x47C4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1360, 0X47C4));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x47C4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1360, 0X47C4));
;}
RECOMP_FUNC void basudie_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002C4: jal         0x800964DC
    // 0x808002C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800964DC(rdram, ctx);
        goto after_0;
    // 0x808002C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002CC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x808002D0: jal         0x80096364
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096364(rdram, ctx);
        goto after_1;
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808002D8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E0: jal         0x80085300
    // 0x808002E4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    _batimer_get(rdram, ctx);
        goto after_2;
    // 0x808002E4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x808002E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808002EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002F0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808002F4: nop

    // 0x808002F8: bc1t        L_80800304
    if (c1cs) {
        // 0x808002FC: nop
    
            goto L_80800304;
    }
    // 0x808002FC: nop

    // 0x80800300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800304:
    // 0x80800304: beql        $v0, $zero, L_80800394
    if (ctx->r2 == 0) {
        // 0x80800308: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800394;
    }
    goto skip_0;
    // 0x80800308: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080030C: jal         0x80096544
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096544(rdram, ctx);
        goto after_3;
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800314: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800318: beq         $t6, $zero, L_80800390
    if (ctx->r14 == 0) {
        // 0x8080031C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80800390;
    }
    // 0x8080031C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800320: jal         0x8008E35C
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_4;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800328: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8080032C: beq         $t7, $zero, L_80800390
    if (ctx->r15 == 0) {
        // 0x80800330: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80800390;
    }
    // 0x80800330: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80800334: jal         0x8009C150
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C150(rdram, ctx);
        goto after_5;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080033C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800340: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800344: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800348: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080034C: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800350: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80800354: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800358: nop

    // 0x8080035C: bc1f        L_80800368
    if (!c1cs) {
        // 0x80800360: nop
    
            goto L_80800368;
    }
    // 0x80800360: nop

    // 0x80800364: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800368:
    // 0x80800368: beq         $v0, $zero, L_80800390
    if (ctx->r2 == 0) {
        // 0x8080036C: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80800390;
    }
    // 0x8080036C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800370: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80800374: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800378: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080037C: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x80800380: nop

    // 0x80800384: bc1fl       L_80800394
    if (!c1cs) {
        // 0x80800388: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800394;
    }
    goto skip_1;
    // 0x80800388: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080038C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800390:
    // 0x80800390: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800394:
    // 0x80800394: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800398: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080039C: jr          $ra
    // 0x808003A0: nop

    return;
    // 0x808003A0: nop

;}
RECOMP_FUNC void baboost_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x8080000C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800014: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80800018: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8080001C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800020: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800024: addu        $a0, $a1, $t6
    ctx->r4 = ADD32(ctx->r5, ctx->r14);
    // 0x80800028: bc1tl       L_80800038
    if (c1cs) {
        // 0x8080002C: lwc1        $f6, 0x8($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
            goto L_80800038;
    }
    goto skip_0;
    // 0x8080002C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x80800030: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800034: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
L_80800038:
    // 0x80800038: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8080003C: nop

    // 0x80800040: bc1tl       L_80800050
    if (c1cs) {
        // 0x80800044: lwc1        $f8, 0xC($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
            goto L_80800050;
    }
    goto skip_1;
    // 0x80800044: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    skip_1:
    // 0x80800048: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080004C: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
L_80800050:
    // 0x80800050: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80800054: nop

    // 0x80800058: bc1tl       L_80800068
    if (c1cs) {
        // 0x8080005C: lwc1        $f10, 0x10($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
            goto L_80800068;
    }
    goto skip_2;
    // 0x8080005C: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    skip_2:
    // 0x80800060: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800064: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
L_80800068:
    // 0x80800068: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x8080006C: nop

    // 0x80800070: bc1tl       L_80800080
    if (c1cs) {
        // 0x80800074: lwc1        $f16, 0x14($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
            goto L_80800080;
    }
    goto skip_3;
    // 0x80800074: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    skip_3:
    // 0x80800078: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8080007C: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
L_80800080:
    // 0x80800080: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80800084: nop

    // 0x80800088: bc1t        L_80800094
    if (c1cs) {
        // 0x8080008C: nop
    
            goto L_80800094;
    }
    // 0x8080008C: nop

    // 0x80800090: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800094:
    // 0x80800094: jr          $ra
    // 0x80800098: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80800098: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80800064_bskazspring(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800068: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080006C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800070: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800074: beq         $a1, $zero, L_808000A8
    if (ctx->r5 == 0) {
        // 0x80800078: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_808000A8;
    }
    // 0x80800078: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8080007C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800080: beq         $a1, $at, L_808000C8
    if (ctx->r5 == ctx->r1) {
        // 0x80800084: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000C8;
    }
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080008C: beq         $a1, $at, L_80800168
    if (ctx->r5 == ctx->r1) {
        // 0x80800090: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800168;
    }
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800098: beq         $a1, $at, L_80800218
    if (ctx->r5 == ctx->r1) {
        // 0x8080009C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800218;
    }
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: b           L_8080022C
    // 0x808000A4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
        goto L_8080022C;
    // 0x808000A4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_808000A8:
    // 0x808000A8: jal         0x8009EF60
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_popZone(rdram, ctx);
        goto after_0;
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000B0: jal         0x8009BC6C
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_1;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000B8: jal         0x8009BC90
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_2;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000C0: b           L_8080022C
    // 0x808000C4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
        goto L_8080022C;
    // 0x808000C4: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_808000C8:
    // 0x808000C8: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x808000CC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808000D0: jal         0x8008CCBC
    // 0x808000D4: addiu       $a1, $zero, 0x142
    ctx->r5 = ADD32(0, 0X142);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_3;
    // 0x808000D4: addiu       $a1, $zero, 0x142
    ctx->r5 = ADD32(0, 0X142);
    after_3:
    // 0x808000D8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x808000DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808000EC: jal         0x8009FFD8
    // 0x808000F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_4;
    // 0x808000F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x808000F4: jal         0x8009BB00
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_5;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(284, 0X420) << 16);
    // 0x80800100: lwc1        $f4, 0x420($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(284, 0X420));
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080010C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800110: jal         0x8009B9B0
    // 0x80800114: nop

    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x80800114: nop

    after_6:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x8009BCB4
    // 0x80800120: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_7;
    // 0x80800120: lui         $a1, 0xC496
    ctx->r5 = S32(0XC496 << 16);
    after_7:
    // 0x80800124: lui         $a1, 0xC405
    ctx->r5 = S32(0XC405 << 16);
    // 0x80800128: ori         $a1, $a1, 0x5333
    ctx->r5 = ctx->r5 | 0X5333;
    // 0x8080012C: jal         0x8009BCC4
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_8;
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800134: jal         0x8009EFA8
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_pushZone(rdram, ctx);
        goto after_9;
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080013C: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80800140: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x8009F1C8
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_10;
    // 0x8080014C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800158: jal         0x8009F1C8
    // 0x8080015C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_11;
    // 0x8080015C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_11:
    // 0x80800160: b           L_80800228
    // 0x80800164: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
        goto L_80800228;
    // 0x80800164: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
L_80800168:
    // 0x80800168: jal         0x8009C908
    // 0x8080016C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    yaw_setUpdateType(rdram, ctx);
        goto after_12;
    // 0x8080016C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800174: jal         0x8009D2D8
    // 0x80800178: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_13;
    // 0x80800178: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: jal         0x8009C9C8
    // 0x80800184: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    yaw_rotateTimed(rdram, ctx);
        goto after_14;
    // 0x80800184: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_14:
    // 0x80800188: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8080018C: addiu       $t8, $t8, -0x10FC
    ctx->r24 = ADD32(ctx->r24, -0X10FC);
    // 0x80800190: beq         $t8, $zero, L_808001AC
    if (ctx->r24 == 0) {
        // 0x80800194: nop
    
            goto L_808001AC;
    }
    // 0x80800194: nop

    // 0x80800198: jal         0x8009EEB8
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_15;
    // 0x8080019C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808001A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001A4: jal         0x8009C914
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_16;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_808001AC:
    // 0x808001AC: jal         0x8009C990
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_17;
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808001B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001B8: jal         0x8009B9C0
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_18;
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808001C0: jal         0x8009C990
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_19;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808001C8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808001CC: jal         0x8009BB00
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_20;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808001D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: jal         0x8009BA68
    // 0x808001E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_21;
    // 0x808001E0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_21:
    // 0x808001E4: jal         0x80800000
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bskazspring(rdram, ctx);
        goto after_22;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808001EC: lui         $a1, 0x44A1
    ctx->r5 = S32(0X44A1 << 16);
    // 0x808001F0: ori         $a1, $a1, 0xA000
    ctx->r5 = ctx->r5 | 0XA000;
    // 0x808001F4: jal         0x8009BA58
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_23;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800200: addiu       $a1, $zero, 0x45A5
    ctx->r5 = ADD32(0, 0X45A5);
    // 0x80800204: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800208: jal         0x8009DF18
    // 0x8080020C: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF18(rdram, ctx);
        goto after_24;
    // 0x8080020C: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_24:
    // 0x80800210: b           L_8080022C
    // 0x80800214: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
        goto L_8080022C;
    // 0x80800214: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_80800218:
    // 0x80800218: lui         $a2, 0x3E38
    ctx->r6 = S32(0X3E38 << 16);
    // 0x8080021C: ori         $a2, $a2, 0x51EC
    ctx->r6 = ctx->r6 | 0X51EC;
    // 0x80800220: jal         0x8008CB3C
    // 0x80800224: addiu       $a1, $zero, 0x288
    ctx->r5 = ADD32(0, 0X288);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_25;
    // 0x80800224: addiu       $a1, $zero, 0x288
    ctx->r5 = ADD32(0, 0X288);
    after_25:
L_80800228:
    // 0x80800228: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_8080022C:
    // 0x8080022C: sb          $t9, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r25;
    // 0x80800230: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800234: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800238: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080023C: jr          $ra
    // 0x80800240: nop

    return;
    // 0x80800240: nop

;}
RECOMP_FUNC void _sulights_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A8A0: syscall     854
    recomp_syscall_handler(rdram, ctx, 0x8008A8A0);
    return;
    // 0x8008A8A4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80806C58_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806C58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80806C5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80806C60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80806C64: jal         0x80807BB8
    // 0x80806C68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80807BB8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80806C68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80806C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806C70: jal         0x800936E8
    // 0x80806C74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800936E8(rdram, ctx);
        goto after_1;
    // 0x80806C74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80806C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806C7C: jal         0x8009337C
    // 0x80806C80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009337C(rdram, ctx);
        goto after_2;
    // 0x80806C80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80806C84: jal         0x8009B7C0
    // 0x80806C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_3;
    // 0x80806C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80806C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806C90: jal         0x80801B64
    // 0x80806C94: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801B64_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80806C94: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80806C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80806C9C: jal         0x808061AC
    // 0x80806CA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808061AC_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80806CA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80806CA4: jal         0x800A16BC
    // 0x80806CA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A16BC(rdram, ctx);
        goto after_6;
    // 0x80806CA8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80806CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80806CB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80806CB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80806CB8: jr          $ra
    // 0x80806CBC: nop

    return;
    // 0x80806CBC: nop

;}
RECOMP_FUNC void func_80109BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109BEC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80109BF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80109BF4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80109BF8: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80109BFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80109C00: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80109C04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80109C08: jal         0x801099D0
    // 0x80109C0C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_801099D0(rdram, ctx);
        goto after_0;
    // 0x80109C0C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80109C10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80109C14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80109C18: jr          $ra
    // 0x80109C1C: nop

    return;
    // 0x80109C1C: nop

;}
RECOMP_FUNC void func_8080024C_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800250: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800254: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800258: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8080025C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80800260: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800264: addiu       $s2, $a0, 0x1
    ctx->r18 = ADD32(ctx->r4, 0X1);
    // 0x80800268: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8080026C: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80800270: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80800274: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80800278: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080027C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800280: jal         0x800CC5F4
    // 0x80800284: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800CC5F4(rdram, ctx);
        goto after_0;
    // 0x80800284: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800288: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8080028C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800290: jal         0x800CC63C
    // 0x80800294: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800CC63C(rdram, ctx);
        goto after_1;
    // 0x80800294: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_1:
    // 0x80800298: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8080029C: blez        $s4, L_80800308
    if (SIGNED(ctx->r20) <= 0) {
        // 0x808002A0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800308;
    }
    // 0x808002A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_808002A4:
    // 0x808002A4: beq         $s6, $s0, L_808002FC
    if (ctx->r22 == ctx->r16) {
        // 0x808002A8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_808002FC;
    }
    // 0x808002A8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x808002AC: jal         0x800CC63C
    // 0x808002B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800CC63C(rdram, ctx);
        goto after_2;
    // 0x808002B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x808002B4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808002B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808002BC: jal         0x800EFC7C
    // 0x808002C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800EFC7C(rdram, ctx);
        goto after_3;
    // 0x808002C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x808002C4: lh          $t6, 0xC($s3)
    ctx->r14 = MEM_H(ctx->r19, 0XC);
    // 0x808002C8: lh          $t7, 0xC($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XC);
    // 0x808002CC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x808002D0: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808002D4: mflo        $t8
    ctx->r24 = lo;
    // 0x808002D8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x808002DC: nop

    // 0x808002E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002E4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x808002E8: nop

    // 0x808002EC: bc1fl       L_80800300
    if (!c1cs) {
        // 0x808002F0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800300;
    }
    goto skip_0;
    // 0x808002F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x808002F4: sb          $s0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r16;
    // 0x808002F8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_808002FC:
    // 0x808002FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800300:
    // 0x80800300: bne         $s0, $s4, L_808002A4
    if (ctx->r16 != ctx->r20) {
        // 0x80800304: nop
    
            goto L_808002A4;
    }
    // 0x80800304: nop

L_80800308:
    // 0x80800308: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8080030C: subu        $t9, $s2, $v0
    ctx->r25 = SUB32(ctx->r18, ctx->r2);
    // 0x80800310: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800314: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x80800318: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080031C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80800320: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80800324: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80800328: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8080032C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800330: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800334: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800338: jr          $ra
    // 0x8080033C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080033C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chLagoonInnBlockedWall_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800870E8: syscall     513
    recomp_syscall_handler(rdram, ctx, 0x800870E8);
    return;
    // 0x800870EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _sucoaster_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A190: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A190);
    return;
    // 0x8008A194: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void basnowball_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B4C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800B50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B58: jal         0x800D8FF8
    // 0x80800B5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800B5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800B60: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80800B64: jal         0x800EA068
    // 0x80800B68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800EA068(rdram, ctx);
        goto after_1;
    // 0x80800B68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800B6C: beq         $v0, $zero, L_80800C18
    if (ctx->r2 == 0) {
        // 0x80800B70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C18;
    }
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B74: jal         0x8009E674
    // 0x80800B78: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_8009E674(rdram, ctx);
        goto after_2;
    // 0x80800B78: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80800B7C: bne         $v0, $zero, L_80800C18
    if (ctx->r2 != 0) {
        // 0x80800B80: nop
    
            goto L_80800C18;
    }
    // 0x80800B80: nop

    // 0x80800B84: jal         0x800A1718
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_3;
    // 0x80800B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800B8C: blezl       $v0, L_80800CFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800B90: lw          $v1, 0x110($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X110);
            goto L_80800CFC;
    }
    goto skip_0;
    // 0x80800B90: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    skip_0:
    // 0x80800B94: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    // 0x80800B98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B9C: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80800BA0: lbu         $t6, 0x28($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X28);
    // 0x80800BA4: bnel        $t6, $at, L_80800CFC
    if (ctx->r14 != ctx->r1) {
        // 0x80800BA8: lw          $v1, 0x110($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X110);
            goto L_80800CFC;
    }
    goto skip_1;
    // 0x80800BA8: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    skip_1:
    // 0x80800BAC: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800BB0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800BB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800BB8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800BBC: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x80800BC0: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    // 0x80800BC4: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800BC8: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800BCC: nop

    // 0x80800BD0: bc1fl       L_80800CFC
    if (!c1cs) {
        // 0x80800BD4: lw          $v1, 0x110($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X110);
            goto L_80800CFC;
    }
    goto skip_2;
    // 0x80800BD4: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    skip_2:
    // 0x80800BD8: bne         $v0, $at, L_80800BFC
    if (ctx->r2 != ctx->r1) {
        // 0x80800BDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BFC;
    }
    // 0x80800BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BE0: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800BE4: addiu       $a1, $a1, 0x5130
    ctx->r5 = ADD32(ctx->r5, 0X5130);
    // 0x80800BE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BEC: jal         0x8009919C
    // 0x80800BF0: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    func_8009919C(rdram, ctx);
        goto after_4;
    // 0x80800BF0: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    after_4:
    // 0x80800BF4: b           L_80800CFC
    // 0x80800BF8: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
        goto L_80800CFC;
    // 0x80800BF8: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
L_80800BFC:
    // 0x80800BFC: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80800C00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800C04: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800C08: jal         0x800A17A8
    // 0x80800C0C: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    func_800A17A8(rdram, ctx);
        goto after_5;
    // 0x80800C0C: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    after_5:
    // 0x80800C10: b           L_80800CFC
    // 0x80800C14: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
        goto L_80800CFC;
    // 0x80800C14: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
L_80800C18:
    // 0x80800C18: jal         0x8008DE50
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008DE50(rdram, ctx);
        goto after_6;
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800C20: beql        $v0, $zero, L_80800CFC
    if (ctx->r2 == 0) {
        // 0x80800C24: lw          $v1, 0x110($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X110);
            goto L_80800CFC;
    }
    goto skip_3;
    // 0x80800C24: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    skip_3:
    // 0x80800C28: jal         0x8008E078
    // 0x80800C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_7;
    // 0x80800C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800C30: beql        $v0, $zero, L_80800CFC
    if (ctx->r2 == 0) {
        // 0x80800C34: lw          $v1, 0x110($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X110);
            goto L_80800CFC;
    }
    goto skip_4;
    // 0x80800C34: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    skip_4:
    // 0x80800C38: lw          $t7, 0x110($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X110);
    // 0x80800C3C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800C40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C44: lwc1        $f6, 0xC($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80800C48: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800C4C: nop

    // 0x80800C50: bc1fl       L_80800CFC
    if (!c1cs) {
        // 0x80800C54: lw          $v1, 0x110($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X110);
            goto L_80800CFC;
    }
    goto skip_5;
    // 0x80800C54: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    skip_5:
    // 0x80800C58: jal         0x8080099C
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080099C_basnowball(rdram, ctx);
        goto after_8;
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800C60: jal         0x800A1718
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_9;
    // 0x80800C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C6C: jal         0x800A1760
    // 0x80800C70: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800A1760(rdram, ctx);
        goto after_10;
    // 0x80800C70: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_10:
    // 0x80800C74: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800C78: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800C7C: beql        $at, $zero, L_80800CFC
    if (ctx->r1 == 0) {
        // 0x80800C80: lw          $v1, 0x110($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X110);
            goto L_80800CFC;
    }
    goto skip_6;
    // 0x80800C80: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    skip_6:
    // 0x80800C84: lw          $t8, 0x110($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X110);
    // 0x80800C88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C90: lbu         $t9, 0x28($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X28);
    // 0x80800C94: bnel        $t9, $at, L_80800CFC
    if (ctx->r25 != ctx->r1) {
        // 0x80800C98: lw          $v1, 0x110($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X110);
            goto L_80800CFC;
    }
    goto skip_7;
    // 0x80800C98: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    skip_7:
    // 0x80800C9C: jal         0x80096394
    // 0x80800CA0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    func_80096394(rdram, ctx);
        goto after_11;
    // 0x80800CA0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_11:
    // 0x80800CA4: jal         0x800EEF94
    // 0x80800CA8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_800EEF94(rdram, ctx);
        goto after_12;
    // 0x80800CA8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_12:
    // 0x80800CAC: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    // 0x80800CB0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800CB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800CB8: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CC0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80800CC4: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80800CC8: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    // 0x80800CCC: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800CD0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800CD4: nop

    // 0x80800CD8: bc1fl       L_80800CFC
    if (!c1cs) {
        // 0x80800CDC: lw          $v1, 0x110($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X110);
            goto L_80800CFC;
    }
    goto skip_8;
    // 0x80800CDC: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    skip_8:
    // 0x80800CE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800CE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800CE8: jal         0x800A17A8
    // 0x80800CEC: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    func_800A17A8(rdram, ctx);
        goto after_13;
    // 0x80800CEC: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    after_13:
    // 0x80800CF0: jal         0x800FC660
    // 0x80800CF4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800FC660(rdram, ctx);
        goto after_14;
    // 0x80800CF4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_14:
    // 0x80800CF8: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
L_80800CFC:
    // 0x80800CFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800D00: lbu         $a1, 0x28($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X28);
    // 0x80800D04: beq         $a1, $at, L_80800D1C
    if (ctx->r5 == ctx->r1) {
        // 0x80800D08: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800D1C;
    }
    // 0x80800D08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800D0C: beq         $a1, $at, L_80800DBC
    if (ctx->r5 == ctx->r1) {
        // 0x80800D10: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_80800DBC;
    }
    // 0x80800D10: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800D14: b           L_80800E28
    // 0x80800D18: lbu         $a1, 0x14($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X14);
        goto L_80800E28;
    // 0x80800D18: lbu         $a1, 0x14($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X14);
L_80800D1C:
    // 0x80800D1C: jal         0x800A1718
    // 0x80800D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A1718(rdram, ctx);
        goto after_15;
    // 0x80800D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800D24: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800D28: jal         0x80800084
    // 0x80800D2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800084_basnowball(rdram, ctx);
        goto after_16;
    // 0x80800D2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_16:
    // 0x80800D30: lw          $t0, 0x110($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X110);
    // 0x80800D34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D3C: lwc1        $f6, 0x1C($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x80800D40: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80800D44: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80800D48: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80800D4C: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x80800D50: bc1t        L_80800DB4
    if (c1cs) {
        // 0x80800D54: nop
    
            goto L_80800DB4;
    }
    // 0x80800D54: nop

    // 0x80800D58: jal         0x80800098
    // 0x80800D5C: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    func_80800098_basnowball(rdram, ctx);
        goto after_17;
    // 0x80800D5C: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    after_17:
    // 0x80800D60: lw          $t1, 0x110($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X110);
    // 0x80800D64: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80800D68: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800D6C: lwc1        $f8, 0x1C($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x80800D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D74: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80800D78: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80800D7C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80800D80: bc1f        L_80800D90
    if (!c1cs) {
        // 0x80800D84: nop
    
            goto L_80800D90;
    }
    // 0x80800D84: nop

    // 0x80800D88: b           L_80800DA4
    // 0x80800D8C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800DA4;
    // 0x80800D8C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800D90:
    // 0x80800D90: jal         0x800958A4
    // 0x80800D94: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_800958A4(rdram, ctx);
        goto after_18;
    // 0x80800D94: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_18:
    // 0x80800D98: bne         $v0, $zero, L_80800DA4
    if (ctx->r2 != 0) {
        // 0x80800D9C: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_80800DA4;
    }
    // 0x80800D9C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80800DA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800DA4:
    // 0x80800DA4: beq         $v1, $zero, L_80800DB4
    if (ctx->r3 == 0) {
        // 0x80800DA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DB4;
    }
    // 0x80800DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DAC: jal         0x808001B8
    // 0x80800DB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808001B8_basnowball(rdram, ctx);
        goto after_19;
    // 0x80800DB0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_19:
L_80800DB4:
    // 0x80800DB4: b           L_80800E24
    // 0x80800DB8: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
        goto L_80800E24;
    // 0x80800DB8: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
L_80800DBC:
    // 0x80800DBC: lwc1        $f10, 0x20($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80800DC0: lwc1        $f12, 0x18($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800DC4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800DC8: lw          $a3, 0x24($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X24);
    // 0x80800DCC: jal         0x800F10B4
    // 0x80800DD0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_20;
    // 0x80800DD0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_20:
    // 0x80800DD4: lw          $t2, 0x110($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X110);
    // 0x80800DD8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800DDC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800DE0: swc1        $f0, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f0.u32l;
    // 0x80800DE4: lw          $t3, 0x110($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X110);
    // 0x80800DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800DF0: lwc1        $f16, 0x1C($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x80800DF4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800DF8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80800DFC: jal         0x8009E55C
    // 0x80800E00: nop

    func_8009E55C(rdram, ctx);
        goto after_21;
    // 0x80800E00: nop

    after_21:
    // 0x80800E04: lw          $a0, 0x110($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X110);
    // 0x80800E08: jal         0x800D9078
    // 0x80800E0C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800D9078(rdram, ctx);
        goto after_22;
    // 0x80800E0C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_22:
    // 0x80800E10: beq         $v0, $zero, L_80800E20
    if (ctx->r2 == 0) {
        // 0x80800E14: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E20;
    }
    // 0x80800E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E18: jal         0x808001B8
    // 0x80800E1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808001B8_basnowball(rdram, ctx);
        goto after_23;
    // 0x80800E1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
L_80800E20:
    // 0x80800E20: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
L_80800E24:
    // 0x80800E24: lbu         $a1, 0x14($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X14);
L_80800E28:
    // 0x80800E28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800E2C: beq         $a1, $at, L_80800E44
    if (ctx->r5 == ctx->r1) {
        // 0x80800E30: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800E44;
    }
    // 0x80800E30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E34: beql        $a1, $at, L_80800E74
    if (ctx->r5 == ctx->r1) {
        // 0x80800E38: lwc1        $f0, 0x8($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
            goto L_80800E74;
    }
    goto skip_9;
    // 0x80800E38: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    skip_9:
    // 0x80800E3C: b           L_80800F10
    // 0x80800E40: nop

        goto L_80800F10;
    // 0x80800E40: nop

L_80800E44:
    // 0x80800E44: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800E48: lwc1        $f8, 0x1C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80800E4C: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80800E50: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800E54: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800E58: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800E5C: jal         0x800136E4
    // 0x80800E60: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    func_800136E4(rdram, ctx);
        goto after_24;
    // 0x80800E60: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    after_24:
    // 0x80800E64: lw          $t4, 0x110($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X110);
    // 0x80800E68: b           L_80800F10
    // 0x80800E6C: swc1        $f0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f0.u32l;
        goto L_80800F10;
    // 0x80800E6C: swc1        $f0, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f0.u32l;
    // 0x80800E70: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
L_80800E74:
    // 0x80800E74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800E78: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800E7C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800E80: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x80800E84: nop

    // 0x80800E88: bc1t        L_80800F10
    if (c1cs) {
        // 0x80800E8C: nop
    
            goto L_80800F10;
    }
    // 0x80800E8C: nop

    // 0x80800E90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800E94: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80800E98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800E9C: sub.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80800EA0: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80800EA4: lwc1        $f10, 0x1C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80800EA8: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x80800EAC: mul.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80800EB0: jal         0x800F13F0
    // 0x80800EB4: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    func_800F13F0(rdram, ctx);
        goto after_25;
    // 0x80800EB4: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    after_25:
    // 0x80800EB8: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80800EBC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800EC0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800EC4: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800EC8: jal         0x800F0E00
    // 0x80800ECC: nop

    func_800F0E00(rdram, ctx);
        goto after_26;
    // 0x80800ECC: nop

    after_26:
    // 0x80800ED0: lw          $t5, 0x110($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X110);
    // 0x80800ED4: lwc1        $f8, 0x8($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X8);
    // 0x80800ED8: jal         0x800136E4
    // 0x80800EDC: add.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_27;
    // 0x80800EDC: add.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f0.fl;
    after_27:
    // 0x80800EE0: lw          $t6, 0x110($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X110);
    // 0x80800EE4: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x80800EE8: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    // 0x80800EEC: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800EF0: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800EF4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800EF8: nop

    // 0x80800EFC: bc1f        L_80800F10
    if (!c1cs) {
        // 0x80800F00: nop
    
            goto L_80800F10;
    }
    // 0x80800F00: nop

    // 0x80800F04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800F08: nop

    // 0x80800F0C: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
L_80800F10:
    // 0x80800F10: jal         0x80092AD8
    // 0x80800F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092AD8(rdram, ctx);
        goto after_28;
    // 0x80800F14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80800F18: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80800F1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F20: jal         0x800E0AF0
    // 0x80800F24: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_29;
    // 0x80800F24: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_29:
    // 0x80800F28: lw          $t7, 0x110($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X110);
    // 0x80800F2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800F30: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800F34: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x80800F38: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80800F3C: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x80800F40: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800F44: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80800F48: jal         0x800E0AFC
    // 0x80800F4C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_30;
    // 0x80800F4C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_30:
    // 0x80800F50: lw          $t8, 0x110($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X110);
    // 0x80800F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F58: jal         0x80093230
    // 0x80800F5C: lw          $a1, 0x1C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X1C);
    func_80093230(rdram, ctx);
        goto after_31;
    // 0x80800F5C: lw          $a1, 0x1C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X1C);
    after_31:
    // 0x80800F60: jal         0x80085480
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bawobble_entrypoint_8(rdram, ctx);
        goto after_32;
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800F68: lw          $v1, 0x110($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X110);
    // 0x80800F6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800F70: lbu         $t9, 0x2D($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X2D);
    // 0x80800F74: bnel        $t9, $at, L_80800FB4
    if (ctx->r25 != ctx->r1) {
        // 0x80800F78: lbu         $t2, 0x2C($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X2C);
            goto L_80800FB4;
    }
    goto skip_10;
    // 0x80800F78: lbu         $t2, 0x2C($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2C);
    skip_10:
    // 0x80800F7C: lbu         $t0, 0x2C($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X2C);
    // 0x80800F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F84: bne         $t0, $zero, L_80800F9C
    if (ctx->r8 != 0) {
        // 0x80800F88: nop
    
            goto L_80800F9C;
    }
    // 0x80800F88: nop

    // 0x80800F8C: jal         0x80800008
    // 0x80800F90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800008_basnowball(rdram, ctx);
        goto after_33;
    // 0x80800F90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x80800F94: b           L_80800FD4
    // 0x80800F98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800FD4;
    // 0x80800F98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800F9C:
    // 0x80800F9C: jal         0x808007CC
    // 0x80800FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808007CC_basnowball(rdram, ctx);
        goto after_34;
    // 0x80800FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x80800FA4: lw          $t1, 0x110($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X110);
    // 0x80800FA8: b           L_80800FD0
    // 0x80800FAC: sb          $zero, 0x2C($t1)
    MEM_B(0X2C, ctx->r9) = 0;
        goto L_80800FD0;
    // 0x80800FAC: sb          $zero, 0x2C($t1)
    MEM_B(0X2C, ctx->r9) = 0;
    // 0x80800FB0: lbu         $t2, 0x2C($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2C);
L_80800FB4:
    // 0x80800FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FB8: beql        $t2, $zero, L_80800FD4
    if (ctx->r10 == 0) {
        // 0x80800FBC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800FD4;
    }
    goto skip_11;
    // 0x80800FBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_11:
    // 0x80800FC0: jal         0x80800008
    // 0x80800FC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800008_basnowball(rdram, ctx);
        goto after_35;
    // 0x80800FC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_35:
    // 0x80800FC8: lw          $t3, 0x110($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X110);
    // 0x80800FCC: sb          $zero, 0x2C($t3)
    MEM_B(0X2C, ctx->r11) = 0;
L_80800FD0:
    // 0x80800FD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800FD4:
    // 0x80800FD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800FD8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800FDC: jr          $ra
    // 0x80800FE0: nop

    return;
    // 0x80800FE0: nop

    // 0x80800FE4: nop

    // 0x80800FE8: nop

    // 0x80800FEC: nop

;}
RECOMP_FUNC void sujiggy_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080044C: jal         0x800DA298
    // 0x80800450: addiu       $a0, $zero, 0xD4F
    ctx->r4 = ADD32(0, 0XD4F);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800450: addiu       $a0, $zero, 0xD4F
    ctx->r4 = ADD32(0, 0XD4F);
    after_0:
    // 0x80800454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080045C: jr          $ra
    // 0x80800460: nop

    return;
    // 0x80800460: nop

;}
RECOMP_FUNC void func_80800C14_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C1C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800C20: jal         0x800904C8
    // 0x80800C24: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    func_800904C8(rdram, ctx);
        goto after_0;
    // 0x80800C24: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_0:
    // 0x80800C28: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800C2C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800C30: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    // 0x80800C34: jal         0x800EEB9C
    // 0x80800C38: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_1;
    // 0x80800C38: lw          $a1, 0x48($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X48);
    after_1:
    // 0x80800C3C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800C40: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800C44: jal         0x800EF04C
    // 0x80800C48: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80800C48: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80800C4C: jal         0x800903D0
    // 0x80800C50: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_800903D0(rdram, ctx);
        goto after_3;
    // 0x80800C50: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_3:
    // 0x80800C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800C5C: jr          $ra
    // 0x80800C60: nop

    return;
    // 0x80800C60: nop

;}
RECOMP_FUNC void func_80800C3C_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C3C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800C40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C4C: jal         0x80100094
    // 0x80800C50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C54: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C5C: jal         0x80100094
    // 0x80800C60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800C60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800C64: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800C68: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80800C6C: jal         0x80089DE8
    // 0x80800C70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _suspline_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x80800C70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800C74: jal         0x80089E00
    // 0x80800C78: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _suspline_entrypoint_17(rdram, ctx);
        goto after_3;
    // 0x80800C78: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x80800C7C: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x80800C80: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80800C84: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800C88: jal         0x80089D90
    // 0x80800C8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _suspline_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800C8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800C90: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800C94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800C98: jal         0x80089D90
    // 0x80800C9C: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    _suspline_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800C9C: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    after_5:
    // 0x80800CA0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800CA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800CA8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800CAC: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800CB0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800CB4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80800CB8: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x80800CBC: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x80800CC0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800CC4: jal         0x80089DA0
    // 0x80800CC8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _suspline_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80800CC8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x80800CCC: jal         0x80089D80
    // 0x80800CD0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _suspline_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80800CD0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x80800CD4: beq         $v0, $zero, L_80800D30
    if (ctx->r2 == 0) {
        // 0x80800CD8: lw          $t6, 0x3C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X3C);
            goto L_80800D30;
    }
    // 0x80800CD8: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80800CDC: lbu         $t7, 0x26($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X26);
    // 0x80800CE0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800CE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800CE8: bne         $t7, $at, L_80800D0C
    if (ctx->r15 != ctx->r1) {
        // 0x80800CEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D0C;
    }
    // 0x80800CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CF0: jal         0x808012A4
    // 0x80800CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_8;
    // 0x80800CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CFC: jal         0x808009DC
    // 0x80800D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808009DC_chflysaucer(rdram, ctx);
        goto after_9;
    // 0x80800D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800D04: b           L_80800D2C
    // 0x80800D08: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
        goto L_80800D2C;
    // 0x80800D08: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80800D0C:
    // 0x80800D0C: jal         0x808009DC
    // 0x80800D10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808009DC_chflysaucer(rdram, ctx);
        goto after_10;
    // 0x80800D10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80800D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D18: jal         0x808012A4
    // 0x80800D1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808012A4_chflysaucer(rdram, ctx);
        goto after_11;
    // 0x80800D1C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80800D20: jal         0x808005FC
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005FC_chflysaucer(rdram, ctx);
        goto after_12;
    // 0x80800D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800D28: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80800D2C:
    // 0x80800D2C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80800D30:
    // 0x80800D30: jal         0x80089DF8
    // 0x80800D34: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _suspline_entrypoint_16(rdram, ctx);
        goto after_13;
    // 0x80800D34: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_13:
    // 0x80800D38: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80800D3C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800D40: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80800D44: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80800D48: bgez        $t1, L_80800D84
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800D4C: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80800D84;
    }
    // 0x80800D4C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800D50: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800D54: jal         0x800EFB24
    // 0x80800D58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800EFB24(rdram, ctx);
        goto after_14;
    // 0x80800D58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_14:
    // 0x80800D5C: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
    // 0x80800D60: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800D64: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800D68: jal         0x800EF334
    // 0x80800D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF334(rdram, ctx);
        goto after_15;
    // 0x80800D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800D70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D74: jal         0x800EF04C
    // 0x80800D78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_16;
    // 0x80800D78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x80800D7C: b           L_80800D9C
    // 0x80800D80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800D9C;
    // 0x80800D80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D84:
    // 0x80800D84: jal         0x800EE7F8
    // 0x80800D88: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x80800D88: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_17:
    // 0x80800D8C: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x80800D90: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x80800D94: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
    // 0x80800D98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800D9C:
    // 0x80800D9C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80800DA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800DA4: jr          $ra
    // 0x80800DA8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800DA8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _gcboundDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EC0: syscall     661
    recomp_syscall_handler(rdram, ctx, 0x80087EC0);
    return;
    // 0x80087EC4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bawasher_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853F8: syscall     161
    recomp_syscall_handler(rdram, ctx, 0x800853F8);
    return;
    // 0x800853FC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D6B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6B0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D6B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6B14: jal         0x800D6254
    // 0x800D6B18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800D6254(rdram, ctx);
        goto after_0;
    // 0x800D6B18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D6B1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D6B20: beq         $v0, $at, L_800D6C20
    if (ctx->r2 == ctx->r1) {
        // 0x800D6B24: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D6C20;
    }
    // 0x800D6B24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D6B28: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800D6B2C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800D6B30: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D6B34: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D6B38: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800D6B3C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800D6B40: lw          $t8, 0x7E90($t8)
    if (tooie_more_memory()) ctx->r24 = MEM_W(ctx->r24, 0X7E90); else ctx->r24 = MEM_W(ctx->r24, -0X4800);
    // 0x800D6B44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D6B48: sh          $t6, -0x419C($at)
    MEM_H(-0X419C, ctx->r1) = ctx->r14;
    // 0x800D6B4C: sll         $t9, $t8, 27
    ctx->r25 = S32(ctx->r24 << 27);
    // 0x800D6B50: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x800D6B54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D6B58: bnel        $t0, $at, L_800D6BD4
    if (ctx->r8 != ctx->r1) {
        // 0x800D6B5C: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_800D6BD4;
    }
    goto skip_0;
    // 0x800D6B5C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    skip_0:
    // 0x800D6B60: jal         0x8001211C
    // 0x800D6B64: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8001211C(rdram, ctx);
        goto after_1;
    // 0x800D6B64: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800D6B68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800D6B6C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800D6B70: addiu       $t2, $t2, 0x7E90
    if (tooie_more_memory()) ctx->r10 = ADD32(ctx->r10, 0X7E90); else ctx->r10 = ADD32(ctx->r10, -0X4800);
    // 0x800D6B74: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x800D6B78: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x800D6B7C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800D6B80: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x800D6B84: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800D6B88: srl         $t4, $t3, 5
    ctx->r12 = S32(U32(ctx->r11) >> 5);
    // 0x800D6B8C: bnel        $v0, $t4, L_800D6BC8
    if (ctx->r2 != ctx->r12) {
        // 0x800D6B90: lbu         $t5, 0x9($v1)
        ctx->r13 = MEM_BU(ctx->r3, 0X9);
            goto L_800D6BC8;
    }
    goto skip_1;
    // 0x800D6B90: lbu         $t5, 0x9($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X9);
    skip_1:
    // 0x800D6B94: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800D6B98: sll         $t7, $t5, 14
    ctx->r15 = S32(ctx->r13 << 14);
    // 0x800D6B9C: bgezl       $t7, L_800D6BB8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800D6BA0: lbu         $t2, 0x9($v1)
        ctx->r10 = MEM_BU(ctx->r3, 0X9);
            goto L_800D6BB8;
    }
    goto skip_2;
    // 0x800D6BA0: lbu         $t2, 0x9($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X9);
    skip_2:
    // 0x800D6BA4: lbu         $t9, 0x9($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X9);
    // 0x800D6BA8: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x800D6BAC: b           L_800D6BD0
    // 0x800D6BB0: sb          $t0, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r8;
        goto L_800D6BD0;
    // 0x800D6BB0: sb          $t0, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r8;
    // 0x800D6BB4: lbu         $t2, 0x9($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X9);
L_800D6BB8:
    // 0x800D6BB8: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x800D6BBC: b           L_800D6BD0
    // 0x800D6BC0: sb          $t3, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r11;
        goto L_800D6BD0;
    // 0x800D6BC0: sb          $t3, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r11;
    // 0x800D6BC4: lbu         $t5, 0x9($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X9);
L_800D6BC8:
    // 0x800D6BC8: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x800D6BCC: sb          $t6, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r14;
L_800D6BD0:
    // 0x800D6BD0: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
L_800D6BD4:
    // 0x800D6BD4: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800D6BD8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D6BDC: addiu       $t8, $t8, 0x7E90
    if (tooie_more_memory()) ctx->r24 = ADD32(ctx->r24, 0X7E90); else ctx->r24 = ADD32(ctx->r24, -0X4800);
    // 0x800D6BE0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D6BE4: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800D6BE8: jal         0x8001211C
    // 0x800D6BEC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8001211C(rdram, ctx);
        goto after_2;
    // 0x800D6BEC: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_2:
    // 0x800D6BF0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x800D6BF4: lui         $at, 0x7FF
    ctx->r1 = S32(0X7FF << 16);
    // 0x800D6BF8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800D6BFC: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800D6C00: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x800D6C04: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800D6C08: srl         $t0, $a0, 5
    ctx->r8 = S32(U32(ctx->r4) >> 5);
    // 0x800D6C0C: xor         $t1, $t9, $t0
    ctx->r9 = ctx->r25 ^ ctx->r8;
    // 0x800D6C10: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x800D6C14: xor         $t3, $t2, $a0
    ctx->r11 = ctx->r10 ^ ctx->r4;
    // 0x800D6C18: b           L_800D6C24
    // 0x800D6C1C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_800D6C24;
    // 0x800D6C1C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_800D6C20:
    // 0x800D6C20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D6C24:
    // 0x800D6C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D6C28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D6C2C: jr          $ra
    // 0x800D6C30: nop

    return;
    // 0x800D6C30: nop

;}
RECOMP_FUNC void baswim_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808002EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002F4: jal         0x8009EF28
    // 0x808002F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bastick_getX(rdram, ctx);
        goto after_0;
    // 0x808002F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002FC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: lui         $a1, 0x437A
    ctx->r5 = S32(0X437A << 16);
    // 0x80800308: jal         0x8009C99C
    // 0x8080030C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_1;
    // 0x8080030C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_1:
    // 0x80800310: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800314: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800318: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080031C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800320: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80800324: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800328: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8080032C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800330: jal         0x800F10B4
    // 0x80800334: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80800334: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800338: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080033C: jal         0x8009C4CC
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_setIdeal(rdram, ctx);
        goto after_3;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800344: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(624, 0X5C0) << 16);
    // 0x80800348: lwc1        $f0, 0x5C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(624, 0X5C0));
    // 0x8080034C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800350: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800354: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80800358: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8080035C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80800360: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800364: jal         0x800F10B4
    // 0x80800368: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800368: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x8080036C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80800370: jal         0x80084C90
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800378: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    tooie_swim_turn(rdram, ctx);
    // 0x80800380: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800384: jal         0x8009C990
    // 0x80800388: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    yaw_getIdeal(rdram, ctx);
        goto after_6;
    // 0x80800388: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8080038C: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80800398: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8080039C: jal         0x8009C914
    // 0x808003A0: nop

    yaw_setIdeal(rdram, ctx);
        goto after_7;
    // 0x808003A0: nop

    after_7:
    // 0x808003A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808003B0: jr          $ra
    // 0x808003B4: nop

    return;
    // 0x808003B4: nop

;}
RECOMP_FUNC void gsattract_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800204: jal         0x800A8264
    // 0x80800208: nop

    func_800A8264(rdram, ctx);
        goto after_0;
    // 0x80800208: nop

    after_0:
    // 0x8080020C: bne         $v0, $zero, L_80800254
    if (ctx->r2 != 0) {
        // 0x80800210: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80800254;
    }
    // 0x80800210: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80800214: addiu       $v0, $v0, 0x5470
    ctx->r2 = ADD32(ctx->r2, 0X5470);
    // 0x80800218: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8080021C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2882, 0X493) << 16);
    // 0x80800220: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x80800224: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800228: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8080022C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800230: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800234: lbu         $t8, 0x493($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(2882, 0X493));
    // 0x80800238: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8080023C: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80800240: bne         $at, $zero, L_8080024C
    if (ctx->r1 != 0) {
        // 0x80800244: nop
    
            goto L_8080024C;
    }
    // 0x80800244: nop

    // 0x80800248: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8080024C:
    // 0x8080024C: jal         0x808002A4
    // 0x80800250: nop

    func_808002A4_gsattract(rdram, ctx);
        goto after_1;
    // 0x80800250: nop

    after_1:
L_80800254:
    // 0x80800254: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800258: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080025C: jr          $ra
    // 0x80800260: nop

    return;
    // 0x80800260: nop

;}
RECOMP_FUNC void func_8010B13C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B13C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B144: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010B148: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010B14C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010B150: jal         0x8010C4AC
    // 0x8010B154: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_8010C4AC(rdram, ctx);
        goto after_0;
    // 0x8010B154: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010B158: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8010B15C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8010B160: lwc1        $f4, 0x44($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8010B164: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8010B168: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    // 0x8010B16C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8010B170: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8010B174: jal         0x800EF214
    // 0x8010B178: nop

    func_800EF214(rdram, ctx);
        goto after_1;
    // 0x8010B178: nop

    after_1:
    // 0x8010B17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B180: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B184: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B188: jr          $ra
    // 0x8010B18C: nop

    return;
    // 0x8010B18C: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080043C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800440: lbu         $t6, 0x75F0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X75F0);
    // 0x80800444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800448: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080044C: beq         $t6, $at, L_8080045C
    if (ctx->r14 == ctx->r1) {
        // 0x80800450: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8080045C;
    }
    // 0x80800450: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800454: jal         0x80800018
    // 0x80800458: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80800018_glcutDll(rdram, ctx);
        goto after_0;
    // 0x80800458: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
L_8080045C:
    // 0x8080045C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800464: jr          $ra
    // 0x80800468: nop

    return;
    // 0x80800468: nop

;}
RECOMP_FUNC void func_80800A98_sudeflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A98: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800A9C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80800AA0: lui         $s6, 0x8080
    ctx->r22 = S32(RELOC_HI16(3222, 0X1020) << 16);
    // 0x80800AA4: lw          $s6, 0x1020($s6)
    ctx->r22 = MEM_W(ctx->r22, (int16_t)RELOC_LO16(3222, 0X1020));
    // 0x80800AA8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800AAC: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80800AB0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800AB4: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80800AB8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80800ABC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80800AC0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80800AC4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80800AC8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80800ACC: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80800AD0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80800AD4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800AD8: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x80800ADC: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80800AE0: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80800AE4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800AE8: beq         $a1, $zero, L_80800BB0
    if (ctx->r5 == 0) {
        // 0x80800AEC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800BB0;
    }
    // 0x80800AEC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800AF0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800AF4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800AF8: addiu       $s5, $zero, 0x27A
    ctx->r21 = ADD32(0, 0X27A);
L_80800AFC:
    // 0x80800AFC: jal         0x800E9E88
    // 0x80800B00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800E9E88(rdram, ctx);
        goto after_0;
    // 0x80800B00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800B04: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800B08: jal         0x800E9EB4
    // 0x80800B0C: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_1;
    // 0x80800B0C: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_1:
    // 0x80800B10: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80800B14: beq         $at, $zero, L_80800BA0
    if (ctx->r1 == 0) {
        // 0x80800B18: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80800BA0;
    }
    // 0x80800B18: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800B1C: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
L_80800B20:
    // 0x80800B20: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80800B24: beql        $t7, $zero, L_80800B94
    if (ctx->r15 == 0) {
        // 0x80800B28: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800B94;
    }
    goto skip_0;
    // 0x80800B28: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_0:
    // 0x80800B2C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80800B30: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80800B34: srl         $t9, $t8, 22
    ctx->r25 = S32(U32(ctx->r24) >> 22);
    // 0x80800B38: bnel        $s5, $t9, L_80800B94
    if (ctx->r21 != ctx->r25) {
        // 0x80800B3C: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_80800B94;
    }
    goto skip_1;
    // 0x80800B3C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    skip_1:
    // 0x80800B40: jal         0x80106790
    // 0x80800B44: nop

    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800B44: nop

    after_2:
    // 0x80800B48: lw          $t0, 0x64($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X64);
    // 0x80800B4C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800B50: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800B54: sll         $t2, $t0, 14
    ctx->r10 = S32(ctx->r8 << 14);
    // 0x80800B58: bltz        $t2, L_80800B90
    if (SIGNED(ctx->r10) < 0) {
        // 0x80800B5C: addiu       $t3, $v0, 0x4
        ctx->r11 = ADD32(ctx->r2, 0X4);
            goto L_80800B90;
    }
    // 0x80800B5C: addiu       $t3, $v0, 0x4
    ctx->r11 = ADD32(ctx->r2, 0X4);
    // 0x80800B60: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80800B64: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80800B68: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80800B6C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800B70: jal         0x80800E44
    // 0x80800B74: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    func_80800E44_sudeflect(rdram, ctx);
        goto after_3;
    // 0x80800B74: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    after_3:
    // 0x80800B78: beq         $v0, $zero, L_80800B90
    if (ctx->r2 == 0) {
        // 0x80800B7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B90;
    }
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B80: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800B84: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800B88: jal         0x8010108C
    // 0x80800B8C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    func_8010108C(rdram, ctx);
        goto after_4;
    // 0x80800B8C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_4:
L_80800B90:
    // 0x80800B90: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_80800B94:
    // 0x80800B94: sltu        $at, $s1, $s3
    ctx->r1 = ctx->r17 < ctx->r19 ? 1 : 0;
    // 0x80800B98: bnel        $at, $zero, L_80800B20
    if (ctx->r1 != 0) {
        // 0x80800B9C: lw          $t6, 0x8($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X8);
            goto L_80800B20;
    }
    goto skip_2;
    // 0x80800B9C: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    skip_2:
L_80800BA0:
    // 0x80800BA0: lw          $a1, 0x4($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X4);
    // 0x80800BA4: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80800BA8: bne         $a1, $zero, L_80800AFC
    if (ctx->r5 != 0) {
        // 0x80800BAC: nop
    
            goto L_80800AFC;
    }
    // 0x80800BAC: nop

L_80800BB0:
    // 0x80800BB0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80800BB4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80800BB8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80800BBC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800BC0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800BC4: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80800BC8: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800BCC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80800BD0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80800BD4: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80800BD8: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80800BDC: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80800BE0: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80800BE4: jr          $ra
    // 0x80800BE8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800BE8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800D37FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D37FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D3800: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D3804: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800D3808: addiu       $s0, $s0, -0x4C10
    ctx->r16 = ADD32(ctx->r16, -0X4C10);
    // 0x800D380C: lbu         $t6, 0x9($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X9);
    // 0x800D3810: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D3814: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D3818: bnel        $t6, $at, L_800D3864
    if (ctx->r14 != ctx->r1) {
        // 0x800D381C: lb          $a0, 0x0($s0)
        ctx->r4 = MEM_B(ctx->r16, 0X0);
            goto L_800D3864;
    }
    goto skip_0;
    // 0x800D381C: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
    skip_0:
    // 0x800D3820: jal         0x8001B798
    // 0x800D3824: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800D3824: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    after_0:
    // 0x800D3828: jal         0x80088580
    // 0x800D382C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _glgamedata_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x800D382C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800D3830: jal         0x8001B754
    // 0x800D3834: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    func_8001B754(rdram, ctx);
        goto after_2;
    // 0x800D3834: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    after_2:
    // 0x800D3838: lb          $t7, 0x8($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X8);
    // 0x800D383C: lbu         $t8, 0xB($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0XB);
    // 0x800D3840: lbu         $t9, 0xA($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XA);
    // 0x800D3844: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800D3848: sb          $zero, 0x9($s0)
    MEM_B(0X9, ctx->r16) = 0;
    // 0x800D384C: sb          $t0, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r8;
    // 0x800D3850: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x800D3854: sb          $t7, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r15;
    // 0x800D3858: sb          $t8, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r24;
    // 0x800D385C: sb          $t9, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r25;
    // 0x800D3860: lb          $a0, 0x0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X0);
L_800D3864:
    // 0x800D3864: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D3868: beq         $a0, $at, L_800D3880
    if (ctx->r4 == ctx->r1) {
        // 0x800D386C: nop
    
            goto L_800D3880;
    }
    // 0x800D386C: nop

    // 0x800D3870: jal         0x80088558
    // 0x800D3874: nop

    _glsavegame_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x800D3874: nop

    after_3:
    // 0x800D3878: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800D387C: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
L_800D3880:
    // 0x800D3880: jal         0x800D3C70
    // 0x800D3884: nop

    func_800D3C70(rdram, ctx);
        goto after_4;
    // 0x800D3884: nop

    after_4:
    // 0x800D3888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D388C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D3890: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3894: jr          $ra
    // 0x800D3898: nop

    return;
    // 0x800D3898: nop

;}
RECOMP_FUNC void _ncpoducam_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089630: syscall     785
    recomp_syscall_handler(rdram, ctx, 0x80089630);
    return;
    // 0x80089634: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chskeletonexplode_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DF8: syscall     459
    recomp_syscall_handler(rdram, ctx, 0x80086DF8);
    return;
    // 0x80086DFC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void heap_get_allocation_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B388: lw          $t6, -0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, -0XC);
    // 0x8001B38C: lw          $t8, -0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, -0X4);
    // 0x8001B390: subu        $t7, $t6, $a0
    ctx->r15 = SUB32(ctx->r14, ctx->r4);
    // 0x8001B394: srl         $t9, $t8, 8
    ctx->r25 = S32(U32(ctx->r24) >> 8);
    // 0x8001B398: jr          $ra
    // 0x8001B39C: subu        $v0, $t7, $t9
    ctx->r2 = SUB32(ctx->r15, ctx->r25);
    return;
    // 0x8001B39C: subu        $v0, $t7, $t9
    ctx->r2 = SUB32(ctx->r15, ctx->r25);
;}
RECOMP_FUNC void func_800A1040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1040: lw          $v0, 0x150($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X150);
    // 0x800A1044: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800A1048: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A104C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800A1050: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x800A1054: lw          $v0, 0x150($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X150);
    // 0x800A1058: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800A105C: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x800A1060: lw          $t6, 0x150($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X150);
    // 0x800A1064: jr          $ra
    // 0x800A1068: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    return;
    // 0x800A1068: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80102924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010292C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80102930: jal         0x800136E4
    // 0x80102934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x80102934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80102938: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8010293C: swc1        $f0, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->f0.u32l;
    // 0x80102940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102948: jr          $ra
    // 0x8010294C: nop

    return;
    // 0x8010294C: nop

;}
RECOMP_FUNC void _bafly_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C48: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C48);
    return;
    // 0x80084C4C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_800E4190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E4194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E4198: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E419C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E41A0: jal         0x800A89F8
    // 0x800E41A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x800E41A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E41A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E41AC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800E41B0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E41B4: jal         0x800C4C34
    // 0x800E41B8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_800C4C34(rdram, ctx);
        goto after_1;
    // 0x800E41B8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800E41BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E41C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E41C4: jr          $ra
    // 0x800E41C8: nop

    return;
    // 0x800E41C8: nop

;}
RECOMP_FUNC void func_80800000_chminegrilldoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x8080000C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800010: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800014: lhu         $t6, 0x6E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X6E);
    // 0x80800018: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8080001C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800020: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800024: sh          $t7, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r15;
    // 0x80800028: addiu       $t9, $zero, 0x43B
    ctx->r25 = ADD32(0, 0X43B);
    // 0x8080002C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800030: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800034: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800038: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8080003C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800040: jal         0x80086898
    // 0x80800044: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800044: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_0:
    // 0x80800048: beq         $v0, $zero, L_80800058
    if (ctx->r2 == 0) {
        // 0x8080004C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800058;
    }
    // 0x8080004C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800050: jal         0x800868C0
    // 0x80800054: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800054: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
L_80800058:
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080005C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_80800000_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8009C128
    // 0x8080000C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8080000C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800010: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800014: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800018: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080001C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800020: jal         0x800DC178
    // 0x80800024: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800024: nop

    after_1:
    // 0x80800028: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080002C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800030: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800034: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800038: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080003C: jal         0x800DC178
    // 0x80800040: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800040: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80800044: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800048: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080004C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800050: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800054: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80800058: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080005C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800060: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800064: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80800068: jal         0x800DC178
    // 0x8080006C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x8080006C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80800070: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800074: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(96, 0X1D20) << 16);
    // 0x80800078: addiu       $t6, $t6, 0x1D20
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(96, 0X1D20));
    // 0x8080007C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800080: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800084: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080008C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80800090: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800094: jal         0x800BBCB8
    // 0x80800098: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x80800098: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void _glsavegame_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088530: syscall     692
    recomp_syscall_handler(rdram, ctx, 0x80088530);
    return;
    // 0x80088534: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800FA8_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FA8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FB0: jal         0x80106790
    // 0x80800FB4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800FB4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800FB8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800FBC: jal         0x8008A340
    // 0x80800FC0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    _sueggmisc_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800FC0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x80800FC4: beql        $v0, $zero, L_80801040
    if (ctx->r2 == 0) {
        // 0x80800FC8: lw          $v0, 0x44($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X44);
            goto L_80801040;
    }
    goto skip_0;
    // 0x80800FC8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80800FCC: jal         0x80106790
    // 0x80800FD0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800FD0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_2:
    // 0x80800FD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FD8: jal         0x8008A410
    // 0x80800FDC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _suegg_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x80800FDC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80800FE0: jal         0x800D8FF8
    // 0x80800FE4: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x80800FE4: nop

    after_4:
    // 0x80800FE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800FEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800FF0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800FF4: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800FF8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800FFC: jal         0x800EF334
    // 0x80801000: nop

    func_800EF334(rdram, ctx);
        goto after_5;
    // 0x80801000: nop

    after_5:
    // 0x80801004: jal         0x800EEF94
    // 0x80801008: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EEF94(rdram, ctx);
        goto after_6;
    // 0x80801008: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x8080100C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80801010: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80801014: nop

    // 0x80801018: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8080101C: nop

    // 0x80801020: bc1fl       L_808010E0
    if (!c1cs) {
        // 0x80801024: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_808010E0;
    }
    goto skip_1;
    // 0x80801024: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x80801028: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8080102C: jal         0x800EF368
    // 0x80801030: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EF368(rdram, ctx);
        goto after_7;
    // 0x80801030: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_7:
    // 0x80801034: b           L_808010E0
    // 0x80801038: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
        goto L_808010E0;
    // 0x80801038: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8080103C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
L_80801040:
    // 0x80801040: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80801044: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80801048: bne         $t7, $zero, L_808010D4
    if (ctx->r15 != 0) {
        // 0x8080104C: nop
    
            goto L_808010D4;
    }
    // 0x8080104C: nop

    // 0x80801050: lhu         $a0, 0x1A($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X1A);
    // 0x80801054: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80801058: srl         $t8, $a0, 5
    ctx->r24 = S32(U32(ctx->r4) >> 5);
    // 0x8080105C: jal         0x800F5D70
    // 0x80801060: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_800F5D70(rdram, ctx);
        goto after_8;
    // 0x80801060: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_8:
    // 0x80801064: jal         0x800EEFD4
    // 0x80801068: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EEFD4(rdram, ctx);
        goto after_9;
    // 0x80801068: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_9:
    // 0x8080106C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80801070: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801074: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80801078: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8080107C: nop

    // 0x80801080: bc1fl       L_808010E0
    if (!c1cs) {
        // 0x80801084: lw          $a0, 0x3C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X3C);
            goto L_808010E0;
    }
    goto skip_2;
    // 0x80801084: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x80801088: lhu         $a0, 0x1A($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X1A);
    // 0x8080108C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80801090: srl         $t0, $a0, 5
    ctx->r8 = S32(U32(ctx->r4) >> 5);
    // 0x80801094: jal         0x800F5A00
    // 0x80801098: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    func_800F5A00(rdram, ctx);
        goto after_10;
    // 0x80801098: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_10:
    // 0x8080109C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x808010A0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808010A4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x808010A8: jal         0x800EFB24
    // 0x808010AC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EFB24(rdram, ctx);
        goto after_11;
    // 0x808010AC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_11:
    // 0x808010B0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808010B4: jal         0x800EF368
    // 0x808010B8: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    func_800EF368(rdram, ctx);
        goto after_12;
    // 0x808010B8: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    after_12:
    // 0x808010BC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808010C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808010C4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x808010C8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808010CC: b           L_808010DC
    // 0x808010D0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
        goto L_808010DC;
    // 0x808010D0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
L_808010D4:
    // 0x808010D4: jal         0x800EFD24
    // 0x808010D8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800EFD24(rdram, ctx);
        goto after_13;
    // 0x808010D8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_13:
L_808010DC:
    // 0x808010DC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_808010E0:
    // 0x808010E0: jal         0x808014AC
    // 0x808010E4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_808014AC_sucoasterfly(rdram, ctx);
        goto after_14;
    // 0x808010E4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_14:
    // 0x808010E8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808010EC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x808010F0: jal         0x800EF04C
    // 0x808010F4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EF04C(rdram, ctx);
        goto after_15;
    // 0x808010F4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_15:
    // 0x808010F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808010FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801100: jr          $ra
    // 0x80801104: nop

    return;
    // 0x80801104: nop

;}
RECOMP_FUNC void bsclimb_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800814: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080081C: jal         0x808001D0
    // 0x80800820: nop

    func_808001D0_bsclimb(rdram, ctx);
        goto after_0;
    // 0x80800820: nop

    after_0:
    // 0x80800824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800828: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080082C: jr          $ra
    // 0x80800830: nop

    return;
    // 0x80800830: nop

;}
RECOMP_FUNC void sumole_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801400: jal         0x80106790
    // 0x80801404: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801404: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80801408: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080140C: jal         0x80086918
    // 0x80801410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chmolehill_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80801410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080141C: jr          $ra
    // 0x80801420: nop

    return;
    // 0x80801420: nop

;}
RECOMP_FUNC void func_800A61D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A61D4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A61D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A61DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A61E0: addiu       $t6, $t6, -0x5C80
    ctx->r14 = ADD32(ctx->r14, -0X5C80);
    // 0x800A61E4: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800A61E8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800A61EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A61F0: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x800A61F4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800A61F8: addiu       $t0, $t0, -0x5C70
    ctx->r8 = ADD32(ctx->r8, -0X5C70);
    // 0x800A61FC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800A6200: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800A6204: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x800A6208: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x800A620C: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x800A6210: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    // 0x800A6214: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x800A6218: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x800A621C: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800A6220: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x800A6224: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x800A6228: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x800A622C: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x800A6230: jal         0x800DF580
    // 0x800A6234: sw          $t3, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r11;
    func_800DF580(rdram, ctx);
        goto after_0;
    // 0x800A6234: sw          $t3, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r11;
    after_0:
    // 0x800A6238: jal         0x800DF830
    // 0x800A623C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF830(rdram, ctx);
        goto after_1;
    // 0x800A623C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x800A6240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A6244: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800A6248: jr          $ra
    // 0x800A624C: nop

    return;
    // 0x800A624C: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083DC8: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083DC8);
    return;
    // 0x80083DCC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800EAC_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EB4: jal         0x8008E95C
    // 0x80800EB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E95C(rdram, ctx);
        goto after_0;
    // 0x80800EB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800EBC: jal         0x80800130
    // 0x80800EC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800130_bsstatue(rdram, ctx);
        goto after_1;
    // 0x80800EC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800ECC: jr          $ra
    // 0x80800ED0: nop

    return;
    // 0x80800ED0: nop

;}
