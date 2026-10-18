#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800A7AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7AD4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7AD8: addiu       $v0, $v0, 0x7630
    ctx->r2 = ADD32(ctx->r2, 0X7630);
    // 0x800A7ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7AE4: sb          $a0, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r4;
    // 0x800A7AE8: beq         $a0, $zero, L_800A7B08
    if (ctx->r4 == 0) {
        // 0x800A7AEC: sb          $a1, 0x17($v0)
        MEM_B(0X17, ctx->r2) = ctx->r5;
            goto L_800A7B08;
    }
    // 0x800A7AEC: sb          $a1, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r5;
    // 0x800A7AF0: jal         0x800C9510
    // 0x800A7AF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800C9510(rdram, ctx);
        goto after_0;
    // 0x800A7AF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A7AF8: bne         $v0, $zero, L_800A7B08
    if (ctx->r2 != 0) {
        // 0x800A7AFC: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_800A7B08;
    }
    // 0x800A7AFC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7B00: jal         0x800C964C
    // 0x800A7B04: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800C964C(rdram, ctx);
        goto after_1;
    // 0x800A7B04: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
L_800A7B08:
    // 0x800A7B08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7B0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7B10: jr          $ra
    // 0x800A7B14: nop

    return;
    // 0x800A7B14: nop

;}
RECOMP_FUNC void func_800F3930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3930: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F3934: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F3938: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F393C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800F3940: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800F3944: jal         0x800F38A8
    // 0x800F3948: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800F38A8(rdram, ctx);
        goto after_0;
    // 0x800F3948: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800F394C: jal         0x800F9184
    // 0x800F3950: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800F9184(rdram, ctx);
        goto after_1;
    // 0x800F3950: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x800F3954: beq         $v0, $zero, L_800F3964
    if (ctx->r2 == 0) {
        // 0x800F3958: nop
    
            goto L_800F3964;
    }
    // 0x800F3958: nop

    // 0x800F395C: b           L_800F3A64
    // 0x800F3960: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3A64;
    // 0x800F3960: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F3964:
    // 0x800F3964: jal         0x800F6774
    // 0x800F3968: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F6774(rdram, ctx);
        goto after_2;
    // 0x800F3968: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_2:
    // 0x800F396C: bne         $v0, $zero, L_800F397C
    if (ctx->r2 != 0) {
        // 0x800F3970: nop
    
            goto L_800F397C;
    }
    // 0x800F3970: nop

    // 0x800F3974: b           L_800F3A64
    // 0x800F3978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3A64;
    // 0x800F3978: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F397C:
    // 0x800F397C: jal         0x800F6CC8
    // 0x800F3980: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F6CC8(rdram, ctx);
        goto after_3;
    // 0x800F3980: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_3:
    // 0x800F3984: beq         $v0, $zero, L_800F3994
    if (ctx->r2 == 0) {
        // 0x800F3988: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800F3994;
    }
    // 0x800F3988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F398C: b           L_800F3A64
    // 0x800F3990: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3A64;
    // 0x800F3990: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F3994:
    // 0x800F3994: jal         0x8008EF3C
    // 0x800F3998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008EF3C(rdram, ctx);
        goto after_4;
    // 0x800F3998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800F399C: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800F39A0: bne         $v0, $at, L_800F39B0
    if (ctx->r2 != ctx->r1) {
        // 0x800F39A4: nop
    
            goto L_800F39B0;
    }
    // 0x800F39A4: nop

    // 0x800F39A8: b           L_800F3A64
    // 0x800F39AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3A64;
    // 0x800F39AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F39B0:
    // 0x800F39B0: jal         0x8008E078
    // 0x800F39B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_5;
    // 0x800F39B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800F39B8: bne         $v0, $zero, L_800F39D0
    if (ctx->r2 != 0) {
        // 0x800F39BC: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_800F39D0;
    }
    // 0x800F39BC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800F39C0: bnel        $t6, $zero, L_800F39D4
    if (ctx->r14 != 0) {
        // 0x800F39C4: lui         $a1, 0x1
        ctx->r5 = S32(0X1 << 16);
            goto L_800F39D4;
    }
    goto skip_0;
    // 0x800F39C4: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    skip_0:
    // 0x800F39C8: b           L_800F3A64
    // 0x800F39CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3A64;
    // 0x800F39CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F39D0:
    // 0x800F39D0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
L_800F39D4:
    // 0x800F39D4: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x800F39D8: jal         0x800F64A4
    // 0x800F39DC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F64A4(rdram, ctx);
        goto after_6;
    // 0x800F39DC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_6:
    // 0x800F39E0: beq         $v0, $zero, L_800F39F0
    if (ctx->r2 == 0) {
        // 0x800F39E4: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_800F39F0;
    }
    // 0x800F39E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800F39E8: b           L_800F3A64
    // 0x800F39EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3A64;
    // 0x800F39EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F39F0:
    // 0x800F39F0: jal         0x800F64A4
    // 0x800F39F4: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800F64A4(rdram, ctx);
        goto after_7;
    // 0x800F39F4: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_7:
    // 0x800F39F8: bne         $v0, $zero, L_800F3A08
    if (ctx->r2 != 0) {
        // 0x800F39FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800F3A08;
    }
    // 0x800F39FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F3A00: b           L_800F3A64
    // 0x800F3A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3A64;
    // 0x800F3A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F3A08:
    // 0x800F3A08: jal         0x80095738
    // 0x800F3A0C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    baflag_isTrue(rdram, ctx);
        goto after_8;
    // 0x800F3A0C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_8:
    // 0x800F3A10: beq         $v0, $zero, L_800F3A20
    if (ctx->r2 == 0) {
        // 0x800F3A14: nop
    
            goto L_800F3A20;
    }
    // 0x800F3A14: nop

    // 0x800F3A18: b           L_800F3A64
    // 0x800F3A1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3A64;
    // 0x800F3A1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F3A20:
    // 0x800F3A20: jal         0x8009E6F8
    // 0x800F3A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_9;
    // 0x800F3A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800F3A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F3A2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800F3A30: jal         0x8009CA70
    // 0x800F3A34: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    func_8009CA70(rdram, ctx);
        goto after_10;
    // 0x800F3A34: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_10:
    // 0x800F3A38: beq         $v0, $zero, L_800F3A48
    if (ctx->r2 == 0) {
        // 0x800F3A3C: nop
    
            goto L_800F3A48;
    }
    // 0x800F3A3C: nop

    // 0x800F3A40: b           L_800F3A64
    // 0x800F3A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3A64;
    // 0x800F3A44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F3A48:
    // 0x800F3A48: jal         0x800A9C98
    // 0x800F3A4C: nop

    func_800A9C98(rdram, ctx);
        goto after_11;
    // 0x800F3A4C: nop

    after_11:
    // 0x800F3A50: beql        $v0, $zero, L_800F3A64
    if (ctx->r2 == 0) {
        // 0x800F3A54: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F3A64;
    }
    goto skip_1;
    // 0x800F3A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x800F3A58: b           L_800F3A64
    // 0x800F3A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3A64;
    // 0x800F3A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F3A60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F3A64:
    // 0x800F3A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F3A68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F3A6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F3A70: jr          $ra
    // 0x800F3A74: nop

    return;
    // 0x800F3A74: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A178: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A178);
    return;
    // 0x8008A17C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void memcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032AD8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80032ADC: beq         $a2, $zero, L_80032AFC
    if (ctx->r6 == 0) {
        // 0x80032AE0: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80032AFC;
    }
    // 0x80032AE0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80032AE4:
    // 0x80032AE4: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80032AE8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80032AEC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80032AF0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80032AF4: bne         $a2, $zero, L_80032AE4
    if (ctx->r6 != 0) {
        // 0x80032AF8: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_80032AE4;
    }
    // 0x80032AF8: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_80032AFC:
    // 0x80032AFC: jr          $ra
    // 0x80032B00: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80032B00: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_80800B5C_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B68: jal         0x8080009C
    // 0x80800B6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8080009C_chcollballcontrol(rdram, ctx);
        goto after_0;
    // 0x80800B6C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800B70: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800B74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4B88) << 16);
    // 0x80800B78: lwc1        $f12, 0x4B88($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4B88));
    // 0x80800B7C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4B8C) << 16);
    // 0x80800B80: jal         0x800DC178
    // 0x80800B84: lwc1        $f14, 0x4B8C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4B8C));
    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800B84: lwc1        $f14, 0x4B8C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4B8C));
    after_1:
    // 0x80800B88: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800B8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800B90: nop

    // 0x80800B94: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800B98: jal         0x800DC0C0
    // 0x80800B9C: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x80800B9C: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x80800BA0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800BA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BAC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80800BB0: nop

    // 0x80800BB4: bc1f        L_80800BC8
    if (!c1cs) {
        // 0x80800BB8: nop
    
            goto L_80800BC8;
    }
    // 0x80800BB8: nop

    // 0x80800BBC: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80800BC0: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80800BC4: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
L_80800BC8:
    // 0x80800BC8: jal         0x8080324C
    // 0x80800BCC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8080324C_chcollballcontrol(rdram, ctx);
        goto after_3;
    // 0x80800BCC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_3:
    // 0x80800BD0: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800BD4: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800BD8: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BE8: jr          $ra
    // 0x80800BEC: nop

    return;
    // 0x80800BEC: nop

