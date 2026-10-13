#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800900A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800900A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800900AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800900B0: jal         0x800F54E4
    // 0x800900B4: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800900B4: nop

    after_0:
    // 0x800900B8: jal         0x800F6018
    // 0x800900BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6018(rdram, ctx);
        goto after_1;
    // 0x800900BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800900C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800900C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800900C8: jr          $ra
    // 0x800900CC: nop

    return;
    // 0x800900CC: nop

;}
RECOMP_FUNC void func_800D5210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5210: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800D5214: bne         $a0, $at, L_800D5220
    if (ctx->r4 != ctx->r1) {
        // 0x800D5218: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800D5220;
    }
    // 0x800D5218: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800D521C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800D5220:
    // 0x800D5220: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800D5224: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800D5228: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800D522C: jr          $ra
    // 0x800D5230: lbu         $v0, -0x49C0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X49C0);
    return;
    // 0x800D5230: lbu         $v0, -0x49C0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X49C0);
;}
RECOMP_FUNC void _chclinker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873B0: syscall     560
    recomp_syscall_handler(rdram, ctx, 0x800873B0);
    return;
    // 0x800873B4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsdie_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FA0: syscall     37
    recomp_syscall_handler(rdram, ctx, 0x80082FA0);
    return;
    // 0x80082FA4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800754_chhoney(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800754: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800758: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8080075C: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80800760: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80800764: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80800768: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8080076C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80800770: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80800774: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80800778: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8080077C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800780: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800784: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x80800788: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8080078C: lw          $v0, 0x24($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X24);
    // 0x80800790: srl         $t7, $v0, 22
    ctx->r15 = S32(U32(ctx->r2) >> 22);
    // 0x80800794: beq         $t7, $at, L_80800840
    if (ctx->r15 == ctx->r1) {
        // 0x80800798: addiu       $at, $zero, 0x22B
        ctx->r1 = ADD32(0, 0X22B);
            goto L_80800840;
    }
    // 0x80800798: addiu       $at, $zero, 0x22B
    ctx->r1 = ADD32(0, 0X22B);
    // 0x8080079C: beq         $t7, $at, L_808007AC
    if (ctx->r15 == ctx->r1) {
        // 0x808007A0: addiu       $at, $zero, 0x22C
        ctx->r1 = ADD32(0, 0X22C);
            goto L_808007AC;
    }
    // 0x808007A0: addiu       $at, $zero, 0x22C
    ctx->r1 = ADD32(0, 0X22C);
    // 0x808007A4: bnel        $t7, $at, L_80800844
    if (ctx->r15 != ctx->r1) {
        // 0x808007A8: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80800844;
    }
    goto skip_0;
    // 0x808007A8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_808007AC:
    // 0x808007AC: lw          $t8, 0x7C($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X7C);
    // 0x808007B0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808007B4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x808007B8: sll         $t0, $t8, 19
    ctx->r8 = S32(ctx->r24 << 19);
    // 0x808007BC: bgez        $t0, L_80800840
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808007C0: addiu       $s2, $zero, 0x4
        ctx->r18 = ADD32(0, 0X4);
            goto L_80800840;
    }
    // 0x808007C0: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x808007C4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808007C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1668, 0XFE8) << 16);
    // 0x808007CC: lwc1        $f26, 0xFE8($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1668, 0XFE8));
    // 0x808007D0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808007D4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808007D8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808007DC: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
L_808007E0:
    // 0x808007E0: jal         0x800DC298
    // 0x808007E4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    func_800DC298(rdram, ctx);
        goto after_0;
    // 0x808007E4: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    after_0:
    // 0x808007E8: beq         $v0, $zero, L_80800834
    if (ctx->r2 == 0) {
        // 0x808007EC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80800834;
    }
    // 0x808007EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808007F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007F4: jal         0x8008A0D0
    // 0x808007F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    _subaddieskeleton_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808007F8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x808007FC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800800: jal         0x800DC178
    // 0x80800804: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800804: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_2:
    // 0x80800808: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8080080C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80800810: jal         0x800DC178
    // 0x80800814: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800814: mov.s       $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    ctx->f14.fl = ctx->f24.fl;
    after_3:
    // 0x80800818: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080081C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800820: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80800824: jal         0x800EF214
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF214(rdram, ctx);
        goto after_4;
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080082C: jal         0x80088AA8
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _fxtwinkle_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_80800834:
    // 0x80800834: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800838: bne         $s1, $s2, L_808007E0
    if (ctx->r17 != ctx->r18) {
        // 0x8080083C: nop
    
            goto L_808007E0;
    }
    // 0x8080083C: nop

L_80800840:
    // 0x80800840: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80800844:
    // 0x80800844: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80800848: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8080084C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80800850: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80800854: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80800858: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8080085C: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80800860: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x80800864: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x80800868: jr          $ra
    // 0x8080086C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8080086C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80800D5C_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D5C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800D60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800D64: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800D68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800D70: bne         $a1, $at, L_80800DD0
    if (ctx->r5 != ctx->r1) {
        // 0x80800D74: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800DD0;
    }
    // 0x80800D74: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800D78: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1012, 0X1100) << 16);
    // 0x80800D7C: addiu       $t6, $t6, 0x1100
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1012, 0X1100));
    // 0x80800D80: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800D84: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80800D88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800D8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800D90: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800D94: jal         0x800BBCB8
    // 0x80800D98: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800D98: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    after_0:
    // 0x80800D9C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1012, 0X1134) << 16);
    // 0x80800DA0: addiu       $a2, $a2, 0x1134
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1012, 0X1134));
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DA8: jal         0x80089D18
    // 0x80800DAC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800DAC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800DB0: jal         0x80106790
    // 0x80800DB4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800DB4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x80800DB8: jal         0x8010A590
    // 0x80800DBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8010A590(rdram, ctx);
        goto after_3;
    // 0x80800DBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800DC0: jal         0x800FFAB0
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_4;
    // 0x80800DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800DC8: b           L_80800DD4
    // 0x80800DCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800DD4;
    // 0x80800DCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DD0:
    // 0x80800DD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DD4:
    // 0x80800DD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800DD8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800DDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800DE0: jr          $ra
    // 0x80800DE4: nop

    return;
    // 0x80800DE4: nop

;}
RECOMP_FUNC void _cosectionstor_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087840: syscall     634
    recomp_syscall_handler(rdram, ctx, 0x80087840);
    return;
    // 0x80087844: xori        $t0, $zero, 0x8
    ctx->r8 = 0 ^ 0X8;
;}
RECOMP_FUNC void _babee_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084550: syscall     114
    recomp_syscall_handler(rdram, ctx, 0x80084550);
    return;
    // 0x80084554: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080037C_sumole(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080037C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800384: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800388: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080038C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800390: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800394: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x80800398: addiu       $a2, $zero, 0x800
    ctx->r6 = ADD32(0, 0X800);
    // 0x8080039C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808003A0: sll         $t7, $v0, 20
    ctx->r15 = S32(ctx->r2 << 20);
    // 0x808003A4: srl         $t8, $t7, 29
    ctx->r24 = S32(U32(ctx->r15) >> 29);
    // 0x808003A8: beq         $t8, $zero, L_808003CC
    if (ctx->r24 == 0) {
        // 0x808003AC: lw          $t9, 0x18($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18);
            goto L_808003CC;
    }
    // 0x808003AC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x808003B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003B4: beq         $t8, $at, L_808003E8
    if (ctx->r24 == ctx->r1) {
        // 0x808003B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808003E8;
    }
    // 0x808003B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003BC: beql        $t8, $at, L_808003D8
    if (ctx->r24 == ctx->r1) {
        // 0x808003C0: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_808003D8;
    }
    goto skip_0;
    // 0x808003C0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x808003C4: b           L_808003FC
    // 0x808003C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808003FC;
    // 0x808003C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003CC:
    // 0x808003CC: jal         0x800856B0
    // 0x808003D0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808003D0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_0:
    // 0x808003D4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_808003D8:
    // 0x808003D8: lbu         $t1, 0x7A($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X7A);
    // 0x808003DC: andi        $t2, $t1, 0xFFF1
    ctx->r10 = ctx->r9 & 0XFFF1;
    // 0x808003E0: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x808003E4: sb          $t3, 0x7A($t0)
    MEM_B(0X7A, ctx->r8) = ctx->r11;
L_808003E8:
    // 0x808003E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808003EC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808003F0: jal         0x800856D0
    // 0x808003F4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    _capod_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x808003F4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808003F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808003FC:
    // 0x808003FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800400: jr          $ra
    // 0x80800404: nop

    return;
    // 0x80800404: nop

;}
RECOMP_FUNC void func_80800E8C_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800E98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800E9C: jal         0x80106790
    // 0x80800EA0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800EA0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80800EA4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800EA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800EAC: jal         0x80800D14
    // 0x80800EB0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80800D14_chclockworkmouse(rdram, ctx);
        goto after_1;
    // 0x80800EB0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800EB4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EB8: jal         0x808022E4
    // 0x80800EBC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_808022E4_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x80800EBC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800EC8: jr          $ra
    // 0x80800ECC: nop

    return;
    // 0x80800ECC: nop

;}
RECOMP_FUNC void func_80802C30_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802C34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802C38: lw          $t6, 0x158($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X158);
    // 0x80802C3C: bne         $t6, $zero, L_80802C54
    if (ctx->r14 != 0) {
        // 0x80802C40: nop
    
            goto L_80802C54;
    }
    // 0x80802C40: nop

    // 0x80802C44: jal         0x80094510
    // 0x80802C48: nop

    func_80094510(rdram, ctx);
        goto after_0;
    // 0x80802C48: nop

    after_0:
    // 0x80802C4C: b           L_80802C60
    // 0x80802C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802C60;
    // 0x80802C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802C54:
    // 0x80802C54: jal         0x80085528
    // 0x80802C58: nop

    _badeathmatch_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80802C58: nop

    after_1:
    // 0x80802C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802C60:
    // 0x80802C60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802C64: jr          $ra
    // 0x80802C68: nop

    return;
    // 0x80802C68: nop

;}
RECOMP_FUNC void bskazfly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801108: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080110C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(236, 0X1C58) << 16);
    // 0x80801110: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801114: jr          $ra
    // 0x80801118: lw          $v0, 0x1C58($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C58));
    return;
    // 0x80801118: lw          $v0, 0x1C58($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(236, 0X1C58));
;}
RECOMP_FUNC void _bsbshock_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B18: syscall     27
    recomp_syscall_handler(rdram, ctx, 0x80082B18);
    return;
    // 0x80082B1C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chhellterskelter_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(964, 0X858) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x858
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(964, 0X858));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x858
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(964, 0X858));
;}
RECOMP_FUNC void func_80801A1C_bsbfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801A20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801A24: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x80801A28: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80801A2C: jal         0x80084C50
    // 0x80801A30: addiu       $a3, $a0, 0x15C
    ctx->r7 = ADD32(ctx->r4, 0X15C);
    _bafly_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x80801A30: addiu       $a3, $a0, 0x15C
    ctx->r7 = ADD32(ctx->r4, 0X15C);
    after_0:
    // 0x80801A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801A38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A3C: jr          $ra
    // 0x80801A40: nop

    return;
    // 0x80801A40: nop

;}
RECOMP_FUNC void func_80800604_chstatuebossbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800604: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800608: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080060C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800610: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800614: jal         0x800EC398
    // 0x80800618: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EC398(rdram, ctx);
        goto after_0;
    // 0x80800618: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x8080061C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1424, 0X864) << 16);
    // 0x80800620: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800624: addiu       $t6, $t6, 0x864
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1424, 0X864));
    // 0x80800628: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080062C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800630: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800634: jal         0x800BBCB8
    // 0x80800638: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80800638: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x8080063C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800640: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800644: jr          $ra
    // 0x80800648: nop

    return;
    // 0x80800648: nop

;}
RECOMP_FUNC void func_8009D658(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D658: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009D65C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D660: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009D664: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009D668: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009D66C: lbu         $t7, 0x1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X1);
    // 0x8009D670: bnel        $t7, $zero, L_8009D6F4
    if (ctx->r15 != 0) {
        // 0x8009D674: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8009D6F4;
    }
    goto skip_0;
    // 0x8009D674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8009D678: jal         0x800C2E04
    // 0x8009D67C: nop

    func_800C2E04(rdram, ctx);
        goto after_0;
    // 0x8009D67C: nop

    after_0:
    // 0x8009D680: lw          $t8, 0x104($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X104);
    // 0x8009D684: addiu       $a1, $zero, 0x410
    ctx->r5 = ADD32(0, 0X410);
    // 0x8009D688: sb          $v0, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r2;
    // 0x8009D68C: lw          $t9, 0x104($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X104);
    // 0x8009D690: jal         0x800C301C
    // 0x8009D694: lbu         $a0, 0x1($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X1);
    func_800C301C(rdram, ctx);
        goto after_1;
    // 0x8009D694: lbu         $a0, 0x1($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X1);
    after_1:
    // 0x8009D698: lw          $t0, 0x104($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X104);
    // 0x8009D69C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8009D6A0: addiu       $a1, $a1, -0x2C08
    ctx->r5 = ADD32(ctx->r5, -0X2C08);
    // 0x8009D6A4: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    // 0x8009D6A8: jal         0x800C3394
    // 0x8009D6AC: lbu         $a0, 0x1($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X1);
    func_800C3394(rdram, ctx);
        goto after_2;
    // 0x8009D6AC: lbu         $a0, 0x1($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X1);
    after_2:
    // 0x8009D6B0: lw          $t1, 0x104($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X104);
    // 0x8009D6B4: addiu       $a1, $zero, 0x6D60
    ctx->r5 = ADD32(0, 0X6D60);
    // 0x8009D6B8: jal         0x800C3058
    // 0x8009D6BC: lbu         $a0, 0x1($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X1);
    func_800C3058(rdram, ctx);
        goto after_3;
    // 0x8009D6BC: lbu         $a0, 0x1($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X1);
    after_3:
    // 0x8009D6C0: lw          $t2, 0x104($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X104);
    // 0x8009D6C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8009D6C8: jal         0x800C330C
    // 0x8009D6CC: lbu         $a0, 0x1($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X1);
    func_800C330C(rdram, ctx);
        goto after_4;
    // 0x8009D6CC: lbu         $a0, 0x1($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X1);
    after_4:
    // 0x8009D6D0: lw          $t3, 0x104($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X104);
    // 0x8009D6D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D6D8: jal         0x800C3418
    // 0x8009D6DC: lbu         $a0, 0x1($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X1);
    func_800C3418(rdram, ctx);
        goto after_5;
    // 0x8009D6DC: lbu         $a0, 0x1($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X1);
    after_5:
    // 0x8009D6E0: lw          $t4, 0x104($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X104);
    // 0x8009D6E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D6E8: jal         0x800C431C
    // 0x8009D6EC: lbu         $a0, 0x1($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X1);
    func_800C431C(rdram, ctx);
        goto after_6;
    // 0x8009D6EC: lbu         $a0, 0x1($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X1);
    after_6:
    // 0x8009D6F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8009D6F4:
    // 0x8009D6F4: jal         0x8009C128
    // 0x8009D6F8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_7;
    // 0x8009D6F8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_7:
    // 0x8009D6FC: jal         0x800DC0C0
    // 0x8009D700: nop

    func_800DC0C0(rdram, ctx);
        goto after_8;
    // 0x8009D700: nop

    after_8:
    // 0x8009D704: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D708: lwc1        $f4, 0x5380($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5380);
    // 0x8009D70C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D710: lwc1        $f8, 0x5384($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5384);
    // 0x8009D714: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8009D718: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
    // 0x8009D71C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009D720: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009D724: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009D728: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8009D72C: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x8009D730: lw          $t5, 0x104($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X104);
    // 0x8009D734: lwc1        $f14, 0x5388($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5388);
    // 0x8009D738: jal         0x800F0E00
    // 0x8009D73C: lwc1        $f12, 0x14($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X14);
    func_800F0E00(rdram, ctx);
        goto after_9;
    // 0x8009D73C: lwc1        $f12, 0x14($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X14);
    after_9:
    // 0x8009D740: lw          $t6, 0x104($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X104);
    // 0x8009D744: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8009D748: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8009D74C: swc1        $f0, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f0.u32l;
    // 0x8009D750: lw          $t7, 0x104($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X104);
    // 0x8009D754: jal         0x800F13F0
    // 0x8009D758: lwc1        $f12, 0x14($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X14);
    func_800F13F0(rdram, ctx);
        goto after_10;
    // 0x8009D758: lwc1        $f12, 0x14($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X14);
    after_10:
    // 0x8009D75C: lw          $t8, 0x104($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X104);
    // 0x8009D760: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8009D764: swc1        $f0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f0.u32l;
    // 0x8009D768: lw          $t9, 0x104($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X104);
    // 0x8009D76C: jal         0x800C35E8
    // 0x8009D770: lbu         $a0, 0x1($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X1);
    func_800C35E8(rdram, ctx);
        goto after_11;
    // 0x8009D770: lbu         $a0, 0x1($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X1);
    after_11:
    // 0x8009D774: lw          $v0, 0x104($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X104);
    // 0x8009D778: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x8009D77C: jal         0x800C31DC
    // 0x8009D780: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    func_800C31DC(rdram, ctx);
        goto after_12;
    // 0x8009D780: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    after_12:
    // 0x8009D784: lw          $t0, 0x104($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X104);
    // 0x8009D788: jal         0x800C3BDC
    // 0x8009D78C: lbu         $a0, 0x1($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X1);
    func_800C3BDC(rdram, ctx);
        goto after_13;
    // 0x8009D78C: lbu         $a0, 0x1($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X1);
    after_13:
    // 0x8009D790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D794: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009D798: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8009D79C: jr          $ra
    // 0x8009D7A0: nop

    return;
    // 0x8009D7A0: nop

