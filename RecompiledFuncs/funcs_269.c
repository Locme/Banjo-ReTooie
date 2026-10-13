#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F7844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7844: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800F7848: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800F784C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7850: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F7854: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800F7858: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800F785C: jal         0x800F7750
    // 0x800F7860: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800F7750(rdram, ctx);
        goto after_0;
    // 0x800F7860: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x800F7864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F786C: jr          $ra
    // 0x800F7870: nop

    return;
    // 0x800F7870: nop

;}
RECOMP_FUNC void chdummyjigsaw_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800174: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2236, 0X190) << 16);
    // 0x80800178: jr          $ra
    // 0x8080017C: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2236, 0X190));
    return;
    // 0x8080017C: addiu       $v0, $v0, 0x190
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2236, 0X190));
;}
RECOMP_FUNC void bawandglow_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080018C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800194: lw          $t6, 0x148($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X148);
    // 0x80800198: lw          $a1, 0xC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XC);
    // 0x8080019C: beql        $a1, $zero, L_808001B0
    if (ctx->r5 == 0) {
        // 0x808001A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001B0;
    }
    goto skip_0;
    // 0x808001A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001A4: jal         0x80087300
    // 0x808001A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    _chwandglow_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808001A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x808001AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001B0:
    // 0x808001B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001B4: jr          $ra
    // 0x808001B8: nop

    return;
    // 0x808001B8: nop

;}
RECOMP_FUNC void func_800A8D70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8D70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A8D74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A8D78: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A8D7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A8D80: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A8D84: jal         0x80088318
    // 0x800A8D88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    _gcstatusDll_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x800A8D88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A8D8C: jal         0x80088258
    // 0x800A8D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcsectionDll_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x800A8D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800A8D94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A8D98: jal         0x80088260
    // 0x800A8D9C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    _gcsectionDll_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x800A8D9C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_2:
    // 0x800A8DA0: beq         $v0, $zero, L_800A8DC0
    if (ctx->r2 == 0) {
        // 0x800A8DA4: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_800A8DC0;
    }
    // 0x800A8DA4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A8DA8: jal         0x80088368
    // 0x800A8DAC: nop

    _gcstatusDll_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x800A8DAC: nop

    after_3:
    // 0x800A8DB0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A8DB4: addiu       $s1, $s1, 0x76D0
    ctx->r17 = ADD32(ctx->r17, 0X76D0);
    // 0x800A8DB8: b           L_800A8DCC
    // 0x800A8DBC: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
        goto L_800A8DCC;
    // 0x800A8DBC: sh          $v0, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r2;
L_800A8DC0:
    // 0x800A8DC0: addiu       $s1, $s1, 0x76D0
    ctx->r17 = ADD32(ctx->r17, 0X76D0);
    // 0x800A8DC4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A8DC8: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
L_800A8DCC:
    // 0x800A8DCC: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x800A8DD0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A8DD4: blez        $t7, L_800A8DF8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A8DD8: nop
    
            goto L_800A8DF8;
    }
    // 0x800A8DD8: nop

L_800A8DDC:
    // 0x800A8DDC: jal         0x800A877C
    // 0x800A8DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A877C(rdram, ctx);
        goto after_4;
    // 0x800A8DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800A8DE4: lh          $t8, 0x2($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X2);
    // 0x800A8DE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800A8DEC: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800A8DF0: bne         $at, $zero, L_800A8DDC
    if (ctx->r1 != 0) {
        // 0x800A8DF4: nop
    
            goto L_800A8DDC;
    }
    // 0x800A8DF4: nop

L_800A8DF8:
    // 0x800A8DF8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8DFC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A8E00: addiu       $a0, $a0, 0x76E0
    ctx->r4 = ADD32(ctx->r4, 0X76E0);
    // 0x800A8E04: addiu       $v0, $v0, 0x76D0
    ctx->r2 = ADD32(ctx->r2, 0X76D0);
    // 0x800A8E08: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800A8E0C:
    // 0x800A8E0C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800A8E10: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800A8E14: bne         $at, $zero, L_800A8E0C
    if (ctx->r1 != 0) {
        // 0x800A8E18: sh          $v1, 0x6($v0)
        MEM_H(0X6, ctx->r2) = ctx->r3;
            goto L_800A8E0C;
    }
    // 0x800A8E18: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x800A8E1C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8E20: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8E24: addiu       $v1, $v1, 0x76D4
    ctx->r3 = ADD32(ctx->r3, 0X76D4);
    // 0x800A8E28: addiu       $v0, $v0, 0x76D0
    ctx->r2 = ADD32(ctx->r2, 0X76D0);
L_800A8E2C:
    // 0x800A8E2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800A8E30: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800A8E34: bne         $at, $zero, L_800A8E2C
    if (ctx->r1 != 0) {
        // 0x800A8E38: sb          $zero, 0x3($v0)
        MEM_B(0X3, ctx->r2) = 0;
            goto L_800A8E2C;
    }
    // 0x800A8E38: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800A8E3C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8E40: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8E44: addiu       $v1, $v1, 0x76F0
    ctx->r3 = ADD32(ctx->r3, 0X76F0);
    // 0x800A8E48: addiu       $v0, $v0, 0x76D0
    ctx->r2 = ADD32(ctx->r2, 0X76D0);
L_800A8E4C:
    // 0x800A8E4C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800A8E50: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800A8E54: bne         $at, $zero, L_800A8E4C
    if (ctx->r1 != 0) {
        // 0x800A8E58: sw          $zero, 0x34($v0)
        MEM_W(0X34, ctx->r2) = 0;
            goto L_800A8E4C;
    }
    // 0x800A8E58: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x800A8E5C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A8E60: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8E64: addiu       $v1, $v1, 0x76F0
    ctx->r3 = ADD32(ctx->r3, 0X76F0);
    // 0x800A8E68: addiu       $v0, $v0, 0x76D0
    ctx->r2 = ADD32(ctx->r2, 0X76D0);
L_800A8E6C:
    // 0x800A8E6C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800A8E70: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800A8E74: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800A8E78: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x800A8E7C: bne         $v0, $v1, L_800A8E6C
    if (ctx->r2 != ctx->r3) {
        // 0x800A8E80: sw          $zero, 0x8($v0)
        MEM_W(0X8, ctx->r2) = 0;
            goto L_800A8E6C;
    }
    // 0x800A8E80: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800A8E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A8E88: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x800A8E8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A8E90: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A8E94: jr          $ra
    // 0x800A8E98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A8E98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80801CDC_chdinoboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801CDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801CE4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80801CE8: lbu         $a1, 0x5E($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X5E);
    // 0x80801CEC: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80801CF0: jal         0x800D2498
    // 0x80801CF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_0;
    // 0x80801CF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80801CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801CFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801D00: jr          $ra
    // 0x80801D04: nop

    return;
    // 0x80801D04: nop

;}
RECOMP_FUNC void func_80800020_chfog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800024: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080002C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800030: jal         0x800E3980
    // 0x80800034: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    func_800E3980(rdram, ctx);
        goto after_0;
    // 0x80800034: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    after_0:
    // 0x80800038: jal         0x800EFD24
    // 0x8080003C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8080003C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800040: jal         0x800EFD24
    // 0x80800044: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80800044: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_2:
    // 0x80800048: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080004C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800050: nop

    // 0x80800054: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800058: jal         0x800EA05C
    // 0x8080005C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    func_800EA05C(rdram, ctx);
        goto after_3;
    // 0x8080005C: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x80800060: addiu       $at, $zero, 0x10D
    ctx->r1 = ADD32(0, 0X10D);
    // 0x80800064: beq         $v0, $at, L_80800090
    if (ctx->r2 == ctx->r1) {
        // 0x80800068: addiu       $at, $zero, 0x138
        ctx->r1 = ADD32(0, 0X138);
            goto L_80800090;
    }
    // 0x80800068: addiu       $at, $zero, 0x138
    ctx->r1 = ADD32(0, 0X138);
    // 0x8080006C: beq         $v0, $at, L_80800100
    if (ctx->r2 == ctx->r1) {
        // 0x80800070: addiu       $at, $zero, 0x162
        ctx->r1 = ADD32(0, 0X162);
            goto L_80800100;
    }
    // 0x80800070: addiu       $at, $zero, 0x162
    ctx->r1 = ADD32(0, 0X162);
    // 0x80800074: beq         $v0, $at, L_80800110
    if (ctx->r2 == ctx->r1) {
        // 0x80800078: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800110;
    }
    // 0x80800078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080007C: addiu       $at, $zero, 0x19A
    ctx->r1 = ADD32(0, 0X19A);
    // 0x80800080: beq         $v0, $at, L_80800130
    if (ctx->r2 == ctx->r1) {
        // 0x80800084: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800130;
    }
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: b           L_80800158
    // 0x8080008C: nop

        goto L_80800158;
    // 0x8080008C: nop

L_80800090:
    // 0x80800090: jal         0x800DA298
    // 0x80800094: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x80800094: addiu       $a0, $zero, 0x1BD
    ctx->r4 = ADD32(0, 0X1BD);
    after_4:
    // 0x80800098: bnel        $v0, $zero, L_808000B4
    if (ctx->r2 != 0) {
        // 0x8080009C: lw          $t6, 0x78($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X78);
            goto L_808000B4;
    }
    goto skip_0;
    // 0x8080009C: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    skip_0:
    // 0x808000A0: jal         0x800FFAB0
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000A8: b           L_808000EC
    // 0x808000AC: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
        goto L_808000EC;
    // 0x808000AC: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x808000B0: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
L_808000B4:
    // 0x808000B4: sll         $t8, $t6, 26
    ctx->r24 = S32(ctx->r14 << 26);
    // 0x808000B8: bgezl       $t8, L_808000EC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808000BC: lbu         $t0, 0x65($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X65);
            goto L_808000EC;
    }
    goto skip_1;
    // 0x808000BC: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    skip_1:
    // 0x808000C0: jal         0x800F54E4
    // 0x808000C4: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x808000C4: nop

    after_6:
    // 0x808000C8: jal         0x800F6438
    // 0x808000CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_7;
    // 0x808000CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x808000D0: beql        $v0, $zero, L_808000EC
    if (ctx->r2 == 0) {
        // 0x808000D4: lbu         $t0, 0x65($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X65);
            goto L_808000EC;
    }
    goto skip_2;
    // 0x808000D4: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    skip_2:
    // 0x808000D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000DC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808000E0: jal         0x800CF2D4
    // 0x808000E4: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    func_800CF2D4(rdram, ctx);
        goto after_8;
    // 0x808000E4: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    after_8:
    // 0x808000E8: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
L_808000EC:
    // 0x808000EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808000F0: ori         $t1, $t0, 0x8
    ctx->r9 = ctx->r8 | 0X8;
    // 0x808000F4: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
    // 0x808000F8: b           L_80800160
    // 0x808000FC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_80800160;
    // 0x808000FC: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80800100:
    // 0x80800100: jal         0x800CF2D4
    // 0x80800104: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800CF2D4(rdram, ctx);
        goto after_9;
    // 0x80800104: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
    // 0x80800108: b           L_80800164
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800164;
    // 0x8080010C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800110:
    // 0x80800110: jal         0x80101FDC
    // 0x80800114: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_10;
    // 0x80800114: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800118: jal         0x80089CA0
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800120: jal         0x800CF2D4
    // 0x80800124: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800CF2D4(rdram, ctx);
        goto after_12;
    // 0x80800124: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_12:
    // 0x80800128: b           L_80800164
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800164;
    // 0x8080012C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800130:
    // 0x80800130: jal         0x80101FDC
    // 0x80800134: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_13;
    // 0x80800134: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x80800138: jal         0x80089CA0
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800140: jal         0x800CF2D4
    // 0x80800144: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_800CF2D4(rdram, ctx);
        goto after_15;
    // 0x80800144: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_15:
    // 0x80800148: lbu         $t2, 0x75($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X75);
    // 0x8080014C: andi        $t3, $t2, 0xFFFD
    ctx->r11 = ctx->r10 & 0XFFFD;
    // 0x80800150: b           L_80800160
    // 0x80800154: sb          $t3, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r11;
        goto L_80800160;
    // 0x80800154: sb          $t3, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r11;
L_80800158:
    // 0x80800158: jal         0x800CF2D4
    // 0x8080015C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800CF2D4(rdram, ctx);
        goto after_16;
    // 0x8080015C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_16:
L_80800160:
    // 0x80800160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800164:
    // 0x80800164: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080016C: jr          $ra
    // 0x80800170: nop

    return;
    // 0x80800170: nop

;}
RECOMP_FUNC void bstnt_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802028: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080202C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(404, 0X25AC) << 16);
    // 0x80802030: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80802034: jr          $ra
    // 0x80802038: lw          $v0, 0x25AC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X25AC));
    return;
    // 0x80802038: lw          $v0, 0x25AC($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(404, 0X25AC));
