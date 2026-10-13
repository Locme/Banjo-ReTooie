#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80107C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107C00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80107C04: jr          $ra
    // 0x80107C08: lwc1        $f0, 0x6F10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6F10);
    return;
    // 0x80107C08: lwc1        $f0, 0x6F10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6F10);
    // 0x80107C0C: nop

;}
RECOMP_FUNC void func_800C67F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C67F8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C67FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800C6800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C6804: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800C6808:
    // 0x800C6808: lbu         $t6, 0x40($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X40);
    // 0x800C680C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C6810: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C6814: sb          $t6, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r14;
    // 0x800C6818: lbu         $t7, 0x41($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X41);
    // 0x800C681C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800C6820: sb          $t7, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r15;
    // 0x800C6824: lbu         $t8, 0x3E($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X3E);
    // 0x800C6828: sb          $t8, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r24;
    // 0x800C682C: lbu         $t9, 0x3F($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X3F);
    // 0x800C6830: bne         $v0, $a0, L_800C6808
    if (ctx->r2 != ctx->r4) {
        // 0x800C6834: sb          $t9, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r25;
            goto L_800C6808;
    }
    // 0x800C6834: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
    // 0x800C6838: jr          $ra
    // 0x800C683C: nop

    return;
    // 0x800C683C: nop

;}
RECOMP_FUNC void func_80800BBC_chkingjinjo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800BC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BC8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800BCC: jal         0x80088078
    // 0x80800BD0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800BD0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800BD4: beq         $v0, $zero, L_80800C04
    if (ctx->r2 == 0) {
        // 0x80800BD8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800C04;
    }
    // 0x80800BD8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800BDC: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800BE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BE4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800BE8: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80800BEC: beq         $t7, $at, L_80800BFC
    if (ctx->r15 == ctx->r1) {
        // 0x80800BF0: nop
    
            goto L_80800BFC;
    }
    // 0x80800BF0: nop

    // 0x80800BF4: jal         0x80800C60
    // 0x80800BF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800C60_chkingjinjo(rdram, ctx);
        goto after_1;
    // 0x80800BF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
L_80800BFC:
    // 0x80800BFC: b           L_80800C08
    // 0x80800C00: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800C08;
    // 0x80800C00: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800C04:
    // 0x80800C04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C08:
    // 0x80800C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C10: jr          $ra
    // 0x80800C14: nop

    return;
    // 0x80800C14: nop

;}
RECOMP_FUNC void func_80800100_bsbanshack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800104: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800108: jal         0x8009EF1C
    // 0x8080010C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bastick_getZonePosition(rdram, ctx);
        goto after_0;
    // 0x8080010C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800110: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800114: jal         0x8009EF10
    // 0x80800118: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bastick_getZone(rdram, ctx);
        goto after_1;
    // 0x80800118: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080011C: bne         $v0, $zero, L_80800138
    if (ctx->r2 != 0) {
        // 0x80800120: lwc1        $f12, 0x1C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80800138;
    }
    // 0x80800120: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800124: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800128: jal         0x8009B9B0
    // 0x8080012C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080012C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800130: b           L_80800158
    // 0x80800134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800158;
    // 0x80800134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800138:
    // 0x80800138: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080013C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800140: jal         0x800F1214
    // 0x80800144: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800F1214(rdram, ctx);
        goto after_3;
    // 0x80800144: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_3:
    // 0x80800148: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080014C: jal         0x8009B9B0
    // 0x80800150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800158:
    // 0x80800158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080015C: jr          $ra
    // 0x80800160: nop

    return;
    // 0x80800160: nop

;}
RECOMP_FUNC void func_800A3148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A314C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3150: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A3154: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A3158: addiu       $t8, $t8, -0x6CC0
    ctx->r24 = ADD32(ctx->r24, -0X6CC0);
    // 0x800A315C: lbu         $v1, 0x29($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X29);
    // 0x800A3160: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A3164: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800A3168: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x800A316C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A3170: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800A3174: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A3178: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800A317C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A3180: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800A3184: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A3188: beq         $v1, $at, L_800A31A4
    if (ctx->r3 == ctx->r1) {
        // 0x800A318C: swc1        $f8, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
            goto L_800A31A4;
    }
    // 0x800A318C: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x800A3190: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800A3194: beq         $v1, $at, L_800A31E8
    if (ctx->r3 == ctx->r1) {
        // 0x800A3198: nop
    
            goto L_800A31E8;
    }
    // 0x800A3198: nop

    // 0x800A319C: b           L_800A31F4
    // 0x800A31A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800A31F4;
    // 0x800A31A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A31A4:
    // 0x800A31A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A31A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800A31AC: jal         0x800850F8
    // 0x800A31B0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    _basnowball_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800A31B0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A31B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800A31B8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800A31BC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800A31C0: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A31C4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800A31C8: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x800A31CC: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800A31D0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800A31D4: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x800A31D8: lwc1        $f6, 0x0($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800A31DC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A31E0: b           L_800A31F0
    // 0x800A31E4: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
        goto L_800A31F0;
    // 0x800A31E4: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
L_800A31E8:
    // 0x800A31E8: jal         0x800842B8
    // 0x800A31EC: nop

    _bsfirstp_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x800A31EC: nop

    after_1:
L_800A31F0:
    // 0x800A31F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A31F4:
    // 0x800A31F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A31F8: jr          $ra
    // 0x800A31FC: nop

    return;
    // 0x800A31FC: nop

;}
RECOMP_FUNC void func_800B5B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5B40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B5B44: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B5B48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B5B4C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800B5B50: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800B5B54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B5B58: addiu       $s1, $s1, -0x7E87
    ctx->r17 = ADD32(ctx->r17, -0X7E87);
    // 0x800B5B5C: addiu       $s0, $s0, -0x7EAF
    ctx->r16 = ADD32(ctx->r16, -0X7EAF);
L_800B5B60:
    // 0x800B5B60: jal         0x800B58D4
    // 0x800B5B64: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    func_800B58D4(rdram, ctx);
        goto after_0;
    // 0x800B5B64: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    after_0:
    // 0x800B5B68: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B5B6C: bne         $s0, $s1, L_800B5B60
    if (ctx->r16 != ctx->r17) {
        // 0x800B5B70: sb          $zero, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = 0;
            goto L_800B5B60;
    }
    // 0x800B5B70: sb          $zero, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = 0;
    // 0x800B5B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B5B78: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B5B7C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B5B80: jr          $ra
    // 0x800B5B84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B5B84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bsbbuster_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808006E8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(65, 0X730) << 16);
    // 0x808006EC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808006F0: jr          $ra
    // 0x808006F4: lw          $v0, 0x730($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(65, 0X730));
    return;
    // 0x808006F4: lw          $v0, 0x730($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(65, 0X730));
;}
RECOMP_FUNC void func_80800A40_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A48: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800A4C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80800A50: jal         0x80090178
    // 0x80800A54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090178(rdram, ctx);
        goto after_0;
    // 0x80800A54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800A58: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800A5C: addiu       $a1, $zero, 0x1F4
    ctx->r5 = ADD32(0, 0X1F4);
    // 0x80800A60: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800A64: jal         0x8010CAC0
    // 0x80800A68: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    func_8010CAC0(rdram, ctx);
        goto after_1;
    // 0x80800A68: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    after_1:
    // 0x80800A6C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A70: beq         $v0, $zero, L_80800B0C
    if (ctx->r2 == 0) {
        // 0x80800A74: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800B0C;
    }
    // 0x80800A74: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800A78: beql        $v1, $zero, L_80800B10
    if (ctx->r3 == 0) {
        // 0x80800A7C: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80800B10;
    }
    goto skip_0;
    // 0x80800A7C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x80800A80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800A84: lwc1        $f6, 0x24($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X24);
    // 0x80800A88: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800A8C: nop

    // 0x80800A90: bc1fl       L_80800B10
    if (!c1cs) {
        // 0x80800A94: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80800B10;
    }
    goto skip_1;
    // 0x80800A94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_1:
    // 0x80800A98: lhu         $v0, 0x72($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X72);
    // 0x80800A9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800AA0: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800AA4: beq         $t6, $at, L_80800B70
    if (ctx->r14 == ctx->r1) {
        // 0x80800AA8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800B70;
    }
    // 0x80800AA8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800AAC: beq         $t6, $at, L_80800B70
    if (ctx->r14 == ctx->r1) {
        // 0x80800AB0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80800B70;
    }
    // 0x80800AB0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800AB4: beq         $t6, $at, L_80800B70
    if (ctx->r14 == ctx->r1) {
        // 0x80800AB8: addiu       $a0, $zero, 0x334
        ctx->r4 = ADD32(0, 0X334);
            goto L_80800B70;
    }
    // 0x80800AB8: addiu       $a0, $zero, 0x334
    ctx->r4 = ADD32(0, 0X334);
    // 0x80800ABC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800AC0: jal         0x800DA9E4
    // 0x80800AC4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800DA9E4(rdram, ctx);
        goto after_2;
    // 0x80800AC4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x80800AC8: bne         $v0, $zero, L_80800AE8
    if (ctx->r2 != 0) {
        // 0x80800ACC: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800AE8;
    }
    // 0x80800ACC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800AD0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800AD4: addiu       $a1, $zero, 0xDA6
    ctx->r5 = ADD32(0, 0XDA6);
    // 0x80800AD8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80800ADC: jal         0x80800104
    // 0x80800AE0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80800104_chsilo(rdram, ctx);
        goto after_3;
    // 0x80800AE0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_3:
    // 0x80800AE4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_80800AE8:
    // 0x80800AE8: lw          $t7, 0x6C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X6C);
    // 0x80800AEC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800AF0: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80800AF4: beql        $t8, $zero, L_80800B74
    if (ctx->r24 == 0) {
        // 0x80800AF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B74;
    }
    goto skip_2;
    // 0x80800AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800AFC: jal         0x808004C0
    // 0x80800B00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808004C0_chsilo(rdram, ctx);
        goto after_4;
    // 0x80800B00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x80800B04: b           L_80800B74
    // 0x80800B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B74;
    // 0x80800B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B0C:
    // 0x80800B0C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80800B10:
    // 0x80800B10: lwc1        $f10, 0x24($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X24);
    // 0x80800B14: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80800B18: nop

    // 0x80800B1C: bc1tl       L_80800B30
    if (c1cs) {
        // 0x80800B20: lhu         $v0, 0x72($a3)
        ctx->r2 = MEM_HU(ctx->r7, 0X72);
            goto L_80800B30;
    }
    goto skip_3;
    // 0x80800B20: lhu         $v0, 0x72($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X72);
    skip_3:
    // 0x80800B24: bne         $v1, $zero, L_80800B58
    if (ctx->r3 != 0) {
        // 0x80800B28: nop
    
            goto L_80800B58;
    }
    // 0x80800B28: nop

    // 0x80800B2C: lhu         $v0, 0x72($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X72);
L_80800B30:
    // 0x80800B30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800B34: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x80800B38: beq         $t9, $at, L_80800B70
    if (ctx->r25 == ctx->r1) {
        // 0x80800B3C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80800B70;
    }
    // 0x80800B3C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800B40: beq         $t9, $at, L_80800B70
    if (ctx->r25 == ctx->r1) {
        // 0x80800B44: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800B70;
    }
    // 0x80800B44: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800B48: jal         0x808004C0
    // 0x80800B4C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808004C0_chsilo(rdram, ctx);
        goto after_5;
    // 0x80800B4C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_5:
    // 0x80800B50: b           L_80800B74
    // 0x80800B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B74;
    // 0x80800B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B58:
    // 0x80800B58: jal         0x800D8FF8
    // 0x80800B5C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_800D8FF8(rdram, ctx);
        goto after_6;
    // 0x80800B5C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_6:
    // 0x80800B60: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800B64: lwc1        $f16, 0x24($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X24);
    // 0x80800B68: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80800B6C: swc1        $f18, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f18.u32l;
L_80800B70:
    // 0x80800B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B74:
    // 0x80800B74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800B78: jr          $ra
    // 0x80800B7C: nop

    return;
    // 0x80800B7C: nop

;}
RECOMP_FUNC void func_800A392C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A392C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A3930: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A3934: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800A3938: jal         0x8009C128
    // 0x800A393C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800A393C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x800A3940: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800A3944: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A3948: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x800A394C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A3950: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800A3954: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800A3958: jal         0x800C05B8
    // 0x800A395C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800C05B8(rdram, ctx);
        goto after_1;
    // 0x800A395C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x800A3960: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A3964: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800A3968: jr          $ra
    // 0x800A396C: nop

    return;
    // 0x800A396C: nop

