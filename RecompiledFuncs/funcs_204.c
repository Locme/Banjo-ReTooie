#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80800008_basetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x800EA05C
    // 0x80800014: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800018: jal         0x800EA090
    // 0x8080001C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EA090(rdram, ctx);
        goto after_1;
    // 0x8080001C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800020: jal         0x800DB9B0
    // 0x80800024: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800DB9B0(rdram, ctx);
        goto after_2;
    // 0x80800024: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800028: bne         $v0, $zero, L_80800070
    if (ctx->r2 != 0) {
        // 0x8080002C: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80800070;
    }
    // 0x8080002C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800034: addiu       $at, $zero, 0x13A
    ctx->r1 = ADD32(0, 0X13A);
    // 0x80800038: bne         $v0, $at, L_80800044
    if (ctx->r2 != ctx->r1) {
        // 0x8080003C: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_80800044;
    }
    // 0x8080003C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80800040: beq         $v1, $at, L_80800058
    if (ctx->r3 == ctx->r1) {
        // 0x80800044: addiu       $at, $zero, 0x136
        ctx->r1 = ADD32(0, 0X136);
            goto L_80800058;
    }
L_80800044:
    // 0x80800044: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
    // 0x80800048: bne         $v0, $at, L_80800070
    if (ctx->r2 != ctx->r1) {
        // 0x8080004C: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_80800070;
    }
    // 0x8080004C: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80800050: bnel        $v1, $at, L_80800074
    if (ctx->r3 != ctx->r1) {
        // 0x80800054: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800074;
    }
    goto skip_0;
    // 0x80800054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80800058:
    // 0x80800058: jal         0x800DA298
    // 0x8080005C: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x8080005C: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    after_3:
    // 0x80800060: beql        $v0, $zero, L_80800074
    if (ctx->r2 == 0) {
        // 0x80800064: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800074;
    }
    goto skip_1;
    // 0x80800064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800068: jal         0x800A0FF0
    // 0x8080006C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800A0FF0(rdram, ctx);
        goto after_4;
    // 0x8080006C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
L_80800070:
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800074:
    // 0x80800074: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void func_80800630_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800630: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800638: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080063C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800640: jal         0x800897C8
    // 0x80800644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80800644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080064C: jal         0x80100094
    // 0x80800650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800650: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800658: jal         0x8008A2B0
    // 0x8080065C: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x8080065C: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    after_2:
    // 0x80800660: beq         $v0, $zero, L_8080067C
    if (ctx->r2 == 0) {
        // 0x80800664: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080067C;
    }
    // 0x80800664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800668: jal         0x80100094
    // 0x8080066C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x8080066C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800674: jal         0x8008A2C0
    // 0x80800678: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x80800678: addiu       $a1, $v0, 0x6C
    ctx->r5 = ADD32(ctx->r2, 0X6C);
    after_4:
L_8080067C:
    // 0x8080067C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800680: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800684: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800688: jr          $ra
    // 0x8080068C: nop

    return;
    // 0x8080068C: nop

;}
RECOMP_FUNC void func_8080043C_chseaweedbaddy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080043C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800440: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800444: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800448: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8080044C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800450: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800454: lwc1        $f0, 0x38($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X38);
    // 0x80800458: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080045C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800460: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800464: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80800468: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080046C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800470: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800474: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80800478: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080047C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800480: jal         0x80089F20
    // 0x80800484: nop

    _sudeflect_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800484: nop

    after_0:
    // 0x80800488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080048C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800490: jr          $ra
    // 0x80800494: nop

    return;
    // 0x80800494: nop

;}
RECOMP_FUNC void chchuffycont_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800910: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800914: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800918: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080091C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800920: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800924: jal         0x800EA05C
    // 0x80800928: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800928: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080092C: addiu       $at, $zero, 0x121
    ctx->r1 = ADD32(0, 0X121);
    // 0x80800930: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800934: bne         $v0, $at, L_808009D8
    if (ctx->r2 != ctx->r1) {
        // 0x80800938: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_808009D8;
    }
    // 0x80800938: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080093C: jal         0x800DA298
    // 0x80800940: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800940: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_1:
    // 0x80800944: bne         $v0, $zero, L_80800968
    if (ctx->r2 != 0) {
        // 0x80800948: lui         $s0, 0x8080
        ctx->r16 = S32(RELOC_HI16(1704, 0XB20) << 16);
            goto L_80800968;
    }
    // 0x80800948: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1704, 0XB20) << 16);
    // 0x8080094C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800950: addiu       $t6, $zero, 0xD7
    ctx->r14 = ADD32(0, 0XD7);
    // 0x80800954: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80800958: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8080095C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800960: b           L_808009A8
    // 0x80800964: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
        goto L_808009A8;
    // 0x80800964: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
L_80800968:
    // 0x80800968: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1704, 0XB66) << 16);
    // 0x8080096C: addiu       $s1, $s1, 0xB66
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1704, 0XB66));
    // 0x80800970: addiu       $s0, $s0, 0xB20
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1704, 0XB20));
L_80800974:
    // 0x80800974: jal         0x800DA298
    // 0x80800978: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800978: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_2:
    // 0x8080097C: bnel        $v0, $zero, L_80800994
    if (ctx->r2 != 0) {
        // 0x80800980: lh          $t0, 0x0($s0)
        ctx->r8 = MEM_H(ctx->r16, 0X0);
            goto L_80800994;
    }
    goto skip_0;
    // 0x80800980: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    skip_0:
    // 0x80800984: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x80800988: bne         $s0, $s1, L_80800974
    if (ctx->r16 != ctx->r17) {
        // 0x8080098C: nop
    
            goto L_80800974;
    }
    // 0x8080098C: nop

    // 0x80800990: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
L_80800994:
    // 0x80800994: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80800998: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8080099C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x808009A0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x808009A4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
L_808009A8:
    // 0x808009A8: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x808009AC: jal         0x80088268
    // 0x808009B0: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x808009B0: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    after_3:
    // 0x808009B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808009B8: jal         0x80088268
    // 0x808009BC: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x808009BC: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    after_4:
    // 0x808009C0: beq         $v0, $s0, L_808009D0
    if (ctx->r2 == ctx->r16) {
        // 0x808009C4: nop
    
            goto L_808009D0;
    }
    // 0x808009C4: nop

    // 0x808009C8: jal         0x800A8230
    // 0x808009CC: nop

    func_800A8230(rdram, ctx);
        goto after_5;
    // 0x808009CC: nop

    after_5:
L_808009D0:
    // 0x808009D0: b           L_80800A64
    // 0x808009D4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80800A64;
    // 0x808009D4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_808009D8:
    // 0x808009D8: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1704, 0XB20) << 16);
    // 0x808009DC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1704, 0XB66) << 16);
    // 0x808009E0: addiu       $a0, $a0, 0xB66
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1704, 0XB66));
    // 0x808009E4: addiu       $v1, $v1, 0xB20
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(1704, 0XB20));
    // 0x808009E8: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
L_808009EC:
    // 0x808009EC: beq         $v0, $t5, L_80800A00
    if (ctx->r2 == ctx->r13) {
        // 0x808009F0: nop
    
            goto L_80800A00;
    }
    // 0x808009F0: nop

    // 0x808009F4: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x808009F8: bnel        $v1, $a0, L_808009EC
    if (ctx->r3 != ctx->r4) {
        // 0x808009FC: lh          $t5, 0x0($v1)
        ctx->r13 = MEM_H(ctx->r3, 0X0);
            goto L_808009EC;
    }
    goto skip_1;
    // 0x808009FC: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    skip_1:
L_80800A00:
    // 0x80800A00: jal         0x800DA298
    // 0x80800A04: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x80800A04: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    after_6:
    // 0x80800A08: bne         $v0, $zero, L_80800A28
    if (ctx->r2 != 0) {
        // 0x80800A0C: addiu       $at, $zero, 0xD7
        ctx->r1 = ADD32(0, 0XD7);
            goto L_80800A28;
    }
    // 0x80800A0C: addiu       $at, $zero, 0xD7
    ctx->r1 = ADD32(0, 0XD7);
    // 0x80800A10: bnel        $s1, $at, L_80800A68
    if (ctx->r17 != ctx->r1) {
        // 0x80800A14: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A68;
    }
    goto skip_2;
    // 0x80800A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80800A18: jal         0x800DA298
    // 0x80800A1C: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_800DA298(rdram, ctx);
        goto after_7;
    // 0x80800A1C: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_7:
    // 0x80800A20: bnel        $v0, $zero, L_80800A68
    if (ctx->r2 != 0) {
        // 0x80800A24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A68;
    }
    goto skip_3;
    // 0x80800A24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_80800A28:
    // 0x80800A28: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800A2C: addiu       $t6, $zero, 0x121
    ctx->r14 = ADD32(0, 0X121);
    // 0x80800A30: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800A34: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80800A38: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800A3C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80800A40: addiu       $a0, $zero, 0x121
    ctx->r4 = ADD32(0, 0X121);
    // 0x80800A44: jal         0x80088268
    // 0x80800A48: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x80800A48: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    after_8:
    // 0x80800A4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80800A50: lbu         $t0, 0x762C($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X762C);
    // 0x80800A54: beql        $v0, $t0, L_80800A68
    if (ctx->r2 == ctx->r8) {
        // 0x80800A58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800A68;
    }
    goto skip_4;
    // 0x80800A58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80800A5C: jal         0x800A8230
    // 0x80800A60: nop

    func_800A8230(rdram, ctx);
        goto after_9;
    // 0x80800A60: nop

    after_9:
L_80800A64:
    // 0x80800A64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800A68:
    // 0x80800A68: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80800A6C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800A70: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800A74: jr          $ra
    // 0x80800A78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800A78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8010FFD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FFD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010FFDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010FFE0: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
    // 0x8010FFE4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8010FFE8: beq         $a1, $zero, L_80110000
    if (ctx->r5 == 0) {
        // 0x8010FFEC: nop
    
            goto L_80110000;
    }
    // 0x8010FFEC: nop

    // 0x8010FFF0: jal         0x801150F0
    // 0x8010FFF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_801150F0(rdram, ctx);
        goto after_0;
    // 0x8010FFF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8010FFF8: b           L_80110000
    // 0x8010FFFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80110000;
    // 0x8010FFFC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80110000:
    // 0x80110000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110008: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8011000C: jr          $ra
    // 0x80110010: nop

    return;
    // 0x80110010: nop

;}
RECOMP_FUNC void func_800C9714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C971C: jal         0x800C91C8
    // 0x800C9720: nop

    func_800C91C8(rdram, ctx);
        goto after_0;
    // 0x800C9720: nop

    after_0:
    // 0x800C9724: beq         $v0, $zero, L_800C973C
    if (ctx->r2 == 0) {
        // 0x800C9728: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800C973C;
    }
    // 0x800C9728: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C972C: jal         0x800881C0
    // 0x800C9730: nop

    _gctransitionDll_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x800C9730: nop

    after_1:
    // 0x800C9734: b           L_800C9744
    // 0x800C9738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800C9744;
    // 0x800C9738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C973C:
    // 0x800C973C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C9740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9744:
    // 0x800C9744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9748: jr          $ra
    // 0x800C974C: nop

    return;
    // 0x800C974C: nop

