#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800020_ncbasuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800028: jal         0x80112524
    // 0x8080002C: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x8080002C: nop

    after_0:
    // 0x80800030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800038: jr          $ra
    // 0x8080003C: nop

    return;
    // 0x8080003C: nop

;}
RECOMP_FUNC void _bsrest_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800839C8: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x800839C8);
    return;
    // 0x800839CC: addi        $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
;}
RECOMP_FUNC void _gcegg_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800883D8: syscall     680
    recomp_syscall_handler(rdram, ctx, 0x800883D8);
    return;
    // 0x800883DC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void chpotogoldgame_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801C94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80801C98: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80801C9C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80801CA0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80801CA4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80801CA8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80801CAC: jal         0x80106790
    // 0x80801CB0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801CB0: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x80801CB4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80801CB8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80801CBC: addiu       $t7, $t6, -0x15
    ctx->r15 = ADD32(ctx->r14, -0X15);
    // 0x80801CC0: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80801CC4: beq         $at, $zero, L_80802028
    if (ctx->r1 == 0) {
        // 0x80801CC8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80802028;
    }
    // 0x80801CC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801CCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2336, 0X24D8) << 16);
    // 0x80801CD0: addu        $at, $at, $t7
    gpr jr_addend_80801CD8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80801CD4: lw          $t7, 0x24D8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2336, 0X24D8));
    // 0x80801CD8: jr          $t7
    // 0x80801CDC: nop

    switch (jr_addend_80801CD8 >> 2) {
        case 0: goto L_80801CE0; break;
        case 1: goto L_80801D88; break;
        case 2: goto L_80801E30; break;
        case 3: goto L_80801ED8; break;
        case 4: goto L_80801F80; break;
        default: switch_error(__func__, 0x80801CD8, 0x808024D8);
    }
    // 0x80801CDC: nop

L_80801CE0:
    // 0x80801CE0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80801CE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801CE8: lwc1        $f12, 0x2C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80801CEC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801CF0: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80801CF4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80801CF8: jal         0x800F10B4
    // 0x80801CFC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80801CFC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80801D00: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80801D04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801D08: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80801D0C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801D10: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80801D14: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80801D18: nop

    // 0x80801D1C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80801D20: beql        $v0, $zero, L_80801D70
    if (ctx->r2 == 0) {
        // 0x80801D24: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_80801D70;
    }
    goto skip_0;
    // 0x80801D24: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x80801D28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801D2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801D30: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80801D34: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80801D38: nop

    // 0x80801D3C: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801D40: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80801D44: nop

    // 0x80801D48: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80801D4C: bne         $v0, $zero, L_80801D64
    if (ctx->r2 != 0) {
        // 0x80801D50: nop
    
            goto L_80801D64;
    }
    // 0x80801D50: nop

    // 0x80801D54: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80801D58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801D5C: b           L_80801D7C
    // 0x80801D60: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80801D7C;
    // 0x80801D60: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80801D64:
    // 0x80801D64: b           L_80801D7C
    // 0x80801D68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80801D7C;
    // 0x80801D68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80801D6C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_80801D70:
    // 0x80801D70: nop

    // 0x80801D74: bltz        $v0, L_80801D64
    if (SIGNED(ctx->r2) < 0) {
        // 0x80801D78: nop
    
            goto L_80801D64;
    }
    // 0x80801D78: nop

L_80801D7C:
    // 0x80801D7C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80801D80: b           L_80802028
    // 0x80801D84: sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
        goto L_80802028;
    // 0x80801D84: sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
L_80801D88:
    // 0x80801D88: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80801D8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801D90: lwc1        $f12, 0x30($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80801D94: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801D98: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80801D9C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80801DA0: jal         0x800F10B4
    // 0x80801DA4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_2;
    // 0x80801DA4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80801DA8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80801DAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801DB0: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80801DB4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801DB8: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80801DBC: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80801DC0: nop

    // 0x80801DC4: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80801DC8: beql        $v0, $zero, L_80801E18
    if (ctx->r2 == 0) {
        // 0x80801DCC: mfc1        $v0, $f10
        ctx->r2 = (int32_t)ctx->f10.u32l;
            goto L_80801E18;
    }
    goto skip_1;
    // 0x80801DCC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    skip_1:
    // 0x80801DD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801DD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801DD8: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80801DDC: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80801DE0: nop

    // 0x80801DE4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80801DE8: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80801DEC: nop

    // 0x80801DF0: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80801DF4: bne         $v0, $zero, L_80801E0C
    if (ctx->r2 != 0) {
        // 0x80801DF8: nop
    
            goto L_80801E0C;
    }
    // 0x80801DF8: nop

    // 0x80801DFC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80801E00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801E04: b           L_80801E24
    // 0x80801E08: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80801E24;
    // 0x80801E08: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80801E0C:
    // 0x80801E0C: b           L_80801E24
    // 0x80801E10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80801E24;
    // 0x80801E10: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80801E14: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
L_80801E18:
    // 0x80801E18: nop

    // 0x80801E1C: bltz        $v0, L_80801E0C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80801E20: nop
    
            goto L_80801E0C;
    }
    // 0x80801E20: nop

L_80801E24:
    // 0x80801E24: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80801E28: b           L_80802028
    // 0x80801E2C: sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
        goto L_80802028;
    // 0x80801E2C: sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
L_80801E30:
    // 0x80801E30: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80801E34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801E38: lwc1        $f12, 0x28($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X28);
    // 0x80801E3C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801E40: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80801E44: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80801E48: jal         0x800F10B4
    // 0x80801E4C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80801E4C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80801E50: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80801E54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801E58: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80801E5C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801E60: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80801E64: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80801E68: nop

    // 0x80801E6C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80801E70: beql        $v0, $zero, L_80801EC0
    if (ctx->r2 == 0) {
        // 0x80801E74: mfc1        $v0, $f18
        ctx->r2 = (int32_t)ctx->f18.u32l;
            goto L_80801EC0;
    }
    goto skip_2;
    // 0x80801E74: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x80801E78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801E80: sub.s       $f18, $f0, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80801E84: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80801E88: nop

    // 0x80801E8C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80801E90: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80801E94: nop

    // 0x80801E98: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80801E9C: bne         $v0, $zero, L_80801EB4
    if (ctx->r2 != 0) {
        // 0x80801EA0: nop
    
            goto L_80801EB4;
    }
    // 0x80801EA0: nop

    // 0x80801EA4: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80801EA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801EAC: b           L_80801ECC
    // 0x80801EB0: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80801ECC;
    // 0x80801EB0: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80801EB4:
    // 0x80801EB4: b           L_80801ECC
    // 0x80801EB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80801ECC;
    // 0x80801EB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80801EBC: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
L_80801EC0:
    // 0x80801EC0: nop

    // 0x80801EC4: bltz        $v0, L_80801EB4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80801EC8: nop
    
            goto L_80801EB4;
    }
    // 0x80801EC8: nop

L_80801ECC:
    // 0x80801ECC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80801ED0: b           L_80802028
    // 0x80801ED4: sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
        goto L_80802028;
    // 0x80801ED4: sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
L_80801ED8:
    // 0x80801ED8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80801EDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801EE0: lwc1        $f12, 0x18($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80801EE4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801EE8: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80801EEC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80801EF0: jal         0x800F10B4
    // 0x80801EF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80801EF4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80801EF8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80801EFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801F00: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80801F04: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801F08: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80801F0C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80801F10: nop

    // 0x80801F14: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80801F18: beql        $v0, $zero, L_80801F68
    if (ctx->r2 == 0) {
        // 0x80801F1C: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_80801F68;
    }
    goto skip_3;
    // 0x80801F1C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x80801F20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801F24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801F28: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80801F2C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80801F30: nop

    // 0x80801F34: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80801F38: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80801F3C: nop

    // 0x80801F40: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80801F44: bne         $v0, $zero, L_80801F5C
    if (ctx->r2 != 0) {
        // 0x80801F48: nop
    
            goto L_80801F5C;
    }
    // 0x80801F48: nop

    // 0x80801F4C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80801F50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801F54: b           L_80801F74
    // 0x80801F58: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80801F74;
    // 0x80801F58: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80801F5C:
    // 0x80801F5C: b           L_80801F74
    // 0x80801F60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80801F74;
    // 0x80801F60: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80801F64: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_80801F68:
    // 0x80801F68: nop

    // 0x80801F6C: bltz        $v0, L_80801F5C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80801F70: nop
    
            goto L_80801F5C;
    }
    // 0x80801F70: nop

L_80801F74:
    // 0x80801F74: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80801F78: b           L_80802028
    // 0x80801F7C: sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
        goto L_80802028;
    // 0x80801F7C: sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
L_80801F80:
    // 0x80801F80: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80801F84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801F88: lwc1        $f12, 0x1C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80801F8C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80801F90: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x80801F94: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80801F98: jal         0x800F10B4
    // 0x80801F9C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_5;
    // 0x80801F9C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80801FA0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80801FA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801FA8: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80801FAC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80801FB0: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80801FB4: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80801FB8: nop

    // 0x80801FBC: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80801FC0: beql        $v0, $zero, L_80802010
    if (ctx->r2 == 0) {
        // 0x80801FC4: mfc1        $v0, $f10
        ctx->r2 = (int32_t)ctx->f10.u32l;
            goto L_80802010;
    }
    goto skip_4;
    // 0x80801FC4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    skip_4:
    // 0x80801FC8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801FCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801FD0: sub.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80801FD4: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80801FD8: nop

    // 0x80801FDC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80801FE0: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80801FE4: nop

    // 0x80801FE8: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80801FEC: bne         $v0, $zero, L_80802004
    if (ctx->r2 != 0) {
        // 0x80801FF0: nop
    
            goto L_80802004;
    }
    // 0x80801FF0: nop

    // 0x80801FF4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80801FF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80801FFC: b           L_8080201C
    // 0x80802000: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_8080201C;
    // 0x80802000: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80802004:
    // 0x80802004: b           L_8080201C
    // 0x80802008: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8080201C;
    // 0x80802008: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8080200C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
