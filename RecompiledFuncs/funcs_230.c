#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_8080000C_chdiggerbossinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800014: jal         0x800FE850
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800FE850(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800024: jr          $ra
    // 0x80800028: nop

    return;
    // 0x80800028: nop

;}
RECOMP_FUNC void _suexpression_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089800: syscall     795
    recomp_syscall_handler(rdram, ctx, 0x80089800);
    return;
    // 0x80089804: addi        $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
;}
RECOMP_FUNC void _chboxingglove_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085DD8: syscall     241
    recomp_syscall_handler(rdram, ctx, 0x80085DD8);
    return;
    // 0x80085DDC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_808001CC_chmayafarmer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D4: jal         0x80102424
    // 0x808001D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x808001D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001DC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808001E0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808001E4: lhu         $t7, 0x72($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X72);
    // 0x808001E8: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x808001EC: bnel        $t8, $at, L_8080021C
    if (ctx->r24 != ctx->r1) {
        // 0x808001F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080021C;
    }
    goto skip_0;
    // 0x808001F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808001F4: jal         0x800FC660
    // 0x808001F8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_800FC660(rdram, ctx);
        goto after_1;
    // 0x808001F8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x808001FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800200: addiu       $a1, $zero, 0xF07
    ctx->r5 = ADD32(0, 0XF07);
    // 0x80800204: jal         0x80800180
    // 0x80800208: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_80800180_chmayafarmer(rdram, ctx);
        goto after_2;
    // 0x80800208: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_2:
    // 0x8080020C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80800210: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80800214: swc1        $f4, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f4.u32l;
    // 0x80800218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080021C:
    // 0x8080021C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800220: jr          $ra
    // 0x80800224: nop

    return;
    // 0x80800224: nop

;}
RECOMP_FUNC void func_808025CC_chklungo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808025CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808025D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808025D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808025D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808025DC: jal         0x80100094
    // 0x808025E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808025E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808025E4: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x808025E8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x808025EC: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(1240, 0X38A0) << 16);
    // 0x808025F0: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x808025F4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x808025F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808025FC: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80802600: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80802604: addiu       $t1, $t1, 0x38A0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(1240, 0X38A0));
    // 0x80802608: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x8080260C: lw          $a3, 0xC($v1)
    ctx->r7 = MEM_W(ctx->r3, 0XC);
    // 0x80802610: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    // 0x80802614: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80802618: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8080261C: jal         0x8008A2D0
    // 0x80802620: addiu       $a1, $v0, 0x88
    ctx->r5 = ADD32(ctx->r2, 0X88);
    _susubgame_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80802620: addiu       $a1, $v0, 0x88
    ctx->r5 = ADD32(ctx->r2, 0X88);
    after_1:
    // 0x80802624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802628: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080262C: jr          $ra
    // 0x80802630: nop

    return;
    // 0x80802630: nop

;}
RECOMP_FUNC void func_80800CF0_subaddietaxi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800CF0: sll         $t6, $a0, 1
    ctx->r14 = S32(ctx->r4 << 1);
    // 0x80800CF4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(3334, 0XDB4) << 16);
    // 0x80800CF8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800CFC: jr          $ra
    // 0x80800D00: lh          $v0, 0xDB4($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(3334, 0XDB4));
    return;
    // 0x80800D00: lh          $v0, 0xDB4($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(3334, 0XDB4));
    // 0x80800D04: nop

    // 0x80800D08: nop

    // 0x80800D0C: nop

;}
RECOMP_FUNC void mlMtxScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019148: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001914C: addiu       $a0, $a0, -0x4350
    ctx->r4 = ADD32(ctx->r4, -0X4350);
    // 0x80019150: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019154: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80019158: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8001915C: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80019160: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x80019164: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80019168: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8001916C: beql        $v1, $a1, L_800191C0
    if (ctx->r3 == ctx->r5) {
        // 0x80019170: swc1        $f18, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
            goto L_800191C0;
    }
    goto skip_0;
    // 0x80019170: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    skip_0:
    // 0x80019174: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_80019178:
    // 0x80019178: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8001917C: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x80019180: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80019184: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80019188: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x8001918C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80019190: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x80019194: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80019198: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8001919C: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800191A0: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
    // 0x800191A4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800191A8: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x800191AC: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800191B0: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800191B4: bnel        $v1, $a1, L_80019178
    if (ctx->r3 != ctx->r5) {
        // 0x800191B8: swc1        $f18, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
            goto L_80019178;
    }
    goto skip_1;
    // 0x800191B8: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    skip_1:
    // 0x800191BC: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_800191C0:
    // 0x800191C0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800191C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800191C8: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x800191CC: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800191D0: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800191D4: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x800191D8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800191DC: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x800191E0: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800191E4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800191E8: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800191EC: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
    // 0x800191F0: jr          $ra
    // 0x800191F4: nop

    return;
    // 0x800191F4: nop

;}
RECOMP_FUNC void func_80802BE8_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802BE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802BF0: lw          $t6, 0x158($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X158);
    // 0x80802BF4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80802BF8: bnel        $t6, $zero, L_80802C18
    if (ctx->r14 != 0) {
        // 0x80802BFC: mfc1        $a1, $f12
        ctx->r5 = (int32_t)ctx->f12.u32l;
            goto L_80802C18;
    }
    goto skip_0;
    // 0x80802BFC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    skip_0:
    // 0x80802C00: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80802C04: jal         0x80094430
    // 0x80802C08: nop

    func_80094430(rdram, ctx);
        goto after_0;
    // 0x80802C08: nop

    after_0:
    // 0x80802C0C: b           L_80802C24
    // 0x80802C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802C24;
    // 0x80802C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80802C14: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
L_80802C18:
    // 0x80802C18: jal         0x80085538
    // 0x80802C1C: nop

    _badeathmatch_entrypoint_8(rdram, ctx);
        goto after_1;
    // 0x80802C1C: nop

    after_1:
    // 0x80802C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802C24:
    // 0x80802C24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802C28: jr          $ra
    // 0x80802C2C: nop

    return;
    // 0x80802C2C: nop

;}
RECOMP_FUNC void suexpressmorph_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808006DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808006E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808006E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x808006E8: sh          $a1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r5;
    // 0x808006EC: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    // 0x808006F0: jal         0x80800000
    // 0x808006F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80800000_suexpressmorph(rdram, ctx);
        goto after_0;
    // 0x808006F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x808006F8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x808006FC: sh          $v0, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r2;
    // 0x80800700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800708: jr          $ra
    // 0x8080070C: nop

    return;
    // 0x8080070C: nop

;}
RECOMP_FUNC void func_800D3D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3D10: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D3D14: jr          $ra
    // 0x800D3D18: sb          $a0, -0x4C0B($at)
    MEM_B(-0X4C0B, ctx->r1) = ctx->r4;
    return;
    // 0x800D3D18: sb          $a0, -0x4C0B($at)
    MEM_B(-0X4C0B, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void subaddiefind_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800618: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8080061C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800620: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800624: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80800628: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8080062C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800630: jal         0x80800000
    // 0x80800634: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    subaddiefind_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80800634: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x80800638: beq         $v0, $zero, L_80800670
    if (ctx->r2 == 0) {
        // 0x8080063C: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_80800670;
    }
    // 0x8080063C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80800640: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800644: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80800648: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8080064C: nop

    // 0x80800650: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800654: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80800658: nop

    // 0x8080065C: bc1fl       L_80800674
    if (!c1cs) {
        // 0x80800660: sw          $zero, 0x3C($v1)
        MEM_W(0X3C, ctx->r3) = 0;
            goto L_80800674;
    }
    goto skip_0;
    // 0x80800660: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    skip_0:
    // 0x80800664: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80800668: b           L_80800674
    // 0x8080066C: sw          $t7, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r15;
        goto L_80800674;
    // 0x8080066C: sw          $t7, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r15;
L_80800670:
    // 0x80800670: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
L_80800674:
    // 0x80800674: lw          $t8, 0x3C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X3C);
    // 0x80800678: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8080067C: beql        $t8, $zero, L_80800690
    if (ctx->r24 == 0) {
        // 0x80800680: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80800690;
    }
    goto skip_1;
    // 0x80800680: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_1:
    // 0x80800684: b           L_80800694
    // 0x80800688: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
        goto L_80800694;
    // 0x80800688: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8080068C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80800690:
    // 0x80800690: nop

L_80800694:
    // 0x80800694: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80800698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080069C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808006A0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x808006A4: jr          $ra
    // 0x808006A8: nop

    return;
    // 0x808006A8: nop

;}
RECOMP_FUNC void _chfactorytoxicpools_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086258: syscall     295
    recomp_syscall_handler(rdram, ctx, 0x80086258);
    return;
    // 0x8008625C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800E0AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0AF0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800E0AF4: jr          $ra
    // 0x800E0AF8: swc1        $f12, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x800E0AF8: swc1        $f12, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f12.u32l;
