#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808014B4_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808014B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808014BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808014C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808014C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808014C8: jal         0x800845C8
    // 0x808014CC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _babounce_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808014CC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x808014D0: beq         $v0, $zero, L_808014E0
    if (ctx->r2 == 0) {
        // 0x808014D4: nop
    
            goto L_808014E0;
    }
    // 0x808014D4: nop

    // 0x808014D8: jal         0x808001D4
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001D4_bsbansack(rdram, ctx);
        goto after_1;
    // 0x808014DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_808014E0:
    // 0x808014E0: jal         0x80084608
    // 0x808014E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_10(rdram, ctx);
        goto after_2;
    // 0x808014E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808014E8: jal         0x8080119C
    // 0x808014EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080119C_bsbansack(rdram, ctx);
        goto after_3;
    // 0x808014EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808014F0: beq         $v0, $zero, L_808014FC
    if (ctx->r2 == 0) {
        // 0x808014F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808014FC;
    }
    // 0x808014F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014F8: addiu       $s1, $zero, 0x165
    ctx->r17 = ADD32(0, 0X165);
L_808014FC:
    // 0x808014FC: jal         0x8008DF8C
    // 0x80801500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008DF8C(rdram, ctx);
        goto after_4;
    // 0x80801500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80801504: beql        $v0, $zero, L_80801530
    if (ctx->r2 == 0) {
        // 0x80801508: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801530;
    }
    goto skip_0;
    // 0x80801508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080150C: jal         0x8009EF10
    // 0x80801510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_5;
    // 0x80801510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801514: blez        $v0, L_80801520
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801518: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801520;
    }
    // 0x80801518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080151C: addiu       $s1, $zero, 0x166
    ctx->r17 = ADD32(0, 0X166);
L_80801520:
    // 0x80801520: jal         0x80800084
    // 0x80801524: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800084_bsbansack(rdram, ctx);
        goto after_6;
    // 0x80801524: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x80801528: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080152C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801530:
    // 0x80801530: jal         0x8009E5C8
    // 0x80801534: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_7;
    // 0x80801534: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80801538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080153C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80801540: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801544: jr          $ra
    // 0x80801548: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80801548: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800BC0_chnewshovel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800BC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800BD0: jal         0x80100094
    // 0x80800BD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800BD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800BD8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800BDC: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BE4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800BE8: bltz        $t8, L_80800BF8
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800BEC: nop
    
            goto L_80800BF8;
    }
    // 0x80800BEC: nop

    // 0x80800BF0: b           L_80800C44
    // 0x80800BF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800C44;
    // 0x80800BF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800BF8:
    // 0x80800BF8: jal         0x80089BD8
    // 0x80800BFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800BFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800C00: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800C04: beq         $v0, $v1, L_80800C34
    if (ctx->r2 == ctx->r3) {
        // 0x80800C08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C34;
    }
    // 0x80800C08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C0C: jal         0x80089BD8
    // 0x80800C10: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800C10: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_2:
    // 0x80800C14: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800C18: beq         $v0, $v1, L_80800C34
    if (ctx->r2 == ctx->r3) {
        // 0x80800C1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800C34;
    }
    // 0x80800C1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C20: jal         0x80089BE0
    // 0x80800C24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiejoy_entrypoint_7(rdram, ctx);
        goto after_3;
    // 0x80800C24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800C28: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800C2C: bnel        $v0, $v1, L_80800C40
    if (ctx->r2 != ctx->r3) {
        // 0x80800C30: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_80800C40;
    }
    goto skip_0;
    // 0x80800C30: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_80800C34:
    // 0x80800C34: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800C38: sh          $v1, 0x10($t9)
    MEM_H(0X10, ctx->r25) = ctx->r3;
    // 0x80800C3C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_80800C40:
    // 0x80800C40: lh          $v0, 0x10($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X10);
L_80800C44:
    // 0x80800C44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800C50: jr          $ra
    // 0x80800C54: nop

    return;
    // 0x80800C54: nop

;}
RECOMP_FUNC void gccubesearch_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B0: jal         0x80800194
    // 0x808002B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gccubesearch_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808002B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808002B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002C0: jr          $ra
    // 0x808002C4: nop

    return;
    // 0x808002C4: nop

;}
RECOMP_FUNC void func_800A34D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A34D8: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A34DC: jr          $ra
    // 0x800A34E0: sw          $a1, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r5;
    return;
    // 0x800A34E0: sw          $a1, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _chexploder_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800866C8: syscall     354
    recomp_syscall_handler(rdram, ctx, 0x800866C8);
    return;
    // 0x800866CC: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void chboilerid_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800520: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800524: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800528: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080052C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800530: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800534: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800538: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8080053C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800540: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800544: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800548: jal         0x80106790
    // 0x8080054C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x8080054C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x80800550: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800554: jal         0x80100094
    // 0x80800558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080055C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800560: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800564: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800568: addu        $s3, $t7, $s0
    ctx->r19 = ADD32(ctx->r15, ctx->r16);
    // 0x8080056C: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x80800570: beq         $at, $zero, L_808005A4
    if (ctx->r1 == 0) {
        // 0x80800574: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_808005A4;
    }
L_80800574:
    // 0x80800574: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800578: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080057C: jal         0x80800700
    // 0x80800580: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80800700_chboilerid(rdram, ctx);
        goto after_2;
    // 0x80800580: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x80800584: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800588: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080058C: jal         0x8080079C
    // 0x80800590: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_8080079C_chboilerid(rdram, ctx);
        goto after_3;
    // 0x80800590: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_3:
    // 0x80800594: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800598: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8080059C: bne         $at, $zero, L_80800574
    if (ctx->r1 != 0) {
        // 0x808005A0: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80800574;
    }
    // 0x808005A0: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_808005A4:
    // 0x808005A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808005A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808005AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808005B0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808005B4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808005B8: jr          $ra
    // 0x808005BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808005BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800288_chlavaarchgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080028C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800290: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800294: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800298: jal         0x800D9078
    // 0x8080029C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x8080029C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x808002A0: beq         $v0, $zero, L_808002C0
    if (ctx->r2 == 0) {
        // 0x808002A4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808002C0;
    }
    // 0x808002A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002A8: jal         0x80101FDC
    // 0x808002AC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x808002AC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x808002B0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808002B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002B8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808002BC: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
L_808002C0:
    // 0x808002C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002C8: jr          $ra
    // 0x808002CC: nop

    return;
    // 0x808002CC: nop

;}
RECOMP_FUNC void _bskazfly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083388: syscall     57
    recomp_syscall_handler(rdram, ctx, 0x80083388);
    return;
    // 0x8008338C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8080128C_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080128C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801294: jal         0x80100094
    // 0x80801298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080129C: lbu         $t6, 0x3A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3A);
    // 0x808012A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x808012A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808012A8: blez        $t6, L_808012D0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808012AC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808012D0;
    }
    // 0x808012AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_808012B0:
    // 0x808012B0: sb          $zero, 0x34($a0)
    MEM_B(0X34, ctx->r4) = 0;
    // 0x808012B4: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x808012B8: lbu         $t7, 0x3A($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3A);
    // 0x808012BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x808012C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x808012C4: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808012C8: bne         $at, $zero, L_808012B0
    if (ctx->r1 != 0) {
        // 0x808012CC: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_808012B0;
    }
    // 0x808012CC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_808012D0:
    // 0x808012D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012D8: jr          $ra
    // 0x808012DC: nop

    return;
    // 0x808012DC: nop

;}
RECOMP_FUNC void glcutDll_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808004DC: jr          $ra
    // 0x808004E0: sb          $a0, 0x75EF($at)
    MEM_B(0X75EF, ctx->r1) = ctx->r4;
    return;
    // 0x808004E0: sb          $a0, 0x75EF($at)
    MEM_B(0X75EF, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void chmoley_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800938: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080093C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800940: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800944: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800948: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080094C: beql        $a1, $t6, L_808009DC
    if (ctx->r5 == ctx->r14) {
        // 0x80800950: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808009DC;
    }
    goto skip_0;
    // 0x80800950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800954: bne         $t6, $at, L_80800978
    if (ctx->r14 != ctx->r1) {
        // 0x80800958: addiu       $a0, $zero, 0x3A
        ctx->r4 = ADD32(0, 0X3A);
            goto L_80800978;
    }
    // 0x80800958: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x8080095C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800960: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    // 0x80800964: jal         0x800FCAE0
    // 0x80800968: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800FCAE0(rdram, ctx);
        goto after_0;
    // 0x80800968: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080096C: jal         0x800FCA90
    // 0x80800970: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    func_800FCA90(rdram, ctx);
        goto after_1;
    // 0x80800970: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_1:
    // 0x80800974: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80800978:
    // 0x80800978: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080097C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800980: jal         0x80102424
    // 0x80800984: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800984: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x80800988: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8080098C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800990: lhu         $v0, 0x72($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X72);
    // 0x80800994: srl         $t8, $v0, 10
    ctx->r24 = S32(U32(ctx->r2) >> 10);
    // 0x80800998: beq         $t8, $at, L_808009CC
    if (ctx->r24 == ctx->r1) {
        // 0x8080099C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808009CC;
    }
    // 0x8080099C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808009A0: beq         $t8, $at, L_808009B8
    if (ctx->r24 == ctx->r1) {
        // 0x808009A4: addiu       $a0, $zero, 0x3A
        ctx->r4 = ADD32(0, 0X3A);
            goto L_808009B8;
    }
    // 0x808009A4: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x808009A8: lbu         $t0, 0x65($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X65);
    // 0x808009AC: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x808009B0: b           L_808009D8
    // 0x808009B4: sb          $t1, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r9;
        goto L_808009D8;
    // 0x808009B4: sb          $t1, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r9;
L_808009B8:
    // 0x808009B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808009BC: jal         0x800FCAE0
    // 0x808009C0: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    func_800FCAE0(rdram, ctx);
        goto after_3;
    // 0x808009C0: addiu       $a2, $zero, 0x7D0
    ctx->r6 = ADD32(0, 0X7D0);
    after_3:
    // 0x808009C4: b           L_808009DC
    // 0x808009C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808009DC;
    // 0x808009C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009CC:
    // 0x808009CC: lbu         $t2, 0x65($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X65);
    // 0x808009D0: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x808009D4: sb          $t3, 0x65($a3)
    MEM_B(0X65, ctx->r7) = ctx->r11;
L_808009D8:
    // 0x808009D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009DC:
    // 0x808009DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009E0: jr          $ra
    // 0x808009E4: nop

    return;
    // 0x808009E4: nop

;}
RECOMP_FUNC void inflate_block_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C45C: sw          $ra, 0xA68($sp)
    MEM_W(0XA68, ctx->r29) = ctx->r31;
    // 0x8001C460: slti        $at, $fp, 0x3
    ctx->r1 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x8001C464: beq         $at, $zero, L_8001C48C
    if (ctx->r1 == 0) {
        // 0x8001C468: nop
    
            goto L_8001C48C;
    }
    // 0x8001C468: nop

    // 0x8001C46C: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