L_80802010:
    // 0x80802010: nop

    // 0x80802014: bltz        $v0, L_80802004
    if (SIGNED(ctx->r2) < 0) {
        // 0x80802018: nop
    
            goto L_80802004;
    }
    // 0x80802018: nop

L_8080201C:
    // 0x8080201C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80802020: sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
    // 0x80802024: nop

L_80802028:
    // 0x80802028: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8080202C: lbu         $v0, 0x2F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2F);
    // 0x80802030: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80802034: addu        $v1, $t9, $s0
    ctx->r3 = ADD32(ctx->r25, ctx->r16);
    // 0x80802038: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x8080203C: beq         $at, $zero, L_80802058
    if (ctx->r1 == 0) {
        // 0x80802040: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_80802058;
    }
L_80802040:
    // 0x80802040: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80802044: sltu        $at, $s0, $v1
    ctx->r1 = ctx->r16 < ctx->r3 ? 1 : 0;
    // 0x80802048: sb          $v0, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r2;
    // 0x8080204C: sb          $v0, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r2;
    // 0x80802050: bne         $at, $zero, L_80802040
    if (ctx->r1 != 0) {
        // 0x80802054: sb          $v0, -0x2($s0)
        MEM_B(-0X2, ctx->r16) = ctx->r2;
            goto L_80802040;
    }
    // 0x80802054: sb          $v0, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r2;
L_80802058:
    // 0x80802058: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080205C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80802060: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802064: jr          $ra
    // 0x80802068: nop

    return;
    // 0x80802068: nop

;}
RECOMP_FUNC void _gspropctrl_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088BB8: syscall     728
    recomp_syscall_handler(rdram, ctx, 0x80088BB8);
    return;
    // 0x80088BBC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void chfriendlystonehead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800894: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1876, 0X9B4) << 16);
    // 0x80800898: jr          $ra
    // 0x8080089C: addiu       $v0, $v0, 0x9B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1876, 0X9B4));
    return;
    // 0x8080089C: addiu       $v0, $v0, 0x9B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1876, 0X9B4));
;}
RECOMP_FUNC void chjigsawbitcont_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800564: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1644, 0X9B8) << 16);
    // 0x80800568: jr          $ra
    // 0x8080056C: addiu       $v0, $v0, 0x9B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1644, 0X9B8));
    return;
    // 0x8080056C: addiu       $v0, $v0, 0x9B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1644, 0X9B8));
;}
RECOMP_FUNC void func_80800E04_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E0C: jal         0x80082FF0
    // 0x80800E10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800E10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E14: jal         0x80800508
    // 0x80800E18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800508_bskaztorpedo(rdram, ctx);
        goto after_1;
    // 0x80800E18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800E1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E24: jr          $ra
    // 0x80800E28: nop

    return;
    // 0x80800E28: nop

;}
RECOMP_FUNC void func_800F58A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F58A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F58A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F58A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F58AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F58B0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F58B4: jal         0x800841D0
    // 0x800F58B8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    _bswalk_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800F58B8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F58BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F58C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F58C4: jr          $ra
    // 0x800F58C8: nop

    return;
    // 0x800F58C8: nop

;}
RECOMP_FUNC void func_800A5240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5248: jal         0x800F54E4
    // 0x800A524C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x800A524C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A5250: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A5254: jal         0x800878D8
    // 0x800A5258: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    _plcamera_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x800A5258: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800A525C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5264: jr          $ra
    // 0x800A5268: nop

    return;
    // 0x800A5268: nop

;}
RECOMP_FUNC void func_800C35E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C35E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C35EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C35F0: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800C35F4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C35F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C35FC: beq         $t6, $zero, L_800C3638
    if (ctx->r14 == 0) {
        // 0x800C3600: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800C3638;
    }
    // 0x800C3600: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C3604: jal         0x800C1414
    // 0x800C3608: sb          $t6, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r14;
    func_800C1414(rdram, ctx);
        goto after_0;
    // 0x800C3608: sb          $t6, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r14;
    after_0:
    // 0x800C360C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C3610: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C3614: jal         0x800EE7F8
    // 0x800C3618: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800C3618: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800C361C: lbu         $a0, 0x23($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X23);
    // 0x800C3620: jal         0x800C368C
    // 0x800C3624: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C368C(rdram, ctx);
        goto after_2;
    // 0x800C3624: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x800C3628: jal         0x800EA05C
    // 0x800C362C: nop

    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x800C362C: nop

    after_3:
    // 0x800C3630: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3634: sh          $v0, 0x5E($t7)
    MEM_H(0X5E, ctx->r15) = ctx->r2;
L_800C3638:
    // 0x800C3638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C363C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C3640: jr          $ra
    // 0x800C3644: nop

    return;
    // 0x800C3644: nop

;}
RECOMP_FUNC void bsjump_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C34: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800C38: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(216, 0X1130) << 16);
    // 0x80800C3C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800C40: jr          $ra
    // 0x80800C44: lw          $v0, 0x1130($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(216, 0X1130));
    return;
    // 0x80800C44: lw          $v0, 0x1130($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(216, 0X1130));
;}
RECOMP_FUNC void func_80800CCC_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800CD8: jal         0x800839E8
    // 0x80800CDC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _bsrest_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800CDC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800CE0: beq         $v0, $zero, L_80800CF4
    if (ctx->r2 == 0) {
        // 0x80800CE4: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CF4;
    }
    // 0x80800CE4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CE8: jal         0x800839B0
    // 0x80800CEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsrest_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80800CEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800CF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800CF4:
    // 0x80800CF4: jal         0x8009E5C8
    // 0x80800CF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800CF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80800CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D04: jr          $ra
    // 0x80800D08: nop

    return;
    // 0x80800D08: nop

;}
RECOMP_FUNC void idworldmake_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800904: jr          $ra
    // 0x80800908: nop

    return;
    // 0x80800908: nop

;}
RECOMP_FUNC void basudie_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000AC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808000B0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x808000B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000B8: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x808000BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000C0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808000C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000C8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x808000CC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x808000D0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808000D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x808000D8: jal         0x808000F0
    // 0x808000DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    basudie_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808000DC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x808000E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void bamovehover_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800014: lw          $a0, 0xC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC8);
    // 0x80800018: jal         0x800EFD24
    // 0x8080001C: addiu       $a0, $a0, 0xAC
    ctx->r4 = ADD32(ctx->r4, 0XAC);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a0, $a0, 0xAC
    ctx->r4 = ADD32(ctx->r4, 0XAC);
    after_0:
    // 0x80800020: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800024: lw          $a0, 0xC8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XC8);
    // 0x80800028: jal         0x800EFD24
    // 0x8080002C: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8080002C: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    after_1:
    // 0x80800030: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: lui         $a1, 0x4185
    ctx->r5 = S32(0X4185 << 16);
    // 0x80800038: lui         $a2, 0x4205
    ctx->r6 = S32(0X4205 << 16);
    // 0x8080003C: lw          $a0, 0xC8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC8);
    // 0x80800040: ori         $a2, $a2, 0x5556
    ctx->r6 = ctx->r6 | 0X5556;
    // 0x80800044: ori         $a1, $a1, 0x5556
    ctx->r5 = ctx->r5 | 0X5556;
    // 0x80800048: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x8080004C: jal         0x800EFA4C
    // 0x80800050: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_800EFA4C(rdram, ctx);
        goto after_2;
    // 0x80800050: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_2:
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080005C: jr          $ra
    // 0x80800060: nop

    return;
    // 0x80800060: nop

;}
RECOMP_FUNC void func_800CB988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CB98C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CB990: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800CB994: jal         0x80087EB8
    // 0x800CB998: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    _gcboundDll_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x800CB998: addiu       $a0, $a0, -0x5180
    ctx->r4 = ADD32(ctx->r4, -0X5180);
    after_0:
    // 0x800CB99C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CB9A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CB9A4: jr          $ra
    // 0x800CB9A8: nop

    return;
    // 0x800CB9A8: nop