;}
RECOMP_FUNC void _bsmum_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083840: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083840);
    return;
    // 0x80083844: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800C3798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C379C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C37A0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C37A4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C37A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C37AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C37B0: beq         $t6, $zero, L_800C37D0
    if (ctx->r14 == 0) {
        // 0x800C37B4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800C37D0;
    }
    // 0x800C37B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C37B8: jal         0x800C1414
    // 0x800C37BC: nop

    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C37BC: nop

    after_0:
    // 0x800C37C0: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C37C4: swc1        $f4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f4.u32l;
    // 0x800C37C8: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C37CC: swc1        $f6, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f6.u32l;
L_800C37D0:
    // 0x800C37D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C37D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C37D8: jr          $ra
    // 0x800C37DC: nop

    return;
    // 0x800C37DC: nop

;}
RECOMP_FUNC void func_8010CD50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CD50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010CD54: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8010CD58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CD5C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8010CD60: jal         0x800F5A00
    // 0x8010CD64: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x8010CD64: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8010CD68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8010CD6C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8010CD70: jal         0x800F1DF4
    // 0x8010CD74: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_1;
    // 0x8010CD74: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x8010CD78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CD7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010CD80: jr          $ra
    // 0x8010CD84: nop

    return;
    // 0x8010CD84: nop

;}
RECOMP_FUNC void _chprisonbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FF0: syscall     491
    recomp_syscall_handler(rdram, ctx, 0x80086FF0);
    return;
    // 0x80086FF4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808001A8_chfantasytrashcanbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001B4: jal         0x80085808
    // 0x808001B8: addiu       $a1, $zero, 0x9FF
    ctx->r5 = ADD32(0, 0X9FF);
    _chswitch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808001B8: addiu       $a1, $zero, 0x9FF
    ctx->r5 = ADD32(0, 0X9FF);
    after_0:
    // 0x808001BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001C0: jal         0x80085810
    // 0x808001C4: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    _chswitch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808001C4: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    after_1:
    // 0x808001C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001D0: jr          $ra
    // 0x808001D4: nop

    return;
    // 0x808001D4: nop

;}
RECOMP_FUNC void func_80800094_chweather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080009C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000A0: jal         0x8010D254
    // 0x808000A4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x808000A4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x808000A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(732, 0X408) << 16);
    // 0x808000AC: lwc1        $f4, 0x408($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(732, 0X408));
    // 0x808000B0: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808000B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808000B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000BC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808000C0: nop

    // 0x808000C4: bc1f        L_808000D0
    if (!c1cs) {
        // 0x808000C8: nop
    
            goto L_808000D0;
    }
    // 0x808000C8: nop

    // 0x808000CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000D0:
    // 0x808000D0: jr          $ra
    // 0x808000D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sudeflect_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002FC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800300: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800304: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800308: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8080030C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800310: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800314: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800318: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080031C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800320: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800324: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800328: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080032C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800330: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80800334: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800338: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8080033C: addiu       $v0, $sp, 0x4C
    ctx->r2 = ADD32(ctx->r29, 0X4C);
    // 0x80800340: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80800344: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80800348: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8080034C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800350: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80800354: mul.s       $f16, $f14, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80800358: beql        $v0, $a0, L_80800390
    if (ctx->r2 == ctx->r4) {
        // 0x8080035C: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_80800390;
    }
    goto skip_0;
    // 0x8080035C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x80800360: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_80800364:
    // 0x80800364: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80800368: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8080036C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80800370: swc1        $f14, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f14.u32l;
    // 0x80800374: lwc1        $f18, 0x0($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80800378: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8080037C: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80800380: mul.s       $f16, $f14, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80800384: bnel        $v0, $a0, L_80800364
    if (ctx->r2 != ctx->r4) {
        // 0x80800388: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_80800364;
    }
    goto skip_1;
    // 0x80800388: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x8080038C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_80800390:
    // 0x80800390: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80800394: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80800398: swc1        $f14, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f14.u32l;
    // 0x8080039C: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x808003A0: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(3222, 0X1020) << 16);
    // 0x808003A4: addiu       $s1, $s1, 0x1020
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(3222, 0X1020));
    // 0x808003A8: andi        $t7, $t6, 0x18
    ctx->r15 = ctx->r14 & 0X18;
    // 0x808003AC: beq         $t7, $zero, L_808003C0
    if (ctx->r15 == 0) {
        // 0x808003B0: sw          $zero, 0x24($s1)
        MEM_W(0X24, ctx->r17) = 0;
            goto L_808003C0;
    }
    // 0x808003B0: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x808003B4: jal         0x800BE3F8
    // 0x808003B8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800BE3F8(rdram, ctx);
        goto after_0;
    // 0x808003B8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x808003BC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
L_808003C0:
    // 0x808003C0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x808003C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808003C8: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
    // 0x808003CC: andi        $t9, $t8, 0x2
    ctx->r25 = ctx->r24 & 0X2;
    // 0x808003D0: beql        $t9, $zero, L_80800430
    if (ctx->r25 == 0) {
        // 0x808003D4: lw          $t7, 0x60($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X60);
            goto L_80800430;
    }
    goto skip_2;
    // 0x808003D4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    skip_2:
L_808003D8:
    // 0x808003D8: jal         0x800F6438
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808003E0: beq         $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x808003E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800420;
    }
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x808003EC: jal         0x800F4D18
    // 0x808003F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800F4D18(rdram, ctx);
        goto after_2;
    // 0x808003F0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_2:
    // 0x808003F4: beql        $v0, $zero, L_80800424
    if (ctx->r2 == 0) {
        // 0x808003F8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800424;
    }
    goto skip_3;
    // 0x808003F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x808003FC: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x80800400: ori         $t6, $s3, 0x2
    ctx->r14 = ctx->r19 | 0X2;
    // 0x80800404: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x80800408: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8080040C: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x80800410: sw          $s0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r16;
    // 0x80800414: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x80800418: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8080041C: sw          $t5, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r13;
L_80800420:
    // 0x80800420: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800424:
    // 0x80800424: bne         $s0, $s2, L_808003D8
    if (ctx->r16 != ctx->r18) {
        // 0x80800428: nop
    
            goto L_808003D8;
    }
    // 0x80800428: nop

    // 0x8080042C: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
L_80800430:
    // 0x80800430: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800434: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x80800438: beql        $t8, $zero, L_80800458
    if (ctx->r24 == 0) {
        // 0x8080043C: lw          $t1, 0x60($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X60);
            goto L_80800458;
    }
    goto skip_4;
    // 0x8080043C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    skip_4:
    // 0x80800440: jal         0x80800BEC
    // 0x80800444: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80800BEC_sudeflect(rdram, ctx);
        goto after_3;
    // 0x80800444: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
    // 0x80800448: beq         $v0, $zero, L_80800454
    if (ctx->r2 == 0) {
        // 0x8080044C: ori         $t9, $s3, 0x8
        ctx->r25 = ctx->r19 | 0X8;
            goto L_80800454;
    }
    // 0x8080044C: ori         $t9, $s3, 0x8
    ctx->r25 = ctx->r19 | 0X8;
    // 0x80800450: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
L_80800454:
    // 0x80800454: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
L_80800458:
    // 0x80800458: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080045C: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x80800460: beql        $t2, $zero, L_80800480
    if (ctx->r10 == 0) {
        // 0x80800464: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800480;
    }
    goto skip_5;
    // 0x80800464: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x80800468: jal         0x80800D14
    // 0x8080046C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_80800D14_sudeflect(rdram, ctx);
        goto after_4;
    // 0x8080046C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_4:
    // 0x80800470: beq         $v0, $zero, L_8080047C
    if (ctx->r2 == 0) {
        // 0x80800474: ori         $t3, $s3, 0x10
        ctx->r11 = ctx->r19 | 0X10;
            goto L_8080047C;
    }
    // 0x80800474: ori         $t3, $s3, 0x10
    ctx->r11 = ctx->r19 | 0X10;
    // 0x80800478: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
L_8080047C:
    // 0x8080047C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800480:
    // 0x80800480: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80800484: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80800488: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080048C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800490: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800494: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800498: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8080049C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808004A0: jr          $ra
    // 0x808004A4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808004A4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800648_chanemone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800648: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8080064C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800650: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80800654: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800658: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8080065C: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x80800660: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x80800664: jal         0x80106790
    // 0x80800668: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800668: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080066C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800670: jal         0x800CB854
    // 0x80800674: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    func_800CB854(rdram, ctx);
        goto after_1;
    // 0x80800674: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    after_1:
    // 0x80800678: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080067C: beq         $v0, $at, L_80800698
    if (ctx->r2 == ctx->r1) {
        // 0x80800680: lw          $a2, 0x70($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X70);
            goto L_80800698;
    }
    // 0x80800680: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80800684: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800688: beq         $v0, $at, L_80800708
    if (ctx->r2 == ctx->r1) {
        // 0x8080068C: nop
    
            goto L_80800708;
    }
    // 0x8080068C: nop

    // 0x80800690: b           L_8080076C
    // 0x80800694: nop

        goto L_8080076C;
    // 0x80800694: nop

L_80800698:
    // 0x80800698: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8080069C: jal         0x800EE88C
    // 0x808006A0: addiu       $a1, $a2, 0x1E
    ctx->r5 = ADD32(ctx->r6, 0X1E);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x808006A0: addiu       $a1, $a2, 0x1E
    ctx->r5 = ADD32(ctx->r6, 0X1E);
    after_2:
    // 0x808006A4: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x808006A8: jal         0x800EF04C
    // 0x808006AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x808006AC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808006B0: lhu         $t6, 0x68($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X68);
    // 0x808006B4: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x808006B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808006BC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x808006C0: bgez        $t6, L_808006D4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808006C4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808006D4;
    }
    // 0x808006C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808006C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006CC: nop

    // 0x808006D0: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808006D4:
    // 0x808006D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1032, 0X8A8) << 16);
    // 0x808006D8: lwc1        $f10, 0x8A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1032, 0X8A8));
    // 0x808006DC: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808006E0: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x808006E4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x808006E8: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x808006EC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808006F0: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808006F4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808006F8: jal         0x800EFFB4
    // 0x808006FC: nop

    func_800EFFB4(rdram, ctx);
        goto after_4;
    // 0x808006FC: nop

    after_4:
    // 0x80800700: b           L_8080087C
    // 0x80800704: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8080087C;
    // 0x80800704: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80800708:
    // 0x80800708: jal         0x80103D98
    // 0x8080070C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80103D98(rdram, ctx);
        goto after_5;
    // 0x8080070C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x80800710: bne         $v0, $zero, L_80800720
    if (ctx->r2 != 0) {
        // 0x80800714: sw          $v0, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r2;
            goto L_80800720;
    }
    // 0x80800714: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80800718: b           L_80800878
    // 0x8080071C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800878;
    // 0x8080071C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800720:
    // 0x80800720: jal         0x801040A8
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801040A8(rdram, ctx);
        goto after_6;
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800728: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8080072C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80800730: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80800734: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x80800738: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8080073C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80800740: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80800744: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800748: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8080074C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800750: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    // 0x80800754: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80800758: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8080075C: jal         0x800B1F8C
    // 0x80800760: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_800B1F8C(rdram, ctx);
        goto after_7;
    // 0x80800760: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_7:
    // 0x80800764: b           L_80800858
    // 0x80800768: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80800858;
    // 0x80800768: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8080076C:
    // 0x8080076C: jal         0x80103D98
    // 0x80800770: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80103D98(rdram, ctx);
        goto after_8;
    // 0x80800770: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_8:
    // 0x80800774: bne         $v0, $zero, L_80800784
    if (ctx->r2 != 0) {
        // 0x80800778: sw          $v0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r2;
            goto L_80800784;
    }
    // 0x80800778: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8080077C: b           L_80800878
    // 0x80800780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800878;
    // 0x80800780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800784:
    // 0x80800784: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800788: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x8080078C: jal         0x800F1DF4
    // 0x80800790: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    func_800F1DF4(rdram, ctx);
        goto after_9;
    // 0x80800790: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    after_9:
    // 0x80800794: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800798: jal         0x800F1DCC
    // 0x8080079C: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_10;
    // 0x8080079C: lwc1        $f14, 0x48($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X48);
    after_10:
    // 0x808007A0: jal         0x800136E4
    // 0x808007A4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_11;
    // 0x808007A4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_11:
    // 0x808007A8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808007AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007B0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x808007BC: nop

    // 0x808007C0: bc1fl       L_808007D4
    if (!c1cs) {
        // 0x808007C4: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_808007D4;
    }
    goto skip_0;
    // 0x808007C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_0:
    // 0x808007C8: b           L_80800810
    // 0x808007CC: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
        goto L_80800810;
    // 0x808007CC: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x808007D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_808007D4:
    // 0x808007D4: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x808007D8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x808007DC: nop

    // 0x808007E0: bc1fl       L_808007F4
    if (!c1cs) {
        // 0x808007E4: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_808007F4;
    }
    goto skip_1;
    // 0x808007E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_1:
    // 0x808007E8: b           L_80800810
    // 0x808007EC: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
        goto L_80800810;
    // 0x808007EC: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x808007F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_808007F4:
    // 0x808007F4: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x808007F8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808007FC: nop

    // 0x80800800: bc1f        L_80800810
    if (!c1cs) {
        // 0x80800804: nop
    
            goto L_80800810;
    }
    // 0x80800804: nop

    // 0x80800808: b           L_80800810
    // 0x8080080C: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
        goto L_80800810;
    // 0x8080080C: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