;}
RECOMP_FUNC void func_80800410_chcanarymarycage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800410: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800418: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080041C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800420: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800424: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080042C: jal         0x80100094
    // 0x80800430: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800430: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800434: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800438: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x8080043C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800440: beq         $a3, $at, L_80800520
    if (ctx->r7 == ctx->r1) {
        // 0x80800444: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800520;
    }
    // 0x80800444: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800448: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8080044C: beq         $a3, $at, L_80800584
    if (ctx->r7 == ctx->r1) {
        // 0x80800450: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80800584;
    }
    // 0x80800450: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800454: beq         $a3, $at, L_808005C0
    if (ctx->r7 == ctx->r1) {
        // 0x80800458: addiu       $at, $zero, 0x90
        ctx->r1 = ADD32(0, 0X90);
            goto L_808005C0;
    }
    // 0x80800458: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x8080045C: beq         $a3, $at, L_80800474
    if (ctx->r7 == ctx->r1) {
        // 0x80800460: addiu       $at, $zero, 0xAB
        ctx->r1 = ADD32(0, 0XAB);
            goto L_80800474;
    }
    // 0x80800460: addiu       $at, $zero, 0xAB
    ctx->r1 = ADD32(0, 0XAB);
    // 0x80800464: beq         $a3, $at, L_808004E0
    if (ctx->r7 == ctx->r1) {
        // 0x80800468: nop
    
            goto L_808004E0;
    }
    // 0x80800468: nop

    // 0x8080046C: b           L_808005F0
    // 0x80800470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005F0;
    // 0x80800470: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800474:
    // 0x80800474: jal         0x80101080
    // 0x80800478: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80101080(rdram, ctx);
        goto after_1;
    // 0x80800478: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080047C: jal         0x80106790
    // 0x80800480: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_2;
    // 0x80800480: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800484: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800488: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080048C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800490: jal         0x800866A0
    // 0x80800494: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_3;
    // 0x80800494: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800498: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080049C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808004A0: jal         0x800866A0
    // 0x808004A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x808004A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x808004A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808004B0: jal         0x800866A0
    // 0x808004B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _chexploder_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x808004B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x808004B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004BC: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x808004C0: jal         0x80086688
    // 0x808004C4: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    _chexploder_entrypoint_6(rdram, ctx);
        goto after_6;
    // 0x808004C4: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    after_6:
    // 0x808004C8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808004CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808004D0: jal         0x8008A028
    // 0x808004D4: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    _subaddielink_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808004D4: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    after_7:
    // 0x808004D8: b           L_808005F0
    // 0x808004DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005F0;
    // 0x808004DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004E0:
    // 0x808004E0: jal         0x8008A040
    // 0x808004E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    _subaddielink_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x808004E4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_8:
    // 0x808004E8: jal         0x80101080
    // 0x808004EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80101080(rdram, ctx);
        goto after_9;
    // 0x808004EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_9:
    // 0x808004F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808004F4: jal         0x801018A4
    // 0x808004F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_801018A4(rdram, ctx);
        goto after_10;
    // 0x808004F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x808004FC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80800500: addiu       $a1, $zero, 0xAB
    ctx->r5 = ADD32(0, 0XAB);
    // 0x80800504: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800508: beql        $v0, $zero, L_808005F0
    if (ctx->r2 == 0) {
        // 0x8080050C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_808005F0;
    }
    goto skip_0;
    // 0x8080050C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80800510: jal         0x8010114C
    // 0x80800514: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_8010114C(rdram, ctx);
        goto after_11;
    // 0x80800514: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_11:
    // 0x80800518: b           L_808005F0
    // 0x8080051C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005F0;
    // 0x8080051C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800520:
    // 0x80800520: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800524: jal         0x801015D0
    // 0x80800528: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_801015D0(rdram, ctx);
        goto after_12;
    // 0x80800528: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_12:
    // 0x8080052C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800530: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800534: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800538: lhu         $t7, 0x72($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X72);
    // 0x8080053C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800540: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800544: bne         $t8, $at, L_8080055C
    if (ctx->r24 != ctx->r1) {
        // 0x80800548: nop
    
            goto L_8080055C;
    }
    // 0x80800548: nop

    // 0x8080054C: jal         0x800DF744
    // 0x80800550: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_13;
    // 0x80800550: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x80800554: b           L_80800568
    // 0x80800558: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_80800568;
    // 0x80800558: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_8080055C:
    // 0x8080055C: jal         0x800DF744
    // 0x80800560: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_14;
    // 0x80800560: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x80800564: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80800568:
    // 0x80800568: jal         0x800DF744
    // 0x8080056C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_15;
    // 0x8080056C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x80800570: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800574: jal         0x800DF744
    // 0x80800578: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_16;
    // 0x80800578: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x8080057C: b           L_808005F0
    // 0x80800580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005F0;
    // 0x80800580: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800584:
    // 0x80800584: lbu         $v0, 0x79($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X79);
    // 0x80800588: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8080058C: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x80800590: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80800594: sll         $t2, $t0, 4
    ctx->r10 = S32(ctx->r8 << 4);
    // 0x80800598: andi        $t3, $v0, 0xFF0F
    ctx->r11 = ctx->r2 & 0XFF0F;
    // 0x8080059C: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x808005A0: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x808005A4: srl         $t6, $t5, 4
    ctx->r14 = S32(U32(ctx->r13) >> 4);
    // 0x808005A8: bne         $t6, $zero, L_808005EC
    if (ctx->r14 != 0) {
        // 0x808005AC: sb          $t4, 0x79($a2)
        MEM_B(0X79, ctx->r6) = ctx->r12;
            goto L_808005EC;
    }
    // 0x808005AC: sb          $t4, 0x79($a2)
    MEM_B(0X79, ctx->r6) = ctx->r12;
    // 0x808005B0: jal         0x80800000
    // 0x808005B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800000_chcanarymarycage(rdram, ctx);
        goto after_17;
    // 0x808005B4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_17:
    // 0x808005B8: b           L_808005F0
    // 0x808005BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005F0;
    // 0x808005BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005C0:
    // 0x808005C0: jal         0x80090270
    // 0x808005C4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_80090270(rdram, ctx);
        goto after_18;
    // 0x808005C4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_18:
    // 0x808005C8: bne         $v0, $zero, L_808005EC
    if (ctx->r2 != 0) {
        // 0x808005CC: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_808005EC;
    }
    // 0x808005CC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808005D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x808005D4: jal         0x80800338
    // 0x808005D8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80800338_chcanarymarycage(rdram, ctx);
        goto after_19;
    // 0x808005D8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_19:
    // 0x808005DC: b           L_808005F0
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005F0;
    // 0x808005E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808005E4: b           L_808005F0
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005F0;
    // 0x808005E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005EC:
    // 0x808005EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005F0:
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808005F8: jr          $ra
    // 0x808005FC: nop

    return;
    // 0x808005FC: nop

;}
RECOMP_FUNC void func_8009AD14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AD14: lw          $t6, 0xC0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC0);
    // 0x8009AD18: jr          $ra
    // 0x8009AD1C: sw          $a1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r5;
    return;
    // 0x8009AD1C: sw          $a1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void func_800C718C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C718C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C7190: addiu       $v0, $v0, -0x5520
    ctx->r2 = ADD32(ctx->r2, -0X5520);
    // 0x800C7194: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C7198: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C719C: jr          $ra
    // 0x800C71A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x800C71A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C71A4: nop

    // 0x800C71A8: nop

    // 0x800C71AC: nop

;}
RECOMP_FUNC void gcdialogcamera_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800600: jal         0x8080030C
    // 0x80800604: nop

    func_8080030C_gcdialogcamera(rdram, ctx);
        goto after_0;
    // 0x80800604: nop

    after_0:
    // 0x80800608: jal         0x808005C0
    // 0x8080060C: nop

    func_808005C0_gcdialogcamera(rdram, ctx);
        goto after_1;
    // 0x8080060C: nop

    after_1:
    // 0x80800610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800618: jr          $ra
    // 0x8080061C: nop

    return;
    // 0x8080061C: nop

;}
RECOMP_FUNC void func_8080014C_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080014C: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80800150: beq         $at, $zero, L_808001CC
    if (ctx->r1 == 0) {
        // 0x80800154: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_808001CC;
    }
    // 0x80800154: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80800158: subu        $t2, $a3, $a2
    ctx->r10 = SUB32(ctx->r7, ctx->r6);
    // 0x8080015C: andi        $t6, $t2, 0x3
    ctx->r14 = ctx->r10 & 0X3;
    // 0x80800160: beq         $t6, $zero, L_80800190
    if (ctx->r14 == 0) {
        // 0x80800164: addu        $t1, $t6, $a2
        ctx->r9 = ADD32(ctx->r14, ctx->r6);
            goto L_80800190;
    }
    // 0x80800164: addu        $t1, $t6, $a2
    ctx->r9 = ADD32(ctx->r14, ctx->r6);
    // 0x80800168: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x8080016C: subu        $v1, $t7, $a2
    ctx->r3 = SUB32(ctx->r15, ctx->r6);
    // 0x80800170: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
L_80800174:
    // 0x80800174: lbu         $t8, 0x0($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X0);
    // 0x80800178: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8080017C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80800180: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80800184: bne         $t1, $v0, L_80800174
    if (ctx->r9 != ctx->r2) {
        // 0x80800188: sb          $t8, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r24;
            goto L_80800174;
    }
    // 0x80800188: sb          $t8, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r24;
    // 0x8080018C: beq         $v0, $a3, L_808001CC
    if (ctx->r2 == ctx->r7) {
        // 0x80800190: addu        $t9, $a1, $v0
        ctx->r25 = ADD32(ctx->r5, ctx->r2);
            goto L_808001CC;
    }
L_80800190:
    // 0x80800190: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x80800194: subu        $v1, $t9, $a2
    ctx->r3 = SUB32(ctx->r25, ctx->r6);
    // 0x80800198: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
L_8080019C:
    // 0x8080019C: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x808001A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x808001A4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x808001A8: sb          $t3, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r11;
    // 0x808001AC: lbu         $t4, 0x1($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X1);
    // 0x808001B0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x808001B4: sb          $t4, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r12;
    // 0x808001B8: lbu         $t5, -0x2($t0)
    ctx->r13 = MEM_BU(ctx->r8, -0X2);
    // 0x808001BC: sb          $t5, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r13;
    // 0x808001C0: lbu         $t6, -0x1($t0)
    ctx->r14 = MEM_BU(ctx->r8, -0X1);
    // 0x808001C4: bne         $v0, $a3, L_8080019C
    if (ctx->r2 != ctx->r7) {
        // 0x808001C8: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_8080019C;
    }
    // 0x808001C8: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
L_808001CC:
    // 0x808001CC: jr          $ra
    // 0x808001D0: nop

    return;
    // 0x808001D0: nop

;}
RECOMP_FUNC void func_800F0D50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0D50: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x800F0D54: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800F0D58: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F0D5C: bc1fl       L_800F0D70
    if (!c1cs) {
        // 0x800F0D60: c.lt.s      $f4, $f12
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
            goto L_800F0D70;
    }
    goto skip_0;
    // 0x800F0D60: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    skip_0:
    // 0x800F0D64: jr          $ra
    // 0x800F0D68: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    return;
    // 0x800F0D68: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x800F0D6C: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
L_800F0D70:
    // 0x800F0D70: nop

    // 0x800F0D74: bc1fl       L_800F0D88
    if (!c1cs) {
        // 0x800F0D78: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800F0D88;
    }
    goto skip_1;
    // 0x800F0D78: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_1:
    // 0x800F0D7C: jr          $ra
    // 0x800F0D80: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    return;
    // 0x800F0D80: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    // 0x800F0D84: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800F0D88:
    // 0x800F0D88: jr          $ra
    // 0x800F0D8C: nop

    return;
    // 0x800F0D8C: nop

;}
RECOMP_FUNC void baeggcursor_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080018C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800190: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800194: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800198: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x8080019C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001A4: lbu         $v1, 0x9($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X9);
    // 0x808001A8: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x808001AC: beql        $v1, $zero, L_808001D4
    if (ctx->r3 == 0) {
        // 0x808001B0: sb          $zero, 0x8($v0)
        MEM_B(0X8, ctx->r2) = 0;
            goto L_808001D4;
    }
    goto skip_0;
    // 0x808001B0: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
    skip_0:
    // 0x808001B4: beq         $v1, $at, L_808001E8
    if (ctx->r3 == ctx->r1) {
        // 0x808001B8: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_808001E8;
    }
    // 0x808001B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808001BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808001C0: beq         $v1, $at, L_80800200
    if (ctx->r3 == ctx->r1) {
        // 0x808001C4: addiu       $t1, $zero, 0x78
        ctx->r9 = ADD32(0, 0X78);
            goto L_80800200;
    }
    // 0x808001C4: addiu       $t1, $zero, 0x78
    ctx->r9 = ADD32(0, 0X78);
    // 0x808001C8: b           L_8080020C
    // 0x808001CC: sltiu       $at, $a1, 0x6
    ctx->r1 = ctx->r5 < 0X6 ? 1 : 0;
        goto L_8080020C;
    // 0x808001CC: sltiu       $at, $a1, 0x6
    ctx->r1 = ctx->r5 < 0X6 ? 1 : 0;
    // 0x808001D0: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
L_808001D4:
    // 0x808001D4: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x808001D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808001DC: sb          $t6, 0xA($t7)
    MEM_B(0XA, ctx->r15) = ctx->r14;
    // 0x808001E0: b           L_80800208
    // 0x808001E4: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
        goto L_80800208;
    // 0x808001E4: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
L_808001E8:
    // 0x808001E8: sb          $t8, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r24;
    // 0x808001EC: lw          $t0, 0x68($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X68);
    // 0x808001F0: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x808001F4: sw          $t9, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r25;
    // 0x808001F8: b           L_80800208
    // 0x808001FC: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
        goto L_80800208;
    // 0x808001FC: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
L_80800200:
    // 0x80800200: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
    // 0x80800204: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
L_80800208:
    // 0x80800208: sltiu       $at, $a1, 0x6
    ctx->r1 = ctx->r5 < 0X6 ? 1 : 0;
L_8080020C:
    // 0x8080020C: beq         $at, $zero, L_80800314
    if (ctx->r1 == 0) {
        // 0x80800210: sb          $a1, 0x9($v0)
        MEM_B(0X9, ctx->r2) = ctx->r5;
            goto L_80800314;
    }
    // 0x80800210: sb          $a1, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r5;
    // 0x80800214: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(512, 0X640) << 16);
    // 0x80800218: addu        $at, $at, $t2
    gpr jr_addend_80800220 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8080021C: lw          $t2, 0x640($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(512, 0X640));
    // 0x80800220: jr          $t2
    // 0x80800224: nop

    switch (jr_addend_80800220 >> 2) {
        case 0: goto L_80800228; break;
        case 1: goto L_80800228; break;
        case 2: goto L_80800250; break;
        case 3: goto L_80800280; break;
        case 4: goto L_808002CC; break;
        case 5: goto L_808002F0; break;
        default: switch_error(__func__, 0x80800220, 0x80800640);
    }
    // 0x80800224: nop

L_80800228:
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080022C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800230: jal         0x8009ADF0
    // 0x80800234: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009ADF0(rdram, ctx);
        goto after_0;
    // 0x80800234: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80800238: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x8080023C: lbu         $t3, 0x8($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X8);
    // 0x80800240: beql        $t3, $zero, L_80800318
    if (ctx->r11 == 0) {
        // 0x80800244: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800318;
    }
    goto skip_1;
    // 0x80800244: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800248: b           L_80800314
    // 0x8080024C: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
        goto L_80800314;
    // 0x8080024C: sb          $zero, 0x8($v0)
    MEM_B(0X8, ctx->r2) = 0;
L_80800250:
    // 0x80800250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800254: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800258: jal         0x8009ADF0
    // 0x8080025C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_1;
    // 0x8080025C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80800260: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800264: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800268: lw          $t4, 0x68($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X68);
    // 0x8080026C: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x80800270: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
    // 0x80800274: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
    // 0x80800278: b           L_80800314
    // 0x8080027C: sw          $t5, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r13;
        goto L_80800314;
    // 0x8080027C: sw          $t5, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r13;
L_80800280:
    // 0x80800280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800284: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80800288: jal         0x8009ADF0
    // 0x8080028C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_2;
    // 0x8080028C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80800290: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(512, 0X658) << 16);
    // 0x80800294: lwc1        $f6, 0x658($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(512, 0X658));
    // 0x80800298: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002A0: lui         $a1, 0x4318
    ctx->r5 = S32(0X4318 << 16);
    // 0x808002A4: lui         $a2, 0x42E4
    ctx->r6 = S32(0X42E4 << 16);
    // 0x808002A8: jal         0x808003A4
    // 0x808002AC: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    baeggcursor_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x808002AC: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    after_3:
    // 0x808002B0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x808002B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002B8: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    // 0x808002BC: swc1        $f8, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->f8.u32l;
    // 0x808002C0: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x808002C4: b           L_80800314
    // 0x808002C8: sw          $zero, 0x14($t9)
    MEM_W(0X14, ctx->r25) = 0;
        goto L_80800314;
    // 0x808002C8: sw          $zero, 0x14($t9)
    MEM_W(0X14, ctx->r25) = 0;
L_808002CC:
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808002D4: jal         0x8009ADF0
    // 0x808002D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_4;
    // 0x808002D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x808002DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(512, 0X65C) << 16);
    // 0x808002E0: lwc1        $f10, 0x65C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(512, 0X65C));
    // 0x808002E4: lw          $t0, 0x68($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X68);
    // 0x808002E8: b           L_80800314
    // 0x808002EC: swc1        $f10, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f10.u32l;
        goto L_80800314;
    // 0x808002EC: swc1        $f10, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f10.u32l;
