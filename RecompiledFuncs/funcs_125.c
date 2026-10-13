#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bsride_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006BC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808006C0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(348, 0XA80) << 16);
    // 0x808006C4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808006C8: jr          $ra
    // 0x808006CC: lw          $v0, 0xA80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(348, 0XA80));
    return;
    // 0x808006CC: lw          $v0, 0xA80($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(348, 0XA80));
;}
RECOMP_FUNC void _chmermaidstatue_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086238: syscall     292
    recomp_syscall_handler(rdram, ctx, 0x80086238);
    return;
    // 0x8008623C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808011B4_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808011B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808011BC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x808011C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x808011C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808011C8: jal         0x80100094
    // 0x808011CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808011CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808011D0: lh          $v1, 0x84($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X84);
    // 0x808011D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808011D8: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1312, 0X2630) << 16);
    // 0x808011DC: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x808011E0: beq         $at, $zero, L_80801234
    if (ctx->r1 == 0) {
        // 0x808011E4: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_80801234;
    }
    // 0x808011E4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x808011E8: addiu       $t6, $t6, 0x2630
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1312, 0X2630));
    // 0x808011EC: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(1312, 0X2644) << 16);
    // 0x808011F0: addiu       $s2, $s2, 0x2644
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(1312, 0X2644));
    // 0x808011F4: addu        $s1, $v0, $t6
    ctx->r17 = ADD32(ctx->r2, ctx->r14);
    // 0x808011F8: addu        $s0, $a0, $v0
    ctx->r16 = ADD32(ctx->r4, ctx->r2);
L_808011FC:
    // 0x808011FC: jal         0x800D8FF8
    // 0x80801200: nop

    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80801200: nop

    after_1:
    // 0x80801204: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80801208: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8080120C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80801210: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80801214: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x80801218: jal         0x800136E4
    // 0x8080121C: lwc1        $f12, 0x70($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X70);
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x8080121C: lwc1        $f12, 0x70($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X70);
    after_2:
    // 0x80801220: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80801224: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80801228: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8080122C: bne         $at, $zero, L_808011FC
    if (ctx->r1 != 0) {
        // 0x80801230: swc1        $f0, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
            goto L_808011FC;
    }
    // 0x80801230: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_80801234:
    // 0x80801234: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801238: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080123C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80801240: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80801244: jr          $ra
    // 0x80801248: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80801248: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void _gcboundDll_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087ED8: syscall     661
    recomp_syscall_handler(rdram, ctx, 0x80087ED8);
    return;
    // 0x80087EDC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808003E4_chbottlesparty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x808003E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x808003EC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x808003F0: jr          $ra
    // 0x808003F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x808003F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808003F8: nop

    // 0x808003FC: nop

;}
RECOMP_FUNC void func_808015EC_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808015F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808015F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808015F8: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x808015FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801600: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801604: bnel        $t6, $at, L_8080162C
    if (ctx->r14 != ctx->r1) {
        // 0x80801608: sltiu       $at, $a1, 0x6
        ctx->r1 = ctx->r5 < 0X6 ? 1 : 0;
            goto L_8080162C;
    }
    goto skip_0;
    // 0x80801608: sltiu       $at, $a1, 0x6
    ctx->r1 = ctx->r5 < 0X6 ? 1 : 0;
    skip_0:
    // 0x8080160C: lbu         $a0, 0x164($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X164);
    // 0x80801610: beql        $a0, $zero, L_8080162C
    if (ctx->r4 == 0) {
        // 0x80801614: sltiu       $at, $a1, 0x6
        ctx->r1 = ctx->r5 < 0X6 ? 1 : 0;
            goto L_8080162C;
    }
    goto skip_1;
    // 0x80801614: sltiu       $at, $a1, 0x6
    ctx->r1 = ctx->r5 < 0X6 ? 1 : 0;
    skip_1:
    // 0x80801618: jal         0x800C2FDC
    // 0x8080161C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_800C2FDC(rdram, ctx);
        goto after_0;
    // 0x8080161C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801620: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80801624: sb          $zero, 0x164($s0)
    MEM_B(0X164, ctx->r16) = 0;
    // 0x80801628: sltiu       $at, $a1, 0x6
    ctx->r1 = ctx->r5 < 0X6 ? 1 : 0;
L_8080162C:
    // 0x8080162C: beq         $at, $zero, L_80801730
    if (ctx->r1 == 0) {
        // 0x80801630: sw          $a1, 0x15C($s0)
        MEM_W(0X15C, ctx->r16) = ctx->r5;
            goto L_80801730;
    }
    // 0x80801630: sw          $a1, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r5;
    // 0x80801634: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80801638: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(443, 0X1D08) << 16);
    // 0x8080163C: addu        $at, $at, $t7
    gpr jr_addend_80801644 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80801640: lw          $t7, 0x1D08($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(443, 0X1D08));
    // 0x80801644: jr          $t7
    // 0x80801648: nop

    switch (jr_addend_80801644 >> 2) {
        case 0: goto L_80801730; break;
        case 1: goto L_8080164C; break;
        case 2: goto L_808016A0; break;
        case 3: goto L_808016B4; break;
        case 4: goto L_808016C8; break;
        case 5: goto L_80801724; break;
        default: switch_error(__func__, 0x80801644, 0x80801D08);
    }
    // 0x80801648: nop

L_8080164C:
    // 0x8080164C: lui         $a2, 0x40D6
    ctx->r6 = S32(0X40D6 << 16);
    // 0x80801650: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801658: jal         0x8008CCBC
    // 0x8080165C: addiu       $a1, $zero, 0x354
    ctx->r5 = ADD32(0, 0X354);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x8080165C: addiu       $a1, $zero, 0x354
    ctx->r5 = ADD32(0, 0X354);
    after_1:
    // 0x80801660: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80801664: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80801668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080166C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80801670: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801674: jal         0x8009FFD8
    // 0x80801678: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80801678: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x8080167C: jal         0x808000BC
    // 0x80801680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000BC_bswasher(rdram, ctx);
        goto after_3;
    // 0x80801680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801684: jal         0x8009C984
    // 0x80801688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_get(rdram, ctx);
        goto after_4;
    // 0x80801688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080168C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801690: jal         0x8009C914
    // 0x80801694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_5;
    // 0x80801694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801698: b           L_80801730
    // 0x8080169C: sb          $zero, 0x164($s0)
    MEM_B(0X164, ctx->r16) = 0;
        goto L_80801730;
    // 0x8080169C: sb          $zero, 0x164($s0)
    MEM_B(0X164, ctx->r16) = 0;
L_808016A0:
    // 0x808016A0: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    // 0x808016A4: jal         0x80087318
    // 0x808016A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _chfactoryworkerdirty_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x808016A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x808016AC: b           L_80801734
    // 0x808016B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801734;
    // 0x808016B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808016B4:
    // 0x808016B4: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    // 0x808016B8: jal         0x80087318
    // 0x808016BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    _chfactoryworkerdirty_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x808016BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x808016C0: b           L_80801734
    // 0x808016C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801734;
    // 0x808016C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808016C8:
    // 0x808016C8: lui         $a2, 0x3F86
    ctx->r6 = S32(0X3F86 << 16);
    // 0x808016CC: lui         $a3, 0x3F93
    ctx->r7 = S32(0X3F93 << 16);
    // 0x808016D0: addiu       $t9, $zero, 0x4E20
    ctx->r25 = ADD32(0, 0X4E20);
    // 0x808016D4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808016D8: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x808016DC: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x808016E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016E4: jal         0x8009DBB0
    // 0x808016E8: addiu       $a1, $zero, 0x573
    ctx->r5 = ADD32(0, 0X573);
    func_8009DBB0(rdram, ctx);
        goto after_8;
    // 0x808016E8: addiu       $a1, $zero, 0x573
    ctx->r5 = ADD32(0, 0X573);
    after_8:
    // 0x808016EC: lui         $a2, 0x3F59
    ctx->r6 = S32(0X3F59 << 16);
    // 0x808016F0: lui         $a3, 0x3F73
    ctx->r7 = S32(0X3F73 << 16);
    // 0x808016F4: addiu       $t0, $zero, 0x4E20
    ctx->r8 = ADD32(0, 0X4E20);
    // 0x808016F8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808016FC: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x80801700: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80801704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801708: jal         0x8009DBB0
    // 0x8080170C: addiu       $a1, $zero, 0x406
    ctx->r5 = ADD32(0, 0X406);
    func_8009DBB0(rdram, ctx);
        goto after_9;
    // 0x8080170C: addiu       $a1, $zero, 0x406
    ctx->r5 = ADD32(0, 0X406);
    after_9:
    // 0x80801710: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    // 0x80801714: jal         0x80087318
    // 0x80801718: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _chfactoryworkerdirty_entrypoint_1(rdram, ctx);
        goto after_10;
    // 0x80801718: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_10:
    // 0x8080171C: b           L_80801734
    // 0x80801720: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801734;
    // 0x80801720: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801724:
    // 0x80801724: lw          $a0, 0x160($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X160);
    // 0x80801728: jal         0x80087318
    // 0x8080172C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _chfactoryworkerdirty_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x8080172C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_11:
L_80801730:
    // 0x80801730: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801734:
    // 0x80801734: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80801738: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080173C: jr          $ra
    // 0x80801740: nop

    return;
    // 0x80801740: nop

;}
RECOMP_FUNC void func_80800BE4_chtoxicroombits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800BE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BEC: jal         0x800F54E4
    // 0x80800BF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800BF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800BF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800BF8: jal         0x800F5A00
    // 0x80800BFC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800F5A00(rdram, ctx);
        goto after_1;
    // 0x80800BFC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80800C00: lui         $at, 0xC416
    ctx->r1 = S32(0XC416 << 16);
    // 0x80800C04: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80800C08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800C0C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x80800C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800C14: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80800C18: nop

    // 0x80800C1C: bc1f        L_80800CA0
    if (!c1cs) {
        // 0x80800C20: nop
    
            goto L_80800CA0;
    }
    // 0x80800C20: nop

    // 0x80800C24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800C28: nop

    // 0x80800C2C: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80800C30: nop

    // 0x80800C34: bc1f        L_80800CA0
    if (!c1cs) {
        // 0x80800C38: nop
    
            goto L_80800CA0;
    }
    // 0x80800C38: nop

    // 0x80800C3C: jal         0x800F54E4
    // 0x80800C40: nop

    func_800F54E4(rdram, ctx);
        goto after_2;
    // 0x80800C40: nop

    after_2:
    // 0x80800C44: jal         0x800F6C5C
    // 0x80800C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_3;
    // 0x80800C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80800C4C: beq         $v0, $zero, L_80800C98
    if (ctx->r2 == 0) {
        // 0x80800C50: lw          $t6, 0x28($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X28);
            goto L_80800C98;
    }
    // 0x80800C50: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80800C54: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x80800C58: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800C5C: lwc1        $f10, 0x34($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X34);
    // 0x80800C60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800C64: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80800C68: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800C6C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800C70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80800C74: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80800C78: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800C7C: jal         0x800EFA4C
    // 0x80800C80: nop

    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x80800C80: nop

    after_4:
    // 0x80800C84: jal         0x800F54E4
    // 0x80800C88: nop

    func_800F54E4(rdram, ctx);
        goto after_5;
    // 0x80800C88: nop

    after_5:
    // 0x80800C8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800C90: jal         0x800F48BC
    // 0x80800C94: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800F48BC(rdram, ctx);
        goto after_6;
    // 0x80800C94: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_6:
L_80800C98:
    // 0x80800C98: b           L_80800CA0
    // 0x80800C9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800CA0;
    // 0x80800C9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800CA0:
    // 0x80800CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800CA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CA8: jr          $ra
    // 0x80800CAC: nop

    return;
    // 0x80800CAC: nop

