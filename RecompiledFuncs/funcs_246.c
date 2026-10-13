#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void bafpctrl_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800CF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800CF8: lw          $a0, 0x90($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X90);
    // 0x80800CFC: jal         0x800EE7F8
    // 0x80800D00: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800D00: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x80800D04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800D08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800D0C: jr          $ra
    // 0x80800D10: nop

    return;
    // 0x80800D10: nop

;}
RECOMP_FUNC void func_8009E084(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E08C: addiu       $a1, $zero, 0x417
    ctx->r5 = ADD32(0, 0X417);
    // 0x8009E090: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8009E094: jal         0x8009DF18
    // 0x8009E098: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    func_8009DF18(rdram, ctx);
        goto after_0;
    // 0x8009E098: addiu       $a3, $zero, 0x36B0
    ctx->r7 = ADD32(0, 0X36B0);
    after_0:
    // 0x8009E09C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E0A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E0A4: jr          $ra
    // 0x8009E0A8: nop

    return;
    // 0x8009E0A8: nop

;}
RECOMP_FUNC void func_8009E0DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E0DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009E0E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009E0E4: lw          $t6, 0x104($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X104);
    // 0x8009E0E8: jal         0x800C3CE8
    // 0x8009E0EC: lbu         $a0, 0x2($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X2);
    func_800C3CE8(rdram, ctx);
        goto after_0;
    // 0x8009E0EC: lbu         $a0, 0x2($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X2);
    after_0:
    // 0x8009E0F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009E0F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009E0F8: jr          $ra
    // 0x8009E0FC: nop

    return;
    // 0x8009E0FC: nop

;}
RECOMP_FUNC void func_800A7B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7B24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A7B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7B2C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800A7B30: jal         0x800A759C
    // 0x800A7B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A759C(rdram, ctx);
        goto after_0;
    // 0x800A7B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800A7B38: jal         0x80013430
    // 0x800A7B3C: nop

    func_80013430(rdram, ctx);
        goto after_1;
    // 0x800A7B3C: nop

    after_1:
    // 0x800A7B40: jal         0x800B5DF4
    // 0x800A7B44: nop

    func_800B5DF4(rdram, ctx);
        goto after_2;
    // 0x800A7B44: nop

    after_2:
    // 0x800A7B48: jal         0x800CA060
    // 0x800A7B4C: nop

    func_800CA060(rdram, ctx);
        goto after_3;
    // 0x800A7B4C: nop

    after_3:
    // 0x800A7B50: jal         0x800DF35C
    // 0x800A7B54: nop

    func_800DF35C(rdram, ctx);
        goto after_4;
    // 0x800A7B54: nop

    after_4:
    // 0x800A7B58: jal         0x800A7380
    // 0x800A7B5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800A7380(rdram, ctx);
        goto after_5;
    // 0x800A7B5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x800A7B60: jal         0x80088250
    // 0x800A7B64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcsectionDll_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x800A7B64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800A7B68: jal         0x80088228
    // 0x800A7B6C: nop

    _gclevel_entrypoint_1(rdram, ctx);
        goto after_7;
    // 0x800A7B6C: nop

    after_7:
    // 0x800A7B70: jal         0x80087A48
    // 0x800A7B74: nop

    _gcgame_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x800A7B74: nop

    after_8:
    // 0x800A7B78: jal         0x8008B64C
    // 0x800A7B7C: nop

    func_8008B64C(rdram, ctx);
        goto after_9;
    // 0x800A7B7C: nop

    after_9:
    // 0x800A7B80: jal         0x800FB908
    // 0x800A7B84: nop

    func_800FB908(rdram, ctx);
        goto after_10;
    // 0x800A7B84: nop

    after_10:
    // 0x800A7B88: jal         0x800C2A90
    // 0x800A7B8C: nop

    func_800C2A90(rdram, ctx);
        goto after_11;
    // 0x800A7B8C: nop

    after_11:
    // 0x800A7B90: jal         0x800A8710
    // 0x800A7B94: nop

    func_800A8710(rdram, ctx);
        goto after_12;
    // 0x800A7B94: nop

    after_12:
    // 0x800A7B98: jal         0x800E4290
    // 0x800A7B9C: nop

    func_800E4290(rdram, ctx);
        goto after_13;
    // 0x800A7B9C: nop

    after_13:
    // 0x800A7BA0: jal         0x800887B8
    // 0x800A7BA4: nop

    _glcutDll_entrypoint_2(rdram, ctx);
        goto after_14;
    // 0x800A7BA4: nop

    after_14:
    // 0x800A7BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7BAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A7BB0: jr          $ra
    // 0x800A7BB4: nop

    return;
    // 0x800A7BB4: nop

;}
RECOMP_FUNC void _ncfixposrot_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089230: syscall     767
    recomp_syscall_handler(rdram, ctx, 0x80089230);
    return;
    // 0x80089234: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_808002A4_bsbtrot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808002AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808002B0: jal         0x8008CABC
    // 0x808002B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808002B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808002B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808002BC: jal         0x8008B264
    // 0x808002C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_getIndex(rdram, ctx);
        goto after_1;
    // 0x808002C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808002C4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808002C8: beql        $v0, $a1, L_808002F8
    if (ctx->r2 == ctx->r5) {
        // 0x808002CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808002F8;
    }
    goto skip_0;
    // 0x808002CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808002D0: jal         0x8008AED4
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setIndex(rdram, ctx);
        goto after_2;
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808002D8: jal         0x8008B2B4
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_getAnimTimer(rdram, ctx);
        goto after_3;
    // 0x808002DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808002E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x808002E4: jal         0x8008B24C
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_4;
    // 0x808002E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808002EC: jal         0x8008B064
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_5;
    // 0x808002F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x808002F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808002F8:
    // 0x808002F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800300: jr          $ra
    // 0x80800304: nop

    return;
    // 0x80800304: nop

;}
RECOMP_FUNC void func_8080164C_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080164C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801650: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801654: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801658: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8080165C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801660: jal         0x8009C128
    // 0x80801664: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009C128(rdram, ctx);
        goto after_0;
    // 0x80801664: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80801668: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8080166C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80801670: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80801674: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x80801678: beq         $at, $zero, L_80801754
    if (ctx->r1 == 0) {
        // 0x8080167C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80801754;
    }
    // 0x8080167C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801680: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(427, 0X1B5C) << 16);
    // 0x80801684: addu        $at, $at, $t7
    gpr jr_addend_8080168C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80801688: lw          $t7, 0x1B5C($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(427, 0X1B5C));
    // 0x8080168C: jr          $t7
    // 0x80801690: nop

    switch (jr_addend_8080168C >> 2) {
        case 0: goto L_80801694; break;
        case 1: goto L_808016C4; break;
        case 2: goto L_808016E0; break;
        case 3: goto L_80801720; break;
        case 4: goto L_8080173C; break;
        default: switch_error(__func__, 0x8080168C, 0x80801B5C);
    }
    // 0x80801690: nop

L_80801694:
    // 0x80801694: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80801698: jal         0x800F1DF4
    // 0x8080169C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_1;
    // 0x8080169C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x808016A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808016A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808016A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016AC: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x808016B0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808016B4: jal         0x8009C914
    // 0x808016B8: nop

    yaw_setIdeal(rdram, ctx);
        goto after_2;
    // 0x808016B8: nop

    after_2:
    // 0x808016BC: b           L_80801758
    // 0x808016C0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_80801758;
    // 0x808016C0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808016C4:
    // 0x808016C4: lui         $a2, 0x3F99
    ctx->r6 = S32(0X3F99 << 16);
    // 0x808016C8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x808016CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016D0: jal         0x8008CCBC
    // 0x808016D4: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_3;
    // 0x808016D4: addiu       $a1, $zero, 0xF1
    ctx->r5 = ADD32(0, 0XF1);
    after_3:
    // 0x808016D8: b           L_80801758
    // 0x808016DC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_80801758;
    // 0x808016DC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_808016E0:
    // 0x808016E0: lw          $t8, 0x15C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X15C);
    // 0x808016E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808016E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808016EC: bne         $t8, $at, L_80801710
    if (ctx->r24 != ctx->r1) {
        // 0x808016F0: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80801710;
    }
    // 0x808016F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x808016F4: lui         $a2, 0x3A83
    ctx->r6 = S32(0X3A83 << 16);
    // 0x808016F8: ori         $a2, $a2, 0x126F
    ctx->r6 = ctx->r6 | 0X126F;
    // 0x808016FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801700: jal         0x80085338
    // 0x80801704: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    _batimer_set(rdram, ctx);
        goto after_4;
    // 0x80801704: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80801708: b           L_80801758
    // 0x8080170C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_80801758;
    // 0x8080170C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80801710:
    // 0x80801710: jal         0x80085338
    // 0x80801714: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    _batimer_set(rdram, ctx);
        goto after_5;
    // 0x80801714: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_5:
    // 0x80801718: b           L_80801758
    // 0x8080171C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_80801758;
    // 0x8080171C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80801720:
    // 0x80801720: lui         $a2, 0x3FA6
    ctx->r6 = S32(0X3FA6 << 16);
    // 0x80801724: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x80801728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080172C: jal         0x8008CCBC
    // 0x80801730: addiu       $a1, $zero, 0xF2
    ctx->r5 = ADD32(0, 0XF2);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_6;
    // 0x80801730: addiu       $a1, $zero, 0xF2
    ctx->r5 = ADD32(0, 0XF2);
    after_6:
    // 0x80801734: b           L_80801758
    // 0x80801738: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_80801758;
    // 0x80801738: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8080173C:
    // 0x8080173C: lw          $a1, 0x188($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X188);
    // 0x80801740: jal         0x800F1DF4
    // 0x80801744: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_7;
    // 0x80801744: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_7:
    // 0x80801748: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080174C: jal         0x8009C914
    // 0x80801750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    yaw_setIdeal(rdram, ctx);
        goto after_8;
    // 0x80801750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_80801754:
    // 0x80801754: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_80801758:
    // 0x80801758: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
    // 0x8080175C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80801760: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80801764: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801768: jr          $ra
    // 0x8080176C: nop

    return;
    // 0x8080176C: nop

;}
RECOMP_FUNC void func_808005D0_chlagoonbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808005DC: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808005E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005E4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808005E8: bnel        $t7, $at, L_808005FC
    if (ctx->r15 != ctx->r1) {
        // 0x808005EC: lw          $t8, 0x1C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1C);
            goto L_808005FC;
    }
    goto skip_0;
    // 0x808005EC: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808005F0: jal         0x800FFAB0
    // 0x808005F4: nop

    func_800FFAB0(rdram, ctx);
        goto after_0;
    // 0x808005F4: nop

    after_0:
    // 0x808005F8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
L_808005FC:
    // 0x808005FC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1052, 0XA88) << 16);
    // 0x80800600: addiu       $a1, $a1, 0xA88
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1052, 0XA88));
    // 0x80800604: bne         $t8, $zero, L_80800648
    if (ctx->r24 != 0) {
        // 0x80800608: addiu       $a0, $zero, 0x156
        ctx->r4 = ADD32(0, 0X156);
            goto L_80800648;
    }
    // 0x80800608: addiu       $a0, $zero, 0x156
    ctx->r4 = ADD32(0, 0X156);
    // 0x8080060C: jal         0x80108474
    // 0x80800610: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_1;
    // 0x80800610: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800614: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80800618: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x8080061C: jal         0x80102FDC
    // 0x80800620: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80102FDC(rdram, ctx);
        goto after_2;
    // 0x80800620: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80800624: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1052, 0XA7C) << 16);
    // 0x80800628: addiu       $a1, $a1, 0xA7C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1052, 0XA7C));
    // 0x8080062C: addiu       $a0, $zero, 0x157
    ctx->r4 = ADD32(0, 0X157);
    // 0x80800630: jal         0x80108474
    // 0x80800634: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80108474(rdram, ctx);
        goto after_3;
    // 0x80800634: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80800638: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x8080063C: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800640: jal         0x80102FDC
    // 0x80800644: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80102FDC(rdram, ctx);
        goto after_4;
    // 0x80800644: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
L_80800648:
    // 0x80800648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080064C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800650: jr          $ra
    // 0x80800654: nop

    return;
    // 0x80800654: nop

;}
RECOMP_FUNC void func_800E42A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E42A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E42AC: jr          $ra
    // 0x800E42B0: lw          $v0, -0x2B00($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2B00);
    return;
    // 0x800E42B0: lw          $v0, -0x2B00($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2B00);
