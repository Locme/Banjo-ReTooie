#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808000C0_basnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C8: jal         0x800A1718
    // 0x808000CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800A1718(rdram, ctx);
        goto after_0;
    // 0x808000CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000D8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x808000DC: jal         0x80800098
    // 0x808000E0: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    func_80800098_basnowball(rdram, ctx);
        goto after_1;
    // 0x808000E0: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    after_1:
    // 0x808000E4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808000EC: jal         0x800959C8
    // 0x808000F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800959C8(rdram, ctx);
        goto after_2;
    // 0x808000F0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808000F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808000F8: jal         0x8009590C
    // 0x808000FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009590C(rdram, ctx);
        goto after_3;
    // 0x808000FC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800104: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800108: jr          $ra
    // 0x8080010C: nop

    return;
    // 0x8080010C: nop

;}
RECOMP_FUNC void func_800FAA74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAA74: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FAA78: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800FAA7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800FAA80: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800FAA84: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x800FAA88: lw          $a2, 0x3898($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3898);
    // 0x800FAA8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FAA90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FAA94: beq         $a2, $zero, L_800FAAA4
    if (ctx->r6 == 0) {
        // 0x800FAA98: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800FAAA4;
    }
    // 0x800FAA98: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800FAA9C: jal         0x8008A5A8
    // 0x800FAAA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _scinfobar_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x800FAAA0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
L_800FAAA4:
    // 0x800FAAA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FAAA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FAAAC: jr          $ra
    // 0x800FAAB0: nop

    return;
    // 0x800FAAB0: nop

;}
RECOMP_FUNC void _basub_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800851A0: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x800851A0);
    return;
    // 0x800851A4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80095798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095798: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009579C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800957A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800957A4: jal         0x800985B8
    // 0x800957A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800985B8(rdram, ctx);
        goto after_0;
    // 0x800957A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800957AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800957B0: jal         0x8009864C
    // 0x800957B4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_8009864C(rdram, ctx);
        goto after_1;
    // 0x800957B4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800957B8: lw          $v0, 0x94($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X94);
    // 0x800957BC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800957C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800957C4: lwc1        $f2, 0x7C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x800957C8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800957CC: nop

    // 0x800957D0: bc1fl       L_800957E8
    if (!c1cs) {
        // 0x800957D4: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_800957E8;
    }
    goto skip_0;
    // 0x800957D4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_0:
    // 0x800957D8: swc1        $f0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f0.u32l;
    // 0x800957DC: lw          $v0, 0x94($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X94);
    // 0x800957E0: lwc1        $f2, 0x7C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x800957E4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_800957E8:
    // 0x800957E8: nop

    // 0x800957EC: bc1f        L_800957F8
    if (!c1cs) {
        // 0x800957F0: nop
    
            goto L_800957F8;
    }
    // 0x800957F0: nop

    // 0x800957F4: swc1        $f12, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f12.u32l;
L_800957F8:
    // 0x800957F8: jal         0x80098590
    // 0x800957FC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80098590(rdram, ctx);
        goto after_2;
    // 0x800957FC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x80095800: lw          $a0, 0x94($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X94);
    // 0x80095804: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80095808: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8009580C: jal         0x800F1E6C
    // 0x80095810: addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    func_800F1E6C(rdram, ctx);
        goto after_3;
    // 0x80095810: addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    after_3:
    // 0x80095814: jal         0x8009C984
    // 0x80095818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_4;
    // 0x80095818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8009581C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80095820: jal         0x800F1DCC
    // 0x80095824: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_5;
    // 0x80095824: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_5:
    // 0x80095828: jal         0x800F2100
    // 0x8009582C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    mlAbsF(rdram, ctx);
        goto after_6;
    // 0x8009582C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x80095830: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80095834: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80095838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009583C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80095840: nop

    // 0x80095844: bc1fl       L_80095860
    if (!c1cs) {
        // 0x80095848: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80095860;
    }
    goto skip_1;
    // 0x80095848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8009584C: jal         0x8009C914
    // 0x80095850: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    yaw_setIdeal(rdram, ctx);
        goto after_7;
    // 0x80095850: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x80095854: jal         0x8009C974
    // 0x80095858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_applyIdeal(rdram, ctx);
        goto after_8;
    // 0x80095858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8009585C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80095860:
    // 0x80095860: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80095864: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80095868: jr          $ra
    // 0x8009586C: nop

    return;
    // 0x8009586C: nop

;}
RECOMP_FUNC void func_80014F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014F00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80014F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014F08: jal         0x80014F58
    // 0x80014F0C: nop

    func_80014F58(rdram, ctx);
        goto after_0;
    // 0x80014F0C: nop

    after_0:
    // 0x80014F10: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80014F14: lh          $t6, -0x709E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X709E);
    // 0x80014F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014F1C: xor         $t7, $v0, $t6
    ctx->r15 = ctx->r2 ^ ctx->r14;
    // 0x80014F20: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80014F24: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014F28: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80014F2C: lw          $v0, -0x7080($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7080);
    // 0x80014F30: jr          $ra
    // 0x80014F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80014F34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _basnowball_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085120: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x80085120);
    return;
    // 0x80085124: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_800C9D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9D88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9D8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9D90: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C9D94: jal         0x800C9DAC
    // 0x800C9D98: addiu       $a1, $a1, 0x5524
    ctx->r5 = ADD32(ctx->r5, 0X5524);
    func_800C9DAC(rdram, ctx);
        goto after_0;
    // 0x800C9D98: addiu       $a1, $a1, 0x5524
    ctx->r5 = ADD32(ctx->r5, 0X5524);
    after_0:
    // 0x800C9D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9DA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9DA4: jr          $ra
    // 0x800C9DA8: nop

    return;
    // 0x800C9DA8: nop

;}
RECOMP_FUNC void func_800F7ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7ECC: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800F7ED0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7ED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F7ED8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7EE0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7EE4: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800F7EE8: jal         0x800917A8
    // 0x800F7EEC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    bastatetimer_set(rdram, ctx);
        goto after_0;
    // 0x800F7EEC: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F7EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F7EF8: jr          $ra
    // 0x800F7EFC: nop

    return;
    // 0x800F7EFC: nop

