#include "recomp.h"
#include "tooie_hooks.h"
#include "funcs.h"

RECOMP_FUNC void func_800F77E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F77E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F77EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F77F0: lui         $a3, 0xC4BB
    ctx->r7 = S32(0XC4BB << 16);
    // 0x800F77F4: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x800F77F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800F77FC: jal         0x800F7750
    // 0x800F7800: lui         $a2, 0x4452
    ctx->r6 = S32(0X4452 << 16);
    func_800F7750(rdram, ctx);
        goto after_0;
    // 0x800F7800: lui         $a2, 0x4452
    ctx->r6 = S32(0X4452 << 16);
    after_0:
    // 0x800F7804: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F7808: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F780C: jr          $ra
    // 0x800F7810: nop

    return;
    // 0x800F7810: nop

;}
RECOMP_FUNC void func_800F3BD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F3BD4: sltiu       $at, $a1, 0xA
    ctx->r1 = ctx->r5 < 0XA ? 1 : 0;
    // 0x800F3BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F3BDC: beq         $at, $zero, L_800F3E68
    if (ctx->r1 == 0) {
        // 0x800F3BE0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800F3E68;
    }
    // 0x800F3BE0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800F3BE4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800F3BE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F3BEC: addu        $at, $at, $t6
    gpr jr_addend_800F3BF4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800F3BF0: lw          $t6, 0x5F00($at)
    ctx->r14 = ADD32(ctx->r1, 0X5F00);
    // 0x800F3BF4: jr          $t6
    // 0x800F3BF8: nop

    switch (jr_addend_800F3BF4 >> 2) {
        case 0: goto L_800F3E68; break;
        case 1: goto L_800F3BFC; break;
        case 2: goto L_800F3C10; break;
        case 3: goto L_800F3C24; break;
        case 4: goto L_800F3C38; break;
        case 5: goto L_800F3C60; break;
        case 6: goto L_800F3C4C; break;
        case 7: goto L_800F3E2C; break;
        case 8: goto L_800F3E40; break;
        case 9: goto L_800F3E54; break;
        default: switch_error(__func__, 0x800F3BF4, 0x80125F00);
    }
    // 0x800F3BF8: nop

L_800F3BFC:
    // 0x800F3BFC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F3C00: jal         0x80092D44
    // 0x800F3C04: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80092D44(rdram, ctx);
        goto after_0;
    // 0x800F3C04: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800F3C08: b           L_800F3E78
    // 0x800F3C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F3E78;
    // 0x800F3C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F3C10:
    // 0x800F3C10: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F3C14: jal         0x80092E5C
    // 0x800F3C18: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80092E5C(rdram, ctx);
        goto after_1;
    // 0x800F3C18: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x800F3C1C: b           L_800F3E78
    // 0x800F3C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F3E78;
    // 0x800F3C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F3C24:
    // 0x800F3C24: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F3C28: jal         0x80092C00
    // 0x800F3C2C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80092C00(rdram, ctx);
        goto after_2;
    // 0x800F3C2C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x800F3C30: b           L_800F3E78
    // 0x800F3C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F3E78;
    // 0x800F3C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F3C38:
    // 0x800F3C38: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F3C3C: jal         0x80092C24
    // 0x800F3C40: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80092C24(rdram, ctx);
        goto after_3;
    // 0x800F3C40: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x800F3C44: b           L_800F3E78
    // 0x800F3C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F3E78;
    // 0x800F3C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F3C4C:
    // 0x800F3C4C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F3C50: jal         0x80092C48
    // 0x800F3C54: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80092C48(rdram, ctx);
        goto after_4;
    // 0x800F3C54: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x800F3C58: b           L_800F3E78
    // 0x800F3C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F3E78;
    // 0x800F3C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F3C60:
    // 0x800F3C60: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F3C64: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800F3C68: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800F3C6C: jal         0x8009C128
    // 0x800F3C70: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8009C128(rdram, ctx);
        goto after_5;
    // 0x800F3C70: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_5:
    // 0x800F3C74: jal         0x800A3274
    // 0x800F3C78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800A3274(rdram, ctx);
        goto after_6;
    // 0x800F3C78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_6:
    // 0x800F3C7C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800F3C80: sltiu       $at, $t7, 0x13
    ctx->r1 = ctx->r15 < 0X13 ? 1 : 0;
    // 0x800F3C84: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800F3C88: beq         $at, $zero, L_800F3E14
    if (ctx->r1 == 0) {
        // 0x800F3C8C: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_800F3E14;
    }
    // 0x800F3C8C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800F3C90: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800F3C94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F3C98: addu        $at, $at, $t7
    gpr jr_addend_800F3CA0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800F3C9C: lw          $t7, 0x5F28($at)
    ctx->r15 = ADD32(ctx->r1, 0X5F28);
    // 0x800F3CA0: jr          $t7
    // 0x800F3CA4: nop

    switch (jr_addend_800F3CA0 >> 2) {
        case 0: goto L_800F3DB0; break;
        case 1: goto L_800F3CA8; break;
        case 2: goto L_800F3E14; break;
        case 3: goto L_800F3E14; break;
        case 4: goto L_800F3E14; break;
        case 5: goto L_800F3CD8; break;
        case 6: goto L_800F3CF0; break;
        case 7: goto L_800F3E14; break;
        case 8: goto L_800F3E14; break;
        case 9: goto L_800F3E14; break;
        case 10: goto L_800F3D98; break;
        case 11: goto L_800F3D38; break;
        case 12: goto L_800F3E14; break;
        case 13: goto L_800F3D08; break;
        case 14: goto L_800F3CC0; break;
        case 15: goto L_800F3D20; break;
        case 16: goto L_800F3D50; break;
        case 17: goto L_800F3D68; break;
        case 18: goto L_800F3D80; break;
        default: switch_error(__func__, 0x800F3CA0, 0x80125F28);
    }
    // 0x800F3CA4: nop

L_800F3CA8:
    // 0x800F3CA8: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x800F3CAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F3CB0: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3CB4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F3CB8: b           L_800F3E74
    // 0x800F3CBC: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
        goto L_800F3E74;
    // 0x800F3CBC: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
L_800F3CC0:
    // 0x800F3CC0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800F3CC4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F3CC8: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3CCC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F3CD0: b           L_800F3E74
    // 0x800F3CD4: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
        goto L_800F3E74;
    // 0x800F3CD4: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
L_800F3CD8:
    // 0x800F3CD8: lui         $at, 0x42AA
    ctx->r1 = S32(0X42AA << 16);
    // 0x800F3CDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F3CE0: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3CE4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F3CE8: b           L_800F3E74
    // 0x800F3CEC: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
        goto L_800F3E74;
    // 0x800F3CEC: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
L_800F3CF0:
    // 0x800F3CF0: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x800F3CF4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F3CF8: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3CFC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F3D00: b           L_800F3E74
    // 0x800F3D04: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
        goto L_800F3E74;
    // 0x800F3D04: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
L_800F3D08:
    // 0x800F3D08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800F3D0C: lwc1        $f6, 0x5F74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5F74);
    // 0x800F3D10: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3D14: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F3D18: b           L_800F3E74
    // 0x800F3D1C: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
        goto L_800F3E74;
    // 0x800F3D1C: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
L_800F3D20:
    // 0x800F3D20: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x800F3D24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F3D28: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3D2C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F3D30: b           L_800F3E74
    // 0x800F3D34: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
        goto L_800F3E74;
    // 0x800F3D34: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
L_800F3D38:
    // 0x800F3D38: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800F3D3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F3D40: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3D44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F3D48: b           L_800F3E74
    // 0x800F3D4C: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
        goto L_800F3E74;
    // 0x800F3D4C: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
L_800F3D50:
    // 0x800F3D50: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800F3D54: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F3D58: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3D5C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F3D60: b           L_800F3E74
    // 0x800F3D64: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
        goto L_800F3E74;
    // 0x800F3D64: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
L_800F3D68:
    // 0x800F3D68: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x800F3D6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F3D70: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3D74: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F3D78: b           L_800F3E74
    // 0x800F3D7C: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
        goto L_800F3E74;
    // 0x800F3D7C: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
L_800F3D80:
    // 0x800F3D80: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800F3D84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F3D88: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3D8C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F3D90: b           L_800F3E74
    // 0x800F3D94: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
        goto L_800F3E74;
    // 0x800F3D94: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
L_800F3D98:
    // 0x800F3D98: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800F3D9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F3DA0: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3DA4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F3DA8: b           L_800F3E74
    // 0x800F3DAC: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
        goto L_800F3E74;
    // 0x800F3DAC: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
L_800F3DB0:
    // 0x800F3DB0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F3DB4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800F3DB8: jal         0x800F40EC
    // 0x800F3DBC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_800F40EC(rdram, ctx);
        goto after_7;
    // 0x800F3DBC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_7:
    // 0x800F3DC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F3DC4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800F3DC8: beq         $v0, $at, L_800F3DE4
    if (ctx->r2 == ctx->r1) {
        // 0x800F3DCC: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_800F3DE4;
    }
    // 0x800F3DCC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800F3DD0: lw          $a0, 0x184($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X184);
    // 0x800F3DD4: jal         0x800F6720
    // 0x800F3DD8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800F6720(rdram, ctx);
        goto after_8;
    // 0x800F3DD8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_8:
    // 0x800F3DDC: beq         $v0, $zero, L_800F3DFC
    if (ctx->r2 == 0) {
        // 0x800F3DE0: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_800F3DFC;
    }
    // 0x800F3DE0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_800F3DE4:
    // 0x800F3DE4: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x800F3DE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F3DEC: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3DF0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F3DF4: b           L_800F3E74
    // 0x800F3DF8: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
        goto L_800F3E74;
    // 0x800F3DF8: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
L_800F3DFC:
    // 0x800F3DFC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800F3E00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F3E04: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3E08: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F3E0C: b           L_800F3E74
    // 0x800F3E10: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
        goto L_800F3E74;
    // 0x800F3E10: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
L_800F3E14:
    // 0x800F3E14: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800F3E18: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F3E1C: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800F3E20: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F3E24: b           L_800F3E74
    // 0x800F3E28: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
        goto L_800F3E74;
    // 0x800F3E28: swc1        $f18, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f18.u32l;
L_800F3E2C:
    // 0x800F3E2C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F3E30: jal         0x80092DC0
    // 0x800F3E34: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80092DC0(rdram, ctx);
        goto after_9;
    // 0x800F3E34: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_9:
    // 0x800F3E38: b           L_800F3E78
    // 0x800F3E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F3E78;
    // 0x800F3E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F3E40:
    // 0x800F3E40: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F3E44: jal         0x8009C188
    // 0x800F3E48: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8009C188(rdram, ctx);
        goto after_10;
    // 0x800F3E48: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_10:
    // 0x800F3E4C: b           L_800F3E78
    // 0x800F3E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F3E78;
    // 0x800F3E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F3E54:
    // 0x800F3E54: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F3E58: jal         0x80092D9C
    // 0x800F3E5C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80092D9C(rdram, ctx);
        goto after_11;
    // 0x800F3E5C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_11:
    // 0x800F3E60: b           L_800F3E78
    // 0x800F3E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800F3E78;
    // 0x800F3E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F3E68:
    // 0x800F3E68: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F3E6C: jal         0x800F3BB0
    // 0x800F3E70: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800F3BB0(rdram, ctx);
        goto after_12;
    // 0x800F3E70: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_12:
L_800F3E74:
    // 0x800F3E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800F3E78:
    // 0x800F3E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F3E7C: jr          $ra
    // 0x800F3E80: nop

    return;
    // 0x800F3E80: nop

;}
RECOMP_FUNC void func_80800830_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800830: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800834: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800838: jal         0x8080056C
    // 0x8080083C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8080056C_bsfirstp(rdram, ctx);
        goto after_0;
    // 0x8080083C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800840: jal         0x808006DC
    // 0x80800844: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_808006DC_bsfirstp(rdram, ctx);
        goto after_1;
    // 0x80800844: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8080084C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800850: jr          $ra
    // 0x80800854: nop

    return;
    // 0x80800854: nop

;}
RECOMP_FUNC void func_80018854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018854: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x80018858: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8001885C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80018860: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80018864: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x80018868: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8001886C: lw          $t7, -0x4D30($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4D30);
    // 0x80018870: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80018874: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x80018878: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001887C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80018880: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80018884: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80018888: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8001888C: beq         $t7, $zero, L_80018990
    if (ctx->r15 == 0) {
        // 0x80018890: sw          $a3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r7;
            goto L_80018990;
    }
    // 0x80018890: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80018894: lui         $at, 0x4900
    ctx->r1 = S32(0X4900 << 16);
    // 0x80018898: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8001889C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800188A0: lui         $s1, 0x8002
    ctx->r17 = S32(0X8002 << 16);
    // 0x800188A4: mul.s       $f4, $f14, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x800188A8: addiu       $s1, $s1, -0x7C2C
    ctx->r17 = ADD32(ctx->r17, -0X7C2C);
    // 0x800188AC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800188B0: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800188B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800188B8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800188BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800188C0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800188C4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800188C8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800188CC: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x800188D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800188D4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800188D8: jal         0x800C9EAC
    // 0x800188DC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_800C9EAC(rdram, ctx);
        goto after_0;
    // 0x800188DC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_0:
    // 0x800188E0: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800188E4: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800188E8: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800188EC: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800188F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800188F4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800188F8: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800188FC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80018900: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80018904: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80018908: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8001890C: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80018910: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x80018914: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80018918: jal         0x800C9EAC
    // 0x8001891C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    func_800C9EAC(rdram, ctx);
        goto after_1;
    // 0x8001891C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_1:
    // 0x80018920: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80018924: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80018928: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001892C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80018930: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80018934: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80018938: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001893C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80018940: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80018944: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80018948: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8001894C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    // 0x80018950: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80018954: jal         0x800C9EAC
    // 0x80018958: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    func_800C9EAC(rdram, ctx);
        goto after_2;
    // 0x80018958: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_2:
    // 0x8001895C: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80018960: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80018964: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80018968: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8001896C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80018970: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80018974: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80018978: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8001897C: add.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80018980: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80018984: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80018988: jal         0x800C9EAC
    // 0x8001898C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_800C9EAC(rdram, ctx);
        goto after_3;
    // 0x8001898C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_3:
L_80018990:
    // 0x80018990: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80018994: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80018998: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8001899C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800189A0: jr          $ra
    // 0x800189A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800189A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80111680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111680: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x80111684: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80111688: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8011168C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80111690: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80111694: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80111698: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8011169C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x801116A0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x801116A4: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x801116A8: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x801116AC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x801116B0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x801116B4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x801116B8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801116BC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801116C0: sw          $a0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r4;
    // 0x801116C4: sw          $a3, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r7;
    // 0x801116C8: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x801116CC: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x801116D0: jal         0x800EEAD4
    // 0x801116D4: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    func_800EEAD4(rdram, ctx);
        goto after_0;
    // 0x801116D4: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    after_0:
    // 0x801116D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x801116DC: lwc1        $f4, 0x6550($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6550);
    // 0x801116E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801116E4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801116E8: nop

    // 0x801116EC: bc1fl       L_80111708
    if (!c1cs) {
        // 0x801116F0: lw          $a0, 0x108($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X108);
            goto L_80111708;
    }
    goto skip_0;
    // 0x801116F0: lw          $a0, 0x108($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X108);
    skip_0:
    // 0x801116F4: jal         0x800EE7F8
    // 0x801116F8: lw          $a1, 0x108($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X108);
    func_800EE7F8(rdram, ctx);
        goto after_1;
    // 0x801116F8: lw          $a1, 0x108($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X108);
    after_1:
    // 0x801116FC: jal         0x800EFD24
    // 0x80111700: lw          $a0, 0x114($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X114);
    func_800EFD24(rdram, ctx);
        goto after_2;
    // 0x80111700: lw          $a0, 0x114($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X114);
    after_2:
    // 0x80111704: lw          $a0, 0x108($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X108);
L_80111708:
    // 0x80111708: jal         0x800EEAD4
    // 0x8011170C: lw          $a1, 0x120($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X120);
    func_800EEAD4(rdram, ctx);
        goto after_3;
    // 0x8011170C: lw          $a1, 0x120($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X120);
    after_3:
    // 0x80111710: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80111714: lwc1        $f6, 0x6554($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6554);
    // 0x80111718: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x8011171C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80111720: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80111724: nop

    // 0x80111728: bc1f        L_801117D0
    if (!c1cs) {
        // 0x8011172C: nop
    
            goto L_801117D0;
    }
    // 0x8011172C: nop

    // 0x80111730: jal         0x800EFB24
    // 0x80111734: lw          $a2, 0x108($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X108);
    func_800EFB24(rdram, ctx);
        goto after_4;
    // 0x80111734: lw          $a2, 0x108($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X108);
    after_4:
    // 0x80111738: jal         0x800EEEA8
    // 0x8011173C: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    func_800EEEA8(rdram, ctx);
        goto after_5;
    // 0x8011173C: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_5:
    // 0x80111740: beql        $v0, $zero, L_80111768
    if (ctx->r2 == 0) {
        // 0x80111744: addiu       $s0, $sp, 0x74
        ctx->r16 = ADD32(ctx->r29, 0X74);
            goto L_80111768;
    }
    goto skip_1;
    // 0x80111744: addiu       $s0, $sp, 0x74
    ctx->r16 = ADD32(ctx->r29, 0X74);
    skip_1:
    // 0x80111748: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8011174C: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x80111750: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80111754: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80111758: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8011175C: jal         0x800EFA4C
    // 0x80111760: nop

    func_800EFA4C(rdram, ctx);
        goto after_6;
    // 0x80111760: nop

    after_6:
    // 0x80111764: addiu       $s0, $sp, 0x74
    ctx->r16 = ADD32(ctx->r29, 0X74);
L_80111768:
    // 0x80111768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8011176C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80111770: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80111774: jal         0x800EFA4C
    // 0x80111778: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_800EFA4C(rdram, ctx);
        goto after_7;
    // 0x80111778: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_7:
    // 0x8011177C: addiu       $s4, $sp, 0x94
    ctx->r20 = ADD32(ctx->r29, 0X94);
    // 0x80111780: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80111784: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x80111788: jal         0x800EE97C
    // 0x8011178C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE97C(rdram, ctx);
        goto after_8;
    // 0x8011178C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_8:
    // 0x80111790: jal         0x800EF2A0
    // 0x80111794: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800EF2A0(rdram, ctx);
        goto after_9;
    // 0x80111794: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_9:
    // 0x80111798: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8011179C: jal         0x800EEAA4
    // 0x801117A0: lw          $a1, 0x108($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X108);
    func_800EEAA4(rdram, ctx);
        goto after_10;
    // 0x801117A0: lw          $a1, 0x108($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X108);
    after_10:
    // 0x801117A4: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x801117A8: jal         0x800EF2A0
    // 0x801117AC: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    func_800EF2A0(rdram, ctx);
        goto after_11;
    // 0x801117AC: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    after_11:
    // 0x801117B0: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x801117B4: jal         0x800EEAA4
    // 0x801117B8: lw          $a1, 0x108($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X108);
    func_800EEAA4(rdram, ctx);
        goto after_12;
    // 0x801117B8: lw          $a1, 0x108($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X108);
    after_12:
    // 0x801117BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801117C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801117C4: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x801117C8: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x801117CC: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
L_801117D0:
    // 0x801117D0: jal         0x800D8FEC
    // 0x801117D4: addiu       $s4, $sp, 0x94
    ctx->r20 = ADD32(ctx->r29, 0X94);
    func_800D8FEC(rdram, ctx);
        goto after_13;
    // 0x801117D4: addiu       $s4, $sp, 0x94
    ctx->r20 = ADD32(ctx->r29, 0X94);
    after_13:
    // 0x801117D8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x801117DC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x801117E0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x801117E4: blez        $v1, L_801119F4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801117E8: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_801119F4;
    }
    // 0x801117E8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x801117EC: mtc1        $a3, $f18
    ctx->f18.u32l = ctx->r7;
    // 0x801117F0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801117F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801117F8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801117FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80111800: lwc1        $f14, 0x6558($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6558);
    // 0x80111804: sw          $v1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r3;
    // 0x80111808: addiu       $fp, $sp, 0xE4
    ctx->r30 = ADD32(ctx->r29, 0XE4);
    // 0x8011180C: mul.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80111810: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x80111814: addiu       $s7, $sp, 0xF0
    ctx->r23 = ADD32(ctx->r29, 0XF0);
    // 0x80111818: addiu       $s6, $sp, 0xFC
    ctx->r22 = ADD32(ctx->r29, 0XFC);
    // 0x8011181C: addiu       $s2, $sp, 0xC0
    ctx->r18 = ADD32(ctx->r29, 0XC0);
    // 0x80111820: addiu       $s1, $sp, 0xB4
    ctx->r17 = ADD32(ctx->r29, 0XB4);
    // 0x80111824: addiu       $s0, $sp, 0xD8
    ctx->r16 = ADD32(ctx->r29, 0XD8);
    // 0x80111828: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x8011182C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
L_80111830:
    // 0x80111830: lw          $a1, 0x108($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X108);
    // 0x80111834: jal         0x800EFB24
    // 0x80111838: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_800EFB24(rdram, ctx);
        goto after_14;
    // 0x80111838: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_14:
    // 0x8011183C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80111840: jal         0x800EF334
    // 0x80111844: lw          $a1, 0x118($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X118);
    func_800EF334(rdram, ctx);
        goto after_15;
    // 0x80111844: lw          $a1, 0x118($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X118);
    after_15:
    // 0x80111848: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8011184C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80111850: jal         0x800EFB24
    // 0x80111854: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    func_800EFB24(rdram, ctx);
        goto after_16;
    // 0x80111854: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    after_16:
    // 0x80111858: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8011185C: jal         0x800EF334
    // 0x80111860: lw          $a1, 0x11C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X11C);
    func_800EF334(rdram, ctx);
        goto after_17;
    // 0x80111860: lw          $a1, 0x11C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X11C);
    after_17:
    // 0x80111864: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80111868: jal         0x800EE7F8
    // 0x8011186C: lw          $a1, 0x114($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X114);
    func_800EE7F8(rdram, ctx);
        goto after_18;
    // 0x8011186C: lw          $a1, 0x114($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X114);
    after_18:
    // 0x80111870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111874: jal         0x800EE7F8
    // 0x80111878: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_19;
    // 0x80111878: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_19:
    // 0x8011187C: lui         $a2, 0x3B5A
    ctx->r6 = S32(0X3B5A << 16);
    // 0x80111880: ori         $a2, $a2, 0x740E
    ctx->r6 = ctx->r6 | 0X740E;
    // 0x80111884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111888: jal         0x800EF174
    // 0x8011188C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    func_800EF174(rdram, ctx);
        goto after_20;
    // 0x8011188C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_20:
    // 0x80111890: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80111894: jal         0x800EE7F8
    // 0x80111898: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_21;
    // 0x80111898: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_21:
    // 0x8011189C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801118A0: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x801118A4: jal         0x800EE780
    // 0x801118A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_800EE780(rdram, ctx);
        goto after_22;
    // 0x801118A8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_22:
    // 0x801118AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801118B0: jal         0x800EF334
    // 0x801118B4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800EF334(rdram, ctx);
        goto after_23;
    // 0x801118B4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_23:
    // 0x801118B8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x801118BC: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x801118C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801118C4: bne         $t8, $zero, L_801118D4
    if (ctx->r24 != 0) {
        // 0x801118C8: addiu       $a1, $sp, 0xCC
        ctx->r5 = ADD32(ctx->r29, 0XCC);
            goto L_801118D4;
    }
    // 0x801118C8: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
    // 0x801118CC: beql        $t9, $zero, L_80111998
    if (ctx->r25 == 0) {
        // 0x801118D0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80111998;
    }
    goto skip_2;
    // 0x801118D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
L_801118D4:
    // 0x801118D4: jal         0x800EE780
    // 0x801118D8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EE780(rdram, ctx);
        goto after_24;
    // 0x801118D8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_24:
    // 0x801118DC: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x801118E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801118E4: lw          $a1, 0x90($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X90);
    // 0x801118E8: beq         $t0, $zero, L_8011193C
    if (ctx->r8 == 0) {
        // 0x801118EC: or          $a2, $s3, $zero
        ctx->r6 = ctx->r19 | 0;
            goto L_8011193C;
    }
    // 0x801118EC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x801118F0: addiu       $t1, $sp, 0x68
    ctx->r9 = ADD32(ctx->r29, 0X68);
    // 0x801118F4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801118F8: jal         0x801115C8
    // 0x801118FC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_801115C8(rdram, ctx);
        goto after_25;
    // 0x801118FC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_25:
    // 0x80111900: beq         $v0, $zero, L_8011193C
    if (ctx->r2 == 0) {
        // 0x80111904: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8011193C;
    }
    // 0x80111904: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80111908: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8011190C: jal         0x800EF334
    // 0x80111910: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    func_800EF334(rdram, ctx);
        goto after_26;
    // 0x80111910: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    after_26:
    // 0x80111914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111918: jal         0x800EEAA4
    // 0x8011191C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_27;
    // 0x8011191C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_27:
    // 0x80111920: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80111924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111928: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8011192C: jal         0x800EF174
    // 0x80111930: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EF174(rdram, ctx);
        goto after_28;
    // 0x80111930: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_28:
    // 0x80111934: b           L_80111998
    // 0x80111938: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
        goto L_80111998;
    // 0x80111938: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8011193C:
    // 0x8011193C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80111940: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x80111944: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80111948: beq         $t2, $zero, L_80111994
    if (ctx->r10 == 0) {
        // 0x8011194C: or          $a2, $s3, $zero
        ctx->r6 = ctx->r19 | 0;
            goto L_80111994;
    }
    // 0x8011194C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80111950: addiu       $t3, $sp, 0x68
    ctx->r11 = ADD32(ctx->r29, 0X68);
    // 0x80111954: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80111958: jal         0x801115C8
    // 0x8011195C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_801115C8(rdram, ctx);
        goto after_29;
    // 0x8011195C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_29:
    // 0x80111960: beq         $v0, $zero, L_80111994
    if (ctx->r2 == 0) {
        // 0x80111964: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80111994;
    }
    // 0x80111964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80111968: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8011196C: jal         0x800EF334
    // 0x80111970: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    func_800EF334(rdram, ctx);
        goto after_30;
    // 0x80111970: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    after_30:
    // 0x80111974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111978: jal         0x800EEAA4
    // 0x8011197C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    func_800EEAA4(rdram, ctx);
        goto after_31;
    // 0x8011197C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_31:
    // 0x80111980: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80111984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80111988: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8011198C: jal         0x800EF174
    // 0x80111990: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    func_800EF174(rdram, ctx);
        goto after_32;
    // 0x80111990: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    after_32:
L_80111994:
    // 0x80111994: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80111998:
    // 0x80111998: addiu       $a1, $sp, 0xCC
    ctx->r5 = ADD32(ctx->r29, 0XCC);
    // 0x8011199C: jal         0x800EE780
    // 0x801119A0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_800EE780(rdram, ctx);
        goto after_33;
    // 0x801119A0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_33:
    // 0x801119A4: lw          $a0, 0x114($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X114);
    // 0x801119A8: jal         0x800EEAD4
    // 0x801119AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EEAD4(rdram, ctx);
        goto after_34;
    // 0x801119AC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_34:
    // 0x801119B0: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801119B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801119B8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801119BC: div.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801119C0: jal         0x800EE7F8
    // 0x801119C4: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
    func_800EE7F8(rdram, ctx);
        goto after_35;
    // 0x801119C4: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
    after_35:
    // 0x801119C8: lw          $a0, 0x114($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X114);
    // 0x801119CC: jal         0x800EE7F8
    // 0x801119D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_36;
    // 0x801119D0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_36:
    // 0x801119D4: jal         0x800EEF94
    // 0x801119D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800EEF94(rdram, ctx);
        goto after_37;
    // 0x801119D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_37:
    // 0x801119DC: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x801119E0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x801119E4: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x801119E8: slt         $at, $s5, $t4
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x801119EC: bnel        $at, $zero, L_80111830
    if (ctx->r1 != 0) {
        // 0x801119F0: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80111830;
    }
    goto skip_3;
    // 0x801119F0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    skip_3:
L_801119F4:
    // 0x801119F4: lw          $a0, 0x120($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X120);
    // 0x801119F8: jal         0x800EE7F8
    // 0x801119FC: lw          $a1, 0x108($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X108);
    func_800EE7F8(rdram, ctx);
        goto after_38;
    // 0x801119FC: lw          $a1, 0x108($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X108);
    after_38:
    // 0x80111A00: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80111A04: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80111A08: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80111A0C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80111A10: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80111A14: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80111A18: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80111A1C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80111A20: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80111A24: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80111A28: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80111A2C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80111A30: jr          $ra
    // 0x80111A34: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x80111A34: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_8080059C_chjollyroger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080059C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x808005A0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x808005A4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x808005A8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(1036, 0X1456) << 16);
    // 0x808005AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x808005B4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x808005B8: sb          $a3, 0x1456($at)
    MEM_B((int16_t)RELOC_LO16(1036, 0X1456), ctx->r1) = ctx->r7;
    // 0x808005BC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1036, 0X1448) << 16);
    // 0x808005C0: addiu       $a2, $a2, 0x1448
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1036, 0X1448));
    // 0x808005C4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x808005C8: addiu       $a1, $a0, 0x4
    ctx->r5 = ADD32(ctx->r4, 0X4);
    // 0x808005CC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x808005D0: jal         0x8008A1F0
    // 0x808005D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    _subaddiedialog_entrypoint_8(rdram, ctx);
        goto after_0;
    // 0x808005D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x808005D8: bne         $v0, $zero, L_808005E8
    if (ctx->r2 != 0) {
        // 0x808005DC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_808005E8;
    }
    // 0x808005DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808005E0: b           L_80800614
    // 0x808005E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80800614;
    // 0x808005E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808005E8:
    // 0x808005E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x808005EC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x808005F0: jal         0x8008A1F8
    // 0x808005F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    _subaddiedialog_entrypoint_9(rdram, ctx);
        goto after_1;
    // 0x808005F4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x808005F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808005FC: beq         $v0, $at, L_80800610
    if (ctx->r2 == ctx->r1) {
        // 0x80800600: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800610;
    }
    // 0x80800600: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800604: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80800608: jal         0x80800E6C
    // 0x8080060C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80800E6C_chjollyroger(rdram, ctx);
        goto after_2;
    // 0x8080060C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
L_80800610:
    // 0x80800610: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80800614:
    // 0x80800614: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800618: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8080061C: jr          $ra
    // 0x80800620: nop

    return;
    // 0x80800620: nop

;}
RECOMP_FUNC void func_800C2840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2840: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C2844: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C2848: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C284C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800C2850: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C2854: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800C2858: jal         0x800C2E04
    // 0x800C285C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800C2E04(rdram, ctx);
        goto after_0;
    // 0x800C285C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800C2860: beq         $v0, $zero, L_800C28C4
    if (ctx->r2 == 0) {
        // 0x800C2864: andi        $s0, $v0, 0xFF
        ctx->r16 = ctx->r2 & 0XFF;
            goto L_800C28C4;
    }
    // 0x800C2864: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800C2868: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C286C: jal         0x800C301C
    // 0x800C2870: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_800C301C(rdram, ctx);
        goto after_1;
    // 0x800C2870: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800C2874: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C2878: jal         0x800C3058
    // 0x800C287C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_800C3058(rdram, ctx);
        goto after_2;
    // 0x800C287C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800C2880: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C2884: jal         0x800C31DC
    // 0x800C2888: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800C31DC(rdram, ctx);
        goto after_3;
    // 0x800C2888: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x800C288C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C2890: jal         0x800C32C4
    // 0x800C2894: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_800C32C4(rdram, ctx);
        goto after_4;
    // 0x800C2894: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x800C2898: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C289C: jal         0x800C330C
    // 0x800C28A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800C330C(rdram, ctx);
        goto after_5;
    // 0x800C28A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x800C28A4: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C28A8: jal         0x800C3418
    // 0x800C28AC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    func_800C3418(rdram, ctx);
        goto after_6;
    // 0x800C28AC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x800C28B0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x800C28B4: jal         0x800C36F4
    // 0x800C28B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800C36F4(rdram, ctx);
        goto after_7;
    // 0x800C28B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800C28BC: jal         0x800C3BDC
    // 0x800C28C0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    func_800C3BDC(rdram, ctx);
        goto after_8;
    // 0x800C28C0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_8:
L_800C28C4:
    // 0x800C28C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C28C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C28CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C28D0: jr          $ra
    // 0x800C28D4: nop

    return;
    // 0x800C28D4: nop

;}
RECOMP_FUNC void func_80801108_chcollballcontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801108: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8080110C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80801110: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80801114: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80801118: jal         0x80100094
    // 0x8080111C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x8080111C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801120: addu        $t6, $v0, $s0
    ctx->r14 = ADD32(ctx->r2, ctx->r16);
    // 0x80801124: lbu         $v1, 0xA($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0XA);
    // 0x80801128: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080112C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80801130: beq         $v1, $at, L_8080114C
    if (ctx->r3 == ctx->r1) {
        // 0x80801134: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_8080114C;
    }
    // 0x80801134: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80801138: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8080113C: beq         $v1, $at, L_8080118C
    if (ctx->r3 == ctx->r1) {
        // 0x80801140: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080118C;
    }
    // 0x80801140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80801144: b           L_808011D8
    // 0x80801148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808011D8;
    // 0x80801148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080114C:
    // 0x8080114C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80801150: jal         0x80106790
    // 0x80801154: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    func_80106790(rdram, ctx);
        goto after_1;
    // 0x80801154: lw          $a0, 0x10($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X10);
    after_1:
    // 0x80801158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080115C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x80801160: jal         0x80089B18
    // 0x80801164: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    _sukickball_entrypoint_16(rdram, ctx);
        goto after_2;
    // 0x80801164: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_2:
    // 0x80801168: jal         0x80089B10
    // 0x8080116C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _sukickball_entrypoint_15(rdram, ctx);
        goto after_3;
    // 0x8080116C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80801170: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801174: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80801178: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    // 0x8080117C: jal         0x808010B8
    // 0x80801180: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    func_808010B8_chcollballcontrol(rdram, ctx);
        goto after_4;
    // 0x80801180: swc1        $f0, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f0.u32l;
    after_4:
    // 0x80801184: b           L_808011D8
    // 0x80801188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808011D8;
    // 0x80801188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080118C:
    // 0x8080118C: jal         0x800F82D4
    // 0x80801190: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800F82D4(rdram, ctx);
        goto after_5;
    // 0x80801190: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x80801194: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80801198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080119C: jal         0x80089B10
    // 0x808011A0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    _sukickball_entrypoint_15(rdram, ctx);
        goto after_6;
    // 0x808011A0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x808011A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x808011A8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x808011AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011B0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x808011B4: jal         0x800F832C
    // 0x808011B8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_800F832C(rdram, ctx);
        goto after_7;
    // 0x808011B8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x808011BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011C0: jal         0x80089B18
    // 0x808011C4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    _sukickball_entrypoint_16(rdram, ctx);
        goto after_8;
    // 0x808011C4: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_8:
    // 0x808011C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808011CC: jal         0x800F8294
    // 0x808011D0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_800F8294(rdram, ctx);
        goto after_9;
    // 0x808011D0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_9:
    // 0x808011D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808011D8:
    // 0x808011D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808011DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808011E0: jr          $ra
    // 0x808011E4: nop

    return;
    // 0x808011E4: nop

;}
RECOMP_FUNC void batranslate_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800160: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800164: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800168: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8080016C: lw          $v0, 0x140($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X140);
    // 0x80800170: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800178: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8080017C: bnel        $t6, $at, L_80800208
    if (ctx->r14 != ctx->r1) {
        // 0x80800180: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800208;
    }
    goto skip_0;
    // 0x80800180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80800184: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80800188: beq         $v1, $zero, L_808001AC
    if (ctx->r3 == 0) {
        // 0x8080018C: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_808001AC;
    }
    // 0x8080018C: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80800190: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80800194: lw          $t8, 0x140($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X140);
    // 0x80800198: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8080019C: bnel        $t9, $zero, L_80800208
    if (ctx->r25 != 0) {
        // 0x808001A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800208;
    }
    goto skip_1;
    // 0x808001A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808001A4: jal         0x8008C9E4
    // 0x808001A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8008C9E4(rdram, ctx);
        goto after_0;
    // 0x808001A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
L_808001AC:
    // 0x808001AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001B0: jal         0x8009C128
    // 0x808001B4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C128(rdram, ctx);
        goto after_1;
    // 0x808001B4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x808001B8: lw          $a1, 0x140($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X140);
    // 0x808001BC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808001C0: jal         0x800EF3DC
    // 0x808001C4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800EF3DC(rdram, ctx);
        goto after_2;
    // 0x808001C4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_2:
    // 0x808001C8: lw          $a1, 0x140($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X140);
    // 0x808001CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001D0: jal         0x8008C958
    // 0x808001D4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_8008C958(rdram, ctx);
        goto after_3;
    // 0x808001D4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_3:
    // 0x808001D8: lw          $a1, 0x140($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X140);
    // 0x808001DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E0: jal         0x80800008
    // 0x808001E4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_80800008_batranslate(rdram, ctx);
        goto after_4;
    // 0x808001E4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_4:
    // 0x808001E8: lw          $a1, 0x140($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X140);
    // 0x808001EC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x808001F0: jal         0x800EF04C
    // 0x808001F4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800EF04C(rdram, ctx);
        goto after_5;
    // 0x808001F4: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_5:
    // 0x808001F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001FC: jal         0x8009C0F8
    // 0x80800200: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_8009C0F8(rdram, ctx);
        goto after_6;
    // 0x80800200: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x80800204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800208:
    // 0x80800208: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080020C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800210: jr          $ra
    // 0x80800214: nop

    return;
    // 0x80800214: nop

;}
RECOMP_FUNC void _sccustom_entrypoint_4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A668: syscall     846
    recomp_syscall_handler(rdram, ctx, 0x8008A668);
    return;
    // 0x8008A66C: addi        $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
;}
RECOMP_FUNC void func_80800950_chbeanstalkseed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800950: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800954: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80800958: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8080095C: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x80800960: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80800964: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800968: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x8080096C: beq         $t6, $at, L_808009F8
    if (ctx->r14 == ctx->r1) {
        // 0x80800970: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_808009F8;
    }
    // 0x80800970: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800974: beq         $t6, $at, L_808009F8
    if (ctx->r14 == ctx->r1) {
        // 0x80800978: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_808009F8;
    }
    // 0x80800978: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8080097C: bne         $t6, $at, L_808009F0
    if (ctx->r14 != ctx->r1) {
        // 0x80800980: nop
    
            goto L_808009F0;
    }
    // 0x80800980: nop

    // 0x80800984: jal         0x80101870
    // 0x80800988: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80101870(rdram, ctx);
        goto after_0;
    // 0x80800988: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8080098C: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x80800990: lui         $t1, 0x8080
    ctx->r9 = S32(RELOC_HI16(2356, 0XC48) << 16);
    // 0x80800994: addiu       $t1, $t1, 0xC48
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(2356, 0XC48));
    // 0x80800998: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x8080099C: bgez        $t9, L_808009F8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x808009A0: addiu       $t0, $sp, 0x2C
        ctx->r8 = ADD32(ctx->r29, 0X2C);
            goto L_808009F8;
    }
    // 0x808009A0: addiu       $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x808009A4: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x808009A8: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x808009AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x808009B0: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x808009B4: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x808009B8: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x808009BC: jal         0x800DF830
    // 0x808009C0: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    func_800DF830(rdram, ctx);
        goto after_1;
    // 0x808009C0: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    after_1:
    // 0x808009C4: jal         0x800D674C
    // 0x808009C8: addiu       $a0, $zero, 0x8CF
    ctx->r4 = ADD32(0, 0X8CF);
    func_800D674C(rdram, ctx);
        goto after_2;
    // 0x808009C8: addiu       $a0, $zero, 0x8CF
    ctx->r4 = ADD32(0, 0X8CF);
    after_2:
    // 0x808009CC: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x808009D0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x808009D4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x808009D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x808009DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x808009E0: jal         0x800DE498
    // 0x808009E4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    func_800DE498(rdram, ctx);
        goto after_3;
    // 0x808009E4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_3:
    // 0x808009E8: b           L_808009FC
    // 0x808009EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808009FC;
    // 0x808009EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009F0:
    // 0x808009F0: jal         0x80101870
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80101870(rdram, ctx);
        goto after_4;
    // 0x808009F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_808009F8:
    // 0x808009F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808009FC:
    // 0x808009FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800A00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80800A04: jr          $ra
    // 0x80800A08: nop

    return;
    // 0x80800A08: nop

