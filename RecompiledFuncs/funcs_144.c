#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800BCE84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCE84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BCE88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BCE8C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800BCE90: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x800BCE94: jal         0x800BCCC0
    // 0x800BCE98: lbu         $a1, 0x8($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X8);
    static_16_800BCCC0(rdram, ctx);
        goto after_0;
    // 0x800BCE98: lbu         $a1, 0x8($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X8);
    after_0:
    // 0x800BCE9C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCEA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BCEA4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BCEA8: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800BCEAC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800BCEB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BCEB4: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800BCEB8: jr          $ra
    // 0x800BCEBC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    return;
    // 0x800BCEBC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
;}
RECOMP_FUNC void _chjigsawbitcont_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B38: syscall     418
    recomp_syscall_handler(rdram, ctx, 0x80086B38);
    return;
    // 0x80086B3C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080048C_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080048C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800490: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800494: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800498: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8080049C: jal         0x800EA090
    // 0x808004A0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    func_800EA090(rdram, ctx);
        goto after_0;
    // 0x808004A0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_0:
    // 0x808004A4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808004A8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x808004AC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x808004B0: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x808004B4: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x808004B8: bgez        $t9, L_808004E0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808004BC: nop
    
            goto L_808004E0;
    }
    // 0x808004BC: nop

    // 0x808004C0: bne         $v0, $at, L_808004CC
    if (ctx->r2 != ctx->r1) {
        // 0x808004C4: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_808004CC;
    }
    // 0x808004C4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x808004C8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
L_808004CC:
    // 0x808004CC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808004D0: bne         $v0, $at, L_808004E0
    if (ctx->r2 != ctx->r1) {
        // 0x808004D4: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_808004E0;
    }
    // 0x808004D4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808004D8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x808004DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808004E0:
    // 0x808004E0: beql        $v1, $zero, L_80800538
    if (ctx->r3 == 0) {
        // 0x808004E4: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_80800538;
    }
    goto skip_0;
    // 0x808004E4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808004E8: jal         0x800BEA88
    // 0x808004EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEA88(rdram, ctx);
        goto after_1;
    // 0x808004EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x808004F0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808004F4: jal         0x800BEA88
    // 0x808004F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_2;
    // 0x808004F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x808004FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800500: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800504: addiu       $a1, $zero, 0x596
    ctx->r5 = ADD32(0, 0X596);
    // 0x80800508: beq         $a0, $zero, L_80800518
    if (ctx->r4 == 0) {
        // 0x8080050C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80800518;
    }
    // 0x8080050C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800510: jal         0x80088F28
    // 0x80800514: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x80800514: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
L_80800518:
    // 0x80800518: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8080051C: addiu       $a1, $zero, 0x65E
    ctx->r5 = ADD32(0, 0X65E);
    // 0x80800520: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800524: beq         $t2, $zero, L_80800534
    if (ctx->r10 == 0) {
        // 0x80800528: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_80800534;
    }
    // 0x80800528: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x8080052C: jal         0x80088F28
    // 0x80800530: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800530: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
L_80800534:
    // 0x80800534: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_80800538:
    // 0x80800538: beql        $t3, $zero, L_8080054C
    if (ctx->r11 == 0) {
        // 0x8080053C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080054C;
    }
    goto skip_1;
    // 0x8080053C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800540: jal         0x800FFAB0
    // 0x80800544: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x80800544: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80800548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080054C:
    // 0x8080054C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800550: jr          $ra
    // 0x80800554: nop

    return;
    // 0x80800554: nop

;}
RECOMP_FUNC void bskazjump_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005AC: jal         0x800832E0
    // 0x808005B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808005B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808005B4: jal         0x8009E710
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808005BC: xori        $t6, $v0, 0xC6
    ctx->r14 = ctx->r2 ^ 0XC6;
    // 0x808005C0: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x808005C4: sw          $t6, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r14;
    // 0x808005C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005CC: jal         0x80095738
    // 0x808005D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x808005D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x808005D4: beql        $v0, $zero, L_80800610
    if (ctx->r2 == 0) {
        // 0x808005D8: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_80800610;
    }
    goto skip_0;
    // 0x808005D8: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    skip_0:
    // 0x808005DC: jal         0x8009BB50
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_3;
    // 0x808005E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808005E4: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x808005E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808005EC: nop

    // 0x808005F0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808005F4: nop

    // 0x808005F8: bc1fl       L_80800610
    if (!c1cs) {
        // 0x808005FC: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_80800610;
    }
    goto skip_1;
    // 0x808005FC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    skip_1:
    // 0x80800600: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800604: jal         0x8009BA58
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_4;
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080060C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
L_80800610:
    // 0x80800610: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080061C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800620: jal         0x8009FFD8
    // 0x80800624: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_5;
    // 0x80800624: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_5:
    // 0x80800628: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x8080062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800630: jal         0x8008DF8C
    // 0x80800634: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_8008DF8C(rdram, ctx);
        goto after_6;
    // 0x80800634: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_6:
    // 0x80800638: beq         $v0, $zero, L_80800654
    if (ctx->r2 == 0) {
        // 0x8080063C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800654;
    }
    // 0x8080063C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800644: jal         0x808004C4
    // 0x80800648: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_808004C4_bskazjump(rdram, ctx);
        goto after_7;
    // 0x80800648: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8080064C: b           L_80800660
    // 0x80800650: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800660;
    // 0x80800650: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800654:
    // 0x80800654: jal         0x808004C4
    // 0x80800658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808004C4_bskazjump(rdram, ctx);
        goto after_8;
    // 0x80800658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8080065C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800660:
    // 0x80800660: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800664: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800668: jr          $ra
    // 0x8080066C: nop

    return;
    // 0x8080066C: nop

;}
RECOMP_FUNC void _chpoolkids_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860F8: syscall     278
    recomp_syscall_handler(rdram, ctx, 0x800860F8);
    return;
    // 0x800860FC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chexploder_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080137C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80801380: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80801384: lh          $t7, 0x56($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X56);
    // 0x80801388: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8080138C: lh          $t8, 0x58($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X58);
    // 0x80801390: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80801394: lh          $t9, 0x5A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5A);
    // 0x80801398: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8080139C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808013A0: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808013A4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x808013A8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x808013AC: lh          $t6, 0x54($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X54);
    // 0x808013B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808013B4: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x808013B8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x808013BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808013C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808013C4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808013C8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x808013CC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808013D0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808013D4: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x808013D8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808013DC: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x808013E0: addiu       $a0, $zero, 0x1FF
    ctx->r4 = ADD32(0, 0X1FF);
    // 0x808013E4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x808013E8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808013EC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x808013F0: jal         0x80108474
    // 0x808013F4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_80108474(rdram, ctx);
        goto after_0;
    // 0x808013F4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x808013F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808013FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801400: jal         0x80100094
    // 0x80801404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801404: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801408: beq         $s1, $zero, L_80801420
    if (ctx->r17 == 0) {
        // 0x8080140C: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_80801420;
    }
    // 0x8080140C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80801410: jal         0x80106790
    // 0x80801414: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80801414: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80801418: b           L_80801424
    // 0x8080141C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_80801424;
    // 0x8080141C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80801420:
    // 0x80801420: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80801424:
    // 0x80801424: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801428: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080142C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801430: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    // 0x80801434: jal         0x800EE7F8
    // 0x80801438: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80801438: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x8080143C: beql        $s1, $zero, L_80801470
    if (ctx->r17 == 0) {
        // 0x80801440: lw          $v0, 0x28($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X28);
            goto L_80801470;
    }
    goto skip_0;
    // 0x80801440: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    skip_0:
    // 0x80801444: jal         0x80101074
    // 0x80801448: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80101074(rdram, ctx);
        goto after_4;
    // 0x80801448: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x8080144C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80801450: addiu       $a1, $zero, 0x8D
    ctx->r5 = ADD32(0, 0X8D);
    // 0x80801454: jal         0x8010108C
    // 0x80801458: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_8010108C(rdram, ctx);
        goto after_5;
    // 0x80801458: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x8080145C: blezl       $v0, L_80801470
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801460: lw          $v0, 0x28($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X28);
            goto L_80801470;
    }
    goto skip_1;
    // 0x80801460: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80801464: jal         0x80101038
    // 0x80801468: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80101038(rdram, ctx);
        goto after_6;
    // 0x80801468: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x8080146C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_80801470:
    // 0x80801470: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80801474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801478: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x8080147C: sh          $t1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r9;
    // 0x80801480: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80801484: beq         $s1, $zero, L_808014A4
    if (ctx->r17 == 0) {
        // 0x80801488: sh          $t2, 0x54($v0)
        MEM_H(0X54, ctx->r2) = ctx->r10;
            goto L_808014A4;
    }
    // 0x80801488: sh          $t2, 0x54($v0)
    MEM_H(0X54, ctx->r2) = ctx->r10;
    // 0x8080148C: jal         0x80108944
    // 0x80801490: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80108944(rdram, ctx);
        goto after_7;
    // 0x80801490: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x80801494: lbu         $t3, 0x74($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X74);
    // 0x80801498: andi        $t4, $t3, 0xFFFD
    ctx->r12 = ctx->r11 & 0XFFFD;
    // 0x8080149C: sb          $t4, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r12;
    // 0x808014A0: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_808014A4:
    // 0x808014A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014A8: lhu         $a1, 0x14($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X14);
    // 0x808014AC: jal         0x80103140
    // 0x808014B0: lhu         $a2, 0x16($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X16);
    func_80103140(rdram, ctx);
        goto after_8;
    // 0x808014B0: lhu         $a2, 0x16($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X16);
    after_8:
    // 0x808014B4: jal         0x801039E4
    // 0x808014B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_9;
    // 0x808014B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x808014BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808014C4: jal         0x80801188
    // 0x808014C8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80801188_chexploder(rdram, ctx);
        goto after_10;
    // 0x808014C8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_10:
    // 0x808014CC: jal         0x80800A18
    // 0x808014D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A18_chexploder(rdram, ctx);
        goto after_11;
    // 0x808014D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808014D4: beq         $s1, $zero, L_80801510
    if (ctx->r17 == 0) {
        // 0x808014D8: lw          $t5, 0x64($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X64);
            goto L_80801510;
    }
    // 0x808014D8: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x808014DC: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x808014E0: beql        $t6, $zero, L_80801514
    if (ctx->r14 == 0) {
        // 0x808014E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801514;
    }
    goto skip_2;
    // 0x808014E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808014E8: jal         0x80104248
    // 0x808014EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80104248(rdram, ctx);
        goto after_12;
    // 0x808014EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x808014F0: beq         $v0, $zero, L_80801510
    if (ctx->r2 == 0) {
        // 0x808014F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801510;
    }
    // 0x808014F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808014FC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80801500: jal         0x80800AC8
    // 0x80801504: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    func_80800AC8_chexploder(rdram, ctx);
        goto after_13;
    // 0x80801504: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    after_13:
    // 0x80801508: b           L_80801524
    // 0x8080150C: nop

        goto L_80801524;
    // 0x8080150C: nop

