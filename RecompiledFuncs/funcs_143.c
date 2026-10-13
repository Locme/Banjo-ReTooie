#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808008A0_chdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808008A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808008B0: jal         0x80100094
    // 0x808008B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808008B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008B8: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x808008BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808008C0: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808008C4: beq         $t6, $zero, L_808008D4
    if (ctx->r14 == 0) {
        // 0x808008C8: nop
    
            goto L_808008D4;
    }
    // 0x808008C8: nop

    // 0x808008CC: b           L_808008D4
    // 0x808008D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_808008D4;
    // 0x808008D0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_808008D4:
    // 0x808008D4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808008D8: andi        $t7, $a0, 0x4000
    ctx->r15 = ctx->r4 & 0X4000;
    // 0x808008DC: beq         $t7, $zero, L_80800914
    if (ctx->r15 == 0) {
        // 0x808008E0: andi        $t8, $a0, 0x80
        ctx->r24 = ctx->r4 & 0X80;
            goto L_80800914;
    }
    // 0x808008E0: andi        $t8, $a0, 0x80
    ctx->r24 = ctx->r4 & 0X80;
    // 0x808008E4: beql        $t8, $zero, L_80800914
    if (ctx->r24 == 0) {
        // 0x808008E8: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_80800914;
    }
    goto skip_0;
    // 0x808008E8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    skip_0:
    // 0x808008EC: lhu         $a0, 0x2A($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2A);
    // 0x808008F0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808008F4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x808008F8: andi        $t9, $a0, 0x7FFF
    ctx->r25 = ctx->r4 & 0X7FFF;
    // 0x808008FC: jal         0x800DA298
    // 0x80800900: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800900: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x80800904: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800908: bne         $v0, $zero, L_80800914
    if (ctx->r2 != 0) {
        // 0x8080090C: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80800914;
    }
    // 0x8080090C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800910: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_80800914:
    // 0x80800914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800918: jal         0x80800B14
    // 0x8080091C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80800B14_chdoor(rdram, ctx);
        goto after_2;
    // 0x8080091C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800920: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800924: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80800928: srl         $t1, $t0, 26
    ctx->r9 = S32(U32(ctx->r8) >> 26);
    // 0x8080092C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80800930: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x80800934: beq         $at, $zero, L_808009D8
    if (ctx->r1 == 0) {
        // 0x80800938: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_808009D8;
    }
    // 0x80800938: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8080093C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1148, 0X1558) << 16);
    // 0x80800940: addu        $at, $at, $t2
    gpr jr_addend_80800948 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80800944: lw          $t2, 0x1558($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1148, 0X1558));
    // 0x80800948: jr          $t2
    // 0x8080094C: nop

    switch (jr_addend_80800948 >> 2) {
        case 0: goto L_80800950; break;
        case 1: goto L_80800968; break;
        case 2: goto L_8080097C; break;
        case 3: goto L_80800994; break;
        case 4: goto L_808009CC; break;
        default: switch_error(__func__, 0x80800948, 0x80801558);
    }
    // 0x8080094C: nop

L_80800950:
    // 0x80800950: lh          $t3, 0x10($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X10);
    // 0x80800954: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80800958: nop

    // 0x8080095C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800960: b           L_808009D8
    // 0x80800964: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
        goto L_808009D8;
    // 0x80800964: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
L_80800968:
    // 0x80800968: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080096C: jal         0x800EE88C
    // 0x80800970: addiu       $a1, $v1, 0x16
    ctx->r5 = ADD32(ctx->r3, 0X16);
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x80800970: addiu       $a1, $v1, 0x16
    ctx->r5 = ADD32(ctx->r3, 0X16);
    after_3:
    // 0x80800974: b           L_808009D8
    // 0x80800978: nop

        goto L_808009D8;
    // 0x80800978: nop

L_8080097C:
    // 0x8080097C: lh          $t4, 0x10($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X10);
    // 0x80800980: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80800984: nop

    // 0x80800988: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8080098C: b           L_808009D8
    // 0x80800990: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
        goto L_808009D8;
    // 0x80800990: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
L_80800994:
    // 0x80800994: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800998: addiu       $a1, $v1, 0x16
    ctx->r5 = ADD32(ctx->r3, 0X16);
    // 0x8080099C: jal         0x800EE88C
    // 0x808009A0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800EE88C(rdram, ctx);
        goto after_4;
    // 0x808009A0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x808009A4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808009A8: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x808009AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808009B0: lh          $t5, 0x1C($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X1C);
    // 0x808009B4: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x808009B8: nop

    // 0x808009BC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x808009C0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808009C4: b           L_808009D8
    // 0x808009C8: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
        goto L_808009D8;
    // 0x808009C8: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
L_808009CC:
    // 0x808009CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808009D0: jal         0x80089C98
    // 0x808009D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddiefade_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x808009D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_808009D8:
    // 0x808009D8: jal         0x80103014
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_6;
    // 0x808009DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808009E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808009E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808009EC: jr          $ra
    // 0x808009F0: nop

    return;
    // 0x808009F0: nop

;}
RECOMP_FUNC void func_80094F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094F38: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80094F3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80094F40: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80094F44: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80094F48: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80094F4C: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x80094F50: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80094F54: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80094F58: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x80094F5C: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x80094F60: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80094F64: sb          $zero, 0x2($t2)
    MEM_B(0X2, ctx->r10) = 0;
    // 0x80094F68: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x80094F6C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80094F70: jr          $ra
    // 0x80094F74: sb          $zero, 0x3($t4)
    MEM_B(0X3, ctx->r12) = 0;
    return;
    // 0x80094F74: sb          $zero, 0x3($t4)
    MEM_B(0X3, ctx->r12) = 0;
    // 0x80094F78: nop

    // 0x80094F7C: nop

;}
RECOMP_FUNC void func_800AE020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE020: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AE024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AE02C: jal         0x8001B668
    // 0x800AE030: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    func_8001B668(rdram, ctx);
        goto after_0;
    // 0x800AE030: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_0:
    // 0x800AE034: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800AE038: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800AE03C: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x800AE040: jal         0x800AE080
    // 0x800AE044: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    func_800AE080(rdram, ctx);
        goto after_1;
    // 0x800AE044: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_1:
    // 0x800AE048: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800AE04C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800AE050: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AE054: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800AE058: jal         0x80019CD4
    // 0x800AE05C: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    func_80019CD4(rdram, ctx);
        goto after_2;
    // 0x800AE05C: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    after_2:
    // 0x800AE060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800AE064: jal         0x80018AD0
    // 0x800AE068: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    mlMtxGet(rdram, ctx);
        goto after_3;
    // 0x800AE068: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_3:
    // 0x800AE06C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE070: lh          $v0, 0x1E($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X1E);
    // 0x800AE074: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AE078: jr          $ra
    // 0x800AE07C: nop

    return;
    // 0x800AE07C: nop

;}
RECOMP_FUNC void func_800C7364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C736C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C7370: jal         0x800C7338
    // 0x800C7374: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800C7338(rdram, ctx);
        goto after_0;
    // 0x800C7374: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C7378: beq         $v0, $zero, L_800C7394
    if (ctx->r2 == 0) {
        // 0x800C737C: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_800C7394;
    }
    // 0x800C737C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800C7380: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C7384: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7388: bnel        $t6, $zero, L_800C7398
    if (ctx->r14 != 0) {
        // 0x800C738C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C7398;
    }
    goto skip_0;
    // 0x800C738C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C7390: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_800C7394:
    // 0x800C7394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C7398:
    // 0x800C7398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C739C: jr          $ra
    // 0x800C73A0: nop

    return;
    // 0x800C73A0: nop

;}
RECOMP_FUNC void func_8008FFBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FFBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008FFC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008FFC4: jal         0x800F54E4
    // 0x8008FFC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8008FFC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008FFCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8008FFD0: jal         0x800F5D70
    // 0x8008FFD4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_800F5D70(rdram, ctx);
        goto after_1;
    // 0x8008FFD4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8008FFD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008FFDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FFE0: jr          $ra
    // 0x8008FFE4: nop

    return;
    // 0x8008FFE4: nop