;}
RECOMP_FUNC void _bsturn_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084110: syscall     103
    recomp_syscall_handler(rdram, ctx, 0x80084110);
    return;
    // 0x80084114: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void plcamera_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800294: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800298: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080029C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808002A0: jal         0x800F5EF8
    // 0x808002A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F5EF8(rdram, ctx);
        goto after_0;
    // 0x808002A4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808002A8: jal         0x80110014
    // 0x808002AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110014(rdram, ctx);
        goto after_1;
    // 0x808002AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808002B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808002B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808002B8: jal         0x801110EC
    // 0x808002BC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_801110EC(rdram, ctx);
        goto after_2;
    // 0x808002BC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808002C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808002C8: jr          $ra
    // 0x808002CC: nop

    return;
    // 0x808002CC: nop

;}
RECOMP_FUNC void func_80801C60_chaliendad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801C60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801C68: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x80801C6C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80801C70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801C74: beql        $t6, $zero, L_80801C90
    if (ctx->r14 == 0) {
        // 0x80801C78: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801C90;
    }
    goto skip_0;
    // 0x80801C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801C7C: jal         0x800856B8
    // 0x80801C80: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    _capod_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80801C80: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80801C84: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80801C88: sw          $zero, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = 0;
    // 0x80801C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801C90:
    // 0x80801C90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801C94: jr          $ra
    // 0x80801C98: nop

    return;
    // 0x80801C98: nop

;}
RECOMP_FUNC void _ch2dbaddy_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800865D8: syscall     345
    recomp_syscall_handler(rdram, ctx, 0x800865D8);
    return;
    // 0x800865DC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void badrone_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080039C: lw          $t6, 0x54($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X54);
    // 0x808003A0: sw          $a1, 0x48($t6)
    MEM_W(0X48, ctx->r14) = ctx->r5;
    // 0x808003A4: jal         0x80800348
    // 0x808003A8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800348_badrone(rdram, ctx);
        goto after_0;
    // 0x808003A8: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x808003AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808003B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808003B4: jr          $ra
    // 0x808003B8: nop

    return;
    // 0x808003B8: nop

;}
RECOMP_FUNC void badata_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800B68: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80800B6C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80800B70: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80800B74: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80800B78: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80800B7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800B80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800B84: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(473, 0X10C8) << 16);
    // 0x80800B88: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80800B8C: addiu       $a1, $a1, 0x10C8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(473, 0X10C8));
    // 0x80800B90: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800B94: jal         0x80800AA4
    // 0x80800B98: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_80800AA4_badata(rdram, ctx);
        goto after_0;
    // 0x80800B98: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80800B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800BA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800BA4: jr          $ra
    // 0x80800BA8: nop

    return;
    // 0x80800BA8: nop

;}
RECOMP_FUNC void func_800A85A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A85A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800A85AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A85B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A85B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A85B8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A85BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A85C0: addiu       $s1, $s1, 0x7688
    ctx->r17 = ADD32(ctx->r17, 0X7688);
    // 0x800A85C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A85C8: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_800A85CC:
    // 0x800A85CC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800A85D0: beql        $t6, $zero, L_800A85F0
    if (ctx->r14 == 0) {
        // 0x800A85D4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800A85F0;
    }
    goto skip_0;
    // 0x800A85D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x800A85D8: jal         0x800A8380
    // 0x800A85DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A8380(rdram, ctx);
        goto after_0;
    // 0x800A85DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800A85E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A85E4: jal         0x800A84EC
    // 0x800A85E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A84EC(rdram, ctx);
        goto after_1;
    // 0x800A85E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800A85EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800A85F0:
    // 0x800A85F0: bne         $s0, $s2, L_800A85CC
    if (ctx->r16 != ctx->r18) {
        // 0x800A85F4: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_800A85CC;
    }
    // 0x800A85F4: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x800A85F8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800A85FC: jal         0x800A84EC
    // 0x800A8600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800A84EC(rdram, ctx);
        goto after_2;
    // 0x800A8600: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800A8604: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A8608: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A860C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A8610: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A8614: jr          $ra
    // 0x800A8618: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800A8618: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800064_chhillbilly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800064: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800068: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080006C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800070: jal         0x8008A108
    // 0x80800074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _sucoaster_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800078: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x8080007C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80800080: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80800084: sll         $t8, $t6, 29
    ctx->r24 = S32(ctx->r14 << 29);
    // 0x80800088: bltzl       $t8, L_80800288
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080008C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800288;
    }
    goto skip_0;
    // 0x8080008C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800090: jal         0x8008A0E8
    // 0x80800094: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    _subaddieskeleton_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x80800094: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x80800098: jal         0x8008A110
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x808000A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000A4: jal         0x800EE940
    // 0x808000A8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800EE940(rdram, ctx);
        goto after_3;
    // 0x808000A8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x808000AC: lhu         $t9, 0x72($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X72);
    // 0x808000B0: srl         $t0, $t9, 10
    ctx->r8 = S32(U32(ctx->r25) >> 10);
    // 0x808000B4: addiu       $t1, $t0, -0x2
    ctx->r9 = ADD32(ctx->r8, -0X2);
    // 0x808000B8: sltiu       $at, $t1, 0x15
    ctx->r1 = ctx->r9 < 0X15 ? 1 : 0;
    // 0x808000BC: beq         $at, $zero, L_80800284
    if (ctx->r1 == 0) {
        // 0x808000C0: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80800284;
    }
    // 0x808000C0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808000C4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(852, 0XA70) << 16);
    // 0x808000C8: addu        $at, $at, $t1
    gpr jr_addend_808000D0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x808000CC: lw          $t1, 0xA70($at)
    ctx->r9 = ADD32(ctx->r1, (int16_t)RELOC_LO16(852, 0XA70));
    // 0x808000D0: jr          $t1
    // 0x808000D4: nop

    switch (jr_addend_808000D0 >> 2) {
        case 0: goto L_808000D8; break;
        case 1: goto L_808000D8; break;
        case 2: goto L_80800284; break;
        case 3: goto L_80800284; break;
        case 4: goto L_80800284; break;
        case 5: goto L_80800284; break;
        case 6: goto L_808000D8; break;
        case 7: goto L_80800284; break;
        case 8: goto L_80800284; break;
        case 9: goto L_80800284; break;
        case 10: goto L_80800284; break;
        case 11: goto L_80800284; break;
        case 12: goto L_80800284; break;
        case 13: goto L_80800284; break;
        case 14: goto L_80800284; break;
        case 15: goto L_80800284; break;
        case 16: goto L_80800284; break;
        case 17: goto L_808000FC; break;
        case 18: goto L_8080019C; break;
        case 19: goto L_808001D4; break;
        case 20: goto L_8080025C; break;
        default: switch_error(__func__, 0x808000D0, 0x80800A70);
    }
    // 0x808000D4: nop

L_808000D8:
    // 0x808000D8: jal         0x8080042C
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080042C_chhillbilly(rdram, ctx);
        goto after_4;
    // 0x808000DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x808000E0: beq         $v0, $zero, L_80800284
    if (ctx->r2 == 0) {
        // 0x808000E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800284;
    }
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: jal         0x8008A148
    // 0x808000EC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_5;
    // 0x808000EC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_5:
    // 0x808000F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808000F4: b           L_80800284
    // 0x808000F8: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
        goto L_80800284;
    // 0x808000F8: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
L_808000FC:
    // 0x808000FC: jal         0x80800944
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800944_chhillbilly(rdram, ctx);
        goto after_6;
    // 0x80800100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80800104: jal         0x8010CD28
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010CD28(rdram, ctx);
        goto after_7;
    // 0x80800108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080010C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80800110: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800114: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080011C: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80800120: jal         0x80102BF8
    // 0x80800124: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    func_80102BF8(rdram, ctx);
        goto after_8;
    // 0x80800124: lui         $a3, 0x4396
    ctx->r7 = S32(0X4396 << 16);
    after_8:
    // 0x80800128: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(852, 0XCA8) << 16);
    // 0x8080012C: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80800130: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80800134: addiu       $a2, $a2, 0xCA8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(852, 0XCA8));
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: jal         0x80089D20
    // 0x80800140: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_9;
    // 0x80800140: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x80800144: jal         0x80101DDC
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_10;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8080014C: beql        $v0, $zero, L_80800288
    if (ctx->r2 == 0) {
        // 0x80800150: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800288;
    }
    goto skip_1;
    // 0x80800150: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800154: lbu         $t2, 0x74($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X74);
    // 0x80800158: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8080015C: beql        $t3, $zero, L_80800170
    if (ctx->r11 == 0) {
        // 0x80800160: lw          $t4, 0x64($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X64);
            goto L_80800170;
    }
    goto skip_2;
    // 0x80800160: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
    skip_2:
    // 0x80800164: b           L_8080018C
    // 0x80800168: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
        goto L_8080018C;
    // 0x80800168: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8080016C: lw          $t4, 0x64($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X64);
L_80800170:
    // 0x80800170: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80800174: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80800178: bgez        $t6, L_80800188
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8080017C: nop
    
            goto L_80800188;
    }
    // 0x8080017C: nop

    // 0x80800180: b           L_80800188
    // 0x80800184: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80800188;
    // 0x80800184: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80800188:
    // 0x80800188: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8080018C:
    // 0x8080018C: jal         0x8008A148
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_11;
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80800194: b           L_80800288
    // 0x80800198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800288;
    // 0x80800198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080019C:
    // 0x8080019C: jal         0x8008A190
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_19(rdram, ctx);
        goto after_12;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x808001A4: jal         0x80101DDC
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101DDC(rdram, ctx);
        goto after_13;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x808001AC: beq         $v0, $zero, L_80800284
    if (ctx->r2 == 0) {
        // 0x808001B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800284;
    }
    // 0x808001B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B4: addiu       $a1, $zero, 0x78A
    ctx->r5 = ADD32(0, 0X78A);
    // 0x808001B8: jal         0x808009D8
    // 0x808001BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808009D8_chhillbilly(rdram, ctx);
        goto after_14;
    // 0x808001BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x808001C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C4: jal         0x8008A148
    // 0x808001C8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_15;
    // 0x808001C8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_15:
    // 0x808001CC: b           L_80800288
    // 0x808001D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800288;
    // 0x808001D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808001D4:
    // 0x808001D4: jal         0x8008A190
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_19(rdram, ctx);
        goto after_16;
    // 0x808001D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808001DC: jal         0x8008A160
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_13(rdram, ctx);
        goto after_17;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x808001E4: bnel        $v0, $zero, L_80800248
    if (ctx->r2 != 0) {
        // 0x808001E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800248;
    }
    goto skip_3;
    // 0x808001E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x808001EC: jal         0x808002F0
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808002F0_chhillbilly(rdram, ctx);
        goto after_18;
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x808001F4: beq         $v0, $zero, L_80800210
    if (ctx->r2 == 0) {
        // 0x808001F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800210;
    }
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: jal         0x8008A148
    // 0x80800200: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_19;
    // 0x80800200: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_19:
    // 0x80800204: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800208: b           L_80800284
    // 0x8080020C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_80800284;
    // 0x8080020C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80800210:
    // 0x80800210: jal         0x80089F78
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_4(rdram, ctx);
        goto after_20;
    // 0x80800214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80800218: beql        $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x8080021C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800248;
    }
    goto skip_4;
    // 0x8080021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800220: jal         0x8008A110
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sucoaster_entrypoint_3(rdram, ctx);
        goto after_21;
    // 0x80800224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80800228: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8080022C: jal         0x800EE88C
    // 0x80800230: addiu       $a1, $v0, 0x6
    ctx->r5 = ADD32(ctx->r2, 0X6);
    func_800EE88C(rdram, ctx);
        goto after_22;
    // 0x80800230: addiu       $a1, $v0, 0x6
    ctx->r5 = ADD32(ctx->r2, 0X6);
    after_22:
    // 0x80800234: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800238: jal         0x80102D78
    // 0x8080023C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80102D78(rdram, ctx);
        goto after_23;
    // 0x8080023C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_23:
    // 0x80800240: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80800244: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800248:
    // 0x80800248: addiu       $a1, $zero, 0x5802
    ctx->r5 = ADD32(0, 0X5802);
    // 0x8080024C: jal         0x8008A130
    // 0x80800250: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    _sucoaster_entrypoint_7(rdram, ctx);
        goto after_24;
    // 0x80800250: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    after_24:
    // 0x80800254: b           L_80800288
    // 0x80800258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800288;
    // 0x80800258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080025C:
    // 0x8080025C: jal         0x808003C8
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808003C8_chhillbilly(rdram, ctx);
        goto after_25;
    // 0x80800260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800264: beq         $v0, $zero, L_80800284
    if (ctx->r2 == 0) {
        // 0x80800268: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800284;
    }
    // 0x80800268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080026C: addiu       $a1, $zero, 0x789
    ctx->r5 = ADD32(0, 0X789);
    // 0x80800270: jal         0x808009D8
    // 0x80800274: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_808009D8_chhillbilly(rdram, ctx);
        goto after_26;
    // 0x80800274: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_26:
    // 0x80800278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080027C: jal         0x8008A148
    // 0x80800280: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    _sucoaster_entrypoint_10(rdram, ctx);
        goto after_27;
    // 0x80800280: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    after_27:
