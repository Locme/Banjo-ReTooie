#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800E24_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800E28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800E2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800E30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800E34: jal         0x80100094
    // 0x80800E38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E3C: jal         0x800D8FF8
    // 0x80800E40: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800E40: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800E44: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800E48: jal         0x80800D3C
    // 0x80800E4C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80800D3C_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80800E4C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x80800E50: beql        $v0, $zero, L_808011A4
    if (ctx->r2 == 0) {
        // 0x80800E54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808011A4;
    }
    goto skip_0;
    // 0x80800E54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800E58: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800E5C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800E60: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800E64: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80800E68: nop

    // 0x80800E6C: bc1fl       L_80800E80
    if (!c1cs) {
        // 0x80800E70: lw          $t6, 0x64($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X64);
            goto L_80800E80;
    }
    goto skip_1;
    // 0x80800E70: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x80800E74: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80800E78: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x80800E7C: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
L_80800E80:
    // 0x80800E80: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80800E84: bltz        $t8, L_80800FF8
    if (SIGNED(ctx->r24) < 0) {
        // 0x80800E88: nop
    
            goto L_80800FF8;
    }
    // 0x80800E88: nop

    // 0x80800E8C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80800E90: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800E94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800E98: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80800E9C: nop

    // 0x80800EA0: bc1f        L_80800FF8
    if (!c1cs) {
        // 0x80800EA4: nop
    
            goto L_80800FF8;
    }
    // 0x80800EA4: nop

    // 0x80800EA8: jal         0x80016068
    // 0x80800EAC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80016068(rdram, ctx);
        goto after_3;
    // 0x80800EAC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x80800EB0: jal         0x800F2100
    // 0x80800EB4: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    mlAbsF(rdram, ctx);
        goto after_4;
    // 0x80800EB4: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800EB8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800EBC: jal         0x800F2100
    // 0x80800EC0: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    mlAbsF(rdram, ctx);
        goto after_5;
    // 0x80800EC0: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800EC4: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800EC8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7C88) << 16);
    // 0x80800ECC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80800ED0: nop

    // 0x80800ED4: bc1fl       L_80800EEC
    if (!c1cs) {
        // 0x80800ED8: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80800EEC;
    }
    goto skip_2;
    // 0x80800ED8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_2:
    // 0x80800EDC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800EE0: b           L_80800EF4
    // 0x80800EE4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
        goto L_80800EF4;
    // 0x80800EE4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80800EE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80800EEC:
    // 0x80800EEC: nop

    // 0x80800EF0: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
L_80800EF4:
    // 0x80800EF4: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800EF8: lwc1        $f10, 0x7C88($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7C88));
    // 0x80800EFC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7C8C) << 16);
    // 0x80800F00: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800F04: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800F08: nop

    // 0x80800F0C: bc1f        L_80800F3C
    if (!c1cs) {
        // 0x80800F10: nop
    
            goto L_80800F3C;
    }
    // 0x80800F10: nop

    // 0x80800F14: lbu         $t9, 0x79($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X79);
    // 0x80800F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F1C: srl         $t0, $t9, 4
    ctx->r8 = S32(U32(ctx->r25) >> 4);
    // 0x80800F20: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x80800F24: beq         $t1, $zero, L_80800F3C
    if (ctx->r9 == 0) {
        // 0x80800F28: nop
    
            goto L_80800F3C;
    }
    // 0x80800F28: nop

    // 0x80800F2C: jal         0x80801338
    // 0x80800F30: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80801338_chgameselect(rdram, ctx);
        goto after_6;
    // 0x80800F30: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_6:
    // 0x80800F34: b           L_80800F74
    // 0x80800F38: nop

        goto L_80800F74;
    // 0x80800F38: nop

L_80800F3C:
    // 0x80800F3C: lwc1        $f16, 0x7C8C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7C8C));
    // 0x80800F40: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800F44: nop

    // 0x80800F48: bc1f        L_80800F74
    if (!c1cs) {
        // 0x80800F4C: nop
    
            goto L_80800F74;
    }
    // 0x80800F4C: nop

    // 0x80800F50: lbu         $t2, 0x79($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X79);
    // 0x80800F54: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F5C: srl         $t3, $t2, 4
    ctx->r11 = S32(U32(ctx->r10) >> 4);
    // 0x80800F60: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x80800F64: beq         $t4, $at, L_80800F74
    if (ctx->r12 == ctx->r1) {
        // 0x80800F68: nop
    
            goto L_80800F74;
    }
    // 0x80800F68: nop

    // 0x80800F6C: jal         0x80801338
    // 0x80800F70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801338_chgameselect(rdram, ctx);
        goto after_7;
    // 0x80800F70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
L_80800F74:
    // 0x80800F74: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7C90) << 16);
    // 0x80800F78: lwc1        $f6, 0x7C90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7C90));
    // 0x80800F7C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800F80: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800F84: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800F88: nop

    // 0x80800F8C: bc1f        L_80800FC0
    if (!c1cs) {
        // 0x80800F90: nop
    
            goto L_80800FC0;
    }
    // 0x80800F90: nop

    // 0x80800F94: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x80800F98: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FA0: srl         $t5, $v0, 4
    ctx->r13 = S32(U32(ctx->r2) >> 4);
    // 0x80800FA4: andi        $t6, $t5, 0x4
    ctx->r14 = ctx->r13 & 0X4;
    // 0x80800FA8: beq         $t6, $at, L_80800FC0
    if (ctx->r14 == ctx->r1) {
        // 0x80800FAC: nop
    
            goto L_80800FC0;
    }
    // 0x80800FAC: nop

    // 0x80800FB0: jal         0x808013C8
    // 0x80800FB4: addiu       $a1, $t5, 0x4
    ctx->r5 = ADD32(ctx->r13, 0X4);
    func_808013C8_chgameselect(rdram, ctx);
        goto after_8;
    // 0x80800FB4: addiu       $a1, $t5, 0x4
    ctx->r5 = ADD32(ctx->r13, 0X4);
    after_8:
    // 0x80800FB8: b           L_80800FF8
    // 0x80800FBC: nop

        goto L_80800FF8;
    // 0x80800FBC: nop

L_80800FC0:
    // 0x80800FC0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(804, 0X7C94) << 16);
    // 0x80800FC4: lwc1        $f8, 0x7C94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(804, 0X7C94));
    // 0x80800FC8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80800FCC: nop

    // 0x80800FD0: bc1f        L_80800FF8
    if (!c1cs) {
        // 0x80800FD4: nop
    
            goto L_80800FF8;
    }
    // 0x80800FD4: nop

    // 0x80800FD8: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x80800FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800FE0: srl         $t7, $v0, 4
    ctx->r15 = S32(U32(ctx->r2) >> 4);
    // 0x80800FE4: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x80800FE8: beq         $t8, $zero, L_80800FF8
    if (ctx->r24 == 0) {
        // 0x80800FEC: nop
    
            goto L_80800FF8;
    }
    // 0x80800FEC: nop

    // 0x80800FF0: jal         0x808013C8
    // 0x80800FF4: addiu       $a1, $t7, -0x4
    ctx->r5 = ADD32(ctx->r15, -0X4);
    func_808013C8_chgameselect(rdram, ctx);
        goto after_9;
    // 0x80800FF4: addiu       $a1, $t7, -0x4
    ctx->r5 = ADD32(ctx->r15, -0X4);
    after_9:
L_80800FF8:
    // 0x80800FF8: jal         0x800DA298
    // 0x80800FFC: addiu       $a0, $zero, 0x64A
    ctx->r4 = ADD32(0, 0X64A);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800FFC: addiu       $a0, $zero, 0x64A
    ctx->r4 = ADD32(0, 0X64A);
    after_10:
    // 0x80801000: beq         $v0, $zero, L_80801068
    if (ctx->r2 == 0) {
        // 0x80801004: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801068;
    }
    // 0x80801004: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801008: jal         0x80016B30
    // 0x8080100C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_11;
    // 0x8080100C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80801010: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801014: bne         $v0, $at, L_8080103C
    if (ctx->r2 != ctx->r1) {
        // 0x80801018: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8080103C;
    }
    // 0x80801018: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080101C: lbu         $a2, 0x79($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X79);
    // 0x80801020: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801024: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80801028: srl         $t9, $a2, 4
    ctx->r25 = S32(U32(ctx->r6) >> 4);
    // 0x8080102C: jal         0x8010114C
    // 0x80801030: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    func_8010114C(rdram, ctx);
        goto after_12;
    // 0x80801030: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_12:
    // 0x80801034: b           L_8080106C
    // 0x80801038: lw          $t1, 0x6C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X6C);
        goto L_8080106C;
    // 0x80801038: lw          $t1, 0x6C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X6C);
L_8080103C:
    // 0x8080103C: jal         0x80016B30
    // 0x80801040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80016B30(rdram, ctx);
        goto after_13;
    // 0x80801040: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80801044: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801048: bnel        $v0, $at, L_8080106C
    if (ctx->r2 != ctx->r1) {
        // 0x8080104C: lw          $t1, 0x6C($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X6C);
            goto L_8080106C;
    }
    goto skip_3;
    // 0x8080104C: lw          $t1, 0x6C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X6C);
    skip_3:
    // 0x80801050: lbu         $a2, 0x79($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X79);
    // 0x80801054: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80801058: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8080105C: srl         $t0, $a2, 4
    ctx->r8 = S32(U32(ctx->r6) >> 4);
    // 0x80801060: jal         0x8010114C
    // 0x80801064: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    func_8010114C(rdram, ctx);
        goto after_14;
    // 0x80801064: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    after_14:
L_80801068:
    // 0x80801068: lw          $t1, 0x6C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X6C);
L_8080106C:
    // 0x8080106C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801070: andi        $t2, $t1, 0x1FF
    ctx->r10 = ctx->r9 & 0X1FF;
    // 0x80801074: bnel        $t2, $at, L_808010D8
    if (ctx->r10 != ctx->r1) {
        // 0x80801078: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_808010D8;
    }
    goto skip_4;
    // 0x80801078: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_4:
    // 0x8080107C: lw          $t3, 0x7C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X7C);
    // 0x80801080: sll         $t5, $t3, 19
    ctx->r13 = S32(ctx->r11 << 19);
    // 0x80801084: bgezl       $t5, L_808010D8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80801088: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_808010D8;
    }
    goto skip_5;
    // 0x80801088: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_5:
    // 0x8080108C: lbu         $v0, 0x79($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X79);
    // 0x80801090: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80801094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801098: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x8080109C: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x808010A0: lbu         $t8, 0xC0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XC0);
    // 0x808010A4: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x808010A8: subu        $t9, $t9, $t6
    ctx->r25 = SUB32(ctx->r25, ctx->r14);
    // 0x808010AC: beq         $t8, $zero, L_808010D4
    if (ctx->r24 == 0) {
        // 0x808010B0: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_808010D4;
    }
    // 0x808010B0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808010B4: addu        $a1, $v1, $t9
    ctx->r5 = ADD32(ctx->r3, ctx->r25);
    // 0x808010B8: jal         0x808014F0
    // 0x808010BC: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    func_808014F0_chgameselect(rdram, ctx);
        goto after_15;
    // 0x808010BC: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    after_15:
    // 0x808010C0: beql        $v0, $zero, L_808010D8
    if (ctx->r2 == 0) {
        // 0x808010C4: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_808010D8;
    }
    goto skip_6;
    // 0x808010C4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_6:
    // 0x808010C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808010CC: nop

    // 0x808010D0: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_808010D4:
    // 0x808010D4: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_808010D8:
    // 0x808010D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808010DC: sll         $t1, $v0, 12
    ctx->r9 = S32(ctx->r2 << 12);
    // 0x808010E0: bgez        $t1, L_8080114C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808010E4: sll         $t3, $v0, 11
        ctx->r11 = S32(ctx->r2 << 11);
            goto L_8080114C;
    }
    // 0x808010E4: sll         $t3, $v0, 11
    ctx->r11 = S32(ctx->r2 << 11);
    // 0x808010E8: bltzl       $t3, L_80801150
    if (SIGNED(ctx->r11) < 0) {
        // 0x808010EC: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80801150;
    }
    goto skip_7;
    // 0x808010EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_7:
    // 0x808010F0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808010F4: lwc1        $f4, 0x34($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X34);
    // 0x808010F8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x808010FC: nop

    // 0x80801100: bc1fl       L_808011A4
    if (!c1cs) {
        // 0x80801104: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808011A4;
    }
    goto skip_8;
    // 0x80801104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80801108: jal         0x800D8FF8
    // 0x8080110C: nop

    func_800D8FF8(rdram, ctx);
        goto after_16;
    // 0x8080110C: nop

    after_16:
    // 0x80801110: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801114: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801118: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8080111C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801120: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80801124: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80801128: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x8080112C: lwc1        $f18, 0x34($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80801130: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80801134: nop

    // 0x80801138: bc1fl       L_808011A4
    if (!c1cs) {
        // 0x8080113C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808011A4;
    }
    goto skip_9;
    // 0x8080113C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80801140: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801144: b           L_808011A0
    // 0x80801148: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
        goto L_808011A0;
    // 0x80801148: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
L_8080114C:
    // 0x8080114C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80801150:
    // 0x80801150: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80801154: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80801158: nop

    // 0x8080115C: bc1fl       L_808011A4
    if (!c1cs) {
        // 0x80801160: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808011A4;
    }
    goto skip_10;
    // 0x80801160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80801164: jal         0x800D8FF8
    // 0x80801168: nop

    func_800D8FF8(rdram, ctx);
        goto after_17;
    // 0x80801168: nop

    after_17:
    // 0x8080116C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801170: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80801174: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80801178: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8080117C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80801180: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80801184: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80801188: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8080118C: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80801190: nop

    // 0x80801194: bc1fl       L_808011A4
    if (!c1cs) {
        // 0x80801198: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808011A4;
    }
    goto skip_11;
    // 0x80801198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x8080119C: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
L_808011A0:
    // 0x808011A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011A4:
    // 0x808011A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808011A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808011AC: jr          $ra
    // 0x808011B0: nop

    return;
    // 0x808011B0: nop

;}
RECOMP_FUNC void func_8080020C_chjiggygamenew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080020C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800210: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800214: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800218: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8080021C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800220: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800224: jal         0x80106790
    // 0x80800228: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800228: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8080022C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800230: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800234: jal         0x80100094
    // 0x80800238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8080023C: addu        $t6, $v0, $s3
    ctx->r14 = ADD32(ctx->r2, ctx->r19);
    // 0x80800240: lb          $a0, 0x208($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X208);
    // 0x80800244: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80800248: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8080024C: bnel        $a1, $a0, L_8080034C
    if (ctx->r5 != ctx->r4) {
        // 0x80800250: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8080034C;
    }
    goto skip_0;
    // 0x80800250: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x80800254: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x80800258: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    // 0x8080025C: bnel        $s3, $v1, L_808002C0
    if (ctx->r19 != ctx->r3) {
        // 0x80800260: addiu       $s2, $zero, 0x18
        ctx->r18 = ADD32(0, 0X18);
            goto L_808002C0;
    }
    goto skip_1;
    // 0x80800260: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    skip_1:
    // 0x80800264: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800268: mflo        $a3
    ctx->r7 = lo;
    // 0x8080026C: addu        $t7, $v0, $a3
    ctx->r15 = ADD32(ctx->r2, ctx->r7);
    // 0x80800270: lb          $t8, 0x0($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X0);
    // 0x80800274: addu        $t9, $s1, $a3
    ctx->r25 = ADD32(ctx->r17, ctx->r7);
    // 0x80800278: bnel        $t8, $zero, L_808002C0
    if (ctx->r24 != 0) {
        // 0x8080027C: addiu       $s2, $zero, 0x18
        ctx->r18 = ADD32(0, 0X18);
            goto L_808002C0;
    }
    goto skip_2;
    // 0x8080027C: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    skip_2:
    // 0x80800280: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800284: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800288: addiu       $a1, $zero, 0x2E4
    ctx->r5 = ADD32(0, 0X2E4);
    // 0x8080028C: swc1        $f4, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f4.u32l;
    // 0x80800290: jal         0x808007E4
    // 0x80800294: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_2;
    // 0x80800294: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    after_2:
    // 0x80800298: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x8080029C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808002A0: multu       $t0, $s2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808002A4: mflo        $t1
    ctx->r9 = lo;
    // 0x808002A8: addu        $a1, $s1, $t1
    ctx->r5 = ADD32(ctx->r17, ctx->r9);
    // 0x808002AC: jal         0x808035C4
    // 0x808002B0: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_808035C4_chjiggygamenew(rdram, ctx);
        goto after_3;
    // 0x808002B0: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_3:
    // 0x808002B4: b           L_8080034C
    // 0x808002B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080034C;
    // 0x808002B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808002BC: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
