#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void yaw_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C88C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C890: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C894: lw          $v1, 0xF8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XF8);
    // 0x8009C898: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009C89C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8009C8A0: beql        $v0, $zero, L_8009C8FC
    if (ctx->r2 == 0) {
        // 0x8009C8A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009C8FC;
    }
    goto skip_0;
    // 0x8009C8A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8009C8A8: beq         $v0, $at, L_8009C8CC
    if (ctx->r2 == ctx->r1) {
        // 0x8009C8AC: lui         $a1, 0x442F
        ctx->r5 = S32(0X442F << 16);
            goto L_8009C8CC;
    }
    // 0x8009C8AC: lui         $a1, 0x442F
    ctx->r5 = S32(0X442F << 16);
    // 0x8009C8B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009C8B4: beq         $v0, $at, L_8009C8DC
    if (ctx->r2 == ctx->r1) {
        // 0x8009C8B8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8009C8DC;
    }
    // 0x8009C8B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009C8BC: beql        $v0, $at, L_8009C8F0
    if (ctx->r2 == ctx->r1) {
        // 0x8009C8C0: lw          $a1, 0x14($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X14);
            goto L_8009C8F0;
    }
    goto skip_1;
    // 0x8009C8C0: lw          $a1, 0x14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14);
    skip_1:
    // 0x8009C8C4: b           L_8009C8FC
    // 0x8009C8C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009C8FC;
    // 0x8009C8C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009C8CC:
    // 0x8009C8CC: jal         0x8009C750
    // 0x8009C8D0: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    __yaw_update_limited(rdram, ctx);
        goto after_0;
    // 0x8009C8D0: lui         $a2, 0x40F0
    ctx->r6 = S32(0X40F0 << 16);
    after_0:
    // 0x8009C8D4: b           L_8009C8FC
    // 0x8009C8D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009C8FC;
    // 0x8009C8D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009C8DC:
    // 0x8009C8DC: jal         0x8009C5A8
    // 0x8009C8E0: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    __yaw_update_limitless(rdram, ctx);
        goto after_1;
    // 0x8009C8E0: lw          $a1, 0x10($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X10);
    after_1:
    // 0x8009C8E4: b           L_8009C8FC
    // 0x8009C8E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009C8FC;
    // 0x8009C8E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009C8EC: lw          $a1, 0x14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14);
L_8009C8F0:
    // 0x8009C8F0: jal         0x8009C750
    // 0x8009C8F4: lw          $a2, 0x18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X18);
    __yaw_update_limited(rdram, ctx);
        goto after_2;
    // 0x8009C8F4: lw          $a2, 0x18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X18);
    after_2:
    // 0x8009C8F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009C8FC:
    // 0x8009C8FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C900: jr          $ra
    // 0x8009C904: nop

    return;
    // 0x8009C904: nop

;}
RECOMP_FUNC void func_80013460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013460: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x80013464: lw          $v0, 0x69E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X69E8);
    // 0x80013468: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8001346C: jr          $ra
    // 0x80013470: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x80013470: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void func_800A3200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A3204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A3208: lw          $t6, 0xA0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA0);
    // 0x800A320C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A3210: addiu       $t8, $t8, -0x6BD0
    ctx->r24 = ADD32(ctx->r24, -0X6BD0);
    // 0x800A3214: lbu         $v0, 0x29($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X29);
    // 0x800A3218: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A321C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800A3220: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800A3224: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800A3228: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800A322C: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800A3230: bne         $v0, $at, L_800A3264
    if (ctx->r2 != ctx->r1) {
        // 0x800A3234: swc1        $f6, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
            goto L_800A3264;
    }
    // 0x800A3234: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800A3238: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A323C: jal         0x800850F8
    // 0x800A3240: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    _basnowball_entrypoint_4(rdram, ctx);
        goto after_0;
    // 0x800A3240: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800A3244: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800A3248: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800A324C: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800A3250: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800A3254: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x800A3258: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800A325C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800A3260: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
L_800A3264:
    // 0x800A3264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A3268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A326C: jr          $ra
    // 0x800A3270: nop

    return;
    // 0x800A3270: nop

;}
RECOMP_FUNC void func_80800540_chchuffycont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800540: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80800544: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800548: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x8080054C: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1704, 0XB20) << 16);
    // 0x80800550: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800554: addiu       $t7, $t7, 0xB20
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1704, 0XB20));
    // 0x80800558: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8080055C: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80800560: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80800564: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800568: addiu       $at, $zero, 0x12A
    ctx->r1 = ADD32(0, 0X12A);
    // 0x8080056C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80800570: bne         $t8, $at, L_80800598
    if (ctx->r24 != ctx->r1) {
        // 0x80800574: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80800598;
    }
    // 0x80800574: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800578: jal         0x800DA298
    // 0x8080057C: addiu       $a0, $zero, 0x171
    ctx->r4 = ADD32(0, 0X171);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x8080057C: addiu       $a0, $zero, 0x171
    ctx->r4 = ADD32(0, 0X171);
    after_0:
    // 0x80800580: bne         $v0, $zero, L_80800598
    if (ctx->r2 != 0) {
        // 0x80800584: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800598;
    }
    // 0x80800584: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800588: jal         0x80800000
    // 0x8080058C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80800000_chchuffycont(rdram, ctx);
        goto after_1;
    // 0x8080058C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80800590: b           L_80800610
    // 0x80800594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800610;
    // 0x80800594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800598:
    // 0x80800598: jal         0x800DA544
    // 0x8080059C: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    func_800DA544(rdram, ctx);
        goto after_2;
    // 0x8080059C: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    after_2:
    // 0x808005A0: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1704, 0XB20) << 16);
    // 0x808005A4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1704, 0XB66) << 16);
    // 0x808005A8: addiu       $s1, $s1, 0xB66
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1704, 0XB66));
    // 0x808005AC: addiu       $s0, $s0, 0xB20
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1704, 0XB20));
L_808005B0:
    // 0x808005B0: jal         0x800DA298
    // 0x808005B4: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808005B4: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_3:
    // 0x808005B8: bnel        $v0, $zero, L_808005D0
    if (ctx->r2 != 0) {
        // 0x808005BC: lh          $t9, 0x0($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X0);
            goto L_808005D0;
    }
    goto skip_0;
    // 0x808005BC: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    skip_0:
    // 0x808005C0: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x808005C4: bne         $s0, $s1, L_808005B0
    if (ctx->r16 != ctx->r17) {
        // 0x808005C8: nop
    
            goto L_808005B0;
    }
    // 0x808005C8: nop

    // 0x808005CC: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
L_808005D0:
    // 0x808005D0: addiu       $at, $zero, 0xEC
    ctx->r1 = ADD32(0, 0XEC);
    // 0x808005D4: bne         $t9, $at, L_808005E4
    if (ctx->r25 != ctx->r1) {
        // 0x808005D8: nop
    
            goto L_808005E4;
    }
    // 0x808005D8: nop

    // 0x808005DC: jal         0x800DA544
    // 0x808005E0: addiu       $a0, $zero, 0x6E7
    ctx->r4 = ADD32(0, 0X6E7);
    func_800DA544(rdram, ctx);
        goto after_4;
    // 0x808005E0: addiu       $a0, $zero, 0x6E7
    ctx->r4 = ADD32(0, 0X6E7);
    after_4:
L_808005E4:
    // 0x808005E4: jal         0x800887A8
    // 0x808005E8: nop

    _glcutDll_entrypoint_0(rdram, ctx);
        goto after_5;
    // 0x808005E8: nop

    after_5:
    // 0x808005EC: jal         0x800887E0
    // 0x808005F0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    _glcutDll_entrypoint_7(rdram, ctx);
        goto after_6;
    // 0x808005F0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    after_6:
    // 0x808005F4: jal         0x800887F8
    // 0x808005F8: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    _glcutDll_entrypoint_10(rdram, ctx);
        goto after_7;
    // 0x808005F8: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    after_7:
    // 0x808005FC: jal         0x80088858
    // 0x80800600: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    _glcutDll_entrypoint_22(rdram, ctx);
        goto after_8;
    // 0x80800600: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    after_8:
    // 0x80800604: jal         0x80088828
    // 0x80800608: nop

    _glcutDll_entrypoint_16(rdram, ctx);
        goto after_9;
    // 0x80800608: nop

    after_9:
    // 0x8080060C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800610:
    // 0x80800610: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800614: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800618: jr          $ra
    // 0x8080061C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080061C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800AF5F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF5F0: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x800AF5F4: jr          $ra
    // 0x800AF5F8: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    return;
    // 0x800AF5F8: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
;}
RECOMP_FUNC void _bsbwhirl_entrypoint_26(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082E50: syscall     30
    recomp_syscall_handler(rdram, ctx, 0x80082E50);
    return;
    // 0x80082E54: addi        $t0, $zero, 0x68
    ctx->r8 = ADD32(0, 0X68);
;}
RECOMP_FUNC void batimer_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800148: lw          $t6, 0x13C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X13C);
    // 0x8080014C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80800150: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80800154: jr          $ra
    // 0x80800158: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    return;
    // 0x80800158: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
;}
RECOMP_FUNC void chjiggybeam_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(808, 0X70) << 16);
    // 0x80800004: jr          $ra
    // 0x80800008: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(808, 0X70));
    return;
    // 0x80800008: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(808, 0X70));
;}
RECOMP_FUNC void func_800E3DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E3DC0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800E3DC4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800E3DC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E3DCC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800E3DD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3DD4: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E3DD8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800E3DDC: jal         0x800CAB70
    // 0x800E3DE0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800CAB70(rdram, ctx);
        goto after_0;
    // 0x800E3DE0: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x800E3DE4: jal         0x800BCC58
    // 0x800E3DE8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    func_800BCC58(rdram, ctx);
        goto after_1;
    // 0x800E3DE8: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800E3DEC: beq         $v0, $zero, L_800E3E78
    if (ctx->r2 == 0) {
        // 0x800E3DF0: lw          $v1, 0x4C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X4C);
            goto L_800E3E78;
    }
    // 0x800E3DF0: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800E3DF4: bne         $v1, $zero, L_800E3E78
    if (ctx->r3 != 0) {
        // 0x800E3DF8: addiu       $a0, $sp, 0x3C
        ctx->r4 = ADD32(ctx->r29, 0X3C);
            goto L_800E3E78;
    }
    // 0x800E3DF8: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800E3DFC: jal         0x800EE88C
    // 0x800E3E00: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_800EE88C(rdram, ctx);
        goto after_2;
    // 0x800E3E00: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_2:
    // 0x800E3E04: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800E3E08: jal         0x800EE88C
    // 0x800E3E0C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    func_800EE88C(rdram, ctx);
        goto after_3;
    // 0x800E3E0C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x800E3E10: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800E3E14: jal         0x800BCC28
    // 0x800E3E18: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800BCC28(rdram, ctx);
        goto after_4;
    // 0x800E3E18: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_4:
    // 0x800E3E1C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800E3E20: jal         0x800BCC28
    // 0x800E3E24: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800BCC28(rdram, ctx);
        goto after_5;
    // 0x800E3E24: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_5:
    // 0x800E3E28: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x800E3E2C: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
    // 0x800E3E30: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