;}
RECOMP_FUNC void _gccubesearch_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800882D0: syscall     678
    recomp_syscall_handler(rdram, ctx, 0x800882D0);
    return;
    // 0x800882D4: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void chbigterrysbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1056, 0X410) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1056, 0X410));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x410
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1056, 0X410));
;}
RECOMP_FUNC void func_80026CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026CB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80026CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026CB8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80026CBC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80026CC0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80026CC4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80026CC8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80026CCC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80026CD0: beq         $t7, $zero, L_80026DC4
    if (ctx->r15 == 0) {
        // 0x80026CD4: nop
    
            goto L_80026DC4;
    }
    // 0x80026CD4: nop

    // 0x80026CD8: jal         0x80021794
    // 0x80026CDC: nop

    func_80021794(rdram, ctx);
        goto after_0;
    // 0x80026CDC: nop

    after_0:
    // 0x80026CE0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80026CE4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80026CE8: bne         $t8, $zero, L_80026CF8
    if (ctx->r24 != 0) {
        // 0x80026CEC: nop
    
            goto L_80026CF8;
    }
    // 0x80026CEC: nop

    // 0x80026CF0: b           L_80026DCC
    // 0x80026CF4: nop

        goto L_80026DCC;
    // 0x80026CF4: nop

L_80026CF8:
    // 0x80026CF8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80026CFC: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80026D00: lw          $t9, 0x11F4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F4);
    // 0x80026D04: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80026D08: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80026D0C: lw          $t0, 0x1C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C);
    // 0x80026D10: lw          $t3, 0x88($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X88);
    // 0x80026D14: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x80026D18: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x80026D1C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80026D20: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80026D24: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80026D28: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x80026D2C: sh          $t7, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r15;
    // 0x80026D30: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80026D34: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80026D38: lh          $t1, 0x1A($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X1A);
    // 0x80026D3C: sh          $t1, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r9;
    // 0x80026D40: lbu         $t0, 0x33($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X33);
    // 0x80026D44: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80026D48: sb          $t0, 0x12($t3)
    MEM_B(0X12, ctx->r11) = ctx->r8;
    // 0x80026D4C: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80026D50: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80026D54: sh          $t4, 0x10($t5)
    MEM_H(0X10, ctx->r13) = ctx->r12;
    // 0x80026D58: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x80026D5C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80026D60: sb          $t6, 0x13($t7)
    MEM_B(0X13, ctx->r15) = ctx->r14;
    // 0x80026D64: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80026D68: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80026D6C: swc1        $f4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f4.u32l;
    // 0x80026D70: lbu         $t9, 0x43($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X43);
    // 0x80026D74: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80026D78: sb          $t9, 0x14($t1)
    MEM_B(0X14, ctx->r9) = ctx->r25;
    // 0x80026D7C: lbu         $t2, 0x3B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3B);
    // 0x80026D80: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80026D84: sb          $t2, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r10;
    // 0x80026D88: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80026D8C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80026D90: swc1        $f6, 0x18($t3)
    MEM_W(0X18, ctx->r11) = ctx->f6.u32l;
    // 0x80026D94: jal         0x80021928
    // 0x80026D98: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    func_80021928(rdram, ctx);
        goto after_1;
    // 0x80026D98: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_1:
    // 0x80026D9C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80026DA0: sw          $v0, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->r2;
    // 0x80026DA4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80026DA8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80026DAC: sw          $t5, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r13;
    // 0x80026DB0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80026DB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80026DB8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80026DBC: jal         0x8002B684
    // 0x80026DC0: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    func_8002B684(rdram, ctx);
        goto after_2;
    // 0x80026DC0: lw          $a0, 0x8($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X8);
    after_2:
L_80026DC4:
    // 0x80026DC4: b           L_80026DCC
    // 0x80026DC8: nop

        goto L_80026DCC;
    // 0x80026DC8: nop

L_80026DCC:
    // 0x80026DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026DD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80026DD4: jr          $ra
    // 0x80026DD8: nop

    return;
    // 0x80026DD8: nop

    // 0x80026DDC: nop

;}
RECOMP_FUNC void func_80801994_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080199C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808019A0: jal         0x80100094
    // 0x808019A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808019A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808019A8: beq         $v0, $zero, L_808019B8
    if (ctx->r2 == 0) {
        // 0x808019AC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_808019B8;
    }
    // 0x808019AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808019B0: jal         0x800897C8
    // 0x808019B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808019B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_808019B8:
    // 0x808019B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808019BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808019C0: jr          $ra
    // 0x808019C4: nop

    return;
    // 0x808019C4: nop

;}
RECOMP_FUNC void _idworld_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F18: syscall     748
    recomp_syscall_handler(rdram, ctx, 0x80088F18);
    return;
    // 0x80088F1C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void bskazstilt_entrypoint_23(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801068: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8080106C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(292, 0X1250) << 16);
    // 0x80801070: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801074: jr          $ra
    // 0x80801078: lw          $v0, 0x1250($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1250));
    return;
    // 0x80801078: lw          $v0, 0x1250($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(292, 0X1250));
;}
RECOMP_FUNC void func_808025CC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808025D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808025D4: jal         0x80087AF0
    // 0x808025D8: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    _gczoombox_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808025D8: lw          $a0, 0x28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X28);
    after_0:
    // 0x808025DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808025E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808025E4: jr          $ra
    // 0x808025E8: nop

    return;
    // 0x808025E8: nop

;}
RECOMP_FUNC void _bsmum_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083868: syscall     75
    recomp_syscall_handler(rdram, ctx, 0x80083868);
    return;
    // 0x8008386C: addi        $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
;}
RECOMP_FUNC void func_8008C1CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C1CC: jr          $ra
    // 0x8008C1D0: sb          $a1, 0x1E($a0)
    MEM_B(0X1E, ctx->r4) = ctx->r5;
    return;
    // 0x8008C1D0: sb          $a1, 0x1E($a0)
    MEM_B(0X1E, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_808066CC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808066CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808066D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808066D4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808066D8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808066DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808066E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808066E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808066E8: jal         0x80088150
    // 0x808066EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x808066EC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x808066F0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x808066F4: jal         0x80088158
    // 0x808066F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_5(rdram, ctx);
        goto after_1;
    // 0x808066F8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x808066FC: blez        $s3, L_80806724
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80806700: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80806724;
    }
    // 0x80806700: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80806704: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80806708:
    // 0x80806708: jal         0x80088148
    // 0x8080670C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcfrontend_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080670C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80806710: beq         $v0, $zero, L_8080671C
    if (ctx->r2 == 0) {
        // 0x80806714: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8080671C;
    }
    // 0x80806714: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80806718: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8080671C:
    // 0x8080671C: bne         $s1, $s3, L_80806708
    if (ctx->r17 != ctx->r19) {
        // 0x80806720: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80806708;
    }
    // 0x80806720: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80806724:
    // 0x80806724: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80806728: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8080672C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80806730: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80806734: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80806738: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080673C: jr          $ra
    // 0x80806740: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80806740: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _chfantasysafeswitch_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800877D0: syscall     628
    recomp_syscall_handler(rdram, ctx, 0x800877D0);
    return;
    // 0x800877D4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800FB908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB908: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FB90C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FB910: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FB914: jal         0x80017244
    // 0x800FB918: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80017244(rdram, ctx);
        goto after_0;
    // 0x800FB918: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800FB91C: jal         0x80016E7C
    // 0x800FB920: nop

    func_80016E7C(rdram, ctx);
        goto after_1;
    // 0x800FB920: nop

    after_1:
    // 0x800FB924: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FB928: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800FB92C: addiu       $s1, $s1, 0x59B0
    ctx->r17 = ADD32(ctx->r17, 0X59B0);
    // 0x800FB930: addiu       $s0, $s0, 0x57D0
    ctx->r16 = ADD32(ctx->r16, 0X57D0);