;}
RECOMP_FUNC void anctrl_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AF24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008AF28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008AF2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008AF30: lbu         $t8, 0x1B($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1B);
    // 0x8008AF34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8008AF38: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8008AF3C: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x8008AF40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8008AF44: sb          $t6, 0x1A($a0)
    MEM_B(0X1A, ctx->r4) = ctx->r14;
    // 0x8008AF48: sb          $t9, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r25;
    // 0x8008AF4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008AF50: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8008AF54: jal         0x8008B1A0
    // 0x8008AF58: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_0;
    // 0x8008AF58: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    after_0:
    // 0x8008AF5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008AF60: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8008AF64: jal         0x8008B1D4
    // 0x8008AF68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    anctrl_setSubrange(rdram, ctx);
        goto after_1;
    // 0x8008AF68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x8008AF6C: lui         $a1, 0x4024
    ctx->r5 = S32(0X4024 << 16);
    // 0x8008AF70: ori         $a1, $a1, 0x56D6
    ctx->r5 = ctx->r5 | 0X56D6;
    // 0x8008AF74: jal         0x8008B1BC
    // 0x8008AF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_2;
    // 0x8008AF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8008AF7C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8008AF80: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8008AF84: jal         0x8008B1C8
    // 0x8008AF88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B1C8(rdram, ctx);
        goto after_3;
    // 0x8008AF88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8008AF8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008AF90: jal         0x8008B188
    // 0x8008AF94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008B188(rdram, ctx);
        goto after_4;
    // 0x8008AF94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8008AF98: jal         0x800E6A00
    // 0x8008AF9C: nop

    func_800E6A00(rdram, ctx);
        goto after_5;
    // 0x8008AF9C: nop

    after_5:
    // 0x8008AFA0: beq         $v0, $zero, L_8008AFB0
    if (ctx->r2 == 0) {
        // 0x8008AFA4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008AFB0;
    }
    // 0x8008AFA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008AFA8: b           L_8008AFB0
    // 0x8008AFAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_8008AFB0;
    // 0x8008AFAC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8008AFB0:
    // 0x8008AFB0: jal         0x8008B2E8
    // 0x8008AFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B2E8(rdram, ctx);
        goto after_6;
    // 0x8008AFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8008AFB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AFBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008AFC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008AFC4: jr          $ra
    // 0x8008AFC8: nop

    return;
    // 0x8008AFC8: nop

;}
RECOMP_FUNC void boot_osUnmapTLBAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800C8B84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8B84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C8B88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C8B8C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800C8B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8B94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8B98: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8B9C: jal         0x800B28CC
    // 0x800C8BA0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C8BA0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_0:
    // 0x800C8BA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C8BA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C8BAC: addiu       $a1, $a1, -0x5614
    ctx->r5 = ADD32(ctx->r5, -0X5614);
    // 0x800C8BB0: jal         0x800C8CB8
    // 0x800C8BB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800C8CB8(rdram, ctx);
        goto after_1;
    // 0x800C8BB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800C8BB8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C8BBC: addiu       $a1, $a1, -0x5608
    ctx->r5 = ADD32(ctx->r5, -0X5608);
    // 0x800C8BC0: jal         0x800C8D4C
    // 0x800C8BC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800C8D4C(rdram, ctx);
        goto after_2;
    // 0x800C8BC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800C8BC8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C8BCC: addiu       $a1, $a1, -0x5600
    ctx->r5 = ADD32(ctx->r5, -0X5600);
    // 0x800C8BD0: jal         0x800C8E84
    // 0x800C8BD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800C8E84(rdram, ctx);
        goto after_3;
    // 0x800C8BD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x800C8BD8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C8BDC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C8BE0: sb          $t6, 0x16($t7)
    MEM_B(0X16, ctx->r15) = ctx->r14;
    // 0x800C8BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C8BE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C8BEC: jr          $ra
    // 0x800C8BF0: nop

    return;
    // 0x800C8BF0: nop

;}
RECOMP_FUNC void func_80800B4C_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B54: lwc1        $f14, 0x2C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80800B58: lwc1        $f12, 0x28($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80800B5C: jal         0x800DC178
    // 0x80800B60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80800B60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B68: swc1        $f0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f0.u32l;
    // 0x80800B6C: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x80800B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B78: jr          $ra
    // 0x80800B7C: nop

    return;
    // 0x80800B7C: nop

;}
RECOMP_FUNC void func_80800270_cheggclockwork(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800278: jal         0x80100094
    // 0x8080027C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080027C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800280: jal         0x800DB9B0
    // 0x80800284: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DB9B0(rdram, ctx);
        goto after_1;
    // 0x80800284: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800288: beq         $v0, $zero, L_80800298
    if (ctx->r2 == 0) {
        // 0x8080028C: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80800298;
    }
    // 0x8080028C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800290: b           L_808002CC
    // 0x80800294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002CC;
    // 0x80800294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800298:
    // 0x80800298: jal         0x800F6D24
    // 0x8080029C: lh          $a0, 0x3A($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X3A);
    func_800F6D24(rdram, ctx);
        goto after_2;
    // 0x8080029C: lh          $a0, 0x3A($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X3A);
    after_2:
    // 0x808002A0: beq         $v0, $zero, L_808002B0
    if (ctx->r2 == 0) {
        // 0x808002A4: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_808002B0;
    }
    // 0x808002A4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A8: b           L_808002CC
    // 0x808002AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002CC;
    // 0x808002AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002B0:
    // 0x808002B0: jal         0x800F8088
    // 0x808002B4: lh          $a0, 0x3A($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X3A);
    func_800F8088(rdram, ctx);
        goto after_3;
    // 0x808002B4: lh          $a0, 0x3A($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X3A);
    after_3:
    // 0x808002B8: beql        $v0, $zero, L_808002CC
    if (ctx->r2 == 0) {
        // 0x808002BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808002CC;
    }
    goto skip_0;
    // 0x808002BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808002C0: b           L_808002CC
    // 0x808002C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808002CC;
    // 0x808002C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808002C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002CC:
    // 0x808002CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002D4: jr          $ra
    // 0x808002D8: nop

    return;
    // 0x808002D8: nop

;}
RECOMP_FUNC void func_8009EC7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EC7C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EC80: jr          $ra
    // 0x8009EC84: lbu         $v0, 0x7060($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7060);
    return;
    // 0x8009EC84: lbu         $v0, 0x7060($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7060);
;}
RECOMP_FUNC void chfairgroundworker_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(840, 0X3E0) << 16);
    // 0x80800028: jr          $ra
    // 0x8080002C: addiu       $v0, $v0, 0x3E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(840, 0X3E0));
    return;
    // 0x8080002C: addiu       $v0, $v0, 0x3E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(840, 0X3E0));
;}
RECOMP_FUNC void sujiggy_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006CC: jal         0x808000E8
    // 0x808006D0: nop

    sujiggy_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x808006D0: nop

    after_0:
    // 0x808006D4: jal         0x8080010C
    // 0x808006D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    sujiggy_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808006D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808006DC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808006E0: bne         $v0, $t6, L_808006F0
    if (ctx->r2 != ctx->r14) {
        // 0x808006E4: nop
    
            goto L_808006F0;
    }
    // 0x808006E4: nop

    // 0x808006E8: b           L_80800724
    // 0x808006EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80800724;
    // 0x808006EC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_808006F0:
    // 0x808006F0: jal         0x800D035C
    // 0x808006F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800D035C(rdram, ctx);
        goto after_2;
    // 0x808006F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x808006F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808006FC: jal         0x80800114
    // 0x80800700: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    sujiggy_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x80800700: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80800704: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800708: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8080070C: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80800710: bne         $at, $zero, L_80800720
    if (ctx->r1 != 0) {
        // 0x80800714: nop
    
            goto L_80800720;
    }
    // 0x80800714: nop

    // 0x80800718: b           L_80800720
    // 0x8080071C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80800720;
    // 0x8080071C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800720:
    // 0x80800720: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800724:
    // 0x80800724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800728: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080072C: jr          $ra
    // 0x80800730: nop

    return;
    // 0x80800730: nop

;}
RECOMP_FUNC void func_80802DB4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802DB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80802DB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802DBC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802DC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80802DC4: jal         0x80106790
    // 0x80802DC8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80802DC8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80802DCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802DD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802DD4: jal         0x80100094
    // 0x80802DD8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80802DD8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802DDC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80802DE0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80802DE4: lw          $t6, 0x2C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X2C);
    // 0x80802DE8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80802DEC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80802DF0: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80802DF4: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x80802DF8: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x80802DFC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80802E00: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
    // 0x80802E04: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80802E08: sb          $t0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r8;
    // 0x80802E0C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80802E10: sb          $t1, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r9;
    // 0x80802E14: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80802E18: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x80802E1C: lw          $t3, 0x2C($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X2C);
    // 0x80802E20: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80802E24: sw          $t4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r12;
    // 0x80802E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802E2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802E30: jr          $ra
    // 0x80802E34: nop

    return;
    // 0x80802E34: nop

