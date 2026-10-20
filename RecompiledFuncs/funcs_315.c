#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8011337C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011337C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80113380: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80113384: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80113388: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8011338C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80113390: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80113394: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80113398: jal         0x801107F0
    // 0x8011339C: lw          $a1, 0x28($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X28);
    func_801107F0(rdram, ctx);
        goto after_0;
    // 0x8011339C: lw          $a1, 0x28($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X28);
    after_0:
    // 0x801133A0: lw          $t6, 0x28($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X28);
    // 0x801133A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801133A8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801133AC: sw          $zero, 0x10($t6)
    MEM_W(0X10, ctx->r14) = 0;
    // 0x801133B0: lw          $t7, 0x28($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X28);
    // 0x801133B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801133B8: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x801133BC: sb          $zero, 0x14($t7)
    MEM_B(0X14, ctx->r15) = 0;
L_801133C0:
    // 0x801133C0: jal         0x800E8714
    // 0x801133C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800E8714(rdram, ctx);
        goto after_1;
    // 0x801133C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801133C8: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x801133CC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801133D0: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x801133D4: sb          $v0, 0x34($t9)
    MEM_B(0X34, ctx->r25) = ctx->r2;
    // 0x801133D8: lw          $t0, 0x28($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X28);
    // 0x801133DC: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x801133E0: jal         0x800E8870
    // 0x801133E4: lbu         $a0, 0x34($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X34);
    func_800E8870(rdram, ctx);
        goto after_2;
    // 0x801133E4: lbu         $a0, 0x34($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X34);
    after_2:
    // 0x801133E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801133EC: bne         $s0, $s2, L_801133C0
    if (ctx->r16 != ctx->r18) {
        // 0x801133F0: nop
    
            goto L_801133C0;
    }
    // 0x801133F0: nop

    // 0x801133F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801133F8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801133FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80113400: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80113404: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80113408: jr          $ra
    // 0x8011340C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8011340C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8080000C_chflamer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x80100094
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080001C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800020: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x80800024: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x80800028: jal         0x800BF8E4
    // 0x8080002C: sw          $zero, 0x1AC($v0)
    MEM_W(0X1AC, ctx->r2) = 0;
    func_800BF8E4(rdram, ctx);
        goto after_1;
    // 0x8080002C: sw          $zero, 0x1AC($v0)
    MEM_W(0X1AC, ctx->r2) = 0;
    after_1:
    // 0x80800030: blez        $v0, L_80800040
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800034: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80800040;
    }
    // 0x80800034: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800038: addiu       $t6, $zero, 0x190
    ctx->r14 = ADD32(0, 0X190);
    // 0x8080003C: sh          $t6, 0x4($t7)
    MEM_H(0X4, ctx->r15) = ctx->r14;
L_80800040:
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800044: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800048: jr          $ra
    // 0x8080004C: nop

    return;
    // 0x8080004C: nop

;}
RECOMP_FUNC void func_800198D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800198D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800198D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800198DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800198E0: lw          $a2, 0x8($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X8);
    // 0x800198E4: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800198E8: jal         0x80019C84
    // 0x800198EC: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    mlMtxTranslate(rdram, ctx);
        goto after_0;
    // 0x800198EC: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x800198F0: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800198F4: jal         0x8001907C
    // 0x800198F8: lwc1        $f12, 0x8($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X8);
    mlMtxRotRoll(rdram, ctx);
        goto after_1;
    // 0x800198F8: lwc1        $f12, 0x8($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X8);
    after_1:
    // 0x800198FC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80019900: jal         0x80018F50
    // 0x80019904: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    mlMtxRotPitch(rdram, ctx);
        goto after_2;
    // 0x80019904: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x80019908: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8001990C: jal         0x80018FE8
    // 0x80019910: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    mlMtxRotYaw(rdram, ctx);
        goto after_3;
    // 0x80019910: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    after_3:
    // 0x80019914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019918: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001991C: jr          $ra
    // 0x80019920: nop

    return;
    // 0x80019920: nop

;}
RECOMP_FUNC void fxkern_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003FC: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x80800400: jal         0x800B8CF0
    // 0x80800404: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    func_800B8CF0(rdram, ctx);
        goto after_0;
    // 0x80800404: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80800408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080040C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80800410: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2854, 0X480) << 16);
    // 0x80800414: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800418: jr          $ra
    // 0x8080041C: swc1        $f4, 0x480($at)
    MEM_W((int16_t)RELOC_LO16(2854, 0X480), ctx->r1) = ctx->f4.u32l;
    return;
    // 0x8080041C: swc1        $f4, 0x480($at)
    MEM_W((int16_t)RELOC_LO16(2854, 0X480), ctx->r1) = ctx->f4.u32l;
;}
RECOMP_FUNC void cadbfunc_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EC8: jal         0x80800E80
    // 0x80800ECC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800E80_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800ECC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800ED0: bne         $v0, $zero, L_80800EE0
    if (ctx->r2 != 0) {
        // 0x80800ED4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800EE0;
    }
    // 0x80800ED4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800ED8: b           L_80800EF0
    // 0x80800EDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EF0;
    // 0x80800EDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800EE0:
    // 0x80800EE0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80800EE4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800EE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800EEC: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
L_80800EF0:
    // 0x80800EF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EF8: jr          $ra
    // 0x80800EFC: nop

    return;
    // 0x80800EFC: nop

;}
RECOMP_FUNC void func_800A5BAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5BAC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5BB0: lw          $t6, 0x7100($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7100);
    // 0x800A5BB4: jr          $ra
    // 0x800A5BB8: lbu         $v0, 0x9($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X9);
    return;
    // 0x800A5BB8: lbu         $v0, 0x9($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X9);
;}
RECOMP_FUNC void func_80808D80_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80808D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808D88: jal         0x80802508
    // 0x80808D8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802508_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808D8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80808D90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80808D94: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80808D98: jal         0x8008CB3C
    // 0x80808D9C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80808D9C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x80808DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80808DA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80808DA8: jr          $ra
    // 0x80808DAC: nop

    return;
    // 0x80808DAC: nop

;}
RECOMP_FUNC void bahold_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080004C: jal         0x80800008
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800008_bahold(rdram, ctx);
        goto after_0;
    // 0x80800050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800058: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8080005C: lw          $t6, 0x9C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C);
    // 0x80800060: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800064: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800068: jal         0x80800214
    // 0x8080006C: sb          $zero, 0xC($t6)
    MEM_B(0XC, ctx->r14) = 0;
    bahold_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x8080006C: sb          $zero, 0xC($t6)
    MEM_B(0XC, ctx->r14) = 0;
    after_1:
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void _bsbswim_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B88: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082B88);
    return;
    // 0x80082B8C: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_8080025C_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080025C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800260: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800264: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080026C: jal         0x80100094
    // 0x80800270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800270: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800274: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800278: sb          $t6, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r14;
    // 0x8080027C: jal         0x808009E4
    // 0x80800280: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_808009E4_chfactoryworkerdirty(rdram, ctx);
        goto after_1;
    // 0x80800280: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_1:
    // 0x80800284: beq         $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x80800288: nop
    
            goto L_808002EC;
    }
    // 0x80800288: nop

    // 0x8080028C: jal         0x80800A14
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A14_chfactoryworkerdirty(rdram, ctx);
        goto after_2;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800294: beq         $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x80800298: nop
    
            goto L_808002EC;
    }
    // 0x80800298: nop

    // 0x8080029C: jal         0x80088848
    // 0x808002A0: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x808002A0: nop

    after_3:
    // 0x808002A4: bne         $v0, $zero, L_808002EC
    if (ctx->r2 != 0) {
        // 0x808002A8: addiu       $a0, $zero, 0x36
        ctx->r4 = ADD32(0, 0X36);
            goto L_808002EC;
    }
    // 0x808002A8: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x808002AC: jal         0x800D0B68
    // 0x808002B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0B68(rdram, ctx);
        goto after_4;
    // 0x808002B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808002B4: bne         $v0, $zero, L_808002EC
    if (ctx->r2 != 0) {
        // 0x808002B8: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_808002EC;
    }
    // 0x808002B8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808002BC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x808002C0: jal         0x800EEB9C
    // 0x808002C4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_5;
    // 0x808002C4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_5:
    // 0x808002C8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x808002CC: jal         0x800EF04C
    // 0x808002D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_6;
    // 0x808002D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x808002D4: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x808002D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002DC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x808002E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x808002E4: jal         0x800D1000
    // 0x808002E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_7;
    // 0x808002E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
L_808002EC:
    // 0x808002EC: jal         0x80088848
    // 0x808002F0: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_8;
    // 0x808002F0: nop

    after_8:
    // 0x808002F4: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x808002F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080030C;
    }
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002FC: jal         0x808000AC
    // 0x80800300: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808000AC_chfactoryworkerdirty(rdram, ctx);
        goto after_9;
    // 0x80800300: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x80800304: b           L_80800328
    // 0x80800308: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
        goto L_80800328;
    // 0x80800308: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
L_8080030C:
    // 0x8080030C: jal         0x80800AB4
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800AB4_chfactoryworkerdirty(rdram, ctx);
        goto after_10;
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800314: beq         $v0, $zero, L_80800324
    if (ctx->r2 == 0) {
        // 0x80800318: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800324;
    }
    // 0x80800318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080031C: jal         0x808000AC
    // 0x80800320: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808000AC_chfactoryworkerdirty(rdram, ctx);
        goto after_11;
    // 0x80800320: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_11:
L_80800324:
    // 0x80800324: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
L_80800328:
    // 0x80800328: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x8080032C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800330: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800334: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800338: jr          $ra
    // 0x8080033C: nop

    return;
    // 0x8080033C: nop

;}
RECOMP_FUNC void func_800B537C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B537C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B5380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5384: jal         0x800B525C
    // 0x800B5388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800B525C(rdram, ctx);
        goto after_0;
    // 0x800B5388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800B538C: jal         0x800B52EC
    // 0x800B5390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800B52EC(rdram, ctx);
        goto after_1;
    // 0x800B5390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800B5394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B539C: jr          $ra
    // 0x800B53A0: nop

    return;
    // 0x800B53A0: nop

;}
RECOMP_FUNC void func_8080094C_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_8080094C_chfantasyathlete");
    // 0x8080094C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800950: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800954: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800958: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8080095C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800960: jal         0x80100094
    // 0x80800964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800964: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800968: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x8080096C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800970: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80800974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800978: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080097C: bnel        $t7, $at, L_80800990
    if (ctx->r15 != ctx->r1) {
        // 0x80800980: lw          $t8, 0x6C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X6C);
            goto L_80800990;
    }
    goto skip_0;
    // 0x80800980: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    skip_0:
    // 0x80800984: jal         0x80800000
    // 0x80800988: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800000_chfantasyathlete(rdram, ctx);
        goto after_1;
    // 0x80800988: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8080098C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
L_80800990:
    // 0x80800990: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80800994: sltiu       $at, $t9, 0x22
    ctx->r1 = ctx->r25 < 0X22 ? 1 : 0;
    // 0x80800998: beq         $at, $zero, L_808010F4
    if (ctx->r1 == 0) {
        // 0x8080099C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808010F4;
    }
    // 0x8080099C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808009A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2E78) << 16);
    // 0x808009A4: addu        $at, $at, $t9
    gpr jr_addend_808009AC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x808009A8: lw          $t9, 0x2E78($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2E78));
    // 0x808009AC: jr          $t9
    // 0x808009B0: nop

    switch (jr_addend_808009AC >> 2) {
        case 0: goto L_808009B4; break;
        case 1: goto L_808009E8; break;
        case 2: goto L_808009F8; break;
        case 3: goto L_808010F4; break;
        case 4: goto L_80800A0C; break;
        case 5: goto L_80800A5C; break;
        case 6: goto L_80800A6C; break;
        case 7: goto L_80800AAC; break;
        case 8: goto L_80800B20; break;
        case 9: goto L_80800B54; break;
        case 10: goto L_80800B80; break;
        case 11: goto L_80800C18; break;
        case 12: goto L_80800C60; break;
        case 13: goto L_80800C9C; break;
        case 14: goto L_80800CC0; break;
        case 15: goto L_80800CEC; break;
        case 16: goto L_80800D24; break;
        case 17: goto L_808010F4; break;
        case 18: goto L_80800D40; break;
        case 19: goto L_80800D88; break;
        case 20: goto L_80800DAC; break;
        case 21: goto L_80800DFC; break;
        case 22: goto L_80800E70; break;
        case 23: goto L_80800EA4; break;
        case 24: goto L_80800ED0; break;
        case 25: goto L_80800F3C; break;
        case 26: goto L_80800F98; break;
        case 27: goto L_80800FD4; break;
        case 28: goto L_80800FF8; break;
        case 29: goto L_8080101C; break;
        case 30: goto L_80801054; break;
        case 31: goto L_80801064; break;
        case 32: goto L_80801074; break;
        case 33: goto L_808010E4; break;
        default: switch_error(__func__, 0x808009AC, 0x80802E78);
    }
    // 0x808009B0: nop