;}
RECOMP_FUNC void func_80800530_chdippy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800530: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800538: jal         0x800F54E4
    // 0x8080053C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x8080053C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800540: jal         0x8010D23C
    // 0x80800544: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8010D23C(rdram, ctx);
        goto after_1;
    // 0x80800544: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80800548: beql        $v0, $zero, L_80800648
    if (ctx->r2 == 0) {
        // 0x8080054C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800648;
    }
    goto skip_0;
    // 0x8080054C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800550: jal         0x800F6C5C
    // 0x80800554: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F6C5C(rdram, ctx);
        goto after_2;
    // 0x80800554: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x80800558: beq         $v0, $zero, L_80800644
    if (ctx->r2 == 0) {
        // 0x8080055C: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800644;
    }
    // 0x8080055C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80800560: jal         0x800F64A4
    // 0x80800564: addiu       $a1, $zero, 0x601
    ctx->r5 = ADD32(0, 0X601);
    func_800F64A4(rdram, ctx);
        goto after_3;
    // 0x80800564: addiu       $a1, $zero, 0x601
    ctx->r5 = ADD32(0, 0X601);
    after_3:
    // 0x80800568: beql        $v0, $zero, L_80800648
    if (ctx->r2 == 0) {
        // 0x8080056C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800648;
    }
    goto skip_1;
    // 0x8080056C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800570: jal         0x8010C500
    // 0x80800574: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_8010C500(rdram, ctx);
        goto after_4;
    // 0x80800574: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x80800578: beql        $v0, $zero, L_80800648
    if (ctx->r2 == 0) {
        // 0x8080057C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800648;
    }
    goto skip_2;
    // 0x8080057C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80800580: jal         0x800DA298
    // 0x80800584: addiu       $a0, $zero, 0x328
    ctx->r4 = ADD32(0, 0X328);
    func_800DA298(rdram, ctx);
        goto after_5;
    // 0x80800584: addiu       $a0, $zero, 0x328
    ctx->r4 = ADD32(0, 0X328);
    after_5:
    // 0x80800588: bne         $v0, $zero, L_808005A4
    if (ctx->r2 != 0) {
        // 0x8080058C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808005A4;
    }
    // 0x8080058C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800590: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800594: jal         0x80800654
    // 0x80800598: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800654_chdippy(rdram, ctx);
        goto after_6;
    // 0x80800598: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x8080059C: b           L_80800648
    // 0x808005A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800648;
    // 0x808005A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005A4:
    // 0x808005A4: jal         0x80016B30
    // 0x808005A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80016B30(rdram, ctx);
        goto after_7;
    // 0x808005A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x808005AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808005B0: bne         $v0, $at, L_80800644
    if (ctx->r2 != ctx->r1) {
        // 0x808005B4: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800644;
    }
    // 0x808005B4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808005B8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x808005BC: jal         0x800F4BB8
    // 0x808005C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F4BB8(rdram, ctx);
        goto after_8;
    // 0x808005C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x808005C4: beql        $v0, $zero, L_80800648
    if (ctx->r2 == 0) {
        // 0x808005C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800648;
    }
    goto skip_3;
    // 0x808005C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x808005CC: jal         0x8010D254
    // 0x808005D0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_8010D254(rdram, ctx);
        goto after_9;
    // 0x808005D0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_9:
    // 0x808005D4: jal         0x800F5F24
    // 0x808005D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F5F24(rdram, ctx);
        goto after_10;
    // 0x808005D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_10:
    // 0x808005DC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808005E0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x808005E4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x808005E8: jal         0x800F1DF4
    // 0x808005EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_11;
    // 0x808005EC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_11:
    // 0x808005F0: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x808005F4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x808005F8: jal         0x800F20BC
    // 0x808005FC: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    func_800F20BC(rdram, ctx);
        goto after_12;
    // 0x808005FC: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    after_12:
    // 0x80800600: bne         $v0, $zero, L_80800618
    if (ctx->r2 != 0) {
        // 0x80800604: nop
    
            goto L_80800618;
    }
    // 0x80800604: nop

    // 0x80800608: jal         0x800F5FE0
    // 0x8080060C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F5FE0(rdram, ctx);
        goto after_13;
    // 0x8080060C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_13:
    // 0x80800610: b           L_80800648
    // 0x80800614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800648;
    // 0x80800614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800618:
    // 0x80800618: jal         0x800DA298
    // 0x8080061C: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x8080061C: addiu       $a0, $zero, 0x327
    ctx->r4 = ADD32(0, 0X327);
    after_14:
    // 0x80800620: beq         $v0, $zero, L_8080063C
    if (ctx->r2 == 0) {
        // 0x80800624: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8080063C;
    }
    // 0x80800624: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800628: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080062C: jal         0x80800654
    // 0x80800630: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80800654_chdippy(rdram, ctx);
        goto after_15;
    // 0x80800630: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_15:
    // 0x80800634: b           L_80800648
    // 0x80800638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800648;
    // 0x80800638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080063C:
    // 0x8080063C: jal         0x80800654
    // 0x80800640: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80800654_chdippy(rdram, ctx);
        goto after_16;
    // 0x80800640: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_16:
L_80800644:
    // 0x80800644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800648:
    // 0x80800648: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080064C: jr          $ra
    // 0x80800650: nop

    return;
    // 0x80800650: nop

;}
RECOMP_FUNC void func_80800534_chpawnbroker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800534: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800538: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080053C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800540: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800544: beq         $a1, $at, L_808005F4
    if (ctx->r5 == ctx->r1) {
        // 0x80800548: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_808005F4;
    }
    // 0x80800548: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8080054C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80800550: beq         $a1, $at, L_80800590
    if (ctx->r5 == ctx->r1) {
        // 0x80800554: addiu       $v0, $sp, 0x28
        ctx->r2 = ADD32(ctx->r29, 0X28);
            goto L_80800590;
    }
    // 0x80800554: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x80800558: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8080055C: beq         $a1, $at, L_808005A8
    if (ctx->r5 == ctx->r1) {
        // 0x80800560: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808005A8;
    }
    // 0x80800560: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800564: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80800568: beq         $a1, $at, L_808005B8
    if (ctx->r5 == ctx->r1) {
        // 0x8080056C: lui         $a0, 0x8080
        ctx->r4 = S32(RELOC_HI16(1012, 0XF60) << 16);
            goto L_808005B8;
    }
    // 0x8080056C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1012, 0XF60) << 16);
    // 0x80800570: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80800574: beq         $a1, $at, L_808005CC
    if (ctx->r5 == ctx->r1) {
        // 0x80800578: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_808005CC;
    }
    // 0x80800578: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8080057C: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800580: beq         $a1, $at, L_80800604
    if (ctx->r5 == ctx->r1) {
        // 0x80800584: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80800604;
    }
    // 0x80800584: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800588: b           L_80800654
    // 0x8080058C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800654;
    // 0x8080058C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800590:
    // 0x80800590: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80800594: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    // 0x80800598: jal         0x8080083C
    // 0x8080059C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    func_8080083C_chpawnbroker(rdram, ctx);
        goto after_0;
    // 0x8080059C: lh          $a2, 0x2($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X2);
    after_0:
    // 0x808005A0: b           L_80800654
    // 0x808005A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800654;
    // 0x808005A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005A8:
    // 0x808005A8: jal         0x808006FC
    // 0x808005AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_808006FC_chpawnbroker(rdram, ctx);
        goto after_1;
    // 0x808005AC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808005B0: b           L_80800654
    // 0x808005B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800654;
    // 0x808005B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005B8:
    // 0x808005B8: addiu       $a0, $a0, 0xF60
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1012, 0XF60));
    // 0x808005BC: jal         0x80088090
    // 0x808005C0: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808005C0: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x808005C4: b           L_80800654
    // 0x808005C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800654;
    // 0x808005C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808005CC:
    // 0x808005CC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808005D0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x808005D4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x808005D8: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x808005DC: and         $t7, $a2, $at
    ctx->r15 = ctx->r6 & ctx->r1;
    // 0x808005E0: srl         $a2, $t7, 16
    ctx->r6 = S32(U32(ctx->r15) >> 16);
    // 0x808005E4: jal         0x80800A50
    // 0x808005E8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    func_80800A50_chpawnbroker(rdram, ctx);
        goto after_3;
    // 0x808005E8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_3:
    // 0x808005EC: b           L_80800658
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800658;
    // 0x808005F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808005F4:
    // 0x808005F4: jal         0x80800AA8
    // 0x808005F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_80800AA8_chpawnbroker(rdram, ctx);
        goto after_4;
    // 0x808005F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_4:
    // 0x808005FC: b           L_80800654
    // 0x80800600: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_80800654;
    // 0x80800600: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80800604:
    // 0x80800604: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800608: addiu       $a2, $zero, 0x53
    ctx->r6 = ADD32(0, 0X53);
    // 0x8080060C: jal         0x800897C0
    // 0x80800610: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_5;
    // 0x80800610: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_5:
    // 0x80800614: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800618: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080061C: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x80800620: jal         0x800897E8
    // 0x80800624: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_6;
    // 0x80800624: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_6:
    // 0x80800628: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8080062C: jal         0x80089810
    // 0x80800630: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    _suexpression_entrypoint_17(rdram, ctx);
        goto after_7;
    // 0x80800630: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    after_7:
    // 0x80800634: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800638: jal         0x80108B04
    // 0x8080063C: addiu       $a1, $zero, 0x354
    ctx->r5 = ADD32(0, 0X354);
    func_80108B04(rdram, ctx);
        goto after_8;
    // 0x8080063C: addiu       $a1, $zero, 0x354
    ctx->r5 = ADD32(0, 0X354);
    after_8:
    // 0x80800640: b           L_80800654
    // 0x80800644: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800654;
    // 0x80800644: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800648: b           L_80800654
    // 0x8080064C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800654;
    // 0x8080064C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800654:
    // 0x80800654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800658:
    // 0x80800658: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080065C: jr          $ra
    // 0x80800660: nop

    return;
    // 0x80800660: nop

;}
RECOMP_FUNC void _ncpoducam_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089678: syscall     785
    recomp_syscall_handler(rdram, ctx, 0x80089678);
    return;
    // 0x8008967C: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void gsattract_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800004: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80800008: jr          $ra
    // 0x8080000C: swc1        $f4, 0x5474($at)
    MEM_W(0X5474, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x8080000C: swc1        $f4, 0x5474($at)
    MEM_W(0X5474, ctx->r1) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_800DF500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DF500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DF504: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800DF508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DF50C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800DF510: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DF514: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800DF518: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800DF51C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800DF520: sw          $t6, -0x3648($at)
    MEM_W(-0X3648, ctx->r1) = ctx->r14;
    // 0x800DF524: addiu       $a0, $a0, -0x3644
    ctx->r4 = ADD32(ctx->r4, -0X3644);
    // 0x800DF528: jal         0x800EFA4C
    // 0x800DF52C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_800EFA4C(rdram, ctx);
        goto after_0;
    // 0x800DF52C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x800DF530: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DF534: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DF538: jr          $ra
    // 0x800DF53C: nop

    return;
    // 0x800DF53C: nop

;}
RECOMP_FUNC void chnests_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FC8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(752, 0X1548) << 16);
    // 0x80800FCC: jr          $ra
    // 0x80800FD0: addiu       $v0, $v0, 0x1548
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1548));
    return;
    // 0x80800FD0: addiu       $v0, $v0, 0x1548
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(752, 0X1548));
;}
RECOMP_FUNC void sumole_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800020: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800024: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080002C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800030: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800034: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800038: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8080003C: jal         0x80088280
    // 0x80800040: addiu       $a0, $zero, 0x387
    ctx->r4 = ADD32(0, 0X387);
    _gccubesearch_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x80800040: addiu       $a0, $zero, 0x387
    ctx->r4 = ADD32(0, 0X387);
    after_0:
    // 0x80800044: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800048: bne         $v0, $zero, L_80800088
    if (ctx->r2 != 0) {
        // 0x8080004C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800088;
    }
    // 0x8080004C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800050: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800054: jal         0x800EE7F8
    // 0x80800058: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x80800058: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x8080005C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800060: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800064: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80800068: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080006C: lui         $a2, 0x4348
    ctx->r6 = S32(0X4348 << 16);
    // 0x80800070: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80800074: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800078: jal         0x800EF1B8
    // 0x8080007C: nop

    func_800EF1B8(rdram, ctx);
        goto after_2;
    // 0x8080007C: nop

    after_2:
    // 0x80800080: b           L_80800094
    // 0x80800084: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
        goto L_80800094;
    // 0x80800084: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
