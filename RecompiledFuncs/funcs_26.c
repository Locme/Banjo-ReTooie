#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801D50_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D50: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80801D54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801D5C: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x80801D60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801D64: bne         $t6, $zero, L_80801D7C
    if (ctx->r14 != 0) {
        // 0x80801D68: nop
    
            goto L_80801D7C;
    }
    // 0x80801D68: nop

    // 0x80801D6C: jal         0x80800830
    // 0x80801D70: nop

    func_80800830_chhandcart(rdram, ctx);
        goto after_0;
    // 0x80801D70: nop

    after_0:
    // 0x80801D74: b           L_80801FE4
    // 0x80801D78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801FE4;
    // 0x80801D78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801D7C:
    // 0x80801D7C: jal         0x800D8FF8
    // 0x80801D80: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801D80: nop

    after_1:
    // 0x80801D84: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80801D88: jal         0x80106790
    // 0x80801D8C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80801D8C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x80801D90: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80801D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801D98: jal         0x80100094
    // 0x80801D9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80801D9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80801DA0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801DA4: lhu         $t7, 0x72($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X72);
    // 0x80801DA8: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80801DAC: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x80801DB0: sltiu       $at, $t9, 0xE
    ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
    // 0x80801DB4: beq         $at, $zero, L_80801FB4
    if (ctx->r1 == 0) {
        // 0x80801DB8: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80801FB4;
    }
    // 0x80801DB8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80801DBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4498) << 16);
    // 0x80801DC0: addu        $at, $at, $t9
    gpr jr_addend_80801DC8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80801DC4: lw          $t9, 0x4498($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4498));
    // 0x80801DC8: jr          $t9
    // 0x80801DCC: nop

    switch (jr_addend_80801DC8 >> 2) {
        case 0: goto L_80801DD0; break;
        case 1: goto L_80801E10; break;
        case 2: goto L_80801E48; break;
        case 3: goto L_80801F00; break;
        case 4: goto L_80801F10; break;
        case 5: goto L_80801F8C; break;
        case 6: goto L_80801F8C; break;
        case 7: goto L_80801F60; break;
        case 8: goto L_80801F60; break;
        case 9: goto L_80801F60; break;
        case 10: goto L_80801F8C; break;
        case 11: goto L_80801F8C; break;
        case 12: goto L_80801FA4; break;
        case 13: goto L_80801FA4; break;
        default: switch_error(__func__, 0x80801DC8, 0x80804498);
    }
    // 0x80801DCC: nop

L_80801DD0:
    // 0x80801DD0: jal         0x80800830
    // 0x80801DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800830_chhandcart(rdram, ctx);
        goto after_4;
    // 0x80801DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80801DD8: jal         0x80090178
    // 0x80801DDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090178(rdram, ctx);
        goto after_5;
    // 0x80801DDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80801DE0: beq         $v0, $zero, L_80801FB4
    if (ctx->r2 == 0) {
        // 0x80801DE4: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80801FB4;
    }
    // 0x80801DE4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801DE8: jal         0x8010C9B0
    // 0x80801DEC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    func_8010C9B0(rdram, ctx);
        goto after_6;
    // 0x80801DEC: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_6:
    // 0x80801DF0: beql        $v0, $zero, L_80801FB8
    if (ctx->r2 == 0) {
        // 0x80801DF4: lw          $t4, 0x34($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X34);
            goto L_80801FB8;
    }
    goto skip_0;
    // 0x80801DF4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80801DF8: jal         0x800DA544
    // 0x80801DFC: addiu       $a0, $zero, 0x508
    ctx->r4 = ADD32(0, 0X508);
    func_800DA544(rdram, ctx);
        goto after_7;
    // 0x80801DFC: addiu       $a0, $zero, 0x508
    ctx->r4 = ADD32(0, 0X508);
    after_7:
    // 0x80801E00: jal         0x80800214
    // 0x80801E04: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_80800214_chhandcart(rdram, ctx);
        goto after_8;
    // 0x80801E04: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_8:
    // 0x80801E08: b           L_80801FB8
    // 0x80801E0C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_80801FB8;
    // 0x80801E0C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801E10:
    // 0x80801E10: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801E14: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x80801E18: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80801E1C: jal         0x8010CB0C
    // 0x80801E20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8010CB0C(rdram, ctx);
        goto after_9;
    // 0x80801E20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_9:
    // 0x80801E24: beql        $v0, $zero, L_80801FB8
    if (ctx->r2 == 0) {
        // 0x80801E28: lw          $t4, 0x34($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X34);
            goto L_80801FB8;
    }
    goto skip_1;
    // 0x80801E28: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80801E2C: jal         0x800DA544
    // 0x80801E30: addiu       $a0, $zero, 0x508
    ctx->r4 = ADD32(0, 0X508);
    func_800DA544(rdram, ctx);
        goto after_10;
    // 0x80801E30: addiu       $a0, $zero, 0x508
    ctx->r4 = ADD32(0, 0X508);
    after_10:
    // 0x80801E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E38: jal         0x808010D8
    // 0x80801E3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808010D8_chhandcart(rdram, ctx);
        goto after_11;
    // 0x80801E3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
    // 0x80801E40: b           L_80801FB8
    // 0x80801E44: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_80801FB8;
    // 0x80801E44: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801E48:
    // 0x80801E48: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1632, 0X4DB8) << 16);
    // 0x80801E4C: addiu       $t1, $t1, 0x4DB8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1632, 0X4DB8));
    // 0x80801E50: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80801E54: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x80801E58: lw          $t3, 0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X4);
    // 0x80801E5C: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80801E60: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80801E64: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801E68: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80801E6C: jal         0x800907C0
    // 0x80801E70: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    func_800907C0(rdram, ctx);
        goto after_12;
    // 0x80801E70: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    after_12:
    // 0x80801E74: jal         0x80090010
    // 0x80801E78: nop

    func_80090010(rdram, ctx);
        goto after_13;
    // 0x80801E78: nop

    after_13:
    // 0x80801E7C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80801E80: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801E84: jal         0x800F1DCC
    // 0x80801E88: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    func_800F1DCC(rdram, ctx);
        goto after_14;
    // 0x80801E88: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    after_14:
    // 0x80801E8C: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x80801E90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801E94: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80801E98: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80801E9C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80801EA0: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801EA4: bc1t        L_80801EC4
    if (c1cs) {
        // 0x80801EA8: nop
    
            goto L_80801EC4;
    }
    // 0x80801EA8: nop

    // 0x80801EAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801EB0: nop

    // 0x80801EB4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80801EB8: nop

    // 0x80801EBC: bc1f        L_80801EF0
    if (!c1cs) {
        // 0x80801EC0: nop
    
            goto L_80801EF0;
    }
    // 0x80801EC0: nop

L_80801EC4:
    // 0x80801EC4: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80801EC8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80801ECC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801ED0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80801ED4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80801ED8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80801EDC: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80801EE0: jal         0x800906DC
    // 0x80801EE4: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_800906DC(rdram, ctx);
        goto after_15;
    // 0x80801EE4: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x80801EE8: b           L_80801FB8
    // 0x80801EEC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_80801FB8;
    // 0x80801EEC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801EF0:
    // 0x80801EF0: jal         0x80800214
    // 0x80801EF4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_80800214_chhandcart(rdram, ctx);
        goto after_16;
    // 0x80801EF4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_16:
    // 0x80801EF8: b           L_80801FB8
    // 0x80801EFC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_80801FB8;
    // 0x80801EFC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801F00:
    // 0x80801F00: jal         0x8080111C
    // 0x80801F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080111C_chhandcart(rdram, ctx);
        goto after_17;
    // 0x80801F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80801F08: b           L_80801FB8
    // 0x80801F0C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_80801FB8;
    // 0x80801F0C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801F10:
    // 0x80801F10: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801F14: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x80801F18: jal         0x8080115C
    // 0x80801F1C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8080115C_chhandcart(rdram, ctx);
        goto after_18;
    // 0x80801F1C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_18:
    // 0x80801F20: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80801F24: jal         0x80801BA4
    // 0x80801F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801BA4_chhandcart(rdram, ctx);
        goto after_19;
    // 0x80801F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80801F2C: jal         0x8080111C
    // 0x80801F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080111C_chhandcart(rdram, ctx);
        goto after_20;
    // 0x80801F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80801F34: jal         0x80105A5C
    // 0x80801F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_21;
    // 0x80801F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80801F3C: beql        $v0, $zero, L_80801FB8
    if (ctx->r2 == 0) {
        // 0x80801F40: lw          $t4, 0x34($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X34);
            goto L_80801FB8;
    }
    goto skip_2;
    // 0x80801F40: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80801F44: jal         0x80800EA0
    // 0x80801F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800EA0_chhandcart(rdram, ctx);
        goto after_22;
    // 0x80801F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80801F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F50: jal         0x808010D8
    // 0x80801F54: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808010D8_chhandcart(rdram, ctx);
        goto after_23;
    // 0x80801F54: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_23:
    // 0x80801F58: b           L_80801FB8
    // 0x80801F5C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_80801FB8;
    // 0x80801F5C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801F60:
    // 0x80801F60: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801F64: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x80801F68: jal         0x8080115C
    // 0x80801F6C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_8080115C_chhandcart(rdram, ctx);
        goto after_24;
    // 0x80801F6C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_24:
    // 0x80801F70: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80801F74: jal         0x80801BA4
    // 0x80801F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801BA4_chhandcart(rdram, ctx);
        goto after_25;
    // 0x80801F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80801F7C: jal         0x8080111C
    // 0x80801F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080111C_chhandcart(rdram, ctx);
        goto after_26;
    // 0x80801F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80801F84: b           L_80801FB8
    // 0x80801F88: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_80801FB8;
    // 0x80801F88: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801F8C:
    // 0x80801F8C: jal         0x80801CBC
    // 0x80801F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CBC_chhandcart(rdram, ctx);
        goto after_27;
    // 0x80801F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80801F94: jal         0x80801290
    // 0x80801F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801290_chhandcart(rdram, ctx);
        goto after_28;
    // 0x80801F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80801F9C: b           L_80801FB8
    // 0x80801FA0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
        goto L_80801FB8;
    // 0x80801FA0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801FA4:
    // 0x80801FA4: jal         0x80800830
    // 0x80801FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800830_chhandcart(rdram, ctx);
        goto after_29;
    // 0x80801FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80801FAC: jal         0x80801CBC
    // 0x80801FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801CBC_chhandcart(rdram, ctx);
        goto after_30;
    // 0x80801FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
L_80801FB4:
    // 0x80801FB4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
L_80801FB8:
    // 0x80801FB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801FBC: lbu         $v0, 0x8F5($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X8F5);
    // 0x80801FC0: beq         $v0, $at, L_80801FD0
    if (ctx->r2 == ctx->r1) {
        // 0x80801FC4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80801FD0;
    }
    // 0x80801FC4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801FC8: bnel        $v0, $at, L_80801FE4
    if (ctx->r2 != ctx->r1) {
        // 0x80801FCC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801FE4;
    }
    goto skip_3;
    // 0x80801FCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_80801FD0:
    // 0x80801FD0: jal         0x80800B00
    // 0x80801FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B00_chhandcart(rdram, ctx);
        goto after_31;
    // 0x80801FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x80801FD8: jal         0x80800528
    // 0x80801FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800528_chhandcart(rdram, ctx);
        goto after_32;
    // 0x80801FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80801FE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801FE4:
    // 0x80801FE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801FE8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80801FEC: jr          $ra
    // 0x80801FF0: nop

    return;
    // 0x80801FF0: nop

;}
RECOMP_FUNC void func_800D738C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D738C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D7390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D7394: jal         0x800D58FC
    // 0x800D7398: nop

    func_800D58FC(rdram, ctx);
        goto after_0;
    // 0x800D7398: nop

    after_0:
    // 0x800D739C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D73A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D73A4: jr          $ra
    // 0x800D73A8: nop

    return;
    // 0x800D73A8: nop

;}
RECOMP_FUNC void badata_entrypoint_34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800F60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F64: jal         0x80800000
    // 0x80800F68: nop

    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800F68: nop

    after_0:
    // 0x80800F6C: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80800F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F74: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X1490) << 16);
    // 0x80800F78: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800F7C: lh          $v0, 0x1490($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X1490));
    // 0x80800F80: jr          $ra
    // 0x80800F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void choildrill_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080086C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800870: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800874: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2412, 0X13DC) << 16);
    // 0x80800878: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080087C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800880: addiu       $t6, $t6, 0x13DC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2412, 0X13DC));
    // 0x80800884: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080088C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800890: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800894: jal         0x800BBCB8
    // 0x80800898: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x80800898: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8080089C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808008A4: jr          $ra
    // 0x808008A8: nop

    return;
    // 0x808008A8: nop

;}
RECOMP_FUNC void func_800EF030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF030: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800EF034: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF038: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800EF03C: nop

    // 0x800EF040: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800EF044: jr          $ra
    // 0x800EF048: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    return;
    // 0x800EF048: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
;}
RECOMP_FUNC void bsclaw_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8009E474
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009E474(rdram, ctx);
        goto after_0;
    // 0x8080000C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800010: jal         0x800C6DA0
    // 0x80800014: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    func_800C6DA0(rdram, ctx);
        goto after_1;
    // 0x80800014: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    after_1:
    // 0x80800018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080001C: jal         0x80095774
    // 0x80800020: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    baflag_clear(rdram, ctx);
        goto after_2;
    // 0x80800020: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_2:
    // 0x80800024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800028: jal         0x800A0CF4
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A0CF4(rdram, ctx);
        goto after_3;
    // 0x8080002C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_800BA3FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA3FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800BA400: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BA404: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BA408: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x800BA40C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BA410: beql        $a1, $t6, L_800BA440
    if (ctx->r5 == ctx->r14) {
        // 0x800BA414: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800BA440;
    }
    goto skip_0;
    // 0x800BA414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800BA418: sh          $a1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r5;
    // 0x800BA41C: jal         0x800D738C
    // 0x800BA420: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    func_800D738C(rdram, ctx);
        goto after_0;
    // 0x800BA420: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    after_0:
    // 0x800BA424: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    // 0x800BA428: jal         0x800D674C
    // 0x800BA42C: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x800BA42C: lhu         $a0, 0x2($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2);
    after_1:
    // 0x800BA430: jal         0x800AF5A0
    // 0x800BA434: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800AF5A0(rdram, ctx);
        goto after_2;
    // 0x800BA434: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800BA438: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x800BA43C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800BA440:
    // 0x800BA440: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BA444: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800BA448: jr          $ra
    // 0x800BA44C: nop

    return;
    // 0x800BA44C: nop

;}
RECOMP_FUNC void _badeathmatch_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085510: syscall     165
    recomp_syscall_handler(rdram, ctx, 0x80085510);
    return;
    // 0x80085514: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80802130_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802130: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80802134: lw          $t8, 0x78($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X78);
    // 0x80802138: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x8080213C: sra         $a2, $t6, 16
    ctx->r6 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80802140: sll         $t0, $t8, 26
    ctx->r8 = S32(ctx->r24 << 26);
    // 0x80802144: bgezl       $t0, L_80802178
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80802148: mtc1        $a2, $f6
        ctx->f6.u32l = ctx->r6;
            goto L_80802178;
    }
    goto skip_0;
    // 0x80802148: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    skip_0:
    // 0x8080214C: lhu         $v0, 0x76($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X76);
    // 0x80802150: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80802154: srl         $t1, $v0, 7
    ctx->r9 = S32(U32(ctx->r2) >> 7);
    // 0x80802158: beql        $t1, $at, L_80802178
    if (ctx->r9 == ctx->r1) {
        // 0x8080215C: mtc1        $a2, $f6
        ctx->f6.u32l = ctx->r6;
            goto L_80802178;
    }
    goto skip_1;
    // 0x8080215C: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    skip_1:
    // 0x80802160: lbu         $t3, 0x19($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X19);
    // 0x80802164: sh          $t1, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r9;
    // 0x80802168: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x8080216C: jr          $ra
    // 0x80802170: sb          $t4, 0x19($a1)
    MEM_B(0X19, ctx->r5) = ctx->r12;
    return;
    // 0x80802170: sb          $t4, 0x19($a1)
    MEM_B(0X19, ctx->r5) = ctx->r12;
    // 0x80802174: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
L_80802178:
    // 0x80802178: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8080217C: lbu         $t7, 0x19($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X19);
    // 0x80802180: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80802184: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x80802188: sb          $t8, 0x19($a1)
    MEM_B(0X19, ctx->r5) = ctx->r24;
    // 0x8080218C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80802190: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80802194: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80802198: nop

    // 0x8080219C: sh          $t6, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r14;
    // 0x808021A0: jr          $ra
    // 0x808021A4: nop

    return;
    // 0x808021A4: nop

