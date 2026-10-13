#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void ncba1p_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808007EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808007F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808007F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808007F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808007FC: jal         0x800136E4
    // 0x80800800: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    func_800136E4(rdram, ctx);
        goto after_0;
    // 0x80800800: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    after_0:
    // 0x80800804: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80800808: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8080080C: swc1        $f0, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f0.u32l;
    // 0x80800810: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80800814: jal         0x800136E4
    // 0x80800818: lwc1        $f12, 0x4($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X4);
    func_800136E4(rdram, ctx);
        goto after_1;
    // 0x80800818: lwc1        $f12, 0x4($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X4);
    after_1:
    // 0x8080081C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80800820: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80800824: swc1        $f0, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f0.u32l;
    // 0x80800828: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8080082C: jal         0x800136E4
    // 0x80800830: lwc1        $f12, 0x8($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X8);
    func_800136E4(rdram, ctx);
        goto after_2;
    // 0x80800830: lwc1        $f12, 0x8($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X8);
    after_2:
    // 0x80800834: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80800838: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8080083C: swc1        $f0, 0x2C($t4)
    MEM_W(0X2C, ctx->r12) = ctx->f0.u32l;
    // 0x80800840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800848: jr          $ra
    // 0x8080084C: nop

    return;
    // 0x8080084C: nop

;}
RECOMP_FUNC void func_800CFC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CFC5C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800CFC60: lw          $t6, -0x51A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X51A0);
    // 0x800CFC64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800CFC68: subu        $a0, $a0, $t6
    ctx->r4 = SUB32(ctx->r4, ctx->r14);
    // 0x800CFC6C: bltz        $a0, L_800CFC84
    if (SIGNED(ctx->r4) < 0) {
        // 0x800CFC70: slti        $at, $a0, 0xA
        ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
            goto L_800CFC84;
    }
    // 0x800CFC70: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x800CFC74: beq         $at, $zero, L_800CFC84
    if (ctx->r1 == 0) {
        // 0x800CFC78: nop
    
            goto L_800CFC84;
    }
    // 0x800CFC78: nop

    // 0x800CFC7C: jr          $ra
    // 0x800CFC80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800CFC80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800CFC84:
    // 0x800CFC84: jr          $ra
    // 0x800CFC88: nop

    return;
    // 0x800CFC88: nop

;}
RECOMP_FUNC void func_8010EF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010EF70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010EF74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010EF78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010EF7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010EF80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8010EF84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8010EF88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8010EF8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8010EF90: jal         0x800DF8D4
    // 0x8010EF94: sw          $a0, 0x7210($at)
    MEM_W(0X7210, ctx->r1) = ctx->r4;
    func_800DF8D4(rdram, ctx);
        goto after_0;
    // 0x8010EF94: sw          $a0, 0x7210($at)
    MEM_W(0X7210, ctx->r1) = ctx->r4;
    after_0:
    // 0x8010EF98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010EF9C: sb          $v0, 0x7238($at)
    MEM_B(0X7238, ctx->r1) = ctx->r2;
    // 0x8010EFA0: jal         0x800DF8F8
    // 0x8010EFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800DF8F8(rdram, ctx);
        goto after_1;
    // 0x8010EFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8010EFA8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010EFAC: addiu       $a0, $a0, 0x7214
    ctx->r4 = ADD32(ctx->r4, 0X7214);
    // 0x8010EFB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8010EFB4: jal         0x800EFB24
    // 0x8010EFB8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_800EFB24(rdram, ctx);
        goto after_2;
    // 0x8010EFB8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8010EFBC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010EFC0: addiu       $a0, $a0, 0x7214
    ctx->r4 = ADD32(ctx->r4, 0X7214);
    // 0x8010EFC4: jal         0x800EF368
    // 0x8010EFC8: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    func_800EF368(rdram, ctx);
        goto after_3;
    // 0x8010EFC8: lui         $a1, 0xBF80
    ctx->r5 = S32(0XBF80 << 16);
    after_3:
    // 0x8010EFCC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8010EFD0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8010EFD4: addiu       $s0, $s0, 0x722C
    ctx->r16 = ADD32(ctx->r16, 0X722C);
    // 0x8010EFD8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8010EFDC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8010EFE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010EFE4: jal         0x800EFA4C
    // 0x8010EFE8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800EFA4C(rdram, ctx);
        goto after_4;
    // 0x8010EFE8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_4:
    // 0x8010EFEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010EFF0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010EFF4: addiu       $a2, $a2, 0x7214
    ctx->r6 = ADD32(ctx->r6, 0X7214);
    // 0x8010EFF8: addiu       $a0, $a0, 0x7220
    ctx->r4 = ADD32(ctx->r4, 0X7220);
    // 0x8010EFFC: jal         0x800EE97C
    // 0x8010F000: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE97C(rdram, ctx);
        goto after_5;
    // 0x8010F000: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x8010F004: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010F008: jal         0x800EF2A0
    // 0x8010F00C: addiu       $a0, $a0, 0x7220
    ctx->r4 = ADD32(ctx->r4, 0X7220);
    func_800EF2A0(rdram, ctx);
        goto after_6;
    // 0x8010F00C: addiu       $a0, $a0, 0x7220
    ctx->r4 = ADD32(ctx->r4, 0X7220);
    after_6:
    // 0x8010F010: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010F014: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010F018: addiu       $a2, $a2, 0x7220
    ctx->r6 = ADD32(ctx->r6, 0X7220);
    // 0x8010F01C: addiu       $a1, $a1, 0x7214
    ctx->r5 = ADD32(ctx->r5, 0X7214);
    // 0x8010F020: jal         0x800EE97C
    // 0x8010F024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EE97C(rdram, ctx);
        goto after_7;
    // 0x8010F024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8010F028: jal         0x800EF2A0
    // 0x8010F02C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_8;
    // 0x8010F02C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8010F030: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010F034: lbu         $t6, 0x7238($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7238);
    // 0x8010F038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010F03C: bnel        $t6, $zero, L_8010F060
    if (ctx->r14 != 0) {
        // 0x8010F040: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8010F060;
    }
    goto skip_0;
    // 0x8010F040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8010F044: jal         0x800192FC
    // 0x8010F048: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800192FC(rdram, ctx);
        goto after_9;
    // 0x8010F048: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
    // 0x8010F04C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010F050: addiu       $a0, $a0, 0x7220
    ctx->r4 = ADD32(ctx->r4, 0X7220);
    // 0x8010F054: jal         0x800192FC
    // 0x8010F058: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    func_800192FC(rdram, ctx);
        goto after_10;
    // 0x8010F058: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    after_10:
    // 0x8010F05C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8010F060:
    // 0x8010F060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010F064: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010F068: jr          $ra
    // 0x8010F06C: nop

    return;
    // 0x8010F06C: nop

;}
RECOMP_FUNC void func_808004A4_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808004A4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808004A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808004AC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808004B0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808004B4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808004B8: jal         0x80100094
    // 0x808004BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808004BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808004C0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x808004C4: lw          $t6, 0x64($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X64);
    // 0x808004C8: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x808004CC: bgez        $t8, L_808004E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x808004D0: nop
    
            goto L_808004E8;
    }
    // 0x808004D0: nop

    // 0x808004D4: jal         0x8010A624
    // 0x808004D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010A624(rdram, ctx);
        goto after_1;
    // 0x808004D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x808004DC: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x808004E0: b           L_80800534
    // 0x808004E4: lwc1        $f2, 0x30($t9)
    ctx->f2.u32l = MEM_W(ctx->r25, 0X30);
        goto L_80800534;
    // 0x808004E4: lwc1        $f2, 0x30($t9)
    ctx->f2.u32l = MEM_W(ctx->r25, 0X30);
L_808004E8:
    // 0x808004E8: jal         0x8010A63C
    // 0x808004EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8010A63C(rdram, ctx);
        goto after_2;
    // 0x808004EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x808004F0: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x808004F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x808004F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808004FC: lwc1        $f2, 0x30($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X30);
    // 0x80800500: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80800504: nop

    // 0x80800508: bc1fl       L_80800538
    if (!c1cs) {
        // 0x8080050C: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80800538;
    }
    goto skip_0;
    // 0x8080050C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    skip_0:
    // 0x80800510: jal         0x800D8FF8
    // 0x80800514: nop

    func_800D8FF8(rdram, ctx);
        goto after_3;
    // 0x80800514: nop

    after_3:
    // 0x80800518: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1630) << 16);
    // 0x8080051C: lwc1        $f8, 0x1630($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1630));
    // 0x80800520: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80800524: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80800528: lwc1        $f6, 0x30($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X30);
    // 0x8080052C: add.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80800530: swc1        $f2, 0x30($t1)
    MEM_W(0X30, ctx->r9) = ctx->f2.u32l;
L_80800534:
    // 0x80800534: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_80800538:
    // 0x80800538: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080053C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800540: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80800544: swc1        $f4, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f4.u32l;
    // 0x80800548: jal         0x80105A9C
    // 0x8080054C: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
    func_80105A9C(rdram, ctx);
        goto after_4;
    // 0x8080054C: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
    after_4:
    // 0x80800550: jal         0x80105834
    // 0x80800554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80105834(rdram, ctx);
        goto after_5;
    // 0x80800554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80800558: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8080055C: lwc1        $f12, 0x54($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X54);
    // 0x80800560: lwc1        $f14, 0x48($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80800564: jal         0x800F1DCC
    // 0x80800568: swc1        $f8, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f8.u32l;
    func_800F1DCC(rdram, ctx);
        goto after_6;
    // 0x80800568: swc1        $f8, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f8.u32l;
    after_6:
    // 0x8080056C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1634) << 16);
    // 0x80800570: lwc1        $f10, 0x1634($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1634));
    // 0x80800574: lwc1        $f6, 0x48($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80800578: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8080057C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800580: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80800584: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80800588: jal         0x8010262C
    // 0x8080058C: swc1        $f18, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f18.u32l;
    func_8010262C(rdram, ctx);
        goto after_7;
    // 0x8080058C: swc1        $f18, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f18.u32l;
    after_7:
    // 0x80800590: beq         $v0, $zero, L_80800638
    if (ctx->r2 == 0) {
        // 0x80800594: sw          $v0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r2;
            goto L_80800638;
    }
    // 0x80800594: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80800598: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8080059C: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
L_808005A0:
    // 0x808005A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1638) << 16);
    // 0x808005A4: lwc1        $f4, 0x1638($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1638));
    // 0x808005A8: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x808005AC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X163C) << 16);
    // 0x808005B0: addiu       $t2, $zero, 0x5A
    ctx->r10 = ADD32(0, 0X5A);
    // 0x808005B4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x808005B8: nop

    // 0x808005BC: bc1t        L_808005D4
    if (c1cs) {
        // 0x808005C0: nop
    
            goto L_808005D4;
    }
    // 0x808005C0: nop

    // 0x808005C4: lwc1        $f8, 0x163C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X163C));
    // 0x808005C8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x808005CC: nop

    // 0x808005D0: bc1f        L_808005E8
    if (!c1cs) {
        // 0x808005D4: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1776, 0X1640) << 16);
            goto L_808005E8;
    }
L_808005D4:
    // 0x808005D4: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1640) << 16);
    // 0x808005D8: lwc1        $f10, 0x1640($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1640));
    // 0x808005DC: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x808005E0: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x808005E4: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
L_808005E8:
    // 0x808005E8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x808005EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808005F0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x808005F4: subu        $a1, $t2, $s0
    ctx->r5 = SUB32(ctx->r10, ctx->r16);
    // 0x808005F8: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808005FC: andi        $t3, $a1, 0xFF
    ctx->r11 = ctx->r5 & 0XFF;
    // 0x80800600: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80800604: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80800608: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x8080060C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800610: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800614: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80800618: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8080061C: jal         0x800E0AFC
    // 0x80800620: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_8;
    // 0x80800620: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x80800624: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80800628: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8080062C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80800630: bne         $s0, $at, L_808005A0
    if (ctx->r16 != ctx->r1) {
        // 0x80800634: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_808005A0;
    }
    // 0x80800634: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80800638:
    // 0x80800638: lw          $t4, 0x74($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X74);
    // 0x8080063C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80800640: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80800644: bgezl       $t6, L_80800658
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80800648: lhu         $t7, 0x72($s1)
        ctx->r15 = MEM_HU(ctx->r17, 0X72);
            goto L_80800658;
    }
    goto skip_1;
    // 0x80800648: lhu         $t7, 0x72($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X72);
    skip_1:
    // 0x8080064C: jal         0x808003D4
    // 0x80800650: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808003D4_chtoothyfish(rdram, ctx);
        goto after_9;
    // 0x80800650: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80800654: lhu         $t7, 0x72($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X72);
