#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void fxsplash_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800068: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800070: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800074: jal         0x800B5BE4
    // 0x80800078: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800B5BE4(rdram, ctx);
        goto after_0;
    // 0x80800078: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8080007C: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800080: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800084: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800088: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8080008C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800090: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800094: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800098: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080009C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x808000A0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808000A4: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x808000A8: sra         $v1, $t1, 16
    ctx->r3 = S32(SIGNED(ctx->r9) >> 16);
    // 0x808000AC: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x808000B0: sra         $a1, $t7, 16
    ctx->r5 = S32(SIGNED(ctx->r15) >> 16);
    // 0x808000B4: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x808000B8: sra         $t9, $a3, 16
    ctx->r25 = S32(SIGNED(ctx->r7) >> 16);
    // 0x808000BC: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x808000C0: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x808000C4: jal         0x800BA6B0
    // 0x808000C8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_800BA6B0(rdram, ctx);
        goto after_1;
    // 0x808000C8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x808000CC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x808000D0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808000D4: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x808000D8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x808000DC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x808000E0: nop

    // 0x808000E4: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x808000E8: jal         0x800BA4D0
    // 0x808000EC: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    func_800BA4D0(rdram, ctx);
        goto after_2;
    // 0x808000EC: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    after_2:
    // 0x808000F0: lui         $a1, 0x8009
    ctx->r5 = S32(0X8009 << 16);
    // 0x808000F4: addiu       $a1, $a1, -0x7528
    ctx->r5 = ADD32(ctx->r5, -0X7528);
    // 0x808000F8: jal         0x800BA544
    // 0x808000FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800BA544(rdram, ctx);
        goto after_3;
    // 0x808000FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80800100: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2846, 0X144) << 16);
    // 0x80800104: addiu       $t7, $t7, 0x144
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2846, 0X144));
    // 0x80800108: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080010C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800110: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80800114: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800118: jal         0x800BABB8
    // 0x8080011C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x8080011C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80800120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800124: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800128: jr          $ra
    // 0x8080012C: nop

    return;
    // 0x8080012C: nop

;}
RECOMP_FUNC void _gczoombox_entrypoint_36(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C00: syscall     654
    recomp_syscall_handler(rdram, ctx, 0x80087C00);
    return;
    // 0x80087C04: addi        $t0, $zero, 0x90
    ctx->r8 = ADD32(0, 0X90);
;}
RECOMP_FUNC void func_80800C10_chdinofamilysmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C10: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800C14: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x80800C18: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80800C1C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800C20: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x80800C24: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80800C28: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80800C2C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80800C30: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80800C34: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80800C38: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80800C3C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800C40: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800C44: jal         0x80100094
    // 0x80800C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800C4C: beq         $v0, $zero, L_80800C68
    if (ctx->r2 == 0) {
        // 0x80800C50: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80800C68;
    }
    // 0x80800C50: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800C54: jal         0x80100094
    // 0x80800C58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800C58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800C5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C60: jal         0x80089888
    // 0x80800C64: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    _sumumbofx_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800C64: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_2:
L_80800C68:
    // 0x80800C68: lhu         $t6, 0x72($s6)
    ctx->r14 = MEM_HU(ctx->r22, 0X72);
    // 0x80800C6C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800C70: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800C74: bnel        $t7, $at, L_80800DB8
    if (ctx->r15 != ctx->r1) {
        // 0x80800C78: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80800DB8;
    }
    goto skip_0;
    // 0x80800C78: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_0:
    // 0x80800C7C: jal         0x801015D0
    // 0x80800C80: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_801015D0(rdram, ctx);
        goto after_3;
    // 0x80800C80: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_3:
    // 0x80800C84: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2404, 0XFA0) << 16);
    // 0x80800C88: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2404, 0XF94) << 16);
    // 0x80800C8C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800C90: addiu       $s3, $s3, 0xF94
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2404, 0XF94));
    // 0x80800C94: addiu       $s0, $s0, 0xFA0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2404, 0XFA0));
    // 0x80800C98: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80800C9C:
    // 0x80800C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA0: jal         0x800EE7F8
    // 0x80800CA4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x80800CA4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x80800CA8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800CAC: c.eq.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl == ctx->f4.fl;
    // 0x80800CB0: nop

    // 0x80800CB4: bc1tl       L_80800D50
    if (c1cs) {
        // 0x80800CB8: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80800D50;
    }
    goto skip_1;
    // 0x80800CB8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_1:
    // 0x80800CBC: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800CC0: c.eq.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl == ctx->f6.fl;
    // 0x80800CC4: nop

    // 0x80800CC8: bc1tl       L_80800D50
    if (c1cs) {
        // 0x80800CCC: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80800D50;
    }
    goto skip_2;
    // 0x80800CCC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    skip_2:
    // 0x80800CD0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800CD4: sll         $t8, $s1, 4
    ctx->r24 = S32(ctx->r17 << 4);
    // 0x80800CD8: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80800CDC: c.eq.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl == ctx->f8.fl;
    // 0x80800CE0: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80800CE4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800CE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800CEC: bc1t        L_80800D4C
    if (c1cs) {
        // 0x80800CF0: addiu       $t9, $zero, 0xA0
        ctx->r25 = ADD32(0, 0XA0);
            goto L_80800D4C;
    }
    // 0x80800CF0: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x80800CF4: subu        $s2, $t9, $t8
    ctx->r18 = SUB32(ctx->r25, ctx->r24);
    // 0x80800CF8: addiu       $s4, $s6, 0x4
    ctx->r20 = ADD32(ctx->r22, 0X4);
    // 0x80800CFC: jal         0x800DF744
    // 0x80800D00: addiu       $s5, $s6, 0x44
    ctx->r21 = ADD32(ctx->r22, 0X44);
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x80800D00: addiu       $s5, $s6, 0x44
    ctx->r21 = ADD32(ctx->r22, 0X44);
    after_5:
    // 0x80800D04: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80800D08: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800D0C: jal         0x800DF500
    // 0x80800D10: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    func_800DF500(rdram, ctx);
        goto after_6;
    // 0x80800D10: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_6:
    // 0x80800D14: jal         0x800DF410
    // 0x80800D18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800DF410(rdram, ctx);
        goto after_7;
    // 0x80800D18: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x80800D1C: jal         0x800DF830
    // 0x80800D20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF830(rdram, ctx);
        goto after_8;
    // 0x80800D20: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x80800D24: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x80800D28: jal         0x800D674C
    // 0x80800D2C: lhu         $a0, 0x14($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X14);
    func_800D674C(rdram, ctx);
        goto after_9;
    // 0x80800D2C: lhu         $a0, 0x14($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X14);
    after_9:
    // 0x80800D30: lw          $a3, 0x38($s6)
    ctx->r7 = MEM_W(ctx->r22, 0X38);
    // 0x80800D34: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80800D38: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800D3C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800D40: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80800D44: jal         0x800DE498
    // 0x80800D48: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800DE498(rdram, ctx);
        goto after_10;
    // 0x80800D48: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_10:
L_80800D4C:
    // 0x80800D4C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80800D50:
    // 0x80800D50: addiu       $s0, $s0, -0xC
    ctx->r16 = ADD32(ctx->r16, -0XC);
    // 0x80800D54: bne         $s1, $zero, L_80800C9C
    if (ctx->r17 != 0) {
        // 0x80800D58: addiu       $s3, $s3, -0xC
        ctx->r19 = ADD32(ctx->r19, -0XC);
            goto L_80800C9C;
    }
    // 0x80800D58: addiu       $s3, $s3, -0xC
    ctx->r19 = ADD32(ctx->r19, -0XC);
    // 0x80800D5C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2404, 0XF70) << 16);
    // 0x80800D60: addiu       $a0, $a0, 0xF70
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2404, 0XF70));
    // 0x80800D64: jal         0x800EE7F8
    // 0x80800D68: addiu       $a1, $s6, 0x28
    ctx->r5 = ADD32(ctx->r22, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x80800D68: addiu       $a1, $s6, 0x28
    ctx->r5 = ADD32(ctx->r22, 0X28);
    after_11:
    // 0x80800D6C: lwc1        $f12, 0x28($s6)
    ctx->f12.u32l = MEM_W(ctx->r22, 0X28);
    // 0x80800D70: c.eq.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl == ctx->f12.fl;
    // 0x80800D74: nop

    // 0x80800D78: bc1tl       L_80800DB8
    if (c1cs) {
        // 0x80800D7C: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80800DB8;
    }
    goto skip_3;
    // 0x80800D7C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_3:
    // 0x80800D80: lwc1        $f14, 0x2C($s6)
    ctx->f14.u32l = MEM_W(ctx->r22, 0X2C);
    // 0x80800D84: c.eq.s      $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f20.fl == ctx->f14.fl;
    // 0x80800D88: nop

    // 0x80800D8C: bc1tl       L_80800DB8
    if (c1cs) {
        // 0x80800D90: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80800DB8;
    }
    goto skip_4;
    // 0x80800D90: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_4:
    // 0x80800D94: lwc1        $f0, 0x30($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X30);
    // 0x80800D98: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x80800D9C: nop

    // 0x80800DA0: bc1tl       L_80800DB8
    if (c1cs) {
        // 0x80800DA4: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80800DB8;
    }
    goto skip_5;
    // 0x80800DA4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_5:
    // 0x80800DA8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800DAC: jal         0x800DF500
    // 0x80800DB0: nop

    func_800DF500(rdram, ctx);
        goto after_12;
    // 0x80800DB0: nop

    after_12:
    // 0x80800DB4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80800DB8:
    // 0x80800DB8: jal         0x801018A4
    // 0x80800DBC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_801018A4(rdram, ctx);
        goto after_13;
    // 0x80800DBC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_13:
    // 0x80800DC0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800DC4: jal         0x80100094
    // 0x80800DC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_14;
    // 0x80800DC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800DCC: beq         $v0, $zero, L_80800DE8
    if (ctx->r2 == 0) {
        // 0x80800DD0: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80800DE8;
    }
    // 0x80800DD0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80800DD4: jal         0x80100094
    // 0x80800DD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_15;
    // 0x80800DD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800DDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800DE0: jal         0x80089880
    // 0x80800DE4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    _sumumbofx_entrypoint_8(rdram, ctx);
        goto after_16;
    // 0x80800DE4: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_16:
L_80800DE8:
    // 0x80800DE8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800DEC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800DF0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80800DF4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80800DF8: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80800DFC: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x80800E00: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x80800E04: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x80800E08: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x80800E0C: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x80800E10: jr          $ra
    // 0x80800E14: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800E14: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8080084C_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080084C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800858: jal         0x808006D0
    // 0x8080085C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808006D0_bsride(rdram, ctx);
        goto after_0;
    // 0x8080085C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800860: jal         0x8080008C
    // 0x80800864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8080008C_bsride(rdram, ctx);
        goto after_1;
    // 0x80800864: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080086C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800870: jr          $ra
    // 0x80800874: nop

    return;
    // 0x80800874: nop

;}
RECOMP_FUNC void func_8080000C_chcaveofhorrorsdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: jal         0x808001A4
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_808001A4_chcaveofhorrorsdoors(rdram, ctx);
        goto after_0;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800020: jal         0x800DA298
    // 0x80800024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800028: beq         $v0, $zero, L_80800040
    if (ctx->r2 == 0) {
        // 0x8080002C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800040;
    }
    // 0x8080002C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800030: jal         0x800FFAB0
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800038: b           L_8080005C
    // 0x8080003C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080005C;
    // 0x8080003C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800040:
    // 0x80800040: jal         0x80109EEC
    // 0x80800044: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80109EEC(rdram, ctx);
        goto after_3;
    // 0x80800044: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_3:
    // 0x80800048: jal         0x80089D00
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x8080004C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800050: jal         0x8010A63C
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_5;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080005C:
    // 0x8080005C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800060: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800064: jr          $ra
    // 0x80800068: nop

    return;
    // 0x80800068: nop

;}
RECOMP_FUNC void func_800E80A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E80A0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800E80A4: lw          $t6, -0x2A0C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A0C);
    // 0x800E80A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E80AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E80B0: bnel        $t6, $zero, L_800E80F8
    if (ctx->r14 != 0) {
        // 0x800E80B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E80F8;
    }
    goto skip_0;
    // 0x800E80B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800E80B8: jal         0x8001ACCC
    // 0x800E80BC: ori         $a0, $zero, 0xA040
    ctx->r4 = 0 | 0XA040;
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x800E80BC: ori         $a0, $zero, 0xA040
    ctx->r4 = 0 | 0XA040;
    after_0:
    // 0x800E80C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E80C4: addiu       $a0, $a0, -0x2A10
    ctx->r4 = ADD32(ctx->r4, -0X2A10);
    // 0x800E80C8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800E80CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E80D0: andi        $t7, $v0, 0x3F
    ctx->r15 = ctx->r2 & 0X3F;
    // 0x800E80D4: sw          $v0, -0x2A0C($at)
    MEM_W(-0X2A0C, ctx->r1) = ctx->r2;
    // 0x800E80D8: beq         $t7, $zero, L_800E80F4
    if (ctx->r15 == 0) {
        // 0x800E80DC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800E80F4;
    }
    // 0x800E80DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800E80E0:
    // 0x800E80E0: addiu       $t8, $v1, 0x2
    ctx->r24 = ADD32(ctx->r3, 0X2);
    // 0x800E80E4: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x800E80E8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800E80EC: bne         $t9, $zero, L_800E80E0
    if (ctx->r25 != 0) {
        // 0x800E80F0: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800E80E0;
    }
    // 0x800E80F0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800E80F4:
    // 0x800E80F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E80F8:
    // 0x800E80F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E80FC: jr          $ra
    // 0x800E8100: nop

    return;
    // 0x800E8100: nop

;}
RECOMP_FUNC void badialog_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080007C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800080: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800084: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800088: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8080008C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800090: jal         0x8009C128
    // 0x80800094: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80800094: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800098: jal         0x8008E938
    // 0x8080009C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8008E938(rdram, ctx);
        goto after_1;
    // 0x8080009C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x808000A0: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x808000A4: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x808000A8: lui         $t8, 0x8008
    ctx->r24 = S32(0X8008 << 16);
    // 0x808000AC: addiu       $t8, $t8, 0x47D0
    ctx->r24 = ADD32(ctx->r24, 0X47D0);
    // 0x808000B0: addiu       $t7, $t7, 0x47C8
    ctx->r15 = ADD32(ctx->r15, 0X47C8);
    // 0x808000B4: addiu       $t6, $t6, 0x47C0
    ctx->r14 = ADD32(ctx->r14, 0X47C0);
    // 0x808000B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000BC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x808000C0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x808000C4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808000C8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x808000CC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808000D0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x808000D4: jal         0x800C0534
    // 0x808000D8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_800C0534(rdram, ctx);
        goto after_2;
    // 0x808000D8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_2:
    // 0x808000DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808000E4: jr          $ra
    // 0x808000E8: nop

    return;
    // 0x808000E8: nop

;}
RECOMP_FUNC void _sufreezy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B68: syscall     804
    recomp_syscall_handler(rdram, ctx, 0x80089B68);
    return;
    // 0x80089B6C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800E0A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0A98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E0A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E0AA0: jal         0x8001BAFC
    // 0x800E0AA4: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800E0AA4: nop

    after_0:
    // 0x800E0AA8: addiu       $t6, $v0, 0x20
    ctx->r14 = ADD32(ctx->r2, 0X20);
    // 0x800E0AAC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800E0AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E0AB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E0AB8: jr          $ra
    // 0x800E0ABC: nop

    return;
    // 0x800E0ABC: nop