;}
RECOMP_FUNC void func_80800140_chstoneballcoach(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800144: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800148: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080014C: jal         0x80090128
    // 0x80800150: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80090128(rdram, ctx);
        goto after_0;
    // 0x80800150: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800154: beq         $v0, $zero, L_80800170
    if (ctx->r2 == 0) {
        // 0x80800158: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800170;
    }
    // 0x80800158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080015C: addiu       $a1, $zero, 0x8C
    ctx->r5 = ADD32(0, 0X8C);
    // 0x80800160: jal         0x8010C820
    // 0x80800164: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_8010C820(rdram, ctx);
        goto after_1;
    // 0x80800164: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_1:
    // 0x80800168: jal         0x80800100
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800100_chstoneballcoach(rdram, ctx);
        goto after_2;
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80800170:
    // 0x80800170: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800174: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800178: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x8080017C: bnel        $t7, $at, L_8080034C
    if (ctx->r15 != ctx->r1) {
        // 0x80800180: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080034C;
    }
    goto skip_0;
    // 0x80800180: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800184: jal         0x80090178
    // 0x80800188: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    func_80090178(rdram, ctx);
        goto after_3;
    // 0x80800188: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_3:
    // 0x8080018C: beq         $v0, $zero, L_80800300
    if (ctx->r2 == 0) {
        // 0x80800190: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1616, 0X3C8) << 16);
            goto L_80800300;
    }
    // 0x80800190: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1616, 0X3C8) << 16);
    // 0x80800194: addiu       $a0, $a0, 0x3C8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1616, 0X3C8));
    // 0x80800198: jal         0x8010CAC0
    // 0x8080019C: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    func_8010CAC0(rdram, ctx);
        goto after_4;
    // 0x8080019C: addiu       $a1, $zero, 0x96
    ctx->r5 = ADD32(0, 0X96);
    after_4:
    // 0x808001A0: beq         $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x808001A4: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_808001D0;
    }
    // 0x808001A4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808001A8: addiu       $a0, $zero, 0x428
    ctx->r4 = ADD32(0, 0X428);
    // 0x808001AC: jal         0x800DA9E4
    // 0x808001B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DA9E4(rdram, ctx);
        goto after_5;
    // 0x808001B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808001B4: bne         $v0, $zero, L_80800348
    if (ctx->r2 != 0) {
        // 0x808001B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800348;
    }
    // 0x808001B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001BC: addiu       $a1, $zero, 0xF23
    ctx->r5 = ADD32(0, 0XF23);
    // 0x808001C0: jal         0x80800090
    // 0x808001C4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_80800090_chstoneballcoach(rdram, ctx);
        goto after_6;
    // 0x808001C4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_6:
    // 0x808001C8: b           L_8080034C
    // 0x808001CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080034C;
    // 0x808001CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001D0:
    // 0x808001D0: jal         0x8010CAC0
    // 0x808001D4: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_8010CAC0(rdram, ctx);
        goto after_7;
    // 0x808001D4: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_7:
    // 0x808001D8: beq         $v0, $zero, L_80800348
    if (ctx->r2 == 0) {
        // 0x808001DC: addiu       $a0, $zero, 0x80
        ctx->r4 = ADD32(0, 0X80);
            goto L_80800348;
    }
    // 0x808001DC: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x808001E0: jal         0x8008FA60
    // 0x808001E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008FA60(rdram, ctx);
        goto after_8;
    // 0x808001E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808001E8: beq         $v0, $zero, L_80800348
    if (ctx->r2 == 0) {
        // 0x808001EC: addiu       $t8, $zero, 0x6
        ctx->r24 = ADD32(0, 0X6);
            goto L_80800348;
    }
    // 0x808001EC: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x808001F0: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x808001F4: lhu         $a0, 0x76($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X76);
    // 0x808001F8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x808001FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800200: srl         $t9, $a0, 7
    ctx->r25 = S32(U32(ctx->r4) >> 7);
    // 0x80800204: jal         0x800DA9E4
    // 0x80800208: addiu       $a0, $t9, 0x3F3
    ctx->r4 = ADD32(ctx->r25, 0X3F3);
    func_800DA9E4(rdram, ctx);
        goto after_9;
    // 0x80800208: addiu       $a0, $t9, 0x3F3
    ctx->r4 = ADD32(ctx->r25, 0X3F3);
    after_9:
    // 0x8080020C: bne         $v0, $zero, L_8080026C
    if (ctx->r2 != 0) {
        // 0x80800210: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_8080026C;
    }
    // 0x80800210: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800214: jal         0x800DA298
    // 0x80800218: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_800DA298(rdram, ctx);
        goto after_10;
    // 0x80800218: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_10:
    // 0x8080021C: beq         $v0, $zero, L_80800234
    if (ctx->r2 == 0) {
        // 0x80800220: nop
    
            goto L_80800234;
    }
    // 0x80800220: nop

    // 0x80800224: lhu         $a3, 0x76($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X76);
    // 0x80800228: srl         $t0, $a3, 7
    ctx->r8 = S32(U32(ctx->r7) >> 7);
    // 0x8080022C: b           L_80800260
    // 0x80800230: addiu       $a3, $t0, 0xEF8
    ctx->r7 = ADD32(ctx->r8, 0XEF8);
        goto L_80800260;
    // 0x80800230: addiu       $a3, $t0, 0xEF8
    ctx->r7 = ADD32(ctx->r8, 0XEF8);
L_80800234:
    // 0x80800234: jal         0x800DA298
    // 0x80800238: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    func_800DA298(rdram, ctx);
        goto after_11;
    // 0x80800238: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    after_11:
    // 0x8080023C: beql        $v0, $zero, L_80800258
    if (ctx->r2 == 0) {
        // 0x80800240: lhu         $a3, 0x76($s0)
        ctx->r7 = MEM_HU(ctx->r16, 0X76);
            goto L_80800258;
    }
    goto skip_1;
    // 0x80800240: lhu         $a3, 0x76($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X76);
    skip_1:
    // 0x80800244: lhu         $a3, 0x76($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X76);
    // 0x80800248: srl         $t1, $a3, 7
    ctx->r9 = S32(U32(ctx->r7) >> 7);
    // 0x8080024C: b           L_80800260
    // 0x80800250: addiu       $a3, $t1, 0xEF5
    ctx->r7 = ADD32(ctx->r9, 0XEF5);
        goto L_80800260;
    // 0x80800250: addiu       $a3, $t1, 0xEF5
    ctx->r7 = ADD32(ctx->r9, 0XEF5);
    // 0x80800254: lhu         $a3, 0x76($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X76);
L_80800258:
    // 0x80800258: srl         $t2, $a3, 7
    ctx->r10 = S32(U32(ctx->r7) >> 7);
    // 0x8080025C: addiu       $a3, $t2, 0xEF2
    ctx->r7 = ADD32(ctx->r10, 0XEF2);
L_80800260:
    // 0x80800260: addiu       $t3, $zero, 0xE
    ctx->r11 = ADD32(0, 0XE);
    // 0x80800264: b           L_808002E8
    // 0x80800268: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
        goto L_808002E8;
    // 0x80800268: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_8080026C:
    // 0x8080026C: jal         0x80090080
    // 0x80800270: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80090080(rdram, ctx);
        goto after_12;
    // 0x80800270: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_12:
    // 0x80800274: beq         $v0, $zero, L_808002E8
    if (ctx->r2 == 0) {
        // 0x80800278: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_808002E8;
    }
    // 0x80800278: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8080027C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800284: jal         0x80016B30
    // 0x80800288: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80016B30(rdram, ctx);
        goto after_13;
    // 0x80800288: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_13:
    // 0x8080028C: beq         $v0, $zero, L_808002E8
    if (ctx->r2 == 0) {
        // 0x80800290: lw          $a3, 0x2C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X2C);
            goto L_808002E8;
    }
    // 0x80800290: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800294: jal         0x800DA298
    // 0x80800298: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x80800298: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    after_14:
    // 0x8080029C: beq         $v0, $zero, L_808002B4
    if (ctx->r2 == 0) {
        // 0x808002A0: nop
    
            goto L_808002B4;
    }
    // 0x808002A0: nop

    // 0x808002A4: lhu         $a3, 0x76($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X76);
    // 0x808002A8: srl         $t4, $a3, 7
    ctx->r12 = S32(U32(ctx->r7) >> 7);
    // 0x808002AC: b           L_808002E0
    // 0x808002B0: addiu       $a3, $t4, 0xF18
    ctx->r7 = ADD32(ctx->r12, 0XF18);
        goto L_808002E0;
    // 0x808002B0: addiu       $a3, $t4, 0xF18
    ctx->r7 = ADD32(ctx->r12, 0XF18);
L_808002B4:
    // 0x808002B4: jal         0x800DA298
    // 0x808002B8: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    func_800DA298(rdram, ctx);
        goto after_15;
    // 0x808002B8: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    after_15:
    // 0x808002BC: beql        $v0, $zero, L_808002D8
    if (ctx->r2 == 0) {
        // 0x808002C0: lhu         $a3, 0x76($s0)
        ctx->r7 = MEM_HU(ctx->r16, 0X76);
            goto L_808002D8;
    }
    goto skip_2;
    // 0x808002C0: lhu         $a3, 0x76($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X76);
    skip_2:
    // 0x808002C4: lhu         $a3, 0x76($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X76);
    // 0x808002C8: srl         $t5, $a3, 7
    ctx->r13 = S32(U32(ctx->r7) >> 7);
    // 0x808002CC: b           L_808002E0
    // 0x808002D0: addiu       $a3, $t5, 0xF15
    ctx->r7 = ADD32(ctx->r13, 0XF15);
        goto L_808002E0;
    // 0x808002D0: addiu       $a3, $t5, 0xF15
    ctx->r7 = ADD32(ctx->r13, 0XF15);
    // 0x808002D4: lhu         $a3, 0x76($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X76);
L_808002D8:
    // 0x808002D8: srl         $t6, $a3, 7
    ctx->r14 = S32(U32(ctx->r7) >> 7);
    // 0x808002DC: addiu       $a3, $t6, 0xF12
    ctx->r7 = ADD32(ctx->r14, 0XF12);
L_808002E0:
    // 0x808002E0: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x808002E4: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
L_808002E8:
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808002F0: jal         0x80800090
    // 0x808002F4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    func_80800090_chstoneballcoach(rdram, ctx);
        goto after_16;
    // 0x808002F4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_16:
    // 0x808002F8: b           L_8080034C
    // 0x808002FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080034C;
    // 0x808002FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800300:
    // 0x80800300: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800304: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80800308: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080030C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800310: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800314: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x80800318: addiu       $a3, $zero, 0x46
    ctx->r7 = ADD32(0, 0X46);
    // 0x8080031C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800320: jal         0x8008A1E0
    // 0x80800324: nop

    _subaddiedialog_entrypoint_6(rdram, ctx);
        goto after_17;
    // 0x80800324: nop

    after_17:
    // 0x80800328: beql        $v0, $zero, L_8080034C
    if (ctx->r2 == 0) {
        // 0x8080032C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8080034C;
    }
    goto skip_3;
    // 0x8080032C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800330: lhu         $a1, 0x76($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X76);
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800338: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8080033C: srl         $t0, $a1, 7
    ctx->r8 = S32(U32(ctx->r5) >> 7);
    // 0x80800340: jal         0x80800090
    // 0x80800344: addiu       $a1, $t0, 0xF21
    ctx->r5 = ADD32(ctx->r8, 0XF21);
    func_80800090_chstoneballcoach(rdram, ctx);
        goto after_18;
    // 0x80800344: addiu       $a1, $t0, 0xF21
    ctx->r5 = ADD32(ctx->r8, 0XF21);
    after_18:
L_80800348:
    // 0x80800348: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080034C:
    // 0x8080034C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800350: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800354: jr          $ra
    // 0x80800358: nop

    return;
    // 0x80800358: nop

;}
RECOMP_FUNC void func_808091E4_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808091E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808091E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808091EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808091F0: jal         0x80100094
    // 0x808091F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808091F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808091F8: jal         0x800D9078
    // 0x808091FC: addiu       $a0, $v0, 0xE0
    ctx->r4 = ADD32(ctx->r2, 0XE0);
    func_800D9078(rdram, ctx);
        goto after_1;
    // 0x808091FC: addiu       $a0, $v0, 0xE0
    ctx->r4 = ADD32(ctx->r2, 0XE0);
    after_1:
    // 0x80809200: beql        $v0, $zero, L_80809224
    if (ctx->r2 == 0) {
        // 0x80809204: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80809224;
    }
    goto skip_0;
    // 0x80809204: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80809208: jal         0x80809234
    // 0x8080920C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80809234_chdiggerboss(rdram, ctx);
        goto after_2;
    // 0x8080920C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80809210: bnel        $v0, $zero, L_80809224
    if (ctx->r2 != 0) {
        // 0x80809214: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80809224;
    }
    goto skip_1;
    // 0x80809214: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80809218: b           L_80809224
    // 0x8080921C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80809224;
    // 0x8080921C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80809220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80809224:
    // 0x80809224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80809228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080922C: jr          $ra
    // 0x80809230: nop

    return;
    // 0x80809230: nop

;}
RECOMP_FUNC void _chlifeforcespell_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086590: syscall     338
    recomp_syscall_handler(rdram, ctx, 0x80086590);
    return;
    // 0x80086594: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chcrate_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1912, 0X458) << 16);
    // 0x80800010: jr          $ra
    // 0x80800014: addiu       $v0, $v0, 0x458
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1912, 0X458));
    return;
    // 0x80800014: addiu       $v0, $v0, 0x458
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1912, 0X458));
;}
RECOMP_FUNC void gspropctrl_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: lbu         $v0, 0xA($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA);
    return;
    // 0x80800004: lbu         $v0, 0xA($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA);
;}
RECOMP_FUNC void func_80800D88_chrainbow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D8C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800D90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D94: beq         $a1, $at, L_80800DC0
    if (ctx->r5 == ctx->r1) {
        // 0x80800D98: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800DC0;
    }
    // 0x80800D98: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800D9C: addiu       $at, $zero, 0x4B
    ctx->r1 = ADD32(0, 0X4B);
    // 0x80800DA0: beq         $a1, $at, L_80800E30
    if (ctx->r5 == ctx->r1) {
        // 0x80800DA4: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80800E30;
    }
    // 0x80800DA4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x80800DA8: beq         $a1, $at, L_80800E70
    if (ctx->r5 == ctx->r1) {
        // 0x80800DAC: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80800E70;
    }
    // 0x80800DAC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800DB0: beq         $a1, $at, L_80800E80
    if (ctx->r5 == ctx->r1) {
        // 0x80800DB4: addiu       $a0, $zero, 0x2B0
        ctx->r4 = ADD32(0, 0X2B0);
            goto L_80800E80;
    }
    // 0x80800DB4: addiu       $a0, $zero, 0x2B0
    ctx->r4 = ADD32(0, 0X2B0);
    // 0x80800DB8: b           L_80800EA4
    // 0x80800DBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EA4;
    // 0x80800DBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800DC0:
    // 0x80800DC0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80800DC4: jal         0x80085710
    // 0x80800DC8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _capod_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800DC8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800DCC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80800DD0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80800DD4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800DD8: bne         $a2, $at, L_80800E14
    if (ctx->r6 != ctx->r1) {
        // 0x80800DDC: addiu       $a0, $zero, 0x1E1
        ctx->r4 = ADD32(0, 0X1E1);
            goto L_80800E14;
    }
    // 0x80800DDC: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    // 0x80800DE0: jal         0x800DA298
    // 0x80800DE4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800DE4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800DE8: beq         $v0, $zero, L_80800E00
    if (ctx->r2 == 0) {
        // 0x80800DEC: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80800E00;
    }
    // 0x80800DEC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800DF0: jal         0x80800CD4
    // 0x80800DF4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800CD4_chrainbow(rdram, ctx);
        goto after_2;
    // 0x80800DF4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x80800DF8: b           L_80800EA4
    // 0x80800DFC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800EA4;
    // 0x80800DFC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800E00:
    // 0x80800E00: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800E04: jal         0x80800270
    // 0x80800E08: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80800270_chrainbow(rdram, ctx);
        goto after_3;
    // 0x80800E08: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80800E0C: b           L_80800EA4
    // 0x80800E10: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800EA4;
    // 0x80800E10: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800E14:
    // 0x80800E14: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800E18: bne         $a2, $at, L_80800E28
    if (ctx->r6 != ctx->r1) {
        // 0x80800E1C: nop
    
            goto L_80800E28;
    }
    // 0x80800E1C: nop

    // 0x80800E20: jal         0x80800CD4
    // 0x80800E24: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800CD4_chrainbow(rdram, ctx);
        goto after_4;
    // 0x80800E24: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
