#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_808006D0_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x808006D4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2372, 0X10E4) << 16);
    // 0x808006D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006DC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x808006E0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x808006E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808006E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808006EC: addiu       $t6, $t6, 0x10E4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2372, 0X10E4));
    // 0x808006F0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x808006F4: addiu       $s0, $sp, 0x54
    ctx->r16 = ADD32(ctx->r29, 0X54);
    // 0x808006F8: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2372, 0X10F0) << 16);
    // 0x808006FC: sw          $at, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r1;
    // 0x80800700: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80800704: addiu       $t0, $t0, 0x10F0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2372, 0X10F0));
    // 0x80800708: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
    // 0x8080070C: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80800710: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80800714: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80800718: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080071C: sw          $at, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r1;
    // 0x80800720: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80800724: sw          $at, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r1;
    // 0x80800728: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8080072C: sw          $t3, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r11;
    // 0x80800730: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80800734: sw          $at, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r1;
    // 0x80800738: jal         0x80100094
    // 0x8080073C: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080073C: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80800740: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800744: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80800748: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080074C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800750: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80800754: nop

    // 0x80800758: bc1fl       L_80800788
    if (!c1cs) {
        // 0x8080075C: add.s       $f12, $f12, $f12
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
            goto L_80800788;
    }
    goto skip_0;
    // 0x8080075C: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    skip_0:
    // 0x80800760: jal         0x800DC0C0
    // 0x80800764: nop

    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x80800764: nop

    after_1:
    // 0x80800768: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2372, 0X1044) << 16);
    // 0x8080076C: lwc1        $f6, 0x1044($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2372, 0X1044));
    // 0x80800770: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2372, 0X1048) << 16);
    // 0x80800774: lwc1        $f10, 0x1048($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2372, 0X1048));
    // 0x80800778: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8080077C: b           L_80800788
    // 0x80800780: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
        goto L_80800788;
    // 0x80800780: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80800784: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
L_80800788:
    // 0x80800788: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // 0x8080078C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80800790: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80800794: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800798: jal         0x800F3214
    // 0x8080079C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800F3214(rdram, ctx);
        goto after_2;
    // 0x8080079C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x808007A0: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x808007A4: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x808007A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_808007AC:
    // 0x808007AC: lw          $a0, 0x200($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X200);
    // 0x808007B0: jal         0x800C8E84
    // 0x808007B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_800C8E84(rdram, ctx);
        goto after_3;
    // 0x808007B4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x808007B8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x808007BC: bne         $s0, $s3, L_808007AC
    if (ctx->r16 != ctx->r19) {
        // 0x808007C0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_808007AC;
    }
    // 0x808007C0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x808007C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808007CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808007D0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808007D4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808007D8: jr          $ra
    // 0x808007DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x808007DC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void _gcgoto_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A88: syscall     652
    recomp_syscall_handler(rdram, ctx, 0x80087A88);
    return;
    // 0x80087A8C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void gcmapDll_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006C8: jal         0x800EA05C
    // 0x808006CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808006CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808006D0: slti        $at, $v0, 0xDA
    ctx->r1 = SIGNED(ctx->r2) < 0XDA ? 1 : 0;
    // 0x808006D4: bne         $at, $zero, L_8080071C
    if (ctx->r1 != 0) {
        // 0x808006D8: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_8080071C;
    }
    // 0x808006D8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808006DC: slti        $at, $v0, 0xF0
    ctx->r1 = SIGNED(ctx->r2) < 0XF0 ? 1 : 0;
    // 0x808006E0: bne         $at, $zero, L_80800708
    if (ctx->r1 != 0) {
        // 0x808006E4: addiu       $t6, $v0, -0x134
        ctx->r14 = ADD32(ctx->r2, -0X134);
            goto L_80800708;
    }
    // 0x808006E4: addiu       $t6, $v0, -0x134
    ctx->r14 = ADD32(ctx->r2, -0X134);
    // 0x808006E8: sltiu       $at, $t6, 0x62
    ctx->r1 = ctx->r14 < 0X62 ? 1 : 0;
    // 0x808006EC: beq         $at, $zero, L_80800864
    if (ctx->r1 == 0) {
        // 0x808006F0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80800864;
    }
    // 0x808006F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808006F4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2646, 0XD20) << 16);
    // 0x808006F8: addu        $at, $at, $t6
    gpr jr_addend_80800700 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808006FC: lw          $t6, 0xD20($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2646, 0XD20));
    // 0x80800700: jr          $t6
    // 0x80800704: nop

    switch (jr_addend_80800700 >> 2) {
        case 0: goto L_808007B0; break;
        case 1: goto L_80800864; break;
        case 2: goto L_80800864; break;
        case 3: goto L_80800864; break;
        case 4: goto L_80800864; break;
        case 5: goto L_80800864; break;
        case 6: goto L_80800864; break;
        case 7: goto L_80800864; break;
        case 8: goto L_80800864; break;
        case 9: goto L_80800864; break;
        case 10: goto L_80800794; break;
        case 11: goto L_80800794; break;
        case 12: goto L_80800864; break;
        case 13: goto L_80800864; break;
        case 14: goto L_80800864; break;
        case 15: goto L_80800864; break;
        case 16: goto L_80800864; break;
        case 17: goto L_80800864; break;
        case 18: goto L_80800864; break;
        case 19: goto L_80800864; break;
        case 20: goto L_80800864; break;
        case 21: goto L_80800864; break;
        case 22: goto L_80800864; break;
        case 23: goto L_80800864; break;
        case 24: goto L_80800864; break;
        case 25: goto L_80800864; break;
        case 26: goto L_80800864; break;
        case 27: goto L_80800864; break;
        case 28: goto L_80800864; break;
        case 29: goto L_80800864; break;
        case 30: goto L_80800864; break;
        case 31: goto L_80800864; break;
        case 32: goto L_80800864; break;
        case 33: goto L_80800864; break;
        case 34: goto L_80800794; break;
        case 35: goto L_80800864; break;
        case 36: goto L_80800864; break;
        case 37: goto L_80800864; break;
        case 38: goto L_80800864; break;
        case 39: goto L_80800864; break;
        case 40: goto L_80800864; break;
        case 41: goto L_80800864; break;
        case 42: goto L_80800864; break;
        case 43: goto L_80800864; break;
        case 44: goto L_808007CC; break;
        case 45: goto L_80800864; break;
        case 46: goto L_80800864; break;
        case 47: goto L_80800864; break;
        case 48: goto L_80800864; break;
        case 49: goto L_80800864; break;
        case 50: goto L_80800864; break;
        case 51: goto L_80800864; break;
        case 52: goto L_80800864; break;
        case 53: goto L_80800864; break;
        case 54: goto L_80800864; break;
        case 55: goto L_80800864; break;
        case 56: goto L_80800864; break;
        case 57: goto L_80800864; break;
        case 58: goto L_80800864; break;
        case 59: goto L_80800864; break;
        case 60: goto L_80800864; break;
        case 61: goto L_80800794; break;
        case 62: goto L_80800794; break;
        case 63: goto L_80800864; break;
        case 64: goto L_80800864; break;
        case 65: goto L_80800864; break;
        case 66: goto L_80800794; break;
        case 67: goto L_80800864; break;
        case 68: goto L_80800864; break;
        case 69: goto L_80800864; break;
        case 70: goto L_80800864; break;
        case 71: goto L_80800864; break;
        case 72: goto L_80800864; break;
        case 73: goto L_80800864; break;
        case 74: goto L_80800864; break;
        case 75: goto L_80800864; break;
        case 76: goto L_80800864; break;
        case 77: goto L_80800864; break;
        case 78: goto L_80800864; break;
        case 79: goto L_80800864; break;
        case 80: goto L_80800864; break;
        case 81: goto L_80800864; break;
        case 82: goto L_80800864; break;
        case 83: goto L_80800864; break;
        case 84: goto L_80800864; break;
        case 85: goto L_80800864; break;
        case 86: goto L_80800864; break;
        case 87: goto L_8080075C; break;
        case 88: goto L_80800818; break;
        case 89: goto L_80800834; break;
        case 90: goto L_80800864; break;
        case 91: goto L_80800864; break;
        case 92: goto L_80800864; break;
        case 93: goto L_80800864; break;
        case 94: goto L_80800864; break;
        case 95: goto L_80800778; break;
        case 96: goto L_80800850; break;
        case 97: goto L_80800850; break;
        default: switch_error(__func__, 0x80800700, 0x80800D20);
    }
    // 0x80800704: nop