L_800E3E34:
    // 0x800E3E34: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800E3E38: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800E3E3C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800E3E40: nop

    // 0x800E3E44: bc1fl       L_800E3E58
    if (!c1cs) {
        // 0x800E3E48: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800E3E58;
    }
    goto skip_0;
    // 0x800E3E48: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_0:
    // 0x800E3E4C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800E3E50: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x800E3E54: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800E3E58:
    // 0x800E3E58: bne         $v0, $a0, L_800E3E34
    if (ctx->r2 != ctx->r4) {
        // 0x800E3E5C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_800E3E34;
    }
    // 0x800E3E5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800E3E60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3E64: lw          $a0, -0x2B00($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B00);
    // 0x800E3E68: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800E3E6C: jal         0x800CAA24
    // 0x800E3E70: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    func_800CAA24(rdram, ctx);
        goto after_6;
    // 0x800E3E70: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x800E3E74: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800E3E78:
    // 0x800E3E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E3E7C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800E3E80: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800E3E84: jr          $ra
    // 0x800E3E88: nop

    return;
    // 0x800E3E88: nop

;}
RECOMP_FUNC void func_800FC884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC884: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FC888: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC88C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC890: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC894: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800FC898: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FC89C: addiu       $s1, $s1, 0x59B0
    ctx->r17 = ADD32(ctx->r17, 0X59B0);
    // 0x800FC8A0: addiu       $s0, $s0, 0x57D0
    ctx->r16 = ADD32(ctx->r16, 0X57D0);
    // 0x800FC8A4: lh          $t6, 0x28($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X28);
L_800FC8A8:
    // 0x800FC8A8: bltzl       $t6, L_800FC8CC
    if (SIGNED(ctx->r14) < 0) {
        // 0x800FC8AC: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FC8CC;
    }
    goto skip_0;
    // 0x800FC8AC: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_0:
    // 0x800FC8B0: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800FC8B4: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800FC8B8: bnel        $t8, $zero, L_800FC8CC
    if (ctx->r24 != 0) {
        // 0x800FC8BC: addiu       $s0, $s0, 0x50
        ctx->r16 = ADD32(ctx->r16, 0X50);
            goto L_800FC8CC;
    }
    goto skip_1;
    // 0x800FC8BC: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
    skip_1:
    // 0x800FC8C0: jal         0x800FB774
    // 0x800FC8C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FB774(rdram, ctx);
        goto after_0;
    // 0x800FC8C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800FC8C8: addiu       $s0, $s0, 0x50
    ctx->r16 = ADD32(ctx->r16, 0X50);
L_800FC8CC:
    // 0x800FC8CC: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x800FC8D0: bnel        $at, $zero, L_800FC8A8
    if (ctx->r1 != 0) {
        // 0x800FC8D4: lh          $t6, 0x28($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X28);
            goto L_800FC8A8;
    }
    goto skip_2;
    // 0x800FC8D4: lh          $t6, 0x28($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X28);
    skip_2:
    // 0x800FC8D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC8DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC8E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC8E4: jr          $ra
    // 0x800FC8E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FC8E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80800E0C_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800E10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E14: jal         0x8009BC6C
    // 0x80800E18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x80800E18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800E1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E20: jal         0x8009BF5C
    // 0x80800E24: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8009BF5C(rdram, ctx);
        goto after_1;
    // 0x80800E24: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_1:
    // 0x80800E28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800E2C: jal         0x8009C4CC
    // 0x80800E30: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baroll_setIdeal(rdram, ctx);
        goto after_2;
    // 0x80800E30: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80800E34: jal         0x808000F0
    // 0x80800E38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsvan_entrypoint_0(rdram, ctx);
        goto after_3;
    // 0x80800E38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80800E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800E44: jr          $ra
    // 0x80800E48: nop

    return;
    // 0x80800E48: nop

;}
RECOMP_FUNC void _chmineprospector_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085CF8: syscall     228
    recomp_syscall_handler(rdram, ctx, 0x80085CF8);
    return;
    // 0x80085CFC: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void func_80801964_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80801968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8080196C: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80801970: addiu       $a2, $zero, 0xBB
    ctx->r6 = ADD32(0, 0XBB);
    // 0x80801974: jal         0x80084C50
    // 0x80801978: addiu       $a3, $a0, 0x15C
    ctx->r7 = ADD32(ctx->r4, 0X15C);
    _bafly_entrypoint_17(rdram, ctx);
        goto after_0;
    // 0x80801978: addiu       $a3, $a0, 0x15C
    ctx->r7 = ADD32(ctx->r4, 0X15C);
    after_0:
    // 0x8080197C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80801980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801984: jr          $ra
    // 0x80801988: nop

    return;
    // 0x80801988: nop

;}
RECOMP_FUNC void func_808009D8_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808009DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808009E4: jal         0x80100094
    // 0x808009E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808009E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808009EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808009F0: jal         0x80800B90
    // 0x808009F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80800B90_chquiz(rdram, ctx);
        goto after_1;
    // 0x808009F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x808009F8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808009FC: beq         $v0, $zero, L_80800A18
    if (ctx->r2 == 0) {
        // 0x80800A00: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_80800A18;
    }
    // 0x80800A00: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80800A04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800A08: beq         $v0, $at, L_80800A40
    if (ctx->r2 == ctx->r1) {
        // 0x80800A0C: addiu       $v1, $a2, -0x1A00
        ctx->r3 = ADD32(ctx->r6, -0X1A00);
            goto L_80800A40;
    }
    // 0x80800A0C: addiu       $v1, $a2, -0x1A00
    ctx->r3 = ADD32(ctx->r6, -0X1A00);
    // 0x80800A10: b           L_80800A64
    // 0x80800A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800A64;
    // 0x80800A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A18:
    // 0x80800A18: addiu       $v1, $a2, -0x1910
    ctx->r3 = ADD32(ctx->r6, -0X1910);
    // 0x80800A1C: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80800A20: addu        $a0, $a1, $t6
    ctx->r4 = ADD32(ctx->r5, ctx->r14);
    // 0x80800A24: lbu         $v0, 0x9C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9C);
    // 0x80800A28: andi        $t7, $v1, 0x7
    ctx->r15 = ctx->r3 & 0X7;
    // 0x80800A2C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80800A30: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x80800A34: or          $v0, $t9, $v0
    ctx->r2 = ctx->r25 | ctx->r2;
    // 0x80800A38: b           L_80800A60
    // 0x80800A3C: sb          $v0, 0x9C($a0)
    MEM_B(0X9C, ctx->r4) = ctx->r2;
        goto L_80800A60;
    // 0x80800A3C: sb          $v0, 0x9C($a0)
    MEM_B(0X9C, ctx->r4) = ctx->r2;
L_80800A40:
    // 0x80800A40: sra         $t0, $v1, 3
    ctx->r8 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80800A44: addu        $a0, $a1, $t0
    ctx->r4 = ADD32(ctx->r5, ctx->r8);
    // 0x80800A48: lbu         $v0, 0xBA($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XBA);
    // 0x80800A4C: andi        $t1, $v1, 0x7
    ctx->r9 = ctx->r3 & 0X7;
    // 0x80800A50: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80800A54: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80800A58: or          $v0, $t3, $v0
    ctx->r2 = ctx->r11 | ctx->r2;
    // 0x80800A5C: sb          $v0, 0xBA($a0)
    MEM_B(0XBA, ctx->r4) = ctx->r2;
L_80800A60:
    // 0x80800A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800A64:
    // 0x80800A64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800A68: jr          $ra
    // 0x80800A6C: nop

    return;
    // 0x80800A6C: nop

;}
RECOMP_FUNC void _gccollectDll_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088028: syscall     666
    recomp_syscall_handler(rdram, ctx, 0x80088028);
    return;
    // 0x8008802C: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808013D0_chmonsterinterior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808013D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808013D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808013DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808013E0: jal         0x80100094
    // 0x808013E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808013E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808013E8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x808013EC: lw          $t6, 0x2C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2C);
    // 0x808013F0: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x808013F4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x808013F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808013FC: jal         0x8010A3E8
    // 0x80801400: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_8010A3E8(rdram, ctx);
        goto after_1;
    // 0x80801400: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_1:
    // 0x80801404: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80801408: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8080140C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80801410: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80801414: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80801418: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1320, 0X1E30) << 16);
    // 0x8080141C: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    // 0x80801420: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80801424: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80801428: lwc1        $f10, 0x1E30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1E30));
    // 0x8080142C: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
    // 0x80801430: jal         0x80801ADC
    // 0x80801434: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801ADC_chmonsterinterior(rdram, ctx);
        goto after_2;
    // 0x80801434: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80801438: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x8080143C: jal         0x80801B7C
    // 0x80801440: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80801B7C_chmonsterinterior(rdram, ctx);
        goto after_3;
    // 0x80801440: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80801444: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80801448: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1320, 0X1E34) << 16);
    // 0x8080144C: lwc1        $f12, 0x1E34($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1E34));
    // 0x80801450: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1320, 0X1E38) << 16);
    // 0x80801454: jal         0x800DC178
    // 0x80801458: lwc1        $f14, 0x1E38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1E38));
    func_800DC178(rdram, ctx);
        goto after_4;
    // 0x80801458: lwc1        $f14, 0x1E38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1320, 0X1E38));
    after_4:
    // 0x8080145C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80801460: jal         0x80102FDC
    // 0x80801464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102FDC(rdram, ctx);
        goto after_5;
    // 0x80801464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80801468: jal         0x8008A498
    // 0x8080146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddieDll_entrypoint_1(rdram, ctx);
        goto after_6;
    // 0x8080146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80801470: addiu       $a2, $s0, 0x4
    ctx->r6 = ADD32(ctx->r16, 0X4);
    // 0x80801474: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80801478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080147C: jal         0x80089F70
    // 0x80801480: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    _subaddierouteDll_entrypoint_3(rdram, ctx);
        goto after_7;
    // 0x80801480: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80801484: jal         0x80089F60
    // 0x80801488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _subaddierouteDll_entrypoint_1(rdram, ctx);
        goto after_8;
    // 0x80801488: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8080148C: lw          $t7, 0x64($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X64);
    // 0x80801490: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80801494: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(1320, 0X201C) << 16);
    // 0x80801498: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8080149C: bgezl       $t9, L_808014C0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808014A0: lw          $a1, 0x70($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X70);
            goto L_808014C0;
    }
    goto skip_0;
    // 0x808014A0: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    skip_0:
    // 0x808014A4: lbu         $t0, 0x64($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X64);
    // 0x808014A8: lui         $at, 0x40B0
    ctx->r1 = S32(0X40B0 << 16);
    // 0x808014AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808014B0: andi        $t1, $t0, 0xFFFE
    ctx->r9 = ctx->r8 & 0XFFFE;
    // 0x808014B4: sb          $t1, 0x64($s0)
    MEM_B(0X64, ctx->r16) = ctx->r9;
    // 0x808014B8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x808014BC: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
L_808014C0:
    // 0x808014C0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808014C4: addiu       $a3, $a3, 0x201C
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(1320, 0X201C));
    // 0x808014C8: andi        $t2, $a1, 0x1
    ctx->r10 = ctx->r5 & 0X1;
    // 0x808014CC: jal         0x8010D930
    // 0x808014D0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_8010D930(rdram, ctx);
        goto after_9;
    // 0x808014D0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_9:
    // 0x808014D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808014D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808014DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x808014E0: jr          $ra
    // 0x808014E4: nop

    return;
    // 0x808014E4: nop