L_80800088:
    // 0x80800088: jal         0x80088C00
    // 0x8080008C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    _gspropctrl_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x8080008C: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    after_3:
    // 0x80800090: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
L_80800094:
    // 0x80800094: bnel        $t6, $zero, L_808000CC
    if (ctx->r14 != 0) {
        // 0x80800098: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000CC;
    }
    goto skip_0;
    // 0x80800098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8080009C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x808000A0: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x808000A4: addiu       $a0, $a0, -0x6588
    ctx->r4 = ADD32(ctx->r4, -0X6588);
    // 0x808000A8: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x808000AC: bltz        $t9, L_808000C8
    if (SIGNED(ctx->r25) < 0) {
        // 0x808000B0: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_808000C8;
    }
    // 0x808000B0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808000B4: jal         0x80086D38
    // 0x808000B8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    _chbaddiesetup_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x808000B8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x808000BC: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x808000C0: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x808000C4: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
L_808000C8:
    // 0x808000C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808000CC:
    // 0x808000CC: jal         0x8008A4B0
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x808000D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808000D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808000DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808000E0: jr          $ra
    // 0x808000E4: nop

    return;
    // 0x808000E4: nop

;}
RECOMP_FUNC void func_80800FA4_chalienkids(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FA4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800FA8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800FAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800FB0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800FB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800FB8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800FBC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800FC0: jal         0x80100094
    // 0x80800FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800FC8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800FCC: jal         0x800DA298
    // 0x80800FD0: addiu       $a0, $zero, 0x372
    ctx->r4 = ADD32(0, 0X372);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800FD0: addiu       $a0, $zero, 0x372
    ctx->r4 = ADD32(0, 0X372);
    after_1:
    // 0x80800FD4: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800FD8: beq         $v1, $zero, L_80801000
    if (ctx->r3 == 0) {
        // 0x80800FDC: nop
    
            goto L_80801000;
    }
    // 0x80800FDC: nop

    // 0x80800FE0: jal         0x800DA298
    // 0x80800FE4: addiu       $a0, $zero, 0x373
    ctx->r4 = ADD32(0, 0X373);
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x80800FE4: addiu       $a0, $zero, 0x373
    ctx->r4 = ADD32(0, 0X373);
    after_2:
    // 0x80800FE8: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
    // 0x80800FEC: beq         $v1, $zero, L_80801000
    if (ctx->r3 == 0) {
        // 0x80800FF0: nop
    
            goto L_80801000;
    }
    // 0x80800FF0: nop

    // 0x80800FF4: jal         0x800DA298
    // 0x80800FF8: addiu       $a0, $zero, 0x374
    ctx->r4 = ADD32(0, 0X374);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x80800FF8: addiu       $a0, $zero, 0x374
    ctx->r4 = ADD32(0, 0X374);
    after_3:
    // 0x80800FFC: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_80801000:
    // 0x80801000: beql        $v1, $zero, L_8080102C
    if (ctx->r3 == 0) {
        // 0x80801004: lbu         $t7, 0x95($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X95);
            goto L_8080102C;
    }
    goto skip_0;
    // 0x80801004: lbu         $t7, 0x95($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X95);
    skip_0:
    // 0x80801008: jal         0x80088848
    // 0x8080100C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x8080100C: nop

    after_4:
    // 0x80801010: bnel        $v0, $zero, L_8080102C
    if (ctx->r2 != 0) {
        // 0x80801014: lbu         $t7, 0x95($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X95);
            goto L_8080102C;
    }
    goto skip_1;
    // 0x80801014: lbu         $t7, 0x95($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X95);
    skip_1:
    // 0x80801018: jal         0x800FFAB0
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_5;
    // 0x8080101C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801020: b           L_80801128
    // 0x80801024: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801128;
    // 0x80801024: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801028: lbu         $t7, 0x95($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X95);
L_8080102C:
    // 0x8080102C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80801030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801034: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80801038: sb          $t8, 0x95($s0)
    MEM_B(0X95, ctx->r16) = ctx->r24;
    // 0x8080103C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80801040: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80801044: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80801048: jal         0x8008A0C8
    // 0x8080104C: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x8080104C: addiu       $a1, $zero, 0x154
    ctx->r5 = ADD32(0, 0X154);
    after_6:
    // 0x80801050: jal         0x80088848
    // 0x80801054: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_7;
    // 0x80801054: nop

    after_7:
    // 0x80801058: beq         $v0, $zero, L_8080109C
    if (ctx->r2 == 0) {
        // 0x8080105C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080109C;
    }
    // 0x8080105C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801060: jal         0x8010A85C
    // 0x80801064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_8;
    // 0x80801064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80801068: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8080106C: jal         0x800EE7F8
    // 0x80801070: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x80801070: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_9:
    // 0x80801074: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80801078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080107C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80801080: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80801084: jal         0x80102424
    // 0x80801088: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    func_80102424(rdram, ctx);
        goto after_10;
    // 0x80801088: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    after_10:
    // 0x8080108C: jal         0x80103014
    // 0x80801090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_11;
    // 0x80801090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80801094: b           L_80801128
    // 0x80801098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801128;
    // 0x80801098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080109C:
    // 0x8080109C: jal         0x800DA298
    // 0x808010A0: addiu       $a0, $zero, 0x376
    ctx->r4 = ADD32(0, 0X376);
    func_800DA298(rdram, ctx);
        goto after_12;
    // 0x808010A0: addiu       $a0, $zero, 0x376
    ctx->r4 = ADD32(0, 0X376);
    after_12:
    // 0x808010A4: bne         $v0, $zero, L_808010CC
    if (ctx->r2 != 0) {
        // 0x808010A8: nop
    
            goto L_808010CC;
    }
    // 0x808010A8: nop

    // 0x808010AC: lbu         $t1, 0x65($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X65);
    // 0x808010B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808010B8: andi        $t2, $t1, 0xFFFE
    ctx->r10 = ctx->r9 & 0XFFFE;
    // 0x808010BC: jal         0x80103110
    // 0x808010C0: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    func_80103110(rdram, ctx);
        goto after_13;
    // 0x808010C0: sb          $t2, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r10;
    after_13:
    // 0x808010C4: b           L_80801128
    // 0x808010C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801128;
    // 0x808010C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808010CC:
    // 0x808010CC: jal         0x800DA298
    // 0x808010D0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800DA298(rdram, ctx);
        goto after_14;
    // 0x808010D0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_14:
    // 0x808010D4: beq         $v0, $zero, L_8080111C
    if (ctx->r2 == 0) {
        // 0x808010D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080111C;
    }
    // 0x808010D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010E0: jal         0x8010A85C
    // 0x808010E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010A85C(rdram, ctx);
        goto after_15;
    // 0x808010E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808010E8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808010EC: jal         0x800EE7F8
    // 0x808010F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800EE7F8(rdram, ctx);
        goto after_16;
    // 0x808010F0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_16:
    // 0x808010F4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x808010F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808010FC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80801100: lwc1        $f6, 0x10($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X10);
    // 0x80801104: jal         0x80102424
    // 0x80801108: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    func_80102424(rdram, ctx);
        goto after_17;
    // 0x80801108: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    after_17:
    // 0x8080110C: jal         0x80103014
    // 0x80801110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80103014(rdram, ctx);
        goto after_18;
    // 0x80801110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80801114: b           L_80801128
    // 0x80801118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80801128;
    // 0x80801118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080111C:
    // 0x8080111C: jal         0x80102424
    // 0x80801120: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80102424(rdram, ctx);
        goto after_19;
    // 0x80801120: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_19:
    // 0x80801124: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80801128:
    // 0x80801128: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080112C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801130: jr          $ra
    // 0x80801134: nop

    return;
    // 0x80801134: nop

;}
RECOMP_FUNC void _fxleaves_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088940: syscall     711
    recomp_syscall_handler(rdram, ctx, 0x80088940);
    return;
    // 0x80088944: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800168_glglobalsettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800168: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080016C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800170: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80800174: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80800178: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8080017C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80800180: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80800184: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800188: jal         0x80800084
    // 0x8080018C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_80800084_glglobalsettings(rdram, ctx);
        goto after_0;
    // 0x8080018C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800190: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800194: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80800198: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080019C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x808001A0: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x808001A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808001A8:
    // 0x808001A8: jal         0x808000A4
    // 0x808001AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808000A4_glglobalsettings(rdram, ctx);
        goto after_1;
    // 0x808001AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x808001B0: bne         $v0, $zero, L_808001C8
    if (ctx->r2 != 0) {
        // 0x808001B4: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_808001C8;
    }
    // 0x808001B4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x808001B8: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x808001BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x808001C0: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x808001C4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
L_808001C8:
    // 0x808001C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808001CC: bnel        $s0, $s4, L_808001A8
    if (ctx->r16 != ctx->r20) {
        // 0x808001D0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001A8;
    }
    goto skip_0;
    // 0x808001D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001D4: slti        $at, $s2, 0x2
    ctx->r1 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x808001D8: bne         $at, $zero, L_808001E8
    if (ctx->r1 != 0) {
        // 0x808001DC: nop
    
            goto L_808001E8;
    }
    // 0x808001DC: nop

    // 0x808001E0: jal         0x80800114
    // 0x808001E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_80800114_glglobalsettings(rdram, ctx);
        goto after_2;
    // 0x808001E4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_2:
L_808001E8:
    // 0x808001E8: jal         0x8001B084
    // 0x808001EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    heap_free(rdram, ctx);
        goto after_3;
    // 0x808001EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x808001F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808001F4: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x808001F8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x808001FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800200: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800204: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80800208: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8080020C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80800210: jr          $ra
    // 0x80800214: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80800214: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bafly_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084C40: syscall     132
    recomp_syscall_handler(rdram, ctx, 0x80084C40);
    return;
    // 0x80084C44: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void chfaircoinbox_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800388: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080038C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800390: jal         0x80106790
    // 0x80800394: nop

    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80800394: nop

    after_0:
    // 0x80800398: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8080039C: addiu       $t6, $zero, 0x8C
    ctx->r14 = ADD32(0, 0X8C);
    // 0x808003A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808003A4: addiu       $a1, $zero, 0x10B8
    ctx->r5 = ADD32(0, 0X10B8);
    // 0x808003A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x808003AC: jal         0x8008A208
    // 0x808003B0: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x808003B0: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_1:
    // 0x808003B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808003B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808003BC: jr          $ra
    // 0x808003C0: nop

    return;
    // 0x808003C0: nop