L_800FB934:
    // 0x800FB934: jal         0x800B3248
    // 0x800FB938: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    freelist_free(rdram, ctx);
        goto after_2;
    // 0x800FB938: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x800FB93C: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    // 0x800FB940: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800FB944: bne         $at, $zero, L_800FB934
    if (ctx->r1 != 0) {
        // 0x800FB948: sw          $zero, -0x18($s0)
        MEM_W(-0X18, ctx->r16) = 0;
            goto L_800FB934;
    }
    // 0x800FB948: sw          $zero, -0x18($s0)
    MEM_W(-0X18, ctx->r16) = 0;
    // 0x800FB94C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB950: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800FB954: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FB958: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FB95C: sb          $zero, 0x3E40($at)
    MEM_B(0X3E40, ctx->r1) = 0;
    // 0x800FB960: jr          $ra
    // 0x800FB964: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FB964: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _chbounce_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085918: syscall     180
    recomp_syscall_handler(rdram, ctx, 0x80085918);
    return;
    // 0x8008591C: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_808011A8_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808011AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808011B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808011B4: lw          $a2, 0x160($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X160);
    // 0x808011B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808011BC: lui         $a1, 0x3F5C
    ctx->r5 = S32(0X3F5C << 16);
    // 0x808011C0: beq         $a2, $at, L_808011D0
    if (ctx->r6 == ctx->r1) {
        // 0x808011C4: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_808011D0;
    }
    // 0x808011C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808011C8: jal         0x800E144C
    // 0x808011CC: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    func_800E144C(rdram, ctx);
        goto after_0;
    // 0x808011CC: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    after_0:
L_808011D0:
    // 0x808011D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808011D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808011D8: jal         0x8009E55C
    // 0x808011DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8009E55C(rdram, ctx);
        goto after_1;
    // 0x808011DC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_1:
    // 0x808011E0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x808011E4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808011E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808011EC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x808011F0: jal         0x80085498
    // 0x808011F4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    _bamotor_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808011F4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    after_2:
    // 0x808011F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808011FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801200: jr          $ra
    // 0x80801204: nop

    return;
    // 0x80801204: nop

;}
RECOMP_FUNC void badata_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800A00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800A04: jal         0x80800000
    // 0x80800A08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800A08: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800A0C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80800A10: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80800A14: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(473, 0X2498) << 16);
    // 0x80800A18: addiu       $t7, $t7, 0x2498
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(473, 0X2498));
    // 0x80800A1C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800A20: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80800A24: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80800A28: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A2C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80800A30: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800A34: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800A38: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x80800A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800A44: jr          $ra
    // 0x80800A48: nop

    return;
    // 0x80800A48: nop

;}
RECOMP_FUNC void func_800C3E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3E00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C3E04: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C3E08: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C3E0C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C3E10: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C3E14: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C3E18: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C3E1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C3E20: addiu       $s1, $s1, -0x73F0
    ctx->r17 = ADD32(ctx->r17, -0X73F0);
    // 0x800C3E24: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800C3E28: addiu       $s3, $zero, 0x3C
    ctx->r19 = ADD32(0, 0X3C);
L_800C3E2C:
    // 0x800C3E2C: lbu         $t6, 0x78($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X78);
    // 0x800C3E30: beql        $t6, $zero, L_800C3E60
    if (ctx->r14 == 0) {
        // 0x800C3E34: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C3E60;
    }
    goto skip_0;
    // 0x800C3E34: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800C3E38: jal         0x800C3D78
    // 0x800C3E3C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C3D78(rdram, ctx);
        goto after_0;
    // 0x800C3E3C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x800C3E40: beql        $v0, $zero, L_800C3E60
    if (ctx->r2 == 0) {
        // 0x800C3E44: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C3E60;
    }
    goto skip_1;
    // 0x800C3E44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x800C3E48: lh          $t7, 0x58($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X58);
    // 0x800C3E4C: bnel        $s2, $t7, L_800C3E60
    if (ctx->r18 != ctx->r15) {
        // 0x800C3E50: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C3E60;
    }
    goto skip_2;
    // 0x800C3E50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x800C3E54: b           L_800C3E6C
    // 0x800C3E58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C3E6C;
    // 0x800C3E58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C3E5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C3E60:
    // 0x800C3E60: bne         $s0, $s3, L_800C3E2C
    if (ctx->r16 != ctx->r19) {
        // 0x800C3E64: addiu       $s1, $s1, 0x80
        ctx->r17 = ADD32(ctx->r17, 0X80);
            goto L_800C3E2C;
    }
    // 0x800C3E64: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x800C3E68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C3E6C:
    // 0x800C3E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C3E70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C3E74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C3E78: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3E7C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C3E80: jr          $ra
    // 0x800C3E84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C3E84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80802290_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802290: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80802294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802298: jal         0x80100094
    // 0x8080229C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080229C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808022A0: lbu         $t6, 0x24($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X24);
    // 0x808022A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808022A8: bnel        $t6, $at, L_808024D4
    if (ctx->r14 != ctx->r1) {
        // 0x808022AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808024D4;
    }
    goto skip_0;
    // 0x808022AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808022B0: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x808022B4: jal         0x80104200
    // 0x808022B8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_80104200(rdram, ctx);
        goto after_1;
    // 0x808022B8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808022BC: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x808022C0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x808022C4: jal         0x80104200
    // 0x808022C8: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    func_80104200(rdram, ctx);
        goto after_2;
    // 0x808022C8: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    after_2:
    // 0x808022CC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x808022D0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x808022D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x808022D8: jal         0x80016068
    // 0x808022DC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80016068(rdram, ctx);
        goto after_3;
    // 0x808022DC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x808022E0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x808022E4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x808022E8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808022EC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x808022F0: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x808022F4: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808022F8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x808022FC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80802300: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80802304: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80802308: nop

    // 0x8080230C: bc1fl       L_80802320
    if (!c1cs) {
        // 0x80802310: neg.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
            goto L_80802320;
    }
    goto skip_1;
    // 0x80802310: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
    skip_1:
    // 0x80802314: b           L_80802320
    // 0x80802318: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_80802320;
    // 0x80802318: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8080231C: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
L_80802320:
    // 0x80802320: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80802324: nop

    // 0x80802328: bc1fl       L_8080233C
    if (!c1cs) {
        // 0x8080232C: neg.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
            goto L_8080233C;
    }
    goto skip_2;
    // 0x8080232C: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    skip_2:
    // 0x80802330: b           L_8080233C
    // 0x80802334: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_8080233C;
    // 0x80802334: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80802338: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
L_8080233C:
    // 0x8080233C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80802340: nop

    // 0x80802344: bc1fl       L_80802398
    if (!c1cs) {
        // 0x80802348: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80802398;
    }
    goto skip_3;
    // 0x80802348: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_3:
    // 0x8080234C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80802350: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80802354: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80802358: lui         $at, 0xBE80
    ctx->r1 = S32(0XBE80 << 16);
    // 0x8080235C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80802360: nop

    // 0x80802364: bc1fl       L_80802378
    if (!c1cs) {
        // 0x80802368: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80802378;
    }
    goto skip_4;
    // 0x80802368: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_4:
    // 0x8080236C: b           L_808023D4
    // 0x80802370: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_808023D4;
    // 0x80802370: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80802374: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80802378:
    // 0x80802378: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8080237C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80802380: nop

    // 0x80802384: bc1fl       L_808023D8
    if (!c1cs) {
        // 0x80802388: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_808023D8;
    }
    goto skip_5;
    // 0x80802388: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    skip_5:
    // 0x8080238C: b           L_808023D4
    // 0x80802390: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
        goto L_808023D4;
    // 0x80802390: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80802394: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80802398:
    // 0x80802398: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8080239C: lui         $at, 0xBE80
    ctx->r1 = S32(0XBE80 << 16);
    // 0x808023A0: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x808023A4: nop

    // 0x808023A8: bc1fl       L_808023BC
    if (!c1cs) {
        // 0x808023AC: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_808023BC;
    }
    goto skip_6;
    // 0x808023AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_6:
    // 0x808023B0: b           L_808023D4
    // 0x808023B4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
        goto L_808023D4;
    // 0x808023B4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x808023B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_808023BC:
    // 0x808023BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808023C0: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x808023C4: nop

    // 0x808023C8: bc1fl       L_808023D8
    if (!c1cs) {
        // 0x808023CC: lw          $t2, 0x18($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X18);
            goto L_808023D8;
    }
    goto skip_7;
    // 0x808023CC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    skip_7:
    // 0x808023D0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_808023D4:
    // 0x808023D4: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