L_80801510:
    // 0x80801510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801514:
    // 0x80801514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801518: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080151C: jal         0x80800D7C
    // 0x80801520: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    func_80800D7C_chexploder(rdram, ctx);
        goto after_14;
    // 0x80801520: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    after_14:
L_80801524:
    // 0x80801524: beql        $s1, $zero, L_8080154C
    if (ctx->r17 == 0) {
        // 0x80801528: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080154C;
    }
    goto skip_3;
    // 0x80801528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x8080152C: jal         0x80101074
    // 0x80801530: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80101074(rdram, ctx);
        goto after_15;
    // 0x80801530: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_15:
    // 0x80801534: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80801538: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080153C: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    // 0x80801540: jal         0x8010108C
    // 0x80801544: lhu         $a2, 0x14($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X14);
    func_8010108C(rdram, ctx);
        goto after_16;
    // 0x80801544: lhu         $a2, 0x14($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X14);
    after_16:
    // 0x80801548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080154C:
    // 0x8080154C: jal         0x80800F74
    // 0x80801550: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800F74_chexploder(rdram, ctx);
        goto after_17;
    // 0x80801550: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_17:
    // 0x80801554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801558: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080155C: jal         0x808010E0
    // 0x80801560: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    func_808010E0_chexploder(rdram, ctx);
        goto after_18;
    // 0x80801560: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    after_18:
    // 0x80801564: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801568: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080156C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80801570: jr          $ra
    // 0x80801574: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80801574: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _ncba1p_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089410: syscall     777
    recomp_syscall_handler(rdram, ctx, 0x80089410);
    return;
    // 0x80089414: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void gsmaker_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080038C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800390: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800394: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800398: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080039C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808003A0: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x808003A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003AC: bne         $v0, $at, L_808003D0
    if (ctx->r2 != ctx->r1) {
        // 0x808003B0: or          $s1, $a2, $zero
        ctx->r17 = ctx->r6 | 0;
            goto L_808003D0;
    }
    // 0x808003B0: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x808003B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808003B8: jal         0x8001BBA0
    // 0x808003BC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    rare_memcpy(rdram, ctx);
        goto after_0;
    // 0x808003BC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_0:
    // 0x808003C0: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x808003C4: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x808003C8: b           L_80800494
    // 0x808003CC: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_80800494;
    // 0x808003CC: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_808003D0:
    // 0x808003D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808003D4: bne         $v0, $at, L_808003F8
    if (ctx->r2 != ctx->r1) {
        // 0x808003D8: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_808003F8;
    }
    // 0x808003D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808003DC: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x808003E0: jal         0x8001BBA0
    // 0x808003E4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x808003E4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x808003E8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x808003EC: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x808003F0: b           L_80800494
    // 0x808003F4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
        goto L_80800494;
    // 0x808003F4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_808003F8:
    // 0x808003F8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808003FC: bnel        $v0, $at, L_80800498
    if (ctx->r2 != ctx->r1) {
        // 0x80800400: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800498;
    }
    goto skip_0;
    // 0x80800400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800404: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x80800408: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x8080040C: addu        $v0, $a3, $s1
    ctx->r2 = ADD32(ctx->r7, ctx->r17);
    // 0x80800410: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80800414: beql        $at, $zero, L_8080047C
    if (ctx->r1 == 0) {
        // 0x80800418: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8080047C;
    }
    goto skip_1;
    // 0x80800418: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_1:
    // 0x8080041C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80800420: subu        $a1, $v1, $a0
    ctx->r5 = SUB32(ctx->r3, ctx->r4);
    // 0x80800424: sll         $t0, $a1, 1
    ctx->r8 = S32(ctx->r5 << 1);
    // 0x80800428: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8080042C: sltu        $at, $t1, $v0
    ctx->r1 = ctx->r9 < ctx->r2 ? 1 : 0;
    // 0x80800430: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x80800434: beq         $at, $zero, L_80800450
    if (ctx->r1 == 0) {
        // 0x80800438: subu        $a2, $a3, $a0
        ctx->r6 = SUB32(ctx->r7, ctx->r4);
            goto L_80800450;
    }
    // 0x80800438: subu        $a2, $a3, $a0
    ctx->r6 = SUB32(ctx->r7, ctx->r4);
L_8080043C:
    // 0x8080043C: sll         $t2, $a1, 1
    ctx->r10 = S32(ctx->r5 << 1);
    // 0x80800440: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x80800444: sltu        $at, $t3, $v0
    ctx->r1 = ctx->r11 < ctx->r2 ? 1 : 0;
    // 0x80800448: bne         $at, $zero, L_8080043C
    if (ctx->r1 != 0) {
        // 0x8080044C: or          $a1, $t2, $zero
        ctx->r5 = ctx->r10 | 0;
            goto L_8080043C;
    }
    // 0x8080044C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_80800450:
    // 0x80800450: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80800454: jal         0x8001B208
    // 0x80800458: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    heap_realloc(rdram, ctx);
        goto after_2;
    // 0x80800458: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x8080045C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800460: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800464: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80800468: addu        $t5, $v0, $a1
    ctx->r13 = ADD32(ctx->r2, ctx->r5);
    // 0x8080046C: addu        $a3, $v0, $a2
    ctx->r7 = ADD32(ctx->r2, ctx->r6);
    // 0x80800470: sw          $a3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r7;
    // 0x80800474: sw          $t5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r13;
    // 0x80800478: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8080047C:
    // 0x8080047C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800480: jal         0x8001BBA0
    // 0x80800484: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    rare_memcpy(rdram, ctx);
        goto after_3;
    // 0x80800484: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_3:
    // 0x80800488: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8080048C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80800490: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_80800494:
    // 0x80800494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800498:
    // 0x80800498: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080049C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808004A0: jr          $ra
    // 0x808004A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808004A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _bsbansnooze_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082738: syscall     9
    recomp_syscall_handler(rdram, ctx, 0x80082738);
    return;
    // 0x8008273C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _ncbafixpos_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089338: syscall     774
    recomp_syscall_handler(rdram, ctx, 0x80089338);
    return;
    // 0x8008933C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bsbtrot_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808022D8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808022DC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2ED0) << 16);
    // 0x808022E0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808022E4: jr          $ra
    // 0x808022E8: lw          $v0, 0x2ED0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2ED0));
    return;
    // 0x808022E8: lw          $v0, 0x2ED0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2ED0));
;}
RECOMP_FUNC void func_80019924(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001992C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019930: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80019934: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019938: jal         0x80018FE8
    // 0x8001993C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    mlMtxRotYaw(rdram, ctx);
        goto after_0;
    // 0x8001993C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_0:
    // 0x80019940: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80019944: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80019948: jal         0x80018F50
    // 0x8001994C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    mlMtxRotPitch(rdram, ctx);
        goto after_1;
    // 0x8001994C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x80019950: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80019954: lwc1        $f12, 0x8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80019958: jal         0x8001907C
    // 0x8001995C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    mlMtxRotRoll(rdram, ctx);
        goto after_2;
    // 0x8001995C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_2:
    // 0x80019960: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80019964: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80019968: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001996C: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80019970: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80019974: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80019978: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8001997C: jal         0x80019C84
    // 0x80019980: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    mlMtxTranslate(rdram, ctx);
        goto after_3;
    // 0x80019980: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    after_3:
    // 0x80019984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001998C: jr          $ra
    // 0x80019990: nop

    return;
    // 0x80019990: nop

;}
RECOMP_FUNC void func_800A9514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9514: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800A9518: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800A951C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A9520: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800A9524: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A9528: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A952C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800A9530: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9534: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A9538: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A953C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800A9540: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800A9544: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A9548: lwc1        $f20, 0x5600($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5600);
    // 0x800A954C: addiu       $s4, $s4, 0x76F0
    ctx->r20 = ADD32(ctx->r20, 0X76F0);
    // 0x800A9550: addiu       $s0, $s0, 0x76D0
    ctx->r16 = ADD32(ctx->r16, 0X76D0);
    // 0x800A9554: addiu       $s1, $sp, 0x4C
    ctx->r17 = ADD32(ctx->r29, 0X4C);
    // 0x800A9558: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
L_800A955C:
    // 0x800A955C: beql        $a0, $zero, L_800A9598
    if (ctx->r4 == 0) {
        // 0x800A9560: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A9598;
    }
    goto skip_0;
    // 0x800A9560: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800A9564: jal         0x800CA7E4
    // 0x800A9568: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800CA7E4(rdram, ctx);
        goto after_0;
    // 0x800A9568: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800A956C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800A9570: jal         0x800EEB40
    // 0x800A9574: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x800A9574: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800A9578: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800A957C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800A9580: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A9584: bc1fl       L_800A9598
    if (!c1cs) {
        // 0x800A9588: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A9598;
    }
    goto skip_1;
    // 0x800A9588: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x800A958C: jal         0x800EE7F8
    // 0x800A9590: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800A9590: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x800A9594: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800A9598:
    // 0x800A9598: bnel        $s0, $s4, L_800A955C
    if (ctx->r16 != ctx->r20) {
        // 0x800A959C: lw          $a0, 0x38($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X38);
            goto L_800A955C;
    }
    goto skip_2;
    // 0x800A959C: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    skip_2:
    // 0x800A95A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A95A4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800A95A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A95AC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A95B0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A95B4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800A95B8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800A95BC: jr          $ra
    // 0x800A95C0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800A95C0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800CD4_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CD8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800CE4: bne         $a1, $at, L_80800D1C
    if (ctx->r5 != ctx->r1) {
        // 0x80800CE8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800D1C;
    }
    // 0x80800CE8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800CEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800CF0: jal         0x800897C0
    // 0x80800CF4: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800CF4: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_0:
    // 0x80800CF8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800CFC: jal         0x80100094
    // 0x80800D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800D00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800D04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D08: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800D0C: jal         0x800897E8
    // 0x80800D10: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800D10: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_2:
    // 0x80800D14: b           L_80800D24
    // 0x80800D18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800D24;
    // 0x80800D18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D1C:
    // 0x80800D1C: b           L_80800D24
    // 0x80800D20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D24;
    // 0x80800D20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D24:
    // 0x80800D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D2C: jr          $ra
    // 0x80800D30: nop

    return;
    // 0x80800D30: nop