;}
RECOMP_FUNC void _chweldarboss_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865F0: syscall     346
    recomp_syscall_handler(rdram, ctx, 0x800865F0);
    return;
    // 0x800865F4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _fxleaves_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088948: syscall     711
    recomp_syscall_handler(rdram, ctx, 0x80088948);
    return;
    // 0x8008894C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808006E0_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006EC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808006F0: jal         0x80106790
    // 0x808006F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808006F4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x808006F8: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x808006FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800700: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800704: bltz        $t8, L_80800724
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800708: nop
    
            goto L_80800724;
    }
    // 0x80800708: nop

    // 0x8080070C: jal         0x800CEAA8
    // 0x80800710: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800CEAA8(rdram, ctx);
        goto after_1;
    // 0x80800710: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x80800714: beq         $v0, $zero, L_80800724
    if (ctx->r2 == 0) {
        // 0x80800718: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80800724;
    }
    // 0x80800718: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8080071C: jal         0x800CE88C
    // 0x80800720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800CE88C(rdram, ctx);
        goto after_2;
    // 0x80800720: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_80800724:
    // 0x80800724: jal         0x8080356C
    // 0x80800728: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_8080356C_chjiggygamenew(rdram, ctx);
        goto after_3;
    // 0x80800728: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_3:
    // 0x8080072C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800730: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800734: addiu       $a1, $zero, 0x83
    ctx->r5 = ADD32(0, 0X83);
    // 0x80800738: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080073C: jal         0x800C9C34
    // 0x80800740: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    func_800C9C34(rdram, ctx);
        goto after_4;
    // 0x80800740: addiu       $a3, $zero, 0x7D0
    ctx->r7 = ADD32(0, 0X7D0);
    after_4:
    // 0x80800744: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(772, 0X39B4) << 16);
    // 0x80800748: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8080074C: addiu       $a1, $a1, -0x3950
    ctx->r5 = ADD32(ctx->r5, -0X3950);
    // 0x80800750: lwc1        $f12, 0x39B4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X39B4));
    // 0x80800754: jal         0x800C9DE4
    // 0x80800758: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    func_800C9DE4(rdram, ctx);
        goto after_5;
    // 0x80800758: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    after_5:
    // 0x8080075C: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80800760: jal         0x8008A740
    // 0x80800764: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    _sujiggy_entrypoint_21(rdram, ctx);
        goto after_6;
    // 0x80800764: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    after_6:
    // 0x80800768: beq         $v0, $zero, L_80800774
    if (ctx->r2 == 0) {
        // 0x8080076C: addiu       $t0, $zero, 0x155E
        ctx->r8 = ADD32(0, 0X155E);
            goto L_80800774;
    }
    // 0x8080076C: addiu       $t0, $zero, 0x155E
    ctx->r8 = ADD32(0, 0X155E);
    // 0x80800770: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
L_80800774:
    // 0x80800774: jal         0x800C082C
    // 0x80800778: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800C082C(rdram, ctx);
        goto after_7;
    // 0x80800778: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x8080077C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800780: addiu       $t1, $zero, 0x97
    ctx->r9 = ADD32(0, 0X97);
    // 0x80800784: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800788: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8080078C: addiu       $a2, $zero, 0x4C6
    ctx->r6 = ADD32(0, 0X4C6);
    // 0x80800790: jal         0x8008A208
    // 0x80800794: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800794: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x80800798: jal         0x800C082C
    // 0x8080079C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C082C(rdram, ctx);
        goto after_9;
    // 0x8080079C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x808007A0: jal         0x80800B88
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B88_chjiggygamenew(rdram, ctx);
        goto after_10;
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x808007A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808007B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007B4: jr          $ra
    // 0x808007B8: nop

    return;
    // 0x808007B8: nop

;}
RECOMP_FUNC void func_800C8FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8FE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8FE4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C8FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C8FEC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C8FF0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C8FF4: lw          $a0, -0x5500($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5500);
    // 0x800C8FF8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800C8FFC: jal         0x800B28CC
    // 0x800C9000: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    vector_at(rdram, ctx);
        goto after_0;
    // 0x800C9000: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    after_0:
    // 0x800C9004: lbu         $t6, 0x16($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X16);
    // 0x800C9008: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800C900C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C9010: bne         $t6, $zero, L_800C9028
    if (ctx->r14 != 0) {
        // 0x800C9014: nop
    
            goto L_800C9028;
    }
    // 0x800C9014: nop

    // 0x800C9018: lbu         $t7, 0x17($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X17);
    // 0x800C901C: xor         $t8, $a2, $t7
    ctx->r24 = ctx->r6 ^ ctx->r15;
    // 0x800C9020: sltu        $t8, $zero, $t8
    ctx->r24 = 0 < ctx->r24 ? 1 : 0;
    // 0x800C9024: sb          $t8, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r24;
L_800C9028:
    // 0x800C9028: bne         $a2, $zero, L_800C9034
    if (ctx->r6 != 0) {
        // 0x800C902C: sb          $a2, 0x17($v0)
        MEM_B(0X17, ctx->r2) = ctx->r6;
            goto L_800C9034;
    }
    // 0x800C902C: sb          $a2, 0x17($v0)
    MEM_B(0X17, ctx->r2) = ctx->r6;
    // 0x800C9030: sb          $t9, 0x18($v0)
    MEM_B(0X18, ctx->r2) = ctx->r25;
L_800C9034:
    // 0x800C9034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C903C: jr          $ra
    // 0x800C9040: nop

    return;
    // 0x800C9040: nop

;}
RECOMP_FUNC void func_8008B1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B1C8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8008B1CC: jr          $ra
    // 0x8008B1D0: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x8008B1D0: swc1        $f12, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void bsdronejump_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808000B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000C4: addiu       $a2, $s0, 0x190
    ctx->r6 = ADD32(ctx->r16, 0X190);
    // 0x808000C8: addiu       $a3, $s0, 0x194
    ctx->r7 = ADD32(ctx->r16, 0X194);
    // 0x808000CC: jal         0x80084680
    // 0x808000D0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    _badata_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808000D0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808000DC: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x808000E0: jal         0x8008CC34
    // 0x808000E4: lw          $a3, 0x190($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X190);
    baanim_playForDuration_loopStartingAt(rdram, ctx);
        goto after_1;
    // 0x808000E4: lw          $a3, 0x190($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X190);
    after_1:
    // 0x808000E8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808000EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808000FC: jal         0x8009FFD8
    // 0x80800100: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800100: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80800104: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800108: jal         0x8009C128
    // 0x8080010C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_8009C128(rdram, ctx);
        goto after_3;
    // 0x8080010C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80800110: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x80800114: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800118: jal         0x800EEAD4
    // 0x8080011C: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    func_800EEAD4(rdram, ctx);
        goto after_4;
    // 0x8080011C: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    after_4:
    // 0x80800120: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80800124: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x80800128: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080012C: jal         0x800F1DF4
    // 0x80800130: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    func_800F1DF4(rdram, ctx);
        goto after_5;
    // 0x80800130: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    after_5:
    // 0x80800134: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800138: jal         0x8009C914
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_6;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800140: jal         0x80084DB8
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_0(rdram, ctx);
        goto after_7;
    // 0x80800144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800148: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080014C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800150: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80800154: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800158: lui         $a2, 0x459C
    ctx->r6 = S32(0X459C << 16);
    // 0x8080015C: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x80800160: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800164: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x80800168: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8080016C: jal         0x800F10B4
    // 0x80800170: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x80800170: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80800174: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800178: jal         0x80084DF0
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800180: lw          $a1, 0x54($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X54);
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x80084E18
    // 0x8080018C: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    _bamovegoto_entrypoint_12(rdram, ctx);
        goto after_10;
    // 0x8080018C: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
    after_10:
    // 0x80800190: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800194: addiu       $a2, $a2, 0x30F0
    ctx->r6 = ADD32(ctx->r6, 0X30F0);
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: jal         0x80084E10
    // 0x808001A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _bamovegoto_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x808001A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x808001A4: jal         0x80084E20
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bamovegoto_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x800961A0
    // 0x808001B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961A0(rdram, ctx);
        goto after_13;
    // 0x808001B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x808001B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001C0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void func_800BA554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA554: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BA558: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800BA55C: swc1        $f12, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f12.u32l;
    // 0x800BA560: jr          $ra
    // 0x800BA564: swc1        $f14, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x800BA564: swc1        $f14, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void _ncpoducam_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089650: syscall     785
    recomp_syscall_handler(rdram, ctx, 0x80089650);
    return;
    // 0x80089654: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800340_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800340: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800344: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800348: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080034C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800350: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800354: jal         0x8008D04C
    // 0x80800358: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8008D04C(rdram, ctx);
        goto after_0;
    // 0x80800358: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8080035C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800360: jal         0x8008AF24
    // 0x80800364: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800364: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080036C: jal         0x8008AED4
    // 0x80800370: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x80800370: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800378: jal         0x8008B1BC
    // 0x8080037C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    anctrl_setDuration(rdram, ctx);
        goto after_3;
    // 0x8080037C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800384: jal         0x8008B24C
    // 0x80800388: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    anctrl_setStart(rdram, ctx);
        goto after_4;
    // 0x80800388: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x8080038C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800390: jal         0x8008B134
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_5;
    // 0x80800394: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80800398: jal         0x8008B064
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_6;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003AC: jr          $ra
    // 0x808003B0: nop

    return;
    // 0x808003B0: nop

;}
RECOMP_FUNC void func_800C5BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5BE4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C5BE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C5BEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C5BF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C5BF4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800C5BF8: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800C5BFC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800C5C00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C5C04: jal         0x800EE7F8
    // 0x800C5C08: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800C5C08: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x800C5C0C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C5C10: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800C5C14: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800C5C18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C5C1C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C5C20: jal         0x800EE7F8
    // 0x800C5C24: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x800C5C24: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800C5C28: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C5C2C: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C5C30: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5C34: addiu       $at, $zero, 0x1F00
    ctx->r1 = ADD32(0, 0X1F00);
    // 0x800C5C38: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800C5C3C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800C5C40: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800C5C44: bne         $a3, $at, L_800C5C64
    if (ctx->r7 != ctx->r1) {
        // 0x800C5C48: swc1        $f18, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
            goto L_800C5C64;
    }
    // 0x800C5C48: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x800C5C4C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800C5C50: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800C5C54: jal         0x800BEF00
    // 0x800C5C58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800BEF00(rdram, ctx);
        goto after_2;
    // 0x800C5C58: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800C5C5C: b           L_800C5C74
    // 0x800C5C60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800C5C74;
    // 0x800C5C60: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800C5C64:
    // 0x800C5C64: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x800C5C68: jal         0x800C6A7C
    // 0x800C5C6C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800C6A7C(rdram, ctx);
        goto after_3;
    // 0x800C5C6C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x800C5C70: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800C5C74:
    // 0x800C5C74: beql        $v0, $zero, L_800C5C90
    if (ctx->r2 == 0) {
        // 0x800C5C78: sw          $zero, 0x10($s0)
        MEM_W(0X10, ctx->r16) = 0;
            goto L_800C5C90;
    }
    goto skip_0;
    // 0x800C5C78: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    skip_0:
    // 0x800C5C7C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x800C5C80: sh          $zero, 0x14($s0)
    MEM_H(0X14, ctx->r16) = 0;
    // 0x800C5C84: b           L_800C5C94
    // 0x800C5C88: sw          $t6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r14;
        goto L_800C5C94;
    // 0x800C5C88: sw          $t6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r14;
    // 0x800C5C8C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