;}
RECOMP_FUNC void _scinfobar_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A580: syscall     845
    recomp_syscall_handler(rdram, ctx, 0x8008A580);
    return;
    // 0x8008A584: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808006C4_bsswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808006C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006CC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808006D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808006D4: jal         0x8008CABC
    // 0x808006D8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x808006D8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x808006DC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808006E0: jal         0x808001DC
    // 0x808006E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808001DC_bsswim(rdram, ctx);
        goto after_1;
    // 0x808006E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808006E8: jal         0x8009E710
    // 0x808006EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    bs_getPreviousState(rdram, ctx);
        goto after_2;
    // 0x808006EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808006F0: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x808006F4: bne         $v0, $at, L_80800708
    if (ctx->r2 != ctx->r1) {
        // 0x808006F8: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(384, 0XB78) << 16);
            goto L_80800708;
    }
    // 0x808006F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(384, 0XB78) << 16);
    // 0x808006FC: lwc1        $f4, 0xB78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0XB78));
    // 0x80800700: b           L_80800714
    // 0x80800704: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
        goto L_80800714;
    // 0x80800704: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
L_80800708:
    // 0x80800708: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(384, 0XB7C) << 16);
    // 0x8080070C: lwc1        $f6, 0xB7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0XB7C));
    // 0x80800710: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
L_80800714:
    // 0x80800714: jal         0x8008B264
    // 0x80800718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_getIndex(rdram, ctx);
        goto after_3;
    // 0x80800718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8080071C: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80800720: beql        $v0, $at, L_80800770
    if (ctx->r2 == ctx->r1) {
        // 0x80800724: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800770;
    }
    goto skip_0;
    // 0x80800724: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80800728: jal         0x8008AF24
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_reset(rdram, ctx);
        goto after_4;
    // 0x8080072C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800734: jal         0x8008AED4
    // 0x80800738: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    anctrl_setIndex(rdram, ctx);
        goto after_5;
    // 0x80800738: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_5:
    // 0x8080073C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800740: jal         0x8008B1C8
    // 0x80800744: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8008B1C8(rdram, ctx);
        goto after_6;
    // 0x80800744: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
    // 0x80800748: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x8080074C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800750: jal         0x8008B24C
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setStart(rdram, ctx);
        goto after_7;
    // 0x80800754: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080075C: jal         0x8008B134
    // 0x80800760: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_8;
    // 0x80800760: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_8:
    // 0x80800764: jal         0x8008B064
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_9;
    // 0x80800768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8080076C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80800770:
    // 0x80800770: jal         0x8008CA4C
    // 0x80800774: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8008CA4C(rdram, ctx);
        goto after_10;
    // 0x80800774: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80800778: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x8080077C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80800780: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800784: jal         0x8008C9BC
    // 0x80800788: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_11;
    // 0x80800788: lui         $a2, 0x3FC0
    ctx->r6 = S32(0X3FC0 << 16);
    after_11:
    // 0x8080078C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(384, 0XB80) << 16);
    // 0x80800790: lwc1        $f8, 0xB80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0XB80));
    // 0x80800794: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x80800798: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8080079C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007A0: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x808007A4: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x808007A8: jal         0x8008C9F0
    // 0x808007AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_12;
    // 0x808007AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_12:
    // 0x808007B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007B4: jal         0x8009C908
    // 0x808007B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    yaw_setUpdateType(rdram, ctx);
        goto after_13;
    // 0x808007B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x808007BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007C0: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x808007C4: jal         0x8009C99C
    // 0x808007C8: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_14;
    // 0x808007C8: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_14:
    // 0x808007CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007D0: jal         0x8009D2D8
    // 0x808007D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8009D2D8(rdram, ctx);
        goto after_15;
    // 0x808007D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x808007D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007DC: jal         0x8009B800
    // 0x808007E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    baphysics_set_type(rdram, ctx);
        goto after_16;
    // 0x808007E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_16:
    // 0x808007E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808007E8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808007EC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808007F0: jr          $ra
    // 0x808007F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x808007F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void capod_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8080000C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800010: jal         0x8008FFE8
    // 0x80800014: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8008FFE8(rdram, ctx);
        goto after_0;
    // 0x80800014: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x80800018: jal         0x80110024
    // 0x8080001C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80110024(rdram, ctx);
        goto after_1;
    // 0x8080001C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80800020: beql        $v0, $zero, L_80800058
    if (ctx->r2 == 0) {
        // 0x80800024: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80800058;
    }
    goto skip_0;
    // 0x80800024: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_0:
    // 0x80800028: jal         0x8008FFE8
    // 0x8080002C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8008FFE8(rdram, ctx);
        goto after_2;
    // 0x8080002C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800030: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80800034: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80800038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8080003C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80800040: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800044: jal         0x800894F0
    // 0x80800048: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    _ncpod_entrypoint_6(rdram, ctx);
        goto after_3;
    // 0x80800048: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x8080004C: b           L_8080005C
    // 0x80800050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8080005C;
    // 0x80800050: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800054: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80800058:
    // 0x80800058: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080005C:
    // 0x8080005C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800060: jr          $ra
    // 0x80800064: nop

    return;
    // 0x80800064: nop

;}
RECOMP_FUNC void func_80802D74_chfantasyathlete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802D74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80802D7C: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80802D80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802D84: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80802D88: beql        $t6, $at, L_80802D9C
    if (ctx->r14 == ctx->r1) {
        // 0x80802D8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802D9C;
    }
    goto skip_0;
    // 0x80802D8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80802D90: jal         0x80802C94
    // 0x80802D94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80802C94_chfantasyathlete(rdram, ctx);
        goto after_0;
    // 0x80802D94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80802D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802D9C:
    // 0x80802D9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80802DA0: jr          $ra
    // 0x80802DA4: nop

    return;
    // 0x80802DA4: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A850: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A850);
    return;
    // 0x8008A854: addi        $t0, $zero, 0x4C
    ctx->r8 = ADD32(0, 0X4C);
;}
RECOMP_FUNC void func_80800268_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800268: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080026C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800270: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800274: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800278: lhu         $t7, 0x72($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X72);
    // 0x8080027C: addiu       $t0, $a1, -0x2
    ctx->r8 = ADD32(ctx->r5, -0X2);
    // 0x80800280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800284: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800288: beq         $a1, $t8, L_808003E8
    if (ctx->r5 == ctx->r24) {
        // 0x8080028C: sltiu       $at, $t0, 0x5
        ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
            goto L_808003E8;
    }
    // 0x8080028C: sltiu       $at, $t0, 0x5
    ctx->r1 = ctx->r8 < 0X5 ? 1 : 0;
    // 0x80800290: beq         $at, $zero, L_808003DC
    if (ctx->r1 == 0) {
        // 0x80800294: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_808003DC;
    }
    // 0x80800294: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800298: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(760, 0X1060) << 16);
    // 0x8080029C: addu        $at, $at, $t0
    gpr jr_addend_808002A4 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x808002A0: lw          $t0, 0x1060($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(760, 0X1060));
    // 0x808002A4: jr          $t0
    // 0x808002A8: nop

    switch (jr_addend_808002A4 >> 2) {
        case 0: goto L_808002AC; break;
        case 1: goto L_80800328; break;
        case 2: goto L_808002E8; break;
        case 3: goto L_8080037C; break;
        case 4: goto L_808003D0; break;
        default: switch_error(__func__, 0x808002A4, 0x80801060);
    }
    // 0x808002A8: nop

L_808002AC:
    // 0x808002AC: beq         $a2, $zero, L_808002D0
    if (ctx->r6 == 0) {
        // 0x808002B0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_808002D0;
    }
    // 0x808002B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808002BC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808002C0: jal         0x80085708
    // 0x808002C4: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    _capod_entrypoint_13(rdram, ctx);
        goto after_0;
    // 0x808002C4: addiu       $a3, $zero, 0x2830
    ctx->r7 = ADD32(0, 0X2830);
    after_0:
    // 0x808002C8: b           L_808003E0
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003E0;
    // 0x808002CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002D0:
    // 0x808002D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808002D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808002D8: jal         0x80085708
    // 0x808002DC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    _capod_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x808002DC: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_1:
    // 0x808002E0: b           L_808003E0
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003E0;
    // 0x808002E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808002E8:
    // 0x808002E8: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    // 0x808002EC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(760, 0X1130) << 16);
    // 0x808002F0: addiu       $a2, $a2, 0x1130
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(760, 0X1130));
    // 0x808002F4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x808002F8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808002FC: jal         0x80089D18
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80800300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800304: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800308: addiu       $t1, $zero, 0x96
    ctx->r9 = ADD32(0, 0X96);
    // 0x8080030C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80800310: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80800314: addiu       $a1, $zero, 0x17EE
    ctx->r5 = ADD32(0, 0X17EE);
    // 0x80800318: jal         0x8008A208
    // 0x8080031C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_3;
    // 0x8080031C: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x80800320: b           L_808003E0
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003E0;
    // 0x80800324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80800328:
    // 0x80800328: jal         0x8008FD48
    // 0x8080032C: nop

    func_8008FD48(rdram, ctx);
        goto after_4;
    // 0x8080032C: nop

    after_4:
    // 0x80800330: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80800334: bne         $v0, $at, L_80800344
    if (ctx->r2 != ctx->r1) {
        // 0x80800338: nop
    
            goto L_80800344;
    }
    // 0x80800338: nop

    // 0x8080033C: b           L_8080035C
    // 0x80800340: addiu       $a1, $zero, 0x1805
    ctx->r5 = ADD32(0, 0X1805);
        goto L_8080035C;
    // 0x80800340: addiu       $a1, $zero, 0x1805
    ctx->r5 = ADD32(0, 0X1805);