L_808023D8:
    // 0x808023D8: lbu         $t3, 0x27($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X27);
    // 0x808023DC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x808023E0: beq         $t2, $t3, L_808024C0
    if (ctx->r10 == ctx->r11) {
        // 0x808023E4: sltiu       $at, $t4, 0x5
        ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
            goto L_808024C0;
    }
    // 0x808023E4: sltiu       $at, $t4, 0x5
    ctx->r1 = ctx->r12 < 0X5 ? 1 : 0;
    // 0x808023E8: beq         $at, $zero, L_80802480
    if (ctx->r1 == 0) {
        // 0x808023EC: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80802480;
    }
    // 0x808023EC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x808023F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X415C) << 16);
    // 0x808023F4: addu        $at, $at, $t4
    gpr jr_addend_808023FC = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x808023F8: lw          $t4, 0x415C($at)
    ctx->r12 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1692, 0X415C));
    // 0x808023FC: jr          $t4
    // 0x80802400: nop

    switch (jr_addend_808023FC >> 2) {
        case 0: goto L_80802480; break;
        case 1: goto L_80802444; break;
        case 2: goto L_80802464; break;
        case 3: goto L_80802404; break;
        case 4: goto L_80802424; break;
        default: switch_error(__func__, 0x808023FC, 0x8080415C);
    }
    // 0x80802400: nop

L_80802404:
    // 0x80802404: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80802408: jal         0x8008AED4
    // 0x8080240C: addiu       $a1, $zero, 0x484
    ctx->r5 = ADD32(0, 0X484);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x8080240C: addiu       $a1, $zero, 0x484
    ctx->r5 = ADD32(0, 0X484);
    after_4:
    // 0x80802410: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80802414: jal         0x8008AED4
    // 0x80802418: addiu       $a1, $zero, 0x489
    ctx->r5 = ADD32(0, 0X489);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x80802418: addiu       $a1, $zero, 0x489
    ctx->r5 = ADD32(0, 0X489);
    after_5:
    // 0x8080241C: b           L_80802480
    // 0x80802420: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
        goto L_80802480;
    // 0x80802420: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_80802424:
    // 0x80802424: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80802428: jal         0x8008AED4
    // 0x8080242C: addiu       $a1, $zero, 0x485
    ctx->r5 = ADD32(0, 0X485);
    anctrl_setIndex(rdram, ctx);
        goto after_6;
    // 0x8080242C: addiu       $a1, $zero, 0x485
    ctx->r5 = ADD32(0, 0X485);
    after_6:
    // 0x80802430: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80802434: jal         0x8008AED4
    // 0x80802438: addiu       $a1, $zero, 0x48A
    ctx->r5 = ADD32(0, 0X48A);
    anctrl_setIndex(rdram, ctx);
        goto after_7;
    // 0x80802438: addiu       $a1, $zero, 0x48A
    ctx->r5 = ADD32(0, 0X48A);
    after_7:
    // 0x8080243C: b           L_80802480
    // 0x80802440: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
        goto L_80802480;
    // 0x80802440: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_80802444:
    // 0x80802444: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80802448: jal         0x8008AED4
    // 0x8080244C: addiu       $a1, $zero, 0x482
    ctx->r5 = ADD32(0, 0X482);
    anctrl_setIndex(rdram, ctx);
        goto after_8;
    // 0x8080244C: addiu       $a1, $zero, 0x482
    ctx->r5 = ADD32(0, 0X482);
    after_8:
    // 0x80802450: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80802454: jal         0x8008AED4
    // 0x80802458: addiu       $a1, $zero, 0x487
    ctx->r5 = ADD32(0, 0X487);
    anctrl_setIndex(rdram, ctx);
        goto after_9;
    // 0x80802458: addiu       $a1, $zero, 0x487
    ctx->r5 = ADD32(0, 0X487);
    after_9:
    // 0x8080245C: b           L_80802480
    // 0x80802460: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
        goto L_80802480;
    // 0x80802460: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_80802464:
    // 0x80802464: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80802468: jal         0x8008AED4
    // 0x8080246C: addiu       $a1, $zero, 0x483
    ctx->r5 = ADD32(0, 0X483);
    anctrl_setIndex(rdram, ctx);
        goto after_10;
    // 0x8080246C: addiu       $a1, $zero, 0x483
    ctx->r5 = ADD32(0, 0X483);
    after_10:
    // 0x80802470: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80802474: jal         0x8008AED4
    // 0x80802478: addiu       $a1, $zero, 0x488
    ctx->r5 = ADD32(0, 0X488);
    anctrl_setIndex(rdram, ctx);
        goto after_11;
    // 0x80802478: addiu       $a1, $zero, 0x488
    ctx->r5 = ADD32(0, 0X488);
    after_11:
    // 0x8080247C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_80802480:
    // 0x80802480: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x80802484: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80802488: beql        $t5, $zero, L_808024BC
    if (ctx->r13 == 0) {
        // 0x8080248C: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_808024BC;
    }
    goto skip_8;
    // 0x8080248C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    skip_8:
    // 0x80802490: jal         0x8008B134
    // 0x80802494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_12;
    // 0x80802494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80802498: jal         0x8008B064
    // 0x8080249C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    anctrl_start(rdram, ctx);
        goto after_13;
    // 0x8080249C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_13:
    // 0x808024A0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x808024A4: jal         0x8008B134
    // 0x808024A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_14;
    // 0x808024A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x808024AC: jal         0x8008B064
    // 0x808024B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_15;
    // 0x808024B0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_15:
    // 0x808024B4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x808024B8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
L_808024BC:
    // 0x808024BC: sb          $t6, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r14;
L_808024C0:
    // 0x808024C0: jal         0x8008ADE4
    // 0x808024C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8008ADE4(rdram, ctx);
        goto after_16;
    // 0x808024C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_16:
    // 0x808024C8: jal         0x8008ADE4
    // 0x808024CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8008ADE4(rdram, ctx);
        goto after_17;
    // 0x808024CC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_17:
    // 0x808024D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808024D4:
    // 0x808024D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808024D8: jr          $ra
    // 0x808024DC: nop

    return;
    // 0x808024DC: nop

;}
RECOMP_FUNC void func_80800C70_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800C74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800C80: jal         0x8008CABC
    // 0x80800C84: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800C84: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x80800C88: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800C8C: jal         0x80800000
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_bswasher(rdram, ctx);
        goto after_1;
    // 0x80800C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800C98: jal         0x8009BB24
    // 0x80800C9C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_2;
    // 0x80800C9C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80800CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CA4: jal         0x80091A30
    // 0x80800CA8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_3;
    // 0x80800CA8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80800CAC: beq         $v0, $zero, L_80800CD4
    if (ctx->r2 == 0) {
        // 0x80800CB0: lwc1        $f6, 0x28($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800CD4;
    }
    // 0x80800CB0: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800CB4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800CB8: nop

    // 0x80800CBC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800CC0: nop

    // 0x80800CC4: bc1fl       L_80800CD8
    if (!c1cs) {
        // 0x80800CC8: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_80800CD8;
    }
    goto skip_0;
    // 0x80800CC8: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_0:
    // 0x80800CCC: jal         0x8009BC6C
    // 0x80800CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_4;
    // 0x80800CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80800CD4:
    // 0x80800CD4: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_80800CD8:
    // 0x80800CD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800CDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CE0: beq         $v0, $zero, L_80800D10
    if (ctx->r2 == 0) {
        // 0x80800CE4: nop
    
            goto L_80800D10;
    }
    // 0x80800CE4: nop

    // 0x80800CE8: beq         $v0, $at, L_80800D68
    if (ctx->r2 == ctx->r1) {
        // 0x80800CEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D68;
    }
    // 0x80800CEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800CF4: beq         $v0, $at, L_80800D90
    if (ctx->r2 == ctx->r1) {
        // 0x80800CF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D90;
    }
    // 0x80800CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800CFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800D00: beq         $v0, $at, L_80800DCC
    if (ctx->r2 == ctx->r1) {
        // 0x80800D04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800DCC;
    }
    // 0x80800D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D08: b           L_80800E38
    // 0x80800D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800E38;
    // 0x80800D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800D10:
    // 0x80800D10: jal         0x8008DF8C
    // 0x80800D14: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_5;
    // 0x80800D14: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_5:
    // 0x80800D18: beq         $v0, $zero, L_80800D3C
    if (ctx->r2 == 0) {
        // 0x80800D1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800D3C;
    }
    // 0x80800D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D20: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x80800D24: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800D28: jal         0x8008CF1C
    // 0x80800D2C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_6;
    // 0x80800D2C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x80800D30: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800D34: b           L_80800E34
    // 0x80800D38: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
        goto L_80800E34;
    // 0x80800D38: sw          $t6, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r14;
