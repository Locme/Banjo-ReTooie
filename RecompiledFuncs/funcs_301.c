#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800B8E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8E28: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B8E2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B8E30: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800B8E34: addiu       $s1, $s1, -0x7D40
    ctx->r17 = ADD32(ctx->r17, -0X7D40);
    // 0x800B8E38: lbu         $t6, 0xC($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XC);
    // 0x800B8E3C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800B8E40: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800B8E44: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800B8E48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B8E4C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800B8E50: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800B8E54: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800B8E58: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x800B8E5C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B8E60: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800B8E64: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800B8E68: beq         $t6, $zero, L_800B8F5C
    if (ctx->r14 == 0) {
        // 0x800B8E6C: sw          $s3, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r19;
            goto L_800B8F5C;
    }
    // 0x800B8E6C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800B8E70: lbu         $t7, 0x7($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X7);
    // 0x800B8E74: beq         $t7, $zero, L_800B8EA8
    if (ctx->r15 == 0) {
        // 0x800B8E78: nop
    
            goto L_800B8EA8;
    }
    // 0x800B8E78: nop

    // 0x800B8E7C: jal         0x800D3574
    // 0x800B8E80: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    func_800D3574(rdram, ctx);
        goto after_0;
    // 0x800B8E80: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    after_0:
    // 0x800B8E84: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800B8E88: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800B8E8C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800B8E90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B8E94: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B8E98: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800B8E9C: mfc1        $s4, $f16
    ctx->r20 = (int32_t)ctx->f16.u32l;
    // 0x800B8EA0: b           L_800B8ED4
    // 0x800B8EA4: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
        goto L_800B8ED4;
    // 0x800B8EA4: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
L_800B8EA8:
    // 0x800B8EA8: jal         0x800D35BC
    // 0x800B8EAC: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    func_800D35BC(rdram, ctx);
        goto after_1;
    // 0x800B8EAC: lbu         $a0, 0x6($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X6);
    after_1:
    // 0x800B8EB0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x800B8EB4: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800B8EB8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800B8EBC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B8EC0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B8EC4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800B8EC8: mfc1        $s5, $f10
    ctx->r21 = (int32_t)ctx->f10.u32l;
    // 0x800B8ECC: nop

    // 0x800B8ED0: sb          $zero, 0x8($s1)
    MEM_B(0X8, ctx->r17) = 0;
L_800B8ED4:
    // 0x800B8ED4: lbu         $a3, 0x0($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X0);
    // 0x800B8ED8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800B8EDC: beq         $a3, $zero, L_800B8F5C
    if (ctx->r7 == 0) {
        // 0x800B8EE0: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800B8F5C;
    }
    // 0x800B8EE0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_800B8EE4:
    // 0x800B8EE4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800B8EE8: jal         0x800B81CC
    // 0x800B8EEC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    func_800B81CC(rdram, ctx);
        goto after_2;
    // 0x800B8EEC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_2:
    // 0x800B8EF0: lbu         $v1, 0x7($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X7);
    // 0x800B8EF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800B8EF8: beq         $v1, $zero, L_800B8F28
    if (ctx->r3 == 0) {
        // 0x800B8EFC: nop
    
            goto L_800B8F28;
    }
    // 0x800B8EFC: nop

    // 0x800B8F00: lbu         $t0, 0x8($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X8);
    // 0x800B8F04: bne         $t0, $zero, L_800B8F28
    if (ctx->r8 != 0) {
        // 0x800B8F08: nop
    
            goto L_800B8F28;
    }
    // 0x800B8F08: nop

    // 0x800B8F0C: bgez        $v0, L_800B8F1C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B8F10: sra         $t1, $v0, 1
        ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800B8F1C;
    }
    // 0x800B8F10: sra         $t1, $v0, 1
    ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800B8F14: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x800B8F18: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_800B8F1C:
    // 0x800B8F1C: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // 0x800B8F20: b           L_800B8F50
    // 0x800B8F24: sb          $s3, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r19;
        goto L_800B8F50;
    // 0x800B8F24: sb          $s3, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r19;
L_800B8F28:
    // 0x800B8F28: beql        $v1, $zero, L_800B8F4C
    if (ctx->r3 == 0) {
        // 0x800B8F2C: or          $v0, $s5, $zero
        ctx->r2 = ctx->r21 | 0;
            goto L_800B8F4C;
    }
    goto skip_0;
    // 0x800B8F2C: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    skip_0:
    // 0x800B8F30: beq         $v0, $zero, L_800B8F40
    if (ctx->r2 == 0) {
        // 0x800B8F34: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_800B8F40;
    }
    // 0x800B8F34: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x800B8F38: b           L_800B8F50
    // 0x800B8F3C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
        goto L_800B8F50;
    // 0x800B8F3C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_800B8F40:
    // 0x800B8F40: b           L_800B8F4C
    // 0x800B8F44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B8F4C;
    // 0x800B8F44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B8F48: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
L_800B8F4C:
    // 0x800B8F4C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_800B8F50:
    // 0x800B8F50: lbu         $a3, 0x0($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X0);
    // 0x800B8F54: bnel        $a3, $zero, L_800B8EE4
    if (ctx->r7 != 0) {
        // 0x800B8F58: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800B8EE4;
    }
    goto skip_1;
    // 0x800B8F58: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_1:
L_800B8F5C:
    // 0x800B8F5C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800B8F60: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B8F64: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B8F68: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8F6C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800B8F70: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800B8F74: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800B8F78: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800B8F7C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800B8F80: jr          $ra
    // 0x800B8F84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B8F84: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _gczoombox_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B00: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087B00);
    return;
    // 0x80087B04: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800C9358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9358: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C935C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C9360: lbu         $v1, -0x54AC($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X54AC);
    // 0x800C9364: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C9368: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C936C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C9370: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800C9374: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C9378: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C937C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C9380: beq         $v1, $zero, L_800C93EC
    if (ctx->r3 == 0) {
        // 0x800C9384: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800C93EC;
    }
    // 0x800C9384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C9388: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800C938C: blez        $v1, L_800C93E0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C9390: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800C93E0;
    }
    // 0x800C9390: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C9394: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C9398: addiu       $s0, $s0, -0x54C0
    ctx->r16 = ADD32(ctx->r16, -0X54C0);
    // 0x800C939C: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_800C93A0:
    // 0x800C93A0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800C93A4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C93A8: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x800C93AC: beql        $a1, $s3, L_800C93D4
    if (ctx->r5 == ctx->r19) {
        // 0x800C93B0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800C93D4;
    }
    goto skip_0;
    // 0x800C93B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800C93B4: jal         0x800A8BD4
    // 0x800C93B8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800A8BD4(rdram, ctx);
        goto after_0;
    // 0x800C93B8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_0:
    // 0x800C93BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800C93C0: jal         0x800881A8
    // 0x800C93C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    _gctransitionDll_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x800C93C4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800C93C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C93CC: lbu         $v0, -0x54AC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X54AC);
    // 0x800C93D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800C93D4:
    // 0x800C93D4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C93D8: bne         $at, $zero, L_800C93A0
    if (ctx->r1 != 0) {
        // 0x800C93DC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800C93A0;
    }
    // 0x800C93DC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800C93E0:
    // 0x800C93E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C93E4: jal         0x800A8CCC
    // 0x800C93E8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800A8CCC(rdram, ctx);
        goto after_2;
    // 0x800C93E8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
L_800C93EC:
    // 0x800C93EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C93F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C93F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C93F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C93FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C9400: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C9404: jr          $ra
    // 0x800C9408: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C9408: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_801163B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801163B0: mfc1        $t9, $f30
    ctx->r25 = (int32_t)ctx->f30.u32l;
    // 0x801163B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801163B8: mfc1        $t8, $f28
    ctx->r24 = (int32_t)ctx->f28.u32l;
    // 0x801163BC: mfc1        $t7, $f26
    ctx->r15 = (int32_t)ctx->f26.u32l;
    // 0x801163C0: mfc1        $t6, $f24
    ctx->r14 = (int32_t)ctx->f24.u32l;
    // 0x801163C4: mfc1        $t5, $f22
    ctx->r13 = (int32_t)ctx->f22.u32l;
    // 0x801163C8: mfc1        $t4, $f20
    ctx->r12 = (int32_t)ctx->f20.u32l;
    // 0x801163CC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801163D0: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801163D4: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x801163D8: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x801163DC: lwc1        $f8, 0x14($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X14);
    // 0x801163E0: lwc1        $f10, 0x18($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X18);
    // 0x801163E4: lwc1        $f12, 0x20($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X20);
    // 0x801163E8: lwc1        $f14, 0x24($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X24);
    // 0x801163EC: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x801163F0: lwc1        $f30, 0x6630($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X6630);