L_80800344:
    // 0x80800344: jal         0x80800060
    // 0x80800348: nop

    func_80800060_chnastycavemen(rdram, ctx);
        goto after_5;
    // 0x80800348: nop

    after_5:
    // 0x8080034C: beq         $v0, $zero, L_8080035C
    if (ctx->r2 == 0) {
        // 0x80800350: addiu       $a1, $zero, 0x17DA
        ctx->r5 = ADD32(0, 0X17DA);
            goto L_8080035C;
    }
    // 0x80800350: addiu       $a1, $zero, 0x17DA
    ctx->r5 = ADD32(0, 0X17DA);
    // 0x80800354: b           L_8080035C
    // 0x80800358: addiu       $a1, $zero, 0x17DB
    ctx->r5 = ADD32(0, 0X17DB);
        goto L_8080035C;
    // 0x80800358: addiu       $a1, $zero, 0x17DB
    ctx->r5 = ADD32(0, 0X17DB);
L_8080035C:
    // 0x8080035C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800360: addiu       $t2, $zero, 0x96
    ctx->r10 = ADD32(0, 0X96);
    // 0x80800364: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800368: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    // 0x8080036C: jal         0x8008A208
    // 0x80800370: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_6;
    // 0x80800370: addiu       $a3, $s0, 0x4
    ctx->r7 = ADD32(ctx->r16, 0X4);
    after_6:
    // 0x80800374: b           L_808003E0
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003E0;
    // 0x80800378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8080037C:
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800380: jal         0x80100094
    // 0x80800384: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x80800384: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800388: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8080038C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800390: jal         0x800EE7F8
    // 0x80800394: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_8;
    // 0x80800394: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_8:
    // 0x80800398: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8080039C: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x808003A0: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x808003A4: jal         0x800EE7F8
    // 0x808003A8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    func_800EE7F8(rdram, ctx);
        goto after_9;
    // 0x808003A8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_9:
    // 0x808003AC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x808003B0: jal         0x800EE7F8
    // 0x808003B4: addiu       $a0, $a1, 0x18
    ctx->r4 = ADD32(ctx->r5, 0X18);
    func_800EE7F8(rdram, ctx);
        goto after_10;
    // 0x808003B4: addiu       $a0, $a1, 0x18
    ctx->r4 = ADD32(ctx->r5, 0X18);
    after_10:
    // 0x808003B8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808003BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x808003C0: jal         0x800EE7F8
    // 0x808003C4: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    func_800EE7F8(rdram, ctx);
        goto after_11;
    // 0x808003C4: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    after_11:
    // 0x808003C8: b           L_808003E0
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_808003E0;
    // 0x808003CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003D0:
    // 0x808003D0: lbu         $t4, 0x65($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X65);
    // 0x808003D4: ori         $t5, $t4, 0x10
    ctx->r13 = ctx->r12 | 0X10;
    // 0x808003D8: sb          $t5, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r13;
L_808003DC:
    // 0x808003DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_808003E0:
    // 0x808003E0: jal         0x80102424
    // 0x808003E4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80102424(rdram, ctx);
        goto after_12;
    // 0x808003E4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_12:
L_808003E8:
    // 0x808003E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808003EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808003F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808003F4: jr          $ra
    // 0x808003F8: nop

    return;
    // 0x808003F8: nop

;}
RECOMP_FUNC void func_80800454_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800454: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080045C: jal         0x808001E0
    // 0x80800460: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    bsmum_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800460: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800464: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800468: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8080046C: jal         0x808002B8
    // 0x80800470: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    func_808002B8_bsmum(rdram, ctx);
        goto after_1;
    // 0x80800470: sw          $zero, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = 0;
    after_1:
    // 0x80800474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080047C: jr          $ra
    // 0x80800480: nop

    return;
    // 0x80800480: nop

;}
RECOMP_FUNC void func_8080134C_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080134C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801350: slti        $at, $a1, 0x1401
    ctx->r1 = SIGNED(ctx->r5) < 0X1401 ? 1 : 0;
    // 0x80801354: bne         $at, $zero, L_80801380
    if (ctx->r1 != 0) {
        // 0x80801358: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80801380;
    }
    // 0x80801358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080135C: addiu       $t6, $a1, -0x1443
    ctx->r14 = ADD32(ctx->r5, -0X1443);
    // 0x80801360: sltiu       $at, $t6, 0xF
    ctx->r1 = ctx->r14 < 0XF ? 1 : 0;
    // 0x80801364: beq         $at, $zero, L_80801548
    if (ctx->r1 == 0) {
        // 0x80801368: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80801548;
    }
    // 0x80801368: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8080136C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2E9C) << 16);
    // 0x80801370: addu        $at, $at, $t6
    gpr jr_addend_80801378 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801374: lw          $t6, 0x2E9C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2E9C));
    // 0x80801378: jr          $t6
    // 0x8080137C: nop

    switch (jr_addend_80801378 >> 2) {
        case 0: goto L_808014B4; break;
        case 1: goto L_80801404; break;
        case 2: goto L_808014EC; break;
        case 3: goto L_808014EC; break;
        case 4: goto L_808014EC; break;
        case 5: goto L_80801520; break;
        case 6: goto L_80801548; break;
        case 7: goto L_80801548; break;
        case 8: goto L_80801548; break;
        case 9: goto L_80801548; break;
        case 10: goto L_80801548; break;
        case 11: goto L_80801548; break;
        case 12: goto L_80801548; break;
        case 13: goto L_80801548; break;
        case 14: goto L_808014DC; break;
        default: switch_error(__func__, 0x80801378, 0x80802E9C);
    }
    // 0x8080137C: nop

L_80801380:
    // 0x80801380: addiu       $t7, $a1, -0x13EE
    ctx->r15 = ADD32(ctx->r5, -0X13EE);
    // 0x80801384: sltiu       $at, $t7, 0x13
    ctx->r1 = ctx->r15 < 0X13 ? 1 : 0;
    // 0x80801388: beq         $at, $zero, L_80801548
    if (ctx->r1 == 0) {
        // 0x8080138C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80801548;
    }
    // 0x8080138C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80801390: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2384, 0X2ED8) << 16);
    // 0x80801394: addu        $at, $at, $t7
    gpr jr_addend_8080139C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80801398: lw          $t7, 0x2ED8($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2384, 0X2ED8));
    // 0x8080139C: jr          $t7
    // 0x808013A0: nop

    switch (jr_addend_8080139C >> 2) {
        case 0: goto L_808013A4; break;
        case 1: goto L_808013CC; break;
        case 2: goto L_808013CC; break;
        case 3: goto L_808013CC; break;
        case 4: goto L_808013CC; break;
        case 5: goto L_808013F4; break;
        case 6: goto L_80801404; break;
        case 7: goto L_80801404; break;
        case 8: goto L_80801414; break;
        case 9: goto L_80801434; break;
        case 10: goto L_80801414; break;
        case 11: goto L_80801414; break;
        case 12: goto L_80801424; break;
        case 13: goto L_8080147C; break;
        case 14: goto L_80801454; break;
        case 15: goto L_80801444; break;
        case 16: goto L_808014A4; break;
        case 17: goto L_808014A4; break;
        case 18: goto L_808014A4; break;
        default: switch_error(__func__, 0x8080139C, 0x80802ED8);
    }
    // 0x808013A0: nop

