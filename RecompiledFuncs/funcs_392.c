#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void basub_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808008D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808008DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808008E0: jal         0x80085458
    // 0x808008E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bawobble_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x808008E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808008E8: jal         0x808000CC
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000CC_basub(rdram, ctx);
        goto after_1;
    // 0x808008EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808008F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808008F4: lw          $t6, 0x130($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X130);
    // 0x808008F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(616, 0XC30) << 16);
    // 0x808008FC: addiu       $a2, $a2, 0xC30
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(616, 0XC30));
    // 0x80800900: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x80800904: lw          $t7, 0x130($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X130);
    // 0x80800908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080090C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800910: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x80800914: lw          $v1, 0x130($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X130);
    // 0x80800918: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8080091C: jal         0x8009D454
    // 0x80800920: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    func_8009D454(rdram, ctx);
        goto after_2;
    // 0x80800920: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    after_2:
    // 0x80800924: lw          $t8, 0x130($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X130);
    // 0x80800928: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080092C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800930: sb          $v0, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r2;
    // 0x80800934: lw          $t9, 0x130($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X130);
    // 0x80800938: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080093C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800940: swc1        $f6, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f6.u32l;
    // 0x80800944: lw          $t0, 0x130($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X130);
    // 0x80800948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080094C: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x80800950: lw          $v1, 0x130($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X130);
    // 0x80800954: lwc1        $f10, 0x18($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80800958: swc1        $f10, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f10.u32l;
    // 0x8080095C: lw          $t1, 0x130($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X130);
    // 0x80800960: swc1        $f0, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f0.u32l;
    // 0x80800964: lw          $t2, 0x130($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X130);
    // 0x80800968: swc1        $f0, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f0.u32l;
    // 0x8080096C: lw          $t3, 0x130($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X130);
    // 0x80800970: jal         0x808004C8
    // 0x80800974: swc1        $f0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f0.u32l;
    func_808004C8_basub(rdram, ctx);
        goto after_3;
    // 0x80800974: swc1        $f0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f0.u32l;
    after_3:
    // 0x80800978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080097C: jal         0x80800B60
    // 0x80800980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    basub_entrypoint_15(rdram, ctx);
        goto after_4;
    // 0x80800980: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800988: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080098C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800990: jr          $ra
    // 0x80800994: nop

    return;
    // 0x80800994: nop

;}
RECOMP_FUNC void bskaz_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080014C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800150: jal         0x8009EA2C
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009EA2C(rdram, ctx);
        goto after_0;
    // 0x80800154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800158: beq         $v0, $zero, L_80800168
    if (ctx->r2 == 0) {
        // 0x8080015C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800168;
    }
    // 0x8080015C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800160: b           L_8080016C
    // 0x80800164: addiu       $v0, $zero, 0x18B
    ctx->r2 = ADD32(0, 0X18B);
        goto L_8080016C;
    // 0x80800164: addiu       $v0, $zero, 0x18B
    ctx->r2 = ADD32(0, 0X18B);
L_80800168:
    // 0x80800168: addiu       $v0, $zero, 0xC2
    ctx->r2 = ADD32(0, 0XC2);
L_8080016C:
    // 0x8080016C: jr          $ra
    // 0x80800170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800818_chmrsicecube(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800818: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080081C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800820: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800824: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800828: jal         0x8080066C
    // 0x8080082C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8080066C_chmrsicecube(rdram, ctx);
        goto after_0;
    // 0x8080082C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80800830: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1204, 0XA74) << 16);
    // 0x80800834: addiu       $t6, $t6, 0xA74
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1204, 0XA74));
    // 0x80800838: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8080083C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800840: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800844: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800848: jal         0x800BBCB8
    // 0x8080084C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_800BBCB8(rdram, ctx);
        goto after_1;
    // 0x8080084C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_1:
    // 0x80800850: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1204, 0XA64) << 16);
    // 0x80800854: addiu       $a2, $a2, 0xA64
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1204, 0XA64));
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080085C: jal         0x80089D18
    // 0x80800860: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800860: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80800864: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800868: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080086C: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800870: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80800874: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800878: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080087C: jal         0x801094E0
    // 0x80800880: nop

    func_801094E0(rdram, ctx);
        goto after_3;
    // 0x80800880: nop

    after_3:
    // 0x80800884: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800888: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080088C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800890: jr          $ra
    // 0x80800894: nop

    return;
    // 0x80800894: nop

;}
RECOMP_FUNC void glid_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A0: jr          $ra
    // 0x808005A4: sw          $a1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r5;
    return;
    // 0x808005A4: sw          $a1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r5;
    // 0x808005A8: nop

    // 0x808005AC: nop

;}
RECOMP_FUNC void baswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080000C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800010: jal         0x800964DC
    // 0x80800014: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800964DC(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800018: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8080001C: jal         0x8009C150
    // 0x80800020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8009C150(rdram, ctx);
        goto after_1;
    // 0x80800020: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800024: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800028: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8080002C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800030: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80800034: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080003C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800040: nop

    // 0x80800044: bc1f        L_80800050
    if (!c1cs) {
        // 0x80800048: nop
    
            goto L_80800050;
    }
    // 0x80800048: nop

    // 0x8080004C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800050:
    // 0x80800050: jr          $ra
    // 0x80800054: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800054: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800708_chboggygirl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800708: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080070C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800710: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800714: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800718: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080071C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800720: jal         0x80100094
    // 0x80800724: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800724: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800728: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8080072C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800730: addiu       $t6, $a1, -0x108B
    ctx->r14 = ADD32(ctx->r5, -0X108B);
    // 0x80800734: sltiu       $at, $t6, 0xF
    ctx->r1 = ctx->r14 < 0XF ? 1 : 0;
    // 0x80800738: beq         $at, $zero, L_8080084C
    if (ctx->r1 == 0) {
        // 0x8080073C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8080084C;
    }
    // 0x8080073C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800740: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1536, 0XC14) << 16);
    // 0x80800744: addu        $at, $at, $t6
    gpr jr_addend_8080074C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800748: lw          $t6, 0xC14($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1536, 0XC14));
    // 0x8080074C: jr          $t6
    // 0x80800750: nop

    switch (jr_addend_8080074C >> 2) {
        case 0: goto L_808007F0; break;
        case 1: goto L_8080084C; break;
        case 2: goto L_8080084C; break;
        case 3: goto L_808007CC; break;
        case 4: goto L_80800794; break;
        case 5: goto L_80800754; break;
        case 6: goto L_8080084C; break;
        case 7: goto L_8080084C; break;
        case 8: goto L_8080084C; break;
        case 9: goto L_8080084C; break;
        case 10: goto L_8080084C; break;
        case 11: goto L_8080084C; break;
        case 12: goto L_8080084C; break;
        case 13: goto L_8080083C; break;
        case 14: goto L_8080083C; break;
        default: switch_error(__func__, 0x8080074C, 0x80800C14);
    }
    // 0x80800750: nop

L_80800754:
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800758: jal         0x80102424
    // 0x8080075C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080075C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x80800760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800764: jal         0x8008A4B0
    // 0x80800768: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_2;
    // 0x80800768: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8080076C: jal         0x800DA544
    // 0x80800770: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    func_800DA544(rdram, ctx);
        goto after_3;
    // 0x80800770: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_3:
    // 0x80800774: jal         0x80800A4C
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800A4C_chboggygirl(rdram, ctx);
        goto after_4;
    // 0x80800778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080077C: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    // 0x80800780: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x80800784: jal         0x80101180
    // 0x80800788: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x80800788: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8080078C: b           L_8080090C
    // 0x80800790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080090C;
    // 0x80800790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800794:
    // 0x80800794: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800798: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8080079C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808007A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x808007A8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x808007AC: jal         0x80102924
    // 0x808007B0: nop

    func_80102924(rdram, ctx);
        goto after_6;
    // 0x808007B0: nop

    after_6:
    // 0x808007B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808007B8: jal         0x80102424
    // 0x808007BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x808007BC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_7:
    // 0x808007C0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x808007C4: b           L_80800908
    // 0x808007C8: sh          $zero, 0x14($t7)
    MEM_H(0X14, ctx->r15) = 0;
        goto L_80800908;
    // 0x808007C8: sh          $zero, 0x14($t7)
    MEM_H(0X14, ctx->r15) = 0;
L_808007CC:
    // 0x808007CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808007D0: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x808007D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808007D8: addiu       $a1, $zero, 0x108B
    ctx->r5 = ADD32(0, 0X108B);
    // 0x808007DC: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x808007E0: jal         0x8008A208
    // 0x808007E4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_8;
    // 0x808007E4: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x808007E8: b           L_8080090C
    // 0x808007EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080090C;
    // 0x808007EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808007F0:
    // 0x808007F0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x808007F4: addiu       $a1, $zero, 0x108F
    ctx->r5 = ADD32(0, 0X108F);
    // 0x808007F8: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808007FC: blez        $t9, L_80800824
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80800800: addiu       $a3, $s0, 0x4
        ctx->r7 = ADD32(ctx->r16, 0X4);
            goto L_80800824;
    }
    // 0x80800800: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x80800804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800808: jal         0x80102424
    // 0x8080080C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_80102424(rdram, ctx);
        goto after_9;
    // 0x8080080C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_9:
    // 0x80800810: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800814: jal         0x80089FE0
    // 0x80800818: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    _subaddieitem_entrypoint_2(rdram, ctx);
        goto after_10;
    // 0x80800818: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_10:
    // 0x8080081C: b           L_8080090C
    // 0x80800820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080090C;
    // 0x80800820: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800824:
    // 0x80800824: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800828: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x8080082C: jal         0x8008A208
    // 0x80800830: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x80800830: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_11:
    // 0x80800834: b           L_8080090C
    // 0x80800838: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080090C;
    // 0x80800838: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080083C:
    // 0x8080083C: lbu         $t1, 0x16($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X16);
    // 0x80800840: andi        $t2, $t1, 0xFFBF
    ctx->r10 = ctx->r9 & 0XFFBF;
    // 0x80800844: b           L_80800908
    // 0x80800848: sb          $t2, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r10;
        goto L_80800908;
    // 0x80800848: sb          $t2, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r10;
L_8080084C:
    // 0x8080084C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1536, 0XC50) << 16);
    // 0x80800850: addiu       $a2, $a2, 0xC50
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1536, 0XC50));
    // 0x80800854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800858: jal         0x8008A1F8
    // 0x8080085C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_12;
    // 0x8080085C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_12:
    // 0x80800860: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800864: beq         $v0, $at, L_8080087C
    if (ctx->r2 == ctx->r1) {
        // 0x80800868: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080087C;
    }
    // 0x80800868: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080086C: beq         $v0, $at, L_808008C8
    if (ctx->r2 == ctx->r1) {
        // 0x80800870: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808008C8;
    }
    // 0x80800870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800874: b           L_80800900
    // 0x80800878: nop

        goto L_80800900;
    // 0x80800878: nop

L_8080087C:
    // 0x8080087C: jal         0x800DA544
    // 0x80800880: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    func_800DA544(rdram, ctx);
        goto after_13;
    // 0x80800880: addiu       $a0, $zero, 0xB9
    ctx->r4 = ADD32(0, 0XB9);
    after_13:
    // 0x80800884: jal         0x80800B5C
    // 0x80800888: addiu       $a0, $zero, 0x3CB
    ctx->r4 = ADD32(0, 0X3CB);
    func_80800B5C_chboggygirl(rdram, ctx);
        goto after_14;
    // 0x80800888: addiu       $a0, $zero, 0x3CB
    ctx->r4 = ADD32(0, 0X3CB);
    after_14:
    // 0x8080088C: beq         $v0, $zero, L_808008B8
    if (ctx->r2 == 0) {
        // 0x80800890: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_808008B8;
    }
    // 0x80800890: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80800894: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800898: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x8080089C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808008A0: addiu       $a1, $zero, 0x108E
    ctx->r5 = ADD32(0, 0X108E);
    // 0x808008A4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808008A8: jal         0x8008A208
    // 0x808008AC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_15;
    // 0x808008AC: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_15:
    // 0x808008B0: b           L_8080090C
    // 0x808008B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8080090C;
    // 0x808008B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008B8:
    // 0x808008B8: jal         0x800C01A8
    // 0x808008BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_16;
    // 0x808008BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x808008C0: jal         0x800C0850
    // 0x808008C4: nop

    func_800C0850(rdram, ctx);
        goto after_17;
    // 0x808008C4: nop

    after_17:
L_808008C8:
    // 0x808008C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808008CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808008D0: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x808008D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x808008DC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808008E0: jal         0x80102924
    // 0x808008E4: nop

    func_80102924(rdram, ctx);
        goto after_18;
    // 0x808008E4: nop

    after_18:
    // 0x808008E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008EC: jal         0x80102424
    // 0x808008F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80102424(rdram, ctx);
        goto after_19;
    // 0x808008F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_19:
    // 0x808008F4: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x808008F8: b           L_80800908
    // 0x808008FC: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
        goto L_80800908;
    // 0x808008FC: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