;}
RECOMP_FUNC void func_8080000C_chmrsboggyhome(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x80088848
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: beq         $v0, $zero, L_80800034
    if (ctx->r2 == 0) {
        // 0x80800020: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800034;
    }
    // 0x80800020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: jal         0x80102424
    // 0x80800028: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8080002C: b           L_80800050
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800050;
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800034:
    // 0x80800034: jal         0x800DA298
    // 0x80800038: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800038: addiu       $a0, $zero, 0x1CD
    ctx->r4 = ADD32(0, 0X1CD);
    after_2:
    // 0x8080003C: bnel        $v0, $zero, L_80800050
    if (ctx->r2 != 0) {
        // 0x80800040: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800050;
    }
    goto skip_0;
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800044: jal         0x800FFAB0
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800FFAB0(rdram, ctx);
        goto after_3;
    // 0x80800048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800050:
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void _ncbatarget_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089498: syscall     782
    recomp_syscall_handler(rdram, ctx, 0x80089498);
    return;
    // 0x8008949C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800DF8_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DF8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800DFC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80800E00: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800E04: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800E08: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80800E0C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800E10: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800E14: jal         0x8001210C
    // 0x80800E18: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80800E18: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80800E1C: beql        $v0, $zero, L_80801014
    if (ctx->r2 == 0) {
        // 0x80800E20: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801014;
    }
    goto skip_0;
    // 0x80800E20: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80800E24: jal         0x800F54E4
    // 0x80800E28: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800E28: nop

    after_1:
    // 0x80800E2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800E30: jal         0x800F7058
    // 0x80800E34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F7058(rdram, ctx);
        goto after_2;
    // 0x80800E34: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800E38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800E3C: beql        $v0, $at, L_80801014
    if (ctx->r2 == ctx->r1) {
        // 0x80800E40: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801014;
    }
    goto skip_1;
    // 0x80800E40: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80800E44: jal         0x800F6590
    // 0x80800E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6590(rdram, ctx);
        goto after_3;
    // 0x80800E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800E4C: bnel        $v0, $zero, L_80801014
    if (ctx->r2 != 0) {
        // 0x80800E50: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801014;
    }
    goto skip_2;
    // 0x80800E50: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80800E54: jal         0x800F7018
    // 0x80800E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F7018(rdram, ctx);
        goto after_4;
    // 0x80800E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800E5C: bnel        $v0, $zero, L_80801014
    if (ctx->r2 != 0) {
        // 0x80800E60: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801014;
    }
    goto skip_3;
    // 0x80800E60: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_3:
    // 0x80800E64: jal         0x800F6DA0
    // 0x80800E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6DA0(rdram, ctx);
        goto after_5;
    // 0x80800E68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800E6C: bnel        $v0, $zero, L_80801014
    if (ctx->r2 != 0) {
        // 0x80800E70: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801014;
    }
    goto skip_4;
    // 0x80800E70: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x80800E74: jal         0x800F6E40
    // 0x80800E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6E40(rdram, ctx);
        goto after_6;
    // 0x80800E78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800E7C: bnel        $v0, $zero, L_80801014
    if (ctx->r2 != 0) {
        // 0x80800E80: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801014;
    }
    goto skip_5;
    // 0x80800E80: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_5:
    // 0x80800E84: jal         0x800F56AC
    // 0x80800E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F56AC(rdram, ctx);
        goto after_7;
    // 0x80800E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800E8C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80800E90: bnel        $v0, $at, L_80801014
    if (ctx->r2 != ctx->r1) {
        // 0x80800E94: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801014;
    }
    goto skip_6;
    // 0x80800E94: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_6:
    // 0x80800E98: jal         0x800F6AA4
    // 0x80800E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6AA4(rdram, ctx);
        goto after_8;
    // 0x80800E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800EA0: bnel        $v0, $zero, L_80801014
    if (ctx->r2 != 0) {
        // 0x80800EA4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801014;
    }
    goto skip_7;
    // 0x80800EA4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_7:
    // 0x80800EA8: jal         0x800F55D0
    // 0x80800EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F55D0(rdram, ctx);
        goto after_9;
    // 0x80800EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800EB0: bnel        $v0, $zero, L_80801014
    if (ctx->r2 != 0) {
        // 0x80800EB4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801014;
    }
    goto skip_8;
    // 0x80800EB4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_8:
    // 0x80800EB8: jal         0x800F6478
    // 0x80800EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6478(rdram, ctx);
        goto after_10;
    // 0x80800EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800EC0: beql        $v0, $zero, L_80801014
    if (ctx->r2 == 0) {
        // 0x80800EC4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801014;
    }
    goto skip_9;
    // 0x80800EC4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_9:
    // 0x80800EC8: jal         0x800F6438
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_11;
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800ED0: beql        $v0, $zero, L_80801014
    if (ctx->r2 == 0) {
        // 0x80800ED4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80801014;
    }
    goto skip_10;
    // 0x80800ED4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_10:
    // 0x80800ED8: jal         0x800F6C5C
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_12;
    // 0x80800EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800EE0: beq         $v0, $zero, L_80801010
    if (ctx->r2 == 0) {
        // 0x80800EE4: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1236, 0X12F4) << 16);
            goto L_80801010;
    }
    // 0x80800EE4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1236, 0X12F4) << 16);
    // 0x80800EE8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800EEC: addiu       $a0, $a0, 0x12F4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1236, 0X12F4));
    // 0x80800EF0: addiu       $a1, $s1, 0x18
    ctx->r5 = ADD32(ctx->r17, 0X18);
    // 0x80800EF4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80800EF8: jal         0x800F1DF4
    // 0x80800EFC: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    func_800F1DF4(rdram, ctx);
        goto after_13;
    // 0x80800EFC: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x80800F00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800F04: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80800F08: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x80800F0C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_80800F10:
    // 0x80800F10: lui         $at, 0x4548
    ctx->r1 = S32(0X4548 << 16);
    // 0x80800F14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800F18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800F1C: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80800F20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F24: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800F28: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800F2C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80800F30: jal         0x800EEB9C
    // 0x80800F34: nop

    func_800EEB9C(rdram, ctx);
        goto after_14;
    // 0x80800F34: nop

    after_14:
    // 0x80800F38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1236, 0X1250) << 16);
    // 0x80800F3C: lwc1        $f10, 0x1250($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1236, 0X1250));
    // 0x80800F40: addiu       $t6, $sp, 0x5C
    ctx->r14 = ADD32(ctx->r29, 0X5C);
    // 0x80800F44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800F48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800F4C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800F50: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    // 0x80800F54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800F58: jal         0x800C696C
    // 0x80800F5C: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    func_800C696C(rdram, ctx);
        goto after_15;
    // 0x80800F5C: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    after_15:
    // 0x80800F60: beq         $v0, $zero, L_80800FB8
    if (ctx->r2 == 0) {
        // 0x80800F64: addiu       $s0, $s0, 0x64
        ctx->r16 = ADD32(ctx->r16, 0X64);
            goto L_80800FB8;
    }
    // 0x80800F64: addiu       $s0, $s0, 0x64
    ctx->r16 = ADD32(ctx->r16, 0X64);
    // 0x80800F68: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1236, 0X1254) << 16);
    // 0x80800F6C: lwc1        $f16, 0x1254($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1236, 0X1254));
    // 0x80800F70: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80800F74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1236, 0X1258) << 16);
    // 0x80800F78: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800F7C: nop

    // 0x80800F80: bc1fl       L_80800FBC
    if (!c1cs) {
        // 0x80800F84: addiu       $at, $zero, 0x258
        ctx->r1 = ADD32(0, 0X258);
            goto L_80800FBC;
    }
    goto skip_11;
    // 0x80800F84: addiu       $at, $zero, 0x258
    ctx->r1 = ADD32(0, 0X258);
    skip_11:
    // 0x80800F88: lwc1        $f4, 0x1258($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1236, 0X1258));
    // 0x80800F8C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80800F90: nop

    // 0x80800F94: bc1fl       L_80800FBC
    if (!c1cs) {
        // 0x80800F98: addiu       $at, $zero, 0x258
        ctx->r1 = ADD32(0, 0X258);
            goto L_80800FBC;
    }
    goto skip_12;
    // 0x80800F98: addiu       $at, $zero, 0x258
    ctx->r1 = ADD32(0, 0X258);
    skip_12:
    // 0x80800F9C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800FA0: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x80800FA4: c.eq.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl == ctx->f6.fl;
    // 0x80800FA8: nop

    // 0x80800FAC: bc1fl       L_80800FBC
    if (!c1cs) {
        // 0x80800FB0: addiu       $at, $zero, 0x258
        ctx->r1 = ADD32(0, 0X258);
            goto L_80800FBC;
    }
    goto skip_13;
    // 0x80800FB0: addiu       $at, $zero, 0x258
    ctx->r1 = ADD32(0, 0X258);
    skip_13:
    // 0x80800FB4: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
L_80800FB8:
    // 0x80800FB8: addiu       $at, $zero, 0x258
    ctx->r1 = ADD32(0, 0X258);
L_80800FBC:
    // 0x80800FBC: bnel        $s0, $at, L_80800F10
    if (ctx->r16 != ctx->r1) {
        // 0x80800FC0: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_80800F10;
    }
    goto skip_14;
    // 0x80800FC0: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_14:
    // 0x80800FC4: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80800FC8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800FCC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800FD0: add.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x80800FD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800FD8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80800FDC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800FE0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800FE4: jal         0x800EEB9C
    // 0x80800FE8: nop

    func_800EEB9C(rdram, ctx);
        goto after_16;
    // 0x80800FE8: nop

    after_16:
    // 0x80800FEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1236, 0X125C) << 16);
    // 0x80800FF0: lwc1        $f4, 0x125C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1236, 0X125C));
    // 0x80800FF4: jal         0x800F54E4
    // 0x80800FF8: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    func_800F54E4(rdram, ctx);
        goto after_17;
    // 0x80800FF8: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    after_17:
    // 0x80800FFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801000: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    // 0x80801004: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80801008: jal         0x800F7D90
    // 0x8080100C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800F7D90(rdram, ctx);
        goto after_18;
    // 0x8080100C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_18:
L_80801010:
    // 0x80801010: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80801014:
    // 0x80801014: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801018: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8080101C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80801020: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80801024: jr          $ra
    // 0x80801028: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80801028: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8010AFF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AFF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010AFFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B000: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010B004: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010B008: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010B00C: jal         0x8010C4AC
    // 0x8010B010: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_8010C4AC(rdram, ctx);
        goto after_0;
    // 0x8010B010: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010B014: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8010B018: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8010B01C: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8010B020: lw          $a1, 0x44($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X44);
    // 0x8010B024: jal         0x800EF214
    // 0x8010B028: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    func_800EF214(rdram, ctx);
        goto after_1;
    // 0x8010B028: lw          $a2, 0x48($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X48);
    after_1:
    // 0x8010B02C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B038: jr          $ra
    // 0x8010B03C: nop

    return;
    // 0x8010B03C: nop

;}
RECOMP_FUNC void _bashoes_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085000: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80085000);
    return;
    // 0x80085004: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80115750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115750: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80115754: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80115758: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8011575C: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x80115760: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80115764: lbu         $t6, 0x10($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10);
    // 0x80115768: beql        $t6, $zero, L_80115798
    if (ctx->r14 == 0) {
        // 0x8011576C: lwc1        $f4, 0x4($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80115798;
    }
    goto skip_0;
    // 0x8011576C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80115770: lbu         $t7, 0x1C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1C);
    // 0x80115774: bnel        $t7, $zero, L_80115798
    if (ctx->r15 != 0) {
        // 0x80115778: lwc1        $f4, 0x4($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80115798;
    }
    goto skip_1;
    // 0x80115778: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x8011577C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80115780: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x80115784: jal         0x80115618
    // 0x80115788: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_80115618(rdram, ctx);
        goto after_0;
    // 0x80115788: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8011578C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80115790: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x80115794: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