;}
RECOMP_FUNC void _glsavegame_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088528: syscall     692
    recomp_syscall_handler(rdram, ctx, 0x80088528);
    return;
    // 0x8008852C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800F7DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7DE8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F7DEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F7DF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F7DF4: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F7DF8: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F7DFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F7E00: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F7E04: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F7E08: jal         0x8009AD20
    // 0x800F7E0C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009AD20(rdram, ctx);
        goto after_0;
    // 0x800F7E0C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F7E10: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7E14: jal         0x8009AD14
    // 0x800F7E18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8009AD14(rdram, ctx);
        goto after_1;
    // 0x800F7E18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x800F7E1C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7E20: jal         0x8009E7C8
    // 0x800F7E24: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    func_8009E7C8(rdram, ctx);
        goto after_2;
    // 0x800F7E24: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    after_2:
    // 0x800F7E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F7E2C: xori        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 ^ 0X2;
    // 0x800F7E30: sltiu       $v0, $t7, 0x1
    ctx->r2 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800F7E34: jr          $ra
    // 0x800F7E38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F7E38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800634_chjigsawbitcont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800634: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800638: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080063C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800640: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800644: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80800648: jal         0x800E3E8C
    // 0x8080064C: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    func_800E3E8C(rdram, ctx);
        goto after_0;
    // 0x8080064C: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    after_0:
    // 0x80800650: beql        $v0, $zero, L_808006A8
    if (ctx->r2 == 0) {
        // 0x80800654: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808006A8;
    }
    goto skip_0;
    // 0x80800654: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80800658: jal         0x8001211C
    // 0x8080065C: nop

    func_8001211C(rdram, ctx);
        goto after_1;
    // 0x8080065C: nop

    after_1:
    // 0x80800660: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x80800664: bnel        $t6, $zero, L_808006A8
    if (ctx->r14 != 0) {
        // 0x80800668: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_808006A8;
    }
    goto skip_1;
    // 0x80800668: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8080066C: jal         0x800DC0C0
    // 0x80800670: nop

    func_800DC0C0(rdram, ctx);
        goto after_2;
    // 0x80800670: nop

    after_2:
    // 0x80800674: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1644, 0X990) << 16);
    // 0x80800678: lwc1        $f4, 0x990($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1644, 0X990));
    // 0x8080067C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1644, 0XA00) << 16);
    // 0x80800680: addiu       $t7, $t7, 0xA00
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1644, 0XA00));
    // 0x80800684: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800688: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8080068C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800690: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800694: bc1f        L_808006A4
    if (!c1cs) {
        // 0x80800698: addiu       $a3, $zero, 0x2
        ctx->r7 = ADD32(0, 0X2);
            goto L_808006A4;
    }
    // 0x80800698: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8080069C: jal         0x800BBCB8
    // 0x808006A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_800BBCB8(rdram, ctx);
        goto after_3;
    // 0x808006A0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
L_808006A4:
    // 0x808006A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_808006A8:
    // 0x808006A8: jal         0x8010C9B0
    // 0x808006AC: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    func_8010C9B0(rdram, ctx);
        goto after_4;
    // 0x808006AC: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_4:
    // 0x808006B0: beql        $v0, $zero, L_808006CC
    if (ctx->r2 == 0) {
        // 0x808006B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808006CC;
    }
    goto skip_2;
    // 0x808006B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x808006B8: jal         0x8080040C
    // 0x808006BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8080040C_chjigsawbitcont(rdram, ctx);
        goto after_5;
    // 0x808006BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x808006C0: jal         0x800FFAB0
    // 0x808006C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800FFAB0(rdram, ctx);
        goto after_6;
    // 0x808006C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x808006C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006CC:
    // 0x808006CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006D0: jr          $ra
    // 0x808006D4: nop

    return;
    // 0x808006D4: nop

;}
RECOMP_FUNC void func_808012E4_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808012E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808012E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808012EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808012F0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x808012F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808012F8: lwc1        $f4, 0x34($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X34);
    // 0x808012FC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801300: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80801304: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80801308: nop

    // 0x8080130C: beq         $a2, $zero, L_80801328
    if (ctx->r6 == 0) {
        // 0x80801310: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80801328;
    }
    // 0x80801310: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80801314: jal         0x80089CD0
    // 0x80801318: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _subaddiefade_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x80801318: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080131C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801320: jal         0x80101870
    // 0x80801324: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_1;
    // 0x80801324: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
L_80801328:
    // 0x80801328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080132C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801330: jr          $ra
    // 0x80801334: nop

    return;
    // 0x80801334: nop

;}
RECOMP_FUNC void func_80800ED0_chcrusherboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800ED0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800ED4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800ED8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800EDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800EE0: jal         0x80100094
    // 0x80800EE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800EE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80800EE8: beq         $v0, $zero, L_80800EF8
    if (ctx->r2 == 0) {
        // 0x80800EEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800EF8;
    }
    // 0x80800EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800EF0: jal         0x80089848
    // 0x80800EF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _sumumbofx_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800EF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_80800EF8:
    // 0x80800EF8: jal         0x80089D40
    // 0x80800EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioloop_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800F00: jal         0x80089D48
    // 0x80800F04: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
    _subaddieaudioloop_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x80800F04: lbu         $a0, 0x24($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X24);
    after_3:
    // 0x80800F08: sb          $v0, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r2;
    // 0x80800F0C: lwl         $t6, 0x27($sp)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r29, 0X27);
    // 0x80800F10: lwr         $t6, 0x2A($sp)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r29, 0X2A);
    // 0x80800F14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800F18: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80800F1C: jal         0x800DA524
    // 0x80800F20: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    func_800DA524(rdram, ctx);
        goto after_4;
    // 0x80800F20: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x80800F24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800F28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800F2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800F30: jr          $ra
    // 0x80800F34: nop

    return;
    // 0x80800F34: nop

;}
RECOMP_FUNC void func_80106F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106F70: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80106F74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80106F78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80106F7C: jal         0x80106F30
    // 0x80106F80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80106F30(rdram, ctx);
        goto after_0;
    // 0x80106F80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80106F84: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
    // 0x80106F88: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80106F8C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80106F90: beq         $v1, $at, L_80106FC0
    if (ctx->r3 == ctx->r1) {
        // 0x80106F94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80106FC0;
    }
    // 0x80106F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106F98: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80106F9C: beq         $v1, $at, L_80106FE0
    if (ctx->r3 == ctx->r1) {
        // 0x80106FA0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80106FE0;
    }
    // 0x80106FA0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80106FA4: beq         $v1, $at, L_80107000
    if (ctx->r3 == ctx->r1) {
        // 0x80106FA8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80107000;
    }
    // 0x80106FA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106FAC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80106FB0: beq         $v1, $at, L_80107044
    if (ctx->r3 == ctx->r1) {
        // 0x80106FB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80107044;
    }
    // 0x80106FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106FB8: b           L_80107060
    // 0x80106FBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80107060;
    // 0x80106FBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80106FC0:
    // 0x80106FC0: jal         0x80107858
    // 0x80106FC4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80107858(rdram, ctx);
        goto after_1;
    // 0x80106FC4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x80106FC8: beq         $v0, $zero, L_8010705C
    if (ctx->r2 == 0) {
        // 0x80106FCC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010705C;
    }
    // 0x80106FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106FD0: jal         0x80107070
    // 0x80106FD4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80107070(rdram, ctx);
        goto after_2;
    // 0x80106FD4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80106FD8: b           L_80107060
    // 0x80106FDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80107060;
    // 0x80106FDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80106FE0:
    // 0x80106FE0: jal         0x80089C90
    // 0x80106FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80106FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80106FE8: bne         $v0, $zero, L_8010705C
    if (ctx->r2 != 0) {
        // 0x80106FEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010705C;
    }
    // 0x80106FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106FF0: jal         0x80107070
    // 0x80106FF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80107070(rdram, ctx);
        goto after_4;
    // 0x80106FF4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80106FF8: b           L_80107060
    // 0x80106FFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80107060;
    // 0x80106FFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80107000:
    // 0x80107000: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80107004: jal         0x801078AC
    // 0x80107008: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    func_801078AC(rdram, ctx);
        goto after_5;
    // 0x80107008: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_5:
    // 0x8010700C: beq         $v0, $zero, L_8010705C
    if (ctx->r2 == 0) {
        // 0x80107010: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_8010705C;
    }
    // 0x80107010: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80107014: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80107018: jal         0x800EE88C
    // 0x8010701C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    func_800EE88C(rdram, ctx);
        goto after_6;
    // 0x8010701C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    after_6:
    // 0x80107020: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80107024: jal         0x8010CAC0
    // 0x80107028: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_8010CAC0(rdram, ctx);
        goto after_7;
    // 0x80107028: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_7:
    // 0x8010702C: bne         $v0, $zero, L_8010705C
    if (ctx->r2 != 0) {
        // 0x80107030: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010705C;
    }
    // 0x80107030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107034: jal         0x80107070
    // 0x80107038: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80107070(rdram, ctx);
        goto after_8;
    // 0x80107038: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_8:
    // 0x8010703C: b           L_80107060
    // 0x80107040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80107060;
    // 0x80107040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80107044:
    // 0x80107044: jal         0x80107784
    // 0x80107048: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80107784(rdram, ctx);
        goto after_9;
    // 0x80107048: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_9:
    // 0x8010704C: beq         $v0, $zero, L_8010705C
    if (ctx->r2 == 0) {
        // 0x80107050: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8010705C;
    }
    // 0x80107050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107054: jal         0x80107070
    // 0x80107058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80107070(rdram, ctx);
        goto after_10;
    // 0x80107058: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
L_8010705C:
    // 0x8010705C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80107060:
    // 0x80107060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80107064: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80107068: jr          $ra
    // 0x8010706C: nop

    return;
    // 0x8010706C: nop