L_80800810:
    // 0x80800810: jal         0x801040A8
    // 0x80800814: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    func_801040A8(rdram, ctx);
        goto after_12;
    // 0x80800814: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    after_12:
    // 0x80800818: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x8080081C: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x80800820: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x80800824: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80800828: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8080082C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80800830: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800834: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800838: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8080083C: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    // 0x80800840: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80800844: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80800848: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8080084C: jal         0x800B1F8C
    // 0x80800850: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    func_800B1F8C(rdram, ctx);
        goto after_13;
    // 0x80800850: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_13:
    // 0x80800854: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80800858:
    // 0x80800858: beql        $v0, $zero, L_80800878
    if (ctx->r2 == 0) {
        // 0x8080085C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80800878;
    }
    goto skip_2;
    // 0x8080085C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_2:
    // 0x80800860: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800864: andi        $t3, $v0, 0x1FF
    ctx->r11 = ctx->r2 & 0X1FF;
    // 0x80800868: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x8080086C: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80800870: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
    // 0x80800874: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800878:
    // 0x80800878: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8080087C:
    // 0x8080087C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80800880: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800884: jr          $ra
    // 0x80800888: nop

    return;
    // 0x80800888: nop

;}
RECOMP_FUNC void _bafpctrl_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084D00: syscall     133
    recomp_syscall_handler(rdram, ctx, 0x80084D00);
    return;
    // 0x80084D04: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_800AE598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE59C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE5A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800AE5A4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800AE5A8: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x800AE5AC: lw          $a1, 0x0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X0);
    // 0x800AE5B0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x800AE5B4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800AE5B8: jal         0x80116684
    // 0x800AE5BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    func_80116684(rdram, ctx);
        goto after_0;
    // 0x800AE5BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    after_0:
    // 0x800AE5C0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800AE5C4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE5C8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800AE5CC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800AE5D0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800AE5D4: sll         $t0, $t9, 6
    ctx->r8 = S32(ctx->r25 << 6);
    // 0x800AE5D8: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x800AE5DC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800AE5E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE5E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE5E8: jr          $ra
    // 0x800AE5EC: nop

    return;
    // 0x800AE5EC: nop

;}
RECOMP_FUNC void func_808003B0_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B8: jal         0x80085240
    // 0x808003BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _basudie_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808003BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003C0: jal         0x80800198
    // 0x808003C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bssnowball_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808003C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808003C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003D0: jr          $ra
    // 0x808003D4: nop

    return;
    // 0x808003D4: nop

;}
RECOMP_FUNC void func_800EA51C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA51C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800EA520: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800EA524: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800EA528: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800EA52C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800EA530: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800EA534: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800EA538: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800EA53C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800EA540: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800EA544: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800EA548: addiu       $s2, $s2, 0x2DD0
    ctx->r18 = ADD32(ctx->r18, 0X2DD0);
    // 0x800EA54C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800EA550: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // 0x800EA554: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
L_800EA558:
    // 0x800EA558: lw          $a0, 0x14($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X14);
    // 0x800EA55C: beql        $a0, $zero, L_800EA5D4
    if (ctx->r4 == 0) {
        // 0x800EA560: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800EA5D4;
    }
    goto skip_0;
    // 0x800EA560: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800EA564: jal         0x80106790
    // 0x800EA568: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x800EA568: nop

    after_0:
    // 0x800EA56C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EA570: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EA574: jal         0x800F5A00
    // 0x800EA578: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x800EA578: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x800EA57C: jal         0x80103C94
    // 0x800EA580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103C94(rdram, ctx);
        goto after_2;
    // 0x800EA580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800EA584: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800EA588: lh          $a0, 0x80($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X80);
    // 0x800EA58C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800EA590: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800EA594: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800EA598: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800EA59C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800EA5A0: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x800EA5A4: addiu       $a3, $s0, 0x44
    ctx->r7 = ADD32(ctx->r16, 0X44);
    // 0x800EA5A8: jal         0x800D89C8
    // 0x800EA5AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800D89C8(rdram, ctx);
        goto after_3;
    // 0x800EA5AC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x800EA5B0: beq         $v0, $zero, L_800EA5CC
    if (ctx->r2 == 0) {
        // 0x800EA5B4: lwc1        $f6, 0x64($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800EA5CC;
    }
    // 0x800EA5B4: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800EA5B8: sub.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x800EA5BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EA5C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800EA5C4: jal         0x800F8418
    // 0x800EA5C8: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    func_800F8418(rdram, ctx);
        goto after_4;
    // 0x800EA5C8: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    after_4:
L_800EA5CC:
    // 0x800EA5CC: sw          $zero, 0x14($s2)
    MEM_W(0X14, ctx->r18) = 0;
    // 0x800EA5D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800EA5D4:
    // 0x800EA5D4: bne         $s1, $s4, L_800EA558
    if (ctx->r17 != ctx->r20) {
        // 0x800EA5D8: addiu       $s2, $s2, 0x14
        ctx->r18 = ADD32(ctx->r18, 0X14);
            goto L_800EA558;
    }
    // 0x800EA5D8: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x800EA5DC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800EA5E0: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800EA5E4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800EA5E8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800EA5EC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800EA5F0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800EA5F4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800EA5F8: jr          $ra
    // 0x800EA5FC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800EA5FC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void gccubesearch_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CA4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800CA8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800CAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800CB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800CB4: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80800CB8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800CBC: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80800CC0: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80800CC4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800CC8: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80800CCC: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x80800CD0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800CD4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800CD8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800CDC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80800CE0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800CE4: jal         0x800BE554
    // 0x80800CE8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800BE554(rdram, ctx);
        goto after_0;
    // 0x80800CE8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x80800CEC: bne         $s0, $zero, L_80800D20
    if (ctx->r16 != 0) {
        // 0x80800CF0: lw          $s3, 0x78($sp)
        ctx->r19 = MEM_W(ctx->r29, 0X78);
            goto L_80800D20;
    }
    // 0x80800CF0: lw          $s3, 0x78($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X78);
    // 0x80800CF4: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80800CF8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80800CFC: lw          $s2, 0x74($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X74);
    // 0x80800D00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800D04: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80800D08: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80800D0C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80800D10: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80800D14: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x80800D18: b           L_80800E70
    // 0x80800D1C: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
        goto L_80800E70;
    // 0x80800D1C: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_80800D20:
    // 0x80800D20: lw          $s2, 0x74($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X74);
    // 0x80800D24: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80800D28: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_80800D2C:
    // 0x80800D2C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80800D30: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80800D34: beq         $at, $zero, L_80800D44
    if (ctx->r1 == 0) {
        // 0x80800D38: nop
    
            goto L_80800D44;
    }
    // 0x80800D38: nop

    // 0x80800D3C: b           L_80800E70
    // 0x80800D40: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80800E70;
    // 0x80800D40: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800D44:
    // 0x80800D44: jal         0x800BDAD4
    // 0x80800D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800BDAD4(rdram, ctx);
        goto after_1;
    // 0x80800D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800D4C: beq         $v0, $zero, L_80800DC4
    if (ctx->r2 == 0) {
        // 0x80800D50: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80800DC4;
    }
    // 0x80800D50: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800D54: jal         0x800E9DC4
    // 0x80800D58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800E9DC4(rdram, ctx);
        goto after_2;
    // 0x80800D58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800D5C: beq         $v0, $zero, L_80800DC4
    if (ctx->r2 == 0) {
        // 0x80800D60: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800DC4;
    }
    // 0x80800D60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800D64: jal         0x800E9BF4
    // 0x80800D68: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    func_800E9BF4(rdram, ctx);
        goto after_3;
    // 0x80800D68: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    after_3:
    // 0x80800D6C: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80800D70: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x80800D74: sll         $t1, $v1, 11
    ctx->r9 = S32(ctx->r3 << 11);
    // 0x80800D78: srl         $t2, $t1, 21
    ctx->r10 = S32(U32(ctx->r9) >> 21);
    // 0x80800D7C: sw          $t2, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r10;
    // 0x80800D80: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80800D84: srl         $s5, $v1, 21
    ctx->r21 = S32(U32(ctx->r3) >> 21);
    // 0x80800D88: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80800D8C: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80800D90: sw          $t5, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r13;
    // 0x80800D94: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80800D98: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80800D9C: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x80800DA0: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80800DA4: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80800DA8: sw          $t9, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r25;
    // 0x80800DAC: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x80800DB0: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x80800DB4: sw          $t1, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r9;
    // 0x80800DB8: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80800DBC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80800DC0: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
L_80800DC4:
    // 0x80800DC4: beql        $s1, $zero, L_80800DE8
    if (ctx->r17 == 0) {
        // 0x80800DC8: sw          $zero, 0x0($s2)
        MEM_W(0X0, ctx->r18) = 0;
            goto L_80800DE8;
    }
    goto skip_0;
    // 0x80800DC8: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    skip_0:
    // 0x80800DCC: jal         0x800E9DC4
    // 0x80800DD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E9DC4(rdram, ctx);
        goto after_4;
    // 0x80800DD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80800DD4: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80800DD8: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800DDC: bne         $at, $zero, L_80800E64
    if (ctx->r1 != 0) {
        // 0x80800DE0: nop
    
            goto L_80800E64;
    }
    // 0x80800DE0: nop

    // 0x80800DE4: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_80800DE8:
    // 0x80800DE8: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x80800DEC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80800DF0: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    // 0x80800DF4: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80800DF8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80800DFC: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800E00: beq         $at, $zero, L_80800E64
    if (ctx->r1 == 0) {
        // 0x80800E04: nop
    
            goto L_80800E64;
    }
    // 0x80800E04: nop

    // 0x80800E08: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80800E0C: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
    // 0x80800E10: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80800E14: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x80800E18: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80800E1C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80800E20: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800E24: beq         $at, $zero, L_80800E64
    if (ctx->r1 == 0) {
        // 0x80800E28: nop
    
            goto L_80800E64;
    }
    // 0x80800E28: nop

    // 0x80800E2C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80800E30: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80800E34: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80800E38: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80800E3C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80800E40: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800E44: beq         $at, $zero, L_80800E64
    if (ctx->r1 == 0) {
        // 0x80800E48: nop
    
            goto L_80800E64;
    }
    // 0x80800E48: nop

    // 0x80800E4C: beq         $s5, $zero, L_80800E5C
    if (ctx->r21 == 0) {
        // 0x80800E50: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_80800E5C;
    }
    // 0x80800E50: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80800E54: b           L_80800E70
    // 0x80800E58: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
        goto L_80800E70;
    // 0x80800E58: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_80800E5C:
    // 0x80800E5C: b           L_80800E70
    // 0x80800E60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800E70;
    // 0x80800E60: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800E64:
    // 0x80800E64: beql        $s5, $zero, L_80800D2C
    if (ctx->r21 == 0) {
        // 0x80800E68: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_80800D2C;
    }
    goto skip_1;
    // 0x80800E68: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    skip_1:
    // 0x80800E6C: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_80800E70:
    // 0x80800E70: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80800E74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800E78: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800E7C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E80: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800E84: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800E88: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800E8C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E90: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80800E94: jr          $ra
    // 0x80800E98: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80800E98: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80800E9C: nop