L_80115798:
    // 0x80115798: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8011579C: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x801157A0: lbu         $t8, 0x11($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X11);
    // 0x801157A4: beql        $t8, $zero, L_801157E0
    if (ctx->r24 == 0) {
        // 0x801157A8: lw          $t9, 0x3C($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X3C);
            goto L_801157E0;
    }
    goto skip_2;
    // 0x801157A8: lw          $t9, 0x3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X3C);
    skip_2:
    // 0x801157AC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x801157B0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801157B4: jal         0x800F1DCC
    // 0x801157B8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x801157B8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x801157BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801157C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801157C4: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801157C8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x801157CC: nop

    // 0x801157D0: bc1fl       L_801157E0
    if (!c1cs) {
        // 0x801157D4: lw          $t9, 0x3C($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X3C);
            goto L_801157E0;
    }
    goto skip_3;
    // 0x801157D4: lw          $t9, 0x3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X3C);
    skip_3:
    // 0x801157D8: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
    // 0x801157DC: lw          $t9, 0x3C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X3C);
L_801157E0:
    // 0x801157E0: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801157E4: lbu         $t0, 0x12($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X12);
    // 0x801157E8: beql        $t0, $zero, L_80115818
    if (ctx->r8 == 0) {
        // 0x801157EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80115818;
    }
    goto skip_4;
    // 0x801157EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x801157F0: jal         0x800F1DCC
    // 0x801157F4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800F1DCC(rdram, ctx);
        goto after_2;
    // 0x801157F4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_2:
    // 0x801157F8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801157FC: nop

    // 0x80115800: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80115804: nop

    // 0x80115808: bc1fl       L_80115818
    if (!c1cs) {
        // 0x8011580C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80115818;
    }
    goto skip_5;
    // 0x8011580C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80115810: lwc1        $f20, 0x20($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80115814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80115818:
    // 0x80115818: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x8011581C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80115820: jr          $ra
    // 0x80115824: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80115824: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_801125B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801125B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801125BC: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x801125C0: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x801125C4: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x801125C8: swc1        $f0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f0.u32l;
    // 0x801125CC: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x801125D0: jr          $ra
    // 0x801125D4: swc1        $f0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f0.u32l;
    return;
    // 0x801125D4: swc1        $f0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80802D2C_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D2C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80802D30: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802D34: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802D38: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80802D3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802D40: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80802D44: jal         0x80100094
    // 0x80802D48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802D48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802D4C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80802D50: jal         0x800D9078
    // 0x80802D54: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x80802D54: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_1:
    // 0x80802D58: jal         0x800D8FF8
    // 0x80802D5C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_2;
    // 0x80802D5C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_2:
    // 0x80802D60: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80802D64: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80802D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D6C: jal         0x8010CD50
    // 0x80802D70: lh          $a1, 0x78($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X78);
    func_8010CD50(rdram, ctx);
        goto after_3;
    // 0x80802D70: lh          $a1, 0x78($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X78);
    after_3:
    // 0x80802D74: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80802D78: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80802D7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802D80: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80802D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802D88: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80802D8C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80802D90: jal         0x80102B2C
    // 0x80802D94: nop

    func_80102B2C(rdram, ctx);
        goto after_4;
    // 0x80802D94: nop

    after_4:
    // 0x80802D98: jal         0x808029D8
    // 0x80802D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808029D8_chweldarboss(rdram, ctx);
        goto after_5;
    // 0x80802D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80802DA0: jal         0x80802E80
    // 0x80802DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802E80_chweldarboss(rdram, ctx);
        goto after_6;
    // 0x80802DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802DA8: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x80802DAC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80802DB0: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80802DB4: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80802DB8: bgezl       $t9, L_80802E58
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80802DBC: lw          $t1, 0x50($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X50);
            goto L_80802E58;
    }
    goto skip_0;
    // 0x80802DBC: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    skip_0:
    // 0x80802DC0: jal         0x800EEB9C
    // 0x80802DC4: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EEB9C(rdram, ctx);
        goto after_7;
    // 0x80802DC4: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_7:
    // 0x80802DC8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80802DCC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80802DD0: jal         0x800EE7F8
    // 0x80802DD4: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80802DD4: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    after_8:
    // 0x80802DD8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80802DDC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80802DE0: jal         0x800EF1B8
    // 0x80802DE4: lui         $a2, 0xC396
    ctx->r6 = S32(0XC396 << 16);
    func_800EF1B8(rdram, ctx);
        goto after_9;
    // 0x80802DE4: lui         $a2, 0xC396
    ctx->r6 = S32(0XC396 << 16);
    after_9:
    // 0x80802DE8: lui         $a2, 0x450F
    ctx->r6 = S32(0X450F << 16);
    // 0x80802DEC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80802DF0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80802DF4: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x80802DF8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80802DFC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80802E00: jal         0x8010D490
    // 0x80802E04: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    func_8010D490(rdram, ctx);
        goto after_10;
    // 0x80802E04: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    after_10:
    // 0x80802E08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80802E0C: beq         $v0, $at, L_80802E24
    if (ctx->r2 == ctx->r1) {
        // 0x80802E10: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80802E24;
    }
    // 0x80802E10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E18: jal         0x80803080
    // 0x80802E1C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80803080_chweldarboss(rdram, ctx);
        goto after_11;
    // 0x80802E1C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_11:
    // 0x80802E20: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
L_80802E24:
    // 0x80802E24: jal         0x80803184
    // 0x80802E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803184_chweldarboss(rdram, ctx);
        goto after_12;
    // 0x80802E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80802E2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802E30: beq         $v0, $at, L_80802E4C
    if (ctx->r2 == ctx->r1) {
        // 0x80802E34: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802E4C;
    }
    // 0x80802E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802E3C: beql        $v0, $at, L_80802E70
    if (ctx->r2 == ctx->r1) {
        // 0x80802E40: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80802E70;
    }
    goto skip_1;
    // 0x80802E40: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80802E44: b           L_80802E58
    // 0x80802E48: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
        goto L_80802E58;
    // 0x80802E48: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
L_80802E4C:
    // 0x80802E4C: jal         0x80801AA0
    // 0x80802E50: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_13;
    // 0x80802E50: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_13:
    // 0x80802E54: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
L_80802E58:
    // 0x80802E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802E5C: beql        $t1, $zero, L_80802E70
    if (ctx->r9 == 0) {
        // 0x80802E60: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80802E70;
    }
    goto skip_2;
    // 0x80802E60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80802E64: jal         0x80801AA0
    // 0x80802E68: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    func_80801AA0_chweldarboss(rdram, ctx);
        goto after_14;
    // 0x80802E68: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_14:
    // 0x80802E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802E70:
    // 0x80802E70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802E74: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80802E78: jr          $ra
    // 0x80802E7C: nop

    return;
    // 0x80802E7C: nop

;}
RECOMP_FUNC void func_80014F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014F4C: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80014F50: jr          $ra
    // 0x80014F54: lh          $v0, -0x709C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X709C);
    return;
    // 0x80014F54: lh          $v0, -0x709C($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X709C);
;}
RECOMP_FUNC void _sccustom_banjo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A930: syscall     857
    recomp_syscall_handler(rdram, ctx, 0x8008A930);
    return;
    // 0x8008A934: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800DFFDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DFFDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800DFFE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DFFE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800DFFE8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800DFFEC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800DFFF0: jal         0x800D93A0
    // 0x800DFFF4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800D93A0(rdram, ctx);
        goto after_0;
    // 0x800DFFF4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800DFFF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800DFFFC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800E0000: jal         0x800DFF2C
    // 0x800E0004: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_800DFF2C(rdram, ctx);
        goto after_1;
    // 0x800E0004: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x800E0008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E000C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E0010: jr          $ra
    // 0x800E0014: nop

    return;
    // 0x800E0014: nop

;}
RECOMP_FUNC void func_80800134_anseq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800134: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800138: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080013C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800140: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800144: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800148: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080014C: jal         0x800B2A58
    // 0x80800150: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    func_800B2A58(rdram, ctx);
        goto after_0;
    // 0x80800150: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    after_0:
    // 0x80800154: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800158: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080015C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800160: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80800164: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80800168: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8080016C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(26, 0X490) << 16);
    // 0x80800170: sb          $t7, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r15;
    // 0x80800174: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800178: addiu       $a2, $a2, 0x490
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(26, 0X490));
    // 0x8080017C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800180: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
    // 0x80800184: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80800188: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080018C: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x80800190: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80800194: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
    // 0x80800198: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8080019C: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x808001A0: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x808001A4: sw          $t2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r10;
    // 0x808001A8: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x808001AC: bc1f        L_808001D0
    if (!c1cs) {
        // 0x808001B0: sb          $t3, 0x6($v0)
        MEM_B(0X6, ctx->r2) = ctx->r11;
            goto L_808001D0;
    }
    // 0x808001B0: sb          $t3, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r11;
    // 0x808001B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001B8: jal         0x808001EC
    // 0x808001BC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    anseq_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808001BC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x808001C0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(26, 0X490) << 16);
    // 0x808001C4: addiu       $a2, $a2, 0x490
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(26, 0X490));
    // 0x808001C8: b           L_808001D4
    // 0x808001CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_808001D4;
    // 0x808001CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_808001D0:
    // 0x808001D0: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
