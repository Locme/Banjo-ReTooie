#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_80801190_gcnewoption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801198: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8080119C: lh          $v0, 0x6($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X6);
    // 0x808011A0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808011A4: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x808011A8: bne         $at, $zero, L_808011B8
    if (ctx->r1 != 0) {
        // 0x808011AC: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_808011B8;
    }
    // 0x808011AC: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x808011B0: b           L_80801208
    // 0x808011B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801208;
    // 0x808011B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808011B8:
    // 0x808011B8: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
    // 0x808011BC: lh          $a1, 0x6($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X6);
    // 0x808011C0: jal         0x80800038
    // 0x808011C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800038_gcnewoption(rdram, ctx);
        goto after_0;
    // 0x808011C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808011C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808011CC: bne         $v0, $at, L_80801204
    if (ctx->r2 != ctx->r1) {
        // 0x808011D0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80801204;
    }
    // 0x808011D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808011D4: lh          $t1, 0xA($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XA);
    // 0x808011D8: lh          $t9, 0x8($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8);
    // 0x808011DC: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x808011E0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x808011E4: sh          $t2, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r10;
    // 0x808011E8: lh          $t3, 0xA($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XA);
    // 0x808011EC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x808011F0: sh          $t0, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r8;
    // 0x808011F4: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x808011F8: bnel        $at, $zero, L_80801208
    if (ctx->r1 != 0) {
        // 0x808011FC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801208;
    }
    goto skip_0;
    // 0x808011FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80801200: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
L_80801204:
    // 0x80801204: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801208:
    // 0x80801208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080120C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801210: jr          $ra
    // 0x80801214: nop

    return;
    // 0x80801214: nop

;}
RECOMP_FUNC void func_8080000C_chlavafall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080000C: lbu         $t6, 0x7A($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7A);
    // 0x80800010: andi        $t7, $t6, 0xFF3F
    ctx->r15 = ctx->r14 & 0XFF3F;
    // 0x80800014: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80800018: jr          $ra
    // 0x8080001C: sb          $t8, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r24;
    return;
    // 0x8080001C: sb          $t8, 0x7A($a0)
    MEM_B(0X7A, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void chanim_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800200: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80800204: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080020C: jal         0x80100074
    // 0x80800210: addiu       $a2, $zero, 0xFC
    ctx->r6 = ADD32(0, 0XFC);
    func_80100074(rdram, ctx);
        goto after_0;
    // 0x80800210: addiu       $a2, $zero, 0xFC
    ctx->r6 = ADD32(0, 0XFC);
    after_0:
    // 0x80800214: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800218: jal         0x80100094
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_1;
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80800220: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80800224: sw          $zero, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = 0;
    // 0x80800228: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8080022C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80800230: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800234: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800238: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8080023C: sw          $t6, 0xF4($v0)
    MEM_W(0XF4, ctx->r2) = ctx->r14;
L_80800240:
    // 0x80800240: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80800244: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80800248: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8080024C: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x80800250: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80800254: bne         $a0, $a1, L_80800240
    if (ctx->r4 != ctx->r5) {
        // 0x80800258: sw          $zero, -0xC($v1)
        MEM_W(-0XC, ctx->r3) = 0;
            goto L_80800240;
    }
    // 0x80800258: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x8080025C: lw          $t7, 0xF4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XF4);
    // 0x80800260: beql        $t7, $zero, L_8080027C
    if (ctx->r15 == 0) {
        // 0x80800264: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8080027C;
    }
    goto skip_0;
    // 0x80800264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800268: jal         0x80082648
    // 0x8080026C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    _anseq_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x8080026C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80800270: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80800274: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x80800278: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080027C:
    // 0x8080027C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800280: jr          $ra
    // 0x80800284: nop

    return;
    // 0x80800284: nop

;}
RECOMP_FUNC void func_80804220_chgameselect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804220: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80804224: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804228: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080422C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804230: jal         0x80803D60
    // 0x80804234: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    func_80803D60_chgameselect(rdram, ctx);
        goto after_0;
    // 0x80804234: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    after_0:
    // 0x80804238: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8080423C: jal         0x8080218C
    // 0x80804240: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8080218C_chgameselect(rdram, ctx);
        goto after_1;
    // 0x80804240: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80804244: jal         0x80803D60
    // 0x80804248: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_80803D60_chgameselect(rdram, ctx);
        goto after_2;
    // 0x80804248: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_2:
    // 0x8080424C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80804250: jal         0x8080218C
    // 0x80804254: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8080218C_chgameselect(rdram, ctx);
        goto after_3;
    // 0x80804254: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80804258: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x8080425C: jal         0x80801758
    // 0x80804260: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_80801758_chgameselect(rdram, ctx);
        goto after_4;
    // 0x80804260: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_4:
    // 0x80804264: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80804268: jal         0x80801658
    // 0x8080426C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80801658_chgameselect(rdram, ctx);
        goto after_5;
    // 0x8080426C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80804270: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80804274: jal         0x808015DC
    // 0x80804278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808015DC_chgameselect(rdram, ctx);
        goto after_6;
    // 0x80804278: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8080427C: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x80804280: jal         0x808016A0
    // 0x80804284: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_808016A0_chgameselect(rdram, ctx);
        goto after_7;
    // 0x80804284: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80804288: lw          $a0, 0x28($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X28);
    // 0x8080428C: jal         0x808016E8
    // 0x80804290: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808016E8_chgameselect(rdram, ctx);
        goto after_8;
    // 0x80804290: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_8:
    // 0x80804294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804298: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080429C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808042A0: jr          $ra
    // 0x808042A4: nop

    return;
    // 0x808042A4: nop

;}
RECOMP_FUNC void idwater_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800040: jr          $ra
    // 0x80800044: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800044: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _bsdronebubbled_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083050: syscall     40
    recomp_syscall_handler(rdram, ctx, 0x80083050);
    return;
    // 0x80083054: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8010BFA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BFA4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8010BFA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8010BFAC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8010BFB0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8010BFB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010BFB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010BFBC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8010BFC0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010BFC4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8010BFC8: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x8010BFCC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8010BFD0: jal         0x800EFB24
    // 0x8010BFD4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x8010BFD4: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x8010BFD8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8010BFDC: jal         0x800F1EA4
    // 0x8010BFE0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_800F1EA4(rdram, ctx);
        goto after_1;
    // 0x8010BFE0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x8010BFE4: bne         $v0, $zero, L_8010C000
    if (ctx->r2 != 0) {
        // 0x8010BFE8: lw          $a2, 0x54($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X54);
            goto L_8010C000;
    }
    // 0x8010BFE8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8010BFEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010BFF0: jal         0x800EE7F8
    // 0x8010BFF4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_2;
    // 0x8010BFF4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x8010BFF8: b           L_8010C0EC
    // 0x8010BFFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010C0EC;
    // 0x8010BFFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010C000:
    // 0x8010C000: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8010C004: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8010C008: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8010C00C: jal         0x800F1DF4
    // 0x8010C010: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    func_800F1DF4(rdram, ctx);
        goto after_3;
    // 0x8010C010: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8010C014: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8010C018: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8010C01C: jal         0x800F1DCC
    // 0x8010C020: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    func_800F1DCC(rdram, ctx);
        goto after_4;
    // 0x8010C020: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    after_4:
    // 0x8010C024: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8010C028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010C02C: jal         0x800EE7F8
    // 0x8010C030: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    func_800EE7F8(rdram, ctx);
        goto after_5;
    // 0x8010C030: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_5:
    // 0x8010C034: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8010C038: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010C03C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8010C040: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010C044: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8010C048: add.s       $f8, $f20, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x8010C04C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010C050: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8010C054: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8010C058: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8010C05C: jal         0x800EF1B8
    // 0x8010C060: nop

    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x8010C060: nop

    after_6:
    // 0x8010C064: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8010C068: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8010C06C: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8010C070: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8010C074: nop

    // 0x8010C078: bc1fl       L_8010C094
    if (!c1cs) {
        // 0x8010C07C: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8010C094;
    }
    goto skip_0;
    // 0x8010C07C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8010C080: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8010C084: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010C088: b           L_8010C098
    // 0x8010C08C: nop

        goto L_8010C098;
    // 0x8010C08C: nop

    // 0x8010C090: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8010C094:
    // 0x8010C094: nop

L_8010C098:
    // 0x8010C098: jal         0x800136E4
    // 0x8010C09C: add.s       $f12, $f20, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f0.fl;
    func_800136E4(rdram, ctx);
        goto after_7;
    // 0x8010C09C: add.s       $f12, $f20, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f20.fl + ctx->f0.fl;
    after_7:
    // 0x8010C0A0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8010C0A4: jal         0x800EEF94
    // 0x8010C0A8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800EEF94(rdram, ctx);
        goto after_8;
    // 0x8010C0A8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_8:
    // 0x8010C0AC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8010C0B0: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8010C0B4: jal         0x800F1DCC
    // 0x8010C0B8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_800F1DCC(rdram, ctx);
        goto after_9;
    // 0x8010C0B8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_9:
    // 0x8010C0BC: jal         0x800138D0
    // 0x8010C0C0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_800138D0(rdram, ctx);
        goto after_10;
    // 0x8010C0C0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_10:
    // 0x8010C0C4: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010C0C8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010C0CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010C0D0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8010C0D4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8010C0D8: jal         0x800EF1B8
    // 0x8010C0DC: nop

    func_800EF1B8(rdram, ctx);
        goto after_11;
    // 0x8010C0DC: nop

    after_11:
    // 0x8010C0E0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8010C0E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010C0E8: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
L_8010C0EC:
    // 0x8010C0EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8010C0F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8010C0F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8010C0F8: jr          $ra
    // 0x8010C0FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8010C0FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80803148_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803148: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8080314C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80803150: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80803154: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80803158: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8080315C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80803160: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80803164: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80803168: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8080316C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80803170: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80803174: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80803178: jal         0x80100094
    // 0x8080317C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080317C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80803180: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1608, 0X52B0) << 16);
    // 0x80803184: addiu       $t7, $t7, 0x52B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1608, 0X52B0));
    // 0x80803188: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8080318C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80803190: addiu       $t6, $sp, 0x84
    ctx->r14 = ADD32(ctx->r29, 0X84);
    // 0x80803194: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80803198: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8080319C: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x808031A0: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x808031A4: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x808031A8: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x808031AC: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x808031B0: jal         0x80106790
    // 0x808031B4: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x808031B4: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    after_1:
    // 0x808031B8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x808031BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808031C0: jal         0x80100094
    // 0x808031C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_2;
    // 0x808031C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808031C8: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x808031CC: lhu         $v1, 0x72($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X72);
    // 0x808031D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x808031D4: srl         $t1, $v1, 10
    ctx->r9 = S32(U32(ctx->r3) >> 10);
    // 0x808031D8: beq         $t1, $at, L_808031E8
    if (ctx->r9 == ctx->r1) {
        // 0x808031DC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_808031E8;
    }
    // 0x808031DC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x808031E0: bnel        $t1, $at, L_8080350C
    if (ctx->r9 != ctx->r1) {
        // 0x808031E4: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8080350C;
    }
    goto skip_0;
    // 0x808031E4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
L_808031E8:
    // 0x808031E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808031EC: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    // 0x808031F0: addiu       $t4, $zero, 0x7F
    ctx->r12 = ADD32(0, 0X7F);
    // 0x808031F4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x808031F8: nop

    // 0x808031FC: bc1tl       L_8080321C
    if (c1cs) {
        // 0x80803200: sw          $t4, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r12;
            goto L_8080321C;
    }
    goto skip_1;
    // 0x80803200: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    skip_1:
    // 0x80803204: lhu         $t2, 0x72($s5)
    ctx->r10 = MEM_HU(ctx->r21, 0X72);
    // 0x80803208: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080320C: srl         $t3, $t2, 10
    ctx->r11 = S32(U32(ctx->r10) >> 10);
    // 0x80803210: bnel        $t3, $at, L_8080350C
    if (ctx->r11 != ctx->r1) {
        // 0x80803214: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8080350C;
    }
    goto skip_2;
    // 0x80803214: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x80803218: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
L_8080321C:
    // 0x8080321C: lbu         $t5, 0x3A($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X3A);
    // 0x80803220: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1608, 0X4F54) << 16);
    // 0x80803224: lwc1        $f22, 0x4F54($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1608, 0X4F54));
    // 0x80803228: blez        $t5, L_80803374
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8080322C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80803374;
    }
    // 0x8080322C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80803230: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80803234: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80803238: addiu       $s3, $sp, 0x64
    ctx->r19 = ADD32(ctx->r29, 0X64);
    // 0x8080323C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80803240: lhu         $t9, 0x72($s5)
    ctx->r25 = MEM_HU(ctx->r21, 0X72);
L_80803244:
    // 0x80803244: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80803248: srl         $t8, $t9, 10
    ctx->r24 = S32(U32(ctx->r25) >> 10);
    // 0x8080324C: bne         $a2, $t8, L_80803260
    if (ctx->r6 != ctx->r24) {
        // 0x80803250: nop
    
            goto L_80803260;
    }
    // 0x80803250: nop

    // 0x80803254: lbu         $t6, 0x20($s6)
    ctx->r14 = MEM_BU(ctx->r22, 0X20);
    // 0x80803258: beql        $s1, $t6, L_80803358
    if (ctx->r17 == ctx->r14) {
        // 0x8080325C: lw          $t9, 0x7C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X7C);
            goto L_80803358;
    }
    goto skip_3;
    // 0x8080325C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    skip_3:
L_80803260:
    // 0x80803260: jal         0x80089AF8
    // 0x80803264: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_3;
    // 0x80803264: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80803268: bne         $v0, $zero, L_80803354
    if (ctx->r2 != 0) {
        // 0x8080326C: lui         $t7, 0x8080
        ctx->r15 = S32(RELOC_HI16(1608, 0X52C0) << 16);
            goto L_80803354;
    }
    // 0x8080326C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1608, 0X52C0) << 16);
    // 0x80803270: addiu       $t7, $t7, 0x52C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1608, 0X52C0));
    // 0x80803274: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80803278: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080327C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80803280: sw          $at, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r1;
    // 0x80803284: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80803288: sw          $t1, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r9;
    // 0x8080328C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80803290: jal         0x80089AC8
    // 0x80803294: sw          $at, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r1;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_4;
    // 0x80803294: sw          $at, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r1;
    after_4:
    // 0x80803298: beq         $v0, $zero, L_80803304
    if (ctx->r2 == 0) {
        // 0x8080329C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80803304;
    }
    // 0x8080329C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808032A0: jal         0x800F6C5C
    // 0x808032A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F6C5C(rdram, ctx);
        goto after_5;
    // 0x808032A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x808032A8: beql        $v0, $zero, L_80803358
    if (ctx->r2 == 0) {
        // 0x808032AC: lw          $t9, 0x7C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X7C);
            goto L_80803358;
    }
    goto skip_4;
    // 0x808032AC: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    skip_4:
    // 0x808032B0: jal         0x800F5410
    // 0x808032B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800F5410(rdram, ctx);
        goto after_6;
    // 0x808032B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x808032B8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x808032BC: bne         $v0, $at, L_80803354
    if (ctx->r2 != ctx->r1) {
        // 0x808032C0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80803354;
    }
    // 0x808032C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808032C4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x808032C8: jal         0x800F5A00
    // 0x808032CC: addiu       $s2, $s5, 0x4
    ctx->r18 = ADD32(ctx->r21, 0X4);
    func_800F5A00(rdram, ctx);
        goto after_7;
    // 0x808032CC: addiu       $s2, $s5, 0x4
    ctx->r18 = ADD32(ctx->r21, 0X4);
    after_7:
    // 0x808032D0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x808032D4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808032D8: jal         0x800EFFB4
    // 0x808032DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFFB4(rdram, ctx);
        goto after_8;
    // 0x808032DC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_8:
    // 0x808032E0: beq         $v0, $zero, L_80803354
    if (ctx->r2 == 0) {
        // 0x808032E4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803354;
    }
    // 0x808032E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808032E8: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x808032EC: addiu       $t3, $sp, 0x84
    ctx->r11 = ADD32(ctx->r29, 0X84);
    // 0x808032F0: addu        $s0, $t2, $t3
    ctx->r16 = ADD32(ctx->r10, ctx->r11);
    // 0x808032F4: jal         0x800EEB40
    // 0x808032F8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_9;
    // 0x808032F8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_9:
    // 0x808032FC: b           L_80803354
    // 0x80803300: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
        goto L_80803354;
    // 0x80803300: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_80803304:
    // 0x80803304: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80803308: jal         0x80089AD8
    // 0x8080330C: addiu       $s2, $s5, 0x4
    ctx->r18 = ADD32(ctx->r21, 0X4);
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_10;
    // 0x8080330C: addiu       $s2, $s5, 0x4
    ctx->r18 = ADD32(ctx->r21, 0X4);
    after_10:
    // 0x80803310: jal         0x80106790
    // 0x80803314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_11;
    // 0x80803314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80803318: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8080331C: jal         0x800EE7F8
    // 0x80803320: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_12;
    // 0x80803320: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_12:
    // 0x80803324: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80803328: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080332C: jal         0x800EFFB4
    // 0x80803330: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFFB4(rdram, ctx);
        goto after_13;
    // 0x80803330: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_13:
    // 0x80803334: beq         $v0, $zero, L_80803354
    if (ctx->r2 == 0) {
        // 0x80803338: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80803354;
    }
    // 0x80803338: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8080333C: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80803340: addiu       $t5, $sp, 0x84
    ctx->r13 = ADD32(ctx->r29, 0X84);
    // 0x80803344: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x80803348: jal         0x800EEB40
    // 0x8080334C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EEB40(rdram, ctx);
        goto after_14;
    // 0x8080334C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_14:
    // 0x80803350: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_80803354:
    // 0x80803354: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
L_80803358:
    // 0x80803358: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8080335C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80803360: lbu         $t8, 0x3A($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X3A);
    // 0x80803364: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80803368: bnel        $at, $zero, L_80803244
    if (ctx->r1 != 0) {
        // 0x8080336C: lhu         $t9, 0x72($s5)
        ctx->r25 = MEM_HU(ctx->r21, 0X72);
            goto L_80803244;
    }
    goto skip_5;
    // 0x8080336C: lhu         $t9, 0x72($s5)
    ctx->r25 = MEM_HU(ctx->r21, 0X72);
    skip_5:
    // 0x80803370: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80803374:
    // 0x80803374: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80803378: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8080337C: lbu         $v0, 0x3A($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X3A);
    // 0x80803380: blezl       $v0, L_808033DC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80803384: lw          $t3, 0x74($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X74);
            goto L_808033DC;
    }
    goto skip_6;
    // 0x80803384: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    skip_6:
    // 0x80803388: lhu         $v1, 0x72($s5)
    ctx->r3 = MEM_HU(ctx->r21, 0X72);
    // 0x8080338C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80803390: srl         $t0, $v1, 10
    ctx->r8 = S32(U32(ctx->r3) >> 10);
    // 0x80803394: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_80803398:
    // 0x80803398: bne         $a2, $v1, L_808033A8
    if (ctx->r6 != ctx->r3) {
        // 0x8080339C: sll         $t1, $s1, 2
        ctx->r9 = S32(ctx->r17 << 2);
            goto L_808033A8;
    }
    // 0x8080339C: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x808033A0: lbu         $t7, 0x20($s6)
    ctx->r15 = MEM_BU(ctx->r22, 0X20);
    // 0x808033A4: beq         $s1, $t7, L_808033C8
    if (ctx->r17 == ctx->r15) {
        // 0x808033A8: addu        $t2, $a0, $t1
        ctx->r10 = ADD32(ctx->r4, ctx->r9);
            goto L_808033C8;
    }
L_808033A8:
    // 0x808033A8: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x808033AC: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x808033B0: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x808033B4: nop

    // 0x808033B8: bc1fl       L_808033CC
    if (!c1cs) {
        // 0x808033BC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_808033CC;
    }
    goto skip_7;
    // 0x808033BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x808033C0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x808033C4: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
L_808033C8:
    // 0x808033C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_808033CC:
    // 0x808033CC: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x808033D0: bne         $at, $zero, L_80803398
    if (ctx->r1 != 0) {
        // 0x808033D4: nop
    
            goto L_80803398;
    }
    // 0x808033D4: nop

    // 0x808033D8: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
L_808033DC:
    // 0x808033DC: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x808033E0: beql        $t3, $v0, L_8080350C
    if (ctx->r11 == ctx->r2) {
        // 0x808033E4: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8080350C;
    }
    goto skip_8;
    // 0x808033E4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_8:
    // 0x808033E8: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    // 0x808033EC: beql        $v0, $a1, L_80803430
    if (ctx->r2 == ctx->r5) {
        // 0x808033F0: lw          $t4, 0x74($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X74);
            goto L_80803430;
    }
    goto skip_9;
    // 0x808033F0: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    skip_9:
    // 0x808033F4: jal         0x80089AD0
    // 0x808033F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    _sukickball_entrypoint_7(rdram, ctx);
        goto after_15;
    // 0x808033F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_15:
    // 0x808033FC: beq         $v0, $zero, L_80803414
    if (ctx->r2 == 0) {
        // 0x80803400: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80803414;
    }
    // 0x80803400: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80803404: jal         0x80089AF0
    // 0x80803408: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_16;
    // 0x80803408: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    after_16:
    // 0x8080340C: b           L_80803430
    // 0x80803410: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
        goto L_80803430;
    // 0x80803410: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
L_80803414:
    // 0x80803414: lbu         $a0, 0x20($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X20);
    // 0x80803418: jal         0x800F4F98
    // 0x8080341C: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    func_800F4F98(rdram, ctx);
        goto after_17;
    // 0x8080341C: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    after_17:
    // 0x80803420: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80803424: jal         0x80089AF0
    // 0x80803428: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    _sukickball_entrypoint_11(rdram, ctx);
        goto after_18;
    // 0x80803428: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    after_18:
    // 0x8080342C: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
L_80803430:
    // 0x80803430: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80803434: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80803438: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8080343C: sb          $t4, 0x20($s6)
    MEM_B(0X20, ctx->r22) = ctx->r12;
    // 0x80803440: andi        $a1, $t4, 0xFF
    ctx->r5 = ctx->r12 & 0XFF;
    // 0x80803444: jal         0x80089AC8
    // 0x80803448: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    _sukickball_entrypoint_6(rdram, ctx);
        goto after_19;
    // 0x80803448: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    after_19:
    // 0x8080344C: beq         $v0, $zero, L_80803470
    if (ctx->r2 == 0) {
        // 0x80803450: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80803470;
    }
    // 0x80803450: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80803454: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80803458: addiu       $a2, $a2, 0x6A50
    ctx->r6 = ADD32(ctx->r6, 0X6A50);
    // 0x8080345C: lbu         $a0, 0x20($s6)
    ctx->r4 = MEM_BU(ctx->r22, 0X20);
    // 0x80803460: jal         0x800F4950
    // 0x80803464: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    func_800F4950(rdram, ctx);
        goto after_20;
    // 0x80803464: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    after_20:
    // 0x80803468: b           L_80803490
    // 0x8080346C: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
        goto L_80803490;
    // 0x8080346C: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
L_80803470:
    // 0x80803470: jal         0x80089AD8
    // 0x80803474: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    _sukickball_entrypoint_8(rdram, ctx);
        goto after_21;
    // 0x80803474: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    after_21:
    // 0x80803478: jal         0x80106790
    // 0x8080347C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80106790(rdram, ctx);
        goto after_22;
    // 0x8080347C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_22:
    // 0x80803480: lbu         $t5, 0x65($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X65);
    // 0x80803484: andi        $t9, $t5, 0xFFEF
    ctx->r25 = ctx->r13 & 0XFFEF;
    // 0x80803488: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
    // 0x8080348C: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
L_80803490:
    // 0x80803490: addiu       $at, $zero, 0x253
    ctx->r1 = ADD32(0, 0X253);
    // 0x80803494: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80803498: lw          $v0, 0x24($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X24);
    // 0x8080349C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808034A0: srl         $t6, $v0, 22
    ctx->r14 = S32(U32(ctx->r2) >> 22);
    // 0x808034A4: beq         $t6, $at, L_808034D4
    if (ctx->r14 == ctx->r1) {
        // 0x808034A8: addiu       $at, $zero, 0x254
        ctx->r1 = ADD32(0, 0X254);
            goto L_808034D4;
    }
    // 0x808034A8: addiu       $at, $zero, 0x254
    ctx->r1 = ADD32(0, 0X254);
    // 0x808034AC: beq         $t6, $at, L_808034E4
    if (ctx->r14 == ctx->r1) {
        // 0x808034B0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_808034E4;
    }
    // 0x808034B0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808034B4: addiu       $at, $zero, 0x267
    ctx->r1 = ADD32(0, 0X267);
    // 0x808034B8: bne         $t6, $at, L_808034F0
    if (ctx->r14 != ctx->r1) {
        // 0x808034BC: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_808034F0;
    }
    // 0x808034BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x808034C0: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    // 0x808034C4: jal         0x80089AE8
    // 0x808034C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    _sukickball_entrypoint_10(rdram, ctx);
        goto after_23;
    // 0x808034C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_23:
    // 0x808034CC: b           L_808034F4
    // 0x808034D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_808034F4;
    // 0x808034D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_808034D4:
    // 0x808034D4: jal         0x80089AE8
    // 0x808034D8: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    _sukickball_entrypoint_10(rdram, ctx);
        goto after_24;
    // 0x808034D8: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    after_24:
    // 0x808034DC: b           L_808034F4
    // 0x808034E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_808034F4;
    // 0x808034E0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_808034E4:
    // 0x808034E4: lbu         $a1, 0x20($s6)
    ctx->r5 = MEM_BU(ctx->r22, 0X20);
    // 0x808034E8: jal         0x80089AE8
    // 0x808034EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    _sukickball_entrypoint_10(rdram, ctx);
        goto after_25;
    // 0x808034EC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_25:
L_808034F0:
    // 0x808034F0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_808034F4:
    // 0x808034F4: jal         0x80801944
    // 0x808034F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80801944_chstoneballcontrol(rdram, ctx);
        goto after_26;
    // 0x808034F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_26:
    // 0x808034FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80803500: nop

    // 0x80803504: swc1        $f10, 0x24($s5)
    MEM_W(0X24, ctx->r21) = ctx->f10.u32l;
    // 0x80803508: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8080350C:
    // 0x8080350C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80803510: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80803514: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80803518: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8080351C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80803520: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80803524: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80803528: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8080352C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80803530: jr          $ra
    // 0x80803534: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80803534: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_80801414_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801414: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080141C: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    // 0x80801420: jal         0x80801294
    // 0x80801424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80801294_bstrexsmall(rdram, ctx);
        goto after_0;
    // 0x80801424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80801428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080142C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801430: jr          $ra
    // 0x80801434: nop

    return;
    // 0x80801434: nop

;}
RECOMP_FUNC void bsfirstp_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808000E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808000EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808000F0: beq         $a1, $zero, L_8080010C
    if (ctx->r5 == 0) {
        // 0x808000F4: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8080010C;
    }
    // 0x808000F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808000F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000FC: beq         $a1, $at, L_80800140
    if (ctx->r5 == ctx->r1) {
        // 0x80800100: nop
    
            goto L_80800140;
    }
    // 0x80800100: nop

    // 0x80800104: b           L_80800180
    // 0x80800108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800180;
    // 0x80800108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080010C:
    // 0x8080010C: jal         0x8008CABC
    // 0x80800110: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x80800110: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80800114: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800118: jal         0x80801000
    // 0x8080011C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80801000_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x8080011C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80800120: jal         0x8008B304
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B304(rdram, ctx);
        goto after_2;
    // 0x80800124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800128: jal         0x8008B4D4
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B4D4(rdram, ctx);
        goto after_3;
    // 0x8080012C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800130: jal         0x800DF41C
    // 0x80800134: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF41C(rdram, ctx);
        goto after_4;
    // 0x80800134: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80800138: b           L_80800180
    // 0x8080013C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800180;
    // 0x8080013C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800140:
    // 0x80800140: jal         0x8008D04C
    // 0x80800144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8008D04C(rdram, ctx);
        goto after_5;
    // 0x80800144: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x80800148: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8080014C: jal         0x80800864
    // 0x80800150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800864_bsfirstp(rdram, ctx);
        goto after_6;
    // 0x80800150: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800154: beq         $v0, $zero, L_80800164
    if (ctx->r2 == 0) {
        // 0x80800158: nop
    
            goto L_80800164;
    }
    // 0x80800158: nop

    // 0x8080015C: jal         0x80800F14
    // 0x80800160: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80800F14_bsfirstp(rdram, ctx);
        goto after_7;
    // 0x80800160: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_7:
L_80800164:
    // 0x80800164: jal         0x8008B304
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B304(rdram, ctx);
        goto after_8;
    // 0x80800168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080016C: jal         0x8008B4D4
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8008B4D4(rdram, ctx);
        goto after_9;
    // 0x80800170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800174: jal         0x800DF41C
    // 0x80800178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800DF41C(rdram, ctx);
        goto after_10;
    // 0x80800178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x8080017C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800180:
    // 0x80800180: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800184: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800188: jr          $ra
    // 0x8080018C: nop

    return;
    // 0x8080018C: nop