;}
RECOMP_FUNC void bakaztorpedo_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080004C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800050: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800054: lw          $t6, 0xB0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB0);
    // 0x80800058: jr          $ra
    // 0x8080005C: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
    return;
    // 0x8080005C: swc1        $f4, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80014C40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014C40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80014C44: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80014C48: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80014C4C: addiu       $s0, $s0, -0x7C30
    ctx->r16 = ADD32(ctx->r16, -0X7C30);
    // 0x80014C50: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80014C54: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014C58: addiu       $a1, $a1, -0x7C18
    ctx->r5 = ADD32(ctx->r5, -0X7C18);
    // 0x80014C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80014C60: jal         0x8002E070
    // 0x80014C64: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80014C64: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x80014C68: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014C6C: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014C70: addiu       $a1, $a1, -0x7BB0
    ctx->r5 = ADD32(ctx->r5, -0X7BB0);
    // 0x80014C74: addiu       $a0, $a0, -0x7BC8
    ctx->r4 = ADD32(ctx->r4, -0X7BC8);
    // 0x80014C78: jal         0x8002E070
    // 0x80014C7C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80014C7C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x80014C80: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80014C84: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80014C88: jal         0x8002F7E0
    // 0x80014C8C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80014C8C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80014C90: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80014C94: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80014C98: jal         0x8002F7E0
    // 0x80014C9C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80014C9C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_3:
    // 0x80014CA0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80014CA4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80014CA8: jal         0x8002F7E0
    // 0x80014CAC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80014CAC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_4:
    // 0x80014CB0: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80014CB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80014CB8: jal         0x8002F7E0
    // 0x80014CBC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80014CBC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_5:
    // 0x80014CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80014CC4: jal         0x80014F64
    // 0x80014CC8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80014F64(rdram, ctx);
        goto after_6;
    // 0x80014CC8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_6:
    // 0x80014CCC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014CD0: sw          $zero, -0x7B84($at)
    MEM_W(-0X7B84, ctx->r1) = 0;
    // 0x80014CD4: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014CD8: lui         $v1, 0x8008
    ctx->r3 = S32(0X8008 << 16);
    // 0x80014CDC: sw          $zero, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = 0;
    // 0x80014CE0: addiu       $v1, $v1, -0x7B78
    ctx->r3 = ADD32(ctx->r3, -0X7B78);
    // 0x80014CE4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80014CE8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80014CEC: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014CF0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80014CF4: sw          $t6, -0x7B7C($at)
    MEM_W(-0X7B7C, ctx->r1) = ctx->r14;
    // 0x80014CF8: addiu       $a0, $a0, -0x7B70
    ctx->r4 = ADD32(ctx->r4, -0X7B70);
    // 0x80014CFC: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80014D00: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80014D04: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014D08: sw          $t8, -0x7B74($at)
    MEM_W(-0X7B74, ctx->r1) = ctx->r24;
    // 0x80014D0C: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x80014D10: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80014D14: sw          $zero, -0x7B6C($at)
    MEM_W(-0X7B6C, ctx->r1) = 0;
    // 0x80014D18: addiu       $t0, $t0, -0x7154
    ctx->r8 = ADD32(ctx->r8, -0X7154);
    // 0x80014D1C: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x80014D20: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x80014D24: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80014D28: addiu       $t1, $t1, -0x7158
    ctx->r9 = ADD32(ctx->r9, -0X7158);
    // 0x80014D2C: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80014D30: addiu       $v0, $a1, 0x77B0
    ctx->r2 = ADD32(ctx->r5, 0X77B0);
    // 0x80014D34: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80014D38: addiu       $t2, $t2, -0x70FC
    ctx->r10 = ADD32(ctx->r10, -0X70FC);
    // 0x80014D3C: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80014D40: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x80014D44: addiu       $t3, $t3, -0x7100
    ctx->r11 = ADD32(ctx->r11, -0X7100);
    // 0x80014D48: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x80014D4C: beq         $t4, $zero, L_80014D64
    if (ctx->r12 == 0) {
        // 0x80014D50: sw          $zero, 0x0($t3)
        MEM_W(0X0, ctx->r11) = 0;
            goto L_80014D64;
    }
    // 0x80014D50: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x80014D54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80014D58:
    // 0x80014D58: andi        $t5, $v0, 0xF
    ctx->r13 = ctx->r2 & 0XF;
    // 0x80014D5C: bnel        $t5, $zero, L_80014D58
    if (ctx->r13 != 0) {
        // 0x80014D60: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80014D58;
    }
    goto skip_0;
    // 0x80014D60: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
L_80014D64:
    // 0x80014D64: lui         $s0, 0x8008
    ctx->r16 = S32(0X8008 << 16);
    // 0x80014D68: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80014D6C: addiu       $s0, $s0, -0x7368
    ctx->r16 = ADD32(ctx->r16, -0X7368);
    // 0x80014D70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014D74: addiu       $t6, $t6, -0x7368
    ctx->r14 = ADD32(ctx->r14, -0X7368);
    // 0x80014D78: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x80014D7C: lui         $a3, 0x8001
    ctx->r7 = S32(0X8001 << 16);
    // 0x80014D80: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80014D84: sw          $v0, -0xBD8($at)
    MEM_W(-0XBD8, ctx->r1) = ctx->r2;
    // 0x80014D88: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80014D8C: addiu       $a3, $a3, 0x4A88
    ctx->r7 = ADD32(ctx->r7, 0X4A88);
    // 0x80014D90: addiu       $a1, $a1, -0x71B8
    ctx->r5 = ADD32(ctx->r5, -0X71B8);
    // 0x80014D94: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80014D98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80014D9C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80014DA0: jal         0x8001DCB0
    // 0x80014DA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001DCB0(rdram, ctx);
        goto after_7;
    // 0x80014DA4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80014DA8: jal         0x8002E510
    // 0x80014DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_8;
    // 0x80014DAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80014DB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80014DB4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80014DB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80014DBC: jr          $ra
    // 0x80014DC0: nop

    return;
    // 0x80014DC0: nop

;}
RECOMP_FUNC void func_80800B9C_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800BA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800BA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800BA8: beq         $a1, $zero, L_80800BD4
    if (ctx->r5 == 0) {
        // 0x80800BAC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80800BD4;
    }
    // 0x80800BAC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80800BB0: lbu         $t7, 0x64($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X64);
    // 0x80800BB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800BB8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80800BBC: bnel        $t7, $zero, L_80800BF4
    if (ctx->r15 != 0) {
        // 0x80800BC0: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BF4;
    }
    goto skip_0;
    // 0x80800BC0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800BC4: jal         0x80090734
    // 0x80800BC8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80090734(rdram, ctx);
        goto after_0;
    // 0x80800BC8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80800BCC: b           L_80800BF0
    // 0x80800BD0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
        goto L_80800BF0;
    // 0x80800BD0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80800BD4:
    // 0x80800BD4: lbu         $t8, 0x64($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X64);
    // 0x80800BD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800BDC: beql        $t8, $zero, L_80800BF4
    if (ctx->r24 == 0) {
        // 0x80800BE0: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_80800BF4;
    }
    goto skip_1;
    // 0x80800BE0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800BE4: jal         0x80090708
    // 0x80800BE8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80090708(rdram, ctx);
        goto after_1;
    // 0x80800BE8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80800BEC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80800BF0:
    // 0x80800BF0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_80800BF4:
    // 0x80800BF4: sb          $t9, 0x64($a3)
    MEM_B(0X64, ctx->r7) = ctx->r25;
    // 0x80800BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800BFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800C00: jr          $ra
    // 0x80800C04: nop

    return;
    // 0x80800C04: nop

;}
RECOMP_FUNC void _bsvanswim_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800841C0: syscall     106
    recomp_syscall_handler(rdram, ctx, 0x800841C0);
    return;
    // 0x800841C4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void chpiranha_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801A6C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1804, 0X1BA8) << 16);
    // 0x80801A70: jr          $ra
    // 0x80801A74: addiu       $v0, $v0, 0x1BA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1804, 0X1BA8));
    return;
    // 0x80801A74: addiu       $v0, $v0, 0x1BA8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1804, 0X1BA8));
;}
RECOMP_FUNC void _bstaxi_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083DD0: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083DD0);
    return;
    // 0x80083DD4: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_800D9240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9240: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D9244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9248: jal         0x800F8E78
    // 0x800D924C: nop

    func_800F8E78(rdram, ctx);
        goto after_0;
    // 0x800D924C: nop

    after_0:
    // 0x800D9250: jal         0x800F89BC
    // 0x800D9254: nop

    func_800F89BC(rdram, ctx);
        goto after_1;
    // 0x800D9254: nop

    after_1:
    // 0x800D9258: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800D925C: jal         0x800F8A5C
    // 0x800D9260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F8A5C(rdram, ctx);
        goto after_2;
    // 0x800D9260: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x800D9264: jal         0x800887F8
    // 0x800D9268: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _glcutDll_entrypoint_10(rdram, ctx);
        goto after_3;
    // 0x800D9268: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800D926C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800D9270: jal         0x800F9070
    // 0x800D9274: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F9070(rdram, ctx);
        goto after_4;
    // 0x800D9274: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x800D9278: jal         0x80088808
    // 0x800D927C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _glcutDll_entrypoint_12(rdram, ctx);
        goto after_5;
    // 0x800D927C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x800D9280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D9284: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D9288: jr          $ra
    // 0x800D928C: nop

    return;
    // 0x800D928C: nop

;}
RECOMP_FUNC void func_80800440_chchuffycont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800440: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80800444: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080044C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800450: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800454: jal         0x8010A828
    // 0x80800458: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    func_8010A828(rdram, ctx);
        goto after_0;
    // 0x80800458: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x8080045C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800460: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800464: jr          $ra
    // 0x80800468: nop

    return;
    // 0x80800468: nop

;}
RECOMP_FUNC void func_80800EF8_chwarppad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800F00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800F04: jal         0x80100094
    // 0x80800F08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800F08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800F0C: beq         $v0, $zero, L_80800F1C
    if (ctx->r2 == 0) {
        // 0x80800F10: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800F1C;
    }
    // 0x80800F10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800F14: jal         0x80087CC8
    // 0x80800F18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcnewoption_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800F18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_80800F1C:
    // 0x80800F1C: jal         0x80801018
    // 0x80800F20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80801018_chwarppad(rdram, ctx);
        goto after_2;
    // 0x80800F20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80800F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800F28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800F2C: jr          $ra
    // 0x80800F30: nop

    return;
    // 0x80800F30: nop

;}
RECOMP_FUNC void _chfactorybattery_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087490: syscall     577
    recomp_syscall_handler(rdram, ctx, 0x80087490);
    return;
    // 0x80087494: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80806EE4_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80806EE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80806EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80806EEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80806EF0: jal         0x80100094
    // 0x80806EF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80806EF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80806EF8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80806EFC: sb          $t6, 0x5F($v0)
    MEM_B(0X5F, ctx->r2) = ctx->r14;
    // 0x80806F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80806F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80806F08: jr          $ra
    // 0x80806F0C: nop

    return;
    // 0x80806F0C: nop

;}
RECOMP_FUNC void func_80110928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110928: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8011092C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110930: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80110934: lw          $a0, 0x68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68);
    // 0x80110938: jal         0x800F5B38
    // 0x8011093C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800F5B38(rdram, ctx);
        goto after_0;
    // 0x8011093C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80110940: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80110944: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80110948: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8011094C: jal         0x800136E4
    // 0x80110950: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x80110950: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80110954: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80110958: jal         0x80110970
    // 0x8011095C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80110970(rdram, ctx);
        goto after_2;
    // 0x8011095C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80110960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80110964: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80110968: jr          $ra
    // 0x8011096C: nop

    return;
    // 0x8011096C: nop

;}
RECOMP_FUNC void _ncbadive_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800892B8: syscall     770
    recomp_syscall_handler(rdram, ctx, 0x800892B8);
    return;
    // 0x800892BC: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_8009EC3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EC3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EC40: sw          $zero, 0x7054($at)
    MEM_W(0X7054, ctx->r1) = 0;
    // 0x8009EC44: sw          $zero, 0x7050($at)
    MEM_W(0X7050, ctx->r1) = 0;
    // 0x8009EC48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EC4C: sw          $zero, 0x7058($at)
    MEM_W(0X7058, ctx->r1) = 0;
    // 0x8009EC50: sw          $zero, 0x705C($at)
    MEM_W(0X705C, ctx->r1) = 0;
    // 0x8009EC54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EC58: jr          $ra
    // 0x8009EC5C: sb          $zero, 0x7060($at)
    MEM_B(0X7060, ctx->r1) = 0;
    return;
    // 0x8009EC5C: sb          $zero, 0x7060($at)
    MEM_B(0X7060, ctx->r1) = 0;