L_8001C470:
    // 0x8001C470: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8001C474: sllv        $at, $at, $fp
    ctx->r1 = S32(ctx->r1 << (ctx->r30 & 31));
    // 0x8001C478: or          $gp, $gp, $at
    ctx->r28 = ctx->r28 | ctx->r1;
    // 0x8001C47C: addiu       $fp, $fp, 0x8
    ctx->r30 = ADD32(ctx->r30, 0X8);
    // 0x8001C480: slti        $at, $fp, 0x3
    ctx->r1 = SIGNED(ctx->r30) < 0X3 ? 1 : 0;
    // 0x8001C484: bnel        $at, $zero, L_8001C470
    if (ctx->r1 != 0) {
        // 0x8001C488: lbu         $at, 0x0($s7)
        ctx->r1 = MEM_BU(ctx->r23, 0X0);
            goto L_8001C470;
    }
    goto skip_0;
    // 0x8001C488: lbu         $at, 0x0($s7)
    ctx->r1 = MEM_BU(ctx->r23, 0X0);
    skip_0:
L_8001C48C:
    // 0x8001C48C: andi        $at, $gp, 0x1
    ctx->r1 = ctx->r28 & 0X1;
    // 0x8001C490: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x8001C494: srl         $t3, $gp, 1
    ctx->r11 = S32(U32(ctx->r28) >> 1);
    // 0x8001C498: andi        $t3, $t3, 0x3
    ctx->r11 = ctx->r11 & 0X3;
    // 0x8001C49C: srl         $gp, $gp, 3
    ctx->r28 = S32(U32(ctx->r28) >> 3);
    // 0x8001C4A0: addiu       $fp, $fp, -0x3
    ctx->r30 = ADD32(ctx->r30, -0X3);
    // 0x8001C4A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001C4A8: bne         $t3, $at, L_8001C4C0
    if (ctx->r11 != ctx->r1) {
        // 0x8001C4AC: nop
    
            goto L_8001C4C0;
    }
    // 0x8001C4AC: nop

    // 0x8001C4B0: jal         0x8001C500
    // 0x8001C4B4: nop

    inflate_dynamic_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C4B4: nop

    after_0:
    // 0x8001C4B8: j           L_8001C4F4
    // 0x8001C4BC: nop

        goto L_8001C4F4;
    // 0x8001C4BC: nop

L_8001C4C0:
    // 0x8001C4C0: bne         $t3, $zero, L_8001C4D8
    if (ctx->r11 != 0) {
        // 0x8001C4C4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8001C4D8;
    }
    // 0x8001C4C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001C4C8: jal         0x8001C904
    // 0x8001C4CC: nop

    inflate_stored_recomp(rdram, ctx);
        goto after_1;
    // 0x8001C4CC: nop

    after_1:
    // 0x8001C4D0: j           L_8001C4F4
    // 0x8001C4D4: nop

        goto L_8001C4F4;
    // 0x8001C4D4: nop

L_8001C4D8:
    // 0x8001C4D8: bne         $t3, $at, L_8001C4F0
    if (ctx->r11 != ctx->r1) {
        // 0x8001C4DC: nop
    
            goto L_8001C4F0;
    }
    // 0x8001C4DC: nop

    // 0x8001C4E0: jal         0x8001CA2C
    // 0x8001C4E4: nop

    inflate_fixed_recomp(rdram, ctx);
        goto after_2;
    // 0x8001C4E4: nop

    after_2:
    // 0x8001C4E8: j           L_8001C4F4
    // 0x8001C4EC: nop

        goto L_8001C4F4;
    // 0x8001C4EC: nop

L_8001C4F0:
    // 0x8001C4F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8001C4F4:
    // 0x8001C4F4: lw          $ra, 0xA68($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA68);
    // 0x8001C4F8: jr          $ra
    // 0x8001C4FC: nop

    return;
    // 0x8001C4FC: nop

;}
RECOMP_FUNC void func_808004B0_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808004BC: jal         0x8009EF10
    // 0x808004C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    bastick_getZone(rdram, ctx);
        goto after_0;
    // 0x808004C0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808004C4: blez        $v0, L_808004D0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808004C8: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_808004D0;
    }
    // 0x808004C8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808004CC: addiu       $a1, $zero, 0x166
    ctx->r5 = ADD32(0, 0X166);
L_808004D0:
    // 0x808004D0: jal         0x80800084
    // 0x808004D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800084_bsbansack(rdram, ctx);
        goto after_1;
    // 0x808004D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808004D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004DC: jal         0x8009E5C8
    // 0x808004E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x808004E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x808004E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004EC: jr          $ra
    // 0x808004F0: nop

    return;
    // 0x808004F0: nop

;}
RECOMP_FUNC void func_80802450_chinflatableboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802458: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080245C: jal         0x80100094
    // 0x80802460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802460: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802464: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80802468: jal         0x808023B0
    // 0x8080246C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808023B0_chinflatableboss(rdram, ctx);
        goto after_1;
    // 0x8080246C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80802470: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80802474: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802478: lwc1        $f4, 0x44($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X44);
    // 0x8080247C: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80802480: jal         0x80101F24
    // 0x80802484: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_80101F24(rdram, ctx);
        goto after_2;
    // 0x80802484: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80802488: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8080248C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80802490: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802494: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80802498: lwc1        $f8, 0x44($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X44);
    // 0x8080249C: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x808024A0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808024A4: jal         0x80102FDC
    // 0x808024A8: nop

    func_80102FDC(rdram, ctx);
        goto after_3;
    // 0x808024A8: nop

    after_3:
    // 0x808024AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808024B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808024B4: jr          $ra
    // 0x808024B8: nop

    return;
    // 0x808024B8: nop

;}
RECOMP_FUNC void _chmolehill_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086938: syscall     397
    recomp_syscall_handler(rdram, ctx, 0x80086938);
    return;
    // 0x8008693C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_8080106C_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080106C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801070: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801074: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801078: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080107C: jal         0x808005DC
    // 0x80801080: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    bstrexsmall_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801080: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x80801084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801088: jal         0x8008CB10
    // 0x8080108C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x8080108C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_1:
    // 0x80801090: beq         $v0, $zero, L_808010A0
    if (ctx->r2 == 0) {
        // 0x80801094: nop
    
            goto L_808010A0;
    }
    // 0x80801094: nop

    // 0x80801098: jal         0x800951B4
    // 0x8080109C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_2;
    // 0x8080109C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_808010A0:
    // 0x808010A0: jal         0x80084600
    // 0x808010A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _babounce_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x808010A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808010A8: beq         $v0, $zero, L_808010B8
    if (ctx->r2 == 0) {
        // 0x808010AC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010B8;
    }
    // 0x808010AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B0: addiu       $t6, $zero, 0x145
    ctx->r14 = ADD32(0, 0X145);
    // 0x808010B4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_808010B8:
    // 0x808010B8: jal         0x8009E5C8
    // 0x808010BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x808010BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x808010C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808010C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808010C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808010CC: jr          $ra
    // 0x808010D0: nop

    return;
    // 0x808010D0: nop

;}
RECOMP_FUNC void bsmumcast_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800410: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800414: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(316, 0X4A0) << 16);
    // 0x80800418: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8080041C: jr          $ra
    // 0x80800420: lw          $v0, 0x4A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(316, 0X4A0));
    return;
    // 0x80800420: lw          $v0, 0x4A0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(316, 0X4A0));
;}
RECOMP_FUNC void func_800AE080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800AE088: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800AE08C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800AE090: bne         $a0, $zero, L_800AE0A0
    if (ctx->r4 != 0) {
        // 0x800AE094: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AE0A0;
    }
    // 0x800AE094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE098: b           L_800AE0A8
    // 0x800AE09C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AE0A8;
    // 0x800AE09C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800AE0A0:
    // 0x800AE0A0: jal         0x8001B798
    // 0x800AE0A4: nop

    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800AE0A4: nop

    after_0:
L_800AE0A8:
    // 0x800AE0A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE0AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE0B0: jr          $ra
    // 0x800AE0B4: nop

    return;
    // 0x800AE0B4: nop