;}
RECOMP_FUNC void func_8009BB0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BB0C: lw          $t6, 0xC8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BB10: jr          $ra
    // 0x8009BB14: lwc1        $f0, 0x20($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X20);
    return;
    // 0x8009BB14: lwc1        $f0, 0x20($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X20);
;}
RECOMP_FUNC void _chjiggygamenew_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B28: syscall     197
    recomp_syscall_handler(rdram, ctx, 0x80085B28);
    return;
    // 0x80085B2C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A0FD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0FD8: lw          $t6, 0x150($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X150);
    // 0x800A0FDC: jr          $ra
    // 0x800A0FE0: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    return;
    // 0x800A0FE0: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
;}
RECOMP_FUNC void _mlspline_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890F8: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x800890F8);
    return;
    // 0x800890FC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800014_chexplodingchainlinks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080001C: jal         0x8008A4C8
    // 0x80800020: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _subaddieDll_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x80800024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800028: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080002C: jr          $ra
    // 0x80800030: nop

    return;
    // 0x80800030: nop

;}
RECOMP_FUNC void func_80800840_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800840: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800844: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800848: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080084C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800850: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800854: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800858: addiu       $at, $zero, 0x12B1
    ctx->r1 = ADD32(0, 0X12B1);
    // 0x8080085C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800860: beq         $a1, $at, L_808008C0
    if (ctx->r5 == ctx->r1) {
        // 0x80800864: swc1        $f4, 0x58($a0)
        MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
            goto L_808008C0;
    }
    // 0x80800864: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80800868: addiu       $at, $zero, 0x12B2
    ctx->r1 = ADD32(0, 0X12B2);
    // 0x8080086C: bne         $a1, $at, L_808008B4
    if (ctx->r5 != ctx->r1) {
        // 0x80800870: addiu       $a0, $a0, 0x18
        ctx->r4 = ADD32(ctx->r4, 0X18);
            goto L_808008B4;
    }
    // 0x80800870: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x80800874: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800878: jal         0x800EE7F8
    // 0x8080087C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8080087C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800880: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800884: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80800888: jal         0x800EF1B8
    // 0x8080088C: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x8080088C: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    after_1:
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800894: jal         0x80102424
    // 0x80800898: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800898: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x8080089C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808008A0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x808008A4: jal         0x800856D0
    // 0x808008A8: addiu       $a2, $zero, 0x2010
    ctx->r6 = ADD32(0, 0X2010);
    _capod_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x808008A8: addiu       $a2, $zero, 0x2010
    ctx->r6 = ADD32(0, 0X2010);
    after_3:
    // 0x808008AC: b           L_808008C4
    // 0x808008B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808008C4;
    // 0x808008B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008B4:
    // 0x808008B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B8: jal         0x80102424
    // 0x808008BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x808008BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_808008C0:
    // 0x808008C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008C4:
    // 0x808008C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008CC: jr          $ra
    // 0x808008D0: nop

    return;
    // 0x808008D0: nop

;}
RECOMP_FUNC void _bafly_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C10: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C10);
    return;
    // 0x80084C14: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800F5628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5628: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F562C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5630: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5638: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F563C: jal         0x80096364
    // 0x800F5640: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80096364(rdram, ctx);
        goto after_0;
    // 0x800F5640: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5648: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F564C: jr          $ra
    // 0x800F5650: nop

    return;
    // 0x800F5650: nop

;}
RECOMP_FUNC void bainput_should_feathery_flap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097D9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097DA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097DA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097DA8: jal         0x80091A58
    // 0x80097DAC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097DAC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80097DB0: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097DB4: beq         $t6, $zero, L_80097DE4
    if (ctx->r14 == 0) {
        // 0x80097DB8: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80097DE4;
    }
    // 0x80097DB8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097DBC: jal         0x8008E39C
    // 0x80097DC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E39C(rdram, ctx);
        goto after_1;
    // 0x80097DC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80097DC4: sltiu       $t7, $v0, 0x1
    ctx->r15 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80097DC8: beq         $t7, $zero, L_80097DE4
    if (ctx->r15 == 0) {
        // 0x80097DCC: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80097DE4;
    }
    // 0x80097DCC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80097DD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80097DD4: jal         0x80095748
    // 0x80097DD8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    baflag_isFalse(rdram, ctx);
        goto after_2;
    // 0x80097DD8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_2:
    // 0x80097DDC: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097DE0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80097DE4:
    // 0x80097DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80097DEC: jr          $ra
    // 0x80097DF0: nop

    return;
    // 0x80097DF0: nop

;}
RECOMP_FUNC void sucoasterplayer_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: jal         0x80100094
    // 0x80800014: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800014: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800018: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080001C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800020: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800024: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x80800028: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x8080002C: beq         $at, $zero, L_808004A4
    if (ctx->r1 == 0) {
        // 0x80800030: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808004A4;
    }
    // 0x80800030: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800034: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3298, 0X7E0) << 16);
    // 0x80800038: addu        $at, $at, $t8
    gpr jr_addend_80800040 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080003C: lw          $t8, 0x7E0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3298, 0X7E0));
    // 0x80800040: jr          $t8
    // 0x80800044: nop

    switch (jr_addend_80800040 >> 2) {
        case 0: goto L_80800048; break;
        case 1: goto L_8080012C; break;
        case 2: goto L_808004A4; break;
        case 3: goto L_808004A4; break;
        case 4: goto L_808004A4; break;
        case 5: goto L_80800454; break;
        case 6: goto L_80800278; break;
        case 7: goto L_8080035C; break;
        case 8: goto L_808004A4; break;
        case 9: goto L_80800404; break;
        case 10: goto L_80800434; break;
        case 11: goto L_80800434; break;
        case 12: goto L_808004A4; break;
        case 13: goto L_80800444; break;
        case 14: goto L_808004A4; break;
        case 15: goto L_808004A4; break;
        case 16: goto L_80800434; break;
        default: switch_error(__func__, 0x80800040, 0x808007E0);
    }
    // 0x80800044: nop

L_80800048:
    // 0x80800048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080004C: jal         0x8080076C
    // 0x80800050: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8080076C_sucoasterplayer(rdram, ctx);
        goto after_1;
    // 0x80800050: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800054: bnel        $v0, $zero, L_8080011C
    if (ctx->r2 != 0) {
        // 0x80800058: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080011C;
    }
    goto skip_0;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080005C: jal         0x808006E0
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoasterplayer_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800064: beq         $v0, $zero, L_808000DC
    if (ctx->r2 == 0) {
        // 0x80800068: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000DC;
    }
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800070: lw          $a0, 0x18($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X18);
    // 0x80800074: srl         $t0, $a0, 28
    ctx->r8 = S32(U32(ctx->r4) >> 28);
    // 0x80800078: jal         0x8008A248
    // 0x8080007C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    _sucoasterdata_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x8080007C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_3:
    // 0x80800080: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800084: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800088: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080008C: lh          $t2, 0xC($v1)
    ctx->r10 = MEM_H(ctx->r3, 0XC);
    // 0x80800090: lh          $t1, 0xE($v1)
    ctx->r9 = MEM_H(ctx->r3, 0XE);
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8080009C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x808000A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808000A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808000A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000AC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808000B0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808000B4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808000B8: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x808000BC: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x808000C0: nop

    // 0x808000C4: bc1fl       L_8080011C
    if (!c1cs) {
        // 0x808000C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080011C;
    }
    goto skip_1;
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x808000CC: jal         0x8008A140
    // 0x808000D0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x808000D0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_4:
    // 0x808000D4: b           L_8080011C
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080011C;
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000DC:
    // 0x808000DC: jal         0x801021BC
    // 0x808000E0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_801021BC(rdram, ctx);
        goto after_5;
    // 0x808000E0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_5:
    // 0x808000E4: beql        $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x808000E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080011C;
    }
    goto skip_2;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808000EC: lw          $a0, 0x64($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X64);
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F4: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x808000F8: jal         0x80016B54
    // 0x808000FC: srl         $a0, $t3, 30
    ctx->r4 = S32(U32(ctx->r11) >> 30);
    func_80016B54(rdram, ctx);
        goto after_6;
    // 0x808000FC: srl         $a0, $t3, 30
    ctx->r4 = S32(U32(ctx->r11) >> 30);
    after_6:
    // 0x80800100: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800104: bne         $v0, $at, L_80800118
    if (ctx->r2 != ctx->r1) {
        // 0x80800108: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800118;
    }
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800110: jal         0x8008A140
    // 0x80800114: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x80800114: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_7:
L_80800118:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080011C:
    // 0x8080011C: jal         0x80800618
    // 0x80800120: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    sucoasterplayer_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800120: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_8:
    // 0x80800124: b           L_808004A8
    // 0x80800128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004A8;
    // 0x80800128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080012C:
    // 0x8080012C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80800130: lw          $a0, 0x18($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X18);
    // 0x80800134: srl         $t6, $a0, 28
    ctx->r14 = S32(U32(ctx->r4) >> 28);
    // 0x80800138: jal         0x8008A248
    // 0x8080013C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterdata_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x8080013C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_9:
    // 0x80800140: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080014C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800150: jal         0x8008A150
    // 0x80800154: nop

    _sucoaster_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800154: nop

    after_10:
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: jal         0x8080076C
    // 0x80800160: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8080076C_sucoasterplayer(rdram, ctx);
        goto after_11;
    // 0x80800160: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x80800164: bnel        $v0, $zero, L_80800268
    if (ctx->r2 != 0) {
        // 0x80800168: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800268;
    }
    goto skip_3;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x8080016C: jal         0x808006E0
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoasterplayer_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800174: beq         $v0, $zero, L_80800258
    if (ctx->r2 == 0) {
        // 0x80800178: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800258;
    }
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80800180: lw          $a0, 0x18($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X18);
    // 0x80800184: srl         $t8, $a0, 28
    ctx->r24 = S32(U32(ctx->r4) >> 28);
    // 0x80800188: jal         0x8008A250
    // 0x8080018C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    _sucoasterdata_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x8080018C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_13:
    // 0x80800190: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800194: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800198: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080019C: lh          $t0, 0xC($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XC);
    // 0x808001A0: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x808001A4: lh          $t1, 0xE($t9)
    ctx->r9 = MEM_H(ctx->r25, 0XE);
    // 0x808001A8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x808001AC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808001B8: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001BC: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x808001C0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x808001C4: nop

    // 0x808001C8: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808001CC: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x808001D0: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x808001D4: nop

    // 0x808001D8: bc1fl       L_808001EC
    if (!c1cs) {
        // 0x808001DC: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_808001EC;
    }
    goto skip_4;
    // 0x808001DC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x808001E0: jal         0x8008A140
    // 0x808001E4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_14;
    // 0x808001E4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_14:
    // 0x808001E8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_808001EC:
    // 0x808001EC: lw          $a0, 0x18($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X18);
    // 0x808001F0: srl         $t3, $a0, 28
    ctx->r11 = S32(U32(ctx->r4) >> 28);
    // 0x808001F4: jal         0x8008A248
    // 0x808001F8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    _sucoasterdata_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x808001F8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_15:
    // 0x808001FC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80800200: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800204: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800208: lh          $t6, 0xC($t4)
    ctx->r14 = MEM_H(ctx->r12, 0XC);
    // 0x8080020C: lh          $t5, 0xE($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XE);
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80800218: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8080021C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800220: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800224: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800228: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8080022C: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80800230: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800234: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80800238: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x8080023C: nop

    // 0x80800240: bc1fl       L_80800268
    if (!c1cs) {
        // 0x80800244: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800268;
    }
    goto skip_5;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x80800248: jal         0x8008A140
    // 0x8080024C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_16;
    // 0x8080024C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_16:
    // 0x80800250: b           L_80800268
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800268;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800258:
    // 0x80800258: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080025C: jal         0x8008A140
    // 0x80800260: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_17;
    // 0x80800260: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_17:
    // 0x80800264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800268:
    // 0x80800268: jal         0x80800618
    // 0x8080026C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    sucoasterplayer_entrypoint_2(rdram, ctx);
        goto after_18;
    // 0x8080026C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_18:
    // 0x80800270: b           L_808004A8
    // 0x80800274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004A8;
    // 0x80800274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800278:
    // 0x80800278: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8080027C: lw          $a0, 0x18($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X18);
    // 0x80800280: srl         $t8, $a0, 28
    ctx->r24 = S32(U32(ctx->r4) >> 28);
    // 0x80800284: jal         0x8008A250
    // 0x80800288: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    _sucoasterdata_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x80800288: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_19:
    // 0x8080028C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800294: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800298: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8080029C: jal         0x8008A150
    // 0x808002A0: nop

    _sucoaster_entrypoint_11(rdram, ctx);
        goto after_20;
    // 0x808002A0: nop

    after_20:
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: jal         0x8080076C
    // 0x808002AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8080076C_sucoasterplayer(rdram, ctx);
        goto after_21;
    // 0x808002AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_21:
    // 0x808002B0: bnel        $v0, $zero, L_8080034C
    if (ctx->r2 != 0) {
        // 0x808002B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080034C;
    }
    goto skip_6;
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
    // 0x808002B8: jal         0x808006E0
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoasterplayer_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808002C0: beq         $v0, $zero, L_8080033C
    if (ctx->r2 == 0) {
        // 0x808002C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080033C;
    }
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x808002CC: lw          $a0, 0x18($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X18);
    // 0x808002D0: srl         $t9, $a0, 28
    ctx->r25 = S32(U32(ctx->r4) >> 28);
    // 0x808002D4: jal         0x8008A250
    // 0x808002D8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    _sucoasterdata_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x808002D8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_23:
    // 0x808002DC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808002E0: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x808002E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808002E8: lh          $t1, 0xC($v1)
    ctx->r9 = MEM_H(ctx->r3, 0XC);
    // 0x808002EC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x808002F0: lh          $t2, 0xE($v1)
    ctx->r10 = MEM_H(ctx->r3, 0XE);
    // 0x808002F4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x808002F8: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800304: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800308: mul.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8080030C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80800310: nop

    // 0x80800314: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800318: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8080031C: c.le.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl <= ctx->f10.fl;
    // 0x80800320: nop

    // 0x80800324: bc1fl       L_8080034C
    if (!c1cs) {
        // 0x80800328: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080034C;
    }
    goto skip_7;
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_7:
    // 0x8080032C: jal         0x8008A140
    // 0x80800330: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_24;
    // 0x80800330: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_24:
    // 0x80800334: b           L_8080034C
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080034C;
    // 0x80800338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080033C:
    // 0x8080033C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800340: jal         0x8008A140
    // 0x80800344: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_25;
    // 0x80800344: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_25:
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080034C:
    // 0x8080034C: jal         0x80800618
    // 0x80800350: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    sucoasterplayer_entrypoint_2(rdram, ctx);
        goto after_26;
    // 0x80800350: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_26:
    // 0x80800354: b           L_808004A8
    // 0x80800358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004A8;
    // 0x80800358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080035C:
    // 0x8080035C: jal         0x8008A190
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_19(rdram, ctx);
        goto after_27;
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: addiu       $a1, $s0, 0x54
    ctx->r5 = ADD32(ctx->r16, 0X54);
    // 0x8080036C: jal         0x80089BF0
    // 0x80800370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddiejoy_entrypoint_9(rdram, ctx);
        goto after_28;
    // 0x80800370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_28:
    // 0x80800374: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800378: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800380: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800384: jal         0x80102BF8
    // 0x80800388: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    func_80102BF8(rdram, ctx);
        goto after_29;
    // 0x80800388: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    after_29:
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: jal         0x80800618
    // 0x80800394: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    sucoasterplayer_entrypoint_2(rdram, ctx);
        goto after_30;
    // 0x80800394: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_30:
    // 0x80800398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080039C: jal         0x8008A178
    // 0x808003A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sucoaster_entrypoint_16(rdram, ctx);
        goto after_31;
    // 0x808003A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_31:
    // 0x808003A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A8: jal         0x8008A178
    // 0x808003AC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _sucoaster_entrypoint_16(rdram, ctx);
        goto after_32;
    // 0x808003AC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_32:
    // 0x808003B0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B8: lw          $t5, 0x18($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X18);
    // 0x808003BC: sll         $t6, $t5, 10
    ctx->r14 = S32(ctx->r13 << 10);
    // 0x808003C0: bltz        $t6, L_808003E0
    if (SIGNED(ctx->r14) < 0) {
        // 0x808003C4: nop
    
            goto L_808003E0;
    }
    // 0x808003C4: nop

    // 0x808003C8: jal         0x8008A178
    // 0x808003CC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _sucoaster_entrypoint_16(rdram, ctx);
        goto after_33;
    // 0x808003CC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_33:
    // 0x808003D0: beq         $v0, $zero, L_808003E0
    if (ctx->r2 == 0) {
        // 0x808003D4: nop
    
            goto L_808003E0;
    }
    // 0x808003D4: nop

    // 0x808003D8: jal         0x8008A338
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoasterhit_entrypoint_2(rdram, ctx);
        goto after_34;
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
L_808003E0:
    // 0x808003E0: jal         0x80101DDC
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_35;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x808003E8: beq         $v0, $zero, L_808004A4
    if (ctx->r2 == 0) {
        // 0x808003EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004A4;
    }
    // 0x808003EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808003F4: jal         0x8008A140
    // 0x808003F8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_36;
    // 0x808003F8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_36:
    // 0x808003FC: b           L_808004A8
    // 0x80800400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004A8;
    // 0x80800400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800404:
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800408: jal         0x8008A178
    // 0x8080040C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _sucoaster_entrypoint_16(rdram, ctx);
        goto after_37;
    // 0x8080040C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_37:
    // 0x80800410: jal         0x80101DDC
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_38;
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80800418: beq         $v0, $zero, L_808004A4
    if (ctx->r2 == 0) {
        // 0x8080041C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004A4;
    }
    // 0x8080041C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800420: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800424: jal         0x8008A140
    // 0x80800428: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_39;
    // 0x80800428: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_39:
    // 0x8080042C: b           L_808004A8
    // 0x80800430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004A8;
    // 0x80800430: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800434:
    // 0x80800434: lbu         $t7, 0x64($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X64);
    // 0x80800438: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x8080043C: b           L_808004A4
    // 0x80800440: sb          $t8, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r24;
        goto L_808004A4;
    // 0x80800440: sb          $t8, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r24;
L_80800444:
    // 0x80800444: jal         0x8008A330
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoasterhit_entrypoint_1(rdram, ctx);
        goto after_40;
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x8080044C: b           L_808004A8
    // 0x80800450: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004A8;
    // 0x80800450: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800454:
    // 0x80800454: jal         0x8008A190
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_19(rdram, ctx);
        goto after_41;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x8080045C: jal         0x808006E0
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoasterplayer_entrypoint_3(rdram, ctx);
        goto after_42;
    // 0x80800460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800468: jal         0x8008A178
    // 0x8080046C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sucoaster_entrypoint_16(rdram, ctx);
        goto after_43;
    // 0x8080046C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x80800470: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800474: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080047C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800480: jal         0x80102BF8
    // 0x80800484: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    func_80102BF8(rdram, ctx);
        goto after_44;
    // 0x80800484: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    after_44:
    // 0x80800488: jal         0x80101DDC
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_45;
    // 0x8080048C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x80800490: beq         $v0, $zero, L_808004A4
    if (ctx->r2 == 0) {
        // 0x80800494: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004A4;
    }
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080049C: jal         0x8008A140
    // 0x808004A0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    _sucoaster_entrypoint_9(rdram, ctx);
        goto after_46;
    // 0x808004A0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_46:
L_808004A4:
    // 0x808004A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004A8:
    // 0x808004A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808004B0: jr          $ra
    // 0x808004B4: nop

    return;
    // 0x808004B4: nop