;}
RECOMP_FUNC void bitfield_get_n_bits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9EA0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D9EA4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D9EA8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D9EAC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D9EB0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D9EB4: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800D9EB8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800D9EBC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800D9EC0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D9EC4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D9EC8: blez        $a2, L_800D9EF4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800D9ECC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800D9EF4;
    }
    // 0x800D9ECC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D9ED0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_800D9ED4:
    // 0x800D9ED4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800D9ED8: jal         0x800D9E60
    // 0x800D9EDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bitfield_get_bit(rdram, ctx);
        goto after_0;
    // 0x800D9EDC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800D9EE0: sllv        $t6, $v0, $s0
    ctx->r14 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800D9EE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D9EE8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D9EEC: bne         $s0, $s3, L_800D9ED4
    if (ctx->r16 != ctx->r19) {
        // 0x800D9EF0: or          $s2, $s2, $t6
        ctx->r18 = ctx->r18 | ctx->r14;
            goto L_800D9ED4;
    }
    // 0x800D9EF0: or          $s2, $s2, $t6
    ctx->r18 = ctx->r18 | ctx->r14;
L_800D9EF4:
    // 0x800D9EF4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800D9EF8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800D9EFC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D9F00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D9F04: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9F08: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D9F0C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D9F10: jr          $ra
    // 0x800D9F14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D9F14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void fxleaves_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800474: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800478: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080047C: jal         0x80800288
    // 0x80800480: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80800288_fxleaves(rdram, ctx);
        goto after_0;
    // 0x80800480: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800488: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080048C: jr          $ra
    // 0x80800490: nop

    return;
    // 0x80800490: nop

;}
RECOMP_FUNC void func_808010B0_chfantasyeyeball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010B0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808010B4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x808010B8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x808010BC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x808010C0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x808010C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808010C8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x808010CC: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x808010D0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x808010D4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x808010D8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808010DC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808010E0: jal         0x800DC0C0
    // 0x808010E4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800DC0C0(rdram, ctx);
        goto after_0;
    // 0x808010E4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x808010E8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808010EC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808010F0: nop

    // 0x808010F4: mul.s       $f20, $f0, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x808010F8: jal         0x800DC0C0
    // 0x808010FC: nop

    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x808010FC: nop

    after_1:
    // 0x80801100: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80801104: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801108: add.s       $f24, $f20, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x8080110C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801110: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80801114: addiu       $s2, $s0, 0x4
    ctx->r18 = ADD32(ctx->r16, 0X4);
    // 0x80801118: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x8080111C: addiu       $s0, $sp, 0x54
    ctx->r16 = ADD32(ctx->r29, 0X54);
    // 0x80801120: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801124: addiu       $s3, $sp, 0x64
    ctx->r19 = ADD32(ctx->r29, 0X64);
    // 0x80801128: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8080112C: swc1        $f10, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f10.u32l;
    // 0x80801130: bc1f        L_808011A4
    if (!c1cs) {
        // 0x80801134: swc1        $f20, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f20.u32l;
            goto L_808011A4;
    }
    // 0x80801134: swc1        $f20, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f20.u32l;
    // 0x80801138: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080113C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2400, 0X1E18) << 16);
    // 0x80801140: lwc1        $f20, 0x1E18($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2400, 0X1E18));
    // 0x80801144: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80801148: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_8080114C:
    // 0x8080114C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80801150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801154: jal         0x800EEC30
    // 0x80801158: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    func_800EEC30(rdram, ctx);
        goto after_2;
    // 0x80801158: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    after_2:
    // 0x8080115C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801160: jal         0x800EF04C
    // 0x80801164: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x80801164: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80801168: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080116C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801170: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80801174: jal         0x800BEF00
    // 0x80801178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800BEF00(rdram, ctx);
        goto after_4;
    // 0x80801178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8080117C: beql        $v0, $zero, L_808011A8
    if (ctx->r2 == 0) {
        // 0x80801180: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_808011A8;
    }
    goto skip_0;
    // 0x80801180: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80801184: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80801188: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8080118C: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    // 0x80801190: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80801194: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80801198: nop

    // 0x8080119C: bc1tl       L_8080114C
    if (c1cs) {
        // 0x808011A0: mfc1        $a2, $f0
        ctx->r6 = (int32_t)ctx->f0.u32l;
            goto L_8080114C;
    }
    goto skip_1;
    // 0x808011A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    skip_1:
L_808011A4:
    // 0x808011A4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_808011A8:
    // 0x808011A8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808011AC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x808011B0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808011B4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x808011B8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x808011BC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x808011C0: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x808011C4: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x808011C8: jr          $ra
    // 0x808011CC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x808011CC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800C16A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C16A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C16A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C16AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C16B0: jal         0x800C1414
    // 0x800C16B4: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C16B4: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    after_0:
    // 0x800C16B8: lbu         $t6, 0x79($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X79);
    // 0x800C16BC: beql        $t6, $zero, L_800C16DC
    if (ctx->r14 == 0) {
        // 0x800C16C0: lbu         $t7, 0x23($sp)
        ctx->r15 = MEM_BU(ctx->r29, 0X23);
            goto L_800C16DC;
    }
    goto skip_0;
    // 0x800C16C0: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
    skip_0:
    // 0x800C16C4: lbu         $a0, 0x79($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X79);
    // 0x800C16C8: jal         0x800C1568
    // 0x800C16CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800C1568(rdram, ctx);
        goto after_1;
    // 0x800C16CC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800C16D0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800C16D4: sb          $zero, 0x79($v1)
    MEM_B(0X79, ctx->r3) = 0;
    // 0x800C16D8: lbu         $t7, 0x23($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X23);
L_800C16DC:
    // 0x800C16DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C16E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C16E4: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x800C16E8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800C16EC: sb          $zero, -0x73F8($at)
    MEM_B(-0X73F8, ctx->r1) = 0;
    // 0x800C16F0: jr          $ra
    // 0x800C16F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C16F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800E2C_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E34: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80800E38: addiu       $a0, $zero, 0x175
    ctx->r4 = ADD32(0, 0X175);
    // 0x80800E3C: jal         0x800DA564
    // 0x80800E40: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800DA564(rdram, ctx);
        goto after_0;
    // 0x80800E40: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80800E44: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80800E48: beq         $t6, $zero, L_80800E54
    if (ctx->r14 == 0) {
        // 0x80800E4C: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80800E54;
    }
    // 0x80800E4C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E50: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800E54:
    // 0x80800E54: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x80800E58: beq         $t7, $zero, L_80800E64
    if (ctx->r15 == 0) {
        // 0x80800E5C: andi        $t8, $v0, 0x4
        ctx->r24 = ctx->r2 & 0X4;
            goto L_80800E64;
    }
    // 0x80800E5C: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x80800E60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800E64:
    // 0x80800E64: beq         $t8, $zero, L_80800E70
    if (ctx->r24 == 0) {
        // 0x80800E68: andi        $t9, $v0, 0x8
        ctx->r25 = ctx->r2 & 0X8;
            goto L_80800E70;
    }
    // 0x80800E68: andi        $t9, $v0, 0x8
    ctx->r25 = ctx->r2 & 0X8;
    // 0x80800E6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800E70:
    // 0x80800E70: beq         $t9, $zero, L_80800E7C
    if (ctx->r25 == 0) {
        // 0x80800E74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800E7C;
    }
    // 0x80800E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E78: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80800E7C:
    // 0x80800E7C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800E80: jr          $ra
    // 0x80800E84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800E84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80802198_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080219C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808021A0: jal         0x808021C4
    // 0x808021A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808021C4_chtntmineshoot(rdram, ctx);
        goto after_0;
    // 0x808021A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808021A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808021AC: jal         0x808022A8
    // 0x808021B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808022A8_chtntmineshoot(rdram, ctx);
        goto after_1;
    // 0x808021B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x808021B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808021B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808021BC: jr          $ra
    // 0x808021C0: nop

    return;
    // 0x808021C0: nop

;}
RECOMP_FUNC void func_80800000_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x8009C128
    // 0x8080000C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x8080000C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800010: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800014: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800018: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8080001C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800020: jal         0x800DC178
    // 0x80800024: nop

    func_800DC178(rdram, ctx);
        goto after_1;
    // 0x80800024: nop

    after_1:
    // 0x80800028: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080002C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800030: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800034: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800038: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080003C: jal         0x800DC178
    // 0x80800040: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_800DC178(rdram, ctx);
        goto after_2;
    // 0x80800040: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80800044: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800048: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080004C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800050: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80800054: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80800058: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080005C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80800060: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800064: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80800068: jal         0x800DC178
    // 0x8080006C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x8080006C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80800070: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800074: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(236, 0X1C10) << 16);
    // 0x80800078: addiu       $t6, $t6, 0x1C10
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(236, 0X1C10));
    // 0x8080007C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800080: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800084: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800088: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080008C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80800090: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800094: jal         0x800BBCB8
    // 0x80800098: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800BBCB8(rdram, ctx);
        goto after_4;
    // 0x80800098: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8080009C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000A4: jr          $ra
    // 0x808000A8: nop

    return;
    // 0x808000A8: nop

;}
RECOMP_FUNC void chcoderoombits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F28: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800F2C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800F30: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800F34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800F38: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800F3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800F40: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800F44: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80800F48: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800F4C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80800F50: jal         0x80106790
    // 0x80800F54: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800F54: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x80800F58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F5C: jal         0x80100094
    // 0x80800F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800F64: sll         $t6, $s2, 2
    ctx->r14 = S32(ctx->r18 << 2);
    // 0x80800F68: subu        $t6, $t6, $s2
    ctx->r14 = SUB32(ctx->r14, ctx->r18);
    // 0x80800F6C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800F70: addiu       $s3, $sp, 0x28
    ctx->r19 = ADD32(ctx->r29, 0X28);
    // 0x80800F74: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80800F78: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1172, 0X1318) << 16);
    // 0x80800F7C: addiu       $a2, $a2, 0x1318
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1172, 0X1318));
    // 0x80800F80: lw          $a3, 0x10($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X10);
    // 0x80800F84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800F88: jal         0x800F3320
    // 0x80800F8C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    func_800F3320(rdram, ctx);
        goto after_2;
    // 0x80800F8C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    after_2:
    // 0x80800F90: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80800F94: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800F98: addu        $s2, $t9, $s0
    ctx->r18 = ADD32(ctx->r25, ctx->r16);
    // 0x80800F9C: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80800FA0: beq         $at, $zero, L_80800FC0
    if (ctx->r1 == 0) {
        // 0x80800FA4: addiu       $a0, $s1, 0xC
        ctx->r4 = ADD32(ctx->r17, 0XC);
            goto L_80800FC0;
    }
L_80800FA4:
    // 0x80800FA4: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // 0x80800FA8: jal         0x800F2EA0
    // 0x80800FAC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800F2EA0(rdram, ctx);
        goto after_3;
    // 0x80800FAC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x80800FB0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800FB4: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80800FB8: bne         $at, $zero, L_80800FA4
    if (ctx->r1 != 0) {
        // 0x80800FBC: addiu       $s1, $s1, 0x10
        ctx->r17 = ADD32(ctx->r17, 0X10);
            goto L_80800FA4;
    }
    // 0x80800FBC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
L_80800FC0:
    // 0x80800FC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800FC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800FC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800FCC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800FD0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800FD4: jr          $ra
    // 0x80800FD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80800FD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void _chscreenadjust_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B78: syscall     201
    recomp_syscall_handler(rdram, ctx, 0x80085B78);
    return;
    // 0x80085B7C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800000_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080000C: jal         0x80085160
    // 0x80800010: addiu       $a1, $zero, 0x2A8
    ctx->r5 = ADD32(0, 0X2A8);
    _bastatemem_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a1, $zero, 0x2A8
    ctx->r5 = ADD32(0, 0X2A8);
    after_0:
    // 0x80800014: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800018: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080001C: addiu       $a2, $zero, 0x2A8
    ctx->r6 = ADD32(0, 0X2A8);
    // 0x80800020: lw          $a0, 0x188($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X188);
    // 0x80800024: jal         0x80019E98
    // 0x80800028: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    aligned8_memset(rdram, ctx);
        goto after_1;
    // 0x80800028: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800034: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void func_80102F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102F14: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80102F18: sll         $t8, $t6, 13
    ctx->r24 = S32(ctx->r14 << 13);
    // 0x80102F1C: bgezl       $t8, L_80102F30
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80102F20: lbu         $t0, 0x75($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X75);
            goto L_80102F30;
    }
    goto skip_0;
    // 0x80102F20: lbu         $t0, 0x75($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X75);
    skip_0:
    // 0x80102F24: jr          $ra
    // 0x80102F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80102F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80102F2C: lbu         $t0, 0x75($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X75);
L_80102F30:
    // 0x80102F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80102F34: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x80102F38: sb          $t1, 0x75($a0)
    MEM_B(0X75, ctx->r4) = ctx->r9;
    // 0x80102F3C: jr          $ra
    // 0x80102F40: nop

    return;
    // 0x80102F40: nop

;}
RECOMP_FUNC void func_808004C8_chtoxicroombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808004CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808004D0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x808004D4: addiu       $a0, $zero, 0x6DF
    ctx->r4 = ADD32(0, 0X6DF);
    // 0x808004D8: jal         0x800DA7A8
    // 0x808004DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_0;
    // 0x808004DC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x808004E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808004E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808004E8: jr          $ra
    // 0x808004EC: nop

    return;
    // 0x808004EC: nop

;}
RECOMP_FUNC void func_80800000_chminelight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800004: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800008: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: bne         $a1, $at, L_808000FC
    if (ctx->r5 != ctx->r1) {
        // 0x80800018: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_808000FC;
    }
    // 0x80800018: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8080001C: jal         0x80088F08
    // 0x80800020: addiu       $a0, $zero, 0x1AA
    ctx->r4 = ADD32(0, 0X1AA);
    _idworld_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a0, $zero, 0x1AA
    ctx->r4 = ADD32(0, 0X1AA);
    after_0:
    // 0x80800024: beq         $v0, $zero, L_808000A0
    if (ctx->r2 == 0) {
        // 0x80800028: sw          $v0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r2;
            goto L_808000A0;
    }
    // 0x80800028: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8080002C: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800030: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800034: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80800038: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8080003C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80800040: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80800044: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80800048: lwc1        $f10, 0x30($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8080004C: jal         0x800BEA88
    // 0x80800050: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    func_800BEA88(rdram, ctx);
        goto after_1;
    // 0x80800050: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80800054: beq         $v0, $zero, L_8080006C
    if (ctx->r2 == 0) {
        // 0x80800058: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080006C;
    }
    // 0x80800058: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080005C: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x80800060: addiu       $a2, $zero, 0x1AA
    ctx->r6 = ADD32(0, 0X1AA);
    // 0x80800064: jal         0x80088F28
    // 0x80800068: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800068: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
L_8080006C:
    // 0x8080006C: jal         0x800BEA88
    // 0x80800070: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEA88(rdram, ctx);
        goto after_3;
    // 0x80800070: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800074: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x80800078: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080008C;
    }
    // 0x80800078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080007C: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    // 0x80800080: addiu       $a2, $zero, 0x1AA
    ctx->r6 = ADD32(0, 0X1AA);
    // 0x80800084: jal         0x80088F28
    // 0x80800088: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _idworldmake_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800088: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
L_8080008C:
    // 0x8080008C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800090: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800094: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800098: jal         0x800EDDDC
    // 0x8080009C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800EDDDC(rdram, ctx);
        goto after_5;
    // 0x8080009C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
L_808000A0:
    // 0x808000A0: jal         0x80088840
    // 0x808000A4: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_6;
    // 0x808000A4: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_6:
    // 0x808000A8: beql        $v0, $zero, L_80800108
    if (ctx->r2 == 0) {
        // 0x808000AC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800108;
    }
    goto skip_0;
    // 0x808000AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808000B0: jal         0x800DA298
    // 0x808000B4: addiu       $a0, $zero, 0x9E0
    ctx->r4 = ADD32(0, 0X9E0);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808000B4: addiu       $a0, $zero, 0x9E0
    ctx->r4 = ADD32(0, 0X9E0);
    after_7:
    // 0x808000B8: beq         $v0, $zero, L_808000DC
    if (ctx->r2 == 0) {
        // 0x808000BC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808000DC;
    }
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808000CC: jal         0x80085708
    // 0x808000D0: addiu       $a3, $zero, 0x6910
    ctx->r7 = ADD32(0, 0X6910);
    _capod_entrypoint_13(rdram, ctx);
        goto after_8;
    // 0x808000D0: addiu       $a3, $zero, 0x6910
    ctx->r7 = ADD32(0, 0X6910);
    after_8:
    // 0x808000D4: b           L_808000F0
    // 0x808000D8: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
        goto L_808000F0;
    // 0x808000D8: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