;}
RECOMP_FUNC void func_800F40EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F40EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F40F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F40F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F40F8: jal         0x8009E6F8
    // 0x800F40FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800F40FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800F4100: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800F4104: jal         0x800A3274
    // 0x800F4108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3274(rdram, ctx);
        goto after_1;
    // 0x800F4108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800F410C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800F4110: bnel        $v0, $at, L_800F4170
    if (ctx->r2 != ctx->r1) {
        // 0x800F4114: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800F4170;
    }
    goto skip_0;
    // 0x800F4114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800F4118: jal         0x80096544
    // 0x800F411C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096544(rdram, ctx);
        goto after_2;
    // 0x800F411C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800F4120: bne         $v0, $zero, L_800F4130
    if (ctx->r2 != 0) {
        // 0x800F4124: nop
    
            goto L_800F4130;
    }
    // 0x800F4124: nop

    // 0x800F4128: b           L_800F41EC
    // 0x800F412C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F41EC;
    // 0x800F412C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F4130:
    // 0x800F4130: jal         0x800964DC
    // 0x800F4134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800964DC(rdram, ctx);
        goto after_3;
    // 0x800F4134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800F4138: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800F413C: jal         0x80096364
    // 0x800F4140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80096364(rdram, ctx);
        goto after_4;
    // 0x800F4140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800F4144: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F4148: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800F414C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800F4150: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800F4154: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800F4158: nop

    // 0x800F415C: bc1fl       L_800F4170
    if (!c1cs) {
        // 0x800F4160: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800F4170;
    }
    goto skip_1;
    // 0x800F4160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x800F4164: b           L_800F41EC
    // 0x800F4168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F41EC;
    // 0x800F4168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F416C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800F4170:
    // 0x800F4170: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800F4174: jal         0x8009CA70
    // 0x800F4178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009CA70(rdram, ctx);
        goto after_5;
    // 0x800F4178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800F417C: bne         $v0, $zero, L_800F4198
    if (ctx->r2 != 0) {
        // 0x800F4180: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800F4198;
    }
    // 0x800F4180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F4184: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800F4188: jal         0x8009CA70
    // 0x800F418C: lui         $a2, 0x4
    ctx->r6 = S32(0X4 << 16);
    func_8009CA70(rdram, ctx);
        goto after_6;
    // 0x800F418C: lui         $a2, 0x4
    ctx->r6 = S32(0X4 << 16);
    after_6:
    // 0x800F4190: beq         $v0, $zero, L_800F41A0
    if (ctx->r2 == 0) {
        // 0x800F4194: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_800F41A0;
    }
    // 0x800F4194: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
L_800F4198:
    // 0x800F4198: b           L_800F41EC
    // 0x800F419C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F41EC;
    // 0x800F419C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F41A0:
    // 0x800F41A0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800F41A4: bne         $t6, $at, L_800F41CC
    if (ctx->r14 != ctx->r1) {
        // 0x800F41A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800F41CC;
    }
    // 0x800F41A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F41AC: jal         0x800832B0
    // 0x800F41B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bsjump_entrypoint_16(rdram, ctx);
        goto after_7;
    // 0x800F41B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800F41B4: beq         $v0, $zero, L_800F41C4
    if (ctx->r2 == 0) {
        // 0x800F41B8: nop
    
            goto L_800F41C4;
    }
    // 0x800F41B8: nop

    // 0x800F41BC: b           L_800F41EC
    // 0x800F41C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F41EC;
    // 0x800F41C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F41C4:
    // 0x800F41C4: b           L_800F41EC
    // 0x800F41C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F41EC;
    // 0x800F41C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F41CC:
    // 0x800F41CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800F41D0: jal         0x8009CA70
    // 0x800F41D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8009CA70(rdram, ctx);
        goto after_8;
    // 0x800F41D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
    // 0x800F41D8: beql        $v0, $zero, L_800F41EC
    if (ctx->r2 == 0) {
        // 0x800F41DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F41EC;
    }
    goto skip_2;
    // 0x800F41DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800F41E0: b           L_800F41EC
    // 0x800F41E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800F41EC;
    // 0x800F41E4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800F41E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F41EC:
    // 0x800F41EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F41F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F41F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F41F8: jr          $ra
    // 0x800F41FC: nop

    return;
    // 0x800F41FC: nop

;}
RECOMP_FUNC void _gcboundDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EE8: syscall     661
    recomp_syscall_handler(rdram, ctx, 0x80087EE8);
    return;
    // 0x80087EEC: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800CBA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBA68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CBA6C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800CBA70: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800CBA74: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800CBA78: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800CBA7C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800CBA80: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800CBA84: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800CBA88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800CBA8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CBA90: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800CBA94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CBA98: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800CBA9C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800CBAA0: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    // 0x800CBAA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800CBAA8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800CBAAC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x800CBAB0: jal         0x80087ED0
    // 0x800CBAB4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    _gcboundDll_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800CBAB4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x800CBAB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CBABC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CBAC0: jr          $ra
    // 0x800CBAC4: nop

    return;
    // 0x800CBAC4: nop

;}
RECOMP_FUNC void _ncpoducam_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089648: syscall     785
    recomp_syscall_handler(rdram, ctx, 0x80089648);
    return;
    // 0x8008964C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80802000_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802008: jal         0x800845D0
    // 0x8080200C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080200C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802010: jal         0x80800E54
    // 0x80802014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstnt_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80802014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80802018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080201C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802020: jr          $ra
    // 0x80802024: nop

    return;
    // 0x80802024: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080039C: jr          $ra
    // 0x808003A0: nop

    return;
    // 0x808003A0: nop

;}
RECOMP_FUNC void is_prev_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BB58: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x8001BB5C: lw          $t6, -0x390C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X390C);
    // 0x8001BB60: bnel        $a0, $t6, L_8001BB74
    if (ctx->r4 != ctx->r14) {
        // 0x8001BB64: lw          $t7, -0x10($a0)
        ctx->r15 = MEM_W(ctx->r4, -0X10);
            goto L_8001BB74;
    }
    goto skip_0;
    // 0x8001BB64: lw          $t7, -0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, -0X10);
    skip_0:
    // 0x8001BB68: jr          $ra
    // 0x8001BB6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001BB6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BB70: lw          $t7, -0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, -0X10);
L_8001BB74:
    // 0x8001BB74: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001BB78: lbu         $t8, 0xF($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XF);
    // 0x8001BB7C: srl         $t9, $t8, 6
    ctx->r25 = S32(U32(ctx->r24) >> 6);
    // 0x8001BB80: beq         $t9, $zero, L_8001BB90
    if (ctx->r25 == 0) {
        // 0x8001BB84: nop
    
            goto L_8001BB90;
    }
    // 0x8001BB84: nop

    // 0x8001BB88: b           L_8001BB90
    // 0x8001BB8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8001BB90;
    // 0x8001BB8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001BB90:
    // 0x8001BB90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001BB94: jr          $ra
    // 0x8001BB98: nop

    return;
    // 0x8001BB98: nop

;}
RECOMP_FUNC void func_80802C10_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802C14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C18: jal         0x80106790
    // 0x80802C1C: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802C1C: nop

    after_0:
    // 0x80802C20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802C24: jal         0x80100094
    // 0x80802C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80802C2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802C30: jal         0x80087DC8
    // 0x80802C34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_38(rdram, ctx);
        goto after_2;
    // 0x80802C34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80802C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802C3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802C40: jr          $ra
    // 0x80802C44: nop

    return;
    // 0x80802C44: nop

;}
RECOMP_FUNC void func_800A2E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2E18: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A2E1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A2E20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A2E24: jal         0x8009E6F8
    // 0x800A2E28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getCurrentState(rdram, ctx);
        goto after_0;
    // 0x800A2E28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800A2E2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800A2E30: jal         0x800A2C84
    // 0x800A2E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2C84(rdram, ctx);
        goto after_1;
    // 0x800A2E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A2E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2E3C: jal         0x8009CBDC
    // 0x800A2E40: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009CBDC(rdram, ctx);
        goto after_2;
    // 0x800A2E40: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x800A2E44: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A2E48: beq         $v0, $at, L_800A2E64
    if (ctx->r2 == ctx->r1) {
        // 0x800A2E4C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A2E64;
    }
    // 0x800A2E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A2E50: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A2E54: jal         0x8009CA70
    // 0x800A2E58: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8009CA70(rdram, ctx);
        goto after_3;
    // 0x800A2E58: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_3:
    // 0x800A2E5C: beql        $v0, $zero, L_800A2E88
    if (ctx->r2 == 0) {
        // 0x800A2E60: lw          $v0, 0x124($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X124);
            goto L_800A2E88;
    }
    goto skip_0;
    // 0x800A2E60: lw          $v0, 0x124($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X124);
    skip_0:
L_800A2E64:
    // 0x800A2E64: lw          $v0, 0x124($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X124);
    // 0x800A2E68: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800A2E6C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800A2E70: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A2E74: jal         0x80088A20
    // 0x800A2E78: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    _fxstep_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x800A2E78: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    after_4:
    // 0x800A2E7C: b           L_800A2E9C
    // 0x800A2E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A2E9C;
    // 0x800A2E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2E84: lw          $v0, 0x124($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X124);
L_800A2E88:
    // 0x800A2E88: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800A2E8C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A2E90: jal         0x80088A20
    // 0x800A2E94: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    _fxstep_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x800A2E94: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    after_5:
    // 0x800A2E98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A2E9C:
    // 0x800A2E9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A2EA0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A2EA4: jr          $ra
    // 0x800A2EA8: nop

    return;
    // 0x800A2EA8: nop