L_808002F0:
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808002F8: jal         0x8009ADF0
    // 0x808002FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009ADF0(rdram, ctx);
        goto after_5;
    // 0x808002FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80800300: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800304: lw          $t1, 0x68($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X68);
    // 0x80800308: swc1        $f16, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->f16.u32l;
    // 0x8080030C: lw          $t2, 0x68($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X68);
    // 0x80800310: sb          $zero, 0x10($t2)
    MEM_B(0X10, ctx->r10) = 0;
L_80800314:
    // 0x80800314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800318:
    // 0x80800318: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080031C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800320: jr          $ra
    // 0x80800324: nop

    return;
    // 0x80800324: nop

;}
RECOMP_FUNC void func_80800194_cheggnormal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800194: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800198: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080019C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001A4: jal         0x80100094
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808001A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808001AC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808001B0: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x808001B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808001B8: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x808001BC: beq         $t6, $at, L_808001D4
    if (ctx->r14 == ctx->r1) {
        // 0x808001C0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808001D4;
    }
    // 0x808001C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808001C4: beq         $t6, $at, L_80800234
    if (ctx->r14 == ctx->r1) {
        // 0x808001C8: nop
    
            goto L_80800234;
    }
    // 0x808001C8: nop

    // 0x808001CC: b           L_808002DC
    // 0x808001D0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_808002DC;
    // 0x808001D0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_808001D4:
    // 0x808001D4: jal         0x8008A3B8
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808001DC: bnel        $v0, $zero, L_808002DC
    if (ctx->r2 != 0) {
        // 0x808001E0: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_808002DC;
    }
    goto skip_0;
    // 0x808001E0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808001E4: jal         0x800EEEA8
    // 0x808001E8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EEEA8(rdram, ctx);
        goto after_2;
    // 0x808001E8: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_2:
    // 0x808001EC: beq         $v0, $zero, L_80800204
    if (ctx->r2 == 0) {
        // 0x808001F0: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_80800204;
    }
    // 0x808001F0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808001F4: lbu         $t9, 0x39($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X39);
    // 0x808001F8: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x808001FC: b           L_808002D8
    // 0x80800200: sb          $t0, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r8;
        goto L_808002D8;
    // 0x80800200: sb          $t0, 0x39($t7)
    MEM_B(0X39, ctx->r15) = ctx->r8;
L_80800204:
    // 0x80800204: jal         0x80800000
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_cheggnormal(rdram, ctx);
        goto after_3;
    // 0x80800208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080020C: jal         0x8008A3F8
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_4;
    // 0x80800210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800214: jal         0x8008A3E8
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_14(rdram, ctx);
        goto after_5;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080021C: beq         $v0, $zero, L_808002D8
    if (ctx->r2 == 0) {
        // 0x80800220: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_808002D8;
    }
    // 0x80800220: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80800224: lbu         $t3, 0x39($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X39);
    // 0x80800228: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x8080022C: b           L_808002D8
    // 0x80800230: sb          $t4, 0x39($t1)
    MEM_B(0X39, ctx->r9) = ctx->r12;
        goto L_808002D8;
    // 0x80800230: sb          $t4, 0x39($t1)
    MEM_B(0X39, ctx->r9) = ctx->r12;
L_80800234:
    // 0x80800234: jal         0x8008A3B8
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080023C: bne         $v0, $zero, L_808002D8
    if (ctx->r2 != 0) {
        // 0x80800240: lw          $t5, 0x2C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X2C);
            goto L_808002D8;
    }
    // 0x80800240: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80800244: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80800248: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080024C: lwc1        $f12, 0x30($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X30);
    // 0x80800250: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800254: lui         $a2, 0x3E09
    ctx->r6 = S32(0X3E09 << 16);
    // 0x80800258: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8080025C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800260: ori         $a2, $a2, 0x374C
    ctx->r6 = ctx->r6 | 0X374C;
    // 0x80800264: jal         0x800F10B4
    // 0x80800268: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_7;
    // 0x80800268: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x8080026C: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80800270: jal         0x8008A450
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmove_entrypoint_3(rdram, ctx);
        goto after_8;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800278: beq         $v0, $zero, L_80800288
    if (ctx->r2 == 0) {
        // 0x8080027C: nop
    
            goto L_80800288;
    }
    // 0x8080027C: nop

    // 0x80800280: jal         0x8008A430
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_23(rdram, ctx);
        goto after_9;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_80800288:
    // 0x80800288: jal         0x8008A3E0
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_13(rdram, ctx);
        goto after_10;
    // 0x8080028C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800290: beq         $v0, $zero, L_808002A8
    if (ctx->r2 == 0) {
        // 0x80800294: lw          $t6, 0x2C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X2C);
            goto L_808002A8;
    }
    // 0x80800294: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800298: lbu         $t9, 0x39($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X39);
    // 0x8080029C: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x808002A0: b           L_808002D8
    // 0x808002A4: sb          $t0, 0x39($t6)
    MEM_B(0X39, ctx->r14) = ctx->r8;
        goto L_808002D8;
    // 0x808002A4: sb          $t0, 0x39($t6)
    MEM_B(0X39, ctx->r14) = ctx->r8;
L_808002A8:
    // 0x808002A8: jal         0x8008A3D8
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_12(rdram, ctx);
        goto after_11;
    // 0x808002AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808002B0: beq         $v0, $zero, L_808002C8
    if (ctx->r2 == 0) {
        // 0x808002B4: nop
    
            goto L_808002C8;
    }
    // 0x808002B4: nop

    // 0x808002B8: jal         0x8008A348
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sueggmisc_entrypoint_1(rdram, ctx);
        goto after_12;
    // 0x808002BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808002C0: b           L_808002DC
    // 0x808002C4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_808002DC;
    // 0x808002C4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_808002C8:
    // 0x808002C8: jal         0x80800000
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800000_cheggnormal(rdram, ctx);
        goto after_13;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808002D0: jal         0x8008A3F8
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_14;
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_808002D8:
    // 0x808002D8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_808002DC:
    // 0x808002DC: lb          $t3, 0x39($t7)
    ctx->r11 = MEM_B(ctx->r15, 0X39);
    // 0x808002E0: bgezl       $t3, L_808002F4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x808002E4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808002F4;
    }
    goto skip_1;
    // 0x808002E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x808002E8: jal         0x8008A390
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x808002EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808002F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002F4:
    // 0x808002F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002FC: jr          $ra
    // 0x80800300: nop

    return;
    // 0x80800300: nop

;}
RECOMP_FUNC void _scinfobar_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A598: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A598);
    return;
    // 0x8008A59C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void capod_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080026C: jal         0x8008FFE8
    // 0x80800270: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x80800270: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800274: jal         0x80110024
    // 0x80800278: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_1;
    // 0x80800278: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080027C: beq         $v0, $zero, L_80800290
    if (ctx->r2 == 0) {
        // 0x80800280: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800290;
    }
    // 0x80800280: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800284: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800288: jal         0x80089570
    // 0x8080028C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    _ncpod_entrypoint_22(rdram, ctx);
        goto after_2;
    // 0x8080028C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_80800290:
    // 0x80800290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800298: jr          $ra
    // 0x8080029C: nop

    return;
    // 0x8080029C: nop

;}
RECOMP_FUNC void chdiggerbossbattery_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1496, 0X2F0) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x2F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1496, 0X2F0));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x2F0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1496, 0X2F0));
;}
RECOMP_FUNC void susplinet_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x808002B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808002B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808002BC: jal         0x80800184
    // 0x808002C0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    susplinet_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808002C0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x808002C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808002C8: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x808002CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808002D0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x808002D4: nop

    // 0x808002D8: bc1fl       L_808002E8
    if (!c1cs) {
        // 0x808002DC: lw          $t6, 0x54($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X54);
            goto L_808002E8;
    }
    goto skip_0;
    // 0x808002DC: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    skip_0:
    // 0x808002E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808002E4: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
L_808002E8:
    // 0x808002E8: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x808002EC: beql        $t7, $zero, L_80800328
    if (ctx->r15 == 0) {
        // 0x808002F0: swc1        $f12, 0x44($a0)
        MEM_W(0X44, ctx->r4) = ctx->f12.u32l;
            goto L_80800328;
    }
    goto skip_1;
    // 0x808002F0: swc1        $f12, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f12.u32l;
    skip_1:
    // 0x808002F4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x808002F8: nop

    // 0x808002FC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800300: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80800304: nop

    // 0x80800308: bc1fl       L_80800328
    if (!c1cs) {
        // 0x8080030C: swc1        $f12, 0x44($a0)
        MEM_W(0X44, ctx->r4) = ctx->f12.u32l;
            goto L_80800328;
    }
    goto skip_2;
    // 0x8080030C: swc1        $f12, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f12.u32l;
    skip_2:
    // 0x80800310: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
L_80800314:
    // 0x80800314: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80800318: nop

    // 0x8080031C: bc1tl       L_80800314
    if (c1cs) {
        // 0x80800320: sub.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_80800314;
    }
    goto skip_3;
    // 0x80800320: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    skip_3:
    // 0x80800324: swc1        $f12, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f12.u32l;
L_80800328:
    // 0x80800328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080032C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800330: jr          $ra
    // 0x80800334: nop

    return;
    // 0x80800334: nop

;}
RECOMP_FUNC void gldbstring_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (tooie_pause_settings_text(rdram, ctx)) return;
    // 0x8080003C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800044: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080004C: jal         0x80088730
    // 0x80800050: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    _gldialog_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800050: sh          $a1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800054: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x80800058: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8080005C: lh          $a2, 0x1E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X1E);
    // 0x80800060: addu        $a3, $t2, $t7
    ctx->r7 = ADD32(ctx->r10, ctx->r15);
    // 0x80800064: lbu         $t8, 0x1($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X1);
    // 0x80800068: lbu         $a0, 0x0($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X0);
    // 0x8080006C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800070: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80800074: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80800078: addu        $v1, $t2, $a0
    ctx->r3 = ADD32(ctx->r10, ctx->r4);
    // 0x8080007C: lbu         $t0, -0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, -0X1);
    // 0x80800080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800084: blez        $t0, L_8080014C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80800088: andi        $v0, $t0, 0x3
        ctx->r2 = ctx->r8 & 0X3;
            goto L_8080014C;
    }
    // 0x80800088: andi        $v0, $t0, 0x3
    ctx->r2 = ctx->r8 & 0X3;
    // 0x8080008C: beq         $v0, $zero, L_808000C4
    if (ctx->r2 == 0) {
        // 0x80800090: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_808000C4;
    }
    // 0x80800090: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_80800094:
    // 0x80800094: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80800098: addiu       $t3, $a2, 0x80
    ctx->r11 = ADD32(ctx->r6, 0X80);
    // 0x8080009C: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x808000A0: bne         $t3, $v0, L_808000B0
    if (ctx->r11 != ctx->r2) {
        // 0x808000A4: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_808000B0;
    }
    // 0x808000A4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x808000A8: b           L_80800150
    // 0x808000AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800150;
    // 0x808000AC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808000B0:
    // 0x808000B0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x808000B4: bne         $a3, $a1, L_80800094
    if (ctx->r7 != ctx->r5) {
        // 0x808000B8: addu        $v1, $v1, $a0
        ctx->r3 = ADD32(ctx->r3, ctx->r4);
            goto L_80800094;
    }
    // 0x808000B8: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x808000BC: beql        $a1, $t0, L_80800150
    if (ctx->r5 == ctx->r8) {
        // 0x808000C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800150;
    }
    goto skip_0;
    // 0x808000C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_808000C4:
    // 0x808000C4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x808000C8: addiu       $t4, $a2, 0x80
    ctx->r12 = ADD32(ctx->r6, 0X80);
    // 0x808000CC: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x808000D0: bne         $t4, $v0, L_808000E0
    if (ctx->r12 != ctx->r2) {
        // 0x808000D4: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_808000E0;
    }
    // 0x808000D4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x808000D8: b           L_80800150
    // 0x808000DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800150;
    // 0x808000DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_808000E0:
    // 0x808000E0: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x808000E4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x808000E8: addiu       $t5, $a2, 0x80
    ctx->r13 = ADD32(ctx->r6, 0X80);
    // 0x808000EC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x808000F0: bne         $t5, $v0, L_80800100
    if (ctx->r13 != ctx->r2) {
        // 0x808000F4: lbu         $a0, -0x1($v1)
        ctx->r4 = MEM_BU(ctx->r3, -0X1);
            goto L_80800100;
    }
    // 0x808000F4: lbu         $a0, -0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, -0X1);
    // 0x808000F8: b           L_80800150
    // 0x808000FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800150;
    // 0x808000FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800100:
    // 0x80800100: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80800104: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80800108: addiu       $t6, $a2, 0x80
    ctx->r14 = ADD32(ctx->r6, 0X80);
    // 0x8080010C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800110: bne         $t6, $v0, L_80800120
    if (ctx->r14 != ctx->r2) {
        // 0x80800114: lbu         $a0, -0x1($v1)
        ctx->r4 = MEM_BU(ctx->r3, -0X1);
            goto L_80800120;
    }
    // 0x80800114: lbu         $a0, -0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, -0X1);
    // 0x80800118: b           L_80800150
    // 0x8080011C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800150;
    // 0x8080011C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800120:
    // 0x80800120: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80800124: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80800128: addiu       $t7, $a2, 0x80
    ctx->r15 = ADD32(ctx->r6, 0X80);
    // 0x8080012C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80800130: bne         $t7, $v0, L_80800140
    if (ctx->r15 != ctx->r2) {
        // 0x80800134: lbu         $a0, -0x1($v1)
        ctx->r4 = MEM_BU(ctx->r3, -0X1);
            goto L_80800140;
    }
    // 0x80800134: lbu         $a0, -0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, -0X1);
    // 0x80800138: b           L_80800150
    // 0x8080013C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80800150;
    // 0x8080013C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800140:
    // 0x80800140: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800144: bne         $a1, $t0, L_808000C4
    if (ctx->r5 != ctx->r8) {
        // 0x80800148: addu        $v1, $v1, $a0
        ctx->r3 = ADD32(ctx->r3, ctx->r4);
            goto L_808000C4;
    }
    // 0x80800148: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