;}
RECOMP_FUNC void func_808078F0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808078F0: lhu         $t6, 0x6E($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X6E);
    // 0x808078F4: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x808078F8: jr          $ra
    // 0x808078FC: sh          $t7, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r15;
    return;
    // 0x808078FC: sh          $t7, 0x6E($a0)
    MEM_H(0X6E, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_800BBFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BBFDC: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800BBFE0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800BBFE4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800BBFE8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800BBFEC: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x800BBFF0: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x800BBFF4: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x800BBFF8: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x800BBFFC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800BC000: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800BC004: jal         0x800D674C
    // 0x800BC008: lhu         $a0, 0x2($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x800BC008: lhu         $a0, 0x2($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2);
    after_0:
    // 0x800BC00C: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x800BC010: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800BC014: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800BC018: andi        $t6, $v1, 0x800
    ctx->r14 = ctx->r3 & 0X800;
    // 0x800BC01C: beq         $t6, $zero, L_800BC02C
    if (ctx->r14 == 0) {
        // 0x800BC020: andi        $t7, $v1, 0x20
        ctx->r15 = ctx->r3 & 0X20;
            goto L_800BC02C;
    }
    // 0x800BC020: andi        $t7, $v1, 0x20
    ctx->r15 = ctx->r3 & 0X20;
    // 0x800BC024: b           L_800BC02C
    // 0x800BC028: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
        goto L_800BC02C;
    // 0x800BC028: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800BC02C:
    // 0x800BC02C: bnel        $t7, $zero, L_800BC0E4
    if (ctx->r15 != 0) {
        // 0x800BC030: lbu         $t2, 0x53($s1)
        ctx->r10 = MEM_BU(ctx->r17, 0X53);
            goto L_800BC0E4;
    }
    goto skip_0;
    // 0x800BC030: lbu         $t2, 0x53($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X53);
    skip_0:
    // 0x800BC034: lbu         $t8, 0x80($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X80);
    // 0x800BC038: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800BC03C: bne         $v0, $t8, L_800BC068
    if (ctx->r2 != ctx->r24) {
        // 0x800BC040: nop
    
            goto L_800BC068;
    }
    // 0x800BC040: nop

    // 0x800BC044: lbu         $t9, 0x81($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X81);
    // 0x800BC048: bne         $v0, $t9, L_800BC068
    if (ctx->r2 != ctx->r25) {
        // 0x800BC04C: nop
    
            goto L_800BC068;
    }
    // 0x800BC04C: nop

    // 0x800BC050: lbu         $t0, 0x82($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X82);
    // 0x800BC054: bne         $v0, $t0, L_800BC068
    if (ctx->r2 != ctx->r8) {
        // 0x800BC058: nop
    
            goto L_800BC068;
    }
    // 0x800BC058: nop

    // 0x800BC05C: lbu         $t1, 0x83($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X83);
    // 0x800BC060: beql        $v0, $t1, L_800BC0E4
    if (ctx->r2 == ctx->r9) {
        // 0x800BC064: lbu         $t2, 0x53($s1)
        ctx->r10 = MEM_BU(ctx->r17, 0X53);
            goto L_800BC0E4;
    }
    goto skip_1;
    // 0x800BC064: lbu         $t2, 0x53($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X53);
    skip_1:
L_800BC068:
    // 0x800BC068: jal         0x800E2588
    // 0x800BC06C: lbu         $a0, 0x53($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X53);
    func_800E2588(rdram, ctx);
        goto after_1;
    // 0x800BC06C: lbu         $a0, 0x53($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X53);
    after_1:
    // 0x800BC070: lbu         $a0, 0x80($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X80);
    // 0x800BC074: lbu         $a1, 0x81($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X81);
    // 0x800BC078: jal         0x800E24F8
    // 0x800BC07C: lbu         $a2, 0x82($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X82);
    func_800E24F8(rdram, ctx);
        goto after_2;
    // 0x800BC07C: lbu         $a2, 0x82($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X82);
    after_2:
    // 0x800BC080: lbu         $v0, 0x80($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X80);
    // 0x800BC084: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800BC088: beq         $at, $zero, L_800BC098
    if (ctx->r1 == 0) {
        // 0x800BC08C: addiu       $a0, $v0, -0x8
        ctx->r4 = ADD32(ctx->r2, -0X8);
            goto L_800BC098;
    }
    // 0x800BC08C: addiu       $a0, $v0, -0x8
    ctx->r4 = ADD32(ctx->r2, -0X8);
    // 0x800BC090: b           L_800BC098
    // 0x800BC094: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_800BC098;
    // 0x800BC094: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BC098:
    // 0x800BC098: lbu         $v0, 0x81($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X81);
    // 0x800BC09C: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800BC0A0: beq         $at, $zero, L_800BC0B0
    if (ctx->r1 == 0) {
        // 0x800BC0A4: addiu       $a1, $v0, -0x8
        ctx->r5 = ADD32(ctx->r2, -0X8);
            goto L_800BC0B0;
    }
    // 0x800BC0A4: addiu       $a1, $v0, -0x8
    ctx->r5 = ADD32(ctx->r2, -0X8);
    // 0x800BC0A8: b           L_800BC0B0
    // 0x800BC0AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800BC0B0;
    // 0x800BC0AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800BC0B0:
    // 0x800BC0B0: lbu         $v0, 0x82($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X82);
    // 0x800BC0B4: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800BC0B8: beq         $at, $zero, L_800BC0C8
    if (ctx->r1 == 0) {
        // 0x800BC0BC: addiu       $a2, $v0, -0x8
        ctx->r6 = ADD32(ctx->r2, -0X8);
            goto L_800BC0C8;
    }
    // 0x800BC0BC: addiu       $a2, $v0, -0x8
    ctx->r6 = ADD32(ctx->r2, -0X8);
    // 0x800BC0C0: b           L_800BC0C8
    // 0x800BC0C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800BC0C8;
    // 0x800BC0C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800BC0C8:
    // 0x800BC0C8: jal         0x800E2440
    // 0x800BC0CC: nop

    func_800E2440(rdram, ctx);
        goto after_3;
    // 0x800BC0CC: nop

    after_3:
    // 0x800BC0D0: jal         0x800E24B4
    // 0x800BC0D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800E24B4(rdram, ctx);
        goto after_4;
    // 0x800BC0D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800BC0D8: b           L_800BC104
    // 0x800BC0DC: lhu         $t3, 0x0($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X0);
        goto L_800BC104;
    // 0x800BC0DC: lhu         $t3, 0x0($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X0);
    // 0x800BC0E0: lbu         $t2, 0x53($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X53);
L_800BC0E4:
    // 0x800BC0E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BC0E8: beq         $t2, $zero, L_800BC0F8
    if (ctx->r10 == 0) {
        // 0x800BC0EC: nop
    
            goto L_800BC0F8;
    }
    // 0x800BC0EC: nop

    // 0x800BC0F0: b           L_800BC0F8
    // 0x800BC0F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_800BC0F8;
    // 0x800BC0F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_800BC0F8:
    // 0x800BC0F8: jal         0x800E2588
    // 0x800BC0FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800E2588(rdram, ctx);
        goto after_5;
    // 0x800BC0FC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x800BC100: lhu         $t3, 0x0($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X0);
L_800BC104:
    // 0x800BC104: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BC108: andi        $t4, $t3, 0x200
    ctx->r12 = ctx->r11 & 0X200;
    // 0x800BC10C: beq         $t4, $zero, L_800BC11C
    if (ctx->r12 == 0) {
        // 0x800BC110: nop
    
            goto L_800BC11C;
    }
    // 0x800BC110: nop

    // 0x800BC114: b           L_800BC11C
    // 0x800BC118: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800BC11C;
    // 0x800BC118: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800BC11C:
    // 0x800BC11C: jal         0x800E24D8
    // 0x800BC120: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800E24D8(rdram, ctx);
        goto after_6;
    // 0x800BC120: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_6:
    // 0x800BC124: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800BC128: jal         0x800E2594
    // 0x800BC12C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800E2594(rdram, ctx);
        goto after_7;
    // 0x800BC12C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800BC130: lhu         $t5, 0x0($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X0);
    // 0x800BC134: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800BC138: beql        $t6, $zero, L_800BC160
    if (ctx->r14 == 0) {
        // 0x800BC13C: lw          $s0, 0x8C($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X8C);
            goto L_800BC160;
    }
    goto skip_2;
    // 0x800BC13C: lw          $s0, 0x8C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8C);
    skip_2:
    // 0x800BC140: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BC144: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x800BC148: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x800BC14C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800BC150: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800BC154: jal         0x800EFA4C
    // 0x800BC158: nop

    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x800BC158: nop

    after_8:
    // 0x800BC15C: lw          $s0, 0x8C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X8C);
L_800BC160:
    // 0x800BC160: lw          $t7, 0x90($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X90);
    // 0x800BC164: addiu       $s3, $sp, 0x78
    ctx->r19 = ADD32(ctx->r29, 0X78);
    // 0x800BC168: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // 0x800BC16C: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x800BC170: beq         $at, $zero, L_800BC32C
    if (ctx->r1 == 0) {
        // 0x800BC174: nop
    
            goto L_800BC32C;
    }
    // 0x800BC174: nop

    // 0x800BC178: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
L_800BC17C:
    // 0x800BC17C: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x800BC180: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800BC184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BC188: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800BC18C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800BC190: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800BC194: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BC198: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x800BC19C: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    // 0x800BC1A0: lh          $t1, 0xE($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XE);
    // 0x800BC1A4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800BC1A8: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800BC1AC: nop

    // 0x800BC1B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BC1B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BC1B8: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    // 0x800BC1BC: lh          $t5, 0xA($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA);
    // 0x800BC1C0: lh          $t4, 0x10($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X10);
    // 0x800BC1C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800BC1C8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800BC1CC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800BC1D0: nop

    // 0x800BC1D4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BC1D8: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x800BC1DC: lh          $t7, 0x30($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X30);
    // 0x800BC1E0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800BC1E4: nop

    // 0x800BC1E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BC1EC: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BC1F0: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x800BC1F4: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x800BC1F8: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x800BC1FC: lwc1        $f16, 0x5C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x800BC200: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x800BC204: nop

    // 0x800BC208: bc1tl       L_800BC21C
    if (c1cs) {
        // 0x800BC20C: lhu         $t8, 0x0($s1)
        ctx->r24 = MEM_HU(ctx->r17, 0X0);
            goto L_800BC21C;
    }
    goto skip_3;
    // 0x800BC20C: lhu         $t8, 0x0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X0);
    skip_3:
    // 0x800BC210: jal         0x800BBED8
    // 0x800BC214: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    func_800BBED8(rdram, ctx);
        goto after_9;
    // 0x800BC214: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_9:
    // 0x800BC218: lhu         $t8, 0x0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X0);
L_800BC21C:
    // 0x800BC21C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800BC220: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800BC224: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800BC228: beq         $t9, $zero, L_800BC2A0
    if (ctx->r25 == 0) {
        // 0x800BC22C: addiu       $t1, $sp, 0x6C
        ctx->r9 = ADD32(ctx->r29, 0X6C);
            goto L_800BC2A0;
    }
    // 0x800BC22C: addiu       $t1, $sp, 0x6C
    ctx->r9 = ADD32(ctx->r29, 0X6C);
    // 0x800BC230: lh          $a1, 0x2C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2C);
    // 0x800BC234: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    // 0x800BC238: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800BC23C: lbu         $t2, 0x83($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X83);
    // 0x800BC240: sra         $t0, $a1, 8
    ctx->r8 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800BC244: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x800BC248: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800BC24C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800BC250: bgez        $t2, L_800BC268
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BC254: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BC268;
    }
    // 0x800BC254: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BC258: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC25C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BC260: nop

    // 0x800BC264: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800BC268:
    // 0x800BC268: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800BC26C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800BC270: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BC274: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x800BC278: jal         0x800E28A4
    // 0x800BC27C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    func_800E28A4(rdram, ctx);
        goto after_10;
    // 0x800BC27C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_10:
    // 0x800BC280: lbu         $v1, 0x39($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X39);
    // 0x800BC284: srl         $t5, $v1, 7
    ctx->r13 = S32(U32(ctx->r3) >> 7);
    // 0x800BC288: or          $t7, $t5, $v0
    ctx->r15 = ctx->r13 | ctx->r2;
    // 0x800BC28C: sll         $t9, $t7, 7
    ctx->r25 = S32(ctx->r15 << 7);
    // 0x800BC290: andi        $t0, $v1, 0xFF7F
    ctx->r8 = ctx->r3 & 0XFF7F;
    // 0x800BC294: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x800BC298: b           L_800BC318
    // 0x800BC29C: sb          $t1, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r9;
        goto L_800BC318;
    // 0x800BC29C: sb          $t1, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r9;
L_800BC2A0:
    // 0x800BC2A0: jal         0x800E2530
    // 0x800BC2A4: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    func_800E2530(rdram, ctx);
        goto after_11;
    // 0x800BC2A4: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    after_11:
    // 0x800BC2A8: lh          $a1, 0x2C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2C);
    // 0x800BC2AC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800BC2B0: lbu         $t3, 0x83($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X83);
    // 0x800BC2B4: sra         $t2, $a1, 8
    ctx->r10 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800BC2B8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800BC2BC: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800BC2C0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800BC2C4: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800BC2C8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800BC2CC: bgez        $t3, L_800BC2E4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800BC2D0: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BC2E4;
    }
    // 0x800BC2D0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BC2D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BC2D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BC2DC: nop

    // 0x800BC2E0: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
L_800BC2E4:
    // 0x800BC2E4: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800BC2E8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BC2EC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800BC2F0: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x800BC2F4: jal         0x800E2720
    // 0x800BC2F8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    func_800E2720(rdram, ctx);
        goto after_12;
    // 0x800BC2F8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_12:
    // 0x800BC2FC: lbu         $v1, 0x39($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X39);
    // 0x800BC300: srl         $t6, $v1, 7
    ctx->r14 = S32(U32(ctx->r3) >> 7);
    // 0x800BC304: or          $t8, $t6, $v0
    ctx->r24 = ctx->r14 | ctx->r2;
    // 0x800BC308: sll         $t0, $t8, 7
    ctx->r8 = S32(ctx->r24 << 7);
    // 0x800BC30C: andi        $t1, $v1, 0xFF7F
    ctx->r9 = ctx->r3 & 0XFF7F;
    // 0x800BC310: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x800BC314: sb          $t2, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r10;
L_800BC318:
    // 0x800BC318: lw          $t3, 0x90($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X90);
    // 0x800BC31C: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x800BC320: sltu        $at, $s0, $t3
    ctx->r1 = ctx->r16 < ctx->r11 ? 1 : 0;
    // 0x800BC324: bnel        $at, $zero, L_800BC17C
    if (ctx->r1 != 0) {
        // 0x800BC328: lh          $t8, 0xC($s1)
        ctx->r24 = MEM_H(ctx->r17, 0XC);
            goto L_800BC17C;
    }
    goto skip_4;
    // 0x800BC328: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
    skip_4:
L_800BC32C:
    // 0x800BC32C: jal         0x800E2A14
    // 0x800BC330: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800E2A14(rdram, ctx);
        goto after_13;
    // 0x800BC330: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_13:
    // 0x800BC334: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800BC338: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800BC33C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800BC340: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800BC344: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800BC348: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800BC34C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800BC350: jr          $ra
    // 0x800BC354: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800BC354: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8002603C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002603C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80026040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026044: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80026048: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002604C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80026050: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80026054: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80026058: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8002605C: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80026060: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80026064: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x80026068: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x8002606C: addiu       $t9, $zero, 0x5C
    ctx->r25 = ADD32(0, 0X5C);
    // 0x80026070: sb          $t9, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r25;
    // 0x80026074: lbu         $t0, 0x33($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X33);
    // 0x80026078: sb          $t0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r8;
    // 0x8002607C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80026080: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80026084: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80026088: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002608C: jal         0x80026500
    // 0x80026090: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x80026090: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x80026094: b           L_8002609C
    // 0x80026098: nop

        goto L_8002609C;
    // 0x80026098: nop

L_8002609C:
    // 0x8002609C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800260A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800260A4: jr          $ra
    // 0x800260A8: nop

    return;
    // 0x800260A8: nop

    // 0x800260AC: nop

;}
RECOMP_FUNC void chbottlesfamily_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1300, 0XE70) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0xE70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1300, 0XE70));
    return;
    // 0x80800020: addiu       $v0, $v0, 0xE70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1300, 0XE70));