;}
RECOMP_FUNC void _glid_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088680: syscall     697
    recomp_syscall_handler(rdram, ctx, 0x80088680);
    return;
    // 0x80088684: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bafly_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C30: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C30);
    return;
    // 0x80084C34: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void _subaddiefade_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CE8: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089CE8);
    return;
    // 0x80089CEC: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _chweldarbossfireball_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086628: syscall     350
    recomp_syscall_handler(rdram, ctx, 0x80086628);
    return;
    // 0x8008662C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800070_chfactoryprop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800070: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800078: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080007C: jal         0x800D8FF8
    // 0x80800080: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800080: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800084: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800088: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8080008C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800090: nop

    // 0x80800094: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800098: nop

    // 0x8080009C: bc1f        L_808000DC
    if (!c1cs) {
        // 0x808000A0: nop
    
            goto L_808000DC;
    }
    // 0x808000A0: nop

    // 0x808000A4: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x808000A8: addiu       $at, $zero, 0x3B2
    ctx->r1 = ADD32(0, 0X3B2);
    // 0x808000AC: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x808000B0: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x808000B4: bne         $t8, $at, L_808000CC
    if (ctx->r24 != ctx->r1) {
        // 0x808000B8: nop
    
            goto L_808000CC;
    }
    // 0x808000B8: nop

    // 0x808000BC: jal         0x80800674
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800674_chfactoryprop(rdram, ctx);
        goto after_1;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000C4: b           L_808000E8
    // 0x808000C8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_808000E8;
    // 0x808000C8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_808000CC:
    // 0x808000CC: jal         0x80800988
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800988_chfactoryprop(rdram, ctx);
        goto after_2;
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000D4: b           L_808000E8
    // 0x808000D8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
        goto L_808000E8;
    // 0x808000D8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_808000DC:
    // 0x808000DC: jal         0x80089D40
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808000E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000E4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_808000E8:
    // 0x808000E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000EC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808000F0: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x808000F4: beq         $t9, $at, L_8080010C
    if (ctx->r25 == ctx->r1) {
        // 0x808000F8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080010C;
    }
    // 0x808000F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000FC: beq         $t9, $at, L_80800134
    if (ctx->r25 == ctx->r1) {
        // 0x80800100: lwc1        $f6, 0x24($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80800134;
    }
    // 0x80800100: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800104: b           L_80800194
    // 0x80800108: nop

        goto L_80800194;
    // 0x80800108: nop

L_8080010C:
    // 0x8080010C: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800110: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800114: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800118: jal         0x800136E4
    // 0x8080011C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x8080011C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_4:
    // 0x80800120: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80800124: jal         0x80800324
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800324_chfactoryprop(rdram, ctx);
        goto after_5;
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080012C: b           L_80800194
    // 0x80800130: nop

        goto L_80800194;
    // 0x80800130: nop

L_80800134:
    // 0x80800134: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800138: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080013C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800140: lwc1        $f12, 0x28($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800144: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800148: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8080014C: jal         0x800F15F8
    // 0x80800150: nop

    func_800F15F8(rdram, ctx);
        goto after_6;
    // 0x80800150: nop

    after_6:
    // 0x80800154: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800158: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080015C: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800160: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800164: jal         0x800136E4
    // 0x80800168: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    func_800136E4(rdram, ctx);
        goto after_7;
    // 0x80800168: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_7:
    // 0x8080016C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800170: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800174: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080017C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80800180: nop

    // 0x80800184: bc1f        L_80800194
    if (!c1cs) {
        // 0x80800188: nop
    
            goto L_80800194;
    }
    // 0x80800188: nop

    // 0x8080018C: jal         0x80101FDC
    // 0x80800190: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x80800190: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
L_80800194:
    // 0x80800194: jal         0x801065A4
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801065A4(rdram, ctx);
        goto after_9;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080019C: beql        $v0, $zero, L_808001C8
    if (ctx->r2 == 0) {
        // 0x808001A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001C8;
    }
    goto skip_0;
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808001A4: jal         0x801065A4
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801065A4(rdram, ctx);
        goto after_10;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001AC: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808001B0: addiu       $a2, $a2, 0x61D0
    ctx->r6 = ADD32(ctx->r6, 0X61D0);
    // 0x808001B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001BC: jal         0x80088660
    // 0x808001C0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x808001C0: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    after_11:
    // 0x808001C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001C8:
    // 0x808001C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001D0: jr          $ra
    // 0x808001D4: nop

    return;
    // 0x808001D4: nop

;}
RECOMP_FUNC void _chskeletonexplode_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E10: syscall     459
    recomp_syscall_handler(rdram, ctx, 0x80086E10);
    return;
    // 0x80086E14: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void baphysics_set_horizontal_velocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BA68: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8009BA6C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8009BA70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BA74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BA78: lw          $a0, 0xC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC8);
    // 0x8009BA7C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8009BA80: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8009BA84: jal         0x800EEB9C
    // 0x8009BA88: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EEB9C(rdram, ctx);
        goto after_0;
    // 0x8009BA88: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x8009BA8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BA90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BA94: jr          $ra
    // 0x8009BA98: nop

    return;
    // 0x8009BA98: nop

;}
RECOMP_FUNC void sumole_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800454: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800458: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080045C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800460: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800464: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800468: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_8080046C:
    // 0x8080046C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_80800470:
    // 0x80800470: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800474: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800478: sltiu       $at, $t8, 0x16
    ctx->r1 = ctx->r24 < 0X16 ? 1 : 0;
    // 0x8080047C: beq         $at, $zero, L_80800500
    if (ctx->r1 == 0) {
        // 0x80800480: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800500;
    }
    // 0x80800480: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800484: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3158, 0X2240) << 16);
    // 0x80800488: addu        $at, $at, $t8
    gpr jr_addend_80800490 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8080048C: lw          $t8, 0x2240($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3158, 0X2240));
    // 0x80800490: jr          $t8
    // 0x80800494: nop

    switch (jr_addend_80800490 >> 2) {
        case 0: goto L_80800498; break;
        case 1: goto L_80800500; break;
        case 2: goto L_808004D8; break;
        case 3: goto L_80800500; break;
        case 4: goto L_80800500; break;
        case 5: goto L_80800500; break;
        case 6: goto L_808004B4; break;
        case 7: goto L_808004F4; break;
        case 8: goto L_80800500; break;
        case 9: goto L_80800500; break;
        case 10: goto L_80800500; break;
        case 11: goto L_80800500; break;
        case 12: goto L_80800500; break;
        case 13: goto L_80800500; break;
        case 14: goto L_80800500; break;
        case 15: goto L_80800500; break;
        case 16: goto L_80800500; break;
        case 17: goto L_80800500; break;
        case 18: goto L_80800500; break;
        case 19: goto L_80800500; break;
        case 20: goto L_80800500; break;
        case 21: goto L_808004B4; break;
        default: switch_error(__func__, 0x80800490, 0x80802240);
    }
    // 0x80800494: nop

L_80800498:
    // 0x80800498: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8080049C: beql        $s1, $at, L_80800504
    if (ctx->r17 == ctx->r1) {
        // 0x808004A0: lbu         $t2, 0x72($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X72);
            goto L_80800504;
    }
    goto skip_0;
    // 0x808004A0: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
    skip_0:
    // 0x808004A4: jal         0x800C78CC
    // 0x808004A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C78CC(rdram, ctx);
        goto after_0;
    // 0x808004A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x808004AC: b           L_80800504
    // 0x808004B0: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
        goto L_80800504;
    // 0x808004B0: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
L_808004B4:
    // 0x808004B4: jal         0x800DA544
    // 0x808004B8: addiu       $a0, $zero, 0x9F1
    ctx->r4 = ADD32(0, 0X9F1);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x808004B8: addiu       $a0, $zero, 0x9F1
    ctx->r4 = ADD32(0, 0X9F1);
    after_1:
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808004C8: jal         0x808002E0
    // 0x808004CC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_808002E0_sumole(rdram, ctx);
        goto after_2;
    // 0x808004CC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x808004D0: b           L_80800504
    // 0x808004D4: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
        goto L_80800504;
    // 0x808004D4: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
L_808004D8:
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004E4: jal         0x808002E0
    // 0x808004E8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_808002E0_sumole(rdram, ctx);
        goto after_3;
    // 0x808004E8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x808004EC: b           L_80800504
    // 0x808004F0: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
        goto L_80800504;
    // 0x808004F0: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
L_808004F4:
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: jal         0x80801D3C
    // 0x808004FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    sumole_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x808004FC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
L_80800500:
    // 0x80800500: lbu         $t2, 0x72($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X72);
L_80800504:
    // 0x80800504: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80800508: andi        $t3, $t2, 0xFF03
    ctx->r11 = ctx->r10 & 0XFF03;
    // 0x8080050C: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800510: sb          $t4, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r12;
    // 0x80800514: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
    // 0x80800518: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x8080051C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800520: sltiu       $at, $t7, 0x14
    ctx->r1 = ctx->r15 < 0X14 ? 1 : 0;
    // 0x80800524: beq         $at, $zero, L_808006FC
    if (ctx->r1 == 0) {
        // 0x80800528: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808006FC;
    }
    // 0x80800528: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080052C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3158, 0X2298) << 16);
    // 0x80800530: addu        $at, $at, $t7
    gpr jr_addend_80800538 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800534: lw          $t7, 0x2298($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3158, 0X2298));
    // 0x80800538: jr          $t7
    // 0x8080053C: nop

    switch (jr_addend_80800538 >> 2) {
        case 0: goto L_808006C0; break;
        case 1: goto L_808006FC; break;
        case 2: goto L_8080055C; break;
        case 3: goto L_808006FC; break;
        case 4: goto L_808006FC; break;
        case 5: goto L_808006FC; break;
        case 6: goto L_808005BC; break;
        case 7: goto L_808006FC; break;
        case 8: goto L_808006FC; break;
        case 9: goto L_808006FC; break;
        case 10: goto L_808005DC; break;
        case 11: goto L_808006FC; break;
        case 12: goto L_80800540; break;
        case 13: goto L_8080058C; break;
        case 14: goto L_808006FC; break;
        case 15: goto L_808006FC; break;
        case 16: goto L_80800600; break;
        case 17: goto L_808006FC; break;
        case 18: goto L_808006FC; break;
        case 19: goto L_80800664; break;
        default: switch_error(__func__, 0x80800538, 0x80802298);
    }
    // 0x8080053C: nop

