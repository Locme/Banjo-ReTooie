#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801A80_chfactoryrobot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801A84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801A88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801A8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801A90: jal         0x80100094
    // 0x80801A94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801A94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801A98: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80801A9C: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80801AA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801AA4: nop

    // 0x80801AA8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80801AAC: nop

    // 0x80801AB0: bc1fl       L_80801AC4
    if (!c1cs) {
        // 0x80801AB4: lw          $t6, 0x64($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X64);
            goto L_80801AC4;
    }
    goto skip_0;
    // 0x80801AB4: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x80801AB8: b           L_80801B28
    // 0x80801ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801B28;
    // 0x80801ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801AC0: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
L_80801AC4:
    // 0x80801AC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801AC8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80801ACC: bgezl       $t8, L_80801AE8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80801AD0: lh          $t9, 0x18($v0)
        ctx->r25 = MEM_H(ctx->r2, 0X18);
            goto L_80801AE8;
    }
    goto skip_1;
    // 0x80801AD0: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
    skip_1:
    // 0x80801AD4: jal         0x80089BD8
    // 0x80801AD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiejoy_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80801AD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801ADC: b           L_80801B00
    // 0x80801AE0: nop

        goto L_80801B00;
    // 0x80801AE0: nop

    // 0x80801AE4: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
L_80801AE8:
    // 0x80801AE8: beq         $t9, $zero, L_80801AF8
    if (ctx->r25 == 0) {
        // 0x80801AEC: nop
    
            goto L_80801AF8;
    }
    // 0x80801AEC: nop

    // 0x80801AF0: b           L_80801B28
    // 0x80801AF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801B28;
    // 0x80801AF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801AF8:
    // 0x80801AF8: jal         0x800D9078
    // 0x80801AFC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80801AFC: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_2:
L_80801B00:
    // 0x80801B00: beq         $v0, $zero, L_80801B24
    if (ctx->r2 == 0) {
        // 0x80801B04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801B24;
    }
    // 0x80801B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801B08: jal         0x80801160
    // 0x80801B0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801160_chfactoryrobot(rdram, ctx);
        goto after_3;
    // 0x80801B0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80801B10: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801B14: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80801B18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801B1C: b           L_80801B28
    // 0x80801B20: swc1        $f8, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f8.u32l;
        goto L_80801B28;
    // 0x80801B20: swc1        $f8, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f8.u32l;
L_80801B24:
    // 0x80801B24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801B28:
    // 0x80801B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801B2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801B30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801B34: jr          $ra
    // 0x80801B38: nop

    return;
    // 0x80801B38: nop

;}
RECOMP_FUNC void func_80801688_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801688: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080168C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801690: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801694: jal         0x808005DC
    // 0x80801698: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstrexsmall_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801698: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080169C: jal         0x808002B8
    // 0x808016A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002B8_bstrexsmall(rdram, ctx);
        goto after_1;
    // 0x808016A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808016A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016A8: jal         0x8009D3A8
    // 0x808016AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_2;
    // 0x808016AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808016B0: lui         $a1, 0x3F11
    ctx->r5 = S32(0X3F11 << 16);
    // 0x808016B4: ori         $a1, $a1, 0xF8A1
    ctx->r5 = ctx->r5 | 0XF8A1;
    // 0x808016B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016BC: jal         0x800A2CE8
    // 0x808016C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_3;
    // 0x808016C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x808016C4: lui         $a1, 0x3D8F
    ctx->r5 = S32(0X3D8F << 16);
    // 0x808016C8: ori         $a1, $a1, 0xC505
    ctx->r5 = ctx->r5 | 0XC505;
    // 0x808016CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016D0: jal         0x800A2CE8
    // 0x808016D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_4;
    // 0x808016D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x808016D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016DC: jal         0x80800154
    // 0x808016E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800154_bstrexsmall(rdram, ctx);
        goto after_5;
    // 0x808016E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x808016E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016E8: jal         0x8009E5C8
    // 0x808016EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x808016EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x808016F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808016F4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808016F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808016FC: jr          $ra
    // 0x80801700: nop

    return;
    // 0x80801700: nop

;}
RECOMP_FUNC void func_800959C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800959C8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800959CC: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x800959D0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800959D4: swc1        $f12, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->f12.u32l;
    // 0x800959D8: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x800959DC: lwc1        $f4, 0x64($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64);
    // 0x800959E0: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x800959E4: lw          $t7, 0x94($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X94);
    // 0x800959E8: swc1        $f14, 0x68($t7)
    MEM_W(0X68, ctx->r15) = ctx->f14.u32l;
    // 0x800959EC: lw          $v0, 0x94($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X94);
    // 0x800959F0: lwc1        $f6, 0x68($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X68);
    // 0x800959F4: jr          $ra
    // 0x800959F8: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x800959F8: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void _subaddiefind_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089C58: syscall     807
    recomp_syscall_handler(rdram, ctx, 0x80089C58);
    return;
    // 0x80089C5C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_80107C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107C20: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80107C24: jr          $ra
    // 0x80107C28: addiu       $v0, $v0, 0x4580
    ctx->r2 = ADD32(ctx->r2, 0X4580);
    return;
    // 0x80107C28: addiu       $v0, $v0, 0x4580
    ctx->r2 = ADD32(ctx->r2, 0X4580);
;}
RECOMP_FUNC void _bsbtrot_entrypoint_31(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082CB8: syscall     29
    recomp_syscall_handler(rdram, ctx, 0x80082CB8);
    return;
    // 0x80082CBC: addi        $t0, $zero, 0x7C
    ctx->r8 = ADD32(0, 0X7C);
;}
RECOMP_FUNC void func_80801CE8_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CE8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80801CEC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80801CF0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80801CF4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80801CF8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80801CFC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80801D00: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80801D04: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80801D08: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80801D0C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80801D10: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80801D14: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80801D18: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80801D1C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801D20: jal         0x80100094
    // 0x80801D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801D24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801D28: lw          $t6, 0x20($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X20);
    // 0x80801D2C: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x80801D30: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80801D34: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80801D38: jal         0x8080363C
    // 0x80801D3C: lw          $a0, 0x3C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X3C);
    func_8080363C_chjiggygamenew(rdram, ctx);
        goto after_1;
    // 0x80801D3C: lw          $a0, 0x3C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X3C);
    after_1:
    // 0x80801D40: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39D8) << 16);
    // 0x80801D44: lwc1        $f22, 0x39D8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39D8));
    // 0x80801D48: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39DC) << 16);
    // 0x80801D4C: lui         $s5, 0x8080
    ctx->r21 = S32(RELOC_HI16(772, 0X3DBC) << 16);
    // 0x80801D50: lui         $s4, 0x8080
    ctx->r20 = S32(RELOC_HI16(772, 0X3DAC) << 16);
    // 0x80801D54: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x80801D58: addiu       $s4, $s4, 0x3DAC
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(772, 0X3DAC));
    // 0x80801D5C: addiu       $s5, $s5, 0x3DBC
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(772, 0X3DBC));
    // 0x80801D60: lwc1        $f20, 0x39DC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39DC));
    // 0x80801D64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801D68: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
    // 0x80801D6C: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
L_80801D70:
    // 0x80801D70: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80801D74: lb          $t9, 0x1($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X1);
    // 0x80801D78: lbu         $s2, 0x1E0($s0)
    ctx->r18 = MEM_BU(ctx->r16, 0X1E0);
    // 0x80801D7C: bnel        $t8, $t9, L_80801DAC
    if (ctx->r24 != ctx->r25) {
        // 0x80801D80: sb          $zero, 0x1E0($s0)
        MEM_B(0X1E0, ctx->r16) = 0;
            goto L_80801DAC;
    }
    goto skip_0;
    // 0x80801D80: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
    skip_0:
    // 0x80801D84: beq         $s7, $zero, L_80801DA8
    if (ctx->r23 == 0) {
        // 0x80801D88: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80801DA8;
    }
    // 0x80801D88: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80801D8C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80801D90: jal         0x80801CB0
    // 0x80801D94: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    func_80801CB0_chjiggygamenew(rdram, ctx);
        goto after_2;
    // 0x80801D94: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_2:
    // 0x80801D98: beq         $v0, $zero, L_80801DA8
    if (ctx->r2 == 0) {
        // 0x80801D9C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80801DA8;
    }
    // 0x80801D9C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80801DA0: b           L_80801DAC
    // 0x80801DA4: sb          $t0, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r8;
        goto L_80801DAC;
    // 0x80801DA4: sb          $t0, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = ctx->r8;
L_80801DA8:
    // 0x80801DA8: sb          $zero, 0x1E0($s0)
    MEM_B(0X1E0, ctx->r16) = 0;
L_80801DAC:
    // 0x80801DAC: lbu         $t1, 0x1E0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1E0);
    // 0x80801DB0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80801DB4: beql        $s2, $t1, L_80801E04
    if (ctx->r18 == ctx->r9) {
        // 0x80801DB8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80801E04;
    }
    goto skip_1;
    // 0x80801DB8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80801DBC: jal         0x8010649C
    // 0x80801DC0: addiu       $a1, $s1, 0x190
    ctx->r5 = ADD32(ctx->r17, 0X190);
    func_8010649C(rdram, ctx);
        goto after_3;
    // 0x80801DC0: addiu       $a1, $s1, 0x190
    ctx->r5 = ADD32(ctx->r17, 0X190);
    after_3:
    // 0x80801DC4: lbu         $v1, 0x1E0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1E0);
    // 0x80801DC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801DCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801DD0: beq         $v1, $zero, L_80801DF4
    if (ctx->r3 == 0) {
        // 0x80801DD4: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80801DF4;
    }
    // 0x80801DD4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80801DD8: bne         $v1, $at, L_80801E00
    if (ctx->r3 != ctx->r1) {
        // 0x80801DDC: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_80801E00;
    }
    // 0x80801DDC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80801DE0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801DE4: jal         0x800EDE54
    // 0x80801DE8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800EDE54(rdram, ctx);
        goto after_4;
    // 0x80801DE8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_4:
    // 0x80801DEC: b           L_80801E04
    // 0x80801DF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80801E04;
    // 0x80801DF0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80801DF4:
    // 0x80801DF4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80801DF8: jal         0x800EDE54
    // 0x80801DFC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800EDE54(rdram, ctx);
        goto after_5;
    // 0x80801DFC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_5:
L_80801E00:
    // 0x80801E00: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80801E04:
    // 0x80801E04: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80801E08: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80801E0C: bne         $s1, $at, L_80801D70
    if (ctx->r17 != ctx->r1) {
        // 0x80801E10: addiu       $s3, $s3, 0x18
        ctx->r19 = ADD32(ctx->r19, 0X18);
            goto L_80801D70;
    }
    // 0x80801E10: addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // 0x80801E14: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80801E18: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80801E1C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80801E20: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80801E24: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80801E28: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80801E2C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80801E30: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80801E34: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80801E38: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80801E3C: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80801E40: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80801E44: jr          $ra
    // 0x80801E48: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80801E48: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800B44_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B4C: jal         0x80085148
    // 0x80800B50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _baspin_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800B50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B58: jal         0x80800198
    // 0x80800B5C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    bssnowball_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800B5C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    after_1:
    // 0x80800B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B68: jr          $ra
    // 0x80800B6C: nop

    return;
    // 0x80800B6C: nop