;}
RECOMP_FUNC void bapackctrl_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800088: jal         0x8009EA58
    // 0x8080008C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009EA58(rdram, ctx);
        goto after_0;
    // 0x8080008C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800098: jr          $ra
    // 0x8080009C: nop

    return;
    // 0x8080009C: nop

;}
RECOMP_FUNC void func_80093F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093F7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80093F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093F84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80093F88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80093F8C: lw          $t7, 0x50($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X50);
    // 0x80093F90: jal         0x800D674C
    // 0x80093F94: lw          $a0, 0x10C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10C);
    func_800D674C(rdram, ctx);
        goto after_0;
    // 0x80093F94: lw          $a0, 0x10C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10C);
    after_0:
    // 0x80093F98: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80093F9C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80093FA0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80093FA4: bnel        $t8, $zero, L_80093FC4
    if (ctx->r24 != 0) {
        // 0x80093FA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80093FC4;
    }
    goto skip_0;
    // 0x80093FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80093FAC: lw          $t0, 0x50($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X50);
    // 0x80093FB0: lw          $a0, 0x10C($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X10C);
    // 0x80093FB4: jal         0x800D62E4
    // 0x80093FB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800D62E4(rdram, ctx);
        goto after_1;
    // 0x80093FB8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80093FBC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80093FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80093FC4:
    // 0x80093FC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80093FC8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80093FCC: jr          $ra
    // 0x80093FD0: nop

    return;
    // 0x80093FD0: nop

;}
RECOMP_FUNC void func_80803464_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803464: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803468: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080346C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803470: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80803474: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80803478: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8080347C: jal         0x800F1DF4
    // 0x80803480: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800F1DF4(rdram, ctx);
        goto after_0;
    // 0x80803480: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80803484: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80803488: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080348C: jal         0x800EE7F8
    // 0x80803490: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80803490: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80803494: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80803498: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080349C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808034A0: lh          $t7, 0xC($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XC);
    // 0x808034A4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x808034A8: nop

    // 0x808034AC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808034B0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808034B4: jal         0x800EF1B8
    // 0x808034B8: nop

    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x808034B8: nop

    after_2:
    // 0x808034BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808034C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808034C4: jr          $ra
    // 0x808034C8: nop

    return;
    // 0x808034C8: nop

;}
RECOMP_FUNC void func_8008F854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F854: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F85C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008F860: jal         0x800D1B34
    // 0x8008F864: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D1B34(rdram, ctx);
        goto after_0;
    // 0x8008F864: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8008F868: jal         0x800D1824
    // 0x8008F86C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800D1824(rdram, ctx);
        goto after_1;
    // 0x8008F86C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8008F870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008F878: jr          $ra
    // 0x8008F87C: nop

    return;
    // 0x8008F87C: nop

;}
RECOMP_FUNC void func_800BD28C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD28C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BD290: bne         $a1, $at, L_800BD2C8
    if (ctx->r5 != ctx->r1) {
        // 0x800BD294: sb          $a1, 0x5($a0)
        MEM_B(0X5, ctx->r4) = ctx->r5;
            goto L_800BD2C8;
    }
    // 0x800BD294: sb          $a1, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r5;
    // 0x800BD298: sb          $zero, 0x16($a0)
    MEM_B(0X16, ctx->r4) = 0;
    // 0x800BD29C: sb          $zero, 0x17($a0)
    MEM_B(0X17, ctx->r4) = 0;
    // 0x800BD2A0: addiu       $v1, $a0, 0x2
    ctx->r3 = ADD32(ctx->r4, 0X2);
    // 0x800BD2A4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x800BD2A8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800BD2AC:
    // 0x800BD2AC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BD2B0: sb          $zero, 0x17($v1)
    MEM_B(0X17, ctx->r3) = 0;
    // 0x800BD2B4: sb          $zero, 0x18($v1)
    MEM_B(0X18, ctx->r3) = 0;
    // 0x800BD2B8: sb          $zero, 0x19($v1)
    MEM_B(0X19, ctx->r3) = 0;
    // 0x800BD2BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800BD2C0: bne         $v0, $a0, L_800BD2AC
    if (ctx->r2 != ctx->r4) {
        // 0x800BD2C4: sb          $zero, 0x12($v1)
        MEM_B(0X12, ctx->r3) = 0;
            goto L_800BD2AC;
    }
    // 0x800BD2C4: sb          $zero, 0x12($v1)
    MEM_B(0X12, ctx->r3) = 0;
L_800BD2C8:
    // 0x800BD2C8: jr          $ra
    // 0x800BD2CC: nop

    return;
    // 0x800BD2CC: nop

;}
RECOMP_FUNC void func_800CDBA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDBA8: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800CDBAC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800CDBB0: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x800CDBB4: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x800CDBB8: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x800CDBBC: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x800CDBC0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x800CDBC4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x800CDBC8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800CDBCC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800CDBD0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800CDBD4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800CDBD8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800CDBDC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800CDBE0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800CDBE4: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x800CDBE8: sw          $a2, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r6;
    // 0x800CDBEC: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800CDBF0: jal         0x800CB854
    // 0x800CDBF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_0;
    // 0x800CDBF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800CDBF8: beql        $v0, $zero, L_800CDC20
    if (ctx->r2 == 0) {
        // 0x800CDBFC: sw          $zero, 0x98($sp)
        MEM_W(0X98, ctx->r29) = 0;
            goto L_800CDC20;
    }
    goto skip_0;
    // 0x800CDBFC: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    skip_0:
    // 0x800CDC00: jal         0x800CB854
    // 0x800CDC04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800CB854(rdram, ctx);
        goto after_1;
    // 0x800CDC04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800CDC08: addiu       $t6, $v0, 0x1F
    ctx->r14 = ADD32(ctx->r2, 0X1F);
    // 0x800CDC0C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CDC10: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x800CDC14: b           L_800CDC20
    // 0x800CDC18: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
        goto L_800CDC20;
    // 0x800CDC18: sw          $t8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r24;
    // 0x800CDC1C: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
L_800CDC20:
    // 0x800CDC20: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x800CDC24: jal         0x800EE7F8
    // 0x800CDC28: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x800CDC28: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    after_2:
    // 0x800CDC2C: slti        $at, $s7, 0x2
    ctx->r1 = SIGNED(ctx->r23) < 0X2 ? 1 : 0;
    // 0x800CDC30: bne         $at, $zero, L_800CDC5C
    if (ctx->r1 != 0) {
        // 0x800CDC34: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800CDC5C;
    }
    // 0x800CDC34: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x800CDC38: lw          $s1, 0xCC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XCC);
    // 0x800CDC3C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_800CDC40:
    // 0x800CDC40: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x800CDC44: jal         0x800EF04C
    // 0x800CDC48: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_3;
    // 0x800CDC48: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800CDC4C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800CDC50: bne         $s4, $s7, L_800CDC40
    if (ctx->r20 != ctx->r23) {
        // 0x800CDC54: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800CDC40;
    }
    // 0x800CDC54: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800CDC58: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800CDC5C:
    // 0x800CDC5C: mtc1        $s7, $f6
    ctx->f6.u32l = ctx->r23;
    // 0x800CDC60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CDC64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CDC68: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CDC6C: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x800CDC70: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800CDC74: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800CDC78: jal         0x800EF334
    // 0x800CDC7C: nop

    func_800EF334(rdram, ctx);
        goto after_4;
    // 0x800CDC7C: nop

    after_4:
    // 0x800CDC80: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x800CDC84: jal         0x800EEAD4
    // 0x800CDC88: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    func_800EEAD4(rdram, ctx);
        goto after_5;
    // 0x800CDC88: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    after_5:
    // 0x800CDC8C: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800CDC90: lw          $s1, 0xCC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XCC);
    // 0x800CDC94: slti        $at, $s7, 0x2
    ctx->r1 = SIGNED(ctx->r23) < 0X2 ? 1 : 0;
    // 0x800CDC98: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800CDC9C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800CDCA0: bne         $at, $zero, L_800CDCE4
    if (ctx->r1 != 0) {
        // 0x800CDCA4: add.s       $f22, $f0, $f16
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f0.fl + ctx->f16.fl;
            goto L_800CDCE4;
    }
    // 0x800CDCA4: add.s       $f22, $f0, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x800CDCA8: addiu       $s0, $t9, 0x4
    ctx->r16 = ADD32(ctx->r25, 0X4);
L_800CDCAC:
    // 0x800CDCAC: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x800CDCB0: jal         0x800EEAD4
    // 0x800CDCB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_6;
    // 0x800CDCB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800CDCB8: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800CDCBC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800CDCC0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800CDCC4: add.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800CDCC8: c.lt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
    // 0x800CDCCC: nop

    // 0x800CDCD0: bc1f        L_800CDCDC
    if (!c1cs) {
        // 0x800CDCD4: nop
    
            goto L_800CDCDC;
    }
    // 0x800CDCD4: nop

    // 0x800CDCD8: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
L_800CDCDC:
    // 0x800CDCDC: bne         $s4, $s7, L_800CDCAC
    if (ctx->r20 != ctx->r23) {
        // 0x800CDCE0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800CDCAC;
    }
    // 0x800CDCE0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800CDCE4:
    // 0x800CDCE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800CDCE8: lwc1        $f6, 0x59A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X59A4);
    // 0x800CDCEC: addiu       $a0, $sp, 0xB4
    ctx->r4 = ADD32(ctx->r29, 0XB4);
    // 0x800CDCF0: mul.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x800CDCF4: jal         0x800BE444
    // 0x800CDCF8: nop

    func_800BE444(rdram, ctx);
        goto after_7;
    // 0x800CDCF8: nop

    after_7:
    // 0x800CDCFC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800CDD00: addiu       $s6, $sp, 0x70
    ctx->r22 = ADD32(ctx->r29, 0X70);
    // 0x800CDD04: addiu       $s5, $sp, 0xA0
    ctx->r21 = ADD32(ctx->r29, 0XA0);
    // 0x800CDD08: beq         $t0, $zero, L_800CDF6C
    if (ctx->r8 == 0) {
        // 0x800CDD0C: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800CDF6C;
    }
    // 0x800CDD0C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800CDD10: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
L_800CDD14:
    // 0x800CDD14: jal         0x800E9E88
    // 0x800CDD18: nop

    func_800E9E88(rdram, ctx);
        goto after_8;
    // 0x800CDD18: nop

    after_8:
    // 0x800CDD1C: lw          $t1, 0xC0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC0);
    // 0x800CDD20: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x800CDD24: jal         0x800E9EB4
    // 0x800CDD28: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    func_800E9EB4(rdram, ctx);
        goto after_9;
    // 0x800CDD28: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_9:
    // 0x800CDD2C: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x800CDD30: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x800CDD34: sltu        $at, $t2, $v0
    ctx->r1 = ctx->r10 < ctx->r2 ? 1 : 0;
    // 0x800CDD38: beql        $at, $zero, L_800CDF58
    if (ctx->r1 == 0) {
        // 0x800CDD3C: lw          $v0, 0xC0($sp)
        ctx->r2 = MEM_W(ctx->r29, 0XC0);
            goto L_800CDF58;
    }
    goto skip_1;
    // 0x800CDD3C: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
    skip_1:
L_800CDD40:
    // 0x800CDD40: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x800CDD44: lw          $v0, 0x8($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X8);
    // 0x800CDD48: sll         $t5, $v0, 27
    ctx->r13 = S32(ctx->r2 << 27);
    // 0x800CDD4C: bgez        $t5, L_800CDF3C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800CDD50: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_800CDF3C;
    }
    // 0x800CDD50: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800CDD54: beql        $t7, $zero, L_800CDF40
    if (ctx->r15 == 0) {
        // 0x800CDD58: lw          $t4, 0x88($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X88);
            goto L_800CDF40;
    }
    goto skip_2;
    // 0x800CDD58: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    skip_2:
    // 0x800CDD5C: lw          $s3, 0x0($t3)
    ctx->r19 = MEM_W(ctx->r11, 0X0);
    // 0x800CDD60: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x800CDD64: lw          $t8, 0x28($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X28);
    // 0x800CDD68: sll         $t0, $t8, 22
    ctx->r8 = S32(ctx->r24 << 22);
    // 0x800CDD6C: bgezl       $t0, L_800CDF40
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800CDD70: lw          $t4, 0x88($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X88);
            goto L_800CDF40;
    }
    goto skip_3;
    // 0x800CDD70: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    skip_3:
    // 0x800CDD74: beql        $t1, $s3, L_800CDF40
    if (ctx->r9 == ctx->r19) {
        // 0x800CDD78: lw          $t4, 0x88($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X88);
            goto L_800CDF40;
    }
    goto skip_4;
    // 0x800CDD78: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    skip_4:
    // 0x800CDD7C: lhu         $v0, 0x14($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X14);
    // 0x800CDD80: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800CDD84: beql        $v0, $zero, L_800CDF40
    if (ctx->r2 == 0) {
        // 0x800CDD88: lw          $t4, 0x88($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X88);
            goto L_800CDF40;
    }
    goto skip_5;
    // 0x800CDD88: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    skip_5:
    // 0x800CDD8C: beql        $v0, $at, L_800CDF40
    if (ctx->r2 == ctx->r1) {
        // 0x800CDD90: lw          $t4, 0x88($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X88);
            goto L_800CDF40;
    }
    goto skip_6;
    // 0x800CDD90: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    skip_6:
    // 0x800CDD94: lhu         $t2, 0x18($s3)
    ctx->r10 = MEM_HU(ctx->r19, 0X18);
    // 0x800CDD98: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800CDD9C: beql        $t3, $zero, L_800CDF40
    if (ctx->r11 == 0) {
        // 0x800CDDA0: lw          $t4, 0x88($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X88);
            goto L_800CDF40;
    }
    goto skip_7;
    // 0x800CDDA0: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    skip_7:
    // 0x800CDDA4: jal         0x80106790
    // 0x800CDDA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80106790(rdram, ctx);
        goto after_10;
    // 0x800CDDA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_10:
    // 0x800CDDAC: lw          $t4, 0x64($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X64);
    // 0x800CDDB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CDDB4: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x800CDDB8: sll         $t7, $t4, 14
    ctx->r15 = S32(ctx->r12 << 14);
    // 0x800CDDBC: bltzl       $t7, L_800CDF40
    if (SIGNED(ctx->r15) < 0) {
        // 0x800CDDC0: lw          $t4, 0x88($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X88);
            goto L_800CDF40;
    }
    goto skip_8;
    // 0x800CDDC0: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    skip_8:
    // 0x800CDDC4: lhu         $t6, 0x66($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X66);
    // 0x800CDDC8: and         $t9, $t6, $t8
    ctx->r25 = ctx->r14 & ctx->r24;
    // 0x800CDDCC: bnel        $t9, $zero, L_800CDF40
    if (ctx->r25 != 0) {
        // 0x800CDDD0: lw          $t4, 0x88($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X88);
            goto L_800CDF40;
    }
    goto skip_9;
    // 0x800CDDD0: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    skip_9:
    // 0x800CDDD4: jal         0x8008A018
    // 0x800CDDD8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    _subaddiecustomhits_entrypoint_5(rdram, ctx);
        goto after_11;
    // 0x800CDDD8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_11:
    // 0x800CDDDC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800CDDE0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800CDDE4: jal         0x800EEB40
    // 0x800CDDE8: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    func_800EEB40(rdram, ctx);
        goto after_12;
    // 0x800CDDE8: addiu       $a1, $sp, 0xB4
    ctx->r5 = ADD32(ctx->r29, 0XB4);
    after_12:
    // 0x800CDDEC: add.s       $f2, $f20, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x800CDDF0: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800CDDF4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800CDDF8: nop

    // 0x800CDDFC: bc1tl       L_800CDF40
    if (c1cs) {
        // 0x800CDE00: lw          $t4, 0x88($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X88);
            goto L_800CDF40;
    }
    goto skip_10;
    // 0x800CDE00: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    skip_10:
    // 0x800CDE04: jal         0x800EC3C4
    // 0x800CDE08: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_800EC3C4(rdram, ctx);
        goto after_13;
    // 0x800CDE08: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_13:
    // 0x800CDE0C: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x800CDE10: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800CDE14: beql        $t0, $zero, L_800CDE30
    if (ctx->r8 == 0) {
        // 0x800CDE18: lw          $v0, 0xC($s3)
        ctx->r2 = MEM_W(ctx->r19, 0XC);
            goto L_800CDE30;
    }
    goto skip_11;
    // 0x800CDE18: lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC);
    skip_11:
    // 0x800CDE1C: jalr        $t0
    // 0x800CDE20: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_14;
    // 0x800CDE20: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    after_14:
    // 0x800CDE24: beql        $v0, $zero, L_800CDF40
    if (ctx->r2 == 0) {
        // 0x800CDE28: lw          $t4, 0x88($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X88);
            goto L_800CDF40;
    }
    goto skip_12;
    // 0x800CDE28: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    skip_12:
    // 0x800CDE2C: lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC);