L_808009B4:
    // 0x808009B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808009B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808009BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808009C4: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x808009C8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x808009CC: jal         0x808018B8
    // 0x808009D0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_2;
    // 0x808009D0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_2:
    // 0x808009D4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808009D8: nop

    // 0x808009DC: swc1        $f2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f2.u32l;
    // 0x808009E0: b           L_808010F4
    // 0x808009E4: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
        goto L_808010F4;
    // 0x808009E4: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
L_808009E8:
    // 0x808009E8: jal         0x800FC6B0
    // 0x808009EC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC6B0(rdram, ctx);
        goto after_3;
    // 0x808009EC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
    // 0x808009F0: b           L_808010F8
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009F8:
    // 0x808009F8: jal         0x800DA544
    // 0x808009FC: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x808009FC: addiu       $a0, $zero, 0x3DC
    ctx->r4 = ADD32(0, 0X3DC);
    after_4:
    // 0x80800A00: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800A04: b           L_808010F4
    // 0x80800A08: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
        goto L_808010F4;
    // 0x80800A08: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
L_80800A0C:
    // 0x80800A0C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A14: addiu       $a2, $zero, 0x3B
    ctx->r6 = ADD32(0, 0X3B);
    // 0x80800A18: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x80800A1C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800A20: jal         0x80802C18
    // 0x80800A24: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    func_80802C18_chfantasyathlete(rdram, ctx);
        goto after_5;
    // 0x80800A24: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    after_5:
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A2C: jal         0x8008A4B0
    // 0x80800A30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800A30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800A34: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A3C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800A40: jal         0x8010573C
    // 0x80800A44: nop

    func_8010573C(rdram, ctx);
        goto after_7;
    // 0x80800A44: nop

    after_7:
    // 0x80800A48: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800A4C: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x80800A50: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80800A54: b           L_808010F4
    // 0x80800A58: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
        goto L_808010F4;
    // 0x80800A58: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
L_80800A5C:
    // 0x80800A5C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2F00) << 16);
    // 0x80800A60: lwc1        $f0, 0x2F00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2F00));
    // 0x80800A64: b           L_808010F4
    // 0x80800A68: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
        goto L_808010F4;
    // 0x80800A68: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
L_80800A6C:
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A70: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800A74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800A78: jal         0x808018B8
    // 0x80800A7C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_8;
    // 0x80800A7C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_8:
    // 0x80800A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A84: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800A88: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x80800A8C: jal         0x80802C18
    // 0x80800A90: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    func_80802C18_chfantasyathlete(rdram, ctx);
        goto after_9;
    // 0x80800A90: addiu       $a3, $zero, 0x2810
    ctx->r7 = ADD32(0, 0X2810);
    after_9:
    // 0x80800A94: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80800A98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800A9C: nop

    // 0x80800AA0: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80800AA4: b           L_808010F4
    // 0x80800AA8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
        goto L_808010F4;
    // 0x80800AA8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_80800AAC:
    // 0x80800AAC: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    // 0x80800AB0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AB8: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80800ABC: bne         $t1, $at, L_80800AE0
    if (ctx->r9 != ctx->r1) {
        // 0x80800AC0: lw          $a1, 0x64($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X64);
            goto L_80800AE0;
    }
    // 0x80800AC0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800ACC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800AD0: jal         0x808018B8
    // 0x80800AD4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_10;
    // 0x80800AD4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_10:
    // 0x80800AD8: b           L_80800AF0
    // 0x80800ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800AF0;
    // 0x80800ADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AE0:
    // 0x80800AE0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800AE4: jal         0x808018B8
    // 0x80800AE8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_11;
    // 0x80800AE8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_11:
    // 0x80800AEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800AF0:
    // 0x80800AF0: jal         0x8008A4B0
    // 0x80800AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_12;
    // 0x80800AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800AF8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800AFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800B00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B08: swc1        $f2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f2.u32l;
    // 0x80800B0C: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x80800B10: jal         0x80802D38
    // 0x80800B14: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    func_80802D38_chfantasyathlete(rdram, ctx);
        goto after_13;
    // 0x80800B14: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_13:
    // 0x80800B18: b           L_808010F8
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800B1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800B20:
    // 0x80800B20: lbu         $t2, 0x79($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X79);
    // 0x80800B24: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800B28: addiu       $t5, $zero, 0x6B
    ctx->r13 = ADD32(0, 0X6B);
    // 0x80800B2C: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x80800B30: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x80800B34: sb          $t4, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r12;
    // 0x80800B38: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800B3C: addiu       $a1, $zero, 0x1412
    ctx->r5 = ADD32(0, 0X1412);
    // 0x80800B40: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800B44: jal         0x8008A208
    // 0x80800B48: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80800B48: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_14:
    // 0x80800B4C: b           L_808010F8
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800B54:
    // 0x80800B54: jal         0x80802D38
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D38_chfantasyathlete(rdram, ctx);
        goto after_15;
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800B5C: jal         0x800DA524
    // 0x80800B60: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    func_800DA524(rdram, ctx);
        goto after_16;
    // 0x80800B60: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    after_16:
    // 0x80800B64: jal         0x800EA05C
    // 0x80800B68: nop

    func_800EA05C(rdram, ctx);
        goto after_17;
    // 0x80800B68: nop

    after_17:
    // 0x80800B6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B70: jal         0x80087A58
    // 0x80800B74: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_18;
    // 0x80800B74: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_18:
    // 0x80800B78: b           L_808010F8
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800B80:
    // 0x80800B80: jal         0x800F54E4
    // 0x80800B84: nop

    func_800F54E4(rdram, ctx);
        goto after_19;
    // 0x80800B84: nop

    after_19:
    // 0x80800B88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800B8C: jal         0x800F5A00
    // 0x80800B90: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800F5A00(rdram, ctx);
        goto after_20;
    // 0x80800B90: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_20:
    // 0x80800B94: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800B98: lui         $a1, 0x4282
    ctx->r5 = S32(0X4282 << 16);
    // 0x80800B9C: jal         0x800EEB9C
    // 0x80800BA0: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_21;
    // 0x80800BA0: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_21:
    // 0x80800BA4: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80800BA8: jal         0x800EF04C
    // 0x80800BAC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    func_800EF04C(rdram, ctx);
        goto after_22;
    // 0x80800BAC: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_22:
    // 0x80800BB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800BB8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800BBC: jal         0x808018B8
    // 0x80800BC0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_23;
    // 0x80800BC0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_23:
    // 0x80800BC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800BC8: addiu       $t6, $zero, 0x6B
    ctx->r14 = ADD32(0, 0X6B);
    // 0x80800BCC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800BD0: addiu       $a1, $zero, 0x13E5
    ctx->r5 = ADD32(0, 0X13E5);
    // 0x80800BD4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800BD8: jal         0x8008A208
    // 0x80800BDC: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_24;
    // 0x80800BDC: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_24:
    // 0x80800BE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BE4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800BE8: jal         0x80802C94
    // 0x80800BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802C94_chfantasyathlete(rdram, ctx);
        goto after_25;
    // 0x80800BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_25:
    // 0x80800BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BF4: jal         0x8008A4B0
    // 0x80800BF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_26;
    // 0x80800BF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80800BFC: jal         0x800F54E4
    // 0x80800C00: nop

    func_800F54E4(rdram, ctx);
        goto after_27;
    // 0x80800C00: nop

    after_27:
    // 0x80800C04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C08: jal         0x800F7B9C
    // 0x80800C0C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    func_800F7B9C(rdram, ctx);
        goto after_28;
    // 0x80800C0C: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_28:
    // 0x80800C10: b           L_808010F8
    // 0x80800C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C18:
    // 0x80800C18: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800C1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800C20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800C24: andi        $t9, $t7, 0xFFEF
    ctx->r25 = ctx->r15 & 0XFFEF;
    // 0x80800C28: sb          $t9, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r25;
    // 0x80800C2C: andi        $t0, $t9, 0xF7
    ctx->r8 = ctx->r25 & 0XF7;
    // 0x80800C30: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
    // 0x80800C34: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2F04) << 16);
    // 0x80800C38: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800C3C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800C40: lwc1        $f16, 0x2F04($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2F04));
    // 0x80800C44: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x80800C48: jal         0x800FDC28
    // 0x80800C4C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    func_800FDC28(rdram, ctx);
        goto after_29;
    // 0x80800C4C: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    after_29:
    // 0x80800C50: jal         0x80802D38
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D38_chfantasyathlete(rdram, ctx);
        goto after_30;
    // 0x80800C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80800C58: b           L_808010F8
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C60:
    // 0x80800C60: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x80800C64: addiu       $a0, $zero, 0x6D7
    ctx->r4 = ADD32(0, 0X6D7);
    // 0x80800C68: sll         $t1, $a1, 12
    ctx->r9 = S32(ctx->r5 << 12);
    // 0x80800C6C: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x80800C70: jal         0x800DA3B8
    // 0x80800C74: sltiu       $a1, $t2, 0x1
    ctx->r5 = ctx->r10 < 0X1 ? 1 : 0;
    func_800DA3B8(rdram, ctx);
        goto after_31;
    // 0x80800C74: sltiu       $a1, $t2, 0x1
    ctx->r5 = ctx->r10 < 0X1 ? 1 : 0;
    after_31:
    // 0x80800C78: jal         0x800DA544
    // 0x80800C7C: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    func_800DA544(rdram, ctx);
        goto after_32;
    // 0x80800C7C: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    after_32:
    // 0x80800C80: jal         0x800EA05C
    // 0x80800C84: nop

    func_800EA05C(rdram, ctx);
        goto after_33;
    // 0x80800C84: nop

    after_33:
    // 0x80800C88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C8C: jal         0x80087A58
    // 0x80800C90: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_34;
    // 0x80800C90: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_34:
    // 0x80800C94: b           L_808010F8
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800C9C:
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800CA4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800CA8: jal         0x808018B8
    // 0x80800CAC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_35;
    // 0x80800CAC: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_35:
    // 0x80800CB0: jal         0x8010CD28
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_36;
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x80800CB8: b           L_808010F4
    // 0x80800CBC: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
        goto L_808010F4;
    // 0x80800CBC: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
L_80800CC0:
    // 0x80800CC0: jal         0x800DA544
    // 0x80800CC4: addiu       $a0, $zero, 0x3DD
    ctx->r4 = ADD32(0, 0X3DD);
    func_800DA544(rdram, ctx);
        goto after_37;
    // 0x80800CC4: addiu       $a0, $zero, 0x3DD
    ctx->r4 = ADD32(0, 0X3DD);
    after_37:
    // 0x80800CC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CCC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800CD0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800CD4: jal         0x808018B8
    // 0x80800CD8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_38;
    // 0x80800CD8: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_38:
    // 0x80800CDC: jal         0x8010CD28
    // 0x80800CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_39;
    // 0x80800CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80800CE4: b           L_808010F4
    // 0x80800CE8: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
        goto L_808010F4;
    // 0x80800CE8: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