;}
RECOMP_FUNC void ncpod_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x808001C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808001C8: jal         0x808002B0
    // 0x808001CC: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    ncpod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808001CC: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    after_0:
    // 0x808001D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x808001D4: jal         0x800A940C
    // 0x808001D8: lw          $a0, 0x38($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X38);
    func_800A940C(rdram, ctx);
        goto after_1;
    // 0x808001D8: lw          $a0, 0x38($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X38);
    after_1:
    // 0x808001DC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x808005C0
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ncpod_entrypoint_12(rdram, ctx);
        goto after_2;
    // 0x808001E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x808001EC: lbu         $t6, 0x3E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X3E);
    // 0x808001F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001F4: beql        $t6, $zero, L_80800224
    if (ctx->r14 == 0) {
        // 0x808001F8: lw          $v0, 0x10($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X10);
            goto L_80800224;
    }
    goto skip_0;
    // 0x808001F8: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    skip_0:
    // 0x808001FC: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x80800200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800204: andi        $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 & 0X4000;
    // 0x80800208: beq         $t8, $zero, L_80800218
    if (ctx->r24 == 0) {
        // 0x8080020C: nop
    
            goto L_80800218;
    }
    // 0x8080020C: nop

    // 0x80800210: b           L_80800218
    // 0x80800214: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80800218;
    // 0x80800214: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80800218:
    // 0x80800218: jal         0x808008AC
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ncpod_entrypoint_15(rdram, ctx);
        goto after_3;
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800220: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
L_80800224:
    // 0x80800224: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x80800228: bne         $t9, $zero, L_80800284
    if (ctx->r25 != 0) {
        // 0x8080022C: sll         $t0, $v0, 12
        ctx->r8 = S32(ctx->r2 << 12);
            goto L_80800284;
    }
    // 0x8080022C: sll         $t0, $v0, 12
    ctx->r8 = S32(ctx->r2 << 12);
    // 0x80800230: bgez        $t0, L_80800244
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80800234: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_80800244;
    }
    // 0x80800234: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80800238: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080023C: b           L_8080024C
    // 0x80800240: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
        goto L_8080024C;
    // 0x80800240: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80800244:
    // 0x80800244: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80800248: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_8080024C:
    // 0x8080024C: jal         0x800C5148
    // 0x80800250: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800C5148(rdram, ctx);
        goto after_4;
    // 0x80800250: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80800254: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x80800258: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080025C: sll         $t2, $t1, 12
    ctx->r10 = S32(ctx->r9 << 12);
    // 0x80800260: bgezl       $t2, L_80800278
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800264: lwc1        $f0, 0x48($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
            goto L_80800278;
    }
    goto skip_1;
    // 0x80800264: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    skip_1:
    // 0x80800268: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8080026C: b           L_8080027C
    // 0x80800270: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
        goto L_8080027C;
    // 0x80800270: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80800274: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
L_80800278:
    // 0x80800278: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_8080027C:
    // 0x8080027C: jal         0x800C51A4
    // 0x80800280: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800C51A4(rdram, ctx);
        goto after_5;
    // 0x80800280: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
L_80800284:
    // 0x80800284: jal         0x80015178
    // 0x80800288: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    func_80015178(rdram, ctx);
        goto after_6;
    // 0x80800288: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    after_6:
    // 0x8080028C: jal         0x808000AC
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808000AC_ncpod(rdram, ctx);
        goto after_7;
    // 0x80800290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800294: jal         0x8001B754
    // 0x80800298: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    func_8001B754(rdram, ctx);
        goto after_8;
    // 0x80800298: lh          $a0, 0x2A($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X2A);
    after_8:
    // 0x8080029C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808002A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808002A8: jr          $ra
    // 0x808002AC: nop

    return;
    // 0x808002AC: nop

;}
RECOMP_FUNC void _cheggclockwork_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800871D0: syscall     534
    recomp_syscall_handler(rdram, ctx, 0x800871D0);
    return;
    // 0x800871D4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void func_80800B18_bsbeefly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800B1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800B20: jal         0x808002E4
    // 0x80800B24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_808002E4_bsbeefly(rdram, ctx);
        goto after_0;
    // 0x80800B24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800B28: jal         0x80082830
    // 0x80800B2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bsbee_entrypoint_0(rdram, ctx);
        goto after_1;
    // 0x80800B2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800B38: jr          $ra
    // 0x80800B3C: nop

    return;
    // 0x80800B3C: nop

;}
RECOMP_FUNC void func_800C878C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C878C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800C8790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8794: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800C8798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C879C: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x800C87A0: jal         0x800C8678
    // 0x800C87A4: lw          $a1, -0x5640($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5640);
    func_800C8678(rdram, ctx);
        goto after_0;
    // 0x800C87A4: lw          $a1, -0x5640($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5640);
    after_0:
    // 0x800C87A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C87AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C87B0: jr          $ra
    // 0x800C87B4: nop

    return;
    // 0x800C87B4: nop

;}
RECOMP_FUNC void func_800974FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800974FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80097500: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80097504: lw          $a0, 0x98($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X98);
    // 0x80097508: jal         0x800F1EA4
    // 0x8009750C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_800F1EA4(rdram, ctx);
        goto after_0;
    // 0x8009750C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x80097510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097514: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80097518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009751C: jr          $ra
    // 0x80097520: nop

    return;
    // 0x80097520: nop

;}
RECOMP_FUNC void func_800A4160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4160: jr          $ra
    // 0x800A4164: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800A4164: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void _bamoveledge_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084E58: syscall     139
    recomp_syscall_handler(rdram, ctx, 0x80084E58);
    return;
    // 0x80084E5C: xori        $t0, $zero, 0x0
    ctx->r8 = 0 ^ 0X0;
;}
RECOMP_FUNC void suegg_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800C80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800C84: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80800C88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800C8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80800C90: jal         0x80100094
    // 0x80800C94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800C94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800C98: jal         0x800BF8E4
    // 0x80800C9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    func_800BF8E4(rdram, ctx);
        goto after_1;
    // 0x80800C9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    after_1:
    // 0x80800CA0: blezl       $v0, L_80800CF4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80800CA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800CF4;
    }
    goto skip_0;
    // 0x80800CA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800CA8: jal         0x800C8A98
    // 0x80800CAC: nop

    func_800C8A98(rdram, ctx);
        goto after_2;
    // 0x80800CAC: nop

    after_2:
    // 0x80800CB0: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80800CB4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80800CB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800CBC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80800CC0: jal         0x800C8CB8
    // 0x80800CC4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800C8CB8(rdram, ctx);
        goto after_3;
    // 0x80800CC4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_3:
    // 0x80800CC8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800CCC: jal         0x800C8E84
    // 0x80800CD0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800C8E84(rdram, ctx);
        goto after_4;
    // 0x80800CD0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x80800CD4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80800CD8: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x80800CDC: jal         0x800C8E54
    // 0x80800CE0: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    func_800C8E54(rdram, ctx);
        goto after_5;
    // 0x80800CE0: lui         $a2, 0x43E1
    ctx->r6 = S32(0X43E1 << 16);
    after_5:
    // 0x80800CE4: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80800CE8: jal         0x800EE7F8
    // 0x80800CEC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800CEC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80800CF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800CF4:
    // 0x80800CF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800CF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800CFC: jr          $ra
    // 0x80800D00: nop

    return;
    // 0x80800D00: nop

;}
RECOMP_FUNC void _chtoothyfish_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086D90: syscall     451
    recomp_syscall_handler(rdram, ctx, 0x80086D90);
    return;
    // 0x80086D94: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800D20_chdragonbrothers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800D24: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80800D28: ori         $t7, $a2, 0x6
    ctx->r15 = ctx->r6 | 0X6;
    // 0x80800D2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800D30: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80800D34: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800D38: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80800D3C: lbu         $t8, 0x7A($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X7A);
    // 0x80800D40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800D44: lh          $a0, 0x36($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X36);
    // 0x80800D48: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80800D4C: beq         $t9, $zero, L_80800D5C
    if (ctx->r25 == 0) {
        // 0x80800D50: lw          $a1, 0x38($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X38);
            goto L_80800D5C;
    }
    // 0x80800D50: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80800D54: b           L_80800D60
    // 0x80800D58: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
        goto L_80800D60;
    // 0x80800D58: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
L_80800D5C:
    // 0x80800D5C: addiu       $v0, $zero, 0x76
    ctx->r2 = ADD32(0, 0X76);
L_80800D60:
    // 0x80800D60: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80800D64: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800D68: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80800D6C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800D70: jal         0x800C05B8
    // 0x80800D74: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    func_800C05B8(rdram, ctx);
        goto after_0;
    // 0x80800D74: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80800D78: lbu         $t1, 0x74($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X74);
    // 0x80800D7C: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x80800D80: sb          $t2, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r10;
    // 0x80800D84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80800D88: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80800D8C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800D90: jr          $ra
    // 0x80800D94: nop

    return;
    // 0x80800D94: nop

;}
RECOMP_FUNC void func_80090E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090E24: lw          $t6, 0x2C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2C);
    // 0x80090E28: jr          $ra
    // 0x80090E2C: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    return;
    // 0x80090E2C: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
;}
RECOMP_FUNC void func_80801118_chglowbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080111C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801120: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80801124: jal         0x80089C90
    // 0x80801128: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    _subaddiefade_entrypoint_0(rdram, ctx);
        goto after_0;
    // 0x80801128: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080112C: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x80801130: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80801134: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80801138: jal         0x800DF5D8
    // 0x8080113C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_800DF5D8(rdram, ctx);
        goto after_1;
    // 0x8080113C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_1:
    // 0x80801140: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80801144: jal         0x80101870
    // 0x80801148: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80101870(rdram, ctx);
        goto after_2;
    // 0x80801148: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8080114C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801154: jr          $ra
    // 0x80801158: nop

    return;
    // 0x80801158: nop

;}
RECOMP_FUNC void func_80800728_chjadesnake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800728: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080072C: addiu       $at, $zero, 0xF3C
    ctx->r1 = ADD32(0, 0XF3C);
    // 0x80800730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800734: beq         $a1, $at, L_80800758
    if (ctx->r5 == ctx->r1) {
        // 0x80800738: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_80800758;
    }
    // 0x80800738: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8080073C: addiu       $at, $zero, 0xF3D
    ctx->r1 = ADD32(0, 0XF3D);
    // 0x80800740: bnel        $a1, $at, L_80800764
    if (ctx->r5 != ctx->r1) {
        // 0x80800744: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800764;
    }
    goto skip_0;
    // 0x80800744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80800748: jal         0x80102424
    // 0x8080074C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80102424(rdram, ctx);
        goto after_0;
    // 0x8080074C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80800750: b           L_80800764
    // 0x80800754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800764;
    // 0x80800754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800758:
    // 0x80800758: jal         0x80102424
    // 0x8080075C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80102424(rdram, ctx);
        goto after_1;
    // 0x8080075C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80800760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800764:
    // 0x80800764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800768: jr          $ra
    // 0x8080076C: nop

    return;
    // 0x8080076C: nop

;}
RECOMP_FUNC void func_80800000_chmole_mine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1600, 0XC0) << 16);
    // 0x8080000C: jal         0x800899E8
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1600, 0XC0));
    _sumole_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800010: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1600, 0XC0));
    after_0:
    // 0x80800014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080001C: jr          $ra
    // 0x80800020: nop

    return;
    // 0x80800020: nop

;}
RECOMP_FUNC void func_800C7338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7338: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C733C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7340: jal         0x80088290
    // 0x800C7344: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    _gccubesearch_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x800C7344: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x800C7348: beq         $v0, $zero, L_800C7358
    if (ctx->r2 == 0) {
        // 0x800C734C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C7358;
    }
    // 0x800C734C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7350: b           L_800C735C
    // 0x800C7354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800C735C;
    // 0x800C7354: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C7358:
    // 0x800C7358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C735C:
    // 0x800C735C: jr          $ra
    // 0x800C7360: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C7360: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8010E810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E810: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010E814: jr          $ra
    // 0x8010E818: addiu       $v0, $v0, 0x7080
    ctx->r2 = ADD32(ctx->r2, 0X7080);
    return;
    // 0x8010E818: addiu       $v0, $v0, 0x7080
    ctx->r2 = ADD32(ctx->r2, 0X7080);
;}
RECOMP_FUNC void func_808027E4_chboilerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808027E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808027E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808027EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808027F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808027F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808027F8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808027FC: jal         0x80100094
    // 0x80802800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80802800: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80802804: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80802808: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8080280C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80802810: bne         $t6, $zero, L_80802820
    if (ctx->r14 != 0) {
        // 0x80802814: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_80802820;
    }
    // 0x80802814: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80802818: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8080281C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_80802820:
    // 0x80802820: lbu         $v1, 0x59($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X59);
    // 0x80802824: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802828: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8080282C: beql        $v1, $zero, L_80802850
    if (ctx->r3 == 0) {
        // 0x80802830: lw          $a0, 0x0($t0)
        ctx->r4 = MEM_W(ctx->r8, 0X0);
            goto L_80802850;
    }
    goto skip_0;
    // 0x80802830: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x80802834: beq         $v1, $at, L_80802864
    if (ctx->r3 == ctx->r1) {
        // 0x80802838: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802864;
    }
    // 0x80802838: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080283C: beql        $v1, $at, L_80802860
    if (ctx->r3 == ctx->r1) {
        // 0x80802840: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80802860;
    }
    goto skip_1;
    // 0x80802840: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    skip_1:
    // 0x80802844: b           L_80802878
    // 0x80802848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80802878;
    // 0x80802848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080284C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
L_80802850:
    // 0x80802850: jal         0x800856B0
    // 0x80802854: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    _capod_entrypoint_2(rdram, ctx);
        goto after_1;
    // 0x80802854: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80802858: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8080285C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_80802860:
    // 0x80802860: sb          $t8, 0x59($a3)
    MEM_B(0X59, ctx->r7) = ctx->r24;
L_80802864:
    // 0x80802864: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80802868: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080286C: jal         0x800856D0
    // 0x80802870: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    _capod_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80802870: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80802874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802878:
    // 0x80802878: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080287C: jr          $ra
    // 0x80802880: nop

    return;
    // 0x80802880: nop

    // 0x80802884: nop

    // 0x80802888: nop

    // 0x8080288C: nop

;}
RECOMP_FUNC void func_8080001C_chjiggybeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080001C: jr          $ra
    // 0x80800020: nop

    return;
    // 0x80800020: nop