L_800CDE30:
    // 0x800CDE30: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800CDE34: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800CDE38: beq         $v0, $zero, L_800CDE50
    if (ctx->r2 == 0) {
        // 0x800CDE3C: nop
    
            goto L_800CDE50;
    }
    // 0x800CDE3C: nop

    // 0x800CDE40: jalr        $v0
    // 0x800CDE44: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_15;
    // 0x800CDE44: nop

    after_15:
    // 0x800CDE48: b           L_800CDE50
    // 0x800CDE4C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_800CDE50;
    // 0x800CDE4C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_800CDE50:
    // 0x800CDE50: blez        $s7, L_800CDF3C
    if (SIGNED(ctx->r23) <= 0) {
        // 0x800CDE54: lw          $s1, 0xCC($sp)
        ctx->r17 = MEM_W(ctx->r29, 0XCC);
            goto L_800CDF3C;
    }
    // 0x800CDE54: lw          $s1, 0xCC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XCC);
    // 0x800CDE58: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
L_800CDE5C:
    // 0x800CDE5C: beq         $s2, $zero, L_800CDED4
    if (ctx->r18 == 0) {
        // 0x800CDE60: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800CDED4;
    }
    // 0x800CDE60: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800CDE64: lw          $v0, 0xC($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XC);
    // 0x800CDE68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CDE6C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x800CDE70: beq         $v0, $zero, L_800CDED4
    if (ctx->r2 == 0) {
        // 0x800CDE74: nop
    
            goto L_800CDED4;
    }
    // 0x800CDE74: nop

    // 0x800CDE78: lw          $t1, 0x18($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X18);
    // 0x800CDE7C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800CDE80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800CDE84: sll         $t2, $t1, 27
    ctx->r10 = S32(ctx->r9 << 27);
    // 0x800CDE88: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x800CDE8C: jalr        $v0
    // 0x800CDE90: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_16;
    // 0x800CDE90: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_16:
    // 0x800CDE94: beq         $v0, $zero, L_800CDF2C
    if (ctx->r2 == 0) {
        // 0x800CDE98: sll         $t5, $v0, 1
        ctx->r13 = S32(ctx->r2 << 1);
            goto L_800CDF2C;
    }
    // 0x800CDE98: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x800CDE9C: lbu         $t6, 0x19($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X19);
    // 0x800CDEA0: andi        $t7, $t5, 0x1E
    ctx->r15 = ctx->r13 & 0X1E;
    // 0x800CDEA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CDEA8: andi        $t8, $t6, 0xFFE1
    ctx->r24 = ctx->r14 & 0XFFE1;
    // 0x800CDEAC: or          $t0, $t7, $t8
    ctx->r8 = ctx->r15 | ctx->r24;
    // 0x800CDEB0: sb          $t0, 0x19($s3)
    MEM_B(0X19, ctx->r19) = ctx->r8;
    // 0x800CDEB4: addu        $at, $at, $fp
    ctx->r1 = ADD32(ctx->r1, ctx->r30);
    // 0x800CDEB8: sb          $s4, -0x5010($at)
    MEM_B(-0X5010, ctx->r1) = ctx->r20;
    // 0x800CDEBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800CDEC0: sll         $t9, $fp, 2
    ctx->r25 = S32(ctx->r30 << 2);
    // 0x800CDEC4: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800CDEC8: sw          $s3, -0x5090($at)
    MEM_W(-0X5090, ctx->r1) = ctx->r19;
    // 0x800CDECC: b           L_800CDF3C
    // 0x800CDED0: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
        goto L_800CDF3C;
    // 0x800CDED0: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
L_800CDED4:
    // 0x800CDED4: jal         0x800EC75C
    // 0x800CDED8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EC75C(rdram, ctx);
        goto after_17;
    // 0x800CDED8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_17:
    // 0x800CDEDC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800CDEE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CDEE4: jal         0x800EEB40
    // 0x800CDEE8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_800EEB40(rdram, ctx);
        goto after_18;
    // 0x800CDEE8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_18:
    // 0x800CDEEC: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800CDEF0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800CDEF4: addiu       $v0, $v0, -0x5090
    ctx->r2 = ADD32(ctx->r2, -0X5090);
    // 0x800CDEF8: add.s       $f2, $f8, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800CDEFC: sll         $t2, $fp, 2
    ctx->r10 = S32(ctx->r30 << 2);
    // 0x800CDF00: addu        $t1, $v0, $fp
    ctx->r9 = ADD32(ctx->r2, ctx->r30);
    // 0x800CDF04: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x800CDF08: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800CDF0C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800CDF10: nop

    // 0x800CDF14: bc1fl       L_800CDF30
    if (!c1cs) {
        // 0x800CDF18: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800CDF30;
    }
    goto skip_13;
    // 0x800CDF18: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_13:
    // 0x800CDF1C: sb          $s4, 0x80($t1)
    MEM_B(0X80, ctx->r9) = ctx->r20;
    // 0x800CDF20: sw          $s3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r19;
    // 0x800CDF24: b           L_800CDF3C
    // 0x800CDF28: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
        goto L_800CDF3C;
    // 0x800CDF28: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
L_800CDF2C:
    // 0x800CDF2C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800CDF30:
    // 0x800CDF30: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800CDF34: bne         $s4, $s7, L_800CDE5C
    if (ctx->r20 != ctx->r23) {
        // 0x800CDF38: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800CDE5C;
    }
    // 0x800CDF38: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800CDF3C:
    // 0x800CDF3C: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
L_800CDF40:
    // 0x800CDF40: lw          $t6, 0x84($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X84);
    // 0x800CDF44: addiu       $t5, $t4, 0xC
    ctx->r13 = ADD32(ctx->r12, 0XC);
    // 0x800CDF48: sltu        $at, $t5, $t6
    ctx->r1 = ctx->r13 < ctx->r14 ? 1 : 0;
    // 0x800CDF4C: bne         $at, $zero, L_800CDD40
    if (ctx->r1 != 0) {
        // 0x800CDF50: sw          $t5, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r13;
            goto L_800CDD40;
    }
    // 0x800CDF50: sw          $t5, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r13;
    // 0x800CDF54: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
L_800CDF58:
    // 0x800CDF58: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800CDF5C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800CDF60: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
    // 0x800CDF64: bne         $a0, $zero, L_800CDD14
    if (ctx->r4 != 0) {
        // 0x800CDF68: nop
    
            goto L_800CDD14;
    }
    // 0x800CDF68: nop

L_800CDF6C:
    // 0x800CDF6C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800CDF70: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x800CDF74: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800CDF78: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800CDF7C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800CDF80: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800CDF84: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800CDF88: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800CDF8C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800CDF90: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800CDF94: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800CDF98: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800CDF9C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800CDFA0: jr          $ra
    // 0x800CDFA4: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x800CDFA4: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_800C2AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2AB8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C2ABC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C2AC0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C2AC4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C2AC8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C2ACC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C2AD0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C2AD4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C2AD8: jal         0x800C2B80
    // 0x800C2ADC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800C2B80(rdram, ctx);
        goto after_0;
    // 0x800C2ADC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C2AE0: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800C2AE4: addiu       $s6, $s6, -0x73F0
    ctx->r22 = ADD32(ctx->r22, -0X73F0);
    // 0x800C2AE8: addiu       $s5, $zero, 0x3C
    ctx->r21 = ADD32(0, 0X3C);
    // 0x800C2AEC: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800C2AF0: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
L_800C2AF4:
    // 0x800C2AF4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800C2AF8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800C2AFC:
    // 0x800C2AFC: lbu         $t6, 0x78($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X78);
    // 0x800C2B00: beql        $t6, $zero, L_800C2B48
    if (ctx->r14 == 0) {
        // 0x800C2B04: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800C2B48;
    }
    goto skip_0;
    // 0x800C2B04: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800C2B08: lw          $t7, 0x78($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X78);
    // 0x800C2B0C: andi        $s0, $s2, 0xFF
    ctx->r16 = ctx->r18 & 0XFF;
    // 0x800C2B10: sll         $t8, $t7, 19
    ctx->r24 = S32(ctx->r15 << 19);
    // 0x800C2B14: srl         $t9, $t8, 29
    ctx->r25 = S32(U32(ctx->r24) >> 29);
    // 0x800C2B18: bnel        $s4, $t9, L_800C2B48
    if (ctx->r20 != ctx->r25) {
        // 0x800C2B1C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800C2B48;
    }
    goto skip_1;
    // 0x800C2B1C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x800C2B20: jal         0x800C269C
    // 0x800C2B24: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C269C(rdram, ctx);
        goto after_1;
    // 0x800C2B24: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_1:
    // 0x800C2B28: beql        $v0, $zero, L_800C2B44
    if (ctx->r2 == 0) {
        // 0x800C2B2C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800C2B44;
    }
    goto skip_2;
    // 0x800C2B2C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_2:
    // 0x800C2B30: jal         0x800C16A4
    // 0x800C2B34: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C16A4(rdram, ctx);
        goto after_2;
    // 0x800C2B34: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_2:
    // 0x800C2B38: b           L_800C2B48
    // 0x800C2B3C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_800C2B48;
    // 0x800C2B3C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800C2B40: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800C2B44:
    // 0x800C2B44: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800C2B48:
    // 0x800C2B48: bne         $s2, $s5, L_800C2AFC
    if (ctx->r18 != ctx->r21) {
        // 0x800C2B4C: addiu       $s1, $s1, 0x80
        ctx->r17 = ADD32(ctx->r17, 0X80);
            goto L_800C2AFC;
    }
    // 0x800C2B4C: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    if (ctx->r19 != 0) tooie_sound_slot_wait(rdram, ctx);
    // 0x800C2B50: bnel        $s3, $zero, L_800C2AF4
    if (ctx->r19 != 0) {
        // 0x800C2B54: or          $s1, $s6, $zero
        ctx->r17 = ctx->r22 | 0;
            goto L_800C2AF4;
    }
    goto skip_3;
    // 0x800C2B54: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    skip_3:
    // 0x800C2B58: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C2B5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C2B60: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C2B64: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C2B68: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C2B6C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C2B70: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C2B74: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C2B78: jr          $ra
    // 0x800C2B7C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C2B7C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800AA7FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA7FC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800AA800: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800AA804: lh          $t6, 0x12($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X12);
    // 0x800AA808: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AA80C: addiu       $t1, $t1, 0x77A0
    ctx->r9 = ADD32(ctx->r9, 0X77A0);
    // 0x800AA810: bnel        $t6, $zero, L_800AA844
    if (ctx->r14 != 0) {
        // 0x800AA814: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800AA844;
    }
    goto skip_0;
    // 0x800AA814: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    skip_0:
    // 0x800AA818: sw          $t1, 0x190($t1)
    MEM_W(0X190, ctx->r9) = ctx->r9;
    // 0x800AA81C: addiu       $t7, $a0, 0x18
    ctx->r15 = ADD32(ctx->r4, 0X18);
    // 0x800AA820: addiu       $t5, $t1, 0x4
    ctx->r13 = ADD32(ctx->r9, 0X4);
    // 0x800AA824: sw          $t5, 0x190($t1)
    MEM_W(0X190, ctx->r9) = ctx->r13;
    // 0x800AA828: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800AA82C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x800AA830: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800AA834: lw          $t6, 0x190($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X190);
    // 0x800AA838: b           L_800AAAD8
    // 0x800AA83C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
        goto L_800AAAD8;
    // 0x800AA83C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800AA840: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800AA844:
    // 0x800AA844: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x800AA848: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800AA84C: addiu       $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x800AA850: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x800AA854: addiu       $t4, $sp, 0x44
    ctx->r12 = ADD32(ctx->r29, 0X44);
L_800AA858:
    // 0x800AA858: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AA85C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AA860: lh          $v0, 0x12($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X12);
    // 0x800AA864: bltz        $a1, L_800AA8A4
    if (SIGNED(ctx->r5) < 0) {
        // 0x800AA868: nop
    
            goto L_800AA8A4;
    }
    // 0x800AA868: nop

    // 0x800AA86C: div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // 0x800AA870: mflo        $t8
    ctx->r24 = lo;
    // 0x800AA874: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800AA878: bne         $v0, $zero, L_800AA884
    if (ctx->r2 != 0) {
        // 0x800AA87C: nop
    
            goto L_800AA884;
    }
    // 0x800AA87C: nop

    // 0x800AA880: break       7
    do_break(2148182144);
L_800AA884:
    // 0x800AA884: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA888: bne         $v0, $at, L_800AA89C
    if (ctx->r2 != ctx->r1) {
        // 0x800AA88C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AA89C;
    }
    // 0x800AA88C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA890: bne         $a1, $at, L_800AA89C
    if (ctx->r5 != ctx->r1) {
        // 0x800AA894: nop
    
            goto L_800AA89C;
    }
    // 0x800AA894: nop

    // 0x800AA898: break       6
    do_break(2148182168);
L_800AA89C:
    // 0x800AA89C: b           L_800AA8DC
    // 0x800AA8A0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
        goto L_800AA8DC;
    // 0x800AA8A0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
L_800AA8A4:
    // 0x800AA8A4: div         $zero, $a1, $v0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r2)));
    // 0x800AA8A8: mflo        $t9
    ctx->r25 = lo;
    // 0x800AA8AC: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x800AA8B0: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800AA8B4: bne         $v0, $zero, L_800AA8C0
    if (ctx->r2 != 0) {
        // 0x800AA8B8: nop
    
            goto L_800AA8C0;
    }
    // 0x800AA8B8: nop

    // 0x800AA8BC: break       7
    do_break(2148182204);