L_800C5C90:
    // 0x800C5C90: sh          $zero, 0x14($s0)
    MEM_H(0X14, ctx->r16) = 0;
L_800C5C94:
    // 0x800C5C94: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800C5C98: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x800C5C9C: jal         0x800C69FC
    // 0x800C5CA0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800C69FC(rdram, ctx);
        goto after_4;
    // 0x800C5CA0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x800C5CA4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800C5CA8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800C5CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5CB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C5CB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800C5CB8: jr          $ra
    // 0x800C5CBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C5CBC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void chshockjump_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(688, 0X2B0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(688, 0X2B0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2B0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(688, 0X2B0));
;}
RECOMP_FUNC void _gczoombox_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BA0: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087BA0);
    return;
    // 0x80087BA4: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void func_80800998_chhandcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800998: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080099C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808009A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808009A8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808009AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808009B0: jal         0x80100094
    // 0x808009B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009B8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808009BC: jal         0x808007F0
    // 0x808009C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808007F0_chhandcart(rdram, ctx);
        goto after_1;
    // 0x808009C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808009C4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x808009C8: lbu         $t7, 0x8F4($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X8F4);
    // 0x808009CC: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x808009D0: beq         $at, $zero, L_80800A14
    if (ctx->r1 == 0) {
        // 0x808009D4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800A14;
    }
    // 0x808009D4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808009D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1632, 0X4400) << 16);
    // 0x808009DC: addu        $at, $at, $t7
    gpr jr_addend_808009E4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808009E0: lw          $t7, 0x4400($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1632, 0X4400));
    // 0x808009E4: jr          $t7
    // 0x808009E8: nop

    switch (jr_addend_808009E4 >> 2) {
        case 0: goto L_808009EC; break;
        case 1: goto L_808009F8; break;
        case 2: goto L_808009F8; break;
        case 3: goto L_808009F8; break;
        case 4: goto L_80800A04; break;
        default: switch_error(__func__, 0x808009E4, 0x80804400);
    }
    // 0x808009E8: nop

L_808009EC:
    // 0x808009EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808009F0: jal         0x808007BC
    // 0x808009F4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_808007BC_chhandcart(rdram, ctx);
        goto after_2;
    // 0x808009F4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
L_808009F8:
    // 0x808009F8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x808009FC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80800A00: sb          $t8, 0x8F4($t9)
    MEM_B(0X8F4, ctx->r25) = ctx->r24;
L_80800A04:
    // 0x80800A04: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A08: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800A0C: jal         0x80085740
    // 0x80800A10: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_20(rdram, ctx);
        goto after_3;
    // 0x80800A10: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_3:
L_80800A14:
    // 0x80800A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A1C: jr          $ra
    // 0x80800A20: nop

    return;
    // 0x80800A20: nop

;}
RECOMP_FUNC void func_808007CC_chmrsboggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808007D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808007DC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808007E0: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x808007E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808007EC: beq         $v0, $zero, L_80800818
    if (ctx->r2 == 0) {
        // 0x808007F0: addiu       $a1, $zero, 0x12
        ctx->r5 = ADD32(0, 0X12);
            goto L_80800818;
    }
    // 0x808007F0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x808007F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808007F8: beq         $v0, $at, L_80800820
    if (ctx->r2 == ctx->r1) {
        // 0x808007FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800820;
    }
    // 0x808007FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800800: beq         $v0, $at, L_80800858
    if (ctx->r2 == ctx->r1) {
        // 0x80800804: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800858;
    }
    // 0x80800804: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800808: beq         $v0, $at, L_80800820
    if (ctx->r2 == ctx->r1) {
        // 0x8080080C: nop
    
            goto L_80800820;
    }
    // 0x8080080C: nop

    // 0x80800810: b           L_80800868
    // 0x80800814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800868;
    // 0x80800814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800818:
    // 0x80800818: jal         0x800856B0
    // 0x8080081C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x8080081C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
L_80800820:
    // 0x80800820: jal         0x800856E0
    // 0x80800824: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800824: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80800828: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080082C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(888, 0XA80) << 16);
    // 0x80800830: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x80800834: addiu       $a0, $a0, 0xA80
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(888, 0XA80));
    // 0x80800838: jal         0x80088090
    // 0x8080083C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080083C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80800840: jal         0x80088098
    // 0x80800844: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    _gcdialogcamera_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800844: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x80800848: jal         0x800880A0
    // 0x8080084C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    _gcdialogcamera_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x8080084C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    after_4:
    // 0x80800850: jal         0x800880B8
    // 0x80800854: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800854: nop

    after_5:
L_80800858:
    // 0x80800858: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080085C: jal         0x800856D8
    // 0x80800860: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800860: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80800864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800868:
    // 0x80800868: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080086C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800870: jr          $ra
    // 0x80800874: nop

    return;
    // 0x80800874: nop

;}
RECOMP_FUNC void _subaddiefade_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CF0: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089CF0);
    return;
    // 0x80089CF4: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _chskeletonexplode_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E18: syscall     459
    recomp_syscall_handler(rdram, ctx, 0x80086E18);
    return;
    // 0x80086E1C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void subaddiedialog_entrypoint_16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801448: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080144C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801450: jal         0x800DB9B0
    // 0x80801454: nop

    func_800DB9B0(rdram, ctx);
        goto after_0;
    // 0x80801454: nop

    after_0:
    // 0x80801458: beq         $v0, $zero, L_80801468
    if (ctx->r2 == 0) {
        // 0x8080145C: nop
    
            goto L_80801468;
    }
    // 0x8080145C: nop

    // 0x80801460: b           L_808014C8
    // 0x80801464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808014C8;
    // 0x80801464: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801468:
    // 0x80801468: jal         0x800F54E4
    // 0x8080146C: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x8080146C: nop

    after_1:
    // 0x80801470: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801474: beq         $v0, $at, L_8080148C
    if (ctx->r2 == ctx->r1) {
        // 0x80801478: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080148C;
    }
    // 0x80801478: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080147C: jal         0x800F6438
    // 0x80801480: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800F6438(rdram, ctx);
        goto after_2;
    // 0x80801480: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80801484: bne         $v0, $zero, L_80801494
    if (ctx->r2 != 0) {
        // 0x80801488: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80801494;
    }
    // 0x80801488: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_8080148C:
    // 0x8080148C: b           L_808014C8
    // 0x80801490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808014C8;
    // 0x80801490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801494:
    // 0x80801494: jal         0x800F6774
    // 0x80801498: nop

    func_800F6774(rdram, ctx);
        goto after_3;
    // 0x80801498: nop

    after_3:
    // 0x8080149C: bne         $v0, $zero, L_808014AC
    if (ctx->r2 != 0) {
        // 0x808014A0: nop
    
            goto L_808014AC;
    }
    // 0x808014A0: nop

    // 0x808014A4: b           L_808014C8
    // 0x808014A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808014C8;
    // 0x808014A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808014AC:
    // 0x808014AC: jal         0x800C0638
    // 0x808014B0: nop

    func_800C0638(rdram, ctx);
        goto after_4;
    // 0x808014B0: nop

    after_4:
    // 0x808014B4: beql        $v0, $zero, L_808014C8
    if (ctx->r2 == 0) {
        // 0x808014B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808014C8;
    }
    goto skip_0;
    // 0x808014B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808014BC: b           L_808014C8
    // 0x808014C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808014C8;
    // 0x808014C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808014C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808014C8:
    // 0x808014C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808014D0: jr          $ra
    // 0x808014D4: nop

    return;
    // 0x808014D4: nop

;}
RECOMP_FUNC void func_80018108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018108: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001810C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018110: jal         0x80016800
    // 0x80018114: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80016800(rdram, ctx);
        goto after_0;
    // 0x80018114: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80018118: beql        $v0, $zero, L_80018170
    if (ctx->r2 == 0) {
        // 0x8001811C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80018170;
    }
    goto skip_0;
    // 0x8001811C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80018120: jal         0x80016934
    // 0x80018124: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80016934(rdram, ctx);
        goto after_1;
    // 0x80018124: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_1:
    // 0x80018128: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8001812C: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80018130: addiu       $t7, $t7, -0x4D30
    ctx->r15 = ADD32(ctx->r15, -0X4D30);
    // 0x80018134: sll         $t6, $a2, 5
    ctx->r14 = S32(ctx->r6 << 5);
    // 0x80018138: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x8001813C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80018140: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80018144: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80018148: lw          $a0, -0x50F4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X50F4);
    // 0x8001814C: addiu       $a1, $v1, 0x1C
    ctx->r5 = ADD32(ctx->r3, 0X1C);
    // 0x80018150: jal         0x800308B4
    // 0x80018154: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    osMotorInit_recomp(rdram, ctx);
        goto after_2;
    // 0x80018154: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_2:
    // 0x80018158: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8001815C: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80018160: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80018164: jal         0x80016934
    // 0x80018168: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    func_80016934(rdram, ctx);
        goto after_3;
    // 0x80018168: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    after_3:
    // 0x8001816C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018170:
    // 0x80018170: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80018174: jr          $ra
    // 0x80018178: nop

    return;
    // 0x80018178: nop