L_808002C0:
    // 0x808002C0: multu       $s3, $s2
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808002C4: mflo        $t2
    ctx->r10 = lo;
    // 0x808002C8: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x808002CC: lhu         $t4, 0x4($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X4);
    // 0x808002D0: beql        $s2, $t4, L_8080034C
    if (ctx->r18 == ctx->r12) {
        // 0x808002D4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8080034C;
    }
    goto skip_3;
    // 0x808002D4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_3:
    // 0x808002D8: bnel        $a1, $a0, L_8080034C
    if (ctx->r5 != ctx->r4) {
        // 0x808002DC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8080034C;
    }
    goto skip_4;
    // 0x808002DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_4:
    // 0x808002E0: multu       $v1, $s2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x808002E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808002E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808002EC: addiu       $a1, $zero, 0x194
    ctx->r5 = ADD32(0, 0X194);
    // 0x808002F0: mflo        $t5
    ctx->r13 = lo;
    // 0x808002F4: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x808002F8: swc1        $f6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f6.u32l;
    // 0x808002FC: jal         0x808007E4
    // 0x80800300: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    func_808007E4_chjiggygamenew(rdram, ctx);
        goto after_4;
    // 0x80800300: lw          $a2, 0x24($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X24);
    after_4:
    // 0x80800304: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80800308: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8080030C: multu       $t7, $s2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800310: mflo        $t8
    ctx->r24 = lo;
    // 0x80800314: addu        $a1, $s1, $t8
    ctx->r5 = ADD32(ctx->r17, ctx->r24);
    // 0x80800318: jal         0x808035C4
    // 0x8080031C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_808035C4_chjiggygamenew(rdram, ctx);
        goto after_5;
    // 0x8080031C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_5:
    // 0x80800320: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80800324: addu        $t3, $s1, $s3
    ctx->r11 = ADD32(ctx->r17, ctx->r19);
    // 0x80800328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8080032C: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80800330: mflo        $t0
    ctx->r8 = lo;
    // 0x80800334: addu        $t1, $s1, $t0
    ctx->r9 = ADD32(ctx->r17, ctx->r8);
    // 0x80800338: sb          $s3, 0x3($t1)
    MEM_B(0X3, ctx->r9) = ctx->r19;
    // 0x8080033C: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80800340: b           L_8080034C
    // 0x80800344: sb          $t2, 0x208($t3)
    MEM_B(0X208, ctx->r11) = ctx->r10;
        goto L_8080034C;
    // 0x80800344: sb          $t2, 0x208($t3)
    MEM_B(0X208, ctx->r11) = ctx->r10;
    // 0x80800348: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8080034C:
    // 0x8080034C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800350: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800354: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800358: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8080035C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800360: jr          $ra
    // 0x80800364: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800364: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80802264_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802264: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80802268: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080226C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80802270: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80802274: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1840, 0X4E08) << 16);
    // 0x80802278: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080227C: addiu       $t6, $t6, 0x4E08
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1840, 0X4E08));
    // 0x80802280: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80802284: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80802288: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080228C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80802290: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80802294: jal         0x800BABB8
    // 0x80802298: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_0;
    // 0x80802298: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8080229C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x808022A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808022A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808022A8: bne         $t7, $at, L_808022B8
    if (ctx->r15 != ctx->r1) {
        // 0x808022AC: addiu       $a1, $zero, 0x67A
        ctx->r5 = ADD32(0, 0X67A);
            goto L_808022B8;
    }
    // 0x808022AC: addiu       $a1, $zero, 0x67A
    ctx->r5 = ADD32(0, 0X67A);
    // 0x808022B0: b           L_808022B8
    // 0x808022B4: addiu       $a1, $zero, 0x679
    ctx->r5 = ADD32(0, 0X679);
        goto L_808022B8;
    // 0x808022B4: addiu       $a1, $zero, 0x679
    ctx->r5 = ADD32(0, 0X679);
L_808022B8:
    // 0x808022B8: jal         0x800BA670
    // 0x808022BC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800BA670(rdram, ctx);
        goto after_1;
    // 0x808022BC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x808022C0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808022C4: jal         0x800BA22C
    // 0x808022C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_800BA22C(rdram, ctx);
        goto after_2;
    // 0x808022C8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x808022CC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1840, 0X4C74) << 16);
    // 0x808022D0: addiu       $a2, $a2, 0x4C74
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1840, 0X4C74));
    // 0x808022D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808022D8: jal         0x80089D18
    // 0x808022DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808022DC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x808022E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808022E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808022E8: jr          $ra
    // 0x808022EC: nop

    return;
    // 0x808022EC: nop

;}
RECOMP_FUNC void _cothemedll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087860: syscall     635
    recomp_syscall_handler(rdram, ctx, 0x80087860);
    return;
    // 0x80087864: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _indrv_audio_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F98: syscall     753
    recomp_syscall_handler(rdram, ctx, 0x80088F98);
    return;
    // 0x80088F9C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8080147C_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080147C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801480: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801484: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801488: lui         $a1, 0x3E23
    ctx->r5 = S32(0X3E23 << 16);
    // 0x8080148C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801490: jal         0x8008CB10
    // 0x80801494: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80801494: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    after_0:
    // 0x80801498: beq         $v0, $zero, L_808014B4
    if (ctx->r2 == 0) {
        // 0x8080149C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808014B4;
    }
    // 0x8080149C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014A0: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x808014A4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808014A8: addiu       $a1, $zero, 0x632
    ctx->r5 = ADD32(0, 0X632);
    // 0x808014AC: jal         0x8009DB04
    // 0x808014B0: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    func_8009DB04(rdram, ctx);
        goto after_1;
    // 0x808014B0: addiu       $a3, $zero, 0x2EE0
    ctx->r7 = ADD32(0, 0X2EE0);
    after_1:
L_808014B4:
    // 0x808014B4: lui         $a1, 0x3EC7
    ctx->r5 = S32(0X3EC7 << 16);
    // 0x808014B8: ori         $a1, $a1, 0xAE14
    ctx->r5 = ctx->r5 | 0XAE14;
    // 0x808014BC: jal         0x8008CB10
    // 0x808014C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x808014C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808014C4: beq         $v0, $zero, L_808014E0
    if (ctx->r2 == 0) {
        // 0x808014C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808014E0;
    }
    // 0x808014C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014CC: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808014D0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808014D4: addiu       $a1, $zero, 0x632
    ctx->r5 = ADD32(0, 0X632);
    // 0x808014D8: jal         0x8009DB04
    // 0x808014DC: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    func_8009DB04(rdram, ctx);
        goto after_3;
    // 0x808014DC: addiu       $a3, $zero, 0x3E80
    ctx->r7 = ADD32(0, 0X3E80);
    after_3:
L_808014E0:
    // 0x808014E0: lui         $a1, 0x3F3D
    ctx->r5 = S32(0X3F3D << 16);
    // 0x808014E4: ori         $a1, $a1, 0x70A4
    ctx->r5 = ctx->r5 | 0X70A4;
    // 0x808014E8: jal         0x8008CB10
    // 0x808014EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x808014EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808014F0: beq         $v0, $zero, L_8080150C
    if (ctx->r2 == 0) {
        // 0x808014F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080150C;
    }
    // 0x808014F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808014F8: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x808014FC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801500: addiu       $a1, $zero, 0x632
    ctx->r5 = ADD32(0, 0X632);
    // 0x80801504: jal         0x8009DB04
    // 0x80801508: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DB04(rdram, ctx);
        goto after_5;
    // 0x80801508: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_5:
L_8080150C:
    // 0x8080150C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801510: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801514: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801518: jr          $ra
    // 0x8080151C: nop

    return;
    // 0x8080151C: nop

;}
RECOMP_FUNC void _glintrosyncDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800885E8: syscall     695
    recomp_syscall_handler(rdram, ctx, 0x800885E8);
    return;
    // 0x800885EC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80801E60_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801E64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801E68: jal         0x80800ECC
    // 0x80801E6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstnt_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801E6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801E70: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801E74: jal         0x800845D8
    // 0x80801E78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _babounce_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80801E78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80801E7C: lui         $a2, 0x3ED0
    ctx->r6 = S32(0X3ED0 << 16);
    // 0x80801E80: ori         $a2, $a2, 0xFF97
    ctx->r6 = ctx->r6 | 0XFF97;
    // 0x80801E84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801E88: jal         0x800845E0
    // 0x80801E8C: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    _babounce_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x80801E8C: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    after_2:
    // 0x80801E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801E98: jr          $ra
    // 0x80801E9C: nop

    return;
    // 0x80801E9C: nop

;}
RECOMP_FUNC void func_800BA75C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA75C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA764: jal         0x800EE940
    // 0x800BA768: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    func_800EE940(rdram, ctx);
        goto after_0;
    // 0x800BA768: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    after_0:
    // 0x800BA76C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA774: jr          $ra
    // 0x800BA778: nop

    return;
    // 0x800BA778: nop

;}
RECOMP_FUNC void _chbadbeehive_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D10: syscall     447
    recomp_syscall_handler(rdram, ctx, 0x80086D10);
    return;
    // 0x80086D14: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800280_gcboundDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800280: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800288: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080028C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800290: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80800294: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800298: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8080029C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x808002A0: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x808002A4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808002A8: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x808002AC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x808002B0: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x808002B4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x808002B8: jal         0x8001B208
    // 0x808002BC: sll         $a1, $t9, 2
    ctx->r5 = S32(ctx->r25 << 2);
    heap_realloc(rdram, ctx);
        goto after_0;
    // 0x808002BC: sll         $a1, $t9, 2
    ctx->r5 = S32(ctx->r25 << 2);
    after_0:
    // 0x808002C0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x808002C4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808002C8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x808002CC: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x808002D0: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x808002D4: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x808002D8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x808002DC: addu        $v1, $t2, $v0
    ctx->r3 = ADD32(ctx->r10, ctx->r2);
    // 0x808002E0: lw          $a1, -0x1C($v1)
    ctx->r5 = MEM_W(ctx->r3, -0X1C);
    // 0x808002E4: addiu       $v1, $v1, -0x1C
    ctx->r3 = ADD32(ctx->r3, -0X1C);
    // 0x808002E8: addiu       $a0, $v1, 0x18
    ctx->r4 = ADD32(ctx->r3, 0X18);
    // 0x808002EC: srl         $t3, $a1, 9
    ctx->r11 = S32(U32(ctx->r5) >> 9);
    // 0x808002F0: sll         $t4, $t3, 9
    ctx->r12 = S32(ctx->r11 << 9);
    // 0x808002F4: xor         $t5, $t4, $a1
    ctx->r13 = ctx->r12 ^ ctx->r5;
    // 0x808002F8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x808002FC: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x80800300: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80800304: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800308: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8080030C: sb          $t9, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r25;
    // 0x80800310: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x80800314: jal         0x800B4290
    // 0x80800318: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800B4290(rdram, ctx);
        goto after_1;
    // 0x80800318: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8080031C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800320: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800328: jr          $ra
    // 0x8080032C: nop

    return;
    // 0x8080032C: nop

;}
RECOMP_FUNC void bsclaw_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800044: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800048: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080004C: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x80800050: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800054: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800058: jal         0x8008CCBC
    // 0x8080005C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_0;
    // 0x8080005C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x80800060: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800064: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080006C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800070: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800074: jal         0x8009FFD8
    // 0x80800078: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_1;
    // 0x80800078: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8080007C: jal         0x8009C990
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_getIdeal(rdram, ctx);
        goto after_2;
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800084: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800088: jal         0x8009B9C0
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_target_yaw(rdram, ctx);
        goto after_3;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: jal         0x8009B9B0
    // 0x80800098: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x80800098: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    after_4:
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: jal         0x80095774
    // 0x808000A4: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    baflag_clear(rdram, ctx);
        goto after_5;
    // 0x808000A4: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_5:
    // 0x808000A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000AC: jal         0x800A0CF4
    // 0x808000B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A0CF4(rdram, ctx);
        goto after_6;
    // 0x808000B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808000B4: jal         0x800C6E38
    // 0x808000B8: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_800C6E38(rdram, ctx);
        goto after_7;
    // 0x808000B8: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_7:
    // 0x808000BC: beq         $v0, $zero, L_808000D0
    if (ctx->r2 == 0) {
        // 0x808000C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000D0;
    }
    // 0x808000C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(140, 0X3E0) << 16);
    // 0x808000C8: b           L_808000D8
    // 0x808000CC: lwc1        $f0, 0x3E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(140, 0X3E0));
        goto L_808000D8;
    // 0x808000CC: lwc1        $f0, 0x3E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(140, 0X3E0));
L_808000D0:
    // 0x808000D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808000D4: nop

L_808000D8:
    // 0x808000D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808000DC: jal         0x80085338
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _batimer_set(rdram, ctx);
        goto after_8;
    // 0x808000E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808000E4: jal         0x8009E4AC
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009E4AC(rdram, ctx);
        goto after_9;
    // 0x808000E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808000EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808000F4: jal         0x8009E5A4
    // 0x808000F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8009E5A4(rdram, ctx);
        goto after_10;
    // 0x808000F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_10:
    // 0x808000FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800100: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800104: jal         0x8009E55C
    // 0x80800108: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_8009E55C(rdram, ctx);
        goto after_11;
    // 0x80800108: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_11:
    // 0x8080010C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800110: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800114: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void func_800E8144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8144: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800E8148: lw          $t6, -0x2A0C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2A0C);
    // 0x800E814C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8154: beq         $t6, $zero, L_800E816C
    if (ctx->r14 == 0) {
        // 0x800E8158: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800E816C;
    }
    // 0x800E8158: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E815C: lw          $a0, -0x2A10($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A10);
    // 0x800E8160: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x800E8164: jal         0x800A9828
    // 0x800E8168: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_800A9828(rdram, ctx);
        goto after_0;
    // 0x800E8168: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_0:
L_800E816C:
    // 0x800E816C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8174: jr          $ra
    // 0x800E8178: nop

    return;
    // 0x800E8178: nop

;}
RECOMP_FUNC void func_80800210_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800210: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80800214: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80800218: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8080021C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80800220: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80800224: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800228: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8080022C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800230: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800234: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800238: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080023C: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800240: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80800244: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x80800248: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8080024C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800250: addiu       $s0, $s2, 0x44
    ctx->r16 = ADD32(ctx->r18, 0X44);
    // 0x80800254: bc1fl       L_80800288
    if (!c1cs) {
        // 0x80800258: lui         $at, 0x3E80
        ctx->r1 = S32(0X3E80 << 16);
            goto L_80800288;
    }
    goto skip_0;
    // 0x80800258: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    skip_0:
    // 0x8080025C: jal         0x800EE7F8
    // 0x80800260: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800260: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80800264: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800268: jal         0x80105A9C
    // 0x8080026C: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    func_80105A9C(rdram, ctx);
        goto after_1;
    // 0x8080026C: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    after_1:
    // 0x80800270: jal         0x80105834
    // 0x80800274: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80105834(rdram, ctx);
        goto after_2;
    // 0x80800274: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x800EE7F8
    // 0x80800280: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800280: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80800284: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80800288:
    // 0x80800288: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8080028C: lui         $at, 0xBE80
    ctx->r1 = S32(0XBE80 << 16);
    // 0x80800290: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800294: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800298: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8080029C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x808002A0: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x808002A4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x808002A8: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x808002AC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_808002B0:
    // 0x808002B0: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x808002B4: jal         0x800DC178
    // 0x808002B8: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808002B8: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_4:
    // 0x808002BC: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808002C0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808002C4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x808002C8: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x808002CC: lwc1        $f2, 0x44($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X44);
    // 0x808002D0: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x808002D4: nop

    // 0x808002D8: bc1fl       L_808002EC
    if (!c1cs) {
        // 0x808002DC: c.lt.s      $f22, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
            goto L_808002EC;
    }
    goto skip_1;
    // 0x808002DC: c.lt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
    skip_1:
    // 0x808002E0: b           L_80800308
    // 0x808002E4: swc1        $f20, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f20.u32l;
        goto L_80800308;
    // 0x808002E4: swc1        $f20, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f20.u32l;
    // 0x808002E8: c.lt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