L_80800E28:
    // 0x80800E28: b           L_80800EA4
    // 0x80800E2C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800EA4;
    // 0x80800E2C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800E30:
    // 0x80800E30: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800E34: bne         $a2, $at, L_80800E68
    if (ctx->r6 != ctx->r1) {
        // 0x80800E38: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800E68;
    }
    // 0x80800E38: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800E3C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800E40: jal         0x80800270
    // 0x80800E44: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80800270_chrainbow(rdram, ctx);
        goto after_5;
    // 0x80800E44: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_5:
    // 0x80800E48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E4C: jal         0x8008A4B0
    // 0x80800E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x80800E50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800E54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E58: jal         0x80103110
    // 0x80800E5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_7;
    // 0x80800E5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80800E60: b           L_80800EA4
    // 0x80800E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800EA4;
    // 0x80800E64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E68:
    // 0x80800E68: b           L_80800EA4
    // 0x80800E6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800EA4;
    // 0x80800E6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800E70:
    // 0x80800E70: jal         0x80800CD4
    // 0x80800E74: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800CD4_chrainbow(rdram, ctx);
        goto after_8;
    // 0x80800E74: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_8:
    // 0x80800E78: b           L_80800EA4
    // 0x80800E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800EA4;
    // 0x80800E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800E80:
    // 0x80800E80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800E84: jal         0x80089C30
    // 0x80800E88: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    _subaddiefind_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80800E88: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_9:
    // 0x80800E8C: beq         $v0, $zero, L_80800E9C
    if (ctx->r2 == 0) {
        // 0x80800E90: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80800E9C;
    }
    // 0x80800E90: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80800E94: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800E98: sw          $t6, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r14;
L_80800E9C:
    // 0x80800E9C: b           L_80800EA4
    // 0x80800EA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800EA4;
    // 0x80800EA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800EA4:
    // 0x80800EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800EAC: jr          $ra
    // 0x80800EB0: nop

    return;
    // 0x80800EB0: nop

;}
RECOMP_FUNC void func_80800638_chbanjoctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080063C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800640: bne         $a1, $at, L_80800670
    if (ctx->r5 != ctx->r1) {
        // 0x80800644: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80800670;
    }
    // 0x80800644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080064C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800650: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x80800654: jalr        $t9
    // 0x80800658: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80800658: nop

    after_0:
    // 0x8080065C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800660: beq         $v0, $zero, L_80800670
    if (ctx->r2 == 0) {
        // 0x80800664: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80800670;
    }
    // 0x80800664: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80800668: lwc1        $f4, 0x2C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8080066C: swc1        $f4, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f4.u32l;
L_80800670:
    // 0x80800670: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x80800674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080067C: jr          $ra
    // 0x80800680: nop

    return;
    // 0x80800680: nop

;}
RECOMP_FUNC void _Litob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035F40: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80035F44: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80035F48: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80035F4C: addiu       $v1, $zero, 0x58
    ctx->r3 = ADD32(0, 0X58);
    // 0x80035F50: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80035F54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80035F58: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80035F5C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80035F60: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80035F64: bne         $v1, $v0, L_80035F78
    if (ctx->r3 != ctx->r2) {
        // 0x80035F68: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_80035F78;
    }
    // 0x80035F68: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80035F6C: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80035F70: b           L_80035F80
    // 0x80035F74: addiu       $s3, $s3, 0x1594
    ctx->r19 = ADD32(ctx->r19, 0X1594);
        goto L_80035F80;
    // 0x80035F74: addiu       $s3, $s3, 0x1594
    ctx->r19 = ADD32(ctx->r19, 0X1594);
L_80035F78:
    // 0x80035F78: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80035F7C: addiu       $s3, $s3, 0x1580
    ctx->r19 = ADD32(ctx->r19, 0X1580);
L_80035F80:
    // 0x80035F80: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x80035F84: bne         $v0, $at, L_80035F94
    if (ctx->r2 != ctx->r1) {
        // 0x80035F88: addiu       $s0, $zero, 0x18
        ctx->r16 = ADD32(0, 0X18);
            goto L_80035F94;
    }
    // 0x80035F88: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x80035F8C: b           L_80035FB4
    // 0x80035F90: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_80035FB4;
    // 0x80035F90: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_80035F94:
    // 0x80035F94: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80035F98: beq         $v0, $at, L_80035FB0
    if (ctx->r2 == ctx->r1) {
        // 0x80035F9C: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_80035FB0;
    }
    // 0x80035F9C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80035FA0: beq         $v1, $v0, L_80035FB0
    if (ctx->r3 == ctx->r2) {
        // 0x80035FA4: nop
    
            goto L_80035FB0;
    }
    // 0x80035FA4: nop

    // 0x80035FA8: b           L_80035FB0
    // 0x80035FAC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
        goto L_80035FB0;
    // 0x80035FAC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_80035FB0:
    // 0x80035FB0: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80035FB4:
    // 0x80035FB4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80035FB8: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80035FBC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80035FC0: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80035FC4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80035FC8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80035FCC: beq         $v0, $at, L_80035FE0
    if (ctx->r2 == ctx->r1) {
        // 0x80035FD0: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_80035FE0;
    }
    // 0x80035FD0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80035FD4: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x80035FD8: bnel        $v0, $at, L_8003601C
    if (ctx->r2 != ctx->r1) {
        // 0x80035FDC: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_8003601C;
    }
    goto skip_0;
    // 0x80035FDC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_0:
L_80035FE0:
    // 0x80035FE0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80035FE4: bgtzl       $t4, L_8003601C
    if (SIGNED(ctx->r12) > 0) {
        // 0x80035FE8: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_8003601C;
    }
    goto skip_1;
    // 0x80035FE8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x80035FEC: bltz        $t4, L_80035FFC
    if (SIGNED(ctx->r12) < 0) {
        // 0x80035FF0: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_80035FFC;
    }
    // 0x80035FF0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80035FF4: b           L_8003601C
    // 0x80035FF8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
        goto L_8003601C;
    // 0x80035FF8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_80035FFC:
    // 0x80035FFC: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80036000: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x80036004: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80036008: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x8003600C: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x80036010: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80036014: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80036018: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_8003601C:
    // 0x8003601C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80036020: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x80036024: bne         $t2, $zero, L_80036040
    if (ctx->r10 != 0) {
        // 0x80036028: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80036040;
    }
    // 0x80036028: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8003602C: bnel        $t3, $zero, L_80036044
    if (ctx->r11 != 0) {
        // 0x80036030: addiu       $s0, $zero, 0x17
        ctx->r16 = ADD32(0, 0X17);
            goto L_80036044;
    }
    goto skip_2;
    // 0x80036030: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
    skip_2:
    // 0x80036034: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x80036038: beql        $t4, $zero, L_8003607C
    if (ctx->r12 == 0) {
        // 0x8003603C: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_8003607C;
    }
    goto skip_3;
    // 0x8003603C: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    skip_3:
L_80036040:
    // 0x80036040: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
L_80036044:
    // 0x80036044: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80036048: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8003604C: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80036050: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80036054: jal         0x8002F46C
    // 0x80036058: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x80036058: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_0:
    // 0x8003605C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80036060: addu        $t6, $v1, $s3
    ctx->r14 = ADD32(ctx->r3, ctx->r19);
    // 0x80036064: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80036068: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x8003606C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80036070: addu        $t8, $s2, $t0
    ctx->r24 = ADD32(ctx->r18, ctx->r8);
    // 0x80036074: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80036078: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_8003607C:
    // 0x8003607C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80036080: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80036084: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80036088: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x8003608C: jal         0x8002F4A8
    // 0x80036090: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80036090: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_1:
    // 0x80036094: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80036098: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x8003609C: bltz        $v0, L_8003614C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800360A0: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8003614C;
    }
    // 0x800360A0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800360A4: bgtz        $v0, L_800360B4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800360A8: nop
    
            goto L_800360B4;
    }
    // 0x800360A8: nop

    // 0x800360AC: beql        $v1, $zero, L_80036150
    if (ctx->r3 == 0) {
        // 0x800360B0: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80036150;
    }
    goto skip_4;
    // 0x800360B0: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_4:
L_800360B4:
    // 0x800360B4: blez        $s0, L_8003614C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800360B8: sra         $t4, $t1, 31
        ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
            goto L_8003614C;
    }
    // 0x800360B8: sra         $t4, $t1, 31
    ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800360BC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800360C0: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x800360C4: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800360C8: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800360CC: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800360D0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800360D4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_800360D8:
    // 0x800360D8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800360DC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800360E0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800360E4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800360E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800360EC: jal         0x80037774
    // 0x800360F0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x800360F0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x800360F4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800360F8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800360FC: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x80036100: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80036104: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x80036108: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8003610C: addu        $t7, $s2, $a0
    ctx->r15 = ADD32(ctx->r18, ctx->r4);
    // 0x80036110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80036114: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x80036118: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8003611C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80036120: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80036124: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80036128: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8003612C: bltz        $t8, L_8003614C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80036130: sw          $t9, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r25;
            goto L_8003614C;
    }
    // 0x80036130: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80036134: bgtz        $t8, L_80036144
    if (SIGNED(ctx->r24) > 0) {
        // 0x80036138: nop
    
            goto L_80036144;
    }
    // 0x80036138: nop

    // 0x8003613C: beql        $t9, $zero, L_80036150
    if (ctx->r25 == 0) {
        // 0x80036140: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80036150;
    }
    goto skip_5;
    // 0x80036140: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_5:
L_80036144:
    // 0x80036144: bgtzl       $s0, L_800360D8
    if (SIGNED(ctx->r16) > 0) {
        // 0x80036148: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_800360D8;
    }
    goto skip_6;
    // 0x80036148: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_6:
L_8003614C:
    // 0x8003614C: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
L_80036150:
    // 0x80036150: subu        $a2, $t4, $s0
    ctx->r6 = SUB32(ctx->r12, ctx->r16);
    // 0x80036154: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x80036158: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x8003615C: jal         0x80032AD8
    // 0x80036160: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x80036160: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    after_3:
    // 0x80036164: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x80036168: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x8003616C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80036170: beq         $at, $zero, L_8003617C
    if (ctx->r1 == 0) {
        // 0x80036174: subu        $t5, $a0, $a1
        ctx->r13 = SUB32(ctx->r4, ctx->r5);
            goto L_8003617C;
    }
    // 0x80036174: subu        $t5, $a0, $a1
    ctx->r13 = SUB32(ctx->r4, ctx->r5);
    // 0x80036178: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
L_8003617C:
    // 0x8003617C: bgezl       $a0, L_800361C0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80036180: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800361C0;
    }
    goto skip_7;
    // 0x80036180: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x80036184: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x80036188: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8003618C: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x80036190: bnel        $t7, $at, L_800361C0
    if (ctx->r15 != ctx->r1) {
        // 0x80036194: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800361C0;
    }
    goto skip_8;
    // 0x80036194: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x80036198: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x8003619C: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x800361A0: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800361A4: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x800361A8: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x800361AC: subu        $s0, $t3, $a1
    ctx->r16 = SUB32(ctx->r11, ctx->r5);
    // 0x800361B0: blez        $s0, L_800361BC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800361B4: addu        $t4, $v0, $s0
        ctx->r12 = ADD32(ctx->r2, ctx->r16);
            goto L_800361BC;
    }
    // 0x800361B4: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x800361B8: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
L_800361BC:
    // 0x800361BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800361C0:
    // 0x800361C0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800361C4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800361C8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800361CC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800361D0: jr          $ra
    // 0x800361D4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800361D4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800D28A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D28A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D28A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D28A8: jal         0x800D21D0
    // 0x800D28AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D21D0(rdram, ctx);
        goto after_0;
    // 0x800D28AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800D28B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D28B4: jal         0x800D21F0
    // 0x800D28B8: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    func_800D21F0(rdram, ctx);
        goto after_1;
    // 0x800D28B8: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    after_1:
    // 0x800D28BC: bltz        $v0, L_800D28D4
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D28C0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D28D4;
    }
    // 0x800D28C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D28C4: jal         0x800FAA74
    // 0x800D28C8: nop

    func_800FAA74(rdram, ctx);
        goto after_2;
    // 0x800D28C8: nop

    after_2:
    // 0x800D28CC: b           L_800D28D8
    // 0x800D28D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D28D8;
    // 0x800D28D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D28D4:
    // 0x800D28D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D28D8:
    // 0x800D28D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D28DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D28E0: jr          $ra
    // 0x800D28E4: nop

    return;
    // 0x800D28E4: nop