L_80800CEC:
    // 0x80800CEC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800CF0: addiu       $t4, $zero, 0x6B
    ctx->r12 = ADD32(0, 0X6B);
    // 0x80800CF4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800CF8: addiu       $a1, $zero, 0x1413
    ctx->r5 = ADD32(0, 0X1413);
    // 0x80800CFC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800D00: jal         0x8008A208
    // 0x80800D04: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_40;
    // 0x80800D04: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_40:
    // 0x80800D08: jal         0x800F54E4
    // 0x80800D0C: nop

    func_800F54E4(rdram, ctx);
        goto after_41;
    // 0x80800D0C: nop

    after_41:
    // 0x80800D10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800D14: jal         0x800F7B9C
    // 0x80800D18: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_800F7B9C(rdram, ctx);
        goto after_42;
    // 0x80800D18: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_42:
    // 0x80800D1C: b           L_808010F8
    // 0x80800D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D24:
    // 0x80800D24: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80800D28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D2C: lwc1        $f18, 0x9C($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X9C);
    // 0x80800D30: jal         0x80802D38
    // 0x80800D34: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    func_80802D38_chfantasyathlete(rdram, ctx);
        goto after_43;
    // 0x80800D34: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    after_43:
    // 0x80800D38: b           L_808010F8
    // 0x80800D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800D3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D40:
    // 0x80800D40: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D48: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800D4C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800D50: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80800D54: jal         0x808018B8
    // 0x80800D58: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_44;
    // 0x80800D58: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_44:
    // 0x80800D5C: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D64: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800D68: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x80800D6C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800D70: addiu       $a2, $zero, 0x3D
    ctx->r6 = ADD32(0, 0X3D);
    // 0x80800D74: addiu       $a3, $zero, 0x2811
    ctx->r7 = ADD32(0, 0X2811);
    // 0x80800D78: jal         0x80802C18
    // 0x80800D7C: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    func_80802C18_chfantasyathlete(rdram, ctx);
        goto after_45;
    // 0x80800D7C: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    after_45:
    // 0x80800D80: b           L_808010F8
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D88:
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D8C: jal         0x8008A4B0
    // 0x80800D90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_46;
    // 0x80800D90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_46:
    // 0x80800D94: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800D98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2F08) << 16);
    // 0x80800D9C: lwc1        $f16, 0x2F08($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2F08));
    // 0x80800DA0: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80800DA4: b           L_808010F4
    // 0x80800DA8: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
        goto L_808010F4;
    // 0x80800DA8: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
L_80800DAC:
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DB0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800DB4: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    // 0x80800DB8: jal         0x80802C18
    // 0x80800DBC: addiu       $a3, $zero, 0x2811
    ctx->r7 = ADD32(0, 0X2811);
    func_80802C18_chfantasyathlete(rdram, ctx);
        goto after_47;
    // 0x80800DBC: addiu       $a3, $zero, 0x2811
    ctx->r7 = ADD32(0, 0X2811);
    after_47:
    // 0x80800DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DC4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800DC8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800DCC: jal         0x808018B8
    // 0x80800DD0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_48;
    // 0x80800DD0: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_48:
    // 0x80800DD4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2388, 0X2F0C) << 16);
    // 0x80800DD8: lwc1        $f0, 0x2F0C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2388, 0X2F0C));
    // 0x80800DDC: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80800DE0: jal         0x800F54E4
    // 0x80800DE4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    func_800F54E4(rdram, ctx);
        goto after_49;
    // 0x80800DE4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    after_49:
    // 0x80800DE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DEC: jal         0x800F7B9C
    // 0x80800DF0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_800F7B9C(rdram, ctx);
        goto after_50;
    // 0x80800DF0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_50:
    // 0x80800DF4: b           L_808010F8
    // 0x80800DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800DFC:
    // 0x80800DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E00: jal         0x8008A4B0
    // 0x80800E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_51;
    // 0x80800E04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_51:
    // 0x80800E08: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800E0C: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80800E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E14: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800E18: bne         $t7, $at, L_80800E3C
    if (ctx->r15 != ctx->r1) {
        // 0x80800E1C: lw          $a1, 0x64($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X64);
            goto L_80800E3C;
    }
    // 0x80800E1C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E24: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800E28: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800E2C: jal         0x808018B8
    // 0x80800E30: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_52;
    // 0x80800E30: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_52:
    // 0x80800E34: b           L_80800E4C
    // 0x80800E38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
        goto L_80800E4C;
    // 0x80800E38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80800E3C:
    // 0x80800E3C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800E40: jal         0x808018B8
    // 0x80800E44: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_53;
    // 0x80800E44: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_53:
    // 0x80800E48: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80800E4C:
    // 0x80800E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E54: swc1        $f2, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f2.u32l;
    // 0x80800E58: jal         0x80800000
    // 0x80800E5C: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    func_80800000_chfantasyathlete(rdram, ctx);
        goto after_54;
    // 0x80800E5C: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    after_54:
    // 0x80800E60: jal         0x80802D38
    // 0x80800E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D38_chfantasyathlete(rdram, ctx);
        goto after_55;
    // 0x80800E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80800E68: b           L_808010F8
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E70:
    // 0x80800E70: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x80800E74: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800E78: addiu       $t1, $zero, 0x6B
    ctx->r9 = ADD32(0, 0X6B);
    // 0x80800E7C: andi        $t9, $t8, 0xFF0F
    ctx->r25 = ctx->r24 & 0XFF0F;
    // 0x80800E80: ori         $t0, $t9, 0x20
    ctx->r8 = ctx->r25 | 0X20;
    // 0x80800E84: sb          $t0, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r8;
    // 0x80800E88: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800E8C: addiu       $a1, $zero, 0x1414
    ctx->r5 = ADD32(0, 0X1414);
    // 0x80800E90: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800E94: jal         0x8008A208
    // 0x80800E98: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_56;
    // 0x80800E98: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_56:
    // 0x80800E9C: b           L_808010F8
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800EA4:
    // 0x80800EA4: jal         0x80802D38
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D38_chfantasyathlete(rdram, ctx);
        goto after_57;
    // 0x80800EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_57:
    // 0x80800EAC: jal         0x800DA524
    // 0x80800EB0: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    func_800DA524(rdram, ctx);
        goto after_58;
    // 0x80800EB0: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    after_58:
    // 0x80800EB4: jal         0x800EA05C
    // 0x80800EB8: nop

    func_800EA05C(rdram, ctx);
        goto after_59;
    // 0x80800EB8: nop

    after_59:
    // 0x80800EBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800EC0: jal         0x80087A58
    // 0x80800EC4: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_60;
    // 0x80800EC4: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_60:
    // 0x80800EC8: b           L_808010F8
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800ED0:
    // 0x80800ED0: jal         0x800F54E4
    // 0x80800ED4: nop

    func_800F54E4(rdram, ctx);
        goto after_61;
    // 0x80800ED4: nop

    after_61:
    // 0x80800ED8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800EDC: jal         0x800F5A00
    // 0x80800EE0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F5A00(rdram, ctx);
        goto after_62;
    // 0x80800EE0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_62:
    // 0x80800EE4: lui         $a1, 0x43A7
    ctx->r5 = S32(0X43A7 << 16);
    // 0x80800EE8: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80800EEC: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800EF0: jal         0x800EEB9C
    // 0x80800EF4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_63;
    // 0x80800EF4: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    after_63:
    // 0x80800EF8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800EFC: jal         0x800EF04C
    // 0x80800F00: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800EF04C(rdram, ctx);
        goto after_64;
    // 0x80800F00: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_64:
    // 0x80800F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F08: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800F0C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800F10: jal         0x808018B8
    // 0x80800F14: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_65;
    // 0x80800F14: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_65:
    // 0x80800F18: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800F1C: addiu       $t2, $zero, 0x6B
    ctx->r10 = ADD32(0, 0X6B);
    // 0x80800F20: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800F24: addiu       $a1, $zero, 0x13EA
    ctx->r5 = ADD32(0, 0X13EA);
    // 0x80800F28: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80800F2C: jal         0x8008A208
    // 0x80800F30: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_66;
    // 0x80800F30: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    after_66:
    // 0x80800F34: b           L_808010F8
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F3C:
    // 0x80800F3C: jal         0x80802D38
    // 0x80800F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D38_chfantasyathlete(rdram, ctx);
        goto after_67;
    // 0x80800F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_67:
    // 0x80800F44: lbu         $t3, 0x65($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X65);
    // 0x80800F48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800F4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800F50: andi        $t5, $t3, 0xFFEF
    ctx->r13 = ctx->r11 & 0XFFEF;
    // 0x80800F54: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    // 0x80800F58: andi        $t6, $t5, 0xF7
    ctx->r14 = ctx->r13 & 0XF7;
    // 0x80800F5C: sb          $t6, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r14;
    // 0x80800F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800F68: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800F6C: jal         0x8008A4B0
    // 0x80800F70: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_68;
    // 0x80800F70: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    after_68:
    // 0x80800F74: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80800F78: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800F7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800F80: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x80800F84: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x80800F88: jal         0x800FDC28
    // 0x80800F8C: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    func_800FDC28(rdram, ctx);
        goto after_69;
    // 0x80800F8C: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    after_69:
    // 0x80800F90: b           L_808010F8
    // 0x80800F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800F98:
    // 0x80800F98: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x80800F9C: addiu       $a0, $zero, 0x6D7
    ctx->r4 = ADD32(0, 0X6D7);
    // 0x80800FA0: sll         $t7, $a1, 12
    ctx->r15 = S32(ctx->r5 << 12);
    // 0x80800FA4: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80800FA8: jal         0x800DA3B8
    // 0x80800FAC: sltiu       $a1, $t8, 0x1
    ctx->r5 = ctx->r24 < 0X1 ? 1 : 0;
    func_800DA3B8(rdram, ctx);
        goto after_70;
    // 0x80800FAC: sltiu       $a1, $t8, 0x1
    ctx->r5 = ctx->r24 < 0X1 ? 1 : 0;
    after_70:
    // 0x80800FB0: jal         0x800DA544
    // 0x80800FB4: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    func_800DA544(rdram, ctx);
        goto after_71;
    // 0x80800FB4: addiu       $a0, $zero, 0x6D6
    ctx->r4 = ADD32(0, 0X6D6);
    after_71:
    // 0x80800FB8: jal         0x800EA05C
    // 0x80800FBC: nop

    func_800EA05C(rdram, ctx);
        goto after_72;
    // 0x80800FBC: nop

    after_72:
    // 0x80800FC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FC4: jal         0x80087A58
    // 0x80800FC8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_73;
    // 0x80800FC8: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_73:
    // 0x80800FCC: b           L_808010F8
    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80800FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800FD4:
    // 0x80800FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FD8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800FDC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80800FE0: jal         0x808018B8
    // 0x80800FE4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_74;
    // 0x80800FE4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_74:
    // 0x80800FE8: jal         0x8010CD28
    // 0x80800FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_75;
    // 0x80800FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_75:
    // 0x80800FF0: b           L_808010F4
    // 0x80800FF4: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
        goto L_808010F4;
    // 0x80800FF4: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
L_80800FF8:
    // 0x80800FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FFC: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80801000: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80801004: jal         0x808018B8
    // 0x80801008: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_76;
    // 0x80801008: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_76:
    // 0x8080100C: jal         0x8010CD28
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_77;
    // 0x80801010: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_77:
    // 0x80801014: b           L_808010F4
    // 0x80801018: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
        goto L_808010F4;
    // 0x80801018: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