;}
RECOMP_FUNC void func_80808B8C_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80808B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80808B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80808B94: jal         0x80802444
    // 0x80808B98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80802444_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x80808B98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80808B9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80808BA0: bne         $v0, $v1, L_80808BCC
    if (ctx->r2 != ctx->r3) {
        // 0x80808BA4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80808BCC;
    }
    // 0x80808BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80808BA8: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80808BAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80808BB0: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80808BB4: bnel        $at, $zero, L_80808C3C
    if (ctx->r1 != 0) {
        // 0x80808BB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80808C3C;
    }
    goto skip_0;
    // 0x80808BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80808BBC: jal         0x80808CAC
    // 0x80808BC0: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    func_80808CAC_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80808BC0: sw          $zero, 0x160($a0)
    MEM_W(0X160, ctx->r4) = 0;
    after_1:
    // 0x80808BC4: b           L_80808C3C
    // 0x80808BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80808C3C;
    // 0x80808BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80808BCC:
    // 0x80808BCC: lw          $v0, 0x15C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X15C);
    // 0x80808BD0: beql        $v0, $zero, L_80808C3C
    if (ctx->r2 == 0) {
        // 0x80808BD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80808C3C;
    }
    goto skip_1;
    // 0x80808BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80808BD8: bne         $v0, $v1, L_80808C20
    if (ctx->r2 != ctx->r3) {
        // 0x80808BDC: nop
    
            goto L_80808C20;
    }
    // 0x80808BDC: nop

    // 0x80808BE0: jal         0x800D9004
    // 0x80808BE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800D9004(rdram, ctx);
        goto after_2;
    // 0x80808BE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80808BE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80808BEC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80808BF0: lwc1        $f4, 0x16C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X16C);
    // 0x80808BF4: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80808BF8: swc1        $f6, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = ctx->f6.u32l;
    // 0x80808BFC: lwc1        $f8, 0x16C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X16C);
    // 0x80808C00: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80808C04: nop

    // 0x80808C08: bc1fl       L_80808C3C
    if (!c1cs) {
        // 0x80808C0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80808C3C;
    }
    goto skip_2;
    // 0x80808C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80808C10: jal         0x80808CAC
    // 0x80808C14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80808CAC_bsfirstp(rdram, ctx);
        goto after_3;
    // 0x80808C14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80808C18: b           L_80808C3C
    // 0x80808C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80808C3C;
    // 0x80808C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80808C20:
    // 0x80808C20: jal         0x80800228
    // 0x80808C24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80800228_bsfirstp(rdram, ctx);
        goto after_4;
    // 0x80808C24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_4:
    // 0x80808C28: beq         $v0, $zero, L_80808C38
    if (ctx->r2 == 0) {
        // 0x80808C2C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80808C38;
    }
    // 0x80808C2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80808C30: jal         0x80808CAC
    // 0x80808C34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80808CAC_bsfirstp(rdram, ctx);
        goto after_5;
    // 0x80808C34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
L_80808C38:
    // 0x80808C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80808C3C:
    // 0x80808C3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80808C40: jr          $ra
    // 0x80808C44: nop

    return;
    // 0x80808C44: nop

;}
RECOMP_FUNC void _bstaxi_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083DF0: syscall     96
    recomp_syscall_handler(rdram, ctx, 0x80083DF0);
    return;
    // 0x80083DF4: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void chchuffycont_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808007C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808007C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x808007CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x808007D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808007D4: jal         0x800EA05C
    // 0x808007D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800EA05C(rdram, ctx);
        goto after_0;
    // 0x808007D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x808007DC: addiu       $s0, $zero, 0xD0
    ctx->r16 = ADD32(0, 0XD0);
    // 0x808007E0: bne         $v0, $s0, L_80800880
    if (ctx->r2 != ctx->r16) {
        // 0x808007E4: lui         $s1, 0x8080
        ctx->r17 = S32(RELOC_HI16(1704, 0XB66) << 16);
            goto L_80800880;
    }
    // 0x808007E4: lui         $s1, 0x8080
    ctx->r17 = S32(RELOC_HI16(1704, 0XB66) << 16);
    // 0x808007E8: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(1704, 0XB20) << 16);
    // 0x808007EC: addiu       $s0, $s0, 0xB20
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(1704, 0XB20));
    // 0x808007F0: addiu       $s1, $s1, 0xB66
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(1704, 0XB66));
L_808007F4:
    // 0x808007F4: jal         0x800DA298
    // 0x808007F8: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x808007F8: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_1:
    // 0x808007FC: bnel        $v0, $zero, L_80800814
    if (ctx->r2 != 0) {
        // 0x80800800: lh          $t6, 0x0($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X0);
            goto L_80800814;
    }
    goto skip_0;
    // 0x80800800: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    skip_0:
    // 0x80800804: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x80800808: bne         $s0, $s1, L_808007F4
    if (ctx->r16 != ctx->r17) {
        // 0x8080080C: nop
    
            goto L_808007F4;
    }
    // 0x8080080C: nop

    // 0x80800810: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
L_80800814:
    // 0x80800814: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80800818: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8080081C: addiu       $a0, $zero, 0x66B
    ctx->r4 = ADD32(0, 0X66B);
    // 0x80800820: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80800824: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80800828: jal         0x800DA298
    // 0x8080082C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    func_800DA298(rdram, ctx);
        goto after_2;
    // 0x8080082C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    after_2:
    // 0x80800830: beq         $v0, $zero, L_80800848
    if (ctx->r2 == 0) {
        // 0x80800834: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_80800848;
    }
    // 0x80800834: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80800838: jal         0x800A7A5C
    // 0x8080083C: nop

    func_800A7A5C(rdram, ctx);
        goto after_3;
    // 0x8080083C: nop

    after_3:
    // 0x80800840: b           L_80800870
    // 0x80800844: addiu       $a0, $zero, 0x66B
    ctx->r4 = ADD32(0, 0X66B);
        goto L_80800870;
    // 0x80800844: addiu       $a0, $zero, 0x66B
    ctx->r4 = ADD32(0, 0X66B);
L_80800848:
    // 0x80800848: jal         0x80088268
    // 0x8080084C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_4;
    // 0x8080084C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x80800850: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80800854: jal         0x80088268
    // 0x80800858: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x80800858: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    after_5:
    // 0x8080085C: beql        $v0, $s0, L_80800870
    if (ctx->r2 == ctx->r16) {
        // 0x80800860: addiu       $a0, $zero, 0x66B
        ctx->r4 = ADD32(0, 0X66B);
            goto L_80800870;
    }
    goto skip_1;
    // 0x80800860: addiu       $a0, $zero, 0x66B
    ctx->r4 = ADD32(0, 0X66B);
    skip_1:
    // 0x80800864: jal         0x800A8230
    // 0x80800868: nop

    func_800A8230(rdram, ctx);
        goto after_6;
    // 0x80800868: nop

    after_6:
    // 0x8080086C: addiu       $a0, $zero, 0x66B
    ctx->r4 = ADD32(0, 0X66B);
L_80800870:
    // 0x80800870: jal         0x800DA3B8
    // 0x80800874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800DA3B8(rdram, ctx);
        goto after_7;
    // 0x80800874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80800878: b           L_808008FC
    // 0x8080087C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008FC;
    // 0x8080087C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800880:
    // 0x80800880: jal         0x800EA05C
    // 0x80800884: nop

    func_800EA05C(rdram, ctx);
        goto after_8;
    // 0x80800884: nop

    after_8:
    // 0x80800888: lui         $v1, 0x8080
    ctx->r3 = S32(RELOC_HI16(1704, 0XB20) << 16);
    // 0x8080088C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(1704, 0XB66) << 16);
    // 0x80800890: addiu       $a0, $a0, 0xB66
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(1704, 0XB66));
    // 0x80800894: addiu       $v1, $v1, 0xB20
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(1704, 0XB20));
    // 0x80800898: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
L_8080089C:
    // 0x8080089C: beq         $v0, $t1, L_808008B0
    if (ctx->r2 == ctx->r9) {
        // 0x808008A0: nop
    
            goto L_808008B0;
    }
    // 0x808008A0: nop

    // 0x808008A4: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x808008A8: bnel        $v1, $a0, L_8080089C
    if (ctx->r3 != ctx->r4) {
        // 0x808008AC: lh          $t1, 0x0($v1)
        ctx->r9 = MEM_H(ctx->r3, 0X0);
            goto L_8080089C;
    }
    goto skip_2;
    // 0x808008AC: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    skip_2:
L_808008B0:
    // 0x808008B0: jal         0x800DA298
    // 0x808008B4: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    func_800DA298(rdram, ctx);
        goto after_9;
    // 0x808008B4: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    after_9:
    // 0x808008B8: beq         $v0, $zero, L_808008F8
    if (ctx->r2 == 0) {
        // 0x808008BC: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_808008F8;
    }
    // 0x808008BC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x808008C0: sw          $s0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r16;
    // 0x808008C4: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x808008C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x808008CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008D0: jal         0x80088268
    // 0x808008D4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    _gcsectionDll_entrypoint_4(rdram, ctx);
        goto after_10;
    // 0x808008D4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    after_10:
    // 0x808008D8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x808008DC: lbu         $t5, 0x762C($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X762C);
    // 0x808008E0: beq         $v0, $t5, L_808008F0
    if (ctx->r2 == ctx->r13) {
        // 0x808008E4: nop
    
            goto L_808008F0;
    }
    // 0x808008E4: nop

    // 0x808008E8: jal         0x800A8230
    // 0x808008EC: nop

    func_800A8230(rdram, ctx);
        goto after_11;
    // 0x808008EC: nop

    after_11:
L_808008F0:
    // 0x808008F0: b           L_808008FC
    // 0x808008F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808008FC;
    // 0x808008F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808008F8:
    // 0x808008F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808008FC:
    // 0x808008FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800900: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80800904: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80800908: jr          $ra
    // 0x8080090C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8080090C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void suquiz_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808005E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808005E8: jal         0x800DA298
    // 0x808005EC: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808005EC: addiu       $a0, $zero, 0x6B6
    ctx->r4 = ADD32(0, 0X6B6);
    after_0:
    // 0x808005F0: beq         $v0, $zero, L_80800610
    if (ctx->r2 == 0) {
        // 0x808005F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800610;
    }
    // 0x808005F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808005F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x808005FC: lw          $t6, 0x7614($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7614);
    // 0x80800600: lb          $v0, 0x28($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X28);
    // 0x80800604: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80800608: b           L_80800614
    // 0x8080060C: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
        goto L_80800614;
    // 0x8080060C: sltu        $v0, $zero, $t7
    ctx->r2 = 0 < ctx->r15 ? 1 : 0;
L_80800610:
    // 0x80800610: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800614:
    // 0x80800614: jr          $ra
    // 0x80800618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80800618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800BA594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA594: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BA598: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800BA59C: swc1        $f12, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f12.u32l;
    // 0x800BA5A0: jr          $ra
    // 0x800BA5A4: swc1        $f14, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f14.u32l;
    return;
    // 0x800BA5A4: swc1        $f14, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f14.u32l;
;}
RECOMP_FUNC void func_80800700_chclockworkmouse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80800708: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8080070C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800710: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80800714: ori         $t6, $a2, 0x800
    ctx->r14 = ctx->r6 | 0X800;
    // 0x80800718: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8080071C: jal         0x800856B0
    // 0x80800720: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    _capod_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80800720: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_0:
    // 0x80800724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080072C: jr          $ra
    // 0x80800730: nop

    return;
    // 0x80800730: nop