L_801163F4:
    // 0x801163F4: lb          $t0, 0x0($a0)
    ctx->r8 = MEM_B(ctx->r4, 0X0);
    // 0x801163F8: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x801163FC: lb          $t1, 0x1($a0)
    ctx->r9 = MEM_B(ctx->r4, 0X1);
    // 0x80116400: mtc1        $t1, $f20
    ctx->f20.u32l = ctx->r9;
    // 0x80116404: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80116408: mul.s       $f18, $f18, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f30.fl);
    // 0x8011640C: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x80116410: mul.s       $f20, $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80116414: lb          $t2, 0x2($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X2);
    // 0x80116418: mul.s       $f24, $f18, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8011641C: mtc1        $t2, $f22
    ctx->f22.u32l = ctx->r10;
    // 0x80116420: mul.s       $f26, $f20, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80116424: cvt.s.w     $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    ctx->f22.fl = CVT_S_W(ctx->f22.u32l);
    // 0x80116428: mul.s       $f22, $f22, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f30.fl);
    // 0x8011642C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80116430: mul.s       $f28, $f22, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f28.fl = MUL_S(ctx->f22.fl, ctx->f12.fl);
    // 0x80116434: add.s       $f26, $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f24.fl;
    // 0x80116438: mul.s       $f24, $f18, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8011643C: add.s       $f28, $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f26.fl;
    // 0x80116440: mul.s       $f26, $f20, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f26.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80116444: swc1        $f28, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f28.u32l;
    // 0x80116448: mul.s       $f28, $f22, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f28.fl = MUL_S(ctx->f22.fl, ctx->f14.fl);
    // 0x8011644C: add.s       $f26, $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f24.fl;
    // 0x80116450: mul.s       $f24, $f18, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80116454: add.s       $f28, $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f26.fl;
    // 0x80116458: mul.s       $f26, $f20, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x8011645C: swc1        $f28, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f28.u32l;
    // 0x80116460: mul.s       $f28, $f22, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f28.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x80116464: add.s       $f26, $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f24.fl;
    // 0x80116468: add.s       $f28, $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f26.fl;
    // 0x8011646C: swc1        $f28, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f28.u32l;
    // 0x80116470: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80116474: bgtz        $a3, L_801163F4
    if (SIGNED(ctx->r7) > 0) {
        // 0x80116478: addiu       $a2, $a2, 0xC
        ctx->r6 = ADD32(ctx->r6, 0XC);
            goto L_801163F4;
    }
    // 0x80116478: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    // 0x8011647C: mtc1        $t9, $f30
    ctx->f30.u32l = ctx->r25;
    // 0x80116480: mtc1        $t8, $f28
    ctx->f28.u32l = ctx->r24;
    // 0x80116484: mtc1        $t7, $f26
    ctx->f26.u32l = ctx->r15;
    // 0x80116488: mtc1        $t6, $f24
    ctx->f24.u32l = ctx->r14;
    // 0x8011648C: mtc1        $t5, $f22
    ctx->f22.u32l = ctx->r13;
    // 0x80116490: mtc1        $t4, $f20
    ctx->f20.u32l = ctx->r12;
    // 0x80116494: jr          $ra
    // 0x80116498: nop

    return;
    // 0x80116498: nop

;}
RECOMP_FUNC void func_80109FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109FE8: beql        $a1, $zero, L_8010A008
    if (ctx->r5 == 0) {
        // 0x80109FEC: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8010A008;
    }
    goto skip_0;
    // 0x80109FEC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80109FF0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80109FF4: lbu         $t6, 0x1B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1B);
    // 0x80109FF8: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80109FFC: jr          $ra
    // 0x8010A000: sb          $t7, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r15;
    return;
    // 0x8010A000: sb          $t7, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r15;
    // 0x8010A004: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_8010A008:
    // 0x8010A008: lbu         $t9, 0x1B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1B);
    // 0x8010A00C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8010A010: sb          $t0, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r8;
    // 0x8010A014: jr          $ra
    // 0x8010A018: nop

    return;
    // 0x8010A018: nop

;}
RECOMP_FUNC void _changlerbossflare_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865B0: syscall     340
    recomp_syscall_handler(rdram, ctx, 0x800865B0);
    return;
    // 0x800865B4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _gczoombox_entrypoint_37(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C08: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087C08);
    return;
    // 0x80087C0C: addi        $t0, $zero, 0x94
    ctx->r8 = ADD32(0, 0X94);
;}
RECOMP_FUNC void func_80096628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009662C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096630: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80096634: jal         0x800C6744
    // 0x80096638: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C6744(rdram, ctx);
        goto after_0;
    // 0x80096638: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8009663C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80096644: jr          $ra
    // 0x80096648: nop

    return;
    // 0x80096648: nop

;}
RECOMP_FUNC void func_80100120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100120: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80100124: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100128: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010012C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80100130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80100134: sll         $t8, $t6, 10
    ctx->r24 = S32(ctx->r14 << 10);
    // 0x80100138: bltzl       $t8, L_801001C8
    if (SIGNED(ctx->r24) < 0) {
        // 0x8010013C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801001C8;
    }
    goto skip_0;
    // 0x8010013C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80100140: jal         0x80100368
    // 0x80100144: nop

    func_80100368(rdram, ctx);
        goto after_0;
    // 0x80100144: nop

    after_0:
    // 0x80100148: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x8010014C: beql        $v1, $zero, L_801001BC
    if (ctx->r3 == 0) {
        // 0x80100150: lbu         $t1, 0x75($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X75);
            goto L_801001BC;
    }
    goto skip_1;
    // 0x80100150: lbu         $t1, 0x75($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X75);
    skip_1:
    // 0x80100154: lw          $t9, 0x70($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X70);
    // 0x80100158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010015C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80100160: sll         $t1, $t9, 28
    ctx->r9 = S32(ctx->r25 << 28);
    // 0x80100164: bgez        $t1, L_8010018C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80100168: nop
    
            goto L_8010018C;
    }
    // 0x80100168: nop

    // 0x8010016C: jal         0x80102F74
    // 0x80100170: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80102F74(rdram, ctx);
        goto after_1;
    // 0x80100170: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80100174: beq         $v0, $zero, L_8010018C
    if (ctx->r2 == 0) {
        // 0x80100178: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8010018C;
    }
    // 0x80100178: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8010017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80100180: jal         0x8010381C
    // 0x80100184: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8010381C(rdram, ctx);
        goto after_2;
    // 0x80100184: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80100188: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8010018C:
    // 0x8010018C: jalr        $v1
    // 0x80100190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_3;
    // 0x80100190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80100194: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80100198: sll         $t4, $t2, 14
    ctx->r12 = S32(ctx->r10 << 14);
    // 0x8010019C: bgezl       $t4, L_801001BC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x801001A0: lbu         $t1, 0x75($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X75);
            goto L_801001BC;
    }
    goto skip_2;
    // 0x801001A0: lbu         $t1, 0x75($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X75);
    skip_2:
    // 0x801001A4: lbu         $t6, 0x7E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7E);
    // 0x801001A8: ori         $t8, $t6, 0x80
    ctx->r24 = ctx->r14 | 0X80;
    // 0x801001AC: sb          $t8, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r24;
    // 0x801001B0: andi        $t9, $t8, 0xBF
    ctx->r25 = ctx->r24 & 0XBF;
    // 0x801001B4: sb          $t9, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r25;
    // 0x801001B8: lbu         $t1, 0x75($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X75);
L_801001BC:
    // 0x801001BC: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x801001C0: sb          $t2, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r10;
    // 0x801001C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801001C8:
    // 0x801001C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801001CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801001D0: jr          $ra
    // 0x801001D4: nop

    return;
    // 0x801001D4: nop