L_80800708:
    // 0x80800708: addiu       $at, $zero, 0xEF
    ctx->r1 = ADD32(0, 0XEF);
    // 0x8080070C: beq         $v0, $at, L_80800794
    if (ctx->r2 == ctx->r1) {
        // 0x80800710: nop
    
            goto L_80800794;
    }
    // 0x80800710: nop

    // 0x80800714: b           L_80800868
    // 0x80800718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800868;
    // 0x80800718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080071C:
    // 0x8080071C: slti        $at, $v0, 0xB8
    ctx->r1 = SIGNED(ctx->r2) < 0XB8 ? 1 : 0;
    // 0x80800720: bne         $at, $zero, L_8080073C
    if (ctx->r1 != 0) {
        // 0x80800724: addiu       $t7, $v0, -0xA1
        ctx->r15 = ADD32(ctx->r2, -0XA1);
            goto L_8080073C;
    }
    // 0x80800724: addiu       $t7, $v0, -0xA1
    ctx->r15 = ADD32(ctx->r2, -0XA1);
    // 0x80800728: addiu       $at, $zero, 0xD9
    ctx->r1 = ADD32(0, 0XD9);
    // 0x8080072C: beq         $v0, $at, L_80800794
    if (ctx->r2 == ctx->r1) {
        // 0x80800730: nop
    
            goto L_80800794;
    }
    // 0x80800730: nop

    // 0x80800734: b           L_80800868
    // 0x80800738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800868;
    // 0x80800738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080073C:
    // 0x8080073C: sltiu       $at, $t7, 0x17
    ctx->r1 = ctx->r15 < 0X17 ? 1 : 0;
    // 0x80800740: beq         $at, $zero, L_80800864
    if (ctx->r1 == 0) {
        // 0x80800744: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800864;
    }
    // 0x80800744: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800748: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2646, 0XEA8) << 16);
    // 0x8080074C: addu        $at, $at, $t7
    gpr jr_addend_80800754 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800750: lw          $t7, 0xEA8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2646, 0XEA8));
    // 0x80800754: jr          $t7
    // 0x80800758: nop

    switch (jr_addend_80800754 >> 2) {
        case 0: goto L_8080075C; break;
        case 1: goto L_8080075C; break;
        case 2: goto L_8080075C; break;
        case 3: goto L_8080075C; break;
        case 4: goto L_8080075C; break;
        case 5: goto L_8080075C; break;
        case 6: goto L_80800778; break;
        case 7: goto L_80800864; break;
        case 8: goto L_80800864; break;
        case 9: goto L_80800864; break;
        case 10: goto L_80800864; break;
        case 11: goto L_80800864; break;
        case 12: goto L_80800864; break;
        case 13: goto L_80800864; break;
        case 14: goto L_80800778; break;
        case 15: goto L_80800864; break;
        case 16: goto L_80800864; break;
        case 17: goto L_80800864; break;
        case 18: goto L_80800864; break;
        case 19: goto L_80800864; break;
        case 20: goto L_80800864; break;
        case 21: goto L_80800864; break;
        case 22: goto L_80800794; break;
        default: switch_error(__func__, 0x80800754, 0x80800EA8);
    }
    // 0x80800758: nop

L_8080075C:
    // 0x8080075C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2646, 0X1B98) << 16);
    // 0x80800760: addiu       $a1, $a1, 0x1B98
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2646, 0X1B98));
    // 0x80800764: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800768: jal         0x80800668
    // 0x8080076C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800668_gcmapDll(rdram, ctx);
        goto after_1;
    // 0x8080076C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80800770: b           L_80800868
    // 0x80800774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800868;
    // 0x80800774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800778:
    // 0x80800778: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2646, 0X1BA0) << 16);
    // 0x8080077C: addiu       $a1, $a1, 0x1BA0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2646, 0X1BA0));
    // 0x80800780: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800784: jal         0x80800668
    // 0x80800788: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800668_gcmapDll(rdram, ctx);
        goto after_2;
    // 0x80800788: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x8080078C: b           L_80800868
    // 0x80800790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800868;
    // 0x80800790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800794:
    // 0x80800794: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2646, 0X1BB0) << 16);
    // 0x80800798: addiu       $a1, $a1, 0x1BB0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2646, 0X1BB0));
    // 0x8080079C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808007A0: jal         0x80800668
    // 0x808007A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800668_gcmapDll(rdram, ctx);
        goto after_3;
    // 0x808007A4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_3:
    // 0x808007A8: b           L_80800868
    // 0x808007AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800868;
    // 0x808007AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007B0:
    // 0x808007B0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2646, 0X1BA8) << 16);
    // 0x808007B4: addiu       $a1, $a1, 0x1BA8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2646, 0X1BA8));
    // 0x808007B8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808007BC: jal         0x80800668
    // 0x808007C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80800668_gcmapDll(rdram, ctx);
        goto after_4;
    // 0x808007C0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x808007C4: b           L_80800868
    // 0x808007C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800868;
    // 0x808007C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007CC:
    // 0x808007CC: addiu       $a0, $zero, 0x360
    ctx->r4 = ADD32(0, 0X360);
    // 0x808007D0: jal         0x800DA298
    // 0x808007D4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x808007D4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_5:
    // 0x808007D8: beq         $v0, $zero, L_808007FC
    if (ctx->r2 == 0) {
        // 0x808007DC: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_808007FC;
    }
    // 0x808007DC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x808007E0: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2646, 0X1BC8) << 16);
    // 0x808007E4: addiu       $a1, $a1, 0x1BC8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2646, 0X1BC8));
    // 0x808007E8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808007EC: jal         0x80800668
    // 0x808007F0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800668_gcmapDll(rdram, ctx);
        goto after_6;
    // 0x808007F0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
    // 0x808007F4: b           L_80800868
    // 0x808007F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800868;
    // 0x808007F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808007FC:
    // 0x808007FC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2646, 0X1BB8) << 16);
    // 0x80800800: addiu       $a1, $a1, 0x1BB8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2646, 0X1BB8));
    // 0x80800804: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800808: jal         0x80800668
    // 0x8080080C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800668_gcmapDll(rdram, ctx);
        goto after_7;
    // 0x8080080C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x80800810: b           L_80800868
    // 0x80800814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800868;
    // 0x80800814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800818:
    // 0x80800818: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2646, 0X1BB8) << 16);
    // 0x8080081C: addiu       $a1, $a1, 0x1BB8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2646, 0X1BB8));
    // 0x80800820: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800824: jal         0x80800668
    // 0x80800828: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800668_gcmapDll(rdram, ctx);
        goto after_8;
    // 0x80800828: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_8:
    // 0x8080082C: b           L_80800868
    // 0x80800830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800868;
    // 0x80800830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800834:
    // 0x80800834: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2646, 0X1BD8) << 16);
    // 0x80800838: addiu       $a1, $a1, 0x1BD8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2646, 0X1BD8));
    // 0x8080083C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800840: jal         0x80800668
    // 0x80800844: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800668_gcmapDll(rdram, ctx);
        goto after_9;
    // 0x80800844: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_9:
    // 0x80800848: b           L_80800868
    // 0x8080084C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800868;
    // 0x8080084C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800850:
    // 0x80800850: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2646, 0X1BC8) << 16);
    // 0x80800854: addiu       $a1, $a1, 0x1BC8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2646, 0X1BC8));
    // 0x80800858: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080085C: jal         0x80800668
    // 0x80800860: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_80800668_gcmapDll(rdram, ctx);
        goto after_10;
    // 0x80800860: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
L_80800864:
    // 0x80800864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800868:
    // 0x80800868: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080086C: jr          $ra
    // 0x80800870: nop

    return;
    // 0x80800870: nop

;}
RECOMP_FUNC void func_808000D4_chnewfreezy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D4: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x808000D8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x808000DC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x808000E0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x808000E4: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x808000E8: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x808000EC: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x808000F0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x808000F4: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x808000F8: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x808000FC: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80800100: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80800104: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80800108: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8080010C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80800110: jal         0x80100094
    // 0x80800114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800118: lw          $t6, 0x64($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X64);
    // 0x8080011C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800120: addiu       $s5, $sp, 0x8C
    ctx->r21 = ADD32(ctx->r29, 0X8C);
    // 0x80800124: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800128: bltzl       $t8, L_80800288
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080012C: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_80800288;
    }
    goto skip_0;
    // 0x8080012C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x80800130: lbu         $t0, 0x65($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X65);
    // 0x80800134: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800138: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8080013C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80800140: sb          $t1, 0x65($s2)
    MEM_B(0X65, ctx->r18) = ctx->r9;
    // 0x80800144: jal         0x8010D254
    // 0x80800148: swc1        $f4, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f4.u32l;
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x80800148: swc1        $f4, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f4.u32l;
    after_1:
    // 0x8080014C: lw          $v0, 0x6C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X6C);
    // 0x80800150: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800154: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800158: andi        $t2, $v0, 0x1FF
    ctx->r10 = ctx->r2 & 0X1FF;
    // 0x8080015C: beq         $t2, $zero, L_80800278
    if (ctx->r10 == 0) {
        // 0x80800160: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_80800278;
    }
    // 0x80800160: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80800164: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80800168: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8080016C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800170: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x80800174: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800178: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x8080017C: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x80800180: lb          $t3, 0x5C($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X5C);