L_8080014C:
    // 0x8080014C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800150:
    // 0x80800150: jr          $ra
    // 0x80800154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800D2054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D2054: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D2058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D205C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D2060: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D2064: jal         0x800D1FC0
    // 0x800D2068: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D1FC0(rdram, ctx);
        goto after_0;
    // 0x800D2068: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800D206C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D2070: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x800D2074: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800D2078: bne         $v1, $zero, L_800D2088
    if (ctx->r3 != 0) {
        // 0x800D207C: nop
    
            goto L_800D2088;
    }
    // 0x800D207C: nop

    // 0x800D2080: b           L_800D20D0
    // 0x800D2084: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800D20D0;
    // 0x800D2084: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800D2088:
    // 0x800D2088: beq         $a0, $zero, L_800D20A4
    if (ctx->r4 == 0) {
        // 0x800D208C: lw          $t6, 0x30($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X30);
            goto L_800D20A4;
    }
    // 0x800D208C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800D2090: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D2094: beq         $a0, $at, L_800D20AC
    if (ctx->r4 == ctx->r1) {
        // 0x800D2098: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_800D20AC;
    }
    // 0x800D2098: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800D209C: b           L_800D20B0
    // 0x800D20A0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_800D20B0;
    // 0x800D20A0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800D20A4:
    // 0x800D20A4: b           L_800D20B0
    // 0x800D20A8: subu        $a0, $t6, $v1
    ctx->r4 = SUB32(ctx->r14, ctx->r3);
        goto L_800D20B0;
    // 0x800D20A8: subu        $a0, $t6, $v1
    ctx->r4 = SUB32(ctx->r14, ctx->r3);
L_800D20AC:
    // 0x800D20AC: subu        $a0, $v1, $t7
    ctx->r4 = SUB32(ctx->r3, ctx->r15);
L_800D20B0:
    // 0x800D20B0: bgtz        $a0, L_800D20D0
    if (SIGNED(ctx->r4) > 0) {
        // 0x800D20B4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800D20D0;
    }
    // 0x800D20B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800D20B8: beq         $a0, $zero, L_800D20C8
    if (ctx->r4 == 0) {
        // 0x800D20BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D20C8;
    }
    // 0x800D20BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D20C0: b           L_800D20D0
    // 0x800D20C4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_800D20D0;
    // 0x800D20C4: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800D20C8:
    // 0x800D20C8: b           L_800D20D0
    // 0x800D20CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800D20D0;
    // 0x800D20CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D20D0:
    // 0x800D20D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D20D4: bnel        $v1, $at, L_800D210C
    if (ctx->r3 != ctx->r1) {
        // 0x800D20D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D210C;
    }
    goto skip_0;
    // 0x800D20D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D20DC: jal         0x800D395C
    // 0x800D20E0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800D395C(rdram, ctx);
        goto after_1;
    // 0x800D20E0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x800D20E4: beq         $v0, $zero, L_800D20FC
    if (ctx->r2 == 0) {
        // 0x800D20E8: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_800D20FC;
    }
    // 0x800D20E8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800D20EC: addiu       $a0, $zero, 0xD54
    ctx->r4 = ADD32(0, 0XD54);
    // 0x800D20F0: jal         0x800DA544
    // 0x800D20F4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x800D20F4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x800D20F8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_800D20FC:
    // 0x800D20FC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800D2100: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800D2104: sh          $t8, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r24;
    // 0x800D2108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D210C:
    // 0x800D210C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D2110: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800D2114: jr          $ra
    // 0x800D2118: nop

    return;
    // 0x800D2118: nop

;}
RECOMP_FUNC void func_8008E1A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E1A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008E1A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008E1A8: jal         0x80096694
    // 0x8008E1AC: nop

    func_80096694(rdram, ctx);
        goto after_0;
    // 0x8008E1AC: nop

    after_0:
    // 0x8008E1B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008E1B4: xori        $t6, $v0, 0x18
    ctx->r14 = ctx->r2 ^ 0X18;
    // 0x8008E1B8: sltiu       $v0, $t6, 0x1
    ctx->r2 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x8008E1BC: jr          $ra
    // 0x8008E1C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008E1C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80802070_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802074: beq         $a1, $zero, L_808020A0
    if (ctx->r5 == 0) {
        // 0x80802078: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_808020A0;
    }
    // 0x80802078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080207C: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x80802080: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80802084: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80802088: beql        $t7, $at, L_808020C0
    if (ctx->r15 == ctx->r1) {
        // 0x8080208C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808020C0;
    }
    goto skip_0;
    // 0x8080208C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802090: jal         0x80102424
    // 0x80802094: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x80802094: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80802098: b           L_808020C0
    // 0x8080209C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808020C0;
    // 0x8080209C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808020A0:
    // 0x808020A0: lhu         $t8, 0x72($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X72);
    // 0x808020A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808020A8: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808020AC: bnel        $t9, $at, L_808020C0
    if (ctx->r25 != ctx->r1) {
        // 0x808020B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808020C0;
    }
    goto skip_1;
    // 0x808020B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x808020B4: jal         0x80102424
    // 0x808020B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x808020B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x808020BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808020C0:
    // 0x808020C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808020C4: jr          $ra
    // 0x808020C8: nop

    return;
    // 0x808020C8: nop

;}
RECOMP_FUNC void func_80800720_bstnt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800728: lbu         $t6, 0x169($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X169);
    // 0x8080072C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80800730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800734: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80800738: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8080073C: jal         0x800F0E00
    // 0x80800740: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_800F0E00(rdram, ctx);
        goto after_0;
    // 0x80800740: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x80800744: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80800748: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8080074C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800750: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800754: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80800758: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8080075C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80800760: nop

    // 0x80800764: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800768: beql        $t9, $zero, L_808007B8
    if (ctx->r25 == 0) {
        // 0x8080076C: mfc1        $t9, $f6
        ctx->r25 = (int32_t)ctx->f6.u32l;
            goto L_808007B8;
    }
    goto skip_0;
    // 0x8080076C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x80800770: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800774: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80800778: sub.s       $f6, $f0, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8080077C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80800780: nop

    // 0x80800784: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80800788: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8080078C: nop

    // 0x80800790: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80800794: bne         $t9, $zero, L_808007AC
    if (ctx->r25 != 0) {
        // 0x80800798: nop
    
            goto L_808007AC;
    }
    // 0x80800798: nop

    // 0x8080079C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x808007A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x808007A4: b           L_808007C4
    // 0x808007A8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_808007C4;
    // 0x808007A8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_808007AC:
    // 0x808007AC: b           L_808007C4
    // 0x808007B0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_808007C4;
    // 0x808007B0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x808007B4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
L_808007B8:
    // 0x808007B8: nop

    // 0x808007BC: bltz        $t9, L_808007AC
    if (SIGNED(ctx->r25) < 0) {
        // 0x808007C0: nop
    
            goto L_808007AC;
    }
    // 0x808007C0: nop

L_808007C4:
    // 0x808007C4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x808007C8: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x808007CC: bne         $t0, $zero, L_808007DC
    if (ctx->r8 != 0) {
        // 0x808007D0: sb          $t9, 0x169($a0)
        MEM_B(0X169, ctx->r4) = ctx->r25;
            goto L_808007DC;
    }
    // 0x808007D0: sb          $t9, 0x169($a0)
    MEM_B(0X169, ctx->r4) = ctx->r25;
    // 0x808007D4: jal         0x808006EC
    // 0x808007D8: nop

    func_808006EC_bstnt(rdram, ctx);
        goto after_1;
    // 0x808007D8: nop

    after_1:
L_808007DC:
    // 0x808007DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808007E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808007E4: jr          $ra
    // 0x808007E8: nop

    return;
    // 0x808007E8: nop

;}
RECOMP_FUNC void chlilterry_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1068, 0XC8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1068, 0XC8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xC8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1068, 0XC8));
;}
RECOMP_FUNC void func_80800608_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800608: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8080060C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800610: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800614: jal         0x800F54E4
    // 0x80800618: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800618: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080061C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800620: jal         0x800F5BF0
    // 0x80800624: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800F5BF0(rdram, ctx);
        goto after_1;
    // 0x80800624: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80800628: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8080062C: jal         0x800EE7F8
    // 0x80800630: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800630: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x80800634: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80800638: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080063C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800640: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800644: jal         0x800DC178
    // 0x80800648: nop

    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x80800648: nop

    after_3:
    // 0x8080064C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1528, 0XE70) << 16);
    // 0x80800650: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80800654: lwc1        $f10, 0xE70($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1528, 0XE70));
    // 0x80800658: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8080065C: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80800660: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80800664: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800668: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080066C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800670: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800674: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80800678: jal         0x800DC178
    // 0x8080067C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x8080067C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x80800680: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80800684: addiu       $a0, $zero, 0x4FD
    ctx->r4 = ADD32(0, 0X4FD);
    // 0x80800688: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8080068C: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80800690: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800694: addiu       $a3, $sp, 0x50
    ctx->r7 = ADD32(ctx->r29, 0X50);
    // 0x80800698: jal         0x80108528
    // 0x8080069C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    func_80108528(rdram, ctx);
        goto after_5;
    // 0x8080069C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x808006A0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x808006A4: lbu         $t2, 0x65($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X65);
    // 0x808006A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1528, 0XE74) << 16);
    // 0x808006AC: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x808006B0: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x808006B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006B8: sll         $t8, $t7, 11
    ctx->r24 = S32(ctx->r15 << 11);
    // 0x808006BC: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x808006C0: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x808006C4: andi        $t1, $t0, 0x10
    ctx->r9 = ctx->r8 & 0X10;
    // 0x808006C8: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x808006CC: sb          $t4, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r12;
    // 0x808006D0: lwc1        $f12, 0xE74($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1528, 0XE74));
    // 0x808006D4: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x808006D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808006DC: jal         0x800DC178
    // 0x808006E0: nop

    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808006E0: nop

    after_6:
    // 0x808006E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808006E8: jal         0x80102FDC
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_7;
    // 0x808006EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808006F0: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x808006F4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808006F8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808006FC: jal         0x800EFB24
    // 0x80800700: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_8;
    // 0x80800700: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_8:
    // 0x80800704: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1528, 0XE78) << 16);
    // 0x80800708: lwc1        $f12, 0xE78($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1528, 0XE78));
    // 0x8080070C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1528, 0XE7C) << 16);
    // 0x80800710: jal         0x800DC178
    // 0x80800714: lwc1        $f14, 0xE7C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1528, 0XE7C));
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80800714: lwc1        $f14, 0xE7C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1528, 0XE7C));
    after_9:
    // 0x80800718: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080071C: jal         0x800EF368
    // 0x80800720: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800EF368(rdram, ctx);
        goto after_10;
    // 0x80800720: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_10:
    // 0x80800724: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800728: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8080072C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800730: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800734: jal         0x800DC178
    // 0x80800738: nop

    func_800DC178(rdram, ctx);
        goto after_11;
    // 0x80800738: nop

    after_11:
    // 0x8080073C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80800740: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800744: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800748: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8080074C: jal         0x800DC178
    // 0x80800750: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800DC178(rdram, ctx);
        goto after_12;
    // 0x80800750: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x80800754: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80800758: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8080075C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800760: jal         0x800EFA4C
    // 0x80800764: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_13;
    // 0x80800764: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_13:
    // 0x80800768: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8080076C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800770: addiu       $a3, $zero, 0x815
    ctx->r7 = ADD32(0, 0X815);
    // 0x80800774: lw          $t6, 0x64($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X64);
    // 0x80800778: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x8080077C: bgez        $t8, L_8080078C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800780: nop
    
            goto L_8080078C;
    }
    // 0x80800780: nop

    // 0x80800784: b           L_8080078C
    // 0x80800788: addiu       $a3, $zero, 0x814
    ctx->r7 = ADD32(0, 0X814);
        goto L_8080078C;
    // 0x80800788: addiu       $a3, $zero, 0x814
    ctx->r7 = ADD32(0, 0X814);
L_8080078C:
    // 0x8080078C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800790: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    // 0x80800794: jal         0x80103140
    // 0x80800798: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    func_80103140(rdram, ctx);
        goto after_14;
    // 0x80800798: lhu         $a2, 0x16($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X16);
    after_14:
    // 0x8080079C: lw          $t0, 0x64($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X64);
    // 0x808007A0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1528, 0XE80) << 16);
    // 0x808007A4: addiu       $a3, $a3, 0xE80
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1528, 0XE80));
    // 0x808007A8: sll         $t1, $t0, 11
    ctx->r9 = S32(ctx->r8 << 11);
    // 0x808007AC: bgez        $t1, L_808007C0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x808007B0: nop
    
            goto L_808007C0;
    }
    // 0x808007B0: nop

    // 0x808007B4: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1528, 0XE94) << 16);
    // 0x808007B8: b           L_808007C0
    // 0x808007BC: addiu       $a3, $a3, 0xE94
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1528, 0XE94));
        goto L_808007C0;
    // 0x808007BC: addiu       $a3, $a3, 0xE94
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1528, 0XE94));
L_808007C0:
    // 0x808007C0: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x808007C4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x808007C8: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x808007CC: andi        $t3, $a1, 0x1
    ctx->r11 = ctx->r5 & 0X1;
    // 0x808007D0: jal         0x8010D930
    // 0x808007D4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    func_8010D930(rdram, ctx);
        goto after_15;
    // 0x808007D4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_15:
    // 0x808007D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808007DC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x808007E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808007E4: jr          $ra
    // 0x808007E8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x808007E8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _chfactorytoxicpools_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086270: syscall     295
    recomp_syscall_handler(rdram, ctx, 0x80086270);
    return;
    // 0x80086274: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void babee_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: jr          $ra
    // 0x80800004: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    return;
    // 0x80800004: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800140_sumultiscore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800140: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80800144: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80800148: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8080014C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800150: blez        $a3, L_80800208
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80800154: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80800208;
    }
    // 0x80800154: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800158: andi        $a1, $a3, 0x1
    ctx->r5 = ctx->r7 & 0X1;
    // 0x8080015C: beq         $a1, $zero, L_80800174
    if (ctx->r5 == 0) {
        // 0x80800160: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80800174;
    }
    // 0x80800160: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800164: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800168: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8080016C: beq         $v1, $a3, L_80800208
    if (ctx->r3 == ctx->r7) {
        // 0x80800170: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80800208;
    }
    // 0x80800170: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800174:
    // 0x80800174: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x80800178: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8080017C: addu        $t1, $t6, $a2
    ctx->r9 = ADD32(ctx->r14, ctx->r6);
    // 0x80800180: addu        $t0, $a2, $a1
    ctx->r8 = ADD32(ctx->r6, ctx->r5);