;}
RECOMP_FUNC void func_80800CA4_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CA4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800CA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800CAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800CB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800CB4: jal         0x8008CABC
    // 0x80800CB8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800CB8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800CBC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80800CC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800CC8: beq         $a1, $zero, L_80800E70
    if (ctx->r5 == 0) {
        // 0x80800CCC: sb          $a1, 0x15C($s0)
        MEM_B(0X15C, ctx->r16) = ctx->r5;
            goto L_80800E70;
    }
    // 0x80800CCC: sb          $a1, 0x15C($s0)
    MEM_B(0X15C, ctx->r16) = ctx->r5;
    // 0x80800CD0: beq         $a1, $at, L_80800CE8
    if (ctx->r5 == ctx->r1) {
        // 0x80800CD4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800CE8;
    }
    // 0x80800CD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800CD8: beq         $a1, $at, L_80800E58
    if (ctx->r5 == ctx->r1) {
        // 0x80800CDC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E58;
    }
    // 0x80800CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE0: b           L_80800E84
    // 0x80800CE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E84;
    // 0x80800CE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800CE8:
    // 0x80800CE8: jal         0x8008AF24
    // 0x80800CEC: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800CEC: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800CF0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800CF4: jal         0x8008AED4
    // 0x80800CF8: addiu       $a1, $zero, 0x1D1
    ctx->r5 = ADD32(0, 0X1D1);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800CF8: addiu       $a1, $zero, 0x1D1
    ctx->r5 = ADD32(0, 0X1D1);
    after_2:
    // 0x80800CFC: lui         $a1, 0x400C
    ctx->r5 = S32(0X400C << 16);
    // 0x80800D00: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800D04: jal         0x8008B1BC
    // 0x80800D08: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x80800D08: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800D0C: lui         $a2, 0x3F37
    ctx->r6 = S32(0X3F37 << 16);
    // 0x80800D10: ori         $a2, $a2, 0xA3D
    ctx->r6 = ctx->r6 | 0XA3D;
    // 0x80800D14: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800D18: jal         0x8008B1D4
    // 0x80800D1C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_4;
    // 0x80800D1C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800D20: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800D24: jal         0x8008B134
    // 0x80800D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80800D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800D2C: lui         $a1, 0x3E46
    ctx->r5 = S32(0X3E46 << 16);
    // 0x80800D30: ori         $a1, $a1, 0xA7F0
    ctx->r5 = ctx->r5 | 0XA7F0;
    // 0x80800D34: jal         0x8008B24C
    // 0x80800D38: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setStart(rdram, ctx);
        goto after_6;
    // 0x80800D38: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80800D3C: jal         0x8008B064
    // 0x80800D40: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80800D40: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800D44: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800D48: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800D54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800D58: jal         0x8009FFD8
    // 0x80800D5C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_8;
    // 0x80800D5C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x80800D60: jal         0x8009EF04
    // 0x80800D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_9;
    // 0x80800D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800D68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800D6C: nop

    // 0x80800D70: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80800D74: nop

    // 0x80800D78: bc1t        L_80800D94
    if (c1cs) {
        // 0x80800D7C: nop
    
            goto L_80800D94;
    }
    // 0x80800D7C: nop

    // 0x80800D80: jal         0x8009EEB8
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_10;
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800D88: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800D8C: jal         0x8009C914
    // 0x80800D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_11;
    // 0x80800D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_80800D94:
    // 0x80800D94: jal         0x8009C990
    // 0x80800D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_12;
    // 0x80800D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800D9C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800DA0: jal         0x8009B9C0
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_13;
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800DA8: jal         0x8009C990
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_14;
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800DB0: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80800DB4: jal         0x8009BB00
    // 0x80800DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_15;
    // 0x80800DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800DBC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DC4: jal         0x8009BA68
    // 0x80800DC8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x80800DC8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_16:
    // 0x80800DCC: lui         $a1, 0x4489
    ctx->r5 = S32(0X4489 << 16);
    // 0x80800DD0: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800DD4: jal         0x8009BA58
    // 0x80800DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_17;
    // 0x80800DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800DDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DE0: jal         0x8009BCB4
    // 0x80800DE4: lui         $a1, 0xC4E1
    ctx->r5 = S32(0XC4E1 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_18;
    // 0x80800DE4: lui         $a1, 0xC4E1
    ctx->r5 = S32(0XC4E1 << 16);
    after_18:
    // 0x80800DE8: jal         0x800DC0C0
    // 0x80800DEC: nop

    func_800DC0C0(rdram, ctx);
        goto after_19;
    // 0x80800DEC: nop

    after_19:
    // 0x80800DF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800DF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800DF8: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80800DFC: lui         $a3, 0x3FAC
    ctx->r7 = S32(0X3FAC << 16);
    // 0x80800E00: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800E04: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800E08: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800E0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E10: bc1f        L_80800E44
    if (!c1cs) {
        // 0x80800E14: addiu       $a1, $zero, 0x4D9
        ctx->r5 = ADD32(0, 0X4D9);
            goto L_80800E44;
    }
    // 0x80800E14: addiu       $a1, $zero, 0x4D9
    ctx->r5 = ADD32(0, 0X4D9);
    // 0x80800E18: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80800E1C: lui         $a3, 0x3FAC
    ctx->r7 = S32(0X3FAC << 16);
    // 0x80800E20: addiu       $t7, $zero, 0x55F0
    ctx->r15 = ADD32(0, 0X55F0);
    // 0x80800E24: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800E28: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800E2C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E34: jal         0x8009DBB0
    // 0x80800E38: addiu       $a1, $zero, 0x4D8
    ctx->r5 = ADD32(0, 0X4D8);
    func_8009DBB0(rdram, ctx);
        goto after_20;
    // 0x80800E38: addiu       $a1, $zero, 0x4D8
    ctx->r5 = ADD32(0, 0X4D8);
    after_20:
    // 0x80800E3C: b           L_80800E84
    // 0x80800E40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E84;
    // 0x80800E40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E44:
    // 0x80800E44: addiu       $t8, $zero, 0x55F0
    ctx->r24 = ADD32(0, 0X55F0);
    // 0x80800E48: jal         0x8009DBB0
    // 0x80800E4C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_8009DBB0(rdram, ctx);
        goto after_21;
    // 0x80800E4C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_21:
    // 0x80800E50: b           L_80800E84
    // 0x80800E54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E84;
    // 0x80800E54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E58:
    // 0x80800E58: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800E5C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800E60: jal         0x8008CF1C
    // 0x80800E64: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_22;
    // 0x80800E64: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_22:
    // 0x80800E68: b           L_80800E84
    // 0x80800E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800E84;
    // 0x80800E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E70:
    // 0x80800E70: lui         $a1, 0xC53B
    ctx->r5 = S32(0XC53B << 16);
    // 0x80800E74: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800E78: jal         0x8009BCB4
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_23;
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800E80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800E84:
    // 0x80800E84: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800E88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800E8C: jr          $ra
    // 0x80800E90: nop

    return;
    // 0x80800E90: nop

;}
RECOMP_FUNC void func_80800A2C_chtoxicroombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A2C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80800A30: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80800A34: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80800A38: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2308, 0X1010) << 16);
    // 0x80800A3C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800A40: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80800A44: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x80800A48: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x80800A4C: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x80800A50: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x80800A54: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80800A58: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x80800A5C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800A60: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800A64: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800A68: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800A6C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800A70: addiu       $t6, $t6, 0x1010
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2308, 0X1010));
    // 0x80800A74: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80800A78: addiu       $s3, $sp, 0x84
    ctx->r19 = ADD32(ctx->r29, 0X84);
    // 0x80800A7C: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x80800A80: sw          $at, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r1;
    // 0x80800A84: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80800A88: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x80800A8C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80800A90: sw          $t9, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r25;
    // 0x80800A94: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80800A98: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    // 0x80800A9C: sw          $at, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r1;
    // 0x80800AA0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80800AA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800AA8: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80800AAC: lwc1        $f12, 0x58($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800AB0: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    // 0x80800AB4: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800AB8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80800ABC: jal         0x800F10B4
    // 0x80800AC0: nop

    func_800F10B4(rdram, ctx);
        goto after_0;
    // 0x80800AC0: nop

    after_0:
    // 0x80800AC4: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80800AC8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800ACC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800AD0: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80800AD4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800AD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800ADC: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(2308, 0X101C) << 16);
    // 0x80800AE0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800AE4: addiu       $s4, $s4, 0x101C
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(2308, 0X101C));
    // 0x80800AE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800AEC: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
    // 0x80800AF0: addiu       $s1, $sp, 0x70
    ctx->r17 = ADD32(ctx->r29, 0X70);
    // 0x80800AF4: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_80800AF8:
    // 0x80800AF8: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x80800AFC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800B00: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80800B04: lui         $a2, 0x44FA
    ctx->r6 = S32(0X44FA << 16);
    // 0x80800B08: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80800B0C: jal         0x800F10B4
    // 0x80800B10: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800B10: swc1        $f12, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80800B14: mul.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80800B18: lw          $at, 0x0($s4)
    ctx->r1 = MEM_W(ctx->r20, 0X0);
    // 0x80800B1C: lw          $t2, 0x4($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X4);
    // 0x80800B20: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800B24: sw          $at, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r1;
    // 0x80800B28: lw          $at, 0x8($s4)
    ctx->r1 = MEM_W(ctx->r20, 0X8);
    // 0x80800B2C: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    // 0x80800B30: mul.s       $f12, $f10, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x80800B34: jal         0x800138D0
    // 0x80800B38: sw          $at, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r1;
    func_800138D0(rdram, ctx);
        goto after_2;
    // 0x80800B38: sw          $at, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r1;
    after_2:
    // 0x80800B3C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800B40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2308, 0XEFC) << 16);
    // 0x80800B48: lwc1        $f4, 0xEFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2308, 0XEFC));
    // 0x80800B4C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800B50: nop

    // 0x80800B54: mul.s       $f8, $f20, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x80800B58: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800B5C: mul.s       $f12, $f8, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80800B60: jal         0x800138D0
    // 0x80800B64: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    func_800138D0(rdram, ctx);
        goto after_3;
    // 0x80800B64: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80800B68: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80800B6C: jal         0x800DF830
    // 0x80800B70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_4;
    // 0x80800B70: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x80800B74: jal         0x800D674C
    // 0x80800B78: addiu       $a0, $zero, 0x882
    ctx->r4 = ADD32(0, 0X882);
    func_800D674C(rdram, ctx);
        goto after_5;
    // 0x80800B78: addiu       $a0, $zero, 0x882
    ctx->r4 = ADD32(0, 0X882);
    after_5:
    // 0x80800B7C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80800B80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800B84: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800B88: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80800B8C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800B90: jal         0x800DE498
    // 0x80800B94: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800DE498(rdram, ctx);
        goto after_6;
    // 0x80800B94: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_6:
    // 0x80800B98: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80800B9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800BA0: bne         $s0, $s5, L_80800AF8
    if (ctx->r16 != ctx->r21) {
        // 0x80800BA4: add.s       $f12, $f12, $f30
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f30.fl;
            goto L_80800AF8;
    }
    // 0x80800BA4: add.s       $f12, $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f30.fl;
    // 0x80800BA8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80800BAC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800BB0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800BB4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800BB8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800BBC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800BC0: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80800BC4: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x80800BC8: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x80800BCC: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80800BD0: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80800BD4: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x80800BD8: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x80800BDC: jr          $ra
    // 0x80800BE0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80800BE0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void idtwinklea_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800078: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x8080007C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80800080: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x80800084: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80800088: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8080008C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800090: beq         $at, $zero, L_808001C0
    if (ctx->r1 == 0) {
        // 0x80800094: sw          $a0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r4;
            goto L_808001C0;
    }
    // 0x80800094: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80800098: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8080009C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808000A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808000AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_808000B0:
    // 0x808000B0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x808000B4: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x808000B8: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x808000BC: beq         $at, $zero, L_80800104
    if (ctx->r1 == 0) {
        // 0x808000C0: nop
    
            goto L_80800104;
    }
    // 0x808000C0: nop

    // 0x808000C4: lh          $a3, 0x0($a1)
    ctx->r7 = MEM_H(ctx->r5, 0X0);
    // 0x808000C8: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