L_80800900:
    // 0x80800900: jal         0x80102424
    // 0x80800904: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80102424(rdram, ctx);
        goto after_20;
    // 0x80800904: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
L_80800908:
    // 0x80800908: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080090C:
    // 0x8080090C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800910: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800914: jr          $ra
    // 0x80800918: nop

    return;
    // 0x80800918: nop

;}
RECOMP_FUNC void badust_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080015C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800160: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800164: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800168: jal         0x80096544
    // 0x8080016C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80096544(rdram, ctx);
        goto after_0;
    // 0x8080016C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800170: beql        $v0, $zero, L_808001A4
    if (ctx->r2 == 0) {
        // 0x80800174: lw          $v0, 0x5C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X5C);
            goto L_808001A4;
    }
    goto skip_0;
    // 0x80800174: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
    skip_0:
    // 0x80800178: jal         0x800964DC
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800964DC(rdram, ctx);
        goto after_1;
    // 0x8080017C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800180: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800184: jal         0x8009C150
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009C150(rdram, ctx);
        goto after_2;
    // 0x80800188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080018C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800190: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800194: nop

    // 0x80800198: bc1tl       L_80800250
    if (c1cs) {
        // 0x8080019C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800250;
    }
    goto skip_1;
    // 0x8080019C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808001A0: lw          $v0, 0x5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X5C);
L_808001A4:
    // 0x808001A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x808001A8: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x808001AC: beql        $t6, $zero, L_808001C0
    if (ctx->r14 == 0) {
        // 0x808001B0: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_808001C0;
    }
    goto skip_2;
    // 0x808001B0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    skip_2:
    // 0x808001B4: b           L_808001C0
    // 0x808001B8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
        goto L_808001C0;
    // 0x808001B8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x808001BC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_808001C0:
    // 0x808001C0: jal         0x8009BB5C
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_3;
    // 0x808001C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001C8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x808001CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001D0: nop

    // 0x808001D4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x808001D8: nop

    // 0x808001DC: bc1fl       L_80800250
    if (!c1cs) {
        // 0x808001E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800250;
    }
    goto skip_3;
    // 0x808001E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x808001E4: lw          $t8, 0x5C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X5C);
    // 0x808001E8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x808001EC: beq         $t9, $zero, L_80800224
    if (ctx->r25 == 0) {
        // 0x808001F0: nop
    
            goto L_80800224;
    }
    // 0x808001F0: nop

    // 0x808001F4: jal         0x8009BB18
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_4;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808001FC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800200: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800208: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8080020C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800210: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800214: jal         0x80800424
    // 0x80800218: nop

    badust_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800218: nop

    after_5:
    // 0x8080021C: b           L_80800250
    // 0x80800220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800250;
    // 0x80800220: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800224:
    // 0x80800224: jal         0x8009BB18
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB18(rdram, ctx);
        goto after_6;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080022C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800230: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8080023C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800240: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80800244: jal         0x80800424
    // 0x80800248: nop

    badust_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800248: nop

    after_7:
    // 0x8080024C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800250:
    // 0x80800250: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800254: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800258: jr          $ra
    // 0x8080025C: nop

    return;
    // 0x8080025C: nop

;}
RECOMP_FUNC void bswalk_entrypoint_14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800DB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800DB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800DBC: jal         0x8008CABC
    // 0x80800DC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800DC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800DC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800DC8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80800DCC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80800DD0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80800DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DD8: jal         0x8009E710
    // 0x80800DDC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    bs_getPreviousState(rdram, ctx);
        goto after_1;
    // 0x80800DDC: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800DE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800DE4: beq         $v0, $at, L_80800E0C
    if (ctx->r2 == ctx->r1) {
        // 0x80800DE8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800E0C;
    }
    // 0x80800DE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800DEC: beq         $v0, $at, L_80800E0C
    if (ctx->r2 == ctx->r1) {
        // 0x80800DF0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800E0C;
    }
    // 0x80800DF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800DF4: beq         $v0, $at, L_80800E58
    if (ctx->r2 == ctx->r1) {
        // 0x80800DF8: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80800E58;
    }
    // 0x80800DF8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80800DFC: beq         $v0, $at, L_80800E50
    if (ctx->r2 == ctx->r1) {
        // 0x80800E00: nop
    
            goto L_80800E50;
    }
    // 0x80800E00: nop

    // 0x80800E04: b           L_80800E6C
    // 0x80800E08: nop

        goto L_80800E6C;
    // 0x80800E08: nop

L_80800E0C:
    // 0x80800E0C: jal         0x8009BB5C
    // 0x80800E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009BB5C(rdram, ctx);
        goto after_2;
    // 0x80800E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800E14: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800E18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800E1C: nop

    // 0x80800E20: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80800E24: nop

    // 0x80800E28: bc1f        L_80800E6C
    if (!c1cs) {
        // 0x80800E2C: nop
    
            goto L_80800E6C;
    }
    // 0x80800E2C: nop

    // 0x80800E30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800E38: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800E3C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800E40: jal         0x800849E0
    // 0x80800E44: nop

    _badust_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800E44: nop

    after_3:
    // 0x80800E48: b           L_80800E6C
    // 0x80800E4C: nop

        goto L_80800E6C;
    // 0x80800E4C: nop

L_80800E50:
    // 0x80800E50: b           L_80800E6C
    // 0x80800E54: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
        goto L_80800E6C;
    // 0x80800E54: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
L_80800E58:
    // 0x80800E58: jal         0x8008AEDC
    // 0x80800E5C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8008AEDC(rdram, ctx);
        goto after_4;
    // 0x80800E5C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x80800E60: jal         0x8008C0C8
    // 0x80800E64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8008C0C8(rdram, ctx);
        goto after_5;
    // 0x80800E64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800E68: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
L_80800E6C:
    // 0x80800E6C: jal         0x8008AF24
    // 0x80800E70: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_reset(rdram, ctx);
        goto after_6;
    // 0x80800E70: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80800E74: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800E78: jal         0x8008B1A0
    // 0x80800E7C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_7;
    // 0x80800E7C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80800E80: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800E84: jal         0x8008AED4
    // 0x80800E88: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    anctrl_setIndex(rdram, ctx);
        goto after_8;
    // 0x80800E88: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_8:
    // 0x80800E8C: lui         $a1, 0x3F28
    ctx->r5 = S32(0X3F28 << 16);
    // 0x80800E90: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x80800E94: jal         0x8008B1BC
    // 0x80800E98: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_setDuration(rdram, ctx);
        goto after_9;
    // 0x80800E98: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_9:
    // 0x80800E9C: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80800EA0: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800EA4: jal         0x8008B1C8
    // 0x80800EA8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_8008B1C8(rdram, ctx);
        goto after_10;
    // 0x80800EA8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_10:
    // 0x80800EAC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800EB0: jal         0x8008B24C
    // 0x80800EB4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    anctrl_setStart(rdram, ctx);
        goto after_11;
    // 0x80800EB4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_11:
    // 0x80800EB8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800EBC: jal         0x8008B134
    // 0x80800EC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_12;
    // 0x80800EC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x80800EC4: jal         0x8008B064
    // 0x80800EC8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    anctrl_start(rdram, ctx);
        goto after_13;
    // 0x80800EC8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_13:
    // 0x80800ECC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80800ED0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800ED8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800EDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800EE0: jal         0x8009FFD8
    // 0x80800EE4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_14;
    // 0x80800EE4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x80800EE8: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800EEC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF4: jal         0x8008C9BC
    // 0x80800EF8: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_15;
    // 0x80800EF8: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_15:
    // 0x80800EFC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(435, 0X1504) << 16);
    // 0x80800F00: lwc1        $f8, 0x1504($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0X1504));
    // 0x80800F04: lui         $a3, 0x3F0A
    ctx->r7 = S32(0X3F0A << 16);
    // 0x80800F08: ori         $a3, $a3, 0x3D71
    ctx->r7 = ctx->r7 | 0X3D71;
    // 0x80800F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F10: lui         $a1, 0x4361
    ctx->r5 = S32(0X4361 << 16);
    // 0x80800F14: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x80800F18: jal         0x8008C9F0
    // 0x80800F1C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_16;
    // 0x80800F1C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x80800F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F24: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800F28: jal         0x8009BFE4
    // 0x80800F2C: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    func_8009BFE4(rdram, ctx);
        goto after_17;
    // 0x80800F2C: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_17:
    // 0x80800F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F34: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80800F38: jal         0x8009C554
    // 0x80800F3C: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    baroll_setAngularVelocity(rdram, ctx);
        goto after_18;
    // 0x80800F3C: lui         $a2, 0x4140
    ctx->r6 = S32(0X4140 << 16);
    after_18:
    // 0x80800F40: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80800F44: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800F48: jal         0x808001D8
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001D8_bswalk(rdram, ctx);
        goto after_19;
    // 0x80800F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80800F50: jal         0x8009F1E0
    // 0x80800F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_resetZones(rdram, ctx);
        goto after_20;
    // 0x80800F54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800F58: jal         0x8008E0E8
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E0E8(rdram, ctx);
        goto after_21;
    // 0x80800F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800F60: beq         $v0, $zero, L_80800F70
    if (ctx->r2 == 0) {
        // 0x80800F64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800F70;
    }
    // 0x80800F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800F68: jal         0x80084788
    // 0x80800F6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _bapackctrl_entrypoint_5(rdram, ctx);
        goto after_22;
    // 0x80800F6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_22:
L_80800F70:
    // 0x80800F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800F74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800F78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800F7C: jr          $ra
    // 0x80800F80: nop

    return;
    // 0x80800F80: nop

;}
RECOMP_FUNC void func_800CF840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CF840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CF844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CF848: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800CF84C: jal         0x800CE83C
    // 0x800CF850: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800CE83C(rdram, ctx);
        goto after_0;
    // 0x800CF850: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800CF854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CF858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CF85C: jr          $ra
    // 0x800CF860: nop

    return;
    // 0x800CF860: nop

    // 0x800CF864: nop

    // 0x800CF868: nop

    // 0x800CF86C: nop

;}
RECOMP_FUNC void bsturn_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800334: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800338: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(420, 0X360) << 16);
    // 0x8080033C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800340: jr          $ra
    // 0x80800344: lw          $v0, 0x360($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(420, 0X360));
    return;
    // 0x80800344: lw          $v0, 0x360($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(420, 0X360));
    // 0x80800348: nop

    // 0x8080034C: nop

;}
RECOMP_FUNC void func_80022E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022E20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80022E24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80022E28: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80022E2C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80022E30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022E34: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80022E38: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80022E3C: beq         $t7, $zero, L_80022EB0
    if (ctx->r15 == 0) {
        // 0x80022E40: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_80022EB0;
    }
    // 0x80022E40: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80022E44:
    // 0x80022E44: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80022E48: lbu         $t0, 0x37($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X37);
    // 0x80022E4C: lbu         $t9, 0x35($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X35);
    // 0x80022E50: bne         $t9, $t0, L_80022EA0
    if (ctx->r25 != ctx->r8) {
        // 0x80022E54: nop
    
            goto L_80022EA0;
    }
    // 0x80022E54: nop

    // 0x80022E58: lbu         $t1, 0x38($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X38);
    // 0x80022E5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80022E60: beq         $t1, $at, L_80022EA0
    if (ctx->r9 == ctx->r1) {
        // 0x80022E64: nop
    
            goto L_80022EA0;
    }
    // 0x80022E64: nop

    // 0x80022E68: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80022E6C: jal         0x80029D54
    // 0x80022E70: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_80029D54(rdram, ctx);
        goto after_0;
    // 0x80022E70: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80022E74: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x80022E78: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80022E7C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80022E80: jal         0x80029F5C
    // 0x80022E84: lw          $a1, 0x1C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X1C);
    func_80029F5C(rdram, ctx);
        goto after_1;
    // 0x80022E84: lw          $a1, 0x1C($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X1C);
    after_1:
    // 0x80022E88: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80022E8C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80022E90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80022E94: lh          $a1, 0x2A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X2A);
    // 0x80022E98: jal         0x80026BE0
    // 0x80022E9C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_80026BE0(rdram, ctx);
        goto after_2;
    // 0x80022E9C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_2:
L_80022EA0:
    // 0x80022EA0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80022EA4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80022EA8: bne         $t4, $zero, L_80022E44
    if (ctx->r12 != 0) {
        // 0x80022EAC: sw          $t4, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r12;
            goto L_80022E44;
    }
    // 0x80022EAC: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_80022EB0:
    // 0x80022EB0: b           L_80022EB8
    // 0x80022EB4: nop

        goto L_80022EB8;
    // 0x80022EB4: nop

L_80022EB8:
    // 0x80022EB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022EBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022EC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80022EC4: jr          $ra
    // 0x80022EC8: nop

    return;
    // 0x80022EC8: nop