;}
RECOMP_FUNC void _glzone_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088790: syscall     703
    recomp_syscall_handler(rdram, ctx, 0x80088790);
    return;
    // 0x80088794: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void _baattach_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084440: syscall     111
    recomp_syscall_handler(rdram, ctx, 0x80084440);
    return;
    // 0x80084444: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80806DC4_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806DC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80806DC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80806DCC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80806DD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80806DD4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80806DD8: jal         0x80100094
    // 0x80806DDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806DDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806DE0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80806DE4: addiu       $at, $zero, 0x26C
    ctx->r1 = ADD32(0, 0X26C);
    // 0x80806DE8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80806DEC: lw          $v1, 0x24($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X24);
    // 0x80806DF0: srl         $t7, $v1, 22
    ctx->r15 = S32(U32(ctx->r3) >> 22);
    // 0x80806DF4: beq         $t7, $at, L_80806E1C
    if (ctx->r15 == ctx->r1) {
        // 0x80806DF8: addiu       $at, $zero, 0x26D
        ctx->r1 = ADD32(0, 0X26D);
            goto L_80806E1C;
    }
    // 0x80806DF8: addiu       $at, $zero, 0x26D
    ctx->r1 = ADD32(0, 0X26D);
    // 0x80806DFC: beq         $t7, $at, L_80806E24
    if (ctx->r15 == ctx->r1) {
        // 0x80806E00: addiu       $at, $zero, 0x26E
        ctx->r1 = ADD32(0, 0X26E);
            goto L_80806E24;
    }
    // 0x80806E00: addiu       $at, $zero, 0x26E
    ctx->r1 = ADD32(0, 0X26E);
    // 0x80806E04: beq         $t7, $at, L_80806E24
    if (ctx->r15 == ctx->r1) {
        // 0x80806E08: addiu       $at, $zero, 0x26F
        ctx->r1 = ADD32(0, 0X26F);
            goto L_80806E24;
    }
    // 0x80806E08: addiu       $at, $zero, 0x26F
    ctx->r1 = ADD32(0, 0X26F);
    // 0x80806E0C: beq         $t7, $at, L_80806E2C
    if (ctx->r15 == ctx->r1) {
        // 0x80806E10: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80806E2C;
    }
    // 0x80806E10: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80806E14: b           L_80806ED4
    // 0x80806E18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80806ED4;
    // 0x80806E18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806E1C:
    // 0x80806E1C: b           L_80806E2C
    // 0x80806E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80806E2C;
    // 0x80806E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80806E24:
    // 0x80806E24: b           L_80806E2C
    // 0x80806E28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80806E2C;
    // 0x80806E28: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80806E2C:
    // 0x80806E2C: lbu         $t8, 0x2($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X2);
    // 0x80806E30: lbu         $a1, 0x69($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X69);
    // 0x80806E34: jal         0x800F0E28
    // 0x80806E38: subu        $a0, $t8, $v0
    ctx->r4 = SUB32(ctx->r24, ctx->r2);
    func_800F0E28(rdram, ctx);
        goto after_1;
    // 0x80806E38: subu        $a0, $t8, $v0
    ctx->r4 = SUB32(ctx->r24, ctx->r2);
    after_1:
    // 0x80806E3C: sb          $v0, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r2;
    // 0x80806E40: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80806E44: jal         0x80806F10
    // 0x80806E48: lbu         $a1, 0x78($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X78);
    func_80806F10_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80806E48: lbu         $a1, 0x78($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X78);
    after_2:
    // 0x80806E4C: lbu         $t9, 0x69($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X69);
    // 0x80806E50: lbu         $t0, 0x2($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X2);
    // 0x80806E54: sb          $v0, 0x78($s0)
    MEM_B(0X78, ctx->r16) = ctx->r2;
    // 0x80806E58: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80806E5C: bnel        $t9, $t0, L_80806E70
    if (ctx->r25 != ctx->r8) {
        // 0x80806E60: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80806E70;
    }
    goto skip_0;
    // 0x80806E60: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x80806E64: jal         0x80109FE8
    // 0x80806E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80109FE8(rdram, ctx);
        goto after_3;
    // 0x80806E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80806E6C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80806E70:
    // 0x80806E70: jal         0x80802298
    // 0x80806E74: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_80802298_chdiggerboss(rdram, ctx);
        goto after_4;
    // 0x80806E74: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80806E78: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80806E7C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80806E80: jal         0x8010963C
    // 0x80806E84: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    func_8010963C(rdram, ctx);
        goto after_5;
    // 0x80806E84: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_5:
    // 0x80806E88: lbu         $v1, 0x5C($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X5C);
    // 0x80806E8C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80806E90: beq         $v1, $at, L_80806ED0
    if (ctx->r3 == ctx->r1) {
        // 0x80806E94: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80806ED0;
    }
    // 0x80806E94: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80806E98: beq         $v1, $at, L_80806EB4
    if (ctx->r3 == ctx->r1) {
        // 0x80806E9C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80806EB4;
    }
    // 0x80806E9C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80806EA0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80806EA4: beql        $v1, $at, L_80806ED4
    if (ctx->r3 == ctx->r1) {
        // 0x80806EA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80806ED4;
    }
    goto skip_1;
    // 0x80806EA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80806EAC: b           L_80806EC0
    // 0x80806EB0: nop

        goto L_80806EC0;
    // 0x80806EB0: nop

L_80806EB4:
    // 0x80806EB4: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x80806EB8: bnel        $t1, $zero, L_80806ED4
    if (ctx->r9 != 0) {
        // 0x80806EBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80806ED4;
    }
    goto skip_2;
    // 0x80806EBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_80806EC0:
    // 0x80806EC0: jal         0x80800180
    // 0x80806EC4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800180_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x80806EC4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
    // 0x80806EC8: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80806ECC: sb          $t2, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r10;
L_80806ED0:
    // 0x80806ED0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80806ED4:
    // 0x80806ED4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80806ED8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80806EDC: jr          $ra
    // 0x80806EE0: nop

    return;
    // 0x80806EE0: nop

;}
RECOMP_FUNC void _subaddiejoy_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BC8: syscall     805
    recomp_syscall_handler(rdram, ctx, 0x80089BC8);
    return;
    // 0x80089BCC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800140_chflysaucerdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800148: jal         0x80085840
    // 0x8080014C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _chswitch_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x8080014C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80800150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800158: jr          $ra
    // 0x8080015C: nop

    return;
    // 0x8080015C: nop

;}
RECOMP_FUNC void idtwinklecolour_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: sll         $t6, $a3, 4
    ctx->r14 = S32(ctx->r7 << 4);
    // 0x80800250: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80800254: addu        $v0, $t6, $a1
    ctx->r2 = ADD32(ctx->r14, ctx->r5);
    // 0x80800258: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8080025C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80800260: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80800264: beq         $at, $zero, L_80800568
    if (ctx->r1 == 0) {
        // 0x80800268: sw          $a0, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r4;
            goto L_80800568;
    }
    // 0x80800268: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x8080026C: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2946, 0X970) << 16);
    // 0x80800270: addiu       $t4, $t4, 0x970
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2946, 0X970));
    // 0x80800274: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80800278: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8080027C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800280:
    // 0x80800280: lh          $a2, 0x22($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X22);
    // 0x80800284: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800288: blez        $a2, L_808002D4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8080028C: nop
    
            goto L_808002D4;
    }
    // 0x8080028C: nop

    // 0x80800290: lh          $a3, 0x0($a1)
    ctx->r7 = MEM_H(ctx->r5, 0X0);
    // 0x80800294: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
L_80800298:
    // 0x80800298: lh          $t7, 0x4($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X4);
    // 0x8080029C: bnel        $a3, $t7, L_808002C8
    if (ctx->r7 != ctx->r15) {
        // 0x808002A0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_808002C8;
    }
    goto skip_0;
    // 0x808002A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x808002A4: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x808002A8: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x808002AC: bnel        $t8, $t9, L_808002C8
    if (ctx->r24 != ctx->r25) {
        // 0x808002B0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_808002C8;
    }
    goto skip_1;
    // 0x808002B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x808002B4: lh          $t6, 0x4($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X4);
    // 0x808002B8: lh          $t7, 0x8($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X8);
    // 0x808002BC: beq         $t6, $t7, L_808002D4
    if (ctx->r14 == ctx->r15) {
        // 0x808002C0: nop
    
            goto L_808002D4;
    }
    // 0x808002C0: nop

    // 0x808002C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_808002C8:
    // 0x808002C8: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x808002CC: bne         $at, $zero, L_80800298
    if (ctx->r1 != 0) {
        // 0x808002D0: addiu       $t0, $t0, 0x14
        ctx->r8 = ADD32(ctx->r8, 0X14);
            goto L_80800298;
    }
    // 0x808002D0: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
L_808002D4:
    // 0x808002D4: beql        $v1, $a2, L_8080055C
    if (ctx->r3 == ctx->r6) {
        // 0x808002D8: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_8080055C;
    }
    goto skip_2;
    // 0x808002D8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    skip_2:
    // 0x808002DC: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808002E0: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x808002E4: lbu         $a3, 0xC($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0XC);
    // 0x808002E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808002EC: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x808002F0: nop

    // 0x808002F4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808002F8: mflo        $t9
    ctx->r25 = lo;
    // 0x808002FC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80800300: lbu         $t6, 0xC($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0XC);
    // 0x80800304: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80800308: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080030C: mflo        $t7
    ctx->r15 = lo;
    // 0x80800310: addu        $a2, $t4, $t7
    ctx->r6 = ADD32(ctx->r12, ctx->r15);
    // 0x80800314: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x80800318: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x8080031C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80800320: nop

    // 0x80800324: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800328: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8080032C: bgezl       $a3, L_80800344
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80800330: add.s       $f4, $f8, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
            goto L_80800344;
    }
    goto skip_3;
    // 0x80800330: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    skip_3:
    // 0x80800334: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800338: nop

    // 0x8080033C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800340: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
L_80800344:
    // 0x80800344: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800348: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8080034C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800350: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800354: nop

    // 0x80800358: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8080035C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800360: nop

    // 0x80800364: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800368: beql        $t7, $zero, L_808003B8
    if (ctx->r15 == 0) {
        // 0x8080036C: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_808003B8;
    }
    goto skip_4;
    // 0x8080036C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_4:
    // 0x80800370: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800374: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800378: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8080037C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800380: nop

    // 0x80800384: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800388: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8080038C: nop

    // 0x80800390: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800394: bne         $t7, $zero, L_808003AC
    if (ctx->r15 != 0) {
        // 0x80800398: nop
    
            goto L_808003AC;
    }
    // 0x80800398: nop

    // 0x8080039C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x808003A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808003A4: b           L_808003C4
    // 0x808003A8: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_808003C4;
    // 0x808003A8: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_808003AC:
    // 0x808003AC: b           L_808003C4
    // 0x808003B0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_808003C4;
    // 0x808003B0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x808003B4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_808003B8:
    // 0x808003B8: nop

    // 0x808003BC: bltz        $t7, L_808003AC
    if (SIGNED(ctx->r15) < 0) {
        // 0x808003C0: nop
    
            goto L_808003AC;
    }
    // 0x808003C0: nop

L_808003C4:
    // 0x808003C4: sb          $t7, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r15;
    // 0x808003C8: lbu         $t8, 0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X1);
    // 0x808003CC: lbu         $t1, 0xD($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XD);
    // 0x808003D0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x808003D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808003D8: subu        $t9, $t8, $t1
    ctx->r25 = SUB32(ctx->r24, ctx->r9);
    // 0x808003DC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x808003E0: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x808003E4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808003E8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808003EC: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x808003F0: bgezl       $t1, L_80800408
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808003F4: add.s       $f10, $f8, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
            goto L_80800408;
    }
    goto skip_5;
    // 0x808003F4: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    skip_5:
    // 0x808003F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003FC: nop

    // 0x80800400: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800404: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
L_80800408:
    // 0x80800408: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080040C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800410: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80800414: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800418: nop

    // 0x8080041C: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80800420: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800424: nop

    // 0x80800428: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8080042C: beql        $t7, $zero, L_8080047C
    if (ctx->r15 == 0) {
        // 0x80800430: mfc1        $t7, $f18
        ctx->r15 = (int32_t)ctx->f18.u32l;
            goto L_8080047C;
    }
    goto skip_6;
    // 0x80800430: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    skip_6:
    // 0x80800434: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800438: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8080043C: sub.s       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80800440: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800444: nop

    // 0x80800448: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8080044C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800450: nop

    // 0x80800454: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80800458: bne         $t7, $zero, L_80800470
    if (ctx->r15 != 0) {
        // 0x8080045C: nop
    
            goto L_80800470;
    }
    // 0x8080045C: nop

    // 0x80800460: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80800464: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800468: b           L_80800488
    // 0x8080046C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80800488;
    // 0x8080046C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80800470:
    // 0x80800470: b           L_80800488
    // 0x80800474: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80800488;
    // 0x80800474: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80800478: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
L_8080047C:
    // 0x8080047C: nop

    // 0x80800480: bltz        $t7, L_80800470
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800484: nop
    
            goto L_80800470;
    }
    // 0x80800484: nop

L_80800488:
    // 0x80800488: sb          $t7, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r15;
    // 0x8080048C: lbu         $t8, 0x2($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X2);
    // 0x80800490: lbu         $t2, 0xE($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XE);
    // 0x80800494: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800498: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080049C: subu        $t9, $t8, $t2
    ctx->r25 = SUB32(ctx->r24, ctx->r10);
    // 0x808004A0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x808004A4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x808004A8: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808004AC: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808004B0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808004B4: bgezl       $t2, L_808004CC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808004B8: add.s       $f16, $f8, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
            goto L_808004CC;
    }
    goto skip_7;
    // 0x808004B8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    skip_7:
    // 0x808004BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808004C0: nop

    // 0x808004C4: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x808004C8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
L_808004CC:
    // 0x808004CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808004D0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808004D4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x808004D8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x808004DC: nop

    // 0x808004E0: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x808004E4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x808004E8: nop

    // 0x808004EC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x808004F0: beql        $t7, $zero, L_80800540
    if (ctx->r15 == 0) {
        // 0x808004F4: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_80800540;
    }
    goto skip_8;
    // 0x808004F4: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_8:
    // 0x808004F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808004FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800500: sub.s       $f6, $f16, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80800504: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80800508: nop

    // 0x8080050C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800510: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80800514: nop

    // 0x80800518: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8080051C: bne         $t7, $zero, L_80800534
    if (ctx->r15 != 0) {
        // 0x80800520: nop
    
            goto L_80800534;
    }
    // 0x80800520: nop

    // 0x80800524: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800528: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8080052C: b           L_8080054C
    // 0x80800530: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8080054C;
    // 0x80800530: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80800534:
    // 0x80800534: b           L_8080054C
    // 0x80800538: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8080054C;
    // 0x80800538: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8080053C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_80800540:
    // 0x80800540: nop

    // 0x80800544: bltz        $t7, L_80800534
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800548: nop
    
            goto L_80800534;
    }
    // 0x80800548: nop