L_808013A4:
    // 0x808013A4: beq         $a2, $zero, L_808013BC
    if (ctx->r6 == 0) {
        // 0x808013A8: nop
    
            goto L_808013BC;
    }
    // 0x808013A8: nop

    // 0x808013AC: jal         0x808003D0
    // 0x808013B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_0;
    // 0x808013B0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x808013B4: b           L_8080154C
    // 0x808013B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x808013B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013BC:
    // 0x808013BC: jal         0x808003D0
    // 0x808013C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_1;
    // 0x808013C0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x808013C4: b           L_8080154C
    // 0x808013C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x808013C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013CC:
    // 0x808013CC: beq         $a2, $zero, L_808013E4
    if (ctx->r6 == 0) {
        // 0x808013D0: nop
    
            goto L_808013E4;
    }
    // 0x808013D0: nop

    // 0x808013D4: jal         0x808003D0
    // 0x808013D8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_2;
    // 0x808013D8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x808013DC: b           L_8080154C
    // 0x808013E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x808013E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013E4:
    // 0x808013E4: jal         0x808003D0
    // 0x808013E8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_3;
    // 0x808013E8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_3:
    // 0x808013EC: b           L_8080154C
    // 0x808013F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x808013F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808013F4:
    // 0x808013F4: jal         0x808003D0
    // 0x808013F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_4;
    // 0x808013F8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x808013FC: b           L_8080154C
    // 0x80801400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x80801400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801404:
    // 0x80801404: jal         0x808003D0
    // 0x80801408: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_5;
    // 0x80801408: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x8080140C: b           L_8080154C
    // 0x80801410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x80801410: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801414:
    // 0x80801414: jal         0x808003D0
    // 0x80801418: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_6;
    // 0x80801418: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_6:
    // 0x8080141C: b           L_8080154C
    // 0x80801420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x80801420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801424:
    // 0x80801424: jal         0x808003D0
    // 0x80801428: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_7;
    // 0x80801428: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_7:
    // 0x8080142C: b           L_8080154C
    // 0x80801430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x80801430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801434:
    // 0x80801434: jal         0x808003D0
    // 0x80801438: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_8;
    // 0x80801438: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_8:
    // 0x8080143C: b           L_8080154C
    // 0x80801440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x80801440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801444:
    // 0x80801444: jal         0x808003D0
    // 0x80801448: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_9;
    // 0x80801448: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_9:
    // 0x8080144C: b           L_8080154C
    // 0x80801450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x80801450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801454:
    // 0x80801454: beq         $a2, $zero, L_8080146C
    if (ctx->r6 == 0) {
        // 0x80801458: nop
    
            goto L_8080146C;
    }
    // 0x80801458: nop

    // 0x8080145C: jal         0x808003D0
    // 0x80801460: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_10;
    // 0x80801460: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_10:
    // 0x80801464: b           L_8080154C
    // 0x80801468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x80801468: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080146C:
    // 0x8080146C: jal         0x808003D0
    // 0x80801470: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_11;
    // 0x80801470: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_11:
    // 0x80801474: b           L_8080154C
    // 0x80801478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x80801478: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080147C:
    // 0x8080147C: beq         $a2, $zero, L_80801494
    if (ctx->r6 == 0) {
        // 0x80801480: nop
    
            goto L_80801494;
    }
    // 0x80801480: nop

    // 0x80801484: jal         0x808003D0
    // 0x80801488: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_12;
    // 0x80801488: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_12:
    // 0x8080148C: b           L_8080154C
    // 0x80801490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x80801490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801494:
    // 0x80801494: jal         0x808003D0
    // 0x80801498: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_13;
    // 0x80801498: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_13:
    // 0x8080149C: b           L_8080154C
    // 0x808014A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x808014A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014A4:
    // 0x808014A4: jal         0x808003D0
    // 0x808014A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_14;
    // 0x808014A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x808014AC: b           L_8080154C
    // 0x808014B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x808014B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014B4:
    // 0x808014B4: beq         $a2, $zero, L_808014CC
    if (ctx->r6 == 0) {
        // 0x808014B8: nop
    
            goto L_808014CC;
    }
    // 0x808014B8: nop

    // 0x808014BC: jal         0x808003D0
    // 0x808014C0: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_15;
    // 0x808014C0: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_15:
    // 0x808014C4: b           L_8080154C
    // 0x808014C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x808014C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014CC:
    // 0x808014CC: jal         0x808003D0
    // 0x808014D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_16;
    // 0x808014D0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_16:
    // 0x808014D4: b           L_8080154C
    // 0x808014D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x808014D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014DC:
    // 0x808014DC: jal         0x808003D0
    // 0x808014E0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_17;
    // 0x808014E0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_17:
    // 0x808014E4: b           L_8080154C
    // 0x808014E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x808014E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808014EC:
    // 0x808014EC: addiu       $a1, $zero, 0x1448
    ctx->r5 = ADD32(0, 0X1448);
    // 0x808014F0: addiu       $a2, $zero, 0x4E
    ctx->r6 = ADD32(0, 0X4E);
    // 0x808014F4: jal         0x808017F0
    // 0x808014F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808017F0_chtrashcangame(rdram, ctx);
        goto after_18;
    // 0x808014F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_18:
    // 0x808014FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801500: jal         0x80800014
    // 0x80801504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80800014_chtrashcangame(rdram, ctx);
        goto after_19;
    // 0x80801504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_19:
    // 0x80801508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080150C: addiu       $a1, $zero, 0x86
    ctx->r5 = ADD32(0, 0X86);
    // 0x80801510: jal         0x800D2054
    // 0x80801514: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800D2054(rdram, ctx);
        goto after_20;
    // 0x80801514: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_20:
    // 0x80801518: b           L_8080154C
    // 0x8080151C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x8080151C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801520:
    // 0x80801520: beq         $a2, $zero, L_80801538
    if (ctx->r6 == 0) {
        // 0x80801524: nop
    
            goto L_80801538;
    }
    // 0x80801524: nop

    // 0x80801528: jal         0x808003D0
    // 0x8080152C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_808003D0_chtrashcangame(rdram, ctx);
        goto after_21;
    // 0x8080152C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_21:
    // 0x80801530: b           L_8080154C
    // 0x80801534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8080154C;
    // 0x80801534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801538:
    // 0x80801538: jal         0x800C0850
    // 0x8080153C: nop

    func_800C0850(rdram, ctx);
        goto after_22;
    // 0x8080153C: nop

    after_22:
    // 0x80801540: jal         0x80088180
    // 0x80801544: nop

    _gcfrontend_entrypoint_10(rdram, ctx);
        goto after_23;
    // 0x80801544: nop

    after_23:
L_80801548:
    // 0x80801548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080154C:
    // 0x8080154C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801550: jr          $ra
    // 0x80801554: nop

    return;
    // 0x80801554: nop

;}
RECOMP_FUNC void _glcutDll_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800887D0: syscall     705
    recomp_syscall_handler(rdram, ctx, 0x800887D0);
    return;
    // 0x800887D4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _gcnewoption_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087D58: syscall     657
    recomp_syscall_handler(rdram, ctx, 0x80087D58);
    return;
    // 0x80087D5C: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void bsbansack_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080154C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80801550: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(41, 0X1E60) << 16);
    // 0x80801554: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80801558: jr          $ra
    // 0x8080155C: lw          $v0, 0x1E60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E60));
    return;
    // 0x8080155C: lw          $v0, 0x1E60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(41, 0X1E60));
;}
RECOMP_FUNC void func_800CB840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB840: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800CB844: addiu       $v0, $v0, -0x5190
    ctx->r2 = ADD32(ctx->r2, -0X5190);
    // 0x800CB848: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x800CB84C: jr          $ra
    // 0x800CB850: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    return;
    // 0x800CB850: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void sucoasterflydata_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800138: sltiu       $at, $a0, 0x5
    ctx->r1 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x8080013C: beq         $at, $zero, L_80800184
    if (ctx->r1 == 0) {
        // 0x80800140: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80800184;
    }
    // 0x80800140: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80800144: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800148: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3286, 0X254) << 16);
    // 0x8080014C: addu        $at, $at, $t6
    gpr jr_addend_80800154 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80800150: lw          $t6, 0x254($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3286, 0X254));
    // 0x80800154: jr          $t6
    // 0x80800158: nop

    switch (jr_addend_80800154 >> 2) {
        case 0: goto L_8080015C; break;
        case 1: goto L_80800164; break;
        case 2: goto L_8080016C; break;
        case 3: goto L_80800174; break;
        case 4: goto L_8080017C; break;
        default: switch_error(__func__, 0x80800154, 0x80800254);
    }
    // 0x80800158: nop

L_8080015C:
    // 0x8080015C: jr          $ra
    // 0x80800160: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    return;
    // 0x80800160: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
L_80800164:
    // 0x80800164: jr          $ra
    // 0x80800168: addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
    return;
    // 0x80800168: addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
L_8080016C:
    // 0x8080016C: jr          $ra
    // 0x80800170: addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
    return;
    // 0x80800170: addiu       $v0, $zero, 0xFA
    ctx->r2 = ADD32(0, 0XFA);
L_80800174:
    // 0x80800174: jr          $ra
    // 0x80800178: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    return;
    // 0x80800178: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
L_8080017C:
    // 0x8080017C: jr          $ra
    // 0x80800180: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    return;
    // 0x80800180: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
L_80800184:
    // 0x80800184: jr          $ra
    // 0x80800188: nop

    return;
    // 0x80800188: nop