;}
RECOMP_FUNC void func_800C7494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7494: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C7498: lbu         $t6, -0x5510($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X5510);
    // 0x800C749C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C74A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C74A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C74A8: beq         $t6, $zero, L_800C74EC
    if (ctx->r14 == 0) {
        // 0x800C74AC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800C74EC;
    }
    // 0x800C74AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C74B0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800C74B4: addiu       $s1, $s1, -0x5760
    ctx->r17 = ADD32(ctx->r17, -0X5760);
    // 0x800C74B8: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800C74BC: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
L_800C74C0:
    // 0x800C74C0: beql        $t7, $zero, L_800C74E0
    if (ctx->r15 == 0) {
        // 0x800C74C4: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800C74E0;
    }
    goto skip_0;
    // 0x800C74C4: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_0:
    // 0x800C74C8: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800C74CC: beql        $v0, $zero, L_800C74E0
    if (ctx->r2 == 0) {
        // 0x800C74D0: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800C74E0;
    }
    goto skip_1;
    // 0x800C74D0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    skip_1:
    // 0x800C74D4: jalr        $v0
    // 0x800C74D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x800C74D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800C74DC: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_800C74E0:
    // 0x800C74E0: addiu       $t8, $s1, 0x64
    ctx->r24 = ADD32(ctx->r17, 0X64);
    // 0x800C74E4: bnel        $s0, $t8, L_800C74C0
    if (ctx->r16 != ctx->r24) {
        // 0x800C74E8: lw          $t7, 0x4($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X4);
            goto L_800C74C0;
    }
    goto skip_2;
    // 0x800C74E8: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    skip_2:
L_800C74EC:
    // 0x800C74EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C74F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C74F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C74F8: jr          $ra
    // 0x800C74FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C74FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808000D0_bscarry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000D8: jal         0x8009E6EC
    // 0x808000DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808000DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808000E0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808000E4: beq         $v0, $at, L_80800100
    if (ctx->r2 == ctx->r1) {
        // 0x808000E8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800100;
    }
    // 0x808000E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000EC: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x808000F0: beq         $v0, $at, L_80800100
    if (ctx->r2 == ctx->r1) {
        // 0x808000F4: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_80800100;
    }
    // 0x808000F4: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x808000F8: bne         $v0, $at, L_80800110
    if (ctx->r2 != ctx->r1) {
        // 0x808000FC: nop
    
            goto L_80800110;
    }
    // 0x808000FC: nop

L_80800100:
    // 0x80800100: jal         0x80800000
    // 0x80800104: nop

    func_80800000_bscarry(rdram, ctx);
        goto after_1;
    // 0x80800104: nop

    after_1:
    // 0x80800108: b           L_8080011C
    // 0x8080010C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080011C;
    // 0x8080010C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800110:
    // 0x80800110: jal         0x80082FF8
    // 0x80800114: nop

    _bsdrone_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800114: nop

    after_2:
    // 0x80800118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080011C:
    // 0x8080011C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

;}
RECOMP_FUNC void func_80801D3C_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801D40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801D48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801D4C: jal         0x80100094
    // 0x80801D50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801D50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801D54: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80801D58: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x80801D5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801D60: lw          $t7, 0x7C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X7C);
    // 0x80801D64: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801D68: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80801D6C: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80801D70: bgez        $t9, L_80801D84
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80801D74: lui         $t0, 0x8080
        ctx->r8 = S32(RELOC_HI16(1700, 0X25E4) << 16);
            goto L_80801D84;
    }
    // 0x80801D74: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1700, 0X25E4) << 16);
    // 0x80801D78: addiu       $t0, $t0, 0x25E4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1700, 0X25E4));
    // 0x80801D7C: jal         0x800BBCB8
    // 0x80801D80: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80801D80: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
L_80801D84:
    // 0x80801D84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801D88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801D8C: jr          $ra
    // 0x80801D90: nop

    return;
    // 0x80801D90: nop

;}
RECOMP_FUNC void chbottlesplantgrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1460, 0XF0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1460, 0XF0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1460, 0XF0));
;}
RECOMP_FUNC void func_80800164_gcdialogexec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080016C: jal         0x808000A0
    // 0x80800170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808000A0_gcdialogexec(rdram, ctx);
        goto after_0;
    // 0x80800170: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800178: lbu         $t6, 0x11C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X11C);
    // 0x8080017C: srl         $t7, $t6, 6
    ctx->r15 = S32(U32(ctx->r14) >> 6);
    // 0x80800180: bnel        $t7, $zero, L_808001A8
    if (ctx->r15 != 0) {
        // 0x80800184: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_808001A8;
    }
    goto skip_0;
    // 0x80800184: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    skip_0:
    // 0x80800188: lbu         $t8, 0x11D($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X11D);
    // 0x8080018C: srl         $t9, $t8, 6
    ctx->r25 = S32(U32(ctx->r24) >> 6);
    // 0x80800190: bnel        $t9, $zero, L_808001A8
    if (ctx->r25 != 0) {
        // 0x80800194: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_808001A8;
    }
    goto skip_1;
    // 0x80800194: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    skip_1:
    // 0x80800198: jal         0x8080002C
    // 0x8080019C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080002C_gcdialogexec(rdram, ctx);
        goto after_1;
    // 0x8080019C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x808001A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001A4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_808001A8:
    // 0x808001A8: andi        $t1, $zero, 0xFF
    ctx->r9 = 0 & 0XFF;
    // 0x808001AC: sh          $t0, 0x162($a0)
    MEM_H(0X162, ctx->r4) = ctx->r8;
    // 0x808001B0: sh          $t1, 0x15A($a0)
    MEM_H(0X15A, ctx->r4) = ctx->r9;
    // 0x808001B4: sb          $zero, 0x15D($a0)
    MEM_B(0X15D, ctx->r4) = 0;
    // 0x808001B8: sw          $zero, 0x168($a0)
    MEM_W(0X168, ctx->r4) = 0;
    // 0x808001BC: sb          $zero, 0x167($a0)
    MEM_B(0X167, ctx->r4) = 0;
    // 0x808001C0: sw          $zero, 0x170($a0)
    MEM_W(0X170, ctx->r4) = 0;
    // 0x808001C4: sw          $zero, 0x174($a0)
    MEM_W(0X174, ctx->r4) = 0;
    // 0x808001C8: sw          $zero, 0x178($a0)
    MEM_W(0X178, ctx->r4) = 0;
    // 0x808001CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001D4: jr          $ra
    // 0x808001D8: nop

    return;
    // 0x808001D8: nop

;}
RECOMP_FUNC void _chklungoleave_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800863D8: syscall     320
    recomp_syscall_handler(rdram, ctx, 0x800863D8);
    return;
    // 0x800863DC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _glhittableDll_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088638: syscall     696
    recomp_syscall_handler(rdram, ctx, 0x80088638);
    return;
    // 0x8008863C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void subaddiefind_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800808: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8080080C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800810: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800814: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x80800818: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8080081C: jal         0x80800390
    // 0x80800820: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    subaddiefind_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x80800820: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x80800824: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x80800828: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080082C: blez        $v0, L_80800864
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800830: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800864;
    }
    // 0x80800830: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800834: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
L_80800838:
    // 0x80800838: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8080083C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800840: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80800844: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800848: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080084C: bne         $a3, $t7, L_8080085C
    if (ctx->r7 != ctx->r15) {
        // 0x80800850: nop
    
            goto L_8080085C;
    }
    // 0x80800850: nop

    // 0x80800854: b           L_80800868
    // 0x80800858: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80800868;
    // 0x80800858: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8080085C:
    // 0x8080085C: bne         $at, $zero, L_80800838
    if (ctx->r1 != 0) {
        // 0x80800860: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80800838;
    }
    // 0x80800860: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80800864:
    // 0x80800864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800868:
    // 0x80800868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080086C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80800870: jr          $ra
    // 0x80800874: nop

    return;
    // 0x80800874: nop

;}
RECOMP_FUNC void baflamethrower_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001EC: jal         0x80800088
    // 0x808001F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800088_baflamethrower(rdram, ctx);
        goto after_0;
    // 0x808001F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x808001F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001FC: jr          $ra
    // 0x80800200: nop

    return;
    // 0x80800200: nop

;}
RECOMP_FUNC void func_800F521C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F521C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5220: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5224: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5228: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F522C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F5230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5234: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F5238: jal         0x80084758
    // 0x800F523C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    _badata_entrypoint_35(rdram, ctx);
        goto after_0;
    // 0x800F523C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F5240: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F5244: jal         0x8009E5C8
    // 0x800F5248: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_1;
    // 0x800F5248: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800F524C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F5250: jal         0x800F457C
    // 0x800F5254: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800F457C(rdram, ctx);
        goto after_2;
    // 0x800F5254: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x800F5258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F525C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F5260: jr          $ra
    // 0x800F5264: nop

    return;
    // 0x800F5264: nop

;}
RECOMP_FUNC void func_801073F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801073F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801073FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107400: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80107404: jal         0x80107388
    // 0x80107408: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80107388(rdram, ctx);
        goto after_0;
    // 0x80107408: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8010740C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80107410: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80107414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107418: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8010741C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80107420: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x80107424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80107428: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010742C: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x80107430: beq         $t1, $zero, L_80107440
    if (ctx->r9 == 0) {
        // 0x80107434: nop
    
            goto L_80107440;
    }
    // 0x80107434: nop

    // 0x80107438: b           L_80107440
    // 0x8010743C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80107440;
    // 0x8010743C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80107440:
    // 0x80107440: jr          $ra
    // 0x80107444: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80107444: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8080024C_chhotwaterpoolbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080024C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800250: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800254: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800258: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x8080025C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800260: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800264: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800268: beq         $t6, $at, L_80800294
    if (ctx->r14 == ctx->r1) {
        // 0x8080026C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800294;
    }
    // 0x8080026C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800270: beq         $t6, $at, L_808002F8
    if (ctx->r14 == ctx->r1) {
        // 0x80800274: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_808002F8;
    }
    // 0x80800274: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800278: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080027C: beq         $t6, $at, L_8080031C
    if (ctx->r14 == ctx->r1) {
        // 0x80800280: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8080031C;
    }
    // 0x80800280: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800284: beq         $t6, $at, L_80800398
    if (ctx->r14 == ctx->r1) {
        // 0x80800288: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_80800398;
    }
    // 0x80800288: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x8080028C: b           L_808003C4
    // 0x80800290: nop

        goto L_808003C4;
    // 0x80800290: nop