;}
RECOMP_FUNC void _bskazow_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083510: syscall     64
    recomp_syscall_handler(rdram, ctx, 0x80083510);
    return;
    // 0x80083514: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void _bssplitup_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083AC0: syscall     89
    recomp_syscall_handler(rdram, ctx, 0x80083AC0);
    return;
    // 0x80083AC4: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800F2F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F2F20: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800F2F24: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800F2F28: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800F2F2C: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x800F2F30: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800F2F34: jr          $ra
    // 0x800F2F38: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
    return;
    // 0x800F2F38: sb          $t8, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void bskazstilt_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808007FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800800: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80800804: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800808: jal         0x8008CABC
    // 0x8080080C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_0;
    // 0x8080080C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x80800810: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800814: jal         0x8008AF24
    // 0x80800818: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    anctrl_reset(rdram, ctx);
        goto after_1;
    // 0x80800818: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8080081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800820: jal         0x8008B1A0
    // 0x80800824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    anctrl_setSmoothTransition(rdram, ctx);
        goto after_2;
    // 0x80800824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: jal         0x8008B188
    // 0x80800830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8008B188(rdram, ctx);
        goto after_3;
    // 0x80800830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800838: jal         0x8008AED4
    // 0x8080083C: addiu       $a1, $zero, 0x27F
    ctx->r5 = ADD32(0, 0X27F);
    anctrl_setIndex(rdram, ctx);
        goto after_4;
    // 0x8080083C: addiu       $a1, $zero, 0x27F
    ctx->r5 = ADD32(0, 0X27F);
    after_4:
    // 0x80800840: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80800844: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80800848: jal         0x8008B1BC
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_setDuration(rdram, ctx);
        goto after_5;
    // 0x8080084C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800854: jal         0x8008B134
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_6;
    // 0x80800858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x8080085C: jal         0x8008B064
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    anctrl_start(rdram, ctx);
        goto after_7;
    // 0x80800860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800864: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80800868: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080086C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800874: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800878: jal         0x8009FFD8
    // 0x8080087C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_8009FFD8(rdram, ctx);
        goto after_8;
    // 0x8080087C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_8:
    // 0x80800880: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800884: jal         0x8009B9B0
    // 0x80800888: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_9;
    // 0x80800888: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_9:
    // 0x8080088C: jal         0x800C2E04
    // 0x80800890: nop

    func_800C2E04(rdram, ctx);
        goto after_10;
    // 0x80800890: nop

    after_10:
    // 0x80800894: sb          $v0, 0x160($s1)
    MEM_B(0X160, ctx->r17) = ctx->r2;
    // 0x80800898: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8080089C: jal         0x800C301C
    // 0x808008A0: addiu       $a1, $zero, 0x41D
    ctx->r5 = ADD32(0, 0X41D);
    func_800C301C(rdram, ctx);
        goto after_11;
    // 0x808008A0: addiu       $a1, $zero, 0x41D
    ctx->r5 = ADD32(0, 0X41D);
    after_11:
    // 0x808008A4: lbu         $a0, 0x160($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X160);
    // 0x808008A8: jal         0x800C330C
    // 0x808008AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_800C330C(rdram, ctx);
        goto after_12;
    // 0x808008AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_12:
    // 0x808008B0: lui         $a1, 0x3FB3
    ctx->r5 = S32(0X3FB3 << 16);
    // 0x808008B4: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x808008B8: lui         $a3, 0xBF99
    ctx->r7 = S32(0XBF99 << 16);
    // 0x808008BC: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808008C0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x808008C4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x808008C8: jal         0x800C3730
    // 0x808008CC: lbu         $a0, 0x160($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X160);
    func_800C3730(rdram, ctx);
        goto after_13;
    // 0x808008CC: lbu         $a0, 0x160($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X160);
    after_13:
    // 0x808008D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808008D4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808008D8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x808008DC: jr          $ra
    // 0x808008E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x808008E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80809078_chdiggerboss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80809078: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080907C: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80809080: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80809084: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80809088: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8080908C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80809090: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80809094: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80809098: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8080909C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x808090A0: jal         0x80100094
    // 0x808090A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808090A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808090A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808090AC: lui         $s0, 0x8081
    ctx->r16 = S32(RELOC_HI16(1480, 0XA1F4) << 16);
    // 0x808090B0: lui         $s3, 0x8081
    ctx->r19 = S32(RELOC_HI16(1480, 0XA1FA) << 16);
    // 0x808090B4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x808090B8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x808090BC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808090C0: addiu       $s3, $s3, -0x5E06
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1480, 0XA1FA));
    // 0x808090C4: addiu       $s0, $s0, -0x5E0C
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1480, 0XA1F4));
    // 0x808090C8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
L_808090CC:
    // 0x808090CC: lw          $a3, 0xC0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC0);
    // 0x808090D0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x808090D4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x808090D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x808090DC: jal         0x800E0AFC
    // 0x808090E0: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    func_800E0AFC(rdram, ctx);
        goto after_1;
    // 0x808090E0: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    after_1:
    // 0x808090E4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x808090E8: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x808090EC: bnel        $at, $zero, L_808090CC
    if (ctx->r1 != 0) {
        // 0x808090F0: mfc1        $a2, $f22
        ctx->r6 = (int32_t)ctx->f22.u32l;
            goto L_808090CC;
    }
    goto skip_0;
    // 0x808090F0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    skip_0:
    // 0x808090F4: lui         $s0, 0x8081
    ctx->r16 = S32(RELOC_HI16(1480, 0XA1FC) << 16);
    // 0x808090F8: lui         $s3, 0x8081
    ctx->r19 = S32(RELOC_HI16(1480, 0XA202) << 16);
    // 0x808090FC: addiu       $s3, $s3, -0x5DFE
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(1480, 0XA202));
    // 0x80809100: addiu       $s0, $s0, -0x5E04
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1480, 0XA1FC));
    // 0x80809104: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
L_80809108:
    // 0x80809108: lw          $a3, 0xC4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC4);
    // 0x8080910C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80809110: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80809114: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80809118: jal         0x800E0AFC
    // 0x8080911C: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    func_800E0AFC(rdram, ctx);
        goto after_2;
    // 0x8080911C: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    after_2:
    // 0x80809120: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80809124: bnel        $s0, $s3, L_80809108
    if (ctx->r16 != ctx->r19) {
        // 0x80809128: mfc1        $a2, $f22
        ctx->r6 = (int32_t)ctx->f22.u32l;
            goto L_80809108;
    }
    goto skip_1;
    // 0x80809128: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    skip_1:
    // 0x8080912C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80809130: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80809134: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80809138: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8080913C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80809140: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x80809144: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80809148: jr          $ra
    // 0x8080914C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8080914C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void _chbigterrysbits_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FE8: syscall     269
    recomp_syscall_handler(rdram, ctx, 0x80085FE8);
    return;
    // 0x80085FEC: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_80800888_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800888: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080088C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800890: lw          $v0, 0x188($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X188);
    // 0x80800894: sw          $a1, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->r5;
    // 0x80800898: jal         0x80800900
    // 0x8080089C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80800900_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080089C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_0:
    // 0x808008A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808008A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008A8: jr          $ra
    // 0x808008AC: nop

    return;
    // 0x808008AC: nop

;}
RECOMP_FUNC void badata_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DC0: jal         0x80800000
    // 0x80800DC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800000_badata(rdram, ctx);
        goto after_0;
    // 0x80800DC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800DC8: jal         0x80800000
    // 0x80800DCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_badata(rdram, ctx);
        goto after_1;
    // 0x80800DCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800DD0: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80800DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DD8: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(473, 0X1448) << 16);
    // 0x80800DDC: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800DE0: lh          $v0, 0x1448($v0)
    ctx->r2 = MEM_H(ctx->r2, (int16_t)RELOC_LO16(473, 0X1448));
    // 0x80800DE4: jr          $ra
    // 0x80800DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void chlagoonpirate_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1164, 0XF8) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0xF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1164, 0XF8));
    return;
    // 0x80800008: addiu       $v0, $v0, 0xF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1164, 0XF8));
;}
RECOMP_FUNC void func_80800038_chstatuebossbits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800038: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8080003C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800040: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800044: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800048: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080004C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800050: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x80800054: beq         $t6, $at, L_80800070
    if (ctx->r14 == ctx->r1) {
        // 0x80800058: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80800070;
    }
    // 0x80800058: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8080005C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800060: beq         $t6, $at, L_80800198
    if (ctx->r14 == ctx->r1) {
        // 0x80800064: nop
    
            goto L_80800198;
    }
    // 0x80800064: nop

    // 0x80800068: b           L_80800214
    // 0x8080006C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800214;
    // 0x8080006C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800070:
    // 0x80800070: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80800074: addiu       $a0, $a0, -0x6048
    ctx->r4 = ADD32(ctx->r4, -0X6048);
    // 0x80800078: jal         0x800EA600
    // 0x8080007C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_800EA600(rdram, ctx);
        goto after_0;
    // 0x8080007C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x80800080: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    // 0x80800084: ori         $a1, $a1, 0x5
    ctx->r5 = ctx->r5 | 0X5;
    // 0x80800088: jal         0x8010B990
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_1;
    // 0x8080008C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800090: jal         0x800EA614
    // 0x80800094: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800EA614(rdram, ctx);
        goto after_2;
    // 0x80800094: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80800098: jal         0x800D8FF8
    // 0x8080009C: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x8080009C: nop

    after_3:
    // 0x808000A0: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x808000A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808000A8: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x808000AC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x808000B0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808000B4: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x808000B8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x808000BC: beql        $t7, $zero, L_80800214
    if (ctx->r15 == 0) {
        // 0x808000C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800214;
    }
    goto skip_0;
    // 0x808000C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x808000C4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x808000C8: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x808000CC: beql        $a0, $zero, L_80800124
    if (ctx->r4 == 0) {
        // 0x808000D0: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80800124;
    }
    goto skip_1;
    // 0x808000D0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_1:
    // 0x808000D4: jal         0x80106790
    // 0x808000D8: nop

    func_80106790(rdram, ctx);
        goto after_4;
    // 0x808000D8: nop

    after_4:
    // 0x808000DC: lw          $t8, 0x6C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X6C);
    // 0x808000E0: addiu       $at, $zero, 0x449
    ctx->r1 = ADD32(0, 0X449);
    // 0x808000E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808000E8: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x808000EC: srl         $t0, $t9, 20
    ctx->r8 = S32(U32(ctx->r25) >> 20);
    // 0x808000F0: bne         $t0, $at, L_80800120
    if (ctx->r8 != ctx->r1) {
        // 0x808000F4: addiu       $a1, $zero, 0x40
        ctx->r5 = ADD32(0, 0X40);
            goto L_80800120;
    }
    // 0x808000F4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x808000F8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x808000FC: jal         0x8010108C
    // 0x80800100: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_8010108C(rdram, ctx);
        goto after_5;
    // 0x80800100: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_5:
    // 0x80800104: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800108: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8080010C: lw          $t1, 0x54($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X54);
    // 0x80800110: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80800114: bnel        $at, $zero, L_80800124
    if (ctx->r1 != 0) {
        // 0x80800118: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80800124;
    }
    goto skip_2;
    // 0x80800118: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_2:
    // 0x8080011C: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
L_80800120:
    // 0x80800120: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80800124:
    // 0x80800124: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800128: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080012C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800130: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80800134: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80800138: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080013C: jal         0x800EF1B8
    // 0x80800140: nop

    func_800EF1B8(rdram, ctx);
        goto after_6;
    // 0x80800140: nop

    after_6:
    // 0x80800144: jal         0x80800270
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800270_chstatuebossbits(rdram, ctx);
        goto after_7;
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080014C: jal         0x8010A570
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_8;
    // 0x80800150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80800154: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80800158: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8080015C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800160: beq         $t3, $zero, L_80800180
    if (ctx->r11 == 0) {
        // 0x80800164: nop
    
            goto L_80800180;
    }
    // 0x80800164: nop

    // 0x80800168: jal         0x80101FDC
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101FDC(rdram, ctx);
        goto after_9;
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80800170: jal         0x80089CA8
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_10;
    // 0x80800174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80800178: b           L_80800214
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800214;
    // 0x8080017C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800180:
    // 0x80800180: jal         0x80101FDC
    // 0x80800184: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80800184: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80800188: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1424, 0X6E0) << 16);
    // 0x8080018C: lwc1        $f4, 0x6E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1424, 0X6E0));
    // 0x80800190: b           L_80800210
    // 0x80800194: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800210;
    // 0x80800194: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800198:
    // 0x80800198: jal         0x800D9078
    // 0x8080019C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    func_800D9078(rdram, ctx);
        goto after_12;
    // 0x8080019C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    after_12:
    // 0x808001A0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x808001A4: jal         0x8001210C
    // 0x808001A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8001210C(rdram, ctx);
        goto after_13;
    // 0x808001A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x808001AC: beq         $v0, $zero, L_808001BC
    if (ctx->r2 == 0) {
        // 0x808001B0: lui         $a2, 0x3FB3
        ctx->r6 = S32(0X3FB3 << 16);
            goto L_808001BC;
    }
    // 0x808001B0: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x808001B4: b           L_808001C0
    // 0x808001B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_808001C0;
    // 0x808001B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_808001BC:
    // 0x808001BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001C0:
    // 0x808001C0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x808001C4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x808001C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808001CC: lwc1        $f12, 0x58($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X58);
    // 0x808001D0: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x808001D4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808001D8: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808001DC: jal         0x800F10B4
    // 0x808001E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_800F10B4(rdram, ctx);
        goto after_14;
    // 0x808001E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_14:
    // 0x808001E4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x808001E8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x808001EC: nop

    // 0x808001F0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x808001F4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808001F8: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x808001FC: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80800200: beql        $t4, $zero, L_80800214
    if (ctx->r12 == 0) {
        // 0x80800204: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80800214;
    }
    goto skip_3;
    // 0x80800204: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80800208: jal         0x80089CA8
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddiefade_entrypoint_3(rdram, ctx);
        goto after_15;
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_80800210:
    // 0x80800210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800214:
    // 0x80800214: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800218: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8080021C: jr          $ra
    // 0x80800220: nop

    return;
    // 0x80800220: nop