;}
RECOMP_FUNC void func_800FFAB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFAB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FFAB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFAB8: lbu         $t7, 0x65($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X65);
    // 0x800FFABC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FFAC0: addiu       $v1, $v1, 0x5A50
    ctx->r3 = ADD32(ctx->r3, 0X5A50);
    // 0x800FFAC4: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x800FFAC8: sb          $t8, 0x65($a0)
    MEM_B(0X65, ctx->r4) = ctx->r24;
    // 0x800FFACC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800FFAD0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800FFAD4: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800FFAD8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800FFADC: lw          $a2, 0x40($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X40);
    // 0x800FFAE0: beql        $a2, $zero, L_800FFB3C
    if (ctx->r6 == 0) {
        // 0x800FFAE4: lbu         $t9, 0x7B($a1)
        ctx->r25 = MEM_BU(ctx->r5, 0X7B);
            goto L_800FFB3C;
    }
    goto skip_0;
    // 0x800FFAE4: lbu         $t9, 0x7B($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X7B);
    skip_0:
    // 0x800FFAE8: lw          $t1, 0x6C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X6C);
    // 0x800FFAEC: addiu       $at, $zero, 0x243
    ctx->r1 = ADD32(0, 0X243);
    // 0x800FFAF0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800FFAF4: sll         $t2, $t1, 11
    ctx->r10 = S32(ctx->r9 << 11);
    // 0x800FFAF8: srl         $t3, $t2, 20
    ctx->r11 = S32(U32(ctx->r10) >> 20);
    // 0x800FFAFC: beql        $t3, $at, L_800FFB3C
    if (ctx->r11 == ctx->r1) {
        // 0x800FFB00: lbu         $t9, 0x7B($a1)
        ctx->r25 = MEM_BU(ctx->r5, 0X7B);
            goto L_800FFB3C;
    }
    goto skip_1;
    // 0x800FFB00: lbu         $t9, 0x7B($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X7B);
    skip_1:
    // 0x800FFB04: jal         0x80106790
    // 0x800FFB08: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x800FFB08: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800FFB0C: lbu         $t5, 0x65($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X65);
    // 0x800FFB10: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800FFB14: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800FFB18: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x800FFB1C: sb          $t6, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r14;
    // 0x800FFB20: sw          $zero, 0x40($a1)
    MEM_W(0X40, ctx->r5) = 0;
    // 0x800FFB24: addiu       $v1, $v1, 0x5A50
    ctx->r3 = ADD32(ctx->r3, 0X5A50);
    // 0x800FFB28: sw          $zero, 0x40($v0)
    MEM_W(0X40, ctx->r2) = 0;
    // 0x800FFB2C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800FFB30: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800FFB34: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800FFB38: lbu         $t9, 0x7B($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X7B);
L_800FFB3C:
    // 0x800FFB3C: lbu         $t5, 0x74($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X74);
    // 0x800FFB40: andi        $t0, $t9, 0xFFFB
    ctx->r8 = ctx->r25 & 0XFFFB;
    // 0x800FFB44: sb          $t0, 0x7B($a1)
    MEM_B(0X7B, ctx->r5) = ctx->r8;
    // 0x800FFB48: lw          $t1, 0x78($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X78);
    // 0x800FFB4C: andi        $t6, $t5, 0xFFFE
    ctx->r14 = ctx->r13 & 0XFFFE;
    // 0x800FFB50: sll         $t2, $t1, 29
    ctx->r10 = S32(ctx->r9 << 29);
    // 0x800FFB54: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x800FFB58: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800FFB5C: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800FFB60: sb          $t7, 0x74($a1)
    MEM_B(0X74, ctx->r5) = ctx->r15;
    // 0x800FFB64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFB68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FFB6C: jr          $ra
    // 0x800FFB70: nop

    return;
    // 0x800FFB70: nop

;}
RECOMP_FUNC void sueggmove_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003E0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808003E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808003E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808003EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003F0: lui         $a3, 0x242
    ctx->r7 = S32(0X242 << 16);
    // 0x808003F4: ori         $a3, $a3, 0xA0
    ctx->r7 = ctx->r7 | 0XA0;
    // 0x808003F8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x808003FC: jal         0x800FAB50
    // 0x80800400: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800FAB50(rdram, ctx);
        goto after_0;
    // 0x80800400: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80800404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800408: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080040C: jr          $ra
    // 0x80800410: nop

    return;
    // 0x80800410: nop

    // 0x80800414: nop

    // 0x80800418: nop

    // 0x8080041C: nop

;}
RECOMP_FUNC void func_808001F8_chtalontorpedoboulder(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F8: lhu         $v1, 0x76($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X76);
    // 0x808001FC: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(1436, 0X314) << 16);
    // 0x80800200: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1436, 0X318) << 16);
    // 0x80800204: srl         $t6, $v1, 7
    ctx->r14 = S32(U32(ctx->r3) >> 7);
    // 0x80800208: addiu       $v1, $t6, -0x32
    ctx->r3 = ADD32(ctx->r14, -0X32);
    // 0x8080020C: addiu       $v0, $v0, 0x318
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1436, 0X318));
    // 0x80800210: addiu       $a1, $a1, 0x314
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(1436, 0X314));
    // 0x80800214: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
L_80800218:
    // 0x80800218: bnel        $v1, $t7, L_8080022C
    if (ctx->r3 != ctx->r15) {
        // 0x8080021C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8080022C;
    }
    goto skip_0;
    // 0x8080021C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    skip_0:
    // 0x80800220: jr          $ra
    // 0x80800224: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
    return;
    // 0x80800224: lh          $v0, 0x2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X2);
    // 0x80800228: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8080022C:
    // 0x8080022C: bnel        $a1, $v0, L_80800218
    if (ctx->r5 != ctx->r2) {
        // 0x80800230: lh          $t7, 0x0($a1)
        ctx->r15 = MEM_H(ctx->r5, 0X0);
            goto L_80800218;
    }
    goto skip_1;
    // 0x80800230: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    skip_1:
    // 0x80800234: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80800238: jr          $ra
    // 0x8080023C: nop

    return;
    // 0x8080023C: nop

;}
RECOMP_FUNC void _bskazcrouch_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083310: syscall     54
    recomp_syscall_handler(rdram, ctx, 0x80083310);
    return;
    // 0x80083314: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800608_bswasher(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800608: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080060C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800610: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800614: jal         0x80085228
    // 0x80800618: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    _basudie_entrypoint_5(rdram, ctx);
        goto after_0;
    // 0x80800618: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8080061C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800620: jal         0x8009B9B0
    // 0x80800624: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_1;
    // 0x80800624: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_1:
    // 0x80800628: lw          $v0, 0x15C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X15C);
    // 0x8080062C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800630: beq         $v0, $at, L_8080065C
    if (ctx->r2 == ctx->r1) {
        // 0x80800634: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8080065C;
    }
    // 0x80800634: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800638: beq         $v0, $at, L_8080067C
    if (ctx->r2 == ctx->r1) {
        // 0x8080063C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080067C;
    }
    // 0x8080063C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800640: beq         $v0, $at, L_8080069C
    if (ctx->r2 == ctx->r1) {
        // 0x80800644: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080069C;
    }
    // 0x80800644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800648: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080064C: beql        $v0, $at, L_808006B0
    if (ctx->r2 == ctx->r1) {
        // 0x80800650: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_808006B0;
    }
    goto skip_0;
    // 0x80800650: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_0:
    // 0x80800654: b           L_808006D8
    // 0x80800658: nop

        goto L_808006D8;
    // 0x80800658: nop

L_8080065C:
    // 0x8080065C: jal         0x8008E078
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_2;
    // 0x80800660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800664: beq         $v0, $zero, L_808006D8
    if (ctx->r2 == 0) {
        // 0x80800668: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D8;
    }
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080066C: jal         0x8080042C
    // 0x80800670: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8080042C_bswasher(rdram, ctx);
        goto after_3;
    // 0x80800670: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80800674: b           L_808006D8
    // 0x80800678: nop

        goto L_808006D8;
    // 0x80800678: nop

L_8080067C:
    // 0x8080067C: jal         0x8008E078
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    player_isStable(rdram, ctx);
        goto after_4;
    // 0x80800680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800684: beq         $v0, $zero, L_808006D8
    if (ctx->r2 == 0) {
        // 0x80800688: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808006D8;
    }
    // 0x80800688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080068C: jal         0x8080042C
    // 0x80800690: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8080042C_bswasher(rdram, ctx);
        goto after_5;
    // 0x80800690: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80800694: b           L_808006D8
    // 0x80800698: nop

        goto L_808006D8;
    // 0x80800698: nop

L_8080069C:
    // 0x8080069C: jal         0x8080042C
    // 0x808006A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8080042C_bswasher(rdram, ctx);
        goto after_6;
    // 0x808006A0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_6:
    // 0x808006A4: b           L_808006D8
    // 0x808006A8: nop

        goto L_808006D8;
    // 0x808006A8: nop

    // 0x808006AC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_808006B0:
    // 0x808006B0: lwc1        $f0, 0x16C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x808006B4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808006B8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x808006BC: nop

    // 0x808006C0: bc1f        L_808006D8
    if (!c1cs) {
        // 0x808006C4: nop
    
            goto L_808006D8;
    }
    // 0x808006C4: nop

    // 0x808006C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006CC: jal         0x800F0E00
    // 0x808006D0: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    func_800F0E00(rdram, ctx);
        goto after_7;
    // 0x808006D0: sub.s       $f14, $f0, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f4.fl;
    after_7:
    // 0x808006D4: swc1        $f0, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f0.u32l;