L_80800540:
    // 0x80800540: jal         0x80106790
    // 0x80800544: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80800544: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_5:
    // 0x80800548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080054C: jal         0x80086918
    // 0x80800550: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    _chmolehill_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80800550: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_6:
    // 0x80800554: b           L_80800700
    // 0x80800558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800700;
    // 0x80800558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080055C:
    // 0x8080055C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800560: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800564: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800568: jal         0x808002E0
    // 0x8080056C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_808002E0_sumole(rdram, ctx);
        goto after_7;
    // 0x8080056C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x80800570: jal         0x808013F8
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sumole_entrypoint_7(rdram, ctx);
        goto after_8;
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080057C: jal         0x80801D3C
    // 0x80800580: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    sumole_entrypoint_19(rdram, ctx);
        goto after_9;
    // 0x80800580: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800584: b           L_80800700
    // 0x80800588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800700;
    // 0x80800588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080058C:
    // 0x8080058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800590: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800594: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800598: jal         0x808002E0
    // 0x8080059C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_808002E0_sumole(rdram, ctx);
        goto after_10;
    // 0x8080059C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x808005A0: jal         0x808014B0
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sumole_entrypoint_9(rdram, ctx);
        goto after_11;
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: jal         0x80801D3C
    // 0x808005B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    sumole_entrypoint_19(rdram, ctx);
        goto after_12;
    // 0x808005B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x808005B4: b           L_80800700
    // 0x808005B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800700;
    // 0x808005B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005BC:
    // 0x808005BC: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808005C0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808005C4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x808005C8: nop

    // 0x808005CC: bnel        $t9, $zero, L_80800700
    if (ctx->r25 != 0) {
        // 0x808005D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800700;
    }
    goto skip_1;
    // 0x808005D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808005D4: b           L_80800700
    // 0x808005D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800700;
    // 0x808005D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005DC:
    // 0x808005DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808005E8: jal         0x808002E0
    // 0x808005EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_808002E0_sumole(rdram, ctx);
        goto after_13;
    // 0x808005EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_13:
    // 0x808005F0: jal         0x808015CC
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sumole_entrypoint_13(rdram, ctx);
        goto after_14;
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808005F8: b           L_80800700
    // 0x808005FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800700;
    // 0x808005FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800600:
    // 0x80800600: jal         0x8008FC28
    // 0x80800604: nop

    func_8008FC28(rdram, ctx);
        goto after_15;
    // 0x80800604: nop

    after_15:
    // 0x80800608: jal         0x8008FC00
    // 0x8080060C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_8008FC00(rdram, ctx);
        goto after_16;
    // 0x8080060C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_16:
    // 0x80800610: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80800614: beq         $at, $zero, L_80800634
    if (ctx->r1 == 0) {
        // 0x80800618: addiu       $a0, $zero, 0x422
        ctx->r4 = ADD32(0, 0X422);
            goto L_80800634;
    }
    // 0x80800618: addiu       $a0, $zero, 0x422
    ctx->r4 = ADD32(0, 0X422);
    // 0x8080061C: jal         0x800DA9E4
    // 0x80800620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_17;
    // 0x80800620: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x80800624: beql        $v0, $zero, L_80800700
    if (ctx->r2 == 0) {
        // 0x80800628: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800700;
    }
    goto skip_2;
    // 0x80800628: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8080062C: b           L_8080046C
    // 0x80800630: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
        goto L_8080046C;
    // 0x80800630: addiu       $s1, $zero, 0x14
    ctx->r17 = ADD32(0, 0X14);
L_80800634:
    // 0x80800634: jal         0x80106790
    // 0x80800638: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_18;
    // 0x80800638: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_18:
    // 0x8080063C: jal         0x80086928
    // 0x80800640: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _chmolehill_entrypoint_3(rdram, ctx);
        goto after_19;
    // 0x80800640: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
    // 0x80800644: beq         $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x80800648: nop
    
            goto L_80800654;
    }
    // 0x80800648: nop

    // 0x8080064C: b           L_8080046C
    // 0x80800650: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
        goto L_8080046C;
    // 0x80800650: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
L_80800654:
    // 0x80800654: jal         0x800C0850
    // 0x80800658: addiu       $s1, $zero, 0x12
    ctx->r17 = ADD32(0, 0X12);
    func_800C0850(rdram, ctx);
        goto after_20;
    // 0x80800658: addiu       $s1, $zero, 0x12
    ctx->r17 = ADD32(0, 0X12);
    after_20:
    // 0x8080065C: b           L_80800470
    // 0x80800660: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
        goto L_80800470;
    // 0x80800660: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_80800664:
    // 0x80800664: jal         0x8008FC00
    // 0x80800668: nop

    func_8008FC00(rdram, ctx);
        goto after_21;
    // 0x80800668: nop

    after_21:
    // 0x8080066C: jal         0x8008FC28
    // 0x80800670: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_8008FC28(rdram, ctx);
        goto after_22;
    // 0x80800670: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_22:
    // 0x80800674: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800678: bne         $at, $zero, L_808006B0
    if (ctx->r1 != 0) {
        // 0x8080067C: nop
    
            goto L_808006B0;
    }
    // 0x8080067C: nop

    // 0x80800680: jal         0x80106790
    // 0x80800684: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_23;
    // 0x80800684: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_23:
    // 0x80800688: jal         0x80086928
    // 0x8080068C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _chmolehill_entrypoint_3(rdram, ctx);
        goto after_24;
    // 0x8080068C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_24:
    // 0x80800690: beq         $v0, $zero, L_808006A0
    if (ctx->r2 == 0) {
        // 0x80800694: nop
    
            goto L_808006A0;
    }
    // 0x80800694: nop

    // 0x80800698: b           L_8080046C
    // 0x8080069C: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
        goto L_8080046C;
    // 0x8080069C: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
L_808006A0:
    // 0x808006A0: jal         0x800C0850
    // 0x808006A4: addiu       $s1, $zero, 0x12
    ctx->r17 = ADD32(0, 0X12);
    func_800C0850(rdram, ctx);
        goto after_25;
    // 0x808006A4: addiu       $s1, $zero, 0x12
    ctx->r17 = ADD32(0, 0X12);
    after_25:
    // 0x808006A8: b           L_80800470
    // 0x808006AC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
        goto L_80800470;
    // 0x808006AC: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
L_808006B0:
    // 0x808006B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3158, 0X22E8) << 16);
    // 0x808006B4: lwc1        $f8, 0x22E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3158, 0X22E8));
    // 0x808006B8: b           L_808006FC
    // 0x808006BC: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
        goto L_808006FC;
    // 0x808006BC: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
L_808006C0:
    // 0x808006C0: jal         0x800C78CC
    // 0x808006C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C78CC(rdram, ctx);
        goto after_26;
    // 0x808006C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x808006C8: jal         0x800DA524
    // 0x808006CC: addiu       $a0, $zero, 0x9F1
    ctx->r4 = ADD32(0, 0X9F1);
    func_800DA524(rdram, ctx);
        goto after_27;
    // 0x808006CC: addiu       $a0, $zero, 0x9F1
    ctx->r4 = ADD32(0, 0X9F1);
    after_27:
    // 0x808006D0: jal         0x80800408
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800408_sumole(rdram, ctx);
        goto after_28;
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808006D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006DC: jal         0x80801D3C
    // 0x808006E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sumole_entrypoint_19(rdram, ctx);
        goto after_29;
    // 0x808006E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x808006E4: lhu         $t0, 0x76($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X76);
    // 0x808006E8: srl         $t2, $t0, 7
    ctx->r10 = S32(U32(ctx->r8) >> 7);
    // 0x808006EC: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x808006F0: nop

    // 0x808006F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808006F8: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
L_808006FC:
    // 0x808006FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800700:
    // 0x80800700: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800704: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800708: jr          $ra
    // 0x8080070C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080070C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800D37F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D37F0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D37F4: jr          $ra
    // 0x800D37F8: lb          $v0, -0x4C0F($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4C0F);
    return;
    // 0x800D37F8: lb          $v0, -0x4C0F($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4C0F);
;}
RECOMP_FUNC void func_800BD600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BD604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BD608: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD60C: jal         0x8001BAFC
    // 0x800BD610: lw          $a0, -0x7BF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7BF0);
    defrag(rdram, ctx);
        goto after_0;
    // 0x800BD610: lw          $a0, -0x7BF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7BF0);
    after_0:
    // 0x800BD614: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BD618: addiu       $v1, $v1, -0x7BF0
    ctx->r3 = ADD32(ctx->r3, -0X7BF0);
    // 0x800BD61C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800BD620: jal         0x8001BAFC
    // 0x800BD624: lw          $a0, 0x44($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X44);
    defrag(rdram, ctx);
        goto after_1;
    // 0x800BD624: lw          $a0, 0x44($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X44);
    after_1:
    // 0x800BD628: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BD62C: jal         0x800E9DF8
    // 0x800BD630: sw          $v0, -0x7BAC($at)
    MEM_W(-0X7BAC, ctx->r1) = ctx->r2;
    func_800E9DF8(rdram, ctx);
        goto after_2;
    // 0x800BD630: sw          $v0, -0x7BAC($at)
    MEM_W(-0X7BAC, ctx->r1) = ctx->r2;
    after_2:
    // 0x800BD634: jal         0x800D2EE4
    // 0x800BD638: nop

    func_800D2EE4(rdram, ctx);
        goto after_3;
    // 0x800BD638: nop

    after_3:
    // 0x800BD63C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BD640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BD644: jr          $ra
    // 0x800BD648: nop

    return;
    // 0x800BD648: nop

;}
RECOMP_FUNC void func_800BECCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BECCC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BECD0: lw          $t6, -0x78CC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X78CC);
    // 0x800BECD4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800BECD8: jr          $ra
    // 0x800BECDC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    return;
    // 0x800BECDC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