;}
RECOMP_FUNC void func_808001DC_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001EC: jal         0x8009E6C4
    // 0x808001F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009E6C4(rdram, ctx);
        goto after_0;
    // 0x808001F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808001F4: bne         $v0, $zero, L_8080025C
    if (ctx->r2 != 0) {
        // 0x808001F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080025C;
    }
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: jal         0x8009BCB4
    // 0x80800200: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    baphysics_set_gravity(rdram, ctx);
        goto after_1;
    // 0x80800200: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    after_1:
    // 0x80800204: lui         $a1, 0x4305
    ctx->r5 = S32(0X4305 << 16);
    // 0x80800208: ori         $a1, $a1, 0x547B
    ctx->r5 = ctx->r5 | 0X547B;
    // 0x8080020C: jal         0x8009BCC4
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_2;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800214: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x80800218: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800220: jal         0x8009F1C8
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bastick_setZoneMax(rdram, ctx);
        goto after_3;
    // 0x80800224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800230: jal         0x8009F1C8
    // 0x80800234: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    bastick_setZoneMax(rdram, ctx);
        goto after_4;
    // 0x80800234: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x800961AC
    // 0x80800240: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_5;
    // 0x80800240: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800244: jal         0x8008E0E8
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_6;
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080024C: beq         $v0, $zero, L_8080025C
    if (ctx->r2 == 0) {
        // 0x80800250: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080025C;
    }
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: jal         0x80084788
    // 0x80800258: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_7;
    // 0x80800258: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_7:
L_8080025C:
    // 0x8080025C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800260: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800268: jr          $ra
    // 0x8080026C: nop

    return;
    // 0x8080026C: nop

;}
RECOMP_FUNC void chtntminecelldoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(912, 0X140) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(912, 0X140));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x140
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(912, 0X140));
;}
RECOMP_FUNC void anctrl_getIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B26C: jal         0x8008C0C0
    // 0x8008B270: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_8008C0C0(rdram, ctx);
        goto after_0;
    // 0x8008B270: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8008B274: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B278: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B27C: jr          $ra
    // 0x8008B280: nop

    return;
    // 0x8008B280: nop

;}
RECOMP_FUNC void gspropctrl_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80800128: lui         $at, 0x7F
    ctx->r1 = S32(0X7F << 16);
    // 0x8080012C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80800130: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x80800134: jr          $ra
    // 0x80800138: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x80800138: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8080013C: nop

;}
RECOMP_FUNC void chminelight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080062C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1744, 0X6AC) << 16);
    // 0x80800630: jr          $ra
    // 0x80800634: addiu       $v0, $v0, 0x6AC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1744, 0X6AC));
    return;
    // 0x80800634: addiu       $v0, $v0, 0x6AC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1744, 0X6AC));
    // 0x80800638: nop

    // 0x8080063C: nop

;}
RECOMP_FUNC void chdodgemdoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800344: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1756, 0X374) << 16);
    // 0x80800348: jr          $ra
    // 0x8080034C: addiu       $v0, $v0, 0x374
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1756, 0X374));
    return;
    // 0x8080034C: addiu       $v0, $v0, 0x374
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1756, 0X374));
;}
RECOMP_FUNC void badata_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808008BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808008C0: jal         0x80800000
    // 0x808008C4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x808008C4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x808008C8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x808008CC: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x808008D0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(473, 0X2648) << 16);
    // 0x808008D4: addiu       $t7, $t7, 0x2648
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(473, 0X2648));
    // 0x808008D8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808008DC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x808008E0: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x808008E4: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x808008E8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x808008EC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x808008F0: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x808008F4: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x808008F8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x808008FC: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80800900: swc1        $f6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f6.u32l;
    // 0x80800904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080090C: jr          $ra
    // 0x80800910: nop

    return;
    // 0x80800910: nop

;}
RECOMP_FUNC void chappearfx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1188, 0X990) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x990
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1188, 0X990));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x990
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1188, 0X990));
;}
RECOMP_FUNC void func_8009C188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C188: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C18C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8009C190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C194: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8009C198: lw          $a1, 0xE4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XE4);
    // 0x8009C19C: jal         0x800EE7F8
    // 0x8009C1A0: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x8009C1A0: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_0:
    // 0x8009C1A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C1A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C1AC: jr          $ra
    // 0x8009C1B0: nop

    return;
    // 0x8009C1B0: nop

;}
RECOMP_FUNC void fxtwinkle_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800084: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080008C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800090: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800094: jal         0x800B53A4
    // 0x80800098: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80800098: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8080009C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2838, 0X10C) << 16);
    // 0x808000A0: addiu       $t6, $t6, 0x10C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2838, 0X10C));
    // 0x808000A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808000A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000B0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808000B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000B8: jal         0x800BABB8
    // 0x808000BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x808000BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x808000C0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808000C4: jal         0x800BA3FC
    // 0x808000C8: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    func_800BA3FC(rdram, ctx);
        goto after_2;
    // 0x808000C8: lh          $a1, 0x2E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2E);
    after_2:
    // 0x808000CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808000D0: jal         0x800BA22C
    // 0x808000D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x808000D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x808000D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000E0: jr          $ra
    // 0x808000E4: nop

    return;
    // 0x808000E4: nop

    // 0x808000E8: nop

    // 0x808000EC: nop

;}
RECOMP_FUNC void func_800D1254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1254: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D1258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D125C: jal         0x800D0634
    // 0x800D1260: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800D0634(rdram, ctx);
        goto after_0;
    // 0x800D1260: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800D1264: beq         $v0, $zero, L_800D128C
    if (ctx->r2 == 0) {
        // 0x800D1268: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D128C;
    }
    // 0x800D1268: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D126C: jal         0x80106790
    // 0x800D1270: nop

    func_80106790(rdram, ctx);
        goto after_1;
    // 0x800D1270: nop

    after_1:
    // 0x800D1274: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800D1278: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x800D127C: jal         0x800EE7F8
    // 0x800D1280: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800D1280: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800D1284: jal         0x80103014
    // 0x800D1288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80103014(rdram, ctx);
        goto after_3;
    // 0x800D1288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
L_800D128C:
    // 0x800D128C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1290: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D1294: jr          $ra
    // 0x800D1298: nop

    return;
    // 0x800D1298: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801938: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080193C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801940: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801944: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801948: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8080194C: jal         0x8009D3A8
    // 0x80801950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x80801950: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801954: lbu         $t6, 0x15C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X15C);
    // 0x80801958: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8080195C: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80801960: beq         $at, $zero, L_80801C5C
    if (ctx->r1 == 0) {
        // 0x80801964: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80801C5C;
    }
    // 0x80801964: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801968: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X20B4) << 16);
    // 0x8080196C: addu        $at, $at, $t7
    gpr jr_addend_80801974 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80801970: lw          $t7, 0x20B4($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(392, 0X20B4));
    // 0x80801974: jr          $t7
    // 0x80801978: nop

    switch (jr_addend_80801974 >> 2) {
        case 0: goto L_8080197C; break;
        case 1: goto L_808019E8; break;
        case 2: goto L_80801AF0; break;
        case 3: goto L_80801B28; break;
        case 4: goto L_80801B48; break;
        default: switch_error(__func__, 0x80801974, 0x808020B4);
    }
    // 0x80801978: nop

L_8080197C:
    // 0x8080197C: jal         0x80800000
    // 0x80801980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bstaxi(rdram, ctx);
        goto after_1;
    // 0x80801980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801988: jal         0x80095738
    // 0x8080198C: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x8080198C: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_2:
    // 0x80801990: beq         $v0, $zero, L_808019A0
    if (ctx->r2 == 0) {
        // 0x80801994: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808019A0;
    }
    // 0x80801994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801998: jal         0x80095774
    // 0x8080199C: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    baflag_clear(rdram, ctx);
        goto after_3;
    // 0x8080199C: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_3:
L_808019A0:
    // 0x808019A0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x808019A4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808019A8: jal         0x8008CB10
    // 0x808019AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x808019AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808019B0: beq         $v0, $zero, L_808019C0
    if (ctx->r2 == 0) {
        // 0x808019B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808019C0;
    }
    // 0x808019B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019B8: jal         0x80095760
    // 0x808019BC: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    baflag_set(rdram, ctx);
        goto after_5;
    // 0x808019BC: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_5:
L_808019C0:
    // 0x808019C0: lui         $a1, 0x3EB3
    ctx->r5 = S32(0X3EB3 << 16);
    // 0x808019C4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808019C8: jal         0x8008CB10
    // 0x808019CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x808019CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808019D0: beq         $v0, $zero, L_80801C5C
    if (ctx->r2 == 0) {
        // 0x808019D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801C5C;
    }
    // 0x808019D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808019D8: jal         0x80801600
    // 0x808019DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801600_bstaxi(rdram, ctx);
        goto after_7;
    // 0x808019DC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x808019E0: b           L_80801C60
    // 0x808019E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801C60;
    // 0x808019E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808019E8:
    // 0x808019E8: lui         $a1, 0x3EE1
    ctx->r5 = S32(0X3EE1 << 16);
    // 0x808019EC: ori         $a1, $a1, 0x47AE
    ctx->r5 = ctx->r5 | 0X47AE;
    // 0x808019F0: jal         0x8008CB10
    // 0x808019F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_8;
    // 0x808019F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808019F8: beq         $v0, $zero, L_80801A18
    if (ctx->r2 == 0) {
        // 0x808019FC: lui         $a2, 0x3F73
        ctx->r6 = S32(0X3F73 << 16);
            goto L_80801A18;
    }
    // 0x808019FC: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80801A00: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80801A04: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80801A08: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A10: jal         0x8009DC98
    // 0x80801A14: addiu       $a1, $zero, 0x5AC
    ctx->r5 = ADD32(0, 0X5AC);
    func_8009DC98(rdram, ctx);
        goto after_9;
    // 0x80801A14: addiu       $a1, $zero, 0x5AC
    ctx->r5 = ADD32(0, 0X5AC);
    after_9:
L_80801A18:
    // 0x80801A18: lui         $a1, 0x3F23
    ctx->r5 = S32(0X3F23 << 16);
    // 0x80801A1C: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80801A20: jal         0x8008CB10
    // 0x80801A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_10;
    // 0x80801A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801A28: beq         $v0, $zero, L_80801A38
    if (ctx->r2 == 0) {
        // 0x80801A2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801A38;
    }
    // 0x80801A2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A30: jal         0x8009B9B0
    // 0x80801A34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_11;
    // 0x80801A34: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_11:
L_80801A38:
    // 0x80801A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A3C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801A40: jal         0x80084518
    // 0x80801A44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _babackpack_entrypoint_6(rdram, ctx);
        goto after_12;
    // 0x80801A44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_12:
    // 0x80801A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A4C: jal         0x80085300
    // 0x80801A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_13;
    // 0x80801A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80801A54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801A58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801A5C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801A60: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801A64: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80801A68: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80801A6C: jal         0x800F10B4
    // 0x80801A70: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x80801A70: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x80801A74: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80801A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A7C: jal         0x80085300
    // 0x80801A80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_get(rdram, ctx);
        goto after_15;
    // 0x80801A80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80801A84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(392, 0X20C8) << 16);
    // 0x80801A88: lwc1        $f14, 0x20C8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(392, 0X20C8));
    // 0x80801A8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801A90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801A94: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80801A98: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80801A9C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80801AA0: jal         0x800F10B4
    // 0x80801AA4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800F10B4(rdram, ctx);
        goto after_16;
    // 0x80801AA4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_16:
    // 0x80801AA8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80801AAC: jal         0x80084768
    // 0x80801AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bapackctrl_entrypoint_1(rdram, ctx);
        goto after_17;
    // 0x80801AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801AB4: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    // 0x80801AB8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80801ABC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80801AC0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80801AC4: jal         0x8008A538
    // 0x80801AC8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    _subaddietaxi_entrypoint_8(rdram, ctx);
        goto after_18;
    // 0x80801AC8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_18:
    // 0x80801ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AD0: jal         0x800852F0
    // 0x80801AD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_19;
    // 0x80801AD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80801AD8: beq         $v0, $zero, L_80801C5C
    if (ctx->r2 == 0) {
        // 0x80801ADC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801C5C;
    }
    // 0x80801ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AE0: jal         0x80801600
    // 0x80801AE4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801600_bstaxi(rdram, ctx);
        goto after_20;
    // 0x80801AE4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_20:
    // 0x80801AE8: b           L_80801C60
    // 0x80801AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801C60;
    // 0x80801AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801AF0:
    // 0x80801AF0: lui         $a1, 0x3F23
    ctx->r5 = S32(0X3F23 << 16);
    // 0x80801AF4: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x80801AF8: jal         0x8008CB10
    // 0x80801AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_21;
    // 0x80801AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80801B00: beq         $v0, $zero, L_80801B10
    if (ctx->r2 == 0) {
        // 0x80801B04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B10;
    }
    // 0x80801B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B08: jal         0x8009B9B0
    // 0x80801B0C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_22;
    // 0x80801B0C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_22:
L_80801B10:
    // 0x80801B10: jal         0x8008CAEC
    // 0x80801B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_23;
    // 0x80801B14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80801B18: beq         $v0, $zero, L_80801C5C
    if (ctx->r2 == 0) {
        // 0x80801B1C: addiu       $t8, $zero, 0x125
        ctx->r24 = ADD32(0, 0X125);
            goto L_80801C5C;
    }
    // 0x80801B1C: addiu       $t8, $zero, 0x125
    ctx->r24 = ADD32(0, 0X125);
    // 0x80801B20: b           L_80801C5C
    // 0x80801B24: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
        goto L_80801C5C;
    // 0x80801B24: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_80801B28:
    // 0x80801B28: jal         0x8008CAEC
    // 0x80801B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_24;
    // 0x80801B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80801B30: beq         $v0, $zero, L_80801C5C
    if (ctx->r2 == 0) {
        // 0x80801B34: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801C5C;
    }
    // 0x80801B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B38: jal         0x80801600
    // 0x80801B3C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801600_bstaxi(rdram, ctx);
        goto after_25;
    // 0x80801B3C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_25:
    // 0x80801B40: b           L_80801C60
    // 0x80801B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80801C60;
    // 0x80801B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801B48:
    // 0x80801B48: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80801B4C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801B50: jal         0x8008CB10
    // 0x80801B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_26;
    // 0x80801B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80801B58: beq         $v0, $zero, L_80801B70
    if (ctx->r2 == 0) {
        // 0x80801B5C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B70;
    }
    // 0x80801B5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B60: addiu       $a1, $zero, 0x5AF
    ctx->r5 = ADD32(0, 0X5AF);
    // 0x80801B64: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801B68: jal         0x8009DF18
    // 0x80801B6C: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF18(rdram, ctx);
        goto after_27;
    // 0x80801B6C: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_27:
L_80801B70:
    // 0x80801B70: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80801B74: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801B78: jal         0x8008CB10
    // 0x80801B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_28;
    // 0x80801B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80801B80: beq         $v0, $zero, L_80801B9C
    if (ctx->r2 == 0) {
        // 0x80801B84: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B9C;
    }
    // 0x80801B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B88: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80801B8C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801B90: addiu       $a1, $zero, 0x5AF
    ctx->r5 = ADD32(0, 0X5AF);
    // 0x80801B94: jal         0x8009DF18
    // 0x80801B98: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    func_8009DF18(rdram, ctx);
        goto after_29;
    // 0x80801B98: addiu       $a3, $zero, 0x6D60
    ctx->r7 = ADD32(0, 0X6D60);
    after_29:
L_80801B9C:
    // 0x80801B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BA0: jal         0x8008CB10
    // 0x80801BA4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    baanim_isAt(rdram, ctx);
        goto after_30;
    // 0x80801BA4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_30:
    // 0x80801BA8: beq         $v0, $zero, L_80801BD8
    if (ctx->r2 == 0) {
        // 0x80801BAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801BD8;
    }
    // 0x80801BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BB0: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x80801BB4: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x80801BB8: addiu       $t9, $zero, 0x4E20
    ctx->r25 = ADD32(0, 0X4E20);
    // 0x80801BBC: addiu       $t0, $zero, 0x55F0
    ctx->r8 = ADD32(0, 0X55F0);
    // 0x80801BC0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80801BC4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801BC8: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80801BCC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80801BD0: jal         0x8009DFD4
    // 0x80801BD4: addiu       $a1, $zero, 0x5AE
    ctx->r5 = ADD32(0, 0X5AE);
    func_8009DFD4(rdram, ctx);
        goto after_31;
    // 0x80801BD4: addiu       $a1, $zero, 0x5AE
    ctx->r5 = ADD32(0, 0X5AE);
    after_31:
L_80801BD8:
    // 0x80801BD8: lui         $a1, 0x3F34
    ctx->r5 = S32(0X3F34 << 16);
    // 0x80801BDC: ori         $a1, $a1, 0xFDF4
    ctx->r5 = ctx->r5 | 0XFDF4;
    // 0x80801BE0: jal         0x8008CB10
    // 0x80801BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_32;
    // 0x80801BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80801BE8: beq         $v0, $zero, L_80801C20
    if (ctx->r2 == 0) {
        // 0x80801BEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801C20;
    }
    // 0x80801BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BF0: jal         0x80084538
    // 0x80801BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babackpack_set_state(rdram, ctx);
        goto after_33;
    // 0x80801BF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
    // 0x80801BF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801BFC: jal         0x800A0CD0
    // 0x80801C00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CD0(rdram, ctx);
        goto after_34;
    // 0x80801C00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_34:
    // 0x80801C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C08: jal         0x80084788
    // 0x80801C0C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_35;
    // 0x80801C0C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_35:
    // 0x80801C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801C14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801C18: jal         0x8009E55C
    // 0x80801C1C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_36;
    // 0x80801C1C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_36:
L_80801C20:
    // 0x80801C20: jal         0x8008CAEC
    // 0x80801C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_37;
    // 0x80801C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80801C28: beql        $v0, $zero, L_80801C60
    if (ctx->r2 == 0) {
        // 0x80801C2C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801C60;
    }
    goto skip_0;
    // 0x80801C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80801C30: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801C34: lwc1        $f10, 0x16C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x80801C38: addiu       $t1, $zero, 0x6F
    ctx->r9 = ADD32(0, 0X6F);
    // 0x80801C3C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80801C40: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80801C44: nop

    // 0x80801C48: bc1tl       L_80801C5C
    if (c1cs) {
        // 0x80801C4C: sw          $t2, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r10;
            goto L_80801C5C;
    }
    goto skip_1;
    // 0x80801C4C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    skip_1:
    // 0x80801C50: b           L_80801C5C
    // 0x80801C54: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_80801C5C;
    // 0x80801C54: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x80801C58: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_80801C5C:
    // 0x80801C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801C60:
    // 0x80801C60: jal         0x8009E5C8
    // 0x80801C64: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    bs_setState(rdram, ctx);
        goto after_38;
    // 0x80801C64: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    after_38:
    // 0x80801C68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801C6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801C70: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801C74: jr          $ra
    // 0x80801C78: nop

    return;
    // 0x80801C78: nop

;}
RECOMP_FUNC void func_80800B80_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B80: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80800B84: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80800B88: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800B8C: bgez        $t8, L_80800B98
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800B90: nop
    
            goto L_80800B98;
    }
    // 0x80800B90: nop

    // 0x80800B94: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