;}
RECOMP_FUNC void babee_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002AC: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x808002B0: lbu         $t6, 0x1C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1C);
    // 0x808002B4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x808002B8: jr          $ra
    // 0x808002BC: sb          $t7, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r15;
    return;
    // 0x808002BC: sb          $t7, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_808015DC_bstrexsmall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808015DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808015E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808015E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808015E8: jal         0x808004CC
    // 0x808015EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstrexsmall_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x808015EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808015F0: lui         $a2, 0x3F33
    ctx->r6 = S32(0X3F33 << 16);
    // 0x808015F4: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x808015F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808015FC: jal         0x8008CB3C
    // 0x80801600: addiu       $a1, $zero, 0x1CF
    ctx->r5 = ADD32(0, 0X1CF);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x80801600: addiu       $a1, $zero, 0x1CF
    ctx->r5 = ADD32(0, 0X1CF);
    after_1:
    // 0x80801604: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80801608: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8080160C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801610: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801614: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80801618: jal         0x8009FFD8
    // 0x8080161C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x8080161C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80801620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801624: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x80801628: jal         0x8009C99C
    // 0x8080162C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    yaw_setVelocityBounded(rdram, ctx);
        goto after_3;
    // 0x8080162C: lui         $a2, 0x40D0
    ctx->r6 = S32(0X40D0 << 16);
    after_3:
    // 0x80801630: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80801634: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80801638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080163C: jal         0x8008C9BC
    // 0x80801640: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    baanim_setDurationRange(rdram, ctx);
        goto after_4;
    // 0x80801640: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_4:
    // 0x80801644: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(416, 0X1ADC) << 16);
    // 0x80801648: lwc1        $f4, 0x1ADC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(416, 0X1ADC));
    // 0x8080164C: lui         $a3, 0x3F5C
    ctx->r7 = S32(0X3F5C << 16);
    // 0x80801650: ori         $a3, $a3, 0x28F6
    ctx->r7 = ctx->r7 | 0X28F6;
    // 0x80801654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801658: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x8080165C: lui         $a2, 0x4416
    ctx->r6 = S32(0X4416 << 16);
    // 0x80801660: jal         0x8008C9F0
    // 0x80801664: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8008C9F0(rdram, ctx);
        goto after_5;
    // 0x80801664: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80801668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080166C: jal         0x8008CA30
    // 0x80801670: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_8008CA30(rdram, ctx);
        goto after_6;
    // 0x80801670: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_6:
    // 0x80801674: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80801678: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080167C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80801680: jr          $ra
    // 0x80801684: nop

    return;
    // 0x80801684: nop

;}
RECOMP_FUNC void func_808018D0_bskazfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808018D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808018D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808018D8: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x808018DC: jal         0x80084C38
    // 0x808018E0: addiu       $a2, $zero, 0xBB
    ctx->r6 = ADD32(0, 0XBB);
    _bafly_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x808018E0: addiu       $a2, $zero, 0xBB
    ctx->r6 = ADD32(0, 0XBB);
    after_0:
    // 0x808018E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808018E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808018EC: jr          $ra
    // 0x808018F0: nop

    return;
    // 0x808018F0: nop

;}
RECOMP_FUNC void func_801042D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801042D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801042DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801042E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801042E4: jal         0x80104200
    // 0x801042E8: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    func_80104200(rdram, ctx);
        goto after_0;
    // 0x801042E8: lh          $a0, 0x0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X0);
    after_0:
    // 0x801042EC: beq         $v0, $zero, L_80104318
    if (ctx->r2 == 0) {
        // 0x801042F0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80104318;
    }
    // 0x801042F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801042F4: jal         0x8008B5E8
    // 0x801042F8: nop

    func_8008B5E8(rdram, ctx);
        goto after_1;
    // 0x801042F8: nop

    after_1:
    // 0x801042FC: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80104300: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80104304: lw          $a0, 0x6E70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6E70);
    // 0x80104308: jal         0x800B32C0
    // 0x8010430C: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    freelist_erase(rdram, ctx);
        goto after_2;
    // 0x8010430C: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    after_2:
    // 0x80104310: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80104314: sh          $zero, 0x0($t8)
    MEM_H(0X0, ctx->r24) = 0;
L_80104318:
    // 0x80104318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010431C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80104320: jr          $ra
    // 0x80104324: nop

    return;
    // 0x80104324: nop

;}
RECOMP_FUNC void _subaddietaxi_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A550: syscall     844
    recomp_syscall_handler(rdram, ctx, 0x8008A550);
    return;
    // 0x8008A554: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void _chdinoswitches_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085FA8: syscall     267
    recomp_syscall_handler(rdram, ctx, 0x80085FA8);
    return;
    // 0x80085FAC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void func_808008D4_chmadamegrunty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808008D4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x808008D8: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x808008DC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808008E0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x808008E4: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x808008E8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x808008EC: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x808008F0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x808008F4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x808008F8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x808008FC: lwc1        $f22, 0x58($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80800900: jal         0x800D9078
    // 0x80800904: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    func_800D9078(rdram, ctx);
        goto after_0;
    // 0x80800904: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80800908: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8080090C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800910: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800914: lui         $s0, 0x8080
    ctx->r16 = S32(RELOC_HI16(916, 0XBE0) << 16);
    // 0x80800918: lui         $s2, 0x8080
    ctx->r18 = S32(RELOC_HI16(916, 0XC4C) << 16);
    // 0x8080091C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800920: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800924: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80800928: addiu       $s2, $s2, 0xC4C
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(916, 0XC4C));
    // 0x8080092C: addiu       $s0, $s0, 0xBE0
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(916, 0XBE0));
    // 0x80800930: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
L_80800934:
    // 0x80800934: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80800938: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080093C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80800940: jal         0x800F10B4
    // 0x80800944: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800944: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80800948: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8080094C: lwc1        $f12, 0x58($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80800950: jal         0x80800898
    // 0x80800954: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_80800898_chmadamegrunty(rdram, ctx);
        goto after_2;
    // 0x80800954: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_2:
    // 0x80800958: beq         $v0, $zero, L_8080096C
    if (ctx->r2 == 0) {
        // 0x8080095C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8080096C;
    }
    // 0x8080095C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800960: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80800964: jal         0x808009AC
    // 0x80800968: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    func_808009AC_chmadamegrunty(rdram, ctx);
        goto after_3;
    // 0x80800968: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_3:
L_8080096C:
    // 0x8080096C: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80800970: bnel        $s0, $s2, L_80800934
    if (ctx->r16 != ctx->r18) {
        // 0x80800974: mfc1        $a2, $f24
        ctx->r6 = (int32_t)ctx->f24.u32l;
            goto L_80800934;
    }
    goto skip_0;
    // 0x80800974: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    skip_0:
    // 0x80800978: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8080097C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80800980: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80800984: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80800988: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8080098C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80800990: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80800994: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80800998: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8080099C: sltiu       $t6, $v0, 0x1
    ctx->r14 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x808009A0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x808009A4: jr          $ra
    // 0x808009A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x808009A8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800E7254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E7254: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800E7258: beql        $v0, $zero, L_800E7288
    if (ctx->r2 == 0) {
        // 0x800E725C: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_800E7288;
    }
    goto skip_0;
    // 0x800E725C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_0:
    // 0x800E7260: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800E7264: beql        $v0, $v1, L_800E7288
    if (ctx->r2 == ctx->r3) {
        // 0x800E7268: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_800E7288;
    }
    goto skip_1;
    // 0x800E7268: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x800E726C: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
L_800E7270:
    // 0x800E7270: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800E7274: beql        $v0, $zero, L_800E7288
    if (ctx->r2 == 0) {
        // 0x800E7278: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_800E7288;
    }
    goto skip_2;
    // 0x800E7278: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_2:
    // 0x800E727C: bnel        $v0, $v1, L_800E7270
    if (ctx->r2 != ctx->r3) {
        // 0x800E7280: lbu         $v0, 0x1($a1)
        ctx->r2 = MEM_BU(ctx->r5, 0X1);
            goto L_800E7270;
    }
    goto skip_3;
    // 0x800E7280: lbu         $v0, 0x1($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1);
    skip_3:
    // 0x800E7284: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_800E7288:
    // 0x800E7288: bne         $v0, $t6, L_800E7294
    if (ctx->r2 != ctx->r14) {
        // 0x800E728C: nop
    
            goto L_800E7294;
    }
    // 0x800E728C: nop

    // 0x800E7290: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800E7294:
    // 0x800E7294: jr          $ra
    // 0x800E7298: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x800E7298: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void _chquizexitdoor_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087800: syscall     630
    recomp_syscall_handler(rdram, ctx, 0x80087800);
    return;
    // 0x80087804: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_800FB040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FB040: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800FB044: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800FB048: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800FB04C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FB050: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FB054: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x800FB058: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800FB05C: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x800FB060: jal         0x800EFB24
    // 0x800FB064: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x800FB064: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    after_0:
    // 0x800FB068: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    // 0x800FB06C: lw          $a1, 0x84($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X84);
    // 0x800FB070: jal         0x800EFB24
    // 0x800FB074: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    func_800EFB24(rdram, ctx);
        goto after_1;
    // 0x800FB074: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    after_1:
    // 0x800FB078: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x800FB07C: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x800FB080: jal         0x800EFB24
    // 0x800FB084: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x800FB084: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_2:
    // 0x800FB088: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800FB08C: jal         0x800EF410
    // 0x800FB090: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EF410(rdram, ctx);
        goto after_3;
    // 0x800FB090: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_3:
    // 0x800FB094: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800FB098: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x800FB09C: jal         0x800EF934
    // 0x800FB0A0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    func_800EF934(rdram, ctx);
        goto after_4;
    // 0x800FB0A0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    after_4:
    // 0x800FB0A4: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x800FB0A8: jal         0x800EEAA4
    // 0x800FB0AC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_800EEAA4(rdram, ctx);
        goto after_5;
    // 0x800FB0AC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x800FB0B0: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x800FB0B4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800FB0B8: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x800FB0BC: beq         $t6, $zero, L_800FB0D8
    if (ctx->r14 == 0) {
        // 0x800FB0C0: addiu       $a1, $sp, 0x30
        ctx->r5 = ADD32(ctx->r29, 0X30);
            goto L_800FB0D8;
    }
    // 0x800FB0C0: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800FB0C4: jal         0x800EEAA4
    // 0x800FB0C8: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    func_800EEAA4(rdram, ctx);
        goto after_6;
    // 0x800FB0C8: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x800FB0CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FB0D0: swc1        $f0, 0x57C0($at)
    MEM_W(0X57C0, ctx->r1) = ctx->f0.u32l;
    // 0x800FB0D4: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
L_800FB0D8:
    // 0x800FB0D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FB0DC: lwc1        $f4, 0x57C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X57C0);
    // 0x800FB0E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800FB0E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FB0E8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800FB0EC: nop

    // 0x800FB0F0: bc1fl       L_800FB10C
    if (!c1cs) {
        // 0x800FB0F4: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_800FB10C;
    }
    goto skip_0;
    // 0x800FB0F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x800FB0F8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800FB0FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800FB100: b           L_800FB110
    // 0x800FB104: nop

        goto L_800FB110;
    // 0x800FB104: nop

    // 0x800FB108: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_800FB10C:
    // 0x800FB10C: nop