L_8080054C:
    // 0x8080054C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80800550: sb          $t7, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r15;
    // 0x80800554: nop

    // 0x80800558: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
L_8080055C:
    // 0x8080055C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80800560: bne         $at, $zero, L_80800280
    if (ctx->r1 != 0) {
        // 0x80800564: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_80800280;
    }
    // 0x80800564: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_80800568:
    // 0x80800568: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8080056C: jr          $ra
    // 0x80800570: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80800570: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void chtoxicroomprops_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800644: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2492, 0X9E8) << 16);
    // 0x80800648: jr          $ra
    // 0x8080064C: addiu       $v0, $v0, 0x9E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2492, 0X9E8));
    return;
    // 0x8080064C: addiu       $v0, $v0, 0x9E8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2492, 0X9E8));
;}
RECOMP_FUNC void func_800E829C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E829C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800E82A0: addiu       $a1, $t6, -0x2A00
    ctx->r5 = ADD32(ctx->r14, -0X2A00);
    // 0x800E82A4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800E82A8: addiu       $a3, $a3, -0x2988
    ctx->r7 = ADD32(ctx->r7, -0X2988);
    // 0x800E82AC: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800E82B0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
L_800E82B4:
    // 0x800E82B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E82B8: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800E82BC: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800E82C0: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    // 0x800E82C4: mflo        $t7
    ctx->r15 = lo;
    // 0x800E82C8: addu        $a0, $v1, $t7
    ctx->r4 = ADD32(ctx->r3, ctx->r15);
    // 0x800E82CC: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // 0x800E82D0: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x800E82D4: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x800E82D8: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x800E82DC: bne         $a1, $a3, L_800E82B4
    if (ctx->r5 != ctx->r7) {
        // 0x800E82E0: sw          $zero, 0xC($a0)
        MEM_W(0XC, ctx->r4) = 0;
            goto L_800E82B4;
    }
    // 0x800E82E0: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800E82E4: jr          $ra
    // 0x800E82E8: nop

    return;
    // 0x800E82E8: nop

;}
RECOMP_FUNC void func_80800E48_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E50: jal         0x800D395C
    // 0x80800E54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D395C(rdram, ctx);
        goto after_0;
    // 0x80800E54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E58: beq         $v0, $zero, L_80800E8C
    if (ctx->r2 == 0) {
        // 0x80800E5C: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_80800E8C;
    }
    // 0x80800E5C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80800E60: jal         0x800D211C
    // 0x80800E64: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800D211C(rdram, ctx);
        goto after_1;
    // 0x80800E64: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_1:
    // 0x80800E68: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80800E6C: lh          $t6, 0x75C8($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X75C8);
    // 0x80800E70: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80800E74: beq         $at, $zero, L_80800E84
    if (ctx->r1 == 0) {
        // 0x80800E78: nop
    
            goto L_80800E84;
    }
    // 0x80800E78: nop

    // 0x80800E7C: b           L_80800F88
    // 0x80800E80: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800F88;
    // 0x80800E80: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800E84:
    // 0x80800E84: b           L_80800F88
    // 0x80800E88: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80800F88;
    // 0x80800E88: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80800E8C:
    // 0x80800E8C: jal         0x800D0A9C
    // 0x80800E90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_2;
    // 0x80800E90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800E94: bne         $v0, $zero, L_80800EFC
    if (ctx->r2 != 0) {
        // 0x80800E98: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_80800EFC;
    }
    // 0x80800E98: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80800E9C: jal         0x800D0A9C
    // 0x80800EA0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_3;
    // 0x80800EA0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800EA4: bne         $v0, $zero, L_80800EFC
    if (ctx->r2 != 0) {
        // 0x80800EA8: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80800EFC;
    }
    // 0x80800EA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80800EAC: lh          $v0, 0x75C8($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X75C8);
    // 0x80800EB0: slti        $at, $v0, 0x1F4
    ctx->r1 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    // 0x80800EB4: bne         $at, $zero, L_80800ECC
    if (ctx->r1 != 0) {
        // 0x80800EB8: slti        $at, $v0, 0x190
        ctx->r1 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
            goto L_80800ECC;
    }
    // 0x80800EB8: slti        $at, $v0, 0x190
    ctx->r1 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    // 0x80800EBC: bnel        $at, $zero, L_80800ED0
    if (ctx->r1 != 0) {
        // 0x80800EC0: slti        $at, $v0, 0x1F4
        ctx->r1 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
            goto L_80800ED0;
    }
    goto skip_0;
    // 0x80800EC0: slti        $at, $v0, 0x1F4
    ctx->r1 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
    skip_0:
    // 0x80800EC4: b           L_80800F88
    // 0x80800EC8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800F88;
    // 0x80800EC8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800ECC:
    // 0x80800ECC: slti        $at, $v0, 0x1F4
    ctx->r1 = SIGNED(ctx->r2) < 0X1F4 ? 1 : 0;
L_80800ED0:
    // 0x80800ED0: bnel        $at, $zero, L_80800EE4
    if (ctx->r1 != 0) {
        // 0x80800ED4: slti        $at, $v0, 0x190
        ctx->r1 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
            goto L_80800EE4;
    }
    goto skip_1;
    // 0x80800ED4: slti        $at, $v0, 0x190
    ctx->r1 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
    skip_1:
    // 0x80800ED8: b           L_80800F88
    // 0x80800EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F88;
    // 0x80800EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800EE0: slti        $at, $v0, 0x190
    ctx->r1 = SIGNED(ctx->r2) < 0X190 ? 1 : 0;
L_80800EE4:
    // 0x80800EE4: bne         $at, $zero, L_80800EF4
    if (ctx->r1 != 0) {
        // 0x80800EE8: nop
    
            goto L_80800EF4;
    }
    // 0x80800EE8: nop

    // 0x80800EEC: b           L_80800F88
    // 0x80800EF0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800F88;
    // 0x80800EF0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800EF4:
    // 0x80800EF4: b           L_80800F88
    // 0x80800EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F88;
    // 0x80800EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800EFC:
    // 0x80800EFC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80800F00: jal         0x800D0A9C
    // 0x80800F04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_4;
    // 0x80800F04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800F08: bne         $v0, $zero, L_80800F34
    if (ctx->r2 != 0) {
        // 0x80800F0C: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_80800F34;
    }
    // 0x80800F0C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80800F10: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80800F14: lh          $t7, 0x75C8($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X75C8);
    // 0x80800F18: slti        $at, $t7, 0x1F4
    ctx->r1 = SIGNED(ctx->r15) < 0X1F4 ? 1 : 0;
    // 0x80800F1C: bne         $at, $zero, L_80800F2C
    if (ctx->r1 != 0) {
        // 0x80800F20: nop
    
            goto L_80800F2C;
    }
    // 0x80800F20: nop

    // 0x80800F24: b           L_80800F88
    // 0x80800F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F88;
    // 0x80800F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F2C:
    // 0x80800F2C: b           L_80800F88
    // 0x80800F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F88;
    // 0x80800F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800F34:
    // 0x80800F34: jal         0x800D0A9C
    // 0x80800F38: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_5;
    // 0x80800F38: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x80800F3C: bne         $v0, $zero, L_80800F64
    if (ctx->r2 != 0) {
        // 0x80800F40: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80800F64;
    }
    // 0x80800F40: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80800F44: lh          $t8, 0x75C8($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X75C8);
    // 0x80800F48: slti        $at, $t8, 0x190
    ctx->r1 = SIGNED(ctx->r24) < 0X190 ? 1 : 0;
    // 0x80800F4C: bne         $at, $zero, L_80800F5C
    if (ctx->r1 != 0) {
        // 0x80800F50: nop
    
            goto L_80800F5C;
    }
    // 0x80800F50: nop

    // 0x80800F54: b           L_80800F88
    // 0x80800F58: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800F88;
    // 0x80800F58: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800F5C:
    // 0x80800F5C: b           L_80800F88
    // 0x80800F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F88;
    // 0x80800F60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800F64:
    // 0x80800F64: jal         0x800D211C
    // 0x80800F68: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800D211C(rdram, ctx);
        goto after_6;
    // 0x80800F68: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_6:
    // 0x80800F6C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80800F70: lh          $t9, 0x75C8($t9)
    ctx->r25 = MEM_H(ctx->r25, 0X75C8);
    // 0x80800F74: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800F78: beq         $at, $zero, L_80800F88
    if (ctx->r1 == 0) {
        // 0x80800F7C: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_80800F88;
    }
    // 0x80800F7C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80800F80: b           L_80800F88
    // 0x80800F84: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800F88;
    // 0x80800F84: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800F88:
    // 0x80800F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F90: jr          $ra
    // 0x80800F94: nop

    return;
    // 0x80800F94: nop

;}
RECOMP_FUNC void plcamera_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080045C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800460: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800464: jal         0x800F5EF8
    // 0x80800468: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x80800468: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080046C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800470: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800474: jal         0x8010FDA8
    // 0x80800478: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_8010FDA8(rdram, ctx);
        goto after_1;
    // 0x80800478: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8080047C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800484: jr          $ra
    // 0x80800488: nop

    return;
    // 0x80800488: nop

;}
RECOMP_FUNC void func_808027DC_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027DC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808027E0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808027E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808027E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808027EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808027F0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x808027F4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x808027F8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x808027FC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80802800: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80802804: jal         0x80800070
    // 0x80802808: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    func_80800070_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x80802808: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    after_0:
    // 0x8080280C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80802810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802814: jal         0x80800000
    // 0x80802818: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_1;
    // 0x80802818: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8080281C: sll         $t6, $s5, 1
    ctx->r14 = S32(ctx->r21 << 1);
    // 0x80802820: addu        $s6, $s0, $t6
    ctx->r22 = ADD32(ctx->r16, ctx->r14);
    // 0x80802824: lh          $t7, 0xEC($s6)
    ctx->r15 = MEM_H(ctx->r22, 0XEC);
    // 0x80802828: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8080282C: jal         0x80088730
    // 0x80802830: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    _gldialog_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80802830: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    after_2:
    // 0x80802834: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80802838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080283C: jal         0x80800000
    // 0x80802840: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800000_gcnewoption(rdram, ctx);
        goto after_3;
    // 0x80802840: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80802844: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x80802848: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x8080284C: lh          $t1, 0x50($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X50);
    // 0x80802850: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80802854: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80802858: bnel        $t8, $t1, L_808028C8
    if (ctx->r24 != ctx->r9) {
        // 0x8080285C: sll         $t4, $s4, 2
        ctx->r12 = S32(ctx->r20 << 2);
            goto L_808028C8;
    }
    goto skip_0;
    // 0x8080285C: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
    skip_0:
    // 0x80802860: multu       $s4, $v0
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802864: mflo        $t2
    ctx->r10 = lo;
    // 0x80802868: addu        $s2, $s0, $t2
    ctx->r18 = ADD32(ctx->r16, ctx->r10);
    // 0x8080286C: lh          $t4, 0x5A($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X5A);
    // 0x80802870: multu       $s5, $v0
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80802874: mflo        $t3
    ctx->r11 = lo;
    // 0x80802878: addu        $s1, $s0, $t3
    ctx->r17 = ADD32(ctx->r16, ctx->r11);
    // 0x8080287C: lh          $t5, 0x128($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X128);
    // 0x80802880: bnel        $t4, $t5, L_808028C8
    if (ctx->r12 != ctx->r13) {
        // 0x80802884: sll         $t4, $s4, 2
        ctx->r12 = S32(ctx->r20 << 2);
            goto L_808028C8;
    }
    goto skip_1;
    // 0x80802884: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
    skip_1:
    // 0x80802888: lh          $t6, 0x5C($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X5C);
    // 0x8080288C: lh          $t7, 0x12A($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X12A);
    // 0x80802890: bnel        $t6, $t7, L_808028C8
    if (ctx->r14 != ctx->r15) {
        // 0x80802894: sll         $t4, $s4, 2
        ctx->r12 = S32(ctx->r20 << 2);
            goto L_808028C8;
    }
    goto skip_2;
    // 0x80802894: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
    skip_2:
    // 0x80802898: lh          $t9, 0x5E($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X5E);
    // 0x8080289C: lh          $t0, 0x12C($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X12C);
    // 0x808028A0: addu        $t8, $s0, $s4
    ctx->r24 = ADD32(ctx->r16, ctx->r20);
    // 0x808028A4: bnel        $t9, $t0, L_808028C8
    if (ctx->r25 != ctx->r8) {
        // 0x808028A8: sll         $t4, $s4, 2
        ctx->r12 = S32(ctx->r20 << 2);
            goto L_808028C8;
    }
    goto skip_3;
    // 0x808028A8: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
    skip_3:
    // 0x808028AC: lbu         $t1, 0x78($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X78);
    // 0x808028B0: lh          $t2, 0x1DC($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X1DC);
    // 0x808028B4: bnel        $t1, $t2, L_808028C8
    if (ctx->r9 != ctx->r10) {
        // 0x808028B8: sll         $t4, $s4, 2
        ctx->r12 = S32(ctx->r20 << 2);
            goto L_808028C8;
    }
    goto skip_4;
    // 0x808028B8: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
    skip_4:
    // 0x808028BC: lh          $t3, 0xC($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XC);
    // 0x808028C0: beq         $s3, $t3, L_80802970
    if (ctx->r19 == ctx->r11) {
        // 0x808028C4: sll         $t4, $s4, 2
        ctx->r12 = S32(ctx->r20 << 2);
            goto L_80802970;
    }
    // 0x808028C4: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
L_808028C8:
    // 0x808028C8: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x808028CC: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x808028D0: subu        $t6, $t6, $s5
    ctx->r14 = SUB32(ctx->r14, ctx->r21);
    // 0x808028D4: subu        $t5, $t5, $s4
    ctx->r13 = SUB32(ctx->r13, ctx->r20);
    // 0x808028D8: addu        $s3, $s0, $t4
    ctx->r19 = ADD32(ctx->r16, ctx->r12);
    // 0x808028DC: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    // 0x808028E0: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x808028E4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x808028E8: addu        $t7, $s0, $s4
    ctx->r15 = ADD32(ctx->r16, ctx->r20);
    // 0x808028EC: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x808028F0: addu        $s1, $s0, $t6
    ctx->r17 = ADD32(ctx->r16, ctx->r14);
    // 0x808028F4: jal         0x80087BE0
    // 0x808028F8: addu        $s2, $s0, $t5
    ctx->r18 = ADD32(ctx->r16, ctx->r13);
    _gczoombox_entrypoint_32(rdram, ctx);
        goto after_4;
    // 0x808028F8: addu        $s2, $s0, $t5
    ctx->r18 = ADD32(ctx->r16, ctx->r13);
    after_4:
    // 0x808028FC: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    // 0x80802900: jal         0x80087BB8
    // 0x80802904: addiu       $a1, $s1, 0x128
    ctx->r5 = ADD32(ctx->r17, 0X128);
    _gczoombox_entrypoint_27(rdram, ctx);
        goto after_5;
    // 0x80802904: addiu       $a1, $s1, 0x128
    ctx->r5 = ADD32(ctx->r17, 0X128);
    after_5:
    // 0x80802908: lw          $a0, 0x23C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X23C);
    // 0x8080290C: jal         0x80088720
    // 0x80802910: lh          $a1, 0x56($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X56);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80802910: lh          $a1, 0x56($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X56);
    after_6:
    // 0x80802914: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    // 0x80802918: jal         0x80087B20
    // 0x8080291C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gczoombox_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x8080291C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80802920: addu        $t9, $s0, $s5
    ctx->r25 = ADD32(ctx->r16, ctx->r21);
    // 0x80802924: lbu         $a1, 0x218($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X218);
    // 0x80802928: jal         0x80087C20
    // 0x8080292C: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    _gczoombox_entrypoint_40(rdram, ctx);
        goto after_8;
    // 0x8080292C: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    after_8:
    // 0x80802930: lw          $a0, 0x3C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X3C);
    // 0x80802934: jal         0x80087C00
    // 0x80802938: lh          $a1, 0x1DC($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X1DC);
    _gczoombox_entrypoint_36(rdram, ctx);
        goto after_9;
    // 0x80802938: lh          $a1, 0x1DC($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X1DC);
    after_9:
    // 0x8080293C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x80802940: sll         $t8, $s4, 1
    ctx->r24 = S32(ctx->r20 << 1);
    // 0x80802944: addu        $t1, $s0, $t8
    ctx->r9 = ADD32(ctx->r16, ctx->r24);
    // 0x80802948: sh          $t0, 0x50($t1)
    MEM_H(0X50, ctx->r9) = ctx->r8;
    // 0x8080294C: lh          $t2, 0x128($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X128);
    // 0x80802950: sh          $t2, 0x5A($s2)
    MEM_H(0X5A, ctx->r18) = ctx->r10;
    // 0x80802954: lh          $t3, 0x12A($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X12A);
    // 0x80802958: sh          $t3, 0x5C($s2)
    MEM_H(0X5C, ctx->r18) = ctx->r11;
    // 0x8080295C: lh          $t4, 0x12C($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X12C);
    // 0x80802960: sh          $t4, 0x5E($s2)
    MEM_H(0X5E, ctx->r18) = ctx->r12;
    // 0x80802964: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80802968: lh          $t5, 0x1DC($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X1DC);
    // 0x8080296C: sb          $t5, 0x78($t6)
    MEM_B(0X78, ctx->r14) = ctx->r13;