L_8080101C:
    // 0x8080101C: jal         0x800F54E4
    // 0x80801020: nop

    func_800F54E4(rdram, ctx);
        goto after_78;
    // 0x80801020: nop

    after_78:
    // 0x80801024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801028: jal         0x800F82D4
    // 0x8080102C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F82D4(rdram, ctx);
        goto after_79;
    // 0x8080102C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_79:
    // 0x80801030: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801034: addiu       $t0, $zero, 0x6B
    ctx->r8 = ADD32(0, 0X6B);
    // 0x80801038: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8080103C: addiu       $a1, $zero, 0x1415
    ctx->r5 = ADD32(0, 0X1415);
    // 0x80801040: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x80801044: jal         0x8008A208
    // 0x80801048: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_80;
    // 0x80801048: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_80:
    // 0x8080104C: b           L_808010F8
    // 0x80801050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80801050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801054:
    // 0x80801054: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80801058: lwc1        $f16, 0xA8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0XA8);
    // 0x8080105C: b           L_808010F4
    // 0x80801060: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
        goto L_808010F4;
    // 0x80801060: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
L_80801064:
    // 0x80801064: jal         0x80802D38
    // 0x80801068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802D38_chfantasyathlete(rdram, ctx);
        goto after_81;
    // 0x80801068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_81:
    // 0x8080106C: b           L_808010F8
    // 0x80801070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808010F8;
    // 0x80801070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801074:
    // 0x80801074: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80801078: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080107C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801080: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801084: jal         0x800D1000
    // 0x80801088: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_82;
    // 0x80801088: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_82:
    // 0x8080108C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801090: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80801094: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x80801098: jal         0x80802C18
    // 0x8080109C: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    func_80802C18_chfantasyathlete(rdram, ctx);
        goto after_83;
    // 0x8080109C: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    after_83:
    // 0x808010A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010A4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x808010A8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x808010AC: jal         0x808018B8
    // 0x808010B0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_808018B8_chfantasyathlete(rdram, ctx);
        goto after_84;
    // 0x808010B0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_84:
    // 0x808010B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B8: jal         0x8008A4B0
    // 0x808010BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_85;
    // 0x808010BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_85:
    // 0x808010C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808010C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808010C8: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x808010CC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x808010D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808010D4: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x808010D8: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x808010DC: b           L_808010F4
    // 0x808010E0: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
        goto L_808010F4;
    // 0x808010E0: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
L_808010E4:
    // 0x808010E4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2388, 0X3150) << 16);
    // 0x808010E8: addiu       $a1, $a1, 0x3150
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2388, 0X3150));
    // 0x808010EC: jal         0x800EE7F8
    // 0x808010F0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_86;
    // 0x808010F0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_86:
L_808010F4:
    // 0x808010F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808010F8:
    // 0x808010F8: jal         0x80102424
    // 0x808010FC: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    func_80102424(rdram, ctx);
        goto after_87;
    // 0x808010FC: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    after_87:
    // 0x80801100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801104: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801108: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8080110C: jr          $ra
    // 0x80801110: nop

    return;
    // 0x80801110: nop

;}
RECOMP_FUNC void bskaz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080003C: jal         0x80085050
    // 0x80800040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bashoes_entrypoint_15(rdram, ctx);
        goto after_0;
    // 0x80800040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800044: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800048: addiu       $a1, $a1, 0x32D8
    ctx->r5 = ADD32(ctx->r5, 0X32D8);
    // 0x8080004C: jal         0x80085010
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_7(rdram, ctx);
        goto after_1;
    // 0x80800050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800054: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800058: addiu       $a1, $a1, 0x3508
    ctx->r5 = ADD32(ctx->r5, 0X3508);
    // 0x8080005C: jal         0x80085018
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800064: jal         0x8009F258
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_func_8009F258(rdram, ctx);
        goto after_3;
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: jal         0x80095760
    // 0x80800074: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_set(rdram, ctx);
        goto after_4;
    // 0x80800074: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800078: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x8080007C: ori         $a1, $a1, 0x6600
    ctx->r5 = ctx->r5 | 0X6600;
    // 0x80800080: jal         0x80092864
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80092864(rdram, ctx);
        goto after_5;
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080008C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

;}
RECOMP_FUNC void _trangler_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A360: syscall     838
    recomp_syscall_handler(rdram, ctx, 0x8008A360);
    return;
    // 0x8008A364: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chhillbilly_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(852, 0XC60) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xC60
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(852, 0XC60));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xC60
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(852, 0XC60));
;}
RECOMP_FUNC void func_80107448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010744C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80107450: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80107454: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80107458: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010745C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80107460: jal         0x801073F8
    // 0x80107464: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_801073F8(rdram, ctx);
        goto after_0;
    // 0x80107464: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80107468: bne         $v0, $zero, L_801074A8
    if (ctx->r2 != 0) {
        // 0x8010746C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801074A8;
    }
    // 0x8010746C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107470: lbu         $t6, 0x75($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X75);
    // 0x80107474: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80107478: lbu         $t5, 0x7E($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X7E);
    // 0x8010747C: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80107480: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
    // 0x80107484: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x80107488: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x8010748C: andi        $t6, $t5, 0xFFEF
    ctx->r14 = ctx->r13 & 0XFFEF;
    // 0x80107490: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x80107494: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x80107498: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8010749C: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x801074A0: sb          $t4, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r12;
    // 0x801074A4: sb          $t6, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r14;
L_801074A8:
    // 0x801074A8: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x801074AC: lbu         $t9, 0x64($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X64);
    // 0x801074B0: lbu         $t2, 0x79($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X79);
    // 0x801074B4: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x801074B8: lbu         $t7, 0x71($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X71);
    // 0x801074BC: andi        $t3, $t9, 0xFFFE
    ctx->r11 = ctx->r25 & 0XFFFE;
    // 0x801074C0: andi        $t5, $t3, 0x7F
    ctx->r13 = ctx->r11 & 0X7F;
    // 0x801074C4: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
    // 0x801074C8: sb          $t3, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r11;
    // 0x801074CC: sb          $t5, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r13;
    // 0x801074D0: andi        $t6, $t5, 0xBF
    ctx->r14 = ctx->r13 & 0XBF;
    // 0x801074D4: andi        $t1, $t2, 0xFFFC
    ctx->r9 = ctx->r10 & 0XFFFC;
    // 0x801074D8: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x801074DC: sb          $t1, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r9;
    // 0x801074E0: sb          $t6, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r14;
    // 0x801074E4: jal         0x8010A570
    // 0x801074E8: sb          $t8, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r24;
    func_8010A570(rdram, ctx);
        goto after_1;
    // 0x801074E8: sb          $t8, 0x71($s0)
    MEM_B(0X71, ctx->r16) = ctx->r24;
    after_1:
    // 0x801074EC: jal         0x8010A624
    // 0x801074F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_2;
    // 0x801074F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801074F4: jal         0x80104580
    // 0x801074F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104580(rdram, ctx);
        goto after_3;
    // 0x801074F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801074FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107500: jal         0x8010754C
    // 0x80107504: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8010754C(rdram, ctx);
        goto after_4;
    // 0x80107504: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80107508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010750C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80107510: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80107514: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
L_80107518:
    // 0x80107518: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8010751C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80107520: bne         $v0, $a1, L_80107518
    if (ctx->r2 != ctx->r5) {
        // 0x80107524: sb          $a0, 0x5B($v1)
        MEM_B(0X5B, ctx->r3) = ctx->r4;
            goto L_80107518;
    }
    // 0x80107524: sb          $a0, 0x5B($v1)
    MEM_B(0X5B, ctx->r3) = ctx->r4;
    // 0x80107528: jal         0x80107A80
    // 0x8010752C: nop

    func_80107A80(rdram, ctx);
        goto after_5;
    // 0x8010752C: nop

    after_5:
    // 0x80107530: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80107534: swc1        $f0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
    // 0x80107538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010753C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80107540: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80107544: jr          $ra
    // 0x80107548: nop

    return;
    // 0x80107548: nop

;}
RECOMP_FUNC void func_800F14FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F14FC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800F1500: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F1504: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F1508: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800F150C: nop

    // 0x800F1510: bc1fl       L_800F1528
    if (!c1cs) {
        // 0x800F1514: c.le.s      $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
            goto L_800F1528;
    }
    goto skip_0;
    // 0x800F1514: c.le.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
    skip_0:
    // 0x800F1518: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F151C: jr          $ra
    // 0x800F1520: nop

    return;
    // 0x800F1520: nop

    // 0x800F1524: c.le.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl <= ctx->f6.fl;
L_800F1528:
    // 0x800F1528: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F152C: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F1530: bc1fl       L_800F1548
    if (!c1cs) {
        // 0x800F1534: sub.s       $f10, $f8, $f12
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
            goto L_800F1548;
    }
    goto skip_1;
    // 0x800F1534: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    skip_1:
    // 0x800F1538: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F153C: jr          $ra
    // 0x800F1540: nop

    return;
    // 0x800F1540: nop

    // 0x800F1544: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
L_800F1548:
    // 0x800F1548: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800F154C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800F1550: sub.s       $f16, $f14, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x800F1554: div.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800F1558: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800F155C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800F1560: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800F1564: mul.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800F1568: nop

    // 0x800F156C: jr          $ra
    // 0x800F1570: nop

    return;
    // 0x800F1570: nop

;}
RECOMP_FUNC void func_808004A4_chfactorytoxicpools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808004A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808004B0: jal         0x800BEA88
    // 0x808004B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_0;
    // 0x808004B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x808004B8: beq         $v0, $zero, L_808004F0
    if (ctx->r2 == 0) {
        // 0x808004BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808004F0;
    }
    // 0x808004BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004C0: addiu       $a1, $zero, 0x7D
    ctx->r5 = ADD32(0, 0X7D);
    // 0x808004C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808004C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808004CC: jal         0x80088F28
    // 0x808004D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808004D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808004D4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808004D8: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x808004DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808004E0: addiu       $a2, $a2, 0x6270
    ctx->r6 = ADD32(ctx->r6, 0X6270);
    // 0x808004E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004E8: jal         0x80088660
    // 0x808004EC: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    _glid_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x808004EC: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    after_2:
L_808004F0:
    // 0x808004F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004F8: jr          $ra
    // 0x808004FC: nop

    return;
    // 0x808004FC: nop

;}
RECOMP_FUNC void dbpalette_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800004: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x80800008: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8080000C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80800010: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80800014: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80800018: srl         $t0, $t9, 8
    ctx->r8 = S32(U32(ctx->r25) >> 8);
    // 0x8080001C: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80800020: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x80800024: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80800028: srl         $t3, $t2, 16
    ctx->r11 = S32(U32(ctx->r10) >> 16);
    // 0x8080002C: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80800030: sw          $t4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r12;
    // 0x80800034: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80800038: srl         $t6, $t5, 24
    ctx->r14 = S32(U32(ctx->r13) >> 24);
    // 0x8080003C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80800040: jr          $ra
    // 0x80800044: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    return;
    // 0x80800044: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void _bsbwhirl_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E10: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E10);
    return;
    // 0x80082E14: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_808000C0_chfloater(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808000C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808000CC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808000D0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808000D4: jal         0x80100094
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808000DC: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x808000E0: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x808000E4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x808000E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808000EC: jal         0x800EE904
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EE904(rdram, ctx);
        goto after_1;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808000F4: addiu       $t6, $zero, 0x1F4
    ctx->r14 = ADD32(0, 0X1F4);
    // 0x808000F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80800104: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80800108: jal         0x800882F8
    // 0x8080010C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    _gccubesearch_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x8080010C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80800110: beq         $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800114: lw          $s0, 0x44($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X44);
            goto L_8080027C;
    }
    // 0x80800114: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80800118: lbu         $t9, 0xB($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XB);
    // 0x8080011C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800120: ori         $t1, $t9, 0x20
    ctx->r9 = ctx->r25 | 0X20;
    // 0x80800124: sb          $t1, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r9;
    // 0x80800128: andi        $t2, $t1, 0xEF
    ctx->r10 = ctx->r9 & 0XEF;
    // 0x8080012C: sb          $t2, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r10;
    // 0x80800130: jal         0x800EE88C
    // 0x80800134: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x80800134: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80800138: lbu         $t3, 0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2);
    // 0x8080013C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800140: bgez        $t3, L_80800158
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800144: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800158;
    }
    // 0x80800144: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800148: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8080014C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800150: nop

    // 0x80800154: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_80800158:
    // 0x80800158: jal         0x800136E4
    // 0x8080015C: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_4;
    // 0x8080015C: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    after_4:
    // 0x80800160: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x80800164: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x80800168: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8080016C: bgez        $t4, L_80800184
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800170: cvt.s.w     $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80800184;
    }
    // 0x80800170: cvt.s.w     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800174: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800178: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080017C: nop

    // 0x80800180: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