L_80800184:
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8080018C: bne         $s3, $t3, L_8080019C
    if (ctx->r19 != ctx->r11) {
        // 0x80800190: lui         $at, 0x4282
        ctx->r1 = S32(0X4282 << 16);
            goto L_8080019C;
    }
    // 0x80800190: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80800194: b           L_80800268
    // 0x80800198: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
        goto L_80800268;
    // 0x80800198: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
L_8080019C:
    // 0x8080019C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808001A0: neg.s       $f22, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = -ctx->f30.fl;
    // 0x808001A4: jal         0x800F1DF4
    // 0x808001A8: neg.s       $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = -ctx->f24.fl;
    func_800F1DF4(rdram, ctx);
        goto after_2;
    // 0x808001A8: neg.s       $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = -ctx->f24.fl;
    after_2:
    // 0x808001AC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808001B0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x808001B4: jal         0x800DC178
    // 0x808001B8: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    func_800DC178(rdram, ctx);
        goto after_3;
    // 0x808001B8: mov.s       $f14, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    ctx->f14.fl = ctx->f30.fl;
    after_3:
    // 0x808001BC: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x808001C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001C4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x808001C8: jal         0x800DC178
    // 0x808001CC: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x808001CC: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_4:
    // 0x808001D0: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x808001D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001D8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x808001DC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001E0: jal         0x800DC178
    // 0x808001E4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    func_800DC178(rdram, ctx);
        goto after_5;
    // 0x808001E4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    after_5:
    // 0x808001E8: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x808001EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808001F0: add.s       $f10, $f24, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f24.fl + ctx->f20.fl;
    // 0x808001F4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x808001F8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808001FC: add.s       $f8, $f22, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x80800200: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80800204: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800208: jal         0x800EEC30
    // 0x8080020C: nop

    func_800EEC30(rdram, ctx);
        goto after_6;
    // 0x8080020C: nop

    after_6:
    // 0x80800210: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80800214: jal         0x800DC178
    // 0x80800218: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x80800218: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    after_7:
    // 0x8080021C: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80800220: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80800224: jal         0x800DC178
    // 0x80800228: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    func_800DC178(rdram, ctx);
        goto after_8;
    // 0x80800228: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    after_8:
    // 0x8080022C: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80800230: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80800234: jal         0x800DC178
    // 0x80800238: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    func_800DC178(rdram, ctx);
        goto after_9;
    // 0x80800238: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    after_9:
    // 0x8080023C: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80800240: sb          $s4, 0x5C($s0)
    MEM_B(0X5C, ctx->r16) = ctx->r20;
    // 0x80800244: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1812, 0X1920) << 16);
    // 0x80800248: lwc1        $f18, 0x1920($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1812, 0X1920));
    // 0x8080024C: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800250: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    // 0x80800254: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80800258: swc1        $f4, -0x14($s0)
    MEM_W(-0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8080025C: lw          $v0, 0x6C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X6C);
    // 0x80800260: andi        $t4, $v0, 0x1FF
    ctx->r12 = ctx->r2 & 0X1FF;
    // 0x80800264: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_80800268:
    // 0x80800268: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080026C: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x80800270: bnel        $at, $zero, L_80800184
    if (ctx->r1 != 0) {
        // 0x80800274: lb          $t3, 0x5C($s0)
        ctx->r11 = MEM_B(ctx->r16, 0X5C);
            goto L_80800184;
    }
    goto skip_1;
    // 0x80800274: lb          $t3, 0x5C($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X5C);
    skip_1:
L_80800278:
    // 0x80800278: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8080027C: jal         0x80089B88
    // 0x80800280: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    _sufreezy_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x80800280: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_10:
    // 0x80800284: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80800288:
    // 0x80800288: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8080028C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80800290: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80800294: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80800298: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8080029C: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x808002A0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x808002A4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x808002A8: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x808002AC: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x808002B0: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x808002B4: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x808002B8: jr          $ra
    // 0x808002BC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x808002BC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_808000DC_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000E4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000E8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x808000EC: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x808000F0: jal         0x800A4C68
    // 0x808000F4: swc1        $f12, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f12.u32l;
    func_800A4C68(rdram, ctx);
        goto after_0;
    // 0x808000F4: swc1        $f12, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f12.u32l;
    after_0:
    // 0x808000F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000FC: jal         0x800C51A4
    // 0x80800100: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800C51A4(rdram, ctx);
        goto after_1;
    // 0x80800100: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80800104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080010C: jr          $ra
    // 0x80800110: nop

    return;
    // 0x80800110: nop

;}
RECOMP_FUNC void func_800A9378(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A9378: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A937C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A9380: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A9384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A9388: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A938C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A9390: addiu       $s1, $s1, 0x76D0
    ctx->r17 = ADD32(ctx->r17, 0X76D0);
    // 0x800A9394: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A9398: addiu       $s2, $zero, 0x8
    ctx->r18 = ADD32(0, 0X8);
L_800A939C:
    // 0x800A939C: lw          $t6, 0x58($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X58);
    // 0x800A93A0: beql        $t6, $zero, L_800A93C4
    if (ctx->r14 == 0) {
        // 0x800A93A4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800A93C4;
    }
    goto skip_0;
    // 0x800A93A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800A93A8: jal         0x800A9420
    // 0x800A93AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A9420(rdram, ctx);
        goto after_0;
    // 0x800A93AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800A93B0: beql        $v0, $zero, L_800A93C4
    if (ctx->r2 == 0) {
        // 0x800A93B4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800A93C4;
    }
    goto skip_1;
    // 0x800A93B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x800A93B8: jal         0x80110164
    // 0x800A93BC: lw          $a0, 0x58($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X58);
    func_80110164(rdram, ctx);
        goto after_1;
    // 0x800A93BC: lw          $a0, 0x58($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X58);
    after_1:
    // 0x800A93C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800A93C4:
    // 0x800A93C4: bne         $s0, $s2, L_800A939C
    if (ctx->r16 != ctx->r18) {
        // 0x800A93C8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800A939C;
    }
    // 0x800A93C8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800A93CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A93D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A93D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A93D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A93DC: jr          $ra
    // 0x800A93E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A93E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _capod_entrypoint_13(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085708: syscall     171
    recomp_syscall_handler(rdram, ctx, 0x80085708);
    return;
    // 0x8008570C: addi        $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
;}
RECOMP_FUNC void bsblongleg_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012FC: jal         0x800839B8
    // 0x80801300: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80801300: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801304: jal         0x80800204
    // 0x80801308: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800204_bsblongleg(rdram, ctx);
        goto after_1;
    // 0x80801308: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080130C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801314: jr          $ra
    // 0x80801318: nop

    return;
    // 0x80801318: nop

;}
RECOMP_FUNC void _badata_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800846B8: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x800846B8);
    return;
    // 0x800846BC: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _baeggsetup_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A38: syscall     126
    recomp_syscall_handler(rdram, ctx, 0x80084A38);
    return;
    // 0x80084A3C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void ncbaspline_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C4: jal         0x8080002C
    // 0x808000C8: nop

    func_8080002C_ncbaspline(rdram, ctx);
        goto after_0;
    // 0x808000C8: nop

    after_0:
    // 0x808000CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000D4: jr          $ra
    // 0x808000D8: nop

    return;
    // 0x808000D8: nop

;}
RECOMP_FUNC void func_80803DCC_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803DCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803DD0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80803DD4: beq         $a0, $at, L_80803DF0
    if (ctx->r4 == ctx->r1) {
        // 0x80803DD8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80803DF0;
    }
    // 0x80803DD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803DDC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80803DE0: beq         $a0, $at, L_80803E10
    if (ctx->r4 == ctx->r1) {
        // 0x80803DE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80803E10;
    }
    // 0x80803DE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80803DE8: b           L_80803E30
    // 0x80803DEC: nop

        goto L_80803E30;
    // 0x80803DEC: nop

L_80803DF0:
    // 0x80803DF0: jal         0x80088138
    // 0x80803DF4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _gcfrontend_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80803DF4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x80803DF8: beq         $v0, $zero, L_80803E08
    if (ctx->r2 == 0) {
        // 0x80803DFC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80803E08;
    }
    // 0x80803DFC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80803E00: b           L_80803E30
    // 0x80803E04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803E30;
    // 0x80803E04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803E08:
    // 0x80803E08: b           L_80803E30
    // 0x80803E0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80803E30;
    // 0x80803E0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80803E10:
    // 0x80803E10: jal         0x80088140
    // 0x80803E14: nop

    _gcfrontend_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80803E14: nop

    after_1:
    // 0x80803E18: beq         $v0, $zero, L_80803E28
    if (ctx->r2 == 0) {
        // 0x80803E1C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80803E28;
    }
    // 0x80803E1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80803E20: b           L_80803E30
    // 0x80803E24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80803E30;
    // 0x80803E24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80803E28:
    // 0x80803E28: b           L_80803E30
    // 0x80803E2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80803E30;
    // 0x80803E2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80803E30:
    // 0x80803E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803E34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803E38: jr          $ra
    // 0x80803E3C: nop

    return;
    // 0x80803E3C: nop