;}
RECOMP_FUNC void func_80801600_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801600: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80801604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801608: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080160C: lbu         $t6, 0x90($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X90);
    // 0x80801610: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801614: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80801618: beq         $t6, $zero, L_808016E4
    if (ctx->r14 == 0) {
        // 0x8080161C: nop
    
            goto L_808016E4;
    }
    // 0x8080161C: nop

    // 0x80801620: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80801624: jal         0x800D9004
    // 0x80801628: swc1        $f4, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f4.u32l;
    func_800D9004(rdram, ctx);
        goto after_0;
    // 0x80801628: swc1        $f4, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x8080162C: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80801630: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80801634: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80801638: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8080163C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80801640: addiu       $a0, $zero, 0x4D5
    ctx->r4 = ADD32(0, 0X4D5);
    // 0x80801644: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80801648: swc1        $f8, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f8.u32l;
    // 0x8080164C: lwc1        $f16, 0x84($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80801650: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80801654: nop

    // 0x80801658: bc1f        L_80801664
    if (!c1cs) {
        // 0x8080165C: nop
    
            goto L_80801664;
    }
    // 0x8080165C: nop

    // 0x80801660: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80801664:
    // 0x80801664: bne         $t7, $zero, L_808016B8
    if (ctx->r15 != 0) {
        // 0x80801668: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_808016B8;
    }
    // 0x80801668: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8080166C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801670: jal         0x800F13C4
    // 0x80801674: lwc1        $f12, 0x88($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X88);
    func_800F13C4(rdram, ctx);
        goto after_1;
    // 0x80801674: lwc1        $f12, 0x88($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X88);
    after_1:
    // 0x80801678: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8080167C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80801680: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80801684: jal         0x800F13C4
    // 0x80801688: lwc1        $f12, 0x84($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X84);
    func_800F13C4(rdram, ctx);
        goto after_2;
    // 0x80801688: lwc1        $f12, 0x84($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X84);
    after_2:
    // 0x8080168C: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80801690: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80801694: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80801698: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8080169C: addiu       $a0, $zero, 0x3E9
    ctx->r4 = ADD32(0, 0X3E9);
    // 0x808016A0: bc1fl       L_808016C4
    if (!c1cs) {
        // 0x808016A4: lwc1        $f4, 0x84($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
            goto L_808016C4;
    }
    goto skip_0;
    // 0x808016A4: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    skip_0:
    // 0x808016A8: jal         0x800C3FC0
    // 0x808016AC: addiu       $a2, $zero, 0x7D00
    ctx->r6 = ADD32(0, 0X7D00);
    func_800C3FC0(rdram, ctx);
        goto after_3;
    // 0x808016AC: addiu       $a2, $zero, 0x7D00
    ctx->r6 = ADD32(0, 0X7D00);
    after_3:
    // 0x808016B0: b           L_808016C4
    // 0x808016B4: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
        goto L_808016C4;
    // 0x808016B4: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
L_808016B8:
    // 0x808016B8: jal         0x800C3FC0
    // 0x808016BC: addiu       $a2, $zero, 0x2710
    ctx->r6 = ADD32(0, 0X2710);
    func_800C3FC0(rdram, ctx);
        goto after_4;
    // 0x808016BC: addiu       $a2, $zero, 0x2710
    ctx->r6 = ADD32(0, 0X2710);
    after_4:
    // 0x808016C0: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
L_808016C4:
    // 0x808016C4: addiu       $a0, $zero, 0x116
    ctx->r4 = ADD32(0, 0X116);
    // 0x808016C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808016CC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x808016D0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x808016D4: jal         0x800D2498
    // 0x808016D8: nop

    func_800D2498(rdram, ctx);
        goto after_5;
    // 0x808016D8: nop

    after_5:
    // 0x808016DC: b           L_808016E4
    // 0x808016E0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
        goto L_808016E4;
    // 0x808016E0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_808016E4:
    // 0x808016E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808016E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808016EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808016F0: jr          $ra
    // 0x808016F4: nop

    return;
    // 0x808016F4: nop

;}
RECOMP_FUNC void func_80093E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093E18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80093E1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80093E20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80093E24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80093E28: jal         0x800A89F8
    // 0x80093E2C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_800A89F8(rdram, ctx);
        goto after_0;
    // 0x80093E2C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80093E30: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80093E34: jal         0x800A5090
    // 0x80093E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800A5090(rdram, ctx);
        goto after_1;
    // 0x80093E38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80093E3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80093E40: jal         0x800A88C4
    // 0x80093E44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800A88C4(rdram, ctx);
        goto after_2;
    // 0x80093E44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80093E48: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80093E4C: jal         0x800E44FC
    // 0x80093E50: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800E44FC(rdram, ctx);
        goto after_3;
    // 0x80093E50: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_3:
    // 0x80093E54: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x80093E58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093E5C: lbu         $t7, 0xA1($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0XA1);
    // 0x80093E60: bnel        $t7, $zero, L_80093E98
    if (ctx->r15 != 0) {
        // 0x80093E64: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80093E98;
    }
    goto skip_0;
    // 0x80093E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80093E68: jal         0x80084290
    // 0x80093E6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _bsfirstp_entrypoint_1(rdram, ctx);
        goto after_4;
    // 0x80093E6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80093E70: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x80093E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093E78: addiu       $a1, $v0, 0xAC
    ctx->r5 = ADD32(ctx->r2, 0XAC);
    // 0x80093E7C: jal         0x80084288
    // 0x80093E80: addiu       $a2, $v0, 0xB8
    ctx->r6 = ADD32(ctx->r2, 0XB8);
    _bsfirstp_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x80093E80: addiu       $a2, $v0, 0xB8
    ctx->r6 = ADD32(ctx->r2, 0XB8);
    after_5:
    // 0x80093E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80093E88: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80093E8C: jal         0x8009375C
    // 0x80093E90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8009375C(rdram, ctx);
        goto after_6;
    // 0x80093E90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80093E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80093E98:
    // 0x80093E98: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80093E9C: jal         0x80093864
    // 0x80093EA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80093864(rdram, ctx);
        goto after_7;
    // 0x80093EA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80093EA4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80093EA8: jal         0x800A88C4
    // 0x80093EAC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800A88C4(rdram, ctx);
        goto after_8;
    // 0x80093EAC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x80093EB0: jal         0x800E44FC
    // 0x80093EB4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800E44FC(rdram, ctx);
        goto after_9;
    // 0x80093EB4: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_9:
    // 0x80093EB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80093EBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80093EC0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80093EC4: jr          $ra
    // 0x80093EC8: nop

    return;
    // 0x80093EC8: nop

;}
RECOMP_FUNC void func_808003DC_chtorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808003DC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x808003E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808003E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808003E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808003EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808003F0: jal         0x80100094
    // 0x808003F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808003F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808003F8: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x808003FC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800400: jal         0x800D8FF8
    // 0x80800404: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    func_800D8FF8(rdram, ctx);
        goto after_1;
    // 0x80800404: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80800408: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8080040C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    // 0x80800410: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800418: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080041C: beq         $t6, $at, L_8080043C
    if (ctx->r14 == ctx->r1) {
        // 0x80800420: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8080043C;
    }
    // 0x80800420: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800424: beq         $t6, $at, L_80800550
    if (ctx->r14 == ctx->r1) {
        // 0x80800428: addiu       $t7, $s0, 0x4
        ctx->r15 = ADD32(ctx->r16, 0X4);
            goto L_80800550;
    }
    // 0x80800428: addiu       $t7, $s0, 0x4
    ctx->r15 = ADD32(ctx->r16, 0X4);
    // 0x8080042C: addiu       $t8, $s1, 0x14
    ctx->r24 = ADD32(ctx->r17, 0X14);
    // 0x80800430: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80800434: b           L_80800568
    // 0x80800438: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_80800568;
    // 0x80800438: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_8080043C:
    // 0x8080043C: jal         0x8008A798
    // 0x80800440: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _sumissilehome_entrypoint_6(rdram, ctx);
        goto after_2;
    // 0x80800440: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80800444: lui         $a1, 0x10
    ctx->r5 = S32(0X10 << 16);
    // 0x80800448: ori         $a1, $a1, 0x4
    ctx->r5 = ctx->r5 | 0X4;
    // 0x8080044C: jal         0x8010B990
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010B990(rdram, ctx);
        goto after_3;
    // 0x80800450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800454: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80800458: bne         $v0, $at, L_80800468
    if (ctx->r2 != ctx->r1) {
        // 0x8080045C: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_80800468;
    }
    // 0x8080045C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800460: jal         0x8010AA78
    // 0x80800464: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_8010AA78(rdram, ctx);
        goto after_4;
    // 0x80800464: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_4:
L_80800468:
    // 0x80800468: addiu       $t9, $s0, 0x4
    ctx->r25 = ADD32(ctx->r16, 0X4);
    // 0x8080046C: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80800470: jal         0x80800350
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800350_chtorpedo(rdram, ctx);
        goto after_5;
    // 0x80800474: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800478: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x8080047C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800480: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800484: lwc1        $f16, 0x4C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80800488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080048C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800490: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800494: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80800498: jal         0x80800000
    // 0x8080049C: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    func_80800000_chtorpedo(rdram, ctx);
        goto after_6;
    // 0x8080049C: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    after_6:
    // 0x808004A0: jal         0x8010A590
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A590(rdram, ctx);
        goto after_7;
    // 0x808004A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x808004A8: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x808004AC: jal         0x800CB840
    // 0x808004B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800CB840(rdram, ctx);
        goto after_8;
    // 0x808004B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x808004B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x808004B8: addiu       $a1, $s1, 0x14
    ctx->r5 = ADD32(ctx->r17, 0X14);
    // 0x808004BC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x808004C0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808004C4: jal         0x800CD820
    // 0x808004C8: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_800CD820(rdram, ctx);
        goto after_9;
    // 0x808004C8: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_9:
    // 0x808004CC: jal         0x800CB870
    // 0x808004D0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_800CB870(rdram, ctx);
        goto after_10;
    // 0x808004D0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_10:
    // 0x808004D4: jal         0x8010A570
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8010A570(rdram, ctx);
        goto after_11;
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x808004DC: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x808004E0: lb          $a3, 0x0($s1)
    ctx->r7 = MEM_B(ctx->r17, 0X0);
    // 0x808004E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808004E8: sltu        $t0, $zero, $v1
    ctx->r8 = 0 < ctx->r3 ? 1 : 0;
    // 0x808004EC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x808004F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808004F4: jal         0x8010D350
    // 0x808004F8: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    func_8010D350(rdram, ctx);
        goto after_12;
    // 0x808004F8: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_12:
    // 0x808004FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80800500: beq         $v0, $at, L_8080050C
    if (ctx->r2 == ctx->r1) {
        // 0x80800504: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_8080050C;
    }
    // 0x80800504: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80800508: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8080050C:
    // 0x8080050C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80800510: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80800514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800518: beq         $t1, $at, L_80800540
    if (ctx->r9 == ctx->r1) {
        // 0x8080051C: nop
    
            goto L_80800540;
    }
    // 0x8080051C: nop

    // 0x80800520: bne         $v1, $zero, L_80800540
    if (ctx->r3 != 0) {
        // 0x80800524: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80800540;
    }
    // 0x80800524: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80800528: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8080052C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80800530: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80800534: nop

    // 0x80800538: bc1fl       L_8080056C
    if (!c1cs) {
        // 0x8080053C: lwc1        $f8, 0x44($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
            goto L_8080056C;
    }
    goto skip_0;
    // 0x8080053C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    skip_0:
L_80800540:
    // 0x80800540: jal         0x808001E0
    // 0x80800544: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_808001E0_chtorpedo(rdram, ctx);
        goto after_13;
    // 0x80800544: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_13:
    // 0x80800548: b           L_8080056C
    // 0x8080054C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
        goto L_8080056C;
    // 0x8080054C: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
L_80800550:
    // 0x80800550: jal         0x800FFAB0
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_14;
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80800558: addiu       $t2, $s0, 0x4
    ctx->r10 = ADD32(ctx->r16, 0X4);
    // 0x8080055C: addiu       $t3, $s1, 0x14
    ctx->r11 = ADD32(ctx->r17, 0X14);
    // 0x80800560: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80800564: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
L_80800568:
    // 0x80800568: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
L_8080056C:
    // 0x8080056C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80800570: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80800574: swc1        $f10, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f10.u32l;
    // 0x80800578: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8080057C: jal         0x800EE7F8
    // 0x80800580: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800EE7F8(rdram, ctx);
        goto after_15;
    // 0x80800580: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_15:
    // 0x80800584: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800588: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8080058C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800590: jr          $ra
    // 0x80800594: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80800594: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void bsbeefly_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800C18: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800C1C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(76, 0XE60) << 16);
    // 0x80800C20: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800C24: jr          $ra
    // 0x80800C28: lw          $v0, 0xE60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(76, 0XE60));
    return;
    // 0x80800C28: lw          $v0, 0xE60($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(76, 0XE60));
;}
RECOMP_FUNC void func_808011F4_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808011F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x808011F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808011FC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80801200: jal         0x800B53A4
    // 0x80801204: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800B53A4(rdram, ctx);
        goto after_0;
    // 0x80801204: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80801208: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8080120C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80801210: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x80801214: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801218: lwc1        $f4, 0x58($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X58);
    // 0x8080121C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80801220: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x80801224: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80801228: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8080122C: jal         0x800EEB9C
    // 0x80801230: nop

    func_800EEB9C(rdram, ctx);
        goto after_1;
    // 0x80801230: nop

    after_1:
    // 0x80801234: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80801238: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8080123C: jal         0x800EF04C
    // 0x80801240: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_2;
    // 0x80801240: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_2:
    // 0x80801244: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1676, 0X434C) << 16);
    // 0x80801248: addiu       $t7, $t7, 0x434C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1676, 0X434C));
    // 0x8080124C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80801250: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801254: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80801258: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8080125C: jal         0x800BABB8
    // 0x80801260: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_800BABB8(rdram, ctx);
        goto after_3;
    // 0x80801260: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80801264: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80801268: jal         0x800BA22C
    // 0x8080126C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_800BA22C(rdram, ctx);
        goto after_4;
    // 0x8080126C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80801270: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3DEC) << 16);
    // 0x80801274: jal         0x800DC298
    // 0x80801278: lwc1        $f12, 0x3DEC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3DEC));
    func_800DC298(rdram, ctx);
        goto after_5;
    // 0x80801278: lwc1        $f12, 0x3DEC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3DEC));
    after_5:
    // 0x8080127C: beql        $v0, $zero, L_80801290
    if (ctx->r2 == 0) {
        // 0x80801280: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80801290;
    }
    goto skip_0;
    // 0x80801280: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80801284: jal         0x808011B8
    // 0x80801288: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808011B8_chevilmumbo(rdram, ctx);
        goto after_6;
    // 0x80801288: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x8080128C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801290:
    // 0x80801290: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80801294: jr          $ra
    // 0x80801298: nop

    return;
    // 0x80801298: nop