L_800FB110:
    // 0x800FB110: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800FB114: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800FB118: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FB11C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800FB120: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x800FB124: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800FB128: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800FB12C: jal         0x800EF934
    // 0x800FB130: nop

    func_800EF934(rdram, ctx);
        goto after_7;
    // 0x800FB130: nop

    after_7:
    // 0x800FB134: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800FB138: jal         0x800EEAA4
    // 0x800FB13C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    func_800EEAA4(rdram, ctx);
        goto after_8;
    // 0x800FB13C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_8:
    // 0x800FB140: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800FB144: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800FB148: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x800FB14C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800FB150: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x800FB154: nop

    // 0x800FB158: bc1f        L_800FB164
    if (!c1cs) {
        // 0x800FB15C: nop
    
            goto L_800FB164;
    }
    // 0x800FB15C: nop

    // 0x800FB160: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_800FB164:
    // 0x800FB164: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800FB168: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800FB16C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800FB170: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800FB174: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800FB178: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x800FB17C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800FB180: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800FB184: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800FB188: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x800FB18C: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800FB190: mul.s       $f16, $f12, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800FB194: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800FB198: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x800FB19C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FB1A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FB1A4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x800FB1A8: jr          $ra
    // 0x800FB1AC: nop

    return;
    // 0x800FB1AC: nop

;}
RECOMP_FUNC void ncpod_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800E80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800E88: jal         0x80110024
    // 0x80800E8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80110024(rdram, ctx);
        goto after_0;
    // 0x80800E8C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80800E90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800E94: jal         0x808009E4
    // 0x80800E98: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    ncpod_entrypoint_17(rdram, ctx);
        goto after_1;
    // 0x80800E98: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80800E9C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80800EA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800EA4: jal         0x8010F9C0
    // 0x80800EA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8010F9C0(rdram, ctx);
        goto after_2;
    // 0x80800EA8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x80800EAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800EB0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80800EB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800EB8: jr          $ra
    // 0x80800EBC: nop

    return;
    // 0x80800EBC: nop

;}
RECOMP_FUNC void func_80800800_chcheatomenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800800: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800804: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80800808: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8080080C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800810: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800814: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80800818: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8080081C: addiu       $s2, $zero, 0xD
    ctx->r18 = ADD32(0, 0XD);
L_80800820:
    // 0x80800820: jal         0x800D3DD0
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D3DD0(rdram, ctx);
        goto after_0;
    // 0x80800824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80800828: bnel        $v0, $zero, L_80800844
    if (ctx->r2 != 0) {
        // 0x8080082C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80800844;
    }
    goto skip_0;
    // 0x8080082C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80800830: jal         0x800D3E14
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800D3E14(rdram, ctx);
        goto after_1;
    // 0x80800834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800838: beql        $v0, $zero, L_80800848
    if (ctx->r2 == 0) {
        // 0x8080083C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80800848;
    }
    goto skip_1;
    // 0x8080083C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80800840: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80800844:
    // 0x80800844: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80800848:
    // 0x80800848: bne         $s0, $s2, L_80800820
    if (ctx->r16 != ctx->r18) {
        // 0x8080084C: nop
    
            goto L_80800820;
    }
    // 0x8080084C: nop

    // 0x80800850: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800854: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80800858: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8080085C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800860: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80800864: jr          $ra
    // 0x80800868: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80800868: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080086C: nop

;}
RECOMP_FUNC void func_80800FF8_chevilmumbo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800FF8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80800FFC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80801000: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80801004: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80801008: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x8080100C: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80801010: jal         0x8008A0E0
    // 0x80801014: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_0;
    // 0x80801014: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x80801018: lui         $t6, 0x8080
    ctx->r14 = S32(RELOC_HI16(1676, 0X42A0) << 16);
    // 0x8080101C: addiu       $t6, $t6, 0x42A0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(1676, 0X42A0));
    // 0x80801020: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80801024: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80801028: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8080102C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80801030: jal         0x800BABB8
    // 0x80801034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800BABB8(rdram, ctx);
        goto after_1;
    // 0x80801034: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80801038: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8080103C: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80801040: addiu       $t0, $zero, -0x4B
    ctx->r8 = ADD32(0, -0X4B);
    // 0x80801044: addiu       $t1, $zero, 0xFA
    ctx->r9 = ADD32(0, 0XFA);
    // 0x80801048: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8080104C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80801050: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80801054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801058: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8080105C: addiu       $a1, $zero, -0x4B
    ctx->r5 = ADD32(0, -0X4B);
    // 0x80801060: addiu       $a3, $zero, 0x96
    ctx->r7 = ADD32(0, 0X96);
    // 0x80801064: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80801068: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8080106C: jal         0x800BA994
    // 0x80801070: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    func_800BA994(rdram, ctx);
        goto after_2;
    // 0x80801070: sw          $a2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r6;
    after_2:
    // 0x80801074: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801078: jal         0x800BA22C
    // 0x8080107C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_800BA22C(rdram, ctx);
        goto after_3;
    // 0x8080107C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_3:
    // 0x80801080: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80801084: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80801088: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1676, 0X3DE8) << 16);
    // 0x8080108C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80801090: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    // 0x80801094: jal         0x800DC298
    // 0x80801098: lwc1        $f12, 0x3DE8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3DE8));
    func_800DC298(rdram, ctx);
        goto after_4;
    // 0x80801098: lwc1        $f12, 0x3DE8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1676, 0X3DE8));
    after_4:
    // 0x8080109C: beql        $v0, $zero, L_808010B4
    if (ctx->r2 == 0) {
        // 0x808010A0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_808010B4;
    }
    goto skip_0;
    // 0x808010A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x808010A4: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x808010A8: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x808010AC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x808010B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_808010B4:
    // 0x808010B4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x808010B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808010BC: jr          $ra
    // 0x808010C0: nop

    return;
    // 0x808010C0: nop

;}
RECOMP_FUNC void func_80012F0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80012F10: lui         $at, 0x8007
    ctx->r1 = S32(0X8007 << 16);
    // 0x80012F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012F18: sh          $a0, -0x5E34($at)
    MEM_H(-0X5E34, ctx->r1) = ctx->r4;
    // 0x80012F1C: jal         0x80021A00
    // 0x80012F20: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    func_80021A00(rdram, ctx);
        goto after_0;
    // 0x80012F20: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_0:
    // 0x80012F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012F28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80012F2C: jr          $ra
    // 0x80012F30: nop

    return;
    // 0x80012F30: nop

;}
RECOMP_FUNC void func_808009F4_chdoor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x808009F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808009FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800A00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800A04: jal         0x80100094
    // 0x80800A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800A08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800A0C: lhu         $t6, 0x72($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X72);
    // 0x80800A10: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800A14: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x80800A18: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80800A1C: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x80800A20: beq         $at, $zero, L_80800B00
    if (ctx->r1 == 0) {
        // 0x80800A24: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80800B00;
    }
    // 0x80800A24: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80800A28: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1148, 0X156C) << 16);
    // 0x80800A2C: addu        $at, $at, $t8
    gpr jr_addend_80800A34 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80800A30: lw          $t8, 0x156C($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1148, 0X156C));
    // 0x80800A34: jr          $t8
    // 0x80800A38: nop

    switch (jr_addend_80800A34 >> 2) {
        case 0: goto L_80800A3C; break;
        case 1: goto L_80800A3C; break;
        case 2: goto L_80800AA0; break;
        case 3: goto L_80800ADC; break;
        case 4: goto L_80800ADC; break;
        case 5: goto L_80800A64; break;
        case 6: goto L_80800A3C; break;
        case 7: goto L_80800ADC; break;
        default: switch_error(__func__, 0x80800A34, 0x8080156C);
    }
    // 0x80800A38: nop

L_80800A3C:
    // 0x80800A3C: lh          $t9, 0xC($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XC);
    // 0x80800A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A44: sh          $t9, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r25;
    // 0x80800A48: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x80800A4C: jal         0x80800754
    // 0x80800A50: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80800754_chdoor(rdram, ctx);
        goto after_1;
    // 0x80800A50: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80800A54: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800A58: lh          $t0, 0x26($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X26);
    // 0x80800A5C: b           L_80800B00
    // 0x80800A60: sh          $t0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r8;
        goto L_80800B00;
    // 0x80800A60: sh          $t0, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r8;
L_80800A64:
    // 0x80800A64: lh          $t1, 0xA($v1)
    ctx->r9 = MEM_H(ctx->r3, 0XA);
    // 0x80800A68: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800A6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800A70: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80800A74: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800A7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800A80: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800A84: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80800A88: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80800A8C: jal         0x80800B14
    // 0x80800A90: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    func_80800B14_chdoor(rdram, ctx);
        goto after_2;
    // 0x80800A90: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80800A94: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800A98: b           L_80800B00
    // 0x80800A9C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80800B00;
    // 0x80800A9C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80800AA0:
    // 0x80800AA0: lh          $t2, 0xA($v1)
    ctx->r10 = MEM_H(ctx->r3, 0XA);
    // 0x80800AA4: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80800AA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800AAC: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80800AB0: lwc1        $f18, 0x58($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80800AB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AB8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80800ABC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80800AC0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80800AC4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80800AC8: jal         0x80800B14
    // 0x80800ACC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_80800B14_chdoor(rdram, ctx);
        goto after_3;
    // 0x80800ACC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x80800AD0: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80800AD4: b           L_80800B00
    // 0x80800AD8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
        goto L_80800B00;
    // 0x80800AD8: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
L_80800ADC:
    // 0x80800ADC: lh          $t3, 0xE($v1)
    ctx->r11 = MEM_H(ctx->r3, 0XE);
    // 0x80800AE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AE4: sh          $t3, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r11;
    // 0x80800AE8: sh          $zero, 0xE($v1)
    MEM_H(0XE, ctx->r3) = 0;
    // 0x80800AEC: jal         0x808008A0
    // 0x80800AF0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_808008A0_chdoor(rdram, ctx);
        goto after_4;
    // 0x80800AF0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_4:
    // 0x80800AF4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800AF8: lh          $t4, 0x26($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X26);
    // 0x80800AFC: sh          $t4, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r12;
L_80800B00:
    // 0x80800B00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800B04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800B08: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800B0C: jr          $ra
    // 0x80800B10: nop

    return;
    // 0x80800B10: nop

;}
RECOMP_FUNC void func_80800E64_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800E64: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800E6C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80800E70: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80800E74: jal         0x80100094
    // 0x80800E78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800E78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800E7C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80800E80: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80800E84: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80800E88: lhu         $t7, 0x72($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X72);
    // 0x80800E8C: addiu       $t0, $t9, -0x2
    ctx->r8 = ADD32(ctx->r25, -0X2);
    // 0x80800E90: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800E94: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x80800E98: beq         $t6, $t8, L_80801118
    if (ctx->r14 == ctx->r24) {
        // 0x80800E9C: sltiu       $at, $t0, 0xB
        ctx->r1 = ctx->r8 < 0XB ? 1 : 0;
            goto L_80801118;
    }
    // 0x80800E9C: sltiu       $at, $t0, 0xB
    ctx->r1 = ctx->r8 < 0XB ? 1 : 0;
    // 0x80800EA0: beq         $at, $zero, L_8080110C
    if (ctx->r1 == 0) {
        // 0x80800EA4: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8080110C;
    }
    // 0x80800EA4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80800EA8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2204, 0X2470) << 16);
    // 0x80800EAC: addu        $at, $at, $t0
    gpr jr_addend_80800EB4 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80800EB0: lw          $t0, 0x2470($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2204, 0X2470));
    // 0x80800EB4: jr          $t0
    // 0x80800EB8: nop

    switch (jr_addend_80800EB4 >> 2) {
        case 0: goto L_80800EBC; break;
        case 1: goto L_80800ED8; break;
        case 2: goto L_80800F40; break;
        case 3: goto L_80800F78; break;
        case 4: goto L_8080110C; break;
        case 5: goto L_80800F94; break;
        case 6: goto L_80800FB4; break;
        case 7: goto L_80801034; break;
        case 8: goto L_808010F4; break;
        case 9: goto L_80801088; break;
        case 10: goto L_808010FC; break;
        default: switch_error(__func__, 0x80800EB4, 0x80802470);
    }
    // 0x80800EB8: nop