L_80800184:
    // 0x80800184: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80800188: bne         $at, $zero, L_808001B8
    if (ctx->r1 != 0) {
        // 0x8080018C: addu        $v1, $a0, $a1
        ctx->r3 = ADD32(ctx->r4, ctx->r5);
            goto L_808001B8;
    }
    // 0x8080018C: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x80800190: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80800194: lw          $t8, -0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, -0X4);
    // 0x80800198: bnel        $t7, $t8, L_808001BC
    if (ctx->r15 != ctx->r24) {
        // 0x8080019C: sw          $v0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r2;
            goto L_808001BC;
    }
    goto skip_0;
    // 0x8080019C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    skip_0:
    // 0x808001A0: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x808001A4: addu        $v1, $s0, $a1
    ctx->r3 = ADD32(ctx->r16, ctx->r5);
    // 0x808001A8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x808001AC: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x808001B0: b           L_808001BC
    // 0x808001B4: sw          $t2, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r10;
        goto L_808001BC;
    // 0x808001B4: sw          $t2, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r10;
L_808001B8:
    // 0x808001B8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
L_808001BC:
    // 0x808001BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x808001C0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x808001C4: bne         $at, $zero, L_808001F4
    if (ctx->r1 != 0) {
        // 0x808001C8: addu        $v1, $a0, $a1
        ctx->r3 = ADD32(ctx->r4, ctx->r5);
            goto L_808001F4;
    }
    // 0x808001C8: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x808001CC: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x808001D0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x808001D4: bnel        $t3, $t4, L_808001F8
    if (ctx->r11 != ctx->r12) {
        // 0x808001D8: sw          $v0, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->r2;
            goto L_808001F8;
    }
    goto skip_1;
    // 0x808001D8: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    skip_1:
    // 0x808001DC: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x808001E0: addu        $v1, $s0, $a1
    ctx->r3 = ADD32(ctx->r16, ctx->r5);
    // 0x808001E4: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x808001E8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x808001EC: b           L_808001F8
    // 0x808001F0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
        goto L_808001F8;
    // 0x808001F0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
L_808001F4:
    // 0x808001F4: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
L_808001F8:
    // 0x808001F8: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x808001FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80800200: bne         $t0, $t1, L_80800184
    if (ctx->r8 != ctx->r9) {
        // 0x80800204: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_80800184;
    }
    // 0x80800204: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_80800208:
    // 0x80800208: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8080020C: jr          $ra
    // 0x80800210: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80800210: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void ncpod_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800BFC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800C00: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800C04: jal         0x80110024
    // 0x80800C08: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_80110024(rdram, ctx);
        goto after_0;
    // 0x80800C08: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800C0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800C10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C14: jal         0x808005C0
    // 0x80800C18: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ncpod_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x80800C18: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800C1C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C20: jal         0x80089638
    // 0x80800C24: lh          $a0, 0x2($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X2);
    _ncpoducam_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800C24: lh          $a0, 0x2($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X2);
    after_2:
    // 0x80800C28: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800C2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C30: jal         0x80089650
    // 0x80800C34: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _ncpoducam_entrypoint_4(rdram, ctx);
        goto after_3;
    // 0x80800C34: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80800C38: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800C3C: jal         0x80800BC0
    // 0x80800C40: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    ncpod_entrypoint_19(rdram, ctx);
        goto after_4;
    // 0x80800C40: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800C44: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800C48: beql        $a1, $zero, L_80800C5C
    if (ctx->r5 == 0) {
        // 0x80800C4C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800C5C;
    }
    goto skip_0;
    // 0x80800C4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800C50: jal         0x80089648
    // 0x80800C54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _ncpoducam_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x80800C54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80800C58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800C5C:
    // 0x80800C5C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800C60: jal         0x80089640
    // 0x80800C64: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _ncpoducam_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800C64: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80800C68: jal         0x8010FD88
    // 0x80800C6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8010FD88(rdram, ctx);
        goto after_7;
    // 0x80800C6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x80800C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800C74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800C78: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80800C7C: jr          $ra
    // 0x80800C80: nop

    return;
    // 0x80800C80: nop

;}
RECOMP_FUNC void func_808022C4_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808022C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808022C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808022CC: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808022D0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808022D4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808022D8: beq         $t6, $at, L_80802330
    if (ctx->r14 == ctx->r1) {
        // 0x808022DC: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80802330;
    }
    // 0x808022DC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x808022E0: beq         $t6, $at, L_80802330
    if (ctx->r14 == ctx->r1) {
        // 0x808022E4: slti        $at, $t6, 0x5
        ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
            goto L_80802330;
    }
    // 0x808022E4: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x808022E8: bne         $at, $zero, L_80802330
    if (ctx->r1 != 0) {
        // 0x808022EC: slti        $at, $t6, 0x19
        ctx->r1 = SIGNED(ctx->r14) < 0X19 ? 1 : 0;
            goto L_80802330;
    }
    // 0x808022EC: slti        $at, $t6, 0x19
    ctx->r1 = SIGNED(ctx->r14) < 0X19 ? 1 : 0;
    // 0x808022F0: beq         $at, $zero, L_80802330
    if (ctx->r1 == 0) {
        // 0x808022F4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80802330;
    }
    // 0x808022F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808022F8: jal         0x80100094
    // 0x808022FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808022FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802300: lh          $t7, 0x92($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X92);
    // 0x80802304: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80802308: bnel        $t7, $zero, L_80802324
    if (ctx->r15 != 0) {
        // 0x8080230C: lh          $a1, 0x96($v0)
        ctx->r5 = MEM_H(ctx->r2, 0X96);
            goto L_80802324;
    }
    goto skip_0;
    // 0x8080230C: lh          $a1, 0x96($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X96);
    skip_0:
    // 0x80802310: jal         0x80801C50
    // 0x80802314: nop

    func_80801C50_changlerboss(rdram, ctx);
        goto after_1;
    // 0x80802314: nop

    after_1:
    // 0x80802318: b           L_80802324
    // 0x8080231C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80802324;
    // 0x8080231C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80802320: lh          $a1, 0x96($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X96);
L_80802324:
    // 0x80802324: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x80802328: jal         0x800D2498
    // 0x8080232C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_2;
    // 0x8080232C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80802330:
    // 0x80802330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802338: jr          $ra
    // 0x8080233C: nop

    return;
    // 0x8080233C: nop

;}
RECOMP_FUNC void _chfactorylobbydoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800873C0: syscall     561
    recomp_syscall_handler(rdram, ctx, 0x800873C0);
    return;
    // 0x800873C4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800024_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800024: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800028: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8080002C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800030: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800034: jal         0x80100094
    // 0x80800038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800038: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8080003C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800040: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800044: jal         0x800897D8
    // 0x80800048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    _suexpression_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x80800048: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8080004C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80800050: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80800054: jal         0x800EE7F8
    // 0x80800058: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x80800058: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_2:
    // 0x8080005C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80800060: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80800064: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x80800068: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8080006C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800070: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800074: slti        $at, $t7, 0x5
    ctx->r1 = SIGNED(ctx->r15) < 0X5 ? 1 : 0;
    // 0x80800078: beq         $at, $zero, L_8080008C
    if (ctx->r1 == 0) {
        // 0x8080007C: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_8080008C;
    }
    // 0x8080007C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80800080: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800084: b           L_8080009C
    // 0x80800088: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
        goto L_8080009C;
    // 0x80800088: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
L_8080008C:
    // 0x8080008C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800090: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800094: nop

    // 0x80800098: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
L_8080009C:
    // 0x8080009C: jal         0x8008FB10
    // 0x808000A0: lui         $a2, 0xC1A0
    ctx->r6 = S32(0XC1A0 << 16);
    func_8008FB10(rdram, ctx);
        goto after_3;
    // 0x808000A0: lui         $a2, 0xC1A0
    ctx->r6 = S32(0XC1A0 << 16);
    after_3:
    // 0x808000A4: lw          $t8, 0x7C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X7C);
    // 0x808000A8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808000AC: sll         $t0, $t8, 19
    ctx->r8 = S32(ctx->r24 << 19);
    // 0x808000B0: bgezl       $t0, L_808000C8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x808000B4: lhu         $t1, 0x72($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X72);
            goto L_808000C8;
    }
    goto skip_0;
    // 0x808000B4: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    skip_0:
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: jal         0x80085770
    // 0x808000C0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    _chbadshad_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x808000C0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x808000C4: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
L_808000C8:
    // 0x808000C8: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x808000CC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x808000D0: sltiu       $at, $t3, 0x8
    ctx->r1 = ctx->r11 < 0X8 ? 1 : 0;
    // 0x808000D4: beq         $at, $zero, L_80800288
    if (ctx->r1 == 0) {
        // 0x808000D8: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80800288;
    }
    // 0x808000D8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x808000DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(892, 0XE40) << 16);
    // 0x808000E0: addu        $at, $at, $t3
    gpr jr_addend_808000E8 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x808000E4: lw          $t3, 0xE40($at)
    ctx->r11 = ADD32(ctx->r1, (int16_t)RELOC_LO16(892, 0XE40));
    // 0x808000E8: jr          $t3
    // 0x808000EC: nop

    switch (jr_addend_808000E8 >> 2) {
        case 0: goto L_808000F0; break;
        case 1: goto L_8080015C; break;
        case 2: goto L_8080017C; break;
        case 3: goto L_808001C0; break;
        case 4: goto L_808001E0; break;
        case 5: goto L_80800248; break;
        case 6: goto L_80800270; break;
        case 7: goto L_80800280; break;
        default: switch_error(__func__, 0x808000E8, 0x80800E40);
    }
    // 0x808000EC: nop

L_808000F0:
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: jal         0x80100094
    // 0x808000F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x808000F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808000FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800100: jal         0x80089818
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_6;
    // 0x80800104: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800108: jal         0x808005F0
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005F0_chmineprospector(rdram, ctx);
        goto after_7;
    // 0x8080010C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800110: jal         0x800DA298
    // 0x80800114: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x80800114: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_8:
    // 0x80800118: beq         $v0, $zero, L_80800140
    if (ctx->r2 == 0) {
        // 0x8080011C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800140;
    }
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(892, 0XF58) << 16);
    // 0x80800124: addiu       $a1, $a1, 0xF58
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(892, 0XF58));
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80800130: jal         0x80800540
    // 0x80800134: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80800540_chmineprospector(rdram, ctx);
        goto after_9;
    // 0x80800134: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_9:
    // 0x80800138: b           L_8080028C
    // 0x8080013C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080028C;
    // 0x8080013C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800140:
    // 0x80800140: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(892, 0XF20) << 16);
    // 0x80800144: addiu       $a1, $a1, 0xF20
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(892, 0XF20));
    // 0x80800148: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8080014C: jal         0x80800540
    // 0x80800150: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80800540_chmineprospector(rdram, ctx);
        goto after_10;
    // 0x80800150: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_10:
    // 0x80800154: b           L_8080028C
    // 0x80800158: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080028C;
    // 0x80800158: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080015C:
    // 0x8080015C: jal         0x80101DDC
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_11;
    // 0x80800160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800164: beq         $v0, $zero, L_80800288
    if (ctx->r2 == 0) {
        // 0x80800168: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800288;
    }
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080016C: jal         0x80102424
    // 0x80800170: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x80800170: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x80800174: b           L_8080028C
    // 0x80800178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080028C;
    // 0x80800178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080017C:
    // 0x8080017C: lui         $a1, 0x3EC2
    ctx->r5 = S32(0X3EC2 << 16);
    // 0x80800180: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80800184: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800188: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x8080018C: jal         0x80102320
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102320(rdram, ctx);
        goto after_13;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800194: bne         $v0, $zero, L_808001B0
    if (ctx->r2 != 0) {
        // 0x80800198: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B0;
    }
    // 0x80800198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080019C: jal         0x80100094
    // 0x808001A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_14;
    // 0x808001A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x808001A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001A8: jal         0x80089818
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _suexpression_entrypoint_18(rdram, ctx);
        goto after_15;
    // 0x808001AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
L_808001B0:
    // 0x808001B0: jal         0x80800638
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800638_chmineprospector(rdram, ctx);
        goto after_16;
    // 0x808001B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001B8: b           L_8080028C
    // 0x808001BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080028C;
    // 0x808001BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001C0:
    // 0x808001C0: jal         0x80101DDC
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_17;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808001C8: beq         $v0, $zero, L_80800288
    if (ctx->r2 == 0) {
        // 0x808001CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800288;
    }
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x80102424
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_18;
    // 0x808001D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x808001D8: b           L_8080028C
    // 0x808001DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080028C;
    // 0x808001DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001E0:
    // 0x808001E0: jal         0x80101DDC
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_19;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808001E8: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x808001EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800224;
    }
    // 0x808001EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808001F4: jal         0x808009B0
    // 0x808001F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808009B0_chmineprospector(rdram, ctx);
        goto after_20;
    // 0x808001F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_20:
    // 0x808001FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800200: addiu       $t4, $zero, 0x3F
    ctx->r12 = ADD32(0, 0X3F);
    // 0x80800204: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800208: addiu       $a1, $zero, 0xF90
    ctx->r5 = ADD32(0, 0XF90);
    // 0x8080020C: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80800210: jal         0x8008A208
    // 0x80800214: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_21;
    // 0x80800214: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_21:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: jal         0x80102424
    // 0x80800220: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80102424(rdram, ctx);
        goto after_22;
    // 0x80800220: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_22:
L_80800224:
    // 0x80800224: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(892, 0X1104) << 16);
    // 0x80800228: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x8080022C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800230: addiu       $a2, $a2, 0x1104
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(892, 0X1104));
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: jal         0x80089D20
    // 0x8080023C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x8080023C: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_23:
    // 0x80800240: b           L_8080028C
    // 0x80800244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080028C;
    // 0x80800244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800248:
    // 0x80800248: jal         0x8080068C
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080068C_chmineprospector(rdram, ctx);
        goto after_24;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800250: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(892, 0XF90) << 16);
    // 0x80800254: addiu       $a1, $a1, 0xF90
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(892, 0XF90));
    // 0x80800258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080025C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80800260: jal         0x80800540
    // 0x80800264: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_80800540_chmineprospector(rdram, ctx);
        goto after_25;
    // 0x80800264: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_25:
    // 0x80800268: b           L_8080028C
    // 0x8080026C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080028C;
    // 0x8080026C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800270:
    // 0x80800270: jal         0x8080068C
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080068C_chmineprospector(rdram, ctx);
        goto after_26;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x80800278: b           L_8080028C
    // 0x8080027C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080028C;
    // 0x8080027C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800280:
    // 0x80800280: jal         0x8080068C
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080068C_chmineprospector(rdram, ctx);
        goto after_27;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