L_80800284:
    // 0x80800284: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800288:
    // 0x80800288: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080028C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80800290: jr          $ra
    // 0x80800294: nop

    return;
    // 0x80800294: nop

;}
RECOMP_FUNC void _suspline_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089D98: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089D98);
    return;
    // 0x80089D9C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_808010F4_bsbeemain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808010F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808010F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808010FC: jal         0x800839B8
    // 0x80801100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80801100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801104: jal         0x80082830
    // 0x80801108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbee_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80801108: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8080110C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801114: jr          $ra
    // 0x80801118: nop

    return;
    // 0x80801118: nop

;}
RECOMP_FUNC void _badata_entrypoint_30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084730: syscall     118
    recomp_syscall_handler(rdram, ctx, 0x80084730);
    return;
    // 0x80084734: addi        $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
;}
RECOMP_FUNC void _sudeflect_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089F38: syscall     816
    recomp_syscall_handler(rdram, ctx, 0x80089F38);
    return;
    // 0x80089F3C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_800F759C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F759C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F75A0: lbu         $t6, 0x54D9($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X54D9);
    // 0x800F75A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800F75A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800F75AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800F75B0: beq         $t6, $zero, L_800F75C8
    if (ctx->r14 == 0) {
        // 0x800F75B4: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800F75C8;
    }
    // 0x800F75B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F75B8: jal         0x800F82C0
    // 0x800F75BC: nop

    func_800F82C0(rdram, ctx);
        goto after_0;
    // 0x800F75BC: nop

    after_0:
    // 0x800F75C0: b           L_800F7610
    // 0x800F75C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800F7610;
    // 0x800F75C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F75C8:
    // 0x800F75C8: addiu       $a0, $zero, 0xB5
    ctx->r4 = ADD32(0, 0XB5);
    // 0x800F75CC: jal         0x80101238
    // 0x800F75D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80101238(rdram, ctx);
        goto after_1;
    // 0x800F75D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800F75D4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F75D8: addiu       $t8, $t8, 0x5490
    ctx->r24 = ADD32(ctx->r24, 0X5490);
    // 0x800F75DC: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800F75E0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800F75E4: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800F75E8: jal         0x800F3880
    // 0x800F75EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_800F3880(rdram, ctx);
        goto after_2;
    // 0x800F75EC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x800F75F0: jal         0x800A91F4
    // 0x800F75F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A91F4(rdram, ctx);
        goto after_3;
    // 0x800F75F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800F75F8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800F75FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7600: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x800F7604: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800F7608: sb          $zero, 0x54B0($at)
    MEM_B(0X54B0, ctx->r1) = 0;
    // 0x800F760C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F7610:
    // 0x800F7610: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800F7614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800F7618: jr          $ra
    // 0x800F761C: nop

    return;
    // 0x800F761C: nop

;}
RECOMP_FUNC void cheggnormal_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808003DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808003E4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x808003E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808003EC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808003F0: jal         0x8008A488
    // 0x808003F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    _sueggmove_entrypoint_10(rdram, ctx);
        goto after_0;
    // 0x808003F4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808003F8: addiu       $a0, $zero, 0x15A
    ctx->r4 = ADD32(0, 0X15A);
    // 0x808003FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800400: jal         0x8008A3D0
    // 0x80800404: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    _suegg_entrypoint_11(rdram, ctx);
        goto after_1;
    // 0x80800404: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80800408: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080040C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800410: jal         0x80100094
    // 0x80800414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800414: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800418: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8080041C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800420: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800428: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080042C: jal         0x8008A460
    // 0x80800430: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    _sueggmove_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x80800430: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x80800434: lui         $a2, 0xC7C3
    ctx->r6 = S32(0XC7C3 << 16);
    // 0x80800438: ori         $a2, $a2, 0x5000
    ctx->r6 = ctx->r6 | 0X5000;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800440: jal         0x8008A468
    // 0x80800444: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    _sueggmove_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80800444: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x80800448: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080044C: jal         0x8008A380
    // 0x80800450: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    _suegg_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x80800450: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    after_5:
    // 0x80800454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800458: jal         0x8008A470
    // 0x8080045C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _sueggmove_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x8080045C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80800460: lbu         $t6, 0x72($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X72);
    // 0x80800464: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x80800468: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x8080046C: sb          $t8, 0x72($s0)
    MEM_B(0X72, ctx->r16) = ctx->r24;
    // 0x80800470: jal         0x800F693C
    // 0x80800474: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F693C(rdram, ctx);
        goto after_7;
    // 0x80800474: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80800478: beql        $v0, $zero, L_80800494
    if (ctx->r2 == 0) {
        // 0x8080047C: lbu         $t2, 0x39($s1)
        ctx->r10 = MEM_BU(ctx->r17, 0X39);
            goto L_80800494;
    }
    goto skip_0;
    // 0x8080047C: lbu         $t2, 0x39($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X39);
    skip_0:
    // 0x80800480: lbu         $t0, 0x39($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X39);
    // 0x80800484: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80800488: b           L_8080049C
    // 0x8080048C: sb          $t1, 0x39($s1)
    MEM_B(0X39, ctx->r17) = ctx->r9;
        goto L_8080049C;
    // 0x8080048C: sb          $t1, 0x39($s1)
    MEM_B(0X39, ctx->r17) = ctx->r9;
    // 0x80800490: lbu         $t2, 0x39($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X39);
L_80800494:
    // 0x80800494: andi        $t3, $t2, 0xFFEF
    ctx->r11 = ctx->r10 & 0XFFEF;
    // 0x80800498: sb          $t3, 0x39($s1)
    MEM_B(0X39, ctx->r17) = ctx->r11;
L_8080049C:
    // 0x8080049C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004A0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x808004A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808004A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808004AC: jr          $ra
    // 0x808004B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808004B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808004B4: nop

    // 0x808004B8: nop

    // 0x808004BC: nop

;}
RECOMP_FUNC void func_800A7BB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7BB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A7BBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A7BC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A7BC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A7BC8: jal         0x800A5CF0
    // 0x800A7BCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800A5CF0(rdram, ctx);
        goto after_0;
    // 0x800A7BCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800A7BD0: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A7BD4: addiu       $s0, $s0, 0x7630
    ctx->r16 = ADD32(ctx->r16, 0X7630);
    // 0x800A7BD8: andi        $t0, $zero, 0xFF
    ctx->r8 = 0 & 0XFF;
    // 0x800A7BDC: sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
    // 0x800A7BE0: sh          $t0, 0x10($s0)
    MEM_H(0X10, ctx->r16) = ctx->r8;
    // 0x800A7BE4: sb          $zero, 0x16($s0)
    MEM_B(0X16, ctx->r16) = 0;
    // 0x800A7BE8: sb          $zero, 0x15($s0)
    MEM_B(0X15, ctx->r16) = 0;
    // 0x800A7BEC: sb          $zero, 0x17($s0)
    MEM_B(0X17, ctx->r16) = 0;
    // 0x800A7BF0: sb          $zero, 0x14($s0)
    MEM_B(0X14, ctx->r16) = 0;
    // 0x800A7BF4: sb          $zero, 0x13($s0)
    MEM_B(0X13, ctx->r16) = 0;
    // 0x800A7BF8: sb          $zero, 0x1A($s0)
    MEM_B(0X1A, ctx->r16) = 0;
    // 0x800A7BFC: sb          $zero, 0x1B($s0)
    MEM_B(0X1B, ctx->r16) = 0;
    // 0x800A7C00: jal         0x800A8240
    // 0x800A7C04: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    func_800A8240(rdram, ctx);
        goto after_1;
    // 0x800A7C04: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    after_1:
    // 0x800A7C08: jal         0x800DA238
    // 0x800A7C0C: nop

    func_800DA238(rdram, ctx);
        goto after_2;
    // 0x800A7C0C: nop

    after_2:
    // 0x800A7C10: jal         0x800DA268
    // 0x800A7C14: nop

    func_800DA268(rdram, ctx);
        goto after_3;
    // 0x800A7C14: nop

    after_3:
    // 0x800A7C18: jal         0x800885A8
    // 0x800A7C1C: nop

    _glglobaldata_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x800A7C1C: nop

    after_4:
    // 0x800A7C20: jal         0x800886C8
    // 0x800A7C24: nop

    _glglobalsettings_entrypoint_1(rdram, ctx);
        goto after_5;
    // 0x800A7C24: nop

    after_5:
    // 0x800A7C28: jal         0x80088570
    // 0x800A7C2C: nop

    _glgamedata_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x800A7C2C: nop

    after_6:
    // 0x800A7C30: jal         0x800D3970
    // 0x800A7C34: nop

    func_800D3970(rdram, ctx);
        goto after_7;
    // 0x800A7C34: nop

    after_7:
    // 0x800A7C38: jal         0x800E4278
    // 0x800A7C3C: nop

    func_800E4278(rdram, ctx);
        goto after_8;
    // 0x800A7C3C: nop

    after_8:
    // 0x800A7C40: jal         0x800A861C
    // 0x800A7C44: nop

    func_800A861C(rdram, ctx);
        goto after_9;
    // 0x800A7C44: nop

    after_9:
    // 0x800A7C48: jal         0x800C2A08
    // 0x800A7C4C: nop

    func_800C2A08(rdram, ctx);
        goto after_10;
    // 0x800A7C4C: nop

    after_10:
    // 0x800A7C50: jal         0x800FB808
    // 0x800A7C54: nop

    func_800FB808(rdram, ctx);
        goto after_11;
    // 0x800A7C54: nop

    after_11:
    // 0x800A7C58: jal         0x800887C0
    // 0x800A7C5C: nop

    _glcutDll_entrypoint_3(rdram, ctx);
        goto after_12;
    // 0x800A7C5C: nop

    after_12:
    // 0x800A7C60: jal         0x800CA098
    // 0x800A7C64: nop

    func_800CA098(rdram, ctx);
        goto after_13;
    // 0x800A7C64: nop

    after_13:
    // 0x800A7C68: jal         0x800D34A0
    // 0x800A7C6C: nop

    func_800D34A0(rdram, ctx);
        goto after_14;
    // 0x800A7C6C: nop

    after_14:
    // 0x800A7C70: jal         0x800B5DD4
    // 0x800A7C74: nop

    func_800B5DD4(rdram, ctx);
        goto after_15;
    // 0x800A7C74: nop

    after_15:
    // 0x800A7C78: jal         0x800133A0
    // 0x800A7C7C: nop

    func_800133A0(rdram, ctx);
        goto after_16;
    // 0x800A7C7C: nop

    after_16:
    // 0x800A7C80: jal         0x800DF38C
    // 0x800A7C84: nop

    func_800DF38C(rdram, ctx);
        goto after_17;
    // 0x800A7C84: nop

    after_17:
    // 0x800A7C88: jal         0x8008B610
    // 0x800A7C8C: nop

    func_8008B610(rdram, ctx);
        goto after_18;
    // 0x800A7C8C: nop

    after_18:
    // 0x800A7C90: jal         0x800DC310
    // 0x800A7C94: nop

    func_800DC310(rdram, ctx);
        goto after_19;
    // 0x800A7C94: nop

    after_19:
    // 0x800A7C98: jal         0x8001A290
    // 0x800A7C9C: nop

    func_8001A290(rdram, ctx);
        goto after_20;
    // 0x800A7C9C: nop

    after_20:
    // 0x800A7CA0: jal         0x800D8F84
    // 0x800A7CA4: nop

    func_800D8F84(rdram, ctx);
        goto after_21;
    // 0x800A7CA4: nop

    after_21:
    // 0x800A7CA8: jal         0x80088C78
    // 0x800A7CAC: nop

    _gsattract_entrypoint_4(rdram, ctx);
        goto after_22;
    // 0x800A7CAC: nop

    after_22:
    // 0x800A7CB0: jal         0x800EBB5C
    // 0x800A7CB4: nop

    func_800EBB5C(rdram, ctx);
        goto after_23;
    // 0x800A7CB4: nop

    after_23:
    // 0x800A7CB8: jal         0x80087A40
    // 0x800A7CBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _gcgame_entrypoint_0(rdram, ctx);
        goto after_24;
    // 0x800A7CBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
    // 0x800A7CC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A7CC4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800A7CC8: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x800A7CCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A7CD0: jal         0x800D8FA0
    // 0x800A7CD4: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    func_800D8FA0(rdram, ctx);
        goto after_25;
    // 0x800A7CD4: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_25:
    // 0x800A7CD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A7CDC: jal         0x80088220
    // 0x800A7CE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gclevel_entrypoint_0(rdram, ctx);
        goto after_26;
    // 0x800A7CE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x800A7CE4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A7CE8: jal         0x80088248
    // 0x800A7CEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _gcsectionDll_entrypoint_0(rdram, ctx);
        goto after_27;
    // 0x800A7CEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x800A7CF0: jal         0x800A71E0
    // 0x800A7CF4: nop

    func_800A71E0(rdram, ctx);
        goto after_28;
    // 0x800A7CF4: nop

    after_28:
    // 0x800A7CF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A7CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A7D00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A7D04: jal         0x800A72A4
    // 0x800A7D08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800A72A4(rdram, ctx);
        goto after_29;
    // 0x800A7D08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_29:
    // 0x800A7D0C: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x800A7D10: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800A7D14: jal         0x800A759C
    // 0x800A7D18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800A759C(rdram, ctx);
        goto after_30;
    // 0x800A7D18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x800A7D1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7D20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A7D24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A7D28: jr          $ra
    // 0x800A7D2C: nop

    return;
    // 0x800A7D2C: nop

