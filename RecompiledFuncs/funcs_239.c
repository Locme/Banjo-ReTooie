#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800728_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080072C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800730: jal         0x80100094
    // 0x80800734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800738: lbu         $t6, 0x26($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X26);
    // 0x8080073C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800740: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1692, 0X45DA) << 16);
    // 0x80800744: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80800748: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8080074C: lh          $v0, 0x45DA($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(1692, 0X45DA));
    // 0x80800750: jr          $ra
    // 0x80800754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EDF2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDF2C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800EDF30: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800EDF34: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800EDF38: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EDF3C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800EDF40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EDF44: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800EDF48: sb          $t6, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r14;
    // 0x800EDF4C: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
    // 0x800EDF50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EDF54: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EDF58: swc1        $f6, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f6.u32l;
    // 0x800EDF5C: swc1        $f0, 0x80($a0)
    MEM_W(0X80, ctx->r4) = ctx->f0.u32l;
    // 0x800EDF60: swc1        $f0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->f0.u32l;
    // 0x800EDF64: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
    // 0x800EDF68: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x800EDF6C: swc1        $f10, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->f10.u32l;
    // 0x800EDF70: swc1        $f0, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->f0.u32l;
    // 0x800EDF74: swc1        $f0, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f0.u32l;
    // 0x800EDF78: bc1f        L_800EDF88
    if (!c1cs) {
        // 0x800EDF7C: swc1        $f0, 0x88($a0)
        MEM_W(0X88, ctx->r4) = ctx->f0.u32l;
            goto L_800EDF88;
    }
    // 0x800EDF7C: swc1        $f0, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f0.u32l;
    // 0x800EDF80: b           L_800EDF90
    // 0x800EDF84: swc1        $f12, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->f12.u32l;
        goto L_800EDF90;
    // 0x800EDF84: swc1        $f12, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->f12.u32l;
L_800EDF88:
    // 0x800EDF88: lwc1        $f18, 0x5E70($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5E70);
    // 0x800EDF8C: swc1        $f18, 0x9C($a0)
    MEM_W(0X9C, ctx->r4) = ctx->f18.u32l;
L_800EDF90:
    // 0x800EDF90: jr          $ra
    // 0x800EDF94: swc1        $f0, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800EDF94: swc1        $f0, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8001E7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E7E0: jr          $ra
    // 0x8001E7E4: lui         $v0, 0x8040
    ctx->r2 = S32(0X8040 << 16);
    return;
    // 0x8001E7E4: lui         $v0, 0x8040
    ctx->r2 = S32(0X8040 << 16);
;}
RECOMP_FUNC void fxgenlist_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2850, 0X30) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2850, 0X30));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2850, 0X30));
;}
RECOMP_FUNC void _gcmapsects_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087F78: syscall     662
    recomp_syscall_handler(rdram, ctx, 0x80087F78);
    return;
    // 0x80087F7C: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void func_808002BC_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002C8: jal         0x80100094
    // 0x808002CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808002CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808002D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002D4: jal         0x80089D48
    // 0x808002D8: lbu         $a0, 0xB0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XB0);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808002D8: lbu         $a0, 0xB0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XB0);
    after_1:
    // 0x808002DC: sb          $v0, 0xB0($s0)
    MEM_B(0XB0, ctx->r16) = ctx->r2;
    // 0x808002E0: jal         0x80089D48
    // 0x808002E4: lbu         $a0, 0xB1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB1);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808002E4: lbu         $a0, 0xB1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB1);
    after_2:
    // 0x808002E8: sb          $v0, 0xB1($s0)
    MEM_B(0XB1, ctx->r16) = ctx->r2;
    // 0x808002EC: jal         0x80089D48
    // 0x808002F0: lbu         $a0, 0xB2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB2);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808002F0: lbu         $a0, 0xB2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB2);
    after_3:
    // 0x808002F4: sb          $v0, 0xB2($s0)
    MEM_B(0XB2, ctx->r16) = ctx->r2;
    // 0x808002F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800300: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800304: jr          $ra
    // 0x80800308: nop

    return;
    // 0x80800308: nop

;}
RECOMP_FUNC void chexploder_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808018F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808018F4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808018F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808018FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80801900: jal         0x80100094
    // 0x80801904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801908: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080190C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801910: jal         0x80100094
    // 0x80801914: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801914: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801918: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8080191C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801920: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801924: lh          $t0, 0xE($t1)
    ctx->r8 = MEM_H(ctx->r9, 0XE);
    // 0x80801928: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8080192C: blezl       $t0, L_8080198C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80801930: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080198C;
    }
    goto skip_0;
    // 0x80801930: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80801934:
    // 0x80801934: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80801938: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8080193C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80801940: beql        $a1, $t6, L_80801980
    if (ctx->r5 == ctx->r14) {
        // 0x80801944: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80801980;
    }
    goto skip_1;
    // 0x80801944: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    skip_1:
    // 0x80801948: lbu         $a0, 0x39($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X39);
    // 0x8080194C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
L_80801950:
    // 0x80801950: bnel        $a0, $v1, L_80801970
    if (ctx->r4 != ctx->r3) {
        // 0x80801954: lh          $v1, 0x2($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X2);
            goto L_80801970;
    }
    goto skip_2;
    // 0x80801954: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    skip_2:
    // 0x80801958: lbu         $t7, 0x36($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X36);
    // 0x8080195C: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x80801960: sb          $t8, 0x36($a2)
    MEM_B(0X36, ctx->r6) = ctx->r24;
    // 0x80801964: b           L_8080197C
    // 0x80801968: lh          $t0, 0xE($t1)
    ctx->r8 = MEM_H(ctx->r9, 0XE);
        goto L_8080197C;
    // 0x80801968: lh          $t0, 0xE($t1)
    ctx->r8 = MEM_H(ctx->r9, 0XE);
    // 0x8080196C: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
L_80801970:
    // 0x80801970: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80801974: bne         $a1, $v1, L_80801950
    if (ctx->r5 != ctx->r3) {
        // 0x80801978: nop
    
            goto L_80801950;
    }
    // 0x80801978: nop

L_8080197C:
    // 0x8080197C: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
L_80801980:
    // 0x80801980: bne         $at, $zero, L_80801934
    if (ctx->r1 != 0) {
        // 0x80801984: addiu       $a2, $a2, 0x3C
        ctx->r6 = ADD32(ctx->r6, 0X3C);
            goto L_80801934;
    }
    // 0x80801984: addiu       $a2, $a2, 0x3C
    ctx->r6 = ADD32(ctx->r6, 0X3C);
    // 0x80801988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080198C:
    // 0x8080198C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801990: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801994: jr          $ra
    // 0x80801998: nop

    return;
    // 0x80801998: nop

;}
RECOMP_FUNC void func_800B7C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7C10: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B7C14: lw          $v1, -0x7D50($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D50);
    // 0x800B7C18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B7C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B7C20: bnel        $v1, $zero, L_800B7C44
    if (ctx->r3 != 0) {
        // 0x800B7C24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B7C44;
    }
    goto skip_0;
    // 0x800B7C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B7C28: jal         0x80088950
    // 0x800B7C2C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    _fxleaves_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800B7C2C: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_0:
    // 0x800B7C30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B7C34: sw          $v0, -0x7D50($at)
    MEM_W(-0X7D50, ctx->r1) = ctx->r2;
    // 0x800B7C38: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B7C3C: lw          $v1, -0x7D50($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D50);
    // 0x800B7C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B7C44:
    // 0x800B7C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B7C48: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B7C4C: jr          $ra
    // 0x800B7C50: nop

    return;
    // 0x800B7C50: nop

;}
RECOMP_FUNC void func_80800108_sueggmove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: lbu         $t6, 0xD($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XD);
    // 0x8080010C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800110: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80800114: bne         $t6, $zero, L_80800124
    if (ctx->r14 != 0) {
        // 0x80800118: nop
    
            goto L_80800124;
    }
    // 0x80800118: nop

    // 0x8080011C: sb          $t7, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r15;
    // 0x80800120: sb          $t8, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r24;