L_80800B98:
    // 0x80800B98: jr          $ra
    // 0x80800B9C: nop

    return;
    // 0x80800B9C: nop

;}
RECOMP_FUNC void func_800BDAD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDAD4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BDAD8: addiu       $t2, $t2, -0x7BF0
    ctx->r10 = ADD32(ctx->r10, -0X7BF0);
    // 0x800BDADC: lw          $a1, 0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X4);
    // 0x800BDAE0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BDAE4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BDAE8: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800BDAEC: bne         $at, $zero, L_800BDB4C
    if (ctx->r1 != 0) {
        // 0x800BDAF0: nop
    
            goto L_800BDB4C;
    }
    // 0x800BDAF0: nop

    // 0x800BDAF4: lw          $a2, 0x4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X4);
    // 0x800BDAF8: lw          $a3, 0x8($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X8);
    // 0x800BDAFC: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800BDB00: bne         $at, $zero, L_800BDB4C
    if (ctx->r1 != 0) {
        // 0x800BDB04: nop
    
            goto L_800BDB4C;
    }
    // 0x800BDB04: nop

    // 0x800BDB08: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800BDB0C: lw          $t1, 0xC($t2)
    ctx->r9 = MEM_W(ctx->r10, 0XC);
    // 0x800BDB10: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800BDB14: bne         $at, $zero, L_800BDB4C
    if (ctx->r1 != 0) {
        // 0x800BDB18: nop
    
            goto L_800BDB4C;
    }
    // 0x800BDB18: nop

    // 0x800BDB1C: lw          $t6, 0x10($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X10);
    // 0x800BDB20: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BDB24: bne         $at, $zero, L_800BDB4C
    if (ctx->r1 != 0) {
        // 0x800BDB28: nop
    
            goto L_800BDB4C;
    }
    // 0x800BDB28: nop

    // 0x800BDB2C: lw          $t7, 0x14($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X14);
    // 0x800BDB30: slt         $at, $t7, $a2
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BDB34: bne         $at, $zero, L_800BDB4C
    if (ctx->r1 != 0) {
        // 0x800BDB38: nop
    
            goto L_800BDB4C;
    }
    // 0x800BDB38: nop

    // 0x800BDB3C: lw          $t8, 0x18($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X18);
    // 0x800BDB40: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BDB44: beql        $at, $zero, L_800BDB58
    if (ctx->r1 == 0) {
        // 0x800BDB48: lw          $t9, 0x20($t2)
        ctx->r25 = MEM_W(ctx->r10, 0X20);
            goto L_800BDB58;
    }
    goto skip_0;
    // 0x800BDB48: lw          $t9, 0x20($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X20);
    skip_0:
L_800BDB4C:
    // 0x800BDB4C: jr          $ra
    // 0x800BDB50: addiu       $v0, $v0, -0x7BBC
    ctx->r2 = ADD32(ctx->r2, -0X7BBC);
    return;
    // 0x800BDB50: addiu       $v0, $v0, -0x7BBC
    ctx->r2 = ADD32(ctx->r2, -0X7BBC);
    // 0x800BDB54: lw          $t9, 0x20($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X20);
L_800BDB58:
    // 0x800BDB58: subu        $t3, $t0, $t1
    ctx->r11 = SUB32(ctx->r8, ctx->r9);
    // 0x800BDB5C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800BDB60: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDB64: subu        $t8, $v1, $a1
    ctx->r24 = SUB32(ctx->r3, ctx->r5);
    // 0x800BDB68: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BDB6C: mflo        $t4
    ctx->r12 = lo;
    // 0x800BDB70: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x800BDB74: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800BDB78: lw          $t5, 0x1C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X1C);
    // 0x800BDB7C: subu        $t4, $a2, $a3
    ctx->r12 = SUB32(ctx->r6, ctx->r7);
    // 0x800BDB80: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x800BDB84: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BDB88: mflo        $t6
    ctx->r14 = lo;
    // 0x800BDB8C: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800BDB90: addu        $v0, $t3, $t8
    ctx->r2 = ADD32(ctx->r11, ctx->r24);
    // 0x800BDB94: jr          $ra
    // 0x800BDB98: nop

    return;
    // 0x800BDB98: nop

;}
RECOMP_FUNC void func_8080017C_ncbaspline(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800180: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800184: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800188: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080018C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800190: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800194: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80800198: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8080019C: jal         0x800C82CC
    // 0x808001A0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800C82CC(rdram, ctx);
        goto after_0;
    // 0x808001A0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x808001A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808001A8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x808001AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001B0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x808001BC: bc1tl       L_808001E0
    if (c1cs) {
        // 0x808001C0: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_808001E0;
    }
    goto skip_0;
    // 0x808001C0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_0:
    // 0x808001C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001C8: nop

    // 0x808001CC: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x808001D0: nop

    // 0x808001D4: bc1fl       L_808002A4
    if (!c1cs) {
        // 0x808001D8: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_808002A4;
    }
    goto skip_1;
    // 0x808001D8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_1:
    // 0x808001DC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_808001E0:
    // 0x808001E0: jal         0x800C7A68
    // 0x808001E4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_800C7A68(rdram, ctx);
        goto after_1;
    // 0x808001E4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x808001E8: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808001EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808001F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3062, 0XA34) << 16);
    // 0x808001F4: c.eq.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl == ctx->f8.fl;
    // 0x808001F8: nop

    // 0x808001FC: bc1f        L_8080022C
    if (!c1cs) {
        // 0x80800200: nop
    
            goto L_8080022C;
    }
    // 0x80800200: nop

    // 0x80800204: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3062, 0XA30) << 16);
    // 0x80800208: lwc1        $f10, 0xA30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3062, 0XA30));
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800214: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80800218: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8080021C: jal         0x800C7A68
    // 0x80800220: nop

    func_800C7A68(rdram, ctx);
        goto after_2;
    // 0x80800220: nop

    after_2:
    // 0x80800224: b           L_8080024C
    // 0x80800228: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
        goto L_8080024C;
    // 0x80800228: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
L_8080022C:
    // 0x8080022C: lwc1        $f18, 0xA34($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3062, 0XA34));
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800238: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8080023C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800240: jal         0x800C7A68
    // 0x80800244: nop

    func_800C7A68(rdram, ctx);
        goto after_3;
    // 0x80800244: nop

    after_3:
    // 0x80800248: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
L_8080024C:
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800250: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800254: jal         0x800EFB24
    // 0x80800258: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x80800258: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_4:
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: jal         0x800EF368
    // 0x80800264: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    func_800EF368(rdram, ctx);
        goto after_5;
    // 0x80800264: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    after_5:
    // 0x80800268: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080026C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800270: jal         0x800EE780
    // 0x80800274: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_800EE780(rdram, ctx);
        goto after_6;
    // 0x80800274: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x80800278: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8080027C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800280: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800284: jal         0x800F018C
    // 0x80800288: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    func_800F018C(rdram, ctx);
        goto after_7;
    // 0x80800288: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    after_7:
    // 0x8080028C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80800290: jal         0x800EEAD4
    // 0x80800294: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    func_800EEAD4(rdram, ctx);
        goto after_8;
    // 0x80800294: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_8:
    // 0x80800298: b           L_80800308
    // 0x8080029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800308;
    // 0x8080029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_808002A4:
    // 0x808002A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x808002AC: jal         0x800C7A68
    // 0x808002B0: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_800C7A68(rdram, ctx);
        goto after_9;
    // 0x808002B0: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x808002B4: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x808002B8: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x808002BC: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x808002C0: lw          $t7, 0x44($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X44);
    // 0x808002C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C8: lwc1        $f0, 0x8($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X8);
    // 0x808002CC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x808002D0: nop

    // 0x808002D4: bc1fl       L_808002F8
    if (!c1cs) {
        // 0x808002D8: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_808002F8;
    }
    goto skip_2;
    // 0x808002D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_2:
    // 0x808002DC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x808002E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808002E4: jal         0x800C7B28
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C7B28(rdram, ctx);
        goto after_10;
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808002EC: b           L_80800308
    // 0x808002F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800308;
    // 0x808002F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_808002F8:
    // 0x808002F8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x808002FC: jal         0x800C7B28
    // 0x80800300: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    func_800C7B28(rdram, ctx);
        goto after_11;
    // 0x80800300: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_11:
    // 0x80800304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800308:
    // 0x80800308: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080030C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800310: jr          $ra
    // 0x80800314: nop

    return;
    // 0x80800314: nop

;}
RECOMP_FUNC void bsblongleg_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005C4: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x808005C8: jal         0x8008CB3C
    // 0x808005CC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_0;
    // 0x808005CC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_0:
    // 0x808005D0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808005D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808005D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808005E4: jal         0x8009FFD8
    // 0x808005E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x808005E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: jal         0x8009B9B0
    // 0x808005F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_2;
    // 0x808005F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x808005F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005FC: jal         0x800931AC
    // 0x80800600: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800931AC(rdram, ctx);
        goto after_3;
    // 0x80800600: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800604: jal         0x8080013C
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080013C_bsblongleg(rdram, ctx);
        goto after_4;
    // 0x80800608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080060C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800610: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800618: jr          $ra
    // 0x8080061C: nop

    return;
    // 0x8080061C: nop

;}
RECOMP_FUNC void chstoneballcontrol_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804DF0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1608, 0X5434) << 16);
    // 0x80804DF4: jr          $ra
    // 0x80804DF8: addiu       $v0, $v0, 0x5434
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1608, 0X5434));
    return;
    // 0x80804DF8: addiu       $v0, $v0, 0x5434
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1608, 0X5434));
    // 0x80804DFC: nop

;}
RECOMP_FUNC void _chstoneballcontrol_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086A50: syscall     409
    recomp_syscall_handler(rdram, ctx, 0x80086A50);
    return;
    // 0x80086A54: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8001A290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A298: jal         0x80015190
    // 0x8001A29C: nop

    func_80015190(rdram, ctx);
        goto after_0;
    // 0x8001A29C: nop

    after_0:
    // 0x8001A2A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A2A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A2A8: jr          $ra
    // 0x8001A2AC: nop

    return;
    // 0x8001A2AC: nop