;}
RECOMP_FUNC void func_80801694_chstatueboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801694: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080169C: jal         0x80100094
    // 0x808016A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808016A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808016A4: lh          $a1, 0x84($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X84);
    // 0x808016A8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1312, 0X25C0) << 16);
    // 0x808016AC: addiu       $t7, $t7, 0x25C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1312, 0X25C0));
    // 0x808016B0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x808016B4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x808016B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x808016BC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x808016C0: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x808016C4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x808016C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808016CC: beq         $t0, $t9, L_80801718
    if (ctx->r8 == ctx->r25) {
        // 0x808016D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801718;
    }
    // 0x808016D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808016D4: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x808016D8: subu        $t1, $t1, $a1
    ctx->r9 = SUB32(ctx->r9, ctx->r5);
    // 0x808016DC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x808016E0: addu        $v1, $t1, $t7
    ctx->r3 = ADD32(ctx->r9, ctx->r15);
    // 0x808016E4: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x808016E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808016EC: addu        $t2, $v0, $a0
    ctx->r10 = ADD32(ctx->r2, ctx->r4);
L_808016F0:
    // 0x808016F0: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x808016F4: addiu       $t4, $a0, 0x1F
    ctx->r12 = ADD32(ctx->r4, 0X1F);
    // 0x808016F8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x808016FC: bne         $a3, $t3, L_80801708
    if (ctx->r7 != ctx->r11) {
        // 0x80801700: sllv        $t6, $t5, $t4
        ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
            goto L_80801708;
    }
    // 0x80801700: sllv        $t6, $t5, $t4
    ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x80801704: or          $a2, $a2, $t6
    ctx->r6 = ctx->r6 | ctx->r14;
L_80801708:
    // 0x80801708: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x8080170C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80801710: bnel        $t0, $a0, L_808016F0
    if (ctx->r8 != ctx->r4) {
        // 0x80801714: addu        $t2, $v0, $a0
        ctx->r10 = ADD32(ctx->r2, ctx->r4);
            goto L_808016F0;
    }
    goto skip_0;
    // 0x80801714: addu        $t2, $v0, $a0
    ctx->r10 = ADD32(ctx->r2, ctx->r4);
    skip_0:
L_80801718:
    // 0x80801718: xor         $v0, $t0, $a2
    ctx->r2 = ctx->r8 ^ ctx->r6;
    // 0x8080171C: jr          $ra
    // 0x80801720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80801720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80800330_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800330: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800334: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800338: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080033C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800340: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800344: jal         0x80100094
    // 0x80800348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800348: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080034C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800350: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800354: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800358: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8080035C: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80800360: beq         $at, $zero, L_80800404
    if (ctx->r1 == 0) {
        // 0x80800364: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800404;
    }
    // 0x80800364: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800368: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2220, 0XCA4) << 16);
    // 0x8080036C: addu        $at, $at, $t8
    gpr jr_addend_80800374 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800370: lw          $t8, 0xCA4($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2220, 0XCA4));
    // 0x80800374: jr          $t8
    // 0x80800378: nop

    switch (jr_addend_80800374 >> 2) {
        case 0: goto L_8080037C; break;
        case 1: goto L_8080039C; break;
        case 2: goto L_808003BC; break;
        case 3: goto L_808003D0; break;
        case 4: goto L_808003E4; break;
        case 5: goto L_808003F8; break;
        default: switch_error(__func__, 0x80800374, 0x80800CA4);
    }
    // 0x80800378: nop

L_8080037C:
    // 0x8080037C: jal         0x8008A3B8
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80800380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800384: bne         $v0, $zero, L_80800404
    if (ctx->r2 != 0) {
        // 0x80800388: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800404;
    }
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080038C: jal         0x8080048C
    // 0x80800390: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8080048C_cheggproximity(rdram, ctx);
        goto after_2;
    // 0x80800390: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80800394: b           L_80800408
    // 0x80800398: lb          $t0, 0x39($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X39);
        goto L_80800408;
    // 0x80800398: lb          $t0, 0x39($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X39);
L_8080039C:
    // 0x8080039C: jal         0x8008A3B8
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_8(rdram, ctx);
        goto after_3;
    // 0x808003A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808003A4: bne         $v0, $zero, L_80800404
    if (ctx->r2 != 0) {
        // 0x808003A8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800404;
    }
    // 0x808003A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003AC: jal         0x80800510
    // 0x808003B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800510_cheggproximity(rdram, ctx);
        goto after_4;
    // 0x808003B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x808003B4: b           L_80800408
    // 0x808003B8: lb          $t0, 0x39($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X39);
        goto L_80800408;
    // 0x808003B8: lb          $t0, 0x39($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X39);
L_808003BC:
    // 0x808003BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003C0: jal         0x80800588
    // 0x808003C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800588_cheggproximity(rdram, ctx);
        goto after_5;
    // 0x808003C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x808003C8: b           L_80800408
    // 0x808003CC: lb          $t0, 0x39($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X39);
        goto L_80800408;
    // 0x808003CC: lb          $t0, 0x39($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X39);
L_808003D0:
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D4: jal         0x808005EC
    // 0x808003D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808005EC_cheggproximity(rdram, ctx);
        goto after_6;
    // 0x808003D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x808003DC: b           L_80800408
    // 0x808003E0: lb          $t0, 0x39($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X39);
        goto L_80800408;
    // 0x808003E0: lb          $t0, 0x39($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X39);
L_808003E4:
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: jal         0x80800650
    // 0x808003EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80800650_cheggproximity(rdram, ctx);
        goto after_7;
    // 0x808003EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x808003F0: b           L_80800408
    // 0x808003F4: lb          $t0, 0x39($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X39);
        goto L_80800408;
    // 0x808003F4: lb          $t0, 0x39($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X39);
L_808003F8:
    // 0x808003F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003FC: jal         0x808006A4
    // 0x80800400: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_808006A4_cheggproximity(rdram, ctx);
        goto after_8;
    // 0x80800400: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
L_80800404:
    // 0x80800404: lb          $t0, 0x39($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X39);
L_80800408:
    // 0x80800408: bgezl       $t0, L_8080047C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8080040C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080047C;
    }
    goto skip_0;
    // 0x8080040C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800410: lw          $t1, 0x38($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X38);
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: sll         $t3, $t1, 9
    ctx->r11 = S32(ctx->r9 << 9);
    // 0x8080041C: bltzl       $t3, L_8080047C
    if (SIGNED(ctx->r11) < 0) {
        // 0x80800420: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8080047C;
    }
    goto skip_1;
    // 0x80800420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80800424: jal         0x80100094
    // 0x80800428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8080042C: lw          $t4, 0xA8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XA8);
    // 0x80800430: addiu       $a0, $zero, 0x2C4
    ctx->r4 = ADD32(0, 0X2C4);
    // 0x80800434: addiu       $a1, $zero, 0x74
    ctx->r5 = ADD32(0, 0X74);
    // 0x80800438: beql        $t4, $zero, L_8080044C
    if (ctx->r12 == 0) {
        // 0x8080043C: lhu         $t5, 0x72($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X72);
            goto L_8080044C;
    }
    goto skip_2;
    // 0x8080043C: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
    skip_2:
    // 0x80800440: jal         0x80101180
    // 0x80800444: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    func_80101180(rdram, ctx);
        goto after_10;
    // 0x80800444: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x80800448: lhu         $t5, 0x72($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X72);
L_8080044C:
    // 0x8080044C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80800450: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80800454: srl         $t6, $t5, 10
    ctx->r14 = S32(U32(ctx->r13) >> 10);
    // 0x80800458: bne         $t6, $at, L_80800470
    if (ctx->r14 != ctx->r1) {
        // 0x8080045C: addiu       $a0, $a0, 0x73E0
        ctx->r4 = ADD32(ctx->r4, 0X73E0);
            goto L_80800470;
    }
    // 0x8080045C: addiu       $a0, $a0, 0x73E0
    ctx->r4 = ADD32(ctx->r4, 0X73E0);
    // 0x80800460: jal         0x80086D30
    // 0x80800464: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    _chbaddiesetup_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800464: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_11:
    // 0x80800468: b           L_8080047C
    // 0x8080046C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080047C;
    // 0x8080046C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800470:
    // 0x80800470: jal         0x800FFAB0
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_12;
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800478: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080047C:
    // 0x8080047C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800480: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800484: jr          $ra
    // 0x80800488: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80800488: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800030_chsabreman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800030: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080003C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800040: jal         0x80100094
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800048: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x8080004C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800050: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80800054: jal         0x80102FDC
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_1;
    // 0x80800058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8080005C: lui         $a1, 0x1000
    ctx->r5 = S32(0X1000 << 16);
    // 0x80800060: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x80800064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800068: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080006C: jal         0x801088A8
    // 0x80800070: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_801088A8(rdram, ctx);
        goto after_2;
    // 0x80800070: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80800074: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80800078: jal         0x8008A020
    // 0x8080007C: addiu       $a0, $a0, 0x810
    ctx->r4 = ADD32(ctx->r4, 0X810);
    _subaddielink_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x8080007C: addiu       $a0, $a0, 0x810
    ctx->r4 = ADD32(ctx->r4, 0X810);
    after_3:
    // 0x80800080: jal         0x80088848
    // 0x80800084: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_4;
    // 0x80800084: nop

    after_4:
    // 0x80800088: beq         $v0, $zero, L_808000CC
    if (ctx->r2 == 0) {
        // 0x8080008C: addiu       $a0, $zero, 0x1CA
        ctx->r4 = ADD32(0, 0X1CA);
            goto L_808000CC;
    }
    // 0x8080008C: addiu       $a0, $zero, 0x1CA
    ctx->r4 = ADD32(0, 0X1CA);
    // 0x80800090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800094: jal         0x80100094
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_5;
    // 0x80800098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8080009C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808000A4: jal         0x8008A060
    // 0x808000A8: addiu       $a2, $zero, 0x7F1
    ctx->r6 = ADD32(0, 0X7F1);
    _subaddiepalette_entrypoint_0(rdram, ctx);
        goto after_6;
    // 0x808000A8: addiu       $a2, $zero, 0x7F1
    ctx->r6 = ADD32(0, 0X7F1);
    after_6:
    // 0x808000AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000B0: jal         0x80102424
    // 0x808000B4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_80102424(rdram, ctx);
        goto after_7;
    // 0x808000B4: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_7:
    // 0x808000B8: jal         0x8080112C
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080112C_chsabreman(rdram, ctx);
        goto after_8;
    // 0x808000BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808000C0: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x808000C4: b           L_80800204
    // 0x808000C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800204;
    // 0x808000C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000CC:
    // 0x808000CC: jal         0x800DA564
    // 0x808000D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800DA564(rdram, ctx);
        goto after_9;
    // 0x808000D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x808000D4: beq         $v0, $zero, L_80800108
    if (ctx->r2 == 0) {
        // 0x808000D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800108;
    }
    // 0x808000D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000E0: beq         $v0, $at, L_8080015C
    if (ctx->r2 == ctx->r1) {
        // 0x808000E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080015C;
    }
    // 0x808000E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000EC: beq         $v0, $at, L_808001B4
    if (ctx->r2 == ctx->r1) {
        // 0x808000F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001B4;
    }
    // 0x808000F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808000F4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808000F8: beq         $v0, $at, L_808001F0
    if (ctx->r2 == ctx->r1) {
        // 0x808000FC: nop
    
            goto L_808001F0;
    }
    // 0x808000FC: nop

    // 0x80800100: b           L_80800204
    // 0x80800104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800204;
    // 0x80800104: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800108:
    // 0x80800108: jal         0x8010A85C
    // 0x8080010C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010A85C(rdram, ctx);
        goto after_10;
    // 0x8080010C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800114: jal         0x80100094
    // 0x80800118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x80800118: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x8080011C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800120: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80800124: jal         0x8008A060
    // 0x80800128: addiu       $a2, $zero, 0x7F0
    ctx->r6 = ADD32(0, 0X7F0);
    _subaddiepalette_entrypoint_0(rdram, ctx);
        goto after_12;
    // 0x80800128: addiu       $a2, $zero, 0x7F0
    ctx->r6 = ADD32(0, 0X7F0);
    after_12:
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800130: jal         0x80108B04
    // 0x80800134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_13;
    // 0x80800134: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80800138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080013C: jal         0x808011F8
    // 0x80800140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_14;
    // 0x80800140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80800144: jal         0x8010A570
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_15;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080014C: lbu         $t6, 0x75($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X75);
    // 0x80800150: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x80800154: b           L_80800200
    // 0x80800158: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
        goto L_80800200;
    // 0x80800158: sb          $t7, 0x75($s0)
    MEM_B(0X75, ctx->r16) = ctx->r15;