;}
RECOMP_FUNC void chfaircoinbox_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800438: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2132, 0X4C8) << 16);
    // 0x8080043C: jr          $ra
    // 0x80800440: addiu       $v0, $v0, 0x4C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2132, 0X4C8));
    return;
    // 0x80800440: addiu       $v0, $v0, 0x4C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2132, 0X4C8));
    // 0x80800444: nop

    // 0x80800448: nop

    // 0x8080044C: nop

;}
RECOMP_FUNC void chidgoldhorde_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(736, 0X1F0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X1F0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x1F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(736, 0X1F0));
;}
RECOMP_FUNC void func_800DAAF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAAF8: beq         $a2, $zero, L_800DAB28
    if (ctx->r6 == 0) {
        // 0x800DAAFC: sra         $t3, $a1, 5
        ctx->r11 = S32(SIGNED(ctx->r5) >> 5);
            goto L_800DAB28;
    }
    // 0x800DAAFC: sra         $t3, $a1, 5
    ctx->r11 = S32(SIGNED(ctx->r5) >> 5);
    // 0x800DAB00: sra         $t6, $a1, 5
    ctx->r14 = S32(SIGNED(ctx->r5) >> 5);
    // 0x800DAB04: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800DAB08: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800DAB0C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800DAB10: andi        $t9, $a1, 0x1F
    ctx->r25 = ctx->r5 & 0X1F;
    // 0x800DAB14: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800DAB18: sllv        $t1, $t0, $t9
    ctx->r9 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x800DAB1C: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x800DAB20: jr          $ra
    // 0x800DAB24: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    return;
    // 0x800DAB24: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
L_800DAB28:
    // 0x800DAB28: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800DAB2C: addu        $v0, $a0, $t4
    ctx->r2 = ADD32(ctx->r4, ctx->r12);
    // 0x800DAB30: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x800DAB34: andi        $t5, $a1, 0x1F
    ctx->r13 = ctx->r5 & 0X1F;
    // 0x800DAB38: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DAB3C: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x800DAB40: and         $t0, $v1, $t7
    ctx->r8 = ctx->r3 & ctx->r15;
    // 0x800DAB44: subu        $t9, $v1, $t0
    ctx->r25 = SUB32(ctx->r3, ctx->r8);
    // 0x800DAB48: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800DAB4C: jr          $ra
    // 0x800DAB50: nop

    return;
    // 0x800DAB50: nop

;}
RECOMP_FUNC void sumole_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800710: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800714: slti        $at, $a1, 0x96
    ctx->r1 = SIGNED(ctx->r5) < 0X96 ? 1 : 0;
    // 0x80800718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080071C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800720: bne         $at, $zero, L_8080073C
    if (ctx->r1 != 0) {
        // 0x80800724: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_8080073C;
    }
    // 0x80800724: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800728: addiu       $at, $zero, 0xAC
    ctx->r1 = ADD32(0, 0XAC);
    // 0x8080072C: beq         $a1, $at, L_80800A30
    if (ctx->r5 == ctx->r1) {
        // 0x80800730: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_80800A30;
    }
    // 0x80800730: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800734: b           L_80800B70
    // 0x80800738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B70;
    // 0x80800738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080073C:
    // 0x8080073C: slti        $at, $a1, 0x3E
    ctx->r1 = SIGNED(ctx->r5) < 0X3E ? 1 : 0;
    // 0x80800740: bne         $at, $zero, L_8080075C
    if (ctx->r1 != 0) {
        // 0x80800744: addiu       $t6, $a1, -0xB
        ctx->r14 = ADD32(ctx->r5, -0XB);
            goto L_8080075C;
    }
    // 0x80800744: addiu       $t6, $a1, -0xB
    ctx->r14 = ADD32(ctx->r5, -0XB);
    // 0x80800748: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080074C: beq         $a1, $at, L_8080077C
    if (ctx->r5 == ctx->r1) {
        // 0x80800750: nop
    
            goto L_8080077C;
    }
    // 0x80800750: nop

    // 0x80800754: b           L_80800B70
    // 0x80800758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B70;
    // 0x80800758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080075C:
    // 0x8080075C: sltiu       $at, $t6, 0x33
    ctx->r1 = ctx->r14 < 0X33 ? 1 : 0;
    // 0x80800760: beq         $at, $zero, L_80800B64
    if (ctx->r1 == 0) {
        // 0x80800764: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800B64;
    }
    // 0x80800764: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800768: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3158, 0X22EC) << 16);
    // 0x8080076C: addu        $at, $at, $t6
    gpr jr_addend_80800774 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800770: lw          $t6, 0x22EC($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3158, 0X22EC));
    // 0x80800774: jr          $t6
    // 0x80800778: nop

    switch (jr_addend_80800774 >> 2) {
        case 0: goto L_80800A98; break;
        case 1: goto L_80800B64; break;
        case 2: goto L_80800B64; break;
        case 3: goto L_80800B64; break;
        case 4: goto L_80800B64; break;
        case 5: goto L_80800B64; break;
        case 6: goto L_80800B64; break;
        case 7: goto L_80800B64; break;
        case 8: goto L_80800B64; break;
        case 9: goto L_80800B64; break;
        case 10: goto L_80800B64; break;
        case 11: goto L_80800B64; break;
        case 12: goto L_80800B64; break;
        case 13: goto L_80800B64; break;
        case 14: goto L_80800B64; break;
        case 15: goto L_80800B64; break;
        case 16: goto L_80800B64; break;
        case 17: goto L_80800B64; break;
        case 18: goto L_80800B64; break;
        case 19: goto L_80800B64; break;
        case 20: goto L_80800B64; break;
        case 21: goto L_80800B64; break;
        case 22: goto L_8080079C; break;
        case 23: goto L_80800B64; break;
        case 24: goto L_80800B64; break;
        case 25: goto L_80800B64; break;
        case 26: goto L_80800B64; break;
        case 27: goto L_80800B64; break;
        case 28: goto L_80800B64; break;
        case 29: goto L_80800B64; break;
        case 30: goto L_80800B64; break;
        case 31: goto L_80800B64; break;
        case 32: goto L_80800B64; break;
        case 33: goto L_80800B64; break;
        case 34: goto L_80800B64; break;
        case 35: goto L_808008A0; break;
        case 36: goto L_80800900; break;
        case 37: goto L_80800B50; break;
        case 38: goto L_80800B64; break;
        case 39: goto L_80800B64; break;
        case 40: goto L_80800B64; break;
        case 41: goto L_80800B64; break;
        case 42: goto L_80800B64; break;
        case 43: goto L_80800B64; break;
        case 44: goto L_80800B64; break;
        case 45: goto L_80800B64; break;
        case 46: goto L_80800B64; break;
        case 47: goto L_80800B64; break;
        case 48: goto L_80800B64; break;
        case 49: goto L_80800B64; break;
        case 50: goto L_808007AC; break;
        default: switch_error(__func__, 0x80800774, 0x808022EC);
    }
    // 0x80800778: nop

L_8080077C:
    // 0x8080077C: jal         0x80088848
    // 0x80800780: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_0;
    // 0x80800780: nop

    after_0:
    // 0x80800784: beq         $v0, $zero, L_80800B6C
    if (ctx->r2 == 0) {
        // 0x80800788: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800B6C;
    }
    // 0x80800788: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080078C: jal         0x80800454
    // 0x80800790: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    sumole_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80800790: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_1:
    // 0x80800794: b           L_80800B70
    // 0x80800798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B70;
    // 0x80800798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080079C:
    // 0x8080079C: jal         0x80101074
    // 0x808007A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80101074(rdram, ctx);
        goto after_2;
    // 0x808007A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x808007A4: b           L_80800B70
    // 0x808007A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B70;
    // 0x808007A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808007AC:
    // 0x808007AC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x808007B0: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x808007B4: beq         $at, $zero, L_80800B6C
    if (ctx->r1 == 0) {
        // 0x808007B8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800B6C;
    }
    // 0x808007B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808007BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3158, 0X23B8) << 16);
    // 0x808007C0: addu        $at, $at, $t7
    gpr jr_addend_808007C8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808007C4: lw          $t7, 0x23B8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3158, 0X23B8));
    // 0x808007C8: jr          $t7
    // 0x808007CC: nop

    switch (jr_addend_808007C8 >> 2) {
        case 0: goto L_8080083C; break;
        case 1: goto L_8080083C; break;
        case 2: goto L_8080083C; break;
        case 3: goto L_8080083C; break;
        case 4: goto L_808007D0; break;
        case 5: goto L_808007D0; break;
        case 6: goto L_808007D0; break;
        default: switch_error(__func__, 0x808007C8, 0x808023B8);
    }
    // 0x808007CC: nop