;}
RECOMP_FUNC void bsmumswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800484: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800488: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(332, 0XB30) << 16);
    // 0x8080048C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800490: jr          $ra
    // 0x80800494: lw          $v0, 0xB30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(332, 0XB30));
    return;
    // 0x80800494: lw          $v0, 0xB30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(332, 0XB30));
;}
RECOMP_FUNC void func_8080017C_chjigsaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080017C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800188: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8080018C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800190: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800194: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80800198: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8080019C: jal         0x800D05E4
    // 0x808001A0: nop

    func_800D05E4(rdram, ctx);
        goto after_0;
    // 0x808001A0: nop

    after_0:
    // 0x808001A4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x808001A8: lw          $v0, 0x6C($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X6C);
    // 0x808001AC: andi        $t9, $v0, 0x1FF
    ctx->r25 = ctx->r2 & 0X1FF;
    // 0x808001B0: beql        $t9, $zero, L_808001C4
    if (ctx->r25 == 0) {
        // 0x808001B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808001C4;
    }
    goto skip_0;
    // 0x808001B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001B8: jal         0x800C8B84
    // 0x808001BC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    func_800C8B84(rdram, ctx);
        goto after_1;
    // 0x808001BC: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_1:
    // 0x808001C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808001C4:
    // 0x808001C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001C8: jr          $ra
    // 0x808001CC: nop

    return;
    // 0x808001CC: nop

;}
RECOMP_FUNC void func_800F7200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7200: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800F7204: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F7208: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F720C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F7210: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800F7214: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800F7218: lw          $t7, 0x5490($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5490);
    // 0x800F721C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7224: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800F7228: bc1t        L_800F7244
    if (c1cs) {
        // 0x800F722C: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_800F7244;
    }
    // 0x800F722C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x800F7230: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800F7234: jal         0x8008DDEC
    // 0x800F7238: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    func_8008DDEC(rdram, ctx);
        goto after_0;
    // 0x800F7238: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_0:
    // 0x800F723C: beql        $v0, $zero, L_800F7260
    if (ctx->r2 == 0) {
        // 0x800F7240: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F7260;
    }
    goto skip_0;
    // 0x800F7240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_800F7244:
    // 0x800F7244: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7248: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800F724C: jal         0x8008F568
    // 0x800F7250: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_8008F568(rdram, ctx);
        goto after_1;
    // 0x800F7250: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x800F7254: b           L_800F7264
    // 0x800F7258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F7264;
    // 0x800F7258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F725C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F7260:
    // 0x800F7260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F7264:
    // 0x800F7264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F7268: jr          $ra
    // 0x800F726C: nop

    return;
    // 0x800F726C: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805F88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80805F8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80805F90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80805F94: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80805F98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80805F9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80805FA0: lw          $v1, 0x19C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X19C);
    // 0x80805FA4: beq         $v1, $at, L_80805FE4
    if (ctx->r3 == ctx->r1) {
        // 0x80805FA8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80805FE4;
    }
    // 0x80805FA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80805FAC: beq         $v1, $at, L_80805FCC
    if (ctx->r3 == ctx->r1) {
        // 0x80805FB0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80805FCC;
    }
    // 0x80805FB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80805FB4: beq         $v1, $at, L_80805FDC
    if (ctx->r3 == ctx->r1) {
        // 0x80805FB8: nop
    
            goto L_80805FDC;
    }
    // 0x80805FB8: nop

    // 0x80805FBC: jal         0x80806774
    // 0x80805FC0: nop

    func_80806774_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80805FC0: nop

    after_0:
    // 0x80805FC4: b           L_80805FE4
    // 0x80805FC8: nop

        goto L_80805FE4;
    // 0x80805FC8: nop

L_80805FCC:
    // 0x80805FCC: jal         0x8080649C
    // 0x80805FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080649C_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80805FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80805FD4: b           L_80805FE4
    // 0x80805FD8: nop

        goto L_80805FE4;
    // 0x80805FD8: nop

L_80805FDC:
    // 0x80805FDC: jal         0x80806588
    // 0x80805FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80806588_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80805FE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80805FE4:
    // 0x80805FE4: jal         0x80806000
    // 0x80805FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80806000_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80805FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80805FEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80805FF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80805FF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80805FF8: jr          $ra
    // 0x80805FFC: nop

    return;
    // 0x80805FFC: nop

;}
RECOMP_FUNC void gccubesearch_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080042C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800434: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800438: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8080043C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80800440: jal         0x808002E8
    // 0x80800444: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    gccubesearch_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x80800444: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80800448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080044C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800450: jr          $ra
    // 0x80800454: nop

    return;
    // 0x80800454: nop

;}
RECOMP_FUNC void func_80801ADC_chfpsgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801AE4: jal         0x80100094
    // 0x80801AE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801AE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801AEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801AF0: lwc1        $f4, 0x55C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X55C);
    // 0x80801AF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801AF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801AFC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80801B00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80801B04: bc1t        L_80801B28
    if (c1cs) {
        // 0x80801B08: nop
    
            goto L_80801B28;
    }
    // 0x80801B08: nop

    // 0x80801B0C: lwc1        $f6, 0x560($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X560);
    // 0x80801B10: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x80801B14: nop

    // 0x80801B18: bc1f        L_80801B28
    if (!c1cs) {
        // 0x80801B1C: nop
    
            goto L_80801B28;
    }
    // 0x80801B1C: nop

    // 0x80801B20: b           L_80801B28
    // 0x80801B24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80801B28;
    // 0x80801B24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80801B28:
    // 0x80801B28: jr          $ra
    // 0x80801B2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80801B2C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80800D30_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D30: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80800D34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800D3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D40: jal         0x801022E4
    // 0x80800D44: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    func_801022E4(rdram, ctx);
        goto after_0;
    // 0x80800D44: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800D48: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80800D4C: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x80800D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D54: beq         $t6, $zero, L_80800D9C
    if (ctx->r14 == 0) {
        // 0x80800D58: nop
    
            goto L_80800D9C;
    }
    // 0x80800D58: nop

    // 0x80800D5C: jal         0x80089CD8
    // 0x80800D60: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    _subaddiefade_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x80800D60: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80800D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D68: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x80800D6C: jal         0x80086598
    // 0x80800D70: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    _chlifeforcespell_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800D70: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_2:
    // 0x80800D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D78: jal         0x80089CE8
    // 0x80800D7C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x80800D7C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_3:
    // 0x80800D80: jal         0x801015D0
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_4;
    // 0x80800D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800D88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800D8C: jal         0x80089CE8
    // 0x80800D90: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    _subaddiefade_entrypoint_11(rdram, ctx);
        goto after_5;
    // 0x80800D90: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_5:
    // 0x80800D94: b           L_80800DA8
    // 0x80800D98: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
        goto L_80800DA8;
    // 0x80800D98: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
L_80800D9C:
    // 0x80800D9C: jal         0x801015D0
    // 0x80800DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_801015D0(rdram, ctx);
        goto after_6;
    // 0x80800DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800DA4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
L_80800DA8:
    // 0x80800DA8: addiu       $at, $zero, 0x2FA
    ctx->r1 = ADD32(0, 0X2FA);
    // 0x80800DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DB0: beq         $t7, $at, L_80800E5C
    if (ctx->r15 == ctx->r1) {
        // 0x80800DB4: lui         $a1, 0x3EA8
        ctx->r5 = S32(0X3EA8 << 16);
            goto L_80800E5C;
    }
    // 0x80800DB4: lui         $a1, 0x3EA8
    ctx->r5 = S32(0X3EA8 << 16);
    // 0x80800DB8: addiu       $at, $zero, 0x2FB
    ctx->r1 = ADD32(0, 0X2FB);
    // 0x80800DBC: bne         $t7, $at, L_80800EA8
    if (ctx->r15 != ctx->r1) {
        // 0x80800DC0: addiu       $a0, $zero, 0x5
        ctx->r4 = ADD32(0, 0X5);
            goto L_80800EA8;
    }
    // 0x80800DC0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800DC4: jal         0x80101F24
    // 0x80800DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101F24(rdram, ctx);
        goto after_7;
    // 0x80800DC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800DCC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1232, 0X1BA8) << 16);
    // 0x80800DD0: lwc1        $f2, 0x1BA8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1232, 0X1BA8));
    // 0x80800DD4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800DDC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80800DE0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80800DE4: lui         $a2, 0x3F51
    ctx->r6 = S32(0X3F51 << 16);
    // 0x80800DE8: bc1fl       L_80800DFC
    if (!c1cs) {
        // 0x80800DEC: sw          $zero, 0x30($sp)
        MEM_W(0X30, ctx->r29) = 0;
            goto L_80800DFC;
    }
    goto skip_0;
    // 0x80800DEC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    skip_0:
    // 0x80800DF0: b           L_80800DFC
    // 0x80800DF4: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80800DFC;
    // 0x80800DF4: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80800DF8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_80800DFC:
    // 0x80800DFC: jal         0x80102320
    // 0x80800E00: ori         $a2, $a2, 0xA9FC
    ctx->r6 = ctx->r6 | 0XA9FC;
    func_80102320(rdram, ctx);
        goto after_8;
    // 0x80800E00: ori         $a2, $a2, 0xA9FC
    ctx->r6 = ctx->r6 | 0XA9FC;
    after_8:
    // 0x80800E04: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800E08: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800E0C: jal         0x800DF744
    // 0x80800E10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_9;
    // 0x80800E10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80800E14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800E18: jal         0x800DF744
    // 0x80800E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_10;
    // 0x80800E1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80800E20: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800E24: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800E28: beq         $a1, $zero, L_80800E40
    if (ctx->r5 == 0) {
        // 0x80800E2C: nop
    
            goto L_80800E40;
    }
    // 0x80800E2C: nop

    // 0x80800E30: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x80800E34: sll         $t0, $a1, 11
    ctx->r8 = S32(ctx->r5 << 11);
    // 0x80800E38: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x80800E3C: sltu        $a1, $zero, $t1
    ctx->r5 = 0 < ctx->r9 ? 1 : 0;