L_80802970:
    // 0x80802970: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80802974: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802978: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080297C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80802980: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80802984: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80802988: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8080298C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80802990: jr          $ra
    // 0x80802994: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80802994: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _bskazdie_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833D0: syscall     58
    recomp_syscall_handler(rdram, ctx, 0x800833D0);
    return;
    // 0x800833D4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800B9170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9170: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800B9174: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B9178: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800B917C: addiu       $s0, $s0, 0x7128
    ctx->r16 = ADD32(ctx->r16, 0X7128);
    // 0x800B9180: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800B9184: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B9188: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800B918C: beql        $t6, $zero, L_800B955C
    if (ctx->r14 == 0) {
        // 0x800B9190: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B955C;
    }
    goto skip_0;
    // 0x800B9190: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800B9194: jal         0x800A5490
    // 0x800B9198: nop

    func_800A5490(rdram, ctx);
        goto after_0;
    // 0x800B9198: nop

    after_0:
    // 0x800B919C: beq         $v0, $zero, L_800B91AC
    if (ctx->r2 == 0) {
        // 0x800B91A0: nop
    
            goto L_800B91AC;
    }
    // 0x800B91A0: nop

    // 0x800B91A4: b           L_800B9558
    // 0x800B91A8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
        goto L_800B9558;
    // 0x800B91A8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_800B91AC:
    // 0x800B91AC: jal         0x800D8FF8
    // 0x800B91B0: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x800B91B0: nop

    after_1:
    // 0x800B91B4: jal         0x8001211C
    // 0x800B91B8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001211C(rdram, ctx);
        goto after_2;
    // 0x800B91B8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x800B91BC: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800B91C0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B91C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B91C8: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800B91CC: jal         0x8008FE68
    // 0x800B91D0: addiu       $a0, $a0, 0x7138
    ctx->r4 = ADD32(ctx->r4, 0X7138);
    func_8008FE68(rdram, ctx);
        goto after_3;
    // 0x800B91D0: addiu       $a0, $a0, 0x7138
    ctx->r4 = ADD32(ctx->r4, 0X7138);
    after_3:
    // 0x800B91D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B91D8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B91DC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800B91E0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B91E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B91E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B91EC: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x800B91F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B91F4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B91F8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800B91FC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800B9200: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
    // 0x800B9204: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800B9208: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800B920C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800B9210: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B9214: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B9218: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x800B921C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800B9220: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B9224: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x800B9228: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B922C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800B9230: swc1        $f16, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f16.u32l;
    // 0x800B9234: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800B9238: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800B923C: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
    // 0x800B9240: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B9244: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800B9248: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B924C: blez        $v1, L_800B9328
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B9250: swc1        $f8, 0x1C($s0)
        MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
            goto L_800B9328;
    }
    // 0x800B9250: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x800B9254: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800B9258: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800B925C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800B9260: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x800B9264: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x800B9268: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
L_800B926C:
    // 0x800B926C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B9270: lw          $t5, 0x1C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C);
    // 0x800B9274: addu        $a2, $t5, $a3
    ctx->r6 = ADD32(ctx->r13, ctx->r7);
    // 0x800B9278: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800B927C: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800B9280: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B9284: mul.s       $f18, $f14, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800B9288: beql        $v1, $a0, L_800B92B4
    if (ctx->r3 == ctx->r4) {
        // 0x800B928C: lwc1        $f16, 0x0($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
            goto L_800B92B4;
    }
    goto skip_1;
    // 0x800B928C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    skip_1:
L_800B9290:
    // 0x800B9290: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B9294: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800B9298: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B929C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B92A0: mul.s       $f18, $f14, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800B92A4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B92A8: bne         $v1, $a0, L_800B9290
    if (ctx->r3 != ctx->r4) {
        // 0x800B92AC: swc1        $f16, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
            goto L_800B9290;
    }
    // 0x800B92AC: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800B92B0: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
L_800B92B4:
    // 0x800B92B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B92B8: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B92BC: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x800B92C0: sw          $a1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r5;
    // 0x800B92C4: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    // 0x800B92C8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800B92CC: jal         0x800DC0C0
    // 0x800B92D0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800DC0C0(rdram, ctx);
        goto after_4;
    // 0x800B92D0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_4:
    // 0x800B92D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800B92D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B92DC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800B92E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B92E4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800B92E8: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800B92EC: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800B92F0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800B92F4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800B92F8: addu        $v0, $a2, $t0
    ctx->r2 = ADD32(ctx->r6, ctx->r8);
    // 0x800B92FC: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800B9300: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800B9304: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B9308: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800B930C: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    // 0x800B9310: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800B9314: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800B9318: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800B931C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B9320: bnel        $at, $zero, L_800B926C
    if (ctx->r1 != 0) {
        // 0x800B9324: lw          $t4, 0x0($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X0);
            goto L_800B926C;
    }
    goto skip_2;
    // 0x800B9324: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    skip_2:
L_800B9328:
    // 0x800B9328: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800B932C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B9330: addiu       $a1, $a1, 0x7138
    ctx->r5 = ADD32(ctx->r5, 0X7138);
    // 0x800B9334: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800B9338: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B933C: beq         $at, $zero, L_800B9388
    if (ctx->r1 == 0) {
        // 0x800B9340: sw          $t7, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r15;
            goto L_800B9388;
    }
    // 0x800B9340: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x800B9344: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800B9348: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x800B934C: subu        $t1, $t1, $t7
    ctx->r9 = SUB32(ctx->r9, ctx->r15);
    // 0x800B9350: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x800B9354: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800B9358: jal         0x800EEAD4
    // 0x800B935C: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    func_800EEAD4(rdram, ctx);
        goto after_5;
    // 0x800B935C: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    after_5:
    // 0x800B9360: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B9364: lwc1        $f6, 0x56A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X56A0);
    // 0x800B9368: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800B936C: nop

    // 0x800B9370: bc1fl       L_800B9390
    if (!c1cs) {
        // 0x800B9374: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_800B9390;
    }
    goto skip_3;
    // 0x800B9374: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x800B9378: jal         0x800B9108
    // 0x800B937C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    func_800B9108(rdram, ctx);
        goto after_6;
    // 0x800B937C: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    after_6:
    // 0x800B9380: b           L_800B9390
    // 0x800B9384: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_800B9390;
    // 0x800B9384: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_800B9388:
    // 0x800B9388: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800B938C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_800B9390:
    // 0x800B9390: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B9394: lbu         $t2, 0x18($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X18);
    // 0x800B9398: bnel        $t2, $at, L_800B955C
    if (ctx->r10 != ctx->r1) {
        // 0x800B939C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B955C;
    }
    goto skip_4;
    // 0x800B939C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x800B93A0: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x800B93A4: slti        $at, $v1, 0x64
    ctx->r1 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
    // 0x800B93A8: beq         $at, $zero, L_800B9558
    if (ctx->r1 == 0) {
        // 0x800B93AC: sll         $t4, $v1, 2
        ctx->r12 = S32(ctx->r3 << 2);
            goto L_800B9558;
    }
    // 0x800B93AC: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800B93B0: lw          $t3, 0x1C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1C);
    // 0x800B93B4: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800B93B8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800B93BC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x800B93C0: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800B93C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B93C8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800B93CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B93D0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B93D4: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
    // 0x800B93D8: jal         0x800DC178
    // 0x800B93DC: lwc1        $f14, 0x56A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X56A4);
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x800B93DC: lwc1        $f14, 0x56A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X56A4);
    after_7:
    // 0x800B93E0: jal         0x800DC0C0
    // 0x800B93E4: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    func_800DC0C0(rdram, ctx);
        goto after_8;
    // 0x800B93E4: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x800B93E8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800B93EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B93F0: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800B93F4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800B93F8: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B93FC: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x800B9400: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B9404: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x800B9408: add.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800B940C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800B9410: jal         0x800EFA4C
    // 0x800B9414: nop

    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x800B9414: nop

    after_9:
    // 0x800B9418: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B941C: jal         0x800EEFD4
    // 0x800B9420: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EEFD4(rdram, ctx);
        goto after_10;
    // 0x800B9420: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_10:
    // 0x800B9424: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x800B9428: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B942C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800B9430: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800B9434: nop

    // 0x800B9438: bc1fl       L_800B9454
    if (!c1cs) {
        // 0x800B943C: mtc1        $at, $f20
        ctx->f20.u32l = ctx->r1;
            goto L_800B9454;
    }
    goto skip_5;
    // 0x800B943C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    skip_5:
    // 0x800B9440: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800B9444: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800B9448: b           L_800B9458
    // 0x800B944C: nop

        goto L_800B9458;
    // 0x800B944C: nop

    // 0x800B9450: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
L_800B9454:
    // 0x800B9454: nop

L_800B9458:
    // 0x800B9458: jal         0x800E3A80
    // 0x800B945C: nop

    func_800E3A80(rdram, ctx);
        goto after_11;
    // 0x800B945C: nop

    after_11:
    // 0x800B9460: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800B9464: neg.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = -ctx->f20.fl;
    // 0x800B9468: jal         0x800DC178
    // 0x800B946C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x800B946C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_12:
    // 0x800B9470: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B9474: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800B9478: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B947C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800B9480: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800B9484: jal         0x800EF934
    // 0x800B9488: nop

    func_800EF934(rdram, ctx);
        goto after_13;
    // 0x800B9488: nop

    after_13:
    // 0x800B948C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B9490: addiu       $a1, $a1, 0x7138
    ctx->r5 = ADD32(ctx->r5, 0X7138);
    // 0x800B9494: jal         0x800EF04C
    // 0x800B9498: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800EF04C(rdram, ctx);
        goto after_14;
    // 0x800B9498: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_14:
    // 0x800B949C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B94A0: lwc1        $f18, 0x56A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X56A8);
    // 0x800B94A4: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800B94A8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800B94AC: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B94B0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800B94B4: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B94B8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800B94BC: bc1fl       L_800B951C
    if (!c1cs) {
        // 0x800B94C0: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_800B951C;
    }
    goto skip_6;
    // 0x800B94C0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    skip_6:
    // 0x800B94C4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800B94C8: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800B94CC: jal         0x800E3F8C
    // 0x800B94D0: sub.s       $f14, $f10, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f20.fl;
    func_800E3F8C(rdram, ctx);
        goto after_15;
    // 0x800B94D0: sub.s       $f14, $f10, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f20.fl;
    after_15:
    // 0x800B94D4: beq         $v0, $zero, L_800B9518
    if (ctx->r2 == 0) {
        // 0x800B94D8: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_800B9518;
    }
    // 0x800B94D8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_800B94DC:
    // 0x800B94DC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800B94E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B94E4: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B94E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B94EC: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x800B94F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B94F4: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B94F8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800B94FC: beq         $at, $zero, L_800B9518
    if (ctx->r1 == 0) {
        // 0x800B9500: swc1        $f8, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
            goto L_800B9518;
    }
    // 0x800B9500: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x800B9504: sub.s       $f14, $f8, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800B9508: jal         0x800E3F8C
    // 0x800B950C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_800E3F8C(rdram, ctx);
        goto after_16;
    // 0x800B950C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_16:
    // 0x800B9510: bne         $v0, $zero, L_800B94DC
    if (ctx->r2 != 0) {
        // 0x800B9514: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_800B94DC;
    }
    // 0x800B9514: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_800B9518:
    // 0x800B9518: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_800B951C:
    // 0x800B951C: jal         0x800EE7F8
    // 0x800B9520: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_17;
    // 0x800B9520: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_17:
    // 0x800B9524: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x800B9528: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B952C: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800B9530: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B9534: jal         0x800DC178
    // 0x800B9538: nop

    func_800DC178(rdram, ctx);
        goto after_18;
    // 0x800B9538: nop

    after_18:
    // 0x800B953C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800B9540: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800B9544: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B9548: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B954C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800B9550: jal         0x800EFA4C
    // 0x800B9554: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EFA4C(rdram, ctx);
        goto after_19;
    // 0x800B9554: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_19:
L_800B9558:
    // 0x800B9558: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B955C:
    // 0x800B955C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800B9560: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B9564: jr          $ra
    // 0x800B9568: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800B9568: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800A0714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0714: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A0718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A071C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A0720: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A0724: jal         0x800DF3E0
    // 0x800A0728: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800DF3E0(rdram, ctx);
        goto after_0;
    // 0x800A0728: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A072C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0730: slti        $at, $a1, 0x666
    ctx->r1 = SIGNED(ctx->r5) < 0X666 ? 1 : 0;
    // 0x800A0734: bne         $at, $zero, L_800A0778
    if (ctx->r1 != 0) {
        // 0x800A0738: slti        $at, $a1, 0x83B
        ctx->r1 = SIGNED(ctx->r5) < 0X83B ? 1 : 0;
            goto L_800A0778;
    }
    // 0x800A0738: slti        $at, $a1, 0x83B
    ctx->r1 = SIGNED(ctx->r5) < 0X83B ? 1 : 0;
    // 0x800A073C: bne         $at, $zero, L_800A0764
    if (ctx->r1 != 0) {
        // 0x800A0740: addiu       $t6, $a1, -0x984
        ctx->r14 = ADD32(ctx->r5, -0X984);
            goto L_800A0764;
    }
    // 0x800A0740: addiu       $t6, $a1, -0x984
    ctx->r14 = ADD32(ctx->r5, -0X984);
    // 0x800A0744: sltiu       $at, $t6, 0x15
    ctx->r1 = ctx->r14 < 0X15 ? 1 : 0;
    // 0x800A0748: beq         $at, $zero, L_800A0C0C
    if (ctx->r1 == 0) {
        // 0x800A074C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800A0C0C;
    }
    // 0x800A074C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800A0750: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0754: addu        $at, $at, $t6
    gpr jr_addend_800A075C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A0758: lw          $t6, 0x53B0($at)
    ctx->r14 = ADD32(ctx->r1, 0X53B0);
    // 0x800A075C: jr          $t6
    // 0x800A0760: nop

    switch (jr_addend_800A075C >> 2) {
        case 0: goto L_800A0BFC; break;
        case 1: goto L_800A0C0C; break;
        case 2: goto L_800A0BFC; break;
        case 3: goto L_800A0C0C; break;
        case 4: goto L_800A0B94; break;
        case 5: goto L_800A0C0C; break;
        case 6: goto L_800A0C0C; break;
        case 7: goto L_800A0C0C; break;
        case 8: goto L_800A0C0C; break;
        case 9: goto L_800A0BD8; break;
        case 10: goto L_800A0C0C; break;
        case 11: goto L_800A0C0C; break;
        case 12: goto L_800A0C0C; break;
        case 13: goto L_800A0C0C; break;
        case 14: goto L_800A07B8; break;
        case 15: goto L_800A094C; break;
        case 16: goto L_800A0C0C; break;
        case 17: goto L_800A0C0C; break;
        case 18: goto L_800A0C0C; break;
        case 19: goto L_800A0C0C; break;
        case 20: goto L_800A0B34; break;
        default: switch_error(__func__, 0x800A075C, 0x801253B0);
    }
    // 0x800A0760: nop