L_80800294:
    // 0x80800294: jal         0x800D9078
    // 0x80800298: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800298: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x8080029C: beq         $v0, $zero, L_808002B8
    if (ctx->r2 == 0) {
        // 0x808002A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002B8;
    }
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A4: jal         0x80101FDC
    // 0x808002A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_1;
    // 0x808002A8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002B0: jal         0x80103110
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_2;
    // 0x808002B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_808002B8:
    // 0x808002B8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808002BC: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808002C0: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x808002C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808002C8: jal         0x800F10B4
    // 0x808002CC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x808002CC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x808002D0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1268, 0XA50) << 16);
    // 0x808002D4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1268, 0XA5C) << 16);
    // 0x808002D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808002DC: addiu       $a2, $a2, 0xA5C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1268, 0XA5C));
    // 0x808002E0: addiu       $a1, $a1, 0xA50
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1268, 0XA50));
    // 0x808002E4: jal         0x800F3214
    // 0x808002E8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800F3214(rdram, ctx);
        goto after_4;
    // 0x808002E8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_4:
    // 0x808002EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808002F0: b           L_808003C4
    // 0x808002F4: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
        goto L_808003C4;
    // 0x808002F4: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
L_808002F8:
    // 0x808002F8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1268, 0XA5C) << 16);
    // 0x808002FC: jal         0x800F2E60
    // 0x80800300: addiu       $a1, $a1, 0xA5C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1268, 0XA5C));
    func_800F2E60(rdram, ctx);
        goto after_5;
    // 0x80800300: addiu       $a1, $a1, 0xA5C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1268, 0XA5C));
    after_5:
    // 0x80800304: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80800308: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080030C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800310: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    // 0x80800314: b           L_808003C4
    // 0x80800318: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
        goto L_808003C4;
    // 0x80800318: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
L_8080031C:
    // 0x8080031C: jal         0x800D9078
    // 0x80800320: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x80800320: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_6:
    // 0x80800324: beq         $v0, $zero, L_80800340
    if (ctx->r2 == 0) {
        // 0x80800328: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800340;
    }
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080032C: jal         0x80101FDC
    // 0x80800330: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x80800330: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: jal         0x80103110
    // 0x8080033C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_8;
    // 0x8080033C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_80800340:
    // 0x80800340: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800344: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800348: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8080034C: lui         $a3, 0xC448
    ctx->r7 = S32(0XC448 << 16);
    // 0x80800350: jal         0x800F12D4
    // 0x80800354: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_9;
    // 0x80800354: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_9:
    // 0x80800358: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8080035C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800360: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800364: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80800368: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8080036C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x80800370: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80800374: jal         0x800F12D4
    // 0x80800378: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F12D4(rdram, ctx);
        goto after_10;
    // 0x80800378: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x8080037C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1268, 0XA5C) << 16);
    // 0x80800380: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800384: addiu       $a1, $a1, 0xA5C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1268, 0XA5C));
    // 0x80800388: jal         0x800F2E60
    // 0x8080038C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800F2E60(rdram, ctx);
        goto after_11;
    // 0x8080038C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_11:
    // 0x80800390: b           L_808003C4
    // 0x80800394: nop

        goto L_808003C4;
    // 0x80800394: nop

L_80800398:
    // 0x80800398: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1268, 0XA5C) << 16);
    // 0x8080039C: jal         0x800F2E60
    // 0x808003A0: addiu       $a1, $a1, 0xA5C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1268, 0XA5C));
    func_800F2E60(rdram, ctx);
        goto after_12;
    // 0x808003A0: addiu       $a1, $a1, 0xA5C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1268, 0XA5C));
    after_12:
    // 0x808003A4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808003A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808003AC: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x808003B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808003B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003B8: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x808003BC: jal         0x800FFAB0
    // 0x808003C0: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    func_800FFAB0(rdram, ctx);
        goto after_13;
    // 0x808003C0: swc1        $f18, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f18.u32l;
    after_13:
L_808003C4:
    // 0x808003C4: jal         0x80800528
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800528_chhotwaterpoolbits(rdram, ctx);
        goto after_14;
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808003CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003D8: jr          $ra
    // 0x808003DC: nop

    return;
    // 0x808003DC: nop

;}
RECOMP_FUNC void func_808016E8_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808016EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808016F0: jal         0x80106790
    // 0x808016F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808016F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808016F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808016FC: jal         0x808013C8
    // 0x80801700: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_808013C8_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80801700: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80801704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080170C: jr          $ra
    // 0x80801710: nop

    return;
    // 0x80801710: nop

;}
RECOMP_FUNC void func_80800968_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800968: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080096C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800970: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800974: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800978: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080097C: beq         $a1, $at, L_80800A2C
    if (ctx->r5 == ctx->r1) {
        // 0x80800980: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80800A2C;
    }
    // 0x80800980: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800984: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800988: beq         $a1, $at, L_808009D0
    if (ctx->r5 == ctx->r1) {
        // 0x8080098C: addiu       $v0, $sp, 0x30
        ctx->r2 = ADD32(ctx->r29, 0X30);
            goto L_808009D0;
    }
    // 0x8080098C: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x80800990: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80800994: beq         $a1, $at, L_808009E8
    if (ctx->r5 == ctx->r1) {
        // 0x80800998: addiu       $v0, $sp, 0x30
        ctx->r2 = ADD32(ctx->r29, 0X30);
            goto L_808009E8;
    }
    // 0x80800998: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x8080099C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808009A0: beq         $a1, $at, L_80800A00
    if (ctx->r5 == ctx->r1) {
        // 0x808009A4: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80800A00;
    }
    // 0x808009A4: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x808009A8: beq         $a1, $at, L_80800A18
    if (ctx->r5 == ctx->r1) {
        // 0x808009AC: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(800, 0X10C0) << 16);
            goto L_80800A18;
    }
    // 0x808009AC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(800, 0X10C0) << 16);
    // 0x808009B0: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x808009B4: beq         $a1, $at, L_80800AD4
    if (ctx->r5 == ctx->r1) {
        // 0x808009B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800AD4;
    }
    // 0x808009B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009BC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808009C0: beq         $a1, $at, L_80800A34
    if (ctx->r5 == ctx->r1) {
        // 0x808009C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A34;
    }
    // 0x808009C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009C8: b           L_80800B18
    // 0x808009CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B18;
    // 0x808009CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808009D0:
    // 0x808009D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D4: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808009D8: jal         0x80800744
    // 0x808009DC: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80800744_chhoneyb(rdram, ctx);
        goto after_0;
    // 0x808009DC: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_0:
    // 0x808009E0: b           L_80800B18
    // 0x808009E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B18;
    // 0x808009E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009E8:
    // 0x808009E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009EC: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x808009F0: jal         0x80800920
    // 0x808009F4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_80800920_chhoneyb(rdram, ctx);
        goto after_1;
    // 0x808009F4: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_1:
    // 0x808009F8: b           L_80800B1C
    // 0x808009FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B1C;
    // 0x808009FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800A00:
    // 0x80800A00: jal         0x800904C8
    // 0x80800A04: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800904C8(rdram, ctx);
        goto after_2;
    // 0x80800A04: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_2:
    // 0x80800A08: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x80800A0C: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80800A10: b           L_80800B14
    // 0x80800A14: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
        goto L_80800B14;
    // 0x80800A14: sb          $t8, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r24;
L_80800A18:
    // 0x80800A18: addiu       $a0, $a0, 0x10C0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(800, 0X10C0));
    // 0x80800A1C: jal         0x80088090
    // 0x80800A20: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800A20: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x80800A24: b           L_80800B18
    // 0x80800A28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B18;
    // 0x80800A28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A2C:
    // 0x80800A2C: b           L_80800B18
    // 0x80800A30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800B18;
    // 0x80800A30: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800A34:
    // 0x80800A34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A38: jal         0x800897C0
    // 0x80800A3C: addiu       $a2, $zero, 0x9B
    ctx->r6 = ADD32(0, 0X9B);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_4;
    // 0x80800A3C: addiu       $a2, $zero, 0x9B
    ctx->r6 = ADD32(0, 0X9B);
    after_4:
    // 0x80800A40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A44: lui         $a1, 0x4270
    ctx->r5 = S32(0X4270 << 16);
    // 0x80800A48: jal         0x800897E8
    // 0x80800A4C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x80800A4C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_5:
    // 0x80800A50: jal         0x800DA298
    // 0x80800A54: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800A54: addiu       $a0, $zero, 0x4E9
    ctx->r4 = ADD32(0, 0X4E9);
    after_6:
    // 0x80800A58: bnel        $v0, $zero, L_80800B18
    if (ctx->r2 != 0) {
        // 0x80800A5C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800B18;
    }
    goto skip_0;
    // 0x80800A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800A60: jal         0x80088848
    // 0x80800A64: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_7;
    // 0x80800A64: nop

    after_7:
    // 0x80800A68: bnel        $v0, $zero, L_80800B18
    if (ctx->r2 != 0) {
        // 0x80800A6C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800B18;
    }
    goto skip_1;
    // 0x80800A6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800A70: jal         0x8008F8B0
    // 0x80800A74: nop

    func_8008F8B0(rdram, ctx);
        goto after_8;
    // 0x80800A74: nop

    after_8:
    // 0x80800A78: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800A7C: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80800A80: jal         0x8008F904
    // 0x80800A84: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_8008F904(rdram, ctx);
        goto after_9;
    // 0x80800A84: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x80800A88: jal         0x8008F8D8
    // 0x80800A8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_10;
    // 0x80800A8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x80800A90: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800A94: jal         0x8008F990
    // 0x80800A98: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_8008F990(rdram, ctx);
        goto after_11;
    // 0x80800A98: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_11:
    // 0x80800A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA0: jal         0x80100094
    // 0x80800AA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x80800AA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800AA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800AB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800AB4: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    // 0x80800AB8: jal         0x8008A2D0
    // 0x80800ABC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_13;
    // 0x80800ABC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AC4: jal         0x80102424
    // 0x80800AC8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_14;
    // 0x80800AC8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x80800ACC: b           L_80800B18
    // 0x80800AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B18;
    // 0x80800AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AD4:
    // 0x80800AD4: jal         0x80100094
    // 0x80800AD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_15;
    // 0x80800AD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800ADC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80800AE0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800AE4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80800AE8: andi        $t9, $a2, 0xFFFF
    ctx->r25 = ctx->r6 & 0XFFFF;
    // 0x80800AEC: and         $t0, $a3, $at
    ctx->r8 = ctx->r7 & ctx->r1;
    // 0x80800AF0: srl         $a3, $t0, 16
    ctx->r7 = S32(U32(ctx->r8) >> 16);
    // 0x80800AF4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80800AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AFC: jal         0x8008A2B8
    // 0x80800B00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _susubgame_entrypoint_3(rdram, ctx);
        goto after_16;
    // 0x80800B00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x80800B04: b           L_80800B1C
    // 0x80800B08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800B1C;
    // 0x80800B08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800B0C: b           L_80800B18
    // 0x80800B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B18;
    // 0x80800B10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B14:
    // 0x80800B14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B18:
    // 0x80800B18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800B1C:
    // 0x80800B1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800B20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800B24: jr          $ra
    // 0x80800B28: nop

    return;
    // 0x80800B28: nop

