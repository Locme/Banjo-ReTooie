#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void _ncbafly_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892D8: syscall     771
    recomp_syscall_handler(rdram, ctx, 0x800892D8);
    return;
    // 0x800892DC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bskazjump_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A08: jal         0x8008E95C
    // 0x80800A0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E95C(rdram, ctx);
        goto after_0;
    // 0x80800A0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800A10: jal         0x800832E8
    // 0x80800A14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bskaz_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800A14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A20: jr          $ra
    // 0x80800A24: nop

    return;
    // 0x80800A24: nop

;}
RECOMP_FUNC void gcgoto_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001C4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x808001C8: jal         0x8080011C
    // 0x808001CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080011C_gcgoto(rdram, ctx);
        goto after_0;
    // 0x808001CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808001D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001D8: jr          $ra
    // 0x808001DC: nop

    return;
    // 0x808001DC: nop

;}
RECOMP_FUNC void func_8080221C_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080221C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802220: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802224: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80802228: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080222C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80802230: lw          $a2, 0x3C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X3C);
    // 0x80802234: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802238: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080223C: bne         $a2, $zero, L_80802260
    if (ctx->r6 != 0) {
        // 0x80802240: addiu       $a1, $zero, 0x321
        ctx->r5 = ADD32(0, 0X321);
            goto L_80802260;
    }
    // 0x80802240: addiu       $a1, $zero, 0x321
    ctx->r5 = ADD32(0, 0X321);
    // 0x80802244: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80802248: jal         0x80089C20
    // 0x8080224C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x8080224C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80802250: beql        $v0, $zero, L_808022AC
    if (ctx->r2 == 0) {
        // 0x80802254: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808022AC;
    }
    goto skip_0;
    // 0x80802254: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80802258: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8080225C: sw          $a2, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r6;
L_80802260:
    // 0x80802260: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x80802264: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80802268: jal         0x80106790
    // 0x8080226C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x8080226C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80802270: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80802274: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80802278: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080227C: beq         $t8, $zero, L_80802294
    if (ctx->r24 == 0) {
        // 0x80802280: nop
    
            goto L_80802294;
    }
    // 0x80802280: nop

    // 0x80802284: jal         0x800860C0
    // 0x80802288: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    _chboilerid_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80802288: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x8080228C: b           L_808022A0
    // 0x80802290: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
        goto L_808022A0;
    // 0x80802290: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
L_80802294:
    // 0x80802294: jal         0x800860B8
    // 0x80802298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _chboilerid_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80802298: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080229C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
L_808022A0:
    // 0x808022A0: jal         0x800EE7F8
    // 0x808022A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808022A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x808022A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808022AC:
    // 0x808022AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808022B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808022B4: jr          $ra
    // 0x808022B8: nop

    return;
    // 0x808022B8: nop

;}
RECOMP_FUNC void func_80800D90_chcoderoombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D98: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800D9C: jal         0x80100094
    // 0x80800DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DA4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800DAC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800DB0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800DB4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800DB8: addu        $a0, $v0, $t7
    ctx->r4 = ADD32(ctx->r2, ctx->r15);
    // 0x80800DBC: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x80800DC0: beql        $v1, $zero, L_80800E0C
    if (ctx->r3 == 0) {
        // 0x80800DC4: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_80800E0C;
    }
    goto skip_0;
    // 0x80800DC4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_0:
    // 0x80800DC8: beq         $v1, $a1, L_80800E18
    if (ctx->r3 == ctx->r5) {
        // 0x80800DCC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800E18;
    }
    // 0x80800DCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DD0: beq         $v1, $at, L_80800E18
    if (ctx->r3 == ctx->r1) {
        // 0x80800DD4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800E18;
    }
    // 0x80800DD4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800DD8: bne         $v1, $at, L_80800E18
    if (ctx->r3 != ctx->r1) {
        // 0x80800DDC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1172, 0X115C) << 16);
            goto L_80800E18;
    }
    // 0x80800DDC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1172, 0X115C) << 16);
    // 0x80800DE0: lwc1        $f2, 0x115C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1172, 0X115C));
    // 0x80800DE4: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80800DE8: sw          $a1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r5;
    // 0x80800DEC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1172, 0X1160) << 16);
    // 0x80800DF0: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80800DF4: lwc1        $f8, 0x1160($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1172, 0X1160));
    // 0x80800DF8: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80800DFC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800E00: b           L_80800E18
    // 0x80800E04: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
        goto L_80800E18;
    // 0x80800E04: swc1        $f10, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f10.u32l;
    // 0x80800E08: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_80800E0C:
    // 0x80800E0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800E10: sw          $a1, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r5;
    // 0x80800E14: swc1        $f16, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f16.u32l;
L_80800E18:
    // 0x80800E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E20: jr          $ra
    // 0x80800E24: nop

    return;
    // 0x80800E24: nop

;}
RECOMP_FUNC void func_8080075C_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080075C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800760: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800764: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800768: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8080076C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800770: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800774: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800778: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080077C: jal         0x80100094
    // 0x80800780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800780: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800784: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800788: jal         0x80088388
    // 0x8080078C: addiu       $s4, $v0, 0x14
    ctx->r20 = ADD32(ctx->r2, 0X14);
    _gcstatusDll_entrypoint_15(rdram, ctx);
        goto after_1;
    // 0x8080078C: addiu       $s4, $v0, 0x14
    ctx->r20 = ADD32(ctx->r2, 0X14);
    after_1:
    // 0x80800790: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80800794: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800798: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8080079C: beq         $v1, $at, L_808007BC
    if (ctx->r3 == ctx->r1) {
        // 0x808007A0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808007BC;
    }
    // 0x808007A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808007A4: beq         $v1, $at, L_808007CC
    if (ctx->r3 == ctx->r1) {
        // 0x808007A8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808007CC;
    }
    // 0x808007A8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808007AC: beql        $v1, $at, L_808007E0
    if (ctx->r3 == ctx->r1) {
        // 0x808007B0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808007E0;
    }
    goto skip_0;
    // 0x808007B0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_0:
    // 0x808007B4: b           L_808007F0
    // 0x808007B8: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
        goto L_808007F0;
    // 0x808007B8: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
L_808007BC:
    // 0x808007BC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x808007C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007C4: b           L_808007EC
    // 0x808007C8: swc1        $f4, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f4.u32l;
        goto L_808007EC;
    // 0x808007C8: swc1        $f4, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f4.u32l;
L_808007CC:
    // 0x808007CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808007D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007D4: b           L_808007EC
    // 0x808007D8: swc1        $f6, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f6.u32l;
        goto L_808007EC;
    // 0x808007D8: swc1        $f6, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f6.u32l;
    // 0x808007DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_808007E0:
    // 0x808007E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007E4: nop

    // 0x808007E8: swc1        $f8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f8.u32l;
L_808007EC:
    // 0x808007EC: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
L_808007F0:
    // 0x808007F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808007F4: jal         0x80089980
    // 0x808007F8: swc1        $f10, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f10.u32l;
    _sumultiscore_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808007F8: swc1        $f10, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f10.u32l;
    after_2:
    // 0x808007FC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800800: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800804: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800808: jal         0x80089988
    // 0x8080080C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x8080080C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80800810: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800814: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800818: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8080081C: jal         0x80089988
    // 0x80800820: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _sumultiscore_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800820: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80800824: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80800828: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080082C: blezl       $t6, L_808008B4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800830: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808008B4;
    }
    goto skip_1;
    // 0x80800830: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
L_80800834:
    // 0x80800834: jal         0x800F53D0
    // 0x80800838: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F53D0(rdram, ctx);
        goto after_5;
    // 0x80800838: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8080083C: bne         $s1, $s5, L_8080086C
    if (ctx->r17 != ctx->r21) {
        // 0x80800840: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8080086C;
    }
    // 0x80800840: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800844: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800848: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080084C: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x80800850: jal         0x80085548
    // 0x80800854: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    _badeathmatch_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80800854: addiu       $a3, $zero, 0x19
    ctx->r7 = ADD32(0, 0X19);
    after_6:
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080085C: jal         0x80085530
    // 0x80800860: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _badeathmatch_entrypoint_7(rdram, ctx);
        goto after_7;
    // 0x80800860: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x80800864: b           L_808008A0
    // 0x80800868: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
        goto L_808008A0;
    // 0x80800868: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
L_8080086C:
    // 0x8080086C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80800870: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x80800874: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80800878: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x8080087C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800880: addu        $s2, $s4, $t7
    ctx->r18 = ADD32(ctx->r20, ctx->r15);
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800888: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080088C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800890: jal         0x80085548
    // 0x80800894: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    _badeathmatch_entrypoint_10(rdram, ctx);
        goto after_8;
    // 0x80800894: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_8:
    // 0x80800898: sb          $zero, 0x86($s2)
    MEM_B(0X86, ctx->r18) = 0;
    // 0x8080089C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
L_808008A0:
    // 0x808008A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808008A4: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x808008A8: bne         $at, $zero, L_80800834
    if (ctx->r1 != 0) {
        // 0x808008AC: nop
    
            goto L_80800834;
    }
    // 0x808008AC: nop

    // 0x808008B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808008B4:
    // 0x808008B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808008B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808008BC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808008C0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808008C4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x808008C8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808008CC: jr          $ra
    // 0x808008D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808008D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808005E4_chquizremotectrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808005E8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808005EC: bne         $a1, $at, L_808005FC
    if (ctx->r5 != ctx->r1) {
        // 0x808005F0: sw          $a2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r6;
            goto L_808005FC;
    }
    // 0x808005F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808005F4: jr          $ra
    // 0x808005F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    return;
    // 0x808005F8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808005FC:
    // 0x808005FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800600: jr          $ra
    // 0x80800604: nop

    return;
    // 0x80800604: nop

;}
RECOMP_FUNC void func_800E1120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1120: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800E1124: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800E1128: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800E112C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E1130: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800E1134: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x800E1138: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E113C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800E1140: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800E1144: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800E1148: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800E114C: jal         0x800EFA4C
    // 0x800E1150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800E1150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800E1154: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800E1158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E115C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E1160: jal         0x800EF8BC
    // 0x800E1164: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    func_800EF8BC(rdram, ctx);
        goto after_1;
    // 0x800E1164: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x800E1168: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800E116C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E1170: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800E1174: jal         0x800EF934
    // 0x800E1178: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    func_800EF934(rdram, ctx);
        goto after_2;
    // 0x800E1178: lw          $a2, 0x4($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X4);
    after_2:
    // 0x800E117C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800E1180: jal         0x800EF04C
    // 0x800E1184: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x800E1184: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x800E1188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800E118C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E1190: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800E1194: jr          $ra
    // 0x800E1198: nop

    return;
    // 0x800E1198: nop

;}
RECOMP_FUNC void _sucoasterhit_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A330: syscall     836
    recomp_syscall_handler(rdram, ctx, 0x8008A330);
    return;
    // 0x8008A334: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800F54F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F54F0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F54F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F54F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F54FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5500: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5504: jal         0x800918F8
    // 0x800F5508: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    bakey_getControllerIndex(rdram, ctx);
        goto after_0;
    // 0x800F5508: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F550C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5514: jr          $ra
    // 0x800F5518: nop

    return;
    // 0x800F5518: nop