;}
RECOMP_FUNC void _bsmumswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800838E8: syscall     81
    recomp_syscall_handler(rdram, ctx, 0x800838E8);
    return;
    // 0x800838EC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void subaddie3d_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80800010: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800014: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80800018: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8080001C: jal         0x800EE7F8
    // 0x80800020: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80800024: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800028: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080002C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800030: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800034: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800038: jal         0x800EE7F8
    // 0x8080003C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x8080003C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800040: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800044: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800048: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x8080004C: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80800050: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800054: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80800058: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8080005C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800060: jal         0x800BEF00
    // 0x80800064: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x80800064: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80800068: beq         $v0, $zero, L_80800080
    if (ctx->r2 == 0) {
        // 0x8080006C: lwc1        $f4, 0x20($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
            goto L_80800080;
    }
    // 0x8080006C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800070: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80800074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800078: b           L_80800084
    // 0x8080007C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
        goto L_80800084;
    // 0x8080007C: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
L_80800080:
    // 0x80800080: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800084:
    // 0x80800084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800088: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080008C: jr          $ra
    // 0x80800090: nop

    return;
    // 0x80800090: nop

;}
RECOMP_FUNC void func_800F55A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F55A4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F55A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F55AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F55B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F55B4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F55B8: jal         0x800A1760
    // 0x800F55BC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A1760(rdram, ctx);
        goto after_0;
    // 0x800F55BC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F55C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F55C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F55C8: jr          $ra
    // 0x800F55CC: nop

    return;
    // 0x800F55CC: nop

;}
RECOMP_FUNC void func_8002A318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A318: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002A31C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A320: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002A324: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002A328: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002A32C: jal         0x800E93AC
    // 0x8002A330: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800E93AC(rdram, ctx);
        goto after_0;
    // 0x8002A330: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x8002A334: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8002A338: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8002A33C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002A340: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8002A344: lw          $t8, 0x60($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X60);
    // 0x8002A348: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8002A34C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8002A350: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8002A354: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002A358: sb          $t6, 0x33($t1)
    MEM_B(0X33, ctx->r9) = ctx->r14;
    // 0x8002A35C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8002A360: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8002A364: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A368: lw          $t5, 0x60($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X60);
    // 0x8002A36C: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8002A370: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x8002A374: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8002A378: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8002A37C: addu        $t8, $t5, $t9
    ctx->r24 = ADD32(ctx->r13, ctx->r25);
    // 0x8002A380: sb          $t3, 0x3($t8)
    MEM_B(0X3, ctx->r24) = ctx->r11;
    // 0x8002A384: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002A388: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8002A38C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A390: lw          $t2, 0x60($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X60);
    // 0x8002A394: sll         $t7, $t4, 3
    ctx->r15 = S32(ctx->r12 << 3);
    // 0x8002A398: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x8002A39C: subu        $t7, $t7, $t4
    ctx->r15 = SUB32(ctx->r15, ctx->r12);
    // 0x8002A3A0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002A3A4: addu        $t5, $t2, $t7
    ctx->r13 = ADD32(ctx->r10, ctx->r15);
    // 0x8002A3A8: sb          $t6, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r14;
    // 0x8002A3AC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8002A3B0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002A3B4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A3B8: lw          $t0, 0x60($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X60);
    // 0x8002A3BC: sll         $t4, $t1, 3
    ctx->r12 = S32(ctx->r9 << 3);
    // 0x8002A3C0: lbu         $t3, 0x2($t9)
    ctx->r11 = MEM_BU(ctx->r25, 0X2);
    // 0x8002A3C4: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8002A3C8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8002A3CC: addu        $t2, $t0, $t4
    ctx->r10 = ADD32(ctx->r8, ctx->r12);
    // 0x8002A3D0: sb          $t3, 0x4($t2)
    MEM_B(0X4, ctx->r10) = ctx->r11;
    // 0x8002A3D4: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8002A3D8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8002A3DC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A3E0: lw          $t9, 0x60($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X60);
    // 0x8002A3E4: sll         $t1, $t8, 3
    ctx->r9 = S32(ctx->r24 << 3);
    // 0x8002A3E8: lh          $t6, 0xC($t7)
    ctx->r14 = MEM_H(ctx->r15, 0XC);
    // 0x8002A3EC: subu        $t1, $t1, $t8
    ctx->r9 = SUB32(ctx->r9, ctx->r24);
    // 0x8002A3F0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002A3F4: addu        $t0, $t9, $t1
    ctx->r8 = ADD32(ctx->r25, ctx->r9);
    // 0x8002A3F8: sh          $t6, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r14;
    // 0x8002A3FC: jal         0x800E9054
    // 0x8002A400: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800E9054(rdram, ctx);
        goto after_1;
    // 0x8002A400: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8002A404: bne         $v0, $zero, L_8002A414
    if (ctx->r2 != 0) {
        // 0x8002A408: nop
    
            goto L_8002A414;
    }
    // 0x8002A408: nop

    // 0x8002A40C: b           L_8002A694
    // 0x8002A410: nop

        goto L_8002A694;
    // 0x8002A410: nop

L_8002A414:
    // 0x8002A414: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002A418: jal         0x800E9300
    // 0x8002A41C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800E9300(rdram, ctx);
        goto after_2;
    // 0x8002A41C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8002A420: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8002A424: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002A428: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8002A42C: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8002A430: lw          $t7, 0x60($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X60);
    // 0x8002A434: sll         $t8, $t5, 3
    ctx->r24 = S32(ctx->r13 << 3);
    // 0x8002A438: lw          $t3, 0x0($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X0);
    // 0x8002A43C: subu        $t8, $t8, $t5
    ctx->r24 = SUB32(ctx->r24, ctx->r13);
    // 0x8002A440: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002A444: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002A448: sw          $t3, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r11;
    // 0x8002A44C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002A450: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8002A454: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8002A458: lw          $t4, 0x60($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X60);
    // 0x8002A45C: sll         $t5, $t2, 3
    ctx->r13 = S32(ctx->r10 << 3);
    // 0x8002A460: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x8002A464: subu        $t5, $t5, $t2
    ctx->r13 = SUB32(ctx->r13, ctx->r10);
    // 0x8002A468: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8002A46C: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8002A470: sw          $t6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->r14;
    // 0x8002A474: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8002A478: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002A47C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8002A480: lw          $t1, 0x60($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X60);
    // 0x8002A484: sll         $t2, $t0, 3
    ctx->r10 = S32(ctx->r8 << 3);
    // 0x8002A488: lw          $t3, 0x8($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X8);
    // 0x8002A48C: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8002A490: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8002A494: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8002A498: sw          $t3, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r11;
    // 0x8002A49C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8002A4A0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002A4A4: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x8002A4A8: lw          $t8, 0x60($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X60);
    // 0x8002A4AC: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8002A4B0: lbu         $t6, 0xC($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XC);
    // 0x8002A4B4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8002A4B8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8002A4BC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8002A4C0: sb          $t6, 0x25($t1)
    MEM_B(0X25, ctx->r9) = ctx->r14;
    // 0x8002A4C4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8002A4C8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8002A4CC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8002A4D0: lw          $t5, 0x60($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X60);
    // 0x8002A4D4: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8002A4D8: lbu         $t3, 0xD($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XD);
    // 0x8002A4DC: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8002A4E0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8002A4E4: addu        $t8, $t5, $t9
    ctx->r24 = ADD32(ctx->r13, ctx->r25);
    // 0x8002A4E8: sb          $t3, 0x26($t8)
    MEM_B(0X26, ctx->r24) = ctx->r11;
    // 0x8002A4EC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002A4F0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002A4F4: lw          $t6, 0x60($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X60);
    // 0x8002A4F8: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x8002A4FC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8002A500: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8002A504: addu        $t4, $t6, $t2
    ctx->r12 = ADD32(ctx->r14, ctx->r10);
    // 0x8002A508: sb          $zero, 0x27($t4)
    MEM_B(0X27, ctx->r12) = 0;
    // 0x8002A50C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8002A510: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8002A514: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A518: lw          $t3, 0x60($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X60);
    // 0x8002A51C: sll         $t0, $t8, 3
    ctx->r8 = S32(ctx->r24 << 3);
    // 0x8002A520: lbu         $t5, 0x4($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X4);
    // 0x8002A524: subu        $t0, $t0, $t8
    ctx->r8 = SUB32(ctx->r8, ctx->r24);
    // 0x8002A528: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8002A52C: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x8002A530: sb          $t5, 0x28($t1)
    MEM_B(0X28, ctx->r9) = ctx->r13;
    // 0x8002A534: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8002A538: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002A53C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A540: lw          $t7, 0x60($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X60);
    // 0x8002A544: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x8002A548: lbu         $t2, 0x5($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X5);
    // 0x8002A54C: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x8002A550: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8002A554: addu        $t3, $t7, $t8
    ctx->r11 = ADD32(ctx->r15, ctx->r24);
    // 0x8002A558: sb          $t2, 0x29($t3)
    MEM_B(0X29, ctx->r11) = ctx->r10;
    // 0x8002A55C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002A560: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8002A564: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A568: lw          $t6, 0x60($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X60);
    // 0x8002A56C: sll         $t9, $t4, 3
    ctx->r25 = S32(ctx->r12 << 3);
    // 0x8002A570: lbu         $t5, 0x6($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X6);
    // 0x8002A574: subu        $t9, $t9, $t4
    ctx->r25 = SUB32(ctx->r25, ctx->r12);
    // 0x8002A578: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8002A57C: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x8002A580: sb          $t5, 0x2A($t7)
    MEM_B(0X2A, ctx->r15) = ctx->r13;
    // 0x8002A584: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8002A588: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8002A58C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A590: lw          $t0, 0x60($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X60);
    // 0x8002A594: sll         $t4, $t1, 3
    ctx->r12 = S32(ctx->r9 << 3);
    // 0x8002A598: lbu         $t2, 0x7($t8)
    ctx->r10 = MEM_BU(ctx->r24, 0X7);
    // 0x8002A59C: subu        $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8002A5A0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8002A5A4: addu        $t6, $t0, $t4
    ctx->r14 = ADD32(ctx->r8, ctx->r12);
    // 0x8002A5A8: sb          $t2, 0x2B($t6)
    MEM_B(0X2B, ctx->r14) = ctx->r10;
    // 0x8002A5AC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8002A5B0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8002A5B4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A5B8: lw          $t8, 0x60($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X60);
    // 0x8002A5BC: sll         $t1, $t3, 3
    ctx->r9 = S32(ctx->r11 << 3);
    // 0x8002A5C0: lbu         $t5, 0x8($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X8);
    // 0x8002A5C4: subu        $t1, $t1, $t3
    ctx->r9 = SUB32(ctx->r9, ctx->r11);
    // 0x8002A5C8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8002A5CC: addu        $t0, $t8, $t1
    ctx->r8 = ADD32(ctx->r24, ctx->r9);
    // 0x8002A5D0: sb          $t5, 0x2C($t0)
    MEM_B(0X2C, ctx->r8) = ctx->r13;
    // 0x8002A5D4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8002A5D8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8002A5DC: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A5E0: lw          $t9, 0x60($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X60);
    // 0x8002A5E4: sll         $t3, $t7, 3
    ctx->r11 = S32(ctx->r15 << 3);
    // 0x8002A5E8: lbu         $t2, 0x9($t4)
    ctx->r10 = MEM_BU(ctx->r12, 0X9);
    // 0x8002A5EC: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x8002A5F0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8002A5F4: addu        $t8, $t9, $t3
    ctx->r24 = ADD32(ctx->r25, ctx->r11);
    // 0x8002A5F8: sb          $t2, 0x2D($t8)
    MEM_B(0X2D, ctx->r24) = ctx->r10;
    // 0x8002A5FC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002A600: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002A604: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A608: lw          $t4, 0x60($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X60);
    // 0x8002A60C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8002A610: lbu         $t5, 0xA($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0XA);
    // 0x8002A614: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8002A618: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8002A61C: addu        $t9, $t4, $t7
    ctx->r25 = ADD32(ctx->r12, ctx->r15);
    // 0x8002A620: sb          $t5, 0x2E($t9)
    MEM_B(0X2E, ctx->r25) = ctx->r13;
    // 0x8002A624: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8002A628: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8002A62C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8002A630: lw          $t1, 0x60($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X60);
    // 0x8002A634: sll         $t6, $t0, 3
    ctx->r14 = S32(ctx->r8 << 3);
    // 0x8002A638: lbu         $t2, 0xB($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0XB);
    // 0x8002A63C: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x8002A640: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8002A644: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x8002A648: sb          $t2, 0x2F($t4)
    MEM_B(0X2F, ctx->r12) = ctx->r10;
    // 0x8002A64C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8002A650: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002A654: lw          $t5, 0x60($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X60);
    // 0x8002A658: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x8002A65C: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x8002A660: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8002A664: addu        $t8, $t5, $t3
    ctx->r24 = ADD32(ctx->r13, ctx->r11);
    // 0x8002A668: sb          $zero, 0x24($t8)
    MEM_B(0X24, ctx->r24) = 0;
    // 0x8002A66C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002A670: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002A674: lw          $t1, 0x60($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X60);
    // 0x8002A678: sll         $t2, $t6, 3
    ctx->r10 = S32(ctx->r14 << 3);
    // 0x8002A67C: subu        $t2, $t2, $t6
    ctx->r10 = SUB32(ctx->r10, ctx->r14);
    // 0x8002A680: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8002A684: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8002A688: sb          $zero, 0x31($t4)
    MEM_B(0X31, ctx->r12) = 0;
    // 0x8002A68C: b           L_8002A694
    // 0x8002A690: nop

        goto L_8002A694;
    // 0x8002A690: nop

