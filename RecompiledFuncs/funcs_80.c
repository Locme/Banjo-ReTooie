#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808003F8_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808003FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800400: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800404: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80800408: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8080040C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800410: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1236, 0X12B8) << 16);
    // 0x80800414: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80800418: addiu       $a0, $a0, 0x12B8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1236, 0X12B8));
    // 0x8080041C: addiu       $a1, $zero, 0xC1C
    ctx->r5 = ADD32(0, 0XC1C);
    // 0x80800420: addiu       $a2, $zero, -0x8C
    ctx->r6 = ADD32(0, -0X8C);
    // 0x80800424: bc1fl       L_808004E8
    if (!c1cs) {
        // 0x80800428: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808004E8;
    }
    goto skip_0;
    // 0x80800428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080042C: jal         0x8010CB0C
    // 0x80800430: addiu       $a3, $zero, -0xFA
    ctx->r7 = ADD32(0, -0XFA);
    func_8010CB0C(rdram, ctx);
        goto after_0;
    // 0x80800430: addiu       $a3, $zero, -0xFA
    ctx->r7 = ADD32(0, -0XFA);
    after_0:
    // 0x80800434: beql        $v0, $zero, L_808004E8
    if (ctx->r2 == 0) {
        // 0x80800438: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808004E8;
    }
    goto skip_1;
    // 0x80800438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8080043C: jal         0x800F54E4
    // 0x80800440: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x80800440: nop

    after_1:
    // 0x80800444: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800448: jal         0x800F6C5C
    // 0x8080044C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_2;
    // 0x8080044C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800450: beql        $v0, $zero, L_808004E8
    if (ctx->r2 == 0) {
        // 0x80800454: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808004E8;
    }
    goto skip_2;
    // 0x80800454: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800458: jal         0x800F6478
    // 0x8080045C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800F6478(rdram, ctx);
        goto after_3;
    // 0x8080045C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80800460: beql        $v0, $zero, L_808004E8
    if (ctx->r2 == 0) {
        // 0x80800464: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808004E8;
    }
    goto skip_3;
    // 0x80800464: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80800468: jal         0x8010CD28
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_4;
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800470: jal         0x80800360
    // 0x80800474: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80800360_chbanjoctrl(rdram, ctx);
        goto after_5;
    // 0x80800474: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x80800478: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080047C: lui         $a2, 0x4541
    ctx->r6 = S32(0X4541 << 16);
    // 0x80800480: ori         $a2, $a2, 0xC000
    ctx->r6 = ctx->r6 | 0XC000;
    // 0x80800484: jal         0x800EFCD8
    // 0x80800488: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_800EFCD8(rdram, ctx);
        goto after_6;
    // 0x80800488: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x8080048C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800490: jal         0x800F54E4
    // 0x80800494: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800494: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x80800498: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080049C: addiu       $a1, $zero, 0x52
    ctx->r5 = ADD32(0, 0X52);
    // 0x808004A0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x808004A4: jal         0x800F7D90
    // 0x808004A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800F7D90(rdram, ctx);
        goto after_8;
    // 0x808004A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x808004AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004B0: bnel        $v0, $at, L_808004E8
    if (ctx->r2 != ctx->r1) {
        // 0x808004B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808004E8;
    }
    goto skip_4;
    // 0x808004B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x808004B8: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808004C4: bgez        $t8, L_808004DC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808004C8: nop
    
            goto L_808004DC;
    }
    // 0x808004C8: nop

    // 0x808004CC: jal         0x80800544
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800544_chbanjoctrl(rdram, ctx);
        goto after_9;
    // 0x808004D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808004D4: b           L_808004E8
    // 0x808004D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808004E8;
    // 0x808004D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004DC:
    // 0x808004DC: jal         0x80086448
    // 0x808004E0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    _chhotwaterpoolbits_entrypoint_5(rdram, ctx);
        goto after_10;
    // 0x808004E0: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_10:
    // 0x808004E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004E8:
    // 0x808004E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808004F0: jr          $ra
    // 0x808004F4: nop

    return;
    // 0x808004F4: nop

;}
RECOMP_FUNC void func_80800690_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800690: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800698: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x8080069C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x808006A0: addiu       $a2, $a3, 0x4
    ctx->r6 = ADD32(ctx->r7, 0X4);
    // 0x808006A4: sll         $a0, $v0, 11
    ctx->r4 = S32(ctx->r2 << 11);
    // 0x808006A8: srl         $t6, $a0, 20
    ctx->r14 = S32(U32(ctx->r4) >> 20);
    // 0x808006AC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x808006B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x808006B4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x808006B8: jal         0x800882F0
    // 0x808006BC: srl         $a1, $v0, 21
    ctx->r5 = S32(U32(ctx->r2) >> 21);
    _gccubesearch_entrypoint_15(rdram, ctx);
        goto after_0;
    // 0x808006BC: srl         $a1, $v0, 21
    ctx->r5 = S32(U32(ctx->r2) >> 21);
    after_0:
    // 0x808006C0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808006C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808006C8: jal         0x80088C00
    // 0x808006CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808006CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808006D0: jal         0x80088C08
    // 0x808006D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    _gspropctrl_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808006D4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x808006D8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808006DC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x808006E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x808006E4: swc1        $f6, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->f6.u32l;
    // 0x808006E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808006EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006F0: jr          $ra
    // 0x808006F4: nop

    return;
    // 0x808006F4: nop

;}
RECOMP_FUNC void func_80801F44_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801F48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801F4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801F50: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x80801F54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801F58: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80801F5C: bltz        $t8, L_80802064
    if (SIGNED(ctx->r24) < 0) {
        // 0x80801F60: nop
    
            goto L_80802064;
    }
    // 0x80801F60: nop

    // 0x80801F64: jal         0x80106790
    // 0x80801F68: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80801F68: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80801F6C: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x80801F70: addiu       $at, $zero, 0x223
    ctx->r1 = ADD32(0, 0X223);
    // 0x80801F74: sll         $t9, $v1, 11
    ctx->r25 = S32(ctx->r3 << 11);
    // 0x80801F78: srl         $t0, $t9, 20
    ctx->r8 = S32(U32(ctx->r25) >> 20);
    // 0x80801F7C: beq         $t0, $at, L_80801F9C
    if (ctx->r8 == ctx->r1) {
        // 0x80801F80: addiu       $at, $zero, 0x224
        ctx->r1 = ADD32(0, 0X224);
            goto L_80801F9C;
    }
    // 0x80801F80: addiu       $at, $zero, 0x224
    ctx->r1 = ADD32(0, 0X224);
    // 0x80801F84: beq         $t0, $at, L_80801FDC
    if (ctx->r8 == ctx->r1) {
        // 0x80801F88: addiu       $at, $zero, 0x225
        ctx->r1 = ADD32(0, 0X225);
            goto L_80801FDC;
    }
    // 0x80801F88: addiu       $at, $zero, 0x225
    ctx->r1 = ADD32(0, 0X225);
    // 0x80801F8C: beql        $t0, $at, L_80802020
    if (ctx->r8 == ctx->r1) {
        // 0x80801F90: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_80802020;
    }
    goto skip_0;
    // 0x80801F90: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80801F94: b           L_8080205C
    // 0x80801F98: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
        goto L_8080205C;
    // 0x80801F98: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
L_80801F9C:
    // 0x80801F9C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80801FA0: lbu         $t1, 0x2A($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X2A);
    // 0x80801FA4: andi        $t2, $t1, 0xFFDF
    ctx->r10 = ctx->r9 & 0XFFDF;
    // 0x80801FA8: sb          $t2, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r10;
    // 0x80801FAC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80801FB0: lw          $t3, 0x18($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X18);
    // 0x80801FB4: lbu         $t0, 0x1B($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1B);
    // 0x80801FB8: sll         $t4, $t3, 27
    ctx->r12 = S32(ctx->r11 << 27);
    // 0x80801FBC: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x80801FC0: ori         $t7, $t5, 0x1
    ctx->r15 = ctx->r13 | 0X1;
    // 0x80801FC4: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80801FC8: andi        $t9, $t8, 0x1E
    ctx->r25 = ctx->r24 & 0X1E;
    // 0x80801FCC: andi        $t1, $t0, 0xFFE1
    ctx->r9 = ctx->r8 & 0XFFE1;
    // 0x80801FD0: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80801FD4: b           L_80802058
    // 0x80801FD8: sb          $t2, 0x1B($v1)
    MEM_B(0X1B, ctx->r3) = ctx->r10;
        goto L_80802058;
    // 0x80801FD8: sb          $t2, 0x1B($v1)
    MEM_B(0X1B, ctx->r3) = ctx->r10;
L_80801FDC:
    // 0x80801FDC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80801FE0: lbu         $t3, 0x2A($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X2A);
    // 0x80801FE4: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x80801FE8: sb          $t4, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r12;
    // 0x80801FEC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80801FF0: lw          $t5, 0x18($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X18);
    // 0x80801FF4: lbu         $t2, 0x1B($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1B);
    // 0x80801FF8: sll         $t6, $t5, 27
    ctx->r14 = S32(ctx->r13 << 27);
    // 0x80801FFC: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80802000: ori         $t0, $t7, 0x2
    ctx->r8 = ctx->r15 | 0X2;
    // 0x80802004: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x80802008: andi        $t1, $t9, 0x1E
    ctx->r9 = ctx->r25 & 0X1E;
    // 0x8080200C: andi        $t3, $t2, 0xFFE1
    ctx->r11 = ctx->r10 & 0XFFE1;
    // 0x80802010: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80802014: b           L_80802058
    // 0x80802018: sb          $t4, 0x1B($v1)
    MEM_B(0X1B, ctx->r3) = ctx->r12;
        goto L_80802058;
    // 0x80802018: sb          $t4, 0x1B($v1)
    MEM_B(0X1B, ctx->r3) = ctx->r12;
    // 0x8080201C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_80802020:
    // 0x80802020: lbu         $t5, 0x2A($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2A);
    // 0x80802024: andi        $t6, $t5, 0xFFF7
    ctx->r14 = ctx->r13 & 0XFFF7;
    // 0x80802028: sb          $t6, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r14;
    // 0x8080202C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80802030: lw          $t7, 0x18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X18);
    // 0x80802034: lbu         $t4, 0x1B($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X1B);
    // 0x80802038: sll         $t8, $t7, 27
    ctx->r24 = S32(ctx->r15 << 27);
    // 0x8080203C: srl         $t0, $t8, 28
    ctx->r8 = S32(U32(ctx->r24) >> 28);
    // 0x80802040: ori         $t2, $t0, 0x4
    ctx->r10 = ctx->r8 | 0X4;
    // 0x80802044: sll         $t1, $t2, 1
    ctx->r9 = S32(ctx->r10 << 1);
    // 0x80802048: andi        $t3, $t1, 0x1E
    ctx->r11 = ctx->r9 & 0X1E;
    // 0x8080204C: andi        $t5, $t4, 0xFFE1
    ctx->r13 = ctx->r12 & 0XFFE1;
    // 0x80802050: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80802054: sb          $t6, 0x1B($v1)
    MEM_B(0X1B, ctx->r3) = ctx->r14;
L_80802058:
    // 0x80802058: lbu         $t8, 0x65($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X65);
L_8080205C:
    // 0x8080205C: ori         $t0, $t8, 0x10
    ctx->r8 = ctx->r24 | 0X10;
    // 0x80802060: sb          $t0, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r8;
L_80802064:
    // 0x80802064: jal         0x80101DDC
    // 0x80802068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_1;
    // 0x80802068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080206C: beq         $v0, $zero, L_8080207C
    if (ctx->r2 == 0) {
        // 0x80802070: nop
    
            goto L_8080207C;
    }
    // 0x80802070: nop

    // 0x80802074: jal         0x80089CA8
    // 0x80802078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80802078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_8080207C:
    // 0x8080207C: jal         0x80802098
    // 0x80802080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802098_chboilerboss(rdram, ctx);
        goto after_3;
    // 0x80802080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80802084: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802088: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080208C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802090: jr          $ra
    // 0x80802094: nop

    return;
    // 0x80802094: nop

;}
RECOMP_FUNC void chbubble_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x80800004: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8080000C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80800010: sw          $a0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r4;
    // 0x80800014: sw          $a1, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r5;
    // 0x80800018: sw          $a2, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r6;
    // 0x8080001C: sw          $a3, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r7;
    // 0x80800020: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800024: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800028: addiu       $s1, $sp, 0xF8
    ctx->r17 = ADD32(ctx->r29, 0XF8);
    // 0x8080002C: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x80800030: lw          $s0, 0x8($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X8);
    // 0x80800034: sw          $a3, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r7;
    // 0x80800038: jal         0x800E3980
    // 0x8080003C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x8080003C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80800040: lwc1        $f2, 0x118($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80800044: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800048: lw          $a0, 0x10C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10C);
    // 0x8080004C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80800050: nop

    // 0x80800054: bc1fl       L_80800088
    if (!c1cs) {
        // 0x80800058: addiu       $a0, $sp, 0xEC
        ctx->r4 = ADD32(ctx->r29, 0XEC);
            goto L_80800088;
    }
    goto skip_0;
    // 0x80800058: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
    skip_0:
    // 0x8080005C: jal         0x800EEB40
    // 0x80800060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EEB40(rdram, ctx);
        goto after_1;
    // 0x80800060: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80800064: lwc1        $f2, 0x118($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80800068: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8080006C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80800070: nop

    // 0x80800074: bc1fl       L_80800088
    if (!c1cs) {
        // 0x80800078: addiu       $a0, $sp, 0xEC
        ctx->r4 = ADD32(ctx->r29, 0XEC);
            goto L_80800088;
    }
    goto skip_1;
    // 0x80800078: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
    skip_1:
    // 0x8080007C: b           L_808006C0
    // 0x80800080: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808006C0;
    // 0x80800080: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800084: addiu       $a0, $sp, 0xEC
    ctx->r4 = ADD32(ctx->r29, 0XEC);