L_808000CC:
    // 0x808000CC: bnel        $a3, $t7, L_808000F8
    if (ctx->r7 != ctx->r15) {
        // 0x808000D0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_808000F8;
    }
    goto skip_0;
    // 0x808000D0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_0:
    // 0x808000D4: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x808000D8: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    // 0x808000DC: bnel        $t8, $t9, L_808000F8
    if (ctx->r24 != ctx->r25) {
        // 0x808000E0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_808000F8;
    }
    goto skip_1;
    // 0x808000E0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    skip_1:
    // 0x808000E4: lh          $t0, 0x4($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X4);
    // 0x808000E8: lh          $t1, 0xC($v1)
    ctx->r9 = MEM_H(ctx->r3, 0XC);
    // 0x808000EC: beq         $t0, $t1, L_80800104
    if (ctx->r8 == ctx->r9) {
        // 0x808000F0: nop
    
            goto L_80800104;
    }
    // 0x808000F0: nop

    // 0x808000F4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_808000F8:
    // 0x808000F8: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x808000FC: bnel        $at, $zero, L_808000CC
    if (ctx->r1 != 0) {
        // 0x80800100: lh          $t7, 0x8($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X8);
            goto L_808000CC;
    }
    goto skip_2;
    // 0x80800100: lh          $t7, 0x8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X8);
    skip_2:
L_80800104:
    // 0x80800104: bne         $v1, $a2, L_80800114
    if (ctx->r3 != ctx->r6) {
        // 0x80800108: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_80800114;
    }
    // 0x80800108: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8080010C: b           L_80800118
    // 0x80800110: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80800118;
    // 0x80800110: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80800114:
    // 0x80800114: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80800118:
    // 0x80800118: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8080011C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800120: bc1f        L_8080012C
    if (!c1cs) {
        // 0x80800124: nop
    
            goto L_8080012C;
    }
    // 0x80800124: nop

    // 0x80800128: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8080012C:
    // 0x8080012C: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80800130: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800134: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80800138: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8080013C: nop

    // 0x80800140: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800144: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800148: nop

    // 0x8080014C: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80800150: beql        $t3, $zero, L_808001A0
    if (ctx->r11 == 0) {
        // 0x80800154: mfc1        $t3, $f6
        ctx->r11 = (int32_t)ctx->f6.u32l;
            goto L_808001A0;
    }
    goto skip_3;
    // 0x80800154: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x80800158: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080015C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800160: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800164: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80800168: nop

    // 0x8080016C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800170: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80800174: nop

    // 0x80800178: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8080017C: bne         $t3, $zero, L_80800194
    if (ctx->r11 != 0) {
        // 0x80800180: nop
    
            goto L_80800194;
    }
    // 0x80800180: nop

    // 0x80800184: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80800188: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080018C: b           L_808001AC
    // 0x80800190: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_808001AC;
    // 0x80800190: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80800194:
    // 0x80800194: b           L_808001AC
    // 0x80800198: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_808001AC;
    // 0x80800198: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8080019C: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
L_808001A0:
    // 0x808001A0: nop

    // 0x808001A4: bltz        $t3, L_80800194
    if (SIGNED(ctx->r11) < 0) {
        // 0x808001A8: nop
    
            goto L_80800194;
    }
    // 0x808001A8: nop

L_808001AC:
    // 0x808001AC: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x808001B0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x808001B4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x808001B8: bne         $at, $zero, L_808000B0
    if (ctx->r1 != 0) {
        // 0x808001BC: sb          $t3, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r11;
            goto L_808000B0;
    }
    // 0x808001BC: sb          $t3, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r11;
L_808001C0:
    // 0x808001C0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x808001C4: jr          $ra
    // 0x808001C8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x808001C8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x808001CC: nop

;}
RECOMP_FUNC void func_8080068C_bskazpaddle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080068C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800690: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800694: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800698: jal         0x80800068
    // 0x8080069C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800068_bskazpaddle(rdram, ctx);
        goto after_0;
    // 0x8080069C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808006A0: lui         $a2, 0x4033
    ctx->r6 = S32(0X4033 << 16);
    // 0x808006A4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808006A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006AC: jal         0x8008CB3C
    // 0x808006B0: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808006B0: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    after_1:
    // 0x808006B4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808006B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808006C4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808006C8: jal         0x8009FFD8
    // 0x808006CC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808006CC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x808006D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D4: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808006D8: jal         0x8009C99C
    // 0x808006DC: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x808006DC: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_3:
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E4: jal         0x8009B9B0
    // 0x808006E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x808006E8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F0: jal         0x800A4DA4
    // 0x808006F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800A4DA4(rdram, ctx);
        goto after_5;
    // 0x808006F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x808006F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808006FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800700: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800704: jr          $ra
    // 0x80800708: nop

    return;
    // 0x80800708: nop

;}
RECOMP_FUNC void _sumole_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A20: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A20);
    return;
    // 0x80089A24: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_80800000_chegggolden(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80800004: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8080000C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80800010: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80800014: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80800018: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8080001C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80800020: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80800024: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80800028: jal         0x80100094
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800030: jal         0x800A946C
    // 0x80800034: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    func_800A946C(rdram, ctx);
        goto after_1;
    // 0x80800034: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_1:
    // 0x80800038: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8080003C: beq         $at, $zero, L_808000E8
    if (ctx->r1 == 0) {
        // 0x80800040: addiu       $s3, $sp, 0x64
        ctx->r19 = ADD32(ctx->r29, 0X64);
            goto L_808000E8;
    }
    // 0x80800040: addiu       $s3, $sp, 0x64
    ctx->r19 = ADD32(ctx->r29, 0X64);
    // 0x80800044: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800048: addiu       $a1, $s4, 0x28
    ctx->r5 = ADD32(ctx->r20, 0X28);
    // 0x8080004C: jal         0x800EFA20
    // 0x80800050: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_800EFA20(rdram, ctx);
        goto after_2;
    // 0x80800050: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_2:
    // 0x80800054: jal         0x800D8FF8
    // 0x80800058: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x80800058: nop

    after_3:
    // 0x8080005C: lwc1        $f4, 0x28($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80800060: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2112, 0X3E0) << 16);
    // 0x80800064: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80800068: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8080006C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800070: lui         $a2, 0x3FE6
    ctx->r6 = S32(0X3FE6 << 16);
    // 0x80800074: lui         $a3, 0x3D08
    ctx->r7 = S32(0X3D08 << 16);
    // 0x80800078: swc1        $f6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f6.u32l;
    // 0x8080007C: lwc1        $f8, 0x3E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2112, 0X3E0));
    // 0x80800080: ori         $a3, $a3, 0x6595
    ctx->r7 = ctx->r7 | 0X6595;
    // 0x80800084: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800088: jal         0x800F10B4
    // 0x8080008C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x8080008C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80800090: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800094: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80800098: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8080009C: addiu       $s0, $s4, 0x4
    ctx->r16 = ADD32(ctx->r20, 0X4);
    // 0x808000A0: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x808000A4: addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
    // 0x808000A8: bc1fl       L_808000EC
    if (!c1cs) {
        // 0x808000AC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808000EC;
    }
    goto skip_0;
    // 0x808000AC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x808000B0: add.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f20.fl;
L_808000B4:
    // 0x808000B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000BC: jal         0x800EE7F8
    // 0x808000C0: swc1        $f10, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f10.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x808000C0: swc1        $f10, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f10.u32l;
    after_5:
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: lw          $a1, 0x38($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X38);
    // 0x808000CC: jal         0x80088A90
    // 0x808000D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    _fxegg_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x808000D0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_6:
    // 0x808000D4: lwc1        $f2, 0x28($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X28);
    // 0x808000D8: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x808000DC: nop

    // 0x808000E0: bc1tl       L_808000B4
    if (c1cs) {
        // 0x808000E4: add.s       $f10, $f2, $f20
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f20.fl;
            goto L_808000B4;
    }
    goto skip_1;
    // 0x808000E4: add.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f20.fl;
    skip_1:
L_808000E8:
    // 0x808000E8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808000EC:
    // 0x808000EC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x808000F0: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x808000F4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808000F8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x808000FC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80800100: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80800104: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80800108: jr          $ra
    // 0x8080010C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8080010C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_80102E08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102E08: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80102E0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80102E10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80102E14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80102E18: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80102E1C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80102E20: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80102E24: jal         0x800EE7F8
    // 0x80102E28: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80102E28: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_0:
    // 0x80102E2C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80102E30: jal         0x800EE7F8
    // 0x80102E34: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80102E34: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80102E38: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80102E3C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80102E40: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80102E44: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80102E48: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80102E4C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80102E50: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80102E54: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80102E58: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80102E5C: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x80102E60: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x80102E64: jal         0x800BEF00
    // 0x80102E68: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x80102E68: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    after_2:
    // 0x80102E6C: beq         $v0, $zero, L_80102EA8
    if (ctx->r2 == 0) {
        // 0x80102E70: lwc1        $f16, 0x44($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
            goto L_80102EA8;
    }
    // 0x80102E70: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80102E74: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80102E78: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80102E7C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80102E80: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x80102E84: jal         0x800F1B78
    // 0x80102E88: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800F1B78(rdram, ctx);
        goto after_3;
    // 0x80102E88: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80102E8C: beq         $v0, $zero, L_80102EA8
    if (ctx->r2 == 0) {
        // 0x80102E90: lwc1        $f18, 0x24($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
            goto L_80102EA8;
    }
    // 0x80102E90: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80102E94: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x80102E98: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80102E9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80102EA0: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x80102EA4: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_80102EA8:
    // 0x80102EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80102EAC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80102EB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80102EB4: jr          $ra
    // 0x80102EB8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80102EB8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80102EBC: nop