L_80800EBC:
    // 0x80800EBC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80800EC0: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    // 0x80800EC4: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80800EC8: jal         0x800D2498
    // 0x80800ECC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800D2498(rdram, ctx);
        goto after_1;
    // 0x80800ECC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80800ED0: b           L_8080110C
    // 0x80800ED4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_8080110C;
    // 0x80800ED4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80800ED8:
    // 0x80800ED8: jal         0x80088178
    // 0x80800EDC: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    _gcfrontend_entrypoint_9(rdram, ctx);
        goto after_2;
    // 0x80800EDC: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_2:
    // 0x80800EE0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80800EE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800EE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800EEC: lhu         $v0, 0x76($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X76);
    // 0x80800EF0: srl         $t2, $v0, 7
    ctx->r10 = S32(U32(ctx->r2) >> 7);
    // 0x80800EF4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80800EF8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80800EFC: bgez        $t2, L_80800F10
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80800F00: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80800F10;
    }
    // 0x80800F00: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80800F04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800F08: nop

    // 0x80800F0C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80800F10:
    // 0x80800F10: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800F14: jal         0x800CE8D8
    // 0x80800F18: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800CE8D8(rdram, ctx);
        goto after_3;
    // 0x80800F18: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x80800F1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800F20: jal         0x800CE88C
    // 0x80800F24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800CE88C(rdram, ctx);
        goto after_4;
    // 0x80800F24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80800F28: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    // 0x80800F2C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80800F30: jal         0x80101180
    // 0x80800F34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_5;
    // 0x80800F34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x80800F38: b           L_8080110C
    // 0x80800F3C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_8080110C;
    // 0x80800F3C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80800F40:
    // 0x80800F40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800F44: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80800F48: jal         0x800FE820
    // 0x80800F4C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_800FE820(rdram, ctx);
        goto after_6;
    // 0x80800F4C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_6:
    // 0x80800F50: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80800F54: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80800F58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80800F5C: jal         0x8008A2F8
    // 0x80800F60: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_7;
    // 0x80800F60: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    after_7:
    // 0x80800F64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80800F68: jal         0x80801974
    // 0x80800F6C: addiu       $a1, $zero, 0xFA2
    ctx->r5 = ADD32(0, 0XFA2);
    func_80801974_chtntmineshoot(rdram, ctx);
        goto after_8;
    // 0x80800F6C: addiu       $a1, $zero, 0xFA2
    ctx->r5 = ADD32(0, 0XFA2);
    after_8:
    // 0x80800F70: b           L_8080110C
    // 0x80800F74: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_8080110C;
    // 0x80800F74: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80800F78:
    // 0x80800F78: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80800F7C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80800F80: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x80800F84: jal         0x8008A2F8
    // 0x80800F88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x80800F88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80800F8C: b           L_8080110C
    // 0x80800F90: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_8080110C;
    // 0x80800F90: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80800F94:
    // 0x80800F94: jal         0x8008A2F8
    // 0x80800F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    _susubgame_entrypoint_11(rdram, ctx);
        goto after_10;
    // 0x80800F98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80800F9C: jal         0x800D284C
    // 0x80800FA0: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_800D284C(rdram, ctx);
        goto after_11;
    // 0x80800FA0: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_11:
    // 0x80800FA4: jal         0x800D284C
    // 0x80800FA8: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    func_800D284C(rdram, ctx);
        goto after_12;
    // 0x80800FA8: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    after_12:
    // 0x80800FAC: b           L_8080110C
    // 0x80800FB0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_8080110C;
    // 0x80800FB0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80800FB4:
    // 0x80800FB4: jal         0x800F54E4
    // 0x80800FB8: nop

    func_800F54E4(rdram, ctx);
        goto after_13;
    // 0x80800FB8: nop

    after_13:
    // 0x80800FBC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80800FC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800FC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800FC8: jal         0x800F49D4
    // 0x80800FCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F49D4(rdram, ctx);
        goto after_14;
    // 0x80800FCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80800FD0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800FD4: jal         0x800F7B9C
    // 0x80800FD8: addiu       $a1, $zero, 0x8F
    ctx->r5 = ADD32(0, 0X8F);
    func_800F7B9C(rdram, ctx);
        goto after_15;
    // 0x80800FD8: addiu       $a1, $zero, 0x8F
    ctx->r5 = ADD32(0, 0X8F);
    after_15:
    // 0x80800FDC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800FE0: jal         0x800F7B9C
    // 0x80800FE4: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    func_800F7B9C(rdram, ctx);
        goto after_16;
    // 0x80800FE4: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    after_16:
    // 0x80800FE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80800FEC: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    // 0x80800FF0: jal         0x800F7C58
    // 0x80800FF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800F7C58(rdram, ctx);
        goto after_17;
    // 0x80800FF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x80800FF8: jal         0x800D211C
    // 0x80800FFC: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    func_800D211C(rdram, ctx);
        goto after_18;
    // 0x80800FFC: addiu       $a0, $zero, 0x95
    ctx->r4 = ADD32(0, 0X95);
    after_18:
    // 0x80801000: beq         $v0, $zero, L_80801010
    if (ctx->r2 == 0) {
        // 0x80801004: addiu       $a1, $zero, 0xCEC
        ctx->r5 = ADD32(0, 0XCEC);
            goto L_80801010;
    }
    // 0x80801004: addiu       $a1, $zero, 0xCEC
    ctx->r5 = ADD32(0, 0XCEC);
    // 0x80801008: b           L_80801010
    // 0x8080100C: addiu       $a1, $zero, 0xFB3
    ctx->r5 = ADD32(0, 0XFB3);
        goto L_80801010;
    // 0x8080100C: addiu       $a1, $zero, 0xFB3
    ctx->r5 = ADD32(0, 0XFB3);
L_80801010:
    // 0x80801010: jal         0x80801974
    // 0x80801014: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80801974_chtntmineshoot(rdram, ctx);
        goto after_19;
    // 0x80801014: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_19:
    // 0x80801018: jal         0x800F54E4
    // 0x8080101C: nop

    func_800F54E4(rdram, ctx);
        goto after_20;
    // 0x8080101C: nop

    after_20:
    // 0x80801020: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801024: jal         0x800F7F98
    // 0x80801028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_21;
    // 0x80801028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x8080102C: b           L_8080110C
    // 0x80801030: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_8080110C;
    // 0x80801030: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80801034:
    // 0x80801034: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80801038: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8080103C: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    // 0x80801040: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80801044: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80801048: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8080104C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801050: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80801054: jal         0x800D2498
    // 0x80801058: nop

    func_800D2498(rdram, ctx);
        goto after_22;
    // 0x80801058: nop

    after_22:
    // 0x8080105C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80801060: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    // 0x80801064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80801068: jal         0x800D2498
    // 0x8080106C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    func_800D2498(rdram, ctx);
        goto after_23;
    // 0x8080106C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_23:
    // 0x80801070: addiu       $a0, $zero, 0x2BE
    ctx->r4 = ADD32(0, 0X2BE);
    // 0x80801074: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80801078: jal         0x80101180
    // 0x8080107C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80101180(rdram, ctx);
        goto after_24;
    // 0x8080107C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_24:
    // 0x80801080: b           L_8080110C
    // 0x80801084: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_8080110C;
    // 0x80801084: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_80801088:
    // 0x80801088: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8080108C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80801090: addiu       $a1, $zero, 0x95
    ctx->r5 = ADD32(0, 0X95);
    // 0x80801094: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80801098: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8080109C: jal         0x800D2054
    // 0x808010A0: nop

    func_800D2054(rdram, ctx);
        goto after_25;
    // 0x808010A0: nop

    after_25:
    // 0x808010A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x808010A8: beq         $v0, $at, L_808010CC
    if (ctx->r2 == ctx->r1) {
        // 0x808010AC: addiu       $t6, $zero, 0xFB6
        ctx->r14 = ADD32(0, 0XFB6);
            goto L_808010CC;
    }
    // 0x808010AC: addiu       $t6, $zero, 0xFB6
    ctx->r14 = ADD32(0, 0XFB6);
    // 0x808010B0: beq         $v0, $zero, L_808010D4
    if (ctx->r2 == 0) {
        // 0x808010B4: addiu       $t8, $zero, 0xFB5
        ctx->r24 = ADD32(0, 0XFB5);
            goto L_808010D4;
    }
    // 0x808010B4: addiu       $t8, $zero, 0xFB5
    ctx->r24 = ADD32(0, 0XFB5);
    // 0x808010B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808010BC: beq         $v0, $at, L_808010DC
    if (ctx->r2 == ctx->r1) {
        // 0x808010C0: addiu       $t9, $zero, 0xFB4
        ctx->r25 = ADD32(0, 0XFB4);
            goto L_808010DC;
    }
    // 0x808010C0: addiu       $t9, $zero, 0xFB4
    ctx->r25 = ADD32(0, 0XFB4);
    // 0x808010C4: b           L_808010E4
    // 0x808010C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
        goto L_808010E4;
    // 0x808010C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_808010CC:
    // 0x808010CC: b           L_808010E0
    // 0x808010D0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
        goto L_808010E0;
    // 0x808010D0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_808010D4:
    // 0x808010D4: b           L_808010E0
    // 0x808010D8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
        goto L_808010E0;
    // 0x808010D8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
L_808010DC:
    // 0x808010DC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
L_808010E0:
    // 0x808010E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_808010E4:
    // 0x808010E4: jal         0x80801974
    // 0x808010E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80801974_chtntmineshoot(rdram, ctx);
        goto after_26;
    // 0x808010E8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_26:
    // 0x808010EC: b           L_8080110C
    // 0x808010F0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
        goto L_8080110C;
    // 0x808010F0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_808010F4:
    // 0x808010F4: b           L_8080110C
    // 0x808010F8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
        goto L_8080110C;
    // 0x808010F8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
L_808010FC:
    // 0x808010FC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801100: jal         0x80801974
    // 0x80801104: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    func_80801974_chtntmineshoot(rdram, ctx);
        goto after_27;
    // 0x80801104: addiu       $a1, $zero, 0xCEB
    ctx->r5 = ADD32(0, 0XCEB);
    after_27:
    // 0x80801108: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
L_8080110C:
    // 0x8080110C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80801110: jal         0x80101FDC
    // 0x80801114: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_80101FDC(rdram, ctx);
        goto after_28;
    // 0x80801114: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_28:
L_80801118:
    // 0x80801118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080111C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80801120: jr          $ra
    // 0x80801124: nop

    return;
    // 0x80801124: nop

;}
RECOMP_FUNC void func_808014A0_bsbswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808014A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808014A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808014A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808014AC: jal         0x800A0024
    // 0x808014B0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_800A0024(rdram, ctx);
        goto after_0;
    // 0x808014B0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x808014B4: jal         0x8008E35C
    // 0x808014B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    player_inWater(rdram, ctx);
        goto after_1;
    // 0x808014B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808014BC: bne         $v0, $zero, L_808014C8
    if (ctx->r2 != 0) {
        // 0x808014C0: addiu       $t6, $zero, 0x74
        ctx->r14 = ADD32(0, 0X74);
            goto L_808014C8;
    }
    // 0x808014C0: addiu       $t6, $zero, 0x74
    ctx->r14 = ADD32(0, 0X74);
    // 0x808014C4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