L_80800124:
    // 0x80800124: jr          $ra
    // 0x80800128: nop

    return;
    // 0x80800128: nop

;}
RECOMP_FUNC void func_80800044_chlavaarchgrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800048: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080004C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800050: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800054: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800058: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8080005C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800060: addiu       $a0, $zero, 0xA1A
    ctx->r4 = ADD32(0, 0XA1A);
    // 0x80800064: jal         0x800DA564
    // 0x80800068: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800068: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080006C: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80800070: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1956, 0X610) << 16);
    // 0x80800074: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80800078: srl         $t6, $a1, 7
    ctx->r14 = S32(U32(ctx->r5) >> 7);
    // 0x8080007C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800080: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80800084: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80800088: addiu       $t0, $t0, 0x610
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1956, 0X610));
    // 0x8080008C: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
L_80800090:
    // 0x80800090: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80800094: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x80800098: beq         $a1, $t7, L_808000B0
    if (ctx->r5 == ctx->r15) {
        // 0x8080009C: sll         $t8, $t8, 1
        ctx->r24 = S32(ctx->r24 << 1);
            goto L_808000B0;
    }
    // 0x8080009C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x808000A0: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(1956, 0X610) << 16);
    // 0x808000A4: addiu       $t9, $t9, 0x610
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(1956, 0X610));
    // 0x808000A8: b           L_80800260
    // 0x808000AC: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
        goto L_80800260;
    // 0x808000AC: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
L_808000B0:
    // 0x808000B0: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
    // 0x808000B4: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x808000B8: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x808000BC: beq         $a3, $t1, L_808000D4
    if (ctx->r7 == ctx->r9) {
        // 0x808000C0: sll         $t2, $t2, 1
        ctx->r10 = S32(ctx->r10 << 1);
            goto L_808000D4;
    }
    // 0x808000C0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x808000C4: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(1956, 0X610) << 16);
    // 0x808000C8: addiu       $t3, $t3, 0x610
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(1956, 0X610));
    // 0x808000CC: b           L_80800260
    // 0x808000D0: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
        goto L_80800260;
    // 0x808000D0: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
L_808000D4:
    // 0x808000D4: lhu         $t4, 0x72($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X72);
    // 0x808000D8: lbu         $t6, 0x5($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X5);
    // 0x808000DC: srl         $t5, $t4, 10
    ctx->r13 = S32(U32(ctx->r12) >> 10);
    // 0x808000E0: bnel        $t5, $t6, L_8080024C
    if (ctx->r13 != ctx->r14) {
        // 0x808000E4: sll         $t5, $a0, 2
        ctx->r13 = S32(ctx->r4 << 2);
            goto L_8080024C;
    }
    goto skip_0;
    // 0x808000E4: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    skip_0:
    // 0x808000E8: lbu         $t7, 0x4($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X4);
    // 0x808000EC: bnel        $a2, $t7, L_8080024C
    if (ctx->r6 != ctx->r15) {
        // 0x808000F0: sll         $t5, $a0, 2
        ctx->r13 = S32(ctx->r4 << 2);
            goto L_8080024C;
    }
    goto skip_1;
    // 0x808000F0: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    skip_1:
    // 0x808000F4: lbu         $t8, 0x9($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X9);
    // 0x808000F8: bne         $v0, $t8, L_80800248
    if (ctx->r2 != ctx->r24) {
        // 0x808000FC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80800248;
    }
    // 0x808000FC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800100: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: lbu         $a1, 0x6($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X6);
    // 0x8080010C: jal         0x80101FDC
    // 0x80800110: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x80800110: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_1:
    // 0x80800114: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800118: lbu         $v0, 0x7($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X7);
    // 0x8080011C: beql        $v0, $zero, L_8080017C
    if (ctx->r2 == 0) {
        // 0x80800120: lbu         $t3, 0x8($t0)
        ctx->r11 = MEM_BU(ctx->r8, 0X8);
            goto L_8080017C;
    }
    goto skip_2;
    // 0x80800120: lbu         $t3, 0x8($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X8);
    skip_2:
    // 0x80800124: lbu         $t1, 0x4($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X4);
    // 0x80800128: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080012C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800130: beq         $t1, $zero, L_80800168
    if (ctx->r9 == 0) {
        // 0x80800134: addiu       $a3, $zero, 0x10
        ctx->r7 = ADD32(0, 0X10);
            goto L_80800168;
    }
    // 0x80800134: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80800138: jal         0x80085710
    // 0x8080013C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    _capod_entrypoint_14(rdram, ctx);
        goto after_2;
    // 0x8080013C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_2:
    // 0x80800140: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800144: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080014C: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    // 0x80800150: jal         0x80085708
    // 0x80800154: lbu         $a2, 0x7($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X7);
    _capod_entrypoint_13(rdram, ctx);
        goto after_3;
    // 0x80800154: lbu         $a2, 0x7($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X7);
    after_3:
    // 0x80800158: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8080015C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800160: b           L_80800178
    // 0x80800164: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
        goto L_80800178;
    // 0x80800164: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_80800168:
    // 0x80800168: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080016C: jal         0x80085708
    // 0x80800170: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    _capod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x80800170: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_4:
    // 0x80800174: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
L_80800178:
    // 0x80800178: lbu         $t3, 0x8($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X8);
L_8080017C:
    // 0x8080017C: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80800180: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x80800184: beq         $at, $zero, L_80800240
    if (ctx->r1 == 0) {
        // 0x80800188: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80800240;
    }
    // 0x80800188: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8080018C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1956, 0X5D0) << 16);
    // 0x80800190: addu        $at, $at, $t4
    gpr jr_addend_80800198 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80800194: lw          $t4, 0x5D0($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1956, 0X5D0));
    // 0x80800198: jr          $t4
    // 0x8080019C: nop

    switch (jr_addend_80800198 >> 2) {
        case 0: goto L_808001A0; break;
        case 1: goto L_808001B0; break;
        case 2: goto L_808001D8; break;
        case 3: goto L_808001FC; break;
        case 4: goto L_80800224; break;
        default: switch_error(__func__, 0x80800198, 0x808005D0);
    }
    // 0x8080019C: nop

L_808001A0:
    // 0x808001A0: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808001A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808001A8: b           L_80800240
    // 0x808001AC: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
        goto L_80800240;
    // 0x808001AC: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
L_808001B0:
    // 0x808001B0: addiu       $a0, $zero, 0xA1A
    ctx->r4 = ADD32(0, 0XA1A);
    // 0x808001B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808001B8: jal         0x800DA7A8
    // 0x808001BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_5;
    // 0x808001BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x808001C0: addiu       $a0, $zero, 0x288
    ctx->r4 = ADD32(0, 0X288);
    // 0x808001C4: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    // 0x808001C8: jal         0x80101180
    // 0x808001CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x808001CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x808001D0: b           L_80800240
    // 0x808001D4: nop

        goto L_80800240;
    // 0x808001D4: nop

L_808001D8:
    // 0x808001D8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x808001DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001E0: addiu       $a0, $zero, 0xA1A
    ctx->r4 = ADD32(0, 0XA1A);
    // 0x808001E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808001EC: jal         0x800DA7A8
    // 0x808001F0: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    func_800DA7A8(rdram, ctx);
        goto after_7;
    // 0x808001F0: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    after_7:
    // 0x808001F4: b           L_80800240
    // 0x808001F8: nop

        goto L_80800240;
    // 0x808001F8: nop