;}
RECOMP_FUNC void func_80800EB8_chfiregen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EB8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800EBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800EC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800EC4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80800EC8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1514) << 16);
    // 0x80800ECC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800ED0: jal         0x800DC178
    // 0x80800ED4: lwc1        $f14, 0x1514($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1514));
    func_800DC178(rdram, ctx);
        goto after_0;
    // 0x80800ED4: lwc1        $f14, 0x1514($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1514));
    after_0:
    // 0x80800ED8: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x80800EDC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80800EE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800EE4: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80800EE8: srl         $t8, $t7, 20
    ctx->r24 = S32(U32(ctx->r15) >> 20);
    // 0x80800EEC: addiu       $t9, $t8, -0x1AB
    ctx->r25 = ADD32(ctx->r24, -0X1AB);
    // 0x80800EF0: sltiu       $at, $t9, 0xB
    ctx->r1 = ctx->r25 < 0XB ? 1 : 0;
    // 0x80800EF4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80800EF8: beq         $at, $zero, L_80800F88
    if (ctx->r1 == 0) {
        // 0x80800EFC: swc1        $f4, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
            goto L_80800F88;
    }
    // 0x80800EFC: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x80800F00: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80800F04: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1588, 0X1518) << 16);
    // 0x80800F08: addu        $at, $at, $t9
    gpr jr_addend_80800F10 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800F0C: lw          $t9, 0x1518($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1588, 0X1518));
    // 0x80800F10: jr          $t9
    // 0x80800F14: nop

    switch (jr_addend_80800F10 >> 2) {
        case 0: goto L_80800F18; break;
        case 1: goto L_80800F88; break;
        case 2: goto L_80800F28; break;
        case 3: goto L_80800F88; break;
        case 4: goto L_80800F3C; break;
        case 5: goto L_80800F88; break;
        case 6: goto L_80800F50; break;
        case 7: goto L_80800F88; break;
        case 8: goto L_80800F64; break;
        case 9: goto L_80800F88; break;
        case 10: goto L_80800F78; break;
        default: switch_error(__func__, 0x80800F10, 0x80801518);
    }
    // 0x80800F14: nop

L_80800F18:
    // 0x80800F18: lhu         $t0, 0x6E($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800F1C: andi        $t1, $t0, 0xFE00
    ctx->r9 = ctx->r8 & 0XFE00;
    // 0x80800F20: b           L_80800F88
    // 0x80800F24: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
        goto L_80800F88;
    // 0x80800F24: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
L_80800F28:
    // 0x80800F28: lhu         $t2, 0x6E($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800F2C: andi        $t3, $t2, 0xFE00
    ctx->r11 = ctx->r10 & 0XFE00;
    // 0x80800F30: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80800F34: b           L_80800F88
    // 0x80800F38: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
        goto L_80800F88;
    // 0x80800F38: sh          $t4, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r12;
L_80800F3C:
    // 0x80800F3C: lhu         $t5, 0x6E($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800F40: andi        $t6, $t5, 0xFE00
    ctx->r14 = ctx->r13 & 0XFE00;
    // 0x80800F44: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80800F48: b           L_80800F88
    // 0x80800F4C: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
        goto L_80800F88;
    // 0x80800F4C: sh          $t7, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r15;
L_80800F50:
    // 0x80800F50: lhu         $t8, 0x6E($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800F54: andi        $t9, $t8, 0xFE00
    ctx->r25 = ctx->r24 & 0XFE00;
    // 0x80800F58: ori         $t0, $t9, 0x3
    ctx->r8 = ctx->r25 | 0X3;
    // 0x80800F5C: b           L_80800F88
    // 0x80800F60: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
        goto L_80800F88;
    // 0x80800F60: sh          $t0, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r8;
L_80800F64:
    // 0x80800F64: lhu         $t1, 0x6E($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800F68: andi        $t2, $t1, 0xFE00
    ctx->r10 = ctx->r9 & 0XFE00;
    // 0x80800F6C: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80800F70: b           L_80800F88
    // 0x80800F74: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
        goto L_80800F88;
    // 0x80800F74: sh          $t3, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r11;
L_80800F78:
    // 0x80800F78: lhu         $t4, 0x6E($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X6E);
    // 0x80800F7C: andi        $t5, $t4, 0xFE00
    ctx->r13 = ctx->r12 & 0XFE00;
    // 0x80800F80: ori         $t6, $t5, 0x5
    ctx->r14 = ctx->r13 | 0X5;
    // 0x80800F84: sh          $t6, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r14;
L_80800F88:
    // 0x80800F88: jal         0x800C9128
    // 0x80800F8C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_800C9128(rdram, ctx);
        goto after_1;
    // 0x80800F8C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x80800F90: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80800F94: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80800F98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800F9C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800FA0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80800FA4: jal         0x800C8800
    // 0x80800FA8: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    func_800C8800(rdram, ctx);
        goto after_2;
    // 0x80800FA8: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x80800FAC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80800FB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800FB4: jal         0x800EE7F8
    // 0x80800FB8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    func_800EE7F8(rdram, ctx);
        goto after_3;
    // 0x80800FB8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80800FBC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80800FC0: jal         0x800C8900
    // 0x80800FC4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800C8900(rdram, ctx);
        goto after_4;
    // 0x80800FC4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800FC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800FCC: jal         0x800EE84C
    // 0x80800FD0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800EE84C(rdram, ctx);
        goto after_5;
    // 0x80800FD0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80800FD4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80800FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800FDC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80800FE0: jal         0x800EFA88
    // 0x80800FE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800EFA88(rdram, ctx);
        goto after_6;
    // 0x80800FE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x80800FE8: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80800FEC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80800FF0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800FF4: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80800FF8: jal         0x800C8E84
    // 0x80800FFC: nop

    func_800C8E84(rdram, ctx);
        goto after_7;
    // 0x80800FFC: nop

    after_7:
    // 0x80801000: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801004: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801008: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080100C: jr          $ra
    // 0x80801010: nop

    return;
    // 0x80801010: nop

;}
RECOMP_FUNC void func_80800608_chdumbwaiterlift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800608: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080060C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800610: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800614: beq         $a3, $zero, L_80800638
    if (ctx->r7 == 0) {
        // 0x80800618: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80800638;
    }
    // 0x80800618: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080061C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800620: beq         $a3, $at, L_80800648
    if (ctx->r7 == ctx->r1) {
        // 0x80800624: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800648;
    }
    // 0x80800624: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800628: beq         $a3, $at, L_80800664
    if (ctx->r7 == ctx->r1) {
        // 0x8080062C: nop
    
            goto L_80800664;
    }
    // 0x8080062C: nop

    // 0x80800630: b           L_80800760
    // 0x80800634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800760;
    // 0x80800634: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800638:
    // 0x80800638: jal         0x80800560
    // 0x8080063C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80800560_chdumbwaiterlift(rdram, ctx);
        goto after_0;
    // 0x8080063C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80800640: b           L_80800760
    // 0x80800644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800760;
    // 0x80800644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800648:
    // 0x80800648: jal         0x80800B40
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B40_chdumbwaiterlift(rdram, ctx);
        goto after_1;
    // 0x8080064C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800654: jal         0x80101FDC
    // 0x80800658: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_80101FDC(rdram, ctx);
        goto after_2;
    // 0x80800658: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_2:
    // 0x8080065C: b           L_80800760
    // 0x80800660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800760;
    // 0x80800660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800664:
    // 0x80800664: jal         0x808009B8
    // 0x80800668: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_808009B8_chdumbwaiterlift(rdram, ctx);
        goto after_3;
    // 0x80800668: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x8080066C: jal         0x808008B4
    // 0x80800670: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_808008B4_chdumbwaiterlift(rdram, ctx);
        goto after_4;
    // 0x80800670: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_4:
    // 0x80800674: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800678: lhu         $t9, 0x6E($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X6E);
    // 0x8080067C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80800680: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800684: andi        $t0, $t9, 0xFE00
    ctx->r8 = ctx->r25 & 0XFE00;
    // 0x80800688: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8080068C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80800690: sh          $t1, 0x6E($s0)
    MEM_H(0X6E, ctx->r16) = ctx->r9;
    // 0x80800694: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800698: jal         0x800EE7F8
    // 0x8080069C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x8080069C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_5:
    // 0x808006A0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808006A4: jal         0x800EE7F8
    // 0x808006A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x808006A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x808006AC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x808006B0: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x808006B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B8: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x808006BC: beq         $at, $zero, L_808006D0
    if (ctx->r1 == 0) {
        // 0x808006C0: lui         $at, 0xC316
        ctx->r1 = S32(0XC316 << 16);
            goto L_808006D0;
    }
    // 0x808006C0: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x808006C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808006C8: b           L_808006E0
    // 0x808006CC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
        goto L_808006E0;
    // 0x808006CC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
L_808006D0:
    // 0x808006D0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808006D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x808006D8: nop

    // 0x808006DC: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
L_808006E0:
    // 0x808006E0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x808006E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808006E8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x808006EC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x808006F0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x808006F4: jal         0x80101FDC
    // 0x808006F8: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    func_80101FDC(rdram, ctx);
        goto after_7;
    // 0x808006F8: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    after_7:
    // 0x808006FC: jal         0x800F54E4
    // 0x80800700: nop

    func_800F54E4(rdram, ctx);
        goto after_8;
    // 0x80800700: nop

    after_8:
    // 0x80800704: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800708: jal         0x800F8418
    // 0x8080070C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800F8418(rdram, ctx);
        goto after_9;
    // 0x8080070C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x80800710: jal         0x800F54E4
    // 0x80800714: nop

    func_800F54E4(rdram, ctx);
        goto after_10;
    // 0x80800714: nop

    after_10:
    // 0x80800718: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080071C: jal         0x800F8444
    // 0x80800720: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    func_800F8444(rdram, ctx);
        goto after_11;
    // 0x80800720: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    after_11:
    // 0x80800724: jal         0x80800B40
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800B40_chdumbwaiterlift(rdram, ctx);
        goto after_12;
    // 0x80800728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8080072C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80800730: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1200, 0XBC6) << 16);
    // 0x80800734: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800738: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8080073C: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x80800740: lbu         $a2, 0xBC6($a2)
    ctx->r6 = MEM_BU(ctx->r6, (int16_t)RELOC_LO16(1200, 0XBC6));
    // 0x80800744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800748: jal         0x80085748
    // 0x8080074C: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    _capod_entrypoint_21(rdram, ctx);
        goto after_13;
    // 0x8080074C: addiu       $a3, $zero, 0x2010
    ctx->r7 = ADD32(0, 0X2010);
    after_13:
    // 0x80800750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800754: jal         0x8008A4B0
    // 0x80800758: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_14;
    // 0x80800758: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x8080075C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800760:
    // 0x80800760: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800764: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800768: jr          $ra
    // 0x8080076C: nop

    return;
    // 0x8080076C: nop

;}
RECOMP_FUNC void func_80801004_chclinker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801004: jr          $ra
    // 0x80801008: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80801008: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void baeggcursor_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800180: lw          $t6, 0x68($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X68);
    // 0x80800184: jr          $ra
    // 0x80800188: sb          $a1, 0xA($t6)
    MEM_B(0XA, ctx->r14) = ctx->r5;
    return;
    // 0x80800188: sb          $a1, 0xA($t6)
    MEM_B(0XA, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void chmineproplight_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1580, 0X240) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x240
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1580, 0X240));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x240
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1580, 0X240));
;}
RECOMP_FUNC void func_80800018_chbiggafoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080001C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800020: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800024: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800028: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1216, 0XEE0) << 16);
    // 0x8080002C: lwc1        $f6, 0xEE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1216, 0XEE0));
    // 0x80800030: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80800034: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800038: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080003C: jal         0x80102FDC
    // 0x80800040: nop

    func_80102FDC(rdram, ctx);
        goto after_0;
    // 0x80800040: nop

    after_0:
    // 0x80800044: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800048: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080004C: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80800050: swc1        $f0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f0.u32l;
    // 0x80800054: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80800058: jal         0x800A9C98
    // 0x8080005C: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    func_800A9C98(rdram, ctx);
        goto after_1;
    // 0x8080005C: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x80800060: beq         $v0, $zero, L_80800078
    if (ctx->r2 == 0) {
        // 0x80800064: nop
    
            goto L_80800078;
    }
    // 0x80800064: nop

    // 0x80800068: jal         0x800DA544
    // 0x8080006C: addiu       $a0, $zero, 0x1C7
    ctx->r4 = ADD32(0, 0X1C7);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x8080006C: addiu       $a0, $zero, 0x1C7
    ctx->r4 = ADD32(0, 0X1C7);
    after_2:
    // 0x80800070: jal         0x800DA524
    // 0x80800074: addiu       $a0, $zero, 0x1CC
    ctx->r4 = ADD32(0, 0X1CC);
    func_800DA524(rdram, ctx);
        goto after_3;
    // 0x80800074: addiu       $a0, $zero, 0x1CC
    ctx->r4 = ADD32(0, 0X1CC);
    after_3:
L_80800078:
    // 0x80800078: jal         0x80088848
    // 0x8080007C: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x8080007C: nop

    after_4:
    // 0x80800080: beq         $v0, $zero, L_80800098
    if (ctx->r2 == 0) {
        // 0x80800084: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800098;
    }
    // 0x80800084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800088: jal         0x80102424
    // 0x8080008C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80102424(rdram, ctx);
        goto after_5;
    // 0x8080008C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_5:
    // 0x80800090: b           L_808000E0
    // 0x80800094: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
        goto L_808000E0;
    // 0x80800094: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_80800098:
    // 0x80800098: jal         0x800DA298
    // 0x8080009C: addiu       $a0, $zero, 0x1CC
    ctx->r4 = ADD32(0, 0X1CC);
    func_800DA298(rdram, ctx);
        goto after_6;
    // 0x8080009C: addiu       $a0, $zero, 0x1CC
    ctx->r4 = ADD32(0, 0X1CC);
    after_6:
    // 0x808000A0: beq         $v0, $zero, L_808000B8
    if (ctx->r2 == 0) {
        // 0x808000A4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808000B8;
    }
    // 0x808000A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A8: jal         0x800FFAB0
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_7;
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808000B0: b           L_808000F0
    // 0x808000B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808000F0;
    // 0x808000B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000B8:
    // 0x808000B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x808000BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808000C0: addiu       $a1, $zero, 0x320
    ctx->r5 = ADD32(0, 0X320);
    // 0x808000C4: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x808000C8: jal         0x8008A0C8
    // 0x808000CC: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    _subaddiemarker_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x808000CC: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_8:
    // 0x808000D0: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x808000D4: jal         0x800EE7F8
    // 0x808000D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x808000D8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_9:
    // 0x808000DC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_808000E0:
    // 0x808000E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808000E4: nop

    // 0x808000E8: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x808000EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000F0:
    // 0x808000F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808000F4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808000F8: jr          $ra
    // 0x808000FC: nop

    return;
    // 0x808000FC: nop

;}
RECOMP_FUNC void cadbfunc_entrypoint_28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800D48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800D4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800D50: jal         0x80800C9C
    // 0x80800D54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80800C9C_cadbfunc(rdram, ctx);
        goto after_0;
    // 0x80800D54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800D58: bne         $v0, $zero, L_80800D68
    if (ctx->r2 != 0) {
        // 0x80800D5C: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80800D68;
    }
    // 0x80800D5C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80800D60: b           L_80800D98
    // 0x80800D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800D98;
    // 0x80800D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800D68:
    // 0x80800D68: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D6C: beql        $t6, $zero, L_80800D88
    if (ctx->r14 == 0) {
        // 0x80800D70: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_80800D88;
    }
    goto skip_0;
    // 0x80800D70: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80800D74: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80800D78: or          $t8, $t7, $v1
    ctx->r24 = ctx->r15 | ctx->r3;
    // 0x80800D7C: b           L_80800D94
    // 0x80800D80: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_80800D94;
    // 0x80800D80: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80800D84: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_80800D88:
    // 0x80800D88: nor         $t0, $v1, $zero
    ctx->r8 = ~(ctx->r3 | 0);
    // 0x80800D8C: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x80800D90: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_80800D94:
    // 0x80800D94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800D98:
    // 0x80800D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DA0: jr          $ra
    // 0x80800DA4: nop

    return;
    // 0x80800DA4: nop

;}
RECOMP_FUNC void func_80800E18_chamazongoldhordeofficial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800E24: jal         0x80100094
    // 0x80800E28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E2C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80800E30: lbu         $a1, 0x67($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X67);
    // 0x80800E34: jal         0x80800DB4
    // 0x80800E38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800DB4_chamazongoldhordeofficial(rdram, ctx);
        goto after_1;
    // 0x80800E38: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800E3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E40: jal         0x80102424
    // 0x80800E44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80102424(rdram, ctx);
        goto after_2;
    // 0x80800E44: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800E48: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80800E4C: addiu       $t6, $zero, -0x3E7
    ctx->r14 = ADD32(0, -0X3E7);
    // 0x80800E50: sh          $t6, 0x8($t7)
    MEM_H(0X8, ctx->r15) = ctx->r14;
    // 0x80800E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800E5C: jr          $ra
    // 0x80800E60: nop

    return;
    // 0x80800E60: nop

;}
RECOMP_FUNC void func_808000D0_chfactorytoxicpools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808000DC: jal         0x80100094
    // 0x808000E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808000E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808000E4: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x808000E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808000EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000F0: beq         $a0, $zero, L_80800108
    if (ctx->r4 == 0) {
        // 0x808000F4: nop
    
            goto L_80800108;
    }
    // 0x808000F4: nop

    // 0x808000F8: beql        $a0, $at, L_8080011C
    if (ctx->r4 == ctx->r1) {
        // 0x808000FC: addiu       $a0, $v1, 0x4
        ctx->r4 = ADD32(ctx->r3, 0X4);
            goto L_8080011C;
    }
    goto skip_0;
    // 0x808000FC: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x80800100: b           L_80800178
    // 0x80800104: nop

        goto L_80800178;
    // 0x80800104: nop

L_80800108:
    // 0x80800108: jal         0x80085800
    // 0x8080010C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    _chswitch_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x8080010C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80800110: b           L_80800178
    // 0x80800114: nop

        goto L_80800178;
    // 0x80800114: nop

    // 0x80800118: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
L_8080011C:
    // 0x8080011C: jal         0x800D9078
    // 0x80800120: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800D9078(rdram, ctx);
        goto after_2;
    // 0x80800120: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x80800124: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800128: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8080012C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800130: lwc1        $f12, 0x4($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80800134: lui         $a2, 0x4100
    ctx->r6 = S32(0X4100 << 16);
    // 0x80800138: lui         $a3, 0x4461
    ctx->r7 = S32(0X4461 << 16);
    // 0x8080013C: jal         0x800F12D4
    // 0x80800140: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    func_800F12D4(rdram, ctx);
        goto after_3;
    // 0x80800140: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x80800144: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800148: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8080014C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80800150: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800154: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80800158: nop

    // 0x8080015C: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x80800160: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80800164: beq         $t8, $zero, L_80800178
    if (ctx->r24 == 0) {
        // 0x80800168: nop
    
            goto L_80800178;
    }
    // 0x80800168: nop

    // 0x8080016C: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x80800170: jal         0x80103110
    // 0x80800174: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80103110(rdram, ctx);
        goto after_4;
    // 0x80800174: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
L_80800178:
    // 0x80800178: jal         0x80800270
    // 0x8080017C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80800270_chfactorytoxicpools(rdram, ctx);
        goto after_5;
    // 0x8080017C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80800180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800184: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800188: jr          $ra
    // 0x8080018C: nop

    return;
    // 0x8080018C: nop

;}
RECOMP_FUNC void func_800F6BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F6BE4: bltz        $a0, L_800F6C10
    if (SIGNED(ctx->r4) < 0) {
        // 0x800F6BE8: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800F6C10;
    }
    // 0x800F6BE8: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800F6BEC: beq         $at, $zero, L_800F6C10
    if (ctx->r1 == 0) {
        // 0x800F6BF0: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800F6C10;
    }
    // 0x800F6BF0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F6BF4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F6BF8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800F6BFC: lw          $t7, 0x5490($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5490);
    // 0x800F6C00: beql        $t7, $zero, L_800F6C14
    if (ctx->r15 == 0) {
        // 0x800F6C04: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F6C14;
    }
    goto skip_0;
    // 0x800F6C04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800F6C08: jr          $ra
    // 0x800F6C0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800F6C0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F6C10:
    // 0x800F6C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F6C14:
    // 0x800F6C14: jr          $ra
    // 0x800F6C18: nop

    return;
    // 0x800F6C18: nop

;}
RECOMP_FUNC void func_80800228_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8080022C: slti        $at, $a1, 0x12
    ctx->r1 = SIGNED(ctx->r5) < 0X12 ? 1 : 0;
    // 0x80800230: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800234: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800238: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8080023C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800240: bne         $at, $zero, L_80800288
    if (ctx->r1 != 0) {
        // 0x80800244: sw          $a2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r6;
            goto L_80800288;
    }
    // 0x80800244: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800248: slti        $at, $a1, 0x53
    ctx->r1 = SIGNED(ctx->r5) < 0X53 ? 1 : 0;
    // 0x8080024C: bne         $at, $zero, L_80800268
    if (ctx->r1 != 0) {
        // 0x80800250: addiu       $t6, $a1, -0x2E
        ctx->r14 = ADD32(ctx->r5, -0X2E);
            goto L_80800268;
    }
    // 0x80800250: addiu       $t6, $a1, -0x2E
    ctx->r14 = ADD32(ctx->r5, -0X2E);
    // 0x80800254: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x80800258: beq         $a1, $at, L_808002A8
    if (ctx->r5 == ctx->r1) {
        // 0x8080025C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808002A8;
    }
    // 0x8080025C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800260: b           L_8080050C
    // 0x80800264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080050C;
    // 0x80800264: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800268:
    // 0x80800268: sltiu       $at, $t6, 0x25
    ctx->r1 = ctx->r14 < 0X25 ? 1 : 0;
    // 0x8080026C: beq         $at, $zero, L_808002A0
    if (ctx->r1 == 0) {
        // 0x80800270: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_808002A0;
    }
    // 0x80800270: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800274: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1612, 0X1120) << 16);
    // 0x80800278: addu        $at, $at, $t6
    gpr jr_addend_80800280 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8080027C: lw          $t6, 0x1120($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1612, 0X1120));
    // 0x80800280: jr          $t6
    // 0x80800284: nop

    switch (jr_addend_80800280 >> 2) {
        case 0: goto L_8080030C; break;
        case 1: goto L_80800380; break;
        case 2: goto L_808002A0; break;
        case 3: goto L_808002A0; break;
        case 4: goto L_808002A0; break;
        case 5: goto L_808002A0; break;
        case 6: goto L_808002A0; break;
        case 7: goto L_808002A0; break;
        case 8: goto L_808002A0; break;
        case 9: goto L_808002A0; break;
        case 10: goto L_808002A0; break;
        case 11: goto L_808002A0; break;
        case 12: goto L_808002A0; break;
        case 13: goto L_808002A0; break;
        case 14: goto L_808002A0; break;
        case 15: goto L_80800454; break;
        case 16: goto L_808002A0; break;
        case 17: goto L_808002A0; break;
        case 18: goto L_8080040C; break;
        case 19: goto L_808002A0; break;
        case 20: goto L_808002A0; break;
        case 21: goto L_808002A0; break;
        case 22: goto L_808002A0; break;
        case 23: goto L_808002A0; break;
        case 24: goto L_808002A0; break;
        case 25: goto L_808002A0; break;
        case 26: goto L_808002A0; break;
        case 27: goto L_808002A0; break;
        case 28: goto L_808002A0; break;
        case 29: goto L_808002A0; break;
        case 30: goto L_808002A0; break;
        case 31: goto L_808002A0; break;
        case 32: goto L_808002A0; break;
        case 33: goto L_808002A0; break;
        case 34: goto L_808002A0; break;
        case 35: goto L_808002A0; break;
        case 36: goto L_808003F0; break;
        default: switch_error(__func__, 0x80800280, 0x80801120);
    }
    // 0x80800284: nop