;}
RECOMP_FUNC void _gcskyDll_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088060: syscall     667
    recomp_syscall_handler(rdram, ctx, 0x80088060);
    return;
    // 0x80088064: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsrest_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083990: syscall     84
    recomp_syscall_handler(rdram, ctx, 0x80083990);
    return;
    // 0x80083994: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void func_80803460_chweldarboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803460: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80803464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803468: jal         0x80100094
    // 0x8080346C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080346C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803470: lbu         $t6, 0x64($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X64);
    // 0x80803474: beql        $t6, $zero, L_80803494
    if (ctx->r14 == 0) {
        // 0x80803478: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80803494;
    }
    goto skip_0;
    // 0x80803478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080347C: lh          $a0, 0x78($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X78);
    // 0x80803480: jal         0x800F4B20
    // 0x80803484: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800F4B20(rdram, ctx);
        goto after_1;
    // 0x80803484: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80803488: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8080348C: sb          $zero, 0x64($v1)
    MEM_B(0X64, ctx->r3) = 0;
    // 0x80803490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80803494:
    // 0x80803494: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80803498: jr          $ra
    // 0x8080349C: nop

    return;
    // 0x8080349C: nop

;}
RECOMP_FUNC void func_800F6B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6B34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F6B38: jr          $ra
    // 0x800F6B3C: lbu         $v0, 0x54DA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X54DA);
    return;
    // 0x800F6B3C: lbu         $v0, 0x54DA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X54DA);
;}
RECOMP_FUNC void func_80800740_chpickups(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800748: jal         0x80800638
    // 0x8080074C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800638_chpickups(rdram, ctx);
        goto after_0;
    // 0x8080074C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800750: jal         0x80087450
    // 0x80800754: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _chdoubloon_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800754: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080075C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800760: jr          $ra
    // 0x80800764: nop

    return;
    // 0x80800764: nop

;}
RECOMP_FUNC void func_80800294_chballoonbomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800298: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080029C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002A0: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808002A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002A8: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x808002AC: bltzl       $t8, L_80800344
    if (SIGNED(ctx->r24) < 0) {
        // 0x808002B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800344;
    }
    goto skip_0;
    // 0x808002B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808002B4: jal         0x80800440
    // 0x808002B8: nop

    func_80800440_chballoonbomb(rdram, ctx);
        goto after_0;
    // 0x808002B8: nop

    after_0:
    // 0x808002BC: jal         0x80088B00
    // 0x808002C0: nop

    _fxgenlist_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808002C0: nop

    after_1:
    // 0x808002C4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808002C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808002CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002D0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808002D8: jal         0x800BBCB8
    // 0x808002DC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_800BBCB8(rdram, ctx);
        goto after_2;
    // 0x808002DC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x808002E0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(836, 0X4F8) << 16);
    // 0x808002E4: addiu       $a1, $a1, 0x4F8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(836, 0X4F8));
    // 0x808002E8: jal         0x800C4AF0
    // 0x808002EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800C4AF0(rdram, ctx);
        goto after_3;
    // 0x808002EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x808002F0: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x808002F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808002F8: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x808002FC: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x80800300: sltiu       $at, $t0, 0x4
    ctx->r1 = ctx->r8 < 0X4 ? 1 : 0;
    // 0x80800304: bne         $at, $zero, L_8080032C
    if (ctx->r1 != 0) {
        // 0x80800308: lui         $a2, 0x3F66
        ctx->r6 = S32(0X3F66 << 16);
            goto L_8080032C;
    }
    // 0x80800308: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x8080030C: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80800310: jal         0x800E1610
    // 0x80800314: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_800E1610(rdram, ctx);
        goto after_4;
    // 0x80800314: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80800318: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x8080031C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80800320: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800324: jal         0x80018820
    // 0x80800328: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80018820(rdram, ctx);
        goto after_5;
    // 0x80800328: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_5:
L_8080032C:
    // 0x8080032C: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800334: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x80800338: jal         0x800FFAB0
    // 0x8080033C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x8080033C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    after_6:
    // 0x80800340: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800344:
    // 0x80800344: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800348: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080034C: jr          $ra
    // 0x80800350: nop

    return;
    // 0x80800350: nop

;}
RECOMP_FUNC void func_80800AF0_bskaztorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800AFC: jal         0x80085358
    // 0x80800B00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _batranslate_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800B00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800B04: jal         0x80800508
    // 0x80800B08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800508_bskaztorpedo(rdram, ctx);
        goto after_1;
    // 0x80800B08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800B0C: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80800B10: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800B14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800B18: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800B1C: jal         0x80084EE0
    // 0x80800B20: swc1        $f0, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f0.u32l;
    _bamovethrust_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800B20: swc1        $f0, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f0.u32l;
    after_2:
    // 0x80800B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B2C: jr          $ra
    // 0x80800B30: nop

    return;
    // 0x80800B30: nop

;}
RECOMP_FUNC void func_80801790_chlakemonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801790: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801794: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801798: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080179C: jal         0x80101FDC
    // 0x808017A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80101FDC(rdram, ctx);
        goto after_0;
    // 0x808017A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808017A4: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x808017A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808017AC: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808017B0: beq         $t6, $at, L_808017D4
    if (ctx->r14 == ctx->r1) {
        // 0x808017B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808017D4;
    }
    // 0x808017B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808017B8: beq         $t6, $at, L_808017FC
    if (ctx->r14 == ctx->r1) {
        // 0x808017BC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808017FC;
    }
    // 0x808017BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808017C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808017C4: beql        $t6, $at, L_808017E8
    if (ctx->r14 == ctx->r1) {
        // 0x808017C8: lbu         $t7, 0x7E($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X7E);
            goto L_808017E8;
    }
    goto skip_0;
    // 0x808017C8: lbu         $t7, 0x7E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7E);
    skip_0:
    // 0x808017CC: b           L_80801824
    // 0x808017D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80801824;
    // 0x808017D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808017D4:
    // 0x808017D4: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x808017D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808017DC: b           L_80801820
    // 0x808017E0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
        goto L_80801820;
    // 0x808017E0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x808017E4: lbu         $t7, 0x7E($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X7E);
L_808017E8:
    // 0x808017E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808017EC: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x808017F0: sb          $t8, 0x7E($s0)
    MEM_B(0X7E, ctx->r16) = ctx->r24;
    // 0x808017F4: b           L_80801820
    // 0x808017F8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_80801820;
    // 0x808017F8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_808017FC:
    // 0x808017FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80801800: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801804: jal         0x80085708
    // 0x80801808: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80801808: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_1:
    // 0x8080180C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80801810: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80801814: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80801818: swc1        $f8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f8.u32l;
    // 0x8080181C: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
L_80801820:
    // 0x80801820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801824:
    // 0x80801824: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801828: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080182C: jr          $ra
    // 0x80801830: nop

    return;
    // 0x80801830: nop

;}
RECOMP_FUNC void func_808004D8_chjiggytemple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004D8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808004DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808004E4: jal         0x800D8FF8
    // 0x808004E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808004E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808004EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004F0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x808004F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808004F8: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x808004FC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(784, 0XA24) << 16);
    // 0x80800500: addiu       $a2, $a2, 0xA24
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(784, 0XA24));
    // 0x80800504: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80800508: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080050C: bc1fl       L_80800548
    if (!c1cs) {
        // 0x80800510: lw          $a0, 0x2C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X2C);
            goto L_80800548;
    }
    goto skip_0;
    // 0x80800510: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    skip_0:
    // 0x80800514: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800518: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080051C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800520: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80800524: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x80800528: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8080052C: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x80800530: nop

    // 0x80800534: bc1fl       L_80800548
    if (!c1cs) {
        // 0x80800538: lw          $a0, 0x2C($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X2C);
            goto L_80800548;
    }
    goto skip_1;
    // 0x80800538: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    skip_1:
    // 0x8080053C: swc1        $f12, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f12.u32l;
    // 0x80800540: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x80800544: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
L_80800548:
    // 0x80800548: bne         $a0, $zero, L_80800598
    if (ctx->r4 != 0) {
        // 0x8080054C: nop
    
            goto L_80800598;
    }
    // 0x8080054C: nop

    // 0x80800550: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800554: jal         0x800EE780
    // 0x80800558: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800EE780(rdram, ctx);
        goto after_1;
    // 0x80800558: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8080055C: jal         0x800B53A4
    // 0x80800560: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    func_800B53A4(rdram, ctx);
        goto after_2;
    // 0x80800560: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_2:
    // 0x80800564: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x80800568: jal         0x800B5534
    // 0x8080056C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800B5534(rdram, ctx);
        goto after_3;
    // 0x8080056C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800570: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(784, 0X9E0) << 16);
    // 0x80800574: addiu       $t7, $t7, 0x9E0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(784, 0X9E0));
    // 0x80800578: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x8080057C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800580: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800584: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800588: jal         0x800BABB8
    // 0x8080058C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x8080058C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80800590: sw          $v0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r2;
    // 0x80800594: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80800598:
    // 0x80800598: jal         0x800BA22C
    // 0x8080059C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BA22C(rdram, ctx);
        goto after_5;
    // 0x8080059C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x808005A0: jal         0x80088840
    // 0x808005A4: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_6;
    // 0x808005A4: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    after_6:
    // 0x808005A8: beql        $v0, $zero, L_808005E4
    if (ctx->r2 == 0) {
        // 0x808005AC: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_808005E4;
    }
    goto skip_2;
    // 0x808005AC: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_2:
    // 0x808005B0: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x808005B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808005B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x808005BC: bnel        $v1, $zero, L_808005D8
    if (ctx->r3 != 0) {
        // 0x808005C0: addiu       $a0, $v1, -0x1
        ctx->r4 = ADD32(ctx->r3, -0X1);
            goto L_808005D8;
    }
    goto skip_3;
    // 0x808005C0: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    skip_3:
    // 0x808005C4: jal         0x800E15CC
    // 0x808005C8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800E15CC(rdram, ctx);
        goto after_7;
    // 0x808005C8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x808005CC: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x808005D0: sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
    // 0x808005D4: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
L_808005D8:
    // 0x808005D8: jal         0x800E13F0
    // 0x808005DC: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    func_800E13F0(rdram, ctx);
        goto after_8;
    // 0x808005DC: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    after_8:
    // 0x808005E0: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_808005E4:
    // 0x808005E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005E8: srl         $t9, $v0, 10
    ctx->r25 = S32(U32(ctx->r2) >> 10);
    // 0x808005EC: beq         $t9, $at, L_80800604
    if (ctx->r25 == ctx->r1) {
        // 0x808005F0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800604;
    }
    // 0x808005F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808005F4: beq         $t9, $at, L_80800630
    if (ctx->r25 == ctx->r1) {
        // 0x808005F8: lui         $a1, 0x8080
        ctx->r5 = S32(RELOC_HI16(784, 0XA30) << 16);
            goto L_80800630;
    }
    // 0x808005F8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(784, 0XA30) << 16);
    // 0x808005FC: b           L_80800678
    // 0x80800600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800678;
    // 0x80800600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800604:
    // 0x80800604: jal         0x80088840
    // 0x80800608: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_9;
    // 0x80800608: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    after_9:
    // 0x8080060C: beq         $v0, $zero, L_80800674
    if (ctx->r2 == 0) {
        // 0x80800610: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80800674;
    }
    // 0x80800610: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800614: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x80800618: jal         0x80018820
    // 0x8080061C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_80018820(rdram, ctx);
        goto after_10;
    // 0x8080061C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_10:
    // 0x80800620: jal         0x8080047C
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080047C_chjiggytemple(rdram, ctx);
        goto after_11;
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800628: b           L_80800678
    // 0x8080062C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800678;
    // 0x8080062C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800630:
    // 0x80800630: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800634: addiu       $a1, $a1, 0xA30
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(784, 0XA30));
    // 0x80800638: jal         0x800F3780
    // 0x8080063C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800F3780(rdram, ctx);
        goto after_12;
    // 0x8080063C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
    // 0x80800640: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80800644: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80800648: beq         $t0, $zero, L_8080066C
    if (ctx->r8 == 0) {
        // 0x8080064C: nop
    
            goto L_8080066C;
    }
    // 0x8080064C: nop

    // 0x80800650: jal         0x80085710
    // 0x80800654: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_13;
    // 0x80800654: nop

    after_13:
    // 0x80800658: jal         0x8008A698
    // 0x8080065C: nop

    _sujiggy_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x8080065C: nop

    after_14:
    // 0x80800660: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80800664: jal         0x8008A710
    // 0x80800668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sujiggy_entrypoint_15(rdram, ctx);
        goto after_15;
    // 0x80800668: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
L_8080066C:
    // 0x8080066C: jal         0x8080047C
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080047C_chjiggytemple(rdram, ctx);
        goto after_16;
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_80800674:
    // 0x80800674: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800678:
    // 0x80800678: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080067C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80800680: jr          $ra
    // 0x80800684: nop

    return;
    // 0x80800684: nop

;}
RECOMP_FUNC void func_80803B84_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803B88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803B8C: jal         0x800AA120
    // 0x80803B90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800AA120(rdram, ctx);
        goto after_0;
    // 0x80803B90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803B94: lui         $v1, 0x8081
    ctx->r3 = S32(RELOC_HI16(804, 0X8370) << 16);
    // 0x80803B98: lui         $a0, 0x8081
    ctx->r4 = S32(RELOC_HI16(804, 0X83A0) << 16);
    // 0x80803B9C: addiu       $a0, $a0, -0x7C60
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(804, 0X83A0));
    // 0x80803BA0: addiu       $v1, $v1, -0x7C90
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(804, 0X8370));
    // 0x80803BA4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80803BA8:
    // 0x80803BA8: bnel        $v0, $t6, L_80803BC8
    if (ctx->r2 != ctx->r14) {
        // 0x80803BAC: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80803BC8;
    }
    goto skip_0;
    // 0x80803BAC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    skip_0:
    // 0x80803BB0: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x80803BB4: jalr        $t9
    // 0x80803BB8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80803BB8: nop

    after_1:
    // 0x80803BBC: b           L_80803BD0
    // 0x80803BC0: nop

        goto L_80803BD0;
    // 0x80803BC0: nop

    // 0x80803BC4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80803BC8:
    // 0x80803BC8: bnel        $v1, $a0, L_80803BA8
    if (ctx->r3 != ctx->r4) {
        // 0x80803BCC: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80803BA8;
    }
    goto skip_1;
    // 0x80803BCC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_1:
L_80803BD0:
    // 0x80803BD0: jal         0x80803B3C
    // 0x80803BD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80803B3C_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80803BD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80803BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803BE0: jr          $ra
    // 0x80803BE4: nop

    return;
    // 0x80803BE4: nop