;}
RECOMP_FUNC void func_80803A84_bsfirstp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80803A84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80803A88: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80803A8C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80803A90: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80803A94: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80803A98: lui         $s1, 0x8008
    ctx->r17 = S32(0X8008 << 16);
    // 0x80803A9C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80803AA0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80803AA4: addiu       $s1, $s1, 0x42F0
    ctx->r17 = ADD32(ctx->r17, 0X42F0);
    // 0x80803AA8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80803AAC: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x80803AB0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80803AB4:
    // 0x80803AB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80803AB8: jal         0x8009E4E0
    // 0x80803ABC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8009E4E0(rdram, ctx);
        goto after_0;
    // 0x80803ABC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x80803AC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80803AC4: bnel        $s0, $s2, L_80803AB4
    if (ctx->r16 != ctx->r18) {
        // 0x80803AC8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80803AB4;
    }
    goto skip_0;
    // 0x80803AC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x80803ACC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80803AD0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80803AD4: jal         0x8009E4E0
    // 0x80803AD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8009E4E0(rdram, ctx);
        goto after_1;
    // 0x80803AD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80803ADC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80803AE0: jal         0x80803B58
    // 0x80803AE4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_80803B58_bsfirstp(rdram, ctx);
        goto after_2;
    // 0x80803AE4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80803AE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80803AEC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80803AF0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80803AF4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80803AF8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80803AFC: jr          $ra
    // 0x80803B00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80803B00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80800424_bafpctrl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800424: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80800428: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8080042C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800430: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80800434: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x80800438: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080043C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800440: lbu         $t6, 0x14($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X14);
    // 0x80800444: beq         $t6, $zero, L_8080045C
    if (ctx->r14 == 0) {
        // 0x80800448: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_8080045C;
    }
    // 0x80800448: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8080044C: beq         $t6, $at, L_80800468
    if (ctx->r14 == ctx->r1) {
        // 0x80800450: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_80800468;
    }
    // 0x80800450: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80800454: b           L_808004A4
    // 0x80800458: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
        goto L_808004A4;
    // 0x80800458: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_8080045C:
    // 0x8080045C: sb          $zero, 0x16($v0)
    MEM_B(0X16, ctx->r2) = 0;
    // 0x80800460: b           L_808004A0
    // 0x80800464: lw          $v0, 0x90($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X90);
        goto L_808004A0;
    // 0x80800464: lw          $v0, 0x90($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X90);
L_80800468:
    // 0x80800468: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8080046C: bne         $t8, $at, L_80800494
    if (ctx->r24 != ctx->r1) {
        // 0x80800470: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800494;
    }
    // 0x80800470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800474: jal         0x8009E674
    // 0x80800478: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E674(rdram, ctx);
        goto after_0;
    // 0x80800478: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8080047C: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(532, 0X10D0) << 16);
    // 0x80800480: addiu       $a3, $a3, 0x10D0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(532, 0X10D0));
    // 0x80800484: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80800488: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8080048C: jal         0x8010D930
    // 0x80800490: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010D930(rdram, ctx);
        goto after_1;
    // 0x80800490: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_80800494:
    // 0x80800494: jal         0x80084A98
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggaim_entrypoint_1(rdram, ctx);
        goto after_2;
    // 0x80800498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8080049C: lw          $v0, 0x90($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X90);
L_808004A0:
    // 0x808004A0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
L_808004A4:
    // 0x808004A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004AC: sb          $t9, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r25;
    // 0x808004B0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x808004B4: beq         $t0, $at, L_80800514
    if (ctx->r8 == ctx->r1) {
        // 0x808004B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800514;
    }
    // 0x808004B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808004BC: bnel        $t0, $at, L_808005EC
    if (ctx->r8 != ctx->r1) {
        // 0x808004C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_808005EC;
    }
    goto skip_0;
    // 0x808004C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x808004C4: lw          $v0, 0x90($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X90);
    // 0x808004C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004CC: lbu         $v1, 0x16($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X16);
    // 0x808004D0: beq         $v1, $zero, L_80800500
    if (ctx->r3 == 0) {
        // 0x808004D4: addiu       $t1, $v1, 0x1
        ctx->r9 = ADD32(ctx->r3, 0X1);
            goto L_80800500;
    }
    // 0x808004D4: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x808004D8: jal         0x8009E674
    // 0x808004DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8009E674(rdram, ctx);
        goto after_3;
    // 0x808004DC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x808004E0: lui         $a3, 0x8080
    ctx->r7 = S32(RELOC_HI16(532, 0X10C0) << 16);
    // 0x808004E4: addiu       $a3, $a3, 0x10C0
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(532, 0X10C0));
    // 0x808004E8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x808004EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x808004F0: jal         0x8010D930
    // 0x808004F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8010D930(rdram, ctx);
        goto after_4;
    // 0x808004F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x808004F8: b           L_80800504
    // 0x808004FC: nop

        goto L_80800504;
    // 0x808004FC: nop

L_80800500:
    // 0x80800500: sb          $t1, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r9;
L_80800504:
    // 0x80800504: jal         0x80084AA0
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    _baeggaim_entrypoint_2(rdram, ctx);
        goto after_5;
    // 0x80800508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8080050C: b           L_808005EC
    // 0x80800510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_808005EC;
    // 0x80800510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800514:
    // 0x80800514: jal         0x8009E71C
    // 0x80800518: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8009E71C(rdram, ctx);
        goto after_6;
    // 0x80800518: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_6:
    // 0x8080051C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80800520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800524: jal         0x8009E71C
    // 0x80800528: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8009E71C(rdram, ctx);
        goto after_7;
    // 0x80800528: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_7:
    // 0x8080052C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80800530: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80800534: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x80800538: sltiu       $a1, $v1, 0x1
    ctx->r5 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8080053C: beq         $a1, $zero, L_80800548
    if (ctx->r5 == 0) {
        // 0x80800540: nop
    
            goto L_80800548;
    }
    // 0x80800540: nop

    // 0x80800544: sltiu       $a1, $v0, 0x1
    ctx->r5 = ctx->r2 < 0X1 ? 1 : 0;
L_80800548:
    // 0x80800548: jal         0x800C6E38
    // 0x8080054C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_800C6E38(rdram, ctx);
        goto after_8;
    // 0x8080054C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_8:
    // 0x80800550: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80800554: jal         0x800C6E38
    // 0x80800558: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    func_800C6E38(rdram, ctx);
        goto after_9;
    // 0x80800558: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_9:
    // 0x8080055C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80800560: jal         0x800C6E38
    // 0x80800564: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800C6E38(rdram, ctx);
        goto after_10;
    // 0x80800564: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_10:
    // 0x80800568: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8080056C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80800570: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80800574: beq         $t3, $zero, L_80800584
    if (ctx->r11 == 0) {
        // 0x80800578: sltu        $a1, $zero, $v1
        ctx->r5 = 0 < ctx->r3 ? 1 : 0;
            goto L_80800584;
    }
    // 0x80800578: sltu        $a1, $zero, $v1
    ctx->r5 = 0 < ctx->r3 ? 1 : 0;
    // 0x8080057C: bne         $a1, $zero, L_808005B0
    if (ctx->r5 != 0) {
        // 0x80800580: nop
    
            goto L_808005B0;
    }
    // 0x80800580: nop

L_80800584:
    // 0x80800584: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80800588: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8080058C: beq         $t5, $zero, L_8080059C
    if (ctx->r13 == 0) {
        // 0x80800590: sltu        $a1, $zero, $v1
        ctx->r5 = 0 < ctx->r3 ? 1 : 0;
            goto L_8080059C;
    }
    // 0x80800590: sltu        $a1, $zero, $v1
    ctx->r5 = 0 < ctx->r3 ? 1 : 0;
    // 0x80800594: bne         $a1, $zero, L_808005B0
    if (ctx->r5 != 0) {
        // 0x80800598: nop
    
            goto L_808005B0;
    }
    // 0x80800598: nop

L_8080059C:
    // 0x8080059C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x808005A0: sltu        $a1, $zero, $v1
    ctx->r5 = 0 < ctx->r3 ? 1 : 0;
    // 0x808005A4: beq         $a1, $zero, L_808005B0
    if (ctx->r5 == 0) {
        // 0x808005A8: nop
    
            goto L_808005B0;
    }
    // 0x808005A8: nop

    // 0x808005AC: sltu        $a1, $zero, $v0
    ctx->r5 = 0 < ctx->r2 ? 1 : 0;
L_808005B0:
    // 0x808005B0: bnel        $t8, $zero, L_808005E4
    if (ctx->r24 != 0) {
        // 0x808005B4: lw          $t2, 0x90($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X90);
            goto L_808005E4;
    }
    goto skip_1;
    // 0x808005B4: lw          $t2, 0x90($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X90);
    skip_1:
    // 0x808005B8: beql        $a1, $zero, L_808005E4
    if (ctx->r5 == 0) {
        // 0x808005BC: lw          $t2, 0x90($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X90);
            goto L_808005E4;
    }
    goto skip_2;
    // 0x808005BC: lw          $t2, 0x90($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X90);
    skip_2:
    // 0x808005C0: lw          $v0, 0x90($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X90);
    // 0x808005C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x808005C8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x808005CC: andi        $t0, $t9, 0x4
    ctx->r8 = ctx->r25 & 0X4;
    // 0x808005D0: bnel        $t0, $zero, L_808005E4
    if (ctx->r8 != 0) {
        // 0x808005D4: lw          $t2, 0x90($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X90);
            goto L_808005E4;
    }
    goto skip_3;
    // 0x808005D4: lw          $t2, 0x90($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X90);
    skip_3:
    // 0x808005D8: b           L_808005E8
    // 0x808005DC: sb          $t1, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r9;
        goto L_808005E8;
    // 0x808005DC: sb          $t1, 0x15($v0)
    MEM_B(0X15, ctx->r2) = ctx->r9;
    // 0x808005E0: lw          $t2, 0x90($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X90);
L_808005E4:
    // 0x808005E4: sb          $zero, 0x15($t2)
    MEM_B(0X15, ctx->r10) = 0;
L_808005E8:
    // 0x808005E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808005EC:
    // 0x808005EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x808005F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x808005F4: jr          $ra
    // 0x808005F8: nop

    return;
    // 0x808005F8: nop

;}
RECOMP_FUNC void bsjig_entrypoint_10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080051C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80800520: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800524: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80800528: lui         $a1, 0x3F17
    ctx->r5 = S32(0X3F17 << 16);
    // 0x8080052C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800530: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80800534: jal         0x8008CB10
    // 0x80800538: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    baanim_isAt(rdram, ctx);
        goto after_0;
    // 0x80800538: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    after_0:
    // 0x8080053C: bne         $v0, $zero, L_80800554
    if (ctx->r2 != 0) {
        // 0x80800540: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800554;
    }
    // 0x80800540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800544: lui         $a1, 0x3F57
    ctx->r5 = S32(0X3F57 << 16);
    // 0x80800548: jal         0x8008CB10
    // 0x8080054C: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    baanim_isAt(rdram, ctx);
        goto after_1;
    // 0x8080054C: ori         $a1, $a1, 0xA3D
    ctx->r5 = ctx->r5 | 0XA3D;
    after_1:
    // 0x80800550: beq         $v0, $zero, L_80800568
    if (ctx->r2 == 0) {
        // 0x80800554: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800568;
    }
L_80800554:
    // 0x80800554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800558: addiu       $a1, $zero, 0x3EA
    ctx->r5 = ADD32(0, 0X3EA);
    // 0x8080055C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800560: jal         0x8009DF18
    // 0x80800564: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    func_8009DF18(rdram, ctx);
        goto after_2;
    // 0x80800564: addiu       $a3, $zero, 0x7530
    ctx->r7 = ADD32(0, 0X7530);
    after_2:
L_80800568:
    // 0x80800568: jal         0x8008CAEC
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_isStopped(rdram, ctx);
        goto after_3;
    // 0x8080056C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80800570: beq         $v0, $zero, L_80800580
    if (ctx->r2 == 0) {
        // 0x80800574: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800580;
    }
    // 0x80800574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800578: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8080057C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80800580:
    // 0x80800580: jal         0x8009E5C8
    // 0x80800584: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    bs_setState(rdram, ctx);
        goto after_4;
    // 0x80800584: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80800588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8080058C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80800590: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800594: jr          $ra
    // 0x80800598: nop

    return;
    // 0x80800598: nop

;}
RECOMP_FUNC void fxstep_entrypoint_6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080053C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800544: jal         0x800EE7F8
    // 0x80800548: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800548: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_0:
    // 0x8080054C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800550: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800554: jr          $ra
    // 0x80800558: nop

    return;
    // 0x80800558: nop

;}
RECOMP_FUNC void func_80095A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095A6C: jr          $ra
    // 0x80095A70: sw          $a0, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->r4;
    return;
    // 0x80095A70: sw          $a0, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void func_808005C0_chquiz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x808005C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x808005CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808005D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808005D4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x808005D8: jal         0x80100094
    // 0x808005DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x808005DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x808005E0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x808005E4: lw          $t6, 0x94($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X94);
    // 0x808005E8: sltiu       $at, $t7, 0xA
    ctx->r1 = ctx->r15 < 0XA ? 1 : 0;
    // 0x808005EC: beq         $at, $zero, L_80800714
    if (ctx->r1 == 0) {
        // 0x808005F0: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_80800714;
    }
    // 0x808005F0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x808005F4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x808005F8: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(2484, 0X6568) << 16);
    // 0x808005FC: addu        $at, $at, $t7
    gpr jr_addend_80800604 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80800600: lw          $t7, 0x6568($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(2484, 0X6568));
    // 0x80800604: jr          $t7
    // 0x80800608: nop

    switch (jr_addend_80800604 >> 2) {
        case 0: goto L_80800690; break;
        case 1: goto L_80800714; break;
        case 2: goto L_8080070C; break;
        case 3: goto L_8080070C; break;
        case 4: goto L_8080060C; break;
        case 5: goto L_80800714; break;
        case 6: goto L_80800714; break;
        case 7: goto L_80800714; break;
        case 8: goto L_80800714; break;
        case 9: goto L_808006B0; break;
        default: switch_error(__func__, 0x80800604, 0x80806568);
    }
    // 0x80800608: nop