;}
RECOMP_FUNC void func_800C0208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0208: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C020C: addiu       $v0, $v0, -0x7750
    ctx->r2 = ADD32(ctx->r2, -0X7750);
    // 0x800C0210: lw          $a0, 0x168($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X168);
    // 0x800C0214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C0218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C021C: bne         $a0, $zero, L_800C022C
    if (ctx->r4 != 0) {
        // 0x800C0220: nop
    
            goto L_800C022C;
    }
    // 0x800C0220: nop

    // 0x800C0224: b           L_800C0248
    // 0x800C0228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C0248;
    // 0x800C0228: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C022C:
    // 0x800C022C: jal         0x800C0090
    // 0x800C0230: lw          $a1, 0x16C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X16C);
    func_800C0090(rdram, ctx);
        goto after_0;
    // 0x800C0230: lw          $a1, 0x16C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X16C);
    after_0:
    // 0x800C0234: beq         $v0, $zero, L_800C0244
    if (ctx->r2 == 0) {
        // 0x800C0238: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800C0244;
    }
    // 0x800C0238: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C023C: b           L_800C0248
    // 0x800C0240: lw          $v0, -0x75E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X75E8);
        goto L_800C0248;
    // 0x800C0240: lw          $v0, -0x75E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X75E8);
L_800C0244:
    // 0x800C0244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0248:
    // 0x800C0248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C024C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C0250: jr          $ra
    // 0x800C0254: nop

    return;
    // 0x800C0254: nop

;}
RECOMP_FUNC void func_800E71EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E71EC: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800E71F0: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x800E71F4: bnel        $t6, $t7, L_800E724C
    if (ctx->r14 != ctx->r15) {
        // 0x800E71F8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800E724C;
    }
    goto skip_0;
    // 0x800E71F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800E71FC: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
L_800E7200:
    // 0x800E7200: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800E7204: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800E7208: beql        $v0, $zero, L_800E7220
    if (ctx->r2 == 0) {
        // 0x800E720C: lbu         $v1, 0x0($a2)
        ctx->r3 = MEM_BU(ctx->r6, 0X0);
            goto L_800E7220;
    }
    goto skip_1;
    // 0x800E720C: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    skip_1:
    // 0x800E7210: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800E7214: bnel        $v0, $t8, L_800E7240
    if (ctx->r2 != ctx->r24) {
        // 0x800E7218: lbu         $t0, 0x0($a2)
        ctx->r8 = MEM_BU(ctx->r6, 0X0);
            goto L_800E7240;
    }
    goto skip_2;
    // 0x800E7218: lbu         $t0, 0x0($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X0);
    skip_2:
    // 0x800E721C: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
L_800E7220:
    // 0x800E7220: beq         $v1, $zero, L_800E7234
    if (ctx->r3 == 0) {
        // 0x800E7224: nop
    
            goto L_800E7234;
    }
    // 0x800E7224: nop

    // 0x800E7228: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800E722C: bnel        $v1, $t9, L_800E7240
    if (ctx->r3 != ctx->r25) {
        // 0x800E7230: lbu         $t0, 0x0($a2)
        ctx->r8 = MEM_BU(ctx->r6, 0X0);
            goto L_800E7240;
    }
    goto skip_3;
    // 0x800E7230: lbu         $t0, 0x0($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X0);
    skip_3:
L_800E7234:
    // 0x800E7234: jr          $ra
    // 0x800E7238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E7238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E723C: lbu         $t0, 0x0($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X0);
L_800E7240:
    // 0x800E7240: beql        $v0, $t0, L_800E7200
    if (ctx->r2 == ctx->r8) {
        // 0x800E7244: lbu         $v0, 0x1($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X1);
            goto L_800E7200;
    }
    goto skip_4;
    // 0x800E7244: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    skip_4:
    // 0x800E7248: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E724C:
    // 0x800E724C: jr          $ra
    // 0x800E7250: nop

    return;
    // 0x800E7250: nop

;}
RECOMP_FUNC void func_80800250_bsbbilldrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800250: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800258: jal         0x8009C128
    // 0x8080025C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8080025C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800260: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800264: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800268: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8080026C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800270: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800274: jal         0x80088970
    // 0x80800278: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    _fxdlsmoke_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800278: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8080027C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800280: jal         0x800BA22C
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_2;
    // 0x80800284: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080028C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800290: jr          $ra
    // 0x80800294: nop

    return;
    // 0x80800294: nop

;}
RECOMP_FUNC void func_800ABCE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABCE0: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x800ABCE4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800ABCE8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800ABCEC: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x800ABCF0: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x800ABCF4: addiu       $s0, $sp, 0xAC
    ctx->r16 = ADD32(ctx->r29, 0XAC);
    // 0x800ABCF8: addiu       $s2, $sp, 0xA0
    ctx->r18 = ADD32(ctx->r29, 0XA0);
    // 0x800ABCFC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800ABD00: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x800ABD04: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800ABD08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800ABD0C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800ABD10: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800ABD14: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800ABD18: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800ABD1C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800ABD20: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800ABD24: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800ABD28: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800ABD2C: lw          $a2, 0xEC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XEC);
    // 0x800ABD30: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800ABD34: jal         0x800ABC58
    // 0x800ABD38: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_800ABC58(rdram, ctx);
        goto after_0;
    // 0x800ABD38: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_0:
    // 0x800ABD3C: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x800ABD40: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800ABD44: addiu       $a0, $sp, 0xA0
    ctx->r4 = ADD32(ctx->r29, 0XA0);
    // 0x800ABD48: lhu         $t7, 0x14($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X14);
    // 0x800ABD4C: addiu       $a1, $sp, 0xB8
    ctx->r5 = ADD32(ctx->r29, 0XB8);
    // 0x800ABD50: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800ABD54: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800ABD58: addiu       $a3, $sp, 0xD4
    ctx->r7 = ADD32(ctx->r29, 0XD4);
    // 0x800ABD5C: bgez        $t7, L_800ABD74
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800ABD60: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800ABD74;
    }
    // 0x800ABD60: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800ABD64: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800ABD68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ABD6C: nop

    // 0x800ABD70: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_800ABD74:
    // 0x800ABD74: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_800ABD78:
    // 0x800ABD78: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800ABD7C: addu        $v0, $s0, $v1
    ctx->r2 = ADD32(ctx->r16, ctx->r3);
    // 0x800ABD80: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800ABD84: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x800ABD88: nop

    // 0x800ABD8C: bc1t        L_800ABDAC
    if (c1cs) {
        // 0x800ABD90: nop
    
            goto L_800ABDAC;
    }
    // 0x800ABD90: nop

    // 0x800ABD94: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800ABD98: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800ABD9C: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x800ABDA0: nop

    // 0x800ABDA4: bc1f        L_800ABDB4
    if (!c1cs) {
        // 0x800ABDA8: nop
    
            goto L_800ABDB4;
    }
    // 0x800ABDA8: nop

L_800ABDAC:
    // 0x800ABDAC: b           L_800AC0CC
    // 0x800ABDB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800AC0CC;
    // 0x800ABDB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800ABDB4:
    // 0x800ABDB4: bne         $v0, $a1, L_800ABD78
    if (ctx->r2 != ctx->r5) {
        // 0x800ABDB8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800ABD78;
    }
    // 0x800ABDB8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800ABDBC: addiu       $t8, $sp, 0xCC
    ctx->r24 = ADD32(ctx->r29, 0XCC);
    // 0x800ABDC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800ABDC4: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x800ABDC8: jal         0x800AA4D4
    // 0x800ABDCC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800AA4D4(rdram, ctx);
        goto after_1;
    // 0x800ABDCC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800ABDD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800ABDD4: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
    // 0x800ABDD8: lw          $v0, 0x798C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X798C);
    // 0x800ABDDC: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x800ABDE0: sw          $v1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r3;
    // 0x800ABDE4: addiu       $t9, $v0, 0x10
    ctx->r25 = ADD32(ctx->r2, 0X10);
    // 0x800ABDE8: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x800ABDEC: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x800ABDF0: beq         $at, $zero, L_800AC0AC
    if (ctx->r1 == 0) {
        // 0x800ABDF4: sw          $v0, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r2;
            goto L_800AC0AC;
    }
    // 0x800ABDF4: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x800ABDF8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800ABDFC: lw          $fp, 0xF0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XF0);
    // 0x800ABE00: addiu       $s6, $sp, 0xC0
    ctx->r22 = ADD32(ctx->r29, 0XC0);
    // 0x800ABE04: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800ABE08: addiu       $s2, $sp, 0x80
    ctx->r18 = ADD32(ctx->r29, 0X80);
L_800ABE0C:
    // 0x800ABE0C: lw          $t1, 0xD0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD0);
    // 0x800ABE10: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x800ABE14: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800ABE18: lhu         $t6, 0x10($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X10);
    // 0x800ABE1C: lhu         $t2, 0x0($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X0);
    // 0x800ABE20: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x800ABE24: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800ABE28: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800ABE2C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800ABE30: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800ABE34: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800ABE38: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800ABE3C: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x800ABE40: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800ABE44: addiu       $s5, $v0, 0x18
    ctx->r21 = ADD32(ctx->r2, 0X18);
    // 0x800ABE48: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800ABE4C: addu        $s7, $t9, $s5
    ctx->r23 = ADD32(ctx->r25, ctx->r21);
    // 0x800ABE50: sltu        $at, $s5, $s7
    ctx->r1 = ctx->r21 < ctx->r23 ? 1 : 0;
    // 0x800ABE54: beql        $at, $zero, L_800AC098
    if (ctx->r1 == 0) {
        // 0x800ABE58: lw          $t4, 0xD0($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XD0);
            goto L_800AC098;
    }
    goto skip_0;
    // 0x800ABE58: lw          $t4, 0xD0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD0);
    skip_0:
    // 0x800ABE5C: lw          $t0, 0x8($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X8);
L_800ABE60:
    // 0x800ABE60: lw          $s3, 0xDC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XDC);
    // 0x800ABE64: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x800ABE68: and         $t1, $t0, $fp
    ctx->r9 = ctx->r8 & ctx->r30;
    // 0x800ABE6C: bne         $t1, $zero, L_800AC084
    if (ctx->r9 != 0) {
        // 0x800ABE70: addiu       $s3, $s3, 0x18
        ctx->r19 = ADD32(ctx->r19, 0X18);
            goto L_800AC084;
    }
    // 0x800ABE70: addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // 0x800ABE74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800ABE78:
    // 0x800ABE78: lhu         $t2, 0x0($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X0);
    // 0x800ABE7C: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x800ABE80: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800ABE84: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    // 0x800ABE88: addu        $a1, $t3, $s3
    ctx->r5 = ADD32(ctx->r11, ctx->r19);
    // 0x800ABE8C: jal         0x800EE88C
    // 0x800ABE90: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x800ABE90: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_2:
    // 0x800ABE94: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800ABE98: slti        $at, $s0, 0x24
    ctx->r1 = SIGNED(ctx->r16) < 0X24 ? 1 : 0;
    // 0x800ABE9C: bne         $at, $zero, L_800ABE78
    if (ctx->r1 != 0) {
        // 0x800ABEA0: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800ABE78;
    }
    // 0x800ABEA0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800ABEA4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800ABEA8: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x800ABEAC: jal         0x800EE7F8
    // 0x800ABEB0: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x800ABEB0: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_3:
    // 0x800ABEB4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800ABEB8: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x800ABEBC: jal         0x800EE7F8
    // 0x800ABEC0: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x800ABEC0: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_4:
    // 0x800ABEC4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800ABEC8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800ABECC: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_800ABED0:
    // 0x800ABED0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800ABED4: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x800ABED8: addiu       $v0, $sp, 0x74
    ctx->r2 = ADD32(ctx->r29, 0X74);