L_80800E40:
    // 0x80800E40: jal         0x800DF744
    // 0x80800E44: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_800DF744(rdram, ctx);
        goto after_11;
    // 0x80800E44: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_11:
    // 0x80800E48: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800E4C: jal         0x800DF744
    // 0x80800E50: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800DF744(rdram, ctx);
        goto after_12;
    // 0x80800E50: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_12:
    // 0x80800E54: b           L_80800ED8
    // 0x80800E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800ED8;
    // 0x80800E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800E5C:
    // 0x80800E5C: lui         $a2, 0x3F6E
    ctx->r6 = S32(0X3F6E << 16);
    // 0x80800E60: ori         $a2, $a2, 0x147B
    ctx->r6 = ctx->r6 | 0X147B;
    // 0x80800E64: jal         0x80102320
    // 0x80800E68: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    func_80102320(rdram, ctx);
        goto after_13;
    // 0x80800E68: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    after_13:
    // 0x80800E6C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800E70: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800E74: jal         0x800DF744
    // 0x80800E78: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    func_800DF744(rdram, ctx);
        goto after_14;
    // 0x80800E78: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
    after_14:
    // 0x80800E7C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800E80: jal         0x800DF744
    // 0x80800E84: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800DF744(rdram, ctx);
        goto after_15;
    // 0x80800E84: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_15:
    // 0x80800E88: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800E8C: jal         0x800DF744
    // 0x80800E90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_16;
    // 0x80800E90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800E94: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800E98: jal         0x800DF744
    // 0x80800E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_17;
    // 0x80800E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x80800EA0: b           L_80800ED8
    // 0x80800EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800ED8;
    // 0x80800EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800EA8:
    // 0x80800EA8: jal         0x800DF744
    // 0x80800EAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_18;
    // 0x80800EAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x80800EB0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80800EB4: jal         0x800DF744
    // 0x80800EB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_19;
    // 0x80800EB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80800EBC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800EC0: jal         0x800DF744
    // 0x80800EC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_20;
    // 0x80800EC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x80800EC8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800ECC: jal         0x800DF744
    // 0x80800ED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DF744(rdram, ctx);
        goto after_21;
    // 0x80800ED0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x80800ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800ED8:
    // 0x80800ED8: jal         0x80100094
    // 0x80800EDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_22;
    // 0x80800EDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80800EE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800EE8: jal         0x8008A078
    // 0x80800EEC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    _subaddiepalette_entrypoint_3(rdram, ctx);
        goto after_23;
    // 0x80800EEC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    after_23:
    // 0x80800EF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800EF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800EF8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80800EFC: jr          $ra
    // 0x80800F00: nop

    return;
    // 0x80800F00: nop

;}
RECOMP_FUNC void bsbabykaz_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D04: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800D08: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(68, 0X1760) << 16);
    // 0x80800D0C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800D10: jr          $ra
    // 0x80800D14: lw          $v0, 0x1760($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1760));
    return;
    // 0x80800D14: lw          $v0, 0x1760($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(68, 0X1760));
;}
RECOMP_FUNC void func_8080000C_chfactorysmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1184, 0XF0) << 16);
    // 0x80800010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800014: lwc1        $f12, 0xF0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1184, 0XF0));
    // 0x80800018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080001C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1184, 0XF4) << 16);
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800024: jal         0x800DC178
    // 0x80800028: lwc1        $f14, 0xF4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1184, 0XF4));
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80800028: lwc1        $f14, 0xF4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1184, 0XF4));
    after_0:
    // 0x8080002C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800030: swc1        $f0, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f0.u32l;
    // 0x80800034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800038: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080003C: jr          $ra
    // 0x80800040: nop

    return;
    // 0x80800040: nop

;}
RECOMP_FUNC void func_80800980_chfireicestorm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800980: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800984: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800988: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8080098C: lw          $t7, 0x64($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X64);
    // 0x80800990: addiu       $v0, $zero, 0x76
    ctx->r2 = ADD32(0, 0X76);
    // 0x80800994: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800998: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x8080099C: bgez        $t9, L_808009AC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808009A0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_808009AC;
    }
    // 0x808009A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x808009A4: b           L_808009AC
    // 0x808009A8: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
        goto L_808009AC;
    // 0x808009A8: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
L_808009AC:
    // 0x808009AC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x808009B0: jal         0x8008A208
    // 0x808009B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808009B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x808009B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009C0: jr          $ra
    // 0x808009C4: nop

    return;
    // 0x808009C4: nop

;}
RECOMP_FUNC void func_80800440_chboilerid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800448: jal         0x80100094
    // 0x8080044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800450: jal         0x80088FA8
    // 0x80800454: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    _mlwave_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800454: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    after_1:
    // 0x80800458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080045C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800460: jr          $ra
    // 0x80800464: nop

    return;
    // 0x80800464: nop

;}
RECOMP_FUNC void baduo_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800044: lw          $t6, 0x58($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X58);
    // 0x80800048: jr          $ra
    // 0x8080004C: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    return;
    // 0x8080004C: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
;}
RECOMP_FUNC void func_808003BC_chbabydino(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x808003CC: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x808003D0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808003D4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x808003D8: bgezl       $t8, L_80800404
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808003DC: addiu       $at, $zero, 0x107E
        ctx->r1 = ADD32(0, 0X107E);
            goto L_80800404;
    }
    goto skip_0;
    // 0x808003DC: addiu       $at, $zero, 0x107E
    ctx->r1 = ADD32(0, 0X107E);
    skip_0:
    // 0x808003E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808003E4: jal         0x80085750
    // 0x808003E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _capod_entrypoint_22(rdram, ctx);
        goto after_0;
    // 0x808003E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808003EC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808003F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808003F4: lbu         $t9, 0x65($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X65);
    // 0x808003F8: andi        $t0, $t9, 0xFFF7
    ctx->r8 = ctx->r25 & 0XFFF7;
    // 0x808003FC: sb          $t0, 0x65($a2)
    MEM_B(0X65, ctx->r6) = ctx->r8;
    // 0x80800400: addiu       $at, $zero, 0x107E
    ctx->r1 = ADD32(0, 0X107E);
L_80800404:
    // 0x80800404: beq         $a1, $at, L_80800438
    if (ctx->r5 == ctx->r1) {
        // 0x80800408: addiu       $at, $zero, 0x1080
        ctx->r1 = ADD32(0, 0X1080);
            goto L_80800438;
    }
    // 0x80800408: addiu       $at, $zero, 0x1080
    ctx->r1 = ADD32(0, 0X1080);
    // 0x8080040C: beq         $a1, $at, L_80800438
    if (ctx->r5 == ctx->r1) {
        // 0x80800410: addiu       $a0, $zero, 0x588
        ctx->r4 = ADD32(0, 0X588);
            goto L_80800438;
    }
    // 0x80800410: addiu       $a0, $zero, 0x588
    ctx->r4 = ADD32(0, 0X588);
    // 0x80800414: jal         0x800DA298
    // 0x80800418: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800418: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8080041C: beq         $v0, $zero, L_8080042C
    if (ctx->r2 == 0) {
        // 0x80800420: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8080042C;
    }
    // 0x80800420: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800424: b           L_80800430
    // 0x80800428: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
        goto L_80800430;
    // 0x80800428: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_8080042C:
    // 0x8080042C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80800430:
    // 0x80800430: jal         0x80102424
    // 0x80800434: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800434: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_80800438:
    // 0x80800438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080043C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800440: jr          $ra
    // 0x80800444: nop

    return;
    // 0x80800444: nop