L_8080060C:
    // 0x8080060C: jal         0x8080414C
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8080414C_chquiz(rdram, ctx);
        goto after_1;
    // 0x80800610: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80800614: beql        $v0, $zero, L_80800718
    if (ctx->r2 == 0) {
        // 0x80800618: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800718;
    }
    goto skip_0;
    // 0x80800618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8080061C: jal         0x80800C00
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800C00_chquiz(rdram, ctx);
        goto after_2;
    // 0x80800620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80800624: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80800628: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8080062C: addiu       $a2, $zero, 0x7D00
    ctx->r6 = ADD32(0, 0X7D00);
    // 0x80800630: bne         $v0, $t8, L_80800648
    if (ctx->r2 != ctx->r24) {
        // 0x80800634: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800648;
    }
    // 0x80800634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800638: jal         0x800C3FC0
    // 0x8080063C: addiu       $a0, $zero, 0x42B
    ctx->r4 = ADD32(0, 0X42B);
    func_800C3FC0(rdram, ctx);
        goto after_3;
    // 0x8080063C: addiu       $a0, $zero, 0x42B
    ctx->r4 = ADD32(0, 0X42B);
    after_3:
    // 0x80800640: b           L_80800718
    // 0x80800644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800718;
    // 0x80800644: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800648:
    // 0x80800648: jal         0x80100094
    // 0x8080064C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_4;
    // 0x8080064C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80800650: jal         0x80800E44
    // 0x80800654: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80800E44_chquiz(rdram, ctx);
        goto after_5;
    // 0x80800654: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80800658: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8080065C: bne         $v0, $t9, L_80800674
    if (ctx->r2 != ctx->r25) {
        // 0x80800660: nop
    
            goto L_80800674;
    }
    // 0x80800660: nop

    // 0x80800664: jal         0x808040D4
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808040D4_chquiz(rdram, ctx);
        goto after_6;
    // 0x80800668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8080066C: b           L_80800718
    // 0x80800670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800718;
    // 0x80800670: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800674:
    // 0x80800674: jal         0x80804110
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80804110_chquiz(rdram, ctx);
        goto after_7;
    // 0x80800678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8080067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800680: jal         0x80800BD4
    // 0x80800684: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80800BD4_chquiz(rdram, ctx);
        goto after_8;
    // 0x80800684: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
    // 0x80800688: b           L_80800718
    // 0x8080068C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800718;
    // 0x8080068C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800690:
    // 0x80800690: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800694: jal         0x80100094
    // 0x80800698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_9;
    // 0x80800698: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8080069C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808006A0: jal         0x80800218
    // 0x808006A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80800218_chquiz(rdram, ctx);
        goto after_10;
    // 0x808006A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x808006A8: b           L_80800718
    // 0x808006AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800718;
    // 0x808006AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_808006B0:
    // 0x808006B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006B4: jal         0x80100094
    // 0x808006B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_11;
    // 0x808006B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x808006BC: jal         0x80801710
    // 0x808006C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80801710_chquiz(rdram, ctx);
        goto after_12;
    // 0x808006C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_12:
    // 0x808006C4: jal         0x8008A7D8
    // 0x808006C8: nop

    _suquiz_entrypoint_4(rdram, ctx);
        goto after_13;
    // 0x808006C8: nop

    after_13:
    // 0x808006CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808006D0: beq         $v0, $at, L_80800714
    if (ctx->r2 == ctx->r1) {
        // 0x808006D4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_80800714;
    }
    // 0x808006D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x808006D8: jal         0x80087D60
    // 0x808006DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    _gcnewoption_entrypoint_25(rdram, ctx);
        goto after_14;
    // 0x808006DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x808006E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808006E4: jal         0x80100094
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_15;
    // 0x808006E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x808006EC: lbu         $t0, 0x98($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X98);
    // 0x808006F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808006F4: bnel        $t0, $at, L_80800718
    if (ctx->r8 != ctx->r1) {
        // 0x808006F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80800718;
    }
    goto skip_1;
    // 0x808006F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x808006FC: jal         0x8008A850
    // 0x80800700: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    _suquiz_entrypoint_19(rdram, ctx);
        goto after_16;
    // 0x80800700: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x80800704: b           L_80800718
    // 0x80800708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80800718;
    // 0x80800708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8080070C:
    // 0x8080070C: jal         0x808008D4
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808008D4_chquiz(rdram, ctx);
        goto after_17;
    // 0x80800710: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_80800714:
    // 0x80800714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80800718:
    // 0x80800718: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8080071C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80800720: jr          $ra
    // 0x80800724: nop

    return;
    // 0x80800724: nop

;}
RECOMP_FUNC void _bsjump_entrypoint_17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800832B8: syscall     52
    recomp_syscall_handler(rdram, ctx, 0x800832B8);
    return;
    // 0x800832BC: addi        $t0, $zero, 0x44
    ctx->r8 = ADD32(0, 0X44);
;}
RECOMP_FUNC void sumumbofx_entrypoint_27(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808013D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808013D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808013D8: jal         0x80801360
    // 0x808013DC: nop

    sumumbofx_entrypoint_21(rdram, ctx);
        goto after_0;
    // 0x808013DC: nop

    after_0:
    // 0x808013E0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x808013E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x808013E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808013EC: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x808013F0: nop

    // 0x808013F4: bc1f        L_80801400
    if (!c1cs) {
        // 0x808013F8: nop
    
            goto L_80801400;
    }
    // 0x808013F8: nop

    // 0x808013FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801400:
    // 0x80801400: jr          $ra
    // 0x80801404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80801404: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80801714_chtntmineshoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801714: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80801718: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8080171C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80801720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801724: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80801728: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8080172C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80801730: jal         0x80100094
    // 0x80801734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_0;
    // 0x80801734: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80801738: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8080173C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80801740: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80801744: beq         $a2, $at, L_8080181C
    if (ctx->r6 == ctx->r1) {
        // 0x80801748: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_8080181C;
    }
    // 0x80801748: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x8080174C: beq         $a2, $at, L_8080190C
    if (ctx->r6 == ctx->r1) {
        // 0x80801750: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8080190C;
    }
    // 0x80801750: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801754: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80801758: beq         $a2, $at, L_808018F8
    if (ctx->r6 == ctx->r1) {
        // 0x8080175C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_808018F8;
    }
    // 0x8080175C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801760: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80801764: beq         $a2, $at, L_8080178C
    if (ctx->r6 == ctx->r1) {
        // 0x80801768: addiu       $at, $zero, 0x4F
        ctx->r1 = ADD32(0, 0X4F);
            goto L_8080178C;
    }
    // 0x80801768: addiu       $at, $zero, 0x4F
    ctx->r1 = ADD32(0, 0X4F);
    // 0x8080176C: beq         $a2, $at, L_80801858
    if (ctx->r6 == ctx->r1) {
        // 0x80801770: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_80801858;
    }
    // 0x80801770: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80801774: beq         $a2, $at, L_80801930
    if (ctx->r6 == ctx->r1) {
        // 0x80801778: addiu       $at, $zero, 0x9F
        ctx->r1 = ADD32(0, 0X9F);
            goto L_80801930;
    }
    // 0x80801778: addiu       $at, $zero, 0x9F
    ctx->r1 = ADD32(0, 0X9F);
    // 0x8080177C: beq         $a2, $at, L_80801920
    if (ctx->r6 == ctx->r1) {
        // 0x80801780: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80801920;
    }
    // 0x80801780: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801784: b           L_80801964
    // 0x80801788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801964;
    // 0x80801788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8080178C:
    // 0x8080178C: jal         0x800D395C
    // 0x80801790: nop

    func_800D395C(rdram, ctx);
        goto after_1;
    // 0x80801790: nop

    after_1:
    // 0x80801794: beq         $v0, $zero, L_808017D0
    if (ctx->r2 == 0) {
        // 0x80801798: addiu       $a0, $zero, 0xF
        ctx->r4 = ADD32(0, 0XF);
            goto L_808017D0;
    }
    // 0x80801798: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x8080179C: jal         0x80801658
    // 0x808017A0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_80801658_chtntmineshoot(rdram, ctx);
        goto after_2;
    // 0x808017A0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x808017A4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x808017A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808017AC: jal         0x80100094
    // 0x808017B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_3;
    // 0x808017B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x808017B4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x808017B8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x808017BC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x808017C0: jal         0x80800E64
    // 0x808017C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800E64_chtntmineshoot(rdram, ctx);
        goto after_4;
    // 0x808017C4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x808017C8: b           L_80801964
    // 0x808017CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801964;
    // 0x808017CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808017D0:
    // 0x808017D0: jal         0x800D0A9C
    // 0x808017D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800D0A9C(rdram, ctx);
        goto after_5;
    // 0x808017D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x808017D8: bne         $v0, $zero, L_80801814
    if (ctx->r2 != 0) {
        // 0x808017DC: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_80801814;
    }
    // 0x808017DC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x808017E0: jal         0x80801658
    // 0x808017E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    func_80801658_chtntmineshoot(rdram, ctx);
        goto after_6;
    // 0x808017E4: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x808017E8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x808017EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x808017F0: jal         0x80100094
    // 0x808017F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80100094(rdram, ctx);
        goto after_7;
    // 0x808017F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x808017F8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x808017FC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80801800: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80801804: jal         0x80800E64
    // 0x80801808: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800E64_chtntmineshoot(rdram, ctx);
        goto after_8;
    // 0x80801808: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_8:
    // 0x8080180C: b           L_80801964
    // 0x80801810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801964;
    // 0x80801810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801814:
    // 0x80801814: b           L_80801960
    // 0x80801818: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
        goto L_80801960;
    // 0x80801818: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_8080181C:
    // 0x8080181C: jal         0x800D395C
    // 0x80801820: nop

    func_800D395C(rdram, ctx);
        goto after_9;
    // 0x80801820: nop

    after_9:
    // 0x80801824: beq         $v0, $zero, L_80801834
    if (ctx->r2 == 0) {
        // 0x80801828: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80801834;
    }
    // 0x80801828: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8080182C: b           L_80801834
    // 0x80801830: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
        goto L_80801834;
    // 0x80801830: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_80801834:
    // 0x80801834: jal         0x80800E64
    // 0x80801838: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800E64_chtntmineshoot(rdram, ctx);
        goto after_10;
    // 0x80801838: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_10:
    // 0x8080183C: jal         0x800F54E4
    // 0x80801840: nop

    func_800F54E4(rdram, ctx);
        goto after_11;
    // 0x80801840: nop

    after_11:
    // 0x80801844: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80801848: jal         0x800F7F98
    // 0x8080184C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F7F98(rdram, ctx);
        goto after_12;
    // 0x8080184C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x80801850: b           L_80801964
    // 0x80801854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801964;
    // 0x80801854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801858:
    // 0x80801858: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8080185C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80801860: beq         $t0, $zero, L_808018C0
    if (ctx->r8 == 0) {
        // 0x80801864: sw          $t0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r8;
            goto L_808018C0;
    }
    // 0x80801864: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80801868: jal         0x800D395C
    // 0x8080186C: nop

    func_800D395C(rdram, ctx);
        goto after_13;
    // 0x8080186C: nop

    after_13:
    // 0x80801870: bne         $v0, $zero, L_80801898
    if (ctx->r2 != 0) {
        // 0x80801874: lw          $t2, 0x30($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X30);
            goto L_80801898;
    }
    // 0x80801874: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80801878: lhu         $t3, 0x72($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X72);
    // 0x8080187C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80801880: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80801884: srl         $t4, $t3, 10
    ctx->r12 = S32(U32(ctx->r11) >> 10);
    // 0x80801888: bnel        $t4, $at, L_8080189C
    if (ctx->r12 != ctx->r1) {
        // 0x8080188C: lw          $t5, 0x30($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X30);
            goto L_8080189C;
    }
    goto skip_0;
    // 0x8080188C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80801890: jal         0x80800E64
    // 0x80801894: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80800E64_chtntmineshoot(rdram, ctx);
        goto after_14;
    // 0x80801894: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_14:
L_80801898:
    // 0x80801898: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
L_8080189C:
    // 0x8080189C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x808018A0: lhu         $t6, 0x72($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X72);
    // 0x808018A4: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808018A8: bnel        $t7, $at, L_80801964
    if (ctx->r15 != ctx->r1) {
        // 0x808018AC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80801964;
    }
    goto skip_1;
    // 0x808018AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x808018B0: jal         0x800FC660
    // 0x808018B4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800FC660(rdram, ctx);
        goto after_15;
    // 0x808018B4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_15:
    // 0x808018B8: b           L_80801964
    // 0x808018BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801964;
    // 0x808018BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018C0:
    // 0x808018C0: jal         0x800D395C
    // 0x808018C4: nop

    func_800D395C(rdram, ctx);
        goto after_16;
    // 0x808018C4: nop

    after_16:
    // 0x808018C8: beq         $v0, $zero, L_808018D8
    if (ctx->r2 == 0) {
        // 0x808018CC: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_808018D8;
    }
    // 0x808018CC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x808018D0: b           L_808018DC
    // 0x808018D4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
        goto L_808018DC;
    // 0x808018D4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
L_808018D8:
    // 0x808018D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_808018DC:
    // 0x808018DC: jal         0x800FC660
    // 0x808018E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800FC660(rdram, ctx);
        goto after_17;
    // 0x808018E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_17:
    // 0x808018E4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808018E8: jal         0x80800E64
    // 0x808018EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80800E64_chtntmineshoot(rdram, ctx);
        goto after_18;
    // 0x808018EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_18:
    // 0x808018F0: b           L_80801964
    // 0x808018F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801964;
    // 0x808018F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808018F8:
    // 0x808018F8: lh          $a1, 0x38($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X38);
    // 0x808018FC: jal         0x80801A18
    // 0x80801900: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    func_80801A18_chtntmineshoot(rdram, ctx);
        goto after_19;
    // 0x80801900: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    after_19:
    // 0x80801904: b           L_80801968
    // 0x80801908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80801968;
    // 0x80801908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8080190C:
    // 0x8080190C: lh          $a1, 0x38($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X38);
    // 0x80801910: jal         0x80801A54
    // 0x80801914: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    func_80801A54_chtntmineshoot(rdram, ctx);
        goto after_20;
    // 0x80801914: lh          $a2, 0x3A($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X3A);
    after_20:
    // 0x80801918: b           L_80801964
    // 0x8080191C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801964;
    // 0x8080191C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801920:
    // 0x80801920: jal         0x80800E64
    // 0x80801924: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80800E64_chtntmineshoot(rdram, ctx);
        goto after_21;
    // 0x80801924: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_21:
    // 0x80801928: b           L_80801964
    // 0x8080192C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801964;
    // 0x8080192C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801930:
    // 0x80801930: jal         0x800D395C
    // 0x80801934: nop

    func_800D395C(rdram, ctx);
        goto after_22;
    // 0x80801934: nop

    after_22:
    // 0x80801938: bne         $v0, $zero, L_80801948
    if (ctx->r2 != 0) {
        // 0x8080193C: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80801948;
    }
    // 0x8080193C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80801940: b           L_80801964
    // 0x80801944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801964;
    // 0x80801944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801948:
    // 0x80801948: jal         0x80800E64
    // 0x8080194C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80800E64_chtntmineshoot(rdram, ctx);
        goto after_23;
    // 0x8080194C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_23:
    // 0x80801950: b           L_80801964
    // 0x80801954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80801964;
    // 0x80801954: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80801958: b           L_80801964
    // 0x8080195C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80801964;
    // 0x8080195C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80801960:
    // 0x80801960: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80801964:
    // 0x80801964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801968:
    // 0x80801968: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8080196C: jr          $ra
    // 0x80801970: nop

    return;
    // 0x80801970: nop

;}
RECOMP_FUNC void func_800C7074(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C707C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C7080: jal         0x800C70B0
    // 0x800C7084: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800C70B0(rdram, ctx);
        goto after_0;
    // 0x800C7084: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C7088: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800C708C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x800C7090: beql        $t6, $zero, L_800C70A4
    if (ctx->r14 == 0) {
        // 0x800C7094: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C70A4;
    }
    goto skip_0;
    // 0x800C7094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C7098: jal         0x80101238
    // 0x800C709C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_80101238(rdram, ctx);
        goto after_1;
    // 0x800C709C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800C70A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C70A4:
    // 0x800C70A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C70A8: jr          $ra
    // 0x800C70AC: nop

    return;
    // 0x800C70AC: nop

;}
RECOMP_FUNC void func_808002F0_chhellterskelter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808002F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x808002F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808002F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808002FC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80800300: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800304: jal         0x800F54E4
    // 0x80800308: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    func_800F54E4(rdram, ctx);
        goto after_0;
    // 0x80800308: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8080030C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80800310: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80800314: jal         0x800F64A4
    // 0x80800318: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    func_800F64A4(rdram, ctx);
        goto after_1;
    // 0x80800318: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    after_1:
    // 0x8080031C: bnel        $v0, $zero, L_80800338
    if (ctx->r2 != 0) {
        // 0x80800320: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_80800338;
    }
    goto skip_0;
    // 0x80800320: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x80800324: jal         0x800F6478
    // 0x80800328: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_800F6478(rdram, ctx);
        goto after_2;
    // 0x80800328: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x8080032C: bne         $v0, $zero, L_80800348
    if (ctx->r2 != 0) {
        // 0x80800330: nop
    
            goto L_80800348;
    }
    // 0x80800330: nop

    // 0x80800334: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80800338:
    // 0x80800338: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8080033C: lui         $a2, 0x4248
    ctx->r6 = S32(0X4248 << 16);
    // 0x80800340: jal         0x800F4F34
    // 0x80800344: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    func_800F4F34(rdram, ctx);
        goto after_3;
    // 0x80800344: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_3:
L_80800348:
    // 0x80800348: jal         0x80105834
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105834(rdram, ctx);
        goto after_4;
    // 0x8080034C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80800350: jal         0x808004D0
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808004D0_chhellterskelter(rdram, ctx);
        goto after_5;
    // 0x80800354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800358: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x8080035C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80800360: addiu       $a1, $zero, 0x190
    ctx->r5 = ADD32(0, 0X190);
    // 0x80800364: sll         $t8, $t6, 11
    ctx->r24 = S32(ctx->r14 << 11);
    // 0x80800368: bltzl       $t8, L_808003A0
    if (SIGNED(ctx->r24) < 0) {
        // 0x8080036C: lhu         $v0, 0x72($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X72);
            goto L_808003A0;
    }
    goto skip_1;
    // 0x8080036C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
    skip_1:
    // 0x80800370: jal         0x8010CAC0
    // 0x80800374: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8010CAC0(rdram, ctx);
        goto after_6;
    // 0x80800374: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_6:
    // 0x80800378: beq         $v0, $zero, L_8080039C
    if (ctx->r2 == 0) {
        // 0x8080037C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8080039C;
    }
    // 0x8080037C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800380: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(964, 0X8A0) << 16);
    // 0x80800384: addiu       $a2, $a2, 0x8A0
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(964, 0X8A0));
    // 0x80800388: jal         0x80089D18
    // 0x8080038C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    _subaddieaudioquick_entrypoint_2(rdram, ctx);
        goto after_7;
    // 0x8080038C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80800390: lbu         $t0, 0x65($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X65);
    // 0x80800394: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80800398: sb          $t1, 0x65($s0)
    MEM_B(0X65, ctx->r16) = ctx->r9;
L_8080039C:
    // 0x8080039C: lhu         $v0, 0x72($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X72);
L_808003A0:
    // 0x808003A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808003A4: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x808003A8: srl         $t2, $v0, 10
    ctx->r10 = S32(U32(ctx->r2) >> 10);
    // 0x808003AC: beq         $t2, $at, L_808003C8
    if (ctx->r10 == ctx->r1) {
        // 0x808003B0: addiu       $a1, $zero, 0x5DC
        ctx->r5 = ADD32(0, 0X5DC);
            goto L_808003C8;
    }
    // 0x808003B0: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    // 0x808003B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808003B8: beq         $t2, $at, L_8080044C
    if (ctx->r10 == ctx->r1) {
        // 0x808003BC: lwc1        $f10, 0x3C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8080044C;
    }
    // 0x808003BC: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x808003C0: b           L_808004C0
    // 0x808003C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004C0;
    // 0x808003C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808003C8:
    // 0x808003C8: jal         0x8010CAC0
    // 0x808003CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8010CAC0(rdram, ctx);
        goto after_8;
    // 0x808003CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_8:
    // 0x808003D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003D4: jal         0x80105494
    // 0x808003D8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    func_80105494(rdram, ctx);
        goto after_9;
    // 0x808003D8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_9:
    // 0x808003DC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x808003E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x808003E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808003E8: bne         $a2, $zero, L_80800400
    if (ctx->r6 != 0) {
        // 0x808003EC: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_80800400;
    }
    // 0x808003EC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x808003F0: bne         $a2, $zero, L_8080041C
    if (ctx->r6 != 0) {
        // 0x808003F4: nop
    
            goto L_8080041C;
    }
    // 0x808003F4: nop

    // 0x808003F8: lbu         $t3, 0x5F($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X5F);
    // 0x808003FC: beq         $t3, $zero, L_8080041C
    if (ctx->r11 == 0) {
        // 0x80800400: lui         $t4, 0x8080
        ctx->r12 = S32(RELOC_HI16(964, 0X8AC) << 16);
            goto L_8080041C;
    }
L_80800400:
    // 0x80800400: lui         $t4, 0x8080
    ctx->r12 = S32(RELOC_HI16(964, 0X8AC) << 16);
    // 0x80800404: addiu       $t4, $t4, 0x8AC
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(964, 0X8AC));
    // 0x80800408: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8080040C: addiu       $a3, $zero, 0x4B0
    ctx->r7 = ADD32(0, 0X4B0);
    // 0x80800410: jal         0x80089D58
    // 0x80800414: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_10;
    // 0x80800414: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_10:
    // 0x80800418: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_8080041C:
    // 0x8080041C: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(964, 0X7A4) << 16);
    // 0x80800420: lwc1        $f6, 0x7A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(964, 0X7A4));
    // 0x80800424: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80800428: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080042C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80800430: nop

    // 0x80800434: bc1fl       L_808004C0
    if (!c1cs) {
        // 0x80800438: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808004C0;
    }
    goto skip_2;
    // 0x80800438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8080043C: jal         0x80101FDC
    // 0x80800440: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80101FDC(rdram, ctx);
        goto after_11;
    // 0x80800440: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_11:
    // 0x80800444: b           L_808004C0
    // 0x80800448: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_808004C0;
    // 0x80800448: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8080044C:
    // 0x8080044C: lui         $at, 0xC2DC
    ctx->r1 = S32(0XC2DC << 16);
    // 0x80800450: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80800454: nop

    // 0x80800458: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8080045C: nop

    // 0x80800460: bc1fl       L_80800488
    if (!c1cs) {
        // 0x80800464: lui         $a1, 0x3F7C
        ctx->r5 = S32(0X3F7C << 16);
            goto L_80800488;
    }
    goto skip_3;
    // 0x80800464: lui         $a1, 0x3F7C
    ctx->r5 = S32(0X3F7C << 16);
    skip_3:
    // 0x80800468: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8080046C: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80800470: nop

    // 0x80800474: bc1fl       L_80800488
    if (!c1cs) {
        // 0x80800478: lui         $a1, 0x3F7C
        ctx->r5 = S32(0X3F7C << 16);
            goto L_80800488;
    }
    goto skip_4;
    // 0x80800478: lui         $a1, 0x3F7C
    ctx->r5 = S32(0X3F7C << 16);
    skip_4:
    // 0x8080047C: jal         0x80800540
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800540_chhellterskelter(rdram, ctx);
        goto after_12;
    // 0x80800480: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80800484: lui         $a1, 0x3F7C
    ctx->r5 = S32(0X3F7C << 16);
L_80800488:
    // 0x80800488: ori         $a1, $a1, 0x28F6
    ctx->r5 = ctx->r5 | 0X28F6;
    // 0x8080048C: jal         0x80105998
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105998(rdram, ctx);
        goto after_13;
    // 0x80800490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80800494: beq         $v0, $zero, L_808004A4
    if (ctx->r2 == 0) {
        // 0x80800498: nop
    
            goto L_808004A4;
    }
    // 0x80800498: nop

    // 0x8080049C: jal         0x808005E0
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005E0_chhellterskelter(rdram, ctx);
        goto after_14;
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
L_808004A4:
    // 0x808004A4: jal         0x80105A5C
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80105A5C(rdram, ctx);
        goto after_15;
    // 0x808004A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x808004AC: beql        $v0, $zero, L_808004C0
    if (ctx->r2 == 0) {
        // 0x808004B0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_808004C0;
    }
    goto skip_5;
    // 0x808004B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x808004B4: jal         0x800FFAB0
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800FFAB0(rdram, ctx);
        goto after_16;
    // 0x808004B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x808004BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_808004C0:
    // 0x808004C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808004C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x808004C8: jr          $ra
    // 0x808004CC: nop

    return;
    // 0x808004CC: nop

;}
RECOMP_FUNC void _bsdie_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082F88: syscall     37
    recomp_syscall_handler(rdram, ctx, 0x80082F88);
    return;
    // 0x80082F8C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void chpowerhut_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808000D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808000D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808000D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x808000DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808000E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x808000E4: jal         0x800DA298
    // 0x808000E8: lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X0);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x808000E8: lhu         $a0, 0x0($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X0);
    after_0:
    // 0x808000EC: sltu        $a2, $zero, $v0
    ctx->r6 = 0 < ctx->r2 ? 1 : 0;
    // 0x808000F0: bne         $a2, $zero, L_80800104
    if (ctx->r6 != 0) {
        // 0x808000F4: nop
    
            goto L_80800104;
    }
    // 0x808000F4: nop

    // 0x808000F8: jal         0x80088848
    // 0x808000FC: nop

    _glcutDll_entrypoint_20(rdram, ctx);
        goto after_1;
    // 0x808000FC: nop

    after_1:
    // 0x80800100: sltu        $a2, $zero, $v0
    ctx->r6 = 0 < ctx->r2 ? 1 : 0;
