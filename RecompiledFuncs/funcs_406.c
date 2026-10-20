#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8001A570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A570: jr          $ra
    // 0x8001A574: nop

    return;
    // 0x8001A574: nop

;}
RECOMP_FUNC void func_8080035C_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080035C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800360: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80800364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800368: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8080036C: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80800370: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80800374: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x80800378: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8080037C: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x80800380: lw          $a2, 0x44($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X44);
    // 0x80800384: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800388: beq         $a2, $zero, L_808003B8
    if (ctx->r6 == 0) {
        // 0x8080038C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808003B8;
    }
    // 0x8080038C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800390: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80800394: jal         0x80087A38
    // 0x80800398: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _dbtex_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800398: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080039C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808003A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808003A4: lw          $t7, 0x68($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X68);
    // 0x808003A8: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x808003AC: sw          $zero, 0x44($t8)
    MEM_W(0X44, ctx->r24) = 0;
    // 0x808003B0: lw          $t9, 0x68($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X68);
    // 0x808003B4: addu        $v0, $t9, $v1
    ctx->r2 = ADD32(ctx->r25, ctx->r3);
L_808003B8:
    // 0x808003B8: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x808003BC: beql        $a0, $zero, L_808003E8
    if (ctx->r4 == 0) {
        // 0x808003C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003E8;
    }
    goto skip_0;
    // 0x808003C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808003C4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x808003C8: jal         0x80087A38
    // 0x808003CC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _dbtex_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808003CC: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x808003D0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808003D4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808003D8: lw          $t0, 0x68($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X68);
    // 0x808003DC: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x808003E0: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
    // 0x808003E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003E8:
    // 0x808003E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003EC: jr          $ra
    // 0x808003F0: nop

    return;
    // 0x808003F0: nop

;}
RECOMP_FUNC void glgamestore_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800188: jal         0x80800038
    // 0x8080018C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800038_glgamestore(rdram, ctx);
        goto after_0;
    // 0x8080018C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800190: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800194: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800198: jal         0x8080013C
    // 0x8080019C: addiu       $a2, $zero, 0x1C0
    ctx->r6 = ADD32(0, 0X1C0);
    func_8080013C_glgamestore(rdram, ctx);
        goto after_1;
    // 0x8080019C: addiu       $a2, $zero, 0x1C0
    ctx->r6 = ADD32(0, 0X1C0);
    after_1:
    // 0x808001A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A8: jr          $ra
    // 0x808001AC: nop

    return;
    // 0x808001AC: nop

;}
RECOMP_FUNC void func_800AB868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB868: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800AB86C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AB870: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800AB874: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800AB878: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800AB87C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800AB880: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800AB884: jal         0x80019CD4
    // 0x800AB888: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_80019CD4(rdram, ctx);
        goto after_0;
    // 0x800AB888: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800AB88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AB890: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800AB894: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800AB898: jal         0x8001980C
    // 0x800AB89C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8001980C(rdram, ctx);
        goto after_1;
    // 0x800AB89C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800AB8A0: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800AB8A4: jal         0x800193C4
    // 0x800AB8A8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_800193C4(rdram, ctx);
        goto after_2;
    // 0x800AB8A8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_2:
    // 0x800AB8AC: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
    // 0x800AB8B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800AB8B4: jal         0x800193C4
    // 0x800AB8B8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    func_800193C4(rdram, ctx);
        goto after_3;
    // 0x800AB8B8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_3:
    // 0x800AB8BC: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x800AB8C0: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x800AB8C4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800AB8C8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800AB8CC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x800AB8D0: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x800AB8D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800AB8D8: jal         0x800AB0BC
    // 0x800AB8DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_800AB0BC(rdram, ctx);
        goto after_4;
    // 0x800AB8DC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_4:
    // 0x800AB8E0: bne         $v0, $zero, L_800AB8F0
    if (ctx->r2 != 0) {
        // 0x800AB8E4: sw          $v0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r2;
            goto L_800AB8F0;
    }
    // 0x800AB8E4: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800AB8E8: b           L_800AB96C
    // 0x800AB8EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AB96C;
    // 0x800AB8EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AB8F0:
    // 0x800AB8F0: jal         0x80019CD4
    // 0x800AB8F4: nop

    func_80019CD4(rdram, ctx);
        goto after_5;
    // 0x800AB8F4: nop

    after_5:
    // 0x800AB8F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800AB8FC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800AB900: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x800AB904: jal         0x80019750
    // 0x800AB908: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80019750(rdram, ctx);
        goto after_6;
    // 0x800AB908: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x800AB90C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800AB910: jal         0x800193C4
    // 0x800AB914: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800193C4(rdram, ctx);
        goto after_7;
    // 0x800AB914: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800AB918: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800AB91C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800AB920: addiu       $s1, $s1, 0x795C
    ctx->r17 = ADD32(ctx->r17, 0X795C);
    // 0x800AB924: addiu       $s0, $s0, 0x7938
    ctx->r16 = ADD32(ctx->r16, 0X7938);
    // 0x800AB928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800AB92C:
    // 0x800AB92C: jal         0x80019224
    // 0x800AB930: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80019224(rdram, ctx);
        goto after_8;
    // 0x800AB930: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800AB934: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800AB938: bnel        $s0, $s1, L_800AB92C
    if (ctx->r16 != ctx->r17) {
        // 0x800AB93C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800AB92C;
    }
    goto skip_0;
    // 0x800AB93C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x800AB940: jal         0x80019CD4
    // 0x800AB944: nop

    func_80019CD4(rdram, ctx);
        goto after_9;
    // 0x800AB944: nop

    after_9:
    // 0x800AB948: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AB94C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x800AB950: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800AB954: jal         0x80019750
    // 0x800AB958: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80019750(rdram, ctx);
        goto after_10;
    // 0x800AB958: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x800AB95C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x800AB960: jal         0x80019224
    // 0x800AB964: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_80019224(rdram, ctx);
        goto after_11;
    // 0x800AB964: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_11:
    // 0x800AB968: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
L_800AB96C:
    // 0x800AB96C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AB970: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800AB974: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800AB978: jr          $ra
    // 0x800AB97C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800AB97C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _bsbfly_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082980: syscall     22
    recomp_syscall_handler(rdram, ctx, 0x80082980);
    return;
    // 0x80082984: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_800DCF48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DCF48: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800DCF4C: lw          $a2, -0x3698($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X3698);
    // 0x800DCF50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DCF54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DCF58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DCF5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DCF60: beq         $a2, $zero, L_800DCFC0
    if (ctx->r6 == 0) {
        // 0x800DCF64: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800DCFC0;
    }
    // 0x800DCF64: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800DCF68: lb          $a1, 0x9($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X9);
    // 0x800DCF6C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800DCF70: jal         0x800ADE2C
    // 0x800DCF74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800ADE2C(rdram, ctx);
        goto after_0;
    // 0x800DCF74: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    tooie_snout_bone(rdram, ctx);
    // 0x800DCF78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DCF7C: addiu       $a0, $a0, -0x31A8
    ctx->r4 = ADD32(ctx->r4, -0X31A8);
    // 0x800DCF80: jal         0x80019AA0
    // 0x800DCF84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80019AA0(rdram, ctx);
        goto after_1;
    // 0x800DCF84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800DCF88: jal         0x80018C28
    // 0x800DCF8C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_2;
    // 0x800DCF8C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x800DCF90: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800DCF94: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x800DCF98: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800DCF9C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800DCFA0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800DCFA4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800DCFA8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800DCFAC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800DCFB0: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800DCFB4: addiu       $t0, $t9, 0x40
    ctx->r8 = ADD32(ctx->r25, 0X40);
    // 0x800DCFB8: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x800DCFBC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_800DCFC0:
    // 0x800DCFC0: lbu         $v0, 0x8($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X8);
    // 0x800DCFC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800DCFC8: beq         $v0, $zero, L_800DCFD8
    if (ctx->r2 == 0) {
        // 0x800DCFCC: nop
    
            goto L_800DCFD8;
    }
    // 0x800DCFCC: nop

    // 0x800DCFD0: jal         0x800DE2A4
    // 0x800DCFD4: addu        $a1, $a3, $v0
    ctx->r5 = ADD32(ctx->r7, ctx->r2);
    func_800DE2A4(rdram, ctx);
        goto after_3;
    // 0x800DCFD4: addu        $a1, $a3, $v0
    ctx->r5 = ADD32(ctx->r7, ctx->r2);
    after_3:
L_800DCFD8:
    // 0x800DCFD8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800DCFDC: lw          $t1, -0x3698($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X3698);
    // 0x800DCFE0: beql        $t1, $zero, L_800DD014
    if (ctx->r9 == 0) {
        // 0x800DCFE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DD014;
    }
    goto skip_0;
    // 0x800DCFE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800DCFE8: jal         0x80018DAC
    // 0x800DCFEC: nop

    mlMtxPop(rdram, ctx);
        goto after_4;
    // 0x800DCFEC: nop

    after_4:
    // 0x800DCFF0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800DCFF4: lui         $t3, 0xD838
    ctx->r11 = S32(0XD838 << 16);
    // 0x800DCFF8: ori         $t3, $t3, 0x2
    ctx->r11 = ctx->r11 | 0X2;
    // 0x800DCFFC: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800DD000: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x800DD004: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x800DD008: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800DD00C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800DD010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DD014:
    // 0x800DD014: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DD018: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DD01C: jr          $ra
    // 0x800DD020: nop

    return;
    // 0x800DD020: nop

;}
RECOMP_FUNC void chnewmumbo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801874: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1584, 0X1B14) << 16);
    // 0x80801878: jr          $ra
    // 0x8080187C: addiu       $v0, $v0, 0x1B14
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1584, 0X1B14));
    return;
    // 0x8080187C: addiu       $v0, $v0, 0x1B14
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1584, 0X1B14));
;}
RECOMP_FUNC void _bssnowball_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A38: syscall     87
    recomp_syscall_handler(rdram, ctx, 0x80083A38);
    return;
    // 0x80083A3C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808002B4_chdingpot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002B8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1176, 0X5B4) << 16);
    // 0x808002BC: lw          $t6, 0x5B4($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(1176, 0X5B4));
    // 0x808002C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002CC: jal         0x80101E4C
    // 0x808002D0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80101E4C(rdram, ctx);
        goto after_0;
    // 0x808002D0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x808002D4: beql        $v0, $zero, L_80800340
    if (ctx->r2 == 0) {
        // 0x808002D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800340;
    }
    goto skip_0;
    // 0x808002D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002DC: lbu         $t7, 0x5F($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5F);
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: bnel        $t7, $zero, L_808002FC
    if (ctx->r15 != 0) {
        // 0x808002E8: addiu       $t8, $s0, 0x4
        ctx->r24 = ADD32(ctx->r16, 0X4);
            goto L_808002FC;
    }
    goto skip_1;
    // 0x808002E8: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x808002EC: jal         0x80089D10
    // 0x808002F0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808002F0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x808002F4: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x808002F8: addiu       $t8, $s0, 0x4
    ctx->r24 = ADD32(ctx->r16, 0X4);
L_808002FC:
    // 0x808002FC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80800300: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800304: jal         0x800DC128
    // 0x80800308: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DC128(rdram, ctx);
        goto after_2;
    // 0x80800308: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080030C: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80800310: addu        $a1, $sp, $t9
    ctx->r5 = ADD32(ctx->r29, ctx->r25);
    // 0x80800314: lh          $a1, 0x2C($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X2C);
    // 0x80800318: jal         0x800C301C
    // 0x8080031C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C301C(rdram, ctx);
        goto after_3;
    // 0x8080031C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_3:
    // 0x80800320: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1176, 0X5B8) << 16);
    // 0x80800324: addiu       $a2, $a2, 0x5B8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1176, 0X5B8));
    // 0x80800328: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x8080032C: jal         0x800C4350
    // 0x80800330: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800C4350(rdram, ctx);
        goto after_4;
    // 0x80800330: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800334: jal         0x800C3BDC
    // 0x80800338: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C3BDC(rdram, ctx);
        goto after_5;
    // 0x80800338: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_5:
    // 0x8080033C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800340:
    // 0x80800340: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800344: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800348: jr          $ra
    // 0x8080034C: nop

    return;
    // 0x8080034C: nop

;}
RECOMP_FUNC void func_808000E0_chbadshad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808000E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000EC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x808000F0: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808000F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000FC: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80800100: bltzl       $t8, L_8080027C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800104: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080027C;
    }
    goto skip_0;
    // 0x80800104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800108: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8080010C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80800110: lw          $a0, 0x40($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X40);
    // 0x80800114: beq         $a0, $zero, L_80800128
    if (ctx->r4 == 0) {
        // 0x80800118: nop
    
            goto L_80800128;
    }
    // 0x80800118: nop

    // 0x8080011C: jal         0x80106790
    // 0x80800120: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800120: nop

    after_0:
    // 0x80800124: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800128:
    // 0x80800128: beq         $a1, $zero, L_80800144
    if (ctx->r5 == 0) {
        // 0x8080012C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80800144;
    }
    // 0x8080012C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800130: jal         0x80089C90
    // 0x80800134: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800134: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x80800138: jal         0x800DF410
    // 0x8080013C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF410(rdram, ctx);
        goto after_2;
    // 0x8080013C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800140: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