L_80800088:
    // 0x80800088: jal         0x800EE7F8
    // 0x8080008C: lw          $a1, 0x10C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10C);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8080008C: lw          $a1, 0x10C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10C);
    after_2:
    // 0x80800090: jal         0x800E401C
    // 0x80800094: nop

    func_800E401C(rdram, ctx);
        goto after_3;
    // 0x80800094: nop

    after_3:
    // 0x80800098: jal         0x80018EFC
    // 0x8080009C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mlMtxSet(rdram, ctx);
        goto after_4;
    // 0x8080009C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808000A0: lwc1        $f12, 0xEC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x808000A4: lwc1        $f14, 0xF0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x808000A8: jal         0x800191F8
    // 0x808000AC: lw          $a2, 0xF4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF4);
    func_800191F8(rdram, ctx);
        goto after_5;
    // 0x808000AC: lw          $a2, 0xF4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XF4);
    after_5:
    // 0x808000B0: lw          $t7, 0x108($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X108);
    // 0x808000B4: jal         0x80018C28
    // 0x808000B8: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    mlMtxApply(rdram, ctx);
        goto after_6;
    // 0x808000B8: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_6:
    // 0x808000BC: lw          $v0, 0xC8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC8);
    // 0x808000C0: lw          $a2, 0x108($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X108);
    // 0x808000C4: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x808000C8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x808000CC: lw          $v1, 0x110($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X110);
    // 0x808000D0: lwc1        $f2, 0x114($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X114);
    // 0x808000D4: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x808000D8: ori         $t6, $t6, 0x2
    ctx->r14 = ctx->r14 | 0X2;
    // 0x808000DC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x808000E0: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    // 0x808000E4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808000E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808000EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808000F0: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x808000F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x808000F8: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x808000FC: addiu       $a1, $sp, 0xE4
    ctx->r5 = ADD32(ctx->r29, 0XE4);
    // 0x80800100: addiu       $t6, $t9, 0x40
    ctx->r14 = ADD32(ctx->r25, 0X40);
    // 0x80800104: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80800108: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8080010C: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800110: lw          $a0, 0x10C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10C);
    // 0x80800114: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800118: nop

    // 0x8080011C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80800120: nop

    // 0x80800124: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80800128: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8080012C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80800130: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80800134: nop

    // 0x80800138: sw          $t2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r10;
    // 0x8080013C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800140: mfc1        $s1, $f10
    ctx->r17 = (int32_t)ctx->f10.u32l;
    // 0x80800144: jal         0x800E4140
    // 0x80800148: nop

    func_800E4140(rdram, ctx);
        goto after_7;
    // 0x80800148: nop

    after_7:
    // 0x8080014C: lw          $t9, 0x110($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X110);
    // 0x80800150: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80800154: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800158: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8080015C: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80800160: lwc1        $f4, 0xE4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80800164: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80800168: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x8080016C: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
    // 0x80800170: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80800174: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80800178: addiu       $a0, $zero, 0x9CC
    ctx->r4 = ADD32(0, 0X9CC);
    // 0x8080017C: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80800180: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80800184: lwc1        $f18, 0xE8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80800188: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8080018C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80800190: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800194: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x80800198: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8080019C: bgez        $t0, L_808001AC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808001A0: slti        $at, $t0, 0x111
        ctx->r1 = SIGNED(ctx->r8) < 0X111 ? 1 : 0;
            goto L_808001AC;
    }
    // 0x808001A0: slti        $at, $t0, 0x111
    ctx->r1 = SIGNED(ctx->r8) < 0X111 ? 1 : 0;
    // 0x808001A4: b           L_808001B8
    // 0x808001A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_808001B8;
    // 0x808001A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_808001AC:
    // 0x808001AC: bne         $at, $zero, L_808001B8
    if (ctx->r1 != 0) {
        // 0x808001B0: nop
    
            goto L_808001B8;
    }
    // 0x808001B0: nop

    // 0x808001B4: addiu       $t0, $zero, 0x110
    ctx->r8 = ADD32(0, 0X110);
L_808001B8:
    // 0x808001B8: bgez        $t3, L_808001C8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808001BC: slti        $at, $t3, 0xC5
        ctx->r1 = SIGNED(ctx->r11) < 0XC5 ? 1 : 0;
            goto L_808001C8;
    }
    // 0x808001BC: slti        $at, $t3, 0xC5
    ctx->r1 = SIGNED(ctx->r11) < 0XC5 ? 1 : 0;
    // 0x808001C0: b           L_808001D4
    // 0x808001C4: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
        goto L_808001D4;
    // 0x808001C4: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_808001C8:
    // 0x808001C8: bnel        $at, $zero, L_808001D8
    if (ctx->r1 != 0) {
        // 0x808001CC: sw          $t6, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r14;
            goto L_808001D8;
    }
    goto skip_2;
    // 0x808001CC: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    skip_2:
    // 0x808001D0: addiu       $t3, $zero, 0xC4
    ctx->r11 = ADD32(0, 0XC4);
L_808001D4:
    // 0x808001D4: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
L_808001D8:
    // 0x808001D8: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x808001DC: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x808001E0: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x808001E4: lui         $t6, 0xD9C0
    ctx->r14 = S32(0XD9C0 << 16);
    // 0x808001E8: ori         $t6, $t6, 0xFFFA
    ctx->r14 = ctx->r14 | 0XFFFA;
    // 0x808001EC: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x808001F0: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x808001F4: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x808001F8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x808001FC: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x80800200: lui         $t6, 0x20
    ctx->r14 = S32(0X20 << 16);
    // 0x80800204: lui         $t8, 0xD9FF
    ctx->r24 = S32(0XD9FF << 16);
    // 0x80800208: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x8080020C: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x80800210: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80800214: ori         $t6, $t6, 0x5
    ctx->r14 = ctx->r14 | 0X5;
    // 0x80800218: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x8080021C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80800220: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x80800224: lui         $t8, 0xD700
    ctx->r24 = S32(0XD700 << 16);
    // 0x80800228: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8080022C: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80800230: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x80800234: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x80800238: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x8080023C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80800240: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80800244: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x80800248: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8080024C: ori         $t8, $t8, 0xF00
    ctx->r24 = ctx->r24 | 0XF00;
    // 0x80800250: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80800254: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x80800258: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8080025C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80800260: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80800264: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80800268: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x8080026C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80800270: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80800274: lui         $t8, 0x10
    ctx->r24 = S32(0X10 << 16);
    // 0x80800278: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8080027C: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80800280: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80800284: lui         $t7, 0xFC22
    ctx->r15 = S32(0XFC22 << 16);
    // 0x80800288: ori         $t7, $t7, 0x19FF
    ctx->r15 = ctx->r15 | 0X19FF;
    // 0x8080028C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80800290: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80800294: addiu       $t8, $zero, -0x1C8
    ctx->r24 = ADD32(0, -0X1C8);
    // 0x80800298: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8080029C: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x808002A0: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x808002A4: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x808002A8: lui         $t8, 0xC18
    ctx->r24 = S32(0XC18 << 16);
    // 0x808002AC: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x808002B0: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x808002B4: ori         $t8, $t8, 0x4A50
    ctx->r24 = ctx->r24 | 0X4A50;
    // 0x808002B8: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x808002BC: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x808002C0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x808002C4: sw          $t3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r11;
    // 0x808002C8: sw          $t2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r10;
    // 0x808002CC: jal         0x800D674C
    // 0x808002D0: sw          $t0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r8;
    func_800D674C(rdram, ctx);
        goto after_8;
    // 0x808002D0: sw          $t0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r8;
    after_8:
    // 0x808002D4: addiu       $t6, $sp, 0xD0
    ctx->r14 = ADD32(ctx->r29, 0XD0);
    // 0x808002D8: addiu       $t9, $sp, 0xCC
    ctx->r25 = ADD32(ctx->r29, 0XCC);
    // 0x808002DC: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x808002E0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x808002E4: addiu       $a0, $sp, 0xC8
    ctx->r4 = ADD32(ctx->r29, 0XC8);
    // 0x808002E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808002EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808002F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808002F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808002F8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x808002FC: jal         0x800AF614
    // 0x80800300: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_800AF614(rdram, ctx);
        goto after_9;
    // 0x80800300: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_9:
    // 0x80800304: jal         0x80014F00
    // 0x80800308: nop

    func_80014F00(rdram, ctx);
        goto after_10;
    // 0x80800308: nop

    after_10:
    // 0x8080030C: lw          $t3, 0xDC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XDC);
    // 0x80800310: lw          $v1, 0xC8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC8);
    // 0x80800314: lw          $t0, 0xE0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE0);
    // 0x80800318: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x8080031C: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x80800320: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800324: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x80800328: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8080032C: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
    // 0x80800330: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80800334: ori         $t6, $t6, 0x12F
    ctx->r14 = ctx->r14 | 0X12F;
    // 0x80800338: subu        $t9, $t9, $t3
    ctx->r25 = SUB32(ctx->r25, ctx->r11);
    // 0x8080033C: sll         $t7, $t9, 5
    ctx->r15 = S32(ctx->r25 << 5);
    // 0x80800340: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80800344: andi        $t6, $t0, 0xFFFC
    ctx->r14 = ctx->r8 & 0XFFFC;
    // 0x80800348: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x8080034C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80800350: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80800354: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80800358: addu        $t6, $t7, $at
    ctx->r14 = ADD32(ctx->r15, ctx->r1);
    // 0x8080035C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80800360: lw          $a0, 0xC8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC8);
    // 0x80800364: lui         $t1, 0xF510
    ctx->r9 = S32(0XF510 << 16);
    // 0x80800368: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x8080036C: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80800370: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80800374: ori         $t1, $t1, 0x1280
    ctx->r9 = ctx->r9 | 0X1280;
    // 0x80800378: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x8080037C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80800380: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80800384: lw          $a1, 0xC8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC8);
    // 0x80800388: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8080038C: lui         $at, 0xF200
    ctx->r1 = S32(0XF200 << 16);
    // 0x80800390: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x80800394: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80800398: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8080039C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x808003A0: lw          $a2, 0xC8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC8);
    // 0x808003A4: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x808003A8: lui         $t8, 0xF400
    ctx->r24 = S32(0XF400 << 16);
    // 0x808003AC: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x808003B0: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x808003B4: ori         $t9, $t9, 0xC07C
    ctx->r25 = ctx->r25 | 0XC07C;
    // 0x808003B8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x808003BC: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x808003C0: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    // 0x808003C4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x808003C8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x808003CC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x808003D0: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x808003D4: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x808003D8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x808003DC: lw          $v0, 0xC8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC8);
    // 0x808003E0: lui         $t6, 0x108
    ctx->r14 = S32(0X108 << 16);
    // 0x808003E4: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x808003E8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x808003EC: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x808003F0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x808003F4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x808003F8: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x808003FC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80800400: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80800404: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80800408: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x8080040C: bgez        $t0, L_80800420
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800410: andi        $t7, $t0, 0x3
        ctx->r15 = ctx->r8 & 0X3;
            goto L_80800420;
    }
    // 0x80800410: andi        $t7, $t0, 0x3
    ctx->r15 = ctx->r8 & 0X3;
    // 0x80800414: beq         $t7, $zero, L_80800420
    if (ctx->r15 == 0) {
        // 0x80800418: nop
    
            goto L_80800420;
    }
    // 0x80800418: nop

    // 0x8080041C: addiu       $t7, $t7, -0x4
    ctx->r15 = ADD32(ctx->r15, -0X4);