;}
RECOMP_FUNC void func_8080097C_chboggygirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080097C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800980: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800984: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080098C: jal         0x80100094
    // 0x80800990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800994: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800998: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x8080099C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x808009A0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808009A4: bne         $t7, $at, L_808009CC
    if (ctx->r15 != ctx->r1) {
        // 0x808009A8: nop
    
            goto L_808009CC;
    }
    // 0x808009A8: nop

    // 0x808009AC: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x808009B0: sll         $t0, $t8, 17
    ctx->r8 = S32(ctx->r24 << 17);
    // 0x808009B4: bltzl       $t0, L_80800A3C
    if (SIGNED(ctx->r8) < 0) {
        // 0x808009B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A3C;
    }
    goto skip_0;
    // 0x808009B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808009BC: jal         0x800FFAB0
    // 0x808009C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x808009C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808009C4: b           L_80800A3C
    // 0x808009C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800A3C;
    // 0x808009C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009CC:
    // 0x808009CC: jal         0x80105834
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_2;
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808009D4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808009D8: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x808009DC: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x808009E0: jal         0x80089F18
    // 0x808009E4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808009E4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_3:
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009EC: jal         0x80105230
    // 0x808009F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80105230(rdram, ctx);
        goto after_4;
    // 0x808009F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808009F4: jal         0x80105A5C
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_5;
    // 0x808009F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808009FC: beq         $v0, $zero, L_80800A38
    if (ctx->r2 == 0) {
        // 0x80800A00: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80800A38;
    }
    // 0x80800A00: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80800A04: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80800A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A0C: sll         $t4, $t2, 17
    ctx->r12 = S32(ctx->r10 << 17);
    // 0x80800A10: bgez        $t4, L_80800A30
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800A14: nop
    
            goto L_80800A30;
    }
    // 0x80800A14: nop

    // 0x80800A18: jal         0x80102424
    // 0x80800A1C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800A1C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_6:
    // 0x80800A20: lbu         $t5, 0x65($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X65);
    // 0x80800A24: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x80800A28: b           L_80800A38
    // 0x80800A2C: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
        goto L_80800A38;
    // 0x80800A2C: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
L_80800A30:
    // 0x80800A30: jal         0x800FFAB0
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x80800A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80800A38:
    // 0x80800A38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A3C:
    // 0x80800A3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800A40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800A44: jr          $ra
    // 0x80800A48: nop

    return;
    // 0x80800A48: nop

;}
RECOMP_FUNC void func_80800904_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080090C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800910: jal         0x80100094
    // 0x80800914: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800914: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800918: bne         $v0, $zero, L_80800960
    if (ctx->r2 != 0) {
        // 0x8080091C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800960;
    }
    // 0x8080091C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800920: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800924: jal         0x800897C0
    // 0x80800928: addiu       $a2, $zero, 0x51
    ctx->r6 = ADD32(0, 0X51);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800928: addiu       $a2, $zero, 0x51
    ctx->r6 = ADD32(0, 0X51);
    after_1:
    // 0x8080092C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800930: jal         0x80100094
    // 0x80800934: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800934: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800938: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080093C: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x80800940: jal         0x800897E8
    // 0x80800944: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80800944: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_3:
    // 0x80800948: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080094C: jal         0x80100094
    // 0x80800950: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x80800950: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800954: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800958: jal         0x80089810
    // 0x8080095C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x8080095C: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_5:
L_80800960:
    // 0x80800960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800964: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800968: jr          $ra
    // 0x8080096C: nop

    return;
    // 0x8080096C: nop

;}
RECOMP_FUNC void chdragonbrothers_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804FBC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1852, 0X5A5C) << 16);
    // 0x80804FC0: jr          $ra
    // 0x80804FC4: addiu       $v0, $v0, 0x5A5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1852, 0X5A5C));
    return;
    // 0x80804FC4: addiu       $v0, $v0, 0x5A5C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1852, 0X5A5C));
    // 0x80804FC8: nop

    // 0x80804FCC: nop

;}
RECOMP_FUNC void bsbbarge_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800344: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800348: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080034C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800350: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800354: jal         0x8008CABC
    // 0x80800358: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800358: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x8080035C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: jal         0x80091A30
    // 0x80800368: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_released(rdram, ctx);
        goto after_1;
    // 0x80800368: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x8080036C: beq         $v0, $zero, L_8080037C
    if (ctx->r2 == 0) {
        // 0x80800370: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_8080037C;
    }
    // 0x80800370: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800374: jal         0x80095760
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baflag_set(rdram, ctx);
        goto after_2;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8080037C:
    // 0x8080037C: lw          $t6, 0x160($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X160);
    // 0x80800380: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800384: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80800388: beq         $at, $zero, L_80800594
    if (ctx->r1 == 0) {
        // 0x8080038C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800594;
    }
    // 0x8080038C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800390: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(57, 0X61C) << 16);
    // 0x80800394: addu        $at, $at, $t7
    gpr jr_addend_8080039C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800398: lw          $t7, 0x61C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(57, 0X61C));
    // 0x8080039C: jr          $t7
    // 0x808003A0: nop

    switch (jr_addend_8080039C >> 2) {
        case 0: goto L_808003A4; break;
        case 1: goto L_808003E4; break;
        case 2: goto L_80800488; break;
        case 3: goto L_808004B4; break;
        case 4: goto L_80800530; break;
        default: switch_error(__func__, 0x8080039C, 0x8080061C);
    }
    // 0x808003A0: nop

L_808003A4:
    // 0x808003A4: lui         $a1, 0x3E0E
    ctx->r5 = S32(0X3E0E << 16);
    // 0x808003A8: ori         $a1, $a1, 0x8A72
    ctx->r5 = ctx->r5 | 0X8A72;
    // 0x808003AC: jal         0x8008B348
    // 0x808003B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x808003B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808003B4: beq         $v0, $zero, L_808003C4
    if (ctx->r2 == 0) {
        // 0x808003B8: nop
    
            goto L_808003C4;
    }
    // 0x808003B8: nop

    // 0x808003BC: jal         0x8009D874
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_4;
    // 0x808003C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_808003C4:
    // 0x808003C4: jal         0x8008B324
    // 0x808003C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_5;
    // 0x808003C8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x808003CC: beq         $v0, $zero, L_80800594
    if (ctx->r2 == 0) {
        // 0x808003D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800594;
    }
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D4: jal         0x80800000
    // 0x808003D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bsbbarge_setSubstate(rdram, ctx);
        goto after_6;
    // 0x808003D8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808003DC: b           L_80800598
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800598;
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003E4:
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: jal         0x800852F0
    // 0x808003EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_decrement(rdram, ctx);
        goto after_7;
    // 0x808003EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003F4: jal         0x80095748
    // 0x808003F8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    baflag_isFalse(rdram, ctx);
        goto after_8;
    // 0x808003F8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_8:
    // 0x808003FC: beq         $v0, $zero, L_80800464
    if (ctx->r2 == 0) {
        // 0x80800400: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800464;
    }
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800404: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80800408: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080040C: jal         0x80085318
    // 0x80800410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_isLessThan(rdram, ctx);
        goto after_9;
    // 0x80800410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800414: beq         $v0, $zero, L_80800464
    if (ctx->r2 == 0) {
        // 0x80800418: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800464;
    }
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: jal         0x80095738
    // 0x80800420: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    baflag_isTrue(rdram, ctx);
        goto after_10;
    // 0x80800420: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_10:
    // 0x80800424: beq         $v0, $zero, L_80800448
    if (ctx->r2 == 0) {
        // 0x80800428: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800448;
    }
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: addiu       $a1, $zero, 0x4400
    ctx->r5 = ADD32(0, 0X4400);
    // 0x80800434: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800438: jal         0x8009DF94
    // 0x8080043C: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    func_8009DF94(rdram, ctx);
        goto after_11;
    // 0x8080043C: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    after_11:
    // 0x80800440: b           L_8080045C
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080045C;
    // 0x80800444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800448:
    // 0x80800448: addiu       $a1, $zero, 0x442D
    ctx->r5 = ADD32(0, 0X442D);
    // 0x8080044C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800450: jal         0x8009DF94
    // 0x80800454: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    func_8009DF94(rdram, ctx);
        goto after_12;
    // 0x80800454: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    after_12:
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080045C:
    // 0x8080045C: jal         0x80095760
    // 0x80800460: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    baflag_set(rdram, ctx);
        goto after_13;
    // 0x80800460: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_13:
L_80800464:
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800468: jal         0x80085330
    // 0x8080046C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batimer_isZero(rdram, ctx);
        goto after_14;
    // 0x8080046C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800470: beq         $v0, $zero, L_80800594
    if (ctx->r2 == 0) {
        // 0x80800474: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800594;
    }
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800478: jal         0x80800000
    // 0x8080047C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    bsbbarge_setSubstate(rdram, ctx);
        goto after_15;
    // 0x8080047C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x80800480: b           L_80800598
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800598;
    // 0x80800484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800488:
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: jal         0x8009B9B0
    // 0x80800490: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x80800490: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_16:
    // 0x80800494: jal         0x8008B324
    // 0x80800498: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_17;
    // 0x80800498: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_17:
    // 0x8080049C: beq         $v0, $zero, L_80800594
    if (ctx->r2 == 0) {
        // 0x808004A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800594;
    }
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: jal         0x80800000
    // 0x808004A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    bsbbarge_setSubstate(rdram, ctx);
        goto after_18;
    // 0x808004A8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_18:
    // 0x808004AC: b           L_80800598
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800598;
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808004B4:
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: jal         0x800852F0
    // 0x808004BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_decrement(rdram, ctx);
        goto after_19;
    // 0x808004BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x808004C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C4: jal         0x80095748
    // 0x808004C8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    baflag_isFalse(rdram, ctx);
        goto after_20;
    // 0x808004C8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_20:
    // 0x808004CC: bne         $v0, $zero, L_808004E0
    if (ctx->r2 != 0) {
        // 0x808004D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004E0;
    }
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D4: jal         0x80085330
    // 0x808004D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_isZero(rdram, ctx);
        goto after_21;
    // 0x808004D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x808004DC: beq         $v0, $zero, L_808004F4
    if (ctx->r2 == 0) {
        // 0x808004E0: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_808004F4;
    }