;}
RECOMP_FUNC void func_808009F4_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A00: jal         0x80100094
    // 0x80800A04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A08: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800A0C: jal         0x80800734
    // 0x80800A10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800734_chclockworkmouse(rdram, ctx);
        goto after_1;
    // 0x80800A10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800A14: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A18: lbu         $t7, 0xFA($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XFA);
    // 0x80800A1C: beql        $t7, $zero, L_80800A38
    if (ctx->r15 == 0) {
        // 0x80800A20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800A38;
    }
    goto skip_0;
    // 0x80800A20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800A24: jal         0x800856B8
    // 0x80800A28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _capod_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800A28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800A2C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A30: sb          $zero, 0xFA($t8)
    MEM_B(0XFA, ctx->r24) = 0;
    // 0x80800A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A38:
    // 0x80800A38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A3C: jr          $ra
    // 0x80800A40: nop

    return;
    // 0x80800A40: nop

;}
RECOMP_FUNC void func_80800000_chfantasydrillfield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8080000C: addiu       $a0, $zero, 0x40A
    ctx->r4 = ADD32(0, 0X40A);
    // 0x80800010: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800014: jal         0x80089C40
    // 0x80800018: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800018: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x8080001C: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80800020: bltz        $a0, L_80800074
    if (SIGNED(ctx->r4) < 0) {
        // 0x80800024: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800074;
    }
    // 0x80800024: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800028: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8080002C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800030: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x80800034: lw          $a0, 0x6C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X6C);
    // 0x80800038: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8080003C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80800040: srl         $t9, $a0, 21
    ctx->r25 = S32(U32(ctx->r4) >> 21);
    // 0x80800044: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x80800048: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
L_8080004C:
    // 0x8080004C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80800050: lw          $t1, 0x6C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X6C);
    // 0x80800054: srl         $t2, $t1, 21
    ctx->r10 = S32(U32(ctx->r9) >> 21);
    // 0x80800058: sltu        $at, $t2, $a0
    ctx->r1 = ctx->r10 < ctx->r4 ? 1 : 0;
    // 0x8080005C: beql        $at, $zero, L_8080006C
    if (ctx->r1 == 0) {
        // 0x80800060: sltu        $at, $v0, $a1
        ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
            goto L_8080006C;
    }
    goto skip_0;
    // 0x80800060: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    skip_0:
    // 0x80800064: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800068: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
L_8080006C:
    // 0x8080006C: beql        $at, $zero, L_8080004C
    if (ctx->r1 == 0) {
        // 0x80800070: lw          $t0, 0x0($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X0);
            goto L_8080004C;
    }
    goto skip_1;
    // 0x80800070: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    skip_1:
L_80800074:
    // 0x80800074: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2348, 0X8D0) << 16);
    // 0x80800078: addiu       $t4, $t4, 0x8D0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2348, 0X8D0));
    // 0x8080007C: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x80800080: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80800084: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80800088: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8080008C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80800090: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80800094: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800098: jal         0x800EFA4C
    // 0x8080009C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFA4C(rdram, ctx);
        goto after_1;
    // 0x8080009C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x808000A0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808000A8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808000AC: jal         0x80103014
    // 0x808000B0: swc1        $f4, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f4.u32l;
    func_80103014(rdram, ctx);
        goto after_2;
    // 0x808000B0: swc1        $f4, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f4.u32l;
    after_2:
    // 0x808000B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808000BC: jr          $ra
    // 0x808000C0: nop

    return;
    // 0x808000C0: nop

;}
RECOMP_FUNC void bastatetimer_isAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800915E8: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800915EC: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800915F0: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800915F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800915F8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800915FC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80091600: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80091604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80091608: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8009160C: nop

    // 0x80091610: bc1f        L_8009161C
    if (!c1cs) {
        // 0x80091614: nop
    
            goto L_8009161C;
    }
    // 0x80091614: nop

    // 0x80091618: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8009161C:
    // 0x8009161C: beq         $v0, $zero, L_80091640
    if (ctx->r2 == 0) {
        // 0x80091620: nop
    
            goto L_80091640;
    }
    // 0x80091620: nop

    // 0x80091624: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80091628: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009162C: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
    // 0x80091630: nop

    // 0x80091634: bc1f        L_80091640
    if (!c1cs) {
        // 0x80091638: nop
    
            goto L_80091640;
    }
    // 0x80091638: nop

    // 0x8009163C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80091640:
    // 0x80091640: jr          $ra
    // 0x80091644: nop

    return;
    // 0x80091644: nop

;}
RECOMP_FUNC void func_800E0A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0A50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E0A54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E0A58: jal         0x8001B084
    // 0x800E0A5C: nop

    heap_free(rdram, ctx);
        goto after_0;
    // 0x800E0A5C: nop

    after_0:
    // 0x800E0A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E0A64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E0A68: jr          $ra
    // 0x800E0A6C: nop

    return;
    // 0x800E0A6C: nop

;}
RECOMP_FUNC void chlightfader_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1260, 0X3A0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x3A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1260, 0X3A0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x3A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1260, 0X3A0));
;}
RECOMP_FUNC void _glidmake_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088890: syscall     707
    recomp_syscall_handler(rdram, ctx, 0x80088890);
    return;
    // 0x80088894: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800F6634(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6634: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800F6638: jr          $ra
    // 0x800F663C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800F663C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void _cadbmgrDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085570: syscall     167
    recomp_syscall_handler(rdram, ctx, 0x80085570);
    return;
    // 0x80085574: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void subaddieitem_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: jr          $ra
    // 0x8080004C: sb          $a1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r5;
    return;
    // 0x8080004C: sb          $a1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_800A5B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5B7C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5B80: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x800A5B84: jr          $ra
    // 0x800A5B88: lb          $v0, 0x3($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X3);
    return;
    // 0x800A5B88: lb          $v0, 0x3($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X3);
;}
RECOMP_FUNC void _gcfrontend_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088148: syscall     673
    recomp_syscall_handler(rdram, ctx, 0x80088148);
    return;
    // 0x8008814C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801628_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801628: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080162C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801630: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801634: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801638: jal         0x80100094
    // 0x8080163C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080163C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801640: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80801644: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80801648: lw          $v1, 0x28($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X28);
    // 0x8080164C: sll         $t8, $v1, 19
    ctx->r24 = S32(ctx->r3 << 19);
    // 0x80801650: sll         $t0, $v1, 20
    ctx->r8 = S32(ctx->r3 << 20);
    // 0x80801654: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80801658: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x8080165C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80801660: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80801664: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x80801668: sll         $a1, $v1, 18
    ctx->r5 = S32(ctx->r3 << 18);
    // 0x8080166C: srl         $t7, $a1, 31
    ctx->r15 = S32(U32(ctx->r5) >> 31);
    // 0x80801670: srl         $t2, $a0, 10
    ctx->r10 = S32(U32(ctx->r4) >> 10);
    // 0x80801674: slti        $at, $t2, 0xB
    ctx->r1 = SIGNED(ctx->r10) < 0XB ? 1 : 0;
    // 0x80801678: beql        $at, $zero, L_808017E0
    if (ctx->r1 == 0) {
        // 0x8080167C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808017E0;
    }
    goto skip_0;
    // 0x8080167C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801680: beql        $t1, $zero, L_808016FC
    if (ctx->r9 == 0) {
        // 0x80801684: lw          $t4, 0x38($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X38);
            goto L_808016FC;
    }
    goto skip_1;
    // 0x80801684: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x80801688: bne         $t7, $zero, L_808016F8
    if (ctx->r15 != 0) {
        // 0x8080168C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808016F8;
    }
    // 0x8080168C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801690: bne         $t2, $at, L_808016CC
    if (ctx->r10 != ctx->r1) {
        // 0x80801694: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808016CC;
    }
    // 0x80801694: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801698: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080169C: jal         0x800DC298
    // 0x808016A0: nop

    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x808016A0: nop

    after_1:
    // 0x808016A4: beq         $v0, $zero, L_808016F8
    if (ctx->r2 == 0) {
        // 0x808016A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808016F8;
    }
    // 0x808016A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016AC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808016B0: jal         0x80801464
    // 0x808016B4: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    func_80801464_chboilerboss(rdram, ctx);
        goto after_2;
    // 0x808016B4: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    after_2:
    // 0x808016B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016BC: jal         0x808019C8
    // 0x808016C0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_808019C8_chboilerboss(rdram, ctx);
        goto after_3;
    // 0x808016C0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x808016C4: b           L_808016FC
    // 0x808016C8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
        goto L_808016FC;
    // 0x808016C8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