L_80800658:
    // 0x80800658: srl         $t8, $t7, 10
    ctx->r24 = S32(U32(ctx->r15) >> 10);
    // 0x8080065C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80800660: sltiu       $at, $t9, 0x6
    ctx->r1 = ctx->r25 < 0X6 ? 1 : 0;
    // 0x80800664: beq         $at, $zero, L_80800880
    if (ctx->r1 == 0) {
        // 0x80800668: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80800880;
    }
    // 0x80800668: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8080066C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1644) << 16);
    // 0x80800670: addu        $at, $at, $t9
    gpr jr_addend_80800678 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80800674: lw          $t9, 0x1644($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1644));
    // 0x80800678: jr          $t9
    // 0x8080067C: nop

    switch (jr_addend_80800678 >> 2) {
        case 0: goto L_80800880; break;
        case 1: goto L_80800680; break;
        case 2: goto L_808006A8; break;
        case 3: goto L_808006CC; break;
        case 4: goto L_80800800; break;
        case 5: goto L_808007F0; break;
        default: switch_error(__func__, 0x80800678, 0x80801644);
    }
    // 0x8080067C: nop

L_80800680:
    // 0x80800680: lui         $a1, 0x3F7F
    ctx->r5 = S32(0X3F7F << 16);
    // 0x80800684: ori         $a1, $a1, 0xBE77
    ctx->r5 = ctx->r5 | 0XBE77;
    // 0x80800688: jal         0x80101E14
    // 0x8080068C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80101E14(rdram, ctx);
        goto after_10;
    // 0x8080068C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80800690: beq         $v0, $zero, L_80800880
    if (ctx->r2 == 0) {
        // 0x80800694: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800880;
    }
    // 0x80800694: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800698: jal         0x808000E8
    // 0x8080069C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_808000E8_chtoothyfish(rdram, ctx);
        goto after_11;
    // 0x8080069C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x808006A0: b           L_80800880
    // 0x808006A4: nop

        goto L_80800880;
    // 0x808006A4: nop

L_808006A8:
    // 0x808006A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006AC: jal         0x80101E14
    // 0x808006B0: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    func_80101E14(rdram, ctx);
        goto after_12;
    // 0x808006B0: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    after_12:
    // 0x808006B4: beq         $v0, $zero, L_80800880
    if (ctx->r2 == 0) {
        // 0x808006B8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800880;
    }
    // 0x808006B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808006BC: jal         0x808000E8
    // 0x808006C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808000E8_chtoothyfish(rdram, ctx);
        goto after_13;
    // 0x808006C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_13:
    // 0x808006C4: b           L_80800880
    // 0x808006C8: nop

        goto L_80800880;
    // 0x808006C8: nop

L_808006CC:
    // 0x808006CC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808006D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x808006D4: lwc1        $f8, 0x44($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X44);
    // 0x808006D8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x808006DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006E0: lwc1        $f18, 0x38($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X38);
    // 0x808006E4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x808006E8: addiu       $s0, $sp, 0x50
    ctx->r16 = ADD32(ctx->r29, 0X50);
    // 0x808006EC: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x808006F0: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x808006F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006F8: lw          $a2, 0x48($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X48);
    // 0x808006FC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80800700: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80800704: jal         0x800EEC30
    // 0x80800708: nop

    func_800EEC30(rdram, ctx);
        goto after_14;
    // 0x80800708: nop

    after_14:
    // 0x8080070C: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80800710: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80800714: jal         0x800EF04C
    // 0x80800718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800EF04C(rdram, ctx);
        goto after_15;
    // 0x80800718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8080071C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800720: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80800724: lwc1        $f0, 0x38($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800728: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8080072C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800730: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80800734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800738: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8080073C: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80800740: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80800744: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80800748: jal         0x80089F18
    // 0x8080074C: nop

    _sudeflect_entrypoint_0(rdram, ctx);
        goto after_16;
    // 0x8080074C: nop

    after_16:
    // 0x80800750: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80800754: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800758: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x8080075C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800760: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800764: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80800768: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8080076C: jal         0x8010CAC0
    // 0x80800770: nop

    func_8010CAC0(rdram, ctx);
        goto after_17;
    // 0x80800770: nop

    after_17:
    // 0x80800774: beq         $v0, $zero, L_80800880
    if (ctx->r2 == 0) {
        // 0x80800778: nop
    
            goto L_80800880;
    }
    // 0x80800778: nop

    // 0x8080077C: jal         0x800F8B88
    // 0x80800780: nop

    func_800F8B88(rdram, ctx);
        goto after_18;
    // 0x80800780: nop

    after_18:
    // 0x80800784: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800788: beq         $v0, $at, L_80800880
    if (ctx->r2 == ctx->r1) {
        // 0x8080078C: lw          $a0, 0x64($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X64);
            goto L_80800880;
    }
    // 0x8080078C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80800790: jal         0x800E39A8
    // 0x80800794: addiu       $a1, $a0, 0xC
    ctx->r5 = ADD32(ctx->r4, 0XC);
    func_800E39A8(rdram, ctx);
        goto after_19;
    // 0x80800794: addiu       $a1, $a0, 0xC
    ctx->r5 = ADD32(ctx->r4, 0XC);
    after_19:
    // 0x80800798: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8080079C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x808007A0: lwc1        $f16, 0x48($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X48);
    // 0x808007A4: addiu       $a0, $zero, 0xF8
    ctx->r4 = ADD32(0, 0XF8);
    // 0x808007A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x808007AC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x808007B0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x808007B4: jal         0x80087A78
    // 0x808007B8: nop

    _gcgoto_entrypoint_5(rdram, ctx);
        goto after_20;
    // 0x808007B8: nop

    after_20:
    // 0x808007BC: lbu         $t3, 0x65($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X65);
    // 0x808007C0: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x808007C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x808007C8: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x808007CC: sb          $t4, 0x65($s1)
    MEM_B(0X65, ctx->r17) = ctx->r12;
    // 0x808007D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808007D4: jal         0x80090358
    // 0x808007D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80090358(rdram, ctx);
        goto after_21;
    // 0x808007D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_21:
    // 0x808007DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808007E0: jal         0x808000E8
    // 0x808007E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_808000E8_chtoothyfish(rdram, ctx);
        goto after_22;
    // 0x808007E4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_22:
    // 0x808007E8: b           L_80800880
    // 0x808007EC: nop

        goto L_80800880;
    // 0x808007EC: nop

L_808007F0:
    // 0x808007F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x808007F4: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x808007F8: b           L_80800880
    // 0x808007FC: swc1        $f8, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f8.u32l;
        goto L_80800880;
    // 0x808007FC: swc1        $f8, 0x30($t5)
    MEM_W(0X30, ctx->r13) = ctx->f8.u32l;
L_80800800:
    // 0x80800800: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80800804: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800808: lwc1        $f10, 0x44($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X44);
    // 0x8080080C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80800810: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80800814: lwc1        $f4, 0x38($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800818: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8080081C: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
    // 0x80800820: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80800824: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80800828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080082C: lw          $a2, 0x48($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X48);
    // 0x80800830: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80800834: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80800838: jal         0x800EEC30
    // 0x8080083C: nop

    func_800EEC30(rdram, ctx);
        goto after_23;
    // 0x8080083C: nop

    after_23:
    // 0x80800840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800844: jal         0x800EF04C
    // 0x80800848: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    func_800EF04C(rdram, ctx);
        goto after_24;
    // 0x80800848: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    after_24:
    // 0x8080084C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80800850: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800854: lwc1        $f6, 0x38($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80800858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080085C: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80800860: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80800864: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80800868: jal         0x8010CAC0
    // 0x8080086C: nop

    func_8010CAC0(rdram, ctx);
        goto after_25;
    // 0x8080086C: nop

    after_25:
    // 0x80800870: bne         $v0, $zero, L_80800880
    if (ctx->r2 != 0) {
        // 0x80800874: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80800880;
    }
    // 0x80800874: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800878: jal         0x808000E8
    // 0x8080087C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_808000E8_chtoothyfish(rdram, ctx);
        goto after_26;
    // 0x8080087C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_26:
L_80800880:
    // 0x80800880: jal         0x808002DC
    // 0x80800884: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_808002DC_chtoothyfish(rdram, ctx);
        goto after_27;
    // 0x80800884: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x80800888: lw          $t7, 0x7C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X7C);
    // 0x8080088C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X165C) << 16);
    // 0x80800890: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x80800894: bgezl       $t9, L_808008F8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800898: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808008F8;
    }
    goto skip_2;
    // 0x80800898: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8080089C: jal         0x800DC298
    // 0x808008A0: lwc1        $f12, 0x165C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X165C));
    func_800DC298(rdram, ctx);
        goto after_28;
    // 0x808008A0: lwc1        $f12, 0x165C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X165C));
    after_28:
    // 0x808008A4: bnel        $v0, $zero, L_808008D0
    if (ctx->r2 != 0) {
        // 0x808008A8: addiu       $s0, $sp, 0x38
        ctx->r16 = ADD32(ctx->r29, 0X38);
            goto L_808008D0;
    }
    goto skip_3;
    // 0x808008A8: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    skip_3:
    // 0x808008AC: lhu         $t0, 0x72($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X72);
    // 0x808008B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808008B4: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x808008B8: bne         $t1, $at, L_808008F4
    if (ctx->r9 != ctx->r1) {
        // 0x808008BC: lui         $at, 0x8080
        ctx->r1 = S32(RELOC_HI16(1776, 0X1660) << 16);
            goto L_808008F4;
    }
    // 0x808008BC: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1776, 0X1660) << 16);
    // 0x808008C0: jal         0x800DC298
    // 0x808008C4: lwc1        $f12, 0x1660($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1660));
    func_800DC298(rdram, ctx);
        goto after_29;
    // 0x808008C4: lwc1        $f12, 0x1660($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1776, 0X1660));
    after_29:
    // 0x808008C8: beq         $v0, $zero, L_808008F4
    if (ctx->r2 == 0) {
        // 0x808008CC: addiu       $s0, $sp, 0x38
        ctx->r16 = ADD32(ctx->r29, 0X38);
            goto L_808008F4;
    }
    // 0x808008CC: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
L_808008D0:
    // 0x808008D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x808008D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x808008D8: jal         0x8008A0E0
    // 0x808008DC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    _subaddieskeleton_entrypoint_2(rdram, ctx);
        goto after_30;
    // 0x808008DC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_30:
    // 0x808008E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808008E4: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x808008E8: lw          $a2, 0x38($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X38);
    // 0x808008EC: jal         0x80800188
    // 0x808008F0: lw          $a3, 0x48($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X48);
    func_80800188_chtoothyfish(rdram, ctx);
        goto after_31;
    // 0x808008F0: lw          $a3, 0x48($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X48);
    after_31:
L_808008F4:
    // 0x808008F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808008F8:
    // 0x808008F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x808008FC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800900: jr          $ra
    // 0x80800904: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800904: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void gcwater_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800004: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800008: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080000C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80800010: jal         0x800BEB28
    // 0x80800014: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800BEB28(rdram, ctx);
        goto after_0;
    // 0x80800014: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80800018: beq         $v0, $zero, L_8080003C
    if (ctx->r2 == 0) {
        // 0x8080001C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080003C;
    }
    // 0x8080001C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800020: jal         0x800B2720
    // 0x80800024: nop

    func_800B2720(rdram, ctx);
        goto after_1;
    // 0x80800024: nop

    after_1:
    // 0x80800028: beq         $v0, $zero, L_8080003C
    if (ctx->r2 == 0) {
        // 0x8080002C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8080003C;
    }
    // 0x8080002C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800030: jal         0x800AAD80
    // 0x80800034: nop

    func_800AAD80(rdram, ctx);
        goto after_2;
    // 0x80800034: nop

    after_2:
    // 0x80800038: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8080003C:
    // 0x8080003C: bne         $s0, $zero, L_80800070
    if (ctx->r16 != 0) {
        // 0x80800040: nop
    
            goto L_80800070;
    }
    // 0x80800040: nop

    // 0x80800044: jal         0x800BEB28
    // 0x80800048: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800BEB28(rdram, ctx);
        goto after_3;
    // 0x80800048: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8080004C: beq         $v0, $zero, L_80800070
    if (ctx->r2 == 0) {
        // 0x80800050: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800070;
    }
    // 0x80800050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800054: jal         0x800B2720
    // 0x80800058: nop

    func_800B2720(rdram, ctx);
        goto after_4;
    // 0x80800058: nop

    after_4:
    // 0x8080005C: beq         $v0, $zero, L_80800070
    if (ctx->r2 == 0) {
        // 0x80800060: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80800070;
    }
    // 0x80800060: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800064: jal         0x800AAD80
    // 0x80800068: nop

    func_800AAD80(rdram, ctx);
        goto after_5;
    // 0x80800068: nop

    after_5:
    // 0x8080006C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80800070:
    // 0x80800070: beq         $s0, $zero, L_80800080
    if (ctx->r16 == 0) {
        // 0x80800074: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80800080;
    }
    // 0x80800074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800078: b           L_80800080
    // 0x8080007C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800080;
    // 0x8080007C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800080:
    // 0x80800080: jal         0x800DA3B8
    // 0x80800084: addiu       $a0, $zero, 0x6B5
    ctx->r4 = ADD32(0, 0X6B5);
    func_800DA3B8(rdram, ctx);
        goto after_6;
    // 0x80800084: addiu       $a0, $zero, 0x6B5
    ctx->r4 = ADD32(0, 0X6B5);
    after_6:
    // 0x80800088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080008C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800090: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800094: jr          $ra
    // 0x80800098: nop

    return;
    // 0x80800098: nop

    // 0x8080009C: nop