L_8080015C:
    // 0x8080015C: jal         0x80100094
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_16;
    // 0x80800160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80800164: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800168: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080016C: jal         0x8008A060
    // 0x80800170: addiu       $a2, $zero, 0x7F0
    ctx->r6 = ADD32(0, 0X7F0);
    _subaddiepalette_entrypoint_0(rdram, ctx);
        goto after_17;
    // 0x80800170: addiu       $a2, $zero, 0x7F0
    ctx->r6 = ADD32(0, 0X7F0);
    after_17:
    // 0x80800174: jal         0x800CB3E0
    // 0x80800178: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    func_800CB3E0(rdram, ctx);
        goto after_18;
    // 0x80800178: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_18:
    // 0x8080017C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800180: bne         $v0, $at, L_80800190
    if (ctx->r2 != ctx->r1) {
        // 0x80800184: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800190;
    }
    // 0x80800184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800188: jal         0x80108B04
    // 0x8080018C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80108B04(rdram, ctx);
        goto after_19;
    // 0x8080018C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
L_80800190:
    // 0x80800190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800194: jal         0x808011F8
    // 0x80800198: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_20;
    // 0x80800198: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_20:
    // 0x8080019C: jal         0x8010A590
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_21;
    // 0x808001A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808001A4: jal         0x8080112C
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080112C_chsabreman(rdram, ctx);
        goto after_22;
    // 0x808001A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808001AC: b           L_80800200
    // 0x808001B0: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
        goto L_80800200;
    // 0x808001B0: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_808001B4:
    // 0x808001B4: jal         0x80100094
    // 0x808001B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_23;
    // 0x808001B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
    // 0x808001BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808001C4: jal         0x8008A060
    // 0x808001C8: addiu       $a2, $zero, 0x7F1
    ctx->r6 = ADD32(0, 0X7F1);
    _subaddiepalette_entrypoint_0(rdram, ctx);
        goto after_24;
    // 0x808001C8: addiu       $a2, $zero, 0x7F1
    ctx->r6 = ADD32(0, 0X7F1);
    after_24:
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x808011F8
    // 0x808001D4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808011F8_chsabreman(rdram, ctx);
        goto after_25;
    // 0x808001D4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_25:
    // 0x808001D8: jal         0x8010A590
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_26;
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x808001E0: jal         0x8080112C
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080112C_chsabreman(rdram, ctx);
        goto after_27;
    // 0x808001E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x808001E8: b           L_80800200
    // 0x808001EC: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
        goto L_80800200;
    // 0x808001EC: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_808001F0:
    // 0x808001F0: jal         0x800FFAB0
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_28;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x808001F8: b           L_80800204
    // 0x808001FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800204;
    // 0x808001FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800200:
    // 0x80800200: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800204:
    // 0x80800204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800208: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080020C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800210: jr          $ra
    // 0x80800214: nop

    return;
    // 0x80800214: nop

;}
RECOMP_FUNC void _bsblongleg_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082A50: syscall     24
    recomp_syscall_handler(rdram, ctx, 0x80082A50);
    return;
    // 0x80082A54: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void func_800A8E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8E9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A8EA0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A8EA4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A8EA8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A8EAC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A8EB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A8EB4: addiu       $s1, $s1, 0x76F0
    ctx->r17 = ADD32(ctx->r17, 0X76F0);
    // 0x800A8EB8: addiu       $s0, $s0, 0x76D0
    ctx->r16 = ADD32(ctx->r16, 0X76D0);
    // 0x800A8EBC: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
L_800A8EC0:
    // 0x800A8EC0: beql        $a0, $zero, L_800A8ED4
    if (ctx->r4 == 0) {
        // 0x800A8EC4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A8ED4;
    }
    goto skip_0;
    // 0x800A8EC4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x800A8EC8: jal         0x8010FC38
    // 0x800A8ECC: nop

    func_8010FC38(rdram, ctx);
        goto after_0;
    // 0x800A8ECC: nop

    after_0:
    // 0x800A8ED0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800A8ED4:
    // 0x800A8ED4: bnel        $s0, $s1, L_800A8EC0
    if (ctx->r16 != ctx->r17) {
        // 0x800A8ED8: lw          $a0, 0x58($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X58);
            goto L_800A8EC0;
    }
    goto skip_1;
    // 0x800A8ED8: lw          $a0, 0x58($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X58);
    skip_1:
    // 0x800A8EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A8EE0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A8EE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A8EE8: jr          $ra
    // 0x800A8EEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A8EEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80804784_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80804788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080478C: jal         0x80100094
    // 0x80804790: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80804790: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80804794: sb          $zero, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = 0;
    // 0x80804798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080479C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808047A0: jr          $ra
    // 0x808047A4: nop

    return;
    // 0x808047A4: nop

;}
RECOMP_FUNC void func_800C53EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C53EC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C53F0: addiu       $t7, $t7, -0x5660
    ctx->r15 = ADD32(ctx->r15, -0X5660);
    // 0x800C53F4: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800C53F8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C53FC: lbu         $v1, 0xC($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XC);
    // 0x800C5400: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C5404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C5408: beq         $v1, $zero, L_800C541C
    if (ctx->r3 == 0) {
        // 0x800C540C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800C541C;
    }
    // 0x800C540C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C5410: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C5414: bne         $v1, $at, L_800C5424
    if (ctx->r3 != ctx->r1) {
        // 0x800C5418: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_800C5424;
    }
    // 0x800C5418: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
L_800C541C:
    // 0x800C541C: b           L_800C5454
    // 0x800C5420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C5454;
    // 0x800C5420: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C5424:
    // 0x800C5424: sb          $t8, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r24;
    // 0x800C5428: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800C542C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C5430: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C5434: jal         0x800C524C
    // 0x800C5438: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_800C524C(rdram, ctx);
        goto after_0;
    // 0x800C5438: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x800C543C: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x800C5440: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800C5444: bnel        $t0, $zero, L_800C5454
    if (ctx->r8 != 0) {
        // 0x800C5448: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C5454;
    }
    goto skip_0;
    // 0x800C5448: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800C544C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C5450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C5454:
    // 0x800C5454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C5458: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C545C: jr          $ra
    // 0x800C5460: nop

    return;
    // 0x800C5460: nop

;}
RECOMP_FUNC void func_80801060_bsstatue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801068: jal         0x8080147C
    // 0x8080106C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080147C_bsstatue(rdram, ctx);
        goto after_0;
    // 0x8080106C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801070: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x80801074: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80801078: jal         0x8008CB10
    // 0x8080107C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x8080107C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80801080: beql        $v0, $zero, L_80801094
    if (ctx->r2 == 0) {
        // 0x80801084: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801094;
    }
    goto skip_0;
    // 0x80801084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80801088: jal         0x80800D84
    // 0x8080108C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800D84_bsstatue(rdram, ctx);
        goto after_2;
    // 0x8080108C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80801090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801094:
    // 0x80801094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801098: jr          $ra
    // 0x8080109C: nop

    return;
    // 0x8080109C: nop

;}
RECOMP_FUNC void func_808000F4_cadbmgrDll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808000F8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(664, 0X630) << 16);
    // 0x808000FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800100: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800104: addiu       $t7, $t7, 0x630
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(664, 0X630));
    // 0x80800108: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8080010C: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80800110: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80800114: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80800118: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8080011C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80800120: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80800124: jal         0x800A5854
    // 0x80800128: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800A5854(rdram, ctx);
        goto after_0;
    // 0x80800128: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x8080012C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800130: jal         0x800A5800
    // 0x80800134: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_800A5800(rdram, ctx);
        goto after_1;
    // 0x80800134: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80800138: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8080013C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800140: beq         $v1, $at, L_80800160
    if (ctx->r3 == ctx->r1) {
        // 0x80800144: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800160;
    }
    // 0x80800144: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800148: beq         $v1, $at, L_80800160
    if (ctx->r3 == ctx->r1) {
        // 0x8080014C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800160;
    }
    // 0x8080014C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800150: beq         $v1, $at, L_80800160
    if (ctx->r3 == ctx->r1) {
        // 0x80800154: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80800160;
    }
    // 0x80800154: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800158: bne         $v1, $at, L_80800188
    if (ctx->r3 != ctx->r1) {
        // 0x8080015C: nop
    
            goto L_80800188;
    }
    // 0x8080015C: nop

L_80800160:
    // 0x80800160: jal         0x800E3980
    // 0x80800164: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800E3980(rdram, ctx);
        goto after_2;
    // 0x80800164: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80800168: jal         0x80085588
    // 0x8080016C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    _cadbfunc_entrypoint_1(rdram, ctx);
        goto after_3;
    // 0x8080016C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80800170: jal         0x800E3A58
    // 0x80800174: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_800E3A58(rdram, ctx);
        goto after_4;
    // 0x80800174: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80800178: jal         0x80085598
    // 0x8080017C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    _cadbfunc_entrypoint_3(rdram, ctx);
        goto after_5;
    // 0x8080017C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80800180: b           L_80800198
    // 0x80800184: nop

        goto L_80800198;
    // 0x80800184: nop

L_80800188:
    // 0x80800188: jal         0x80085588
    // 0x8080018C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    _cadbfunc_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x8080018C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_6:
    // 0x80800190: jal         0x80085598
    // 0x80800194: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    _cadbfunc_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80800194: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_7:
L_80800198:
    // 0x80800198: jal         0x800855A8
    // 0x8080019C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    _cadbfunc_entrypoint_5(rdram, ctx);
        goto after_8;
    // 0x8080019C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_8:
    // 0x808001A0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x808001A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001A8: lui         $at, 0x4070
    ctx->r1 = S32(0X4070 << 16);
    // 0x808001AC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001B0: jal         0x800855B8
    // 0x808001B4: nop

    _cadbfunc_entrypoint_7(rdram, ctx);
        goto after_9;
    // 0x808001B4: nop

    after_9:
    // 0x808001B8: lui         $at, 0x4030
    ctx->r1 = S32(0X4030 << 16);
    // 0x808001BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001C0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x808001C4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x808001C8: jal         0x800855C8
    // 0x808001CC: nop

    _cadbfunc_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x808001CC: nop

    after_10:
    // 0x808001D0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808001D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001D8: jal         0x800855D8
    // 0x808001DC: nop

    _cadbfunc_entrypoint_11(rdram, ctx);
        goto after_11;
    // 0x808001DC: nop

    after_11:
    // 0x808001E0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x808001E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001E8: jal         0x800855E8
    // 0x808001EC: nop

    _cadbfunc_entrypoint_13(rdram, ctx);
        goto after_12;
    // 0x808001EC: nop

    after_12:
    // 0x808001F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808001F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808001F8: jal         0x800855F8
    // 0x808001FC: nop

    _cadbfunc_entrypoint_15(rdram, ctx);
        goto after_13;
    // 0x808001FC: nop

    after_13:
    // 0x80800200: jal         0x80085608
    // 0x80800204: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    _cadbfunc_entrypoint_17(rdram, ctx);
        goto after_14;
    // 0x80800204: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_14:
    // 0x80800208: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8080020C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800210: jal         0x80085618
    // 0x80800214: nop

    _cadbfunc_entrypoint_19(rdram, ctx);
        goto after_15;
    // 0x80800214: nop

    after_15:
    // 0x80800218: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8080021C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800220: jal         0x80085628
    // 0x80800224: nop

    _cadbfunc_entrypoint_21(rdram, ctx);
        goto after_16;
    // 0x80800224: nop

    after_16:
    // 0x80800228: jal         0x80085648
    // 0x8080022C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _cadbfunc_entrypoint_25(rdram, ctx);
        goto after_17;
    // 0x8080022C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x80800230: jal         0x80085658
    // 0x80800234: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _cadbfunc_entrypoint_27(rdram, ctx);
        goto after_18;
    // 0x80800234: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
    // 0x80800238: jal         0x80085638
    // 0x8080023C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _cadbfunc_entrypoint_23(rdram, ctx);
        goto after_19;
    // 0x8080023C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x80800240: jal         0x80085678
    // 0x80800244: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _cadbfunc_entrypoint_31(rdram, ctx);
        goto after_20;
    // 0x80800244: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_20:
    // 0x80800248: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8080024C: jal         0x80085688
    // 0x80800250: nop

    _cadbfunc_entrypoint_33(rdram, ctx);
        goto after_21;
    // 0x80800250: nop

    after_21:
    // 0x80800254: jal         0x80085698
    // 0x80800258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _cadbfunc_entrypoint_35(rdram, ctx);
        goto after_22;
    // 0x80800258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x8080025C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80800260: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800264: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80800268: beq         $v1, $at, L_808002A0
    if (ctx->r3 == ctx->r1) {
        // 0x8080026C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808002A0;
    }
    // 0x8080026C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800270: beq         $v1, $at, L_80800288
    if (ctx->r3 == ctx->r1) {
        // 0x80800274: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80800288;
    }
    // 0x80800274: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80800278: beq         $v1, $at, L_808002B0
    if (ctx->r3 == ctx->r1) {
        // 0x8080027C: nop
    
            goto L_808002B0;
    }
    // 0x8080027C: nop

    // 0x80800280: b           L_808002BC
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002BC;
    // 0x80800284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800288:
    // 0x80800288: jal         0x80085658
    // 0x8080028C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _cadbfunc_entrypoint_27(rdram, ctx);
        goto after_23;
    // 0x8080028C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x80800290: jal         0x80085638
    // 0x80800294: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    _cadbfunc_entrypoint_23(rdram, ctx);
        goto after_24;
    // 0x80800294: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_24:
    // 0x80800298: b           L_808002BC
    // 0x8080029C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002BC;
    // 0x8080029C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002A0:
    // 0x808002A0: jal         0x80085660
    // 0x808002A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _cadbfunc_entrypoint_28(rdram, ctx);
        goto after_25;
    // 0x808002A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x808002A8: b           L_808002BC
    // 0x808002AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808002BC;
    // 0x808002AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002B0:
    // 0x808002B0: jal         0x80085648
    // 0x808002B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    _cadbfunc_entrypoint_25(rdram, ctx);
        goto after_26;
    // 0x808002B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_26:
    // 0x808002B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808002BC:
    // 0x808002BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808002C0: jr          $ra
    // 0x808002C4: nop

    return;
    // 0x808002C4: nop

;}
RECOMP_FUNC void func_8080028C_chflysaucercrate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080028C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800290: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800294: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800298: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x8080029C: ori         $t6, $a2, 0x4
    ctx->r14 = ctx->r6 | 0X4;
    // 0x808002A0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x808002A4: addiu       $t8, $zero, 0x41
    ctx->r24 = ADD32(0, 0X41);
    // 0x808002A8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x808002AC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808002B0: jal         0x8008A208
    // 0x808002B4: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_0;
    // 0x808002B4: addiu       $a3, $t7, 0x4
    ctx->r7 = ADD32(ctx->r15, 0X4);
    after_0:
    // 0x808002B8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x808002BC: lbu         $t0, 0x74($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X74);
    // 0x808002C0: ori         $t1, $t0, 0x40
    ctx->r9 = ctx->r8 | 0X40;
    // 0x808002C4: sb          $t1, 0x74($v0)
    MEM_B(0X74, ctx->r2) = ctx->r9;
    // 0x808002C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002D0: jr          $ra
    // 0x808002D4: nop

    return;
    // 0x808002D4: nop

;}
RECOMP_FUNC void sukickball_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800F40: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800F44: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X1234) << 16);
    // 0x80800F48: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800F4C: jr          $ra
    // 0x80800F50: lwc1        $f0, 0x1234($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X1234));
    return;
    // 0x80800F50: lwc1        $f0, 0x1234($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X1234));
;}
RECOMP_FUNC void func_80800DAC_bstrexlarge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800DB8: jal         0x80800BC4
    // 0x80800DBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800BC4_bstrexlarge(rdram, ctx);
        goto after_0;
    // 0x80800DBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800DC0: jal         0x8080064C
    // 0x80800DC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bstrexlarge_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800DC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DD0: jr          $ra
    // 0x80800DD4: nop

    return;
    // 0x80800DD4: nop

;}
RECOMP_FUNC void _idflame_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088E20: syscall     743
    recomp_syscall_handler(rdram, ctx, 0x80088E20);
    return;
    // 0x80088E24: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _chballoonburst_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085ED8: syscall     257
    recomp_syscall_handler(rdram, ctx, 0x80085ED8);
    return;
    // 0x80085EDC: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_800B8FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8FEC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800B8FF0: lw          $v0, 0x7128($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7128);
    // 0x800B8FF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B8FF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B8FFC: beql        $v0, $zero, L_800B902C
    if (ctx->r2 == 0) {
        // 0x800B9000: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B902C;
    }
    goto skip_0;
    // 0x800B9000: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B9004: jal         0x8001B084
    // 0x800B9008: lw          $a0, 0x1C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1C);
    heap_free(rdram, ctx);
        goto after_0;
    // 0x800B9008: lw          $a0, 0x1C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1C);
    after_0:
    // 0x800B900C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B9010: jal         0x8001B084
    // 0x800B9014: lw          $a0, 0x7128($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7128);
    heap_free(rdram, ctx);
        goto after_1;
    // 0x800B9014: lw          $a0, 0x7128($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7128);
    after_1:
    // 0x800B9018: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800B901C: addiu       $v0, $v0, 0x7128
    ctx->r2 = ADD32(ctx->r2, 0X7128);
    // 0x800B9020: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B9024: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800B9028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B902C:
    // 0x800B902C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B9030: jr          $ra
    // 0x800B9034: nop

    return;
    // 0x800B9034: nop

;}
RECOMP_FUNC void func_80800228_gczoombox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800228: lw          $v0, 0x1E4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E4);
    // 0x8080022C: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80800230: sll         $t6, $v0, 12
    ctx->r14 = S32(ctx->r2 << 12);
    // 0x80800234: srl         $v0, $t6, 31
    ctx->r2 = S32(U32(ctx->r14) >> 31);
    // 0x80800238: beq         $v0, $zero, L_80800248
    if (ctx->r2 == 0) {
        // 0x8080023C: nop
    
            goto L_80800248;
    }
    // 0x8080023C: nop

    // 0x80800240: b           L_80800248
    // 0x80800244: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
        goto L_80800248;
    // 0x80800244: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
L_80800248:
    // 0x80800248: lh          $t8, 0x1B0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X1B0);
    // 0x8080024C: bgez        $v1, L_8080025C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80800250: sra         $t9, $v1, 1
        ctx->r25 = S32(SIGNED(ctx->r3) >> 1);
            goto L_8080025C;
    }
    // 0x80800250: sra         $t9, $v1, 1
    ctx->r25 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80800254: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x80800258: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8080025C:
    // 0x8080025C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80800260: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80800264: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x80800268: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8080026C: beq         $v0, $zero, L_8080027C
    if (ctx->r2 == 0) {
        // 0x80800270: swc1        $f6, 0x1A4($a0)
        MEM_W(0X1A4, ctx->r4) = ctx->f6.u32l;
            goto L_8080027C;
    }
    // 0x80800270: swc1        $f6, 0x1A4($a0)
    MEM_W(0X1A4, ctx->r4) = ctx->f6.u32l;
    // 0x80800274: b           L_8080027C
    // 0x80800278: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
        goto L_8080027C;
    // 0x80800278: addiu       $v1, $zero, 0xF
    ctx->r3 = ADD32(0, 0XF);
L_8080027C:
    // 0x8080027C: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x80800280: lwc1        $f16, 0x1A4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X1A4);
    // 0x80800284: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800288: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8080028C: jr          $ra
    // 0x80800290: swc1        $f18, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x80800290: swc1        $f18, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_80800394_chdrips(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800394: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80800398: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8080039C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x808003A0: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x808003A4: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x808003A8: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x808003AC: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x808003B0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x808003B4: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x808003B8: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x808003BC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x808003C0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x808003C4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x808003C8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x808003CC: lw          $t6, 0x70($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X70);
    // 0x808003D0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x808003D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808003D8: srl         $t7, $t6, 25
    ctx->r15 = S32(U32(ctx->r14) >> 25);
    // 0x808003DC: bnel        $t7, $zero, L_808003F8
    if (ctx->r15 != 0) {
        // 0x808003E0: lhu         $v0, 0x76($s3)
        ctx->r2 = MEM_HU(ctx->r19, 0X76);
            goto L_808003F8;
    }
    goto skip_0;
    // 0x808003E0: lhu         $v0, 0x76($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X76);
    skip_0:
    // 0x808003E4: jal         0x800FFA88
    // 0x808003E8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_800FFA88(rdram, ctx);
        goto after_0;
    // 0x808003E8: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x808003EC: b           L_80800594
    // 0x808003F0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_80800594;
    // 0x808003F0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x808003F4: lhu         $v0, 0x76($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X76);
L_808003F8:
    // 0x808003F8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x808003FC: srl         $v1, $v0, 7
    ctx->r3 = S32(U32(ctx->r2) >> 7);
    // 0x80800400: slti        $at, $v1, 0x33
    ctx->r1 = SIGNED(ctx->r3) < 0X33 ? 1 : 0;
    // 0x80800404: beq         $at, $zero, L_8080041C
    if (ctx->r1 == 0) {
        // 0x80800408: andi        $t8, $v0, 0x7F
        ctx->r24 = ctx->r2 & 0X7F;
            goto L_8080041C;
    }
    // 0x80800408: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x8080040C: ori         $t9, $t8, 0x1E00
    ctx->r25 = ctx->r24 | 0X1E00;
    // 0x80800410: andi        $v0, $t9, 0xFFFF
    ctx->r2 = ctx->r25 & 0XFFFF;
    // 0x80800414: srl         $v1, $v0, 7
    ctx->r3 = S32(U32(ctx->r2) >> 7);
    // 0x80800418: sh          $t9, 0x76($s3)
    MEM_H(0X76, ctx->r19) = ctx->r25;