L_80800184:
    // 0x80800184: jal         0x800136E4
    // 0x80800188: add.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
    func_800136E4(rdram, ctx);
        goto after_5;
    // 0x80800188: add.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
    after_5:
    // 0x8080018C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800190: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80800194: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x80800198: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x8080019C: swc1        $f16, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f16.u32l;
    // 0x808001A0: swc1        $f18, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f18.u32l;
    // 0x808001A4: lbu         $t5, 0xA($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XA);
    // 0x808001A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001AC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x808001B0: bgez        $t5, L_808001C8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808001B4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_808001C8;
    }
    // 0x808001B4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808001B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808001BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001C0: nop

    // 0x808001C4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_808001C8:
    // 0x808001C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(988, 0X290) << 16);
    // 0x808001CC: lwc1        $f10, 0x290($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(988, 0X290));
    // 0x808001D0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x808001D4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808001D8: jal         0x80102FDC
    // 0x808001DC: nop

    func_80102FDC(rdram, ctx);
        goto after_6;
    // 0x808001DC: nop

    after_6:
    // 0x808001E0: jal         0x80088C88
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gsproplookup_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808001E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808001EC: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x808001F0: jal         0x80103140
    // 0x808001F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80103140(rdram, ctx);
        goto after_8;
    // 0x808001F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x808001F8: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x808001FC: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800200: jal         0x80088FA0
    // 0x80800204: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    _mlwave_entrypoint_0(rdram, ctx);
        goto after_9;
    // 0x80800204: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_9:
    // 0x80800208: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8080020C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800210: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x80800214: addiu       $s0, $s0, 0x1C
    ctx->r16 = ADD32(ctx->r16, 0X1C);
    // 0x80800218: jal         0x80088FA0
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _mlwave_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800220: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80800224: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80800228: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    // 0x8080022C: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    // 0x80800230: jal         0x80088FA0
    // 0x80800234: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    _mlwave_entrypoint_0(rdram, ctx);
        goto after_11;
    // 0x80800234: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_11:
    // 0x80800238: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8080023C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800240: jal         0x80088FB0
    // 0x80800244: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    _mlwave_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80800244: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_12:
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80800250: jal         0x80088FB0
    // 0x80800254: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    _mlwave_entrypoint_2(rdram, ctx);
        goto after_13;
    // 0x80800254: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_13:
    // 0x80800258: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080025C: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80800260: jal         0x80088FB0
    // 0x80800264: lui         $a2, 0x40E0
    ctx->r6 = S32(0X40E0 << 16);
    _mlwave_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x80800264: lui         $a2, 0x40E0
    ctx->r6 = S32(0X40E0 << 16);
    after_14:
    // 0x80800268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080026C: jal         0x8010A800
    // 0x80800270: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A800(rdram, ctx);
        goto after_15;
    // 0x80800270: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x80800274: jal         0x80104E78
    // 0x80800278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80104E78(rdram, ctx);
        goto after_16;
    // 0x80800278: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
L_8080027C:
    // 0x8080027C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800280: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800284: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800288: jr          $ra
    // 0x8080028C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8080028C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void suspline_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800E28: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800E2C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800E30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800E38: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80800E3C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800E40: jal         0x80800D10
    // 0x80800E44: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    suspline_entrypoint_18(rdram, ctx);
        goto after_0;
    // 0x80800E44: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x80800E48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E50: jal         0x80100074
    // 0x80800E54: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x80800E54: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_1:
    // 0x80800E58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E5C: jal         0x80100094
    // 0x80800E60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800E60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800E64: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800E68: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800E6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800E70: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800E74: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800E78: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800E7C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800E80: jal         0x80800D38
    // 0x80800E84: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    suspline_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x80800E84: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_3:
    // 0x80800E88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E90: jr          $ra
    // 0x80800E94: nop

    return;
    // 0x80800E94: nop

    // 0x80800E98: nop

    // 0x80800E9C: nop

;}
RECOMP_FUNC void badeathmatch_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800104: jal         0x800EA068
    // 0x80800108: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_800EA068(rdram, ctx);
        goto after_0;
    // 0x80800108: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_0:
    // 0x8080010C: beql        $v0, $zero, L_80800140
    if (ctx->r2 == 0) {
        // 0x80800110: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800140;
    }
    goto skip_0;
    // 0x80800110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800114: jal         0x8001ACCC
    // 0x80800118: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    heap_alloc(rdram, ctx);
        goto after_1;
    // 0x80800118: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_1:
    // 0x8080011C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800120: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800124: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800128: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x8080012C: jal         0x80019E98
    // 0x80800130: sw          $v0, 0x158($t6)
    MEM_W(0X158, ctx->r14) = ctx->r2;
    aligned8_memset(rdram, ctx);
        goto after_2;
    // 0x80800130: sw          $v0, 0x158($t6)
    MEM_W(0X158, ctx->r14) = ctx->r2;
    after_2:
    // 0x80800134: jal         0x80800000
    // 0x80800138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_badeathmatch(rdram, ctx);
        goto after_3;
    // 0x80800138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8080013C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800140:
    // 0x80800140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800144: jr          $ra
    // 0x80800148: nop

    return;
    // 0x80800148: nop

;}
RECOMP_FUNC void func_80800C3C_chmole_training(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C3C: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800C40: lbu         $t8, 0x72($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X72);
    // 0x80800C44: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800C48: andi        $t9, $t8, 0xFF03
    ctx->r25 = ctx->r24 & 0XFF03;
    // 0x80800C4C: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x80800C50: sb          $t0, 0x72($a0)
    MEM_B(0X72, ctx->r4) = ctx->r8;
    // 0x80800C54: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80800C58: nop

    // 0x80800C5C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80800C60: nop

    // 0x80800C64: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800C68: jr          $ra
    // 0x80800C6C: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80800C6C: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_80800098_chjadestatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080009C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000A4: jal         0x800D8FF8
    // 0x808000A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808000A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000AC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x808000B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000B4: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808000C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C4: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x808000C8: jal         0x80103110
    // 0x808000CC: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x808000CC: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x808000D0: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808000D4: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808000D8: bgezl       $t8, L_808000F4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808000DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000F4;
    }
    goto skip_0;
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000E0: jal         0x808001C0
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001C0_chjadestatue(rdram, ctx);
        goto after_2;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000E8: jal         0x800FFA88
    // 0x808000EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_3;
    // 0x808000EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x808000F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F4:
    // 0x808000F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void func_800BFF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFF70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BFF74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BFF78: jal         0x800D8FF8
    // 0x800BFF7C: nop

    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x800BFF7C: nop

    after_0:
    // 0x800BFF80: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BFF84: addiu       $v0, $v0, -0x7890
    ctx->r2 = ADD32(ctx->r2, -0X7890);
    // 0x800BFF88: lwc1        $f4, 0x134($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X134);
    // 0x800BFF8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BFF90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BFF94: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800BFF98: jr          $ra
    // 0x800BFF9C: swc1        $f6, 0x134($v0)
    MEM_W(0X134, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x800BFF9C: swc1        $f6, 0x134($v0)
    MEM_W(0X134, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80802728_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080272C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802730: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80802734: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802738: jal         0x80100094
    // 0x8080273C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080273C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80802740: beq         $v0, $zero, L_80802750
    if (ctx->r2 == 0) {
        // 0x80802744: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80802750;
    }
    // 0x80802744: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802748: jal         0x800897C8
    // 0x8080274C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x8080274C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80802750:
    // 0x80802750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802758: jr          $ra
    // 0x8080275C: nop

    return;
    // 0x8080275C: nop

;}
RECOMP_FUNC void defrag_prev(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B9BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001B9C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B9C4: lw          $t6, -0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, -0XC);
    // 0x8001B9C8: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8001B9CC: addiu       $t1, $t1, -0x3910
    ctx->r9 = ADD32(ctx->r9, -0X3910);
    // 0x8001B9D0: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8001B9D4: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    // 0x8001B9D8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8001B9DC: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8001B9E0: ori         $at, $at, 0x4240
    ctx->r1 = ctx->r1 | 0X4240;
    // 0x8001B9E4: addu        $v0, $t7, $a2
    ctx->r2 = ADD32(ctx->r15, ctx->r6);
    // 0x8001B9E8: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8001B9EC: bne         $at, $zero, L_8001B9FC
    if (ctx->r1 != 0) {
        // 0x8001B9F0: addiu       $a1, $a0, -0x10
        ctx->r5 = ADD32(ctx->r4, -0X10);
            goto L_8001B9FC;
    }
    // 0x8001B9F0: addiu       $a1, $a0, -0x10
    ctx->r5 = ADD32(ctx->r4, -0X10);
    // 0x8001B9F4: b           L_8001BAEC
    // 0x8001B9F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8001BAEC;
    // 0x8001B9F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8001B9FC:
    // 0x8001B9FC: lw          $a3, 0x0($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X0);
    // 0x8001BA00: lbu         $t8, 0xF($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0XF);
    // 0x8001BA04: srl         $t9, $t8, 6
    ctx->r25 = S32(U32(ctx->r24) >> 6);
    // 0x8001BA08: bne         $t9, $zero, L_8001BA2C
    if (ctx->r25 != 0) {
        // 0x8001BA0C: nop
    
            goto L_8001BA2C;
    }
    // 0x8001BA0C: nop

    // 0x8001BA10: lw          $t2, 0x4($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X4);
    // 0x8001BA14: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001BA18: subu        $t3, $t2, $a3
    ctx->r11 = SUB32(ctx->r10, ctx->r7);
    // 0x8001BA1C: addiu       $t4, $t3, -0x10
    ctx->r12 = ADD32(ctx->r11, -0X10);
    // 0x8001BA20: sltiu       $at, $t4, 0x74
    ctx->r1 = ctx->r12 < 0X74 ? 1 : 0;
    // 0x8001BA24: beq         $at, $zero, L_8001BA34
    if (ctx->r1 == 0) {
        // 0x8001BA28: nop
    
            goto L_8001BA34;
    }
    // 0x8001BA28: nop

L_8001BA2C:
    // 0x8001BA2C: b           L_8001BAEC
    // 0x8001BA30: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8001BAEC;
    // 0x8001BA30: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8001BA34:
    // 0x8001BA34: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001BA38: sw          $t5, -0x3908($at)
    MEM_W(-0X3908, ctx->r1) = ctx->r13;
    // 0x8001BA3C: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8001BA40: lw          $v1, 0x14($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X14);
    // 0x8001BA44: lw          $t0, 0x10($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X10);
    // 0x8001BA48: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8001BA4C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001BA50: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8001BA54: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8001BA58: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8001BA5C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8001BA60: jal         0x80019E70
    // 0x8001BA64: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    aligned8_memcpy(rdram, ctx);
        goto after_0;
    // 0x8001BA64: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x8001BA68: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8001BA6C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8001BA70: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8001BA74: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8001BA78: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x8001BA7C: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x8001BA80: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x8001BA84: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8001BA88: sw          $a0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r4;
    // 0x8001BA8C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8001BA90: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8001BA94: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8001BA98: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
    // 0x8001BA9C: sw          $a0, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r4;
    // 0x8001BAA0: sw          $a0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r4;
    // 0x8001BAA4: lbu         $t2, 0xF($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0XF);
    // 0x8001BAA8: sw          $v1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r3;
    // 0x8001BAAC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x8001BAB0: andi        $t4, $t2, 0xFF3F
    ctx->r12 = ctx->r10 & 0XFF3F;
    // 0x8001BAB4: andi        $t6, $t4, 0xF7
    ctx->r14 = ctx->r12 & 0XF7;
    // 0x8001BAB8: sb          $t4, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r12;
    // 0x8001BABC: sb          $t6, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r14;
    // 0x8001BAC0: andi        $t7, $t6, 0xFB
    ctx->r15 = ctx->r14 & 0XFB;
    // 0x8001BAC4: sb          $t7, 0xF($a0)
    MEM_B(0XF, ctx->r4) = ctx->r15;
    // 0x8001BAC8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8001BACC: srl         $t8, $v0, 8
    ctx->r24 = S32(U32(ctx->r2) >> 8);
    // 0x8001BAD0: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8001BAD4: xor         $t2, $t9, $v0
    ctx->r10 = ctx->r25 ^ ctx->r2;
    // 0x8001BAD8: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x8001BADC: jal         0x8001A6EC
    // 0x8001BAE0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    heap_update_empty_block(rdram, ctx);
        goto after_1;
    // 0x8001BAE0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_1:
    // 0x8001BAE4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8001BAE8: addiu       $v0, $a3, 0x10
    ctx->r2 = ADD32(ctx->r7, 0X10);
L_8001BAEC:
    // 0x8001BAEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001BAF0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001BAF4: jr          $ra
    // 0x8001BAF8: nop

    return;
    // 0x8001BAF8: nop

;}
RECOMP_FUNC void _bsbtrot_entrypoint_41(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082D08: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082D08);
    return;
    // 0x80082D0C: addi        $t0, $zero, 0xA4
    ctx->r8 = ADD32(0, 0XA4);