L_808007D0:
    // 0x808007D0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x808007D4: addiu       $a0, $zero, 0xB7
    ctx->r4 = ADD32(0, 0XB7);
    // 0x808007D8: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x808007DC: lwc1        $f4, 0x48($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X48);
    // 0x808007E0: addiu       $a1, $t8, 0x18
    ctx->r5 = ADD32(ctx->r24, 0X18);
    // 0x808007E4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808007E8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x808007EC: jal         0x80108528
    // 0x808007F0: nop

    func_80108528(rdram, ctx);
        goto after_3;
    // 0x808007F0: nop

    after_3:
    // 0x808007F4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x808007F8: lhu         $t4, 0x6E($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X6E);
    // 0x808007FC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3158, 0X2530) << 16);
    // 0x80800800: addiu       $t2, $t0, -0x4
    ctx->r10 = ADD32(ctx->r8, -0X4);
    // 0x80800804: andi        $t3, $t2, 0x1FF
    ctx->r11 = ctx->r10 & 0X1FF;
    // 0x80800808: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x8080080C: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80800810: sh          $t6, 0x6E($v0)
    MEM_H(0X6E, ctx->r2) = ctx->r14;
    // 0x80800814: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80800818: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080081C: addiu       $a2, $zero, 0x6000
    ctx->r6 = ADD32(0, 0X6000);
    // 0x80800820: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800824: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80800828: lw          $a1, 0x2530($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(3158, 0X2530));
    // 0x8080082C: jal         0x8080037C
    // 0x80800830: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8080037C_sumole(rdram, ctx);
        goto after_4;
    // 0x80800830: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80800834: b           L_80800B70
    // 0x80800838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B70;
    // 0x80800838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080083C:
    // 0x8080083C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80800840: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3158, 0X254C) << 16);
    // 0x80800844: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800848: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8080084C: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80800850: lw          $a1, 0x254C($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(3158, 0X254C));
    // 0x80800854: addiu       $a2, $zero, 0x6000
    ctx->r6 = ADD32(0, 0X6000);
    // 0x80800858: jal         0x8080037C
    // 0x8080085C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8080037C_sumole(rdram, ctx);
        goto after_5;
    // 0x8080085C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80800860: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80800864: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800868: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3158, 0X255C) << 16);
    // 0x8080086C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80800870: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x80800874: lw          $a2, 0x255C($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(3158, 0X255C));
    // 0x80800878: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8080087C: jal         0x80085900
    // 0x80800880: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _chbounce_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x80800880: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_6:
    // 0x80800884: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800888: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x8080088C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800890: jal         0x800862E0
    // 0x80800894: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    _chappearfx_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800894: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x80800898: b           L_80800B70
    // 0x8080089C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B70;
    // 0x8080089C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008A0:
    // 0x808008A0: lh          $a1, 0x38($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X38);
    // 0x808008A4: addiu       $at, $zero, 0xD6C
    ctx->r1 = ADD32(0, 0XD6C);
    // 0x808008A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808008AC: bne         $a1, $at, L_808008F0
    if (ctx->r5 != ctx->r1) {
        // 0x808008B0: nop
    
            goto L_808008F0;
    }
    // 0x808008B0: nop

    // 0x808008B4: jal         0x808017C4
    // 0x808008B8: addiu       $a1, $zero, 0xD6C
    ctx->r5 = ADD32(0, 0XD6C);
    sumole_entrypoint_16(rdram, ctx);
        goto after_8;
    // 0x808008B8: addiu       $a1, $zero, 0xD6C
    ctx->r5 = ADD32(0, 0XD6C);
    after_8:
    // 0x808008BC: lh          $t4, 0x3A($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3A);
    // 0x808008C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008C4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x808008C8: bne         $t4, $at, L_808008E0
    if (ctx->r12 != ctx->r1) {
        // 0x808008CC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808008E0;
    }
    // 0x808008CC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808008D0: jal         0x80800454
    // 0x808008D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    sumole_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x808008D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_9:
    // 0x808008D8: b           L_80800B70
    // 0x808008DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B70;
    // 0x808008DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008E0:
    // 0x808008E0: jal         0x80800454
    // 0x808008E4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    sumole_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x808008E4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_10:
    // 0x808008E8: b           L_80800B70
    // 0x808008EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B70;
    // 0x808008EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008F0:
    // 0x808008F0: jal         0x808017C4
    // 0x808008F4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    sumole_entrypoint_16(rdram, ctx);
        goto after_11;
    // 0x808008F4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x808008F8: b           L_80800B70
    // 0x808008FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B70;
    // 0x808008FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800900:
    // 0x80800900: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80800904: lw          $a0, 0x3C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X3C);
    // 0x80800908: jal         0x80106790
    // 0x8080090C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_80106790(rdram, ctx);
        goto after_12;
    // 0x8080090C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_12:
    // 0x80800910: lh          $v1, 0x3A($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X3A);
    // 0x80800914: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800918: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8080091C: beq         $v1, $at, L_8080094C
    if (ctx->r3 == ctx->r1) {
        // 0x80800920: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080094C;
    }
    // 0x80800920: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800924: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800928: beq         $v1, $at, L_8080096C
    if (ctx->r3 == ctx->r1) {
        // 0x8080092C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080096C;
    }
    // 0x8080092C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800930: beq         $v1, $at, L_8080098C
    if (ctx->r3 == ctx->r1) {
        // 0x80800934: lw          $t5, 0x30($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X30);
            goto L_8080098C;
    }
    // 0x80800934: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x80800938: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080093C: beq         $v1, $at, L_808009C8
    if (ctx->r3 == ctx->r1) {
        // 0x80800940: lui         $v0, 0x8080
        ctx->r2 = S32(RELOC_HI16(3158, 0X256C) << 16);
            goto L_808009C8;
    }
    // 0x80800940: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3158, 0X256C) << 16);
    // 0x80800944: b           L_80800B70
    // 0x80800948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B70;
    // 0x80800948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080094C:
    // 0x8080094C: jal         0x80086928
    // 0x80800950: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    _chmolehill_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x80800950: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_13:
    // 0x80800954: beq         $v0, $zero, L_80800B6C
    if (ctx->r2 == 0) {
        // 0x80800958: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    // 0x80800958: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080095C: jal         0x80086918
    // 0x80800960: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chmolehill_entrypoint_1(rdram, ctx);
        goto after_14;
    // 0x80800960: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_14:
    // 0x80800964: b           L_80800B70
    // 0x80800968: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B70;
    // 0x80800968: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080096C:
    // 0x8080096C: jal         0x80086928
    // 0x80800970: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    _chmolehill_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x80800970: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_15:
    // 0x80800974: beq         $v0, $zero, L_80800B6C
    if (ctx->r2 == 0) {
        // 0x80800978: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800B6C;
    }
    // 0x80800978: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080097C: jal         0x80086918
    // 0x80800980: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _chmolehill_entrypoint_1(rdram, ctx);
        goto after_16;
    // 0x80800980: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_16:
    // 0x80800984: b           L_80800B70
    // 0x80800988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B70;
    // 0x80800988: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080098C:
    // 0x8080098C: lwc1        $f8, 0x54($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X54);
    // 0x80800990: addiu       $a0, $zero, 0x18BB
    ctx->r4 = ADD32(0, 0X18BB);
    // 0x80800994: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800998: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8080099C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x808009A0: nop

    // 0x808009A4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x808009A8: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x808009AC: lbu         $v0, 0xE($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0XE);
    // 0x808009B0: blez        $v0, L_80800B6C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x808009B4: addiu       $a1, $v0, -0x1
        ctx->r5 = ADD32(ctx->r2, -0X1);
            goto L_80800B6C;
    }
    // 0x808009B4: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x808009B8: jal         0x800861A0
    // 0x808009BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    _chintrotext_entrypoint_1(rdram, ctx);
        goto after_17;
    // 0x808009BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_17:
    // 0x808009C0: b           L_80800B70
    // 0x808009C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B70;
    // 0x808009C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009C8:
    // 0x808009C8: addiu       $v0, $v0, 0x256C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(3158, 0X256C));
    // 0x808009CC: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
L_808009D0:
    // 0x808009D0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x808009D4: lwc1        $f16, 0x54($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X54);
    // 0x808009D8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x808009DC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x808009E0: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x808009E4: nop

    // 0x808009E8: sll         $t3, $t4, 4
    ctx->r11 = S32(ctx->r12 << 4);
    // 0x808009EC: addu        $t5, $a3, $t3
    ctx->r13 = ADD32(ctx->r7, ctx->r11);
    // 0x808009F0: lh          $t6, 0x6($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X6);
    // 0x808009F4: bne         $t0, $t6, L_80800A14
    if (ctx->r8 != ctx->r14) {
        // 0x808009F8: nop
    
            goto L_80800A14;
    }
    // 0x808009F8: nop

    // 0x808009FC: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80800A00: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800A04: jal         0x80108B04
    // 0x80800A08: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_80108B04(rdram, ctx);
        goto after_18;
    // 0x80800A08: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_18:
    // 0x80800A0C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80800A10: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