L_8080041C:
    // 0x8080041C: addiu       $t1, $v1, -0x32
    ctx->r9 = ADD32(ctx->r3, -0X32);
    // 0x80800420: sll         $t3, $t1, 7
    ctx->r11 = S32(ctx->r9 << 7);
    // 0x80800424: andi        $t4, $v0, 0x7F
    ctx->r12 = ctx->r2 & 0X7F;
    // 0x80800428: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8080042C: andi        $a2, $t5, 0xFFFF
    ctx->r6 = ctx->r13 & 0XFFFF;
    // 0x80800430: srl         $t6, $a2, 7
    ctx->r14 = S32(U32(ctx->r6) >> 7);
    // 0x80800434: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80800438: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8080043C: sh          $t5, 0x76($s3)
    MEM_H(0X76, ctx->r19) = ctx->r13;
    // 0x80800440: jal         0x80100074
    // 0x80800444: sll         $a2, $t7, 2
    ctx->r6 = S32(ctx->r15 << 2);
    func_80100074(rdram, ctx);
        goto after_1;
    // 0x80800444: sll         $a2, $t7, 2
    ctx->r6 = S32(ctx->r15 << 2);
    after_1:
    // 0x80800448: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080044C: jal         0x80100094
    // 0x80800450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x80800450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800454: lw          $a0, 0x70($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X70);
    // 0x80800458: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080045C: srl         $t8, $a0, 25
    ctx->r24 = S32(U32(ctx->r4) >> 25);
    // 0x80800460: jal         0x800CC5F4
    // 0x80800464: addiu       $a0, $t8, -0x1
    ctx->r4 = ADD32(ctx->r24, -0X1);
    func_800CC5F4(rdram, ctx);
        goto after_3;
    // 0x80800464: addiu       $a0, $t8, -0x1
    ctx->r4 = ADD32(ctx->r24, -0X1);
    after_3:
    // 0x80800468: lhu         $t9, 0x76($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X76);
    // 0x8080046C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80800470: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80800474: srl         $t0, $t9, 7
    ctx->r8 = S32(U32(ctx->r25) >> 7);
    // 0x80800478: blez        $t0, L_80800590
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8080047C: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_80800590;
    }
    // 0x8080047C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80800480: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80800484: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1816, 0X608) << 16);
    // 0x80800488: lwc1        $f26, 0x608($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1816, 0X608));
    // 0x8080048C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1816, 0X60C) << 16);
    // 0x80800490: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800494: lwc1        $f24, 0x60C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1816, 0X60C));
    // 0x80800498: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8080049C: addiu       $s4, $sp, 0x78
    ctx->r20 = ADD32(ctx->r29, 0X78);
    // 0x808004A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_808004A4:
    // 0x808004A4: jal         0x800DC128
    // 0x808004A8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    func_800DC128(rdram, ctx);
        goto after_4;
    // 0x808004A8: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_4:
    // 0x808004AC: lw          $a0, 0x70($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X70);
    // 0x808004B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808004B4: srl         $t1, $a0, 25
    ctx->r9 = S32(U32(ctx->r4) >> 25);
    // 0x808004B8: jal         0x800CC63C
    // 0x808004BC: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
    func_800CC63C(rdram, ctx);
        goto after_5;
    // 0x808004BC: addiu       $a0, $t1, -0x1
    ctx->r4 = ADD32(ctx->r9, -0X1);
    after_5:
    // 0x808004C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808004C4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x808004C8: jal         0x800DC178
    // 0x808004CC: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800DC178(rdram, ctx);
        goto after_6;
    // 0x808004CC: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_6:
    // 0x808004D0: lh          $t2, 0xC($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XC);
    // 0x808004D4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x808004D8: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x808004DC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x808004E0: jal         0x800DC178
    // 0x808004E4: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    func_800DC178(rdram, ctx);
        goto after_7;
    // 0x808004E4: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_7:
    // 0x808004E8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808004EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x808004F0: jal         0x800EEB9C
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EEB9C(rdram, ctx);
        goto after_8;
    // 0x808004F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808004F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004FC: jal         0x800EF04C
    // 0x80800500: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800EF04C(rdram, ctx);
        goto after_9;
    // 0x80800500: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80800504: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80800508: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8080050C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800510: jal         0x80089830
    // 0x80800514: addiu       $a3, $s0, 0xC
    ctx->r7 = ADD32(ctx->r16, 0XC);
    _subaddie3d_entrypoint_0(rdram, ctx);
        goto after_10;
    // 0x80800514: addiu       $a3, $s0, 0xC
    ctx->r7 = ADD32(ctx->r16, 0XC);
    after_10:
    // 0x80800518: bne         $v0, $zero, L_80800528
    if (ctx->r2 != 0) {
        // 0x8080051C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800528;
    }
    // 0x8080051C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800520: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80800524: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_80800528:
    // 0x80800528: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8080052C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80800530: jal         0x80089838
    // 0x80800534: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    _subaddie3d_entrypoint_1(rdram, ctx);
        goto after_11;
    // 0x80800534: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_11:
    // 0x80800538: bnel        $v0, $zero, L_80800550
    if (ctx->r2 != 0) {
        // 0x8080053C: lwc1        $f16, 0xC($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80800550;
    }
    goto skip_1;
    // 0x8080053C: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    skip_1:
    // 0x80800540: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800544: sub.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f28.fl;
    // 0x80800548: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x8080054C: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
L_80800550:
    // 0x80800550: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80800554: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80800558: nop

    // 0x8080055C: bc1fl       L_80800574
    if (!c1cs) {
        // 0x80800560: sb          $zero, 0x10($s0)
        MEM_B(0X10, ctx->r16) = 0;
            goto L_80800574;
    }
    goto skip_2;
    // 0x80800560: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    skip_2:
    // 0x80800564: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x80800568: b           L_80800574
    // 0x8080056C: sb          $s5, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r21;
        goto L_80800574;
    // 0x8080056C: sb          $s5, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r21;
    // 0x80800570: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
L_80800574:
    // 0x80800574: lhu         $t3, 0x76($s3)
    ctx->r11 = MEM_HU(ctx->r19, 0X76);
    // 0x80800578: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8080057C: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80800580: srl         $t4, $t3, 7
    ctx->r12 = S32(U32(ctx->r11) >> 7);
    // 0x80800584: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80800588: bnel        $at, $zero, L_808004A4
    if (ctx->r1 != 0) {
        // 0x8080058C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_808004A4;
    }
    goto skip_3;
    // 0x8080058C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_3:
L_80800590:
    // 0x80800590: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80800594:
    // 0x80800594: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800598: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8080059C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x808005A0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x808005A4: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x808005A8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x808005AC: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x808005B0: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x808005B4: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x808005B8: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x808005BC: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x808005C0: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x808005C4: jr          $ra
    // 0x808005C8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x808005C8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80800998_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800998: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080099C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009A0: jal         0x80800448
    // 0x808009A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bstrexsmall_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808009A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009A8: jal         0x80082FF0
    // 0x808009AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsdrone_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x808009AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808009B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009B8: jr          $ra
    // 0x808009BC: nop

    return;
    // 0x808009BC: nop

;}
RECOMP_FUNC void func_800923A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800923A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800923AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800923B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800923B4: jal         0x80092258
    // 0x800923B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80092258(rdram, ctx);
        goto after_0;
    // 0x800923B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800923BC: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    // 0x800923C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800923C4: jal         0x800A2540
    // 0x800923C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A2540(rdram, ctx);
        goto after_1;
    // 0x800923C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x800923CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800923D0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800923D4: jal         0x800DF464
    // 0x800923D8: nop

    func_800DF464(rdram, ctx);
        goto after_2;
    // 0x800923D8: nop

    after_2:
    // 0x800923DC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800923E0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800923E4: beq         $t6, $zero, L_80092404
    if (ctx->r14 == 0) {
        // 0x800923E8: nop
    
            goto L_80092404;
    }
    // 0x800923E8: nop

    // 0x800923EC: lw          $v0, 0x50($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X50);
    // 0x800923F0: lbu         $t8, 0x16($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X16);
    // 0x800923F4: bne         $t8, $zero, L_80092404
    if (ctx->r24 != 0) {
        // 0x800923F8: nop
    
            goto L_80092404;
    }
    // 0x800923F8: nop

    // 0x800923FC: jal         0x800DF738
    // 0x80092400: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    func_800DF738(rdram, ctx);
        goto after_3;
    // 0x80092400: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_3:
L_80092404:
    // 0x80092404: jal         0x800DF830
    // 0x80092408: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_4;
    // 0x80092408: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8009240C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80092410: lbu         $a3, 0x1F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1F);
    // 0x80092414: lw          $v0, 0x50($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X50);
    // 0x80092418: lbu         $t0, 0x88($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X88);
    // 0x8009241C: beql        $t0, $zero, L_80092438
    if (ctx->r8 == 0) {
        // 0x80092420: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80092438;
    }
    goto skip_0;
    // 0x80092420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80092424: lbu         $a0, 0x89($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X89);
    // 0x80092428: lbu         $a1, 0x8A($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X8A);
    // 0x8009242C: jal         0x800DF5D8
    // 0x80092430: lbu         $a2, 0x8B($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X8B);
    func_800DF5D8(rdram, ctx);
        goto after_5;
    // 0x80092430: lbu         $a2, 0x8B($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X8B);
    after_5:
    // 0x80092434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80092438:
    // 0x80092438: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009243C: jr          $ra
    // 0x80092440: nop

    return;
    // 0x80092440: nop

;}
RECOMP_FUNC void mlMtx_push_duplicate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018DC4: lui         $t0, 0x8008
    ctx->r8 = S32(0X8008 << 16);
    // 0x80018DC8: addiu       $t0, $t0, -0x4350
    ctx->r8 = ADD32(ctx->r8, -0X4350);
    // 0x80018DCC: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x80018DD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018DD4: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80018DD8: addiu       $a2, $a3, 0x40
    ctx->r6 = ADD32(ctx->r7, 0X40);
L_80018DDC:
    // 0x80018DDC: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80018DE0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80018DE4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80018DE8: swc1        $f4, -0x10($a2)
    MEM_W(-0X10, ctx->r6) = ctx->f4.u32l;
    // 0x80018DEC: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80018DF0: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80018DF4: swc1        $f6, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->f6.u32l;
    // 0x80018DF8: lwc1        $f8, -0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, -0X8);
    // 0x80018DFC: swc1        $f8, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->f8.u32l;
    // 0x80018E00: lwc1        $f10, -0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, -0X4);
    // 0x80018E04: bne         $a1, $v0, L_80018DDC
    if (ctx->r5 != ctx->r2) {
        // 0x80018E08: swc1        $f10, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->f10.u32l;
            goto L_80018DDC;
    }
    // 0x80018E08: swc1        $f10, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f10.u32l;
    // 0x80018E0C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80018E10: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x80018E14: jr          $ra
    // 0x80018E18: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    return;
    // 0x80018E18: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
;}
RECOMP_FUNC void _bsjump_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083270: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x80083270);
    return;
    // 0x80083274: addi        $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
;}
RECOMP_FUNC void _bstimeout_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083F48: syscall     98
    recomp_syscall_handler(rdram, ctx, 0x80083F48);
    return;
    // 0x80083F4C: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void bskazjump_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001D0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808001D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808001E0: jal         0x8008CABC
    // 0x808001E4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808001E4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_0:
    // 0x808001E8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808001EC: lw          $t6, 0x164($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X164);
    // 0x808001F0: beql        $t6, $zero, L_80800204
    if (ctx->r14 == 0) {
        // 0x808001F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800204;
    }
    goto skip_0;
    // 0x808001F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x808001F8: jal         0x80083550
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazshock_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x808001FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800204:
    // 0x80800204: jal         0x80095738
    // 0x80800208: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    baflag_isTrue(rdram, ctx);
        goto after_2;
    // 0x80800208: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_2:
    // 0x8080020C: beq         $v0, $zero, L_80800224
    if (ctx->r2 == 0) {
        // 0x80800210: nop
    
            goto L_80800224;
    }
    // 0x80800210: nop

    // 0x80800214: jal         0x8009B7C0
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009B7C0(rdram, ctx);
        goto after_3;
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080021C: b           L_80800230
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80800230;
    // 0x80800220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800224:
    // 0x80800224: jal         0x800834B0
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _bskazmove_entrypoint_0(rdram, ctx);
        goto after_4;
    // 0x80800228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080022C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800230:
    // 0x80800230: jal         0x8009BB24
    // 0x80800234: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_8009BB24(rdram, ctx);
        goto after_5;
    // 0x80800234: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_5:
    // 0x80800238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080023C: jal         0x80091A30
    // 0x80800240: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_6;
    // 0x80800240: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_6:
    // 0x80800244: beq         $v0, $zero, L_80800270
    if (ctx->r2 == 0) {
        // 0x80800248: nop
    
            goto L_80800270;
    }
    // 0x80800248: nop

    // 0x8080024C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800250: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800254: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800258: nop

    // 0x8080025C: bc1f        L_80800270
    if (!c1cs) {
        // 0x80800260: nop
    
            goto L_80800270;
    }
    // 0x80800260: nop

    // 0x80800264: lw          $t7, 0x164($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X164);
    // 0x80800268: beq         $t7, $zero, L_80800280
    if (ctx->r15 == 0) {
        // 0x8080026C: nop
    
            goto L_80800280;
    }
    // 0x8080026C: nop

L_80800270:
    // 0x80800270: jal         0x8008D544
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008D544(rdram, ctx);
        goto after_7;
    // 0x80800274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800278: bnel        $v0, $zero, L_8080028C
    if (ctx->r2 != 0) {
        // 0x8080027C: lw          $v0, 0x15C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X15C);
            goto L_8080028C;
    }
    goto skip_1;
    // 0x8080027C: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    skip_1:
L_80800280:
    // 0x80800280: jal         0x8009BC6C
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_reset_gravity(rdram, ctx);
        goto after_8;
    // 0x80800284: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800288: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