;}
RECOMP_FUNC void _bsbpeck_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AD8: syscall     25
    recomp_syscall_handler(rdram, ctx, 0x80082AD8);
    return;
    // 0x80082ADC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bskaz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800832E0: syscall     53
    recomp_syscall_handler(rdram, ctx, 0x800832E0);
    return;
    // 0x800832E4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsdronefired_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800830C0: syscall     42
    recomp_syscall_handler(rdram, ctx, 0x800830C0);
    return;
    // 0x800830C4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800BA5B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA5B0: sh          $a1, 0x84($a0)
    MEM_H(0X84, ctx->r4) = ctx->r5;
    // 0x800BA5B4: jr          $ra
    // 0x800BA5B8: sh          $a2, 0x86($a0)
    MEM_H(0X86, ctx->r4) = ctx->r6;
    return;
    // 0x800BA5B8: sh          $a2, 0x86($a0)
    MEM_H(0X86, ctx->r4) = ctx->r6;
;}
RECOMP_FUNC void ncpod_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808009E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808009F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808009F4: jal         0x80110024
    // 0x808009F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80110024(rdram, ctx);
        goto after_0;
    // 0x808009F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808009FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800A00: jal         0x800A940C
    // 0x80800A04: lw          $a0, 0x38($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X38);
    func_800A940C(rdram, ctx);
        goto after_1;
    // 0x80800A04: lw          $a0, 0x38($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X38);
    after_1:
    // 0x80800A08: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A10: jal         0x808005C0
    // 0x80800A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ncpod_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x80800A14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800A18: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A1C: bnel        $t6, $zero, L_80800AB4
    if (ctx->r14 != 0) {
        // 0x80800A20: lw          $t3, 0x10($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X10);
            goto L_80800AB4;
    }
    goto skip_0;
    // 0x80800A20: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x80800A24: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80800A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A2C: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x80800A30: bne         $t7, $zero, L_80800AB0
    if (ctx->r15 != 0) {
        // 0x80800A34: andi        $t8, $v0, 0x4000
        ctx->r24 = ctx->r2 & 0X4000;
            goto L_80800AB0;
    }
    // 0x80800A34: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x80800A38: beq         $t8, $zero, L_80800A48
    if (ctx->r24 == 0) {
        // 0x80800A3C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80800A48;
    }
    // 0x80800A3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800A40: b           L_80800A48
    // 0x80800A44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80800A48;
    // 0x80800A44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80800A48:
    // 0x80800A48: jal         0x808008AC
    // 0x80800A4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ncpod_entrypoint_15(rdram, ctx);
        goto after_3;
    // 0x80800A4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800A50: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x80800A54: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800A58: sll         $t0, $t9, 12
    ctx->r8 = S32(ctx->r25 << 12);
    // 0x80800A5C: bgezl       $t0, L_80800A74
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800A60: lwc1        $f0, 0x44($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
            goto L_80800A74;
    }
    goto skip_1;
    // 0x80800A60: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    skip_1:
    // 0x80800A64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800A68: b           L_80800A78
    // 0x80800A6C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
        goto L_80800A78;
    // 0x80800A6C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800A70: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
L_80800A74:
    // 0x80800A74: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80800A78:
    // 0x80800A78: jal         0x800C5148
    // 0x80800A7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800C5148(rdram, ctx);
        goto after_4;
    // 0x80800A7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800A80: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x80800A84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A88: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x80800A8C: bgezl       $t2, L_80800AA4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800A90: lwc1        $f0, 0x48($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
            goto L_80800AA4;
    }
    goto skip_2;
    // 0x80800A90: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    skip_2:
    // 0x80800A94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800A98: b           L_80800AA8
    // 0x80800A9C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
        goto L_80800AA8;
    // 0x80800A9C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800AA0: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
L_80800AA4:
    // 0x80800AA4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80800AA8:
    // 0x80800AA8: jal         0x800C51A4
    // 0x80800AAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800C51A4(rdram, ctx);
        goto after_5;
    // 0x80800AAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
L_80800AB0:
    // 0x80800AB0: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
L_80800AB4:
    // 0x80800AB4: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x80800AB8: beq         $t4, $zero, L_80800AC8
    if (ctx->r12 == 0) {
        // 0x80800ABC: nop
    
            goto L_80800AC8;
    }
    // 0x80800ABC: nop

    // 0x80800AC0: jal         0x80800038
    // 0x80800AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800038_ncpod(rdram, ctx);
        goto after_6;
    // 0x80800AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80800AC8:
    // 0x80800AC8: jal         0x808000AC
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000AC_ncpod(rdram, ctx);
        goto after_7;
    // 0x80800ACC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800AD0: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AD4: beq         $t5, $zero, L_80800AE8
    if (ctx->r13 == 0) {
        // 0x80800AD8: nop
    
            goto L_80800AE8;
    }
    // 0x80800AD8: nop

    // 0x80800ADC: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x80800AE0: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x80800AE4: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_80800AE8:
    // 0x80800AE8: jal         0x80015178
    // 0x80800AEC: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    func_80015178(rdram, ctx);
        goto after_8;
    // 0x80800AEC: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    after_8:
    // 0x80800AF0: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80800AF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AF8: andi        $t8, $v0, 0x200
    ctx->r24 = ctx->r2 & 0X200;
    // 0x80800AFC: beq         $t8, $zero, L_80800B0C
    if (ctx->r24 == 0) {
        // 0x80800B00: sll         $t9, $v0, 15
        ctx->r25 = S32(ctx->r2 << 15);
            goto L_80800B0C;
    }
    // 0x80800B00: sll         $t9, $v0, 15
    ctx->r25 = S32(ctx->r2 << 15);
    // 0x80800B04: b           L_80800B1C
    // 0x80800B08: addiu       $s0, $zero, 0x200
    ctx->r16 = ADD32(0, 0X200);
        goto L_80800B1C;
    // 0x80800B08: addiu       $s0, $zero, 0x200
    ctx->r16 = ADD32(0, 0X200);
L_80800B0C:
    // 0x80800B0C: bgez        $t9, L_80800B1C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800B10: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800B1C;
    }
    // 0x80800B10: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800B14: b           L_80800B1C
    // 0x80800B18: lui         $s0, 0x1
    ctx->r16 = S32(0X1 << 16);
        goto L_80800B1C;
    // 0x80800B18: lui         $s0, 0x1
    ctx->r16 = S32(0X1 << 16);
L_80800B1C:
    // 0x80800B1C: jal         0x8010F9C0
    // 0x80800B20: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010F9C0(rdram, ctx);
        goto after_9;
    // 0x80800B20: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x80800B24: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x80800B28: bnel        $s0, $at, L_80800B4C
    if (ctx->r16 != ctx->r1) {
        // 0x80800B2C: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80800B4C;
    }
    goto skip_3;
    // 0x80800B2C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    skip_3:
    // 0x80800B30: jal         0x80110014
    // 0x80800B34: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80110014(rdram, ctx);
        goto after_10;
    // 0x80800B34: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_10:
    // 0x80800B38: jal         0x801108A0
    // 0x80800B3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_801108A0(rdram, ctx);
        goto after_11;
    // 0x80800B3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80800B40: b           L_80800B68
    // 0x80800B44: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_80800B68;
    // 0x80800B44: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B48: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
L_80800B4C:
    // 0x80800B4C: bnel        $s0, $at, L_80800B68
    if (ctx->r16 != ctx->r1) {
        // 0x80800B50: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_80800B68;
    }
    goto skip_4;
    // 0x80800B50: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x80800B54: jal         0x80110014
    // 0x80800B58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80110014(rdram, ctx);
        goto after_12;
    // 0x80800B58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x80800B5C: jal         0x80110928
    // 0x80800B60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110928(rdram, ctx);
        goto after_13;
    // 0x80800B60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x80800B64: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_80800B68:
    // 0x80800B68: bnel        $t0, $zero, L_80800B7C
    if (ctx->r8 != 0) {
        // 0x80800B6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800B7C;
    }
    goto skip_5;
    // 0x80800B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80800B70: jal         0x8010FD88
    // 0x80800B74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8010FD88(rdram, ctx);
        goto after_14;
    // 0x80800B74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_14:
    // 0x80800B78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B7C:
    // 0x80800B7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B84: jr          $ra
    // 0x80800B88: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    return;
    // 0x80800B88: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80800194_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800198: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080019C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x808001A0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808001A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x808001AC: jal         0x800F64A4
    // 0x808001B0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    func_800F64A4(rdram, ctx);
        goto after_0;
    // 0x808001B0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    after_0:
    // 0x808001B4: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808001B8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x808001BC: jal         0x800F651C
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F651C(rdram, ctx);
        goto after_1;
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001C4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808001C8: jal         0x800F6C5C
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_2;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001D0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808001D4: jal         0x800F72DC
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F72DC(rdram, ctx);
        goto after_3;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001DC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808001E0: jal         0x800F56AC
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F56AC(rdram, ctx);
        goto after_4;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001E8: xori        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 ^ 0X10;
    // 0x808001EC: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x808001F0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x808001F4: jal         0x800F6478
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6478(rdram, ctx);
        goto after_5;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808001FC: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800200: beq         $t8, $zero, L_80800254
    if (ctx->r24 == 0) {
        // 0x80800204: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80800254;
    }
    // 0x80800204: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80800208: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x8080020C: sltu        $t9, $zero, $v0
    ctx->r25 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800210: beq         $t9, $zero, L_80800254
    if (ctx->r25 == 0) {
        // 0x80800214: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80800254;
    }
    // 0x80800214: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80800218: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8080021C: sltu        $t0, $zero, $v0
    ctx->r8 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800220: beq         $t0, $zero, L_80800254
    if (ctx->r8 == 0) {
        // 0x80800224: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80800254;
    }
    // 0x80800224: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80800228: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8080022C: sltu        $t1, $zero, $v0
    ctx->r9 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800230: bne         $t1, $zero, L_80800254
    if (ctx->r9 != 0) {
        // 0x80800234: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80800254;
    }
    // 0x80800234: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80800238: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8080023C: sltu        $t2, $zero, $v0
    ctx->r10 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800240: beq         $t2, $zero, L_80800254
    if (ctx->r10 == 0) {
        // 0x80800244: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_80800254;
    }
    // 0x80800244: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80800248: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8080024C: sltiu       $t3, $v0, 0x1
    ctx->r11 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800250: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80800254:
    // 0x80800254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800258: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080025C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800260: jr          $ra
    // 0x80800264: nop

    return;
    // 0x80800264: nop