L_808000DC:
    // 0x808000DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808000E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808000E4: jal         0x80085708
    // 0x808000E8: addiu       $a3, $zero, 0x6910
    ctx->r7 = ADD32(0, 0X6910);
    _capod_entrypoint_13(rdram, ctx);
        goto after_9;
    // 0x808000E8: addiu       $a3, $zero, 0x6910
    ctx->r7 = ADD32(0, 0X6910);
    after_9:
    // 0x808000EC: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
L_808000F0:
    // 0x808000F0: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x808000F4: b           L_80800104
    // 0x808000F8: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
        goto L_80800104;
    // 0x808000F8: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
L_808000FC:
    // 0x808000FC: b           L_80800108
    // 0x80800100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800108;
    // 0x80800100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800104:
    // 0x80800104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800108:
    // 0x80800108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080010C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800110: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800114: jr          $ra
    // 0x80800118: nop

    return;
    // 0x80800118: nop

;}
RECOMP_FUNC void func_80800248_bsbflap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800248: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8080024C: lwc1        $f4, 0x16C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X16C);
    // 0x80800250: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800254: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80800258: nop

    // 0x8080025C: bc1f        L_80800268
    if (!c1cs) {
        // 0x80800260: nop
    
            goto L_80800268;
    }
    // 0x80800260: nop

    // 0x80800264: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800268:
    // 0x80800268: beq         $v0, $zero, L_8080028C
    if (ctx->r2 == 0) {
        // 0x8080026C: nop
    
            goto L_8080028C;
    }
    // 0x8080026C: nop

    // 0x80800270: lwc1        $f6, 0x170($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X170);
    // 0x80800274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800278: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x8080027C: nop

    // 0x80800280: bc1f        L_8080028C
    if (!c1cs) {
        // 0x80800284: nop
    
            goto L_8080028C;
    }
    // 0x80800284: nop

    // 0x80800288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080028C:
    // 0x8080028C: jr          $ra
    // 0x80800290: nop

    return;
    // 0x80800290: nop

;}
RECOMP_FUNC void func_800F6690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6690: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6698: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F669C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F66A0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F66A4: jal         0x80092EB0
    // 0x800F66A8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80092EB0(rdram, ctx);
        goto after_0;
    // 0x800F66A8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F66AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F66B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F66B4: jr          $ra
    // 0x800F66B8: nop

    return;
    // 0x800F66B8: nop

;}
RECOMP_FUNC void func_800A89F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A89F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A89FC: jr          $ra
    // 0x800A8A00: lw          $v0, 0x7674($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7674);
    return;
    // 0x800A8A00: lw          $v0, 0x7674($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7674);
;}
RECOMP_FUNC void func_800B3BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3BDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B3BE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B3BE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800B3BE8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800B3BEC: lh          $a1, 0x0($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X0);
    // 0x800B3BF0: jal         0x800B39D0
    // 0x800B3BF4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_800B39D0(rdram, ctx);
        goto after_0;
    // 0x800B3BF4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x800B3BF8: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x800B3BFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B3C00: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800B3C04: bne         $t6, $at, L_800B3C18
    if (ctx->r14 != ctx->r1) {
        // 0x800B3C08: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800B3C18;
    }
    // 0x800B3C08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800B3C0C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800B3C10: b           L_800B3C2C
    // 0x800B3C14: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
        goto L_800B3C2C;
    // 0x800B3C14: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
L_800B3C18:
    // 0x800B3C18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800B3C1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800B3C20: jal         0x800B3B8C
    // 0x800B3C24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800B3B8C(rdram, ctx);
        goto after_1;
    // 0x800B3C24: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800B3C28: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_800B3C2C:
    // 0x800B3C2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3C30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B3C34: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800B3C38: jr          $ra
    // 0x800B3C3C: nop

    return;
    // 0x800B3C3C: nop

;}
RECOMP_FUNC void chminegrill2switches_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2056, 0X150) << 16);
    // 0x808000E4: jr          $ra
    // 0x808000E8: addiu       $v0, $v0, 0x150
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2056, 0X150));
    return;
    // 0x808000E8: addiu       $v0, $v0, 0x150
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2056, 0X150));
;}
RECOMP_FUNC void func_80800038_chjrinnlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080003C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800040: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080004C: bne         $a1, $at, L_808000BC
    if (ctx->r5 != ctx->r1) {
        // 0x80800050: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808000BC;
    }
    // 0x80800050: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800054: jal         0x800DA298
    // 0x80800058: addiu       $a0, $zero, 0x3A9
    ctx->r4 = ADD32(0, 0X3A9);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800058: addiu       $a0, $zero, 0x3A9
    ctx->r4 = ADD32(0, 0X3A9);
    after_0:
    // 0x8080005C: beq         $v0, $zero, L_808000B4
    if (ctx->r2 == 0) {
        // 0x80800060: nop
    
            goto L_808000B4;
    }
    // 0x80800060: nop

    // 0x80800064: jal         0x800C8A98
    // 0x80800068: nop

    func_800C8A98(rdram, ctx);
        goto after_1;
    // 0x80800068: nop

    after_1:
    // 0x8080006C: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x80800070: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800074: jal         0x800C8CB8
    // 0x80800078: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C8CB8(rdram, ctx);
        goto after_2;
    // 0x80800078: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x8080007C: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    // 0x80800080: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80800084: jal         0x800C8E54
    // 0x80800088: lui         $a2, 0x442F
    ctx->r6 = S32(0X442F << 16);
    func_800C8E54(rdram, ctx);
        goto after_3;
    // 0x80800088: lui         $a2, 0x442F
    ctx->r6 = S32(0X442F << 16);
    after_3:
    // 0x8080008C: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    // 0x80800090: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80800094: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80800098: jal         0x800C8FB0
    // 0x8080009C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    func_800C8FB0(rdram, ctx);
        goto after_4;
    // 0x8080009C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x808000A0: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    // 0x808000A4: jal         0x800C8F64
    // 0x808000A8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_800C8F64(rdram, ctx);
        goto after_5;
    // 0x808000A8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_5:
    // 0x808000AC: b           L_808000C8
    // 0x808000B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000C8;
    // 0x808000B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000B4:
    // 0x808000B4: b           L_808000C4
    // 0x808000B8: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
        goto L_808000C4;
    // 0x808000B8: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
L_808000BC:
    // 0x808000BC: b           L_808000C8
    // 0x808000C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000C8;
    // 0x808000C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000C4:
    // 0x808000C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C8:
    // 0x808000C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void _basnowball_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850F8: syscall     151
    recomp_syscall_handler(rdram, ctx, 0x800850F8);
    return;
    // 0x800850FC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8080012C_chswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080012C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800130: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800134: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800138: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080013C: jal         0x80106790
    // 0x80800140: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800140: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800144: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800148: jal         0x8008FCC8
    // 0x8080014C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008FCC8(rdram, ctx);
        goto after_1;
    // 0x8080014C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800150: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800154: bnel        $v0, $v1, L_8080019C
    if (ctx->r2 != ctx->r3) {
        // 0x80800158: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080019C;
    }
    goto skip_0;
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080015C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800160: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800164: bnel        $v1, $t7, L_8080019C
    if (ctx->r3 != ctx->r15) {
        // 0x80800168: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080019C;
    }
    goto skip_1;
    // 0x80800168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080016C: jal         0x800880D0
    // 0x80800170: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_2;
    // 0x80800170: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: jal         0x80102424
    // 0x8080017C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x8080017C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800180: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800184: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800188: lhu         $t9, 0x1A($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X1A);
    // 0x8080018C: srl         $a0, $t9, 5
    ctx->r4 = S32(U32(ctx->r25) >> 5);
    // 0x80800190: jal         0x800F7F98
    // 0x80800194: sw          $a0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r4;
    func_800F7F98(rdram, ctx);
        goto after_4;
    // 0x80800194: sw          $a0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r4;
    after_4:
    // 0x80800198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080019C:
    // 0x8080019C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001A4: jr          $ra
    // 0x808001A8: nop

    return;
    // 0x808001A8: nop

;}
RECOMP_FUNC void func_808001B0_bsbansack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x808001BC: jal         0x80800100
    // 0x808001C0: addiu       $a1, $a1, -0x6558
    ctx->r5 = ADD32(ctx->r5, -0X6558);
    func_80800100_bsbansack(rdram, ctx);
        goto after_0;
    // 0x808001C0: addiu       $a1, $a1, -0x6558
    ctx->r5 = ADD32(ctx->r5, -0X6558);
    after_0:
    // 0x808001C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001CC: jr          $ra
    // 0x808001D0: nop

    return;
    // 0x808001D0: nop

;}
RECOMP_FUNC void _basub_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085198: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x80085198);
    return;
    // 0x8008519C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_8009F354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F354: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009F358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F35C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8009F360: jal         0x80095738
    // 0x8009F364: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x8009F364: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x8009F368: beq         $v0, $zero, L_8009F378
    if (ctx->r2 == 0) {
        // 0x8009F36C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8009F378;
    }
    // 0x8009F36C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8009F370: b           L_8009F3AC
    // 0x8009F374: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009F3AC;
    // 0x8009F374: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009F378:
    // 0x8009F378: jal         0x80095760
    // 0x8009F37C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_set(rdram, ctx);
        goto after_1;
    // 0x8009F37C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x8009F380: jal         0x80084700
    // 0x8009F384: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _badata_entrypoint_24(rdram, ctx);
        goto after_2;
    // 0x8009F384: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8009F388: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8009F38C: jal         0x8009E6F8
    // 0x8009F390: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    bs_getCurrentState(rdram, ctx);
        goto after_3;
    // 0x8009F390: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8009F394: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8009F398: beql        $v0, $v1, L_8009F3AC
    if (ctx->r2 == ctx->r3) {
        // 0x8009F39C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8009F3AC;
    }
    goto skip_0;
    // 0x8009F39C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8009F3A0: b           L_8009F3AC
    // 0x8009F3A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8009F3AC;
    // 0x8009F3A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8009F3A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009F3AC:
    // 0x8009F3AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F3B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009F3B4: jr          $ra
    // 0x8009F3B8: nop

    return;
    // 0x8009F3B8: nop

;}
RECOMP_FUNC void func_80800180_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800188: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080018C: jal         0x80102424
    // 0x80800190: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80800190: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800194: jal         0x801022E4
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801022E4(rdram, ctx);
        goto after_1;
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080019C: beql        $v0, $zero, L_808001B8
    if (ctx->r2 == 0) {
        // 0x808001A0: lbu         $t9, 0x65($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X65);
            goto L_808001B8;
    }
    goto skip_0;
    // 0x808001A0: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    skip_0:
    // 0x808001A4: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x808001A8: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x808001AC: b           L_808001C0
    // 0x808001B0: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
        goto L_808001C0;
    // 0x808001B0: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x808001B4: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
L_808001B8:
    // 0x808001B8: andi        $t0, $t9, 0xFFFE
    ctx->r8 = ctx->r25 & 0XFFFE;
    // 0x808001BC: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
L_808001C0:
    // 0x808001C0: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x808001C4: beql        $t1, $zero, L_808001F0
    if (ctx->r9 == 0) {
        // 0x808001C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808001F0;
    }
    goto skip_1;
    // 0x808001C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808001CC: jal         0x80802228
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001D4: lhu         $a2, 0x64($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X64);
    // 0x808001D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001DC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x808001E0: andi        $t2, $a2, 0x1
    ctx->r10 = ctx->r6 & 0X1;
    // 0x808001E4: jal         0x808008C0
    // 0x808001E8: sltiu       $a2, $t2, 0x1
    ctx->r6 = ctx->r10 < 0X1 ? 1 : 0;
    func_808008C0_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x808001E8: sltiu       $a2, $t2, 0x1
    ctx->r6 = ctx->r10 < 0X1 ? 1 : 0;
    after_3:
    // 0x808001EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001F0:
    // 0x808001F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808001F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void func_80106730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106730: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80106734: lw          $a0, 0x6EE0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6EE0);
    // 0x80106738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010673C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106740: bne         $a0, $zero, L_80106750
    if (ctx->r4 != 0) {
        // 0x80106744: nop
    
            goto L_80106750;
    }
    // 0x80106744: nop

    // 0x80106748: b           L_80106758
    // 0x8010674C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80106758;
    // 0x8010674C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80106750:
    // 0x80106750: jal         0x800B2928
    // 0x80106754: nop

    vector_size(rdram, ctx);
        goto after_0;
    // 0x80106754: nop

    after_0:
L_80106758:
    // 0x80106758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010675C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80106760: jr          $ra
    // 0x80106764: nop

    return;
    // 0x80106764: nop

;}
RECOMP_FUNC void func_80102FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102FA0: sll         $t6, $a1, 0
    ctx->r14 = S32(ctx->r5 << 0);
    // 0x80102FA4: bgez        $t6, L_80102FB4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80102FA8: lui         $at, 0x7FFF
        ctx->r1 = S32(0X7FFF << 16);
            goto L_80102FB4;
    }
    // 0x80102FA8: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x80102FAC: b           L_80102FB8
    // 0x80102FB0: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
        goto L_80102FB8;
    // 0x80102FB0: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
L_80102FB4:
    // 0x80102FB4: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
L_80102FB8:
    // 0x80102FB8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80102FBC: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80102FC0: and         $t8, $t7, $a1
    ctx->r24 = ctx->r15 & ctx->r5;
    // 0x80102FC4: beq         $t8, $zero, L_80102FD4
    if (ctx->r24 == 0) {
        // 0x80102FC8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80102FD4;
    }
    // 0x80102FC8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80102FCC: jr          $ra
    // 0x80102FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80102FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80102FD4:
    // 0x80102FD4: jr          $ra
    // 0x80102FD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80102FD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void _bashoes_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FF8: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80084FF8);
    return;
    // 0x80084FFC: xori        $t0, $zero, 0x10
    ctx->r8 = 0 ^ 0X10;
;}
RECOMP_FUNC void func_80803C60_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803C68: jal         0x800FC660
    // 0x80803C6C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    func_800FC660(rdram, ctx);
        goto after_0;
    // 0x80803C6C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_0:
    // 0x80803C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803C74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803C78: jr          $ra
    // 0x80803C7C: nop

    return;
    // 0x80803C7C: nop

;}
RECOMP_FUNC void gczoombox_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801DF4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80801DF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801DFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801E00: beq         $a0, $zero, L_80802B80
    if (ctx->r4 == 0) {
        // 0x80801E04: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80802B80;
    }
    // 0x80801E04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801E08: lw          $t6, 0x1E4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E4);
    // 0x80801E0C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80801E10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801E14: sll         $t8, $t6, 21
    ctx->r24 = S32(ctx->r14 << 21);
    // 0x80801E18: bltz        $t8, L_80801E64
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801E1C: nop
    
            goto L_80801E64;
    }
    // 0x80801E1C: nop

    // 0x80801E20: jal         0x80015E80
    // 0x80801E24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80015E80(rdram, ctx);
        goto after_0;
    // 0x80801E24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80801E28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801E2C: jal         0x80015F28
    // 0x80801E30: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80015F28(rdram, ctx);
        goto after_1;
    // 0x80801E30: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x80801E34: lw          $t9, 0x1E4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E4);
    // 0x80801E38: sll         $t1, $t9, 30
    ctx->r9 = S32(ctx->r25 << 30);
    // 0x80801E3C: bgez        $t1, L_80801E54
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80801E40: nop
    
            goto L_80801E54;
    }
    // 0x80801E40: nop

    // 0x80801E44: jal         0x800885F8
    // 0x80801E48: nop

    _glintrosyncDll_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80801E48: nop

    after_2:
    // 0x80801E4C: b           L_80801E84
    // 0x80801E50: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
        goto L_80801E84;
    // 0x80801E50: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
L_80801E54:
    // 0x80801E54: jal         0x800D8FF8
    // 0x80801E58: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x80801E58: nop

    after_3:
    // 0x80801E5C: b           L_80801E84
    // 0x80801E60: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
        goto L_80801E84;
    // 0x80801E60: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
L_80801E64:
    // 0x80801E64: jal         0x80015ECC
    // 0x80801E68: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    func_80015ECC(rdram, ctx);
        goto after_4;
    // 0x80801E68: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    after_4:
    // 0x80801E6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801E70: jal         0x80015F5C
    // 0x80801E74: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    func_80015F5C(rdram, ctx);
        goto after_5;
    // 0x80801E74: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_5:
    // 0x80801E78: jal         0x800D9004
    // 0x80801E7C: nop

    func_800D9004(rdram, ctx);
        goto after_6;
    // 0x80801E7C: nop

    after_6:
    // 0x80801E80: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