L_80800144:
    // 0x80800144: beq         $a1, $zero, L_80800164
    if (ctx->r5 == 0) {
        // 0x80800148: lui         $a2, 0x4448
        ctx->r6 = S32(0X4448 << 16);
            goto L_80800164;
    }
    // 0x80800148: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    // 0x8080014C: lw          $t9, 0x74($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X74);
    // 0x80800150: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800154: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800158: sll         $t1, $t9, 5
    ctx->r9 = S32(ctx->r25 << 5);
    // 0x8080015C: bltzl       $t1, L_80800198
    if (SIGNED(ctx->r9) < 0) {
        // 0x80800160: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80800198;
    }
    goto skip_1;
    // 0x80800160: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_1:
L_80800164:
    // 0x80800164: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(684, 0XA00) << 16);
    // 0x80800168: lwc1        $f6, 0xA00($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(684, 0XA00));
    // 0x8080016C: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800170: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800174: lui         $a3, 0x3F07
    ctx->r7 = S32(0X3F07 << 16);
    // 0x80800178: ori         $a3, $a3, 0xAE14
    ctx->r7 = ctx->r7 | 0XAE14;
    // 0x8080017C: jal         0x800F10B4
    // 0x80800180: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800180: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80800184: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800188: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8080018C: b           L_808001A4
    // 0x80800190: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
        goto L_808001A4;
    // 0x80800190: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80800194: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80800198:
    // 0x80800198: nop

    // 0x8080019C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808001A0: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
L_808001A4:
    // 0x808001A4: jal         0x800DF470
    // 0x808001A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF470(rdram, ctx);
        goto after_4;
    // 0x808001A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x808001AC: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x808001B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001B4: jal         0x800DF428
    // 0x808001B8: nop

    func_800DF428(rdram, ctx);
        goto after_5;
    // 0x808001B8: nop

    after_5:
    // 0x808001BC: lhu         $a0, 0x7A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X7A);
    // 0x808001C0: srl         $t2, $a0, 14
    ctx->r10 = S32(U32(ctx->r4) >> 14);
    // 0x808001C4: jal         0x800DF830
    // 0x808001C8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    func_800DF830(rdram, ctx);
        goto after_6;
    // 0x808001C8: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_6:
    // 0x808001CC: lhu         $t3, 0x7A($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X7A);
    // 0x808001D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001D4: srl         $t4, $t3, 14
    ctx->r12 = S32(U32(ctx->r11) >> 14);
    // 0x808001D8: bne         $t4, $at, L_80800228
    if (ctx->r12 != ctx->r1) {
        // 0x808001DC: nop
    
            goto L_80800228;
    }
    // 0x808001DC: nop

    // 0x808001E0: jal         0x801039E4
    // 0x808001E4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_7;
    // 0x808001E4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x808001E8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001EC: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x808001F0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x808001F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808001F8: jal         0x800DE448
    // 0x808001FC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800DE448(rdram, ctx);
        goto after_8;
    // 0x808001FC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x80800200: beql        $v0, $zero, L_8080021C
    if (ctx->r2 == 0) {
        // 0x80800204: lbu         $t8, 0x7E($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X7E);
            goto L_8080021C;
    }
    goto skip_2;
    // 0x80800204: lbu         $t8, 0x7E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X7E);
    skip_2:
    // 0x80800208: lbu         $t6, 0x7E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7E);
    // 0x8080020C: ori         $t7, $t6, 0x10
    ctx->r15 = ctx->r14 | 0X10;
    // 0x80800210: b           L_80800278
    // 0x80800214: sb          $t7, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r15;
        goto L_80800278;
    // 0x80800214: sb          $t7, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r15;
    // 0x80800218: lbu         $t8, 0x7E($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X7E);
L_8080021C:
    // 0x8080021C: andi        $t9, $t8, 0xFFEF
    ctx->r25 = ctx->r24 & 0XFFEF;
    // 0x80800220: b           L_80800278
    // 0x80800224: sb          $t9, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r25;
        goto L_80800278;
    // 0x80800224: sb          $t9, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r25;
L_80800228:
    // 0x80800228: jal         0x80101918
    // 0x8080022C: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    func_80101918(rdram, ctx);
        goto after_9;
    // 0x8080022C: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    after_9:
    // 0x80800230: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800234: jal         0x801039E4
    // 0x80800238: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_10;
    // 0x80800238: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x8080023C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800240: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80800244: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80800248: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8080024C: jal         0x800DE448
    // 0x80800250: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800DE448(rdram, ctx);
        goto after_11;
    // 0x80800250: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_11:
    // 0x80800254: beql        $v0, $zero, L_80800270
    if (ctx->r2 == 0) {
        // 0x80800258: lbu         $t3, 0x7E($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X7E);
            goto L_80800270;
    }
    goto skip_3;
    // 0x80800258: lbu         $t3, 0x7E($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7E);
    skip_3:
    // 0x8080025C: lbu         $t1, 0x7E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X7E);
    // 0x80800260: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x80800264: b           L_80800278
    // 0x80800268: sb          $t2, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r10;
        goto L_80800278;
    // 0x80800268: sb          $t2, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r10;
    // 0x8080026C: lbu         $t3, 0x7E($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X7E);
L_80800270:
    // 0x80800270: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x80800274: sb          $t4, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r12;
L_80800278:
    // 0x80800278: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080027C:
    // 0x8080027C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800280: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800284: jr          $ra
    // 0x80800288: nop

    return;
    // 0x80800288: nop

;}
RECOMP_FUNC void _chbadshad_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085780: syscall     173
    recomp_syscall_handler(rdram, ctx, 0x80085780);
    return;
    // 0x80085784: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800FB3C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB3C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FB3C4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800FB3C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FB3CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800FB3D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800FB3D4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800FB3D8: jal         0x800EEB40
    // 0x800FB3DC: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    func_800EEB40(rdram, ctx);
        goto after_0;
    // 0x800FB3DC: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800FB3E0: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800FB3E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800FB3E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800FB3EC: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800FB3F0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800FB3F4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800FB3F8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800FB3FC: nop

    // 0x800FB400: bc1fl       L_800FB414
    if (!c1cs) {
        // 0x800FB404: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_800FB414;
    }
    goto skip_0;
    // 0x800FB404: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x800FB408: b           L_800FB424
    // 0x800FB40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FB424;
    // 0x800FB40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FB410: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
L_800FB414:
    // 0x800FB414: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800FB418: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800FB41C: jal         0x800C6B78
    // 0x800FB420: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_800C6B78(rdram, ctx);
        goto after_1;
    // 0x800FB420: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
L_800FB424:
    // 0x800FB424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB428: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800FB42C: jr          $ra
    // 0x800FB430: nop

    return;
    // 0x800FB430: nop

;}
RECOMP_FUNC void func_800F8850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8858: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x800F885C: jal         0x800F47C0
    // 0x800F8860: addiu       $a0, $a0, -0x77D0
    ctx->r4 = ADD32(ctx->r4, -0X77D0);
    func_800F47C0(rdram, ctx);
        goto after_0;
    // 0x800F8860: addiu       $a0, $a0, -0x77D0
    ctx->r4 = ADD32(ctx->r4, -0X77D0);
    after_0:
    // 0x800F8864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F886C: jr          $ra
    // 0x800F8870: nop

    return;
    // 0x800F8870: nop

;}
RECOMP_FUNC void func_80802FCC_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802FCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802FD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802FD4: jal         0x80100094
    // 0x80802FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802FDC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802FE0: jal         0x80089D48
    // 0x80802FE4: lbu         $a0, 0x48($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X48);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80802FE4: lbu         $a0, 0x48($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X48);
    after_1:
    // 0x80802FE8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80802FEC: sb          $v0, 0x48($t6)
    MEM_B(0X48, ctx->r14) = ctx->r2;
    // 0x80802FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802FF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802FF8: jr          $ra
    // 0x80802FFC: nop

    return;
    // 0x80802FFC: nop

;}
RECOMP_FUNC void func_808047A8_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808047A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808047AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808047B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808047B4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808047B8: jal         0x80100094
    // 0x808047BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808047BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808047C0: lh          $v1, 0x18($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X18);
    // 0x808047C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808047C8: beq         $v1, $zero, L_808047E8
    if (ctx->r3 == 0) {
        // 0x808047CC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808047E8;
    }
    // 0x808047CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808047D0: beq         $v1, $at, L_80804828
    if (ctx->r3 == ctx->r1) {
        // 0x808047D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80804828;
    }
    // 0x808047D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808047D8: beq         $v1, $at, L_8080486C
    if (ctx->r3 == ctx->r1) {
        // 0x808047DC: nop
    
            goto L_8080486C;
    }
    // 0x808047DC: nop

    // 0x808047E0: b           L_808048AC
    // 0x808047E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_808048AC;
    // 0x808047E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_808047E8:
    // 0x808047E8: jal         0x800D8FF8
    // 0x808047EC: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x808047EC: nop

    after_1:
    // 0x808047F0: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B7C) << 16);
    // 0x808047F4: lwc1        $f4, -0x6484($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B7C));
    // 0x808047F8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808047FC: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80804800: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80804804: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80804808: jal         0x800F15F8
    // 0x8080480C: nop

    func_800F15F8(rdram, ctx);
        goto after_2;
    // 0x8080480C: nop

    after_2:
    // 0x80804810: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80804814: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80804818: jal         0x80804AC8
    // 0x8080481C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80804AC8_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x8080481C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80804820: b           L_808048AC
    // 0x80804824: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_808048AC;
    // 0x80804824: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80804828:
    // 0x80804828: jal         0x800D8FF8
    // 0x8080482C: nop

    func_800D8FF8(rdram, ctx);
        goto after_4;
    // 0x8080482C: nop

    after_4:
    // 0x80804830: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B80) << 16);
    // 0x80804834: lwc1        $f14, -0x6480($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B80));
    // 0x80804838: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B84) << 16);
    // 0x8080483C: lwc1        $f8, -0x647C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B84));
    // 0x80804840: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80804844: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80804848: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8080484C: jal         0x800F15F8
    // 0x80804850: nop

    func_800F15F8(rdram, ctx);
        goto after_5;
    // 0x80804850: nop

    after_5:
    // 0x80804854: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80804858: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8080485C: jal         0x80804AC8
    // 0x80804860: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80804AC8_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80804860: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80804864: b           L_808048AC
    // 0x80804868: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_808048AC;
    // 0x80804868: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8080486C:
    // 0x8080486C: jal         0x800D8FF8
    // 0x80804870: nop

    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x80804870: nop

    after_7:
    // 0x80804874: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80804878: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080487C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B88) << 16);
    // 0x80804880: lwc1        $f16, -0x6478($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B88));
    // 0x80804884: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80804888: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8080488C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80804890: jal         0x800F15F8
    // 0x80804894: nop

    func_800F15F8(rdram, ctx);
        goto after_8;
    // 0x80804894: nop

    after_8:
    // 0x80804898: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x8080489C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808048A0: jal         0x80804AC8
    // 0x808048A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80804AC8_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x808048A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x808048A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_808048AC:
    // 0x808048AC: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808048B0: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x808048B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808048B8: nop

    // 0x808048BC: bc1fl       L_808048CC
    if (!c1cs) {
        // 0x808048C0: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_808048CC;
    }
    goto skip_0;
    // 0x808048C0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    skip_0:
    // 0x808048C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808048C8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_808048CC:
    // 0x808048CC: jal         0x808049DC
    // 0x808048D0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808049DC_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x808048D0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_10:
    // 0x808048D4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(1480, 0X9B8C) << 16);
    // 0x808048D8: lwc1        $f8, -0x6474($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1480, 0X9B8C));
    // 0x808048DC: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808048E0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808048E4: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x808048E8: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808048EC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808048F0: jal         0x800F10B4
    // 0x808048F4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_11;
    // 0x808048F4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x808048F8: lui         $at, 0x46FA
    ctx->r1 = S32(0X46FA << 16);
    // 0x808048FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80804900: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80804904: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80804908: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080490C: lui         $a3, 0x46AB
    ctx->r7 = S32(0X46AB << 16);
    // 0x80804910: ori         $a3, $a3, 0xE000
    ctx->r7 = ctx->r7 | 0XE000;
    // 0x80804914: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80804918: jal         0x800F10B4
    // 0x8080491C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_12;
    // 0x8080491C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x80804920: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80804924: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80804928: nop

    // 0x8080492C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80804930: lbu         $a0, 0x1A($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1A);
    // 0x80804934: bnel        $a0, $zero, L_80804954
    if (ctx->r4 != 0) {
        // 0x80804938: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_80804954;
    }
    goto skip_1;
    // 0x80804938: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x8080493C: jal         0x800C4B64
    // 0x80804940: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    func_800C4B64(rdram, ctx);
        goto after_13;
    // 0x80804940: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x80804944: jal         0x800C4B70
    // 0x80804948: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800C4B70(rdram, ctx);
        goto after_14;
    // 0x80804948: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_14:
    // 0x8080494C: lbu         $a0, 0x1A($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1A);
    // 0x80804950: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_80804954:
    // 0x80804954: lui         $a3, 0x8081
    ctx->r7 = S32(RELOC_HI16(1480, 0XA028) << 16);
    // 0x80804958: addiu       $a3, $a3, -0x5FD8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1480, 0XA028));
    // 0x8080495C: lw          $t9, 0x70($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X70);
    // 0x80804960: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80804964: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80804968: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8080496C: jal         0x80089D68
    // 0x80804970: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    _subaddieaudioloop_entrypoint_7(rdram, ctx);
        goto after_15;
    // 0x80804970: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_15:
    // 0x80804974: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80804978: beq         $a0, $zero, L_80804994
    if (ctx->r4 == 0) {
        // 0x8080497C: sb          $v0, 0x1A($s0)
        MEM_B(0X1A, ctx->r16) = ctx->r2;
            goto L_80804994;
    }
    // 0x8080497C: sb          $v0, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = ctx->r2;
    // 0x80804980: jal         0x800C31DC
    // 0x80804984: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800C31DC(rdram, ctx);
        goto after_16;
    // 0x80804984: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x80804988: lbu         $a0, 0x1A($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1A);
    // 0x8080498C: jal         0x800C3058
    // 0x80804990: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800C3058(rdram, ctx);
        goto after_17;
    // 0x80804990: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_17:
L_80804994:
    // 0x80804994: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80804998: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080499C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808049A0: jr          $ra
    // 0x808049A4: nop

    return;
    // 0x808049A4: nop

;}
RECOMP_FUNC void func_8009FC80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FC80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009FC84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009FC88: jal         0x8009C128
    // 0x8009FC8C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8009FC8C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8009FC90: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8009FC94: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009FC98: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8009FC9C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8009FCA0: jal         0x800DC178
    // 0x8009FCA4: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x8009FCA4: nop

    after_1:
    // 0x8009FCA8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8009FCAC: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x8009FCB0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009FCB4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8009FCB8: lui         $at, 0x42D2
    ctx->r1 = S32(0X42D2 << 16);
    // 0x8009FCBC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8009FCC0: jal         0x800DC178
    // 0x8009FCC4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x8009FCC4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8009FCC8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8009FCCC: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8009FCD0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009FCD4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8009FCD8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8009FCDC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8009FCE0: jal         0x800DC178
    // 0x8009FCE4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x8009FCE4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8009FCE8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8009FCEC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009FCF0: addiu       $t6, $t6, -0x6DE0
    ctx->r14 = ADD32(ctx->r14, -0X6DE0);
    // 0x8009FCF4: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8009FCF8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009FCFC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8009FD00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009FD04: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8009FD08: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8009FD0C: jal         0x800BBCB8
    // 0x8009FD10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x8009FD10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8009FD14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009FD18: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009FD1C: jr          $ra
    // 0x8009FD20: nop

    return;
    // 0x8009FD20: nop

;}
RECOMP_FUNC void func_808002B0_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808002B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002C0: bne         $a1, $at, L_808002EC
    if (ctx->r5 != ctx->r1) {
        // 0x808002C4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_808002EC;
    }
    // 0x808002C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002C8: addiu       $a0, $zero, 0x2BF
    ctx->r4 = ADD32(0, 0X2BF);
    // 0x808002CC: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x808002D0: jal         0x80101180
    // 0x808002D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_0;
    // 0x808002D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808002D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002DC: jal         0x80800304
    // 0x808002E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800304_chclinker(rdram, ctx);
        goto after_1;
    // 0x808002E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x808002E4: b           L_808002F4
    // 0x808002E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002F4;
    // 0x808002E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002EC:
    // 0x808002EC: b           L_808002F4
    // 0x808002F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002F4;
    // 0x808002F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002F4:
    // 0x808002F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002FC: jr          $ra
    // 0x80800300: nop

    return;
    // 0x80800300: nop

;}
RECOMP_FUNC void chsabreman_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1232, 0X1D78) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x1D78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1232, 0X1D78));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x1D78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1232, 0X1D78));
;}
RECOMP_FUNC void func_800266B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800266B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800266B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800266B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800266BC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800266C0: jal         0x8002FEC0
    // 0x800266C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800266C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800266C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800266CC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800266D0: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800266D4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800266D8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800266DC: beq         $t8, $zero, L_80026760
    if (ctx->r24 == 0) {
        // 0x800266E0: nop
    
            goto L_80026760;
    }
    // 0x800266E0: nop

L_800266E4:
    // 0x800266E4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800266E8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800266EC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800266F0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800266F4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x800266F8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800266FC: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80026700: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80026704: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x80026708: lh          $t4, 0xC($t3)
    ctx->r12 = MEM_H(ctx->r11, 0XC);
    // 0x8002670C: bne         $t4, $t5, L_8002674C
    if (ctx->r12 != ctx->r13) {
        // 0x80026710: nop
    
            goto L_8002674C;
    }
    // 0x80026710: nop

    // 0x80026714: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80026718: beq         $t6, $zero, L_80026738
    if (ctx->r14 == 0) {
        // 0x8002671C: nop
    
            goto L_80026738;
    }
    // 0x8002671C: nop

    // 0x80026720: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80026724: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80026728: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8002672C: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80026730: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80026734: sw          $t1, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r9;
L_80026738:
    // 0x80026738: jal         0x80020E74
    // 0x8002673C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80020E74(rdram, ctx);
        goto after_1;
    // 0x8002673C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80026740: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80026744: jal         0x80020E40
    // 0x80026748: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80020E40(rdram, ctx);
        goto after_2;
    // 0x80026748: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_2:
L_8002674C:
    // 0x8002674C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80026750: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x80026754: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80026758: bne         $t3, $zero, L_800266E4
    if (ctx->r11 != 0) {
        // 0x8002675C: nop
    
            goto L_800266E4;
    }
    // 0x8002675C: nop

L_80026760:
    // 0x80026760: jal         0x8002FEC0
    // 0x80026764: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x80026764: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80026768: b           L_80026770
    // 0x8002676C: nop

        goto L_80026770;
    // 0x8002676C: nop

L_80026770:
    // 0x80026770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026774: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80026778: jr          $ra
    // 0x8002677C: nop

    return;
    // 0x8002677C: nop

;}
RECOMP_FUNC void subaddietaxi_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800010: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800014: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800018: jal         0x8010410C
    // 0x8080001C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8010410C(rdram, ctx);
        goto after_0;
    // 0x8080001C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800020: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800024: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800028: bltzl       $a1, L_8080003C
    if (SIGNED(ctx->r5) < 0) {
        // 0x8080002C: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_8080003C;
    }
    goto skip_0;
    // 0x8080002C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x80800030: jal         0x80102424
    // 0x80800034: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800034: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800038: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_8080003C:
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800040: jal         0x800EE7F8
    // 0x80800044: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800044: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80800048: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x8080004C: jal         0x800EE7F8
    // 0x80800050: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800050: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800054: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800058: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3334, 0XD10) << 16);
    // 0x8080005C: lwc1        $f4, 0x38($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80800060: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x80800064: lwc1        $f6, 0xD10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3334, 0XD10));
    // 0x80800068: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8080006C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800070: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800074: swc1        $f6, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f6.u32l;
    // 0x80800078: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x8080007C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800080: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void bskazfly_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801884: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801888: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(236, 0X1C88) << 16);
    // 0x8080188C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801890: jr          $ra
    // 0x80801894: lw          $v0, 0x1C88($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C88));
    return;
    // 0x80801894: lw          $v0, 0x1C88($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C88));
;}
RECOMP_FUNC void func_80800054_chsquits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800054: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800058: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080005C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800060: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800064: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800068: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080006C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800070: bne         $t7, $at, L_808000EC
    if (ctx->r15 != ctx->r1) {
        // 0x80800074: nop
    
            goto L_808000EC;
    }
    // 0x80800074: nop

    // 0x80800078: jal         0x800D90A4
    // 0x8080007C: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x8080007C: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800080: beq         $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x80800084: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808000EC;
    }
    // 0x80800084: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800088: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x8080008C: jal         0x8010CAC0
    // 0x80800090: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_8010CAC0(rdram, ctx);
        goto after_1;
    // 0x80800090: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800094: beq         $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x80800098: nop
    
            goto L_808000EC;
    }
    // 0x80800098: nop

    // 0x8080009C: jal         0x808001A4
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001A4_chsquits(rdram, ctx);
        goto after_2;
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000A8: addiu       $t8, $zero, 0x8F
    ctx->r24 = ADD32(0, 0X8F);
    // 0x808000AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808000B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000B8: jal         0x8008A208
    // 0x808000BC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x808000BC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x808000C0: beq         $v0, $zero, L_808000D0
    if (ctx->r2 == 0) {
        // 0x808000C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D0;
    }
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: jal         0x80101FDC
    // 0x808000CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808000CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
L_808000D0:
    // 0x808000D0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808000D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000D8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808000DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808000E0: jal         0x800DC178
    // 0x808000E4: nop

    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x808000E4: nop

    after_5:
    // 0x808000E8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_808000EC:
    // 0x808000EC: jal         0x80800358
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800358_chsquits(rdram, ctx);
        goto after_6;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808000F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800100: jr          $ra
    // 0x80800104: nop

    return;
    // 0x80800104: nop

;}
RECOMP_FUNC void bastatetimerlist_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091650: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80091654: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80091658: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x8009165C: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x80091660: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x80091664: lw          $t7, 0x3C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X3C);
    // 0x80091668: addiu       $t2, $zero, -0xC
    ctx->r10 = ADD32(0, -0XC);
    // 0x8009166C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80091670: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x80091674: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x80091678: addiu       $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
    // 0x8009167C: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x80091680: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
    // 0x80091684: lw          $t9, 0x3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X3C);
    // 0x80091688: swc1        $f0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f0.u32l;
    // 0x8009168C: lw          $t4, 0x3C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X3C);
    // 0x80091690: swc1        $f0, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f0.u32l;
    // 0x80091694: lw          $t5, 0x3C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X3C);
    // 0x80091698: sb          $zero, 0x14($t5)
    MEM_B(0X14, ctx->r13) = 0;
L_8009169C:
    // 0x8009169C: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800916A0: xor         $v0, $v1, $a3
    ctx->r2 = ctx->r3 ^ ctx->r7;
    // 0x800916A4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x800916A8: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800916AC: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x800916B0: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x800916B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800916B8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800916BC: bne         $v0, $zero, L_800916CC
    if (ctx->r2 != 0) {
        // 0x800916C0: swc1        $f0, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
            goto L_800916CC;
    }
    // 0x800916C0: swc1        $f0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f0.u32l;
    // 0x800916C4: xor         $a1, $v1, $t0
    ctx->r5 = ctx->r3 ^ ctx->r8;
    // 0x800916C8: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