L_80800D3C:
    // 0x80800D3C: jal         0x8008B324
    // 0x80800D40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_7;
    // 0x80800D40: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_7:
    // 0x80800D44: beq         $v0, $zero, L_80800E34
    if (ctx->r2 == 0) {
        // 0x80800D48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E34;
    }
    // 0x80800D48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D4C: lui         $a1, 0x3F34
    ctx->r5 = S32(0X3F34 << 16);
    // 0x80800D50: ori         $a1, $a1, 0xBC6A
    ctx->r5 = ctx->r5 | 0XBC6A;
    // 0x80800D54: jal         0x8008CF1C
    // 0x80800D58: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_8;
    // 0x80800D58: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_8:
    // 0x80800D5C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80800D60: b           L_80800E34
    // 0x80800D64: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
        goto L_80800E34;
    // 0x80800D64: sw          $t7, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r15;
L_80800D68:
    // 0x80800D68: jal         0x8008DF8C
    // 0x80800D6C: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_9;
    // 0x80800D6C: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_9:
    // 0x80800D70: beq         $v0, $zero, L_80800E34
    if (ctx->r2 == 0) {
        // 0x80800D74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E34;
    }
    // 0x80800D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D78: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800D7C: jal         0x8008CF1C
    // 0x80800D80: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_10;
    // 0x80800D80: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_10:
    // 0x80800D84: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80800D88: b           L_80800E34
    // 0x80800D8C: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
        goto L_80800E34;
    // 0x80800D8C: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_80800D90:
    // 0x80800D90: jal         0x8009D3A8
    // 0x80800D94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_11;
    // 0x80800D94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80800D98: jal         0x8008E078
    // 0x80800D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_12;
    // 0x80800D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800DA0: beql        $v0, $zero, L_80800E38
    if (ctx->r2 == 0) {
        // 0x80800DA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800E38;
    }
    goto skip_1;
    // 0x80800DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80800DA8: jal         0x800A2EAC
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A2EAC(rdram, ctx);
        goto after_13;
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DB4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800DB8: jal         0x8008CF1C
    // 0x80800DBC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_14;
    // 0x80800DBC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_14:
    // 0x80800DC0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80800DC4: b           L_80800E34
    // 0x80800DC8: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
        goto L_80800E34;
    // 0x80800DC8: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
L_80800DCC:
    // 0x80800DCC: jal         0x8009D2D8
    // 0x80800DD0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8009D2D8(rdram, ctx);
        goto after_15;
    // 0x80800DD0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_15:
    // 0x80800DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DD8: jal         0x8009D3A8
    // 0x80800DDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_16;
    // 0x80800DDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800DE0: jal         0x8009BB5C
    // 0x80800DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_17;
    // 0x80800DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800DE8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800DEC: addiu       $t0, $zero, 0x33
    ctx->r8 = ADD32(0, 0X33);
    // 0x80800DF0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80800DF4: nop

    // 0x80800DF8: bc1f        L_80800E08
    if (!c1cs) {
        // 0x80800DFC: nop
    
            goto L_80800E08;
    }
    // 0x80800DFC: nop

    // 0x80800E00: b           L_80800E1C
    // 0x80800E04: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
        goto L_80800E1C;
    // 0x80800E04: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80800E08:
    // 0x80800E08: jal         0x8008B324
    // 0x80800E0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_18;
    // 0x80800E0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_18:
    // 0x80800E10: beq         $v0, $zero, L_80800E1C
    if (ctx->r2 == 0) {
        // 0x80800E14: addiu       $t1, $zero, 0x32
        ctx->r9 = ADD32(0, 0X32);
            goto L_80800E1C;
    }
    // 0x80800E14: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80800E18: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
L_80800E1C:
    // 0x80800E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E20: jal         0x80091A58
    // 0x80800E24: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_pressed(rdram, ctx);
        goto after_19;
    // 0x80800E24: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_19:
    // 0x80800E28: beq         $v0, $zero, L_80800E34
    if (ctx->r2 == 0) {
        // 0x80800E2C: addiu       $t2, $zero, 0x35
        ctx->r10 = ADD32(0, 0X35);
            goto L_80800E34;
    }
    // 0x80800E2C: addiu       $t2, $zero, 0x35
    ctx->r10 = ADD32(0, 0X35);
    // 0x80800E30: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80800E34:
    // 0x80800E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E38:
    // 0x80800E38: jal         0x80091A58
    // 0x80800E3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bakey_pressed(rdram, ctx);
        goto after_20;
    // 0x80800E3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x80800E40: beq         $v0, $zero, L_80800E4C
    if (ctx->r2 == 0) {
        // 0x80800E44: addiu       $t3, $zero, 0x38
        ctx->r11 = ADD32(0, 0X38);
            goto L_80800E4C;
    }
    // 0x80800E44: addiu       $t3, $zero, 0x38
    ctx->r11 = ADD32(0, 0X38);
    // 0x80800E48: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
L_80800E4C:
    // 0x80800E4C: jal         0x80800300
    // 0x80800E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800300_bswasher(rdram, ctx);
        goto after_21;
    // 0x80800E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E58: jal         0x8009E5C8
    // 0x80800E5C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_22;
    // 0x80800E5C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_22:
    // 0x80800E60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800E68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800E6C: jr          $ra
    // 0x80800E70: nop

    return;
    // 0x80800E70: nop

;}
RECOMP_FUNC void _suspline_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089DB8: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089DB8);
    return;
    // 0x80089DBC: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_800CF9E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF9E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CF9E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF9EC: jal         0x800CF918
    // 0x800CF9F0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_800CF918(rdram, ctx);
        goto after_0;
    // 0x800CF9F0: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x800CF9F4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800CF9F8: addiu       $t7, $t7, -0x518C
    ctx->r15 = ADD32(ctx->r15, -0X518C);
    // 0x800CF9FC: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800CFA00: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CFA04: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800CFA08: addiu       $v1, $sp, 0x28
    ctx->r3 = ADD32(ctx->r29, 0X28);
    // 0x800CFA0C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
L_800CFA10:
    // 0x800CFA10: lbu         $t8, 0xC($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XC);
    // 0x800CFA14: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800CFA18: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CFA1C: bne         $v1, $a1, L_800CFA10
    if (ctx->r3 != ctx->r5) {
        // 0x800CFA20: sw          $t8, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r24;
            goto L_800CFA10;
    }
    // 0x800CFA20: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x800CFA24: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800CFA28: addiu       $t0, $t0, -0x518C
    ctx->r8 = ADD32(ctx->r8, -0X518C);
    // 0x800CFA2C: sll         $t9, $a2, 4
    ctx->r25 = S32(ctx->r6 << 4);
    // 0x800CFA30: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800CFA34: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x800CFA38: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800CFA3C: jal         0x800C8D4C
    // 0x800CFA40: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_800C8D4C(rdram, ctx);
        goto after_1;
    // 0x800CFA40: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x800CFA44: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800CFA48: jal         0x800C8E84
    // 0x800CFA4C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800C8E84(rdram, ctx);
        goto after_2;
    // 0x800CFA4C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x800CFA50: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800CFA54: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800CFA58: jal         0x800C8F64
    // 0x800CFA5C: lbu         $a1, 0xF($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0XF);
    func_800C8F64(rdram, ctx);
        goto after_3;
    // 0x800CFA5C: lbu         $a1, 0xF($t1)
    ctx->r5 = MEM_BU(ctx->r9, 0XF);
    after_3:
    // 0x800CFA60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CFA64: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800CFA68: jr          $ra
    // 0x800CFA6C: nop

    return;
    // 0x800CFA6C: nop

;}
RECOMP_FUNC void bsdronefired_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: jal         0x800845D0
    // 0x8080000C: nop

    _babounce_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080000C: nop

    after_0:
    // 0x80800010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800018: jr          $ra
    // 0x8080001C: nop

    return;
    // 0x8080001C: nop