;}
RECOMP_FUNC void func_80801660_gcnewpause(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801668: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8080166C: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    // 0x80801670: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80801674: jal         0x80088718
    // 0x80801678: addiu       $a1, $zero, 0x1864
    ctx->r5 = ADD32(0, 0X1864);
    _gldbstring_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801678: addiu       $a1, $zero, 0x1864
    ctx->r5 = ADD32(0, 0X1864);
    after_0:
    // 0x8080167C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80801680: lb          $t6, 0x6($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X6);
    // 0x80801684: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x80801688: sb          $zero, 0x1A($a2)
    MEM_B(0X1A, ctx->r6) = 0;
    // 0x8080168C: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80801690: sh          $t7, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r15;
    // 0x80801694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080169C: jr          $ra
    // 0x808016A0: nop

    return;
    // 0x808016A0: nop

;}
RECOMP_FUNC void func_80803B60_chflysaucer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803B60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80803B64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80803B68: lbu         $v0, 0x79($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X79);
    // 0x80803B6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80803B70: srl         $t6, $v0, 4
    ctx->r14 = S32(U32(ctx->r2) >> 4);
    // 0x80803B74: beq         $t6, $at, L_80803B8C
    if (ctx->r14 == ctx->r1) {
        // 0x80803B78: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80803B8C;
    }
    // 0x80803B78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80803B7C: beql        $t6, $at, L_80803BAC
    if (ctx->r14 == ctx->r1) {
        // 0x80803B80: lw          $t8, 0x0($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X0);
            goto L_80803BAC;
    }
    goto skip_0;
    // 0x80803B80: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80803B84: b           L_80803BC0
    // 0x80803B88: nop

        goto L_80803BC0;
    // 0x80803B88: nop

L_80803B8C:
    // 0x80803B8C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80803B90: addiu       $a1, $zero, 0x826
    ctx->r5 = ADD32(0, 0X826);
    // 0x80803B94: lhu         $a2, 0x16($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X16);
    // 0x80803B98: jal         0x80103140
    // 0x80803B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103140(rdram, ctx);
        goto after_0;
    // 0x80803B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80803BA0: b           L_80803BC0
    // 0x80803BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80803BC0;
    // 0x80803BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80803BA8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
L_80803BAC:
    // 0x80803BAC: addiu       $a1, $zero, 0x827
    ctx->r5 = ADD32(0, 0X827);
    // 0x80803BB0: lhu         $a2, 0x16($t8)
    ctx->r6 = MEM_HU(ctx->r24, 0X16);
    // 0x80803BB4: jal         0x80103140
    // 0x80803BB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80103140(rdram, ctx);
        goto after_1;
    // 0x80803BB8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80803BBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80803BC0:
    // 0x80803BC0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X4258) << 16);
    // 0x80803BC4: lwc1        $f4, 0x4258($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X4258));
    // 0x80803BC8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1692, 0X425C) << 16);
    // 0x80803BCC: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x80803BD0: lwc1        $f6, 0x425C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1692, 0X425C));
    // 0x80803BD4: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x80803BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80803BDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80803BE0: jr          $ra
    // 0x80803BE4: nop

    return;
    // 0x80803BE4: nop

;}
RECOMP_FUNC void _chegggrenade_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087228: syscall     537
    recomp_syscall_handler(rdram, ctx, 0x80087228);
    return;
    // 0x8008722C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chmolehill_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086918: syscall     397
    recomp_syscall_handler(rdram, ctx, 0x80086918);
    return;
    // 0x8008691C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _bsfirstp_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800842E8: syscall     108
    recomp_syscall_handler(rdram, ctx, 0x800842E8);
    return;
    // 0x800842EC: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void bsledge_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CE0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800CE4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(304, 0X1378) << 16);
    // 0x80800CE8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800CEC: jr          $ra
    // 0x80800CF0: lw          $v0, 0x1378($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(304, 0X1378));
    return;
    // 0x80800CF0: lw          $v0, 0x1378($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(304, 0X1378));
;}
RECOMP_FUNC void chdinoswitches_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800664: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800668: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080066C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800670: jal         0x800EA05C
    // 0x80800674: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x80800674: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800678: addiu       $at, $zero, 0x112
    ctx->r1 = ADD32(0, 0X112);
    // 0x8080067C: bne         $v0, $at, L_808006D4
    if (ctx->r2 != ctx->r1) {
        // 0x80800680: addiu       $a0, $zero, 0x364
        ctx->r4 = ADD32(0, 0X364);
            goto L_808006D4;
    }
    // 0x80800680: addiu       $a0, $zero, 0x364
    ctx->r4 = ADD32(0, 0X364);
    // 0x80800684: jal         0x80089C78
    // 0x80800688: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    _subaddiefind_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800688: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_1:
    // 0x8080068C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800690: addiu       $a0, $zero, 0x433
    ctx->r4 = ADD32(0, 0X433);
    // 0x80800694: jal         0x80089C78
    // 0x80800698: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    _subaddiefind_entrypoint_11(rdram, ctx);
        goto after_2;
    // 0x80800698: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_2:
    // 0x8080069C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x808006A0: addiu       $a0, $zero, 0x433
    ctx->r4 = ADD32(0, 0X433);
    // 0x808006A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808006A8: jal         0x80101180
    // 0x808006AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_3;
    // 0x808006AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x808006B0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x808006B4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808006B8: jal         0x8010108C
    // 0x808006BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010108C(rdram, ctx);
        goto after_4;
    // 0x808006BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808006C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808006C4: jal         0x80103110
    // 0x808006C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80103110(rdram, ctx);
        goto after_5;
    // 0x808006C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808006CC: b           L_80800708
    // 0x808006D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800708;
    // 0x808006D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006D4:
    // 0x808006D4: jal         0x800DA298
    // 0x808006D8: addiu       $a0, $zero, 0xA3A
    ctx->r4 = ADD32(0, 0XA3A);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x808006D8: addiu       $a0, $zero, 0xA3A
    ctx->r4 = ADD32(0, 0XA3A);
    after_6:
    // 0x808006DC: bne         $v0, $zero, L_808006F4
    if (ctx->r2 != 0) {
        // 0x808006E0: addiu       $a0, $zero, 0x112
        ctx->r4 = ADD32(0, 0X112);
            goto L_808006F4;
    }
    // 0x808006E0: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    // 0x808006E4: jal         0x800887D8
    // 0x808006E8: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    _glcutDll_entrypoint_6(rdram, ctx);
        goto after_7;
    // 0x808006E8: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_7:
    // 0x808006EC: b           L_80800708
    // 0x808006F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800708;
    // 0x808006F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808006F4:
    // 0x808006F4: jal         0x800DA524
    // 0x808006F8: addiu       $a0, $zero, 0xA10
    ctx->r4 = ADD32(0, 0XA10);
    func_800DA524(rdram, ctx);
        goto after_8;
    // 0x808006F8: addiu       $a0, $zero, 0xA10
    ctx->r4 = ADD32(0, 0XA10);
    after_8:
    // 0x808006FC: jal         0x800DA524
    // 0x80800700: addiu       $a0, $zero, 0x676
    ctx->r4 = ADD32(0, 0X676);
    func_800DA524(rdram, ctx);
        goto after_9;
    // 0x80800700: addiu       $a0, $zero, 0x676
    ctx->r4 = ADD32(0, 0X676);
    after_9:
    // 0x80800704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800708:
    // 0x80800708: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080070C: jr          $ra
    // 0x80800710: nop

    return;
    // 0x80800710: nop

;}
RECOMP_FUNC void func_80800000_chdinotraindoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800004: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080000C: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x80800010: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80800014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800018: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x8080001C: bne         $t7, $at, L_80800034
    if (ctx->r15 != ctx->r1) {
        // 0x80800020: lwc1        $f0, 0x48($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
            goto L_80800034;
    }
    // 0x80800020: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800024: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80800028: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080002C: nop

    // 0x80800030: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
L_80800034:
    // 0x80800034: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800038: jal         0x800EFD24
    // 0x8080003C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x8080003C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80800040: jal         0x80103014
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_1;
    // 0x80800044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800048: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8080004C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800050: lwc1        $f6, 0x38($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800054: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800058: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8080005C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800060: addiu       $t9, $zero, 0x164
    ctx->r25 = ADD32(0, 0X164);
    // 0x80800064: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800068: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8080006C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800074: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800078: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8080007C: jal         0x80086898
    // 0x80800080: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x80800080: nop

    after_2:
    // 0x80800084: beq         $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x80800088: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000E4;
    }
    // 0x80800088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080008C: jal         0x800868A8
    // 0x80800090: lui         $a1, 0x4060
    ctx->r5 = S32(0X4060 << 16);
    _chdoormake_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80800090: lui         $a1, 0x4060
    ctx->r5 = S32(0X4060 << 16);
    after_3:
    // 0x80800094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800098: jal         0x800868B0
    // 0x8080009C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x8080009C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_4:
    // 0x808000A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000A8: jal         0x800868E0
    // 0x808000AC: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    _chdoormake_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x808000AC: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_5:
    // 0x808000B0: lhu         $t0, 0x76($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X76);
    // 0x808000B4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x808000B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000BC: srl         $t1, $t0, 7
    ctx->r9 = S32(U32(ctx->r8) >> 7);
    // 0x808000C0: bne         $t1, $at, L_808000E4
    if (ctx->r9 != ctx->r1) {
        // 0x808000C4: nop
    
            goto L_808000E4;
    }
    // 0x808000C4: nop

    // 0x808000C8: jal         0x800868C0
    // 0x808000CC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_6;
    // 0x808000CC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x808000D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808000D8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x808000DC: jal         0x800868C8
    // 0x808000E0: addiu       $a3, $zero, 0x910
    ctx->r7 = ADD32(0, 0X910);
    _chdoormake_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x808000E0: addiu       $a3, $zero, 0x910
    ctx->r7 = ADD32(0, 0X910);
    after_7:
L_808000E4:
    // 0x808000E4: jal         0x800DA298
    // 0x808000E8: addiu       $a0, $zero, 0x164
    ctx->r4 = ADD32(0, 0X164);
    func_800DA298(rdram, ctx);
        goto after_8;
    // 0x808000E8: addiu       $a0, $zero, 0x164
    ctx->r4 = ADD32(0, 0X164);
    after_8:
    // 0x808000EC: beql        $v0, $zero, L_80800110
    if (ctx->r2 == 0) {
        // 0x808000F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800110;
    }
    goto skip_0;
    // 0x808000F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000F4: jal         0x80088840
    // 0x808000F8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    _glcutDll_entrypoint_19(rdram, ctx);
        goto after_9;
    // 0x808000F8: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_9:
    // 0x808000FC: bnel        $v0, $zero, L_80800110
    if (ctx->r2 != 0) {
        // 0x80800100: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800110;
    }
    goto skip_1;
    // 0x80800100: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80800104: jal         0x800FFAB0
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_10;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080010C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800110:
    // 0x80800110: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800114: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800118: jr          $ra
    // 0x8080011C: nop

    return;
    // 0x8080011C: nop

;}
RECOMP_FUNC void _gcsectionDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088268: syscall     677
    recomp_syscall_handler(rdram, ctx, 0x80088268);
    return;
    // 0x8008826C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8009C25C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C25C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C264: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009C268: lw          $a0, 0xE4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XE4);
    // 0x8009C26C: jal         0x800EF04C
    // 0x8009C270: addiu       $a1, $a0, 0x24
    ctx->r5 = ADD32(ctx->r4, 0X24);
    func_800EF04C(rdram, ctx);
        goto after_0;
    // 0x8009C270: addiu       $a1, $a0, 0x24
    ctx->r5 = ADD32(ctx->r4, 0X24);
    after_0:
    // 0x8009C274: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8009C278: lw          $a0, 0xE4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0XE4);
    // 0x8009C27C: jal         0x800EFD24
    // 0x8009C280: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x8009C280: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_1:
    // 0x8009C284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C28C: jr          $ra
    // 0x8009C290: nop

    return;
    // 0x8009C290: nop

    // 0x8009C294: nop

    // 0x8009C298: nop

    // 0x8009C29C: nop

;}
RECOMP_FUNC void _chcheatopage_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CC0: syscall     223
    recomp_syscall_handler(rdram, ctx, 0x80085CC0);
    return;
    // 0x80085CC4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chfactorytwinklies_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800864F8: syscall     333
    recomp_syscall_handler(rdram, ctx, 0x800864F8);
    return;
    // 0x800864FC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808002A4_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808002A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002B0: jal         0x800A4CA8
    // 0x808002B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_0;
    // 0x808002B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808002B8: jal         0x80089418
    // 0x808002BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _ncba1p_entrypoint_10(rdram, ctx);
        goto after_1;
    // 0x808002BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808002C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808002C4: bnel        $v0, $at, L_808003AC
    if (ctx->r2 != ctx->r1) {
        // 0x808002C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808003AC;
    }
    goto skip_0;
    // 0x808002C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002CC: jal         0x800A4CA8
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_2;
    // 0x808002D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002D8: jal         0x80089408
    // 0x808002DC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    _ncba1p_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808002DC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x808002E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E4: jal         0x80095738
    // 0x808002E8: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    baflag_isTrue(rdram, ctx);
        goto after_4;
    // 0x808002E8: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    after_4:
    // 0x808002EC: bne         $v0, $zero, L_80800374
    if (ctx->r2 != 0) {
        // 0x808002F0: nop
    
            goto L_80800374;
    }
    // 0x808002F0: nop

    // 0x808002F4: jal         0x800D8FF8
    // 0x808002F8: nop

    func_800D8FF8(rdram, ctx);
        goto after_5;
    // 0x808002F8: nop

    after_5:
    // 0x808002FC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80800300: jal         0x80800BAC
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bafpctrl_entrypoint_3(rdram, ctx);
        goto after_6;
    // 0x80800304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800308: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8080030C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80800318: jal         0x8009EF34
    // 0x8080031C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    bastick_getY(rdram, ctx);
        goto after_7;
    // 0x8080031C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x80800320: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800324: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80800328: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080032C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800334: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800338: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8080033C: jal         0x8009EF28
    // 0x80800340: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    bastick_getX(rdram, ctx);
        goto after_8;
    // 0x80800340: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x80800344: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80800348: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8080034C: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800350: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80800354: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80800358: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8080035C: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x80800360: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800364: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80800368: jal         0x80083128
    // 0x8080036C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    _bsdronelook_entrypoint_2(rdram, ctx);
        goto after_9;
    // 0x8080036C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x80800370: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
L_80800374:
    // 0x80800374: jal         0x800A4CA8
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A4CA8(rdram, ctx);
        goto after_10;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080037C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800380: jal         0x80089400
    // 0x80800384: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    _ncba1p_entrypoint_7(rdram, ctx);
        goto after_11;
    // 0x80800384: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_11:
    // 0x80800388: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080038C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800390: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80800394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800398: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080039C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x808003A0: jal         0x8009C914
    // 0x808003A4: nop

    yaw_setIdeal(rdram, ctx);
        goto after_12;
    // 0x808003A4: nop

    after_12:
    // 0x808003A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808003AC:
    // 0x808003AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808003B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

;}
RECOMP_FUNC void func_80801F84_chchuffy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801F84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801F88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801F8C: jal         0x800EFD24
    // 0x80801F90: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EFD24(rdram, ctx);
        goto after_0;
    // 0x80801F90: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80801F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801F98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801F9C: jr          $ra
    // 0x80801FA0: nop

    return;
    // 0x80801FA0: nop

;}
RECOMP_FUNC void dbtex_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800008: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080000C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800010: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800014: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800018: bne         $a0, $zero, L_80800028
    if (ctx->r4 != 0) {
        // 0x8080001C: sw          $s1, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r17;
            goto L_80800028;
    }
    // 0x8080001C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800020: b           L_808000C0
    // 0x80800024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000C0;
    // 0x80800024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800028:
    // 0x80800028: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x8080002C: andi        $t7, $t6, 0x100
    ctx->r15 = ctx->r14 & 0X100;
    // 0x80800030: bnel        $t7, $zero, L_80800044
    if (ctx->r15 != 0) {
        // 0x80800034: lh          $s1, 0x4($s0)
        ctx->r17 = MEM_H(ctx->r16, 0X4);
            goto L_80800044;
    }
    goto skip_0;
    // 0x80800034: lh          $s1, 0x4($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X4);
    skip_0:
    // 0x80800038: b           L_808000C0
    // 0x8080003C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808000C0;
    // 0x8080003C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800040: lh          $s1, 0x4($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X4);