;}
RECOMP_FUNC void bsbshock_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x8008CABC
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800018: jal         0x8008AF24
    // 0x8080001C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x8080001C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800020: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800024: jal         0x8008AED4
    // 0x80800028: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800028: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_2:
    // 0x8080002C: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800030: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800034: jal         0x8008B1C8
    // 0x80800038: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8008B1C8(rdram, ctx);
        goto after_3;
    // 0x80800038: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x8080003C: lui         $a1, 0x4086
    ctx->r5 = S32(0X4086 << 16);
    // 0x80800040: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800044: jal         0x8008B1BC
    // 0x80800048: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setDuration(rdram, ctx);
        goto after_4;
    // 0x80800048: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x8080004C: lui         $a2, 0x3DD9
    ctx->r6 = S32(0X3DD9 << 16);
    // 0x80800050: ori         $a2, $a2, 0x4AF5
    ctx->r6 = ctx->r6 | 0X4AF5;
    // 0x80800054: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800058: jal         0x8008B1D4
    // 0x8080005C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    anctrl_setSubrange(rdram, ctx);
        goto after_5;
    // 0x8080005C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_5:
    // 0x80800060: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800064: jal         0x8008B134
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080006C: jal         0x8008B064
    // 0x80800070: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80800070: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_7:
    // 0x80800074: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80800078: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800084: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800088: jal         0x8009FFD8
    // 0x8080008C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_8;
    // 0x8080008C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_8:
    // 0x80800090: jal         0x8009EF04
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_distance(rdram, ctx);
        goto after_9;
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800098: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080009C: nop

    // 0x808000A0: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x808000A4: nop

    // 0x808000A8: bc1t        L_808000C4
    if (c1cs) {
        // 0x808000AC: nop
    
            goto L_808000C4;
    }
    // 0x808000AC: nop

    // 0x808000B0: jal         0x8009EEB8
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getAngleRelativeToBanjo(rdram, ctx);
        goto after_10;
    // 0x808000B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808000B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000BC: jal         0x8009C914
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_11;
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_808000C4:
    // 0x808000C4: jal         0x8009C990
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_12;
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808000CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808000D0: jal         0x8009B9C0
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_13;
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808000D8: jal         0x800841D8
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bswalk_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808000E0: jal         0x8009C990
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_15;
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808000E8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x808000EC: jal         0x8009BB00
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_16;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808000F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000FC: jal         0x8009BA68
    // 0x80800100: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    baphysics_set_horizontal_velocity(rdram, ctx);
        goto after_17;
    // 0x80800100: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_17:
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: jal         0x800A0CE8
    // 0x8080010C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CE8(rdram, ctx);
        goto after_18;
    // 0x8080010C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800114: jal         0x800A0CF4
    // 0x80800118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_19;
    // 0x80800118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x8080011C: jal         0x8009D874
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_20;
    // 0x80800120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800124: jal         0x800C2E04
    // 0x80800128: nop

    func_800C2E04(rdram, ctx);
        goto after_21;
    // 0x80800128: nop

    after_21:
    // 0x8080012C: sb          $v0, 0x164($s0)
    MEM_B(0X164, ctx->r16) = ctx->r2;
    // 0x80800130: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80800134: jal         0x800C3418
    // 0x80800138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C3418(rdram, ctx);
        goto after_22;
    // 0x80800138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x8080013C: jal         0x800C2E40
    // 0x80800140: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    func_800C2E40(rdram, ctx);
        goto after_23;
    // 0x80800140: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    after_23:
    // 0x80800144: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    // 0x80800148: jal         0x800C330C
    // 0x8080014C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_24;
    // 0x8080014C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_24:
    // 0x80800150: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    // 0x80800154: jal         0x800C301C
    // 0x80800158: addiu       $a1, $zero, 0x41D
    ctx->r5 = ADD32(0, 0X41D);
    func_800C301C(rdram, ctx);
        goto after_25;
    // 0x80800158: addiu       $a1, $zero, 0x41D
    ctx->r5 = ADD32(0, 0X41D);
    after_25:
    // 0x8080015C: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x80800160: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800164: lui         $a3, 0xBF99
    ctx->r7 = S32(0XBF99 << 16);
    // 0x80800168: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080016C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800170: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x80800174: jal         0x800C3730
    // 0x80800178: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    func_800C3730(rdram, ctx);
        goto after_26;
    // 0x80800178: lbu         $a0, 0x164($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X164);
    after_26:
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800180: jal         0x80093300
    // 0x80800184: lui         $a1, 0xC2AE
    ctx->r5 = S32(0XC2AE << 16);
    func_80093300(rdram, ctx);
        goto after_27;
    // 0x80800184: lui         $a1, 0xC2AE
    ctx->r5 = S32(0XC2AE << 16);
    after_27:
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080018C: jal         0x8009C1B4
    // 0x80800190: lui         $a1, 0xC2AE
    ctx->r5 = S32(0XC2AE << 16);
    func_8009C1B4(rdram, ctx);
        goto after_28;
    // 0x80800190: lui         $a1, 0xC2AE
    ctx->r5 = S32(0XC2AE << 16);
    after_28:
    // 0x80800194: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800198: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
    // 0x8080019C: sw          $zero, 0x160($s0)
    MEM_W(0X160, ctx->r16) = 0;
    // 0x808001A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808001AC: jr          $ra
    // 0x808001B0: nop

    return;
    // 0x808001B0: nop

;}
RECOMP_FUNC void func_80800000_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: jal         0x808011DC
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808011DC_chpotogoldgame(rdram, ctx);
        goto after_0;
    // 0x80800010: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800014: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x80800018: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    // 0x8080001C: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800020: jal         0x800DA298
    // 0x80800024: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800024: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    after_1:
    // 0x80800028: beq         $v0, $zero, L_80800044
    if (ctx->r2 == 0) {
        // 0x8080002C: addiu       $a0, $zero, 0x49
        ctx->r4 = ADD32(0, 0X49);
            goto L_80800044;
    }
    // 0x8080002C: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: jal         0x80800434
    // 0x80800038: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_2;
    // 0x80800038: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_2:
    // 0x8080003C: b           L_808000EC
    // 0x80800040: nop

        goto L_808000EC;
    // 0x80800040: nop

L_80800044:
    // 0x80800044: jal         0x800D0A9C
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_3;
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8080004C: bne         $v0, $zero, L_80800080
    if (ctx->r2 != 0) {
        // 0x80800050: addiu       $a0, $zero, 0x17
        ctx->r4 = ADD32(0, 0X17);
            goto L_80800080;
    }
    // 0x80800050: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80800054: jal         0x800D0A9C
    // 0x80800058: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_4;
    // 0x80800058: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x8080005C: bnel        $v0, $zero, L_80800084
    if (ctx->r2 != 0) {
        // 0x80800060: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80800084;
    }
    goto skip_0;
    // 0x80800060: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_0:
    // 0x80800064: jal         0x800DA298
    // 0x80800068: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800068: addiu       $a0, $zero, 0x1DB
    ctx->r4 = ADD32(0, 0X1DB);
    after_5:
    // 0x8080006C: bnel        $v0, $zero, L_80800084
    if (ctx->r2 != 0) {
        // 0x80800070: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80800084;
    }
    goto skip_1;
    // 0x80800070: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_1:
    // 0x80800074: jal         0x800D395C
    // 0x80800078: nop

    func_800D395C(rdram, ctx);
        goto after_6;
    // 0x80800078: nop

    after_6:
    // 0x8080007C: beq         $v0, $zero, L_808000D0
    if (ctx->r2 == 0) {
        // 0x80800080: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808000D0;
    }
L_80800080:
    // 0x80800080: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_80800084:
    // 0x80800084: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800088: nop

    // 0x8080008C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800090: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800094: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800098: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x8080009C: jal         0x800D395C
    // 0x808000A0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    func_800D395C(rdram, ctx);
        goto after_7;
    // 0x808000A0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    after_7:
    // 0x808000A4: beq         $v0, $zero, L_808000C0
    if (ctx->r2 == 0) {
        // 0x808000A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000C0;
    }
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x80800434
    // 0x808000B4: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_8;
    // 0x808000B4: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_8:
    // 0x808000B8: b           L_808000EC
    // 0x808000BC: nop

        goto L_808000EC;
    // 0x808000BC: nop

L_808000C0:
    // 0x808000C0: jal         0x80800434
    // 0x808000C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800434_chpotogoldgame(rdram, ctx);
        goto after_9;
    // 0x808000C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x808000C8: b           L_808000EC
    // 0x808000CC: nop

        goto L_808000EC;
    // 0x808000CC: nop

L_808000D0:
    // 0x808000D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000D4: nop

    // 0x808000D8: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x808000DC: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x808000E0: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x808000E4: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x808000E8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_808000EC:
    // 0x808000EC: jal         0x80801A7C
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801A7C_chpotogoldgame(rdram, ctx);
        goto after_10;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808000F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F8: jal         0x80801494
    // 0x808000FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801494_chpotogoldgame(rdram, ctx);
        goto after_11;
    // 0x808000FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80800100: jal         0x80801558
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801558_chpotogoldgame(rdram, ctx);
        goto after_12;
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800108: jal         0x8008A358
    // 0x8080010C: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    _sueggmisc_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x8080010C: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    after_13:
    // 0x80800110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800114: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800118: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080011C: jr          $ra
    // 0x80800120: nop

    return;
    // 0x80800120: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829E0: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x800829E0);
    return;
    // 0x800829E4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _bsrest_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083998: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x80083998);
    return;
    // 0x8008399C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void _gspropctrl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BA8: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088BA8);
    return;
    // 0x80088BAC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80801504_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801504: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80801508: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8080150C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80801510: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801514: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80801518: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8080151C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80801520: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80801524: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80801528: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8080152C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80801530: lui         $s5, 0x86
    ctx->r21 = S32(0X86 << 16);
    // 0x80801534: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80801538: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8080153C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80801540: ori         $s5, $s5, 0x20
    ctx->r21 = ctx->r21 | 0X20;
    // 0x80801544: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801548: addiu       $s1, $a0, 0x64
    ctx->r17 = ADD32(ctx->r4, 0X64);
    // 0x8080154C: addiu       $s2, $a0, 0x58
    ctx->r18 = ADD32(ctx->r4, 0X58);
    // 0x80801550: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // 0x80801554: addiu       $s4, $sp, 0x6C
    ctx->r20 = ADD32(ctx->r29, 0X6C);
    // 0x80801558: addiu       $s6, $zero, 0x6C
    ctx->r22 = ADD32(0, 0X6C);
L_8080155C:
    // 0x8080155C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80801560: jal         0x800EE7F8
    // 0x80801564: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80801564: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80801568: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080156C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80801570: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80801574: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80801578: jal         0x800BF340
    // 0x8080157C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800BF340(rdram, ctx);
        goto after_1;
    // 0x8080157C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80801580: beq         $v0, $zero, L_8080158C
    if (ctx->r2 == 0) {
        // 0x80801584: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_8080158C;
    }
    // 0x80801584: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80801588: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_8080158C:
    // 0x8080158C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80801590: bne         $s0, $s6, L_8080155C
    if (ctx->r16 != ctx->r22) {
        // 0x80801594: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_8080155C;
    }
    // 0x80801594: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80801598: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8080159C: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x808015A0: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x808015A4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808015A8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808015AC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x808015B0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x808015B4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x808015B8: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x808015BC: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x808015C0: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x808015C4: jr          $ra
    // 0x808015C8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x808015C8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void fxripple_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800198: jal         0x80800094
    // 0x8080019C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800094_fxripple(rdram, ctx);
        goto after_0;
    // 0x8080019C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808001A0: beq         $v0, $zero, L_808001B0
    if (ctx->r2 == 0) {
        // 0x808001A4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_808001B0;
    }
    // 0x808001A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001A8: jal         0x800BA22C
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BA22C(rdram, ctx);
        goto after_1;
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_808001B0:
    // 0x808001B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B8: jr          $ra
    // 0x808001BC: nop

    return;
    // 0x808001BC: nop

;}
RECOMP_FUNC void _cadbfunc_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085620: syscall     169
    recomp_syscall_handler(rdram, ctx, 0x80085620);
    return;
    // 0x80085624: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_80801110_choildrill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801110: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801114: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801118: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8080111C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801120: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801124: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80801128: beq         $a1, $at, L_808011FC
    if (ctx->r5 == ctx->r1) {
        // 0x8080112C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_808011FC;
    }
    // 0x8080112C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80801130: addiu       $at, $zero, 0x91
    ctx->r1 = ADD32(0, 0X91);
    // 0x80801134: bnel        $a1, $at, L_80801210
    if (ctx->r5 != ctx->r1) {
        // 0x80801138: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801210;
    }
    goto skip_0;
    // 0x80801138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080113C: jal         0x800F54E4
    // 0x80801140: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80801140: nop

    after_0:
    // 0x80801144: jal         0x800F6B94
    // 0x80801148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6B94(rdram, ctx);
        goto after_1;
    // 0x80801148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080114C: beql        $v0, $zero, L_808011B4
    if (ctx->r2 == 0) {
        // 0x80801150: lw          $t4, 0x74($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X74);
            goto L_808011B4;
    }
    goto skip_1;
    // 0x80801150: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    skip_1:
    // 0x80801154: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80801158: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8080115C: bltz        $t9, L_808011F4
    if (SIGNED(ctx->r25) < 0) {
        // 0x80801160: nop
    
            goto L_808011F4;
    }
    // 0x80801160: nop

    // 0x80801164: jal         0x800DA298
    // 0x80801168: addiu       $a0, $zero, 0x351
    ctx->r4 = ADD32(0, 0X351);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80801168: addiu       $a0, $zero, 0x351
    ctx->r4 = ADD32(0, 0X351);
    after_2:
    // 0x8080116C: bne         $v0, $zero, L_808011F4
    if (ctx->r2 != 0) {
        // 0x80801170: addiu       $a1, $zero, 0x12BE
        ctx->r5 = ADD32(0, 0X12BE);
            goto L_808011F4;
    }
    // 0x80801170: addiu       $a1, $zero, 0x12BE
    ctx->r5 = ADD32(0, 0X12BE);
    // 0x80801174: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801178: addiu       $t0, $zero, 0x6F
    ctx->r8 = ADD32(0, 0X6F);
    // 0x8080117C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801180: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x80801184: jal         0x8008A208
    // 0x80801188: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80801188: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x8080118C: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x80801190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801194: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x80801198: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
    // 0x8080119C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x808011A0: jal         0x80085820
    // 0x808011A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_4;
    // 0x808011A4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x808011A8: b           L_80801220
    // 0x808011AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801220;
    // 0x808011AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808011B0: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
L_808011B4:
    // 0x808011B4: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x808011B8: bltz        $t6, L_808011F4
    if (SIGNED(ctx->r14) < 0) {
        // 0x808011BC: nop
    
            goto L_808011F4;
    }
    // 0x808011BC: nop

    // 0x808011C0: jal         0x800DA298
    // 0x808011C4: addiu       $a0, $zero, 0x351
    ctx->r4 = ADD32(0, 0X351);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808011C4: addiu       $a0, $zero, 0x351
    ctx->r4 = ADD32(0, 0X351);
    after_5:
    // 0x808011C8: bne         $v0, $zero, L_808011F4
    if (ctx->r2 != 0) {
        // 0x808011CC: addiu       $a1, $zero, 0x12BD
        ctx->r5 = ADD32(0, 0X12BD);
            goto L_808011F4;
    }
    // 0x808011CC: addiu       $a1, $zero, 0x12BD
    ctx->r5 = ADD32(0, 0X12BD);
    // 0x808011D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808011D4: addiu       $t7, $zero, 0x6F
    ctx->r15 = ADD32(0, 0X6F);
    // 0x808011D8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808011DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808011E0: jal         0x8008A208
    // 0x808011E4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x808011E4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x808011E8: lbu         $t9, 0x74($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X74);
    // 0x808011EC: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x808011F0: sb          $t0, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r8;