;}
RECOMP_FUNC void func_80800480_chdinofoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800480: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80800484: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800488: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080048C: jal         0x800F54E4
    // 0x80800490: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800490: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80800494: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800498: jal         0x800F6438
    // 0x8080049C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800F6438(rdram, ctx);
        goto after_1;
    // 0x8080049C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x808004A0: beq         $v0, $zero, L_808004B8
    if (ctx->r2 == 0) {
        // 0x808004A4: nop
    
            goto L_808004B8;
    }
    // 0x808004A4: nop

    // 0x808004A8: jal         0x800F6478
    // 0x808004AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_800F6478(rdram, ctx);
        goto after_2;
    // 0x808004AC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x808004B0: bne         $v0, $zero, L_808004C0
    if (ctx->r2 != 0) {
        // 0x808004B4: nop
    
            goto L_808004C0;
    }
    // 0x808004B4: nop

L_808004B8:
    // 0x808004B8: b           L_80800548
    // 0x808004BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800548;
    // 0x808004BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808004C0:
    // 0x808004C0: jal         0x800DA298
    // 0x808004C4: addiu       $a0, $zero, 0xC5
    ctx->r4 = ADD32(0, 0XC5);
    func_800DA298(rdram, ctx);
        goto after_3;
    // 0x808004C4: addiu       $a0, $zero, 0xC5
    ctx->r4 = ADD32(0, 0XC5);
    after_3:
    // 0x808004C8: bne         $v0, $zero, L_80800544
    if (ctx->r2 != 0) {
        // 0x808004CC: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80800544;
    }
    // 0x808004CC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x808004D0: jal         0x800F5A00
    // 0x808004D4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    func_800F5A00(rdram, ctx);
        goto after_4;
    // 0x808004D4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_4:
    // 0x808004D8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1040, 0X7CC) << 16);
    // 0x808004DC: lwc1        $f6, 0x7CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(1040, 0X7CC));
    // 0x808004E0: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x808004E4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x808004E8: nop

    // 0x808004EC: bc1f        L_8080053C
    if (!c1cs) {
        // 0x808004F0: nop
    
            goto L_8080053C;
    }
    // 0x808004F0: nop

    // 0x808004F4: jal         0x800DA544
    // 0x808004F8: addiu       $a0, $zero, 0xC5
    ctx->r4 = ADD32(0, 0XC5);
    func_800DA544(rdram, ctx);
        goto after_5;
    // 0x808004F8: addiu       $a0, $zero, 0xC5
    ctx->r4 = ADD32(0, 0XC5);
    after_5:
    // 0x808004FC: lbu         $t7, 0x65($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X65);
    // 0x80800500: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800504: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80800508: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8080050C: jal         0x80102424
    // 0x80800510: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    func_80102424(rdram, ctx);
        goto after_6;
    // 0x80800510: sb          $t8, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r24;
    after_6:
    // 0x80800514: lui         $at, 0x41AC
    ctx->r1 = S32(0X41AC << 16);
    // 0x80800518: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080051C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80800520: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800524: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800528: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8080052C: jal         0x80085708
    // 0x80800530: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    _capod_entrypoint_13(rdram, ctx);
        goto after_7;
    // 0x80800530: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_7:
    // 0x80800534: jal         0x800FDC28
    // 0x80800538: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800FDC28(rdram, ctx);
        goto after_8;
    // 0x80800538: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
L_8080053C:
    // 0x8080053C: b           L_80800548
    // 0x80800540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800548;
    // 0x80800540: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800544:
    // 0x80800544: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800548:
    // 0x80800548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080054C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800550: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80800554: jr          $ra
    // 0x80800558: nop

    return;
    // 0x80800558: nop

;}
RECOMP_FUNC void func_80116850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80116850: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80116854: ld          $a0, 0x4A70($a0)
    ctx->r4 = LD(ctx->r4, 0X4A70);
    // 0x80116858: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8011685C: dsll32      $a2, $a0, 31
    ctx->r6 = ctx->r4 << (31 + 32);
    // 0x80116860: dsll        $a1, $a0, 31
    ctx->r5 = ctx->r4 << 31;
    // 0x80116864: dsrl        $a2, $a2, 31
    ctx->r6 = ctx->r6 >> 31;
    // 0x80116868: dsrl32      $a1, $a1, 0
    ctx->r5 = ctx->r5 >> (0 + 32);
    // 0x8011686C: dsll32      $a0, $a0, 12
    ctx->r4 = ctx->r4 << (12 + 32);
    // 0x80116870: or          $a2, $a2, $a1
    ctx->r6 = ctx->r6 | ctx->r5;
    // 0x80116874: dsrl32      $a0, $a0, 0
    ctx->r4 = ctx->r4 >> (0 + 32);
    // 0x80116878: xor         $a2, $a2, $a0
    ctx->r6 = ctx->r6 ^ ctx->r4;
    // 0x8011687C: dsrl        $a0, $a2, 20
    ctx->r4 = ctx->r6 >> 20;
    // 0x80116880: andi        $a0, $a0, 0xFFF
    ctx->r4 = ctx->r4 & 0XFFF;
    // 0x80116884: xor         $a0, $a0, $a2
    ctx->r4 = ctx->r4 ^ ctx->r6;
    // 0x80116888: dsll32      $v0, $a0, 0
    ctx->r2 = ctx->r4 << (0 + 32);
    // 0x8011688C: sd          $a0, 0x4A70($at)
    SD(ctx->r4, 0X4A70, ctx->r1);
    // 0x80116890: jr          $ra
    // 0x80116894: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
    return;
    // 0x80116894: dsra32      $v0, $v0, 0
    ctx->r2 = SIGNED(ctx->r2) >> (0 + 32);
;}
RECOMP_FUNC void func_8010A764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A76C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010A770: jal         0x80100368
    // 0x8010A774: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80100368(rdram, ctx);
        goto after_0;
    // 0x8010A774: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8010A778: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8010A77C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8010A780: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8010A784: jalr        $t9
    // 0x8010A788: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8010A788: nop

    after_1:
    // 0x8010A78C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010A790: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A794: jr          $ra
    // 0x8010A798: nop

    return;
    // 0x8010A798: nop

;}
RECOMP_FUNC void func_8080076C_chfishshootgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080076C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800770: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800774: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80800778: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8080077C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80800780: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80800784: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80800788: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8080078C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80800790: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80800794: jal         0x80100094
    // 0x80800798: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800798: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8080079C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x808007A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808007A4: slti        $at, $a3, 0x1026
    ctx->r1 = SIGNED(ctx->r7) < 0X1026 ? 1 : 0;
    // 0x808007A8: bne         $at, $zero, L_808007E0
    if (ctx->r1 != 0) {
        // 0x808007AC: addiu       $at, $zero, 0x1026
        ctx->r1 = ADD32(0, 0X1026);
            goto L_808007E0;
    }
    // 0x808007AC: addiu       $at, $zero, 0x1026
    ctx->r1 = ADD32(0, 0X1026);
    // 0x808007B0: beq         $a3, $at, L_80800950
    if (ctx->r7 == ctx->r1) {
        // 0x808007B4: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800950;
    }
    // 0x808007B4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808007B8: addiu       $at, $zero, 0x105E
    ctx->r1 = ADD32(0, 0X105E);
    // 0x808007BC: beq         $a3, $at, L_80800860
    if (ctx->r7 == ctx->r1) {
        // 0x808007C0: addiu       $at, $zero, 0x105F
        ctx->r1 = ADD32(0, 0X105F);
            goto L_80800860;
    }
    // 0x808007C0: addiu       $at, $zero, 0x105F
    ctx->r1 = ADD32(0, 0X105F);
    // 0x808007C4: beq         $a3, $at, L_808008D0
    if (ctx->r7 == ctx->r1) {
        // 0x808007C8: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_808008D0;
    }
    // 0x808007C8: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x808007CC: addiu       $at, $zero, 0x1060
    ctx->r1 = ADD32(0, 0X1060);
    // 0x808007D0: beq         $a3, $at, L_8080096C
    if (ctx->r7 == ctx->r1) {
        // 0x808007D4: nop
    
            goto L_8080096C;
    }
    // 0x808007D4: nop

    // 0x808007D8: b           L_80800978
    // 0x808007DC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
        goto L_80800978;
    // 0x808007DC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_808007E0:
    // 0x808007E0: slti        $at, $a3, 0x1024
    ctx->r1 = SIGNED(ctx->r7) < 0X1024 ? 1 : 0;
    // 0x808007E4: bne         $at, $zero, L_80800808
    if (ctx->r1 != 0) {
        // 0x808007E8: addiu       $at, $zero, 0x1024
        ctx->r1 = ADD32(0, 0X1024);
            goto L_80800808;
    }
    // 0x808007E8: addiu       $at, $zero, 0x1024
    ctx->r1 = ADD32(0, 0X1024);
    // 0x808007EC: beq         $a3, $at, L_80800918
    if (ctx->r7 == ctx->r1) {
        // 0x808007F0: addiu       $t1, $zero, 0xB
        ctx->r9 = ADD32(0, 0XB);
            goto L_80800918;
    }
    // 0x808007F0: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x808007F4: addiu       $at, $zero, 0x1025
    ctx->r1 = ADD32(0, 0X1025);
    // 0x808007F8: beq         $a3, $at, L_80800924
    if (ctx->r7 == ctx->r1) {
        // 0x808007FC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800924;
    }
    // 0x808007FC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80800800: b           L_80800978
    // 0x80800804: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
        goto L_80800978;
    // 0x80800804: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_80800808:
    // 0x80800808: slti        $at, $a3, 0xFF1
    ctx->r1 = SIGNED(ctx->r7) < 0XFF1 ? 1 : 0;
    // 0x8080080C: bne         $at, $zero, L_80800828
    if (ctx->r1 != 0) {
        // 0x80800810: addiu       $t7, $a3, -0xFEC
        ctx->r15 = ADD32(ctx->r7, -0XFEC);
            goto L_80800828;
    }
    // 0x80800810: addiu       $t7, $a3, -0xFEC
    ctx->r15 = ADD32(ctx->r7, -0XFEC);
    // 0x80800814: addiu       $at, $zero, 0x1023
    ctx->r1 = ADD32(0, 0X1023);
    // 0x80800818: beq         $a3, $at, L_8080090C
    if (ctx->r7 == ctx->r1) {
        // 0x8080081C: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_8080090C;
    }
    // 0x8080081C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x80800820: b           L_80800978
    // 0x80800824: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
        goto L_80800978;
    // 0x80800824: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_80800828:
    // 0x80800828: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x8080082C: beq         $at, $zero, L_80800974
    if (ctx->r1 == 0) {
        // 0x80800830: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80800974;
    }
    // 0x80800830: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80800834: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(740, 0X17EC) << 16);
    // 0x80800838: addu        $at, $at, $t7
    gpr jr_addend_80800840 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8080083C: lw          $t7, 0x17EC($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(740, 0X17EC));
    // 0x80800840: jr          $t7
    // 0x80800844: nop

    switch (jr_addend_80800840 >> 2) {
        case 0: goto L_80800848; break;
        case 1: goto L_80800868; break;
        case 2: goto L_80800890; break;
        case 3: goto L_808008A0; break;
        case 4: goto L_808008FC; break;
        default: switch_error(__func__, 0x80800840, 0x808017EC);
    }
    // 0x80800844: nop

L_80800848:
    // 0x80800848: addiu       $t8, $zero, 0x105E
    ctx->r24 = ADD32(0, 0X105E);
    // 0x8080084C: addiu       $t9, $zero, 0x4E
    ctx->r25 = ADD32(0, 0X4E);
    // 0x80800850: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80800854: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80800858: b           L_80800978
    // 0x8080085C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
        goto L_80800978;
    // 0x8080085C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_80800860:
    // 0x80800860: jal         0x800DA544
    // 0x80800864: addiu       $a0, $zero, 0x449
    ctx->r4 = ADD32(0, 0X449);
    func_800DA544(rdram, ctx);
        goto after_1;
    // 0x80800864: addiu       $a0, $zero, 0x449
    ctx->r4 = ADD32(0, 0X449);
    after_1:
L_80800868:
    // 0x80800868: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8080086C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800870: addiu       $t2, $zero, 0x1026
    ctx->r10 = ADD32(0, 0X1026);
    // 0x80800874: bne         $t0, $at, L_80800884
    if (ctx->r8 != ctx->r1) {
        // 0x80800878: addiu       $t1, $zero, 0x1025
        ctx->r9 = ADD32(0, 0X1025);
            goto L_80800884;
    }
    // 0x80800878: addiu       $t1, $zero, 0x1025
    ctx->r9 = ADD32(0, 0X1025);
    // 0x8080087C: b           L_80800888
    // 0x80800880: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
        goto L_80800888;
    // 0x80800880: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
L_80800884:
    // 0x80800884: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