L_800ABEDC:
    // 0x800ABEDC: lwc1        $f0, 0x28($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X28);
    // 0x800ABEE0: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800ABEE4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800ABEE8: nop

    // 0x800ABEEC: bc1fl       L_800ABF00
    if (!c1cs) {
        // 0x800ABEF0: lwc1        $f18, 0x0($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
            goto L_800ABF00;
    }
    goto skip_1;
    // 0x800ABEF0: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x800ABEF4: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x800ABEF8: lwc1        $f0, 0x28($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X28);
    // 0x800ABEFC: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
L_800ABF00:
    // 0x800ABF00: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800ABF04: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800ABF08: nop

    // 0x800ABF0C: bc1fl       L_800ABF1C
    if (!c1cs) {
        // 0x800ABF10: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800ABF1C;
    }
    goto skip_2;
    // 0x800ABF10: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_2:
    // 0x800ABF14: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x800ABF18: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800ABF1C:
    // 0x800ABF1C: bne         $v0, $s2, L_800ABEDC
    if (ctx->r2 != ctx->r18) {
        // 0x800ABF20: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800ABEDC;
    }
    // 0x800ABF20: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800ABF24: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800ABF28: bne         $a3, $s4, L_800ABED0
    if (ctx->r7 != ctx->r20) {
        // 0x800ABF2C: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_800ABED0;
    }
    // 0x800ABF2C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x800ABF30: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800ABF34: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800ABF38: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800ABF3C: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800ABF40: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800ABF44: nop

    // 0x800ABF48: bc1tl       L_800AC088
    if (c1cs) {
        // 0x800ABF4C: addiu       $s5, $s5, 0xC
        ctx->r21 = ADD32(ctx->r21, 0XC);
            goto L_800AC088;
    }
    goto skip_3;
    // 0x800ABF4C: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    skip_3:
    // 0x800ABF50: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800ABF54: lwc1        $f16, 0xA4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800ABF58: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800ABF5C: bc1tl       L_800AC088
    if (c1cs) {
        // 0x800ABF60: addiu       $s5, $s5, 0xC
        ctx->r21 = ADD32(ctx->r21, 0XC);
            goto L_800AC088;
    }
    goto skip_4;
    // 0x800ABF60: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    skip_4:
    // 0x800ABF64: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800ABF68: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800ABF6C: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800ABF70: bc1tl       L_800AC088
    if (c1cs) {
        // 0x800ABF74: addiu       $s5, $s5, 0xC
        ctx->r21 = ADD32(ctx->r21, 0XC);
            goto L_800AC088;
    }
    goto skip_5;
    // 0x800ABF74: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    skip_5:
    // 0x800ABF78: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800ABF7C: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800ABF80: lwc1        $f10, 0x88($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800ABF84: bc1tl       L_800AC088
    if (c1cs) {
        // 0x800ABF88: addiu       $s5, $s5, 0xC
        ctx->r21 = ADD32(ctx->r21, 0XC);
            goto L_800AC088;
    }
    goto skip_6;
    // 0x800ABF88: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    skip_6:
    // 0x800ABF8C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800ABF90: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800ABF94: lwc1        $f18, 0xB4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800ABF98: bc1tl       L_800AC088
    if (c1cs) {
        // 0x800ABF9C: addiu       $s5, $s5, 0xC
        ctx->r21 = ADD32(ctx->r21, 0XC);
            goto L_800AC088;
    }
    goto skip_7;
    // 0x800ABF9C: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    skip_7:
    // 0x800ABFA0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800ABFA4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800ABFA8: bc1t        L_800AC084
    if (c1cs) {
        // 0x800ABFAC: addiu       $a1, $a0, 0x34
        ctx->r5 = ADD32(ctx->r4, 0X34);
            goto L_800AC084;
    }
    // 0x800ABFAC: addiu       $a1, $a0, 0x34
    ctx->r5 = ADD32(ctx->r4, 0X34);
    // 0x800ABFB0: jal         0x800EFB24
    // 0x800ABFB4: addiu       $a2, $a0, 0x28
    ctx->r6 = ADD32(ctx->r4, 0X28);
    func_800EFB24(rdram, ctx);
        goto after_5;
    // 0x800ABFB4: addiu       $a2, $a0, 0x28
    ctx->r6 = ADD32(ctx->r4, 0X28);
    after_5:
    // 0x800ABFB8: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800ABFBC: addiu       $a0, $t5, 0xC
    ctx->r4 = ADD32(ctx->r13, 0XC);
    // 0x800ABFC0: addiu       $a1, $t5, 0x40
    ctx->r5 = ADD32(ctx->r13, 0X40);
    // 0x800ABFC4: jal         0x800EFB24
    // 0x800ABFC8: addiu       $a2, $t5, 0x28
    ctx->r6 = ADD32(ctx->r13, 0X28);
    func_800EFB24(rdram, ctx);
        goto after_6;
    // 0x800ABFC8: addiu       $a2, $t5, 0x28
    ctx->r6 = ADD32(ctx->r13, 0X28);
    after_6:
    // 0x800ABFCC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800ABFD0: addiu       $a0, $a1, 0x18
    ctx->r4 = ADD32(ctx->r5, 0X18);
    // 0x800ABFD4: jal         0x800EE97C
    // 0x800ABFD8: addiu       $a2, $a1, 0xC
    ctx->r6 = ADD32(ctx->r5, 0XC);
    func_800EE97C(rdram, ctx);
        goto after_7;
    // 0x800ABFD8: addiu       $a2, $a1, 0xC
    ctx->r6 = ADD32(ctx->r5, 0XC);
    after_7:
    // 0x800ABFDC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800ABFE0: jal         0x800EF2A0
    // 0x800ABFE4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EF2A0(rdram, ctx);
        goto after_8;
    // 0x800ABFE4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_8:
    // 0x800ABFE8: lw          $t8, 0x8($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X8);
    // 0x800ABFEC: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800ABFF0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800ABFF4: sll         $t9, $t8, 15
    ctx->r25 = S32(ctx->r24 << 15);
    // 0x800ABFF8: bgez        $t9, L_800AC054
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800ABFFC: addiu       $a2, $a2, 0x28
        ctx->r6 = ADD32(ctx->r6, 0X28);
            goto L_800AC054;
    }
    // 0x800ABFFC: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x800AC000: jal         0x800EFB24
    // 0x800AC004: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    func_800EFB24(rdram, ctx);
        goto after_9;
    // 0x800AC004: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    after_9:
    // 0x800AC008: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800AC00C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800AC010: jal         0x800EEAA4
    // 0x800AC014: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    func_800EEAA4(rdram, ctx);
        goto after_10;
    // 0x800AC014: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_10:
    // 0x800AC018: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800AC01C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800AC020: bc1fl       L_800AC058
    if (!c1cs) {
        // 0x800AC024: lw          $a0, 0x68($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X68);
            goto L_800AC058;
    }
    goto skip_8;
    // 0x800AC024: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    skip_8:
    // 0x800AC028: lwc1        $f4, 0x18($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800AC02C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800AC030: swc1        $f6, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f6.u32l;
    // 0x800AC034: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800AC038: lwc1        $f8, 0x1C($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800AC03C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800AC040: swc1        $f10, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f10.u32l;
    // 0x800AC044: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800AC048: lwc1        $f16, 0x20($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X20);
    // 0x800AC04C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800AC050: swc1        $f18, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f18.u32l;
L_800AC054:
    // 0x800AC054: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
L_800AC058:
    // 0x800AC058: lw          $a1, 0xE8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE8);
    // 0x800AC05C: jal         0x800EEAA4
    // 0x800AC060: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    func_800EEAA4(rdram, ctx);
        goto after_11;
    // 0x800AC060: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_11:
    // 0x800AC064: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800AC068: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800AC06C: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x800AC070: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x800AC074: bc1tl       L_800AC088
    if (c1cs) {
        // 0x800AC078: addiu       $s5, $s5, 0xC
        ctx->r21 = ADD32(ctx->r21, 0XC);
            goto L_800AC088;
    }
    goto skip_9;
    // 0x800AC078: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    skip_9:
    // 0x800AC07C: jal         0x800ABB34
    // 0x800AC080: sw          $s5, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r21;
    func_800ABB34(rdram, ctx);
        goto after_12;
    // 0x800AC080: sw          $s5, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r21;
    after_12:
L_800AC084:
    // 0x800AC084: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
L_800AC088:
    // 0x800AC088: sltu        $at, $s5, $s7
    ctx->r1 = ctx->r21 < ctx->r23 ? 1 : 0;
    // 0x800AC08C: bnel        $at, $zero, L_800ABE60
    if (ctx->r1 != 0) {
        // 0x800AC090: lw          $t0, 0x8($s5)
        ctx->r8 = MEM_W(ctx->r21, 0X8);
            goto L_800ABE60;
    }
    goto skip_10;
    // 0x800AC090: lw          $t0, 0x8($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X8);
    skip_10:
    // 0x800AC094: lw          $t4, 0xD0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD0);
L_800AC098:
    // 0x800AC098: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x800AC09C: addiu       $t6, $t4, 0x4
    ctx->r14 = ADD32(ctx->r12, 0X4);
    // 0x800AC0A0: sltu        $at, $t6, $t5
    ctx->r1 = ctx->r14 < ctx->r13 ? 1 : 0;
    // 0x800AC0A4: bne         $at, $zero, L_800ABE0C
    if (ctx->r1 != 0) {
        // 0x800AC0A8: sw          $t6, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->r14;
            goto L_800ABE0C;
    }
    // 0x800AC0A8: sw          $t6, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r14;