L_808011F4:
    // 0x808011F4: b           L_8080121C
    // 0x808011F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080121C;
    // 0x808011F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808011FC:
    // 0x808011FC: addiu       $a0, $zero, 0x484
    ctx->r4 = ADD32(0, 0X484);
    // 0x80801200: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80801204: jal         0x80101180
    // 0x80801208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80801208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8080120C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80801210:
    // 0x80801210: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801214: jal         0x80085820
    // 0x80801218: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    _chswitch_entrypoint_10(rdram, ctx);
        goto after_8;
    // 0x80801218: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_8:
L_8080121C:
    // 0x8080121C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801220:
    // 0x80801220: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801224: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801228: jr          $ra
    // 0x8080122C: nop

    return;
    // 0x8080122C: nop

;}
RECOMP_FUNC void _gcegg_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883C8: syscall     680
    recomp_syscall_handler(rdram, ctx, 0x800883C8);
    return;
    // 0x800883CC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void boot___ull_div(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002878: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000287C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80002880: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80002884: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80002888: ld          $t7, 0x8($sp)
    ctx->r15 = LD(ctx->r29, 0X8);
    // 0x8000288C: ld          $t6, 0x0($sp)
    ctx->r14 = LD(ctx->r29, 0X0);
    // 0x80002890: ddivu       $zero, $t6, $t7
    DDIVU(U64(ctx->r14), U64(ctx->r15), &lo, &hi);
    // 0x80002894: bne         $t7, $zero, L_800028A0
    if (ctx->r15 != 0) {
        // 0x80002898: nop
    
            goto L_800028A0;
    }
    // 0x80002898: nop

    // 0x8000289C: break       7
    do_break(2147494044);
L_800028A0:
    // 0x800028A0: mflo        $v0
    ctx->r2 = lo;
    // 0x800028A4: dsll32      $v1, $v0, 0
    ctx->r3 = ctx->r2 << (0 + 32);
    // 0x800028A8: dsra32      $v1, $v1, 0
    ctx->r3 = SIGNED(ctx->r3) >> (0 + 32);
    // 0x800028AC: jr          $ra
    // 0x800028B0: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x800028B0: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8009D4D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D4D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009D4DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009D4E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009D4E4: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009D4E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009D4EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009D4F0: sw          $zero, 0x18($t6)
    MEM_W(0X18, ctx->r14) = 0;
    // 0x8009D4F4: lw          $t8, 0x104($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X104);
    // 0x8009D4F8: sb          $t7, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r15;
    // 0x8009D4FC: lw          $t9, 0x104($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X104);
    // 0x8009D500: sw          $zero, 0x8($t9)
    MEM_W(0X8, ctx->r25) = 0;
    // 0x8009D504: lw          $t0, 0x104($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X104);
    // 0x8009D508: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x8009D50C: lw          $t1, 0x104($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X104);
    // 0x8009D510: jal         0x800C2E04
    // 0x8009D514: sw          $zero, 0x10($t1)
    MEM_W(0X10, ctx->r9) = 0;
    func_800C2E04(rdram, ctx);
        goto after_0;
    // 0x8009D514: sw          $zero, 0x10($t1)
    MEM_W(0X10, ctx->r9) = 0;
    after_0:
    // 0x8009D518: lw          $t2, 0x104($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X104);
    // 0x8009D51C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8009D520: sb          $v0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r2;
    // 0x8009D524: lw          $t3, 0x104($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X104);
    // 0x8009D528: jal         0x800C330C
    // 0x8009D52C: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    func_800C330C(rdram, ctx);
        goto after_1;
    // 0x8009D52C: lbu         $a0, 0x0($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X0);
    after_1:
    // 0x8009D530: lw          $t4, 0x104($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X104);
    // 0x8009D534: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D538: jal         0x800C3418
    // 0x8009D53C: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    func_800C3418(rdram, ctx);
        goto after_2;
    // 0x8009D53C: lbu         $a0, 0x0($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X0);
    after_2:
    // 0x8009D540: lw          $t5, 0x104($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X104);
    // 0x8009D544: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D548: jal         0x800C431C
    // 0x8009D54C: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    func_800C431C(rdram, ctx);
        goto after_3;
    // 0x8009D54C: lbu         $a0, 0x0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X0);
    after_3:
    // 0x8009D550: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009D554: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009D558: lw          $t6, 0x104($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X104);
    // 0x8009D55C: swc1        $f4, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f4.u32l;
    // 0x8009D560: lw          $t7, 0x104($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X104);
    // 0x8009D564: jal         0x800C2E04
    // 0x8009D568: sb          $zero, 0x1($t7)
    MEM_B(0X1, ctx->r15) = 0;
    func_800C2E04(rdram, ctx);
        goto after_4;
    // 0x8009D568: sb          $zero, 0x1($t7)
    MEM_B(0X1, ctx->r15) = 0;
    after_4:
    // 0x8009D56C: lw          $t8, 0x104($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X104);
    // 0x8009D570: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D574: sb          $v0, 0x2($t8)
    MEM_B(0X2, ctx->r24) = ctx->r2;
    // 0x8009D578: lw          $t9, 0x104($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X104);
    // 0x8009D57C: jal         0x800C3418
    // 0x8009D580: lbu         $a0, 0x2($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X2);
    func_800C3418(rdram, ctx);
        goto after_5;
    // 0x8009D580: lbu         $a0, 0x2($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X2);
    after_5:
    // 0x8009D584: lw          $t0, 0x104($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X104);
    // 0x8009D588: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D58C: jal         0x800C431C
    // 0x8009D590: lbu         $a0, 0x2($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X2);
    func_800C431C(rdram, ctx);
        goto after_6;
    // 0x8009D590: lbu         $a0, 0x2($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X2);
    after_6:
    // 0x8009D594: jal         0x800C2E04
    // 0x8009D598: nop

    func_800C2E04(rdram, ctx);
        goto after_7;
    // 0x8009D598: nop

    after_7:
    // 0x8009D59C: lw          $t1, 0x104($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X104);
    // 0x8009D5A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D5A4: sb          $v0, 0x3($t1)
    MEM_B(0X3, ctx->r9) = ctx->r2;
    // 0x8009D5A8: lw          $t2, 0x104($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X104);
    // 0x8009D5AC: jal         0x800C3418
    // 0x8009D5B0: lbu         $a0, 0x3($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X3);
    func_800C3418(rdram, ctx);
        goto after_8;
    // 0x8009D5B0: lbu         $a0, 0x3($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X3);
    after_8:
    // 0x8009D5B4: lw          $t3, 0x104($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X104);
    // 0x8009D5B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D5BC: jal         0x800C431C
    // 0x8009D5C0: lbu         $a0, 0x3($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X3);
    func_800C431C(rdram, ctx);
        goto after_9;
    // 0x8009D5C0: lbu         $a0, 0x3($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X3);
    after_9:
    // 0x8009D5C4: lw          $t4, 0x104($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X104);
    // 0x8009D5C8: sb          $zero, 0x4($t4)
    MEM_B(0X4, ctx->r12) = 0;
    // 0x8009D5CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D5D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009D5D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009D5D8: jr          $ra
    // 0x8009D5DC: nop

    return;
    // 0x8009D5DC: nop

;}
RECOMP_FUNC void func_808016B4_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016B4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808016B8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x808016BC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808016C0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x808016C4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x808016C8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x808016CC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x808016D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808016D4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x808016D8: lhu         $t6, 0x76($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X76);
    // 0x808016DC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x808016E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808016E4: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808016E8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808016EC: bgez        $t7, L_80801700
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808016F0: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80801700;
    }
    // 0x808016F0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808016F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808016F8: nop

    // 0x808016FC: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80801700:
    // 0x80801700: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80801704: jal         0x800E3E8C
    // 0x80801708: nop

    func_800E3E8C(rdram, ctx);
        goto after_0;
    // 0x80801708: nop

    after_0:
    // 0x8080170C: beq         $v0, $zero, L_808017DC
    if (ctx->r2 == 0) {
        // 0x80801710: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_808017DC;
    }
    // 0x80801710: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801714: jal         0x80100094
    // 0x80801718: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80801718: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080171C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80801720: jal         0x800D674C
    // 0x80801724: addiu       $a0, $zero, 0x74C
    ctx->r4 = ADD32(0, 0X74C);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x80801724: addiu       $a0, $zero, 0x74C
    ctx->r4 = ADD32(0, 0X74C);
    after_2:
    // 0x80801728: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8080172C: jal         0x800D674C
    // 0x80801730: addiu       $a0, $zero, 0x74D
    ctx->r4 = ADD32(0, 0X74D);
    func_800D674C(rdram, ctx);
        goto after_3;
    // 0x80801730: addiu       $a0, $zero, 0x74D
    ctx->r4 = ADD32(0, 0X74D);
    after_3:
    // 0x80801734: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80801738: jal         0x800D674C
    // 0x8080173C: addiu       $a0, $zero, 0x74E
    ctx->r4 = ADD32(0, 0X74E);
    func_800D674C(rdram, ctx);
        goto after_4;
    // 0x8080173C: addiu       $a0, $zero, 0x74E
    ctx->r4 = ADD32(0, 0X74E);
    after_4:
    // 0x80801740: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80801744: lw          $v1, 0x6C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X6C);
    // 0x80801748: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8080174C: addiu       $s4, $sp, 0x48
    ctx->r20 = ADD32(ctx->r29, 0X48);
    // 0x80801750: andi        $t8, $v1, 0x1FF
    ctx->r24 = ctx->r3 & 0X1FF;
    // 0x80801754: beq         $t8, $zero, L_808017DC
    if (ctx->r24 == 0) {
        // 0x80801758: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_808017DC;
    }
    // 0x80801758: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8080175C: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
L_80801760:
    // 0x80801760: lb          $t9, 0x5C($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X5C);
    // 0x80801764: beql        $s3, $t9, L_808017D0
    if (ctx->r19 == ctx->r25) {
        // 0x80801768: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808017D0;
    }
    goto skip_0;
    // 0x80801768: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8080176C: jal         0x80089C90
    // 0x80801770: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80801770: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80801774: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80801778: beq         $at, $zero, L_80801790
    if (ctx->r1 == 0) {
        // 0x8080177C: nop
    
            goto L_80801790;
    }
    // 0x8080177C: nop

    // 0x80801780: jal         0x80089C90
    // 0x80801784: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80801784: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80801788: jal         0x800DF410
    // 0x8080178C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF410(rdram, ctx);
        goto after_7;
    // 0x8080178C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
L_80801790:
    // 0x80801790: jal         0x800DF830
    // 0x80801794: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_8;
    // 0x80801794: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x80801798: lb          $t0, 0x5D($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X5D);
    // 0x8080179C: lw          $a2, 0x4C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4C);
    // 0x808017A0: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x808017A4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808017A8: addu        $t2, $s4, $t1
    ctx->r10 = ADD32(ctx->r20, ctx->r9);
    // 0x808017AC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x808017B0: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x808017B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808017B8: jal         0x800DE448
    // 0x808017BC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_800DE448(rdram, ctx);
        goto after_9;
    // 0x808017BC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_9:
    // 0x808017C0: lw          $v1, 0x6C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X6C);
    // 0x808017C4: andi        $t4, $v1, 0x1FF
    ctx->r12 = ctx->r3 & 0X1FF;
    // 0x808017C8: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x808017CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808017D0:
    // 0x808017D0: sltu        $at, $s1, $v1
    ctx->r1 = ctx->r17 < ctx->r3 ? 1 : 0;
    // 0x808017D4: bne         $at, $zero, L_80801760
    if (ctx->r1 != 0) {
        // 0x808017D8: addiu       $s0, $s0, 0x60
        ctx->r16 = ADD32(ctx->r16, 0X60);
            goto L_80801760;
    }
    // 0x808017D8: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
L_808017DC:
    // 0x808017DC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808017E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808017E4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x808017E8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x808017EC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x808017F0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x808017F4: jr          $ra
    // 0x808017F8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808017F8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800CA8_baduo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800CAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CB0: jal         0x800A3274
    // 0x80800CB4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x80800CB4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800CB8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800CBC: jal         0x800A3274
    // 0x80800CC0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800A3274(rdram, ctx);
        goto after_1;
    // 0x80800CC0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800CC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800CC8: jal         0x800D5034
    // 0x80800CCC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800D5034(rdram, ctx);
        goto after_2;
    // 0x80800CCC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80800CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CD8: jr          $ra
    // 0x80800CDC: nop

    return;
    // 0x80800CDC: nop

;}
RECOMP_FUNC void _sujiggy_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A730: syscall     849
    recomp_syscall_handler(rdram, ctx, 0x8008A730);
    return;
    // 0x8008A734: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void _ncpod_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800894F8: syscall     783
    recomp_syscall_handler(rdram, ctx, 0x800894F8);
    return;
    // 0x800894FC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_8080085C_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080085C: lui         $at, 0x3EC0
    ctx->r1 = S32(0X3EC0 << 16);
    // 0x80800860: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800864: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800868: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080086C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800870: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800874: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x80800878: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8080087C: jal         0x800D0A9C
    // 0x80800880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_0;
    // 0x80800880: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800884: beq         $v0, $zero, L_808008A4
    if (ctx->r2 == 0) {
        // 0x80800888: nop
    
            goto L_808008A4;
    }
    // 0x80800888: nop

    // 0x8080088C: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800894: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800898: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x8080089C: jal         0x808001CC
    // 0x808008A0: sh          $t7, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r15;
    func_808001CC_chmayafarmer(rdram, ctx);
        goto after_1;
    // 0x808008A0: sh          $t7, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r15;
    after_1:
L_808008A4:
    // 0x808008A4: jal         0x80088848
    // 0x808008A8: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x808008A8: nop

    after_2:
    // 0x808008AC: beql        $v0, $zero, L_808008DC
    if (ctx->r2 == 0) {
        // 0x808008B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808008DC;
    }
    goto skip_0;
    // 0x808008B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808008B4: lhu         $t8, 0x76($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X76);
    // 0x808008B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808008C0: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x808008C4: jal         0x808001CC
    // 0x808008C8: sh          $t9, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r25;
    func_808001CC_chmayafarmer(rdram, ctx);
        goto after_3;
    // 0x808008C8: sh          $t9, 0x76($s0)
    MEM_H(0X76, ctx->r16) = ctx->r25;
    after_3:
    // 0x808008CC: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x808008D0: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x808008D4: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    // 0x808008D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808008DC:
    // 0x808008DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808008E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008E4: jr          $ra
    // 0x808008E8: nop

    return;
    // 0x808008E8: nop

;}
RECOMP_FUNC void glgamedata_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080038C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800390: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800394: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80800398: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8080039C: jal         0x808002F0
    // 0x808003A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    glgamedata_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808003A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808003A4: beq         $v0, $zero, L_808003C8
    if (ctx->r2 == 0) {
        // 0x808003A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808003C8;
    }
    // 0x808003A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003AC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808003B0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808003B4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x808003B8: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x808003BC: xori        $t9, $v0, 0x1E
    ctx->r25 = ctx->r2 ^ 0X1E;
    // 0x808003C0: b           L_808003CC
    // 0x808003C4: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
        goto L_808003CC;
    // 0x808003C4: sltiu       $v0, $t9, 0x1
    ctx->r2 = ctx->r25 < 0X1 ? 1 : 0;
L_808003C8:
    // 0x808003C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808003CC:
    // 0x808003CC: jr          $ra
    // 0x808003D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808003D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8080053C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080053C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800544: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80800548: jal         0x808004F8
    // 0x8080054C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_808004F8_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080054C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80800550: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800554: jal         0x800EFD24
    // 0x80800558: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80800558: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    after_1:
    // 0x8080055C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800560: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800564: jr          $ra
    // 0x80800568: nop

    return;
    // 0x80800568: nop

;}
RECOMP_FUNC void chkingjinjobits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1464, 0XA80) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xA80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1464, 0XA80));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xA80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1464, 0XA80));
;}
RECOMP_FUNC void _subaddiedialog_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A1F0: syscall     830
    recomp_syscall_handler(rdram, ctx, 0x8008A1F0);
    return;
    // 0x8008A1F4: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_8080015C_chsilo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800164: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80800168: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8080016C: bne         $a1, $t7, L_8080017C
    if (ctx->r5 != ctx->r15) {
        // 0x80800170: nop
    
            goto L_8080017C;
    }
    // 0x80800170: nop

    // 0x80800174: b           L_80800198
    // 0x80800178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800198;
    // 0x80800178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080017C:
    // 0x8080017C: jal         0x800DA298
    // 0x80800180: addiu       $a0, $a1, 0x32C
    ctx->r4 = ADD32(ctx->r5, 0X32C);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800180: addiu       $a0, $a1, 0x32C
    ctx->r4 = ADD32(ctx->r5, 0X32C);
    after_0:
    // 0x80800184: bnel        $v0, $zero, L_80800198
    if (ctx->r2 != 0) {
        // 0x80800188: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800198;
    }
    goto skip_0;
    // 0x80800188: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8080018C: b           L_80800198
    // 0x80800190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800198;
    // 0x80800190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800198:
    // 0x80800198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080019C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001A0: jr          $ra
    // 0x808001A4: nop

    return;
    // 0x808001A4: nop

;}
RECOMP_FUNC void func_80800DA4_chbilldrillplate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DA4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800DA8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80800DAC: sw          $s7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r23;
    // 0x80800DB0: sw          $s6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r22;
    // 0x80800DB4: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x80800DB8: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x80800DBC: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x80800DC0: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80800DC4: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80800DC8: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80800DCC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800DD0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800DD4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800DD8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800DDC: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800DE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DE4: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80800DE8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800DEC: bnel        $t7, $at, L_80800EEC
    if (ctx->r15 != ctx->r1) {
        // 0x80800DF0: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_80800EEC;
    }
    goto skip_0;
    // 0x80800DF0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x80800DF4: jal         0x800D9078
    // 0x80800DF8: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800DF8: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800DFC: beq         $v0, $zero, L_80800EE8
    if (ctx->r2 == 0) {
        // 0x80800E00: addiu       $s6, $sp, 0x7C
        ctx->r22 = ADD32(ctx->r29, 0X7C);
            goto L_80800EE8;
    }
    // 0x80800E00: addiu       $s6, $sp, 0x7C
    ctx->r22 = ADD32(ctx->r29, 0X7C);
    // 0x80800E04: addiu       $s4, $s7, 0x4
    ctx->r20 = ADD32(ctx->r23, 0X4);
    // 0x80800E08: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800E0C: jal         0x800EE7F8
    // 0x80800E10: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800E10: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x80800E14: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800E18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E1C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80800E20: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1192, 0X1234) << 16);
    // 0x80800E24: addiu       $a2, $a2, 0x1234
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1192, 0X1234));
    // 0x80800E28: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800E2C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800E30: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800E34: jal         0x80089D18
    // 0x80800E38: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800E38: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80800E3C: jal         0x800B53A4
    // 0x80800E40: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800B53A4(rdram, ctx);
        goto after_3;
    // 0x80800E40: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x80800E44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1192, 0X108C) << 16);
    // 0x80800E48: lwc1        $f26, 0x108C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1192, 0X108C));
    // 0x80800E4C: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x80800E50: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800E54: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800E58: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800E5C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800E60: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1192, 0X1244) << 16);
    // 0x80800E64: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80800E68: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80800E6C: addiu       $s2, $s2, 0x1244
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1192, 0X1244));
    // 0x80800E70: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800E74: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x80800E78: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E80:
    // 0x80800E80: jal         0x800EE7F8
    // 0x80800E84: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800E84: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_4:
    // 0x80800E88: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80800E8C: jal         0x800DC178
    // 0x80800E90: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x80800E90: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_5:
    // 0x80800E94: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x80800E98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EA0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80800EA4: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80800EA8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800EAC: jal         0x800EF1B8
    // 0x80800EB0: nop

    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x80800EB0: nop

    after_6:
    // 0x80800EB4: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800EB8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80800EBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800EC0: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80800EC4: jal         0x800BABB8
    // 0x80800EC8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_800BABB8(rdram, ctx);
        goto after_7;
    // 0x80800EC8: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_7:
    // 0x80800ECC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80800ED0: bnel        $s1, $s3, L_80800E80
    if (ctx->r17 != ctx->r19) {
        // 0x80800ED4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E80;
    }
    goto skip_1;
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800ED8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800EDC: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80800EE0: jal         0x80086670
    // 0x80800EE4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x80800EE4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_8:
L_80800EE8:
    // 0x80800EE8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80800EEC:
    // 0x80800EEC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800EF0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800EF4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800EF8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800EFC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x80800F00: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80800F04: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x80800F08: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x80800F0C: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x80800F10: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x80800F14: lw          $s6, 0x54($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X54);
    // 0x80800F18: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x80800F1C: jr          $ra
    // 0x80800F20: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80800F20: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_808000A4_chfaircoinbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000B0: jal         0x80101FDC
    // 0x808000B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x808000B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808000B8: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808000BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000C0: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x808000C4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808000C8: beq         $t6, $at, L_808000E0
    if (ctx->r14 == ctx->r1) {
        // 0x808000CC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808000E0;
    }
    // 0x808000CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000D0: beq         $t6, $at, L_808000F0
    if (ctx->r14 == ctx->r1) {
        // 0x808000D4: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_808000F0;
    }
    // 0x808000D4: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x808000D8: b           L_8080015C
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080015C;
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000E0:
    // 0x808000E0: jal         0x800904F4
    // 0x808000E4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800904F4(rdram, ctx);
        goto after_1;
    // 0x808000E4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x808000E8: b           L_8080015C
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080015C;
    // 0x808000EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F0:
    // 0x808000F0: jal         0x800C01A8
    // 0x808000F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_2;
    // 0x808000F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808000F8: jal         0x8080001C
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080001C_chfaircoinbox(rdram, ctx);
        goto after_3;
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800100: jal         0x80090708
    // 0x80800104: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_4;
    // 0x80800104: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80800108: jal         0x800FC660
    // 0x8080010C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC660(rdram, ctx);
        goto after_5;
    // 0x8080010C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_5:
    // 0x80800110: lhu         $v0, 0x76($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X76);
    // 0x80800114: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800118: addiu       $a0, $zero, 0x340
    ctx->r4 = ADD32(0, 0X340);
    // 0x8080011C: srl         $t7, $v0, 7
    ctx->r15 = S32(U32(ctx->r2) >> 7);
    // 0x80800120: addiu       $v0, $t7, -0x32
    ctx->r2 = ADD32(ctx->r15, -0X32);
    // 0x80800124: beq         $v0, $zero, L_8080013C
    if (ctx->r2 == 0) {
        // 0x80800128: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_8080013C;
    }
    // 0x80800128: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8080012C: beq         $v0, $at, L_8080014C
    if (ctx->r2 == ctx->r1) {
        // 0x80800130: addiu       $a0, $zero, 0x307
        ctx->r4 = ADD32(0, 0X307);
            goto L_8080014C;
    }
    // 0x80800130: addiu       $a0, $zero, 0x307
    ctx->r4 = ADD32(0, 0X307);
    // 0x80800134: b           L_8080015C
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080015C;
    // 0x80800138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080013C:
    // 0x8080013C: jal         0x80101180
    // 0x80800140: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_6;
    // 0x80800140: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800144: b           L_8080015C
    // 0x80800148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080015C;
    // 0x80800148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080014C:
    // 0x8080014C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800150: jal         0x80101180
    // 0x80800154: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_7;
    // 0x80800154: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080015C:
    // 0x8080015C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800160: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800164: jr          $ra
    // 0x80800168: nop

    return;
    // 0x80800168: nop

;}
RECOMP_FUNC void func_8080027C_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080027C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800280: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800284: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800288: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8080028C: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800290: lw          $a0, 0x18($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X18);
    // 0x80800294: srl         $t7, $a0, 28
    ctx->r15 = S32(U32(ctx->r4) >> 28);
    // 0x80800298: jal         0x8008A240
    // 0x8080029C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    _sucoasterdata_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080029C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x808002A0: lhu         $t8, 0x72($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X72);
    // 0x808002A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808002A8: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808002AC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x808002B0: sltiu       $at, $t0, 0x12
    ctx->r1 = ctx->r8 < 0X12 ? 1 : 0;
    // 0x808002B4: beq         $at, $zero, L_80800BC8
    if (ctx->r1 == 0) {
        // 0x808002B8: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80800BC8;
    }
    // 0x808002B8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x808002BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X27B4) << 16);
    // 0x808002C0: addu        $at, $at, $t0
    gpr jr_addend_808002C8 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808002C4: lw          $t0, 0x27B4($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3274, 0X27B4));
    // 0x808002C8: jr          $t0
    // 0x808002CC: nop

    switch (jr_addend_808002C8 >> 2) {
        case 0: goto L_808002D0; break;
        case 1: goto L_80800318; break;
        case 2: goto L_808003D8; break;
        case 3: goto L_80800494; break;
        case 4: goto L_80800524; break;
        case 5: goto L_8080063C; break;
        case 6: goto L_808006E0; break;
        case 7: goto L_808007B4; break;
        case 8: goto L_80800884; break;
        case 9: goto L_8080093C; break;
        case 10: goto L_808009CC; break;
        case 11: goto L_80800A3C; break;
        case 12: goto L_80800A9C; break;
        case 13: goto L_80800AAC; break;
        case 14: goto L_80800ABC; break;
        case 15: goto L_80800BC8; break;
        case 16: goto L_80800ACC; break;
        case 17: goto L_80800ADC; break;
        default: switch_error(__func__, 0x808002C8, 0x808027B4);
    }
    // 0x808002CC: nop

L_808002D0:
    // 0x808002D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808002D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808002D8: jal         0x800DC298
    // 0x808002DC: nop

    func_800DC298(rdram, ctx);
        goto after_1;
    // 0x808002DC: nop

    after_1:
    // 0x808002E0: beq         $v0, $zero, L_808002F0
    if (ctx->r2 == 0) {
        // 0x808002E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002F0;
    }
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: b           L_808002F4
    // 0x808002EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_808002F4;
    // 0x808002EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_808002F0:
    // 0x808002F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_808002F4:
    // 0x808002F4: jal         0x80801004
    // 0x808002F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x808002F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808002FC: bne         $v0, $zero, L_80800BC8
    if (ctx->r2 != 0) {
        // 0x80800300: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BC8;
    }
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800304: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800308: jal         0x80801004
    // 0x8080030C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x8080030C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800310: b           L_80800BCC
    // 0x80800314: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800314: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800318:
    // 0x80800318: jal         0x80801BA8
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x8080031C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800320: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800324: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800328: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X27FC) << 16);
    // 0x8080032C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800330: nop

    // 0x80800334: bc1f        L_808003C0
    if (!c1cs) {
        // 0x80800338: nop
    
            goto L_808003C0;
    }
    // 0x80800338: nop

    // 0x8080033C: jal         0x800DC298
    // 0x80800340: lwc1        $f12, 0x27FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X27FC));
    func_800DC298(rdram, ctx);
        goto after_5;
    // 0x80800340: lwc1        $f12, 0x27FC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X27FC));
    after_5:
    // 0x80800344: beq         $v0, $zero, L_808003C0
    if (ctx->r2 == 0) {
        // 0x80800348: lw          $t1, 0x54($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X54);
            goto L_808003C0;
    }
    // 0x80800348: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8080034C: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x80800350: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800358: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x8080035C: bgez        $t4, L_80800384
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80800360: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80800384;
    }
    // 0x80800360: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: jal         0x80801004
    // 0x8080036C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x8080036C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800370: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x80800374: lbu         $t6, 0x18($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X18);
    // 0x80800378: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x8080037C: b           L_808003C0
    // 0x80800380: sb          $t7, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r15;
        goto L_808003C0;
    // 0x80800380: sb          $t7, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r15;