;}
RECOMP_FUNC void sueggmove_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800274: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080027C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800280: jal         0x80100094
    // 0x80800284: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800284: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800288: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8080028C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80800290: addiu       $a0, $a2, 0x18
    ctx->r4 = ADD32(ctx->r6, 0X18);
    // 0x80800294: swc1        $f0, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f0.u32l;
    // 0x80800298: swc1        $f0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f0.u32l;
    // 0x8080029C: jal         0x800EFD24
    // 0x808002A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x808002A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808002A4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x808002A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808002AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808002B0: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x808002B4: sb          $zero, 0xE($v1)
    MEM_B(0XE, ctx->r3) = 0;
    // 0x808002B8: sb          $zero, 0xF($v1)
    MEM_B(0XF, ctx->r3) = 0;
    // 0x808002BC: jal         0x80800334
    // 0x808002C0: sb          $zero, 0xD($v1)
    MEM_B(0XD, ctx->r3) = 0;
    sueggmove_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x808002C0: sb          $zero, 0xD($v1)
    MEM_B(0XD, ctx->r3) = 0;
    after_2:
    // 0x808002C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808002C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808002CC: jr          $ra
    // 0x808002D0: nop

    return;
    // 0x808002D0: nop

;}
RECOMP_FUNC void func_800CCEF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCEF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CCEF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CCEFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CCF00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CCF04: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800CCF08: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800CCF0C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800CCF10: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800CCF14: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800CCF18: bne         $v1, $t6, L_800CCF44
    if (ctx->r3 != ctx->r14) {
        // 0x800CCF1C: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_800CCF44;
    }
    // 0x800CCF1C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800CCF20: jal         0x800CC078
    // 0x800CCF24: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_800CC078(rdram, ctx);
        goto after_0;
    // 0x800CCF24: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800CCF28: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800CCF2C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800CCF30: bne         $v0, $v1, L_800CCF44
    if (ctx->r2 != ctx->r3) {
        // 0x800CCF34: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800CCF44;
    }
    // 0x800CCF34: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800CCF38: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x800CCF3C: b           L_800CCFD8
    // 0x800CCF40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CCFD8;
    // 0x800CCF40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CCF44:
    // 0x800CCF44: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800CCF48: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800CCF4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CCF50: bne         $v1, $v0, L_800CCF60
    if (ctx->r3 != ctx->r2) {
        // 0x800CCF54: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800CCF60;
    }
    // 0x800CCF54: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800CCF58: b           L_800CCF60
    // 0x800CCF5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800CCF60;
    // 0x800CCF5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CCF60:
    // 0x800CCF60: jal         0x800CC6F4
    // 0x800CCF64: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800CC6F4(rdram, ctx);
        goto after_1;
    // 0x800CCF64: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x800CCF68: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800CCF6C: bltz        $v0, L_800CCF7C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800CCF70: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_800CCF7C;
    }
    // 0x800CCF70: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800CCF74: b           L_800CCFD8
    // 0x800CCF78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CCFD8;
    // 0x800CCF78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CCF7C:
    // 0x800CCF7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CCF80: jal         0x800CC078
    // 0x800CCF84: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_800CC078(rdram, ctx);
        goto after_2;
    // 0x800CCF84: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_2:
    // 0x800CCF88: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800CCF8C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800CCF90: bne         $v0, $v1, L_800CCFA4
    if (ctx->r2 != ctx->r3) {
        // 0x800CCF94: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800CCFA4;
    }
    // 0x800CCF94: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800CCF98: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x800CCF9C: b           L_800CCFD8
    // 0x800CCFA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CCFD8;
    // 0x800CCFA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CCFA4:
    // 0x800CCFA4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800CCFA8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x800CCFAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CCFB0: jal         0x800CC6F4
    // 0x800CCFB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800CC6F4(rdram, ctx);
        goto after_3;
    // 0x800CCFB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800CCFB8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800CCFBC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800CCFC0: bltz        $v0, L_800CCFD0
    if (SIGNED(ctx->r2) < 0) {
        // 0x800CCFC4: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_800CCFD0;
    }
    // 0x800CCFC4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x800CCFC8: b           L_800CCFD8
    // 0x800CCFCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CCFD8;
    // 0x800CCFCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CCFD0:
    // 0x800CCFD0: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x800CCFD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CCFD8:
    // 0x800CCFD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CCFDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CCFE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CCFE4: jr          $ra
    // 0x800CCFE8: nop

    return;
    // 0x800CCFE8: nop

;}
RECOMP_FUNC void func_80800000_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800008: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8080000C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2204, 0X2590) << 16);
    // 0x80800010: addiu       $a1, $a1, 0x2590
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2204, 0X2590));
    // 0x80800014: jal         0x800C4AF0
    // 0x80800018: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800C4AF0(rdram, ctx);
        goto after_0;
    // 0x80800018: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8080001C: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(2204, 0X259C) << 16);
    // 0x80800020: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80800024: jal         0x800C4AF0
    // 0x80800028: addiu       $a1, $a1, 0x259C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2204, 0X259C));
    func_800C4AF0(rdram, ctx);
        goto after_1;
    // 0x80800028: addiu       $a1, $a1, 0x259C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(2204, 0X259C));
    after_1:
    // 0x8080002C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800030: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800034: jr          $ra
    // 0x80800038: nop

    return;
    // 0x80800038: nop

;}
RECOMP_FUNC void func_8009359C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009359C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800935A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800935A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800935A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800935AC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800935B0: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x800935B4: lh          $v0, 0x9C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X9C);
    // 0x800935B8: addiu       $s0, $s0, 0x90
    ctx->r16 = ADD32(ctx->r16, 0X90);
    // 0x800935BC: beql        $a1, $v0, L_800936BC
    if (ctx->r5 == ctx->r2) {
        // 0x800935C0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800936BC;
    }
    goto skip_0;
    // 0x800935C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800935C4: beql        $v0, $zero, L_80093614
    if (ctx->r2 == 0) {
        // 0x800935C8: lw          $t9, 0x3C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X3C);
            goto L_80093614;
    }
    goto skip_1;
    // 0x800935C8: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x800935CC: lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X10);
    // 0x800935D0: beq         $v0, $zero, L_800935E8
    if (ctx->r2 == 0) {
        // 0x800935D4: sll         $a0, $v0, 16
        ctx->r4 = S32(ctx->r2 << 16);
            goto L_800935E8;
    }
    // 0x800935D4: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x800935D8: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800935DC: jal         0x80100E18
    // 0x800935E0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    func_80100E18(rdram, ctx);
        goto after_0;
    // 0x800935E0: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
    // 0x800935E4: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
L_800935E8:
    // 0x800935E8: jal         0x800ADFE0
    // 0x800935EC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_800ADFE0(rdram, ctx);
        goto after_1;
    // 0x800935EC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_1:
    // 0x800935F0: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x800935F4: lh          $a0, 0xC($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC);
    // 0x800935F8: jal         0x800D70F8
    // 0x800935FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800D70F8(rdram, ctx);
        goto after_2;
    // 0x800935FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80093600: jal         0x800D6CEC
    // 0x80093604: lh          $a0, 0xC($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC);
    func_800D6CEC(rdram, ctx);
        goto after_3;
    // 0x80093604: lh          $a0, 0xC($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC);
    after_3:
    // 0x80093608: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    // 0x8009360C: sh          $zero, 0xE($s0)
    MEM_H(0XE, ctx->r16) = 0;
    // 0x80093610: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_80093614:
    // 0x80093614: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80093618: bnel        $t9, $zero, L_8009362C
    if (ctx->r25 != 0) {
        // 0x8009361C: sh          $t0, 0xC($s0)
        MEM_H(0XC, ctx->r16) = ctx->r8;
            goto L_8009362C;
    }
    goto skip_2;
    // 0x8009361C: sh          $t0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r8;
    skip_2:
    // 0x80093620: b           L_800936B8
    // 0x80093624: sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
        goto L_800936B8;
    // 0x80093624: sb          $zero, 0x12($s0)
    MEM_B(0X12, ctx->r16) = 0;
    // 0x80093628: sh          $t0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r8;
L_8009362C:
    // 0x8009362C: jal         0x80093738
    // 0x80093630: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80093738(rdram, ctx);
        goto after_4;
    // 0x80093630: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x80093634: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80093638: lh          $a0, 0xC($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XC);
    // 0x8009363C: jal         0x800D70F8
    // 0x80093640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D70F8(rdram, ctx);
        goto after_5;
    // 0x80093640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80093644: jal         0x800B26F0
    // 0x80093648: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    func_800B26F0(rdram, ctx);
        goto after_6;
    // 0x80093648: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x8009364C: beq         $v0, $zero, L_8009365C
    if (ctx->r2 == 0) {
        // 0x80093650: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_8009365C;
    }
    // 0x80093650: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80093654: b           L_80093660
    // 0x80093658: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80093660;
    // 0x80093658: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8009365C:
    // 0x8009365C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80093660:
    // 0x80093660: jal         0x800A25D0
    // 0x80093664: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_800A25D0(rdram, ctx);
        goto after_7;
    // 0x80093664: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_7:
    // 0x80093668: lh          $a1, 0xC($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XC);
    // 0x8009366C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80093670: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80093674: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80093678: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8009367C: jal         0x80100D24
    // 0x80093680: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80100D24(rdram, ctx);
        goto after_8;
    // 0x80093680: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_8:
    // 0x80093684: jal         0x800AE020
    // 0x80093688: sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    func_800AE020(rdram, ctx);
        goto after_9;
    // 0x80093688: sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    after_9:
    // 0x8009368C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80093690: jal         0x800AE080
    // 0x80093694: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    func_800AE080(rdram, ctx);
        goto after_10;
    // 0x80093694: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_10:
    // 0x80093698: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8009369C: jal         0x800E09B8
    // 0x800936A0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_800E09B8(rdram, ctx);
        goto after_11;
    // 0x800936A0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_11:
    // 0x800936A4: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x800936A8: sra         $t1, $a1, 16
    ctx->r9 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800936AC: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800936B0: jal         0x800AE6FC
    // 0x800936B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800AE6FC(rdram, ctx);
        goto after_12;
    // 0x800936B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_800936B8:
    // 0x800936B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800936BC:
    // 0x800936BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800936C0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800936C4: jr          $ra
    // 0x800936C8: nop

    return;
    // 0x800936C8: nop

;}
RECOMP_FUNC void indrv_fx_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800090: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800094: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80800098: sltiu       $at, $a1, 0x1F
    ctx->r1 = ctx->r5 < 0X1F ? 1 : 0;
    // 0x8080009C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x808000A0: beq         $at, $zero, L_80800514
    if (ctx->r1 == 0) {
        // 0x808000A4: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80800514;
    }
    // 0x808000A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000A8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x808000AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2966, 0X530) << 16);
    // 0x808000B0: addu        $at, $at, $t6
    gpr jr_addend_808000B8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x808000B4: lw          $t6, 0x530($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2966, 0X530));
    // 0x808000B8: jr          $t6
    // 0x808000BC: nop

    switch (jr_addend_808000B8 >> 2) {
        case 0: goto L_808000C0; break;
        case 1: goto L_808000E4; break;
        case 2: goto L_80800108; break;
        case 3: goto L_8080012C; break;
        case 4: goto L_80800150; break;
        case 5: goto L_80800174; break;
        case 6: goto L_808001BC; break;
        case 7: goto L_808001E0; break;
        case 8: goto L_80800204; break;
        case 9: goto L_80800228; break;
        case 10: goto L_80800198; break;
        case 11: goto L_8080024C; break;
        case 12: goto L_80800270; break;
        case 13: goto L_80800294; break;
        case 14: goto L_808002B8; break;
        case 15: goto L_808002DC; break;
        case 16: goto L_80800300; break;
        case 17: goto L_80800324; break;
        case 18: goto L_80800348; break;
        case 19: goto L_8080036C; break;
        case 20: goto L_80800390; break;
        case 21: goto L_808003B4; break;
        case 22: goto L_808003D8; break;
        case 23: goto L_808003FC; break;
        case 24: goto L_80800420; break;
        case 25: goto L_80800444; break;
        case 26: goto L_80800468; break;
        case 27: goto L_8080048C; break;
        case 28: goto L_808004B0; break;
        case 29: goto L_808004D4; break;
        case 30: goto L_808004F8; break;
        default: switch_error(__func__, 0x808000B8, 0x80800530);
    }
    // 0x808000BC: nop