L_800A0764:
    // 0x800A0764: addiu       $at, $zero, 0x83A
    ctx->r1 = ADD32(0, 0X83A);
    // 0x800A0768: beql        $a1, $at, L_800A0950
    if (ctx->r5 == ctx->r1) {
        // 0x800A076C: lw          $t3, 0x138($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X138);
            goto L_800A0950;
    }
    goto skip_0;
    // 0x800A076C: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
    skip_0:
    // 0x800A0770: b           L_800A0C10
    // 0x800A0774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A0C10;
    // 0x800A0774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A0778:
    // 0x800A0778: slti        $at, $a1, 0x627
    ctx->r1 = SIGNED(ctx->r5) < 0X627 ? 1 : 0;
    // 0x800A077C: bne         $at, $zero, L_800A0798
    if (ctx->r1 != 0) {
        // 0x800A0780: addiu       $t7, $a1, -0x607
        ctx->r15 = ADD32(ctx->r5, -0X607);
            goto L_800A0798;
    }
    // 0x800A0780: addiu       $t7, $a1, -0x607
    ctx->r15 = ADD32(ctx->r5, -0X607);
    // 0x800A0784: addiu       $at, $zero, 0x665
    ctx->r1 = ADD32(0, 0X665);
    // 0x800A0788: beql        $a1, $at, L_800A0A24
    if (ctx->r5 == ctx->r1) {
        // 0x800A078C: lw          $t1, 0x138($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X138);
            goto L_800A0A24;
    }
    goto skip_1;
    // 0x800A078C: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    skip_1:
    // 0x800A0790: b           L_800A0C10
    // 0x800A0794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A0C10;
    // 0x800A0794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A0798:
    // 0x800A0798: sltiu       $at, $t7, 0x20
    ctx->r1 = ctx->r15 < 0X20 ? 1 : 0;
    // 0x800A079C: beq         $at, $zero, L_800A0C0C
    if (ctx->r1 == 0) {
        // 0x800A07A0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800A0C0C;
    }
    // 0x800A07A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A07A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A07A8: addu        $at, $at, $t7
    gpr jr_addend_800A07B0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800A07AC: lw          $t7, 0x5404($at)
    ctx->r15 = ADD32(ctx->r1, 0X5404);
    // 0x800A07B0: jr          $t7
    // 0x800A07B4: nop

    switch (jr_addend_800A07B0 >> 2) {
        case 0: goto L_800A07B8; break;
        case 1: goto L_800A07B8; break;
        case 2: goto L_800A0AD4; break;
        case 3: goto L_800A0C0C; break;
        case 4: goto L_800A0B34; break;
        case 5: goto L_800A0B34; break;
        case 6: goto L_800A0A74; break;
        case 7: goto L_800A0C0C; break;
        case 8: goto L_800A0C0C; break;
        case 9: goto L_800A0C0C; break;
        case 10: goto L_800A0C0C; break;
        case 11: goto L_800A0C0C; break;
        case 12: goto L_800A0C0C; break;
        case 13: goto L_800A0C0C; break;
        case 14: goto L_800A0C0C; break;
        case 15: goto L_800A0C0C; break;
        case 16: goto L_800A0C0C; break;
        case 17: goto L_800A0C0C; break;
        case 18: goto L_800A0C0C; break;
        case 19: goto L_800A0C0C; break;
        case 20: goto L_800A0C0C; break;
        case 21: goto L_800A094C; break;
        case 22: goto L_800A0C0C; break;
        case 23: goto L_800A0C0C; break;
        case 24: goto L_800A07B8; break;
        case 25: goto L_800A0C0C; break;
        case 26: goto L_800A0C0C; break;
        case 27: goto L_800A0C0C; break;
        case 28: goto L_800A0B34; break;
        case 29: goto L_800A0B34; break;
        case 30: goto L_800A0C0C; break;
        case 31: goto L_800A0B34; break;
        default: switch_error(__func__, 0x800A07B0, 0x80125404);
    }
    // 0x800A07B4: nop

L_800A07B8:
    // 0x800A07B8: lw          $v0, 0x138($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X138);
    // 0x800A07BC: lbu         $t8, 0x17($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X17);
    // 0x800A07C0: bne         $t8, $zero, L_800A0898
    if (ctx->r24 != 0) {
        // 0x800A07C4: addiu       $a0, $zero, 0x9
        ctx->r4 = ADD32(0, 0X9);
            goto L_800A0898;
    }
    // 0x800A07C4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x800A07C8: jal         0x800DF744
    // 0x800A07CC: lbu         $a1, 0x10($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X10);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x800A07CC: lbu         $a1, 0x10($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X10);
    after_1:
    // 0x800A07D0: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x800A07D4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x800A07D8: jal         0x800DF744
    // 0x800A07DC: lbu         $a1, 0x10($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X10);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x800A07DC: lbu         $a1, 0x10($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X10);
    after_2:
    // 0x800A07E0: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
    // 0x800A07E4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800A07E8: jal         0x800DF744
    // 0x800A07EC: lbu         $a1, 0xE($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0XE);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x800A07EC: lbu         $a1, 0xE($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0XE);
    after_3:
    // 0x800A07F0: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    // 0x800A07F4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800A07F8: jal         0x800DF744
    // 0x800A07FC: lbu         $a1, 0xE($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0XE);
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x800A07FC: lbu         $a1, 0xE($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0XE);
    after_4:
    // 0x800A0800: lw          $t2, 0x138($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X138);
    // 0x800A0804: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x800A0808: jal         0x800DF744
    // 0x800A080C: lbu         $a1, 0xD($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0XD);
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x800A080C: lbu         $a1, 0xD($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0XD);
    after_5:
    // 0x800A0810: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
    // 0x800A0814: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x800A0818: jal         0x800DF744
    // 0x800A081C: lbu         $a1, 0xD($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0XD);
    func_800DF744(rdram, ctx);
        goto after_6;
    // 0x800A081C: lbu         $a1, 0xD($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0XD);
    after_6:
    // 0x800A0820: lw          $t4, 0x138($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X138);
    // 0x800A0824: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x800A0828: lbu         $a1, 0xF($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0XF);
    // 0x800A082C: jal         0x800DF744
    // 0x800A0830: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DF744(rdram, ctx);
        goto after_7;
    // 0x800A0830: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_7:
    // 0x800A0834: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x800A0838: jal         0x800DF744
    // 0x800A083C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DF744(rdram, ctx);
        goto after_8;
    // 0x800A083C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x800A0840: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x800A0844: jal         0x800DF744
    // 0x800A0848: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DF744(rdram, ctx);
        goto after_9;
    // 0x800A0848: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x800A084C: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800A0850: jal         0x800DF744
    // 0x800A0854: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DF744(rdram, ctx);
        goto after_10;
    // 0x800A0854: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x800A0858: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
    // 0x800A085C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x800A0860: lbu         $a1, 0x11($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X11);
    // 0x800A0864: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A0868: jal         0x800DF744
    // 0x800A086C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DF744(rdram, ctx);
        goto after_11;
    // 0x800A086C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_11:
    // 0x800A0870: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x800A0874: jal         0x800DF744
    // 0x800A0878: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DF744(rdram, ctx);
        goto after_12;
    // 0x800A0878: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_12:
    // 0x800A087C: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x800A0880: jal         0x800DF744
    // 0x800A0884: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DF744(rdram, ctx);
        goto after_13;
    // 0x800A0884: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_13:
    // 0x800A0888: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x800A088C: jal         0x800DF744
    // 0x800A0890: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DF744(rdram, ctx);
        goto after_14;
    // 0x800A0890: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_14:
    // 0x800A0894: lw          $v0, 0x138($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X138);
L_800A0898:
    // 0x800A0898: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800A089C: jal         0x800DF744
    // 0x800A08A0: lbu         $a1, 0x12($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X12);
    func_800DF744(rdram, ctx);
        goto after_15;
    // 0x800A08A0: lbu         $a1, 0x12($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X12);
    after_15:
    // 0x800A08A4: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x800A08A8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A08AC: jal         0x800DF744
    // 0x800A08B0: lbu         $a1, 0x12($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X12);
    func_800DF744(rdram, ctx);
        goto after_16;
    // 0x800A08B0: lbu         $a1, 0x12($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X12);
    after_16:
    // 0x800A08B4: lw          $t7, 0x138($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X138);
    // 0x800A08B8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800A08BC: jal         0x800DF744
    // 0x800A08C0: lbu         $a1, 0x12($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X12);
    func_800DF744(rdram, ctx);
        goto after_17;
    // 0x800A08C0: lbu         $a1, 0x12($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X12);
    after_17:
    // 0x800A08C4: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x800A08C8: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x800A08CC: jal         0x800DF744
    // 0x800A08D0: lbu         $a1, 0x12($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X12);
    func_800DF744(rdram, ctx);
        goto after_18;
    // 0x800A08D0: lbu         $a1, 0x12($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X12);
    after_18:
    // 0x800A08D4: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x800A08D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A08DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A08E0: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x800A08E4: jal         0x800F1214
    // 0x800A08E8: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    func_800F1214(rdram, ctx);
        goto after_19;
    // 0x800A08E8: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    after_19:
    // 0x800A08EC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A08F0: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x800A08F4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800A08F8: jal         0x800DF744
    // 0x800A08FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DF744(rdram, ctx);
        goto after_20;
    // 0x800A08FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_20:
    // 0x800A0900: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x800A0904: jal         0x800DF744
    // 0x800A0908: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DF744(rdram, ctx);
        goto after_21;
    // 0x800A0908: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_21:
    // 0x800A090C: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    // 0x800A0910: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A0914: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A0918: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x800A091C: jal         0x800F1214
    // 0x800A0920: lwc1        $f12, 0x4($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X4);
    func_800F1214(rdram, ctx);
        goto after_22;
    // 0x800A0920: lwc1        $f12, 0x4($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X4);
    after_22:
    // 0x800A0924: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A0928: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x800A092C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A0930: jal         0x800DF744
    // 0x800A0934: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DF744(rdram, ctx);
        goto after_23;
    // 0x800A0934: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_23:
    // 0x800A0938: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x800A093C: jal         0x800DF744
    // 0x800A0940: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DF744(rdram, ctx);
        goto after_24;
    // 0x800A0940: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_24:
    // 0x800A0944: b           L_800A0C10
    // 0x800A0948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A0C10;
    // 0x800A0948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A094C:
    // 0x800A094C: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
L_800A0950:
    // 0x800A0950: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A0954: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800A0958: lbu         $t4, 0x15($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X15);
    // 0x800A095C: beq         $t4, $zero, L_800A0974
    if (ctx->r12 == 0) {
        // 0x800A0960: nop
    
            goto L_800A0974;
    }
    // 0x800A0960: nop

    // 0x800A0964: jal         0x800DF744
    // 0x800A0968: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_25;
    // 0x800A0968: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_25:
    // 0x800A096C: b           L_800A0980
    // 0x800A0970: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
        goto L_800A0980;
    // 0x800A0970: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
L_800A0974:
    // 0x800A0974: jal         0x800DF744
    // 0x800A0978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_26;
    // 0x800A0978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x800A097C: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
L_800A0980:
    // 0x800A0980: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800A0984: lbu         $a1, 0xF($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0XF);
    // 0x800A0988: jal         0x800DF744
    // 0x800A098C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DF744(rdram, ctx);
        goto after_27;
    // 0x800A098C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_27:
    // 0x800A0990: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800A0994: jal         0x800DF744
    // 0x800A0998: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DF744(rdram, ctx);
        goto after_28;
    // 0x800A0998: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_28:
    // 0x800A099C: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x800A09A0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A09A4: lbu         $a1, 0x11($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X11);
    // 0x800A09A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A09AC: jal         0x800DF744
    // 0x800A09B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DF744(rdram, ctx);
        goto after_29;
    // 0x800A09B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_29:
    // 0x800A09B4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800A09B8: jal         0x800DF744
    // 0x800A09BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DF744(rdram, ctx);
        goto after_30;
    // 0x800A09BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_30:
    // 0x800A09C0: lw          $t7, 0x138($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X138);
    // 0x800A09C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A09C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A09CC: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x800A09D0: jal         0x800F1214
    // 0x800A09D4: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    func_800F1214(rdram, ctx);
        goto after_31;
    // 0x800A09D4: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    after_31:
    // 0x800A09D8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A09DC: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x800A09E0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800A09E4: jal         0x800DF744
    // 0x800A09E8: nop

    func_800DF744(rdram, ctx);
        goto after_32;
    // 0x800A09E8: nop

    after_32:
    // 0x800A09EC: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x800A09F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A09F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A09F8: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x800A09FC: jal         0x800F1214
    // 0x800A0A00: lwc1        $f12, 0x4($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X4);
    func_800F1214(rdram, ctx);
        goto after_33;
    // 0x800A0A00: lwc1        $f12, 0x4($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X4);
    after_33:
    // 0x800A0A04: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A0A08: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800A0A0C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A0A10: jal         0x800DF744
    // 0x800A0A14: nop

    func_800DF744(rdram, ctx);
        goto after_34;
    // 0x800A0A14: nop

    after_34:
    // 0x800A0A18: b           L_800A0C10
    // 0x800A0A1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A0C10;
    // 0x800A0A1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A0A20: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