L_808002EC:
    // 0x808002EC: nop

    // 0x808002F0: bc1fl       L_80800304
    if (!c1cs) {
        // 0x808002F4: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80800304;
    }
    goto skip_2;
    // 0x808002F4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_2:
    // 0x808002F8: b           L_80800304
    // 0x808002FC: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
        goto L_80800304;
    // 0x808002FC: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x80800300: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80800304:
    // 0x80800304: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
L_80800308:
    // 0x80800308: bne         $s1, $s2, L_808002B0
    if (ctx->r17 != ctx->r18) {
        // 0x8080030C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808002B0;
    }
    // 0x8080030C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80800310: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80800314: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800318: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8080031C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800320: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800324: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800328: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8080032C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80800330: jr          $ra
    // 0x80800334: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800334: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_808013D0_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808013D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808013D8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808013DC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808013E0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808013E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808013E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808013EC: jal         0x80100094
    // 0x808013F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808013F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808013F4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808013F8: jal         0x800D211C
    // 0x808013FC: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    func_800D211C(rdram, ctx);
        goto after_1;
    // 0x808013FC: addiu       $a0, $zero, 0x8A
    ctx->r4 = ADD32(0, 0X8A);
    after_1:
    // 0x80801400: bne         $v0, $zero, L_80801434
    if (ctx->r2 != 0) {
        // 0x80801404: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801434;
    }
    // 0x80801404: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801408: addiu       $a1, $zero, 0x8A
    ctx->r5 = ADD32(0, 0X8A);
    // 0x8080140C: jal         0x800D2054
    // 0x80801410: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800D2054(rdram, ctx);
        goto after_2;
    // 0x80801410: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80801414: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801418: addiu       $a1, $zero, 0x8B
    ctx->r5 = ADD32(0, 0X8B);
    // 0x8080141C: jal         0x800D2054
    // 0x80801420: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800D2054(rdram, ctx);
        goto after_3;
    // 0x80801420: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x80801424: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801428: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x8080142C: jal         0x800D2054
    // 0x80801430: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800D2054(rdram, ctx);
        goto after_4;
    // 0x80801430: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
L_80801434:
    // 0x80801434: jal         0x800EA05C
    // 0x80801438: nop

    func_800EA05C(rdram, ctx);
        goto after_5;
    // 0x80801438: nop

    after_5:
    // 0x8080143C: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x80801440: beq         $v0, $at, L_8080146C
    if (ctx->r2 == ctx->r1) {
        // 0x80801444: addiu       $at, $zero, 0xDF
        ctx->r1 = ADD32(0, 0XDF);
            goto L_8080146C;
    }
    // 0x80801444: addiu       $at, $zero, 0xDF
    ctx->r1 = ADD32(0, 0XDF);
    // 0x80801448: beq         $v0, $at, L_808014B4
    if (ctx->r2 == ctx->r1) {
        // 0x8080144C: addiu       $at, $zero, 0xE0
        ctx->r1 = ADD32(0, 0XE0);
            goto L_808014B4;
    }
    // 0x8080144C: addiu       $at, $zero, 0xE0
    ctx->r1 = ADD32(0, 0XE0);
    // 0x80801450: beq         $v0, $at, L_80801500
    if (ctx->r2 == ctx->r1) {
        // 0x80801454: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_80801500;
    }
    // 0x80801454: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80801458: addiu       $at, $zero, 0x186
    ctx->r1 = ADD32(0, 0X186);
    // 0x8080145C: beq         $v0, $at, L_8080154C
    if (ctx->r2 == ctx->r1) {
        // 0x80801460: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8080154C;
    }
    // 0x80801460: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80801464: b           L_80801598
    // 0x80801468: lbu         $t3, 0xC5($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0XC5);
        goto L_80801598;
    // 0x80801468: lbu         $t3, 0xC5($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0XC5);
L_8080146C:
    // 0x8080146C: lbu         $t6, 0x79($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X79);
    // 0x80801470: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80801474: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    // 0x80801478: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x8080147C: sb          $t7, 0x79($s2)
    MEM_B(0X79, ctx->r18) = ctx->r15;
    // 0x80801480: jal         0x800DA298
    // 0x80801484: sb          $t8, 0xC5($s3)
    MEM_B(0XC5, ctx->r19) = ctx->r24;
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80801484: sb          $t8, 0xC5($s3)
    MEM_B(0XC5, ctx->r19) = ctx->r24;
    after_6:
    // 0x80801488: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080148C: jal         0x808012C8
    // 0x80801490: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808012C8_chdodgemcontrol(rdram, ctx);
        goto after_7;
    // 0x80801490: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80801494: lbu         $t9, 0x79($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X79);
    // 0x80801498: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(1752, 0X4D00) << 16);
    // 0x8080149C: srl         $t0, $t9, 4
    ctx->r8 = S32(U32(ctx->r25) >> 4);
    // 0x808014A0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x808014A4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x808014A8: lw          $t2, 0x4D00($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(1752, 0X4D00));
    // 0x808014AC: b           L_80801594
    // 0x808014B0: sb          $t2, 0xC2($s3)
    MEM_B(0XC2, ctx->r19) = ctx->r10;
        goto L_80801594;
    // 0x808014B0: sb          $t2, 0xC2($s3)
    MEM_B(0XC2, ctx->r19) = ctx->r10;
L_808014B4:
    // 0x808014B4: lbu         $t3, 0x79($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X79);
    // 0x808014B8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x808014BC: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    // 0x808014C0: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x808014C4: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x808014C8: sb          $t5, 0x79($s2)
    MEM_B(0X79, ctx->r18) = ctx->r13;
    // 0x808014CC: jal         0x800DA298
    // 0x808014D0: sb          $t6, 0xC5($s3)
    MEM_B(0XC5, ctx->r19) = ctx->r14;
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x808014D0: sb          $t6, 0xC5($s3)
    MEM_B(0XC5, ctx->r19) = ctx->r14;
    after_8:
    // 0x808014D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808014D8: jal         0x808012C8
    // 0x808014DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808012C8_chdodgemcontrol(rdram, ctx);
        goto after_9;
    // 0x808014DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x808014E0: lbu         $t7, 0x79($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X79);
    // 0x808014E4: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1752, 0X4D00) << 16);
    // 0x808014E8: srl         $t8, $t7, 4
    ctx->r24 = S32(U32(ctx->r15) >> 4);
    // 0x808014EC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808014F0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x808014F4: lw          $t0, 0x4D00($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(1752, 0X4D00));
    // 0x808014F8: b           L_80801594
    // 0x808014FC: sb          $t0, 0xC2($s3)
    MEM_B(0XC2, ctx->r19) = ctx->r8;
        goto L_80801594;
    // 0x808014FC: sb          $t0, 0xC2($s3)
    MEM_B(0XC2, ctx->r19) = ctx->r8;
L_80801500:
    // 0x80801500: lbu         $t1, 0x79($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X79);
    // 0x80801504: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80801508: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080150C: andi        $t2, $t1, 0xFF0F
    ctx->r10 = ctx->r9 & 0XFF0F;
    // 0x80801510: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x80801514: sb          $t3, 0x79($s2)
    MEM_B(0X79, ctx->r18) = ctx->r11;
    // 0x80801518: jal         0x800D0A9C
    // 0x8080151C: sb          $t4, 0xC5($s3)
    MEM_B(0XC5, ctx->r19) = ctx->r12;
    func_800D0A9C(rdram, ctx);
        goto after_10;
    // 0x8080151C: sb          $t4, 0xC5($s3)
    MEM_B(0XC5, ctx->r19) = ctx->r12;
    after_10:
    // 0x80801520: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80801524: jal         0x808012C8
    // 0x80801528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808012C8_chdodgemcontrol(rdram, ctx);
        goto after_11;
    // 0x80801528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x8080152C: lbu         $t5, 0x79($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X79);
    // 0x80801530: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(1752, 0X4D00) << 16);
    // 0x80801534: srl         $t6, $t5, 4
    ctx->r14 = S32(U32(ctx->r13) >> 4);
    // 0x80801538: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8080153C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80801540: lw          $t8, 0x4D00($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(1752, 0X4D00));
    // 0x80801544: b           L_80801594
    // 0x80801548: sb          $t8, 0xC2($s3)
    MEM_B(0XC2, ctx->r19) = ctx->r24;
        goto L_80801594;
    // 0x80801548: sb          $t8, 0xC2($s3)
    MEM_B(0XC2, ctx->r19) = ctx->r24;
L_8080154C:
    // 0x8080154C: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
L_80801550:
    // 0x80801550: jal         0x800F6438
    // 0x80801554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800F6438(rdram, ctx);
        goto after_12;
    // 0x80801554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80801558: beq         $v0, $zero, L_80801568
    if (ctx->r2 == 0) {
        // 0x8080155C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801568;
    }
    // 0x8080155C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801560: jal         0x800F4CEC
    // 0x80801564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F4CEC(rdram, ctx);
        goto after_13;
    // 0x80801564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_80801568:
    // 0x80801568: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080156C: bne         $s0, $s1, L_80801550
    if (ctx->r16 != ctx->r17) {
        // 0x80801570: nop
    
            goto L_80801550;
    }
    // 0x80801570: nop

    // 0x80801574: lbu         $t9, 0x79($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X79);
    // 0x80801578: andi        $t0, $t9, 0xFF0F
    ctx->r8 = ctx->r25 & 0XFF0F;
    // 0x8080157C: ori         $t1, $t0, 0x30
    ctx->r9 = ctx->r8 | 0X30;
    // 0x80801580: jal         0x80088368
    // 0x80801584: sb          $t1, 0x79($s2)
    MEM_B(0X79, ctx->r18) = ctx->r9;
    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x80801584: sb          $t1, 0x79($s2)
    MEM_B(0X79, ctx->r18) = ctx->r9;
    after_14:
    // 0x80801588: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8080158C: sb          $v0, 0xC2($s3)
    MEM_B(0XC2, ctx->r19) = ctx->r2;
    // 0x80801590: sb          $t2, 0xC5($s3)
    MEM_B(0XC5, ctx->r19) = ctx->r10;
L_80801594:
    // 0x80801594: lbu         $t3, 0xC5($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0XC5);
L_80801598:
    // 0x80801598: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8080159C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808015A0: slti        $at, $t3, 0xB
    ctx->r1 = SIGNED(ctx->r11) < 0XB ? 1 : 0;
    // 0x808015A4: bne         $at, $zero, L_808015B0
    if (ctx->r1 != 0) {
        // 0x808015A8: nop
    
            goto L_808015B0;
    }
    // 0x808015A8: nop

    // 0x808015AC: sb          $t4, 0xC5($s3)
    MEM_B(0XC5, ctx->r19) = ctx->r12;
L_808015B0:
    // 0x808015B0: jal         0x808017F0
    // 0x808015B4: sb          $zero, 0xC3($s3)
    MEM_B(0XC3, ctx->r19) = 0;
    func_808017F0_chdodgemcontrol(rdram, ctx);
        goto after_15;
    // 0x808015B4: sb          $zero, 0xC3($s3)
    MEM_B(0XC3, ctx->r19) = 0;
    after_15:
    // 0x808015B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808015BC: jal         0x800BF744
    // 0x808015C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800BF744(rdram, ctx);
        goto after_16;
    // 0x808015C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808015C4: jal         0x80801344
    // 0x808015C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80801344_chdodgemcontrol(rdram, ctx);
        goto after_17;
    // 0x808015C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_17:
    // 0x808015CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808015D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808015D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808015D8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808015DC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808015E0: jr          $ra
    // 0x808015E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808015E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8080019C_bsmumsplat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001A4: jal         0x8008E95C
    // 0x808001A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8008E95C(rdram, ctx);
        goto after_0;
    // 0x808001A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001AC: jal         0x8009BD88
    // 0x808001B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8009BD88(rdram, ctx);
        goto after_1;
    // 0x808001B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808001B4: jal         0x80083800
    // 0x808001B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsmum_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x808001B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808001BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C4: jr          $ra
    // 0x808001C8: nop

    return;
    // 0x808001C8: nop

;}
RECOMP_FUNC void func_80800344_chpickups(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800348: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080034C: jal         0x80101FDC
    // 0x80800350: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800350: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800358: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080035C: jr          $ra
    // 0x80800360: nop

    return;
    // 0x80800360: nop

;}
RECOMP_FUNC void func_808011EC_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808011F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808011F8: jal         0x8009E6EC
    // 0x808011FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8009E6EC(rdram, ctx);
        goto after_0;
    // 0x808011FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801200: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80801204: beq         $v0, $at, L_80801250
    if (ctx->r2 == ctx->r1) {
        // 0x80801208: addiu       $at, $zero, 0x86
        ctx->r1 = ADD32(0, 0X86);
            goto L_80801250;
    }
    // 0x80801208: addiu       $at, $zero, 0x86
    ctx->r1 = ADD32(0, 0X86);
    // 0x8080120C: beq         $v0, $at, L_808012B0
    if (ctx->r2 == ctx->r1) {
        // 0x80801210: addiu       $at, $zero, 0x87
        ctx->r1 = ADD32(0, 0X87);
            goto L_808012B0;
    }
    // 0x80801210: addiu       $at, $zero, 0x87
    ctx->r1 = ADD32(0, 0X87);
    // 0x80801214: beq         $v0, $at, L_80801230
    if (ctx->r2 == ctx->r1) {
        // 0x80801218: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801230;
    }
    // 0x80801218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080121C: addiu       $at, $zero, 0x94
    ctx->r1 = ADD32(0, 0X94);
    // 0x80801220: beql        $v0, $at, L_80801290
    if (ctx->r2 == ctx->r1) {
        // 0x80801224: lw          $t6, 0x15C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X15C);
            goto L_80801290;
    }
    goto skip_0;
    // 0x80801224: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    skip_0:
    // 0x80801228: b           L_808012B4
    // 0x8080122C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808012B4;
    // 0x8080122C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801230:
    // 0x80801230: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80801234: jal         0x80085338
    // 0x80801238: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    _batimer_set(rdram, ctx);
        goto after_1;
    // 0x80801238: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_1:
    // 0x8080123C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801240: jal         0x8009E830
    // 0x80801244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_2;
    // 0x80801244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80801248: b           L_808012B4
    // 0x8080124C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808012B4;
    // 0x8080124C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801250:
    // 0x80801250: jal         0x80099A58
    // 0x80801254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80099A58(rdram, ctx);
        goto after_3;
    // 0x80801254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801258: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080125C: bnel        $v0, $at, L_808012B4
    if (ctx->r2 != ctx->r1) {
        // 0x80801260: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808012B4;
    }
    goto skip_1;
    // 0x80801260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80801264: jal         0x800F9BA4
    // 0x80801268: nop

    func_800F9BA4(rdram, ctx);
        goto after_4;
    // 0x80801268: nop

    after_4:
    // 0x8080126C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801270: jal         0x80801134
    // 0x80801274: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801134_bsbabykaz(rdram, ctx);
        goto after_5;
    // 0x80801274: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80801278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080127C: jal         0x8009E830
    // 0x80801280: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E830(rdram, ctx);
        goto after_6;
    // 0x80801280: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x80801284: b           L_808012B4
    // 0x80801288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808012B4;
    // 0x80801288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080128C: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
L_80801290:
    // 0x80801290: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801294: bnel        $t6, $at, L_808012B4
    if (ctx->r14 != ctx->r1) {
        // 0x80801298: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808012B4;
    }
    goto skip_2;
    // 0x80801298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8080129C: jal         0x800F9B54
    // 0x808012A0: nop

    func_800F9B54(rdram, ctx);
        goto after_7;
    // 0x808012A0: nop

    after_7:
    // 0x808012A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012A8: jal         0x80801134
    // 0x808012AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80801134_bsbabykaz(rdram, ctx);
        goto after_8;
    // 0x808012AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
L_808012B0:
    // 0x808012B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808012B4:
    // 0x808012B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808012B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808012BC: jr          $ra
    // 0x808012C0: nop

    return;
    // 0x808012C0: nop