L_80800044:
    // 0x80800044: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80800048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080004C: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x80800050: addiu       $s1, $t8, 0x8
    ctx->r17 = ADD32(ctx->r24, 0X8);
    // 0x80800054: jal         0x8001ACEC
    // 0x80800058: addu        $a0, $t9, $s1
    ctx->r4 = ADD32(ctx->r25, ctx->r17);
    heap_alloc_sided(rdram, ctx);
        goto after_0;
    // 0x80800058: addu        $a0, $t9, $s1
    ctx->r4 = ADD32(ctx->r25, ctx->r17);
    after_0:
    // 0x8080005C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80800060: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800064: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800068: jal         0x8001BBA0
    // 0x8080006C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    rare_memcpy(rdram, ctx);
        goto after_1;
    // 0x8080006C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x80800070: lh          $t0, 0x4($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X4);
    // 0x80800074: addiu       $s0, $s3, 0x8
    ctx->r16 = ADD32(ctx->r19, 0X8);
    // 0x80800078: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8080007C: addu        $s2, $t1, $s3
    ctx->r18 = ADD32(ctx->r9, ctx->r19);
    // 0x80800080: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80800084: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x80800088: beq         $at, $zero, L_808000BC
    if (ctx->r1 == 0) {
        // 0x8080008C: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_808000BC;
    }
    // 0x8080008C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80800090:
    // 0x80800090: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800098: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8080009C: jal         0x800E6950
    // 0x808000A0: addiu       $a0, $a0, 0x1EF6
    ctx->r4 = ADD32(ctx->r4, 0X1EF6);
    func_800E6950(rdram, ctx);
        goto after_2;
    // 0x808000A0: addiu       $a0, $a0, 0x1EF6
    ctx->r4 = ADD32(ctx->r4, 0X1EF6);
    after_2:
    // 0x808000A4: jal         0x800D5944
    // 0x808000A8: nop

    func_800D5944(rdram, ctx);
        goto after_3;
    // 0x808000A8: nop

    after_3:
    // 0x808000AC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x808000B0: sltu        $at, $s0, $s2
    ctx->r1 = ctx->r16 < ctx->r18 ? 1 : 0;
    // 0x808000B4: bne         $at, $zero, L_80800090
    if (ctx->r1 != 0) {
        // 0x808000B8: addu        $s1, $s1, $v0
        ctx->r17 = ADD32(ctx->r17, ctx->r2);
            goto L_80800090;
    }
    // 0x808000B8: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_808000BC:
    // 0x808000BC: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_808000C0:
    // 0x808000C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808000C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x808000D4: jr          $ra
    // 0x808000D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808000D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _mlspline_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089130: syscall     762
    recomp_syscall_handler(rdram, ctx, 0x80089130);
    return;
    // 0x80089134: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _idtwinklea_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088EA8: syscall     746
    recomp_syscall_handler(rdram, ctx, 0x80088EA8);
    return;
    // 0x80088EAC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801A3C_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801A40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801A44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801A48: jal         0x808005DC
    // 0x80801A4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstrexsmall_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801A4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80801A50: jal         0x808002B8
    // 0x80801A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002B8_bstrexsmall(rdram, ctx);
        goto after_1;
    // 0x80801A54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80801A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A5C: jal         0x8009D3A8
    // 0x80801A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8009D3A8(rdram, ctx);
        goto after_2;
    // 0x80801A60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80801A64: lui         $a1, 0x3F65
    ctx->r5 = S32(0X3F65 << 16);
    // 0x80801A68: ori         $a1, $a1, 0xCFAB
    ctx->r5 = ctx->r5 | 0XCFAB;
    // 0x80801A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A70: jal         0x800A2CE8
    // 0x80801A74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800A2CE8(rdram, ctx);
        goto after_3;
    // 0x80801A74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x80801A78: lui         $a1, 0x3ECB
    ctx->r5 = S32(0X3ECB << 16);
    // 0x80801A7C: ori         $a1, $a1, 0x9F56
    ctx->r5 = ctx->r5 | 0X9F56;
    // 0x80801A80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A84: jal         0x800A2CE8
    // 0x80801A88: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_800A2CE8(rdram, ctx);
        goto after_4;
    // 0x80801A88: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x80801A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A90: jal         0x80800154
    // 0x80801A94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800154_bstrexsmall(rdram, ctx);
        goto after_5;
    // 0x80801A94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80801A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801A9C: jal         0x8009E5C8
    // 0x80801AA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    bs_setState(rdram, ctx);
        goto after_6;
    // 0x80801AA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80801AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801AA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801AAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80801AB0: jr          $ra
    // 0x80801AB4: nop

    return;
    // 0x80801AB4: nop

;}
RECOMP_FUNC void func_80090A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090A2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80090A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80090A34: jal         0x800908F0
    // 0x80090A38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800908F0(rdram, ctx);
        goto after_0;
    // 0x80090A38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80090A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090A40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80090A44: jr          $ra
    // 0x80090A48: nop

    return;
    // 0x80090A48: nop

;}
RECOMP_FUNC void chpotogoldbits_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008C8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(2344, 0X9D0) << 16);
    // 0x808008CC: jr          $ra
    // 0x808008D0: addiu       $v0, $v0, 0x9D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2344, 0X9D0));
    return;
    // 0x808008D0: addiu       $v0, $v0, 0x9D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(2344, 0X9D0));
    // 0x808008D4: nop

    // 0x808008D8: nop

    // 0x808008DC: nop

;}
RECOMP_FUNC void func_80800B10_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800B1C: jal         0x800DF3E0
    // 0x80800B20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800DF3E0(rdram, ctx);
        goto after_0;
    // 0x80800B20: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800B24: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80800B28: jal         0x800DF744
    // 0x80800B2C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_1;
    // 0x80800B2C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80800B30: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80800B34: jal         0x800DF744
    // 0x80800B38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DF744(rdram, ctx);
        goto after_2;
    // 0x80800B38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800B3C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80800B40: jal         0x800DF744
    // 0x80800B44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800DF744(rdram, ctx);
        goto after_3;
    // 0x80800B44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80800B48: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80800B4C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800B50: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x80800B54: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x80800B58: bgez        $t9, L_80800B68
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800B5C: nop
    
            goto L_80800B68;
    }
    // 0x80800B5C: nop

    // 0x80800B60: b           L_80800B68
    // 0x80800B64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80800B68;
    // 0x80800B64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80800B68:
    // 0x80800B68: jal         0x800DF744
    // 0x80800B6C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800DF744(rdram, ctx);
        goto after_4;
    // 0x80800B6C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_4:
    // 0x80800B70: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800B74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800B78: lw          $t1, 0x64($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X64);
    // 0x80800B7C: sll         $t3, $t1, 11
    ctx->r11 = S32(ctx->r9 << 11);
    // 0x80800B80: bgez        $t3, L_80800B90
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80800B84: nop
    
            goto L_80800B90;
    }
    // 0x80800B84: nop

    // 0x80800B88: b           L_80800B90
    // 0x80800B8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_80800B90;
    // 0x80800B8C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80800B90:
    // 0x80800B90: jal         0x800DF744
    // 0x80800B94: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800DF744(rdram, ctx);
        goto after_5;
    // 0x80800B94: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_5:
    // 0x80800B98: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80800B9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800BA0: lhu         $t5, 0x72($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X72);
    // 0x80800BA4: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x80800BA8: bnel        $t6, $at, L_80800BBC
    if (ctx->r14 != ctx->r1) {
        // 0x80800BAC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800BBC;
    }
    goto skip_0;
    // 0x80800BAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80800BB0: jal         0x800DF440
    // 0x80800BB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800DF440(rdram, ctx);
        goto after_6;
    // 0x80800BB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x80800BB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80800BBC:
    // 0x80800BBC: jal         0x80101870
    // 0x80800BC0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_7;
    // 0x80800BC0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_7:
    // 0x80800BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800BCC: jr          $ra
    // 0x80800BD0: nop

    return;
    // 0x80800BD0: nop

;}
RECOMP_FUNC void func_808002A4_bsdronevanish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808002A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x808002AC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x808002B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808002B4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808002B8: jal         0x800D8FF8
    // 0x808002BC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808002BC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x808002C0: lw          $v0, 0x188($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X188);
    // 0x808002C4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808002C8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(200, 0X550) << 16);
    // 0x808002CC: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x808002D0: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x808002D4: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x808002D8: lw          $t6, 0x188($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X188);
    // 0x808002DC: lwc1        $f8, 0x10($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X10);
    // 0x808002E0: c.lt.s      $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f8.fl < ctx->f22.fl;
    // 0x808002E4: nop

    // 0x808002E8: bc1fl       L_80800340
    if (!c1cs) {
        // 0x808002EC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80800340;
    }
    goto skip_0;
    // 0x808002EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808002F0: lwc1        $f20, 0x550($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(200, 0X550));
L_808002F4:
    // 0x808002F4: jal         0x808000CC
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000CC_bsdronevanish(rdram, ctx);
        goto after_1;
    // 0x808002F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x808002FC: lw          $v0, 0x188($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X188);
    // 0x80800300: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80800304: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80800308: mul.s       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8080030C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80800310: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80800314: lw          $v0, 0x188($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X188);
    // 0x80800318: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8080031C: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80800320: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    // 0x80800324: lw          $t7, 0x188($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X188);
    // 0x80800328: lwc1        $f16, 0x10($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8080032C: c.lt.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl < ctx->f22.fl;
    // 0x80800330: nop

    // 0x80800334: bc1t        L_808002F4
    if (c1cs) {
        // 0x80800338: nop
    
            goto L_808002F4;
    }
    // 0x80800338: nop

    // 0x8080033C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80800340:
    // 0x80800340: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800344: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800348: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8080034C: jr          $ra
    // 0x80800350: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800350: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800EA340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA340: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EA344: jr          $ra
    // 0x800EA348: lh          $v0, 0x2DCA($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2DCA);
    return;
    // 0x800EA348: lh          $v0, 0x2DCA($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2DCA);
;}
RECOMP_FUNC void _bskazjump_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083438: syscall     62
    recomp_syscall_handler(rdram, ctx, 0x80083438);
    return;
    // 0x8008343C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_8009FE58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009FE58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009FE5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009FE60: jal         0x800A2E18
    // 0x8009FE64: nop

    func_800A2E18(rdram, ctx);
        goto after_0;
    // 0x8009FE64: nop

    after_0:
    // 0x8009FE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009FE6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009FE70: jr          $ra
    // 0x8009FE74: nop

    return;
    // 0x8009FE74: nop

;}