L_80801E84:
    // 0x80801E84: lbu         $t2, 0x171($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X171);
    // 0x80801E88: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80801E8C: sltiu       $at, $t3, 0xB
    ctx->r1 = ctx->r11 < 0XB ? 1 : 0;
    // 0x80801E90: beq         $at, $zero, L_80802B80
    if (ctx->r1 == 0) {
        // 0x80801E94: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80802B80;
    }
    // 0x80801E94: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80801E98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3DE0) << 16);
    // 0x80801E9C: addu        $at, $at, $t3
    gpr jr_addend_80801EA4 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80801EA0: lw          $t3, 0x3DE0($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3DE0));
    // 0x80801EA4: jr          $t3
    // 0x80801EA8: nop

    switch (jr_addend_80801EA4 >> 2) {
        case 0: goto L_80801EAC; break;
        case 1: goto L_8080204C; break;
        case 2: goto L_808022A0; break;
        case 3: goto L_80802324; break;
        case 4: goto L_80802590; break;
        case 5: goto L_80802718; break;
        case 6: goto L_80802890; break;
        case 7: goto L_808028AC; break;
        case 8: goto L_80802A10; break;
        case 9: goto L_80802538; break;
        case 10: goto L_80802B68; break;
        default: switch_error(__func__, 0x80801EA4, 0x80803DE0);
    }
    // 0x80801EA8: nop

L_80801EAC:
    // 0x80801EAC: lbu         $t4, 0x19D($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X19D);
    // 0x80801EB0: beql        $t4, $zero, L_80801ED4
    if (ctx->r12 == 0) {
        // 0x80801EB4: lbu         $t9, 0x175($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0X175);
            goto L_80801ED4;
    }
    goto skip_0;
    // 0x80801EB4: lbu         $t9, 0x175($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X175);
    skip_0:
    // 0x80801EB8: lw          $t5, 0x1A0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1A0);
    // 0x80801EBC: lbu         $t6, 0x19C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X19C);
    // 0x80801EC0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80801EC4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80801EC8: b           L_80801F00
    // 0x80801ECC: sw          $t8, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->r24;
        goto L_80801F00;
    // 0x80801ECC: sw          $t8, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->r24;
    // 0x80801ED0: lbu         $t9, 0x175($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X175);
L_80801ED4:
    // 0x80801ED4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80801ED8: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80801EDC: lw          $a0, 0x17C($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X17C);
    // 0x80801EE0: jal         0x80088738
    // 0x80801EE4: sw          $a0, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->r4;
    _gldialog_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x80801EE4: sw          $a0, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->r4;
    after_7:
    // 0x80801EE8: lbu         $t6, 0x1E5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1E5);
    // 0x80801EEC: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x80801EF0: andi        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 & 0X8;
    // 0x80801EF4: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x80801EF8: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80801EFC: sb          $t8, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r24;
L_80801F00:
    // 0x80801F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F04: jal         0x80801C0C
    // 0x80801F08: lw          $a1, 0x1A0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1A0);
    func_80801C0C_gczoombox(rdram, ctx);
        goto after_8;
    // 0x80801F08: lw          $a1, 0x1A0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1A0);
    after_8:
    // 0x80801F0C: lw          $t9, 0x1A0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1A0);
    // 0x80801F10: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x80801F14: sb          $v0, 0x19C($s0)
    MEM_B(0X19C, ctx->r16) = ctx->r2;
    // 0x80801F18: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80801F1C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80801F20: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80801F24: addiu       $a1, $s0, 0xC0
    ctx->r5 = ADD32(ctx->r16, 0XC0);
    // 0x80801F28: beq         $t2, $zero, L_80801F38
    if (ctx->r10 == 0) {
        // 0x80801F2C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80801F38;
    }
    // 0x80801F2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801F30: b           L_80801F3C
    // 0x80801F34: sb          $t3, 0x19D($s0)
    MEM_B(0X19D, ctx->r16) = ctx->r11;
        goto L_80801F3C;
    // 0x80801F34: sb          $t3, 0x19D($s0)
    MEM_B(0X19D, ctx->r16) = ctx->r11;
L_80801F38:
    // 0x80801F38: sb          $zero, 0x19D($s0)
    MEM_B(0X19D, ctx->r16) = 0;
L_80801F3C:
    // 0x80801F3C: lw          $a0, 0x1A0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1A0);
    // 0x80801F40: jal         0x8080014C
    // 0x80801F44: lbu         $a3, 0x19C($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X19C);
    func_8080014C_gczoombox(rdram, ctx);
        goto after_9;
    // 0x80801F44: lbu         $a3, 0x19C($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X19C);
    after_9:
    // 0x80801F48: lbu         $t4, 0x19C($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X19C);
    // 0x80801F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F50: addu        $t6, $s0, $t4
    ctx->r14 = ADD32(ctx->r16, ctx->r12);
    // 0x80801F54: sb          $zero, 0xC0($t6)
    MEM_B(0XC0, ctx->r14) = 0;
    // 0x80801F58: lbu         $v0, 0x19D($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X19D);
    // 0x80801F5C: bne         $v0, $zero, L_80801F74
    if (ctx->r2 != 0) {
        // 0x80801F60: nop
    
            goto L_80801F74;
    }
    // 0x80801F60: nop

    // 0x80801F64: lbu         $t5, 0x175($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X175);
    // 0x80801F68: lbu         $v0, 0x19D($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X19D);
    // 0x80801F6C: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80801F70: sb          $t7, 0x175($s0)
    MEM_B(0X175, ctx->r16) = ctx->r15;
L_80801F74:
    // 0x80801F74: bnel        $v0, $zero, L_80801F94
    if (ctx->r2 != 0) {
        // 0x80801F78: lbu         $t0, 0x1E4($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X1E4);
            goto L_80801F94;
    }
    goto skip_1;
    // 0x80801F78: lbu         $t0, 0x1E4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1E4);
    skip_1:
    // 0x80801F7C: lbu         $t8, 0x175($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X175);
    // 0x80801F80: lbu         $t9, 0x174($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X174);
    // 0x80801F84: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80801F88: beql        $at, $zero, L_80801FAC
    if (ctx->r1 == 0) {
        // 0x80801F8C: lbu         $t6, 0x1E4($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X1E4);
            goto L_80801FAC;
    }
    goto skip_2;
    // 0x80801F8C: lbu         $t6, 0x1E4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1E4);
    skip_2:
    // 0x80801F90: lbu         $t0, 0x1E4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1E4);
L_80801F94:
    // 0x80801F94: andi        $t2, $t0, 0xFFFD
    ctx->r10 = ctx->r8 & 0XFFFD;
    // 0x80801F98: sb          $t2, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r10;
    // 0x80801F9C: andi        $t3, $t2, 0x7F
    ctx->r11 = ctx->r10 & 0X7F;
    // 0x80801FA0: b           L_80801FBC
    // 0x80801FA4: sb          $t3, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r11;
        goto L_80801FBC;
    // 0x80801FA4: sb          $t3, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r11;
    // 0x80801FA8: lbu         $t6, 0x1E4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1E4);
L_80801FAC:
    // 0x80801FAC: ori         $t8, $t6, 0x2
    ctx->r24 = ctx->r14 | 0X2;
    // 0x80801FB0: sb          $t8, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r24;
    // 0x80801FB4: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x80801FB8: sb          $t9, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r25;
L_80801FBC:
    // 0x80801FBC: lw          $t0, 0x1E4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1E4);
    // 0x80801FC0: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x80801FC4: bgezl       $t2, L_80801FF0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80801FC8: lbu         $t1, 0x1E4($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X1E4);
            goto L_80801FF0;
    }
    goto skip_3;
    // 0x80801FC8: lbu         $t1, 0x1E4($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1E4);
    skip_3:
    // 0x80801FCC: lbu         $t4, 0x1E4($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1E4);
    // 0x80801FD0: ori         $t7, $t4, 0x4
    ctx->r15 = ctx->r12 | 0X4;
    // 0x80801FD4: ori         $t9, $t7, 0x40
    ctx->r25 = ctx->r15 | 0X40;
    // 0x80801FD8: sb          $t7, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r15;
    // 0x80801FDC: sb          $t9, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r25;
    // 0x80801FE0: andi        $t0, $t9, 0xDF
    ctx->r8 = ctx->r25 & 0XDF;
    // 0x80801FE4: b           L_80801FF8
    // 0x80801FE8: sb          $t0, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r8;
        goto L_80801FF8;
    // 0x80801FE8: sb          $t0, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r8;
    // 0x80801FEC: lbu         $t1, 0x1E4($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1E4);
L_80801FF0:
    // 0x80801FF0: andi        $t2, $t1, 0xFFFB
    ctx->r10 = ctx->r9 & 0XFFFB;
    // 0x80801FF4: sb          $t2, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r10;
L_80801FF8:
    // 0x80801FF8: jal         0x808006E0
    // 0x80801FFC: lbu         $a1, 0x19C($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X19C);
    func_808006E0_gczoombox(rdram, ctx);
        goto after_10;
    // 0x80801FFC: lbu         $a1, 0x19C($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X19C);
    after_10:
    // 0x80802000: lw          $t4, 0x1E4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E4);
    // 0x80802004: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80802008: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8080200C: andi        $a3, $zero, 0xFF
    ctx->r7 = 0 & 0XFF;
    // 0x80802010: sll         $t5, $t4, 12
    ctx->r13 = S32(ctx->r12 << 12);
    // 0x80802014: sb          $t3, 0x171($s0)
    MEM_B(0X171, ctx->r16) = ctx->r11;
    // 0x80802018: sb          $a3, 0x1CE($s0)
    MEM_B(0X1CE, ctx->r16) = ctx->r7;
    // 0x8080201C: sb          $zero, 0x19E($s0)
    MEM_B(0X19E, ctx->r16) = 0;
    // 0x80802020: bgez        $t5, L_80802030
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80802024: swc1        $f4, 0x1D4($s0)
        MEM_W(0X1D4, ctx->r16) = ctx->f4.u32l;
            goto L_80802030;
    }
    // 0x80802024: swc1        $f4, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = ctx->f4.u32l;
    // 0x80802028: addiu       $t7, $a3, 0x2
    ctx->r15 = ADD32(ctx->r7, 0X2);
    // 0x8080202C: sb          $t7, 0x19E($s0)
    MEM_B(0X19E, ctx->r16) = ctx->r15;
L_80802030:
    // 0x80802030: lbu         $t9, 0x1E5($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1E5);
    // 0x80802034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802038: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x8080203C: jal         0x80800294
    // 0x80802040: sb          $t0, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r8;
    func_80800294_gczoombox(rdram, ctx);
        goto after_11;
    // 0x80802040: sb          $t0, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r8;
    after_11:
    // 0x80802044: b           L_80802B84
    // 0x80802048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B84;
    // 0x80802048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080204C:
    // 0x8080204C: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    // 0x80802050: lwc1        $f2, 0x1D8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1D8);
    // 0x80802054: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80802058: sll         $t2, $v0, 12
    ctx->r10 = S32(ctx->r2 << 12);
    // 0x8080205C: bgez        $t2, L_80802074
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80802060: sll         $t4, $v0, 27
        ctx->r12 = S32(ctx->r2 << 27);
            goto L_80802074;
    }
    // 0x80802060: sll         $t4, $v0, 27
    ctx->r12 = S32(ctx->r2 << 27);
    // 0x80802064: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80802068: nop

    // 0x8080206C: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80802070: nop

L_80802074:
    // 0x80802074: bgez        $t4, L_80802098
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80802078: lw          $t7, 0x50($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X50);
            goto L_80802098;
    }
    // 0x80802078: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8080207C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3E0C) << 16);
    // 0x80802080: lwc1        $f8, 0x3E0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3E0C));
    // 0x80802084: lbu         $t6, 0x1E7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1E7);
    // 0x80802088: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8080208C: andi        $t5, $t6, 0xFFEF
    ctx->r13 = ctx->r14 & 0XFFEF;
    // 0x80802090: b           L_808020E0
    // 0x80802094: sb          $t5, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r13;
        goto L_808020E0;
    // 0x80802094: sb          $t5, 0x1E7($s0)
    MEM_B(0X1E7, ctx->r16) = ctx->r13;
L_80802098:
    // 0x80802098: beq         $t7, $zero, L_808020B8
    if (ctx->r15 == 0) {
        // 0x8080209C: sll         $t9, $v0, 19
        ctx->r25 = S32(ctx->r2 << 19);
            goto L_808020B8;
    }
    // 0x8080209C: sll         $t9, $v0, 19
    ctx->r25 = S32(ctx->r2 << 19);
    // 0x808020A0: bgez        $t9, L_808020B8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808020A4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(2578, 0X3E10) << 16);
            goto L_808020B8;
    }
    // 0x808020A4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3E10) << 16);
    // 0x808020A8: lwc1        $f10, 0x3E10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3E10));
    // 0x808020AC: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x808020B0: b           L_808020E4
    // 0x808020B4: lwc1        $f18, 0x1D4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1D4);
        goto L_808020E4;
    // 0x808020B4: lwc1        $f18, 0x1D4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1D4);
L_808020B8:
    // 0x808020B8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x808020BC: sll         $t2, $v0, 19
    ctx->r10 = S32(ctx->r2 << 19);
    // 0x808020C0: beql        $t0, $zero, L_808020E4
    if (ctx->r8 == 0) {
        // 0x808020C4: lwc1        $f18, 0x1D4($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X1D4);
            goto L_808020E4;
    }
    goto skip_4;
    // 0x808020C4: lwc1        $f18, 0x1D4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1D4);
    skip_4:
    // 0x808020C8: bgez        $t2, L_808020E0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808020CC: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_808020E0;
    }
    // 0x808020CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808020D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808020D4: nop

    // 0x808020D8: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x808020DC: nop

L_808020E0:
    // 0x808020E0: lwc1        $f18, 0x1D4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1D4);
L_808020E4:
    // 0x808020E4: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x808020E8: swc1        $f4, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = ctx->f4.u32l;
    tooie_dialogue_timer_advanced(rdram, ctx);
    // 0x808020EC: lwc1        $f6, 0x1D4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1D4);
    // 0x808020F0: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x808020F4: nop

    // 0x808020F8: bc1fl       L_808021BC
    if (!c1cs) {
        // 0x808020FC: lw          $v0, 0x1E4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E4);
            goto L_808021BC;
    }
    goto skip_5;
    // 0x808020FC: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    skip_5:
    // 0x80802100: lbu         $v0, 0x19E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X19E);
    // 0x80802104: lbu         $t3, 0x19C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X19C);
    // 0x80802108: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8080210C: bnel        $at, $zero, L_808021BC
    if (ctx->r1 != 0) {
        // 0x80802110: lw          $v0, 0x1E4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E4);
            goto L_808021BC;
    }
    goto skip_6;
    // 0x80802110: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    skip_6:
    // 0x80802114: lw          $a1, 0x1E4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1E4);
L_80802118:
    // 0x80802118: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8080211C: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x80802120: sb          $t4, 0x19E($s0)
    MEM_B(0X19E, ctx->r16) = ctx->r12;
    // 0x80802124: addu        $t5, $s0, $t6
    ctx->r13 = ADD32(ctx->r16, ctx->r14);
    // 0x80802128: sll         $t7, $a1, 12
    ctx->r15 = S32(ctx->r5 << 12);
    // 0x8080212C: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80802130: lbu         $a0, 0xC0($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0XC0);
    // 0x80802134: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x80802138: jal         0x808005F0
    // 0x8080213C: andi        $a1, $t8, 0xFF
    ctx->r5 = ctx->r24 & 0XFF;
    func_808005F0_gczoombox(rdram, ctx);
        goto after_12;
    // 0x8080213C: andi        $a1, $t8, 0xFF
    ctx->r5 = ctx->r24 & 0XFF;
    after_12:
    // 0x80802140: beq         $v0, $zero, L_80802184
    if (ctx->r2 == 0) {
        // 0x80802144: lwc1        $f2, 0x40($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
            goto L_80802184;
    }
    // 0x80802144: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80802148: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8080214C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3E18) << 16);
    // 0x80802150: beq         $t0, $zero, L_80802174
    if (ctx->r8 == 0) {
        // 0x80802154: nop
    
            goto L_80802174;
    }
    // 0x80802154: nop

    // 0x80802158: lw          $t1, 0x1E4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E4);
    // 0x8080215C: sll         $t3, $t1, 19
    ctx->r11 = S32(ctx->r9 << 19);
    // 0x80802160: bgez        $t3, L_80802174
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80802164: nop
    
            goto L_80802174;
    }
    // 0x80802164: nop

    // 0x80802168: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3E14) << 16);
    // 0x8080216C: b           L_80802178
    // 0x80802170: lwc1        $f0, 0x3E14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3E14));
        goto L_80802178;
    // 0x80802170: lwc1        $f0, 0x3E14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3E14));