L_800AC0AC:
    // 0x800AC0AC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800AC0B0: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x800AC0B4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AC0B8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800AC0BC: lw          $t9, 0x798C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X798C);
    // 0x800AC0C0: addiu       $t0, $t9, 0x10
    ctx->r8 = ADD32(ctx->r25, 0X10);
    // 0x800AC0C4: xor         $v0, $t7, $t0
    ctx->r2 = ctx->r15 ^ ctx->r8;
    // 0x800AC0C8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_800AC0CC:
    // 0x800AC0CC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800AC0D0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800AC0D4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AC0D8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800AC0DC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800AC0E0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800AC0E4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800AC0E8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800AC0EC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800AC0F0: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800AC0F4: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800AC0F8: jr          $ra
    // 0x800AC0FC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x800AC0FC: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_80098BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098BA0: jr          $ra
    // 0x80098BA4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    return;
    // 0x80098BA4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bskazstilt_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808002F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002FC: jal         0x8080013C
    // 0x80800300: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8080013C_bskazstilt(rdram, ctx);
        goto after_0;
    // 0x80800300: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800308: addiu       $a1, $zero, 0x27F
    ctx->r5 = ADD32(0, 0X27F);
    // 0x8080030C: jal         0x8008CDB8
    // 0x80800310: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_playForDuration_once(rdram, ctx);
        goto after_1;
    // 0x80800310: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x80800314: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800318: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800324: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800328: jal         0x8009FFD8
    // 0x8080032C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080032C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800334: jal         0x8009B9B0
    // 0x80800338: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800338: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x8080033C: jal         0x800A3394
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3394(rdram, ctx);
        goto after_4;
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800344: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080034C: jal         0x800917A8
    // 0x80800350: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    bastatetimer_set(rdram, ctx);
        goto after_5;
    // 0x80800350: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80800354: jal         0x800C77DC
    // 0x80800358: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800C77DC(rdram, ctx);
        goto after_6;
    // 0x80800358: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x8080035C: jal         0x800C2E04
    // 0x80800360: nop

    func_800C2E04(rdram, ctx);
        goto after_7;
    // 0x80800360: nop

    after_7:
    // 0x80800364: sb          $v0, 0x160($s0)
    MEM_B(0X160, ctx->r16) = ctx->r2;
    // 0x80800368: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8080036C: jal         0x800C301C
    // 0x80800370: addiu       $a1, $zero, 0x41D
    ctx->r5 = ADD32(0, 0X41D);
    func_800C301C(rdram, ctx);
        goto after_8;
    // 0x80800370: addiu       $a1, $zero, 0x41D
    ctx->r5 = ADD32(0, 0X41D);
    after_8:
    // 0x80800374: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    // 0x80800378: jal         0x800C330C
    // 0x8080037C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_9;
    // 0x8080037C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x80800380: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80800384: lui         $a2, 0x3FF3
    ctx->r6 = S32(0X3FF3 << 16);
    // 0x80800388: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x8080038C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800390: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800394: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800398: jal         0x800C3730
    // 0x8080039C: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    func_800C3730(rdram, ctx);
        goto after_10;
    // 0x8080039C: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    after_10:
    // 0x808003A0: jal         0x800C3BDC
    // 0x808003A4: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    func_800C3BDC(rdram, ctx);
        goto after_11;
    // 0x808003A4: lbu         $a0, 0x160($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X160);
    after_11:
    // 0x808003A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

;}
RECOMP_FUNC void func_80802AD4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802AD4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802AD8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802ADC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802AE0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80802AE4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80802AE8: jal         0x80106790
    // 0x80802AEC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802AEC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80802AF0: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80802AF4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80802AF8: addiu       $a2, $a2, 0x7DB0
    ctx->r6 = ADD32(ctx->r6, 0X7DB0);
    // 0x80802AFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802B00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802B04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80802B08: jal         0x80087CB8
    // 0x80802B0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    _gcnewoption_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80802B0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
    // 0x80802B10: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80802B14: jal         0x80100094
    // 0x80802B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80802B18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80802B1C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802B20: jal         0x80087DB8
    // 0x80802B24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcnewoption_entrypoint_36(rdram, ctx);
        goto after_3;
    // 0x80802B24: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80802B28: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80802B2C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80802B30: bgtzl       $v0, L_80802B40
    if (SIGNED(ctx->r2) > 0) {
        // 0x80802B34: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80802B40;
    }
    goto skip_0;
    // 0x80802B34: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    skip_0:
    // 0x80802B38: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80802B3C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_80802B40:
    // 0x80802B40: beq         $at, $zero, L_80802B50
    if (ctx->r1 == 0) {
        // 0x80802B44: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80802B50;
    }
    // 0x80802B44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802B48: b           L_80802B50
    // 0x80802B4C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
        goto L_80802B50;
    // 0x80802B4C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_80802B50:
    // 0x80802B50: jal         0x80087CD8
    // 0x80802B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80802B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80802B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B5C: jal         0x80087CE0
    // 0x80802B60: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80802B60: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x80802B64: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80802B68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80802B6C: beq         $t6, $zero, L_80802B7C
    if (ctx->r14 == 0) {
        // 0x80802B70: nop
    
            goto L_80802B7C;
    }
    // 0x80802B70: nop

    // 0x80802B74: b           L_80802B7C
    // 0x80802B78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80802B7C;
    // 0x80802B78: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80802B7C:
    // 0x80802B7C: jal         0x80087CE8
    // 0x80802B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80802B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802B84: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7CC4) << 16);
    // 0x80802B88: lwc1        $f4, 0x7CC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7CC4));
    // 0x80802B8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802B90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B98: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x80802B9C: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80802BA0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80802BA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80802BA8: jal         0x80087DD8
    // 0x80802BAC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_7;
    // 0x80802BAC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x80802BB0: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80802BB4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80802BB8: jal         0x80087DE8
    // 0x80802BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_42(rdram, ctx);
        goto after_8;
    // 0x80802BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80802BC0: jal         0x80087CF0
    // 0x80802BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80802BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80802BC8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80802BCC: jal         0x80101FDC
    // 0x80802BD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x80802BD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80802BD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80802BD8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802BDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80802BE0: jr          $ra
    // 0x80802BE4: nop

    return;
    // 0x80802BE4: nop

;}
RECOMP_FUNC void func_808019CC_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808019D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808019D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808019D8: jal         0x8008A4C0
    // 0x808019DC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    _subaddieDll_entrypoint_6(rdram, ctx);
        goto after_0;
    // 0x808019DC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x808019E0: beq         $v0, $zero, L_808019F0
    if (ctx->r2 == 0) {
        // 0x808019E4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808019F0;
    }
    // 0x808019E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808019E8: jal         0x80108B04
    // 0x808019EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80108B04(rdram, ctx);
        goto after_1;
    // 0x808019EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_808019F0:
    // 0x808019F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808019F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808019F8: jr          $ra
    // 0x808019FC: nop

    return;
    // 0x808019FC: nop

;}
RECOMP_FUNC void func_808008A8_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008B0: jal         0x8080064C
    // 0x808008B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexlarge_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808008B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808008B8: jal         0x80082FF0
    // 0x808008BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808008BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808008C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008C8: jr          $ra
    // 0x808008CC: nop

    return;
    // 0x808008CC: nop

;}
RECOMP_FUNC void func_800DF3E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF3E0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DF3E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF3E8: addiu       $v0, $v0, -0x36C0
    ctx->r2 = ADD32(ctx->r2, -0X36C0);
    // 0x800DF3EC: addiu       $v1, $v1, -0x37B0
    ctx->r3 = ADD32(ctx->r3, -0X37B0);
L_800DF3F0:
    // 0x800DF3F0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800DF3F4: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x800DF3F8: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x800DF3FC: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x800DF400: bne         $v1, $v0, L_800DF3F0
    if (ctx->r3 != ctx->r2) {
        // 0x800DF404: sw          $zero, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = 0;
            goto L_800DF3F0;
    }
    // 0x800DF404: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x800DF408: jr          $ra
    // 0x800DF40C: nop

    return;
    // 0x800DF40C: nop

;}
RECOMP_FUNC void func_80800000_gcskyDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2630, 0X510) << 16);
    // 0x80800004: addiu       $v1, $v0, 0x510
    ctx->r3 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2630, 0X510));
    // 0x80800008: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x8080000C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2630, 0X510) << 16);
    // 0x80800010: addiu       $t7, $t7, 0x510
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2630, 0X510));
    // 0x80800014: beql        $t6, $zero, L_80800044
    if (ctx->r14 == 0) {
        // 0x80800018: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80800044;
    }
    goto skip_0;
    // 0x80800018: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x8080001C: lh          $v0, 0x0($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X0);
L_80800020:
    // 0x80800020: bnel        $a0, $v0, L_80800034
    if (ctx->r4 != ctx->r2) {
        // 0x80800024: lh          $v0, 0x24($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X24);
            goto L_80800034;
    }
    goto skip_1;
    // 0x80800024: lh          $v0, 0x24($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X24);
    skip_1:
    // 0x80800028: jr          $ra
    // 0x8080002C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8080002C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800030: lh          $v0, 0x24($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X24);
L_80800034:
    // 0x80800034: addiu       $v1, $v1, 0x24
    ctx->r3 = ADD32(ctx->r3, 0X24);
    // 0x80800038: bne         $v0, $zero, L_80800020
    if (ctx->r2 != 0) {
        // 0x8080003C: nop
    
            goto L_80800020;
    }
    // 0x8080003C: nop

    // 0x80800040: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800044:
    // 0x80800044: jr          $ra
    // 0x80800048: nop

    return;
    // 0x80800048: nop

;}
RECOMP_FUNC void func_808002E8_chhellterskelter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: jr          $ra
    // 0x808002EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808002EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800D5B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5B24: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D5B28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D5B2C: jr          $ra
    // 0x800D5B30: sb          $t6, -0x481A($at)
    MEM_B(-0X481A, ctx->r1) = ctx->r14;
    return;
    // 0x800D5B30: sb          $t6, -0x481A($at)
    MEM_B(-0X481A, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void _dbskeleton_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A10: syscall     649
    recomp_syscall_handler(rdram, ctx, 0x80087A10);
    return;
    // 0x80087A14: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chwitchytents_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800034: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(816, 0X50) << 16);
    // 0x80800038: jr          $ra
    // 0x8080003C: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(816, 0X50));
    return;
    // 0x8080003C: addiu       $v0, $v0, 0x50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(816, 0X50));
;}
RECOMP_FUNC void func_80800000_chsmalltrexdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_80800000_chsmalltrexdoor");
    // 0x80800000: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x800F54E4
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: jal         0x800F5410
    // 0x80800018: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_1;
    // 0x80800018: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080001C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80800020: bnel        $v0, $at, L_80800080
    if (ctx->r2 != ctx->r1) {
        // 0x80800024: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80800080;
    }
    goto skip_0;
    // 0x80800024: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80800028: jal         0x800F54E4
    // 0x8080002C: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x8080002C: nop

    after_2:
    // 0x80800030: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800034: jal         0x800F5A00
    // 0x80800038: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_800F5A00(rdram, ctx);
        goto after_3;
    // 0x80800038: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_3:
    // 0x8080003C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x80800040: jal         0x800EEAD4
    // 0x80800044: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EEAD4(rdram, ctx);
        goto after_4;
    // 0x80800044: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_4:
    // 0x80800048: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8080004C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800050: nop

    // 0x80800054: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800058: nop

    // 0x8080005C: bc1fl       L_80800080
    if (!c1cs) {
        // 0x80800060: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_80800080;
    }
    goto skip_1;
    // 0x80800060: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x80800064: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800070: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80800074: jal         0x80101FDC
    // 0x80800078: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800078: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_5:
    // 0x8080007C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