L_808001D4:
    // 0x808001D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x808001DC: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    // 0x808001E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001E4: jr          $ra
    // 0x808001E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x808001E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void chjujubagfx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800404: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800408: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080040C: jal         0x8010D254
    // 0x80800410: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_8010D254(rdram, ctx);
        goto after_0;
    // 0x80800410: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800414: addiu       $a0, $zero, 0x2F9
    ctx->r4 = ADD32(0, 0X2F9);
    // 0x80800418: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8080041C: jal         0x80108474
    // 0x80800420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_1;
    // 0x80800420: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800428: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080042C: jr          $ra
    // 0x80800430: nop

    return;
    // 0x80800430: nop

;}
RECOMP_FUNC void bsjig_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800018: jal         0x8008CABC
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800020: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800024: jal         0x8008AF24
    // 0x80800028: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800028: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080002C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800030: jal         0x8008B1A0
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x80800034: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800038: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080003C: jal         0x8008AED4
    // 0x80800040: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    anctrl_setIndex(rdram, ctx);
        goto after_3;
    // 0x80800040: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    after_3:
    // 0x80800044: lui         $a1, 0x4089
    ctx->r5 = S32(0X4089 << 16);
    // 0x80800048: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8080004C: jal         0x8008B1BC
    // 0x80800050: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80800050: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800054: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800058: jal         0x8008B134
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x8080005C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800060: jal         0x8008B064
    // 0x80800064: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x80800064: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80800068: jal         0x8009F308
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F308(rdram, ctx);
        goto after_7;
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800070: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800074: jal         0x8009C914
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_8;
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080007C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800080: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080008C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800090: jal         0x8009FFD8
    // 0x80800094: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_9;
    // 0x80800094: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_9:
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080009C: jal         0x8009B9B0
    // 0x808000A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_10;
    // 0x808000A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_10:
    // 0x808000A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x808000A8: lbu         $a1, 0x762C($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X762C);
    // 0x808000AC: jal         0x800D0018
    // 0x808000B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D0018(rdram, ctx);
        goto after_11;
    // 0x808000B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x808000B4: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000B8: bne         $a1, $zero, L_808000C4
    if (ctx->r5 != 0) {
        // 0x808000BC: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_808000C4;
    }
    // 0x808000BC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_808000C4:
    // 0x808000C4: jal         0x800FC660
    // 0x808000C8: sw          $a1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r5;
    func_800FC660(rdram, ctx);
        goto after_12;
    // 0x808000C8: sw          $a1, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r5;
    after_12:
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D0: jal         0x800A4DFC
    // 0x808000D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_800A4DFC(rdram, ctx);
        goto after_13;
    // 0x808000D4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_13:
    // 0x808000D8: jal         0x800A4C68
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4C68(rdram, ctx);
        goto after_14;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808000E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000E4: jal         0x800C52F4
    // 0x808000E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800C52F4(rdram, ctx);
        goto after_15;
    // 0x808000E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: jal         0x800A0CF4
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_16;
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: addiu       $a1, $zero, 0x422
    ctx->r5 = ADD32(0, 0X422);
    // 0x80800100: jal         0x8009DE38
    // 0x80800104: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_17;
    // 0x80800104: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_17:
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080010C: jal         0x80095774
    // 0x80800110: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    baflag_clear(rdram, ctx);
        goto after_18;
    // 0x80800110: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_18:
    // 0x80800114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800118: jal         0x80095774
    // 0x8080011C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_clear(rdram, ctx);
        goto after_19;
    // 0x8080011C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_19:
    // 0x80800120: jal         0x8008E944
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E944(rdram, ctx);
        goto after_20;
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800128: jal         0x800A32F8
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A32F8(rdram, ctx);
        goto after_21;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800130: jal         0x80106790
    // 0x80800134: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_22;
    // 0x80800134: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_22:
    // 0x80800138: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080013C: jal         0x800858B8
    // 0x80800140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chjigsawdance_entrypoint_1(rdram, ctx);
        goto after_23;
    // 0x80800140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80800144: sw          $zero, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = 0;
    // 0x80800148: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080014C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800150: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void func_808035D0_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808035D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808035D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808035D8: jal         0x80100094
    // 0x808035DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808035DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808035E0: lbu         $t6, 0x65($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X65);
    // 0x808035E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808035E8: beql        $t6, $zero, L_80803618
    if (ctx->r14 == 0) {
        // 0x808035EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80803618;
    }
    goto skip_0;
    // 0x808035EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808035F0: lh          $a0, 0x78($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X78);
    // 0x808035F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808035F8: jal         0x800F82D4
    // 0x808035FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F82D4(rdram, ctx);
        goto after_1;
    // 0x808035FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80803600: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803604: jal         0x800F7B9C
    // 0x80803608: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_800F7B9C(rdram, ctx);
        goto after_2;
    // 0x80803608: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_2:
    // 0x8080360C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80803610: sb          $zero, 0x65($t7)
    MEM_B(0X65, ctx->r15) = 0;
    // 0x80803614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803618:
    // 0x80803618: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080361C: jr          $ra
    // 0x80803620: nop

    return;
    // 0x80803620: nop

;}
RECOMP_FUNC void chusefeather_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800208: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080020C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800210: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800214: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800218: jal         0x800F5A00
    // 0x8080021C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_0;
    // 0x8080021C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80800220: jal         0x800F5F24
    // 0x80800224: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800F5F24(rdram, ctx);
        goto after_1;
    // 0x80800224: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800228: jal         0x800DC0C0
    // 0x8080022C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x8080022C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800230: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800234: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800238: addiu       $v0, $zero, -0x1E
    ctx->r2 = ADD32(0, -0X1E);
    // 0x8080023C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800240: nop

    // 0x80800244: bc1f        L_80800254
    if (!c1cs) {
        // 0x80800248: nop
    
            goto L_80800254;
    }
    // 0x80800248: nop

    // 0x8080024C: b           L_80800254
    // 0x80800250: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
        goto L_80800254;
    // 0x80800250: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
L_80800254:
    // 0x80800254: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800258: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8080025C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800260: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800264: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800268: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8080026C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800270: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800274: jal         0x80108474
    // 0x80800278: nop

    func_80108474(rdram, ctx);
        goto after_3;
    // 0x80800278: nop

    after_3:
    // 0x8080027C: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x80800280: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800284: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800288: jal         0x80102FDC
    // 0x8080028C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80102FDC(rdram, ctx);
        goto after_4;
    // 0x8080028C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800290: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80800294: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800298: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8080029C: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x808002A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(720, 0X330) << 16);
    // 0x808002A8: swc1        $f4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f4.u32l;
    // 0x808002AC: swc1        $f6, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f6.u32l;
    // 0x808002B0: lwc1        $f8, 0x330($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(720, 0X330));
    // 0x808002B4: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x808002B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002C0: jr          $ra
    // 0x808002C4: nop

    return;
    // 0x808002C4: nop

;}
RECOMP_FUNC void _sumumbofx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089840: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089840);
    return;
    // 0x80089844: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800D98_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DA0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800DA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800DA8: jal         0x80100094
    // 0x80800DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DB0: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80800DB4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800DB8: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80800DBC: bne         $t6, $at, L_80800DD4
    if (ctx->r14 != ctx->r1) {
        // 0x80800DC0: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800DD4;
    }
    // 0x80800DC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800DC4: jal         0x800878A0
    // 0x80800DC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _plsu_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800DC8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800DCC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DD0: sw          $v0, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r2;
L_80800DD4:
    // 0x80800DD4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800DD8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80800DDC: sltiu       $at, $t7, 0x11
    ctx->r1 = ctx->r15 < 0X11 ? 1 : 0;
    // 0x80800DE0: beq         $at, $zero, L_808010FC
    if (ctx->r1 == 0) {
        // 0x80800DE4: sw          $v0, 0x10($a3)
        MEM_W(0X10, ctx->r7) = ctx->r2;
            goto L_808010FC;
    }
    // 0x80800DE4: sw          $v0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r2;
    // 0x80800DE8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800DEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1852, 0X5008) << 16);
    // 0x80800DF0: addu        $at, $at, $t7
    gpr jr_addend_80800DF8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800DF4: lw          $t7, 0x5008($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1852, 0X5008));
    // 0x80800DF8: jr          $t7
    // 0x80800DFC: nop

    switch (jr_addend_80800DF8 >> 2) {
        case 0: goto L_80800E00; break;
        case 1: goto L_808010FC; break;
        case 2: goto L_80800F78; break;
        case 3: goto L_808010FC; break;
        case 4: goto L_80800EF4; break;
        case 5: goto L_80800F2C; break;
        case 6: goto L_808010FC; break;
        case 7: goto L_8080100C; break;
        case 8: goto L_808010FC; break;
        case 9: goto L_808010FC; break;
        case 10: goto L_80801064; break;
        case 11: goto L_80801078; break;
        case 12: goto L_80801094; break;
        case 13: goto L_808010E4; break;
        case 14: goto L_808010E4; break;
        case 15: goto L_808010F0; break;
        case 16: goto L_808010F0; break;
        default: switch_error(__func__, 0x80800DF8, 0x80805008);
    }
    // 0x80800DFC: nop