L_80800420:
    // 0x80800420: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    // 0x80800424: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x80800428: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8080042C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80800430: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80800434: addiu       $t8, $a0, 0x1F
    ctx->r24 = ADD32(ctx->r4, 0X1F);
    // 0x80800438: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8080043C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80800440: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80800444: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80800448: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8080044C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80800450: ori         $t9, $t8, 0x7C
    ctx->r25 = ctx->r24 | 0X7C;
    // 0x80800454: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80800458: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8080045C: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x80800460: ori         $t8, $t8, 0x8010
    ctx->r24 = ctx->r24 | 0X8010;
    // 0x80800464: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80800468: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x8080046C: sw          $s0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r16;
    // 0x80800470: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80800474: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x80800478: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8080047C: ori         $t7, $t7, 0x206
    ctx->r15 = ctx->r15 | 0X206;
    // 0x80800480: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x80800484: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x80800488: addiu       $t8, $zero, 0x604
    ctx->r24 = ADD32(0, 0X604);
    // 0x8080048C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80800490: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x80800494: sw          $t3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r11;
    // 0x80800498: addiu       $a0, $zero, 0x9CB
    ctx->r4 = ADD32(0, 0X9CB);
    // 0x8080049C: jal         0x800D674C
    // 0x808004A0: sw          $t2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r10;
    func_800D674C(rdram, ctx);
        goto after_11;
    // 0x808004A0: sw          $t2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r10;
    after_11:
    // 0x808004A4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808004A8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808004AC: addiu       $t7, $sp, 0xD0
    ctx->r15 = ADD32(ctx->r29, 0XD0);
    // 0x808004B0: addiu       $t8, $sp, 0xCC
    ctx->r24 = ADD32(ctx->r29, 0XCC);
    // 0x808004B4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x808004B8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x808004BC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x808004C0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808004C4: addiu       $a0, $sp, 0xC8
    ctx->r4 = ADD32(ctx->r29, 0XC8);
    // 0x808004C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808004CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808004D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808004D4: jal         0x800AF614
    // 0x808004D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800AF614(rdram, ctx);
        goto after_12;
    // 0x808004D8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_12:
    // 0x808004DC: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x808004E0: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
    // 0x808004E4: lw          $t3, 0xDC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XDC);
    // 0x808004E8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x808004EC: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x808004F0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x808004F4: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x808004F8: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x808004FC: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x80800500: lui         $t7, 0x3FFD
    ctx->r15 = S32(0X3FFD << 16);
    // 0x80800504: lui         $t6, 0xFC10
    ctx->r14 = S32(0XFC10 << 16);
    // 0x80800508: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8080050C: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80800510: ori         $t6, $t6, 0x9804
    ctx->r14 = ctx->r14 | 0X9804;
    // 0x80800514: ori         $t7, $t7, 0xFFF8
    ctx->r15 = ctx->r15 | 0XFFF8;
    // 0x80800518: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8080051C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80800520: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x80800524: lui         $t7, 0x50F0
    ctx->r15 = S32(0X50F0 << 16);
    // 0x80800528: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8080052C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80800530: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80800534: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80800538: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8080053C: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80800540: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x80800544: lui         $t7, 0xC
    ctx->r15 = S32(0XC << 16);
    // 0x80800548: lui         $t6, 0x60E
    ctx->r14 = S32(0X60E << 16);
    // 0x8080054C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80800550: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80800554: ori         $t6, $t6, 0x80A
    ctx->r14 = ctx->r14 | 0X80A;
    // 0x80800558: ori         $t7, $t7, 0x80E
    ctx->r15 = ctx->r15 | 0X80E;
    // 0x8080055C: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80800560: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80800564: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x80800568: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8080056C: lui         $t1, 0xB4F0
    ctx->r9 = S32(0XB4F0 << 16);
    // 0x80800570: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80800574: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80800578: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x8080057C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80800580: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x80800584: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80800588: ori         $t9, $t9, 0x1001
    ctx->r25 = ctx->r25 | 0X1001;
    // 0x8080058C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80800590: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80800594: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80800598: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8080059C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x808005A0: lui         $t8, 0xD838
    ctx->r24 = S32(0XD838 << 16);
    // 0x808005A4: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x808005A8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x808005AC: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x808005B0: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x808005B4: ori         $t1, $t1, 0xFFA0
    ctx->r9 = ctx->r9 | 0XFFA0;
    // 0x808005B8: sra         $ra, $s1, 1
    ctx->r31 = S32(SIGNED(ctx->r17) >> 1);
    // 0x808005BC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x808005C0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x808005C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x808005C8: sra         $a3, $t2, 1
    ctx->r7 = S32(SIGNED(ctx->r10) >> 1);
    // 0x808005CC: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x808005D0: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
L_808005D4:
    // 0x808005D4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x808005D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808005DC: subu        $a0, $ra, $t4
    ctx->r4 = SUB32(ctx->r31, ctx->r12);
    // 0x808005E0: addiu       $v1, $zero, 0x1F
    ctx->r3 = ADD32(0, 0X1F);
    // 0x808005E4: sll         $a1, $t5, 6
    ctx->r5 = S32(ctx->r13 << 6);
L_808005E8:
    // 0x808005E8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x808005EC: subu        $t6, $a3, $v0
    ctx->r14 = SUB32(ctx->r7, ctx->r2);
    // 0x808005F0: sll         $t7, $v1, 6
    ctx->r15 = S32(ctx->r3 << 6);
    // 0x808005F4: addiu       $v1, $v1, -0x1F
    ctx->r3 = ADD32(ctx->r3, -0X1F);
    // 0x808005F8: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x808005FC: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x80800600: sh          $a0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r4;
    // 0x80800604: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80800608: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x8080060C: sh          $a1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r5;
    // 0x80800610: sw          $t1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r9;
    // 0x80800614: bne         $t0, $a2, L_808005E8
    if (ctx->r8 != ctx->r6) {
        // 0x80800618: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_808005E8;
    }
    // 0x80800618: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8080061C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80800620: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80800624: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x80800628: bne         $at, $zero, L_808005D4
    if (ctx->r1 != 0) {
        // 0x8080062C: addiu       $t5, $t5, 0x1F
        ctx->r13 = ADD32(ctx->r13, 0X1F);
            goto L_808005D4;
    }
    // 0x8080062C: addiu       $t5, $t5, 0x1F
    ctx->r13 = ADD32(ctx->r13, 0X1F);
    // 0x80800630: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80800634: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80800638: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8080063C:
    // 0x8080063C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80800640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800644: subu        $a0, $ra, $t4
    ctx->r4 = SUB32(ctx->r31, ctx->r12);
L_80800648:
    // 0x80800648: subu        $t8, $a3, $v0
    ctx->r24 = SUB32(ctx->r7, ctx->r2);
    // 0x8080064C: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x80800650: sh          $a0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r4;
    // 0x80800654: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80800658: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x8080065C: xori        $t9, $t0, 0x1
    ctx->r25 = ctx->r8 ^ 0X1;
    // 0x80800660: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80800664: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800668: multu       $t9, $t7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8080066C: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80800670: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80800674: mflo        $t8
    ctx->r24 = lo;
    // 0x80800678: sll         $t6, $t8, 6
    ctx->r14 = S32(ctx->r24 << 6);
    // 0x8080067C: sh          $t6, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r14;
    // 0x80800680: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x80800684: sw          $v1, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r3;
    // 0x80800688: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x8080068C: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800690: mflo        $t8
    ctx->r24 = lo;
    // 0x80800694: sll         $t6, $t8, 6
    ctx->r14 = S32(ctx->r24 << 6);
    // 0x80800698: bne         $t0, $a2, L_80800648
    if (ctx->r8 != ctx->r6) {
        // 0x8080069C: sh          $t6, -0x6($s0)
        MEM_H(-0X6, ctx->r16) = ctx->r14;
            goto L_80800648;
    }
    // 0x8080069C: sh          $t6, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r14;
    // 0x808006A0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x808006A4: bne         $t3, $a2, L_8080063C
    if (ctx->r11 != ctx->r6) {
        // 0x808006A8: addu        $t4, $t4, $s1
        ctx->r12 = ADD32(ctx->r12, ctx->r17);
            goto L_8080063C;
    }
    // 0x808006A8: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x808006AC: lw          $t7, 0x108($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X108);
    // 0x808006B0: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x808006B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808006B8: sw          $s0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r16;
    // 0x808006BC: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
L_808006C0:
    // 0x808006C0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x808006C4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x808006C8: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x808006CC: jr          $ra
    // 0x808006D0: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x808006D0: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    // 0x808006D4: nop

    // 0x808006D8: nop

    // 0x808006DC: nop

;}
RECOMP_FUNC void fxkern_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003D0: jal         0x800B8C50
    // 0x808003D4: nop

    func_800B8C50(rdram, ctx);
        goto after_0;
    // 0x808003D4: nop

    after_0:
    // 0x808003D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808003DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003E4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2854, 0X480) << 16);
    // 0x808003E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003EC: jr          $ra
    // 0x808003F0: swc1        $f4, 0x480($at)
    MEM_W((int16_t)RELOC_LO16(2854, 0X480), ctx->r1) = ctx->f4.u32l;
    return;
    // 0x808003F0: swc1        $f4, 0x480($at)
    MEM_W((int16_t)RELOC_LO16(2854, 0X480), ctx->r1) = ctx->f4.u32l;
;}
RECOMP_FUNC void chwaspstatue_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800538: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2364, 0X740) << 16);
    // 0x8080053C: jr          $ra
    // 0x80800540: addiu       $v0, $v0, 0x740
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2364, 0X740));
    return;
    // 0x80800540: addiu       $v0, $v0, 0x740
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2364, 0X740));
;}
RECOMP_FUNC void func_80803224_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803224: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80803228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080322C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80803230: jal         0x801039E4
    // 0x80803234: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_801039E4(rdram, ctx);
        goto after_0;
    // 0x80803234: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x80803238: jal         0x800B27E0
    // 0x8080323C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B27E0(rdram, ctx);
        goto after_1;
    // 0x8080323C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80803240: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80803244: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80803248: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8080324C: jal         0x800AE080
    // 0x80803250: lh          $a0, 0x10($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X10);
    func_800AE080(rdram, ctx);
        goto after_2;
    // 0x80803250: lh          $a0, 0x10($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X10);
    after_2:
    // 0x80803254: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80803258: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080325C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80803260: addiu       $a2, $zero, 0x2A
    ctx->r6 = ADD32(0, 0X2A);
    // 0x80803264: jal         0x800AE630
    // 0x80803268: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_800AE630(rdram, ctx);
        goto after_3;
    // 0x80803268: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x8080326C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80803270: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80803274: addiu       $a2, $zero, 0x2B
    ctx->r6 = ADD32(0, 0X2B);
    // 0x80803278: jal         0x800AE630
    // 0x8080327C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    func_800AE630(rdram, ctx);
        goto after_4;
    // 0x8080327C: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80803280: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80803284: jal         0x800F1828
    // 0x80803288: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F1828(rdram, ctx);
        goto after_5;
    // 0x80803288: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x8080328C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803290: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80803294: jr          $ra
    // 0x80803298: nop

    return;
    // 0x80803298: nop

;}
RECOMP_FUNC void func_808003D0_gcgoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x808003D4: lbu         $t6, 0x75C0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X75C0);
    // 0x808003D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003E0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808003E4: bne         $t6, $zero, L_80800434
    if (ctx->r14 != 0) {
        // 0x808003E8: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80800434;
    }
    // 0x808003E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808003EC: beq         $a0, $zero, L_80800420
    if (ctx->r4 == 0) {
        // 0x808003F0: lw          $t7, 0x34($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X34);
            goto L_80800420;
    }
    // 0x808003F0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808003F4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x808003F8: jal         0x800EE88C
    // 0x808003FC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE88C(rdram, ctx);
        goto after_0;
    // 0x808003FC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800400: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80800404: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800408: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8080040C: sra         $a1, $v0, 8
    ctx->r5 = S32(SIGNED(ctx->r2) >> 8);
    // 0x80800410: jal         0x808001E0
    // 0x80800414: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    func_808001E0_gcgoto(rdram, ctx);
        goto after_1;
    // 0x80800414: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_1:
    // 0x80800418: b           L_80800438
    // 0x8080041C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800438;
    // 0x8080041C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800420:
    // 0x80800420: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800424: sra         $a1, $t7, 8
    ctx->r5 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80800428: andi        $a2, $t7, 0xFF
    ctx->r6 = ctx->r15 & 0XFF;
    // 0x8080042C: jal         0x808001E0
    // 0x80800430: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_808001E0_gcgoto(rdram, ctx);
        goto after_2;
    // 0x80800430: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
L_80800434:
    // 0x80800434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800438:
    // 0x80800438: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080043C: jr          $ra
    // 0x80800440: nop

    return;
    // 0x80800440: nop