;}
RECOMP_FUNC void func_8080183C_subaddierouteDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080183C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801840: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80801844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801848: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8080184C: addiu       $a1, $a2, 0x18
    ctx->r5 = ADD32(ctx->r6, 0X18);
    // 0x80801850: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80801854: jal         0x800EFBFC
    // 0x80801858: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFBFC(rdram, ctx);
        goto after_0;
    // 0x80801858: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8080185C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80801860: jal         0x800F13F0
    // 0x80801864: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F13F0(rdram, ctx);
        goto after_1;
    // 0x80801864: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_1:
    // 0x80801868: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8080186C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3230, 0X18D0) << 16);
    // 0x80801870: lwc1        $f6, 0x18D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3230, 0X18D0));
    // 0x80801874: lhu         $t6, 0x62($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X62);
    // 0x80801878: lwc1        $f4, 0x38($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X38);
    // 0x8080187C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80801880: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80801884: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801888: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8080188C: bgez        $t6, L_808018A0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80801890: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_808018A0;
    }
    // 0x80801890: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80801894: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80801898: nop

    // 0x8080189C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_808018A0:
    // 0x808018A0: mul.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x808018A4: jal         0x800F0E00
    // 0x808018A8: nop

    func_800F0E00(rdram, ctx);
        goto after_2;
    // 0x808018A8: nop

    after_2:
    // 0x808018AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018B4: jr          $ra
    // 0x808018B8: nop

    return;
    // 0x808018B8: nop

    // 0x808018BC: nop

;}
RECOMP_FUNC void func_8080008C_bsride(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080008C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800090: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800094: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800098: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080009C: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    // 0x808000A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808000A4: jal         0x800947EC
    // 0x808000A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800947EC(rdram, ctx);
        goto after_0;
    // 0x808000A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x800A34E4
    // 0x808000B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A34E4(rdram, ctx);
        goto after_1;
    // 0x808000B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: jal         0x800961AC
    // 0x808000C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_2;
    // 0x808000C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x808000C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000C8: jal         0x8009C4CC
    // 0x808000CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_3;
    // 0x808000CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: jal         0x8009BF5C
    // 0x808000D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_4;
    // 0x808000D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x808000DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_80800418_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800418: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080041C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800420: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800424: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800428: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080042C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800430: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800434: beq         $a1, $t6, L_808006AC
    if (ctx->r5 == ctx->r14) {
        // 0x80800438: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808006AC;
    }
    // 0x80800438: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080043C: beq         $t6, $at, L_80800458
    if (ctx->r14 == ctx->r1) {
        // 0x80800440: addiu       $a0, $zero, 0x3EE
        ctx->r4 = ADD32(0, 0X3EE);
            goto L_80800458;
    }
    // 0x80800440: addiu       $a0, $zero, 0x3EE
    ctx->r4 = ADD32(0, 0X3EE);
    // 0x80800444: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800448: beq         $t6, $at, L_80800490
    if (ctx->r14 == ctx->r1) {
        // 0x8080044C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800490;
    }
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800450: b           L_808004B8
    // 0x80800454: lbu         $t0, 0x72($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X72);
        goto L_808004B8;
    // 0x80800454: lbu         $t0, 0x72($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X72);
L_80800458:
    // 0x80800458: jal         0x800DA298
    // 0x8080045C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080045C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800460: bne         $v0, $zero, L_80800470
    if (ctx->r2 != 0) {
        // 0x80800464: nop
    
            goto L_80800470;
    }
    // 0x80800464: nop

    // 0x80800468: jal         0x80090708
    // 0x8080046C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_1;
    // 0x8080046C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
L_80800470:
    // 0x80800470: jal         0x808000B4
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B4_chwarppad(rdram, ctx);
        goto after_2;
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800478: blez        $v0, L_80800488
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8080047C: nop
    
            goto L_80800488;
    }
    // 0x8080047C: nop

    // 0x80800480: jal         0x800DA544
    // 0x80800484: addiu       $a0, $zero, 0x3EE
    ctx->r4 = ADD32(0, 0X3EE);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800484: addiu       $a0, $zero, 0x3EE
    ctx->r4 = ADD32(0, 0X3EE);
    after_3:
L_80800488:
    // 0x80800488: b           L_808004B4
    // 0x8080048C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
        goto L_808004B4;
    // 0x8080048C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
L_80800490:
    // 0x80800490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800494: jal         0x80087CC8
    // 0x80800498: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800498: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_4:
    // 0x8080049C: jal         0x80090708
    // 0x808004A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_5;
    // 0x808004A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A8: jal         0x8010A828
    // 0x808004AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A828(rdram, ctx);
        goto after_6;
    // 0x808004AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_6:
    // 0x808004B0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
L_808004B4:
    // 0x808004B4: lbu         $t0, 0x72($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X72);
L_808004B8:
    // 0x808004B8: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x808004BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004C0: andi        $t1, $t0, 0xFF03
    ctx->r9 = ctx->r8 & 0XFF03;
    // 0x808004C4: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x808004C8: beq         $a2, $at, L_808004EC
    if (ctx->r6 == ctx->r1) {
        // 0x808004CC: sb          $t2, 0x72($s0)
        MEM_B(0X72, ctx->r16) = ctx->r10;
            goto L_808004EC;
    }
    // 0x808004CC: sb          $t2, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r10;
    // 0x808004D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808004D4: beq         $a2, $at, L_8080051C
    if (ctx->r6 == ctx->r1) {
        // 0x808004D8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8080051C;
    }
    // 0x808004D8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808004DC: beq         $a2, $at, L_80800638
    if (ctx->r6 == ctx->r1) {
        // 0x808004E0: nop
    
            goto L_80800638;
    }
    // 0x808004E0: nop

    // 0x808004E4: b           L_808006B0
    // 0x808004E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006B0;
    // 0x808004E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004EC:
    // 0x808004EC: jal         0x800DA298
    // 0x808004F0: addiu       $a0, $zero, 0x3EE
    ctx->r4 = ADD32(0, 0X3EE);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x808004F0: addiu       $a0, $zero, 0x3EE
    ctx->r4 = ADD32(0, 0X3EE);
    after_7:
    // 0x808004F4: bne         $v0, $zero, L_8080050C
    if (ctx->r2 != 0) {
        // 0x808004F8: nop
    
            goto L_8080050C;
    }
    // 0x808004F8: nop

    // 0x808004FC: jal         0x80090708
    // 0x80800500: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090708(rdram, ctx);
        goto after_8;
    // 0x80800500: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80800504: b           L_808006B0
    // 0x80800508: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006B0;
    // 0x80800508: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080050C:
    // 0x8080050C: jal         0x808003B8
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003B8_chwarppad(rdram, ctx);
        goto after_9;
    // 0x80800510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800514: b           L_808006B0
    // 0x80800518: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006B0;
    // 0x80800518: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080051C:
    // 0x8080051C: jal         0x808000B4
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000B4_chwarppad(rdram, ctx);
        goto after_10;
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800524: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800528: lw          $t3, 0x2C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X2C);
    // 0x8080052C: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800530: addiu       $a2, $a2, 0x7DB0
    ctx->r6 = ADD32(ctx->r6, 0X7DB0);
    // 0x80800534: addiu       $t4, $t3, 0x185A
    ctx->r12 = ADD32(ctx->r11, 0X185A);
    // 0x80800538: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080053C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800544: jal         0x80087CB8
    // 0x80800548: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _gcnewoption_entrypoint_4(rdram, ctx);
        goto after_11;
    // 0x80800548: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x8080054C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800550: jal         0x80100094
    // 0x80800554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_12;
    // 0x80800554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80800558: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8080055C: jal         0x800C78CC
    // 0x80800560: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800C78CC(rdram, ctx);
        goto after_13;
    // 0x80800560: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x80800564: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800568: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8080056C: bnel        $at, $zero, L_80800580
    if (ctx->r1 != 0) {
        // 0x80800570: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80800580;
    }
    goto skip_0;
    // 0x80800570: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    skip_0:
    // 0x80800574: b           L_80800580
    // 0x80800578: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_80800580;
    // 0x80800578: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080057C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80800580:
    // 0x80800580: jal         0x80087CD8
    // 0x80800584: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_14;
    // 0x80800584: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_14:
    // 0x80800588: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8080058C: jal         0x80087CE0
    // 0x80800590: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_15;
    // 0x80800590: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_15:
    // 0x80800594: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800598: jal         0x80087CE8
    // 0x8080059C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_16;
    // 0x8080059C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x808005A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A4: jal         0x80800124
    // 0x808005A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80800124_chwarppad(rdram, ctx);
        goto after_17;
    // 0x808005A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_17:
    // 0x808005AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808005B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808005B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808005BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808005C0: jal         0x80087D08
    // 0x808005C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    _gcnewoption_entrypoint_14(rdram, ctx);
        goto after_18;
    // 0x808005C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_18:
    // 0x808005C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(780, 0X1070) << 16);
    // 0x808005CC: lwc1        $f6, 0x1070($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(780, 0X1070));
    // 0x808005D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808005D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808005D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808005DC: addiu       $a1, $zero, 0x41
    ctx->r5 = ADD32(0, 0X41);
    // 0x808005E0: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x808005E4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x808005E8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x808005EC: jal         0x80087DD8
    // 0x808005F0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    _gcnewoption_entrypoint_40(rdram, ctx);
        goto after_19;
    // 0x808005F0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_19:
    // 0x808005F4: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x808005F8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x808005FC: jal         0x80087DE8
    // 0x80800600: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _gcnewoption_entrypoint_42(rdram, ctx);
        goto after_20;
    // 0x80800600: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_20:
    // 0x80800604: jal         0x80087CF0
    // 0x80800608: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_21;
    // 0x80800608: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_21:
    // 0x8080060C: jal         0x80090708
    // 0x80800610: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_22;
    // 0x80800610: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_22:
    // 0x80800614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800618: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080061C: jal         0x80800F34
    // 0x80800620: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800F34_chwarppad(rdram, ctx);
        goto after_23;
    // 0x80800620: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_23:
    // 0x80800624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800628: jal         0x8010A828
    // 0x8080062C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8010A828(rdram, ctx);
        goto after_24;
    // 0x8080062C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_24:
    // 0x80800630: b           L_808006B0
    // 0x80800634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808006B0;
    // 0x80800634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800638:
    // 0x80800638: jal         0x800DA544
    // 0x8080063C: addiu       $a0, $zero, 0x9FE
    ctx->r4 = ADD32(0, 0X9FE);
    func_800DA544(rdram, ctx);
        goto after_25;
    // 0x8080063C: addiu       $a0, $zero, 0x9FE
    ctx->r4 = ADD32(0, 0X9FE);
    after_25:
    // 0x80800640: lw          $t5, 0x30($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X30);
    // 0x80800644: lw          $t7, 0x28($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X28);
    // 0x80800648: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(780, 0X10B0) << 16);
    // 0x8080064C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80800650: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800654: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80800658: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8080065C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800660: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800664: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x80800668: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x8080066C: jal         0x80800E10
    // 0x80800670: lw          $a0, 0x10B0($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(780, 0X10B0));
    func_80800E10_chwarppad(rdram, ctx);
        goto after_26;
    // 0x80800670: lw          $a0, 0x10B0($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(780, 0X10B0));
    after_26:
    // 0x80800674: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x80800678: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x8080067C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(780, 0X10B4) << 16);
    // 0x80800680: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80800684: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80800688: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x8080068C: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80800690: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80800694: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80800698: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8080069C: addu        $a1, $a1, $t4
    ctx->r5 = ADD32(ctx->r5, ctx->r12);
    // 0x808006A0: lbu         $a1, 0x10B4($a1)
    ctx->r5 = MEM_BU(ctx->r5, (int16_t)RELOC_LO16(780, 0X10B4));
    // 0x808006A4: jal         0x80087A58
    // 0x808006A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _gcgoto_entrypoint_1(rdram, ctx);
        goto after_27;
    // 0x808006A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_27:
L_808006AC:
    // 0x808006AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808006B0:
    // 0x808006B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808006B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808006B8: jr          $ra
    // 0x808006BC: nop

    return;
    // 0x808006BC: nop