L_808001FC:
    // 0x808001FC: addiu       $a0, $zero, 0xA1A
    ctx->r4 = ADD32(0, 0XA1A);
    // 0x80800200: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800204: jal         0x800DA7A8
    // 0x80800208: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_8;
    // 0x80800208: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x8080020C: addiu       $a0, $zero, 0x288
    ctx->r4 = ADD32(0, 0X288);
    // 0x80800210: addiu       $a1, $zero, 0x5D
    ctx->r5 = ADD32(0, 0X5D);
    // 0x80800214: jal         0x80101180
    // 0x80800218: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_9;
    // 0x80800218: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8080021C: b           L_80800240
    // 0x80800220: nop

        goto L_80800240;
    // 0x80800220: nop

L_80800224:
    // 0x80800224: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80800228: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080022C: addiu       $a0, $zero, 0xA1A
    ctx->r4 = ADD32(0, 0XA1A);
    // 0x80800230: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800234: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80800238: jal         0x800DA7A8
    // 0x8080023C: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    func_800DA7A8(rdram, ctx);
        goto after_10;
    // 0x8080023C: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    after_10:
L_80800240:
    // 0x80800240: b           L_80800274
    // 0x80800244: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_80800274;
    // 0x80800244: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80800248:
    // 0x80800248: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
L_8080024C:
    // 0x8080024C: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x80800250: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1956, 0X610) << 16);
    // 0x80800254: addiu       $t6, $t6, 0x610
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1956, 0X610));
    // 0x80800258: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8080025C: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
L_80800260:
    // 0x80800260: addiu       $t0, $t0, 0xA
    ctx->r8 = ADD32(ctx->r8, 0XA);
    // 0x80800264: sltu        $at, $t0, $v1
    ctx->r1 = ctx->r8 < ctx->r3 ? 1 : 0;
    // 0x80800268: bnel        $at, $zero, L_80800090
    if (ctx->r1 != 0) {
        // 0x8080026C: lbu         $t7, 0x0($t0)
        ctx->r15 = MEM_BU(ctx->r8, 0X0);
            goto L_80800090;
    }
    goto skip_3;
    // 0x8080026C: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    skip_3:
    // 0x80800270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800274:
    // 0x80800274: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800278: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080027C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800280: jr          $ra
    // 0x80800284: nop

    return;
    // 0x80800284: nop

;}
RECOMP_FUNC void func_8080000C_chkingjinjobits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: jr          $ra
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800010: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _ncfixposrot_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089220: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x80089220);
    return;
    // 0x80089224: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void bakey_getStick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800919D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800919D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800919D8: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x800919DC: jal         0x800BCF90
    // 0x800919E0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800BCF90(rdram, ctx);
        goto after_0;
    // 0x800919E0: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x800919E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800919E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800919EC: jr          $ra
    // 0x800919F0: nop

    return;
    // 0x800919F0: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C20: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087C20);
    return;
    // 0x80087C24: addi        $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
;}
RECOMP_FUNC void func_80804A48_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804A48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804A4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804A50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804A54: jal         0x80800040
    // 0x80804A58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80800040_chcollballcontrol(rdram, ctx);
        goto after_0;
    // 0x80804A58: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80804A5C: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80804A60: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80804A64: nop

    // 0x80804A68: bc1f        L_80804A88
    if (!c1cs) {
        // 0x80804A6C: nop
    
            goto L_80804A88;
    }
    // 0x80804A6C: nop

    // 0x80804A70: jal         0x808000C8
    // 0x80804A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C8_chcollballcontrol(rdram, ctx);
        goto after_1;
    // 0x80804A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80804A78: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80804A7C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80804A80: b           L_80804A94
    // 0x80804A84: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
        goto L_80804A94;
    // 0x80804A84: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_80804A88:
    // 0x80804A88: jal         0x80800040
    // 0x80804A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800040_chcollballcontrol(rdram, ctx);
        goto after_2;
    // 0x80804A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80804A90: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_80804A94:
    // 0x80804A94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804A98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804A9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80804AA0: jr          $ra
    // 0x80804AA4: nop

    return;
    // 0x80804AA4: nop

;}
RECOMP_FUNC void func_80110068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8011006C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80110070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80110074: jal         0x8001BAFC
    // 0x80110078: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    defrag(rdram, ctx);
        goto after_0;
    // 0x80110078: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8011007C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80110080: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80110084: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80110088: beq         $t7, $zero, L_801100A0
    if (ctx->r15 == 0) {
        // 0x8011008C: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_801100A0;
    }
    // 0x8011008C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80110090: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80110094: jal         0x80110FCC
    // 0x80110098: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80110FCC(rdram, ctx);
        goto after_1;
    // 0x80110098: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8011009C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_801100A0:
    // 0x801100A0: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x801100A4: beql        $a0, $zero, L_801100BC
    if (ctx->r4 == 0) {
        // 0x801100A8: lw          $a0, 0x10($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X10);
            goto L_801100BC;
    }
    goto skip_0;
    // 0x801100A8: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x801100AC: jal         0x80115324
    // 0x801100B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80115324(rdram, ctx);
        goto after_2;
    // 0x801100B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x801100B4: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x801100B8: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
L_801100BC:
    // 0x801100BC: beql        $a0, $zero, L_801100D4
    if (ctx->r4 == 0) {
        // 0x801100C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801100D4;
    }
    goto skip_1;
    // 0x801100C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801100C4: jal         0x80114CD4
    // 0x801100C8: nop

    func_80114CD4(rdram, ctx);
        goto after_3;
    // 0x801100C8: nop

    after_3:
    // 0x801100CC: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x801100D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801100D4:
    // 0x801100D4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x801100D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801100DC: jr          $ra
    // 0x801100E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801100E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bsbanshack_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800914: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800918: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(45, 0XCD0) << 16);
    // 0x8080091C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800920: jr          $ra
    // 0x80800924: lw          $v0, 0xCD0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XCD0));
    return;
    // 0x80800924: lw          $v0, 0xCD0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(45, 0XCD0));
;}
RECOMP_FUNC void func_808010A0_chquicksandbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010A8: jal         0x800EA05C
    // 0x808010AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808010AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808010B0: addiu       $at, $zero, 0xB9
    ctx->r1 = ADD32(0, 0XB9);
    // 0x808010B4: beq         $v0, $at, L_808010F8
    if (ctx->r2 == ctx->r1) {
        // 0x808010B8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808010F8;
    }
    // 0x808010B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808010BC: addiu       $at, $zero, 0xC4
    ctx->r1 = ADD32(0, 0XC4);
    // 0x808010C0: beq         $v0, $at, L_808010F8
    if (ctx->r2 == ctx->r1) {
        // 0x808010C4: addiu       $at, $zero, 0x100
        ctx->r1 = ADD32(0, 0X100);
            goto L_808010F8;
    }
    // 0x808010C4: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x808010C8: beq         $v0, $at, L_80801118
    if (ctx->r2 == ctx->r1) {
        // 0x808010CC: addiu       $v1, $zero, 0xB4
        ctx->r3 = ADD32(0, 0XB4);
            goto L_80801118;
    }
    // 0x808010CC: addiu       $v1, $zero, 0xB4
    ctx->r3 = ADD32(0, 0XB4);
    // 0x808010D0: addiu       $at, $zero, 0x106
    ctx->r1 = ADD32(0, 0X106);
    // 0x808010D4: beq         $v0, $at, L_8080112C
    if (ctx->r2 == ctx->r1) {
        // 0x808010D8: addiu       $t8, $zero, 0xA0
        ctx->r24 = ADD32(0, 0XA0);
            goto L_8080112C;
    }
    // 0x808010D8: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x808010DC: addiu       $at, $zero, 0x10F
    ctx->r1 = ADD32(0, 0X10F);
    // 0x808010E0: beq         $v0, $at, L_80801118
    if (ctx->r2 == ctx->r1) {
        // 0x808010E4: addiu       $at, $zero, 0x15C
        ctx->r1 = ADD32(0, 0X15C);
            goto L_80801118;
    }
    // 0x808010E4: addiu       $at, $zero, 0x15C
    ctx->r1 = ADD32(0, 0X15C);
    // 0x808010E8: beql        $v0, $at, L_8080111C
    if (ctx->r2 == ctx->r1) {
        // 0x808010EC: sb          $v1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r3;
            goto L_8080111C;
    }
    goto skip_0;
    // 0x808010EC: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    skip_0:
    // 0x808010F0: b           L_80801144
    // 0x808010F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801144;
    // 0x808010F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808010F8:
    // 0x808010F8: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x808010FC: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x80801100: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x80801104: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80801108: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x8080110C: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
    // 0x80801110: b           L_80801144
    // 0x80801114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801144;
    // 0x80801114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801118:
    // 0x80801118: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_8080111C:
    // 0x8080111C: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
    // 0x80801120: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
    // 0x80801124: b           L_80801144
    // 0x80801128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801144;
    // 0x80801128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080112C:
    // 0x8080112C: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x80801130: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x80801134: sb          $t8, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r24;
    // 0x80801138: sb          $v1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r3;
    // 0x8080113C: b           L_80801144
    // 0x80801140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801144;
    // 0x80801140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801144:
    // 0x80801144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080114C: jr          $ra
    // 0x80801150: nop

    return;
    // 0x80801150: nop