;}
RECOMP_FUNC void func_8080006C_chcaveofhorrorsdoors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800074: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800078: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080007C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800080: beq         $a1, $at, L_8080009C
    if (ctx->r5 == ctx->r1) {
        // 0x80800084: sw          $a2, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r6;
            goto L_8080009C;
    }
    // 0x80800084: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800088: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8080008C: beq         $a1, $at, L_80800114
    if (ctx->r5 == ctx->r1) {
        // 0x80800090: nop
    
            goto L_80800114;
    }
    // 0x80800090: nop

    // 0x80800094: b           L_80800130
    // 0x80800098: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800130;
    // 0x80800098: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080009C:
    // 0x8080009C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808000A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808000A4: jal         0x800EE7F8
    // 0x808000A8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808000A8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x808000AC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808000B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000B4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808000B8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808000BC: lui         $a2, 0xC2A0
    ctx->r6 = S32(0XC2A0 << 16);
    // 0x808000C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808000C4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x808000C8: jal         0x800EF1B8
    // 0x808000CC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808000CC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    after_1:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808000D8: jal         0x80086670
    // 0x808000DC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    _chexploder_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808000DC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_2:
    // 0x808000E0: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x808000E4: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808000E8: slti        $at, $t7, 0x34
    ctx->r1 = SIGNED(ctx->r15) < 0X34 ? 1 : 0;
    // 0x808000EC: beql        $at, $zero, L_80800130
    if (ctx->r1 == 0) {
        // 0x808000F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800130;
    }
    goto skip_0;
    // 0x808000F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808000F4: jal         0x800F54E4
    // 0x808000F8: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x808000F8: nop

    after_3:
    // 0x808000FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800104: jal         0x800F8300
    // 0x80800108: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    func_800F8300(rdram, ctx);
        goto after_4;
    // 0x80800108: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x8080010C: b           L_80800130
    // 0x80800110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800130;
    // 0x80800110: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800114:
    // 0x80800114: jal         0x80800144
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800144_chcaveofhorrorsdoors(rdram, ctx);
        goto after_5;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080011C: b           L_80800130
    // 0x80800120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800130;
    // 0x80800120: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800124: b           L_80800130
    // 0x80800128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800130;
    // 0x80800128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080012C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800130:
    // 0x80800130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800134: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800138: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void func_808006C4_chboggyboy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808006C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006D0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808006D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808006DC: jal         0x80100094
    // 0x808006E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808006E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808006E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808006E8: addiu       $at, $zero, 0x108A
    ctx->r1 = ADD32(0, 0X108A);
    // 0x808006EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808006F0: beq         $a1, $at, L_80800710
    if (ctx->r5 == ctx->r1) {
        // 0x808006F4: addiu       $at, $zero, 0x1098
        ctx->r1 = ADD32(0, 0X1098);
            goto L_80800710;
    }
    // 0x808006F4: addiu       $at, $zero, 0x1098
    ctx->r1 = ADD32(0, 0X1098);
    // 0x808006F8: beq         $a1, $at, L_80800750
    if (ctx->r5 == ctx->r1) {
        // 0x808006FC: addiu       $at, $zero, 0x1099
        ctx->r1 = ADD32(0, 0X1099);
            goto L_80800750;
    }
    // 0x808006FC: addiu       $at, $zero, 0x1099
    ctx->r1 = ADD32(0, 0X1099);
    // 0x80800700: beq         $a1, $at, L_80800750
    if (ctx->r5 == ctx->r1) {
        // 0x80800704: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800750;
    }
    // 0x80800704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800708: b           L_80800760
    // 0x8080070C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1532, 0XC00) << 16);
        goto L_80800760;
    // 0x8080070C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1532, 0XC00) << 16);
L_80800710:
    // 0x80800710: jal         0x800DA544
    // 0x80800714: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800714: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_1:
    // 0x80800718: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x8080071C: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x80800720: jal         0x80101180
    // 0x80800724: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x80800724: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080072C: jal         0x80102424
    // 0x80800730: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x80800730: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_3:
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800738: jal         0x8008A4B0
    // 0x8080073C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x8080073C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800740: jal         0x808009F4
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808009F4_chboggyboy(rdram, ctx);
        goto after_5;
    // 0x80800744: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800748: b           L_808007E4
    // 0x8080074C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808007E4;
    // 0x8080074C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800750:
    // 0x80800750: lbu         $t6, 0x16($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X16);
    // 0x80800754: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x80800758: b           L_808007E0
    // 0x8080075C: sb          $t7, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r15;
        goto L_808007E0;
    // 0x8080075C: sb          $t7, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r15;
L_80800760:
    // 0x80800760: addiu       $a2, $a2, 0xC00
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1532, 0XC00));
    // 0x80800764: jal         0x8008A1F8
    // 0x80800768: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x80800768: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x8080076C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800770: beq         $v0, $at, L_80800788
    if (ctx->r2 == ctx->r1) {
        // 0x80800774: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800788;
    }
    // 0x80800774: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800778: beq         $v0, $at, L_808007A0
    if (ctx->r2 == ctx->r1) {
        // 0x8080077C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808007A0;
    }
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800780: b           L_808007D8
    // 0x80800784: nop

        goto L_808007D8;
    // 0x80800784: nop

L_80800788:
    // 0x80800788: jal         0x8010A590
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_7;
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800790: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80800794: lbu         $t0, 0x16($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X16);
    // 0x80800798: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x8080079C: sb          $t1, 0x16($t8)
    MEM_B(0X16, ctx->r24) = ctx->r9;
L_808007A0:
    // 0x808007A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808007A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007A8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808007B4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808007B8: jal         0x80102924
    // 0x808007BC: nop

    func_80102924(rdram, ctx);
        goto after_8;
    // 0x808007BC: nop

    after_8:
    // 0x808007C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007C4: jal         0x80102424
    // 0x808007C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x808007C8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x808007CC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x808007D0: b           L_808007E0
    // 0x808007D4: sh          $zero, 0x14($t2)
    MEM_H(0X14, ctx->r10) = 0;
        goto L_808007E0;
    // 0x808007D4: sh          $zero, 0x14($t2)
    MEM_H(0X14, ctx->r10) = 0;
L_808007D8:
    // 0x808007D8: jal         0x80102424
    // 0x808007DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x808007DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
L_808007E0:
    // 0x808007E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007E4:
    // 0x808007E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808007EC: jr          $ra
    // 0x808007F0: nop

    return;
    // 0x808007F0: nop

;}
RECOMP_FUNC void func_800EDD68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDD68: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EDD6C: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800EDD70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EDD74: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    // 0x800EDD78: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EDD7C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800EDD80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800EDD84: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x800EDD88: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800EDD8C: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
    // 0x800EDD90: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800EDD94: swc1        $f10, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f10.u32l;
    // 0x800EDD98: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EDD9C: swc1        $f16, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f16.u32l;
    // 0x800EDDA0: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EDDA4: swc1        $f18, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->f18.u32l;
    // 0x800EDDA8: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EDDAC: swc1        $f4, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->f4.u32l;
    // 0x800EDDB0: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800EDDB4: sb          $zero, 0x28($a0)
    MEM_B(0X28, ctx->r4) = 0;
    // 0x800EDDB8: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x800EDDBC: bc1f        L_800EDDCC
    if (!c1cs) {
        // 0x800EDDC0: swc1        $f6, 0x6C($a0)
        MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
            goto L_800EDDCC;
    }
    // 0x800EDDC0: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x800EDDC4: jr          $ra
    // 0x800EDDC8: swc1        $f12, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x800EDDC8: swc1        $f12, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f12.u32l;
L_800EDDCC:
    // 0x800EDDCC: lwc1        $f8, 0x5E64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5E64);
    // 0x800EDDD0: swc1        $f8, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f8.u32l;
    // 0x800EDDD4: jr          $ra
    // 0x800EDDD8: nop

    return;
    // 0x800EDDD8: nop

;}
RECOMP_FUNC void _bsbswim_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B70: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082B70);
    return;
    // 0x80082B74: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _vpwibble_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089020: syscall     756
    recomp_syscall_handler(rdram, ctx, 0x80089020);
    return;
    // 0x80089024: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bahold_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800080: jr          $ra
    // 0x80800084: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800084: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8008E124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E12C: jal         0x8009CC68
    // 0x8008E130: nop

    func_8009CC68(rdram, ctx);
        goto after_0;
    // 0x8008E130: nop

    after_0:
    // 0x8008E134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E138: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x8008E13C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8008E140: jr          $ra
    // 0x8008E144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008E144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_808012CC_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808012D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808012DC: lbu         $t7, 0x1B($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1B);
    // 0x808012E0: beql        $t7, $zero, L_80801324
    if (ctx->r15 == 0) {
        // 0x808012E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801324;
    }
    goto skip_0;
    // 0x808012E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808012E8: jal         0x80088B20
    // 0x808012EC: nop

    _fxkern_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808012EC: nop

    after_0:
    // 0x808012F0: jal         0x800B8CE0
    // 0x808012F4: addiu       $a0, $zero, 0xC28
    ctx->r4 = ADD32(0, 0XC28);
    func_800B8CE0(rdram, ctx);
        goto after_1;
    // 0x808012F4: addiu       $a0, $zero, 0xC28
    ctx->r4 = ADD32(0, 0XC28);
    after_1:
    // 0x808012F8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x808012FC: lw          $a0, 0x14($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X14);
    // 0x80801300: jal         0x80088720
    // 0x80801304: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    _gldbstring_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80801304: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    after_2:
    // 0x80801308: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8080130C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80801310: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80801314: lh          $a1, 0x18($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X18);
    // 0x80801318: jal         0x80088B18
    // 0x8080131C: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    _fxkern_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080131C: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_3:
    // 0x80801320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801324:
    // 0x80801324: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801328: jr          $ra
    // 0x8080132C: nop

    return;
    // 0x8080132C: nop

;}
RECOMP_FUNC void func_800F4FC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F4FC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F4FCC: jal         0x800878A0
    // 0x800F4FD0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    _plsu_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800F4FD0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_0:
    // 0x800F4FD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F4FD8: beq         $v0, $at, L_800F4FE8
    if (ctx->r2 == ctx->r1) {
        // 0x800F4FDC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800F4FE8;
    }
    // 0x800F4FDC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800F4FE0: jal         0x800F7B9C
    // 0x800F4FE4: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    func_800F7B9C(rdram, ctx);
        goto after_1;
    // 0x800F4FE4: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_1:
L_800F4FE8:
    // 0x800F4FE8: addiu       $a0, $zero, 0x15E
    ctx->r4 = ADD32(0, 0X15E);
    // 0x800F4FEC: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x800F4FF0: jal         0x80101180
    // 0x800F4FF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_2;
    // 0x800F4FF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800F4FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F4FFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5000: jr          $ra
    // 0x800F5004: nop

    return;
    // 0x800F5004: nop

;}
RECOMP_FUNC void _chtemplelobbydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087370: syscall     556
    recomp_syscall_handler(rdram, ctx, 0x80087370);
    return;
    // 0x80087374: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void bamum_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001C4: jr          $ra
    // 0x808001C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x808001C8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_808006AC_chfloaty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808006B0: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x808006B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808006B8: sltiu       $at, $t7, 0x6
    ctx->r1 = ctx->r15 < 0X6 ? 1 : 0;
    // 0x808006BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808006C4: beq         $at, $zero, L_808008EC
    if (ctx->r1 == 0) {
        // 0x808006C8: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_808008EC;
    }
    // 0x808006C8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808006CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808006D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2416, 0XDD8) << 16);
    // 0x808006D4: addu        $at, $at, $t7
    gpr jr_addend_808006DC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808006D8: lw          $t7, 0xDD8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2416, 0XDD8));
    // 0x808006DC: jr          $t7
    // 0x808006E0: nop

    switch (jr_addend_808006DC >> 2) {
        case 0: goto L_808006E4; break;
        case 1: goto L_8080071C; break;
        case 2: goto L_80800778; break;
        case 3: goto L_808007E4; break;
        case 4: goto L_80800840; break;
        case 5: goto L_8080086C; break;
        default: switch_error(__func__, 0x808006DC, 0x80800DD8);
    }
    // 0x808006E0: nop