L_800AA8C0:
    // 0x800AA8C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA8C4: bne         $v0, $at, L_800AA8D8
    if (ctx->r2 != ctx->r1) {
        // 0x800AA8C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AA8D8;
    }
    // 0x800AA8C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA8CC: bne         $a1, $at, L_800AA8D8
    if (ctx->r5 != ctx->r1) {
        // 0x800AA8D0: nop
    
            goto L_800AA8D8;
    }
    // 0x800AA8D0: nop

    // 0x800AA8D4: break       6
    do_break(2148182228);
L_800AA8D8:
    // 0x800AA8D8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
L_800AA8DC:
    // 0x800AA8DC: bltzl       $v0, L_800AA924
    if (SIGNED(ctx->r2) < 0) {
        // 0x800AA8E0: lh          $t8, 0x12($a0)
        ctx->r24 = MEM_H(ctx->r4, 0X12);
            goto L_800AA924;
    }
    goto skip_1;
    // 0x800AA8E0: lh          $t8, 0x12($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X12);
    skip_1:
    // 0x800AA8E4: lh          $t6, 0x12($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X12);
    // 0x800AA8E8: div         $zero, $v0, $t6
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r14)));
    // 0x800AA8EC: mflo        $t7
    ctx->r15 = lo;
    // 0x800AA8F0: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800AA8F4: bne         $t6, $zero, L_800AA900
    if (ctx->r14 != 0) {
        // 0x800AA8F8: nop
    
            goto L_800AA900;
    }
    // 0x800AA8F8: nop

    // 0x800AA8FC: break       7
    do_break(2148182268);
L_800AA900:
    // 0x800AA900: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA904: bne         $t6, $at, L_800AA918
    if (ctx->r14 != ctx->r1) {
        // 0x800AA908: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AA918;
    }
    // 0x800AA908: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA90C: bne         $v0, $at, L_800AA918
    if (ctx->r2 != ctx->r1) {
        // 0x800AA910: nop
    
            goto L_800AA918;
    }
    // 0x800AA910: nop

    // 0x800AA914: break       6
    do_break(2148182292);
L_800AA918:
    // 0x800AA918: b           L_800AA95C
    // 0x800AA91C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
        goto L_800AA95C;
    // 0x800AA91C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800AA920: lh          $t8, 0x12($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X12);
L_800AA924:
    // 0x800AA924: div         $zero, $v0, $t8
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r24)));
    // 0x800AA928: mflo        $t9
    ctx->r25 = lo;
    // 0x800AA92C: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x800AA930: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800AA934: bne         $t8, $zero, L_800AA940
    if (ctx->r24 != 0) {
        // 0x800AA938: nop
    
            goto L_800AA940;
    }
    // 0x800AA938: nop

    // 0x800AA93C: break       7
    do_break(2148182332);
L_800AA940:
    // 0x800AA940: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800AA944: bne         $t8, $at, L_800AA958
    if (ctx->r24 != ctx->r1) {
        // 0x800AA948: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800AA958;
    }
    // 0x800AA948: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800AA94C: bne         $v0, $at, L_800AA958
    if (ctx->r2 != ctx->r1) {
        // 0x800AA950: nop
    
            goto L_800AA958;
    }
    // 0x800AA950: nop

    // 0x800AA954: break       6
    do_break(2148182356);
L_800AA958:
    // 0x800AA958: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_800AA95C:
    // 0x800AA95C: lh          $a1, 0x0($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X0);
    // 0x800AA960: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AA964: beql        $at, $zero, L_800AA978
    if (ctx->r1 == 0) {
        // 0x800AA968: lh          $a1, 0x6($t2)
        ctx->r5 = MEM_H(ctx->r10, 0X6);
            goto L_800AA978;
    }
    goto skip_2;
    // 0x800AA968: lh          $a1, 0x6($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X6);
    skip_2:
    // 0x800AA96C: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x800AA970: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800AA974: lh          $a1, 0x6($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X6);
L_800AA978:
    // 0x800AA978: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800AA97C: beql        $at, $zero, L_800AA990
    if (ctx->r1 == 0) {
        // 0x800AA980: lw          $t3, 0x0($t1)
        ctx->r11 = MEM_W(ctx->r9, 0X0);
            goto L_800AA990;
    }
    goto skip_3;
    // 0x800AA980: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    skip_3:
    // 0x800AA984: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x800AA988: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800AA98C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
L_800AA990:
    // 0x800AA990: lh          $a1, 0x0($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X0);
    // 0x800AA994: slt         $at, $t3, $a1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AA998: beql        $at, $zero, L_800AA9AC
    if (ctx->r1 == 0) {
        // 0x800AA99C: lh          $a1, 0x6($t2)
        ctx->r5 = MEM_H(ctx->r10, 0X6);
            goto L_800AA9AC;
    }
    goto skip_4;
    // 0x800AA99C: lh          $a1, 0x6($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X6);
    skip_4:
    // 0x800AA9A0: sw          $a1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r5;
    // 0x800AA9A4: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x800AA9A8: lh          $a1, 0x6($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X6);
L_800AA9AC:
    // 0x800AA9AC: slt         $at, $a1, $t3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800AA9B0: beql        $at, $zero, L_800AA9C4
    if (ctx->r1 == 0) {
        // 0x800AA9B4: lh          $t6, 0x0($t2)
        ctx->r14 = MEM_H(ctx->r10, 0X0);
            goto L_800AA9C4;
    }
    goto skip_5;
    // 0x800AA9B4: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    skip_5:
    // 0x800AA9B8: sw          $a1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r5;
    // 0x800AA9BC: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x800AA9C0: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
L_800AA9C4:
    // 0x800AA9C4: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800AA9C8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800AA9CC: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x800AA9D0: sw          $t7, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r15;
    // 0x800AA9D4: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x800AA9D8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800AA9DC: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x800AA9E0: subu        $t9, $t3, $t8
    ctx->r25 = SUB32(ctx->r11, ctx->r24);
    // 0x800AA9E4: bne         $t1, $t4, L_800AA858
    if (ctx->r9 != ctx->r12) {
        // 0x800AA9E8: sw          $t9, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r25;
            goto L_800AA858;
    }
    // 0x800AA9E8: sw          $t9, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r25;
    // 0x800AA9EC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800AA9F0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800AA9F4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AA9F8: addiu       $t1, $t1, 0x77A0
    ctx->r9 = ADD32(ctx->r9, 0X77A0);
    // 0x800AA9FC: slt         $at, $t5, $v1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AAA00: bne         $at, $zero, L_800AAAC8
    if (ctx->r1 != 0) {
        // 0x800AAA04: sw          $t1, 0x190($t1)
        MEM_W(0X190, ctx->r9) = ctx->r9;
            goto L_800AAAC8;
    }
    // 0x800AAA04: sw          $t1, 0x190($t1)
    MEM_W(0X190, ctx->r9) = ctx->r9;
    // 0x800AAA08: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800AAA0C: addiu       $t2, $t2, 0x7930
    ctx->r10 = ADD32(ctx->r10, 0X7930);
    // 0x800AAA10: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800AAA14: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
L_800AAA18:
    // 0x800AAA18: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800AAA1C: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AAA20: bnel        $at, $zero, L_800AAAB8
    if (ctx->r1 != 0) {
        // 0x800AAA24: lw          $t6, 0x40($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X40);
            goto L_800AAAB8;
    }
    goto skip_6;
    // 0x800AAA24: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    skip_6:
    // 0x800AAA28: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
L_800AAA2C:
    // 0x800AAA2C: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AAA30: bnel        $at, $zero, L_800AAAA4
    if (ctx->r1 != 0) {
        // 0x800AAA34: lw          $t5, 0x3C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X3C);
            goto L_800AAAA4;
    }
    goto skip_7;
    // 0x800AAA34: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    skip_7:
    // 0x800AAA38: lw          $v0, 0x190($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X190);
L_800AAA3C:
    // 0x800AAA3C: sltu        $at, $v0, $t2
    ctx->r1 = ctx->r2 < ctx->r10 ? 1 : 0;
    // 0x800AAA40: beql        $at, $zero, L_800AAA94
    if (ctx->r1 == 0) {
        // 0x800AAA44: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800AAA94;
    }
    goto skip_8;
    // 0x800AAA44: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_8:
    // 0x800AAA48: lhu         $t7, 0xE($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XE);
    // 0x800AAA4C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800AAA50: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AAA54: mflo        $t8
    ctx->r24 = lo;
    // 0x800AAA58: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800AAA5C: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x800AAA60: addu        $t5, $t9, $a0
    ctx->r13 = ADD32(ctx->r25, ctx->r4);
    // 0x800AAA64: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AAA68: multu       $a1, $t8
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AAA6C: mflo        $t9
    ctx->r25 = lo;
    // 0x800AAA70: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800AAA74: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x800AAA78: addiu       $t8, $t6, 0x18
    ctx->r24 = ADD32(ctx->r14, 0X18);
    // 0x800AAA7C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AAA80: lw          $t9, 0x190($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X190);
    // 0x800AAA84: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800AAA88: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x800AAA8C: sw          $t7, 0x190($t1)
    MEM_W(0X190, ctx->r9) = ctx->r15;
    // 0x800AAA90: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800AAA94:
    // 0x800AAA94: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800AAA98: beql        $at, $zero, L_800AAA3C
    if (ctx->r1 == 0) {
        // 0x800AAA9C: lw          $v0, 0x190($t1)
        ctx->r2 = MEM_W(ctx->r9, 0X190);
            goto L_800AAA3C;
    }
    goto skip_9;
    // 0x800AAA9C: lw          $v0, 0x190($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X190);
    skip_9:
    // 0x800AAAA0: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
L_800AAAA4:
    // 0x800AAAA4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800AAAA8: slt         $at, $t5, $a1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AAAAC: beql        $at, $zero, L_800AAA2C
    if (ctx->r1 == 0) {
        // 0x800AAAB0: lw          $a2, 0x44($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X44);
            goto L_800AAA2C;
    }
    goto skip_10;
    // 0x800AAAB0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    skip_10:
    // 0x800AAAB4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
L_800AAAB8:
    // 0x800AAAB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800AAABC: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AAAC0: beql        $at, $zero, L_800AAA18
    if (ctx->r1 == 0) {
        // 0x800AAAC4: lw          $a1, 0x48($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X48);
            goto L_800AAA18;
    }
    goto skip_11;
    // 0x800AAAC4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    skip_11:
L_800AAAC8:
    // 0x800AAAC8: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x800AAACC: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x800AAAD0: lw          $t8, 0x190($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X190);
    // 0x800AAAD4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_800AAAD8:
    // 0x800AAAD8: jr          $ra
    // 0x800AAADC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800AAADC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void chevilmumbo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803CF4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1676, 0X458C) << 16);
    // 0x80803CF8: jr          $ra
    // 0x80803CFC: addiu       $v0, $v0, 0x458C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1676, 0X458C));
    return;
    // 0x80803CFC: addiu       $v0, $v0, 0x458C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1676, 0X458C));
;}
RECOMP_FUNC void func_80800C84_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800C90: jal         0x800DA298
    // 0x80800C94: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800C94: addiu       $a0, $zero, 0x514
    ctx->r4 = ADD32(0, 0X514);
    after_0:
    // 0x80800C98: beq         $v0, $zero, L_80800CB0
    if (ctx->r2 == 0) {
        // 0x80800C9C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800CB0;
    }
    // 0x80800C9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800CA0: jal         0x80102424
    // 0x80800CA4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x80800CA4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x80800CA8: b           L_80800CB4
    // 0x80800CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CB4;
    // 0x80800CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CB0:
    // 0x80800CB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800CB4:
    // 0x80800CB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800CBC: jr          $ra
    // 0x80800CC0: nop

    return;
    // 0x80800CC0: nop

;}
RECOMP_FUNC void func_80800C6C_chhumba(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800C74: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800C78: jal         0x80800BA8
    // 0x80800C7C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80800BA8_chhumba(rdram, ctx);
        goto after_0;
    // 0x80800C7C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80800C80: jal         0x8008F8B0
    // 0x80800C84: nop

    func_8008F8B0(rdram, ctx);
        goto after_1;
    // 0x80800C84: nop

    after_1:
    // 0x80800C88: jal         0x8008F8D8
    // 0x80800C8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F8D8(rdram, ctx);
        goto after_2;
    // 0x80800C8C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80800C90: jal         0x8008F938
    // 0x80800C94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8008F938(rdram, ctx);
        goto after_3;
    // 0x80800C94: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800C98: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800C9C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80800CA0: addiu       $a0, $a0, -0x2A24
    ctx->r4 = ADD32(ctx->r4, -0X2A24);
    // 0x80800CA4: jal         0x8008F904
    // 0x80800CA8: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    func_8008F904(rdram, ctx);
        goto after_4;
    // 0x80800CA8: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_4:
    // 0x80800CAC: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800CB0: jal         0x8008F990
    // 0x80800CB4: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    func_8008F990(rdram, ctx);
        goto after_5;
    // 0x80800CB4: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    after_5:
    // 0x80800CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CC0: jr          $ra
    // 0x80800CC4: nop

    return;
    // 0x80800CC4: nop

;}
RECOMP_FUNC void vplight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80800010: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x80800014: lhu         $t6, 0x10($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X10);
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80800020: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80800024: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    // 0x80800028: jal         0x8001ACCC
    // 0x8080002C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    heap_alloc(rdram, ctx);
        goto after_0;
    // 0x8080002C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800030: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800034: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080003C: jal         0x8001BCF8
    // 0x80800040: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    rare_memset(rdram, ctx);
        goto after_1;
    // 0x80800040: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800044: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x80800048: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8080004C: lhu         $t5, 0x10($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X10);
    // 0x80800050: sll         $t4, $t0, 4
    ctx->r12 = S32(ctx->r8 << 4);
    // 0x80800054: addu        $t2, $t3, $t4
    ctx->r10 = ADD32(ctx->r11, ctx->r12);
    // 0x80800058: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8080005C: addu        $a0, $t6, $t2
    ctx->r4 = ADD32(ctx->r14, ctx->r10);
    // 0x80800060: sltu        $at, $t2, $a0
    ctx->r1 = ctx->r10 < ctx->r4 ? 1 : 0;
    // 0x80800064: beq         $at, $zero, L_80800084
    if (ctx->r1 == 0) {
        // 0x80800068: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_80800084;
    }
    // 0x80800068: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8080006C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80800070:
    // 0x80800070: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80800074: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80800078: bne         $at, $zero, L_80800070
    if (ctx->r1 != 0) {
        // 0x8080007C: sh          $v1, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r3;
            goto L_80800070;
    }
    // 0x8080007C: sh          $v1, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r3;
    // 0x80800080: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