L_80800288:
    // 0x80800288: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8080028C: beq         $a1, $at, L_808003B0
    if (ctx->r5 == ctx->r1) {
        // 0x80800290: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_808003B0;
    }
    // 0x80800290: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80800294: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80800298: beq         $a1, $at, L_808002E4
    if (ctx->r5 == ctx->r1) {
        // 0x8080029C: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_808002E4;
    }
    // 0x8080029C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_808002A0:
    // 0x808002A0: b           L_8080050C
    // 0x808002A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8080050C;
    // 0x808002A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808002A8:
    // 0x808002A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002AC: jal         0x800897C0
    // 0x808002B0: addiu       $a2, $zero, 0x2A
    ctx->r6 = ADD32(0, 0X2A);
    _suexpression_entrypoint_7(rdram, ctx);
        goto after_0;
    // 0x808002B0: addiu       $a2, $zero, 0x2A
    ctx->r6 = ADD32(0, 0X2A);
    after_0:
    // 0x808002B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808002B8: jal         0x80100094
    // 0x808002BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x808002BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808002C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002C4: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x808002C8: jal         0x800897E8
    // 0x808002CC: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    _suexpression_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808002CC: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_2:
    // 0x808002D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808002D4: jal         0x80108B04
    // 0x808002D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_3;
    // 0x808002D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808002DC: b           L_8080050C
    // 0x808002E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080050C;
    // 0x808002E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808002E4:
    // 0x808002E4: lhu         $t8, 0x72($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X72);
    // 0x808002E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808002EC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x808002F0: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x808002F4: bnel        $t9, $at, L_8080050C
    if (ctx->r25 != ctx->r1) {
        // 0x808002F8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080050C;
    }
    goto skip_0;
    // 0x808002F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x808002FC: jal         0x808001CC
    // 0x80800300: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808001CC_chmayafarmer(rdram, ctx);
        goto after_4;
    // 0x80800300: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80800304: b           L_8080050C
    // 0x80800308: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080050C;
    // 0x80800308: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080030C:
    // 0x8080030C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80800310: addiu       $at, $zero, 0xF06
    ctx->r1 = ADD32(0, 0XF06);
    // 0x80800314: lbu         $t1, 0x74($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X74);
    // 0x80800318: andi        $t2, $t1, 0xFFBF
    ctx->r10 = ctx->r9 & 0XFFBF;
    // 0x8080031C: sb          $t2, 0x74($t0)
    MEM_B(0X74, ctx->r8) = ctx->r10;
    // 0x80800320: lh          $v0, 0x38($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X38);
    // 0x80800324: beq         $v0, $at, L_80800370
    if (ctx->r2 == ctx->r1) {
        // 0x80800328: addiu       $at, $zero, 0xF07
        ctx->r1 = ADD32(0, 0XF07);
            goto L_80800370;
    }
    // 0x80800328: addiu       $at, $zero, 0xF07
    ctx->r1 = ADD32(0, 0XF07);
    // 0x8080032C: bne         $v0, $at, L_80800508
    if (ctx->r2 != ctx->r1) {
        // 0x80800330: addiu       $a0, $zero, 0x64
        ctx->r4 = ADD32(0, 0X64);
            goto L_80800508;
    }
    // 0x80800330: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x80800334: jal         0x800C01A8
    // 0x80800338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C01A8(rdram, ctx);
        goto after_5;
    // 0x80800338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080033C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800340: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800344: addiu       $a2, $zero, 0x2010
    ctx->r6 = ADD32(0, 0X2010);
    // 0x80800348: jal         0x808000B0
    // 0x8080034C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    func_808000B0_chmayafarmer(rdram, ctx);
        goto after_6;
    // 0x8080034C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    after_6:
    // 0x80800350: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80800354: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800358: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080035C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80800360: jal         0x800D1000
    // 0x80800364: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800D1000(rdram, ctx);
        goto after_7;
    // 0x80800364: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80800368: b           L_8080050C
    // 0x8080036C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080050C;
    // 0x8080036C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800370:
    // 0x80800370: jal         0x80800138
    // 0x80800374: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800138_chmayafarmer(rdram, ctx);
        goto after_8;
    // 0x80800374: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x80800378: b           L_8080050C
    // 0x8080037C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080050C;
    // 0x8080037C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800380:
    // 0x80800380: lh          $t4, 0x38($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X38);
    // 0x80800384: addiu       $at, $zero, 0xF06
    ctx->r1 = ADD32(0, 0XF06);
    // 0x80800388: bnel        $t4, $at, L_8080050C
    if (ctx->r12 != ctx->r1) {
        // 0x8080038C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080050C;
    }
    goto skip_1;
    // 0x8080038C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80800390: jal         0x800C07F4
    // 0x80800394: nop

    func_800C07F4(rdram, ctx);
        goto after_9;
    // 0x80800394: nop

    after_9:
    // 0x80800398: bnel        $v0, $zero, L_8080050C
    if (ctx->r2 != 0) {
        // 0x8080039C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080050C;
    }
    goto skip_2;
    // 0x8080039C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x808003A0: jal         0x800DA544
    // 0x808003A4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800DA544(rdram, ctx);
        goto after_10;
    // 0x808003A4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_10:
    // 0x808003A8: b           L_8080050C
    // 0x808003AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080050C;
    // 0x808003AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808003B0:
    // 0x808003B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808003B4: beq         $v0, $at, L_808003D8
    if (ctx->r2 == ctx->r1) {
        // 0x808003B8: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_808003D8;
    }
    // 0x808003B8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x808003BC: bne         $v0, $at, L_808003E8
    if (ctx->r2 != ctx->r1) {
        // 0x808003C0: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808003E8;
    }
    // 0x808003C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808003C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808003C8: jal         0x80800000
    // 0x808003CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80800000_chmayafarmer(rdram, ctx);
        goto after_11;
    // 0x808003CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x808003D0: b           L_8080050C
    // 0x808003D4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080050C;
    // 0x808003D4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808003D8:
    // 0x808003D8: jal         0x80800138
    // 0x808003DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800138_chmayafarmer(rdram, ctx);
        goto after_12;
    // 0x808003DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_12:
    // 0x808003E0: b           L_8080050C
    // 0x808003E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8080050C;
    // 0x808003E4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_808003E8:
    // 0x808003E8: b           L_8080050C
    // 0x808003EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8080050C;
    // 0x808003EC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_808003F0:
    // 0x808003F0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x808003F4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1612, 0X125C) << 16);
    // 0x808003F8: addiu       $a0, $a0, 0x125C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1612, 0X125C));
    // 0x808003FC: jal         0x80088090
    // 0x80800400: lw          $a1, 0x38($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X38);
    _gcdialogcamera_entrypoint_3(rdram, ctx);
        goto after_13;
    // 0x80800400: lw          $a1, 0x38($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X38);
    after_13:
    // 0x80800404: b           L_8080050C
    // 0x80800408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080050C;
    // 0x80800408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080040C:
    // 0x8080040C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800410: lhu         $v1, 0x76($t6)
    ctx->r3 = MEM_HU(ctx->r14, 0X76);
    // 0x80800414: srl         $t8, $v1, 7
    ctx->r24 = S32(U32(ctx->r3) >> 7);
    // 0x80800418: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8080041C: sll         $t1, $t9, 7
    ctx->r9 = S32(ctx->r25 << 7);
    // 0x80800420: andi        $t2, $v1, 0x7F
    ctx->r10 = ctx->r3 & 0X7F;
    // 0x80800424: or          $t0, $t1, $t2
    ctx->r8 = ctx->r9 | ctx->r10;
    // 0x80800428: sh          $t0, 0x76($t6)
    MEM_H(0X76, ctx->r14) = ctx->r8;
    // 0x8080042C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80800430: lhu         $t4, 0x76($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X76);
    // 0x80800434: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x80800438: srl         $t5, $t4, 7
    ctx->r13 = S32(U32(ctx->r12) >> 7);
    // 0x8080043C: bgtzl       $t5, L_8080050C
    if (SIGNED(ctx->r13) > 0) {
        // 0x80800440: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8080050C;
    }
    goto skip_3;
    // 0x80800440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x80800444: jal         0x808001CC
    // 0x80800448: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808001CC_chmayafarmer(rdram, ctx);
        goto after_14;
    // 0x80800448: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_14:
    // 0x8080044C: b           L_8080050C
    // 0x80800450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8080050C;
    // 0x80800450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800454:
    // 0x80800454: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1612, 0X126C) << 16);
    // 0x80800458: addiu       $s1, $s1, 0x126C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1612, 0X126C));
    // 0x8080045C: jal         0x800CBC3C
    // 0x80800460: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800CBC3C(rdram, ctx);
        goto after_15;
    // 0x80800460: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80800464: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80800468: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080046C: lhu         $v1, 0x76($t8)
    ctx->r3 = MEM_HU(ctx->r24, 0X76);
    // 0x80800470: srl         $a1, $v1, 7
    ctx->r5 = S32(U32(ctx->r3) >> 7);
    // 0x80800474: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x80800478: bne         $at, $zero, L_80800498
    if (ctx->r1 != 0) {
        // 0x8080047C: andi        $t9, $v1, 0x7F
        ctx->r25 = ctx->r3 & 0X7F;
            goto L_80800498;
    }
    // 0x8080047C: andi        $t9, $v1, 0x7F
    ctx->r25 = ctx->r3 & 0X7F;
    // 0x80800480: ori         $t7, $t9, 0x400
    ctx->r15 = ctx->r25 | 0X400;
    // 0x80800484: sh          $t7, 0x76($t8)
    MEM_H(0X76, ctx->r24) = ctx->r15;
    // 0x80800488: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8080048C: lhu         $a1, 0x76($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0X76);
    // 0x80800490: srl         $t2, $a1, 7
    ctx->r10 = S32(U32(ctx->r5) >> 7);
    // 0x80800494: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_80800498:
    // 0x80800498: blez        $a1, L_80800508
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8080049C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80800508;
    }
    // 0x8080049C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x808004A0: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x808004A4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_808004A8:
    // 0x808004A8: jal         0x800CD08C
    // 0x808004AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800CD08C(rdram, ctx);
        goto after_16;
    // 0x808004AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_16:
    // 0x808004B0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x808004B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808004B8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x808004BC: jal         0x800DC178
    // 0x808004C0: nop

    func_800DC178(rdram, ctx);
        goto after_17;
    // 0x808004C0: nop

    after_17:
    // 0x808004C4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x808004C8: addiu       $a0, $zero, 0x2F8
    ctx->r4 = ADD32(0, 0X2F8);
    // 0x808004CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808004D0: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x808004D4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808004D8: jal         0x80108528
    // 0x808004DC: nop

    func_80108528(rdram, ctx);
        goto after_18;
    // 0x808004DC: nop

    after_18:
    // 0x808004E0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x808004E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808004E8: lw          $t4, 0x0($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X0);
    // 0x808004EC: sw          $t4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r12;
    // 0x808004F0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x808004F4: lhu         $t3, 0x76($t5)
    ctx->r11 = MEM_HU(ctx->r13, 0X76);
    // 0x808004F8: srl         $t9, $t3, 7
    ctx->r25 = S32(U32(ctx->r11) >> 7);
    // 0x808004FC: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80800500: bnel        $at, $zero, L_808004A8
    if (ctx->r1 != 0) {
        // 0x80800504: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_808004A8;
    }
    goto skip_4;
    // 0x80800504: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    skip_4:
L_80800508:
    // 0x80800508: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080050C:
    // 0x8080050C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800510: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800514: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800518: jr          $ra
    // 0x8080051C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8080051C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