L_80800288:
    // 0x80800288: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080028C:
    // 0x8080028C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800290: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800294: jr          $ra
    // 0x80800298: nop

    return;
    // 0x80800298: nop

;}
RECOMP_FUNC void func_80800000_chjigsaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8080000C: lhu         $a1, 0x1A($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X1A);
    // 0x80800010: srl         $t6, $a1, 5
    ctx->r14 = S32(U32(ctx->r5) >> 5);
    // 0x80800014: jal         0x8010A6B0
    // 0x80800018: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_8010A6B0(rdram, ctx);
        goto after_0;
    // 0x80800018: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_0:
    // 0x8080001C: beql        $v0, $zero, L_80800064
    if (ctx->r2 == 0) {
        // 0x80800020: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800064;
    }
    goto skip_0;
    // 0x80800020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800024: jal         0x800DA298
    // 0x80800028: addiu       $a0, $zero, 0x665
    ctx->r4 = ADD32(0, 0X665);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a0, $zero, 0x665
    ctx->r4 = ADD32(0, 0X665);
    after_1:
    // 0x8080002C: bne         $v0, $zero, L_80800060
    if (ctx->r2 != 0) {
        // 0x80800030: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800060;
    }
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: jal         0x80108B04
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_2;
    // 0x80800038: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080003C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800040: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800044: lwc1        $f4, 0x50($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X50);
    // 0x80800048: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080004C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80800050: jal         0x800D0BD4
    // 0x80800054: nop

    func_800D0BD4(rdram, ctx);
        goto after_3;
    // 0x80800054: nop

    after_3:
    // 0x80800058: jal         0x80089FC8
    // 0x8080005C: nop

    _suautobaddies_entrypoint_3(rdram, ctx);
        goto after_4;
    // 0x8080005C: nop

    after_4:
L_80800060:
    // 0x80800060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800064:
    // 0x80800064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800068: jr          $ra
    // 0x8080006C: nop

    return;
    // 0x8080006C: nop

;}
RECOMP_FUNC void func_800CE980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CE984: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800CE988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CE98C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CE990: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800CE994: jal         0x800CE3E0
    // 0x800CE998: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_800CE3E0(rdram, ctx);
        goto after_0;
    // 0x800CE998: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800CE99C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CE9A0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800CE9A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CE9A8: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800CE9AC: nop

    // 0x800CE9B0: bc1fl       L_800CE9C0
    if (!c1cs) {
        // 0x800CE9B4: swc1        $f12, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
            goto L_800CE9C0;
    }
    goto skip_0;
    // 0x800CE9B4: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
    skip_0:
    // 0x800CE9B8: swc1        $f12, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f12.u32l;
    // 0x800CE9BC: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
L_800CE9C0:
    // 0x800CE9C0: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x800CE9C4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800CE9C8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800CE9CC: sltiu       $t6, $a2, 0x1
    ctx->r14 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x800CE9D0: jal         0x800CE49C
    // 0x800CE9D4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    func_800CE49C(rdram, ctx);
        goto after_1;
    // 0x800CE9D4: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    after_1:
    // 0x800CE9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CE9DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CE9E0: jr          $ra
    // 0x800CE9E4: nop

    return;
    // 0x800CE9E4: nop

;}
RECOMP_FUNC void func_80800058_ncbatarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080005C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800060: jal         0x80112524
    // 0x80800064: nop

    func_80112524(rdram, ctx);
        goto after_0;
    // 0x80800064: nop

    after_0:
    // 0x80800068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080006C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800070: jr          $ra
    // 0x80800074: nop

    return;
    // 0x80800074: nop

;}
RECOMP_FUNC void func_80800580_chfactorycrusher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800580: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800584: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800588: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080058C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800590: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800594: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800598: jal         0x80100094
    // 0x8080059C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080059C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808005A4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x808005A8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808005AC: beq         $a0, $at, L_808005E8
    if (ctx->r4 == ctx->r1) {
        // 0x808005B0: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808005E8;
    }
    // 0x808005B0: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808005B4: bne         $a0, $at, L_8080065C
    if (ctx->r4 != ctx->r1) {
        // 0x808005B8: addiu       $a1, $zero, 0x3BA
        ctx->r5 = ADD32(0, 0X3BA);
            goto L_8080065C;
    }
    // 0x808005B8: addiu       $a1, $zero, 0x3BA
    ctx->r5 = ADD32(0, 0X3BA);
    // 0x808005BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005C0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x808005C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808005C8: jal         0x80089C28
    // 0x808005CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    _subaddiefind_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808005CC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x808005D0: beq         $v0, $zero, L_808005E0
    if (ctx->r2 == 0) {
        // 0x808005D4: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_808005E0;
    }
    // 0x808005D4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x808005D8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808005DC: sw          $t6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r14;
L_808005E0:
    // 0x808005E0: b           L_80800664
    // 0x808005E4: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
        goto L_80800664;
    // 0x808005E4: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
L_808005E8:
    // 0x808005E8: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x808005EC: beq         $a1, $at, L_808005FC
    if (ctx->r5 == ctx->r1) {
        // 0x808005F0: addiu       $at, $zero, 0x22
        ctx->r1 = ADD32(0, 0X22);
            goto L_808005FC;
    }
    // 0x808005F0: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x808005F4: bne         $a1, $at, L_80800654
    if (ctx->r5 != ctx->r1) {
        // 0x808005F8: nop
    
            goto L_80800654;
    }
    // 0x808005F8: nop

L_808005FC:
    // 0x808005FC: jal         0x80800898
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800898_chfactorycrusher(rdram, ctx);
        goto after_2;
    // 0x80800600: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800604: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800608: andi        $t8, $t7, 0xFFF7
    ctx->r24 = ctx->r15 & 0XFFF7;
    // 0x8080060C: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    // 0x80800610: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x80800614: lbu         $t4, 0x65($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X65);
    // 0x80800618: sll         $t0, $t9, 12
    ctx->r8 = S32(ctx->r25 << 12);
    // 0x8080061C: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x80800620: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80800624: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x80800628: andi        $t5, $t4, 0xFFF7
    ctx->r13 = ctx->r12 & 0XFFF7;
    // 0x8080062C: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80800630: jal         0x800F54E4
    // 0x80800634: sb          $t6, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r14;
    func_800F54E4(rdram, ctx);
        goto after_3;
    // 0x80800634: sb          $t6, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r14;
    after_3:
    // 0x80800638: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080063C: jal         0x800F7F98
    // 0x80800640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800F7F98(rdram, ctx);
        goto after_4;
    // 0x80800640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800644: addiu       $a0, $zero, 0x3EE
    ctx->r4 = ADD32(0, 0X3EE);
    // 0x80800648: addiu       $a1, $zero, 0xBA
    ctx->r5 = ADD32(0, 0XBA);
    // 0x8080064C: jal         0x80101180
    // 0x80800650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x80800650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
L_80800654:
    // 0x80800654: b           L_80800668
    // 0x80800658: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80800668;
    // 0x80800658: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8080065C:
    // 0x8080065C: b           L_80800668
    // 0x80800660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800668;
    // 0x80800660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800664:
    // 0x80800664: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800668:
    // 0x80800668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080066C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800670: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800674: jr          $ra
    // 0x80800678: nop

    return;
    // 0x80800678: nop

;}
RECOMP_FUNC void _subaddietaxi_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A508: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A508);
    return;
    // 0x8008A50C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80801428_bssub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801428: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080142C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801430: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801434: jal         0x80800AEC
    // 0x80801438: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_80800AEC_bssub(rdram, ctx);
        goto after_0;
    // 0x80801438: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x8080143C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801440: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x80801444: jal         0x800914FC
    // 0x80801448: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800914FC(rdram, ctx);
        goto after_1;
    // 0x80801448: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8080144C: jal         0x80084600
    // 0x80801450: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    _babounce_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80801450: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80801454: beq         $v0, $zero, L_80801460
    if (ctx->r2 == 0) {
        // 0x80801458: addiu       $t6, $zero, 0x131
        ctx->r14 = ADD32(0, 0X131);
            goto L_80801460;
    }
    // 0x80801458: addiu       $t6, $zero, 0x131
    ctx->r14 = ADD32(0, 0X131);
    // 0x8080145C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_80801460:
    // 0x80801460: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80801464: jal         0x8009E5C8
    // 0x80801468: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x80801468: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8080146C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801470: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801474: jr          $ra
    // 0x80801478: nop

    return;
    // 0x80801478: nop

;}
RECOMP_FUNC void func_8080054C_chfantasydrillfield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080054C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80800550: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80800554: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800558: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8080055C: beq         $a1, $at, L_80800718
    if (ctx->r5 == ctx->r1) {
        // 0x80800560: sw          $a2, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r6;
            goto L_80800718;
    }
    // 0x80800560: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80800564: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80800568: beq         $a1, $at, L_808005B8
    if (ctx->r5 == ctx->r1) {
        // 0x8080056C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_808005B8;
    }
    // 0x8080056C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80800570: beq         $a1, $at, L_8080058C
    if (ctx->r5 == ctx->r1) {
        // 0x80800574: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_8080058C;
    }
    // 0x80800574: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800578: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x8080057C: beq         $a1, $at, L_80800784
    if (ctx->r5 == ctx->r1) {
        // 0x80800580: lw          $t7, 0x58($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X58);
            goto L_80800784;
    }
    // 0x80800580: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80800584: b           L_80800890
    // 0x80800588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800890;
    // 0x80800588: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080058C:
    // 0x8080058C: jal         0x8008A4B8
    // 0x80800590: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    _subaddieDll_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800590: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_0:
    // 0x80800594: beq         $v0, $zero, L_808005B0
    if (ctx->r2 == 0) {
        // 0x80800598: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_808005B0;
    }
    // 0x80800598: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080059C: jal         0x80103110
    // 0x808005A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_1;
    // 0x808005A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808005A4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808005A8: jal         0x80101FDC
    // 0x808005AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x808005AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
L_808005B0:
    // 0x808005B0: b           L_80800890
    // 0x808005B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800890;
    // 0x808005B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005B8:
    // 0x808005B8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x808005BC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808005C0: jal         0x800EE7F8
    // 0x808005C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x808005C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x808005C8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x808005CC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808005D0: jal         0x800EE7F8
    // 0x808005D4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_4;
    // 0x808005D4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_4:
    // 0x808005D8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808005DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808005E0: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x808005E4: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x808005E8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808005EC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808005F0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808005F4: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x808005F8: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x808005FC: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x80800600: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80800604: jal         0x800BEF00
    // 0x80800608: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    func_800BEF00(rdram, ctx);
        goto after_5;
    // 0x80800608: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8080060C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80800610: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2348, 0X8B0) << 16);
    // 0x80800614: addiu       $at, $zero, 0x1F7
    ctx->r1 = ADD32(0, 0X1F7);
    // 0x80800618: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x8080061C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80800620: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800624: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80800628: lw          $a0, 0x8B0($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(2348, 0X8B0));
    // 0x8080062C: beq         $a0, $zero, L_80800644
    if (ctx->r4 == 0) {
        // 0x80800630: nop
    
            goto L_80800644;
    }
    // 0x80800630: nop

    // 0x80800634: beq         $a0, $at, L_80800654
    if (ctx->r4 == ctx->r1) {
        // 0x80800638: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800654;
    }
    // 0x80800638: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080063C: b           L_80800678
    // 0x80800640: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
        goto L_80800678;
    // 0x80800640: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
L_80800644:
    // 0x80800644: jal         0x800FFA88
    // 0x80800648: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_6;
    // 0x80800648: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_6:
    // 0x8080064C: b           L_808006D0
    // 0x80800650: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
        goto L_808006D0;
    // 0x80800650: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
L_80800654:
    // 0x80800654: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80800658: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8080065C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80800660: jal         0x800D10D4
    // 0x80800664: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D10D4(rdram, ctx);
        goto after_7;
    // 0x80800664: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80800668: jal         0x80106790
    // 0x8080066C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_8;
    // 0x8080066C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80800670: b           L_808006D0
    // 0x80800674: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
        goto L_808006D0;
    // 0x80800674: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
L_80800678:
    // 0x80800678: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080067C: jal         0x80108528
    // 0x80800680: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    func_80108528(rdram, ctx);
        goto after_9;
    // 0x80800680: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_9:
    // 0x80800684: lw          $v1, 0x6C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6C);
    // 0x80800688: addiu       $at, $zero, 0x3DB
    ctx->r1 = ADD32(0, 0X3DB);
    // 0x8080068C: sll         $t0, $v1, 11
    ctx->r8 = S32(ctx->r3 << 11);
    // 0x80800690: srl         $v1, $t0, 20
    ctx->r3 = S32(U32(ctx->r8) >> 20);
    // 0x80800694: bne         $v1, $at, L_808006A8
    if (ctx->r3 != ctx->r1) {
        // 0x80800698: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_808006A8;
    }
    // 0x80800698: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8080069C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808006A0: b           L_808006CC
    // 0x808006A4: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
        goto L_808006CC;
    // 0x808006A4: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
L_808006A8:
    // 0x808006A8: addiu       $at, $zero, 0x40D
    ctx->r1 = ADD32(0, 0X40D);
    // 0x808006AC: bne         $v1, $at, L_808006CC
    if (ctx->r3 != ctx->r1) {
        // 0x808006B0: lw          $t2, 0x58($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X58);
            goto L_808006CC;
    }
    // 0x808006B0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x808006B4: lw          $t4, 0x34($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X34);
    // 0x808006B8: lhu         $t7, 0x76($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X76);
    // 0x808006BC: sll         $t6, $t4, 7
    ctx->r14 = S32(ctx->r12 << 7);
    // 0x808006C0: andi        $t8, $t7, 0x7F
    ctx->r24 = ctx->r15 & 0X7F;
    // 0x808006C4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x808006C8: sh          $t9, 0x76($v0)
    MEM_H(0X76, ctx->r2) = ctx->r25;