;}
RECOMP_FUNC void func_800F8200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8200: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F8204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F8208: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F820C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F8210: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F8214: jal         0x800F4524
    // 0x800F8218: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_800F4524(rdram, ctx);
        goto after_0;
    // 0x800F8218: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F821C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F8220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F8224: jr          $ra
    // 0x800F8228: nop

    return;
    // 0x800F8228: nop

;}
RECOMP_FUNC void func_800FE8EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE8EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FE8F0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800FE8F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FE8F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FE8FC: jal         0x80087878
    // 0x800FE900: addiu       $a0, $a0, 0x59C0
    ctx->r4 = ADD32(ctx->r4, 0X59C0);
    _cothemedll_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800FE900: addiu       $a0, $a0, 0x59C0
    ctx->r4 = ADD32(ctx->r4, 0X59C0);
    after_0:
    // 0x800FE904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FE908: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FE90C: jr          $ra
    // 0x800FE910: nop

    return;
    // 0x800FE910: nop

;}
RECOMP_FUNC void gctransitionDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008E0: lbu         $v1, 0x1C($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1C);
    // 0x808008E4: xori        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 ^ 0X4;
    // 0x808008E8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808008EC: bne         $v0, $zero, L_8080094C
    if (ctx->r2 != 0) {
        // 0x808008F0: nop
    
            goto L_8080094C;
    }
    // 0x808008F0: nop

    // 0x808008F4: xori        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 ^ 0X2;
    // 0x808008F8: bnel        $v0, $zero, L_80800914
    if (ctx->r2 != 0) {
        // 0x808008FC: xori        $v0, $v1, 0x6
        ctx->r2 = ctx->r3 ^ 0X6;
            goto L_80800914;
    }
    goto skip_0;
    // 0x808008FC: xori        $v0, $v1, 0x6
    ctx->r2 = ctx->r3 ^ 0X6;
    skip_0:
    // 0x80800900: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80800904: slti        $t6, $v0, 0x2
    ctx->r14 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80800908: bne         $t6, $zero, L_8080094C
    if (ctx->r14 != 0) {
        // 0x8080090C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8080094C;
    }
    // 0x8080090C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80800910: xori        $v0, $v1, 0x6
    ctx->r2 = ctx->r3 ^ 0X6;
L_80800914:
    // 0x80800914: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800918: bne         $v0, $zero, L_8080094C
    if (ctx->r2 != 0) {
        // 0x8080091C: nop
    
            goto L_8080094C;
    }
    // 0x8080091C: nop

    // 0x80800920: xori        $v0, $v1, 0x9
    ctx->r2 = ctx->r3 ^ 0X9;
    // 0x80800924: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800928: bne         $v0, $zero, L_8080094C
    if (ctx->r2 != 0) {
        // 0x8080092C: nop
    
            goto L_8080094C;
    }
    // 0x8080092C: nop

    // 0x80800930: xori        $v0, $v1, 0x7
    ctx->r2 = ctx->r3 ^ 0X7;
    // 0x80800934: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800938: beq         $v0, $zero, L_8080094C
    if (ctx->r2 == 0) {
        // 0x8080093C: nop
    
            goto L_8080094C;
    }
    // 0x8080093C: nop

    // 0x80800940: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80800944: slti        $t7, $v0, 0x2
    ctx->r15 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80800948: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8080094C:
    // 0x8080094C: jr          $ra
    // 0x80800950: nop

    return;
    // 0x80800950: nop

;}
RECOMP_FUNC void func_800BED50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BED50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BED54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BED58: jal         0x800BE600
    // 0x800BED5C: addiu       $a1, $zero, 0x1F00
    ctx->r5 = ADD32(0, 0X1F00);
    func_800BE600(rdram, ctx);
        goto after_0;
    // 0x800BED5C: addiu       $a1, $zero, 0x1F00
    ctx->r5 = ADD32(0, 0X1F00);
    after_0:
    // 0x800BED60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BED64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BED68: jr          $ra
    // 0x800BED6C: nop

    return;
    // 0x800BED6C: nop

;}
RECOMP_FUNC void _subaddieDll_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4E0: syscall     843
    recomp_syscall_handler(rdram, ctx, 0x8008A4E0);
    return;
    // 0x8008A4E4: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void fxleaves_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800454: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080045C: jal         0x80800288
    // 0x80800460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800288_fxleaves(rdram, ctx);
        goto after_0;
    // 0x80800460: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080046C: jr          $ra
    // 0x80800470: nop

    return;
    // 0x80800470: nop

;}
RECOMP_FUNC void func_80017534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001753C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80017540: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80017544: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80017548: jal         0x80017778
    // 0x8001754C: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    func_80017778(rdram, ctx);
        goto after_0;
    // 0x8001754C: lbu         $a0, 0x1B($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1B);
    after_0:
    // 0x80017550: bne         $v0, $zero, L_80017590
    if (ctx->r2 != 0) {
        // 0x80017554: lbu         $t6, 0x1B($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1B);
            goto L_80017590;
    }
    // 0x80017554: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x80017558: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001755C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80017560: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80017564: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80017568: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001756C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80017570: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80017574: lui         $t9, 0x8008
    ctx->r25 = S32(0X8008 << 16);
    // 0x80017578: addiu       $t9, $t9, -0x6060
    ctx->r25 = ADD32(ctx->r25, -0X6060);
    // 0x8001757C: addiu       $t8, $t7, 0x1E0
    ctx->r24 = ADD32(ctx->r15, 0X1E0);
    // 0x80017580: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x80017584: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80017588: jal         0x80025FE0
    // 0x8001758C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_80025FE0(rdram, ctx);
        goto after_1;
    // 0x8001758C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
L_80017590:
    // 0x80017590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017598: jr          $ra
    // 0x8001759C: nop

    return;
    // 0x8001759C: nop

;}
RECOMP_FUNC void choildrill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010B4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2412, 0X14A8) << 16);
    // 0x808010B8: jr          $ra
    // 0x808010BC: addiu       $v0, $v0, 0x14A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2412, 0X14A8));
    return;
    // 0x808010BC: addiu       $v0, $v0, 0x14A8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2412, 0X14A8));
;}
RECOMP_FUNC void bafly_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080010C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800110: lw          $t6, 0x8C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8C);
    // 0x80800114: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80800118: lbu         $a1, 0x9($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X9);
    // 0x8080011C: beq         $a1, $zero, L_80800138
    if (ctx->r5 == 0) {
        // 0x80800120: andi        $a0, $a1, 0xFF
        ctx->r4 = ctx->r5 & 0XFF;
            goto L_80800138;
    }
    // 0x80800120: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80800124: jal         0x800C2FDC
    // 0x80800128: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x80800128: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080012C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800130: lw          $t7, 0x8C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8C);
    // 0x80800134: sb          $zero, 0x9($t7)
    MEM_B(0X9, ctx->r15) = 0;
L_80800138:
    // 0x80800138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080013C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800140: jr          $ra
    // 0x80800144: nop

    return;
    // 0x80800144: nop

;}
RECOMP_FUNC void chcoderoombits_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808009F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009FC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80800A00: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800A04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800A08: jal         0x80089C30
    // 0x80800A0C: addiu       $a0, $zero, 0x3CE
    ctx->r4 = ADD32(0, 0X3CE);
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800A0C: addiu       $a0, $zero, 0x3CE
    ctx->r4 = ADD32(0, 0X3CE);
    after_0:
    // 0x80800A10: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800A14: lhu         $t6, 0x72($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X72);
    // 0x80800A18: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800A1C: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800A20: bnel        $t7, $at, L_80800B34
    if (ctx->r15 != ctx->r1) {
        // 0x80800A24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B34;
    }
    goto skip_0;
    // 0x80800A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800A28: jal         0x800BEC10
    // 0x80800A2C: nop

    func_800BEC10(rdram, ctx);
        goto after_1;
    // 0x80800A2C: nop

    after_1:
    // 0x80800A30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A34: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800A38: jal         0x800DBEFC
    // 0x80800A3C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    func_800DBEFC(rdram, ctx);
        goto after_2;
    // 0x80800A3C: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_2:
    // 0x80800A40: lui         $at, 0x43FF
    ctx->r1 = S32(0X43FF << 16);
    // 0x80800A44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800A48: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1172, 0X114C) << 16);
    // 0x80800A4C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800A50: lwc1        $f16, 0x114C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1172, 0X114C));
    // 0x80800A54: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800A58: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800A5C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80800A60: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80800A64: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800A68: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80800A6C: jal         0x800EC398
    // 0x80800A70: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    func_800EC398(rdram, ctx);
        goto after_3;
    // 0x80800A70: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80800A74: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800A78: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800A7C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800A80: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1172, 0X1150) << 16);
    // 0x80800A84: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800A88: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80800A8C: lwc1        $f0, 0x1150($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1172, 0X1150));
    // 0x80800A90: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800A94: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800A98: nop

    // 0x80800A9C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800AA0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800AA4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800AA8: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80800AAC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80800AB0: bltz        $v1, L_80800B30
    if (SIGNED(ctx->r3) < 0) {
        // 0x80800AB4: slti        $at, $v1, 0x6
        ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
            goto L_80800B30;
    }
    // 0x80800AB4: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80800AB8: beql        $at, $zero, L_80800B34
    if (ctx->r1 == 0) {
        // 0x80800ABC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800B34;
    }
    goto skip_1;
    // 0x80800ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800AC0: bltz        $v0, L_80800B30
    if (SIGNED(ctx->r2) < 0) {
        // 0x80800AC4: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_80800B30;
    }
    // 0x80800AC4: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80800AC8: beq         $at, $zero, L_80800B30
    if (ctx->r1 == 0) {
        // 0x80800ACC: lui         $t0, 0x8080
        ctx->r8 = S32(RELOC_HI16(1172, 0X11B8) << 16);
            goto L_80800B30;
    }
    // 0x80800ACC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(1172, 0X11B8) << 16);
    // 0x80800AD0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80800AD4: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80800AD8: addiu       $t0, $t0, 0x11B8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(1172, 0X11B8));
    // 0x80800ADC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800AE0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80800AE4: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x80800AE8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80800AEC: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x80800AF0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80800AF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800AF8: beq         $t5, $at, L_80800B30
    if (ctx->r13 == ctx->r1) {
        // 0x80800AFC: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80800B30;
    }
    // 0x80800AFC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800B00: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80800B04: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800B08: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x80800B0C: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x80800B10: jal         0x8080052C
    // 0x80800B14: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    func_8080052C_chcoderoombits(rdram, ctx);
        goto after_4;
    // 0x80800B14: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x80800B18: beq         $v0, $zero, L_80800B30
    if (ctx->r2 == 0) {
        // 0x80800B1C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80800B30;
    }
    // 0x80800B1C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800B20: jal         0x80101FDC
    // 0x80800B24: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_5;
    // 0x80800B24: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_5:
    // 0x80800B28: jal         0x808004B8
    // 0x80800B2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_808004B8_chcoderoombits(rdram, ctx);
        goto after_6;
    // 0x80800B2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
L_80800B30:
    // 0x80800B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800B34:
    // 0x80800B34: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800B38: jr          $ra
    // 0x80800B3C: nop

    return;
    // 0x80800B3C: nop

;}
RECOMP_FUNC void func_808009DC_chheggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009DC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808009E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808009E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808009E8: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808009EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808009F0: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808009F4: addiu       $t8, $t7, -0x3
    ctx->r24 = ADD32(ctx->r15, -0X3);
    // 0x808009F8: sltiu       $at, $t8, 0x12
    ctx->r1 = ctx->r24 < 0X12 ? 1 : 0;
    // 0x808009FC: beq         $at, $zero, L_80800E78
    if (ctx->r1 == 0) {
        // 0x80800A00: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800E78;
    }
    // 0x80800A00: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800A04: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2456, 0X1B84) << 16);
    // 0x80800A08: addu        $at, $at, $t8
    gpr jr_addend_80800A10 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800A0C: lw          $t8, 0x1B84($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2456, 0X1B84));
    // 0x80800A10: jr          $t8
    // 0x80800A14: nop

    switch (jr_addend_80800A10 >> 2) {
        case 0: goto L_80800E78; break;
        case 1: goto L_80800E78; break;
        case 2: goto L_80800E78; break;
        case 3: goto L_80800E78; break;
        case 4: goto L_80800A18; break;
        case 5: goto L_80800A38; break;
        case 6: goto L_80800E78; break;
        case 7: goto L_80800B4C; break;
        case 8: goto L_80800E78; break;
        case 9: goto L_80800B6C; break;
        case 10: goto L_80800B8C; break;
        case 11: goto L_80800C54; break;
        case 12: goto L_80800C7C; break;
        case 13: goto L_80800D28; break;
        case 14: goto L_80800E78; break;
        case 15: goto L_80800D64; break;
        case 16: goto L_80800D84; break;
        case 17: goto L_80800E78; break;
        default: switch_error(__func__, 0x80800A10, 0x80801B84);
    }
    // 0x80800A14: nop

L_80800A18:
    // 0x80800A18: jal         0x800D90A4
    // 0x80800A1C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_0;
    // 0x80800A1C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_0:
    // 0x80800A20: beq         $v0, $zero, L_80800E78
    if (ctx->r2 == 0) {
        // 0x80800A24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E78;
    }
    // 0x80800A24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A28: jal         0x80800ECC
    // 0x80800A2C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_1;
    // 0x80800A2C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80800A30: b           L_80800E78
    // 0x80800A34: nop

        goto L_80800E78;
    // 0x80800A34: nop

L_80800A38:
    // 0x80800A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A3C: jal         0x80100094
    // 0x80800A40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800A40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80800A44: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80800A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A4C: jal         0x80100094
    // 0x80800A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x80800A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800A54: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800A58: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80800A5C: jal         0x80089C30
    // 0x80800A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x80800A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800A64: beql        $v0, $zero, L_80800A90
    if (ctx->r2 == 0) {
        // 0x80800A68: lw          $t9, 0x34($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X34);
            goto L_80800A90;
    }
    goto skip_0;
    // 0x80800A68: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x80800A6C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800A70: beql        $a0, $zero, L_80800A90
    if (ctx->r4 == 0) {
        // 0x80800A74: lw          $t9, 0x34($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X34);
            goto L_80800A90;
    }
    goto skip_1;
    // 0x80800A74: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x80800A78: jal         0x80106790
    // 0x80800A7C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_80106790(rdram, ctx);
        goto after_5;
    // 0x80800A7C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_5:
    // 0x80800A80: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80800A84: lwc1        $f4, 0x48($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X48);
    // 0x80800A88: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
    // 0x80800A8C: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
L_80800A90:
    // 0x80800A90: addiu       $at, $zero, 0x515
    ctx->r1 = ADD32(0, 0X515);
    // 0x80800A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A98: bne         $t9, $at, L_80800AA8
    if (ctx->r25 != ctx->r1) {
        // 0x80800A9C: lw          $t0, 0x50($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X50);
            goto L_80800AA8;
    }
    // 0x80800A9C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80800AA0: b           L_80800AAC
    // 0x80800AA4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800AAC;
    // 0x80800AA4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80800AA8:
    // 0x80800AA8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800AAC:
    // 0x80800AAC: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80800AB0: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80800AB4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800AB8: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x80800ABC: jal         0x80089FE8
    // 0x80800AC0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    _subaddieitem_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800AC0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    after_6:
    // 0x80800AC4: beq         $v0, $zero, L_80800E78
    if (ctx->r2 == 0) {
        // 0x80800AC8: nop
    
            goto L_80800E78;
    }
    // 0x80800AC8: nop

    // 0x80800ACC: lw          $t2, 0x34($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X34);
    // 0x80800AD0: addiu       $at, $zero, 0x515
    ctx->r1 = ADD32(0, 0X515);
    // 0x80800AD4: bne         $t2, $at, L_80800B24
    if (ctx->r10 != ctx->r1) {
        // 0x80800AD8: nop
    
            goto L_80800B24;
    }
    // 0x80800AD8: nop

    // 0x80800ADC: jal         0x800DA524
    // 0x80800AE0: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    func_800DA524(rdram, ctx);
        goto after_7;
    // 0x80800AE0: addiu       $a0, $zero, 0x3E3
    ctx->r4 = ADD32(0, 0X3E3);
    after_7:
    // 0x80800AE4: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x80800AE8: addiu       $a0, $zero, 0x3E5
    ctx->r4 = ADD32(0, 0X3E5);
    // 0x80800AEC: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x80800AF0: jal         0x800DA298
    // 0x80800AF4: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800AF4: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
    after_8:
    // 0x80800AF8: beq         $v0, $zero, L_80800B14
    if (ctx->r2 == 0) {
        // 0x80800AFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800B14;
    }
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B04: jal         0x80800ECC
    // 0x80800B08: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_9;
    // 0x80800B08: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_9:
    // 0x80800B0C: b           L_80800E78
    // 0x80800B10: nop

        goto L_80800E78;
    // 0x80800B10: nop