L_80800E00:
    // 0x80800E00: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800E04: addiu       $a3, $zero, 0x2A
    ctx->r7 = ADD32(0, 0X2A);
    // 0x80800E08: lbu         $t9, 0x7A($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X7A);
    // 0x80800E0C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80800E10: beq         $t0, $zero, L_80800E20
    if (ctx->r8 == 0) {
        // 0x80800E14: nop
    
            goto L_80800E20;
    }
    // 0x80800E14: nop

    // 0x80800E18: b           L_80800E20
    // 0x80800E1C: addiu       $a3, $zero, 0x29
    ctx->r7 = ADD32(0, 0X29);
        goto L_80800E20;
    // 0x80800E1C: addiu       $a3, $zero, 0x29
    ctx->r7 = ADD32(0, 0X29);
L_80800E20:
    // 0x80800E20: jal         0x80088178
    // 0x80800E24: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800E24: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x80800E28: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80800E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E30: addiu       $a0, $zero, 0x1D4
    ctx->r4 = ADD32(0, 0X1D4);
    // 0x80800E34: lbu         $t2, 0x7A($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X7A);
    // 0x80800E38: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80800E3C: beq         $t3, $zero, L_80800E94
    if (ctx->r11 == 0) {
        // 0x80800E40: nop
    
            goto L_80800E94;
    }
    // 0x80800E40: nop

    // 0x80800E44: jal         0x800DA9E4
    // 0x80800E48: addiu       $a0, $zero, 0x1D3
    ctx->r4 = ADD32(0, 0X1D3);
    func_800DA9E4(rdram, ctx);
        goto after_3;
    // 0x80800E48: addiu       $a0, $zero, 0x1D3
    ctx->r4 = ADD32(0, 0X1D3);
    after_3:
    // 0x80800E4C: bne         $v0, $zero, L_80800E8C
    if (ctx->r2 != 0) {
        // 0x80800E50: nop
    
            goto L_80800E8C;
    }
    // 0x80800E50: nop

    // 0x80800E54: jal         0x800DA298
    // 0x80800E58: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800E58: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    after_4:
    // 0x80800E5C: beq         $v0, $zero, L_80800E6C
    if (ctx->r2 == 0) {
        // 0x80800E60: nop
    
            goto L_80800E6C;
    }
    // 0x80800E60: nop

    // 0x80800E64: b           L_80800EDC
    // 0x80800E68: addiu       $a1, $zero, 0x129C
    ctx->r5 = ADD32(0, 0X129C);
        goto L_80800EDC;
    // 0x80800E68: addiu       $a1, $zero, 0x129C
    ctx->r5 = ADD32(0, 0X129C);
L_80800E6C:
    // 0x80800E6C: jal         0x800DA298
    // 0x80800E70: addiu       $a0, $zero, 0x1D4
    ctx->r4 = ADD32(0, 0X1D4);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800E70: addiu       $a0, $zero, 0x1D4
    ctx->r4 = ADD32(0, 0X1D4);
    after_5:
    // 0x80800E74: beq         $v0, $zero, L_80800E84
    if (ctx->r2 == 0) {
        // 0x80800E78: nop
    
            goto L_80800E84;
    }
    // 0x80800E78: nop

    // 0x80800E7C: b           L_80800EDC
    // 0x80800E80: addiu       $a1, $zero, 0x129A
    ctx->r5 = ADD32(0, 0X129A);
        goto L_80800EDC;
    // 0x80800E80: addiu       $a1, $zero, 0x129A
    ctx->r5 = ADD32(0, 0X129A);
L_80800E84:
    // 0x80800E84: b           L_80800EDC
    // 0x80800E88: addiu       $a1, $zero, 0x1296
    ctx->r5 = ADD32(0, 0X1296);
        goto L_80800EDC;
    // 0x80800E88: addiu       $a1, $zero, 0x1296
    ctx->r5 = ADD32(0, 0X1296);
L_80800E8C:
    // 0x80800E8C: b           L_80800EDC
    // 0x80800E90: addiu       $a1, $zero, 0x1298
    ctx->r5 = ADD32(0, 0X1298);
        goto L_80800EDC;
    // 0x80800E90: addiu       $a1, $zero, 0x1298
    ctx->r5 = ADD32(0, 0X1298);
L_80800E94:
    // 0x80800E94: jal         0x800DA9E4
    // 0x80800E98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_6;
    // 0x80800E98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800E9C: bne         $v0, $zero, L_80800EDC
    if (ctx->r2 != 0) {
        // 0x80800EA0: addiu       $a1, $zero, 0x1299
        ctx->r5 = ADD32(0, 0X1299);
            goto L_80800EDC;
    }
    // 0x80800EA0: addiu       $a1, $zero, 0x1299
    ctx->r5 = ADD32(0, 0X1299);
    // 0x80800EA4: jal         0x800DA298
    // 0x80800EA8: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800EA8: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    after_7:
    // 0x80800EAC: beq         $v0, $zero, L_80800EBC
    if (ctx->r2 == 0) {
        // 0x80800EB0: nop
    
            goto L_80800EBC;
    }
    // 0x80800EB0: nop

    // 0x80800EB4: b           L_80800EDC
    // 0x80800EB8: addiu       $a1, $zero, 0x129D
    ctx->r5 = ADD32(0, 0X129D);
        goto L_80800EDC;
    // 0x80800EB8: addiu       $a1, $zero, 0x129D
    ctx->r5 = ADD32(0, 0X129D);
L_80800EBC:
    // 0x80800EBC: jal         0x800DA298
    // 0x80800EC0: addiu       $a0, $zero, 0x1D3
    ctx->r4 = ADD32(0, 0X1D3);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800EC0: addiu       $a0, $zero, 0x1D3
    ctx->r4 = ADD32(0, 0X1D3);
    after_8:
    // 0x80800EC4: beq         $v0, $zero, L_80800ED4
    if (ctx->r2 == 0) {
        // 0x80800EC8: nop
    
            goto L_80800ED4;
    }
    // 0x80800EC8: nop

    // 0x80800ECC: b           L_80800EDC
    // 0x80800ED0: addiu       $a1, $zero, 0x129B
    ctx->r5 = ADD32(0, 0X129B);
        goto L_80800EDC;
    // 0x80800ED0: addiu       $a1, $zero, 0x129B
    ctx->r5 = ADD32(0, 0X129B);
L_80800ED4:
    // 0x80800ED4: b           L_80800EDC
    // 0x80800ED8: addiu       $a1, $zero, 0x1297
    ctx->r5 = ADD32(0, 0X1297);
        goto L_80800EDC;
    // 0x80800ED8: addiu       $a1, $zero, 0x1297
    ctx->r5 = ADD32(0, 0X1297);
L_80800EDC:
    // 0x80800EDC: beq         $a1, $zero, L_808010FC
    if (ctx->r5 == 0) {
        // 0x80800EE0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808010FC;
    }
    // 0x80800EE0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800EE4: jal         0x80800D20
    // 0x80800EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800D20_chdragonbrothers(rdram, ctx);
        goto after_9;
    // 0x80800EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80800EEC: b           L_80801100
    // 0x80800EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801100;
    // 0x80800EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800EF4:
    // 0x80800EF4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80800EF8: sb          $t4, 0x58($a3)
    MEM_B(0X58, ctx->r7) = ctx->r12;
    // 0x80800EFC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800F00: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800F04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F08: jal         0x80800B9C
    // 0x80800F0C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_80800B9C_chdragonbrothers(rdram, ctx);
        goto after_10;
    // 0x80800F0C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_10:
    // 0x80800F10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800F14: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800F18: addiu       $a2, $zero, 0x420
    ctx->r6 = ADD32(0, 0X420);
    // 0x80800F1C: jal         0x80800A80
    // 0x80800F20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800A80_chdragonbrothers(rdram, ctx);
        goto after_11;
    // 0x80800F20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x80800F24: b           L_80801100
    // 0x80800F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801100;
    // 0x80800F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F2C:
    // 0x80800F2C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800F30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800F34: addiu       $a3, $zero, 0x12A6
    ctx->r7 = ADD32(0, 0X12A6);
    // 0x80800F38: lbu         $t5, 0x7A($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X7A);
    // 0x80800F3C: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x80800F40: beq         $t6, $zero, L_80800F50
    if (ctx->r14 == 0) {
        // 0x80800F44: nop
    
            goto L_80800F50;
    }
    // 0x80800F44: nop

    // 0x80800F48: b           L_80800F50
    // 0x80800F4C: addiu       $a3, $zero, 0x12A5
    ctx->r7 = ADD32(0, 0X12A5);
        goto L_80800F50;
    // 0x80800F4C: addiu       $a3, $zero, 0x12A5
    ctx->r7 = ADD32(0, 0X12A5);