;}
RECOMP_FUNC void func_808016E8_chnicecavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808016EC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808016F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808016F8: bne         $a1, $at, L_80801750
    if (ctx->r5 != ctx->r1) {
        // 0x808016FC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80801750;
    }
    // 0x808016FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801700: lhu         $t6, 0x18($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X18);
    // 0x80801704: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801708: addiu       $a1, $zero, 0x92
    ctx->r5 = ADD32(0, 0X92);
    // 0x8080170C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80801710: beq         $t7, $zero, L_80801720
    if (ctx->r15 == 0) {
        // 0x80801714: nop
    
            goto L_80801720;
    }
    // 0x80801714: nop

    // 0x80801718: jal         0x8010114C
    // 0x8080171C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x8080171C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_80801720:
    // 0x80801720: jal         0x8010A570
    // 0x80801724: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x80801724: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801728: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080172C: jal         0x80101FDC
    // 0x80801730: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80801730: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80801734: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80801738: jal         0x800DA544
    // 0x8080173C: lw          $a0, 0x28($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X28);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x8080173C: lw          $a0, 0x28($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X28);
    after_3:
    // 0x80801740: jal         0x800FC6B0
    // 0x80801744: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_4;
    // 0x80801744: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_4:
    // 0x80801748: b           L_8080175C
    // 0x8080174C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080175C;
    // 0x8080174C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801750:
    // 0x80801750: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801754: jal         0x80086158
    // 0x80801758: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _chfirefx_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80801758: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_5:
L_8080175C:
    // 0x8080175C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801760: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801764: jr          $ra
    // 0x80801768: nop

    return;
    // 0x80801768: nop

    // 0x8080176C: nop

;}
RECOMP_FUNC void _chmumbopadstatue_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086FC8: syscall     488
    recomp_syscall_handler(rdram, ctx, 0x80086FC8);
    return;
    // 0x80086FCC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _batimer_get_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800852E0: syscall     157
    recomp_syscall_handler(rdram, ctx, 0x800852E0);
    return;
    // 0x800852E4: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_800EEBF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEBF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EEBF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EEBF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800EEBFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800EEC00: jal         0x800EFD24
    // 0x800EEC04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x800EEC04: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800EEC08: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800EEC0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800EEC10: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800EEC14: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800EEC18: jal         0x800EF214
    // 0x800EEC1C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    func_800EF214(rdram, ctx);
        goto after_1;
    // 0x800EEC1C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x800EEC20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EEC24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EEC28: jr          $ra
    // 0x800EEC2C: nop

    return;
    // 0x800EEC2C: nop

;}
RECOMP_FUNC void bainvisible_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800410: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800414: lw          $t6, 0xA8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA8);
    // 0x80800418: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8080041C: swc1        $f12, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f12.u32l;
    // 0x80800420: lw          $t7, 0xA8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XA8);
    // 0x80800424: jr          $ra
    // 0x80800428: swc1        $f14, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f14.u32l;
    return;
    // 0x80800428: swc1        $f14, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f14.u32l;
;}
RECOMP_FUNC void scinfobar_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800590: jr          $ra
    // 0x80800594: lh          $v0, 0x8($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X8);
    return;
    // 0x80800594: lh          $v0, 0x8($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X8);
;}
RECOMP_FUNC void func_80094E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094E70: jr          $ra
    // 0x80094E74: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    return;
    // 0x80094E74: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_808019EC_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019EC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808019F0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808019F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808019F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808019FC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80801A00: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80801A04: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80801A08: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x80801A0C: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x80801A10: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80801A14: beq         $at, $zero, L_80801CD0
    if (ctx->r1 == 0) {
        // 0x80801A18: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_80801CD0;
    }
    // 0x80801A18: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80801A1C: sw          $t9, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r25;
    // 0x80801A20: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80801A24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801A28: beq         $t0, $zero, L_80801A58
    if (ctx->r8 == 0) {
        // 0x80801A2C: nop
    
            goto L_80801A58;
    }
    // 0x80801A2C: nop

    // 0x80801A30: beq         $t0, $at, L_80801B58
    if (ctx->r8 == ctx->r1) {
        // 0x80801A34: addiu       $s0, $sp, 0x3C
        ctx->r16 = ADD32(ctx->r29, 0X3C);
            goto L_80801B58;
    }
    // 0x80801A34: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x80801A38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801A3C: beq         $t0, $at, L_80801B80
    if (ctx->r8 == ctx->r1) {
        // 0x80801A40: addiu       $s0, $sp, 0x3C
        ctx->r16 = ADD32(ctx->r29, 0X3C);
            goto L_80801B80;
    }
    // 0x80801A40: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x80801A44: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801A48: beq         $t0, $at, L_80801BB0
    if (ctx->r8 == ctx->r1) {
        // 0x80801A4C: addiu       $s0, $sp, 0x3C
        ctx->r16 = ADD32(ctx->r29, 0X3C);
            goto L_80801BB0;
    }
    // 0x80801A4C: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x80801A50: b           L_80801BD8
    // 0x80801A54: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
        goto L_80801BD8;
    // 0x80801A54: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
L_80801A58:
    // 0x80801A58: jal         0x800DC0C0
    // 0x80801A5C: nop

    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x80801A5C: nop

    after_0:
    // 0x80801A60: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80801A64: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80801A68: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x80801A6C: lw          $a0, 0x70($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X70);
    // 0x80801A70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801A74: srl         $t2, $a0, 25
    ctx->r10 = S32(U32(ctx->r4) >> 25);
    // 0x80801A78: jal         0x800CD08C
    // 0x80801A7C: addiu       $a0, $t2, -0x1
    ctx->r4 = ADD32(ctx->r10, -0X1);
    func_800CD08C(rdram, ctx);
        goto after_1;
    // 0x80801A7C: addiu       $a0, $t2, -0x1
    ctx->r4 = ADD32(ctx->r10, -0X1);
    after_1:
    // 0x80801A80: jal         0x80800B64
    // 0x80801A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B64_chtrashcangame(rdram, ctx);
        goto after_2;
    // 0x80801A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801A88: beql        $v0, $zero, L_80801ABC
    if (ctx->r2 == 0) {
        // 0x80801A8C: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80801ABC;
    }
    goto skip_0;
    // 0x80801A8C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x80801A90: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
L_80801A94:
    // 0x80801A94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801A98: lw          $a0, 0x70($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X70);
    // 0x80801A9C: srl         $t4, $a0, 25
    ctx->r12 = S32(U32(ctx->r4) >> 25);
    // 0x80801AA0: jal         0x800CD08C
    // 0x80801AA4: addiu       $a0, $t4, -0x1
    ctx->r4 = ADD32(ctx->r12, -0X1);
    func_800CD08C(rdram, ctx);
        goto after_3;
    // 0x80801AA4: addiu       $a0, $t4, -0x1
    ctx->r4 = ADD32(ctx->r12, -0X1);
    after_3:
    // 0x80801AA8: jal         0x80800B64
    // 0x80801AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B64_chtrashcangame(rdram, ctx);
        goto after_4;
    // 0x80801AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801AB0: bnel        $v0, $zero, L_80801A94
    if (ctx->r2 != 0) {
        // 0x80801AB4: lw          $t3, 0x48($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X48);
            goto L_80801A94;
    }
    goto skip_1;
    // 0x80801AB4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    skip_1:
    // 0x80801AB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80801ABC:
    // 0x80801ABC: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801AC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801AC4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2F90) << 16);
    // 0x80801AC8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801ACC: nop

    // 0x80801AD0: bc1f        L_80801AFC
    if (!c1cs) {
        // 0x80801AD4: nop
    
            goto L_80801AFC;
    }
    // 0x80801AD4: nop

    // 0x80801AD8: jal         0x800D3948
    // 0x80801ADC: nop

    func_800D3948(rdram, ctx);
        goto after_5;
    // 0x80801ADC: nop

    after_5:
    // 0x80801AE0: beq         $v0, $zero, L_80801AF4
    if (ctx->r2 == 0) {
        // 0x80801AE4: addiu       $t6, $zero, 0x805
        ctx->r14 = ADD32(0, 0X805);
            goto L_80801AF4;
    }
    // 0x80801AE4: addiu       $t6, $zero, 0x805
    ctx->r14 = ADD32(0, 0X805);
    // 0x80801AE8: addiu       $t5, $zero, 0x99D
    ctx->r13 = ADD32(0, 0X99D);
    // 0x80801AEC: b           L_80801BD8
    // 0x80801AF0: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
        goto L_80801BD8;
    // 0x80801AF0: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_80801AF4:
    // 0x80801AF4: b           L_80801BD8
    // 0x80801AF8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
        goto L_80801BD8;
    // 0x80801AF8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_80801AFC:
    // 0x80801AFC: lwc1        $f6, 0x2F90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2F90));
    // 0x80801B00: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80801B04: nop

    // 0x80801B08: bc1f        L_80801B34
    if (!c1cs) {
        // 0x80801B0C: nop
    
            goto L_80801B34;
    }
    // 0x80801B0C: nop

    // 0x80801B10: jal         0x800D3948
    // 0x80801B14: nop

    func_800D3948(rdram, ctx);
        goto after_6;
    // 0x80801B14: nop

    after_6:
    // 0x80801B18: beq         $v0, $zero, L_80801B2C
    if (ctx->r2 == 0) {
        // 0x80801B1C: addiu       $t9, $zero, 0x804
        ctx->r25 = ADD32(0, 0X804);
            goto L_80801B2C;
    }
    // 0x80801B1C: addiu       $t9, $zero, 0x804
    ctx->r25 = ADD32(0, 0X804);
    // 0x80801B20: addiu       $t8, $zero, 0x99E
    ctx->r24 = ADD32(0, 0X99E);
    // 0x80801B24: b           L_80801BD8
    // 0x80801B28: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_80801BD8;
    // 0x80801B28: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80801B2C:
    // 0x80801B2C: b           L_80801BD8
    // 0x80801B30: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
        goto L_80801BD8;
    // 0x80801B30: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_80801B34:
    // 0x80801B34: jal         0x800D3948
    // 0x80801B38: nop

    func_800D3948(rdram, ctx);
        goto after_7;
    // 0x80801B38: nop

    after_7:
    // 0x80801B3C: beq         $v0, $zero, L_80801B50
    if (ctx->r2 == 0) {
        // 0x80801B40: addiu       $t0, $zero, 0x806
        ctx->r8 = ADD32(0, 0X806);
            goto L_80801B50;
    }
    // 0x80801B40: addiu       $t0, $zero, 0x806
    ctx->r8 = ADD32(0, 0X806);
    // 0x80801B44: addiu       $t7, $zero, 0x99F
    ctx->r15 = ADD32(0, 0X99F);
    // 0x80801B48: b           L_80801BD8
    // 0x80801B4C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_80801BD8;
    // 0x80801B4C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80801B50:
    // 0x80801B50: b           L_80801BD8
    // 0x80801B54: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
        goto L_80801BD8;
    // 0x80801B54: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80801B58:
    // 0x80801B58: addiu       $t1, $zero, 0x805
    ctx->r9 = ADD32(0, 0X805);
    // 0x80801B5C: lui         $a3, 0xC492
    ctx->r7 = S32(0XC492 << 16);
    // 0x80801B60: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x80801B64: ori         $a3, $a3, 0xA000
    ctx->r7 = ctx->r7 | 0XA000;
    // 0x80801B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B6C: lui         $a1, 0xC433
    ctx->r5 = S32(0XC433 << 16);
    // 0x80801B70: jal         0x800EFA4C
    // 0x80801B74: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_8;
    // 0x80801B74: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_8:
    // 0x80801B78: b           L_80801BD8
    // 0x80801B7C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
        goto L_80801BD8;
    // 0x80801B7C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80801B80:
    // 0x80801B80: addiu       $t2, $zero, 0x804
    ctx->r10 = ADD32(0, 0X804);
    // 0x80801B84: lui         $a1, 0x4496
    ctx->r5 = S32(0X4496 << 16);
    // 0x80801B88: lui         $a3, 0xC44A
    ctx->r7 = S32(0XC44A << 16);
    // 0x80801B8C: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80801B90: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x80801B94: ori         $a1, $a1, 0x6000
    ctx->r5 = ctx->r5 | 0X6000;
    // 0x80801B98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B9C: jal         0x800EFA4C
    // 0x80801BA0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x80801BA0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_9:
    // 0x80801BA4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80801BA8: b           L_80801BD8
    // 0x80801BAC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
        goto L_80801BD8;
    // 0x80801BAC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
L_80801BB0:
    // 0x80801BB0: addiu       $t4, $zero, 0x806
    ctx->r12 = ADD32(0, 0X806);
    // 0x80801BB4: lui         $a1, 0x4483
    ctx->r5 = S32(0X4483 << 16);
    // 0x80801BB8: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80801BBC: ori         $a1, $a1, 0x4000
    ctx->r5 = ctx->r5 | 0X4000;
    // 0x80801BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BC4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80801BC8: jal         0x800EFA4C
    // 0x80801BCC: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    func_800EFA4C(rdram, ctx);
        goto after_10;
    // 0x80801BCC: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    after_10:
    // 0x80801BD0: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80801BD4: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