L_80800B14:
    // 0x80800B14: jal         0x80800ECC
    // 0x80800B18: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_10;
    // 0x80800B18: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_10:
    // 0x80800B1C: b           L_80800E78
    // 0x80800B20: nop

        goto L_80800E78;
    // 0x80800B20: nop

L_80800B24:
    // 0x80800B24: jal         0x800DA524
    // 0x80800B28: addiu       $a0, $zero, 0x3E5
    ctx->r4 = ADD32(0, 0X3E5);
    func_800DA524(rdram, ctx);
        goto after_11;
    // 0x80800B28: addiu       $a0, $zero, 0x3E5
    ctx->r4 = ADD32(0, 0X3E5);
    after_11:
    // 0x80800B2C: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800B30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B34: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80800B38: ori         $t8, $t7, 0x8
    ctx->r24 = ctx->r15 | 0X8;
    // 0x80800B3C: jal         0x80800ECC
    // 0x80800B40: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_80800ECC_chheggy(rdram, ctx);
        goto after_12;
    // 0x80800B40: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_12:
    // 0x80800B44: b           L_80800E78
    // 0x80800B48: nop

        goto L_80800E78;
    // 0x80800B48: nop

L_80800B4C:
    // 0x80800B4C: jal         0x800D90A4
    // 0x80800B50: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_13;
    // 0x80800B50: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_13:
    // 0x80800B54: beq         $v0, $zero, L_80800E78
    if (ctx->r2 == 0) {
        // 0x80800B58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E78;
    }
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B5C: jal         0x80800ECC
    // 0x80800B60: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_14;
    // 0x80800B60: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_14:
    // 0x80800B64: b           L_80800E78
    // 0x80800B68: nop

        goto L_80800E78;
    // 0x80800B68: nop

L_80800B6C:
    // 0x80800B6C: jal         0x808000C0
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C0_chheggy(rdram, ctx);
        goto after_15;
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80800B74: beq         $v0, $zero, L_80800E78
    if (ctx->r2 == 0) {
        // 0x80800B78: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E78;
    }
    // 0x80800B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B7C: jal         0x80800ECC
    // 0x80800B80: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_16;
    // 0x80800B80: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_16:
    // 0x80800B84: b           L_80800E78
    // 0x80800B88: nop

        goto L_80800E78;
    // 0x80800B88: nop

L_80800B8C:
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B90: jal         0x80100094
    // 0x80800B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_17;
    // 0x80800B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800B98: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80800B9C: jal         0x80101F24
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_18;
    // 0x80800BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80800BA4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2456, 0X1BCC) << 16);
    // 0x80800BA8: lwc1        $f6, 0x1BCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2456, 0X1BCC));
    // 0x80800BAC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2456, 0X1BD0) << 16);
    // 0x80800BB0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800BB4: nop

    // 0x80800BB8: bc1f        L_80800BCC
    if (!c1cs) {
        // 0x80800BBC: nop
    
            goto L_80800BCC;
    }
    // 0x80800BBC: nop

    // 0x80800BC0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80800BC4: b           L_80800C38
    // 0x80800BC8: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
        goto L_80800C38;
    // 0x80800BC8: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
L_80800BCC:
    // 0x80800BCC: lwc1        $f8, 0x1BD0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2456, 0X1BD0));
    // 0x80800BD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800BD8: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80800BDC: nop

    // 0x80800BE0: bc1fl       L_80800C24
    if (!c1cs) {
        // 0x80800BE4: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80800C24;
    }
    goto skip_2;
    // 0x80800BE4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_2:
    // 0x80800BE8: jal         0x80101F24
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_19;
    // 0x80800BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800BF0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2456, 0X1BD4) << 16);
    // 0x80800BF4: lwc1        $f14, 0x1BD4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2456, 0X1BD4));
    // 0x80800BF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800BFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800C00: lui         $a2, 0x3E23
    ctx->r6 = S32(0X3E23 << 16);
    // 0x80800C04: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80800C08: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800C0C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800C10: jal         0x800F10B4
    // 0x80800C14: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800F10B4(rdram, ctx);
        goto after_20;
    // 0x80800C14: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_20:
    // 0x80800C18: b           L_80800C34
    // 0x80800C1C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80800C34;
    // 0x80800C1C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800C20: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80800C24:
    // 0x80800C24: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80800C28: jal         0x80800ECC
    // 0x80800C2C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    func_80800ECC_chheggy(rdram, ctx);
        goto after_21;
    // 0x80800C2C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    after_21:
    // 0x80800C30: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
L_80800C34:
    // 0x80800C34: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
L_80800C38:
    // 0x80800C38: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800C3C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800C40: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    // 0x80800C44: jal         0x800EFE50
    // 0x80800C48: addiu       $a2, $v0, 0x70
    ctx->r6 = ADD32(ctx->r2, 0X70);
    func_800EFE50(rdram, ctx);
        goto after_22;
    // 0x80800C48: addiu       $a2, $v0, 0x70
    ctx->r6 = ADD32(ctx->r2, 0X70);
    after_22:
    // 0x80800C4C: b           L_80800E78
    // 0x80800C50: nop

        goto L_80800E78;
    // 0x80800C50: nop

L_80800C54:
    // 0x80800C54: lui         $a1, 0x3F57
    ctx->r5 = S32(0X3F57 << 16);
    // 0x80800C58: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    // 0x80800C5C: jal         0x80101E14
    // 0x80800C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_23;
    // 0x80800C60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80800C64: beq         $v0, $zero, L_80800E78
    if (ctx->r2 == 0) {
        // 0x80800C68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E78;
    }
    // 0x80800C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C6C: jal         0x80800ECC
    // 0x80800C70: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_24;
    // 0x80800C70: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_24:
    // 0x80800C74: b           L_80800E78
    // 0x80800C78: nop

        goto L_80800E78;
    // 0x80800C78: nop

L_80800C7C:
    // 0x80800C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C80: jal         0x80100094
    // 0x80800C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_25;
    // 0x80800C84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_25:
    // 0x80800C88: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80800C8C: jal         0x80101F24
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_26;
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800C94: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2456, 0X1BD8) << 16);
    // 0x80800C98: lwc1        $f16, 0x1BD8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2456, 0X1BD8));
    // 0x80800C9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA4: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x80800CA8: nop

    // 0x80800CAC: bc1fl       L_80800CF0
    if (!c1cs) {
        // 0x80800CB0: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80800CF0;
    }
    goto skip_3;
    // 0x80800CB0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_3:
    // 0x80800CB4: jal         0x80101F24
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_27;
    // 0x80800CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80800CBC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2456, 0X1BDC) << 16);
    // 0x80800CC0: lwc1        $f14, 0x1BDC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2456, 0X1BDC));
    // 0x80800CC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800CC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800CCC: lui         $a2, 0x3F6B
    ctx->r6 = S32(0X3F6B << 16);
    // 0x80800CD0: ori         $a2, $a2, 0x851F
    ctx->r6 = ctx->r6 | 0X851F;
    // 0x80800CD4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800CD8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800CDC: jal         0x800F10B4
    // 0x80800CE0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800F10B4(rdram, ctx);
        goto after_28;
    // 0x80800CE0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_28:
    // 0x80800CE4: b           L_80800D00
    // 0x80800CE8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80800D00;
    // 0x80800CE8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80800CEC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80800CF0:
    // 0x80800CF0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80800CF4: jal         0x80800ECC
    // 0x80800CF8: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    func_80800ECC_chheggy(rdram, ctx);
        goto after_29;
    // 0x80800CF8: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    after_29:
    // 0x80800CFC: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
L_80800D00:
    // 0x80800D00: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80800D04: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800D08: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800D0C: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    // 0x80800D10: jal         0x800EFE50
    // 0x80800D14: addiu       $a2, $v0, 0x70
    ctx->r6 = ADD32(ctx->r2, 0X70);
    func_800EFE50(rdram, ctx);
        goto after_30;
    // 0x80800D14: addiu       $a2, $v0, 0x70
    ctx->r6 = ADD32(ctx->r2, 0X70);
    after_30:
    // 0x80800D18: jal         0x800D1804
    // 0x80800D1C: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    func_800D1804(rdram, ctx);
        goto after_31;
    // 0x80800D1C: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    after_31:
    // 0x80800D20: b           L_80800E78
    // 0x80800D24: nop

        goto L_80800E78;
    // 0x80800D24: nop

L_80800D28:
    // 0x80800D28: jal         0x800D90A4
    // 0x80800D2C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D90A4(rdram, ctx);
        goto after_32;
    // 0x80800D2C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_32:
    // 0x80800D30: beq         $v0, $zero, L_80800D40
    if (ctx->r2 == 0) {
        // 0x80800D34: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D40;
    }
    // 0x80800D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D38: jal         0x80800ECC
    // 0x80800D3C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_33;
    // 0x80800D3C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_33:
L_80800D40:
    // 0x80800D40: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800D44: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80800D48: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800D4C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D54: jal         0x80102BAC
    // 0x80800D58: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    func_80102BAC(rdram, ctx);
        goto after_34;
    // 0x80800D58: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    after_34:
    // 0x80800D5C: b           L_80800E78
    // 0x80800D60: nop

        goto L_80800E78;
    // 0x80800D60: nop

L_80800D64:
    // 0x80800D64: jal         0x808000C0
    // 0x80800D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000C0_chheggy(rdram, ctx);
        goto after_35;
    // 0x80800D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x80800D6C: beq         $v0, $zero, L_80800E78
    if (ctx->r2 == 0) {
        // 0x80800D70: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E78;
    }
    // 0x80800D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D74: jal         0x80800ECC
    // 0x80800D78: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    func_80800ECC_chheggy(rdram, ctx);
        goto after_36;
    // 0x80800D78: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_36:
    // 0x80800D7C: b           L_80800E78
    // 0x80800D80: nop

        goto L_80800E78;
    // 0x80800D80: nop

L_80800D84:
    // 0x80800D84: jal         0x80103EF4
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EF4(rdram, ctx);
        goto after_37;
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x80800D8C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80800D90: jal         0x80103EAC
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_38;
    // 0x80800D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x80800D98: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2456, 0X1BE0) << 16);
    // 0x80800D9C: lwc1        $f4, 0x1BE0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2456, 0X1BE0));
    // 0x80800DA0: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800DA4: addiu       $t9, $zero, 0xE
    ctx->r25 = ADD32(0, 0XE);
    // 0x80800DA8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800DAC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800DB0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800DB4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800DB8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800DBC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80800DC0: jal         0x80089F20
    // 0x80800DC4: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_39;
    // 0x80800DC4: nop

    after_39:
    // 0x80800DC8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800DCC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800DD0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800DD4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80800DD8: addiu       $a2, $zero, 0x258
    ctx->r6 = ADD32(0, 0X258);
    // 0x80800DDC: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x80800DE0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800DE4: jal         0x8008A1E0
    // 0x80800DE8: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_40;
    // 0x80800DE8: nop

    after_40:
    // 0x80800DEC: beq         $v0, $zero, L_80800E78
    if (ctx->r2 == 0) {
        // 0x80800DF0: nop
    
            goto L_80800E78;
    }
    // 0x80800DF0: nop

    // 0x80800DF4: jal         0x800DA298
    // 0x80800DF8: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    func_800DA298(rdram, ctx);
        goto after_41;
    // 0x80800DF8: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    after_41:
    // 0x80800DFC: bne         $v0, $zero, L_80800E1C
    if (ctx->r2 != 0) {
        // 0x80800E00: nop
    
            goto L_80800E1C;
    }
    // 0x80800E00: nop

    // 0x80800E04: jal         0x800DA298
    // 0x80800E08: addiu       $a0, $zero, 0x3E6
    ctx->r4 = ADD32(0, 0X3E6);
    func_800DA298(rdram, ctx);
        goto after_42;
    // 0x80800E08: addiu       $a0, $zero, 0x3E6
    ctx->r4 = ADD32(0, 0X3E6);
    after_42:
    // 0x80800E0C: bne         $v0, $zero, L_80800E1C
    if (ctx->r2 != 0) {
        // 0x80800E10: nop
    
            goto L_80800E1C;
    }
    // 0x80800E10: nop

    // 0x80800E14: b           L_80800E60
    // 0x80800E18: addiu       $a1, $zero, 0x1546
    ctx->r5 = ADD32(0, 0X1546);
        goto L_80800E60;
    // 0x80800E18: addiu       $a1, $zero, 0x1546
    ctx->r5 = ADD32(0, 0X1546);
L_80800E1C:
    // 0x80800E1C: jal         0x800DA298
    // 0x80800E20: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    func_800DA298(rdram, ctx);
        goto after_43;
    // 0x80800E20: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    after_43:
    // 0x80800E24: beql        $v0, $zero, L_80800E60
    if (ctx->r2 == 0) {
        // 0x80800E28: addiu       $a1, $zero, 0x1547
        ctx->r5 = ADD32(0, 0X1547);
            goto L_80800E60;
    }
    goto skip_4;
    // 0x80800E28: addiu       $a1, $zero, 0x1547
    ctx->r5 = ADD32(0, 0X1547);
    skip_4:
    // 0x80800E2C: jal         0x800DA298
    // 0x80800E30: addiu       $a0, $zero, 0x3E6
    ctx->r4 = ADD32(0, 0X3E6);
    func_800DA298(rdram, ctx);
        goto after_44;
    // 0x80800E30: addiu       $a0, $zero, 0x3E6
    ctx->r4 = ADD32(0, 0X3E6);
    after_44:
    // 0x80800E34: beql        $v0, $zero, L_80800E60
    if (ctx->r2 == 0) {
        // 0x80800E38: addiu       $a1, $zero, 0x1547
        ctx->r5 = ADD32(0, 0X1547);
            goto L_80800E60;
    }
    goto skip_5;
    // 0x80800E38: addiu       $a1, $zero, 0x1547
    ctx->r5 = ADD32(0, 0X1547);
    skip_5:
    // 0x80800E3C: jal         0x800DA298
    // 0x80800E40: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    func_800DA298(rdram, ctx);
        goto after_45;
    // 0x80800E40: addiu       $a0, $zero, 0x3E7
    ctx->r4 = ADD32(0, 0X3E7);
    after_45:
    // 0x80800E44: beq         $v0, $zero, L_80800E54
    if (ctx->r2 == 0) {
        // 0x80800E48: nop
    
            goto L_80800E54;
    }
    // 0x80800E48: nop

    // 0x80800E4C: b           L_80800E60
    // 0x80800E50: addiu       $a1, $zero, 0x1549
    ctx->r5 = ADD32(0, 0X1549);
        goto L_80800E60;
    // 0x80800E50: addiu       $a1, $zero, 0x1549
    ctx->r5 = ADD32(0, 0X1549);
L_80800E54:
    // 0x80800E54: b           L_80800E60
    // 0x80800E58: addiu       $a1, $zero, 0x1548
    ctx->r5 = ADD32(0, 0X1548);
        goto L_80800E60;
    // 0x80800E58: addiu       $a1, $zero, 0x1548
    ctx->r5 = ADD32(0, 0X1548);
    // 0x80800E5C: addiu       $a1, $zero, 0x1547
    ctx->r5 = ADD32(0, 0X1547);
L_80800E60:
    // 0x80800E60: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800E64: addiu       $t1, $zero, 0xCB
    ctx->r9 = ADD32(0, 0XCB);
    // 0x80800E68: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800E6C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800E70: jal         0x8008A208
    // 0x80800E74: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_46;
    // 0x80800E74: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_46:
L_80800E78:
    // 0x80800E78: jal         0x8080015C
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080015C_chheggy(rdram, ctx);
        goto after_47;
    // 0x80800E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80800E80: jal         0x800DA298
    // 0x80800E84: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    func_800DA298(rdram, ctx);
        goto after_48;
    // 0x80800E84: addiu       $a0, $zero, 0x3E4
    ctx->r4 = ADD32(0, 0X3E4);
    after_48:
    // 0x80800E88: beq         $v0, $zero, L_80800EA0
    if (ctx->r2 == 0) {
        // 0x80800E8C: nop
    
            goto L_80800EA0;
    }
    // 0x80800E8C: nop

    // 0x80800E90: jal         0x800DA298
    // 0x80800E94: addiu       $a0, $zero, 0x3E6
    ctx->r4 = ADD32(0, 0X3E6);
    func_800DA298(rdram, ctx);
        goto after_49;
    // 0x80800E94: addiu       $a0, $zero, 0x3E6
    ctx->r4 = ADD32(0, 0X3E6);
    after_49:
    // 0x80800E98: bnel        $v0, $zero, L_80800EBC
    if (ctx->r2 != 0) {
        // 0x80800E9C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800EBC;
    }
    goto skip_6;
    // 0x80800E9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
L_80800EA0:
    // 0x80800EA0: jal         0x80088848
    // 0x80800EA4: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_50;
    // 0x80800EA4: nop

    after_50:
    // 0x80800EA8: bnel        $v0, $zero, L_80800EBC
    if (ctx->r2 != 0) {
        // 0x80800EAC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800EBC;
    }
    goto skip_7;
    // 0x80800EAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x80800EB0: jal         0x800D1824
    // 0x80800EB4: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    func_800D1824(rdram, ctx);
        goto after_51;
    // 0x80800EB4: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    after_51:
    // 0x80800EB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800EBC:
    // 0x80800EBC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800EC0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800EC4: jr          $ra
    // 0x80800EC8: nop

    return;
    // 0x80800EC8: nop

;}
RECOMP_FUNC void bskazpaddle_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080097C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800980: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(268, 0XA90) << 16);
    // 0x80800984: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800988: jr          $ra
    // 0x8080098C: lw          $v0, 0xA90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(268, 0XA90));
    return;
    // 0x8080098C: lw          $v0, 0xA90($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(268, 0XA90));
;}
RECOMP_FUNC void func_800F5C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5C44: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5C48: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5C4C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5C50: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F5C54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F5C58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5C5C: jal         0x800A3274
    // 0x800F5C60: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800A3274(rdram, ctx);
        goto after_0;
    // 0x800F5C60: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F5C64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F5C68: beq         $v0, $at, L_800F5C7C
    if (ctx->r2 == ctx->r1) {
        // 0x800F5C6C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_800F5C7C;
    }
    // 0x800F5C6C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F5C70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F5C74: b           L_800F5C88
    // 0x800F5C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F5C88;
    // 0x800F5C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F5C7C:
    // 0x800F5C7C: jal         0x800850F8
    // 0x800F5C80: nop

    _basnowball_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x800F5C80: nop

    after_1:
    // 0x800F5C84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F5C88:
    // 0x800F5C88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F5C8C: jr          $ra
    // 0x800F5C90: nop

    return;
    // 0x800F5C90: nop

;}
RECOMP_FUNC void chegggolden_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800338: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080033C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800340: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800344: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800348: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8080034C: jal         0x8008A488
    // 0x80800350: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x80800350: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800354: addiu       $a0, $zero, 0x15F
    ctx->r4 = ADD32(0, 0X15F);
    // 0x80800358: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080035C: jal         0x8008A3D0
    // 0x80800360: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _suegg_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800360: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800364: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800368: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080036C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800370: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800378: jal         0x8008A460
    // 0x8080037C: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    _sueggmove_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x8080037C: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    after_2:
    // 0x80800380: lui         $a2, 0xC7C3
    ctx->r6 = S32(0XC7C3 << 16);
    // 0x80800384: ori         $a2, $a2, 0x5000
    ctx->r6 = ctx->r6 | 0X5000;
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: jal         0x8008A468
    // 0x80800390: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _sueggmove_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800390: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: jal         0x8008A380
    // 0x8080039C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    _suegg_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x8080039C: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_4:
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003A4: jal         0x8008A470
    // 0x808003A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sueggmove_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x808003A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x808003AC: lbu         $t6, 0x72($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X72);
    // 0x808003B0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808003B4: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x808003B8: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x808003BC: sb          $t8, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r24;
    // 0x808003C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003CC: jr          $ra
    // 0x808003D0: nop

    return;
    // 0x808003D0: nop

    // 0x808003D4: nop

    // 0x808003D8: nop

    // 0x808003DC: nop

;}
RECOMP_FUNC void func_808005A8_gcmapDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x808005AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005B8: addiu       $a2, $s0, 0x180
    ctx->r6 = ADD32(ctx->r16, 0X180);
    // 0x808005BC: addiu       $a3, $s0, 0x18C
    ctx->r7 = ADD32(ctx->r16, 0X18C);
    // 0x808005C0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808005C4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808005C8: jal         0x8080045C
    // 0x808005CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8080045C_gcmapDll(rdram, ctx);
        goto after_0;
    // 0x808005CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005D0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808005D4: jal         0x800EE830
    // 0x808005D8: addiu       $a0, $s0, 0x198
    ctx->r4 = ADD32(ctx->r16, 0X198);
    func_800EE830(rdram, ctx);
        goto after_1;
    // 0x808005D8: addiu       $a0, $s0, 0x198
    ctx->r4 = ADD32(ctx->r16, 0X198);
    after_1:
    // 0x808005DC: addiu       $a0, $s0, 0x1A4
    ctx->r4 = ADD32(ctx->r16, 0X1A4);
    // 0x808005E0: jal         0x800EE830
    // 0x808005E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE830(rdram, ctx);
        goto after_2;
    // 0x808005E4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x808005E8: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x808005EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808005F4: beq         $t6, $zero, L_80800654
    if (ctx->r14 == 0) {
        // 0x808005F8: addiu       $a2, $sp, 0x40
        ctx->r6 = ADD32(ctx->r29, 0X40);
            goto L_80800654;
    }
    // 0x808005F8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x808005FC: jal         0x8080045C
    // 0x80800600: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    func_8080045C_gcmapDll(rdram, ctx);
        goto after_3;
    // 0x80800600: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x80800604: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80800608: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8080060C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800610: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
L_80800614:
    // 0x80800614: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80800618: lw          $t7, 0x198($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X198);
    // 0x8080061C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800620: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80800624: beql        $at, $zero, L_80800634
    if (ctx->r1 == 0) {
        // 0x80800628: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_80800634;
    }
    goto skip_0;
    // 0x80800628: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8080062C: sw          $v1, 0x198($v0)
    MEM_W(0X198, ctx->r2) = ctx->r3;
    // 0x80800630: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_80800634:
    // 0x80800634: lw          $t8, 0x1A4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1A4);
    // 0x80800638: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080063C: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80800640: beq         $at, $zero, L_8080064C
    if (ctx->r1 == 0) {
        // 0x80800644: nop
    
            goto L_8080064C;
    }
    // 0x80800644: nop

    // 0x80800648: sw          $v1, 0x1A4($v0)
    MEM_W(0X1A4, ctx->r2) = ctx->r3;
L_8080064C:
    // 0x8080064C: bne         $a0, $a2, L_80800614
    if (ctx->r4 != ctx->r6) {
        // 0x80800650: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80800614;
    }
    // 0x80800650: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80800654:
    // 0x80800654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800658: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080065C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800660: jr          $ra
    // 0x80800664: nop

    return;
    // 0x80800664: nop

;}
RECOMP_FUNC void func_808006A0_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808006A4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x808006A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006AC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x808006B0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x808006B4: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x808006B8: lhu         $v1, 0x72($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X72);
    // 0x808006BC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(804, 0X7DD8) << 16);
    // 0x808006C0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808006C4: srl         $t8, $v1, 10
    ctx->r24 = S32(U32(ctx->r3) >> 10);
    // 0x808006C8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x808006CC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x808006D0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808006D4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808006D8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x808006DC: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x808006E0: lw          $v0, 0x7DD8($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(804, 0X7DD8));
    // 0x808006E4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x808006E8: beql        $v0, $zero, L_80800714
    if (ctx->r2 == 0) {
        // 0x808006EC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800714;
    }
    goto skip_0;
    // 0x808006EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x808006F0: jalr        $v0
    // 0x808006F4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x808006F4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x808006F8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x808006FC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800700: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80800704: lhu         $v1, 0x72($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X72);
    // 0x80800708: srl         $t1, $v1, 10
    ctx->r9 = S32(U32(ctx->r3) >> 10);
    // 0x8080070C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80800710: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80800714:
    // 0x80800714: bne         $v1, $at, L_8080082C
    if (ctx->r3 != ctx->r1) {
        // 0x80800718: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080082C;
    }
    // 0x80800718: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080071C: beq         $a1, $at, L_80800744
    if (ctx->r5 == ctx->r1) {
        // 0x80800720: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800744;
    }
    // 0x80800720: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800724: beq         $a1, $at, L_80800794
    if (ctx->r5 == ctx->r1) {
        // 0x80800728: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80800794;
    }
    // 0x80800728: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8080072C: beq         $a1, $at, L_808007AC
    if (ctx->r5 == ctx->r1) {
        // 0x80800730: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_808007AC;
    }
    // 0x80800730: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800734: beq         $a1, $at, L_808007E0
    if (ctx->r5 == ctx->r1) {
        // 0x80800738: nop
    
            goto L_808007E0;
    }
    // 0x80800738: nop

    // 0x8080073C: b           L_808007F8
    // 0x80800740: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
        goto L_808007F8;
    // 0x80800740: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_80800744:
    // 0x80800744: jal         0x80803718
    // 0x80800748: nop

    func_80803718_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80800748: nop

    after_1:
    // 0x8080074C: bne         $v0, $zero, L_8080075C
    if (ctx->r2 != 0) {
        // 0x80800750: addiu       $t2, $zero, 0x5
        ctx->r10 = ADD32(0, 0X5);
            goto L_8080075C;
    }
    // 0x80800750: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80800754: b           L_808007F4
    // 0x80800758: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
        goto L_808007F4;
    // 0x80800758: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_8080075C:
    // 0x8080075C: jal         0x808036F8
    // 0x80800760: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_808036F8_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80800760: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80800764: beql        $v0, $zero, L_808007F8
    if (ctx->r2 == 0) {
        // 0x80800768: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_808007F8;
    }
    goto skip_1;
    // 0x80800768: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8080076C: jal         0x808036F8
    // 0x80800770: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_808036F8_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80800770: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800774: beql        $v0, $zero, L_808007F8
    if (ctx->r2 == 0) {
        // 0x80800778: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_808007F8;
    }
    goto skip_2;
    // 0x80800778: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x8080077C: jal         0x808036F8
    // 0x80800780: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_808036F8_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80800780: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80800784: beq         $v0, $zero, L_808007F4
    if (ctx->r2 == 0) {
        // 0x80800788: addiu       $t3, $zero, 0x7
        ctx->r11 = ADD32(0, 0X7);
            goto L_808007F4;
    }
    // 0x80800788: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x8080078C: b           L_808007F4
    // 0x80800790: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
        goto L_808007F4;
    // 0x80800790: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
L_80800794:
    // 0x80800794: jal         0x80803718
    // 0x80800798: nop

    func_80803718_chgameselect(rdram, ctx);
        goto after_5;
    // 0x80800798: nop

    after_5:
    // 0x8080079C: bne         $v0, $zero, L_808007F4
    if (ctx->r2 != 0) {
        // 0x808007A0: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_808007F4;
    }
    // 0x808007A0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x808007A4: b           L_808007F4
    // 0x808007A8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
        goto L_808007F4;
    // 0x808007A8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_808007AC:
    // 0x808007AC: jal         0x80803D60
    // 0x808007B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80803D60_chgameselect(rdram, ctx);
        goto after_6;
    // 0x808007B0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_6:
    // 0x808007B4: bne         $v0, $zero, L_808007C4
    if (ctx->r2 != 0) {
        // 0x808007B8: nop
    
            goto L_808007C4;
    }
    // 0x808007B8: nop

    // 0x808007BC: b           L_808007F4
    // 0x808007C0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
        goto L_808007F4;
    // 0x808007C0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_808007C4:
    // 0x808007C4: jal         0x80803E40
    // 0x808007C8: nop

    func_80803E40_chgameselect(rdram, ctx);
        goto after_7;
    // 0x808007C8: nop

    after_7:
    // 0x808007CC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x808007D0: beq         $at, $zero, L_808007F4
    if (ctx->r1 == 0) {
        // 0x808007D4: addiu       $t5, $zero, 0x23
        ctx->r13 = ADD32(0, 0X23);
            goto L_808007F4;
    }
    // 0x808007D4: addiu       $t5, $zero, 0x23
    ctx->r13 = ADD32(0, 0X23);
    // 0x808007D8: b           L_808007F4
    // 0x808007DC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
        goto L_808007F4;
    // 0x808007DC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_808007E0:
    // 0x808007E0: jal         0x80803D60
    // 0x808007E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80803D60_chgameselect(rdram, ctx);
        goto after_8;
    // 0x808007E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_8:
    // 0x808007E8: bnel        $v0, $zero, L_808007F8
    if (ctx->r2 != 0) {
        // 0x808007EC: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_808007F8;
    }
    goto skip_3;
    // 0x808007EC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x808007F0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_808007F4:
    // 0x808007F4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_808007F8:
    // 0x808007F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808007FC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800800: beq         $t6, $at, L_80800810
    if (ctx->r14 == ctx->r1) {
        // 0x80800804: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80800810;
    }
    // 0x80800804: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800808: b           L_8080082C
    // 0x8080080C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
        goto L_8080082C;
    // 0x8080080C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
L_80800810:
    // 0x80800810: lbu         $t7, 0x79($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X79);
    // 0x80800814: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(804, 0X7DB2) << 16);
    // 0x80800818: srl         $t0, $t7, 4
    ctx->r8 = S32(U32(ctx->r15) >> 4);
    // 0x8080081C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80800820: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80800824: jal         0x80800478
    // 0x80800828: lh          $a1, 0x7DB2($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(804, 0X7DB2));
    func_80800478_chgameselect(rdram, ctx);
        goto after_9;
    // 0x80800828: lh          $a1, 0x7DB2($a1)
    ctx->r5 = MEM_H(ctx->r5, (int16_t)RELOC_LO16(804, 0X7DB2));
    after_9:
L_8080082C:
    // 0x8080082C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80800830: beql        $t2, $zero, L_80800844
    if (ctx->r10 == 0) {
        // 0x80800834: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_80800844;
    }
    goto skip_4;
    // 0x80800834: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x80800838: jal         0x80803C60
    // 0x8080083C: nop

    func_80803C60_chgameselect(rdram, ctx);
        goto after_10;
    // 0x8080083C: nop

    after_10:
    // 0x80800840: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_80800844:
    // 0x80800844: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800848: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8080084C: beq         $t3, $at, L_8080085C
    if (ctx->r11 == ctx->r1) {
        // 0x80800850: or          $a1, $t3, $zero
        ctx->r5 = ctx->r11 | 0;
            goto L_8080085C;
    }
    // 0x80800850: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80800854: jal         0x808026C8
    // 0x80800858: lw          $a0, 0x2C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X2C);
    func_808026C8_chgameselect(rdram, ctx);
        goto after_11;
    // 0x80800858: lw          $a0, 0x2C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X2C);
    after_11:
L_8080085C:
    // 0x8080085C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800860: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800864: jr          $ra
    // 0x80800868: nop

    return;
    // 0x80800868: nop

;}
RECOMP_FUNC void glsplinefind_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800174: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80800178: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8080017C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800180: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800184: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800188: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8080018C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80800190: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80800194: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800198: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8080019C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808001A0: jal         0x800D7400
    // 0x808001A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    func_800D7400(rdram, ctx);
        goto after_0;
    // 0x808001A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_0:
    // 0x808001A8: addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
    // 0x808001AC: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x808001B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808001B4: jal         0x800EE84C
    // 0x808001B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE84C(rdram, ctx);
        goto after_1;
    // 0x808001B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x808001BC: addiu       $s4, $sp, 0x4C
    ctx->r20 = ADD32(ctx->r29, 0X4C);
    // 0x808001C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808001C4: jal         0x800EE84C
    // 0x808001C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EE84C(rdram, ctx);
        goto after_2;
    // 0x808001C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x808001CC: lw          $t6, 0x188($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X188);
    // 0x808001D0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x808001D4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x808001D8: blezl       $t6, L_80800258
    if (SIGNED(ctx->r14) <= 0) {
        // 0x808001DC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80800258;
    }
    goto skip_0;
    // 0x808001DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x808001E0: lh          $a0, 0x184($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X184);