L_8002A694:
    // 0x8002A694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A698: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002A69C: jr          $ra
    // 0x8002A6A0: nop

    return;
    // 0x8002A6A0: nop

;}
RECOMP_FUNC void _bsfirstp_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084308: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x80084308);
    return;
    // 0x8008430C: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void func_80800008_bamum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080000C: lw          $t6, 0xD0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD0);
    // 0x80800010: jr          $ra
    // 0x80800014: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
    return;
    // 0x80800014: swc1        $f4, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->f4.u32l;
;}
RECOMP_FUNC void _ch1pfreeze_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873F0: syscall     564
    recomp_syscall_handler(rdram, ctx, 0x800873F0);
    return;
    // 0x800873F4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800A24_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A30: jal         0x800839E8
    // 0x80800A34: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800A34: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800A38: beq         $v0, $zero, L_80800A44
    if (ctx->r2 == 0) {
        // 0x80800A3C: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A44;
    }
    // 0x80800A3C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A40: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
L_80800A44:
    // 0x80800A44: jal         0x8009E5C8
    // 0x80800A48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x80800A48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A54: jr          $ra
    // 0x80800A58: nop

    return;
    // 0x80800A58: nop

;}
RECOMP_FUNC void func_808001D0_chbanjocurrent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x808001D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D8: jal         0x80800000
    // 0x808001DC: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    func_80800000_chbanjocurrent(rdram, ctx);
        goto after_0;
    // 0x808001DC: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001E0: beql        $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808001E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004FC;
    }
    goto skip_0;
    // 0x808001E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001E8: jal         0x800F54E4
    // 0x808001EC: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808001EC: nop

    after_1:
    // 0x808001F0: jal         0x8008FF94
    // 0x808001F4: sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    func_8008FF94(rdram, ctx);
        goto after_2;
    // 0x808001F4: sw          $v0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r2;
    after_2:
    // 0x808001F8: beq         $v0, $zero, L_808004F8
    if (ctx->r2 == 0) {
        // 0x808001FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808004F8;
    }
    // 0x808001FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800200: bnel        $v0, $at, L_80800278
    if (ctx->r2 != ctx->r1) {
        // 0x80800204: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80800278;
    }
    goto skip_1;
    // 0x80800204: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x80800208: jal         0x800F5E7C
    // 0x8080020C: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    func_800F5E7C(rdram, ctx);
        goto after_3;
    // 0x8080020C: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    after_3:
    // 0x80800210: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800214: jal         0x800F5F7C
    // 0x80800218: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    func_800F5F7C(rdram, ctx);
        goto after_4;
    // 0x80800218: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    after_4:
    // 0x8080021C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800220: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800224: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800228: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8080022C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800230: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x80800234: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80800238: bc1tl       L_808004FC
    if (c1cs) {
        // 0x8080023C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004FC;
    }
    goto skip_2;
    // 0x8080023C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800240: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800244: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800248: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(756, 0X7B0) << 16);
    // 0x8080024C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80800250: nop

    // 0x80800254: bc1f        L_80800260
    if (!c1cs) {
        // 0x80800258: nop
    
            goto L_80800260;
    }
    // 0x80800258: nop

    // 0x8080025C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80800260:
    // 0x80800260: lwc1        $f10, 0x7B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(756, 0X7B0));
    // 0x80800264: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80800268: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8080026C: b           L_80800284
    // 0x80800270: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
        goto L_80800284;
    // 0x80800270: swc1        $f18, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f18.u32l;
    // 0x80800274: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80800278:
    // 0x80800278: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080027C: nop

    // 0x80800280: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
L_80800284:
    // 0x80800284: jal         0x800F5E50
    // 0x80800288: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    func_800F5E50(rdram, ctx);
        goto after_5;
    // 0x80800288: lw          $a0, 0xCC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XCC);
    after_5:
    // 0x8080028C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80800290: lui         $at, 0x7800
    ctx->r1 = S32(0X7800 << 16);
    // 0x80800294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800298: and         $t6, $v1, $at
    ctx->r14 = ctx->r3 & ctx->r1;
    // 0x8080029C: srl         $v1, $t6, 27
    ctx->r3 = S32(U32(ctx->r14) >> 27);
    // 0x808002A0: beq         $v1, $zero, L_808004F8
    if (ctx->r3 == 0) {
        // 0x808002A4: lw          $t8, 0xD8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XD8);
            goto L_808004F8;
    }
    // 0x808002A4: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x808002A8: lwc1        $f0, 0x48($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X48);
    // 0x808002AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808002B0: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    // 0x808002B4: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x808002B8: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x808002BC: nop

    // 0x808002C0: bc1t        L_808002E4
    if (c1cs) {
        // 0x808002C4: nop
    
            goto L_808002E4;
    }
    // 0x808002C4: nop

    // 0x808002C8: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x808002CC: nop

    // 0x808002D0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808002D4: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x808002D8: nop

    // 0x808002DC: bc1fl       L_808004FC
    if (!c1cs) {
        // 0x808002E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004FC;
    }
    goto skip_3;
    // 0x808002E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_808002E4:
    // 0x808002E4: jal         0x80800050
    // 0x808002E8: addiu       $a3, $sp, 0x78
    ctx->r7 = ADD32(ctx->r29, 0X78);
    func_80800050_chbanjocurrent(rdram, ctx);
        goto after_6;
    // 0x808002E8: addiu       $a3, $sp, 0x78
    ctx->r7 = ADD32(ctx->r29, 0X78);
    after_6:
    // 0x808002EC: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x808002F0: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x808002F4: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x808002F8: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808002FC: addiu       $v0, $sp, 0x9C
    ctx->r2 = ADD32(ctx->r29, 0X9C);
    // 0x80800300: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80800304: mflo        $t1
    ctx->r9 = lo;
    // 0x80800308: addu        $a1, $v0, $t1
    ctx->r5 = ADD32(ctx->r2, ctx->r9);
    // 0x8080030C: nop

    // 0x80800310: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800314: mflo        $t3
    ctx->r11 = lo;
    // 0x80800318: addu        $a2, $v0, $t3
    ctx->r6 = ADD32(ctx->r2, ctx->r11);
    // 0x8080031C: jal         0x800EFB24
    // 0x80800320: nop

    func_800EFB24(rdram, ctx);
        goto after_7;
    // 0x80800320: nop

    after_7:
    // 0x80800324: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80800328: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x8080032C: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x80800330: sll         $t4, $t0, 3
    ctx->r12 = S32(ctx->r8 << 3);
    // 0x80800334: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80800338: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8080033C: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x80800340: lwc1        $f12, 0x0($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80800344: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80800348: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8080034C: sub.s       $f2, $f16, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80800350: c.eq.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl == ctx->f18.fl;
    // 0x80800354: nop

    // 0x80800358: bc1t        L_80800414
    if (c1cs) {
        // 0x8080035C: nop
    
            goto L_80800414;
    }
    // 0x8080035C: nop

    // 0x80800360: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x80800364: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80800368: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x8080036C: sll         $t9, $a3, 3
    ctx->r25 = S32(ctx->r7 << 3);
    // 0x80800370: addu        $t1, $a2, $t9
    ctx->r9 = ADD32(ctx->r6, ctx->r25);
    // 0x80800374: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80800378: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8080037C: addiu       $t3, $sp, 0x9C
    ctx->r11 = ADD32(ctx->r29, 0X9C);
    // 0x80800380: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80800384: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x80800388: addiu       $v1, $sp, 0x60
    ctx->r3 = ADD32(ctx->r29, 0X60);
    // 0x8080038C: addiu       $v0, $sp, 0x6C
    ctx->r2 = ADD32(ctx->r29, 0X6C);
    // 0x80800390: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80800394: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x80800398: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8080039C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808003A0: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x808003A4: beql        $v0, $a1, L_808003D4
    if (ctx->r2 == ctx->r5) {
        // 0x808003A8: lwc1        $f16, 0x0($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
            goto L_808003D4;
    }
    goto skip_4;
    // 0x808003A8: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    skip_4:
L_808003AC:
    // 0x808003AC: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x808003B0: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808003B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808003B8: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x808003BC: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x808003C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808003C4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808003C8: bne         $v0, $a1, L_808003AC
    if (ctx->r2 != ctx->r5) {
        // 0x808003CC: swc1        $f16, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
            goto L_808003AC;
    }
    // 0x808003CC: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x808003D0: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
L_808003D4:
    // 0x808003D4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808003D8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808003DC: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x808003E0: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x808003E4: sll         $t4, $a3, 2
    ctx->r12 = S32(ctx->r7 << 2);
    // 0x808003E8: subu        $t4, $t4, $a3
    ctx->r12 = SUB32(ctx->r12, ctx->r7);
    // 0x808003EC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x808003F0: addiu       $t5, $sp, 0x9C
    ctx->r13 = ADD32(ctx->r29, 0X9C);
    // 0x808003F4: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x808003F8: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x808003FC: jal         0x800EFB24
    // 0x80800400: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x80800400: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    after_8:
    // 0x80800404: jal         0x800EF2A0
    // 0x80800408: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_800EF2A0(rdram, ctx);
        goto after_9;
    // 0x80800408: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_9:
    // 0x8080040C: b           L_80800420
    // 0x80800410: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
        goto L_80800420;
    // 0x80800410: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
L_80800414:
    // 0x80800414: jal         0x800EFD24
    // 0x80800418: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    func_800EFD24(rdram, ctx);
        goto after_10;
    // 0x80800418: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_10:
    // 0x8080041C: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
L_80800420:
    // 0x80800420: jal         0x800EF3DC
    // 0x80800424: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    func_800EF3DC(rdram, ctx);
        goto after_11;
    // 0x80800424: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_11:
    // 0x80800428: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x8080042C: jal         0x800EF3DC
    // 0x80800430: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    func_800EF3DC(rdram, ctx);
        goto after_12;
    // 0x80800430: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_12:
    // 0x80800434: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80800438: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x8080043C: jal         0x800EE97C
    // 0x80800440: addiu       $a2, $sp, 0xB4
    ctx->r6 = ADD32(ctx->r29, 0XB4);
    func_800EE97C(rdram, ctx);
        goto after_13;
    // 0x80800440: addiu       $a2, $sp, 0xB4
    ctx->r6 = ADD32(ctx->r29, 0XB4);
    after_13:
    // 0x80800444: jal         0x800EF2A0
    // 0x80800448: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_800EF2A0(rdram, ctx);
        goto after_14;
    // 0x80800448: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_14:
    // 0x8080044C: jal         0x80013A7C
    // 0x80800450: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    func_80013A7C(rdram, ctx);
        goto after_15;
    // 0x80800450: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    after_15:
    // 0x80800454: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(756, 0X7B4) << 16);
    // 0x80800458: lwc1        $f4, 0x7B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(756, 0X7B4));
    // 0x8080045C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800460: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800464: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800468: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x8080046C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800470: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800474: jal         0x800EF334
    // 0x80800478: nop

    func_800EF334(rdram, ctx);
        goto after_16;
    // 0x80800478: nop

    after_16:
    // 0x8080047C: jal         0x80090794
    // 0x80800480: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_80090794(rdram, ctx);
        goto after_17;
    // 0x80800480: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_17:
    // 0x80800484: jal         0x800D8FF8
    // 0x80800488: nop

    func_800D8FF8(rdram, ctx);
        goto after_18;
    // 0x80800488: nop

    after_18:
    // 0x8080048C: lw          $t6, 0xD8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD8);
    // 0x80800490: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800494: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80800498: lhu         $t7, 0x76($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X76);
    // 0x8080049C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808004A0: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x808004A4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x808004A8: bgez        $t8, L_808004BC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808004AC: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_808004BC;
    }
    // 0x808004AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808004B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004B4: nop

    // 0x808004B8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_808004BC:
    // 0x808004BC: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x808004C0: lwc1        $f10, 0xC8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x808004C4: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x808004C8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x808004CC: jal         0x800EF174
    // 0x808004D0: nop

    func_800EF174(rdram, ctx);
        goto after_19;
    // 0x808004D0: nop

    after_19:
    // 0x808004D4: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x808004D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808004DC: lwc1        $f4, 0x48($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X48);
    // 0x808004E0: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x808004E4: nop

    // 0x808004E8: bc1tl       L_808004FC
    if (c1cs) {
        // 0x808004EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808004FC;
    }
    goto skip_5;
    // 0x808004EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x808004F0: jal         0x800907C0
    // 0x808004F4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_800907C0(rdram, ctx);
        goto after_20;
    // 0x808004F4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_20:
L_808004F8:
    // 0x808004F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808004FC:
    // 0x808004FC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x80800500: jr          $ra
    // 0x80800504: nop

    return;
    // 0x80800504: nop

;}
RECOMP_FUNC void chchuffy_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802298: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1700, 0X26F4) << 16);
    // 0x8080229C: jr          $ra
    // 0x808022A0: addiu       $v0, $v0, 0x26F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1700, 0X26F4));
    return;
    // 0x808022A0: addiu       $v0, $v0, 0x26F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1700, 0X26F4));
    // 0x808022A4: nop

    // 0x808022A8: nop

    // 0x808022AC: nop

;}
RECOMP_FUNC void func_80800908_chstonedartgunhead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800908: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8080090C: sw          $s7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r23;
    // 0x80800910: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800914: sw          $s6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r22;
    // 0x80800918: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x8080091C: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x80800920: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80800924: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80800928: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x8080092C: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80800930: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800934: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800938: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080093C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800940: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80800944: lwc1        $f20, 0x38($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800948: addiu       $s2, $sp, 0x70
    ctx->r18 = ADD32(ctx->r29, 0X70);
    // 0x8080094C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800950: jal         0x800EC398
    // 0x80800954: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EC398(rdram, ctx);
        goto after_0;
    // 0x80800954: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80800958: addiu       $s3, $sp, 0x7C
    ctx->r19 = ADD32(ctx->r29, 0X7C);
    // 0x8080095C: addiu       $a1, $s7, 0x4
    ctx->r5 = ADD32(ctx->r23, 0X4);
    // 0x80800960: sw          $a1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r5;
    // 0x80800964: jal         0x800EE7F8
    // 0x80800968: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800968: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x8080096C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800970: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800974: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800978: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XE04) << 16);
    // 0x8080097C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80800980: lwc1        $f26, 0xE04($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1872, 0XE04));
    // 0x80800984: lui         $at, 0x42E6
    ctx->r1 = S32(0X42E6 << 16);
    // 0x80800988: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8080098C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800990: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(1872, 0XEE0) << 16);
    // 0x80800994: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(1872, 0XEBC) << 16);
    // 0x80800998: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8080099C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808009A0: addiu       $s4, $s4, 0xEBC
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(1872, 0XEBC));
    // 0x808009A4: addiu       $s5, $s5, 0xEE0
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(1872, 0XEE0));
    // 0x808009A8: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x808009AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808009B0: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