L_80800084:
    // 0x80800084: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80800088: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8080008C: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x80800090: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    // 0x80800094: addiu       $a2, $a2, 0x14
    ctx->r6 = ADD32(ctx->r6, 0X14);
    // 0x80800098: addiu       $a1, $v0, 0x14
    ctx->r5 = ADD32(ctx->r2, 0X14);
    // 0x8080009C: sltu        $at, $a1, $a2
    ctx->r1 = ctx->r5 < ctx->r6 ? 1 : 0;
    // 0x808000A0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x808000A4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x808000A8: beq         $at, $zero, L_80800100
    if (ctx->r1 == 0) {
        // 0x808000AC: addu        $a3, $s0, $t7
        ctx->r7 = ADD32(ctx->r16, ctx->r15);
            goto L_80800100;
    }
    // 0x808000AC: addu        $a3, $s0, $t7
    ctx->r7 = ADD32(ctx->r16, ctx->r15);
    // 0x808000B0: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x808000B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_808000B8:
    // 0x808000B8: lhu         $t9, 0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2);
    // 0x808000BC: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x808000C0: sra         $t4, $v0, 2
    ctx->r12 = S32(SIGNED(ctx->r2) >> 2);
    // 0x808000C4: beql        $t9, $zero, L_808000F4
    if (ctx->r25 == 0) {
        // 0x808000C8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_808000F4;
    }
    goto skip_0;
    // 0x808000C8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x808000CC: multu       $t4, $t1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808000D0: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x808000D4: sb          $zero, 0x1($a0)
    MEM_B(0X1, ctx->r4) = 0;
    // 0x808000D8: mflo        $t5
    ctx->r13 = lo;
    // 0x808000DC: addu        $t6, $t5, $a3
    ctx->r14 = ADD32(ctx->r13, ctx->r7);
    // 0x808000E0: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x808000E4: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x808000E8: addu        $t9, $t2, $t7
    ctx->r25 = ADD32(ctx->r10, ctx->r15);
    // 0x808000EC: sh          $t4, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r12;
    // 0x808000F0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_808000F4:
    // 0x808000F4: sltu        $at, $v1, $a2
    ctx->r1 = ctx->r3 < ctx->r6 ? 1 : 0;
    // 0x808000F8: bne         $at, $zero, L_808000B8
    if (ctx->r1 != 0) {
        // 0x808000FC: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_808000B8;
    }
    // 0x808000FC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
L_80800100:
    // 0x80800100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800104: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800108: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8080010C: jr          $ra
    // 0x80800110: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    return;
    // 0x80800110: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
;}
RECOMP_FUNC void func_808010A0_chpotogoldgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808010A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010A8: jal         0x8080206C
    // 0x808010AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8080206C_chpotogoldgame(rdram, ctx);
        goto after_0;
    // 0x808010AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808010B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808010B4: jal         0x800D211C
    // 0x808010B8: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    func_800D211C(rdram, ctx);
        goto after_1;
    // 0x808010B8: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_1:
    // 0x808010BC: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x808010C0: bne         $v0, $v1, L_808010E4
    if (ctx->r2 != ctx->r3) {
        // 0x808010C4: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_808010E4;
    }
    // 0x808010C4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808010C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808010CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808010D0: addiu       $a1, $zero, 0x89
    ctx->r5 = ADD32(0, 0X89);
    // 0x808010D4: jal         0x800D2054
    // 0x808010D8: lw          $a2, 0x20($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X20);
    func_800D2054(rdram, ctx);
        goto after_2;
    // 0x808010D8: lw          $a2, 0x20($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X20);
    after_2:
    // 0x808010DC: b           L_80801110
    // 0x808010E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801110;
    // 0x808010E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808010E4:
    // 0x808010E4: bne         $t7, $v1, L_808010FC
    if (ctx->r15 != ctx->r3) {
        // 0x808010E8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_808010FC;
    }
    // 0x808010E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808010EC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x808010F0: addiu       $a1, $zero, 0x89
    ctx->r5 = ADD32(0, 0X89);
    // 0x808010F4: jal         0x800D2054
    // 0x808010F8: lw          $a2, 0x20($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X20);
    func_800D2054(rdram, ctx);
        goto after_3;
    // 0x808010F8: lw          $a2, 0x20($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X20);
    after_3:
L_808010FC:
    // 0x808010FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801100: addiu       $a1, $zero, 0x84
    ctx->r5 = ADD32(0, 0X84);
    // 0x80801104: jal         0x800D2054
    // 0x80801108: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_800D2054(rdram, ctx);
        goto after_4;
    // 0x80801108: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_4:
    // 0x8080110C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801110:
    // 0x80801110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801114: jr          $ra
    // 0x80801118: nop

    return;
    // 0x80801118: nop

;}
RECOMP_FUNC void func_808025D4_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808025D8: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x808025DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808025E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808025E4: beq         $a1, $at, L_8080261C
    if (ctx->r5 == ctx->r1) {
        // 0x808025E8: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8080261C;
    }
    // 0x808025E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808025EC: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x808025F0: beq         $a1, $at, L_80802648
    if (ctx->r5 == ctx->r1) {
        // 0x808025F4: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_80802648;
    }
    // 0x808025F4: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x808025F8: beq         $a1, $at, L_808026C8
    if (ctx->r5 == ctx->r1) {
        // 0x808025FC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_808026C8;
    }
    // 0x808025FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802600: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80802604: beq         $a1, $at, L_808026E4
    if (ctx->r5 == ctx->r1) {
        // 0x80802608: addiu       $at, $zero, 0x9C
        ctx->r1 = ADD32(0, 0X9C);
            goto L_808026E4;
    }
    // 0x80802608: addiu       $at, $zero, 0x9C
    ctx->r1 = ADD32(0, 0X9C);
    // 0x8080260C: beq         $a1, $at, L_80802634
    if (ctx->r5 == ctx->r1) {
        // 0x80802610: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80802634;
    }
    // 0x80802610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802614: b           L_808026E8
    // 0x80802618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808026E8;
    // 0x80802618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080261C:
    // 0x8080261C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802620: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80802624: jal         0x808006F8
    // 0x80802628: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_808006F8_chdiggerboss(rdram, ctx);
        goto after_0;
    // 0x80802628: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080262C: b           L_808026E8
    // 0x80802630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808026E8;
    // 0x80802630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802634:
    // 0x80802634: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80802638: jal         0x808007E0
    // 0x8080263C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_808007E0_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x8080263C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x80802640: b           L_808026E8
    // 0x80802644: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808026E8;
    // 0x80802644: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802648:
    // 0x80802648: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080264C: beq         $a2, $at, L_80802674
    if (ctx->r6 == ctx->r1) {
        // 0x80802650: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80802674;
    }
    // 0x80802650: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802654: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80802658: beq         $a2, $at, L_80802688
    if (ctx->r6 == ctx->r1) {
        // 0x8080265C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80802688;
    }
    // 0x8080265C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802660: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80802664: beq         $a2, $at, L_8080269C
    if (ctx->r6 == ctx->r1) {
        // 0x80802668: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8080269C;
    }
    // 0x80802668: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080266C: b           L_808026E8
    // 0x80802670: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808026E8;
    // 0x80802670: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802674:
    // 0x80802674: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80802678: jal         0x8080815C
    // 0x8080267C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8080815C_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x8080267C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    // 0x80802680: b           L_808026E8
    // 0x80802684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808026E8;
    // 0x80802684: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80802688:
    // 0x80802688: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8080268C: jal         0x808089BC
    // 0x80802690: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_808089BC_chdiggerboss(rdram, ctx);
        goto after_3;
    // 0x80802690: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_3:
    // 0x80802694: b           L_808026E8
    // 0x80802698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808026E8;
    // 0x80802698: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080269C:
    // 0x8080269C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808026A0: jal         0x80100094
    // 0x808026A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x808026A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808026A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808026AC: addiu       $a0, $zero, 0x4FF
    ctx->r4 = ADD32(0, 0X4FF);
    // 0x808026B0: jal         0x801084B0
    // 0x808026B4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_801084B0(rdram, ctx);
        goto after_5;
    // 0x808026B4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_5:
    // 0x808026B8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808026BC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x808026C0: b           L_808026E4
    // 0x808026C4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
        goto L_808026E4;
    // 0x808026C4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_808026C8:
    // 0x808026C8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x808026CC: jal         0x808058B0
    // 0x808026D0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_808058B0_chdiggerboss(rdram, ctx);
        goto after_6;
    // 0x808026D0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_6:
    // 0x808026D4: b           L_808026E8
    // 0x808026D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808026E8;
    // 0x808026D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808026DC: b           L_808026E8
    // 0x808026E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808026E8;
    // 0x808026E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808026E4:
    // 0x808026E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808026E8:
    // 0x808026E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808026EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808026F0: jr          $ra
    // 0x808026F4: nop

    return;
    // 0x808026F4: nop

;}
RECOMP_FUNC void func_80800120_bssilowait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800120: jr          $ra
    // 0x80800124: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800124: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800B20_chfactorymagnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B20: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800B24: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B2C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80800B30: beq         $a1, $at, L_80800B9C
    if (ctx->r5 == ctx->r1) {
        // 0x80800B34: sw          $a2, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r6;
            goto L_80800B9C;
    }
    // 0x80800B34: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800B38: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80800B3C: beq         $a1, $at, L_80800B80
    if (ctx->r5 == ctx->r1) {
        // 0x80800B40: lh          $t6, 0x58($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X58);
            goto L_80800B80;
    }
    // 0x80800B40: lh          $t6, 0x58($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X58);
    // 0x80800B44: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800B48: beq         $a1, $at, L_80800BE4
    if (ctx->r5 == ctx->r1) {
        // 0x80800B4C: lw          $v0, 0x58($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X58);
            goto L_80800BE4;
    }
    // 0x80800B4C: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x80800B50: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x80800B54: beq         $a1, $at, L_80800B70
    if (ctx->r5 == ctx->r1) {
        // 0x80800B58: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80800B70;
    }
    // 0x80800B58: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800B5C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800B60: beq         $a1, $at, L_80800D4C
    if (ctx->r5 == ctx->r1) {
        // 0x80800B64: addiu       $a0, $zero, 0x3F6
        ctx->r4 = ADD32(0, 0X3F6);
            goto L_80800D4C;
    }
    // 0x80800B64: addiu       $a0, $zero, 0x3F6
    ctx->r4 = ADD32(0, 0X3F6);
    // 0x80800B68: b           L_80800E30
    // 0x80800B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E30;
    // 0x80800B6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B70:
    // 0x80800B70: jal         0x80800898
    // 0x80800B74: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_0;
    // 0x80800B74: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x80800B78: b           L_80800E30
    // 0x80800B7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E30;
    // 0x80800B7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800B80:
    // 0x80800B80: addiu       $at, $zero, 0x1337
    ctx->r1 = ADD32(0, 0X1337);
    // 0x80800B84: bne         $t6, $at, L_80800B94
    if (ctx->r14 != ctx->r1) {
        // 0x80800B88: nop
    
            goto L_80800B94;
    }
    // 0x80800B88: nop

    // 0x80800B8C: b           L_80800E30
    // 0x80800B90: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
        goto L_80800E30;
    // 0x80800B90: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
L_80800B94:
    // 0x80800B94: b           L_80800E30
    // 0x80800B98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800E30;
    // 0x80800B98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800B9C:
    // 0x80800B9C: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80800BA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800BA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800BA8: bne         $t7, $at, L_80800BDC
    if (ctx->r15 != ctx->r1) {
        // 0x80800BAC: lui         $a1, 0x42B4
        ctx->r5 = S32(0X42B4 << 16);
            goto L_80800BDC;
    }
    // 0x80800BAC: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x80800BB0: jal         0x800CE8D8
    // 0x80800BB4: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    func_800CE8D8(rdram, ctx);
        goto after_1;
    // 0x80800BB4: addiu       $a2, $zero, 0x5A
    ctx->r6 = ADD32(0, 0X5A);
    after_1:
    // 0x80800BB8: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80800BBC: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800BC0: addiu       $a1, $a1, 0x74C8
    ctx->r5 = ADD32(ctx->r5, 0X74C8);
    // 0x80800BC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800BC8: jal         0x800CE928
    // 0x80800BCC: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    func_800CE928(rdram, ctx);
        goto after_2;
    // 0x80800BCC: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    after_2:
    // 0x80800BD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800BD4: jal         0x800CE88C
    // 0x80800BD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_3;
    // 0x80800BD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
L_80800BDC:
    // 0x80800BDC: b           L_80800E30
    // 0x80800BE0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800E30;
    // 0x80800BE0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800BE4:
    // 0x80800BE4: beq         $v0, $zero, L_80800C00
    if (ctx->r2 == 0) {
        // 0x80800BE8: addiu       $a0, $zero, 0x3F6
        ctx->r4 = ADD32(0, 0X3F6);
            goto L_80800C00;
    }
    // 0x80800BE8: addiu       $a0, $zero, 0x3F6
    ctx->r4 = ADD32(0, 0X3F6);
    // 0x80800BEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800BF0: beql        $v0, $at, L_80800C68
    if (ctx->r2 == ctx->r1) {
        // 0x80800BF4: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80800C68;
    }
    goto skip_0;
    // 0x80800BF4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x80800BF8: b           L_80800E30
    // 0x80800BFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E30;
    // 0x80800BFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800C00:
    // 0x80800C00: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2284, 0X2910) << 16);
    // 0x80800C04: addiu       $a1, $a1, 0x2910
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2284, 0X2910));
    // 0x80800C08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800C0C: jal         0x80108528
    // 0x80800C10: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    func_80108528(rdram, ctx);
        goto after_4;
    // 0x80800C10: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_4:
    // 0x80800C14: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80800C18: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80800C1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C20: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80800C24: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800C28: sw          $t0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r8;
    // 0x80800C2C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80800C30: sw          $t1, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->r9;
    // 0x80800C34: jal         0x80801A9C
    // 0x80800C38: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80801A9C_chfactorymagnet(rdram, ctx);
        goto after_5;
    // 0x80800C38: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_5:
    // 0x80800C3C: addiu       $a0, $zero, 0x50F
    ctx->r4 = ADD32(0, 0X50F);
    // 0x80800C40: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800C44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800C48: jal         0x80108528
    // 0x80800C4C: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    func_80108528(rdram, ctx);
        goto after_6;
    // 0x80800C4C: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_6:
    // 0x80800C50: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x80800C54: lwc1        $f4, 0x38($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X38);
    // 0x80800C58: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x80800C5C: b           L_80800E30
    // 0x80800C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E30;
    // 0x80800C60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800C64: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_80800C68:
    // 0x80800C68: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C6C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800C70: jal         0x800DC178
    // 0x80800C74: nop

    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800C74: nop

    after_7:
    // 0x80800C78: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800C7C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800C80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800C84: jal         0x80801A9C
    // 0x80800C88: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_80801A9C_chfactorymagnet(rdram, ctx);
        goto after_8;
    // 0x80800C88: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_8:
    // 0x80800C8C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800C90: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800C94: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800C98: jal         0x800DC178
    // 0x80800C9C: nop

    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80800C9C: nop

    after_9:
    // 0x80800CA0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80800CA4: jal         0x80103EAC
    // 0x80800CA8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80103EAC(rdram, ctx);
        goto after_10;
    // 0x80800CA8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_10:
    // 0x80800CAC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800CB0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800CB4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CB8: jal         0x800EF214
    // 0x80800CBC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800EF214(rdram, ctx);
        goto after_11;
    // 0x80800CBC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x80800CC0: addiu       $a0, $zero, 0x52F
    ctx->r4 = ADD32(0, 0X52F);
    // 0x80800CC4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80800CC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800CCC: jal         0x80108528
    // 0x80800CD0: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    func_80108528(rdram, ctx);
        goto after_12;
    // 0x80800CD0: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    after_12:
    // 0x80800CD4: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80800CD8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80800CDC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800CE0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800CE4: lwc1        $f6, 0x38($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X38);
    // 0x80800CE8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800CEC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800CF0: jal         0x800DC178
    // 0x80800CF4: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
    func_800DC178(rdram, ctx);
        goto after_13;
    // 0x80800CF4: swc1        $f6, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f6.u32l;
    after_13:
    // 0x80800CF8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800CFC: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80800D00: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800D04: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800D08: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80800D0C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800D10: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800D14: jal         0x800DC178
    // 0x80800D18: swc1        $f10, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f10.u32l;
    func_800DC178(rdram, ctx);
        goto after_14;
    // 0x80800D18: swc1        $f10, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f10.u32l;
    after_14:
    // 0x80800D1C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800D20: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800D24: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80800D28: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x80800D2C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800D30: jal         0x800DC178
    // 0x80800D34: swc1        $f0, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_15;
    // 0x80800D34: swc1        $f0, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->f0.u32l;
    after_15:
    // 0x80800D38: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80800D3C: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x80800D40: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80800D44: b           L_80800E30
    // 0x80800D48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E30;
    // 0x80800D48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D4C:
    // 0x80800D4C: jal         0x80089C30
    // 0x80800D50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_16;
    // 0x80800D50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800D54: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80800D58: sb          $zero, 0x24($t7)
    MEM_B(0X24, ctx->r15) = 0;
    // 0x80800D5C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80800D60: sb          $zero, 0x54($t8)
    MEM_B(0X54, ctx->r24) = 0;
    // 0x80800D64: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800D68: jal         0x80801AE8
    // 0x80800D6C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80801AE8_chfactorymagnet(rdram, ctx);
        goto after_17;
    // 0x80800D6C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_17:
    // 0x80800D70: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D74: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800D78: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80800D7C: bnel        $v1, $zero, L_80800D9C
    if (ctx->r3 != 0) {
        // 0x80800D80: lw          $t0, 0x0($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X0);
            goto L_80800D9C;
    }
    goto skip_1;
    // 0x80800D80: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x80800D84: jal         0x80108B04
    // 0x80800D88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_18;
    // 0x80800D88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80800D8C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80800D90: b           L_80800DA0
    // 0x80800D94: sw          $zero, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = 0;
        goto L_80800DA0;
    // 0x80800D94: sw          $zero, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = 0;
    // 0x80800D98: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