L_808016CC:
    // 0x808016CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A6C) << 16);
    // 0x808016D0: jal         0x800DC298
    // 0x808016D4: lwc1        $f12, 0x2A6C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A6C));
    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x808016D4: lwc1        $f12, 0x2A6C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A6C));
    after_4:
    // 0x808016D8: beq         $v0, $zero, L_808016F8
    if (ctx->r2 == 0) {
        // 0x808016DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808016F8;
    }
    // 0x808016DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016E0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808016E4: jal         0x80801464
    // 0x808016E8: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    func_80801464_chboilerboss(rdram, ctx);
        goto after_5;
    // 0x808016E8: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    after_5:
    // 0x808016EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016F0: jal         0x808019C8
    // 0x808016F4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_808019C8_chboilerboss(rdram, ctx);
        goto after_6;
    // 0x808016F4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_6:
L_808016F8:
    // 0x808016F8: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
L_808016FC:
    // 0x808016FC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80801700: beql        $t4, $zero, L_80801788
    if (ctx->r12 == 0) {
        // 0x80801704: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_80801788;
    }
    goto skip_2;
    // 0x80801704: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    skip_2:
    // 0x80801708: bnel        $t5, $zero, L_80801788
    if (ctx->r13 != 0) {
        // 0x8080170C: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_80801788;
    }
    goto skip_3;
    // 0x8080170C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    skip_3:
    // 0x80801710: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80801714: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801718: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080171C: bne         $t7, $at, L_80801758
    if (ctx->r15 != ctx->r1) {
        // 0x80801720: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80801758;
    }
    // 0x80801720: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80801724: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80801728: jal         0x800DC298
    // 0x8080172C: nop

    func_800DC298(rdram, ctx);
        goto after_7;
    // 0x8080172C: nop

    after_7:
    // 0x80801730: beq         $v0, $zero, L_80801784
    if (ctx->r2 == 0) {
        // 0x80801734: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801784;
    }
    // 0x80801734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801738: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8080173C: jal         0x808014F4
    // 0x80801740: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    func_808014F4_chboilerboss(rdram, ctx);
        goto after_8;
    // 0x80801740: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    after_8:
    // 0x80801744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801748: jal         0x808019C8
    // 0x8080174C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_808019C8_chboilerboss(rdram, ctx);
        goto after_9;
    // 0x8080174C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_9:
    // 0x80801750: b           L_80801788
    // 0x80801754: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
        goto L_80801788;
    // 0x80801754: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
L_80801758:
    // 0x80801758: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A70) << 16);
    // 0x8080175C: jal         0x800DC298
    // 0x80801760: lwc1        $f12, 0x2A70($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A70));
    func_800DC298(rdram, ctx);
        goto after_10;
    // 0x80801760: lwc1        $f12, 0x2A70($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A70));
    after_10:
    // 0x80801764: beq         $v0, $zero, L_80801784
    if (ctx->r2 == 0) {
        // 0x80801768: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801784;
    }
    // 0x80801768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080176C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80801770: jal         0x808014F4
    // 0x80801774: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    func_808014F4_chboilerboss(rdram, ctx);
        goto after_11;
    // 0x80801774: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    after_11:
    // 0x80801778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080177C: jal         0x808019C8
    // 0x80801780: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_808019C8_chboilerboss(rdram, ctx);
        goto after_12;
    // 0x80801780: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_12:
L_80801784:
    // 0x80801784: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
L_80801788:
    // 0x80801788: bnel        $t8, $zero, L_808017E0
    if (ctx->r24 != 0) {
        // 0x8080178C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808017E0;
    }
    goto skip_4;
    // 0x8080178C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80801790: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x80801794: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80801798: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x8080179C: beq         $t0, $at, L_808017DC
    if (ctx->r8 == ctx->r1) {
        // 0x808017A0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(932, 0X2A74) << 16);
            goto L_808017DC;
    }
    // 0x808017A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(932, 0X2A74) << 16);
    // 0x808017A4: jal         0x800DC298
    // 0x808017A8: lwc1        $f12, 0x2A74($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A74));
    func_800DC298(rdram, ctx);
        goto after_13;
    // 0x808017A8: lwc1        $f12, 0x2A74($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(932, 0X2A74));
    after_13:
    // 0x808017AC: beq         $v0, $zero, L_808017DC
    if (ctx->r2 == 0) {
        // 0x808017B0: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_808017DC;
    }
    // 0x808017B0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808017B4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808017B8: jal         0x800EE7F8
    // 0x808017BC: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_14;
    // 0x808017BC: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_14:
    // 0x808017C0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808017C4: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808017C8: jal         0x800EF1B8
    // 0x808017CC: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_15;
    // 0x808017CC: lui         $a2, 0x4296
    ctx->r6 = S32(0X4296 << 16);
    after_15:
    // 0x808017D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017D4: jal         0x80801A08
    // 0x808017D8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80801A08_chboilerboss(rdram, ctx);
        goto after_16;
    // 0x808017D8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_16:
L_808017DC:
    // 0x808017DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808017E0:
    // 0x808017E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808017E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808017E8: jr          $ra
    // 0x808017EC: nop

    return;
    // 0x808017EC: nop

;}
RECOMP_FUNC void func_80800D78_chtiptup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D80: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800D84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D8C: beq         $a1, $at, L_80800DA8
    if (ctx->r5 == ctx->r1) {
        // 0x80800D90: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800DA8;
    }
    // 0x80800D90: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800D94: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800D98: beq         $a1, $at, L_80800DF0
    if (ctx->r5 == ctx->r1) {
        // 0x80800D9C: addiu       $a0, $zero, 0x358
        ctx->r4 = ADD32(0, 0X358);
            goto L_80800DF0;
    }
    // 0x80800D9C: addiu       $a0, $zero, 0x358
    ctx->r4 = ADD32(0, 0X358);
    // 0x80800DA0: b           L_80800E18
    // 0x80800DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E18;
    // 0x80800DA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DA8:
    // 0x80800DA8: jal         0x800F54E4
    // 0x80800DAC: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800DAC: nop

    after_0:
    // 0x80800DB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800DB8: jal         0x800F8300
    // 0x80800DBC: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800F8300(rdram, ctx);
        goto after_1;
    // 0x80800DBC: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800DC0: jal         0x8010A570
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_2;
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DCC: jal         0x80102424
    // 0x80800DD0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800DD0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DD8: jal         0x8008A4B0
    // 0x80800DDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800DDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800DE0: jal         0x800FC660
    // 0x80800DE4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_5;
    // 0x80800DE4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_5:
    // 0x80800DE8: b           L_80800E18
    // 0x80800DEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E18;
    // 0x80800DEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DF0:
    // 0x80800DF0: jal         0x80089C30
    // 0x80800DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800DF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800DF8: beql        $v0, $zero, L_80800E18
    if (ctx->r2 == 0) {
        // 0x80800DFC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800E18;
    }
    goto skip_0;
    // 0x80800DFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800E00: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800E04: b           L_80800E14
    // 0x80800E08: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
        goto L_80800E14;
    // 0x80800E08: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
    // 0x80800E0C: b           L_80800E18
    // 0x80800E10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E18;
    // 0x80800E10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E14:
    // 0x80800E14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E18:
    // 0x80800E18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E24: jr          $ra
    // 0x80800E28: nop

    return;
    // 0x80800E28: nop

;}
RECOMP_FUNC void func_8008E148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E14C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008E154: jal         0x80091570
    // 0x8008E158: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    bastatetimer_isActive(rdram, ctx);
        goto after_0;
    // 0x8008E158: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x8008E15C: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008E160: bne         $t6, $zero, L_8008E190
    if (ctx->r14 != 0) {
        // 0x8008E164: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8008E190;
    }
    // 0x8008E164: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008E168: jal         0x800A3378
    // 0x8008E16C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3378(rdram, ctx);
        goto after_1;
    // 0x8008E16C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008E170: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008E174: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008E178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008E17C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8008E180: nop

    // 0x8008E184: bc1fl       L_8008E194
    if (!c1cs) {
        // 0x8008E188: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008E194;
    }
    goto skip_0;
    // 0x8008E188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008E18C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008E190:
    // 0x8008E190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008E194:
    // 0x8008E194: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008E198: jr          $ra
    // 0x8008E19C: nop

    return;
    // 0x8008E19C: nop

;}
RECOMP_FUNC void func_80800778_cheggsplode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080077C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800780: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800784: jal         0x800D3948
    // 0x80800788: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x80800788: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080078C: bnel        $v0, $zero, L_808007C8
    if (ctx->r2 != 0) {
        // 0x80800790: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007C8;
    }
    goto skip_0;
    // 0x80800790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800794: jal         0x800F6BE4
    // 0x80800798: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F6BE4(rdram, ctx);
        goto after_1;
    // 0x80800798: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8080079C: beql        $v0, $zero, L_808007C8
    if (ctx->r2 == 0) {
        // 0x808007A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808007C8;
    }
    goto skip_1;
    // 0x808007A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808007A4: jal         0x800F6CC8
    // 0x808007A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800F6CC8(rdram, ctx);
        goto after_2;
    // 0x808007A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808007AC: beq         $v0, $zero, L_808007C4
    if (ctx->r2 == 0) {
        // 0x808007B0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808007C4;
    }
    // 0x808007B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007B4: jal         0x80100094
    // 0x808007B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808007B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808007BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808007C0: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