L_800A0A24:
    // 0x800A0A24: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A0A28: jal         0x800DF744
    // 0x800A0A2C: lbu         $a1, 0x13($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X13);
    func_800DF744(rdram, ctx);
        goto after_35;
    // 0x800A0A2C: lbu         $a1, 0x13($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0X13);
    after_35:
    // 0x800A0A30: lw          $t2, 0x138($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X138);
    // 0x800A0A34: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800A0A38: jal         0x800DF744
    // 0x800A0A3C: lbu         $a1, 0x14($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X14);
    func_800DF744(rdram, ctx);
        goto after_36;
    // 0x800A0A3C: lbu         $a1, 0x14($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X14);
    after_36:
    // 0x800A0A40: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
    // 0x800A0A44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A0A48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A0A4C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x800A0A50: jal         0x800F1214
    // 0x800A0A54: lwc1        $f12, 0x4($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X4);
    func_800F1214(rdram, ctx);
        goto after_37;
    // 0x800A0A54: lwc1        $f12, 0x4($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X4);
    after_37:
    // 0x800A0A58: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A0A5C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A0A60: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800A0A64: jal         0x800DF744
    // 0x800A0A68: nop

    func_800DF744(rdram, ctx);
        goto after_38;
    // 0x800A0A68: nop

    after_38:
    // 0x800A0A6C: b           L_800A0C10
    // 0x800A0A70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A0C10;
    // 0x800A0A70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A0A74:
    // 0x800A0A74: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
    // 0x800A0A78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A0A7C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A0A80: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x800A0A84: jal         0x800F1214
    // 0x800A0A88: lwc1        $f12, 0x0($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X0);
    func_800F1214(rdram, ctx);
        goto after_39;
    // 0x800A0A88: lwc1        $f12, 0x0($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X0);
    after_39:
    // 0x800A0A8C: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A0A90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A0A94: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800A0A98: jal         0x800DF744
    // 0x800A0A9C: nop

    func_800DF744(rdram, ctx);
        goto after_40;
    // 0x800A0A9C: nop

    after_40:
    // 0x800A0AA0: lw          $t7, 0x138($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X138);
    // 0x800A0AA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A0AA8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A0AAC: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x800A0AB0: jal         0x800F1214
    // 0x800A0AB4: lwc1        $f12, 0x4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X4);
    func_800F1214(rdram, ctx);
        goto after_41;
    // 0x800A0AB4: lwc1        $f12, 0x4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X4);
    after_41:
    // 0x800A0AB8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A0ABC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800A0AC0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800A0AC4: jal         0x800DF744
    // 0x800A0AC8: nop

    func_800DF744(rdram, ctx);
        goto after_42;
    // 0x800A0AC8: nop

    after_42:
    // 0x800A0ACC: b           L_800A0C10
    // 0x800A0AD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A0C10;
    // 0x800A0AD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A0AD4:
    // 0x800A0AD4: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x800A0AD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A0ADC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A0AE0: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x800A0AE4: jal         0x800F1214
    // 0x800A0AE8: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    func_800F1214(rdram, ctx);
        goto after_43;
    // 0x800A0AE8: lwc1        $f12, 0x0($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X0);
    after_43:
    // 0x800A0AEC: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A0AF0: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x800A0AF4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A0AF8: jal         0x800DF744
    // 0x800A0AFC: nop

    func_800DF744(rdram, ctx);
        goto after_44;
    // 0x800A0AFC: nop

    after_44:
    // 0x800A0B00: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    // 0x800A0B04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A0B08: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A0B0C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x800A0B10: jal         0x800F1214
    // 0x800A0B14: lwc1        $f12, 0x4($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X4);
    func_800F1214(rdram, ctx);
        goto after_45;
    // 0x800A0B14: lwc1        $f12, 0x4($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X4);
    after_45:
    // 0x800A0B18: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A0B1C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800A0B20: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800A0B24: jal         0x800DF744
    // 0x800A0B28: nop

    func_800DF744(rdram, ctx);
        goto after_46;
    // 0x800A0B28: nop

    after_46:
    // 0x800A0B2C: b           L_800A0C10
    // 0x800A0B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A0C10;
    // 0x800A0B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A0B34:
    // 0x800A0B34: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
    // 0x800A0B38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A0B3C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A0B40: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x800A0B44: jal         0x800F1214
    // 0x800A0B48: lwc1        $f12, 0x0($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X0);
    func_800F1214(rdram, ctx);
        goto after_47;
    // 0x800A0B48: lwc1        $f12, 0x0($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X0);
    after_47:
    // 0x800A0B4C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A0B50: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x800A0B54: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A0B58: jal         0x800DF744
    // 0x800A0B5C: nop

    func_800DF744(rdram, ctx);
        goto after_48;
    // 0x800A0B5C: nop

    after_48:
    // 0x800A0B60: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
    // 0x800A0B64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A0B68: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800A0B6C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x800A0B70: jal         0x800F1214
    // 0x800A0B74: lwc1        $f12, 0x4($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X4);
    func_800F1214(rdram, ctx);
        goto after_49;
    // 0x800A0B74: lwc1        $f12, 0x4($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X4);
    after_49:
    // 0x800A0B78: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800A0B7C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800A0B80: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800A0B84: jal         0x800DF744
    // 0x800A0B88: nop

    func_800DF744(rdram, ctx);
        goto after_50;
    // 0x800A0B88: nop

    after_50:
    // 0x800A0B8C: b           L_800A0C10
    // 0x800A0B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A0C10;
    // 0x800A0B90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A0B94:
    // 0x800A0B94: jal         0x800A940C
    // 0x800A0B98: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800A940C(rdram, ctx);
        goto after_51;
    // 0x800A0B98: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_51:
    // 0x800A0B9C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A0BA0: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800A0BA4: lbu         $a1, -0x6DB0($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X6DB0);
    // 0x800A0BA8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800A0BAC: jal         0x800DF744
    // 0x800A0BB0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800DF744(rdram, ctx);
        goto after_52;
    // 0x800A0BB0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_52:
    // 0x800A0BB4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A0BB8: jal         0x800DF744
    // 0x800A0BBC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800DF744(rdram, ctx);
        goto after_53;
    // 0x800A0BBC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_53:
    // 0x800A0BC0: lw          $t7, 0x138($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X138);
    // 0x800A0BC4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800A0BC8: jal         0x800DF744
    // 0x800A0BCC: lbu         $a1, 0x16($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X16);
    func_800DF744(rdram, ctx);
        goto after_54;
    // 0x800A0BCC: lbu         $a1, 0x16($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X16);
    after_54:
    // 0x800A0BD0: b           L_800A0C10
    // 0x800A0BD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A0C10;
    // 0x800A0BD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A0BD8:
    // 0x800A0BD8: jal         0x800A940C
    // 0x800A0BDC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    func_800A940C(rdram, ctx);
        goto after_55;
    // 0x800A0BDC: lw          $a0, 0x184($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X184);
    after_55:
    // 0x800A0BE0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A0BE4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800A0BE8: lbu         $a1, -0x6DAC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X6DAC);
    // 0x800A0BEC: jal         0x800DF744
    // 0x800A0BF0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_56;
    // 0x800A0BF0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_56:
    // 0x800A0BF4: b           L_800A0C10
    // 0x800A0BF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800A0C10;
    // 0x800A0BF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A0BFC:
    // 0x800A0BFC: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x800A0C00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A0C04: jal         0x800DF744
    // 0x800A0C08: lbu         $a1, 0x16($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X16);
    func_800DF744(rdram, ctx);
        goto after_57;
    // 0x800A0C08: lbu         $a1, 0x16($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X16);
    after_57:
L_800A0C0C:
    // 0x800A0C0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800A0C10:
    // 0x800A0C10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A0C14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800A0C18: jr          $ra
    // 0x800A0C1C: nop

    return;
    // 0x800A0C1C: nop

;}
RECOMP_FUNC void func_80809D6C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809D6C: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80809D70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80809D74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80809D78: lw          $t6, 0x254($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X254);
    // 0x80809D7C: bne         $t6, $at, L_80809D8C
    if (ctx->r14 != ctx->r1) {
        // 0x80809D80: nop
    
            goto L_80809D8C;
    }
    // 0x80809D80: nop

    // 0x80809D84: jr          $ra
    // 0x80809D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80809D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80809D8C:
    // 0x80809D8C: jr          $ra
    // 0x80809D90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80809D90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800E4730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E4730: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E4734: lw          $v0, -0x2AA0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AA0);
    // 0x800E4738: beq         $v0, $zero, L_800E4754
    if (ctx->r2 == 0) {
        // 0x800E473C: nop
    
            goto L_800E4754;
    }
    // 0x800E473C: nop

    // 0x800E4740: lh          $t6, 0x3A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X3A);
    // 0x800E4744: bne         $a0, $t6, L_800E4754
    if (ctx->r4 != ctx->r14) {
        // 0x800E4748: nop
    
            goto L_800E4754;
    }
    // 0x800E4748: nop

    // 0x800E474C: jr          $ra
    // 0x800E4750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800E4750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E4754:
    // 0x800E4754: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E4758: lw          $v0, -0x2A9C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2A9C);
    // 0x800E475C: beq         $v0, $zero, L_800E4778
    if (ctx->r2 == 0) {
        // 0x800E4760: nop
    
            goto L_800E4778;
    }
    // 0x800E4760: nop

    // 0x800E4764: lh          $t7, 0x3A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X3A);
    // 0x800E4768: bne         $a0, $t7, L_800E4778
    if (ctx->r4 != ctx->r15) {
        // 0x800E476C: nop
    
            goto L_800E4778;
    }
    // 0x800E476C: nop

    // 0x800E4770: jr          $ra
    // 0x800E4774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E4774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E4778:
    // 0x800E4778: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E477C: lw          $v0, -0x2A98($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2A98);
    // 0x800E4780: beq         $v0, $zero, L_800E479C
    if (ctx->r2 == 0) {
        // 0x800E4784: nop
    
            goto L_800E479C;
    }
    // 0x800E4784: nop

    // 0x800E4788: lh          $t8, 0x3A($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X3A);
    // 0x800E478C: bne         $a0, $t8, L_800E479C
    if (ctx->r4 != ctx->r24) {
        // 0x800E4790: nop
    
            goto L_800E479C;
    }
    // 0x800E4790: nop

    // 0x800E4794: jr          $ra
    // 0x800E4798: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x800E4798: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800E479C:
    // 0x800E479C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E47A0: lw          $v0, -0x2A94($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2A94);
    // 0x800E47A4: beql        $v0, $zero, L_800E47C4
    if (ctx->r2 == 0) {
        // 0x800E47A8: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800E47C4;
    }
    goto skip_0;
    // 0x800E47A8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x800E47AC: lh          $t9, 0x3A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X3A);
    // 0x800E47B0: bnel        $a0, $t9, L_800E47C4
    if (ctx->r4 != ctx->r25) {
        // 0x800E47B4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800E47C4;
    }
    goto skip_1;
    // 0x800E47B4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x800E47B8: jr          $ra
    // 0x800E47BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x800E47BC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800E47C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800E47C4:
    // 0x800E47C4: jr          $ra
    // 0x800E47C8: nop

    return;
    // 0x800E47C8: nop

;}
RECOMP_FUNC void func_80017210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017210: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80017214: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80017218: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001721C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80017220: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80017224: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017228: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001722C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017230: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x80017234: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80017238: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001723C: jr          $ra
    // 0x80017240: lw          $v0, -0x5E54($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E54);
    return;
    // 0x80017240: lw          $v0, -0x5E54($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E54);
;}
RECOMP_FUNC void bsstonehead_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801318: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080131C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(376, 0X16B0) << 16);
    // 0x80801320: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801324: jr          $ra
    // 0x80801328: lw          $v0, 0x16B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X16B0));
    return;
    // 0x80801328: lw          $v0, 0x16B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(376, 0X16B0));
;}
RECOMP_FUNC void func_80800000_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800004: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800014: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80800018: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8080001C: jal         0x80100094
    // 0x80800020: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800024: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800028: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080002C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80800030: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80800034: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800038: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x8080003C: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800040: beq         $v0, $zero, L_80800064
    if (ctx->r2 == 0) {
        // 0x80800044: swc1        $f10, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
            goto L_80800064;
    }
    // 0x80800044: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x80800048: jal         0x80089890
    // 0x8080004C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x8080004C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800054: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800058: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8080005C: jal         0x800DF5D8
    // 0x80800060: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800DF5D8(rdram, ctx);
        goto after_2;
    // 0x80800060: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
L_80800064:
    // 0x80800064: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x80800068: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080006C: jal         0x800EE7F8
    // 0x80800070: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800070: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_3:
    // 0x80800074: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800078: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080007C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800080: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800084: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    // 0x80800088: jal         0x800EF5A0
    // 0x8080008C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800EF5A0(rdram, ctx);
        goto after_4;
    // 0x8080008C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80800090: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800094: jal         0x800EF04C
    // 0x80800098: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x80800098: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_5:
    // 0x8080009C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808000A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808000A4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808000A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000AC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x808000B0: beq         $s2, $zero, L_808000C0
    if (ctx->r18 == 0) {
        // 0x808000B4: swc1        $f4, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
            goto L_808000C0;
    }
    // 0x808000B4: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x808000B8: jal         0x80089888
    // 0x808000BC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    _sumumbofx_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x808000BC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_6:
L_808000C0:
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: jal         0x80101870
    // 0x808000C8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_80101870(rdram, ctx);
        goto after_7;
    // 0x808000C8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_7:
    // 0x808000CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000D0: jal         0x800EE7F8
    // 0x808000D4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x808000D4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    after_8:
    // 0x808000D8: beq         $s2, $zero, L_808000E8
    if (ctx->r18 == 0) {
        // 0x808000DC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808000E8;
    }
    // 0x808000DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808000E0: jal         0x80089880
    // 0x808000E4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    _sumumbofx_entrypoint_8(rdram, ctx);
        goto after_9;
    // 0x808000E4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_9:
L_808000E8:
    // 0x808000E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808000EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000F0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808000F4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808000F8: jr          $ra
    // 0x808000FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808000FC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void vector_assign(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2F20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800B2F24: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800B2F28: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x800B2F2C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800B2F30: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B2F34: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800B2F38: mflo        $t8
    ctx->r24 = lo;
    // 0x800B2F3C: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x800B2F40: jal         0x8001BBC8
    // 0x800B2F44: nop

    aligned4_memcpy(rdram, ctx);
        goto after_0;
    // 0x800B2F44: nop

    after_0:
    // 0x800B2F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B2F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B2F50: jr          $ra
    // 0x800B2F54: nop

    return;
    // 0x800B2F54: nop

;}
RECOMP_FUNC void func_800EFA6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFA6C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800EFA70: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800EFA74: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800EFA78: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x800EFA7C: sh          $a2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r6;
    // 0x800EFA80: jr          $ra
    // 0x800EFA84: sh          $a3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r7;
    return;
    // 0x800EFA84: sh          $a3, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_80025F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025F70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80025F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025F78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80025F7C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80025F80: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80025F84: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80025F88: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80025F8C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80025F90: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80025F94: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80025F98: lbu         $t8, 0x2F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X2F);
    // 0x80025F9C: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80025FA0: addiu       $t9, $zero, 0x5B
    ctx->r25 = ADD32(0, 0X5B);
    // 0x80025FA4: sb          $t9, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r25;
    // 0x80025FA8: lbu         $t0, 0x33($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X33);
    // 0x80025FAC: sb          $t0, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r8;
    // 0x80025FB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80025FB4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80025FB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025FBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80025FC0: jal         0x80026500
    // 0x80025FC4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    func_80026500(rdram, ctx);
        goto after_0;
    // 0x80025FC4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x80025FC8: b           L_80025FD0
    // 0x80025FCC: nop

        goto L_80025FD0;
    // 0x80025FCC: nop

L_80025FD0:
    // 0x80025FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025FD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80025FD8: jr          $ra
    // 0x80025FDC: nop

    return;
    // 0x80025FDC: nop

;}
RECOMP_FUNC void _gcdialogcamera_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088098: syscall     669
    recomp_syscall_handler(rdram, ctx, 0x80088098);
    return;
    // 0x8008809C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _plcamera_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087928: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x80087928);
    return;
    // 0x8008792C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_800D3524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3524: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800D3528: addiu       $t7, $t7, -0x4AA0
    ctx->r15 = ADD32(ctx->r15, -0X4AA0);
    // 0x800D352C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800D3530: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800D3534: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x800D3538: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D353C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3540: bnel        $a1, $zero, L_800D3564
    if (ctx->r5 != 0) {
        // 0x800D3544: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D3564;
    }
    goto skip_0;
    // 0x800D3544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D3548: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x800D354C: jal         0x800D674C
    // 0x800D3550: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x800D3550: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800D3554: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800D3558: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800D355C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x800D3560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D3564:
    // 0x800D3564: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3568: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800D356C: jr          $ra
    // 0x800D3570: nop

    return;
    // 0x800D3570: nop

;}
RECOMP_FUNC void ncpodfixpos_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800334: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800338: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080033C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800340: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80800344: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80800348: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080034C: jal         0x808000F0
    // 0x80800350: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    ncpodfixpos_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800350: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800354: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x80800358: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080035C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800360: beql        $v1, $zero, L_808003F0
    if (ctx->r3 == 0) {
        // 0x80800364: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003F0;
    }
    goto skip_0;
    // 0x80800364: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800368: bnel        $v1, $at, L_808003F0
    if (ctx->r3 != ctx->r1) {
        // 0x8080036C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003F0;
    }
    goto skip_1;
    // 0x8080036C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800370: jal         0x80110024
    // 0x80800374: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_80110024(rdram, ctx);
        goto after_1;
    // 0x80800374: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x80800378: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8080037C: jal         0x808001A8
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001A8_ncpodfixpos(rdram, ctx);
        goto after_2;
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800384: beq         $v0, $zero, L_808003A8
    if (ctx->r2 == 0) {
        // 0x80800388: addiu       $a0, $s0, 0x20
        ctx->r4 = ADD32(ctx->r16, 0X20);
            goto L_808003A8;
    }
    // 0x80800388: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x8080038C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800390: jal         0x800F18FC
    // 0x80800394: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    func_800F18FC(rdram, ctx);
        goto after_3;
    // 0x80800394: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    after_3:
    // 0x80800398: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8080039C: jal         0x800136E4
    // 0x808003A0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x808003A0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_4:
    // 0x808003A4: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_808003A8:
    // 0x808003A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808003AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003B0: jal         0x80089500
    // 0x808003B4: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    _ncpod_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x808003B4: addiu       $a2, $s0, 0xC
    ctx->r6 = ADD32(ctx->r16, 0XC);
    after_5:
    // 0x808003B8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808003BC: jal         0x80089508
    // 0x808003C0: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    _ncpod_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x808003C0: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    after_6:
    // 0x808003C4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808003C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003CC: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x808003D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808003D4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x808003D8: nop

    // 0x808003DC: bc1fl       L_808003F0
    if (!c1cs) {
        // 0x808003E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003F0;
    }
    goto skip_2;
    // 0x808003E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808003E4: jal         0x80089518
    // 0x808003E8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    _ncpod_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x808003E8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    after_7:
    // 0x808003EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003F0:
    // 0x808003F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808003F8: jr          $ra
    // 0x808003FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x808003FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
;}
RECOMP_FUNC void func_80800068_chfactorybtwmdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800068: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080006C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800070: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800074: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800078: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080007C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800080: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800084: beq         $t6, $at, L_808000A8
    if (ctx->r14 == ctx->r1) {
        // 0x80800088: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808000A8;
    }
    // 0x80800088: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080008C: beq         $t6, $at, L_8080020C
    if (ctx->r14 == ctx->r1) {
        // 0x80800090: addiu       $a0, $s0, 0x58
        ctx->r4 = ADD32(ctx->r16, 0X58);
            goto L_8080020C;
    }
    // 0x80800090: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80800094: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800098: beq         $t6, $at, L_80800274
    if (ctx->r14 == ctx->r1) {
        // 0x8080009C: nop
    
            goto L_80800274;
    }
    // 0x8080009C: nop

    // 0x808000A0: b           L_808002D4
    // 0x808000A4: nop

        goto L_808002D4;
    // 0x808000A4: nop