;}
RECOMP_FUNC void _chquiz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800877E0: syscall     629
    recomp_syscall_handler(rdram, ctx, 0x800877E0);
    return;
    // 0x800877E4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80806588_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806588: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8080658C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80806590: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80806594: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80806598: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8080659C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808065A0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808065A4: jal         0x80802458
    // 0x808065A8: lw          $s0, 0x188($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X188);
    func_80802458_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x808065A8: lw          $s0, 0x188($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X188);
    after_0:
    // 0x808065AC: jal         0x800D9004
    // 0x808065B0: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    func_800D9004(rdram, ctx);
        goto after_1;
    // 0x808065B0: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    after_1:
    // 0x808065B4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x808065B8: lw          $v0, 0xC8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC8);
    // 0x808065BC: addiu       $s1, $s0, 0x1A0
    ctx->r17 = ADD32(ctx->r16, 0X1A0);
    // 0x808065C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808065C4: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x808065C8: addiu       $t6, $v0, 0x28
    ctx->r14 = ADD32(ctx->r2, 0X28);
    // 0x808065CC: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x808065D0: sw          $a1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r5;
    // 0x808065D4: jal         0x800EF04C
    // 0x808065D8: addiu       $s2, $v0, 0x10
    ctx->r18 = ADD32(ctx->r2, 0X10);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x808065D8: addiu       $s2, $v0, 0x10
    ctx->r18 = ADD32(ctx->r2, 0X10);
    after_2:
    // 0x808065DC: addiu       $a1, $s0, 0x1AC
    ctx->r5 = ADD32(ctx->r16, 0X1AC);
    // 0x808065E0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808065E4: jal         0x800EF3DC
    // 0x808065E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EF3DC(rdram, ctx);
        goto after_3;
    // 0x808065E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x808065EC: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x808065F0: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x808065F4: addiu       $s1, $s0, 0x1DC
    ctx->r17 = ADD32(ctx->r16, 0X1DC);
    // 0x808065F8: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x808065FC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80806600: addiu       $a1, $s1, 0x8
    ctx->r5 = ADD32(ctx->r17, 0X8);
    // 0x80806604: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80806608: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x8080660C: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80806610: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80806614: lwc1        $f18, 0x48($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X48);
    // 0x80806618: lw          $a3, 0x50($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X50);
    // 0x8080661C: lw          $a2, 0x4C($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4C);
    // 0x80806620: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80806624: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80806628: jal         0x800FF060
    // 0x8080662C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_800FF060(rdram, ctx);
        goto after_4;
    // 0x8080662C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x80806630: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80806634: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80806638: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8080663C: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x80806640: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80806644: jal         0x8009C984
    // 0x80806648: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    yaw_get(rdram, ctx);
        goto after_5;
    // 0x80806648: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8080664C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA554) << 16);
    // 0x80806650: lwc1        $f16, -0x5AAC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA554));
    // 0x80806654: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80806658: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8080665C: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA558) << 16);
    // 0x80806660: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80806664: lwc1        $f8, -0x5AA8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA558));
    // 0x80806668: lwc1        $f6, 0x24C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24C);
    // 0x8080666C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80806670: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80806674: nop

    // 0x80806678: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8080667C: jal         0x800137AC
    // 0x80806680: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    func_800137AC(rdram, ctx);
        goto after_6;
    // 0x80806680: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x80806684: jal         0x800137C4
    // 0x80806688: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    func_800137C4(rdram, ctx);
        goto after_7;
    // 0x80806688: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8080668C: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80806690: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80806694: lwc1        $f18, 0x1A0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1A0);
    // 0x80806698: lwc1        $f16, 0x1A8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1A8);
    // 0x8080669C: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x808066A0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x808066A4: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x808066A8: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x808066AC: add.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x808066B0: swc1        $f4, 0x1AC($s0)
    MEM_W(0X1AC, ctx->r16) = ctx->f4.u32l;
    // 0x808066B4: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x808066B8: swc1        $f18, 0x1B4($s0)
    MEM_W(0X1B4, ctx->r16) = ctx->f18.u32l;
    // 0x808066BC: swc1        $f10, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->f10.u32l;
    // 0x808066C0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x808066C4: jal         0x800EFB24
    // 0x808066C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x808066C8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_8:
    // 0x808066CC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808066D0: jal         0x800EE7F8
    // 0x808066D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x808066D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_9:
    // 0x808066D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808066DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808066E0: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808066E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808066E8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x808066EC: div.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x808066F0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x808066F4: jal         0x800EFA20
    // 0x808066F8: nop

    func_800EFA20(rdram, ctx);
        goto after_10;
    // 0x808066F8: nop

    after_10:
    // 0x808066FC: jal         0x800F2100
    // 0x80806700: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    mlAbsF(rdram, ctx);
        goto after_11;
    // 0x80806700: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    after_11:
    // 0x80806704: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80806708: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8080670C: nop

    // 0x80806710: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80806714: nop

    // 0x80806718: bc1fl       L_80806744
    if (!c1cs) {
        // 0x8080671C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80806744;
    }
    goto skip_0;
    // 0x8080671C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x80806720: jal         0x800EEFFC
    // 0x80806724: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800EEFFC(rdram, ctx);
        goto after_12;
    // 0x80806724: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x80806728: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8080672C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80806730: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80806734: jal         0x80013B70
    // 0x80806738: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    func_80013B70(rdram, ctx);
        goto after_13;
    // 0x80806738: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    after_13:
    // 0x8080673C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80806740: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80806744:
    // 0x80806744: jal         0x8009B9B0
    // 0x80806748: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_14;
    // 0x80806748: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_14:
    // 0x8080674C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80806750: jal         0x8009B9C0
    // 0x80806754: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    baphysics_set_target_yaw(rdram, ctx);
        goto after_15;
    // 0x80806754: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    after_15:
    // 0x80806758: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8080675C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80806760: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80806764: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80806768: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8080676C: jr          $ra
    // 0x80806770: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80806770: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void gsmaker_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x80800010: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: bne         $t6, $at, L_8080003C
    if (ctx->r14 != ctx->r1) {
        // 0x8080001C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8080003C;
    }
    // 0x8080001C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800020: jal         0x800D721C
    // 0x80800024: lh          $a0, 0x20($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X20);
    func_800D721C(rdram, ctx);
        goto after_0;
    // 0x80800024: lh          $a0, 0x20($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X20);
    after_0:
    // 0x80800028: lh          $a0, 0x20($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X20);
    // 0x8080002C: jal         0x800D70F8
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D70F8(rdram, ctx);
        goto after_1;
    // 0x80800030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800034: jal         0x800D6CEC
    // 0x80800038: lh          $a0, 0x20($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X20);
    func_800D6CEC(rdram, ctx);
        goto after_2;
    // 0x80800038: lh          $a0, 0x20($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X20);
    after_2:
L_8080003C:
    // 0x8080003C: jal         0x8001B084
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    heap_free(rdram, ctx);
        goto after_3;
    // 0x80800040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800048: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080004C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800050: jr          $ra
    // 0x80800054: nop

    return;
    // 0x80800054: nop

;}
RECOMP_FUNC void func_800A5524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A552C: jal         0x8008FFE8
    // 0x800A5530: nop

    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x800A5530: nop

    after_0:
    // 0x800A5534: jal         0x80089220
    // 0x800A5538: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncfixposrot_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x800A5538: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800A553C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5544: jr          $ra
    // 0x800A5548: nop

    return;
    // 0x800A5548: nop

    // 0x800A554C: nop

;}
RECOMP_FUNC void bsrest_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800844: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080084C: jal         0x808007E8
    // 0x80800850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bsrest_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x80800850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080085C: jr          $ra
    // 0x80800860: nop

    return;
    // 0x80800860: nop

;}
RECOMP_FUNC void func_80800ED0_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800ED8: jal         0x8009EA64
    // 0x80800EDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009EA64(rdram, ctx);
        goto after_0;
    // 0x80800EDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800EE0: addiu       $at, $zero, 0x171
    ctx->r1 = ADD32(0, 0X171);
    // 0x80800EE4: bne         $v0, $at, L_80800F00
    if (ctx->r2 != ctx->r1) {
        // 0x80800EE8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800F00;
    }
    // 0x80800EE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800EEC: jal         0x800907C0
    // 0x80800EF0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800907C0(rdram, ctx);
        goto after_1;
    // 0x80800EF0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_1:
    // 0x80800EF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800EF8: jal         0x800906DC
    // 0x80800EFC: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    func_800906DC(rdram, ctx);
        goto after_2;
    // 0x80800EFC: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    after_2:
L_80800F00:
    // 0x80800F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F08: jr          $ra
    // 0x80800F0C: nop

    return;
    // 0x80800F0C: nop

;}
RECOMP_FUNC void _subaddiefade_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089CB0: syscall     808
    recomp_syscall_handler(rdram, ctx, 0x80089CB0);
    return;
    // 0x80089CB4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _subaddiepalette_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A078: syscall     825
    recomp_syscall_handler(rdram, ctx, 0x8008A078);
    return;
    // 0x8008A07C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_800B27D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B27D8: jr          $ra
    // 0x800B27DC: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    return;
    // 0x800B27DC: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
;}
RECOMP_FUNC void func_80800140_chmumbopad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800144: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800148: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080014C: jal         0x800EA05C
    // 0x80800150: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800150: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800154: slti        $at, $v0, 0x137
    ctx->r1 = SIGNED(ctx->r2) < 0X137 ? 1 : 0;
    // 0x80800158: bne         $at, $zero, L_8080017C
    if (ctx->r1 != 0) {
        // 0x8080015C: addiu       $t7, $v0, -0xB8
        ctx->r15 = ADD32(ctx->r2, -0XB8);
            goto L_8080017C;
    }
    // 0x8080015C: addiu       $t7, $v0, -0xB8
    ctx->r15 = ADD32(ctx->r2, -0XB8);
    // 0x80800160: addiu       $at, $zero, 0x155
    ctx->r1 = ADD32(0, 0X155);
    // 0x80800164: beq         $v0, $at, L_80800350
    if (ctx->r2 == ctx->r1) {
        // 0x80800168: addiu       $at, $zero, 0x1A7
        ctx->r1 = ADD32(0, 0X1A7);
            goto L_80800350;
    }
    // 0x80800168: addiu       $at, $zero, 0x1A7
    ctx->r1 = ADD32(0, 0X1A7);
    // 0x8080016C: beql        $v0, $at, L_80800254
    if (ctx->r2 == ctx->r1) {
        // 0x80800170: lhu         $t7, 0x6E($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X6E);
            goto L_80800254;
    }
    goto skip_0;
    // 0x80800170: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    skip_0:
    // 0x80800174: b           L_80800364
    // 0x80800178: lw          $t4, 0x6C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X6C);
        goto L_80800364;
    // 0x80800178: lw          $t4, 0x6C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X6C);
L_8080017C:
    // 0x8080017C: slti        $at, $v0, 0xE7
    ctx->r1 = SIGNED(ctx->r2) < 0XE7 ? 1 : 0;
    // 0x80800180: bne         $at, $zero, L_808001A8
    if (ctx->r1 != 0) {
        // 0x80800184: addiu       $t6, $v0, -0x107
        ctx->r14 = ADD32(ctx->r2, -0X107);
            goto L_808001A8;
    }
    // 0x80800184: addiu       $t6, $v0, -0x107
    ctx->r14 = ADD32(ctx->r2, -0X107);
    // 0x80800188: sltiu       $at, $t6, 0x30
    ctx->r1 = ctx->r14 < 0X30 ? 1 : 0;
    // 0x8080018C: beq         $at, $zero, L_80800360
    if (ctx->r1 == 0) {
        // 0x80800190: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800360;
    }
    // 0x80800190: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800194: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1720, 0XE50) << 16);
    // 0x80800198: addu        $at, $at, $t6
    gpr jr_addend_808001A0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080019C: lw          $t6, 0xE50($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1720, 0XE50));
    // 0x808001A0: jr          $t6
    // 0x808001A4: nop

    switch (jr_addend_808001A0 >> 2) {
        case 0: goto L_808002B4; break;
        case 1: goto L_80800360; break;
        case 2: goto L_80800360; break;
        case 3: goto L_80800360; break;
        case 4: goto L_808002C8; break;
        case 5: goto L_80800360; break;
        case 6: goto L_80800360; break;
        case 7: goto L_80800360; break;
        case 8: goto L_80800360; break;
        case 9: goto L_80800360; break;
        case 10: goto L_80800360; break;
        case 11: goto L_80800278; break;
        case 12: goto L_80800360; break;
        case 13: goto L_80800360; break;
        case 14: goto L_80800360; break;
        case 15: goto L_80800360; break;
        case 16: goto L_80800360; break;
        case 17: goto L_80800264; break;
        case 18: goto L_80800360; break;
        case 19: goto L_80800360; break;
        case 20: goto L_80800360; break;
        case 21: goto L_80800360; break;
        case 22: goto L_80800360; break;
        case 23: goto L_80800360; break;
        case 24: goto L_80800360; break;
        case 25: goto L_80800360; break;
        case 26: goto L_80800360; break;
        case 27: goto L_80800360; break;
        case 28: goto L_80800360; break;
        case 29: goto L_80800360; break;
        case 30: goto L_80800360; break;
        case 31: goto L_80800360; break;
        case 32: goto L_80800360; break;
        case 33: goto L_808002F0; break;
        case 34: goto L_80800360; break;
        case 35: goto L_80800360; break;
        case 36: goto L_80800360; break;
        case 37: goto L_80800360; break;
        case 38: goto L_80800360; break;
        case 39: goto L_80800360; break;
        case 40: goto L_80800360; break;
        case 41: goto L_80800360; break;
        case 42: goto L_80800360; break;
        case 43: goto L_80800360; break;
        case 44: goto L_80800360; break;
        case 45: goto L_80800360; break;
        case 46: goto L_80800360; break;
        case 47: goto L_808002DC; break;
        default: switch_error(__func__, 0x808001A0, 0x80800E50);
    }
    // 0x808001A4: nop

L_808001A8:
    // 0x808001A8: sltiu       $at, $t7, 0x2F
    ctx->r1 = ctx->r15 < 0X2F ? 1 : 0;
    // 0x808001AC: beq         $at, $zero, L_80800360
    if (ctx->r1 == 0) {
        // 0x808001B0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800360;
    }
    // 0x808001B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808001B4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1720, 0XF10) << 16);
    // 0x808001B8: addu        $at, $at, $t7
    gpr jr_addend_808001C0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x808001BC: lw          $t7, 0xF10($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1720, 0XF10));
    // 0x808001C0: jr          $t7
    // 0x808001C4: nop

    switch (jr_addend_808001C0 >> 2) {
        case 0: goto L_808001EC; break;
        case 1: goto L_80800360; break;
        case 2: goto L_80800360; break;
        case 3: goto L_80800360; break;
        case 4: goto L_80800360; break;
        case 5: goto L_80800360; break;
        case 6: goto L_80800360; break;
        case 7: goto L_80800360; break;
        case 8: goto L_80800360; break;
        case 9: goto L_80800360; break;
        case 10: goto L_80800360; break;
        case 11: goto L_80800360; break;
        case 12: goto L_80800360; break;
        case 13: goto L_80800360; break;
        case 14: goto L_80800360; break;
        case 15: goto L_808001D8; break;
        case 16: goto L_80800360; break;
        case 17: goto L_80800360; break;
        case 18: goto L_80800360; break;
        case 19: goto L_80800360; break;
        case 20: goto L_80800360; break;
        case 21: goto L_80800360; break;
        case 22: goto L_80800360; break;
        case 23: goto L_80800360; break;
        case 24: goto L_80800360; break;
        case 25: goto L_80800360; break;
        case 26: goto L_80800360; break;
        case 27: goto L_80800360; break;
        case 28: goto L_80800360; break;
        case 29: goto L_80800360; break;
        case 30: goto L_80800214; break;
        case 31: goto L_808001C8; break;
        case 32: goto L_80800360; break;
        case 33: goto L_80800360; break;
        case 34: goto L_80800360; break;
        case 35: goto L_80800360; break;
        case 36: goto L_80800360; break;
        case 37: goto L_80800360; break;
        case 38: goto L_80800360; break;
        case 39: goto L_80800360; break;
        case 40: goto L_80800360; break;
        case 41: goto L_80800360; break;
        case 42: goto L_80800360; break;
        case 43: goto L_80800360; break;
        case 44: goto L_80800360; break;
        case 45: goto L_80800360; break;
        case 46: goto L_80800200; break;
        default: switch_error(__func__, 0x808001C0, 0x80800F10);
    }
    // 0x808001C4: nop