;}
RECOMP_FUNC void babounce_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800504: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080050C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800510: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80800514: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800518: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080051C: lbu         $v0, 0xC($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0XC);
    // 0x80800520: beq         $v0, $at, L_808005C4
    if (ctx->r2 == ctx->r1) {
        // 0x80800524: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808005C4;
    }
    // 0x80800524: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800528: beq         $v0, $at, L_80800590
    if (ctx->r2 == ctx->r1) {
        // 0x8080052C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800590;
    }
    // 0x8080052C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800530: bnel        $v0, $at, L_808005D0
    if (ctx->r2 != ctx->r1) {
        // 0x80800534: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808005D0;
    }
    goto skip_0;
    // 0x80800534: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80800538: jal         0x800852F0
    // 0x8080053C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _batimer_decrement(rdram, ctx);
        goto after_0;
    // 0x8080053C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80800540: beq         $v0, $zero, L_80800588
    if (ctx->r2 == 0) {
        // 0x80800544: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800588;
    }
    // 0x80800544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800548: jal         0x8009BB24
    // 0x8080054C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_1;
    // 0x8080054C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80800550: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800558: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8080055C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80800560: jal         0x8009BA9C
    // 0x80800564: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_8009BA9C(rdram, ctx);
        goto after_2;
    // 0x80800564: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80800568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080056C: jal         0x8009B9B0
    // 0x80800570: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800570: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: jal         0x80800008
    // 0x8080057C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800008_babounce(rdram, ctx);
        goto after_4;
    // 0x8080057C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800580: b           L_808005D0
    // 0x80800584: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005D0;
    // 0x80800584: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800588:
    // 0x80800588: b           L_808005D0
    // 0x8080058C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005D0;
    // 0x8080058C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800590:
    // 0x80800590: jal         0x8008E078
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_5;
    // 0x80800594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800598: beq         $v0, $zero, L_808005BC
    if (ctx->r2 == 0) {
        // 0x8080059C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808005BC;
    }
    // 0x8080059C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005A0: jal         0x8009B9B0
    // 0x808005A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_6;
    // 0x808005A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_6:
    // 0x808005A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005AC: jal         0x80800008
    // 0x808005B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80800008_babounce(rdram, ctx);
        goto after_7;
    // 0x808005B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808005B4: b           L_808005D0
    // 0x808005B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808005D0;
    // 0x808005B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005BC:
    // 0x808005BC: b           L_808005D0
    // 0x808005C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808005D0;
    // 0x808005C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005C4:
    // 0x808005C4: b           L_808005D0
    // 0x808005C8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_808005D0;
    // 0x808005C8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x808005CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005D0:
    // 0x808005D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808005D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005D8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808005DC: jr          $ra
    // 0x808005E0: nop

    return;
    // 0x808005E0: nop

;}
RECOMP_FUNC void chskeletonexplode_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C70: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800C74: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80800C78: swc1        $f12, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f12.u32l;
    // 0x80800C7C: jr          $ra
    // 0x80800C80: swc1        $f14, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x80800C80: swc1        $f14, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void _chpickups_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085878: syscall     177
    recomp_syscall_handler(rdram, ctx, 0x80085878);
    return;
    // 0x8008587C: addi        $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
;}
RECOMP_FUNC void func_808013C0_ncpoddialog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013C0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808013C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808013C8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808013CC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808013D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808013D4: jal         0x808006D4
    // 0x808013D8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    func_808006D4_ncpoddialog(rdram, ctx);
        goto after_0;
    // 0x808013D8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    after_0:
    // 0x808013DC: beq         $v0, $zero, L_8080145C
    if (ctx->r2 == 0) {
        // 0x808013E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080145C;
    }
    // 0x808013E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808013E8: jal         0x80800000
    // 0x808013EC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_80800000_ncpoddialog(rdram, ctx);
        goto after_1;
    // 0x808013EC: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x808013F0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808013F4: jal         0x800EE7F8
    // 0x808013F8: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x808013F8: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    after_2:
    // 0x808013FC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801400: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801404: lui         $a3, 0x86
    ctx->r7 = S32(0X86 << 16);
    // 0x80801408: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x8080140C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801410: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80801414: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80801418: jal         0x800BF340
    // 0x8080141C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800BF340(rdram, ctx);
        goto after_3;
    // 0x8080141C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80801420: beq         $v0, $zero, L_80801430
    if (ctx->r2 == 0) {
        // 0x80801424: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_80801430;
    }
    // 0x80801424: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80801428: b           L_8080145C
    // 0x8080142C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_8080145C;
    // 0x8080142C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80801430:
    // 0x80801430: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801434: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801438: lui         $a3, 0x86
    ctx->r7 = S32(0X86 << 16);
    // 0x8080143C: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x80801440: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80801444: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80801448: jal         0x800BF340
    // 0x8080144C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800BF340(rdram, ctx);
        goto after_4;
    // 0x8080144C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80801450: beq         $v0, $zero, L_8080145C
    if (ctx->r2 == 0) {
        // 0x80801454: nop
    
            goto L_8080145C;
    }
    // 0x80801454: nop

    // 0x80801458: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8080145C:
    // 0x8080145C: jal         0x80800698
    // 0x80801460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800698_ncpoddialog(rdram, ctx);
        goto after_5;
    // 0x80801460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801464: beq         $v0, $zero, L_808014EC
    if (ctx->r2 == 0) {
        // 0x80801468: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808014EC;
    }
    // 0x80801468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080146C: addiu       $t6, $s0, 0xC4
    ctx->r14 = ADD32(ctx->r16, 0XC4);
    // 0x80801470: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80801474: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801478: jal         0x80800000
    // 0x8080147C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_80800000_ncpoddialog(rdram, ctx);
        goto after_6;
    // 0x8080147C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x80801480: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80801484: jal         0x800EE7F8
    // 0x80801488: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80801488: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x8080148C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80801490: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80801494: lui         $a3, 0x86
    ctx->r7 = S32(0X86 << 16);
    // 0x80801498: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x8080149C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x808014A0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x808014A4: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x808014A8: jal         0x800BF340
    // 0x808014AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800BF340(rdram, ctx);
        goto after_8;
    // 0x808014AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x808014B0: beq         $v0, $zero, L_808014C0
    if (ctx->r2 == 0) {
        // 0x808014B4: addiu       $a0, $sp, 0x40
        ctx->r4 = ADD32(ctx->r29, 0X40);
            goto L_808014C0;
    }
    // 0x808014B4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808014B8: b           L_808014EC
    // 0x808014BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_808014EC;
    // 0x808014BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_808014C0:
    // 0x808014C0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808014C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808014C8: lui         $a3, 0x86
    ctx->r7 = S32(0X86 << 16);
    // 0x808014CC: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x808014D0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x808014D4: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x808014D8: jal         0x800BF340
    // 0x808014DC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_800BF340(rdram, ctx);
        goto after_9;
    // 0x808014DC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x808014E0: beql        $v0, $zero, L_808014F0
    if (ctx->r2 == 0) {
        // 0x808014E4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808014F0;
    }
    goto skip_0;
    // 0x808014E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808014E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_808014EC:
    // 0x808014EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808014F0:
    // 0x808014F0: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x808014F4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808014F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808014FC: jr          $ra
    // 0x80801500: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80801500: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80800200_bsvanswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800200: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800204: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800208: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080020C: jal         0x80084128
    // 0x80800210: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _bsvan_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800210: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800218: jal         0x8009BCB4
    // 0x8080021C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_gravity(rdram, ctx);
        goto after_1;
    // 0x8080021C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800220: lui         $a1, 0xC3C7
    ctx->r5 = S32(0XC3C7 << 16);
    // 0x80800224: ori         $a1, $a1, 0xFEB8
    ctx->r5 = ctx->r5 | 0XFEB8;
    // 0x80800228: jal         0x8009BCC4
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_terminal_velocity(rdram, ctx);
        goto after_2;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800234: jal         0x800961AC
    // 0x80800238: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800961AC(rdram, ctx);
        goto after_3;
    // 0x80800238: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_3:
    // 0x8080023C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800240: jal         0x8009BC5C
    // 0x80800244: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_8009BC5C(rdram, ctx);
        goto after_4;
    // 0x80800244: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_4:
    // 0x80800248: jal         0x800A046C
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A046C(rdram, ctx);
        goto after_5;
    // 0x8080024C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800250: jal         0x800A3298
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A3298(rdram, ctx);
        goto after_6;
    // 0x80800254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800258: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8080025C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800260: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x80800264: jal         0x8008CB3C
    // 0x80800268: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_7;
    // 0x80800268: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_7:
    // 0x8080026C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800270: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80800274: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x80800278: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080027C: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800280: lui         $a2, 0x447A
    ctx->r6 = S32(0X447A << 16);
    // 0x80800284: lui         $a3, 0xC396
    ctx->r7 = S32(0XC396 << 16);
    // 0x80800288: jal         0x800F10B4
    // 0x8080028C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_8;
    // 0x8080028C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80800290: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800294: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
    // 0x80800298: jal         0x8009BA58
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_set_vertical_velocity(rdram, ctx);
        goto after_9;
    // 0x8080029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x808002A0: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x808002A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808002B4: jal         0x8009FFD8
    // 0x808002B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_10;
    // 0x808002B8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_10:
    // 0x808002BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808002C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808002C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002C8: jr          $ra
    // 0x808002CC: nop

    return;
    // 0x808002CC: nop

;}
RECOMP_FUNC void _chfactoryrobot_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086220: syscall     291
    recomp_syscall_handler(rdram, ctx, 0x80086220);
    return;
    // 0x80086224: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8080115C_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080115C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801160: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801164: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801168: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080116C: jal         0x80100094
    // 0x80801170: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801170: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801174: jal         0x800DC0C0
    // 0x80801178: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x80801178: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080117C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80801180: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80801184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801188: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8080118C: nop

    // 0x80801190: bc1f        L_808011A0
    if (!c1cs) {
        // 0x80801194: nop
    
            goto L_808011A0;
    }
    // 0x80801194: nop

    // 0x80801198: jal         0x80801D3C
    // 0x8080119C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801D3C_chchuffy(rdram, ctx);
        goto after_2;
    // 0x8080119C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
L_808011A0:
    // 0x808011A0: jal         0x80801F04
    // 0x808011A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801F04_chchuffy(rdram, ctx);
        goto after_3;
    // 0x808011A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808011A8: jal         0x8080059C
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080059C_chchuffy(rdram, ctx);
        goto after_4;
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808011B0: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x808011B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808011B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011BC: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808011C0: beq         $t7, $at, L_808012F8
    if (ctx->r15 == ctx->r1) {
        // 0x808011C4: lui         $a1, 0x3E57
        ctx->r5 = S32(0X3E57 << 16);
            goto L_808012F8;
    }
    // 0x808011C4: lui         $a1, 0x3E57
    ctx->r5 = S32(0X3E57 << 16);
    // 0x808011C8: lui         $a2, 0x3E9E
    ctx->r6 = S32(0X3E9E << 16);
    // 0x808011CC: ori         $a2, $a2, 0xB852
    ctx->r6 = ctx->r6 | 0XB852;
    // 0x808011D0: jal         0x80102320
    // 0x808011D4: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    func_80102320(rdram, ctx);
        goto after_5;
    // 0x808011D4: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    after_5:
    // 0x808011D8: beq         $v0, $zero, L_808011E8
    if (ctx->r2 == 0) {
        // 0x808011DC: nop
    
            goto L_808011E8;
    }
    // 0x808011DC: nop

    // 0x808011E0: jal         0x80801EAC
    // 0x808011E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801EAC_chchuffy(rdram, ctx);
        goto after_6;
    // 0x808011E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_808011E8:
    // 0x808011E8: jal         0x80801DDC
    // 0x808011EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80801DDC_chchuffy(rdram, ctx);
        goto after_7;
    // 0x808011EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808011F0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1700, 0X24FC) << 16);
    // 0x808011F4: addiu       $a1, $a1, 0x24FC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1700, 0X24FC));
    // 0x808011F8: jal         0x80101E4C
    // 0x808011FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_8;
    // 0x808011FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80801200: beq         $v0, $zero, L_80801238
    if (ctx->r2 == 0) {
        // 0x80801204: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801238;
    }
    // 0x80801204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801208: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080120C: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X238C) << 16);
    // 0x80801210: addiu       $a2, $a2, 0x238C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X238C));
    // 0x80801214: jal         0x80089D18
    // 0x80801218: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x80801218: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_9:
    // 0x8080121C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801220: jal         0x80801D94
    // 0x80801224: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801D94_chchuffy(rdram, ctx);
        goto after_10;
    // 0x80801224: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_10:
    // 0x80801228: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1700, 0X2314) << 16);
    // 0x8080122C: lwc1        $f6, 0x2314($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1700, 0X2314));
    // 0x80801230: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80801234: swc1        $f6, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f6.u32l;
L_80801238:
    // 0x80801238: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1700, 0X2534) << 16);
    // 0x8080123C: addiu       $a1, $a1, 0x2534
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1700, 0X2534));
    // 0x80801240: jal         0x80101E4C
    // 0x80801244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_11;
    // 0x80801244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801248: beq         $v0, $zero, L_80801264
    if (ctx->r2 == 0) {
        // 0x8080124C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801264;
    }
    // 0x8080124C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801250: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80801254: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X238C) << 16);
    // 0x80801258: addiu       $a2, $a2, 0x238C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X238C));
    // 0x8080125C: jal         0x80089D18
    // 0x80801260: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_12;
    // 0x80801260: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_12:
L_80801264:
    // 0x80801264: lui         $a1, 0x3CA3
    ctx->r5 = S32(0X3CA3 << 16);
    // 0x80801268: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x8080126C: jal         0x80101E14
    // 0x80801270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_13;
    // 0x80801270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80801274: bne         $v0, $zero, L_80801290
    if (ctx->r2 != 0) {
        // 0x80801278: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80801290;
    }
    // 0x80801278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080127C: lui         $a1, 0x3D0F
    ctx->r5 = S32(0X3D0F << 16);
    // 0x80801280: jal         0x80101E14
    // 0x80801284: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    func_80101E14(rdram, ctx);
        goto after_14;
    // 0x80801284: ori         $a1, $a1, 0x5C29
    ctx->r5 = ctx->r5 | 0X5C29;
    after_14:
    // 0x80801288: beql        $v0, $zero, L_808012B8
    if (ctx->r2 == 0) {
        // 0x8080128C: lui         $a1, 0x3F17
        ctx->r5 = S32(0X3F17 << 16);
            goto L_808012B8;
    }
    goto skip_0;
    // 0x8080128C: lui         $a1, 0x3F17
    ctx->r5 = S32(0X3F17 << 16);
    skip_0:
L_80801290:
    // 0x80801290: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80801294: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X23A0) << 16);
    // 0x80801298: addiu       $a2, $a2, 0x23A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X23A0));
    // 0x8080129C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012A0: jal         0x80089D18
    // 0x808012A4: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_15;
    // 0x808012A4: addiu       $a1, $a1, 0x2C
    ctx->r5 = ADD32(ctx->r5, 0X2C);
    after_15:
    // 0x808012A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012AC: jal         0x80801CF8
    // 0x808012B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80801CF8_chchuffy(rdram, ctx);
        goto after_16;
    // 0x808012B0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_16:
    // 0x808012B4: lui         $a1, 0x3F17
    ctx->r5 = S32(0X3F17 << 16);
L_808012B8:
    // 0x808012B8: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    // 0x808012BC: jal         0x80101E14
    // 0x808012C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E14(rdram, ctx);
        goto after_17;
    // 0x808012C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808012C4: bne         $v0, $zero, L_808012E0
    if (ctx->r2 != 0) {
        // 0x808012C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808012E0;
    }
    // 0x808012C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012CC: lui         $a1, 0x3EFA
    ctx->r5 = S32(0X3EFA << 16);
    // 0x808012D0: jal         0x80101E14
    // 0x808012D4: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    func_80101E14(rdram, ctx);
        goto after_18;
    // 0x808012D4: ori         $a1, $a1, 0xE148
    ctx->r5 = ctx->r5 | 0XE148;
    after_18:
    // 0x808012D8: beql        $v0, $zero, L_808012FC
    if (ctx->r2 == 0) {
        // 0x808012DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808012FC;
    }
    goto skip_1;
    // 0x808012DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_808012E0:
    // 0x808012E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808012E4: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1700, 0X23C8) << 16);
    // 0x808012E8: addiu       $a2, $a2, 0x23C8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1700, 0X23C8));
    // 0x808012EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808012F0: jal         0x80089D18
    // 0x808012F4: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_19;
    // 0x808012F4: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    after_19:
L_808012F8:
    // 0x808012F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808012FC:
    // 0x808012FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801300: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801304: jr          $ra
    // 0x80801308: nop

    return;
    // 0x80801308: nop

;}
RECOMP_FUNC void func_808001E8_chhotwatersteam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001F0: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x808001F4: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x808001F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x808001FC: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800200: bne         $t7, $at, L_8080021C
    if (ctx->r15 != ctx->r1) {
        // 0x80800204: nop
    
            goto L_8080021C;
    }
    // 0x80800204: nop

    // 0x80800208: jal         0x800DA298
    // 0x8080020C: addiu       $a0, $zero, 0x31B
    ctx->r4 = ADD32(0, 0X31B);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080020C: addiu       $a0, $zero, 0x31B
    ctx->r4 = ADD32(0, 0X31B);
    after_0:
    // 0x80800210: sltiu       $t8, $v0, 0x1
    ctx->r24 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80800214: b           L_8080021C
    // 0x80800218: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8080021C;
    // 0x80800218: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8080021C:
    // 0x8080021C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800220: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800224: jr          $ra
    // 0x80800228: nop

    return;
    // 0x80800228: nop

    // 0x8080022C: nop

;}
RECOMP_FUNC void func_80800910_chmineprospector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800910: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800914: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080091C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80800920: jal         0x80088078
    // 0x80800924: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    _gcdialogcamera_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800924: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80800928: beq         $v0, $zero, L_8080095C
    if (ctx->r2 == 0) {
        // 0x8080092C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8080095C;
    }
    // 0x8080092C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800930: jal         0x80100094
    // 0x80800934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x80800934: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800938: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8080093C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800940: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800944: beq         $t6, $at, L_80800954
    if (ctx->r14 == ctx->r1) {
        // 0x80800948: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80800954;
    }
    // 0x80800948: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080094C: jal         0x808009B0
    // 0x80800950: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_808009B0_chmineprospector(rdram, ctx);
        goto after_2;
    // 0x80800950: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_80800954:
    // 0x80800954: b           L_80800960
    // 0x80800958: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800960;
    // 0x80800958: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8080095C:
    // 0x8080095C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800960:
    // 0x80800960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800964: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800968: jr          $ra
    // 0x8080096C: nop

    return;
    // 0x8080096C: nop

;}
RECOMP_FUNC void gcmapsects_lagoonbot_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8080000C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80800010: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800014: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80800018: jal         0x80087F50
    // 0x8080001C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    _gcmapsects_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x8080001C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80800020: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2622, 0X230) << 16);
    // 0x80800024: lui         $s3, 0x8080
    ctx->r19 = S32(RELOC_HI16(2622, 0X23C) << 16);
    // 0x80800028: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2622, 0X248) << 16);
    // 0x8080002C: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(2622, 0X2F8) << 16);
    // 0x80800030: addiu       $s2, $s2, 0x2F8
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(2622, 0X2F8));
    // 0x80800034: addiu       $s1, $s1, 0x248
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2622, 0X248));
    // 0x80800038: addiu       $s3, $s3, 0x23C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(2622, 0X23C));
    // 0x8080003C: addiu       $s0, $s0, 0x230
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2622, 0X230));
L_80800040:
    // 0x80800040: lh          $t6, 0x24($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X24);
    // 0x80800044: lh          $a0, 0x26($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X26);
    // 0x80800048: lh          $a1, 0x28($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X28);
    // 0x8080004C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800050: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80800054: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80800058: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080005C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80800060: jal         0x80087F00
    // 0x80800064: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    _gcmapsects_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800064: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80800068: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x8080006C: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80800070: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // 0x80800074: bne         $at, $zero, L_80800040
    if (ctx->r1 != 0) {
        // 0x80800078: addiu       $s3, $s3, 0x2C
        ctx->r19 = ADD32(ctx->r19, 0X2C);
            goto L_80800040;
    }
    // 0x80800078: addiu       $s3, $s3, 0x2C
    ctx->r19 = ADD32(ctx->r19, 0X2C);
    // 0x8080007C: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2622, 0X2E0) << 16);
    // 0x80800080: addiu       $s0, $s0, 0x2E0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2622, 0X2E0));
    // 0x80800084: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80800088:
    // 0x80800088: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8080008C: jal         0x80087F18
    // 0x80800090: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    _gcmapsects_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800090: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    after_2:
    // 0x80800094: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80800098: sltiu       $at, $s2, 0x3
    ctx->r1 = ctx->r18 < 0X3 ? 1 : 0;
    // 0x8080009C: bne         $at, $zero, L_80800088
    if (ctx->r1 != 0) {
        // 0x808000A0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80800088;
    }
    // 0x808000A0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808000A4: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(2622, 0X2EC) << 16);
    // 0x808000A8: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(2622, 0X2F4) << 16);
    // 0x808000AC: addiu       $s1, $s1, 0x2F4
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(2622, 0X2F4));
    // 0x808000B0: addiu       $s0, $s0, 0x2EC
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(2622, 0X2EC));
    // 0x808000B4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_808000B8:
    // 0x808000B8: jal         0x80087F08
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcmapsects_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x808000BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808000C0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x808000C4: jal         0x80087F10
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcmapsects_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808000C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808000CC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x808000D0: bnel        $s0, $s1, L_808000B8
    if (ctx->r16 != ctx->r17) {
        // 0x808000D4: lh          $a0, 0x0($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X0);
            goto L_808000B8;
    }
    goto skip_0;
    // 0x808000D4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    skip_0:
    // 0x808000D8: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x808000DC: jal         0x80087F60
    // 0x808000E0: addiu       $a0, $a0, -0x7FF8
    ctx->r4 = ADD32(ctx->r4, -0X7FF8);
    _gcmapsects_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x808000E0: addiu       $a0, $a0, -0x7FF8
    ctx->r4 = ADD32(ctx->r4, -0X7FF8);
    after_5:
    // 0x808000E4: jal         0x80087F70
    // 0x808000E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    _gcmapsects_entrypoint_14(rdram, ctx);
        goto after_6;
    // 0x808000E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x808000EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808000F0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808000F4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808000F8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x808000FC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80800100: jr          $ra
    // 0x80800104: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800104: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800C9C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9C70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C9C74: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C9C78: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C9C7C: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800C9C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9C84: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800C9C88: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x800C9C8C: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x800C9C90: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x800C9C94: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800C9C98: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800C9C9C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x800C9CA0: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800C9CA4: jal         0x800EE7F8
    // 0x800C9CA8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800C9CA8: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800C9CAC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800C9CB0: addiu       $a1, $a1, -0x6610
    ctx->r5 = ADD32(ctx->r5, -0X6610);
    // 0x800C9CB4: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C9CB8: jal         0x800C9EF8
    // 0x800C9CBC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_800C9EF8(rdram, ctx);
        goto after_1;
    // 0x800C9CBC: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x800C9CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9CC4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800C9CC8: jr          $ra
    // 0x800C9CCC: nop

    return;
    // 0x800C9CCC: nop

;}
RECOMP_FUNC void _bafly_entrypoint_20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C68: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C68);
    return;
    // 0x80084C6C: addi        $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