;}
RECOMP_FUNC void gcmapsects_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080279C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808027A0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x808027A4: sw          $s7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r23;
    // 0x808027A8: sw          $s6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r22;
    // 0x808027AC: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x808027B0: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x808027B4: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x808027B8: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x808027BC: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x808027C0: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x808027C4: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x808027C8: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x808027CC: lbu         $t6, 0x77($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X77);
    // 0x808027D0: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x808027D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808027D8: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x808027DC: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x808027E0: bne         $t6, $zero, L_808027F0
    if (ctx->r14 != 0) {
        // 0x808027E4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_808027F0;
    }
    // 0x808027E4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x808027E8: b           L_808028C0
    // 0x808027EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808028C0;
    // 0x808027EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808027F0:
    // 0x808027F0: jal         0x800BEB58
    // 0x808027F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEB58(rdram, ctx);
        goto after_0;
    // 0x808027F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x808027F8: lbu         $t7, 0x77($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X77);
    // 0x808027FC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80802800: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80802804: blez        $t7, L_808028BC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80802808: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_808028BC;
    }
    // 0x80802808: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080280C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80802810: lw          $s5, 0x70($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X70);
    // 0x80802814: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
L_80802818:
    // 0x80802818: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x8080281C: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x80802820: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x80802824: bgezl       $t1, L_808028A8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80802828: lbu         $t5, 0x77($s1)
        ctx->r13 = MEM_BU(ctx->r17, 0X77);
            goto L_808028A8;
    }
    goto skip_0;
    // 0x80802828: lbu         $t5, 0x77($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X77);
    skip_0:
    // 0x8080282C: jal         0x800D674C
    // 0x80802830: lhu         $a0, 0x40($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X40);
    func_800D674C(rdram, ctx);
        goto after_1;
    // 0x80802830: lhu         $a0, 0x40($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X40);
    after_1:
    // 0x80802834: beq         $v0, $zero, L_808028A4
    if (ctx->r2 == 0) {
        // 0x80802838: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_808028A4;
    }
    // 0x80802838: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8080283C: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
    // 0x80802840: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80802844: jal         0x800D62E4
    // 0x80802848: lhu         $a0, 0x40($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X40);
    func_800D62E4(rdram, ctx);
        goto after_2;
    // 0x80802848: lhu         $a0, 0x40($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X40);
    after_2:
    // 0x8080284C: jal         0x800B2720
    // 0x80802850: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800B2720(rdram, ctx);
        goto after_3;
    // 0x80802850: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80802854: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80802858: jal         0x800B2840
    // 0x8080285C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800B2840(rdram, ctx);
        goto after_4;
    // 0x8080285C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x80802860: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x80802864: sw          $s5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r21;
    // 0x80802868: sw          $s7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r23;
    // 0x8080286C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80802870: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x80802874: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80802878: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080287C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80802884: jal         0x800AD1AC
    // 0x80802888: addu        $a2, $t4, $s0
    ctx->r6 = ADD32(ctx->r12, ctx->r16);
    func_800AD1AC(rdram, ctx);
        goto after_5;
    // 0x80802888: addu        $a2, $t4, $s0
    ctx->r6 = ADD32(ctx->r12, ctx->r16);
    after_5:
    // 0x8080288C: beq         $v0, $zero, L_808028A4
    if (ctx->r2 == 0) {
        // 0x80802890: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_808028A4;
    }
    // 0x80802890: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80802894: jal         0x800BEB58
    // 0x80802898: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_800BEB58(rdram, ctx);
        goto after_6;
    // 0x80802898: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x8080289C: b           L_808028C0
    // 0x808028A0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_808028C0;
    // 0x808028A0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_808028A4:
    // 0x808028A4: lbu         $t5, 0x77($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X77);
L_808028A8:
    // 0x808028A8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x808028AC: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x808028B0: slt         $at, $s4, $t5
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x808028B4: bnel        $at, $zero, L_80802818
    if (ctx->r1 != 0) {
        // 0x808028B8: lw          $t8, 0x68($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X68);
            goto L_80802818;
    }
    goto skip_1;
    // 0x808028B8: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    skip_1:
L_808028BC:
    // 0x808028BC: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_808028C0:
    // 0x808028C0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x808028C4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x808028C8: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x808028CC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x808028D0: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x808028D4: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x808028D8: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x808028DC: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x808028E0: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x808028E4: lw          $s6, 0x54($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X54);
    // 0x808028E8: lw          $s7, 0x58($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X58);
    // 0x808028EC: jr          $ra
    // 0x808028F0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x808028F0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void sukickball_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800CF4: jal         0x80100094
    // 0x80800CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800CF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800CFC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D00: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D04: sb          $zero, 0x34($t7)
    MEM_B(0X34, ctx->r15) = 0;
    // 0x80800D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D10: jr          $ra
    // 0x80800D14: nop

    return;
    // 0x80800D14: nop

;}
RECOMP_FUNC void _chbosskogsdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874F8: syscall     581
    recomp_syscall_handler(rdram, ctx, 0x800874F8);
    return;
    // 0x800874FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800460_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800460: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800464: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800468: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080046C: lhu         $a1, 0x72($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X72);
    // 0x80800470: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800474: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800478: srl         $t6, $a1, 10
    ctx->r14 = S32(U32(ctx->r5) >> 10);
    // 0x8080047C: beq         $t6, $at, L_80800494
    if (ctx->r14 == ctx->r1) {
        // 0x80800480: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80800494;
    }
    // 0x80800480: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800484: beql        $t6, $at, L_80800524
    if (ctx->r14 == ctx->r1) {
        // 0x80800488: lw          $t9, 0x64($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X64);
            goto L_80800524;
    }
    goto skip_0;
    // 0x80800488: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x8080048C: b           L_80800554
    // 0x80800490: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800554;
    // 0x80800490: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800494:
    // 0x80800494: jal         0x800F54E4
    // 0x80800498: nop

    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800498: nop

    after_0:
    // 0x8080049C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808004A0: jal         0x800F64A4
    // 0x808004A4: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x808004A4: addiu       $a1, $zero, 0x201
    ctx->r5 = ADD32(0, 0X201);
    after_1:
    // 0x808004A8: bne         $v0, $zero, L_808004E0
    if (ctx->r2 != 0) {
        // 0x808004AC: addiu       $a1, $zero, 0x109F
        ctx->r5 = ADD32(0, 0X109F);
            goto L_808004E0;
    }
    // 0x808004AC: addiu       $a1, $zero, 0x109F
    ctx->r5 = ADD32(0, 0X109F);
    // 0x808004B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004B4: addiu       $t7, $zero, 0x43
    ctx->r15 = ADD32(0, 0X43);
    // 0x808004B8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808004BC: addiu       $a1, $zero, 0x10A0
    ctx->r5 = ADD32(0, 0X10A0);
    // 0x808004C0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808004C4: jal         0x8008A208
    // 0x808004C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x808004C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x808004CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004D0: jal         0x8080082C
    // 0x808004D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080082C_chmadamegrunty(rdram, ctx);
        goto after_3;
    // 0x808004D4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x808004D8: b           L_80800504
    // 0x808004DC: nop

        goto L_80800504;
    // 0x808004DC: nop

L_808004E0:
    // 0x808004E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004E4: addiu       $t8, $zero, 0x43
    ctx->r24 = ADD32(0, 0X43);
    // 0x808004E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808004EC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808004F0: jal         0x8008A208
    // 0x808004F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_4;
    // 0x808004F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: jal         0x8080082C
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080082C_chmadamegrunty(rdram, ctx);
        goto after_5;
    // 0x80800500: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
L_80800504:
    // 0x80800504: jal         0x800F54E4
    // 0x80800508: nop

    func_800F54E4(rdram, ctx);
        goto after_6;
    // 0x80800508: nop

    after_6:
    // 0x8080050C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800510: jal         0x800F82D4
    // 0x80800514: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_7;
    // 0x80800514: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x80800518: b           L_80800554
    // 0x8080051C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800554;
    // 0x8080051C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800520: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
L_80800524:
    // 0x80800524: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800528: sll         $t1, $t9, 11
    ctx->r9 = S32(ctx->r25 << 11);
    // 0x8080052C: bgez        $t1, L_8080053C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80800530: nop
    
            goto L_8080053C;
    }
    // 0x80800530: nop

    // 0x80800534: b           L_8080053C
    // 0x80800538: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
        goto L_8080053C;
    // 0x80800538: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_8080053C:
    // 0x8080053C: jal         0x8080082C
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080082C_chmadamegrunty(rdram, ctx);
        goto after_8;
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800544: lbu         $t2, 0x65($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X65);
    // 0x80800548: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x8080054C: sb          $t3, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r11;
    // 0x80800550: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800554:
    // 0x80800554: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800558: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080055C: jr          $ra
    // 0x80800560: nop

    return;
    // 0x80800560: nop