L_80800888:
    // 0x80800888: b           L_80800978
    // 0x8080088C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
        goto L_80800978;
    // 0x8080088C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_80800890:
    // 0x80800890: jal         0x80800320
    // 0x80800894: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80800320_chfishshootgame(rdram, ctx);
        goto after_2;
    // 0x80800894: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x80800898: b           L_80800978
    // 0x8080089C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
        goto L_80800978;
    // 0x8080089C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_808008A0:
    // 0x808008A0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x808008A4: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    // 0x808008A8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x808008AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x808008B0: jal         0x8008A2C8
    // 0x808008B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    _susubgame_entrypoint_5(rdram, ctx);
        goto after_3;
    // 0x808008B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x808008B8: addiu       $t3, $zero, 0x105F
    ctx->r11 = ADD32(0, 0X105F);
    // 0x808008BC: addiu       $t4, $zero, 0x4E
    ctx->r12 = ADD32(0, 0X4E);
    // 0x808008C0: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x808008C4: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x808008C8: b           L_80800978
    // 0x808008CC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
        goto L_80800978;
    // 0x808008CC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_808008D0:
    // 0x808008D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808008D4: bne         $t5, $at, L_808008E8
    if (ctx->r13 != ctx->r1) {
        // 0x808008D8: addiu       $t8, $zero, 0xE
        ctx->r24 = ADD32(0, 0XE);
            goto L_808008E8;
    }
    // 0x808008D8: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x808008DC: addiu       $t6, $zero, 0x1025
    ctx->r14 = ADD32(0, 0X1025);
    // 0x808008E0: b           L_808008F0
    // 0x808008E4: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
        goto L_808008F0;
    // 0x808008E4: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_808008E8:
    // 0x808008E8: addiu       $t7, $zero, 0x1026
    ctx->r15 = ADD32(0, 0X1026);
    // 0x808008EC: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
L_808008F0:
    // 0x808008F0: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x808008F4: b           L_80800978
    // 0x808008F8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
        goto L_80800978;
    // 0x808008F8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_808008FC:
    // 0x808008FC: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80800900: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80800904: b           L_80800978
    // 0x80800908: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_80800978;
    // 0x80800908: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_8080090C:
    // 0x8080090C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80800910: b           L_80800978
    // 0x80800914: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
        goto L_80800978;
    // 0x80800914: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80800918:
    // 0x80800918: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x8080091C: b           L_80800978
    // 0x80800920: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
        goto L_80800978;
    // 0x80800920: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
L_80800924:
    // 0x80800924: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    // 0x80800928: jal         0x8008A2B0
    // 0x8080092C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_4;
    // 0x8080092C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_4:
    // 0x80800930: beq         $v0, $zero, L_80800940
    if (ctx->r2 == 0) {
        // 0x80800934: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80800940;
    }
    // 0x80800934: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800938: jal         0x8008A2C0
    // 0x8080093C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_5;
    // 0x8080093C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_5:
L_80800940:
    // 0x80800940: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80800944: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    // 0x80800948: b           L_80800978
    // 0x8080094C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80800978;
    // 0x8080094C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80800950:
    // 0x80800950: addiu       $a1, $v1, 0xB0
    ctx->r5 = ADD32(ctx->r3, 0XB0);
    // 0x80800954: jal         0x8008A2B0
    // 0x80800958: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    _susubgame_entrypoint_2(rdram, ctx);
        goto after_6;
    // 0x80800958: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_6:
    // 0x8080095C: beq         $v0, $zero, L_8080096C
    if (ctx->r2 == 0) {
        // 0x80800960: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_8080096C;
    }
    // 0x80800960: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80800964: jal         0x8008A2C0
    // 0x80800968: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _susubgame_entrypoint_4(rdram, ctx);
        goto after_7;
    // 0x80800968: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_7:
L_8080096C:
    // 0x8080096C: b           L_80800978
    // 0x80800970: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80800978;
    // 0x80800970: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80800974:
    // 0x80800974: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
L_80800978:
    // 0x80800978: beql        $a1, $zero, L_8080098C
    if (ctx->r5 == 0) {
        // 0x8080097C: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_8080098C;
    }
    goto skip_0;
    // 0x8080097C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80800980: jal         0x808003B0
    // 0x80800984: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_808003B0_chfishshootgame(rdram, ctx);
        goto after_8;
    // 0x80800984: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_8:
    // 0x80800988: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
L_8080098C:
    // 0x8080098C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80800990: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80800994: beq         $t3, $zero, L_808009B0
    if (ctx->r11 == 0) {
        // 0x80800998: or          $a1, $t3, $zero
        ctx->r5 = ctx->r11 | 0;
            goto L_808009B0;
    }
    // 0x80800998: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8080099C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x808009A0: addiu       $t4, $zero, 0x63
    ctx->r12 = ADD32(0, 0X63);
    // 0x808009A4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x808009A8: jal         0x8008A208
    // 0x808009AC: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    _subaddiedialog_entrypoint_11(rdram, ctx);
        goto after_9;
    // 0x808009AC: addiu       $a3, $v0, 0x4
    ctx->r7 = ADD32(ctx->r2, 0X4);
    after_9:
L_808009B0:
    // 0x808009B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808009B4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808009B8: jr          $ra
    // 0x808009BC: nop

    return;
    // 0x808009BC: nop

;}
RECOMP_FUNC void _bsbeemain_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828A8: syscall     17
    recomp_syscall_handler(rdram, ctx, 0x800828A8);
    return;
    // 0x800828AC: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800CA384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CA388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CA38C: jal         0x8001BAFC
    // 0x800CA390: nop

    defrag(rdram, ctx);
        goto after_0;
    // 0x800CA390: nop

    after_0:
    // 0x800CA394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CA39C: jr          $ra
    // 0x800CA3A0: nop

    return;
    // 0x800CA3A0: nop

;}
RECOMP_FUNC void _bscrashout_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F50: syscall     35
    recomp_syscall_handler(rdram, ctx, 0x80082F50);
    return;
    // 0x80082F54: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _chstatuebossbits_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086738: syscall     362
    recomp_syscall_handler(rdram, ctx, 0x80086738);
    return;
    // 0x8008673C: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _sucoasterplayer_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A308: syscall     835
    recomp_syscall_handler(rdram, ctx, 0x8008A308);
    return;
    // 0x8008A30C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_808001CC_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001D4: jal         0x8009BC34
    // 0x808001D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8009BC34(rdram, ctx);
        goto after_0;
    // 0x808001D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808001DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808001E0: jal         0x800961AC
    // 0x808001E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800961AC(rdram, ctx);
        goto after_1;
    // 0x808001E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x808001E8: jal         0x80083F60
    // 0x808001EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bstnt_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x808001EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x808001F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void func_800E98C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E98C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E98C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E98C8: jal         0x800E9804
    // 0x800E98CC: nop

    func_800E9804(rdram, ctx);
        goto after_0;
    // 0x800E98CC: nop

    after_0:
    // 0x800E98D0: lbu         $t6, 0xB($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XB);
    // 0x800E98D4: lbu         $t0, 0xA($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XA);
    // 0x800E98D8: lbu         $t2, 0x3($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X3);
    // 0x800E98DC: andi        $t8, $t6, 0xFFFE
    ctx->r24 = ctx->r14 & 0XFFFE;
    // 0x800E98E0: sb          $t8, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r24;
    // 0x800E98E4: andi        $t9, $t8, 0xFD
    ctx->r25 = ctx->r24 & 0XFD;
    // 0x800E98E8: andi        $t1, $t0, 0xFF07
    ctx->r9 = ctx->r8 & 0XFF07;
    // 0x800E98EC: andi        $t3, $t2, 0xFFFD
    ctx->r11 = ctx->r10 & 0XFFFD;
    // 0x800E98F0: sb          $t9, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r25;
    // 0x800E98F4: sb          $t1, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r9;
    // 0x800E98F8: sb          $t3, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r11;
    // 0x800E98FC: jal         0x800DC0C0
    // 0x800E9900: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800DC0C0(rdram, ctx);
        goto after_1;
    // 0x800E9900: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x800E9904: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800E9908: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E990C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800E9910: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800E9914: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800E9918: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800E991C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800E9920: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800E9924: nop

    // 0x800E9928: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800E992C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800E9930: nop

    // 0x800E9934: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800E9938: beql        $t5, $zero, L_800E9988
    if (ctx->r13 == 0) {
        // 0x800E993C: mfc1        $t5, $f8
        ctx->r13 = (int32_t)ctx->f8.u32l;
            goto L_800E9988;
    }
    goto skip_0;
    // 0x800E993C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x800E9940: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800E9944: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800E9948: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800E994C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800E9950: nop

    // 0x800E9954: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800E9958: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800E995C: nop

    // 0x800E9960: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800E9964: bne         $t5, $zero, L_800E997C
    if (ctx->r13 != 0) {
        // 0x800E9968: nop
    
            goto L_800E997C;
    }
    // 0x800E9968: nop

    // 0x800E996C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800E9970: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800E9974: b           L_800E9994
    // 0x800E9978: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800E9994;
    // 0x800E9978: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800E997C:
    // 0x800E997C: b           L_800E9994
    // 0x800E9980: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800E9994;
    // 0x800E9980: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800E9984: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
L_800E9988:
    // 0x800E9988: nop

    // 0x800E998C: bltz        $t5, L_800E997C
    if (SIGNED(ctx->r13) < 0) {
        // 0x800E9990: nop
    
            goto L_800E997C;
    }
    // 0x800E9990: nop

L_800E9994:
    // 0x800E9994: lhu         $t9, 0xA($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XA);
    // 0x800E9998: sll         $t7, $t5, 6
    ctx->r15 = S32(ctx->r13 << 6);
    // 0x800E999C: andi        $t8, $t7, 0x7C0
    ctx->r24 = ctx->r15 & 0X7C0;
    // 0x800E99A0: andi        $t0, $t9, 0xF83F
    ctx->r8 = ctx->r25 & 0XF83F;
    // 0x800E99A4: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800E99A8: sh          $t1, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r9;
    // 0x800E99AC: lbu         $t2, 0xB($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XB);
    // 0x800E99B0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800E99B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800E99B8: andi        $t4, $t2, 0xFFF7
    ctx->r12 = ctx->r10 & 0XFFF7;
    // 0x800E99BC: andi        $t7, $t4, 0xFB
    ctx->r15 = ctx->r12 & 0XFB;
    // 0x800E99C0: sb          $t4, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r12;
    // 0x800E99C4: sb          $t7, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r15;
    // 0x800E99C8: ori         $t9, $t7, 0x10
    ctx->r25 = ctx->r15 | 0X10;
    // 0x800E99CC: sb          $t9, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r25;
    // 0x800E99D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E99D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E99D8: jr          $ra
    // 0x800E99DC: nop

    return;
    // 0x800E99DC: nop

;}
RECOMP_FUNC void func_80110EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110EFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80110F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80110F04: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x80110F08: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80110F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80110F10: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80110F14: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80110F18: lh          $t8, 0x47AC($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X47AC);
    // 0x80110F1C: beq         $t8, $zero, L_80110F34
    if (ctx->r24 == 0) {
        // 0x80110F20: nop
    
            goto L_80110F34;
    }
    // 0x80110F20: nop

    // 0x80110F24: jal         0x80110E00
    // 0x80110F28: nop

    func_80110E00(rdram, ctx);
        goto after_0;
    // 0x80110F28: nop

    after_0:
    // 0x80110F2C: b           L_80110F38
    // 0x80110F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80110F38;
    // 0x80110F30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80110F34:
    // 0x80110F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80110F38:
    // 0x80110F38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80110F3C: jr          $ra
    // 0x80110F40: nop

    return;
    // 0x80110F40: nop

;}
RECOMP_FUNC void _bsdronegoto_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800830E8: syscall     43
    recomp_syscall_handler(rdram, ctx, 0x800830E8);
    return;
    // 0x800830EC: addi        $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
;}
RECOMP_FUNC void _suspline_entrypoint_18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089E08: syscall     811
    recomp_syscall_handler(rdram, ctx, 0x80089E08);
    return;
    // 0x80089E0C: addi        $t0, $zero, 0x48
    ctx->r8 = ADD32(0, 0X48);
;}
RECOMP_FUNC void _baeggcursor_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084AD0: syscall     128
    recomp_syscall_handler(rdram, ctx, 0x80084AD0);
    return;
    // 0x80084AD4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void gcnewoption_entrypoint_15(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801328: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080132C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80801330: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801334: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801338: bne         $a3, $v1, L_808013CC
    if (ctx->r7 != ctx->r3) {
        // 0x8080133C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_808013CC;
    }
    // 0x8080133C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80801340: sll         $t6, $a2, 1
    ctx->r14 = S32(ctx->r6 << 1);
    // 0x80801344: addu        $s0, $a1, $t6
    ctx->r16 = ADD32(ctx->r5, ctx->r14);
    // 0x80801348: lh          $a0, 0xB0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XB0);
    // 0x8080134C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80801350: beql        $a0, $at, L_808013AC
    if (ctx->r4 == ctx->r1) {
        // 0x80801354: lw          $t9, 0x248($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X248);
            goto L_808013AC;
    }
    goto skip_0;
    // 0x80801354: lw          $t9, 0x248($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X248);
    skip_0:
    // 0x80801358: beql        $a0, $zero, L_80801374
    if (ctx->r4 == 0) {
        // 0x8080135C: sh          $v1, 0xB0($s0)
        MEM_H(0XB0, ctx->r16) = ctx->r3;
            goto L_80801374;
    }
    goto skip_1;
    // 0x8080135C: sh          $v1, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r3;
    skip_1:
    // 0x80801360: beql        $a0, $v1, L_80801390
    if (ctx->r4 == ctx->r3) {
        // 0x80801364: sh          $zero, 0xB0($s0)
        MEM_H(0XB0, ctx->r16) = 0;
            goto L_80801390;
    }
    goto skip_2;
    // 0x80801364: sh          $zero, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = 0;
    skip_2:
    // 0x80801368: b           L_808013BC
    // 0x8080136C: nop

        goto L_808013BC;
    // 0x8080136C: nop

    // 0x80801370: sh          $v1, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r3;