L_80800384:
    // 0x80800384: jal         0x80801004
    // 0x80800388: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x80800388: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8080038C: beq         $v0, $zero, L_808003C0
    if (ctx->r2 == 0) {
        // 0x80800390: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C0;
    }
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800398: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080039C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808003A0: lbu         $a2, 0x16($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X16);
    // 0x808003A4: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x808003A8: addiu       $t0, $zero, 0x2D
    ctx->r8 = ADD32(0, 0X2D);
    // 0x808003AC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x808003B0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808003B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808003B8: jal         0x80089F88
    // 0x808003BC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x808003BC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
L_808003C0:
    // 0x808003C0: jal         0x8080168C
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x808003C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003C8: jal         0x80800FDC
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_8(rdram, ctx);
        goto after_10;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808003D0: b           L_80800BCC
    // 0x808003D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x808003D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808003D8:
    // 0x808003D8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x808003DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2800) << 16);
    // 0x808003E0: lwc1        $f10, 0x2800($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2800));
    // 0x808003E4: lbu         $a2, 0x16($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X16);
    // 0x808003E8: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x808003EC: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x808003F0: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x808003F4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x80800400: jal         0x80089F88
    // 0x80800404: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_11;
    // 0x80800404: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x80800408: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8080040C: lbu         $t6, 0x16($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X16);
    // 0x80800410: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80800414: bnel        $t7, $zero, L_80800470
    if (ctx->r15 != 0) {
        // 0x80800418: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800470;
    }
    goto skip_0;
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080041C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800420: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800424: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2804) << 16);
    // 0x80800428: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x8080042C: nop

    // 0x80800430: bc1fl       L_80800470
    if (!c1cs) {
        // 0x80800434: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800470;
    }
    goto skip_1;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800438: jal         0x800DC298
    // 0x8080043C: lwc1        $f12, 0x2804($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2804));
    func_800DC298(rdram, ctx);
        goto after_12;
    // 0x8080043C: lwc1        $f12, 0x2804($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2804));
    after_12:
    // 0x80800440: beq         $v0, $zero, L_8080046C
    if (ctx->r2 == 0) {
        // 0x80800444: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(3274, 0X2808) << 16);
            goto L_8080046C;
    }
    // 0x80800444: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2808) << 16);
    // 0x80800448: jal         0x800DC298
    // 0x8080044C: lwc1        $f12, 0x2808($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2808));
    func_800DC298(rdram, ctx);
        goto after_13;
    // 0x8080044C: lwc1        $f12, 0x2808($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2808));
    after_13:
    // 0x80800450: beq         $v0, $zero, L_80800460
    if (ctx->r2 == 0) {
        // 0x80800454: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800460;
    }
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800458: b           L_80800464
    // 0x8080045C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_80800464;
    // 0x8080045C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80800460:
    // 0x80800460: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80800464:
    // 0x80800464: jal         0x80801004
    // 0x80800468: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_14;
    // 0x80800468: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
L_8080046C:
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800470:
    // 0x80800470: addiu       $a1, $zero, 0x802
    ctx->r5 = ADD32(0, 0X802);
    // 0x80800474: jal         0x80800D8C
    // 0x80800478: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    sucoaster_entrypoint_7(rdram, ctx);
        goto after_15;
    // 0x80800478: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_15:
    // 0x8080047C: bnel        $v0, $zero, L_80800BCC
    if (ctx->r2 != 0) {
        // 0x80800480: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800BCC;
    }
    goto skip_2;
    // 0x80800480: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80800484: jal         0x8080168C
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_13(rdram, ctx);
        goto after_16;
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8080048C: b           L_80800BCC
    // 0x80800490: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800490: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800494:
    // 0x80800494: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800498: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X280C) << 16);
    // 0x8080049C: lwc1        $f4, 0x280C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X280C));
    // 0x808004A0: lbu         $a2, 0x16($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X16);
    // 0x808004A4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x808004A8: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x808004AC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x808004B0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B8: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x808004BC: jal         0x80089F88
    // 0x808004C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_17;
    // 0x808004C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_17:
    // 0x808004C4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808004C8: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808004CC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3274, 0X2810) << 16);
    // 0x808004D0: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x808004D4: nop

    // 0x808004D8: bc1fl       L_80800500
    if (!c1cs) {
        // 0x808004DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800500;
    }
    goto skip_3;
    // 0x808004DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808004E0: jal         0x800DC298
    // 0x808004E4: lwc1        $f12, 0x2810($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2810));
    func_800DC298(rdram, ctx);
        goto after_18;
    // 0x808004E4: lwc1        $f12, 0x2810($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3274, 0X2810));
    after_18:
    // 0x808004E8: beq         $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004FC;
    }
    // 0x808004EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808004F4: jal         0x80801004
    // 0x808004F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_19;
    // 0x808004F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
L_808004FC:
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800500:
    // 0x80800500: addiu       $a1, $zero, 0x802
    ctx->r5 = ADD32(0, 0X802);
    // 0x80800504: jal         0x80800D8C
    // 0x80800508: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    sucoaster_entrypoint_7(rdram, ctx);
        goto after_20;
    // 0x80800508: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_20:
    // 0x8080050C: bnel        $v0, $zero, L_80800BCC
    if (ctx->r2 != 0) {
        // 0x80800510: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800BCC;
    }
    goto skip_4;
    // 0x80800510: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x80800514: jal         0x8080168C
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_13(rdram, ctx);
        goto after_21;
    // 0x80800518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080051C: b           L_80800BCC
    // 0x80800520: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800520: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800524:
    // 0x80800524: jal         0x808017E0
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_14(rdram, ctx);
        goto after_22;
    // 0x80800528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8080052C: beq         $v0, $zero, L_80800570
    if (ctx->r2 == 0) {
        // 0x80800530: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800570;
    }
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800538: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080053C: jal         0x80801004
    // 0x80800540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_23;
    // 0x80800540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x80800544: beq         $v0, $zero, L_8080062C
    if (ctx->r2 == 0) {
        // 0x80800548: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8080062C;
    }
    // 0x80800548: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8080054C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800550: jal         0x800D9058
    // 0x80800554: nop

    func_800D9058(rdram, ctx);
        goto after_24;
    // 0x80800554: nop

    after_24:
    // 0x80800558: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080055C: andi        $t1, $v0, 0x1FF
    ctx->r9 = ctx->r2 & 0X1FF;
    // 0x80800560: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80800564: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80800568: b           L_8080062C
    // 0x8080056C: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
        goto L_8080062C;
    // 0x8080056C: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
L_80800570:
    // 0x80800570: jal         0x8080264C
    // 0x80800574: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_8080264C_sucoaster(rdram, ctx);
        goto after_25;
    // 0x80800574: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_25:
    // 0x80800578: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8080057C: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x80800580: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800584: lh          $t6, 0x10($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X10);
    // 0x80800588: addiu       $t7, $zero, 0x5802
    ctx->r15 = ADD32(0, 0X5802);
    // 0x8080058C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80800590: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800598: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080059C: jal         0x80089F90
    // 0x808005A0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_26;
    // 0x808005A0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_26:
    // 0x808005A4: bne         $v0, $zero, L_808005E8
    if (ctx->r2 != 0) {
        // 0x808005A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005E8;
    }
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005B0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005B4: jal         0x80801004
    // 0x808005B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_27;
    // 0x808005B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x808005BC: beq         $v0, $zero, L_8080062C
    if (ctx->r2 == 0) {
        // 0x808005C0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8080062C;
    }
    // 0x808005C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808005C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808005C8: jal         0x800D9058
    // 0x808005CC: nop

    func_800D9058(rdram, ctx);
        goto after_28;
    // 0x808005CC: nop

    after_28:
    // 0x808005D0: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x808005D4: andi        $t8, $v0, 0x1FF
    ctx->r24 = ctx->r2 & 0X1FF;
    // 0x808005D8: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x808005DC: or          $t2, $t8, $t0
    ctx->r10 = ctx->r24 | ctx->r8;
    // 0x808005E0: b           L_8080062C
    // 0x808005E4: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
        goto L_8080062C;
    // 0x808005E4: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
L_808005E8:
    // 0x808005E8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x808005EC: jal         0x808020B8
    // 0x808005F0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_808020B8_sucoaster(rdram, ctx);
        goto after_29;
    // 0x808005F0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_29:
    // 0x808005F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F8: jal         0x80102CF4
    // 0x808005FC: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    func_80102CF4(rdram, ctx);
        goto after_30;
    // 0x808005FC: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    after_30:
    // 0x80800600: beq         $v0, $zero, L_8080062C
    if (ctx->r2 == 0) {
        // 0x80800604: lw          $t1, 0x54($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X54);
            goto L_8080062C;
    }
    // 0x80800604: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80800608: lbu         $t3, 0x12($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X12);
    // 0x8080060C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800614: beq         $t3, $zero, L_80800624
    if (ctx->r11 == 0) {
        // 0x80800618: nop
    
            goto L_80800624;
    }
    // 0x80800618: nop

    // 0x8080061C: b           L_80800624
    // 0x80800620: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
        goto L_80800624;
    // 0x80800620: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_80800624:
    // 0x80800624: jal         0x80801004
    // 0x80800628: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_31;
    // 0x80800628: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_31:
L_8080062C:
    // 0x8080062C: jal         0x80800FDC
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_8(rdram, ctx);
        goto after_32;
    // 0x80800630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80800634: b           L_80800BCC
    // 0x80800638: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800638: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080063C:
    // 0x8080063C: lh          $t4, 0x50($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X50);
    // 0x80800640: lh          $t6, 0x52($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X52);
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8080064C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800650: lw          $a1, 0x4C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4C);
    // 0x80800654: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80800658: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080065C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800660: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800664: jal         0x80102BF8
    // 0x80800668: nop

    func_80102BF8(rdram, ctx);
        goto after_33;
    // 0x80800668: nop

    after_33:
    // 0x8080066C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800670: jal         0x80102CF4
    // 0x80800674: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    func_80102CF4(rdram, ctx);
        goto after_34;
    // 0x80800674: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    after_34:
    // 0x80800678: beq         $v0, $zero, L_808006D0
    if (ctx->r2 == 0) {
        // 0x8080067C: nop
    
            goto L_808006D0;
    }
    // 0x8080067C: nop

    // 0x80800680: lbu         $t7, 0x74($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X74);
    // 0x80800684: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: andi        $t5, $t7, 0x1
    ctx->r13 = ctx->r15 & 0X1;
    // 0x80800690: beq         $t5, $zero, L_808006B8
    if (ctx->r13 == 0) {
        // 0x80800694: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_808006B8;
    }
    // 0x80800694: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080069C: jal         0x80801004
    // 0x808006A0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_35;
    // 0x808006A0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_35:
    // 0x808006A4: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x808006A8: lbu         $t9, 0x18($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18);
    // 0x808006AC: andi        $t8, $t9, 0xFFFD
    ctx->r24 = ctx->r25 & 0XFFFD;
    // 0x808006B0: b           L_808006D0
    // 0x808006B4: sb          $t8, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r24;
        goto L_808006D0;
    // 0x808006B4: sb          $t8, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r24;
L_808006B8:
    // 0x808006B8: jal         0x80801004
    // 0x808006BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_36;
    // 0x808006BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_36:
    // 0x808006C0: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x808006C4: lbu         $t0, 0x18($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X18);
    // 0x808006C8: andi        $t2, $t0, 0xFFFD
    ctx->r10 = ctx->r8 & 0XFFFD;
    // 0x808006CC: sb          $t2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r10;
L_808006D0:
    // 0x808006D0: jal         0x80800FDC
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_8(rdram, ctx);
        goto after_37;
    // 0x808006D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x808006D8: b           L_80800BCC
    // 0x808006DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x808006DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808006E0:
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E4: jal         0x808019D4
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sucoaster_entrypoint_16(rdram, ctx);
        goto after_38;
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_38:
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F0: jal         0x8080264C
    // 0x808006F4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_8080264C_sucoaster(rdram, ctx);
        goto after_39;
    // 0x808006F4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_39:
    // 0x808006F8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x808006FC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800704: jal         0x808020B8
    // 0x80800708: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_808020B8_sucoaster(rdram, ctx);
        goto after_40;
    // 0x80800708: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_40:
    // 0x8080070C: jal         0x80101DDC
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_41;
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80800714: beq         $v0, $zero, L_808007A4
    if (ctx->r2 == 0) {
        // 0x80800718: nop
    
            goto L_808007A4;
    }
    // 0x80800718: nop

    // 0x8080071C: jal         0x808017E0
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_14(rdram, ctx);
        goto after_42;
    // 0x80800720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x80800724: beq         $v0, $zero, L_80800798
    if (ctx->r2 == 0) {
        // 0x80800728: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800798;
    }
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800730: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800734: jal         0x80801004
    // 0x80800738: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_43;
    // 0x80800738: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_43:
    // 0x8080073C: beq         $v0, $zero, L_808007A4
    if (ctx->r2 == 0) {
        // 0x80800740: lw          $a1, 0x54($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X54);
            goto L_808007A4;
    }
    // 0x80800740: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80800744: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800748: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080074C: lbu         $a2, 0x16($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X16);
    // 0x80800750: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x80800754: addiu       $t3, $zero, 0x46
    ctx->r11 = ADD32(0, 0X46);
    // 0x80800758: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8080075C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800768: jal         0x80089F88
    // 0x8080076C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_44;
    // 0x8080076C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_44:
    // 0x80800770: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80800774: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800778: jal         0x800D9058
    // 0x8080077C: nop

    func_800D9058(rdram, ctx);
        goto after_45;
    // 0x8080077C: nop

    after_45:
    // 0x80800780: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800784: andi        $t6, $v0, 0x1FF
    ctx->r14 = ctx->r2 & 0X1FF;
    // 0x80800788: andi        $t5, $t7, 0xFE00
    ctx->r13 = ctx->r15 & 0XFE00;
    // 0x8080078C: or          $t9, $t6, $t5
    ctx->r25 = ctx->r14 | ctx->r13;
    // 0x80800790: b           L_808007A4
    // 0x80800794: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
        goto L_808007A4;
    // 0x80800794: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