L_808001C8:
    // 0x808001C8: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x808001CC: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808001D0: b           L_80800360
    // 0x808001D4: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
        goto L_80800360;
    // 0x808001D4: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
L_808001D8:
    // 0x808001D8: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x808001DC: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x808001E0: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x808001E4: b           L_80800360
    // 0x808001E8: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
        goto L_80800360;
    // 0x808001E8: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
L_808001EC:
    // 0x808001EC: lhu         $t3, 0x6E($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X6E);
    // 0x808001F0: andi        $t4, $t3, 0xFE00
    ctx->r12 = ctx->r11 & 0XFE00;
    // 0x808001F4: ori         $t5, $t4, 0x2
    ctx->r13 = ctx->r12 | 0X2;
    // 0x808001F8: b           L_80800360
    // 0x808001FC: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
        goto L_80800360;
    // 0x808001FC: sh          $t5, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r13;
L_80800200:
    // 0x80800200: lhu         $t6, 0x6E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800204: andi        $t7, $t6, 0xFE00
    ctx->r15 = ctx->r14 & 0XFE00;
    // 0x80800208: ori         $t8, $t7, 0x3
    ctx->r24 = ctx->r15 | 0X3;
    // 0x8080020C: b           L_80800360
    // 0x80800210: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
        goto L_80800360;
    // 0x80800210: sh          $t8, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r24;
L_80800214:
    // 0x80800214: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    // 0x80800218: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x8080021C: srl         $t0, $t9, 21
    ctx->r8 = S32(U32(ctx->r25) >> 21);
    // 0x80800220: bnel        $t0, $at, L_80800240
    if (ctx->r8 != ctx->r1) {
        // 0x80800224: lhu         $t4, 0x6E($s0)
        ctx->r12 = MEM_HU(ctx->r16, 0X6E);
            goto L_80800240;
    }
    goto skip_1;
    // 0x80800224: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    skip_1:
    // 0x80800228: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080022C: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x80800230: ori         $t3, $t2, 0x5
    ctx->r11 = ctx->r10 | 0X5;
    // 0x80800234: b           L_80800360
    // 0x80800238: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
        goto L_80800360;
    // 0x80800238: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
    // 0x8080023C: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
L_80800240:
    // 0x80800240: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x80800244: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x80800248: b           L_80800360
    // 0x8080024C: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
        goto L_80800360;
    // 0x8080024C: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
    // 0x80800250: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
L_80800254:
    // 0x80800254: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x80800258: ori         $t9, $t8, 0x6
    ctx->r25 = ctx->r24 | 0X6;
    // 0x8080025C: b           L_80800360
    // 0x80800260: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
        goto L_80800360;
    // 0x80800260: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
L_80800264:
    // 0x80800264: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800268: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x8080026C: ori         $t2, $t1, 0x7
    ctx->r10 = ctx->r9 | 0X7;
    // 0x80800270: b           L_80800360
    // 0x80800274: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
        goto L_80800360;
    // 0x80800274: sh          $t2, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r10;
L_80800278:
    // 0x80800278: lw          $t3, 0x6C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X6C);
    // 0x8080027C: addiu       $at, $zero, 0x5D
    ctx->r1 = ADD32(0, 0X5D);
    // 0x80800280: srl         $t4, $t3, 21
    ctx->r12 = S32(U32(ctx->r11) >> 21);
    // 0x80800284: bnel        $t4, $at, L_808002A4
    if (ctx->r12 != ctx->r1) {
        // 0x80800288: lhu         $t8, 0x6E($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X6E);
            goto L_808002A4;
    }
    goto skip_2;
    // 0x80800288: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    skip_2:
    // 0x8080028C: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800290: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x80800294: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x80800298: b           L_80800360
    // 0x8080029C: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
        goto L_80800360;
    // 0x8080029C: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
    // 0x808002A0: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
L_808002A4:
    // 0x808002A4: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x808002A8: ori         $t0, $t9, 0x9
    ctx->r8 = ctx->r25 | 0X9;
    // 0x808002AC: b           L_80800360
    // 0x808002B0: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
        goto L_80800360;
    // 0x808002B0: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
L_808002B4:
    // 0x808002B4: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x808002B8: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x808002BC: ori         $t3, $t2, 0xA
    ctx->r11 = ctx->r10 | 0XA;
    // 0x808002C0: b           L_80800360
    // 0x808002C4: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
        goto L_80800360;
    // 0x808002C4: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
L_808002C8:
    // 0x808002C8: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    // 0x808002CC: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x808002D0: ori         $t6, $t5, 0xB
    ctx->r14 = ctx->r13 | 0XB;
    // 0x808002D4: b           L_80800360
    // 0x808002D8: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
        goto L_80800360;
    // 0x808002D8: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
L_808002DC:
    // 0x808002DC: lhu         $t7, 0x6E($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6E);
    // 0x808002E0: andi        $t8, $t7, 0xFE00
    ctx->r24 = ctx->r15 & 0XFE00;
    // 0x808002E4: ori         $t9, $t8, 0xC
    ctx->r25 = ctx->r24 | 0XC;
    // 0x808002E8: b           L_80800360
    // 0x808002EC: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
        goto L_80800360;
    // 0x808002EC: sh          $t9, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r25;
L_808002F0:
    // 0x808002F0: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x808002F4: addiu       $at, $zero, 0x144
    ctx->r1 = ADD32(0, 0X144);
    // 0x808002F8: srl         $t1, $t0, 21
    ctx->r9 = S32(U32(ctx->r8) >> 21);
    // 0x808002FC: bne         $t1, $at, L_80800318
    if (ctx->r9 != ctx->r1) {
        // 0x80800300: nop
    
            goto L_80800318;
    }
    // 0x80800300: nop

    // 0x80800304: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800308: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x8080030C: ori         $t4, $t3, 0xD
    ctx->r12 = ctx->r11 | 0XD;
    // 0x80800310: b           L_80800360
    // 0x80800314: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
        goto L_80800360;
    // 0x80800314: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
L_80800318:
    // 0x80800318: jal         0x800DA298
    // 0x8080031C: addiu       $a0, $zero, 0x376
    ctx->r4 = ADD32(0, 0X376);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x8080031C: addiu       $a0, $zero, 0x376
    ctx->r4 = ADD32(0, 0X376);
    after_1:
    // 0x80800320: beql        $v0, $zero, L_80800340
    if (ctx->r2 == 0) {
        // 0x80800324: lhu         $t8, 0x6E($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0X6E);
            goto L_80800340;
    }
    goto skip_3;
    // 0x80800324: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    skip_3:
    // 0x80800328: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080032C: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x80800330: ori         $t7, $t6, 0xF
    ctx->r15 = ctx->r14 | 0XF;
    // 0x80800334: b           L_80800360
    // 0x80800338: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
        goto L_80800360;
    // 0x80800338: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
    // 0x8080033C: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
L_80800340:
    // 0x80800340: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800344: ori         $t0, $t9, 0xE
    ctx->r8 = ctx->r25 | 0XE;
    // 0x80800348: b           L_80800360
    // 0x8080034C: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
        goto L_80800360;
    // 0x8080034C: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
L_80800350:
    // 0x80800350: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800354: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x80800358: ori         $t3, $t2, 0x10
    ctx->r11 = ctx->r10 | 0X10;
    // 0x8080035C: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
L_80800360:
    // 0x80800360: lw          $t4, 0x6C($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X6C);
L_80800364:
    // 0x80800364: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80800368: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1720, 0X1084) << 16);
    // 0x8080036C: andi        $t5, $t4, 0x1FF
    ctx->r13 = ctx->r12 & 0X1FF;
    // 0x80800370: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80800374: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80800378: lhu         $a1, 0x1084($a1)
    ctx->r5 = MEM_HU(ctx->r5, (int16_t)RELOC_LO16(1720, 0X1084));
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800380: jal         0x80103140
    // 0x80800384: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    func_80103140(rdram, ctx);
        goto after_2;
    // 0x80800384: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    after_2:
    // 0x80800388: jal         0x800DA298
    // 0x8080038C: addiu       $a0, $zero, 0x64D
    ctx->r4 = ADD32(0, 0X64D);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x8080038C: addiu       $a0, $zero, 0x64D
    ctx->r4 = ADD32(0, 0X64D);
    after_3:
    // 0x80800390: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800394: jal         0x8010A654
    // 0x80800398: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010A654(rdram, ctx);
        goto after_4;
    // 0x80800398: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8080039C: jal         0x80800098
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800098_chmumbopad(rdram, ctx);
        goto after_5;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808003A4: beql        $v0, $zero, L_808003F4
    if (ctx->r2 == 0) {
        // 0x808003A8: lw          $t9, 0x6C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X6C);
            goto L_808003F4;
    }
    goto skip_4;
    // 0x808003A8: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
    skip_4:
    // 0x808003AC: jal         0x80103EAC
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103EAC(rdram, ctx);
        goto after_6;
    // 0x808003B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808003B4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808003B8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808003BC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x808003C0: jal         0x8010CB84
    // 0x808003C4: nop

    func_8010CB84(rdram, ctx);
        goto after_7;
    // 0x808003C4: nop

    after_7:
    // 0x808003C8: beq         $v0, $zero, L_808003E0
    if (ctx->r2 == 0) {
        // 0x808003CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808003E0;
    }
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D0: jal         0x80101FDC
    // 0x808003D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_8;
    // 0x808003D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x808003D8: b           L_808003F4
    // 0x808003DC: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
        goto L_808003F4;
    // 0x808003DC: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
L_808003E0:
    // 0x808003E0: jal         0x800FFAB0
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808003E8: b           L_8080043C
    // 0x808003EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080043C;
    // 0x808003EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003F0: lw          $t9, 0x6C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X6C);
L_808003F4:
    // 0x808003F4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1720, 0X1060) << 16);
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: andi        $t0, $t9, 0x1FF
    ctx->r8 = ctx->r25 & 0X1FF;
    // 0x80800400: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80800404: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x80800408: lh          $a2, 0x1060($a2)
    ctx->r6 = MEM_H(ctx->r6, (int16_t)RELOC_LO16(1720, 0X1060));
    // 0x8080040C: jal         0x80800014
    // 0x80800410: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    func_80800014_chmumbopad(rdram, ctx);
        goto after_10;
    // 0x80800410: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_10:
    // 0x80800414: jal         0x800F54E4
    // 0x80800418: nop

    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x80800418: nop

    after_11:
    // 0x8080041C: jal         0x800F5410
    // 0x80800420: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5410(rdram, ctx);
        goto after_12;
    // 0x80800420: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x80800424: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800428: beq         $v0, $at, L_80800438
    if (ctx->r2 == ctx->r1) {
        // 0x8080042C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800438;
    }
    // 0x8080042C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800430: jal         0x80089C98
    // 0x80800434: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_13;
    // 0x80800434: addiu       $a1, $zero, 0x87
    ctx->r5 = ADD32(0, 0X87);
    after_13:
L_80800438:
    // 0x80800438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080043C:
    // 0x8080043C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800440: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800444: jr          $ra
    // 0x80800448: nop

    return;
    // 0x80800448: nop

;}
RECOMP_FUNC void _chmusicmenu_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E70: syscall     463
    recomp_syscall_handler(rdram, ctx, 0x80086E70);
    return;
    // 0x80086E74: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void subaddieDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080019C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001A0: beq         $a1, $zero, L_808001B0
    if (ctx->r5 == 0) {
        // 0x808001A4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808001B0;
    }
    // 0x808001A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001A8: b           L_808001C4
    // 0x808001AC: sh          $zero, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = 0;
        goto L_808001C4;
    // 0x808001AC: sh          $zero, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = 0;
L_808001B0:
    // 0x808001B0: jal         0x80100368
    // 0x808001B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100368(rdram, ctx);
        goto after_0;
    // 0x808001B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001BC: lhu         $t6, 0x18($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X18);
    // 0x808001C0: sh          $t6, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r14;
L_808001C4:
    // 0x808001C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001CC: jr          $ra
    // 0x808001D0: nop

    return;
    // 0x808001D0: nop

;}
RECOMP_FUNC void func_8080000C_ch2dbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800010: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800018: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080001C: jal         0x8008A0F8
    // 0x80800020: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _sucoaster_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800020: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x80800024: beq         $v0, $zero, L_8080008C
    if (ctx->r2 == 0) {
        // 0x80800028: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080008C;
    }
    // 0x80800028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080002C: lui         $a1, 0x3F0C
    ctx->r5 = S32(0X3F0C << 16);
    // 0x80800030: jal         0x8010A3E8
    // 0x80800034: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    func_8010A3E8(rdram, ctx);
        goto after_1;
    // 0x80800034: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_1:
    // 0x80800038: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1356, 0X8A0) << 16);
    // 0x8080003C: lwc1        $f6, 0x8A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1356, 0X8A0));
    // 0x80800040: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800048: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8080004C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800050: jal         0x80102FDC
    // 0x80800054: nop

    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x80800054: nop

    after_2:
    // 0x80800058: jal         0x8008A110
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x8080005C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800060: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800064: jal         0x80800850
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800850_ch2dbaddy(rdram, ctx);
        goto after_4;
    // 0x80800068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080006C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800070: jal         0x800EE940
    // 0x80800074: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE940(rdram, ctx);
        goto after_5;
    // 0x80800074: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_5:
    // 0x80800078: lbu         $t6, 0x65($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X65);
    // 0x8080007C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800080: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x80800084: jal         0x8010A570
    // 0x80800088: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    func_8010A570(rdram, ctx);
        goto after_6;
    // 0x80800088: sb          $t7, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r15;
    after_6:
L_8080008C:
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800090: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800094: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800098: jr          $ra
    // 0x8080009C: nop

    return;
    // 0x8080009C: nop