L_8080028C:
    // 0x8080028C: beq         $v0, $zero, L_808002AC
    if (ctx->r2 == 0) {
        // 0x80800290: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808002AC;
    }
    // 0x80800290: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800294: beq         $v0, $at, L_80800304
    if (ctx->r2 == ctx->r1) {
        // 0x80800298: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800304;
    }
    // 0x80800298: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080029C: beql        $v0, $at, L_8080035C
    if (ctx->r2 == ctx->r1) {
        // 0x808002A0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080035C;
    }
    goto skip_2;
    // 0x808002A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x808002A4: b           L_8080035C
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8080035C;
    // 0x808002A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002AC:
    // 0x808002AC: jal         0x8008B324
    // 0x808002B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    anctrl_isStopped(rdram, ctx);
        goto after_9;
    // 0x808002B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_9:
    // 0x808002B4: beq         $v0, $zero, L_808002D4
    if (ctx->r2 == 0) {
        // 0x808002B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808002D4;
    }
    // 0x808002B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002BC: lui         $a1, 0x3F2A
    ctx->r5 = S32(0X3F2A << 16);
    // 0x808002C0: ori         $a1, $a1, 0xACDA
    ctx->r5 = ctx->r5 | 0XACDA;
    // 0x808002C4: jal         0x8008CF1C
    // 0x808002C8: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_10;
    // 0x808002C8: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    after_10:
    // 0x808002CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x808002D0: sw          $t8, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r24;
L_808002D4:
    // 0x808002D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002D8: jal         0x8008DF8C
    // 0x808002DC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    func_8008DF8C(rdram, ctx);
        goto after_11;
    // 0x808002DC: addiu       $a1, $zero, 0x82
    ctx->r5 = ADD32(0, 0X82);
    after_11:
    // 0x808002E0: beq         $v0, $zero, L_80800358
    if (ctx->r2 == 0) {
        // 0x808002E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800358;
    }
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808002E8: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x808002EC: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808002F0: jal         0x8008CF1C
    // 0x808002F4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_12;
    // 0x808002F4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_12:
    // 0x808002F8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x808002FC: b           L_80800358
    // 0x80800300: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
        goto L_80800358;
    // 0x80800300: sw          $t9, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r25;
L_80800304:
    // 0x80800304: jal         0x8008CAEC
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_13;
    // 0x80800308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8080030C: beq         $v0, $zero, L_8080031C
    if (ctx->r2 == 0) {
        // 0x80800310: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080031C;
    }
    // 0x80800310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800314: addiu       $t0, $zero, 0xDF
    ctx->r8 = ADD32(0, 0XDF);
    // 0x80800318: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_8080031C:
    // 0x8080031C: lw          $t1, 0x164($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X164);
    // 0x80800320: addiu       $t2, $zero, 0xC3
    ctx->r10 = ADD32(0, 0XC3);
    // 0x80800324: beq         $t1, $zero, L_80800334
    if (ctx->r9 == 0) {
        // 0x80800328: nop
    
            goto L_80800334;
    }
    // 0x80800328: nop

    // 0x8080032C: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
    // 0x80800330: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
L_80800334:
    // 0x80800334: jal         0x8008DF8C
    // 0x80800338: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    func_8008DF8C(rdram, ctx);
        goto after_14;
    // 0x80800338: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_14:
    // 0x8080033C: beq         $v0, $zero, L_80800358
    if (ctx->r2 == 0) {
        // 0x80800340: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800358;
    }
    // 0x80800340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800344: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80800348: jal         0x8008CF1C
    // 0x8080034C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    baanim_setEndAndDuration(rdram, ctx);
        goto after_15;
    // 0x8080034C: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    after_15:
    // 0x80800350: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80800354: sw          $t3, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->r11;
L_80800358:
    // 0x80800358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080035C:
    // 0x8080035C: jal         0x80091A30
    // 0x80800360: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    bakey_released(rdram, ctx);
        goto after_16;
    // 0x80800360: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_16:
    // 0x80800364: beq         $v0, $zero, L_80800370
    if (ctx->r2 == 0) {
        // 0x80800368: nop
    
            goto L_80800370;
    }
    // 0x80800368: nop

    // 0x8080036C: sw          $zero, 0x164($s0)
    MEM_W(0X164, ctx->r16) = 0;
L_80800370:
    // 0x80800370: jal         0x80097D9C
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_should_feathery_flap(rdram, ctx);
        goto after_17;
    // 0x80800374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80800378: beq         $v0, $zero, L_80800384
    if (ctx->r2 == 0) {
        // 0x8080037C: addiu       $t4, $zero, 0x15C
        ctx->r12 = ADD32(0, 0X15C);
            goto L_80800384;
    }
    // 0x8080037C: addiu       $t4, $zero, 0x15C
    ctx->r12 = ADD32(0, 0X15C);
    // 0x80800380: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80800384:
    // 0x80800384: jal         0x80097FB8
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097FB8(rdram, ctx);
        goto after_18;
    // 0x80800388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8080038C: beq         $v0, $zero, L_80800398
    if (ctx->r2 == 0) {
        // 0x80800390: addiu       $t5, $zero, 0xC4
        ctx->r13 = ADD32(0, 0XC4);
            goto L_80800398;
    }
    // 0x80800390: addiu       $t5, $zero, 0xC4
    ctx->r13 = ADD32(0, 0XC4);
    // 0x80800394: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_80800398:
    // 0x80800398: jal         0x80097E74
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bainput_func_80097E74(rdram, ctx);
        goto after_19;
    // 0x8080039C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x808003A0: beq         $v0, $zero, L_808003CC
    if (ctx->r2 == 0) {
        // 0x808003A4: nop
    
            goto L_808003CC;
    }
    // 0x808003A4: nop

    // 0x808003A8: jal         0x8009BB50
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baphysics_get_vertical_velocity(rdram, ctx);
        goto after_20;
    // 0x808003AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x808003B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808003B4: addiu       $t6, $zero, 0xBE
    ctx->r14 = ADD32(0, 0XBE);
    // 0x808003B8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808003BC: nop

    // 0x808003C0: bc1f        L_808003CC
    if (!c1cs) {
        // 0x808003C4: nop
    
            goto L_808003CC;
    }
    // 0x808003C4: nop

    // 0x808003C8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_808003CC:
    // 0x808003CC: jal         0x8008E078
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_21;
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x808003D4: beql        $v0, $zero, L_80800420
    if (ctx->r2 == 0) {
        // 0x808003D8: lwc1        $f10, 0x28($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
            goto L_80800420;
    }
    goto skip_3;
    // 0x808003D8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    skip_3:
    // 0x808003DC: jal         0x8009FE58
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8009FE58(rdram, ctx);
        goto after_22;
    // 0x808003E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x808003E4: jal         0x8009EF10
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    bastick_getZone(rdram, ctx);
        goto after_23;
    // 0x808003E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x808003EC: bne         $v0, $zero, L_808003FC
    if (ctx->r2 != 0) {
        // 0x808003F0: addiu       $t7, $zero, 0xDE
        ctx->r15 = ADD32(0, 0XDE);
            goto L_808003FC;
    }
    // 0x808003F0: addiu       $t7, $zero, 0xDE
    ctx->r15 = ADD32(0, 0XDE);
    // 0x808003F4: b           L_8080041C
    // 0x808003F8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_8080041C;
    // 0x808003F8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_808003FC:
    // 0x808003FC: jal         0x8008E39C
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008E39C(rdram, ctx);
        goto after_24;
    // 0x80800400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80800404: beq         $v0, $zero, L_80800418
    if (ctx->r2 == 0) {
        // 0x80800408: addiu       $t9, $zero, 0xBC
        ctx->r25 = ADD32(0, 0XBC);
            goto L_80800418;
    }
    // 0x80800408: addiu       $t9, $zero, 0xBC
    ctx->r25 = ADD32(0, 0XBC);
    // 0x8080040C: addiu       $t8, $zero, 0xC7
    ctx->r24 = ADD32(0, 0XC7);
    // 0x80800410: b           L_8080041C
    // 0x80800414: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_8080041C;
    // 0x80800414: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80800418:
    // 0x80800418: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_8080041C:
    // 0x8080041C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
L_80800420:
    // 0x80800420: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80800424: nop

    // 0x80800428: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8080042C: nop

    // 0x80800430: bc1fl       L_80800450
    if (!c1cs) {
        // 0x80800434: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800450;
    }
    goto skip_4;
    // 0x80800434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x80800438: jal         0x8008E35C
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_inWater(rdram, ctx);
        goto after_25;
    // 0x8080043C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80800440: beq         $v0, $zero, L_8080044C
    if (ctx->r2 == 0) {
        // 0x80800444: addiu       $t0, $zero, 0x160
        ctx->r8 = ADD32(0, 0X160);
            goto L_8080044C;
    }
    // 0x80800444: addiu       $t0, $zero, 0x160
    ctx->r8 = ADD32(0, 0X160);
    // 0x80800448: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_8080044C:
    // 0x8080044C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800450:
    // 0x80800450: jal         0x8009E5C8
    // 0x80800454: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    bs_setState(rdram, ctx);
        goto after_26;
    // 0x80800454: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_26:
    // 0x80800458: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080045C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800460: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800464: jr          $ra
    // 0x80800468: nop

    return;
    // 0x80800468: nop

;}
RECOMP_FUNC void _inantab_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088F70: syscall     750
    recomp_syscall_handler(rdram, ctx, 0x80088F70);
    return;
    // 0x80088F74: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80805380_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80805380: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80805384: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80805388: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x8080538C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80805390: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80805394: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80805398: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8080539C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x808053A0: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x808053A4: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x808053A8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x808053AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x808053B0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x808053B4: jal         0x800D8FEC
    // 0x808053B8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    func_800D8FEC(rdram, ctx);
        goto after_0;
    // 0x808053B8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_0:
    // 0x808053BC: beq         $v0, $zero, L_80805464
    if (ctx->r2 == 0) {
        // 0x808053C0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80805464;
    }
    // 0x808053C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808053C4: lui         $at, 0x8081
    ctx->r1 = S32(RELOC_HI16(439, 0XA470) << 16);
    // 0x808053C8: lwc1        $f30, -0x5B90($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(439, 0XA470));
    // 0x808053CC: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x808053D0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808053D4: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x808053D8: nop

L_808053DC:
    // 0x808053DC: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x808053E0: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x808053E4: jal         0x80013728
    // 0x808053E8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80013728(rdram, ctx);
        goto after_1;
    // 0x808053E8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x808053EC: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x808053F0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x808053F4: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x808053F8: c.eq.s      $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f24.fl == ctx->f2.fl;
    // 0x808053FC: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x80805400: bc1t        L_80805444
    if (c1cs) {
        // 0x80805404: nop
    
            goto L_80805444;
    }
    // 0x80805404: nop

    // 0x80805408: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
    // 0x8080540C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80805410: bc1fl       L_80805434
    if (!c1cs) {
        // 0x80805414: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_80805434;
    }
    goto skip_0;
    // 0x80805414: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_0:
    // 0x80805418: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8080541C: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80805420: jal         0x800F0D50
    // 0x80805424: neg.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = -ctx->f26.fl;
    func_800F0D50(rdram, ctx);
        goto after_2;
    // 0x80805424: neg.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = -ctx->f26.fl;
    after_2:
    // 0x80805428: b           L_80805444
    // 0x8080542C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
        goto L_80805444;
    // 0x8080542C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80805430: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_80805434:
    // 0x80805434: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80805438: jal         0x800F0D50
    // 0x8080543C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800F0D50(rdram, ctx);
        goto after_3;
    // 0x8080543C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x80805440: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80805444:
    // 0x80805444: mul.s       $f12, $f20, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80805448: jal         0x800F212C
    // 0x8080544C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_800F212C(rdram, ctx);
        goto after_4;
    // 0x8080544C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_4:
    // 0x80805450: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80805454: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80805458: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8080545C: bne         $s0, $zero, L_808053DC
    if (ctx->r16 != 0) {
        // 0x80805460: swc1        $f16, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
            goto L_808053DC;
    }
    // 0x80805460: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
L_80805464:
    // 0x80805464: jal         0x80013728
    // 0x80805468: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    func_80013728(rdram, ctx);
        goto after_5;
    // 0x80805468: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x8080546C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x80805470: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80805474: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80805478: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8080547C: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80805480: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80805484: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80805488: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8080548C: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80805490: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80805494: jr          $ra
    // 0x80805498: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80805498: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void _bskazglide_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833E0: syscall     59
    recomp_syscall_handler(rdram, ctx, 0x800833E0);
    return;
    // 0x800833E4: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