L_808009B4:
    // 0x808009B4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808009B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808009BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808009C0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x808009C4: jal         0x800BABB8
    // 0x808009C8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x808009C8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x808009CC: lwc1        $f16, 0x8($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X8);
    // 0x808009D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808009D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009D8: sub.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x808009DC: trunc.w.s   $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x808009E0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808009E4: nop

    // 0x808009E8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x808009EC: jal         0x800BA4D0
    // 0x808009F0: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    func_800BA4D0(rdram, ctx);
        goto after_3;
    // 0x808009F0: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    after_3:
    // 0x808009F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808009F8: jal         0x800BA22C
    // 0x808009FC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800BA22C(rdram, ctx);
        goto after_4;
    // 0x808009FC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x80800A00: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800A04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800A08: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80800A0C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800A10: jal         0x800BBCB8
    // 0x80800A14: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    func_800BBCB8(rdram, ctx);
        goto after_5;
    // 0x80800A14: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_5:
    // 0x80800A18: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800A1C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80800A20: sub.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x80800A24: add.s       $f8, $f4, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80800A28: bne         $s0, $s6, L_808009B4
    if (ctx->r16 != ctx->r22) {
        // 0x80800A2C: swc1        $f8, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
            goto L_808009B4;
    }
    // 0x80800A2C: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    // 0x80800A30: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XE08) << 16);
    // 0x80800A34: lwc1        $f10, 0xE08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1872, 0XE08));
    // 0x80800A38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1872, 0XE0C) << 16);
    // 0x80800A3C: lwc1        $f16, 0xE0C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1872, 0XE0C));
    // 0x80800A40: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800A44: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800A48: addiu       $a0, $zero, 0x413
    ctx->r4 = ADD32(0, 0X413);
    // 0x80800A4C: addiu       $a2, $zero, 0x7D00
    ctx->r6 = ADD32(0, 0X7D00);
    // 0x80800A50: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x80800A54: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800A58: jal         0x800C4104
    // 0x80800A5C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_800C4104(rdram, ctx);
        goto after_6;
    // 0x80800A5C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x80800A60: jal         0x800FFAB0
    // 0x80800A64: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x80800A64: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_7:
    // 0x80800A68: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80800A6C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800A70: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800A74: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800A78: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800A7C: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x80800A80: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80800A84: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x80800A88: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x80800A8C: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x80800A90: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x80800A94: lw          $s6, 0x54($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X54);
    // 0x80800A98: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x80800A9C: jr          $ra
    // 0x80800AA0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80800AA0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_8080398C_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080398C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80803990: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80803994: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80803998: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080399C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x808039A0: jal         0x80106790
    // 0x808039A4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808039A4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x808039A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808039AC: jal         0x80100094
    // 0x808039B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808039B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x808039B4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808039B8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x808039BC: jal         0x800EE7F8
    // 0x808039C0: addiu       $a1, $v0, 0x78
    ctx->r5 = ADD32(ctx->r2, 0X78);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808039C0: addiu       $a1, $v0, 0x78
    ctx->r5 = ADD32(ctx->r2, 0X78);
    after_2:
    // 0x808039C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808039C8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x808039CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808039D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808039D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808039D8: jal         0x800EFA4C
    // 0x808039DC: nop

    func_800EFA4C(rdram, ctx);
        goto after_3;
    // 0x808039DC: nop

    after_3:
    // 0x808039E0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x808039E4: addiu       $a0, $a0, 0x17D0
    ctx->r4 = ADD32(ctx->r4, 0X17D0);
    // 0x808039E8: jal         0x800DF47C
    // 0x808039EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800DF47C(rdram, ctx);
        goto after_4;
    // 0x808039EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x808039F0: jal         0x801039E4
    // 0x808039F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_5;
    // 0x808039F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x808039F8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x808039FC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80803A00: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80803A04: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80803A08: jal         0x800DE448
    // 0x80803A0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800DE448(rdram, ctx);
        goto after_6;
    // 0x80803A0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80803A10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80803A14: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80803A18: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80803A1C: jr          $ra
    // 0x80803A20: nop

    return;
    // 0x80803A20: nop

;}
RECOMP_FUNC void func_80802BF4_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802BF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802BF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802BFC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80802C00: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80802C04: lbu         $t6, 0x178($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X178);
    // 0x80802C08: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80802C0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802C10: blezl       $t6, L_80802C70
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80802C14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802C70;
    }
    goto skip_0;
    // 0x80802C14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802C18: lbu         $t7, 0x1E6($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1E6);
L_80802C1C:
    // 0x80802C1C: addu        $t9, $s1, $s0
    ctx->r25 = ADD32(ctx->r17, ctx->r16);
    // 0x80802C20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802C24: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80802C28: beql        $t8, $zero, L_80802C3C
    if (ctx->r24 == 0) {
        // 0x80802C2C: lw          $t0, 0x1E4($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X1E4);
            goto L_80802C3C;
    }
    goto skip_1;
    // 0x80802C2C: lw          $t0, 0x1E4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1E4);
    skip_1:
    // 0x80802C30: jal         0x800C431C
    // 0x80802C34: lbu         $a0, 0x144($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X144);
    func_800C431C(rdram, ctx);
        goto after_0;
    // 0x80802C34: lbu         $a0, 0x144($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X144);
    after_0:
    // 0x80802C38: lw          $t0, 0x1E4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1E4);
L_80802C3C:
    // 0x80802C3C: addu        $t2, $s1, $s0
    ctx->r10 = ADD32(ctx->r17, ctx->r16);
    // 0x80802C40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802C44: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x80802C48: beql        $t1, $zero, L_80802C5C
    if (ctx->r9 == 0) {
        // 0x80802C4C: lbu         $t3, 0x178($s1)
        ctx->r11 = MEM_BU(ctx->r17, 0X178);
            goto L_80802C5C;
    }
    goto skip_2;
    // 0x80802C4C: lbu         $t3, 0x178($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X178);
    skip_2:
    // 0x80802C50: jal         0x800C3528
    // 0x80802C54: lbu         $a0, 0x144($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X144);
    func_800C3528(rdram, ctx);
        goto after_1;
    // 0x80802C54: lbu         $a0, 0x144($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X144);
    after_1:
    // 0x80802C58: lbu         $t3, 0x178($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X178);
L_80802C5C:
    // 0x80802C5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80802C60: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80802C64: bnel        $at, $zero, L_80802C1C
    if (ctx->r1 != 0) {
        // 0x80802C68: lbu         $t7, 0x1E6($s1)
        ctx->r15 = MEM_BU(ctx->r17, 0X1E6);
            goto L_80802C1C;
    }
    goto skip_3;
    // 0x80802C68: lbu         $t7, 0x1E6($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1E6);
    skip_3:
    // 0x80802C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802C70:
    // 0x80802C70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80802C74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80802C78: jr          $ra
    // 0x80802C7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80802C7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _cheggfire_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871E0: syscall     535
    recomp_syscall_handler(rdram, ctx, 0x800871E0);
    return;
    // 0x800871E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void glzone_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x808000A8: jr          $ra
    // 0x808000AC: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    return;
    // 0x808000AC: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
;}
RECOMP_FUNC void ncbaspline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800794: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80800798: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8080079C: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x808007A0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x808007A4: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x808007A8: beq         $t6, $zero, L_808007B4
    if (ctx->r14 == 0) {
        // 0x808007AC: nop
    
            goto L_808007B4;
    }
    // 0x808007AC: nop

    // 0x808007B0: sw          $t7, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r15;
L_808007B4:
    // 0x808007B4: jr          $ra
    // 0x808007B8: nop

    return;
    // 0x808007B8: nop

;}
RECOMP_FUNC void _chfactoryroofbits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874A0: syscall     578
    recomp_syscall_handler(rdram, ctx, 0x800874A0);
    return;
    // 0x800874A4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80104350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80104354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80104358: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x8010435C: jal         0x800B3268
    // 0x80104360: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    freelist_new(rdram, ctx);
        goto after_0;
    // 0x80104360: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80104364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80104368: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010436C: sw          $v0, 0x6E80($at)
    MEM_W(0X6E80, ctx->r1) = ctx->r2;
    // 0x80104370: jr          $ra
    // 0x80104374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80104374: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800260_subaddieDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800268: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080026C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800270: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80800274: jal         0x8001210C
    // 0x80800278: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80800278: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8080027C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800280: beq         $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x80800284: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80800290;
    }
    // 0x80800284: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800288: b           L_80800294
    // 0x8080028C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800294;
    // 0x8080028C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800290:
    // 0x80800290: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_80800294:
    // 0x80800294: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800298: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8080029C: lwc1        $f10, 0xC($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XC);
    // 0x808002A0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002A4: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x808002A8: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x808002AC: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x808002B0: swc1        $f16, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f16.u32l;
    // 0x808002B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002BC: jr          $ra
    // 0x808002C0: nop

    return;
    // 0x808002C0: nop

;}
RECOMP_FUNC void chhumba_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802280: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1688, 0X2780) << 16);
    // 0x80802284: jr          $ra
    // 0x80802288: addiu       $v0, $v0, 0x2780
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1688, 0X2780));
    return;
    // 0x80802288: addiu       $v0, $v0, 0x2780
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1688, 0X2780));
    // 0x8080228C: nop