L_808000C0:
    // 0x808000C0: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2966, 0X5B0) << 16);
    // 0x808000C4: addiu       $t7, $t7, 0x5B0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2966, 0X5B0));
    // 0x808000C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x808000CC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000D0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808000D4: jal         0x80800000
    // 0x808000D8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_0;
    // 0x808000D8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_0:
    // 0x808000DC: b           L_80800518
    // 0x808000E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x808000E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808000E4:
    // 0x808000E4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2966, 0X608) << 16);
    // 0x808000E8: addiu       $t8, $t8, 0x608
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2966, 0X608));
    // 0x808000EC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808000F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808000F4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808000F8: jal         0x80800000
    // 0x808000FC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_1;
    // 0x808000FC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_1:
    // 0x80800100: b           L_80800518
    // 0x80800104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800104: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800108:
    // 0x80800108: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2966, 0X648) << 16);
    // 0x8080010C: addiu       $t9, $t9, 0x648
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2966, 0X648));
    // 0x80800110: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80800114: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800118: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080011C: jal         0x80800000
    // 0x80800120: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_2;
    // 0x80800120: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_2:
    // 0x80800124: b           L_80800518
    // 0x80800128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080012C:
    // 0x8080012C: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2966, 0X684) << 16);
    // 0x80800130: addiu       $t0, $t0, 0x684
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2966, 0X684));
    // 0x80800134: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800138: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080013C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800140: jal         0x80800000
    // 0x80800144: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_3;
    // 0x80800144: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80800148: b           L_80800518
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x8080014C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800150:
    // 0x80800150: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2966, 0X6E4) << 16);
    // 0x80800154: addiu       $t1, $t1, 0x6E4
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2966, 0X6E4));
    // 0x80800158: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080015C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800160: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800164: jal         0x80800000
    // 0x80800168: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_4;
    // 0x80800168: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_4:
    // 0x8080016C: b           L_80800518
    // 0x80800170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800170: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800174:
    // 0x80800174: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2966, 0X720) << 16);
    // 0x80800178: addiu       $t2, $t2, 0x720
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2966, 0X720));
    // 0x8080017C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800180: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800184: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800188: jal         0x80800000
    // 0x8080018C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_5;
    // 0x8080018C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80800190: b           L_80800518
    // 0x80800194: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800194: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800198:
    // 0x80800198: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2966, 0X780) << 16);
    // 0x8080019C: addiu       $t3, $t3, 0x780
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2966, 0X780));
    // 0x808001A0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x808001A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808001A8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001AC: jal         0x80800000
    // 0x808001B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_6;
    // 0x808001B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x808001B4: b           L_80800518
    // 0x808001B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x808001B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001BC:
    // 0x808001BC: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2966, 0X7E0) << 16);
    // 0x808001C0: addiu       $t4, $t4, 0x7E0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2966, 0X7E0));
    // 0x808001C4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808001C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808001CC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001D0: jal         0x80800000
    // 0x808001D4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_7;
    // 0x808001D4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_7:
    // 0x808001D8: b           L_80800518
    // 0x808001DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x808001DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808001E0:
    // 0x808001E0: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2966, 0X818) << 16);
    // 0x808001E4: addiu       $t5, $t5, 0x818
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2966, 0X818));
    // 0x808001E8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808001EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808001F0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808001F4: jal         0x80800000
    // 0x808001F8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_8;
    // 0x808001F8: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_8:
    // 0x808001FC: b           L_80800518
    // 0x80800200: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800200: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800204:
    // 0x80800204: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2966, 0X870) << 16);
    // 0x80800208: addiu       $t6, $t6, 0x870
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2966, 0X870));
    // 0x8080020C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800210: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800214: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800218: jal         0x80800000
    // 0x8080021C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_9;
    // 0x8080021C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_9:
    // 0x80800220: b           L_80800518
    // 0x80800224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800224: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800228:
    // 0x80800228: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2966, 0X8C0) << 16);
    // 0x8080022C: addiu       $t7, $t7, 0x8C0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2966, 0X8C0));
    // 0x80800230: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800234: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800238: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080023C: jal         0x80800000
    // 0x80800240: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_10;
    // 0x80800240: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80800244: b           L_80800518
    // 0x80800248: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800248: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080024C:
    // 0x8080024C: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2966, 0X920) << 16);
    // 0x80800250: addiu       $t8, $t8, 0x920
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2966, 0X920));
    // 0x80800254: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80800258: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080025C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800260: jal         0x80800000
    // 0x80800264: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_11;
    // 0x80800264: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x80800268: b           L_80800518
    // 0x8080026C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x8080026C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800270:
    // 0x80800270: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2966, 0X964) << 16);
    // 0x80800274: addiu       $t9, $t9, 0x964
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2966, 0X964));
    // 0x80800278: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8080027C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800280: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800284: jal         0x80800000
    // 0x80800288: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_12;
    // 0x80800288: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x8080028C: b           L_80800518
    // 0x80800290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800290: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800294:
    // 0x80800294: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2966, 0X9A8) << 16);
    // 0x80800298: addiu       $t0, $t0, 0x9A8
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2966, 0X9A8));
    // 0x8080029C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x808002A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808002A4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002A8: jal         0x80800000
    // 0x808002AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_13;
    // 0x808002AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_13:
    // 0x808002B0: b           L_80800518
    // 0x808002B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x808002B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002B8:
    // 0x808002B8: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2966, 0X9F4) << 16);
    // 0x808002BC: addiu       $t1, $t1, 0x9F4
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2966, 0X9F4));
    // 0x808002C0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x808002C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808002C8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002CC: jal         0x80800000
    // 0x808002D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_14;
    // 0x808002D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_14:
    // 0x808002D4: b           L_80800518
    // 0x808002D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x808002D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808002DC:
    // 0x808002DC: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2966, 0XA4C) << 16);
    // 0x808002E0: addiu       $t2, $t2, 0xA4C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2966, 0XA4C));
    // 0x808002E4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x808002E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808002EC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808002F0: jal         0x80800000
    // 0x808002F4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_15;
    // 0x808002F4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_15:
    // 0x808002F8: b           L_80800518
    // 0x808002FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x808002FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800300:
    // 0x80800300: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2966, 0XAA4) << 16);
    // 0x80800304: addiu       $t3, $t3, 0xAA4
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2966, 0XAA4));
    // 0x80800308: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8080030C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800310: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800314: jal         0x80800000
    // 0x80800318: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_16;
    // 0x80800318: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_16:
    // 0x8080031C: b           L_80800518
    // 0x80800320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800324:
    // 0x80800324: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2966, 0XAFC) << 16);
    // 0x80800328: addiu       $t4, $t4, 0xAFC
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2966, 0XAFC));
    // 0x8080032C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800330: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800334: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800338: jal         0x80800000
    // 0x8080033C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_17;
    // 0x8080033C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_17:
    // 0x80800340: b           L_80800518
    // 0x80800344: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800344: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800348:
    // 0x80800348: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2966, 0XB2C) << 16);
    // 0x8080034C: addiu       $t5, $t5, 0xB2C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2966, 0XB2C));
    // 0x80800350: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80800354: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800358: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080035C: jal         0x80800000
    // 0x80800360: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_18;
    // 0x80800360: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_18:
    // 0x80800364: b           L_80800518
    // 0x80800368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800368: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080036C:
    // 0x8080036C: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2966, 0XB5C) << 16);
    // 0x80800370: addiu       $t6, $t6, 0xB5C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2966, 0XB5C));
    // 0x80800374: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80800378: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080037C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800380: jal         0x80800000
    // 0x80800384: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_19;
    // 0x80800384: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_19:
    // 0x80800388: b           L_80800518
    // 0x8080038C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x8080038C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800390:
    // 0x80800390: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2966, 0XBA0) << 16);
    // 0x80800394: addiu       $t7, $t7, 0xBA0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2966, 0XBA0));
    // 0x80800398: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8080039C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808003A4: jal         0x80800000
    // 0x808003A8: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_20;
    // 0x808003A8: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    after_20:
    // 0x808003AC: b           L_80800518
    // 0x808003B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x808003B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003B4:
    // 0x808003B4: lui         $t8, 0x8080
    ctx->r24 = S32(RELOC_HI16(2966, 0XBE8) << 16);
    // 0x808003B8: addiu       $t8, $t8, 0xBE8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(2966, 0XBE8));
    // 0x808003BC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x808003C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808003C8: jal         0x80800000
    // 0x808003CC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_21;
    // 0x808003CC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_21:
    // 0x808003D0: b           L_80800518
    // 0x808003D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x808003D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003D8:
    // 0x808003D8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2966, 0XC3C) << 16);
    // 0x808003DC: addiu       $t9, $t9, 0xC3C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(2966, 0XC3C));
    // 0x808003E0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x808003E4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808003E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808003EC: jal         0x80800000
    // 0x808003F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_22;
    // 0x808003F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_22:
    // 0x808003F4: b           L_80800518
    // 0x808003F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x808003F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003FC:
    // 0x808003FC: lui         $t0, 0x8080
    ctx->r8 = S32(RELOC_HI16(2966, 0XCA4) << 16);
    // 0x80800400: addiu       $t0, $t0, 0xCA4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(2966, 0XCA4));
    // 0x80800404: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80800408: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080040C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800410: jal         0x80800000
    // 0x80800414: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_23;
    // 0x80800414: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_23:
    // 0x80800418: b           L_80800518
    // 0x8080041C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x8080041C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800420:
    // 0x80800420: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2966, 0XCF0) << 16);
    // 0x80800424: addiu       $t1, $t1, 0xCF0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2966, 0XCF0));
    // 0x80800428: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8080042C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800430: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800434: jal         0x80800000
    // 0x80800438: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_24;
    // 0x80800438: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_24:
    // 0x8080043C: b           L_80800518
    // 0x80800440: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800440: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800444:
    // 0x80800444: lui         $t2, 0x8080
    ctx->r10 = S32(RELOC_HI16(2966, 0XD30) << 16);
    // 0x80800448: addiu       $t2, $t2, 0xD30
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(2966, 0XD30));
    // 0x8080044C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80800450: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800454: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800458: jal         0x80800000
    // 0x8080045C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_25;
    // 0x8080045C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_25:
    // 0x80800460: b           L_80800518
    // 0x80800464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800464: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800468:
    // 0x80800468: lui         $t3, 0x8080
    ctx->r11 = S32(RELOC_HI16(2966, 0XD6C) << 16);
    // 0x8080046C: addiu       $t3, $t3, 0xD6C
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(2966, 0XD6C));
    // 0x80800470: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80800474: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800478: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080047C: jal         0x80800000
    // 0x80800480: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_26;
    // 0x80800480: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_26:
    // 0x80800484: b           L_80800518
    // 0x80800488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x80800488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080048C:
    // 0x8080048C: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(2966, 0XDBC) << 16);
    // 0x80800490: addiu       $t4, $t4, 0xDBC
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(2966, 0XDBC));
    // 0x80800494: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80800498: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080049C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808004A0: jal         0x80800000
    // 0x808004A4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_27;
    // 0x808004A4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_27:
    // 0x808004A8: b           L_80800518
    // 0x808004AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x808004AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004B0:
    // 0x808004B0: lui         $t5, 0x8080
    ctx->r13 = S32(RELOC_HI16(2966, 0XE0C) << 16);
    // 0x808004B4: addiu       $t5, $t5, 0xE0C
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(2966, 0XE0C));
    // 0x808004B8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x808004BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004C0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808004C4: jal         0x80800000
    // 0x808004C8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_28;
    // 0x808004C8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_28:
    // 0x808004CC: b           L_80800518
    // 0x808004D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x808004D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004D4:
    // 0x808004D4: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(2966, 0XE5C) << 16);
    // 0x808004D8: addiu       $t6, $t6, 0xE5C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(2966, 0XE5C));
    // 0x808004DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808004E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x808004E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x808004E8: jal         0x80800000
    // 0x808004EC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_29;
    // 0x808004EC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_29:
    // 0x808004F0: b           L_80800518
    // 0x808004F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80800518;
    // 0x808004F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004F8:
    // 0x808004F8: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(2966, 0XEAC) << 16);
    // 0x808004FC: addiu       $t7, $t7, 0xEAC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(2966, 0XEAC));
    // 0x80800500: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800504: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800508: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8080050C: jal         0x80800000
    // 0x80800510: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_80800000_indrv_fx(rdram, ctx);
        goto after_30;
    // 0x80800510: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_30:
L_80800514:
    // 0x80800514: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80800518:
    // 0x80800518: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080051C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800520: jr          $ra
    // 0x80800524: nop

    return;
    // 0x80800524: nop

    // 0x80800528: nop

    // 0x8080052C: nop