L_808001E4:
    // 0x808001E4: jal         0x8001B798
    // 0x808001E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8001B798(rdram, ctx);
        goto after_3;
    // 0x808001E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_3:
    // 0x808001EC: addu        $t7, $v0, $s5
    ctx->r15 = ADD32(ctx->r2, ctx->r21);
    // 0x808001F0: jal         0x8001B798
    // 0x808001F4: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    func_8001B798(rdram, ctx);
        goto after_4;
    // 0x808001F4: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    after_4:
    // 0x808001F8: lbu         $s2, 0x2($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X2);
    // 0x808001FC: addiu       $s0, $v0, 0x14
    ctx->r16 = ADD32(ctx->r2, 0X14);
    // 0x80800200: blez        $s2, L_8080023C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80800204: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8080023C;
    }
L_80800204:
    // 0x80800204: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80800208: jal         0x800EECE0
    // 0x8080020C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EECE0(rdram, ctx);
        goto after_5;
    // 0x8080020C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x80800210: beq         $v0, $zero, L_80800230
    if (ctx->r2 == 0) {
        // 0x80800214: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80800230;
    }
    // 0x80800214: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800218: jal         0x800EECE0
    // 0x8080021C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    func_800EECE0(rdram, ctx);
        goto after_6;
    // 0x8080021C: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    after_6:
    // 0x80800220: beql        $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800224: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800234;
    }
    goto skip_1;
    // 0x80800224: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x80800228: b           L_80800258
    // 0x8080022C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
        goto L_80800258;
    // 0x8080022C: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
L_80800230:
    // 0x80800230: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800234:
    // 0x80800234: bne         $s1, $s2, L_80800204
    if (ctx->r17 != ctx->r18) {
        // 0x80800238: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80800204;
    }
    // 0x80800238: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_8080023C:
    // 0x8080023C: lw          $t8, 0x188($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X188);
    // 0x80800240: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80800244: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    // 0x80800248: slt         $at, $s6, $t8
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8080024C: bnel        $at, $zero, L_808001E4
    if (ctx->r1 != 0) {
        // 0x80800250: lh          $a0, 0x184($s7)
        ctx->r4 = MEM_H(ctx->r23, 0X184);
            goto L_808001E4;
    }
    goto skip_2;
    // 0x80800250: lh          $a0, 0x184($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X184);
    skip_2:
    // 0x80800254: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800258:
    // 0x80800258: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8080025C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800260: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800264: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800268: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080026C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800270: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800274: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80800278: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8080027C: jr          $ra
    // 0x80800280: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80800280: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800284: nop

    // 0x80800288: nop

    // 0x8080028C: nop

;}
RECOMP_FUNC void _basub_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085190: syscall     154
    recomp_syscall_handler(rdram, ctx, 0x80085190);
    return;
    // 0x80085194: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_8080023C_chterryegg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080023C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800240: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800244: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80800248: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080024C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800250: beq         $a1, $at, L_8080029C
    if (ctx->r5 == ctx->r1) {
        // 0x80800254: sw          $a2, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r6;
            goto L_8080029C;
    }
    // 0x80800254: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80800258: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8080025C: beq         $a1, $at, L_8080041C
    if (ctx->r5 == ctx->r1) {
        // 0x80800260: addiu       $at, $zero, 0x29
        ctx->r1 = ADD32(0, 0X29);
            goto L_8080041C;
    }
    // 0x80800260: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80800264: beq         $a1, $at, L_80800460
    if (ctx->r5 == ctx->r1) {
        // 0x80800268: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800460;
    }
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800270: beq         $a1, $at, L_808003C4
    if (ctx->r5 == ctx->r1) {
        // 0x80800274: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003C4;
    }
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800278: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8080027C: beq         $a1, $at, L_808003D4
    if (ctx->r5 == ctx->r1) {
        // 0x80800280: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808003D4;
    }
    // 0x80800280: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800284: beq         $a1, $at, L_8080047C
    if (ctx->r5 == ctx->r1) {
        // 0x80800288: addiu       $at, $zero, 0xA0
        ctx->r1 = ADD32(0, 0XA0);
            goto L_8080047C;
    }
    // 0x80800288: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x8080028C: beq         $a1, $at, L_80800340
    if (ctx->r5 == ctx->r1) {
        // 0x80800290: nop
    
            goto L_80800340;
    }
    // 0x80800290: nop

    // 0x80800294: b           L_80800568
    // 0x80800298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800568;
    // 0x80800298: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080029C:
    // 0x8080029C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808002A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808002A4: jal         0x800EE7F8
    // 0x808002A8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x808002A8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x808002AC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808002B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808002B4: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808002B8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808002BC: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x808002C0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808002C4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808002C8: jal         0x800EF1B8
    // 0x808002CC: nop

    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x808002CC: nop

    after_1:
    // 0x808002D0: jal         0x800F54E4
    // 0x808002D4: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x808002D4: nop

    after_2:
    // 0x808002D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002DC: jal         0x800F77E8
    // 0x808002E0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800F77E8(rdram, ctx);
        goto after_3;
    // 0x808002E0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x808002E4: jal         0x800F54E4
    // 0x808002E8: nop

    func_800F54E4(rdram, ctx);
        goto after_4;
    // 0x808002E8: nop

    after_4:
    // 0x808002EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808002F4: jal         0x800F8300
    // 0x808002F8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800F8300(rdram, ctx);
        goto after_5;
    // 0x808002F8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x808002FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800300: jal         0x80102424
    // 0x80800304: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800304: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_6:
    // 0x80800308: jal         0x80106790
    // 0x8080030C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_80106790(rdram, ctx);
        goto after_7;
    // 0x8080030C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_7:
    // 0x80800310: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800318: jal         0x80102424
    // 0x8080031C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x8080031C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800324: jal         0x80801188
    // 0x80800328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801188_chterryegg(rdram, ctx);
        goto after_9;
    // 0x80800328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8080032C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800330: jal         0x80102FDC
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_10;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800338: b           L_80800568
    // 0x8080033C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800568;
    // 0x8080033C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800340:
    // 0x80800340: jal         0x800DA298
    // 0x80800344: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x80800344: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    after_11:
    // 0x80800348: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8080034C: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800350: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80800354: beq         $t6, $zero, L_808003BC
    if (ctx->r14 == 0) {
        // 0x80800358: nop
    
            goto L_808003BC;
    }
    // 0x80800358: nop

    // 0x8080035C: beq         $v1, $zero, L_808003BC
    if (ctx->r3 == 0) {
        // 0x80800360: addiu       $a0, $zero, 0x39
        ctx->r4 = ADD32(0, 0X39);
            goto L_808003BC;
    }
    // 0x80800360: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    // 0x80800364: jal         0x800DA9E4
    // 0x80800368: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_12;
    // 0x80800368: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x8080036C: bne         $v0, $zero, L_80800398
    if (ctx->r2 != 0) {
        // 0x80800370: addiu       $a1, $zero, 0x180C
        ctx->r5 = ADD32(0, 0X180C);
            goto L_80800398;
    }
    // 0x80800370: addiu       $a1, $zero, 0x180C
    ctx->r5 = ADD32(0, 0X180C);
    // 0x80800374: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800378: addiu       $t7, $zero, 0x57
    ctx->r15 = ADD32(0, 0X57);
    // 0x8080037C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800380: addiu       $a1, $zero, 0x180B
    ctx->r5 = ADD32(0, 0X180B);
    // 0x80800384: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800388: jal         0x8008A208
    // 0x8080038C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_13;
    // 0x8080038C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x80800390: b           L_808003B4
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003B4;
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800398:
    // 0x80800398: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8080039C: addiu       $t8, $zero, 0x57
    ctx->r24 = ADD32(0, 0X57);
    // 0x808003A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808003A4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808003A8: jal         0x8008A208
    // 0x808003AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_14;
    // 0x808003AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_14:
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003B4:
    // 0x808003B4: jal         0x80102424
    // 0x808003B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_15;
    // 0x808003B8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
L_808003BC:
    // 0x808003BC: b           L_80800568
    // 0x808003C0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
        goto L_80800568;
    // 0x808003C0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_808003C4:
    // 0x808003C4: jal         0x80102424
    // 0x808003C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_16;
    // 0x808003C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x808003CC: b           L_80800568
    // 0x808003D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800568;
    // 0x808003D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003D4:
    // 0x808003D4: jal         0x80101080
    // 0x808003D8: nop

    func_80101080(rdram, ctx);
        goto after_17;
    // 0x808003D8: nop

    after_17:
    // 0x808003DC: jal         0x80106790
    // 0x808003E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_18;
    // 0x808003E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_18:
    // 0x808003E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808003E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808003EC: lui         $a1, 0x4416
    ctx->r5 = S32(0X4416 << 16);
    // 0x808003F0: jal         0x80086688
    // 0x808003F4: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_19;
    // 0x808003F4: lui         $a2, 0x4448
    ctx->r6 = S32(0X4448 << 16);
    after_19:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x800866B8
    // 0x80800400: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _chexploder_entrypoint_12(rdram, ctx);
        goto after_20;
    // 0x80800400: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_20:
    // 0x80800404: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800408: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080040C: jal         0x800866A0
    // 0x80800410: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_21;
    // 0x80800410: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_21:
    // 0x80800414: b           L_80800568
    // 0x80800418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800568;
    // 0x80800418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080041C:
    // 0x8080041C: jal         0x801015D0
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_22;
    // 0x80800420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x80800424: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800428: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8080042C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800430: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80800434: jal         0x800DF6BC
    // 0x80800438: nop

    func_800DF6BC(rdram, ctx);
        goto after_23;
    // 0x80800438: nop

    after_23:
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: jal         0x80100094
    // 0x80800444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_24;
    // 0x80800444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080044C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800450: jal         0x8008A078
    // 0x80800454: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    _subaddiepalette_entrypoint_3(rdram, ctx);
        goto after_25;
    // 0x80800454: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    after_25:
    // 0x80800458: b           L_80800568
    // 0x8080045C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800568;
    // 0x8080045C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800460:
    // 0x80800460: jal         0x80100094
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_26;
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80800468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080046C: jal         0x8008A080
    // 0x80800470: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _subaddiepalette_entrypoint_4(rdram, ctx);
        goto after_27;
    // 0x80800470: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_27:
    // 0x80800474: b           L_80800568
    // 0x80800478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800568;
    // 0x80800478: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080047C:
    // 0x8080047C: jal         0x80088840
    // 0x80800480: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_28;
    // 0x80800480: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    after_28:
    // 0x80800484: beq         $v0, $zero, L_808004D8
    if (ctx->r2 == 0) {
        // 0x80800488: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004D8;
    }
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: jal         0x80100094
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_29;
    // 0x80800490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80800494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800498: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080049C: jal         0x8008A060
    // 0x808004A0: addiu       $a2, $zero, 0x7BD
    ctx->r6 = ADD32(0, 0X7BD);
    _subaddiepalette_entrypoint_0(rdram, ctx);
        goto after_30;
    // 0x808004A0: addiu       $a2, $zero, 0x7BD
    ctx->r6 = ADD32(0, 0X7BD);
    after_30:
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: jal         0x80102424
    // 0x808004AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_31;
    // 0x808004AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_31:
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B4: jal         0x8008A4B0
    // 0x808004B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_32;
    // 0x808004B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_32:
    // 0x808004BC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808004C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808004C4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808004C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004CC: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x808004D0: b           L_80800544
    // 0x808004D4: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
        goto L_80800544;
    // 0x808004D4: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
L_808004D8:
    // 0x808004D8: jal         0x800DA298
    // 0x808004DC: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    func_800DA298(rdram, ctx);
        goto after_33;
    // 0x808004DC: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    after_33:
    // 0x808004E0: beq         $v0, $zero, L_8080051C
    if (ctx->r2 == 0) {
        // 0x808004E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080051C;
    }
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: jal         0x80102424
    // 0x808004F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_34;
    // 0x808004F0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_34:
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004F8: jal         0x80100094
    // 0x808004FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_35;
    // 0x808004FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800508: jal         0x8008A060
    // 0x8080050C: addiu       $a2, $zero, 0x7BE
    ctx->r6 = ADD32(0, 0X7BE);
    _subaddiepalette_entrypoint_0(rdram, ctx);
        goto after_36;
    // 0x8080050C: addiu       $a2, $zero, 0x7BE
    ctx->r6 = ADD32(0, 0X7BE);
    after_36:
    // 0x80800510: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800514: b           L_80800544
    // 0x80800518: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
        goto L_80800544;
    // 0x80800518: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_8080051C:
    // 0x8080051C: jal         0x80100094
    // 0x80800520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_37;
    // 0x80800520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
    // 0x80800524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080052C: jal         0x8008A060
    // 0x80800530: addiu       $a2, $zero, 0x7BD
    ctx->r6 = ADD32(0, 0X7BD);
    _subaddiepalette_entrypoint_0(rdram, ctx);
        goto after_38;
    // 0x80800530: addiu       $a2, $zero, 0x7BD
    ctx->r6 = ADD32(0, 0X7BD);
    after_38:
    // 0x80800534: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80800538: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080053C: nop

    // 0x80800540: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
L_80800544:
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800548: addiu       $a1, $zero, 0x3D6
    ctx->r5 = ADD32(0, 0X3D6);
    // 0x8080054C: jal         0x80089C58
    // 0x80800550: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    _subaddiefind_entrypoint_7(rdram, ctx);
        goto after_39;
    // 0x80800550: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_39:
    // 0x80800554: b           L_80800568
    // 0x80800558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800568;
    // 0x80800558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8080055C: b           L_80800568
    // 0x80800560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800568;
    // 0x80800560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800564: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800568:
    // 0x80800568: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080056C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800570: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800574: jr          $ra
    // 0x80800578: nop

    return;
    // 0x80800578: nop

;}
RECOMP_FUNC void _bashoes_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084FF0: syscall     148
    recomp_syscall_handler(rdram, ctx, 0x80084FF0);
    return;
    // 0x80084FF4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chminegrill2switches_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2056, 0X198) << 16);
    // 0x8080013C: jr          $ra
    // 0x80800140: addiu       $v0, $v0, 0x198
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2056, 0X198));
    return;
    // 0x80800140: addiu       $v0, $v0, 0x198
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2056, 0X198));
    // 0x80800144: nop

    // 0x80800148: nop

    // 0x8080014C: nop

;}
RECOMP_FUNC void func_808003E0_chhotwaterpoolbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808003E8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x808003EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003F0: beq         $a1, $at, L_8080040C
    if (ctx->r5 == ctx->r1) {
        // 0x808003F4: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8080040C;
    }
    // 0x808003F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003F8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808003FC: beq         $a1, $at, L_80800478
    if (ctx->r5 == ctx->r1) {
        // 0x80800400: nop
    
            goto L_80800478;
    }
    // 0x80800400: nop

    // 0x80800404: b           L_80800514
    // 0x80800408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800514;
    // 0x80800408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080040C:
    // 0x8080040C: addiu       $at, $zero, 0x3E7
    ctx->r1 = ADD32(0, 0X3E7);
    // 0x80800410: bne         $a2, $at, L_80800440
    if (ctx->r6 != ctx->r1) {
        // 0x80800414: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800440;
    }
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080041C: jal         0x80101FDC
    // 0x80800420: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x80800420: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: jal         0x80103110
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x8080042C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80800430: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80800434: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800438: b           L_80800510
    // 0x8080043C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800510;
    // 0x8080043C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800440:
    // 0x80800440: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1268, 0XA68) << 16);
    // 0x80800444: addiu       $a2, $a2, 0xA68
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1268, 0XA68));
    // 0x80800448: jal         0x80089D18
    // 0x8080044C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080044C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800454: jal         0x80101FDC
    // 0x80800458: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80101FDC(rdram, ctx);
        goto after_3;
    // 0x80800458: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x8080045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800460: jal         0x80103110
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x80800464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800468: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8080046C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800470: b           L_80800510
    // 0x80800474: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800510;
    // 0x80800474: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800478:
    // 0x80800478: jal         0x800DA298
    // 0x8080047C: addiu       $a0, $zero, 0x167
    ctx->r4 = ADD32(0, 0X167);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x8080047C: addiu       $a0, $zero, 0x167
    ctx->r4 = ADD32(0, 0X167);
    after_5:
    // 0x80800480: beq         $v0, $zero, L_808004BC
    if (ctx->r2 == 0) {
        // 0x80800484: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_808004BC;
    }
    // 0x80800484: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x80800488: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1268, 0XA5C) << 16);
    // 0x8080048C: jal         0x800F2E60
    // 0x80800490: addiu       $a1, $a1, 0xA5C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1268, 0XA5C));
    func_800F2E60(rdram, ctx);
        goto after_6;
    // 0x80800490: addiu       $a1, $a1, 0xA5C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1268, 0XA5C));
    after_6:
    // 0x80800494: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800498: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080049C: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x808004A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x808004AC: jal         0x800FFAB0
    // 0x808004B0: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x808004B0: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    after_7:
    // 0x808004B4: b           L_808004F8
    // 0x808004B8: nop

        goto L_808004F8;
    // 0x808004B8: nop