;}
RECOMP_FUNC void func_800F5AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5AD0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800F5AD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F5AD8: jr          $ra
    // 0x800F5ADC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800F5ADC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800E4278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4278: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E427C: addiu       $v0, $v0, -0x2AFC
    ctx->r2 = ADD32(ctx->r2, -0X2AFC);
    // 0x800E4280: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800E4284: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E4288: jr          $ra
    // 0x800E428C: sw          $zero, -0x2B00($at)
    MEM_W(-0X2B00, ctx->r1) = 0;
    return;
    // 0x800E428C: sw          $zero, -0x2B00($at)
    MEM_W(-0X2B00, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80801080_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801080: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801084: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801088: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080108C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801090: jal         0x80800ECC
    // 0x80801094: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    bstnt_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801094: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x80801098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080109C: jal         0x80085248
    // 0x808010A0: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    _basudie_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808010A0: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    after_1:
    // 0x808010A4: jal         0x80800554
    // 0x808010A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800554_bstnt(rdram, ctx);
        goto after_2;
    // 0x808010A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808010AC: addiu       $s1, $sp, 0x2C
    ctx->r17 = ADD32(ctx->r29, 0X2C);
    // 0x808010B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808010B4: jal         0x8009C128
    // 0x808010B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x808010B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808010BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010C0: jal         0x808004F8
    // 0x808010C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808004F8_bstnt(rdram, ctx);
        goto after_4;
    // 0x808010C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x808010C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010CC: jal         0x8080030C
    // 0x808010D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080030C_bstnt(rdram, ctx);
        goto after_5;
    // 0x808010D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x808010D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010D8: jal         0x808002AC
    // 0x808010DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808002AC_bstnt(rdram, ctx);
        goto after_6;
    // 0x808010DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x808010E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010E4: addiu       $a1, $zero, 0x693
    ctx->r5 = ADD32(0, 0X693);
    // 0x808010E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808010EC: jal         0x8009DB04
    // 0x808010F0: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    func_8009DB04(rdram, ctx);
        goto after_7;
    // 0x808010F0: addiu       $a3, $zero, 0x7FFF
    ctx->r7 = ADD32(0, 0X7FFF);
    after_7:
    // 0x808010F4: jal         0x8009D9D4
    // 0x808010F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D9D4(rdram, ctx);
        goto after_8;
    // 0x808010F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808010FC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(404, 0X2418) << 16);
    // 0x80801100: addiu       $t6, $t6, 0x2418
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(404, 0X2418));
    // 0x80801104: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801108: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080110C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801110: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801114: jal         0x800BBCB8
    // 0x80801118: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_9;
    // 0x80801118: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x8080111C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(404, 0X246C) << 16);
    // 0x80801120: addiu       $t7, $t7, 0x246C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(404, 0X246C));
    // 0x80801124: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080112C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801130: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801134: jal         0x800BBCB8
    // 0x80801138: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_10;
    // 0x80801138: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x8080113C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(404, 0X24B8) << 16);
    // 0x80801140: addiu       $t8, $t8, 0x24B8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(404, 0X24B8));
    // 0x80801144: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801148: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080114C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801150: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801154: jal         0x800BBCB8
    // 0x80801158: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_11;
    // 0x80801158: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x8080115C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(404, 0X2504) << 16);
    // 0x80801160: addiu       $t9, $t9, 0x2504
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(404, 0X2504));
    // 0x80801164: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801168: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080116C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801170: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801174: jal         0x800BBCB8
    // 0x80801178: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_800BBCB8(rdram, ctx);
        goto after_12;
    // 0x80801178: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_12:
    // 0x8080117C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801180: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801184: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801188: jr          $ra
    // 0x8080118C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8080118C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800F452C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F452C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F4530: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F4534: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F4538: jal         0x8009C0BC
    // 0x800F453C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009C0BC(rdram, ctx);
        goto after_0;
    // 0x800F453C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800F4540: jal         0x80095C94
    // 0x800F4544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80095C94(rdram, ctx);
        goto after_1;
    // 0x800F4544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800F4548: jal         0x800A10A0
    // 0x800F454C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A10A0(rdram, ctx);
        goto after_2;
    // 0x800F454C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800F4550: jal         0x800A4030
    // 0x800F4554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4030(rdram, ctx);
        goto after_3;
    // 0x800F4554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800F4558: jal         0x800A4B08
    // 0x800F455C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4B08(rdram, ctx);
        goto after_4;
    // 0x800F455C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800F4560: jal         0x800A380C
    // 0x800F4564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A380C(rdram, ctx);
        goto after_5;
    // 0x800F4564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800F4568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F456C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F4570: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F4574: jr          $ra
    // 0x800F4578: nop

    return;
    // 0x800F4578: nop

;}
RECOMP_FUNC void gcnewoption_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800A98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800A9C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800AA0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800AA4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800AA8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800AAC: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80800AB0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800AB4: jal         0x80088718
    // 0x80800AB8: lw          $a0, 0x23C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X23C);
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800AB8: lw          $a0, 0x23C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X23C);
    after_0:
    // 0x80800ABC: sw          $v0, 0x23C($s0)
    MEM_W(0X23C, ctx->r16) = ctx->r2;
    // 0x80800AC0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800AC4: lbu         $t2, 0x1C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1C);
    // 0x80800AC8: sh          $t6, 0x240($s0)
    MEM_H(0X240, ctx->r16) = ctx->r14;
    // 0x80800ACC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AD0: lbu         $t6, 0x1D($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1D);
    // 0x80800AD4: andi        $t4, $t2, 0xFFEF
    ctx->r12 = ctx->r10 & 0XFFEF;
    // 0x80800AD8: sw          $t7, 0x244($s0)
    MEM_W(0X244, ctx->r16) = ctx->r15;
    // 0x80800ADC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800AE0: andi        $t5, $t4, 0xF7
    ctx->r13 = ctx->r12 & 0XF7;
    // 0x80800AE4: sw          $t8, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->r24;
    // 0x80800AE8: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80800AEC: andi        $t8, $t6, 0xFFEF
    ctx->r24 = ctx->r14 & 0XFFEF;
    // 0x80800AF0: sb          $t4, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r12;
    // 0x80800AF4: andi        $t2, $t8, 0xBF
    ctx->r10 = ctx->r24 & 0XBF;
    // 0x80800AF8: sb          $t8, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r24;
    // 0x80800AFC: andi        $t4, $t2, 0x7F
    ctx->r12 = ctx->r10 & 0X7F;
    // 0x80800B00: sb          $t2, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r10;
    // 0x80800B04: andi        $t6, $t4, 0xDF
    ctx->r14 = ctx->r12 & 0XDF;
    // 0x80800B08: sb          $t4, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r12;
    // 0x80800B0C: andi        $t8, $t6, 0xF7
    ctx->r24 = ctx->r14 & 0XF7;
    // 0x80800B10: sb          $t6, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r14;
    // 0x80800B14: sw          $t9, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->r25;
    // 0x80800B18: sb          $t8, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r24;
    // 0x80800B1C: andi        $t9, $t8, 0xFB
    ctx->r25 = ctx->r24 & 0XFB;
    // 0x80800B20: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x80800B24: sb          $t5, 0x1C($s0)
    MEM_B(0X1C, ctx->r16) = ctx->r13;
    // 0x80800B28: sh          $zero, 0x238($s0)
    MEM_H(0X238, ctx->r16) = 0;
    // 0x80800B2C: sb          $t9, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r25;
    // 0x80800B30: jal         0x80088730
    // 0x80800B34: sh          $t2, 0x236($s0)
    MEM_H(0X236, ctx->r16) = ctx->r10;
    _gldialog_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800B34: sh          $t2, 0x236($s0)
    MEM_H(0X236, ctx->r16) = ctx->r10;
    after_1:
    // 0x80800B38: lbu         $t3, 0x1D($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1D);
    // 0x80800B3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B40: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800B44: andi        $t4, $t3, 0xFFFD
    ctx->r12 = ctx->r11 & 0XFFFD;
    // 0x80800B48: sh          $v0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r2;
    // 0x80800B4C: sb          $t4, 0x1D($s0)
    MEM_B(0X1D, ctx->r16) = ctx->r12;
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B54: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80800B58: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80800B5C: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80800B60: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80800B64: jal         0x80802CF4
    // 0x80800B68: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    gcnewoption_entrypoint_40(rdram, ctx);
        goto after_2;
    // 0x80800B68: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800B6C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80800B70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800B74: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80800B78: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x80800B7C: sb          $zero, 0x250($s0)
    MEM_B(0X250, ctx->r16) = 0;
    // 0x80800B80: sh          $a3, 0x1DC($s0)
    MEM_H(0X1DC, ctx->r16) = ctx->r7;
    // 0x80800B84: sh          $a3, 0x1DE($s0)
    MEM_H(0X1DE, ctx->r16) = ctx->r7;
    // 0x80800B88: sh          $a2, 0xEC($s0)
    MEM_H(0XEC, ctx->r16) = ctx->r6;
    // 0x80800B8C: sh          $a2, 0xEE($s0)
    MEM_H(0XEE, ctx->r16) = ctx->r6;
    // 0x80800B90: sh          $a0, 0x128($s0)
    MEM_H(0X128, ctx->r16) = ctx->r4;
    // 0x80800B94: sh          $a0, 0x12A($s0)
    MEM_H(0X12A, ctx->r16) = ctx->r4;
    // 0x80800B98: sh          $a0, 0x12C($s0)
    MEM_H(0X12C, ctx->r16) = ctx->r4;
    // 0x80800B9C: sh          $a0, 0x12E($s0)
    MEM_H(0X12E, ctx->r16) = ctx->r4;
    // 0x80800BA0: sh          $a0, 0x130($s0)
    MEM_H(0X130, ctx->r16) = ctx->r4;
    // 0x80800BA4: sh          $a0, 0x132($s0)
    MEM_H(0X132, ctx->r16) = ctx->r4;
    // 0x80800BA8: sh          $zero, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = 0;
    // 0x80800BAC: sb          $zero, 0x218($s0)
    MEM_B(0X218, ctx->r16) = 0;
    // 0x80800BB0: sh          $zero, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = 0;
    // 0x80800BB4: sb          $zero, 0x219($s0)
    MEM_B(0X219, ctx->r16) = 0;
    // 0x80800BB8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80800BBC: addiu       $v0, $s0, 0x4
    ctx->r2 = ADD32(ctx->r16, 0X4);
    // 0x80800BC0: addiu       $v1, $s0, 0xC
    ctx->r3 = ADD32(ctx->r16, 0XC);
    // 0x80800BC4: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // 0x80800BC8: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x80800BCC: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