L_80801374:
    // 0x80801374: lw          $t9, 0x248($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X248);
    // 0x80801378: lw          $a0, 0x24C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X24C);
    // 0x8080137C: jalr        $t9
    // 0x80801380: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80801380: nop

    after_0:
    // 0x80801384: b           L_808013BC
    // 0x80801388: lh          $a0, 0xB0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XB0);
        goto L_808013BC;
    // 0x80801388: lh          $a0, 0xB0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XB0);
    // 0x8080138C: sh          $zero, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = 0;
L_80801390:
    // 0x80801390: lw          $t9, 0x248($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X248);
    // 0x80801394: lw          $a0, 0x24C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X24C);
    // 0x80801398: jalr        $t9
    // 0x8080139C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8080139C: nop

    after_1:
    // 0x808013A0: b           L_808013BC
    // 0x808013A4: lh          $a0, 0xB0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XB0);
        goto L_808013BC;
    // 0x808013A4: lh          $a0, 0xB0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XB0);
    // 0x808013A8: lw          $t9, 0x248($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X248);
L_808013AC:
    // 0x808013AC: lw          $a0, 0x24C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X24C);
    // 0x808013B0: jalr        $t9
    // 0x808013B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x808013B4: nop

    after_2:
    // 0x808013B8: lh          $a0, 0xB0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XB0);
L_808013BC:
    // 0x808013BC: jal         0x808012C8
    // 0x808013C0: nop

    func_808012C8_gcnewoption(rdram, ctx);
        goto after_3;
    // 0x808013C0: nop

    after_3:
    // 0x808013C4: b           L_808013E0
    // 0x808013C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808013E0;
    // 0x808013C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808013CC:
    // 0x808013CC: lw          $t9, 0x248($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X248);
    // 0x808013D0: lw          $a0, 0x24C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X24C);
    // 0x808013D4: jalr        $t9
    // 0x808013D8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x808013D8: nop

    after_4:
    // 0x808013DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808013E0:
    // 0x808013E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808013E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808013E8: jr          $ra
    // 0x808013EC: nop

    return;
    // 0x808013EC: nop

;}
RECOMP_FUNC void _badust_entrypoint_12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084A28: syscall     125
    recomp_syscall_handler(rdram, ctx, 0x80084A28);
    return;
    // 0x80084A2C: addi        $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
;}
RECOMP_FUNC void _bsstonehead_entrypoint_24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083CA0: syscall     92
    recomp_syscall_handler(rdram, ctx, 0x80083CA0);
    return;
    // 0x80083CA4: addi        $t0, $zero, 0x60
    ctx->r8 = ADD32(0, 0X60);
;}
RECOMP_FUNC void _ncbaswim_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089318: syscall     773
    recomp_syscall_handler(rdram, ctx, 0x80089318);
    return;
    // 0x8008931C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void sulights_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080089C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x808008A0: lw          $a0, 0x7EF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7EF0);
    // 0x808008A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808008A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808008AC: beql        $a0, $zero, L_808008C8
    if (ctx->r4 == 0) {
        // 0x808008B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808008C8;
    }
    goto skip_0;
    // 0x808008B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808008B4: jal         0x800B2D28
    // 0x808008B8: nop

    vector_free(rdram, ctx);
        goto after_0;
    // 0x808008B8: nop

    after_0:
    // 0x808008BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x808008C0: sw          $zero, 0x7EF0($at)
    MEM_W(0X7EF0, ctx->r1) = 0;
    // 0x808008C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808008C8:
    // 0x808008C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808008CC: jr          $ra
    // 0x808008D0: nop

    return;
    // 0x808008D0: nop

;}
RECOMP_FUNC void sukickball_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x808006AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808006B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808006B4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x808006B8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808006BC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808006C0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x808006C4: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x808006C8: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x808006CC: jal         0x800EFB24
    // 0x808006D0: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    func_800EFB24(rdram, ctx);
        goto after_0;
    // 0x808006D0: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    after_0:
    // 0x808006D4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x808006D8: jal         0x800EE7F8
    // 0x808006DC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x808006DC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x808006E0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x808006E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808006E8: lui         $a3, 0x2
    ctx->r7 = S32(0X2 << 16);
    // 0x808006EC: ori         $a3, $a3, 0x20
    ctx->r7 = ctx->r7 | 0X20;
    // 0x808006F0: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x808006F4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x808006F8: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x808006FC: jal         0x800BF340
    // 0x80800700: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800BF340(rdram, ctx);
        goto after_2;
    // 0x80800700: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80800704: beq         $v0, $zero, L_8080075C
    if (ctx->r2 == 0) {
        // 0x80800708: lw          $v1, 0x48($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X48);
            goto L_8080075C;
    }
    // 0x80800708: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x8080070C: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800714: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x80800718: jal         0x800EFDE8
    // 0x8080071C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    func_800EFDE8(rdram, ctx);
        goto after_3;
    // 0x8080071C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_3:
    // 0x80800720: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80800724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800728: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8080072C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x80800730: jal         0x800EFA98
    // 0x80800734: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    func_800EFA98(rdram, ctx);
        goto after_4;
    // 0x80800734: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80800738: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8080073C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80800740: jal         0x800EE780
    // 0x80800744: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_5;
    // 0x80800744: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80800748: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x8080074C: jal         0x800EE7F8
    // 0x80800750: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_800EE7F8(rdram, ctx);
        goto after_6;
    // 0x80800750: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_6:
    // 0x80800754: b           L_80800974
    // 0x80800758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800974;
    // 0x80800758: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8080075C:
    // 0x8080075C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X11E0) << 16);
    // 0x80800760: lwc1        $f14, 0x11E0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X11E0));
    // 0x80800764: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800768: lui         $at, 0xC31F
    ctx->r1 = S32(0XC31F << 16);
    // 0x8080076C: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80800770: nop

    // 0x80800774: bc1fl       L_808007EC
    if (!c1cs) {
        // 0x80800778: lui         $at, 0xC42E
        ctx->r1 = S32(0XC42E << 16);
            goto L_808007EC;
    }
    goto skip_0;
    // 0x80800778: lui         $at, 0xC42E
    ctx->r1 = S32(0XC42E << 16);
    skip_0:
    // 0x8080077C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800780: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800784: lui         $at, 0x431F
    ctx->r1 = S32(0X431F << 16);
    // 0x80800788: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8080078C: nop

    // 0x80800790: bc1fl       L_808007E0
    if (!c1cs) {
        // 0x80800794: swc1        $f14, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f14.u32l;
            goto L_808007E0;
    }
    goto skip_1;
    // 0x80800794: swc1        $f14, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f14.u32l;
    skip_1:
    // 0x80800798: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8080079C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X11E4) << 16);
    // 0x808007A0: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x808007A4: nop

    // 0x808007A8: bc1fl       L_808007E0
    if (!c1cs) {
        // 0x808007AC: swc1        $f14, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f14.u32l;
            goto L_808007E0;
    }
    goto skip_2;
    // 0x808007AC: swc1        $f14, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f14.u32l;
    skip_2:
    // 0x808007B0: lwc1        $f8, 0x11E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X11E4));
    // 0x808007B4: lui         $at, 0x444C
    ctx->r1 = S32(0X444C << 16);
    // 0x808007B8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x808007BC: nop

    // 0x808007C0: bc1fl       L_808007EC
    if (!c1cs) {
        // 0x808007C4: lui         $at, 0xC42E
        ctx->r1 = S32(0XC42E << 16);
            goto L_808007EC;
    }
    goto skip_3;
    // 0x808007C4: lui         $at, 0xC42E
    ctx->r1 = S32(0XC42E << 16);
    skip_3:
    // 0x808007C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x808007CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808007D0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x808007D4: b           L_808007E8
    // 0x808007D8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
        goto L_808007E8;
    // 0x808007D8: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808007DC: swc1        $f14, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f14.u32l;
L_808007E0:
    // 0x808007E0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x808007E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_808007E8:
    // 0x808007E8: lui         $at, 0xC42E
    ctx->r1 = S32(0XC42E << 16);
L_808007EC:
    // 0x808007EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x808007F0: lui         $at, 0xC31F
    ctx->r1 = S32(0XC31F << 16);
    // 0x808007F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808007F8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x808007FC: lui         $at, 0x431F
    ctx->r1 = S32(0X431F << 16);
    // 0x80800800: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800804: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800808: bc1fl       L_80800874
    if (!c1cs) {
        // 0x8080080C: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_80800874;
    }
    goto skip_4;
    // 0x8080080C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_4:
    // 0x80800810: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x80800814: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X11EC) << 16);
    // 0x80800818: bc1f        L_80800860
    if (!c1cs) {
        // 0x8080081C: nop
    
            goto L_80800860;
    }
    // 0x8080081C: nop

    // 0x80800820: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80800824: nop

    // 0x80800828: bc1f        L_80800860
    if (!c1cs) {
        // 0x8080082C: nop
    
            goto L_80800860;
    }
    // 0x8080082C: nop

    // 0x80800830: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X11E8) << 16);
    // 0x80800834: lwc1        $f4, 0x11E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X11E8));
    // 0x80800838: lui         $at, 0xC44C
    ctx->r1 = S32(0XC44C << 16);
    // 0x8080083C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80800840: nop

    // 0x80800844: bc1fl       L_80800874
    if (!c1cs) {
        // 0x80800848: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_80800874;
    }
    goto skip_5;
    // 0x80800848: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_5:
    // 0x8080084C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800850: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800854: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80800858: b           L_80800870
    // 0x8080085C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
        goto L_80800870;
    // 0x8080085C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_80800860:
    // 0x80800860: lwc1        $f8, 0x11EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X11EC));
    // 0x80800864: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800868: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8080086C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
L_80800870:
    // 0x80800870: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_80800874:
    // 0x80800874: nop

    // 0x80800878: bc1fl       L_808008EC
    if (!c1cs) {
        // 0x8080087C: lui         $at, 0x442E
        ctx->r1 = S32(0X442E << 16);
            goto L_808008EC;
    }
    goto skip_6;
    // 0x8080087C: lui         $at, 0x442E
    ctx->r1 = S32(0X442E << 16);
    skip_6:
    // 0x80800880: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800884: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X11F4) << 16);
    // 0x80800888: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8080088C: nop

    // 0x80800890: bc1f        L_808008D8
    if (!c1cs) {
        // 0x80800894: nop
    
            goto L_808008D8;
    }
    // 0x80800894: nop

    // 0x80800898: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8080089C: nop

    // 0x808008A0: bc1f        L_808008D8
    if (!c1cs) {
        // 0x808008A4: nop
    
            goto L_808008D8;
    }
    // 0x808008A4: nop

    // 0x808008A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X11F0) << 16);
    // 0x808008AC: lwc1        $f10, 0x11F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X11F0));
    // 0x808008B0: lui         $at, 0xC44C
    ctx->r1 = S32(0XC44C << 16);
    // 0x808008B4: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x808008B8: nop

    // 0x808008BC: bc1fl       L_808008EC
    if (!c1cs) {
        // 0x808008C0: lui         $at, 0x442E
        ctx->r1 = S32(0X442E << 16);
            goto L_808008EC;
    }
    goto skip_7;
    // 0x808008C0: lui         $at, 0x442E
    ctx->r1 = S32(0X442E << 16);
    skip_7:
    // 0x808008C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x808008C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808008CC: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x808008D0: b           L_808008E8
    // 0x808008D4: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
        goto L_808008E8;
    // 0x808008D4: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
L_808008D8:
    // 0x808008D8: lwc1        $f6, 0x11F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X11F4));
    // 0x808008DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x808008E0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x808008E4: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
L_808008E8:
    // 0x808008E8: lui         $at, 0x442E
    ctx->r1 = S32(0X442E << 16);
L_808008EC:
    // 0x808008EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x808008F0: nop

    // 0x808008F4: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x808008F8: nop

    // 0x808008FC: bc1f        L_80800958
    if (!c1cs) {
        // 0x80800900: nop
    
            goto L_80800958;
    }
    // 0x80800900: nop

    // 0x80800904: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80800908: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8080090C: nop

    // 0x80800910: bc1fl       L_80800954
    if (!c1cs) {
        // 0x80800914: swc1        $f14, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->f14.u32l;
            goto L_80800954;
    }
    goto skip_8;
    // 0x80800914: swc1        $f14, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f14.u32l;
    skip_8:
    // 0x80800918: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8080091C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(3166, 0X11F8) << 16);
    // 0x80800920: bc1fl       L_80800954
    if (!c1cs) {
        // 0x80800924: swc1        $f14, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->f14.u32l;
            goto L_80800954;
    }
    goto skip_9;
    // 0x80800924: swc1        $f14, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f14.u32l;
    skip_9:
    // 0x80800928: lwc1        $f10, 0x11F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(3166, 0X11F8));
    // 0x8080092C: lui         $at, 0x444C
    ctx->r1 = S32(0X444C << 16);
    // 0x80800930: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80800934: nop

    // 0x80800938: bc1f        L_80800958
    if (!c1cs) {
        // 0x8080093C: nop
    
            goto L_80800958;
    }
    // 0x8080093C: nop

    // 0x80800940: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80800944: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80800948: b           L_80800958
    // 0x8080094C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
        goto L_80800958;
    // 0x8080094C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80800950: swc1        $f14, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f14.u32l;