L_808004BC:
    // 0x808004BC: jal         0x800DA298
    // 0x808004C0: addiu       $a0, $zero, 0x31B
    ctx->r4 = ADD32(0, 0X31B);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x808004C0: addiu       $a0, $zero, 0x31B
    ctx->r4 = ADD32(0, 0X31B);
    after_8:
    // 0x808004C4: beq         $v0, $zero, L_808004F8
    if (ctx->r2 == 0) {
        // 0x808004C8: addiu       $a0, $s0, 0x28
        ctx->r4 = ADD32(ctx->r16, 0X28);
            goto L_808004F8;
    }
    // 0x808004C8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808004CC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1268, 0XA5C) << 16);
    // 0x808004D0: jal         0x800F2E60
    // 0x808004D4: addiu       $a1, $a1, 0xA5C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1268, 0XA5C));
    func_800F2E60(rdram, ctx);
        goto after_9;
    // 0x808004D4: addiu       $a1, $a1, 0xA5C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1268, 0XA5C));
    after_9:
    // 0x808004D8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808004DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808004E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808004E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808004EC: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x808004F0: jal         0x80101FDC
    // 0x808004F4: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x808004F4: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    after_10:
L_808004F8:
    // 0x808004F8: jal         0x80800528
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800528_chhotwaterpoolbits(rdram, ctx);
        goto after_11;
    // 0x808004FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800500: b           L_80800514
    // 0x80800504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800514;
    // 0x80800504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800508: b           L_80800514
    // 0x8080050C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800514;
    // 0x8080050C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800510:
    // 0x80800510: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800514:
    // 0x80800514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800518: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080051C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800520: jr          $ra
    // 0x80800524: nop

    return;
    // 0x80800524: nop

;}
RECOMP_FUNC void func_80800480_chklungospiral(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800480: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800484: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800488: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080048C: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x80800490: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800494: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1468, 0X688) << 16);
    // 0x80800498: sll         $t8, $t6, 19
    ctx->r24 = S32(ctx->r14 << 19);
    // 0x8080049C: bgezl       $t8, L_8080054C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808004A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080054C;
    }
    goto skip_0;
    // 0x808004A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808004A4: jal         0x80101E4C
    // 0x808004A8: addiu       $a1, $a1, 0x688
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1468, 0X688));
    func_80101E4C(rdram, ctx);
        goto after_0;
    // 0x808004A8: addiu       $a1, $a1, 0x688
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1468, 0X688));
    after_0:
    // 0x808004AC: beq         $v0, $zero, L_808004FC
    if (ctx->r2 == 0) {
        // 0x808004B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004FC;
    }
    // 0x808004B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004B4: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x808004B8: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x808004BC: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808004C0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808004C4: jal         0x80018820
    // 0x808004C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80018820(rdram, ctx);
        goto after_1;
    // 0x808004C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x808004CC: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808004D0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808004D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808004D8: jal         0x800E15CC
    // 0x808004DC: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    func_800E15CC(rdram, ctx);
        goto after_2;
    // 0x808004DC: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    after_2:
    // 0x808004E0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1468, 0X674) << 16);
    // 0x808004E4: addiu       $a2, $a2, 0x674
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1468, 0X674));
    // 0x808004E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004EC: jal         0x80089D18
    // 0x808004F0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_3;
    // 0x808004F0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x808004F4: b           L_8080054C
    // 0x808004F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080054C;
    // 0x808004F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808004FC:
    // 0x808004FC: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x80800500: jal         0x80101E14
    // 0x80800504: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    func_80101E14(rdram, ctx);
        goto after_4;
    // 0x80800504: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    after_4:
    // 0x80800508: beq         $v0, $zero, L_80800548
    if (ctx->r2 == 0) {
        // 0x8080050C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800548;
    }
    // 0x8080050C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800510: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x80800514: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800518: jal         0x80018820
    // 0x8080051C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80018820(rdram, ctx);
        goto after_5;
    // 0x8080051C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_5:
    // 0x80800520: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800524: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800528: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080052C: jal         0x800E15CC
    // 0x80800530: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_800E15CC(rdram, ctx);
        goto after_6;
    // 0x80800530: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_6:
    // 0x80800534: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1468, 0X674) << 16);
    // 0x80800538: addiu       $a2, $a2, 0x674
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1468, 0X674));
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800540: jal         0x80089D18
    // 0x80800544: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x80800544: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
L_80800548:
    // 0x80800548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080054C:
    // 0x8080054C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800550: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800554: jr          $ra
    // 0x80800558: nop

    return;
    // 0x80800558: nop

    // 0x8080055C: nop

;}
RECOMP_FUNC void _sccustom_banjo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A940: syscall     857
    recomp_syscall_handler(rdram, ctx, 0x8008A940);
    return;
    // 0x8008A944: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800FCC_chfactorytoxiccloud(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FCC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800FD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800FD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800FD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800FDC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80800FE0: jal         0x8001210C
    // 0x80800FE4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_8001210C(rdram, ctx);
        goto after_0;
    // 0x80800FE4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80800FE8: beq         $v0, $zero, L_80800FF4
    if (ctx->r2 == 0) {
        // 0x80800FEC: lw          $t6, 0x54($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X54);
            goto L_80800FF4;
    }
    // 0x80800FEC: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80800FF0: beq         $t6, $zero, L_808010A4
    if (ctx->r14 == 0) {
        // 0x80800FF4: addiu       $a1, $s0, 0x4
        ctx->r5 = ADD32(ctx->r16, 0X4);
            goto L_808010A4;
    }
L_80800FF4:
    // 0x80800FF4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800FF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800FFC: jal         0x800EE7F8
    // 0x80801000: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80801000: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80801004: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80801008: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080100C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80801010: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80801014: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801018: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080101C: jal         0x800EE7F8
    // 0x80801020: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80801020: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80801024: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80801028: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080102C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801030: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80801034: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80801038: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8080103C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80801040: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80801044: jal         0x800BEF00
    // 0x80801048: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    func_800BEF00(rdram, ctx);
        goto after_3;
    // 0x80801048: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8080104C: beq         $v0, $zero, L_8080105C
    if (ctx->r2 == 0) {
        // 0x80801050: lwc1        $f4, 0x38($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
            goto L_8080105C;
    }
    // 0x80801050: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80801054: b           L_80801064
    // 0x80801058: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
        goto L_80801064;
    // 0x80801058: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
L_8080105C:
    // 0x8080105C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801060: swc1        $f6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f6.u32l;
L_80801064:
    // 0x80801064: lw          $v0, 0x70($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X70);
    // 0x80801068: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x8080106C: srl         $t7, $a1, 26
    ctx->r15 = S32(U32(ctx->r5) >> 26);
    // 0x80801070: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x80801074: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80801078: jal         0x800CC63C
    // 0x8080107C: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_4;
    // 0x8080107C: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    after_4:
    // 0x80801080: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x80801084: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80801088: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8080108C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80801090: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801094: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80801098: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8080109C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x808010A0: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_808010A4:
    // 0x808010A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808010A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808010AC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x808010B0: jr          $ra
    // 0x808010B4: nop

    return;
    // 0x808010B4: nop

;}
RECOMP_FUNC void bainput_func_80097FB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80097FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097FC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80097FC4: jal         0x80091A58
    // 0x80097FC8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80097FC8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80097FCC: sltu        $t6, $zero, $v0
    ctx->r14 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097FD0: beq         $t6, $zero, L_80098014
    if (ctx->r14 == 0) {
        // 0x80097FD4: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_80098014;
    }
    // 0x80097FD4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80097FD8: jal         0x800C6E38
    // 0x80097FDC: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800C6E38(rdram, ctx);
        goto after_1;
    // 0x80097FDC: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_1:
    // 0x80097FE0: sltu        $t7, $zero, $v0
    ctx->r15 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097FE4: beq         $t7, $zero, L_80098014
    if (ctx->r15 == 0) {
        // 0x80097FE8: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80098014;
    }
    // 0x80097FE8: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80097FEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80097FF0: jal         0x80095748
    // 0x80097FF4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    baflag_isFalse(rdram, ctx);
        goto after_2;
    // 0x80097FF4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x80097FF8: sltu        $t8, $zero, $v0
    ctx->r24 = 0 < ctx->r2 ? 1 : 0;
    // 0x80097FFC: beq         $t8, $zero, L_80098014
    if (ctx->r24 == 0) {
        // 0x80098000: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80098014;
    }
    // 0x80098000: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80098004: jal         0x8008E39C
    // 0x80098008: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8008E39C(rdram, ctx);
        goto after_3;
    // 0x80098008: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8009800C: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80098010: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80098014:
    // 0x80098014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009801C: jr          $ra
    // 0x80098020: nop

    return;
    // 0x80098020: nop

;}
RECOMP_FUNC void func_808003AC_bainvisible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003B4: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x808003B8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x808003BC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x808003C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808003C4: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808003C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(653, 0X9B8) << 16);
    // 0x808003CC: mul.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x808003D0: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x808003D4: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x808003D8: jal         0x800F214C
    // 0x808003DC: lwc1        $f14, 0x9B8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(653, 0X9B8));
    func_800F214C(rdram, ctx);
        goto after_0;
    // 0x808003DC: lwc1        $f14, 0x9B8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(653, 0X9B8));
    after_0:
    // 0x808003E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x808003E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003EC: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x808003F0: nop

    // 0x808003F4: bc1f        L_80800400
    if (!c1cs) {
        // 0x808003F8: nop
    
            goto L_80800400;
    }
    // 0x808003F8: nop

    // 0x808003FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800400:
    // 0x80800400: jr          $ra
    // 0x80800404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void bsjig_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001BC: jal         0x8008CABC
    // 0x808001C0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001C0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x808001C4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808001C8: jal         0x8009F308
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009F308(rdram, ctx);
        goto after_1;
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808001D4: jal         0x8009C914
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_2;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808001DC: lui         $a1, 0x3F26
    ctx->r5 = S32(0X3F26 << 16);
    // 0x808001E0: ori         $a1, $a1, 0x7382
    ctx->r5 = ctx->r5 | 0X7382;
    // 0x808001E4: jal         0x8008B348
    // 0x808001E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_3;
    // 0x808001E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x808001EC: beql        $v0, $zero, L_80800200
    if (ctx->r2 == 0) {
        // 0x808001F0: lui         $a1, 0x3F55
        ctx->r5 = S32(0X3F55 << 16);
            goto L_80800200;
    }
    goto skip_0;
    // 0x808001F0: lui         $a1, 0x3F55
    ctx->r5 = S32(0X3F55 << 16);
    skip_0:
    // 0x808001F4: jal         0x8009D874
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009D874(rdram, ctx);
        goto after_4;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001FC: lui         $a1, 0x3F55
    ctx->r5 = S32(0X3F55 << 16);
L_80800200:
    // 0x80800200: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x80800204: jal         0x8008B348
    // 0x80800208: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_5;
    // 0x80800208: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x8080020C: beq         $v0, $zero, L_80800230
    if (ctx->r2 == 0) {
        // 0x80800210: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800230;
    }
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800214: lw          $t6, 0x15C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X15C);
    // 0x80800218: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x8080021C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800220: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80800224: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
    // 0x80800228: jal         0x8009DE38
    // 0x8080022C: addiu       $a1, $zero, 0x434
    ctx->r5 = ADD32(0, 0X434);
    func_8009DE38(rdram, ctx);
        goto after_6;
    // 0x8080022C: addiu       $a1, $zero, 0x434
    ctx->r5 = ADD32(0, 0X434);
    after_6:
L_80800230:
    // 0x80800230: lui         $a1, 0x3F70
    ctx->r5 = S32(0X3F70 << 16);
    // 0x80800234: ori         $a1, $a1, 0xA3D7
    ctx->r5 = ctx->r5 | 0XA3D7;
    // 0x80800238: jal         0x8008B348
    // 0x8080023C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isAt(rdram, ctx);
        goto after_7;
    // 0x8080023C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x80800240: beq         $v0, $zero, L_80800254
    if (ctx->r2 == 0) {
        // 0x80800244: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800254;
    }
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: addiu       $a1, $zero, 0x3EA
    ctx->r5 = ADD32(0, 0X3EA);
    // 0x8080024C: jal         0x8009DE38
    // 0x80800250: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_8009DE38(rdram, ctx);
        goto after_8;
    // 0x80800250: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_8:
L_80800254:
    // 0x80800254: jal         0x8008B324
    // 0x80800258: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    anctrl_isStopped(rdram, ctx);
        goto after_9;
    // 0x80800258: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x8080025C: beq         $v0, $zero, L_80800284
    if (ctx->r2 == 0) {
        // 0x80800260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800284;
    }
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800264: lw          $t8, 0x160($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X160);
    // 0x80800268: addiu       $t9, $zero, 0x34
    ctx->r25 = ADD32(0, 0X34);
    // 0x8080026C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80800270: beql        $t8, $zero, L_80800284
    if (ctx->r24 == 0) {
        // 0x80800274: sw          $t0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r8;
            goto L_80800284;
    }
    goto skip_1;
    // 0x80800274: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    skip_1:
    // 0x80800278: b           L_80800284
    // 0x8080027C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
        goto L_80800284;
    // 0x8080027C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80800280: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
L_80800284:
    // 0x80800284: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80800288: addiu       $a1, $a1, 0x31E0
    ctx->r5 = ADD32(ctx->r5, 0X31E0);
    // 0x8080028C: jal         0x8009919C
    // 0x80800290: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    func_8009919C(rdram, ctx);
        goto after_10;
    // 0x80800290: lw          $a2, 0x184($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X184);
    after_10:
    // 0x80800294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800298: jal         0x8009E5C8
    // 0x8080029C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_11;
    // 0x8080029C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x808002A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002AC: jr          $ra
    // 0x808002B0: nop

    return;
    // 0x808002B0: nop

;}
RECOMP_FUNC void fxspgold_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800028: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080002C: jal         0x800B5758
    // 0x80800030: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_800B5758(rdram, ctx);
        goto after_0;
    // 0x80800030: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8080003C: sb          $v0, 0x7120($at)
    MEM_B(0X7120, ctx->r1) = ctx->r2;
    // 0x80800040: jr          $ra
    // 0x80800044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800000_bsdie(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800004: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80800008: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080000C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80800010: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80800014: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800018: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8080001C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800020: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x80800024: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80800028: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8080002C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800030: bc1f        L_8080006C
    if (!c1cs) {
        // 0x80800034: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_8080006C;
    }
    // 0x80800034: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80800038: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8080003C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80800040: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800044: nop

    // 0x80800048: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_8080004C:
    // 0x8080004C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800050: jal         0x800849F0
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _badust_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800058: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x8080005C: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x80800060: nop

    // 0x80800064: bc1tl       L_8080004C
    if (c1cs) {
        // 0x80800068: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_8080004C;
    }
    goto skip_0;
    // 0x80800068: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_0:
L_8080006C:
    // 0x8080006C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80800070: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800074: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800078: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8080007C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800080: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80800084: jr          $ra
    // 0x80800088: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80800088: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _bsbanbflip_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082670: syscall     5
    recomp_syscall_handler(rdram, ctx, 0x80082670);
    return;
    // 0x80082674: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _sumumbofx_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089850: syscall     797
    recomp_syscall_handler(rdram, ctx, 0x80089850);
    return;
    // 0x80089854: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