;}
RECOMP_FUNC void _suexpressjoint_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089780: syscall     794
    recomp_syscall_handler(rdram, ctx, 0x80089780);
    return;
    // 0x80089784: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800C5F8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5F8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C5F90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800C5F94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C5F98: addiu       $t6, $t6, -0x5770
    ctx->r14 = ADD32(ctx->r14, -0X5770);
    // 0x800C5F9C: lui         $a1, 0xC68C
    ctx->r5 = S32(0XC68C << 16);
    // 0x800C5FA0: ori         $a1, $a1, 0xA000
    ctx->r5 = ctx->r5 | 0XA000;
    // 0x800C5FA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C5FA8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C5FAC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C5FB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C5FB4: jal         0x800C5EB8
    // 0x800C5FB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800C5EB8(rdram, ctx);
        goto after_0;
    // 0x800C5FB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800C5FBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C5FC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C5FC4: jr          $ra
    // 0x800C5FC8: nop

    return;
    // 0x800C5FC8: nop

;}
RECOMP_FUNC void func_80801058_chminisubgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801058: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080105C: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x80801060: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801064: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801068: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080106C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80801070: beq         $a1, $at, L_808011C4
    if (ctx->r5 == ctx->r1) {
        // 0x80801074: sw          $zero, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = 0;
            goto L_808011C4;
    }
    // 0x80801074: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80801078: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x8080107C: beq         $a1, $at, L_808011C4
    if (ctx->r5 == ctx->r1) {
        // 0x80801080: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_808011C4;
    }
    // 0x80801080: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80801084: beq         $a1, $at, L_80801100
    if (ctx->r5 == ctx->r1) {
        // 0x80801088: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80801100;
    }
    // 0x80801088: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8080108C: bne         $a1, $at, L_808011BC
    if (ctx->r5 != ctx->r1) {
        // 0x80801090: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808011BC;
    }
    // 0x80801090: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80801094: jal         0x8008A0B0
    // 0x80801098: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    _subaddiemulti_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80801098: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8080109C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808010A0: lw          $s0, 0x6C($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X6C);
    // 0x808010A4: lw          $a0, 0x3C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X3C);
    // 0x808010A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808010AC: andi        $t6, $s0, 0x1FF
    ctx->r14 = ctx->r16 & 0X1FF;
    // 0x808010B0: jal         0x80106790
    // 0x808010B4: addiu       $s0, $t6, 0x1
    ctx->r16 = ADD32(ctx->r14, 0X1);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808010B4: addiu       $s0, $t6, 0x1
    ctx->r16 = ADD32(ctx->r14, 0X1);
    after_1:
    // 0x808010B8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808010BC: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x808010C0: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x808010C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808010C8: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x808010CC: sw          $t8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r24;
    // 0x808010D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808010D8: jal         0x80086468
    // 0x808010DC: addiu       $a2, $v1, 0x4
    ctx->r6 = ADD32(ctx->r3, 0X4);
    _chscorepoints_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808010DC: addiu       $a2, $v1, 0x4
    ctx->r6 = ADD32(ctx->r3, 0X4);
    after_2:
    // 0x808010E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808010E4: addiu       $a1, $zero, 0x98
    ctx->r5 = ADD32(0, 0X98);
    // 0x808010E8: lhu         $t9, 0x18($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X18);
    // 0x808010EC: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x808010F0: beql        $t1, $zero, L_80801104
    if (ctx->r9 == 0) {
        // 0x808010F4: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_80801104;
    }
    goto skip_0;
    // 0x808010F4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808010F8: jal         0x8010114C
    // 0x808010FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010114C(rdram, ctx);
        goto after_3;
    // 0x808010FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_80801100:
    // 0x80801100: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_80801104:
    // 0x80801104: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80801108: bne         $t2, $zero, L_8080111C
    if (ctx->r10 != 0) {
        // 0x8080110C: nop
    
            goto L_8080111C;
    }
    // 0x8080110C: nop

    // 0x80801110: jal         0x80106790
    // 0x80801114: lw          $a0, 0x3C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X3C);
    func_80106790(rdram, ctx);
        goto after_4;
    // 0x80801114: lw          $a0, 0x3C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X3C);
    after_4:
    // 0x80801118: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_8080111C:
    // 0x8080111C: jal         0x8010A570
    // 0x80801120: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8010A570(rdram, ctx);
        goto after_5;
    // 0x80801120: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80801124: jal         0x800DA298
    // 0x80801128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80801128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x8080112C: bne         $v0, $zero, L_8080118C
    if (ctx->r2 != 0) {
        // 0x80801130: nop
    
            goto L_8080118C;
    }
    // 0x80801130: nop

    // 0x80801134: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80801138: addiu       $s0, $v0, 0x4
    ctx->r16 = ADD32(ctx->r2, 0X4);
    // 0x8080113C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801140: jal         0x8010CC10
    // 0x80801144: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    func_8010CC10(rdram, ctx);
        goto after_7;
    // 0x80801144: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    after_7:
    // 0x80801148: beq         $v0, $zero, L_8080118C
    if (ctx->r2 == 0) {
        // 0x8080114C: nop
    
            goto L_8080118C;
    }
    // 0x8080114C: nop

    // 0x80801150: jal         0x8010CCE0
    // 0x80801154: nop

    func_8010CCE0(rdram, ctx);
        goto after_8;
    // 0x80801154: nop

    after_8:
    // 0x80801158: jal         0x8010CCEC
    // 0x8080115C: nop

    func_8010CCEC(rdram, ctx);
        goto after_9;
    // 0x8080115C: nop

    after_9:
    // 0x80801160: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801164: beq         $v0, $at, L_8080118C
    if (ctx->r2 == ctx->r1) {
        // 0x80801168: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080118C;
    }
    // 0x80801168: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8080116C:
    // 0x8080116C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80801170: jal         0x800F7A2C
    // 0x80801174: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F7A2C(rdram, ctx);
        goto after_10;
    // 0x80801174: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_10:
    // 0x80801178: jal         0x8010CCEC
    // 0x8080117C: nop

    func_8010CCEC(rdram, ctx);
        goto after_11;
    // 0x8080117C: nop

    after_11:
    // 0x80801180: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801184: bne         $v0, $at, L_8080116C
    if (ctx->r2 != ctx->r1) {
        // 0x80801188: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080116C;
    }
    // 0x80801188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8080118C:
    // 0x8080118C: jal         0x80801248
    // 0x80801190: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80801248_chminisubgame(rdram, ctx);
        goto after_12;
    // 0x80801190: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_12:
    // 0x80801194: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80801198: lw          $a1, 0x34($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X34);
    // 0x8080119C: bltz        $a1, L_808011AC
    if (SIGNED(ctx->r5) < 0) {
        // 0x808011A0: nop
    
            goto L_808011AC;
    }
    // 0x808011A0: nop

    // 0x808011A4: jal         0x80800A64
    // 0x808011A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_80800A64_chminisubgame(rdram, ctx);
        goto after_13;
    // 0x808011A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_13:
L_808011AC:
    // 0x808011AC: jal         0x800FFAB0
    // 0x808011B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x808011B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_14:
    // 0x808011B4: b           L_808011C8
    // 0x808011B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808011C8;
    // 0x808011B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011BC:
    // 0x808011BC: b           L_808011C8
    // 0x808011C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808011C8;
    // 0x808011C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808011C4:
    // 0x808011C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808011C8:
    // 0x808011C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808011CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808011D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808011D4: jr          $ra
    // 0x808011D8: nop

    return;
    // 0x808011D8: nop

;}
RECOMP_FUNC void func_80800BF4_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800BFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C04: jal         0x800DA298
    // 0x80800C08: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800C08: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_0:
    // 0x80800C0C: bne         $v0, $zero, L_80800C34
    if (ctx->r2 != 0) {
        // 0x80800C10: nop
    
            goto L_80800C34;
    }
    // 0x80800C10: nop

    // 0x80800C14: jal         0x80088848
    // 0x80800C18: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x80800C18: nop

    after_1:
    // 0x80800C1C: bne         $v0, $zero, L_80800C34
    if (ctx->r2 != 0) {
        // 0x80800C20: nop
    
            goto L_80800C34;
    }
    // 0x80800C20: nop

    // 0x80800C24: jal         0x800FFAB0
    // 0x80800C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_2;
    // 0x80800C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800C2C: b           L_80800CC4
    // 0x80800C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800CC4;
    // 0x80800C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800C34:
    // 0x80800C34: jal         0x800DA298
    // 0x80800C38: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800C38: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    after_3:
    // 0x80800C3C: bne         $v0, $zero, L_80800C54
    if (ctx->r2 != 0) {
        // 0x80800C40: nop
    
            goto L_80800C54;
    }
    // 0x80800C40: nop

    // 0x80800C44: jal         0x80088848
    // 0x80800C48: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800C48: nop

    after_4:
    // 0x80800C4C: beql        $v0, $zero, L_80800C98
    if (ctx->r2 == 0) {
        // 0x80800C50: lw          $t8, 0x78($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X78);
            goto L_80800C98;
    }
    goto skip_0;
    // 0x80800C50: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
    skip_0:
L_80800C54:
    // 0x80800C54: jal         0x80105494
    // 0x80800C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105494(rdram, ctx);
        goto after_5;
    // 0x80800C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800C5C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800C60: sll         $t6, $a0, 21
    ctx->r14 = S32(ctx->r4 << 21);
    // 0x80800C64: jal         0x800D7520
    // 0x80800C68: sra         $a0, $t6, 22
    ctx->r4 = S32(SIGNED(ctx->r14) >> 22);
    func_800D7520(rdram, ctx);
        goto after_6;
    // 0x80800C68: sra         $a0, $t6, 22
    ctx->r4 = S32(SIGNED(ctx->r14) >> 22);
    after_6:
    // 0x80800C6C: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800C70: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800C74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C78: jal         0x800C7A68
    // 0x80800C7C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800C7A68(rdram, ctx);
        goto after_7;
    // 0x80800C7C: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80800C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C84: jal         0x80102424
    // 0x80800C88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_8;
    // 0x80800C88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800C8C: b           L_80800CB8
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800CB8;
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C94: lw          $t8, 0x78($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X78);
L_80800C98:
    // 0x80800C98: sll         $t0, $t8, 26
    ctx->r8 = S32(ctx->r24 << 26);
    // 0x80800C9C: bgezl       $t0, L_80800CB8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800CA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800CB8;
    }
    goto skip_1;
    // 0x80800CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800CA4: jal         0x800FFAB0
    // 0x80800CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_9;
    // 0x80800CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800CAC: b           L_80800CC4
    // 0x80800CB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800CC4;
    // 0x80800CB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800CB8:
    // 0x80800CB8: jal         0x80105A9C
    // 0x80800CBC: lui         $a1, 0x43E1
    ctx->r5 = S32(0X43E1 << 16);
    func_80105A9C(rdram, ctx);
        goto after_10;
    // 0x80800CBC: lui         $a1, 0x43E1
    ctx->r5 = S32(0X43E1 << 16);
    after_10:
    // 0x80800CC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CC4:
    // 0x80800CC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800CCC: jr          $ra
    // 0x80800CD0: nop

    return;
    // 0x80800CD0: nop

;}
RECOMP_FUNC void func_800BA574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BA578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BA57C: jal         0x800EE814
    // 0x800BA580: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    func_800EE814(rdram, ctx);
        goto after_0;
    // 0x800BA580: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x800BA584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BA588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BA58C: jr          $ra
    // 0x800BA590: nop

    return;
    // 0x800BA590: nop

;}
RECOMP_FUNC void _bsride_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083A00: syscall     85
    recomp_syscall_handler(rdram, ctx, 0x80083A00);
    return;
    // 0x80083A04: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800100_chjujubagfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800100: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800104: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800108: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080010C: jal         0x8010D278
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8010D278(rdram, ctx);
        goto after_0;
    // 0x80800110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800114: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80800118: beq         $v0, $at, L_80800140
    if (ctx->r2 == ctx->r1) {
        // 0x8080011C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80800140;
    }
    // 0x8080011C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800120: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800124: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x80800128: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8080012C: jal         0x80089C20
    // 0x80800130: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiefind_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800130: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80800134: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80800138: b           L_80800148
    // 0x8080013C: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
        goto L_80800148;
    // 0x8080013C: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
L_80800140:
    // 0x80800140: jal         0x8008FE94
    // 0x80800144: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_8008FE94(rdram, ctx);
        goto after_2;
    // 0x80800144: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_2:
L_80800148:
    // 0x80800148: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x8080014C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800150: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800154: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x80800158: jal         0x8080000C
    // 0x8080015C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_8080000C_chjujubagfx(rdram, ctx);
        goto after_3;
    // 0x8080015C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_3:
    // 0x80800160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800164: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800168: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080016C: jr          $ra
    // 0x80800170: nop

    return;
    // 0x80800170: nop

;}
RECOMP_FUNC void func_80801114_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801114: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080111C: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x80801120: bgtz        $v0, L_80801130
    if (SIGNED(ctx->r2) > 0) {
        // 0x80801124: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80801130;
    }
    // 0x80801124: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80801128: b           L_80801180
    // 0x8080112C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801180;
    // 0x8080112C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801130:
    // 0x80801130: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    // 0x80801134: lh          $a1, 0x6($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X6);
    // 0x80801138: jal         0x80800038
    // 0x8080113C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800038_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x8080113C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801140: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801144: bne         $v0, $at, L_8080117C
    if (ctx->r2 != ctx->r1) {
        // 0x80801148: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080117C;
    }
    // 0x80801148: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8080114C: lh          $t9, 0xA($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XA);
    // 0x80801150: lh          $t7, 0x8($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X8);
    // 0x80801154: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80801158: sh          $t0, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r8;
    // 0x8080115C: lh          $t1, 0xA($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XA);
    // 0x80801160: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80801164: sh          $t8, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r24;
    // 0x80801168: bgezl       $t1, L_80801180
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8080116C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801180;
    }
    goto skip_0;
    // 0x8080116C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80801170: lh          $t2, 0x2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2);
    // 0x80801174: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80801178: sh          $t3, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r11;
L_8080117C:
    // 0x8080117C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801180:
    // 0x80801180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801188: jr          $ra
    // 0x8080118C: nop

    return;
    // 0x8080118C: nop

;}