;}
RECOMP_FUNC void sumole_entrypoint_19(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801D3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80801D40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801D44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801D48: lbu         $v1, 0x79($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X79);
    // 0x80801D4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801D50: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801D54: srl         $v0, $v1, 4
    ctx->r2 = S32(U32(ctx->r3) >> 4);
    // 0x80801D58: beq         $a1, $v0, L_80802104
    if (ctx->r5 == ctx->r2) {
        // 0x80801D5C: sltiu       $at, $v0, 0x5
        ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
            goto L_80802104;
    }
    // 0x80801D5C: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x80801D60: beq         $at, $zero, L_80802104
    if (ctx->r1 == 0) {
        // 0x80801D64: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_80802104;
    }
    // 0x80801D64: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80801D68: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3158, 0X24F4) << 16);
    // 0x80801D6C: addu        $at, $at, $t6
    gpr jr_addend_80801D74 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80801D70: lw          $t6, 0x24F4($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(3158, 0X24F4));
    // 0x80801D74: jr          $t6
    // 0x80801D78: nop

    switch (jr_addend_80801D74 >> 2) {
        case 0: goto L_80801D7C; break;
        case 1: goto L_80801E34; break;
        case 2: goto L_80801F0C; break;
        case 3: goto L_80801FAC; break;
        case 4: goto L_80802068; break;
        default: switch_error(__func__, 0x80801D74, 0x808024F4);
    }
    // 0x80801D78: nop

L_80801D7C:
    // 0x80801D7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801D80: beq         $a2, $at, L_80801DB4
    if (ctx->r6 == ctx->r1) {
        // 0x80801D84: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801DB4;
    }
    // 0x80801D84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801D88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801D8C: beq         $a2, $at, L_80801DD8
    if (ctx->r6 == ctx->r1) {
        // 0x80801D90: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80801DD8;
    }
    // 0x80801D90: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801D94: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801D98: beq         $a2, $at, L_80801DFC
    if (ctx->r6 == ctx->r1) {
        // 0x80801D9C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80801DFC;
    }
    // 0x80801D9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801DA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801DA4: beq         $a2, $at, L_80801E24
    if (ctx->r6 == ctx->r1) {
        // 0x80801DA8: sll         $t7, $a2, 4
        ctx->r15 = S32(ctx->r6 << 4);
            goto L_80801E24;
    }
    // 0x80801DA8: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x80801DAC: b           L_80802108
    // 0x80801DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802108;
    // 0x80801DB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801DB4:
    // 0x80801DB4: jal         0x80090708
    // 0x80801DB8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80090708(rdram, ctx);
        goto after_0;
    // 0x80801DB8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_0:
    // 0x80801DBC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80801DC0: lbu         $t0, 0x79($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X79);
    // 0x80801DC4: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x80801DC8: andi        $t1, $t0, 0xFF0F
    ctx->r9 = ctx->r8 & 0XFF0F;
    // 0x80801DCC: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80801DD0: b           L_80802104
    // 0x80801DD4: sb          $t2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r10;
        goto L_80802104;
    // 0x80801DD4: sb          $t2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r10;
L_80801DD8:
    // 0x80801DD8: jal         0x8010D254
    // 0x80801DDC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8010D254(rdram, ctx);
        goto after_1;
    // 0x80801DDC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x80801DE0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80801DE4: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x80801DE8: sll         $t5, $t3, 4
    ctx->r13 = S32(ctx->r11 << 4);
    // 0x80801DEC: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x80801DF0: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80801DF4: b           L_80802104
    // 0x80801DF8: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
        goto L_80802104;
    // 0x80801DF8: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
L_80801DFC:
    // 0x80801DFC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801E00: jal         0x80090734
    // 0x80801E04: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80090734(rdram, ctx);
        goto after_2;
    // 0x80801E04: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x80801E08: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80801E0C: lbu         $t2, 0x79($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X79);
    // 0x80801E10: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80801E14: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x80801E18: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80801E1C: b           L_80802104
    // 0x80801E20: sb          $t4, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r12;
        goto L_80802104;
    // 0x80801E20: sb          $t4, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r12;
L_80801E24:
    // 0x80801E24: andi        $t8, $v1, 0xFF0F
    ctx->r24 = ctx->r3 & 0XFF0F;
    // 0x80801E28: or          $t0, $t7, $t8
    ctx->r8 = ctx->r15 | ctx->r24;
    // 0x80801E2C: b           L_80802104
    // 0x80801E30: sb          $t0, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r8;
        goto L_80802104;
    // 0x80801E30: sb          $t0, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r8;
L_80801E34:
    // 0x80801E34: beq         $a2, $zero, L_80801E68
    if (ctx->r6 == 0) {
        // 0x80801E38: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801E68;
    }
    // 0x80801E38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801E3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801E40: beq         $a2, $at, L_80801E8C
    if (ctx->r6 == ctx->r1) {
        // 0x80801E44: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80801E8C;
    }
    // 0x80801E44: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801E48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801E4C: beq         $a2, $at, L_80801EB8
    if (ctx->r6 == ctx->r1) {
        // 0x80801E50: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801EB8;
    }
    // 0x80801E50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801E54: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801E58: beq         $a2, $at, L_80801EE8
    if (ctx->r6 == ctx->r1) {
        // 0x80801E5C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801EE8;
    }
    // 0x80801E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801E60: b           L_80802108
    // 0x80801E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802108;
    // 0x80801E64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801E68:
    // 0x80801E68: jal         0x80090708
    // 0x80801E6C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80090708(rdram, ctx);
        goto after_3;
    // 0x80801E6C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x80801E70: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80801E74: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x80801E78: sll         $t1, $t9, 4
    ctx->r9 = S32(ctx->r25 << 4);
    // 0x80801E7C: andi        $t4, $t3, 0xFF0F
    ctx->r12 = ctx->r11 & 0XFF0F;
    // 0x80801E80: or          $t6, $t1, $t4
    ctx->r14 = ctx->r9 | ctx->r12;
    // 0x80801E84: b           L_80802104
    // 0x80801E88: sb          $t6, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r14;
        goto L_80802104;
    // 0x80801E88: sb          $t6, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r14;
L_80801E8C:
    // 0x80801E8C: jal         0x8010D254
    // 0x80801E90: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8010D254(rdram, ctx);
        goto after_4;
    // 0x80801E90: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_4:
    // 0x80801E94: jal         0x80090708
    // 0x80801E98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_5;
    // 0x80801E98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80801E9C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80801EA0: lbu         $t0, 0x79($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X79);
    // 0x80801EA4: sll         $t8, $t5, 4
    ctx->r24 = S32(ctx->r13 << 4);
    // 0x80801EA8: andi        $t9, $t0, 0xFF0F
    ctx->r25 = ctx->r8 & 0XFF0F;
    // 0x80801EAC: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x80801EB0: b           L_80802104
    // 0x80801EB4: sb          $t2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r10;
        goto L_80802104;
    // 0x80801EB4: sb          $t2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r10;
L_80801EB8:
    // 0x80801EB8: jal         0x80090708
    // 0x80801EBC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80090708(rdram, ctx);
        goto after_6;
    // 0x80801EBC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_6:
    // 0x80801EC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801EC4: jal         0x80090734
    // 0x80801EC8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    func_80090734(rdram, ctx);
        goto after_7;
    // 0x80801EC8: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    after_7:
    // 0x80801ECC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80801ED0: lbu         $t6, 0x79($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X79);
    // 0x80801ED4: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80801ED8: andi        $t5, $t6, 0xFF0F
    ctx->r13 = ctx->r14 & 0XFF0F;
    // 0x80801EDC: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x80801EE0: b           L_80802104
    // 0x80801EE4: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
        goto L_80802104;
    // 0x80801EE4: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
L_80801EE8:
    // 0x80801EE8: jal         0x80090708
    // 0x80801EEC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80090708(rdram, ctx);
        goto after_8;
    // 0x80801EEC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_8:
    // 0x80801EF0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80801EF4: lbu         $t2, 0x79($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X79);
    // 0x80801EF8: sll         $t9, $t0, 4
    ctx->r25 = S32(ctx->r8 << 4);
    // 0x80801EFC: andi        $t3, $t2, 0xFF0F
    ctx->r11 = ctx->r10 & 0XFF0F;
    // 0x80801F00: or          $t1, $t9, $t3
    ctx->r9 = ctx->r25 | ctx->r11;
    // 0x80801F04: b           L_80802104
    // 0x80801F08: sb          $t1, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r9;
        goto L_80802104;
    // 0x80801F08: sb          $t1, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r9;
L_80801F0C:
    // 0x80801F0C: beq         $a2, $zero, L_80801F40
    if (ctx->r6 == 0) {
        // 0x80801F10: sll         $t5, $a2, 4
        ctx->r13 = S32(ctx->r6 << 4);
            goto L_80801F40;
    }
    // 0x80801F10: sll         $t5, $a2, 4
    ctx->r13 = S32(ctx->r6 << 4);
    // 0x80801F14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801F18: beq         $a2, $at, L_80801F50
    if (ctx->r6 == ctx->r1) {
        // 0x80801F1C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80801F50;
    }
    // 0x80801F1C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801F20: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80801F24: beq         $a2, $at, L_80801F74
    if (ctx->r6 == ctx->r1) {
        // 0x80801F28: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80801F74;
    }
    // 0x80801F28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801F2C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801F30: beq         $a2, $at, L_80801F9C
    if (ctx->r6 == ctx->r1) {
        // 0x80801F34: sll         $t1, $a2, 4
        ctx->r9 = S32(ctx->r6 << 4);
            goto L_80801F9C;
    }
    // 0x80801F34: sll         $t1, $a2, 4
    ctx->r9 = S32(ctx->r6 << 4);
    // 0x80801F38: b           L_80802108
    // 0x80801F3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802108;
    // 0x80801F3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801F40:
    // 0x80801F40: andi        $t7, $v1, 0xFF0F
    ctx->r15 = ctx->r3 & 0XFF0F;
    // 0x80801F44: or          $t0, $t5, $t7
    ctx->r8 = ctx->r13 | ctx->r15;
    // 0x80801F48: b           L_80802104
    // 0x80801F4C: sb          $t0, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r8;
        goto L_80802104;
    // 0x80801F4C: sb          $t0, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r8;
L_80801F50:
    // 0x80801F50: jal         0x80090708
    // 0x80801F54: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80090708(rdram, ctx);
        goto after_9;
    // 0x80801F54: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_9:
    // 0x80801F58: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80801F5C: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x80801F60: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80801F64: andi        $t1, $t3, 0xFF0F
    ctx->r9 = ctx->r11 & 0XFF0F;
    // 0x80801F68: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x80801F6C: b           L_80802104
    // 0x80801F70: sb          $t6, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r14;
        goto L_80802104;
    // 0x80801F70: sb          $t6, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r14;
L_80801F74:
    // 0x80801F74: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80801F78: jal         0x80090734
    // 0x80801F7C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80090734(rdram, ctx);
        goto after_10;
    // 0x80801F7C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_10:
    // 0x80801F80: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80801F84: lbu         $t0, 0x79($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X79);
    // 0x80801F88: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x80801F8C: andi        $t8, $t0, 0xFF0F
    ctx->r24 = ctx->r8 & 0XFF0F;
    // 0x80801F90: or          $t2, $t7, $t8
    ctx->r10 = ctx->r15 | ctx->r24;
    // 0x80801F94: b           L_80802104
    // 0x80801F98: sb          $t2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r10;
        goto L_80802104;
    // 0x80801F98: sb          $t2, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r10;
L_80801F9C:
    // 0x80801F9C: andi        $t6, $v1, 0xFF0F
    ctx->r14 = ctx->r3 & 0XFF0F;
    // 0x80801FA0: or          $t4, $t1, $t6
    ctx->r12 = ctx->r9 | ctx->r14;
    // 0x80801FA4: b           L_80802104
    // 0x80801FA8: sb          $t4, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r12;
        goto L_80802104;
    // 0x80801FA8: sb          $t4, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r12;
L_80801FAC:
    // 0x80801FAC: beq         $a2, $zero, L_80801FDC
    if (ctx->r6 == 0) {
        // 0x80801FB0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80801FDC;
    }
    // 0x80801FB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801FB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80801FB8: beq         $a2, $at, L_80802000
    if (ctx->r6 == ctx->r1) {
        // 0x80801FBC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80802000;
    }
    // 0x80801FBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801FC0: beq         $a2, $at, L_80802018
    if (ctx->r6 == ctx->r1) {
        // 0x80801FC4: addiu       $a0, $s0, 0x4
        ctx->r4 = ADD32(ctx->r16, 0X4);
            goto L_80802018;
    }
    // 0x80801FC4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80801FC8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80801FCC: beq         $a2, $at, L_80802044
    if (ctx->r6 == ctx->r1) {
        // 0x80801FD0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80802044;
    }
    // 0x80801FD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80801FD4: b           L_80802108
    // 0x80801FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802108;
    // 0x80801FD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80801FDC:
    // 0x80801FDC: jal         0x80090708
    // 0x80801FE0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80090708(rdram, ctx);
        goto after_11;
    // 0x80801FE0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_11:
    // 0x80801FE4: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80801FE8: lbu         $t8, 0x79($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X79);
    // 0x80801FEC: sll         $t7, $t5, 4
    ctx->r15 = S32(ctx->r13 << 4);
    // 0x80801FF0: andi        $t2, $t8, 0xFF0F
    ctx->r10 = ctx->r24 & 0XFF0F;
    // 0x80801FF4: or          $t3, $t7, $t2
    ctx->r11 = ctx->r15 | ctx->r10;
    // 0x80801FF8: b           L_80802104
    // 0x80801FFC: sb          $t3, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r11;
        goto L_80802104;
    // 0x80801FFC: sb          $t3, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r11;
L_80802000:
    // 0x80802000: jal         0x80090708
    // 0x80802004: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_12;
    // 0x80802004: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x80802008: jal         0x80090708
    // 0x8080200C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090708(rdram, ctx);
        goto after_13;
    // 0x8080200C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x80802010: b           L_80802108
    // 0x80802014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802108;
    // 0x80802014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802018:
    // 0x80802018: jal         0x8010D254
    // 0x8080201C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8010D254(rdram, ctx);
        goto after_14;
    // 0x8080201C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_14:
    // 0x80802020: jal         0x80090708
    // 0x80802024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80090708(rdram, ctx);
        goto after_15;
    // 0x80802024: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x80802028: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8080202C: lbu         $t4, 0x79($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X79);
    // 0x80802030: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x80802034: andi        $t5, $t4, 0xFF0F
    ctx->r13 = ctx->r12 & 0XFF0F;
    // 0x80802038: or          $t0, $t6, $t5
    ctx->r8 = ctx->r14 | ctx->r13;
    // 0x8080203C: b           L_80802104
    // 0x80802040: sb          $t0, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r8;
        goto L_80802104;
    // 0x80802040: sb          $t0, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r8;
L_80802044:
    // 0x80802044: jal         0x80090708
    // 0x80802048: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80090708(rdram, ctx);
        goto after_16;
    // 0x80802048: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_16:
    // 0x8080204C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80802050: lbu         $t3, 0x79($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X79);
    // 0x80802054: sll         $t2, $t8, 4
    ctx->r10 = S32(ctx->r24 << 4);
    // 0x80802058: andi        $t9, $t3, 0xFF0F
    ctx->r25 = ctx->r11 & 0XFF0F;
    // 0x8080205C: or          $t1, $t2, $t9
    ctx->r9 = ctx->r10 | ctx->r25;
    // 0x80802060: b           L_80802104
    // 0x80802064: sb          $t1, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r9;
        goto L_80802104;
    // 0x80802064: sb          $t1, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r9;
L_80802068:
    // 0x80802068: beq         $a2, $zero, L_8080209C
    if (ctx->r6 == 0) {
        // 0x8080206C: sll         $t5, $a2, 4
        ctx->r13 = S32(ctx->r6 << 4);
            goto L_8080209C;
    }
    // 0x8080206C: sll         $t5, $a2, 4
    ctx->r13 = S32(ctx->r6 << 4);
    // 0x80802070: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80802074: beq         $a2, $at, L_808020AC
    if (ctx->r6 == ctx->r1) {
        // 0x80802078: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_808020AC;
    }
    // 0x80802078: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8080207C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80802080: beq         $a2, $at, L_808020D0
    if (ctx->r6 == ctx->r1) {
        // 0x80802084: sll         $t0, $a2, 4
        ctx->r8 = S32(ctx->r6 << 4);
            goto L_808020D0;
    }
    // 0x80802084: sll         $t0, $a2, 4
    ctx->r8 = S32(ctx->r6 << 4);
    // 0x80802088: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8080208C: beq         $a2, $at, L_808020E0
    if (ctx->r6 == ctx->r1) {
        // 0x80802090: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_808020E0;
    }
    // 0x80802090: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80802094: b           L_80802108
    // 0x80802098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80802108;
    // 0x80802098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080209C:
    // 0x8080209C: andi        $t0, $v1, 0xFF0F
    ctx->r8 = ctx->r3 & 0XFF0F;
    // 0x808020A0: or          $t8, $t5, $t0
    ctx->r24 = ctx->r13 | ctx->r8;
    // 0x808020A4: b           L_80802104
    // 0x808020A8: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
        goto L_80802104;
    // 0x808020A8: sb          $t8, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r24;
L_808020AC:
    // 0x808020AC: jal         0x80090708
    // 0x808020B0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80090708(rdram, ctx);
        goto after_17;
    // 0x808020B0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_17:
    // 0x808020B4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808020B8: lbu         $t9, 0x79($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X79);
    // 0x808020BC: sll         $t2, $t7, 4
    ctx->r10 = S32(ctx->r15 << 4);
    // 0x808020C0: andi        $t1, $t9, 0xFF0F
    ctx->r9 = ctx->r25 & 0XFF0F;
    // 0x808020C4: or          $t4, $t2, $t1
    ctx->r12 = ctx->r10 | ctx->r9;
    // 0x808020C8: b           L_80802104
    // 0x808020CC: sb          $t4, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r12;
        goto L_80802104;
    // 0x808020CC: sb          $t4, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r12;
L_808020D0:
    // 0x808020D0: andi        $t8, $v1, 0xFF0F
    ctx->r24 = ctx->r3 & 0XFF0F;
    // 0x808020D4: or          $t7, $t0, $t8
    ctx->r15 = ctx->r8 | ctx->r24;
    // 0x808020D8: b           L_80802104
    // 0x808020DC: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
        goto L_80802104;
    // 0x808020DC: sb          $t7, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r15;
L_808020E0:
    // 0x808020E0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808020E4: jal         0x80090734
    // 0x808020E8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80090734(rdram, ctx);
        goto after_18;
    // 0x808020E8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_18:
    // 0x808020EC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x808020F0: lbu         $t1, 0x79($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X79);
    // 0x808020F4: sll         $t2, $t3, 4
    ctx->r10 = S32(ctx->r11 << 4);
    // 0x808020F8: andi        $t4, $t1, 0xFF0F
    ctx->r12 = ctx->r9 & 0XFF0F;
    // 0x808020FC: or          $t6, $t2, $t4
    ctx->r14 = ctx->r10 | ctx->r12;
    // 0x80802100: sb          $t6, 0x79($s0)
    MEM_B(0X79, ctx->r16) = ctx->r14;
L_80802104:
    // 0x80802104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80802108:
    // 0x80802108: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080210C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80802110: jr          $ra
    // 0x80802114: nop

    return;
    // 0x80802114: nop

;}
RECOMP_FUNC void _susubgame_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A300: syscall     834
    recomp_syscall_handler(rdram, ctx, 0x8008A300);
    return;
    // 0x8008A304: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