;}
RECOMP_FUNC void func_800FE614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE614: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FE618: addiu       $a0, $a0, 0x59C0
    ctx->r4 = ADD32(ctx->r4, 0X59C0);
    // 0x800FE61C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800FE620: sb          $t6, 0x16($a0)
    MEM_B(0X16, ctx->r4) = ctx->r14;
    // 0x800FE624: sb          $zero, 0x17($a0)
    MEM_B(0X17, ctx->r4) = 0;
    // 0x800FE628: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FE62C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FE630: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800FE634: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE638: addiu       $v0, $t8, 0x59C0
    ctx->r2 = ADD32(ctx->r24, 0X59C0);
    // 0x800FE63C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FE640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FE644: sw          $t7, 0x5A40($at)
    MEM_W(0X5A40, ctx->r1) = ctx->r15;
    // 0x800FE648: addiu       $a0, $a0, 0x59C4
    ctx->r4 = ADD32(ctx->r4, 0X59C4);
    // 0x800FE64C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800FE650:
    // 0x800FE650: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800FE654: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800FE658: sb          $zero, 0x34($v1)
    MEM_B(0X34, ctx->r3) = 0;
    // 0x800FE65C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800FE660: bne         $at, $zero, L_800FE650
    if (ctx->r1 != 0) {
        // 0x800FE664: sh          $zero, 0x34($v0)
        MEM_H(0X34, ctx->r2) = 0;
            goto L_800FE650;
    }
    // 0x800FE664: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x800FE668: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FE66C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FE670: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FE674: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800FE678: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FE67C: addiu       $a1, $a1, 0x5A3F
    ctx->r5 = ADD32(ctx->r5, 0X5A3F);
    // 0x800FE680: addiu       $v0, $v0, 0x5A3C
    ctx->r2 = ADD32(ctx->r2, 0X5A3C);
    // 0x800FE684: addiu       $a0, $a0, 0x5A30
    ctx->r4 = ADD32(ctx->r4, 0X5A30);
    // 0x800FE688: addiu       $v1, $v1, 0x5A20
    ctx->r3 = ADD32(ctx->r3, 0X5A20);
L_800FE68C:
    // 0x800FE68C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800FE690: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800FE694: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800FE698: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800FE69C: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x800FE6A0: swc1        $f0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f0.u32l;
    // 0x800FE6A4: bne         $at, $zero, L_800FE68C
    if (ctx->r1 != 0) {
        // 0x800FE6A8: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_800FE68C;
    }
    // 0x800FE6A8: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x800FE6AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FE6B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800FE6B4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FE6B8: addiu       $v1, $v1, 0x5A1E
    ctx->r3 = ADD32(ctx->r3, 0X5A1E);
    // 0x800FE6BC: addiu       $v0, $v0, 0x5A12
    ctx->r2 = ADD32(ctx->r2, 0X5A12);
    // 0x800FE6C0: sb          $zero, 0x5A10($at)
    MEM_B(0X5A10, ctx->r1) = 0;
    // 0x800FE6C4: sb          $zero, 0x5A11($at)
    MEM_B(0X5A11, ctx->r1) = 0;
L_800FE6C8:
    // 0x800FE6C8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800FE6CC: sb          $zero, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = 0;
    // 0x800FE6D0: sb          $zero, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = 0;
    // 0x800FE6D4: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x800FE6D8: bne         $v0, $v1, L_800FE6C8
    if (ctx->r2 != ctx->r3) {
        // 0x800FE6DC: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_800FE6C8;
    }
    // 0x800FE6DC: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x800FE6E0: jal         0x800FDC28
    // 0x800FE6E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_0;
    // 0x800FE6E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800FE6E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FE6EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FE6F0: jr          $ra
    // 0x800FE6F4: nop

    return;
    // 0x800FE6F4: nop

;}
RECOMP_FUNC void _glsavegame_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088558: syscall     692
    recomp_syscall_handler(rdram, ctx, 0x80088558);
    return;
    // 0x8008855C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_8009333C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009333C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80093340: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093344: lw          $a0, 0x50($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X50);
    // 0x80093348: jal         0x800EE7F8
    // 0x8009334C: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009334C: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    after_0:
    // 0x80093350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80093354: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80093358: jr          $ra
    // 0x8009335C: nop

    return;
    // 0x8009335C: nop

;}
RECOMP_FUNC void func_80803224_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803224: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803228: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080322C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80803230: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80803234: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80803238: jal         0x80100094
    // 0x8080323C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080323C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803240: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80803244: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80803248: jal         0x80100094
    // 0x8080324C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080324C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80803250: jal         0x80087CA8
    // 0x80803254: addiu       $s0, $v0, 0x10C
    ctx->r16 = ADD32(ctx->r2, 0X10C);
    _gcnewoption_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80803254: addiu       $s0, $v0, 0x10C
    ctx->r16 = ADD32(ctx->r2, 0X10C);
    after_2:
    // 0x80803258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080325C: jal         0x8002D6E0
    // 0x80803260: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _bzero(rdram, ctx);
        goto after_3;
    // 0x80803260: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80803264: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80803268: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8080326C: lhu         $a3, 0x44($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X44);
    // 0x80803270: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80803274: addiu       $a1, $a1, 0x7DB0
    ctx->r5 = ADD32(ctx->r5, 0X7DB0);
    // 0x80803278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080327C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80803280: jal         0x80087CC0
    // 0x80803284: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _gcnewoption_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80803284: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_4:
    // 0x80803288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080328C: jal         0x80087CD8
    // 0x80803290: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80803290: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80803294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803298: jal         0x80087CE0
    // 0x8080329C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x8080329C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x808032A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808032A4: jal         0x80087CE8
    // 0x808032A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x808032A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808032AC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808032B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808032B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808032B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808032BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808032C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808032C4: jal         0x80087D08
    // 0x808032C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _gcnewoption_entrypoint_14(rdram, ctx);
        goto after_8;
    // 0x808032C8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x808032CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808032D0: jal         0x80087D98
    // 0x808032D4: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    _gcnewoption_entrypoint_32(rdram, ctx);
        goto after_9;
    // 0x808032D4: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_9:
    // 0x808032D8: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(1480, 0X9F34) << 16);
    // 0x808032DC: addiu       $a1, $a1, -0x60CC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1480, 0X9F34));
    // 0x808032E0: jal         0x80087D88
    // 0x808032E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_30(rdram, ctx);
        goto after_10;
    // 0x808032E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808032E8: jal         0x80087D78
    // 0x808032EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_28(rdram, ctx);
        goto after_11;
    // 0x808032EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808032F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808032F4: jal         0x80087D80
    // 0x808032F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_29(rdram, ctx);
        goto after_12;
    // 0x808032F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x808032FC: jal         0x80087CF0
    // 0x80803300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x80803300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80803304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80803308: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8080330C: sb          $t8, 0x40($s1)
    MEM_B(0X40, ctx->r17) = ctx->r24;
    // 0x80803310: sb          $v0, 0x42($s1)
    MEM_B(0X42, ctx->r17) = ctx->r2;
    // 0x80803314: sb          $v0, 0x48($s1)
    MEM_B(0X48, ctx->r17) = ctx->r2;
    // 0x80803318: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080331C: jal         0x8010A828
    // 0x80803320: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8010A828(rdram, ctx);
        goto after_14;
    // 0x80803320: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_14:
    // 0x80803324: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80803328: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080332C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80803330: jr          $ra
    // 0x80803334: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80803334: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chhoney_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B70: syscall     424
    recomp_syscall_handler(rdram, ctx, 0x80086B70);
    return;
    // 0x80086B74: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _sucoasterdata_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A248: syscall     831
    recomp_syscall_handler(rdram, ctx, 0x8008A248);
    return;
    // 0x8008A24C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808013E0_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808013E4: lbu         $v1, 0x5C($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X5C);
    // 0x808013E8: xori        $v0, $v1, 0x3
    ctx->r2 = ctx->r3 ^ 0X3;
    // 0x808013EC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808013F0: bne         $v0, $zero, L_80801400
    if (ctx->r2 != 0) {
        // 0x808013F4: nop
    
            goto L_80801400;
    }
    // 0x808013F4: nop

    // 0x808013F8: xori        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 ^ 0X4;
    // 0x808013FC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_80801400:
    // 0x80801400: jr          $ra
    // 0x80801404: nop

    return;
    // 0x80801404: nop

;}
RECOMP_FUNC void func_8080290C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080290C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802910: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80802914: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80802918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080291C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80802920: jal         0x80802938
    // 0x80802924: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    func_80802938_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x80802924: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80802928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080292C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802930: jr          $ra
    // 0x80802934: nop

    return;
    // 0x80802934: nop

;}
RECOMP_FUNC void gcdialogcamera_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808001D8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808001DC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x808001E0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x808001E4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x808001E8: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x808001EC: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x808001F0: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x808001F4: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808001F8: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x808001FC: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x80800200: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80800204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800208: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8080020C: jal         0x800856E8
    // 0x80800210: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    _capod_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x80800210: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80800214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800218: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080021C: jr          $ra
    // 0x80800220: nop

    return;
    // 0x80800220: nop