;}
RECOMP_FUNC void _chshockjump_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085790: syscall     174
    recomp_syscall_handler(rdram, ctx, 0x80085790);
    return;
    // 0x80085794: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _anseq_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082638: syscall     3
    recomp_syscall_handler(rdram, ctx, 0x80082638);
    return;
    // 0x8008263C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080002C_chfactoryworkerdirty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080002C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800034: jal         0x80100094
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080003C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800040: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800044: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80800048: jal         0x8010114C
    // 0x8080004C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_1;
    // 0x8080004C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800050: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800054: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80800058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080005C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_808001F0_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808001F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001F8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x808001FC: jal         0x80100094
    // 0x80800200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800204: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80800208: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8080020C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800210: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800214: jal         0x800EE7F8
    // 0x80800218: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800218: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080021C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80800220: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(740, 0X1910) << 16);
    // 0x80800224: addiu       $t7, $t7, 0x1910
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(740, 0X1910));
    // 0x80800228: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x8080022C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800230: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800234: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800238: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080023C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800240: jal         0x800BBCB8
    // 0x80800244: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x80800244: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800248: jal         0x800B5BE4
    // 0x8080024C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B5BE4(rdram, ctx);
        goto after_3;
    // 0x8080024C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800250: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800254: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080025C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800260: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800264: nop

    // 0x80800268: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x8080026C: jal         0x800BA4D0
    // 0x80800270: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    func_800BA4D0(rdram, ctx);
        goto after_4;
    // 0x80800270: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    after_4:
    // 0x80800274: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x80800278: addiu       $a1, $a1, -0x7528
    ctx->r5 = ADD32(ctx->r5, -0X7528);
    // 0x8080027C: jal         0x800BA544
    // 0x80800280: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800BA544(rdram, ctx);
        goto after_5;
    // 0x80800280: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800284: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800288: jal         0x800EE7F8
    // 0x8080028C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x8080028C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_6:
    // 0x80800290: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800294: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800298: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080029C: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(740, 0X1934) << 16);
    // 0x808002A0: addiu       $t1, $t1, 0x1934
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(740, 0X1934));
    // 0x808002A4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x808002A8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808002AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808002B0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x808002B4: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x808002B8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808002BC: jal         0x800BABB8
    // 0x808002C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x808002C0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x808002C4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(740, 0X1908) << 16);
    // 0x808002C8: addiu       $a2, $a2, 0x1908
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(740, 0X1908));
    // 0x808002CC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x808002D0: jal         0x80089D18
    // 0x808002D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x808002D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_8:
    // 0x808002D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808002E0: jr          $ra
    // 0x808002E4: nop

    return;
    // 0x808002E4: nop

;}
RECOMP_FUNC void func_80803390_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803390: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80803394: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80803398: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8080339C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808033A0: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x808033A4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x808033A8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x808033AC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808033B0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808033B4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808033B8: lw          $a0, 0x70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X70);
    // 0x808033BC: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x808033C0: srl         $t6, $a0, 25
    ctx->r14 = S32(U32(ctx->r4) >> 25);
    // 0x808033C4: jal         0x800CC5F4
    // 0x808033C8: addiu       $a0, $t6, -0x1
    ctx->r4 = ADD32(ctx->r14, -0X1);
    func_800CC5F4(rdram, ctx);
        goto after_0;
    // 0x808033C8: addiu       $a0, $t6, -0x1
    ctx->r4 = ADD32(ctx->r14, -0X1);
    after_0:
    // 0x808033CC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x808033D0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808033D4: blez        $v0, L_80803438
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808033D8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80803438;
    }
    // 0x808033D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808033DC: lw          $a0, 0x70($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X70);
L_808033E0:
    // 0x808033E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808033E4: srl         $t7, $a0, 25
    ctx->r15 = S32(U32(ctx->r4) >> 25);
    // 0x808033E8: jal         0x800CC63C
    // 0x808033EC: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_1;
    // 0x808033EC: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    after_1:
    // 0x808033F0: beq         $s2, $zero, L_80803424
    if (ctx->r18 == 0) {
        // 0x808033F4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80803424;
    }
    // 0x808033F4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808033F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808033FC: jal         0x800EEB40
    // 0x80803400: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_2;
    // 0x80803400: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x80803404: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80803408: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080340C: jal         0x800EEB40
    // 0x80803410: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_3;
    // 0x80803410: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x80803414: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80803418: nop

    // 0x8080341C: bc1fl       L_8080342C
    if (!c1cs) {
        // 0x80803420: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8080342C;
    }
    goto skip_0;
    // 0x80803420: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
L_80803424:
    // 0x80803424: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x80803428: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8080342C:
    // 0x8080342C: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80803430: bnel        $at, $zero, L_808033E0
    if (ctx->r1 != 0) {
        // 0x80803434: lw          $a0, 0x70($s4)
        ctx->r4 = MEM_W(ctx->r20, 0X70);
            goto L_808033E0;
    }
    goto skip_1;
    // 0x80803434: lw          $a0, 0x70($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X70);
    skip_1:
L_80803438:
    // 0x80803438: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080343C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80803440: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80803444: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80803448: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8080344C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80803450: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80803454: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80803458: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8080345C: jr          $ra
    // 0x80803460: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80803460: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_808000F0_chklungoleave(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000F8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1256, 0X178) << 16);
    // 0x808000FC: jal         0x80105230
    // 0x80800100: addiu       $a1, $a1, 0x178
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1256, 0X178));
    func_80105230(rdram, ctx);
        goto after_0;
    // 0x80800100: addiu       $a1, $a1, 0x178
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1256, 0X178));
    after_0:
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

    // 0x80800114: nop

    // 0x80800118: nop

    // 0x8080011C: nop

;}
RECOMP_FUNC void func_80021818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021818: jr          $ra
    // 0x8002181C: nop

    return;
    // 0x8002181C: nop

;}
RECOMP_FUNC void gcnewpause_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808007DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007E0: sltiu       $at, $a3, 0x6
    ctx->r1 = ctx->r7 < 0X6 ? 1 : 0;
    // 0x808007E4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808007E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808007F0: beq         $at, $zero, L_808009F4
    if (ctx->r1 == 0) {
        // 0x808007F4: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_808009F4;
    }
    // 0x808007F4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808007F8: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x808007FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2658, 0X1FA8) << 16);
    // 0x80800800: addu        $at, $at, $t6
    gpr jr_addend_80800808 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800804: lw          $t6, 0x1FA8($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2658, 0X1FA8));
    // 0x80800808: jr          $t6
    // 0x8080080C: nop

    switch (jr_addend_80800808 >> 2) {
        case 0: goto L_80800810; break;
        case 1: goto L_808009F4; break;
        case 2: goto L_808009EC; break;
        case 3: goto L_80800824; break;
        case 4: goto L_8080083C; break;
        case 5: goto L_80800948; break;
        default: switch_error(__func__, 0x80800808, 0x80801FA8);
    }
    // 0x8080080C: nop