L_80800D9C:
    // 0x80800D9C: sw          $t0, 0x3C($t1)
    MEM_W(0X3C, ctx->r9) = ctx->r8;
L_80800DA0:
    // 0x80800DA0: jal         0x800DA298
    // 0x80800DA4: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    func_800DA298(rdram, ctx);
        goto after_19;
    // 0x80800DA4: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    after_19:
    // 0x80800DA8: beq         $v0, $zero, L_80800DFC
    if (ctx->r2 == 0) {
        // 0x80800DAC: nop
    
            goto L_80800DFC;
    }
    // 0x80800DAC: nop

    // 0x80800DB0: jal         0x80800E40
    // 0x80800DB4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_80800E40_chfactorymagnet(rdram, ctx);
        goto after_20;
    // 0x80800DB4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_20:
    // 0x80800DB8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800DBC: jal         0x80089860
    // 0x80800DC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _sumumbofx_entrypoint_4(rdram, ctx);
        goto after_21;
    // 0x80800DC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
    // 0x80800DC4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800DC8: jal         0x80089858
    // 0x80800DCC: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    _sumumbofx_entrypoint_3(rdram, ctx);
        goto after_22;
    // 0x80800DCC: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_22:
    // 0x80800DD0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800DD4: jal         0x80800898
    // 0x80800DD8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_23;
    // 0x80800DD8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_23:
    // 0x80800DDC: jal         0x800DA298
    // 0x80800DE0: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    func_800DA298(rdram, ctx);
        goto after_24;
    // 0x80800DE0: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    after_24:
    // 0x80800DE4: beq         $v0, $zero, L_80800E28
    if (ctx->r2 == 0) {
        // 0x80800DE8: nop
    
            goto L_80800E28;
    }
    // 0x80800DE8: nop

    // 0x80800DEC: jal         0x800DA524
    // 0x80800DF0: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    func_800DA524(rdram, ctx);
        goto after_25;
    // 0x80800DF0: addiu       $a0, $zero, 0xA06
    ctx->r4 = ADD32(0, 0XA06);
    after_25:
    // 0x80800DF4: b           L_80800E30
    // 0x80800DF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E30;
    // 0x80800DF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800DFC:
    // 0x80800DFC: jal         0x800DA298
    // 0x80800E00: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    func_800DA298(rdram, ctx);
        goto after_26;
    // 0x80800E00: addiu       $a0, $zero, 0x1B8
    ctx->r4 = ADD32(0, 0X1B8);
    after_26:
    // 0x80800E04: beq         $v0, $zero, L_80800E20
    if (ctx->r2 == 0) {
        // 0x80800E08: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80800E20;
    }
    // 0x80800E08: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800E0C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80800E10: jal         0x80800898
    // 0x80800E14: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_27;
    // 0x80800E14: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_27:
    // 0x80800E18: b           L_80800E30
    // 0x80800E1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E30;
    // 0x80800E1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E20:
    // 0x80800E20: jal         0x80800898
    // 0x80800E24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800898_chfactorymagnet(rdram, ctx);
        goto after_28;
    // 0x80800E24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
L_80800E28:
    // 0x80800E28: b           L_80800E30
    // 0x80800E2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800E30;
    // 0x80800E2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E30:
    // 0x80800E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E34: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800E38: jr          $ra
    // 0x80800E3C: nop

    return;
    // 0x80800E3C: nop

;}
RECOMP_FUNC void subaddiejoy_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800258: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080025C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800260: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80800264: lw          $a0, 0x64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X64);
    // 0x80800268: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080026C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x80800270: jal         0x80015F28
    // 0x80800274: srl         $a0, $t7, 30
    ctx->r4 = S32(U32(ctx->r15) >> 30);
    func_80015F28(rdram, ctx);
        goto after_0;
    // 0x80800274: srl         $a0, $t7, 30
    ctx->r4 = S32(U32(ctx->r15) >> 30);
    after_0:
    // 0x80800278: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8080027C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800280: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80800284: bnel        $v0, $t9, L_80800298
    if (ctx->r2 != ctx->r25) {
        // 0x80800288: lw          $a0, 0x64($t0)
        ctx->r4 = MEM_W(ctx->r8, 0X64);
            goto L_80800298;
    }
    goto skip_0;
    // 0x80800288: lw          $a0, 0x64($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X64);
    skip_0:
    // 0x8080028C: b           L_808002D0
    // 0x80800290: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002D0;
    // 0x80800290: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800294: lw          $a0, 0x64($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X64);
L_80800298:
    // 0x80800298: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8080029C: sll         $t1, $a0, 3
    ctx->r9 = S32(ctx->r4 << 3);
    // 0x808002A0: jal         0x80015E80
    // 0x808002A4: srl         $a0, $t1, 30
    ctx->r4 = S32(U32(ctx->r9) >> 30);
    func_80015E80(rdram, ctx);
        goto after_1;
    // 0x808002A4: srl         $a0, $t1, 30
    ctx->r4 = S32(U32(ctx->r9) >> 30);
    after_1:
    // 0x808002A8: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x808002AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002B0: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x808002B4: beq         $v0, $t3, L_808002C4
    if (ctx->r2 == ctx->r11) {
        // 0x808002B8: nop
    
            goto L_808002C4;
    }
    // 0x808002B8: nop

    // 0x808002BC: bnel        $v0, $t4, L_808002D0
    if (ctx->r2 != ctx->r12) {
        // 0x808002C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808002D0;
    }
    goto skip_1;
    // 0x808002C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
L_808002C4:
    // 0x808002C4: b           L_808002D0
    // 0x808002C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808002D0;
    // 0x808002C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002D0:
    // 0x808002D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808002D8: jr          $ra
    // 0x808002DC: nop

    return;
    // 0x808002DC: nop

;}
RECOMP_FUNC void func_80803784_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803784: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080378C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80803790: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80803794: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80803798: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080379C: lw          $a3, 0x114($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X114);
    // 0x808037A0: beq         $a3, $zero, L_808037BC
    if (ctx->r7 == 0) {
        // 0x808037A4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808037BC;
    }
    // 0x808037A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808037A8: lw          $a2, 0x184($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X184);
    // 0x808037AC: jal         0x8010114C
    // 0x808037B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8010114C(rdram, ctx);
        goto after_0;
    // 0x808037B0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x808037B4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x808037B8: sw          $zero, 0x114($v0)
    MEM_W(0X114, ctx->r2) = 0;
L_808037BC:
    // 0x808037BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808037C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808037C4: jal         0x800A38F0
    // 0x808037C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800A38F0(rdram, ctx);
        goto after_1;
    // 0x808037C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x808037CC: jal         0x80807C8C
    // 0x808037D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80807C8C_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x808037D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808037D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808037D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808037DC: jr          $ra
    // 0x808037E0: nop

    return;
    // 0x808037E0: nop

;}
RECOMP_FUNC void func_80800634_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800634: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800638: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080063C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800640: jal         0x8009EF28
    // 0x80800644: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bastick_getX(rdram, ctx);
        goto after_0;
    // 0x80800644: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800648: jal         0x800D8FF8
    // 0x8080064C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x8080064C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80800650: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800654: jal         0x8009BB94
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB94(rdram, ctx);
        goto after_2;
    // 0x80800658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080065C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800660: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800664: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800668: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080066C: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    // 0x80800670: lui         $a3, 0x4134
    ctx->r7 = S32(0X4134 << 16);
    // 0x80800674: jal         0x800F10B4
    // 0x80800678: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_3;
    // 0x80800678: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8080067C: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80800680: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800684: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800688: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8080068C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800690: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800694: jal         0x800F10B4
    // 0x80800698: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800F10B4(rdram, ctx);
        goto after_4;
    // 0x80800698: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8080069C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808006A0: jal         0x8009C4CC
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baroll_setIdeal(rdram, ctx);
        goto after_5;
    // 0x808006A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808006A8: jal         0x8008E35C
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_6;
    // 0x808006AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808006B0: beq         $v0, $zero, L_808006EC
    if (ctx->r2 == 0) {
        // 0x808006B4: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_808006EC;
    }
    // 0x808006B4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x808006B8: jal         0x8009BB94
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB94(rdram, ctx);
        goto after_7;
    // 0x808006BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808006C0: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x808006C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006C8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808006CC: lui         $a3, 0x422A
    ctx->r7 = S32(0X422A << 16);
    // 0x808006D0: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x808006D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808006D8: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    // 0x808006DC: jal         0x800F10B4
    // 0x808006E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x808006E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x808006E4: b           L_808006F4
    // 0x808006E8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_808006F4;
    // 0x808006E8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_808006EC:
    // 0x808006EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x808006F0: nop

L_808006F4:
    // 0x808006F4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x808006F8: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x808006FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800700: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800704: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80800708: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8080070C: jal         0x800F10B4
    // 0x80800710: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800F10B4(rdram, ctx);
        goto after_9;
    // 0x80800710: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_9:
    // 0x80800714: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080071C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800720: jal         0x80084C90
    // 0x80800724: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    _bafpctrl_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80800724: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x80800728: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800730: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800734: jal         0x8009C990
    // 0x80800738: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    yaw_getIdeal(rdram, ctx);
        goto after_11;
    // 0x80800738: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x8080073C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800744: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80800748: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8080074C: jal         0x8009C914
    // 0x80800750: nop

    yaw_setIdeal(rdram, ctx);
        goto after_12;
    // 0x80800750: nop

    after_12:
    // 0x80800754: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800758: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080075C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800760: jr          $ra
    // 0x80800764: nop

    return;
    // 0x80800764: nop

;}
RECOMP_FUNC void _fxsparkle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800888C0: syscall     709
    recomp_syscall_handler(rdram, ctx, 0x800888C0);
    return;
    // 0x800888C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800BDC_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BDC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800BE0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800BE4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800BE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800BEC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800BF0: lw          $a1, 0x188($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X188);
    // 0x80800BF4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800BF8: jal         0x800EE7F8
    // 0x80800BFC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800BFC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    after_0:
    // 0x80800C00: jal         0x800A4C48
    // 0x80800C04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800A4C48(rdram, ctx);
        goto after_1;
    // 0x80800C04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80800C08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C0C: jal         0x800CA9D8
    // 0x80800C10: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800CA9D8(rdram, ctx);
        goto after_2;
    // 0x80800C10: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80800C14: jal         0x8009EF28
    // 0x80800C18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getX(rdram, ctx);
        goto after_3;
    // 0x80800C18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80800C1C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800C20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C24: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800C28: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x80800C2C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800C30: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800C34: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800C38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C3C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800C40: jal         0x800EFA4C
    // 0x80800C44: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800C44: nop

    after_4:
    // 0x80800C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C4C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800C50: jal         0x800EF8BC
    // 0x80800C54: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800EF8BC(rdram, ctx);
        goto after_5;
    // 0x80800C54: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800C60: jal         0x800EF934
    // 0x80800C64: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800EF934(rdram, ctx);
        goto after_6;
    // 0x80800C64: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80800C68: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800C6C: jal         0x800EF04C
    // 0x80800C70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_7;
    // 0x80800C70: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80800C74: jal         0x8009EF34
    // 0x80800C78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bastick_getY(rdram, ctx);
        goto after_8;
    // 0x80800C78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80800C7C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800C80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800C84: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80800C88: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800C8C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C94: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800C98: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800C9C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80800CA0: jal         0x800EFA4C
    // 0x80800CA4: nop

    func_800EFA4C(rdram, ctx);
        goto after_9;
    // 0x80800CA4: nop

    after_9:
    // 0x80800CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800CB0: jal         0x800EF8BC
    // 0x80800CB4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800EF8BC(rdram, ctx);
        goto after_10;
    // 0x80800CB4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CBC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800CC0: jal         0x800EF934
    // 0x80800CC4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_800EF934(rdram, ctx);
        goto after_11;
    // 0x80800CC4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x80800CC8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80800CCC: jal         0x800EF04C
    // 0x80800CD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_12;
    // 0x80800CD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_12:
    // 0x80800CD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800CD8: jal         0x8009BA9C
    // 0x80800CDC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8009BA9C(rdram, ctx);
        goto after_13;
    // 0x80800CDC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_13:
    // 0x80800CE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CE4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800CE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800CEC: jr          $ra
    // 0x80800CF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80800CF0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _chcredits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086B20: syscall     416
    recomp_syscall_handler(rdram, ctx, 0x80086B20);
    return;
    // 0x80086B24: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080071C_basetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080071C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800724: addiu       $a2, $zero, 0x52
    ctx->r6 = ADD32(0, 0X52);
    // 0x80800728: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8080072C: jal         0x800A9C98
    // 0x80800730: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800A9C98(rdram, ctx);
        goto after_0;
    // 0x80800730: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800734: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800738: beq         $v0, $zero, L_80800748
    if (ctx->r2 == 0) {
        // 0x8080073C: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_80800748;
    }
    // 0x8080073C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80800740: b           L_80800768
    // 0x80800744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800768;
    // 0x80800744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800748:
    // 0x80800748: blez        $a0, L_80800760
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8080074C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800760;
    }
    // 0x8080074C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800750: slti        $at, $a0, 0x29
    ctx->r1 = SIGNED(ctx->r4) < 0X29 ? 1 : 0;
    // 0x80800754: beq         $at, $zero, L_80800760
    if (ctx->r1 == 0) {
        // 0x80800758: nop
    
            goto L_80800760;
    }
    // 0x80800758: nop

    // 0x8080075C: addiu       $a2, $a0, 0x52
    ctx->r6 = ADD32(ctx->r4, 0X52);