L_808006D8:
    // 0x808006D8: jal         0x80800300
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800300_bswasher(rdram, ctx);
        goto after_8;
    // 0x808006DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E4: jal         0x8009E5C8
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    bs_setState(rdram, ctx);
        goto after_9;
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x808006EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808006F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808006F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808006F8: jr          $ra
    // 0x808006FC: nop

    return;
    // 0x808006FC: nop

;}
RECOMP_FUNC void func_80802884_chdodgemcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802884: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80802888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080288C: jal         0x80104248
    // 0x80802890: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80104248(rdram, ctx);
        goto after_0;
    // 0x80802890: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80802894: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80802898: jal         0x8008AED4
    // 0x8080289C: addiu       $a1, $zero, 0x10A
    ctx->r5 = ADD32(0, 0X10A);
    anctrl_setIndex(rdram, ctx);
        goto after_1;
    // 0x8080289C: addiu       $a1, $zero, 0x10A
    ctx->r5 = ADD32(0, 0X10A);
    after_1:
    // 0x808028A0: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x808028A4: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x808028A8: jal         0x80101CDC
    // 0x808028AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80101CDC(rdram, ctx);
        goto after_2;
    // 0x808028AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808028B0: jal         0x808026D0
    // 0x808028B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808026D0_chdodgemcontrol(rdram, ctx);
        goto after_3;
    // 0x808028B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x808028B8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x808028BC: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x808028C0: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x808028C4: bgezl       $t9, L_808028D8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808028C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808028D8;
    }
    goto skip_0;
    // 0x808028C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808028CC: jal         0x808000B8
    // 0x808028D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_808000B8_chdodgemcontrol(rdram, ctx);
        goto after_4;
    // 0x808028D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x808028D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808028D8:
    // 0x808028D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808028DC: jr          $ra
    // 0x808028E0: nop

    return;
    // 0x808028E0: nop

;}
RECOMP_FUNC void ovl_unload(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    tooie_overlay_unloading(rdram, ctx);
    // 0x800819E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800819E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800819EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800819F0: lbu         $v0, 0xF($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XF);
    // 0x800819F4: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x800819F8: beq         $t6, $zero, L_80081A08
    if (ctx->r14 == 0) {
        // 0x800819FC: andi        $a1, $v0, 0x1
        ctx->r5 = ctx->r2 & 0X1;
            goto L_80081A08;
    }
    // 0x800819FC: andi        $a1, $v0, 0x1
    ctx->r5 = ctx->r2 & 0X1;
    // 0x80081A00: b           L_80081A80
    // 0x80081A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80081A80;
    // 0x80081A04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80081A08:
    // 0x80081A08: sltu        $t7, $zero, $a1
    ctx->r15 = 0 < ctx->r5 ? 1 : 0;
    // 0x80081A0C: beq         $t7, $zero, L_80081A20
    if (ctx->r15 == 0) {
        // 0x80081A10: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_80081A20;
    }
    // 0x80081A10: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80081A14: lh          $a1, 0x6($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X6);
    // 0x80081A18: sltu        $t8, $zero, $a1
    ctx->r24 = 0 < ctx->r5 ? 1 : 0;
    // 0x80081A1C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
L_80081A20:
    // 0x80081A20: jal         0x80082428
    // 0x80081A24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ovl_reset_syscalls(rdram, ctx);
        goto after_0;
    // 0x80081A24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80081A28: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80081A2C: addiu       $a1, $a1, 0x7C60
    ctx->r5 = ADD32(ctx->r5, 0X7C60);
    // 0x80081A30: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80081A34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80081A38: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80081A3C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80081A40: lh          $v0, 0x30($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X30);
    // 0x80081A44: addiu       $a3, $a3, 0x6738
    ctx->r7 = ADD32(ctx->r7, 0X6738);
    // 0x80081A48: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x80081A4C: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80081A50: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80081A54: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80081A58: addu        $v1, $a3, $t1
    ctx->r3 = ADD32(ctx->r7, ctx->r9);
    // 0x80081A5C: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80081A60: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80081A64: sh          $v0, 0x30($t5)
    MEM_H(0X30, ctx->r13) = ctx->r2;
    // 0x80081A68: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80081A6C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80081A70: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80081A74: jal         0x8001B084
    // 0x80081A78: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    heap_free(rdram, ctx);
        goto after_1;
    // 0x80081A78: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    after_1:
    // 0x80081A7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80081A80:
    // 0x80081A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081A84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80081A88: jr          $ra
    // 0x80081A8C: nop

    return;
    // 0x80081A8C: nop

;}
RECOMP_FUNC void suquiz_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008C0: sltiu       $at, $a0, 0x5
    ctx->r1 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x808008C4: beq         $at, $zero, L_8080099C
    if (ctx->r1 == 0) {
        // 0x808008C8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8080099C;
    }
    // 0x808008C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008CC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808008D0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3370, 0XF30) << 16);
    // 0x808008D4: addu        $at, $at, $t6
    gpr jr_addend_808008DC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808008D8: lw          $t6, 0xF30($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3370, 0XF30));
    // 0x808008DC: jr          $t6
    // 0x808008E0: nop

    switch (jr_addend_808008DC >> 2) {
        case 0: goto L_808008E4; break;
        case 1: goto L_80800904; break;
        case 2: goto L_8080092C; break;
        case 3: goto L_80800954; break;
        case 4: goto L_8080097C; break;
        default: switch_error(__func__, 0x808008DC, 0x80800F30);
    }
    // 0x808008E0: nop

L_808008E4:
    // 0x808008E4: jal         0x800DA524
    // 0x808008E8: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_800DA524(rdram, ctx);
        goto after_0;
    // 0x808008E8: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_0:
    // 0x808008EC: addiu       $a0, $zero, 0x442
    ctx->r4 = ADD32(0, 0X442);
    // 0x808008F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x808008F4: jal         0x800DA7A8
    // 0x808008F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_1;
    // 0x808008F8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x808008FC: b           L_808009A0
    // 0x80800900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808009A0;
    // 0x80800900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800904:
    // 0x80800904: jal         0x800DA524
    // 0x80800908: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_800DA524(rdram, ctx);
        goto after_2;
    // 0x80800908: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_2:
    // 0x8080090C: addiu       $a0, $zero, 0x442
    ctx->r4 = ADD32(0, 0X442);
    // 0x80800910: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800914: jal         0x800DA7A8
    // 0x80800918: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_3;
    // 0x80800918: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x8080091C: jal         0x80088178
    // 0x80800920: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_4;
    // 0x80800920: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    after_4:
    // 0x80800924: b           L_808009A0
    // 0x80800928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808009A0;
    // 0x80800928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080092C:
    // 0x8080092C: jal         0x800DA524
    // 0x80800930: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_800DA524(rdram, ctx);
        goto after_5;
    // 0x80800930: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_5:
    // 0x80800934: addiu       $a0, $zero, 0x442
    ctx->r4 = ADD32(0, 0X442);
    // 0x80800938: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8080093C: jal         0x800DA7A8
    // 0x80800940: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_6;
    // 0x80800940: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_6:
    // 0x80800944: jal         0x80088178
    // 0x80800948: addiu       $a0, $zero, 0x75
    ctx->r4 = ADD32(0, 0X75);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_7;
    // 0x80800948: addiu       $a0, $zero, 0x75
    ctx->r4 = ADD32(0, 0X75);
    after_7:
    // 0x8080094C: b           L_808009A0
    // 0x80800950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808009A0;
    // 0x80800950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800954:
    // 0x80800954: jal         0x800DA524
    // 0x80800958: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_800DA524(rdram, ctx);
        goto after_8;
    // 0x80800958: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_8:
    // 0x8080095C: addiu       $a0, $zero, 0x442
    ctx->r4 = ADD32(0, 0X442);
    // 0x80800960: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800964: jal         0x800DA7A8
    // 0x80800968: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_9;
    // 0x80800968: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_9:
    // 0x8080096C: jal         0x80088178
    // 0x80800970: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_10;
    // 0x80800970: addiu       $a0, $zero, 0x76
    ctx->r4 = ADD32(0, 0X76);
    after_10:
    // 0x80800974: b           L_808009A0
    // 0x80800978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_808009A0;
    // 0x80800978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080097C:
    // 0x8080097C: jal         0x800DA544
    // 0x80800980: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    func_800DA544(rdram, ctx);
        goto after_11;
    // 0x80800980: addiu       $a0, $zero, 0x441
    ctx->r4 = ADD32(0, 0X441);
    after_11:
    // 0x80800984: addiu       $a0, $zero, 0x442
    ctx->r4 = ADD32(0, 0X442);
    // 0x80800988: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8080098C: jal         0x800DA7A8
    // 0x80800990: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_800DA7A8(rdram, ctx);
        goto after_12;
    // 0x80800990: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_12:
    // 0x80800994: jal         0x80088178
    // 0x80800998: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_13;
    // 0x80800998: addiu       $a0, $zero, 0x84
    ctx->r4 = ADD32(0, 0X84);
    after_13:
L_8080099C:
    // 0x8080099C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808009A0:
    // 0x808009A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009A4: jr          $ra
    // 0x808009A8: nop

    return;
    // 0x808009A8: nop

;}
RECOMP_FUNC void chdiggerbossdoor_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808003B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808003BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808003C0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x808003C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x808003C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808003CC: jal         0x80106790
    // 0x808003D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x808003D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808003D4: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x808003D8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x808003DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808003E0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808003E4: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x808003E8: addu        $a0, $t0, $a1
    ctx->r4 = ADD32(ctx->r8, ctx->r5);
    // 0x808003EC: sltu        $at, $a1, $a0
    ctx->r1 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x808003F0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x808003F4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808003F8: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x808003FC: beq         $at, $zero, L_80800420
    if (ctx->r1 == 0) {
        // 0x80800400: sra         $v1, $t7, 16
        ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
            goto L_80800420;
    }
    // 0x80800400: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
L_80800404:
    // 0x80800404: lh          $t1, 0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X2);
    // 0x80800408: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8080040C: sltu        $at, $a1, $a0
    ctx->r1 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x80800410: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x80800414: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80800418: bne         $at, $zero, L_80800404
    if (ctx->r1 != 0) {
        // 0x8080041C: sh          $t2, -0xE($a2)
        MEM_H(-0XE, ctx->r6) = ctx->r10;
            goto L_80800404;
    }
    // 0x8080041C: sh          $t2, -0xE($a2)
    MEM_H(-0XE, ctx->r6) = ctx->r10;
L_80800420:
    // 0x80800420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800428: jr          $ra
    // 0x8080042C: nop

    return;
    // 0x8080042C: nop

;}
RECOMP_FUNC void gcfrontend_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080006C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800070: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80800074: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2650, 0XD80) << 16);
    // 0x80800078: addiu       $t7, $t7, 0xD80
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2650, 0XD80));
    // 0x8080007C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80800080: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800084: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80800088: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8080008C: lh          $s0, 0x2($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X2);
    // 0x80800090: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80800094: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800098: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080009C: addu        $s1, $t8, $s0
    ctx->r17 = ADD32(ctx->r24, ctx->r16);
    // 0x808000A0: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x808000A4: beql        $at, $zero, L_808000D4
    if (ctx->r1 == 0) {
        // 0x808000A8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_808000D4;
    }
    goto skip_0;
    // 0x808000A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_808000AC:
    // 0x808000AC: jal         0x800DA298
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x808000B4: beq         $v0, $zero, L_808000C4
    if (ctx->r2 == 0) {
        // 0x808000B8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_808000C4;
    }
    // 0x808000B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x808000BC: b           L_808000D4
    // 0x808000C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808000D4;
    // 0x808000C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808000C4:
    // 0x808000C4: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x808000C8: bne         $at, $zero, L_808000AC
    if (ctx->r1 != 0) {
        // 0x808000CC: nop
    
            goto L_808000AC;
    }
    // 0x808000CC: nop

    // 0x808000D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808000D4:
    // 0x808000D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808000D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808000DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808000E0: jr          $ra
    // 0x808000E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808000E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80100938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100938: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010093C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80100940: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80100944: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100948: lw          $a0, 0x5A64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A64);
    // 0x8010094C: jal         0x800B301C
    // 0x80100950: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    freelist_at(rdram, ctx);
        goto after_0;
    // 0x80100950: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80100954: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x80100958: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8010095C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80100960: bne         $t8, $zero, L_801009B4
    if (ctx->r24 != 0) {
        // 0x80100964: sb          $t7, 0x8($v0)
        MEM_B(0X8, ctx->r2) = ctx->r15;
            goto L_801009B4;
    }
    // 0x80100964: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    // 0x80100968: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8010096C: jal         0x800887A0
    // 0x80100970: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    _glpackvtx_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80100970: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80100974: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80100978: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010097C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80100980: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x80100984: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80100988: jal         0x800B32C0
    // 0x8010098C: lw          $a0, 0x5A64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A64);
    freelist_erase(rdram, ctx);
        goto after_2;
    // 0x8010098C: lw          $a0, 0x5A64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A64);
    after_2:
    // 0x80100990: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100994: jal         0x800B3204
    // 0x80100998: lw          $a0, 0x5A64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A64);
    freelist_used_count(rdram, ctx);
        goto after_3;
    // 0x80100998: lw          $a0, 0x5A64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A64);
    after_3:
    // 0x8010099C: bne         $v0, $zero, L_801009B4
    if (ctx->r2 != 0) {
        // 0x801009A0: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801009B4;
    }
    // 0x801009A0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801009A4: jal         0x800B3248
    // 0x801009A8: lw          $a0, 0x5A64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A64);
    freelist_free(rdram, ctx);
        goto after_4;
    // 0x801009A8: lw          $a0, 0x5A64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5A64);
    after_4:
    // 0x801009AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801009B0: sw          $zero, 0x5A64($at)
    MEM_W(0X5A64, ctx->r1) = 0;
L_801009B4:
    // 0x801009B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801009B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801009BC: jr          $ra
    // 0x801009C0: nop

    return;
    // 0x801009C0: nop

;}
RECOMP_FUNC void func_80800510_cheggproximity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800510: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800514: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800518: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080051C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800520: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800524: jal         0x800EEEA8
    // 0x80800528: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_800EEEA8(rdram, ctx);
        goto after_0;
    // 0x80800528: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x8080052C: beq         $v0, $zero, L_80800544
    if (ctx->r2 == 0) {
        // 0x80800530: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800544;
    }
    // 0x80800530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800534: jal         0x80800718
    // 0x80800538: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800718_cheggproximity(rdram, ctx);
        goto after_1;
    // 0x80800538: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8080053C: b           L_80800578
    // 0x80800540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800578;
    // 0x80800540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800544:
    // 0x80800544: jal         0x808001CC
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808001CC_cheggproximity(rdram, ctx);
        goto after_2;
    // 0x80800548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080054C: jal         0x8008A3F8
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_16(rdram, ctx);
        goto after_3;
    // 0x80800550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800554: jal         0x8008A3E8
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _suegg_entrypoint_14(rdram, ctx);
        goto after_4;
    // 0x80800558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8080055C: beql        $v0, $zero, L_80800578
    if (ctx->r2 == 0) {
        // 0x80800560: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800578;
    }
    goto skip_0;
    // 0x80800560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800564: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80800568: lbu         $t7, 0x39($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X39);
    // 0x8080056C: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80800570: sb          $t8, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r24;
    // 0x80800574: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800578:
    // 0x80800578: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080057C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800580: jr          $ra
    // 0x80800584: nop

    return;
    // 0x80800584: nop

;}
RECOMP_FUNC void _chjiggytemple_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085B70: syscall     200
    recomp_syscall_handler(rdram, ctx, 0x80085B70);
    return;
    // 0x80085B74: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_808009D4_chnests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009DC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x808009E0: jal         0x8010DD20
    // 0x808009E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8010DD20(rdram, ctx);
        goto after_0;
    // 0x808009E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x808009E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009F0: jr          $ra
    // 0x808009F4: nop

    return;
    // 0x808009F4: nop

;}
RECOMP_FUNC void _suquiz_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A7B8: syscall     853
    recomp_syscall_handler(rdram, ctx, 0x8008A7B8);
    return;
    // 0x8008A7BC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80802090_chevilspirit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80802090: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80802094: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80802098: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080209C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808020A0: lbu         $a2, 0x5F($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X5F);
    // 0x808020A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808020A8: bnel        $a2, $zero, L_808020D0
    if (ctx->r6 != 0) {
        // 0x808020AC: addiu       $t6, $s0, 0x4
        ctx->r14 = ADD32(ctx->r16, 0X4);
            goto L_808020D0;
    }
    goto skip_0;
    // 0x808020AC: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x808020B0: jal         0x80089D10
    // 0x808020B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    _subaddieaudioquick_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808020B4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x808020B8: sb          $v0, 0x5F($s0)
    MEM_B(0X5F, ctx->r16) = ctx->r2;
    // 0x808020BC: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x808020C0: jal         0x800C330C
    // 0x808020C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_1;
    // 0x808020C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x808020C8: lbu         $a2, 0x5F($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X5F);
    // 0x808020CC: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