L_808006E4:
    // 0x808006E4: jal         0x8010A63C
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_0;
    // 0x808006E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808006EC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x808006F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F4: addiu       $a1, $zero, 0x923
    ctx->r5 = ADD32(0, 0X923);
    // 0x808006F8: jal         0x80103140
    // 0x808006FC: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    func_80103140(rdram, ctx);
        goto after_1;
    // 0x808006FC: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    after_1:
    // 0x80800700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800704: jal         0x80102FDC
    // 0x80800708: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x80800708: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_2:
    // 0x8080070C: jal         0x8010A63C
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A63C(rdram, ctx);
        goto after_3;
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800714: b           L_808008F0
    // 0x80800718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008F0;
    // 0x80800718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080071C:
    // 0x8080071C: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800720: srl         $t9, $a0, 7
    ctx->r25 = S32(U32(ctx->r4) >> 7);
    // 0x80800724: jal         0x800DA544
    // 0x80800728: addiu       $a0, $t9, 0x320
    ctx->r4 = ADD32(ctx->r25, 0X320);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x80800728: addiu       $a0, $t9, 0x320
    ctx->r4 = ADD32(ctx->r25, 0X320);
    after_4:
    // 0x8080072C: jal         0x8010A624
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_5;
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800734: jal         0x8010A570
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x80800738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080073C: jal         0x800F54E4
    // 0x80800740: nop

    func_800F54E4(rdram, ctx);
        goto after_7;
    // 0x80800740: nop

    after_7:
    // 0x80800744: lhu         $t0, 0x76($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X76);
    // 0x80800748: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2416, 0XE84) << 16);
    // 0x8080074C: addiu       $t4, $t4, 0xE84
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2416, 0XE84));
    // 0x80800750: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x80800754: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80800758: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8080075C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80800760: addiu       $t3, $t2, -0x258
    ctx->r11 = ADD32(ctx->r10, -0X258);
    // 0x80800764: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x80800768: jal         0x800F77E8
    // 0x8080076C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F77E8(rdram, ctx);
        goto after_8;
    // 0x8080076C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800770: b           L_808008F0
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008F0;
    // 0x80800774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800778:
    // 0x80800778: jal         0x80104580
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104580(rdram, ctx);
        goto after_9;
    // 0x8080077C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800780: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80800784: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800788: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8080078C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800790: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x80800794: addiu       $a1, $zero, 0x924
    ctx->r5 = ADD32(0, 0X924);
    // 0x80800798: jal         0x80103140
    // 0x8080079C: lhu         $a2, 0x16($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X16);
    func_80103140(rdram, ctx);
        goto after_10;
    // 0x8080079C: lhu         $a2, 0x16($t5)
    ctx->r6 = MEM_HU(ctx->r13, 0X16);
    after_10:
    // 0x808007A0: jal         0x8010CD28
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_11;
    // 0x808007A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808007A8: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x808007AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B0: jal         0x80800BD8
    // 0x808007B4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80800BD8_chfloaty(rdram, ctx);
        goto after_12;
    // 0x808007B4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_12:
    // 0x808007B8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808007BC: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808007C0: lui         $a2, 0xC47A
    ctx->r6 = S32(0XC47A << 16);
    // 0x808007C4: jal         0x800C6920
    // 0x808007C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6920(rdram, ctx);
        goto after_13;
    // 0x808007C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x808007CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808007D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808007D4: nop

    // 0x808007D8: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x808007DC: b           L_808008EC
    // 0x808007E0: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_808008EC;
    // 0x808007E0: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_808007E4:
    // 0x808007E4: jal         0x80104580
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104580(rdram, ctx);
        goto after_14;
    // 0x808007E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x808007EC: jal         0x8010A624
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_15;
    // 0x808007F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808007F4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x808007F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007FC: addiu       $a1, $zero, 0x924
    ctx->r5 = ADD32(0, 0X924);
    // 0x80800800: jal         0x80103140
    // 0x80800804: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    func_80103140(rdram, ctx);
        goto after_16;
    // 0x80800804: lhu         $a2, 0x16($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X16);
    after_16:
    // 0x80800808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080080C: jal         0x80102FDC
    // 0x80800810: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80102FDC(rdram, ctx);
        goto after_17;
    // 0x80800810: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_17:
    // 0x80800814: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800818: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x8080081C: lui         $a2, 0xC47A
    ctx->r6 = S32(0XC47A << 16);
    // 0x80800820: jal         0x800C6920
    // 0x80800824: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6920(rdram, ctx);
        goto after_18;
    // 0x80800824: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x80800828: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080082C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800830: nop

    // 0x80800834: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80800838: b           L_808008EC
    // 0x8080083C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_808008EC;
    // 0x8080083C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_80800840:
    // 0x80800840: jal         0x800F54E4
    // 0x80800844: nop

    func_800F54E4(rdram, ctx);
        goto after_19;
    // 0x80800844: nop

    after_19:
    // 0x80800848: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8080084C: jal         0x80800B68
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B68_chfloaty(rdram, ctx);
        goto after_20;
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800854: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800858: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8080085C: jal         0x800F7C0C
    // 0x80800860: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    func_800F7C0C(rdram, ctx);
        goto after_21;
    // 0x80800860: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
    after_21:
    // 0x80800864: b           L_808008F0
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808008F0;
    // 0x80800868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080086C:
    // 0x8080086C: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x80800870: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800874: srl         $t7, $a0, 7
    ctx->r15 = S32(U32(ctx->r4) >> 7);
    // 0x80800878: jal         0x800CB698
    // 0x8080087C: addiu       $a0, $t7, -0x25
    ctx->r4 = ADD32(ctx->r15, -0X25);
    func_800CB698(rdram, ctx);
        goto after_22;
    // 0x8080087C: addiu       $a0, $t7, -0x25
    ctx->r4 = ADD32(ctx->r15, -0X25);
    after_22:
    // 0x80800880: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800884: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80800888: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080088C: jal         0x800EEB9C
    // 0x80800890: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    func_800EEB9C(rdram, ctx);
        goto after_23;
    // 0x80800890: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_23:
    // 0x80800894: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800898: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080089C: jal         0x800EF04C
    // 0x808008A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800EF04C(rdram, ctx);
        goto after_24;
    // 0x808008A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_24:
    // 0x808008A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808008A8: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808008AC: lui         $a2, 0xC47A
    ctx->r6 = S32(0XC47A << 16);
    // 0x808008B0: jal         0x800C6920
    // 0x808008B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C6920(rdram, ctx);
        goto after_25;
    // 0x808008B4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_25:
    // 0x808008B8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808008BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808008C0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808008C4: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x808008C8: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x808008CC: jal         0x800EE7F8
    // 0x808008D0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_26;
    // 0x808008D0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_26:
    // 0x808008D4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x808008D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808008DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808008E4: jal         0x8008A4B0
    // 0x808008E8: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x808008E8: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    after_27:
L_808008EC:
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808008F0:
    // 0x808008F0: jal         0x80102424
    // 0x808008F4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80102424(rdram, ctx);
        goto after_28;
    // 0x808008F4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_28:
    // 0x808008F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808008FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800900: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800904: jr          $ra
    // 0x80800908: nop

    return;
    // 0x80800908: nop

;}
RECOMP_FUNC void func_800C4208(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4208: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C420C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C4210: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C4214: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C4218: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C421C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C4220: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800C4224: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800C4228: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C422C: jal         0x800C401C
    // 0x800C4230: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_800C401C(rdram, ctx);
        goto after_0;
    // 0x800C4230: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800C4234: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C4238: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C423C: jr          $ra
    // 0x800C4240: nop

    return;
    // 0x800C4240: nop

;}
RECOMP_FUNC void _bsbwhirl_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E18: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E18);
    return;
    // 0x80082E1C: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void _bsbanswim_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082768: syscall     10
    recomp_syscall_handler(rdram, ctx, 0x80082768);
    return;
    // 0x8008276C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800274_gsattract(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80800278: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8080027C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80800280: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80800284: addiu       $v0, $v0, 0x5470
    ctx->r2 = ADD32(ctx->r2, 0X5470);
    // 0x80800288: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8080028C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2882, 0X493) << 16);
    // 0x80800290: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x80800294: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80800298: lbu         $t8, 0x493($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(2882, 0X493));
    // 0x8080029C: jr          $ra
    // 0x808002A0: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    return;
    // 0x808002A0: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void func_808009CC_chburgerstand(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808009D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808009D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808009D8: jal         0x800EA05C
    // 0x808009DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808009DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808009E0: addiu       $at, $zero, 0x124
    ctx->r1 = ADD32(0, 0X124);
    // 0x808009E4: bnel        $v0, $at, L_808009F8
    if (ctx->r2 != ctx->r1) {
        // 0x808009E8: lui         $at, 0x4361
        ctx->r1 = S32(0X4361 << 16);
            goto L_808009F8;
    }
    goto skip_0;
    // 0x808009E8: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    skip_0:
    // 0x808009EC: jal         0x8010A624
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A624(rdram, ctx);
        goto after_1;
    // 0x808009F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808009F4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
L_808009F8:
    // 0x808009F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808009FC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800A00: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800A04: jal         0x80088848
    // 0x80800A08: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_2;
    // 0x80800A08: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x80800A0C: beq         $v0, $zero, L_80800A2C
    if (ctx->r2 == 0) {
        // 0x80800A10: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A2C;
    }
    // 0x80800A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800A18: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800A1C: jal         0x80101FDC
    // 0x80800A20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800A20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x80800A24: b           L_80800A30
    // 0x80800A28: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_80800A30;
    // 0x80800A28: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80800A2C:
    // 0x80800A2C: addiu       $v0, $zero, 0x9F
    ctx->r2 = ADD32(0, 0X9F);
L_80800A30:
    // 0x80800A30: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80800A34: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A3C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80800A40: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80800A44: lui         $a3, 0x4361
    ctx->r7 = S32(0X4361 << 16);
    // 0x80800A48: jal         0x80086898
    // 0x80800A4C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x80800A4C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800A50: beq         $v0, $zero, L_80800A78
    if (ctx->r2 == 0) {
        // 0x80800A54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800A78;
    }
    // 0x80800A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A58: jal         0x800868A8
    // 0x80800A5C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_5;
    // 0x80800A5C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_5:
    // 0x80800A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A64: jal         0x800868A8
    // 0x80800A68: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_6;
    // 0x80800A68: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_6:
    // 0x80800A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A70: jal         0x800868C0
    // 0x80800A74: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_7;
    // 0x80800A74: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
L_80800A78:
    // 0x80800A78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800A7C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A80: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800A84: jr          $ra
    // 0x80800A88: nop

    return;
    // 0x80800A88: nop

;}
RECOMP_FUNC void badeathmatch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080003C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800044: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800048: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080004C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800050: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800054: lw          $s2, 0x158($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X158);
    // 0x80800058: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8080005C: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
    // 0x80800060: lbu         $s1, 0x20($s2)
    ctx->r17 = MEM_BU(ctx->r18, 0X20);
L_80800064:
    // 0x80800064: jal         0x80800028
    // 0x80800068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800028_badeathmatch(rdram, ctx);
        goto after_0;
    // 0x80800068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8080006C: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80800070: addu        $v1, $s2, $t7
    ctx->r3 = ADD32(ctx->r18, ctx->r15);
    // 0x80800074: lh          $t8, 0x10($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X10);
    // 0x80800078: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080007C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800080: bnel        $t8, $zero, L_80800094
    if (ctx->r24 != 0) {
        // 0x80800084: lh          $t9, 0x0($v1)
        ctx->r25 = MEM_H(ctx->r3, 0X0);
            goto L_80800094;
    }
    goto skip_0;
    // 0x80800084: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    skip_0:
    // 0x80800088: bne         $s0, $s3, L_80800064
    if (ctx->r16 != ctx->r19) {
        // 0x8080008C: nop
    
            goto L_80800064;
    }
    // 0x8080008C: nop

    // 0x80800090: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
L_80800094:
    // 0x80800094: bnel        $t9, $zero, L_808000C0
    if (ctx->r25 != 0) {
        // 0x80800098: lw          $t3, 0x28($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X28);
            goto L_808000C0;
    }
    goto skip_1;
    // 0x80800098: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    skip_1:
L_8080009C:
    // 0x8080009C: jal         0x80800028
    // 0x808000A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80800028_badeathmatch(rdram, ctx);
        goto after_1;
    // 0x808000A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808000A4: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
    // 0x808000A8: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x808000AC: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x808000B0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808000B4: beq         $t2, $zero, L_8080009C
    if (ctx->r10 == 0) {
        // 0x808000B8: nop
    
            goto L_8080009C;
    }
    // 0x808000B8: nop

    // 0x808000BC: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_808000C0:
    // 0x808000C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808000C4: lw          $t4, 0x158($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X158);
    // 0x808000C8: jal         0x800883C8
    // 0x808000CC: sb          $s1, 0x20($t4)
    MEM_B(0X20, ctx->r12) = ctx->r17;
    _gcegg_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808000CC: sb          $s1, 0x20($t4)
    MEM_B(0X20, ctx->r12) = ctx->r17;
    after_2:
    // 0x808000D0: jal         0x800FC6B0
    // 0x808000D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800FC6B0(rdram, ctx);
        goto after_3;
    // 0x808000D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808000D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000DC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x808000E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000E8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808000EC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808000F0: jr          $ra
    // 0x808000F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800790_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800794: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800798: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080079C: jal         0x80095738
    // 0x808007A0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_0;
    // 0x808007A0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x808007A4: beq         $v0, $zero, L_808007BC
    if (ctx->r2 == 0) {
        // 0x808007A8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808007BC;
    }
    // 0x808007A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808007AC: jal         0x8009B7C0
    // 0x808007B0: nop

    func_8009B7C0(rdram, ctx);
        goto after_1;
    // 0x808007B0: nop

    after_1:
    // 0x808007B4: b           L_808007C8
    // 0x808007B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808007C8;
    // 0x808007B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007BC:
    // 0x808007BC: jal         0x80800BEC
    // 0x808007C0: nop

    func_80800BEC_bsstatue(rdram, ctx);
        goto after_2;
    // 0x808007C0: nop

    after_2:
    // 0x808007C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007C8:
    // 0x808007C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007CC: jr          $ra
    // 0x808007D0: nop

    return;
    // 0x808007D0: nop

;}
RECOMP_FUNC void func_800B38C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B38C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B38CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B38D0: jal         0x800C87B8
    // 0x800B38D4: nop

    func_800C87B8(rdram, ctx);
        goto after_0;
    // 0x800B38D4: nop

    after_0:
    // 0x800B38D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B38DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B38E0: jr          $ra
    // 0x800B38E4: nop

    return;
    // 0x800B38E4: nop

;}
RECOMP_FUNC void func_800F9F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9F04: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F9F08: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F9F0C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x800F9F10: jr          $ra
    // 0x800F9F14: lh          $v0, 0x5530($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5530);
    return;
    // 0x800F9F14: lh          $v0, 0x5530($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X5530);
;}
RECOMP_FUNC void func_80090818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009081C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090820: jal         0x800F54E4
    // 0x80090824: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80090824: nop

    after_0:
    // 0x80090828: jal         0x800F87A4
    // 0x8009082C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F87A4(rdram, ctx);
        goto after_1;
    // 0x8009082C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80090830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090838: jr          $ra
    // 0x8009083C: nop

    return;
    // 0x8009083C: nop

;}
RECOMP_FUNC void func_80802D04_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D04: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80802D08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80802D0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80802D10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80802D14: jal         0x80100094
    // 0x80802D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802D18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802D1C: jal         0x800D8FF8
    // 0x80802D20: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80802D20: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80802D24: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80802D28: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80802D2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80802D30: lwc1        $f2, 0x1C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80802D34: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80802D38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802D3C: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x80802D40: nop

    // 0x80802D44: bc1fl       L_80802D58
    if (!c1cs) {
        // 0x80802D48: lwc1        $f10, 0x24($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
            goto L_80802D58;
    }
    goto skip_0;
    // 0x80802D48: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    skip_0:
    // 0x80802D4C: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80802D50: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x80802D54: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