L_80800104:
    // 0x80800104: lui         $t7, 0x8080
    ctx->r15 = S32(RELOC_HI16(1076, 0X970) << 16);
    // 0x80800108: addiu       $t7, $t7, 0x970
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(1076, 0X970));
    // 0x8080010C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80800110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800114: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80800118: jal         0x80089D58
    // 0x8080011C: addiu       $a3, $zero, 0x708
    ctx->r7 = ADD32(0, 0X708);
    _subaddieaudioloop_entrypoint_5(rdram, ctx);
        goto after_2;
    // 0x8080011C: addiu       $a3, $zero, 0x708
    ctx->r7 = ADD32(0, 0X708);
    after_2:
    // 0x80800120: lhu         $a2, 0x72($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X72);
    // 0x80800124: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80800128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080012C: srl         $t8, $a2, 10
    ctx->r24 = S32(U32(ctx->r6) >> 10);
    // 0x80800130: beq         $t8, $at, L_80800154
    if (ctx->r24 == ctx->r1) {
        // 0x80800134: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80800154;
    }
    // 0x80800134: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80800138: beq         $t8, $at, L_80800164
    if (ctx->r24 == ctx->r1) {
        // 0x8080013C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800164;
    }
    // 0x8080013C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800140: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80800144: beq         $t8, $at, L_80800180
    if (ctx->r24 == ctx->r1) {
        // 0x80800148: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80800180;
    }
    // 0x80800148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080014C: b           L_808001AC
    // 0x80800150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001AC;
    // 0x80800150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800154:
    // 0x80800154: jal         0x8080047C
    // 0x80800158: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8080047C_chpowerhut(rdram, ctx);
        goto after_3;
    // 0x80800158: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8080015C: b           L_808001AC
    // 0x80800160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001AC;
    // 0x80800160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800164:
    // 0x80800164: jal         0x8080047C
    // 0x80800168: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8080047C_chpowerhut(rdram, ctx);
        goto after_4;
    // 0x80800168: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x8080016C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800170: jal         0x80800698
    // 0x80800174: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80800698_chpowerhut(rdram, ctx);
        goto after_5;
    // 0x80800174: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x80800178: b           L_808001AC
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_808001AC;
    // 0x8080017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800180:
    // 0x80800180: jal         0x8080047C
    // 0x80800184: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8080047C_chpowerhut(rdram, ctx);
        goto after_6;
    // 0x80800184: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_6:
    // 0x80800188: jal         0x808005F4
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_808005F4_chpowerhut(rdram, ctx);
        goto after_7;
    // 0x8080018C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80800190: beq         $v0, $zero, L_808001A8
    if (ctx->r2 == 0) {
        // 0x80800194: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_808001A8;
    }
    // 0x80800194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80800198: jal         0x8008A4B0
    // 0x8080019C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    _subaddieDll_entrypoint_4(rdram, ctx);
        goto after_8;
    // 0x8080019C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x808001A0: b           L_808001AC
    // 0x808001A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_808001AC;
    // 0x808001A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_808001A8:
    // 0x808001A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_808001AC:
    // 0x808001AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x808001B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x808001B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x808001B8: jr          $ra
    // 0x808001BC: nop

    return;
    // 0x808001BC: nop

;}
RECOMP_FUNC void func_8009590C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009590C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80095910: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80095914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80095918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009591C: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x80095920: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80095924: bc1fl       L_80095948
    if (!c1cs) {
        // 0x80095928: lw          $t7, 0x94($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X94);
            goto L_80095948;
    }
    goto skip_0;
    // 0x80095928: lw          $t7, 0x94($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X94);
    skip_0:
    // 0x8009592C: lw          $t6, 0x94($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X94);
    // 0x80095930: lui         $a1, 0x4260
    ctx->r5 = S32(0X4260 << 16);
    // 0x80095934: jal         0x800C68A0
    // 0x80095938: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800C68A0(rdram, ctx);
        goto after_0;
    // 0x80095938: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_0:
    // 0x8009593C: b           L_80095958
    // 0x80095940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80095958;
    // 0x80095940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80095944: lw          $t7, 0x94($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X94);
L_80095948:
    // 0x80095948: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8009594C: jal         0x800C68A0
    // 0x80095950: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_800C68A0(rdram, ctx);
        goto after_1;
    // 0x80095950: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_1:
    // 0x80095954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80095958:
    // 0x80095958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009595C: jr          $ra
    // 0x80095960: nop

    return;
    // 0x80095960: nop

;}
RECOMP_FUNC void bssnowball_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808006A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x808006AC: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(356, 0X1074) << 16);
    // 0x808006B0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x808006B4: jr          $ra
    // 0x808006B8: lw          $v0, 0x1074($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X1074));
    return;
    // 0x808006B8: lw          $v0, 0x1074($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(356, 0X1074));
;}
RECOMP_FUNC void func_8010AE30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AE30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010AE34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AE38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010AE3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8010AE40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010AE44: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8010AE48: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x8010AE4C: srl         $v1, $v0, 25
    ctx->r3 = S32(U32(ctx->r2) >> 25);
    // 0x8010AE50: beq         $v1, $zero, L_8010AE78
    if (ctx->r3 == 0) {
        // 0x8010AE54: addiu       $a0, $v1, -0x1
        ctx->r4 = ADD32(ctx->r3, -0X1);
            goto L_8010AE78;
    }
    // 0x8010AE54: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x8010AE58: sll         $a1, $v0, 22
    ctx->r5 = S32(ctx->r2 << 22);
    // 0x8010AE5C: srl         $t7, $a1, 26
    ctx->r15 = S32(U32(ctx->r5) >> 26);
    // 0x8010AE60: jal         0x800CC6CC
    // 0x8010AE64: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    func_800CC6CC(rdram, ctx);
        goto after_0;
    // 0x8010AE64: addiu       $a1, $t7, -0x1
    ctx->r5 = ADD32(ctx->r15, -0X1);
    after_0:
    // 0x8010AE68: bnel        $v0, $zero, L_8010AE7C
    if (ctx->r2 != 0) {
        // 0x8010AE6C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8010AE7C;
    }
    goto skip_0;
    // 0x8010AE6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x8010AE70: b           L_8010AE8C
    // 0x8010AE74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010AE8C;
    // 0x8010AE74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010AE78:
    // 0x8010AE78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8010AE7C:
    // 0x8010AE7C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8010AE80: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8010AE84: jal         0x8010AD4C
    // 0x8010AE88: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_8010AD4C(rdram, ctx);
        goto after_1;
    // 0x8010AE88: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_1:
L_8010AE8C:
    // 0x8010AE8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AE90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AE94: jr          $ra
    // 0x8010AE98: nop

    return;
    // 0x8010AE98: nop

;}
RECOMP_FUNC void func_800F5654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5654: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800F5658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F565C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F5660: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F5664: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x800F5668: jal         0x80096670
    // 0x800F566C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    func_80096670(rdram, ctx);
        goto after_0;
    // 0x800F566C: lw          $a0, 0x5490($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5490);
    after_0:
    // 0x800F5670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F5674: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F5678: jr          $ra
    // 0x800F567C: nop

    return;
    // 0x800F567C: nop

;}
RECOMP_FUNC void _bsbshock_entrypoint_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082B40: syscall     27
    recomp_syscall_handler(rdram, ctx, 0x80082B40);
    return;
    // 0x80082B44: addi        $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
;}
RECOMP_FUNC void func_800C84A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C84A4: jr          $ra
    // 0x800C84A8: sb          $a1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r5;
    return;
    // 0x800C84A8: sb          $a1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r5;
    // 0x800C84AC: nop

;}
RECOMP_FUNC void bskaztorpedo_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DF0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80800DF4: lui         $v0, 0x8080
    ctx->r2 = S32(RELOC_HI16(296, 0X1750) << 16);
    // 0x80800DF8: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80800DFC: jr          $ra
    // 0x80800E00: lw          $v0, 0x1750($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X1750));
    return;
    // 0x80800E00: lw          $v0, 0x1750($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(296, 0X1750));
;}
RECOMP_FUNC void func_80800460_chloggo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800460: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800464: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80800468: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8080046C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80800470: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800474: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x80800478: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1292, 0X6F8) << 16);
    // 0x8080047C: lui         $a3, 0x3DB8
    ctx->r7 = S32(0X3DB8 << 16);
    // 0x80800480: ori         $a3, $a3, 0x51EC
    ctx->r7 = ctx->r7 | 0X51EC;
    // 0x80800484: addiu       $a2, $a2, 0x6F8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1292, 0X6F8));
    // 0x80800488: jal         0x80089D20
    // 0x8080048C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x8080048C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80800490: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1292, 0X740) << 16);
    // 0x80800494: lui         $a3, 0x3E23
    ctx->r7 = S32(0X3E23 << 16);
    // 0x80800498: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8080049C: addiu       $a2, $a2, 0x740
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1292, 0X740));
    // 0x808004A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004A4: jal         0x80089D20
    // 0x808004A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_1;
    // 0x808004A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x808004AC: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1292, 0X710) << 16);
    // 0x808004B0: lui         $a3, 0x3E61
    ctx->r7 = S32(0X3E61 << 16);
    // 0x808004B4: ori         $a3, $a3, 0x47AE
    ctx->r7 = ctx->r7 | 0X47AE;
    // 0x808004B8: addiu       $a2, $a2, 0x710
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1292, 0X710));
    // 0x808004BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004C0: jal         0x80089D20
    // 0x808004C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_2;
    // 0x808004C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x808004C8: lui         $a2, 0x8080
    ctx->r6 = S32(RELOC_HI16(1292, 0X728) << 16);
    // 0x808004CC: lui         $a3, 0x3F19
    ctx->r7 = S32(0X3F19 << 16);
    // 0x808004D0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x808004D4: addiu       $a2, $a2, 0x728
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(1292, 0X728));
    // 0x808004D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808004DC: jal         0x80089D20
    // 0x808004E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    _subaddieaudioquick_entrypoint_3(rdram, ctx);
        goto after_3;
    // 0x808004E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x808004E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x808004E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x808004EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x808004F0: jr          $ra
    // 0x808004F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x808004F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_808019D4_chwaspnestgame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808019D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x808019D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808019DC: lhu         $v0, 0x72($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X72);
    // 0x808019E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808019E4: srl         $t6, $v0, 10
    ctx->r14 = S32(U32(ctx->r2) >> 10);
    // 0x808019E8: beq         $t6, $at, L_808019F8
    if (ctx->r14 == ctx->r1) {
        // 0x808019EC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_808019F8;
    }
    // 0x808019EC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x808019F0: bnel        $t6, $at, L_80801A04
    if (ctx->r14 != ctx->r1) {
        // 0x808019F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80801A04;
    }
    goto skip_0;
    // 0x808019F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_808019F8:
    // 0x808019F8: jal         0x8010DCB4
    // 0x808019FC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_8010DCB4(rdram, ctx);
        goto after_0;
    // 0x808019FC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80801A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80801A04:
    // 0x80801A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80801A08: jr          $ra
    // 0x80801A0C: nop

    return;
    // 0x80801A0C: nop

;}
RECOMP_FUNC void func_80800018_chbottlesparty(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080001C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80800024: jal         0x800DA298
    // 0x80800028: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800DA298(rdram, ctx);
        goto after_0;
    // 0x80800028: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_0:
    // 0x8080002C: bne         $v0, $zero, L_80800044
    if (ctx->r2 != 0) {
        // 0x80800030: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80800044;
    }
    // 0x80800030: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80800034: jal         0x800FFAB0
    // 0x80800038: nop

    func_800FFAB0(rdram, ctx);
        goto after_1;
    // 0x80800038: nop

    after_1:
    // 0x8080003C: b           L_80800050
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800050;
    // 0x80800040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800044:
    // 0x80800044: jal         0x8010A800
    // 0x80800048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8010A800(rdram, ctx);
        goto after_2;
    // 0x80800048: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8080004C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800050:
    // 0x80800050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800054: jr          $ra
    // 0x80800058: nop

    return;
    // 0x80800058: nop

;}
RECOMP_FUNC void _subaddiejoy_entrypoint_9(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089BF0: syscall     805
    recomp_syscall_handler(rdram, ctx, 0x80089BF0);
    return;
    // 0x80089BF4: addi        $t0, $zero, 0x24
    ctx->r8 = ADD32(0, 0X24);
;}
RECOMP_FUNC void _chboilerid_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860B8: syscall     276
    recomp_syscall_handler(rdram, ctx, 0x800860B8);
    return;
    // 0x800860BC: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void _babee_entrypoint_5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084568: syscall     114
    recomp_syscall_handler(rdram, ctx, 0x80084568);
    return;
    // 0x8008456C: addi        $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
;}
RECOMP_FUNC void func_80800000_chlavaslab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800000: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80800004: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800008: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8080000C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800010: lui         $at, 0x43D7
    ctx->r1 = S32(0X43D7 << 16);
    // 0x80800014: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80800018: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8080001C: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80800020: addiu       $t6, $zero, 0x38F
    ctx->r14 = ADD32(0, 0X38F);
    // 0x80800024: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80800028: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8080002C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80800030: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80800034: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80800038: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8080003C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80800040: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80800044: jal         0x80086898
    // 0x80800048: nop

    _chdoormake_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800048: nop

    after_0:
    // 0x8080004C: beq         $v0, $zero, L_80800080
    if (ctx->r2 == 0) {
        // 0x80800050: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80800080;
    }
    // 0x80800050: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800054: lhu         $t7, 0x76($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X76);
    // 0x80800058: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x8080005C: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    // 0x80800060: srl         $t8, $t7, 7
    ctx->r24 = S32(U32(ctx->r15) >> 7);
    // 0x80800064: bne         $t8, $at, L_80800078
    if (ctx->r24 != ctx->r1) {
        // 0x80800068: nop
    
            goto L_80800078;
    }
    // 0x80800068: nop

    // 0x8080006C: jal         0x800868B0
    // 0x80800070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _chdoormake_entrypoint_6(rdram, ctx);
        goto after_1;
    // 0x80800070: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80800074: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_80800078:
    // 0x80800078: jal         0x800868C0
    // 0x8080007C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    _chdoormake_entrypoint_8(rdram, ctx);
        goto after_2;
    // 0x8080007C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
L_80800080:
    // 0x80800080: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800084: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800088: jr          $ra
    // 0x8080008C: nop

    return;
    // 0x8080008C: nop