L_808020D0:
    // 0x808020D0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x808020D4: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x808020D8: jal         0x800C3058
    // 0x808020DC: addiu       $a1, $zero, 0x55F0
    ctx->r5 = ADD32(0, 0X55F0);
    func_800C3058(rdram, ctx);
        goto after_2;
    // 0x808020DC: addiu       $a1, $zero, 0x55F0
    ctx->r5 = ADD32(0, 0X55F0);
    after_2:
    // 0x808020E0: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808020E4: jal         0x800C31DC
    // 0x808020E8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800C31DC(rdram, ctx);
        goto after_3;
    // 0x808020E8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x808020EC: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    // 0x808020F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x808020F4: jal         0x800C4350
    // 0x808020F8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800C4350(rdram, ctx);
        goto after_4;
    // 0x808020F8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x808020FC: jal         0x800C3BDC
    // 0x80802100: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    func_800C3BDC(rdram, ctx);
        goto after_5;
    // 0x80802100: lbu         $a0, 0x5F($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X5F);
    after_5:
    // 0x80802104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80802108: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080210C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80802110: jr          $ra
    // 0x80802114: nop

    return;
    // 0x80802114: nop

;}
RECOMP_FUNC void _bsstonehead_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083C40: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083C40);
    return;
    // 0x80083C44: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void func_80092E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092E80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092E88: lw          $t6, 0x50($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X50);
    // 0x80092E8C: jal         0x800AE080
    // 0x80092E90: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    func_800AE080(rdram, ctx);
        goto after_0;
    // 0x80092E90: lh          $a0, 0x0($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X0);
    after_0:
    // 0x80092E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092E98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092E9C: jr          $ra
    // 0x80092EA0: nop

    return;
    // 0x80092EA0: nop

;}
RECOMP_FUNC void _plcamera_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800878D0: syscall     639
    recomp_syscall_handler(rdram, ctx, 0x800878D0);
    return;
    // 0x800878D4: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_80081F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081F64: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80081F68: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80081F6C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80081F70: beq         $t0, $zero, L_80081FC0
    if (ctx->r8 == 0) {
        // 0x80081F74: sw          $ra, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r31;
            goto L_80081FC0;
    }
    // 0x80081F74: sw          $ra, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r31;
    // 0x80081F78: lhu         $t1, 0x6($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X6);
    // 0x80081F7C: lui         $t2, 0x8008
    ctx->r10 = S32(0X8008 << 16);
    // 0x80081F80: addiu       $t2, $t2, 0x1E18
    ctx->r10 = ADD32(ctx->r10, 0X1E18);
    // 0x80081F84: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x80081F88: lw          $t1, 0x38($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X38);
    // 0x80081F8C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80081F90: addiu       $t0, $a0, 0x10
    ctx->r8 = ADD32(ctx->r4, 0X10);
    // 0x80081F94: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80081F98: srl         $t1, $t1, 6
    ctx->r9 = S32(U32(ctx->r9) >> 6);
    // 0x80081F9C: or          $t3, $t3, $t1
    ctx->r11 = ctx->r11 | ctx->r9;
    // 0x80081FA0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80081FA4: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80081FA8: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80081FAC: sw          $zero, 0xC($t0)
    MEM_W(0XC, ctx->r8) = 0;
    // 0x80081FB0: sw          $a3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r7;
    // 0x80081FB4: sw          $zero, 0x14($t0)
    MEM_W(0X14, ctx->r8) = 0;
    // 0x80081FB8: b           L_80082018
    // 0x80081FBC: sw          $t4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r12;
        goto L_80082018;
    // 0x80081FBC: sw          $t4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r12;
L_80081FC0:
    // 0x80081FC0: addiu       $t2, $a0, 0x38
    ctx->r10 = ADD32(ctx->r4, 0X38);
    // 0x80081FC4: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x80081FC8: and         $t1, $t2, $t3
    ctx->r9 = ctx->r10 & ctx->r11;
    // 0x80081FCC: srl         $t2, $t2, 16
    ctx->r10 = S32(U32(ctx->r10) >> 16);
    // 0x80081FD0: and         $t2, $t2, $t3
    ctx->r10 = ctx->r10 & ctx->r11;
    // 0x80081FD4: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x80081FD8: addiu       $t3, $t3, 0x1E00
    ctx->r11 = ADD32(ctx->r11, 0X1E00);
    // 0x80081FDC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80081FE0: addiu       $t0, $a0, 0x10
    ctx->r8 = ADD32(ctx->r4, 0X10);
    // 0x80081FE4: or          $t4, $t4, $t2
    ctx->r12 = ctx->r12 | ctx->r10;
    // 0x80081FE8: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80081FEC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80081FF0: or          $t4, $t4, $t1
    ctx->r12 = ctx->r12 | ctx->r9;
    // 0x80081FF4: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80081FF8: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80081FFC: sw          $t4, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r12;
    // 0x80082000: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x80082004: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    // 0x80082008: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8008200C: sw          $t4, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r12;
    // 0x80082010: lw          $t4, 0x14($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X14);
    // 0x80082014: sw          $t4, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r12;
L_80082018:
    // 0x80082018: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8008201C: jal         0x8002E660
    // 0x80082020: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80082020: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_0:
    // 0x80082024: jal         0x80030AB0
    // 0x80082028: nop

    osInvalICache_recomp(rdram, ctx);
        goto after_1;
    // 0x80082028: nop

    after_1:
    // 0x8008202C: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x80082030: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80082034: lui         $t1, 0x800
    ctx->r9 = S32(0X800 << 16);
    // 0x80082038: addiu       $t0, $a0, 0x10
    ctx->r8 = ADD32(ctx->r4, 0X10);
    // 0x8008203C: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80082040: srl         $t0, $t0, 6
    ctx->r8 = S32(U32(ctx->r8) >> 6);
    // 0x80082044: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x80082048: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8008204C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80082050: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
L_80082054:
    // 0x80082054: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80082058: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8008205C: beql        $t1, $t2, L_80082054
    if (ctx->r9 == ctx->r10) {
        // 0x80082060: lw          $t2, 0x8($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X8);
            goto L_80082054;
    }
    goto skip_0;
    // 0x80082060: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    skip_0:
    // 0x80082064: jal         0x8002E660
    // 0x80082068: sub         $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    osWritebackDCache_recomp(rdram, ctx);
        goto after_2;
    // 0x80082068: sub         $a1, $a1, $a0
    ctx->r5 = SUB32(ctx->r5, ctx->r4);
    after_2:
    // 0x8008206C: jal         0x80030AB0
    // 0x80082070: nop

    osInvalICache_recomp(rdram, ctx);
        goto after_3;
    // 0x80082070: nop

    after_3:
    // 0x80082074: lw          $ra, 0x8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8);
    // 0x80082078: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8008207C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80082080: jr          $ra
    // 0x80082084: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80082084: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_800F1F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1F0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F1F10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F1F14: jal         0x800F1DF4
    // 0x800F1F18: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F1DF4(rdram, ctx);
        goto after_0;
    // 0x800F1F18: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800F1F1C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x800F1F20: jal         0x800F1DCC
    // 0x800F1F24: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    func_800F1DCC(rdram, ctx);
        goto after_1;
    // 0x800F1F24: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800F1F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1F2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F1F30: jr          $ra
    // 0x800F1F34: nop

    return;
    // 0x800F1F34: nop

;}
RECOMP_FUNC void func_800D7570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D7570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D7574: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800D7578: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D757C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800D7580: jal         0x8001B798
    // 0x800D7584: lh          $a0, -0x400A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X400A);
    func_8001B798(rdram, ctx);
        goto after_0;
    // 0x800D7584: lh          $a0, -0x400A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X400A);
    after_0:
    // 0x800D7588: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800D758C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D7590: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D7594: bne         $a1, $at, L_800D75A4
    if (ctx->r5 != ctx->r1) {
        // 0x800D7598: sll         $t6, $a1, 1
        ctx->r14 = S32(ctx->r5 << 1);
            goto L_800D75A4;
    }
    // 0x800D7598: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800D759C: b           L_800D75CC
    // 0x800D75A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D75CC;
    // 0x800D75A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D75A4:
    // 0x800D75A4: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800D75A8: jal         0x8001B798
    // 0x800D75AC: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    func_8001B798(rdram, ctx);
        goto after_1;
    // 0x800D75AC: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    after_1:
    // 0x800D75B0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800D75B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D75B8: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    // 0x800D75BC: bne         $t8, $zero, L_800D75CC
    if (ctx->r24 != 0) {
        // 0x800D75C0: nop
    
            goto L_800D75CC;
    }
    // 0x800D75C0: nop

    // 0x800D75C4: b           L_800D75CC
    // 0x800D75C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D75CC;
    // 0x800D75C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D75CC:
    // 0x800D75CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D75D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D75D4: jr          $ra
    // 0x800D75D8: nop

    return;
    // 0x800D75D8: nop

;}
RECOMP_FUNC void yaw_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C984: lw          $t6, 0xF8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C988: jr          $ra
    // 0x8009C98C: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    return;
    // 0x8009C98C: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
;}
RECOMP_FUNC void bsstatue_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009AC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808009B0: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(372, 0X15B0) << 16);
    // 0x808009B4: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808009B8: jr          $ra
    // 0x808009BC: lw          $v0, 0x15B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X15B0));
    return;
    // 0x808009BC: lw          $v0, 0x15B0($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(372, 0X15B0));
;}