L_80800080:
    // 0x80800080: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800084: jal         0x800EE7F8
    // 0x80800088: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800088: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_6:
    // 0x8080008C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800090: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800094: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800098: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080009C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x808000A0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x808000A4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x808000A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808000AC: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x808000B0: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808000B4: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x808000B8: jal         0x800BEF00
    // 0x808000BC: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    func_800BEF00(rdram, ctx);
        goto after_7;
    // 0x808000BC: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    after_7:
    // 0x808000C0: jal         0x80103EAC
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_8;
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808000C8: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x808000CC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808000D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000D4: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x808000D8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808000DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808000E0: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x808000E4: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x808000E8: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808000EC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x808000F0: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x808000F4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808000F8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808000FC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80800100: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800104: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800108: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800110: jal         0x80086890
    // 0x80800114: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _chdoormake_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800114: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_9:
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: jal         0x800868A8
    // 0x80800120: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_10;
    // 0x80800120: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_10:
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800128: jal         0x800868B0
    // 0x8080012C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_11;
    // 0x8080012C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_11:
    // 0x80800130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800134: jal         0x800868C0
    // 0x80800138: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_12;
    // 0x80800138: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_12:
    // 0x8080013C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800140: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800144: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800148: jr          $ra
    // 0x8080014C: nop

    return;
    // 0x8080014C: nop

;}
RECOMP_FUNC void func_8010279C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010279C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801027A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801027A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801027A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801027AC: jal         0x800136E4
    // 0x801027B0: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x801027B0: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    after_0:
    // 0x801027B4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x801027B8: swc1        $f0, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f0.u32l;
    // 0x801027BC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x801027C0: jal         0x800136E4
    // 0x801027C4: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x801027C4: lwc1        $f12, 0x4($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X4);
    after_1:
    // 0x801027C8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x801027CC: swc1        $f0, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->f0.u32l;
    // 0x801027D0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801027D4: jal         0x800136E4
    // 0x801027D8: lwc1        $f12, 0x8($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X8);
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x801027D8: lwc1        $f12, 0x8($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X8);
    after_2:
    // 0x801027DC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x801027E0: swc1        $f0, 0x4C($t1)
    MEM_W(0X4C, ctx->r9) = ctx->f0.u32l;
    // 0x801027E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801027E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801027EC: jr          $ra
    // 0x801027F0: nop

    return;
    // 0x801027F0: nop

;}
RECOMP_FUNC void func_80801244_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801244: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80801248: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8080124C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80801250: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80801254: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80801258: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8080125C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80801260: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80801264: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80801268: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080126C: jal         0x80100094
    // 0x80801270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801270: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801274: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80801278: lbu         $t6, 0x14($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X14);
    // 0x8080127C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801280: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801284: beq         $t6, $zero, L_808012FC
    if (ctx->r14 == 0) {
        // 0x80801288: addiu       $s2, $v0, 0xC
        ctx->r18 = ADD32(ctx->r2, 0XC);
            goto L_808012FC;
    }
    // 0x80801288: addiu       $s2, $v0, 0xC
    ctx->r18 = ADD32(ctx->r2, 0XC);
    // 0x8080128C: addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // 0x80801290: addiu       $s4, $sp, 0x54
    ctx->r20 = ADD32(ctx->r29, 0X54);
    // 0x80801294: addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
L_80801298:
    // 0x80801298: jal         0x8008A040
    // 0x8080129C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x8080129C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x808012A0: bne         $v0, $zero, L_808012DC
    if (ctx->r2 != 0) {
        // 0x808012A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808012DC;
    }
    // 0x808012A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012A8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808012AC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x808012B0: jal         0x808016E8
    // 0x808012B4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_808016E8_chpotogoldgame(rdram, ctx);
        goto after_2;
    // 0x808012B4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_2:
    // 0x808012B8: beq         $v0, $zero, L_808012DC
    if (ctx->r2 == 0) {
        // 0x808012BC: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_808012DC;
    }
    // 0x808012BC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x808012C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808012C4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808012C8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x808012CC: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x808012D0: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x808012D4: jal         0x808013BC
    // 0x808012D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_808013BC_chpotogoldgame(rdram, ctx);
        goto after_3;
    // 0x808012D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_3:
L_808012DC:
    // 0x808012DC: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x808012E0: slti        $at, $s1, 0xF0
    ctx->r1 = SIGNED(ctx->r17) < 0XF0 ? 1 : 0;
    // 0x808012E4: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x808012E8: beq         $at, $zero, L_808012FC
    if (ctx->r1 == 0) {
        // 0x808012EC: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_808012FC;
    }
    // 0x808012EC: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x808012F0: lbu         $t8, 0x14($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X14);
    // 0x808012F4: bne         $t8, $zero, L_80801298
    if (ctx->r24 != 0) {
        // 0x808012F8: nop
    
            goto L_80801298;
    }
    // 0x808012F8: nop

L_808012FC:
    // 0x808012FC: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    // 0x80801300: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x80801304: jal         0x80089C40
    // 0x80801308: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    _subaddiefind_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80801308: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_4:
    // 0x8080130C: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80801310: blez        $v0, L_80801364
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80801314: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80801364;
    }
    // 0x80801314: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80801318: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x8080131C: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // 0x80801320: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80801324: addiu       $s3, $s0, 0xC
    ctx->r19 = ADD32(ctx->r16, 0XC);
L_80801328:
    // 0x80801328: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8080132C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801330: jal         0x800EE7F8
    // 0x80801334: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x80801334: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_5:
    // 0x80801338: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8080133C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801340: jal         0x8008A028
    // 0x80801344: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x80801344: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    after_6:
    // 0x80801348: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080134C: slt         $at, $s1, $s5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80801350: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80801354: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80801358: addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // 0x8080135C: bne         $at, $zero, L_80801328
    if (ctx->r1 != 0) {
        // 0x80801360: sb          $s4, -0x4($s0)
        MEM_B(-0X4, ctx->r16) = ctx->r20;
            goto L_80801328;
    }
    // 0x80801360: sb          $s4, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r20;
L_80801364:
    // 0x80801364: slti        $at, $s1, 0xA
    ctx->r1 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x80801368: beq         $at, $zero, L_80801394
    if (ctx->r1 == 0) {
        // 0x8080136C: lw          $t0, 0x5C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X5C);
            goto L_80801394;
    }
    // 0x8080136C: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80801370: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80801374: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x80801378: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8080137C: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
L_80801380:
    // 0x80801380: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80801384: slti        $at, $s1, 0xA
    ctx->r1 = SIGNED(ctx->r17) < 0XA ? 1 : 0;
    // 0x80801388: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x8080138C: bne         $at, $zero, L_80801380
    if (ctx->r1 != 0) {
        // 0x80801390: sb          $zero, -0x4($s0)
        MEM_B(-0X4, ctx->r16) = 0;
            goto L_80801380;
    }
    // 0x80801390: sb          $zero, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = 0;
L_80801394:
    // 0x80801394: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80801398: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080139C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808013A0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808013A4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808013A8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808013AC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x808013B0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x808013B4: jr          $ra
    // 0x808013B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x808013B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800F5E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5E7C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5E80: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5E84: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5E88: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F5E8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F5E90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5E94: jal         0x80096544
    // 0x800F5E98: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80096544(rdram, ctx);
        goto after_0;
    // 0x800F5E98: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F5E9C: beq         $v0, $zero, L_800F5EB4
    if (ctx->r2 == 0) {
        // 0x800F5EA0: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F5EB4;
    }
    // 0x800F5EA0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F5EA4: jal         0x800964DC
    // 0x800F5EA8: nop

    func_800964DC(rdram, ctx);
        goto after_1;
    // 0x800F5EA8: nop

    after_1:
    // 0x800F5EAC: b           L_800F5EC0
    // 0x800F5EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F5EC0;
    // 0x800F5EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F5EB4:
    // 0x800F5EB4: jal         0x8009C150
    // 0x800F5EB8: nop

    func_8009C150(rdram, ctx);
        goto after_2;
    // 0x800F5EB8: nop

    after_2:
    // 0x800F5EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F5EC0:
    // 0x800F5EC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F5EC4: jr          $ra
    // 0x800F5EC8: nop

    return;
    // 0x800F5EC8: nop