L_808014C8:
    // 0x808014C8: jal         0x8009CC68
    // 0x808014CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8009CC68(rdram, ctx);
        goto after_2;
    // 0x808014CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x808014D0: bne         $v0, $zero, L_808014DC
    if (ctx->r2 != 0) {
        // 0x808014D4: addiu       $t7, $zero, 0x2B
        ctx->r15 = ADD32(0, 0X2B);
            goto L_808014DC;
    }
    // 0x808014D4: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x808014D8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_808014DC:
    // 0x808014DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808014E0: jal         0x8009E5C8
    // 0x808014E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    bs_setState(rdram, ctx);
        goto after_3;
    // 0x808014E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x808014E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808014EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808014F0: jr          $ra
    // 0x808014F4: nop

    return;
    // 0x808014F4: nop

;}
RECOMP_FUNC void func_800F274C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F274C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F2750: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800F2754: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F2758: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800F275C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800F2760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F2764: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x800F2768: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800F276C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800F2770:
    // 0x800F2770: bnel        $v0, $zero, L_800F2784
    if (ctx->r2 != 0) {
        // 0x800F2774: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_800F2784;
    }
    goto skip_0;
    // 0x800F2774: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x800F2778: b           L_800F2784
    // 0x800F277C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_800F2784;
    // 0x800F277C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800F2780: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_800F2784:
    // 0x800F2784: bnel        $v0, $a0, L_800F2798
    if (ctx->r2 != ctx->r4) {
        // 0x800F2788: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_800F2798;
    }
    goto skip_1;
    // 0x800F2788: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x800F278C: b           L_800F2798
    // 0x800F2790: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_800F2798;
    // 0x800F2790: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x800F2794: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_800F2798:
    // 0x800F2798: bnel        $v0, $a1, L_800F27AC
    if (ctx->r2 != ctx->r5) {
        // 0x800F279C: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_800F27AC;
    }
    goto skip_2;
    // 0x800F279C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x800F27A0: b           L_800F27AC
    // 0x800F27A4: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_800F27AC;
    // 0x800F27A4: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x800F27A8: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_800F27AC:
    // 0x800F27AC: bnel        $v0, $a2, L_800F27C0
    if (ctx->r2 != ctx->r6) {
        // 0x800F27B0: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_800F27C0;
    }
    goto skip_3;
    // 0x800F27B0: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x800F27B4: b           L_800F27C0
    // 0x800F27B8: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_800F27C0;
    // 0x800F27B8: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x800F27BC: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_800F27C0:
    // 0x800F27C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F27C4: bne         $v0, $a3, L_800F2770
    if (ctx->r2 != ctx->r7) {
        // 0x800F27C8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800F2770;
    }
    // 0x800F27C8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800F27CC: jr          $ra
    // 0x800F27D0: nop

    return;
    // 0x800F27D0: nop

;}
RECOMP_FUNC void func_800F5DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5DC8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5DCC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5DD0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5DD4: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    // 0x800F5DD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F5DDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5DE0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800F5DE4: jal         0x8009BFD8
    // 0x800F5DE8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8009BFD8(rdram, ctx);
        goto after_0;
    // 0x800F5DE8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F5DEC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800F5DF0: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x800F5DF4: jal         0x8009C990
    // 0x800F5DF8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    yaw_getIdeal(rdram, ctx);
        goto after_1;
    // 0x800F5DF8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x800F5DFC: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800F5E00: swc1        $f0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f0.u32l;
    // 0x800F5E04: jal         0x8009C548
    // 0x800F5E08: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    baroll_getIdeal(rdram, ctx);
        goto after_2;
    // 0x800F5E08: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800F5E0C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800F5E10: swc1        $f0, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f0.u32l;
    // 0x800F5E14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5E18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F5E1C: jr          $ra
    // 0x800F5E20: nop

    return;
    // 0x800F5E20: nop

;}
RECOMP_FUNC void func_80804B60_chstoneballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80804B60: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80804B64: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1608, 0X5428) << 16);
    // 0x80804B68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80804B6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80804B70: addiu       $t7, $t7, 0x5428
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1608, 0X5428));
    // 0x80804B74: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80804B78: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80804B7C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80804B80: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80804B84: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80804B88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80804B8C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80804B90: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80804B94: jal         0x80106790
    // 0x80804B98: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_80106790(rdram, ctx);
        goto after_0;
    // 0x80804B98: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x80804B9C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80804BA0: lhu         $t1, 0x72($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X72);
    // 0x80804BA4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80804BA8: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x80804BAC: srl         $t2, $t1, 10
    ctx->r10 = S32(U32(ctx->r9) >> 10);
    // 0x80804BB0: beq         $t2, $at, L_80804C38
    if (ctx->r10 == ctx->r1) {
        // 0x80804BB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804C38;
    }
    // 0x80804BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804BB8: jal         0x80102D78
    // 0x80804BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80102D78(rdram, ctx);
        goto after_1;
    // 0x80804BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80804BC0: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80804BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804BC8: jal         0x80102CF4
    // 0x80804BCC: lui         $a1, 0x4370
    ctx->r5 = S32(0X4370 << 16);
    func_80102CF4(rdram, ctx);
        goto after_2;
    // 0x80804BCC: lui         $a1, 0x4370
    ctx->r5 = S32(0X4370 << 16);
    after_2:
    // 0x80804BD0: bne         $v0, $zero, L_80804BE8
    if (ctx->r2 != 0) {
        // 0x80804BD4: nop
    
            goto L_80804BE8;
    }
    // 0x80804BD4: nop

    // 0x80804BD8: jal         0x80804DA0
    // 0x80804BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804DA0_chstoneballcontrol(rdram, ctx);
        goto after_3;
    // 0x80804BDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80804BE0: b           L_80804BF4
    // 0x80804BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80804BF4;
    // 0x80804BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80804BE8:
    // 0x80804BE8: jal         0x80804D40
    // 0x80804BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804D40_chstoneballcontrol(rdram, ctx);
        goto after_4;
    // 0x80804BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80804BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80804BF4:
    // 0x80804BF4: jal         0x80102CF4
    // 0x80804BF8: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102CF4(rdram, ctx);
        goto after_5;
    // 0x80804BF8: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_5:
    // 0x80804BFC: bne         $v0, $zero, L_80804C18
    if (ctx->r2 != 0) {
        // 0x80804C00: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804C18;
    }
    // 0x80804C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C08: jal         0x80102B2C
    // 0x80804C0C: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102B2C(rdram, ctx);
        goto after_6;
    // 0x80804C0C: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_6:
    // 0x80804C10: b           L_80804C9C
    // 0x80804C14: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
        goto L_80804C9C;
    // 0x80804C14: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
L_80804C18:
    // 0x80804C18: jal         0x80102CF4
    // 0x80804C1C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102CF4(rdram, ctx);
        goto after_7;
    // 0x80804C1C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_7:
    // 0x80804C20: bne         $v0, $zero, L_80804C98
    if (ctx->r2 != 0) {
        // 0x80804C24: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804C98;
    }
    // 0x80804C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C28: jal         0x80102B2C
    // 0x80804C2C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102B2C(rdram, ctx);
        goto after_8;
    // 0x80804C2C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_8:
    // 0x80804C30: b           L_80804C9C
    // 0x80804C34: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
        goto L_80804C9C;
    // 0x80804C34: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
L_80804C38:
    // 0x80804C38: jal         0x80102CF4
    // 0x80804C3C: lui         $a1, 0x4200
    ctx->r5 = S32(0X4200 << 16);
    func_80102CF4(rdram, ctx);
        goto after_9;
    // 0x80804C3C: lui         $a1, 0x4200
    ctx->r5 = S32(0X4200 << 16);
    after_9:
    // 0x80804C40: bne         $v0, $zero, L_80804C5C
    if (ctx->r2 != 0) {
        // 0x80804C44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804C5C;
    }
    // 0x80804C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C4C: jal         0x80102B2C
    // 0x80804C50: lui         $a1, 0x4200
    ctx->r5 = S32(0X4200 << 16);
    func_80102B2C(rdram, ctx);
        goto after_10;
    // 0x80804C50: lui         $a1, 0x4200
    ctx->r5 = S32(0X4200 << 16);
    after_10:
    // 0x80804C54: b           L_80804C9C
    // 0x80804C58: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
        goto L_80804C9C;
    // 0x80804C58: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
L_80804C5C:
    // 0x80804C5C: jal         0x80102CF4
    // 0x80804C60: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102CF4(rdram, ctx);
        goto after_11;
    // 0x80804C60: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_11:
    // 0x80804C64: bne         $v0, $zero, L_80804C80
    if (ctx->r2 != 0) {
        // 0x80804C68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804C80;
    }
    // 0x80804C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C70: jal         0x80102B2C
    // 0x80804C74: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    func_80102B2C(rdram, ctx);
        goto after_12;
    // 0x80804C74: lui         $a1, 0x4180
    ctx->r5 = S32(0X4180 << 16);
    after_12:
    // 0x80804C78: b           L_80804C9C
    // 0x80804C7C: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
        goto L_80804C9C;
    // 0x80804C7C: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
L_80804C80:
    // 0x80804C80: jal         0x80102CF4
    // 0x80804C84: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102CF4(rdram, ctx);
        goto after_13;
    // 0x80804C84: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_13:
    // 0x80804C88: bne         $v0, $zero, L_80804C98
    if (ctx->r2 != 0) {
        // 0x80804C8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80804C98;
    }
    // 0x80804C8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80804C90: jal         0x80102B2C
    // 0x80804C94: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    func_80102B2C(rdram, ctx);
        goto after_14;
    // 0x80804C94: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    after_14:
L_80804C98:
    // 0x80804C98: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
L_80804C9C:
    // 0x80804C9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80804CA0: andi        $t3, $a1, 0x1FF
    ctx->r11 = ctx->r5 & 0X1FF;
    // 0x80804CA4: jal         0x80089AF8
    // 0x80804CA8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    _sukickball_entrypoint_12(rdram, ctx);
        goto after_15;
    // 0x80804CA8: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_15:
    // 0x80804CAC: beq         $v0, $zero, L_80804CDC
    if (ctx->r2 == 0) {
        // 0x80804CB0: nop
    
            goto L_80804CDC;
    }
    // 0x80804CB0: nop

    // 0x80804CB4: jal         0x80800070
    // 0x80804CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800070_chstoneballcontrol(rdram, ctx);
        goto after_16;
    // 0x80804CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80804CBC: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80804CC0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80804CC4: nop

    // 0x80804CC8: bc1f        L_80804CDC
    if (!c1cs) {
        // 0x80804CCC: nop
    
            goto L_80804CDC;
    }
    // 0x80804CCC: nop

    // 0x80804CD0: jal         0x80800070
    // 0x80804CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800070_chstoneballcontrol(rdram, ctx);
        goto after_17;
    // 0x80804CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80804CD8: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
L_80804CDC:
    // 0x80804CDC: jal         0x800D8FF8
    // 0x80804CE0: nop

    func_800D8FF8(rdram, ctx);
        goto after_18;
    // 0x80804CE0: nop

    after_18:
    // 0x80804CE4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80804CE8: addiu       $a3, $s0, 0x28
    ctx->r7 = ADD32(ctx->r16, 0X28);
    // 0x80804CEC: lw          $a1, 0x48($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X48);
    // 0x80804CF0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80804CF4: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80804CF8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80804CFC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80804D00: jal         0x800EFCD8
    // 0x80804D04: nop

    func_800EFCD8(rdram, ctx);
        goto after_19;
    // 0x80804D04: nop

    after_19:
    // 0x80804D08: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80804D0C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80804D10: jal         0x800EE780
    // 0x80804D14: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800EE780(rdram, ctx);
        goto after_20;
    // 0x80804D14: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_20:
    // 0x80804D18: jal         0x80804304
    // 0x80804D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804304_chstoneballcontrol(rdram, ctx);
        goto after_21;
    // 0x80804D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80804D20: jal         0x800136E4
    // 0x80804D24: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    func_800136E4(rdram, ctx);
        goto after_22;
    // 0x80804D24: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    after_22:
    // 0x80804D28: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80804D2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80804D30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80804D34: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80804D38: jr          $ra
    // 0x80804D3C: nop

    return;
    // 0x80804D3C: nop