L_800916CC:
    // 0x800916CC: lw          $t4, 0x3C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X3C);
    // 0x800916D0: xor         $a2, $v1, $t1
    ctx->r6 = ctx->r3 ^ ctx->r9;
    // 0x800916D4: sltiu       $a2, $a2, 0x1
    ctx->r6 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x800916D8: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x800916DC: sb          $a1, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r5;
    // 0x800916E0: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800916E4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800916E8: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800916EC: swc1        $f0, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f0.u32l;
    // 0x800916F0: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x800916F4: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800916F8: bne         $a2, $zero, L_80091704
    if (ctx->r6 != 0) {
        // 0x800916FC: swc1        $f0, 0x10($t9)
        MEM_W(0X10, ctx->r25) = ctx->f0.u32l;
            goto L_80091704;
    }
    // 0x800916FC: swc1        $f0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f0.u32l;
    // 0x80091700: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80091704:
    // 0x80091704: lw          $t4, 0x3C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X3C);
    // 0x80091708: sltiu       $v0, $v1, 0x1
    ctx->r2 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8009170C: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80091710: sb          $a1, 0x14($t5)
    MEM_B(0X14, ctx->r13) = ctx->r5;
    // 0x80091714: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80091718: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009171C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80091720: swc1        $f0, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->f0.u32l;
    // 0x80091724: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x80091728: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8009172C: bne         $v0, $zero, L_80091738
    if (ctx->r2 != 0) {
        // 0x80091730: swc1        $f0, 0x1C($t9)
        MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
            goto L_80091738;
    }
    // 0x80091730: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x80091734: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_80091738:
    // 0x80091738: lw          $t4, 0x3C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X3C);
    // 0x8009173C: xor         $a2, $v1, $t2
    ctx->r6 = ctx->r3 ^ ctx->r10;
    // 0x80091740: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80091744: sb          $a1, 0x20($t5)
    MEM_B(0X20, ctx->r13) = ctx->r5;
    // 0x80091748: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8009174C: sltiu       $a1, $a2, 0x1
    ctx->r5 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x80091750: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80091754: swc1        $f0, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f0.u32l;
    // 0x80091758: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x8009175C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80091760: bne         $a1, $zero, L_8009176C
    if (ctx->r5 != 0) {
        // 0x80091764: swc1        $f0, 0x28($t9)
        MEM_W(0X28, ctx->r25) = ctx->f0.u32l;
            goto L_8009176C;
    }
    // 0x80091764: swc1        $f0, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->f0.u32l;
    // 0x80091768: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8009176C:
    // 0x8009176C: lw          $t4, 0x3C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X3C);
    // 0x80091770: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80091774: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x80091778: bne         $v1, $t3, L_8009169C
    if (ctx->r3 != ctx->r11) {
        // 0x8009177C: sb          $a1, 0x2C($t5)
        MEM_B(0X2C, ctx->r13) = ctx->r5;
            goto L_8009169C;
    }
    // 0x8009177C: sb          $a1, 0x2C($t5)
    MEM_B(0X2C, ctx->r13) = ctx->r5;
    // 0x80091780: jr          $ra
    // 0x80091784: nop

    return;
    // 0x80091784: nop

;}
RECOMP_FUNC void func_800E3A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E3A34: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800E3A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3A3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3A40: jal         0x800CA934
    // 0x800E3A44: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    func_800CA934(rdram, ctx);
        goto after_0;
    // 0x800E3A44: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    after_0:
    // 0x800E3A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3A4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E3A50: jr          $ra
    // 0x800E3A54: nop

    return;
    // 0x800E3A54: nop

;}
RECOMP_FUNC void func_800E5390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E5390: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800E5394: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800E5398: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800E539C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800E53A0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800E53A4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800E53A8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800E53AC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800E53B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800E53B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800E53B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E53BC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800E53C0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800E53C4: addiu       $t0, $t0, 0x32C0
    ctx->r8 = ADD32(ctx->r8, 0X32C0);
    // 0x800E53C8: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800E53CC: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x800E53D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E53D4: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800E53D8: lw          $t8, 0x1C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1C);
    // 0x800E53DC: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800E53E0: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x800E53E4: lw          $s4, 0xC($a0)
    ctx->r20 = MEM_W(ctx->r4, 0XC);
    // 0x800E53E8: lw          $s2, 0x10($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X10);
    // 0x800E53EC: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800E53F0: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800E53F4: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800E53F8: lw          $fp, 0x14($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X14);
    // 0x800E53FC: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800E5400: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x800E5404: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800E5408: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x800E540C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800E5410: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
L_800E5414:
    // 0x800E5414: sltu        $at, $s2, $v0
    ctx->r1 = ctx->r18 < ctx->r2 ? 1 : 0;
    // 0x800E5418: beq         $at, $zero, L_800E5480
    if (ctx->r1 == 0) {
        // 0x800E541C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800E5480;
    }
    // 0x800E541C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800E5420: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E5424:
    // 0x800E5424: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5428: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E542C: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E5430: bnel        $at, $zero, L_800E5460
    if (ctx->r1 != 0) {
        // 0x800E5434: addu        $t9, $s1, $v0
        ctx->r25 = ADD32(ctx->r17, ctx->r2);
            goto L_800E5460;
    }
    goto skip_0;
    // 0x800E5434: addu        $t9, $s1, $v0
    ctx->r25 = ADD32(ctx->r17, ctx->r2);
    skip_0:
    // 0x800E5438: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E543C: jal         0x8001311C
    // 0x800E5440: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_0;
    // 0x800E5440: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_0:
    // 0x800E5444: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800E5448: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x800E544C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5450: addiu       $t8, $t7, 0x1800
    ctx->r24 = ADD32(ctx->r15, 0X1800);
    // 0x800E5454: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x800E5458: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E545C: addu        $t9, $s1, $v0
    ctx->r25 = ADD32(ctx->r17, ctx->r2);
L_800E5460:
    // 0x800E5460: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x800E5464: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x800E5468: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800E546C: sllv        $t2, $t1, $s2
    ctx->r10 = S32(ctx->r9 << (ctx->r18 & 31));
    // 0x800E5470: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E5474: sltu        $at, $s2, $v1
    ctx->r1 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x800E5478: bne         $at, $zero, L_800E5424
    if (ctx->r1 != 0) {
        // 0x800E547C: or          $s4, $s4, $t2
        ctx->r20 = ctx->r20 | ctx->r10;
            goto L_800E5424;
    }
    // 0x800E547C: or          $s4, $s4, $t2
    ctx->r20 = ctx->r20 | ctx->r10;
L_800E5480:
    // 0x800E5480: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800E5484: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800E5488: and         $t0, $s4, $t4
    ctx->r8 = ctx->r20 & ctx->r12;
    // 0x800E548C: sll         $t5, $t0, 3
    ctx->r13 = S32(ctx->r8 << 3);
    // 0x800E5490: addu        $s6, $t5, $t6
    ctx->r22 = ADD32(ctx->r13, ctx->r14);
    // 0x800E5494: lbu         $s3, 0x0($s6)
    ctx->r19 = MEM_BU(ctx->r22, 0X0);
    // 0x800E5498: sltiu       $at, $s3, 0x11
    ctx->r1 = ctx->r19 < 0X11 ? 1 : 0;
    // 0x800E549C: bnel        $at, $zero, L_800E554C
    if (ctx->r1 != 0) {
        // 0x800E54A0: lbu         $v0, 0x1($s6)
        ctx->r2 = MEM_BU(ctx->r22, 0X1);
            goto L_800E554C;
    }
    goto skip_1;
    // 0x800E54A0: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
    skip_1:
    // 0x800E54A4: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
L_800E54A8:
    // 0x800E54A8: addiu       $s3, $s3, -0x10
    ctx->r19 = ADD32(ctx->r19, -0X10);
    // 0x800E54AC: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x800E54B0: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E54B4: beq         $at, $zero, L_800E5518
    if (ctx->r1 == 0) {
        // 0x800E54B8: srlv        $s4, $s4, $v0
        ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
            goto L_800E5518;
    }
    // 0x800E54B8: srlv        $s4, $s4, $v0
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
    // 0x800E54BC: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E54C0:
    // 0x800E54C0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E54C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E54C8: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E54CC: bnel        $at, $zero, L_800E54F8
    if (ctx->r1 != 0) {
        // 0x800E54D0: addu        $t9, $s1, $v0
        ctx->r25 = ADD32(ctx->r17, ctx->r2);
            goto L_800E54F8;
    }
    goto skip_2;
    // 0x800E54D0: addu        $t9, $s1, $v0
    ctx->r25 = ADD32(ctx->r17, ctx->r2);
    skip_2:
    // 0x800E54D4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E54D8: jal         0x8001311C
    // 0x800E54DC: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_1;
    // 0x800E54DC: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_1:
    // 0x800E54E0: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800E54E4: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E54E8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E54EC: addiu       $t8, $t7, 0x1800
    ctx->r24 = ADD32(ctx->r15, 0X1800);
    // 0x800E54F0: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x800E54F4: addu        $t9, $s1, $v0
    ctx->r25 = ADD32(ctx->r17, ctx->r2);
L_800E54F8:
    // 0x800E54F8: lbu         $t1, 0x0($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0X0);
    // 0x800E54FC: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x800E5500: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800E5504: sllv        $t2, $t1, $s2
    ctx->r10 = S32(ctx->r9 << (ctx->r18 & 31));
    // 0x800E5508: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E550C: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E5510: bne         $at, $zero, L_800E54C0
    if (ctx->r1 != 0) {
        // 0x800E5514: or          $s4, $s4, $t2
        ctx->r20 = ctx->r20 | ctx->r10;
            goto L_800E54C0;
    }
    // 0x800E5514: or          $s4, $s4, $t2
    ctx->r20 = ctx->r20 | ctx->r10;
L_800E5518:
    // 0x800E5518: sll         $t4, $s3, 1
    ctx->r12 = S32(ctx->r19 << 1);
    // 0x800E551C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800E5520: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x800E5524: lhu         $t0, 0x32C0($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X32C0);
    // 0x800E5528: lw          $t7, 0x4($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X4);
    // 0x800E552C: and         $t5, $t0, $s4
    ctx->r13 = ctx->r8 & ctx->r20;
    // 0x800E5530: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800E5534: addu        $s6, $t6, $t7
    ctx->r22 = ADD32(ctx->r14, ctx->r15);
    // 0x800E5538: lbu         $s3, 0x0($s6)
    ctx->r19 = MEM_BU(ctx->r22, 0X0);
    // 0x800E553C: sltiu       $at, $s3, 0x11
    ctx->r1 = ctx->r19 < 0X11 ? 1 : 0;
    // 0x800E5540: beql        $at, $zero, L_800E54A8
    if (ctx->r1 == 0) {
        // 0x800E5544: lbu         $v0, 0x1($s6)
        ctx->r2 = MEM_BU(ctx->r22, 0X1);
            goto L_800E54A8;
    }
    goto skip_3;
    // 0x800E5544: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
    skip_3:
    // 0x800E5548: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
L_800E554C:
    // 0x800E554C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800E5550: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800E5554: srlv        $s4, $s4, $v0
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
    // 0x800E5558: bne         $s3, $at, L_800E5578
    if (ctx->r19 != ctx->r1) {
        // 0x800E555C: subu        $s2, $s2, $v0
        ctx->r18 = SUB32(ctx->r18, ctx->r2);
            goto L_800E5578;
    }
    // 0x800E555C: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x800E5560: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800E5564: lhu         $t8, 0x4($s6)
    ctx->r24 = MEM_HU(ctx->r22, 0X4);
    // 0x800E5568: addu        $t1, $t9, $fp
    ctx->r9 = ADD32(ctx->r25, ctx->r30);
    // 0x800E556C: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800E5570: b           L_800E5854
    // 0x800E5574: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
        goto L_800E5854;
    // 0x800E5574: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
L_800E5578:
    // 0x800E5578: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800E557C: beq         $s3, $at, L_800E585C
    if (ctx->r19 == ctx->r1) {
        // 0x800E5580: sltu        $at, $s2, $s3
        ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
            goto L_800E585C;
    }
    // 0x800E5580: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E5584: beq         $at, $zero, L_800E55E8
    if (ctx->r1 == 0) {
        // 0x800E5588: addu        $s5, $t2, $fp
        ctx->r21 = ADD32(ctx->r10, ctx->r30);
            goto L_800E55E8;
    }
    // 0x800E5588: addu        $s5, $t2, $fp
    ctx->r21 = ADD32(ctx->r10, ctx->r30);
    // 0x800E558C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E5590:
    // 0x800E5590: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E5598: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E559C: bnel        $at, $zero, L_800E55C8
    if (ctx->r1 != 0) {
        // 0x800E55A0: addu        $t0, $s1, $v0
        ctx->r8 = ADD32(ctx->r17, ctx->r2);
            goto L_800E55C8;
    }
    goto skip_4;
    // 0x800E55A0: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
    skip_4:
    // 0x800E55A4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E55A8: jal         0x8001311C
    // 0x800E55AC: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_2;
    // 0x800E55AC: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_2:
    // 0x800E55B0: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x800E55B4: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E55B8: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E55BC: addiu       $t4, $t3, 0x1800
    ctx->r12 = ADD32(ctx->r11, 0X1800);
    // 0x800E55C0: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
    // 0x800E55C4: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
L_800E55C8:
    // 0x800E55C8: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800E55CC: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800E55D0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800E55D4: sllv        $t6, $t5, $s2
    ctx->r14 = S32(ctx->r13 << (ctx->r18 & 31));
    // 0x800E55D8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E55DC: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E55E0: bne         $at, $zero, L_800E5590
    if (ctx->r1 != 0) {
        // 0x800E55E4: or          $s4, $s4, $t6
        ctx->r20 = ctx->r20 | ctx->r14;
            goto L_800E5590;
    }
    // 0x800E55E4: or          $s4, $s4, $t6
    ctx->r20 = ctx->r20 | ctx->r14;