;}
RECOMP_FUNC void bsbwhirl_entrypoint_22(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DB4: jal         0x80082FF0
    // 0x80800DB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800DB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800DBC: jal         0x8080017C
    // 0x80800DC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080017C_bsbwhirl(rdram, ctx);
        goto after_1;
    // 0x80800DC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DCC: jr          $ra
    // 0x80800DD0: nop

    return;
    // 0x80800DD0: nop

;}
RECOMP_FUNC void func_800D3948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3948: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D394C: lbu         $v0, -0x4C0E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X4C0E);
    // 0x800D3950: xori        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 ^ 0X3;
    // 0x800D3954: jr          $ra
    // 0x800D3958: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    return;
    // 0x800D3958: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void _bskazstilt_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083720: syscall     71
    recomp_syscall_handler(rdram, ctx, 0x80083720);
    return;
    // 0x80083724: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void func_80800200_changlerbossbubble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800204: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800208: addiu       $at, $zero, 0x2C
    ctx->r1 = ADD32(0, 0X2C);
    // 0x8080020C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800210: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800214: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800218: beq         $a1, $at, L_80800234
    if (ctx->r5 == ctx->r1) {
        // 0x8080021C: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_80800234;
    }
    // 0x8080021C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800220: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80800224: beq         $a1, $at, L_80800244
    if (ctx->r5 == ctx->r1) {
        // 0x80800228: lw          $s1, 0x28($sp)
        ctx->r17 = MEM_W(ctx->r29, 0X28);
            goto L_80800244;
    }
    // 0x80800228: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8080022C: b           L_80800320
    // 0x80800230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800320;
    // 0x80800230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800234:
    // 0x80800234: jal         0x80800334
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800334_changlerbossbubble(rdram, ctx);
        goto after_0;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8080023C: b           L_80800320
    // 0x80800240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800320;
    // 0x80800240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800244:
    // 0x80800244: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x80800248: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x8080024C: bne         $t7, $zero, L_80800304
    if (ctx->r15 != 0) {
        // 0x80800250: nop
    
            goto L_80800304;
    }
    // 0x80800250: nop

    // 0x80800254: lhu         $a0, 0x1A($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X1A);
    // 0x80800258: srl         $t8, $a0, 5
    ctx->r24 = S32(U32(ctx->r4) >> 5);
    // 0x8080025C: jal         0x80800194
    // 0x80800260: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80800194_changlerbossbubble(rdram, ctx);
        goto after_1;
    // 0x80800260: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x80800264: beq         $v0, $zero, L_80800304
    if (ctx->r2 == 0) {
        // 0x80800268: nop
    
            goto L_80800304;
    }
    // 0x80800268: nop

    // 0x8080026C: lhu         $a0, 0x1A($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X1A);
    // 0x80800270: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x80800274: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80800278: srl         $t9, $a0, 5
    ctx->r25 = S32(U32(ctx->r4) >> 5);
    // 0x8080027C: jal         0x800F7BC8
    // 0x80800280: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800F7BC8(rdram, ctx);
        goto after_2;
    // 0x80800280: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_2:
    // 0x80800284: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800288: bne         $v0, $at, L_80800304
    if (ctx->r2 != ctx->r1) {
        // 0x8080028C: nop
    
            goto L_80800304;
    }
    // 0x8080028C: nop

    // 0x80800290: jal         0x8010A570
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080029C: jal         0x80101FDC
    // 0x808002A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_4;
    // 0x808002A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x808002A4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808002A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808002AC: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    // 0x808002B0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002B4: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x808002B8: lhu         $t0, 0x1A($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X1A);
    // 0x808002BC: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x808002C0: srl         $t2, $t0, 5
    ctx->r10 = S32(U32(ctx->r8) >> 5);
    // 0x808002C4: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x808002C8: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x808002CC: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
    // 0x808002D0: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x808002D4: andi        $t7, $a0, 0x1FF
    ctx->r15 = ctx->r4 & 0X1FF;
    // 0x808002D8: jal         0x800F5BF0
    // 0x808002DC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800F5BF0(rdram, ctx);
        goto after_5;
    // 0x808002DC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_5:
    // 0x808002E0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1340, 0X5B0) << 16);
    // 0x808002E4: lwc1        $f6, 0x5B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1340, 0X5B0));
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002EC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808002F0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808002F4: jal         0x80102FDC
    // 0x808002F8: nop

    func_80102FDC(rdram, ctx);
        goto after_6;
    // 0x808002F8: nop

    after_6:
    // 0x808002FC: b           L_80800320
    // 0x80800300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800320;
    // 0x80800300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800304:
    // 0x80800304: jal         0x80800334
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800334_changlerbossbubble(rdram, ctx);
        goto after_7;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080030C: b           L_80800320
    // 0x80800310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800320;
    // 0x80800310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800314: b           L_80800320
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800320;
    // 0x80800318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080031C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800320:
    // 0x80800320: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800324: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800328: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8080032C: jr          $ra
    // 0x80800330: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800330: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void gspropmarker_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808001F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808001F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808001FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800200: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80800204: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80800208: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8080020C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800210: beq         $a0, $zero, L_8080030C
    if (ctx->r4 == 0) {
        // 0x80800214: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8080030C;
    }
    // 0x80800214: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80800218: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080021C: jal         0x800E9DC4
    // 0x80800220: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    func_800E9DC4(rdram, ctx);
        goto after_0;
    // 0x80800220: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    after_0:
    // 0x80800224: beq         $v0, $zero, L_8080030C
    if (ctx->r2 == 0) {
        // 0x80800228: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_8080030C;
    }
    // 0x80800228: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8080022C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800230: jal         0x800E9D68
    // 0x80800234: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_800E9D68(rdram, ctx);
        goto after_1;
    // 0x80800234: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80800238: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080023C: jal         0x800E9D90
    // 0x80800240: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_800E9D90(rdram, ctx);
        goto after_2;
    // 0x80800240: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800244: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800248: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8080024C: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x80800250: beql        $at, $zero, L_80800310
    if (ctx->r1 == 0) {
        // 0x80800254: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800310;
    }
    goto skip_0;
    // 0x80800254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800258: blez        $s0, L_8080030C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8080025C: addiu       $t2, $zero, 0xC
        ctx->r10 = ADD32(0, 0XC);
            goto L_8080030C;
    }
    // 0x8080025C: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80800260: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80800264: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800268: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080026C: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
L_80800270:
    // 0x80800270: andi        $a0, $v1, 0x1
    ctx->r4 = ctx->r3 & 0X1;
    // 0x80800274: beq         $a2, $a0, L_80800290
    if (ctx->r6 == ctx->r4) {
        // 0x80800278: sll         $t8, $v1, 25
        ctx->r24 = S32(ctx->r3 << 25);
            goto L_80800290;
    }
    // 0x80800278: sll         $t8, $v1, 25
    ctx->r24 = S32(ctx->r3 << 25);
    // 0x8080027C: bnel        $a0, $zero, L_808002F8
    if (ctx->r4 != 0) {
        // 0x80800280: addiu       $a1, $a1, 0x14
        ctx->r5 = ADD32(ctx->r5, 0X14);
            goto L_808002F8;
    }
    goto skip_1;
    // 0x80800280: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    skip_1:
    // 0x80800284: lbu         $t6, 0x12($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X12);
    // 0x80800288: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8080028C: bne         $a3, $t7, L_808002F4
    if (ctx->r7 != ctx->r15) {
        // 0x80800290: srl         $t9, $t8, 26
        ctx->r25 = S32(U32(ctx->r24) >> 26);
            goto L_808002F4;
    }
L_80800290:
    // 0x80800290: srl         $t9, $t8, 26
    ctx->r25 = S32(U32(ctx->r24) >> 26);
    // 0x80800294: bnel        $t1, $t9, L_808002F8
    if (ctx->r9 != ctx->r25) {
        // 0x80800298: addiu       $a1, $a1, 0x14
        ctx->r5 = ADD32(ctx->r5, 0X14);
            goto L_808002F8;
    }
    goto skip_2;
    // 0x80800298: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    skip_2:
    // 0x8080029C: lhu         $t3, 0x8($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X8);
    // 0x808002A0: bnel        $s1, $t3, L_808002F8
    if (ctx->r17 != ctx->r11) {
        // 0x808002A4: addiu       $a1, $a1, 0x14
        ctx->r5 = ADD32(ctx->r5, 0X14);
            goto L_808002F8;
    }
    goto skip_3;
    // 0x808002A4: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    skip_3:
    // 0x808002A8: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808002AC: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x808002B0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x808002B4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x808002B8: nop

    // 0x808002BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808002C0: mflo        $t4
    ctx->r12 = lo;
    // 0x808002C4: addu        $v1, $s2, $t4
    ctx->r3 = ADD32(ctx->r18, ctx->r12);
    // 0x808002C8: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x808002CC: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x808002D0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x808002D4: nop

    // 0x808002D8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808002DC: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x808002E0: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x808002E4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x808002E8: nop

    // 0x808002EC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808002F0: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
L_808002F4:
    // 0x808002F4: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
L_808002F8:
    // 0x808002F8: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x808002FC: beq         $at, $zero, L_8080030C
    if (ctx->r1 == 0) {
        // 0x80800300: slt         $at, $t0, $s0
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_8080030C;
    }
    // 0x80800300: slt         $at, $t0, $s0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80800304: bnel        $at, $zero, L_80800270
    if (ctx->r1 != 0) {
        // 0x80800308: lw          $v1, 0x4($a1)
        ctx->r3 = MEM_W(ctx->r5, 0X4);
            goto L_80800270;
    }
    goto skip_4;
    // 0x80800308: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    skip_4:
L_8080030C:
    // 0x8080030C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800310:
    // 0x80800310: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800314: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800318: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8080031C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800320: jr          $ra
    // 0x80800324: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x80800324: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void _ncpod_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089550: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x80089550);
    return;
    // 0x80089554: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_800C3F48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3F48: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800C3F4C: srl         $t7, $t6, 21
    ctx->r15 = S32(U32(ctx->r14) >> 21);
    // 0x800C3F50: andi        $t8, $t7, 0x7FF
    ctx->r24 = ctx->r15 & 0X7FF;
    // 0x800C3F54: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800C3F58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C3F5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C3F60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3F64: andi        $a0, $a0, 0x7FF
    ctx->r4 = ctx->r4 & 0X7FF;
    // 0x800C3F68: bgez        $t8, L_800C3F80
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C3F6C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C3F80;
    }
    // 0x800C3F6C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C3F70: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C3F74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C3F78: nop

    // 0x800C3F7C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800C3F80:
    // 0x800C3F80: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800C3F84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C3F88: srl         $a2, $t6, 6
    ctx->r6 = S32(U32(ctx->r14) >> 6);
    // 0x800C3F8C: andi        $t9, $a2, 0x7FE0
    ctx->r25 = ctx->r6 & 0X7FE0;
    // 0x800C3F90: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C3F94: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800C3F98: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C3F9C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C3FA0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C3FA4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800C3FA8: jal         0x800C2840
    // 0x800C3FAC: nop

    func_800C2840(rdram, ctx);
        goto after_0;
    // 0x800C3FAC: nop

    after_0:
    // 0x800C3FB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3FB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3FB8: jr          $ra
    // 0x800C3FBC: nop

    return;
    // 0x800C3FBC: nop

;}
RECOMP_FUNC void func_808000D4_bashoes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000E0: jal         0x80084420
    // 0x808000E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _baalarm_free(rdram, ctx);
        goto after_0;
    // 0x808000E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000EC: jal         0x800A0DB8
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0DB8(rdram, ctx);
        goto after_1;
    // 0x808000F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000F4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F8: beql        $t6, $zero, L_8080011C
    if (ctx->r14 == 0) {
        // 0x808000FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080011C;
    }
    goto skip_0;
    // 0x808000FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800100: jal         0x800C77DC
    // 0x80800104: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C77DC(rdram, ctx);
        goto after_2;
    // 0x80800104: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080010C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800110: jal         0x800917A8
    // 0x80800114: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    bastatetimer_set(rdram, ctx);
        goto after_3;
    // 0x80800114: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_3:
    // 0x80800118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080011C:
    // 0x8080011C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800120: jr          $ra
    // 0x80800124: nop

    return;
    // 0x80800124: nop

;}
RECOMP_FUNC void mlMtxRotYaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018FE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80018FEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80018FF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018FF4: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x80018FF8: nop

    // 0x80018FFC: bc1tl       L_80019070
    if (c1cs) {
        // 0x80019000: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80019070;
    }
    goto skip_0;
    // 0x80019000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80019004: jal         0x800137F4
    // 0x80019008: nop

    func_800137F4(rdram, ctx);
        goto after_0;
    // 0x80019008: nop

    after_0:
    // 0x8001900C: jal         0x80013788
    // 0x80019010: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80013788(rdram, ctx);
        goto after_1;
    // 0x80019010: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80019014: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80019018: lw          $v0, -0x4350($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X4350);
    // 0x8001901C: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80019020: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80019024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019028: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
L_8001902C:
    // 0x8001902C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80019030: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80019034: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80019038: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8001903C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80019040: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80019044: mul.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80019048: nop

    // 0x8001904C: mul.s       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80019050: nop

    // 0x80019054: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80019058: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001905C: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80019060: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80019064: bne         $a0, $a1, L_8001902C
    if (ctx->r4 != ctx->r5) {
        // 0x80019068: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_8001902C;
    }
    // 0x80019068: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8001906C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80019070:
    // 0x80019070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80019074: jr          $ra
    // 0x80019078: nop

    return;
    // 0x80019078: nop

;}