L_80800810:
    // 0x80800810: addiu       $a0, $s0, -0x30
    ctx->r4 = ADD32(ctx->r16, -0X30);
    // 0x80800814: jal         0x80800C54
    // 0x80800818: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80800C54_gcnewpause(rdram, ctx);
        goto after_0;
    // 0x80800818: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8080081C: b           L_808009F8
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009F8;
    // 0x80800820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800824:
    // 0x80800824: addiu       $a0, $s0, -0x30
    ctx->r4 = ADD32(ctx->r16, -0X30);
    // 0x80800828: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080082C: jal         0x80800CE4
    // 0x80800830: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    func_80800CE4_gcnewpause(rdram, ctx);
        goto after_1;
    // 0x80800830: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80800834: b           L_808009F8
    // 0x80800838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009F8;
    // 0x80800838: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080083C:
    // 0x8080083C: addiu       $a3, $s0, -0x30
    ctx->r7 = ADD32(ctx->r16, -0X30);
    // 0x80800840: lb          $t8, 0xD($a3)
    ctx->r24 = MEM_B(ctx->r7, 0XD);
    // 0x80800844: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80800848: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2658, 0X2074) << 16);
    // 0x8080084C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80800850: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80800854: lw          $t0, 0x2074($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(2658, 0X2074));
    // 0x80800858: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8080085C: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x80800860: sll         $v1, $t7, 1
    ctx->r3 = S32(ctx->r15 << 1);
    // 0x80800864: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x80800868: lbu         $t2, 0x5($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X5);
    // 0x8080086C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800870: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800874: beq         $t2, $zero, L_80800888
    if (ctx->r10 == 0) {
        // 0x80800878: nop
    
            goto L_80800888;
    }
    // 0x80800878: nop

    // 0x8080087C: lbu         $t3, 0xE($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0XE);
    // 0x80800880: beql        $t3, $zero, L_808008C8
    if (ctx->r11 == 0) {
        // 0x80800884: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008C8;
    }
    goto skip_0;
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80800888:
    // 0x80800888: jal         0x80087DC0
    // 0x8080088C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_2;
    // 0x8080088C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_2:
    // 0x80800890: beq         $v0, $zero, L_808009F4
    if (ctx->r2 == 0) {
        // 0x80800894: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_808009F4;
    }
    // 0x80800894: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800898: lbu         $t4, 0x11($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X11);
    // 0x8080089C: lbu         $t5, 0xE($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0XE);
    // 0x808008A0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x808008A4: bnel        $t4, $t5, L_808008BC
    if (ctx->r12 != ctx->r13) {
        // 0x808008A8: sb          $zero, 0x3($a3)
        MEM_B(0X3, ctx->r7) = 0;
            goto L_808008BC;
    }
    goto skip_1;
    // 0x808008A8: sb          $zero, 0x3($a3)
    MEM_B(0X3, ctx->r7) = 0;
    skip_1:
    // 0x808008AC: jal         0x800880D0
    // 0x808008B0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808008B0: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_3:
    // 0x808008B4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808008B8: sb          $zero, 0x3($a3)
    MEM_B(0X3, ctx->r7) = 0;
L_808008BC:
    // 0x808008BC: b           L_808009F4
    // 0x808008C0: sb          $zero, 0xE($a3)
    MEM_B(0XE, ctx->r7) = 0;
        goto L_808009F4;
    // 0x808008C0: sb          $zero, 0xE($a3)
    MEM_B(0XE, ctx->r7) = 0;
    // 0x808008C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008C8:
    // 0x808008C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008CC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x808008D0: jal         0x80087DC8
    // 0x808008D4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    _gcnewoption_entrypoint_38(rdram, ctx);
        goto after_4;
    // 0x808008D4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_4:
    // 0x808008D8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808008DC: beq         $v0, $zero, L_808009F4
    if (ctx->r2 == 0) {
        // 0x808008E0: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_808009F4;
    }
    // 0x808008E0: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808008E4: lb          $t6, 0xD($a3)
    ctx->r14 = MEM_B(ctx->r7, 0XD);
    // 0x808008E8: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2658, 0X2074) << 16);
    // 0x808008EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008F0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808008F4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x808008F8: lw          $t8, 0x2074($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(2658, 0X2074));
    // 0x808008FC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80800900: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80800904: lbu         $t0, 0x3($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X3);
    // 0x80800908: bnel        $t0, $at, L_80800928
    if (ctx->r8 != ctx->r1) {
        // 0x8080090C: lw          $t1, 0x38($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X38);
            goto L_80800928;
    }
    goto skip_2;
    // 0x8080090C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    skip_2:
    // 0x80800910: jal         0x800FC6B0
    // 0x80800914: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800FC6B0(rdram, ctx);
        goto after_5;
    // 0x80800914: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_5:
    // 0x80800918: jal         0x800D389C
    // 0x8080091C: nop

    func_800D389C(rdram, ctx);
        goto after_6;
    // 0x8080091C: nop

    after_6:
    // 0x80800920: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800924: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
L_80800928:
    // 0x80800928: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8080092C: sb          $t2, 0xE($a3)
    MEM_B(0XE, ctx->r7) = ctx->r10;
    // 0x80800930: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800934: addiu       $a1, $a3, 0x30
    ctx->r5 = ADD32(ctx->r7, 0X30);
    // 0x80800938: jal         0x80801E08
    // 0x8080093C: sb          $t1, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r9;
    func_80801E08_gcnewpause(rdram, ctx);
        goto after_7;
    // 0x8080093C: sb          $t1, 0x5($a3)
    MEM_B(0X5, ctx->r7) = ctx->r9;
    after_7:
    // 0x80800940: b           L_808009F8
    // 0x80800944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009F8;
    // 0x80800944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800948:
    // 0x80800948: addiu       $a3, $s0, -0x30
    ctx->r7 = ADD32(ctx->r16, -0X30);
    // 0x8080094C: lbu         $t3, 0xE($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0XE);
    // 0x80800950: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800958: bne         $t3, $zero, L_8080097C
    if (ctx->r11 != 0) {
        // 0x8080095C: nop
    
            goto L_8080097C;
    }
    // 0x8080095C: nop

    // 0x80800960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800964: jal         0x80087DC0
    // 0x80800968: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    _gcnewoption_entrypoint_37(rdram, ctx);
        goto after_8;
    // 0x80800968: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_8:
    // 0x8080096C: beq         $v0, $zero, L_808009F4
    if (ctx->r2 == 0) {
        // 0x80800970: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_808009F4;
    }
    // 0x80800970: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800974: b           L_808009F4
    // 0x80800978: sb          $zero, 0x3($a3)
    MEM_B(0X3, ctx->r7) = 0;
        goto L_808009F4;
    // 0x80800978: sb          $zero, 0x3($a3)
    MEM_B(0X3, ctx->r7) = 0;
L_8080097C:
    // 0x8080097C: jal         0x80087DD0
    // 0x80800980: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    _gcnewoption_entrypoint_39(rdram, ctx);
        goto after_9;
    // 0x80800980: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_9:
    // 0x80800984: beq         $v0, $zero, L_808009F4
    if (ctx->r2 == 0) {
        // 0x80800988: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_808009F4;
    }
    // 0x80800988: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8080098C: lbu         $t4, 0x11($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X11);
    // 0x80800990: lbu         $t5, 0xE($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0XE);
    // 0x80800994: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80800998: bnel        $t4, $t5, L_808009B0
    if (ctx->r12 != ctx->r13) {
        // 0x8080099C: lb          $t6, 0xD($a3)
        ctx->r14 = MEM_B(ctx->r7, 0XD);
            goto L_808009B0;
    }
    goto skip_3;
    // 0x8080099C: lb          $t6, 0xD($a3)
    ctx->r14 = MEM_B(ctx->r7, 0XD);
    skip_3:
    // 0x808009A0: jal         0x800880D0
    // 0x808009A4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x808009A4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_10:
    // 0x808009A8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x808009AC: lb          $t6, 0xD($a3)
    ctx->r14 = MEM_B(ctx->r7, 0XD);