L_800E55E8:
    // 0x800E55E8: sll         $t9, $s3, 1
    ctx->r25 = S32(ctx->r19 << 1);
    // 0x800E55EC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800E55F0: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800E55F4: lhu         $t8, 0x32C0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X32C0);
    // 0x800E55F8: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x800E55FC: lhu         $t2, 0x4($s6)
    ctx->r10 = MEM_HU(ctx->r22, 0X4);
    // 0x800E5600: subu        $s2, $s2, $s3
    ctx->r18 = SUB32(ctx->r18, ctx->r19);
    // 0x800E5604: and         $t1, $t8, $s4
    ctx->r9 = ctx->r24 & ctx->r20;
    // 0x800E5608: sltu        $at, $s2, $v1
    ctx->r1 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x800E560C: srlv        $s4, $s4, $s3
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r19 & 31));
    // 0x800E5610: beq         $at, $zero, L_800E5678
    if (ctx->r1 == 0) {
        // 0x800E5614: addu        $s7, $t1, $t2
        ctx->r23 = ADD32(ctx->r9, ctx->r10);
            goto L_800E5678;
    }
    // 0x800E5614: addu        $s7, $t1, $t2
    ctx->r23 = ADD32(ctx->r9, ctx->r10);
    // 0x800E5618: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E561C:
    // 0x800E561C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5620: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E5624: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E5628: bnel        $at, $zero, L_800E5658
    if (ctx->r1 != 0) {
        // 0x800E562C: addu        $t0, $s1, $v0
        ctx->r8 = ADD32(ctx->r17, ctx->r2);
            goto L_800E5658;
    }
    goto skip_5;
    // 0x800E562C: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
    skip_5:
    // 0x800E5630: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E5634: jal         0x8001311C
    // 0x800E5638: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_3;
    // 0x800E5638: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_3:
    // 0x800E563C: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x800E5640: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5644: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E5648: addiu       $t4, $t3, 0x1800
    ctx->r12 = ADD32(ctx->r11, 0X1800);
    // 0x800E564C: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
    // 0x800E5650: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x800E5654: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
L_800E5658:
    // 0x800E5658: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800E565C: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800E5660: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800E5664: sllv        $t6, $t5, $s2
    ctx->r14 = S32(ctx->r13 << (ctx->r18 & 31));
    // 0x800E5668: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E566C: sltu        $at, $s2, $v1
    ctx->r1 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x800E5670: bne         $at, $zero, L_800E561C
    if (ctx->r1 != 0) {
        // 0x800E5674: or          $s4, $s4, $t6
        ctx->r20 = ctx->r20 | ctx->r14;
            goto L_800E561C;
    }
    // 0x800E5674: or          $s4, $s4, $t6
    ctx->r20 = ctx->r20 | ctx->r14;
L_800E5678:
    // 0x800E5678: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800E567C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800E5680: and         $t8, $s4, $t9
    ctx->r24 = ctx->r20 & ctx->r25;
    // 0x800E5684: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x800E5688: addu        $s6, $t1, $t2
    ctx->r22 = ADD32(ctx->r9, ctx->r10);
    // 0x800E568C: lbu         $s3, 0x0($s6)
    ctx->r19 = MEM_BU(ctx->r22, 0X0);
    // 0x800E5690: sltiu       $at, $s3, 0x11
    ctx->r1 = ctx->r19 < 0X11 ? 1 : 0;
    // 0x800E5694: bnel        $at, $zero, L_800E5744
    if (ctx->r1 != 0) {
        // 0x800E5698: lbu         $v0, 0x1($s6)
        ctx->r2 = MEM_BU(ctx->r22, 0X1);
            goto L_800E5744;
    }
    goto skip_6;
    // 0x800E5698: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
    skip_6:
    // 0x800E569C: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
L_800E56A0:
    // 0x800E56A0: addiu       $s3, $s3, -0x10
    ctx->r19 = ADD32(ctx->r19, -0X10);
    // 0x800E56A4: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x800E56A8: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E56AC: beq         $at, $zero, L_800E5710
    if (ctx->r1 == 0) {
        // 0x800E56B0: srlv        $s4, $s4, $v0
        ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
            goto L_800E5710;
    }
    // 0x800E56B0: srlv        $s4, $s4, $v0
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
    // 0x800E56B4: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E56B8:
    // 0x800E56B8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E56BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E56C0: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E56C4: bnel        $at, $zero, L_800E56F0
    if (ctx->r1 != 0) {
        // 0x800E56C8: addu        $t0, $s1, $v0
        ctx->r8 = ADD32(ctx->r17, ctx->r2);
            goto L_800E56F0;
    }
    goto skip_7;
    // 0x800E56C8: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
    skip_7:
    // 0x800E56CC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E56D0: jal         0x8001311C
    // 0x800E56D4: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_4;
    // 0x800E56D4: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_4:
    // 0x800E56D8: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x800E56DC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E56E0: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E56E4: addiu       $t4, $t3, 0x1800
    ctx->r12 = ADD32(ctx->r11, 0X1800);
    // 0x800E56E8: sw          $t4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r12;
    // 0x800E56EC: addu        $t0, $s1, $v0
    ctx->r8 = ADD32(ctx->r17, ctx->r2);
L_800E56F0:
    // 0x800E56F0: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x800E56F4: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800E56F8: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800E56FC: sllv        $t6, $t5, $s2
    ctx->r14 = S32(ctx->r13 << (ctx->r18 & 31));
    // 0x800E5700: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E5704: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E5708: bne         $at, $zero, L_800E56B8
    if (ctx->r1 != 0) {
        // 0x800E570C: or          $s4, $s4, $t6
        ctx->r20 = ctx->r20 | ctx->r14;
            goto L_800E56B8;
    }
    // 0x800E570C: or          $s4, $s4, $t6
    ctx->r20 = ctx->r20 | ctx->r14;
L_800E5710:
    // 0x800E5710: sll         $t9, $s3, 1
    ctx->r25 = S32(ctx->r19 << 1);
    // 0x800E5714: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800E5718: addu        $t8, $t8, $t9
    ctx->r24 = ADD32(ctx->r24, ctx->r25);
    // 0x800E571C: lhu         $t8, 0x32C0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X32C0);
    // 0x800E5720: lw          $t3, 0x4($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X4);
    // 0x800E5724: and         $t1, $t8, $s4
    ctx->r9 = ctx->r24 & ctx->r20;
    // 0x800E5728: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800E572C: addu        $s6, $t2, $t3
    ctx->r22 = ADD32(ctx->r10, ctx->r11);
    // 0x800E5730: lbu         $s3, 0x0($s6)
    ctx->r19 = MEM_BU(ctx->r22, 0X0);
    // 0x800E5734: sltiu       $at, $s3, 0x11
    ctx->r1 = ctx->r19 < 0X11 ? 1 : 0;
    // 0x800E5738: beql        $at, $zero, L_800E56A0
    if (ctx->r1 == 0) {
        // 0x800E573C: lbu         $v0, 0x1($s6)
        ctx->r2 = MEM_BU(ctx->r22, 0X1);
            goto L_800E56A0;
    }
    goto skip_8;
    // 0x800E573C: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
    skip_8:
    // 0x800E5740: lbu         $v0, 0x1($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X1);
L_800E5744:
    // 0x800E5744: subu        $s2, $s2, $v0
    ctx->r18 = SUB32(ctx->r18, ctx->r2);
    // 0x800E5748: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E574C: beq         $at, $zero, L_800E57B0
    if (ctx->r1 == 0) {
        // 0x800E5750: srlv        $s4, $s4, $v0
        ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
            goto L_800E57B0;
    }
    // 0x800E5750: srlv        $s4, $s4, $v0
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r2 & 31));
    // 0x800E5754: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
L_800E5758:
    // 0x800E5758: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E575C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E5760: slti        $at, $v0, 0x1800
    ctx->r1 = SIGNED(ctx->r2) < 0X1800 ? 1 : 0;
    // 0x800E5764: bnel        $at, $zero, L_800E5790
    if (ctx->r1 != 0) {
        // 0x800E5768: addu        $t5, $s1, $v0
        ctx->r13 = ADD32(ctx->r17, ctx->r2);
            goto L_800E5790;
    }
    goto skip_9;
    // 0x800E5768: addu        $t5, $s1, $v0
    ctx->r13 = ADD32(ctx->r17, ctx->r2);
    skip_9:
    // 0x800E576C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800E5770: jal         0x8001311C
    // 0x800E5774: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    func_8001311C(rdram, ctx);
        goto after_5;
    // 0x800E5774: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_5:
    // 0x800E5778: lw          $t4, 0x30($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X30);
    // 0x800E577C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E5780: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800E5784: addiu       $t0, $t4, 0x1800
    ctx->r8 = ADD32(ctx->r12, 0X1800);
    // 0x800E5788: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x800E578C: addu        $t5, $s1, $v0
    ctx->r13 = ADD32(ctx->r17, ctx->r2);
L_800E5790:
    // 0x800E5790: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800E5794: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800E5798: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800E579C: sllv        $t7, $t6, $s2
    ctx->r15 = S32(ctx->r14 << (ctx->r18 & 31));
    // 0x800E57A0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x800E57A4: sltu        $at, $s2, $s3
    ctx->r1 = ctx->r18 < ctx->r19 ? 1 : 0;
    // 0x800E57A8: bne         $at, $zero, L_800E5758
    if (ctx->r1 != 0) {
        // 0x800E57AC: or          $s4, $s4, $t7
        ctx->r20 = ctx->r20 | ctx->r15;
            goto L_800E5758;
    }
    // 0x800E57AC: or          $s4, $s4, $t7
    ctx->r20 = ctx->r20 | ctx->r15;
L_800E57B0:
    // 0x800E57B0: sll         $t2, $s3, 1
    ctx->r10 = S32(ctx->r19 << 1);
    // 0x800E57B4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800E57B8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800E57BC: lhu         $t3, 0x32C0($t3)
    ctx->r11 = MEM_HU(ctx->r11, 0X32C0);
    // 0x800E57C0: lhu         $t8, 0x4($s6)
    ctx->r24 = MEM_HU(ctx->r22, 0X4);
    // 0x800E57C4: andi        $a1, $s7, 0x3
    ctx->r5 = ctx->r23 & 0X3;
    // 0x800E57C8: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800E57CC: and         $t4, $t3, $s4
    ctx->r12 = ctx->r11 & ctx->r20;
    // 0x800E57D0: subu        $t1, $fp, $t8
    ctx->r9 = SUB32(ctx->r30, ctx->r24);
    // 0x800E57D4: subu        $v1, $t1, $t4
    ctx->r3 = SUB32(ctx->r9, ctx->r12);
    // 0x800E57D8: srlv        $s4, $s4, $s3
    ctx->r20 = S32(U32(ctx->r20) >> (ctx->r19 & 31));
    // 0x800E57DC: beq         $a1, $zero, L_800E5818
    if (ctx->r5 == 0) {
        // 0x800E57E0: subu        $s2, $s2, $s3
        ctx->r18 = SUB32(ctx->r18, ctx->r19);
            goto L_800E5818;
    }
    // 0x800E57E0: subu        $s2, $s2, $s3
    ctx->r18 = SUB32(ctx->r18, ctx->r19);
    // 0x800E57E4: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800E57E8: addu        $a0, $a1, $s7
    ctx->r4 = ADD32(ctx->r5, ctx->r23);
    // 0x800E57EC: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
L_800E57F0:
    // 0x800E57F0: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x800E57F4: addiu       $s7, $s7, -0x1
    ctx->r23 = ADD32(ctx->r23, -0X1);
    // 0x800E57F8: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800E57FC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800E5800: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800E5804: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E5808: bne         $a0, $s7, L_800E57F0
    if (ctx->r4 != ctx->r23) {
        // 0x800E580C: sb          $t5, -0x1($s5)
        MEM_B(-0X1, ctx->r21) = ctx->r13;
            goto L_800E57F0;
    }
    // 0x800E580C: sb          $t5, -0x1($s5)
    MEM_B(-0X1, ctx->r21) = ctx->r13;
    // 0x800E5810: beq         $s7, $zero, L_800E5854
    if (ctx->r23 == 0) {
        // 0x800E5814: nop
    
            goto L_800E5854;
    }
    // 0x800E5814: nop

L_800E5818:
    // 0x800E5818: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800E581C: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
L_800E5820:
    // 0x800E5820: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800E5824: addiu       $s7, $s7, -0x4
    ctx->r23 = ADD32(ctx->r23, -0X4);
    // 0x800E5828: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800E582C: sb          $t7, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r15;
    // 0x800E5830: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x800E5834: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x800E5838: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800E583C: sb          $t9, -0x3($s5)
    MEM_B(-0X3, ctx->r21) = ctx->r25;
    // 0x800E5840: lbu         $t8, -0x2($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X2);
    // 0x800E5844: sb          $t8, -0x2($s5)
    MEM_B(-0X2, ctx->r21) = ctx->r24;
    // 0x800E5848: lbu         $t2, -0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, -0X1);
    // 0x800E584C: bne         $s7, $zero, L_800E5820
    if (ctx->r23 != 0) {
        // 0x800E5850: sb          $t2, -0x1($s5)
        MEM_B(-0X1, ctx->r21) = ctx->r10;
            goto L_800E5820;
    }
    // 0x800E5850: sb          $t2, -0x1($s5)
    MEM_B(-0X1, ctx->r21) = ctx->r10;