L_80802174:
    // 0x80802174: lwc1        $f0, 0x3E18($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3E18));
L_80802178:
    // 0x80802178: lwc1        $f8, 0x1D4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1D4);
    // 0x8080217C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80802180: swc1        $f10, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = ctx->f10.u32l;
L_80802184:
    // 0x80802184: lwc1        $f16, 0x1D4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1D4);
    // 0x80802188: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8080218C: swc1        $f18, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = ctx->f18.u32l;
    // 0x80802190: lwc1        $f4, 0x1D4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1D4);
    // 0x80802194: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80802198: nop

    // 0x8080219C: bc1fl       L_808021BC
    if (!c1cs) {
        // 0x808021A0: lw          $v0, 0x1E4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1E4);
            goto L_808021BC;
    }
    goto skip_7;
    // 0x808021A0: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    skip_7:
    // 0x808021A4: lbu         $v0, 0x19E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X19E);
    // 0x808021A8: lbu         $t4, 0x19C($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X19C);
    // 0x808021AC: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808021B0: beql        $at, $zero, L_80802118
    if (ctx->r1 == 0) {
        // 0x808021B4: lw          $a1, 0x1E4($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X1E4);
            goto L_80802118;
    }
    goto skip_8;
    // 0x808021B4: lw          $a1, 0x1E4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1E4);
    skip_8:
    // 0x808021B8: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
L_808021BC:
    // 0x808021BC: lbu         $a3, 0x19E($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X19E);
    // 0x808021C0: sll         $t5, $v0, 5
    ctx->r13 = S32(ctx->r2 << 5);
    // 0x808021C4: bgez        $t5, L_80802224
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808021C8: sll         $t7, $v0, 28
        ctx->r15 = S32(ctx->r2 << 28);
            goto L_80802224;
    }
    // 0x808021C8: sll         $t7, $v0, 28
    ctx->r15 = S32(ctx->r2 << 28);
    // 0x808021CC: sll         $t8, $v0, 28
    ctx->r24 = S32(ctx->r2 << 28);
    // 0x808021D0: bgez        $t8, L_80802208
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808021D4: addiu       $a0, $s0, 0xC0
        ctx->r4 = ADD32(ctx->r16, 0XC0);
            goto L_80802208;
    }
    // 0x808021D4: addiu       $a0, $s0, 0xC0
    ctx->r4 = ADD32(ctx->r16, 0XC0);
    // 0x808021D8: addiu       $t9, $zero, 0xFD
    ctx->r25 = ADD32(0, 0XFD);
    // 0x808021DC: addiu       $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
    // 0x808021E0: sb          $t9, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r25;
    // 0x808021E4: sb          $t0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r8;
    // 0x808021E8: addiu       $a0, $s0, 0xC0
    ctx->r4 = ADD32(ctx->r16, 0XC0);
    // 0x808021EC: addiu       $a1, $s0, 0x32
    ctx->r5 = ADD32(ctx->r16, 0X32);
    // 0x808021F0: jal         0x8080014C
    // 0x808021F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080014C_gczoombox(rdram, ctx);
        goto after_13;
    // 0x808021F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x808021F8: lbu         $t1, 0x19E($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X19E);
    // 0x808021FC: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x80802200: b           L_80802214
    // 0x80802204: sb          $zero, 0x32($t2)
    MEM_B(0X32, ctx->r10) = 0;
        goto L_80802214;
    // 0x80802204: sb          $zero, 0x32($t2)
    MEM_B(0X32, ctx->r10) = 0;
L_80802208:
    // 0x80802208: addiu       $a1, $s0, 0x30
    ctx->r5 = ADD32(ctx->r16, 0X30);
    // 0x8080220C: jal         0x8080014C
    // 0x80802210: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080014C_gczoombox(rdram, ctx);
        goto after_14;
    // 0x80802210: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
L_80802214:
    // 0x80802214: lbu         $t4, 0x1E4($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1E4);
    // 0x80802218: ori         $t6, $t4, 0x20
    ctx->r14 = ctx->r12 | 0X20;
    // 0x8080221C: b           L_8080227C
    // 0x80802220: sb          $t6, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r14;
        goto L_8080227C;
    // 0x80802220: sb          $t6, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r14;
L_80802224:
    // 0x80802224: bgez        $t7, L_8080225C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80802228: addiu       $a0, $s0, 0xC0
        ctx->r4 = ADD32(ctx->r16, 0XC0);
            goto L_8080225C;
    }
    // 0x80802228: addiu       $a0, $s0, 0xC0
    ctx->r4 = ADD32(ctx->r16, 0XC0);
    // 0x8080222C: addiu       $t8, $zero, 0xFD
    ctx->r24 = ADD32(0, 0XFD);
    // 0x80802230: addiu       $t9, $zero, 0x68
    ctx->r25 = ADD32(0, 0X68);
    // 0x80802234: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x80802238: sb          $t9, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r25;
    // 0x8080223C: addiu       $a0, $s0, 0xC0
    ctx->r4 = ADD32(ctx->r16, 0XC0);
    // 0x80802240: addiu       $a1, $s0, 0x2
    ctx->r5 = ADD32(ctx->r16, 0X2);
    // 0x80802244: jal         0x8080014C
    // 0x80802248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080014C_gczoombox(rdram, ctx);
        goto after_15;
    // 0x80802248: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x8080224C: lbu         $t0, 0x19E($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X19E);
    // 0x80802250: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x80802254: b           L_80802268
    // 0x80802258: sb          $zero, 0x2($t1)
    MEM_B(0X2, ctx->r9) = 0;
        goto L_80802268;
    // 0x80802258: sb          $zero, 0x2($t1)
    MEM_B(0X2, ctx->r9) = 0;
L_8080225C:
    // 0x8080225C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80802260: jal         0x8080014C
    // 0x80802264: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8080014C_gczoombox(rdram, ctx);
        goto after_16;
    // 0x80802264: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
L_80802268:
    // 0x80802268: lbu         $t3, 0x1E4($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1E4);
    // 0x8080226C: ori         $t5, $t3, 0x8
    ctx->r13 = ctx->r11 | 0X8;
    // 0x80802270: sb          $t5, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r13;
    // 0x80802274: ori         $t7, $t5, 0x40
    ctx->r15 = ctx->r13 | 0X40;
    // 0x80802278: sb          $t7, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r15;
L_8080227C:
    // 0x8080227C: lbu         $t8, 0x19C($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X19C);
    // 0x80802280: lbu         $t9, 0x19E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X19E);
    // 0x80802284: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80802288: beql        $at, $zero, L_80802B84
    if (ctx->r1 == 0) {
        // 0x8080228C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802B84;
    }
    goto skip_9;
    // 0x8080228C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80802290: jal         0x808002E4
    // 0x80802294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002E4_gczoombox(rdram, ctx);
        goto after_17;
    // 0x80802294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80802298: b           L_80802B84
    // 0x8080229C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B84;
    // 0x8080229C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808022A0:
    // 0x808022A0: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x808022A4: beql        $t0, $zero, L_808022C0
    if (ctx->r8 == 0) {
        // 0x808022A8: lwc1        $f2, 0x1C4($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X1C4);
            goto L_808022C0;
    }
    goto skip_10;
    // 0x808022A8: lwc1        $f2, 0x1C4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C4);
    skip_10:
    // 0x808022AC: lw          $t1, 0x1E4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E4);
    // 0x808022B0: sll         $t3, $t1, 19
    ctx->r11 = S32(ctx->r9 << 19);
    // 0x808022B4: bltzl       $t3, L_808022DC
    if (SIGNED(ctx->r11) < 0) {
        // 0x808022B8: lbu         $t6, 0x1CD($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X1CD);
            goto L_808022DC;
    }
    goto skip_11;
    // 0x808022B8: lbu         $t6, 0x1CD($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1CD);
    skip_11:
    // 0x808022BC: lwc1        $f2, 0x1C4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X1C4);
L_808022C0:
    // 0x808022C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808022C4: nop

    // 0x808022C8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x808022CC: nop

    // 0x808022D0: bc1fl       L_8080231C
    if (!c1cs) {
        // 0x808022D4: sub.s       $f8, $f2, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_8080231C;
    }
    goto skip_12;
    // 0x808022D4: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    skip_12:
    // 0x808022D8: lbu         $t6, 0x1CD($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1CD);
L_808022DC:
    // 0x808022DC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x808022E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808022E4: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x808022E8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x808022EC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808022F0: sb          $t4, 0x171($s0)
    MEM_B(0X171, ctx->r16) = ctx->r12;
    // 0x808022F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808022F8: bgez        $t6, L_8080230C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x808022FC: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8080230C;
    }
    // 0x808022FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80802300: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802304: nop

    // 0x80802308: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8080230C:
    // 0x8080230C: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80802310: b           L_80802B80
    // 0x80802314: swc1        $f6, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->f6.u32l;
        goto L_80802B80;
    // 0x80802314: swc1        $f6, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->f6.u32l;
    // 0x80802318: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
L_8080231C:
    // 0x8080231C: b           L_80802B80
    // 0x80802320: swc1        $f8, 0x1C4($s0)
    MEM_W(0X1C4, ctx->r16) = ctx->f8.u32l;
        goto L_80802B80;
    // 0x80802320: swc1        $f8, 0x1C4($s0)
    MEM_W(0X1C4, ctx->r16) = ctx->f8.u32l;
L_80802324:
    // 0x80802324: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80802328: beql        $t5, $zero, L_80802378
    if (ctx->r13 == 0) {
        // 0x8080232C: lw          $t4, 0x1E4($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X1E4);
            goto L_80802378;
    }
    goto skip_13;
    // 0x8080232C: lw          $t4, 0x1E4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E4);
    skip_13:
    // 0x80802330: lw          $t7, 0x1E4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E4);
    // 0x80802334: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80802338: bgezl       $t9, L_80802378
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8080233C: lw          $t4, 0x1E4($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X1E4);
            goto L_80802378;
    }
    goto skip_14;
    // 0x8080233C: lw          $t4, 0x1E4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E4);
    skip_14:
    // 0x80802340: lbu         $t0, 0x1CD($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1CD);
    // 0x80802344: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80802348: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080234C: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x80802350: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80802354: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80802358: lbu         $t2, 0x1E5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1E5);
    // 0x8080235C: andi        $t3, $t2, 0xFF7F
    ctx->r11 = ctx->r10 & 0XFF7F;
    // 0x80802360: sb          $t3, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r11;
    // 0x80802364: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80802368: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8080236C: b           L_808023B4
    // 0x80802370: swc1        $f6, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->f6.u32l;
        goto L_808023B4;
    // 0x80802370: swc1        $f6, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->f6.u32l;
    // 0x80802374: lw          $t4, 0x1E4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E4);
L_80802378:
    // 0x80802378: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8080237C: sll         $t5, $t4, 19
    ctx->r13 = S32(ctx->r12 << 19);
    // 0x80802380: bgezl       $t5, L_808023B8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80802384: lbu         $t0, 0x1E5($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X1E5);
            goto L_808023B8;
    }
    goto skip_15;
    // 0x80802384: lbu         $t0, 0x1E5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1E5);
    skip_15:
    // 0x80802388: beql        $t7, $zero, L_808023B8
    if (ctx->r15 == 0) {
        // 0x8080238C: lbu         $t0, 0x1E5($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X1E5);
            goto L_808023B8;
    }
    goto skip_16;
    // 0x8080238C: lbu         $t0, 0x1E5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1E5);
    skip_16:
    // 0x80802390: lbu         $t8, 0x1CD($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1CD);
    // 0x80802394: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80802398: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080239C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x808023A0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x808023A4: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x808023A8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808023AC: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x808023B0: swc1        $f18, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->f18.u32l;
L_808023B4:
    // 0x808023B4: lbu         $t0, 0x1E5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1E5);
L_808023B8:
    // 0x808023B8: andi        $t1, $t0, 0xFFFD
    ctx->r9 = ctx->r8 & 0XFFFD;
    // 0x808023BC: sb          $t1, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r9;
    // 0x808023C0: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    // 0x808023C4: sll         $a0, $v0, 5
    ctx->r4 = S32(ctx->r2 << 5);
    // 0x808023C8: srl         $t2, $a0, 31
    ctx->r10 = S32(U32(ctx->r4) >> 31);
    // 0x808023CC: bne         $t2, $zero, L_808023DC
    if (ctx->r10 != 0) {
        // 0x808023D0: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_808023DC;
    }
    // 0x808023D0: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x808023D4: srl         $t3, $v0, 31
    ctx->r11 = S32(U32(ctx->r2) >> 31);
    // 0x808023D8: beq         $t3, $zero, L_80802520
    if (ctx->r11 == 0) {
        // 0x808023DC: sll         $v1, $v0, 6
        ctx->r3 = S32(ctx->r2 << 6);
            goto L_80802520;
    }
L_808023DC:
    // 0x808023DC: sll         $v1, $v0, 6
    ctx->r3 = S32(ctx->r2 << 6);
    // 0x808023E0: srl         $t4, $v1, 31
    ctx->r12 = S32(U32(ctx->r3) >> 31);
    // 0x808023E4: beq         $t4, $zero, L_80802438
    if (ctx->r12 == 0) {
        // 0x808023E8: or          $v1, $t4, $zero
        ctx->r3 = ctx->r12 | 0;
            goto L_80802438;
    }
    // 0x808023E8: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x808023EC: sll         $t5, $v0, 25
    ctx->r13 = S32(ctx->r2 << 25);
    // 0x808023F0: bgez        $t5, L_80802418
    if (SIGNED(ctx->r13) >= 0) {
        // 0x808023F4: nop
    
            goto L_80802418;
    }
    // 0x808023F4: nop

    // 0x808023F8: lbu         $t7, 0x171($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X171);
    // 0x808023FC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80802400: beq         $t7, $at, L_80802418
    if (ctx->r15 == ctx->r1) {
        // 0x80802404: nop
    
            goto L_80802418;
    }
    // 0x80802404: nop

    // 0x80802408: beq         $a0, $zero, L_80802418
    if (ctx->r4 == 0) {
        // 0x8080240C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80802418;
    }
    // 0x8080240C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802410: jal         0x80101238
    // 0x80802414: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    func_80101238(rdram, ctx);
        goto after_18;
    // 0x80802414: addiu       $a0, $zero, 0x6D
    ctx->r4 = ADD32(0, 0X6D);
    after_18:
L_80802418:
    // 0x80802418: jal         0x808033D0
    // 0x8080241C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gczoombox_entrypoint_14(rdram, ctx);
        goto after_19;
    // 0x8080241C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80802420: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    // 0x80802424: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80802428: sb          $t8, 0x171($s0)
    MEM_B(0X171, ctx->r16) = ctx->r24;
    // 0x8080242C: sll         $v1, $v0, 6
    ctx->r3 = S32(ctx->r2 << 6);
    // 0x80802430: srl         $t9, $v1, 31
    ctx->r25 = S32(U32(ctx->r3) >> 31);
    // 0x80802434: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_80802438:
    // 0x80802438: lbu         $a0, 0x1E5($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1E5);
    // 0x8080243C: srl         $t0, $a0, 7
    ctx->r8 = S32(U32(ctx->r4) >> 7);
    // 0x80802440: bne         $t0, $zero, L_80802480
    if (ctx->r8 != 0) {
        // 0x80802444: nop
    
            goto L_80802480;
    }
    // 0x80802444: nop

    // 0x80802448: bne         $v1, $zero, L_80802480
    if (ctx->r3 != 0) {
        // 0x8080244C: ori         $t2, $a0, 0x2
        ctx->r10 = ctx->r4 | 0X2;
            goto L_80802480;
    }
    // 0x8080244C: ori         $t2, $a0, 0x2
    ctx->r10 = ctx->r4 | 0X2;
    // 0x80802450: lwc1        $f0, 0x1C8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C8);
    // 0x80802454: lwc1        $f6, 0x1A4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1A4);
    // 0x80802458: lwc1        $f10, 0x1A8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1A8);
    // 0x8080245C: sb          $t2, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r10;
    // 0x80802460: lw          $v0, 0x1E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E4);
    // 0x80802464: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80802468: sll         $v1, $v0, 6
    ctx->r3 = S32(ctx->r2 << 6);
    // 0x8080246C: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80802470: srl         $t3, $v1, 31
    ctx->r11 = S32(U32(ctx->r3) >> 31);
    // 0x80802474: swc1        $f8, 0x1A4($s0)
    MEM_W(0X1A4, ctx->r16) = ctx->f8.u32l;
    // 0x80802478: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x8080247C: swc1        $f16, 0x1A8($s0)
    MEM_W(0X1A8, ctx->r16) = ctx->f16.u32l;