L_80800760:
    // 0x80800760: jal         0x800882E8
    // 0x80800764: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    _gccubesearch_entrypoint_14(rdram, ctx);
        goto after_1;
    // 0x80800764: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_80800768:
    // 0x80800768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080076C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800770: jr          $ra
    // 0x80800774: nop

    return;
    // 0x80800774: nop

;}
RECOMP_FUNC void func_80801E2C_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801E30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801E34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801E38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801E3C: jal         0x80100094
    // 0x80801E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801E44: jal         0x800D8FF8
    // 0x80801E48: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801E48: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801E4C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80801E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801E54: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80801E58: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80801E5C: jal         0x801022E4
    // 0x80801E60: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    func_801022E4(rdram, ctx);
        goto after_2;
    // 0x80801E60: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    after_2:
    // 0x80801E64: addiu       $t6, $v0, -0x7D
    ctx->r14 = ADD32(ctx->r2, -0X7D);
    // 0x80801E68: sltiu       $at, $t6, 0xE
    ctx->r1 = ctx->r14 < 0XE ? 1 : 0;
    // 0x80801E6C: beq         $at, $zero, L_80801FB4
    if (ctx->r1 == 0) {
        // 0x80801E70: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801FB4;
    }
    // 0x80801E70: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80801E74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X377C) << 16);
    // 0x80801E78: addu        $at, $at, $t6
    gpr jr_addend_80801E80 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801E7C: lw          $t6, 0x377C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1564, 0X377C));
    // 0x80801E80: jr          $t6
    // 0x80801E84: nop

    switch (jr_addend_80801E80 >> 2) {
        case 0: goto L_80801E88; break;
        case 1: goto L_80801FB4; break;
        case 2: goto L_80801FB4; break;
        case 3: goto L_80801F78; break;
        case 4: goto L_80801FB4; break;
        case 5: goto L_80801FB4; break;
        case 6: goto L_80801FB4; break;
        case 7: goto L_80801FB4; break;
        case 8: goto L_80801F54; break;
        case 9: goto L_80801FB4; break;
        case 10: goto L_80801FB4; break;
        case 11: goto L_80801FB4; break;
        case 12: goto L_80801F0C; break;
        case 13: goto L_80801F30; break;
        default: switch_error(__func__, 0x80801E80, 0x8080377C);
    }
    // 0x80801E84: nop

L_80801E88:
    // 0x80801E88: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801E8C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1564, 0X3964) << 16);
    // 0x80801E90: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80801E94: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801E98: addiu       $a2, $a2, 0x3964
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1564, 0X3964));
    // 0x80801E9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801EA0: jal         0x80089D20
    // 0x80801EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80801EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801EA8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80801EAC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801EB0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X37B4) << 16);
    // 0x80801EB4: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80801EB8: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80801EBC: nop

    // 0x80801EC0: bc1fl       L_80801FB8
    if (!c1cs) {
        // 0x80801EC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801FB8;
    }
    goto skip_0;
    // 0x80801EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801EC8: jal         0x800DC298
    // 0x80801ECC: lwc1        $f12, 0x37B4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X37B4));
    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x80801ECC: lwc1        $f12, 0x37B4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1564, 0X37B4));
    after_4:
    // 0x80801ED0: beql        $v0, $zero, L_80801FB8
    if (ctx->r2 == 0) {
        // 0x80801ED4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801FB8;
    }
    goto skip_1;
    // 0x80801ED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80801ED8: jal         0x800C0638
    // 0x80801EDC: nop

    func_800C0638(rdram, ctx);
        goto after_5;
    // 0x80801EDC: nop

    after_5:
    // 0x80801EE0: bne         $v0, $zero, L_80801FB4
    if (ctx->r2 != 0) {
        // 0x80801EE4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801FB4;
    }
    // 0x80801EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801EE8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1564, 0X3950) << 16);
    // 0x80801EEC: addiu       $a2, $a2, 0x3950
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1564, 0X3950));
    // 0x80801EF0: jal         0x80089D18
    // 0x80801EF4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80801EF4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80801EF8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80801EFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801F00: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80801F04: b           L_80801FB4
    // 0x80801F08: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
        goto L_80801FB4;
    // 0x80801F08: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
L_80801F0C:
    // 0x80801F0C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1564, 0X3964) << 16);
    // 0x80801F10: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1564, 0X3E90) << 16);
    // 0x80801F14: addiu       $a3, $a3, 0x3E90
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1564, 0X3E90));
    // 0x80801F18: addiu       $a2, $a2, 0x3964
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1564, 0X3964));
    // 0x80801F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F20: jal         0x80089D28
    // 0x80801F24: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80801F24: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80801F28: b           L_80801FB8
    // 0x80801F2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801FB8;
    // 0x80801F2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F30:
    // 0x80801F30: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1564, 0X3964) << 16);
    // 0x80801F34: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1564, 0X3E9C) << 16);
    // 0x80801F38: addiu       $a3, $a3, 0x3E9C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1564, 0X3E9C));
    // 0x80801F3C: addiu       $a2, $a2, 0x3964
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1564, 0X3964));
    // 0x80801F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F44: jal         0x80089D28
    // 0x80801F48: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80801F48: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80801F4C: b           L_80801FB8
    // 0x80801F50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801FB8;
    // 0x80801F50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F54:
    // 0x80801F54: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1564, 0X3978) << 16);
    // 0x80801F58: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1564, 0X3EB0) << 16);
    // 0x80801F5C: addiu       $a3, $a3, 0x3EB0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1564, 0X3EB0));
    // 0x80801F60: addiu       $a2, $a2, 0x3978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1564, 0X3978));
    // 0x80801F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801F68: jal         0x80089D28
    // 0x80801F6C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_9;
    // 0x80801F6C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80801F70: b           L_80801FB8
    // 0x80801F74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801FB8;
    // 0x80801F74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F78:
    // 0x80801F78: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801F7C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1564, 0X3964) << 16);
    // 0x80801F80: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1564, 0X3EBC) << 16);
    // 0x80801F84: addiu       $a3, $a3, 0x3EBC
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1564, 0X3EBC));
    // 0x80801F88: addiu       $a2, $a2, 0x3964
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1564, 0X3964));
    // 0x80801F8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80801F90: jal         0x80089D28
    // 0x80801F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80801F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801F98: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1564, 0X3978) << 16);
    // 0x80801F9C: lui         $a3, 0x3F66
    ctx->r7 = S32(0X3F66 << 16);
    // 0x80801FA0: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80801FA4: addiu       $a2, $a2, 0x3978
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1564, 0X3978));
    // 0x80801FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801FAC: jal         0x80089D20
    // 0x80801FB0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_11;
    // 0x80801FB0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_11:
L_80801FB4:
    // 0x80801FB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801FB8:
    // 0x80801FB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801FBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801FC0: jr          $ra
    // 0x80801FC4: nop

    return;
    // 0x80801FC4: nop

;}
RECOMP_FUNC void func_808007C8_chcablecar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808007CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808007D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808007D4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808007D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808007DC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x808007E0: jal         0x80100094
    // 0x808007E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007E8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808007EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007F0: jal         0x8008A4B0
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x808007F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808007F8: jal         0x801039E4
    // 0x808007FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_801039E4(rdram, ctx);
        goto after_2;
    // 0x808007FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80800800: jal         0x80103D48
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103D48(rdram, ctx);
        goto after_3;
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800808: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8080080C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800810: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    // 0x80800814: bnel        $t6, $at, L_80800834
    if (ctx->r14 != ctx->r1) {
        // 0x80800818: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_80800834;
    }
    goto skip_0;
    // 0x80800818: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8080081C: jal         0x800DA9E4
    // 0x80800820: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_4;
    // 0x80800820: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800824: beq         $v0, $zero, L_80800830
    if (ctx->r2 == 0) {
        // 0x80800828: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_80800830;
    }
    // 0x80800828: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8080082C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80800830:
    // 0x80800830: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
L_80800834:
    // 0x80800834: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080083C: beq         $t8, $at, L_80800858
    if (ctx->r24 == ctx->r1) {
        // 0x80800840: lw          $a1, 0x2C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X2C);
            goto L_80800858;
    }
    // 0x80800840: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800844: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800848: beq         $t8, $at, L_80800878
    if (ctx->r24 == ctx->r1) {
        // 0x8080084C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800878;
    }
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800850: b           L_8080089C
    // 0x80800854: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_8080089C;
    // 0x80800854: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80800858:
    // 0x80800858: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x8080085C: ori         $a3, $a3, 0x10
    ctx->r7 = ctx->r7 | 0X10;
    // 0x80800860: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    // 0x80800864: addiu       $a2, $zero, 0x2F
    ctx->r6 = ADD32(0, 0X2F);
    // 0x80800868: jal         0x8008A2E0
    // 0x8080086C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x8080086C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80800870: b           L_808008F0
    // 0x80800874: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
        goto L_808008F0;
    // 0x80800874: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_80800878:
    // 0x80800878: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8080087C: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x80800880: ori         $a3, $a3, 0x10
    ctx->r7 = ctx->r7 | 0X10;
    // 0x80800884: addiu       $a2, $zero, 0x2E
    ctx->r6 = ADD32(0, 0X2E);
    // 0x80800888: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8080088C: jal         0x8008A2E0
    // 0x80800890: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    _susubgame_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800890: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_6:
    // 0x80800894: b           L_808008F0
    // 0x80800898: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
        goto L_808008F0;
    // 0x80800898: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_8080089C:
    // 0x8080089C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008A0: bne         $t9, $at, L_808008B0
    if (ctx->r25 != ctx->r1) {
        // 0x808008A4: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_808008B0;
    }
    // 0x808008A4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x808008A8: b           L_808008B4
    // 0x808008AC: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
        goto L_808008B4;
    // 0x808008AC: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
L_808008B0:
    // 0x808008B0: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
L_808008B4:
    // 0x808008B4: jal         0x80015178
    // 0x808008B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80015178(rdram, ctx);
        goto after_7;
    // 0x808008B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_7:
    // 0x808008BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x808008C0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808008C4: lui         $a3, 0x1
    ctx->r7 = S32(0X1 << 16);
    // 0x808008C8: lbu         $t1, 0x2A($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2A);
    // 0x808008CC: ori         $a3, $a3, 0x70
    ctx->r7 = ctx->r7 | 0X70;
    // 0x808008D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D4: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x808008D8: sb          $t2, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r10;
    // 0x808008DC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808008E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808008E4: jal         0x8008A2D0
    // 0x808008E8: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_8;
    // 0x808008E8: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_8:
    // 0x808008EC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
L_808008F0:
    // 0x808008F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008F4: sw          $t3, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r11;
    // 0x808008F8: jal         0x80101FDC
    // 0x808008FC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x808008FC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_9:
    // 0x80800900: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800904: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800908: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080090C: jr          $ra
    // 0x80800910: nop

    return;
    // 0x80800910: nop

;}
RECOMP_FUNC void func_80801FC8_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801FC8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80801FCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801FD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801FD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801FD8: jal         0x80100094
    // 0x80801FDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801FDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801FE0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80801FE4: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x80801FE8: jal         0x800D0A9C
    // 0x80801FEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_1;
    // 0x80801FEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801FF0: lbu         $t9, 0x65($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X65);
    // 0x80801FF4: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80801FF8: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x80801FFC: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x80802000: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80802004: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x80802008: jal         0x8080011C
    // 0x8080200C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080011C_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x8080200C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802010: beq         $v0, $zero, L_808020BC
    if (ctx->r2 == 0) {
        // 0x80802014: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808020BC;
    }
    // 0x80802014: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802018: beq         $v0, $at, L_80802030
    if (ctx->r2 == ctx->r1) {
        // 0x8080201C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802030;
    }
    // 0x8080201C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802020: beq         $v0, $at, L_80802088
    if (ctx->r2 == ctx->r1) {
        // 0x80802024: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802088;
    }
    // 0x80802024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802028: b           L_808020C0
    // 0x8080202C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
        goto L_808020C0;
    // 0x8080202C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80802030:
    // 0x80802030: lw          $t2, 0x64($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X64);
    // 0x80802034: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80802038: addiu       $a0, $zero, 0x384
    ctx->r4 = ADD32(0, 0X384);
    // 0x8080203C: sll         $t4, $t2, 12
    ctx->r12 = S32(ctx->r10 << 12);
    // 0x80802040: bgez        $t4, L_8080205C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80802044: nop
    
            goto L_8080205C;
    }
    // 0x80802044: nop

    // 0x80802048: jal         0x80088480
    // 0x8080204C: addiu       $a0, $zero, 0x385
    ctx->r4 = ADD32(0, 0X385);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8080204C: addiu       $a0, $zero, 0x385
    ctx->r4 = ADD32(0, 0X385);
    after_3:
    // 0x80802050: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80802054: b           L_8080206C
    // 0x80802058: sh          $v0, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r2;
        goto L_8080206C;
    // 0x80802058: sh          $v0, 0xC($t5)
    MEM_H(0XC, ctx->r13) = ctx->r2;
L_8080205C:
    // 0x8080205C: jal         0x80088480
    // 0x80802060: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80802060: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x80802064: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80802068: sh          $v0, 0xC($t6)
    MEM_H(0XC, ctx->r14) = ctx->r2;
L_8080206C:
    // 0x8080206C: jal         0x80800024
    // 0x80802070: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80800024_chclockworkmouse(rdram, ctx);
        goto after_5;
    // 0x80802070: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80802074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802078: jal         0x808026E0
    // 0x8080207C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_6;
    // 0x8080207C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80802080: b           L_808020C0
    // 0x80802084: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
        goto L_808020C0;
    // 0x80802084: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_80802088:
    // 0x80802088: jal         0x808026E0
    // 0x8080208C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_7;
    // 0x8080208C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_7:
    // 0x80802090: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80802094: addiu       $a0, $zero, 0x389
    ctx->r4 = ADD32(0, 0X389);
    // 0x80802098: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8080209C: bgez        $t8, L_808020B4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808020A0: nop
    
            goto L_808020B4;
    }
    // 0x808020A0: nop

    // 0x808020A4: jal         0x80088480
    // 0x808020A8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x808020A8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_8:
    // 0x808020AC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x808020B0: sh          $v0, 0xC($t0)
    MEM_H(0XC, ctx->r8) = ctx->r2;