;}
RECOMP_FUNC void func_80801C78_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C80: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1312, 0X2850) << 16);
    // 0x80801C84: addiu       $a2, $a2, 0x2850
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1312, 0X2850));
    // 0x80801C88: jal         0x80089D18
    // 0x80801C8C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801C8C: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80801C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C98: jr          $ra
    // 0x80801C9C: nop

    return;
    // 0x80801C9C: nop

;}
RECOMP_FUNC void func_80800090_chstatictorch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800098: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080009C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808000A0: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x808000A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x808000A8: jal         0x8008FB10
    // 0x808000AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8008FB10(rdram, ctx);
        goto after_0;
    // 0x808000AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x808000B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: jal         0x80100094
    // 0x808000B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808000B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808000BC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x808000C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000C4: jal         0x80089938
    // 0x808000C8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    _suflamefx_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808000C8: addiu       $a1, $a1, 0x18
    ctx->r5 = ADD32(ctx->r5, 0X18);
    after_2:
    // 0x808000CC: jal         0x80800140
    // 0x808000D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800140_chstatictorch(rdram, ctx);
        goto after_3;
    // 0x808000D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808000D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000DC: jr          $ra
    // 0x808000E0: nop

    return;
    // 0x808000E0: nop

;}
RECOMP_FUNC void _chjujubagfx_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086C90: syscall     439
    recomp_syscall_handler(rdram, ctx, 0x80086C90);
    return;
    // 0x80086C94: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void scinfobar_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800420: jr          $ra
    // 0x80800424: sw          $a1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r5;
    return;
    // 0x80800424: sw          $a1, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void _dbmorph_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087998: syscall     643
    recomp_syscall_handler(rdram, ctx, 0x80087998);
    return;
    // 0x8008799C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void _bssplitup_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083B18: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083B18);
    return;
    // 0x80083B1C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void func_800AA0D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA0D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800AA0D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AA0D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AA0DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AA0E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AA0E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AA0E8: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x800AA0EC: addiu       $s2, $zero, 0x4E
    ctx->r18 = ADD32(0, 0X4E);
L_800AA0F0:
    // 0x800AA0F0: jal         0x800A9F80
    // 0x800AA0F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A9F80(rdram, ctx);
        goto after_0;
    // 0x800AA0F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800AA0F8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800AA0FC: bne         $s0, $s2, L_800AA0F0
    if (ctx->r16 != ctx->r18) {
        // 0x800AA100: addu        $s1, $s1, $v0
        ctx->r17 = ADD32(ctx->r17, ctx->r2);
            goto L_800AA0F0;
    }
    // 0x800AA100: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x800AA104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AA108: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800AA10C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AA110: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AA114: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AA118: jr          $ra
    // 0x800AA11C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800AA11C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_808008B8_chfactorycrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008B8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808008BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008C0: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x808008C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808008CC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x808008D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808008D4: addiu       $a1, $t6, 0x18
    ctx->r5 = ADD32(ctx->r14, 0X18);
    // 0x808008D8: jal         0x800EFE50
    // 0x808008DC: addiu       $a2, $t6, 0x28
    ctx->r6 = ADD32(ctx->r14, 0X28);
    func_800EFE50(rdram, ctx);
        goto after_0;
    // 0x808008DC: addiu       $a2, $t6, 0x28
    ctx->r6 = ADD32(ctx->r14, 0X28);
    after_0:
    // 0x808008E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008E8: jr          $ra
    // 0x808008EC: nop

    return;
    // 0x808008EC: nop

;}
RECOMP_FUNC void func_80800A98_bsmumswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800A9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800AA0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800AA4: jal         0x800848D8
    // 0x80800AA8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _badrone_entrypoint_30(rdram, ctx);
        goto after_0;
    // 0x80800AA8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800AAC: beq         $v0, $zero, L_80800AB8
    if (ctx->r2 == 0) {
        // 0x80800AB0: addiu       $t6, $zero, 0xE5
        ctx->r14 = ADD32(0, 0XE5);
            goto L_80800AB8;
    }
    // 0x80800AB0: addiu       $t6, $zero, 0xE5
    ctx->r14 = ADD32(0, 0XE5);
    // 0x80800AB4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80800AB8:
    // 0x80800AB8: jal         0x80082FE8
    // 0x80800ABC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _bsdrone_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800ABC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800AC0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800AC4: jal         0x8009E5C8
    // 0x80800AC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_2;
    // 0x80800AC8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80800ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800AD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800AD4: jr          $ra
    // 0x80800AD8: nop

    return;
    // 0x80800AD8: nop

;}
RECOMP_FUNC void func_808018B0_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018B8: jal         0x80100094
    // 0x808018BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808018BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808018C0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808018C4: sb          $zero, 0x558($v0)
    MEM_B(0X558, ctx->r2) = 0;
    // 0x808018C8: sb          $zero, 0x559($v0)
    MEM_B(0X559, ctx->r2) = 0;
    // 0x808018CC: swc1        $f4, 0x55C($v0)
    MEM_W(0X55C, ctx->r2) = ctx->f4.u32l;
    // 0x808018D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018D8: jr          $ra
    // 0x808018DC: nop

    return;
    // 0x808018DC: nop

;}
RECOMP_FUNC void func_80800A40_chmasterjiggy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800A44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800A48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A4C: jal         0x800D8FF8
    // 0x80800A50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x80800A50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800A54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800A58: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800A5C: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800A60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800A64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A68: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80800A6C: nop

    // 0x80800A70: bc1f        L_80800AA4
    if (!c1cs) {
        // 0x80800A74: nop
    
            goto L_80800AA4;
    }
    // 0x80800A74: nop

    // 0x80800A78: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80800A7C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800A80: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80800A84: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x80800A88: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800A8C: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x80800A90: nop

    // 0x80800A94: bc1f        L_80800AA4
    if (!c1cs) {
        // 0x80800A98: nop
    
            goto L_80800AA4;
    }
    // 0x80800A98: nop

    // 0x80800A9C: swc1        $f12, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f12.u32l;
    // 0x80800AA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800AA4:
    // 0x80800AA4: jal         0x808010E4
    // 0x80800AA8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_808010E4_chmasterjiggy(rdram, ctx);
        goto after_1;
    // 0x80800AA8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800AAC: jal         0x80801448
    // 0x80800AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801448_chmasterjiggy(rdram, ctx);
        goto after_2;
    // 0x80800AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800AB4: jal         0x80801488
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801488_chmasterjiggy(rdram, ctx);
        goto after_3;
    // 0x80800AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800ABC: jal         0x8080096C
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080096C_chmasterjiggy(rdram, ctx);
        goto after_4;
    // 0x80800AC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800AC4: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800AC8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800ACC: addiu       $t8, $t7, -0x2
    ctx->r24 = ADD32(ctx->r15, -0X2);
    // 0x80800AD0: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80800AD4: beq         $at, $zero, L_80800BF4
    if (ctx->r1 == 0) {
        // 0x80800AD8: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800BF4;
    }
    // 0x80800AD8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800ADC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(768, 0X1590) << 16);
    // 0x80800AE0: addu        $at, $at, $t8
    gpr jr_addend_80800AE8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800AE4: lw          $t8, 0x1590($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(768, 0X1590));
    // 0x80800AE8: jr          $t8
    // 0x80800AEC: nop

    switch (jr_addend_80800AE8 >> 2) {
        case 0: goto L_80800AF0; break;
        case 1: goto L_80800B10; break;
        case 2: goto L_80800B48; break;
        case 3: goto L_80800B90; break;
        case 4: goto L_80800BD8; break;
        default: switch_error(__func__, 0x80800AE8, 0x80801590);
    }
    // 0x80800AEC: nop