L_808006CC:
    // 0x808006CC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
L_808006D0:
    // 0x808006D0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x808006D4: beq         $t0, $zero, L_80800710
    if (ctx->r8 == 0) {
        // 0x808006D8: nop
    
            goto L_80800710;
    }
    // 0x808006D8: nop

    // 0x808006DC: lw          $a0, 0x34($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X34);
    // 0x808006E0: jal         0x800DA544
    // 0x808006E4: addiu       $a0, $a0, 0x335
    ctx->r4 = ADD32(ctx->r4, 0X335);
    func_800DA544(rdram, ctx);
        goto after_10;
    // 0x808006E4: addiu       $a0, $a0, 0x335
    ctx->r4 = ADD32(ctx->r4, 0X335);
    after_10:
    // 0x808006E8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x808006EC: jal         0x80086E20
    // 0x808006F0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    _chskeletonexplode_entrypoint_7(rdram, ctx);
        goto after_11;
    // 0x808006F0: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    after_11:
    // 0x808006F4: jal         0x8010A570
    // 0x808006F8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_8010A570(rdram, ctx);
        goto after_12;
    // 0x808006F8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_12:
    // 0x808006FC: jal         0x8010A624
    // 0x80800700: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_8010A624(rdram, ctx);
        goto after_13;
    // 0x80800700: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_13:
    // 0x80800704: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80800708: jal         0x800FFA88
    // 0x8080070C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_14;
    // 0x8080070C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_14:
L_80800710:
    // 0x80800710: b           L_80800890
    // 0x80800714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800890;
    // 0x80800714: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800718:
    // 0x80800718: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8080071C: lui         $a0, 0x5991
    ctx->r4 = S32(0X5991 << 16);
    // 0x80800720: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800724: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x80800728: ori         $a0, $a0, 0x9413
    ctx->r4 = ctx->r4 | 0X9413;
    // 0x8080072C: jal         0x800C4140
    // 0x80800730: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800C4140(rdram, ctx);
        goto after_15;
    // 0x80800730: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_15:
    // 0x80800734: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800738: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2348, 0X950) << 16);
    // 0x8080073C: addiu       $t4, $t4, 0x950
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2348, 0X950));
    // 0x80800740: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800744: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80800748: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080074C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800750: jal         0x800BBCB8
    // 0x80800754: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_800BBCB8(rdram, ctx);
        goto after_16;
    // 0x80800754: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_16:
    // 0x80800758: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080075C: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2348, 0X988) << 16);
    // 0x80800760: addiu       $t5, $t5, 0x988
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2348, 0X988));
    // 0x80800764: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800768: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8080076C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800770: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800774: jal         0x800BBCB8
    // 0x80800778: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_800BBCB8(rdram, ctx);
        goto after_17;
    // 0x80800778: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_17:
    // 0x8080077C: b           L_80800890
    // 0x80800780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800890;
    // 0x80800780: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800784:
    // 0x80800784: lw          $a0, 0x34($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X34);
    // 0x80800788: jal         0x800DA298
    // 0x8080078C: addiu       $a0, $a0, 0x335
    ctx->r4 = ADD32(ctx->r4, 0X335);
    func_800DA298(rdram, ctx);
        goto after_18;
    // 0x8080078C: addiu       $a0, $a0, 0x335
    ctx->r4 = ADD32(ctx->r4, 0X335);
    after_18:
    // 0x80800790: beq         $v0, $zero, L_80800880
    if (ctx->r2 == 0) {
        // 0x80800794: lw          $t6, 0x58($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X58);
            goto L_80800880;
    }
    // 0x80800794: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80800798: lbu         $t8, 0x65($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X65);
    // 0x8080079C: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x808007A0: sb          $t9, 0x65($t6)
    MEM_B(0X65, ctx->r14) = ctx->r25;
    // 0x808007A4: jal         0x8010A570
    // 0x808007A8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_8010A570(rdram, ctx);
        goto after_19;
    // 0x808007A8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_19:
    // 0x808007AC: jal         0x8010A624
    // 0x808007B0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_8010A624(rdram, ctx);
        goto after_20;
    // 0x808007B0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_20:
    // 0x808007B4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x808007B8: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(2348, 0X8B0) << 16);
    // 0x808007BC: addiu       $at, $zero, 0x1F7
    ctx->r1 = ADD32(0, 0X1F7);
    // 0x808007C0: lw          $t1, 0x34($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X34);
    // 0x808007C4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x808007C8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x808007CC: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x808007D0: lw          $v1, 0x8B0($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(2348, 0X8B0));
    // 0x808007D4: beq         $v1, $zero, L_808007EC
    if (ctx->r3 == 0) {
        // 0x808007D8: nop
    
            goto L_808007EC;
    }
    // 0x808007D8: nop

    // 0x808007DC: beq         $v1, $at, L_808007FC
    if (ctx->r3 == ctx->r1) {
        // 0x808007E0: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_808007FC;
    }
    // 0x808007E0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x808007E4: b           L_80800830
    // 0x808007E8: nop

        goto L_80800830;
    // 0x808007E8: nop

L_808007EC:
    // 0x808007EC: jal         0x800FFA88
    // 0x808007F0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_21;
    // 0x808007F0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_21:
    // 0x808007F4: b           L_80800880
    // 0x808007F8: nop

        goto L_80800880;
    // 0x808007F8: nop

L_808007FC:
    // 0x808007FC: jal         0x800D0B68
    // 0x80800800: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800D0B68(rdram, ctx);
        goto after_22;
    // 0x80800800: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_22:
    // 0x80800804: beq         $v0, $zero, L_80800820
    if (ctx->r2 == 0) {
        // 0x80800808: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_80800820;
    }
    // 0x80800808: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8080080C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80800810: jal         0x800FFA88
    // 0x80800814: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_23;
    // 0x80800814: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    after_23:
    // 0x80800818: b           L_80800880
    // 0x8080081C: nop

        goto L_80800880;
    // 0x8080081C: nop

L_80800820:
    // 0x80800820: jal         0x80108B04
    // 0x80800824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_24;
    // 0x80800824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_24:
    // 0x80800828: b           L_80800880
    // 0x8080082C: nop

        goto L_80800880;
    // 0x8080082C: nop

L_80800830:
    // 0x80800830: jal         0x80103EAC
    // 0x80800834: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    func_80103EAC(rdram, ctx);
        goto after_25;
    // 0x80800834: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_25:
    // 0x80800838: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x8080083C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(2348, 0X8B0) << 16);
    // 0x80800840: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x80800844: lw          $t7, 0x34($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X34);
    // 0x80800848: addiu       $t9, $t9, -0x14C0
    ctx->r25 = ADD32(ctx->r25, -0X14C0);
    // 0x8080084C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80800850: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80800854: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80800858: lw          $a0, 0x8B0($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(2348, 0X8B0));
    // 0x8080085C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80800860: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800864: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800868: jal         0x80089C48
    // 0x8080086C: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    _subaddiefind_entrypoint_5(rdram, ctx);
        goto after_26;
    // 0x8080086C: addiu       $a3, $t5, 0x4
    ctx->r7 = ADD32(ctx->r13, 0X4);
    after_26:
    // 0x80800870: bne         $v0, $zero, L_80800880
    if (ctx->r2 != 0) {
        // 0x80800874: lw          $a0, 0x58($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X58);
            goto L_80800880;
    }
    // 0x80800874: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80800878: jal         0x80108B04
    // 0x8080087C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_27;
    // 0x8080087C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
L_80800880:
    // 0x80800880: jal         0x800DA524
    // 0x80800884: addiu       $a0, $zero, 0xA0F
    ctx->r4 = ADD32(0, 0XA0F);
    func_800DA524(rdram, ctx);
        goto after_28;
    // 0x80800884: addiu       $a0, $zero, 0xA0F
    ctx->r4 = ADD32(0, 0XA0F);
    after_28:
    // 0x80800888: b           L_80800890
    // 0x8080088C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800890;
    // 0x8080088C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800890:
    // 0x80800890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800894: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80800898: jr          $ra
    // 0x8080089C: nop

    return;
    // 0x8080089C: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897D8: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x800897D8);
    return;
    // 0x800897DC: addi        $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
;}
RECOMP_FUNC void func_808015F8_sucoaster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_aim_trace(rdram, ctx, "func_808015F8_sucoaster");
    // 0x808015F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808015FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801600: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80801604: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801608: jal         0x80802760
    // 0x8080160C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80802760_sucoaster(rdram, ctx);
        goto after_0;
    // 0x8080160C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80801610: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80801614: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801618: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8080161C: lbu         $v1, 0x15($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X15);
    // 0x80801620: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80801624: beql        $v1, $zero, L_80801638
    if (ctx->r3 == 0) {
        // 0x80801628: lw          $v0, 0x70($t7)
        ctx->r2 = MEM_W(ctx->r15, 0X70);
            goto L_80801638;
    }
    goto skip_0;
    // 0x80801628: lw          $v0, 0x70($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X70);
    skip_0:
    // 0x8080162C: b           L_80801640
    // 0x80801630: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80801640;
    // 0x80801630: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80801634: lw          $v0, 0x70($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X70);
L_80801638:
    // 0x80801638: sll         $t8, $v0, 22
    ctx->r24 = S32(ctx->r2 << 22);
    // 0x8080163C: srl         $v0, $t8, 26
    ctx->r2 = S32(U32(ctx->r24) >> 26);
L_80801640:
    // 0x80801640: jal         0x800F5A00
    // 0x80801644: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80801644: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80801648: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8080164C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80801650: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80801654: lw          $a1, 0x70($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X70);
    // 0x80801658: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x8080165C: srl         $t1, $a1, 25
    ctx->r9 = S32(U32(ctx->r5) >> 25);
    // 0x80801660: jal         0x800CC338
    // 0x80801664: addiu       $a1, $t1, -0x1
    ctx->r5 = ADD32(ctx->r9, -0X1);
    func_800CC338(rdram, ctx);
        goto after_2;
    // 0x80801664: addiu       $a1, $t1, -0x1
    ctx->r5 = ADD32(ctx->r9, -0X1);
    after_2:
    // 0x80801668: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8080166C: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80801670: andi        $v0, $t2, 0xFF
    ctx->r2 = ctx->r10 & 0XFF;
    // 0x80801674: sb          $t2, 0x15($v1)
    MEM_B(0X15, ctx->r3) = ctx->r10;
    // 0x80801678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080167C: sltu        $t3, $zero, $v0
    ctx->r11 = 0 < ctx->r2 ? 1 : 0;
    // 0x80801680: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80801684: jr          $ra
    // 0x80801688: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80801688: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80800B00_chcheato(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800B04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800B08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800B0C: jal         0x80800C0C
    // 0x80800B10: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    func_80800C0C_chcheato(rdram, ctx);
        goto after_0;
    // 0x80800B10: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B14: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80800B18: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80800B1C: addiu       $t6, $zero, 0x1849
    ctx->r14 = ADD32(0, 0X1849);
    // 0x80800B20: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800B24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800B28: addiu       $a3, $a3, 0x7DB0
    ctx->r7 = ADD32(ctx->r7, 0X7DB0);
    // 0x80800B2C: addiu       $a2, $a2, 0x7D18
    ctx->r6 = ADD32(ctx->r6, 0X7D18);
    // 0x80800B30: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800B34: jal         0x80087CB8
    // 0x80800B38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_4(rdram, ctx);
        goto after_1;
    // 0x80800B38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800B3C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800B40: jal         0x80100094
    // 0x80800B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800B48: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800B4C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800B50: jal         0x800F1418
    // 0x80800B54: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800F1418(rdram, ctx);
        goto after_3;
    // 0x80800B54: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x80800B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B5C: jal         0x80087CD8
    // 0x80800B60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    _gcnewoption_entrypoint_8(rdram, ctx);
        goto after_4;
    // 0x80800B60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80800B64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B68: jal         0x80087CE0
    // 0x80800B6C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _gcnewoption_entrypoint_9(rdram, ctx);
        goto after_5;
    // 0x80800B6C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800B74: jal         0x80087CE8
    // 0x80800B78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_10(rdram, ctx);
        goto after_6;
    // 0x80800B78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80800B7C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800B80: jal         0x8080098C
    // 0x80800B84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8080098C_chcheato(rdram, ctx);
        goto after_7;
    // 0x80800B84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x80800B88: jal         0x80087CF0
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _gcnewoption_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x80800B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800B90: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800B94: jal         0x80102424
    // 0x80800B98: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x80800B98: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x80800B9C: jal         0x80090708
    // 0x80800BA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80090708(rdram, ctx);
        goto after_10;
    // 0x80800BA0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x80800BA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800BA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800BAC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800BB0: jr          $ra
    // 0x80800BB4: nop

    return;
    // 0x80800BB4: nop

;}
RECOMP_FUNC void chburgerstand_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(936, 0XCB8) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0xCB8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(936, 0XCB8));
    return;
    // 0x80800020: addiu       $v0, $v0, 0xCB8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(936, 0XCB8));
;}
RECOMP_FUNC void func_808016B4_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808016B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808016B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808016BC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808016C0: jal         0x8080000C
    // 0x808016C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8080000C_bstrexlarge(rdram, ctx);
        goto after_0;
    // 0x808016C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808016C8: jal         0x8080081C
    // 0x808016CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bstrexlarge_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808016CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808016D0: lui         $a1, 0x3DC2
    ctx->r5 = S32(0X3DC2 << 16);
    // 0x808016D4: ori         $a1, $a1, 0x8F5C
    ctx->r5 = ctx->r5 | 0X8F5C;
    // 0x808016D8: jal         0x8008CB10
    // 0x808016DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_2;
    // 0x808016DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808016E0: beq         $v0, $zero, L_808016FC
    if (ctx->r2 == 0) {
        // 0x808016E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808016FC;
    }
    // 0x808016E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016E8: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x808016EC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808016F0: addiu       $a1, $zero, 0x570
    ctx->r5 = ADD32(0, 0X570);
    // 0x808016F4: jal         0x8009DF18
    // 0x808016F8: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    func_8009DF18(rdram, ctx);
        goto after_3;
    // 0x808016F8: addiu       $a3, $zero, 0x4650
    ctx->r7 = ADD32(0, 0X4650);
    after_3:
L_808016FC:
    // 0x808016FC: lui         $a1, 0x3F0B
    ctx->r5 = S32(0X3F0B << 16);
    // 0x80801700: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80801704: jal         0x8008CB10
    // 0x80801708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_4;
    // 0x80801708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080170C: beq         $v0, $zero, L_8080173C
    if (ctx->r2 == 0) {
        // 0x80801710: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080173C;
    }
    // 0x80801710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801714: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80801718: lui         $a3, 0x3F8C
    ctx->r7 = S32(0X3F8C << 16);
    // 0x8080171C: addiu       $t6, $zero, 0x4E20
    ctx->r14 = ADD32(0, 0X4E20);
    // 0x80801720: addiu       $t7, $zero, 0x55F0
    ctx->r15 = ADD32(0, 0X55F0);
    // 0x80801724: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80801728: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080172C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80801730: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801734: jal         0x8009DEC0
    // 0x80801738: addiu       $a1, $zero, 0x56F
    ctx->r5 = ADD32(0, 0X56F);
    func_8009DEC0(rdram, ctx);
        goto after_5;
    // 0x80801738: addiu       $a1, $zero, 0x56F
    ctx->r5 = ADD32(0, 0X56F);
    after_5:
L_8080173C:
    // 0x8080173C: lui         $a1, 0x3F51
    ctx->r5 = S32(0X3F51 << 16);
    // 0x80801740: ori         $a1, $a1, 0xEB85
    ctx->r5 = ctx->r5 | 0XEB85;
    // 0x80801744: jal         0x8008CB10
    // 0x80801748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_6;
    // 0x80801748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080174C: beq         $v0, $zero, L_80801768
    if (ctx->r2 == 0) {
        // 0x80801750: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801768;
    }
    // 0x80801750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801754: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80801758: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8080175C: addiu       $a1, $zero, 0x570
    ctx->r5 = ADD32(0, 0X570);
    // 0x80801760: jal         0x8009DF18
    // 0x80801764: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    func_8009DF18(rdram, ctx);
        goto after_7;
    // 0x80801764: addiu       $a3, $zero, 0x4E20
    ctx->r7 = ADD32(0, 0X4E20);
    after_7:
L_80801768:
    // 0x80801768: lui         $a1, 0x3F6B
    ctx->r5 = S32(0X3F6B << 16);
    // 0x8080176C: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x80801770: jal         0x8008CB10
    // 0x80801774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isAt(rdram, ctx);
        goto after_8;
    // 0x80801774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801778: beq         $v0, $zero, L_80801790
    if (ctx->r2 == 0) {
        // 0x8080177C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801790;
    }
    // 0x8080177C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801780: addiu       $a1, $zero, 0x570
    ctx->r5 = ADD32(0, 0X570);
    // 0x80801784: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80801788: jal         0x8009DF18
    // 0x8080178C: addiu       $a3, $zero, 0x32C8
    ctx->r7 = ADD32(0, 0X32C8);
    func_8009DF18(rdram, ctx);
        goto after_9;
    // 0x8080178C: addiu       $a3, $zero, 0x32C8
    ctx->r7 = ADD32(0, 0X32C8);
    after_9:
L_80801790:
    // 0x80801790: jal         0x808004B4
    // 0x80801794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004B4_bstrexlarge(rdram, ctx);
        goto after_10;
    // 0x80801794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80801798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080179C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808017A0: jal         0x808003C4
    // 0x808017A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808003C4_bstrexlarge(rdram, ctx);
        goto after_11;
    // 0x808017A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x808017A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808017AC: jal         0x8009E5C8
    // 0x808017B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_12;
    // 0x808017B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x808017B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808017B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808017BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808017C0: jr          $ra
    // 0x808017C4: nop

    return;
    // 0x808017C4: nop

;}
RECOMP_FUNC void subaddiefind_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080053C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800540: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80800544: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800548: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8080054C: addiu       $s5, $sp, 0x3C
    ctx->r21 = ADD32(ctx->r29, 0X3C);
    // 0x80800550: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800554: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800558: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8080055C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800560: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80800564: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80800568: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8080056C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800570: jal         0x801067C4
    // 0x80800574: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_801067C4(rdram, ctx);
        goto after_0;
    // 0x80800574: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_0:
    // 0x80800578: beq         $v0, $zero, L_808005F0
    if (ctx->r2 == 0) {
        // 0x8080057C: addiu       $s2, $zero, -0x1
        ctx->r18 = ADD32(0, -0X1);
            goto L_808005F0;
    }
    // 0x8080057C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80800580: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
L_80800584:
    // 0x80800584: sll         $t8, $t6, 14
    ctx->r24 = S32(ctx->r14 << 14);
    // 0x80800588: bltz        $t8, L_808005E0
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080058C: nop
    
            goto L_808005E0;
    }
    // 0x8080058C: nop

    // 0x80800590: lh          $t9, 0x0($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X0);
    // 0x80800594: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x80800598: beq         $s2, $t9, L_808005E0
    if (ctx->r18 == ctx->r25) {
        // 0x8080059C: nop
    
            goto L_808005E0;
    }
    // 0x8080059C: nop

    // 0x808005A0: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x808005A4: lw          $t0, 0x6C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X6C);
L_808005A8:
    // 0x808005A8: sll         $t1, $t0, 11
    ctx->r9 = S32(ctx->r8 << 11);
    // 0x808005AC: srl         $t2, $t1, 20
    ctx->r10 = S32(U32(ctx->r9) >> 20);
    // 0x808005B0: bnel        $t2, $a0, L_808005D4
    if (ctx->r10 != ctx->r4) {
        // 0x808005B4: lh          $a0, 0x2($v1)
        ctx->r4 = MEM_H(ctx->r3, 0X2);
            goto L_808005D4;
    }
    goto skip_0;
    // 0x808005B4: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    skip_0:
    // 0x808005B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x808005BC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x808005C0: bne         $s1, $s3, L_808005D0
    if (ctx->r17 != ctx->r19) {
        // 0x808005C4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_808005D0;
    }
    // 0x808005C4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808005C8: b           L_808005F4
    // 0x808005CC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_808005F4;
    // 0x808005CC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_808005D0:
    // 0x808005D0: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
L_808005D4:
    // 0x808005D4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x808005D8: bnel        $s2, $a0, L_808005A8
    if (ctx->r18 != ctx->r4) {
        // 0x808005DC: lw          $t0, 0x6C($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X6C);
            goto L_808005A8;
    }
    goto skip_1;
    // 0x808005DC: lw          $t0, 0x6C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X6C);
    skip_1:
L_808005E0:
    // 0x808005E0: jal         0x8010682C
    // 0x808005E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_8010682C(rdram, ctx);
        goto after_1;
    // 0x808005E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x808005E8: bnel        $v0, $zero, L_80800584
    if (ctx->r2 != 0) {
        // 0x808005EC: lw          $t6, 0x64($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X64);
            goto L_80800584;
    }
    goto skip_2;
    // 0x808005EC: lw          $t6, 0x64($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X64);
    skip_2:
L_808005F0:
    // 0x808005F0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_808005F4:
    // 0x808005F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808005F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808005FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800600: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800604: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80800608: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8080060C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80800610: jr          $ra
    // 0x80800614: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800614: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80800000_bskazshoesspringjump(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800010: beq         $a1, $zero, L_80800038
    if (ctx->r5 == 0) {
        // 0x80800014: sw          $a1, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r5;
            goto L_80800038;
    }
    // 0x80800014: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800018: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080001C: beq         $a1, $at, L_80800048
    if (ctx->r5 == ctx->r1) {
        // 0x80800020: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800048;
    }
    // 0x80800020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800024: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800028: beq         $a1, $at, L_80800098
    if (ctx->r5 == ctx->r1) {
        // 0x8080002C: nop
    
            goto L_80800098;
    }
    // 0x8080002C: nop

    // 0x80800030: b           L_808000EC
    // 0x80800034: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_808000EC;
    // 0x80800034: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_80800038:
    // 0x80800038: jal         0x8009BC6C
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x8080003C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800040: b           L_808000EC
    // 0x80800044: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_808000EC;
    // 0x80800044: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_80800048:
    // 0x80800048: lui         $a2, 0x3FF3
    ctx->r6 = S32(0X3FF3 << 16);
    // 0x8080004C: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80800050: jal         0x8008CCBC
    // 0x80800054: addiu       $a1, $zero, 0x24C
    ctx->r5 = ADD32(0, 0X24C);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x80800054: addiu       $a1, $zero, 0x24C
    ctx->r5 = ADD32(0, 0X24C);
    after_1:
    // 0x80800058: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8080005C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800068: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080006C: jal         0x8009FFD8
    // 0x80800070: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800070: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x80800074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800078: jal         0x8009B9B0
    // 0x8080007C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x8080007C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800080: lui         $a1, 0xC528
    ctx->r5 = S32(0XC528 << 16);
    // 0x80800084: ori         $a1, $a1, 0xC000
    ctx->r5 = ctx->r5 | 0XC000;
    // 0x80800088: jal         0x8009BCB4
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_gravity(rdram, ctx);
        goto after_4;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800090: b           L_808000EC
    // 0x80800094: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
        goto L_808000EC;
    // 0x80800094: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_80800098:
    // 0x80800098: jal         0x80085060
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bashoes_entrypoint_17(rdram, ctx);
        goto after_5;
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: jal         0x8009B800
    // 0x808000A8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    baphysics_set_type(rdram, ctx);
        goto after_6;
    // 0x808000A8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_6:
    // 0x808000AC: lui         $a1, 0x4548
    ctx->r5 = S32(0X4548 << 16);
    // 0x808000B0: ori         $a1, $a1, 0x7000
    ctx->r5 = ctx->r5 | 0X7000;
    // 0x808000B4: jal         0x8009BA58
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_7;
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000BC: lui         $a2, 0x3F73
    ctx->r6 = S32(0X3F73 << 16);
    // 0x808000C0: lui         $a3, 0x3F86
    ctx->r7 = S32(0X3F86 << 16);
    // 0x808000C4: addiu       $t8, $zero, 0x7FFF
    ctx->r24 = ADD32(0, 0X7FFF);
    // 0x808000C8: addiu       $t9, $zero, 0x7FFF
    ctx->r25 = ADD32(0, 0X7FFF);
    // 0x808000CC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x808000D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808000D4: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x808000D8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E0: jal         0x8009DEC0
    // 0x808000E4: addiu       $a1, $zero, 0x4598
    ctx->r5 = ADD32(0, 0X4598);
    func_8009DEC0(rdram, ctx);
        goto after_8;
    // 0x808000E4: addiu       $a1, $zero, 0x4598
    ctx->r5 = ADD32(0, 0X4598);
    after_8:
    // 0x808000E8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_808000EC:
    // 0x808000EC: sw          $t0, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r8;
    // 0x808000F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808000FC: jr          $ra
    // 0x80800100: nop

    return;
    // 0x80800100: nop

;}
RECOMP_FUNC void bskazshoessuckspline_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080032C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800330: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800334: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800338: jal         0x800832E0
    // 0x8080033C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080033C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800340: jal         0x808000A4
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000A4_bskazshoessuckspline(rdram, ctx);
        goto after_1;
    // 0x80800344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080034C: addiu       $a1, $zero, 0xA4
    ctx->r5 = ADD32(0, 0XA4);
    // 0x80800350: jal         0x8008CB3C
    // 0x80800354: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_2;
    // 0x80800354: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_2:
    // 0x80800358: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x8080035C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800364: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800368: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8080036C: jal         0x8009FFD8
    // 0x80800370: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_8009FFD8(rdram, ctx);
        goto after_3;
    // 0x80800370: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_3:
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800378: jal         0x8009B9B0
    // 0x8080037C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_4;
    // 0x8080037C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800384: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800388: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080038C: jr          $ra
    // 0x80800390: nop

    return;
    // 0x80800390: nop

;}
RECOMP_FUNC void bsbansack_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800A00: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800A04: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(41, 0X1E30) << 16);
    // 0x80800A08: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800A0C: jr          $ra
    // 0x80800A10: lw          $v0, 0x1E30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E30));
    return;
    // 0x80800A10: lw          $v0, 0x1E30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E30));
;}
RECOMP_FUNC void sccustom_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800770: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800778: jal         0x8008A618
    // 0x8080077C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _scinfobar_entrypoint_19(rdram, ctx);
        goto after_0;
    // 0x8080077C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800780: addiu       $at, $zero, 0x3E7
    ctx->r1 = ADD32(0, 0X3E7);
    // 0x80800784: bne         $v0, $at, L_808007F8
    if (ctx->r2 != ctx->r1) {
        // 0x80800788: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(3342, 0X920) << 16);
            goto L_808007F8;
    }
    // 0x80800788: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3342, 0X920) << 16);
    // 0x8080078C: jal         0x800E7188
    // 0x80800790: lw          $a0, 0x920($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(3342, 0X920));
    func_800E7188(rdram, ctx);
        goto after_1;
    // 0x80800790: lw          $a0, 0x920($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(3342, 0X920));
    after_1:
    // 0x80800794: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800798: jal         0x8008A610
    // 0x8080079C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _scinfobar_entrypoint_18(rdram, ctx);
        goto after_2;
    // 0x8080079C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x808007A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808007A4: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x808007A8: beql        $at, $zero, L_808007B8
    if (ctx->r1 == 0) {
        // 0x808007AC: lui         $at, 0x41C0
        ctx->r1 = S32(0X41C0 << 16);
            goto L_808007B8;
    }
    goto skip_0;
    // 0x808007AC: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    skip_0:
    // 0x808007B0: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x808007B4: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
L_808007B8:
    // 0x808007B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808007BC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x808007C0: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x808007C4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x808007C8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x808007CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808007D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808007D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007D8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x808007DC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x808007E0: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x808007E4: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x808007E8: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x808007EC: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x808007F0: b           L_80800810
    // 0x808007F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800810;
    // 0x808007F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007F8:
    // 0x808007F8: jal         0x808004C8
    // 0x808007FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808004C8_sccustom(rdram, ctx);
        goto after_3;
    // 0x808007FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80800800: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800804: jal         0x808006C4
    // 0x80800808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_808006C4_sccustom(rdram, ctx);
        goto after_4;
    // 0x80800808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8080080C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800810:
    // 0x80800810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800814: jr          $ra
    // 0x80800818: nop

    return;
    // 0x80800818: nop

;}
RECOMP_FUNC void _chfactorymagnet_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800874E8: syscall     579
    recomp_syscall_handler(rdram, ctx, 0x800874E8);
    return;
    // 0x800874EC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