;}
RECOMP_FUNC void func_8010A828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A828: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8010A82C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x8010A830: andi        $t8, $t7, 0x1FE
    ctx->r24 = ctx->r15 & 0X1FE;
    // 0x8010A834: lhu         $t9, 0x2A($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2A);
    // 0x8010A838: andi        $t0, $t9, 0xFE01
    ctx->r8 = ctx->r25 & 0XFE01;
    // 0x8010A83C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8010A840: jr          $ra
    // 0x8010A844: sh          $t1, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r9;
    return;
    // 0x8010A844: sh          $t1, 0x2A($v0)
    MEM_H(0X2A, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void func_80801C50_changlerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C58: jal         0x80100094
    // 0x80801C5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801C5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801C60: lbu         $t6, 0x1B($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1B);
    // 0x80801C64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801C68: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801C6C: beq         $a1, $t6, L_80801C78
    if (ctx->r5 == ctx->r14) {
        // 0x80801C70: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80801C78;
    }
    // 0x80801C70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801C74: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80801C78:
    // 0x80801C78: lbu         $t7, 0x1C($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1C);
    // 0x80801C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801C80: addu        $a0, $v0, $a1
    ctx->r4 = ADD32(ctx->r2, ctx->r5);
    // 0x80801C84: beq         $a1, $t7, L_80801C90
    if (ctx->r5 == ctx->r15) {
        // 0x80801C88: addiu       $sp, $sp, 0x18
        ctx->r29 = ADD32(ctx->r29, 0X18);
            goto L_80801C90;
    }
    // 0x80801C88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C8C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80801C90:
    // 0x80801C90: lbu         $t8, 0x1B($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1B);
    // 0x80801C94: beql        $a1, $t8, L_80801CA4
    if (ctx->r5 == ctx->r24) {
        // 0x80801C98: lbu         $t9, 0x1C($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X1C);
            goto L_80801CA4;
    }
    goto skip_0;
    // 0x80801C98: lbu         $t9, 0x1C($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1C);
    skip_0:
    // 0x80801C9C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80801CA0: lbu         $t9, 0x1C($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1C);
L_80801CA4:
    // 0x80801CA4: beql        $a1, $t9, L_80801CB4
    if (ctx->r5 == ctx->r25) {
        // 0x80801CA8: lbu         $t0, 0x1D($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X1D);
            goto L_80801CB4;
    }
    goto skip_1;
    // 0x80801CA8: lbu         $t0, 0x1D($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1D);
    skip_1:
    // 0x80801CAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80801CB0: lbu         $t0, 0x1D($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X1D);
L_80801CB4:
    // 0x80801CB4: beql        $a1, $t0, L_80801CC4
    if (ctx->r5 == ctx->r8) {
        // 0x80801CB8: lbu         $t1, 0x1E($a0)
        ctx->r9 = MEM_BU(ctx->r4, 0X1E);
            goto L_80801CC4;
    }
    goto skip_2;
    // 0x80801CB8: lbu         $t1, 0x1E($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X1E);
    skip_2:
    // 0x80801CBC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80801CC0: lbu         $t1, 0x1E($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X1E);
L_80801CC4:
    // 0x80801CC4: beq         $a1, $t1, L_80801CD0
    if (ctx->r5 == ctx->r9) {
        // 0x80801CC8: nop
    
            goto L_80801CD0;
    }
    // 0x80801CC8: nop

    // 0x80801CCC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80801CD0:
    // 0x80801CD0: jr          $ra
    // 0x80801CD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80801CD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800F7814(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7814: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7818: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F781C: lui         $a3, 0xC4BB
    ctx->r7 = S32(0XC4BB << 16);
    // 0x800F7820: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800F7824: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800F7828: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x800F782C: jal         0x800F7750
    // 0x800F7830: lui         $a2, 0x4452
    ctx->r6 = S32(0X4452 << 16);
    func_800F7750(rdram, ctx);
        goto after_0;
    // 0x800F7830: lui         $a2, 0x4452
    ctx->r6 = S32(0X4452 << 16);
    after_0:
    // 0x800F7834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7838: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F783C: jr          $ra
    // 0x800F7840: nop

    return;
    // 0x800F7840: nop

;}
RECOMP_FUNC void func_8080040C_chstatuebossbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080040C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800410: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800414: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800418: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8080041C: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x80800420: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800428: bne         $t6, $zero, L_80800438
    if (ctx->r14 != 0) {
        // 0x8080042C: nop
    
            goto L_80800438;
    }
    // 0x8080042C: nop

    // 0x80800430: b           L_80800438
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800438;
    // 0x80800434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800438:
    // 0x80800438: jal         0x800DF744
    // 0x8080043C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_0;
    // 0x8080043C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800440: lw          $t7, 0x54($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X54);
    // 0x80800444: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080044C: bne         $t7, $at, L_8080045C
    if (ctx->r15 != ctx->r1) {
        // 0x80800450: nop
    
            goto L_8080045C;
    }
    // 0x80800450: nop

    // 0x80800454: b           L_8080045C
    // 0x80800458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8080045C;
    // 0x80800458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8080045C:
    // 0x8080045C: jal         0x800DF744
    // 0x80800460: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800460: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80800464: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x80800468: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080046C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800470: bne         $t8, $at, L_80800480
    if (ctx->r24 != ctx->r1) {
        // 0x80800474: nop
    
            goto L_80800480;
    }
    // 0x80800474: nop

    // 0x80800478: b           L_80800480
    // 0x8080047C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800480;
    // 0x8080047C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800480:
    // 0x80800480: jal         0x800DF744
    // 0x80800484: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800484: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x80800488: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x8080048C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800490: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800494: bne         $t9, $at, L_808004A4
    if (ctx->r25 != ctx->r1) {
        // 0x80800498: nop
    
            goto L_808004A4;
    }
    // 0x80800498: nop

    // 0x8080049C: b           L_808004A4
    // 0x808004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_808004A4;
    // 0x808004A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_808004A4:
    // 0x808004A4: jal         0x800DF744
    // 0x808004A8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x808004A8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_3:
    // 0x808004AC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x808004B0: jal         0x800DF744
    // 0x808004B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x808004B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004BC: jal         0x80101870
    // 0x808004C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80101870(rdram, ctx);
        goto after_5;
    // 0x808004C0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x808004C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808004CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004D0: jr          $ra
    // 0x808004D4: nop

    return;
    // 0x808004D4: nop

;}
RECOMP_FUNC void func_800C524C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C524C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C5250: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C5254: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C5258: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C525C: jal         0x800A89A0
    // 0x800C5260: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    func_800A89A0(rdram, ctx);
        goto after_0;
    // 0x800C5260: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C5264: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800C5268: jal         0x800A8984
    // 0x800C526C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A8984(rdram, ctx);
        goto after_1;
    // 0x800C526C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C5270: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x800C5274: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800C5278: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C527C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C5280: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800C5284: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x800C5288: jal         0x800A8A44
    // 0x800C528C: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    func_800A8A44(rdram, ctx);
        goto after_2;
    // 0x800C528C: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x800C5290: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x800C5294: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800C5298: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800C529C: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800C52A0: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800C52A4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C52A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800C52AC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800C52B0: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800C52B4: jal         0x80015B34
    // 0x800C52B8: addu        $a2, $t7, $v0
    ctx->r6 = ADD32(ctx->r15, ctx->r2);
    func_80015B34(rdram, ctx);
        goto after_3;
    // 0x800C52B8: addu        $a2, $t7, $v0
    ctx->r6 = ADD32(ctx->r15, ctx->r2);
    after_3:
    // 0x800C52BC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800C52C0: jal         0x80015CE8
    // 0x800C52C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_80015CE8(rdram, ctx);
        goto after_4;
    // 0x800C52C4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x800C52C8: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800C52CC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C52D0: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x800C52D4: lw          $a1, -0x5610($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5610);
    // 0x800C52D8: jal         0x800C5148
    // 0x800C52DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800C5148(rdram, ctx);
        goto after_5;
    // 0x800C52DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800C52E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C52E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C52E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800C52EC: jr          $ra
    // 0x800C52F0: nop

    return;
    // 0x800C52F0: nop

;}
RECOMP_FUNC void _badrone_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800847E8: syscall     122
    recomp_syscall_handler(rdram, ctx, 0x800847E8);
    return;
    // 0x800847EC: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void func_8080079C_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080079C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808007A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808007AC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808007B0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808007B4: jal         0x80100094
    // 0x808007B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808007B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808007BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808007C0: jal         0x80800734
    // 0x808007C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800734_chclockworkmouse(rdram, ctx);
        goto after_1;
    // 0x808007C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808007C8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x808007CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808007D0: bnel        $t6, $zero, L_808007E0
    if (ctx->r14 != 0) {
        // 0x808007D4: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_808007E0;
    }
    goto skip_0;
    // 0x808007D4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808007D8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x808007DC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
L_808007E0:
    // 0x808007E0: lbu         $t8, 0xFA($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XFA);
    // 0x808007E4: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x808007E8: beq         $at, $zero, L_80800840
    if (ctx->r1 == 0) {
        // 0x808007EC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800840;
    }
    // 0x808007EC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x808007F0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1564, 0X3680) << 16);
    // 0x808007F4: addu        $at, $at, $t8
    gpr jr_addend_808007FC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x808007F8: lw          $t8, 0x3680($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1564, 0X3680));
    // 0x808007FC: jr          $t8
    // 0x80800800: nop

    switch (jr_addend_808007FC >> 2) {
        case 0: goto L_80800804; break;
        case 1: goto L_8080080C; break;
        case 2: goto L_80800834; break;
        case 3: goto L_8080080C; break;
        case 4: goto L_8080080C; break;
        default: switch_error(__func__, 0x808007FC, 0x80803680);
    }
    // 0x80800800: nop

L_80800804:
    // 0x80800804: jal         0x80800700
    // 0x80800808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800700_chclockworkmouse(rdram, ctx);
        goto after_2;
    // 0x80800808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_8080080C:
    // 0x8080080C: jal         0x800856E0
    // 0x80800810: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _capod_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x80800810: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80800814: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80800818: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8080081C: sb          $t9, 0xFA($t0)
    MEM_B(0XFA, ctx->r8) = ctx->r25;
    // 0x80800820: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80800824: jal         0x800880A8
    // 0x80800828: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    _gcdialogcamera_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800828: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_4:
    // 0x8080082C: jal         0x800880B8
    // 0x80800830: nop

    _gcdialogcamera_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x80800830: nop

    after_5:
L_80800834:
    // 0x80800834: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800838: jal         0x800856D8
    // 0x8080083C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _capod_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x8080083C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
L_80800840:
    // 0x80800840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800844: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800848: jr          $ra
    // 0x8080084C: nop

    return;
    // 0x8080084C: nop

;}
RECOMP_FUNC void _bsclimb_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F10: syscall     34
    recomp_syscall_handler(rdram, ctx, 0x80082F10);
    return;
    // 0x80082F14: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void func_80800288_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800288: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080028C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800290: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800294: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800298: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080029C: jal         0x800852C0
    // 0x808002A0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    _baswim_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808002A0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_0:
    // 0x808002A4: jal         0x800852C8
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_12(rdram, ctx);
        goto after_1;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808002AC: jal         0x800852D0
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_13(rdram, ctx);
        goto after_2;
    // 0x808002B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002B4: jal         0x8008E23C
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E23C(rdram, ctx);
        goto after_3;
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002BC: beq         $v0, $zero, L_808002EC
    if (ctx->r2 == 0) {
        // 0x808002C0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002EC;
    }
    // 0x808002C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002C4: jal         0x800919F4
    // 0x808002C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_held(rdram, ctx);
        goto after_4;
    // 0x808002C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x808002CC: bne         $v0, $zero, L_808002E4
    if (ctx->r2 != 0) {
        // 0x808002D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002E4;
    }
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D4: jal         0x800919F4
    // 0x808002D8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_held(rdram, ctx);
        goto after_5;
    // 0x808002D8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_5:
    // 0x808002DC: beq         $v0, $zero, L_80800344
    if (ctx->r2 == 0) {
        // 0x808002E0: nop
    
            goto L_80800344;
    }
    // 0x808002E0: nop

L_808002E4:
    // 0x808002E4: b           L_80800344
    // 0x808002E8: addiu       $s1, $zero, 0x81
    ctx->r17 = ADD32(0, 0X81);
        goto L_80800344;
    // 0x808002E8: addiu       $s1, $zero, 0x81
    ctx->r17 = ADD32(0, 0X81);
L_808002EC:
    // 0x808002EC: jal         0x80085280
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x808002F4: beq         $v0, $zero, L_80800330
    if (ctx->r2 == 0) {
        // 0x808002F8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80800330;
    }
    // 0x808002F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002FC: beq         $v0, $at, L_8080031C
    if (ctx->r2 == ctx->r1) {
        // 0x80800300: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080031C;
    }
    // 0x80800300: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800304: beq         $v0, $at, L_80800324
    if (ctx->r2 == ctx->r1) {
        // 0x80800308: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800324;
    }
    // 0x80800308: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080030C: beql        $v0, $at, L_80800330
    if (ctx->r2 == ctx->r1) {
        // 0x80800310: addiu       $s1, $zero, 0x19
        ctx->r17 = ADD32(0, 0X19);
            goto L_80800330;
    }
    goto skip_0;
    // 0x80800310: addiu       $s1, $zero, 0x19
    ctx->r17 = ADD32(0, 0X19);
    skip_0:
    // 0x80800314: b           L_80800330
    // 0x80800318: nop

        goto L_80800330;
    // 0x80800318: nop

L_8080031C:
    // 0x8080031C: b           L_80800330
    // 0x80800320: addiu       $s1, $zero, 0x39
    ctx->r17 = ADD32(0, 0X39);
        goto L_80800330;
    // 0x80800320: addiu       $s1, $zero, 0x39
    ctx->r17 = ADD32(0, 0X39);
L_80800324:
    // 0x80800324: b           L_80800330
    // 0x80800328: addiu       $s1, $zero, 0x2C
    ctx->r17 = ADD32(0, 0X2C);
        goto L_80800330;
    // 0x80800328: addiu       $s1, $zero, 0x2C
    ctx->r17 = ADD32(0, 0X2C);
    // 0x8080032C: addiu       $s1, $zero, 0x19
    ctx->r17 = ADD32(0, 0X19);
L_80800330:
    // 0x80800330: jal         0x8009803C
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_8009803C(rdram, ctx);
        goto after_7;
    // 0x80800334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800338: beq         $v0, $zero, L_80800344
    if (ctx->r2 == 0) {
        // 0x8080033C: nop
    
            goto L_80800344;
    }
    // 0x8080033C: nop

    // 0x80800340: addiu       $s1, $zero, 0x157
    ctx->r17 = ADD32(0, 0X157);
L_80800344:
    // 0x80800344: jal         0x80085278
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baswim_entrypoint_2(rdram, ctx);
        goto after_8;
    // 0x80800348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080034C: beq         $v0, $zero, L_80800358
    if (ctx->r2 == 0) {
        // 0x80800350: nop
    
            goto L_80800358;
    }
    // 0x80800350: nop

    // 0x80800354: addiu       $s1, $zero, 0x2D
    ctx->r17 = ADD32(0, 0X2D);