L_808009B0:
    // 0x808009B0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x808009B4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2658, 0X2074) << 16);
    // 0x808009B8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x808009BC: sb          $zero, 0xE($a3)
    MEM_B(0XE, ctx->r7) = 0;
    // 0x808009C0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x808009C4: lw          $t8, 0x2074($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(2658, 0X2074));
    // 0x808009C8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x808009CC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x808009D0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x808009D4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x808009D8: lbu         $a2, 0x2($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X2);
    // 0x808009DC: jal         0x80087CF8
    // 0x808009E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x808009E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808009E4: b           L_808009F8
    // 0x808009E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808009F8;
    // 0x808009E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009EC:
    // 0x808009EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808009F0: sb          $t1, -0x2E($s0)
    MEM_B(-0X2E, ctx->r16) = ctx->r9;
L_808009F4:
    // 0x808009F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808009F8:
    // 0x808009F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800A00: jr          $ra
    // 0x80800A04: nop

    return;
    // 0x80800A04: nop

;}
RECOMP_FUNC void _idwibble_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E98: syscall     745
    recomp_syscall_handler(rdram, ctx, 0x80088E98);
    return;
    // 0x80088E9C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_808001EC_chdiggerbossshell(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808001F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001FC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800200: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800204: jal         0x800EE7F8
    // 0x80800208: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800208: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8080020C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800210: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800214: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800218: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080021C: jal         0x80088B00
    // 0x80800220: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    _fxgenlist_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800220: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80800224: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800228: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8080022C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800230: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800234: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800238: jal         0x800BBCB8
    // 0x8080023C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x8080023C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800240: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1492, 0X5F0) << 16);
    // 0x80800244: addiu       $a2, $a2, 0x5F0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1492, 0X5F0));
    // 0x80800248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080024C: jal         0x80089D18
    // 0x80800250: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800250: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80800254: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80800258: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8080025C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800260: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80800264: jal         0x800E1610
    // 0x80800268: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_800E1610(rdram, ctx);
        goto after_4;
    // 0x80800268: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x8080026C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800270: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80800274: jal         0x80018820
    // 0x80800278: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    func_80018820(rdram, ctx);
        goto after_5;
    // 0x80800278: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    after_5:
    // 0x8080027C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800280: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800284: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800288: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080028C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80800290: jal         0x808002CC
    // 0x80800294: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    func_808002CC_chdiggerbossshell(rdram, ctx);
        goto after_6;
    // 0x80800294: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x80800298: jal         0x8010A570
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_7;
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: jal         0x80101FDC
    // 0x808002A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x808002A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: jal         0x80108B04
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_9;
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808002B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808002C4: jr          $ra
    // 0x808002C8: nop

    return;
    // 0x808002C8: nop

;}
RECOMP_FUNC void func_800D5688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D568C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D5690: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D5694: jal         0x800B2F58
    // 0x800D5698: lw          $a0, -0x4810($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4810);
    vector_defrag(rdram, ctx);
        goto after_0;
    // 0x800D5698: lw          $a0, -0x4810($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4810);
    after_0:
    // 0x800D569C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D56A0: addiu       $v1, $v1, -0x4810
    ctx->r3 = ADD32(ctx->r3, -0X4810);
    // 0x800D56A4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800D56A8: jal         0x800B2F58
    // 0x800D56AC: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    vector_defrag(rdram, ctx);
        goto after_1;
    // 0x800D56AC: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    after_1:
    // 0x800D56B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D56B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D56B8: sw          $v0, -0x480C($at)
    MEM_W(-0X480C, ctx->r1) = ctx->r2;
    // 0x800D56BC: jr          $ra
    // 0x800D56C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D56C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8009BC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BC34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009BC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BC3C: jal         0x8009BC6C
    // 0x8009BC40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x8009BC40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009BC44: jal         0x8009BC90
    // 0x8009BC48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baphysics_reset_terminal_velocity(rdram, ctx);
        goto after_1;
    // 0x8009BC48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8009BC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BC50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009BC54: jr          $ra
    // 0x8009BC58: nop

    return;
    // 0x8009BC58: nop

;}
RECOMP_FUNC void func_808004B4_chbottlesfamily(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808004C0: jal         0x800DA298
    // 0x808004C4: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808004C4: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_0:
    // 0x808004C8: beq         $v0, $zero, L_808004D8
    if (ctx->r2 == 0) {
        // 0x808004CC: nop
    
            goto L_808004D8;
    }
    // 0x808004CC: nop

    // 0x808004D0: b           L_80800510
    // 0x808004D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800510;
    // 0x808004D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808004D8:
    // 0x808004D8: jal         0x800DA298
    // 0x808004DC: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808004DC: addiu       $a0, $zero, 0x1A5
    ctx->r4 = ADD32(0, 0X1A5);
    after_1:
    // 0x808004E0: beq         $v0, $zero, L_808004F8
    if (ctx->r2 == 0) {
        // 0x808004E4: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(1300, 0XF04) << 16);
            goto L_808004F8;
    }
    // 0x808004E4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1300, 0XF04) << 16);
    // 0x808004E8: addiu       $t6, $zero, 0x1539
    ctx->r14 = ADD32(0, 0X1539);
    // 0x808004EC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1300, 0XF08) << 16);
    // 0x808004F0: b           L_80800504
    // 0x808004F4: sh          $t6, 0xF08($at)
    MEM_H((int16_t)RELOC_LO16(1300, 0XF08), ctx->r1) = ctx->r14;
        goto L_80800504;
    // 0x808004F4: sh          $t6, 0xF08($at)
    MEM_H((int16_t)RELOC_LO16(1300, 0XF08), ctx->r1) = ctx->r14;
L_808004F8:
    // 0x808004F8: addiu       $t7, $zero, 0x1501
    ctx->r15 = ADD32(0, 0X1501);
    // 0x808004FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1300, 0XF08) << 16);
    // 0x80800500: sh          $t7, 0xF08($at)
    MEM_H((int16_t)RELOC_LO16(1300, 0XF08), ctx->r1) = ctx->r15;
L_80800504:
    // 0x80800504: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800508: jal         0x808009F0
    // 0x8080050C: addiu       $a1, $a1, 0xF04
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1300, 0XF04));
    func_808009F0_chbottlesfamily(rdram, ctx);
        goto after_2;
    // 0x8080050C: addiu       $a1, $a1, 0xF04
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1300, 0XF04));
    after_2:
L_80800510:
    // 0x80800510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800514: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800518: jr          $ra
    // 0x8080051C: nop

    return;
    // 0x8080051C: nop

;}
RECOMP_FUNC void func_80800074_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080007C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800080: jal         0x80100094
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800088: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8080008C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80800090: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800094: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x80800098: and         $t0, $t6, $t9
    ctx->r8 = ctx->r14 & ctx->r25;
    // 0x8080009C: beq         $t0, $zero, L_808000AC
    if (ctx->r8 == 0) {
        // 0x808000A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000AC;
    }
    // 0x808000A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000A4: b           L_808000B0
    // 0x808000A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_808000B0;
    // 0x808000A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808000AC:
    // 0x808000AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_808000B0:
    // 0x808000B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x808000B4: jr          $ra
    // 0x808000B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808000B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _chfloater_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085E78: syscall     252
    recomp_syscall_handler(rdram, ctx, 0x80085E78);
    return;
    // 0x80085E7C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800A4168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4168: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A416C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4170: lw          $t6, 0x38($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X38);
    // 0x800A4174: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A4178: jal         0x800A4074
    // 0x800A417C: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    func_800A4074(rdram, ctx);
        goto after_0;
    // 0x800A417C: sw          $zero, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = 0;
    after_0:
    // 0x800A4180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A4188: jr          $ra
    // 0x800A418C: nop

    return;
    // 0x800A418C: nop