;}
RECOMP_FUNC void func_80800F54_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F5C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(443, 0X1E50) << 16);
    // 0x80800F60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800F64: addiu       $a2, $a2, 0x1E50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(443, 0X1E50));
    // 0x80800F68: jal         0x8009D454
    // 0x80800F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D454(rdram, ctx);
        goto after_0;
    // 0x80800F6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800F70: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800F74: sb          $v0, 0x165($t6)
    MEM_B(0X165, ctx->r14) = ctx->r2;
    // 0x80800F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F80: jr          $ra
    // 0x80800F84: nop

    return;
    // 0x80800F84: nop

;}
RECOMP_FUNC void func_808000C4_ncbasuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000CC: jal         0x80110840
    // 0x808000D0: nop

    func_80110840(rdram, ctx);
        goto after_0;
    // 0x808000D0: nop

    after_0:
    // 0x808000D4: jal         0x800F53D0
    // 0x808000D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F53D0(rdram, ctx);
        goto after_1;
    // 0x808000D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808000DC: jal         0x80092BD0
    // 0x808000E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80092BD0(rdram, ctx);
        goto after_2;
    // 0x808000E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000EC: jr          $ra
    // 0x808000F0: nop

    return;
    // 0x808000F0: nop

;}
RECOMP_FUNC void sukickball_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A28: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800A2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800A30: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80800A34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A38: jal         0x80100094
    // 0x80800A3C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A3C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800A40: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800A44: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800A48: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800A4C: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x80800A50: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800A54: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80800A58: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800A5C: bne         $a1, $t8, L_80800CA0
    if (ctx->r5 != ctx->r24) {
        // 0x80800A60: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800CA0;
    }
    // 0x80800A60: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800A64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A68: beq         $a2, $at, L_80800A98
    if (ctx->r6 == ctx->r1) {
        // 0x80800A6C: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_80800A98;
    }
    // 0x80800A6C: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80800A70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800A74: beq         $a2, $at, L_80800B40
    if (ctx->r6 == ctx->r1) {
        // 0x80800A78: sll         $a0, $a3, 2
        ctx->r4 = S32(ctx->r7 << 2);
            goto L_80800B40;
    }
    // 0x80800A78: sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7 << 2);
    // 0x80800A7C: beq         $a2, $a1, L_80800BA0
    if (ctx->r6 == ctx->r5) {
        // 0x80800A80: sll         $a0, $a3, 2
        ctx->r4 = S32(ctx->r7 << 2);
            goto L_80800BA0;
    }
    // 0x80800A80: sll         $a0, $a3, 2
    ctx->r4 = S32(ctx->r7 << 2);
    // 0x80800A84: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800A88: beq         $a2, $at, L_80800AEC
    if (ctx->r6 == ctx->r1) {
        // 0x80800A8C: sll         $t4, $a3, 2
        ctx->r12 = S32(ctx->r7 << 2);
            goto L_80800AEC;
    }
    // 0x80800A8C: sll         $t4, $a3, 2
    ctx->r12 = S32(ctx->r7 << 2);
    // 0x80800A90: b           L_80800C00
    // 0x80800A94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
        goto L_80800C00;
    // 0x80800A94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80800A98:
    // 0x80800A98: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x80800A9C: lw          $t0, 0x20($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X20);
    // 0x80800AA0: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x80800AA4: bne         $a3, $zero, L_80800AB8
    if (ctx->r7 != 0) {
        // 0x80800AA8: sw          $t1, 0x20($v1)
        MEM_W(0X20, ctx->r3) = ctx->r9;
            goto L_80800AB8;
    }
    // 0x80800AA8: sw          $t1, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r9;
    // 0x80800AAC: lbu         $t2, 0x39($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X39);
    // 0x80800AB0: bne         $a1, $t2, L_80800ADC
    if (ctx->r5 != ctx->r10) {
        // 0x80800AB4: nop
    
            goto L_80800ADC;
    }
    // 0x80800AB4: nop

L_80800AB8:
    // 0x80800AB8: lbu         $t3, 0x39($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X39);
    // 0x80800ABC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800AC0: bne         $a1, $t3, L_80800AE4
    if (ctx->r5 != ctx->r11) {
        // 0x80800AC4: nop
    
            goto L_80800AE4;
    }
    // 0x80800AC4: nop

    // 0x80800AC8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800ACC: jal         0x800DC298
    // 0x80800AD0: nop

    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x80800AD0: nop

    after_1:
    // 0x80800AD4: beq         $v0, $zero, L_80800AE4
    if (ctx->r2 == 0) {
        // 0x80800AD8: nop
    
            goto L_80800AE4;
    }
    // 0x80800AD8: nop

L_80800ADC:
    // 0x80800ADC: b           L_80800BFC
    // 0x80800AE0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80800BFC;
    // 0x80800AE0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80800AE4:
    // 0x80800AE4: b           L_80800BFC
    // 0x80800AE8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800BFC;
    // 0x80800AE8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800AEC:
    // 0x80800AEC: addu        $v1, $v0, $t4
    ctx->r3 = ADD32(ctx->r2, ctx->r12);
    // 0x80800AF0: lw          $t5, 0x20($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X20);
    // 0x80800AF4: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x80800AF8: bne         $a3, $zero, L_80800B0C
    if (ctx->r7 != 0) {
        // 0x80800AFC: sw          $t6, 0x20($v1)
        MEM_W(0X20, ctx->r3) = ctx->r14;
            goto L_80800B0C;
    }
    // 0x80800AFC: sw          $t6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r14;
    // 0x80800B00: lbu         $t7, 0x39($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X39);
    // 0x80800B04: bne         $a1, $t7, L_80800B30
    if (ctx->r5 != ctx->r15) {
        // 0x80800B08: nop
    
            goto L_80800B30;
    }
    // 0x80800B08: nop

L_80800B0C:
    // 0x80800B0C: lbu         $t8, 0x39($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X39);
    // 0x80800B10: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800B14: bne         $a1, $t8, L_80800B38
    if (ctx->r5 != ctx->r24) {
        // 0x80800B18: nop
    
            goto L_80800B38;
    }
    // 0x80800B18: nop

    // 0x80800B1C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800B20: jal         0x800DC298
    // 0x80800B24: nop

    func_800DC298(rdram, ctx);
        goto after_2;
    // 0x80800B24: nop

    after_2:
    // 0x80800B28: beq         $v0, $zero, L_80800B38
    if (ctx->r2 == 0) {
        // 0x80800B2C: nop
    
            goto L_80800B38;
    }
    // 0x80800B2C: nop

L_80800B30:
    // 0x80800B30: b           L_80800BFC
    // 0x80800B34: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80800BFC;
    // 0x80800B34: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80800B38:
    // 0x80800B38: b           L_80800BFC
    // 0x80800B3C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800BFC;
    // 0x80800B3C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800B40:
    // 0x80800B40: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x80800B44: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x80800B48: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800B4C: bgez        $t0, L_80800B58
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800B50: sw          $t0, 0x20($v1)
        MEM_W(0X20, ctx->r3) = ctx->r8;
            goto L_80800B58;
    }
    // 0x80800B50: sw          $t0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r8;
    // 0x80800B54: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
L_80800B58:
    // 0x80800B58: bnel        $a0, $zero, L_80800B70
    if (ctx->r4 != 0) {
        // 0x80800B5C: lbu         $t3, 0x39($v0)
        ctx->r11 = MEM_BU(ctx->r2, 0X39);
            goto L_80800B70;
    }
    goto skip_0;
    // 0x80800B5C: lbu         $t3, 0x39($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X39);
    skip_0:
    // 0x80800B60: lbu         $t2, 0x39($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X39);
    // 0x80800B64: bne         $a1, $t2, L_80800B90
    if (ctx->r5 != ctx->r10) {
        // 0x80800B68: nop
    
            goto L_80800B90;
    }
    // 0x80800B68: nop

    // 0x80800B6C: lbu         $t3, 0x39($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X39);
L_80800B70:
    // 0x80800B70: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800B74: bne         $a1, $t3, L_80800B98
    if (ctx->r5 != ctx->r11) {
        // 0x80800B78: nop
    
            goto L_80800B98;
    }
    // 0x80800B78: nop

    // 0x80800B7C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800B80: jal         0x800DC298
    // 0x80800B84: nop

    func_800DC298(rdram, ctx);
        goto after_3;
    // 0x80800B84: nop

    after_3:
    // 0x80800B88: beq         $v0, $zero, L_80800B98
    if (ctx->r2 == 0) {
        // 0x80800B8C: nop
    
            goto L_80800B98;
    }
    // 0x80800B8C: nop

L_80800B90:
    // 0x80800B90: b           L_80800BFC
    // 0x80800B94: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800BFC;
    // 0x80800B94: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800B98:
    // 0x80800B98: b           L_80800BFC
    // 0x80800B9C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80800BFC;
    // 0x80800B9C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80800BA0:
    // 0x80800BA0: addu        $v1, $v0, $a0
    ctx->r3 = ADD32(ctx->r2, ctx->r4);
    // 0x80800BA4: lw          $t4, 0x20($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X20);
    // 0x80800BA8: addiu       $t5, $t4, -0x2
    ctx->r13 = ADD32(ctx->r12, -0X2);
    // 0x80800BAC: bgez        $t5, L_80800BB8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80800BB0: sw          $t5, 0x20($v1)
        MEM_W(0X20, ctx->r3) = ctx->r13;
            goto L_80800BB8;
    }
    // 0x80800BB0: sw          $t5, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r13;
    // 0x80800BB4: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
L_80800BB8:
    // 0x80800BB8: bnel        $a0, $zero, L_80800BD0
    if (ctx->r4 != 0) {
        // 0x80800BBC: lbu         $t8, 0x39($v0)
        ctx->r24 = MEM_BU(ctx->r2, 0X39);
            goto L_80800BD0;
    }
    goto skip_1;
    // 0x80800BBC: lbu         $t8, 0x39($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X39);
    skip_1:
    // 0x80800BC0: lbu         $t7, 0x39($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X39);
    // 0x80800BC4: bne         $a1, $t7, L_80800BF0
    if (ctx->r5 != ctx->r15) {
        // 0x80800BC8: nop
    
            goto L_80800BF0;
    }
    // 0x80800BC8: nop

    // 0x80800BCC: lbu         $t8, 0x39($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X39);
L_80800BD0:
    // 0x80800BD0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800BD4: bnel        $a1, $t8, L_80800BFC
    if (ctx->r5 != ctx->r24) {
        // 0x80800BD8: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_80800BFC;
    }
    goto skip_2;
    // 0x80800BD8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    skip_2:
    // 0x80800BDC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800BE0: jal         0x800DC298
    // 0x80800BE4: nop

    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x80800BE4: nop

    after_4:
    // 0x80800BE8: beql        $v0, $zero, L_80800BFC
    if (ctx->r2 == 0) {
        // 0x80800BEC: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_80800BFC;
    }
    goto skip_3;
    // 0x80800BEC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    skip_3:
L_80800BF0:
    // 0x80800BF0: b           L_80800BFC
    // 0x80800BF4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800BFC;
    // 0x80800BF4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800BF8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80800BFC:
    // 0x80800BFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80800C00:
    // 0x80800C00: beq         $v1, $at, L_80800C1C
    if (ctx->r3 == ctx->r1) {
        // 0x80800C04: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80800C1C;
    }
    // 0x80800C04: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800C0C: beq         $v1, $at, L_80800C60
    if (ctx->r3 == ctx->r1) {
        // 0x80800C10: lw          $t1, 0x1C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X1C);
            goto L_80800C60;
    }
    // 0x80800C10: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C14: b           L_80800CA4
    // 0x80800C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800CA4;
    // 0x80800C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800C1C:
    // 0x80800C1C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800C20: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80800C24: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800C28: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80800C2C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800C30: ori         $a0, $a0, 0x453A
    ctx->r4 = ctx->r4 | 0X453A;
    // 0x80800C34: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    // 0x80800C38: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800C3C: bc1fl       L_80800CA4
    if (!c1cs) {
        // 0x80800C40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800CA4;
    }
    goto skip_4;
    // 0x80800C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80800C44: jal         0x800C4140
    // 0x80800C48: ori         $a2, $a2, 0x640
    ctx->r6 = ctx->r6 | 0X640;
    func_800C4140(rdram, ctx);
        goto after_5;
    // 0x80800C48: ori         $a2, $a2, 0x640
    ctx->r6 = ctx->r6 | 0X640;
    after_5:
    // 0x80800C4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800C50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800C54: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C58: b           L_80800CA0
    // 0x80800C5C: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
        goto L_80800CA0;
    // 0x80800C5C: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