L_80801BD8:
    // 0x80801BD8: addiu       $a0, $zero, 0x476
    ctx->r4 = ADD32(0, 0X476);
    // 0x80801BDC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801BE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801BE4: jal         0x80108528
    // 0x80801BE8: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    func_80108528(rdram, ctx);
        goto after_11;
    // 0x80801BE8: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    after_11:
    // 0x80801BEC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801BF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801BF4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801BF8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80801BFC: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
    // 0x80801C00: lhu         $a1, 0x36($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X36);
    // 0x80801C04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801C08: jal         0x80103140
    // 0x80801C0C: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    func_80103140(rdram, ctx);
        goto after_12;
    // 0x80801C0C: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    after_12:
    // 0x80801C10: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80801C14: lhu         $a1, 0x72($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X72);
    // 0x80801C18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C1C: srl         $t8, $a1, 10
    ctx->r24 = S32(U32(ctx->r5) >> 10);
    // 0x80801C20: jal         0x80102424
    // 0x80801C24: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    func_80102424(rdram, ctx);
        goto after_13;
    // 0x80801C24: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_13:
    // 0x80801C28: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80801C2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801C30: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80801C34: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80801C38: sw          $t7, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r15;
    // 0x80801C3C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80801C40: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80801C44: beq         $t0, $at, L_80801C54
    if (ctx->r8 == ctx->r1) {
        // 0x80801C48: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_80801C54;
    }
    // 0x80801C48: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80801C4C: jal         0x808016B4
    // 0x80801C50: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    func_808016B4_chtrashcangame(rdram, ctx);
        goto after_14;
    // 0x80801C50: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    after_14:
L_80801C54:
    // 0x80801C54: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x80801C58: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80801C5C: beq         $t2, $zero, L_80801C90
    if (ctx->r10 == 0) {
        // 0x80801C60: nop
    
            goto L_80801C90;
    }
    // 0x80801C60: nop

    // 0x80801C64: lbu         $t4, 0x79($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X79);
    // 0x80801C68: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x80801C6C: srl         $t5, $t4, 4
    ctx->r13 = S32(U32(ctx->r12) >> 4);
    // 0x80801C70: xor         $t6, $t2, $t5
    ctx->r14 = ctx->r10 ^ ctx->r13;
    // 0x80801C74: sltiu       $t8, $t6, 0x1
    ctx->r24 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x80801C78: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80801C7C: andi        $t7, $t9, 0x10
    ctx->r15 = ctx->r25 & 0X10;
    // 0x80801C80: andi        $t0, $t1, 0xFFEF
    ctx->r8 = ctx->r9 & 0XFFEF;
    // 0x80801C84: or          $t3, $t7, $t0
    ctx->r11 = ctx->r15 | ctx->r8;
    // 0x80801C88: b           L_80801CD0
    // 0x80801C8C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
        goto L_80801CD0;
    // 0x80801C8C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80801C90:
    // 0x80801C90: jal         0x800DC0C0
    // 0x80801C94: nop

    func_800DC0C0(rdram, ctx);
        goto after_15;
    // 0x80801C94: nop

    after_15:
    // 0x80801C98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2F94) << 16);
    // 0x80801C9C: lwc1        $f10, 0x2F94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2F94));
    // 0x80801CA0: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80801CA4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80801CA8: nop

    // 0x80801CAC: bc1fl       L_80801CBC
    if (!c1cs) {
        // 0x80801CB0: lbu         $t8, 0x65($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X65);
            goto L_80801CBC;
    }
    goto skip_2;
    // 0x80801CB0: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
    skip_2:
    // 0x80801CB4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80801CB8: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
L_80801CBC:
    // 0x80801CBC: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80801CC0: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x80801CC4: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x80801CC8: or          $t1, $t6, $t9
    ctx->r9 = ctx->r14 | ctx->r25;
    // 0x80801CCC: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_80801CD0:
    // 0x80801CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801CD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801CD8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801CDC: jr          $ra
    // 0x80801CE0: nop

    return;
    // 0x80801CE0: nop

;}
RECOMP_FUNC void func_808008E4_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008E8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808008EC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808008F0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808008F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808008F8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808008FC: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80800900: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800904: jal         0x800DA298
    // 0x80800908: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800908: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_0:
    // 0x8080090C: beq         $v0, $zero, L_8080091C
    if (ctx->r2 == 0) {
        // 0x80800910: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080091C;
    }
    // 0x80800910: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800914: b           L_80800920
    // 0x80800918: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80800920;
    // 0x80800918: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_8080091C:
    // 0x8080091C: addiu       $v0, $zero, 0x9E
    ctx->r2 = ADD32(0, 0X9E);
L_80800920:
    // 0x80800920: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80800924: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80800928: jal         0x80087D98
    // 0x8080092C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    _gcnewoption_entrypoint_32(rdram, ctx);
        goto after_1;
    // 0x8080092C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_1:
    // 0x80800930: blez        $s2, L_80800970
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80800934: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800970;
    }
    // 0x80800934: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800938: andi        $t7, $s0, 0x1
    ctx->r15 = ctx->r16 & 0X1;
L_8080093C:
    // 0x8080093C: beq         $t7, $zero, L_8080094C
    if (ctx->r15 == 0) {
        // 0x80800940: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080094C;
    }
    // 0x80800940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800944: b           L_80800950
    // 0x80800948: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
        goto L_80800950;
    // 0x80800948: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
L_8080094C:
    // 0x8080094C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_80800950:
    // 0x80800950: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80800954: sra         $t8, $a2, 16
    ctx->r24 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80800958: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8080095C: jal         0x80087D90
    // 0x80800960: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    _gcnewoption_entrypoint_31(rdram, ctx);
        goto after_2;
    // 0x80800960: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80800964: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800968: bnel        $s0, $s2, L_8080093C
    if (ctx->r16 != ctx->r18) {
        // 0x8080096C: andi        $t7, $s0, 0x1
        ctx->r15 = ctx->r16 & 0X1;
            goto L_8080093C;
    }
    goto skip_0;
    // 0x8080096C: andi        $t7, $s0, 0x1
    ctx->r15 = ctx->r16 & 0X1;
    skip_0:
L_80800970:
    // 0x80800970: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800974: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800978: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080097C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800980: jr          $ra
    // 0x80800984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void bskazshock_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080072C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800734: jal         0x8009BC6C
    // 0x80800738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x80800738: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080073C: jal         0x800832E8
    // 0x80800740: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800740: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080074C: jr          $ra
    // 0x80800750: nop

    return;
    // 0x80800750: nop

;}
RECOMP_FUNC void chflowerbaddie_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1388, 0XC14) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xC14
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1388, 0XC14));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xC14
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1388, 0XC14));
;}
RECOMP_FUNC void func_8008FE14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FE14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FE18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FE1C: jal         0x800F54E4
    // 0x8008FE20: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FE20: nop

    after_0:
    // 0x8008FE24: jal         0x800F5704
    // 0x8008FE28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5704(rdram, ctx);
        goto after_1;
    // 0x8008FE28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008FE2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FE30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FE34: jr          $ra
    // 0x8008FE38: nop

    return;
    // 0x8008FE38: nop

;}
RECOMP_FUNC void func_800E8B04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8B04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E8B08: lw          $a0, -0x2980($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2980);
    // 0x800E8B0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8B14: beql        $a0, $zero, L_800E8B30
    if (ctx->r4 == 0) {
        // 0x800E8B18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E8B30;
    }
    goto skip_0;
    // 0x800E8B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E8B1C: jal         0x800B3248
    // 0x800E8B20: nop

    freelist_free(rdram, ctx);
        goto after_0;
    // 0x800E8B20: nop

    after_0:
    // 0x800E8B24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E8B28: sw          $zero, -0x2980($at)
    MEM_W(-0X2980, ctx->r1) = 0;
    // 0x800E8B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E8B30:
    // 0x800E8B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8B34: jr          $ra
    // 0x800E8B38: nop

    return;
    // 0x800E8B38: nop

;}
RECOMP_FUNC void func_8080061C_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080061C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800620: addiu       $t9, $a1, -0x10D4
    ctx->r25 = ADD32(ctx->r5, -0X10D4);
    // 0x80800624: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800628: ori         $t7, $a2, 0x6
    ctx->r15 = ctx->r6 | 0X6;
    // 0x8080062C: sltiu       $at, $t9, 0x1E
    ctx->r1 = ctx->r25 < 0X1E ? 1 : 0;
    // 0x80800630: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800634: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800638: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080063C: beq         $at, $zero, L_8080069C
    if (ctx->r1 == 0) {
        // 0x80800640: sw          $t7, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r15;
            goto L_8080069C;
    }
    // 0x80800640: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80800644: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800648: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X49CC) << 16);
    // 0x8080064C: addu        $at, $at, $t9
    gpr jr_addend_80800654 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800650: lw          $t9, 0x49CC($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1752, 0X49CC));
    // 0x80800654: jr          $t9
    // 0x80800658: nop

    switch (jr_addend_80800654 >> 2) {
        case 0: goto L_80800674; break;
        case 1: goto L_80800674; break;
        case 2: goto L_80800674; break;
        case 3: goto L_8080068C; break;
        case 4: goto L_8080069C; break;
        case 5: goto L_8080065C; break;
        case 6: goto L_8080065C; break;
        case 7: goto L_8080069C; break;
        case 8: goto L_8080069C; break;
        case 9: goto L_8080069C; break;
        case 10: goto L_8080069C; break;
        case 11: goto L_8080069C; break;
        case 12: goto L_8080069C; break;
        case 13: goto L_8080069C; break;
        case 14: goto L_8080069C; break;
        case 15: goto L_8080069C; break;
        case 16: goto L_8080069C; break;
        case 17: goto L_8080069C; break;
        case 18: goto L_8080069C; break;
        case 19: goto L_8080069C; break;
        case 20: goto L_8080069C; break;
        case 21: goto L_8080069C; break;
        case 22: goto L_8080069C; break;
        case 23: goto L_8080069C; break;
        case 24: goto L_80800674; break;
        case 25: goto L_8080068C; break;
        case 26: goto L_80800674; break;
        case 27: goto L_8080068C; break;
        case 28: goto L_80800674; break;
        case 29: goto L_8080068C; break;
        default: switch_error(__func__, 0x80800654, 0x808049CC);
    }
    // 0x80800658: nop

L_8080065C:
    // 0x8080065C: jal         0x800FC6B0
    // 0x80800660: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC6B0(rdram, ctx);
        goto after_0;
    // 0x80800660: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_0:
    // 0x80800664: jal         0x800FDC28
    // 0x80800668: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_1;
    // 0x80800668: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8080066C: b           L_808006A0
    // 0x80800670: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
        goto L_808006A0;
    // 0x80800670: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_80800674:
    // 0x80800674: jal         0x800FC6B0
    // 0x80800678: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800FC6B0(rdram, ctx);
        goto after_2;
    // 0x80800678: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_2:
    // 0x8080067C: jal         0x800FDC28
    // 0x80800680: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_3;
    // 0x80800680: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80800684: b           L_808006A0
    // 0x80800688: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
        goto L_808006A0;
    // 0x80800688: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_8080068C:
    // 0x8080068C: jal         0x800FC6B0
    // 0x80800690: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    func_800FC6B0(rdram, ctx);
        goto after_4;
    // 0x80800690: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_4:
    // 0x80800694: jal         0x800FDC28
    // 0x80800698: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_5;
    // 0x80800698: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
L_8080069C:
    // 0x8080069C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_808006A0:
    // 0x808006A0: addiu       $t1, $zero, 0x22
    ctx->r9 = ADD32(0, 0X22);
    // 0x808006A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808006A8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x808006AC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808006B0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808006B4: jal         0x8008A208
    // 0x808006B8: addiu       $a3, $t0, 0x4
    ctx->r7 = ADD32(ctx->r8, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808006B8: addiu       $a3, $t0, 0x4
    ctx->r7 = ADD32(ctx->r8, 0X4);
    after_6:
    // 0x808006BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006C4: jr          $ra
    // 0x808006C8: nop

    return;
    // 0x808006C8: nop

;}