L_808004E0:
    // 0x808004E0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808004E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004E8: lwc1        $f4, 0x16C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808004EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808004F0: swc1        $f8, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f8.u32l;
L_808004F4:
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: jal         0x8009B9B0
    // 0x808004FC: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_22;
    // 0x808004FC: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_22:
    // 0x80800500: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800504: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800508: lwc1        $f10, 0x16C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800510: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80800514: nop

    // 0x80800518: bc1fl       L_80800598
    if (!c1cs) {
        // 0x8080051C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800598;
    }
    goto skip_0;
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80800520: jal         0x80800000
    // 0x80800524: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    bsbbarge_setSubstate(rdram, ctx);
        goto after_23;
    // 0x80800524: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_23:
    // 0x80800528: b           L_80800598
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800598;
    // 0x8080052C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800530:
    // 0x80800530: jal         0x8008E078
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_24;
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800538: bne         $v0, $zero, L_80800548
    if (ctx->r2 != 0) {
        // 0x8080053C: lui         $a1, 0x3F33
        ctx->r5 = S32(0X3F33 << 16);
            goto L_80800548;
    }
    // 0x8080053C: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800540: addiu       $t8, $zero, 0x2F
    ctx->r24 = ADD32(0, 0X2F);
    // 0x80800544: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80800548:
    // 0x80800548: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080054C: jal         0x8008B348
    // 0x80800550: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    anctrl_isAt(rdram, ctx);
        goto after_25;
    // 0x80800550: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_25:
    // 0x80800554: beq         $v0, $zero, L_8080056C
    if (ctx->r2 == 0) {
        // 0x80800558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080056C;
    }
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080055C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800560: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80800564: jal         0x80095774
    // 0x80800568: swc1        $f18, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f18.u32l;
    baflag_clear(rdram, ctx);
        goto after_26;
    // 0x80800568: swc1        $f18, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f18.u32l;
    after_26:
L_8080056C:
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800570: jal         0x8009B9B0
    // 0x80800574: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_27;
    // 0x80800574: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_27:
    // 0x80800578: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    // 0x8080057C: ori         $a1, $a1, 0x573F
    ctx->r5 = ctx->r5 | 0X573F;
    // 0x80800580: jal         0x8008B348
    // 0x80800584: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_28;
    // 0x80800584: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_28:
    // 0x80800588: beq         $v0, $zero, L_80800594
    if (ctx->r2 == 0) {
        // 0x8080058C: addiu       $t9, $zero, 0x20
        ctx->r25 = ADD32(0, 0X20);
            goto L_80800594;
    }
    // 0x8080058C: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80800590: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80800594:
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800598:
    // 0x80800598: jal         0x80095738
    // 0x8080059C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    baflag_isTrue(rdram, ctx);
        goto after_29;
    // 0x8080059C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_29:
    // 0x808005A0: beq         $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x808005A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005B0;
    }
    // 0x808005A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A8: jal         0x8008EE88
    // 0x808005AC: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    func_8008EE88(rdram, ctx);
        goto after_30;
    // 0x808005AC: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    after_30:
L_808005B0:
    // 0x808005B0: jal         0x8008E35C
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_31;
    // 0x808005B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x808005B8: beq         $v0, $zero, L_808005C8
    if (ctx->r2 == 0) {
        // 0x808005BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005C8;
    }
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: addiu       $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
    // 0x808005C4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_808005C8:
    // 0x808005C8: jal         0x8009E5C8
    // 0x808005CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_32;
    // 0x808005CC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_32:
    // 0x808005D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005DC: jr          $ra
    // 0x808005E0: nop

    return;
    // 0x808005E0: nop

;}
RECOMP_FUNC void _chamazonstadiumguard_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F70: syscall     483
    recomp_syscall_handler(rdram, ctx, 0x80086F70);
    return;
    // 0x80086F74: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80100E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80100E1C: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x80100E20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80100E24: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80100E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100E2C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100E30: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80100E34: jal         0x800B301C
    // 0x80100E38: lw          $a0, 0x5A60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A60);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x80100E38: lw          $a0, 0x5A60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A60);
    after_0:
    // 0x80100E3C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80100E40: sb          $t7, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r15;
    // 0x80100E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80100E48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80100E4C: jr          $ra
    // 0x80100E50: nop

    return;
    // 0x80100E50: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080071C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800724: jal         0x80800060
    // 0x80800728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800060_bsstonehead(rdram, ctx);
        goto after_0;
    // 0x80800728: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080072C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800734: jal         0x808005F0
    // 0x80800738: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_808005F0_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x80800738: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_1:
    // 0x8080073C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800744: jr          $ra
    // 0x80800748: nop

    return;
    // 0x80800748: nop

;}
RECOMP_FUNC void func_800BFCBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFCBC: jr          $ra
    // 0x800BFCC0: nop

    return;
    // 0x800BFCC0: nop

;}
RECOMP_FUNC void func_800C0890(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0894: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C0898: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800C089C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C08A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C08A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C08A8: jal         0x80087E70
    // 0x800C08AC: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    _gcdialogexec_entrypoint_9(rdram, ctx);
        goto after_0;
    // 0x800C08AC: addiu       $a0, $a0, -0x7750
    ctx->r4 = ADD32(ctx->r4, -0X7750);
    after_0:
    // 0x800C08B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C08B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C08B8: jr          $ra
    // 0x800C08BC: nop

    return;
    // 0x800C08BC: nop

;}
RECOMP_FUNC void bsbswim_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EB4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800EB8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(120, 0X1EC0) << 16);
    // 0x80800EBC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800EC0: jr          $ra
    // 0x80800EC4: lw          $v0, 0x1EC0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1EC0));
    return;
    // 0x80800EC4: lw          $v0, 0x1EC0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(120, 0X1EC0));
;}
RECOMP_FUNC void ncpoducam_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800150: jr          $ra
    // 0x80800154: sh          $a1, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r5;
    return;
    // 0x80800154: sh          $a1, 0x48($a0)
    MEM_H(0X48, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void _bsstand_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B70: syscall     90
    recomp_syscall_handler(rdram, ctx, 0x80083B70);
    return;
    // 0x80083B74: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80800448_chlighthalo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800448: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080044C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800450: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800454: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800458: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080045C: bne         $a1, $at, L_80800618
    if (ctx->r5 != ctx->r1) {
        // 0x80800460: sw          $a2, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r6;
            goto L_80800618;
    }
    // 0x80800460: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80800464: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800468: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080046C: addiu       $t8, $t7, -0x32
    ctx->r24 = ADD32(ctx->r15, -0X32);
    // 0x80800470: sltiu       $at, $t8, 0x12
    ctx->r1 = ctx->r24 < 0X12 ? 1 : 0;
    // 0x80800474: beq         $at, $zero, L_808004DC
    if (ctx->r1 == 0) {
        // 0x80800478: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_808004DC;
    }
    // 0x80800478: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8080047C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2432, 0X654) << 16);
    // 0x80800480: addu        $at, $at, $t8
    gpr jr_addend_80800488 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800484: lw          $t8, 0x654($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2432, 0X654));
    // 0x80800488: jr          $t8
    // 0x8080048C: nop

    switch (jr_addend_80800488 >> 2) {
        case 0: goto L_80800490; break;
        case 1: goto L_8080049C; break;
        case 2: goto L_808004A4; break;
        case 3: goto L_808004B0; break;
        case 4: goto L_808004B0; break;
        case 5: goto L_808004BC; break;
        case 6: goto L_808004C8; break;
        case 7: goto L_808004D4; break;
        case 8: goto L_808004DC; break;
        case 9: goto L_808004DC; break;
        case 10: goto L_80800490; break;
        case 11: goto L_8080049C; break;
        case 12: goto L_808004A4; break;
        case 13: goto L_808004B0; break;
        case 14: goto L_808004B0; break;
        case 15: goto L_808004BC; break;
        case 16: goto L_808004C8; break;
        case 17: goto L_808004D4; break;
        default: switch_error(__func__, 0x80800488, 0x80800654);
    }
    // 0x8080048C: nop

L_80800490:
    // 0x80800490: lui         $v0, 0xFFFF
    ctx->r2 = S32(0XFFFF << 16);
    // 0x80800494: b           L_808004E0
    // 0x80800498: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
        goto L_808004E0;
    // 0x80800498: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
L_8080049C:
    // 0x8080049C: b           L_808004E0
    // 0x808004A0: lui         $v0, 0x20FF
    ctx->r2 = S32(0X20FF << 16);
        goto L_808004E0;
    // 0x808004A0: lui         $v0, 0x20FF
    ctx->r2 = S32(0X20FF << 16);
L_808004A4:
    // 0x808004A4: lui         $v0, 0xFF20
    ctx->r2 = S32(0XFF20 << 16);
    // 0x808004A8: b           L_808004E0
    // 0x808004AC: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
        goto L_808004E0;
    // 0x808004AC: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
L_808004B0:
    // 0x808004B0: lui         $v0, 0x20FF
    ctx->r2 = S32(0X20FF << 16);
    // 0x808004B4: b           L_808004E0
    // 0x808004B8: ori         $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 | 0XFF00;
        goto L_808004E0;
    // 0x808004B8: ori         $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 | 0XFF00;
L_808004BC:
    // 0x808004BC: lui         $v0, 0xFF80
    ctx->r2 = S32(0XFF80 << 16);
    // 0x808004C0: b           L_808004E0
    // 0x808004C4: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
        goto L_808004E0;
    // 0x808004C4: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
L_808004C8:
    // 0x808004C8: lui         $v0, 0xFF60
    ctx->r2 = S32(0XFF60 << 16);
    // 0x808004CC: b           L_808004E0
    // 0x808004D0: ori         $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 | 0XFF00;
        goto L_808004E0;
    // 0x808004D0: ori         $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 | 0XFF00;
L_808004D4:
    // 0x808004D4: b           L_808004E0
    // 0x808004D8: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
        goto L_808004E0;
    // 0x808004D8: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
L_808004DC:
    // 0x808004DC: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