L_80800358:
    // 0x80800358: jal         0x8008E35C
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_9;
    // 0x8080035C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800360: bne         $v0, $zero, L_8080036C
    if (ctx->r2 != 0) {
        // 0x80800364: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080036C;
    }
    // 0x80800364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800368: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8080036C:
    // 0x8080036C: jal         0x8009E5C8
    // 0x80800370: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    bs_setState(rdram, ctx);
        goto after_10;
    // 0x80800370: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_10:
    // 0x80800374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800378: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080037C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800380: jr          $ra
    // 0x80800384: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800384: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800FE3EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FE3EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800FE3F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FE3F4: lh          $a0, 0x59C8($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X59C8);
    // 0x800FE3F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FE3FC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800FE400: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x800FE404: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x800FE408: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800FE40C: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800FE410: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800FE414: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800FE418: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800FE41C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800FE420: beq         $a0, $at, L_800FE430
    if (ctx->r4 == ctx->r1) {
        // 0x800FE424: sdc1        $f20, 0x10($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
            goto L_800FE430;
    }
    // 0x800FE424: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800FE428: jal         0x800FCA90
    // 0x800FE42C: nop

    func_800FCA90(rdram, ctx);
        goto after_0;
    // 0x800FE42C: nop

    after_0:
L_800FE430:
    // 0x800FE430: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800FE434: addiu       $s5, $s5, 0x5A40
    ctx->r21 = ADD32(ctx->r21, 0X5A40);
    // 0x800FE438: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x800FE43C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800FE440: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800FE444: blez        $t6, L_800FE4B4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800FE448: lui         $s2, 0x8013
        ctx->r18 = S32(0X8013 << 16);
            goto L_800FE4B4;
    }
    // 0x800FE448: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800FE44C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800FE450: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800FE454: addiu       $s6, $s6, 0x5A3C
    ctx->r22 = ADD32(ctx->r22, 0X5A3C);
    // 0x800FE458: addiu       $s2, $s2, 0x5A20
    ctx->r18 = ADD32(ctx->r18, 0X5A20);
    // 0x800FE45C: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
L_800FE460:
    // 0x800FE460: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800FE464: addu        $s0, $s6, $s1
    ctx->r16 = ADD32(ctx->r22, ctx->r17);
    // 0x800FE468: beql        $a0, $zero, L_800FE4A8
    if (ctx->r4 == 0) {
        // 0x800FE46C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FE4A8;
    }
    goto skip_0;
    // 0x800FE46C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800FE470: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x800FE474: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FE478: addiu       $t8, $t8, 0x5A30
    ctx->r24 = ADD32(ctx->r24, 0X5A30);
    // 0x800FE47C: beql        $t7, $zero, L_800FE4A8
    if (ctx->r15 == 0) {
        // 0x800FE480: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800FE4A8;
    }
    goto skip_1;
    // 0x800FE480: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x800FE484: jal         0x800FCA90
    // 0x800FE488: addu        $s4, $s3, $t8
    ctx->r20 = ADD32(ctx->r19, ctx->r24);
    func_800FCA90(rdram, ctx);
        goto after_1;
    // 0x800FE488: addu        $s4, $s3, $t8
    ctx->r20 = ADD32(ctx->r19, ctx->r24);
    after_1:
    // 0x800FE48C: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x800FE490: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x800FE494: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800FE498: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800FE49C: swc1        $f20, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f20.u32l;
    // 0x800FE4A0: sw          $t0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r8;
    // 0x800FE4A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800FE4A8:
    // 0x800FE4A8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800FE4AC: bne         $s1, $s7, L_800FE460
    if (ctx->r17 != ctx->r23) {
        // 0x800FE4B0: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800FE460;
    }
    // 0x800FE4B0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800FE4B4:
    // 0x800FE4B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800FE4B8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800FE4BC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800FE4C0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800FE4C4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800FE4C8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800FE4CC: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800FE4D0: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800FE4D4: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x800FE4D8: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x800FE4DC: jr          $ra
    // 0x800FE4E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800FE4E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _bsbegghead_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828F0: syscall     19
    recomp_syscall_handler(rdram, ctx, 0x800828F0);
    return;
    // 0x800828F4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80095490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095490: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80095494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095498: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009549C: jal         0x8009C128
    // 0x800954A0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x800954A0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800954A4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800954A8: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800954AC: lw          $v0, 0x7C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X7C);
    // 0x800954B0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800954B4: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x800954B8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800954BC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800954C0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800954C4: jal         0x800953E0
    // 0x800954C8: nop

    func_800953E0(rdram, ctx);
        goto after_1;
    // 0x800954C8: nop

    after_1:
    // 0x800954CC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800954D0: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x800954D4: sw          $v0, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->r2;
    // 0x800954D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800954DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800954E0: jr          $ra
    // 0x800954E4: nop

    return;
    // 0x800954E4: nop

;}
RECOMP_FUNC void func_800D4F9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4F9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D4FA0: bne         $a0, $at, L_800D4FB0
    if (ctx->r4 != ctx->r1) {
        // 0x800D4FA4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800D4FB0;
    }
    // 0x800D4FA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D4FA8: jr          $ra
    // 0x800D4FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800D4FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D4FB0:
    // 0x800D4FB0: jr          $ra
    // 0x800D4FB4: nop

    return;
    // 0x800D4FB4: nop

;}
RECOMP_FUNC void func_80800DAC_chprisonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800DB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DB4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800DB8: jal         0x80100094
    // 0x80800DBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800DBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DC0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80800DC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800DC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800DCC: lw          $a0, 0x70($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X70);
    // 0x80800DD0: srl         $t7, $a0, 25
    ctx->r15 = S32(U32(ctx->r4) >> 25);
    // 0x80800DD4: jal         0x800CD08C
    // 0x80800DD8: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    func_800CD08C(rdram, ctx);
        goto after_1;
    // 0x80800DD8: addiu       $a0, $t7, -0x1
    ctx->r4 = ADD32(ctx->r15, -0X1);
    after_1:
    // 0x80800DDC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800DE0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800DE4: lwc1        $f4, 0x8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80800DE8: swc1        $f4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f4.u32l;
    // 0x80800DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800DF4: jr          $ra
    // 0x80800DF8: nop

    return;
    // 0x80800DF8: nop

;}
RECOMP_FUNC void func_80800000_chhagstraindoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800010: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800014: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800018: jal         0x800EFD24
    // 0x8080001C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x8080001C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800020: jal         0x80103014
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_1;
    // 0x80800024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800028: lhu         $t6, 0x76($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X76);
    // 0x8080002C: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800034: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x80800038: bne         $t7, $at, L_80800050
    if (ctx->r15 != ctx->r1) {
        // 0x8080003C: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_80800050;
    }
    // 0x8080003C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800040: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800044: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800048: nop

    // 0x8080004C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
L_80800050:
    // 0x80800050: addiu       $t8, $zero, 0x21
    ctx->r24 = ADD32(0, 0X21);
    // 0x80800054: addiu       $t9, $zero, 0x403
    ctx->r25 = ADD32(0, 0X403);
    // 0x80800058: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8080005C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800060: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80800064: jal         0x80086898
    // 0x80800068: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800068: lui         $a3, 0x4416
    ctx->r7 = S32(0X4416 << 16);
    after_2:
    // 0x8080006C: beq         $v0, $zero, L_808000C0
    if (ctx->r2 == 0) {
        // 0x80800070: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000C0;
    }
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800074: lui         $a1, 0x408C
    ctx->r5 = S32(0X408C << 16);
    // 0x80800078: jal         0x800868B0
    // 0x8080007C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x8080007C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_3:
    // 0x80800080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800084: jal         0x800868A8
    // 0x80800088: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_4;
    // 0x80800088: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    after_4:
    // 0x8080008C: lhu         $t0, 0x76($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X76);
    // 0x80800090: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x8080009C: bnel        $t1, $at, L_808000C4
    if (ctx->r9 != ctx->r1) {
        // 0x808000A0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808000C4;
    }
    goto skip_0;
    // 0x808000A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000A4: jal         0x800868C0
    // 0x808000A8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_5;
    // 0x808000A8: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_5:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808000B8: jal         0x800868C8
    // 0x808000BC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_6;
    // 0x808000BC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_6:
L_808000C0:
    // 0x808000C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000C4:
    // 0x808000C4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000CC: jr          $ra
    // 0x808000D0: nop

    return;
    // 0x808000D0: nop

;}
RECOMP_FUNC void bstrexsmall_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BF8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800BFC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(416, 0X1B38) << 16);
    // 0x80800C00: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800C04: jr          $ra
    // 0x80800C08: lw          $v0, 0x1B38($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B38));
    return;
    // 0x80800C08: lw          $v0, 0x1B38($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(416, 0X1B38));
;}
RECOMP_FUNC void func_80800880_chglowbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800880: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800884: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800888: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8080088C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800890: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800894: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80800898: jal         0x80100094
    // 0x8080089C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080089C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808008A0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808008A4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x808008A8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808008AC: beq         $a3, $at, L_808009D8
    if (ctx->r7 == ctx->r1) {
        // 0x808008B0: lw          $t2, 0x38($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X38);
            goto L_808009D8;
    }
    // 0x808008B0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x808008B4: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x808008B8: beq         $a3, $at, L_808008F8
    if (ctx->r7 == ctx->r1) {
        // 0x808008BC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808008F8;
    }
    // 0x808008BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808008C0: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x808008C4: beq         $a3, $at, L_808009E0
    if (ctx->r7 == ctx->r1) {
        // 0x808008C8: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_808009E0;
    }
    // 0x808008C8: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x808008CC: bne         $a3, $at, L_80800A20
    if (ctx->r7 != ctx->r1) {
        // 0x808008D0: nop
    
            goto L_80800A20;
    }
    // 0x808008D0: nop

    // 0x808008D4: jal         0x80089F60
    // 0x808008D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808008D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x808008DC: jal         0x800DA298
    // 0x808008E0: addiu       $a0, $zero, 0x64E
    ctx->r4 = ADD32(0, 0X64E);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x808008E0: addiu       $a0, $zero, 0x64E
    ctx->r4 = ADD32(0, 0X64E);
    after_2:
    // 0x808008E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808008E8: jal         0x8010A5B0
    // 0x808008EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010A5B0(rdram, ctx);
        goto after_3;
    // 0x808008EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x808008F0: b           L_80800A2C
    // 0x808008F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A2C;
    // 0x808008F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008F8:
    // 0x808008F8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x808008FC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80800900: jal         0x800888C8
    // 0x80800904: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _fxsparkle_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80800904: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_4:
    // 0x80800908: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8080090C: addiu       $a1, $zero, 0xD03
    ctx->r5 = ADD32(0, 0XD03);
    // 0x80800910: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800914: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x80800918: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8080091C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x80800920: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80800924: bgez        $t8, L_80800950
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80800928: nop
    
            goto L_80800950;
    }
    // 0x80800928: nop

    // 0x8080092C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80800930: jal         0x8008A208
    // 0x80800934: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800934: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80800938: jal         0x800DA544
    // 0x8080093C: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    func_800DA544(rdram, ctx);
        goto after_6;
    // 0x8080093C: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    after_6:
    // 0x80800940: jal         0x800D1844
    // 0x80800944: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_800D1844(rdram, ctx);
        goto after_7;
    // 0x80800944: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_7:
    // 0x80800948: b           L_80800970
    // 0x8080094C: nop

        goto L_80800970;
    // 0x8080094C: nop

L_80800950:
    // 0x80800950: jal         0x8008A298
    // 0x80800954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _sudialog_entrypoint_0(rdram, ctx);
        goto after_8;
    // 0x80800954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80800958: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8080095C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800960: jal         0x800D0BD4
    // 0x80800964: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    func_800D0BD4(rdram, ctx);
        goto after_9;
    // 0x80800964: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_9:
    // 0x80800968: jal         0x800D1844
    // 0x8080096C: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    func_800D1844(rdram, ctx);
        goto after_10;
    // 0x8080096C: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_10:
L_80800970:
    // 0x80800970: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1628, 0X1454) << 16);
    // 0x80800974: addiu       $a2, $a2, 0x1454
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1628, 0X1454));
    // 0x80800978: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080097C: jal         0x80089D18
    // 0x80800980: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_11;
    // 0x80800980: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_11:
    // 0x80800984: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800988: jal         0x80101FDC
    // 0x8080098C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80101FDC(rdram, ctx);
        goto after_12;
    // 0x8080098C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80800990: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80800994: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x80800998: beql        $a0, $zero, L_80800A2C
    if (ctx->r4 == 0) {
        // 0x8080099C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80800A2C;
    }
    goto skip_0;
    // 0x8080099C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808009A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x808009A4: nop

    // 0x808009A8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808009AC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808009B0: jal         0x800C8E54
    // 0x808009B4: nop

    func_800C8E54(rdram, ctx);
        goto after_13;
    // 0x808009B4: nop

    after_13:
    // 0x808009B8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x808009BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808009C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808009C4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808009C8: jal         0x800C8FB0
    // 0x808009CC: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    func_800C8FB0(rdram, ctx);
        goto after_14;
    // 0x808009CC: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    after_14:
    // 0x808009D0: b           L_80800A2C
    // 0x808009D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800A2C;
    // 0x808009D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808009D8:
    // 0x808009D8: b           L_80800A28
    // 0x808009DC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
        goto L_80800A28;
    // 0x808009DC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_808009E0:
    // 0x808009E0: jal         0x800C8A98
    // 0x808009E4: nop

    func_800C8A98(rdram, ctx);
        goto after_15;
    // 0x808009E4: nop

    after_15:
    // 0x808009E8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x808009EC: lui         $a2, 0x443B
    ctx->r6 = S32(0X443B << 16);
    // 0x808009F0: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x808009F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808009F8: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x808009FC: jal         0x800C8E54
    // 0x80800A00: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    func_800C8E54(rdram, ctx);
        goto after_16;
    // 0x80800A00: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    after_16:
    // 0x80800A04: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A08: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800A0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800A10: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80800A14: sb          $t4, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r12;
    // 0x80800A18: b           L_80800A28
    // 0x80800A1C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
        goto L_80800A28;
    // 0x80800A1C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