L_80800F50:
    // 0x80800F50: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x80800F54: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80800F58: jal         0x80800D20
    // 0x80800F5C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_80800D20_chdragonbrothers(rdram, ctx);
        goto after_12;
    // 0x80800F5C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_12:
    // 0x80800F60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800F64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800F68: jal         0x8080098C
    // 0x80800F6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8080098C_chdragonbrothers(rdram, ctx);
        goto after_13;
    // 0x80800F6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80800F70: b           L_80801100
    // 0x80800F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801100;
    // 0x80800F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800F78:
    // 0x80800F78: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800F7C: lbu         $t9, 0x7A($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X7A);
    // 0x80800F80: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80800F84: beq         $t0, $zero, L_80800FB4
    if (ctx->r8 == 0) {
        // 0x80800F88: nop
    
            goto L_80800FB4;
    }
    // 0x80800F88: nop

    // 0x80800F8C: jal         0x800DA298
    // 0x80800F90: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x80800F90: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    after_14:
    // 0x80800F94: beq         $v0, $zero, L_80800FAC
    if (ctx->r2 == 0) {
        // 0x80800F98: nop
    
            goto L_80800FAC;
    }
    // 0x80800F98: nop

    // 0x80800F9C: jal         0x800DA544
    // 0x80800FA0: addiu       $a0, $zero, 0x1D2
    ctx->r4 = ADD32(0, 0X1D2);
    func_800DA544(rdram, ctx);
        goto after_15;
    // 0x80800FA0: addiu       $a0, $zero, 0x1D2
    ctx->r4 = ADD32(0, 0X1D2);
    after_15:
    // 0x80800FA4: b           L_80800FD4
    // 0x80800FA8: addiu       $a3, $zero, 0x12A3
    ctx->r7 = ADD32(0, 0X12A3);
        goto L_80800FD4;
    // 0x80800FA8: addiu       $a3, $zero, 0x12A3
    ctx->r7 = ADD32(0, 0X12A3);
L_80800FAC:
    // 0x80800FAC: b           L_80800FD4
    // 0x80800FB0: addiu       $a3, $zero, 0x12A1
    ctx->r7 = ADD32(0, 0X12A1);
        goto L_80800FD4;
    // 0x80800FB0: addiu       $a3, $zero, 0x12A1
    ctx->r7 = ADD32(0, 0X12A1);
L_80800FB4:
    // 0x80800FB4: jal         0x800DA298
    // 0x80800FB8: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    func_800DA298(rdram, ctx);
        goto after_16;
    // 0x80800FB8: addiu       $a0, $zero, 0x1D5
    ctx->r4 = ADD32(0, 0X1D5);
    after_16:
    // 0x80800FBC: beq         $v0, $zero, L_80800FD4
    if (ctx->r2 == 0) {
        // 0x80800FC0: addiu       $a3, $zero, 0x12A2
        ctx->r7 = ADD32(0, 0X12A2);
            goto L_80800FD4;
    }
    // 0x80800FC0: addiu       $a3, $zero, 0x12A2
    ctx->r7 = ADD32(0, 0X12A2);
    // 0x80800FC4: jal         0x800DA524
    // 0x80800FC8: addiu       $a0, $zero, 0x1D2
    ctx->r4 = ADD32(0, 0X1D2);
    func_800DA524(rdram, ctx);
        goto after_17;
    // 0x80800FC8: addiu       $a0, $zero, 0x1D2
    ctx->r4 = ADD32(0, 0X1D2);
    after_17:
    // 0x80800FCC: b           L_80800FD4
    // 0x80800FD0: addiu       $a3, $zero, 0x12A4
    ctx->r7 = ADD32(0, 0X12A4);
        goto L_80800FD4;
    // 0x80800FD0: addiu       $a3, $zero, 0x12A4
    ctx->r7 = ADD32(0, 0X12A4);
L_80800FD4:
    // 0x80800FD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800FD8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800FDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800FE0: jal         0x8080098C
    // 0x80800FE4: sh          $a3, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r7;
    func_8080098C_chdragonbrothers(rdram, ctx);
        goto after_18;
    // 0x80800FE4: sh          $a3, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r7;
    after_18:
    // 0x80800FE8: lh          $a3, 0x18($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X18);
    // 0x80800FEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800FF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800FF4: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x80800FF8: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80800FFC: jal         0x80800D20
    // 0x80801000: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_80800D20_chdragonbrothers(rdram, ctx);
        goto after_19;
    // 0x80801000: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_19:
    // 0x80801004: b           L_80801100
    // 0x80801008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801100;
    // 0x80801008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080100C:
    // 0x8080100C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801010: jal         0x800FDC28
    // 0x80801014: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_800FDC28(rdram, ctx);
        goto after_20;
    // 0x80801014: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_20:
    // 0x80801018: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8080101C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80801020: jal         0x800D395C
    // 0x80801024: sb          $t2, 0x58($a3)
    MEM_B(0X58, ctx->r7) = ctx->r10;
    func_800D395C(rdram, ctx);
        goto after_21;
    // 0x80801024: sb          $t2, 0x58($a3)
    MEM_B(0X58, ctx->r7) = ctx->r10;
    after_21:
    // 0x80801028: beq         $v0, $zero, L_8080104C
    if (ctx->r2 == 0) {
        // 0x8080102C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8080104C;
    }
    // 0x8080102C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801030: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801034: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80801038: addiu       $a2, $zero, 0x420
    ctx->r6 = ADD32(0, 0X420);
    // 0x8080103C: jal         0x80800A80
    // 0x80801040: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800A80_chdragonbrothers(rdram, ctx);
        goto after_22;
    // 0x80801040: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_22:
    // 0x80801044: b           L_80801100
    // 0x80801048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801100;
    // 0x80801048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080104C:
    // 0x8080104C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80801050: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    // 0x80801054: jal         0x80800A80
    // 0x80801058: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800A80_chdragonbrothers(rdram, ctx);
        goto after_23;
    // 0x80801058: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_23:
    // 0x8080105C: b           L_80801100
    // 0x80801060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801100;
    // 0x80801060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801064:
    // 0x80801064: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80801068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080106C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80801070: b           L_808010FC
    // 0x80801074: swc1        $f4, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f4.u32l;
        goto L_808010FC;
    // 0x80801074: swc1        $f4, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f4.u32l;
L_80801078:
    // 0x80801078: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080107C: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x80801080: addiu       $a2, $zero, 0x430
    ctx->r6 = ADD32(0, 0X430);
    // 0x80801084: jal         0x80800A80
    // 0x80801088: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80800A80_chdragonbrothers(rdram, ctx);
        goto after_24;
    // 0x80801088: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_24:
    // 0x8080108C: b           L_80801100
    // 0x80801090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801100;
    // 0x80801090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801094:
    // 0x80801094: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80801098: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080109C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808010A0: jal         0x80800B9C
    // 0x808010A4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_80800B9C_chdragonbrothers(rdram, ctx);
        goto after_25;
    // 0x808010A4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_25:
    // 0x808010A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808010AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808010B0: addiu       $a3, $zero, 0x12AF
    ctx->r7 = ADD32(0, 0X12AF);
    // 0x808010B4: lbu         $t4, 0x7A($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X7A);
    // 0x808010B8: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x808010BC: beq         $t5, $zero, L_808010CC
    if (ctx->r13 == 0) {
        // 0x808010C0: nop
    
            goto L_808010CC;
    }
    // 0x808010C0: nop

    // 0x808010C4: b           L_808010CC
    // 0x808010C8: addiu       $a3, $zero, 0x12AE
    ctx->r7 = ADD32(0, 0X12AE);
        goto L_808010CC;
    // 0x808010C8: addiu       $a3, $zero, 0x12AE
    ctx->r7 = ADD32(0, 0X12AE);
L_808010CC:
    // 0x808010CC: sll         $a1, $a3, 16
    ctx->r5 = S32(ctx->r7 << 16);
    // 0x808010D0: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x808010D4: jal         0x80800D20
    // 0x808010D8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_80800D20_chdragonbrothers(rdram, ctx);
        goto after_26;
    // 0x808010D8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_26:
    // 0x808010DC: b           L_80801100
    // 0x808010E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801100;
    // 0x808010E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808010E4:
    // 0x808010E4: lbu         $t7, 0x5B($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X5B);
    // 0x808010E8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x808010EC: sb          $t8, 0x5B($a3)
    MEM_B(0X5B, ctx->r7) = ctx->r24;