L_80800A14:
    // 0x80800A14: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(3158, 0X25D8) << 16);
    // 0x80800A18: addiu       $t7, $t7, 0x25D8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(3158, 0X25D8));
    // 0x80800A1C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80800A20: bnel        $v0, $t7, L_808009D0
    if (ctx->r2 != ctx->r15) {
        // 0x80800A24: lw          $t1, 0x30($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X30);
            goto L_808009D0;
    }
    goto skip_0;
    // 0x80800A24: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80800A28: b           L_80800B70
    // 0x80800A2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800B70;
    // 0x80800A2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A30:
    // 0x80800A30: lwc1        $f4, 0x54($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X54);
    // 0x80800A34: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800A38: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80800A3C: nop

    // 0x80800A40: sll         $t4, $t2, 4
    ctx->r12 = S32(ctx->r10 << 4);
    // 0x80800A44: addu        $t3, $a3, $t4
    ctx->r11 = ADD32(ctx->r7, ctx->r12);
    // 0x80800A48: lbu         $t5, 0xF($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0XF);
    // 0x80800A4C: beq         $t5, $zero, L_80800A90
    if (ctx->r13 == 0) {
        // 0x80800A50: nop
    
            goto L_80800A90;
    }
    // 0x80800A50: nop

    // 0x80800A54: jal         0x80101080
    // 0x80800A58: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_80101080(rdram, ctx);
        goto after_19;
    // 0x80800A58: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_19:
    // 0x80800A5C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80800A60: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80800A64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A68: lwc1        $f8, 0x54($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X54);
    // 0x80800A6C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800A70: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80800A74: nop

    // 0x80800A78: sll         $t7, $t1, 4
    ctx->r15 = S32(ctx->r9 << 4);
    // 0x80800A7C: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80800A80: jal         0x80089610
    // 0x80800A84: lbu         $a1, 0xF($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0XF);
    _ncpoddialog_entrypoint_8(rdram, ctx);
        goto after_20;
    // 0x80800A84: lbu         $a1, 0xF($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0XF);
    after_20:
    // 0x80800A88: b           L_80800B74
    // 0x80800A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B74;
    // 0x80800A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A90:
    // 0x80800A90: b           L_80800B70
    // 0x80800A94: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800B70;
    // 0x80800A94: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800A98:
    // 0x80800A98: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80800A9C: slti        $at, $v1, 0x26
    ctx->r1 = SIGNED(ctx->r3) < 0X26 ? 1 : 0;
    // 0x80800AA0: bne         $at, $zero, L_80800ABC
    if (ctx->r1 != 0) {
        // 0x80800AA4: addiu       $t9, $v1, -0x7
        ctx->r25 = ADD32(ctx->r3, -0X7);
            goto L_80800ABC;
    }
    // 0x80800AA4: addiu       $t9, $v1, -0x7
    ctx->r25 = ADD32(ctx->r3, -0X7);
    // 0x80800AA8: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80800AAC: beql        $v1, $at, L_80800AE0
    if (ctx->r3 == ctx->r1) {
        // 0x80800AB0: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800AE0;
    }
    goto skip_1;
    // 0x80800AB0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x80800AB4: b           L_80800B70
    // 0x80800AB8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800B70;
    // 0x80800AB8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800ABC:
    // 0x80800ABC: sltiu       $at, $t9, 0x1F
    ctx->r1 = ctx->r25 < 0X1F ? 1 : 0;
    // 0x80800AC0: beq         $at, $zero, L_80800B48
    if (ctx->r1 == 0) {
        // 0x80800AC4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800B48;
    }
    // 0x80800AC4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800AC8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3158, 0X23D4) << 16);
    // 0x80800ACC: addu        $at, $at, $t9
    gpr jr_addend_80800AD4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800AD0: lw          $t9, 0x23D4($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3158, 0X23D4));
    // 0x80800AD4: jr          $t9
    // 0x80800AD8: nop

    switch (jr_addend_80800AD4 >> 2) {
        case 0: goto L_80800AF8; break;
        case 1: goto L_80800B48; break;
        case 2: goto L_80800B48; break;
        case 3: goto L_80800B48; break;
        case 4: goto L_80800B48; break;
        case 5: goto L_80800B48; break;
        case 6: goto L_80800AF8; break;
        case 7: goto L_80800B48; break;
        case 8: goto L_80800AF8; break;
        case 9: goto L_80800B48; break;
        case 10: goto L_80800B48; break;
        case 11: goto L_80800B48; break;
        case 12: goto L_80800B48; break;
        case 13: goto L_80800B48; break;
        case 14: goto L_80800B48; break;
        case 15: goto L_80800B48; break;
        case 16: goto L_80800B48; break;
        case 17: goto L_80800B48; break;
        case 18: goto L_80800B48; break;
        case 19: goto L_80800B48; break;
        case 20: goto L_80800B48; break;
        case 21: goto L_80800B48; break;
        case 22: goto L_80800B48; break;
        case 23: goto L_80800ADC; break;
        case 24: goto L_80800B48; break;
        case 25: goto L_80800B48; break;
        case 26: goto L_80800AF8; break;
        case 27: goto L_80800B48; break;
        case 28: goto L_80800B48; break;
        case 29: goto L_80800B48; break;
        case 30: goto L_80800ADC; break;
        default: switch_error(__func__, 0x80800AD4, 0x808023D4);
    }
    // 0x80800AD8: nop

L_80800ADC:
    // 0x80800ADC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80800AE0:
    // 0x80800AE0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800AE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800AE8: jal         0x808002E0
    // 0x80800AEC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_808002E0_sumole(rdram, ctx);
        goto after_21;
    // 0x80800AEC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_21:
    // 0x80800AF0: b           L_80800B70
    // 0x80800AF4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800B70;
    // 0x80800AF4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800AF8:
    // 0x80800AF8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800AFC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800B00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800B04: jal         0x808002E0
    // 0x80800B08: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_808002E0_sumole(rdram, ctx);
        goto after_22;
    // 0x80800B08: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_22:
    // 0x80800B0C: jal         0x800C6E38
    // 0x80800B10: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    func_800C6E38(rdram, ctx);
        goto after_23;
    // 0x80800B10: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_23:
    // 0x80800B14: beq         $v0, $zero, L_80800B30
    if (ctx->r2 == 0) {
        // 0x80800B18: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80800B30;
    }
    // 0x80800B18: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800B1C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800B20: jal         0x80800454
    // 0x80800B24: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    sumole_entrypoint_2(rdram, ctx);
        goto after_24;
    // 0x80800B24: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_24:
    // 0x80800B28: b           L_80800B70
    // 0x80800B2C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800B70;
    // 0x80800B2C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800B30:
    // 0x80800B30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800B34: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80800B38: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80800B3C: swc1        $f16, 0x54($t2)
    MEM_W(0X54, ctx->r10) = ctx->f16.u32l;
    // 0x80800B40: jal         0x80800454
    // 0x80800B44: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    sumole_entrypoint_2(rdram, ctx);
        goto after_25;
    // 0x80800B44: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_25:
L_80800B48:
    // 0x80800B48: b           L_80800B70
    // 0x80800B4C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800B70;
    // 0x80800B4C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800B50:
    // 0x80800B50: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800B54: jal         0x80800000
    // 0x80800B58: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80800000_sumole(rdram, ctx);
        goto after_26;
    // 0x80800B58: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_26:
    // 0x80800B5C: b           L_80800B74
    // 0x80800B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800B74;
    // 0x80800B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B64:
    // 0x80800B64: b           L_80800B70
    // 0x80800B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800B70;
    // 0x80800B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B6C:
    // 0x80800B6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B70:
    // 0x80800B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B74:
    // 0x80800B74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800B78: jr          $ra
    // 0x80800B7C: nop

    return;
    // 0x80800B7C: nop

;}
RECOMP_FUNC void func_808006B8_chfactorylight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808006BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808006C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006CC: jal         0x80100094
    // 0x808006D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006D4: lhu         $a0, 0x72($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X72);
    // 0x808006D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808006E0: srl         $t6, $a0, 10
    ctx->r14 = S32(U32(ctx->r4) >> 10);
    // 0x808006E4: beq         $t6, $at, L_808006F4
    if (ctx->r14 == ctx->r1) {
        // 0x808006E8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808006F4;
    }
    // 0x808006E8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808006EC: bne         $t6, $at, L_8080074C
    if (ctx->r14 != ctx->r1) {
        // 0x808006F0: nop
    
            goto L_8080074C;
    }
    // 0x808006F0: nop

L_808006F4:
    // 0x808006F4: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x808006F8: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x808006FC: lw          $t9, 0x14($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X14);
    // 0x80800700: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80800704: lw          $t1, 0x18($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X18);
    // 0x80800708: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8080070C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800710: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80800714: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80800718: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8080071C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800720: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80800724: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80800728: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8080072C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800730: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800734: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800738: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080073C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80800740: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800744: jal         0x800DF5D8
    // 0x80800748: nop

    func_800DF5D8(rdram, ctx);
        goto after_1;
    // 0x80800748: nop

    after_1:
L_8080074C:
    // 0x8080074C: jal         0x80101970
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101970(rdram, ctx);
        goto after_2;
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800754: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80800758: addiu       $a1, $a1, 0x15D0
    ctx->r5 = ADD32(ctx->r5, 0X15D0);
    // 0x8080075C: jal         0x80101808
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101808(rdram, ctx);
        goto after_3;
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800764: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800768: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080076C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800770: jr          $ra
    // 0x80800774: nop

    return;
    // 0x80800774: nop

;}
RECOMP_FUNC void func_800C11F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C11F8: lbu         $t9, 0x7A($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X7A);
    // 0x800C11FC: sll         $t8, $a1, 5
    ctx->r24 = S32(ctx->r5 << 5);
    // 0x800C1200: andi        $t0, $t9, 0xFF1F
    ctx->r8 = ctx->r25 & 0XFF1F;
    // 0x800C1204: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800C1208: jr          $ra
    // 0x800C120C: sb          $t1, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r9;
    return;
    // 0x800C120C: sb          $t1, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r9;
;}