;}
RECOMP_FUNC void func_80800968_chnastycavemen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800968: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080096C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800970: jal         0x800EA090
    // 0x80800974: nop

    func_800EA090(rdram, ctx);
        goto after_0;
    // 0x80800974: nop

    after_0:
    // 0x80800978: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8080097C: lh          $t6, 0x75CA($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X75CA);
    // 0x80800980: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80800984: beq         $t6, $zero, L_808009A4
    if (ctx->r14 == 0) {
        // 0x80800988: nop
    
            goto L_808009A4;
    }
    // 0x80800988: nop

    // 0x8080098C: beq         $v0, $zero, L_808009AC
    if (ctx->r2 == 0) {
        // 0x80800990: lui         $a0, 0x1
        ctx->r4 = S32(0X1 << 16);
            goto L_808009AC;
    }
    // 0x80800990: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x80800994: jal         0x80090178
    // 0x80800998: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80090178(rdram, ctx);
        goto after_1;
    // 0x80800998: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8080099C: bne         $v0, $zero, L_808009AC
    if (ctx->r2 != 0) {
        // 0x808009A0: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_808009AC;
    }
    // 0x808009A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_808009A4:
    // 0x808009A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808009A8: sh          $v1, 0x75CA($at)
    MEM_H(0X75CA, ctx->r1) = ctx->r3;
L_808009AC:
    // 0x808009AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808009B4: jr          $ra
    // 0x808009B8: nop

    return;
    // 0x808009B8: nop

;}
RECOMP_FUNC void func_800F5310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5310: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5314: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F5318: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800F531C: addiu       $v0, $v0, 0x54B0
    ctx->r2 = ADD32(ctx->r2, 0X54B0);
    // 0x800F5320: addiu       $a0, $a0, 0x5490
    ctx->r4 = ADD32(ctx->r4, 0X5490);
    // 0x800F5324: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
L_800F5328:
    // 0x800F5328: beql        $t6, $zero, L_800F5338
    if (ctx->r14 == 0) {
        // 0x800F532C: lw          $t7, 0x4($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X4);
            goto L_800F5338;
    }
    goto skip_0;
    // 0x800F532C: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x800F5330: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F5334: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
L_800F5338:
    // 0x800F5338: beql        $t7, $zero, L_800F5348
    if (ctx->r15 == 0) {
        // 0x800F533C: lw          $t8, 0x8($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X8);
            goto L_800F5348;
    }
    goto skip_1;
    // 0x800F533C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x800F5340: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F5344: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
L_800F5348:
    // 0x800F5348: beql        $t8, $zero, L_800F5358
    if (ctx->r24 == 0) {
        // 0x800F534C: lw          $t9, 0xC($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XC);
            goto L_800F5358;
    }
    goto skip_2;
    // 0x800F534C: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    skip_2:
    // 0x800F5350: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F5354: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
L_800F5358:
    // 0x800F5358: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800F535C: beq         $t9, $zero, L_800F5368
    if (ctx->r25 == 0) {
        // 0x800F5360: nop
    
            goto L_800F5368;
    }
    // 0x800F5360: nop

    // 0x800F5364: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800F5368:
    // 0x800F5368: bnel        $a0, $v0, L_800F5328
    if (ctx->r4 != ctx->r2) {
        // 0x800F536C: lw          $t6, 0x0($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X0);
            goto L_800F5328;
    }
    goto skip_3;
    // 0x800F536C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    skip_3:
    // 0x800F5370: jr          $ra
    // 0x800F5374: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800F5374: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_800DAC08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAC08: jr          $ra
    // 0x800DAC0C: addiu       $v0, $zero, 0xB0
    ctx->r2 = ADD32(0, 0XB0);
    return;
    // 0x800DAC0C: addiu       $v0, $zero, 0xB0
    ctx->r2 = ADD32(0, 0XB0);
;}
RECOMP_FUNC void cic_read_response(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E11C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E124: jal         0x800319F0
    // 0x8001E128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    __osSiGetAccess_recomp(rdram, ctx);
        goto after_0;
    // 0x8001E128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001E12C: addiu       $t6, $zero, 0xFE
    ctx->r14 = ADD32(0, 0XFE);
    // 0x8001E130: lui         $at, 0x8008
    ctx->r1 = S32(0X8008 << 16);
    // 0x8001E134: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8001E138: sb          $t6, 0x10C0($at)
    MEM_B(0X10C0, ctx->r1) = ctx->r14;
    // 0x8001E13C: addiu       $a0, $a0, -0x27B0
    ctx->r4 = ADD32(ctx->r4, -0X27B0);
    // 0x8001E140: jal         0x8002E6E0
    // 0x8001E144: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x8001E144: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x8001E148: lui         $a1, 0x8008
    ctx->r5 = S32(0X8008 << 16);
    // 0x8001E14C: addiu       $a1, $a1, -0x27B0
    ctx->r5 = ADD32(ctx->r5, -0X27B0);
    // 0x8001E150: jal         0x80031A60
    // 0x8001E154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    __osSiRawStartDma_recomp(rdram, ctx);
        goto after_2;
    // 0x8001E154: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8001E158: jal         0x80031A34
    // 0x8001E15C: nop

    __osSiRelAccess_recomp(rdram, ctx);
        goto after_3;
    // 0x8001E15C: nop

    after_3:
    // 0x8001E160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E168: jr          $ra
    // 0x8001E16C: nop

    return;
    // 0x8001E16C: nop

;}
RECOMP_FUNC void _ncpoddialog_entrypoint_11(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089628: syscall     784
    recomp_syscall_handler(rdram, ctx, 0x80089628);
    return;
    // 0x8008962C: addi        $t0, $zero, 0x2C
    ctx->r8 = ADD32(0, 0X2C);
;}
RECOMP_FUNC void func_800D04A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D04A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D04A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D04A8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800D04AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800D04B0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D04B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D04B8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800D04BC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D04C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D04C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800D04C8: jal         0x800D0820
    // 0x800D04CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800D0820(rdram, ctx);
        goto after_0;
    // 0x800D04CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x800D04D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D04D4: jal         0x800D0894
    // 0x800D04D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_1;
    // 0x800D04D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x800D04DC: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D04E0: bne         $at, $zero, L_800D0518
    if (ctx->r1 != 0) {
        // 0x800D04E4: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_800D0518;
    }
    // 0x800D04E4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800D04E8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_800D04EC:
    // 0x800D04EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800D04F0: jal         0x800D046C
    // 0x800D04F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800D046C(rdram, ctx);
        goto after_2;
    // 0x800D04F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x800D04F8: bne         $v0, $s3, L_800D0504
    if (ctx->r2 != ctx->r19) {
        // 0x800D04FC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800D0504;
    }
    // 0x800D04FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D0500: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800D0504:
    // 0x800D0504: jal         0x800D0894
    // 0x800D0508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800D0894(rdram, ctx);
        goto after_3;
    // 0x800D0508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800D050C: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800D0510: beql        $at, $zero, L_800D04EC
    if (ctx->r1 == 0) {
        // 0x800D0514: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800D04EC;
    }
    goto skip_0;
    // 0x800D0514: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_0:
L_800D0518:
    // 0x800D0518: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800D051C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x800D0520: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D0524: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D0528: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D052C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D0530: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D0534: jr          $ra
    // 0x800D0538: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800D0538: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_808002CC_chfaircoinbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808002D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808002D4: lhu         $t6, 0x76($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X76);
    // 0x808002D8: lui         $t9, 0x8080
    ctx->r25 = S32(RELOC_HI16(2132, 0X3E4) << 16);
    // 0x808002DC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2132, 0X494) << 16);
    // 0x808002E0: srl         $t7, $t6, 7
    ctx->r15 = S32(U32(ctx->r14) >> 7);
    // 0x808002E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x808002E8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x808002EC: lw          $t9, 0x3E4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(2132, 0X3E4));
    // 0x808002F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808002F4: jal         0x80800000
    // 0x808002F8: sh          $t9, 0x494($at)
    MEM_H((int16_t)RELOC_LO16(2132, 0X494), ctx->r1) = ctx->r25;
    func_80800000_chfaircoinbox(rdram, ctx);
        goto after_0;
    // 0x808002F8: sh          $t9, 0x494($at)
    MEM_H((int16_t)RELOC_LO16(2132, 0X494), ctx->r1) = ctx->r25;
    after_0:
    // 0x808002FC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2132, 0X490) << 16);
    // 0x80800300: sh          $v0, 0x490($at)
    MEM_H((int16_t)RELOC_LO16(2132, 0X490), ctx->r1) = ctx->r2;
    // 0x80800304: jal         0x800DA298
    // 0x80800308: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    func_800DA298(rdram, ctx);
        goto after_1;
    // 0x80800308: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_1:
    // 0x8080030C: bne         $v0, $zero, L_80800348
    if (ctx->r2 != 0) {
        // 0x80800310: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_80800348;
    }
    // 0x80800310: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80800314: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80800318: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(2132, 0X490) << 16);
    // 0x8080031C: addiu       $a2, $a2, 0x490
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(2132, 0X490));
    // 0x80800320: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80800324: jal         0x8008A1E8
    // 0x80800328: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    _subaddiedialog_entrypoint_7(rdram, ctx);
        goto after_2;
    // 0x80800328: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x8080032C: beq         $v0, $zero, L_80800348
    if (ctx->r2 == 0) {
        // 0x80800330: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80800348;
    }
    // 0x80800330: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80800334: addiu       $at, $zero, 0x10B5
    ctx->r1 = ADD32(0, 0X10B5);
    // 0x80800338: beq         $v0, $at, L_80800340
    if (ctx->r2 == ctx->r1) {
        // 0x8080033C: nop
    
            goto L_80800340;
    }
    // 0x8080033C: nop

L_80800340:
    // 0x80800340: jal         0x80090734
    // 0x80800344: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80090734(rdram, ctx);
        goto after_3;
    // 0x80800344: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
L_80800348:
    // 0x80800348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080034C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800350: jr          $ra
    // 0x80800354: nop

    return;
    // 0x80800354: nop

;}
RECOMP_FUNC void bskazshoessuckspline_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808001B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808001B4: jal         0x800832E0
    // 0x808001B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _bskaz_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808001B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001BC: jal         0x808000A4
    // 0x808001C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_808000A4_bskazshoessuckspline(rdram, ctx);
        goto after_1;
    // 0x808001C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x808001C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001C8: jal         0x800834D8
    // 0x808001CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    _bskazmove_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x808001CC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x808001D0: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x808001D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808001DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808001E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x808001E4: jal         0x8009FFD8
    // 0x808001E8: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_8009FFD8(rdram, ctx);
        goto after_3;
    // 0x808001E8: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_3:
    // 0x808001EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808001F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808001F4: jr          $ra
    // 0x808001F8: nop

    return;
    // 0x808001F8: nop

;}