L_808010F0:
    // 0x808010F0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808010F4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x808010F8: swc1        $f6, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f6.u32l;
L_808010FC:
    // 0x808010FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801100:
    // 0x80801100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801104: jr          $ra
    // 0x80801108: nop

    return;
    // 0x80801108: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_55(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802DCC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80802DD0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2F20) << 16);
    // 0x80802DD4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80802DD8: jr          $ra
    // 0x80802DDC: lw          $v0, 0x2F20($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2F20));
    return;
    // 0x80802DDC: lw          $v0, 0x2F20($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2F20));
;}
RECOMP_FUNC void func_80800158_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800158: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080015C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800160: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800164: jal         0x80100094
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080016C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800170: addiu       $a0, $zero, 0xA37
    ctx->r4 = ADD32(0, 0XA37);
    // 0x80800174: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800178: jal         0x800DA7A8
    // 0x8080017C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_1;
    // 0x8080017C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x80800180: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80800184: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800188: sb          $t6, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r14;
    // 0x8080018C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800194: jr          $ra
    // 0x80800198: nop

    return;
    // 0x80800198: nop

;}
RECOMP_FUNC void _ncbadie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089280: syscall     769
    recomp_syscall_handler(rdram, ctx, 0x80089280);
    return;
    // 0x80089284: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _ncpodfixpos_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089690: syscall     786
    recomp_syscall_handler(rdram, ctx, 0x80089690);
    return;
    // 0x80089694: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bsbtrot_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801798: jal         0x8009E704
    // 0x8080179C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bs_getNextState(rdram, ctx);
        goto after_0;
    // 0x8080179C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808017A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808017A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808017A8: jal         0x8009CA70
    // 0x808017AC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x808017AC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_1:
    // 0x808017B0: beq         $v0, $zero, L_808017C0
    if (ctx->r2 == 0) {
        // 0x808017B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808017C0;
    }
    // 0x808017B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808017B8: jal         0x800931AC
    // 0x808017BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800931AC(rdram, ctx);
        goto after_2;
    // 0x808017BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_808017C0:
    // 0x808017C0: jal         0x8080061C
    // 0x808017C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080061C_bsbtrot(rdram, ctx);
        goto after_3;
    // 0x808017C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808017C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808017CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808017D0: jr          $ra
    // 0x808017D4: nop

    return;
    // 0x808017D4: nop

;}
RECOMP_FUNC void _bskazjump_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800834A0: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x800834A0);
    return;
    // 0x800834A4: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800DD56C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD56C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800DD570: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800DD574: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800DD578: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800DD57C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800DD580: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800DD584: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800DD588: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800DD58C: lh          $v0, 0xA($a1)
    ctx->r2 = MEM_H(ctx->r5, 0XA);
    // 0x800DD590: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DD594: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x800DD598: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800DD59C: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800DD5A0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800DD5A4: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800DD5A8: beq         $v0, $zero, L_800DD638
    if (ctx->r2 == 0) {
        // 0x800DD5AC: lw          $v1, -0x37B0($v1)
        ctx->r3 = MEM_W(ctx->r3, -0X37B0);
            goto L_800DD638;
    }
    // 0x800DD5AC: lw          $v1, -0x37B0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X37B0);
    // 0x800DD5B0: beql        $v1, $zero, L_800DD63C
    if (ctx->r3 == 0) {
        // 0x800DD5B4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800DD63C;
    }
    goto skip_0;
    // 0x800DD5B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800DD5B8: blezl       $v1, L_800DD5F0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800DD5BC: lh          $t2, 0x8($s3)
        ctx->r10 = MEM_H(ctx->r19, 0X8);
            goto L_800DD5F0;
    }
    goto skip_1;
    // 0x800DD5BC: lh          $t2, 0x8($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X8);
    skip_1:
    // 0x800DD5C0: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x800DD5C4: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x800DD5C8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800DD5CC: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800DD5D0: bne         $at, $zero, L_800DD638
    if (ctx->r1 != 0) {
        // 0x800DD5D4: addu        $t0, $a1, $t9
        ctx->r8 = ADD32(ctx->r5, ctx->r25);
            goto L_800DD638;
    }
    // 0x800DD5D4: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x800DD5D8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x800DD5DC: jal         0x800DE2A4
    // 0x800DD5E0: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    func_800DE2A4(rdram, ctx);
        goto after_0;
    // 0x800DD5E0: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    after_0:
    // 0x800DD5E4: b           L_800DD63C
    // 0x800DD5E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800DD63C;
    // 0x800DD5E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD5EC: lh          $t2, 0x8($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X8);
L_800DD5F0:
    // 0x800DD5F0: negu        $s1, $v1
    ctx->r17 = SUB32(0, ctx->r3);
    // 0x800DD5F4: addiu       $s0, $s3, 0xC
    ctx->r16 = ADD32(ctx->r19, 0XC);
    // 0x800DD5F8: blez        $t2, L_800DD638
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800DD5FC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800DD638;
    }
    // 0x800DD5FC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_800DD600:
    // 0x800DD600: andi        $t3, $s1, 0x1
    ctx->r11 = ctx->r17 & 0X1;
    // 0x800DD604: beql        $t3, $zero, L_800DD620
    if (ctx->r11 == 0) {
        // 0x800DD608: lh          $t6, 0x8($s4)
        ctx->r14 = MEM_H(ctx->r20, 0X8);
            goto L_800DD620;
    }
    goto skip_2;
    // 0x800DD608: lh          $t6, 0x8($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X8);
    skip_2:
    // 0x800DD60C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x800DD610: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800DD614: jal         0x800DE2A4
    // 0x800DD618: addu        $a1, $s3, $t4
    ctx->r5 = ADD32(ctx->r19, ctx->r12);
    func_800DE2A4(rdram, ctx);
        goto after_1;
    // 0x800DD618: addu        $a1, $s3, $t4
    ctx->r5 = ADD32(ctx->r19, ctx->r12);
    after_1:
    // 0x800DD61C: lh          $t6, 0x8($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X8);
L_800DD620:
    // 0x800DD620: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800DD624: sra         $t5, $s1, 1
    ctx->r13 = S32(SIGNED(ctx->r17) >> 1);
    // 0x800DD628: slt         $at, $s2, $t6
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800DD62C: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x800DD630: bne         $at, $zero, L_800DD600
    if (ctx->r1 != 0) {
        // 0x800DD634: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800DD600;
    }
    // 0x800DD634: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800DD638:
    // 0x800DD638: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800DD63C:
    // 0x800DD63C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800DD640: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800DD644: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD648: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800DD64C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800DD650: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800DD654: jr          $ra
    // 0x800DD658: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800DD658: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800DC354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DC354: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800DC358: lw          $t6, -0x3808($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3808);
    // 0x800DC35C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC360: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DC364: lw          $t7, -0x3804($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3804);
    // 0x800DC368: sw          $t6, -0x3810($at)
    MEM_W(-0X3810, ctx->r1) = ctx->r14;
    // 0x800DC36C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DC370: jr          $ra
    // 0x800DC374: sw          $t7, -0x380C($at)
    MEM_W(-0X380C, ctx->r1) = ctx->r15;
    return;
    // 0x800DC374: sw          $t7, -0x380C($at)
    MEM_W(-0X380C, ctx->r1) = ctx->r15;
    // 0x800DC378: nop

    // 0x800DC37C: nop