L_808000A8:
    // 0x808000A8: jal         0x800D90A4
    // 0x808000AC: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x808000AC: addiu       $a0, $s0, 0x24
    ctx->r4 = ADD32(ctx->r16, 0X24);
    after_0:
    // 0x808000B0: beq         $v0, $zero, L_808002D4
    if (ctx->r2 == 0) {
        // 0x808000B4: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_808002D4;
    }
    // 0x808000B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C0: jal         0x8010C500
    // 0x808000C4: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    func_8010C500(rdram, ctx);
        goto after_1;
    // 0x808000C4: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x808000C8: beq         $v0, $zero, L_808001A4
    if (ctx->r2 == 0) {
        // 0x808000CC: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_808001A4;
    }
    // 0x808000CC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808000D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000D4: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808000D8: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x808000DC: nop

    // 0x808000E0: bc1t        L_808001A4
    if (c1cs) {
        // 0x808000E4: nop
    
            goto L_808001A4;
    }
    // 0x808000E4: nop

    // 0x808000E8: jal         0x800F54E4
    // 0x808000EC: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808000EC: nop

    after_2:
    // 0x808000F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000F4: jal         0x800F64A4
    // 0x808000F8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x808000F8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_3:
    // 0x808000FC: beql        $v0, $zero, L_80800168
    if (ctx->r2 == 0) {
        // 0x80800100: lw          $t4, 0x74($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X74);
            goto L_80800168;
    }
    goto skip_0;
    // 0x80800100: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x80800104: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80800108: addiu       $a1, $zero, 0x1336
    ctx->r5 = ADD32(0, 0X1336);
    // 0x8080010C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800110: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80800114: bltz        $t9, L_8080013C
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800118: addiu       $a3, $s0, 0x4
        ctx->r7 = ADD32(ctx->r16, 0X4);
            goto L_8080013C;
    }
    // 0x80800118: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x8080011C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800120: addiu       $t0, $zero, 0xA3
    ctx->r8 = ADD32(0, 0XA3);
    // 0x80800124: jal         0x8008A208
    // 0x80800128: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x80800128: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_4:
    // 0x8080012C: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x80800130: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x80800134: jal         0x80086B58
    // 0x80800138: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80800138: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    after_5:
L_8080013C:
    // 0x8080013C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2288, 0X338) << 16);
    // 0x80800140: addiu       $a2, $a2, 0x338
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2288, 0X338));
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800148: jal         0x80089D18
    // 0x8080014C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x8080014C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800154: jal         0x80101FDC
    // 0x80800158: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800158: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x8080015C: b           L_808002D4
    // 0x80800160: nop

        goto L_808002D4;
    // 0x80800160: nop

    // 0x80800164: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
L_80800168:
    // 0x80800168: addiu       $a1, $zero, 0x1335
    ctx->r5 = ADD32(0, 0X1335);
    // 0x8080016C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800170: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80800174: bltz        $t6, L_808002D4
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800178: addiu       $a3, $s0, 0x4
        ctx->r7 = ADD32(ctx->r16, 0X4);
            goto L_808002D4;
    }
    // 0x80800178: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x8080017C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800180: addiu       $t7, $zero, 0xA3
    ctx->r15 = ADD32(0, 0XA3);
    // 0x80800184: jal         0x8008A208
    // 0x80800188: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800188: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_8:
    // 0x8080018C: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
    // 0x80800190: ori         $t0, $t9, 0x20
    ctx->r8 = ctx->r25 | 0X20;
    // 0x80800194: jal         0x80086B58
    // 0x80800198: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
    _chmrtannoy_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80800198: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
    after_9:
    // 0x8080019C: b           L_808002D4
    // 0x808001A0: nop

        goto L_808002D4;
    // 0x808001A0: nop

L_808001A4:
    // 0x808001A4: jal         0x8010C500
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_10;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808001AC: beql        $v0, $zero, L_808001D4
    if (ctx->r2 == 0) {
        // 0x808001B0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_808001D4;
    }
    goto skip_1;
    // 0x808001B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
    // 0x808001B4: jal         0x800F54E4
    // 0x808001B8: nop

    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x808001B8: nop

    after_11:
    // 0x808001BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001C0: jal         0x800F64A4
    // 0x808001C4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_800F64A4(rdram, ctx);
        goto after_12;
    // 0x808001C4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_12:
    // 0x808001C8: bne         $v0, $zero, L_808002D4
    if (ctx->r2 != 0) {
        // 0x808001CC: nop
    
            goto L_808002D4;
    }
    // 0x808001CC: nop

    // 0x808001D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_808001D4:
    // 0x808001D4: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001DC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808001E0: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x808001E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2288, 0X338) << 16);
    // 0x808001E8: bc1t        L_808002D4
    if (c1cs) {
        // 0x808001EC: nop
    
            goto L_808002D4;
    }
    // 0x808001EC: nop

    // 0x808001F0: jal         0x80089D18
    // 0x808001F4: addiu       $a2, $a2, 0x338
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2288, 0X338));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x808001F4: addiu       $a2, $a2, 0x338
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2288, 0X338));
    after_13:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: jal         0x80101FDC
    // 0x80800200: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_14;
    // 0x80800200: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
    // 0x80800204: b           L_808002D4
    // 0x80800208: nop

        goto L_808002D4;
    // 0x80800208: nop

L_8080020C:
    // 0x8080020C: jal         0x800D91EC
    // 0x80800210: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    func_800D91EC(rdram, ctx);
        goto after_15;
    // 0x80800210: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_15:
    // 0x80800214: beq         $v0, $zero, L_80800258
    if (ctx->r2 == 0) {
        // 0x80800218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800258;
    }
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800220: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800228: jal         0x80089D40
    // 0x8080022C: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x8080022C: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    after_16:
    // 0x80800230: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2288, 0X32C) << 16);
    // 0x80800234: addiu       $a2, $a2, 0x32C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2288, 0X32C));
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x80089D18
    // 0x80800240: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_17;
    // 0x80800240: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_17:
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: jal         0x80101FDC
    // 0x8080024C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_18;
    // 0x8080024C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80800250: b           L_808002D4
    // 0x80800254: nop

        goto L_808002D4;
    // 0x80800254: nop

L_80800258:
    // 0x80800258: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2288, 0X320) << 16);
    // 0x8080025C: addiu       $a3, $a3, 0x320
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2288, 0X320));
    // 0x80800260: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800264: jal         0x80089D50
    // 0x80800268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_19;
    // 0x80800268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_19:
    // 0x8080026C: b           L_808002D4
    // 0x80800270: nop

        goto L_808002D4;
    // 0x80800270: nop

L_80800274:
    // 0x80800274: jal         0x800D90A4
    // 0x80800278: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_20;
    // 0x80800278: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_20:
    // 0x8080027C: beq         $v0, $zero, L_808002C0
    if (ctx->r2 == 0) {
        // 0x80800280: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002C0;
    }
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800288: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800290: jal         0x80089D40
    // 0x80800294: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_21;
    // 0x80800294: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_21:
    // 0x80800298: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2288, 0X32C) << 16);
    // 0x8080029C: addiu       $a2, $a2, 0x32C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2288, 0X32C));
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: jal         0x80089D18
    // 0x808002A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_22;
    // 0x808002A8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_22:
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: jal         0x80101FDC
    // 0x808002B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_23;
    // 0x808002B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x808002B8: b           L_808002D4
    // 0x808002BC: nop

        goto L_808002D4;
    // 0x808002BC: nop

L_808002C0:
    // 0x808002C0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(2288, 0X320) << 16);
    // 0x808002C4: addiu       $a3, $a3, 0x320
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(2288, 0X320));
    // 0x808002C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002CC: jal         0x80089D50
    // 0x808002D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_24;
    // 0x808002D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_24:
L_808002D4:
    // 0x808002D4: jal         0x80103EF4
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_25;
    // 0x808002D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808002DC: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808002E0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002E4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808002E8: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    // 0x808002EC: jal         0x800F10B4
    // 0x808002F0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800F10B4(rdram, ctx);
        goto after_26;
    // 0x808002F0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_26:
    // 0x808002F4: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808002F8: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x808002FC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80800300: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800304: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800308: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080030C: jr          $ra
    // 0x80800310: nop

    return;
    // 0x80800310: nop

;}
RECOMP_FUNC void func_800EBB6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EBB6C: jr          $ra
    // 0x800EBB70: nop

    return;
    // 0x800EBB70: nop

;}
RECOMP_FUNC void func_80800424_chcrystalbaddie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800424: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800428: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080042C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800430: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800434: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800438: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080043C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800440: nop

    // 0x80800444: bc1f        L_80800454
    if (!c1cs) {
        // 0x80800448: nop
    
            goto L_80800454;
    }
    // 0x80800448: nop

    // 0x8080044C: b           L_808004A0
    // 0x80800450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808004A0;
    // 0x80800450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800454:
    // 0x80800454: jal         0x80089F78
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800458: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080045C: beq         $v0, $zero, L_8080049C
    if (ctx->r2 == 0) {
        // 0x80800460: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_8080049C;
    }
    // 0x80800460: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800464: jal         0x8010C9B0
    // 0x80800468: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    func_8010C9B0(rdram, ctx);
        goto after_1;
    // 0x80800468: addiu       $a1, $zero, 0x4B0
    ctx->r5 = ADD32(0, 0X4B0);
    after_1:
    // 0x8080046C: beql        $v0, $zero, L_808004A0
    if (ctx->r2 == 0) {
        // 0x80800470: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808004A0;
    }
    goto skip_0;
    // 0x80800470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800474: jal         0x80089F00
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suchase_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080047C: beql        $v0, $zero, L_808004A0
    if (ctx->r2 == 0) {
        // 0x80800480: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808004A0;
    }
    goto skip_1;
    // 0x80800480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80800484: jal         0x8010C500
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_3;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080048C: beql        $v0, $zero, L_808004A0
    if (ctx->r2 == 0) {
        // 0x80800490: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808004A0;
    }
    goto skip_2;
    // 0x80800490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80800494: b           L_808004A0
    // 0x80800498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808004A0;
    // 0x80800498: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080049C:
    // 0x8080049C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004A0:
    // 0x808004A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004AC: jr          $ra
    // 0x808004B0: nop

    return;
    // 0x808004B0: nop

;}
RECOMP_FUNC void func_80800B68_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B68: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800B6C: slti        $at, $a1, 0x41
    ctx->r1 = SIGNED(ctx->r5) < 0X41 ? 1 : 0;
    // 0x80800B70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B74: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80800B78: bne         $at, $zero, L_80800B94
    if (ctx->r1 != 0) {
        // 0x80800B7C: sw          $a2, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r6;
            goto L_80800B94;
    }
    // 0x80800B7C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80800B80: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800B84: beq         $a1, $at, L_80800F18
    if (ctx->r5 == ctx->r1) {
        // 0x80800B88: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_80800F18;
    }
    // 0x80800B88: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800B8C: b           L_80800F68
    // 0x80800B90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F68;
    // 0x80800B90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B94:
    // 0x80800B94: addiu       $t6, $a1, -0xF
    ctx->r14 = ADD32(ctx->r5, -0XF);
    // 0x80800B98: sltiu       $at, $t6, 0x32
    ctx->r1 = ctx->r14 < 0X32 ? 1 : 0;
    // 0x80800B9C: beq         $at, $zero, L_80800F64
    if (ctx->r1 == 0) {
        // 0x80800BA0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800F64;
    }
    // 0x80800BA0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800BA4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1D38) << 16);
    // 0x80800BA8: addu        $at, $at, $t6
    gpr jr_addend_80800BB0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800BAC: lw          $t6, 0x1D38($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1D38));
    // 0x80800BB0: jr          $t6
    // 0x80800BB4: nop

    switch (jr_addend_80800BB0 >> 2) {
        case 0: goto L_80800E8C; break;
        case 1: goto L_80800F64; break;
        case 2: goto L_80800F64; break;
        case 3: goto L_80800F64; break;
        case 4: goto L_80800F64; break;
        case 5: goto L_80800F64; break;
        case 6: goto L_80800F64; break;
        case 7: goto L_80800F64; break;
        case 8: goto L_80800F64; break;
        case 9: goto L_80800F64; break;
        case 10: goto L_80800F64; break;
        case 11: goto L_80800F64; break;
        case 12: goto L_80800F64; break;
        case 13: goto L_80800F64; break;
        case 14: goto L_80800F64; break;
        case 15: goto L_80800F64; break;
        case 16: goto L_80800EC4; break;
        case 17: goto L_80800F64; break;
        case 18: goto L_80800F64; break;
        case 19: goto L_80800F64; break;
        case 20: goto L_80800F64; break;
        case 21: goto L_80800F64; break;
        case 22: goto L_80800F64; break;
        case 23: goto L_80800F64; break;
        case 24: goto L_80800F64; break;
        case 25: goto L_80800F64; break;
        case 26: goto L_80800F64; break;
        case 27: goto L_80800F64; break;
        case 28: goto L_80800F64; break;
        case 29: goto L_80800F64; break;
        case 30: goto L_80800F64; break;
        case 31: goto L_80800EE0; break;
        case 32: goto L_80800F64; break;
        case 33: goto L_80800F64; break;
        case 34: goto L_80800F64; break;
        case 35: goto L_80800F64; break;
        case 36: goto L_80800F64; break;
        case 37: goto L_80800F64; break;
        case 38: goto L_80800F64; break;
        case 39: goto L_80800F64; break;
        case 40: goto L_80800F64; break;
        case 41: goto L_80800C84; break;
        case 42: goto L_80800F64; break;
        case 43: goto L_80800F64; break;
        case 44: goto L_80800F64; break;
        case 45: goto L_80800F64; break;
        case 46: goto L_80800C98; break;
        case 47: goto L_80800F64; break;
        case 48: goto L_80800BB8; break;
        case 49: goto L_80800C2C; break;
        default: switch_error(__func__, 0x80800BB0, 0x80801D38);
    }
    // 0x80800BB4: nop

L_80800BB8:
    // 0x80800BB8: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80800BBC: lhu         $t8, 0x72($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X72);
    // 0x80800BC0: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800BC4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800BC8: sltiu       $at, $t0, 0x6
    ctx->r1 = ctx->r8 < 0X6 ? 1 : 0;
    // 0x80800BCC: beq         $at, $zero, L_80800C08
    if (ctx->r1 == 0) {
        // 0x80800BD0: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800C08;
    }
    // 0x80800BD0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800BD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1E00) << 16);
    // 0x80800BD8: addu        $at, $at, $t0
    gpr jr_addend_80800BE0 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800BDC: lw          $t0, 0x1E00($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1E00));
    // 0x80800BE0: jr          $t0
    // 0x80800BE4: nop

    switch (jr_addend_80800BE0 >> 2) {
        case 0: goto L_80800BE8; break;
        case 1: goto L_80800BE8; break;
        case 2: goto L_80800BFC; break;
        case 3: goto L_80800BE8; break;
        case 4: goto L_80800BFC; break;
        case 5: goto L_80800BE8; break;
        default: switch_error(__func__, 0x80800BE0, 0x80801E00);
    }
    // 0x80800BE4: nop

L_80800BE8:
    // 0x80800BE8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800BEC: jal         0x80800950
    // 0x80800BF0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_0;
    // 0x80800BF0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x80800BF4: b           L_80800C0C
    // 0x80800BF8: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
        goto L_80800C0C;
    // 0x80800BF8: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
L_80800BFC:
    // 0x80800BFC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800C00: jal         0x80800950
    // 0x80800C04: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800950_chfantasyeyeball(rdram, ctx);
        goto after_1;
    // 0x80800C04: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
L_80800C08:
    // 0x80800C08: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
L_80800C0C:
    // 0x80800C0C: jal         0x800D0B68
    // 0x80800C10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_2;
    // 0x80800C10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800C14: bne         $v0, $zero, L_80800C24
    if (ctx->r2 != 0) {
        // 0x80800C18: nop
    
            goto L_80800C24;
    }
    // 0x80800C18: nop

    // 0x80800C1C: jal         0x800FC6B0
    // 0x80800C20: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC6B0(rdram, ctx);
        goto after_3;
    // 0x80800C20: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_3:
L_80800C24:
    // 0x80800C24: b           L_80800F68
    // 0x80800C28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F68;
    // 0x80800C28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C2C:
    // 0x80800C2C: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80800C30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800C34: lwc1        $f6, 0x30($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X30);
    // 0x80800C38: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800C3C: nop

    // 0x80800C40: bc1fl       L_80800C70
    if (!c1cs) {
        // 0x80800C44: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80800C70;
    }
    goto skip_0;
    // 0x80800C44: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_0:
    // 0x80800C48: lw          $t2, 0x78($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X78);
    // 0x80800C4C: lui         $a0, 0x3FEF
    ctx->r4 = S32(0X3FEF << 16);
    // 0x80800C50: ori         $a0, $a0, 0xA49D
    ctx->r4 = ctx->r4 | 0XA49D;
    // 0x80800C54: sll         $t4, $t2, 29
    ctx->r12 = S32(ctx->r10 << 29);
    // 0x80800C58: bltz        $t4, L_80800C6C
    if (SIGNED(ctx->r12) < 0) {
        // 0x80800C5C: addiu       $a1, $t1, 0x4
        ctx->r5 = ADD32(ctx->r9, 0X4);
            goto L_80800C6C;
    }
    // 0x80800C5C: addiu       $a1, $t1, 0x4
    ctx->r5 = ADD32(ctx->r9, 0X4);
    // 0x80800C60: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800C64: jal         0x800C4140
    // 0x80800C68: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    func_800C4140(rdram, ctx);
        goto after_4;
    // 0x80800C68: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    after_4:
L_80800C6C:
    // 0x80800C6C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_80800C70:
    // 0x80800C70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800C74: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x80800C78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800C7C: b           L_80800F68
    // 0x80800C80: swc1        $f8, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f8.u32l;
        goto L_80800F68;
    // 0x80800C80: swc1        $f8, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f8.u32l;
L_80800C84:
    // 0x80800C84: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2400, 0X1E98) << 16);
    // 0x80800C88: jal         0x80101074
    // 0x80800C8C: addiu       $a0, $a0, 0x1E98
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2400, 0X1E98));
    func_80101074(rdram, ctx);
        goto after_5;
    // 0x80800C8C: addiu       $a0, $a0, 0x1E98
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2400, 0X1E98));
    after_5:
    // 0x80800C90: b           L_80800F68
    // 0x80800C94: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80800F68;
    // 0x80800C94: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80800C98:
    // 0x80800C98: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80800C9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800CA0: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x80800CA4: beq         $t6, $zero, L_80800CC8
    if (ctx->r14 == 0) {
        // 0x80800CA8: nop
    
            goto L_80800CC8;
    }
    // 0x80800CA8: nop

    // 0x80800CAC: beq         $t6, $at, L_80800D44
    if (ctx->r14 == ctx->r1) {
        // 0x80800CB0: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_80800D44;
    }
    // 0x80800CB0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800CB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800CB8: beq         $t6, $at, L_80800E48
    if (ctx->r14 == ctx->r1) {
        // 0x80800CBC: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_80800E48;
    }
    // 0x80800CBC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800CC0: b           L_80800F68
    // 0x80800CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F68;
    // 0x80800CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CC8:
    // 0x80800CC8: jal         0x800D0B68
    // 0x80800CCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_6;
    // 0x80800CCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800CD0: bne         $v0, $zero, L_80800D3C
    if (ctx->r2 != 0) {
        // 0x80800CD4: addiu       $a0, $zero, 0x4C
        ctx->r4 = ADD32(0, 0X4C);
            goto L_80800D3C;
    }
    // 0x80800CD4: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x80800CD8: jal         0x800D0A9C
    // 0x80800CDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_7;
    // 0x80800CDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800CE0: bne         $v0, $zero, L_80800D3C
    if (ctx->r2 != 0) {
        // 0x80800CE4: addiu       $a0, $zero, 0x4C
        ctx->r4 = ADD32(0, 0X4C);
            goto L_80800D3C;
    }
    // 0x80800CE4: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x80800CE8: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80800CEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800CF0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800CF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800CF8: jal         0x800D10D4
    // 0x80800CFC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    func_800D10D4(rdram, ctx);
        goto after_8;
    // 0x80800CFC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_8:
    // 0x80800D00: jal         0x80106790
    // 0x80800D04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_9;
    // 0x80800D04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x80800D08: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800D10: jal         0x80100094
    // 0x80800D14: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_10;
    // 0x80800D14: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    after_10:
    // 0x80800D18: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80800D1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D20: jal         0x8008A028
    // 0x80800D24: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800D24: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    after_11:
    // 0x80800D28: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800D2C: lbu         $t7, 0x77($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X77);
    // 0x80800D30: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x80800D34: jal         0x8010A570
    // 0x80800D38: sb          $t8, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r24;
    func_8010A570(rdram, ctx);
        goto after_12;
    // 0x80800D38: sb          $t8, 0x77($a0)
    MEM_B(0X77, ctx->r4) = ctx->r24;
    after_12:
L_80800D3C:
    // 0x80800D3C: b           L_80800F68
    // 0x80800D40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F68;
    // 0x80800D40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D44:
    // 0x80800D44: jal         0x80801740
    // 0x80800D48: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_80801740_chfantasyeyeball(rdram, ctx);
        goto after_13;
    // 0x80800D48: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_13:
    // 0x80800D4C: addiu       $a0, $zero, 0x483
    ctx->r4 = ADD32(0, 0X483);
    // 0x80800D50: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800D54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800D58: jal         0x80108528
    // 0x80800D5C: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    func_80108528(rdram, ctx);
        goto after_14;
    // 0x80800D5C: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_14:
    // 0x80800D60: jal         0x800F54E4
    // 0x80800D64: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    func_800F54E4(rdram, ctx);
        goto after_15;
    // 0x80800D64: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    after_15:
    // 0x80800D68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D6C: jal         0x800F5A00
    // 0x80800D70: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800F5A00(rdram, ctx);
        goto after_16;
    // 0x80800D70: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_16:
    // 0x80800D74: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800D78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800D7C: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800D80: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800D84: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800D88: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800D8C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800D90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800D94: jal         0x800EEAD4
    // 0x80800D98: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    func_800EEAD4(rdram, ctx);
        goto after_17;
    // 0x80800D98: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x80800D9C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80800DA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800DA4: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80800DA8: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800DAC: jal         0x800F54E4
    // 0x80800DB0: swc1        $f6, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f6.u32l;
    func_800F54E4(rdram, ctx);
        goto after_18;
    // 0x80800DB0: swc1        $f6, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f6.u32l;
    after_18:
    // 0x80800DB4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80800DB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DBC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800DC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800DC4: jal         0x8010D12C
    // 0x80800DC8: lw          $a2, 0x58($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X58);
    func_8010D12C(rdram, ctx);
        goto after_19;
    // 0x80800DC8: lw          $a2, 0x58($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X58);
    after_19:
    // 0x80800DCC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800DD0: jal         0x800EEAD4
    // 0x80800DD4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800EEAD4(rdram, ctx);
        goto after_20;
    // 0x80800DD4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_20:
    // 0x80800DD8: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80800DDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800DE0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80800DE4: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80800DE8: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800DEC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800DF0: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80800DF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800DF8: lui         $a2, 0x459C
    ctx->r6 = S32(0X459C << 16);
    // 0x80800DFC: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x80800E00: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800E04: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80800E08: swc1        $f10, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f10.u32l;
    // 0x80800E0C: jal         0x800F10B4
    // 0x80800E10: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_21;
    // 0x80800E10: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_21:
    // 0x80800E14: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80800E18: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80800E1C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80800E20: swc1        $f0, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->f0.u32l;
    // 0x80800E24: jal         0x800F18FC
    // 0x80800E28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800F18FC(rdram, ctx);
        goto after_22;
    // 0x80800E28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_22:
    // 0x80800E2C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800E30: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800E34: lui         $a2, 0x4496
    ctx->r6 = S32(0X4496 << 16);
    // 0x80800E38: jal         0x800EEBF0
    // 0x80800E3C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EEBF0(rdram, ctx);
        goto after_23;
    // 0x80800E3C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_23:
    // 0x80800E40: b           L_80800F68
    // 0x80800E44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F68;
    // 0x80800E44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E48:
    // 0x80800E48: jal         0x80801740
    // 0x80800E4C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80801740_chfantasyeyeball(rdram, ctx);
        goto after_24;
    // 0x80800E4C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_24:
    // 0x80800E50: addiu       $a0, $zero, 0x483
    ctx->r4 = ADD32(0, 0X483);
    // 0x80800E54: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800E58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800E5C: jal         0x80108528
    // 0x80800E60: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    func_80108528(rdram, ctx);
        goto after_25;
    // 0x80800E60: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_25:
    // 0x80800E64: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800E68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800E6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800E70: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80800E74: jal         0x80086E20
    // 0x80800E78: swc1        $f18, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f18.u32l;
    _chskeletonexplode_entrypoint_7(rdram, ctx);
        goto after_26;
    // 0x80800E78: swc1        $f18, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f18.u32l;
    after_26:
    // 0x80800E7C: b           L_80800F68
    // 0x80800E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F68;
    // 0x80800E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800E84: b           L_80800F68
    // 0x80800E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800F68;
    // 0x80800E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E8C:
    // 0x80800E8C: jal         0x80101080
    // 0x80800E90: nop

    func_80101080(rdram, ctx);
        goto after_27;
    // 0x80800E90: nop

    after_27:
    // 0x80800E94: jal         0x80106790
    // 0x80800E98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_28;
    // 0x80800E98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_28:
    // 0x80800E9C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800EA0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800EA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800EA8: jal         0x80086E00
    // 0x80800EAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chskeletonexplode_entrypoint_3(rdram, ctx);
        goto after_29;
    // 0x80800EAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_29:
    // 0x80800EB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800EB4: jal         0x80086E08
    // 0x80800EB8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _chskeletonexplode_entrypoint_4(rdram, ctx);
        goto after_30;
    // 0x80800EB8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_30:
    // 0x80800EBC: b           L_80800F68
    // 0x80800EC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F68;
    // 0x80800EC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EC4:
    // 0x80800EC4: jal         0x801015D0
    // 0x80800EC8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_801015D0(rdram, ctx);
        goto after_31;
    // 0x80800EC8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_31:
    // 0x80800ECC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800ED0: jal         0x800DF744
    // 0x80800ED4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_32;
    // 0x80800ED4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x80800ED8: b           L_80800F68
    // 0x80800EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F68;
    // 0x80800EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EE0:
    // 0x80800EE0: lh          $v0, 0x60($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X60);
    // 0x80800EE4: addiu       $at, $zero, 0x141A
    ctx->r1 = ADD32(0, 0X141A);
    // 0x80800EE8: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80800EEC: beq         $v0, $at, L_80800F04
    if (ctx->r2 == ctx->r1) {
        // 0x80800EF0: addiu       $at, $zero, 0x141B
        ctx->r1 = ADD32(0, 0X141B);
            goto L_80800F04;
    }
    // 0x80800EF0: addiu       $at, $zero, 0x141B
    ctx->r1 = ADD32(0, 0X141B);
    // 0x80800EF4: beq         $v0, $at, L_80800F04
    if (ctx->r2 == ctx->r1) {
        // 0x80800EF8: addiu       $at, $zero, 0x141C
        ctx->r1 = ADD32(0, 0X141C);
            goto L_80800F04;
    }
    // 0x80800EF8: addiu       $at, $zero, 0x141C
    ctx->r1 = ADD32(0, 0X141C);
    // 0x80800EFC: bne         $v0, $at, L_80800F10
    if (ctx->r2 != ctx->r1) {
        // 0x80800F00: nop
    
            goto L_80800F10;
    }
    // 0x80800F00: nop

L_80800F04:
    // 0x80800F04: lbu         $t1, 0x65($t4)
    ctx->r9 = MEM_BU(ctx->r12, 0X65);
    // 0x80800F08: andi        $t5, $t1, 0xFFF7
    ctx->r13 = ctx->r9 & 0XFFF7;
    // 0x80800F0C: sb          $t5, 0x65($t4)
    MEM_B(0X65, ctx->r12) = ctx->r13;
L_80800F10:
    // 0x80800F10: b           L_80800F68
    // 0x80800F14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F68;
    // 0x80800F14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F18:
    // 0x80800F18: jal         0x80100094
    // 0x80800F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_33;
    // 0x80800F1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x80800F20: jal         0x8008A038
    // 0x80800F24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _subaddielink_entrypoint_3(rdram, ctx);
        goto after_34;
    // 0x80800F24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_34:
    // 0x80800F28: bne         $v0, $zero, L_80800F5C
    if (ctx->r2 != 0) {
        // 0x80800F2C: addiu       $a0, $zero, 0x4C
        ctx->r4 = ADD32(0, 0X4C);
            goto L_80800F5C;
    }
    // 0x80800F2C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x80800F30: jal         0x800D0B68
    // 0x80800F34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_35;
    // 0x80800F34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x80800F38: bne         $v0, $zero, L_80800F5C
    if (ctx->r2 != 0) {
        // 0x80800F3C: lw          $t6, 0x58($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X58);
            goto L_80800F5C;
    }
    // 0x80800F3C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80800F40: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80800F44: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80800F48: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800F4C: bgez        $t9, L_80800F5C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800F50: nop
    
            goto L_80800F5C;
    }
    // 0x80800F50: nop

    // 0x80800F54: jal         0x80108B04
    // 0x80800F58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_36;
    // 0x80800F58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_36:
L_80800F5C:
    // 0x80800F5C: b           L_80800F68
    // 0x80800F60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800F68;
    // 0x80800F60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800F64:
    // 0x80800F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800F68:
    // 0x80800F68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F6C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800F70: jr          $ra
    // 0x80800F74: nop

    return;
    // 0x80800F74: nop

;}
RECOMP_FUNC void chfactorymaindoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2320, 0X4D4) << 16);
    // 0x8080033C: jr          $ra
    // 0x80800340: addiu       $v0, $v0, 0x4D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2320, 0X4D4));
    return;
    // 0x80800340: addiu       $v0, $v0, 0x4D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2320, 0X4D4));
;}
RECOMP_FUNC void func_80800028_ncbapan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800028: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080002C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800030: jal         0x80112524
    // 0x80800034: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800034: nop

    after_0:
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080003C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800040: jr          $ra
    // 0x80800044: nop

    return;
    // 0x80800044: nop

;}
RECOMP_FUNC void func_80800254_chintroticker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080025C: lbu         $t6, 0x79($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X79);
    // 0x80800260: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x80800264: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x80800268: beq         $at, $zero, L_808002CC
    if (ctx->r1 == 0) {
        // 0x8080026C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_808002CC;
    }
    // 0x8080026C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800270: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1648, 0X804) << 16);
    // 0x80800274: addu        $at, $at, $t7
    gpr jr_addend_8080027C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800278: lw          $t7, 0x804($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1648, 0X804));
    // 0x8080027C: jr          $t7
    // 0x80800280: nop

    switch (jr_addend_8080027C >> 2) {
        case 0: goto L_808002CC; break;
        case 1: goto L_808002CC; break;
        case 2: goto L_80800284; break;
        case 3: goto L_80800294; break;
        case 4: goto L_808002AC; break;
        case 5: goto L_808002CC; break;
        default: switch_error(__func__, 0x8080027C, 0x80800804);
    }
    // 0x80800280: nop

L_80800284:
    // 0x80800284: jal         0x800DA524
    // 0x80800288: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x80800288: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_0:
    // 0x8080028C: b           L_808002D0
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002D0;
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800294:
    // 0x80800294: jal         0x800DA544
    // 0x80800298: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800298: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_1:
    // 0x8080029C: jal         0x800DA524
    // 0x808002A0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x808002A0: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_2:
    // 0x808002A4: b           L_808002D0
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002D0;
    // 0x808002A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002AC:
    // 0x808002AC: jal         0x800DA524
    // 0x808002B0: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x808002B0: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    after_3:
    // 0x808002B4: jal         0x800DA544
    // 0x808002B8: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x808002B8: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_4:
    // 0x808002BC: jal         0x800DA524
    // 0x808002C0: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    func_800DA524(rdram, ctx);
        goto after_5;
    // 0x808002C0: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    after_5:
    // 0x808002C4: jal         0x800DA544
    // 0x808002C8: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x808002C8: addiu       $a0, $zero, 0x578
    ctx->r4 = ADD32(0, 0X578);
    after_6:
L_808002CC:
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002D0:
    // 0x808002D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