L_808007C4:
    // 0x808007C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007C8:
    // 0x808007C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007CC: jr          $ra
    // 0x808007D0: nop

    return;
    // 0x808007D0: nop

;}
RECOMP_FUNC void subaddiejoy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080000C: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x80800010: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800014: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80800018: jal         0x80016A74
    // 0x8080001C: srl         $a0, $t6, 30
    ctx->r4 = S32(U32(ctx->r14) >> 30);
    func_80016A74(rdram, ctx);
        goto after_0;
    // 0x8080001C: srl         $a0, $t6, 30
    ctx->r4 = S32(U32(ctx->r14) >> 30);
    after_0:
    // 0x80800020: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800024: bne         $v0, $at, L_80800034
    if (ctx->r2 != ctx->r1) {
        // 0x80800028: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800034;
    }
    // 0x80800028: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8080002C: b           L_80800054
    // 0x80800030: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80800054;
    // 0x80800030: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80800034:
    // 0x80800034: jal         0x800E3A80
    // 0x80800038: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800E3A80(rdram, ctx);
        goto after_1;
    // 0x80800038: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8080003C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800040: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800044: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80800048: nop

    // 0x8080004C: addu        $v1, $t9, $v1
    ctx->r3 = ADD32(ctx->r25, ctx->r3);
    // 0x80800050: addiu       $v1, $v1, 0x5A
    ctx->r3 = ADD32(ctx->r3, 0X5A);
L_80800054:
    // 0x80800054: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80800058: jal         0x800136E4
    // 0x8080005C: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x8080005C: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_2:
    // 0x80800060: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800068: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080006C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void func_800F7750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7750: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F7754: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800F7758: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F775C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F7760: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7764: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800F7768: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x800F776C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F7770: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800F7774: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800F7778: beq         $t7, $zero, L_800F778C
    if (ctx->r15 == 0) {
        // 0x800F777C: lw          $s0, 0x5490($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X5490);
            goto L_800F778C;
    }
    // 0x800F777C: lw          $s0, 0x5490($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X5490);
    // 0x800F7780: addiu       $t8, $zero, 0x98
    ctx->r24 = ADD32(0, 0X98);
    // 0x800F7784: b           L_800F7794
    // 0x800F7788: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_800F7794;
    // 0x800F7788: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_800F778C:
    // 0x800F778C: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800F7790: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_800F7794:
    // 0x800F7794: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800F7798: jal         0x8009ACF4
    // 0x800F779C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009ACF4(rdram, ctx);
        goto after_0;
    // 0x800F779C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800F77A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F77A4: jal         0x8009AD04
    // 0x800F77A8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_8009AD04(rdram, ctx);
        goto after_1;
    // 0x800F77A8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x800F77AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F77B0: jal         0x8009AD20
    // 0x800F77B4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8009AD20(rdram, ctx);
        goto after_2;
    // 0x800F77B4: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_2:
    // 0x800F77B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F77BC: jal         0x8009AD44
    // 0x800F77C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8009AD44(rdram, ctx);
        goto after_3;
    // 0x800F77C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800F77C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F77C8: jal         0x8009E7C8
    // 0x800F77CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009E7C8(rdram, ctx);
        goto after_4;
    // 0x800F77CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x800F77D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F77D4: xori        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 ^ 0X2;
    // 0x800F77D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F77DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F77E0: jr          $ra
    // 0x800F77E4: sltiu       $v0, $t0, 0x1
    ctx->r2 = ctx->r8 < 0X1 ? 1 : 0;
    return;
    // 0x800F77E4: sltiu       $v0, $t0, 0x1
    ctx->r2 = ctx->r8 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void _chiciclebits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086368: syscall     313
    recomp_syscall_handler(rdram, ctx, 0x80086368);
    return;
    // 0x8008636C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void baeggsetup_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800524: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800528: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080052C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800530: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800534: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800538: jal         0x80094C0C
    // 0x8080053C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80094C0C(rdram, ctx);
        goto after_0;
    // 0x8080053C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800540: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80800544: jal         0x800EE7F8
    // 0x80800548: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800548: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8080054C: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80800550: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800554: jal         0x800EE7F8
    // 0x80800558: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800558: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_2:
    // 0x8080055C: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80800560: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800564: jal         0x800EE7F8
    // 0x80800568: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800568: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_3:
    // 0x8080056C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800570: lw          $t7, 0x70($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X70);
    // 0x80800574: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800578: addiu       $a0, $a0, 0x4A58
    ctx->r4 = ADD32(ctx->r4, 0X4A58);
    // 0x8080057C: sb          $t6, 0x24($t7)
    MEM_B(0X24, ctx->r15) = ctx->r14;
    // 0x80800580: jal         0x80086D30
    // 0x80800584: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800584: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    after_4:
    // 0x80800588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080058C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800590: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800594: jr          $ra
    // 0x80800598: nop

    return;
    // 0x80800598: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A1A8: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A1A8);
    return;
    // 0x8008A1AC: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_80801C44_sucoasterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801C50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801C54: jal         0x80100094
    // 0x80801C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801C5C: lbu         $a0, 0x11($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X11);
    // 0x80801C60: srl         $t6, $a0, 4
    ctx->r14 = S32(U32(ctx->r4) >> 4);
    // 0x80801C64: jal         0x8008A270
    // 0x80801C68: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    _sucoasterflydata_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80801C68: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x80801C6C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80801C70: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x80801C74: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80801C78: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x80801C7C: addu        $t0, $v0, $t7
    ctx->r8 = ADD32(ctx->r2, ctx->r15);
    // 0x80801C80: beql        $t9, $zero, L_80801CC4
    if (ctx->r25 == 0) {
        // 0x80801C84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801CC4;
    }
    goto skip_0;
    // 0x80801C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801C88: lh          $t1, 0xA($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XA);
    // 0x80801C8C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80801C90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801C94: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80801C98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801C9C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80801CA0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80801CA4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80801CA8: jal         0x80101E14
    // 0x80801CAC: nop

    func_80101E14(rdram, ctx);
        goto after_2;
    // 0x80801CAC: nop

    after_2:
    // 0x80801CB0: beq         $v0, $zero, L_80801CC0
    if (ctx->r2 == 0) {
        // 0x80801CB4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801CC0;
    }
    // 0x80801CB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801CB8: jal         0x80801CD0
    // 0x80801CBC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80801CD0_sucoasterfly(rdram, ctx);
        goto after_3;
    // 0x80801CBC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
L_80801CC0:
    // 0x80801CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801CC4:
    // 0x80801CC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801CC8: jr          $ra
    // 0x80801CCC: nop

    return;
    // 0x80801CCC: nop

;}
RECOMP_FUNC void func_800A5598(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5598: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A559C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A55A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A55A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A55A8: lhu         $a0, 0x1A($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X1A);
    // 0x800A55AC: srl         $t7, $a0, 5
    ctx->r15 = S32(U32(ctx->r4) >> 5);
    // 0x800A55B0: jal         0x800A93E4
    // 0x800A55B4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800A93E4(rdram, ctx);
        goto after_0;
    // 0x800A55B4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x800A55B8: jal         0x80110014
    // 0x800A55BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x800A55BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A55C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A55C4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800A55C8: jal         0x800893B0
    // 0x800A55CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    _ncbaspline_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x800A55CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800A55D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A55D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A55D8: jr          $ra
    // 0x800A55DC: nop

    return;
    // 0x800A55DC: nop

;}
RECOMP_FUNC void func_8010CEAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CEAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010CEB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CEB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8010CEB8: jal         0x8010D600
    // 0x8010CEBC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D600(rdram, ctx);
        goto after_0;
    // 0x8010CEBC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8010CEC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8010CEC4: jal         0x80102D78
    // 0x8010CEC8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x8010CEC8: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8010CECC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8010CED0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x8010CED4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8010CED8: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x8010CEDC: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    // 0x8010CEE0: jal         0x80102BF8
    // 0x8010CEE4: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_80102BF8(rdram, ctx);
        goto after_2;
    // 0x8010CEE4: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_2:
    // 0x8010CEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CEEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010CEF0: jr          $ra
    // 0x8010CEF4: nop

    return;
    // 0x8010CEF4: nop

;}
RECOMP_FUNC void anseq_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800324: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080032C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800330: jal         0x8001B668
    // 0x80800334: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8001B668(rdram, ctx);
        goto after_0;
    // 0x80800334: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800338: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x8080033C: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80800340: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x80800344: jal         0x8001B798
    // 0x80800348: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x80800348: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x8080034C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80800350: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800354: jal         0x800B2DC0
    // 0x80800358: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800B2DC0(rdram, ctx);
        goto after_2;
    // 0x80800358: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8080035C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800360: jal         0x8080010C
    // 0x80800364: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    anseq_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800364: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    after_3:
    // 0x80800368: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080036C: lh          $v0, 0x1A($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1A);
    // 0x80800370: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800374: jr          $ra
    // 0x80800378: nop

    return;
    // 0x80800378: nop