L_80800798:
    // 0x80800798: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8080079C: jal         0x80801004
    // 0x808007A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_46;
    // 0x808007A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_46:
L_808007A4:
    // 0x808007A4: jal         0x80800FDC
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_8(rdram, ctx);
        goto after_47;
    // 0x808007A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x808007AC: b           L_80800BCC
    // 0x808007B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x808007B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808007B4:
    // 0x808007B4: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x808007B8: lw          $a0, 0x18($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X18);
    // 0x808007BC: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x808007C0: srl         $t0, $a0, 28
    ctx->r8 = S32(U32(ctx->r4) >> 28);
    // 0x808007C4: jal         0x8008A250
    // 0x808007C8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    _sucoasterdata_entrypoint_3(rdram, ctx);
        goto after_48;
    // 0x808007C8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_48:
    // 0x808007CC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x808007D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007D4: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x808007D8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808007DC: jal         0x808014C4
    // 0x808007E0: nop

    sucoaster_entrypoint_11(rdram, ctx);
        goto after_49;
    // 0x808007E0: nop

    after_49:
    // 0x808007E4: jal         0x808017E0
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_14(rdram, ctx);
        goto after_50;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x808007EC: beq         $v0, $zero, L_80800804
    if (ctx->r2 == 0) {
        // 0x808007F0: lw          $t2, 0x54($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X54);
            goto L_80800804;
    }
    // 0x808007F0: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x808007F4: jal         0x808018B4
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_15(rdram, ctx);
        goto after_51;
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x808007FC: b           L_80800870
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800870;
    // 0x80800800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800804:
    // 0x80800804: lb          $t3, 0x19($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X19);
    // 0x80800808: bltzl       $t3, L_80800820
    if (SIGNED(ctx->r11) < 0) {
        // 0x8080080C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800820;
    }
    goto skip_5;
    // 0x8080080C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x80800810: jal         0x80089F78
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_52;
    // 0x80800814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x80800818: beq         $v0, $zero, L_8080082C
    if (ctx->r2 == 0) {
        // 0x8080081C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080082C;
    }
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800820:
    // 0x80800820: jal         0x8080264C
    // 0x80800824: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_8080264C_sucoaster(rdram, ctx);
        goto after_53;
    // 0x80800824: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_53:
    // 0x80800828: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_8080082C:
    // 0x8080082C: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80800830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800834: lhu         $t7, 0x4A($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X4A);
    // 0x80800838: beql        $t7, $zero, L_80800870
    if (ctx->r15 == 0) {
        // 0x8080083C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800870;
    }
    goto skip_6;
    // 0x8080083C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_6:
    // 0x80800840: jal         0x80102CF4
    // 0x80800844: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    func_80102CF4(rdram, ctx);
        goto after_54;
    // 0x80800844: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    after_54:
    // 0x80800848: beq         $v0, $zero, L_8080086C
    if (ctx->r2 == 0) {
        // 0x8080084C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080086C;
    }
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800850: jal         0x80802400
    // 0x80800854: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80802400_sucoaster(rdram, ctx);
        goto after_55;
    // 0x80800854: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_55:
    // 0x80800858: beq         $v0, $zero, L_8080086C
    if (ctx->r2 == 0) {
        // 0x8080085C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080086C;
    }
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800860: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800864: jal         0x80801004
    // 0x80800868: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_56;
    // 0x80800868: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_56:
L_8080086C:
    // 0x8080086C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800870:
    // 0x80800870: addiu       $a1, $zero, 0x5802
    ctx->r5 = ADD32(0, 0X5802);
    // 0x80800874: jal         0x80800D8C
    // 0x80800878: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    sucoaster_entrypoint_7(rdram, ctx);
        goto after_57;
    // 0x80800878: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_57:
    // 0x8080087C: b           L_80800BCC
    // 0x80800880: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800880: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800884:
    // 0x80800884: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80800888: lb          $t9, 0x19($t6)
    ctx->r25 = MEM_B(ctx->r14, 0X19);
    // 0x8080088C: bltzl       $t9, L_808008A4
    if (SIGNED(ctx->r25) < 0) {
        // 0x80800890: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008A4;
    }
    goto skip_7;
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_7:
    // 0x80800894: jal         0x80089F78
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_58;
    // 0x80800898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_58:
    // 0x8080089C: beq         $v0, $zero, L_808008B0
    if (ctx->r2 == 0) {
        // 0x808008A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008B0;
    }
    // 0x808008A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008A4:
    // 0x808008A4: jal         0x8080264C
    // 0x808008A8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_8080264C_sucoaster(rdram, ctx);
        goto after_59;
    // 0x808008A8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_59:
    // 0x808008AC: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_808008B0:
    // 0x808008B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008B4: addiu       $a1, $zero, 0x5802
    ctx->r5 = ADD32(0, 0X5802);
    // 0x808008B8: jal         0x80800D8C
    // 0x808008BC: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    sucoaster_entrypoint_7(rdram, ctx);
        goto after_60;
    // 0x808008BC: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_60:
    // 0x808008C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008C4: jal         0x808019D4
    // 0x808008C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sucoaster_entrypoint_16(rdram, ctx);
        goto after_61;
    // 0x808008C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_61:
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D0: jal         0x808019D4
    // 0x808008D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    sucoaster_entrypoint_16(rdram, ctx);
        goto after_62;
    // 0x808008D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_62:
    // 0x808008D8: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E0: lw          $t0, 0x18($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X18);
    // 0x808008E4: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x808008E8: bltz        $t1, L_80800908
    if (SIGNED(ctx->r9) < 0) {
        // 0x808008EC: nop
    
            goto L_80800908;
    }
    // 0x808008EC: nop

    // 0x808008F0: jal         0x808019D4
    // 0x808008F4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    sucoaster_entrypoint_16(rdram, ctx);
        goto after_63;
    // 0x808008F4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_63:
    // 0x808008F8: beq         $v0, $zero, L_80800908
    if (ctx->r2 == 0) {
        // 0x808008FC: nop
    
            goto L_80800908;
    }
    // 0x808008FC: nop

    // 0x80800900: jal         0x8008A338
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoasterhit_entrypoint_2(rdram, ctx);
        goto after_64;
    // 0x80800904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_64:
L_80800908:
    // 0x80800908: jal         0x80101DDC
    // 0x8080090C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_65;
    // 0x8080090C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_65:
    // 0x80800910: beql        $v0, $zero, L_80800BCC
    if (ctx->r2 == 0) {
        // 0x80800914: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800BCC;
    }
    goto skip_8;
    // 0x80800914: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x80800918: jal         0x8080168C
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_13(rdram, ctx);
        goto after_66;
    // 0x8080091C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x80800920: bne         $v0, $zero, L_80800BC8
    if (ctx->r2 != 0) {
        // 0x80800924: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BC8;
    }
    // 0x80800924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800928: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080092C: jal         0x80801004
    // 0x80800930: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_67;
    // 0x80800930: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_67:
    // 0x80800934: b           L_80800BCC
    // 0x80800938: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800938: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080093C:
    // 0x8080093C: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80800940: lw          $a0, 0x18($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X18);
    // 0x80800944: srl         $t4, $a0, 28
    ctx->r12 = S32(U32(ctx->r4) >> 28);
    // 0x80800948: jal         0x8008A250
    // 0x8080094C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    _sucoasterdata_entrypoint_3(rdram, ctx);
        goto after_68;
    // 0x8080094C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_68:
    // 0x80800950: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80800954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800958: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8080095C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800960: jal         0x808014C4
    // 0x80800964: nop

    sucoaster_entrypoint_11(rdram, ctx);
        goto after_69;
    // 0x80800964: nop

    after_69:
    // 0x80800968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080096C: jal         0x80802550
    // 0x80800970: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_80802550_sucoaster(rdram, ctx);
        goto after_70;
    // 0x80800970: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_70:
    // 0x80800974: beq         $v0, $zero, L_8080098C
    if (ctx->r2 == 0) {
        // 0x80800978: lw          $t7, 0x54($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X54);
            goto L_8080098C;
    }
    // 0x80800978: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8080097C: jal         0x808018B4
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_15(rdram, ctx);
        goto after_71;
    // 0x80800980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_71:
    // 0x80800984: b           L_808009B8
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808009B8;
    // 0x80800988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080098C:
    // 0x8080098C: lb          $t5, 0x19($t7)
    ctx->r13 = MEM_B(ctx->r15, 0X19);
    // 0x80800990: bltzl       $t5, L_808009A8
    if (SIGNED(ctx->r13) < 0) {
        // 0x80800994: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009A8;
    }
    goto skip_9;
    // 0x80800994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_9:
    // 0x80800998: jal         0x80089F78
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_72;
    // 0x8080099C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_72:
    // 0x808009A0: beq         $v0, $zero, L_808009B4
    if (ctx->r2 == 0) {
        // 0x808009A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808009B4;
    }
    // 0x808009A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009A8:
    // 0x808009A8: jal         0x8080230C
    // 0x808009AC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_8080230C_sucoaster(rdram, ctx);
        goto after_73;
    // 0x808009AC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_73:
    // 0x808009B0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
L_808009B4:
    // 0x808009B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808009B8:
    // 0x808009B8: addiu       $a1, $zero, 0x4802
    ctx->r5 = ADD32(0, 0X4802);
    // 0x808009BC: jal         0x80800D8C
    // 0x808009C0: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    sucoaster_entrypoint_7(rdram, ctx);
        goto after_74;
    // 0x808009C0: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_74:
    // 0x808009C4: b           L_80800BCC
    // 0x808009C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x808009C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808009CC:
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D0: jal         0x808019D4
    // 0x808009D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    sucoaster_entrypoint_16(rdram, ctx);
        goto after_75;
    // 0x808009D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_75:
    // 0x808009D8: jal         0x80101DDC
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_76;
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_76:
    // 0x808009E0: beq         $v0, $zero, L_80800A2C
    if (ctx->r2 == 0) {
        // 0x808009E4: nop
    
            goto L_80800A2C;
    }
    // 0x808009E4: nop

    // 0x808009E8: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
    // 0x808009EC: sll         $t0, $t9, 28
    ctx->r8 = S32(ctx->r25 << 28);
    // 0x808009F0: bltz        $t0, L_80800A2C
    if (SIGNED(ctx->r8) < 0) {
        // 0x808009F4: nop
    
            goto L_80800A2C;
    }
    // 0x808009F4: nop

    // 0x808009F8: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x808009FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800A00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A04: andi        $t1, $t2, 0x1
    ctx->r9 = ctx->r10 & 0X1;
    // 0x80800A08: beq         $t1, $zero, L_80800A24
    if (ctx->r9 == 0) {
        // 0x80800A0C: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80800A24;
    }
    // 0x80800A0C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A14: jal         0x80801004
    // 0x80800A18: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_77;
    // 0x80800A18: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_77:
    // 0x80800A1C: b           L_80800A2C
    // 0x80800A20: nop

        goto L_80800A2C;
    // 0x80800A20: nop

L_80800A24:
    // 0x80800A24: jal         0x80801004
    // 0x80800A28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_78;
    // 0x80800A28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_78:
L_80800A2C:
    // 0x80800A2C: jal         0x80800FDC
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_8(rdram, ctx);
        goto after_79;
    // 0x80800A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_79:
    // 0x80800A34: b           L_80800BCC
    // 0x80800A38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800A38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800A3C:
    // 0x80800A3C: jal         0x80801BA8
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_19(rdram, ctx);
        goto after_80;
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_80:
    // 0x80800A44: jal         0x80101DDC
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_81;
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_81:
    // 0x80800A4C: beql        $v0, $zero, L_80800A8C
    if (ctx->r2 == 0) {
        // 0x80800A50: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A8C;
    }
    goto skip_10;
    // 0x80800A50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_10:
    // 0x80800A54: lw          $t3, 0x78($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X78);
    // 0x80800A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A5C: sll         $t7, $t3, 28
    ctx->r15 = S32(ctx->r11 << 28);
    // 0x80800A60: bltzl       $t7, L_80800A8C
    if (SIGNED(ctx->r15) < 0) {
        // 0x80800A64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A8C;
    }
    goto skip_11;
    // 0x80800A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_11:
    // 0x80800A68: jal         0x80107070
    // 0x80800A6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80107070(rdram, ctx);
        goto after_82;
    // 0x80800A6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_82:
    // 0x80800A70: bne         $v0, $zero, L_80800A88
    if (ctx->r2 != 0) {
        // 0x80800A74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A88;
    }
    // 0x80800A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A78: jal         0x80801054
    // 0x80800A7C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    sucoaster_entrypoint_10(rdram, ctx);
        goto after_83;
    // 0x80800A7C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_83:
    // 0x80800A80: jal         0x80089CA8
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_84;
    // 0x80800A84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_84:
L_80800A88:
    // 0x80800A88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800A8C:
    // 0x80800A8C: jal         0x808019D4
    // 0x80800A90: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    sucoaster_entrypoint_16(rdram, ctx);
        goto after_85;
    // 0x80800A90: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_85:
    // 0x80800A94: b           L_80800BCC
    // 0x80800A98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800A98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800A9C:
    // 0x80800A9C: jal         0x80801BA8
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_19(rdram, ctx);
        goto after_86;
    // 0x80800AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_86:
    // 0x80800AA4: b           L_80800BCC
    // 0x80800AA8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800AA8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800AAC:
    // 0x80800AAC: jal         0x80801BA8
    // 0x80800AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_19(rdram, ctx);
        goto after_87;
    // 0x80800AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_87:
    // 0x80800AB4: b           L_80800BCC
    // 0x80800AB8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800AB8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800ABC:
    // 0x80800ABC: jal         0x8008A330
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoasterhit_entrypoint_1(rdram, ctx);
        goto after_88;
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_88:
    // 0x80800AC4: b           L_80800BCC
    // 0x80800AC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800AC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800ACC:
    // 0x80800ACC: jal         0x80801BA8
    // 0x80800AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sucoaster_entrypoint_19(rdram, ctx);
        goto after_89;
    // 0x80800AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_89:
    // 0x80800AD4: b           L_80800BCC
    // 0x80800AD8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800AD8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800ADC:
    // 0x80800ADC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80800AE0: lw          $a0, 0x18($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X18);
    // 0x80800AE4: srl         $t5, $a0, 28
    ctx->r13 = S32(U32(ctx->r4) >> 28);
    // 0x80800AE8: jal         0x8008A250
    // 0x80800AEC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    _sucoasterdata_entrypoint_3(rdram, ctx);
        goto after_90;
    // 0x80800AEC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_90:
    // 0x80800AF0: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80800AF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AF8: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800AFC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800B00: jal         0x808014C4
    // 0x80800B04: nop

    sucoaster_entrypoint_11(rdram, ctx);
        goto after_91;
    // 0x80800B04: nop

    after_91:
    // 0x80800B08: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80800B0C: lbu         $a1, 0x16($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X16);
    // 0x80800B10: sltiu       $t8, $a1, 0x1
    ctx->r24 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80800B14: andi        $t0, $t8, 0x1B
    ctx->r8 = ctx->r24 & 0X1B;
    // 0x80800B18: beql        $t0, $zero, L_80800B98
    if (ctx->r8 == 0) {
        // 0x80800B1C: lbu         $t4, 0x74($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X74);
            goto L_80800B98;
    }
    goto skip_12;
    // 0x80800B1C: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
    skip_12:
    // 0x80800B20: jal         0x8001210C
    // 0x80800B24: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_8001210C(rdram, ctx);
        goto after_92;
    // 0x80800B24: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_92:
    // 0x80800B28: bne         $v0, $zero, L_80800B94
    if (ctx->r2 != 0) {
        // 0x80800B2C: lw          $t2, 0x54($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X54);
            goto L_80800B94;
    }
    // 0x80800B2C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80800B30: lbu         $t1, 0x18($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X18);
    // 0x80800B34: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800B38: andi        $t3, $t1, 0x1
    ctx->r11 = ctx->r9 & 0X1;
    // 0x80800B3C: beql        $t3, $zero, L_80800B58
    if (ctx->r11 == 0) {
        // 0x80800B40: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80800B58;
    }
    goto skip_13;
    // 0x80800B40: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_13:
    // 0x80800B44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800B48: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800B4C: b           L_80800B60
    // 0x80800B50: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_80800B60;
    // 0x80800B50: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800B54: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80800B58:
    // 0x80800B58: nop

    // 0x80800B5C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80800B60:
    // 0x80800B60: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800B64: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800B68: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800B6C: jal         0x800DC178
    // 0x80800B70: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_800DC178(rdram, ctx);
        goto after_93;
    // 0x80800B70: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_93:
    // 0x80800B74: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800B78: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B80: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80800B84: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800B88: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800B8C: jal         0x80102924
    // 0x80800B90: nop

    func_80102924(rdram, ctx);
        goto after_94;
    // 0x80800B90: nop

    after_94:
L_80800B94:
    // 0x80800B94: lbu         $t4, 0x74($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X74);
L_80800B98:
    // 0x80800B98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BA0: andi        $t7, $t4, 0x1
    ctx->r15 = ctx->r12 & 0X1;
    // 0x80800BA4: bne         $t7, $zero, L_80800BC0
    if (ctx->r15 != 0) {
        // 0x80800BA8: addiu       $a1, $zero, 0x4000
        ctx->r5 = ADD32(0, 0X4000);
            goto L_80800BC0;
    }
    // 0x80800BA8: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    // 0x80800BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BB0: jal         0x80801004
    // 0x80800BB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    sucoaster_entrypoint_9(rdram, ctx);
        goto after_95;
    // 0x80800BB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_95:
    // 0x80800BB8: b           L_80800BCC
    // 0x80800BBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80800BCC;
    // 0x80800BBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800BC0:
    // 0x80800BC0: jal         0x80800D8C
    // 0x80800BC4: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    sucoaster_entrypoint_7(rdram, ctx);
        goto after_96;
    // 0x80800BC4: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_96:
L_80800BC8:
    // 0x80800BC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800BCC:
    // 0x80800BCC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800BD0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800BD4: jr          $ra
    // 0x80800BD8: nop

    return;
    // 0x80800BD8: nop

;}
RECOMP_FUNC void basudie_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800238: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080023C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800240: jal         0x8009D3A8
    // 0x80800244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_0;
    // 0x80800244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800248: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080024C: jal         0x800852F0
    // 0x80800250: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    _batimer_decrement(rdram, ctx);
        goto after_1;
    // 0x80800250: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_1:
    // 0x80800254: beql        $v0, $zero, L_80800268
    if (ctx->r2 == 0) {
        // 0x80800258: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800268;
    }
    goto skip_0;
    // 0x80800258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080025C: jal         0x80800000
    // 0x80800260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    basudie_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800260: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800268:
    // 0x80800268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080026C: jr          $ra
    // 0x80800270: nop

    return;
    // 0x80800270: nop

;}
RECOMP_FUNC void _chpotogoldgame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875A8: syscall     592
    recomp_syscall_handler(rdram, ctx, 0x800875A8);
    return;
    // 0x800875AC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chweldarboss_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803BB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803BB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803BB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80803BBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80803BC0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80803BC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80803BC8: jal         0x80106790
    // 0x80803BCC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80803BCC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80803BD0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80803BD4: jal         0x80100094
    // 0x80803BD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80803BD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80803BDC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80803BE0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80803BE4: lbu         $v1, 0xAF($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XAF);
    // 0x80803BE8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80803BEC: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    // 0x80803BF0: sltu        $at, $a2, $a0
    ctx->r1 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x80803BF4: beq         $at, $zero, L_80803C08
    if (ctx->r1 == 0) {
        // 0x80803BF8: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_80803C08;
    }
L_80803BF8:
    // 0x80803BF8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80803BFC: sltu        $at, $a2, $a0
    ctx->r1 = ctx->r6 < ctx->r4 ? 1 : 0;
    // 0x80803C00: bne         $at, $zero, L_80803BF8
    if (ctx->r1 != 0) {
        // 0x80803C04: sb          $v1, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r3;
            goto L_80803BF8;
    }
    // 0x80803C04: sb          $v1, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r3;
L_80803C08:
    // 0x80803C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803C10: jr          $ra
    // 0x80803C14: nop

    return;
    // 0x80803C14: nop

;}
RECOMP_FUNC void baboost_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808001AC: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x808001B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001B4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808001B8: swc1        $f0, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f0.u32l;
    // 0x808001BC: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x808001C0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x808001C4: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x808001C8: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x808001CC: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x808001D0: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x808001D4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x808001D8: swc1        $f0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f0.u32l;
    // 0x808001DC: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x808001E0: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    // 0x808001E4: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x808001E8: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    // 0x808001EC: lw          $t0, 0x24($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X24);
    // 0x808001F0: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x808001F4: swc1        $f0, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f0.u32l;
    // 0x808001F8: lw          $t2, 0x24($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X24);
    // 0x808001FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80800200: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80800204: addu        $a1, $t2, $v1
    ctx->r5 = ADD32(ctx->r10, ctx->r3);
    // 0x80800208: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8080020C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80800210: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    // 0x80800214: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x80800218: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x8080021C: swc1        $f0, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f0.u32l;
    // 0x80800220: lw          $t5, 0x24($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X24);
    // 0x80800224: addu        $a1, $t5, $v1
    ctx->r5 = ADD32(ctx->r13, ctx->r3);
    // 0x80800228: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8080022C: swc1        $f10, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f10.u32l;
    // 0x80800230: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x80800234: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80800238: swc1        $f0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f0.u32l;
    // 0x8080023C: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x80800240: addu        $a1, $t8, $v1
    ctx->r5 = ADD32(ctx->r24, ctx->r3);
    // 0x80800244: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80800248: swc1        $f16, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f16.u32l;
    // 0x8080024C: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x80800250: swc1        $f18, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f18.u32l;
    // 0x80800254: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80800258: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8080025C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80800260: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80800264: nop

    // 0x80800268: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x8080026C: beql        $t1, $zero, L_808002BC
    if (ctx->r9 == 0) {
        // 0x80800270: mfc1        $t1, $f6
        ctx->r9 = (int32_t)ctx->f6.u32l;
            goto L_808002BC;
    }
    goto skip_0;
    // 0x80800270: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x80800274: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800278: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8080027C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800280: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80800284: nop

    // 0x80800288: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8080028C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80800290: nop

    // 0x80800294: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80800298: bne         $t1, $zero, L_808002B0
    if (ctx->r9 != 0) {
        // 0x8080029C: nop
    
            goto L_808002B0;
    }
    // 0x8080029C: nop

    // 0x808002A0: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x808002A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808002A8: b           L_808002C8
    // 0x808002AC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_808002C8;
    // 0x808002AC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_808002B0:
    // 0x808002B0: b           L_808002C8
    // 0x808002B4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_808002C8;
    // 0x808002B4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x808002B8: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
L_808002BC:
    // 0x808002BC: nop

    // 0x808002C0: bltz        $t1, L_808002B0
    if (SIGNED(ctx->r9) < 0) {
        // 0x808002C4: nop
    
            goto L_808002B0;
    }
    // 0x808002C4: nop

L_808002C8:
    // 0x808002C8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x808002CC: jr          $ra
    // 0x808002D0: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    return;
    // 0x808002D0: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void func_800D5FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5FE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D5FEC: lbu         $v0, -0x481C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X481C);
    // 0x800D5FF0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D5FF4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800D5FF8: blezl       $v0, L_800D6038
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D5FFC: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800D6038;
    }
    goto skip_0;
    // 0x800D5FFC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    skip_0:
    // 0x800D6000: lh          $t6, -0x4920($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4920);
    // 0x800D6004: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800D6008: addiu       $a1, $a1, -0x4920
    ctx->r5 = ADD32(ctx->r5, -0X4920);
    // 0x800D600C: beql        $a0, $t6, L_800D6038
    if (ctx->r4 == ctx->r14) {
        // 0x800D6010: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800D6038;
    }
    goto skip_1;
    // 0x800D6010: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    skip_1:
    // 0x800D6014: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D6018:
    // 0x800D6018: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D601C: beq         $at, $zero, L_800D6034
    if (ctx->r1 == 0) {
        // 0x800D6020: sll         $t7, $v1, 1
        ctx->r15 = S32(ctx->r3 << 1);
            goto L_800D6034;
    }
    // 0x800D6020: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x800D6024: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x800D6028: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800D602C: bnel        $a0, $t9, L_800D6018
    if (ctx->r4 != ctx->r25) {
        // 0x800D6030: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D6018;
    }
    goto skip_2;
    // 0x800D6030: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
L_800D6034:
    // 0x800D6034: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_800D6038:
    // 0x800D6038: bne         $at, $zero, L_800D6048
    if (ctx->r1 != 0) {
        // 0x800D603C: sll         $t0, $v1, 2
        ctx->r8 = S32(ctx->r3 << 2);
            goto L_800D6048;
    }
    // 0x800D603C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800D6040: jr          $ra
    // 0x800D6044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D6044: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D6048:
    // 0x800D6048: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800D604C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800D6050: lw          $v0, -0x4BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
    // 0x800D6054: jr          $ra
    // 0x800D6058: nop

    return;
    // 0x800D6058: nop

    // 0x800D605C: nop

;}
RECOMP_FUNC void D_808002E8_chdiggerbossbattery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: jr          $ra
    // 0x808002EC: nop

    return;
    // 0x808002EC: nop