L_808004E0:
    // 0x808004E0: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x808004E4: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x808004E8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x808004EC: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x808004F0: andi        $t3, $v0, 0xFF00
    ctx->r11 = ctx->r2 & 0XFF00;
    // 0x808004F4: srl         $t4, $t3, 8
    ctx->r12 = S32(U32(ctx->r11) >> 8);
    // 0x808004F8: srl         $t2, $t1, 16
    ctx->r10 = S32(U32(ctx->r9) >> 16);
    // 0x808004FC: srl         $t0, $t9, 24
    ctx->r8 = S32(U32(ctx->r25) >> 24);
    // 0x80800500: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80800504: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80800508: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800510: jal         0x80089CE8
    // 0x80800514: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x80800514: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80800518: lhu         $t5, 0x76($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X76);
    // 0x8080051C: srl         $t6, $t5, 7
    ctx->r14 = S32(U32(ctx->r13) >> 7);
    // 0x80800520: slti        $at, $t6, 0x3C
    ctx->r1 = SIGNED(ctx->r14) < 0X3C ? 1 : 0;
    // 0x80800524: beql        $at, $zero, L_808005C4
    if (ctx->r1 == 0) {
        // 0x80800528: addiu       $t1, $s0, 0x4
        ctx->r9 = ADD32(ctx->r16, 0X4);
            goto L_808005C4;
    }
    goto skip_0;
    // 0x80800528: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8080052C: jal         0x800BF8E4
    // 0x80800530: nop

    func_800BF8E4(rdram, ctx);
        goto after_1;
    // 0x80800530: nop

    after_1:
    // 0x80800534: blez        $v0, L_808005C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800538: lui         $t8, 0x8080
        ctx->r24 = S32(RELOC_HI16(2432, 0X6A0) << 16);
            goto L_808005C0;
    }
    // 0x80800538: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2432, 0X6A0) << 16);
    // 0x8080053C: addiu       $t8, $t8, 0x6A0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2432, 0X6A0));
    // 0x80800540: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80800544: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x80800548: addiu       $t7, $sp, 0x28
    ctx->r15 = ADD32(ctx->r29, 0X28);
    // 0x8080054C: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x80800550: sw          $t0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r8;
    // 0x80800554: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800558: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8080055C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800560: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800564: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80800568: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8080056C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800570: jal         0x800C8A98
    // 0x80800574: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x80800574: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80800578: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8080057C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80800580: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80800584: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800588: jal         0x800C8FB0
    // 0x8080058C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800C8FB0(rdram, ctx);
        goto after_3;
    // 0x8080058C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800590: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x80800594: jal         0x800C8CB8
    // 0x80800598: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_4;
    // 0x80800598: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x8080059C: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x808005A0: jal         0x800C8F64
    // 0x808005A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800C8F64(rdram, ctx);
        goto after_5;
    // 0x808005A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x808005A8: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x808005AC: jal         0x800C8D4C
    // 0x808005B0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800C8D4C(rdram, ctx);
        goto after_6;
    // 0x808005B0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x808005B4: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x808005B8: jal         0x800C8FE0
    // 0x808005BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C8FE0(rdram, ctx);
        goto after_7;
    // 0x808005BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_808005C0:
    // 0x808005C0: addiu       $t1, $s0, 0x4
    ctx->r9 = ADD32(ctx->r16, 0X4);
L_808005C4:
    // 0x808005C4: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x808005C8: jal         0x800E8714
    // 0x808005CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E8714(rdram, ctx);
        goto after_8;
    // 0x808005CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x808005D0: sb          $v0, 0x34($s0)
    MEM_B(0X34, ctx->r16) = ctx->r2;
    // 0x808005D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808005D8: jal         0x800E8830
    // 0x808005DC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    func_800E8830(rdram, ctx);
        goto after_9;
    // 0x808005DC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    after_9:
    // 0x808005E0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808005E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808005E8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808005EC: lbu         $a0, 0x34($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X34);
    // 0x808005F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808005F4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808005F8: jal         0x800E8870
    // 0x808005FC: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    func_800E8870(rdram, ctx);
        goto after_10;
    // 0x808005FC: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    after_10:
    // 0x80800600: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800604: sb          $zero, 0x9B($s0)
    MEM_B(0X9B, ctx->r16) = 0;
    // 0x80800608: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080060C: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x80800610: b           L_8080061C
    // 0x80800614: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
        goto L_8080061C;
    // 0x80800614: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
L_80800618:
    // 0x80800618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080061C:
    // 0x8080061C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800620: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800624: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800628: jr          $ra
    // 0x8080062C: nop

    return;
    // 0x8080062C: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083EE0: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083EE0);
    return;
    // 0x80083EE4: addi        $t0, $zero, 0x8C
    ctx->r8 = ADD32(0, 0X8C);
;}
RECOMP_FUNC void func_8080011C_bsmumstill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080011C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800120: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800124: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800128: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8080012C: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80800130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800138: bne         $t6, $zero, L_80800168
    if (ctx->r14 != 0) {
        // 0x8080013C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80800168;
    }
    // 0x8080013C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800140: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    // 0x80800144: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800148: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080014C: jal         0x8009FFD8
    // 0x80800150: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_0;
    // 0x80800150: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80800154: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800158: jal         0x8009B9B0
    // 0x8080015C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x8080015C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800160: jal         0x800909CC
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800909CC(rdram, ctx);
        goto after_2;
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80800168:
    // 0x80800168: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8080016C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800170: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
    // 0x80800174: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80800178: beq         $t9, $zero, L_808001CC
    if (ctx->r25 == 0) {
        // 0x8080017C: nop
    
            goto L_808001CC;
    }
    // 0x8080017C: nop

    // 0x80800180: beq         $t9, $at, L_8080019C
    if (ctx->r25 == ctx->r1) {
        // 0x80800184: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080019C;
    }
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080018C: beq         $t9, $at, L_808001B4
    if (ctx->r25 == ctx->r1) {
        // 0x80800190: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B4;
    }
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: b           L_808001E0
    // 0x80800198: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001E0;
    // 0x80800198: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080019C:
    // 0x8080019C: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x808001A0: ori         $a2, $a2, 0xF5C3
    ctx->r6 = ctx->r6 | 0XF5C3;
    // 0x808001A4: jal         0x8008CCBC
    // 0x808001A8: addiu       $a1, $zero, 0xB5
    ctx->r5 = ADD32(0, 0XB5);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_3;
    // 0x808001A8: addiu       $a1, $zero, 0xB5
    ctx->r5 = ADD32(0, 0XB5);
    after_3:
    // 0x808001AC: b           L_808001E0
    // 0x808001B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001E0;
    // 0x808001B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001B4:
    // 0x808001B4: lui         $a2, 0x4003
    ctx->r6 = S32(0X4003 << 16);
    // 0x808001B8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808001BC: jal         0x8008CCBC
    // 0x808001C0: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_4;
    // 0x808001C0: addiu       $a1, $zero, 0xB6
    ctx->r5 = ADD32(0, 0XB6);
    after_4:
    // 0x808001C4: b           L_808001E0
    // 0x808001C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808001E0;
    // 0x808001C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001CC:
    // 0x808001CC: jal         0x80090A2C
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80090A2C(rdram, ctx);
        goto after_5;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001D4: jal         0x800951B4
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800951B4(rdram, ctx);
        goto after_6;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808001DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001E0:
    // 0x808001E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001E8: jr          $ra
    // 0x808001EC: nop

    return;
    // 0x808001EC: nop

;}
RECOMP_FUNC void func_800F81A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F81A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F81AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F81B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F81B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F81B8: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F81BC: jal         0x800A1870
    // 0x800F81C0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800A1870(rdram, ctx);
        goto after_0;
    // 0x800F81C0: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F81C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F81C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F81CC: jr          $ra
    // 0x800F81D0: nop

    return;
    // 0x800F81D0: nop

;}
RECOMP_FUNC void func_80800AEC_chklungophial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800AF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800AF4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800AF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800AFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800B00: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800B04: jal         0x80100094
    // 0x80800B08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800B08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B0C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800B10: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800B14: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800B18: bnel        $t6, $at, L_80800B2C
    if (ctx->r14 != ctx->r1) {
        // 0x80800B1C: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_80800B2C;
    }
    goto skip_0;
    // 0x80800B1C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80800B20: b           L_80800BD8
    // 0x80800B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BD8;
    // 0x80800B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800B28: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_80800B2C:
    // 0x80800B2C: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x80800B30: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80800B34: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800B38: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800B3C: addu        $s0, $s1, $t8
    ctx->r16 = ADD32(ctx->r17, ctx->r24);
    // 0x80800B40: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800B44: jal         0x8002D6E0
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bzero(rdram, ctx);
        goto after_1;
    // 0x80800B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800B4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B50: jal         0x800EE7F8
    // 0x80800B54: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800B54: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800B58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC14) << 16);
    // 0x80800B5C: lwc1        $f12, 0xC14($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC14));
    // 0x80800B60: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80800B64: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800B68: jal         0x800DC178
    // 0x80800B6C: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800B6C: nop

    after_3:
    // 0x80800B70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800B74: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80800B78: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC18) << 16);
    // 0x80800B7C: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x80800B80: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800B84: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80800B88: lwc1        $f12, 0xC18($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC18));
    // 0x80800B8C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC1C) << 16);
    // 0x80800B90: jal         0x800DC178
    // 0x80800B94: lwc1        $f14, 0xC1C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC1C));
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80800B94: lwc1        $f14, 0xC1C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC1C));
    after_4:
    // 0x80800B98: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800B9C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800BA0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800BA4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800BA8: jal         0x800DC178
    // 0x80800BAC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800BAC: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    after_5:
    // 0x80800BB0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80800BB4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800BB8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1244, 0XC20) << 16);
    // 0x80800BBC: jal         0x800DC178
    // 0x80800BC0: lwc1        $f14, 0xC20($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC20));
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x80800BC0: lwc1        $f14, 0xC20($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1244, 0XC20));
    after_6:
    // 0x80800BC4: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80800BC8: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80800BCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800BD0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80800BD4: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
L_80800BD8:
    // 0x80800BD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BDC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800BE0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800BE4: jr          $ra
    // 0x80800BE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800BE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BEC: nop

;}