L_80802480:
    // 0x80802480: bne         $v1, $zero, L_80802B80
    if (ctx->r3 != 0) {
        // 0x80802484: sll         $t6, $v0, 12
        ctx->r14 = S32(ctx->r2 << 12);
            goto L_80802B80;
    }
    // 0x80802484: sll         $t6, $v0, 12
    ctx->r14 = S32(ctx->r2 << 12);
    // 0x80802488: bgez        $t6, L_80802498
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080248C: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_80802498;
    }
    // 0x8080248C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x80802490: b           L_80802498
    // 0x80802494: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
        goto L_80802498;
    // 0x80802494: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
L_80802498:
    // 0x80802498: lh          $t5, 0x1B0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1B0);
    // 0x8080249C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x808024A0: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x808024A4: bgez        $t7, L_808024B4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x808024A8: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_808024B4;
    }
    // 0x808024A8: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x808024AC: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x808024B0: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_808024B4:
    // 0x808024B4: subu        $t9, $t5, $t8
    ctx->r25 = SUB32(ctx->r13, ctx->r24);
    // 0x808024B8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x808024BC: lwc1        $f6, 0x1A4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1A4);
    // 0x808024C0: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x808024C4: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808024C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808024CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808024D0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x808024D4: c.le.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl <= ctx->f18.fl;
    // 0x808024D8: nop

    // 0x808024DC: bc1fl       L_80802B84
    if (!c1cs) {
        // 0x808024E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802B84;
    }
    goto skip_17;
    // 0x808024E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_17:
    // 0x808024E4: jal         0x8080014C
    // 0x808024E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8080014C_gczoombox(rdram, ctx);
        goto after_20;
    // 0x808024E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_20:
    // 0x808024EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808024F0: jal         0x808001D4
    // 0x808024F4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_808001D4_gczoombox(rdram, ctx);
        goto after_21;
    // 0x808024F4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_21:
    // 0x808024F8: jal         0x80800228
    // 0x808024FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800228_gczoombox(rdram, ctx);
        goto after_22;
    // 0x808024FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80802500: lbu         $t1, 0x1E4($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1E4);
    // 0x80802504: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80802508: sb          $t6, 0x171($s0)
    MEM_B(0X171, ctx->r16) = ctx->r14;
    // 0x8080250C: ori         $t3, $t1, 0x40
    ctx->r11 = ctx->r9 | 0X40;
    // 0x80802510: sb          $t3, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r11;
    // 0x80802514: andi        $t4, $t3, 0xDF
    ctx->r12 = ctx->r11 & 0XDF;
    // 0x80802518: b           L_80802B80
    // 0x8080251C: sb          $t4, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r12;
        goto L_80802B80;
    // 0x8080251C: sb          $t4, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r12;
L_80802520:
    // 0x80802520: lb          $t5, 0x1E5($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E5);
    // 0x80802524: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80802528: bltzl       $t5, L_80802B84
    if (SIGNED(ctx->r13) < 0) {
        // 0x8080252C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802B84;
    }
    goto skip_18;
    // 0x8080252C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_18:
    // 0x80802530: b           L_80802B80
    // 0x80802534: sb          $t8, 0x171($s0)
    MEM_B(0X171, ctx->r16) = ctx->r24;
        goto L_80802B80;
    // 0x80802534: sb          $t8, 0x171($s0)
    MEM_B(0X171, ctx->r16) = ctx->r24;
L_80802538:
    // 0x80802538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080253C: jal         0x80801BD0
    // 0x80802540: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801BD0_gczoombox(rdram, ctx);
        goto after_23;
    // 0x80802540: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_23:
    // 0x80802544: lbu         $v0, 0x177($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X177);
    // 0x80802548: andi        $t9, $v0, 0x8
    ctx->r25 = ctx->r2 & 0X8;
    // 0x8080254C: beq         $t9, $zero, L_80802570
    if (ctx->r25 == 0) {
        // 0x80802550: andi        $t2, $v0, 0x4
        ctx->r10 = ctx->r2 & 0X4;
            goto L_80802570;
    }
    // 0x80802550: andi        $t2, $v0, 0x4
    ctx->r10 = ctx->r2 & 0X4;
    // 0x80802554: lbu         $t0, 0x1E4($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1E4);
    // 0x80802558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080255C: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80802560: jal         0x808004D0
    // 0x80802564: sb          $t1, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r9;
    func_808004D0_gczoombox(rdram, ctx);
        goto after_24;
    // 0x80802564: sb          $t1, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r9;
    after_24:
    // 0x80802568: b           L_80802B84
    // 0x8080256C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B84;
    // 0x8080256C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802570:
    // 0x80802570: beq         $t2, $zero, L_80802B80
    if (ctx->r10 == 0) {
        // 0x80802574: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_80802B80;
    }
    // 0x80802574: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80802578: lbu         $t3, 0x1E4($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1E4);
    // 0x8080257C: sb          $zero, 0x170($s0)
    MEM_B(0X170, ctx->r16) = 0;
    // 0x80802580: sb          $t6, 0x171($s0)
    MEM_B(0X171, ctx->r16) = ctx->r14;
    // 0x80802584: andi        $t4, $t3, 0xFFFD
    ctx->r12 = ctx->r11 & 0XFFFD;
    // 0x80802588: b           L_80802B80
    // 0x8080258C: sb          $t4, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r12;
        goto L_80802B80;
    // 0x8080258C: sb          $t4, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r12;
L_80802590:
    // 0x80802590: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80802594: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802598: nop

    // 0x8080259C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x808025A0: lhu         $t7, 0x1E4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1E4);
    // 0x808025A4: andi        $t5, $t7, 0x1
    ctx->r13 = ctx->r15 & 0X1;
    // 0x808025A8: beql        $t5, $zero, L_808025EC
    if (ctx->r13 == 0) {
        // 0x808025AC: lw          $t1, 0x1E4($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X1E4);
            goto L_808025EC;
    }
    goto skip_19;
    // 0x808025AC: lw          $t1, 0x1E4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E4);
    skip_19:
    // 0x808025B0: jal         0x80800364
    // 0x808025B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800364_gczoombox(rdram, ctx);
        goto after_25;
    // 0x808025B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x808025B8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x808025BC: lw          $t8, 0x1E4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E4);
    // 0x808025C0: sll         $t0, $t8, 17
    ctx->r8 = S32(ctx->r24 << 17);
    // 0x808025C4: bgezl       $t0, L_808025EC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808025C8: lw          $t1, 0x1E4($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X1E4);
            goto L_808025EC;
    }
    goto skip_20;
    // 0x808025C8: lw          $t1, 0x1E4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E4);
    skip_20:
    // 0x808025CC: lwc1        $f10, 0x1EC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1EC);
    // 0x808025D0: lwc1        $f16, 0x1F4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1F4);
    // 0x808025D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808025D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808025DC: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x808025E0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808025E4: swc1        $f6, 0x1C0($s0)
    MEM_W(0X1C0, ctx->r16) = ctx->f6.u32l;
    // 0x808025E8: lw          $t1, 0x1E4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E4);
L_808025EC:
    // 0x808025EC: sll         $t3, $t1, 20
    ctx->r11 = S32(ctx->r9 << 20);
    // 0x808025F0: bgezl       $t3, L_80802650
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808025F4: lhu         $t7, 0x1E4($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X1E4);
            goto L_80802650;
    }
    goto skip_21;
    // 0x808025F4: lhu         $t7, 0x1E4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1E4);
    skip_21:
    // 0x808025F8: lhu         $t4, 0x1E4($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X1E4);
    // 0x808025FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3E1C) << 16);
    // 0x80802600: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x80802604: beql        $t6, $zero, L_80802650
    if (ctx->r14 == 0) {
        // 0x80802608: lhu         $t7, 0x1E4($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X1E4);
            goto L_80802650;
    }
    goto skip_22;
    // 0x80802608: lhu         $t7, 0x1E4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1E4);
    skip_22:
    // 0x8080260C: lwc1        $f8, 0x1F4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1F4);
    // 0x80802610: lwc1        $f10, 0x3E1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3E1C));
    // 0x80802614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802618: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8080261C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80802620: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80802624: jal         0x808003D8
    // 0x80802628: nop

    func_808003D8_gczoombox(rdram, ctx);
        goto after_26;
    // 0x80802628: nop

    after_26:
    // 0x8080262C: beql        $v0, $zero, L_80802650
    if (ctx->r2 == 0) {
        // 0x80802630: lhu         $t7, 0x1E4($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X1E4);
            goto L_80802650;
    }
    goto skip_23;
    // 0x80802630: lhu         $t7, 0x1E4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1E4);
    skip_23:
    // 0x80802634: jal         0x800C710C
    // 0x80802638: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C710C(rdram, ctx);
        goto after_27;
    // 0x80802638: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_27:
    // 0x8080263C: beq         $v0, $zero, L_8080264C
    if (ctx->r2 == 0) {
        // 0x80802640: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8080264C;
    }
    // 0x80802640: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80802644: jal         0x800880D8
    // 0x80802648: lh          $a1, 0x16A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X16A);
    _gcaudiolist_entrypoint_1(rdram, ctx);
        goto after_28;
    // 0x80802648: lh          $a1, 0x16A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X16A);
    after_28:
L_8080264C:
    // 0x8080264C: lhu         $t7, 0x1E4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1E4);
L_80802650:
    // 0x80802650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802654: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80802658: andi        $t5, $t7, 0x1
    ctx->r13 = ctx->r15 & 0X1;
    // 0x8080265C: beql        $t5, $zero, L_808026CC
    if (ctx->r13 == 0) {
        // 0x80802660: lhu         $t3, 0x1E4($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X1E4);
            goto L_808026CC;
    }
    goto skip_24;
    // 0x80802660: lhu         $t3, 0x1E4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X1E4);
    skip_24:
    // 0x80802664: jal         0x808003D8
    // 0x80802668: lw          $a2, 0x1F4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1F4);
    func_808003D8_gczoombox(rdram, ctx);
        goto after_29;
    // 0x80802668: lw          $a2, 0x1F4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1F4);
    after_29:
    // 0x8080266C: beql        $v0, $zero, L_808026CC
    if (ctx->r2 == 0) {
        // 0x80802670: lhu         $t3, 0x1E4($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X1E4);
            goto L_808026CC;
    }
    goto skip_25;
    // 0x80802670: lhu         $t3, 0x1E4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X1E4);
    skip_25:
    // 0x80802674: lw          $t8, 0x1E4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1E4);
    // 0x80802678: lwc1        $f18, 0x1F4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1F4);
    // 0x8080267C: sll         $t0, $t8, 17
    ctx->r8 = S32(ctx->r24 << 17);
    // 0x80802680: bgez        $t0, L_80802690
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80802684: swc1        $f18, 0x1EC($s0)
        MEM_W(0X1EC, ctx->r16) = ctx->f18.u32l;
            goto L_80802690;
    }
    // 0x80802684: swc1        $f18, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->f18.u32l;
    // 0x80802688: jal         0x808000C4
    // 0x8080268C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C4_gczoombox(rdram, ctx);
        goto after_30;
    // 0x8080268C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
L_80802690:
    // 0x80802690: lbu         $t1, 0x1E6($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1E6);
    // 0x80802694: andi        $t8, $t1, 0xFFDF
    ctx->r24 = ctx->r9 & 0XFFDF;
    // 0x80802698: sb          $t8, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r24;
    // 0x8080269C: lw          $t3, 0x1E4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E4);
    // 0x808026A0: lbu         $t1, 0x1E5($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1E5);
    // 0x808026A4: andi        $t9, $t8, 0xBF
    ctx->r25 = ctx->r24 & 0XBF;
    // 0x808026A8: sll         $t4, $t3, 18
    ctx->r12 = S32(ctx->r11 << 18);
    // 0x808026AC: srl         $t6, $t4, 31
    ctx->r14 = S32(U32(ctx->r12) >> 31);
    // 0x808026B0: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x808026B4: andi        $t5, $t7, 0x40
    ctx->r13 = ctx->r15 & 0X40;
    // 0x808026B8: or          $t0, $t5, $t9
    ctx->r8 = ctx->r13 | ctx->r25;
    // 0x808026BC: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x808026C0: sb          $t0, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r8;
    // 0x808026C4: sb          $t2, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r10;
    // 0x808026C8: lhu         $t3, 0x1E4($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X1E4);
L_808026CC:
    // 0x808026CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808026D0: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x808026D4: bnel        $t4, $zero, L_80802B84
    if (ctx->r12 != 0) {
        // 0x808026D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802B84;
    }
    goto skip_26;
    // 0x808026D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_26:
    // 0x808026DC: jal         0x80801BD0
    // 0x808026E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801BD0_gczoombox(rdram, ctx);
        goto after_31;
    // 0x808026E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_31:
    // 0x808026E4: lbu         $v0, 0x177($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X177);
    // 0x808026E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808026EC: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x808026F0: beq         $t6, $zero, L_80802700
    if (ctx->r14 == 0) {
        // 0x808026F4: andi        $t8, $v0, 0x8
        ctx->r24 = ctx->r2 & 0X8;
            goto L_80802700;
    }
    // 0x808026F4: andi        $t8, $v0, 0x8
    ctx->r24 = ctx->r2 & 0X8;
    // 0x808026F8: b           L_80802B80
    // 0x808026FC: sb          $t7, 0x171($s0)
    MEM_B(0X171, ctx->r16) = ctx->r15;
        goto L_80802B80;
    // 0x808026FC: sb          $t7, 0x171($s0)
    MEM_B(0X171, ctx->r16) = ctx->r15;
L_80802700:
    // 0x80802700: beql        $t8, $zero, L_80802B84
    if (ctx->r24 == 0) {
        // 0x80802704: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802B84;
    }
    goto skip_27;
    // 0x80802704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_27:
    // 0x80802708: jal         0x808004D0
    // 0x8080270C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004D0_gczoombox(rdram, ctx);
        goto after_32;
    // 0x8080270C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x80802710: b           L_80802B84
    // 0x80802714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B84;
    // 0x80802714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802718:
    // 0x80802718: lhu         $t5, 0x1E4($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X1E4);
    // 0x8080271C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80802720: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80802724: andi        $t9, $t5, 0x1
    ctx->r25 = ctx->r13 & 0X1;
    // 0x80802728: beql        $t9, $zero, L_80802760
    if (ctx->r25 == 0) {
        // 0x8080272C: lw          $t3, 0x1E4($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X1E4);
            goto L_80802760;
    }
    goto skip_28;
    // 0x8080272C: lw          $t3, 0x1E4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E4);
    skip_28:
    // 0x80802730: jal         0x80800364
    // 0x80802734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800364_gczoombox(rdram, ctx);
        goto after_33;
    // 0x80802734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80802738: lw          $t0, 0x1E4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1E4);
    // 0x8080273C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80802740: sll         $t2, $t0, 17
    ctx->r10 = S32(ctx->r8 << 17);
    // 0x80802744: bgezl       $t2, L_80802760
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80802748: lw          $t3, 0x1E4($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X1E4);
            goto L_80802760;
    }
    goto skip_29;
    // 0x80802748: lw          $t3, 0x1E4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E4);
    skip_29:
    // 0x8080274C: lwc1        $f4, 0x1EC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1EC);
    // 0x80802750: lwc1        $f6, 0x1F4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1F4);
    // 0x80802754: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80802758: swc1        $f8, 0x1C0($s0)
    MEM_W(0X1C0, ctx->r16) = ctx->f8.u32l;
    // 0x8080275C: lw          $t3, 0x1E4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E4);