L_80800BD0:
    // 0x80800BD0: sh          $zero, 0xB0($v0)
    MEM_H(0XB0, ctx->r2) = 0;
    // 0x80800BD4: sh          $a2, 0xEC($v0)
    MEM_H(0XEC, ctx->r2) = ctx->r6;
    // 0x80800BD8: sh          $a0, 0x128($v1)
    MEM_H(0X128, ctx->r3) = ctx->r4;
    // 0x80800BDC: sh          $a0, 0x12A($v1)
    MEM_H(0X12A, ctx->r3) = ctx->r4;
    // 0x80800BE0: sh          $a0, 0x12C($v1)
    MEM_H(0X12C, ctx->r3) = ctx->r4;
    // 0x80800BE4: sh          $a3, 0x1DC($v0)
    MEM_H(0X1DC, ctx->r2) = ctx->r7;
    // 0x80800BE8: sb          $zero, 0x218($a1)
    MEM_B(0X218, ctx->r5) = 0;
    // 0x80800BEC: sh          $a2, 0xEE($v0)
    MEM_H(0XEE, ctx->r2) = ctx->r6;
    // 0x80800BF0: sh          $zero, 0xB2($v0)
    MEM_H(0XB2, ctx->r2) = 0;
    // 0x80800BF4: sh          $a0, 0x132($v1)
    MEM_H(0X132, ctx->r3) = ctx->r4;
    // 0x80800BF8: sh          $a0, 0x130($v1)
    MEM_H(0X130, ctx->r3) = ctx->r4;
    // 0x80800BFC: sh          $a0, 0x12E($v1)
    MEM_H(0X12E, ctx->r3) = ctx->r4;
    // 0x80800C00: sh          $a3, 0x1DE($v0)
    MEM_H(0X1DE, ctx->r2) = ctx->r7;
    // 0x80800C04: sb          $zero, 0x219($a1)
    MEM_B(0X219, ctx->r5) = 0;
    // 0x80800C08: sh          $a2, 0xF0($v0)
    MEM_H(0XF0, ctx->r2) = ctx->r6;
    // 0x80800C0C: sh          $zero, 0xB4($v0)
    MEM_H(0XB4, ctx->r2) = 0;
    // 0x80800C10: sh          $a0, 0x138($v1)
    MEM_H(0X138, ctx->r3) = ctx->r4;
    // 0x80800C14: sh          $a0, 0x136($v1)
    MEM_H(0X136, ctx->r3) = ctx->r4;
    // 0x80800C18: sh          $a0, 0x134($v1)
    MEM_H(0X134, ctx->r3) = ctx->r4;
    // 0x80800C1C: sh          $a3, 0x1E0($v0)
    MEM_H(0X1E0, ctx->r2) = ctx->r7;
    // 0x80800C20: sb          $zero, 0x21A($a1)
    MEM_B(0X21A, ctx->r5) = 0;
    // 0x80800C24: sh          $a2, 0xF2($v0)
    MEM_H(0XF2, ctx->r2) = ctx->r6;
    // 0x80800C28: sh          $zero, 0xB6($v0)
    MEM_H(0XB6, ctx->r2) = 0;
    // 0x80800C2C: sh          $a0, 0x13E($v1)
    MEM_H(0X13E, ctx->r3) = ctx->r4;
    // 0x80800C30: sh          $a0, 0x13C($v1)
    MEM_H(0X13C, ctx->r3) = ctx->r4;
    // 0x80800C34: sh          $a0, 0x13A($v1)
    MEM_H(0X13A, ctx->r3) = ctx->r4;
    // 0x80800C38: sh          $a3, 0x1E2($v0)
    MEM_H(0X1E2, ctx->r2) = ctx->r7;
    // 0x80800C3C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80800C40: sb          $zero, 0x21B($a1)
    MEM_B(0X21B, ctx->r5) = 0;
    // 0x80800C44: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80800C48: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x80800C4C: bne         $t1, $t0, L_80800BD0
    if (ctx->r9 != ctx->r8) {
        // 0x80800C50: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80800BD0;
    }
    // 0x80800C50: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800C54: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800C5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800C60: jr          $ra
    // 0x80800C64: nop

    return;
    // 0x80800C64: nop

;}
RECOMP_FUNC void _bskazjump_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083458: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083458);
    return;
    // 0x8008345C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void cothemedll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080014C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800150: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800154: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800158: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8080015C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80800160: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800164: jal         0x800FE890
    // 0x80800168: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_800FE890(rdram, ctx);
        goto after_0;
    // 0x80800168: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080016C: bnel        $v0, $zero, L_808001C8
    if (ctx->r2 != 0) {
        // 0x80800170: addiu       $a0, $zero, 0x674
        ctx->r4 = ADD32(0, 0X674);
            goto L_808001C8;
    }
    goto skip_0;
    // 0x80800170: addiu       $a0, $zero, 0x674
    ctx->r4 = ADD32(0, 0X674);
    skip_0:
    // 0x80800174: jal         0x80800000
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_cothemedll(rdram, ctx);
        goto after_1;
    // 0x80800178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080017C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800180: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80800184: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80800188: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2508, 0X732) << 16);
    // 0x8080018C: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x80800190: lh          $s0, 0x732($s0)
    ctx->r16 = MEM_H(ctx->r16, (int16_t)RELOC_LO16(2508, 0X732));
    // 0x80800194: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800198: sra         $t7, $s0, 2
    ctx->r15 = S32(SIGNED(ctx->r16) >> 2);
    // 0x8080019C: beq         $t7, $at, L_808001C4
    if (ctx->r15 == ctx->r1) {
        // 0x808001A0: or          $s0, $t7, $zero
        ctx->r16 = ctx->r15 | 0;
            goto L_808001C4;
    }
    // 0x808001A0: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x808001A4: jal         0x800FCCD4
    // 0x808001A8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800FCCD4(rdram, ctx);
        goto after_2;
    // 0x808001A8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x808001AC: beq         $v0, $zero, L_808001BC
    if (ctx->r2 == 0) {
        // 0x808001B0: nop
    
            goto L_808001BC;
    }
    // 0x808001B0: nop

    // 0x808001B4: jal         0x800FC74C
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FC74C(rdram, ctx);
        goto after_3;
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_808001BC:
    // 0x808001BC: jal         0x80016DF8
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80016DF8(rdram, ctx);
        goto after_4;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_808001C4:
    // 0x808001C4: addiu       $a0, $zero, 0x674
    ctx->r4 = ADD32(0, 0X674);
L_808001C8:
    // 0x808001C8: jal         0x800DA9E4
    // 0x808001CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_5;
    // 0x808001CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808001D0: bnel        $v0, $zero, L_808001E4
    if (ctx->r2 != 0) {
        // 0x808001D4: addiu       $a0, $zero, 0x675
        ctx->r4 = ADD32(0, 0X675);
            goto L_808001E4;
    }
    goto skip_1;
    // 0x808001D4: addiu       $a0, $zero, 0x675
    ctx->r4 = ADD32(0, 0X675);
    skip_1:
    // 0x808001D8: jal         0x800FDC28
    // 0x808001DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800FDC28(rdram, ctx);
        goto after_6;
    // 0x808001DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x808001E0: addiu       $a0, $zero, 0x675
    ctx->r4 = ADD32(0, 0X675);
L_808001E4:
    // 0x808001E4: jal         0x800DA9E4
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA9E4(rdram, ctx);
        goto after_7;
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808001EC: bne         $v0, $zero, L_80800224
    if (ctx->r2 != 0) {
        // 0x808001F0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800224;
    }
    // 0x808001F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808001F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001F8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808001FC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800200: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80800204: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
L_80800208:
    // 0x80800208: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: jal         0x800FEDC4
    // 0x80800214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800FEDC4(rdram, ctx);
        goto after_8;
    // 0x80800214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800218: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080021C: bnel        $s0, $s1, L_80800208
    if (ctx->r16 != ctx->r17) {
        // 0x80800220: mfc1        $a2, $f20
        ctx->r6 = (int32_t)ctx->f20.u32l;
            goto L_80800208;
    }
    goto skip_2;
    // 0x80800220: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    skip_2:
L_80800224:
    // 0x80800224: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800228: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8080022C: sb          $t8, 0x41($t9)
    MEM_B(0X41, ctx->r25) = ctx->r24;
    // 0x80800230: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800234: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800238: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8080023C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800240: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800244: jr          $ra
    // 0x80800248: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800248: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _ncpod_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895B8: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800895B8);
    return;
    // 0x800895BC: addi        $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void func_80800450_bsledge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800450: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800458: jal         0x8009BB5C
    // 0x8080045C: nop

    func_8009BB5C(rdram, ctx);
        goto after_0;
    // 0x8080045C: nop

    after_0:
    // 0x80800460: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080046C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800470: nop

    // 0x80800474: bc1f        L_80800480
    if (!c1cs) {
        // 0x80800478: nop
    
            goto L_80800480;
    }
    // 0x80800478: nop

    // 0x8080047C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800480:
    // 0x80800480: jr          $ra
    // 0x80800484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8001D32C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D32C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8001D330: addiu       $v0, $v0, -0x89C
    ctx->r2 = ADD32(ctx->r2, -0X89C);
    // 0x8001D334: jr          $ra
    // 0x8001D338: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    return;
    // 0x8001D338: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8001D33C: nop

;}
RECOMP_FUNC void _gctransitionDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800881B0: syscall     674
    recomp_syscall_handler(rdram, ctx, 0x800881B0);
    return;
    // 0x800881B4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _glsplineDll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800884D8: syscall     689
    recomp_syscall_handler(rdram, ctx, 0x800884D8);
    return;
    // 0x800884DC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