;}
RECOMP_FUNC void _chcredits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B18: syscall     416
    recomp_syscall_handler(rdram, ctx, 0x80086B18);
    return;
    // 0x80086B1C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800000_chlagoonufoext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800008: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080000C: beq         $a1, $at, L_80800030
    if (ctx->r5 == ctx->r1) {
        // 0x80800010: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_80800030;
    }
    // 0x80800010: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800014: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800018: beq         $a1, $at, L_80800084
    if (ctx->r5 == ctx->r1) {
        // 0x8080001C: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800084;
    }
    // 0x8080001C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800020: beq         $a1, $at, L_80800094
    if (ctx->r5 == ctx->r1) {
        // 0x80800024: nop
    
            goto L_80800094;
    }
    // 0x80800024: nop

    // 0x80800028: b           L_80800158
    // 0x8080002C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800158;
    // 0x8080002C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800030:
    // 0x80800030: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800034: bne         $a2, $at, L_8080007C
    if (ctx->r6 != ctx->r1) {
        // 0x80800038: nop
    
            goto L_8080007C;
    }
    // 0x80800038: nop

    // 0x8080003C: jal         0x800DA544
    // 0x80800040: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    func_800DA544(rdram, ctx);
        goto after_0;
    // 0x80800040: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    after_0:
    // 0x80800044: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800048: jal         0x80100094
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080004C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800050: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800054: jal         0x8008A2C0
    // 0x80800058: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800058: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8080005C: jal         0x80088238
    // 0x80800060: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    _gclevel_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800060: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_3:
    // 0x80800064: beq         $v0, $zero, L_80800074
    if (ctx->r2 == 0) {
        // 0x80800068: addiu       $a0, $zero, 0x128
        ctx->r4 = ADD32(0, 0X128);
            goto L_80800074;
    }
    // 0x80800068: addiu       $a0, $zero, 0x128
    ctx->r4 = ADD32(0, 0X128);
    // 0x8080006C: jal         0x800887D8
    // 0x80800070: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800070: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    after_4:
L_80800074:
    // 0x80800074: b           L_80800158
    // 0x80800078: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800158;
    // 0x80800078: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8080007C:
    // 0x8080007C: b           L_80800158
    // 0x80800080: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800158;
    // 0x80800080: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800084:
    // 0x80800084: jal         0x808002A4
    // 0x80800088: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808002A4_chlagoonufoext(rdram, ctx);
        goto after_5;
    // 0x80800088: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x8080008C: b           L_80800158
    // 0x80800090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800158;
    // 0x80800090: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800094:
    // 0x80800094: jal         0x800DA298
    // 0x80800098: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800098: addiu       $a0, $zero, 0x9F0
    ctx->r4 = ADD32(0, 0X9F0);
    after_6:
    // 0x8080009C: beql        $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x808000A0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800158;
    }
    goto skip_0;
    // 0x808000A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808000A4: jal         0x80090178
    // 0x808000A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090178(rdram, ctx);
        goto after_7;
    // 0x808000A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x808000AC: beql        $v0, $zero, L_80800158
    if (ctx->r2 == 0) {
        // 0x808000B0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800158;
    }
    goto skip_1;
    // 0x808000B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808000B4: jal         0x800EA090
    // 0x808000B8: nop

    func_800EA090(rdram, ctx);
        goto after_8;
    // 0x808000B8: nop

    after_8:
    // 0x808000BC: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x808000C0: bnel        $v0, $at, L_80800158
    if (ctx->r2 != ctx->r1) {
        // 0x808000C4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800158;
    }
    goto skip_2;
    // 0x808000C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808000C8: jal         0x800F54E4
    // 0x808000CC: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x808000CC: nop

    after_9:
    // 0x808000D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808000D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000D8: jal         0x800F608C
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F608C(rdram, ctx);
        goto after_10;
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x808000E0: jal         0x800F497C
    // 0x808000E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800F497C(rdram, ctx);
        goto after_11;
    // 0x808000E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x808000E8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808000EC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x808000F0: addiu       $a1, $a1, -0x2A24
    ctx->r5 = ADD32(ctx->r5, -0X2A24);
    // 0x808000F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808000F8: jal         0x800F49D4
    // 0x808000FC: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    func_800F49D4(rdram, ctx);
        goto after_12;
    // 0x808000FC: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    after_12:
    // 0x80800100: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800104: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800108: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x8080010C: jal         0x800F4AC0
    // 0x80800110: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800F4AC0(rdram, ctx);
        goto after_13;
    // 0x80800110: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_13:
    // 0x80800114: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800118: jal         0x80100094
    // 0x8080011C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_14;
    // 0x8080011C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80800120: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800124: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800128: addiu       $a2, $zero, 0x42
    ctx->r6 = ADD32(0, 0X42);
    // 0x8080012C: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x80800130: jal         0x8008A2D0
    // 0x80800134: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_15;
    // 0x80800134: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_15:
    // 0x80800138: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080013C: jal         0x80102424
    // 0x80800140: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x80800140: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_16:
    // 0x80800144: b           L_80800158
    // 0x80800148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800158;
    // 0x80800148: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080014C: b           L_80800158
    // 0x80800150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800158;
    // 0x80800150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800158:
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080015C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

;}
RECOMP_FUNC void func_800AF5E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF5E4: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800AF5E8: jr          $ra
    // 0x800AF5EC: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    return;
    // 0x800AF5EC: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
;}
RECOMP_FUNC void bstrexsmall_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801704: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801708: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1B98) << 16);
    // 0x8080170C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801710: jr          $ra
    // 0x80801714: lw          $v0, 0x1B98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B98));
    return;
    // 0x80801714: lw          $v0, 0x1B98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B98));
;}
RECOMP_FUNC void func_80806F8C_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806F8C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80806F90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80806F94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80806F98: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80806F9C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80806FA0: jal         0x80802228
    // 0x80806FA4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x80806FA4: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80806FA8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80806FAC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80806FB0: jal         0x80802298
    // 0x80806FB4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80802298_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80806FB4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x80806FB8: lui         $a1, 0x8081
    ctx->r5 = S32(RELOC_HI16(1480, 0XA134) << 16);
    // 0x80806FBC: addiu       $a1, $a1, -0x5ECC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1480, 0XA134));
    // 0x80806FC0: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80806FC4: jal         0x800F1E6C
    // 0x80806FC8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800F1E6C(rdram, ctx);
        goto after_2;
    // 0x80806FC8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x80806FCC: bne         $v0, $zero, L_80806FE0
    if (ctx->r2 != 0) {
        // 0x80806FD0: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80806FE0;
    }
    // 0x80806FD0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80806FD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80806FD8: nop

    // 0x80806FDC: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
L_80806FE0:
    // 0x80806FE0: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80806FE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80806FE8: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80806FEC: jal         0x800F2094
    // 0x80806FF0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    func_800F2094(rdram, ctx);
        goto after_3;
    // 0x80806FF0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_3:
    // 0x80806FF4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80806FF8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80806FFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80807000: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80807004: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80807008: jal         0x800F2094
    // 0x8080700C: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    func_800F2094(rdram, ctx);
        goto after_4;
    // 0x8080700C: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    after_4:
    // 0x80807010: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80807014: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80807018: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080701C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80807020: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80807024: bc1fl       L_8080703C
    if (!c1cs) {
        // 0x80807028: lwc1        $f8, 0x48($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
            goto L_8080703C;
    }
    goto skip_0;
    // 0x80807028: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    skip_0:
    // 0x8080702C: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80807030: b           L_80807040
    // 0x80807034: add.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f12.fl;
        goto L_80807040;
    // 0x80807034: add.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80807038: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
L_8080703C:
    // 0x8080703C: sub.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f12.fl;
L_80807040:
    // 0x80807040: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80807044: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80807048: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080704C: jal         0x800DC178
    // 0x80807050: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80807050: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x80807054: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80807058: jal         0x800858E0
    // 0x8080705C: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
    _chbounce_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x8080705C: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
    after_6:
    // 0x80807060: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80807064: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80807068: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8080706C: addiu       $a0, $a0, 0x6D78
    ctx->r4 = ADD32(ctx->r4, 0X6D78);
    // 0x80807070: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80807074: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80807078: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8080707C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80807080: jal         0x80086D50
    // 0x80807084: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    _chbaddiesetup_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80807084: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_7:
    // 0x80807088: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8080708C: lui         $a2, 0x8081
    ctx->r6 = S32(RELOC_HI16(1480, 0XA120) << 16);
    // 0x80807090: addiu       $a2, $a2, -0x5EE0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1480, 0XA120));
    // 0x80807094: jal         0x80089D18
    // 0x80807098: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80807098: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_8:
    // 0x8080709C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808070A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808070A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808070A8: jr          $ra
    // 0x808070AC: nop

    return;
    // 0x808070AC: nop

;}
RECOMP_FUNC void _suegg_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A3B8: syscall     841
    recomp_syscall_handler(rdram, ctx, 0x8008A3B8);
    return;
    // 0x8008A3BC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void sucoaster_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801BF0: jal         0x80101870
    // 0x80801BF4: nop

    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80801BF4: nop

    after_0:
    // 0x80801BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C00: jr          $ra
    // 0x80801C04: nop

    return;
    // 0x80801C04: nop

;}
RECOMP_FUNC void _subaddierouteDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F68: syscall     818
    recomp_syscall_handler(rdram, ctx, 0x80089F68);
    return;
    // 0x80089F6C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801058_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080105C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801060: jal         0x80085240
    // 0x80801064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _basudie_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80801064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801068: jal         0x80800E54
    // 0x8080106C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstnt_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x8080106C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801078: jr          $ra
    // 0x8080107C: nop

    return;
    // 0x8080107C: nop

;}
RECOMP_FUNC void _chmrsicecube_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086318: syscall     307
    recomp_syscall_handler(rdram, ctx, 0x80086318);
    return;
    // 0x8008631C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