L_80800954:
    // 0x80800954: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80800958:
    // 0x80800958: beq         $v1, $zero, L_80800970
    if (ctx->r3 == 0) {
        // 0x8080095C: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80800970;
    }
    // 0x8080095C: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80800960: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x80800964: jal         0x800EE7F8
    // 0x80800968: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    func_800EE7F8(rdram, ctx);
        goto after_7;
    // 0x80800968: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_7:
    // 0x8080096C: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
L_80800970:
    // 0x80800970: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80800974:
    // 0x80800974: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800978: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8080097C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80800980: jr          $ra
    // 0x80800984: nop

    return;
    // 0x80800984: nop

;}
RECOMP_FUNC void gzreg_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001A0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x808001A4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x808001A8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x808001AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001B0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x808001B4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XB90) << 16);
    // 0x808001B8: addiu       $a0, $a0, 0xB90
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XB90));
    // 0x808001BC: jal         0x8001D37C
    // 0x808001C0: lw          $a1, 0x11C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X11C);
    func_8001D37C(rdram, ctx);
        goto after_0;
    // 0x808001C0: lw          $a1, 0x11C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X11C);
    after_0:
    // 0x808001C4: addiu       $s0, $s1, 0x20
    ctx->r16 = ADD32(ctx->r17, 0X20);
    // 0x808001C8: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3394, 0XB9C) << 16);
    // 0x808001CC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3394, 0XFF0) << 16);
    // 0x808001D0: addiu       $a2, $a2, 0xFF0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3394, 0XFF0));
    // 0x808001D4: addiu       $a1, $a1, 0xB9C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XB9C));
    // 0x808001D8: jal         0x80800000
    // 0x808001DC: lw          $a0, 0x100($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X100);
    func_80800000_gzreg(rdram, ctx);
        goto after_1;
    // 0x808001DC: lw          $a0, 0x100($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X100);
    after_1:
    // 0x808001E0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XBA4) << 16);
    // 0x808001E4: jal         0x8001D37C
    // 0x808001E8: addiu       $a0, $a0, 0xBA4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XBA4));
    func_8001D37C(rdram, ctx);
        goto after_2;
    // 0x808001E8: addiu       $a0, $a0, 0xBA4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XBA4));
    after_2:
    // 0x808001EC: lw          $t3, 0x1C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C);
    // 0x808001F0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XBA8) << 16);
    // 0x808001F4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x808001F8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x808001FC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80800200: addiu       $a0, $a0, 0xBA8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XBA8));
    // 0x80800204: jal         0x8001D37C
    // 0x80800208: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8001D37C(rdram, ctx);
        goto after_3;
    // 0x80800208: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_3:
    // 0x8080020C: lw          $t3, 0x3C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X3C);
    // 0x80800210: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XBD0) << 16);
    // 0x80800214: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x80800218: lw          $a2, 0x2C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2C);
    // 0x8080021C: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    // 0x80800220: addiu       $a0, $a0, 0xBD0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XBD0));
    // 0x80800224: jal         0x8001D37C
    // 0x80800228: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8001D37C(rdram, ctx);
        goto after_4;
    // 0x80800228: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
    // 0x8080022C: lw          $t1, 0x5C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X5C);
    // 0x80800230: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XBF8) << 16);
    // 0x80800234: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x80800238: lw          $a2, 0x4C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4C);
    // 0x8080023C: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80800240: addiu       $a0, $a0, 0xBF8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XBF8));
    // 0x80800244: jal         0x8001D37C
    // 0x80800248: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_8001D37C(rdram, ctx);
        goto after_5;
    // 0x80800248: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_5:
    // 0x8080024C: lw          $t1, 0x7C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C);
    // 0x80800250: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XC20) << 16);
    // 0x80800254: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x80800258: lw          $a2, 0x6C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X6C);
    // 0x8080025C: lw          $a3, 0x74($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X74);
    // 0x80800260: addiu       $a0, $a0, 0xC20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XC20));
    // 0x80800264: jal         0x8001D37C
    // 0x80800268: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_8001D37C(rdram, ctx);
        goto after_6;
    // 0x80800268: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_6:
    // 0x8080026C: lw          $t9, 0x9C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X9C);
    // 0x80800270: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XC48) << 16);
    // 0x80800274: lw          $a1, 0x84($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X84);
    // 0x80800278: lw          $a2, 0x8C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8C);
    // 0x8080027C: lw          $a3, 0x94($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X94);
    // 0x80800280: addiu       $a0, $a0, 0xC48
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XC48));
    // 0x80800284: jal         0x8001D37C
    // 0x80800288: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_8001D37C(rdram, ctx);
        goto after_7;
    // 0x80800288: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_7:
    // 0x8080028C: lw          $t9, 0xBC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XBC);
    // 0x80800290: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XC70) << 16);
    // 0x80800294: lw          $a1, 0xA4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XA4);
    // 0x80800298: lw          $a2, 0xAC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XAC);
    // 0x8080029C: lw          $a3, 0xB4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB4);
    // 0x808002A0: addiu       $a0, $a0, 0xC70
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XC70));
    // 0x808002A4: jal         0x8001D37C
    // 0x808002A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_8001D37C(rdram, ctx);
        goto after_8;
    // 0x808002A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_8:
    // 0x808002AC: lw          $t7, 0xDC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XDC);
    // 0x808002B0: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XC98) << 16);
    // 0x808002B4: lw          $a1, 0xC4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC4);
    // 0x808002B8: lw          $a2, 0xCC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XCC);
    // 0x808002BC: lw          $a3, 0xD4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XD4);
    // 0x808002C0: addiu       $a0, $a0, 0xC98
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XC98));
    // 0x808002C4: jal         0x8001D37C
    // 0x808002C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8001D37C(rdram, ctx);
        goto after_9;
    // 0x808002C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_9:
    // 0x808002CC: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XCC0) << 16);
    // 0x808002D0: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3394, 0XCE8) << 16);
    // 0x808002D4: addiu       $a2, $a2, 0xCE8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3394, 0XCE8));
    // 0x808002D8: addiu       $a0, $a0, 0xCC0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XCC0));
    // 0x808002DC: lw          $a1, 0xE4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XE4);
    // 0x808002E0: jal         0x8001D37C
    // 0x808002E4: lw          $a3, 0x104($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X104);
    func_8001D37C(rdram, ctx);
        goto after_10;
    // 0x808002E4: lw          $a3, 0x104($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X104);
    after_10:
    // 0x808002E8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XCF4) << 16);
    // 0x808002EC: jal         0x8001D37C
    // 0x808002F0: addiu       $a0, $a0, 0xCF4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XCF4));
    func_8001D37C(rdram, ctx);
        goto after_11;
    // 0x808002F0: addiu       $a0, $a0, 0xCF4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XCF4));
    after_11:
    // 0x808002F4: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3394, 0XCF8) << 16);
    // 0x808002F8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3394, 0X12B4) << 16);
    // 0x808002FC: addiu       $a2, $a2, 0x12B4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3394, 0X12B4));
    // 0x80800300: addiu       $a1, $a1, 0xCF8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XCF8));
    // 0x80800304: jal         0x80800000
    // 0x80800308: lw          $a0, 0x10C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10C);
    func_80800000_gzreg(rdram, ctx);
        goto after_12;
    // 0x80800308: lw          $a0, 0x10C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10C);
    after_12:
    // 0x8080030C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XD00) << 16);
    // 0x80800310: jal         0x8001D37C
    // 0x80800314: addiu       $a0, $a0, 0xD00
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XD00));
    func_8001D37C(rdram, ctx);
        goto after_13;
    // 0x80800314: addiu       $a0, $a0, 0xD00
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XD00));
    after_13:
    // 0x80800318: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x8080031C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800320: jal         0x808000CC
    // 0x80800324: lw          $a1, 0x114($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X114);
    func_808000CC_gzreg(rdram, ctx);
        goto after_14;
    // 0x80800324: lw          $a1, 0x114($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X114);
    after_14:
    // 0x80800328: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080032C: jal         0x808000CC
    // 0x80800330: lw          $a1, 0x11C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X11C);
    func_808000CC_gzreg(rdram, ctx);
        goto after_15;
    // 0x80800330: lw          $a1, 0x11C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X11C);
    after_15:
    // 0x80800334: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800338: jal         0x808000CC
    // 0x8080033C: lw          $a1, 0x124($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X124);
    func_808000CC_gzreg(rdram, ctx);
        goto after_16;
    // 0x8080033C: lw          $a1, 0x124($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X124);
    after_16:
    // 0x80800340: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XD04) << 16);
    // 0x80800344: addiu       $a0, $a0, 0xD04
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XD04));
    // 0x80800348: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080034C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800350: jal         0x8001D37C
    // 0x80800354: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_8001D37C(rdram, ctx);
        goto after_17;
    // 0x80800354: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_17:
    // 0x80800358: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080035C: jal         0x808000CC
    // 0x80800360: lw          $a1, 0x12C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X12C);
    func_808000CC_gzreg(rdram, ctx);
        goto after_18;
    // 0x80800360: lw          $a1, 0x12C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X12C);
    after_18:
    // 0x80800364: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x80800368: jal         0x808000CC
    // 0x8080036C: lw          $a1, 0x134($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X134);
    func_808000CC_gzreg(rdram, ctx);
        goto after_19;
    // 0x8080036C: lw          $a1, 0x134($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X134);
    after_19:
    // 0x80800370: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800374: jal         0x808000CC
    // 0x80800378: lw          $a1, 0x13C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X13C);
    func_808000CC_gzreg(rdram, ctx);
        goto after_20;
    // 0x80800378: lw          $a1, 0x13C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X13C);
    after_20:
    // 0x8080037C: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XD24) << 16);
    // 0x80800380: addiu       $a0, $a0, 0xD24
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XD24));
    // 0x80800384: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800388: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8080038C: jal         0x8001D37C
    // 0x80800390: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_8001D37C(rdram, ctx);
        goto after_21;
    // 0x80800390: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_21:
    // 0x80800394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800398: jal         0x808000CC
    // 0x8080039C: lw          $a1, 0x144($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X144);
    func_808000CC_gzreg(rdram, ctx);
        goto after_22;
    // 0x8080039C: lw          $a1, 0x144($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X144);
    after_22:
    // 0x808003A0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808003A4: jal         0x808000CC
    // 0x808003A8: lw          $a1, 0x14C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14C);
    func_808000CC_gzreg(rdram, ctx);
        goto after_23;
    // 0x808003A8: lw          $a1, 0x14C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14C);
    after_23:
    // 0x808003AC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808003B0: jal         0x808000CC
    // 0x808003B4: lw          $a1, 0x154($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X154);
    func_808000CC_gzreg(rdram, ctx);
        goto after_24;
    // 0x808003B4: lw          $a1, 0x154($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X154);
    after_24:
    // 0x808003B8: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XD44) << 16);
    // 0x808003BC: addiu       $a0, $a0, 0xD44
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XD44));
    // 0x808003C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x808003C4: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x808003C8: jal         0x8001D37C
    // 0x808003CC: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_8001D37C(rdram, ctx);
        goto after_25;
    // 0x808003CC: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_25:
    // 0x808003D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x808003D4: jal         0x808000CC
    // 0x808003D8: lw          $a1, 0x15C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X15C);
    func_808000CC_gzreg(rdram, ctx);
        goto after_26;
    // 0x808003D8: lw          $a1, 0x15C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X15C);
    after_26:
    // 0x808003DC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x808003E0: jal         0x808000CC
    // 0x808003E4: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    func_808000CC_gzreg(rdram, ctx);
        goto after_27;
    // 0x808003E4: lw          $a1, 0x164($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X164);
    after_27:
    // 0x808003E8: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x808003EC: jal         0x808000CC
    // 0x808003F0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    func_808000CC_gzreg(rdram, ctx);
        goto after_28;
    // 0x808003F0: lw          $a1, 0x16C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X16C);
    after_28:
    // 0x808003F4: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XD64) << 16);
    // 0x808003F8: addiu       $a0, $a0, 0xD64
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XD64));
    // 0x808003FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800400: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800404: jal         0x8001D37C
    // 0x80800408: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_8001D37C(rdram, ctx);
        goto after_29;
    // 0x80800408: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_29:
    // 0x8080040C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800410: jal         0x808000CC
    // 0x80800414: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    func_808000CC_gzreg(rdram, ctx);
        goto after_30;
    // 0x80800414: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    after_30:
    // 0x80800418: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8080041C: jal         0x808000CC
    // 0x80800420: lw          $a1, 0x17C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X17C);
    func_808000CC_gzreg(rdram, ctx);
        goto after_31;
    // 0x80800420: lw          $a1, 0x17C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X17C);
    after_31:
    // 0x80800424: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80800428: jal         0x808000CC
    // 0x8080042C: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    func_808000CC_gzreg(rdram, ctx);
        goto after_32;
    // 0x8080042C: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    after_32:
    // 0x80800430: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XD84) << 16);
    // 0x80800434: addiu       $a0, $a0, 0xD84
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XD84));
    // 0x80800438: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8080043C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80800440: jal         0x8001D37C
    // 0x80800444: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    func_8001D37C(rdram, ctx);
        goto after_33;
    // 0x80800444: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_33:
    // 0x80800448: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080044C: jal         0x808000CC
    // 0x80800450: lw          $a1, 0x18C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18C);
    func_808000CC_gzreg(rdram, ctx);
        goto after_34;
    // 0x80800450: lw          $a1, 0x18C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18C);
    after_34:
    // 0x80800454: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XDA4) << 16);
    // 0x80800458: addiu       $a0, $a0, 0xDA4
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XDA4));
    // 0x8080045C: jal         0x8001D37C
    // 0x80800460: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8001D37C(rdram, ctx);
        goto after_35;
    // 0x80800460: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_35:
    // 0x80800464: lui         $a0, 0x8080
    ctx->r4 = S32(RELOC_HI16(3394, 0XDB0) << 16);
    // 0x80800468: jal         0x8001D37C
    // 0x8080046C: addiu       $a0, $a0, 0xDB0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XDB0));
    func_8001D37C(rdram, ctx);
        goto after_36;
    // 0x8080046C: addiu       $a0, $a0, 0xDB0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(3394, 0XDB0));
    after_36:
    // 0x80800470: lui         $a1, 0x8080
    ctx->r5 = S32(RELOC_HI16(3394, 0XDB4) << 16);
    // 0x80800474: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(3394, 0X1140) << 16);
    // 0x80800478: addiu       $a2, $a2, 0x1140
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(3394, 0X1140));
    // 0x8080047C: addiu       $a1, $a1, 0xDB4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(3394, 0XDB4));
    // 0x80800480: jal         0x80800000
    // 0x80800484: lw          $a0, 0xF8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XF8);
    func_80800000_gzreg(rdram, ctx);
        goto after_37;
    // 0x80800484: lw          $a0, 0xF8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XF8);
    after_37:
    // 0x80800488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080048C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80800490: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80800494: jr          $ra
    // 0x80800498: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80800498: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void bstaxi_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808001D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808001D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808001D8: jal         0x80800144
    // 0x808001DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bstaxi_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808001DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: addiu       $a1, $zero, 0x129
    ctx->r5 = ADD32(0, 0X129);
    // 0x808001E8: jal         0x8008CCBC
    // 0x808001EC: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    baanim_playForDuration_onceSmooth(rdram, ctx);
        goto after_1;
    // 0x808001EC: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    after_1:
    // 0x808001F0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x808001F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80800200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80800204: jal         0x8009FFD8
    // 0x80800208: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x80800208: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8080020C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800210: jal         0x8009B9B0
    // 0x80800214: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    baphysics_set_target_horizontal_velocity(rdram, ctx);
        goto after_3;
    // 0x80800214: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80800218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080021C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80800220: jal         0x80098140
    // 0x80800224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    bainput_enable(rdram, ctx);
        goto after_4;
    // 0x80800224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80800228: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8080022C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800230: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800234: jr          $ra
    // 0x80800238: nop

    return;
    // 0x80800238: nop