;}
RECOMP_FUNC void func_80800D5C_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D5C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800D60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800D64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D6C: jal         0x800D9078
    // 0x80800D70: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800D70: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800D74: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800D78: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800D7C: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x80800D80: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800D84: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800D88: jal         0x800F10B4
    // 0x80800D8C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800D8C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x80800D90: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800D94: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800D98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800D9C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800DA0: jal         0x800EFE50
    // 0x80800DA4: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    func_800EFE50(rdram, ctx);
        goto after_2;
    // 0x80800DA4: addiu       $a2, $s0, 0x18
    ctx->r6 = ADD32(ctx->r16, 0X18);
    after_2:
    // 0x80800DA8: jal         0x80800E98
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800E98_chbiggafoot(rdram, ctx);
        goto after_3;
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800DB0: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800DB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800DB8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80800DBC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800DC0: bnel        $t7, $at, L_80800E1C
    if (ctx->r15 != ctx->r1) {
        // 0x80800DC4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800E1C;
    }
    goto skip_0;
    // 0x80800DC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800DC8: beq         $t8, $zero, L_80800E18
    if (ctx->r24 == 0) {
        // 0x80800DCC: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_80800E18;
    }
    // 0x80800DCC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800DD0: jal         0x800EE7F8
    // 0x80800DD4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800DD4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DDC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800DE0: jal         0x80086670
    // 0x80800DE4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800DE4: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_5:
    // 0x80800DE8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1216, 0X1238) << 16);
    // 0x80800DEC: addiu       $a2, $a2, 0x1238
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1216, 0X1238));
    // 0x80800DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DF4: jal         0x80089D18
    // 0x80800DF8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800DF8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80800DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E00: jal         0x80101FDC
    // 0x80800E04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800E04: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800E08: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800E0C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800E10: jal         0x8010114C
    // 0x80800E14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_8;
    // 0x80800E14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
L_80800E18:
    // 0x80800E18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E1C:
    // 0x80800E1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800E20: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800E24: jr          $ra
    // 0x80800E28: nop

    return;
    // 0x80800E28: nop

;}
RECOMP_FUNC void func_80801944_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801944: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80801948: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080194C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80801950: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80801954: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80801958: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8080195C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80801960: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80801964: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801968: jal         0x80100094
    // 0x8080196C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080196C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801970: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80801974: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80801978: jal         0x800D731C
    // 0x8080197C: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    func_800D731C(rdram, ctx);
        goto after_1;
    // 0x8080197C: lhu         $a0, 0x14($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X14);
    after_1:
    // 0x80801980: beq         $v0, $zero, L_80801994
    if (ctx->r2 == 0) {
        // 0x80801984: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_80801994;
    }
    // 0x80801984: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80801988: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080198C: jal         0x800DBE60
    // 0x80801990: lw          $a2, 0x84($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X84);
    func_800DBE60(rdram, ctx);
        goto after_2;
    // 0x80801990: lw          $a2, 0x84($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X84);
    after_2:
L_80801994:
    // 0x80801994: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801998: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x8080199C: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
L_808019A0:
    // 0x808019A0: addiu       $a0, $s0, 0x3
    ctx->r4 = ADD32(ctx->r16, 0X3);
    // 0x808019A4: jal         0x800DF744
    // 0x808019A8: lbu         $a1, 0x68($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X68);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x808019A8: lbu         $a1, 0x68($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X68);
    after_3:
    // 0x808019AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808019B0: bne         $s0, $s2, L_808019A0
    if (ctx->r16 != ctx->r18) {
        // 0x808019B4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808019A0;
    }
    // 0x808019B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808019B8: lbu         $t7, 0x6E($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X6E);
    // 0x808019BC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808019C0: beql        $t7, $zero, L_808019E0
    if (ctx->r15 == 0) {
        // 0x808019C4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_808019E0;
    }
    goto skip_0;
    // 0x808019C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x808019C8: jal         0x800EE7F8
    // 0x808019CC: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808019CC: addiu       $a1, $s3, 0x4
    ctx->r5 = ADD32(ctx->r19, 0X4);
    after_4:
    // 0x808019D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808019D4: jal         0x8008A4C8
    // 0x808019D8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    _subaddieDll_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x808019D8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_5:
    // 0x808019DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_808019E0:
    // 0x808019E0: jal         0x80101870
    // 0x808019E4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_80101870(rdram, ctx);
        goto after_6;
    // 0x808019E4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_6:
    // 0x808019E8: lbu         $t8, 0x6E($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X6E);
    // 0x808019EC: addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    // 0x808019F0: beql        $t8, $zero, L_80801A04
    if (ctx->r24 == 0) {
        // 0x808019F4: lw          $t9, 0x7C($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X7C);
            goto L_80801A04;
    }
    goto skip_1;
    // 0x808019F4: lw          $t9, 0x7C($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X7C);
    skip_1:
    // 0x808019F8: jal         0x800EE7F8
    // 0x808019FC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x808019FC: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_7:
    // 0x80801A00: lw          $t9, 0x7C($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X7C);
L_80801A04:
    // 0x80801A04: sll         $t1, $t9, 19
    ctx->r9 = S32(ctx->r25 << 19);
    // 0x80801A08: bgezl       $t1, L_80801A84
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80801A0C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80801A84;
    }
    goto skip_2;
    // 0x80801A0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80801A10: jal         0x8008A040
    // 0x80801A14: addiu       $a0, $s4, 0x30
    ctx->r4 = ADD32(ctx->r20, 0X30);
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80801A14: addiu       $a0, $s4, 0x30
    ctx->r4 = ADD32(ctx->r20, 0X30);
    after_8:
    // 0x80801A18: addiu       $s0, $s4, 0x44
    ctx->r16 = ADD32(ctx->r20, 0X44);
    // 0x80801A1C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80801A20: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80801A24: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80801A28: jal         0x8008A0E0
    // 0x80801A2C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80801A2C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x80801A30: addiu       $s2, $s4, 0x50
    ctx->r18 = ADD32(ctx->r20, 0X50);
    // 0x80801A34: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80801A38: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80801A3C: jal         0x8008A0E0
    // 0x80801A40: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80801A40: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_10:
    // 0x80801A44: beq         $s1, $zero, L_80801A80
    if (ctx->r17 == 0) {
        // 0x80801A48: addiu       $a0, $s1, 0x4
        ctx->r4 = ADD32(ctx->r17, 0X4);
            goto L_80801A80;
    }
    // 0x80801A48: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x80801A4C: jal         0x800EE7F8
    // 0x80801A50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x80801A50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_11:
    // 0x80801A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A58: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80801A5C: jal         0x800F18FC
    // 0x80801A60: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    func_800F18FC(rdram, ctx);
        goto after_12;
    // 0x80801A60: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    after_12:
    // 0x80801A64: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80801A68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801A6C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80801A70: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80801A74: swc1        $f8, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f8.u32l;
    // 0x80801A78: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80801A7C: swc1        $f10, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f10.u32l;
L_80801A80:
    // 0x80801A80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80801A84:
    // 0x80801A84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801A88: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801A8C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801A90: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80801A94: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80801A98: jr          $ra
    // 0x80801A9C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80801A9C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void __yaw_update_limited(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C750: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009C754: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009C758: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8009C75C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8009C760: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8009C764: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8009C768: jal         0x800D8FF8
    // 0x8009C76C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x8009C76C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x8009C770: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8009C774: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8009C778: lw          $s0, 0xF8($t6)
    ctx->r16 = MEM_W(ctx->r14, 0XF8);
    // 0x8009C77C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009C780: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8009C784: jal         0x80013728
    // 0x8009C788: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x8009C788: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x8009C78C: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8009C790: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8009C794: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8009C798: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8009C79C: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x8009C7A0: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x8009C7A4: bc1tl       L_8009C7F0
    if (c1cs) {
        // 0x8009C7A8: swc1        $f20, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
            goto L_8009C7F0;
    }
    goto skip_0;
    // 0x8009C7A8: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
    skip_0:
    // 0x8009C7AC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8009C7B0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8009C7B4: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8009C7B8: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009C7BC: bc1fl       L_8009C7E0
    if (!c1cs) {
        // 0x8009C7C0: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_8009C7E0;
    }
    goto skip_1;
    // 0x8009C7C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_1:
    // 0x8009C7C4: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8009C7C8: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x8009C7CC: jal         0x800F0D50
    // 0x8009C7D0: lui         $a2, 0xC040
    ctx->r6 = S32(0XC040 << 16);
    func_800F0D50(rdram, ctx);
        goto after_2;
    // 0x8009C7D0: lui         $a2, 0xC040
    ctx->r6 = S32(0XC040 << 16);
    after_2:
    // 0x8009C7D4: b           L_8009C7EC
    // 0x8009C7D8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_8009C7EC;
    // 0x8009C7D8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8009C7DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_8009C7E0:
    // 0x8009C7E0: jal         0x800F0D50
    // 0x8009C7E4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800F0D50(rdram, ctx);
        goto after_3;
    // 0x8009C7E4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8009C7E8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8009C7EC:
    // 0x8009C7EC: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
L_8009C7F0:
    // 0x8009C7F0: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8009C7F4: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009C7F8: mul.s       $f12, $f20, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8009C7FC: jal         0x800F212C
    // 0x8009C800: nop

    func_800F212C(rdram, ctx);
        goto after_4;
    // 0x8009C800: nop

    after_4:
    // 0x8009C804: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8009C808: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8009C80C: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x8009C810: jal         0x800136E4
    // 0x8009C814: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x8009C814: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x8009C818: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8009C81C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009C820: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8009C824: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8009C828: jr          $ra
    // 0x8009C82C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8009C82C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _ncbadive_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892A8: syscall     770
    recomp_syscall_handler(rdram, ctx, 0x800892A8);
    return;
    // 0x800892AC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void baeggcursor_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080013C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800140: jal         0x8080018C
    // 0x80800144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    baeggcursor_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080014C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800150: jr          $ra
    // 0x80800154: nop

    return;
    // 0x80800154: nop

;}
RECOMP_FUNC void func_808004B0_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808004BC: jal         0x800DA524
    // 0x808004C0: addiu       $a0, $zero, 0x6CD
    ctx->r4 = ADD32(0, 0X6CD);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x808004C0: addiu       $a0, $zero, 0x6CD
    ctx->r4 = ADD32(0, 0X6CD);
    after_0:
    // 0x808004C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004CC: jr          $ra
    // 0x808004D0: nop

    return;
    // 0x808004D0: nop