;}
RECOMP_FUNC void func_800D52CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D52CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D52D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D52D4: jal         0x800D52B0
    // 0x800D52D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D52B0(rdram, ctx);
        goto after_0;
    // 0x800D52D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D52DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D52E0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800D52E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D52E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D52EC: jr          $ra
    // 0x800D52F0: sh          $t6, -0x4BCE($at)
    MEM_H(-0X4BCE, ctx->r1) = ctx->r14;
    return;
    // 0x800D52F0: sh          $t6, -0x4BCE($at)
    MEM_H(-0X4BCE, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void idworld_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800104: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800108: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080010C: jal         0x80800000
    // 0x80800110: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800000_idworld(rdram, ctx);
        goto after_0;
    // 0x80800110: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80800114: beq         $v0, $zero, L_80800124
    if (ctx->r2 == 0) {
        // 0x80800118: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800124;
    }
    // 0x80800118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080011C: b           L_80800128
    // 0x80800120: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
        goto L_80800128;
    // 0x80800120: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
L_80800124:
    // 0x80800124: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80800128:
    // 0x80800128: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8080012C: jr          $ra
    // 0x80800130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800FB6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB6C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FB6C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FB6C8: jal         0x800FB650
    // 0x800FB6CC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_800FB650(rdram, ctx);
        goto after_0;
    // 0x800FB6CC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x800FB6D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FB6D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FB6D8: jr          $ra
    // 0x800FB6DC: nop

    return;
    // 0x800FB6DC: nop

;}
RECOMP_FUNC void bstrexlarge_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800B38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800B3C: jal         0x8009C128
    // 0x80800B40: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800B40: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80800B44: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80800B48: jal         0x800EFC7C
    // 0x80800B4C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EFC7C(rdram, ctx);
        goto after_1;
    // 0x80800B4C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800B50: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(412, 0X197C) << 16);
    // 0x80800B54: lwc1        $f4, 0x197C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(412, 0X197C));
    // 0x80800B58: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(412, 0X1980) << 16);
    // 0x80800B5C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800B60: nop

    // 0x80800B64: bc1f        L_80800B74
    if (!c1cs) {
        // 0x80800B68: nop
    
            goto L_80800B74;
    }
    // 0x80800B68: nop

    // 0x80800B6C: b           L_80800BB4
    // 0x80800B70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800BB4;
    // 0x80800B70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B74:
    // 0x80800B74: lwc1        $f6, 0x1980($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(412, 0X1980));
    // 0x80800B78: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B7C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B80: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800B84: nop

    // 0x80800B88: bc1f        L_80800B98
    if (!c1cs) {
        // 0x80800B8C: nop
    
            goto L_80800B98;
    }
    // 0x80800B8C: nop

    // 0x80800B90: b           L_80800BB4
    // 0x80800B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BB4;
    // 0x80800B94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B98:
    // 0x80800B98: jal         0x8008DAE8
    // 0x80800B9C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    func_8008DAE8(rdram, ctx);
        goto after_2;
    // 0x80800B9C: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_2:
    // 0x80800BA0: bnel        $v0, $zero, L_80800BB4
    if (ctx->r2 != 0) {
        // 0x80800BA4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800BB4;
    }
    goto skip_0;
    // 0x80800BA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800BA8: b           L_80800BB4
    // 0x80800BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800BB4;
    // 0x80800BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800BB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800BB4:
    // 0x80800BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800BBC: jr          $ra
    // 0x80800BC0: nop

    return;
    // 0x80800BC0: nop

;}
RECOMP_FUNC void func_8002ABE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ABE0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002ABE4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8002ABE8: sw          $t6, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r14;
    // 0x8002ABEC: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x8002ABF0: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x8002ABF4: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8002ABF8: bne         $t8, $zero, L_8002AC08
    if (ctx->r24 != 0) {
        // 0x8002ABFC: nop
    
            goto L_8002AC08;
    }
    // 0x8002ABFC: nop

    // 0x8002AC00: b           L_8002ACD0
    // 0x8002AC04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8002ACD0;
    // 0x8002AC04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002AC08:
    // 0x8002AC08: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
    // 0x8002AC0C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8002AC10: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8002AC14: beq         $t0, $zero, L_8002ACB4
    if (ctx->r8 == 0) {
        // 0x8002AC18: nop
    
            goto L_8002ACB4;
    }
    // 0x8002AC18: nop

L_8002AC1C:
    // 0x8002AC1C: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x8002AC20: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8002AC24: srlv        $t3, $t1, $t2
    ctx->r11 = S32(U32(ctx->r9) >> (ctx->r10 & 31));
    // 0x8002AC28: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8002AC2C: beq         $t4, $zero, L_8002AC94
    if (ctx->r12 == 0) {
        // 0x8002AC30: nop
    
            goto L_8002AC94;
    }
    // 0x8002AC30: nop

    // 0x8002AC34: lw          $t5, 0x14($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14);
    // 0x8002AC38: beq         $t5, $zero, L_8002AC60
    if (ctx->r13 == 0) {
        // 0x8002AC3C: nop
    
            goto L_8002AC60;
    }
    // 0x8002AC3C: nop

    // 0x8002AC40: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8002AC44: lw          $t0, 0x4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4);
    // 0x8002AC48: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002AC4C: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8002AC50: lw          $t9, 0x158($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X158);
    // 0x8002AC54: addu        $t2, $a0, $t7
    ctx->r10 = ADD32(ctx->r4, ctx->r15);
    // 0x8002AC58: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x8002AC5C: sw          $t1, 0x158($t2)
    MEM_W(0X158, ctx->r10) = ctx->r9;
L_8002AC60:
    // 0x8002AC60: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8002AC64: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8002AC68: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8002AC6C: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8002AC70: lw          $t6, 0x158($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X158);
    // 0x8002AC74: sltu        $at, $t6, $t8
    ctx->r1 = ctx->r14 < ctx->r24 ? 1 : 0;
    // 0x8002AC78: beq         $at, $zero, L_8002AC94
    if (ctx->r1 == 0) {
        // 0x8002AC7C: nop
    
            goto L_8002AC94;
    }
    // 0x8002AC7C: nop

    // 0x8002AC80: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8002AC84: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8002AC88: addu        $t7, $a0, $t0
    ctx->r15 = ADD32(ctx->r4, ctx->r8);
    // 0x8002AC8C: lw          $t1, 0x158($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X158);
    // 0x8002AC90: sw          $t1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r9;
L_8002AC94:
    // 0x8002AC94: lw          $t2, 0xC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC);
    // 0x8002AC98: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8002AC9C: sw          $t3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r11;
    // 0x8002ACA0: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8002ACA4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x8002ACA8: sltu        $at, $t3, $t5
    ctx->r1 = ctx->r11 < ctx->r13 ? 1 : 0;
    // 0x8002ACAC: bne         $at, $zero, L_8002AC1C
    if (ctx->r1 != 0) {
        // 0x8002ACB0: nop
    
            goto L_8002AC1C;
    }
    // 0x8002ACB0: nop

L_8002ACB4:
    // 0x8002ACB4: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8002ACB8: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8002ACBC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8002ACC0: b           L_8002ACD0
    // 0x8002ACC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8002ACD0;
    // 0x8002ACC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002ACC8: b           L_8002ACD0
    // 0x8002ACCC: nop

        goto L_8002ACD0;
    // 0x8002ACCC: nop

L_8002ACD0:
    // 0x8002ACD0: jr          $ra
    // 0x8002ACD4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002ACD4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8002ACD8: nop

    // 0x8002ACDC: nop