;}
RECOMP_FUNC void func_808009C4_bsbabykaz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808009C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808009C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808009CC: jal         0x8009BC6C
    // 0x808009D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    baphysics_reset_gravity(rdram, ctx);
        goto after_0;
    // 0x808009D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x808009D4: jal         0x808004B8
    // 0x808009D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsbabykaz_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808009D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808009DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808009E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808009E4: jr          $ra
    // 0x808009E8: nop

    return;
    // 0x808009E8: nop

;}
RECOMP_FUNC void func_80800730_chnicecavemenguard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800738: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1272, 0X9E8) << 16);
    // 0x8080073C: addiu       $a2, $a2, 0x9E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1272, 0X9E8));
    // 0x80800740: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x80800744: jal         0x80089D20
    // 0x80800748: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800748: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x8080074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800754: jr          $ra
    // 0x80800758: nop

    return;
    // 0x80800758: nop

;}
RECOMP_FUNC void bsstand_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800B98: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800B9C: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(368, 0XD98) << 16);
    // 0x80800BA0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800BA4: jr          $ra
    // 0x80800BA8: lw          $v0, 0xD98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(368, 0XD98));
    return;
    // 0x80800BA8: lw          $v0, 0xD98($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(368, 0XD98));
;}
RECOMP_FUNC void func_8010B040(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010B044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010B048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010B04C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010B050: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010B054: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8010B058: jal         0x8010C4AC
    // 0x8010B05C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8010C4AC(rdram, ctx);
        goto after_0;
    // 0x8010B05C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8010B060: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8010B064: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8010B068: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    // 0x8010B06C: jal         0x800EF1B8
    // 0x8010B070: lw          $a1, 0x48($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X48);
    func_800EF1B8(rdram, ctx);
        goto after_1;
    // 0x8010B070: lw          $a1, 0x48($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X48);
    after_1:
    // 0x8010B074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010B078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010B07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010B080: jr          $ra
    // 0x8010B084: nop

    return;
    // 0x8010B084: nop

;}
RECOMP_FUNC void func_80800830_bstntswim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800838: jal         0x80800174
    // 0x8080083C: nop

    func_80800174_bstntswim(rdram, ctx);
        goto after_0;
    // 0x8080083C: nop

    after_0:
    // 0x80800840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800848: jr          $ra
    // 0x8080084C: nop

    return;
    // 0x8080084C: nop

;}
RECOMP_FUNC void func_800C9214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9214: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9218: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C921C: addiu       $t6, $t6, -0x54C0
    ctx->r14 = ADD32(ctx->r14, -0X54C0);
    // 0x800C9220: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9224: lbu         $a1, 0x14($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X14);
    // 0x800C9228: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C922C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800C9230: blez        $a1, L_800C928C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C9234: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800C928C;
    }
    // 0x800C9234: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C9238:
    // 0x800C9238: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800C923C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C9240: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C9244: bne         $a2, $a0, L_800C9284
    if (ctx->r6 != ctx->r4) {
        // 0x800C9248: nop
    
            goto L_800C9284;
    }
    // 0x800C9248: nop

    // 0x800C924C: jal         0x8001B084
    // 0x800C9250: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    heap_free(rdram, ctx);
        goto after_0;
    // 0x800C9250: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x800C9254: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C9258: addiu       $a3, $a3, -0x54C0
    ctx->r7 = ADD32(ctx->r7, -0X54C0);
    // 0x800C925C: lbu         $v1, 0x14($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X14);
    // 0x800C9260: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800C9264: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800C9268: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x800C926C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C9270: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800C9274: sb          $t7, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r15;
    // 0x800C9278: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800C927C: b           L_800C928C
    // 0x800C9280: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
        goto L_800C928C;
    // 0x800C9280: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_800C9284:
    // 0x800C9284: bne         $at, $zero, L_800C9238
    if (ctx->r1 != 0) {
        // 0x800C9288: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800C9238;
    }
    // 0x800C9288: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800C928C:
    // 0x800C928C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9290: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C9294: jr          $ra
    // 0x800C9298: nop

    return;
    // 0x800C9298: nop

;}
RECOMP_FUNC void func_808000BC_bsvan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808000C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000C8: jal         0x80091A58
    // 0x808000CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    bakey_pressed(rdram, ctx);
        goto after_0;
    // 0x808000CC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x808000D0: beql        $v0, $zero, L_808000E4
    if (ctx->r2 == 0) {
        // 0x808000D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_808000E4;
    }
    goto skip_0;
    // 0x808000D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000D8: jal         0x80085370
    // 0x808000DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    _bavan_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x808000DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808000E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000E4:
    // 0x808000E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808000E8: jr          $ra
    // 0x808000EC: nop

    return;
    // 0x808000EC: nop

;}
RECOMP_FUNC void func_800F0E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0E28: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800F0E2C: beq         $at, $zero, L_800F0E3C
    if (ctx->r1 == 0) {
        // 0x800F0E30: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800F0E3C;
    }
    // 0x800F0E30: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800F0E34: jr          $ra
    // 0x800F0E38: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800F0E38: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800F0E3C:
    // 0x800F0E3C: jr          $ra
    // 0x800F0E40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800F0E40: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void fxfontstring_entrypoint_3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808001AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808001B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808001B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808001B8: jal         0x80800000
    // 0x808001BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80800000_fxfontstring(rdram, ctx);
        goto after_0;
    // 0x808001BC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808001C0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x808001C4: addiu       $t6, $zero, 0xFD
    ctx->r14 = ADD32(0, 0XFD);
    // 0x808001C8: addiu       $t7, $zero, 0x69
    ctx->r15 = ADD32(0, 0X69);
    // 0x808001CC: sra         $t0, $t8, 8
    ctx->r8 = S32(SIGNED(ctx->r24) >> 8);
    // 0x808001D0: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x808001D4: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    // 0x808001D8: sb          $t0, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r8;
    // 0x808001DC: sb          $t8, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r24;
    // 0x808001E0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x808001E4: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x808001E8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x808001EC: sb          $t2, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r10;
    // 0x808001F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808001F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808001F8: jr          $ra
    // 0x808001FC: nop

    return;
    // 0x808001FC: nop

;}
RECOMP_FUNC void _vpflicker_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089040: syscall     757
    recomp_syscall_handler(rdram, ctx, 0x80089040);
    return;
    // 0x80089044: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void _vpmodule_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890C0: syscall     761
    recomp_syscall_handler(rdram, ctx, 0x800890C0);
    return;
    // 0x800890C4: addi        $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
;}
RECOMP_FUNC void _bsbkflamethrower_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829C0: syscall     23
    recomp_syscall_handler(rdram, ctx, 0x800829C0);
    return;
    // 0x800829C4: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80095004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80095008: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8009500C: beq         $a1, $zero, L_80095038
    if (ctx->r5 == 0) {
        // 0x80095010: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80095038;
    }
    // 0x80095010: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095014: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80095018: beq         $a1, $at, L_8009504C
    if (ctx->r5 == ctx->r1) {
        // 0x8009501C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8009504C;
    }
    // 0x8009501C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80095020: beq         $a1, $at, L_80095058
    if (ctx->r5 == ctx->r1) {
        // 0x80095024: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80095058;
    }
    // 0x80095024: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80095028: beql        $a1, $at, L_8009505C
    if (ctx->r5 == ctx->r1) {
        // 0x8009502C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8009505C;
    }
    goto skip_0;
    // 0x8009502C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80095030: b           L_8009505C
    // 0x80095034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009505C;
    // 0x80095034: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80095038:
    // 0x80095038: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8009503C: jal         0x800A0D74
    // 0x80095040: nop

    func_800A0D74(rdram, ctx);
        goto after_0;
    // 0x80095040: nop

    after_0:
    // 0x80095044: b           L_8009505C
    // 0x80095048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009505C;
    // 0x80095048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009504C:
    // 0x8009504C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80095050: jal         0x800A0D84
    // 0x80095054: nop

    func_800A0D84(rdram, ctx);
        goto after_1;
    // 0x80095054: nop

    after_1:
L_80095058:
    // 0x80095058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009505C:
    // 0x8009505C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80095060: jr          $ra
    // 0x80095064: nop

    return;
    // 0x80095064: nop

;}
RECOMP_FUNC void func_80800838_chfactorysparkroom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800838: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8080083C: sw          $s7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r23;
    // 0x80800840: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x80800844: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80800848: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x8080084C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800850: sw          $s6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r22;
    // 0x80800854: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x80800858: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x8080085C: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x80800860: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x80800864: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80800868: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8080086C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80800870: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80800874: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80800878: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8080087C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80800880: jal         0x80100094
    // 0x80800884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80800884: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80800888: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x8080088C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80800890: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80800894: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x80800898: beq         $t6, $zero, L_808009F4
    if (ctx->r14 == 0) {
        // 0x8080089C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_808009F4;
    }
    // 0x8080089C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x808008A0: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2372, 0X104C) << 16);
    // 0x808008A4: lwc1        $f30, 0x104C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2372, 0X104C));
    // 0x808008A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x808008AC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x808008B0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808008B4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x808008B8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x808008BC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x808008C0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x808008C4: addiu       $s5, $sp, 0xA8
    ctx->r21 = ADD32(ctx->r29, 0XA8);
    // 0x808008C8: addiu       $s4, $sp, 0xB4
    ctx->r20 = ADD32(ctx->r29, 0XB4);