L_80802D58:
    // 0x80802D58: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80802D5C: nop

    // 0x80802D60: bc1fl       L_80802E74
    if (!c1cs) {
        // 0x80802D64: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_80802E74;
    }
    goto skip_1;
    // 0x80802D64: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x80802D68: jal         0x8080460C
    // 0x80802D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_2;
    // 0x80802D6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80802D70: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80802D74: jal         0x8080460C
    // 0x80802D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x80802D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80802D7C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C8C) << 16);
    // 0x80802D80: lwc1        $f18, 0x4C8C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C8C));
    // 0x80802D84: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80802D88: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C90) << 16);
    // 0x80802D8C: lwc1        $f4, 0x4C90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C90));
    // 0x80802D90: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802D94: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80802D98: mul.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80802D9C: lui         $a3, 0x44FA
    ctx->r7 = S32(0X44FA << 16);
    // 0x80802DA0: jal         0x800F11E4
    // 0x80802DA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F11E4(rdram, ctx);
        goto after_4;
    // 0x80802DA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80802DA8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80802DAC: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1752, 0X4D10) << 16);
    // 0x80802DB0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80802DB4: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1752, 0X4D10));
    // 0x80802DB8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80802DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802DC0: jal         0x80089D50
    // 0x80802DC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _subaddieaudioloop_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80802DC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80802DC8: jal         0x8080460C
    // 0x80802DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_6;
    // 0x80802DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80802DD0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80802DD4: jal         0x8080460C
    // 0x80802DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_7;
    // 0x80802DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80802DDC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80802DE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80802DE4: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80802DE8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C94) << 16);
    // 0x80802DEC: lwc1        $f10, 0x4C94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C94));
    // 0x80802DF0: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802DF4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80802DF8: lui         $a3, 0x3F59
    ctx->r7 = S32(0X3F59 << 16);
    // 0x80802DFC: mul.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80802E00: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80802E04: jal         0x800F11E4
    // 0x80802E08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F11E4(rdram, ctx);
        goto after_8;
    // 0x80802E08: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x80802E0C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80802E10: jal         0x800C31DC
    // 0x80802E14: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C31DC(rdram, ctx);
        goto after_9;
    // 0x80802E14: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_9:
    // 0x80802E18: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80802E1C: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x80802E20: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80802E24: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80802E28: jal         0x800C3058
    // 0x80802E2C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800C3058(rdram, ctx);
        goto after_10;
    // 0x80802E2C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_10:
    // 0x80802E30: jal         0x800DC0C0
    // 0x80802E34: nop

    func_800DC0C0(rdram, ctx);
        goto after_11;
    // 0x80802E34: nop

    after_11:
    // 0x80802E38: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C98) << 16);
    // 0x80802E3C: lwc1        $f4, 0x4C98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C98));
    // 0x80802E40: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80802E44: nop

    // 0x80802E48: bc1fl       L_80802E74
    if (!c1cs) {
        // 0x80802E4C: lw          $t7, 0x64($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X64);
            goto L_80802E74;
    }
    goto skip_2;
    // 0x80802E4C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    skip_2:
    // 0x80802E50: jal         0x800C4B70
    // 0x80802E54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800C4B70(rdram, ctx);
        goto after_12;
    // 0x80802E54: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_12:
    // 0x80802E58: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1752, 0X4DA4) << 16);
    // 0x80802E5C: addiu       $a3, $a3, 0x4DA4
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1752, 0X4DA4));
    // 0x80802E60: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80802E64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80802E68: jal         0x8010D930
    // 0x80802E6C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8010D930(rdram, ctx);
        goto after_13;
    // 0x80802E6C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x80802E70: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
L_80802E74:
    // 0x80802E74: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80802E78: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80802E7C: bgezl       $t9, L_80802E94
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80802E80: lhu         $t0, 0x72($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X72);
            goto L_80802E94;
    }
    goto skip_3;
    // 0x80802E80: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
    skip_3:
    // 0x80802E84: jal         0x80800044
    // 0x80802E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800044_chdodgemcontrol(rdram, ctx);
        goto after_14;
    // 0x80802E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80802E8C: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80802E90: lhu         $t0, 0x72($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X72);
L_80802E94:
    // 0x80802E94: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x80802E98: addiu       $t2, $t1, -0x2
    ctx->r10 = ADD32(ctx->r9, -0X2);
    // 0x80802E9C: sltiu       $at, $t2, 0x6
    ctx->r1 = ctx->r10 < 0X6 ? 1 : 0;
    // 0x80802EA0: beq         $at, $zero, L_808031EC
    if (ctx->r1 == 0) {
        // 0x80802EA4: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_808031EC;
    }
    // 0x80802EA4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80802EA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4C9C) << 16);
    // 0x80802EAC: addu        $at, $at, $t2
    gpr jr_addend_80802EB4 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80802EB0: lw          $t2, 0x4C9C($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4C9C));
    // 0x80802EB4: jr          $t2
    // 0x80802EB8: nop

    switch (jr_addend_80802EB4 >> 2) {
        case 0: goto L_80802F6C; break;
        case 1: goto L_80802ED4; break;
        case 2: goto L_80802EBC; break;
        case 3: goto L_808030B4; break;
        case 4: goto L_8080312C; break;
        case 5: goto L_8080317C; break;
        default: switch_error(__func__, 0x80802EB4, 0x80804C9C);
    }
    // 0x80802EB8: nop

L_80802EBC:
    // 0x80802EBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1752, 0X4CB4) << 16);
    // 0x80802EC0: lwc1        $f8, 0x4CB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1752, 0X4CB4));
    // 0x80802EC4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802EC8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80802ECC: b           L_808031EC
    // 0x80802ED0: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
        goto L_808031EC;
    // 0x80802ED0: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_80802ED4:
    // 0x80802ED4: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80802ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802EDC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80802EE0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80802EE4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80802EE8: jal         0x80089BB8
    // 0x80802EEC: nop

    _subaddiejoy_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x80802EEC: nop

    after_15:
    // 0x80802EF0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80802EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80802EF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80802EFC: jal         0x8080460C
    // 0x80802F00: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_16;
    // 0x80802F00: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    after_16:
    // 0x80802F04: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802F08: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80802F0C: nop

    // 0x80802F10: bc1f        L_80802F34
    if (!c1cs) {
        // 0x80802F14: nop
    
            goto L_80802F34;
    }
    // 0x80802F14: nop

    // 0x80802F18: jal         0x8080458C
    // 0x80802F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080458C_chdodgemcontrol(rdram, ctx);
        goto after_17;
    // 0x80802F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80802F20: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80802F24: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802F28: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80802F2C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80802F30: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_80802F34:
    // 0x80802F34: jal         0x80802180
    // 0x80802F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802180_chdodgemcontrol(rdram, ctx);
        goto after_18;
    // 0x80802F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80802F3C: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    // 0x80802F40: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80802F44: bltz        $t6, L_80802F5C
    if (SIGNED(ctx->r14) < 0) {
        // 0x80802F48: nop
    
            goto L_80802F5C;
    }
    // 0x80802F48: nop

    // 0x80802F4C: lbu         $t7, 0x72($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X72);
    // 0x80802F50: andi        $t8, $t7, 0xFF03
    ctx->r24 = ctx->r15 & 0XFF03;
    // 0x80802F54: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x80802F58: sb          $t9, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r25;
L_80802F5C:
    // 0x80802F5C: jal         0x808028E4
    // 0x80802F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808028E4_chdodgemcontrol(rdram, ctx);
        goto after_19;
    // 0x80802F60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80802F64: b           L_808031F0
    // 0x80802F68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808031F0;
    // 0x80802F68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80802F6C:
    // 0x80802F6C: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x80802F70: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80802F74: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80802F78: bgezl       $t2, L_80802F94
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80802F7C: lwc1        $f2, 0x10($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
            goto L_80802F94;
    }
    goto skip_4;
    // 0x80802F7C: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    skip_4:
    // 0x80802F80: lbu         $t3, 0x72($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X72);
    // 0x80802F84: andi        $t4, $t3, 0xFF03
    ctx->r12 = ctx->r11 & 0XFF03;
    // 0x80802F88: ori         $t5, $t4, 0xC
    ctx->r13 = ctx->r12 | 0XC;
    // 0x80802F8C: sb          $t5, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r13;
    // 0x80802F90: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
L_80802F94:
    // 0x80802F94: c.le.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl <= ctx->f6.fl;
    // 0x80802F98: nop

    // 0x80802F9C: bc1fl       L_80803020
    if (!c1cs) {
        // 0x80802FA0: lwc1        $f0, 0x14($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
            goto L_80803020;
    }
    goto skip_5;
    // 0x80802FA0: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    skip_5:
    // 0x80802FA4: jal         0x8080476C
    // 0x80802FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080476C_chdodgemcontrol(rdram, ctx);
        goto after_20;
    // 0x80802FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80802FAC: jal         0x8080460C
    // 0x80802FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_21;
    // 0x80802FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80802FB4: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802FB8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80802FBC: nop

    // 0x80802FC0: bc1fl       L_80802FE0
    if (!c1cs) {
        // 0x80802FC4: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_80802FE0;
    }
    goto skip_6;
    // 0x80802FC4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    skip_6:
    // 0x80802FC8: jal         0x8080458C
    // 0x80802FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080458C_chdodgemcontrol(rdram, ctx);
        goto after_22;
    // 0x80802FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80802FD0: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80802FD4: add.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80802FD8: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x80802FDC: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
L_80802FE0:
    // 0x80802FE0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80802FE4: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80802FE8: lwc1        $f0, 0x14($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80802FEC: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80802FF0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80802FF4: nop

    // 0x80802FF8: bc1fl       L_80803010
    if (!c1cs) {
        // 0x80802FFC: lwc1        $f8, 0x50($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
            goto L_80803010;
    }
    goto skip_7;
    // 0x80802FFC: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    skip_7:
    // 0x80803000: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80803004: b           L_8080309C
    // 0x80803008: swc1        $f6, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f6.u32l;
        goto L_8080309C;
    // 0x80803008: swc1        $f6, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f6.u32l;
    // 0x8080300C: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
L_80803010:
    // 0x80803010: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80803014: b           L_8080309C
    // 0x80803018: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
        goto L_8080309C;
    // 0x80803018: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    // 0x8080301C: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
L_80803020:
    // 0x80803020: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80803024: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80803028: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8080302C: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80803030: bc1f        L_80803084
    if (!c1cs) {
        // 0x80803034: swc1        $f4, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
            goto L_80803084;
    }
    // 0x80803034: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x80803038: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8080303C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803040: sub.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80803044: jal         0x8080460C
    // 0x80803048: swc1        $f16, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f16.u32l;
    func_8080460C_chdodgemcontrol(rdram, ctx);
        goto after_23;
    // 0x80803048: swc1        $f16, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f16.u32l;
    after_23:
    // 0x8080304C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80803050: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80803054: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803058: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8080305C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80803060: nop

    // 0x80803064: bc1f        L_8080309C
    if (!c1cs) {
        // 0x80803068: nop
    
            goto L_8080309C;
    }
    // 0x80803068: nop

    // 0x8080306C: jal         0x8080458C
    // 0x80803070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080458C_chdodgemcontrol(rdram, ctx);
        goto after_24;
    // 0x80803070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80803074: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80803078: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8080307C: b           L_8080309C
    // 0x80803080: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
        goto L_8080309C;
    // 0x80803080: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_80803084:
    // 0x80803084: jal         0x8080349C
    // 0x80803088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080349C_chdodgemcontrol(rdram, ctx);
        goto after_25;
    // 0x80803088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8080308C: jal         0x808037C8
    // 0x80803090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808037C8_chdodgemcontrol(rdram, ctx);
        goto after_26;
    // 0x80803090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80803094: jal         0x80803200
    // 0x80803098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80803200_chdodgemcontrol(rdram, ctx);
        goto after_27;
    // 0x80803098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
L_8080309C:
    // 0x8080309C: jal         0x80802180
    // 0x808030A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80802180_chdodgemcontrol(rdram, ctx);
        goto after_28;
    // 0x808030A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808030A4: jal         0x808028E4
    // 0x808030A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808028E4_chdodgemcontrol(rdram, ctx);
        goto after_29;
    // 0x808030A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808030AC: b           L_808031F0
    // 0x808030B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808031F0;
    // 0x808030B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808030B4:
    // 0x808030B4: lui         $a1, 0x3F3A
    ctx->r5 = S32(0X3F3A << 16);
    // 0x808030B8: ori         $a1, $a1, 0x71DE
    ctx->r5 = ctx->r5 | 0X71DE;
    // 0x808030BC: jal         0x80101E14
    // 0x808030C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_30;
    // 0x808030C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x808030C4: beq         $v0, $zero, L_808030DC
    if (ctx->r2 == 0) {
        // 0x808030C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808030DC;
    }
    // 0x808030C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808030CC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1752, 0X4D48) << 16);
    // 0x808030D0: addiu       $a2, $a2, 0x4D48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1752, 0X4D48));
    // 0x808030D4: jal         0x80089D18
    // 0x808030D8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_31;
    // 0x808030D8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_31:
L_808030DC:
    // 0x808030DC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1752, 0X4F74) << 16);
    // 0x808030E0: addiu       $a1, $a1, 0x4F74
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1752, 0X4F74));
    // 0x808030E4: jal         0x80101E4C
    // 0x808030E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_32;
    // 0x808030E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x808030EC: beq         $v0, $zero, L_80803104
    if (ctx->r2 == 0) {
        // 0x808030F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803104;
    }
    // 0x808030F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808030F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1752, 0X4D5C) << 16);
    // 0x808030F8: addiu       $a2, $a2, 0x4D5C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1752, 0X4D5C));
    // 0x808030FC: jal         0x80089D18
    // 0x80803100: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_33;
    // 0x80803100: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_33:
L_80803104:
    // 0x80803104: jal         0x80104248
    // 0x80803108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_34;
    // 0x80803108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x8080310C: jal         0x8008B324
    // 0x80803110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_35;
    // 0x80803110: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_35:
    // 0x80803114: beq         $v0, $zero, L_808031EC
    if (ctx->r2 == 0) {
        // 0x80803118: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808031EC;
    }
    // 0x80803118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080311C: jal         0x8080422C
    // 0x80803120: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080422C_chdodgemcontrol(rdram, ctx);
        goto after_36;
    // 0x80803120: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_36:
    // 0x80803124: b           L_808031F0
    // 0x80803128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808031F0;
    // 0x80803128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080312C:
    // 0x8080312C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1752, 0X4F84) << 16);
    // 0x80803130: addiu       $a1, $a1, 0x4F84
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1752, 0X4F84));
    // 0x80803134: jal         0x80101E4C
    // 0x80803138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_37;
    // 0x80803138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x8080313C: beq         $v0, $zero, L_80803154
    if (ctx->r2 == 0) {
        // 0x80803140: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80803154;
    }
    // 0x80803140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803144: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1752, 0X4D74) << 16);
    // 0x80803148: addiu       $a2, $a2, 0x4D74
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1752, 0X4D74));
    // 0x8080314C: jal         0x80089D18
    // 0x80803150: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_38;
    // 0x80803150: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_38:
L_80803154:
    // 0x80803154: jal         0x80104248
    // 0x80803158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_39;
    // 0x80803158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x8080315C: jal         0x8008B324
    // 0x80803160: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_40;
    // 0x80803160: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_40:
    // 0x80803164: beq         $v0, $zero, L_808031EC
    if (ctx->r2 == 0) {
        // 0x80803168: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808031EC;
    }
    // 0x80803168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080316C: jal         0x8080422C
    // 0x80803170: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080422C_chdodgemcontrol(rdram, ctx);
        goto after_41;
    // 0x80803170: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_41:
    // 0x80803174: b           L_808031F0
    // 0x80803178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808031F0;
    // 0x80803178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080317C:
    // 0x8080317C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1752, 0X4F94) << 16);
    // 0x80803180: addiu       $a1, $a1, 0x4F94
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1752, 0X4F94));
    // 0x80803184: jal         0x80101E4C
    // 0x80803188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_42;
    // 0x80803188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x8080318C: beq         $v0, $zero, L_808031A4
    if (ctx->r2 == 0) {
        // 0x80803190: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808031A4;
    }
    // 0x80803190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80803194: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1752, 0X4D8C) << 16);
    // 0x80803198: addiu       $a2, $a2, 0x4D8C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1752, 0X4D8C));
    // 0x8080319C: jal         0x80089D18
    // 0x808031A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_43;
    // 0x808031A0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_43:
L_808031A4:
    // 0x808031A4: lui         $a1, 0x3EC7
    ctx->r5 = S32(0X3EC7 << 16);
    // 0x808031A8: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    // 0x808031AC: jal         0x80101E14
    // 0x808031B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_44;
    // 0x808031B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x808031B4: beq         $v0, $zero, L_808031CC
    if (ctx->r2 == 0) {
        // 0x808031B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808031CC;
    }
    // 0x808031B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808031BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1752, 0X4D48) << 16);
    // 0x808031C0: addiu       $a2, $a2, 0x4D48
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1752, 0X4D48));
    // 0x808031C4: jal         0x80089D18
    // 0x808031C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_45;
    // 0x808031C8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_45:
L_808031CC:
    // 0x808031CC: jal         0x80104248
    // 0x808031D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80104248(rdram, ctx);
        goto after_46;
    // 0x808031D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_46:
    // 0x808031D4: jal         0x8008B324
    // 0x808031D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_isStopped(rdram, ctx);
        goto after_47;
    // 0x808031D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_47:
    // 0x808031DC: beq         $v0, $zero, L_808031EC
    if (ctx->r2 == 0) {
        // 0x808031E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808031EC;
    }
    // 0x808031E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808031E4: jal         0x8080422C
    // 0x808031E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080422C_chdodgemcontrol(rdram, ctx);
        goto after_48;
    // 0x808031E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_48:
L_808031EC:
    // 0x808031EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808031F0:
    // 0x808031F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808031F4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808031F8: jr          $ra
    // 0x808031FC: nop

    return;
    // 0x808031FC: nop

;}
RECOMP_FUNC void func_8009E69C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E69C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E6A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E6A4: lw          $t6, 0x120($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X120);
    // 0x8009E6A8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8009E6AC: jal         0x8009CA70
    // 0x8009E6B0: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    func_8009CA70(rdram, ctx);
        goto after_0;
    // 0x8009E6B0: lw          $a1, 0x8($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X8);
    after_0:
    // 0x8009E6B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E6B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E6BC: jr          $ra
    // 0x8009E6C0: nop

    return;
    // 0x8009E6C0: nop

;}
RECOMP_FUNC void func_8080035C_chdinofoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080035C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800360: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800364: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800368: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x8080036C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800370: srl         $t7, $t6, 22
    ctx->r15 = S32(U32(ctx->r14) >> 22);
    // 0x80800374: bnel        $t7, $zero, L_808003F8
    if (ctx->r15 != 0) {
        // 0x80800378: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003F8;
    }
    goto skip_0;
    // 0x80800378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080037C: lhu         $t8, 0x72($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X72);
    // 0x80800380: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800384: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800388: bne         $t9, $at, L_808003D4
    if (ctx->r25 != ctx->r1) {
        // 0x8080038C: nop
    
            goto L_808003D4;
    }
    // 0x8080038C: nop

    // 0x80800390: jal         0x80101F24
    // 0x80800394: nop

    func_80101F24(rdram, ctx);
        goto after_0;
    // 0x80800394: nop

    after_0:
    // 0x80800398: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1040, 0X7C4) << 16);
    // 0x8080039C: lwc1        $f4, 0x7C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1040, 0X7C4));
    // 0x808003A0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x808003A4: nop

    // 0x808003A8: bc1f        L_808003D4
    if (!c1cs) {
        // 0x808003AC: nop
    
            goto L_808003D4;
    }
    // 0x808003AC: nop

    // 0x808003B0: jal         0x800F54E4
    // 0x808003B4: nop

    func_800F54E4(rdram, ctx);
        goto after_1;
    // 0x808003B4: nop

    after_1:
    // 0x808003B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003BC: jal         0x800F7B9C
    // 0x808003C0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_800F7B9C(rdram, ctx);
        goto after_2;
    // 0x808003C0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_2:
    // 0x808003C4: jal         0x8010A570
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_3;
    // 0x808003C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003CC: b           L_808003F8
    // 0x808003D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808003F8;
    // 0x808003D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003D4:
    // 0x808003D4: jal         0x800F54E4
    // 0x808003D8: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808003D8: nop

    after_4:
    // 0x808003DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003E0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x808003E4: jal         0x800F79DC
    // 0x808003E8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_800F79DC(rdram, ctx);
        goto after_5;
    // 0x808003E8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x808003EC: jal         0x8010A570
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x808003F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003F8:
    // 0x808003F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800400: jr          $ra
    // 0x80800404: nop

    return;
    // 0x80800404: nop

;}
RECOMP_FUNC void _bskaz_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800832E8: syscall     53
    recomp_syscall_handler(rdram, ctx, 0x800832E8);
    return;
    // 0x800832EC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _chtrashcangame_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800876A0: syscall     604
    recomp_syscall_handler(rdram, ctx, 0x800876A0);
    return;
    // 0x800876A4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800CE95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE95C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE964: jal         0x800CE3E0
    // 0x800CE968: nop

    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CE968: nop

    after_0:
    // 0x800CE96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE970: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x800CE974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE978: jr          $ra
    // 0x800CE97C: nop

    return;
    // 0x800CE97C: nop

;}
RECOMP_FUNC void func_808011A0_chfactorytoxiccloud(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808011A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808011A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808011AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808011B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808011B4: beq         $a1, $v0, L_80801244
    if (ctx->r5 == ctx->r2) {
        // 0x808011B8: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80801244;
    }
    // 0x808011B8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808011BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808011C0: beq         $a1, $at, L_80801268
    if (ctx->r5 == ctx->r1) {
        // 0x808011C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801268;
    }
    // 0x808011C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011C8: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x808011CC: beq         $a1, $at, L_80801290
    if (ctx->r5 == ctx->r1) {
        // 0x808011D0: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(2300, 0X1434) << 16);
            goto L_80801290;
    }
    // 0x808011D0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2300, 0X1434) << 16);
    // 0x808011D4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x808011D8: beq         $a1, $at, L_808011F4
    if (ctx->r5 == ctx->r1) {
        // 0x808011DC: addiu       $a0, $s0, 0x18
        ctx->r4 = ADD32(ctx->r16, 0X18);
            goto L_808011F4;
    }
    // 0x808011DC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808011E0: addiu       $at, $zero, 0x97
    ctx->r1 = ADD32(0, 0X97);
    // 0x808011E4: beq         $a1, $at, L_808012A0
    if (ctx->r5 == ctx->r1) {
        // 0x808011E8: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(2300, 0X155C) << 16);
            goto L_808012A0;
    }
    // 0x808011E8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2300, 0X155C) << 16);
    // 0x808011EC: b           L_808012B0
    // 0x808011F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808012B0;
    // 0x808011F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808011F4:
    // 0x808011F4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2300, 0X1518) << 16);
    // 0x808011F8: addiu       $t6, $t6, 0x1518
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2300, 0X1518));
    // 0x808011FC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80801200: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801204: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801208: jal         0x800BBCB8
    // 0x8080120C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_800BBCB8(rdram, ctx);
        goto after_0;
    // 0x8080120C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x80801210: jal         0x800FFAB0
    // 0x80801214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80801214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801218: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x8080121C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80801220: bgez        $t9, L_8080123C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80801224: nop
    
            goto L_8080123C;
    }
    // 0x80801224: nop

    // 0x80801228: jal         0x800CF494
    // 0x8080122C: nop

    func_800CF494(rdram, ctx);
        goto after_2;
    // 0x8080122C: nop

    after_2:
    // 0x80801230: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80801234: andi        $t1, $t0, 0xFFF7
    ctx->r9 = ctx->r8 & 0XFFF7;
    // 0x80801238: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_8080123C:
    // 0x8080123C: b           L_808012B0
    // 0x80801240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808012B0;
    // 0x80801240: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801244:
    // 0x80801244: lhu         $t2, 0x72($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X72);
    // 0x80801248: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080124C: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80801250: beq         $v0, $t3, L_80801260
    if (ctx->r2 == ctx->r11) {
        // 0x80801254: nop
    
            goto L_80801260;
    }
    // 0x80801254: nop

    // 0x80801258: jal         0x80102424
    // 0x8080125C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_3;
    // 0x8080125C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
L_80801260:
    // 0x80801260: b           L_808012B0
    // 0x80801264: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808012B0;
    // 0x80801264: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801268:
    // 0x80801268: jal         0x80107070
    // 0x8080126C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80107070(rdram, ctx);
        goto after_4;
    // 0x8080126C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80801270: bne         $v0, $zero, L_80801288
    if (ctx->r2 != 0) {
        // 0x80801274: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801288;
    }
    // 0x80801274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801278: jal         0x80102424
    // 0x8080127C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x8080127C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_5:
    // 0x80801280: jal         0x80089CA8
    // 0x80801284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80801284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80801288:
    // 0x80801288: b           L_808012B0
    // 0x8080128C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808012B0;
    // 0x8080128C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801290:
    // 0x80801290: jal         0x80101074
    // 0x80801294: addiu       $a0, $a0, 0x1434
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2300, 0X1434));
    func_80101074(rdram, ctx);
        goto after_7;
    // 0x80801294: addiu       $a0, $a0, 0x1434
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2300, 0X1434));
    after_7:
    // 0x80801298: b           L_808012B0
    // 0x8080129C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808012B0;
    // 0x8080129C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_808012A0:
    // 0x808012A0: jal         0x80101010
    // 0x808012A4: addiu       $a0, $a0, 0x155C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2300, 0X155C));
    func_80101010(rdram, ctx);
        goto after_8;
    // 0x808012A4: addiu       $a0, $a0, 0x155C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(2300, 0X155C));
    after_8:
    // 0x808012A8: b           L_808012B0
    // 0x808012AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808012B0;
    // 0x808012AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808012B0:
    // 0x808012B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808012B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808012B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808012BC: jr          $ra
    // 0x808012C0: nop

    return;
    // 0x808012C0: nop