L_80800C60:
    // 0x80800C60: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800C64: lwc1        $f16, 0x4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80800C68: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800C6C: lui         $a0, 0x7FFF
    ctx->r4 = S32(0X7FFF << 16);
    // 0x80800C70: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80800C74: ori         $a0, $a0, 0x453B
    ctx->r4 = ctx->r4 | 0X453B;
    // 0x80800C78: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    // 0x80800C7C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800C80: bc1fl       L_80800CA4
    if (!c1cs) {
        // 0x80800C84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800CA4;
    }
    goto skip_5;
    // 0x80800C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80800C88: jal         0x800C4140
    // 0x80800C8C: ori         $a2, $a2, 0x640
    ctx->r6 = ctx->r6 | 0X640;
    func_800C4140(rdram, ctx);
        goto after_6;
    // 0x80800C8C: ori         $a2, $a2, 0x640
    ctx->r6 = ctx->r6 | 0X640;
    after_6:
    // 0x80800C90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800C94: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800C98: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C9C: swc1        $f18, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f18.u32l;
L_80800CA0:
    // 0x80800CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800CA4:
    // 0x80800CA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CA8: jr          $ra
    // 0x80800CAC: nop

    return;
    // 0x80800CAC: nop

;}
RECOMP_FUNC void _gcnewoption_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087CF8: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087CF8);
    return;
    // 0x80087CFC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80800E34_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E40: jal         0x808009B0
    // 0x80800E44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808009B0_bssub(rdram, ctx);
        goto after_0;
    // 0x80800E44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800E48: jal         0x800EA068
    // 0x80800E4C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    func_800EA068(rdram, ctx);
        goto after_1;
    // 0x80800E4C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_1:
    // 0x80800E50: beq         $v0, $zero, L_80800E68
    if (ctx->r2 == 0) {
        // 0x80800E54: sw          $v0, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r2;
            goto L_80800E68;
    }
    // 0x80800E54: sw          $v0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r2;
    // 0x80800E58: jal         0x80800B2C
    // 0x80800E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B2C_bssub(rdram, ctx);
        goto after_2;
    // 0x80800E5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800E60: b           L_80800E88
    // 0x80800E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800E88;
    // 0x80800E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E68:
    // 0x80800E68: jal         0x80084D10
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bafpctrl_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x80800E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800E70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E74: jal         0x80085248
    // 0x80800E78: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    _basudie_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800E78: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_4:
    // 0x80800E7C: jal         0x80800C60
    // 0x80800E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C60_bssub(rdram, ctx);
        goto after_5;
    // 0x80800E80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800E88:
    // 0x80800E88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E90: jr          $ra
    // 0x80800E94: nop

    return;
    // 0x80800E94: nop

;}
RECOMP_FUNC void func_800C4244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4244: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C4248: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C424C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C4250: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C4254: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C4258: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800C425C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C4260: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C4264: jal         0x800C401C
    // 0x800C4268: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C401C(rdram, ctx);
        goto after_0;
    // 0x800C4268: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800C426C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C4270: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C4274: jr          $ra
    // 0x800C4278: nop

    return;
    // 0x800C4278: nop

;}
RECOMP_FUNC void bssplitup_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C0: jal         0x800A0CF4
    // 0x808006C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_0;
    // 0x808006C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808006D0: jr          $ra
    // 0x808006D4: nop

    return;
    // 0x808006D4: nop

;}
RECOMP_FUNC void _bsjig_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083218: syscall     51
    recomp_syscall_handler(rdram, ctx, 0x80083218);
    return;
    // 0x8008321C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80801DD8_chfactorytwinklies(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DD8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801DDC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801DE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801DE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801DE8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80801DEC: jal         0x80106790
    // 0x80801DF0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801DF0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80801DF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801DF8: jal         0x80100094
    // 0x80801DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801DFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801E00: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80801E04: jal         0x800B53A4
    // 0x80801E08: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x80801E08: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_2:
    // 0x80801E0C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E14: jal         0x80103DFC
    // 0x80801E18: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80103DFC(rdram, ctx);
        goto after_3;
    // 0x80801E18: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80801E1C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1308, 0X243C) << 16);
    // 0x80801E20: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80801E24: addiu       $t6, $t6, 0x243C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1308, 0X243C));
    // 0x80801E28: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801E2C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801E30: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801E34: jal         0x800BABB8
    // 0x80801E38: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80801E38: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80801E3C: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80801E40: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1308, 0X2478) << 16);
    // 0x80801E44: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801E48: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80801E4C: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80801E50: jal         0x800BA3FC
    // 0x80801E54: lh          $a1, 0x2478($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1308, 0X2478));
    func_800BA3FC(rdram, ctx);
        goto after_5;
    // 0x80801E54: lh          $a1, 0x2478($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(1308, 0X2478));
    after_5:
    // 0x80801E58: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801E5C: jal         0x800BA22C
    // 0x80801E60: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_800BA22C(rdram, ctx);
        goto after_6;
    // 0x80801E60: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_6:
    // 0x80801E64: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80801E68: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80801E6C: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x80801E70: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80801E74: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80801E78: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80801E7C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80801E80: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80801E84: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x80801E88: lw          $t5, 0x40($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X40);
    // 0x80801E8C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1308, 0X2468) << 16);
    // 0x80801E90: addiu       $a3, $a3, 0x2468
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1308, 0X2468));
    // 0x80801E94: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80801E98: sw          $t6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r14;
    // 0x80801E9C: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80801EA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801EA4: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801EA8: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x80801EAC: jal         0x8010D930
    // 0x80801EB0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_8010D930(rdram, ctx);
        goto after_7;
    // 0x80801EB0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_7:
    // 0x80801EB4: jal         0x800FFAB0
    // 0x80801EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_8;
    // 0x80801EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801EBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801EC0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801EC4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801EC8: jr          $ra
    // 0x80801ECC: nop

    return;
    // 0x80801ECC: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800828: jal         0x808000D4
    // 0x8080082C: nop

    bstaxi_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080082C: nop

    after_0:
    // 0x80800830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800838: jr          $ra
    // 0x8080083C: nop

    return;
    // 0x8080083C: nop

;}
RECOMP_FUNC void func_8080061C_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080061C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800620: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800624: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800628: jal         0x8009E704
    // 0x8080062C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bs_getNextState(rdram, ctx);
        goto after_0;
    // 0x8080062C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800630: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800638: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080063C: jal         0x8009CA70
    // 0x80800640: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    func_8009CA70(rdram, ctx);
        goto after_1;
    // 0x80800640: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_1:
    // 0x80800644: bnel        $v0, $zero, L_80800700
    if (ctx->r2 != 0) {
        // 0x80800648: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800700;
    }
    goto skip_0;
    // 0x80800648: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080064C: jal         0x8009E474
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E474(rdram, ctx);
        goto after_2;
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800658: jal         0x800931AC
    // 0x8080065C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800931AC(rdram, ctx);
        goto after_3;
    // 0x8080065C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800660: jal         0x8009F1E0
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_resetZones(rdram, ctx);
        goto after_4;
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: jal         0x800A0CF4
    // 0x80800670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_5;
    // 0x80800670: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80800674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800678: jal         0x800A0CE8
    // 0x8080067C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CE8(rdram, ctx);
        goto after_6;
    // 0x8080067C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800684: jal         0x8009BF5C
    // 0x80800688: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_7;
    // 0x80800688: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x8080068C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800690: jal         0x8009C4CC
    // 0x80800694: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_8;
    // 0x80800694: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_8:
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080069C: jal         0x80095774
    // 0x808006A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    baflag_clear(rdram, ctx);
        goto after_9;
    // 0x808006A0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x808006A4: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808006A8: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B0: beq         $t6, $at, L_808006C0
    if (ctx->r14 == ctx->r1) {
        // 0x808006B4: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_808006C0;
    }
    // 0x808006B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808006B8: jal         0x800917A8
    // 0x808006BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    bastatetimer_set(rdram, ctx);
        goto after_10;
    // 0x808006BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_10:
L_808006C0:
    // 0x808006C0: jal         0x808004B4
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bsbtrot(rdram, ctx);
        goto after_11;
    // 0x808006C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808006C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006CC: jal         0x800962B0
    // 0x808006D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800962B0(rdram, ctx);
        goto after_12;
    // 0x808006D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006D8: jal         0x8008CA4C
    // 0x808006DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008CA4C(rdram, ctx);
        goto after_13;
    // 0x808006DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x808006E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808006EC: jal         0x80094F14
    // 0x808006F0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_80094F14(rdram, ctx);
        goto after_14;
    // 0x808006F0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_14:
    // 0x808006F4: jal         0x80085048
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_14(rdram, ctx);
        goto after_15;
    // 0x808006F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808006FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800700:
    // 0x80800700: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800704: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800708: jr          $ra
    // 0x8080070C: nop

    return;
    // 0x8080070C: nop

;}
RECOMP_FUNC void func_80800EC0_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800EC8: jal         0x808004CC
    // 0x80800ECC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexsmall_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800ECC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800ED0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800ED4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800ED8: jal         0x80800CA4
    // 0x80800EDC: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    func_80800CA4_bstrexsmall(rdram, ctx);
        goto after_1;
    // 0x80800EDC: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80800EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EE8: jr          $ra
    // 0x80800EEC: nop

    return;
    // 0x80800EEC: nop

;}
RECOMP_FUNC void func_80801E08_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801E0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801E10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80801E14: lbu         $t6, 0xE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XE);
    // 0x80801E18: lbu         $t8, 0x12($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X12);
    // 0x80801E1C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801E20: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80801E24: andi        $v0, $t7, 0xFF
    ctx->r2 = ctx->r15 & 0XFF;
    // 0x80801E28: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80801E2C: bne         $at, $zero, L_80801E40
    if (ctx->r1 != 0) {
        // 0x80801E30: sb          $t7, 0xE($a0)
        MEM_B(0XE, ctx->r4) = ctx->r15;
            goto L_80801E40;
    }
    // 0x80801E30: sb          $t7, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r15;
    // 0x80801E34: lbu         $t9, 0x10($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X10);
    // 0x80801E38: sb          $t9, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r25;
    // 0x80801E3C: andi        $v0, $t9, 0xFF
    ctx->r2 = ctx->r25 & 0XFF;
L_80801E40:
    // 0x80801E40: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80801E44: sra         $t0, $a2, 16
    ctx->r8 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80801E48: lbu         $a1, 0x5($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X5);
    // 0x80801E4C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80801E50: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80801E54: jal         0x80087CF8
    // 0x80801E58: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_0;
    // 0x80801E58: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x80801E5C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80801E60: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80801E64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801E68: nop

    // 0x80801E6C: swc1        $f4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f4.u32l;
    // 0x80801E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801E74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801E78: jr          $ra
    // 0x80801E7C: nop

    return;
    // 0x80801E7C: nop

;}
RECOMP_FUNC void func_8080000C_chsignpost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800018: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080001C: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800024: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800028: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080002C: jal         0x80102FDC
    // 0x80800030: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800030: nop

    after_0:
    // 0x80800034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800038: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x8080003C: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800040: addiu       $t8, $t7, -0x32
    ctx->r24 = ADD32(ctx->r15, -0X32);
    // 0x80800044: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    // 0x80800048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080004C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_800F5F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5F7C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F5F84: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5F88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5F8C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5F90: jal         0x8009C150
    // 0x800F5F94: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_8009C150(rdram, ctx);
        goto after_0;
    // 0x800F5F94: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5FA0: jr          $ra
    // 0x800F5FA4: nop

    return;
    // 0x800F5FA4: nop

;}