L_800E5854:
    // 0x800E5854: b           L_800E5414
    // 0x800E5858: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
        goto L_800E5414;
    // 0x800E5858: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
L_800E585C:
    // 0x800E585C: sw          $fp, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r30;
    // 0x800E5860: sw          $s4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r20;
    // 0x800E5864: sw          $s2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r18;
    // 0x800E5868: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800E586C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800E5870: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800E5874: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800E5878: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800E587C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800E5880: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800E5884: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800E5888: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800E588C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E5890: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800E5894: jr          $ra
    // 0x800E5898: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800E5898: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8080060C_sumumbofx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080060C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800610: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800614: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800618: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080061C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800620: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800624: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800628: lwc1        $f0, 0x28($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8080062C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800630: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800634: sub.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80800638: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8080063C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800640: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800644: nop

    // 0x80800648: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8080064C: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80800650: jal         0x800D8FF8
    // 0x80800654: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800654: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800658: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8080065C: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800660: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800664: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80800668: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080066C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X149C) << 16);
    // 0x80800670: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x80800674: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800678: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8080067C: nop

    // 0x80800680: bc1fl       L_80800694
    if (!c1cs) {
        // 0x80800684: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80800694;
    }
    goto skip_0;
    // 0x80800684: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80800688: sub.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8080068C: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x80800690: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_80800694:
    // 0x80800694: lw          $v0, 0x60($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X60);
    // 0x80800698: srl         $t8, $v0, 25
    ctx->r24 = S32(U32(ctx->r2) >> 25);
    // 0x8080069C: beql        $t8, $zero, L_80800734
    if (ctx->r24 == 0) {
        // 0x808006A0: lwc1        $f6, 0x28($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
            goto L_80800734;
    }
    goto skip_1;
    // 0x808006A0: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x808006A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006A8: beq         $t8, $at, L_808006D4
    if (ctx->r24 == ctx->r1) {
        // 0x808006AC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808006D4;
    }
    // 0x808006AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006B0: beq         $t8, $at, L_808006CC
    if (ctx->r24 == ctx->r1) {
        // 0x808006B4: lwc1        $f18, 0x38($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
            goto L_808006CC;
    }
    // 0x808006B4: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x808006B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006BC: beql        $t8, $at, L_80800760
    if (ctx->r24 == ctx->r1) {
        // 0x808006C0: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_80800760;
    }
    goto skip_2;
    // 0x808006C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_2:
    // 0x808006C4: b           L_808007AC
    // 0x808006C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808007AC;
    // 0x808006C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006CC:
    // 0x808006CC: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x808006D0: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
L_808006D4:
    // 0x808006D4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808006D8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808006DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006E0: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808006E4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x808006E8: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808006EC: jal         0x800F10B4
    // 0x808006F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808006F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x808006F4: jal         0x80013970
    // 0x808006F8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013970(rdram, ctx);
        goto after_2;
    // 0x808006F8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x808006FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X1494) << 16);
    // 0x80800700: lwc1        $f10, 0x1494($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X1494));
    // 0x80800704: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X1498) << 16);
    // 0x80800708: lwc1        $f18, 0x1498($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X1498));
    // 0x8080070C: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800710: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800714: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800718: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8080071C: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80800720: nop

    // 0x80800724: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800728: b           L_808007A8
    // 0x8080072C: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
        goto L_808007A8;
    // 0x8080072C: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x80800730: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
L_80800734:
    // 0x80800734: lwc1        $f10, 0x149C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X149C));
    // 0x80800738: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8080073C: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x80800740: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800744: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x80800748: nop

    // 0x8080074C: bc1fl       L_8080075C
    if (!c1cs) {
        // 0x80800750: lwc1        $f16, 0x24($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
            goto L_8080075C;
    }
    goto skip_3;
    // 0x80800750: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    skip_3:
    // 0x80800754: swc1        $f12, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f12.u32l;
    // 0x80800758: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
L_8080075C:
    // 0x8080075C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_80800760:
    // 0x80800760: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800764: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800768: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8080076C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800770: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80800774: jal         0x800F10B4
    // 0x80800778: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800778: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8080077C: jal         0x80013970
    // 0x80800780: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80013970(rdram, ctx);
        goto after_4;
    // 0x80800780: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x80800784: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X14A0) << 16);
    // 0x80800788: lwc1        $f6, 0x14A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X14A0));
    // 0x8080078C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3146, 0X14A4) << 16);
    // 0x80800790: lwc1        $f4, 0x14A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3146, 0X14A4));
    // 0x80800794: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80800798: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080079C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x808007A0: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x808007A4: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
L_808007A8:
    // 0x808007A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007AC:
    // 0x808007AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808007B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808007B4: jr          $ra
    // 0x808007B8: nop

    return;
    // 0x808007B8: nop

;}
RECOMP_FUNC void func_80801930_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801930: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801934: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801938: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080193C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801940: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80801944: jal         0x80106790
    // 0x80801948: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801948: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x8080194C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801950: jal         0x80100094
    // 0x80801954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801958: jal         0x800D3948
    // 0x8080195C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    func_800D3948(rdram, ctx);
        goto after_2;
    // 0x8080195C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_2:
    // 0x80801960: beq         $v0, $zero, L_80801970
    if (ctx->r2 == 0) {
        // 0x80801964: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_80801970;
    }
    // 0x80801964: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801968: b           L_80801980
    // 0x8080196C: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
        goto L_80801980;
    // 0x8080196C: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_80801970:
    // 0x80801970: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80801974: jal         0x800DC128
    // 0x80801978: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800DC128(rdram, ctx);
        goto after_3;
    // 0x80801978: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x8080197C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
L_80801980:
    // 0x80801980: jal         0x800B53A4
    // 0x80801984: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    func_800B53A4(rdram, ctx);
        goto after_4;
    // 0x80801984: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x80801988: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8080198C: jal         0x8008A0B0
    // 0x80801990: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    _subaddiemulti_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80801990: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_5:
    // 0x80801994: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80801998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080199C: jal         0x80103DFC
    // 0x808019A0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80103DFC(rdram, ctx);
        goto after_6;
    // 0x808019A0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_6:
    // 0x808019A4: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1320, 0X2044) << 16);
    // 0x808019A8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808019AC: addiu       $t7, $t7, 0x2044
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1320, 0X2044));
    // 0x808019B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808019B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808019B8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808019BC: jal         0x800BABB8
    // 0x808019C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x808019C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x808019C4: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x808019C8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1320, 0X208C) << 16);
    // 0x808019CC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808019D0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x808019D4: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x808019D8: jal         0x800BA670
    // 0x808019DC: lh          $a1, 0x208C($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1320, 0X208C));
    func_800BA670(rdram, ctx);
        goto after_8;
    // 0x808019DC: lh          $a1, 0x208C($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1320, 0X208C));
    after_8:
    // 0x808019E0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808019E4: jal         0x800BA22C
    // 0x808019E8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    func_800BA22C(rdram, ctx);
        goto after_9;
    // 0x808019E8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    after_9:
    // 0x808019EC: jal         0x800D3948
    // 0x808019F0: nop

    func_800D3948(rdram, ctx);
        goto after_10;
    // 0x808019F0: nop

    after_10:
    // 0x808019F4: beq         $v0, $zero, L_80801A28
    if (ctx->r2 == 0) {
        // 0x808019F8: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80801A28;
    }
    // 0x808019F8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x808019FC: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x80801A00: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1320, 0X1E50) << 16);
    // 0x80801A04: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x80801A08: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80801A0C: addu        $a3, $a3, $t1
    ctx->r7 = ADD32(ctx->r7, ctx->r9);
    // 0x80801A10: lh          $a3, 0x1E50($a3)
    ctx->r7 = MEM_H(ctx->r7, (int16_t)RELOC_LO16(1320, 0X1E50));
    // 0x80801A14: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80801A18: jal         0x800899A0
    // 0x80801A1C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _sumultiscore_entrypoint_7(rdram, ctx);
        goto after_11;
    // 0x80801A1C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_11:
    // 0x80801A20: b           L_80801A50
    // 0x80801A24: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
        goto L_80801A50;
    // 0x80801A24: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
L_80801A28:
    // 0x80801A28: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x80801A2C: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x80801A30: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(1320, 0X1E50) << 16);
    // 0x80801A34: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80801A38: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80801A3C: lh          $t5, 0x1E50($t5)
    ctx->r13 = MEM_H(ctx->r13, (int16_t)RELOC_LO16(1320, 0X1E50));
    // 0x80801A40: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80801A44: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80801A48: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80801A4C: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
L_80801A50:
    // 0x80801A50: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1320, 0X207C) << 16);
    // 0x80801A54: addiu       $a3, $a3, 0x207C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1320, 0X207C));
    // 0x80801A58: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x80801A5C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80801A60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801A64: jal         0x8010D930
    // 0x80801A68: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    func_8010D930(rdram, ctx);
        goto after_12;
    // 0x80801A68: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_12:
    // 0x80801A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A70: jal         0x80103DFC
    // 0x80801A74: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80103DFC(rdram, ctx);
        goto after_13;
    // 0x80801A74: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_13:
    // 0x80801A78: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80801A7C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1320, 0X1E50) << 16);
    // 0x80801A80: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80801A84: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80801A88: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80801A8C: lh          $a0, 0x1E50($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(1320, 0X1E50));
    // 0x80801A90: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80801A94: jal         0x80086468
    // 0x80801A98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _chscorepoints_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x80801A98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x80801A9C: jal         0x800FFAB0
    // 0x80801AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_15;
    // 0x80801AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80801AA4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80801AA8: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x80801AAC: lhu         $t1, 0x18($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X18);
    // 0x80801AB0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x80801AB4: andi        $t3, $t1, 0x1
    ctx->r11 = ctx->r9 & 0X1;
    // 0x80801AB8: beql        $t3, $zero, L_80801ACC
    if (ctx->r11 == 0) {
        // 0x80801ABC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80801ACC;
    }
    goto skip_0;
    // 0x80801ABC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80801AC0: jal         0x8010114C
    // 0x80801AC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_16;
    // 0x80801AC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x80801AC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801ACC:
    // 0x80801ACC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801AD0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80801AD4: jr          $ra
    // 0x80801AD8: nop

    return;
    // 0x80801AD8: nop

;}
RECOMP_FUNC void func_800EFB58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFB58: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800EFB5C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800EFB60: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800EFB64: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800EFB68: lw          $t0, 0x4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X4);
    // 0x800EFB6C: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800EFB70: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800EFB74: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x800EFB78: lw          $t3, 0x8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8);
    // 0x800EFB7C: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x800EFB80: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800EFB84: jr          $ra
    // 0x800EFB88: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    return;
    // 0x800EFB88: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
;}
RECOMP_FUNC void baeggsetup_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800170: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800174: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800178: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080017C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800180: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80800184: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80800188: jal         0x80094C0C
    // 0x8080018C: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    func_80094C0C(rdram, ctx);
        goto after_0;
    // 0x8080018C: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: jal         0x8009C128
    // 0x80800198: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x80800198: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8080019C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808001A0: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808001A4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808001A8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x808001AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808001B0: jal         0x800EE7F8
    // 0x808001B4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808001B4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: jal         0x800F3E84
    // 0x808001C0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800F3E84(rdram, ctx);
        goto after_3;
    // 0x808001C0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x808001C4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808001C8: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808001CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808001D0: jal         0x800136E4
    // 0x808001D4: add.s       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f10.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x808001D4: add.s       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f10.fl;
    after_4:
    // 0x808001D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001DC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808001E0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x808001E4: jal         0x800EEB9C
    // 0x808001E8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    func_800EEB9C(rdram, ctx);
        goto after_5;
    // 0x808001E8: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x808001EC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808001F0: jal         0x800EF04C
    // 0x808001F4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x808001F4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x808001F8: jal         0x800DC0C0
    // 0x808001FC: nop

    func_800DC0C0(rdram, ctx);
        goto after_7;
    // 0x808001FC: nop

    after_7:
    // 0x80800200: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800204: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800208: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8080020C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800210: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800214: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800218: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080021C: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80800220: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800224: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80800228: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8080022C: jal         0x800EEB9C
    // 0x80800230: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    func_800EEB9C(rdram, ctx);
        goto after_8;
    // 0x80800230: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    after_8:
    // 0x80800234: jal         0x800DC0C0
    // 0x80800238: nop

    func_800DC0C0(rdram, ctx);
        goto after_9;
    // 0x80800238: nop

    after_9:
    // 0x8080023C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800240: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800244: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80800248: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080024C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800250: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800254: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800258: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    // 0x8080025C: jal         0x800EE7F8
    // 0x80800260: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x80800260: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    after_10:
    // 0x80800264: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80800268: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8080026C: jal         0x800EE7F8
    // 0x80800270: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x80800270: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_11:
    // 0x80800274: lw          $a0, 0x70($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X70);
    // 0x80800278: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080027C: jal         0x800EE7F8
    // 0x80800280: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_12;
    // 0x80800280: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_12:
    // 0x80800284: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80800288: lw          $t7, 0x70($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X70);
    // 0x8080028C: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800290: addiu       $a0, $a0, 0x4A40
    ctx->r4 = ADD32(ctx->r4, 0X4A40);
    // 0x80800294: sb          $t6, 0x24($t7)
    MEM_B(0X24, ctx->r15) = ctx->r14;
    // 0x80800298: jal         0x80086D30
    // 0x8080029C: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x8080029C: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    after_13:
    // 0x808002A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808002AC: jr          $ra
    // 0x808002B0: nop

    return;
    // 0x808002B0: nop