;}
RECOMP_FUNC void func_800DF574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF574: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF578: jr          $ra
    // 0x800DF57C: sh          $a0, -0x35C8($at)
    MEM_H(-0X35C8, ctx->r1) = ctx->r4;
    return;
    // 0x800DF57C: sh          $a0, -0x35C8($at)
    MEM_H(-0X35C8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_801088A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801088A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801088AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801088B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801088B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801088B8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801088BC: lbu         $t6, 0x96($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X96);
    // 0x801088C0: lbu         $t2, 0x74($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X74);
    // 0x801088C4: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x801088C8: sb          $t7, 0x96($a0)
    MEM_B(0X96, ctx->r4) = ctx->r15;
    // 0x801088CC: lhu         $v0, 0x96($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X96);
    // 0x801088D0: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x801088D4: andi        $t3, $t2, 0xFFFD
    ctx->r11 = ctx->r10 & 0XFFFD;
    // 0x801088D8: srl         $t9, $v0, 15
    ctx->r25 = S32(U32(ctx->r2) >> 15);
    // 0x801088DC: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x801088E0: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x801088E4: lbu         $t0, 0x7B($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X7B);
    // 0x801088E8: sll         $v1, $t9, 6
    ctx->r3 = S32(ctx->r25 << 6);
    // 0x801088EC: andi        $t5, $v1, 0x40
    ctx->r13 = ctx->r3 & 0X40;
    // 0x801088F0: andi        $t9, $v1, 0xC0
    ctx->r25 = ctx->r3 & 0XC0;
    // 0x801088F4: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x801088F8: andi        $t7, $t6, 0xFFBF
    ctx->r15 = ctx->r14 & 0XFFBF;
    // 0x801088FC: andi        $t2, $t0, 0xFF3F
    ctx->r10 = ctx->r8 & 0XFF3F;
    // 0x80108900: or          $t1, $t9, $t2
    ctx->r9 = ctx->r25 | ctx->r10;
    // 0x80108904: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80108908: sb          $t8, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r24;
    // 0x8010890C: sb          $t1, 0x7B($a0)
    MEM_B(0X7B, ctx->r4) = ctx->r9;
    // 0x80108910: sb          $t4, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r12;
    // 0x80108914: jal         0x800BF8E4
    // 0x80108918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800BF8E4(rdram, ctx);
        goto after_0;
    // 0x80108918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010891C: beq         $v0, $zero, L_80108934
    if (ctx->r2 == 0) {
        // 0x80108920: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80108934;
    }
    // 0x80108920: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80108924: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80108928: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8010892C: jal         0x80108658
    // 0x80108930: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_80108658(rdram, ctx);
        goto after_1;
    // 0x80108930: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
L_80108934:
    // 0x80108934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108938: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010893C: jr          $ra
    // 0x80108940: nop

    return;
    // 0x80108940: nop

;}
RECOMP_FUNC void _bsledge_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800837B8: syscall     74
    recomp_syscall_handler(rdram, ctx, 0x800837B8);
    return;
    // 0x800837BC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void badust_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080062C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XC84) << 16);
    // 0x80800630: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80800634: lwc1        $f4, 0xC84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XC84));
    // 0x80800638: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080063C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800640: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80800644: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800648: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080064C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800650: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80800654: jal         0x8009C128
    // 0x80800658: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800658: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8080065C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80800660: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800664: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800668: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080066C: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800670: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800674: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800678: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8080067C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80800680: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80800684: jal         0x800EFCD8
    // 0x80800688: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    func_800EFCD8(rdram, ctx);
        goto after_1;
    // 0x80800688: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8080068C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XC88) << 16);
    // 0x80800690: lwc1        $f6, 0xC88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XC88));
    // 0x80800694: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(500, 0XC8C) << 16);
    // 0x80800698: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8080069C: lwc1        $f8, 0xC8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(500, 0XC8C));
    // 0x808006A0: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x808006A4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x808006A8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808006AC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x808006B0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808006B4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808006B8: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x808006BC: jal         0x80800260
    // 0x808006C0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    badust_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808006C0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x808006C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808006CC: jr          $ra
    // 0x808006D0: nop

    return;
    // 0x808006D0: nop

;}
RECOMP_FUNC void func_808001F0_glgamedata(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001F8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x808001FC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2730, 0X4F4) << 16);
    // 0x80800200: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800204: addu        $a2, $v1, $a0
    ctx->r6 = ADD32(ctx->r3, ctx->r4);
    // 0x80800208: lbu         $t0, 0x0($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X0);
    // 0x8080020C: lbu         $t6, 0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1);
    // 0x80800210: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80800214: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80800218: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x8080021C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800220: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80800224: lw          $v0, 0x4F4($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(2730, 0X4F4));
    // 0x80800228: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080022C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80800230: beq         $v0, $zero, L_80800250
    if (ctx->r2 == 0) {
        // 0x80800234: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80800250;
    }
    // 0x80800234: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80800238: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080023C: jalr        $v0
    // 0x80800240: sb          $t0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r8;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80800240: sb          $t0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r8;
    after_0:
    // 0x80800244: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800248: lbu         $t0, 0x1F($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X1F);
    // 0x8080024C: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
L_80800250:
    // 0x80800250: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800254: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80800258: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8080025C: addiu       $t1, $t9, 0x2
    ctx->r9 = ADD32(ctx->r25, 0X2);
    // 0x80800260: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80800264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800268: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800B10: jal         0x80800A18
    // 0x80800B14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800A18_bstaxi(rdram, ctx);
        goto after_0;
    // 0x80800B14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800B18: jal         0x808000D4
    // 0x80800B1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstaxi_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800B1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B28: jr          $ra
    // 0x80800B2C: nop

    return;
    // 0x80800B2C: nop

;}
RECOMP_FUNC void func_800984CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800984CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800984D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800984D4: lw          $a0, 0xAC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XAC);
    // 0x800984D8: jal         0x800EE7F8
    // 0x800984DC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800984DC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x800984E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800984E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800984E8: jr          $ra
    // 0x800984EC: nop

    return;
    // 0x800984EC: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083E28: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083E28);
    return;
    // 0x80083E2C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void gcnewoption_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D1C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800D20: jr          $ra
    // 0x80800D24: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x80800D24: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8009BD44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BD44: lw          $t6, 0xD4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD4);
    // 0x8009BD48: jr          $ra
    // 0x8009BD4C: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    return;
    // 0x8009BD4C: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
;}
RECOMP_FUNC void chworlddoors_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800928: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2476, 0XA04) << 16);
    // 0x8080092C: jr          $ra
    // 0x80800930: addiu       $v0, $v0, 0xA04
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2476, 0XA04));
    return;
    // 0x80800930: addiu       $v0, $v0, 0xA04
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2476, 0XA04));
    // 0x80800934: nop

    // 0x80800938: nop

    // 0x8080093C: nop

;}
RECOMP_FUNC void func_80800918_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800918: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080091C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800920: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800924: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800928: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8080092C: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800930: jal         0x800EE88C
    // 0x80800934: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x80800934: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800938: jal         0x800EEF94
    // 0x8080093C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EEF94(rdram, ctx);
        goto after_1;
    // 0x8080093C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800940: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80800944: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800948: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8080094C: lh          $t6, 0x5C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X5C);
    // 0x80800950: addiu       $a0, $v0, 0x3C
    ctx->r4 = ADD32(ctx->r2, 0X3C);
    // 0x80800954: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800958: nop

    // 0x8080095C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800960: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800964: jal         0x80088FC0
    // 0x80800968: nop

    _mlwave_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800968: nop

    after_2:
    // 0x8080096C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800970: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800974: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80800978: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8080097C: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80800980: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x80800984: sh          $t3, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r11;
    // 0x80800988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080098C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800990: jr          $ra
    // 0x80800994: nop

    return;
    // 0x80800994: nop

;}
RECOMP_FUNC void func_800E3220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3220: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800E3224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E3228: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E322C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E3230: jal         0x800E1DF4
    // 0x800E3234: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800E1DF4(rdram, ctx);
        goto after_0;
    // 0x800E3234: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E3238: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E323C: lui         $t7, 0xDB06
    ctx->r15 = S32(0XDB06 << 16);
    // 0x800E3240: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x800E3244: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800E3248: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800E324C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800E3250: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800E3254: jal         0x800AF5D8
    // 0x800E3258: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800AF5D8(rdram, ctx);
        goto after_1;
    // 0x800E3258: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x800E325C: jal         0x8002E330
    // 0x800E3260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800E3260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800E3264: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800E3268: lui         $t0, 0xDB06
    ctx->r8 = S32(0XDB06 << 16);
    // 0x800E326C: ori         $t0, $t0, 0x4
    ctx->r8 = ctx->r8 | 0X4;
    // 0x800E3270: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x800E3274: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800E3278: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800E327C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800E3280: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800E3284: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800E3288: jal         0x800AF5E4
    // 0x800E328C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_800AF5E4(rdram, ctx);
        goto after_3;
    // 0x800E328C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x800E3290: jal         0x8002E330
    // 0x800E3294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800E3294: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800E3298: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800E329C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E32A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E32A4: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x800E32A8: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800E32AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800E32B0: jal         0x800E42F0
    // 0x800E32B4: sw          $t2, -0x2B0C($at)
    MEM_W(-0X2B0C, ctx->r1) = ctx->r10;
    func_800E42F0(rdram, ctx);
        goto after_5;
    // 0x800E32B4: sw          $t2, -0x2B0C($at)
    MEM_W(-0X2B0C, ctx->r1) = ctx->r10;
    after_5:
    // 0x800E32B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E32BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E32C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800E32C4: jr          $ra
    // 0x800E32C8: nop

    return;
    // 0x800E32C8: nop

;}
RECOMP_FUNC void func_800A5298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5298: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A529C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A52A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A52A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A52A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800A52AC: jal         0x800F54E4
    // 0x800A52B0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800A52B0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A52B4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800A52B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A52BC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800A52C0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800A52C4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800A52C8: jal         0x800878E8
    // 0x800A52CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _plcamera_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x800A52CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800A52D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A52D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A52D8: jr          $ra
    // 0x800A52DC: nop

    return;
    // 0x800A52DC: nop

;}
RECOMP_FUNC void basub_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808009BC: lw          $t6, 0x130($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X130);
    // 0x808009C0: jr          $ra
    // 0x808009C4: swc1        $f12, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x808009C4: swc1        $f12, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void _chlagoonufoint_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085A58: syscall     190
    recomp_syscall_handler(rdram, ctx, 0x80085A58);
    return;
    // 0x80085A5C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