;}
RECOMP_FUNC void func_80020CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020CA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80020CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020CA8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80020CAC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80020CB0: jal         0x8002FEC0
    // 0x80020CB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80020CB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80020CB8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80020CBC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80020CC0: lw          $t6, 0x11D0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X11D0);
    // 0x80020CC4: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80020CC8: lbu         $t9, 0x3B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3B);
    // 0x80020CCC: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x80020CD0: lw          $t8, -0x15DC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X15DC);
    // 0x80020CD4: lhu         $t7, 0x3E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3E);
    // 0x80020CD8: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80020CDC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80020CE0: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x80020CE4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80020CE8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80020CEC: beq         $t2, $zero, L_80020D60
    if (ctx->r10 == 0) {
        // 0x80020CF0: nop
    
            goto L_80020D60;
    }
    // 0x80020CF0: nop

L_80020CF4:
    // 0x80020CF4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80020CF8: lbu         $t9, 0x3B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3B);
    // 0x80020CFC: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80020D00: lbu         $t5, 0x12($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X12);
    // 0x80020D04: andi        $t6, $t5, 0x1F
    ctx->r14 = ctx->r13 & 0X1F;
    // 0x80020D08: bne         $t6, $t9, L_80020D3C
    if (ctx->r14 != ctx->r25) {
        // 0x80020D0C: nop
    
            goto L_80020D3C;
    }
    // 0x80020D0C: nop

    // 0x80020D10: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x80020D14: sh          $t8, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r24;
    // 0x80020D18: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80020D1C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80020D20: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80020D24: lw          $a0, 0x11DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X11DC);
    // 0x80020D28: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80020D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80020D30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80020D34: jal         0x80026500
    // 0x80020D38: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_80026500(rdram, ctx);
        goto after_1;
    // 0x80020D38: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
L_80020D3C:
    // 0x80020D3C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80020D40: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80020D44: addiu       $t1, $t7, 0x1
    ctx->r9 = ADD32(ctx->r15, 0X1);
    // 0x80020D48: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80020D4C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80020D50: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80020D54: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80020D58: bne         $t4, $zero, L_80020CF4
    if (ctx->r12 != 0) {
        // 0x80020D5C: nop
    
            goto L_80020CF4;
    }
    // 0x80020D5C: nop

L_80020D60:
    // 0x80020D60: jal         0x8002FEC0
    // 0x80020D64: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x80020D64: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x80020D68: b           L_80020D70
    // 0x80020D6C: nop

        goto L_80020D70;
    // 0x80020D6C: nop

L_80020D70:
    // 0x80020D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020D74: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80020D78: jr          $ra
    // 0x80020D7C: nop

    return;
    // 0x80020D7C: nop

;}
RECOMP_FUNC void func_800E2478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E247C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E2480: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E2484: jal         0x800E24F8
    // 0x800E2488: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_800E24F8(rdram, ctx);
        goto after_0;
    // 0x800E2488: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x800E248C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E2490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E2494: jr          $ra
    // 0x800E2498: nop

    return;
    // 0x800E2498: nop