;}
RECOMP_FUNC void basetup_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800220: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800228: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080022C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800230: jal         0x800F53D0
    // 0x80800234: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800F53D0(rdram, ctx);
        goto after_0;
    // 0x80800234: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800238: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080023C: jal         0x80084758
    // 0x80800240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _badata_entrypoint_35(rdram, ctx);
        goto after_1;
    // 0x80800240: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800244: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800248: jal         0x800EA068
    // 0x8080024C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800EA068(rdram, ctx);
        goto after_2;
    // 0x8080024C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_2:
    // 0x80800250: jal         0x8009E958
    // 0x80800254: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8009E958(rdram, ctx);
        goto after_3;
    // 0x80800254: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x80800258: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080025C: beq         $v0, $at, L_80800278
    if (ctx->r2 == ctx->r1) {
        // 0x80800260: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80800278;
    }
    // 0x80800260: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800264: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800268: beq         $v0, $at, L_80800298
    if (ctx->r2 == ctx->r1) {
        // 0x8080026C: nop
    
            goto L_80800298;
    }
    // 0x8080026C: nop

    // 0x80800270: b           L_808002AC
    // 0x80800274: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
        goto L_808002AC;
    // 0x80800274: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80800278:
    // 0x80800278: beql        $v1, $zero, L_808002AC
    if (ctx->r3 == 0) {
        // 0x8080027C: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_808002AC;
    }
    goto skip_0;
    // 0x8080027C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800280: jal         0x800C6E38
    // 0x80800284: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800C6E38(rdram, ctx);
        goto after_4;
    // 0x80800284: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_4:
    // 0x80800288: beql        $v0, $zero, L_808002AC
    if (ctx->r2 == 0) {
        // 0x8080028C: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_808002AC;
    }
    goto skip_1;
    // 0x8080028C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80800290: b           L_808002A8
    // 0x80800294: addiu       $s0, $zero, 0xC8
    ctx->r16 = ADD32(0, 0XC8);
        goto L_808002A8;
    // 0x80800294: addiu       $s0, $zero, 0xC8
    ctx->r16 = ADD32(0, 0XC8);
L_80800298:
    // 0x80800298: beq         $v1, $zero, L_808002A8
    if (ctx->r3 == 0) {
        // 0x8080029C: addiu       $s0, $zero, 0xC9
        ctx->r16 = ADD32(0, 0XC9);
            goto L_808002A8;
    }
    // 0x8080029C: addiu       $s0, $zero, 0xC9
    ctx->r16 = ADD32(0, 0XC9);
    // 0x808002A0: b           L_808002A8
    // 0x808002A4: addiu       $s0, $zero, 0xCB
    ctx->r16 = ADD32(0, 0XCB);
        goto L_808002A8;
    // 0x808002A4: addiu       $s0, $zero, 0xCB
    ctx->r16 = ADD32(0, 0XCB);
L_808002A8:
    // 0x808002A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_808002AC:
    // 0x808002AC: jal         0x800A3544
    // 0x808002B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A3544(rdram, ctx);
        goto after_5;
    // 0x808002B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808002B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808002B8: jal         0x8009E5C8
    // 0x808002BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x808002BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x808002C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002CC: jr          $ra
    // 0x808002D0: nop

    return;
    // 0x808002D0: nop

;}
RECOMP_FUNC void func_800B27E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B27E0: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x800B27E4: bne         $v1, $zero, L_800B27F4
    if (ctx->r3 != 0) {
        // 0x800B27E8: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_800B27F4;
    }
    // 0x800B27E8: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x800B27EC: jr          $ra
    // 0x800B27F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800B27F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B27F4:
    // 0x800B27F4: jr          $ra
    // 0x800B27F8: nop

    return;
    // 0x800B27F8: nop

;}
RECOMP_FUNC void glrecord_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80800004: addiu       $a3, $a3, -0x2A50
    ctx->r7 = ADD32(ctx->r7, -0X2A50);
    // 0x80800008: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x8080000C: lw          $t0, 0xC($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XC);
    // 0x80800010: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80800014: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800018: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8080001C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80800020: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80800024: slt         $a2, $t8, $t0
    ctx->r6 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80800028: sw          $t8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r24;
    // 0x8080002C: bne         $a2, $zero, L_8080003C
    if (ctx->r6 != 0) {
        // 0x80800030: addu        $v1, $t6, $t7
        ctx->r3 = ADD32(ctx->r14, ctx->r15);
            goto L_8080003C;
    }
    // 0x80800030: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800034: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80800038: addiu       $v1, $v1, -0x2A40
    ctx->r3 = ADD32(ctx->r3, -0X2A40);
L_8080003C:
    // 0x8080003C: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80800040: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80800044: sb          $t1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r9;
    // 0x80800048: lbu         $t2, 0x1($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1);
    // 0x8080004C: sb          $t2, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r10;
    // 0x80800050: lhu         $t3, 0x2($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X2);
    // 0x80800054: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x80800058: lbu         $t4, 0x4($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X4);
    // 0x8080005C: jr          $ra
    // 0x80800060: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    return;
    // 0x80800060: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
;}
RECOMP_FUNC void chweather_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(732, 0X488) << 16);
    // 0x808000E8: jr          $ra
    // 0x808000EC: addiu       $v0, $v0, 0x488
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X488));
    return;
    // 0x808000EC: addiu       $v0, $v0, 0x488
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(732, 0X488));
;}
RECOMP_FUNC void chfootwear_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800684: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2448, 0X788) << 16);
    // 0x80800688: jr          $ra
    // 0x8080068C: addiu       $v0, $v0, 0x788
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2448, 0X788));
    return;
    // 0x8080068C: addiu       $v0, $v0, 0x788
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2448, 0X788));
;}
RECOMP_FUNC void _sumole_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A40: syscall     800
    recomp_syscall_handler(rdram, ctx, 0x80089A40);
    return;
    // 0x80089A44: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void _glgamestore_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884B0: syscall     688
    recomp_syscall_handler(rdram, ctx, 0x800884B0);
    return;
    // 0x800884B4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800A0E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0E58: lw          $t6, 0x150($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X150);
    // 0x800A0E5C: jr          $ra
    // 0x800A0E60: lwc1        $f0, 0x8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8);
    return;
    // 0x800A0E60: lwc1        $f0, 0x8($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X8);
;}
RECOMP_FUNC void func_808001AC_chicywind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_808001AC_chicywind");
    // 0x808001AC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808001B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001B4: jal         0x800F54E4
    // 0x808001B8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x808001B8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001BC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808001C0: jal         0x800F5410
    // 0x808001C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x808001C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808001C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001CC: beq         $v0, $at, L_808001F8
    if (ctx->r2 == ctx->r1) {
        // 0x808001D0: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_808001F8;
    }
    // 0x808001D0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808001D4: beq         $v0, $at, L_808001EC
    if (ctx->r2 == ctx->r1) {
        // 0x808001D8: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_808001EC;
    }
    // 0x808001D8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x808001DC: beq         $v0, $at, L_808001EC
    if (ctx->r2 == ctx->r1) {
        // 0x808001E0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1280, 0X2F0) << 16);
            goto L_808001EC;
    }
    // 0x808001E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1280, 0X2F0) << 16);
    // 0x808001E4: b           L_80800244
    // 0x808001E8: lwc1        $f2, 0x2F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1280, 0X2F0));
        goto L_80800244;
    // 0x808001E8: lwc1        $f2, 0x2F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1280, 0X2F0));
L_808001EC:
    // 0x808001EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1280, 0X2F4) << 16);
    // 0x808001F0: b           L_80800244
    // 0x808001F4: lwc1        $f2, 0x2F4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1280, 0X2F4));
        goto L_80800244;
    // 0x808001F4: lwc1        $f2, 0x2F4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1280, 0X2F4));
L_808001F8:
    // 0x808001F8: jal         0x800F5578
    // 0x808001FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800F5578(rdram, ctx);
        goto after_2;
    // 0x808001FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80800200: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800204: jal         0x800F55A4
    // 0x80800208: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800F55A4(rdram, ctx);
        goto after_3;
    // 0x80800208: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8080020C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800210: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800214: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800218: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8080021C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800220: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800224: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800228: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x8080022C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800230: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800234: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80800238: jal         0x800F10B4
    // 0x8080023C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x8080023C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_4:
    // 0x80800240: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80800244:
    // 0x80800244: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800248: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8080024C: jal         0x800F5A00
    // 0x80800250: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_800F5A00(rdram, ctx);
        goto after_5;
    // 0x80800250: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x80800254: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80800258: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080025C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800260: jal         0x800EEAD4
    // 0x80800264: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800EEAD4(rdram, ctx);
        goto after_6;
    // 0x80800264: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_6:
    // 0x80800268: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8080026C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800270: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80800274: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800278: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080027C: lui         $a2, 0x44E1
    ctx->r6 = S32(0X44E1 << 16);
    // 0x80800280: lui         $a3, 0x4496
    ctx->r7 = S32(0X4496 << 16);
    // 0x80800284: jal         0x800F10B4
    // 0x80800288: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800288: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x8080028C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800290: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800294: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800298: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080029C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808002A0: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x808002A4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808002A8: jal         0x800F1DF4
    // 0x808002AC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    func_800F1DF4(rdram, ctx);
        goto after_8;
    // 0x808002AC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x808002B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002B4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808002B8: jal         0x800EEB9C
    // 0x808002BC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_800EEB9C(rdram, ctx);
        goto after_9;
    // 0x808002BC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_9:
    // 0x808002C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808002C4: jal         0x800F48BC
    // 0x808002C8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800F48BC(rdram, ctx);
        goto after_10;
    // 0x808002C8: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_10:
    // 0x808002CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002D0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

    // 0x808002DC: nop

;}
RECOMP_FUNC void _glgamedata_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088588: syscall     693
    recomp_syscall_handler(rdram, ctx, 0x80088588);
    return;
    // 0x8008858C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800E9DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9DF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9DFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9E00: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E9E04: jal         0x8001BAFC
    // 0x800E9E08: lw          $a0, 0x2DB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DB0);
    defrag(rdram, ctx);
        goto after_0;
    // 0x800E9E08: lw          $a0, 0x2DB0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DB0);
    after_0:
    // 0x800E9E0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9E10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E9E14: sw          $v0, 0x2DB0($at)
    MEM_W(0X2DB0, ctx->r1) = ctx->r2;
    // 0x800E9E18: jal         0x8001BAFC
    // 0x800E9E1C: lw          $a0, 0x2DB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DB4);
    defrag(rdram, ctx);
        goto after_1;
    // 0x800E9E1C: lw          $a0, 0x2DB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2DB4);
    after_1:
    // 0x800E9E20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E9E24: addiu       $a0, $a0, 0x2DB4
    ctx->r4 = ADD32(ctx->r4, 0X2DB4);
    // 0x800E9E28: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800E9E2C: beql        $v0, $t6, L_800E9E40
    if (ctx->r2 == ctx->r14) {
        // 0x800E9E30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E9E40;
    }
    goto skip_0;
    // 0x800E9E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E9E34: jal         0x800BE4C4
    // 0x800E9E38: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    func_800BE4C4(rdram, ctx);
        goto after_2;
    // 0x800E9E38: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    after_2:
    // 0x800E9E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E9E40:
    // 0x800E9E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9E44: jr          $ra
    // 0x800E9E48: nop

    return;
    // 0x800E9E48: nop