;}
RECOMP_FUNC void func_808019E0_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808019E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808019E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808019EC: lui         $a1, 0x3E57
    ctx->r5 = S32(0X3E57 << 16);
    // 0x808019F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808019F4: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    // 0x808019F8: jal         0x8008CB10
    // 0x808019FC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x808019FC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_0:
    // 0x80801A00: beq         $v0, $zero, L_80801A98
    if (ctx->r2 == 0) {
        // 0x80801A04: lw          $a2, 0x3C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X3C);
            goto L_80801A98;
    }
    // 0x80801A04: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80801A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A0C: jal         0x800A0CF4
    // 0x80801A10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_1;
    // 0x80801A10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80801A14: jal         0x800849C0
    // 0x80801A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baduo_entrypoint_21(rdram, ctx);
        goto after_2;
    // 0x80801A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80801A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A20: jal         0x800A3410
    // 0x80801A24: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800A3410(rdram, ctx);
        goto after_3;
    // 0x80801A24: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x80801A28: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80801A2C: sb          $t6, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r14;
    // 0x80801A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A34: jal         0x8009C128
    // 0x80801A38: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_8009C128(rdram, ctx);
        goto after_4;
    // 0x80801A38: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x80801A3C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80801A40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801A44: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80801A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A4C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80801A50: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80801A54: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    // 0x80801A58: jal         0x8009FBB0
    // 0x80801A5C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    func_8009FBB0(rdram, ctx);
        goto after_5;
    // 0x80801A5C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80801A60: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(120, 0X1F20) << 16);
    // 0x80801A64: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80801A68: addiu       $t7, $t7, 0x1F20
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(120, 0X1F20));
    // 0x80801A6C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801A70: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801A74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801A78: jal         0x800BABB8
    // 0x80801A7C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_6;
    // 0x80801A7C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_6:
    // 0x80801A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A84: addiu       $a1, $zero, 0x4592
    ctx->r5 = ADD32(0, 0X4592);
    // 0x80801A88: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801A8C: jal         0x8009DF18
    // 0x80801A90: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    func_8009DF18(rdram, ctx);
        goto after_7;
    // 0x80801A90: addiu       $a3, $zero, 0x55F0
    ctx->r7 = ADD32(0, 0X55F0);
    after_7:
    // 0x80801A94: addiu       $a2, $zero, 0xED
    ctx->r6 = ADD32(0, 0XED);
L_80801A98:
    // 0x80801A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A9C: jal         0x8009E5C8
    // 0x80801AA0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    bs_setState(rdram, ctx);
        goto after_8;
    // 0x80801AA0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_8:
    // 0x80801AA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801AA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801AAC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801AB0: jr          $ra
    // 0x80801AB4: nop

    return;
    // 0x80801AB4: nop

;}
RECOMP_FUNC void _sucoaster_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A180: syscall     829
    recomp_syscall_handler(rdram, ctx, 0x8008A180);
    return;
    // 0x8008A184: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void sujiggy_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808003BC: jal         0x800FC6B0
    // 0x808003C0: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    func_800FC6B0(rdram, ctx);
        goto after_0;
    // 0x808003C0: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_0:
    // 0x808003C4: jal         0x800FE844
    // 0x808003C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800FE844(rdram, ctx);
        goto after_1;
    // 0x808003C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x808003CC: jal         0x800FE734
    // 0x808003D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FE734(rdram, ctx);
        goto after_2;
    // 0x808003D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x808003D4: jal         0x80800758
    // 0x808003D8: nop

    sujiggy_entrypoint_19(rdram, ctx);
        goto after_3;
    // 0x808003D8: nop

    after_3:
    // 0x808003DC: addiu       $a0, $zero, 0xD57
    ctx->r4 = ADD32(0, 0XD57);
    // 0x808003E0: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x808003E4: jal         0x800DA7A8
    // 0x808003E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800DA7A8(rdram, ctx);
        goto after_4;
    // 0x808003E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x808003EC: jal         0x80800178
    // 0x808003F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    sujiggy_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x808003F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x808003F4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808003F8: jal         0x808001AC
    // 0x808003FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    sujiggy_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x808003FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800400: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800404: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800408: jal         0x800A9BA0
    // 0x8080040C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800A9BA0(rdram, ctx);
        goto after_7;
    // 0x8080040C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_7:
    // 0x80800410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800414: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800418: jr          $ra
    // 0x8080041C: nop

    return;
    // 0x8080041C: nop

;}
RECOMP_FUNC void func_800DF5D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF5D8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800DF5DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF5E0: sw          $t6, -0x37C4($at)
    MEM_W(-0X37C4, ctx->r1) = ctx->r14;
    // 0x800DF5E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DF5E8: slti        $at, $a0, 0x100
    ctx->r1 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x800DF5EC: bne         $at, $zero, L_800DF608
    if (ctx->r1 != 0) {
        // 0x800DF5F0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800DF608;
    }
    // 0x800DF5F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF5F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF5F8: addiu       $v0, $v0, -0x3678
    ctx->r2 = ADD32(ctx->r2, -0X3678);
    // 0x800DF5FC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800DF600: b           L_800DF618
    // 0x800DF604: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
        goto L_800DF618;
    // 0x800DF604: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
L_800DF608:
    // 0x800DF608: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DF60C: addiu       $v0, $v0, -0x3678
    ctx->r2 = ADD32(ctx->r2, -0X3678);
    // 0x800DF610: sw          $a0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r4;
    // 0x800DF614: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_800DF618:
    // 0x800DF618: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x800DF61C: bnel        $at, $zero, L_800DF630
    if (ctx->r1 != 0) {
        // 0x800DF620: sw          $a1, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r5;
            goto L_800DF630;
    }
    goto skip_0;
    // 0x800DF620: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    skip_0:
    // 0x800DF624: b           L_800DF630
    // 0x800DF628: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
        goto L_800DF630;
    // 0x800DF628: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x800DF62C: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
L_800DF630:
    // 0x800DF630: slti        $at, $a2, 0x100
    ctx->r1 = SIGNED(ctx->r6) < 0X100 ? 1 : 0;
    // 0x800DF634: bnel        $at, $zero, L_800DF648
    if (ctx->r1 != 0) {
        // 0x800DF638: sw          $a2, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r6;
            goto L_800DF648;
    }
    goto skip_1;
    // 0x800DF638: sw          $a2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r6;
    skip_1:
    // 0x800DF63C: b           L_800DF648
    // 0x800DF640: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
        goto L_800DF648;
    // 0x800DF640: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x800DF644: sw          $a2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r6;
L_800DF648:
    // 0x800DF648: jal         0x800DF410
    // 0x800DF64C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800DF410(rdram, ctx);
        goto after_0;
    // 0x800DF64C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800DF650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DF658: jr          $ra
    // 0x800DF65C: nop

    return;
    // 0x800DF65C: nop

;}
RECOMP_FUNC void func_80800970_chfriesstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800978: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080097C: jal         0x80100094
    // 0x80800980: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800980: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800984: beq         $v0, $zero, L_80800994
    if (ctx->r2 == 0) {
        // 0x80800988: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800994;
    }
    // 0x80800988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080098C: jal         0x800897C8
    // 0x80800990: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800990: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800994:
    // 0x80800994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800998: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080099C: jr          $ra
    // 0x808009A0: nop

    return;
    // 0x808009A0: nop

;}
RECOMP_FUNC void func_80800B58_gcmapsects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800B5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B60: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800B64: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80800B68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800B6C: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x80800B70: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800B74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800B78: blez        $t6, L_80800C3C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80800B7C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80800C3C;
    }
    // 0x80800B7C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800B80: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
L_80800B84:
    // 0x80800B84: addu        $v1, $t7, $s0
    ctx->r3 = ADD32(ctx->r15, ctx->r16);
    // 0x80800B88: lw          $t8, 0x4C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4C);
    // 0x80800B8C: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x80800B90: bgezl       $t0, L_80800C28
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800B94: lbu         $t7, 0x77($s1)
        ctx->r15 = MEM_BU(ctx->r17, 0X77);
            goto L_80800C28;
    }
    goto skip_0;
    // 0x80800B94: lbu         $t7, 0x77($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X77);
    skip_0:
    // 0x80800B98: jal         0x800D73CC
    // 0x80800B9C: lhu         $a0, 0x40($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X40);
    func_800D73CC(rdram, ctx);
        goto after_0;
    // 0x80800B9C: lhu         $a0, 0x40($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X40);
    after_0:
    // 0x80800BA0: bnel        $v0, $zero, L_80800C28
    if (ctx->r2 != 0) {
        // 0x80800BA4: lbu         $t7, 0x77($s1)
        ctx->r15 = MEM_BU(ctx->r17, 0X77);
            goto L_80800C28;
    }
    goto skip_1;
    // 0x80800BA4: lbu         $t7, 0x77($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X77);
    skip_1:
    // 0x80800BA8: lw          $t1, 0x68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X68);
    // 0x80800BAC: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80800BB0: jal         0x800E488C
    // 0x80800BB4: lhu         $a0, 0x40($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X40);
    func_800E488C(rdram, ctx);
        goto after_1;
    // 0x80800BB4: lhu         $a0, 0x40($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X40);
    after_1:
    // 0x80800BB8: beql        $v0, $zero, L_80800C00
    if (ctx->r2 == 0) {
        // 0x80800BBC: lw          $t1, 0x68($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X68);
            goto L_80800C00;
    }
    goto skip_2;
    // 0x80800BBC: lw          $t1, 0x68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X68);
    skip_2:
    // 0x80800BC0: lw          $t3, 0x68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X68);
    // 0x80800BC4: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80800BC8: jal         0x800D674C
    // 0x80800BCC: lhu         $a0, 0x40($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X40);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x80800BCC: lhu         $a0, 0x40($t4)
    ctx->r4 = MEM_HU(ctx->r12, 0X40);
    after_2:
    // 0x80800BD0: lw          $t5, 0x68($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X68);
    // 0x80800BD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800BD8: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x80800BDC: jal         0x800D70F8
    // 0x80800BE0: lhu         $a0, 0x40($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X40);
    func_800D70F8(rdram, ctx);
        goto after_3;
    // 0x80800BE0: lhu         $a0, 0x40($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X40);
    after_3:
    // 0x80800BE4: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    // 0x80800BE8: addu        $v1, $t7, $s0
    ctx->r3 = ADD32(ctx->r15, ctx->r16);
    // 0x80800BEC: lbu         $t9, 0x4C($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4C);
    // 0x80800BF0: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80800BF4: b           L_80800C24
    // 0x80800BF8: sb          $t0, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r8;
        goto L_80800C24;
    // 0x80800BF8: sb          $t0, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r8;
    // 0x80800BFC: lw          $t1, 0x68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X68);
L_80800C00:
    // 0x80800C00: addu        $v1, $t1, $s0
    ctx->r3 = ADD32(ctx->r9, ctx->r16);
    // 0x80800C04: lbu         $t2, 0x4C($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X4C);
    // 0x80800C08: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x80800C0C: sb          $t3, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r11;
    // 0x80800C10: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x80800C14: addu        $v1, $t4, $s0
    ctx->r3 = ADD32(ctx->r12, ctx->r16);
    // 0x80800C18: lbu         $t5, 0x4C($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X4C);
    // 0x80800C1C: andi        $t6, $t5, 0xFFBF
    ctx->r14 = ctx->r13 & 0XFFBF;
    // 0x80800C20: sb          $t6, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r14;
L_80800C24:
    // 0x80800C24: lbu         $t7, 0x77($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X77);
L_80800C28:
    // 0x80800C28: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800C2C: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80800C30: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800C34: bnel        $at, $zero, L_80800B84
    if (ctx->r1 != 0) {
        // 0x80800C38: lw          $t7, 0x68($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X68);
            goto L_80800B84;
    }
    goto skip_3;
    // 0x80800C38: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    skip_3:
L_80800C3C:
    // 0x80800C3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800C40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800C44: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C48: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800C4C: jr          $ra
    // 0x80800C50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800C50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800048_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: jr          $ra
    // 0x8080004C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8080004C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80802268_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802268: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080226C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80802270: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80802274: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80802278: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8080227C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80802280: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802284: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80802288: jal         0x80100094
    // 0x8080228C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080228C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802290: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802294: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80802298: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8080229C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x808022A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808022A4: addiu       $s2, $v0, 0x16C
    ctx->r18 = ADD32(ctx->r2, 0X16C);
    // 0x808022A8: addiu       $s3, $zero, 0x60
    ctx->r19 = ADD32(0, 0X60);
L_808022AC:
    // 0x808022AC: lwc1        $f4, 0x17C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x808022B0: addiu       $a0, $zero, 0x1C8
    ctx->r4 = ADD32(0, 0X1C8);
    // 0x808022B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x808022B8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808022BC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808022C0: jal         0x80108474
    // 0x808022C4: nop

    func_80108474(rdram, ctx);
        goto after_1;
    // 0x808022C4: nop

    after_1:
    // 0x808022C8: lhu         $t7, 0x76($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X76);
    // 0x808022CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808022D0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x808022D4: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x808022D8: ori         $t9, $t8, 0x1980
    ctx->r25 = ctx->r24 | 0X1980;
    // 0x808022DC: sh          $t9, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r25;
    // 0x808022E0: lbu         $t0, 0x1CC($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0X1CC);
    // 0x808022E4: bnel        $t0, $zero, L_808022FC
    if (ctx->r8 != 0) {
        // 0x808022E8: addiu       $s1, $s1, 0x18
        ctx->r17 = ADD32(ctx->r17, 0X18);
            goto L_808022FC;
    }
    goto skip_0;
    // 0x808022E8: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    skip_0:
    // 0x808022EC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x808022F0: jal         0x800862E0
    // 0x808022F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chappearfx_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808022F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x808022F8: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
L_808022FC:
    // 0x808022FC: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x80802300: bne         $s1, $s3, L_808022AC
    if (ctx->r17 != ctx->r19) {
        // 0x80802304: addiu       $s2, $s2, 0x18
        ctx->r18 = ADD32(ctx->r18, 0X18);
            goto L_808022AC;
    }
    // 0x80802304: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x80802308: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080230C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80802310: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802314: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80802318: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8080231C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80802320: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80802324: jr          $ra
    // 0x80802328: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80802328: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80800094_chminegrill2switches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080009C: addiu       $a1, $zero, 0xA26
    ctx->r5 = ADD32(0, 0XA26);
    // 0x808000A0: jal         0x80800000
    // 0x808000A4: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    func_80800000_chminegrill2switches(rdram, ctx);
        goto after_0;
    // 0x808000A4: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_0:
    // 0x808000A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000B0: jr          $ra
    // 0x808000B4: nop

    return;
    // 0x808000B4: nop

;}