;}
RECOMP_FUNC void func_808000A0_ncba1p(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808000A4: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x808000A8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808000AC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x808000B0: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x808000B4: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x808000B8: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x808000BC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808000C0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808000C4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808000C8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808000CC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808000D0: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x808000D4: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808000D8: jal         0x800D9078
    // 0x808000DC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x808000DC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x808000E0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x808000E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000E8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808000EC: lwc1        $f4, 0x48($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X48);
    // 0x808000F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000F4: mul.s       $f0, $f4, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x808000F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000FC: jal         0x801163A0
    // 0x80800100: nop

    func_801163A0(rdram, ctx);
        goto after_1;
    // 0x80800100: nop

    after_1:
    // 0x80800104: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800108: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080010C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80800110: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800114: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800118: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
L_8080011C:
    // 0x8080011C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80800120: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800124: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x80800128: addu        $s0, $a1, $s1
    ctx->r16 = ADD32(ctx->r5, ctx->r17);
    // 0x8080012C: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80800130: lw          $a3, 0x30($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X30);
    // 0x80800134: lwc1        $f12, 0x48($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X48);
    // 0x80800138: jal         0x800F130C
    // 0x8080013C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F130C(rdram, ctx);
        goto after_2;
    // 0x8080013C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80800140: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80800144: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80800148: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x8080014C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80800150: addu        $s0, $t9, $s1
    ctx->r16 = ADD32(ctx->r25, ctx->r17);
    // 0x80800154: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800158: jal         0x800F1DCC
    // 0x8080015C: lwc1        $f14, 0x3C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3C);
    func_800F1DCC(rdram, ctx);
        goto after_3;
    // 0x8080015C: lwc1        $f14, 0x3C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3C);
    after_3:
    // 0x80800160: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80800164: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800168: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8080016C: lwc1        $f12, 0x48($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X48);
    // 0x80800170: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800174: jal         0x800F130C
    // 0x80800178: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800F130C(rdram, ctx);
        goto after_4;
    // 0x80800178: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_4:
    // 0x8080017C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80800180: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x80800184: lwc1        $f8, 0x3C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X3C);
    // 0x80800188: jal         0x800136E4
    // 0x8080018C: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x8080018C: add.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f8.fl;
    after_5:
    // 0x80800190: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80800194: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80800198: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8080019C: bne         $s1, $s3, L_8080011C
    if (ctx->r17 != ctx->r19) {
        // 0x808001A0: swc1        $f0, 0xC($t4)
        MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
            goto L_8080011C;
    }
    // 0x808001A0: swc1        $f0, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f0.u32l;
    // 0x808001A4: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x808001A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808001AC: lwc1        $f10, 0x48($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X48);
    // 0x808001B0: c.eq.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl == ctx->f10.fl;
    // 0x808001B4: nop

    // 0x808001B8: bc1fl       L_808001D0
    if (!c1cs) {
        // 0x808001BC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808001D0;
    }
    goto skip_0;
    // 0x808001BC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x808001C0: jal         0x80800620
    // 0x808001C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ncba1p_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x808001C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808001C8: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x808001CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_808001D0:
    // 0x808001D0: jal         0x80800008
    // 0x808001D4: addiu       $a2, $a1, 0x18
    ctx->r6 = ADD32(ctx->r5, 0X18);
    func_80800008_ncba1p(rdram, ctx);
        goto after_7;
    // 0x808001D4: addiu       $a2, $a1, 0x18
    ctx->r6 = ADD32(ctx->r5, 0X18);
    after_7:
    // 0x808001D8: beq         $v0, $zero, L_808001E8
    if (ctx->r2 == 0) {
        // 0x808001DC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808001E8;
    }
    // 0x808001DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808001E0: jal         0x8080004C
    // 0x808001E4: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    func_8080004C_ncba1p(rdram, ctx);
        goto after_8;
    // 0x808001E4: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    after_8:
L_808001E8:
    // 0x808001E8: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x808001EC: jal         0x800EE7F8
    // 0x808001F0: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x808001F0: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    after_9:
    // 0x808001F4: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x808001F8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808001FC: jal         0x800EE7F8
    // 0x80800200: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80800200: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_10:
    // 0x80800204: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80800208: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8080020C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800210: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800214: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800218: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8080021C: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80800220: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x80800224: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x80800228: jr          $ra
    // 0x8080022C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8080022C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800E6728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6728: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800E672C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800E6730: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800E6734: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800E6738: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800E673C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800E6740: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800E6744: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800E6748: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E674C: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800E6750: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E6754: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x800E6758: lw          $s2, 0x10($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X10);
    // 0x800E675C: lw          $s3, 0xC($a0)
    ctx->r19 = MEM_W(ctx->r4, 0XC);
    // 0x800E6760: lw          $s6, 0x14($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X14);
    // 0x800E6764: andi        $v0, $s2, 0x7
    ctx->r2 = ctx->r18 & 0X7;
    // 0x800E6768: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x800E676C: sltiu       $at, $s2, 0x10
    ctx->r1 = ctx->r18 < 0X10 ? 1 : 0;
    // 0x800E6770: beq         $at, $zero, L_800E67D4
    if (ctx->r1 == 0) {
        // 0x800E6774: srlv        $s3, $s3, $v0
        ctx->r19 = S32(U32(ctx->r19) >> (ctx->r2 & 31));
            goto L_800E67D4;
    }
    // 0x800E6774: srlv        $s3, $s3, $v0
    ctx->r19 = S32(U32(ctx->r19) >> (ctx->r2 & 31));
    // 0x800E6778: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
L_800E677C:
    // 0x800E677C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E6780: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E6784: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E6788: bnel        $at, $zero, L_800E67B4
    if (ctx->r1 != 0) {
        // 0x800E678C: addu        $t9, $s1, $v0
        ctx->r25 = ADD32(ctx->r17, ctx->r2);
            goto L_800E67B4;
    }
    goto skip_0;
    // 0x800E678C: addu        $t9, $s1, $v0
    ctx->r25 = ADD32(ctx->r17, ctx->r2);
    skip_0:
    // 0x800E6790: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E6794: jal         0x8001311C
    // 0x800E6798: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_0;
    // 0x800E6798: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_0:
    // 0x800E679C: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800E67A0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E67A4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E67A8: addiu       $t8, $t7, 0x1800
    ctx->r24 = ADD32(ctx->r15, 0X1800);
    // 0x800E67AC: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x800E67B0: addu        $t9, $s1, $v0
    ctx->r25 = ADD32(ctx->r17, ctx->r2);
L_800E67B4:
    // 0x800E67B4: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x800E67B8: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x800E67BC: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x800E67C0: sllv        $t1, $t0, $s2
    ctx->r9 = S32(ctx->r8 << (ctx->r18 & 31));
    // 0x800E67C4: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E67C8: sltiu       $at, $s2, 0x10
    ctx->r1 = ctx->r18 < 0X10 ? 1 : 0;
    // 0x800E67CC: bne         $at, $zero, L_800E677C
    if (ctx->r1 != 0) {
        // 0x800E67D0: or          $s3, $s3, $t1
        ctx->r19 = ctx->r19 | ctx->r9;
            goto L_800E677C;
    }
    // 0x800E67D0: or          $s3, $s3, $t1
    ctx->r19 = ctx->r19 | ctx->r9;
L_800E67D4:
    // 0x800E67D4: addiu       $s2, $s2, -0x10
    ctx->r18 = ADD32(ctx->r18, -0X10);
    // 0x800E67D8: andi        $s5, $s3, 0xFFFF
    ctx->r21 = ctx->r19 & 0XFFFF;
    // 0x800E67DC: srl         $t3, $s3, 16
    ctx->r11 = S32(U32(ctx->r19) >> 16);
    // 0x800E67E0: sltiu       $at, $s2, 0x10
    ctx->r1 = ctx->r18 < 0X10 ? 1 : 0;
    // 0x800E67E4: beq         $at, $zero, L_800E6848
    if (ctx->r1 == 0) {
        // 0x800E67E8: or          $s3, $t3, $zero
        ctx->r19 = ctx->r11 | 0;
            goto L_800E6848;
    }
    // 0x800E67E8: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x800E67EC: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E67F0:
    // 0x800E67F0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E67F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E67F8: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E67FC: bnel        $at, $zero, L_800E6828
    if (ctx->r1 != 0) {
        // 0x800E6800: addu        $t6, $s1, $v0
        ctx->r14 = ADD32(ctx->r17, ctx->r2);
            goto L_800E6828;
    }
    goto skip_1;
    // 0x800E6800: addu        $t6, $s1, $v0
    ctx->r14 = ADD32(ctx->r17, ctx->r2);
    skip_1:
    // 0x800E6804: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E6808: jal         0x8001311C
    // 0x800E680C: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_1;
    // 0x800E680C: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_1:
    // 0x800E6810: lw          $t4, 0x30($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X30);
    // 0x800E6814: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E6818: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E681C: addiu       $t5, $t4, 0x1800
    ctx->r13 = ADD32(ctx->r12, 0X1800);
    // 0x800E6820: sw          $t5, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r13;
    // 0x800E6824: addu        $t6, $s1, $v0
    ctx->r14 = ADD32(ctx->r17, ctx->r2);
L_800E6828:
    // 0x800E6828: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800E682C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800E6830: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800E6834: sllv        $t8, $t7, $s2
    ctx->r24 = S32(ctx->r15 << (ctx->r18 & 31));
    // 0x800E6838: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E683C: sltiu       $at, $s2, 0x10
    ctx->r1 = ctx->r18 < 0X10 ? 1 : 0;
    // 0x800E6840: bne         $at, $zero, L_800E67F0
    if (ctx->r1 != 0) {
        // 0x800E6844: or          $s3, $s3, $t8
        ctx->r19 = ctx->r19 | ctx->r24;
            goto L_800E67F0;
    }
    // 0x800E6844: or          $s3, $s3, $t8
    ctx->r19 = ctx->r19 | ctx->r24;
L_800E6848:
    // 0x800E6848: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x800E684C: srl         $t0, $s3, 16
    ctx->r8 = S32(U32(ctx->r19) >> 16);
    // 0x800E6850: or          $s3, $t0, $zero
    ctx->r19 = ctx->r8 | 0;
    // 0x800E6854: addiu       $s2, $s2, -0x10
    ctx->r18 = ADD32(ctx->r18, -0X10);
    // 0x800E6858: beq         $s5, $zero, L_800E68F4
    if (ctx->r21 == 0) {
        // 0x800E685C: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_800E68F4;
    }
    // 0x800E685C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800E6860: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x800E6864: addu        $s4, $t1, $s6
    ctx->r20 = ADD32(ctx->r9, ctx->r22);
L_800E6868:
    // 0x800E6868: sltiu       $at, $s2, 0x8
    ctx->r1 = ctx->r18 < 0X8 ? 1 : 0;
    // 0x800E686C: beql        $at, $zero, L_800E68D4
    if (ctx->r1 == 0) {
        // 0x800E6870: or          $v0, $s5, $zero
        ctx->r2 = ctx->r21 | 0;
            goto L_800E68D4;
    }
    goto skip_2;
    // 0x800E6870: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    skip_2:
    // 0x800E6874: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E6878:
    // 0x800E6878: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E687C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E6880: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E6884: bnel        $at, $zero, L_800E68B0
    if (ctx->r1 != 0) {
        // 0x800E6888: addu        $t4, $s1, $v0
        ctx->r12 = ADD32(ctx->r17, ctx->r2);
            goto L_800E68B0;
    }
    goto skip_3;
    // 0x800E6888: addu        $t4, $s1, $v0
    ctx->r12 = ADD32(ctx->r17, ctx->r2);
    skip_3:
    // 0x800E688C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E6890: jal         0x8001311C
    // 0x800E6894: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_2;
    // 0x800E6894: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_2:
    // 0x800E6898: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
    // 0x800E689C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E68A0: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E68A4: addiu       $t3, $t2, 0x1800
    ctx->r11 = ADD32(ctx->r10, 0X1800);
    // 0x800E68A8: sw          $t3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r11;
    // 0x800E68AC: addu        $t4, $s1, $v0
    ctx->r12 = ADD32(ctx->r17, ctx->r2);
L_800E68B0:
    // 0x800E68B0: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800E68B4: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800E68B8: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800E68BC: sllv        $t6, $t5, $s2
    ctx->r14 = S32(ctx->r13 << (ctx->r18 & 31));
    // 0x800E68C0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E68C4: sltiu       $at, $s2, 0x8
    ctx->r1 = ctx->r18 < 0X8 ? 1 : 0;
    // 0x800E68C8: bne         $at, $zero, L_800E6878
    if (ctx->r1 != 0) {
        // 0x800E68CC: or          $s3, $s3, $t6
        ctx->r19 = ctx->r19 | ctx->r14;
            goto L_800E6878;
    }
    // 0x800E68CC: or          $s3, $s3, $t6
    ctx->r19 = ctx->r19 | ctx->r14;
    // 0x800E68D0: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_800E68D4:
    // 0x800E68D4: sb          $s3, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r19;
    // 0x800E68D8: srl         $t8, $s3, 8
    ctx->r24 = S32(U32(ctx->r19) >> 8);
    // 0x800E68DC: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800E68E0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800E68E4: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x800E68E8: addiu       $s2, $s2, -0x8
    ctx->r18 = ADD32(ctx->r18, -0X8);
    // 0x800E68EC: bne         $s5, $zero, L_800E6868
    if (ctx->r21 != 0) {
        // 0x800E68F0: addiu       $s5, $s5, -0x1
        ctx->r21 = ADD32(ctx->r21, -0X1);
            goto L_800E6868;
    }
    // 0x800E68F0: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_800E68F4:
    // 0x800E68F4: sw          $s6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r22;
    // 0x800E68F8: sw          $s3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r19;
    // 0x800E68FC: sw          $s2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r18;
    // 0x800E6900: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800E6904: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800E6908: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800E690C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800E6910: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800E6914: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800E6918: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800E691C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E6920: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800E6924: jr          $ra
    // 0x800E6928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800E6928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void _scinfobar_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A5B0: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A5B0);
    return;
    // 0x8008A5B4: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_8008E974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E974: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8008E978: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008E97C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8008E980: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x8008E984: sll         $t0, $t8, 22
    ctx->r8 = S32(ctx->r24 << 22);
    // 0x8008E988: bgez        $t0, L_8008E998
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8008E98C: nop
    
            goto L_8008E998;
    }
    // 0x8008E98C: nop

    // 0x8008E990: jr          $ra
    // 0x8008E994: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8008E994: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008E998:
    // 0x8008E998: jr          $ra
    // 0x8008E99C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8008E99C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void capod_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_test_room_quiet()) { ctx->r2 = 0; return; }
    // 0x808001A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808001B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808001B4: jal         0x8008FFE8
    // 0x808001B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x808001B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808001BC: beq         $v0, $zero, L_808001DC
    if (ctx->r2 == 0) {
        // 0x808001C0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808001DC;
    }
    // 0x808001C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001C4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808001C8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x808001CC: jal         0x80089560
    // 0x808001D0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    _ncpod_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808001D0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808001D4: b           L_808001E4
    // 0x808001D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808001E4;
    // 0x808001D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001DC:
    // 0x808001DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808001E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001E4:
    // 0x808001E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001E8: jr          $ra
    // 0x808001EC: nop

    return;
    // 0x808001EC: nop

;}
RECOMP_FUNC void func_8008D6D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D6D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D6D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D6DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D6E0: jal         0x800C6E38
    // 0x8008D6E4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    func_800C6E38(rdram, ctx);
        goto after_0;
    // 0x8008D6E4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_0:
    // 0x8008D6E8: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D6EC: beq         $t6, $zero, L_8008D704
    if (ctx->r14 == 0) {
        // 0x8008D6F0: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008D704;
    }
    // 0x8008D6F0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008D6F4: jal         0x800A3304
    // 0x8008D6F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3304(rdram, ctx);
        goto after_1;
    // 0x8008D6F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008D6FC: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008D700: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8008D704:
    // 0x8008D704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D70C: jr          $ra
    // 0x8008D710: nop

    return;
    // 0x8008D710: nop

;}
RECOMP_FUNC void _chdinoswitches_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F98: syscall     267
    recomp_syscall_handler(rdram, ctx, 0x80085F98);
    return;
    // 0x80085F9C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void susplinet_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800350: lh          $t6, 0x34($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X34);
    // 0x80800354: jr          $ra
    // 0x80800358: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    return;
    // 0x80800358: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
;}