;}
RECOMP_FUNC void chproplighter_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1316, 0X1A0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1316, 0X1A0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1A0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1316, 0X1A0));
;}
RECOMP_FUNC void bsfirstp_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808034A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808034A4: lui         $v0, 0x8081
    ctx->r2 = S32(RELOC_HI16(439, 0XB484) << 16);
    // 0x808034A8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808034AC: jr          $ra
    // 0x808034B0: lw          $v0, -0x4B7C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB484));
    return;
    // 0x808034B0: lw          $v0, -0x4B7C($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(439, 0XB484));
;}
RECOMP_FUNC void func_800F1660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1660: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F1664: nop

    // 0x800F1668: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800F166C: nop

    // 0x800F1670: bc1fl       L_800F1680
    if (!c1cs) {
        // 0x800F1674: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_800F1680;
    }
    goto skip_0;
    // 0x800F1674: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_0:
    // 0x800F1678: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800F167C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_800F1680:
    // 0x800F1680: nop

    // 0x800F1684: bc1fl       L_800F1694
    if (!c1cs) {
        // 0x800F1688: c.lt.s      $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
            goto L_800F1694;
    }
    goto skip_1;
    // 0x800F1688: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    skip_1:
    // 0x800F168C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x800F1690: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
L_800F1694:
    // 0x800F1694: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F1698: bc1f        L_800F16A4
    if (!c1cs) {
        // 0x800F169C: nop
    
            goto L_800F16A4;
    }
    // 0x800F169C: nop

    // 0x800F16A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F16A4:
    // 0x800F16A4: jr          $ra
    // 0x800F16A8: nop

    return;
    // 0x800F16A8: nop

;}
RECOMP_FUNC void func_800905F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800905F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800905FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090600: jal         0x800F54E4
    // 0x80090604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090604: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80090608: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009060C: jal         0x800F7E64
    // 0x80090610: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F7E64(rdram, ctx);
        goto after_1;
    // 0x80090610: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80090614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009061C: jr          $ra
    // 0x80090620: nop

    return;
    // 0x80090620: nop

;}
RECOMP_FUNC void _susubgame_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A2E0: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A2E0);
    return;
    // 0x8008A2E4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _bsstatue_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083BB0: syscall     91
    recomp_syscall_handler(rdram, ctx, 0x80083BB0);
    return;
    // 0x80083BB4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void bsbtrot_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DB0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800DB4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(124, 0X2E60) << 16);
    // 0x80800DB8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800DBC: jr          $ra
    // 0x80800DC0: lw          $v0, 0x2E60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2E60));
    return;
    // 0x80800DC0: lw          $v0, 0x2E60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(124, 0X2E60));
;}
RECOMP_FUNC void func_808014A4_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808014A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014AC: jal         0x8080064C
    // 0x808014B0: nop

    bstrexlarge_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808014B0: nop

    after_0:
    // 0x808014B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808014BC: jr          $ra
    // 0x808014C0: nop

    return;
    // 0x808014C0: nop

;}
RECOMP_FUNC void func_80016DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016DA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80016DA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016DA8: addiu       $a0, $a0, 0x1DDD
    ctx->r4 = ADD32(ctx->r4, 0X1DDD);
    // 0x80016DAC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80016DB0: jal         0x800D73CC
    // 0x80016DB4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800D73CC(rdram, ctx);
        goto after_0;
    // 0x80016DB4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80016DB8: bne         $v0, $zero, L_80016DE8
    if (ctx->r2 != 0) {
        // 0x80016DBC: lw          $t6, 0x24($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X24);
            goto L_80016DE8;
    }
    // 0x80016DBC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80016DC0: beq         $t6, $zero, L_80016DD0
    if (ctx->r14 == 0) {
        // 0x80016DC4: nop
    
            goto L_80016DD0;
    }
    // 0x80016DC4: nop

    // 0x80016DC8: jal         0x800D5B24
    // 0x80016DCC: nop

    func_800D5B24(rdram, ctx);
        goto after_1;
    // 0x80016DCC: nop

    after_1:
L_80016DD0:
    // 0x80016DD0: jal         0x800D674C
    // 0x80016DD4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x80016DD4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80016DD8: jal         0x800D70D0
    // 0x80016DDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D70D0(rdram, ctx);
        goto after_3;
    // 0x80016DDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80016DE0: jal         0x800D71F4
    // 0x80016DE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D71F4(rdram, ctx);
        goto after_4;
    // 0x80016DE4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
L_80016DE8:
    // 0x80016DE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016DEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80016DF0: jr          $ra
    // 0x80016DF4: nop

    return;
    // 0x80016DF4: nop

;}
RECOMP_FUNC void _ncpod_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089570: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089570);
    return;
    // 0x80089574: addi        $t0, $zero, 0x58
    ctx->r8 = ADD32(0, 0X58);
;}
RECOMP_FUNC void func_8080102C_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080102C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801030: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801034: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801038: jal         0x8008CABC
    // 0x8080103C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080103C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801040: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801044: jal         0x8008B264
    // 0x80801048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getIndex(rdram, ctx);
        goto after_1;
    // 0x80801048: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080104C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80801050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801054: jal         0x8008CA4C
    // 0x80801058: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008CA4C(rdram, ctx);
        goto after_2;
    // 0x80801058: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8080105C: jal         0x8009BB94
    // 0x80801060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB94(rdram, ctx);
        goto after_3;
    // 0x80801060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801064: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80801068: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080106C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80801070: addiu       $at, $zero, 0x12F
    ctx->r1 = ADD32(0, 0X12F);
    // 0x80801074: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801078: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8080107C: bc1f        L_808010D4
    if (!c1cs) {
        // 0x80801080: nop
    
            goto L_808010D4;
    }
    // 0x80801080: nop

    // 0x80801084: addiu       $at, $zero, 0x12E
    ctx->r1 = ADD32(0, 0X12E);
    // 0x80801088: beq         $t6, $at, L_808010AC
    if (ctx->r14 == ctx->r1) {
        // 0x8080108C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010AC;
    }
    // 0x8080108C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801090: addiu       $a1, $zero, 0x12E
    ctx->r5 = ADD32(0, 0X12E);
    // 0x80801094: jal         0x8008CB3C
    // 0x80801098: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_4;
    // 0x80801098: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    after_4:
    // 0x8080109C: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x808010A0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808010A4: jal         0x8008B1C8
    // 0x808010A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008B1C8(rdram, ctx);
        goto after_5;
    // 0x808010A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
L_808010AC:
    // 0x808010AC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808010B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808010B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808010BC: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    // 0x808010C0: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x808010C4: jal         0x8008C9F0
    // 0x808010C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_6;
    // 0x808010C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x808010CC: b           L_80801120
    // 0x808010D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801120;
    // 0x808010D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808010D4:
    // 0x808010D4: beq         $t7, $at, L_808010FC
    if (ctx->r15 == ctx->r1) {
        // 0x808010D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808010FC;
    }
    // 0x808010D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010DC: lui         $a2, 0x3EE6
    ctx->r6 = S32(0X3EE6 << 16);
    // 0x808010E0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808010E4: jal         0x8008CB3C
    // 0x808010E8: addiu       $a1, $zero, 0x12F
    ctx->r5 = ADD32(0, 0X12F);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_7;
    // 0x808010E8: addiu       $a1, $zero, 0x12F
    ctx->r5 = ADD32(0, 0X12F);
    after_7:
    // 0x808010EC: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x808010F0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808010F4: jal         0x8008B1C8
    // 0x808010F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_8008B1C8(rdram, ctx);
        goto after_8;
    // 0x808010F8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_8:
L_808010FC:
    // 0x808010FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(380, 0X16DC) << 16);
    // 0x80801100: lwc1        $f8, 0x16DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(380, 0X16DC));
    // 0x80801104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801108: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8080110C: lui         $a2, 0x4461
    ctx->r6 = S32(0X4461 << 16);
    // 0x80801110: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x80801114: jal         0x8008C9F0
    // 0x80801118: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_9;
    // 0x80801118: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x8080111C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801120:
    // 0x80801120: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801124: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801128: jr          $ra
    // 0x8080112C: nop

    return;
    // 0x8080112C: nop

;}