L_80802760:
    // 0x80802760: sll         $t6, $t3, 20
    ctx->r14 = S32(ctx->r11 << 20);
    // 0x80802764: bgezl       $t6, L_808027C4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80802768: lhu         $v0, 0x1E4($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X1E4);
            goto L_808027C4;
    }
    goto skip_30;
    // 0x80802768: lhu         $v0, 0x1E4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1E4);
    skip_30:
    // 0x8080276C: lhu         $t7, 0x1E4($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1E4);
    // 0x80802770: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2578, 0X3E20) << 16);
    // 0x80802774: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80802778: beql        $t8, $zero, L_808027C4
    if (ctx->r24 == 0) {
        // 0x8080277C: lhu         $v0, 0x1E4($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X1E4);
            goto L_808027C4;
    }
    goto skip_31;
    // 0x8080277C: lhu         $v0, 0x1E4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1E4);
    skip_31:
    // 0x80802780: lwc1        $f10, 0x1F4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1F4);
    // 0x80802784: lwc1        $f16, 0x3E20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2578, 0X3E20));
    // 0x80802788: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8080278C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802790: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80802794: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80802798: jal         0x808003D8
    // 0x8080279C: nop

    func_808003D8_gczoombox(rdram, ctx);
        goto after_34;
    // 0x8080279C: nop

    after_34:
    // 0x808027A0: beql        $v0, $zero, L_808027C4
    if (ctx->r2 == 0) {
        // 0x808027A4: lhu         $v0, 0x1E4($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X1E4);
            goto L_808027C4;
    }
    goto skip_32;
    // 0x808027A4: lhu         $v0, 0x1E4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1E4);
    skip_32:
    // 0x808027A8: jal         0x800C710C
    // 0x808027AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C710C(rdram, ctx);
        goto after_35;
    // 0x808027AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_35:
    // 0x808027B0: beq         $v0, $zero, L_808027C0
    if (ctx->r2 == 0) {
        // 0x808027B4: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_808027C0;
    }
    // 0x808027B4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808027B8: jal         0x800880D8
    // 0x808027BC: lh          $a1, 0x16A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X16A);
    _gcaudiolist_entrypoint_1(rdram, ctx);
        goto after_36;
    // 0x808027BC: lh          $a1, 0x16A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X16A);
    after_36:
L_808027C0:
    // 0x808027C0: lhu         $v0, 0x1E4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1E4);
L_808027C4:
    // 0x808027C4: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x808027C8: beq         $t5, $zero, L_80802848
    if (ctx->r13 == 0) {
        // 0x808027CC: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_80802848;
    }
    // 0x808027CC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x808027D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808027D4: lwc1        $f4, 0x1EC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1EC);
    // 0x808027D8: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x808027DC: nop

    // 0x808027E0: bc1f        L_80802848
    if (!c1cs) {
        // 0x808027E4: nop
    
            goto L_80802848;
    }
    // 0x808027E4: nop

    // 0x808027E8: lw          $t9, 0x1E4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1E4);
    // 0x808027EC: swc1        $f0, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->f0.u32l;
    // 0x808027F0: sll         $t1, $t9, 17
    ctx->r9 = S32(ctx->r25 << 17);
    // 0x808027F4: bgezl       $t1, L_80802808
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808027F8: lbu         $t2, 0x1E6($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X1E6);
            goto L_80802808;
    }
    goto skip_33;
    // 0x808027F8: lbu         $t2, 0x1E6($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1E6);
    skip_33:
    // 0x808027FC: jal         0x808000C4
    // 0x80802800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C4_gczoombox(rdram, ctx);
        goto after_37;
    // 0x80802800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80802804: lbu         $t2, 0x1E6($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1E6);
L_80802808:
    // 0x80802808: andi        $t9, $t2, 0xFFDF
    ctx->r25 = ctx->r10 & 0XFFDF;
    // 0x8080280C: lbu         $t2, 0x1E5($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1E5);
    // 0x80802810: sb          $t9, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r25;
    // 0x80802814: lw          $t4, 0x1E4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1E4);
    // 0x80802818: andi        $t3, $t2, 0xFFFE
    ctx->r11 = ctx->r10 & 0XFFFE;
    // 0x8080281C: sb          $t3, 0x1E5($s0)
    MEM_B(0X1E5, ctx->r16) = ctx->r11;
    // 0x80802820: sll         $t6, $t4, 18
    ctx->r14 = S32(ctx->r12 << 18);
    // 0x80802824: lhu         $v0, 0x1E4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1E4);
    // 0x80802828: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8080282C: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x80802830: andi        $t5, $t8, 0x40
    ctx->r13 = ctx->r24 & 0X40;
    // 0x80802834: andi        $t0, $t9, 0xBF
    ctx->r8 = ctx->r25 & 0XBF;
    // 0x80802838: or          $t1, $t5, $t0
    ctx->r9 = ctx->r13 | ctx->r8;
    // 0x8080283C: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x80802840: sb          $t1, 0x1E6($s0)
    MEM_B(0X1E6, ctx->r16) = ctx->r9;
    // 0x80802844: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_80802848:
    // 0x80802848: bne         $v0, $zero, L_80802B80
    if (ctx->r2 != 0) {
        // 0x8080284C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802B80;
    }
    // 0x8080284C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802850: jal         0x80801BD0
    // 0x80802854: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80801BD0_gczoombox(rdram, ctx);
        goto after_38;
    // 0x80802854: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_38:
    // 0x80802858: lbu         $v0, 0x177($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X177);
    // 0x8080285C: andi        $t6, $v0, 0x10
    ctx->r14 = ctx->r2 & 0X10;
    // 0x80802860: beq         $t6, $zero, L_80802878
    if (ctx->r14 == 0) {
        // 0x80802864: andi        $t7, $v0, 0x2
        ctx->r15 = ctx->r2 & 0X2;
            goto L_80802878;
    }
    // 0x80802864: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x80802868: jal         0x80801B90
    // 0x8080286C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B90_gczoombox(rdram, ctx);
        goto after_39;
    // 0x8080286C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x80802870: b           L_80802B84
    // 0x80802874: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B84;
    // 0x80802874: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802878:
    // 0x80802878: beql        $t7, $zero, L_80802B84
    if (ctx->r15 == 0) {
        // 0x8080287C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802B84;
    }
    goto skip_34;
    // 0x8080287C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_34:
    // 0x80802880: jal         0x80800470
    // 0x80802884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800470_gczoombox(rdram, ctx);
        goto after_40;
    // 0x80802884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_40:
    // 0x80802888: b           L_80802B84
    // 0x8080288C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B84;
    // 0x8080288C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802890:
    // 0x80802890: jal         0x80800964
    // 0x80802894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800964_gczoombox(rdram, ctx);
        goto after_41;
    // 0x80802894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80802898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080289C: jal         0x80801BD0
    // 0x808028A0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80801BD0_gczoombox(rdram, ctx);
        goto after_42;
    // 0x808028A0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_42:
    // 0x808028A4: b           L_80802B84
    // 0x808028A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B84;
    // 0x808028A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808028AC:
    // 0x808028AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808028B0: lwc1        $f8, 0x1E0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1E0);
    // 0x808028B4: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x808028B8: nop

    // 0x808028BC: bc1fl       L_808028D4
    if (!c1cs) {
        // 0x808028C0: lw          $t0, 0x1E4($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X1E4);
            goto L_808028D4;
    }
    goto skip_35;
    // 0x808028C0: lw          $t0, 0x1E4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1E4);
    skip_35:
    // 0x808028C4: lbu         $t9, 0x1E4($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1E4);
    // 0x808028C8: ori         $t5, $t9, 0x10
    ctx->r13 = ctx->r25 | 0X10;
    // 0x808028CC: sb          $t5, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r13;
    // 0x808028D0: lw          $t0, 0x1E4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1E4);
L_808028D4:
    // 0x808028D4: sll         $t2, $t0, 20
    ctx->r10 = S32(ctx->r8 << 20);
    // 0x808028D8: bgezl       $t2, L_80802914
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808028DC: lbu         $t3, 0x1E4($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X1E4);
            goto L_80802914;
    }
    goto skip_36;
    // 0x808028DC: lbu         $t3, 0x1E4($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1E4);
    skip_36:
    // 0x808028E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808028E4: lwc1        $f10, 0x1E0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1E0);
    // 0x808028E8: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x808028EC: nop

    // 0x808028F0: bc1fl       L_80802914
    if (!c1cs) {
        // 0x808028F4: lbu         $t3, 0x1E4($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X1E4);
            goto L_80802914;
    }
    goto skip_37;
    // 0x808028F4: lbu         $t3, 0x1E4($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1E4);
    skip_37:
    // 0x808028F8: jal         0x800C710C
    // 0x808028FC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800C710C(rdram, ctx);
        goto after_43;
    // 0x808028FC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_43:
    // 0x80802900: beq         $v0, $zero, L_80802910
    if (ctx->r2 == 0) {
        // 0x80802904: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80802910;
    }
    // 0x80802904: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80802908: jal         0x800880D8
    // 0x8080290C: lh          $a1, 0x16A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X16A);
    _gcaudiolist_entrypoint_1(rdram, ctx);
        goto after_44;
    // 0x8080290C: lh          $a1, 0x16A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X16A);
    after_44:
L_80802910:
    // 0x80802910: lbu         $t3, 0x1E4($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1E4);
L_80802914:
    // 0x80802914: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2578, 0X3E44) << 16);
    // 0x80802918: lwc1        $f14, 0x1E0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1E0);
    // 0x8080291C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80802920: beq         $t4, $zero, L_80802960
    if (ctx->r12 == 0) {
        // 0x80802924: addiu       $a1, $a1, 0x3E44
        ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2578, 0X3E44));
            goto L_80802960;
    }
    // 0x80802924: addiu       $a1, $a1, 0x3E44
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2578, 0X3E44));
    // 0x80802928: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2578, 0X3E44) << 16);
    // 0x8080292C: addiu       $a1, $a1, 0x3E44
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2578, 0X3E44));
    // 0x80802930: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80802934: jal         0x800F3780
    // 0x80802938: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_800F3780(rdram, ctx);
        goto after_45;
    // 0x80802938: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_45:
    // 0x8080293C: lh          $v0, 0x1B2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1B2);
    // 0x80802940: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80802944: nop

    // 0x80802948: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8080294C: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80802950: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80802954: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80802958: b           L_80802990
    // 0x8080295C: sh          $t7, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r15;
        goto L_80802990;
    // 0x8080295C: sh          $t7, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r15;
L_80802960:
    // 0x80802960: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80802964: jal         0x800F3780
    // 0x80802968: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_800F3780(rdram, ctx);
        goto after_46;
    // 0x80802968: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_46:
    // 0x8080296C: lh          $v0, 0x1B2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1B2);
    // 0x80802970: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80802974: nop

    // 0x80802978: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080297C: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80802980: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80802984: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80802988: nop

    // 0x8080298C: sh          $t9, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r25;
L_80802990:
    // 0x80802990: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802994: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802998: lwc1        $f14, 0x1E0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1E0);
    // 0x8080299C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808029A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808029A4: c.le.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl <= ctx->f14.fl;
    // 0x808029A8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x808029AC: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808029B0: bc1fl       L_808029FC
    if (!c1cs) {
        // 0x808029B4: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_808029FC;
    }
    goto skip_38;
    // 0x808029B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_38:
    // 0x808029B8: jal         0x80801BD0
    // 0x808029BC: sh          $v0, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r2;
    func_80801BD0_gczoombox(rdram, ctx);
        goto after_47;
    // 0x808029BC: sh          $v0, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r2;
    after_47:
    // 0x808029C0: lbu         $v0, 0x177($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X177);
    // 0x808029C4: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x808029C8: beq         $t5, $zero, L_808029E0
    if (ctx->r13 == 0) {
        // 0x808029CC: andi        $t0, $v0, 0x10
        ctx->r8 = ctx->r2 & 0X10;
            goto L_808029E0;
    }
    // 0x808029CC: andi        $t0, $v0, 0x10
    ctx->r8 = ctx->r2 & 0X10;
    // 0x808029D0: jal         0x80800470
    // 0x808029D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800470_gczoombox(rdram, ctx);
        goto after_48;
    // 0x808029D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x808029D8: b           L_80802B84
    // 0x808029DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B84;
    // 0x808029DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808029E0:
    // 0x808029E0: beql        $t0, $zero, L_80802B84
    if (ctx->r8 == 0) {
        // 0x808029E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802B84;
    }
    goto skip_39;
    // 0x808029E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_39:
    // 0x808029E8: jal         0x80801B90
    // 0x808029EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B90_gczoombox(rdram, ctx);
        goto after_49;
    // 0x808029EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_49:
    // 0x808029F0: b           L_80802B84
    // 0x808029F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B84;
    // 0x808029F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808029F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_808029FC:
    // 0x808029FC: nop

    // 0x80802A00: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80802A04: add.s       $f16, $f14, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80802A08: b           L_80802B80
    // 0x80802A0C: swc1        $f16, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->f16.u32l;
        goto L_80802B80;
    // 0x80802A0C: swc1        $f16, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->f16.u32l;
L_80802A10:
    // 0x80802A10: lw          $t1, 0x1E4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E4);
    // 0x80802A14: sll         $t3, $t1, 20
    ctx->r11 = S32(ctx->r9 << 20);
    // 0x80802A18: bgezl       $t3, L_80802A54
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80802A1C: lbu         $t4, 0x1E4($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X1E4);
            goto L_80802A54;
    }
    goto skip_40;
    // 0x80802A1C: lbu         $t4, 0x1E4($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1E4);
    skip_40:
    // 0x80802A20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80802A24: lwc1        $f18, 0x1E0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1E0);
    // 0x80802A28: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x80802A2C: nop

    // 0x80802A30: bc1fl       L_80802A54
    if (!c1cs) {
        // 0x80802A34: lbu         $t4, 0x1E4($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X1E4);
            goto L_80802A54;
    }
    goto skip_41;
    // 0x80802A34: lbu         $t4, 0x1E4($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1E4);
    skip_41:
    // 0x80802A38: jal         0x800C710C
    // 0x80802A3C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800C710C(rdram, ctx);
        goto after_50;
    // 0x80802A3C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_50:
    // 0x80802A40: beq         $v0, $zero, L_80802A50
    if (ctx->r2 == 0) {
        // 0x80802A44: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_80802A50;
    }
    // 0x80802A44: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80802A48: jal         0x800880D8
    // 0x80802A4C: lh          $a1, 0x16A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X16A);
    _gcaudiolist_entrypoint_1(rdram, ctx);
        goto after_51;
    // 0x80802A4C: lh          $a1, 0x16A($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X16A);
    after_51:
L_80802A50:
    // 0x80802A50: lbu         $t4, 0x1E4($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1E4);
L_80802A54:
    // 0x80802A54: lwc1        $f14, 0x1E0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1E0);
    // 0x80802A58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802A5C: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x80802A60: beq         $t6, $zero, L_80802AA8
    if (ctx->r14 == 0) {
        // 0x80802A64: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(2578, 0X3E44) << 16);
            goto L_80802AA8;
    }
    // 0x80802A64: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2578, 0X3E44) << 16);
    // 0x80802A68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802A6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80802A70: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2578, 0X3E44) << 16);
    // 0x80802A74: addiu       $a1, $a1, 0x3E44
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2578, 0X3E44));
    // 0x80802A78: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80802A7C: jal         0x800F3780
    // 0x80802A80: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    func_800F3780(rdram, ctx);
        goto after_52;
    // 0x80802A80: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    after_52:
    // 0x80802A84: lh          $t7, 0x1B2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1B2);
    // 0x80802A88: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80802A8C: nop

    // 0x80802A90: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80802A94: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80802A98: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80802A9C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80802AA0: b           L_80802AE0
    // 0x80802AA4: sh          $t9, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r25;
        goto L_80802AE0;
    // 0x80802AA4: sh          $t9, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r25;
L_80802AA8:
    // 0x80802AA8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80802AAC: addiu       $a1, $a1, 0x3E44
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2578, 0X3E44));
    // 0x80802AB0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80802AB4: jal         0x800F3780
    // 0x80802AB8: sub.s       $f12, $f18, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f14.fl;
    func_800F3780(rdram, ctx);
        goto after_53;
    // 0x80802AB8: sub.s       $f12, $f18, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f14.fl;
    after_53:
    // 0x80802ABC: lh          $t5, 0x1B2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1B2);
    // 0x80802AC0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80802AC4: nop

    // 0x80802AC8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802ACC: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80802AD0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80802AD4: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80802AD8: nop

    // 0x80802ADC: sh          $t1, 0x1AE($s0)
    MEM_H(0X1AE, ctx->r16) = ctx->r9;
L_80802AE0:
    // 0x80802AE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80802AE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80802AE8: lwc1        $f14, 0x1E0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1E0);
    // 0x80802AEC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80802AF0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80802AF4: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
    // 0x80802AF8: nop

    // 0x80802AFC: bc1fl       L_80802B54
    if (!c1cs) {
        // 0x80802B00: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80802B54;
    }
    goto skip_42;
    // 0x80802B00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_42:
    // 0x80802B04: lbu         $t2, 0x1E4($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1E4);
    // 0x80802B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802B0C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80802B10: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x80802B14: jal         0x80801BD0
    // 0x80802B18: sb          $t3, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r11;
    func_80801BD0_gczoombox(rdram, ctx);
        goto after_54;
    // 0x80802B18: sb          $t3, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r11;
    after_54:
    // 0x80802B1C: lbu         $v0, 0x177($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X177);
    // 0x80802B20: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80802B24: andi        $t4, $v0, 0x20
    ctx->r12 = ctx->r2 & 0X20;
    // 0x80802B28: beq         $t4, $zero, L_80802B38
    if (ctx->r12 == 0) {
        // 0x80802B2C: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_80802B38;
    }
    // 0x80802B2C: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80802B30: b           L_80802B80
    // 0x80802B34: sb          $t6, 0x171($s0)
    MEM_B(0X171, ctx->r16) = ctx->r14;
        goto L_80802B80;
    // 0x80802B34: sb          $t6, 0x171($s0)
    MEM_B(0X171, ctx->r16) = ctx->r14;