L_80800AF0:
    // 0x80800AF0: jal         0x800D90A4
    // 0x80800AF4: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    func_800D90A4(rdram, ctx);
        goto after_5;
    // 0x80800AF4: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    after_5:
    // 0x80800AF8: beq         $v0, $zero, L_80800BF4
    if (ctx->r2 == 0) {
        // 0x80800AFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800BF4;
    }
    // 0x80800AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B00: jal         0x80800E58
    // 0x80800B04: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800E58_chmasterjiggy(rdram, ctx);
        goto after_6;
    // 0x80800B04: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x80800B08: b           L_80800BF8
    // 0x80800B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B10:
    // 0x80800B10: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(768, 0X16B0) << 16);
    // 0x80800B14: addiu       $a1, $a1, 0x16B0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(768, 0X16B0));
    // 0x80800B18: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800B1C: jal         0x800F3780
    // 0x80800B20: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_800F3780(rdram, ctx);
        goto after_7;
    // 0x80800B20: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_7:
    // 0x80800B24: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800B28: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80800B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B30: beql        $t9, $zero, L_80800BF8
    if (ctx->r25 == 0) {
        // 0x80800B34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BF8;
    }
    goto skip_0;
    // 0x80800B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800B38: jal         0x80800E58
    // 0x80800B3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800E58_chmasterjiggy(rdram, ctx);
        goto after_8;
    // 0x80800B3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x80800B40: b           L_80800BF8
    // 0x80800B44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800B44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B48:
    // 0x80800B48: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(768, 0X1760) << 16);
    // 0x80800B4C: addiu       $a1, $a1, 0x1760
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(768, 0X1760));
    // 0x80800B50: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800B54: jal         0x800F3780
    // 0x80800B58: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800F3780(rdram, ctx);
        goto after_9;
    // 0x80800B58: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_9:
    // 0x80800B5C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80800B60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800B64: lui         $a1, 0x3F40
    ctx->r5 = S32(0X3F40 << 16);
    // 0x80800B68: jal         0x80018820
    // 0x80800B6C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    func_80018820(rdram, ctx);
        goto after_10;
    // 0x80800B6C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_10:
    // 0x80800B70: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B78: beql        $t0, $zero, L_80800BF8
    if (ctx->r8 == 0) {
        // 0x80800B7C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BF8;
    }
    goto skip_1;
    // 0x80800B7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800B80: jal         0x808001D0
    // 0x80800B84: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808001D0_chmasterjiggy(rdram, ctx);
        goto after_11;
    // 0x80800B84: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_11:
    // 0x80800B88: b           L_80800BF8
    // 0x80800B8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800B8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800B90:
    // 0x80800B90: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(768, 0X1770) << 16);
    // 0x80800B94: addiu       $a1, $a1, 0x1770
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(768, 0X1770));
    // 0x80800B98: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800B9C: jal         0x800F3780
    // 0x80800BA0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800F3780(rdram, ctx);
        goto after_12;
    // 0x80800BA0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
    // 0x80800BA4: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80800BA8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80800BAC: beql        $t1, $zero, L_80800BF8
    if (ctx->r9 == 0) {
        // 0x80800BB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BF8;
    }
    goto skip_2;
    // 0x80800BB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800BB4: jal         0x80085710
    // 0x80800BB8: nop

    _capod_entrypoint_14(rdram, ctx);
        goto after_13;
    // 0x80800BB8: nop

    after_13:
    // 0x80800BBC: jal         0x8008A698
    // 0x80800BC0: nop

    _sujiggy_entrypoint_0(rdram, ctx);
        goto after_14;
    // 0x80800BC0: nop

    after_14:
    // 0x80800BC4: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x80800BC8: jal         0x8008A710
    // 0x80800BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sujiggy_entrypoint_15(rdram, ctx);
        goto after_15;
    // 0x80800BCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80800BD0: b           L_80800BF8
    // 0x80800BD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800BF8;
    // 0x80800BD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BD8:
    // 0x80800BD8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(768, 0X16E8) << 16);
    // 0x80800BDC: addiu       $a1, $a1, 0x16E8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(768, 0X16E8));
    // 0x80800BE0: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80800BE4: jal         0x800F3780
    // 0x80800BE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_800F3780(rdram, ctx);
        goto after_16;
    // 0x80800BE8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_16:
    // 0x80800BEC: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80800BF0: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_80800BF4:
    // 0x80800BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800BF8:
    // 0x80800BF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800BFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800C00: jr          $ra
    // 0x80800C04: nop

    return;
    // 0x80800C04: nop

;}
RECOMP_FUNC void _chjellycastle_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087758: syscall     619
    recomp_syscall_handler(rdram, ctx, 0x80087758);
    return;
    // 0x8008775C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void chfactorymagnet_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802384: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2284, 0X2AB4) << 16);
    // 0x80802388: jr          $ra
    // 0x8080238C: addiu       $v0, $v0, 0x2AB4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2284, 0X2AB4));
    return;
    // 0x8080238C: addiu       $v0, $v0, 0x2AB4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2284, 0X2AB4));
;}
RECOMP_FUNC void _chdippy_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086490: syscall     327
    recomp_syscall_handler(rdram, ctx, 0x80086490);
    return;
    // 0x80086494: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80800248_bswalk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800248: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080024C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800250: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800254: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800258: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080025C: jal         0x80091A58
    // 0x80800260: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x80800260: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80800264: beql        $v0, $zero, L_808002B4
    if (ctx->r2 == 0) {
        // 0x80800268: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002B4;
    }
    goto skip_0;
    // 0x80800268: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080026C: jal         0x8009BB00
    // 0x80800270: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baphysics_get_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x80800270: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800274: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80800278: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080027C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800280: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800284: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80800288: nop

    // 0x8080028C: bc1f        L_808002A4
    if (!c1cs) {
        // 0x80800290: nop
    
            goto L_808002A4;
    }
    // 0x80800290: nop

    // 0x80800294: jal         0x800A04F4
    // 0x80800298: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800A04F4(rdram, ctx);
        goto after_2;
    // 0x80800298: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8080029C: b           L_808002B0
    // 0x808002A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_808002B0;
    // 0x808002A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808002A4:
    // 0x808002A4: jal         0x800A055C
    // 0x808002A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800A055C(rdram, ctx);
        goto after_3;
    // 0x808002A8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x808002AC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_808002B0:
    // 0x808002B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002B4:
    // 0x808002B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808002B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002BC: jr          $ra
    // 0x808002C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808002C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80106320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106320: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80106324: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80106328: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8010632C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80106330: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80106334: jal         0x801063C0
    // 0x80106338: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_801063C0(rdram, ctx);
        goto after_0;
    // 0x80106338: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8010633C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80106340: jal         0x800B2974
    // 0x80106344: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    vector_push_back(rdram, ctx);
        goto after_1;
    // 0x80106344: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x80106348: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8010634C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80106350: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80106354: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x80106358: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8010635C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80106360: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x80106364: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80106368: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8010636C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80106370: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x80106374: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80106378: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8010637C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80106380: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80106384: sw          $t1, 0x6ED8($at)
    MEM_W(0X6ED8, ctx->r1) = ctx->r9;
    // 0x80106388: lh          $a3, 0x6($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X6);
    // 0x8010638C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80106390: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80106394: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x80106398: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8010639C: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x801063A0: lw          $t9, 0x4440($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4440);
    // 0x801063A4: jalr        $t9
    // 0x801063A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x801063A8: nop

    after_2:
    // 0x801063AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801063B0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x801063B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801063B8: jr          $ra
    // 0x801063BC: nop

    return;
    // 0x801063BC: nop

;}
RECOMP_FUNC void _chterryegg_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086188: syscall     283
    recomp_syscall_handler(rdram, ctx, 0x80086188);
    return;
    // 0x8008618C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void bskazflamethrower_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800200: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    // 0x80800204: jal         0x80800094
    // 0x80800208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800094_bskazflamethrower(rdram, ctx);
        goto after_0;
    // 0x80800208: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080020C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800214: jr          $ra
    // 0x80800218: nop

    return;
    // 0x80800218: nop

;}
RECOMP_FUNC void func_800F6C5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6C5C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F6C64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F6C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F6C6C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F6C70: jal         0x8008E078
    // 0x800F6C74: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    player_isStable(rdram, ctx);
        goto after_0;
    // 0x800F6C74: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F6C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F6C7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F6C80: jr          $ra
    // 0x800F6C84: nop

    return;
    // 0x800F6C84: nop

;}
RECOMP_FUNC void _bskazglide_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083400: syscall     59
    recomp_syscall_handler(rdram, ctx, 0x80083400);
    return;
    // 0x80083404: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