L_80800A20:
    // 0x80800A20: b           L_80800A2C
    // 0x80800A24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800A2C;
    // 0x80800A24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800A28:
    // 0x80800A28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800A2C:
    // 0x80800A2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800A30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800A34: jr          $ra
    // 0x80800A38: nop

    return;
    // 0x80800A38: nop

;}
RECOMP_FUNC void func_80801058_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801058: sll         $t6, $a3, 24
    ctx->r14 = S32(ctx->r7 << 24);
    // 0x8080105C: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x80801060: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80801064: lb          $t9, 0x5B($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X5B);
    // 0x80801068: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8080106C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80801070: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80801074: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2484, 0X70C4) << 16);
    // 0x80801078: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8080107C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80801080: lb          $t1, 0x70C4($t1)
    ctx->r9 = MEM_B(ctx->r9, (int16_t)RELOC_LO16(2484, 0X70C4));
    // 0x80801084: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801088: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080108C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801090: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80801094: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80801098: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8080109C: jal         0x800A89F8
    // 0x808010A0: sh          $t1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r9;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x808010A0: sh          $t1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r9;
    after_0:
    // 0x808010A4: jal         0x800A9478
    // 0x808010A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800A9478(rdram, ctx);
        goto after_1;
    // 0x808010A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808010AC: jal         0x800F5EF8
    // 0x808010B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F5EF8(rdram, ctx);
        goto after_2;
    // 0x808010B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x808010B4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x808010B8: jal         0x80110024
    // 0x808010BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_3;
    // 0x808010BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x808010C0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x808010C4: jal         0x80089528
    // 0x808010C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncpod_entrypoint_13(rdram, ctx);
        goto after_4;
    // 0x808010C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x808010CC: beq         $v0, $zero, L_808010EC
    if (ctx->r2 == 0) {
        // 0x808010D0: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_808010EC;
    }
    // 0x808010D0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x808010D4: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x808010D8: jal         0x8010FFB0
    // 0x808010DC: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    func_8010FFB0(rdram, ctx);
        goto after_5;
    // 0x808010DC: addiu       $a2, $s0, 0x44
    ctx->r6 = ADD32(ctx->r16, 0X44);
    after_5:
    // 0x808010E0: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808010E4: jal         0x80089520
    // 0x808010E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _ncpod_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x808010E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_808010EC:
    // 0x808010EC: lh          $a0, 0x46($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X46);
    // 0x808010F0: lh          $t2, 0x50($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X50);
    // 0x808010F4: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x808010F8: addiu       $a2, $s0, 0x28
    ctx->r6 = ADD32(ctx->r16, 0X28);
    // 0x808010FC: beq         $a0, $t2, L_8080115C
    if (ctx->r4 == ctx->r10) {
        // 0x80801100: addiu       $t3, $s0, 0x38
        ctx->r11 = ADD32(ctx->r16, 0X38);
            goto L_8080115C;
    }
    // 0x80801100: addiu       $t3, $s0, 0x38
    ctx->r11 = ADD32(ctx->r16, 0X38);
    // 0x80801104: addiu       $t4, $s0, 0x44
    ctx->r12 = ADD32(ctx->r16, 0X44);
    // 0x80801108: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8080110C: jal         0x80800EF4
    // 0x80801110: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    func_80800EF4_chquiz(rdram, ctx);
        goto after_7;
    // 0x80801110: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_7:
    // 0x80801114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801118: jal         0x800EE7F8
    // 0x8080111C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x8080111C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80801120: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x80801124: jal         0x800EE7F8
    // 0x80801128: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80801128: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x8080112C: lb          $v0, 0x5F($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X5F);
    // 0x80801130: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80801134: bne         $v0, $zero, L_80801148
    if (ctx->r2 != 0) {
        // 0x80801138: nop
    
            goto L_80801148;
    }
    // 0x80801138: nop

    // 0x8080113C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801140: b           L_8080114C
    // 0x80801144: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
        goto L_8080114C;
    // 0x80801144: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80801148:
    // 0x80801148: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_8080114C:
    // 0x8080114C: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80801150: sb          $v0, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r2;
    // 0x80801154: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x80801158: sh          $t5, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r13;
L_8080115C:
    // 0x8080115C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801160: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801164: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80801168: jr          $ra
    // 0x8080116C: nop

    return;
    // 0x8080116C: nop

;}
RECOMP_FUNC void func_80800784_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800784: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800788: addiu       $at, $zero, 0x109F
    ctx->r1 = ADD32(0, 0X109F);
    // 0x8080078C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800790: beq         $a1, $at, L_808007C4
    if (ctx->r5 == ctx->r1) {
        // 0x80800794: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_808007C4;
    }
    // 0x80800794: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800798: addiu       $at, $zero, 0x10A0
    ctx->r1 = ADD32(0, 0X10A0);
    // 0x8080079C: beq         $a1, $at, L_80800804
    if (ctx->r5 == ctx->r1) {
        // 0x808007A0: addiu       $at, $zero, 0x10A9
        ctx->r1 = ADD32(0, 0X10A9);
            goto L_80800804;
    }
    // 0x808007A0: addiu       $at, $zero, 0x10A9
    ctx->r1 = ADD32(0, 0X10A9);
    // 0x808007A4: beq         $a1, $at, L_808007F4
    if (ctx->r5 == ctx->r1) {
        // 0x808007A8: addiu       $at, $zero, 0x10CA
        ctx->r1 = ADD32(0, 0X10CA);
            goto L_808007F4;
    }
    // 0x808007A8: addiu       $at, $zero, 0x10CA
    ctx->r1 = ADD32(0, 0X10CA);
    // 0x808007AC: beq         $a1, $at, L_8080081C
    if (ctx->r5 == ctx->r1) {
        // 0x808007B0: addiu       $at, $zero, 0x10CB
        ctx->r1 = ADD32(0, 0X10CB);
            goto L_8080081C;
    }
    // 0x808007B0: addiu       $at, $zero, 0x10CB
    ctx->r1 = ADD32(0, 0X10CB);
    // 0x808007B4: beql        $a1, $at, L_80800820
    if (ctx->r5 == ctx->r1) {
        // 0x808007B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800820;
    }
    goto skip_0;
    // 0x808007B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808007BC: b           L_80800814
    // 0x808007C0: nop

        goto L_80800814;
    // 0x808007C0: nop

L_808007C4:
    // 0x808007C4: jal         0x80800564
    // 0x808007C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80800564_chmadamegrunty(rdram, ctx);
        goto after_0;
    // 0x808007C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808007CC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x808007D0: addiu       $t7, $zero, 0x43
    ctx->r15 = ADD32(0, 0X43);
    // 0x808007D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808007D8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x808007DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808007E0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x808007E4: jal         0x8008A208
    // 0x808007E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808007E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x808007EC: b           L_80800820
    // 0x808007F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800820;
    // 0x808007F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808007F4:
    // 0x808007F4: jal         0x808002BC
    // 0x808007F8: nop

    func_808002BC_chmadamegrunty(rdram, ctx);
        goto after_2;
    // 0x808007F8: nop

    after_2:
    // 0x808007FC: b           L_80800820
    // 0x80800800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800820;
    // 0x80800800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800804:
    // 0x80800804: jal         0x808002BC
    // 0x80800808: nop

    func_808002BC_chmadamegrunty(rdram, ctx);
        goto after_3;
    // 0x80800808: nop

    after_3:
    // 0x8080080C: b           L_80800820
    // 0x80800810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800820;
    // 0x80800810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800814:
    // 0x80800814: jal         0x80800670
    // 0x80800818: nop

    func_80800670_chmadamegrunty(rdram, ctx);
        goto after_4;
    // 0x80800818: nop

    after_4:
L_8080081C:
    // 0x8080081C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800820:
    // 0x80800820: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800824: jr          $ra
    // 0x80800828: nop

    return;
    // 0x80800828: nop

;}
RECOMP_FUNC void sumissilehome_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800060: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80800064: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80800068: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080006C: sb          $t6, 0xA($a1)
    MEM_B(0XA, ctx->r5) = ctx->r14;
    // 0x80800070: jr          $ra
    // 0x80800074: swc1        $f12, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f12.u32l;
    return;
    // 0x80800074: swc1        $f12, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_808000CC_bsdronevanish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808000D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000DC: jal         0x800F3BB0
    // 0x808000E0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_800F3BB0(rdram, ctx);
        goto after_0;
    // 0x808000E0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x808000E4: lw          $t6, 0x188($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X188);
    // 0x808000E8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(200, 0X560) << 16);
    // 0x808000EC: addiu       $t7, $t7, 0x560
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(200, 0X560));
    // 0x808000F0: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x808000F4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808000F8: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x808000FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800100: jal         0x800BABB8
    // 0x80800104: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80800104: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80800108: lw          $t8, 0x188($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X188);
    // 0x8080010C: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(200, 0X560) << 16);
    // 0x80800110: addiu       $t9, $t9, 0x560
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(200, 0X560));
    // 0x80800114: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80800118: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080011C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800124: jal         0x800BABB8
    // 0x80800128: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_2;
    // 0x80800128: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x8080012C: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80800130: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800134: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800138: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(200, 0X56C) << 16);
    // 0x8080013C: addiu       $t1, $t1, 0x56C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(200, 0X56C));
    // 0x80800140: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80800144: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80800148: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080014C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80800150: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80800154: lw          $t0, 0x188($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X188);
    // 0x80800158: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x8080015C: jal         0x800BABB8
    // 0x80800160: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x80800160: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_3:
    // 0x80800164: lw          $t2, 0x188($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X188);
    // 0x80800168: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(200, 0X56C) << 16);
    // 0x8080016C: addiu       $t3, $t3, 0x56C
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(200, 0X56C));
    // 0x80800170: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80800174: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800178: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8080017C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800180: jal         0x800BABB8
    // 0x80800184: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_4;
    // 0x80800184: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x80800188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080018C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800190: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800194: jr          $ra
    // 0x80800198: nop

    return;
    // 0x80800198: nop

;}
RECOMP_FUNC void func_80800130_chbkcart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800130: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80800134: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800138: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8080013C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800140: jal         0x80100094
    // 0x80800144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800144: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800148: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8080014C: lhu         $v1, 0x72($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X72);
    // 0x80800150: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800154: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800158: srl         $t6, $v1, 10
    ctx->r14 = S32(U32(ctx->r3) >> 10);
    // 0x8080015C: beq         $t6, $at, L_8080018C
    if (ctx->r14 == ctx->r1) {
        // 0x80800160: addiu       $a1, $zero, 0x258
        ctx->r5 = ADD32(0, 0X258);
            goto L_8080018C;
    }
    // 0x80800160: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x80800164: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800168: beq         $t6, $at, L_808001F8
    if (ctx->r14 == ctx->r1) {
        // 0x8080016C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_808001F8;
    }
    // 0x8080016C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800170: beq         $t6, $at, L_80800430
    if (ctx->r14 == ctx->r1) {
        // 0x80800174: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800430;
    }
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800178: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080017C: beq         $t6, $at, L_80800480
    if (ctx->r14 == ctx->r1) {
        // 0x80800180: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800480;
    }
    // 0x80800180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800184: b           L_808004CC
    // 0x80800188: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808004CC;
    // 0x80800188: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8080018C:
    // 0x8080018C: jal         0x8010CA74
    // 0x80800190: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    func_8010CA74(rdram, ctx);
        goto after_1;
    // 0x80800190: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800194: beq         $v0, $zero, L_808001D0
    if (ctx->r2 == 0) {
        // 0x80800198: nop
    
            goto L_808001D0;
    }
    // 0x80800198: nop

    // 0x8080019C: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x808001A0: addiu       $a1, $zero, 0x154B
    ctx->r5 = ADD32(0, 0X154B);
    // 0x808001A4: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x808001A8: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x808001AC: bltz        $t9, L_808001D0
    if (SIGNED(ctx->r25) < 0) {
        // 0x808001B0: lw          $a3, 0x34($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X34);
            goto L_808001D0;
    }
    // 0x808001B0: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x808001B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808001B8: addiu       $t0, $zero, 0x6F
    ctx->r8 = ADD32(0, 0X6F);
    // 0x808001BC: jal         0x8008A208
    // 0x808001C0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x808001C0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x808001C4: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x808001C8: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x808001CC: sb          $t3, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r11;