L_80802B38:
    // 0x80802B38: beql        $t7, $zero, L_80802B84
    if (ctx->r15 == 0) {
        // 0x80802B3C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802B84;
    }
    goto skip_43;
    // 0x80802B3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_43:
    // 0x80802B40: jal         0x80801B30
    // 0x80802B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B30_gczoombox(rdram, ctx);
        goto after_55;
    // 0x80802B44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_55:
    // 0x80802B48: b           L_80802B84
    // 0x80802B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802B84;
    // 0x80802B4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802B50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80802B54:
    // 0x80802B54: nop

    // 0x80802B58: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80802B5C: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x80802B60: b           L_80802B80
    // 0x80802B64: swc1        $f8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->f8.u32l;
        goto L_80802B80;
    // 0x80802B64: swc1        $f8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->f8.u32l;
L_80802B68:
    // 0x80802B68: lbu         $t8, 0x177($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X177);
    // 0x80802B6C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80802B70: beql        $t9, $zero, L_80802B84
    if (ctx->r25 == 0) {
        // 0x80802B74: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80802B84;
    }
    goto skip_44;
    // 0x80802B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_44:
    // 0x80802B78: jal         0x80801B30
    // 0x80802B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801B30_gczoombox(rdram, ctx);
        goto after_56;
    // 0x80802B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
L_80802B80:
    // 0x80802B80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802B84:
    // 0x80802B84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802B88: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80802B8C: jr          $ra
    // 0x80802B90: nop

    return;
    // 0x80802B90: nop

;}
RECOMP_FUNC void func_80022084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022084: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80022088: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002208C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80022090: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80022094: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80022098: addiu       $t7, $zero, 0x2C
    ctx->r15 = ADD32(0, 0X2C);
    // 0x8002209C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800220A0: lw          $a2, 0xC($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XC);
    // 0x800220A4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800220A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800220AC: jal         0x80020EE4
    // 0x800220B0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_80020EE4(rdram, ctx);
        goto after_0;
    // 0x800220B0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_0:
    // 0x800220B4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800220B8: sw          $v0, -0x15BC($at)
    MEM_W(-0X15BC, ctx->r1) = ctx->r2;
    // 0x800220BC: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x800220C0: lw          $t8, -0x15BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X15BC);
    // 0x800220C4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800220C8: sw          $t8, -0x15C0($at)
    MEM_W(-0X15C0, ctx->r1) = ctx->r24;
    // 0x800220CC: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x800220D0: lw          $t9, -0x15BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X15BC);
    // 0x800220D4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x800220D8: sw          $t9, -0x15C0($at)
    MEM_W(-0X15C0, ctx->r1) = ctx->r25;
    // 0x800220DC: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x800220E0: lw          $t0, -0x15BC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X15BC);
    // 0x800220E4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x800220E8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800220EC: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800220F0: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800220F4: blez        $t2, L_80022154
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800220F8: nop
    
            goto L_80022154;
    }
    // 0x800220F8: nop

L_800220FC:
    // 0x800220FC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80022100: lui         $t5, 0x8008
    ctx->r13 = S32(0X8008 << 16);
    // 0x80022104: lw          $t5, -0x15BC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X15BC);
    // 0x80022108: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8002210C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80022110: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80022114: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80022118: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8002211C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80022120: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80022124: addiu       $t7, $t6, 0x2C
    ctx->r15 = ADD32(ctx->r14, 0X2C);
    // 0x80022128: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8002212C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80022130: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80022134: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80022138: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8002213C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80022140: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80022144: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80022148: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002214C: bne         $at, $zero, L_800220FC
    if (ctx->r1 != 0) {
        // 0x80022150: sw          $t2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r10;
            goto L_800220FC;
    }
    // 0x80022150: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
L_80022154:
    // 0x80022154: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80022158: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x8002215C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80022160: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80022164: addiu       $t6, $t6, 0x1C8C
    ctx->r14 = ADD32(ctx->r14, 0X1C8C);
    // 0x80022168: sw          $t6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r14;
    // 0x8002216C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80022170: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x80022174: addiu       $t8, $t8, 0x1E1C
    ctx->r24 = ADD32(ctx->r24, 0X1E1C);
    // 0x80022178: sw          $t8, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r24;
    // 0x8002217C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80022180: lui         $t0, 0x8002
    ctx->r8 = S32(0X8002 << 16);
    // 0x80022184: addiu       $t0, $t0, 0x2060
    ctx->r8 = ADD32(ctx->r8, 0X2060);
    // 0x80022188: sw          $t0, 0x18($t1)
    MEM_W(0X18, ctx->r9) = ctx->r8;
    // 0x8002218C: b           L_80022194
    // 0x80022190: nop

        goto L_80022194;
    // 0x80022190: nop

L_80022194:
    // 0x80022194: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022198: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002219C: jr          $ra
    // 0x800221A0: nop

    return;
    // 0x800221A0: nop

    // 0x800221A4: nop

    // 0x800221A8: nop

    // 0x800221AC: nop

;}
RECOMP_FUNC void fxspgold_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800048: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080004C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800050: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800054: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80800058: jal         0x800B56D0
    // 0x8080005C: lbu         $a0, 0x7120($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7120);
    func_800B56D0(rdram, ctx);
        goto after_0;
    // 0x8080005C: lbu         $a0, 0x7120($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7120);
    after_0:
    // 0x80800060: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2842, 0X90) << 16);
    // 0x80800064: addiu       $t6, $t6, 0x90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2842, 0X90));
    // 0x80800068: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080006C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800070: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800074: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800078: jal         0x800BABB8
    // 0x8080007C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x8080007C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80800080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_8080010C_chexplodingchainlinks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800110: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800114: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800118: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080011C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80800120: jal         0x800EE7F8
    // 0x80800124: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800124: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800128: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8080012C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1440, 0X1B8) << 16);
    // 0x80800130: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800134: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80800138: addiu       $t7, $t7, 0x1B8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1440, 0X1B8));
    // 0x8080013C: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800140: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800144: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800148: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080014C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80800150: jal         0x800BBCB8
    // 0x80800154: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x80800154: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080015C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800160: jr          $ra
    // 0x80800164: nop

    return;
    // 0x80800164: nop

    // 0x80800168: nop

    // 0x8080016C: nop

;}
RECOMP_FUNC void func_80800000_chlavagargoyle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lbu         $t7, 0x64($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X64);
    // 0x8080000C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800010: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800014: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80800018: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8080001C: sb          $t8, 0x64($a0)
    MEM_B(0X64, ctx->r4) = ctx->r24;
    // 0x80800020: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800024: jal         0x800DC178
    // 0x80800028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80800028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080002C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: jal         0x80105010
    // 0x80800034: swc1        $f0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f0.u32l;
    func_80105010(rdram, ctx);
        goto after_1;
    // 0x80800034: swc1        $f0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f0.u32l;
    after_1:
    // 0x80800038: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080003C: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800040: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x80800044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080004C: jr          $ra
    // 0x80800050: nop

    return;
    // 0x80800050: nop

;}
RECOMP_FUNC void _sumumbofx_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089848: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089848);
    return;
    // 0x8008984C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808000B8_baeggfire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000C4: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x808000C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000CC: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x808000D0: bnel        $t6, $zero, L_80800170
    if (ctx->r14 != 0) {
        // 0x808000D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800170;
    }
    goto skip_0;
    // 0x808000D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808000D8: lbu         $t7, 0x12($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X12);
    // 0x808000DC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x808000E0: addiu       $a1, $a1, 0x4B18
    ctx->r5 = ADD32(ctx->r5, 0X4B18);
    // 0x808000E4: beq         $t7, $zero, L_80800120
    if (ctx->r15 == 0) {
        // 0x808000E8: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80800120;
    }
    // 0x808000E8: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808000EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000F0: jal         0x800C9DE4
    // 0x808000F4: lw          $a2, 0x184($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X184);
    func_800C9DE4(rdram, ctx);
        goto after_0;
    // 0x808000F4: lw          $a2, 0x184($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X184);
    after_0:
    // 0x808000F8: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x808000FC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800104: jal         0x80084A88
    // 0x80800108: sb          $t8, 0x13($t9)
    MEM_B(0X13, ctx->r25) = ctx->r24;
    _baeggsetup_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800108: sb          $t8, 0x13($t9)
    MEM_B(0X13, ctx->r25) = ctx->r24;
    after_1:
    // 0x8080010C: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80800110: lbu         $t0, 0x12($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X12);
    // 0x80800114: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80800118: b           L_8080016C
    // 0x8080011C: sb          $t1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r9;
        goto L_8080016C;
    // 0x8080011C: sb          $t1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r9;
L_80800120:
    // 0x80800120: lbu         $t2, 0x11($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X11);
    // 0x80800124: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800128: addiu       $a1, $a1, 0x4B20
    ctx->r5 = ADD32(ctx->r5, 0X4B20);
    // 0x8080012C: beq         $t2, $zero, L_8080016C
    if (ctx->r10 == 0) {
        // 0x80800130: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(516, 0X680) << 16);
            goto L_8080016C;
    }
    // 0x80800130: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(516, 0X680) << 16);
    // 0x80800134: lwc1        $f12, 0x680($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(516, 0X680));
    // 0x80800138: jal         0x800C9DE4
    // 0x8080013C: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    func_800C9DE4(rdram, ctx);
        goto after_2;
    // 0x8080013C: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    after_2:
    // 0x80800140: lw          $t4, 0x6C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X6C);
    // 0x80800144: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: sb          $t3, 0x13($t4)
    MEM_B(0X13, ctx->r12) = ctx->r11;
    // 0x80800150: lw          $t5, 0x6C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X6C);
    // 0x80800154: jal         0x80084A78
    // 0x80800158: lbu         $a1, 0x10($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X10);
    _baeggsetup_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800158: lbu         $a1, 0x10($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0X10);
    after_3:
    // 0x8080015C: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x80800160: lbu         $t6, 0x11($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X11);
    // 0x80800164: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800168: sb          $t7, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r15;
L_8080016C:
    // 0x8080016C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800170:
    // 0x80800170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800174: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void func_808002E8_chdiggerbossdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002EC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808002F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002F4: beq         $a1, $at, L_80800310
    if (ctx->r5 == ctx->r1) {
        // 0x808002F8: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800310;
    }
    // 0x808002F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808002FC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800300: beq         $a1, $at, L_80800344
    if (ctx->r5 == ctx->r1) {
        // 0x80800304: nop
    
            goto L_80800344;
    }
    // 0x80800304: nop

    // 0x80800308: b           L_80800360
    // 0x8080030C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800360;
    // 0x8080030C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800310:
    // 0x80800310: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80800314: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800318: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080031C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800320: bnel        $t7, $at, L_80800360
    if (ctx->r15 != ctx->r1) {
        // 0x80800324: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800360;
    }
    goto skip_0;
    // 0x80800324: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800328: jal         0x80101FDC
    // 0x8080032C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x8080032C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800330: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80800334: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800338: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080033C: b           L_8080035C
    // 0x80800340: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
        goto L_8080035C;
    // 0x80800340: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
L_80800344:
    // 0x80800344: jal         0x80800370
    // 0x80800348: nop

    func_80800370_chdiggerbossdoor(rdram, ctx);
        goto after_1;
    // 0x80800348: nop

    after_1:
    // 0x8080034C: b           L_80800360
    // 0x80800350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800360;
    // 0x80800350: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800354: b           L_80800360
    // 0x80800358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800360;
    // 0x80800358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080035C:
    // 0x8080035C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800360:
    // 0x80800360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800364: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800368: jr          $ra
    // 0x8080036C: nop

    return;
    // 0x8080036C: nop

;}
RECOMP_FUNC void bsbtrot_entrypoint_54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802DA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802DA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802DAC: jal         0x80802A4C
    // 0x80802DB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802A4C_bsbtrot(rdram, ctx);
        goto after_0;
    // 0x80802DB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802DB4: jal         0x8080061C
    // 0x80802DB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080061C_bsbtrot(rdram, ctx);
        goto after_1;
    // 0x80802DB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80802DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802DC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802DC4: jr          $ra
    // 0x80802DC8: nop

    return;
    // 0x80802DC8: nop

;}
RECOMP_FUNC void func_80800194_chhoneyb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800198: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080019C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x808001A8: addiu       $a1, $zero, 0x1C1
    ctx->r5 = ADD32(0, 0X1C1);
    // 0x808001AC: jal         0x8008A0C0
    // 0x808001B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _subaddiemarker_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808001B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x808001B4: beq         $v0, $zero, L_808001C4
    if (ctx->r2 == 0) {
        // 0x808001B8: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_808001C4;
    }
    // 0x808001B8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808001BC: jal         0x800EE7F8
    // 0x808001C0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808001C0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
L_808001C4:
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C8: jal         0x80100094
    // 0x808001CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808001CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808001D0: addiu       $a0, $v0, 0x18
    ctx->r4 = ADD32(ctx->r2, 0X18);
    // 0x808001D4: addiu       $a1, $zero, 0x4B7
    ctx->r5 = ADD32(0, 0X4B7);
    // 0x808001D8: addiu       $a2, $zero, 0x258
    ctx->r6 = ADD32(0, 0X258);
    // 0x808001DC: jal         0x80089FD0
    // 0x808001E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddieitem_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x808001E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_3:
    // 0x808001E4: jal         0x80800058
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800058_chhoneyb(rdram, ctx);
        goto after_4;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: jal         0x80100094
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x808001F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800200: jal         0x8008A2A0
    // 0x80800204: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _susubgame_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x80800204: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080020C: jal         0x80100094
    // 0x80800210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x80800210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800214: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(800, 0X10B0) << 16);
    // 0x80800218: addiu       $a1, $a1, 0x10B0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(800, 0X10B0));
    // 0x8080021C: jal         0x8008A300
    // 0x80800220: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _susubgame_entrypoint_12(rdram, ctx);
        goto after_8;
    // 0x80800220: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800224: jal         0x800A16BC
    // 0x80800228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A16BC(rdram, ctx);
        goto after_9;
    // 0x80800228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x8080022C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800234: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800238: jr          $ra
    // 0x8080023C: nop

    return;
    // 0x8080023C: nop

;}
RECOMP_FUNC void func_800F482C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F482C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F4830: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F4834: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800F4838: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800F483C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F4840: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F4844: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800F4848: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800F484C: addiu       $s0, $s0, 0x5490
    ctx->r16 = ADD32(ctx->r16, 0X5490);
    // 0x800F4850: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800F4854: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_800F4858:
    // 0x800F4858: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800F485C: beql        $a0, $zero, L_800F4898
    if (ctx->r4 == 0) {
        // 0x800F4860: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800F4898;
    }
    goto skip_0;
    // 0x800F4860: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800F4864: beq         $s2, $zero, L_800F4880
    if (ctx->r18 == 0) {
        // 0x800F4868: nop
    
            goto L_800F4880;
    }
    // 0x800F4868: nop

    // 0x800F486C: jal         0x800A3274
    // 0x800F4870: nop

    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x800F4870: nop

    after_0:
    // 0x800F4874: bnel        $v0, $s2, L_800F4898
    if (ctx->r2 != ctx->r18) {
        // 0x800F4878: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800F4898;
    }
    goto skip_1;
    // 0x800F4878: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x800F487C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_800F4880:
    // 0x800F4880: jal         0x800F3880
    // 0x800F4884: nop

    func_800F3880(rdram, ctx);
        goto after_1;
    // 0x800F4884: nop

    after_1:
    // 0x800F4888: jal         0x800A91F4
    // 0x800F488C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A91F4(rdram, ctx);
        goto after_2;
    // 0x800F488C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800F4890: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x800F4894: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800F4898:
    // 0x800F4898: bne         $s1, $s3, L_800F4858
    if (ctx->r17 != ctx->r19) {
        // 0x800F489C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800F4858;
    }
    // 0x800F489C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800F48A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800F48A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F48A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F48AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800F48B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800F48B4: jr          $ra
    // 0x800F48B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800F48B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _ncbadie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089278: syscall     769
    recomp_syscall_handler(rdram, ctx, 0x80089278);
    return;
    // 0x8008927C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