;}
RECOMP_FUNC void func_80800DC0_bsmum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800DC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800DC8: jal         0x800839B8
    // 0x80800DCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80800DCC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800DD0: jal         0x8080016C
    // 0x80800DD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    bsmum_entrypoint_1(rdram, ctx);
        goto after_1;
    // 0x80800DD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80800DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800DDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800DE0: jr          $ra
    // 0x80800DE4: nop

    return;
    // 0x80800DE4: nop

;}
RECOMP_FUNC void func_80800EDC_chtoothyfish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800EDC: jr          $ra
    // 0x80800EE0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80800EE0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80800098_chtrashcangame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080009C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x808000A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x808000A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x808000A8: jal         0x800D3948
    // 0x808000AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_800D3948(rdram, ctx);
        goto after_0;
    // 0x808000AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x808000B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x808000B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x808000B8: beq         $v0, $zero, L_8080011C
    if (ctx->r2 == 0) {
        // 0x808000BC: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8080011C;
    }
    // 0x808000BC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x808000C0: lhu         $t6, 0x72($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X72);
    // 0x808000C4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x808000C8: srl         $t7, $t6, 10
    ctx->r15 = S32(U32(ctx->r14) >> 10);
    // 0x808000CC: bnel        $v0, $t7, L_80800138
    if (ctx->r2 != ctx->r15) {
        // 0x808000D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800138;
    }
    goto skip_0;
    // 0x808000D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x808000D4: beq         $a1, $zero, L_808000FC
    if (ctx->r5 == 0) {
        // 0x808000D8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_808000FC;
    }
    // 0x808000D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x808000DC: beq         $a1, $at, L_80800104
    if (ctx->r5 == ctx->r1) {
        // 0x808000E0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80800104;
    }
    // 0x808000E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x808000E4: beq         $a1, $at, L_8080010C
    if (ctx->r5 == ctx->r1) {
        // 0x808000E8: nop
    
            goto L_8080010C;
    }
    // 0x808000E8: nop

    // 0x808000EC: beq         $a1, $v0, L_80800114
    if (ctx->r5 == ctx->r2) {
        // 0x808000F0: nop
    
            goto L_80800114;
    }
    // 0x808000F0: nop

    // 0x808000F4: b           L_80800138
    // 0x808000F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80800138;
    // 0x808000F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_808000FC:
    // 0x808000FC: b           L_80800134
    // 0x80800100: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
        goto L_80800134;
    // 0x80800100: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
L_80800104:
    // 0x80800104: b           L_80800134
    // 0x80800108: sw          $a2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r6;
        goto L_80800134;
    // 0x80800108: sw          $a2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r6;
L_8080010C:
    // 0x8080010C: b           L_80800134
    // 0x80800110: sw          $a2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r6;
        goto L_80800134;
    // 0x80800110: sw          $a2, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r6;
L_80800114:
    // 0x80800114: b           L_80800134
    // 0x80800118: sw          $a2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r6;
        goto L_80800134;
    // 0x80800118: sw          $a2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r6;
L_8080011C:
    // 0x8080011C: lhu         $t8, 0x72($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X72);
    // 0x80800120: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80800124: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x80800128: bnel        $t9, $at, L_80800138
    if (ctx->r25 != ctx->r1) {
        // 0x8080012C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80800138;
    }
    goto skip_1;
    // 0x8080012C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80800130: sw          $a2, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r6;
L_80800134:
    // 0x80800134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80800138:
    // 0x80800138: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8080013C: jr          $ra
    // 0x80800140: nop

    return;
    // 0x80800140: nop

;}
RECOMP_FUNC void func_8009E9A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009E9A0: jr          $ra
    // 0x8009E9A4: nop

    return;
    // 0x8009E9A4: nop

;}
RECOMP_FUNC void _chtiptup_entrypoint_1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085F18: syscall     260
    recomp_syscall_handler(rdram, ctx, 0x80085F18);
    return;
    // 0x80085F1C: addi        $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
;}
RECOMP_FUNC void bavan_entrypoint_8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800188: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8080018C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80800190: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80800194: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80800198: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8080019C: jal         0x800D8FF8
    // 0x808001A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    func_800D8FF8(rdram, ctx);
        goto after_0;
    // 0x808001A0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x808001A4: lw          $v0, 0x144($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X144);
    // 0x808001A8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x808001AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x808001B0: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x808001B4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x808001B8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x808001BC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x808001C0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x808001C4: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x808001C8: lw          $v0, 0x144($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X144);
    // 0x808001CC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x808001D0: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x808001D4: jal         0x800F15F8
    // 0x808001D8: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    func_800F15F8(rdram, ctx);
        goto after_1;
    // 0x808001D8: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    after_1:
    // 0x808001DC: lw          $t6, 0x144($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X144);
    // 0x808001E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808001E4: jal         0x80092AD8
    // 0x808001E8: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    func_80092AD8(rdram, ctx);
        goto after_2;
    // 0x808001E8: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    after_2:
    // 0x808001EC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x808001F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808001F4: jal         0x800E0AF0
    // 0x808001F8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_800E0AF0(rdram, ctx);
        goto after_3;
    // 0x808001F8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_3:
    // 0x808001FC: lw          $v0, 0x144($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X144);
    // 0x80800200: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80800204: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800208: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8080020C: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80800210: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x80800214: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800218: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8080021C: jal         0x800E0AFC
    // 0x80800220: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_4;
    // 0x80800220: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x80800224: lw          $v0, 0x144($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X144);
    // 0x80800228: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8080022C: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x80800230: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80800234: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80800238: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8080023C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80800240: jal         0x800E0AFC
    // 0x80800244: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_800E0AFC(rdram, ctx);
        goto after_5;
    // 0x80800244: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x80800248: lw          $t7, 0x144($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X144);
    // 0x8080024C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800250: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80800254: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x80800258: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8080025C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800260: jal         0x800E0AFC
    // 0x80800264: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800E0AFC(rdram, ctx);
        goto after_6;
    // 0x80800264: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_6:
    // 0x80800268: lw          $t8, 0x144($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X144);
    // 0x8080026C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80800270: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x80800274: lw          $a3, 0x8($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X8);
    // 0x80800278: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8080027C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80800280: jal         0x800E0AFC
    // 0x80800284: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_800E0AFC(rdram, ctx);
        goto after_7;
    // 0x80800284: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x80800288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8080028C: jal         0x8009C128
    // 0x80800290: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_8009C128(rdram, ctx);
        goto after_8;
    // 0x80800290: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_8:
    // 0x80800294: lw          $t9, 0x144($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X144);
    // 0x80800298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8080029C: jal         0x800C368C
    // 0x808002A0: lbu         $a0, 0x10($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X10);
    func_800C368C(rdram, ctx);
        goto after_9;
    // 0x808002A0: lbu         $a0, 0x10($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X10);
    after_9:
    // 0x808002A4: lw          $t0, 0x144($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X144);
    // 0x808002A8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x808002AC: jal         0x800C334C
    // 0x808002B0: lbu         $a0, 0x10($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X10);
    func_800C334C(rdram, ctx);
        goto after_10;
    // 0x808002B0: lbu         $a0, 0x10($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X10);
    after_10:
    // 0x808002B4: lw          $v0, 0x144($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X144);
    // 0x808002B8: lbu         $a0, 0x10($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X10);
    // 0x808002BC: jal         0x800C31DC
    // 0x808002C0: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    func_800C31DC(rdram, ctx);
        goto after_11;
    // 0x808002C0: lw          $a1, 0x14($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X14);
    after_11:
    // 0x808002C4: lw          $t1, 0x144($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X144);
    // 0x808002C8: jal         0x800C3BDC
    // 0x808002CC: lbu         $a0, 0x10($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X10);
    func_800C3BDC(rdram, ctx);
        goto after_12;
    // 0x808002CC: lbu         $a0, 0x10($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X10);
    after_12:
    // 0x808002D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x808002D4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x808002D8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x808002DC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x808002E0: jr          $ra
    // 0x808002E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x808002E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_808005A4_bssnowball(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x808005A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x808005A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x808005AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x808005B0: jal         0x80800234
    // 0x808005B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    bssnowball_entrypoint_1(rdram, ctx);
        goto after_0;
    // 0x808005B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x808005B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005BC: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x808005C0: jal         0x8008CB3C
    // 0x808005C4: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    baanim_playForDuration_loopSmooth(rdram, ctx);
        goto after_1;
    // 0x808005C4: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    after_1:
    // 0x808005C8: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x808005CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x808005D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x808005D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x808005D8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x808005DC: jal         0x8009FFD8
    // 0x808005E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8009FFD8(rdram, ctx);
        goto after_2;
    // 0x808005E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x808005E4: jal         0x8008CABC
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    baanim_getAnimCtrlPtr(rdram, ctx);
        goto after_3;
    // 0x808005E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x808005EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x808005F0: jal         0x8008B134
    // 0x808005F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    anctrl_setPlaybackType(rdram, ctx);
        goto after_4;
    // 0x808005F4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x808005F8: jal         0x80800164
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80800164_bssnowball(rdram, ctx);
        goto after_5;
    // 0x808005FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80800600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80800604: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80800608: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8080060C: jr          $ra
    // 0x80800610: nop

    return;
    // 0x80800610: nop

;}
RECOMP_FUNC void bsdronebitten_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080013C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800144: jal         0x80099AA8
    // 0x80800148: nop

    func_80099AA8(rdram, ctx);
        goto after_0;
    // 0x80800148: nop

    after_0:
    // 0x8080014C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800154: jr          $ra
    // 0x80800158: nop

    return;
    // 0x80800158: nop

;}
RECOMP_FUNC void dbskeleton_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800018: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8080001C: addiu       $a3, $a0, 0x8
    ctx->r7 = ADD32(ctx->r4, 0X8);
    // 0x80800020: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80800024: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x80800028: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8080002C: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x80800030: beq         $at, $zero, L_80800064
    if (ctx->r1 == 0) {
        // 0x80800034: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80800064;
    }
    // 0x80800034: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80800038: lh          $t8, 0xC($a3)
    ctx->r24 = MEM_H(ctx->r7, 0XC);
L_8080003C:
    // 0x8080003C: bnel        $a1, $t8, L_80800058
    if (ctx->r5 != ctx->r24) {
        // 0x80800040: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_80800058;
    }
    goto skip_0;
    // 0x80800040: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    skip_0:
    // 0x80800044: jal         0x800EE7F8
    // 0x80800048: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_800EE7F8(rdram, ctx);
        goto after_0;
    // 0x80800048: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x8080004C: b           L_80800070
    // 0x80800050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80800070;
    // 0x80800050: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80800054: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_80800058:
    // 0x80800058: sltu        $at, $a3, $v0
    ctx->r1 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x8080005C: bnel        $at, $zero, L_8080003C
    if (ctx->r1 != 0) {
        // 0x80800060: lh          $t8, 0xC($a3)
        ctx->r24 = MEM_H(ctx->r7, 0XC);
            goto L_8080003C;
    }
    goto skip_1;
    // 0x80800060: lh          $t8, 0xC($a3)
    ctx->r24 = MEM_H(ctx->r7, 0XC);
    skip_1:
L_80800064:
    // 0x80800064: jal         0x800EFD24
    // 0x80800068: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_800EFD24(rdram, ctx);
        goto after_1;
    // 0x80800068: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8080006C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80800070:
    // 0x80800070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800078: jr          $ra
    // 0x8080007C: nop

    return;
    // 0x8080007C: nop

;}
RECOMP_FUNC void bsdronefired_entrypoint_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8080010C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80800110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80800114: jal         0x80099AA8
    // 0x80800118: nop

    func_80099AA8(rdram, ctx);
        goto after_0;
    // 0x80800118: nop

    after_0:
    // 0x8080011C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80800120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80800124: jr          $ra
    // 0x80800128: nop

    return;
    // 0x80800128: nop

;}
RECOMP_FUNC void bafly_entrypoint_21(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80800D18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80800D1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80800D20: jal         0x80084C90
    // 0x80800D24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    _bafpctrl_entrypoint_3(rdram, ctx);
        goto after_0;
    // 0x80800D24: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80800D28: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80800D2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80800D30: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80800D34: lui         $at, 0x8080
    ctx->r1 = S32(RELOC_HI16(528, 0XDB0) << 16);
    // 0x80800D38: lwc1        $f14, 0xDB0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(528, 0XDB0));
    // 0x80800D3C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80800D40: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80800D44: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80800D48: jal         0x800F10B4
    // 0x80800D4C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_800F10B4(rdram, ctx);
        goto after_1;
    // 0x80800D4C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80800D50: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80800D54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80800D58: lui         $a2, 0x400C
    ctx->r6 = S32(0X400C << 16);
    // 0x80800D5C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80800D60: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80800D64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80800D68: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80800D6C: jal         0x8009BFE4
    // 0x80800D70: nop

    func_8009BFE4(rdram, ctx);
        goto after_2;
    // 0x80800D70: nop

    after_2:
    // 0x80800D74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80800D78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80800D7C: jr          $ra
    // 0x80800D80: nop

    return;
    // 0x80800D80: nop

    // 0x80800D84: nop

    // 0x80800D88: nop

    // 0x80800D8C: nop

;}
RECOMP_FUNC void bsstonehead_entrypoint_32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80801288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8080128C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80801290: jal         0x800839B8
    // 0x80801294: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _bsrest_entrypoint_14(rdram, ctx);
        goto after_0;
    // 0x80801294: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80801298: jal         0x80800000
    // 0x8080129C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80800000_bsstonehead(rdram, ctx);
        goto after_1;
    // 0x8080129C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x808012A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x808012A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x808012A8: jr          $ra
    // 0x808012AC: nop

    return;
    // 0x808012AC: nop

;}