L_808008CC:
    // 0x808008CC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x808008D0: addiu       $s2, $s0, 0x48
    ctx->r18 = ADD32(ctx->r16, 0X48);
    // 0x808008D4: c.lt.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl < ctx->f12.fl;
    // 0x808008D8: nop

    // 0x808008DC: bc1fl       L_808009E8
    if (!c1cs) {
        // 0x808008E0: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_808009E8;
    }
    goto skip_0;
    // 0x808008E0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x808008E4: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x808008E8: lwc1        $f14, 0x0($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X0);
    // 0x808008EC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x808008F0: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x808008F4: jal         0x800F10B4
    // 0x808008F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x808008F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x808008FC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80800900: jal         0x800D7520
    // 0x80800904: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    func_800D7520(rdram, ctx);
        goto after_2;
    // 0x80800904: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    after_2:
    // 0x80800908: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8080090C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800910: jal         0x800C7A68
    // 0x80800914: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800C7A68(rdram, ctx);
        goto after_3;
    // 0x80800914: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_3:
    // 0x80800918: jal         0x800E3980
    // 0x8080091C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800E3980(rdram, ctx);
        goto after_4;
    // 0x8080091C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x80800920: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80800924: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80800928: jal         0x800F1E6C
    // 0x8080092C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_800F1E6C(rdram, ctx);
        goto after_5;
    // 0x8080092C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x80800930: mul.s       $f12, $f20, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x80800934: jal         0x80013970
    // 0x80800938: nop

    func_80013970(rdram, ctx);
        goto after_6;
    // 0x80800938: nop

    after_6:
    // 0x8080093C: c.lt.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl < ctx->f0.fl;
    // 0x80800940: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80800944: bc1fl       L_80800970
    if (!c1cs) {
        // 0x80800948: lwc1        $f0, 0x38($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
            goto L_80800970;
    }
    goto skip_1;
    // 0x80800948: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    skip_1:
    // 0x8080094C: jal         0x800DC0C0
    // 0x80800950: nop

    func_800DC0C0(rdram, ctx);
        goto after_7;
    // 0x80800950: nop

    after_7:
    // 0x80800954: mul.s       $f6, $f0, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x80800958: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2372, 0X1050) << 16);
    // 0x8080095C: lwc1        $f8, 0x1050($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2372, 0X1050));
    // 0x80800960: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80800964: b           L_80800978
    // 0x80800968: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
        goto L_80800978;
    // 0x80800968: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    // 0x8080096C: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
L_80800970:
    // 0x80800970: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80800974: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
L_80800978:
    // 0x80800978: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8080097C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800980: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800984: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x80800988: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8080098C: swc1        $f22, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f22.u32l;
    // 0x80800990: sub.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x80800994: jal         0x800DF830
    // 0x80800998: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    func_800DF830(rdram, ctx);
        goto after_8;
    // 0x80800998: swc1        $f6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x8080099C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808009A0: jal         0x800DC128
    // 0x808009A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DC128(rdram, ctx);
        goto after_9;
    // 0x808009A4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_9:
    // 0x808009A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808009AC: jal         0x800DF744
    // 0x808009B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DF744(rdram, ctx);
        goto after_10;
    // 0x808009B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x808009B4: jal         0x8010347C
    // 0x808009B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_8010347C(rdram, ctx);
        goto after_11;
    // 0x808009B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_11:
    // 0x808009BC: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x808009C0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x808009C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808009C8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x808009CC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x808009D0: jal         0x800DE498
    // 0x808009D4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_800DE498(rdram, ctx);
        goto after_12;
    // 0x808009D4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_12:
    // 0x808009D8: lw          $v1, 0x6C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X6C);
    // 0x808009DC: andi        $t7, $v1, 0x1FF
    ctx->r15 = ctx->r3 & 0X1FF;
    // 0x808009E0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x808009E4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_808009E8:
    // 0x808009E8: sltu        $at, $s3, $v1
    ctx->r1 = ctx->r19 < ctx->r3 ? 1 : 0;
    // 0x808009EC: bne         $at, $zero, L_808008CC
    if (ctx->r1 != 0) {
        // 0x808009F0: addiu       $s1, $s1, 0x20
        ctx->r17 = ADD32(ctx->r17, 0X20);
            goto L_808008CC;
    }
    // 0x808009F0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
L_808009F4:
    // 0x808009F4: lhu         $t8, 0x76($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X76);
    // 0x808009F8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x808009FC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80800A00: srl         $t9, $t8, 7
    ctx->r25 = S32(U32(ctx->r24) >> 7);
    // 0x80800A04: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80800A08: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80800A0C: bgez        $t9, L_80800A24
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80800A10: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80800A24;
    }
    // 0x80800A10: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80800A14: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80800A18: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800A1C: nop

    // 0x80800A20: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_80800A24:
    // 0x80800A24: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80800A28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80800A2C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2372, 0X1054) << 16);
    // 0x80800A30: lwc1        $f6, 0x1054($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(2372, 0X1054));
    // 0x80800A34: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80800A38: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80800A3C: addiu       $a0, $zero, 0x6B9
    ctx->r4 = ADD32(0, 0X6B9);
    // 0x80800A40: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80800A44: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80800A48: nop

    // 0x80800A4C: bc1fl       L_80800B20
    if (!c1cs) {
        // 0x80800A50: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_80800B20;
    }
    goto skip_2;
    // 0x80800A50: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_2:
    // 0x80800A54: jal         0x800D674C
    // 0x80800A58: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    func_800D674C(rdram, ctx);
        goto after_13;
    // 0x80800A58: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    after_13:
    // 0x80800A5C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80800A60: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x80800A64: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80800A68: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80800A6C: addiu       $s0, $sp, 0x94
    ctx->r16 = ADD32(ctx->r29, 0X94);
    // 0x80800A70: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x80800A74: addiu       $s5, $sp, 0x88
    ctx->r21 = ADD32(ctx->r29, 0X88);
    // 0x80800A78: addiu       $s4, $sp, 0x8C
    ctx->r20 = ADD32(ctx->r29, 0X8C);
L_80800A7C:
    // 0x80800A7C: jal         0x800F54E4
    // 0x80800A80: nop

    func_800F54E4(rdram, ctx);
        goto after_14;
    // 0x80800A80: nop

    after_14:
    // 0x80800A84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800A88: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80800A8C: jal         0x800F5A2C
    // 0x80800A90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800F5A2C(rdram, ctx);
        goto after_15;
    // 0x80800A90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_15:
    // 0x80800A94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800A98: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800A9C: jal         0x800F1E6C
    // 0x80800AA0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_800F1E6C(rdram, ctx);
        goto after_16;
    // 0x80800AA0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_16:
    // 0x80800AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800AA8: jal         0x800F1828
    // 0x80800AAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800F1828(rdram, ctx);
        goto after_17;
    // 0x80800AAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_17:
    // 0x80800AB0: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80800AB4: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x80800AB8: swc1        $f22, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f22.u32l;
    // 0x80800ABC: sub.s       $f18, $f10, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f26.fl;
    // 0x80800AC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800AC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80800AC8: jal         0x800EEAD4
    // 0x80800ACC: swc1        $f18, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f18.u32l;
    func_800EEAD4(rdram, ctx);
        goto after_18;
    // 0x80800ACC: swc1        $f18, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f18.u32l;
    after_18:
    // 0x80800AD0: div.s       $f20, $f0, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80800AD4: jal         0x800DF830
    // 0x80800AD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800DF830(rdram, ctx);
        goto after_19;
    // 0x80800AD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x80800ADC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800AE0: jal         0x800DC128
    // 0x80800AE4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    func_800DC128(rdram, ctx);
        goto after_20;
    // 0x80800AE4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_20:
    // 0x80800AE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80800AEC: jal         0x800DF744
    // 0x80800AF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800DF744(rdram, ctx);
        goto after_21;
    // 0x80800AF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_21:
    // 0x80800AF4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80800AF8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80800AFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80800B00: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80800B04: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800B08: jal         0x800DE498
    // 0x80800B0C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    func_800DE498(rdram, ctx);
        goto after_22;
    // 0x80800B0C: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_22:
    // 0x80800B10: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80800B14: bne         $s3, $s6, L_80800A7C
    if (ctx->r19 != ctx->r22) {
        // 0x80800B18: nop
    
            goto L_80800A7C;
    }
    // 0x80800B18: nop

    // 0x80800B1C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80800B20:
    // 0x80800B20: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80800B24: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80800B28: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80800B2C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80800B30: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80800B34: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80800B38: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x80800B3C: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x80800B40: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80800B44: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80800B48: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x80800B4C: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x80800B50: lw          $s6, 0x64($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X64);
    // 0x80800B54: lw          $s7, 0x68($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X68);
    // 0x80800B58: jr          $ra
    // 0x80800B5C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80800B5C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_80091104(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091104: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x80091108: jr          $ra
    // 0x8009110C: sb          $a1, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r5;
    return;
    // 0x8009110C: sb          $a1, 0xF($t6)
    MEM_B(0XF, ctx->r14) = ctx->r5;
;}
RECOMP_FUNC void _vpscroll_entrypoint_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089078: syscall     759
    recomp_syscall_handler(rdram, ctx, 0x80089078);
    return;
    // 0x8008907C: addi        $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
;}
RECOMP_FUNC void func_8010CD28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CD28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010CD2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010CD30: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010CD34: addiu       $a1, $a1, 0x6F50
    ctx->r5 = ADD32(ctx->r5, 0X6F50);
    // 0x8010CD38: jal         0x800F1DF4
    // 0x8010CD3C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800F1DF4(rdram, ctx);
        goto after_0;
    // 0x8010CD3C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8010CD40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010CD44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010CD48: jr          $ra
    // 0x8010CD4C: nop

    return;
    // 0x8010CD4C: nop

;}
RECOMP_FUNC void baattach_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080009C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A0: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x808000A4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x808000A8: beq         $t6, $zero, L_808000C0
    if (ctx->r14 == 0) {
        // 0x808000AC: sw          $t6, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r14;
            goto L_808000C0;
    }
    // 0x808000AC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x808000B0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x808000B4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x808000B8: jalr        $t9
    // 0x808000BC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x808000BC: nop

    after_0:
L_808000C0:
    // 0x808000C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808000C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x808000C8: jr          $ra
    // 0x808000CC: nop

    return;
    // 0x808000CC: nop

;}
RECOMP_FUNC void chhoopswoop_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(1016, 0X1F50) << 16);
    // 0x8080001C: jr          $ra
    // 0x80800020: addiu       $v0, $v0, 0x1F50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1016, 0X1F50));
    return;
    // 0x80800020: addiu       $v0, $v0, 0x1F50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(1016, 0X1F50));
;}
RECOMP_FUNC void func_808028D0_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808028D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808028D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808028D8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808028DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808028E0: jal         0x80100094
    // 0x808028E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808028E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808028E8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x808028EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x808028F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x808028F4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x808028F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x808028FC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80802900: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80802904: jal         0x80089B00
    // 0x80802908: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    _sukickball_entrypoint_13(rdram, ctx);
        goto after_1;
    // 0x80802908: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_1:
    // 0x8080290C: beq         $v0, $zero, L_80802954
    if (ctx->r2 == 0) {
        // 0x80802910: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_80802954;
    }
    // 0x80802910: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80802914: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80802918: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8080291C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80802920: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x80802924: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80802928: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1840, 0X4C84) << 16);
    // 0x8080292C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80802930: nop

    // 0x80802934: bc1fl       L_80802958
    if (!c1cs) {
        // 0x80802938: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80802958;
    }
    goto skip_0;
    // 0x80802938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8080293C: jal         0x80089D18
    // 0x80802940: addiu       $a2, $a2, 0x4C84
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1840, 0X4C84));
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_2;
    // 0x80802940: addiu       $a2, $a2, 0x4C84
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1840, 0X4C84));
    after_2:
    // 0x80802944: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x80802948: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8080294C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80802950: swc1        $f8, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f8.u32l;
L_80802954:
    // 0x80802954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80802958:
    // 0x80802958: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080295C: jr          $ra
    // 0x80802960: nop

    return;
    // 0x80802960: nop

;}
RECOMP_FUNC void func_8080013C_glgamestore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: lui         $t6, 0x8008
    ctx->r14 = S32(0X8008 << 16);
    // 0x80800140: lw          $t6, -0x60A4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X60A4);
    // 0x80800144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080014C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800150: bne         $t6, $at, L_8080016C
    if (ctx->r14 != ctx->r1) {
        // 0x80800154: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8080016C;
    }
    // 0x80800154: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80800158: jal         0x80088508
    // 0x8080015C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    _gleeprom_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x8080015C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x80800160: beq         $v0, $zero, L_8080016C
    if (ctx->r2 == 0) {
        // 0x80800164: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8080016C;
    }
    // 0x80800164: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80800168: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8080016C:
    // 0x8080016C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800170: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800174: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80800178: jr          $ra
    // 0x8080017C: nop

    return;
    // 0x8080017C: nop

;}
RECOMP_FUNC void func_800EA400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA400: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EA404: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800EA408: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800EA40C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800EA410: addiu       $t8, $t8, 0x2DD0
    ctx->r24 = ADD32(ctx->r24, 0X2DD0);
    // 0x800EA414: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800EA418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA41C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800EA420: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800EA424: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800EA428: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800EA42C: addiu       $a0, $v0, 0x8
    ctx->r4 = ADD32(ctx->r2, 0X8);
    // 0x800EA430: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800EA434: jal         0x800EE7F8
    // 0x800EA438: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x800EA438: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800EA43C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800EA440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA444: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800EA448: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800EA44C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EA450: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x800EA454: jr          $ra
    // 0x800EA458: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    return;
    // 0x800EA458: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
;}