L_808020B4:
    // 0x808020B4: jal         0x8080019C
    // 0x808020B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080019C_chclockworkmouse(rdram, ctx);
        goto after_9;
    // 0x808020B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_808020BC:
    // 0x808020BC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_808020C0:
    // 0x808020C0: jal         0x800D0A9C
    // 0x808020C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800D0A9C(rdram, ctx);
        goto after_10;
    // 0x808020C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_10:
    // 0x808020C8: beql        $v0, $zero, L_80802134
    if (ctx->r2 == 0) {
        // 0x808020CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802134;
    }
    goto skip_0;
    // 0x808020CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808020D0: jal         0x800DA298
    // 0x808020D4: addiu       $a0, $zero, 0x504
    ctx->r4 = ADD32(0, 0X504);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x808020D4: addiu       $a0, $zero, 0x504
    ctx->r4 = ADD32(0, 0X504);
    after_11:
    // 0x808020D8: bne         $v0, $zero, L_80802130
    if (ctx->r2 != 0) {
        // 0x808020DC: addiu       $a0, $zero, 0x388
        ctx->r4 = ADD32(0, 0X388);
            goto L_80802130;
    }
    // 0x808020DC: addiu       $a0, $zero, 0x388
    ctx->r4 = ADD32(0, 0X388);
    // 0x808020E0: jal         0x80088480
    // 0x808020E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _glsplinefind_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x808020E4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_12:
    // 0x808020E8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x808020EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808020F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808020F4: sh          $v0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r2;
    // 0x808020F8: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    // 0x808020FC: jal         0x801058C4
    // 0x80802100: lh          $a1, 0xC($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XC);
    func_801058C4(rdram, ctx);
        goto after_13;
    // 0x80802100: lh          $a1, 0xC($v1)
    ctx->r5 = MEM_H(ctx->r3, 0XC);
    after_13:
    // 0x80802104: jal         0x80088840
    // 0x80802108: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_14;
    // 0x80802108: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    after_14:
    // 0x8080210C: beq         $v0, $zero, L_80802128
    if (ctx->r2 == 0) {
        // 0x80802110: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80802128;
    }
    // 0x80802110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802118: jal         0x808026E0
    // 0x8080211C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_15;
    // 0x8080211C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_15:
    // 0x80802120: b           L_80802134
    // 0x80802124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80802134;
    // 0x80802124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802128:
    // 0x80802128: jal         0x808026E0
    // 0x8080212C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_808026E0_chclockworkmouse(rdram, ctx);
        goto after_16;
    // 0x8080212C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_16:
L_80802130:
    // 0x80802130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80802134:
    // 0x80802134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80802138: jal         0x800897C0
    // 0x8080213C: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_17;
    // 0x8080213C: addiu       $a2, $zero, 0x36
    ctx->r6 = ADD32(0, 0X36);
    after_17:
    // 0x80802140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802144: jal         0x80100094
    // 0x80802148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_18;
    // 0x80802148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x8080214C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802150: lui         $a1, 0x4234
    ctx->r5 = S32(0X4234 << 16);
    // 0x80802154: jal         0x800897E8
    // 0x80802158: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_19;
    // 0x80802158: lui         $a2, 0x4170
    ctx->r6 = S32(0X4170 << 16);
    after_19:
    // 0x8080215C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802160: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80802164: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80802168: jr          $ra
    // 0x8080216C: nop

    return;
    // 0x8080216C: nop

;}
RECOMP_FUNC void bawobble_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080012C: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80800130: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800134: sb          $zero, 0xC($t6)
    MEM_B(0XC, ctx->r14) = 0;
    // 0x80800138: jal         0x8080004C
    // 0x8080013C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080004C_bawobble(rdram, ctx);
        goto after_0;
    // 0x8080013C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800140: jal         0x808000B4
    // 0x80800144: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bawobble_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800144: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080014C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800150: jr          $ra
    // 0x80800154: nop

    return;
    // 0x80800154: nop

;}
RECOMP_FUNC void _subaddierouteDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F80: syscall     818
    recomp_syscall_handler(rdram, ctx, 0x80089F80);
    return;
    // 0x80089F84: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _chdinotraindoorswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087138: syscall     521
    recomp_syscall_handler(rdram, ctx, 0x80087138);
    return;
    // 0x8008713C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800F3214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3214: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800F3218: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800F321C: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800F3220: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800F3224: subu        $t7, $t6, $v1
    ctx->r15 = SUB32(ctx->r14, ctx->r3);
    // 0x800F3228: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800F322C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F3230: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F3234: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F3238: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F323C: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800F3240: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800F3244: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800F3248: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800F324C: nop

    // 0x800F3250: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800F3254: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x800F3258: lw          $a3, 0x4($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X4);
    // 0x800F325C: subu        $t2, $t1, $a3
    ctx->r10 = SUB32(ctx->r9, ctx->r7);
    // 0x800F3260: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800F3264: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800F3268: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F326C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F3270: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800F3274: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800F3278: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800F327C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800F3280: nop

    // 0x800F3284: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x800F3288: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x800F328C: lw          $t0, 0x8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8);
    // 0x800F3290: subu        $t6, $t5, $t0
    ctx->r14 = SUB32(ctx->r13, ctx->r8);
    // 0x800F3294: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800F3298: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800F329C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F32A0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800F32A4: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800F32A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F32AC: nop

    // 0x800F32B0: c.eq.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl == ctx->f16.fl;
    // 0x800F32B4: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800F32B8: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800F32BC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800F32C0: bc1f        L_800F32CC
    if (!c1cs) {
        // 0x800F32C4: sw          $t8, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r24;
            goto L_800F32CC;
    }
    // 0x800F32C4: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x800F32C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F32CC:
    // 0x800F32CC: jr          $ra
    // 0x800F32D0: nop

    return;
    // 0x800F32D0: nop

;}
RECOMP_FUNC void func_80800DFC_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E04: jal         0x800845D0
    // 0x80800E08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800E08: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E10: jal         0x800961AC
    // 0x80800E14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_1;
    // 0x80800E14: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80800E18: jal         0x80800104
    // 0x80800E1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800104_bsbswim(rdram, ctx);
        goto after_2;
    // 0x80800E1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800E20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E28: jr          $ra
    // 0x80800E2C: nop

    return;
    // 0x80800E2C: nop

;}
RECOMP_FUNC void func_80800024_chcactusofstrength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800028: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800030: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800034: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800038: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080003C: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800040: beq         $t6, $at, L_80800058
    if (ctx->r14 == ctx->r1) {
        // 0x80800044: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800058;
    }
    // 0x80800044: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800048: beq         $t6, $at, L_808000C8
    if (ctx->r14 == ctx->r1) {
        // 0x8080004C: nop
    
            goto L_808000C8;
    }
    // 0x8080004C: nop

    // 0x80800050: b           L_808000F8
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808000F8;
    // 0x80800054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800058:
    // 0x80800058: jal         0x80101DDC
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_0;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800060: beql        $v0, $zero, L_808000F8
    if (ctx->r2 == 0) {
        // 0x80800064: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808000F8;
    }
    goto skip_0;
    // 0x80800064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800068: lw          $v0, 0x6C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X6C);
    // 0x8080006C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800070: andi        $t7, $v0, 0x1FF
    ctx->r15 = ctx->r2 & 0X1FF;
    // 0x80800074: beq         $t7, $zero, L_80800098
    if (ctx->r15 == 0) {
        // 0x80800078: nop
    
            goto L_80800098;
    }
    // 0x80800078: nop

    // 0x8080007C: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800080: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800084: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80800088: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x8080008C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80800090: b           L_808000F4
    // 0x80800094: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
        goto L_808000F4;
    // 0x80800094: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
L_80800098:
    // 0x80800098: jal         0x80102424
    // 0x8080009C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080009C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808000A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808000A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808000A8: jal         0x800D9058
    // 0x808000AC: nop

    func_800D9058(rdram, ctx);
        goto after_2;
    // 0x808000AC: nop

    after_2:
    // 0x808000B0: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
    // 0x808000B4: andi        $t4, $v0, 0x1FF
    ctx->r12 = ctx->r2 & 0X1FF;
    // 0x808000B8: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x808000BC: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x808000C0: b           L_808000F4
    // 0x808000C4: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
        goto L_808000F4;
    // 0x808000C4: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
L_808000C8:
    // 0x808000C8: jal         0x80101DDC
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_3;
    // 0x808000CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808000D0: beq         $v0, $zero, L_808000F4
    if (ctx->r2 == 0) {
        // 0x808000D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000F4;
    }
    // 0x808000D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D8: jal         0x80102424
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_4;
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x808000E0: jal         0x800880D0
    // 0x808000E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcaudiolist_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808000E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000EC: jal         0x80103110
    // 0x808000F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80103110(rdram, ctx);
        goto after_6;
    // 0x808000F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_808000F4:
    // 0x808000F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808000F8:
    // 0x808000F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800100: jr          $ra
    // 0x80800104: nop

    return;
    // 0x80800104: nop

;}
RECOMP_FUNC void _bamotor_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800854A0: syscall     163
    recomp_syscall_handler(rdram, ctx, 0x800854A0);
    return;
    // 0x800854A4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _gccubeDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087C78: syscall     655
    recomp_syscall_handler(rdram, ctx, 0x80087C78);
    return;
    // 0x80087C7C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chdoormake_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800870: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800874: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800878: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080087C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800880: jal         0x80100094
    // 0x80800884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800888: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8080088C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800890: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80800894: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80800898: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080089C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x808008A0: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x808008A4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808008A8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x808008AC: nop

    // 0x808008B0: sh          $t7, 0x24($t0)
    MEM_H(0X24, ctx->r8) = ctx->r15;
    // 0x808008B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008BC: jr          $ra
    // 0x808008C0: nop

    return;
    // 0x808008C0: nop

;}
RECOMP_FUNC void glgamestore_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800244: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800248: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080024C: jal         0x80800030
    // 0x80800250: nop

    func_80800030_glgamestore(rdram, ctx);
        goto after_0;
    // 0x80800250: nop

    after_0:
    // 0x80800254: jal         0x808001E0
    // 0x80800258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_808001E0_glgamestore(rdram, ctx);
        goto after_1;
    // 0x80800258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080025C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800264: jr          $ra
    // 0x80800268: nop

    return;
    // 0x80800268: nop

    // 0x8080026C: nop

;}
RECOMP_FUNC void _bsbfly_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082978: syscall     22
    recomp_syscall_handler(rdram, ctx, 0x80082978);
    return;
    // 0x8008297C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80101D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101D0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101D14: jal         0x80104248
    // 0x80101D18: nop

    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80101D18: nop

    after_0:
    // 0x80101D1C: beq         $v0, $zero, L_80101D34
    if (ctx->r2 == 0) {
        // 0x80101D20: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101D34;
    }
    // 0x80101D20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101D24: jal         0x8008B2AC
    // 0x80101D28: nop

    func_8008B2AC(rdram, ctx);
        goto after_1;
    // 0x80101D28: nop

    after_1:
    // 0x80101D2C: b           L_80101D40
    // 0x80101D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80101D40;
    // 0x80101D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80101D34:
    // 0x80101D34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80101D38: nop

    // 0x80101D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80101D40:
    // 0x80101D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101D44: jr          $ra
    // 0x80101D48: nop

    return;
    // 0x80101D48: nop

;}
RECOMP_FUNC void func_800A5550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5558: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A555C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A5560: lhu         $a0, 0x1A($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X1A);
    // 0x800A5564: srl         $t7, $a0, 5
    ctx->r15 = S32(U32(ctx->r4) >> 5);
    // 0x800A5568: jal         0x800A93E4
    // 0x800A556C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_800A93E4(rdram, ctx);
        goto after_0;
    // 0x800A556C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x800A5570: jal         0x80110014
    // 0x800A5574: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x800A5574: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A5578: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A557C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800A5580: jal         0x800893A8
    // 0x800A5584: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    _ncbaspline_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x800A5584: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800A5588: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A558C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5590: jr          $ra
    // 0x800A5594: nop

    return;
    // 0x800A5594: nop

;}
RECOMP_FUNC void _bssnowball_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A30: syscall     87
    recomp_syscall_handler(rdram, ctx, 0x80083A30);
    return;
    // 0x80083A34: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801AF8_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801AF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801AFC: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2658, 0X2130) << 16);
    // 0x80801B00: lh          $t6, 0x2130($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(2658, 0X2130));
    // 0x80801B04: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80801B08: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80801B0C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80801B10: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80801B14: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80801B18: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801B1C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80801B20: beq         $s1, $t6, L_80801B74
    if (ctx->r17 == ctx->r14) {
        // 0x80801B24: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80801B74;
    }
    // 0x80801B24: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80801B28: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2658, 0X2130) << 16);
    // 0x80801B2C: addiu       $s0, $t7, 0x2130
    ctx->r16 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2658, 0X2130));
    // 0x80801B30: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_80801B34:
    // 0x80801B34: jal         0x800D035C
    // 0x80801B38: nop

    func_800D035C(rdram, ctx);
        goto after_0;
    // 0x80801B38: nop

    after_0:
    // 0x80801B3C: beq         $v0, $zero, L_80801B64
    if (ctx->r2 == 0) {
        // 0x80801B40: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80801B64;
    }
    // 0x80801B40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801B44: lh          $a1, 0x4($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4);
    // 0x80801B48: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x80801B4C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80801B50: jal         0x8080190C
    // 0x80801B54: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_8080190C_gcnewpause(rdram, ctx);
        goto after_1;
    // 0x80801B54: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_1:
    // 0x80801B58: beql        $v0, $zero, L_80801B68
    if (ctx->r2 == 0) {
        // 0x80801B5C: lh          $a0, 0x6($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X6);
            goto L_80801B68;
    }
    goto skip_0;
    // 0x80801B5C: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
    skip_0:
    // 0x80801B60: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80801B64:
    // 0x80801B64: lh          $a0, 0x6($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X6);
L_80801B68:
    // 0x80801B68: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x80801B6C: bne         $s1, $a0, L_80801B34
    if (ctx->r17 != ctx->r4) {
        // 0x80801B70: nop
    
            goto L_80801B34;
    }
    // 0x80801B70: nop

L_80801B74:
    // 0x80801B74: jal         0x800DAD10
    // 0x80801B78: nop

    func_800DAD10(rdram, ctx);
        goto after_2;
    // 0x80801B78: nop

    after_2:
    // 0x80801B7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801B80: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x80801B84: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80801B88: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80801B8C: jal         0x8080190C
    // 0x80801B90: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_8080190C_gcnewpause(rdram, ctx);
        goto after_3;
    // 0x80801B90: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_3:
    // 0x80801B94: beq         $v0, $zero, L_80801BA0
    if (ctx->r2 == 0) {
        // 0x80801B98: nop
    
            goto L_80801BA0;
    }
    // 0x80801B98: nop

    // 0x80801B9C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80801BA0:
    // 0x80801BA0: jal         0x80801C3C
    // 0x80801BA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80801C3C_gcnewpause(rdram, ctx);
        goto after_4;
    // 0x80801BA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80801BA8: beq         $v0, $zero, L_80801BD0
    if (ctx->r2 == 0) {
        // 0x80801BAC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80801BD0;
    }
    // 0x80801BAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801BB0: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80801BB4: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80801BB8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80801BBC: jal         0x8080190C
    // 0x80801BC0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    func_8080190C_gcnewpause(rdram, ctx);
        goto after_5;
    // 0x80801BC0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_5:
    // 0x80801BC4: beql        $v0, $zero, L_80801BD4
    if (ctx->r2 == 0) {
        // 0x80801BC8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80801BD4;
    }
    goto skip_1;
    // 0x80801BC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80801BCC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80801BD0:
    // 0x80801BD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80801BD4:
    // 0x80801BD4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80801BD8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80801BDC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80801BE0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80801BE4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80801BE8: jr          $ra
    // 0x80801BEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801BEC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