;}
RECOMP_FUNC void func_80805A64_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805A64: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80805A68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80805A6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80805A70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80805A74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80805A78: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80805A7C: jal         0x80100094
    // 0x80805A80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80805A80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80805A84: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80805A88: jal         0x80802228
    // 0x80805A8C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80802228_chdiggerboss(rdram, ctx);
        goto after_1;
    // 0x80805A8C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80805A90: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80805A94: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80805A98: jal         0x80802C40
    // 0x80805A9C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80802C40_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x80805A9C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80805AA0: jal         0x800F54E4
    // 0x80805AA4: nop

    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80805AA4: nop

    after_3:
    // 0x80805AA8: jal         0x800F6D24
    // 0x80805AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6D24(rdram, ctx);
        goto after_4;
    // 0x80805AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80805AB0: beql        $v0, $zero, L_80805AC4
    if (ctx->r2 == 0) {
        // 0x80805AB4: lbu         $v0, 0x25($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X25);
            goto L_80805AC4;
    }
    goto skip_0;
    // 0x80805AB4: lbu         $v0, 0x25($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X25);
    skip_0:
    // 0x80805AB8: b           L_80805B74
    // 0x80805ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80805B74;
    // 0x80805ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80805AC0: lbu         $v0, 0x25($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X25);
L_80805AC4:
    // 0x80805AC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805AC8: beq         $v0, $at, L_80805AE0
    if (ctx->r2 == ctx->r1) {
        // 0x80805ACC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80805AE0;
    }
    // 0x80805ACC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805AD0: beq         $v0, $at, L_80805AF8
    if (ctx->r2 == ctx->r1) {
        // 0x80805AD4: nop
    
            goto L_80805AF8;
    }
    // 0x80805AD4: nop

    // 0x80805AD8: b           L_80805B74
    // 0x80805ADC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
        goto L_80805B74;
    // 0x80805ADC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80805AE0:
    // 0x80805AE0: jal         0x800D9078
    // 0x80805AE4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    func_800D9078(rdram, ctx);
        goto after_5;
    // 0x80805AE4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    after_5:
    // 0x80805AE8: beq         $v0, $zero, L_80805B70
    if (ctx->r2 == 0) {
        // 0x80805AEC: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_80805B70;
    }
    // 0x80805AEC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80805AF0: b           L_80805B70
    // 0x80805AF4: sb          $t6, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r14;
        goto L_80805B70;
    // 0x80805AF4: sb          $t6, 0x25($s0)
    MEM_B(0X25, ctx->r16) = ctx->r14;
L_80805AF8:
    // 0x80805AF8: jal         0x800D9078
    // 0x80805AFC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    func_800D9078(rdram, ctx);
        goto after_6;
    // 0x80805AFC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    after_6:
    // 0x80805B00: jal         0x800D8FF8
    // 0x80805B04: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_7;
    // 0x80805B04: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_7:
    // 0x80805B08: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80805B0C: lwc1        $f4, 0x48($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X48);
    // 0x80805B10: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80805B14: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80805B18: swc1        $f10, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f10.u32l;
    // 0x80805B1C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80805B20: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80805B24: sltiu       $t7, $a1, 0x1
    ctx->r15 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80805B28: jal         0x808064CC
    // 0x80805B2C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_808064CC_chdiggerboss(rdram, ctx);
        goto after_8;
    // 0x80805B2C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_8:
    // 0x80805B30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80805B34: jal         0x80805B8C
    // 0x80805B38: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    func_80805B8C_chdiggerboss(rdram, ctx);
        goto after_9;
    // 0x80805B38: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    after_9:
    // 0x80805B3C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80805B40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80805B44: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80805B48: beq         $t8, $zero, L_80805B70
    if (ctx->r24 == 0) {
        // 0x80805B4C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80805B70;
    }
    // 0x80805B4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80805B50:
    // 0x80805B50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80805B54: jal         0x80805448
    // 0x80805B58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80805448_chdiggerboss(rdram, ctx);
        goto after_10;
    // 0x80805B58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x80805B5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80805B60: bnel        $s0, $s1, L_80805B50
    if (ctx->r16 != ctx->r17) {
        // 0x80805B64: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80805B50;
    }
    goto skip_1;
    // 0x80805B64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
    // 0x80805B68: jal         0x80802CB4
    // 0x80805B6C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80802CB4_chdiggerboss(rdram, ctx);
        goto after_11;
    // 0x80805B6C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_11:
L_80805B70:
    // 0x80805B70: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80805B74:
    // 0x80805B74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80805B78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80805B7C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80805B80: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80805B84: jr          $ra
    // 0x80805B88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80805B88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void bakey_getBitfield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091D00: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80091D04: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x80091D08: xori        $t7, $v0, 0x3FFF
    ctx->r15 = ctx->r2 ^ 0X3FFF;
    // 0x80091D0C: jr          $ra
    // 0x80091D10: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    return;
    // 0x80091D10: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void ncpod_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B94: jal         0x80110024
    // 0x80800B98: nop

    func_80110024(rdram, ctx);
        goto after_0;
    // 0x80800B98: nop

    after_0:
    // 0x80800B9C: bne         $v0, $zero, L_80800BAC
    if (ctx->r2 != 0) {
        // 0x80800BA0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800BAC;
    }
    // 0x80800BA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800BA4: b           L_80800BB0
    // 0x80800BA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80800BB0;
    // 0x80800BA8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800BAC:
    // 0x80800BAC: lh          $v0, 0x3C($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X3C);
L_80800BB0:
    // 0x80800BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BB8: jr          $ra
    // 0x80800BBC: nop

    return;
    // 0x80800BBC: nop

;}
RECOMP_FUNC void func_80802178_sumole(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080217C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802180: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80802184: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80802188: addiu       $a1, $zero, 0x18F
    ctx->r5 = ADD32(0, 0X18F);
    // 0x8080218C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80802190: jal         0x80089C20
    // 0x80802194: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80802194: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80802198: beq         $v0, $zero, L_808021A8
    if (ctx->r2 == 0) {
        // 0x8080219C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808021A8;
    }
    // 0x8080219C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808021A0: b           L_808021AC
    // 0x808021A4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
        goto L_808021AC;
    // 0x808021A4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_808021A8:
    // 0x808021A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808021AC:
    // 0x808021AC: jr          $ra
    // 0x808021B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x808021B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C075C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C075C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C0760: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C0764: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C0768: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C076C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C0770: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C0774: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C0778: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C077C: addiu       $s2, $s2, -0x7748
    ctx->r18 = ADD32(ctx->r18, -0X7748);
    // 0x800C0780: addiu       $s1, $s1, -0x7750
    ctx->r17 = ADD32(ctx->r17, -0X7750);
    // 0x800C0784: addiu       $s0, $s0, -0x7750
    ctx->r16 = ADD32(ctx->r16, -0X7750);
    // 0x800C0788: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
L_800C078C:
    // 0x800C078C: beql        $a0, $zero, L_800C07A4
    if (ctx->r4 == 0) {
        // 0x800C0790: lw          $a0, 0x12C($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X12C);
            goto L_800C07A4;
    }
    goto skip_0;
    // 0x800C0790: lw          $a0, 0x12C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X12C);
    skip_0:
    // 0x800C0794: jal         0x800C7150
    // 0x800C0798: nop

    func_800C7150(rdram, ctx);
        goto after_0;
    // 0x800C0798: nop

    after_0:
    // 0x800C079C: sw          $v0, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->r2;
    // 0x800C07A0: lw          $a0, 0x12C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X12C);
L_800C07A4:
    // 0x800C07A4: beql        $a0, $zero, L_800C07BC
    if (ctx->r4 == 0) {
        // 0x800C07A8: lw          $a0, 0x104($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X104);
            goto L_800C07BC;
    }
    goto skip_1;
    // 0x800C07A8: lw          $a0, 0x104($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X104);
    skip_1:
    // 0x800C07AC: jal         0x800C7150
    // 0x800C07B0: nop

    func_800C7150(rdram, ctx);
        goto after_1;
    // 0x800C07B0: nop

    after_1:
    // 0x800C07B4: sw          $v0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->r2;
    // 0x800C07B8: lw          $a0, 0x104($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X104);
L_800C07BC:
    // 0x800C07BC: beql        $a0, $zero, L_800C07D4
    if (ctx->r4 == 0) {
        // 0x800C07C0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800C07D4;
    }
    goto skip_2;
    // 0x800C07C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_2:
    // 0x800C07C4: jal         0x8001BAFC
    // 0x800C07C8: nop

    defrag(rdram, ctx);
        goto after_2;
    // 0x800C07C8: nop

    after_2:
    // 0x800C07CC: sw          $v0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->r2;
    // 0x800C07D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800C07D4:
    // 0x800C07D4: bnel        $s0, $s2, L_800C078C
    if (ctx->r16 != ctx->r18) {
        // 0x800C07D8: lw          $a0, 0x120($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X120);
            goto L_800C078C;
    }
    goto skip_3;
    // 0x800C07D8: lw          $a0, 0x120($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X120);
    skip_3:
    // 0x800C07DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C07E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C07E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C07E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C07EC: jr          $ra
    // 0x800C07F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C07F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808000B8_chswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C0: jal         0x80106790
    // 0x808000C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808000C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x808000C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000CC: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x808000D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x808000D8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808000DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000E0: bc1tl       L_80800120
    if (c1cs) {
        // 0x808000E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800120;
    }
    goto skip_0;
    // 0x808000E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000E8: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    // 0x808000EC: lbu         $t3, 0x65($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X65);
    // 0x808000F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808000F4: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x808000F8: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x808000FC: xori        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 ^ 0X1;
    // 0x80800100: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80800104: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x80800108: andi        $t4, $t3, 0xFFEF
    ctx->r12 = ctx->r11 & 0XFFEF;
    // 0x8080010C: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80800110: sb          $t5, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r13;
    // 0x80800114: jal         0x80103110
    // 0x80800118: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x80800118: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    after_1:
    // 0x8080011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800120:
    // 0x80800120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800124: jr          $ra
    // 0x80800128: nop

    return;
    // 0x80800128: nop

;}
RECOMP_FUNC void bstaxi_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800840: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800844: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800848: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080084C: jal         0x80800144
    // 0x80800850: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstaxi_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800850: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800854: lui         $a2, 0x3F8C
    ctx->r6 = S32(0X3F8C << 16);
    // 0x80800858: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8080085C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800860: jal         0x8008CCBC
    // 0x80800864: addiu       $a1, $zero, 0xF3
    ctx->r5 = ADD32(0, 0XF3);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80800864: addiu       $a1, $zero, 0xF3
    ctx->r5 = ADD32(0, 0XF3);
    after_1:
    // 0x80800868: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8080086C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800878: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080087C: jal         0x8009FFD8
    // 0x80800880: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800880: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80800884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800888: jal         0x8009B9B0
    // 0x8080088C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x8080088C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800894: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800898: jal         0x80098140
    // 0x8080089C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_4;
    // 0x8080089C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808008A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808008A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808008AC: jr          $ra
    // 0x808008B0: nop

    return;
    // 0x808008B0: nop

;}
RECOMP_FUNC void _subaddiebounce_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089A90: syscall     801
    recomp_syscall_handler(rdram, ctx, 0x80089A90);
    return;
    // 0x80089A94: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800D8F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8F84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800D8F88: lwc1        $f4, 0x5D14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5D14);
    // 0x800D8F8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D8F90: swc1        $f4, -0x38A0($at)
    MEM_W(-0X38A0, ctx->r1) = ctx->f4.u32l;
    // 0x800D8F94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D8F98: jr          $ra
    // 0x800D8F9C: sw          $zero, -0x389C($at)
    MEM_W(-0X389C, ctx->r1) = 0;
    return;
    // 0x800D8F9C: sw          $zero, -0x389C($at)
    MEM_W(-0X389C, ctx->r1) = 0;
;}
RECOMP_FUNC void _baduo_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800849B8: syscall     124
    recomp_syscall_handler(rdram, ctx, 0x800849B8);
    return;
    // 0x800849BC: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void sukickball_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808009FC: jal         0x80100094
    // 0x80800A00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A04: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A0C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800A10: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80800A14: lw          $v0, 0x10($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X10);
    // 0x80800A18: jr          $ra
    // 0x80800A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D30: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D30);
    return;
    // 0x80087D34: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_808020B0_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808020B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808020B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808020B8: jal         0x8080237C
    // 0x808020BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080237C_chcollballcontrol(rdram, ctx);
        goto after_0;
    // 0x808020BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808020C0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808020C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808020C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808020CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808020D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808020D4: beq         $v0, $at, L_808020E4
    if (ctx->r2 == ctx->r1) {
        // 0x808020D8: swc1        $f4, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
            goto L_808020E4;
    }
    // 0x808020D8: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x808020DC: jal         0x808023FC
    // 0x808020E0: nop

    func_808023FC_chcollballcontrol(rdram, ctx);
        goto after_1;
    // 0x808020E0: nop

    after_1:
L_808020E4:
    // 0x808020E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808020E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808020EC: jr          $ra
    // 0x808020F0: nop

    return;
    // 0x808020F0: nop

;}