L_808001D0:
    // 0x808001D0: jal         0x8010CEAC
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CEAC(rdram, ctx);
        goto after_3;
    // 0x808001D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808001D8: jal         0x800DA298
    // 0x808001DC: addiu       $a0, $zero, 0x342
    ctx->r4 = ADD32(0, 0X342);
    func_800DA298(rdram, ctx);
        goto after_4;
    // 0x808001DC: addiu       $a0, $zero, 0x342
    ctx->r4 = ADD32(0, 0X342);
    after_4:
    // 0x808001E0: beq         $v0, $zero, L_808004C8
    if (ctx->r2 == 0) {
        // 0x808001E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004C8;
    }
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E8: jal         0x80102424
    // 0x808001EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x808001EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x808001F0: b           L_808004CC
    // 0x808001F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808004CC;
    // 0x808001F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808001F8:
    // 0x808001F8: lw          $t4, 0x78($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X78);
    // 0x808001FC: sll         $t6, $t4, 29
    ctx->r14 = S32(ctx->r12 << 29);
    // 0x80800200: bltzl       $t6, L_808004CC
    if (SIGNED(ctx->r14) < 0) {
        // 0x80800204: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808004CC;
    }
    goto skip_0;
    // 0x80800204: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80800208: jal         0x80089F78
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_6;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800210: beql        $v0, $zero, L_80800308
    if (ctx->r2 == 0) {
        // 0x80800214: lwc1        $f4, 0x28($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
            goto L_80800308;
    }
    goto skip_1;
    // 0x80800214: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x80800218: jal         0x8010C500
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C500(rdram, ctx);
        goto after_7;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800220: bne         $v0, $zero, L_80800260
    if (ctx->r2 != 0) {
        // 0x80800224: nop
    
            goto L_80800260;
    }
    // 0x80800224: nop

    // 0x80800228: jal         0x8010C710
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C710(rdram, ctx);
        goto after_8;
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800230: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800234: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2464, 0X760) << 16);
    // 0x80800238: lwc1        $f8, 0x760($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2464, 0X760));
    // 0x8080023C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800240: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2464, 0X764) << 16);
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800248: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8080024C: addiu       $a3, $zero, 0x3F
    ctx->r7 = ADD32(0, 0X3F);
    // 0x80800250: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800254: nop

    // 0x80800258: bc1fl       L_80800290
    if (!c1cs) {
        // 0x8080025C: lwc1        $f18, 0x28($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
            goto L_80800290;
    }
    goto skip_2;
    // 0x8080025C: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
    skip_2:
L_80800260:
    // 0x80800260: jal         0x800F54E4
    // 0x80800264: nop

    func_800F54E4(rdram, ctx);
        goto after_9;
    // 0x80800264: nop

    after_9:
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: jal         0x8010CD50
    // 0x80800270: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8010CD50(rdram, ctx);
        goto after_10;
    // 0x80800270: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x80800274: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800278: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080027C: nop

    // 0x80800280: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80800284: b           L_808002B4
    // 0x80800288: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
        goto L_808002B4;
    // 0x80800288: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    // 0x8080028C: lwc1        $f18, 0x28($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X28);
L_80800290:
    // 0x80800290: lwc1        $f6, 0x764($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2464, 0X764));
    // 0x80800294: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80800298: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8080029C: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x808002A0: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x808002A4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x808002A8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808002AC: jal         0x80089F88
    // 0x808002B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    _subaddierouteDll_entrypoint_6(rdram, ctx);
        goto after_11;
    // 0x808002B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_11:
L_808002B4:
    // 0x808002B4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808002B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808002BC: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x808002C0: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x808002C4: addiu       $t0, $zero, 0x4803
    ctx->r8 = ADD32(0, 0X4803);
    // 0x808002C8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x808002D4: jal         0x80089F90
    // 0x808002D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    _subaddierouteDll_entrypoint_7(rdram, ctx);
        goto after_12;
    // 0x808002D8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x808002DC: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x808002E0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x808002E4: lhu         $t2, 0x6($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X6);
    // 0x808002E8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x808002EC: bgez        $t2, L_80800300
    if (SIGNED(ctx->r10) >= 0) {
        // 0x808002F0: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80800300;
    }
    // 0x808002F0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808002F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808002F8: nop

    // 0x808002FC: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80800300:
    // 0x80800300: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
    // 0x80800304: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
L_80800308:
    // 0x80800308: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8080030C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800310: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800314: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80800318: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8080031C: lui         $a3, 0x3E19
    ctx->r7 = S32(0X3E19 << 16);
    // 0x80800320: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800324: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x80800328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080032C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80800330: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80800334: jal         0x80089F80
    // 0x80800338: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    _subaddierouteDll_entrypoint_5(rdram, ctx);
        goto after_13;
    // 0x80800338: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_13:
    // 0x8080033C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800340: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80800344: jal         0x8010CB84
    // 0x80800348: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    func_8010CB84(rdram, ctx);
        goto after_14;
    // 0x80800348: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    after_14:
    // 0x8080034C: beq         $v0, $zero, L_80800364
    if (ctx->r2 == 0) {
        // 0x80800350: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_80800364;
    }
    // 0x80800350: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800354: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80800358: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080035C: b           L_80800370
    // 0x80800360: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
        goto L_80800370;
    // 0x80800360: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_80800364:
    // 0x80800364: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800368: nop

    // 0x8080036C: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
L_80800370:
    // 0x80800370: jal         0x800D8FF8
    // 0x80800374: nop

    func_800D8FF8(rdram, ctx);
        goto after_15;
    // 0x80800374: nop

    after_15:
    // 0x80800378: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8080037C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800380: lwc1        $f12, 0x24($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80800384: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80800388: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8080038C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80800390: jal         0x800F15F8
    // 0x80800394: nop

    func_800F15F8(rdram, ctx);
        goto after_16;
    // 0x80800394: nop

    after_16:
    // 0x80800398: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2464, 0X864) << 16);
    // 0x8080039C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x808003A0: addiu       $t4, $t4, 0x864
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2464, 0X864));
    // 0x808003A4: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: sw          $at, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r1;
    // 0x808003B0: lw          $a2, 0x4($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X4);
    // 0x808003B4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x808003B8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808003BC: lw          $a3, 0x8($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8);
    // 0x808003C0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x808003C4: jal         0x801026CC
    // 0x808003C8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    func_801026CC(rdram, ctx);
        goto after_17;
    // 0x808003C8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    after_17:
    // 0x808003CC: jal         0x80101F24
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_18;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808003D4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2464, 0X828) << 16);
    // 0x808003D8: addiu       $a1, $a1, 0x828
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2464, 0X828));
    // 0x808003DC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x808003E0: jal         0x800F3780
    // 0x808003E4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_800F3780(rdram, ctx);
        goto after_19;
    // 0x808003E4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_19:
    // 0x808003E8: lui         $a1, 0x30
    ctx->r5 = S32(0X30 << 16);
    // 0x808003EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808003F0: ori         $a1, $a1, 0x5425
    ctx->r5 = ctx->r5 | 0X5425;
    // 0x808003F4: jal         0x8010C3A8
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010C3A8(rdram, ctx);
        goto after_20;
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808003FC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2464, 0X858) << 16);
    // 0x80800400: addiu       $a1, $a1, 0x858
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2464, 0X858));
    // 0x80800404: jal         0x80101E4C
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101E4C(rdram, ctx);
        goto after_21;
    // 0x80800408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8080040C: beq         $v0, $zero, L_808004C8
    if (ctx->r2 == 0) {
        // 0x80800410: lui         $a0, 0xBFCF
        ctx->r4 = S32(0XBFCF << 16);
            goto L_808004C8;
    }
    // 0x80800410: lui         $a0, 0xBFCF
    ctx->r4 = S32(0XBFCF << 16);
    // 0x80800414: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800418: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x8080041C: ori         $a0, $a0, 0xA447
    ctx->r4 = ctx->r4 | 0XA447;
    // 0x80800420: jal         0x800C4140
    // 0x80800424: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800C4140(rdram, ctx);
        goto after_22;
    // 0x80800424: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_22:
    // 0x80800428: b           L_808004CC
    // 0x8080042C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808004CC;
    // 0x8080042C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800430:
    // 0x80800430: lui         $a1, 0x3F14
    ctx->r5 = S32(0X3F14 << 16);
    // 0x80800434: jal         0x80101E14
    // 0x80800438: ori         $a1, $a1, 0x7AE1
    ctx->r5 = ctx->r5 | 0X7AE1;
    func_80101E14(rdram, ctx);
        goto after_23;
    // 0x80800438: ori         $a1, $a1, 0x7AE1
    ctx->r5 = ctx->r5 | 0X7AE1;
    after_23:
    // 0x8080043C: beq         $v0, $zero, L_80800460
    if (ctx->r2 == 0) {
        // 0x80800440: lui         $a0, 0xBFD7
        ctx->r4 = S32(0XBFD7 << 16);
            goto L_80800460;
    }
    // 0x80800440: lui         $a0, 0xBFD7
    ctx->r4 = S32(0XBFD7 << 16);
    // 0x80800444: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800448: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x8080044C: ori         $a0, $a0, 0x7447
    ctx->r4 = ctx->r4 | 0X7447;
    // 0x80800450: jal         0x800C4140
    // 0x80800454: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_24;
    // 0x80800454: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_24:
    // 0x80800458: b           L_808004CC
    // 0x8080045C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808004CC;
    // 0x8080045C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800460:
    // 0x80800460: jal         0x80101DDC
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_25;
    // 0x80800464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800468: beq         $v0, $zero, L_808004C8
    if (ctx->r2 == 0) {
        // 0x8080046C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808004C8;
    }
    // 0x8080046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800470: jal         0x80102424
    // 0x80800474: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_26;
    // 0x80800474: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_26:
    // 0x80800478: b           L_808004CC
    // 0x8080047C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808004CC;
    // 0x8080047C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800480:
    // 0x80800480: lui         $a1, 0x3F14
    ctx->r5 = S32(0X3F14 << 16);
    // 0x80800484: jal         0x80101E14
    // 0x80800488: ori         $a1, $a1, 0x7AE1
    ctx->r5 = ctx->r5 | 0X7AE1;
    func_80101E14(rdram, ctx);
        goto after_27;
    // 0x80800488: ori         $a1, $a1, 0x7AE1
    ctx->r5 = ctx->r5 | 0X7AE1;
    after_27:
    // 0x8080048C: beq         $v0, $zero, L_808004B0
    if (ctx->r2 == 0) {
        // 0x80800490: lui         $a0, 0xBFD7
        ctx->r4 = S32(0XBFD7 << 16);
            goto L_808004B0;
    }
    // 0x80800490: lui         $a0, 0xBFD7
    ctx->r4 = S32(0XBFD7 << 16);
    // 0x80800494: lui         $a2, 0x4B0
    ctx->r6 = S32(0X4B0 << 16);
    // 0x80800498: ori         $a2, $a2, 0xFA
    ctx->r6 = ctx->r6 | 0XFA;
    // 0x8080049C: ori         $a0, $a0, 0x7447
    ctx->r4 = ctx->r4 | 0X7447;
    // 0x808004A0: jal         0x800C4140
    // 0x808004A4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800C4140(rdram, ctx);
        goto after_28;
    // 0x808004A4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_28:
    // 0x808004A8: b           L_808004CC
    // 0x808004AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_808004CC;
    // 0x808004AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808004B0:
    // 0x808004B0: jal         0x80101DDC
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_29;
    // 0x808004B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x808004B8: beql        $v0, $zero, L_808004CC
    if (ctx->r2 == 0) {
        // 0x808004BC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808004CC;
    }
    goto skip_3;
    // 0x808004BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x808004C0: jal         0x80089CA8
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_30;
    // 0x808004C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
L_808004C8:
    // 0x808004C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808004CC:
    // 0x808004CC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808004D0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x808004D4: jr          $ra
    // 0x808004D8: nop

    return;
    // 0x808004D8: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_35(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800FC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800FC4: jal         0x80800F3C
    // 0x80800FC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800F3C_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800FC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800FCC: bne         $v0, $zero, L_80800FDC
    if (ctx->r2 != 0) {
        // 0x80800FD0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80800FDC;
    }
    // 0x80800FD0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800FD4: b           L_80800FE8
    // 0x80800FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800FE8;
    // 0x80800FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800FDC:
    // 0x80800FDC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800FE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800FE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80800FE8:
    // 0x80800FE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800FEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800FF0: jr          $ra
    // 0x80800FF4: nop

    return;
    // 0x80800FF4: nop

    // 0x80800FF8: nop

    // 0x80800FFC: nop

;}
RECOMP_FUNC void _bsbswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B50: syscall     28
    recomp_syscall_handler(rdram, ctx, 0x80082B50);
    return;
    // 0x80082B54: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087CD0: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087CD0);
    return;
    // 0x80087CD4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void _gclightsDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087EA0: syscall     660
    recomp_syscall_handler(rdram, ctx, 0x80087EA0);
    return;
    // 0x80087EA4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chquiz_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803314: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2484, 0X7334) << 16);
    // 0x80803318: jr          $ra
    // 0x8080331C: addiu       $v0, $v0, 0x7334
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2484, 0X7334));
    return;
    // 0x8080331C: addiu       $v0, $v0, 0x7334
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2484, 0X7334));
;}