;}
RECOMP_FUNC void _bsswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083D98: syscall     94
    recomp_syscall_handler(rdram, ctx, 0x80083D98);
    return;
    // 0x80083D9C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801178_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801178: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080117C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801180: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801184: jal         0x8009E0DC
    // 0x80801188: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E0DC(rdram, ctx);
        goto after_0;
    // 0x80801188: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080118C: jal         0x8009E100
    // 0x80801190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E100(rdram, ctx);
        goto after_1;
    // 0x80801190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801198: jal         0x8009E74C
    // 0x8080119C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8009E74C(rdram, ctx);
        goto after_2;
    // 0x8080119C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_2:
    // 0x808011A0: beq         $v0, $zero, L_808011B0
    if (ctx->r2 == 0) {
        // 0x808011A4: nop
    
            goto L_808011B0;
    }
    // 0x808011A4: nop

    // 0x808011A8: jal         0x808000AC
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000AC_bsbfly(rdram, ctx);
        goto after_3;
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_808011B0:
    // 0x808011B0: jal         0x8009E704
    // 0x808011B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getNextState(rdram, ctx);
        goto after_4;
    // 0x808011B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808011B8: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x808011BC: beq         $v0, $at, L_808011D4
    if (ctx->r2 == ctx->r1) {
        // 0x808011C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808011D4;
    }
    // 0x808011C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011C4: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x808011C8: beq         $v0, $at, L_808011D4
    if (ctx->r2 == ctx->r1) {
        // 0x808011CC: addiu       $at, $zero, 0x2D
        ctx->r1 = ADD32(0, 0X2D);
            goto L_808011D4;
    }
    // 0x808011CC: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x808011D0: bne         $v0, $at, L_808011E0
    if (ctx->r2 != ctx->r1) {
        // 0x808011D4: addiu       $a1, $zero, 0x3EA
        ctx->r5 = ADD32(0, 0X3EA);
            goto L_808011E0;
    }
L_808011D4:
    // 0x808011D4: addiu       $a1, $zero, 0x3EA
    ctx->r5 = ADD32(0, 0X3EA);
    // 0x808011D8: jal         0x8009DBF0
    // 0x808011DC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DBF0(rdram, ctx);
        goto after_5;
    // 0x808011DC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_5:
L_808011E0:
    // 0x808011E0: jal         0x80800188
    // 0x808011E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800188_bsbfly(rdram, ctx);
        goto after_6;
    // 0x808011E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808011E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011EC: jal         0x800A0CF4
    // 0x808011F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_7;
    // 0x808011F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808011F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808011F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808011FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801200: jr          $ra
    // 0x80801204: nop

    return;
    // 0x80801204: nop

;}
RECOMP_FUNC void _gcgoto_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087AB0: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087AB0);
    return;
    // 0x80087AB4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void glsavegame_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800418: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080041C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80800420: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80800424: lw          $t7, 0x7618($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7618);
    // 0x80800428: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x8080042C: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800430: jr          $ra
    // 0x80800434: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    return;
    // 0x80800434: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
;}
RECOMP_FUNC void func_80800250_baeggfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800250: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80800254: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800258: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080025C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800260: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80800264: jal         0x800944F8
    // 0x80800268: lbu         $a1, 0x10($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X10);
    func_800944F8(rdram, ctx);
        goto after_0;
    // 0x80800268: lbu         $a1, 0x10($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X10);
    after_0:
    // 0x8080026C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800270: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x80800274: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80800278: bnel        $t7, $zero, L_80800298
    if (ctx->r15 != 0) {
        // 0x8080027C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800298;
    }
    goto skip_0;
    // 0x8080027C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800280: jal         0x80094510
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80094510(rdram, ctx);
        goto after_1;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800288: lw          $t8, 0x6C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X6C);
    // 0x8080028C: sb          $v0, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r2;
    // 0x80800290: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800298:
    // 0x80800298: jal         0x800944E0
    // 0x8080029C: lbu         $a1, 0x10($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X10);
    func_800944E0(rdram, ctx);
        goto after_2;
    // 0x8080029C: lbu         $a1, 0x10($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X10);
    after_2:
    // 0x808002A0: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x808002A4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x808002A8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x808002AC: lw          $v1, 0x4($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X4);
    // 0x808002B0: bne         $v1, $zero, L_808002F8
    if (ctx->r3 != 0) {
        // 0x808002B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F8;
    }
    // 0x808002B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002BC: jal         0x80800008
    // 0x808002C0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_80800008_baeggfire(rdram, ctx);
        goto after_3;
    // 0x808002C0: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_3:
    // 0x808002C4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808002C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808002D0: bne         $a2, $at, L_808002E8
    if (ctx->r6 != ctx->r1) {
        // 0x808002D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002E8;
    }
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: jal         0x80800180
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800180_baeggfire(rdram, ctx);
        goto after_4;
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002E0: b           L_80800344
    // 0x808002E4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
        goto L_80800344;
    // 0x808002E4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
L_808002E8:
    // 0x808002E8: jal         0x80800180
    // 0x808002EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800180_baeggfire(rdram, ctx);
        goto after_5;
    // 0x808002EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808002F0: b           L_80800344
    // 0x808002F4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
        goto L_80800344;
    // 0x808002F4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
L_808002F8:
    // 0x808002F8: bne         $t0, $zero, L_8080030C
    if (ctx->r8 != 0) {
        // 0x808002FC: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_8080030C;
    }
    // 0x808002FC: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80800300: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80800304: beq         $at, $zero, L_8080032C
    if (ctx->r1 == 0) {
        // 0x80800308: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080032C;
    }
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080030C:
    // 0x8080030C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800310: jal         0x80800008
    // 0x80800314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800008_baeggfire(rdram, ctx);
        goto after_6;
    // 0x80800314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: jal         0x80800180
    // 0x80800320: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800180_baeggfire(rdram, ctx);
        goto after_7;
    // 0x80800320: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800324: b           L_80800344
    // 0x80800328: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
        goto L_80800344;
    // 0x80800328: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
L_8080032C:
    // 0x8080032C: jal         0x80800008
    // 0x80800330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800008_baeggfire(rdram, ctx);
        goto after_8;
    // 0x80800330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: jal         0x80800180
    // 0x8080033C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800180_baeggfire(rdram, ctx);
        goto after_9;
    // 0x8080033C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x80800340: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
L_80800344:
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800348: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8080034C: beql        $t2, $zero, L_80800368
    if (ctx->r10 == 0) {
        // 0x80800350: lw          $v1, 0x6C($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X6C);
            goto L_80800368;
    }
    goto skip_1;
    // 0x80800350: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    skip_1:
    // 0x80800354: lw          $t4, 0x6C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X6C);
    // 0x80800358: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8080035C: b           L_80800374
    // 0x80800360: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
        goto L_80800374;
    // 0x80800360: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x80800364: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
L_80800368:
    // 0x80800368: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x8080036C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80800370: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_80800374:
    // 0x80800374: lw          $t7, 0x6C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X6C);
    // 0x80800378: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x8080037C: jal         0x80800414
    // 0x80800380: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    baeggfire_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80800380: sw          $zero, 0xC($t7)
    MEM_W(0XC, ctx->r15) = 0;
    after_10:
    // 0x80800384: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800388: jal         0x800EF368
    // 0x8080038C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    func_800EF368(rdram, ctx);
        goto after_11;
    // 0x8080038C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_11:
    // 0x80800390: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800394: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80800398: jal         0x800EE780
    // 0x8080039C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800EE780(rdram, ctx);
        goto after_12;
    // 0x8080039C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_12:
    // 0x808003A0: lw          $t8, 0x6C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X6C);
    // 0x808003A4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808003A8: lbu         $t9, 0x10($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X10);
    // 0x808003AC: bne         $t9, $at, L_808003BC
    if (ctx->r25 != ctx->r1) {
        // 0x808003B0: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(516, 0X690) << 16);
            goto L_808003BC;
    }
    // 0x808003B0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(516, 0X690) << 16);
    // 0x808003B4: b           L_808003C4
    // 0x808003B8: lwc1        $f0, 0x690($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(516, 0X690));
        goto L_808003C4;
    // 0x808003B8: lwc1        $f0, 0x690($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(516, 0X690));
L_808003BC:
    // 0x808003BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(516, 0X694) << 16);
    // 0x808003C0: lwc1        $f0, 0x694($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(516, 0X694));
L_808003C4:
    // 0x808003C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808003C8: jal         0x800EF368
    // 0x808003CC: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EF368(rdram, ctx);
        goto after_13;
    // 0x808003CC: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_13:
    // 0x808003D0: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x808003D4: addiu       $t1, $sp, 0x44
    ctx->r9 = ADD32(ctx->r29, 0X44);
    // 0x808003D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003DC: lbu         $a1, 0x10($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X10);
    // 0x808003E0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808003E4: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x808003E8: jal         0x80084A68
    // 0x808003EC: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    _baeggsetup_entrypoint_6(rdram, ctx);
        goto after_14;
    // 0x808003EC: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_14:
    // 0x808003F0: jal         0x80084AF0
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggcursor_entrypoint_8(rdram, ctx);
        goto after_15;
    // 0x808003F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808003F8: jal         0x800C6DA0
    // 0x808003FC: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    func_800C6DA0(rdram, ctx);
        goto after_16;
    // 0x808003FC: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_16:
    // 0x80800400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800404: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800408: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8080040C: jr          $ra
    // 0x80800410: nop

    return;
    // 0x80800410: nop

;}
RECOMP_FUNC void func_8008BD3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BD3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008BD40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BD44: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x8008BD48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008BD4C: beq         $t6, $zero, L_8008BD5C
    if (ctx->r14 == 0) {
        // 0x8008BD50: nop
    
            goto L_8008BD5C;
    }
    // 0x8008BD50: nop

    // 0x8008BD54: b           L_8008BD5C
    // 0x8008BD58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_8008BD5C;
    // 0x8008BD58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8008BD5C:
    // 0x8008BD5C: jal         0x8008BCEC
    // 0x8008BD60: nop

    func_8008BCEC(rdram, ctx);
        goto after_0;
    // 0x8008BD60: nop

    after_0:
    // 0x8008BD64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BD68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008BD6C: jr          $ra
    // 0x8008BD70: nop

    return;
    // 0x8008BD70: nop

;}
RECOMP_FUNC void func_8008BD74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BD74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008BD78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008BD7C: jal         0x8008BCEC
    // 0x8008BD80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008BCEC(rdram, ctx);
        goto after_0;
    // 0x8008BD80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8008BD84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008BD88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008BD8C: jr          $ra
    // 0x8008BD90: nop

    return;
    // 0x8008BD90: nop

;}
RECOMP_FUNC void func_8080237C_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080237C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BBC) << 16);
    // 0x80802380: lwc1        $f2, 0x4BBC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BBC));
    // 0x80802384: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80802388: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1840, 0X4BC0) << 16);
    // 0x8080238C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80802390: nop

    // 0x80802394: bc1f        L_808023A4
    if (!c1cs) {
        // 0x80802398: nop
    
            goto L_808023A4;
    }
    // 0x80802398: nop

    // 0x8080239C: jr          $ra
    // 0x808023A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x808023A0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808023A4:
    // 0x808023A4: lwc1        $f12, 0x4BC0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1840, 0X4BC0));
    // 0x808023A8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x808023AC: nop

    // 0x808023B0: bc1fl       L_808023C4
    if (!c1cs) {
        // 0x808023B4: lwc1        $f0, 0xC($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
            goto L_808023C4;
    }
    goto skip_0;
    // 0x808023B4: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    skip_0:
    // 0x808023B8: jr          $ra
    // 0x808023BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808023BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808023C0: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
L_808023C4:
    // 0x808023C4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x808023C8: nop

    // 0x808023CC: bc1fl       L_808023E0
    if (!c1cs) {
        // 0x808023D0: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_808023E0;
    }
    goto skip_1;
    // 0x808023D0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_1:
    // 0x808023D4: jr          $ra
    // 0x808023D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x808023D8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x808023DC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_808023E0:
    // 0x808023E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x808023E4: bc1f        L_808023F4
    if (!c1cs) {
        // 0x808023E8: nop
    
            goto L_808023F4;
    }
    // 0x808023E8: nop

    // 0x808023EC: jr          $ra
    // 0x808023F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x808023F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808023F4:
    // 0x808023F4: jr          $ra
    // 0x808023F8: nop

    return;
    // 0x808023F8: nop

;}
RECOMP_FUNC void babuzz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_8001A0B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A0B4: lui         $v0, 0x2
    ctx->r2 = S32(0X2 << 16);
    // 0x8001A0B8: jr          $ra
    // 0x8001A0BC: ori         $v0, $v0, 0x1D80
    ctx->r2 = ctx->r2 | 0X1D80;
    return;
    // 0x8001A0BC: ori         $v0, $v0, 0x1D80
    ctx->r2 = ctx->r2 | 0X1D80;
;}
